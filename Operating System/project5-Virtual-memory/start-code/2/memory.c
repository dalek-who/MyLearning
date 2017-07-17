/* Author(s): <Your name here>
 * Implementation of the memory manager for the kernel.
*/

/* memory.c
 *
 * Note: 
 * There is no separate swap area. When a data page is swapped out, 
 * it is stored in the location it was loaded from in the process' 
 * image. This means it's impossible to start two processes from the 
 * same image without screwing up the running. It also means the 
 * disk image is read once. And that we cannot use the program disk.
 *
 */

#include "common.h"
#include "kernel.h"
#include "scheduler.h"
#include "memory.h"
#include "thread.h"
#include "util.h"
#include "interrupt.h"
#include "tlb.h"
#include "usb/scsi.h"

/* Static global variables */
// Keep track of all pages: their vaddr, status, and other properties
static page_map_entry_t page_map[PAGEABLE_PAGES];

// address of the kernel page directory (shared by all kernel threads)
static uint32_t *kernel_pdir;

// allocate the kernel page tables
static uint32_t *kernel_ptabs[N_KERNEL_PTS];


//other global variables...
lock_t page_lock;
/* Main API */

/* Use virtual address to get index in page directory. */
uint32_t get_dir_idx(uint32_t vaddr){
  return (vaddr & PAGE_DIRECTORY_MASK) >> PAGE_DIRECTORY_BITS;
}

/* Use virtual address to get index in a page table. */
uint32_t get_tab_idx(uint32_t vaddr){
  return (vaddr & PAGE_TABLE_MASK) >> PAGE_TABLE_BITS;
}

/* TODO1: Returns physical address of page number i */
uint32_t* page_addr(int i){
  return page_map[i].addr;
}

/* Set flags in a page table entry to 'mode' */
void set_ptab_entry_flags(uint32_t * pdir, uint32_t vaddr, uint32_t mode){
  uint32_t dir_idx = get_dir_idx((uint32_t) vaddr);
  uint32_t tab_idx = get_tab_idx((uint32_t) vaddr);
  uint32_t dir_entry;
  uint32_t *tab;
  uint32_t entry;

  dir_entry = pdir[dir_idx];
  ASSERT(dir_entry & PE_P); /* dir entry present */
  tab = (uint32_t *) (dir_entry & PE_BASE_ADDR_MASK);
  /* clear table[index] bits 11..0 */
  entry = tab[tab_idx] & PE_BASE_ADDR_MASK;

  /* set table[index] bits 11..0 */
  entry |= mode & ~PE_BASE_ADDR_MASK;
  tab[tab_idx] = entry;

  /* Flush TLB because we just changed a page table entry in memory */
  flush_tlb_entry(vaddr);
}

/* Initialize a page table entry
 *  
 * 'vaddr' is the virtual address which is mapped to the physical
 * address 'paddr'. 'mode' sets bit [12..0] in the page table entry.
 *   
 * If user is nonzero, the page is mapped as accessible from a user
 * application.
 */
void init_ptab_entry(uint32_t * table, uint32_t vaddr,
         uint32_t paddr, uint32_t mode){
  int index = get_tab_idx(vaddr);
  table[index] =
    (paddr & PE_BASE_ADDR_MASK) | (mode & ~PE_BASE_ADDR_MASK);
  flush_tlb_entry(vaddr);
}

/* Insert a page table entry into the page directory. 
 *   
 * 'mode' sets bit [12..0] in the page table entry.
 */
void insert_ptab_dir(uint32_t * dir, uint32_t *tab, uint32_t vaddr, 
           uint32_t mode){

  uint32_t access = mode & MODE_MASK;
  int idx = get_dir_idx(vaddr);

  dir[idx] = ((uint32_t)tab & PE_BASE_ADDR_MASK) | access;
}

/* TODO1: Allocate a page. Return page index in the page_map directory.
 * 
 * Marks page as pinned if pinned == TRUE. 
 * Swap out a page if no space is available. 
 */
int page_alloc(int pinned){
  // define some local needed variables
  uint32_t free_index;
  // find an availabe physical page
  for (free_index = 0; free_index < PAGEABLE_PAGES; free_index++) 
    if (page_map[free_index].is_available)
      break;
  ASSERT(free_index < PAGEABLE_PAGES);
  // initialize a physical page (wirte infomation to page_map)
  page_map[free_index].vaddr = (current_running->fault_addr & PE_BASE_ADDR_MASK);
  page_map[free_index].swap_loc = current_running->swap_loc;
  page_map[free_index].is_pinned = pinned;
  page_map[free_index].is_available = FALSE;
  page_map[free_index].pid = current_running->pid;
  page_map[free_index].page_dir = current_running->page_directory;
  // zero-out the process page directory
  page_map[free_index].swap_size = current_running->swap_size - ((page_map[free_index].vaddr - PROCESS_START) / PAGE_SIZE) * SECTORS_PER_PAGE;
  if(page_map[free_index].swap_size > SECTORS_PER_PAGE)
    page_map[free_index].swap_size = SECTORS_PER_PAGE;
  bzero((char *)page_map[free_index].addr, PAGE_SIZE);
  return free_index;
}

/* TODO1: Set up kernel memory for kernel threads to run.
 *
 * This method is only called once by _start() in kernel.c, and is only 
 * supposed to set up the page directory and page tables for the kernel.
 */
void init_memory(void){
  // initialize all pageablse pages to a default state
  int i, j;
  lock_init(&page_lock);
  for (i = 0; i < PAGEABLE_PAGES; i++)
  {
    page_map[i].addr = MEM_START + i * PAGE_SIZE;
    page_map[i].is_pinned = FALSE;
    page_map[i].is_available = TRUE;
    page_map[i].pid = -1;
    page_map[i].index = i;
  }
  // pin one page for the kernel page directory
  int index;
  index = page_alloc(TRUE);
  kernel_pdir = page_map[index].addr;
  // zero-out the kernel page directory
  //bzero((char *)kernel_pdir, PAGE_SIZE);
  // pin N_KERNEL_PTS pages for kernel page tables
  uint32_t vaddr = 0;
  for (i = 0; i < N_KERNEL_PTS; i++)
  {
    index = page_alloc(TRUE);
    kernel_ptabs[i] = page_map[index].addr;
    insert_ptab_dir(kernel_pdir, kernel_ptabs[i], vaddr, PE_RW | PE_P);
    j = 0;
    while(j < PAGE_N_ENTRIES && vaddr < MAX_PHYSICAL_MEMORY)
    {
      init_ptab_entry(kernel_ptabs[i], vaddr, vaddr, PE_RW | PE_P);
      vaddr += PAGE_SIZE;
      j++;
    }
  }
  set_ptab_entry_flags(kernel_pdir, SCREEN_ADDR, PE_US | PE_RW | PE_P);
}

/* TODO2: Set up a page directory and page table for a new 
 * user process or thread. */
void setup_page_table(pcb_t * p)
{
  // special case for thread virtual memory setup
  if(p->is_thread)
  {
      p->page_directory = kernel_pdir;
      return; 
  }
  //page directory
  int index;
  index = page_alloc(TRUE);
  p->page_directory = page_map[index].addr;
  page_map[index].page_dir = page_map[index].addr;
  page_map[index].pid = p->pid;
  bzero((char *)p->page_directory, PAGE_SIZE);
  //user stack page tables
  uint32_t vaddr = p->user_stack;
  int i, j, index2;
  index = page_alloc(FALSE);
  page_map[index].pid = p->pid;
  insert_ptab_dir(p->page_directory, page_map[index].addr, vaddr, PE_US | PE_RW | PE_P);
  for (i = get_tab_idx(vaddr), j = 0; i >= 0, j < N_PROCESS_STACK_PAGES; i--, j++, vaddr -= PAGE_SIZE) 
  { 
    index2 = page_alloc(FALSE);
    page_map[index2].pid = p->pid;
    page_map[index2].page_dir = p->page_directory;
    init_ptab_entry(page_map[index].addr, vaddr, page_map[index2].addr, PE_US | PE_RW | PE_P);
  }
  // process page tables
  for (vaddr = p->start_pc; vaddr < p->start_pc + p->swap_size * SECTOR_SIZE;) 
  {
    index = page_alloc(FALSE);
    insert_ptab_dir(p->page_directory, page_map[index].addr, vaddr, PE_US | PE_RW | PE_P);
    page_map[index].pid = p->pid;
    page_map[index].page_dir = p->page_directory;
    vaddr += (PAGE_N_ENTRIES - get_tab_idx(vaddr) - 1) * PAGE_SIZE;
  }
  //kernel page table
  for (i = 0; i < N_KERNEL_PTS; i++) 
    insert_ptab_dir(p->page_directory, kernel_ptabs[i], 0, PE_US | PE_RW | PE_P);
}

/* TODO2: Swap into a free page upon a page fault.
 * This method is called from interrupt.c: exception_14(). 
 * Should handle demand paging.
 */
void page_fault_handler(void)
{
  lock_acquire(&page_lock);

  current_running->page_fault_count++;
  int index = page_alloc(FALSE);
  page_swap_in(index);

  lock_release(&page_lock);
}

/* Get the sector number on disk of a process image
 * Used for page swapping. */
int get_disk_sector(page_map_entry_t * page){
  return page->swap_loc +
    ((page->vaddr - PROCESS_START) / PAGE_SIZE) * SECTORS_PER_PAGE;
}

/* TODO2: Swap from disk into the i-th page using fault address and swap_loc of current running */
void page_swap_in(int i){
  scsi_read(get_disk_sector(&page_map[i]), page_map[i].swap_size, (char *)page_map[i].addr);
  init_ptab_entry((page_map[i].page_dir[get_dir_idx(page_map[i].vaddr)] & PE_BASE_ADDR_MASK),
  page_map[i].vaddr, page_map[i].addr, PE_US | PE_RW | PE_P);
}

uint32_t get_ptab_entry(uint32_t * pdir, uint32_t vaddr) {
  uint32_t dir_idx = get_dir_idx((uint32_t) vaddr);
  uint32_t tab_idx = get_tab_idx((uint32_t) vaddr);
  uint32_t dir_entry;
  uint32_t *tab;
  //uint32_t entry;

  dir_entry = pdir[dir_idx];

  tab = (uint32_t *) (dir_entry & PE_BASE_ADDR_MASK);

  return tab[tab_idx];
}

/* TODO: Swap i-th page out to disk.
 *   
 * Write the page back to the process image.
 * There is no separate swap space on the USB.
 * 
 */
void page_swap_out(int i){

}

/* TODO: Decide which page to replace, return the page number  */
int page_replacement_policy(void){
}


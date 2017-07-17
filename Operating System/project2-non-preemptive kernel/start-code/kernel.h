/* kernel.h: definitions used by kernel code */

#ifndef KERNEL_H
#define KERNEL_H

#define NUM_REGISTERS 8

#include "common.h"

/* ENTRY_POINT points to a location that holds a pointer to kernel_entry */
#define ENTRY_POINT ((void (**)(int)) 0x0f00)

/* System call numbers */
enum {
    SYSCALL_YIELD,
    SYSCALL_EXIT,
};

/* All stacks should be STACK_SIZE bytes large
 * The first stack should be placed at location STACK_MIN
 * Only memory below STACK_MAX should be used for stacks
 */
enum {
    STACK_MIN=0x4000 ,
    STACK_SIZE=0x1000,
    STACK_MAX=0x7fff ,
};

/*xv6 pro.h*/
struct context {
	uint32_t edi;
	uint32_t esi;
	uint32_t ebx;
	uint32_t ebp;
	uint32_t eip;
};
enum procstate { 
	READY, RUNNING, BLOCKED, EXITED
};
typedef struct pcb {
	//uint32_t sz; // Size of process memory (bytes)
	//pde_t* pgdir; // Page table
	//char *kstack; // Bottom of kernel stack for this process
	enum procstate state; // Process state
	int pid; // Process ID
	//struct proc *parent; // Parent process
	//struct trapframe *tf; // Trap frame for current syscall
	struct context *context; // swtch() here to run process
	//void *chan; // If non−zero, sleeping on chan
	//int killed; // If non−zero, have been killed
	//struct file *ofile[NOFILE]; // Open files
	//struct inode *cwd; // Current directory
	//char name[16]; // Process name (debugging)
	uint64_t runtime; //runtime
	int line; //print line
} pcb_t;
/*xv6 pro.h*/

/* The task currently running.  Accessed by scheduler.c and by entry.s assembly methods */
extern pcb_t *current_running;

void kernel_entry(int fn);

#endif                          /* KERNEL_H */

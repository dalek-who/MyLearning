/*
   kernel.c
   the start of kernel
   */

#include "common.h"
#include "kernel.h"
#include "scheduler.h"
#include "th.h"
#include "util.h"
#include "queue.h"

#include "tasks.c"

pcb_t *current_running;
queue_t ready_queue, blocked_queue;
pcb_t *ready_arr[NUM_TASKS], *blocked_arr[NUM_TASKS];

/*
   this function is the entry point for the kernel
   It must be the first function in the file
   */
struct queue R_Queue, B_Queue;
struct pcb Pcb[NUM_TASKS];
void _start(void){

	/*Set up the single entry-point for system calls */
	*ENTRY_POINT = &kernel_entry;

	/* some scheduler queue initialize */
	/*need studet add */
	ready_queue = &R_Queue;
	ready_queue->pcbs=ready_arr;
	queue_init(ready_queue);
	ready_queue->capacity = NUM_TASKS;

	blocked_queue = &B_Queue;
	blocked_queue->pcbs=blocked_arr;
	queue_init(blocked_queue);
	blocked_queue->capacity = NUM_TASKS;

	clear_screen(0, 0, 80, 25);

	/* Initialize the pcbs and the ready queue */
	/*need student add */
	int i = 0;
	while(i < NUM_TASKS) {
		//Pcb[i].sz = ; // Size of process memory (bytes)
		//Pcb[i].pgdir = ; // Page table
		//Pcb[i].kstack = ; // Bottom of kernel stack for this process
		Pcb[i].state = READY; // Process state
		Pcb[i].pid = i; // Process ID
		//Pcb[i].parent = ; // Parent process
		//Pcb[i].tf = ; // Trap frame for current syscall
		Pcb[i].context = STACK_MAX - (STACK_SIZE * i) - sizeof(struct context); // swtch() here to run process
		Pcb[i].context->edi = 0;
		Pcb[i].context->esi = 0;
		Pcb[i].context->ebx = 0;
		Pcb[i].context->ebp = STACK_MAX - (STACK_SIZE * i);
		Pcb[i].context->eip = task[i]->entry_point;
		//Pcb[i].chan = ; // If non−zero, sleeping on chan
		//Pcb[i].killed = ; // If non−zero, have been killed
		//Pcb[i].ofile[NOFILE] = ; // Open files
		//Pcb[i].cwd = ; // Current directory
		//Pcb[i].name[16] = ; // Process name (debugging)
		Pcb[i].runtime = 0;
		Pcb[i].line = 20 + i;
		queue_push(ready_queue, Pcb + i);
		i++;
	}

	/*Schedule the first task */
	scheduler_count = 0;
	scheduler_entry();

	/*We shouldn't ever get here */
	ASSERT(0);
	
}

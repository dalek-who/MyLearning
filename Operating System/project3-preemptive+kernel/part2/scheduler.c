#include "common.h"
#include "interrupt.h"
#include "queue.h"
#include "printf.h"
#include "scheduler.h"
#include "util.h"
#include "syslib.h"

pcb_t *current_running;
node_t ready_queue;
node_t sleep_wait_queue;
// more variables...
volatile uint64_t time_elapsed;
#define NUMBER 65
#define MAX 100
int priority_time[NUMBER] = {0};
int count;

/* TODO:wake up sleeping processes whose deadlines have passed */
void check_sleeping(){
	pcb_t *pcb;
	pcb = (pcb_t *)peek(&sleep_wait_queue);
	while (pcb != NULL) {
		if (pcb->deadline <= time_elapsed) {
			pcb->status = READY;
			enqueue(&ready_queue, dequeue(&sleep_wait_queue));
			pcb = (pcb_t *)peek(&sleep_wait_queue);
		}
		else break;
	}
}

/* scheduling: Save current_running before preempting */
void put_current_running(){
  // TO-DO: Do we want to wake up sleeping processes here as well?
	current_running->status = READY;
	enqueue(&ready_queue, (node_t *)current_running);
	check_sleeping();
}

/* Change current_running to the next task */
void scheduler(){
  ASSERT(disable_count);
  check_sleeping(); // wake up sleeping processes
  while (is_empty(&ready_queue)){     
    leave_critical();
    enter_critical();
    check_sleeping();
  }
	int i;
	pcb_t *first;
	first = (pcb_t *) dequeue(&ready_queue);
	current_running = first;
	count = 0;
	//current_running = (pcb_t *) dequeue(&ready_queue);
	while(TRUE){
		if(count == 1 && first == current_running){
			//priority_time[0] = 0;
			for(i = 1; i < NUMBER; i++)
				priority_time[i] = 2 * i;
		}
		if(priority_time[current_running->priority] == 0){
			enqueue(&ready_queue, (node_t *)current_running);
			current_running = (pcb_t *) dequeue(&ready_queue);
		}
		else{
			priority_time[current_running->priority]--;
			//if(priority_time[current_running->priority] == 0)
				//priority_time[0]--;
			//else if(priority_time[current_running->priority] == 2 * current_running->priority - 1)
				//priority_time[0]++;
			break;
		}
		count = 1;
	}
			
  ASSERT(NULL != current_running);
  ++current_running->entry_count;
}

int lte_deadline(node_t *a, node_t *b) {
  pcb_t *x = (pcb_t *)a;
  pcb_t *y = (pcb_t *)b;

  if (x->deadline <= y->deadline) {
    return 1;
  } else {
    return 0;
  }
}

/* TODO: Blocking sleep. Caution: this function currently cannot be pre-empted! */
void do_sleep(int milliseconds){

	ASSERT(!disable_count);
	enter_critical();
	current_running->deadline = time_elapsed + milliseconds;
	while(current_running->deadline >= time_elapsed){
		current_running->status = SLEEPING;
		enqueue_sort(&sleep_wait_queue, (node_t *)current_running, (node_lte)&lte_deadline);
		break;
	}
	scheduler_entry();	
	leave_critical();
}

/* Do not modify any of the following functions */

void do_yield(){
  enter_critical();
  put_current_running();
  scheduler_entry();
  leave_critical();
}

void do_exit(){
  enter_critical();
  current_running->status = EXITED;
  scheduler_entry();
  /* No need for leave_critical() since scheduler_entry() never returns */
}

void block(node_t * wait_queue){
  ASSERT(disable_count);
  current_running->status = BLOCKED;
  enqueue(wait_queue, (node_t *) current_running);
  scheduler_entry();
}

void unblock(pcb_t * task){
  ASSERT(disable_count);
  task->status = READY;
  enqueue(&ready_queue, (node_t *) task);
}

pid_t do_getpid(){
  pid_t pid;  
  enter_critical();
  pid = current_running->pid;
  leave_critical();
  return pid;
}

uint64_t do_gettimeofday(void){
  return time_elapsed;
}

priority_t do_getpriority(){
  priority_t priority;  
  enter_critical();
  priority = current_running->priority;
  leave_critical();
  return priority;
}

void do_setpriority(priority_t priority){
  if( priority >= 1 ){
    enter_critical();
    current_running->priority = priority;
    leave_critical();
  }
}


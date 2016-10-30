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
int  circle_count;
/* TODO:wake up sleeping processes whose deadlines have passed */
void check_sleeping(){
     node_t *p=NULL;
     pcb_t  *t=NULL;
     p=&sleep_wait_queue;
	 while(p->next!=&sleep_wait_queue){ 
                p=p->next;               
	 	t=(pcb_t *)p;   
 		if(t->deadline<time_elapsed){
	        dequeue(p->prev);
 		enqueue(&ready_queue,p);
                t->status=READY;
                break;
 		}
 	      } 

}
/* scheduling: Save current_running before preempting */
void put_current_running(){
  // TO-DO: Do we want to wake up sleeping processes here as well?
  current_running->status=READY;
  enqueue(&ready_queue,(node_t *)current_running);
   
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
  node_t *p=&ready_queue;
  circle_count++;
   //
   if(circle_count%10>6){
     while(p->next!=&ready_queue&&((pcb_t *)(p->next))->priority!=2)
         p=p->next;
     if(p->next!=&ready_queue)
     current_running = (pcb_t *) dequeue(p);
     else
     current_running = (pcb_t *) dequeue(&ready_queue);
  }
  else
  current_running = (pcb_t *) dequeue(&ready_queue);
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
        enqueue(&sleep_wait_queue,(node_t *)current_running);
        current_running->status=SLEEPING;
	current_running->deadline = time_elapsed + milliseconds;        
	while(current_running->deadline > time_elapsed)
		break;
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


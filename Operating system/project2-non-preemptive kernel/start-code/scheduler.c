/* scheduler.c */

#include "common.h"
#include "kernel.h"
#include "scheduler.h"
#include "util.h"
#include "queue.h"

int scheduler_count;
char * strings1 = "The rhalf time of tast ";
char * strings2 = "The total time of tast ";
int type = 0;//0 fair scheduler; 1 FIFO

void scheduler(void)
{
    ++scheduler_count;

    /* pop new pcb off ready queue */
	/* need studnet add */
	//fair--the early version
	/*
	struct pcb *Pcb[5];
	int flag = 1, num = 0, min = 0, count = 0;
	while(flag)
	{
		Pcb[num] = queue_pop(ready_queue);
		num++;
		if(ready_queue->isEmpty == TRUE)
			flag = 0;
	}
	while(count < num)
	{
		if((Pcb[count]->runtime) < (Pcb[min]->runtime))
			min = count;
		count++;
	}
	while(num > 0)
	{
		num--;
		if(num != min)
			queue_push(ready_queue, Pcb[num]);
	}
	current_running = Pcb[min];*/
	int min, i, j, count;

	if(ready_queue->isEmpty) 
		current_running = NULL;
	else if(type == 0)
	{
		min = ready_queue->head;
		i = (ready_queue->head + 1) % ready_queue->capacity;
		while(i != ready_queue->tail)
		{
			if((ready_queue->pcbs[i]->runtime) < (ready_queue->pcbs[min]->runtime))
				min = i;
			i++;
			i %= ready_queue->capacity;
		}
		current_running = ready_queue->pcbs[min];
		for(i = min; i != ready_queue->head;)
		{
			j = i;
			i = i + ready_queue->capacity - 1;
			i %= ready_queue->capacity;
			ready_queue->pcbs[j] = ready_queue->pcbs[i];
		}
		ready_queue->head++;
		ready_queue->head %= ready_queue->capacity;
		if( ready_queue->head == ready_queue->tail)
			ready_queue->isEmpty = TRUE;
	}
	else
		current_running = queue_pop(ready_queue);
	current_running->state = RUNNING;

}

void do_yield(void)
{
	save_pcb();
	print_str(current_running->line, 35, strings1);
	print_int(current_running->line, 57, current_running->pid);
	print_u64(current_running->line, 60, current_running->runtime);
	/* set pcb state */
	current_running->state = READY;
	/* push the currently running process on ready queue */
	/*need student add */
	queue_push(ready_queue, current_running);
	/* call scheduler_entry to start next task*/
	scheduler_entry();

	/* should never reach here */
	ASSERT(0);
}

void do_exit(void)
{
	current_running->runtime += get_timer();
	print_str(current_running->line, 35, strings2);
	print_int(current_running->line, 57, current_running->pid);
	print_u64(current_running->line, 60, current_running->runtime);
	/*need student add */
	current_running->state = EXITED;
	scheduler_entry();
}

void block(void)
{
	save_pcb();
	current_running->state = BLOCKED;
	queue_push(blocked_queue, current_running);
	scheduler_entry();
}

void unblock(void)
{
	pcb_t *Pcb;
	int i;
	int block_count = queue_size(blocked_queue);
	ready_queue->head = (ready_queue->head - block_count + ready_queue->capacity) % ready_queue->capacity;
	i = ready_queue->head;
	while(block_count > 0)
	{
		Pcb = queue_pop(blocked_queue);
		ready_queue->pcbs[i] = Pcb;
		if(ready_queue->isEmpty == TRUE)
			ready_queue->isEmpty = FALSE;
		i++;
		i %= ready_queue->capacity;
		block_count--;
	}
	/*while(block_count > 0)
	{
		Pcb = queue_pop(blocked_queue);
		Pcb->state = READY;
		queue_push(ready_queue, Pcb);
		block_count--;
	}*/
}


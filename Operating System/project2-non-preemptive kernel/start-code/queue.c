/* queue.c */

#include "queue.h"
#include "common.h"

/* Push the pcb for a task onto the queue. Return true if successful, or false if full */
bool_t queue_push(queue_t queue, pcb_t *pcb) {
	// If the queue is full, return false
	if (!queue->isEmpty && (queue->head == queue->tail)) {
		return FALSE;
	}

	// push the pcb
	queue->pcbs[queue->tail] = pcb;
	// set new tail
	queue->tail++;
	queue->tail %= queue->capacity;
	queue->isEmpty = FALSE; // manage isEmpty

	return TRUE;
}

/* Pop a pcb for a task off of the queue. */
pcb_t* queue_pop(queue_t queue) {
	// If the queue is empty, return null
	if (queue->isEmpty) {
		return NULL;
	}

	pcb_t *oPopped = queue->pcbs[queue->head];

	// set new head
	queue->head++;
	queue->head %= queue->capacity;
	// track whether queue was just made empty
	if (queue->head == queue->tail) {
		queue->isEmpty = TRUE;
	}

	return oPopped;
}

/* Initialize the queue */
void queue_init(queue_t queue) {
	queue->head = 0;
	queue->tail = 0;
	queue->isEmpty = TRUE;
}

/* Return the size of the queue */
uint32_t queue_size(queue_t queue) {
	uint32_t head = queue->head;
	uint32_t tail = queue->tail;
	return (queue->isEmpty) ? 0 : 
						(head < tail) ? (tail - head) : (tail + queue->capacity - head);
}

/* DEBUG
void queue_print(queue_t queue) {
	uint32_t i;
	printf("queue with %d members.\n\t\t", queue_size(queue));

	for(i = 0; i < QUEUE_SIZE; i++) {
		if(i == queue->head && i == queue->tail) {
			printf("HDTL->");
		}
		else if(i == queue->head) {
			printf("HEAD->");
		}
		else if(i == queue->tail) {
			printf("TAIL->");
		}
		else {
			printf("%4d->", i);
		}
	}
	printf("\n");
} */

/* DEBUG
int main() {
	struct queue q_struct; //force static allocation
	queue_t q = &q_struct;
	int i;

	queue_init(q); // should have q of size 5

	printf("testing QUEUE_SIZE enqueues\n");
	for(i = 0; i < QUEUE_SIZE; i++) {
		printf("enqueue");
		queue_push(q, (pcb_t *) &i);
		queue_print(q);	
	}
	for(i = 0; i < QUEUE_SIZE; i++) {
		printf("dequeue");
		queue_pop(q
			);
		queue_print(q);	
	}

}*/

/* thread.h: Implementation of locks, condition variables, semaphores, and
   barriers */
#ifndef THREAD_H
#define THREAD_H

#include "queue.h"
//we do begin
lock_id do_lock_init(void);
void do_lock_acquire(lock_id i);
void do_lock_release(lock_id i);
void lock_sheet_init();
//we do end
typedef struct lock {
    enum {
        UNLOCKED,
        LOCKED,
	UNUSED//we do for
    } status;
    node_t wait_queue;

    /* Who currently holds this lock? */
    struct pcb  *owner;
} lock_t;

typedef struct {
  /* A list of threads blocking on this condition variable */
  node_t        wait_queue;

} condition_t;

typedef struct {
  /* The value of this semaphore. */
  unsigned      value;

  /* An ordered list of processes waiting for this semaphore */
  node_t        wait_queue;
} semaphore_t;

typedef struct {
  /* We accumulate a list of processes which
   * are waiting for this barrier until a
   * quorum has been reached.
   */

  /* The quorum size */
  unsigned      quorum;

  /* The number of processes who are already waiting */
  unsigned      size;

  /* The list of processes who are already waiting */
  node_t        wait_queue;
} barrier_t;

//we do begin
typedef enum{
	OTHERS,
	LOCK,
	CONDITION,
	SEMAPHORE,
	BARRIER
}situation_t;

typedef struct node_info{
	struct node_info *prev, *next;
	situation_t x;
	lock_t *l;
	condition_t *c;
	semaphore_t *s;
	barrier_t *b;
}node_info_t;
/*
void node_put(node_info_t * queue, node_info_t * item);
node_info_t *node_get(node_info_t * queue);
*/
void unblock_mailbox_wait(node_t * wait_queue);
//we do end
// Prototypes
// Lock functions
void lock_init(lock_t *);
int lock_acquire(lock_t *); // return 0 on success, 1 on failure (extra credit)
void lock_release(lock_t *);

// Initialize c
void condition_init(condition_t * c);

// Unlock m and block on condition c, when unblocked acquire lock
// m
void condition_wait(lock_t * m, condition_t * c);

// Unblock first thread enqueued on c
void condition_signal(condition_t * c);

// Unblock all threads enqueued on c
void condition_broadcast(condition_t * c);

// Semaphore functions
void semaphore_init(semaphore_t * s, int value);
void semaphore_up(semaphore_t * s);
void semaphore_down(semaphore_t * s);

// Initialize a barrier, to block all processes entering the
// barrier until N processes have entered
void barrier_init(barrier_t * b, int n);

// Make calling process wait at barrier until all N processes have
// called barrier_wait()
void barrier_wait(barrier_t * b);

#endif

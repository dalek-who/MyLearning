/* thread.c

   Implementation of locks and condition variables
 */

#include "common.h"
#include "interrupt.h"
#include "queue.h"
#include "scheduler.h"
#include "sync.h"
#include "util.h"
#include "kernel.h"

//we do for the change
lock_t mylock[MAX_LOCK];
void lock_sheet_init()
{
	int i;
	for(i = 0; i < MAX_LOCK; i++)
		mylock[i].status = UNUSED;
}
lock_id do_lock_init(void)
{
	int i;
	for(i = 0; i < MAX_LOCK; i++)
		if(mylock[i].status == UNUSED)
		{
			lock_init(&mylock[i]);
			return i;
		}
	return -1;
}
void do_lock_acquire(lock_id i)
{
	if(i >= 0 && i < MAX_LOCK)
		lock_acquire(&mylock[i]);
}
void do_lock_release(lock_id i)
{
	if(i >= 0 && i < MAX_LOCK)
		lock_release(&mylock[i]);
}
void node_put(node_info_t * queue, node_info_t * item)
{
    item->prev = queue->prev;
    item->next = queue;
    item->prev->next = item;
    item->next->prev = item;
}
node_info_t *node_get(node_info_t * queue)
{
    node_t *item;

    item = queue->next;
    if (item == queue) {
        item = NULL;
    } else {
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }
    return item;
}
void unblock_mailbox_wait(node_t * wait_queue)
{
    pcb_t *p;
	enter_critical();
    ASSERT(disable_count);
    p = (pcb_t *) queue_get(wait_queue);
    if (NULL != p) {
        unblock(p);
    }
	leave_critical();
}
void block_mail(node_t *wait_queue)
{
	enter_critical();
	block(wait_queue);
	leave_critical();
}
//we do for the change*/

static int check_for_deadlock(pcb_t *owner, pcb_t *src)
{
  int timeout;
  pcb_t *i;
  for(i=owner, timeout=get_max_pcbs(); i && i->waiting_for_lock && timeout >= 0; i=i->waiting_for_lock->owner, timeout--)
  {
    if( i == src )
      return 1;
  }

  return 0;
}

static pcb_t * unblock_one(node_t * wait_queue)
{
    pcb_t *p;

    ASSERT(disable_count);
    p = (pcb_t *) queue_get(wait_queue);
    if (NULL != p) {
		//we do begin
		if(current_running->node_queue.x == LOCK)
			p->node_queue.l = current_running->node_queue.l;
		else if(current_running->node_queue.x == CONDITION)
			p->node_queue.c = current_running->node_queue.c;
		else if(current_running->node_queue.x == SEMAPHORE)
			p->node_queue.s = current_running->node_queue.s;
		else if(current_running->node_queue.x == BARRIER)
			p->node_queue.b = NULL;
		//we do end 
        unblock(p);
        return p;
    } else {
        return NULL;
    }
}

static void unblock_all(node_t * wait_queue)
{
  while( unblock_one(wait_queue) )
    {}
}

/* Initialize a lock */
void lock_init(lock_t * l)
{
    /* No critical section; it is the caller's responsibility to make sure
       that locks are initialized only once */
    l->status = UNLOCKED;
    l->owner = NULL;
    queue_init(&l->wait_queue);
}

// return 0 on success, 1 on failure (extra credit)
static int lock_acquire_helper(lock_t * l)
{
    ASSERT(disable_count);
    if (LOCKED == l->status)
    {
        current_running->waiting_for_lock = l;

        if( check_for_deadlock(l->owner, current_running) )
        {
          current_running->waiting_for_lock = NULL;
          return 1;
        }
        block(&l->wait_queue);
    }
    else
    {
      current_running->waiting_for_lock = NULL;
      l->owner = current_running;
    }
	//we do begin
	current_running->node_queue.l = l;
	//we do end
    l->status = LOCKED;

    return 0;
}

// return 0 on success, 1 on failure (extra credit)
int lock_acquire(lock_t * l)
{
    enter_critical();
    int result = lock_acquire_helper(l);
    leave_critical();

    return result;
}

static void lock_release_helper(lock_t * l)
{
    ASSERT(disable_count);
	//we do begin
	current_running->node_queue.x = LOCK;
	//we do end
    pcb_t *p = unblock_one(&l->wait_queue);
    if( p )
    {
      p->waiting_for_lock = NULL;
      l->owner = p;
    }
    else
    {
      l->owner = NULL;
    }
	//we do begin
	current_running->node_queue.l = NULL;
	//we do end
    l->status = UNLOCKED;
}

void lock_release(lock_t * l)
{
    enter_critical();
    lock_release_helper(l);
    leave_critical();
}

/* Initialize a condition variable */
void condition_init(condition_t * c)
{
    queue_init( &c->wait_queue );
}

/* Release m and block the thread (enqueued on c).  When unblocked,
   reacquire m */
void condition_wait(lock_t * m, condition_t * c)
{
  enter_critical();
  lock_release_helper(m);

  ASSERT(disable_count);
  block( &c->wait_queue );
  lock_acquire_helper(m);
  
  leave_critical();

}

/* Unblock the first thread waiting on c, if extant */
void condition_signal(condition_t * c)
{
  enter_critical();
  ASSERT(disable_count);
	//we do begin
	current_running->node_queue.x = CONDITION;
	//we do end
  unblock_one( &c->wait_queue );
	//we do begin
	current_running->node_queue.c = NULL;
	//we do end
  leave_critical();
}

/* Unblock all threads waiting on c */
void condition_broadcast(condition_t * c)
{
  enter_critical();
  ASSERT(disable_count);
	//we do begin
	current_running->node_queue.x = CONDITION;
	//we do end
  unblock_all( &c->wait_queue );
	//we do begin
	current_running->node_queue.c = NULL;
	//we do end
  leave_critical();
}

/* Initialize a semaphore with the specified value */
void semaphore_init(semaphore_t * s, int value)
{
  s->value = value;
  queue_init( &s->wait_queue );
}

/* Increment the semaphore value atomically */
void semaphore_up(semaphore_t * s)
{
  enter_critical();
	//we do begin
	current_running->node_queue.x = SEMAPHORE;
	//we do end
  if(s->value < 1 && !queue_empty(&s->wait_queue))
    unblock_one(&s->wait_queue);
  else
    s->value++;
	//we do begin
	current_running->node_queue.s = NULL;
	//we do end

  leave_critical();
}

/* Block until the semaphore value is greater than zero and decrement it */
void semaphore_down(semaphore_t * s)
{
  enter_critical();
	
  if( s->value < 1 )
    block( &s->wait_queue );
  else{
	  s->value--;
	//we do begin
	current_running->node_queue.s = s;
	//we do end
  }

  leave_critical();
}

/* Initialize a barrier.  n is number of threads that rendezvous at the
   barrier */
void barrier_init(barrier_t * b, int n)
{
  b->quorum = n;
  b->size = 0;
  queue_init( &b->wait_queue );
}

/* Block until all n threads have called barrier_wait */
void barrier_wait(barrier_t * b)
{
  enter_critical();

  if( b->size + 1 >= b->quorum )
  {
    b->size = 0;
	//we do begin
	current_running->node_queue.x = BARRIER;
	//we do end
    unblock_all( &b->wait_queue );
  }
  else
  {
    b->size ++;
	//we do begin
	current_running->node_queue.b = b;
	//we do end
    block( &b->wait_queue );
  }

  leave_critical();
}




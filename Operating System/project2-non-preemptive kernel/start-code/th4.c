#include "common.h"
#include "scheduler.h"
#include "util.h"
#include "lock.h"

#define MSDELAY 250

lock_t lock;

void thread11(void)
{
	lock_init(&lock);
		thread_print("lock initialized by thread 1!");
		
	lock_acquire(&lock);
		thread_print("lock acquired by thread 1! yielding...");
		
	do_yield();
		thread_print("thread 1 in context!");
		
		thread_print("thread 1 releasing lock");
		
	lock_release(&lock);
		thread_print("thread 1 exiting");
		
	do_exit();
}

void thread12(void)
{
	while(1) {
			thread_print("thread 2 in context!");
			
	    do_yield();
	}
}

void thread13(void)
{
		thread_print("thread 3 in context! yielding...");
		
	do_yield();
		thread_print("thread 3 acquiring lock!");
		
	lock_acquire(&lock);
		thread_print("thread 3 in context! releasing lock!!");
		
	lock_release(&lock);
		thread_print("thread 3 exiting");
		
	do_exit();
}

void thread14(void)
{
		thread_print("thread 4 in context! acquiring lock...");
		
	lock_acquire(&lock);
		thread_print("thread 4 in context! releasing lock...");
		
	lock_release(&lock);
		thread_print("thread 4 exiting!");
		
	do_exit();
}

int line = 0;

void thread_print(char * toPrint) {
//	clear_screen(0, 0, 80, 25);
	print_str(line, 0, toPrint);
	line++;
	delay(MSDELAY);

}

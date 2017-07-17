#include "common.h"
#include "scheduler.h"
#include "util.h"

uint64_t time;
char * string = "thread: ";

void thread4(void)
{
	time = get_timer();
	do_yield();
	do_exit();
}

void thread5(void)
{
	time = get_timer() - time;
	print_str(0, 0, string);
	print_int(0, 10, time);
	do_exit();
}

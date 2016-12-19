#include "common.h"
#include "syslib.h"
#include "util.h"

char *string = "process: ";
int flag = 1;
uint64_t time, last_time;

void _start(void)
{

	time = get_timer();
	if (flag) {
		last_time = time; 
		flag = 0;
		yield();
		exit();
	}
	else {
		print_str(2, 0, string);
		print_int(2, 10, time - last_time);
    		exit();
	}
	
}

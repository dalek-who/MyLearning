#include "kernel.h"
#include "scheduler.h"

void ps_thread(void)
{
	do_setpriority(2);
  for(;;)
  {
    print_status();
    do_yield();
  }
}

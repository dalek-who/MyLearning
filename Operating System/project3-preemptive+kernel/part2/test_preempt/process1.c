#include "printf.h"

void _start(void)
{
	setpriority(3);
  int i;
  for(i=0; ;++i)
  {
    printf(2,1, "Process 1: %d", i);
  }
}


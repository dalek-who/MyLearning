#include "printf.h"

void _start(void)
{
	setpriority(4);
  int i;
  for(i=0; ;++i)
  {
    printf(3,1, "Process 2: %d", i);
  }
}

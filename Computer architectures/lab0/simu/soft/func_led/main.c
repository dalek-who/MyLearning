#include <asm/context.h>
#include <asm/mipsregs.h>

int main()
{
	return 0;
}

#define LUI(r,imm) (0x3c000000|((r)<<16)|(imm))
#define ORI(rt,rs,imm) (0x34000000|((rs)<<21)|((rt)<<16)|(imm))
#define JR(r) (8|((r)<<21))	
#define NOP 0

int mymain()
{
#if 0
*(volatile int *)0x80000000 = LUI(27,0x9fc0);
*(volatile int *)0x80000004 = ORI(27,27,0x0200);
*(volatile int *)0x80000008 = JR(27);
*(volatile int *)0x8000000c = NOP;

*(volatile int *)0x80000180 = LUI(27,0x9fc0);
*(volatile int *)0x80000184 = ORI(27,27,0x0380);
*(volatile int *)0x80000188 = JR(27);
*(volatile int *)0x8000018c = NOP;

#endif
 return main();
}

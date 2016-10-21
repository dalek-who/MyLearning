TOPDIR=$(shell pwd)

CFLAGS := -D_KERNEL -DCONFIG_PAGE_SIZE_16KB -fno-builtin -mips32 -DCACHELOCK_MEM -DMEMSTART=0xbfc80000 -DMEMSIZE=0x01000 -DCPU_COUNT_PER_US=10 -I $(TOPDIR)/include -include common.h -DAPB_CLK=33333333
CFLAGS += -DLS1FSOC  -DCPU_MULT=6 -DDDR_MULT=6

export TOPDIR AR CFLAGS

export CROSS_COMPILE ?= mipsel-linux-
all: main.bin convert
	./convert
	cp flash.vlog ../../../run_ise/.

libtinyc.a libtinyc64.a:
	make -C lib $(TOPDIR)/$@
libm.a:
	make -C libm $(TOPDIR)/$@

.SUFFIXES: .o64 .elf64 .bin64

%.elf:%.o start.o libtinyc.a libm.a
	${CROSS_COMPILE}gcc -E -P -Umips -D_LOADER -U_MAIN $(CFLAGS) bin.lds.S -o bin.lds
	${CROSS_COMPILE}ld -g -T  bin.lds  -o $@ start.o $<  -L . -ltinyc -lm
	${CROSS_COMPILE}objdump -ald $@ > test.s

%.bin:%.elf
	${CROSS_COMPILE}objcopy -O binary $< $@ 

%.elf64:%.o64 start64.o64 libtinyc64.a libm.a
	${CROSS_COMPILE}ld -g -T  bin64.lds -Ttext 0 -o $@ start64.o64 $<  -L . -ltinyc64 -lm


%.bin64:%.elf64
	${CROSS_COMPILE}objcopy -O binary $< $@ 

testbin:
	gcc -o testbin testbin.c
convert:convert.c
	gcc -o convert convert.c
clean:
	rm -f *.o *.bin *.elf *.a testbin *.o64 *.bin64 *.elf64 *.s *.vlog
	make -C lib clean
	make -C libm clean

-include rules.make

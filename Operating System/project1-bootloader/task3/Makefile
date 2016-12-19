# Makefile for the OS projects.
# Best viewed with tabs set to 4 spaces.

CC = gcc
LD = ld

# Where to locate the kernel in memory
KERNEL_ADDR	= 0x1000


CCOPTS = -Wall -O0 -g -m32 -c -fomit-frame-pointer -fno-builtin

LDOPTS = -nostartfiles -nostdlib -melf_i386

# Makefile targets

all: bootblock image

bootblock: bootblock.o
	$(LD) $(LDOPTS) -Ttext 0x0 -o bootblock $<


# Create an image to put on the floppy
image: bootblock  
	./createimage.given --extended bootblock


# Clean up!
clean:
	rm -f *.o
	rm -f createimage image bootblock 

# No, really, clean up!
distclean: clean
	rm -f *~
	rm -f \#*
	rm -f *.bak
	rm -f serial.out
	rm -f bochsout.txt

# How to compile a C file
%.o:%.c
	$(CC) $(CCOPTS) $<

# How to assemble
%.o:%.s
	$(CC) $(CCOPTS) $<

# How to produce assembler input from a C file
%.s:%.c
	$(CC) $(CCOPTS) -S $<

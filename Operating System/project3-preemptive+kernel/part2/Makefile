### Makefile for Project 3, COS 318


# C compiler and linker
CC = gcc
LD = ld

# Entry points of the kernel and the processes
KERNEL_ADDR = 0x1000
PROC1_ADDR = 0x10000
PROC2_ADDR = 0x20000

## Assembler flags
# 32-bit code generation
ASFLAGS += -m32

# Compiler flags
#-fno-builtin:		Don't recognize builtin functions that do not begin
#			with '__builtin_' as prefix.
#
#-fomit-frame-pointer:	Don't keep the frame pointer in a register for 
#			functions that don't need one.
#
#-make-program-do-what-i-want-it-to-do:
#			Turn on all friendly compiler flags.
#
#-O2:			Turn on all optional optimizations except for loop
#			unrolling and function inlining.
#
#-c:			Compile or assemble the source files, but do not link.
#
#-Wall:			All of the `-W' options combined (all warnings on)

## C compiler flags
# Normally, we would select c99, but we need inline assembly
CFLAGS += -std=gnu99
# 32-bit code generation
CFLAGS += -m32
# No external environment
CFLAGS += -ffreestanding
# Turn on all warnings and make them errors
CFLAGS += -Wall -Wextra #-Werror
# Turn on optimization
#CFLAGS += -O2 -fomit-frame-pointer -fno-builtin
CFLAGS += -O0 -fomit-frame-pointer -fno-builtin
# -fstack-protector is not compatible with -ffreestanding
CFLAGS += -fno-stack-protector
# -funit-at-time reorders functions---we need the entry point to be first in the object file
CFLAGS += -fno-unit-at-a-time
# Specify the memory layout with #defines
CFLAGS += -DKERNEL_ADDR=$(KERNEL_ADDR)
CFLAGS += -DPROC1_ADDR=$(PROC1_ADDR)
CFLAGS += -DPROC2_ADDR=$(PROC2_ADDR)
# Add debugging symbols
CFLAGS += -g -c

## Linker flags
# 32-bit code generation
LDFLAGS += -melf_i386
# Don't use the standard startup files or libraries
LDFLAGS += -nostdlib
# Specify a location on a per-target basis
LDFLAGS += -Ttext


## First Makefile target
# Create a generic image to put on a boot medium
all : kernel process1 process2
	./createimage --extended bootblock kernel process1 process2

createimage : createimage.c
	$(CC) -Wall $^ -o $@

# Put the boot block at the specified address
bootblock : LDFLAGS += 0x0000
bootblock : bootblock.o

kernel : LDFLAGS += $(KERNEL_ADDR)
# Important: the entry point is in kernel.o, so it must come first
kernel : kernel.o entry.o interrupt.o queue.o scheduler.o sync.o util.o printf.o barrier_test.o philosophers.o th1.o th2.o

kernel_test : LDFLAGS += $(KERNEL_ADDR)
# Important: the entry point is in kernel.o, so it must come first
kernel_test : kernel.o entry.o interrupt.o queue.o scheduler.o sync.o util.o printf.o th1.o th2.o

process1 : LDFLAGS += $(PROC1_ADDR)
# Important: the entry point is in process1.o, so it must come first
process1 : process1.o syslib.o util.o printf.o

process2 : LDFLAGS += $(PROC2_ADDR)
process2 : process2.o syslib.o util.o printf.o helper.o

# How to compile a C file
%.o : %.c
	$(CC) $(CFLAGS) $<

# Override the default implicit rule to call $(LD) directly
% : %.o
	$(LD) $(LDFLAGS) $^ -o $@


# Copy the image to the USB drive in the fishbowl lab
# WARNING: make sure this is right before you make this target on another system
boot : image
	cat image > /dev/sdf

# Dependency management
depend : .depend
.depend :
	$(CC) -MM *.c *.S > $@

# Clean up!
clean :
	-rm -f image kernel process1 process2 *.o .depend serial.out log.txt bochsout.txt

cleantest: clean
		-rm -f process*.* philosophers.* barrier_test.* tasks.* th*.*

.PHONY : boot depend clean distclean

# Inform make of the dependencies found by gcc
# The dash causes make to make .depend if it doesn't exist
-include .depend


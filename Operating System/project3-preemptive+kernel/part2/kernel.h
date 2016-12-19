/* kernel.h */
/* Do not change this file */

#ifndef KERNEL_H
#define KERNEL_H

#include "common.h"

void print_status(void);

extern int (*syscall[NUM_SYSCALLS]) ();

enum {
    /* Used to set Timer 0 frequency.
       Alternate values are for instance 1193 (1000 Hz) and 119 (10 000
       Hz). The last value will be too have the timer interrupt fire too
       often, so try something higher! */
    PREEMPT_TICKS = 1193,       /* Timer interrupt every 1ms */

    /* Kernel code segment descriptor */
    KERNEL_CS = 1 << 3,

    /*
     * IDT - Interrupt Descriptor Table
     * GDT - Global Descriptor Table
     * TSS - Task State Segment
     */
    GDT_SIZE = 7,
    IDT_SIZE = 49,
    IRQ_START = 32,             /* remapped irq0 IDT entry */
    INTERRUPT_GATE = 0x0e,      /* interrupt gate descriptor */
    IDT_SYSCALL_POS = 48,       /* system call IDT entry */
};

/* Structure describing the contents of the idt and gdt registers. Used
   for loading the idt and gdt registers. */
struct point_t {
    uint16_t limit;
    uint32_t base;
} __attribute__ ((packed));

/* Shut down the computer */
void do_shutdown(void);

/* Write a character to the serial port */
void do_write_serial(int character);


#endif                          /* KERNEL_H */

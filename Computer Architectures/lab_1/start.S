#/*	$Id: start.S,v 1.1.1.1 2006/09/14 01:59:08 root Exp $ */

/*
 * Copyright (c) 2001 Opsycon AB  (www.opsycon.se)
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Opsycon AB, Sweden.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef _KERNEL
#define _KERNEL
#endif

#include <asm/asm.h>
#include <asm/regdef.h>
#include <cpu.h>
#include <machine.h>
#include <ns16550.h>
#include <asm/context.h>

#define UART_BASEADDR          	0xbfe40000 
#define INST_SRAM_BASEADDR      0xa0000000
#define DATA_SRAM_BASEADDR      0xa8000000
#define CONFREG_BASE            0xbfd00000

#define CONFREG_CR01_CSN        0xbfd00004
#define CONFREG_CR02_A_G        0xbfd00008


	.set	noreorder
	.globl	_start
	.globl	start
	.globl	__main
_start:
start:
	mtc0	zero, c0_status
	mtc0	zero, c0_cause
	la	sp, _stack
	la	gp, _gp

	bal	locate			/* Get current execute address */
	nop

/*
 *  exception handle
 */
locate:
	.set noreorder

#COPY your data to inst_sram
    la    v0, DATA_SRAM_BASEADDR
    la    a0, you_data_begin
    la    a1, you_data_end
1:
    lw    a2, 0(a0)
    addiu a0, 4
    addiu v0, 4
    bne   a0, a1, 1b
    sw    a2, -4(v0)

#COPY your code to inst_sram
    la    v0, INST_SRAM_BASEADDR
    la    a0, you_code_begin
    la    a1, you_code_end
    addiu a1, a1, 4
1:
    lw    a2, 0(a0)
    addiu a0, 4
    addiu v0, 4
    bne   a0, a1, 1b
    sw    a2, -4(v0)

#jump to inst_sram, run your code
    la    v0, INST_SRAM_BASEADDR
    jalr  v0

#jump to main
    la	v0, mymain
    jalr	v0
    nop

1:
    b	1b
    nop

you_code_begin:
#######################################################################
### YOUR CODE
#######################################################################
#TODO:code by you
    move t9, ra
#a0 for temp compare
#a1 for temp flag

    la     t0, CONFREG_BASE
#t1 for date_base    
    la     t1, DATA_SRAM_BASEADDR
#t2 t3 for a repetition 10 times
    ori    t2, zero, 0x01
    ori    t3, zero, 0x200
#t4 for index
#t5 for temp save num
#t6 for 4
#t7  for 2
    ori    t4,zero,0x0
    move   t5, zero
    ori   t6, zero,0x04
    ori   t7, zero,0x02
#t8 for temp save count 

#close the led
	not a3,zero
	sh a3,(t0)

LEDNUMBACK:
    mtc0   zero,c0_count

    addi t1,t1,20
    add t1,t1,t4
    lb a0,0(t1)
    sub t1,t1,t4
    addi t1,t1,-20

    andi a1,t4,1
    bne a1,zero,3f 
    nop
	addi a0,a0,10
3:
	add t1,t1,a0
    lb t5,0(t1)
    sub t1,t1,a0
	
    sb t5,8(t0)

    not    t2,t2
    sb     t2,4(t0)
    not    t2,t2

    addiu  t4,t4,1

    bne    t2, t3, 1f
    sll    t2, t2, 1    
    ori    t2, zero, 0x01
    ori    t4,zero,0x0

    lb t5,27(t1)
    addi t5,t5,1
    slti a0,t5,10
    bne a0,zero,5f
    nop
    addi t5,t5,-10
5:    
    sb t5,27(t1)

    lb t5,26(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,10
    bne a0,zero,5f
    nop
    addi t5,t5,-10
5:
       
    sb t5,26(t1)

    lb t5,25(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,10
    bne a0,zero,5f
    nop
    addi t5,t5,-10
5:   
    sb t5,25(t1)

    lb t5,24(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,6
    bne a0,zero,5f
    nop
    addi t5,t5,-6
5:
        
    sb t5,24(t1)

    lb t5,23(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,10
    bne a0,zero,5f
    nop
    addi t5,t5,-10
5:   
    sb t5,23(t1)

    lb t5,22(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,6
    bne a0,zero,5f
    nop
    addi t5,t5,-6
5:
      
    sb t5,22(t1)

    lb t5,21(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,10
    bne a0,zero,5f
    nop
    addi t5,t5,-10
5:

    bne t5,t6,6f
    xori a1,zero,1
6:
    sb t5,21(t1)


    lb t5,20(t1)
    xori a0,a0,1
    add t5,t5,a0
    slti a0,t5,10
    bne a0,zero,5f
    nop
    addi t5,t5,-10
5:
    bne t5, t7, 6f
    nop
    beq a1,zero,6f
    nop

    move t5,zero
    sb zero,21(t1)

6:    
       
    sb t5,20(t1)


    
1:  
     
    bal    WAITMS
    nop

    bal    LEDNUMBACK
    nop


WAITMS:
    mfc0   t8,c0_count
    slti  a0,t8,0x4074
    bne   a0,zero,WAITMS
    nop

    jr     ra
    nop



    move ra, t9
##code end
############
you_code_end:
    jr    ra
    nop

	.rdata
you_data_begin:
#######################################################################
### YOUR DATA
#######################################################################
#TODO:data defined by you
#for example:
#ones need dot,tens don't
#ones come first, start from 0.
    .byte 0xfd
    .byte 0x61
    .byte 0xdb
    .byte 0xf3
    .byte 0x67
    .byte 0xb7
    .byte 0xbf
    .byte 0xe1
    .byte 0xff
    .byte 0xf7
#these are tens without . start from 0    
    .byte 0xfc
    .byte 0x60
    .byte 0xda
    .byte 0xf2
    .byte 0x66
    .byte 0xb6
    .byte 0xbe
    .byte 0xe0
    .byte 0xfe
    .byte 0xf6
#these are eight numbers , start from the lowest
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0



##datae end
############
you_data_end:
      .word 0x0

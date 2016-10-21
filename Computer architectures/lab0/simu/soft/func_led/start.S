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

    la     t0, CONFREG_BASE
    ori    t1, zero, 0x0001
    ori    t2, zero, 0x8000
    
LEDBACK:
    sw     t1, 0x0(t0)
    lui    a0, 0x000f
    bal    WAITSEC
    ori    a0, a0, 0xffff
    bne    t1, t2, 1f
    sll    t1, t1, 1
    ori    t1, zero, 0x0001
    
1:    
    bal    LEDBACK
    nop

WAITSEC:
    bne    a0, zero, WAITSEC
    addi   a0, a0, -1
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
      .word 0xf2da60fc
      .word 0xe0beb666
      .word 0x0000f6fe
##datae end
############
you_data_end:
      .word 0x0

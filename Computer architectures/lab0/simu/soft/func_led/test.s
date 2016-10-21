
main.elf:     file format elf32-tradlittlemips
main.elf


Disassembly of section .text:

bfc00000 <_ftext>:
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:56
bfc00000:	40806000 	mtc0	zero,c0_status
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:57
bfc00004:	40806800 	mtc0	zero,c0_cause
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:58
bfc00008:	3c1dbfc8 	lui	sp,0xbfc8
bfc0000c:	27bd0fe0 	addiu	sp,sp,4064
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:59
bfc00010:	3c1cbfc9 	lui	gp,0xbfc9
bfc00014:	279c8000 	addiu	gp,gp,-32768
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:61
bfc00018:	04110001 	bal	bfc00020 <locate>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:62
bfc0001c:	00000000 	nop

bfc00020 <locate>:
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:71
bfc00020:	3c02a800 	lui	v0,0xa800
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:72
bfc00024:	3c04bfc0 	lui	a0,0xbfc0
bfc00028:	24840100 	addiu	a0,a0,256
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:73
bfc0002c:	3c05bfc0 	lui	a1,0xbfc0
bfc00030:	24a5010c 	addiu	a1,a1,268
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:75
bfc00034:	8c860000 	lw	a2,0(a0)
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:76
bfc00038:	24840004 	addiu	a0,a0,4
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:77
bfc0003c:	24420004 	addiu	v0,v0,4
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:78
bfc00040:	1485fffc 	bne	a0,a1,bfc00034 <locate+0x14>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:79
bfc00044:	ac46fffc 	sw	a2,-4(v0)
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:82
bfc00048:	3c02a000 	lui	v0,0xa000
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:83
bfc0004c:	3c04bfc0 	lui	a0,0xbfc0
bfc00050:	24840094 	addiu	a0,a0,148
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:84
bfc00054:	3c05bfc0 	lui	a1,0xbfc0
bfc00058:	24a500dc 	addiu	a1,a1,220
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:85
bfc0005c:	24a50004 	addiu	a1,a1,4
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:87
bfc00060:	8c860000 	lw	a2,0(a0)
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:88
bfc00064:	24840004 	addiu	a0,a0,4
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:89
bfc00068:	24420004 	addiu	v0,v0,4
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:90
bfc0006c:	1485fffc 	bne	a0,a1,bfc00060 <locate+0x40>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:91
bfc00070:	ac46fffc 	sw	a2,-4(v0)
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:94
bfc00074:	3c02a000 	lui	v0,0xa000
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:95
bfc00078:	0040f809 	jalr	v0
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:98
bfc0007c:	3c02bfc0 	lui	v0,0xbfc0
bfc00080:	244200f8 	addiu	v0,v0,248
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:99
bfc00084:	0040f809 	jalr	v0
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:100
bfc00088:	00000000 	nop
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:103
bfc0008c:	1000ffff 	b	bfc0008c <locate+0x6c>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:104
bfc00090:	00000000 	nop

bfc00094 <you_code_begin>:
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:111
bfc00094:	03e0c821 	move	t9,ra
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:113
bfc00098:	3c08bfd0 	lui	t0,0xbfd0
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:114
bfc0009c:	34090001 	li	t1,0x1
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:115
bfc000a0:	340a8000 	li	t2,0x8000

bfc000a4 <LEDBACK>:
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:118
bfc000a4:	ad090000 	sw	t1,0(t0)
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:119
bfc000a8:	3c04000f 	lui	a0,0xf
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:120
bfc000ac:	04110006 	bal	bfc000c8 <WAITSEC>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:121
bfc000b0:	3484ffff 	ori	a0,a0,0xffff
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:122
bfc000b4:	152a0002 	bne	t1,t2,bfc000c0 <LEDBACK+0x1c>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:123
bfc000b8:	00094840 	sll	t1,t1,0x1
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:124
bfc000bc:	34090001 	li	t1,0x1
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:127
bfc000c0:	0411fff8 	bal	bfc000a4 <LEDBACK>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:128
bfc000c4:	00000000 	nop

bfc000c8 <WAITSEC>:
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:131
bfc000c8:	1480ffff 	bnez	a0,bfc000c8 <WAITSEC>
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:132
bfc000cc:	2084ffff 	addi	a0,a0,-1
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:133
bfc000d0:	03e00008 	jr	ra
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:134
bfc000d4:	00000000 	nop
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:136
bfc000d8:	0320f821 	move	ra,t9

bfc000dc <you_code_end>:
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:140
bfc000dc:	03e00008 	jr	ra
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/start.S:141
bfc000e0:	00000000 	nop
	...

bfc000f0 <main>:
main():
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/main.c:7
bfc000f0:	03e00008 	jr	ra
bfc000f4:	00001021 	move	v0,zero

bfc000f8 <mymain>:
mymain():
/home/ucas/cpu_lab/lab_0_20161010/simu/soft/func_led/main.c:29
bfc000f8:	03e00008 	jr	ra
bfc000fc:	00001021 	move	v0,zero

bfc00100 <you_data_begin>:
you_data_begin():
bfc00100:	f2da60fc 	0xf2da60fc
bfc00104:	e0beb666 	sc	s8,-18842(a1)
bfc00108:	0000f6fe 	0xf6fe

bfc0010c <you_data_end>:
you_data_end():
bfc0010c:	00000000 	nop
bfc00110:	b2000774 	0xb2000774
	...

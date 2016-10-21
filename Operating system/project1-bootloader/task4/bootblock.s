.section .data
.global _start
.code16

_start:
  jmp	load_kernel

# Area reserved for createimage to write the OS size
# num of sector
#position should not be changed
os_size:
        .word   0
        .word   0


# setup registers for kernel data and disk read
load_kernel:
  movw	$0x07c0,%bx
  movw	%bx,%ds
  movb	os_size,%al
  movw	$0x0000,%bx
  movw	%bx,%ds
  movb	$0x2,%cl
  movb	$0x0,%ch
  movb	$0x0,%dl
  movb	$0x0,%dh
  movb	$0x2,%ah
  movw	$0x0000,%bx
  movw	%bx,%es
  movw	$0x1000,%bx
  int 	$0x13
  jmp	setup_stack	

#setup the kernel stack
setup_stack:
  movw	$0x9001,%sp
  movw	%sp,%ss
  movw	$0xfff0,%sp
  movw	$0xfff0,%bp

#switch control to kernel
switch_to_kernel:
  jmp	*%bx

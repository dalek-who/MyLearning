.section .data
.global _start
.code16

_start:
  jmp	before_load1

# Area reserved for createimage to write the OS size
# num of sector
#position should not be changed
os_size:
        .word   0
        .word   0
# setup registers for kernel data and disk read
before_load1:
  cmp	$0xf000,%bx
  jne	load_bootblock
  jmp	before_load2
# once move the bootblock, and twice load kernel 

load_bootblock:
  movw	$0x0000,%bx
  movw	%bx,%es
  movw	$0xf000,%bx
  movb	$0x02,%ah
  movb	$0x01,%al
  movb	$0x00,%ch
  movb	$0x01,%cl
  movb	$0x00,%dh
  movb	$0x00,%dl
  int 	$0x13
  jmp	*%bx
# move the bootblock to 0x0f000

before_load2:
  movw	$0x0f00,%bx
  movw	%bx,%ds
  movw	os_size,%si
  movw	$0x0000,%bx
  movw	%bx,%ds
# get the os_size, and store in %si

  movb	$0x00,%ch
  movb	$0x00,%dl
  movb	$0x00,%dh
  movb	$0x02,%cl
  movw	$0x0000,%bx
  movw	%bx,%es
  movw  $0x1000,%bx
# setup for int0x13 02H

  movb	$0x11,%al
  movb	$0x00,%ah
  cmp	%ax,%si
  jbe	load_kernel_last
# judge the size of kernel
# load_kernel_last: the number of kernel sectors <= the number of sectors
# continue: >

  movb	$0x02,%ah
  int 	$0x13
# the fisrt load - (the number of sectors - 1) sectors

  movb	$0x01,%cl
  inc	%al
  inc	%si
  subw	$0x0200,%bx
# due to the special of the first load, we need to change the %bx, %si and %al,for the loop

after_load1:
  shl	$9,%ax
  addw	%ax,%bx
  shr	$9,%ax
# get the next address for loading

  subw	%ax,%si
# get the rest of sectors

  addb	%dh,%ch
# if %dh=0x01, then inc %ch, else do nothing

  cmp	$0x01,%dh
  je	after_load2
  inc	%dh
  inc	%dh
# if %dh=0x01,then jmp to dec %dh, else inc %dh,(but "inc" twice,due to the next "dec")

after_load2:
  dec	%dh
  cmp	%ax,%si
  jbe	load_kernel_last
# judge the size of the rest of kernel
# load_kernel: the number of kernel sectors > the number of sectors
# continue: <=

load_kernel:
  movb	$0x02,%ah
  int	$0x13
# the load loop

load_kernel_last:
  movw	%si,%ax
  movb	$0x02,%ah
  int	$0x13
# the last load

#setup the kernel stack
setup_stack:
  movw	$0x9001,%sp
  movw	%sp,%ss
  movw	$0xfff0,%sp
  movw	$0xfff0,%bp

#switch control to kernel
switch_to_kernel:
  movw	$0x0000,%bx
  movw	%bx,%ds
  movw	$0x1000,%bx
  jmp	*%bx

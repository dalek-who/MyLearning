# entry.S
##

	.data
	.text
	.code32

	.globl	kernel_entry
kernel_entry:
	movl %ecx, %eax
	movl 4(%esp), %ecx
	# do_yield if ecx is 0
	jecxz no_exit

exit_process:
	movl %eax, %ecx
	# we're assuming that if %eax is not 0, then it is 1
	call do_exit
	ret

no_exit:
	movl %eax, %ecx
	pushl %ebp
	movl %esp, %ebp
	call do_yield
	popl %ebp
	ret


.globl	scheduler_entry
scheduler_entry:
	# call scheduler, which will set new current running process
	# need student add
	call scheduler
	movl current_running,%ecx
	movl 8(%ecx),%esp
	popl %edi
	popl %esi
	popl %ebx
	popl %ebp

	#time 
	rdtsc
	subl %eax,12(%ecx)
	sbbl %edx,16(%ecx)

	ret



# Saves the pcb of the currently running process. Use EIP from above stack base pointer
.globl save_pcb
save_pcb:
	#the important is ebp and esp
	# need student add
	movl current_running,%ecx

	#time 
	rdtsc
	addl %eax,12(%ecx)
	adcl %edx,16(%ecx)

	popl %eax
	movl %ebp,%edx
	subl %esp,%edx
	movl %ebp,%esp
	pushl %ebx
	pushl %esi
	pushl %edi
	movl %esp,8(%ecx)
	movl %esp,%ebp
	subl %edx,%esp
	pushl %eax

	ret
	

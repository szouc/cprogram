	.file	"Ch05_21.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -12(%rbp)
	leaq	-12(%rbp), %rsi
	leaq	.LC0(%rip), %rdi
	call	__isoc99_scanf@PLT
	movslq	-12(%rbp), %rax         %rax = n
	leaq	18(,%rax,4), %rax       n = n * 4 + 24
	andq	$-16, %rax              n = n & 0xfffffffffffffff0
	subq	%rax, %rsp              sp = sp - n
	leaq	3(%rsp), %rax           n = sp + 3
	shrq	$2, %rax                n = n >> 2
	movl	$255, 0(,%rax,4)
	movl	$255, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	jne	.L4
	movl	$0, %eax
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

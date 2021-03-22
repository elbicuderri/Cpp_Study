	.file	"WhyNot.c"
	.text
Ltext0:
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
LFB16:
	.file 1 "WhyNot.c"
	.loc 1 5 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	.loc 1 6 17
	movl	16(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
LBB2:
	.loc 1 8 11
	movl	$0, -12(%ebp)
	.loc 1 8 2
	jmp	L2
L3:
	.loc 1 9 11 discriminator 3
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %ecx
	.loc 1 9 18 discriminator 3
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	.loc 1 9 4 discriminator 3
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	-16(%ebp), %eax
	addl	%ebx, %eax
	.loc 1 9 15 discriminator 3
	addl	%ecx, %edx
	.loc 1 9 8 discriminator 3
	movl	%edx, (%eax)
	.loc 1 8 26 discriminator 3
	addl	$1, -12(%ebp)
L2:
	.loc 1 8 2 discriminator 1
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	L3
LBE2:
	.loc 1 14 9
	movl	-16(%ebp), %eax
	.loc 1 15 1
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.loc 1 19 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	.loc 1 19 1
	call	___main
LVL0:
	.loc 1 20 17
	movl	$12, (%esp)
	call	_malloc
	movl	%eax, 32(%esp)
	.loc 1 21 17
	movl	$12, (%esp)
	call	_malloc
	movl	%eax, 28(%esp)
LBB3:
	.loc 1 23 11
	movl	$0, 44(%esp)
	.loc 1 23 2
	jmp	L6
L7:
	.loc 1 24 4 discriminator 3
	movl	44(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	32(%esp), %eax
	addl	%edx, %eax
	.loc 1 24 12 discriminator 3
	movl	44(%esp), %edx
	addl	%edx, %edx
	.loc 1 24 8 discriminator 3
	movl	%edx, (%eax)
	.loc 1 23 26 discriminator 3
	addl	$1, 44(%esp)
L6:
	.loc 1 23 2 discriminator 1
	cmpl	$2, 44(%esp)
	jle	L7
LBE3:
LBB4:
	.loc 1 27 11
	movl	$0, 40(%esp)
	.loc 1 27 2
	jmp	L8
L9:
	.loc 1 28 12 discriminator 3
	movl	40(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%eax, %edx
	.loc 1 28 4 discriminator 3
	movl	40(%esp), %eax
	leal	0(,%eax,4), %ecx
	movl	28(%esp), %eax
	addl	%ecx, %eax
	.loc 1 28 16 discriminator 3
	subl	$2, %edx
	.loc 1 28 8 discriminator 3
	movl	%edx, (%eax)
	.loc 1 27 26 discriminator 3
	addl	$1, 40(%esp)
L8:
	.loc 1 27 2 discriminator 1
	cmpl	$2, 40(%esp)
	jle	L9
LBE4:
	.loc 1 31 17
	movl	$12, (%esp)
	call	_malloc
	movl	%eax, 24(%esp)
	.loc 1 33 6
	movl	$3, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	_add
	movl	%eax, 24(%esp)
LBB5:
	.loc 1 35 11
	movl	$0, 36(%esp)
	.loc 1 35 2
	jmp	L10
L11:
	.loc 1 36 19 discriminator 3
	movl	36(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	.loc 1 36 3 discriminator 3
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	.loc 1 35 26 discriminator 3
	addl	$1, 36(%esp)
L10:
	.loc 1 35 2 discriminator 1
	cmpl	$2, 36(%esp)
	jle	L11
LBE5:
	.loc 1 39 2
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	.loc 1 40 2
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	.loc 1 41 2
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	.loc 1 44 9
	movl	$0, %eax
	.loc 1 45 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
Letext0:
	.file 2 "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/i686-w64-mingw32/include/stdio.h"
	.file 3 "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/i686-w64-mingw32/include/crtdefs.h"
	.file 4 "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/i686-w64-mingw32/include/stdlib.h"
	.file 5 "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/i686-w64-mingw32/include/malloc.h"
	.section	.debug_info,"dr"
Ldebug_info0:
	.long	0x46d
	.word	0x4
	.secrel32	Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.ascii "GNU C17 8.1.0 -mtune=generic -march=i686 -g\0"
	.byte	0xc
	.ascii "WhyNot.c\0"
	.ascii "C:\\GitHub\\Cpp_Study\0"
	.long	Ltext0
	.long	Letext0-Ltext0
	.secrel32	Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x3
	.ascii "wchar_t\0"
	.byte	0x3
	.byte	0x62
	.byte	0x18
	.long	0x91
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x4
	.byte	0x4
	.long	0x62
	.uleb128 0x4
	.byte	0x4
	.long	0x81
	.uleb128 0x4
	.byte	0x4
	.long	0x7a
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "long unsigned int\0"
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0x5
	.ascii "_iobuf\0"
	.byte	0x20
	.byte	0x2
	.byte	0x1a
	.byte	0xa
	.long	0x18c
	.uleb128 0x6
	.ascii "_ptr\0"
	.byte	0x2
	.byte	0x1b
	.byte	0xb
	.long	0xc4
	.byte	0
	.uleb128 0x6
	.ascii "_cnt\0"
	.byte	0x2
	.byte	0x1c
	.byte	0x9
	.long	0x7a
	.byte	0x4
	.uleb128 0x6
	.ascii "_base\0"
	.byte	0x2
	.byte	0x1d
	.byte	0xb
	.long	0xc4
	.byte	0x8
	.uleb128 0x6
	.ascii "_flag\0"
	.byte	0x2
	.byte	0x1e
	.byte	0x9
	.long	0x7a
	.byte	0xc
	.uleb128 0x6
	.ascii "_file\0"
	.byte	0x2
	.byte	0x1f
	.byte	0x9
	.long	0x7a
	.byte	0x10
	.uleb128 0x6
	.ascii "_charbuf\0"
	.byte	0x2
	.byte	0x20
	.byte	0x9
	.long	0x7a
	.byte	0x14
	.uleb128 0x6
	.ascii "_bufsiz\0"
	.byte	0x2
	.byte	0x21
	.byte	0x9
	.long	0x7a
	.byte	0x18
	.uleb128 0x6
	.ascii "_tmpfname\0"
	.byte	0x2
	.byte	0x22
	.byte	0xb
	.long	0xc4
	.byte	0x1c
	.byte	0
	.uleb128 0x3
	.ascii "FILE\0"
	.byte	0x2
	.byte	0x24
	.byte	0x19
	.long	0xfc
	.uleb128 0x7
	.long	0x18c
	.long	0x1a4
	.uleb128 0x8
	.byte	0
	.uleb128 0x9
	.ascii "_imp___iob\0"
	.byte	0x2
	.byte	0x5c
	.byte	0x10
	.long	0x1b7
	.uleb128 0x4
	.byte	0x4
	.long	0x199
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.ascii "double\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.ascii "float\0"
	.uleb128 0x2
	.byte	0xc
	.byte	0x4
	.ascii "long double\0"
	.uleb128 0x9
	.ascii "_imp____mb_cur_max\0"
	.byte	0x4
	.byte	0x73
	.byte	0x10
	.long	0xd0
	.uleb128 0x7
	.long	0xc4
	.long	0x20a
	.uleb128 0xa
	.long	0x6a
	.byte	0
	.byte	0
	.uleb128 0x9
	.ascii "_sys_errlist\0"
	.byte	0x4
	.byte	0xac
	.byte	0x26
	.long	0x1fa
	.uleb128 0x9
	.ascii "_sys_nerr\0"
	.byte	0x4
	.byte	0xad
	.byte	0x24
	.long	0x7a
	.uleb128 0xb
	.ascii "_imp____argc\0"
	.byte	0x4
	.word	0x119
	.byte	0x10
	.long	0xd0
	.uleb128 0xb
	.ascii "_imp____argv\0"
	.byte	0x4
	.word	0x11d
	.byte	0x13
	.long	0x25d
	.uleb128 0x4
	.byte	0x4
	.long	0x263
	.uleb128 0x4
	.byte	0x4
	.long	0xc4
	.uleb128 0xb
	.ascii "_imp____wargv\0"
	.byte	0x4
	.word	0x121
	.byte	0x16
	.long	0x280
	.uleb128 0x4
	.byte	0x4
	.long	0x286
	.uleb128 0x4
	.byte	0x4
	.long	0xca
	.uleb128 0xb
	.ascii "_imp___environ\0"
	.byte	0x4
	.word	0x127
	.byte	0x13
	.long	0x25d
	.uleb128 0xb
	.ascii "_imp___wenviron\0"
	.byte	0x4
	.word	0x12c
	.byte	0x16
	.long	0x280
	.uleb128 0xb
	.ascii "_imp___pgmptr\0"
	.byte	0x4
	.word	0x132
	.byte	0x12
	.long	0x263
	.uleb128 0xb
	.ascii "_imp___wpgmptr\0"
	.byte	0x4
	.word	0x137
	.byte	0x15
	.long	0x286
	.uleb128 0xb
	.ascii "_imp___osplatform\0"
	.byte	0x4
	.word	0x13c
	.byte	0x19
	.long	0x307
	.uleb128 0x4
	.byte	0x4
	.long	0x6a
	.uleb128 0xb
	.ascii "_imp___osver\0"
	.byte	0x4
	.word	0x141
	.byte	0x19
	.long	0x307
	.uleb128 0xb
	.ascii "_imp___winver\0"
	.byte	0x4
	.word	0x146
	.byte	0x19
	.long	0x307
	.uleb128 0xb
	.ascii "_imp___winmajor\0"
	.byte	0x4
	.word	0x14b
	.byte	0x19
	.long	0x307
	.uleb128 0xb
	.ascii "_imp___winminor\0"
	.byte	0x4
	.word	0x150
	.byte	0x19
	.long	0x307
	.uleb128 0x9
	.ascii "_amblksiz\0"
	.byte	0x5
	.byte	0x35
	.byte	0x17
	.long	0x6a
	.uleb128 0xc
	.ascii "main\0"
	.byte	0x1
	.byte	0x12
	.byte	0x5
	.long	0x7a
	.long	LFB17
	.long	LFE17-LFB17
	.uleb128 0x1
	.byte	0x9c
	.long	0x40e
	.uleb128 0xd
	.ascii "x\0"
	.byte	0x1
	.byte	0x14
	.byte	0x7
	.long	0xd0
	.uleb128 0x2
	.byte	0x74
	.sleb128 32
	.uleb128 0xd
	.ascii "y\0"
	.byte	0x1
	.byte	0x15
	.byte	0x7
	.long	0xd0
	.uleb128 0x2
	.byte	0x74
	.sleb128 28
	.uleb128 0xd
	.ascii "z\0"
	.byte	0x1
	.byte	0x1f
	.byte	0x7
	.long	0xd0
	.uleb128 0x2
	.byte	0x74
	.sleb128 24
	.uleb128 0xe
	.long	LBB3
	.long	LBE3-LBB3
	.long	0x3db
	.uleb128 0xd
	.ascii "i\0"
	.byte	0x1
	.byte	0x17
	.byte	0xb
	.long	0x7a
	.uleb128 0x2
	.byte	0x74
	.sleb128 44
	.byte	0
	.uleb128 0xe
	.long	LBB4
	.long	LBE4-LBB4
	.long	0x3f6
	.uleb128 0xd
	.ascii "i\0"
	.byte	0x1
	.byte	0x1b
	.byte	0xb
	.long	0x7a
	.uleb128 0x2
	.byte	0x74
	.sleb128 40
	.byte	0
	.uleb128 0xf
	.long	LBB5
	.long	LBE5-LBB5
	.uleb128 0xd
	.ascii "i\0"
	.byte	0x1
	.byte	0x23
	.byte	0xb
	.long	0x7a
	.uleb128 0x2
	.byte	0x74
	.sleb128 36
	.byte	0
	.byte	0
	.uleb128 0x10
	.ascii "add\0"
	.byte	0x1
	.byte	0x4
	.byte	0x6
	.long	0xd0
	.long	LFB16
	.long	LFE16-LFB16
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x11
	.ascii "a\0"
	.byte	0x1
	.byte	0x4
	.byte	0xf
	.long	0xd0
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x11
	.ascii "b\0"
	.byte	0x1
	.byte	0x4
	.byte	0x17
	.long	0xd0
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x11
	.ascii "L\0"
	.byte	0x1
	.byte	0x4
	.byte	0x1e
	.long	0x7a
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xd
	.ascii "c\0"
	.byte	0x1
	.byte	0x6
	.byte	0x7
	.long	0xd0
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xf
	.long	LBB2
	.long	LBE2-LBB2
	.uleb128 0xd
	.ascii "i\0"
	.byte	0x1
	.byte	0x8
	.byte	0xb
	.long	0x7a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"dr"
Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x1c
	.word	0x2
	.secrel32	Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	Ltext0
	.long	Letext0-Ltext0
	.long	0
	.long	0
	.section	.debug_line,"dr"
Ldebug_line0:
	.section	.debug_str,"dr"
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef

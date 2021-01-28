/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (C) 2006 Atmark Techno, Inc.
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License. See the file "COPYING" in the main directory of this archive
 * for more details.
 */

#ifndef _UAPI_ASM_PATMOS_PTRACE_H
#define _UAPI_ASM_PATMOS_PTRACE_H

#ifndef __ASSEMBLY__

typedef unsigned long patmos_reg_t; /* 32 32bit general purpose registers */
typedef unsigned long patmos_pre_t; /* 1  8bit  predicate register */
typedef unsigned long patmos_spr_t; /* 16 32bit special purpose registers */

struct pt_regs {
	patmos_reg_t r0;
	patmos_reg_t r1;
	patmos_reg_t r2;
	patmos_reg_t r3;
	patmos_reg_t r4;
	patmos_reg_t r5;
	patmos_reg_t r6;
	patmos_reg_t r7;
	patmos_reg_t r8;
	patmos_reg_t r9;
	patmos_reg_t r10;
	patmos_reg_t r11;
	patmos_reg_t r12;
	patmos_reg_t r13;
	patmos_reg_t r14;
	patmos_reg_t r15;
	patmos_reg_t r16;
	patmos_reg_t r17;
	patmos_reg_t r18;
	patmos_reg_t r19;
	patmos_reg_t r20;
	patmos_reg_t r21;
	patmos_reg_t r22;
	patmos_reg_t r23;
	patmos_reg_t r24;
	patmos_reg_t r25;
	patmos_reg_t r26;
	patmos_reg_t r27;
	patmos_reg_t r28;
	patmos_reg_t r29;
	patmos_reg_t r30;
	patmos_reg_t r31;

    patmos_pre_t preds;

    patmos_spr_t s0;
    patmos_spr_t s1;
    patmos_spr_t s2;
    patmos_spr_t s3;
    patmos_spr_t s4;
    patmos_spr_t s5;
    patmos_spr_t s6;
    patmos_spr_t s7;
    patmos_spr_t s8;
    patmos_spr_t s9;
    patmos_spr_t s10;
    patmos_spr_t s11;
    patmos_spr_t s12;
    patmos_spr_t s13;
    patmos_spr_t s14;
    patmos_spr_t s15;
};

#ifndef __KERNEL__

/* pt_regs offsets used by gdbserver etc in ptrace syscalls */
/*#define PT_GPR(n)	((n) * sizeof(patmos_reg_t))
#define PT_PC		(32 * sizeof(patmos_reg_t))
#define PT_MSR		(33 * sizeof(patmos_reg_t))
#define PT_EAR		(34 * sizeof(patmos_reg_t))
#define PT_ESR		(35 * sizeof(patmos_reg_t))
#define PT_FSR		(36 * sizeof(patmos_reg_t))
#define PT_KERNEL_MODE	(37 * sizeof(patmos_reg_t))
*/

#endif /* __KERNEL */

#endif /* __ASSEMBLY__ */

#endif /* _UAPI_ASM_PATMOS_PTRACE_H */

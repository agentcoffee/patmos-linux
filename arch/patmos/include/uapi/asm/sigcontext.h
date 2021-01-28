/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */
#ifndef _ASM_PATMOS_SIGCONTEXT_H
#define _ASM_PATMOS_SIGCONTEXT_H


struct sigcontext {
    struct pt_regs regs;        /* context */
	unsigned long  sc_mask;		/* old sigmask */
};

#endif /* _ASM_PATMOS_SIGCONTEXT_H */

/* SPDX-License-Identifier: GPL-2.0-only */
/*
 *  Port on Texas Instruments TMS320C6x architecture
 *
 *  Copyright (C) 2004, 2009, 2011 Texas Instruments Incorporated
 *  Author: Aurelien Jacquiot (aurelien.jacquiot@jaluna.com)
 */
#ifndef _ASM_PATMOS_STRING_H
#define _ASM_PATMOS_STRING_H

#include <asm/page.h>
#include <linux/linkage.h>

#define __HAVE_ARCH_MEMCPY

extern void *memcpy(void *to, const void *from, size_t n);

#endif /* _ASM_PATMOS_STRING_H */

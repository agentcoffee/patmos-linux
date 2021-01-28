/* SPDX-License-Identifier: GPL-2.0-only */
/*
 *  Port on Texas Instruments TMS320C6x architecture
 *
 *  Copyright (C) 2004, 2009, 2010 2011 Texas Instruments Incorporated
 *  Author: Aurelien Jacquiot (aurelien.jacquiot@jaluna.com)
 */
#ifndef _ASM_PATMOS_SETUP_H
#define _ASM_PATMOS_SETUP_H

#include <uapi/asm/setup.h>
#include <linux/types.h>

#ifndef __ASSEMBLY__

extern unsigned long ram_start;
extern unsigned long ram_end;

extern void machine_init(unsigned long dt_ptr);
extern void time_init(void);

#endif /* !__ASSEMBLY__ */
#endif /* _ASM_PATMOS_SETUP_H */

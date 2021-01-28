// SPDX-License-Identifier: GPL-2.0-only
/*
 *  Port on Texas Instruments TMS320C6x architecture
 *
 *  Copyright (C) 2004, 2009, 2010, 2011 Texas Instruments Incorporated
 *  Author: Aurelien Jacquiot (aurelien.jacquiot@jaluna.com)
 */
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

#include <asm/syscalls.h>

/*
 * Note that we can't include <linux/unistd.h> here since the header
 * guard will defeat us; <asm/unistd.h> checks for __SYSCALL as well.
 */
void *sys_call_table[__NR_syscalls] = {
	[0 ... __NR_syscalls-1] = sys_ni_syscall,
};

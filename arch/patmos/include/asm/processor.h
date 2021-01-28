/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2008-2009 Michal Simek <monstr@monstr.eu>
 * Copyright (C) 2008-2009 PetaLogix
 * Copyright (C) 2006 Atmark Techno, Inc.
 */

#ifndef _ASM_PATMOS_PROCESSOR_H
#define _ASM_PATMOS_PROCESSOR_H

#include <asm/ptrace.h>
#include <asm/setup.h>
//#include <asm/registers.h>
//#include <asm/entry.h>
//#include <asm/current.h>

// TODO
# define cpu_relax()		do { } while(0)

#define task_pt_regs(tsk) \
		(((struct pt_regs *)(THREAD_SIZE + task_stack_page(tsk))) - 1)

/*
 * User space process size: memory size
 *
 * TASK_SIZE on MMU cpu is usually 1GB. However, on no-MMU arch, both
 * user processes and the kernel is on the same memory region. They
 * both share the memory space and that is limited by the amount of
 * physical memory. thus, we set TASK_SIZE == amount of total memory.
 */
# define TASK_SIZE	0x7fffffff

/*
 * This decides where the kernel will search for a free chunk of vm
 * space during mmap's. We won't be using it
 */
# define TASK_UNMAPPED_BASE	0

#endif /* _ASM_PATMOS_PROCESSOR_H */

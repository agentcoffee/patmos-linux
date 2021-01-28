/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _ASM_PATMOS_CACHEFLUSH_H
#define _ASM_PATMOS_CACHEFLUSH_H

#include <linux/spinlock.h>

#include <asm/setup.h>
#include <asm/cache.h>
#include <asm/mman.h>
#include <asm/page.h>
#include <asm/string.h>

/*
 * physically-indexed cache management
 */
#define flush_cache_all()				  \
do {								  \
    inval_dcache();
} while (0)

#include <asm-generic/cacheflush.h>

#endif /* _ASM_C6X_CACHEFLUSH_H */

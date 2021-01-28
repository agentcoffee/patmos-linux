/* SPDX-License-Identifier: GPL-2.0-only */
/*
 */
#ifndef _ASM_PATMOS_CMPXCHG_H
#define _ASM_PATMOS_CMPXCHG_H

#include "exceptions.h"
#include <linux/irqflags.h>

/*
 * Misc. functions
 */
static inline unsigned int __xchg(unsigned int x, volatile void *ptr, int size)
{
	unsigned int tmp;

    intr_disable();

	switch (size) {
	case 1:
		tmp = 0;
		tmp = *((unsigned char *) ptr);
		*((unsigned char *) ptr) = (unsigned char) x;
		break;
	case 2:
		tmp = 0;
		tmp = *((unsigned short *) ptr);
		*((unsigned short *) ptr) = x;
		break;
	case 4:
		tmp = 0;
		tmp = *((unsigned int *) ptr);
		*((unsigned int *) ptr) = x;
		break;
	}

    intr_enable();
	return tmp;
}

#define xchg(ptr, x) \
	((__typeof__(*(ptr)))__xchg((unsigned int)(x), (void *) (ptr), \
				    sizeof(*(ptr))))

#include <asm-generic/cmpxchg-local.h>

/*
 * cmpxchg_local and cmpxchg64_local are atomic wrt current CPU. Always make
 * them available.
 *
 * TODO: is this true on PATMOS?
 */
#define cmpxchg_local(ptr, o, n)					\
	((__typeof__(*(ptr)))__cmpxchg_local_generic((ptr),		\
						     (unsigned long)(o), \
						     (unsigned long)(n), \
						     sizeof(*(ptr))))
//#define cmpxchg64_local(ptr, o, n) __cmpxchg64_local_generic((ptr), (o), (n))

#include <asm-generic/cmpxchg.h>

#endif /* _ASM_PATMOS_CMPXCHG_H */

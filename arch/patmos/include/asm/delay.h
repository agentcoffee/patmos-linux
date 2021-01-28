/* SPDX-License-Identifier: GPL-2.0-only */
/*
 */
#ifndef _ASM_PATMOS_DELAY_H
#define _ASM_PATMOS_DELAY_H

#include <linux/kernel.h>

extern unsigned int ticks_per_ns_scaled;

static inline void __delay(unsigned long loops)
{
    for (uint32_t i = 0; i < loops; i++) ;
}

static inline void _ndelay(unsigned int n)
{
    // Assuming 3 asm instr's per iteration, this is about 40ns per iteration.
    // Shift by 6 is approx n / 32 which is good enough for now.
    for (uint32_t i = 0; i < (n >> 6); i++) ;
}

static inline void _udelay(unsigned int n)
{
	while (n >= 10) {
		_ndelay(10000);
		n -= 10;
	}
	while (n-- > 0)
		_ndelay(1000);
}

#define udelay(x) _udelay((unsigned int)(x))
#define ndelay(x) _ndelay((unsigned int)(x))

#endif /* _ASM_C6X_DELAY_H */

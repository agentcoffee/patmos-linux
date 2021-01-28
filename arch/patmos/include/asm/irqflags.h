/* SPDX-License-Identifier: GPL-2.0 */
/* Based on include/asm-generic/irqflags.h */

#ifndef __ASM_PATMOS_IRQFLAGS_H
#define __ASM_PATMOS_IRQFLAGS_H

#define ARCH_IRQ_DISABLED   0
#define ARCH_IRQ_ENABLED    0xffffffff

/* The minimal implementation necessary */
unsigned long arch_local_save_flags(void);
void arch_local_irq_restore(unsigned long flags);

#include <asm-generic/irqflags.h>

#endif /* __ASM_PATMOS_IRQFLAGS_H */

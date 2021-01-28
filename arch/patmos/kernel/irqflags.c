/* SPDX-License-Identifier: GPL-2.0 */
/* Based on include/asm-generic/irqflags.h */

/* read interrupt enabled status */
unsigned long arch_local_save_flags()
{
    return EXC_MASK;
}

/* set interrupt enabled status */
void arch_local_irq_restore(unsigned long flags)
{
    EXC_MASK = flags;
}

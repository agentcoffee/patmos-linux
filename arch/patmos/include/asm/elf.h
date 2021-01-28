/* SPDX-License-Identifier: GPL-2.0 */
/*
 */
#ifndef _ASM_PATMOS_ELF_H
#define _ASM_PATMOS_ELF_H

#include <uapi/asm/elf.h>

#ifndef __uClinux__

#ifndef ELF_GREG_T
#endif

#ifndef ELF_NGREG
#endif

#ifndef ELF_GREGSET_T
#endif

#ifndef ELF_FPREGSET_T
#endif

#define SET_PERSONALITY(ex) \
	set_personality(PER_LINUX_32BIT | (current->personality & (~PER_MASK)))
#endif /* __uClinux__ */

#endif /* _ASM_MICROBLAZE_ELF_H */

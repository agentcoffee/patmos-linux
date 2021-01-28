// SPDX-License-Identifier: GPL-2.0-only
/*
 *  Console driver for PATMOS, based on:
 *
 *  linux/arch/arm/kernel/early_printk.c
 *
 *  Copyright (C) 2009 Sascha Hauer <s.hauer@pengutronix.de>
 */

#include <linux/kernel.h>
#include <linux/console.h>
#include <linux/init.h>
#include <linux/string.h>
#include "patmos.h"

#define PATMOS_UART_REGISTER    (* (u32 *) 0xf0080000)
#define PATMOS_UART_CTRL        (* (u32 *) 0xf0080004)

static void console_write(struct console *con, const char *s, unsigned n)
{
    u32 s;

    for(unsigned i = 0; i < n; i++) {
        __PATMOS_UART_WRITE_DATA(s[i]);
        do {
            __PATMOS_UART_STATUS(s);
        } while((s & __PATMOS_UART_TRE) == 0);
    }
}

static struct console patmos_console = {
	.name =		"ttyPATMOS",
	.write =	console_write,
	.flags =	CON_PRINTBUFFER | CON_BOOT,
	.index =	-1,
};

static int __init patmos_setup_console(void)
{
    //__PATMOS_UART_WR_CTRL(data); // TODO i found no description of the UART
    // ctrl register, their newlib also has no reference to this macro.
	register_console(&patmos_console);
    return 0;
}

console_initcall(patmos_setup_console);

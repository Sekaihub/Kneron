/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (C) 2021 VATICS Inc.
 */

#include <config.h>
#include <linux/linkage.h>
#include <asm/macro.h>

.align 8
.global tfa_boot_args
tfa_boot_args:
        .dword 0
        .dword 0
        .dword 0
        .dword 0

/*
 * Routine: save_boot_params (called after reset from start.S)
 */

ENTRY(save_boot_params)
	/* The firmware provided ARGS can be found in r2/x0 */
	adr	x8, tfa_boot_args
	stp	x0, x1, [x8], #16
	stp	x2, x3, [x8], #16

	/* Returns */
	b	save_boot_params_ret
ENDPROC(save_boot_params)


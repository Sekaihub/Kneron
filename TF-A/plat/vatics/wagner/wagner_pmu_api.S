/*
 * Copyright (c) 2017-2020, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <asm_macros.S>
#include "../wagner_def.h"

	.global read_pmu_reg
	.global write_pmu_reg
	.global check_voltage_in


/*
 * uint32_t read_pmu_reg(uint32_t addr)
 * - Used register: X0~X3
 * - return value: stored in X0
 */
func read_pmu_reg
	lsl x1, x0, #8
	orr x1, x1, #1
	mov_imm x2, VPL_PMU_BASE

	/*
	 * Start bit can't work if pmu shift operation
	 * does not complete. so it needs to trigger shift
	 * reigster until start bit change from `0` to `1`
	 */
3:
	str w1, [x2, #0x10]
	ldr w0, [x2, #0x10]
	tbz w0, #0, 3b

	/*Wait shift done asserted*/
1:
	ldr w1, [x2, #0x4]
	tbz w1, #0, 1b

	/*clear shift done status*/
	mov w1, #1
	str w1, [x2, #0xC]

	/*Wait shift done staus deasserted*/
2:
	ldr w1, [x2, #0x4]
	tbnz w1, #0, 2b

	ldr w0, [x2, #0x18] /*read data*/
	ret

endfunc read_pmu_reg

/*
 * void write_pmu_reg(uint32_t addr, uint32_t val)
 * - Used register: X0~X3
 */
func write_pmu_reg
	lsl w2, w0, #8
	mov w3, #0x11
	orr w2, w2, w3
	mov_imm x3, VPL_PMU_BASE
	str w1, [x3, #0x14]  //config shift write data
	/*
	 * Start bit can't work if pmu shift operation
	 * does not complete. so it needs to trigger shift
	 * reigster until start bit change from `0` to `1`
	 */
3:
	str w2, [x3, #0x10]  //enable shift write
	ldr w0, [x3, #0x10]
	tbz w0, #0, 3b

	/*Wait shift done asserted*/
1:
	ldr w2, [x3, #0x4]
	tbz w2, #0, 1b

	/*clear shift done status*/
	mov w2, #1
	str w2, [x3, #0xC]

	/*Wait shift done staus deasserted*/
2:
	ldr w2, [x3, #0x4]
	tbnz w2, #0, 2b

	ret
endfunc write_pmu_reg
/*
 * uint32_t check_voltage_in(void)
 * - Used register: X0~X1
 * return:
 *        1: voltage exist
 *        0: voltage not exist
 */
func check_voltage_in
	mov_imm x1, VPL_PMU_BASE
	ldr w0, [x1]
	mov_imm w1, 0x10000
	and w0, w0, w1
	cmp	w0, w1
	cset    x0, eq
	ret
endfunc check_voltage_in

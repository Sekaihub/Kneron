/*
 * Copyright (c) 2017-2020, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <asm_macros.S>
#include <sysctrl.h>
#include "../wagner_def.h"

	.globl	plat_my_core_pos
	.globl  plat_wagner_calc_core_pos
	.globl  plat_is_my_cpu_primary
	.globl	plat_secondary_cold_boot_setup
	.globl  plat_crash_console_init
	.globl  plat_crash_console_putc
	.globl  plat_crash_console_flush
	.globl	platform_mem_init
	.globl	plat_report_exception
	.globl	plat_reset_handler
	.globl  plat_get_my_entrypoint
	.globl	clr_ex
	.globl	nop

/*-------------------------
 * Check Warm boot or Cold boot
 *  - X0~X6 will be used, caller needs to backup X0~X6 by itself
 *  - X5 is used to store lr registe,
 *    and x6 is used to store sysc base address,
 *    so don't overwrite them in whole function.
 *-------------------------
 */
func plat_get_my_entrypoint
	mov	x5, x30
	bl	plat_is_my_cpu_primary
	cbz	w0, 1f
	// Only pirmary core need to check invalid mode and warmboot
	mov_imm x6, SYSC_S_BASE
#if WAGNER_FPGA && FORCE_STOP
	b	.
#endif
invalid_mode:
	ldr	w1, [x6, SYSC_GENERAL_INFO]
	mov	w2, w1, lsl #16	// Backup original boot info
	and     x1, x1, #(SYSC_BOOT_MODE_MASK)
	//
	// You can change boot mode (modify X1) here for debug
	//
	cmp     x1, #(BOOT_INVALID)
	mov_imm x0, WAGNER_BOOTMODE_ADDR
	orr	w2, w2, w1
	str	w2, [x0]
	b.eq	invalid_mode
#if WAGNER_FPGA
	b	1f
#endif
	/*Check PMU_BOOT_DISABLE*/
	ldr	w0, [x6, #SYSC_CHIP_ID_INFO]
	ands	w0, w0, #PMU_BOOT_DISABLE
	b.ne	1f

	/*Check PRODUCTION_MODE*/
	ldr	w0, [x6, #SYSC_HW_CFG_0]
	ands	w0, w0, #PRODUCTION_MODE
	b.ne	1f

	/*dassert clampz*/
	mov	x0, #0xE
	bl	read_pmu_reg
	mov_imm	x1, 0x40000
	orr	x1, x0, x1
	mov_imm	x0, 0xE
	bl	write_pmu_reg

	//
	/* to distinguish between coldboot and wramboot*/
	/*pmu gpr ofs = 0x08*/
	mov	x0, #0x8
	bl read_pmu_reg
	/*backup reset status to BACKUP_PMUGPR*/
	str	w0, [x6, SYSC_CORE0_SPIN]
	/* clear PMU GPR*/
	cbz     w0, skip_write0
	mov	x1, #0
	mov	x0, #0x8
	bl	write_pmu_reg
skip_write0:
	ldr	w0, [x6, SYSC_CORE0_SPIN]
	and	x1, x0, #SUSPEND_STATUS_BIT
	cbz	x1, clear_suspend_sram //if !suspend, clear SUSPEND_FLAG_ADDR

	/*read suspend sram(0xc003a7FC)*/
	ldr	w0, =SUSPEND_FLAG_ADDR
	ldr	w2, [x0]
	/*clear SUSPEND_FLAG_ADDR before jumping to warmboot entrypoint*/
	str	wzr, [x0]

	mov_imm	w0, 0x55AA55AA
	cmp	w0, w2
	b.ne	2f
	mov_imm	x0, SUSPEND_SRAM_ENTRY
	br	x0        //Jump to warmboot entrypoint


	/*SUSPEND_FLAG_ADDR != suspend, it is coldboot*/
2:
	ldr	w1, [x6, SYSC_CORE0_SPIN]
	ldr	w0, =0xfffffffe
	and	w1, w1, w0
	str	w1, [x6, SYSC_CORE0_SPIN]
	b	1f

clear_suspend_sram:
	ldr	x0, =SUSPEND_FLAG_ADDR
	str	wzr, [x0]
	//
1:
	mov x0, #0
	ret x5
endfunc plat_get_my_entrypoint

func plat_my_core_pos
	mrs	x0, mpidr_el1
	b	plat_wagner_calc_core_pos
	ret
endfunc plat_my_core_pos

        /* -----------------------------------------------------
         * unsigned int plat_wagner_calc_core_pos(u_register_t mpidr);
         *
	 * For Cortex-A35:
         *   With this function: CorePos = CoreID (AFF0)
         *   we do it with x0 = (x0) & 0xff
	 * For Cortex-A55:
         *   With this function: CorePos = CoreID (AFF1)
         *   we do it with x0 = (x0 >> 8) & 0xff
         * -----------------------------------------------------
         */
func plat_wagner_calc_core_pos
#if (WAGNER_A35==1)
	and	x0, x0, #MPIDR_AFFLVL_MASK
#else
        mov     x1, #MPIDR_AFFLVL_MASK
        and     x0, x1, x0, lsr #MPIDR_AFF1_SHIFT
#endif
        ret
endfunc plat_wagner_calc_core_pos

	/* --------------------------------------------------------------------
	 * void plat_secondary_cold_boot_setup (void);
	 *
	 * This function performs any platform specific actions
	 * needed for a secondary cpu after a cold reset e.g
	 * mark the cpu's presence, mechanism to place it in a
	 * holding pen etc.
	 * --------------------------------------------------------------------
	 */
func plat_secondary_cold_boot_setup
	bl	plat_my_core_pos
	mov_imm	x1, SECONDARY_CPU_SPIN_BASE_ADDR
	add	x0, x1, x0, LSL #2

	/* Wait until the entrypoint gets populated */
poll_mailbox:
	ldr	w1, [x0]
	cbz	x1, 1f
	br	x1
1:
	wfe
	b	poll_mailbox
endfunc plat_secondary_cold_boot_setup

func plat_is_my_cpu_primary
	mrs     x0, mpidr_el1
	and     x0, x0, #(MPIDR_CLUSTER_MASK | MPIDR_CPU_MASK)
	cmp     x0, #PLAT_WAGNER_PRIMARY_CPU
	cset    x0, eq
	ret
endfunc plat_is_my_cpu_primary

	/* ---------------------------------------------
	 * int plat_crash_console_init(void)
	 * Function to initialize the crash console
	 * without a C Runtime to print crash report.
	 * Clobber list : x0, x1, x2
	 * ---------------------------------------------
	 */
func plat_crash_console_init
	mov_imm x1, UART_CLOCK
	mov_imm x0, UART_0
	mov_imm x2, 115200
	b       console_16550_core_init
endfunc plat_crash_console_init

	/* ---------------------------------------------
	 * int plat_crash_console_putc(int c)
	 * Function to print a character on the crash
	 * console without a C Runtime.
	 * Clobber list : x1, x2
	 * ---------------------------------------------
	 */
func plat_crash_console_putc
	mov_imm x1, UART_0
	b       console_16550_core_putc
endfunc plat_crash_console_putc

	/* ---------------------------------------------
	 * void plat_crash_console_flush()
	 * Function to force a write of all buffered
	 * data that hasn't been output.
	 * Out : void.
	 * Clobber list : r0
	 * ---------------------------------------------
	 */
func plat_crash_console_flush
	mov_imm x0, UART_0
	b       console_16550_core_flush
endfunc plat_crash_console_flush

	/* -----------------------------------------------------
	 * void platform_mem_init(void);
	 *
	 * We don't need to carry out any memory initialization
	 * on HIKEY. The Secure RAM is accessible straight away.
	 * -----------------------------------------------------
	 */
func platform_mem_init
	ret
endfunc platform_mem_init


	/* ---------------------------------------------
	 * void plat_report_exception(unsigned int type)
	 * Function to report an unhandled exception
	 * with platform-specific means.
	 * ---------------------------------------------
	 */
func plat_report_exception
	mov	x8, x30

	mrs	x2, currentel
	and	x2, x2, #0x0c
	/* Check EL1 */
	cmp	x2, #0x04
	beq	plat_report_el1

	adr	x4, plat_err_str
	bl	asm_print_str

	adr	x4, esr_el3_str
	bl	asm_print_str

	mrs	x4, esr_el3
	bl	asm_print_hex

	adr	x4, elr_el3_str
	bl	asm_print_str

	mrs	x4, elr_el3
	bl	asm_print_hex
	b	plat_report_end

plat_report_el1:
	adr	x4, plat_err_str
	bl	asm_print_str

	adr	x4, esr_el1_str
	bl	asm_print_str

	mrs	x4, esr_el1
	bl	asm_print_hex

	adr	x4, elr_el1_str
	bl	asm_print_str

	mrs	x4, elr_el1
	bl	asm_print_hex
plat_report_end:
	mov	x30, x8
	ret
endfunc plat_report_exception

	/* -----------------------------------------------------
	 * void plat_reset_handler(void);
	 * -----------------------------------------------------
	 */
func plat_reset_handler
	ret
endfunc plat_reset_handler

	/* -----------------------------------------------------
	 * void clrex(void);
	 * -----------------------------------------------------
	 */
func clr_ex
	clrex
	ret
endfunc clr_ex

	/* -----------------------------------------------------
	 * void nop(void);
	 * -----------------------------------------------------
	 */
func nop
	nop
	ret
endfunc nop

.section .rodata.rev_err_str, "aS"
plat_err_str:
	.asciz "\nPlatform exception reporting:"
esr_el3_str:
	.asciz "\nESR_EL3: "
elr_el3_str:
	.asciz "\nELR_EL3: "
esr_el1_str:
	.asciz "\nESR_EL1: "
elr_el1_str:
	.asciz "\nELR_EL1: "

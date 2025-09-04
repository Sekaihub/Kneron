/*
 * Copyright (c) 2023, VATICS INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WAGNER_DEF_H
#define WAGNER_DEF_H

#include <common/tbbr/tbbr_img_def.h>
#include <plat/common/common_def.h>

#if WAGNER_FPGA
#define SYS_COUNT_CLOCK			CLOCK_8MHZ
#define	SYS_WDT_CLOCK			CLOCK_8MHZ
#else
#define SYS_COUNT_CLOCK			CLOCK_200MHZ
#define	SYS_WDT_CLOCK			CLOCK_200MHZ
#endif

#define DDR_BASE			0x0
#define DDR_SIZE			0x40000000

#define DEVICE_BASE			0xC0000000
#define DEVICE_SIZE			0x10000000

#define CA55_BUS_BASE			CA55_DAP
#define CA55_BUS_SIZE			0x01000000

/*
 * DDR for OP-TEE (32MB from 0x3E00000-0x3FFFFFFF) is divided in several
 * regions:
 *   - Secure DDR (default is the top 16MB) used by OP-TEE
 *   - Non-secure DDR used by OP-TEE (shared memory and padding) (4MB)
 *   - Secure DDR (4MB aligned on 4MB) for OP-TEE's "Secure Data Path" feature
 *   - Non-secure DDR (8MB) reserved for OP-TEE's future use
 */
#define DDR_SEC_SIZE			0x01000000
#define DDR_SEC_BASE			0x0F000000

#define DDR_SDP_SIZE			0x00400000
#define DDR_SDP_BASE			(DDR_SEC_BASE - 0x400000 /* align */ - \
					DDR_SDP_SIZE)

/*
 * USB related constants
 */
#define CONFIG_USB_GADGET_VBUS_DRAW	2
#define BITS_PER_LONG			64
/*
 * UART related constants
 */
#define UART_0                         (VPL_UARTC0_MMR_BASE+4)
#define UART_1                         (VPL_UARTC1_MMR_BASE+4)
#define UART_2                         (VPL_UARTC2_MMR_BASE+4)
#define UART_3                         (VPL_UARTC3_MMR_BASE+4)
#define UART_4                         (VPL_UARTC4_MMR_BASE+4)
#define CLOCK_200MHZ		U(200000000)                    //UART 0/1
#define CLOCK_19MHZ		U(19200000)                     //UART 2~4
#define CLOCK_16MHZ		U(16000000)                     //FPGA
#define CLOCK_12MHZ		U(12000000)                     //FPGA
#define CLOCK_8MHZ		U(8000000)			//FPGA
#if WAGNER_FPGA
#define UART_CLOCK              CLOCK_8MHZ
#else
#define UART_CLOCK              CLOCK_200MHZ
#endif

/* warmboot/coldboot/watchdog*/
#define SUSPEND_FLAG_ADDR               0xC003A7FC
#define SUSPEND_SRAM_ENTRY              RETENTION_SRAM_BASE

/* PMU GPR*/
#define SUSPEND_STATUS_BIT		BIT(0)
#define WATCHDOG_STATUS_BIT		BIT(1)

/* Boot Watchdog */
#define BOOT_WATCHDOG_TIME			256	// sec
#define	NORMAL_FIRST_TIMEOUT			30	// sec
#define	BOOT_ERR_RESET_TIME			5	// sec

#endif /* WAGNER_DEF_H */

/* SPDX-License-Identifier: GPL-2.0+*/
/*
 * Copyright (C) 2023 VATICS Inc.
 */

#ifndef __SOC_GPIO_H__
#define __SOC_GPIO_H__

#include <asm/io.h>
#include <errno.h>

#define GPIOC_VERSION		(0x00)
#define GPIOC_DATA_OUT		(0x04)
#define GPIOC_DATA_IN		(0x08)
#define GPIOC_PIN_DIR		(0x0C)
#define GPIOC_DATA_SET		(0x14)
#define GPIOC_DATA_CLEAR	(0x18)

#define GPIOC_DATA_CLR		GPIOC_DATA_CLEAR //match kernel code

#define LEIPZIG_GPIO_COUNT_PER_BANK		32
#define LEIPZIG_GPIO_BANK_COUNT			3
#define LEIPZIG_GPIO_COUNT		        96

struct gpio_bank {
	u8 *base;	/* address of registers in physical memory */
};

/* Information about a GPIO bank */
struct vpl_gpio_plat {
	int bank_index;
	ulong base;     /* address of registers in physical memory */
};

#endif

/*
 * Copyright (C) 2018-2022, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: GPL-2.0+ OR BSD-3-Clause
 */

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>

#include <arch.h>
#include <arch_helpers.h>
#include <common/debug.h>
#include <drivers/clk.h>
#include <drivers/delay_timer.h>
#include <dt-bindings/clock/kl730-clk.h>
#include <lib/mmio.h>
#include <lib/spinlock.h>
#include <lib/utils_def.h>
#include <plat/common/platform.h>
#include <sysctrl.h>

#include <platform_def.h>

#define SYSC_SECURE_MMR_BASE SYSC_S_BASE

struct kl730_clk_gate {
	uint16_t offset;
	union {
		uint8_t index;
		struct _index_ {
			uint8_t bit : 5;
			uint8_t pll : 3;
		} mmr;
	};
};

static void __clk_enable(struct kl730_clk_gate const *gate)
{
	VERBOSE("Enable clock %x\n", gate->index);

	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_SET_REG_0
				+ (gate->mmr.pll << 2), BIT(gate->mmr.bit));
}

static void __clk_disable(struct kl730_clk_gate const *gate)
{
	VERBOSE("Disable clock %x\n", gate->index);

	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_0
				+ (gate->mmr.pll << 2), BIT(gate->mmr.bit));
}

static bool __clk_is_enabled(struct kl730_clk_gate const *gate)
{
	return mmio_read_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_0_EN_STAT
				+ (gate->mmr.pll << 2));
}

static void __kl730_clk_enable(unsigned long id, bool with_refcnt)
{
	struct kl730_clk_gate gate;

	gate.index = id;

	__clk_enable(&gate);
}

static void __kl730_clk_disable(unsigned long id, bool with_refcnt)
{
	struct kl730_clk_gate gate;

	gate.index = id;

	__clk_disable(&gate);
}

static int kl730_clk_enable(unsigned long id)
{
	__kl730_clk_enable(id, true);

	return 0;
}

static void kl730_clk_disable(unsigned long id)
{
	__kl730_clk_disable(id, true);
}

static bool kl730_clk_is_enabled(unsigned long id)
{
	struct kl730_clk_gate gate;

	gate.index = id;

	return __clk_is_enabled(&gate);
}

static unsigned long kl730_clk_get_rate(unsigned long id)
{
	return 2U;
}

int kl730_clk_init(void)
{
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_0
			, SYSC_CLK_EN_0);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_1
			, SYSC_CLK_EN_1);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_2
			, SYSC_CLK_EN_2);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_3
			, SYSC_CLK_EN_3);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_4
			, SYSC_CLK_EN_4);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_5
			, SYSC_CLK_EN_5);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_MEM_PWR_DOWN_SET_0
			, SYSC_MEM_PWR_DOWN_0);
	mmio_write_32(SYSC_SECURE_MMR_BASE + SYSC_MEM_PWR_DOWN_SET_1
			, SYSC_MEM_PWR_DOWN_1);

	return 0;
}

static const struct clk_ops kl730_clk_ops = {
	.enable		= kl730_clk_enable,
	.disable	= kl730_clk_disable,
	.is_enabled	= kl730_clk_is_enabled,
	.get_rate	= kl730_clk_get_rate,
	.get_parent	= NULL,
};

int kl730_clk_probe(void)
{
	clk_register(&kl730_clk_ops);

	return 0;
}


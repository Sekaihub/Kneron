/*
 * Watchdog Driver for Vatics watchdog timer.
 *
 * Copyright (C) 2023  VATICS Inc.
 *
 * Author: Jun Chen <jun.chen@vatics.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <lib/mmio.h>
#include <drivers/vatics/wdt.h>

static void vpl_wdt_set_timer(uint32_t sec)
{
	// WDTC counter unit: 64 APB clock cycles
	const uint32_t count_unit = SYS_WDT_CLOCK / 64;
	uint32_t count;

	if ((UINT_MAX/count_unit) < sec)
		count = UINT_MAX;
	else if (sec == 0)
		count = 1;
	else
		count = sec * count_unit;

	mmio_write_32(VPL_WDTC_OFFSET_RELOAD_VALUE, count);
}

static inline void vpl_wdt_reload(void)
{
	mmio_write_32(VPL_WDTC_OFFSET_RELOAD_CTRL, VPL_WDTC_RELOAD_PASSWD);
}

static void vpl_wdt_enable(void)
{
	uint32_t ctrl;

	ctrl = mmio_read_32(VPL_WDTC_OFFSET_CTRL);
	mmio_write_32(VPL_WDTC_OFFSET_RST_LEN, VPL_WDTC_RESET_LEN);
	mmio_write_32(VPL_WDTC_OFFSET_CTRL, ctrl | VPL_WDTC_CTRL_OP_EN);
}

int vpl_wdt_start(uint32_t sec)
{
	vpl_wdt_set_timer(sec);
	vpl_wdt_reload();
	vpl_wdt_enable();

	return 0;
}

int vpl_wdt_stop(void)
{
	uint32_t ctrl;

	ctrl = mmio_read_32(VPL_WDTC_OFFSET_CTRL);
	ctrl &= ~VPL_WDTC_CTRL_OP_EN;
	mmio_write_32(VPL_WDTC_OFFSET_CTRL, ctrl);

	return 0;
}

int vpl_wdt_ping(void)
{
	vpl_wdt_reload();

	return 0;
}

int vpl_wdt_set_timeout(uint32_t sec)
{
	vpl_wdt_set_timer(sec);
	vpl_wdt_reload();

	return 0;
}



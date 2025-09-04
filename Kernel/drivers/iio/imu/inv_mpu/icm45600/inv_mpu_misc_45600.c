/*
 * Copyright (C) 2018-2021 InvenSense, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define pr_fmt(fmt) "inv_mpu: " fmt

#include <linux/delay.h>
#include "../inv_mpu_iio.h"

/**
 * inv_set_idle() - Set Idle bit in PWR_MGMT_0 register
 * @st: struct inv_mpu_state.
 *
 * Set ACCEL_LP_CLK_SEL as well when necessary with a proper wait
 *
 * Return: 0 when successful.
 */
int inv_set_idle(struct inv_mpu_state *st)
{
	(void)st;
	return 0;
}

/**
 * inv_reset_idle() - Reset Idle bit in PWR_MGMT_0 register
 * @st: struct inv_mpu_state.
 *
 * Reset ACCEL_LP_CLK_SEL as well
 *
 * Return: 0 when successful.
 */
int inv_reset_idle(struct inv_mpu_state *st)
{
	(void)st;
	return 0;
}

static int wait_for_ireg_access_completion(struct inv_mpu_state *st)
{
	int status = 0;
	u8 ireg_done;

	do {
		status |= inv_plat_read(st, REG_REG_MISC2_DREG_BANK1, 1,
						&ireg_done);
	} while (!status && !(ireg_done & BIT_IREG_DONE));

	return status;
}


/**
 * inv_ireg_write() - bytes write to IREG area.
 * @st: struct inv_mpu_state.
 * @addr: IREG register address including bank in upper byte.
 * @size: number of bytes written into the IREG register.
 * @data: data to write.
 *
 * Return: 0 when successful.
 */
int inv_ireg_write(struct inv_mpu_state *st, int reg, int size, u8 *buf)
{
	int ret, i;

	ret = 0;
	for (i = 0; i < size; i++) {
		ret |= inv_ireg_single_write(st, reg+i, buf[i]);
	}

	return ret;
}

static int inv_ireg_access(struct inv_mpu_state *st, int addr)
{
	int ret;
	u8 d;

	wait_for_ireg_access_completion(st);
	d = ((addr >> 8) & 0xff);
	ret = inv_plat_single_write(st, REG_IREG_ADDR_15_8_DREG_BANK1, d);
	if (ret)
		return ret;
	wait_for_ireg_access_completion(st);
	d = (addr & 0xff);
	ret = inv_plat_single_write(st, REG_IREG_ADDR_7_0_DREG_BANK1, d);

	return ret;
}
/**
 * inv_ireg_single_write() - Single byte write to IREG area.
 * @st: struct inv_mpu_state.
 * @addr: IREG register address including bank in upper byte.
 * @data: data to write.
 *
 * Return: 0 when successful.
 */
int inv_ireg_single_write(struct inv_mpu_state *st, int addr, u8 data)
{
	int ret;
	u8 d;

	d = 0;
	ret = inv_plat_read(st, REG_INTF_CONFIG0_DREG_BANK1, 1, &d);
	if (ret)
		return ret;

	d |= BIT_AP_IREG_AUTO_ADDR_INC_DIS;
	ret = inv_plat_single_write(st, REG_INTF_CONFIG0_DREG_BANK1, d);
	if (ret)
		return ret;

	inv_ireg_access(st, addr);

	wait_for_ireg_access_completion(st);
	ret = inv_plat_single_write(st, REG_IREG_DATA_DREG_BANK1, data);
	if (ret)
		return ret;

	d &= (~BIT_AP_IREG_AUTO_ADDR_INC_DIS);
	ret = inv_plat_single_write(st, REG_INTF_CONFIG0_DREG_BANK1, d);

	return ret;
}

/**
 * inv_ireg_read() - Multiple byte read from IREG area.
 * @st: struct inv_mpu_state.
 * @addr: IREG register start address including bank in upper byte.
 * @len: length to read in byte.
 * @data: pointer to store read data.
 *
 * Return: 0 when successful.
 */
int inv_ireg_read(struct inv_mpu_state *st, int addr, int len, u8 *data)
{
	int ret;
	int i;

	inv_ireg_access(st, addr);
	ret = 0;

	for (i = 0; i < len; i++) {
		wait_for_ireg_access_completion(st);
		ret = inv_plat_read(st, REG_IREG_DATA_DREG_BANK1, 1, data + i);
	}

	return ret;
}

/**
 * inv_imu_soft_reset() - soft reset chip
 * @st: struct inv_mpu_state.
 *
 * Return: 0 when successful.
 */
int inv_imu_soft_reset(struct inv_mpu_state *st)
{
	u8 v;
	int res;

	/* Trigger soft reset */
	res = inv_plat_single_write(st, REG_REG_MISC2_DREG_BANK1, BIT_SOFT_RST);
	if (res)
		return res;
	msleep(1);

	/* Clear the RESET_DONE interrupt */
	v = 0;
	while (!(v & REG_INT1_STATUS0_INT1_STATUS_RESET_DONE_MASK)) {
		res = inv_plat_read(st, REG_INT1_STATUS0_DREG_BANK1, 1, &v);
	}

	return res;
}

/**
 * inv_get_apex_enabled() - Check if any APEX feature is enabled
 * @st: struct inv_mpu_state.
 *
 * Return: true when any is enabled, otherwise false.
 */
bool inv_get_apex_enabled(struct inv_mpu_state *st)
{
	if (st->step_detector_l_on ||
		st->step_detector_wake_l_on ||
		st->step_counter_l_on ||
		st->step_counter_wake_l_on ||
		st->chip_config.tilt_enable ||
		st->smd.on ||
		st->chip_config.tap_enable ||
		st->chip_config.pick_up_enable)
		return true;

	return false;
}

/**
 * inv_get_apex_odr() - Get min accel ODR according to enabled APEX feature
 * @st: struct inv_mpu_state.
 *
 * Return: min accel ODR in Hz
 */
int inv_get_apex_odr(struct inv_mpu_state *st)
{
#if 1 // TODO
	int odr_hz = 0;

#ifdef SUPPORT_ACCEL_LPM
	odr_hz = MPU_INIT_SENSOR_RATE_LPM;
#else
	odr_hz = MPU_INIT_SENSOR_RATE_LNM;
#endif
	/* returns min accel rate for each algorithm */
	if (st->step_detector_l_on ||
		st->step_detector_wake_l_on ||
		st->step_counter_l_on ||
		st->step_counter_wake_l_on ||
		st->chip_config.tilt_enable ||
		st->smd.on)
		odr_hz = 50;

	return odr_hz;
#else
	(void)st;
	return 0;
#endif
}

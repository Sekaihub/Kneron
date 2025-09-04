/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Audio_SSM2603
 * Driver for Audio Codec SSM2603.
 */

#ifndef _SSM2603_H_
#define _SSM2603_H_

#include <linux/i2c.h>
#include <linux/regmap.h>

/* ========================================================================== */

/* SSM2603 register definition */
#define LEFT_ADC_VOLUME_REG   0x00
#define RIGHT_ADC_VOLUME_REG  0x01
#define LEFT_DAC_VOLUME_REG   0x02
#define RIGHT_DAC_VOLUME_REG  0x03
#define ANA_AUDIO_PATH_REG    0x04
#define DIG_AUDIO_PATH_REG    0x05
#define POWER_MANAGE_REG      0x06
#define DIGI_AUDIO_IF_REG     0x07
#define SAMPLE_RATE_REG       0x08
#define ACTIVE_REG            0x09
#define SW_RESET_REG          0x0F
#define ALC_CTRL1_REG         0x10
#define ALC_CTRL2_REG         0x11
#define NOISE_GATE_REG        0x12

#define NUMBER_SSM2603_REG  NOISE_GATE_REG

/* ========================================================================== */

struct ssm2603_priv {
	unsigned int sysclk;
	int reg_cache[NUMBER_SSM2603_REG];
	struct regmap *regmap;
	struct i2c_client *i2c_client;
};

/* ========================================================================== */

extern struct i2c_driver ssm2603_i2c_driver;

#endif // #ifndef _SSM2603_H_



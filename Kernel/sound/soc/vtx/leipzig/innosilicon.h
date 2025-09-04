/* SPDX-License-Identifier: GPL-2.0 */
/*
 * INNOSILICON
 * Driver for Audio Codec INNOSILICON.
 */

#ifndef __INNO_SILICON_H__
#define __INNO_SILICON_H__

/* ========================================================================== */

#define INNO_MMR_BASE  0xCE000000
#define INNO_MMR_SIZE  100

/*
 * Register definition
 */
#define REG_SW_RESET  0x00 // software reset
/* I2S */
#define REG_ADC_I2S      0x02
#define REG_ADC_DAC_I2S  0x03
#define REG_DAC_I2S      0x04
#define REG_DAC_I2S_1    0x05
/* ADC - Microphone; DAC - Headphone */
#define REG_DAC_VOL_DIG  0x06 // digital volume Control
#define REG_BIST_MODE    0x07
#define REG_ADC_VOL_L    0x08
#define REG_ADC_VOL_R    0x09
#define REG_PGA_ADC      0x0A
#define REG_MIC_PDM      0x0F

/* Voltage & Current control for ADC and DAC modules */
#define REG_VOLTAGE   0x20
#define REG_CURRENT   0x21
#define REG_BIAS_CUR  0x22 // bias current

/* ADC - Microphone */
	/* Left Channel */
#define REG_ADC_CTRL_L  0x23
#define REG_ADC_GAIN_L  0x24
#define REG_ADC_ZERO_L  0x25 // input zero-crossing detection module
	/* Right Channel */
#define REG_ADC_CTRL_R  0x26
#define REG_ADC_GAIN_R  0x27
#define REG_ADC_ZERO_R  0x28 // input zero-crossing detection module

/* DAC - Headphone */
	/* Left Channel */
#define REG_DAC_CTRL_L  0x29
#define REG_DAC_INIT_L  0x2A
#define REG_DAC_GAIN_L  0x2B
	/* Right Channel */
#define REG_DAC_CTRL_R  0x2C
#define REG_DAC_INIT_R  0x2D
#define REG_DAC_GAIN_R  0x2E

/* AGC (ALC module) */
	/* Left Channel */
#define REG_AGC_CTRL_L  0x40
/* Decay (gain ramp-up) time; Attack (gain ramp-down) time */
#define REG_AGC_GAIN_L  0x41
#define REG_AGC_MODE_L  0x42
#define REG_AGC_PGA_L   0x43
/* Slow clock enabled; Approximate sample rate */
#define REG_AGC_RATE_L  0x44
/* The low 8 bits of the AGC maximum level */
#define REG_AGC_MAXL_L  0x45
/* The high 8 bits of the AGC maximum level */
#define REG_AGC_MAXH_L  0x46
/* The low 8 bits of the AGC minimum level */
#define REG_AGC_MINL_L  0x47
/* The high 8 bits of the AGC minimum level */
#define REG_AGC_MINH_L  0x48
/* Set maximum, minimum gain of PGA */
#define REG_AGC_PGA_GAIN_L    0x49
/* Peak detect value decrease rate */
#define REG_AGC_PEAK_L        0x4B
/* Timeout Counter for slow clock when zero cross not occur */
#define REG_AGC_TO_CNT_L      0x4C
/* Time Delay for noise judge when ALC gain changed */
#define REG_AGC_TIME_DELAY_L  0x4D
/* AGC gain probe signal (R.O.) */
#define REG_AGC_PROBE_L       0x4E
	/* Right Channel */
#define REG_AGC_CTRL_R  0x50
/* Decay (gain ramp-up) time; Attack (gain ramp-down) time */
#define REG_AGC_GAIN_R  0x51
#define REG_AGC_MODE_R  0x52
#define REG_AGC_PGA_R   0x53
/* Slow clock enabled; Approximate sample rate */
#define REG_AGC_RATE_R  0x54
/* The low 8 bits of the AGC maximum level */
#define REG_AGC_MAXL_R  0x55
/* The high 8 bits of the AGC maximum level */
#define REG_AGC_MAXH_R  0x56
/* The low 8 bits of the AGC minimum level */
#define REG_AGC_MINL_R  0x57
/* The high 8 bits of the AGC minimum level */
#define REG_AGC_MINH_R  0x58
/* Set maximum, minimum gain of PGA */
#define REG_AGC_PGA_GAIN_R    0x59
/* Peak detect value decrease rate */
#define REG_AGC_PEAK_R        0x5B
/* Timeout Counter for slow clock when zero cross not occur */
#define REG_AGC_TO_CNT_R      0x5C
/* Time Delay for noise judge when ALC gain changed */
#define REG_AGC_TIME_DELAY_R  0x5D
/* AGC gain probe signal (R.O.) */
#define REG_AGC_PROBE_R       0x5E


#define REG_SAMPLE_RATE_L  0x44 // [2:0] 96k ~ 8k Hz
#define REG_SAMPLE_RATE_R  0x54 // [2:0] 96k ~ 8k Hz

/* ========================================================================== */

#endif // #define __INNO_SILICON_H__


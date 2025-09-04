// SPDX-License-Identifier: GPL-2.0-only
/*
 * INNOSILICON
 * Driver for Audio Codec INNOSILICON.
 */

/* ========================================================================== */
/* Compile Option */

//#define OPT_DEBUG_LOCAL // local switch for debug
//#define OPT_DUMP_MMR
#define OPT_USE_ALC  0 // Auto Level Control requires complex adjustments!

/* ========================================================================== */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/slab.h>
#include <linux/regmap.h>
#include <linux/regulator/consumer.h>
#include <linux/spi/spi.h>
#include <linux/of_device.h>
#include <linux/clk.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

#include "vtx-asoc.h"
#include "innosilicon.h"

/* ========================================================================== */

/* Clock name definition */
#define CLK_ADCD_TX_MCLK    "adcdcc_tx_clk"
#define CLK_ADCD_RX_MCLK    "adcdcc_rx_clk"
#define CLK_RATIO_MCLK_FS   256


/* Platform Device Private Data */
struct inno_priv {
	struct device *dev;
	void __iomem *mmr_base;
	struct regmap *regmap;
	/* PDM */
	bool is_pdm_on;
	unsigned int pdm_gain;
	/* I2S Bus Master Clock */
	struct clk *clk_tx_mclk;
	struct clk *clk_rx_mclk;
	/* MONO mode - 0: stereo, 1: left channel, 2: right channel */
	unsigned int mono_mode_adc; // MIC IN
};

/* ---------------------------------------------------------------------------*/

enum {
	I2S_MODE_SLAVE  = 0x00, // Slave mode
	I2S_MODE_MASTER = 0x01, // Master
};

enum {
	I2S_WORD_LEN_16B = 0x00, // 16 bits
	I2S_WORD_LEN_20B = 0x01, // 20 bits -> DMA engine not support!
	I2S_WORD_LEN_24B = 0x02, // 24 bits -> DMA engine not support!
	I2S_WORD_LEN_32B = 0x03, // 32 bits
};

enum {
	I2S_FORMAT_RJ  = 0x00, // Right Justified
	I2S_FORMAT_LJ  = 0x01, // Left Justified
	I2S_FORMAT_I2S = 0x02, // I2S
	I2S_FORMAT_PCM = 0x03, // PCM
};

enum {
	I2S_MOD_RESET = 0x00, // module reset
	I2S_MOD_WORK  = 0x01, // module work
};

/* fixme... use DT later */
#if (CFG_I2S_MASTER_MODE == 0)
#define PAR_I2S_MODE  I2S_MODE_MASTER
#else /* H/W default is Slave mode */
#define PAR_I2S_MODE  I2S_MODE_SLAVE
#endif

#define PAR_I2S_FRAME_LEN  I2S_WORD_LEN_32B
#define PAR_I2S_VALID_LEN  I2S_WORD_LEN_16B
#define PAR_I2S_FORMAT     I2S_FORMAT_I2S
#define PAR_I2S_LRC_POL    0x00 // LRC polarity. 0: Normal, 1: Reversal
#define PAR_I2S_LR_SWAP    0x00 // Left-Right. 0: Normal, 1: Swap
#define PAR_I2S_BCLK_POL   0x00 // Bit Clock polarity. 0: Normal, 1: Reversal

#define PAR_I2S_MIC_TYPE   0x00 // 0: Stereo, 1: Mono

/* MIC input type - bit[1:0] @ REG_ADC_I2S */
#define PAR_I2S_MIC_STEREO      0x00
#define PAR_I2S_MIC_MONO_LEFT   0x01
#define PAR_I2S_MIC_MONO_RIGHT  0x02

/*
 * REG_CURRENT to select current to pre-charge/dis-charge
 * [7] 128*Io, [6] 64*Io, [5] 32*Io, ... , [0] Io
 * =1 choose; =0 don't choose
 */
#define PAR_CURRENT  0x80

/*
 * MIC L/R module - [6:5] 2-bits gain setting
 */
enum {
	ADC_GAIN_0DB  = 0x00,
	ADC_GAIN_6DB  = 0x01,
	ADC_GAIN_20DB = 0x02,
	ADC_GAIN_30DB = 0x03,
};

#define PAR_MIC_GAIN ADC_GAIN_6DB

/*
 * Digital gain of microphone input: (step is 6 dB)
 * 3b'000:  0 dB (min)
 * 3b'001:  6 dB
 * 3b'111: 42 dB (max)
 */
#define PAR_MIC_GAIN_DIG  3 // 18 dB

/*
 * ADC L/R module - [4:0] 5-bits gain setting: (step is 1.5 dB)
 * 00000: -18 dB (min)
 * 01100: 0 dB
 * 11111: 28.5 dB (max)
 */
#define PAR_ADC_GAIN  0x10 // 6 dB
/*
 * DAC L/R module - [4:0] 5-bits gain setting: (step is 1.5 dB)
 * 00000: -39 dB (min)
 * 11010: 0 dB
 * 11111: 6 dB (max) -> b'101 = d'5 => 1.5*5 = 7.5 dB
 */
#define PAR_DAC_GAIN  0x1a // 0 dB
/*
 * DAC L/R module - [3:0] 4-bits The signal to adjust HPOUT driver strength
 * 0001: 100% (max)
 * 0010: 60.1%
 * 1000: 20.4% (min)
 */
#define PAR_DAC_DRIVER  0x01

/*
 * ALC L/R module - max & min level
 * signal amplitude (dB) max = 20log(max_level / 16'h7fff)
 * signal amplitude (dB) min = 20log(min_level / 16'h7fff)
 * 16'h7fff means the full scale amplitude
 */
#define PAR_ALC_MAX_LEVEL  0x4026 // H/W default 0x4026
#define PAR_ALC_MIN_LEVEL  0x4026 // H/W default 0x4026

/*
 * ALC L/R module - approximate sampe rate
 */
enum {
	ALC_RATE_96KHz  = 0x00,
	ALC_RATE_48KHz  = 0x01,
	ALC_RATE_44KHz  = 0x02,
	ALC_RATE_32KHz  = 0x03,
	ALC_RATE_24KHz  = 0x04,
	ALC_RATE_16KHz  = 0x05,
	ALC_RATE_12KHz  = 0x06,
	ALC_RATE_08KHz  = 0x07,
};

#define PAR_ALC_SAMPLE_RATE  ALC_RATE_48KHz

/* ========================================================================== */

static const struct regmap_config inno_regmap_config = {
	.reg_bits = 32,
	.reg_stride = 4,
	.val_bits = 32,
	.max_register = (0x5F * 4),
};

static const int table_mono_mode_adc[3] = {
	PAR_I2S_MIC_STEREO,
	PAR_I2S_MIC_MONO_LEFT,
	PAR_I2S_MIC_MONO_RIGHT,
};

/* -------------------------------------------------------------------------- */

/*
 * TLV: Type-Length-Value data exchange format
 * DB SCALE unit: 0.01 dB
 */
// SNDRV_CTL_TLVD_DECLARE_DB_SCALE(name, min, step, mute)
/* -39 dB min, 1.5 dB step */
static const DECLARE_TLV_DB_SCALE(tlv_dac_gain, -3900, 150, 0);
/* -97 dB min, 0.5 dB step for Digital Volume */
static const DECLARE_TLV_DB_SCALE(tlv_dig_vol, -9700, 50, 0);
/* 0 dB min, 6 dB step for Microphone Digital Volume */
static const DECLARE_TLV_DB_SCALE(tlv_mic_dig, 0, 600, 0);
/* -18 dB min, 1.5 dB step for ALC Module Gain */
static const DECLARE_TLV_DB_SCALE(tlv_alc_gain, -1800, 150, 0);
/* -18 dB min, 1.5 dB step for Input PGA Gain */
static const DECLARE_TLV_DB_SCALE(tlv_pga_gain, -1800, 150, 0);
/* -13.5 dB min, 6 dB step for PGA Maximum Gain */
static const DECLARE_TLV_DB_SCALE(tlv_pga_gain_max, -1350, 600, 0);
/* -18 dB min, 6 dB step for PGA Minimum Gain */
static const DECLARE_TLV_DB_SCALE(tlv_pga_gain_min, -1800, 600, 0);

static const char
	*hpf_sel_text[] = { "Enable", "Disable", },
	*mic_ana_text[] = { "0dB", "6dB", "20dB", "30dB", },
	*pga_gain_sel_text[] = { "ADC gain", "ALC module", },
	*hp_drive_text[] = { "100%", "60.1%", "44.2%", "35.5%",
		"29.7%", "25.7%", "22.7%", "20.4%" },
	*noise_gate_thr_text[] = { "-39dB", "-45dB", "-51dB", "-57dB", };

static const struct soc_enum innosilicon_enum[] = {
	/* DAC */
	SOC_ENUM_SINGLE(REG_DAC_INIT_L, 0, // xreg, xshift
		ARRAY_SIZE(hp_drive_text), hp_drive_text), // xitems, xtexts
	SOC_ENUM_SINGLE(REG_DAC_INIT_R, 0, // xreg, xshift
		ARRAY_SIZE(hp_drive_text), hp_drive_text), // xitems, xtexts
	/* ADC */
	SOC_ENUM_SINGLE(REG_PGA_ADC, 2, // xreg, xshift
		ARRAY_SIZE(hpf_sel_text), hpf_sel_text), // xitems, xtexts
	SOC_ENUM_DOUBLE(REG_PGA_ADC, 5, 4, // xreg, xshift_l, xshift_r,
		ARRAY_SIZE(pga_gain_sel_text), pga_gain_sel_text), // xitems, xtexts
};

/*
 * Microphone Analog Volume
 * - DECLaring a struct and calculating ARRAY_SIZE internally
 * - set parameter with TEXT listed above
 */
static SOC_ENUM_SINGLE_DECL(mic_ana_enum_l, REG_ADC_GAIN_L,
	5, mic_ana_text); // xshift, xtexts
static SOC_ENUM_SINGLE_DECL(mic_ana_enum_r, REG_ADC_GAIN_R,
	5, mic_ana_text); // xshift, xtexts

/* AGC noise gate function threshold */
static SOC_ENUM_SINGLE_DECL(noise_gate_thr_enum_l, REG_AGC_MODE_L,
	0, noise_gate_thr_text); // xshift, xtexts
static SOC_ENUM_SINGLE_DECL(noise_gate_thr_enum_r, REG_AGC_MODE_R,
	0, noise_gate_thr_text); // xshift, xtexts

/*
 * Callback function for Control Object with EXT data type
 */
static int agc_level_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *comp = snd_kcontrol_chip(kcontrol);
	struct soc_mixer_control *mc =
		(struct soc_mixer_control *)kcontrol->private_value;
	unsigned int reg_left = mc->reg;
	unsigned int reg_right = mc->rreg;
	unsigned int val_lo, val_hi, val;
	int ret;

	DBG("register L 0x%x, R 0x%x\n", reg_left, reg_right);
	/* Left Channel */
	val = ucontrol->value.integer.value[0];
	val_lo = val & 0xff;
	val_hi = (val & 0xff00) >> 8;
	DBG("L value: 0x%x -> low %x, high %x\n", val, val_lo, val_hi);
	ret = snd_soc_component_write(comp, reg_left, val_lo);
	ret |= snd_soc_component_write(comp, reg_left + 1, val_hi);
	if (ret != 0) {
		ERR("write register ch.L 0x%x failed!(%d)\n", reg_left, ret);
		return ret;
	}
	/* Right Channel */
	val = ucontrol->value.integer.value[1];
	val_lo = val & 0xff;
	val_hi = (val & 0xff00) >> 8;
	DBG("R value: 0x%x -> low %x, high %x\n", val, val_lo, val_hi);
	ret = snd_soc_component_write(comp, reg_right, val_lo);
	ret |= snd_soc_component_write(comp, reg_right + 1, val_hi);
	if (ret != 0) {
		ERR("write register ch.R 0x%x failed!(%d)\n", reg_right, ret);
		return ret;
	}

	return 1; // 1 means changed
}

static int agc_level_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *comp = snd_kcontrol_chip(kcontrol);
	struct soc_mixer_control *mc =
		(struct soc_mixer_control *)kcontrol->private_value;
	unsigned int reg_left = mc->reg;
	unsigned int reg_right = mc->rreg;
	unsigned int val_lo, val_hi, val, val_ch_r;

	DBG("register L 0x%x, R 0x%x\n", reg_left, reg_right);
	/* Left Channel */
	val_lo = snd_soc_component_read(comp, reg_left);
	val_hi = snd_soc_component_read(comp, reg_left + 1);
	val = (val_hi << 8) | val_lo;
	DBG("L low %x, high %x -> real value: 0x%x\n", val_lo, val_hi, val);
	/* Right Channel */
	val_lo = snd_soc_component_read(comp, reg_right);
	val_hi = snd_soc_component_read(comp, reg_right + 1);
	val_ch_r = (val_hi << 8) | val_lo;
	DBG("R low %x, high %x -> real value: 0x%x\n", val_lo, val_hi, val_ch_r);
	/* integer: long value[128] */
	ucontrol->value.integer.value[0] = val;
	ucontrol->value.integer.value[1] = val_ch_r;
	return 0;
}

/*
 * SINGLE: one control item
 * DOUBLE: for Left and Right channels
 * R: Register; S: Sign
 */
static const struct snd_kcontrol_new innosilicon_snd_controls[] = {
	/*
	 * DAC relative controls for Playback
	 */
	/* DAC Digital Volume control. (=0: Digital Mute) */
	SOC_SINGLE_RANGE_TLV("Playback Volume - Digital", REG_DAC_VOL_DIG,
		0, 0x01, 0xff, 0, // xshift, xmin, xmax, xinvert
		tlv_dig_vol), // tlv_array
	/* DAC gain control. */
	SOC_DOUBLE_R_TLV("Headphone Output Gain", REG_DAC_GAIN_L, REG_DAC_GAIN_R,
		0, 0x1f, 0, // xshift, xmax, xinvert
		tlv_dac_gain), // tlv_array
	/* DAC drive strength control. */
	SOC_ENUM("Headphone Output Driver Strength L", innosilicon_enum[0]),
	SOC_ENUM("Headphone Output Driver Strength R", innosilicon_enum[1]),
	/*
	 * ADC relative controls for Capture
	 */
	/* ADC HPF disable control. */
	SOC_ENUM("Capture HPF Disable", innosilicon_enum[2]),
	/* PGA control source. (=1'b0: ADC GAIN , =1'b1: ALC Module) */
	SOC_ENUM("Capture PGA Control Source", innosilicon_enum[3]),
	/* ADC Digital Volume control. (=0: Digital Mute) */
	SOC_DOUBLE_R_RANGE_TLV("Capture Volume - Digital",
		REG_ADC_VOL_L, REG_ADC_VOL_R,
		0, 0x01, 0xff, 0, // xshift, xmin, xmax, xinvert
		tlv_dig_vol), // tlv_array
	/* Digital gain of microphone input. */
	SOC_SINGLE_TLV("Microphone Input Gain - Digital", REG_MIC_PDM,
		0, 0x07, 0, // shift, max, invert
		tlv_mic_dig), // tlv_array
	/* Analog gain of microphone input. */
	SOC_ENUM("Microphone Input Gain - Analog L", mic_ana_enum_l),
	SOC_ENUM("Microphone Input Gain - Analog R", mic_ana_enum_r),
	/* ALC(Auto Level Control) module gain control. */
	SOC_DOUBLE_R_TLV("ALC Module Gain", REG_ADC_GAIN_L, REG_ADC_GAIN_R,
		0, 0x1f, 0, // xshift, xmax, xinvert
		tlv_alc_gain), // tlv_array
	/*
	 * AGC relative controls for Capture
	 */
	/* AGC function select. */
	SOC_DOUBLE_R("AGC Function Switch", REG_AGC_PGA_GAIN_L, REG_AGC_PGA_GAIN_R,
		6, 1, 0), // xshift, xmax, xinvert
	/* Set maximum gain of PGA */
	SOC_DOUBLE_R_TLV("AGC PGA Maximum Gain",
		REG_AGC_PGA_GAIN_L, REG_AGC_PGA_GAIN_R, // reg_left, reg_right
		3, 0x07, 0, // xshift, xmax, xinvert
		tlv_pga_gain_max), // tlv_array
	/* Set minimum gain of PGA */
	SOC_DOUBLE_R_TLV("AGC PGA Minimum Gain",
		REG_AGC_PGA_GAIN_L, REG_AGC_PGA_GAIN_R, // reg_left, reg_right
		0, 0x07, 0, // xshift, xmax, xinvert
		tlv_pga_gain_min), // tlv_array
	/* AGC mode of opeartion. (=0: AGC mode(normal), =1: Limiter mode) */
	SOC_DOUBLE_R("AGC Mode Switch", REG_AGC_MODE_L, REG_AGC_MODE_R,
		6, 1, 1), // xshift, xmax, xinvert
	/* AGC users zero cross enable. */
	/*	 (=1: Enabled, the AGC gain will update at zero cross enable) */
	SOC_DOUBLE_R("AGC Users Zero Cross Switch", REG_AGC_MODE_L, REG_AGC_MODE_R,
		6, 1, 0), // xshift, xmax, xinvert
	/* AGC noise gate function enable. */
	SOC_SINGLE("AGC Noise Gate Switch L", REG_AGC_MODE_L,
		3, 1, 0), // xshift, xmax, xinvert
	SOC_SINGLE("AGC Noise Gate Switch R", REG_AGC_MODE_R,
		3, 1, 0), // xshift, xmax, xinvert
	/* AGC noise gate threshold. */
	SOC_ENUM("AGC Noise Gate Threshold L", noise_gate_thr_enum_l),
	SOC_ENUM("AGC Noise Gate Threshold R", noise_gate_thr_enum_r),
	/* Input PGA zero cross enable */
	/*	 (=0: Update gain when gain register changes.) */
	/*	 (=1: Update gain on 1st zero cross after gain register write.) */
	SOC_DOUBLE_R("AGC PGA Zero Cross Switch", REG_AGC_PGA_L, REG_AGC_PGA_R,
		5, 1, 0), // xshift, xmax, xinvert
	/* Input PGA gain */
	SOC_DOUBLE_R_TLV("AGC PGA Gain", REG_AGC_PGA_L, REG_AGC_PGA_R,
		0, 0x1f, 0, // xshift, xmax, xinvert
		tlv_pga_gain), // tlv_array
	/* AGC maximum level. (include two 8-bits registers) */
	SOC_DOUBLE_R_EXT("AGC Maximum Level", REG_AGC_MAXL_L, REG_AGC_MAXL_R,
		0, 0xffff, 0, // xshift, xmax, xinvert,
		agc_level_get, agc_level_put), // xhandler_get, xhandler_put
	/* AGC minimum level. (include two 8-bits registers) */
	SOC_DOUBLE_R_EXT("AGC Minimum Level", REG_AGC_MINL_L, REG_AGC_MINL_R,
		0, 0xffff, 0, // xshift, xmax, xinvert,
		agc_level_get, agc_level_put), // xhandler_get, xhandler_put
};

/* ========================================================================== */

static inline void __codec_write(void __iomem *mmr_base,
	unsigned int reg, unsigned int val)
{
	writel(val, (mmr_base + (reg << 2)));
}

static inline unsigned int __codec_read(void __iomem *mmr_base,
	unsigned int reg)
{
	return readl(mmr_base + (reg << 2));
}

/* callback function for snd_soc_component_write() */
static int codec_register_write(struct snd_soc_component *component,
	unsigned int reg, unsigned int val)
{
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);
	void __iomem *mmr_base = priv_data->mmr_base;

	DBG("Reg. %x, value %x\n", reg, val);
	writel(val, (mmr_base + (reg << 2)));
	return 0;
}

/* callback function for snd_soc_component_read() */
static unsigned int codec_register_read(struct snd_soc_component *component,
	unsigned int reg)
{
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);
	void __iomem *mmr_base = priv_data->mmr_base;

	DBG("Reg. %x\n", reg);
	return readl(mmr_base + (reg << 2));
}

/* ---------------------------------------------------------------------------*/

#ifdef tag_User_Guide
#endif

/*
 * ADC module - Microphone input
 */
static int _adc_enable(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* step.0:
	 * Power up the CODEC according to the section 10.1.
	 */

	/* step.1:
	 * Configure the register EN_IBIAS_ADC_1p2V 0x20[5] to 1,
	 * to enable the current source of ADC.
	 */
	value = __codec_read(mmr_base, REG_VOLTAGE);
	__codec_write(mmr_base, REG_VOLTAGE, value | 0x20);

	/* step.2:
	 * Configure the register EN_BUF_ADCL_1p2V 0x23[7] to 1,
	 * to enable the reference voltage buffer in ADC left channel.
	 * Configure the register EN_BUF_ADCR_1p2V 0x26[7] to 1,
	 * to enable the reference voltage buffer in ADC right channel.
	 */
	/* step.3:
	 * Configure the register EN_MICL_1p2V 0x23[6] to 1,
	 * to enable the MIC module in ADC left channel.
	 * Configure the register EN_MICR_1p2V 0x26[6] to 1,
	 * to enable the MIC module in ADC right channel.
	 */
	/* step.4:
	 * Configure the register EN_ALCL_1p2V 0x23[5] to 1,
	 * to enable the ALC module in ADC left channel.
	 * Configure the register EN_ALCR_1p2V 0x26[5] to 1,
	 * to enable the ALC module in ADC right channel.
	 */
	/* step.5:
	 * Configure the register EN_CLK_ADCL_1p2V 0x23[4] to 1,
	 * to enable the clock module in ADC left channel.
	 * Configure the register EN_CLK_ADCR_1p2V 0x26[4] to 1,
	 * to enable the clock module in ADC right channel.
	 */
	/* step.6:
	 * Configure the register EN_ADCL_1p2V 0x23[3] to 1,
	 * to enable the ADC module in ADC left channel.
	 * Configure the register EN_ADCR_1p2V 0x26[3] to 1,
	 * to enable the ADC module in ADC right channel.
	 */
	/* step.7:
	 * Configure the register INITIAL_ADCL_1p2V 0x23[2] to 1,
	 * to end the initialization of the ADCL module.
	 * Configure the register INITIAL_ADCR_1p2V 0x26[2] to 1,
	 * to end the initialization of the ADCR module.
	 */
	/* step.8:
	 * Configure the register INITIAL_ALCL_1p2V 0x23[1] to 1,
	 * to end the initialization of the left ALC module.
	 * Configure the register INITIAL_ALCR_1p2V 0x26[1] to 1,
	 * to end the initialization of the right ALC module.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value | 0xFE);
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value | 0xFE);

	/* step.9:
	 * Configure the register INITIAL_MICL_1p2V 0x23[0] to 1,
	 * to end the initialization of the left MIC module.
	 * Configure the register INITIAL_MICR_1p2V 0x26[0] to 1,
	 * to end the initialization of the right MIC module.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value | 0x01);
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value | 0x01);

	/* step.10:
	 * Configure the register MUTE_MICL_1p2V 0x24[7] to 1,
	 * to end the mute station of the ADC left channel.
	 * Configure the register MUTE_MICR_1p2V 0x27[7] to 1,
	 * to end the mute station of the ADC right channel.
	 */
	/* step.11:
	 * Configure the register GAIN_MICL_1p2V<1:0> 0x24[6:5],
	 * to select the gain of the left MIC module.
	 * Configure the register GAIN_MICR_1p2V<1:0> 0x27[6:5],
	 * to select the gain of the right MIC module.
	 */
	/* step.12:
	 * Configure the register GAIN_ALCL_1p2V<4:0> 0x24[4:0],
	 * to select the gain of the left ALC module.
	 * Configure the register GAIN_ALCR_1p2V<4:0> 0x27[4:0],
	 * to select the gain of the right ALC module.
	 */
	value = (PAR_MIC_GAIN << 5) | PAR_ADC_GAIN;
	__codec_write(mmr_base, REG_ADC_GAIN_L, value);
	__codec_write(mmr_base, REG_ADC_GAIN_R, value);

	/* step.13:
	 * Configure the register EN_ZeroDET_ADCL_1p2V 0x25[1] to 1,
	 * to enable the zero-crossing detection function in ADC left channel.
	 * Configure the register EN_ZeroDET_ADCR_1p2V 0x28[1] to 1,
	 * to enable the zero-crossing detection function in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_ZERO_L);
	__codec_write(mmr_base, REG_ADC_ZERO_L, value | 0x02);
	value = __codec_read(mmr_base, REG_ADC_ZERO_R);
	__codec_write(mmr_base, REG_ADC_ZERO_R, value | 0x02);

	/* step.14:
	 * Begin recording
	 */

	return 0;
}

static int _adc_disable(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* step.0:
	 * Keep ADC channel work and stop recording.
	 */

	/* step.1:
	 * Configure the register EN_ZeroDET_ADCL_1p2V 0x25[1] to 0,
	 * to disable the zero-crossing detection function in ADC left channel.
	 * Configure the register EN_ZeroDET_ADCR_1p2V 0x28[1] to 0,
	 * to disable the zero-crossing detection function in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_ZERO_L);
	__codec_write(mmr_base, REG_ADC_ZERO_L, value & ~(0x01 << 1));
	value = __codec_read(mmr_base, REG_ADC_ZERO_R);
	__codec_write(mmr_base, REG_ADC_ZERO_R, value & ~(0x01 << 1));

	/* step.2:
	 * Configure the register EN_ADCL_1p2V 0x23[3] to 0,
	 * to disable the ADC module in ADC left channel.
	 * Configure the register EN_ADCR_1p2V 0x26[3] to 0,
	 * to disable the ADC module in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 3));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 3));

	/* step.3:
	 * Configure the register EN_CLK_ADCL_1p2V 0x23[4] to 0,
	 * to disable the clock module in ADC left channel.
	 * Configure the register EN_CLK_ADCR_1p2V 0x26[4] to 0,
	 * to disable the clock module in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 4));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 4));

	/* step.4:
	 * Configure the register EN_ALCL_1p2V 0x23[5] to 0,
	 * to disable the ALC module in ADC left channel.
	 * Configure the register EN_ALCR_1p2V 0x26[5] to 0,
	 * to disable the ALC module in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 5));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 5));

	/* step.5:
	 * Configure the register EN_MICL_1p2V 0x23[6] to 0,
	 * to disable the MIC module in ADC left channel.
	 * Configure the register EN_MICR_1p2V 0x26[6] to 0,
	 * to disable the MIC module in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 6));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 6));

	/* step.6:
	 * Configure the register EN_BUF_ADCL_1p2V 0x23[7] to 0,
	 * to disable the reference voltage buffer in ADC left channel.
	 * Configure the register EN_BUF_ADCR_1p2V 0x26[7] to 0,
	 * to disable the reference voltage buffer in ADC right channel.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 7));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 7));

	/* step.7:
	 * Configure the register EN_IBIAS_ADC_1p2V 0x20[5] to 0,
	 * to disable the current source of ADC.
	 */
	value = __codec_read(mmr_base, REG_VOLTAGE);
	__codec_write(mmr_base, REG_VOLTAGE, value & ~(0x01 << 5));

	/* step.8:
	 * Configure the register INITIAL_ADCL_1p2V 0x23[2] to 0,
	 * to begin the initialization of the ADCL module.
	 * Configure the register INITIAL_ADCR_1p2V 0x26[2] to 0,
	 * to begin the initialization of the ADCR module.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 2));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 2));

	/* step.9:
	 * Configure the register INITIAL_ALCL_1p2V 0x23[1] to 0,
	 * to begin the initialization of the left ALC module.
	 * Configure the register INITIAL_ALCR_1p2V 0x26[1] to 0,
	 * to begin the initialization of the right ALC module.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 1));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 1));

	/* step.10:
	 * Configure the register INITIAL_MICL_1p2V 0x23[0] to 0,
	 * to begintheinitialization of the left MIC module.
	 * Configure the register INITIAL_MICR_1p2V 0x26[0] to 0,
	 * to begin the initialization of the right MIC module.
	 */
	value = __codec_read(mmr_base, REG_ADC_CTRL_L);
	__codec_write(mmr_base, REG_ADC_CTRL_L, value & ~(0x01 << 0));
	value = __codec_read(mmr_base, REG_ADC_CTRL_R);
	__codec_write(mmr_base, REG_ADC_CTRL_R, value & ~(0x01 << 0));

	return 0;
}

static int _adc_i2s_setup(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value, mono_mode;

	MSG("\n");
	if (info->is_pdm_on) {
		value = info->pdm_gain | 0x10; // use PDM interface as ADC input
		__codec_write(mmr_base, REG_MIC_PDM, value);
	}

	/* Step1:
	 * Provide stable clock to the pin_sys_clk and pin_mclk.
	 */

	/* Step2:
	 * Reset the IP by low the pin_rst_n.
	 */

	/* Step3:
	 * Reset the IP by soft reset register
	 */

	/* Step4:
	 * Configure the register related to the ADC I2S function to make the
	 * I2S TX work in different mode.
	 */
		/* REG_0x03 */
	/* [5] ADC I2S Mode Select for I/O pin. 1: Master, 0: Slave */
	/* [4] ADC I2S Mode Select for inner module. 1: Master, 0: Slave */
	/* [3:2] 1/2Frame World Length */
	/* [1]   Reset. 0: Reset, 1: Work */
	/* [0]   Bit Clock Polarity. 0: Normal, 1: Reversal */
	value = __codec_read(mmr_base, REG_ADC_DAC_I2S) & 0xc0; // [7:6] DAC
	value |= (PAR_I2S_MODE << 5) | (PAR_I2S_MODE << 4) |
			(PAR_I2S_FRAME_LEN << 2) |
			(I2S_MOD_WORK      << 1) |
			(PAR_I2S_BCLK_POL  << 0);
	__codec_write(mmr_base, REG_ADC_DAC_I2S, value);
		/* REG_0x02 */
	/* [7]   LRC Polarity. 0: Normal, 1: Reversal */
	/* [6:5] Valid Word Length in one 1/2 Frame */
	/* [4:3] Mode - PCM/I2S/LJ/RJ */
	/* [1]   Left-Right Swap. 0: Normal, 1: Swap */
	/* [0]   Type. 0: Stereo, 1: Mono */
	if (info->mono_mode_adc > 2) {
		WRN("Invalid ADC mono mode value (%d)! Set preset stereo mode.\n",
			info->mono_mode_adc);
		info->mono_mode_adc = 0;
	}
	mono_mode = table_mono_mode_adc[info->mono_mode_adc];

	value = (PAR_I2S_LRC_POL   << 7) |
			(PAR_I2S_VALID_LEN << 5) |
			(PAR_I2S_FORMAT    << 3) |
			mono_mode;
	__codec_write(mmr_base, REG_ADC_I2S, value);

	/* Step5:
	 * Begin to use the I2S interface of the ADC to output the parallel data.
	 */

	return 0;
}

/*
 * DAC module - Headphone output
 */
static int _dac_enable(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* step.0:
	 * Power up the CODEC according to the section 10.1 and
	 * input the mute signal.
	 */

	/* step.1:
	 * Configure the register EN_IBIAS_DAC_1p2V 0x20[4] to 1,
	 * to enable the current source of DAC.
	 */
	value = __codec_read(mmr_base, REG_VOLTAGE);
	__codec_write(mmr_base, REG_VOLTAGE, value | (0x01 << 4));

	/* step.2:
	 * Configure the register EN_BUF_DACL_1p2V 0x29[6] to 1,
	 * to enable the reference voltage buffer of the DAC left channel.
	 * Configure the register EN_BUF_DACR_1p2V 0x2c[6] to 1,
	 * to enablethe reference voltage buffer of the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 6));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 6));

	/* step.3:
	 * Configure the register POP_CTRL_DACL_1p2V<1:0> 0x29[5:4] to 2’b10,
	 * to enable POP sound in the DAC left channel.
	 * Configure the register POP_CTRL_DACR_1p2V<1:0> 0x2c[5:4] to 2’b10,
	 * to enable POP sound in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L) & ~(0x03 << 4);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x02 << 4));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R) & ~(0x03 << 4);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x02 << 4));

	/* step.4:
	 * Configure the register reg_en_hpoutl 0x2a[5] to 1,
	 * to enable the HPDRV module in the DAC left channel.
	 * Configure the register reg_en_hpoutr 0x2d[5] to 1,
	 * to enable the HPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_INIT_L);
	__codec_write(mmr_base, REG_DAC_INIT_L, value | (0x01 << 5));
	value = __codec_read(mmr_base, REG_DAC_INIT_R);
	__codec_write(mmr_base, REG_DAC_INIT_R, value | (0x01 << 5));

	/* step.5:
	 * Configure the register reg_ini_hpoutl 0x2a[4] to 1,
	 * to end the initialization of the HPDRV module in the DAC left channel.
	 * Configure the register reg_en_hpoutr 0x2d[4] to 1,
	 * to end theinitialization of the HPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_INIT_L);
	__codec_write(mmr_base, REG_DAC_INIT_L, value | (0x01 << 4));
	value = __codec_read(mmr_base, REG_DAC_INIT_R);
	__codec_write(mmr_base, REG_DAC_INIT_R, value | (0x01 << 4));

	/* HPOUT driver strength value */
	value = __codec_read(mmr_base, REG_DAC_INIT_L) & 0xf0;
	__codec_write(mmr_base, REG_DAC_INIT_L, value | PAR_DAC_DRIVER);
	value = __codec_read(mmr_base, REG_DAC_INIT_R) & 0xf0;
	__codec_write(mmr_base, REG_DAC_INIT_R, value | PAR_DAC_DRIVER);

	/* step.6:
	 * Configure the register EN_VREF_DACL_1p2V 0x29[3] to 1,
	 * to enable the reference voltage of DACL module.
	 * Configure the register EN_VREF_DACR_1p2V 0x2c[3] to 1,
	 * to enable the reference voltage of DACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 3));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 3));

	/* step.7:
	 * Configure the register EN_CLK_DACL_1p2V 0x29[2] to 1,
	 * to enable the clock module of DACL module.
	 * Configure the register EN_CLK_DACR_1p2V 0x2c[2] to 1,
	 * to enable the clock module of DACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 2));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 2));

	/* step.8:
	 * Configure the register EN_DACL_1p2V 0x29[1] to 1,
	 * to enable the DACL module.
	 * Configure the register EN_DACR_1p2V 0x2c[1] to 1,
	 * to enabletheDACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 1));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 1));

	/* step.9:
	 * Configure the register INITIAL_DACL_1p2V 0x29[0] to 1,
	 * to end the initialization of the DACL module.
	 * Configure the register INITIAL_DACR_1p2V 0x2c[0] to 1,
	 * to end the initialization of the DACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 0));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 0));

	/* step.10:
	 * Configure the register MUTE_HPOUTL_1p2V 0x29[7] to 1,
	 * to end the mute station of the HPDRV module in the DAC left channel.
	 * Configure the register MUTE_HPOUTR_1p2V 0x2c[7] to 1,
	 * to end the mute station of the HPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 7));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 7));

	/* step.11:
	 * Configure the register GAIN_HPOUTL_1p2V<4:0> 0x2b[4:0],
	 * to select the gain of HPDRV module in the DAC left channel.
	 * Configure the register GAIN_HPOUTR_1p2V<4:0> 0x2e[4:0],
	 * to select the gain of HPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_GAIN_L) & ~0x1f;
	__codec_write(mmr_base, REG_DAC_GAIN_L, value | PAR_DAC_GAIN);
	value = __codec_read(mmr_base, REG_DAC_GAIN_R) & ~0x1f;
	__codec_write(mmr_base, REG_DAC_GAIN_R, value | PAR_DAC_GAIN);

	/* step.12:
	 * Play the music.
	 */

	return 0;
}

static int _dac_disable(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* step.0:
	 * Keep the DAC channel work and input the mute signal.
	 */

	/* step.1:
	 * Configure the register GAIN_HPOUTL_1p2V<4:0> 0x2b[4:0] to 5’b0_0000,
	 * to select the gain of the HPDRV in the DAC left channel.
	 * Configure the register GAIN_HPOUTR_1p2V<4:0> 0x2e[4:0] to 5’b0_0000,
	 * to select the gain of the HPDRV in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_GAIN_L);
	__codec_write(mmr_base, REG_DAC_GAIN_L, value & ~0x1f);
	value = __codec_read(mmr_base, REG_DAC_GAIN_R);
	__codec_write(mmr_base, REG_DAC_GAIN_R, value & ~0x1f);

	/* step.2:
	 * Configure the register MUTE_HPOUTL_1p2V 0x29[7] to 0,
	 * to mute the HPDRV module in the DAC left channel.
	 * Configure the register MUTE_HPOUTR_1p2V 0x2c[7] to 0,
	 * to mute the HPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value & ~(0x01 << 7));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value & ~(0x01 << 7));

	/* step.3:
	 * Configure the register reg_ini_hpoutl 0x2a[4] to 0, to begin the
	 * initialization of the HPDRV module in the DAC left channel.
	 * Configure the register reg_ini_hpoutr 0x2d[4] to 0, to begin the
	 * initialization of the HPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_INIT_L);
	__codec_write(mmr_base, REG_DAC_INIT_L, value & ~(0x01 << 4));
	value = __codec_read(mmr_base, REG_DAC_INIT_R);
	__codec_write(mmr_base, REG_DAC_INIT_R, value & ~(0x01 << 4));

	/* step.4:
	 * Configure the register reg_en_hpoutl 0x2a[5] to 0,
	 * to disable the HPDRV module in the DAC left channel.
	 * Configure the register reg_en_hpoutr 0x2d[5] to 0,
	 * to disabletheHPDRV module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_INIT_L);
	__codec_write(mmr_base, REG_DAC_INIT_L, value & ~(0x01 << 5));
	value = __codec_read(mmr_base, REG_DAC_INIT_R);
	__codec_write(mmr_base, REG_DAC_INIT_R, value & ~(0x01 << 5));

	/* step.5:
	 * Configure the register EN_DACL_1p2V 0x29[1] to 0,
	 * to disable the DACL module.
	 * Configure the register EN_DACR_1p2V 0x2c[1] to 0,
	 * to disabletheDACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value & ~(0x01 << 1));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value & ~(0x01 << 1));

	/* step.6:
	 * Configure the register EN_CLK_DACL_1p2V 0x29[2] to 0,
	 * to disable the clock module of DACL module.
	 * Configure the register EN_CLK_DACR_1p2V 0x2c[2] to 0,
	 * to disable the clock module of DACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value & ~(0x01 << 2));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value & ~(0x01 << 2));

	/* step.7:
	 * Configure the register EN_VREF_DACL_1p2V 0x29[3] to 0,
	 * to disable the reference voltage of DACL module.
	 * Configure the register EN_VREF_DACR_1p2V 0x2c[3] to 0,
	 * to disable the reference voltage of DACR module.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value & ~(0x01 << 3));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value & ~(0x01 << 3));

	/* step.8:
	 * Configure the register POP_CTRL_DACL_1p2V<1:0>0x29[5:4] to 2’b01,
	 * to initialize the POP sound in the DAC left channel.
	 * Configure the register POP_CTRL_DACR_1p2V<1:0>0x2c[5:4] to 2’b01,
	 * to initialize the POP sound in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L) & ~(0x03 << 4);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value | (0x01 << 4));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R) & ~(0x03 << 4);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value | (0x01 << 4));

	/* step.9:
	 * Configure the register EN_BUF_DACL_1p2V 0x29[6] to 0,
	 * to disablethe reference voltage buffer of the DAC left channel.
	 * Configure the register EN_BUF_DACR_1p2V 0x2c[6] to 0,
	 * to disable the reference voltage buffer of the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value & ~(0x01 << 6));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value & ~(0x01 << 6));

	/* step.10:
	 * Configure the register EN_IBIAS_DAC_1p2V 0x20[4] to 0,
	 * to disable the current source of DAC.
	 */
	value = __codec_read(mmr_base, REG_VOLTAGE);
	__codec_write(mmr_base, REG_VOLTAGE, value & ~(0x01 << 4));

	/* step.11:
	 * Configure the register INITIAL_DACL_1p2V 0x29[0] to 0,
	 * to initialize the DAC module in the DAC left channel.
	 * Configure the register INITIAL_DACR_1p2V 0x2c[0] to 0,
	 * to initialize the DAC module in the DAC right channel.
	 */
	value = __codec_read(mmr_base, REG_DAC_CTRL_L);
	__codec_write(mmr_base, REG_DAC_CTRL_L, value & ~(0x01 << 0));
	value = __codec_read(mmr_base, REG_DAC_CTRL_R);
	__codec_write(mmr_base, REG_DAC_CTRL_R, value & ~(0x01 << 0));

	return 0;
}

static int _dac_i2s_setup(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* Step1:
	 * Provide stable clock to the pin_sys_clk and pin_mclk.
	 */

	/* Step2:
	 * Reset the IP by low the pin_rst_n.
	 */

	/* Step3:
	 * Reset the IP by soft reset register
	 */

	/* Step4:
	 * Configure the register related to the DAC I2S function to make the
	 * I2S RX work in different mode.
	 */
		/* REG_0x03 */
	/* [7] DAC I2S Mode Select for I/O pin. 1: Master, 0: Slave */
	/* [6] DAC I2S Mode Select for inner module. 1: Master, 0: Slave */
	value = __codec_read(mmr_base, REG_ADC_DAC_I2S) & 0x3f; // [5:0] ADC
	value |= (PAR_I2S_MODE << 7) | (PAR_I2S_MODE << 6);
	__codec_write(mmr_base, REG_ADC_DAC_I2S, value);
		/* REG_0x04 */
	/* [7]   LRC Polarity. 0: Normal, 1: Reversal */
	/* [6:5] Valid Word Length in one 1/2 Frame */
	/* [4:3] Mode - PCM/I2S/LJ/RJ */
	/* [2]   Left-Right Swap. 0: Normal, 1: Swap */
	value = (PAR_I2S_LRC_POL   << 7) |
			(PAR_I2S_VALID_LEN << 5) |
			(PAR_I2S_FORMAT    << 3) |
			(PAR_I2S_LR_SWAP   << 2);
	__codec_write(mmr_base, REG_DAC_I2S, value);
		/* REG_0x05 */
	/* [3:2] 1/2Frame World Length */
	/* [1]   Reset. 0: Reset, 1: Work */
	/* [0]   Bit Clock Polarity. 0: Normal, 1: Reversal */
	value = (PAR_I2S_FRAME_LEN << 2) |
			(I2S_MOD_WORK      << 1) |
			(PAR_I2S_BCLK_POL  << 0);
	__codec_write(mmr_base, REG_DAC_I2S_1, value);

	/* Step5:
	 * Begin to input the I2S data stream to the I2S interface of the DAC.
	 */

	return 0;
}

/*
 * ALC module - AGC
 */
static int _alc_enable(struct inno_priv *info)
{
#if OPT_USE_ALC
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* step.1:
	 * Set the Max level and Min level of the ALC need tocontrol.
	 */
	/* amplitude (dB) = 20log(max_level / 16'h7fff) */
	__codec_write(mmr_base, REG_AGC_MAXH_L, (PAR_ALC_MAX_LEVEL & 0xff00) >> 8);
	__codec_write(mmr_base, REG_AGC_MAXH_R, (PAR_ALC_MAX_LEVEL & 0xff00) >> 8);
	/* amplitude (dB) = 20log(min_level / 16'h7fff) */
	__codec_write(mmr_base, REG_AGC_MAXL_L, (PAR_ALC_MAX_LEVEL & 0xff));
	__codec_write(mmr_base, REG_AGC_MAXL_R, (PAR_ALC_MAX_LEVEL & 0xff));

	/* step.2:
	 * According to the sample rate to choose the configuration.
	 */
	__codec_write(mmr_base, REG_AGC_RATE_L, PAR_ALC_SAMPLE_RATE);
	__codec_write(mmr_base, REG_AGC_RATE_R, PAR_ALC_SAMPLE_RATE);

	/* step.3:
	 * Enable the ALC module.
	 * Set the register 0x49/0x59 [6] to 1 to enable the ALC L/R module.
	 */
	value = __codec_read(mmr_base, REG_AGC_PGA_GAIN_L);
	__codec_write(mmr_base, REG_AGC_PGA_GAIN_L, value | (0x01 << 6));
	value = __codec_read(mmr_base, REG_AGC_PGA_GAIN_R);
	__codec_write(mmr_base, REG_AGC_PGA_GAIN_R, value | (0x01 << 6));

	/* step.4:
	 * Choose the ALC module to control the gain of the PGA.
	 * Set the register 0x0a [5]/[4] to 1,
	 * to choose the ALC L/R module to control the gain of the PGA.
	 */
	value = __codec_read(mmr_base, REG_PGA_ADC);
	__codec_write(mmr_base, REG_PGA_ADC, value | (0x03 << 4));

	/* step.5:
	 * Observe the register 0x4e/0x5e [4:0] current ALC L/R output gain.
	 */
	value = __codec_read(mmr_base, REG_AGC_PROBE_L);
	MSG("ALC module output gain - L 0x%x\n", value);
	value = __codec_read(mmr_base, REG_AGC_PROBE_R);
	MSG("ALC module output gain - R 0x%x\n", value);
#endif
	return 0;
}

static int _alc_disable(struct inno_priv *info)
{
#if OPT_USE_ALC
	void __iomem *mmr_base = info->mmr_base;
	unsigned int value;

	MSG("\n");
	/* step.1:
	 * Disable the ALC module.
	 * Set the register 0x49/0x59 [6] to 0 to disable the ALC L/R module,
	 * then the ALC L/R output gain will keep to the last value.
	 */
	value = __codec_read(mmr_base, REG_AGC_PGA_GAIN_L);
	__codec_write(mmr_base, REG_AGC_PGA_GAIN_L, value & ~(0x01 << 6));
	value = __codec_read(mmr_base, REG_AGC_PGA_GAIN_R);
	__codec_write(mmr_base, REG_AGC_PGA_GAIN_R, value & ~(0x01 << 6));

	/* step.2:
	 * Choose to use the register to control the gain of the PGA.
	 * Set the register 0x0a [5]/[4] to 0,
	 * to choose to use the register to control the gain of the PGA,
	 * then we can use the register 0x27/0x28 [4:0].
	 */
	value = __codec_read(mmr_base, REG_PGA_ADC);
	__codec_write(mmr_base, REG_PGA_ADC, value & ~(0x03 << 4));
#endif
	return 0;
}

static int _power_up(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;

	MSG("\n");
	/* step.0:
	 * Supply the power of the digital part and reset the audio codec.
	 */

	/* step.1:
	 * Configure the register 0x29[5:4] to 2’b01,
	 * to setup the output dc voltage of DAC left channel.
	 * Configure the register 0x2c[5:4] to 2’b01,
	 * to setup the output dc voltage of DAC right channel.
	 */
	__codec_write(mmr_base, REG_DAC_CTRL_L, (0x01 << 4));
	__codec_write(mmr_base, REG_DAC_CTRL_R, (0x01 << 4));

	/* step.2:
	 * Configure the register reg0x21[7:0] to 8’b000_0001.
	 */
	__codec_write(mmr_base, REG_CURRENT, 0x01);

	/* step.3:
	 * Supply the power of the analog part.
	 */

	/* step.4:
	 * Configure the register reg0x20[6] to 1 to setup reference voltage.
	 * Configure the register reg0x20[3] to 1 to setup MIC bias voltage.
	 */
	__codec_write(mmr_base, REG_VOLTAGE, (0x01 << 6) | (0x01 << 3));

	/* step.5:
	 * Change the register reg0x21[7:0] from the 8’b0000_0001 t o8’b1111_1111
	 * step by step or configure the reg0x21[7:0] to 7’b1111_1111 directly.
	 * The suggestion slot time of the step is 20ms.
	 */
	__codec_write(mmr_base, REG_CURRENT, 0xff);
	msleep(20);

	/* step.6:
	 * Wait until the voltage of VCM keeps stable at the AVDD/2.
	 */

	/* step.7:
	 * Configure the register reg0x21[7:0] to the appropriate value
	 * (except 7’b0000_00000) for reducing power.
	 */
	__codec_write(mmr_base, REG_CURRENT, PAR_CURRENT);

	return 0;
}

static int _power_down(struct inno_priv *info)
{
	void __iomem *mmr_base = info->mmr_base;

	MSG("\n");
	/* step.0:
	 * Keep the power on and disable the DAC and ADC path
	 * according to the description of section 10.6 and 10.4
	 */
	_dac_disable(info);
	_adc_disable(info);

	/* step.1:
	 * Configure the register reg0x21[7:0] to 8’b0000_0001.
	 */
	__codec_write(mmr_base, REG_CURRENT, 0x01);

	/* step.2:
	 * Configure the register reg0x20[6] to 1’b0 to disable reference voltage
	 */
	__codec_write(mmr_base, REG_VOLTAGE, 0x00);

	/* step.3:
	 * Change the register reg0x21[7:0] from the 8’b0000_0001 to
	 * 8’b111_1111 step by step or configure the reg0x21[7:0] to
	 * 8’b111_1111 directly. The suggestion slot time of the step is 20ms.
	 */
	__codec_write(mmr_base, REG_CURRENT, 0xff);
	msleep(20);

	/* step.4:
	 * Wait until the voltage of VCM keep stable at AGND.
	 */

	/* step.5:
	 * Power off the analog power supply.
	 */

	/* step.6:
	 * Power off the digital power supply
	 */

	return 0;
}

/* ---------------------------------------------------------------------------*/

static int _codec_init(struct snd_soc_component *component)
{
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);
	int ret = 0;

	MSG("\n");
	/*
	 * initial every registers...
	 */
	_power_up(priv_data);
	_dac_i2s_setup(priv_data);
	_adc_i2s_setup(priv_data);

	_dac_enable(priv_data);
	_adc_enable(priv_data);

	/* Automatic Level Control (ALC) for smooth audio recording */
	_alc_enable(priv_data);

	if (ret != 0) {
		ERR("initialize Codec failed!!\n");
		return -1;
	}
	return 0;
}

/* ---------------------------------------------------------------------------*/

static int inno_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *codec_dai)
{
	struct snd_soc_component *component = codec_dai->component;
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);
	void __iomem *mmr_base = priv_data->mmr_base;
	int pcm_fmt = params_format(params);
	unsigned int valid_len, value;

	MSG("PCM format %d; Sample Rate %d, Stream direction %d\n",
		pcm_fmt, params_rate(params), substream->stream);

	switch (pcm_fmt) {
	case SNDRV_PCM_FORMAT_S16_LE:
		valid_len = I2S_WORD_LEN_16B;
		break;
	case SNDRV_PCM_FORMAT_S32_LE:
		valid_len = I2S_WORD_LEN_32B;
		break;
	default:
		ERR("Unexpected PCM format %d\n", pcm_fmt);
		return -EINVAL;
	}

	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		/* Playback - DAC */
		value = (PAR_I2S_LRC_POL   << 7) |
				(valid_len         << 5) |
				(PAR_I2S_FORMAT    << 3) |
				(PAR_I2S_LR_SWAP   << 2);
		__codec_write(mmr_base, REG_DAC_I2S, value);
	} else {
		/* Capture - ADC */
		unsigned int mono_mode;

		if (priv_data->mono_mode_adc > 2) {
			WRN("Invalid ADC mono mode value (%d)! Set preset stereo mode.\n",
				priv_data->mono_mode_adc);
			priv_data->mono_mode_adc = 0;
		}
		mono_mode = table_mono_mode_adc[priv_data->mono_mode_adc];

		value = (PAR_I2S_LRC_POL   << 7) |
				(valid_len		   << 5) |
				(PAR_I2S_FORMAT    << 3) |
				mono_mode;
		__codec_write(mmr_base, REG_ADC_I2S, value);
	}

	return 0;
}

/* bit [7] 0: Mute. 1: Work. */
#define INNO_MASK_MUTE  (0x01 << 7)
#define INNO_HW_MUTE    (0x00 << 7) // 0: Mute.
#define INNO_HW_UNMUTE  (0x01 << 7) // 1: Work.

#define INNO_MUTE(reg) \
	snd_soc_component_update_bits(component, reg, INNO_MASK_MUTE, INNO_HW_MUTE)
#define INNO_UNMUTE(reg) \
	snd_soc_component_update_bits(component, reg, INNO_MASK_MUTE, INNO_HW_UNMUTE)

static int inno_mute(struct snd_soc_dai *codec_dai, int mute, int stream)
{
	struct snd_soc_component *component = codec_dai->component;

	MSG("%s, direction %d\n", mute ? "Mute" : "Un-Mute", stream);

	if (mute) {
		if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
			INNO_MUTE(REG_DAC_CTRL_L);
			INNO_MUTE(REG_DAC_CTRL_R);
		} else if (stream == SNDRV_PCM_STREAM_CAPTURE) {
			INNO_MUTE(REG_ADC_GAIN_L);
			INNO_MUTE(REG_ADC_GAIN_R);
		}
	} else {
		if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
			INNO_UNMUTE(REG_DAC_CTRL_L);
			INNO_UNMUTE(REG_DAC_CTRL_R);
		} else if (stream == SNDRV_PCM_STREAM_CAPTURE) {
			INNO_UNMUTE(REG_ADC_GAIN_L);
			INNO_UNMUTE(REG_ADC_GAIN_R);
		}
	}

	return 0;
}

static int inno_set_dai_sysclk(struct snd_soc_dai *codec_dai,
	int clk_id, unsigned int freq, int dir)
{
	MSG("\n");
	return 0;
}

static int inno_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	// fmt: SND_SOC_DAIFMT_* format value. ex: I2S, DSP_A, LEFT_J, AC97.
	MSG("\n");
	return 0;
}

static int inno_set_bias_level(struct snd_soc_component *component,
	enum snd_soc_bias_level level)
{
	// TODO: implement it (API: snd_soc_component_update_bits)
	switch (level) {
	case SND_SOC_BIAS_ON:
		DBG("SND_SOC_BIAS_ON\n");
		break;
	case SND_SOC_BIAS_PREPARE:
		DBG("SND_SOC_BIAS_PREPARE\n");
		break;
	case SND_SOC_BIAS_STANDBY:
		DBG("SND_SOC_BIAS_STANDBY\n");
		break;
	case SND_SOC_BIAS_OFF:
		DBG("SND_SOC_BIAS_OFF\n");
		break;
	}

	return 0;
}

static int inno_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
	int div_id, int div)
{
	struct snd_soc_component *component = codec_dai->component;
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);
	void __iomem *mmr_base = priv_data->mmr_base;
	struct clk *clk;

	/* called when this internal codec as I2S bus master */
	MSG("div_id %d, div %d\n", div_id, div); // div = Fs

	/*
	 * input  MCLK = 256 * Fs (pin_adc_mclk & pin_dac_mclk)
	 * output BCLK = 1/4 MCLK (pin_sck_o)
	 * output WS   = 1/64 BCLK (pin_adc_ws_o , pin_dac_ws_o)
	 */
	// ex: Fs = 48 KHz -> MCLK = 256 * Fs = 256 * 48 KHz = 12.288 MHz

	switch (div_id) {
	default:
		WRN("div_id: 0x%x not support!\n", div_id);
		break;
	/* TX */
	case VTX_BOARD_ADCD_TX:
		if (priv_data->clk_tx_mclk == NULL) {
			clk = devm_clk_get(priv_data->dev, CLK_ADCD_TX_MCLK);
			priv_data->clk_tx_mclk = clk;
		} else
			clk = priv_data->clk_tx_mclk;
		/* error handle */
		if (IS_ERR(clk)) {
			priv_data->clk_tx_mclk = NULL;
			ERR("[I2S] Failed to get [" CLK_ADCD_TX_MCLK "]!\n");
			return PTR_ERR(clk);
		}
		clk_set_rate(clk, CLK_RATIO_MCLK_FS * div);
		break;
	/* RX */
	case VTX_BOARD_ADCD_RX:
		if (priv_data->clk_rx_mclk == NULL) {
			clk = devm_clk_get(priv_data->dev, CLK_ADCD_RX_MCLK);
			priv_data->clk_rx_mclk = clk;
		} else
			clk = priv_data->clk_rx_mclk;
		/* error handle */
		if (IS_ERR(clk)) {
			priv_data->clk_rx_mclk = NULL;
			ERR("[I2S] Failed to get [" CLK_ADCD_RX_MCLK "]!\n");
			return PTR_ERR(clk);
		}
		clk_set_rate(clk, CLK_RATIO_MCLK_FS * div);
		break;
	}

	/* ALC module (for ADC microphone input) */
	switch (div) {
	case 96000:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 0);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 0);
		break;
	case 48000:
	default:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 1);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 1);
		break;
	case 44100:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 2);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 2);
		break;
	case 32000:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 3);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 3);
		break;
	case 24000:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 4);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 4);
		break;
	case 16000:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 5);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 5);
		break;
	case 12000:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 6);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 6);
		break;
	case 8000:
		__codec_write(mmr_base, REG_SAMPLE_RATE_L, 7);
		__codec_write(mmr_base, REG_SAMPLE_RATE_R, 7);
		break;
	}

	return 0;
}

static const struct snd_soc_dai_ops inno_dai_ops = {
	.hw_params    = inno_hw_params,
	.mute_stream  = inno_mute, // digital_mute
	.set_sysclk   = inno_set_dai_sysclk,
	.set_fmt      = inno_set_dai_fmt,
	.set_clkdiv   = inno_set_dai_clkdiv,
//	.no_capture_mute = 1,
};

static struct snd_soc_dai_driver inno_dai = {
	.name = "inno-hifi",
	.playback = {
		.stream_name = "Playback",
		.channels_min = 1,
		.channels_max = 2,
		.rates = (SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000 |
			  SNDRV_PCM_RATE_32000 | SNDRV_PCM_RATE_44100 |
			  SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_KNOT),
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S32_LE,
		},
	.capture = {
		.stream_name = "Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rates = (SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000 |
			  SNDRV_PCM_RATE_32000 | SNDRV_PCM_RATE_44100 |
			  SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_KNOT),
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S32_LE,
		},
	.ops = &inno_dai_ops,
	.symmetric_rate = 1,
};

static int inno_probe(struct snd_soc_component *component)
{
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);
	void __iomem *mmr_base = priv_data->mmr_base;
	int ret;

	MSG("+++ Component probe\n");
	util_dump_mmr("INNO-ACDC", mmr_base, 100);

	/* Soft Reset */
	__codec_write(mmr_base, REG_SW_RESET, 0x0);
	usleep_range(100, 1000); // check...
	__codec_write(mmr_base, REG_SW_RESET, 0x3);

	/* Codec Initial */
	ret = _codec_init(component);
	if (ret < 0) {
		DERR(component->dev, "failed to codec initial!\n");
		return ret;
	}

	inno_set_bias_level(component, SND_SOC_BIAS_STANDBY);

	util_dump_mmr("INNO-ACDC init", mmr_base, 100);
	MSG("--- Component probe\n");
	return ret;
}

static void inno_remove(struct snd_soc_component *component)
{
	struct inno_priv *priv_data = snd_soc_component_get_drvdata(component);

	MSG("\n");
	inno_set_bias_level(component, SND_SOC_BIAS_OFF);
	_alc_disable(priv_data);
	_power_down(priv_data);
}

#ifdef CONFIG_PM
static int inno_suspend(struct snd_soc_component *component)
{
	MSG("\n");
	inno_set_bias_level(component, SND_SOC_BIAS_OFF);
	return 0;
}

static int inno_resume(struct snd_soc_component *component)
{
	MSG("\n");
	inno_set_bias_level(component, SND_SOC_BIAS_STANDBY);
	return 0;
}
#else
#define inno_suspend NULL
#define inno_resume  NULL
#endif

/* ========================================================================== */

static const struct snd_soc_component_driver inno_driver = {
//	.name    = "inno-acdc",
	.probe   = inno_probe,
	.remove  = inno_remove,
	.suspend = inno_suspend,
	.resume  = inno_resume,
	.set_bias_level = inno_set_bias_level,
//	.legacy_dai_naming = 1,
	/* Register access */
	.write = codec_register_write,
	.read  = codec_register_read,
	/* kcontrol objects */
	.controls     = innosilicon_snd_controls,
	.num_controls = ARRAY_SIZE(innosilicon_snd_controls),
};

/* ========================================================================== */

#ifdef tag_PLATFORM_DRIVER
#endif

static int inno_platform_probe(struct platform_device *pdev)
{
	int ret;
	struct device *dev = &pdev->dev;
	struct resource *res;
	struct inno_priv *priv_data;
	unsigned long base_addr, mmr_size;

	MSG("+++\n");

	priv_data = devm_kzalloc(dev, sizeof(*priv_data), GFP_KERNEL);
	if (priv_data == NULL)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		ERR("get resource from DT failed!\n");
		ret = -EFAULT;
		goto err_get_resource;
	}
	base_addr = res->start;
	mmr_size = res->end - res->start + 1; // INNO_MMR_SIZE
	MSG("MMR base address @ %lx, size %ld\n", base_addr, mmr_size);

	/* ------------------------------------------------------------------ */
	/*
	 * Device Tree parsing
	 */
	/* DT: Digital MIC - PDM */
	if (device_property_present(dev, "adcdcc-pdm")) {
		MSG("PDM on.\n");
		priv_data->is_pdm_on = true;
		if (device_property_present(dev, "pdm-gain")) {
			ret = device_property_read_u32(dev,
					"pdm-gain", &priv_data->pdm_gain);
			if ((ret) || (priv_data->pdm_gain > 7)) {
				DWRN(dev, "Invalid PDM gain value specified!\n");
				priv_data->pdm_gain = PAR_MIC_GAIN_DIG; // set default
			}
			MSG("PDM gain: %d\n", priv_data->pdm_gain);
		}
	}

	/* DT: MONO mode */
		/* ADC / MIC IN */
	if (device_property_present(dev, "adc-mono")) {
		ret = device_property_read_u32(dev, "adc-mono", &priv_data->mono_mode_adc);
		if ((ret) || (priv_data->mono_mode_adc > 2)) {
			DWRN(dev, "Invalid ADC mono value specified!\n");
			priv_data->mono_mode_adc = 0; // set default
		}
		MSG("ADC mono mode property: %d\n", priv_data->mono_mode_adc);
	}
	/* ------------------------------------------------------------------ */

	/* MMR remap */
	request_mem_region(base_addr, mmr_size >> 2, "INNO-ACDC");
	priv_data->mmr_base = ioremap(base_addr, mmr_size);
	if (IS_ERR(priv_data->mmr_base)) {
		ERR("get INNO-ACDC MMR ioremap resource failed!\n");
		ret = PTR_ERR(priv_data->mmr_base);
		goto err_iomap_reg;
	}

	/* Register mapping initial */
	priv_data->regmap = devm_regmap_init_mmio(dev, priv_data->mmr_base, &inno_regmap_config);
	if (IS_ERR(priv_data->regmap)) {
		ERR("failed to init register map!\n");
		ret = PTR_ERR(priv_data->regmap);
		goto err_regmap_init;
	}

	priv_data->dev = dev;
	dev_set_drvdata(dev, priv_data);

	/* Component registration */
	ret = devm_snd_soc_register_component(dev, &inno_driver, &inno_dai, 1);
	if (ret < 0) {
		ERR("failed to register Component!\n");
		goto err_reg_comp;
	}
	DDBG(dev, "register Component done.\n");

	MSG("---\n");
	return ret;

err_reg_comp:
err_regmap_init:
	iounmap(priv_data->mmr_base);
	release_mem_region(base_addr, mmr_size);
err_iomap_reg:
err_get_resource:
	devm_kfree(dev, priv_data);

	return ret;
}

static int inno_platform_remove(struct platform_device *pdev)
{
	struct inno_priv *priv_data;
	struct clk *clk;

	priv_data = platform_get_drvdata(pdev);

	MSG("+++\n");
	/*
	 * Clock Framework
	 */
	/* Tx Master Clock */
	clk = priv_data->clk_tx_mclk;
	if (!IS_ERR(clk))
		devm_clk_put(priv_data->dev, clk);
	priv_data->clk_tx_mclk = NULL;
	/* Rx Master Clock */
	clk = priv_data->clk_rx_mclk;
	if (!IS_ERR(clk))
		devm_clk_put(priv_data->dev, clk);
	priv_data->clk_rx_mclk = NULL;

	/*
	 * release I/O mapped MMR region
	 */
	iounmap(priv_data->mmr_base);
	release_mem_region(INNO_MMR_BASE, INNO_MMR_SIZE);

	devm_kfree(&pdev->dev, priv_data);

	MSG("---\n");
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id inno_dt_match[] = {
	{ .compatible = "innosilicon,audio-codec", },
//	{ .compatible = "vtx,audio-codec-int", },
	{}
};
#endif

static struct platform_driver inno_platform = {
	.driver = {
		.name = "inno-acdc",
		.owner = THIS_MODULE,
#ifdef CONFIG_OF
		.of_match_table = inno_dt_match,
#endif
	},
	.probe  = inno_platform_probe,
	.remove = inno_platform_remove,
};

module_platform_driver(inno_platform);

MODULE_DESCRIPTION("ASoC Audio Codec driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");


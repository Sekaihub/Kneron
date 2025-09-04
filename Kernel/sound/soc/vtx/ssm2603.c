// SPDX-License-Identifier: GPL-2.0-only
/*
 * Audio_SSM2603
 * Driver for Audio Codec SSM2603.
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/regmap.h>
#include <linux/regulator/consumer.h>
#include <linux/spi/spi.h>
#include <linux/of_device.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

#include "vtx-asoc-platform.h"
#include "ssm2603.h"

/* ========================================================================== */

#define ssm2603_reset(c)  regmap_write(c, SW_RESET_REG, 0)

/* ========================================================================== */

static int ssm2603_i2c_write(struct snd_soc_component *component,
	unsigned int reg, unsigned int val)
{
	struct ssm2603_priv *ssm2603 = snd_soc_component_get_drvdata(component);
	struct i2c_client *i2cdev = ssm2603->i2c_client;
	unsigned char buf[2];
	unsigned char recv[2] = {0};
	int ret = 0;

	buf[0] = (unsigned char)((reg << 1) | ((val >> 8) & 0x01));
	buf[1] = (unsigned char)(val & 0xff);

	if (i2c_master_send(i2cdev, buf, 2) != 2) {
		ERR("i2c_master_send return unexcepted size(2)!\n");
		ret = -1;
	}
	ssm2603->reg_cache[reg] = val;

	recv[0] = (unsigned char)(reg << 1);
	recv[1] = 0;
	i2c_master_recv(i2cdev, recv, 2);
	return ret;
}

static int codec_init(struct snd_soc_component *component)
{
	int ret = 0;

	MSG("\n");
	/* initial every registers.. */
	ret = 0;
	ret |= snd_soc_component_write(component, LEFT_ADC_VOLUME_REG, 0x17);
	ret |= snd_soc_component_write(component, RIGHT_ADC_VOLUME_REG, 0x17);
	ret |= snd_soc_component_write(component, LEFT_DAC_VOLUME_REG, 0x79);
	ret |= snd_soc_component_write(component, RIGHT_DAC_VOLUME_REG, 0x79);
	ret |= snd_soc_component_write(component, ANA_AUDIO_PATH_REG, 0x113);
	ret |= snd_soc_component_write(component, DIG_AUDIO_PATH_REG, 0x00);
	ret |= snd_soc_component_write(component, POWER_MANAGE_REG, 0x60);
#if (CFG_I2S_MASTER_MODE < 2) /* as I2S Slave mode */
	ret |= snd_soc_component_write(component, DIGI_AUDIO_IF_REG, 0x2);
#else /* as I2S Master mode */
	ret |= snd_soc_component_write(component, DIGI_AUDIO_IF_REG, 0x42);
#endif
	ret |= snd_soc_component_write(component, SAMPLE_RATE_REG, 0x00);
	ret |= snd_soc_component_write(component, ACTIVE_REG, 0x01);

	if (ret != 0) {
		ERR("Initialize SSM2603 failed!!\n");
		return -1;
	}
	return 0;
}

static int ssm2603_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
//TODO implement it
	//struct snd_soc_codec *codec = dai->codec;
	MSG("\n");
	return 0;
}

static int ssm2603_mute(struct snd_soc_dai *dai, int mute, int direction)
{
//TODO implement it
	MSG("\n");
	return 0;
}

static int ssm2603_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
//TODO implement it
	MSG("\n");
	return 0;
}

static int ssm2603_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
//TODO implement it
	MSG("\n");
	return 0;
}

static int ssm2603_set_bias_level(struct snd_soc_component *component,
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

static int ssm2603_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
	int div_id, int div)
{
	struct snd_soc_component *component = codec_dai->component;

	/*  need to set mclk to 11.2896, do it in board file
	 *  other mclk would be 12.288
	 */
	switch (div) {
	case 48000:
	default:
		snd_soc_component_write(component, SAMPLE_RATE_REG, 0x00 << 2);
		break;
	case 44100:
		snd_soc_component_write(component, SAMPLE_RATE_REG, 0x8 << 2);
		break;
	case 32000:
		snd_soc_component_write(component, SAMPLE_RATE_REG, 0x6 << 2);
		break;
	case 16000:
		snd_soc_component_write(component, SAMPLE_RATE_REG, 0x5 << 2);
		break;
	case 8000:
		snd_soc_component_write(component, SAMPLE_RATE_REG, 0x3 << 2);
		break;
	}
	return 0;
}

static const struct snd_soc_dai_ops ssm2603_dai_ops = {
	.hw_params    = ssm2603_hw_params,
	.mute_stream  = ssm2603_mute, // digital_mute
	.set_sysclk   = ssm2603_set_dai_sysclk,
	.set_fmt      = ssm2603_set_dai_fmt,
	.set_clkdiv   = ssm2603_set_dai_clkdiv,
//	.no_capture_mute = 1,
};

static struct snd_soc_dai_driver ssm2603_dai = {
	.name = "ssm2603-hifi",
	.playback = {
		.stream_name = "Playback",
		.channels_min = 1,
		.channels_max = 2,
		.rates = (SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000 |
			  SNDRV_PCM_RATE_32000 | SNDRV_PCM_RATE_44100 |
			  SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_KNOT),
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		},
	.capture = {
		.stream_name = "Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rates = (SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000 |
			  SNDRV_PCM_RATE_32000 | SNDRV_PCM_RATE_44100 |
			  SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_KNOT),
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
		},
	.ops = &ssm2603_dai_ops,
	.symmetric_rate = 1,
};

static int ssm2603_probe(struct snd_soc_component *component)
{
	struct ssm2603_priv *ssm2603 = snd_soc_component_get_drvdata(component);
	int ret;

	MSG("\n");
	ret = ssm2603_reset(ssm2603->regmap);
	if (ret < 0) {
		DERR(component->dev, "Failed to issue reset!\n");
		return ret;
	}

	ret = codec_init(component);
	if (ret < 0)
		return ret;

	ssm2603_set_bias_level(component, SND_SOC_BIAS_STANDBY);
	return ret;
}

static void ssm2603_remove(struct snd_soc_component *component)
{
	MSG("\n");
	ssm2603_set_bias_level(component, SND_SOC_BIAS_OFF);
}

#ifdef CONFIG_PM
static int ssm2603_suspend(struct snd_soc_component *component)
{
	MSG("\n");
	ssm2603_set_bias_level(component, SND_SOC_BIAS_OFF);
	return 0;
}

static int ssm2603_resume(struct snd_soc_component *component)
{
	MSG("\n");
	ssm2603_set_bias_level(component, SND_SOC_BIAS_STANDBY);
	return 0;
}
#else
#define ssm2603_suspend NULL
#define ssm2603_resume NULL
#endif

static const struct snd_soc_component_driver ssm2603_driver = {
	.probe   = ssm2603_probe,
	.remove  = ssm2603_remove,
	.suspend = ssm2603_suspend,
	.resume  = ssm2603_resume,
	.set_bias_level = ssm2603_set_bias_level,
	.write          = ssm2603_i2c_write,
};

static const struct of_device_id ssm2603_of_match[] = {
	{ .compatible = "wlf,ssm2603", },
	{ }
};
MODULE_DEVICE_TABLE(of, ssm2603_of_match);

/* ---------------------------------------------------------------------------*/
#ifdef tag_i2c
#endif

// static const struct reg_default ssm2603_reg_default[] = { };

static bool ssm2603_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case SW_RESET_REG:
		return true;
	default:
		return false;
	}
}

static const struct regmap_config ssm2603_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.max_register = NOISE_GATE_REG,
	.volatile_reg  = ssm2603_volatile_register,
};

static int ssm2603_i2c_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	int ret;
	struct ssm2603_priv *ssm2603;

	MSG("+++\n");
	ssm2603 = kzalloc(sizeof(struct ssm2603_priv), GFP_KERNEL);
	if (ssm2603 == NULL)
		return -ENOMEM;

	ssm2603->regmap = devm_regmap_init_i2c(client, &ssm2603_regmap);
	if (IS_ERR(ssm2603->regmap))
		return PTR_ERR(ssm2603->regmap);

	i2c_set_clientdata(client, ssm2603);
	ssm2603->i2c_client = client;

	ret = devm_snd_soc_register_component(&client->dev,
			&ssm2603_driver, &ssm2603_dai, 1);
	if (ret < 0) {
		ERR("SSM2603 failed to register!\n");
		goto err;
	}
	MSG("---\n");
	return ret;

err:
	return ret;
}

static void ssm2603_i2c_remove(struct i2c_client *client)
{

}

static const struct i2c_device_id ssm2603_i2c_id[] = {
	{ "ssm2603", 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, ssm2603_i2c_id);

static const unsigned short normal_i2c[] = { 0x1a, I2C_CLIENT_END };
struct i2c_driver ssm2603_i2c_driver = {
	.driver = {
		.name = "ssm2603",
		.owner = THIS_MODULE,
		.of_match_table = ssm2603_of_match,
	},
	.probe =    ssm2603_i2c_probe,
	.remove =   ssm2603_i2c_remove,
	.id_table = ssm2603_i2c_id,
	.address_list = normal_i2c,
	.class = I2C_CLASS_HWMON,
};
//module_i2c_driver(ssm2603_i2c_driver);
EXPORT_SYMBOL(ssm2603_i2c_driver);


MODULE_DESCRIPTION("ASoC SSM2603 driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");



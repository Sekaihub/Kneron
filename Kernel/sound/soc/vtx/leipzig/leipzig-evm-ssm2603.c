// SPDX-License-Identifier: GPL-2.0-only
/*
 * ALSA SoC Machine driver for VATICS EVM
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/platform_device.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/soc.h>
#include <sound/soc-dapm.h>

//#define OPT_DEBUG_LOCAL // local switch for debug
#include "vtx-asoc.h"
#include "../ssm2603.h"

/* GPIO */
#include <linux/gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/of_gpio.h>

/* ========================================================================== */

// matser clock source
enum i2s_mclk {
	I2S_MCLK_INTERNAL = 0,
	I2S_MCLK_EXTERNAL = 1,
};

// serial clock source
enum i2s_sclk {
	I2S_SCLK_INTERNAL = 0, // from internal audio codec
	I2S_SCLK_EXTERNAL = 1, // from External audio codec
	I2S_SCLK_INT_DIV  = 2, // from internal divider
};

struct evm_private {
	/* I2S bus master mode */
	int i2s_bus_master; // =0 ADCDCC; =1 I2SSC; >=2 external codec
	/* I2S Rx */
	enum i2s_mclk mclk_rx_src;
	enum i2s_sclk sclk_rx_src;
	int i2s_rx_mode; // internal I2S Rx module as I2S Master or Slave mode
	/* I2S Tx */
	enum i2s_mclk mclk_tx_src;
	enum i2s_sclk sclk_tx_src;
	int i2s_tx_mode; // internal I2S Tx module as I2S Master or Slave mode
	/* GPIO */
	int gpio_select;
};

/* ========================================================================== */

static int evm_hw_params(struct snd_pcm_substream *substream,
					struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	int sample_rate = params_rate(params);
	/* DAI - codec: (rtd)->dais[n + (rtd)->dai_link->num_cpus] */
	struct snd_soc_dai *codec_dai = asoc_rtd_to_codec(rtd, 0);
	/* DAI - CPU: (rtd)->dais[n] */
	struct snd_soc_dai *cpu_dai = asoc_rtd_to_cpu(rtd, 0);
	struct evm_private *priv = snd_soc_card_get_drvdata(rtd->card);
	int div_id = VTX_BOARD_WS;
	int ret = 0;

	MSG("\n");
	if ((priv->i2s_tx_mode) || (priv->i2s_rx_mode))
		ret = snd_soc_dai_set_clkdiv(cpu_dai, div_id, sample_rate);

	/* CODEC clock setting */
	ret = snd_soc_dai_set_clkdiv(codec_dai, 0, sample_rate);

	return 0;
}


static const struct snd_soc_ops evm_ops = {
	.hw_params = evm_hw_params,
};

static int evm_codec_init(struct snd_soc_pcm_runtime *rtd)
{
	MSG("\n");
	return 0;
}

/* ---------------------------------------------------------------------------*/
#ifdef tag_DAI_LINK
#endif

/* I2C bus codec must use this naming style: <NAME>.<I2CBus>-<I2Caddr> */
SND_SOC_DAILINK_DEFS(ext_codec,
	DAILINK_COMP_ARRAY(COMP_CPU(VPL_PLATFORM)),
	DAILINK_COMP_ARRAY(COMP_CODEC("ssm2603.0-001a", "ssm2603-hifi")),
	DAILINK_COMP_ARRAY(COMP_PLATFORM(VPL_PLATFORM)));

/*
 * MACRO "SND_SOC_DAILINK_DEFS(ext_codec, cpu, codec, platform)" expanding:
static struct snd_soc_dai_link_component ext_codec_cpus[] =
	{ { .dai_name = "vtx-pcm", } };
static struct snd_soc_dai_link_component ext_codec_codecs[] = {
	{ .name = "ssm2603.0-001a", .dai_name = "ssm2603-hifi", } };
static struct snd_soc_dai_link_component ext_codec_platforms =
	{ { .name = "vtx-pcm" } };
 *
 * MACRO "SND_SOC_DAILINK_REG(ext_codec)" expanding:
	.cpus     = ext_codec_cpus,
	.num_cpus = ARRAY_SIZE(ext_codec_cpus),
	.codecs	    = ext_codec_codecs,
	.num_codecs = ARRAY_SIZE(ext_codec_codecs),
	.platforms      = ext_codec_platforms,
	.num_platforms  = ARRAY_SIZE(ext_codec_platforms)
 */

static struct snd_soc_dai_link evm_dai_link = {
	.name = "EVM_sound",
	.stream_name = "vtx-stream",
	.init = evm_codec_init,
	.ops = &evm_ops,
	SND_SOC_DAILINK_REG(ext_codec),
};

static struct snd_soc_card evm_soc_card = {
	.name = "VTX EVM - SSM2603",
	.owner = THIS_MODULE,
	.dai_link = &evm_dai_link,
	.num_links = 1,
};

/* ========================================================================== */

#ifdef tag_PLATFORM_DRIVER
#endif

static int leipzig_ssm2603_machine_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &evm_soc_card;
	int ret;
//	struct device_node *platform_node, *codec_node;
	struct evm_private *priv;
	struct device *dev = &pdev->dev;
//	struct snd_soc_dai_link *dai_link;
//	int i;

	MSG("+++\n");
	priv = devm_kzalloc(&pdev->dev, sizeof(struct evm_private),
		GFP_KERNEL);

	if (!priv)
		return -ENOMEM;

	/*
	 * Device Tree parsing
	 */
	/* I2S Rx */
	if (device_property_present(dev, "i2s-rx-mode")) {
		ret = device_property_read_u32(dev,
				"i2s-rx-mode", &priv->i2s_rx_mode);
		if (ret) {
			DWRN(dev, "invalid I2S Rx mode value specified!\n");
			priv->mclk_rx_src = 0; // set default
		}
	}
	if (device_property_present(dev, "i2s-rx,mclk")) {
		ret = device_property_read_u32(dev,
				"i2s-rx,mclk", &priv->mclk_rx_src);
		if (ret) {
			DWRN(dev, "invalid I2S Rx MCLK value specified!\n");
			priv->i2s_rx_mode = 0; // set default
		}
	}
	MSG("I2S Rx config: mode %d, MCLK source %d\n",
		priv->i2s_rx_mode, priv->mclk_rx_src);

	/* I2S Tx */
	if (device_property_present(dev, "i2s-tx-mode")) {
		ret = device_property_read_u32(dev,	"i2s-tx-mode", &priv->i2s_tx_mode);
		if (ret) {
			DWRN(dev, "invalid I2S Tx mode value specified!\n");
			priv->i2s_tx_mode = 0; // set default
		}
	}
	if (device_property_present(dev, "i2s-tx,mclk")) {
		ret = device_property_read_u32(dev,
				"i2s-tx,mclk", &priv->mclk_tx_src);
		if (ret) {
			DWRN(dev, "invalid I2S Tx MCLK value specified!\n");
			priv->mclk_tx_src = 0; // set default
		}
	}
	MSG("I2S Tx config: mode %d, MCLK source %d\n",
		priv->i2s_tx_mode, priv->mclk_tx_src);

	snd_soc_card_set_drvdata(card, priv);

	/*
	 * I2C bus driver
	 */
	i2c_add_driver(&ssm2603_i2c_driver);

	/*
	 * SoC Card Register
	 */
	card->dev = dev;
	ret = devm_snd_soc_register_card(dev, card);
	if (ret)
		DERR(dev, "register SoC card failed!(%d)\n", ret);

	MSG("---\n");
	return ret;
}

#ifdef CONFIG_OF
static const struct of_device_id leipzig_ssm2603_machine_dt_match[] = {
	{ .compatible = "vtx,evm-ssm2603-machine", },
	{}
};
MODULE_DEVICE_TABLE(of, leipzig_ssm2603_machine_dt_match);
#endif

static struct platform_driver leipzig_ssm2603_machine = {
	.driver = {
		.name = "vtx-evm-ssm2603",
#ifdef CONFIG_OF
		.of_match_table = leipzig_ssm2603_machine_dt_match,
#endif
	},
	.probe = leipzig_ssm2603_machine_probe,
};

module_platform_driver(leipzig_ssm2603_machine);


MODULE_DESCRIPTION("LEIPZIG ALSA SoC machine driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");


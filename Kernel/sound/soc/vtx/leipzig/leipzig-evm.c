// SPDX-License-Identifier: GPL-2.0-only
/*
 * ALSA SoC Machine driver for VATICS EVM
 */

/* ========================================================================== */
/* Compile Option */

//#define OPT_DEBUG_LOCAL // local switch for debug

/* ========================================================================== */
/* Include Header File */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/platform_device.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/soc.h>
#include <sound/soc-dapm.h>

#include "vtx-asoc.h"

/* GPIO */
#include <linux/gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/of_gpio.h>

/* ========================================================================== */

// serial clock source
enum i2s_sclk {
	I2S_SCLK_INTERNAL = 0, // from internal audio codec
	I2S_SCLK_EXTERNAL = 1, // from External audio codec
	I2S_SCLK_INT_DIV  = 2, // from internal divider
};

struct evm_private {
	void __iomem *mmr_base_sysc; // SYSC module
	/* I2S bus master mode */
	int i2s_bus_master; // =0 ADCDCC; =1 I2SSC; >=2 external codec
	/* I2S Rx */
	enum i2s_sclk sclk_rx_src;
	/* I2S Tx */
	enum i2s_sclk sclk_tx_src;
	/* others */
	bool adcd_pdm_enable;
	int gpio_select;
};

/* ========================================================================== */

static int set_clk_cpu(struct snd_soc_dai *cpu_dai,
	int stream_dir, int sample_rate)
{
#if (CFG_I2S_MASTER_MODE == 1) // I2SSC as master
	int ret;
	int div_id;

	ret = snd_soc_dai_set_clkdiv(cpu_dai, VTX_BOARD_I2S_MCLK, sample_rate);
	if (ret < 0)
		return ret;

	if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK)
		div_id = VTX_BOARD_I2S_TX;
	else if (stream_dir == SNDRV_PCM_STREAM_CAPTURE)
		div_id = VTX_BOARD_I2S_RX;
	else
		return -EINVAL;

	ret = snd_soc_dai_set_clkdiv(cpu_dai, div_id, sample_rate);
	if (ret < 0)
		return ret;
#endif

	return 0;
}

static int set_clk_codec(struct snd_soc_dai *codec_dai,
	int stream_dir, int sample_rate)
{
#if (CFG_I2S_MASTER_MODE == 0) // ADCDCC as master
	int ret;
	int div_id;

	MSG("Fs %d, Stream direction %d\n", sample_rate, stream_dir);

	if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK)
		div_id = VTX_BOARD_ADCD_TX;
	else if (stream_dir == SNDRV_PCM_STREAM_CAPTURE)
		div_id = VTX_BOARD_ADCD_RX;
	else
		return -EINVAL;

	ret = snd_soc_dai_set_clkdiv(codec_dai, div_id, sample_rate);
	if (ret < 0)
		return ret;
#endif
	return 0;
}

static int evm_hw_params(struct snd_pcm_substream *substream,
					struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	int sample_rate = params_rate(params);
	int stream_dir = substream->stream;
	/* DAI - CODEC: (rtd)->dais[n + (rtd)->dai_link->num_cpus] */
	struct snd_soc_dai *codec_dai = asoc_rtd_to_codec(rtd, 0);
	/* DAI - CPU: (rtd)->dais[n] */
	struct snd_soc_dai *cpu_dai = asoc_rtd_to_cpu(rtd, 0);
	int ret = 0;

	MSG("\n");

	/* CPU */
	if ((sample_rate == 44100) || (sample_rate == 22050) || (sample_rate == 11025))
		ret = snd_soc_dai_set_pll(cpu_dai, 0, 0, 0, 67737600);
	else
		ret = snd_soc_dai_set_pll(cpu_dai, 0, 0, 0, 49152000);

	if (ret < 0)
		return ret;

	ret = set_clk_cpu(cpu_dai, stream_dir, sample_rate);
	if (ret < 0)
		return ret;

	/* CODEC */
	ret = set_clk_codec(codec_dai, stream_dir, sample_rate);

	return ret;
}


static const struct snd_soc_ops evm_ops = {
	.hw_params = evm_hw_params,
};

static int evm_codec_init(struct snd_soc_pcm_runtime *rtd)
{
	struct evm_private *priv = snd_soc_card_get_drvdata(rtd->card);
	void __iomem *mmr_base_sysc = priv->mmr_base_sysc; // SYSC module

	MSG("\n");
	sysc_enable_adcd_tx_dac(mmr_base_sysc);
	sysc_enable_adcd_rx_adc(mmr_base_sysc);
	return 0;
}

/* ---------------------------------------------------------------------------*/
#ifdef tag_DAI_LINK
#endif

/* I2C bus Codec must use this naming style: <NAME>.<I2CBus>-<I2Caddr> */
/* Internal Codec use this naming style if from DT: <Address>.<Node Name> */
SND_SOC_DAILINK_DEFS(vtx_evm,
	DAILINK_COMP_ARRAY(COMP_CPU(VPL_PLATFORM)),
	DAILINK_COMP_ARRAY(COMP_CODEC("ce000000.inno-acdc", "inno-hifi")),
	DAILINK_COMP_ARRAY(COMP_PLATFORM(VPL_PLATFORM)));

/*
 * MACRO "SND_SOC_DAILINK_DEFS(vtx_evm, cpu, codec, platform)" expanding:
static struct snd_soc_dai_link_component vtx_evm_cpus[] =
	{ { .dai_name = "vtx-pcm", } };
static struct snd_soc_dai_link_component vtx_evm_codecs[] = {
	{ .name = "ce000000.inno-acdc", .dai_name = "inno-hifi", } };
static struct snd_soc_dai_link_component vtx_evm_platforms =
	{ { .name = "vtx-pcm" } };
 *
 * MACRO "SND_SOC_DAILINK_REG(vtx_evm)" expanding:
	.cpus     = vtx_evm_cpus,
	.num_cpus = ARRAY_SIZE(vtx_evm_cpus),
	.codecs	    = vtx_evm_codecs,
	.num_codecs = ARRAY_SIZE(vtx_evm_codecs),
	.platforms      = vtx_evm_platforms,
	.num_platforms  = ARRAY_SIZE(vtx_evm_platforms)
 */

static struct snd_soc_dai_link evm_dai_link = {
	.name = "EVM_sound",
	.stream_name = "vtx-stream",
	.init = evm_codec_init,
	.ops = &evm_ops,
	SND_SOC_DAILINK_REG(vtx_evm),
};

static struct snd_soc_card evm_soc_card = {
	.name = "VTX EVM",
	.owner = THIS_MODULE,
	.dai_link = &evm_dai_link,
	.num_links = 1,
};

/* ========================================================================== */

#ifdef tag_PLATFORM_DRIVER
#endif

static int evm_machine_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &evm_soc_card;
	int ret;
	struct evm_private *priv;
	struct device *dev = &pdev->dev;
	void __iomem *mmr_base_sysc; // SYSC module

	MSG("+++\n");
	priv = devm_kzalloc(&pdev->dev, sizeof(struct evm_private),
		GFP_KERNEL);

	if (!priv)
		return -ENOMEM;

	/*
	 * System Controller MMR remap
	 */
	request_mem_region(SYSC_BASE, SYSC_MMR_SIZE >> 2, "SYSC");
	priv->mmr_base_sysc = ioremap(SYSC_MMR_BASE, SYSC_MMR_SIZE);
	if (IS_ERR(priv->mmr_base_sysc)) {
		DERR(dev, "get SYSC ioremap resource failed!\n");
		ret = PTR_ERR(priv->mmr_base_sysc);
		goto err_iomap_sysc;
	}
	mmr_base_sysc = priv->mmr_base_sysc;

	/*
	 * Device Tree parsing
	 */
	/* I2S bus master */
	if (device_property_present(dev, "i2s-bus-master")) {
		ret = device_property_read_u32(dev,
				"i2s-bus-master", &priv->i2s_bus_master);
		if (ret) {
			DWRN(dev, "Invalid I2S bus master value specified!\n");
			priv->i2s_bus_master = 0; // set default
		}
	}

	/* I2S Rx Clock */
	if (device_property_present(dev, "i2ssc-rx,sclk")) {
		ret = device_property_read_u32(dev,
				"i2ssc-rx,sclk", &priv->sclk_rx_src);
		if (ret) {
			DWRN(dev, "Invalid I2S Rx SCLK value specified!\n");
			priv->sclk_rx_src = 0; // set default
		}
	}
	MSG("I2S Rx: serial clock source %d\n", priv->sclk_rx_src);
	sysc_set_i2s_rx_ctrl(mmr_base_sysc, priv->i2s_bus_master);

	/* I2S Tx Clock */
	if (device_property_present(dev, "i2ssc-tx,sclk")) {
		ret = device_property_read_u32(dev,
				"i2ssc-tx,sclk", &priv->sclk_tx_src);
		if (ret) {
			DWRN(dev, "Invalid I2S Tx SCLK value specified!\n");
			priv->sclk_tx_src = 0; // set default
		}
	}
	MSG("I2S Tx: serial clock source %d\n", priv->sclk_tx_src);
	sysc_set_i2s_tx_ctrl(mmr_base_sysc, priv->i2s_bus_master);

	/*
	 * SoC Card Register
	 */
	snd_soc_card_set_drvdata(card, priv);

	card->dev = dev;
	ret = devm_snd_soc_register_card(dev, card);
	if (ret) {
		DERR(dev, "register SoC card failed!(%d)\n", ret);
		goto err_register_card;
	}

	MSG("---\n");
	return 0;

err_register_card:
err_iomap_sysc:
	devm_kfree(dev, priv);

	return ret;
}

#ifdef CONFIG_OF
static const struct of_device_id evm_machine_dt_match[] = {
	{ .compatible = "vtx,evm-machine", },
	{}
};
MODULE_DEVICE_TABLE(of, evm_machine_dt_match);
#endif

static struct platform_driver evm_machine_driver = {
	.driver = {
		.name = "vtx-evm",
#ifdef CONFIG_OF
		.of_match_table = evm_machine_dt_match,
#endif
	},
	.probe = evm_machine_probe,
};
module_platform_driver(evm_machine_driver);


MODULE_DESCRIPTION("LEIPZIG ALSA SoC Machine Driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");



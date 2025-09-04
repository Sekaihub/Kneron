// SPDX-License-Identifier: GPL-2.0-only
/*
 * VTX I2S Platform Driver
 */

/* ========================================================================== */
/* Compile Option */

//#define OPT_DEBUG_LOCAL // local switch for debug
//#define OPT_DUMP_MMR_I2S

/* ========================================================================== */
/* Include Header File */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/clk.h>

#include <linux/of.h>
#include <linux/of_device.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/initval.h>
#include <sound/soc.h>

#include "vtx-asoc.h"
#include "vtx-i2s.h"

/* ========================================================================== */

/* Clock name definition */
#define CLK_DAI_PLL    "pll_9_clk"
#define CLK_I2S_CLK    "i2s_clk"
#define CLK_I2S_MCLK   "i2s_mclk"
/* Tx */
#define CLK_I2S_TX_SCLK  "i2s_tx_sclk"
#define CLK_I2S_TX_WS    "i2s_tx_ws"
/* Rx */
#define CLK_I2S_RX_SCLK  "i2s_rx_sclk"
#define CLK_I2S_RX_WS    "i2s_rx_ws"

/* -------------------------------------------------------------------------- */

#define VTX_I2S_RATES \
	(SNDRV_PCM_RATE_8000_48000 | SNDRV_PCM_RATE_96000)

/* ========================================================================== */

/* Note that this global variable is shared with fake PCM device driver */
struct vtx_audio_dev *vtx_i2s_drvdata;

/* ========================================================================== */

// rx_tx: = 0 Rx, = 1 Tx
void _dump_mmr_i2s(struct vtx_audio_dev *drv_data, int rx_tx)
{
#ifdef OPT_DUMP_MMR_I2S
/* Common: 0x00 ~ 0x1c (8); Channel 0: 0x20 ~ 0x54 (14) */
#define MMR_NUMBER  22 // ~ 0x54
#define STR  "0x%08x [%03x]	"

	unsigned int *mmr_head, mmr_addr;
	unsigned int i, j;

	if (rx_tx)
		mmr_head = (unsigned int *)drv_data->i2s_tx_base;
	else
		mmr_head = (unsigned int *)drv_data->i2s_rx_base;
	mmr_addr = (unsigned int)((unsigned long)mmr_head);

	pr_info("+++++ [I2SSC] %s MMR @ 0x%08x dump:\n",
		(rx_tx) ? "Tx" : "Rx",
		(rx_tx) ? VPL_I2SSC_TX_MMR_BASE : VPL_I2SSC_RX_MMR_BASE);
	for (i = 0; i < MMR_NUMBER; i += 4) {
		j = i * 4;
		pr_info(STR "%08x (%03x)  %08x (%03x)  %08x (%03x)	%08x (%03x)\n",
			mmr_addr + j, j,
			mmr_head[i + 0], (j + 0x0),
			mmr_head[i + 1], (j + 0x4),
			mmr_head[i + 2], (j + 0x8),
			mmr_head[i + 3], (j + 0xc));
	}

	pr_info("  DMA:\n");
	i = I2S_RXDMA; j = I2S_RXDMA >> 2;
	pr_info(STR "%08x (%03x)  %08x (%03x)  %08x (%03x)	%08x (%03x)\n",
		mmr_addr + i, i,
		mmr_head[j + 0], (i + 0x0),
		mmr_head[j + 1], (i + 0x4),
		mmr_head[j + 2], (i + 0x8),
		mmr_head[j + 3], (i + 0xc));

	pr_info("  Component Info:\n");
	i = I2S_COMP_PARAM_2; j = I2S_COMP_PARAM_2 >> 2;
	pr_info(STR "%08x (%03x)  %08x (%03x)  %08x (%03x)	%08x (%03x)\n",
		mmr_addr + i, i,
		mmr_head[j + 0], (i + 0x0),
		mmr_head[j + 1], (i + 0x4),
		mmr_head[j + 2], (i + 0x8),
		mmr_head[j + 3], (i + 0xc));

	pr_info("  TDM DMA:\n");
	mmr_head = (unsigned int *)(drv_data->i2s_tx_base + I2S_DMACR);
	mmr_addr = (unsigned int)((unsigned long)mmr_head);
	for (i = 0; i < 10; i += 4) {
		j = i * 4;
		pr_info(STR "%08x (%03x)  %08x (%03x)  %08x (%03x)	%08x (%03x)\n",
			mmr_addr + j, j,
			mmr_head[i + 0], (j + 0x0),
			mmr_head[i + 1], (j + 0x4),
			mmr_head[i + 2], (j + 0x8),
			mmr_head[i + 3], (j + 0xc));
	}

	pr_info("----- dump done!\n");
#endif
}

/* -------------------------------------------------------------------------- */

/*
 * Initialize I2S Rx, Tx module
 */
static void __i2s_init(struct snd_soc_dai *dai, int direct)
{
	struct vtx_audio_dev *drv_data = snd_soc_dai_get_drvdata(dai);
	void __iomem *mmr_base;

	if (direct == SNDRV_PCM_STREAM_PLAYBACK) {
		/* I2S Tx */
		mmr_base = drv_data->i2s_tx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER,  0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_ITER, 0x0);
//		VTX_VPL_SSP_WRITEL(mmr_base, I2S_TER,  0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IMR,  0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_TFCR, 0x3);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_TFF0, 0x1);
	} else {
		/* I2S Rx */
		mmr_base = drv_data->i2s_rx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER,  0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IRER, 0x0);
//		VTX_VPL_SSP_WRITEL(mmr_base, I2S_RER,  0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IMR,  0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_RFCR, 0x3);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_RFF0, 0x1);
	}

}

static int vtx_i2s_startup(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	DBG("+++\n");
	__i2s_init(dai, substream->stream);
	return 0;
}

static int vtx_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
//	struct vtx_audio_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
	DBG("+++\n");
	/*DO NOTHING for current design, leave this for template*/
	return 0;
}

static int vtx_i2s_set_dai_clkdiv(struct snd_soc_dai *cpu_dai,
	int div_id, int div)
{
	struct vtx_audio_dev *vtx_dev = snd_soc_dai_get_drvdata(cpu_dai);

	MSG("+++ div: %d\n", div);

	switch (div_id) {
	default:
		WRN("div_id: 0x%x not support!\n", div_id);
		break;
	/* MCLK */
	case VTX_BOARD_I2S_MCLK:
		clk_set_rate(vtx_dev->clk_i2s_mclk, div);
		break;
	/* Tx SCLK & WS */
	case VTX_BOARD_I2S_TX:
		clk_set_rate(vtx_dev->clk_i2s_tx_sclk, div * 32);
		clk_set_rate(vtx_dev->clk_i2s_tx_ws, div);
		break;
	/* Rx SCLK & WS */
	case VTX_BOARD_I2S_RX:
		clk_set_rate(vtx_dev->clk_i2s_rx_sclk, div * 32);
		clk_set_rate(vtx_dev->clk_i2s_rx_ws, div);
		break;
	}

	return 0;
}

static int vtx_i2s_set_dai_pll(struct snd_soc_dai *dai,
	int pll_id, int source,
	unsigned int freq_in,
	unsigned int freq_out)
{
	struct vtx_audio_dev *vtx_dev = snd_soc_dai_get_drvdata(dai);
	struct clk *clk;

	DBG("pll target:%d   +++\n", freq_out);
	if (vtx_dev->clk_pll == NULL) {
		clk = devm_clk_get(vtx_dev->dev, CLK_DAI_PLL);
		vtx_dev->clk_pll = clk;
	} else
		clk = vtx_dev->clk_pll;
	if (IS_ERR(clk)) {
		vtx_dev->clk_pll = NULL;
		ERR("[I2S] Failed to get [" CLK_DAI_PLL "] clk\n");
		return PTR_ERR(clk);
	}
	clk_set_rate(clk, freq_out);
	return 0;
}

static int vtx_i2s_set_sysclk(struct snd_soc_dai *dai, int clk_id,
	unsigned int freq, int dir)
{
	//struct davinci_audio_dev *dev = snd_soc_dai_get_drvdata(dai);
	DBG("+++\n");
	/*DO NOTHING for current design, leave this for template*/
	return 0;
}

static int vtx_i2s_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params, struct snd_soc_dai *cpu_dai)
{
	struct vtx_audio_dev *drv_data = snd_soc_dai_get_drvdata(cpu_dai);
	snd_pcm_format_t format = params_format(params);
	unsigned int ch = params_channels(params);
	unsigned int depth;

	DBG("+++\n");

	switch (format) {
	case SNDRV_PCM_FORMAT_S16_LE:
		if (ch == 2)
			depth = I2S_DEPTH_16BIT;
		else
			depth = I2S_DEPTH_32BIT;
		break;
	case SNDRV_PCM_FORMAT_S32_LE:
			depth = I2S_DEPTH_32BIT;
		break;
	default:
		depth = I2S_DEPTH_16BIT;
		break;
	}

	VTX_VPL_SSP_WRITEL(drv_data->i2s_tx_base, I2S_TCR, depth);
	VTX_VPL_SSP_WRITEL(drv_data->i2s_rx_base, I2S_RCR, depth);
	DBG("i2s depth:%d\n", depth == I2S_DEPTH_16BIT ? 16 : 32);
	return 0;
}

static void vtx_i2s_enable_device(struct vtx_audio_dev *drv_data,
	int enable, int stream_id)
{
	void __iomem *mmr_base;

	DBG("%s\n", (enable) ? "On" : "Off");
	/* same configuration for Tx and Rx !! */
#ifdef __TDM_MODE_IN_DSP__
	/* TDM mode */
	if (stream_id == SNDRV_PCM_STREAM_PLAYBACK) {
		mmr_base = drv_data->i2s_tx_base;
		if (enable) {
			VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER,
				(0x1 | (PAR_TDM_MODE << 1) | (PAR_TDM_FRAME_OFFSET << 5) |
				(PAR_TDM_SLOT_NUMBER << 8)));
		} else
			VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER, 0x0);
	} else {
		mmr_base = drv_data->i2s_rx_base;
		if (enable) {
			VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER,
				(0x1 | (PAR_TDM_MODE << 1) | (PAR_TDM_FRAME_OFFSET << 5) |
				(PAR_TDM_SLOT_NUMBER << 8)));
		} else
			VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER, 0x0);
	}
#else
	/* I2S mode */
	if (stream_id == SNDRV_PCM_STREAM_PLAYBACK) {
		mmr_base = drv_data->i2s_tx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER,
			(enable) ? 0x1 : 0x0);
	} else {
		mmr_base = drv_data->i2s_rx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IER,
			(enable) ? 0x1 : 0x0);
	}
#endif

}

static void vtx_i2s_enable_stream(struct vtx_audio_dev *drv_data,
	int enable, int stream_id)
{
//	#define _FOLLOW_PROGRAMMING_GUIDE_
	void __iomem *mmr_base;

	DBG("%s\n", (enable) ? "On" : "Off");

#ifdef __TDM_MODE_IN_DSP__
	/* TDM mode */
	if (stream_id == SNDRV_PCM_STREAM_PLAYBACK) {
		mmr_base = drv_data->i2s_tx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_TER,
			(enable) ? (0x1 | PAR_TDM_SLOT_EBABLE) : 0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_DMACR,
			(enable) ? 0x20000 : 0x0); // [17] DMAEN_TXBLOCK
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_ITER,
			(enable) ? 0x1 : 0x0);
	} else {
		mmr_base = drv_data->i2s_rx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_RER,
			(enable) ? (0x1 | PAR_TDM_SLOT_EBABLE) : 0x0);
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_DMACR,
			(enable) ? 0x10000 : 0x0); // [16] DMAEN_RXBLOCK
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IRER,
			(enable) ? 0x1 : 0x0);
	}
#else
	/* I2S mode */
	if (stream_id == SNDRV_PCM_STREAM_PLAYBACK) {
		mmr_base = drv_data->i2s_tx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_ITER,
			(enable) ? 0x1 : 0x0);
		/* Combined DMA Handshake Interface Mode */
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_DMACR,
#ifdef _FOLLOW_PROGRAMMING_GUIDE_
			(enable) ? 0x100 : 0x0); // [8] DMAEN_TXCH_0
#else
			(enable) ? 0x20000 : 0x0); // [17] DMAEN_TXBLOCK
#endif
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_TER,
			(enable) ? 0x1 : 0x0);
	} else {
		mmr_base = drv_data->i2s_rx_base;
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_IRER,
			(enable) ? 0x1 : 0x0);
		/* Combined DMA Handshake Interface Mode */
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_DMACR,
#ifdef _FOLLOW_PROGRAMMING_GUIDE_
			(enable) ? 0x1 : 0x0); // [0] DMAEN_RXCH_0
#else
			(enable) ? 0x10000 : 0x0); // [16] DMAEN_RXBLOCK
#endif
		VTX_VPL_SSP_WRITEL(mmr_base, I2S_RER,
			(enable) ? 0x1 : 0x0);
	}
#endif

}

static int vtx_i2s_trigger(struct snd_pcm_substream *substream,
	int cmd, struct snd_soc_dai *cpu_dai)
{
	struct vtx_runtime_data *rt_data = substream->runtime->private_data;
	struct vtx_audio_dev *drv_data = snd_soc_dai_get_drvdata(cpu_dai);
	int ret = 0;

	DBG("+++\n");
	spin_lock(&rt_data->lock);

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		vtx_i2s_enable_device(drv_data, 1, substream->stream);
		vtx_i2s_enable_stream(drv_data, 1, substream->stream);
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
			_dump_mmr_i2s(drv_data, 1); // tx
		else
			_dump_mmr_i2s(drv_data, 0); // rx
		break;

	case SNDRV_PCM_TRIGGER_STOP:
		vtx_i2s_enable_stream(drv_data, 0, substream->stream);
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
			_dump_mmr_i2s(drv_data, 1); // tx
		else
			_dump_mmr_i2s(drv_data, 0); // rx
		break;
	default:
		ret = -EINVAL;
		break;
	}

	spin_unlock(&rt_data->lock);
	DBG("---\n");
	return 0;
}

static const struct snd_soc_dai_ops vtx_i2s_dai_ops = {
	.startup    = vtx_i2s_startup,
	.trigger    = vtx_i2s_trigger,
	.hw_params  = vtx_i2s_hw_params,
	.set_fmt    = vtx_i2s_set_dai_fmt,
	.set_clkdiv = vtx_i2s_set_dai_clkdiv,
	.set_sysclk = vtx_i2s_set_sysclk,
	.set_pll    = vtx_i2s_set_dai_pll,
};

/* -------------------------------------------------------------------------- */

static struct snd_soc_dai_driver vtx_i2s_dai[] = {
	{
		/* I2S Tx */
		.playback = {
			.channels_min = 2,
			.channels_max = 2,
			.rates = VTX_I2S_RATES,
			.formats = SNDRV_PCM_FMTBIT_S16_LE |
				   SNDRV_PCM_FMTBIT_S32_LE,
		},
		/* I2S Rx */
		.capture = {
			.channels_min = 2,
			.channels_max = 4,
			.rates = VTX_I2S_RATES,
			.formats = SNDRV_PCM_FMTBIT_S16_LE |
				   SNDRV_PCM_FMTBIT_S32_LE,
		},
		/* Operations */
		.ops     = &vtx_i2s_dai_ops,
	},
};

static const struct snd_soc_component_driver vtx_i2s_component = {
	.name		= "vtx-i2s",
	.legacy_dai_naming = 1,
};

static const struct of_device_id vtx_i2s_dt_ids[] = {
	{
		.compatible = "snps,designware-i2s", // DTS name
//		.compatible = "vtx,vpl-audio-i2s",
	},
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, vtx_i2s_dt_ids);

/*
 * I2S clock setting including PAD setting
 */
static int _enable_i2s_clks(struct vtx_audio_dev *vtx_dev)
{
	unsigned int reg_val;

	/*
	 * Clock enable control
	 */
	DBG("ori I2S CTRL 0x%x\n", VPL_SYSC_READL(SYSC_I2SSC_CONTROL));
#ifdef __I2S_TX_MODULE__
	DBG("ori I2S Tx CTRL 0 0x%x\n", VPL_SYSC_READL(SYSC_I2SSC_TX_CONTROL_0));
	DBG("ori I2S Tx CTRL 1 0x%x\n", VPL_SYSC_READL(SYSC_I2SSC_TX_CONTROL_1));
#endif
#ifdef __I2S_RX_MODULE__
	DBG("ori I2S Rx CTRL 0 0x%x\n", VPL_SYSC_READL(SYSC_I2SSC_RX_CONTROL_0));
	DBG("ori I2S Rx CTRL 1 0x%x\n", VPL_SYSC_READL(SYSC_I2SSC_RX_CONTROL_1));
#endif

	/* VPL I2S */
	reg_val = (PARAM_I2S_MCLK_DIV << SYSC_I2S_DIV_MCLK_SHIFT)
		| SYSC_I2S_DIV_MCLK_SET;
	VPL_SYSC_WRITEL(SYSC_I2SSC_CONTROL, reg_val);

	/* VPL I2S - Tx */
#ifdef __I2S_TX_MODULE__
		/* BCLK */
	reg_val = 0;
  #if (CFG_I2S_MASTER_MODE == 0) // ADCDCC as bus master
	reg_val |= SYSC_I2S_INT_DAC_ENABLE;
	reg_val |= SYSC_I2S_CLK_SRC_INT;
  #elif (CFG_I2S_MASTER_MODE == 1) // I2SSC as bus master
	reg_val |= SYSC_I2S_MASTER_ENABLE;
	reg_val |= SYSC_I2S_CLK_SRC_INT_DIV;
  #else // External Codec as bus master
	reg_val |= SYSC_I2S_CLK_SRC_EXT;
  #endif

	reg_val |= (PARAM_I2S_BCLK_DIV << SYSC_I2S_DIV_SCLK_SHIFT)
		| SYSC_I2S_DIV_SCLK_SET;
	VPL_SYSC_WRITEL(SYSC_I2SSC_TX_CONTROL_0, reg_val);
		/* WS */
	reg_val = (PARAM_I2S_WS_DIV << SYSC_I2S_DIV_WS_SHIFT)
		| SYSC_I2S_DIV_WS_SET;
	VPL_SYSC_WRITEL(SYSC_I2SSC_TX_CONTROL_1, reg_val);
#endif

	/* VPL I2S - Rx */
#ifdef __I2S_RX_MODULE__
		/* BCLK */
	reg_val = 0;
  #if (CFG_I2S_MASTER_MODE == 0) // ADCDCC as bus master
	  reg_val |= SYSC_I2S_INT_ADC_ENABLE;
	  reg_val |= SYSC_I2S_CLK_SRC_INT;
  #elif (CFG_I2S_MASTER_MODE == 1) // I2SSC as bus master
	  reg_val |= SYSC_I2S_MASTER_ENABLE;
	  reg_val |= SYSC_I2S_CLK_SRC_INT_DIV;
  #else // External Codec as bus master
	  reg_val |= SYSC_I2S_CLK_SRC_EXT;
  #endif

	reg_val |= (PARAM_I2S_BCLK_DIV << SYSC_I2S_DIV_SCLK_SHIFT)
		| SYSC_I2S_DIV_SCLK_SET;
	VPL_SYSC_WRITEL(SYSC_I2SSC_RX_CONTROL_0, reg_val);
		/* WS */
	reg_val = (PARAM_I2S_WS_DIV << SYSC_I2S_DIV_WS_SHIFT)
		| SYSC_I2S_DIV_WS_SET;
	VPL_SYSC_WRITEL(SYSC_I2SSC_RX_CONTROL_1, reg_val);
#endif

	reg_val = VPL_SYSC_READL(SYSC_I2SSC_CONTROL);
	DBG("new I2S CTRL 0x%x -> set MCLK div: %s\n",
		reg_val, (reg_val & SYSC_I2S_DIV_MCLK_SET) ? "NG" : "OK");
#ifdef __I2S_TX_MODULE__
	/* Tx */
	reg_val = VPL_SYSC_READL(SYSC_I2SSC_TX_CONTROL_0);
	DBG("new I2S Tx CTRL 0 0x%x -> set SCLK div: %s\n",
		reg_val, (reg_val & SYSC_I2S_DIV_SCLK_SET) ? "NG" : "OK");
	reg_val = VPL_SYSC_READL(SYSC_I2SSC_TX_CONTROL_1);
	DBG("new I2S Tx CTRL 0 0x%x -> set WS div: %s\n",
		reg_val, (reg_val & SYSC_I2S_DIV_WS_SET) ? "NG" : "OK");
#endif
#ifdef __I2S_RX_MODULE__
	/* Rx */
	reg_val = VPL_SYSC_READL(SYSC_I2SSC_RX_CONTROL_0);
	DBG("new I2S Rx CTRL 0 0x%x -> set SCLK div: %s\n",
		reg_val, (reg_val & SYSC_I2S_DIV_SCLK_SET) ? "NG" : "OK");
	reg_val = VPL_SYSC_READL(SYSC_I2SSC_RX_CONTROL_1);
	DBG("new I2S Rx CTRL 0 0x%x -> set WS div: %s\n",
		reg_val, (reg_val & SYSC_I2S_DIV_WS_SET) ? "NG" : "OK");
#endif

	/*
	 * Check if turned on!
	 */
	DBG("new Clk enable status 0x%x ([23:21] Tx SCLK, RX SCLK, APB CLK)\n",
		VPL_SYSC_READL(SYSC_CLK_EN_STATUS));

	return 0;
}

static int _disable_i2s_clks(struct vtx_audio_dev *vtx_dev)
{
	unsigned int reg_val;

	DBG("+++\n");
	/*
	 * Clock disable control
	 */
	/* VPL I2S - Tx */
	reg_val = VPL_SYSC_READL(SYSC_I2SSC_TX_CONTROL_0);
	reg_val &= ~SYSC_I2S_INT_DAC_ENABLE; // check...
	VPL_SYSC_WRITEL(SYSC_I2SSC_TX_CONTROL_0, reg_val);

	/* VPL I2S - Rx */
	reg_val = VPL_SYSC_READL(SYSC_I2SSC_RX_CONTROL_0);
	reg_val &= ~SYSC_I2S_INT_DAC_ENABLE; // check...
	VPL_SYSC_WRITEL(SYSC_I2SSC_RX_CONTROL_0, reg_val);

	DBG("Clk enable status 0x%x ([23:21] Tx SCLK, RX SCLK, APB CLK)\n",
		SYSC_CLK_EN_STATUS);

	return 0;
}

/* ---------------------------------------------------------------------------*/
#ifdef tag_entry
#endif

static int _probe_pcm(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct vtx_audio_dev *vtx_dev;
	int ret;

	DBG("Virtual Platform Device for PCM!\n");

	vtx_dev = vtx_i2s_drvdata;
	if (!vtx_dev) {
		ERR("allocate Platform Device [%s] driver data failed!\n",
			pdev->name);
		return -ENOMEM;
	}
	platform_set_drvdata(pdev, vtx_dev);

	ret = vtx_soc_platform_register(dev);
	if (ret != 0)
		goto err_platform_register_pcm;

	ret = snd_soc_register_component(dev, &vtx_i2s_component,
		&vtx_i2s_dai[0], 1);
	if (ret != 0)
		goto err_register_component;

	return 0;

err_register_component:
	vtx_soc_platform_unregister(dev);

err_platform_register_pcm:

	return ret;
}

static int vtx_i2s_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct vtx_audio_dev *vtx_dev;
	int ret;
	unsigned int i, hw_version;
	struct resource *res;
	struct clk *clk;
	const char *clk_name;
	const char *clk_name_list[5] = { CLK_I2S_MCLK,
		CLK_I2S_RX_SCLK, CLK_I2S_RX_WS, /* Rx */
		CLK_I2S_TX_SCLK, CLK_I2S_TX_WS, /* tx */
	};
	struct clk *clk_list[5];

	DBG("\n");
	MSG("Platform Device [%s]\n");

	if (strcmp(pdev->name, VPL_PLATFORM) == 0)
		return _probe_pcm(pdev);

	vtx_dev = devm_kzalloc(dev, sizeof(struct vtx_audio_dev),
			   GFP_KERNEL);
	if (!vtx_dev) {
		ERR("allocate private driver data failed!\n");
		ret = -ENOMEM;
		goto err_malloc_driver_data;
	}

	/*
	 * Device Tree info
	 */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res) {
		vtx_dev->virq_rx_num = platform_get_irq_byname(pdev, "i2s_rx_irq");
		if (vtx_dev->virq_rx_num < 0)
			ERR("no Rx IRQ resource specified!\n");

		vtx_dev->virq_tx_num = platform_get_irq_byname(pdev, "i2s_tx_irq");
		if (vtx_dev->virq_tx_num < 0)
			ERR("no Tx IRQ resource specified!\n");

		MSG("I2S base_addr 0x%x, virtual IRQ Rx %u, Tx %u\n",
			(unsigned int)res->start, vtx_dev->virq_rx_num, vtx_dev->virq_tx_num);
	} else
		ERR("platform_get_resource failed!\n");

	/* Clocks Acquisition */
	clk_list[0] = vtx_dev->clk_i2s_mclk;
	clk_list[1] = vtx_dev->clk_i2s_rx_sclk;
	clk_list[2] = vtx_dev->clk_i2s_rx_ws;
	clk_list[3] = vtx_dev->clk_i2s_tx_sclk;
	clk_list[4] = vtx_dev->clk_i2s_tx_ws;

	for (i = 0; i < 5; i++) {
		clk_name = clk_name_list[i];
		clk = devm_clk_get(dev, clk_name);
		if (IS_ERR(clk)) {
			ERR("Failed to get '%s' clock!\n", clk_name);
			ret = PTR_ERR(clk);
			goto err_get_i2s_clks;
		}
		clk_list[i] = clk;
	}

	/*
	 * System Controller MMR region mapping
	 */
	request_mem_region(SYSC_BASE, 0x100, "SYSC");
	vtx_dev->sysc_base = ioremap(SYSC_BASE, 0x400); // MMR number = 148
	if (IS_ERR(vtx_dev->sysc_base)) {
		ERR("get SYSC ioremap resource failed!\n");
		ret = PTR_ERR(vtx_dev->sysc_base);
		goto err_iomap_sysc;
	}

	/*
	 * I2S MMR region mapping
	 */
	request_mem_region(VPL_I2SSC_TX_MMR_BASE, VPL_I2SSC_MMR_SIZE, "I2S_TX");
	vtx_dev->i2s_tx_base = ioremap(VPL_I2SSC_TX_MMR_BASE, VPL_I2SSC_MMR_SIZE);
	if (IS_ERR(vtx_dev->i2s_tx_base)) {
		ERR("get I2S_TX ioremap resource failed!\n");
		ret = PTR_ERR(vtx_dev->i2s_tx_base);
		goto err_iomap_i2s_tx;
	}
	request_mem_region(VPL_I2SSC_RX_MMR_BASE, VPL_I2SSC_MMR_SIZE, "I2S_RX");
	vtx_dev->i2s_rx_base = ioremap(VPL_I2SSC_RX_MMR_BASE, VPL_I2SSC_MMR_SIZE);
	if (IS_ERR(vtx_dev->i2s_rx_base)) {
		ERR("get I2S_RX ioremap resource failed!\n");
		ret = PTR_ERR(vtx_dev->i2s_rx_base);
		goto err_iomap_i2s_rx;
	}

	DBG("I2S Reset Status 0x%x\n", VPL_SYSC_READL(SYSC_RESET_STATUS));
	DBG(" ([23] Tx SCLK [22] Rx SCLK [21] APB CLK)\n");

	/*
	 * assign Device Driver private data
	 */
	vtx_dev->dev = dev;
	platform_set_drvdata(pdev, vtx_dev);

	/*
	 * Clock enable
	 */
	ret = _enable_i2s_clks(vtx_dev);
	if (ret != 0)
		goto err_enable_i2s_clks;

	/*
	 * Register component
	 */
	DBG("\n");
	ret = snd_soc_register_component(dev, &vtx_i2s_component,
					 &vtx_i2s_dai[0], 1);
	if (ret != 0) {
		ERR("register Component failed!\n");
		goto err_register_component;
	}

	/*
	 * Display version information
	 */
#ifdef __I2S_TX_MODULE__
	hw_version = VTX_VPL_SSP_READL(vtx_dev->i2s_tx_base, I2S_COMP_VERSION);

#define DRV_TX "Install VPL_IIS Tx device driver version "
#define HW_TX  " on Tx hardware version "

	dev_info(dev, DRV_TX "%d.%d.%d.%d" HW_TX "%c.%c%c%c complete !!\n",
		(int)((VPL_IIS_VERSION >>  0) & 0xFF),
		(int)((VPL_IIS_VERSION >>  8) & 0xFF),
		(int)((VPL_IIS_VERSION >> 16) & 0xFF),
		(int)((VPL_IIS_VERSION >> 24) & 0xFF),
		(unsigned char)((int)(hw_version >> 24) & 0xFF),
		(unsigned char)((int)(hw_version >> 16) & 0xFF),
		(unsigned char)((int)(hw_version >>  8) & 0xFF),
		(unsigned char)((int)(hw_version >>  0) & 0xFF));
#endif
#ifdef __I2S_RX_MODULE__
	hw_version = VTX_VPL_SSP_READL(vtx_dev->i2s_rx_base, I2S_COMP_VERSION);

#define DRV_RX "Install VPL_IIS Rx device driver version "
#define HW_RX  " on Rx hardware version "

	dev_info(dev, DRV_RX "%d.%d.%d.%d" HW_RX "%c.%c%c%c complete !!\n",
		(int)((VPL_IIS_VERSION >>  0) & 0xFF),
		(int)((VPL_IIS_VERSION >>  8) & 0xFF),
		(int)((VPL_IIS_VERSION >> 16) & 0xFF),
		(int)((VPL_IIS_VERSION >> 24) & 0xFF),
		(unsigned char)((int)(hw_version >> 24) & 0xFF),
		(unsigned char)((int)(hw_version >> 16) & 0xFF),
		(unsigned char)((int)(hw_version >>  8) & 0xFF),
		(unsigned char)((int)(hw_version >>  0) & 0xFF));
#endif

	vtx_i2s_drvdata = vtx_dev; // for PCM driver reference
	return 0;

err_register_component:
	_disable_i2s_clks(vtx_dev);
err_enable_i2s_clks:
	iounmap(vtx_dev->i2s_rx_base);
	release_mem_region(VPL_I2SSC_RX_MMR_BASE, VPL_I2SSC_MMR_SIZE);
err_iomap_i2s_rx:
	iounmap(vtx_dev->i2s_tx_base);
	release_mem_region(VPL_I2SSC_TX_MMR_BASE, VPL_I2SSC_MMR_SIZE);
err_iomap_i2s_tx:
	iounmap(vtx_dev->sysc_base);
	release_mem_region(SYSC_BASE, 0x400);
err_iomap_sysc:
err_get_i2s_clks:
	devm_kfree(dev, vtx_dev);
err_malloc_driver_data:
	return ret;
}

static int vtx_i2s_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct vtx_audio_dev *vtx_dev;

	vtx_dev = platform_get_drvdata(pdev);
	return _disable_i2s_clks(vtx_dev);
}

static int vtx_i2s_resume(struct platform_device *pdev)
{
	struct vtx_audio_dev *vtx_dev;

	vtx_dev = platform_get_drvdata(pdev);
	return _enable_i2s_clks(vtx_dev);
}

static int vtx_i2s_remove(struct platform_device *pdev)
{
	struct vtx_audio_dev *vtx_dev;
	struct clk *clk;

	DBG("+++\n");
	vtx_dev = platform_get_drvdata(pdev);

	/*
	 * I2S Bus Clock
	 */
	/* MCLK */
	clk = vtx_dev->clk_i2s_mclk;
	if (!IS_ERR(clk))
		devm_clk_put(vtx_dev->dev, clk);
	vtx_dev->clk_i2s_mclk = NULL;

	/* Tx BCLK/SCLK */
	clk = vtx_dev->clk_i2s_tx_sclk;
	if (!IS_ERR(clk))
		devm_clk_put(vtx_dev->dev, clk);
	vtx_dev->clk_i2s_tx_sclk = NULL;
	/* Tx WS */
	clk = vtx_dev->clk_i2s_tx_ws;
	if (!IS_ERR(clk))
		devm_clk_put(vtx_dev->dev, clk);
	vtx_dev->clk_i2s_tx_ws = NULL;

	/* Rx BCLK/SCLK */
	clk = vtx_dev->clk_i2s_rx_sclk;
	if (!IS_ERR(clk))
		devm_clk_put(vtx_dev->dev, clk);
	vtx_dev->clk_i2s_rx_sclk = NULL;
	/* Rx WS */
	clk = vtx_dev->clk_i2s_rx_ws;
	if (!IS_ERR(clk))
		devm_clk_put(vtx_dev->dev, clk);
	vtx_dev->clk_i2s_rx_ws = NULL;

	/* PLL Clock */
	clk = vtx_dev->clk_pll;
	if (!IS_ERR(clk))
		devm_clk_put(vtx_dev->dev, clk);
	vtx_dev->clk_pll = NULL;

	/*
	 * release I/O mapped MMR region
	 */
	iounmap(vtx_dev->i2s_rx_base);
	release_mem_region(VPL_I2SSC_RX_MMR_BASE, VPL_I2SSC_MMR_SIZE);

	iounmap(vtx_dev->i2s_tx_base);
	release_mem_region(VPL_I2SSC_TX_MMR_BASE, VPL_I2SSC_MMR_SIZE);

	iounmap(vtx_dev->sysc_base);
	release_mem_region(SYSC_BASE, 0x400);

	devm_kfree(&pdev->dev, vtx_dev);

	return 0;
}

static struct platform_driver vtx_i2s_driver = {
	.probe		= vtx_i2s_probe,
	.remove		= vtx_i2s_remove,
	.suspend        = vtx_i2s_suspend,
	.resume         = vtx_i2s_resume,
	.driver		= {
		.name	= VPL_PLATFORM,
		.owner	= THIS_MODULE,
		.of_match_table = of_match_ptr(vtx_i2s_dt_ids),
	},
};

/* -------------------------------------------------------------------------- */

// can't use "module_platform_driver()" if having extra action
static int __init vtx_i2s_init(void)
{

	MSG("+++\n");
	/* I2S driver */
	platform_driver_register(&vtx_i2s_driver);
	MSG("===\n");
	/* PCM driver for virtual platform device -> run probe again! */
	// It's a one-step call to allocate and register a device.
	platform_device_register_simple(VPL_PLATFORM, -1, NULL, 0);
	MSG("---\n");
	return 0;
}

static void __exit vtx_i2s_exit(void)
{
	MSG("\n");
	platform_driver_unregister(&vtx_i2s_driver);
}

module_init(vtx_i2s_init);
module_exit(vtx_i2s_exit);

/* ========================================================================== */

MODULE_DESCRIPTION("VTX I2S Platform Driver");
MODULE_AUTHOR("Kneron Ltd.");
MODULE_LICENSE("GPL");


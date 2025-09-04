/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _VTX_ASOC_H_
#define _VTX_ASOC_H_

#include <linux/completion.h>
#include <linux/irqreturn.h>

/* ========================================================================== */
/* Compile Option */

/* master switch for debug messages */
#define OPT_DEBUG

/*
 * TDM mode with DSP protocol
 * - I2S IP only support this protocol
 * - only be in Slave mode due to unable to generate SCLK,WS timing for DSP
 */
#if defined(CONFIG_SND_CODEC_AIC32X4)
#define __TDM_MODE_IN_DSP__
//#define __CODEC_AIC32X4_SINGLE__
#endif
// I2S_IER
#define PAR_TDM_MODE  1 // 0: I2S mode
#define PAR_TDM_FRAME_OFFSET  0
#define PAR_TDM_SLOT_NUMBER   (4 - 1)// 4 slots in a TDM frame
// I2S_TER / I2S_RER
#define PAR_TDM_SLOT_EBABLE   (0xf << 8)

/*
 * I2S master mode: // fixme... use DT later
 *  =0  ADCDCC as master
 *  =1  I2SSC as master
 * >=2  External codec as master
 */
#define CFG_I2S_MASTER_MODE  0

#define __I2S_TX_MODULE__
#define __I2S_RX_MODULE__

#ifdef CONFIG_VTX_FPGA_AUDIO
#define PARAM_I2S_MCLK_DIV  1  /* FPGA: 49.123 MHz / 2 * (1 + 1) ~= 12.288 MHz */
#define PARAM_I2S_BCLK_DIV  46 /* FPGA: 49.123 MHz / 2 * (46 + 1) ~= 512 KHz */
#define PARAM_I2S_WS_DIV    31 /* FPGA: BCLK / 2 * (31 + 1) ~= 8 KHz, 1/64 */
#else
#define PARAM_I2S_MCLK_DIV  1  /* chip: 49.152 MHz / 2 * (1 + 1)  = 12.288 MHz */
#define PARAM_I2S_BCLK_DIV  47 /* chip: 49.152 MHz / 2 * (47 + 1) = 3.072 MHz */
#define PARAM_I2S_WS_DIV    31 /* chip: BCLK / 2 * (31 + 1) = 48 KHz, 1/64 */
#endif

/*
 * PCM / PDMA
 */
// type = 1: cyclic ring / 2: ring (default)
#define DESC_TYPE_CYCLIC  1
#define DESC_TYPE_RING    2

#define __PDMA_DESC_TYPE__  DESC_TYPE_CYCLIC

/*
 * TI AIC32X4 solution
 */
#define PAR_I2S_MCLK_RATE  12288000 // 12.288 MHz
#define PAR_SCLK_OFFSET    (2 * 32) // TWO slots * 32-bit Data Length

#define PAR_CODEC_DAI_FORMAT \
	(SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM)
//	(SND_SOC_DAIFMT_DSP_B | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM)

// decide which one of TI codec as I2S bus Master
#define PAR_I2S_MASTER_CLIENT_ID  0 // 0 or 2

/* ========================================================================== */

/*! Make from four character codes to one 32-bits DWORD */
#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3) \
	((unsigned int)(unsigned char)(ch0) | \
	((unsigned int)(unsigned char)(ch1) << 8) | \
	((unsigned int)(unsigned char)(ch2) << 16) | \
	((unsigned int)(unsigned char)(ch3) << 24))
#endif //defined(MAKEFOURCC)

#ifndef MAKEVERSTR
#undef _makeverstr
#define _makeverstr(major, minor, build, revision) \
	{ #major"."#minor"."#build"."#revision }
#define MAKEVERSTR(major, minor, build, revision) \
	_makeverstr(major, minor, build, revision)
#endif

/* ---------------------------------------------------------------------------*/
/*
 * Message API
 *   OPT_DEBUG: master switch
 *   OPT_DEBUG_LOCAL: local switch determined by each .c
 */

#if defined(OPT_DEBUG) && defined(OPT_DEBUG_LOCAL)
#define MSG(fmt, args...) \
	pr_info("[ASoC] %s: " fmt, __func__, ##args)
/* pr_debug: (1) CONFIG_DYNAMIC_DEBUG=y (2) # mount debugfs (3) # echo $file */
#define DBG(fmt, args...) \
	pr_debug("[ASoC] %s: %04d: " fmt, __func__, __LINE__, ##args)
#define DDBG(dev, fmt, args...) \
	dev_info(dev, "[ASoC] %s: %04d: " fmt, __func__, __LINE__, ##args)
#else
#define MSG(fmt, args...)
#define DBG(fmt, args...)
#define DDBG(dev, fmt, args...)
#endif

#define WRN(fmt, args...) \
	pr_warn("[ASoC] alert! %s: " fmt, __func__, ##args)
#define DWRN(dev, fmt, args...) \
	dev_warn(dev, "[ASoC] alert! %s: " fmt, __func__, ##args)

#define ERR(fmt, args...) \
	pr_err("[ASoC] error! %s: " fmt, __func__, ##args)
#define DERR(dev, fmt, args...) \
	dev_err(dev, "[ASoC] error! %s: " fmt, __func__, ##args)

/* -------------------------------------------------------------------------- */

#define VPL_PLATFORM "vtx-pcm"

/* -------------------------------------------------------------------------- */
/*
 * [ SYSC ]
 */
#define SYSC_BASE      0xCEF00000 // VPL_SYSC_MMR_BASE
#define SYSC_MMR_BASE  SYSC_BASE
#define SYSC_MMR_SIZE  0x400

#define SYSC_I2SSC_CONTROL_0			0x64
#define SYSC_I2SSC_CONTROL_1			0x68
#define SYSC_I2SSC_BCLK_SRC_SELECT_OFFSET         16

/* Interrupt status register */
#define SYSC_INT_STATUS  0x2C // ro_11
/* Interrupt mask register */
#define SYSC_INT_MASK_STATUS  0x30 // ro_12
/* Reset release status register 0 */
#define SYSC_RESET_STATUS  0x34 // ro_13
/* Clock enable status register 1 */
#define SYSC_CLK_EN_STATUS  0x4C // ro_19

/*
 * pinmux:
 * Tx: (MAIN) Master | (0) Slave | (4) GPIO 2 [7][8][9]    | (5) AGPO [7][8][9]
 * Rx: (MAIN) Master | (0) Slave | (4) GPIO 2 [10][11][12] | (5) AGPO [10][11]
 * (Option 1) VQ7U (Option 2) ADC DCC
 */
/* Pad enable control status register 2 */
#define SYSC_PAD2_EN_STATUS  0x80 // ro_032
/* Pad enable control status register 2 set control (auto-clear). */
#define SYSC_PAD2_SET_CTRL  0x1F0 // wo_124
/* Pad enable control status register 2 clear control (auto-clear). */
#define SYSC_PAD2_CLR_CTRL  0x1F4 // wo_125

#define SYSC_PAD2_MUX_I2S_TX  0x380
#define SYSC_PAD2_MUX_I2S_RX  0x1C00

/* Pad enable control status register 6 */
#define SYSC_PAD6_EN_STATUS  0x90 // ro_036
/* Pad enable control status register 6 set control (auto-clear). */
#define SYSC_PAD6_SET_CTRL  0x210 // wo_132
/* Pad enable control status register 6 clear control (auto-clear). */
#define SYSC_PAD6_CLR_CTRL  0x214 // wo_133

#define SYSC_PAD6_I2S_MCLK  0x10000
#define SYSC_PAD6_I2S_RX_M  0x20000 // Master
#define SYSC_PAD6_I2S_RX_S  0x40000 // Slave
#define SYSC_PAD6_I2S_TX_M  0x80000 // Master
#define SYSC_PAD6_I2S_TX_S  0x100000 // Slave
#define SYSC_PAD6_ADCD_PDM  0x1L // internal codec PDM enable

/* ADCDCC control register */
#define SYSC_ADCDCC_CONTROL  0x9C // rw_039

#define SYSC_ADCDCC_DIV_RX_MCLK_SET    0x1L
#define SYSC_ADCDCC_DIV_RX_MCLK_SHIFT  4
#define SYSC_ADCDCC_DIV_TX_MCLK_SET    0x10000L
#define SYSC_ADCDCC_DIV_TX_MCLK_SHIFT  20

/* I2SSC control register */
#define SYSC_I2SSC_CONTROL  0xA8 // rw_042
/* I2SSC Rx control register 0 */
#define SYSC_I2SSC_RX_CONTROL_0  0xAC // rw_043
/* I2SSC Rx control register 1 */
#define SYSC_I2SSC_RX_CONTROL_1  0xB0 // rw_044
/* I2SSC Tx control register 0 */
#define SYSC_I2SSC_TX_CONTROL_0  0xB4 // rw_045
/* I2SSC Tx control register 1 */
#define SYSC_I2SSC_TX_CONTROL_1  0xB8 // rw_046

	/* _CONTROL */
#define SYSC_I2S_DIV_MCLK_SET    0x1
#define SYSC_I2S_DIV_MCLK_SHIFT  4

	/*
	 * _CONTROL_0
	 */
/* bit [00] */
#define SYSC_I2S_INT_DAC_ENABLE  0x01
#define SYSC_I2S_INT_ADC_ENABLE  0x01
/* bit [04] */
#define SYSC_I2S_MASTER_ENABLE   0x10
/* bit [09:08] */
#define SYSC_I2S_CLK_SRC_INT      0x000
#define SYSC_I2S_CLK_SRC_EXT      0x100
#define SYSC_I2S_CLK_SRC_INT_DIV  0x200
/* bit [12] */
#define SYSC_I2S_DIV_SCLK_SET    0x1000
/* bit [28:16] */
#define SYSC_I2S_DIV_SCLK_SHIFT  16

	/* _CONTROL_1 */
/* bit [00] */
#define SYSC_I2S_DIV_WS_SET    0x1
/* bit [11:04] */
#define SYSC_I2S_DIV_WS_SHIFT  4

/* -------------------------------------------------------------------------- */

/* I2S driver use */
#define VPL_SYSC_READL(reg)        readl(vtx_dev->sysc_base + reg)
#define VPL_SYSC_WRITEL(reg, val)  writel(val, (vtx_dev->sysc_base + reg))

#define VPL_SYSC_READ(reg)        readl(mmr_base_sysc + reg)
#define VPL_SYSC_WRITE(reg, val)  writel(val, (mmr_base_sysc + reg))

/* -------------------------------------------------------------------------- */

/*
 * S/W definition for Clock Divider ID
 */

/* I2S Tx, Rx Module */
#define VTX_BOARD_I2S_MCLK  0x01 // share the same MCLK!
#define VTX_BOARD_I2S_TX    0x02 // Tx SCLK & WS
#define VTX_BOARD_I2S_RX    0x03 // Rx SCLK & WS

/* Internal Codec Module */
#define VTX_BOARD_ADCD_TX   0x11 // Tx MCLK
#define VTX_BOARD_ADCD_RX   0x21 // Rx MCLK

/* ======================================================================== */

/* DMA parameters */
struct vtx_pcm_dma_params {
	/* DMA MMR base address (I/O remapped) */
	void __iomem *reg_base_addr;
	/* DMA framework */
	struct dma_chan *channel;
	u32 burst_len;
	u32 sg_burst;
	/* others */
//	irqreturn_t (*transfer_handler)(void *irq_data); // I2S ISR, not used yet!
	u32 hw_info[6];
};

/* driver data from Device Tree */
struct vtx_audio_dev {
	struct device *dev; // I2S device
	/* MMR base address (I/O remapped) */
	void __iomem *sysc_base;
	void __iomem *pdma_base;
	void __iomem *i2s_tx_base;
	void __iomem *i2s_rx_base;
	/* Virtual IRQ number */
	unsigned int virq_rx_num;
	unsigned int virq_tx_num;
	/* cache for clock object pointer */
		/* I2S clock */
	struct clk *clk_i2s_mclk;
	struct clk *clk_i2s_tx_sclk;
	struct clk *clk_i2s_tx_ws;
	struct clk *clk_i2s_rx_sclk;
	struct clk *clk_i2s_rx_ws;
		/* PLL clock */
	struct clk *clk_pll;
	/* DMA info */
	struct dma_chan *txchan;
	u32 txburst;
	struct dma_chan *rxchan;
	u32 rxburst;
	u32 dma_sg_burst;
//	struct completion dma_completion;
};

struct vtx_runtime_data {
	spinlock_t lock;
	unsigned int active;
	/* DMA info */
	struct vtx_pcm_dma_params *dma_data;	/* DMA H/W relative parameter */
	unsigned int dma_width; // DMA bus access width
		/* Period info */
	unsigned int dma_period_pos; // DMA transferred position
	unsigned int dma_period_num; // DMA period number
	size_t dma_period_size; // DMA period bytes
	/* others */
	unsigned int int_cnt; // DMA interrupt counter
};

/* ========================================================================== */

#ifdef tag_I2S
#endif

/*
 * I2S Rx
 */
static inline void sysc_set_i2s_rx_ctrl(void __iomem *mmr_base_sysc,
	int i2s_bus_master)
{
	unsigned int reg_val = 0;

	/* SCLK, Internal Codec ADC */
#if (CFG_I2S_MASTER_MODE == 0) // ADCDCC as bus master
	reg_val |= SYSC_I2S_INT_ADC_ENABLE;
	reg_val |= SYSC_I2S_CLK_SRC_INT;
#elif (CFG_I2S_MASTER_MODE == 1) // I2SSC as bus master
	reg_val |= SYSC_I2S_MASTER_ENABLE;
	reg_val |= SYSC_I2S_CLK_SRC_INT_DIV;
#else // External Codec as bus master
	reg_val |= SYSC_I2S_CLK_SRC_EXT;
#endif
		/* internal divider */
	reg_val |= (PARAM_I2S_BCLK_DIV << SYSC_I2S_DIV_SCLK_SHIFT)
		| SYSC_I2S_DIV_SCLK_SET;
	VPL_SYSC_WRITE(SYSC_I2SSC_RX_CONTROL_0, reg_val);

	/* WS */
	reg_val = (PARAM_I2S_WS_DIV << SYSC_I2S_DIV_WS_SHIFT)
		| SYSC_I2S_DIV_WS_SET;
	VPL_SYSC_WRITE(SYSC_I2SSC_RX_CONTROL_1, reg_val);

}

/*
 * I2S Tx
 */
static inline void sysc_set_i2s_tx_ctrl(void __iomem *mmr_base_sysc,
	int i2s_bus_master)
{
	unsigned int reg_val = 0;

	/* SCLK, Internal Codec DAC */
#if (CFG_I2S_MASTER_MODE == 0) // ADCDCC as bus master
	reg_val |= SYSC_I2S_INT_DAC_ENABLE;
	reg_val |= SYSC_I2S_CLK_SRC_INT;
#elif (CFG_I2S_MASTER_MODE == 1) // I2SSC as bus master
	reg_val |= SYSC_I2S_MASTER_ENABLE;
	reg_val |= SYSC_I2S_CLK_SRC_INT_DIV;
#else // External Codec as bus master
	reg_val |= SYSC_I2S_CLK_SRC_EXT;
#endif
		/* internal divider */
	reg_val |= (PARAM_I2S_BCLK_DIV << SYSC_I2S_DIV_SCLK_SHIFT)
		| SYSC_I2S_DIV_SCLK_SET;
	VPL_SYSC_WRITE(SYSC_I2SSC_TX_CONTROL_0, reg_val);

	/* WS */
	reg_val = (PARAM_I2S_WS_DIV << SYSC_I2S_DIV_WS_SHIFT)
		| SYSC_I2S_DIV_WS_SET;
	VPL_SYSC_WRITE(SYSC_I2SSC_TX_CONTROL_1, reg_val);

}

/* -------------------------------------------------------------------------- */

#ifdef tag_CODEC
#endif

/*
 * ADCD Tx DAC
 */
static inline void sysc_enable_adcd_tx_dac(void __iomem *mmr_base_sysc)
{
	VPL_SYSC_WRITE(SYSC_I2SSC_TX_CONTROL_0,
		VPL_SYSC_READ(SYSC_I2SSC_TX_CONTROL_0) | SYSC_I2S_INT_DAC_ENABLE);
}

static inline void sysc_disable_adcd_tx_dac(void __iomem *mmr_base_sysc)
{
	VPL_SYSC_WRITE(SYSC_I2SSC_TX_CONTROL_0,
		VPL_SYSC_READ(SYSC_I2SSC_TX_CONTROL_0) & ~SYSC_I2S_INT_DAC_ENABLE);
}

/*
 * ADCD Rx ADC
 */
static inline void sysc_enable_adcd_rx_adc(void __iomem *mmr_base_sysc)
{
	VPL_SYSC_WRITE(SYSC_I2SSC_RX_CONTROL_0,
		VPL_SYSC_READ(SYSC_I2SSC_RX_CONTROL_0) | SYSC_I2S_INT_ADC_ENABLE);
}

static inline void sysc_disable_adcd_rx_adc(void __iomem *mmr_base_sysc)
{
	VPL_SYSC_WRITE(SYSC_I2SSC_RX_CONTROL_0,
		VPL_SYSC_READ(SYSC_I2SSC_RX_CONTROL_0) & ~SYSC_I2S_INT_ADC_ENABLE);
}

/* -------------------------------------------------------------------------- */

static inline void util_dump_mmr(const char *name, void __iomem *addr, unsigned int length)
{
#if defined(OPT_DEBUG_LOCAL) && defined(OPT_DUMP_MMR)
#define STR  "0x%08x [%03x]  "

	unsigned int *mmr_head, mmr_addr;
	unsigned int i, j;

	mmr_head = (unsigned int *)addr;
	mmr_addr = (unsigned int)((unsigned long)mmr_head);
	if (IS_ERR(addr)) {
		pr_err("[ASoC] error! [%s] MMR dump with invalid address %x (%ld)\n",
			name, mmr_addr, PTR_ERR(addr));
		return;
	}

	pr_debug("+++++ [%s] MMR dump:\n", name);
	for (i = 0; i < length; i += 4) {
		j = i * 4;
		pr_debug(STR "%08x (%03d)  %08x (%03d)  %08x (%03d)	%08x (%03d)",
			mmr_addr + j, j,
			mmr_head[i + 0], (i + 0),
			mmr_head[i + 1], (i + 1),
			mmr_head[i + 2], (i + 2),
			mmr_head[i + 3], (i + 3));
	}
	pr_debug("----- [%s] MMR dump done!\n", name);
#endif
}

/* ========================================================================== */

/* symbol export to i2s driver */
int vtx_soc_platform_register(struct device *dev);
void vtx_soc_platform_unregister(struct device *dev);

#endif /* _VTX_ASOC_H_ */


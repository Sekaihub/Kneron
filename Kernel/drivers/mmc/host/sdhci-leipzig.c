// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2024 VATICS Inc.
 */
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/delay.h>
#include <linux/mmc/mmc.h>
#include <linux/slab.h>

#include "sdhci-pltfm.h"
#define VPL_SYSC_NONSECURE_MMR_BASE     0xCEE00000
#define SYSC_CLK_EN_CLR_REG_3            0x19c
#define SYSC_CLK_EN_SET_REG_3         0x198
#define SYSC_MSHC_CTRL       0xc8
#define MSHC_CTRL_4BIT_8BIT           (1U<<31)

#define VPL_MSHC_0_MMR_BASE             0xc6100000
#define VPL_MSHC_1_MMR_BASE             0xc6200000

#define     MSHC_CTRL_4BIT_8BIT           (1U<<31)
#define     MSHC_CTRL_DIV0_OFFSET         4
#define     MSHC_CTRL_DIV0_MASK           (0x3ffU << MSHC_CTRL_DIV0_OFFSET)
#define     MSHC_CTRL_DIV0_REQ            (0x1U   << 0)
#define     MSHC_CTRL_DIV1_OFFSET         20
#define     MSHC_CTRL_DIV1_MASK           (0x3ffU << MSHC_CTRL_DIV1_OFFSET)
#define     MSHC_CTRL_DIV1_REQ            (0x1U   << 16)

#define     MSHC_DEV_0_CLK_TX       (1U<<22)
#define     MSHC_DEV_0_CLK_TM       (1U<<21)
#define     MSHC_DEV_0_CLK_CQETM    (1U<<19)
#define     MSHC_DEV_0_CLK_BASE     (1U<<18)
#define     MSHC_DEV_0_CLK_AXI      (1U<<17)
#define     MSHC_DEV_0_CLK_AHB      (1U<<16)

#define     MSHC_DEV_1_CLK_TX       (1U<<28)
#define     MSHC_DEV_1_CLK_TM       (1U<<27)
#define     MSHC_DEV_1_CLK_CQETM    (1U<<26)
#define     MSHC_DEV_1_CLK_BASE     (1U<<25)
#define     MSHC_DEV_1_CLK_AXI      (1U<<24)
#define     MSHC_DEV_1_CLK_AHB      (1U<<23)

#define         MSHC_DEV_0_CLK_MASK     (MSHC_DEV_0_CLK_TX |\
					MSHC_DEV_0_CLK_TM |\
					MSHC_DEV_0_CLK_CQETM |\
					MSHC_DEV_0_CLK_BASE |\
					MSHC_DEV_0_CLK_AXI |\
					MSHC_DEV_0_CLK_AHB)

#define         MSHC_DEV_1_CLK_MASK	(MSHC_DEV_1_CLK_TX |\
					MSHC_DEV_1_CLK_TM |\
					MSHC_DEV_1_CLK_CQETM |\
					MSHC_DEV_1_CLK_BASE |\
					MSHC_DEV_1_CLK_AXI |\
					MSHC_DEV_1_CLK_AHB)

#define PTR_PHY_REGS            0x300

#define PHY_CNFG                0x0
#define PAD_SP_OFFSET           16
#define PAD_SN_OFFSET           20


#define PHY_CMDPAD_CNFG         0x4
#define PHY_DATAPAD_CNFG        0x6
#define PHY_CLKPAD_CNFG         0x8
#define PHY_STBPAD_CNFG         0xA
#define PHY_RSTNPAD_CNFG        0xC

#define RXSEL_OFFSET            0
#define WAKEPULL_EN_OFFSET      3
#define TXSLEW_CTRL_P_OFFSET    5
#define TXSLEW_CTRL_N_OFFSET    9

#define SDCLKDL_CNFG            0x1d
#define SDCLKDL_DC              0x1e

#define PHY_SMPLDL_CNFG         0x20
#define PHY_ATDL_CNFG           0x21

#define INSPEL_CNFG_BITS        (UL(1)<<2 | UL(1)<<3)
#define INSPEL_CNFG_OFFSET      0x2

#define PHY_RSTN                (1U<<0)
#define PHY_PWRGOOD             (1U<<1)

#define PHY_DLL_CTRL		0x24
#define DLL_EN			(1U<<0)
#define OFFST_EN		(1U<<1)
#define SLV_SWDC_UPDATE		(1U<<2)

#define PHY_DLL_CNFG1		0x25
#define SLVDLY			0x20

#define PHY_DLL_CNFG2		0x26
#define DLL_JUMPSTEP		0

#define PHY_DLLDL_CNFG		0x28
#define SLV_INPSEL		(UL(1)<<5 | UL(1)<<6)

#define PHY_DLL_OFFST		0x29
#define PHY_DLLLBT_CNFG		0x2c
#define LBT_LOADVAL		10000

#define PHY_DLL_STATUS		0x2e
#define DLL_LOCK_STS		(1U<<0)
#define DLL_ERROR_STS		(1U<<1)

#define PHY_DLLDBG_MLKDC	0x30
#define PHY_DLLDBG_SLKDC	0x32

#define MSHC_EMMC_CTRL           0x52c
#define EMMC_CTRL_ENH_STROBE_ENABLE	BIT(8)
#define EMMC_CTRL_EMMC_RST_N     BIT(2)
#define EMMC_CTRL_IS_EMMC        BIT(0)

struct sdhci_leipzig_host {
	struct platform_device *pdev;
	int pwr_irq;		/* power irq */
	struct clk *clk;	/* main SD/MMC bus clock */
	struct clk *pclk;	/* SDHC peripheral bus clock */
	struct mmc_host *mmc;
	void __iomem *sysc;     /* sysc, for clock divider*/
	int devnum;
	u32 clkdl;
	u32 tune_start;
	bool is_emmc;
};

static void sdhci_leipzig_set_emmc(struct sdhci_host *host)
{
	u8 value;

	value = sdhci_readb(host, MSHC_EMMC_CTRL);
	if (!(value & EMMC_CTRL_IS_EMMC)) {
		value |= EMMC_CTRL_IS_EMMC;
		pr_debug("%s: Set EMMC_CTRL: 0x%08x\n",
				mmc_hostname(host->mmc), value);
		sdhci_writeb(host, value, MSHC_EMMC_CTRL);
	}
}

static bool DLL_SET_DONE;
static int sdhci_leipzig_hs400_set_dll(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);
	u32 val = 0;
	u16 clk = 0;
	u8 v8 = 0;
	int i = 0;

	if (DLL_SET_DONE == 0) {
		// Stop eMMC Devie Clock
		clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL);
		clk &= ~SDHCI_CLOCK_CARD_EN;
		sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);

		// HS400 Disable DLL
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CTRL);
		v8 &= ~DLL_EN;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CTRL);

		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CNFG1);
		v8 |= SLVDLY;
		v8 = 0x20;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CNFG1);
		sdhci_writeb(host, DLL_JUMPSTEP, PTR_PHY_REGS + PHY_DLL_CNFG2);
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLLDL_CNFG);
		v8 |= SLV_INPSEL;	//(0) MMC1 CLK -> (3) Strobe Clock
		v8 = 0x60;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLLDL_CNFG);
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CTRL);
		v8 |= SLV_SWDC_UPDATE;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CTRL);
		sdhci_writeb(host, 0, PTR_PHY_REGS + PHY_DLL_OFFST); //copy SDCLKDL_DC ?
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CTRL);
		v8 &= ~SLV_SWDC_UPDATE;
		sdhci_writeb(host, val, PTR_PHY_REGS + PHY_DLL_CTRL);
		sdhci_writew(host, LBT_LOADVAL, PTR_PHY_REGS + PHY_DLLLBT_CNFG);

		clk |= SDHCI_CLOCK_CARD_EN;
		sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);

		// HS400 Enable DLL
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CTRL);
		v8 |= DLL_EN;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CTRL);

#define TIMEOUT_CNT     5000
		// polling DLL status
		for (i = 0 ; i < TIMEOUT_CNT*10 ; i++) {
			v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_STATUS);
			if (v8 & DLL_LOCK_STS)
				break;
			mdelay(1);
		}
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_STATUS);
		if (v8 & DLL_ERROR_STS) {
			pr_debug("DLL status error! (0x%x)\n", v8);
			v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLLDBG_MLKDC);
			pr_debug("PHY_DLLDBG_MLKDC = 0x%x\n", v8);
			v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLLDBG_SLKDC);
			pr_debug("PHY_DLLDBG_SLKDC = 0x%x\n", v8);
			pr_debug("SDHCI_HOST_CONTROL2 = 0x%x\n",
					sdhci_readw(host, SDHCI_HOST_CONTROL2));
			pr_debug("SYSC_MSHC_CTRL = 0x%x\n",
					readl(leipzig_host->sysc + SYSC_MSHC_CTRL));
			return -1;
		}
		pr_debug("!!!!!!!! DLL lock OK !");
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLLDBG_MLKDC);
		pr_debug("PHY_DLLDBG_MLKDC = 0x%x\n", v8);
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLLDBG_SLKDC);
		pr_debug("PHY_DLLDBG_SLKDC = 0x%x\n", v8);
		DLL_SET_DONE = 1;
	} else {
		// HS400 Disable DLL
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CTRL);
		v8 &= ~DLL_EN;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CTRL);
		// HS400 Enable DLL
		v8 |= DLL_EN;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CTRL);
	}
	return 0;
}

static void sdhci_leipzig_hs400_complete(struct mmc_host *mmc)
{
	struct sdhci_host *host = mmc_priv(mmc);

	sdhci_leipzig_hs400_set_dll(host);
}

static void sdhci_leipzig_hs400_enhanced_strobe(struct mmc_host *mmc,
		struct mmc_ios *ios)
{
	u32 vendor;
	struct sdhci_host *host = mmc_priv(mmc);

	vendor = sdhci_readl(host, MSHC_EMMC_CTRL);
	if (ios->enhanced_strobe)
		vendor |= EMMC_CTRL_ENH_STROBE_ENABLE;
	else
		vendor &= ~EMMC_CTRL_ENH_STROBE_ENABLE;

	sdhci_writel(host, vendor, MSHC_EMMC_CTRL);
}


static void sdhci_leipzig_reset_emmc(struct sdhci_host *host)
{
	u8 value;

	pr_debug("%s: Toggle EMMC_CTRL.EMMC_RST_N\n", mmc_hostname(host->mmc));
	value = sdhci_readb(host, MSHC_EMMC_CTRL) &
		~EMMC_CTRL_EMMC_RST_N;
	sdhci_writeb(host, value, MSHC_EMMC_CTRL);
	/* For eMMC, minimum is 1us but give it 10us for good measure */
	usleep_range(10, 20);
	sdhci_writeb(host, value | EMMC_CTRL_EMMC_RST_N,
			MSHC_EMMC_CTRL);
	/* For eMMC, minimum is 200us but give it 300us for good measure */
	usleep_range(300, 400);
}

static int phy_init(struct sdhci_host *host, int mode)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);
	struct platform_device *pdev = leipzig_host->pdev;
	u32 reg = 0, val = 0;
	u16 v16 = 0, clk = 0, clk_org = 0;
	u8 v8 = 0;
	int i = 0;

	if (leipzig_host->devnum == 0) {
		reg |= MSHC_DEV_0_CLK_TX;
	} else {
		/* MSHC1 */
		reg |= MSHC_DEV_1_CLK_TX;
	}

	// disable Tx clock
	writel(reg, leipzig_host->sysc + SYSC_CLK_EN_CLR_REG_3);

	if (host->mmc->caps & MMC_CAP_8_BIT_DATA) {
		// HS400 Disable DLL
		v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_DLL_CTRL);
		v8 &= ~DLL_EN;
		sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_DLL_CTRL);
	}

	// Assert phy_rset (PHY_RSTN)
	val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
	val &= 0xfffffffe;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);

	if (host->mmc->ios.power_mode == MMC_POWER_OFF) {
		pr_debug("%s: MMC_POWER_OFF\n", __func__);
		return 0;
	}

	// Set controller initial 1.8v if using "fix-1-8-v"
	if (!(host->flags & SDHCI_SIGNALING_330) &&
			host->flags & SDHCI_SIGNALING_180) {
		val = sdhci_readw(host, SDHCI_HOST_CONTROL2);
		val |= SDHCI_CTRL_VDD_180;
		sdhci_writew(host, val, SDHCI_HOST_CONTROL2);
	}

	//
	val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
	val |= 0x9 << PAD_SP_OFFSET;
	val |= 0x8 << PAD_SN_OFFSET;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);
//#define MODE_EMMC
#ifdef MODE_EMMC
	// from table 8-6, recommended PAD setting
	// for EMMC PHY 1.8V mode
	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x1 << WAKEPULL_EN_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CMDPAD_CNFG);

	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x1 << WAKEPULL_EN_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_DATAPAD_CNFG);
	v16 &= ~(0x3 << WAKEPULL_EN_OFFSET);
	v16 |= (0x2 << WAKEPULL_EN_OFFSET);
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_STBPAD_CNFG);

	v16 = 0;
	v16 |= 0x0 << RXSEL_OFFSET;
	v16 |= 0x0 << WAKEPULL_EN_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CLKPAD_CNFG);


	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x1 << WAKEPULL_EN_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x2 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_RSTNPAD_CNFG);
#else
	// set phy value from soc team simulation
	// from table 8-8, recommended PAD setting
	// for SD PHY 1.8V mode
	// other values are from golden waveform
	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x1 << WAKEPULL_EN_OFFSET;
	v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CMDPAD_CNFG);

	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x1 << WAKEPULL_EN_OFFSET;
	v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_DATAPAD_CNFG);
	v16 &= ~(0x3 << WAKEPULL_EN_OFFSET);
	v16 |= (0x2 << WAKEPULL_EN_OFFSET);
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_STBPAD_CNFG);

	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x0 << WAKEPULL_EN_OFFSET;
	v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_CLKPAD_CNFG);


	v16 = 0;
	v16 |= 0x2 << RXSEL_OFFSET;
	v16 |= 0x1 << WAKEPULL_EN_OFFSET;
	v16 |= 0x3 << TXSLEW_CTRL_P_OFFSET;
	v16 |= 0x1 << TXSLEW_CTRL_N_OFFSET;
	sdhci_writew(host, v16, PTR_PHY_REGS + PHY_RSTNPAD_CNFG);
#endif

	v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_SMPLDL_CNFG);
	v8 &= ~(INSPEL_CNFG_BITS);
	v8 |= 0x2 << INSPEL_CNFG_OFFSET;

	v8 = 0xc;
	sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_SMPLDL_CNFG);

	v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_ATDL_CNFG);
	v8 &= ~(INSPEL_CNFG_BITS);
	v8 |= 0x2 << INSPEL_CNFG_OFFSET;

	v8 = 0xc;
	sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_ATDL_CNFG);

	/* this tunes clk delay */
	v8 = leipzig_host->clkdl;
	dev_dbg(&pdev->dev, "phy setting, clkdl:%d\n", v8);
	clk_org = sdhci_readw(host, SDHCI_CLOCK_CONTROL);
	clk = clk_org & ~SDHCI_CLOCK_CARD_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);

	sdhci_writeb(host, 0x10, PTR_PHY_REGS + SDCLKDL_CNFG);
	sdhci_writeb(host, v8, PTR_PHY_REGS + SDCLKDL_DC);
	sdhci_writeb(host, 0x0, PTR_PHY_REGS + SDCLKDL_CNFG);

	sdhci_writew(host, clk_org, SDHCI_CLOCK_CONTROL);
#define TIMEOUT_CNT     5000
	// polling powergood to 1
	for (i = 0 ; i < TIMEOUT_CNT ; i++) {
		val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
		if (val & PHY_PWRGOOD)
			break;
		mdelay(1);
	}
	if (i == TIMEOUT_CNT)
		return -1;

	// de-assert phy reset, also keep other bits same
	val |= PHY_RSTN;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);

	// enable Tx clock
	writel(reg, leipzig_host->sysc + SYSC_CLK_EN_SET_REG_3);
	return 0;
}

static int __sdhci_execute_tuning(struct sdhci_host *host, u32 opcode)
{
	int i;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *lhost = sdhci_pltfm_priv(pltfm_host);

	/*
	 * Issue opcode repeatedly till Execute Tuning is set to 0 or the number
	 * of loops reaches tuning loop count.
	 */
	for (i = 0; i < host->tuning_loop_count; i++) {
		u16 ctrl;
		u32 at_stat;

		//enable sw tuning
		ctrl = sdhci_readw(host, SDHCI_AT_CTRL_R);
		ctrl |= 0x1 << 4;
		sdhci_writew(host, ctrl, SDHCI_AT_CTRL_R);

		at_stat = sdhci_readl(host, SDHCI_AT_STAT_R);
		at_stat &= ~(0xFF);
		at_stat |= lhost->tune_start;
		sdhci_writel(host, at_stat, SDHCI_AT_STAT_R);

		ctrl = sdhci_readw(host, SDHCI_AT_CTRL_R);
		ctrl &= ~(0x1 << 4);
		sdhci_writew(host, ctrl, SDHCI_AT_CTRL_R);

		at_stat = sdhci_readl(host, SDHCI_AT_STAT_R);
		pr_debug("++ AT_STAT:0x%x\n", at_stat);

		sdhci_send_tuning(host, opcode);

		if (!host->tuning_done) {
			pr_debug("%s: Tuning timeout, use fixed\n",
					mmc_hostname(host->mmc));
			sdhci_abort_tuning(host, opcode);
			return -ETIMEDOUT;
		}
		/* Spec does not require a delay between tuning cycles */
		if (host->tuning_delay > 0)
			mdelay(host->tuning_delay);

		ctrl = sdhci_readw(host, SDHCI_HOST_CONTROL2);
		at_stat = sdhci_readl(host, SDHCI_AT_STAT_R);
		pr_debug("ctrl:0x%x AT_STAT:0x%x\n", ctrl, at_stat);
		if (!(ctrl & SDHCI_CTRL_EXEC_TUNING)) {
			if (ctrl & SDHCI_CTRL_TUNED_CLK)
				return 0; /* Success! */
			break;
		}

	}

	pr_info("%s: Tuning failed, falling back to fixed sampling clock\n",
			mmc_hostname(host->mmc));
	sdhci_reset_tuning(host);
	return -EAGAIN;
}



static int sdhci_leipzig_execute_tuning(struct sdhci_host *host, u32 opcode)
{
	int rc = 0;
	__maybe_unused struct mmc_host *mmc = host->mmc;
	__maybe_unused struct mmc_ios ios = host->mmc->ios;

	mmc->retune_period = host->tuning_count;

	pr_debug("tuning_count:%d opcode:0x%x\n", host->tuning_count, opcode);
	if (host->tuning_delay < 0)
		host->tuning_delay = opcode == MMC_SEND_TUNING_BLOCK;

	sdhci_start_tuning(host);

	host->tuning_err = __sdhci_execute_tuning(host, opcode);

	sdhci_end_tuning(host);
	pr_debug("tuning_err = 0x%x\n", host->tuning_err);

	return rc;
}

static void sdhci_leipzig_set_uhs_signaling(struct sdhci_host *host,
					unsigned int uhs)
{
	host->tuning_loop_count = 255;
	sdhci_set_uhs_signaling(host, uhs);
}

static void sdhci_leipzig_voltage_switch(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	__maybe_unused struct sdhci_leipzig_host *leipzig_host
						= sdhci_pltfm_priv(pltfm_host);
	pr_debug("%s +++\n", __func__);
}

void wagner_sdhci_clk_enable(struct sdhci_host *host, int enable)
{
	u32 reg = 0;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);

	if (leipzig_host->devnum == 0)
		reg = MSHC_DEV_0_CLK_MASK;
	else
		reg = MSHC_DEV_1_CLK_MASK;

	if (!enable)
		writel(reg, leipzig_host->sysc + SYSC_CLK_EN_CLR_REG_3);
	else
		writel(reg, leipzig_host->sysc + SYSC_CLK_EN_SET_REG_3);
}
/*TODO: this is suppoed to be from clock get_rate*/
unsigned int get_clk_div(unsigned int clock)
{
	unsigned int div;
	/* clock = 400000000 / 2(div+1)*/
	if (clock == 52000000)
		clock = 50000000;
	div = 400000000 / clock;
	div = div / 2;
	div = div - 1;
	return div;
}
void wagner_platform_clock(struct sdhci_host *host, unsigned int clock)
{
	// real clock control here
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);
	u32 reg = readl(leipzig_host->sysc + SYSC_MSHC_CTRL);
	u32 div = get_clk_div(clock);

	pr_debug("%s, SYSC_MSHC_CTRL:0x%x clock:%d\n", __func__, reg, clock);
	wagner_sdhci_clk_enable(host, 0);
	if (leipzig_host->devnum == 0) {
		reg &= ~(MSHC_CTRL_DIV0_MASK);
		reg |= div << MSHC_CTRL_DIV0_OFFSET;
	} else {
		/* MSHC1 */
		reg &= ~(MSHC_CTRL_DIV1_MASK);
		reg |= div << MSHC_CTRL_DIV1_OFFSET;
	}

	writel(reg, leipzig_host->sysc + SYSC_MSHC_CTRL);

	if (leipzig_host->devnum == 0)
		reg |= MSHC_CTRL_DIV0_REQ;
	else
		reg |= MSHC_CTRL_DIV1_REQ;

	writel(reg, leipzig_host->sysc + SYSC_MSHC_CTRL);
#ifndef WAGNER_FPGA
	/* fpga does not clear request bit */
	if (leipzig_host->devnum == 0) {
		do {
			reg = readl(leipzig_host->sysc + SYSC_MSHC_CTRL);
		} while ((reg & MSHC_CTRL_DIV0_REQ) != 0);
	} else {
		do {
			reg = readl(leipzig_host->sysc + SYSC_MSHC_CTRL);
		} while ((reg & MSHC_CTRL_DIV1_REQ) != 0);
	}
#endif
	wagner_sdhci_clk_enable(host, 1);

	pr_debug("read from sysc_mshc_clk:0x%x, div:0x%x\n",
			readl(leipzig_host->sysc + SYSC_MSHC_CTRL), div);

}

void wagner_reset(struct sdhci_host *host, u8 mask)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);
	u32 val = 0;

	if (mask == SDHCI_RESET_ALL) {
		// Assert phy_rset (PHY_RSTN) before controller reset
		// to avoid signal voltage change.
		// phy_rset will be release in phy_init
		val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
		val &= 0xfffffffe;
		sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);
	}

	sdhci_reset(host, mask);

	if (mask == SDHCI_RESET_ALL)
		phy_init(host, 0);

	if (leipzig_host->is_emmc)
		sdhci_leipzig_set_emmc(host);
}


void wagner_set_clock(struct sdhci_host *host, unsigned int clock)
{
	u16 clk;
	unsigned long timeout;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);

	pr_debug("%s, clock:%d sysc_clk:0x%x\n", __func__, clock,
			readl(leipzig_host->sysc + SYSC_MSHC_CTRL));
	host->mmc->actual_clock = 0;

	sdhci_writew(host, 0, SDHCI_CLOCK_CONTROL);

	if (clock == 0)
		return;

	/* wanger platform specific here*/
	wagner_platform_clock(host, clock);


	clk = sdhci_calc_clk(host, clock, &host->mmc->actual_clock);

	clk |= SDHCI_CLOCK_INT_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);

	/* Wait max 20 ms */
	timeout = 20;
	while (!((clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL))
				& SDHCI_CLOCK_INT_STABLE)) {
		if (timeout == 0) {
			pr_err("%s: Internal clock never stabilised.\n",
					mmc_hostname(host->mmc));
			//sdhci_dumpregs(host);
			return;
		}
		timeout--;
		spin_unlock_irq(&host->lock);
		usleep_range(900, 1100);
		spin_lock_irq(&host->lock);
	}

	clk |= SDHCI_CLOCK_PLL_EN;
	clk |= SDHCI_CLOCK_CARD_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
}

static ssize_t phy_clkdl_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *lhost = sdhci_pltfm_priv(pltfm_host);

	return sprintf(buf, "phy_clkdl=%d\n", lhost->clkdl);

}

static ssize_t phy_clkdl_store(struct device *dev,	struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *lhost = sdhci_pltfm_priv(pltfm_host);
	u32 reg;
	int ret = kstrtou32(buf, 10, &reg);

	if (ret < 0)
		return 0;

	lhost->clkdl = reg;
	phy_init(host, 0);

	return count;
}

static ssize_t tune_start_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *lhost = sdhci_pltfm_priv(pltfm_host);

	return sprintf(buf, "tune_start=%d\n", lhost->tune_start);
}

static ssize_t tune_start_store(struct device *dev,	struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *lhost = sdhci_pltfm_priv(pltfm_host);
	u32 reg;
	int ret = kstrtou32(buf, 10, &reg);

	if (ret < 0)
		return 0;

	lhost->tune_start = reg;

	return count;
}

static DEVICE_ATTR_RW(phy_clkdl);
static DEVICE_ATTR_RW(tune_start);

void leipzig_get_of_property(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *lhost = sdhci_pltfm_priv(pltfm_host);

	device_property_read_u32(dev, "phy-clkdl", &lhost->clkdl);

	if (device_property_present(dev, "fix-1-8-v")) {
		/* If device only support 1.8v signal */
		host->flags |= SDHCI_SIGNALING_180;
		host->flags &= ~SDHCI_SIGNALING_330;
	}

	if (device_property_present(dev, "is-emmc"))
		lhost->is_emmc = 1;
}


static const struct of_device_id sdhci_leipzig_dt_match[] = {
	{ .compatible = "leipzig,sdhci" },
	{},
};

MODULE_DEVICE_TABLE(of, sdhci_leipzig_dt_match);

static const struct sdhci_ops sdhci_leipzig_ops = {
	.platform_execute_tuning = sdhci_leipzig_execute_tuning,
	.reset = wagner_reset,
	.set_clock = wagner_set_clock,
	.set_bus_width = sdhci_set_bus_width,
	.set_uhs_signaling = sdhci_leipzig_set_uhs_signaling,
	.voltage_switch = sdhci_leipzig_voltage_switch,
};

static const struct sdhci_pltfm_data sdhci_leipzig_pdata = {
	.quirks =
		  SDHCI_QUIRK_NO_CARD_NO_RESET |
		  SDHCI_QUIRK_NO_LED |
		  SDHCI_QUIRK_SINGLE_POWER_WRITE,
	/*.quirks2 = SDHCI_QUIRK2_CAPS_BIT63_FOR_HS400,*/
	.ops = &sdhci_leipzig_ops,
};

static int proc_init(struct platform_device *pdev)
{
	device_create_file(&pdev->dev, &dev_attr_phy_clkdl);
	device_create_file(&pdev->dev, &dev_attr_tune_start);
	return 0;
}

static int sdhci_leipzig_probe(struct platform_device *pdev)
{
	struct sdhci_host *host;
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_leipzig_host *leipzig_host;
	struct resource *iomem;
	int ret;
	u32 reg;

	host = sdhci_pltfm_init(pdev, &sdhci_leipzig_pdata, sizeof(*leipzig_host));
	if (IS_ERR(host))
		return PTR_ERR(host);


	pltfm_host = sdhci_priv(host);
	leipzig_host = sdhci_pltfm_priv(pltfm_host);
	leipzig_host->mmc = host->mmc;
	leipzig_host->pdev = pdev;
	leipzig_host->sysc = ioremap(VPL_SYSC_NONSECURE_MMR_BASE, 0x100);
	leipzig_host->is_emmc = 0;

	iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (iomem->start == VPL_MSHC_0_MMR_BASE)
		leipzig_host->devnum = 0;
	else
		leipzig_host->devnum = 1;

	/*check if emmc now??? */
	if (leipzig_host->devnum == 1)
		host->quirks |= SDHCI_QUIRK_BROKEN_CARD_DETECTION;

	ret = mmc_of_parse(host->mmc);
	if (ret)
		goto pltfm_free;

	if (host->mmc->f_max <= 52000000)
		host->quirks2 |= SDHCI_QUIRK2_BROKEN_HS200;

	leipzig_get_of_property(pdev);
	sdhci_get_of_property(pdev);

	if (host->mmc->caps & MMC_CAP_8_BIT_DATA) {
		pr_info("set sysc to mshc 8bit data\n");
		reg = readl(leipzig_host->sysc + SYSC_MSHC_CTRL);
		reg &= ~(MSHC_CTRL_4BIT_8BIT);
		writel(reg, leipzig_host->sysc + SYSC_MSHC_CTRL);
	}

	host->mmc_host_ops.hs400_enhanced_strobe = sdhci_leipzig_hs400_enhanced_strobe;
	host->mmc_host_ops.hs400_complete = sdhci_leipzig_hs400_complete;

	/* Setup SDC MMC clock */
/* FIXME: fix this with clock framework */
#ifdef REAL_CLOCK
	leipzig_host->clk = devm_clk_get(&pdev->dev, "core");
	if (IS_ERR(leipzig_host->clk)) {
		ret = PTR_ERR(leipzig_host->clk);
		dev_err(&pdev->dev, "SDC MMC clk setup failed (%d)\n", ret);
		goto pclk_disable;
	}

	/* Vote for maximum clock rate for maximum performance */
	ret = clk_set_rate(leipzig_host->clk, INT_MAX);
	if (ret)
		dev_warn(&pdev->dev, "core clock boost failed\n");

	ret = clk_prepare_enable(leipzig_host->clk);
	if (ret)
		goto pclk_disable;
#endif
	proc_init(pdev);
	phy_init(host, 0);
	sdhci_enable_v4_mode(host);

	if (leipzig_host->is_emmc) {
		/* Do a HW reset of eMMC card */
		sdhci_leipzig_reset_emmc(host);
		/* Update EMMC_CTRL */
		sdhci_leipzig_set_emmc(host);
		/* If eMMC, disable SD and SDIO */
		host->mmc->caps2 |= (MMC_CAP2_NO_SDIO|MMC_CAP2_NO_SD);
	}

	ret = sdhci_add_host(host);
	if (ret)
		goto clk_disable;

	return 0;

clk_disable:
	clk_disable_unprepare(leipzig_host->clk);
#ifdef REAL_CLOCK
pclk_disable:
	clk_disable_unprepare(leipzig_host->pclk);
#endif
pltfm_free:
	sdhci_pltfm_free(pdev);
	return ret;
}

static int sdhci_leipzig_remove(struct platform_device *pdev)
{
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_leipzig_host *leipzig_host = sdhci_pltfm_priv(pltfm_host);

	sdhci_remove_host(host, 0);
	clk_disable_unprepare(leipzig_host->clk);
	clk_disable_unprepare(leipzig_host->pclk);
	sdhci_pltfm_free(pdev);
	return 0;
}

static struct platform_driver sdhci_leipzig_driver = {
	.probe = sdhci_leipzig_probe,
	.remove = sdhci_leipzig_remove,
	.driver = {
		   .name = "sdhci_leipzig",
		   .of_match_table = sdhci_leipzig_dt_match,
	},
};

module_platform_driver(sdhci_leipzig_driver);

MODULE_DESCRIPTION("leipzig Secure Digital Host Controller Interface driver");
MODULE_LICENSE("GPL");

// SPDX-License-Identifier: GPL-2.0+
/*
 * Vatics SDHCI driver - SD/eMMC controller
 *
 * Based on Linux driver
 */
//#define DEBUG 1

#include <common.h>
#include <clk.h>
#include <dm.h>
#include <malloc.h>
#include <sdhci.h>
#include <wait_bit.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <linux/bitops.h>

#define VPL_SYSC_NONSECURE_MMR_BASE     0xCEE00000
#define SYSC_CLK_EN_CLR_REG_3            0x19c
#define SYSC_CLK_EN_SET_REG_3         0x198
#define SYSC_MSHC_CTRL       0xc8

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

#define         MSHC_DEV_1_CLK_MASK     (MSHC_DEV_1_CLK_TX |\
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

#define SDCLKDL_CNFG		0x1d
#define SDCLKDL_DC		0x1e

#define PHY_SMPLDL_CNFG         0x20
#define PHY_ATDL_CNFG           0x21

#define INSPEL_CNFG_BITS        (UL(1)<<2 | UL(1)<<3)
#define INSPEL_CNFG_OFFSET      0x2

#define PHY_RSTN                (1U<<0)
#define PHY_PWRGOOD             (1U<<1)

struct vatics_sdhc_plat {
	struct mmc_config cfg;
	struct mmc mmc;
};

struct vatics_sdhc {
	struct sdhci_host host;
	void *base;
	u32 clkdl;
	bool is_emmc;
	bool fix_1_8_v;
};

DECLARE_GLOBAL_DATA_PTR;

int v_phy_init(struct sdhci_host *host, int mode)
{
	struct mmc *mmc = host->mmc;
	struct udevice *udev = mmc->dev;
	struct vatics_sdhc *priv = dev_get_priv(udev);

	u32 reg = 0, val = 0;
	u16 v16 = 0;
	u8 v8 = 0;
	int i = 0;

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE) {
		reg |= MSHC_DEV_0_CLK_TX;
	} else {
		/* MSHC1 */
		reg |= MSHC_DEV_1_CLK_TX;
	}
	// disable Tx clock
	writel(reg, VPL_SYSC_NONSECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_3);

	// Assert phy_rset (PHY_RSTN)
	val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
	val &= 0xfffffffe;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);

	// Set controller initial 1.8v if using "fix-1-8-v"
	if (priv->fix_1_8_v) {
		val = sdhci_readw(host, SDHCI_HOST_CONTROL2);
		val |= SDHCI_CTRL_VDD_180;
		sdhci_writew(host, val, SDHCI_HOST_CONTROL2);
	}

	//
	val = sdhci_readl(host, PTR_PHY_REGS + PHY_CNFG);
	val |= 0x9 << PAD_SP_OFFSET;
	val |= 0x8 << PAD_SN_OFFSET;
	sdhci_writel(host, val, PTR_PHY_REGS + PHY_CNFG);

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
	sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_SMPLDL_CNFG);

	v8 = sdhci_readb(host, PTR_PHY_REGS + PHY_ATDL_CNFG);
	v8 &= ~(INSPEL_CNFG_BITS);
	v8 |= 0x2 << INSPEL_CNFG_OFFSET;
	sdhci_writeb(host, v8, PTR_PHY_REGS + PHY_ATDL_CNFG);

	v8 = priv->clkdl;
	debug("set clkdl:0x%x\n", v8);
	sdhci_writeb(host, 0x10, PTR_PHY_REGS + SDCLKDL_CNFG);
	sdhci_writeb(host, v8, PTR_PHY_REGS + SDCLKDL_DC);
	sdhci_writeb(host, 0x0, PTR_PHY_REGS + SDCLKDL_CNFG);

#ifdef USE_FIX_DELAYCODE
	printf("use fix delay\n");
	sdhci_writeb(host, 0x1, PTR_PHY_REGS + SDCLKDL_CNFG);
#endif

	// polling powergood to 1
#define TIMEOUT_CNT     5000
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
	writel(reg, VPL_SYSC_NONSECURE_MMR_BASE + SYSC_CLK_EN_SET_REG_3);
	return 0;
}


void vatics_sdhci_set_control_reg(struct sdhci_host *host)
{
	struct vatics_sdhc *priv = dev_get_priv(host->mmc->dev);
	u32 reg;

	if (priv->is_emmc) {
		reg = sdhci_readw(host, 0x52c);
		reg |= 0x1; // card is emmc
		sdhci_writew(host, reg, 0x52c);
	}

	reg = sdhci_readw(host, SDHCI_HOST_CONTROL2);
	reg |= 0x1000; //version 4
	if (priv->fix_1_8_v) {
		host->mmc->signal_voltage = MMC_SIGNAL_VOLTAGE_180;
		reg |= SDHCI_CTRL_VDD_180;
	}
	sdhci_writew(host, reg, SDHCI_HOST_CONTROL2);

	sdhci_set_control_reg(host);

	reg = sdhci_readw(host, SDHCI_HOST_CONTROL2);
	debug("SDHCI_HOST_CONTROL2=0x%x\n", reg);
}

void wagner_sdhci_clk_enable(struct sdhci_host *host, int enable)
{
	u32 reg = 0;

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE)
		reg = MSHC_DEV_0_CLK_MASK;
	else
		reg = MSHC_DEV_1_CLK_MASK;

	if (!enable)
		writel(reg, VPL_SYSC_NONSECURE_MMR_BASE + SYSC_CLK_EN_CLR_REG_3);
	else
		writel(reg, VPL_SYSC_NONSECURE_MMR_BASE + SYSC_CLK_EN_SET_REG_3);
}


void wagner_set_clock(struct sdhci_host *host, u32 div)
{
	// real clock control here
	debug("%s +++, sysc_mshc:0x%x\n", __func__,
			readl(VPL_SYSC_NONSECURE_MMR_BASE
				+ SYSC_MSHC_CTRL));
	wagner_sdhci_clk_enable(host, 0);
	u32 reg = readl(VPL_SYSC_NONSECURE_MMR_BASE + SYSC_MSHC_CTRL);

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE) {
		reg &= ~(MSHC_CTRL_DIV0_MASK);
		reg |= div << MSHC_CTRL_DIV0_OFFSET;
	} else {
		/* MSHC1 */
		reg &= ~(MSHC_CTRL_DIV1_MASK);
		reg |= div << MSHC_CTRL_DIV1_OFFSET;
	}

	writel(reg, VPL_SYSC_NONSECURE_MMR_BASE + SYSC_MSHC_CTRL);

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE)
		reg |= MSHC_CTRL_DIV0_REQ;
	else
		reg |= MSHC_CTRL_DIV1_REQ;

	writel(reg, VPL_SYSC_NONSECURE_MMR_BASE + SYSC_MSHC_CTRL);

	if (host->ioaddr == (void *)VPL_MSHC_0_MMR_BASE) {
		do {
			reg = readl(VPL_SYSC_NONSECURE_MMR_BASE
					+ SYSC_MSHC_CTRL);
		} while ((reg & MSHC_CTRL_DIV0_REQ) != 0);
	} else {
		do {
			reg = readl(VPL_SYSC_NONSECURE_MMR_BASE
					+ SYSC_MSHC_CTRL);
		} while ((reg & MSHC_CTRL_DIV1_REQ) != 0);
	}
	wagner_sdhci_clk_enable(host, 1);
	debug("sysc_mshc_clk:0x%x div:0x%x\n", reg, div);
	debug("read from sysc_mshc_clk:0x%x\n",
			readl(VPL_SYSC_NONSECURE_MMR_BASE + SYSC_MSHC_CTRL));

}

static struct sdhci_ops vatics_sdhci_ops = {
	.set_control_reg = vatics_sdhci_set_control_reg,
	.set_clock = wagner_set_clock,
};

#ifdef REAL_CLOCK_DEFINE
static int vaticssdc_clk_init(struct udevice *dev)
{
	u32 clk_rate = dev_read_u32_default(dev, "clock-frequency", 400000);
	struct clk clk;
	int ret;

	ret = clk_get_by_index(dev, 0, &clk);
	if (ret)
		return ret;

	ret = clk_enable(&clk);
	if (ret)
		return ret;

	return 0;
}
#endif

static int vaticssdc_probe(struct udevice *dev)
{
	struct mmc_uclass_priv *upriv = dev_get_uclass_priv(dev);
	struct vatics_sdhc_plat *plat = dev_get_plat(dev);
	struct vatics_sdhc *prv = dev_get_priv(dev);
	struct sdhci_host *host = &prv->host;
	int ret;

	host->quirks = SDHCI_QUIRK_WAIT_SEND_CMD | SDHCI_QUIRK_BROKEN_R1B;

	host->max_clk = 0;
	/* Init clocks */
#if REAL_CLOCK_ENABLE
	ret = vaticssdc_clk_init(dev);
	if (ret) {
		printf("clock init fail\n");
		return ret;
	}
#endif

	/* Reset the core and Enable SDHC mode */
	/* TODO: power on here, should leipzig do this?*/

	ret = mmc_of_parse(dev, &plat->cfg);
	if (ret)
		return ret;

	host->mmc = &plat->mmc;
	host->mmc->dev = dev;

	if (plat->cfg.f_min == 0)
		plat->cfg.f_min = 400000;

	ret = sdhci_setup_cfg(&plat->cfg, host, plat->cfg.f_max, plat->cfg.f_min);
	if (ret)
		return ret;
	host->mmc->priv = &prv->host;
	upriv->mmc = host->mmc;
	host->ops = &vatics_sdhci_ops;

	return sdhci_probe(dev);
}

static int vaticssdc_remove(struct udevice *dev)
{
	__maybe_unused struct vatics_sdhc *priv = dev_get_priv(dev);

	 /* Disable host-controller mode */
	//writel(0, priv->base + SDCC_MCI_HC_MODE);

	return 0;
}

static int vaticsof_to_plat(struct udevice *dev)
{
	struct vatics_sdhc *priv = dev_get_priv(dev);
	struct sdhci_host *host = &priv->host;

	host->name = strdup(dev->name);
	host->ioaddr = dev_read_addr_ptr(dev);
	host->bus_width = dev_read_u32_default(dev, "bus-width", 4);
	//host->bus_width = 1;
	host->index = dev_read_u32_default(dev, "index", 0);
	priv->base = host->ioaddr;
	priv->clkdl = dev_read_u32_default(dev, "phy-clkdl", 0);
	if (dev_read_bool(dev, "is-emmc"))
		priv->is_emmc = 1;
	if (dev_read_bool(dev, "fix-1-8-v"))
		priv->fix_1_8_v = 1;

	debug("name:%s\n", host->name);
	debug("ioaddr: %p\n", host->ioaddr);
	debug("bus_width: %d\n", host->bus_width);
	debug("index: %d\n", host->index);
	debug("is_emmc: %d\n", priv->is_emmc);
	debug("fix_1_8_v: %d\n", priv->fix_1_8_v);
	return 0;
}

static int vaticssdc_bind(struct udevice *dev)
{
	struct vatics_sdhc_plat *plat = dev_get_plat(dev);

	return sdhci_bind(dev, &plat->mmc, &plat->cfg);
}

static const struct udevice_id vaticsmmc_ids[] = {
	{ .compatible = "vatics,sdhci" },
	{ }
};

U_BOOT_DRIVER(vaticssdc_drv) = {
	.name		= "vaticssdc",
	.id		= UCLASS_MMC,
	.of_match	= vaticsmmc_ids,
	.of_to_plat = vaticsof_to_plat,
	.ops		= &sdhci_ops,
	.bind		= vaticssdc_bind,
	.probe		= vaticssdc_probe,
	.remove		= vaticssdc_remove,
	.priv_auto	= sizeof(struct vatics_sdhc),
	.plat_auto	= sizeof(struct vatics_sdhc_plat),
};

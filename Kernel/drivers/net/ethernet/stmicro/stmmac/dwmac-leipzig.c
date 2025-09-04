// SPDX-License-Identifier: GPL-2.0-only
/*
 * Synopsys DWC Ethernet Quality-of-Service v4.10a linux driver
 *
 * Copyright (C) 2016 Joao Pinto <jpinto@synopsys.com>
 */

#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/device.h>
#include <linux/gpio/consumer.h>
#include <linux/ethtool.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of_net.h>
#include <linux/mfd/syscon.h>
#include <linux/platform_device.h>
#include <linux/regmap.h>
#include <linux/regulator/consumer.h>
#include <linux/reset.h>
#include <linux/stmmac.h>

#include "stmmac_platform.h"
#include "dwmac4.h"
#include "dwmac4_dma.h"

/* SYSC EQOSC control */
#define SYSC_EQOS_CTRL                          0xA4
#define SYSC_PAD_VOLTAGE                        0xE8

#define SYSC_EQOS_REF_OUT_CPHA_180              (0x1 << 29)
#define SYSC_EQOS_RMII_CLK_SRC_SEL_EXT          (0x1 << 28)

#define SYSC_EQOS_TX_CLK_OUT_125M               (0x0 << 24)
#define SYSC_EQOS_TX_CLK_OUT_25M                (0x1 << 24)
#define SYSC_EQOS_TX_CLK_OUT_2_5M               (0x2 << 24)
#define SYSC_EQOS_TX_CLK_OUT_50M                (0x3 << 24)

#define SYSC_EQOS_RMII_50M_CPHA_180             (0x2 << 20)

#define SYSC_EQOS_MODE_SEL_MII                  (0x0 << 16)
#define SYSC_EQOS_MODE_SEL_RGMII                (0x1 << 16)
#define SYSC_EQOS_MODE_SEL_RMII                 (0x4 << 16)

#define SYSC_EQOSC_TX_CLK_SRC_SEL_EXT           (0x0 << 12)
#define SYSC_EQOSC_TX_CLK_SRC_SEL_DIV           (0x1 << 12)
#define SYSC_EQOSC_RX_CLK_SRC_SEL_EXT           (0x0 << 8)
#define SYSC_EQOSC_RX_CLK_SRC_SEL_DIV           (0x1 << 8)

#define SYSC_EQOSC_REDUCED_MODE                 (0x1 << 4)
#define SYSC_EQOSC_TX_OUT_CPHA_90               (0x1 << 4) /* SYSC_EQOSC_REDUCED_MODE */

#define SYSC_EQOSC_INT_CLK_FREQ_SEL_125M        (0x0 << 0)
#define SYSC_EQOSC_INT_CLK_FREQ_SEL_25M         (0x1 << 0)
#define SYSC_EQOSC_INT_CLK_FREQ_SEL_2_5M        (0x2 << 0)
#define SYSC_EQOSC_INT_CLK_FREQ_SEL_RX_25M      (0x0 << 0)
#define SYSC_EQOSC_INT_CLK_FREQ_SEL_RX_2_5M     (0x0 << 0)

#define SYSC_EQOSC_MII_MODE                     (SYSC_EQOS_MODE_SEL_MII | \
						 SYSC_EQOSC_TX_CLK_SRC_SEL_EXT | \
						 SYSC_EQOSC_RX_CLK_SRC_SEL_EXT)

#define SYSC_EQOS_RGMII_BASE_MODE               (SYSC_EQOS_MODE_SEL_RGMII | \
						 SYSC_EQOSC_TX_CLK_SRC_SEL_DIV | \
						 SYSC_EQOSC_RX_CLK_SRC_SEL_EXT | \
						 SYSC_EQOSC_TX_OUT_CPHA_90)

#define SYSC_EQOS_RGMII_1000M_MODE              (SYSC_EQOS_TX_CLK_OUT_125M | \
						 SYSC_EQOS_RGMII_BASE_MODE | \
						 SYSC_EQOSC_INT_CLK_FREQ_SEL_125M)

#define SYSC_EQOS_RGMII_100M_MODE               (SYSC_EQOS_TX_CLK_OUT_25M | \
						 SYSC_EQOS_RGMII_BASE_MODE | \
						 SYSC_EQOSC_INT_CLK_FREQ_SEL_25M)

#define SYSC_EQOS_RGMII_10M_MODE                (SYSC_EQOS_TX_CLK_OUT_2_5M | \
						 SYSC_EQOS_RGMII_BASE_MODE | \
						 SYSC_EQOSC_INT_CLK_FREQ_SEL_2_5M)

#define SYSC_EQOS_RMII_BASE_MODE                (SYSC_EQOS_TX_CLK_OUT_50M | \
						 SYSC_EQOS_RMII_50M_CPHA_180 | \
						 SYSC_EQOS_MODE_SEL_RMII | \
						 SYSC_EQOSC_TX_CLK_SRC_SEL_DIV | \
						 SYSC_EQOSC_RX_CLK_SRC_SEL_DIV)

#define SYSC_EQOS_RMII_50OUT_100M_MODE          (SYSC_EQOS_RMII_BASE_MODE | \
						 SYSC_EQOSC_INT_CLK_FREQ_SEL_25M)

#define SYSC_EQOS_RMII_50OUT_10M_MODE           (SYSC_EQOS_RMII_BASE_MODE | \
						 SYSC_EQOSC_INT_CLK_FREQ_SEL_2_5M)

static phy_interface_t early_phymod = PHY_INTERFACE_MODE_NA;

struct leipzig_dwmac_plat_data {
	struct regmap *regmap;
	struct stmmac_resources *stmmac_res;
	struct plat_stmmacenet_data *plat;
	struct clk *clk_eqosc_rmii;
	struct clk *clk_eqosc_rx;
	struct clk *clk_eqosc_tx;
	struct clk *mem_pwr_eqosc;
	struct regulator *regulator;
};

static int dwc_eth_dwmac_config_dt(struct platform_device *pdev,
				   struct plat_stmmacenet_data *plat_dat)
{
	struct device *dev = &pdev->dev;
	u32 burst_map = 0;
	u32 bit_index = 0;
	u32 a_index = 0;

	if (!plat_dat->axi) {
		plat_dat->axi = kzalloc(sizeof(struct stmmac_axi), GFP_KERNEL);

		if (!plat_dat->axi)
			return -ENOMEM;
	}

	plat_dat->axi->axi_lpi_en = device_property_read_bool(dev,
							      "snps,en-lpi");
	if (device_property_read_u32(dev, "snps,write-requests",
				     &plat_dat->axi->axi_wr_osr_lmt)) {
		/**
		 * Since the register has a reset value of 1, if property
		 * is missing, default to 1.
		 */
		plat_dat->axi->axi_wr_osr_lmt = 1;
	} else {
		/**
		 * If property exists, to keep the behavior from dwc_eth_qos,
		 * subtract one after parsing.
		 */
		plat_dat->axi->axi_wr_osr_lmt--;
	}

	if (device_property_read_u32(dev, "snps,read-requests",
				     &plat_dat->axi->axi_rd_osr_lmt)) {
		/**
		 * Since the register has a reset value of 1, if property
		 * is missing, default to 1.
		 */
		plat_dat->axi->axi_rd_osr_lmt = 1;
	} else {
		/**
		 * If property exists, to keep the behavior from dwc_eth_qos,
		 * subtract one after parsing.
		 */
		plat_dat->axi->axi_rd_osr_lmt--;
	}
	device_property_read_u32(dev, "snps,burst-map", &burst_map);

	/* converts burst-map bitmask to burst array */
	for (bit_index = 0; bit_index < 7; bit_index++) {
		if (burst_map & (1 << bit_index)) {
			switch (bit_index) {
			case 0:
			plat_dat->axi->axi_blen[a_index] = 4; break;
			case 1:
			plat_dat->axi->axi_blen[a_index] = 8; break;
			case 2:
			plat_dat->axi->axi_blen[a_index] = 16; break;
			case 3:
			plat_dat->axi->axi_blen[a_index] = 32; break;
			case 4:
			plat_dat->axi->axi_blen[a_index] = 64; break;
			case 5:
			plat_dat->axi->axi_blen[a_index] = 128; break;
			case 6:
			plat_dat->axi->axi_blen[a_index] = 256; break;
			default:
			break;
			}
			a_index++;
		}
	}

	/* dwc-qos needs GMAC4, AAL, TSO and PMT */
	plat_dat->has_gmac4 = 1;
	plat_dat->dma_cfg->aal = 1;
	plat_dat->tso_en = 1;
	plat_dat->pmt = 1;

	return 0;
}

static int dwc_qos_probe(struct platform_device *pdev,
			 struct plat_stmmacenet_data *plat_dat,
			 struct stmmac_resources *stmmac_res)
{
	int err;
	struct leipzig_dwmac_plat_data *bsp_plat_dat;

	bsp_plat_dat = (struct leipzig_dwmac_plat_data *)plat_dat->bsp_priv;

	bsp_plat_dat->clk_eqosc_rmii = devm_clk_get(&pdev->dev, "eqosc_rmii");
	if (IS_ERR(bsp_plat_dat->clk_eqosc_rmii)) {
		dev_err(&pdev->dev, "clk_eqosc_rmii clock not found.\n");
		return PTR_ERR(bsp_plat_dat->clk_eqosc_rmii);
	}
	err = clk_prepare_enable(bsp_plat_dat->clk_eqosc_rmii);
	if (err < 0) {
		dev_err(&pdev->dev, "failed to enable clk_eqosc_rmii clock: %d\n",
			err);
		return err;
	}

	bsp_plat_dat->clk_eqosc_rx = devm_clk_get(&pdev->dev, "eqosc_rx");
	if (IS_ERR(bsp_plat_dat->clk_eqosc_rx)) {
		dev_err(&pdev->dev, "clk_eqosc_rx clock not found.\n");
		return PTR_ERR(bsp_plat_dat->clk_eqosc_rx);
	}
	err = clk_prepare_enable(bsp_plat_dat->clk_eqosc_rx);
	if (err < 0) {
		dev_err(&pdev->dev, "failed to enable clk_eqosc_rx clock: %d\n",
			err);
		return err;
	}

	bsp_plat_dat->clk_eqosc_tx = devm_clk_get(&pdev->dev, "eqosc_tx");
	if (IS_ERR(bsp_plat_dat->clk_eqosc_tx)) {
		dev_err(&pdev->dev, "clk_eqosc_tx clock not found.\n");
		return PTR_ERR(bsp_plat_dat->clk_eqosc_tx);
	}
	err = clk_prepare_enable(bsp_plat_dat->clk_eqosc_tx);
	if (err < 0) {
		dev_err(&pdev->dev, "failed to enable clk_eqosc_tx clock: %d\n",
			err);
		return err;
	}

	bsp_plat_dat->mem_pwr_eqosc = devm_clk_get(&pdev->dev, "mem_pwr_eqosc");
	if (IS_ERR(bsp_plat_dat->mem_pwr_eqosc)) {
		dev_err(&pdev->dev, "mem_pwr_eqosc clock not found.\n");
		return PTR_ERR(bsp_plat_dat->mem_pwr_eqosc);
	}
	err = clk_prepare_enable(bsp_plat_dat->mem_pwr_eqosc);
	if (err < 0) {
		dev_err(&pdev->dev, "failed to enable mem_pwr_eqosc clock: %d\n",
			err);
		return err;
	}

	/* Optional regulator for MII */
	bsp_plat_dat->regulator = devm_regulator_get_optional(&pdev->dev, "pd_11");
	if (IS_ERR(bsp_plat_dat->regulator)) {
		err = PTR_ERR(bsp_plat_dat->regulator);
			if (err == -EPROBE_DEFER)
				return -EPROBE_DEFER;
		dev_warn(&pdev->dev, "No vdd regulator found: %d\n", err);
		bsp_plat_dat->regulator = NULL;
	} else {
		err = regulator_enable(bsp_plat_dat->regulator);
		if (err)
			dev_warn(&pdev->dev, "Failed to enable regulator: %d\n", err);
	}
	return 0;
}

static int dwc_qos_remove(struct platform_device *pdev)
{
	struct net_device *ndev = platform_get_drvdata(pdev);
	struct stmmac_priv *priv = netdev_priv(ndev);
	struct leipzig_dwmac_plat_data *bsp_plat_dat;
	int err;

	bsp_plat_dat = (struct leipzig_dwmac_plat_data *)priv->plat->bsp_priv;

	clk_disable_unprepare(bsp_plat_dat->clk_eqosc_rmii);
	clk_disable_unprepare(bsp_plat_dat->clk_eqosc_rx);
	clk_disable_unprepare(bsp_plat_dat->clk_eqosc_tx);
	clk_disable_unprepare(bsp_plat_dat->mem_pwr_eqosc);

	if (bsp_plat_dat->regulator) {
		err = regulator_disable(bsp_plat_dat->regulator);
		if (err)
			dev_warn(&pdev->dev, "Failed to disable regulator: %d\n", err);
	}
	return 0;
}

#define SDMEMCOMPPADCTRL 0x8800
#define  SDMEMCOMPPADCTRL_PAD_E_INPUT_OR_E_PWRD BIT(31)

#define AUTO_CAL_CONFIG 0x8804
#define  AUTO_CAL_CONFIG_START BIT(31)
#define  AUTO_CAL_CONFIG_ENABLE BIT(29)

#define AUTO_CAL_STATUS 0x880c
#define  AUTO_CAL_STATUS_ACTIVE BIT(31)

struct dwc_eth_dwmac_data {
	int (*probe)(struct platform_device *pdev,
		     struct plat_stmmacenet_data *data,
		     struct stmmac_resources *res);
	int (*remove)(struct platform_device *pdev);
};

static const struct dwc_eth_dwmac_data dwmac_leipzig_data = {
	.probe = dwc_qos_probe,
	.remove = dwc_qos_remove,
};

/* leipzig board-specific Ethernet Interface initializations. */
static int leipzig_set_mode(struct regmap *regmap,
			    struct stmmac_resources *stmmac_res,
			    struct plat_stmmacenet_data *plat)
{
	u32 val = 0;
	struct leipzig_dwmac_plat_data *bsp_plat_dat;

	bsp_plat_dat = (struct leipzig_dwmac_plat_data *)plat->bsp_priv;

	switch (plat->interface) {
	case PHY_INTERFACE_MODE_MII:
		val = SYSC_EQOSC_MII_MODE;
		plat->max_speed = 100;
		break;
	case PHY_INTERFACE_MODE_RGMII:
	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		val = SYSC_EQOS_RGMII_1000M_MODE;
		if (bsp_plat_dat->regulator)
			regulator_set_voltage(bsp_plat_dat->regulator,
					      2500000, 2500000);
		plat->max_speed = 1000;
		break;
	case PHY_INTERFACE_MODE_RMII:
		val = SYSC_EQOS_RMII_50OUT_100M_MODE;
		plat->max_speed = 100;
		break;
	default:
		break;
	}
	regmap_write(regmap, SYSC_EQOS_CTRL, val);

	/* reset eqos controller */
	writel(readl(stmmac_res->addr + DMA_BUS_MODE) |
	       DMA_BUS_MODE_SFT_RESET,
	       stmmac_res->addr + DMA_BUS_MODE);

	return 0;
}

static void leipzig_dwmac_fix_speed(void *priv, unsigned int speed)
{
	struct leipzig_dwmac_plat_data *bsp_plat_dat;
	u32 val = 0;

	bsp_plat_dat = (struct leipzig_dwmac_plat_data *)priv;

	switch (bsp_plat_dat->plat->interface) {
	case PHY_INTERFACE_MODE_RGMII:
	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		switch (speed) {
		case SPEED_1000:
			val = SYSC_EQOS_RGMII_1000M_MODE;
			bsp_plat_dat->plat->max_speed = 1000;
			break;
		case SPEED_100:
			val = SYSC_EQOS_RGMII_100M_MODE;
			bsp_plat_dat->plat->max_speed = 100;
			break;
		case SPEED_10:
			val = SYSC_EQOS_RGMII_10M_MODE;
			bsp_plat_dat->plat->max_speed = 10;
			break;
		}
		if (bsp_plat_dat->regulator)
			regulator_set_voltage(bsp_plat_dat->regulator,
					      2500000, 2500000);
		break;
	case PHY_INTERFACE_MODE_RMII:
		switch (speed) {
		case SPEED_100:
			val = SYSC_EQOS_RMII_50OUT_100M_MODE;
			bsp_plat_dat->plat->max_speed = 100;
			break;
		case SPEED_10:
			val = SYSC_EQOS_RMII_50OUT_10M_MODE;
			bsp_plat_dat->plat->max_speed = 10;
			break;
		}
		break;
	case PHY_INTERFACE_MODE_MII:
		switch (speed) {
		case SPEED_100:
			val = SYSC_EQOSC_MII_MODE;
			bsp_plat_dat->plat->max_speed = 100;
			break;
		case SPEED_10:
			val = SYSC_EQOSC_MII_MODE;
			bsp_plat_dat->plat->max_speed = 10;
			break;
		}
		break;
	default:
		break;
	}
	regmap_write(bsp_plat_dat->regmap, SYSC_EQOS_CTRL, val);
}

static int dwc_eth_dwmac_probe(struct platform_device *pdev)
{
	const struct dwc_eth_dwmac_data *data;
	struct plat_stmmacenet_data *plat_dat;
	struct leipzig_dwmac_plat_data *bsp_plat_dat;
	struct stmmac_resources stmmac_res;
	struct device *dev = &pdev->dev;
	struct regmap *sysc_regmap;
	int ret;

	data = device_get_match_data(&pdev->dev);

	memset(&stmmac_res, 0, sizeof(struct stmmac_resources));

	/**
	 * Since stmmac_platform supports name IRQ only, basic platform
	 * resource initialization is done in the glue logic.
	 */
	stmmac_res.irq = platform_get_irq(pdev, 0);
	if (stmmac_res.irq < 0)
		return stmmac_res.irq;
	stmmac_res.wol_irq = stmmac_res.irq;

	stmmac_res.addr = devm_platform_ioremap_resource(pdev, 0);
	if (IS_ERR(stmmac_res.addr))
		return PTR_ERR(stmmac_res.addr);

	sysc_regmap = syscon_regmap_lookup_by_phandle(dev->of_node,
						      "sysc-regmap");

	plat_dat = stmmac_probe_config_dt(pdev, stmmac_res.mac);
	if (IS_ERR(plat_dat))
		return PTR_ERR(plat_dat);

	bsp_plat_dat = devm_kzalloc(&pdev->dev, sizeof(*bsp_plat_dat), GFP_KERNEL);
	if (!bsp_plat_dat) {
		ret = -ENOMEM;
		goto remove;
	}
	bsp_plat_dat->regmap = sysc_regmap;
	bsp_plat_dat->stmmac_res = &stmmac_res;
	bsp_plat_dat->plat = plat_dat;
	plat_dat->bsp_priv = (void *)bsp_plat_dat;

	/* if finding phy_mode of early param, overwrite phy_mode */
	if (early_phymod != PHY_INTERFACE_MODE_NA) {
		plat_dat->interface = early_phymod;
		plat_dat->phy_interface = early_phymod;
	}

	ret = data->probe(pdev, plat_dat, &stmmac_res);
	if (ret < 0) {
		dev_err_probe(&pdev->dev, ret, "failed to probe subdriver\n");

		goto remove_config;
	}

	ret = leipzig_set_mode(sysc_regmap, &stmmac_res, plat_dat);

	ret = dwc_eth_dwmac_config_dt(pdev, plat_dat);
	if (ret)
		goto remove;

	ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
	if (ret)
		goto remove;

	plat_dat->fix_mac_speed = leipzig_dwmac_fix_speed;

	return ret;

remove:
	data->remove(pdev);
remove_config:
	stmmac_remove_config_dt(pdev, plat_dat);

	return ret;
}

/* early_param wrapper for setup_phymode() */
static int __init param_setup_phymode(char *buf)
{
	int i;

	if (!buf)
		return 0;

	for (i = (PHY_INTERFACE_MODE_NA + 1); i < PHY_INTERFACE_MODE_MAX; i++) {
		if (!strcasecmp(phy_modes(i), buf)) {
			early_phymod = i;
			break;
		}
	}

	switch (early_phymod) {
	case PHY_INTERFACE_MODE_MII:
	case PHY_INTERFACE_MODE_RMII:
	case PHY_INTERFACE_MODE_RGMII:
	case PHY_INTERFACE_MODE_RGMII_ID:
	case PHY_INTERFACE_MODE_RGMII_RXID:
	case PHY_INTERFACE_MODE_RGMII_TXID:
		break;
	default:
		pr_debug("PHY mode %s is Unsupported, use DTS one\n", buf);
		early_phymod = PHY_INTERFACE_MODE_NA;
	}
	pr_debug("early param : cmdline PHY Mode: %s\n", phy_modes(early_phymod));

	return 0;
}

early_param("phy_mode", param_setup_phymode);

static int dwc_eth_dwmac_remove(struct platform_device *pdev)
{
	struct net_device *ndev = platform_get_drvdata(pdev);
	struct stmmac_priv *priv = netdev_priv(ndev);
	const struct dwc_eth_dwmac_data *data;
	int err;

	data = device_get_match_data(&pdev->dev);

	err = stmmac_dvr_remove(&pdev->dev);
	if (err < 0)
		dev_err(&pdev->dev, "failed to remove platform: %d\n", err);

	err = data->remove(pdev);
	if (err < 0)
		dev_err(&pdev->dev, "failed to remove subdriver: %d\n", err);

	devm_kfree(&pdev->dev, priv->plat->bsp_priv);

	stmmac_remove_config_dt(pdev, priv->plat);

	return err;
}

static const struct of_device_id dwmac_leipzig_match[] = {
	{ .compatible = "snps,dwmac-leipzig", .data = &dwmac_leipzig_data },
	{ }
};
MODULE_DEVICE_TABLE(of, dwmac_leipzig_match);

static struct platform_driver dwmac_leipzig_driver = {
	.probe  = dwc_eth_dwmac_probe,
	.remove = dwc_eth_dwmac_remove,
	.driver = {
		.name           = "dwmac-leipzig",
		.pm             = &stmmac_pltfr_pm_ops,
		.of_match_table = dwmac_leipzig_match,
	},
};
module_platform_driver(dwmac_leipzig_driver);

MODULE_AUTHOR("Joao Pinto <jpinto@synopsys.com>");
MODULE_DESCRIPTION("Synopsys DWC Ethernet Quality-of-Service v4.10a driver");
MODULE_LICENSE("GPL v2");

// SPDX-License-Identifier: GPL-2.0
/*
 * Pinctrl data for the VATICS Leipzig pinmux
 *
 * Copyright (c) 2016-2021, VATICS CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/pinctrl/pinctrl.h>
#include <linux/pinctrl/pinmux.h>
#include <linux/pinctrl/machine.h>
#include <linux/pinctrl/pinconf.h>
#include <linux/pinctrl/pinconf-generic.h>
#include <linux/bitmap.h>
#include <linux/slab.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>
#include <soc/vtx/pinctrl.h>

#include "core.h"
#include "pinconf.h"
#include "pinctrl-utils.h"
#include "pinctrl-leipzig.h"


#define CLEAR_OFFSET			4
DEFINE_SPINLOCK(pinmux_lock);

struct leipzig_group_desc {
	const char *name;
	const unsigned int *pins;
	const unsigned int npins;
	const unsigned int en_ofs;
	const unsigned int bit;
	const unsigned int sts_ofs;
	const short int *confl_grps;
	const u8 nconfl_grps;
};

struct leipzig_function_desc {
	const char *name;
	const char * const *grps;
	unsigned int ngrps;
};

struct leipzig_pinctrl_dev_data {
	const char *name;
	unsigned int ngpios;
	const struct pinctrl_pin_desc *pins;
	unsigned int npins;
	const struct leipzig_group_desc *grps;
	unsigned int ngrps;
	const struct leipzig_function_desc *funcs;
	unsigned int nfuncs;
};

struct leipzig_pinctrl {
	struct device *dev;
	struct pinctrl_dev *pctldev;
	struct regmap *regmap;
	const struct leipzig_pinctrl_dev_data *devdata;
};

static struct pinctrl_gpio_range leipzig_pctl_gpio_range = {
	.name = "Leipzig-gpio-pin",
	.id = 0,
	.base = 0,
};

#define LEIPZIG_PIN(_name, _type_data) \
	[_name] = { \
		.name = #_name, \
		.number = _name, \
		.drv_data = (void *) &_type_data, \
}

static const struct pinctrl_pin_desc leipzig_pins[] = {
	/* INOUT */
	LEIPZIG_PIN(INOUT_39, inout_39_pintype),
	LEIPZIG_PIN(INOUT_40, inout_40_pintype),
	LEIPZIG_PIN(INOUT_41, inout_41_pintype),
	LEIPZIG_PIN(INOUT_42, inout_42_pintype),
	LEIPZIG_PIN(INOUT_43, inout_43_pintype),
	LEIPZIG_PIN(INOUT_44, inout_44_pintype),
	LEIPZIG_PIN(INOUT_45, inout_45_pintype),
	LEIPZIG_PIN(INOUT_46, inout_46_pintype),
	LEIPZIG_PIN(INOUT_47, inout_47_pintype),
	LEIPZIG_PIN(INOUT_48, inout_48_pintype),
	LEIPZIG_PIN(INOUT_49, inout_49_pintype),
	LEIPZIG_PIN(INOUT_50, inout_50_pintype),
	LEIPZIG_PIN(INOUT_51, inout_51_pintype),
	LEIPZIG_PIN(INOUT_52, inout_52_pintype),
	LEIPZIG_PIN(INOUT_53, inout_53_pintype),
	LEIPZIG_PIN(INOUT_54, inout_54_pintype),
	LEIPZIG_PIN(INOUT_55, inout_55_pintype),
	LEIPZIG_PIN(INOUT_56, inout_56_pintype),
	LEIPZIG_PIN(INOUT_57, inout_57_pintype),
	LEIPZIG_PIN(INOUT_58, inout_58_pintype),
	LEIPZIG_PIN(INOUT_59, inout_59_pintype),
	LEIPZIG_PIN(INOUT_60, inout_60_pintype),
	LEIPZIG_PIN(INOUT_61, inout_61_pintype),
	LEIPZIG_PIN(INOUT_62, inout_62_pintype),
	LEIPZIG_PIN(INOUT_63, inout_63_pintype),
	LEIPZIG_PIN(INOUT_64, inout_64_pintype),
	LEIPZIG_PIN(INOUT_65, inout_65_pintype),
	LEIPZIG_PIN(INOUT_66, inout_66_pintype),
	LEIPZIG_PIN(INOUT_67, inout_67_pintype),
	LEIPZIG_PIN(INOUT_68, inout_68_pintype),
	LEIPZIG_PIN(INOUT_69, inout_69_pintype),
	LEIPZIG_PIN(INOUT_70, inout_70_pintype),
	LEIPZIG_PIN(INOUT_71, inout_71_pintype),
	LEIPZIG_PIN(INOUT_72, inout_72_pintype),
	LEIPZIG_PIN(INOUT_73, inout_73_pintype),
	LEIPZIG_PIN(INOUT_74, inout_74_pintype),
	LEIPZIG_PIN(INOUT_75, inout_75_pintype),
	LEIPZIG_PIN(INOUT_76, inout_76_pintype),
	LEIPZIG_PIN(INOUT_77, inout_77_pintype),
	LEIPZIG_PIN(INOUT_78, inout_78_pintype),
	LEIPZIG_PIN(INOUT_79, inout_79_pintype),
	LEIPZIG_PIN(INOUT_80, inout_80_pintype),
	LEIPZIG_PIN(INOUT_81, inout_81_pintype),
	LEIPZIG_PIN(INOUT_82, inout_82_pintype),
	LEIPZIG_PIN(INOUT_83, inout_83_pintype),
	LEIPZIG_PIN(INOUT_84, inout_84_pintype),
	LEIPZIG_PIN(INOUT_85, inout_85_pintype),
	LEIPZIG_PIN(INOUT_86, inout_86_pintype),
	LEIPZIG_PIN(INOUT_87, inout_87_pintype),
	LEIPZIG_PIN(INOUT_88, inout_88_pintype),
	LEIPZIG_PIN(INOUT_89, inout_89_pintype),
	LEIPZIG_PIN(INOUT_90, inout_90_pintype),
	LEIPZIG_PIN(INOUT_91, inout_91_pintype),
	LEIPZIG_PIN(INOUT_92, inout_92_pintype),
	LEIPZIG_PIN(INOUT_93, inout_93_pintype),
	LEIPZIG_PIN(INOUT_94, inout_94_pintype),
	LEIPZIG_PIN(INOUT_95, inout_95_pintype),
	LEIPZIG_PIN(INOUT_0, inout_0_pintype),
	LEIPZIG_PIN(INOUT_1, inout_1_pintype),
	LEIPZIG_PIN(INOUT_2, inout_2_pintype),
	LEIPZIG_PIN(INOUT_3, inout_3_pintype),
	LEIPZIG_PIN(INOUT_4, inout_4_pintype),
	LEIPZIG_PIN(INOUT_5, inout_5_pintype),
	LEIPZIG_PIN(INOUT_6, inout_6_pintype),
	LEIPZIG_PIN(INOUT_7, inout_7_pintype),
	LEIPZIG_PIN(INOUT_8, inout_8_pintype),
	LEIPZIG_PIN(INOUT_9, inout_9_pintype),
	LEIPZIG_PIN(INOUT_10, inout_10_pintype),
	LEIPZIG_PIN(INOUT_11, inout_11_pintype),
	LEIPZIG_PIN(INOUT_12, inout_12_pintype),
	LEIPZIG_PIN(INOUT_13, inout_13_pintype),
	LEIPZIG_PIN(INOUT_14, inout_14_pintype),
	LEIPZIG_PIN(INOUT_15, inout_15_pintype),
	LEIPZIG_PIN(INOUT_16, inout_16_pintype),
	LEIPZIG_PIN(INOUT_17, inout_17_pintype),
	LEIPZIG_PIN(INOUT_18, inout_18_pintype),
	LEIPZIG_PIN(INOUT_19, inout_19_pintype),
	LEIPZIG_PIN(INOUT_20, inout_20_pintype),
	LEIPZIG_PIN(INOUT_21, inout_21_pintype),
	LEIPZIG_PIN(INOUT_22, inout_22_pintype),
	LEIPZIG_PIN(INOUT_23, inout_23_pintype),
	LEIPZIG_PIN(INOUT_24, inout_24_pintype),
	LEIPZIG_PIN(INOUT_25, inout_25_pintype),
	LEIPZIG_PIN(INOUT_26, inout_26_pintype),
	LEIPZIG_PIN(INOUT_27, inout_27_pintype),
	LEIPZIG_PIN(INOUT_28, inout_28_pintype),
	LEIPZIG_PIN(INOUT_29, inout_29_pintype),
	LEIPZIG_PIN(INOUT_30, inout_30_pintype),
	LEIPZIG_PIN(INOUT_31, inout_31_pintype),
	LEIPZIG_PIN(INOUT_32, inout_32_pintype),
	LEIPZIG_PIN(INOUT_33, inout_33_pintype),
	LEIPZIG_PIN(INOUT_34, inout_34_pintype),
	LEIPZIG_PIN(INOUT_35, inout_35_pintype),
	LEIPZIG_PIN(INOUT_36, inout_36_pintype),
	LEIPZIG_PIN(INOUT_37, inout_37_pintype),
	LEIPZIG_PIN(INOUT_38, inout_38_pintype),
	/* OUTPUT */
	LEIPZIG_PIN(OUTPUT_0, output_0_pintype),
	LEIPZIG_PIN(OUTPUT_1, output_1_pintype),
	LEIPZIG_PIN(OUTPUT_2, output_2_pintype),
	LEIPZIG_PIN(OUTPUT_3, output_3_pintype),
	LEIPZIG_PIN(OUTPUT_4, output_4_pintype),
	LEIPZIG_PIN(OUTPUT_5, output_5_pintype),
	/* INPUT */
	LEIPZIG_PIN(INPUT_0, input_0_pintype),
	LEIPZIG_PIN(INPUT_1, input_1_pintype),
	LEIPZIG_PIN(INPUT_2, input_2_pintype),
	LEIPZIG_PIN(INPUT_3, input_3_pintype),
	LEIPZIG_PIN(INPUT_4, input_4_pintype),
	LEIPZIG_PIN(INPUT_5, input_5_pintype),
	LEIPZIG_PIN(INPUT_6, input_6_pintype),
	LEIPZIG_PIN(INPUT_7, input_7_pintype),
	LEIPZIG_PIN(INPUT_8, input_8_pintype),
	LEIPZIG_PIN(INPUT_9, input_9_pintype),
};

DECLARE_BITMAP(allpins, ARRAY_SIZE(leipzig_pins));

/* DEBUG */
static const unsigned int scrtu_dbg_pins[] = {
	INOUT_91,
	INOUT_92,
	INOUT_93,
	INOUT_94,
	INOUT_95,
};

static const unsigned int ca55u_dbg_pins[] = {
	INOUT_59,
	INOUT_60,
};

static const unsigned int usb30c_dbg_pins[] = {
	INOUT_91,
	INOUT_92,
	INOUT_93,
	INOUT_94,
	INOUT_95,
};

static const unsigned int vq7u_dbg_pins[] = {
	INOUT_15,
	INOUT_16,
	INOUT_17,
	INOUT_18,
	INOUT_19,
};

/* SSIC */
static const unsigned int ssic3_sgl_ma_pins[] = {
	INOUT_52,
	//INOUT_53, //for gpio control cs
	INOUT_54,
	INOUT_55,
};

static const unsigned int ssic2_sgl_ma_pins[] = {
	INOUT_35,
	//INOUT_36, //for gpio control cs
	INOUT_37,
	INOUT_38,
};

static const unsigned int ssic1_sgl_ma_pins[] = {
	INOUT_8,
	INOUT_9,
	INOUT_10,
	INOUT_11,
};

static const unsigned int ssic0_sgl_sla_pins[] = {
	INOUT_4,
	INOUT_5,
	INOUT_6,
	INOUT_7,
};

static const unsigned int ssic0_sgl_ma_pins[] = {
	INOUT_4,
	INOUT_5,
	INOUT_6,
	INOUT_7,
};

static const unsigned int ssic0_quad_ma_pins[] = {
	INOUT_1,
	INOUT_2,
	//INOUT_3, //for gpio control cs
	INOUT_4,
	INOUT_5,
	INOUT_6,
	INOUT_7,
};

/* MSHC */
static const unsigned int mshc_pins[] = {
	INOUT_89,
	//INOUT_90, //for gpio control write_prot
};

/* MONITOR CLK */
static const unsigned int monitor_clk_pins[] = {
	INOUT_58,
};

/* IRDAC */
static const unsigned int irdac_pins[] = {
	INOUT_0,
};

/* I2SSC */
static const unsigned int i2ssc_tx_sla_pins[] = {
	INOUT_14,
	INOUT_15,
	INOUT_16,
};

static const unsigned int i2ssc_tx_ma_pins[] = {
	INOUT_14,
	INOUT_15,
	INOUT_16,
};

static const unsigned int i2ssc_rx_sla_pins[] = {
	INOUT_17,
	INOUT_18,
	INOUT_19,
};

static const unsigned int i2ssc_rx_ma_pins[] = {
	INOUT_17,
	INOUT_18,
	INOUT_19,
};

static const unsigned int i2ssc_ma_clk_pins[] = {
	OUTPUT_0,
};

/* I2C */
static const unsigned int i2cc2_pos1_pins[] = {
	INOUT_54,
	INOUT_55,
};

static const unsigned int i2cc2_pos0_pins[] = {
	INOUT_56,
	INOUT_57,
};

static const unsigned int i2cc1_pos1_pins[] = {
	INOUT_37,
	INOUT_38,
};
static const unsigned int i2cc1_pos0_pins[] = {
	INOUT_20,
	INOUT_21,
};

static const unsigned int i2cc0_pins[] = {
	INOUT_12,
	INOUT_13,
};

/* EQOSC */
static const unsigned int eqosc_tx_out_clk_pins[] = {
	OUTPUT_3,
};

static const unsigned int eqosc_tx_in_clk_pins[] = {
	INOUT_78,
};

static const unsigned int eqosc_rx_clk_pins[] = {
	INOUT_73,
};

static const unsigned int eqosc_ref_clk_pins[] = {
	OUTPUT_4,
};

static const unsigned int eqosc_sec3_pins[] = {
	INOUT_71,
	INOUT_80,
	INOUT_87,
	INOUT_88,
};

static const unsigned int eqosc_sec2_pins[] = {
	INOUT_76,
	INOUT_77,
	INOUT_83,
	INOUT_84,
};

static const unsigned int eqosc_sec1_pins[] = {
	INOUT_85,
	INOUT_86,
};

static const unsigned int eqosc_sec0_pins[] = {
	INOUT_72,
	INOUT_74,
	INOUT_75,
	INOUT_79,
	INOUT_81,
	INOUT_82,
};

/* DDRNSDMC */
static const unsigned int ddrnsdmc_test_pins[] = {
	INOUT_0,
};

/* ADCDCC */
static const unsigned int adcdcc_pins[] = {
	INOUT_17,
	INOUT_18,
	INOUT_19,
};

/* USB */
static const unsigned int usb30c_vbus_oc_pins[] = {
	INOUT_93,
};

static const unsigned int usb30c_drv_vbus_pins[] = {
	INOUT_94,
};

static const unsigned int usb20c_vbus_oc_pins[] = {
	INOUT_91,
};

static const unsigned int usb20c_drv_vbus_pins[] = {
	INOUT_92,
};

/* UART4 */
static const unsigned int uart4_pos2_pins[] = {
	INOUT_2,
	INOUT_3,
};

static const unsigned int uart4_pos1_pins[] = {
	INOUT_48,
	INOUT_49,
};

static const unsigned int uart4_pos0_pins[] = {
	INOUT_69,
	INOUT_70,
};

/* UART3 */
static const unsigned int uart3_pos2_pins[] = {
	INOUT_93,
	INOUT_94,
};

static const unsigned int uart3_pos1_pins[] = {
	INOUT_45,
	INOUT_46,
};

static const unsigned int uart3_pos0_pins[] = {
	INOUT_67,
	INOUT_68,
};

/* UART2 */
static const unsigned int uart2_pos2_pins[] = {
	INOUT_91,
	INOUT_92,
};

static const unsigned int uart2_pos1_pins[] = {
	INOUT_41,
	INOUT_42,
};

static const unsigned int uart2_pos0_pins[] = {
	INOUT_63,
	INOUT_64,
};

/* UART1 */
static const unsigned int uart1_pos2_sec1_pins[] = {
	INOUT_2,
	INOUT_3,
};

static const unsigned int uart1_pos2_sec0_pins[] = {
	INOUT_0,
	INOUT_1,
};

static const unsigned int uart1_pos1_sec1_pins[] = {
	INOUT_45,
	INOUT_46,
};

static const unsigned int uart1_pos1_sec0_pins[] = {
	INOUT_43,
	INOUT_44,
};

static const unsigned int uart1_pos0_sec1_pins[] = {
	INOUT_67,
	INOUT_68,
};

static const unsigned int uart1_pos0_sec0_pins[] = {
	INOUT_65,
	INOUT_66,
};

/* UART0 */
static const unsigned int uart0_pos2_sec1_pins[] = {
	INOUT_91,
	INOUT_92,
};

static const unsigned int uart0_pos2_sec0_pins[] = {
	INOUT_89,
	INOUT_90,
};

static const unsigned int uart0_pos1_sec1_pins[] = {
	INOUT_41,
	INOUT_42,
};

static const unsigned int uart0_pos1_sec0_pins[] = {
	INOUT_39,
	INOUT_40,
};

static const unsigned int uart0_pos0_sec1_pins[] = {
	INOUT_63,
	INOUT_64,
};

static const unsigned int uart0_pos0_sec0_pins[] = {
	INOUT_61,
	INOUT_62,
};

/* WDTC */
static const unsigned int wdtc_pins[] = {
	OUTPUT_2,
};

/* VOC */
static const unsigned int voc1_sec7_pos1_pins[] = {
	INOUT_62,
};

static const unsigned int voc1_sec7_pos0_pins[] = {
	OUTPUT_3,
};

static const unsigned int voc1_sec6_pins[] = {
	INOUT_63,
	INOUT_64,
	INOUT_65,
	INOUT_66,
};

static const unsigned int voc1_sec5_pins[] = {
	INOUT_67,
	INOUT_68,
	INOUT_69,
	INOUT_70,
};

static const unsigned int voc1_sec4_pins[] = {
	INOUT_79,
	INOUT_85,
	INOUT_86,
};

static const unsigned int voc1_sec3_pos1_pins[] = {
	INOUT_68,
};

static const unsigned int voc1_sec3_pos0_pins[] = {
	INOUT_72,
};

static const unsigned int voc1_sec2_pos1_pins[] = {
	INOUT_69,
	INOUT_70,
	INOUT_71,
	INOUT_80,
};

static const unsigned int voc1_sec2_pos0_pins[] = {
	INOUT_74,
	INOUT_75,
	INOUT_81,
	INOUT_82,
};

static const unsigned int voc1_sec1_pins[] = {
	INOUT_73,
	INOUT_76,
	INOUT_77,
	INOUT_78,
	INOUT_83,
	INOUT_84,
	INOUT_87,
	INOUT_88,
};

static const unsigned int voc1_sec0_pins[] = {
	INOUT_71,
	INOUT_80,
};

static const unsigned int voc1_clk_pos1_pins[] = {
	INOUT_61,
};

static const unsigned int voc1_clk_pos0_pins[] = {
	OUTPUT_4,
};

/* VIC */
static const unsigned int vic1_sec5_pins[] = {
	INOUT_54,
	INOUT_55,
};

static const unsigned int vic1_sec4_pins[] = {
	INOUT_52,
	INOUT_53,
};

static const unsigned int vic1_sec3_pins[] = {
	INOUT_50,
	INOUT_51,
};

static const unsigned int vic1_sec2_pins[] = {
	INOUT_48,
	INOUT_49,
};

static const unsigned int vic1_sec1_pins[] = {
	INOUT_56,
	INOUT_57,
};

static const unsigned int vic1_sec0_pins[] = {
	INOUT_39,
	INOUT_40,
	INOUT_41,
	INOUT_42,
	INOUT_43,
	INOUT_44,
	INOUT_45,
	INOUT_46,
	INOUT_47,
};

static const unsigned int vic0_sec5_pins[] = {
	INOUT_37,
	INOUT_38,
};

static const unsigned int vic0_sec4_pins[] = {
	INOUT_35,
	INOUT_36,
};

static const unsigned int vic0_sec3_pins[] = {
	INOUT_33,
	INOUT_34,
};

static const unsigned int vic0_sec2_pins[] = {
	INOUT_31,
	INOUT_32,
};

static const unsigned int vic0_sec1_pins[] = {
	INOUT_20,
	INOUT_21,
};

static const unsigned int vic0_sec0_pins[] = {
	INOUT_22,
	INOUT_23,
	INOUT_24,
	INOUT_25,
	INOUT_26,
	INOUT_27,
	INOUT_28,
	INOUT_29,
	INOUT_30,
};

static const unsigned int vic_ref_sync_pins[] = {
	INOUT_35,
	INOUT_36,
};

static const unsigned int vic_ref_clk_pins[] = {
	OUTPUT_1,
};

/* conflict groups */
static const short int scrtu_dbg_confl_grps[] = {
	UART2_POS2,
	UART3_POS2,
	UART0_POS2_SEC1,
	USB20C_VBUS_OC,
	USB20C_DRV_VBUS,
	USB30C_VBUS_OC,
	USB30C_DRV_VBUS,
	USB30C_DBG,
	GPIO1_DATA20,
	GPIO1_DATA21,
	GPIO1_DATA22,
	GPIO1_DATA23,
	GPIO1_DATA24,
};

static const short int ca55u_dbg_confl_grps[] = {
	GPIO0_DATA20,
	GPIO0_DATA21,
	AGPO0_POS3,
	AGPO1_POS3,
};

static const short int usb30c_dbg_confl_grps[] = {
	SCRTU_DBG,
	UART2_POS2,
	UART3_POS2,
	UART0_POS2_SEC1,
	USB20C_VBUS_OC,
	USB20C_DRV_VBUS,
	USB30C_VBUS_OC,
	USB30C_DRV_VBUS,
	GPIO1_DATA20,
	GPIO1_DATA21,
	GPIO1_DATA22,
	GPIO1_DATA23,
	GPIO1_DATA24,

};

static const short int vq7u_dbg_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	ADCDCC,
	GPIO2_DATA8,
	GPIO2_DATA9,
	GPIO2_DATA10,
	GPIO2_DATA11,
	GPIO2_DATA12,
	AGPO8_POS0,
	AGPO9_POS0,
	AGPO10_POS0,
	AGPO11_POS0,
};

static const short int ssic3_sgl_ma_confl_grps[] = {
	GPIO0_DATA13,
	//GPIO0_DATA14, //for gpio control cs
	GPIO0_DATA15,
	GPIO0_DATA16,
	VIC1_SEC4,
	VIC1_SEC5,
	I2CC2_POS1,
};

static const short int ssic2_sgl_ma_confl_grps[] = {
	VIC0_SEC4,
	VIC0_SEC5,
	VIC_REF_SYNC,
	I2CC1_POS1,
	GPIO2_DATA28,
	//GPIO2_DATA29, //for gpio control cs
	GPIO2_DATA30,
	GPIO2_DATA31,
};

static const short int ssic1_sgl_ma_confl_grps[] = {
	GPIO2_DATA1,
	GPIO2_DATA2,
	GPIO2_DATA3,
	GPIO2_DATA4,
	AGPO1_POS0,
	AGPO2_POS0,
	AGPO3_POS0,
	AGPO4_POS0,
};

static const short int ssic0_sgl_sla_confl_grps[] = {
	SSIC0_QUAD_MA,
	SSIC0_SGL_MA,
	GPIO1_DATA29,
	GPIO1_DATA30,
	GPIO1_DATA31,
	GPIO2_DATA0,
};

static const short int ssic0_sgl_ma_confl_grps[] = {
	SSIC0_QUAD_MA,
	SSIC0_SGL_SLA,
	GPIO1_DATA29,
	GPIO1_DATA30,
	GPIO1_DATA31,
	GPIO2_DATA0,
};

static const short int ssic0_quad_ma_confl_grps[] = {
	UART1_POS2_SEC0,
	UART4_POS2,
	UART1_POS2_SEC1,
	SSIC0_SGL_MA,
	SSIC0_SGL_SLA,
	GPIO1_DATA26,
	GPIO1_DATA27,
	//GPIO1_DATA28, //for gpio control cs
	GPIO1_DATA29,
	GPIO1_DATA30,
	GPIO1_DATA31,
	GPIO2_DATA0,
};

static const short int mshc_confl_grps[] = {
	UART0_POS2_SEC0,
	GPIO1_DATA18,
	//GPIO1_DATA19, //for gpio control write_prot
};

static const short int monitor_clk_confl_grps[] = {
	GPIO0_DATA19,
};

static const short int irdac_confl_grps[] = {
	UART1_POS2_SEC0,
	DDRNSDMC_TEST,
	GPIO1_DATA25,
	AGPO0_POS0,
};

static const short int i2ssc_tx_sla_confl_grps[] = {
	I2SSC_TX_MA,
	VQ7U_DBG,
	GPIO2_DATA7,
	GPIO2_DATA8,
	GPIO2_DATA9,
	AGPO7_POS0,
	AGPO8_POS0,
	AGPO9_POS0,
};

static const short int i2ssc_tx_ma_confl_grps[] = {
	I2SSC_TX_SLA,
	VQ7U_DBG,
	GPIO2_DATA7,
	GPIO2_DATA8,
	GPIO2_DATA9,
	AGPO7_POS0,
	AGPO8_POS0,
	AGPO9_POS0,
};

static const short int i2ssc_rx_sla_confl_grps[] = {
	I2SSC_RX_MA,
	VQ7U_DBG,
	ADCDCC,
	GPIO2_DATA10,
	GPIO2_DATA11,
	GPIO2_DATA12,
	AGPO10_POS0,
	AGPO11_POS0,
};

static const short int i2ssc_rx_ma_confl_grps[] = {
	I2SSC_RX_SLA,
	VQ7U_DBG,
	ADCDCC,
	GPIO2_DATA10,
	GPIO2_DATA11,
	GPIO2_DATA12,
	AGPO10_POS0,
	AGPO11_POS0,
};

static const short int i2ssc_ma_clk_confl_grps[] = {
	-1,
};

static const short int i2cc2_pos1_confl_grps[] = {
	GPIO0_DATA15,
	GPIO0_DATA16,
	VIC1_SEC5,
	SSIC3_SGL_MA,
};

static const short int i2cc2_pos0_confl_grps[] = {
	GPIO0_DATA17,
	GPIO0_DATA18,
	VIC1_SEC1,
};

static const short int i2cc1_pos1_confl_grps[] = {
	VIC0_SEC5,
	SSIC2_SGL_MA,
	GPIO2_DATA30,
	GPIO2_DATA31,
};

static const short int i2cc1_pos0_confl_grps[] = {
	VIC0_SEC1,
	GPIO2_DATA13,
	GPIO2_DATA14,
};

static const short int i2cc0_confl_grps[] = {
	GPIO2_DATA5,
	GPIO2_DATA6,
	AGPO5_POS0,
	AGPO6_POS0,
};

static const short int eqosc_tx_out_clk_confl_grps[] = {
	VOC1_SEC7_POS0,
};

static const short int eqosc_tx_in_clk_confl_grps[] = {
	VOC1_SEC1,
	GPIO1_DATA7,
};

static const short int eqosc_rx_clk_confl_grps[] = {
	VOC1_SEC1,
	GPIO1_DATA2,
};

static const short int eqosc_ref_clk_confl_grps[] = {
	VOC1_CLK_POS0,
};

static const short int eqosc_sec3_confl_grps[] = {
	VOC1_SEC0,
	VOC1_SEC2_POS1,
	GPIO1_DATA0,
	GPIO1_DATA9,
	VOC1_SEC1,
	GPIO1_DATA16,
	GPIO1_DATA17,
	AGPO10_POS4,
	AGPO11_POS4,
};

static const short int eqosc_sec2_confl_grps[] = {
	VOC1_SEC1,
	GPIO1_DATA5,
	GPIO1_DATA6,
	AGPO2_POS4,
	AGPO3_POS4,
	GPIO1_DATA12,
	GPIO1_DATA13,
	AGPO6_POS4,
	AGPO7_POS4,
};

static const short int eqosc_sec1_confl_grps[] = {
	VOC1_SEC4,
	GPIO1_DATA14,
	GPIO1_DATA15,
	AGPO8_POS4,
	AGPO9_POS4,
};

static const short int eqosc_sec0_confl_grps[] = {
	VOC1_SEC3_POS0,
	GPIO1_DATA1,
	VOC1_SEC2_POS0,
	GPIO1_DATA3,
	GPIO1_DATA4,
	AGPO0_POS4,
	AGPO1_POS4,
	VOC1_SEC4,
	GPIO1_DATA8,
	GPIO1_DATA10,
	GPIO1_DATA11,
	AGPO4_POS4,
	AGPO5_POS4,
};

static const short int ddrnsdmc_test_confl_grps[] = {
	IRDAC,
	UART1_POS2_SEC0,
	GPIO1_DATA25,
	AGPO0_POS0,
};

static const short int adcdcc_confl_grps[] = {
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	VQ7U_DBG,
	GPIO2_DATA10,
	GPIO2_DATA11,
	GPIO2_DATA12,
	AGPO10_POS0,
	AGPO11_POS0,
};

static const short int usb30c_vbus_oc_confl_grps[] = {
	SCRTU_DBG,
	UART3_POS2,
	USB30C_DBG,
	GPIO1_DATA22,
};

static const short int usb30c_drv_vbus_confl_grps[] = {
	SCRTU_DBG,
	UART3_POS2,
	USB30C_DBG,
	GPIO1_DATA23,
};

static const short int usb20c_vbus_oc_confl_grps[] = {
	SCRTU_DBG,
	UART2_POS2,
	UART0_POS2_SEC1,
	USB30C_DBG,
	GPIO1_DATA20,
};

static const short int usb20c_drv_vbus_confl_grps[] = {
	SCRTU_DBG,
	UART2_POS2,
	UART0_POS2_SEC1,
	USB30C_DBG,
	GPIO1_DATA21,
};

static const short int uart4_pos2_confl_grps[] = {
	SSIC0_QUAD_MA,
	UART1_POS2_SEC1,
	GPIO1_DATA27,
	GPIO1_DATA28,
};

static const short int uart4_pos1_confl_grps[] = {
	GPIO0_DATA9,
	GPIO0_DATA10,
	VIC1_SEC2,
	AGPO8_POS2,
	AGPO9_POS2,
};

static const short int uart4_pos0_confl_grps[] = {
	VOC1_SEC5,
	VOC1_SEC2_POS1,
	GPIO0_DATA30,
	GPIO0_DATA31,
	AGPO10_POS3,
	AGPO11_POS3,
};

static const short int uart3_pos2_confl_grps[] = {
	SCRTU_DBG,
	USB30C_VBUS_OC,
	USB30C_DRV_VBUS,
	USB30C_DBG,
	GPIO1_DATA22,
	GPIO1_DATA23,
};

static const short int uart3_pos1_confl_grps[] = {
	GPIO0_DATA6,
	GPIO0_DATA7,
	VIC1_SEC0,
	UART1_POS1_SEC1,
	AGPO6_POS2,
	AGPO7_POS2,
};

static const short int uart3_pos0_confl_grps[] = {
	VOC1_SEC5,
	VOC1_SEC3_POS1,
	UART1_POS0_SEC1,
	GPIO0_DATA28,
	GPIO0_DATA29,
	AGPO8_POS3,
	AGPO9_POS3,
};

static const short int uart2_pos2_confl_grps[] = {
	SCRTU_DBG,
	UART0_POS2_SEC1,
	USB20C_VBUS_OC,
	USB20C_DRV_VBUS,
	USB30C_DBG,
	GPIO1_DATA20,
	GPIO1_DATA21,
};

static const short int uart2_pos1_confl_grps[] = {
	GPIO0_DATA2,
	GPIO0_DATA3,
	VIC1_SEC0,
	UART0_POS1_SEC1,
	AGPO2_POS2,
	AGPO3_POS2,
};

static const short int uart2_pos0_confl_grps[] = {
	VOC1_SEC6,
	UART0_POS0_SEC1,
	GPIO0_DATA24,
	GPIO0_DATA25,
	AGPO4_POS3,
	AGPO5_POS3,
};

static const short int uart1_pos2_sec1_confl_grps[] = {
	SSIC0_QUAD_MA,
	UART4_POS2,
	GPIO1_DATA27,
	GPIO1_DATA28,
};

static const short int uart1_pos2_sec0_confl_grps[] = {
	IRDAC,
	SSIC0_QUAD_MA,
	DDRNSDMC_TEST,
	GPIO1_DATA25,
	GPIO1_DATA26,
	AGPO0_POS0,
};

static const short int uart1_pos1_sec1_confl_grps[] = {
	GPIO0_DATA6,
	GPIO0_DATA7,
	VIC1_SEC0,
	UART3_POS1,
	AGPO6_POS2,
	AGPO7_POS2,
};

static const short int uart1_pos1_sec0_confl_grps[] = {
	GPIO0_DATA4,
	GPIO0_DATA5,
	VIC1_SEC0,
	AGPO4_POS2,
	AGPO5_POS2,
};

static const short int uart1_pos0_sec1_confl_grps[] = {
	UART3_POS0,
	VOC1_SEC5,
	VOC1_SEC3_POS1,
	GPIO0_DATA28,
	GPIO0_DATA29,
	AGPO8_POS3,
	AGPO9_POS3,
};

static const short int uart1_pos0_sec0_confl_grps[] = {
	VOC1_SEC6,
	GPIO0_DATA26,
	GPIO0_DATA27,
	AGPO6_POS3,
	AGPO7_POS3,
};

static const short int uart0_pos2_sec1_confl_grps[] = {
	SCRTU_DBG,
	UART2_POS2,
	USB20C_VBUS_OC,
	USB20C_DRV_VBUS,
	USB30C_DBG,
	GPIO1_DATA20,
	GPIO1_DATA21,
};

static const short int uart0_pos2_sec0_confl_grps[] = {
	MSHC,
	GPIO1_DATA18,
	GPIO1_DATA19,
};

static const short int uart0_pos1_sec1_confl_grps[] = {
	GPIO0_DATA2,
	GPIO0_DATA3,
	VIC1_SEC0,
	UART2_POS1,
	AGPO2_POS2,
	AGPO3_POS2,
};

static const short int uart0_pos1_sec0_confl_grps[] = {
	GPIO0_DATA0,
	GPIO0_DATA1,
	VIC1_SEC0,
	AGPO0_POS2,
	AGPO1_POS2,
};

static const short int uart0_pos0_sec1_confl_grps[] = {
	UART2_POS0,
	VOC1_SEC6,
	GPIO0_DATA24,
	GPIO0_DATA25,
	AGPO4_POS3,
	AGPO5_POS3,
};

static const short int uart0_pos0_sec0_confl_grps[] = {
	VOC1_CLK_POS1,
	VOC1_SEC7_POS1,
	GPIO0_DATA22,
	GPIO0_DATA23,
	AGPO2_POS3,
	AGPO3_POS3,
};

static const short int wdtc_confl_grps[] = {
	-1,
};

static const short int voc1_sec7_pos1_confl_grps[] = {
	UART0_POS0_SEC0,
	GPIO0_DATA23,
	AGPO3_POS3,
};

static const short int voc1_sec7_pos0_confl_grps[] = {
	EQOSC_TX_OUT_CLK,
};

static const short int voc1_sec6_confl_grps[] = {
	UART2_POS0,
	UART1_POS0_SEC0,
	UART0_POS0_SEC1,
	GPIO0_DATA24,
	GPIO0_DATA25,
	GPIO0_DATA26,
	GPIO0_DATA27,
	AGPO4_POS3,
	AGPO5_POS3,
	AGPO6_POS3,
	AGPO7_POS3,
};

static const short int voc1_sec5_confl_grps[] = {
	UART3_POS0,
	UART4_POS0,
	VOC1_SEC3_POS1,
	VOC1_SEC2_POS1,
	UART1_POS0_SEC1,
	GPIO0_DATA28,
	GPIO0_DATA29,
	GPIO0_DATA30,
	GPIO0_DATA31,
	AGPO8_POS3,
	AGPO9_POS3,
	AGPO10_POS3,
	AGPO11_POS3,
};

static const short int voc1_sec4_confl_grps[] = {
	EQOSC_SEC0,
	GPIO1_DATA8,
	EQOSC_SEC1,
	GPIO1_DATA14,
	GPIO1_DATA15,
	AGPO8_POS4,
	AGPO9_POS4,
};

static const short int voc1_sec3_pos1_confl_grps[] = {
	UART3_POS0,
	VIC1_SEC5,
	UART1_POS0_SEC1,
	GPIO0_DATA29,
	AGPO9_POS3,
};

static const short int voc1_sec3_pos0_confl_grps[] = {
	EQOSC_SEC0,
	GPIO1_DATA1,
};

static const short int voc1_sec2_pos1_confl_grps[] = {
	UART4_POS0,
	EQOSC_SEC3,
	VOC1_SEC5,
	VOC1_SEC0,
	GPIO0_DATA30,
	GPIO0_DATA31,
	GPIO1_DATA0,
	AGPO10_POS3,
	AGPO11_POS3,
	GPIO1_DATA9,
};

static const short int voc1_sec2_pos0_confl_grps[] = {
	EQOSC_SEC0,
	GPIO1_DATA3,
	GPIO1_DATA4,
	AGPO0_POS4,
	AGPO1_POS4,
	GPIO1_DATA10,
	GPIO1_DATA11,
	AGPO4_POS4,
	AGPO5_POS4,
};

static const short int voc1_sec1_confl_grps[] = {
	EQOSC_RX_CLK,
	GPIO1_DATA2,
	EQOSC_SEC2,
	EQOSC_TX_IN_CLK,
	GPIO1_DATA5,
	GPIO1_DATA6,
	GPIO1_DATA7,
	AGPO2_POS4,
	AGPO3_POS4,
	GPIO1_DATA12,
	GPIO1_DATA13,
	AGPO6_POS4,
	AGPO7_POS4,
	EQOSC_SEC3,
	GPIO1_DATA16,
	GPIO1_DATA17,
	AGPO10_POS4,
	AGPO11_POS4,
};

static const short int voc1_sec0_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC2_POS1,
	GPIO1_DATA0,
	GPIO1_DATA9,
};

static const short int voc1_clk_pos1_confl_grps[] = {
	UART0_POS0_SEC0,
	GPIO0_DATA22,
	AGPO2_POS3,
};

static const short int voc1_clk_pos0_confl_grps[] = {
	EQOSC_REF_CLK,
};

static const short int vic1_sec5_confl_grps[] = {
	GPIO0_DATA15,
	GPIO0_DATA16,
	I2CC2_POS1,
	SSIC3_SGL_MA,
};

static const short int vic1_sec4_confl_grps[] = {
	GPIO0_DATA13,
	GPIO0_DATA14,
	SSIC3_SGL_MA,
};

static const short int vic1_sec3_confl_grps[] = {
	GPIO0_DATA11,
	GPIO0_DATA12,
	AGPO10_POS2,
	AGPO11_POS2,
};

static const short int vic1_sec2_confl_grps[] = {
	GPIO0_DATA9,
	GPIO0_DATA10,
	UART4_POS1,
	AGPO8_POS2,
	AGPO9_POS2,
};

static const short int vic1_sec1_confl_grps[] = {
	GPIO0_DATA17,
	GPIO0_DATA18,
	I2CC2_POS0,
};

static const short int vic1_sec0_confl_grps[] = {
	GPIO0_DATA0,
	GPIO0_DATA1,
	GPIO0_DATA2,
	GPIO0_DATA3,
	GPIO0_DATA4,
	GPIO0_DATA5,
	GPIO0_DATA6,
	GPIO0_DATA7,
	GPIO0_DATA8,
	UART0_POS1_SEC0,
	UART2_POS1,
	UART1_POS1_SEC0,
	UART3_POS1,
	UART4_POS1,
	UART0_POS1_SEC1,
	UART1_POS1_SEC1,
	AGPO0_POS2,
	AGPO1_POS2,
	AGPO2_POS2,
	AGPO3_POS2,
	AGPO4_POS2,
	AGPO5_POS2,
	AGPO6_POS2,
	AGPO7_POS2,
};

static const short int vic0_sec5_confl_grps[] = {
	I2CC1_POS1,
	SSIC2_SGL_MA,
	GPIO2_DATA30,
	GPIO2_DATA31,
};

static const short int vic0_sec4_confl_grps[] = {
	VIC_REF_SYNC,
	SSIC2_SGL_MA,
	GPIO2_DATA28,
	GPIO2_DATA29,
};

static const short int vic0_sec3_confl_grps[] = {
	GPIO2_DATA26,
	GPIO2_DATA27,
	AGPO10_POS1,
	AGPO11_POS1,
};

static const short int vic0_sec2_confl_grps[] = {
	GPIO2_DATA24,
	GPIO2_DATA25,
	AGPO8_POS1,
	AGPO9_POS1,
};

static const short int vic0_sec1_confl_grps[] = {
	I2CC1_POS0,
	GPIO2_DATA13,
	GPIO2_DATA14,
};

static const short int vic0_sec0_confl_grps[] = {
	GPIO2_DATA15,
	GPIO2_DATA16,
	GPIO2_DATA17,
	GPIO2_DATA18,
	GPIO2_DATA19,
	GPIO2_DATA20,
	GPIO2_DATA21,
	GPIO2_DATA22,
	GPIO2_DATA23,
	AGPO0_POS1,
	AGPO1_POS1,
	AGPO2_POS1,
	AGPO3_POS1,
	AGPO4_POS1,
	AGPO5_POS1,
	AGPO6_POS1,
	AGPO7_POS1,
};

static const short int vic_ref_sync_confl_grps[] = {
	VIC0_SEC4,
	SSIC2_SGL_MA,
	GPIO2_DATA28,
	GPIO2_DATA29,
};

static const short int vic_ref_clk_confl_grps[] = {
	-1
};


static const short int agpo0_pos0_confl_grps[] = {
	IRDAC,
	UART1_POS2_SEC0,
	DDRNSDMC_TEST,
	GPIO1_DATA25,
};

static const short int agpo1_pos0_confl_grps[] = {
	SSIC1_SGL_MA,
	GPIO2_DATA1,
};

static const short int agpo2_pos0_confl_grps[] = {
	SSIC1_SGL_MA,
	GPIO2_DATA2,
};

static const short int agpo3_pos0_confl_grps[] = {
	SSIC1_SGL_MA,
	GPIO2_DATA3,
};

static const short int agpo4_pos0_confl_grps[] = {
	SSIC1_SGL_MA,
	GPIO2_DATA4,
};

static const short int agpo5_pos0_confl_grps[] = {
	I2CC0,
	GPIO2_DATA5,
};

static const short int agpo6_pos0_confl_grps[] = {
	I2CC0,
	GPIO2_DATA6,
};

static const short int agpo7_pos0_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	GPIO2_DATA7,
};

static const short int agpo8_pos0_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	VQ7U_DBG,
	GPIO2_DATA8,
};

static const short int agpo9_pos0_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	VQ7U_DBG,
	GPIO2_DATA9,
};

static const short int agpo10_pos0_confl_grps[] = {
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	VQ7U_DBG,
	ADCDCC,
	GPIO2_DATA10,
};

static const short int agpo11_pos0_confl_grps[] = {
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	VQ7U_DBG,
	ADCDCC,
	GPIO2_DATA11,
};

static const short int agpo0_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA15,
};

static const short int agpo1_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA16,
};

static const short int agpo2_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA17,
};

static const short int agpo3_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA18,
};

static const short int agpo4_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA19,
};

static const short int agpo5_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA20,
};

static const short int agpo6_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA21,
};

static const short int agpo7_pos1_confl_grps[] = {
	VIC0_SEC0,
	GPIO2_DATA22,
};

static const short int agpo8_pos1_confl_grps[] = {
	VIC0_SEC2,
	GPIO2_DATA24,
};

static const short int agpo9_pos1_confl_grps[] = {
	VIC0_SEC2,
	GPIO2_DATA25,
};

static const short int agpo10_pos1_confl_grps[] = {
	VIC0_SEC3,
	GPIO2_DATA26,
};

static const short int agpo11_pos1_confl_grps[] = {
	VIC0_SEC3,
	GPIO2_DATA27,
};

static const short int agpo0_pos2_confl_grps[] = {
	GPIO0_DATA0,
	VIC1_SEC0,
	UART0_POS1_SEC0,
};

static const short int agpo1_pos2_confl_grps[] = {
	GPIO0_DATA1,
	VIC1_SEC0,
	UART0_POS1_SEC0,
};

static const short int agpo2_pos2_confl_grps[] = {
	GPIO0_DATA2,
	VIC1_SEC0,
	UART2_POS1,
	UART0_POS1_SEC1,
};

static const short int agpo3_pos2_confl_grps[] = {
	GPIO0_DATA3,
	VIC1_SEC0,
	UART2_POS1,
	UART0_POS1_SEC1,
};

static const short int agpo4_pos2_confl_grps[] = {
	GPIO0_DATA4,
	VIC1_SEC0,
	UART1_POS1_SEC0,
};

static const short int agpo5_pos2_confl_grps[] = {
	GPIO0_DATA5,
	VIC1_SEC0,
	UART1_POS1_SEC0,
};

static const short int agpo6_pos2_confl_grps[] = {
	GPIO0_DATA6,
	VIC1_SEC0,
	UART3_POS1,
	UART1_POS1_SEC1,
};

static const short int agpo7_pos2_confl_grps[] = {
	GPIO0_DATA7,
	VIC1_SEC0,
	UART3_POS1,
	UART1_POS1_SEC1,
};

static const short int agpo8_pos2_confl_grps[] = {
	GPIO0_DATA9,
	VIC1_SEC2,
	UART4_POS1,
};

static const short int agpo9_pos2_confl_grps[] = {
	GPIO0_DATA10,
	VIC1_SEC2,
	UART4_POS1,
};

static const short int agpo10_pos2_confl_grps[] = {
	GPIO0_DATA11,
	VIC1_SEC3,
};

static const short int agpo11_pos2_confl_grps[] = {
	GPIO0_DATA12,
	VIC1_SEC3,
};

static const short int agpo0_pos3_confl_grps[] = {
	CA55U_DBG,
	GPIO0_DATA20,
};

static const short int agpo1_pos3_confl_grps[] = {
	CA55U_DBG,
	GPIO0_DATA21,
};

static const short int agpo2_pos3_confl_grps[] = {
	UART0_POS0_SEC0,
	VOC1_CLK_POS1,
	GPIO0_DATA22,
};

static const short int agpo3_pos3_confl_grps[] = {
	UART0_POS0_SEC0,
	VOC1_SEC7_POS1,
	GPIO0_DATA23,
};

static const short int agpo4_pos3_confl_grps[] = {
	UART2_POS0,
	VOC1_SEC6,
	UART0_POS0_SEC1,
	GPIO0_DATA24,
};

static const short int agpo5_pos3_confl_grps[] = {
	UART2_POS0,
	VOC1_SEC6,
	UART0_POS0_SEC1,
	GPIO0_DATA25,
};

static const short int agpo6_pos3_confl_grps[] = {
	UART1_POS0_SEC0,
	VOC1_SEC6,
	GPIO0_DATA26,
};

static const short int agpo7_pos3_confl_grps[] = {
	UART1_POS0_SEC0,
	VOC1_SEC6,
	GPIO0_DATA27,
};

static const short int agpo8_pos3_confl_grps[] = {
	UART3_POS0,
	VOC1_SEC5,
	UART1_POS0_SEC1,
	GPIO0_DATA28,
};

static const short int agpo9_pos3_confl_grps[] = {
	UART3_POS0,
	VOC1_SEC5,
	VOC1_SEC3_POS1,
	UART1_POS0_SEC1,
	GPIO0_DATA29,
};

static const short int agpo10_pos3_confl_grps[] = {
	UART4_POS0,
	VOC1_SEC5,
	VOC1_SEC2_POS1,
	GPIO0_DATA30,
};

static const short int agpo11_pos3_confl_grps[] = {
	UART4_POS0,
	VOC1_SEC5,
	VOC1_SEC2_POS1,
	GPIO0_DATA31,
};

static const short int agpo0_pos4_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	GPIO1_DATA3,
};

static const short int agpo1_pos4_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	GPIO1_DATA4,
};

static const short int agpo2_pos4_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	GPIO1_DATA5,
};

static const short int agpo3_pos4_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	GPIO1_DATA6,
};

static const short int agpo4_pos4_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	GPIO1_DATA10,
};

static const short int agpo5_pos4_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	GPIO1_DATA11,
};

static const short int agpo6_pos4_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	GPIO1_DATA12,
};

static const short int agpo7_pos4_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	GPIO1_DATA13,
};

static const short int agpo8_pos4_confl_grps[] = {
	EQOSC_SEC1,
	VOC1_SEC4,
	GPIO1_DATA14,
};

static const short int agpo9_pos4_confl_grps[] = {
	EQOSC_SEC1,
	VOC1_SEC4,
	GPIO1_DATA15,
};

static const short int agpo10_pos4_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC1,
	GPIO1_DATA16,
};

static const short int agpo11_pos4_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC1,
	GPIO1_DATA17,
};

static const short int gpio0_data0_confl_grps[] = {
	VIC1_SEC0,
	UART0_POS1_SEC0,
	AGPO0_POS2,
};

static const short int gpio0_data1_confl_grps[] = {
	VIC1_SEC0,
	UART0_POS1_SEC0,
	AGPO1_POS2,
};

static const short int gpio0_data2_confl_grps[] = {
	VIC1_SEC0,
	UART2_POS1,
	UART0_POS1_SEC1,
	AGPO2_POS2,
};

static const short int gpio0_data3_confl_grps[] = {
	VIC1_SEC0,
	UART2_POS1,
	UART0_POS1_SEC1,
	AGPO3_POS2,
};

static const short int gpio0_data4_confl_grps[] = {
	VIC1_SEC0,
	UART1_POS1_SEC0,
	AGPO4_POS2,
};

static const short int gpio0_data5_confl_grps[] = {
	VIC1_SEC0,
	UART1_POS1_SEC0,
	AGPO5_POS2,
};

static const short int gpio0_data6_confl_grps[] = {
	VIC1_SEC0,
	UART3_POS1,
	UART1_POS1_SEC1,
	AGPO6_POS2,
};

static const short int gpio0_data7_confl_grps[] = {
	VIC1_SEC0,
	UART3_POS1,
	UART1_POS1_SEC1,
	AGPO7_POS2,
};

static const short int gpio0_data8_confl_grps[] = {
	VIC1_SEC0,
};

static const short int gpio0_data9_confl_grps[] = {
	VIC1_SEC2,
	UART4_POS1,
	AGPO8_POS2,
};

static const short int gpio0_data10_confl_grps[] = {
	VIC1_SEC2,
	UART4_POS1,
	AGPO9_POS2,
};

static const short int gpio0_data11_confl_grps[] = {
	VIC1_SEC3,
	AGPO10_POS2,
};

static const short int gpio0_data12_confl_grps[] = {
	VIC1_SEC3,
	AGPO11_POS2,
};

static const short int gpio0_data13_confl_grps[] = {
	VIC1_SEC4,
	SSIC3_SGL_MA,
};

static const short int gpio0_data14_confl_grps[] = {
	VIC1_SEC4,
	//SSIC3_SGL_MA, //for gpio control cs
};

static const short int gpio0_data15_confl_grps[] = {
	VIC1_SEC5,
	I2CC2_POS1,
	SSIC3_SGL_MA,
};

static const short int gpio0_data16_confl_grps[] = {
	VIC1_SEC5,
	I2CC2_POS1,
	SSIC3_SGL_MA,
};

static const short int gpio0_data17_confl_grps[] = {
	VIC1_SEC1,
	I2CC2_POS0,
};

static const short int gpio0_data18_confl_grps[] = {
	VIC1_SEC1,
	I2CC2_POS0,
};

static const short int gpio0_data19_confl_grps[] = {
	MONITOR_CLK,
};

static const short int gpio0_data20_confl_grps[] = {
	CA55U_DBG,
	AGPO0_POS3,
};

static const short int gpio0_data21_confl_grps[] = {
	CA55U_DBG,
	AGPO1_POS3,
};

static const short int gpio0_data22_confl_grps[] = {
	UART0_POS0_SEC0,
	VOC1_CLK_POS1,
	AGPO2_POS3,
};

static const short int gpio0_data23_confl_grps[] = {
	UART0_POS0_SEC0,
	VOC1_SEC7_POS1,
	AGPO3_POS3,
};

static const short int gpio0_data24_confl_grps[] = {
	UART2_POS0,
	VOC1_SEC6,
	UART0_POS0_SEC1,
	AGPO4_POS3,
};

static const short int gpio0_data25_confl_grps[] = {
	UART2_POS0,
	VOC1_SEC6,
	UART0_POS0_SEC1,
	AGPO5_POS3,
};

static const short int gpio0_data26_confl_grps[] = {
	UART1_POS0_SEC0,
	VOC1_SEC6,
	AGPO6_POS3,
};

static const short int gpio0_data27_confl_grps[] = {
	UART1_POS0_SEC0,
	VOC1_SEC6,
	AGPO7_POS3,
};

static const short int gpio0_data28_confl_grps[] = {
	UART3_POS0,
	VOC1_SEC5,
	UART1_POS0_SEC1,
	AGPO8_POS3,
};

static const short int gpio0_data29_confl_grps[] = {
	UART3_POS0,
	VOC1_SEC5,
	VOC1_SEC3_POS1,
	UART1_POS0_SEC1,
	AGPO9_POS3,
};

static const short int gpio0_data30_confl_grps[] = {
	UART4_POS0,
	VOC1_SEC5,
	VOC1_SEC2_POS1,
	AGPO10_POS3,
};

static const short int gpio0_data31_confl_grps[] = {
	UART4_POS0,
	VOC1_SEC5,
	VOC1_SEC2_POS1,
	AGPO11_POS3,
};

static const short int gpio1_data0_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC0,
	VOC1_SEC2_POS1,
};

static const short int gpio1_data1_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC3_POS0,
};

static const short int gpio1_data2_confl_grps[] = {
	EQOSC_RX_CLK,
	VOC1_SEC1,
};

static const short int gpio1_data3_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	AGPO0_POS4,
};

static const short int gpio1_data4_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	AGPO1_POS4,
};

static const short int gpio1_data5_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	AGPO2_POS4,
};

static const short int gpio1_data6_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	AGPO3_POS4,
};

static const short int gpio1_data7_confl_grps[] = {
	EQOSC_TX_IN_CLK,
	VOC1_SEC1,
};

static const short int gpio1_data8_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC4,
};

static const short int gpio1_data9_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC0,
	VOC1_SEC2_POS1,
};

static const short int gpio1_data10_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	AGPO4_POS4,
};

static const short int gpio1_data11_confl_grps[] = {
	EQOSC_SEC0,
	VOC1_SEC2_POS0,
	AGPO5_POS4,
};

static const short int gpio1_data12_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	AGPO6_POS4,
};

static const short int gpio1_data13_confl_grps[] = {
	EQOSC_SEC2,
	VOC1_SEC1,
	AGPO7_POS4,
};

static const short int gpio1_data14_confl_grps[] = {
	EQOSC_SEC1,
	VOC1_SEC4,
	AGPO8_POS4,
};

static const short int gpio1_data15_confl_grps[] = {
	EQOSC_SEC1,
	VOC1_SEC4,
	AGPO9_POS4,
};

static const short int gpio1_data16_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC1,
	AGPO10_POS4,
};

static const short int gpio1_data17_confl_grps[] = {
	EQOSC_SEC3,
	VOC1_SEC1,
	AGPO11_POS4,
};

static const short int gpio1_data18_confl_grps[] = {
	MSHC,
	UART0_POS2_SEC0,
};

static const short int gpio1_data19_confl_grps[] = {
	//MSHC, //for gpio control write_prot
	UART0_POS2_SEC0,
};

static const short int gpio1_data20_confl_grps[] = {
	SCRTU_DBG,
	UART2_POS2,
	UART0_POS2_SEC1,
	USB20C_VBUS_OC,
	USB30C_DBG,
};

static const short int gpio1_data21_confl_grps[] = {
	SCRTU_DBG,
	UART2_POS2,
	UART0_POS2_SEC1,
	USB20C_DRV_VBUS,
	USB30C_DBG,
};

static const short int gpio1_data22_confl_grps[] = {
	SCRTU_DBG,
	UART3_POS2,
	USB30C_VBUS_OC,
	USB30C_DBG,
};

static const short int gpio1_data23_confl_grps[] = {
	SCRTU_DBG,
	UART3_POS2,
	USB30C_DRV_VBUS,
	USB30C_DBG,
};

static const short int gpio1_data24_confl_grps[] = {
	SCRTU_DBG,
	USB30C_DBG,
};

static const short int gpio1_data25_confl_grps[] = {
	IRDAC,
	UART1_POS2_SEC0,
	DDRNSDMC_TEST,
	AGPO0_POS0,
};

static const short int gpio1_data26_confl_grps[] = {
	SSIC0_QUAD_MA,
	UART1_POS2_SEC0,
};

static const short int gpio1_data27_confl_grps[] = {
	SSIC0_QUAD_MA,
	UART4_POS2,
	UART1_POS2_SEC1,
};

static const short int gpio1_data28_confl_grps[] = {
	//SSIC0_QUAD_MA, //for gpio control cs
	UART4_POS2,
	UART1_POS2_SEC1,
};

static const short int gpio1_data29_confl_grps[] = {
	-1,
	//SSIC0_QUAD_MA, //for gpio control cs
	//SSIC0_SGL_MA, //for gpio control cs
	//SSIC0_SGL_SLA, //for gpio control cs
};

static const short int gpio1_data30_confl_grps[] = {
	SSIC0_QUAD_MA,
	SSIC0_SGL_MA,
	SSIC0_SGL_SLA,
};

static const short int gpio1_data31_confl_grps[] = {
	SSIC0_QUAD_MA,
	SSIC0_SGL_MA,
	SSIC0_SGL_SLA,
};

static const short int gpio2_data0_confl_grps[] = {
	SSIC0_QUAD_MA,
	SSIC0_SGL_MA,
	SSIC0_SGL_SLA,
};

static const short int gpio2_data1_confl_grps[] = {
	//SSIC1_SGL_MA, //for gpio control cs
	AGPO1_POS0,
};

static const short int gpio2_data2_confl_grps[] = {
	SSIC1_SGL_MA,
	AGPO2_POS0,
};

static const short int gpio2_data3_confl_grps[] = {
	SSIC1_SGL_MA,
	AGPO3_POS0,
};

static const short int gpio2_data4_confl_grps[] = {
	SSIC1_SGL_MA,
	AGPO4_POS0,
};

static const short int gpio2_data5_confl_grps[] = {
	I2CC0,
	AGPO5_POS0,
};

static const short int gpio2_data6_confl_grps[] = {
	I2CC0,
	AGPO6_POS0,
};

static const short int gpio2_data7_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	AGPO7_POS0,
};

static const short int gpio2_data8_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	VQ7U_DBG,
	AGPO8_POS0,
};

static const short int gpio2_data9_confl_grps[] = {
	I2SSC_TX_MA,
	I2SSC_TX_SLA,
	VQ7U_DBG,
	AGPO9_POS0,
};

static const short int gpio2_data10_confl_grps[] = {
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	VQ7U_DBG,
	ADCDCC,
	AGPO10_POS0,
};

static const short int gpio2_data11_confl_grps[] = {
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	VQ7U_DBG,
	ADCDCC,
	AGPO11_POS0,
};

static const short int gpio2_data12_confl_grps[] = {
	I2SSC_RX_MA,
	I2SSC_RX_SLA,
	VQ7U_DBG,
	ADCDCC,
};

static const short int gpio2_data13_confl_grps[] = {
	VIC0_SEC1,
	I2CC1_POS0,
};

static const short int gpio2_data14_confl_grps[] = {
	VIC0_SEC1,
	I2CC1_POS0,
};

static const short int gpio2_data15_confl_grps[] = {
	VIC0_SEC0,
	AGPO0_POS1,
};

static const short int gpio2_data16_confl_grps[] = {
	VIC0_SEC0,
	AGPO1_POS1,
};

static const short int gpio2_data17_confl_grps[] = {
	VIC0_SEC0,
	AGPO2_POS1,
};

static const short int gpio2_data18_confl_grps[] = {
	VIC0_SEC0,
	AGPO3_POS1,
};

static const short int gpio2_data19_confl_grps[] = {
	VIC0_SEC0,
	AGPO4_POS1,
};

static const short int gpio2_data20_confl_grps[] = {
	VIC0_SEC0,
	AGPO5_POS1,
};

static const short int gpio2_data21_confl_grps[] = {
	VIC0_SEC0,
	AGPO6_POS1,
};

static const short int gpio2_data22_confl_grps[] = {
	VIC0_SEC0,
	AGPO7_POS1,
};

static const short int gpio2_data23_confl_grps[] = {
	VIC0_SEC0,
};

static const short int gpio2_data24_confl_grps[] = {
	VIC0_SEC2,
	AGPO8_POS1,
};

static const short int gpio2_data25_confl_grps[] = {
	VIC0_SEC2,
	AGPO9_POS1,
};

static const short int gpio2_data26_confl_grps[] = {
	VIC0_SEC3,
	AGPO10_POS1,
};

static const short int gpio2_data27_confl_grps[] = {
	VIC0_SEC3,
	AGPO11_POS1,
};

static const short int gpio2_data28_confl_grps[] = {
	VIC0_SEC4,
	VIC_REF_SYNC,
	SSIC2_SGL_MA,
};

static const short int gpio2_data29_confl_grps[] = {
	VIC0_SEC4,
	VIC_REF_SYNC,
	//SSIC2_SGL_MA, //for gpio control cs
};

static const short int gpio2_data30_confl_grps[] = {
	VIC0_SEC5,
	I2CC1_POS1,
	SSIC2_SGL_MA,
};

static const short int gpio2_data31_confl_grps[] = {
	VIC0_SEC5,
	I2CC1_POS1,
	SSIC2_SGL_MA,
};

#define DECLARE_AGPO_PINS(n, p, pin) \
static const unsigned int agpo##n##_pos##p##_pins[] = { \
	pin, \
}

/* AGPO_POS0 */
DECLARE_AGPO_PINS(0, 0, INOUT_0);
DECLARE_AGPO_PINS(1, 0, INOUT_8);
DECLARE_AGPO_PINS(2, 0, INOUT_9);
DECLARE_AGPO_PINS(3, 0, INOUT_10);
DECLARE_AGPO_PINS(4, 0, INOUT_11);
DECLARE_AGPO_PINS(5, 0, INOUT_12);
DECLARE_AGPO_PINS(6, 0, INOUT_13);
DECLARE_AGPO_PINS(7, 0, INOUT_14);
DECLARE_AGPO_PINS(8, 0, INOUT_15);
DECLARE_AGPO_PINS(9, 0, INOUT_16);
DECLARE_AGPO_PINS(10, 0, INOUT_17);
DECLARE_AGPO_PINS(11, 0, INOUT_18);

/* AGPO_POS1 */
DECLARE_AGPO_PINS(0, 1, INOUT_22);
DECLARE_AGPO_PINS(1, 1, INOUT_23);
DECLARE_AGPO_PINS(2, 1, INOUT_24);
DECLARE_AGPO_PINS(3, 1, INOUT_25);
DECLARE_AGPO_PINS(4, 1, INOUT_26);
DECLARE_AGPO_PINS(5, 1, INOUT_27);
DECLARE_AGPO_PINS(6, 1, INOUT_28);
DECLARE_AGPO_PINS(7, 1, INOUT_29);
DECLARE_AGPO_PINS(8, 1, INOUT_31);
DECLARE_AGPO_PINS(9, 1, INOUT_32);
DECLARE_AGPO_PINS(10, 1, INOUT_33);
DECLARE_AGPO_PINS(11, 1, INOUT_34);

/* AGPO_POS2 */
DECLARE_AGPO_PINS(0, 2, INOUT_39);
DECLARE_AGPO_PINS(1, 2, INOUT_40);
DECLARE_AGPO_PINS(2, 2, INOUT_41);
DECLARE_AGPO_PINS(3, 2, INOUT_42);
DECLARE_AGPO_PINS(4, 2, INOUT_43);
DECLARE_AGPO_PINS(5, 2, INOUT_44);
DECLARE_AGPO_PINS(6, 2, INOUT_45);
DECLARE_AGPO_PINS(7, 2, INOUT_46);
DECLARE_AGPO_PINS(8, 2, INOUT_48);
DECLARE_AGPO_PINS(9, 2, INOUT_49);
DECLARE_AGPO_PINS(10, 2, INOUT_50);
DECLARE_AGPO_PINS(11, 2, INOUT_51);

/* AGPO_POS3 */
DECLARE_AGPO_PINS(0, 3, INOUT_59);
DECLARE_AGPO_PINS(1, 3, INOUT_60);
DECLARE_AGPO_PINS(2, 3, INOUT_61);
DECLARE_AGPO_PINS(3, 3, INOUT_62);
DECLARE_AGPO_PINS(4, 3, INOUT_63);
DECLARE_AGPO_PINS(5, 3, INOUT_64);
DECLARE_AGPO_PINS(6, 3, INOUT_65);
DECLARE_AGPO_PINS(7, 3, INOUT_66);
DECLARE_AGPO_PINS(8, 3, INOUT_67);
DECLARE_AGPO_PINS(9, 3, INOUT_68);
DECLARE_AGPO_PINS(10, 3, INOUT_69);
DECLARE_AGPO_PINS(11, 3, INOUT_70);

/* AGPO_POS4 */
DECLARE_AGPO_PINS(0, 4, INOUT_74);
DECLARE_AGPO_PINS(1, 4, INOUT_75);
DECLARE_AGPO_PINS(2, 4, INOUT_76);
DECLARE_AGPO_PINS(3, 4, INOUT_77);
DECLARE_AGPO_PINS(4, 4, INOUT_81);
DECLARE_AGPO_PINS(5, 4, INOUT_82);
DECLARE_AGPO_PINS(6, 4, INOUT_83);
DECLARE_AGPO_PINS(7, 4, INOUT_84);
DECLARE_AGPO_PINS(8, 4, INOUT_85);
DECLARE_AGPO_PINS(9, 4, INOUT_86);
DECLARE_AGPO_PINS(10, 4, INOUT_87);
DECLARE_AGPO_PINS(11, 4, INOUT_88);

#define DECLARE_GPIO_PINS(n, d, pin) \
static const unsigned int gpio##n##_data##d##_pins[] = { \
	pin, \
}

/* GPIO0 */
DECLARE_GPIO_PINS(0, 0, INOUT_39);
DECLARE_GPIO_PINS(0, 1, INOUT_40);
DECLARE_GPIO_PINS(0, 2, INOUT_41);
DECLARE_GPIO_PINS(0, 3, INOUT_42);
DECLARE_GPIO_PINS(0, 4, INOUT_43);
DECLARE_GPIO_PINS(0, 5, INOUT_44);
DECLARE_GPIO_PINS(0, 6, INOUT_45);
DECLARE_GPIO_PINS(0, 7, INOUT_46);
DECLARE_GPIO_PINS(0, 8, INOUT_47);
DECLARE_GPIO_PINS(0, 9, INOUT_48);
DECLARE_GPIO_PINS(0, 10, INOUT_49);
DECLARE_GPIO_PINS(0, 11, INOUT_50);
DECLARE_GPIO_PINS(0, 12, INOUT_51);
DECLARE_GPIO_PINS(0, 13, INOUT_52);
DECLARE_GPIO_PINS(0, 14, INOUT_53);
DECLARE_GPIO_PINS(0, 15, INOUT_54);
DECLARE_GPIO_PINS(0, 16, INOUT_55);
DECLARE_GPIO_PINS(0, 17, INOUT_56);
DECLARE_GPIO_PINS(0, 18, INOUT_57);
DECLARE_GPIO_PINS(0, 19, INOUT_58);
DECLARE_GPIO_PINS(0, 20, INOUT_59);
DECLARE_GPIO_PINS(0, 21, INOUT_60);
DECLARE_GPIO_PINS(0, 22, INOUT_61);
DECLARE_GPIO_PINS(0, 23, INOUT_62);
DECLARE_GPIO_PINS(0, 24, INOUT_63);
DECLARE_GPIO_PINS(0, 25, INOUT_64);
DECLARE_GPIO_PINS(0, 26, INOUT_65);
DECLARE_GPIO_PINS(0, 27, INOUT_66);
DECLARE_GPIO_PINS(0, 28, INOUT_67);
DECLARE_GPIO_PINS(0, 29, INOUT_68);
DECLARE_GPIO_PINS(0, 30, INOUT_69);
DECLARE_GPIO_PINS(0, 31, INOUT_70);

/* GPIO1 */
DECLARE_GPIO_PINS(1, 0, INOUT_71);
DECLARE_GPIO_PINS(1, 1, INOUT_72);
DECLARE_GPIO_PINS(1, 2, INOUT_73);
DECLARE_GPIO_PINS(1, 3, INOUT_74);
DECLARE_GPIO_PINS(1, 4, INOUT_75);
DECLARE_GPIO_PINS(1, 5, INOUT_76);
DECLARE_GPIO_PINS(1, 6, INOUT_77);
DECLARE_GPIO_PINS(1, 7, INOUT_78);
DECLARE_GPIO_PINS(1, 8, INOUT_79);
DECLARE_GPIO_PINS(1, 9, INOUT_80);
DECLARE_GPIO_PINS(1, 10, INOUT_81);
DECLARE_GPIO_PINS(1, 11, INOUT_82);
DECLARE_GPIO_PINS(1, 12, INOUT_83);
DECLARE_GPIO_PINS(1, 13, INOUT_84);
DECLARE_GPIO_PINS(1, 14, INOUT_85);
DECLARE_GPIO_PINS(1, 15, INOUT_86);
DECLARE_GPIO_PINS(1, 16, INOUT_87);
DECLARE_GPIO_PINS(1, 17, INOUT_88);
DECLARE_GPIO_PINS(1, 18, INOUT_89);
DECLARE_GPIO_PINS(1, 19, INOUT_90);
DECLARE_GPIO_PINS(1, 20, INOUT_91);
DECLARE_GPIO_PINS(1, 21, INOUT_92);
DECLARE_GPIO_PINS(1, 22, INOUT_93);
DECLARE_GPIO_PINS(1, 23, INOUT_94);
DECLARE_GPIO_PINS(1, 24, INOUT_95);
DECLARE_GPIO_PINS(1, 25, INOUT_0);
DECLARE_GPIO_PINS(1, 26, INOUT_1);
DECLARE_GPIO_PINS(1, 27, INOUT_2);
DECLARE_GPIO_PINS(1, 28, INOUT_3);
DECLARE_GPIO_PINS(1, 29, INOUT_4);
DECLARE_GPIO_PINS(1, 30, INOUT_5);
DECLARE_GPIO_PINS(1, 31, INOUT_6);

/* GPIO2 */
DECLARE_GPIO_PINS(2, 0, INOUT_7);
DECLARE_GPIO_PINS(2, 1, INOUT_8);
DECLARE_GPIO_PINS(2, 2, INOUT_9);
DECLARE_GPIO_PINS(2, 3, INOUT_10);
DECLARE_GPIO_PINS(2, 4, INOUT_11);
DECLARE_GPIO_PINS(2, 5, INOUT_12);
DECLARE_GPIO_PINS(2, 6, INOUT_13);
DECLARE_GPIO_PINS(2, 7, INOUT_14);
DECLARE_GPIO_PINS(2, 8, INOUT_15);
DECLARE_GPIO_PINS(2, 9, INOUT_16);
DECLARE_GPIO_PINS(2, 10, INOUT_17);
DECLARE_GPIO_PINS(2, 11, INOUT_18);
DECLARE_GPIO_PINS(2, 12, INOUT_19);
DECLARE_GPIO_PINS(2, 13, INOUT_20);
DECLARE_GPIO_PINS(2, 14, INOUT_21);
DECLARE_GPIO_PINS(2, 15, INOUT_22);
DECLARE_GPIO_PINS(2, 16, INOUT_23);
DECLARE_GPIO_PINS(2, 17, INOUT_24);
DECLARE_GPIO_PINS(2, 18, INOUT_25);
DECLARE_GPIO_PINS(2, 19, INOUT_26);
DECLARE_GPIO_PINS(2, 20, INOUT_27);
DECLARE_GPIO_PINS(2, 21, INOUT_28);
DECLARE_GPIO_PINS(2, 22, INOUT_29);
DECLARE_GPIO_PINS(2, 23, INOUT_30);
DECLARE_GPIO_PINS(2, 24, INOUT_31);
DECLARE_GPIO_PINS(2, 25, INOUT_32);
DECLARE_GPIO_PINS(2, 26, INOUT_33);
DECLARE_GPIO_PINS(2, 27, INOUT_34);
DECLARE_GPIO_PINS(2, 28, INOUT_35);
DECLARE_GPIO_PINS(2, 29, INOUT_36);
DECLARE_GPIO_PINS(2, 30, INOUT_37);
DECLARE_GPIO_PINS(2, 31, INOUT_38);

#define LEIPZIG_GROUP(pg_name, _en_ofs, _firstbit, _sts_ofs) { \
	.name = #pg_name, \
	.pins = pg_name##_pins, \
	.npins = ARRAY_SIZE(pg_name##_pins), \
	.en_ofs = _en_ofs, \
	.bit = _firstbit, \
	.sts_ofs = _sts_ofs, \
	.confl_grps = pg_name##_confl_grps, \
	.nconfl_grps = ARRAY_SIZE(pg_name##_confl_grps), \
}

static const struct leipzig_group_desc leipzig_groups[] = {
	/* DEBUG */
	LEIPZIG_GROUP(scrtu_dbg, VPL_PAD_EN_6, 24, VPL_PAD_STS_6),	//0
	LEIPZIG_GROUP(ca55u_dbg, VPL_PAD_EN_6, 1, VPL_PAD_STS_6),
	LEIPZIG_GROUP(usb30c_dbg, VPL_PAD_EN_7, 23, VPL_PAD_STS_7),
	LEIPZIG_GROUP(vq7u_dbg, VPL_PAD_EN_8, 27, VPL_PAD_STS_8),
	/* SSIC */
	LEIPZIG_GROUP(ssic3_sgl_ma, VPL_PAD_EN_6, 30, VPL_PAD_STS_6),
	LEIPZIG_GROUP(ssic2_sgl_ma, VPL_PAD_EN_6, 29, VPL_PAD_STS_6),	//5
	LEIPZIG_GROUP(ssic1_sgl_ma, VPL_PAD_EN_6, 28, VPL_PAD_STS_6),
	LEIPZIG_GROUP(ssic0_sgl_sla, VPL_PAD_EN_6, 27, VPL_PAD_STS_6),
	LEIPZIG_GROUP(ssic0_sgl_ma, VPL_PAD_EN_6, 26, VPL_PAD_STS_6),
	LEIPZIG_GROUP(ssic0_quad_ma, VPL_PAD_EN_6, 25, VPL_PAD_STS_6),
	/* MSHC */
	LEIPZIG_GROUP(mshc, VPL_PAD_EN_6, 23, VPL_PAD_STS_6),		//10
	/* MONITOR CLOCK */
	LEIPZIG_GROUP(monitor_clk, VPL_PAD_EN_6, 22, VPL_PAD_STS_6),
	/* IRDAC */
	LEIPZIG_GROUP(irdac, VPL_PAD_EN_6, 21, VPL_PAD_STS_6),
	/* I2SSC */
	LEIPZIG_GROUP(i2ssc_tx_sla, VPL_PAD_EN_6, 20, VPL_PAD_STS_6),
	LEIPZIG_GROUP(i2ssc_tx_ma, VPL_PAD_EN_6, 19, VPL_PAD_STS_6),
	LEIPZIG_GROUP(i2ssc_rx_sla, VPL_PAD_EN_6, 18, VPL_PAD_STS_6),	//15
	LEIPZIG_GROUP(i2ssc_rx_ma, VPL_PAD_EN_6, 17, VPL_PAD_STS_6),
	LEIPZIG_GROUP(i2ssc_ma_clk, VPL_PAD_EN_6, 16, VPL_PAD_STS_6),
	/* I2CC */
	LEIPZIG_GROUP(i2cc2_pos1, VPL_PAD_EN_6, 15, VPL_PAD_STS_6),
	LEIPZIG_GROUP(i2cc2_pos0, VPL_PAD_EN_6, 14, VPL_PAD_STS_6),
	LEIPZIG_GROUP(i2cc1_pos1, VPL_PAD_EN_6, 13, VPL_PAD_STS_6),	//20
	LEIPZIG_GROUP(i2cc1_pos0, VPL_PAD_EN_6, 12, VPL_PAD_STS_6),
	LEIPZIG_GROUP(i2cc0, VPL_PAD_EN_6, 11, VPL_PAD_STS_6),
	/* EQOSC */
	LEIPZIG_GROUP(eqosc_tx_out_clk, VPL_PAD_EN_6, 10, VPL_PAD_STS_6),
	LEIPZIG_GROUP(eqosc_tx_in_clk, VPL_PAD_EN_6, 9, VPL_PAD_STS_6),
	LEIPZIG_GROUP(eqosc_rx_clk, VPL_PAD_EN_6, 8, VPL_PAD_STS_6),	//25
	LEIPZIG_GROUP(eqosc_ref_clk, VPL_PAD_EN_6, 7, VPL_PAD_STS_6),
	LEIPZIG_GROUP(eqosc_sec3, VPL_PAD_EN_6, 6, VPL_PAD_STS_6),
	LEIPZIG_GROUP(eqosc_sec2, VPL_PAD_EN_6, 5, VPL_PAD_STS_6),
	LEIPZIG_GROUP(eqosc_sec1, VPL_PAD_EN_6, 4, VPL_PAD_STS_6),
	LEIPZIG_GROUP(eqosc_sec0, VPL_PAD_EN_6, 3, VPL_PAD_STS_6),	//30
	/* DDRNSDMC */
	LEIPZIG_GROUP(ddrnsdmc_test, VPL_PAD_EN_6, 2, VPL_PAD_STS_6),
	/* ADCDCC */
	LEIPZIG_GROUP(adcdcc, VPL_PAD_EN_6, 0, VPL_PAD_STS_6),
	/* USB30C */
	LEIPZIG_GROUP(usb30c_vbus_oc, VPL_PAD_EN_7, 25, VPL_PAD_STS_7),
	LEIPZIG_GROUP(usb30c_drv_vbus, VPL_PAD_EN_7, 24, VPL_PAD_STS_7),
	/* USB20C */
	LEIPZIG_GROUP(usb20c_vbus_oc, VPL_PAD_EN_7, 22, VPL_PAD_STS_7),	//35
	LEIPZIG_GROUP(usb20c_drv_vbus, VPL_PAD_EN_7, 21, VPL_PAD_STS_7),
	/* UART4 */
	LEIPZIG_GROUP(uart4_pos2, VPL_PAD_EN_7, 20, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart4_pos1, VPL_PAD_EN_7, 19, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart4_pos0, VPL_PAD_EN_7, 18, VPL_PAD_STS_7),
	/* UART3 */
	LEIPZIG_GROUP(uart3_pos2, VPL_PAD_EN_7, 17, VPL_PAD_STS_7),	//40
	LEIPZIG_GROUP(uart3_pos1, VPL_PAD_EN_7, 16, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart3_pos0, VPL_PAD_EN_7, 15, VPL_PAD_STS_7),
	/* UART2 */
	LEIPZIG_GROUP(uart2_pos2, VPL_PAD_EN_7, 14, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart2_pos1, VPL_PAD_EN_7, 13, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart2_pos0, VPL_PAD_EN_7, 12, VPL_PAD_STS_7),	//45
	/* UART1 */
	LEIPZIG_GROUP(uart1_pos2_sec1, VPL_PAD_EN_7, 11, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart1_pos2_sec0, VPL_PAD_EN_7, 10, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart1_pos1_sec1, VPL_PAD_EN_7, 9, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart1_pos1_sec0, VPL_PAD_EN_7, 8, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart1_pos0_sec1, VPL_PAD_EN_7, 7, VPL_PAD_STS_7),	//50
	LEIPZIG_GROUP(uart1_pos0_sec0, VPL_PAD_EN_7, 6, VPL_PAD_STS_7),
	/* UART0 */
	LEIPZIG_GROUP(uart0_pos2_sec1, VPL_PAD_EN_7, 5, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart0_pos2_sec0, VPL_PAD_EN_7, 4, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart0_pos1_sec1, VPL_PAD_EN_7, 3, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart0_pos1_sec0, VPL_PAD_EN_7, 2, VPL_PAD_STS_7),	//55
	LEIPZIG_GROUP(uart0_pos0_sec1, VPL_PAD_EN_7, 1, VPL_PAD_STS_7),
	LEIPZIG_GROUP(uart0_pos0_sec0, VPL_PAD_EN_7, 0, VPL_PAD_STS_7),
	/* WDTC */
	LEIPZIG_GROUP(wdtc, VPL_PAD_EN_8, 28, VPL_PAD_STS_8),
	/* VOC */
	LEIPZIG_GROUP(voc1_sec7_pos1, VPL_PAD_EN_8, 26, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec7_pos0, VPL_PAD_EN_8, 25, VPL_PAD_STS_8),	//60
	LEIPZIG_GROUP(voc1_sec6, VPL_PAD_EN_8, 24, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec5, VPL_PAD_EN_8, 23, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec4, VPL_PAD_EN_8, 22, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec3_pos1, VPL_PAD_EN_8, 21, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec3_pos0, VPL_PAD_EN_8, 20, VPL_PAD_STS_8),	//65
	LEIPZIG_GROUP(voc1_sec2_pos1, VPL_PAD_EN_8, 19, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec2_pos0, VPL_PAD_EN_8, 18, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec1, VPL_PAD_EN_8, 17, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_sec0, VPL_PAD_EN_8, 16, VPL_PAD_STS_8),
	LEIPZIG_GROUP(voc1_clk_pos1, VPL_PAD_EN_8, 15, VPL_PAD_STS_8),	//70
	LEIPZIG_GROUP(voc1_clk_pos0, VPL_PAD_EN_8, 14, VPL_PAD_STS_8),
	/* VIC */
	LEIPZIG_GROUP(vic1_sec5, VPL_PAD_EN_8, 13, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic1_sec4, VPL_PAD_EN_8, 12, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic1_sec3, VPL_PAD_EN_8, 11, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic1_sec2, VPL_PAD_EN_8, 10, VPL_PAD_STS_8),	//75
	LEIPZIG_GROUP(vic1_sec1, VPL_PAD_EN_8, 9, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic1_sec0, VPL_PAD_EN_8, 8, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic0_sec5, VPL_PAD_EN_8, 7, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic0_sec4, VPL_PAD_EN_8, 6, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic0_sec3, VPL_PAD_EN_8, 5, VPL_PAD_STS_8),	//80
	LEIPZIG_GROUP(vic0_sec2, VPL_PAD_EN_8, 4, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic0_sec1, VPL_PAD_EN_8, 3, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic0_sec0, VPL_PAD_EN_8, 2, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic_ref_sync, VPL_PAD_EN_8, 1, VPL_PAD_STS_8),
	LEIPZIG_GROUP(vic_ref_clk, VPL_PAD_EN_8, 0, VPL_PAD_STS_8),	//85
	/* AGPO POS0 */
	LEIPZIG_GROUP(agpo0_pos0, VPL_PAD_EN_3, 0, VPL_PAD_STS_3),	//86~97
	LEIPZIG_GROUP(agpo1_pos0, VPL_PAD_EN_3, 1, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo2_pos0, VPL_PAD_EN_3, 2, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo3_pos0, VPL_PAD_EN_3, 3, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo4_pos0, VPL_PAD_EN_3, 4, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo5_pos0, VPL_PAD_EN_3, 5, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo6_pos0, VPL_PAD_EN_3, 6, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo7_pos0, VPL_PAD_EN_3, 7, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo8_pos0, VPL_PAD_EN_3, 8, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo9_pos0, VPL_PAD_EN_3, 9, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo10_pos0, VPL_PAD_EN_3, 10, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo11_pos0, VPL_PAD_EN_3, 11, VPL_PAD_STS_3),
	/* AGPO POS1 */
	LEIPZIG_GROUP(agpo0_pos1, VPL_PAD_EN_3, 16, VPL_PAD_STS_3),	//98~109
	LEIPZIG_GROUP(agpo1_pos1, VPL_PAD_EN_3, 17, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo2_pos1, VPL_PAD_EN_3, 18, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo3_pos1, VPL_PAD_EN_3, 19, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo4_pos1, VPL_PAD_EN_3, 20, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo5_pos1, VPL_PAD_EN_3, 21, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo6_pos1, VPL_PAD_EN_3, 22, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo7_pos1, VPL_PAD_EN_3, 23, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo8_pos1, VPL_PAD_EN_3, 24, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo9_pos1, VPL_PAD_EN_3, 25, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo10_pos1, VPL_PAD_EN_3, 26, VPL_PAD_STS_3),
	LEIPZIG_GROUP(agpo11_pos1, VPL_PAD_EN_3, 27, VPL_PAD_STS_3),
	/* AGPO POS2 */
	LEIPZIG_GROUP(agpo0_pos2, VPL_PAD_EN_4, 0, VPL_PAD_STS_4),	//110~121
	LEIPZIG_GROUP(agpo1_pos2, VPL_PAD_EN_4, 1, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo2_pos2, VPL_PAD_EN_4, 2, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo3_pos2, VPL_PAD_EN_4, 3, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo4_pos2, VPL_PAD_EN_4, 4, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo5_pos2, VPL_PAD_EN_4, 5, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo6_pos2, VPL_PAD_EN_4, 6, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo7_pos2, VPL_PAD_EN_4, 7, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo8_pos2, VPL_PAD_EN_4, 8, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo9_pos2, VPL_PAD_EN_4, 9, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo10_pos2, VPL_PAD_EN_4, 10, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo11_pos2, VPL_PAD_EN_4, 11, VPL_PAD_STS_4),
	/* AGPO POS3 */
	LEIPZIG_GROUP(agpo0_pos3, VPL_PAD_EN_4, 16, VPL_PAD_STS_4),	//122~133
	LEIPZIG_GROUP(agpo1_pos3, VPL_PAD_EN_4, 17, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo2_pos3, VPL_PAD_EN_4, 18, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo3_pos3, VPL_PAD_EN_4, 19, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo4_pos3, VPL_PAD_EN_4, 20, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo5_pos3, VPL_PAD_EN_4, 21, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo6_pos3, VPL_PAD_EN_4, 22, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo7_pos3, VPL_PAD_EN_4, 23, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo8_pos3, VPL_PAD_EN_4, 24, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo9_pos3, VPL_PAD_EN_4, 25, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo10_pos3, VPL_PAD_EN_4, 26, VPL_PAD_STS_4),
	LEIPZIG_GROUP(agpo11_pos3, VPL_PAD_EN_4, 27, VPL_PAD_STS_4),
	/* AGPO POS4 */
	LEIPZIG_GROUP(agpo0_pos4, VPL_PAD_EN_5, 0, VPL_PAD_STS_5),	//134~145
	LEIPZIG_GROUP(agpo1_pos4, VPL_PAD_EN_5, 1, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo2_pos4, VPL_PAD_EN_5, 2, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo3_pos4, VPL_PAD_EN_5, 3, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo4_pos4, VPL_PAD_EN_5, 4, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo5_pos4, VPL_PAD_EN_5, 5, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo6_pos4, VPL_PAD_EN_5, 6, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo7_pos4, VPL_PAD_EN_5, 7, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo8_pos4, VPL_PAD_EN_5, 8, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo9_pos4, VPL_PAD_EN_5, 9, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo10_pos4, VPL_PAD_EN_5, 10, VPL_PAD_STS_5),
	LEIPZIG_GROUP(agpo11_pos4, VPL_PAD_EN_5, 11, VPL_PAD_STS_5),
	/* GPIO0 */
	LEIPZIG_GROUP(gpio0_data0, VPL_PAD_EN_0, 0, VPL_PAD_STS_0),	//146~177
	LEIPZIG_GROUP(gpio0_data1, VPL_PAD_EN_0, 1, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data2, VPL_PAD_EN_0, 2, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data3, VPL_PAD_EN_0, 3, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data4, VPL_PAD_EN_0, 4, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data5, VPL_PAD_EN_0, 5, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data6, VPL_PAD_EN_0, 6, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data7, VPL_PAD_EN_0, 7, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data8, VPL_PAD_EN_0, 8, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data9, VPL_PAD_EN_0, 9, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data10, VPL_PAD_EN_0, 10, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data11, VPL_PAD_EN_0, 11, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data12, VPL_PAD_EN_0, 12, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data13, VPL_PAD_EN_0, 13, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data14, VPL_PAD_EN_0, 14, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data15, VPL_PAD_EN_0, 15, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data16, VPL_PAD_EN_0, 16, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data17, VPL_PAD_EN_0, 17, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data18, VPL_PAD_EN_0, 18, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data19, VPL_PAD_EN_0, 19, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data20, VPL_PAD_EN_0, 20, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data21, VPL_PAD_EN_0, 21, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data22, VPL_PAD_EN_0, 22, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data23, VPL_PAD_EN_0, 23, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data24, VPL_PAD_EN_0, 24, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data25, VPL_PAD_EN_0, 25, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data26, VPL_PAD_EN_0, 26, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data27, VPL_PAD_EN_0, 27, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data28, VPL_PAD_EN_0, 28, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data29, VPL_PAD_EN_0, 29, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data30, VPL_PAD_EN_0, 30, VPL_PAD_STS_0),
	LEIPZIG_GROUP(gpio0_data31, VPL_PAD_EN_0, 31, VPL_PAD_STS_0),
	/* GPIO1 */
	LEIPZIG_GROUP(gpio1_data0, VPL_PAD_EN_1, 0, VPL_PAD_STS_1),	//178~209
	LEIPZIG_GROUP(gpio1_data1, VPL_PAD_EN_1, 1, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data2, VPL_PAD_EN_1, 2, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data3, VPL_PAD_EN_1, 3, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data4, VPL_PAD_EN_1, 4, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data5, VPL_PAD_EN_1, 5, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data6, VPL_PAD_EN_1, 6, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data7, VPL_PAD_EN_1, 7, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data8, VPL_PAD_EN_1, 8, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data9, VPL_PAD_EN_1, 9, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data10, VPL_PAD_EN_1, 10, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data11, VPL_PAD_EN_1, 11, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data12, VPL_PAD_EN_1, 12, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data13, VPL_PAD_EN_1, 13, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data14, VPL_PAD_EN_1, 14, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data15, VPL_PAD_EN_1, 15, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data16, VPL_PAD_EN_1, 16, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data17, VPL_PAD_EN_1, 17, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data18, VPL_PAD_EN_1, 18, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data19, VPL_PAD_EN_1, 19, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data20, VPL_PAD_EN_1, 20, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data21, VPL_PAD_EN_1, 21, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data22, VPL_PAD_EN_1, 22, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data23, VPL_PAD_EN_1, 23, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data24, VPL_PAD_EN_1, 24, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data25, VPL_PAD_EN_1, 25, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data26, VPL_PAD_EN_1, 26, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data27, VPL_PAD_EN_1, 27, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data28, VPL_PAD_EN_1, 28, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data29, VPL_PAD_EN_1, 29, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data30, VPL_PAD_EN_1, 30, VPL_PAD_STS_1),
	LEIPZIG_GROUP(gpio1_data31, VPL_PAD_EN_1, 31, VPL_PAD_STS_1),
	/* GPIO2 */
	LEIPZIG_GROUP(gpio2_data0, VPL_PAD_EN_2, 0, VPL_PAD_STS_2),	//210~241
	LEIPZIG_GROUP(gpio2_data1, VPL_PAD_EN_2, 1, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data2, VPL_PAD_EN_2, 2, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data3, VPL_PAD_EN_2, 3, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data4, VPL_PAD_EN_2, 4, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data5, VPL_PAD_EN_2, 5, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data6, VPL_PAD_EN_2, 6, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data7, VPL_PAD_EN_2, 7, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data8, VPL_PAD_EN_2, 8, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data9, VPL_PAD_EN_2, 9, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data10, VPL_PAD_EN_2, 10, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data11, VPL_PAD_EN_2, 11, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data12, VPL_PAD_EN_2, 12, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data13, VPL_PAD_EN_2, 13, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data14, VPL_PAD_EN_2, 14, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data15, VPL_PAD_EN_2, 15, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data16, VPL_PAD_EN_2, 16, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data17, VPL_PAD_EN_2, 17, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data18, VPL_PAD_EN_2, 18, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data19, VPL_PAD_EN_2, 19, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data20, VPL_PAD_EN_2, 20, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data21, VPL_PAD_EN_2, 21, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data22, VPL_PAD_EN_2, 22, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data23, VPL_PAD_EN_2, 23, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data24, VPL_PAD_EN_2, 24, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data25, VPL_PAD_EN_2, 25, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data26, VPL_PAD_EN_2, 26, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data27, VPL_PAD_EN_2, 27, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data28, VPL_PAD_EN_2, 28, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data29, VPL_PAD_EN_2, 29, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data30, VPL_PAD_EN_2, 30, VPL_PAD_STS_2),
	LEIPZIG_GROUP(gpio2_data31, VPL_PAD_EN_2, 31, VPL_PAD_STS_2),
};

static const char * const dbg_groups[] = {"scrtu_dbg", "ca55u_dbg", "usb30c_dbg",
					"vq7u_dbg"};
static const char * const ssic_groups[] = {"ssic3_sgl_ma", "ssic2_sgl_ma",
					"ssic1_sgl_ma", "ssic0_sgl_sla",
					"ssic0_sgl_ma",	"ssic0_quad_ma"};
static const char * const mshc_groups[] = {"mshc"};
static const char * const clk_groups[] = {"monitor_clk"};
static const char * const irdac_groups[] = {"irdac"};
static const char * const i2s_groups[] = {"i2ssc_tx_sla", "i2ssc_tx_ma",
					"i2ssc_rx_sla", "i2ssc_rx_ma",
					"i2ssc_ma_clk"};
static const char * const i2c_groups[] = {"i2cc2_pos1", "i2cc2_pos0",
					"i2cc1_pos1", "i2cc1_pos0",
					"i2cc0"};
static const char * const eqosc_groups[] = {"eqosc_tx_out_clk", "eqosc_tx_in_clk",
					"eqosc_rx_clk", "eqosc_ref_clk",
					"eqosc_sec3", "eqosc_sec2",
					"eqosc_sec1", "eqosc_sec0"};
static const char * const ddrnsdmc_groups[] = {"ddrnsdmc_test"};
static const char * const adcdc_groups[] = {"adcdcc"};
static const char * const usbc_groups[] = {"usb30c_vbus_oc", "usb30c_drv_vbus",
					"usb20c_vbus_oc", "usb20c_drv_vbus"};
static const char * const uart_groups[] = {"uart4_pos2", "uart4_pos1", "uart4_pos0",
					"uart3_pos2", "uart3_pos1", "uart3_pos0",
					"uart2_pos2", "uart2_pos1", "uart2_pos0",
					"uart1_pos2_sec1", "uart1_pos2_sec0",
					"uart1_pos1_sec1", "uart1_pos1_sec0",
					"uart1_pos0_sec1", "uart1_pos0_sec0",
					"uart0_pos2_sec1", "uart0_pos2_sec0",
					"uart0_pos1_sec1", "uart0_pos1_sec0",
					"uart0_pos0_sec1", "uart0_pos0_sec0"};
static const char * const wdtc_groups[] = {"wdtc"};
static const char * const voc_groups[] = {"voc1_sec7_pos1", "voc1_sec7_pos0",
					"voc1_sec6", "voc1_sec5",
					"voc1_sec4",
					"voc1_sec3_pos1", "voc1_sec3_pos0",
					"voc1_sec2_pos1", "voc1_sec2_pos0",
					"voc1_sec1", "voc1_sec0",
					"voc1_clk_pos1", "voc1_clk_pos0"};

static const char * const vic_groups[] = {"vic1_sec5", "vic1_sec4",
					"vic1_sec3", "vic1_sec2",
					"vic1_sec1", "vic1_sec0",
					"vic0_sec5", "vic0_sec4",
					"vic0_sec3", "vic0_sec2",
					"vic0_sec1", "vic0_sec0",
					"vic_ref_sync", "vic_ref_clk"};

static const char * const agpo0_groups[] = {"agpo0_pos0", "agpo0_pos1",
					"agpo0_pos2", "agpo0_pos3",
					"agpo0_pos4"};

static const char * const agpo1_groups[] = {"agpo1_pos0", "agpo1_pos1",
					"agpo1_pos2", "agpo1_pos3",
					"agpo1_pos4"};

static const char * const agpo2_groups[] = {"agpo2_pos0", "agpo2_pos1",
					"agpo2_pos2", "agpo2_pos3",
					"agpo2_pos4"};

static const char * const agpo3_groups[] = {"agpo3_pos0", "agpo3_pos1",
					"agpo3_pos2", "agpo3_pos3",
					"agpo3_pos4"};

static const char * const agpo4_groups[] = {"agpo4_pos0", "agpo4_pos1",
					"agpo4_pos2", "agpo4_pos3",
					"agpo4_pos4"};

static const char * const agpo5_groups[] = {"agpo5_pos0", "agpo5_pos1",
					"agpo5_pos2", "agpo5_pos3",
					"agpo5_pos4"};

static const char * const agpo6_groups[] = {"agpo6_pos0", "agpo6_pos1",
					"agpo6_pos2", "agpo6_pos3",
					"agpo6_pos4"};

static const char * const agpo7_groups[] = {"agpo7_pos0", "agpo7_pos1",
					"agpo7_pos2", "agpo7_pos3",
					"agpo7_pos4"};

static const char * const agpo8_groups[] = {"agpo8_pos0", "agpo8_pos1",
					"agpo8_pos2", "agpo8_pos3",
					"agpo8_pos4"};

static const char * const agpo9_groups[] = {"agpo9_pos0", "agpo9_pos1",
					"agpo9_pos2", "agpo9_pos3",
					"agpo9_pos4"};

static const char * const agpo10_groups[] = {"agpo10_pos0", "agpo10_pos1",
					"agpo10_pos2", "agpo10_pos3",
					"agpo10_pos4"};

static const char * const agpo11_groups[] = {"agpo11_pos0", "agpo11_pos1",
					"agpo11_pos2", "agpo11_pos3",
					"agpo11_pos4"};

static const char * const gpio0_groups[] = {"gpio0_data0", "gpio0_data1",
					"gpio0_data2", "gpio0_data3",
					"gpio0_data4", "gpio0_data5",
					"gpio0_data6", "gpio0_data7",
					"gpio0_data8", "gpio0_data9",
					"gpio0_data10", "gpio0_data11",
					"gpio0_data12", "gpio0_data13",
					"gpio0_data14", "gpio0_data15",
					"gpio0_data16", "gpio0_data17",
					"gpio0_data18", "gpio0_data19",
					"gpio0_data20", "gpio0_data21",
					"gpio0_data22", "gpio0_data23",
					"gpio0_data24", "gpio0_data25",
					"gpio0_data26", "gpio0_data27",
					"gpio0_data28", "gpio0_data29",
					"gpio0_data30", "gpio0_data31"};

static const char * const gpio1_groups[] = {"gpio1_data0", "gpio1_data1",
					"gpio1_data2", "gpio1_data3",
					"gpio1_data4", "gpio1_data5",
					"gpio1_data6", "gpio1_data7",
					"gpio1_data8", "gpio1_data9",
					"gpio1_data10", "gpio1_data11",
					"gpio1_data12", "gpio1_data13",
					"gpio1_data14", "gpio1_data15",
					"gpio1_data16", "gpio1_data17",
					"gpio1_data18", "gpio1_data19",
					"gpio1_data20", "gpio1_data21",
					"gpio1_data22", "gpio1_data23",
					"gpio1_data24", "gpio1_data25",
					"gpio1_data26", "gpio1_data27",
					"gpio1_data28", "gpio1_data29",
					"gpio1_data30", "gpio1_data31"};

static const char * const gpio2_groups[] = {"gpio2_data0", "gpio2_data1",
					"gpio2_data2", "gpio2_data3",
					"gpio2_data4", "gpio2_data5",
					"gpio2_data6", "gpio2_data7",
					"gpio2_data8", "gpio2_data9",
					"gpio2_data10", "gpio2_data11",
					"gpio2_data12", "gpio2_data13",
					"gpio2_data14", "gpio2_data15",
					"gpio2_data16", "gpio2_data17",
					"gpio2_data18", "gpio2_data19",
					"gpio2_data20", "gpio2_data21",
					"gpio2_data22", "gpio2_data23",
					"gpio2_data24", "gpio2_data25",
					"gpio2_data26", "gpio2_data27",
					"gpio2_data28", "gpio2_data29",
					"gpio2_data30", "gpio2_data31"};

#define FUNCTION(fname) { \
	.name = #fname, \
	.grps = fname##_groups, \
	.ngrps = ARRAY_SIZE(fname##_groups), \
}

static const struct leipzig_function_desc leipzig_functions[] = {
	FUNCTION(dbg),
	FUNCTION(ssic),
	FUNCTION(mshc),
	FUNCTION(clk),
	FUNCTION(irdac),
	FUNCTION(i2s),
	FUNCTION(i2c),
	FUNCTION(eqosc),
	FUNCTION(ddrnsdmc),
	FUNCTION(adcdc),
	FUNCTION(usbc),
	FUNCTION(uart),
	FUNCTION(wdtc),
	FUNCTION(voc),
	FUNCTION(vic),
	FUNCTION(agpo0),
	FUNCTION(agpo1),
	FUNCTION(agpo2),
	FUNCTION(agpo3),
	FUNCTION(agpo4),
	FUNCTION(agpo5),
	FUNCTION(agpo6),
	FUNCTION(agpo7),
	FUNCTION(agpo8),
	FUNCTION(agpo9),
	FUNCTION(agpo10),
	FUNCTION(agpo11),
	FUNCTION(gpio0),
	FUNCTION(gpio1),
	FUNCTION(gpio2),
};

static const struct leipzig_pinctrl_dev_data pctrl_data = {
	.name = "leipzig_pinctrl",
	.ngpios = ARRAY_SIZE(leipzig_pins),
	.pins = leipzig_pins,
	.npins = ARRAY_SIZE(leipzig_pins),
	.grps = leipzig_groups,
	.ngrps = ARRAY_SIZE(leipzig_groups),
	.funcs = leipzig_functions,
	.nfuncs = ARRAY_SIZE(leipzig_functions),
};

static const struct pinconf_generic_params leipzig_pconf_params[] = {
	{"bias-repeater", PIN_CONFIG_BIAS_BUS_HOLD, 3},
	{"slew-rate-enable", PIN_CONFIG_SLEW_RATE, 1},
	{"slew-rate-disable", PIN_CONFIG_SLEW_RATE, 0},
};

static void pinctrl_set_field_pinconf(struct pinctrl_dev *pctldev,
				      unsigned int offset, unsigned int field,
				      unsigned int val)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	unsigned int read_val, write_val;

	regmap_read(pctl->regmap, offset, &read_val);
	write_val = (read_val & (~field)) | (val & field);
	regmap_write(pctl->regmap, offset, write_val);
}

static unsigned int pinctrl_get_field_pinconf(struct pinctrl_dev *pctldev,
					      unsigned int offset,
					      unsigned int field)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	unsigned int read_val;

	regmap_read(pctl->regmap, offset, &read_val);

	return read_val & field;
}

static int leipzig_pinconf_slew_get(struct pinctrl_dev *pctldev,
				    const struct pinctrl_pin_desc *pin_desc,
				    unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field, read_val;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_SLEW_0 + (4 * (pintype->type_num / 32));
	else
		reg = SYSC_OUTPUT_SLEW; //OUTPUT

	bit = pintype->type_num % 32;
	field = 0x01 << bit;

	read_val = pinctrl_get_field_pinconf(pctldev, reg, field) >> bit;

	return read_val;
}

static int leipzig_pinconf_schmitt_get(struct pinctrl_dev *pctldev,
				const struct pinctrl_pin_desc *pin_desc,
				unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, bit, field, read_val;

	reg = read_val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_SMIT_0 + (4 * (pintype->type_num / 32));
	else
		reg = SYSC_INPUT_SMIT; //INPUT

	bit = pintype->type_num % 32;
	field = 0x01 << bit;

	read_val = pinctrl_get_field_pinconf(pctldev, reg, field) >> bit;

	return read_val == 0x01 ? 0x01 : -EINVAL;
}

static int leipzig_pinconf_drive_get(struct pinctrl_dev *pctldev,
				     const struct pinctrl_pin_desc *pin_desc,
				     unsigned int arg)
{
	struct leipzig_pintype *pintype =
			(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field, read_val;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_DRV_0 + (4 * (pintype->type_num / 16));
	else
		reg = SYSC_OUTPUT_DRV; //OUTPUT

	bit = pintype->type_num % 16;
	field = 0x03 << (bit << 1);

	read_val = pinctrl_get_field_pinconf(pctldev, reg, field) >> (bit << 1);

	if (read_val == 0x01)
		val = 4;
	else if (read_val == 0x00)
		val = 2;
	else if (read_val == 0x02)
		val = 8;
	else
		val = 12;

	return val;
}

static int leipzig_pinconf_pull_get(struct pinctrl_dev *pctldev,
				    const struct pinctrl_pin_desc *pin_desc,
				    unsigned int arg)
{
	struct leipzig_pintype *pintype =
			(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field, read_val;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_PU_0 + (4 * (pintype->type_num / 16));
	else if (pintype->type == INPUT)
		reg = SYSC_INPUT_PU; //INPUT
	else
		reg = SYSC_OUTPUT_PU; //OUTPUT

	bit = pintype->type_num % 16;
	field = 0x03 << (bit << 1);
	val = arg << (bit << 1);

	read_val = pinctrl_get_field_pinconf(pctldev, reg, field);

	if (read_val == val)
		return 0x01;
	else
		return -EINVAL;
}

static int leipzig_pconf_pin_config_get(struct pinctrl_dev *pctldev,
					unsigned int pin, unsigned long *config)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const struct pinctrl_pin_desc *pin_desc = &pctl->devdata->pins[pin];
	enum pin_config_param param = pinconf_to_config_param(*config);
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	int ret, arg = 0;

	ret = -EINVAL;
	switch (param) {
	case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
		ret = leipzig_pinconf_pull_get(pctldev, pin_desc, 0x0);
		break;
	case PIN_CONFIG_BIAS_PULL_UP:
		ret = leipzig_pinconf_pull_get(pctldev, pin_desc, 0x01);
		break;
	case PIN_CONFIG_BIAS_PULL_DOWN:
		ret = leipzig_pinconf_pull_get(pctldev, pin_desc, 0x02);
		break;
	case PIN_CONFIG_BIAS_BUS_HOLD:
		ret = leipzig_pinconf_pull_get(pctldev, pin_desc, 0x03);
		break;
	case PIN_CONFIG_DRIVE_STRENGTH:
		if (pintype->type != INPUT)
			ret = leipzig_pinconf_drive_get(pctldev, pin_desc, arg);
		break;
	case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
		if (pintype->type != OUTPUT)
			ret = leipzig_pinconf_schmitt_get(pctldev, pin_desc, arg);
		break;
	case PIN_CONFIG_SLEW_RATE:
		if (pintype->type != INPUT)
			ret = leipzig_pinconf_slew_get(pctldev, pin_desc, arg);
		break;
	default:
		return -ENOTSUPP;
	}

	if (ret < 0)
		return ret;

	*config = pinconf_to_config_packed(param, (u16)ret);

	return 0;
}

static int leipzig_pinconf_pull_set(struct pinctrl_dev *pctldev,
				    const struct pinctrl_pin_desc *pin_desc,
				    unsigned int param, unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_PU_0 + (4 * (pintype->type_num / 16));
	else if (pintype->type == INPUT)
		reg = SYSC_INPUT_PU; //INPUT
	else
		reg = SYSC_OUTPUT_PU; //OUTPUT

	bit = pintype->type_num % 16;
	field = 0x03 << (bit << 1);
	val = arg << (bit << 1);

	dev_dbg(pctldev->dev, "pin %s pull set reg 0x%x val 0x%x\n",
						pin_desc->name, reg, val);
	pinctrl_set_field_pinconf(pctldev, reg, field, val);

	return 0;
}

static int leipzig_pinconf_drive_set(struct pinctrl_dev *pctldev,
				     const struct pinctrl_pin_desc *pin_desc,
				     unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_DRV_0 + (4 * (pintype->type_num / 16));
	else
		reg = SYSC_OUTPUT_DRV; //OUTPUT

	bit = pintype->type_num % 16;
	field = 0x03 << (bit << 1);

	if (arg == 2)
		val = 0x0;
	else if (arg == 4)
		val = 0x1;
	else if (arg == 8)
		val = 0x2;
	else if (arg == 12)
		val = 0x3;
	else  {
		val = 0x0;
		dev_err(pctldev->dev, "pin %s unsupported drive strength parameter %u\n",
							pin_desc->name, arg);
	}

	val = val << (bit << 1);
	dev_dbg(pctldev->dev, "pin %s drive set reg 0x%x val 0x%x\n",
						pin_desc->name, reg, val);
	pinctrl_set_field_pinconf(pctldev, reg, field, val);

	return 0;
}

static int leipzig_pinconf_schmitt_set(struct pinctrl_dev *pctldev,
				       const struct pinctrl_pin_desc *pin_desc,
				       unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_SMIT_0 + (4 * (pintype->type_num / 32));
	else
		reg = SYSC_INPUT_SMIT; //INPUT

	bit = pintype->type_num % 32;
	field = 0x01 << bit;
	val = arg << bit;

	dev_dbg(pctldev->dev, "pin %s schmitt set reg 0x%x val 0x%x\n",
						pin_desc->name, reg, val);
	pinctrl_set_field_pinconf(pctldev, reg, field, val);

	return 0;
}

static int leipzig_pinconf_slew_set(struct pinctrl_dev *pctldev,
				    const struct pinctrl_pin_desc *pin_desc,
				    unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	unsigned int reg, val, bit, field;

	reg = val = bit = field = 0;
	if (pintype->type == INOUT)
		reg = SYSC_INOUT_SLEW_0 + (4 * (pintype->type_num / 32));
	else
		reg = SYSC_OUTPUT_SLEW; //OUTPUT

	bit = pintype->type_num % 32;
	field = 0x01 << bit;
	val = arg << bit;

	dev_dbg(pctldev->dev, "pin %s slew set reg 0x%x val 0x%x\n",
						pin_desc->name, reg, val);
	pinctrl_set_field_pinconf(pctldev, reg, field, val);

	return 0;
}

static int leipzig_pinconf_set(struct pinctrl_dev *pctldev,
			       const struct pinctrl_pin_desc *pin_desc,
			       unsigned int param, unsigned int arg)
{
	struct leipzig_pintype *pintype =
		(struct leipzig_pintype *) pin_desc->drv_data;
	int ret = 0;

	switch (param) {
	case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
	case PIN_CONFIG_BIAS_PULL_UP:
		ret = leipzig_pinconf_pull_set(pctldev, pin_desc, param, arg);
		break;
	case PIN_CONFIG_BIAS_PULL_DOWN:
		ret = leipzig_pinconf_pull_set(pctldev, pin_desc, param, 0x02);
		break;
	case PIN_CONFIG_BIAS_BUS_HOLD:
		ret = leipzig_pinconf_pull_set(pctldev, pin_desc, param, 0x03);
		break;
	case PIN_CONFIG_DRIVE_STRENGTH:
		if (pintype->type != INPUT)
			ret = leipzig_pinconf_drive_set(pctldev, pin_desc, arg);
		else
			dev_err(pctldev->dev, "pin %s unsupported drive strength\n", pin_desc->name);

		break;
	case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
		if (pintype->type != OUTPUT)
			ret = leipzig_pinconf_schmitt_set(pctldev, pin_desc, arg);
		else
			dev_err(pctldev->dev, "pin %s unsupported schmitt\n", pin_desc->name);

		break;
	case PIN_CONFIG_SLEW_RATE:
		if (pintype->type != INPUT)
			ret = leipzig_pinconf_slew_set(pctldev, pin_desc, arg);
		else
			dev_err(pctldev->dev, "pin %s unsupported slew rate\n", pin_desc->name);

		break;
	case PIN_CONFIG_PERSIST_STATE:
		/* gpiolib print unsupport log */
		return -ENOTSUPP;
	default:
		dev_err(pctldev->dev, "unsupported configuration parameter %d\n", param);
		return -ENOTSUPP;
	}

	return ret;
}

static int leipzig_pconf_pin_config_set(struct pinctrl_dev *pctldev,
					unsigned int pin, unsigned long *configs,
					unsigned int num_configs)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const struct pinctrl_pin_desc *pin_desc = &pctl->devdata->pins[pin];
	enum pin_config_param param;
	unsigned int arg;
	int i, ret;

	for (i = 0; i < num_configs; i++) {
		param = pinconf_to_config_param(configs[i]);
		arg = pinconf_to_config_argument(configs[i]);

		ret = leipzig_pinconf_set(pctldev, pin_desc, param, arg);
		if (ret < 0)
			return ret;
	}

	return 0;
}

static int leipzig_pconf_pin_config_group_set(struct pinctrl_dev *pctldev,
					      unsigned int selector,
					      unsigned long *configs,
					      unsigned int num_configs)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const unsigned int *pins = pctl->devdata->grps[selector].pins;
	unsigned int npins = pctl->devdata->grps[selector].npins;
	int i;

	for (i = 0; i < npins; i++)
		leipzig_pconf_pin_config_set(pctldev, pins[i], configs, num_configs);

	return 0;
}

static const struct pinconf_ops leipzig_pconf_ops = {
	.pin_config_get = leipzig_pconf_pin_config_get,
	.pin_config_set = leipzig_pconf_pin_config_set,
	.pin_config_group_set = leipzig_pconf_pin_config_group_set,
	.is_generic = true,
};

static int leipzig_pctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
	return ARRAY_SIZE(leipzig_groups);
}

static const char *leipzig_pctrl_get_group_name(struct pinctrl_dev *pctldev,
						unsigned int selector)
{
	return leipzig_groups[selector].name;
}

static int leipzig_pctrl_get_group_pins(struct pinctrl_dev *pctldev,
					unsigned int selector,
					const unsigned int **pins,
					unsigned int *num_pins)
{
	*pins = (unsigned int *) leipzig_groups[selector].pins;
	*num_pins = leipzig_groups[selector].npins;

	return 0;
}

static const struct pinctrl_ops leipzig_pctrl_ops = {
	.get_groups_count = leipzig_pctrl_get_groups_count,
	.get_group_name = leipzig_pctrl_get_group_name,
	.get_group_pins = leipzig_pctrl_get_group_pins,
	.dt_node_to_map = pinconf_generic_dt_node_to_map_all,
	.dt_free_map = pinctrl_utils_free_map,
};

static void clear_conflict_pinmux(struct pinctrl_dev *pctldev,
				  unsigned int group_selector)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const struct leipzig_group_desc *grp = &pctl->devdata->grps[group_selector];
	const struct leipzig_group_desc *confl_grp;
	const short int *confl_grps;
	int i, num_confl, val;

	confl_grps = grp->confl_grps;
	num_confl = grp->nconfl_grps;

	for (i = 0; i < num_confl; i++) {
		if (confl_grps[i] < 0)
			continue;

		confl_grp = &pctl->devdata->grps[(int)confl_grps[i]];
		val = 0x1 << confl_grp->bit;
		regmap_write(pctl->regmap, confl_grp->en_ofs + CLEAR_OFFSET, val);
	}

}

static int leipzig_gpio_request_enable(struct pinctrl_dev *pctldev,
				       struct pinctrl_gpio_range *range,
				       unsigned int offset)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const struct leipzig_group_desc *grp;
	unsigned long flags;
	unsigned int val, grp_selector;

	if (offset >= GPIO_NUMS) {
		dev_err(pctl->dev, "invalid gpio pin %d.\n", offset);
		return -EINVAL;
	}

	grp_selector = offset + GPIO_GROUP_OFFSET;
	grp = &pctl->devdata->grps[grp_selector];
	spin_lock_irqsave(&pinmux_lock, flags);

	/* for this pin disable others pinmux function */
	clear_conflict_pinmux(pctldev, grp_selector);

	val = 0x01 << grp->bit;
	regmap_write(pctl->regmap, grp->en_ofs, val);

	spin_unlock_irqrestore(&pinmux_lock, flags);

	dev_dbg(pctldev->dev, "gpio request offset:%d, reg_off:0x%08x, val:0x%08x\n",
							offset, grp->en_ofs, val);

	return 0;
}

static void leipzig_gpio_disable_free(struct pinctrl_dev *pctldev,
				      struct pinctrl_gpio_range *range,
				      unsigned int offset)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const struct leipzig_group_desc *grp;
	unsigned int val, grp_selector;

	grp_selector = offset + GPIO_GROUP_OFFSET;
	grp = &pctl->devdata->grps[grp_selector];
	val = 0x01 << grp->bit;
	regmap_write(pctl->regmap, grp->en_ofs + CLEAR_OFFSET, val);

	dev_dbg(pctldev->dev, "gpio free offset:%d, reg_off:0x%08x, val:0x%08x\n",
							offset, grp->en_ofs, val);
}

int leipzig_pmux_get_functions_count(struct pinctrl_dev *pctldev)
{
	return ARRAY_SIZE(leipzig_functions);
}

const char *leipzig_pmux_get_function_name(struct pinctrl_dev *pctldev,
					   unsigned int selector)
{
	return leipzig_functions[selector].name;
}

static int leipzig_pmux_get_function_groups(struct pinctrl_dev *pctldev,
					    unsigned int selector,
					    const char * const **groups,
					    unsigned int * const num_groups)
{
	*groups = leipzig_functions[selector].grps;
	*num_groups = leipzig_functions[selector].ngrps;

	return 0;
}

int leipzig_pmux_set_mux(struct pinctrl_dev *pctldev, unsigned int func_selector,
			 unsigned int group_selector)
{
	struct leipzig_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	const struct leipzig_group_desc *grp = &pctl->devdata->grps[group_selector];
	unsigned long flags;
	unsigned long val;

	dev_dbg(pctldev->dev, "name:%s, reg:0x%x, bit:%d\n", grp->name,
						grp->en_ofs, grp->bit);

	spin_lock_irqsave(&pinmux_lock, flags);
	/* for this pin disable others pinmux function */
	clear_conflict_pinmux(pctldev, group_selector);

	val = 0x01 << grp->bit;
	regmap_write(pctl->regmap, grp->en_ofs, val);
	spin_unlock_irqrestore(&pinmux_lock, flags);

	return 0;
}

static const struct pinmux_ops leipzig_pmux_ops = {
	.get_functions_count = leipzig_pmux_get_functions_count,
	.get_function_name = leipzig_pmux_get_function_name,
	.get_function_groups = leipzig_pmux_get_function_groups,
	.set_mux = leipzig_pmux_set_mux,
	.gpio_request_enable = leipzig_gpio_request_enable,
	.gpio_disable_free = leipzig_gpio_disable_free,
	.strict = false,
};

static struct pinctrl_desc leipzig_pctl_desc = {
	.confops = &leipzig_pconf_ops,
	.pctlops = &leipzig_pctrl_ops,
	.pmxops = &leipzig_pmux_ops,
	.num_custom_params = ARRAY_SIZE(leipzig_pconf_params),
	.custom_params = leipzig_pconf_params,
	.owner = THIS_MODULE,
};

static int leipzig_pinctrl_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node, *node;
	struct leipzig_pinctrl *pctrl;

	pctrl = devm_kzalloc(&pdev->dev, sizeof(*pctrl), GFP_KERNEL);
	if (!pctrl)
		return -ENOMEM;

	node = of_parse_phandle(np, "sysc-regmap", 0);
	if (node) {
		pctrl->regmap = syscon_node_to_regmap(node);
		if (IS_ERR(pctrl->regmap))
			return PTR_ERR(pctrl->regmap);
	} else {
		dev_err(&pdev->dev, "Cannot find pinctrl regmap sysc\n");
		return -EINVAL;
	}

	pctrl->dev = &pdev->dev;
	pctrl->devdata = &pctrl_data;
	leipzig_pctl_gpio_range.npins = pctrl->devdata->ngpios;
	leipzig_pctl_desc.name = dev_name(&pdev->dev);
	leipzig_pctl_desc.pins = pctrl->devdata->pins;
	leipzig_pctl_desc.npins = pctrl->devdata->npins;
	pctrl->pctldev = devm_pinctrl_register(&pdev->dev, &leipzig_pctl_desc,
						pctrl);
	if (!pctrl->pctldev) {
		dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
		return -ENODEV;
	}

	platform_set_drvdata(pdev, pctrl);
	pinctrl_add_gpio_range(pctrl->pctldev, &leipzig_pctl_gpio_range);

	return 0;
}

static const struct of_device_id leipzig_pinctrl_of_match[] = {
	{ .compatible = "vatics,leipzig-pinctrl", },
	{ },
};

static struct platform_driver leipzig_pinctrl_driver = {
	.driver = {
		.name = "leipzig-pinctrl",
		.owner = THIS_MODULE,
		.of_match_table = leipzig_pinctrl_of_match,
	},
	.probe = leipzig_pinctrl_probe,
};

static int __init leipzig_pinctrl_init(void)
{
	return platform_driver_register(&leipzig_pinctrl_driver);
}
arch_initcall(leipzig_pinctrl_init);


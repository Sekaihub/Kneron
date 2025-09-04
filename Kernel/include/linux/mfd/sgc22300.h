/* SPDX-License-Identifier: <SPDX License Expression> */
#ifndef __LINUX_MFD_SGC22300_H
#define __LINUX_MFD_SGC22300_H

/* PMU */
#define PMU_GEN_STAT		0x04
#define PMU_GEN_CTRL		0x08
#define PMU_STAT_CLEAR		0x0C
#define PMU_CTRL_SHIFT		0x10
#define PMU_WDATA_SHIFT		0x14
#define PMU_RDATA_SHIFT		0x18
#define PMU_ADC_CONV_DATA	0x1C

/* General status register */
#define VI_READY_STAT		BIT(16)
#define OSC_READY_STAT		BIT(12)
#define RTC_ALARM_STAT		BIT(8)
#define ADC_COMP_STAT		BIT(4)
#define SHIFT_DONE_STAT_MASK	BIT(0)
#define SHIFT_DONE_STAT		BIT(0)

/* General control register */
#define ADC_CONV_MODE_MASK	GENMASK(25, 24)
#define ADC_CONV_MODE_SHIFT	24
#define ADC_MODE_TEMP		0x0
#define ADC_MODE_DIF_VOLT_1_0	0x1
#define ADC_MODE_DIF_VOLT_0_5	0x2
#define ADC_MODE_DIF_VOLT_HI	0x3
#define ADC_CONV_CHAN_MASK	GENMASK(22, 20)
#define ADC_CONV_CHAN_SHIFT	20
#define ADC_CONV_START		BIT(16)
#define RTC_CLK_DIV_EN_MASK	BIT(12)
#define RTC_CLK_DIV_EN_SHIFT	12
#define RTC_ALARM_RST_MASK	BIT(8)
#define RTC_ALARM_RST		BIT(8)
#define OSC_EN			BIT(4)
#define D_IF_EN			BIT(0)

/* Status clear register */
#define ADC_COMP_CLEAR		BIT(4)
#define SHIFT_DONE_CLEAR	BIT(0)

/* Shift mode control register */
#define SHIFT_ADDR_MASK		GENMASK(11, 8)
#define SHIFT_ADDR_SHIFT	8
#define SHIFT_W_EN_MASK		BIT(4)
#define SHIFT_START_MASK	BIT(0)
#define SHIFT_START_STAT	BIT(0)

/* ADC conversion data register */
#define ADC_DATA_MASK		GENMASK(11, 0)

/* SGC 22300 */
#define SGC_TICKGEN		0x01
#define SGC_TRIMWR		0x02
#define SGC_GPR			0x08
#define SGC_CRYTRIM		0x09
#define SGC_TCXO1		0x0A
#define SGC_TIME		0x0B
#define SGC_ALARM		0x0C
#define SGC_TRIM		0x0D
#define SGC_CONFIG		0x0E
#define SGC_TCXO2		0x0F

/* trim */
#define SGC_TRIM_AO_MASK	BIT(27)
#define SGC_TRIM_AO_EN		BIT(27)
#define SGC_TRIM_CT_MASK	GENMASK(26, 22)
#define SGC_TRIM_CT_SHIFT	22
#define SGC_TRIM_TT_MASK	GENMASK(21, 19)
#define SGC_TRIM_TT_SHIFT	19
#define SGC_TRIM_VT_MASK	GENMASK(18, 14)
#define SGC_TRIM_VT_SHIFT	14
#define SGC_TRIM_IT_MASK	GENMASK(13, 11)
#define SGC_TRIM_IT_SHIFT	11
#define SGC_TRIM_DIGIT_MASK	GENMASK(10, 0)


/* config */
#define SGC_CONFIG_RST_MASK	BIT(30)
#define SGC_CONFIG_RST_SHIFT	30
#define SGC_CONFIG_EAON_MASK	BIT(19)
#define SGC_CONFIG_EAON_SHIFT	19
#define SGC_CONFIG_ECA_MASK	BIT(17)
#define SGC_CONFIG_ECA_SHIFT	17
#define SGC_CONFIG_Z_MASK	BIT(1)
#define SGC_CONFIG_Z_SHIFT	1
#define SGC_CONFIG_CK_MASK	BIT(0)
#define SGC_CONFIG_CK_SHIFT	0

/* sysc */
#define SYSC_HW_CONFIG_INFO_0	0x244
#define SYSC_OPT_VT_MASK	GENMASK(26, 22)
#define SYSC_OPT_VT_SHIFT	22
#define SYSC_OPT_IT_MASK	GENMASK(29, 27)
#define SYSC_OPT_IT_SHIFT	27

struct sgc_data {
	struct device *dev;
	void __iomem *base;
	struct regmap *rmap;
	struct mutex lock;
};

int sgc_pmu_shift_reg_read(struct sgc_data *sgc, unsigned int reg,
			   unsigned int *val);
int sgc_pmu_shift_reg_write(struct sgc_data *sgc, unsigned int reg,
			    unsigned int val);

#endif /* __LINUX_MFD_SGC22300_H */

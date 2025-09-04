// SPDX-License-Identifier: <SPDX License Expression>
/*
 * Copyright (c) 2020 VATICS Inc.
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/thermal.h>
#include <linux/regmap.h>
#include <linux/delay.h>
#include <linux/iio/iio.h>
#include <linux/mfd/sgc22300.h>

#define SGC_ADC_CH_NUMS		5
#define SGC_ADC_DATA_MASK	0xFFF
#define SGC_ADC_TIMEOUT		1000

enum adc_ch_type {
	SGC_EXT_LV_CH0 = 0,
	SGC_EXT_LV_CH1 = 1,
	SGC_EXT_HV_CH2 = 2,
	SGC_EXT_HV_CH3 = 3,
	SGC_INT_TEMP_CH0 = 4,
};

enum adc_op {
	ADC_OP_DIS = 0,
	ADC_OP_EN = 1,
};

struct sgc_adc {
	struct device *dev;
	struct regmap *rmap;
	struct iio_dev *io_dev;
	struct thermal_zone_device *tzd;
	struct sgc_data *sgc_info;
	u32 ch_nums;
	struct mutex lock;
};

static void sgc_adc_set_ao_operation(struct sgc_adc *adc, int op)
{
	int val, ret;

	ret = sgc_pmu_shift_reg_read(adc->sgc_info, SGC_TRIM, &val);
	if (ret)
		goto failed;

	if (op)
		val |= SGC_TRIM_AO_EN;
	else
		val &= ~SGC_TRIM_AO_EN;

	ret = sgc_pmu_shift_reg_write(adc->sgc_info, SGC_TRIM, val);
	if (ret)
		goto failed;

	return;
failed:
	dev_err(adc->dev, "set ao operation failed !!\n");
}

static int sgc_adc_read_scale(struct sgc_adc *adc, int chan,
			      enum iio_chan_type iio_type, int *val,
			      int *val2)
{

	switch (chan) {
	case SGC_EXT_LV_CH0:
	case SGC_EXT_LV_CH1:
		/* 2000mV -> 4096 */
		*val = 0;
		*val2 = 477961;
		return IIO_VAL_INT_PLUS_NANO;
	case SGC_EXT_HV_CH2:
		/* 4000mV -> 4096 */
		*val = 0;
		*val2 = 955137;
		return IIO_VAL_INT_PLUS_NANO;
	case SGC_EXT_HV_CH3:
		/* 4000mV -> 4096 */
		*val = 0;
		*val2 = 950187;
		return IIO_VAL_INT_PLUS_NANO;
	case SGC_INT_TEMP_CH0:
		*val = 105;
		*val2 = 100;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}

static int sgc_adc_read_channel(struct sgc_adc *adc, int chan,
				enum iio_chan_type iio_type, int *val)
{
	u32 ctrl, data, stat, mode = 0x0;
	u32 times = 0;

	mutex_lock(&adc->lock);
	if (iio_type == IIO_VOLTAGE)
		mode = ADC_MODE_DIF_VOLT_HI;

	regmap_read(adc->rmap, PMU_GEN_CTRL, &ctrl);
	ctrl &= ~ADC_CONV_MODE_MASK;
	ctrl |= mode << ADC_CONV_MODE_SHIFT;
	ctrl &= ~ADC_CONV_CHAN_MASK;
	ctrl |= chan << ADC_CONV_CHAN_SHIFT;
	ctrl |= ADC_CONV_START;
	regmap_write(adc->rmap, PMU_GEN_CTRL, ctrl);

	do {
		if (++times > SGC_ADC_TIMEOUT)
			return -EINVAL;

		usleep_range(100, 200);
		regmap_read(adc->rmap, PMU_GEN_STAT, &stat);
	} while ((stat & ADC_COMP_STAT) != ADC_COMP_STAT);

	/* adc complete clear */
	regmap_write(adc->rmap, PMU_STAT_CLEAR, ADC_COMP_CLEAR);

	regmap_read(adc->rmap, PMU_ADC_CONV_DATA, &data);
	mutex_unlock(&adc->lock);

	*val = data & SGC_ADC_DATA_MASK;

	return IIO_VAL_INT;
}

static int sgc_adc_iio_read_raw(struct iio_dev *iio, struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct sgc_adc *adc = iio_priv(iio);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		sgc_adc_set_ao_operation(adc, ADC_OP_EN);
		ret = sgc_adc_read_channel(adc, chan->channel, chan->type, val);
		sgc_adc_set_ao_operation(adc, ADC_OP_DIS);
		return ret;
	case IIO_CHAN_INFO_SCALE:
		return sgc_adc_read_scale(adc, chan->channel, chan->type, val,
					  val2);
	}

	return -EINVAL;
}

static const char *sgc_channel_labels[SGC_ADC_CH_NUMS] = {
	"external lv point 0", "external lv point 1", "external hv point 0",
	"external hv point 1", "internal temp diode",
};

static int sgc_adc_read_label(struct iio_dev *iio_dev, const struct iio_chan_spec *chan,
			      char *label)
{
	return snprintf(label, PAGE_SIZE, "%s\n", sgc_channel_labels[chan->channel]);
}

static const struct iio_info sgc_adc_iio_info = {
	.read_raw = sgc_adc_iio_read_raw,
	.read_label = sgc_adc_read_label,
};

#define SGC_ADC_CHANNEL(_idx, _type) {				\
	.type = _type,						\
	.channel = SGC_##_idx,					\
	.scan_index = SGC_##_idx,				\
	.datasheet_name = #_idx,				\
	.scan_type =  {						\
		.sign = 'u',					\
		.realbits = 12,					\
		.storagebits = 12,				\
		.endianness = IIO_CPU,				\
	},							\
	.indexed = 1,						\
	.info_mask_separate = BIT(IIO_CHAN_INFO_RAW) |		\
				BIT(IIO_CHAN_INFO_SCALE),	\
}

static const struct iio_chan_spec sgc_adc_iio_channels[] = {
	SGC_ADC_CHANNEL(EXT_LV_CH0, IIO_VOLTAGE),
	SGC_ADC_CHANNEL(EXT_LV_CH1, IIO_VOLTAGE),
	SGC_ADC_CHANNEL(EXT_HV_CH2, IIO_VOLTAGE),
	SGC_ADC_CHANNEL(EXT_HV_CH3, IIO_VOLTAGE),
	SGC_ADC_CHANNEL(INT_TEMP_CH0, IIO_TEMP),
};

static inline int delta_to_kelvin(unsigned int delta)
{
	return (delta * 8000 + 24935) / 49870;
}

static inline int delta_to_celsius(unsigned int delta)
{
	return delta_to_kelvin(delta) - 273;
}

static int sgc_get_thermal_temp(struct thermal_zone_device *tz, int *temp)
{
	struct sgc_adc *adc = tz->devdata;
	u32 val;

	sgc_adc_read_channel(adc, 4, IIO_TEMP, &val);
	*temp = delta_to_celsius(val);

	return 0;
}

static struct thermal_zone_device_ops sgc_thermal_ops = {
	.get_temp = sgc_get_thermal_temp,
};


static int sgc_adc_check_pmu_vi_status(struct sgc_adc *adc)
{
	u32 val;

	/* check VI ready status */
	sgc_adc_set_ao_operation(adc, ADC_OP_EN);
	regmap_read(adc->rmap, PMU_GEN_STAT, &val);
	sgc_adc_set_ao_operation(adc, ADC_OP_DIS);

	return (val & VI_READY_STAT) != 0x0 ? 0 : -1;
}

static int sgc_gpadc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sgc_data *sgc = dev_get_drvdata(dev->parent);
	struct sgc_adc *adc_info;
	struct iio_dev *indio_dev;
	struct regmap *regmap;
	int ret;

	regmap = dev_get_regmap(dev->parent, NULL);
	if (!regmap) {
		dev_err(&pdev->dev, "Failed to get sgc regmap\n");
		return -ENODEV;
	}

	indio_dev = devm_iio_device_alloc(dev, sizeof(*adc_info));
	if (!indio_dev)
		return -ENOMEM;

	adc_info = iio_priv(indio_dev);
	adc_info->dev = dev;
	adc_info->rmap = regmap;
	adc_info->ch_nums = SGC_ADC_CH_NUMS;
	adc_info->sgc_info = sgc;
	mutex_init(&adc_info->lock);
	platform_set_drvdata(pdev, adc_info);

	ret = sgc_adc_check_pmu_vi_status(adc_info);
	if (ret) {
		dev_err(dev, "vi status not ready error !!\n");
		return ret;
	}
	dev_info(dev, "vi status ready\n");

	adc_info->tzd = thermal_zone_device_register("sgc_thermal", 0, 0,
						     adc_info, &sgc_thermal_ops,
						     NULL, 0, 0);
	if (IS_ERR(adc_info->tzd)) {
		dev_err(dev, "failed to register thermal zone device\n");
		return PTR_ERR(adc_info->tzd);
	}

	indio_dev->name = dev_name(dev);
	indio_dev->info = &sgc_adc_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = sgc_adc_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(sgc_adc_iio_channels);

	return devm_iio_device_register(dev, indio_dev);
}

static const struct of_device_id sgc_gpadc_of_match[] = {
	{ .compatible = "vatics,sgc-gpadc"},
	{ }
};
MODULE_DEVICE_TABLE(of, sgc_gpadc_of_match);

static struct platform_driver sgc_gpadc_driver = {
	.driver = {
		.name = "sgc-gpadc",
		.of_match_table = sgc_gpadc_of_match,
	},
	.probe = sgc_gpadc_probe,
};
module_platform_driver(sgc_gpadc_driver);

MODULE_DESCRIPTION("GPADC Driver for SGC 22300");
MODULE_LICENSE("GPL");

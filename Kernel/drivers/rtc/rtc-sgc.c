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
#include <linux/regmap.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/mfd/sgc22300.h>
#include <linux/rtc.h>
#include <linux/of_gpio.h>

enum rtc_time_clk {
	RTC_TIME_CLK_32KHZ = 0,
	RTC_TIME_CLK_1HZ = 1,
};

enum rtc_op {
	RTC_OP_DIS = 0,
	RTC_OP_EN = 1,
};

struct sgc_rtc {
	struct device *dev;
	struct regmap *rmap;
	struct rtc_device *rtc_dev;
	struct sgc_data *sgc_info;
	int alarm;
	int alarm_irq;
	unsigned int alarm_sec;
	int alarm_en;
	int osc_ppm;
};

static void sgc_rtc_set_time_reg_clk_mode(struct sgc_rtc *rtc,
					  enum rtc_time_clk time_clk)
{
	int config, ret;

	ret = sgc_pmu_shift_reg_read(rtc->sgc_info, SGC_CONFIG, &config);
	if (ret)
		goto failed;

	config &= ~SGC_CONFIG_CK_MASK;
	config |= time_clk << SGC_CONFIG_CK_SHIFT;

	ret = sgc_pmu_shift_reg_write(rtc->sgc_info, SGC_CONFIG, config);
	if (ret)
		goto failed;

	return;

failed:
	dev_err(rtc->dev, "set time clk mode failed !!\n");
}

static void sgc_rtc_set_alarm_output_mode(struct sgc_rtc *rtc,
					  enum rtc_op alm_op)
{
	int config, ret;

	ret = sgc_pmu_shift_reg_read(rtc->sgc_info, SGC_CONFIG, &config);
	if (ret)
		goto failed;

	config &= ~SGC_CONFIG_Z_MASK;
	config |= alm_op << SGC_CONFIG_Z_SHIFT;

	ret = sgc_pmu_shift_reg_write(rtc->sgc_info, SGC_CONFIG, config);
	if (ret)
		goto failed;

	return;

failed:
	dev_err(rtc->dev, "set alarm output mode failed !!\n");
}

static void sgc_rtc_set_alarm_reset(struct sgc_rtc *rtc)
{
	regmap_update_bits(rtc->rmap, PMU_GEN_CTRL, RTC_ALARM_RST_MASK,
			   RTC_ALARM_RST);
}

static irqreturn_t rtc_alarm_interrupt(int irq, void *id)
{
	struct sgc_rtc *rtc = id;
	struct rtc_device *rdev = rtc->rtc_dev;

	rtc_update_irq(rdev, 1, RTC_IRQF | RTC_AF);

	return IRQ_HANDLED;
}

static int sgc_rtc_read_time(struct device *dev, struct rtc_time *time)
{
	struct sgc_rtc *rtc = dev_get_drvdata(dev);
	unsigned int sec;
	int ret;

	ret = sgc_pmu_shift_reg_read(rtc->sgc_info, SGC_TIME, &sec);
	if (ret)
		dev_err(rtc->dev, "read rtc time failed !!\n");

	rtc_time64_to_tm(sec, time);

	dev_dbg(dev, "%s to %u. %d/%d/%d %d:%02u:%02u\n", __func__,
		sec,
		time->tm_mon + 1,
		time->tm_mday,
		time->tm_year + 1900,
		time->tm_hour,
		time->tm_min,
		time->tm_sec
	);

	return ret;
}

static int sgc_rtc_set_time(struct device *dev, struct rtc_time *time)
{
	struct sgc_rtc *rtc = dev_get_drvdata(dev);
	unsigned long sec;
	int ret;

	sec = rtc_tm_to_time64(time);

	dev_dbg(dev, "%s to %lu. %d/%d/%d %d:%02u:%02u\n", __func__,
		 sec,
		 time->tm_mon+1,
		 time->tm_mday,
		 time->tm_year+1900,
		 time->tm_hour,
		 time->tm_min,
		 time->tm_sec
	);

	ret = sgc_pmu_shift_reg_write(rtc->sgc_info, SGC_TIME, sec);
	if (ret)
		dev_err(rtc->dev, "set rtc time failed !!\n");

	return ret;
}

static int sgc_rtc_alarm_irq_enable(struct device *dev, unsigned int alarm_en)
{
	struct sgc_rtc *rtc = dev_get_drvdata(dev);
	unsigned int sec;
	int ret;

	if (alarm_en) {
		rtc->alarm_en = 1;
		sec = rtc->alarm_sec;
	} else {
		rtc->alarm_en = 0;

		/* get alarm data */
		ret = sgc_pmu_shift_reg_read(rtc->sgc_info, SGC_ALARM, &sec);
		if (ret)
			goto failed;

		rtc->alarm_sec = sec;

		/* alarm reset */
		sgc_rtc_set_alarm_reset(rtc);

		/* get rtc timer */
		ret = sgc_pmu_shift_reg_read(rtc->sgc_info, SGC_TIME, &sec);
		if (ret)
			goto failed;

		sec -= 2;
	}

	ret = sgc_pmu_shift_reg_write(rtc->sgc_info, SGC_ALARM, sec);
	if (ret)
		goto failed;

	return ret;
failed:
	dev_err(rtc->dev, "set rtc alarm irq failed !!\n");
	return ret;
}

static int sgc_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct sgc_rtc *rtc = dev_get_drvdata(dev);
	unsigned int sec;
	int ret;

	if (rtc->alarm_en) {
		ret = sgc_pmu_shift_reg_read(rtc->sgc_info, SGC_ALARM, &sec);
		if (ret)
			goto failed;
	} else
		sec = rtc->alarm_sec;

	rtc_time64_to_tm(sec, &alarm->time);

	dev_dbg(dev, "%s to %u. %d/%d/%d %d:%02u:%02u\n", __func__,
		sec,
		alarm->time.tm_mon+1,
		alarm->time.tm_mday,
		alarm->time.tm_year+1900,
		alarm->time.tm_hour,
		alarm->time.tm_min,
		alarm->time.tm_sec
	);

	alarm->enabled = rtc->alarm_en;

	return ret;
failed:
	dev_err(rtc->dev, "read rtc alarm failed !!\n");
	return ret;
}

static int sgc_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
	struct sgc_rtc *rtc = dev_get_drvdata(dev);
	unsigned long sec;
	int ret;

	sec = rtc_tm_to_time64(&alarm->time);

	dev_dbg(dev, "%s to %lu. %d/%d/%d %d:%02u:%02u\n", __func__,
		 sec,
		 alarm->time.tm_mon+1,
		 alarm->time.tm_mday,
		 alarm->time.tm_year+1900,
		 alarm->time.tm_hour,
		 alarm->time.tm_min,
		 alarm->time.tm_sec
	);

	if (rtc->alarm_en) {
		ret = sgc_pmu_shift_reg_write(rtc->sgc_info, SGC_ALARM, sec);
		if (ret)
			goto failed;
	} else
		rtc->alarm_sec = sec;

	ret = sgc_rtc_alarm_irq_enable(dev, alarm->enabled);
	if (ret)
		goto failed;

	return ret;
failed:
	dev_err(rtc->dev, "set rtc alarm failed !!\n");
	return ret;
}

static const struct rtc_class_ops sgc_rtc_ops = {
	.read_time = sgc_rtc_read_time,
	.set_time = sgc_rtc_set_time,
	.read_alarm = sgc_rtc_read_alarm,
	.set_alarm = sgc_rtc_set_alarm,
	.alarm_irq_enable = sgc_rtc_alarm_irq_enable,
};

static int sgc_rtc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sgc_data *sgc = dev_get_drvdata(dev->parent);
	struct sgc_rtc *rtc_info;
	struct regmap *regmap;
	u32 val;
	int ret;

	rtc_info = devm_kzalloc(dev, sizeof(*rtc_info), GFP_KERNEL);
	if (!rtc_info)
		return -ENOMEM;

	regmap = dev_get_regmap(dev->parent, NULL);
	if (!regmap) {
		dev_err(dev, "Failed to get sgc regmap\n");
		return -ENODEV;
	}

	rtc_info->dev = dev;
	rtc_info->rmap = regmap;
	rtc_info->sgc_info = sgc;
	platform_set_drvdata(pdev, rtc_info);

	/* check OSC ready status */
	regmap_read(regmap, PMU_GEN_STAT, &val);
	if ((val & OSC_READY_STAT) == 0x0) {
		dev_err(dev, "osc status not ready error !!\n");
		return -1;
	}
	dev_info(dev, "osc status ready\n");

	rtc_info->rtc_dev = devm_rtc_allocate_device(dev);
	if (IS_ERR(rtc_info->rtc_dev))
		return PTR_ERR(rtc_info->rtc_dev);

	if (device_property_read_bool(dev, "osc-ppm"))
		device_property_read_u32(dev, "osc-ppm", &rtc_info->osc_ppm);

	if (device_property_read_bool(&pdev->dev, "osc-ppm-negative"))
		rtc_info->osc_ppm = 0 - rtc_info->osc_ppm;

	if (device_property_read_bool(dev, "alarm")) {
		rtc_info->alarm = of_get_named_gpio(dev->of_node, "alarm", 0);
		ret = gpio_request(rtc_info->alarm, "sgc_rtc_alarm");
		if (ret) {
			dev_err(dev, "request alarm gpio fail\n");
			return -1;
		}

		ret = gpio_direction_input(rtc_info->alarm);
		if (ret) {
			dev_err(dev, "set alarm gpio direction fail\n");
			return -1;
		}

		rtc_info->alarm_irq = gpio_to_irq(rtc_info->alarm);
		ret = devm_request_irq(dev, rtc_info->alarm_irq,
					rtc_alarm_interrupt,
					IRQF_TRIGGER_FALLING,
					"sgc_rtc_alarm_isr", rtc_info);
		if (ret < 0) {
			dev_err(dev, "Problem requesting IRQ, error %i\n", ret);
			return -1;
		}
	}

	/* set config ck 1Hz */
	sgc_rtc_set_time_reg_clk_mode(rtc_info, RTC_TIME_CLK_1HZ);

	/* set alarm output open drain */
	sgc_rtc_set_alarm_output_mode(rtc_info, RTC_OP_EN);

	sgc_rtc_set_alarm_reset(rtc_info);

	device_init_wakeup(dev, 1);

	rtc_info->rtc_dev->ops = &sgc_rtc_ops;
	return devm_rtc_register_device(rtc_info->rtc_dev);
}

static const struct of_device_id sgc_rtc_of_match[] = {
	{ .compatible = "vatics,sgc-rtc"},
	{ }
};
MODULE_DEVICE_TABLE(of, sgc_rtc_of_match);

static struct platform_driver sgc_rtc_driver = {
	.driver = {
		.name = "sgc-rtc",
		.of_match_table = sgc_rtc_of_match,
	},
	.probe = sgc_rtc_probe,
};
module_platform_driver(sgc_rtc_driver);

MODULE_DESCRIPTION("RTC Driver for SGC 22300");
MODULE_LICENSE("GPL");

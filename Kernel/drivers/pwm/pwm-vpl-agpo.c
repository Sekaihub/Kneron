// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2024 Kneron Inc.
 *
 * PWM driver for Kneron SoCs
 */

#include <linux/module.h>
#include <linux/of.h>
#include <linux/pwm.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/vpl_agpo.h>

struct agpo_dev {
	struct agpo_desc *desc;
	struct agpo_pattern_cfg cfg;
};

struct vpl_agpo_pwm {
	struct pwm_chip chip;
};

static inline struct vpl_agpo_pwm *to_agpo_pwm(struct pwm_chip *chip)
{
	return container_of(chip, struct vpl_agpo_pwm, chip);
};

static int vpl_agpo_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
	unsigned int hw_agpo = pwm->hwpwm;
	struct agpo_dev *agpo_data;
	struct agpo_desc *desc;
	int ret;

	agpo_data = devm_kzalloc(chip->dev, sizeof(*agpo_data), GFP_KERNEL);
	if (!agpo_data)
		return -ENOMEM;

	desc = agpo_request(hw_agpo, "pwm");
	if (IS_ERR(desc)) {
		ret = PTR_ERR(desc);
		dev_err(chip->dev, "failed to request agpo %d with ret: %d\n",
			hw_agpo, ret);
		return ret;
	}

	/* set port crontrol type to normal 128bit pattern */
	agpo_set_type(desc, AGPO_PORT_TYPE_OPEN_SOURCE, 0);

	agpo_data->desc = desc;

	return pwm_set_chip_data(pwm, agpo_data);
}

static void vpl_agpo_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct agpo_dev *agpo_data = pwm_get_chip_data(pwm);

	agpo_free(agpo_data->desc);
	pwm_set_chip_data(pwm, NULL);
	devm_kfree(chip->dev, agpo_data);
}

#define NORM_PERIOD_BITS 100
static int vpl_agpo_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
				int duty_ns, int period_ns)
{
	struct agpo_dev *agpo_data = pwm_get_chip_data(pwm);
	struct agpo_pattern_cfg *cfg = &agpo_data->cfg;
	int i;
	unsigned long clk_freq = agpo_get_clk_rate(agpo_data->desc);
	u64 duty_bits;
	int period_bits = NORM_PERIOD_BITS;
	u64 agpo_period;

	if (period_ns > NSEC_PER_SEC)
		return -ERANGE;

	/* normalize duty_ns / period_ns to */
	/* (duty bits / NORME_PERIOD_BITS) */
	duty_bits = (u64)duty_ns * NORM_PERIOD_BITS;
	duty_bits = DIV_ROUND_CLOSEST_ULL(duty_bits, period_ns);

	agpo_period = div64_u64((u64)period_ns * clk_freq,
				(u64)NORM_PERIOD_BITS * NSEC_PER_SEC);

	dev_dbg(chip->dev, "duty bits: %lld", duty_bits);
	dev_dbg(chip->dev, "period bits %d\n", period_bits);
	dev_dbg(chip->dev, "agpo pulse ticks %llu\n", agpo_period);

	for (i = 0; i < 4; i++) {
		if (duty_bits / 32) {
			cfg->pattern[i] = 0xFFFFFFFF;
			duty_bits -= 32;
		} else if (duty_bits % 32) {
			cfg->pattern[i] = BITMAP_LAST_WORD_MASK(duty_bits);
			duty_bits = 0;
		} else {
			cfg->pattern[i] = 0x0;
		}
	}

	cfg->period = agpo_period;
	cfg->bits_length = period_bits;
	cfg->repeat = AGPO_REPEAT_INFINITE;
	cfg->interval = period_bits;

	for (i = 0; i < 4; i++)
		dev_dbg(chip->dev, "%08x\n", cfg->pattern[i]);


	dev_dbg(chip->dev, "%08x\n", cfg->period);
	dev_dbg(chip->dev, "%08x\n", cfg->bits_length);
	dev_dbg(chip->dev, "%08x\n", cfg->repeat);
	dev_dbg(chip->dev, "%08x\n", cfg->interval);

	return agpo_config(agpo_data->desc, cfg);
}

static int vpl_agpo_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct agpo_dev *agpo_data = pwm_get_chip_data(pwm);

	return agpo_enable(agpo_data->desc);
}

static void vpl_agpo_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct agpo_dev *agpo_data = pwm_get_chip_data(pwm);

	return agpo_disable(agpo_data->desc);
}

static int vpl_agpo_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
			 const struct pwm_state *state)
{
	int err;

	if (state->polarity != PWM_POLARITY_NORMAL)
		return -EINVAL;

	if (!state->enabled) {
		if (pwm->state.enabled)
			vpl_agpo_pwm_disable(chip, pwm);

		return 0;
	}

	err = vpl_agpo_pwm_config(pwm->chip, pwm, state->duty_cycle,
				  state->period);
	if (err)
		return err;

	if (!pwm->state.enabled)
		err = vpl_agpo_pwm_enable(chip, pwm);

	return err;
}


static const struct pwm_ops vpl_agpo_pwm_ops = {
	.request = vpl_agpo_pwm_request,
	.free = vpl_agpo_pwm_free,
	.apply = vpl_agpo_pwm_apply,
	.owner = THIS_MODULE,
};

static int vpl_agpo_pwm_probe(struct platform_device *pdev)
{
	struct vpl_agpo_pwm *agpo_pwm;
	int ret;

	agpo_pwm = devm_kzalloc(&pdev->dev, sizeof(*agpo_pwm), GFP_KERNEL);
	if (!agpo_pwm)
		return -ENOMEM;

	platform_set_drvdata(pdev, agpo_pwm);

	agpo_pwm->chip.dev = &pdev->dev;
	agpo_pwm->chip.ops = &vpl_agpo_pwm_ops;
	agpo_pwm->chip.base = -1;
	agpo_pwm->chip.npwm = NR_AGPOS;
	//agpo_pwm->chip.of_xlate = of_pwm_xlate_with_flags;
	//agpo_pwm->chip.of_pwm_n_cells = 3;
	/* agpo_pwm->chip.can_sleep = 1; */

	ret = pwmchip_add(&agpo_pwm->chip);
	if (ret < 0) {
		dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
		return ret;
	}

	return 0;
}

static int vpl_agpo_pwm_remove(struct platform_device *pdev)
{
	struct vpl_agpo_pwm *agpo_pwm = platform_get_drvdata(pdev);

	pwmchip_remove(&agpo_pwm->chip);
	return 0;
}

static const struct of_device_id vpl_agpo_pwm_of_match[] = {
	{ .compatible = "vatics,vpl-agpo-pwm"},
	{}
};

static struct platform_driver vpl_agpo_pwm_driver = {
	.driver = {
		.name = "vpl-agpo-pwm",
		.of_match_table = vpl_agpo_pwm_of_match,
	},
	.probe = vpl_agpo_pwm_probe,
	.remove = vpl_agpo_pwm_remove,
};

module_platform_driver(vpl_agpo_pwm_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kneron Inc.");
MODULE_ALIAS("platform:vpl-agpo-pwm");

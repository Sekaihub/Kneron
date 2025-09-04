// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2024 Kneron Inc.
 *
 * Author: ChangHsien Ho <vincent.ho@vatics.com>
 *
 *  agpo_consumer.c - Sample AGPO consumer driver
 */

#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/err.h>
#include <linux/vpl_agpo.h>

/*
 * This sample driver will show how to configur a AGPO port with
 * cfg1 pattern, repeat 5 times.
 * Interrupt will be trigger after finish cfg1, then config to cfg2 pattern
 * repeat 20 times.
 */

static struct agpo_desc *agpo;
static int virq;
static int port_num;

static struct agpo_pattern_cfg cfg1 = {
	.pattern = {0x000000AA, 0x0, 0x0, 0x0},
	.period = 20000000,
	.bits_length = 8,
	.repeat = 5,
	.interval = 12,
};

static struct agpo_pattern_cfg cfg2 = {
	.pattern = {0x0000000F, 0x0, 0x0, 0x0},
	.period = 2000000,
	.bits_length = 5,
	.repeat = 20,
	.interval = 5,
};

static irqreturn_t agpo_isr(int irq, void *data)
{
	/* coinfgur to cfg2 */
	agpo_config(agpo, &cfg2);
	/* kick enable */
	agpo_enable(agpo);
	return IRQ_HANDLED;
}

int __init agpo_consumer_module_init(void)
{
	int ret;

	/* reques port_num agpo */
	agpo = agpo_request(port_num, NULL);
	if (IS_ERR(agpo)) {
		pr_info("request fail %ld\n", PTR_ERR(agpo));
		return -ENODEV;
	}

	/* set to open source type */
	ret = agpo_set_type(agpo, AGPO_PORT_TYPE_OPEN_SOURCE, 0);
	if (ret)
		pr_info("set type fail %d\n", ret);

	/* configure to cfg1 */
	ret = agpo_config(agpo, &cfg1);
	if (ret)
		pr_info("config fail %d\n", ret);

	/* get virq number and register a ISR */
	virq = agpo_to_irq(agpo);
	ret = request_irq(virq, agpo_isr, 0, "agpo-test", NULL);

	/* enable agpo */
	ret = agpo_enable(agpo);
	if (ret)
		pr_info("enable fail %d\n", ret);

	return 0;
}

void __exit agpo_consumer_module_exit(void)
{
	free_irq(virq, NULL);
	agpo_disable(agpo);
	agpo_free(agpo);
}

module_init(agpo_consumer_module_init);
module_exit(agpo_consumer_module_exit);

MODULE_LICENSE("GPL");

/* SPDX-License-Identifier: GPL-2.0 */
/*
 *
 * Copyright (C) 2013-2018  VATICS Inc.
 *
 * Author: ChangHsien Ho <vincent.ho@vatics.com>
 */

#ifndef __VPL_AGPO_H
#define __VPL_AGPO_H

#define NR_AGPOS 12

enum agpo_port_type {
	AGPO_PORT_TYPE_OPEN_SOURCE,
	AGPO_PORT_TYPE_OPEN_DRAIN,
};

/*
 * struct agpo_pattern_data
 * @pattern_0:	 The data pattern bit 31 to 0
 * @pattern_1:	 The data pattern bit 63 to 32
 * @pattern_2:	 The data pattern bit 95 to 64
 * @pattern_3:	 The data pattern bit 127 to 96
 * @period:	 APB cycle unit for each bit period.
 * @data_length: Available pattern bits in 128-bit pattern register.
 * @repeat:	 Repeat times for the same data pattern.
 *               value: 1~254.
 *               255: infinite repeat mode.
 * @interval:    The interval between the start of two successive and
 *               complete data pattern in @period cycle unit.
 * @update:      Use update mode. The update mode is available when Port is
 *               enabled. The update pattern will be applied after a complete
 *               data pattern send out. Note that, when the port is disabled,
 *               if the port is disabled.
 **/

struct agpo_pattern_cfg {
	u32	pattern[4];
	u32	period;
	u32	bits_length;
	u32	repeat;
	u32	interval;
};

#define AGPO_MAX_BITS_LENGTH		128
#define AGPO_MAX_REPEAT_TIMES		4094
#define AGPO_REPEAT_INFINITE		4096

/* Opaque descriptor for a AGPO */
struct agpo_desc;

#define AGPOC_VERSION			0x00
#define AGPOC_CTRL			0x04
#define AGPOC_STATUS			0x08
#define AGPOC_INTR_MASK			0x0C
#define AGPOC_DEFAULT_DATA_OE_N		0x10
#define AGPOC_DEFAULT_DATA		0x14
#define AGPOC_PORT_CTRL_TYPE		0x18
#define AGPOC_PATTERN_0(chan)		(0x1C + chan*0x1C)
#define AGPOC_PATTERN_1(chan)		(0x20 + chan*0x1C)
#define AGPOC_PATTERN_2(chan)		(0x24 + chan*0x1C)
#define AGPOC_PATTERN_3(chan)		(0x28 + chan*0x1C)
#define AGPOC_PERIOD(chan)		(0x2C + chan*0x1C)
#define AGPOC_LENGTH(chan)		(0x30 + chan*0x1C)
#define AGPOC_INTERVAL_REPEAT(chan)	(0x34 + chan*0x1C)
#define AGPOC_UPDATE			0x39C
#define AGPOC_TRIG_ENABLE		0x3A0
#define AGPOC_TRIG_POLARITY		0x3A4
#define AGPOC_UPDATE_PATTERN_0		0x3A8
#define AGPOC_UPDATE_PATTERN_1		0x3AC
#define AGPOC_UPDATE_PATTERN_2		0x3B0
#define AGPOC_UPDATE_PATTERN_3		0x3B4
#define AGPOC_UPDATE_PERIOD		0x3B8
#define AGPOC_UPDATE_LENGTH		0x3BC
#define AGPOC_UPDATE_INTERVAL_REPEAT	0x3C0
#define AGPOC_UPDATE_READ_CTRL		0x3C4

#define AGPOC_REPEAT_STOP_NOW		0xFFE
#define AGPOC_REPEAT_INFINIT		0xFFF
#define AGPOC_REPEAT_MASK		0xFFF
#define AGPOC_REPEAT_SHIFT		20
#define AGPOC_INTERVAL_MASK		0xFFFFF

struct agpo_desc *agpo_request(int agpo, const char *label);
void agpo_free(struct agpo_desc *desc);

int agpo_set_type(struct agpo_desc *desc, enum agpo_port_type, unsigned int def_val);
int agpo_config(struct agpo_desc *desc, struct agpo_pattern_cfg *cfg);

int agpo_enable(struct agpo_desc *desc);
void agpo_disable(struct agpo_desc *desc);

unsigned long agpo_get_clk_rate(struct agpo_desc *desc);
int agpo_to_irq(struct agpo_desc *desc);

#endif /* __VPL_AGPO_H */

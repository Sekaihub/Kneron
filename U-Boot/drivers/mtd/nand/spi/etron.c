// SPDX-License-Identifier: GPL-2.0+
/*
 * Configuration for Leipzig board
 *
 * Copyright (C) 2021 VATICS Inc.
 */

#ifndef __UBOOT__
#include <linux/device.h>
#include <linux/kernel.h>
#endif
#include <linux/mtd/spinand.h>

#define SPINAND_MFR_ETRON		0xd5

static SPINAND_OP_VARIANTS(read_cache_variants,
			   SPINAND_PAGE_READ_FROM_CACHE_X4_OP(0, 1, NULL, 0),
			   SPINAND_PAGE_READ_FROM_CACHE_X2_OP(0, 1, NULL, 0),
			   SPINAND_PAGE_READ_FROM_CACHE_OP(true, 0, 1, NULL, 0),
			   SPINAND_PAGE_READ_FROM_CACHE_OP(false, 0, 1, NULL, 0));

static SPINAND_OP_VARIANTS(write_cache_variants,
			   SPINAND_PROG_LOAD_X4(true, 0, NULL, 0),
			   SPINAND_PROG_LOAD(true, 0, NULL, 0));

static SPINAND_OP_VARIANTS(update_cache_variants,
			   SPINAND_PROG_LOAD_X4(false, 0, NULL, 0),
			   SPINAND_PROG_LOAD(false, 0, NULL, 0));

static int etron_ooblayout_ecc(struct mtd_info *mtd, int section,
				      struct mtd_oob_region *region)
{
	return -ERANGE;
}

static int etron_ooblayout_free(struct mtd_info *mtd, int section,
				       struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	region->offset = 2;
	region->length = mtd->oobsize - 2;

	return 0;
}

static const struct mtd_ooblayout_ops etron_ooblayout = {
	.ecc = etron_ooblayout_ecc,
	.rfree = etron_ooblayout_free,
};

static int etron_ecc_get_status(struct spinand_device *spinand, u8 status)
{
	switch (status & STATUS_ECC_MASK) {
	case STATUS_ECC_NO_BITFLIPS:
		return 0;

	case STATUS_ECC_HAS_BITFLIPS:
		/* Between 1-7 bitflips were corrected */
		return 7;

	case STATUS_ECC_MASK:
		/* Maximum bitflips were corrected */
		return 8;

	case STATUS_ECC_UNCOR_ERROR:
		return -EBADMSG;
	}

	return -EINVAL;
}

static const struct spinand_info etron_spinand_table[] = {
	SPINAND_INFO("EM73F044VCA",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x2D),
		     NAND_MEMORG(1, 4096, 256, 64, 4096, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&etron_ooblayout,
				     etron_ecc_get_status)),
	SPINAND_INFO("EM73F044VCA",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x2B),
		     NAND_MEMORG(1, 4096, 256, 64, 4096, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&etron_ooblayout,
				     etron_ecc_get_status)),
	SPINAND_INFO("EM73C044VCF",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0x25),
		     NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(4, 512),
		     SPINAND_INFO_OP_VARIANTS(&read_cache_variants,
					      &write_cache_variants,
					      &update_cache_variants),
		     SPINAND_HAS_QE_BIT,
		     SPINAND_ECCINFO(&etron_ooblayout,
				     etron_ecc_get_status)),
};

static const struct spinand_manufacturer_ops etron_spinand_manuf_ops = {
};

const struct spinand_manufacturer etron_spinand_manufacturer = {
	.id = SPINAND_MFR_ETRON,
	.name = "ETRON",
	.chips = etron_spinand_table,
	.nchips = ARRAY_SIZE(etron_spinand_table),
	.ops = &etron_spinand_manuf_ops,
};

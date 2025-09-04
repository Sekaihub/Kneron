#include <platform_def.h>
#include <drivers/spi_nor.h>
#include <drivers/spi_nand.h>
#include <common/debug.h>
#include "wagner_private.h"
#include "safezone.h"

#define FLASH_BL31_ADDR		0x60000
#define FLASH_BL31_SIZE		0x20000
//#define FLASH_BL32_ADDR		0x80000
//#define FLASH_BL32_SIZE		0x40000
#define FLASH_BL33_ADDR		0x80000
#define FLASH_BL33_SIZE		0xc0000

extern bl_header_info_t bl_header_info;
extern uint32_t spi_attr;

enum header_page_size {
	PAGESIZE_2K = 0,
	PAGESIZE_4K,
	PAGESIZE_8K,
	PAGESIZE_16K,
};

enum header_plane_select {
	PLANESELECT_DISABLE = 0,
	PLANESELECT_ENABLE,
};

#define SPIHEADER_SCREN       BIT(31)
#define SPIHEADER_RXDEN       BIT(30)
#define SPIHEADER_PLSEN       BIT(29)
#define SPIHEADER_PASEN       BIT(28)

#define BOOT_HEADER_SIZE      sizeof(SBIF_Header_t) //Pure header without cert

int bl1_plat_handle_bootheader(unsigned int header, bool isNand)
{
	uint32_t value = 0;

	if (isNand) {
		struct spinand_device *spi_nand = get_spinand_device();

		if (header & SPIHEADER_PASEN) {
			value = (header & 0x3);
			switch (value) {
			case PAGESIZE_2K:
			spi_nand->nand_dev->page_size = SZ_2K;
			spi_nand->nand_dev->block_size = SZ_2K * SZ_64;
			break;

			case PAGESIZE_4K:
			spi_nand->nand_dev->page_size = SZ_4K;
			spi_nand->nand_dev->block_size = SZ_4K * SZ_64;
			break;

			case PAGESIZE_8K:
			spi_nand->nand_dev->page_size = SZ_8K;
			spi_nand->nand_dev->block_size = SZ_8K * SZ_64;
			break;

			case PAGESIZE_16K:
			spi_nand->nand_dev->page_size = SZ_16K;
			spi_nand->nand_dev->block_size = SZ_16K * SZ_64;
			break;
			}
		}

		if (header & SPIHEADER_PLSEN) {
			value = (header & 0x4) >> 2;
			switch (value) {
			case PLANESELECT_DISABLE:
			spi_nand->nand_dev->nb_planes = 1;
			break;

			case PLANESELECT_ENABLE:
			spi_nand->nand_dev->nb_planes = 2;
			break;
			}
		}
	}

	if (header & SPIHEADER_RXDEN) {
		value = (header & 0xF0) >> 4;
		dw_qspi_set_rxdelay(value);
	}

	if (header & SPIHEADER_SCREN) {
		value = (header & 0xFFFF00) >> 8;
		dw_qspi_set_sckdv(value);
	}
	return 0;
}

int bl1_plat_spi_nor_read(unsigned int image_id, image_info_t *image_data,
			  int bus_id, unsigned int buswidth)
{
	unsigned int image_addr = 0x0;
	size_t len;
	size_t len_tmp = 0;
	int ret = -1;

	unsigned long long size;
	unsigned int erase_size;
	size_t len_cb = 0;
	uintptr_t addr;

	ret = dw_qspi_init(bus_id, buswidth);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_init(&size, &erase_size, buswidth);
	if (ret != 0) {
		return ret;
	}

	/* read boot header */
	spi_nor_read(0, image_data->image_base, BOOT_HEADER_SIZE, &len_cb);

	eip130_headerInfo((SBIF_Header_t *)image_data->image_base);

	ret = bl1_plat_handle_bootheader(bl_header_info.spi_attr, 0);

	if (!bl_header_info.total_size)
		len = BL2_PACKSIZE_DEFAULT;
	else
		len = MIN(image_data->image_max_size,
			bl_header_info.total_size);

	/* read boot image */
	image_data->image_base -= bl_header_info.bl_offset;
	addr = image_data->image_base;
	while (len > 0) {
		len_tmp = MIN(len, (size_t)SZ_4K);
		ret = spi_nor_read(image_addr, addr, len_tmp, &len_cb);
		image_addr += len_tmp;
		addr += len_tmp;
		len -= len_tmp;
	}
	dw_qspi_dma_release();
	return 0;
}

int bl2_plat_spi_nor_read(unsigned int image_id, image_info_t *image_data,
			  int bus_id, unsigned int buswidth)
{
	unsigned int image_addr = 0x0;
	size_t len;
	size_t len_tmp = 0;
	int ret = -1;

	unsigned long long size;
	unsigned int erase_size;
	size_t len_cb = 0;
	uintptr_t addr;

	ret = dw_qspi_init(bus_id, buswidth);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nor_init(&size, &erase_size, buswidth);
	if (ret != 0) {
		return ret;
	}

	ret = bl1_plat_handle_bootheader(spi_attr, 0);

	len = 0x40000;
	/* read boot image */
	addr = image_data->image_base;
	if (image_id == BL31_IMAGE_ID) {
		len = FLASH_BL31_SIZE;
		image_addr = FLASH_BL31_ADDR;
	} else if (image_id == BL33_IMAGE_ID) {
		if (bl_header_info.spi_bl33_size == UNKNOWN_SIZE)
			len = FLASH_BL33_SIZE;
		else
			len = bl_header_info.spi_bl33_size;
		if (bl_header_info.spi_bl33_addr == UNKNOWN_ADDR)
			image_addr = FLASH_BL33_ADDR;
		else
			image_addr = bl_header_info.spi_bl33_addr;
	}

	if (len > image_data->image_max_size) {
		ERROR("Length(0x%lx) exceed the limit(0x%x)!", len,
				image_data->image_max_size);
		len = image_data->image_max_size;
	}

	while (len > 0) {
		len_tmp = MIN(len, (size_t)SZ_4K);
		ret = spi_nor_read(image_addr, addr, len_tmp, &len_cb);
		image_addr += len_tmp;
		addr += len_tmp;
		len -= len_tmp;
	}
	dw_qspi_dma_release();
	return 0;
}
int bl1_plat_spi_nand_read(unsigned int image_id, image_info_t *image_data,
			   int bus_id, unsigned int buswidth)
{
	struct spinand_device *spi_nand;
	int ret = -1;

	unsigned long long size;
	unsigned int erase_size;

	unsigned int page_nb = 0;
	uintptr_t addr = 0;
	size_t len;
	size_t len_tmp = 0;

	ret = dw_qspi_init(bus_id, buswidth);
	if (ret != 0) {
		return ret;
	}

	ret = spi_nand_init(&size, &erase_size, buswidth);
	if (ret != 0) {
		return ret;
	}

	spi_nand = get_spinand_device();

	/* read boot header */
	spi_nand->nand_dev->mtd_read(NULL, page_nb, 0,
		image_data->image_base, BOOT_HEADER_SIZE);

	eip130_headerInfo((SBIF_Header_t *)image_data->image_base);

	ret = bl1_plat_handle_bootheader(bl_header_info.spi_attr, 1);

	if (!bl_header_info.total_size)
		len = BL2_PACKSIZE_DEFAULT;
	else
		len = MIN(image_data->image_max_size,
			bl_header_info.total_size);

	image_data->image_base -= bl_header_info.bl_offset;
	addr = image_data->image_base;

	/* read boot image */
	while(len > 0) {
		len_tmp = MIN(len, (size_t)spi_nand->nand_dev->page_size);
		spi_nand->nand_dev->mtd_read(NULL,
				page_nb, 0, addr, len_tmp);
		page_nb++;
		addr += len_tmp;
		len -= len_tmp;
	}

	dw_qspi_dma_release();

	return 0;
}

int bl2_plat_spi_nand_read(unsigned int image_id, image_info_t *image_data,
			   int bus_id, unsigned int buswidth)
{
	struct spinand_device *spi_nand;
	int ret = -1;

	unsigned long long size;
	unsigned int erase_size;

	unsigned int image_addr = 0x0;
	unsigned int page_nb = 0;
	unsigned int page_count = 1;
	uintptr_t addr = image_data->image_base;
	size_t len;
	size_t len_tmp = 0;

	ret = dw_qspi_init(bus_id, buswidth);
	if (ret != 0) {
		return ret;
	}

	spi_nand = get_spinand_device();
	spi_nand->cont_en = (spi_attr & 0x8) >> 3;

	ret = spi_nand_init(&size, &erase_size, buswidth);
	if (ret != 0) {
		return ret;
	}

	ret = bl1_plat_handle_bootheader(spi_attr, 1);

	len = 0x40000;

	/* read boot image */
	if (image_id == BL31_IMAGE_ID) {
		len = FLASH_BL31_SIZE;
		image_addr = FLASH_BL31_ADDR;
	} else if (image_id == BL33_IMAGE_ID) {
		if (bl_header_info.spi_bl33_size == UNKNOWN_SIZE)
			len = FLASH_BL33_SIZE;
		else
			len = bl_header_info.spi_bl33_size;
		if (bl_header_info.spi_bl33_addr == UNKNOWN_ADDR)
			image_addr = FLASH_BL33_ADDR;
		else
			image_addr = bl_header_info.spi_bl33_addr;
	}
	page_nb = image_addr / spi_nand->nand_dev->page_size;

	/* check if running continuous read mode */
	if (spi_nand->nand_dev->cont_info) {

		/* if frame width is 32 bits, max transfer size is 0x40000 */
		/* if frame width is 8 bits, max transfer size is 0x10000  */
		if (buswidth > 1)
			page_count = 64;
		else if (spi_nand->nand_dev->page_size == SZ_2K)
			page_count = 32;
		else if (spi_nand->nand_dev->page_size == SZ_4K)
			page_count = 16;
	}

	if (len > image_data->image_max_size) {
		ERROR("Length(0x%lx) exceed the limit(0x%x)!", len,
				image_data->image_max_size);
		len = image_data->image_max_size;
	}

	/* read boot image */
	while (len > 0) {
		len_tmp = MIN(len,
			(size_t)spi_nand->nand_dev->page_size * page_count);
		spi_nand->nand_dev->mtd_read(spi_nand->nand_dev,
				page_nb, 0, addr, len_tmp);
		page_nb += page_count;
		addr += len_tmp;
		len -= len_tmp;
	}

	dw_qspi_dma_release();

	return 0;
}


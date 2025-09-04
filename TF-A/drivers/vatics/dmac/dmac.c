#include "dmac.h"
#include "stdint.h"
#include <string.h>
#include <stdio.h>
#include "../ddr/lpddr4.h"
#include <common/debug.h>

#define VPL_SYSC_MMR_BASE 0xCEF00000
#define VPL_DDR32PHY_PUB_BASE 0xCC000000
#define VPL_DMAC_MMR_BASE 0xC7000000

#define DMAC_DESCRIPTOR_BASE 0xC0037F40 //BRC + 32k - 3 * 0x40
#define PHY_TRAIN_FW_BASE    0xC0020000
#define PHY_FW_PORT_BASE     (VPL_DDR32PHY_PUB_BASE + 0xA0000)

#define FW_CHECK
static void clear_low_power_interface(void)
{
	writel(0xFFFFFFFF, VPL_SYSC_MMR_BASE + 0x1DC);
}

void dmac_copy(unsigned int dst, unsigned int src, unsigned int len)
{
	uint32_t val;

	clear_low_power_interface();

	/*********config descriptor**********/
	//ctrl
	// dest: 7-6, src: 5-4 , start: 6
	// AHB0 : 00
	// AHB1 : 01
	// AHB2 : 10
	writel(0x0C000050, DMAC_DESCRIPTOR_BASE);
	//source addr
	writel(src, DMAC_DESCRIPTOR_BASE + 0x4);
	//dest addr
	writel(dst, DMAC_DESCRIPTOR_BASE + 0x10);
	//trans size(byte)
	writel(len, DMAC_DESCRIPTOR_BASE + 0x1C);
	//next
	writel(0x0, DMAC_DESCRIPTOR_BASE + 0x44);

	/********config DMAC controller****************/
	writel(0x10000, VPL_DMAC_MMR_BASE + 0x8);
	writel(0x80, VPL_DMAC_MMR_BASE + 0x48);
	writel(DMAC_DESCRIPTOR_BASE , VPL_DMAC_MMR_BASE + 0x58);
	/*start dma*/
	writel(0x10006, VPL_DMAC_MMR_BASE + 0x8);

	val = readl(VPL_DMAC_MMR_BASE + 8);
	while (!(val & 0x1))
		val = readl(VPL_DMAC_MMR_BASE + 8);
}
#ifdef FW_CHECK
void fwcheck(void){
	int i = 0;

	for (i = 0; i < 0x8800; i += 2) {
		if (readw(PHY_FW_PORT_BASE + i) != readw(PHY_TRAIN_FW_BASE + i)) {
			ERROR("fw unmatch at 0x%08x\n", PHY_FW_PORT_BASE + i);
			return;
		}
	}
	INFO("fw pass.!!\n");
	return;
}
#endif
void dmac_copy_ddrphy_fw(void)
{
	dmac_copy(PHY_FW_PORT_BASE, PHY_TRAIN_FW_BASE, 0x8800);
	#ifdef FW_CHECK
	fwcheck();
	#endif
}

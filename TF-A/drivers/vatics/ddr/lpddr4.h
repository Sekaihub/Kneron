#ifndef __LPDDR4__
#define __LPDDR4__

#include <stdlib.h>
#define XSTR(x) STR(x)
#define STR(x) #x

#include "timing.h"

#define __arch_getb(a)			(*(volatile unsigned char *)(long)(a))
#define __arch_getw(a)			(*(volatile unsigned short *)(long)(a))
#define __arch_getl(a)			(*(volatile unsigned int *)(long)(a))
#define __arch_getq(a)                  (*(volatile unsigned long *)(long)(a))

#define __arch_putb(v, a)		(*(volatile unsigned char *)(long)(a) = (v))
#define __arch_putw(v, a)		(*(volatile unsigned short *)(long)(a) = (v))
#define __arch_putl(v, a)		(*(volatile unsigned int *)(long)(a) = (v))
#define __arch_putq(v, a)                (*(volatile unsigned long *)(long)(a) = (v))

#define __raw_writeb(v, a)		__arch_putb(v, a)
#define __raw_writew(v, a)		__arch_putw(v, a)
#define __raw_writel(v, a)		__arch_putl(v, a)
#define __raw_writeq(v, a)               __arch_putq(v, a)

#define writeb(v, a)			__raw_writeb(v, a)
#define writew(v, a)			__raw_writew(v, a)
#define writel(v, a)			__raw_writel(v, a)
#define writeq(v, a)			__raw_writeq(v, a)

#define __raw_readb(a)			__arch_getb(a)
#define __raw_readw(a)			__arch_getw(a)
#define __raw_readl(a)			__arch_getl(a)
#define __raw_readq(a)                  __arch_getq(a)

#define readb(a)			__raw_readb(a)
#define readw(a)			__raw_readw(a)
#define readl(a)			__raw_readl(a)
#define readq(a)			__raw_readq(a)

#define mrl(addr, v)	 v = readl(addr)
#define mwl(addr, v)		writel(v, addr)

#define mrw(addr, v)	 v = readw(addr)
#define mww(addr, v)		writew(v, addr)

#define DDR3_TOP_CTRL_BASE 0xCB000000
#define APM_BASE 0xCB900000
#define PHY_BASE 0xCC000000
#define DDRNSDMC_PUB_MMR_BASE PHY_BASE
#define SYSC_SECURE_MMR_BASE 0xCEF00000
//&SYSC_NONSECURE_MMR_BASE = 0xCEE00000
#define VPL_RET_RAM_BASE              0xc0038000

#define WAGNER_SYSC_VERSION 0x05000000

#define DDRC_RSTN_CTRL 0x8
#define DDRC_CLK_CTRL 0x9
#define DDRC_MRL_SEL 0xc

#define XTOR0_DATA_WIDTH 64
#define XTOR0_ADDR_WIDTH 32
#define XTOR1_DATA_WIDTH 128
#define XTOR1_ADDR_WIDTH 32

#define EN_TRAIN

#define TRAIN_1ST_FREQ
//#define DEBUG_800_MHZ

#ifndef DEBUG_800_MHZ
#endif

//#define TRAIN_2ND_FREQ

#if WAGNER_FPGA == 0 // ASIC
//#define _STREAM_SIM_PRINT_
#define CHECK_DDR_RESET_TIME
#define MR_ODT_DRV
//#define DDR_DQ_SWAP
#else
#define _STREAM_SIM_PRINT_
#define CHECK_DDR_RESET_TIME
//#define MR_ODT_DRV
#endif

#define SOC_CA_DRV 40
#define DRAM_CA_ODT 60

#define SOC_DQ_DRV 60
#define DRAM_DQ_ODT 60

#define DRAM_DQ_DRV 60
#define SOC_DQ_ODT 60

#define WDQ_DRV 60
#define DrvStrenFSDq(DIVID) WDQ_DRV ## WDQ_DRV
enum DrvStrenFSDq_table{
	WDQ_DRV_HiZ = 0,
	WDQ_DRV_480,
	WDQ_DRV_240,
	WDQ_DRV_160,
	WDQ_DRV_120 = 8,
	WDQ_DRV_96,
	WDQ_DRV_80,
	WDQ_DRV_68,
	WDQ_DRV_60 = 0x18,
	WDQ_DRV_53,
	WDQ_DRV_48,
	WDQ_DRV_43,
	WDQ_DRV_40 = 0x38,
	WDQ_DRV_36,
	WDQ_DRV_34,
	WDQ_DRV_32,
	WDQ_DRV_30 = 0x3E,
	WDQ_DRV_28,
};

typedef  unsigned char uint8_t;
typedef  signed char int8_t;
typedef  unsigned short uint16_t;
typedef  signed short int16_t;
typedef  unsigned int uint32_t;
typedef  signed int int32_t;
typedef  unsigned long uint64_t;
typedef  signed long int64_t;

void ddrc_to_mhz(unsigned short frequncy);
void dwc_ddrphy_phyinit_userCustom_E_setDfiClk(unsigned char pstate);
void dwc_ddrphy_phyinit_userCustom_G_waitFwDone(void);
void dwc_ddrphy_phyinit_sequence(void);
void phy_init(void); 
void initial_pre_lp3(void);
void mctl_initial_post(void);
void reenable_power(void);
void remove_power(void);
void dram_test(void);
void memtester(void);

#endif


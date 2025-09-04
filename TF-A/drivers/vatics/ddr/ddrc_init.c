//#include <loader.h>
#include "lpddr4.h"
#include "../dmac/dmac.h"

//#############################################################
//sys_init
//
static void sys_init(void)
{
	unsigned int rvalue;

#if 0
	writel(0xFFFFFFFF,  SYSC_SECURE_MMR_BASE+(0x00000180)); //Clock0

	writel(0xFFFFFFFF, SYSC_SECURE_MMR_BASE+(0x00000188)); //Clock1

	writel(0xFFFFFFFF, SYSC_SECURE_MMR_BASE+(0x00000190)); //Clock 2

	writel(0xFFFFFFFF, SYSC_SECURE_MMR_BASE+(0x00000198)); //Clock 3

	writel(0xFFFFFFFF, SYSC_SECURE_MMR_BASE+(0x000001A0)); //Clock 4

	writel(0xFFFFFFFF, SYSC_SECURE_MMR_BASE+(0x000001A8)); //Clock 5
#endif

	writel(0x001FFFFF, SYSC_SECURE_MMR_BASE+(0x00000188)); //Clock1

	writel(0x00200007, SYSC_SECURE_MMR_BASE+(0x00000160)); //Reset 1

	writel(0x001FFFE0, SYSC_SECURE_MMR_BASE+(0x00000160));

	writel(0x00800000, SYSC_SECURE_MMR_BASE+(0x00000160));

	writel(0x00400010, SYSC_SECURE_MMR_BASE+(0x00000160));

	//Enable PHY and PUB clock in APM
	rvalue = readl(APM_BASE + 0x00000464);

	writel(rvalue | 0x000FFFF0, APM_BASE + 0x00000464);

	writel(0x00000003, APM_BASE+(0x00000470));
	//&rvalue=Data.Long(D:(&APM_BASE+0x00000470))
	//printf "MRL setting : %#x" &rvalue
}
//#############################################################
//;Version Check
//;

    //&rvalue=Data.Long(D:(&SYSC_SECURE_MMR_BASE+0x0))
    //printf "WAGNER_SYSC_VERSION = %#x , expected : &WAGNER_SYSC_VERSION"
//	 &rvalue
    //
void wagner_ddr_init(void)
{
	unsigned int val;

	sys_init();

	//;#############################################################
	//;uMCTL2 APB read/write Check
	//&rvalue=Data.Long(D:(&DDR3_TOP_CTRL_BASE+0x38))
	//printf "HWLPCTRL = %#x, expected : 0x00000003" &rvalue
	//data.out (&DDR3_TOP_CTRL_BASE+0x38) %long 0x05670002
	//&rvalue=Data.Long(D:(&DDR3_TOP_CTRL_BASE+0x38))
	//printf "HWLPCTRL = %#x, expected : 0x05670002" &rvalue
	//writel(0x05670002, DDR3_TOP_CTRL_BASE+0x38);

	//;#############################################################
	//;`include "lpddr4_mctl2_initial_reset.pat"
	//;

	//;srdata(`DDRNSDMC_APM_MMR_BASE + ( ((17 << 4) +  DDRC_RSTN_CTRL) *4 )
	//		 , data );
	//;sw(`DDRNSDMC_APM_MMR_BASE + ( ((17 << 4) +  DDRC_RSTN_CTRL) *4 ),
	//		 data | 4'b0010,  2); // ddrc presetn =1
	//&rvalue=Data.Long(D:(&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)))
	val = readl(APM_BASE + (((17<<4)+DDRC_RSTN_CTRL) * 4));
	writel(val | 0x00000002, APM_BASE + (((17<<4)+DDRC_RSTN_CTRL) * 4));

	//;10ns;
	//;#sw(`DDRNSDMC_APM_MMR_BASE + ( ((17 << 4) +  DDRC_PWROKIN) *4 ), 1,
	//	  2); // PwrOkIn = 1;
	//;10ns;
	//;#############################################################
	//;ddr4_c_init_pre_lp3
	//;
	initial_pre_lp3();

	//print "Release core_ddrc_rstn"
	//;`include "lpddr4_phy_initial_reset.pat"
	//&rvalue=Data.Long(D:(&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)))
	//Data.Out (&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)) %Long
	// (&rvalue|0x00000001)
	val = readl(APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));
	writel(val | 0x00000001, APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));


	//&rvalue=Data.Long(D:(&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)))
	//Data.Out (&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)) %Long
	// (&rvalue|0x00000004)
	val = readl(APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));
	writel(val | 0x00000004, APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));

	//&rvalue=Data.Long(D:(&APM_BASE+(((17<<4)+&DDRC_CLK_CTRL)*4)))
	//Data.Out (&APM_BASE+(((17<<4)+&DDRC_CLK_CTRL)*4)) %Long
	// (&rvalue|0x000FFFF0)
	val = readl(APM_BASE+(((17<<4)+DDRC_CLK_CTRL)*4));
	writel(val | 0x000FFFF0, APM_BASE+(((17<<4)+DDRC_CLK_CTRL)*4));

	//&rvalue=Data.Long(D:(&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)))
	//Data.Out (&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)) %Long
	// (&rvalue|0x00000007)
	val = readl(APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));
	writel(val | 0x00000007, APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));


	//&rvalue=Data.Long(D:(&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)))
	//Data.Out (&APM_BASE+(((17<<4)+&DDRC_RSTN_CTRL)*4)) %Long
	// (&rvalue|0x000FFFF0)
	val = readl(APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));
	writel(val | 0x000FFFF0, APM_BASE+(((17<<4)+DDRC_RSTN_CTRL)*4));


	//;#------------------------
	//;#Step 4  Disable self-refresh, power down and assertion of
	// dfi_dram_clk_disable
	//;#------------------------
	//data.out (&DDR3_TOP_CTRL_BASE+0x00000060) %long 0x00010000
	writel(0x00010000, DDR3_TOP_CTRL_BASE+0x00000060);
	//    ;#Disble rank0 refresh

	//;#------------------------
	//;#Step 5  Set SWCTL.sw_done to 0
	//;#------------------------
	//;# w uMCTL2 [expr 0x320     SWCTL) Register
	//data.out (&DDR3_TOP_CTRL_BASE+0x00000320) %long 0x00000000
	writel(0x00000000, DDR3_TOP_CTRL_BASE+0x00000320);
	//    ;#Set sw_done = 0

	//;------------------------
	//;#Step 6  Set DFIMISC.dfi_init_complete_en = 0
	//;#------------------------
	//;# w uMCTL2 [expr 0x1b0     DFIMISC) Register
	//&rvalue=Data.Long(D:(&DDR3_TOP_CTRL_BASE+0x000001b0))
	//Data.Out (&DDR3_TOP_CTRL_BASE+0x000001b0) %Long (&rvalue&0xfffffffe)
	val = readl(DDR3_TOP_CTRL_BASE+0x000001b0);
	writel(val & 0xfffffffe, DDR3_TOP_CTRL_BASE+0x000001b0);
	//    ;#bit[0] Set dfi_init_complete_en = 0

	//;#------------------------
	//;#Step 7  Set SWCTL.sw_done to 1
	//;#------------------------
	//;# w uMCTL2 [expr 0x320     SWCTL) Register
	//data.out (&DDR3_TOP_CTRL_BASE+0x00000320) %long 0x00000001
	writel(0x00000001, DDR3_TOP_CTRL_BASE+0x00000320);
	//    ;#Set sw_done = 1

	//;#Polling
	//WHILE (Data.Long(D:(&DDR3_TOP_CTRL_BASE+0x00000324))&0x00000001)==0
	//    print "polling DDR3_TOP_CTRL_BASE" &DDR3_TOP_CTRL_BASE
	while ((readl(DDR3_TOP_CTRL_BASE+0x00000324) & 0x1) == 0)
		;


	//;Check Version
	//;srdata(`DDRNSDMC_MCTL_MMR_BASE+'h00000ff0, data); //check version
	//;src((`DDRNSDMC_PUB_MMR_BASE+32'h001801dc), 16'h2440, 1); //check version
	//;srdata(`DDRNSDMC_APM_MMR_BASE  + 32'h444,data);  //check version
	//
	//;sw((`SYSC_SECURE_MMR_BASE+32'h00000160), 32'h00000008, 2);
	// release DDRNSDMC MCTL CLK
	//data.out (&SYSC_SECURE_MMR_BASE+(0x00000160)) %long 0x00000008
	
	writel(0x00000004, SYSC_SECURE_MMR_BASE + (0x0000018C)); 
	// stop MCTL clock	val = readl(VPL_SYSC_MMR_BASE + 0x0000004C);
	writel(0x00000008, SYSC_SECURE_MMR_BASE + (0x00000160));
	// release DDRNSDMC MCTL release	val = readl(VPL_SYSC_MMR_BASE + 0x0000004C);
	writel(0x00000004, SYSC_SECURE_MMR_BASE + (0x00000188));
	// start MCTL clock	val = readl(VPL_SYSC_MMR_BASE + 0x0000004C);

#if (DDR_DQ_SWAP==1)
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa0), 0x0);  //DQ0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa1), 0x5);  //DQ1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa2), 0x7);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa3), 0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa4), 0x4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa5), 0x1);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa6), 0x3);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000          + 0xa7), 0x2);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa0), 0x2);  //DQ0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa1), 0x3);  //DQ1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa2), 0x0);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa3), 0x1);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa4), 0x7);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa5), 0x5);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa6), 0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x1000 + 0xa7), 0x4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa0), 0x5);  //DQ0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa1), 0x0);  //DQ1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa2), 0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa3), 0x2);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa4), 0x3);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa5), 0x1);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa6), 0x7);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x2000 + 0xa7), 0x4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa0), 0x0);  //DQ0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa1), 0x3);  //DQ1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa2), 0x4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa3), 0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa4), 0x7);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa5), 0x5);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa6), 0x2);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * (0x10000 + 0x3000 + 0xa7), 0x1);
#endif

#ifdef DEBUG_800_MHZ
	ddrc_to_mhz(800);
#else
	ddrc_to_mhz(DRAM_BUSCLK);
#endif

	mww(DDRNSDMC_PUB_MMR_BASE + 2*0xd0099,0x1); //MicroReset
	mww(DDRNSDMC_PUB_MMR_BASE + 2*0xd0000,0x0); //MicroContMuxSel
	mww(DDRNSDMC_PUB_MMR_BASE + 2*0xc0080,0x3); //UcclkHclkEnables
	dmac_copy_ddrphy_fw();

	dwc_ddrphy_phyinit_sequence();

	//
	//;##############################################################
	//;ddr4_c_init_post
	//;
	//

	mctl_initial_post();

#if (DEBUG_DRAM == 1)
	//dram_test();
	memtester();
	//mtest();
#endif
}

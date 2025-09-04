#include "dmac.h"
#include "sim_print.h"
#include "pll.h"
#include "csr_defines.h"
#include "lpddr4.h"
#include <string.h>
#include <stdio.h>
#include <common/debug.h>

#include "mnPmuSramMsgBlock_lpddr4.h"

#ifdef EN_TRAIN
unsigned int mail;
char *pmu_train_string[412] = {
	"PMU1:prbsGenCtl:%x\n",
	"PMU1: loading 2D acsm sequence\n",
	"PMU1: loading 1D acsm sequence\n",
	"PMU3: %d memclocks @ %d to get half of 300ns\n",
	"PMU: Error: User requested MPR read pattern for read DQS training in DDR3 Mode\n",
	"PMU3: Running 1D search for left eye edge\n",
	"PMU1: In Phase Left Edge Search cs %d\n",
	"PMU1: Out of Phase Left Edge Search cs %d\n",
	"PMU3: Running 1D search for right eye edge\n",
	"PMU1: In Phase Right Edge Search cs %d\n",
	"PMU1: Out of Phase Right Edge Search cs %d\n",
	"PMU1: mxRdLat training pstate %d\n",
	"PMU1: mxRdLat search for cs %d\n",
	"PMU0: MaxRdLat non consistant DtsmLoThldXingInd 0x%03x\n",
	"PMU4: CS %d Dbyte %d worked with DFIMRL = %d DFICLKs \n",
	"PMU3: MaxRdLat Read Lane err mask for csn %d, DFIMRL %2d DFIClks, dbyte %d = 0x%03x\n",
	"PMU3: MaxRdLat Read Lane err mask for csn %d DFIMRL %2d, All dbytes = 0x%03x\n",
	"PMU: Error: CS%d failed to find a DFIMRL setting that worked for all bytes during MaxRdLat training\n",
	"PMU3: Smallest passing DFIMRL for all dbytes in CS%d = %d DFIClks\n",
	"PMU: Error: No passing DFIMRL value found for any chip select during MaxRdLat training\n",
	"PMU: Error: Dbyte %d lane %d txDqDly passing region is too small (width = %d)\n",
	"PMU4: Adjusting rxclkdly db %d nib %d from %d+%d=%d->%d\n",
	"PMU4: TxDqDly Passing Regions (EyeLeft EyeRight -> EyeCenter) Units=1/32 UI\n",
	"PMU4: DB %d Lane %d: %3d %3d -> %3d\n",
	"PMU2: TXDQ delayLeft[%2d] = %3d (DISCONNECTED)\n",
	"PMU2: TXDQ delayLeft[%2d] = %3d oopScaled = %3d selectOop %d\n",
	"PMU2: TXDQ delayRight[%2d] = %3d (DISCONNECTED)\n",
	"PMU2: TXDQ delayRight[%2d] = %3d oopScaled = %3d selectOop %d\n",
	"PMU: Error: Dbyte %d lane %d txDqDly passing region is too small (width = %d)\n",
	"PMU4: TxDqDly Passing Regions (EyeLeft EyeRight -> EyeCenter) Units=1/32 UI\n",
	"PMU4: DB %d Lane %d: (DISCONNECTED)\n",
	"PMU4: DB %d Lane %d: %3d %3d -> %3d\n",
	"PMU3: Running 1D search csn %d for DM Right/NotLeft(%d) eye edge\n",
	"PMU3: WrDq DM byte%2d with Errcnt %d\n",
	"PMU3: WrDq DM byte%2d avgDly 0x%04x\n",
	"PMU1: WrDq DM byte%2d with Errcnt %d\n",
	"PMU: Error: Dbyte %d txDqDly DM training did not start inside the eye\n",
	"PMU4: DM TxDqDly Passing Regions (EyeLeft EyeRight -> EyeCenter) Units=1/32 UI\n",
	"PMU4: DB %d Lane %d: (DISCONNECTED)\n",
	"PMU4: DB %d Lane %d: %3d %3d -> %3d\n",
	"PMU: Error: Dbyte %d lane %d txDqDly DM passing region is too small (width = %d)\n",
	"PMU3: Errcnt for MRD/MWD search nib %2d delay = (%d, 0x%02x) = %d\n",
	"PMU3: Precharge all open banks\n",
	"PMU: Error: Dbyte %d nibble %d found multiple working coarse delay setting for MRD/MWD\n",
	"PMU4: MRD Passing Regions (coarseVal, fineLeft fineRight -> fineCenter)\n",
	"PMU4: MWD Passing Regions (coarseVal, fineLeft fineRight -> fineCenter)\n",
	"PMU10: Warning: DB %d nibble %d has multiple working coarse positions, %d and %d, choosing the smaller delay\n",
	"PMU: Error: Dbyte %d nibble %d MRD/MWD passing region is too small (width = %d)\n",
	"PMU4: DB %d nibble %d: %3d, %3d %3d -> %3d\n",
	"PMU1: Start MRD/nMWD %d for csn %d\n",
	"PMU2: RXDQS delayLeft[%2d] = %3d (DISCONNECTED)\n",
	"PMU2: RXDQS delayLeft[%2d] = %3d delayOop[%2d] = %3d OopScaled %4d, selectOop %d\n",
	"PMU2: RXDQS delayRight[%2d] = %3d (DISCONNECTED)\n",
	"PMU2: RXDQS delayRight[%2d] = %3d delayOop[%2d] = %4d OopScaled %4d, selectOop %d\n",
	"PMU4: RxClkDly Passing Regions (EyeLeft EyeRight -> EyeCenter)\n",
	"PMU4: DB %d nibble %d: (DISCONNECTED)\n",
	"PMU4: DB %d nibble %d: %3d %3d -> %3d\n",
	"PMU: Error: Dbyte %d nibble %d rxClkDly passing region is too small (width = %d)\n",
	"PMU0: goodbar = %d for RDWR_BLEN %d\n",
	"PMU3: RxClkDly = %d\n",
	"PMU0: db %d l %d absLane %d -> bottom %d top %d\n",
	"PMU3: BYTE %d - %3d %3d %3d %3d %3d %3d %3d %3d\n",
	"PMU: Error: dbyte %d lane %d's per-lane vrefDAC's had no passing region\n",
	"PMU0: db%d l%d - %d %d\n",
	"PMU0: goodbar = %d for RDWR_BLEN %d\n",
	"PMU3: db%d l%d saw %d issues at rxClkDly %d\n",
	"PMU3: db%d l%d first saw a pass->fail edge at rxClkDly %d\n",
	"PMU3: lane %d PBD = %d\n",
	"PMU3: db%d l%d first saw a DBI pass->fail edge at rxClkDly %d\n",
	"PMU2: db%d l%d already passed rxPBD = %d\n",
	"PMU0: db%d l%d, PBD = %d\n",
	"PMU: Error: dbyte %d lane %d failed read deskew\n",
	"PMU0: db%d l%d, inc PBD = %d\n",
	"PMU1: Running lane deskew on pstate %d csn %d rdDBIEn %d\n",
	"PMU: Error: Read deskew training has been requested, but csrMajorModeDbyte[2] is set\n",
	"PMU1: AcsmCsMapCtrl%02d 0x%04x\n",
	"PMU1: AcsmCsMapCtrl%02d 0x%04x\n",
	"PMU: Error: Wrong PMU image loaded. message Block DramType = 0x%02x, but image built for D3U Type\n",
	"PMU: Error: Wrong PMU image loaded. message Block DramType = 0x%02x, but image built for D3R Type\n",
	"PMU: Error: Wrong PMU image loaded. message Block DramType = 0x%02x, but image built for D4U Type\n",
	"PMU: Error: Wrong PMU image loaded. message Block DramType = 0x%02x, but image built for D4R Type\n",
	"PMU: Error: Wrong PMU image loaded. message Block DramType = 0x%02x, but image built for D4LR Type\n",
	"PMU: Error: Both 2t timing mode and ddr4 geardown mode specifed in the messageblock's PhyCfg and MR3 fields. Only one can be enabled\n",
	"PMU10: PHY TOTALS - NUM_DBYTES %d NUM_NIBBLES %d NUM_ANIBS %d\n",
	"PMU10: CSA=0x%02X, CSB=0x%02X, TSTAGES=0x%04X, HDTOUT=%d, MMISC=%d DRAMFreq=%dMT DramType=LPDDR3\n",
	"PMU10: CSA=0x%02X, CSB=0x%02X, TSTAGES=0x%04X, HDTOUT=%d, MMISC=%d DRAMFreq=%dMT DramType=LPDDR4\n",
	"PMU10: CS=0x%02X, TSTAGES=0x%04X, HDTOUT=%d, 2T=%d, MMISC=%d AddrMirror=%d DRAMFreq=%dMT DramType=%d\n",
	"PMU10: Pstate%d MR0=0x%04X MR1=0x%04X MR2=0x%04X\n",
	"PMU10: Pstate%d MRS MR0=0x%04X MR1=0x%04X MR2=0x%04X MR3=0x%04X MR4=0x%04X MR5=0x%04X MR6=0x%04X\n",
	"PMU10: Pstate%d MRS MR1_A0=0x%04X MR2_A0=0x%04X MR3_A0=0x%04X MR11_A0=0x%04X\n",
	"PMU10: UseBroadcastMR set. All ranks and channels use MRXX_A0 for MR settings.\n",
	"PMU10: Pstate%d MRS MR01_A0=0x%02X MR02_A0=0x%02X MR03_A0=0x%02X MR11_A0=0x%02X\n",
	"PMU10: Pstate%d MRS MR12_A0=0x%02X MR13_A0=0x%02X MR14_A0=0x%02X MR22_A0=0x%02X\n",
	"PMU10: Pstate%d MRS MR01_A1=0x%02X MR02_A1=0x%02X MR03_A1=0x%02X MR11_A1=0x%02X\n",
	"PMU10: Pstate%d MRS MR12_A1=0x%02X MR13_A1=0x%02X MR14_A1=0x%02X MR22_A1=0x%02X\n",
	"PMU10: Pstate%d MRS MR01_B0=0x%02X MR02_B0=0x%02X MR03_B0=0x%02X MR11_B0=0x%02X\n",
	"PMU10: Pstate%d MRS MR12_B0=0x%02X MR13_B0=0x%02X MR14_B0=0x%02X MR22_B0=0x%02X\n",
	"PMU10: Pstate%d MRS MR01_B1=0x%02X MR02_B1=0x%02X MR03_B1=0x%02X MR11_B1=0x%02X\n",
	"PMU10: Pstate%d MRS MR12_B1=0x%02X MR13_B1=0x%02X MR14_B1=0x%02X MR22_B1=0x%02X\n",
	"PMU1: AcsmOdtCtrl%02d 0x%02x\n",
	"PMU1: AcsmCsMapCtrl%02d 0x%04x\n",
	"PMU1: AcsmCsMapCtrl%02d 0x%04x\n",
	"PMU1: HwtCAMode set\n",
	"PMU3: DDR4 infinite preamble enter/exit mode %d\n",
	"PMU1: In rxenb_train() csn=%d pstate=%d\n",
	"PMU3: Finding DQS falling edge\n",
	"PMU3: Searching for DDR3/LPDDR3/LPDDR4 read preamble\n",
	"PMU3: dtsm fails Even Nibbles : %2x %2x %2x %2x %2x %2x %2x %2x %2x\n",
	"PMU3: dtsm fails Odd  Nibbles : %2x %2x %2x %2x %2x %2x %2x %2x %2x\n",
	"PMU3: Preamble search pass=%d anyfail=%d\n",
	"PMU: Error: RxEn training preamble not found\n",
	"PMU3: Found DQS pre-amble\n",
	"PMU: Error: Dbyte %d couldn't find the rising edge of DQS during RxEn Training\n",
	"PMU3: RxEn aligning to first rising edge of burst\n",
	"PMU3: Decreasing RxEn delay by %d fine step to allow full capture of reads\n",
	"PMU3: MREP Delay = %d\n",
	"PMU3: Errcnt for MREP nib %2d delay = %2d is %d\n",
	"PMU3: MREP nibble %d sampled a 1 at data buffer delay %d\n",
	"PMU3: MREP nibble %d saw a 0 to 1 transition at data buffer delay %d\n",
	"PMU2:  MREP did not find a 0 to 1 transition for all nibbles. Failing nibbles assumed to have rising edge close to fine delay 63\n",
	"PMU2:  Rising edge found in alias window, setting rxDly for nibble %d = %d\n",
	"PMU: Error: Failed MREP for nib %d with %d one\n",
	"PMU2:  Rising edge not found in alias window with %d one, leaving rxDly for nibble %d = %d\n",
	"PMU3: Training DIMM %d CSn %d\n",
	"PMU3: exitCAtrain_lp3 cs 0x%x\n",
	"PMU3: enterCAtrain_lp3 cs 0x%x\n",
	"PMU3: CAtrain_switchmsb_lp3 cs 0x%x\n",
	"PMU3: CATrain_rdwr_lp3 looking for pattern %x\n",
	"PMU3: exitCAtrain_lp4\n",
	"PMU3: DEBUG enterCAtrain_lp4 1: cs 0x%x\n",
	"PMU3: DEBUG enterCAtrain_lp4 3: Put dbyte %d in async mode\n",
	"PMU3: DEBUG enterCAtrain_lp4 5: Send MR13 to turn on CA training\n",
	"PMU3: DEBUG enterCAtrain_lp4 7: idx = %d vref = %x mr12 = %x \n",
	"PMU3: CATrain_rdwr_lp4 looking for pattern %x\n",
	"PMU3: Phase %d CAreadbackA db:%d %x xo:%x\n",
	"PMU3: DEBUG lp4SetCatrVref 1: cs=%d chan=%d mr12=%x vref=%d.%d%%\n",
	"PMU3: DEBUG lp4SetCatrVref 3: mr12 = %x send vref= %x to db=%d\n",
	"PMU10:Optimizing vref\n",
	"PMU4:mr12:%2x cs:%d chan %d r:%4x\n",
	"PMU3: i:%2d bstr:%2d bsto:%2d st:%d r:%d\n",
	"Failed to find sufficient CA Vref Passing Region for CS %d channel %d\n",
	"PMU3:Found %d.%d%% MR12:%x for cs:%d chan %d\n",
	"PMU3:Calculated %d for AtxImpedence from acx %d.\n",
	"PMU3:CA Odt impedence ==0.  Use default vref.\n",
	"PMU3:Calculated %d.%d%% for Vref MR12=0x%x.\n",
	"PMU3: CAtrain_lp\n",
	"PMU3: CAtrain Begins.\n",
	"PMU3: CAtrain_lp testing dly %d\n",
	"PMU5: CA bitmap dump for cs %x\n",
	"PMU5: CAA%d ",
	"%02x",
	"\n",
	"PMU5: CAB%d ",
	"%02x",
	"\n",
	"PMU3: anibi=%d, anibichan[anibi]=%d ,chan=%d\n",
	"%02x",
	"PMU3:Raw CA setting :%x\n",
	"PMU3:ATxDly setting:%x margin:%d\n",
	"PMU3:InvClk ATxDly setting:%x margin:%d\n",
	"PMU3:No Range found!\n",
	"PMU3: 2 anibi=%d, anibichan[anibi]=%d ,chan=%d\n",
	"PMU3: no neg clock => CA setting anib=%d, :%d\n",
	"PMU3:Normal margin:%d\n",
	"PMU3:Inverted margin:%d\n",
	"PMU3:Using Inverted clock\n",
	"PMU3:Using normal clk\n",
	"PMU3: 3 anibi=%d, anibichan[anibi]=%d ,chan=%d\n",
	"PMU3: Setting ATxDly for anib %x to %x\n",
	"PMU: Error: CA Training Failed.\n",
	"PMU1: Writing MRs\n",
	"PMU4:Using MR12 values from 1D CA VREF training.\n",
	"PMU3:Writing all MRs to fsp 1\n",
	"PMU10:Lp4Quickboot mode.\n",
	"PMU3: Writing MRs\n",
	"PMU10: Setting boot clock divider to %d\n",
	"PMU3: Resetting DRAM\n",
	"PMU3: setup for RCD initalization\n",
	"PMU3: pmu_exit_SR from dev_init()\n",
	"PMU3: initializing RCD\n",
	"PMU10: **** Executing 2D Image ****\n",
	"PMU10: **** Start DDR4 Training. PMU Firmware Revision 0x%04x ****\n",
	"PMU10: **** Start DDR3 Training. PMU Firmware Revision 0x%04x ****\n",
	"PMU10: **** Start LPDDR3 Training. PMU Firmware Revision 0x%04x ****\n",
	"PMU10: **** Start LPDDR4 Training. PMU Firmware Revision 0x%04x ****\n",
	"PMU: Error: Mismatched internal revision between DCCM and ICCM images\n",
	"PMU10: **** Testchip %d Specific Firmware ****\n",
	"PMU1: LRDIMM with EncodedCS mode, one DIMM\n",
	"PMU1: LRDIMM with EncodedCS mode, two DIMMs\n",
	"PMU1: RDIMM with EncodedCS mode, one DIMM\n",
	"PMU2: Starting LRDIMM MREP training for all ranks\n",
	"PMU199: LRDIMM MREP training for all ranks completed\n",
	"PMU2: Starting LRDIMM DWL training for all ranks\n",
	"PMU199: LRDIMM DWL training for all ranks completed\n",
	"PMU2: Starting LRDIMM MRD training for all ranks\n",
	"PMU199: LRDIMM MRD training for all ranks completed\n",
	"PMU2: Starting RXEN training for all ranks\n",
	"PMU2: Starting write leveling fine delay training for all ranks\n",
	"PMU2: Starting LRDIMM MWD training for all ranks\n",
	"PMU199: LRDIMM MWD training for all ranks completed\n",
	"PMU2: Starting write leveling fine delay training for all ranks\n",
	"PMU2: Starting read deskew training\n",
	"PMU2: Starting SI friendly 1d RdDqs training for all ranks\n",
	"PMU2: Starting write leveling coarse delay training for all ranks\n",
	"PMU2: Starting 1d WrDq training for all ranks\n",
	"PMU2: Running DQS2DQ Oscillator for all ranks\n",
	"PMU2: Starting again read deskew training but with PRBS\n",
	"PMU2: Starting 1d RdDqs training for all ranks\n",
	"PMU2: Starting again 1d WrDq training for all ranks\n",
	"PMU2: Starting MaxRdLat training\n",
	"PMU2: Starting 2d RdDqs training for all ranks\n",
	"PMU2: Starting 2d WrDq training for all ranks\n",
	"PMU2: Starting 2d RdDqs training for all ranks\n",
	"PMU3:read_fifo %x %x\n",
	"PMU: Error: Invalid PhyDrvImpedance of 0x%x specified in message block.\n",
	"PMU: Error: Invalid PhyOdtImpedance of 0x%x specified in message block.\n",
	"PMU: Error: Invalid BPZNResVal of 0x%x specified in message block.\n",
	"PMU3: fixRxEnBackOff csn:%d db:%d dn:%d bo:%d dly:%x\n",
	"PMU3: fixRxEnBackOff dly:%x\n",
	"PMU3: Entering setupPpt\n",
	"PMU3: Start lp4PopulateHighLowBytes\n",
	"PMU3:Dbyte Detect: db%d received %x\n",
	"PMU3:getDqs2Dq read %x from dbyte %d\n",
	"PMU3:getDqs2Dq(2) read %x from dbyte %d\n",
	"PMU: Error: Dbyte %d read 0 from the DQS oscillator it is connected to\n",
	"PMU4: Dbyte %d dqs2dq = %d/32 UI\n",
	"PMU3:getDqs2Dq set dqs2dq:%d/32 ui (%d ps) from dbyte %d\n",
	"PMU3: Setting coarse delay in AtxDly chiplet %d from 0x%02x to 0x%02x \n",
	"PMU3: Clearing coarse delay in AtxDly chiplet %d from 0x%02x to 0x%02x \n",
	"PMU3: Performing DDR4 geardown sync sequence\n",
	"PMU1: Enter self refresh\n",
	"PMU1: Exit self refresh\n",
	"PMU: Error: No dbiEnable with lp4\n",
	"PMU: Error: No dbiDisable with lp4\n",
	"PMU1: DDR4 update Rx DBI Setting disable %d\n",
	"PMU1: DDR4 update 2nCk WPre Setting disable %d\n",
	"PMU1: read_delay: db%d lane%d delays[%2d] = 0x%02x (max 0x%02x)\n",
	"PMU1: write_delay: db%d lane%d delays[%2d] = 0x%04x\n",
	"PMU5: ID=%d -- db0  db1  db2  db3  db4  db5  db6  db7  db8  db9 --\n",
	"PMU5: [%d]:0x %4x %4x %4x %4x %4x %4x %4x %4x %4x %4x\n",
	"PMU2: dump delays - pstate=%d dimm=%d csn=%d\n",
	"PMU3: Printing Mid-Training Delay Information\n",
	"PMU5: CS%d <<KEY>> 0 TrainingCntr <<KEY>> coarse(15:10) fine(9:0)\n",
	"PMU5: CS%d <<KEY>> 0 RxEnDly, 1 RxClkDly <<KEY>> coarse(10:6) fine(5:0)\n",
	"PMU5: CS%d <<KEY>> 0 TxDqsDly, 1 TxDqDly <<KEY>> coarse(9:6) fine(5:0)\n",
	"PMU5: CS%d <<KEY>> 0 RxPBDly <<KEY>> 1 Delay Unit ~= 7ps \n",
	"PMU5: all CS <<KEY>> 0 DFIMRL <<KEY>> Units = DFI clocks\n",
	"PMU5: all CS <<KEY>> VrefDACs <<KEY>> DAC(6:0)\n",
	"PMU1: Set DMD in MR13 and wrDBI in MR3 for training\n",
	"PMU: Error: getMaxRxen() failed to find largest rxen nibble delay\n",
	"PMU2: getMaxRxen(): maxDly %d maxTg %d maxNib %d\n",
	"PMU2: getRankMaxRxen(): maxDly %d Tg %d maxNib %d\n",
	"PMU1: skipping CDD calculation in 2D image\n",
	"PMU3: Calculating CDDs for pstate %d\n",
	"PMU3: rxFromDly[%d][%d] = %d\n",
	"PMU3: rxToDly  [%d][%d] = %d\n",
	"PMU3: rxDly    [%d][%d] = %d\n",
	"PMU3: txDly	[%d][%d] = %d\n",
	"PMU3: allFine CDD_RR_%d_%d = %d\n",
	"PMU3: allFine CDD_WW_%d_%d = %d\n",
	"PMU3: CDD_RR_%d_%d = %d\n",
	"PMU3: CDD_WW_%d_%d = %d\n",
	"PMU3: allFine CDD_RW_%d_%d = %d\n",
	"PMU3: allFine CDD_WR_%d_%d = %d\n",
	"PMU3: CDD_RW_%d_%d = %d\n",
	"PMU3: CDD_WR_%d_%d = %d\n",
	"PMU3: F%dBC2x_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBC3x_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBC4x_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBC5x_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBC8x_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBC9x_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBCAx_B%d_D%d = 0x%02x\n",
	"PMU3: F%dBCBx_B%d_D%d = 0x%02x\n",
	"PMU10: Entering context_switch_postamble\n",
	"PMU10: context_switch_postamble is enabled for DIMM %d, RC0A=0x%x, RC3x=0x%x\n",
	"PMU10: Setting bcw fspace 0\n",
	"PMU10: Sending BC0A = 0x%x\n",
	"PMU10: Sending BC6x = 0x%x\n",
	"PMU10: Sending RC0A = 0x%x\n",
	"PMU10: Sending RC3x = 0x%x\n",
	"PMU10: Sending RC0A = 0x%x\n",
	"PMU1: enter_lp3: DEBUG: pstate = %d\n",
	"PMU1: enter_lp3: DEBUG: dfifreqxlat_pstate = %d\n",
	"PMU1: enter_lp3: DEBUG: pllbypass = %d\n",
	"PMU1: enter_lp3: DEBUG: forcecal = %d\n",
	"PMU1: enter_lp3: DEBUG: pllmaxrange = 0x%x\n",
	"PMU1: enter_lp3: DEBUG: dacval_out = 0x%x\n",
	"PMU1: enter_lp3: DEBUG: pllctrl3 = 0x%x\n",
	"PMU3: Loading DRAM with BIOS supplied MR values and entering self refresh prior to exiting PMU code.\n",
	"PMU3: Setting DataBuffer function space of dimmcs 0x%02x to %d\n",
	"PMU4: Setting RCW FxRC%Xx = 0x%02x\n",
	"PMU4: Setting RCW FxRC%02X = 0x%02x\n",
	"PMU1: DDR4 update Rd Pre Setting disable %d\n",
	"PMU2: Setting BCW FxBC%Xx = 0x%02x\n",
	"PMU2: Setting BCW BC%02X = 0x%02x\n",
	"PMU2: Setting BCW PBA mode FxBC%Xx = 0x%02x\n",
	"PMU2: Setting BCW PBA mode BC%02X = 0x%02x\n",
	"PMU4: BCW value for dimm %d, fspace %d, addr 0x%04x\n",
	"PMU4: DB %d, value 0x%02x\n",
	"PMU6: WARNING MREP underflow, set to min value -2 coarse, 0 fine\n",
	"PMU6: LRDIMM Writing final data buffer fine delay value nib %2d, trainDly %3d, fineDly code %2d, new MREP fine %2d\n",
	"PMU6: LRDIMM Writing final data buffer fine delay value nib %2d, trainDly %3d, fineDly code %2d\n",
	"PMU6: LRDIMM Writing data buffer fine delay type %d nib %2d, code %2d\n",
	"PMU6: Writing final data buffer coarse delay value dbyte %2d, coarse = 0x%02x\n",
	"PMU4: data 0x%04x at MB addr 0x%08x saved at CSR addr 0x%08x\n",
	"PMU4: data 0x%04x at MB addr 0x%08x restored from CSR addr 0x%08x\n",
	"PMU4: data 0x%04x at MB addr 0x%08x saved at CSR addr 0x%08x\n",
	"PMU4: data 0x%04x at MB addr 0x%08x restored from CSR addr 0x%08x\n",
	"PMU3: Update BC00, BC01, BC02 for rank-dimm 0x%02x\n",
	"PMU3: Writing D4 RDIMM RCD Control words F0RC00 -> F0RC0F\n",
	"PMU3: Disable parity in F0RC0E\n",
	"PMU3: Writing D4 RDIMM RCD Control words F1RC00 -> F1RC05\n",
	"PMU3: Writing D4 RDIMM RCD Control words F1RC1x -> F1RC9x\n",
	"PMU3: Writing D4 Data buffer Control words BC00 -> BC0E\n",
	"PMU1: setAltCL Sending MR0 0x%x cl=%d\n",
	"PMU1: restoreFromAltCL Sending MR0 0x%x cl=%d\n",
	"PMU1: restoreAcsmFromAltCL Sending MR0 0x%x cl=%d\n",
	"PMU2: Setting D3R RC%d = 0x%01x\n",
	"PMU3: Writing D3 RDIMM RCD Control words RC0 -> RC11\n",
	"PMU0: VrefDAC0/1 vddqStart %d dacToVddq %d\n",
	"PMU: Error: Messageblock phyVref=0x%x is above the limit for TSMC28's attenuated LPDDR4 receivers. Please see the pub databook\n",
	"PMU: Error: Messageblock phyVref=0x%x is above the limit for TSMC28's attenuated DDR4 receivers. Please see the pub databook\n",
	"PMU0: PHY VREF @ (%d/1000) VDDQ\n",
	"PMU0: initalizing phy vrefDacs to %d ExtVrefRange %x\n",
	"PMU0: initalizing global vref to %d range %d\n",
	"PMU4: Setting initial device vrefDQ for CS%d to MR6 = 0x%04x\n",
	"PMU1: In write_level_fine() csn=%d dimm=%d pstate=%d\n",
	"PMU3: Fine write leveling hardware search increasing TxDqsDly until full bursts are seen\n",
	"PMU4: WL normalized pos	: ........................|........................\n",
	"PMU4: WL margin for nib %2d: %08x%08x%08x%08x%08x%08x\n",
	"PMU4: WL normalized pos   : ........................|........................\n",
	"PMU3: Exiting write leveling mode\n",
	"PMU3: got %d for cl in load_wrlvl_acsm\n",
	"PMU1: In write_level_coarse() csn=%d dimm=%d pstate=%d\n",
	"PMU3: left eye edge search db:%d ln:%d dly:0x%x\n",
	"PMU3: right eye edge search db:%d ln:%d dly:0x%x\n",
	"PMU3: eye center db:%d ln:%d dly:0x%x (maxdq:%x)\n",
	"PMU3: Wrote to TxDqDly db:%d ln:%d dly:0x%x\n",
	"PMU3: Wrote to TxDqDly db:%d ln:%d dly:0x%x\n",
	"PMU3: Coarse write leveling dbyte%2d is still failing for TxDqsDly=0x%04x\n",
	"PMU4: Coarse write leveling iteration %d saw %d data miscompares across the entire phy\n",
	"PMU: Error: Failed write leveling coarse\n",
	"PMU3: got %d for cl in load_wrlvl_acsm\n",
	"PMU3: In write_level_coarse() csn=%d dimm=%d pstate=%d\n",
	"PMU3: left eye edge search db:%d ln:%d dly:0x%x\n",
	"PMU3: right eye edge search db: %d ln: %d dly: 0x%x\n",
	"PMU3: eye center db: %d ln: %d dly: 0x%x (maxdq: 0x%x)\n",
	"PMU3: Wrote to TxDqDly db: %d ln: %d dly: 0x%x\n",
	"PMU3: Wrote to TxDqDly db: %d ln: %d dly: 0x%x\n",
	"PMU3: Coarse write leveling nibble%2d is still failing for TxDqsDly=0x%04x\n",	
	"PMU4: Coarse write leveling iteration %d saw %d data miscompares across the entire phy\n",
	"PMU: Error: Failed write leveling coarse\n",
	"PMU4: WL normalized pos	 : ................................|................................\n",
	"PMU4: WL margin for nib %2d: %08x%08x%08x%08x%08x%08x%08x%08x\n",
	"PMU4: WL normalized pos   : ................................|................................\n",
	"PMU8: Adjust margin after WL coarse to be larger than %d\n",
	"PMU: Error: All margin after write leveling coarse are smaller than minMargin %d\n",
	"PMU8: Decrement nib %d TxDqsDly by %d fine step\n",
	"PMU3: In write_level_coarse() csn=%d dimm=%d pstate=%d\n",
	"PMU2: Write level: dbyte %d nib%d dq/dmbi %2d dqsfine 0x%04x dqDly 0x%04x\n",
	"PMU3: Coarse write leveling nibble%2d is still failing for TxDqsDly=0x%04x\n",
	"PMU4: Coarse write leveling iteration %d saw %d data miscompares across the entire phy\n",
	"PMU: Error: Failed write leveling coarse\n",
	"PMU3: DWL delay = %d\n",
	"PMU3: Errcnt for DWL nib %2d delay = %2d is %d\n",
	"PMU3: DWL nibble %d sampled a 1 at delay %d\n",
	"PMU3: DWL nibble %d passed at delay %d. Rising edge was at %d\n",
	"PMU2: DWL did nto find a rising edge of memclk for all nibbles. Failing nibbles assumed to have rising edge close to fine delay 63\n",
	"PMU2:  Rising edge found in alias window, setting wrlvlDly for nibble %d = %d\n",
	"PMU: Error: Failed DWL for nib %d with %d one\n",
	"PMU2:	Rising edge not found in alias window with %d one, leaving wrlvlDly for nibble %d = %d\n",
	"PMU: Error:Mailbox Buffer Overflowed.\n",
	"PMU: Error:Mailbox Buffer Overflowed.\n",
	"PMU: ***** Assertion Error - terminating *****\n",
	"PMU1: swapByte db %d by %d\n",
	"PMU3: get_cmd_dly max(%d ps, %d memclk) = %d\n",
	"PMU0: Write CSR 0x%06x 0x%04x\n",
	"PMU0: hwt_init_ppgc_prbs(): Polynomial: %x, Deg: %d\n",
	"PMU: Error: acsm_set_cmd to non existant instruction adddress %d\n",
	"PMU: Error: acsm_set_cmd with unknown ddr cmd 0x%x\n",
	"PMU1: acsm_addr %02x, acsm_flgs %04x, ddr_cmd %02x, cmd_dly %02x, ddr_addr %04x, ddr_bnk %02x, ddr_cs %02x, cmd_rcnt %02x, AcsmSeq0/1/2/3 %04x %04x %04x %04x\n",
	"PMU: Error: Polling on ACSM done failed to complete in acsm_poll_done()...\n",
	"PMU1: acsm RUN\n",
	"PMU1: acsm STOPPED\n",
	"PMU1: acsm_init: acsm_mode %04x mxrdlat %04x\n",
	"PMU: Error: setAcsmCLCWL: cl and cwl must be each >= 2 and 5, resp. CL=%d CWL=%d\n",
	"PMU: Error: setAcsmCLCWL: cl and cwl must be each >= 5. CL=%d CWL=%d\n",
	"PMU1: setAcsmCLCWL: CASL %04d WCASL %04d\n",
	"PMU: Error: Reserved value of register F0RC0F found in message block: 0x%04x\n",
	"PMU3: Written MRS to CS=0x%02x\n",
	"PMU3: Written MRS to CS=0x%02x\n",
	"PMU3: Entering Boot Freq Mode.\n",
	"PMU: Error: Boot clock divider setting of %d is too small\n",
	"PMU3: Exiting Boot Freq Mode.\n",
	"PMU3: Writing MR%d OP=%x\n",
	"PMU: Error: Delay too large in slomo\n",
	"PMU3: Written MRS to CS=0x%02x\n",
	"PMU3: Enable Channel A\n",
	"PMU3: Enable Channel B\n",
	"PMU3: Enable All Channels\n",
	"PMU2: Use PDA mode to set MR%d with value 0x%02x\n",
	"PMU3: Written Vref with PDA to CS=0x%02x\n",
	"PMU1: start_cal: DEBUG: setting CalRun to 1\n",
	"PMU1: start_cal: DEBUG: setting CalRun to 0\n",
	"PMU1: lock_pll_dll: DEBUG: pstate = %d\n",
	"PMU1: lock_pll_dll: DEBUG: dfifreqxlat_pstate = %d\n",
	"PMU1: lock_pll_dll: DEBUG: pllbypass = %d\n",
	"PMU3: SaveLcdlSeed: Saving seed seed %d\n",
	"PMU1: in phy_defaults()\n",
	"PMU3: ACXConf:%d MaxNumDbytes:%d NumDfi:%d\n",
	"PMU1: setAltAcsmCLCWL setting cl=%d cwl=%d\n",
}; //unsigned int pmu_train_string[]

static void get_mail_(unsigned char high);
static void decode_streaming_message(void) {
	int i = 0;
	unsigned int codede_message_hex;
	unsigned char num_args;
	unsigned int args_list[18] = {0};
	char arg_ascii[256] = {0};

	get_mail_(1);
	codede_message_hex = mail;

	if((codede_message_hex >> 16) <= 412){ //
		// Get the number of argument need to be read from mailbox
		num_args = 0xFFFF & codede_message_hex;

		if ( num_args ) {
			for(i = 0; i < num_args; i++) {
				get_mail_(1);
				#if LOG_LEVEL >= 40
				if ( num_args >= 5)
					printf("%4x ", mail);
				#endif
				args_list[i] = mail;
			}
			#if (DEBUG_DRAM == 1) && (LOG_LEVEL >= 40)
			if ( num_args == 5)
				printf("\n");
			#endif
		}

		switch (num_args)
		{
			case 0: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16]); break;
			case 1: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0]); break;
			case 2: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1]); break;
			case 3: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2]); break;
			case 4: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3]); break;
			case 5: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4]); break;
			case 6: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5]);break;
			case 7: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6]);break;
			case 8: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7]);break;
			case 9: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8]);break;
			case 10: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9]);break;
			case 11: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10]);break;
			case 12: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10],args_list[11]);break;
			case 13: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10],args_list[11],args_list[12]);break;
			case 14: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10],args_list[11],args_list[12],args_list[13]);break;
			case 15: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10],args_list[11],args_list[12],args_list[13],args_list[14]);break;
			case 16: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10],args_list[11],args_list[12],args_list[13],args_list[14],args_list[15]);break;
			case 17: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16], args_list[0], args_list[1], args_list[2], args_list[3], args_list[4], args_list[5],args_list[6],args_list[7],args_list[8],args_list[9],args_list[10],args_list[11],args_list[12],args_list[13],args_list[14],args_list[15],args_list[16]);break;
			default: snprintf(arg_ascii, sizeof(arg_ascii), pmu_train_string[codede_message_hex>> 16]); break;
		}
		
		#if (DEBUG_DRAM == 1) && (LOG_LEVEL >= 40)
		if ( num_args >= 5)
			printf("0x%08x \n", codede_message_hex);
		#endif
		if (strcmp(pmu_train_string[codede_message_hex>> 16], "PMU: Error:") == 0)
			printf(arg_ascii);

		#if (DEBUG_DRAM == 1) && (LOG_LEVEL >= 40)
		else
			printf(arg_ascii);
		#endif
	}
	else {
		ERROR("PMU Streaming Msg: Debug message not recognized !!  code: 0x%x\n", codede_message_hex);
	}
      return ;
}
#if (DEBUG_DRAM == 1)
static void decode_major_message(void) {
	    switch (mail) {
        case 0x00: INFO("PMU Major Msg: End of initialization\n                                         "); break;
        case 0x01: INFO("PMU Major Msg: End of fine write leveling\n                                    "); break;
        case 0x02: INFO("PMU Major Msg: End of read enable training\n                                   "); break;
        case 0x03: INFO("PMU Major Msg: End of read delay center optimization\n                         "); break;
        case 0x04: INFO("PMU Major Msg: End of write delay center optimization\n                        "); break;
        case 0x05: INFO("PMU Major Msg: End of 2D read delay/voltage center optimization\n              "); break;
        case 0x06: INFO("PMU Major Msg: End of 2D write delay /voltage center optimization\n            "); break;
        case 0x07: INFO("PMU Major Msg: Firmware run has completed\n                                    "); break;
        //case 0x08: INFO("PMU Major Msg: Enter streaming message mode\n                                  "); break;
        case 0x09: INFO("PMU Major Msg: End of max read latency training\n                              "); break;
        case 0x0a: INFO("PMU Major Msg: End of read dq deskew training\n                                "); break;
        case 0x0b: INFO("PMU Major Msg: End of LCDL offset calibration\n                                "); break;
        case 0x0c: INFO("PMU Major Msg: End of LRDIMM Specific training (DWL, MREP, MRD and MWD)\n      "); break;
        case 0x0d: INFO("PMU Major Msg: End of CA training\n                                            "); break;
        case 0xfd: INFO("PMU Major Msg: End of MPR read delay center optimization\n                     "); break;
        case 0xfe: INFO("PMU Major Msg: End of Write leveling coarse delay\n                            "); break;
        case 0xff: ERROR("PMU Major Msg: FATAL ERROR.\n                                                  "); break;
        //default: INFO("PMU Major Msg: Un-recognized message... !\n");
      }
      return ;
}
#endif

static void get_mail_(unsigned char high) {
    unsigned int data;
    unsigned int wd_timer2 = 0;

    mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctShadowRegs,  data);
    while((data & 1) !=0) {
      mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctShadowRegs,  data);
    }
    mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctWriteOnlyShadow,  mail);

    if(high){
	  unsigned int high_byte_data;
	  mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctDatWriteOnlyShadow,	high_byte_data);
	  mail = (high_byte_data<<16) | mail;
    }

    mww(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__DctWriteProt, 0x0000);
    mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctShadowRegs,  data);
    while((data & 1) == 0){
      mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctShadowRegs,  data);
      //ERROR("INFO: Msg read. Waiting acknowledgement from uCtl ...\n");
      // Watchdog timer to ensure no infiit looping during polling
      //INFO($time, " INFO: Watchdog timer2   = %d", wd_timer2);
      wd_timer2++;
      //if(wd_timer2 > 20) {
      //if(wd_timer2 > 1000) {
      if(wd_timer2 > 5000) {
        //INFO("TC ERROR: <%m> Watchdog timer2 overflow\n");
      }
    }
    wd_timer2 = 0;
    mww(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__DctWriteProt, 0x0001);
    
    return;
}

void dwc_ddrphy_phyinit_userCustom_G_waitFwDone(void)
{
   unsigned int i;
   unsigned int phy_data;
   unsigned int train_done;

   train_done = 0;
   for ( i = 0; i < 10; i++) asm volatile("nop\n\t");
  
   INFO(" <%m> INFO: polling DWC_DDRPHYA_APBONLY0__UctShadowRegs, bit 0...\n");
   while(train_done == 0){
     for ( i = 0; i < 500; i++) asm volatile("nop\n\t");

     mrw(DDRNSDMC_PUB_MMR_BASE + DWC_DDRPHYA_APBONLY0__UctShadowRegs, phy_data);
     if((phy_data & 1) == 0){
       get_mail_(0);
       if(mail == 0xff || mail == 0x07){
         train_done = 1;
       }
	   #if (DEBUG_DRAM == 1)
       decode_major_message();
	   #endif
       if(mail == 0x08) {
          decode_streaming_message();
       }
       else {
          //INFO("INFO: Mail Box\n");
		}
     }
   }
   if(mail == 0x07) {
    INFO("Firmware training pass.\n");
   }
   if(mail == 0xff) {
    ERROR("Error: Firmware training failed.\n");
	writel(0xEE, 0xce200004);
    asm volatile("b .\n\t");
   }
}
#endif

void ddrc_to_mhz(unsigned short frequncy) 
{
    unsigned int data;
    //volatile PMU_SMB_LPDDR4_1D_t dmem = {0};

   // Here simulate change  ddr_clk from  1.6G to 1.2G
/*
   $display("In dwc_ddrphy_phyinit_userCustom_E_setDfiClk_p1 @%0t", $time);
   force WAGNER_SIM_FUNC.Chip.Core.PLLC_Core.Core.Atom_0.Fracpllc_Core.div_fb_int_r = 60;
   #100000ns;
   $display("In dwc_ddrphy_phyinit_userCustom_E_setDfiClk_p1 2 @%0t", $time);

*/
   mwl((SYSC_SECURE_MMR_BASE + 0x0000018C), 0x001FFFFF);   //stop ddrnsdmc clk

   mrl((PLLC_MMR_BASE + 0x0000000c), data);
   mwl((PLLC_MMR_BASE+ 0x0000000c), ( (data&0xF000FFFF) | (((frequncy / 10 / 2) & 0xFFF) << 16) ));  // update pll freq
   //mwl((PLLC_MMR_BASE+ 0x0000000c), ( (data&0xF000FFFF) | 0x280000));  // update 0.8G
   //mwl((PLLC_MMR_BASE+ 0x0000000c), ( (data&0xF000FFFF) | 0x3C0000));  // update 1.2G
   //mwl((PLLC_MMR_BASE+ 0x0000000c), ( (data&0xF000FFFF) | 0x500000));  // update 1.6G
   mrl((PLLC_MMR_BASE + 0x00000004), data);
   mwl((PLLC_MMR_BASE+ 0x00000004), (data | 0x1));   // update configuration

   mrl((PLLC_MMR_BASE + 0x00000004), data);
   while ((data&0x00000001)!=0x00000000)
   {
       mrl((PLLC_MMR_BASE+0x00000004), data);
   }

   mrl((PLLC_MMR_BASE + 0x00000008), data);
   while ((data&0x00000003)!=0x00000003)
   {
       mrl((PLLC_MMR_BASE+0x00000008), data);
   }
   mwl((SYSC_SECURE_MMR_BASE+0x00000188), 0x001FFFFF);   // enable ddrnsdmc clk
}

void dwc_ddrphy_phyinit_userCustom_E_setDfiClk(unsigned char pstate) 
{
	if ( pstate == 0) {
		#if defined(DEBUG_800_MHZ) || (DRAM_BUSCLK == 800)
		ddrc_to_mhz(800);
		#else
		ddrc_to_mhz(DRAM_BUSCLK);
		#endif
	} else {
		ddrc_to_mhz(1200);
	}
	return;
}

void phy_init(void) {

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1005f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1005f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1015f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1015f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1105f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1105f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1115f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1115f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1205f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1205f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1215f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1215f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1305f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1305f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1315f,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1315f);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11005f,16'h1ff,1); // DWC_DDRPHYA_DBYTE0_p1_TxSlewRate_b0_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11005f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11015f,16'h1ff,1); // DWC_DDRPHYA_DBYTE0_p1_TxSlewRate_b1_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11015f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11105f,16'h1ff,1); // DWC_DDRPHYA_DBYTE1_p1_TxSlewRate_b0_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11105f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11115f,16'h1ff,1); // DWC_DDRPHYA_DBYTE1_p1_TxSlewRate_b1_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11115f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11205f,16'h1ff,1); // DWC_DDRPHYA_DBYTE2_p1_TxSlewRate_b0_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11205f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11215f,16'h1ff,1); // DWC_DDRPHYA_DBYTE2_p1_TxSlewRate_b1_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11215f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11305f,16'h1ff,1); // DWC_DDRPHYA_DBYTE3_p1_TxSlewRate_b0_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11305f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11315f,16'h1ff,1); // DWC_DDRPHYA_DBYTE3_p1_TxSlewRate_b1_p1
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11315f);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h55,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x55);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1055,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1055);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2055,16'h1ff,1);
	writew(0x1ff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2055);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200c5,16'h19,1);
	writew(0x19, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200c5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1200c5,16'ha,1); // DWC_DDRPHYA_MASTER0_p1_PllCtrl2_p1
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1200c5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2002e,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2002e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12002e,16'h2,1); // DWC_DDRPHYA_MASTER0_p1_ARdPtrInitVal_p1
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12002e);
#else
	writew(0xb, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200c5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2002e,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2002e);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90204,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90204);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h190204,16'h0,1); // DWC_DDRPHYA_INITENG0_p1_Seq0BGPR4_p1
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x190204);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20024,16'he3,1);
	writew(0xe3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20024);
	// writew(0x1e3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20024);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2003a,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2003a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2007d,16'h212,1);
	writew(0x212, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2007d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2007c,16'h61,1);
	writew(0x61, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2007c);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120024,16'he3,1); // DWC_DDRPHYA_MASTER0_p1_DqsPreambleControl_p1
	writew(0xe3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120024);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2003a,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2003a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12007d,16'h212,1); // DWC_DDRPHYA_MASTER0_p1_DllLockParam_p1
	writew(0x212, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12007d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12007c,16'h61,1); // DWC_DDRPHYA_MASTER0_p1_DllGainCtl_p1
	writew(0x61, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12007c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20056,16'h3,1);
	writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20056);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120056,16'h2,1); // DWC_DDRPHYA_MASTER0_p1_ProcOdtTimeCtl_p1
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120056);
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20056,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20056);
	// writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20056);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1004d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1004d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1014d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1014d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1104d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1104d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1114d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1114d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1204d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1204d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1214d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1214d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1304d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1304d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1314d,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1314d);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11004d,16'h600,1); // DWC_DDRPHYA_DBYTE0_p1_TxOdtDrvStren_b0_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11004d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11014d,16'h600,1); // DWC_DDRPHYA_DBYTE0_p1_TxOdtDrvStren_b1_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11014d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11104d,16'h600,1); // DWC_DDRPHYA_DBYTE1_p1_TxOdtDrvStren_b0_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11104d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11114d,16'h600,1); // DWC_DDRPHYA_DBYTE1_p1_TxOdtDrvStren_b1_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11114d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11204d,16'h600,1); // DWC_DDRPHYA_DBYTE2_p1_TxOdtDrvStren_b0_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11204d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11214d,16'h600,1); // DWC_DDRPHYA_DBYTE2_p1_TxOdtDrvStren_b1_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11214d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11304d,16'h600,1); // DWC_DDRPHYA_DBYTE3_p1_TxOdtDrvStren_b0_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11304d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11314d,16'h600,1); // DWC_DDRPHYA_DBYTE3_p1_TxOdtDrvStren_b1_p1
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11314d);
#endif
	char DrvStrenFSDq[] = {0, 1, 2, 3, 8, 9, 10, 11, 0x18, 0x19, 0x1A, 0x1B, 0x38, 0x39, 0x3A, 0x3B, 0x3E, 0x3F};

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10049,16'h618,1);
	//writew((DRVSTRENFSDQ(480 / SOC_DQ_DRV) << 6), DDRNSDMC_PUB_MMR_BASE + 2 * 0x10049);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x10049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10149,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x10149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11049,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x11049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11149,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x11149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12049,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x12049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12149,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x12149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13049,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x13049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13149,16'h618,1);
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x13149);

#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h110049,16'h618,1); // DWC_DDRPHYA_DBYTE0_p1_TxImpedanceCtrl1_b0_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x110049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h110149,16'h618,1); // DWC_DDRPHYA_DBYTE0_p1_TxImpedanceCtrl1_b1_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x110149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h111049,16'h618,1); // DWC_DDRPHYA_DBYTE1_p1_TxImpedanceCtrl1_b0_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x111049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h111149,16'h618,1); // DWC_DDRPHYA_DBYTE1_p1_TxImpedanceCtrl1_b1_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x111149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h112049,16'h618,1); // DWC_DDRPHYA_DBYTE2_p1_TxImpedanceCtrl1_b0_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x112049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h112149,16'h618,1); // DWC_DDRPHYA_DBYTE2_p1_TxImpedanceCtrl1_b1_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x112149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h113049,16'h618,1); // DWC_DDRPHYA_DBYTE3_p1_TxImpedanceCtrl1_b0_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x113049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h113149,16'h618,1); // DWC_DDRPHYA_DBYTE3_p1_TxImpedanceCtrl1_b1_p1
	writew((DrvStrenFSDq[480 / SOC_DQ_DRV] << 6) | DrvStrenFSDq[480 / SOC_DQ_DRV], DDRNSDMC_PUB_MMR_BASE + 2 * 0x113149);
#endif

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h43,16'h3ff,1);
	writew(((((1 << (120 / SOC_CA_DRV)) - 1) - 1) << 5 ) | (((1 << (120 / SOC_CA_DRV)) - 1) - 1), DDRNSDMC_PUB_MMR_BASE + 2 * 0x43);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1043,16'h3ff,1);
	writew(((((1 << (120 / SOC_CA_DRV)) - 1) - 1) << 5 ) | (((1 << (120 / SOC_CA_DRV)) - 1) - 1), DDRNSDMC_PUB_MMR_BASE + 2 * 0x1043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2043,16'h3ff,1);
	writew(((((1 << (120 / SOC_CA_DRV)) - 1) - 1) << 5 ) | (((1 << (120 / SOC_CA_DRV)) - 1) - 1), DDRNSDMC_PUB_MMR_BASE + 2 * 0x2043);
	
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20018,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20075,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20075);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20050,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20050);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20008,16'h320,1);
	writew(0x384, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20008);	// 1866
	// writew(0x320, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20008);	// 1600
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120008,16'h258,1); // DWC_DDRPHYA_MASTER0_p1_CalUclkInfo_p1
	writew(0x258, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120008);
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20008,16'h320,1);
	writew(0x190, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20008);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20088,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20088);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200b2,16'h104,1);
	writew(0x104, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200b2);
	// writew(0x003, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10043,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10143,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11043,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11143,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12043,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12143,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13043,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13143,16'h5a1,1);
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13143);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1200b2,16'h104,1); // DWC_DDRPHYA_MASTER0_p1_VrefInGlobal_p1
	writew(0x104, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1200b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h110043,16'h5a1,1); // DWC_DDRPHYA_DBYTE0_p1_DqDqsRcvCntrl_b0_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x110043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h110143,16'h5a1,1); // DWC_DDRPHYA_DBYTE0_p1_DqDqsRcvCntrl_b1_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x110143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h111043,16'h5a1,1); // DWC_DDRPHYA_DBYTE1_p1_DqDqsRcvCntrl_b0_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x111043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h111143,16'h5a1,1); // DWC_DDRPHYA_DBYTE1_p1_DqDqsRcvCntrl_b1_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x111143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h112043,16'h5a1,1); // DWC_DDRPHYA_DBYTE2_p1_DqDqsRcvCntrl_b0_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x112043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h112143,16'h5a1,1); // DWC_DDRPHYA_DBYTE2_p1_DqDqsRcvCntrl_b1_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x112143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h113043,16'h5a1,1); // DWC_DDRPHYA_DBYTE3_p1_DqDqsRcvCntrl_b0_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x113043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h113143,16'h5a1,1); // DWC_DDRPHYA_DBYTE3_p1_DqDqsRcvCntrl_b1_p1
	writew(0x5a1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x113143);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200fa,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200fa);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1200fa,16'h1,1); // DWC_DDRPHYA_MASTER0_p1_DfiFreqRatio_p1
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1200fa);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20019,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20019);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120019,16'h1,1); // DWC_DDRPHYA_MASTER0_p1_TristateModeCA_p1
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120019);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f0,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f1,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f2,16'h4444,1);
	writew(0x4444, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f3,16'h8888,1);
	writew(0x8888, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f4,16'h5555,1);
	writew(0x5555, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f5,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f6,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200f7,16'hf000,1);
	writew(0xf000, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200f7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1004a,16'h500,1);
	writew(0x500, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1004a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1104a,16'h500,1);
	writew(0x500, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1104a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1204a,16'h500,1);
	writew(0x500, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1204a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h1304a,16'h500,1);
	writew(0x500, DDRNSDMC_PUB_MMR_BASE + 2 * 0x1304a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20025,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20025);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2002d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2002d);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12002d,16'h0,1); // DWC_DDRPHYA_MASTER0_p1_DMIPinPresent_p1
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12002d);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2002c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2002c);

#ifdef EN_TRAIN
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20060,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20060);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);

	/*load firmware here*/
	INFO("Start load phy fw....\n");
	dmac_copy_ddrphy_fw();
	INFO("done.\n");
	
#ifdef TRAIN_1ST_FREQ

#ifdef CHECK_DDR_RESET_TIME
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54000);
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54000,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54000);
#endif

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54001,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54001);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54002,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54002);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54003,16'hc80,1);
	writew(0xe10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54003);		// 
	// writew(0xc80, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54003); // 1600
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54003,16'hc80,1);
	writew(0x640, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54003);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54004,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54004);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54005,16'h0,1);
	writew(0x0000, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54005);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54006,16'h14,1);
	writew(0x14, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54006);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54007,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54007);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54008,16'h131f,1);
	writew(0x1001, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54008);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54009,16'hff,1);
	writew(0x04, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54009);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400b,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400f,16'h100,1);
	writew(0x100, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54010,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54010);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54011,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54012,16'h120,1);
	writew(0x120, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54013,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54014,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54014);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54015,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54015);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54016,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54016);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54017,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54017);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54018,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54018);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54019,16'h2d54,1);
	writew(0x3664, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54019);	// 1866
	// writew(0x2d54, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54019);	// 1600
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54019,16'h2d54,1);
	writew(0x1224, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54019);	// 800
	// writew(0x1b34, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54019);	// 1066
#endif
#ifdef MR_ODT_DRV
	writew(0x23, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401a);		// 60
	//dmem.MR11_A0 = (((240 / SOC_CA_ODT) << 4) | ((240 / DRAM_CA_ODT) << 0));
	//((dmem.MR12_A0 << 8) | dmem.MR11_A0 );
	writew(0x1400 | (((240 / DRAM_CA_ODT) << 4) | ((240 / DRAM_DQ_ODT) << 0)), DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401b);	// [11:8] -> 0x14, ~[5]
	//((dmem.MR14_A0 << 8) | dmem.MR13_A0 );
	writew(0x1928, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401c);	// [11:8] -> 0x19
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401a,16'h33,1);
	writew(0x33, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401a);		// 40
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401b,16'h4d64,1);
	writew(0x4d64, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401b);	// CA 40, DQ 60
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401c,16'h4f28,1);
	writew(0x4f28, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401c);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401e,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401e);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401f,16'h2d54,1);
	writew(0x3664, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401f); //
	// writew(0x2d54, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401f); // 1600
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401f,16'h2d54,1);
	writew(0x1224, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401f);
#endif
#ifdef MR_ODT_DRV
	writew(0x23, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54020);		// ~[4]
	writew(0x1400 | (((240 / DRAM_CA_ODT) << 4) | ((240 / DRAM_DQ_ODT) << 0)), DDRNSDMC_PUB_MMR_BASE + 2 * 0x54021);	// [11:8] -> 0x14, ~[5]
	writew(0x1928, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54022);	// [11:8] -> 0x19
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54020,16'h33,1);
	writew(0x33, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54020);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54021,16'h4d64,1);
	writew(0x4d64, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54021);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54022,16'h4f28,1);
	writew(0x4f28, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54022);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54023,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54023);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54024,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54024);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54025,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54025);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54026,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54026);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54027,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54027);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54028,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54028);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54029,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54029);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402b,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54030,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54030);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54031,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54031);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54032,16'h5400,1);
	writew(0x6400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54032);
	// writew(0x5400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54032); // 6400
	#ifdef MR_ODT_DRV
	writew(0x2336, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54033);	//
	// writew(0x232d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54033);	// ~[12]
	#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54033,16'h332d,1);
	writew(0x332d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54033);
	#endif
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54032,16'h5400,1);
	writew(0x2400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54032);
	#ifdef MR_ODT_DRV
	writew(0x2312, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54033);	// ~[12]
	#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54033,16'h332d,1);
	writew(0x3312, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54033);
	#endif
#endif
#ifdef MR_ODT_DRV
	writew(0x0000 | (((240 / DRAM_CA_ODT) << 12) | ((240 / DRAM_DQ_ODT) << 8)), DDRNSDMC_PUB_MMR_BASE + 2 * 0x54034);	// ~[13]
	writew(0x2814, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54035);	// [7:0] -> 0x14
	writew(0x19, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54036);		// [7:0] -> 0x19
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54034,16'h6400,1);
	writew(0x6400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54034);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54035,16'h284d,1);
	writew(0x284d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54035);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54036,16'h4f,1);
	writew(0x4f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54036);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54037,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54037);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54038,16'h5400,1);
	writew(0x5400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54038);
	#ifdef MR_ODT_DRV
	writew(0x2336, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54039);	// ~[12]
	// writew(0x232d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54039);	// ~[12]
	#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54039,16'h332d,1);
	writew(0x332d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54039);
	#endif
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54038,16'h5400,1);
	writew(0x2400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54038);
	#ifdef MR_ODT_DRV
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54039,16'h332d,1);
	writew(0x2312, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54039);	// ~[12]
	#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54039,16'h332d,1);
	writew(0x3312, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54039);
	#endif
#endif
#ifdef MR_ODT_DRV
	writew(0x0000 | (((240 / DRAM_CA_ODT) << 12) | ((240 / DRAM_DQ_ODT) << 8)), DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403a);	// ~[13]
	writew(0x2814, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403b);	// [7:0] -> 0x14
	writew(0x19, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403c);		// [7:0] -> 0x19
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403a,16'h6400,1);
	writew(0x6400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403b,16'h284d,1);
	writew(0x284d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403c,16'h4f,1);
	writew(0x4f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403c);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403d,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403f);
	
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	// (G) Execute the Training Firmware 
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);

	dwc_ddrphy_phyinit_userCustom_G_waitFwDone();

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	
	// (H) Read the Message Block results
	// H_readMsgBlock();

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
#endif

	INFO("1st train done\n");

#ifdef TRAIN_2ND_FREQ
	// Step (E) Set the PHY input clocks to the desired frequency for pstate 1
	ddrc_to_mhz(1200);
	
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);

#ifdef CHECK_DDR_RESET_TIME
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54000);
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54000,16'h600,1);
	writew(0x600, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54000);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54001,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54001);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54002,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54003,16'h960,1);
	writew(0x960, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54003);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54004,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54004);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54005,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54005);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54006,16'h14,1);
	writew(0x14, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54006);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54007,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54007);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54008,16'h121f,1);
	writew(0x121f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54008);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54009,16'hff,1);
	writew(0xff, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54009);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400b,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5400f,16'h100,1);
	writew(0x100, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5400f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54010,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54010);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54011,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54012,16'h120,1);
	writew(0x120, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54013,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54014,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54014);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54015,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54015);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54016,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54016);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54017,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54017);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54018,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54019,16'h2444,1);
	writew(0x2444, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54019);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401a,16'h33,1);
	writew(0x33, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401b,16'h4d64,1);
	writew(0x4d64, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401c,16'h4f28,1);
	writew(0x4f28, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401e,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5401f,16'h2444,1);
	writew(0x2444, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5401f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54020,16'h33,1);
	writew(0x33, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54020);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54021,16'h4d64,1);
	writew(0x4d64, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54021);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54022,16'h4f28,1);
	writew(0x4f28, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54022);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54023,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54023);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54024,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54024);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54025,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54025);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54026,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54026);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54027,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54027);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54028,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54028);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54029,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54029);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402b,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5402f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5402f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54030,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54030);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54031,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54031);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54032,16'h4400,1);
	writew(0x4400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54032);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54033,16'h3324,1);
	writew(0x3324, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54033);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54034,16'h6400,1);
	writew(0x6400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54034);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54035,16'h284d,1);
	writew(0x284d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54035);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54036,16'h4f,1);
	writew(0x4f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54036);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54037,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54037);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54038,16'h4400,1);
	writew(0x4400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54038);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h54039,16'h3324,1);
	writew(0x3324, DDRNSDMC_PUB_MMR_BASE + 2 * 0x54039);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403a,16'h6400,1);
	writew(0x6400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403b,16'h284d,1);
	writew(0x284d, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403c,16'h4f,1);
	writew(0x4f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403d,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h5403f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x5403f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);

	dwc_ddrphy_phyinit_userCustom_G_waitFwDone();

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0099,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0099);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	
	// (H) Read the Message Block results
	// H_readMsgBlock();

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
#endif //TRAIN_2ND_FREQ

	INFO("2nd train down\n");
#else // !EN_TRAIN
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Start of dwc_ddrphy_phyinit_progCsrSkipTrain()
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] NumRank_total = 1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] PHY_Rx_Fifo_Dly = 1450
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] PHY_Tx_Insertion_Dly = 200
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] PHY_Rx_Insertion_Dly = 200
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DFIMRL to 0x6
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming HwtMRL to 0x6
#ifndef DEBUG_800_MHZ
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x10020,0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x11020,0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12020,0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x13020,0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x20020,0x6);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] PHY_Rx_Fifo_Dly = 1866
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] PHY_Tx_Insertion_Dly = 200
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] PHY_Rx_Insertion_Dly = 200
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming DFIMRL to 0x5
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming HwtMRL to 0x5
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110020,0x5); // DWC_DDRPHYA_DBYTE0_p1_DFIMRL_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x111020,0x5); // DWC_DDRPHYA_DBYTE1_p1_DFIMRL_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x112020,0x5); // DWC_DDRPHYA_DBYTE2_p1_DFIMRL_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x113020,0x5); // DWC_DDRPHYA_DBYTE3_p1_DFIMRL_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120020,0x5); // DWC_DDRPHYA_MASTER0_p1_HwtMRL_p1
#else
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x10020,0x5);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x11020,0x5);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12020,0x5);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x13020,0x5);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x20020,0x5);
#endif
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming TxDqsDlyTg0 to 0x100
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x100d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x101d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x111d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x121d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x130d0,0x100);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x131d0,0x100);
#ifndef DEBUG_800_MHZ
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming TxDqsDlyTg0 to 0x100
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1100d0,0x100); // DWC_DDRPHYA_DBYTE0_p1_TxDqsDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1101d0,0x100); // DWC_DDRPHYA_DBYTE0_p1_TxDqsDlyTg0_u1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1110d0,0x100); // DWC_DDRPHYA_DBYTE1_p1_TxDqsDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1111d0,0x100); // DWC_DDRPHYA_DBYTE1_p1_TxDqsDlyTg0_u1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1120d0,0x100); // DWC_DDRPHYA_DBYTE2_p1_TxDqsDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1121d0,0x100); // DWC_DDRPHYA_DBYTE2_p1_TxDqsDlyTg0_u1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1130d0,0x100); // DWC_DDRPHYA_DBYTE3_p1_TxDqsDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1131d0,0x100); // DWC_DDRPHYA_DBYTE3_p1_TxDqsDlyTg0_u1_p1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming TxDqDlyTg0 to 0x45
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x100c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x101c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x102c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x103c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x104c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x105c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x106c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x107c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x108c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x111c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x112c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x113c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x114c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x115c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x116c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x117c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x118c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x121c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x122c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x123c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x124c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x125c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x126c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x127c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x128c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x130c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x131c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x132c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x133c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x134c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x135c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x136c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x137c0,0x45);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x138c0,0x45);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming TxDqDlyTg0 to 0x40
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1100c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1101c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1102c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r2_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1103c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r3_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1104c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r4_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1105c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r5_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1106c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r6_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1107c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r7_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1108c0,0x40); // DWC_DDRPHYA_DBYTE0_p1_TxDqDlyTg0_r8_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1110c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1111c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1112c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r2_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1113c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r3_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1114c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r4_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1115c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r5_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1116c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r6_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1117c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r7_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1118c0,0x40); // DWC_DDRPHYA_DBYTE1_p1_TxDqDlyTg0_r8_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1120c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1121c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1122c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r2_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1123c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r3_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1124c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r4_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1125c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r5_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1126c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r6_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1127c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r7_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1128c0,0x40); // DWC_DDRPHYA_DBYTE2_p1_TxDqDlyTg0_r8_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1130c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1131c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1132c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r2_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1133c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r3_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1134c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r4_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1135c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r5_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1136c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r6_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1137c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r7_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1138c0,0x40); // DWC_DDRPHYA_DBYTE3_p1_TxDqDlyTg0_r8_p1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming RxEnDly_10to6=9, Rxendly_5to0=17
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming RxEnDlyTg0 to 0x251
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x10080,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x10180,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x11080,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x11180,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12080,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12180,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x13080,0x251);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x13180,0x251);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming RxEnDly_10to6=8, Rxendly_5to0=11
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming RxEnDlyTg0 to 0x20b
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110080,0x20b); // DWC_DDRPHYA_DBYTE0_p1_RxEnDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110180,0x20b); // DWC_DDRPHYA_DBYTE0_p1_RxEnDlyTg0_u1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x111080,0x20b); // DWC_DDRPHYA_DBYTE1_p1_RxEnDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x111180,0x20b); // DWC_DDRPHYA_DBYTE1_p1_RxEnDlyTg0_u1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x112080,0x20b); // DWC_DDRPHYA_DBYTE2_p1_RxEnDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x112180,0x20b); // DWC_DDRPHYA_DBYTE2_p1_RxEnDlyTg0_u1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x113080,0x20b); // DWC_DDRPHYA_DBYTE3_p1_RxEnDlyTg0_u0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x113180,0x20b); // DWC_DDRPHYA_DBYTE3_p1_RxEnDlyTg0_u1_p1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Programming PIE RL=28 WL=14
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90201,0x1a00);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90202,0xc);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90203,0x2600);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Programming PIE RL=24 WL=12
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x190201,0x1600); // DWC_DDRPHYA_INITENG0_p1_Seq0BGPR1_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x190202,0xa); // DWC_DDRPHYA_INITENG0_p1_Seq0BGPR2_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x190203,0x2200); // DWC_DDRPHYA_INITENG0_p1_Seq0BGPR3_p1
#else
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming TxDqDlyTg0 to 0x45
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x100c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x101c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x102c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x103c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x104c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x105c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x106c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x107c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x108c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x111c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x112c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x113c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x114c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x115c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x116c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x117c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x118c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x121c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x122c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x123c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x124c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x125c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x126c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x127c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x128c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x130c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x131c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x132c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x133c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x134c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x135c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x136c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x137c0,0x1b);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x138c0,0x1b);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming RxEnDly_10to6=9, Rxendly_5to0=17
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming RxEnDlyTg0 to 0x251
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x10080,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x10180,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x11080,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x11180,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12080,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12180,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x13080,0x1c4);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x13180,0x1c4);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Programming PIE RL=28 WL=14
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90201,0xc00);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90202,0x6);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90203,0x1800);
#endif
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming HwtLpCsEnA to 0x1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x20072,0x1);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming HwtLpCsEnB to 0x0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x20073,0x0);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming PptDqsCntInvTrnTg0 to 0x15
#ifndef DEBUG_800_MHZ
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x100ae,0x15);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110ae,0x15);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120ae,0x15);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x130ae,0x15);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming PptDqsCntInvTrnTg0 to 0x10
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1100ae,0x10); // DWC_DDRPHYA_DBYTE0_p1_PptDqsCntInvTrnTg0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1110ae,0x10); // DWC_DDRPHYA_DBYTE1_p1_PptDqsCntInvTrnTg0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1120ae,0x10); // DWC_DDRPHYA_DBYTE2_p1_PptDqsCntInvTrnTg0_p1
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x1130ae,0x10); // DWC_DDRPHYA_DBYTE3_p1_PptDqsCntInvTrnTg0_p1
#else
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x100ae,0xb);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110ae,0xb);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120ae,0xb);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x130ae,0xb);
#endif
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming PptCtlStatic CSR
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x100aa,0x501);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x110aa,0x50d);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x120aa,0x501);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x130aa,0x50d);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming HwtCAMode to 0x34
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x20077,0x34);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DllGainCtl::DllGainIV=0x4, DllGainTV=0x5
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DllGainCtl to 0x54
#ifndef DEBUG_800_MHZ
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x2007c,0x54);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DllLockParam::LcdlSeed0 to 63 
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DllLockParam to 0x3f2
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x2007d,0x3f2);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming DllGainCtl::DllGainIV=0x4, DllGainTV=0x5
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming DllGainCtl to 0x54
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12007c,0x54); // DWC_DDRPHYA_MASTER0_p1_DllGainCtl_p1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming DllLockParam::LcdlSeed0 to 84 
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=1, Memclk=1200MHz, Programming DllLockParam to 0x542
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x12007d,0x542); // DWC_DDRPHYA_MASTER0_p1_DllLockParam_p1
#else
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x2007c,0x53);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DllLockParam::LcdlSeed0 to 63 
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Pstate=0, Memclk=1600MHz, Programming DllLockParam to 0x3f2
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x2007d,0x7e2);
#endif
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming AcsmCtrl23 to 0x10f
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x400c0,0x10f);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllDacValIn to 0x10
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllForceCal to 0x1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllEnCal to 0x1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllMaxRange to 0x1f
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming PllCtrl3 to 0x21f0
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6 to 0xe1f0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x200cb,0x21f0);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90206,0xe1f0);
#ifndef DEBUG_800_MHZ
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllDacValIn to 0x11
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllForceCal to 0x1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllEnCal to 0x1
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6/PllCtrl3::PllMaxRange to 0x1f
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming PllCtrl3 to 0x23f0
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Programming GPR6 to 0xe3f0
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x200cb,0x23f0);
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x190206,0xe3f0); // DWC_DDRPHYA_INITENG0_p1_Seq0BGPR6_p1
#endif
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] Special skipTraining configuration to Prevernt DRAM Commands on the first dfi status interface handshake.
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] In order to see this behavior, the frist dfi_freq should be in the range of 0x0f < dfi_freq_sel[4:0] < 0x14.
	mww(DDRNSDMC_PUB_MMR_BASE + 2 * 0x90028,0x0);
	// [dwc_ddrphy_phyinit_progCsrSkipTrain] End of dwc_ddrphy_phyinit_progCsrSkipTrain()
#endif //!EN_TRAIN

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90000,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90001,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90001);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90002,16'h10e,1);
	writew(0x10e, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90003,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90003);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90004,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90004);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90005,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90005);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90029,16'hb,1);
	writew(0xb, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90029);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9002a,16'h480,1);
	writew(0x480, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9002a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9002b,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9002b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9002c,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9002c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9002d,16'h448,1);
	writew(0x448, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9002d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9002e,16'h139,1);
	writew(0x139, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9002e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9002f,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9002f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90030,16'h478,1);
	writew(0x478, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90030);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90031,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90031);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90032,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90032);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90033,16'he8,1);
	writew(0xe8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90033);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90034,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90034);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90035,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90035);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90036,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90036);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90037,16'h139,1);
	writew(0x139, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90037);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90038,16'hb,1);
	writew(0xb, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90038);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90039,16'h7c0,1);
	writew(0x7c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90039);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9003a,16'h139,1);
	writew(0x139, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9003a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9003b,16'h44,1);
	writew(0x44, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9003b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9003c,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9003c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9003d,16'h159,1);
	writew(0x159, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9003d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9003e,16'h14f,1);
	writew(0x14f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9003e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9003f,16'h630,1);
	writew(0x630, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9003f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90040,16'h159,1);
	writew(0x159, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90040);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90041,16'h47,1);
	writew(0x47, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90041);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90042,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90042);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90043,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90044,16'h4f,1);
	writew(0x4f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90044);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90045,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90045);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90046,16'h179,1);
	writew(0x179, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90046);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90047,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90047);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90048,16'he0,1);
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90048);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90049,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9004a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9004a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9004b,16'h7c8,1);
	writew(0x7c8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9004b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9004c,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9004c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9004d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9004d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9004e,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9004e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9004f,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9004f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90050,16'h30,1);
	writew(0x30, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90050);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90051,16'h65a,1);
	writew(0x65a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90051);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90052,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90052);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90053,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90053);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90054,16'h45a,1);
	writew(0x45a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90054);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90055,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90055);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90056,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90056);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90057,16'h448,1);
	writew(0x448, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90057);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90058,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90058);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90059,16'h40,1);
	writew(0x40, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90059);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9005a,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9005a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9005b,16'h179,1);
	writew(0x179, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9005b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9005c,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9005c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9005d,16'h618,1);
	writew(0x618, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9005d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9005e,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9005e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9005f,16'h40c0,1);
	writew(0x40c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9005f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90060,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90060);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90061,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90061);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90062,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90062);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90063,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90063);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90064,16'h48,1);
	writew(0x48, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90064);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90065,16'h4040,1);
	writew(0x4040, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90065);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90066,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90066);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90067,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90067);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90068,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90068);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90069,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90069);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9006a,16'h48,1);
	writew(0x48, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9006a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9006b,16'h40,1);
	writew(0x40, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9006b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9006c,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9006c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9006d,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9006d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9006e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9006e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9006f,16'h658,1);
	writew(0x658, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9006f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90070,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90070);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90071,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90071);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90072,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90072);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90073,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90073);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90074,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90074);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90075,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90075);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90076,16'h78,1);
	writew(0x78, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90076);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90077,16'h549,1);
	writew(0x549, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90077);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90078,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90078);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90079,16'h159,1);
	writew(0x159, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90079);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9007a,16'hd49,1);
	writew(0xd49, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9007a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9007b,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9007b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9007c,16'h159,1);
	writew(0x159, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9007c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9007d,16'h94a,1);
	writew(0x94a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9007d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9007e,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9007e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9007f,16'h159,1);
	writew(0x159, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9007f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90080,16'h441,1);
	writew(0x441, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90080);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90081,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90081);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90082,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90082);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90083,16'h42,1);
	writew(0x42, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90083);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90084,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90084);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90085,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90085);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90086,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90086);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90087,16'h633,1);
	writew(0x633, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90087);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90088,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90088);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90089,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90089);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9008a,16'he0,1);
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9008a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9008b,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9008b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9008c,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9008c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9008d,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9008d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9008e,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9008e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9008f,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9008f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90090,16'h3c0,1);
	writew(0x3c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90090);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90091,16'h149,1);
	writew(0x149, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90091);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90092,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90092);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90093,16'h3c0,1);
	writew(0x3c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90093);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90094,16'h159,1);
	writew(0x159, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90094);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90095,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90095);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90096,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90096);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90097,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90097);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90098,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90098);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90099,16'h3c0,1);
	writew(0x3c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90099);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9009a,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9009a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9009b,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9009b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9009c,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9009c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9009d,16'h48,1);
	writew(0x48, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9009d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9009e,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9009e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9009f,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9009f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a0,16'h58,1);
	writew(0x58, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a1,16'hb,1);
	writew(0xb, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a2,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a3,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a5,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a6,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a7,16'h5,1);
	writew(0x5, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a8,16'h7c0,1);
	writew(0x7c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a8);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900a9,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900a9);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40000,16'h811,1);
	writew(0x811, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40020,16'h880,1);
	writew(0x880, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40020);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40040,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40040);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40060,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40060);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40001,16'h4008,1);
	writew(0x4008, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40001);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40021,16'h83,1);
	writew(0x83, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40021);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40041,16'h4f,1);
	writew(0x4f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40041);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40061,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40061);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40002,16'h4040,1);
	writew(0x4040, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40022,16'h83,1);
	writew(0x83, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40022);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40042,16'h51,1);
	writew(0x51, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40042);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40062,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40062);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40003,16'h811,1);
	writew(0x811, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40003);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40023,16'h880,1);
	writew(0x880, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40023);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40043,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40043);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40063,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40063);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40004,16'h720,1);
	writew(0x720, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40004);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40024,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40024);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40044,16'h1740,1);
	writew(0x1740, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40044);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40064,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40064);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40005,16'h16,1);
	writew(0x16, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40005);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40025,16'h83,1);
	writew(0x83, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40025);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40045,16'h4b,1);
	writew(0x4b, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40045);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40065,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40065);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40006,16'h716,1);
	writew(0x716, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40006);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40026,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40026);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40046,16'h2001,1);
	writew(0x2001, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40046);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40066,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40066);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40007,16'h716,1);
	writew(0x716, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40007);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40027,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40027);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40047,16'h2800,1);
	writew(0x2800, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40047);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40067,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40067);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40008,16'h716,1);
	writew(0x716, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40008);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40028,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40028);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40048,16'hf00,1);
	writew(0xf00, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40048);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40068,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40068);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40009,16'h720,1);
	writew(0x720, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40009);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40029,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40029);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40049,16'h1400,1);
	writew(0x1400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40049);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40069,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40069);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4000a,16'he08,1);
	writew(0xe08, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4000a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4002a,16'hc15,1);
	writew(0xc15, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4002a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4004a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4004a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4006a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4006a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4000b,16'h625,1);
	writew(0x625, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4000b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4002b,16'h15,1);
	writew(0x15, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4002b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4004b,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4004b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4006b,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4006b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4000c,16'h4028,1);
	writew(0x4028, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4000c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4002c,16'h80,1);
	writew(0x80, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4002c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4004c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4004c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4006c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4006c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4000d,16'he08,1);
	writew(0xe08, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4000d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4002d,16'hc1a,1);
	writew(0xc1a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4002d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4004d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4004d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4006d,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4006d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4000e,16'h625,1);
	writew(0x625, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4000e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4002e,16'h1a,1);
	writew(0x1a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4002e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4004e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4004e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4006e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4006e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4000f,16'h4040,1);
	writew(0x4040, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4000f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4002f,16'h80,1);
	writew(0x80, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4002f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4004f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4004f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4006f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4006f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40010,16'h2604,1);
	writew(0x2604, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40010);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40030,16'h15,1);
	writew(0x15, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40030);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40050,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40050);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40070,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40070);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40011,16'h708,1);
	writew(0x708, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40031,16'h5,1);
	writew(0x5, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40031);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40051,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40051);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40071,16'h2002,1);
	writew(0x2002, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40071);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40012,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40032,16'h80,1);
	writew(0x80, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40032);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40052,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40052);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40072,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40072);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40013,16'h2604,1);
	writew(0x2604, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40033,16'h1a,1);
	writew(0x1a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40033);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40053,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40053);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40073,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40073);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40014,16'h708,1);
	writew(0x708, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40014);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40034,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40034);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40054,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40054);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40074,16'h2002,1);
	writew(0x2002, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40074);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40015,16'h4040,1);
	writew(0x4040, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40015);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40035,16'h80,1);
	writew(0x80, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40035);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40055,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40055);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40075,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40075);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40016,16'h60a,1);
	writew(0x60a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40016);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40036,16'h15,1);
	writew(0x15, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40036);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40056,16'h1200,1);
	writew(0x1200, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40056);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40076,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40076);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40017,16'h61a,1);
	writew(0x61a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40017);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40037,16'h15,1);
	writew(0x15, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40037);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40057,16'h1300,1);
	writew(0x1300, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40057);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40077,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40077);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40018,16'h60a,1);
	writew(0x60a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40038,16'h1a,1);
	writew(0x1a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40038);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40058,16'h1200,1);
	writew(0x1200, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40058);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40078,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40078);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40019,16'h642,1);
	writew(0x642, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40019);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40039,16'h1a,1);
	writew(0x1a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40039);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40059,16'h1300,1);
	writew(0x1300, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40059);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40079,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40079);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4001a,16'h4808,1);
	writew(0x4808, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4001a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4003a,16'h880,1);
	writew(0x880, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4003a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4005a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4005a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h4007a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x4007a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900aa,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900aa);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ab,16'h790,1);
	writew(0x790, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ab);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ac,16'h11a,1);
	writew(0x11a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ac);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ad,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ad);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ae,16'h7aa,1);
	writew(0x7aa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ae);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900af,16'h2a,1);
	writew(0x2a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900af);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b0,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b1,16'h7b2,1);
	writew(0x7b2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b2,16'h2a,1);
	writew(0x2a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b3,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b4,16'h7c8,1);
	writew(0x7c8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b5,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b6,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b7,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b8,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b8);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900b9,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900b9);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ba,16'h2a8,1);
	writew(0x2a8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ba);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900bb,16'h129,1);
	writew(0x129, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900bb);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900bc,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900bc);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900bd,16'h370,1);
	writew(0x370, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900bd);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900be,16'h129,1);
	writew(0x129, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900be);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900bf,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900bf);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c0,16'h3c8,1);
	writew(0x3c8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c1,16'h1a9,1);
	writew(0x1a9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c2,16'hc,1);
	writew(0xc, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c3,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c4,16'h199,1);
	writew(0x199, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c5,16'h14,1);
	writew(0x14, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c6,16'h790,1);
	writew(0x790, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c7,16'h11a,1);
	writew(0x11a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c8,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c8);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900c9,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900c9);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ca,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ca);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900cb,16'he,1);
	writew(0xe, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900cb);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900cc,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900cc);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900cd,16'h199,1);
	writew(0x199, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900cd);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ce,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ce);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900cf,16'h8568,1);
	writew(0x8568, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900cf);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d0,16'h108,1);
	writew(0x108, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d1,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d2,16'h790,1);
	writew(0x790, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d3,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d4,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d5,16'h1d8,1);
	writew(0x1d8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d6,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d7,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d8,16'h8558,1);
	writew(0x8558, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d8);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900d9,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900d9);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900da,16'h1ff8,1);
	writew(0x1ff8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900da);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900db,16'h85a8,1);
	writew(0x85a8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900db);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900dc,16'h1e8,1);
	writew(0x1e8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900dc);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900dd,16'h50,1);
	writew(0x50, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900dd);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900de,16'h798,1);
	writew(0x798, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900de);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900df,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900df);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e0,16'h60,1);
	writew(0x60, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e1,16'h7a0,1);
	writew(0x7a0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e2,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e3,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e4,16'h8310,1);
	writew(0x8310, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e5,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e6,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e7,16'ha310,1);
	writew(0xa310, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e8,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e8);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900e9,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900e9);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ea,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ea);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900eb,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900eb);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ec,16'h6e,1);
	writew(0x6e, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ec);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ed,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ed);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ee,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ee);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ef,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ef);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f0,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f1,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f2,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f3,16'h8310,1);
	writew(0x8310, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f4,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f5,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f6,16'ha310,1);
	writew(0xa310, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f7,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f8,16'h1ff8,1);
	writew(0x1ff8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f8);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900f9,16'h85a8,1);
	writew(0x85a8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900f9);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900fa,16'h1e8,1);
	writew(0x1e8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900fa);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900fb,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900fb);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900fc,16'h798,1);
	writew(0x798, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900fc);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900fd,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900fd);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900fe,16'h78,1);
	writew(0x78, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900fe);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h900ff,16'h7a0,1);
	writew(0x7a0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x900ff);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90100,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90100);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90101,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90101);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90102,16'h790,1);
	writew(0x790, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90102);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90103,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90103);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90104,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90104);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90105,16'h8b10,1);
	writew(0x8b10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90105);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90106,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90106);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90107,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90107);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90108,16'hab10,1);
	writew(0xab10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90108);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90109,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90109);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9010a,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9010a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9010b,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9010b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9010c,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9010c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9010d,16'h58,1);
	writew(0x58, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9010d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9010e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9010e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9010f,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9010f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90110,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90110);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90111,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90111);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90112,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90112);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90113,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90113);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90114,16'h8b10,1);
	writew(0x8b10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90114);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90115,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90115);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90116,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90116);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90117,16'hab10,1);
	writew(0xab10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90117);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90118,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90118);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90119,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90119);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9011a,16'h1d8,1);
	writew(0x1d8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9011a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9011b,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9011b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9011c,16'h80,1);
	writew(0x80, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9011c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9011d,16'h790,1);
	writew(0x790, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9011d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9011e,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9011e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9011f,16'h18,1);
	writew(0x18, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9011f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90120,16'h7aa,1);
	writew(0x7aa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90120);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90121,16'h6a,1);
	writew(0x6a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90121);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90122,16'ha,1);
	writew(0xa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90122);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90123,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90123);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90124,16'h1e9,1);
	writew(0x1e9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90124);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90125,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90125);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90126,16'h8080,1);
	writew(0x8080, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90126);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90127,16'h108,1);
	writew(0x108, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90127);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90128,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90128);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90129,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90129);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9012a,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9012a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9012b,16'hc,1);
	writew(0xc, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9012b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9012c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9012c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9012d,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9012d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9012e,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9012e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9012f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9012f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90130,16'h1a9,1);
	writew(0x1a9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90130);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90131,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90131);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90132,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90132);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90133,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90133);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90134,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90134);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90135,16'h8080,1);
	writew(0x8080, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90135);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90136,16'h108,1);
	writew(0x108, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90136);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90137,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90137);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90138,16'h7aa,1);
	writew(0x7aa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90138);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90139,16'h6a,1);
	writew(0x6a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90139);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9013a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9013a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9013b,16'h8568,1);
	writew(0x8568, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9013b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9013c,16'h108,1);
	writew(0x108, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9013c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9013d,16'hb7,1);
	writew(0xb7, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9013d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9013e,16'h790,1);
	writew(0x790, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9013e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9013f,16'h16a,1);
	writew(0x16a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9013f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90140,16'h1f,1);
	writew(0x1f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90140);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90141,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90141);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90142,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90142);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90143,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90143);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90144,16'h8558,1);
	writew(0x8558, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90144);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90145,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90145);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90146,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90146);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90147,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90147);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90148,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90148);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90149,16'hd,1);
	writew(0xd, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90149);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9014a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9014a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9014b,16'h68,1);
	writew(0x68, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9014b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9014c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9014c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9014d,16'h408,1);
	writew(0x408, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9014d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9014e,16'h169,1);
	writew(0x169, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9014e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9014f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9014f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90150,16'h8558,1);
	writew(0x8558, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90150);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90151,16'h168,1);
	writew(0x168, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90151);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90152,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90152);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90153,16'h3c8,1);
	writew(0x3c8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90153);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90154,16'h1a9,1);
	writew(0x1a9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90154);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90155,16'h3,1);
	writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90155);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90156,16'h370,1);
	writew(0x370, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90156);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90157,16'h129,1);
	writew(0x129, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90157);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90158,16'h20,1);
	writew(0x20, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90158);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90159,16'h2aa,1);
	writew(0x2aa, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90159);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9015a,16'h9,1);
	writew(0x9, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9015a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9015b,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9015b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9015c,16'he8,1);
	writew(0xe8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9015c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9015d,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9015d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9015e,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9015e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9015f,16'h8140,1);
	writew(0x8140, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9015f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90160,16'h10c,1);
	writew(0x10c, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90160);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90161,16'h10,1);
	writew(0x10, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90161);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90162,16'h8138,1);
	writew(0x8138, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90162);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90163,16'h104,1);
	writew(0x104, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90163);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90164,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90164);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90165,16'h448,1);
	writew(0x448, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90165);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90166,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90166);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90167,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90167);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90168,16'h7c0,1);
	writew(0x7c0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90168);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90169,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90169);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9016a,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9016a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9016b,16'he8,1);
	writew(0xe8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9016b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9016c,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9016c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9016d,16'h47,1);
	writew(0x47, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9016d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9016e,16'h630,1);
	writew(0x630, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9016e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9016f,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9016f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90170,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90170);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90171,16'h618,1);
	writew(0x618, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90171);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90172,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90172);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90173,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90173);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90174,16'he0,1);
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90174);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90175,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90175);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90176,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90176);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90177,16'h7c8,1);
	writew(0x7c8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90177);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90178,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90178);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90179,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90179);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9017a,16'h8140,1);
	writew(0x8140, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9017a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9017b,16'h10c,1);
	writew(0x10c, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9017b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9017c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9017c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9017d,16'h478,1);
	writew(0x478, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9017d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9017e,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9017e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9017f,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9017f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90180,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90180);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90181,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90181);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90182,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90182);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90183,16'h4,1);
	writew(0x4, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90183);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90184,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90184);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90006,16'h8,1);
	writew(0x8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90006);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90007,16'h7c8,1);
	writew(0x7c8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90007);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90008,16'h109,1);
	writew(0x109, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90008);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90009,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90009);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9000a,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9000a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9000b,16'h106,1);
	writew(0x106, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9000b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd00e7,16'h400,1);
	writew(0x400, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd00e7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90017,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90017);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9001f,16'h2b,1);
	writew(0x2b, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9001f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90026,16'h69,1);
	writew(0x69, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90026);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d0,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d0);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d1,16'h101,1);
	writew(0x101, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d2,16'h105,1);
	writew(0x105, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d3,16'h107,1);
	writew(0x107, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d3);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d4,16'h10f,1);
	writew(0x10f, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d5,16'h202,1);
	writew(0x202, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d5);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d6,16'h20a,1);
	writew(0x20a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d6);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400d7,16'h20b,1);
	writew(0x20b, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400d7);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2003a,16'h2,1);
	writew(0x2, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2003a);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h200be,16'h3,1);
	writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x200be);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000b,16'h64,1);
	writew(0x71, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000b);;
	// writew(0x64, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000b); // 1600
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000c,16'hc8,1);
	writew(0xe1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000c);
	// writew(0xc8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000c);	// 1600
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000d,16'h7d0,1);
	writew(0x8ca, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000d);
	// writew(0x7d0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000d);	// 1600
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000e,16'h2c,1);
	writew(0x2c, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12000b,16'h4b,1); // DWC_DDRPHYA_MASTER0_p1_Seq0BDLY0_p1
	writew(0x4b, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12000b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12000c,16'h96,1); // DWC_DDRPHYA_MASTER0_p1_Seq0BDLY1_p1
	writew(0x96, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12000c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12000d,16'h5dc,1); // DWC_DDRPHYA_MASTER0_p1_Seq0BDLY2_p1
	writew(0x5dc, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12000d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12000e,16'h2c,1); // DWC_DDRPHYA_MASTER0_p1_Seq0BDLY3_p1
	writew(0x2c, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12000e);
#else
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000b,16'h64,1);
	writew(0x32, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000b);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000c,16'hc8,1);
	writew(0x64, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000d,16'h7d0,1);
	writew(0x3E8, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h2000e,16'h2c,1);
	writew(0x2c, DDRNSDMC_PUB_MMR_BASE + 2 * 0x2000e);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9000c,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9000c);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9000d,16'h173,1);
	writew(0x173, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9000d);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9000e,16'h60,1);
	writew(0x60, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9000e);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h9000f,16'h6110,1);
	writew(0x6110, DDRNSDMC_PUB_MMR_BASE + 2 * 0x9000f);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90010,16'h2152,1);
	writew(0x2152, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90010);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90011,16'hdfbd,1);
	writew(0xdfbd, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90011);
#ifdef EN_TRAIN
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90012,16'h2060,1);
	writew(0x2060, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90012);
#else
	writew(0xFFFF, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90012);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h90013,16'h6152,1);
	writew(0x6152, DDRNSDMC_PUB_MMR_BASE + 2 * 0x90013);

#ifdef EN_TRAIN
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20010,16'h5a,1);
	writew(0x5a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20010);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20011,16'h3,1);
	writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20011);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120010,16'h5a,1); // DWC_DDRPHYA_MASTER0_p1_PPTTrainSetup_p1
	writew(0x5a, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120010);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120011,16'h3,1); // DWC_DDRPHYA_MASTER0_p1_PPTTrainSetup2_p1
	writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120011);
#endif
#endif

	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40080,16'he0,1);
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40080);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40081,16'h12,1);
	writew(0x12, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40081);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40082,16'he0,1);
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40082);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40083,16'h12,1);
	writew(0x12, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40083);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40084,16'he0,1);
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40084);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h40085,16'h12,1);
	writew(0x12, DDRNSDMC_PUB_MMR_BASE + 2 * 0x40085);
#ifndef DEBUG_800_MHZ
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h140080,16'he0,1); // DWC_DDRPHYA_ACSM0_p1_AcsmPlayback0x0_p1
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x140080);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h140081,16'h12,1); // DWC_DDRPHYA_ACSM0_p1_AcsmPlayback1x0_p1
	writew(0x12, DDRNSDMC_PUB_MMR_BASE + 2 * 0x140081);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h140082,16'he0,1); // DWC_DDRPHYA_ACSM0_p1_AcsmPlayback0x1_p1
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x140082);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h140083,16'h12,1); // DWC_DDRPHYA_ACSM0_p1_AcsmPlayback1x1_p1
	writew(0x12, DDRNSDMC_PUB_MMR_BASE + 2 * 0x140083);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h140084,16'he0,1); // DWC_DDRPHYA_ACSM0_p1_AcsmPlayback0x2_p1
	writew(0xe0, DDRNSDMC_PUB_MMR_BASE + 2 * 0x140084);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h140085,16'h12,1); // DWC_DDRPHYA_ACSM0_p1_AcsmPlayback1x2_p1
	writew(0x12, DDRNSDMC_PUB_MMR_BASE + 2 * 0x140085);
#endif
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400fd,16'hf,1);
	writew(0xf, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400fd);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h400f1,16'he,1);
	writew(0xe, DDRNSDMC_PUB_MMR_BASE + 2 * 0x400f1);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10011,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10012,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10013,16'h180,1);
	writew(0x180, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10018,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h10002,16'h6209,1);
	writew(0x6209, DDRNSDMC_PUB_MMR_BASE + 2 * 0x10002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h100b2,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x100b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h101b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x101b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h102b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x102b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h103b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x103b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h104b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x104b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h105b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x105b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h106b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x106b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h107b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x107b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h108b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x108b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11011,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11012,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11013,16'h180,1);
	writew(0x180, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11018,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h11002,16'h6209,1);
	writew(0x6209, DDRNSDMC_PUB_MMR_BASE + 2 * 0x11002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h110b2,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x110b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h111b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x111b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h112b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x112b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h113b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x113b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h114b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x114b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h115b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x115b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h116b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x116b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h117b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x117b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h118b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x118b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12011,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12012,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12013,16'h180,1);
	writew(0x180, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12018,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h12002,16'h6209,1);
	writew(0x6209, DDRNSDMC_PUB_MMR_BASE + 2 * 0x12002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h120b2,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x120b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h121b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x121b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h122b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x122b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h123b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x123b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h124b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x124b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h125b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x125b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h126b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x126b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h127b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x127b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h128b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x128b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13011,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13011);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13012,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13012);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13013,16'h180,1);
	writew(0x180, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13013);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13018,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13018);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h13002,16'h6209,1);
	writew(0x6209, DDRNSDMC_PUB_MMR_BASE + 2 * 0x13002);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h130b2,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x130b2);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h131b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x131b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h132b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x132b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h133b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x133b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h134b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x134b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h135b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x135b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h136b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x136b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h137b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x137b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h138b4,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x138b4);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20089,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20089);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'h20088,16'h19,1);
	writew(0x19, DDRNSDMC_PUB_MMR_BASE + 2 * 0x20088);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hc0080,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xc0080);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hc0080,16'h3,1);
	writew(0x3, DDRNSDMC_PUB_MMR_BASE + 2 * 0xc0080);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hc0080,16'h0,1);
	writew(0x0, DDRNSDMC_PUB_MMR_BASE + 2 * 0xc0080);
	//sw(`DDRNSDMC_PUB_MMR_BASE +2*32'hd0000,16'h1,1);
	writew(0x1, DDRNSDMC_PUB_MMR_BASE + 2 * 0xd0000);

	INFO("phy init over.\n");
}



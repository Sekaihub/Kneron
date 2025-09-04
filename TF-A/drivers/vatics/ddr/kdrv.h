#ifndef __KDRV__
		#define __KDRV__

		#define DDRNSDMC_MCTL_MMR_BASE  0xCB000000

		#define PLLC_MMR_BASE  0xCED00000
		#define SYSC_SECURE_MMR_BASE	0xCEF00000

/** @brief uMCTL2 DDRC Registers */
    #define MSTR      0x000 /*Master Register0, Exists: Always */
    #define STAT      0x004 /*Operating Mode Status Register, Exists: Always */
    #define MSTR1     0x008 /*Master Register1, Exists: UMCTL2_DDR4_MRAM_EN_OR_HET_RANK_RFC==1*/
    //#define RSV0      0x00C /* Reserved 0 */
    #define MRCTRL0   0x010 /* Mode Register Read/Write Control Register 0. Exists: Always.*/
    #define MRCTRL1   0x014 /* Mode Register Read/Write Control Register 1. Exists: Always */
    #define MRSTAT    0x018 /* Mode Register Read/Write Status Register. Exists: Always */
    #define MRCTRL2   0x01C /* Mode Register Read/Write Control Register 2. Exists: MEMC_DDR4==1 */
    #define DERATEEN  0x020 /* Temperature Derate Enable Register. Exists: MEMC_LPDDR2==1 */
    #define DERATEINT 0x024 /* Temperature Derate Interval Register. Exists: MEMC_LPDDR2==1*/
    #define MSTR2     0x028 /* Master Register2. Exists: UMCTL2_FREQUENCY_NUM>2*/
    #define DERATECTL 0x02C /* Temperature Derate Control Register. Exists: MEMC_LPDDR2==1 */
    #define PWRCTL    0x030 /* Low Power Control Register. Exists: Always*/
    #define PWRTMG    0x034 /* Low Power Timing Register. Exists: Always*/
    #define HWLPCTL   0x038 /* Hardware Low Power Control Register. Exists: Always */
    #define HWFFCCTL  0x03C /* Hardware Fast Frequency Change (HWFFC) Control Register. Exists: UMCTL2_HWFFC_EN==1 */
    #define HWFFCSTAT 0x040 /* Hardware Fast Frequency Change (HWFFC) Status Register. Exists: UMCTL2_HWFFC_EN==1 */
    #define HWFFCEX_RANK1   0x044 /* Hardware Fast Frequency Change (HWFFC) Function Extended for RANK1 Register. Exists: MEMC_DDR4==1&&UMCTL2_HWFFC_EN==1&&MEMC_NUM_RANKS>1*/
    #define HWFFCEX_RANK2   0x048 /* Hardware Fast Frequency Change (HWFFC) Function Extended for RANK2 Register. Exists: MEMC_DDR4==1&&UMCTL2_HWFFC_EN==1&&MEMC_NUM_RANKS>1 */
    #define HWFFCEX_RANK3   0x04C /* Hardware Fast Frequency Change (HWFFC) Function Extended for RANK3 Register. Exists: MEMC_DDR4==1&&UMCTL2_HWFFC_EN==1&&MEMC_NUM_RANKS>1 */
    #define RFSHCTL0  0x050 /* Refresh Control Register 0. Exists: Always*/
    #define RFSHCTL1  0x054 /* Refresh Control Register 1. Exists: MEMC_NUM_RANKS>1*/
    #define RFSHCTL2  0x058 /* Refresh Control Register 2. Exists: MEMC_NUM_RANKS>2*/
    #define RFSHCTL4  0x05C /* Refresh Control Register 4. Exists: MEMC_NUM_RANKS_GT_4_OR_UMCTL2_CID_EN==1*/
    #define RFSHCTL3  0x060 /* Refresh Control Register 3. Exists: Always
                        Can only be programmed during the initialization or when the controller is in self-refresh mode.*/
    #define RFSHTMG   0x064 /* Refresh Timing Register. Exists: Always*/
    #define RFSHTMG1  0x068 /* Refresh Timing Register1. Exists: MEMC_LPDDR4_OR_UMCTL2_CID_EN==1*/
    //#define RSV2                               0x06C /* Reserved 2 */
    #define KDRV_DDRC_CTRL_REG_ECCCFG0         0x070 /* R ECC Configuration Register 0 */
    #define KDRV_DDRC_CTRL_REG_ECCCFG1         0x074 /* R ECC Configuration Register 1 */
    #define KDRV_DDRC_CTRL_REG_ECCSTAT         0x078 /* R SECDED ECC Status Register (Valid only in MEMC_ECC_SUPPORT==1 (SECDED ECC mode)) */
    #define KDRV_DDRC_CTRL_REG_ECCCTL          0x07C /* R ECC Clear Register */
    #define KDRV_DDRC_CTRL_REG_ECCERRCNT       0x080 /* R ECC Error Counter Register */
    #define KDRV_DDRC_CTRL_REG_ECCCADDR0       0x084 /* R ECC Corrected Error Address Register 0 */
    #define KDRV_DDRC_CTRL_REG_ECCCADDR1       0x088 /* ECC Corrected Error Address Register 1 */
    #define KDRV_DDRC_CTRL_REG_ECCCSYN0        0x08C /* ECC Corrected Syndrome Register 0 */
    #define KDRV_DDRC_CTRL_REG_ECCCSYN1        0x090 /* ECC Corrected Syndrome Register 1 */
    #define KDRV_DDRC_CTRL_REG_ECCCSYN2        0x094 /* ECC Corrected Syndrome Register 2 */
    #define KDRV_DDRC_CTRL_REG_ECCBITMASK0     0x098 /* ECC Corrected Data Bit Mask Register 0 */
    #define KDRV_DDRC_CTRL_REG_ECCBITMASK1     0x09C /* ECC Corrected Data Bit Mask Register 1 */
    #define KDRV_DDRC_CTRL_REG_ECCBITMASK2     0x0A0 /* ECC Corrected Data Bit Mask Register 2 */
    #define KDRV_DDRC_CTRL_REG_ECCUADDR0       0x0A4 /* ECC Uncorrected Error Address Register 0 */
    #define KDRV_DDRC_CTRL_REG_ECCUADDR1       0x0A8 /* ECC Uncorrected Error Address Register 1 */
    #define KDRV_DDRC_CTRL_REG_ECCUSYN0        0x0AC /* ECC Uncorrected Syndrome Register 0 */
    #define KDRV_DDRC_CTRL_REG_ECCUSYN1        0x0B0 /* ECC Uncorrected Syndrome Register 1 */
    #define KDRV_DDRC_CTRL_REG_ECCUSYN2        0x0B4 /* ECC Uncorrected Syndrome Register 2 */
    #define KDRV_DDRC_CTRL_REG_ECCPOISONADDR0  0x0B8 /* ECC Data Poisoning Address Register 0. If a HIF write data beat matches the address specified in... */
    #define KDRV_DDRC_CTRL_REG_ECCPOISONADDR1  0x0BC /* ECC Data Poisoning Address Register 1. If a HIF write data beat matches the address specified in... */
    #define CRCPARCTL0    0x0C0 /* CRC Parity Control Register0. Exists: Always
                            Note: Do not perform any APB access to CRCPARCTL0 within 32 pclk cycles*/
    #define CRCPARCTL1    0x0C4 /* CRC Parity Control Register1. Exists: MEMC_DDR4==1*/
    #define CRCPARCTL2    0x0C8 /* CRC Parity Control Register2. Exists: UMCTL2_CRC_PARITY_RETRY==1*/
    #define CRCPARSTAT    0x0CC /* CRC Parity Status Register. Exists: Always*/
    #define INIT0         0x0D0 /* SDRAM Initialization Register 0. Exists: Always*/
    #define INIT1         0x0D4 /* SDRAM Initialization Register 1. Exists: Always */
    #define INIT2         0x0D8 /* SDRAM Initialization Register 2. Exists: MEMC_LPDDR2==1 */
    #define INIT3         0x0DC /* SDRAM Initialization Register 3. Exists: Always */
    #define INIT4         0x0E0 /* SDRAM Initialization Register 4. Exists: Always */
    #define INIT5         0x0E4 /* SDRAM Initialization Register 5. Exists: MEMC_DDR3_OR_4_OR_LPDDR2==1*/
    #define INIT6         0x0E8 /* SDRAM Initialization Register 6. Exists: MEMC_DDR4_OR_LPDDR4==1*/
    #define INIT7         0x0EC /* SDRAM Initialization Register 7. Exists: MEMC_DDR4_OR_LPDDR4==1*/
    #define DIMMCTL       0x0F0 /* DIMM Control Register. Exists: Always */
    #define RANKCTL       0x0F4 /* Rank Control Register. Exists: UMCTL2_NUM_LRANKS_TOTAL>1*/
    #define RANKCTL1      0x0F8 /* Rank Control 1 Register. Exists: UMCTL2_NUM_LRANKS_TOTAL>1&&MEMC_ENH_CAM_PTR==1*/
    #define CHCTL         0x0FC /* Channel Control Register. Exists: UMCTL2_SHARED_AC==1 && UMCTL2_PROGCHN_OR_UMCTL2_SHAREDAC_LP4DUAL_COMB */
    #define DRAMTMG0      0x100 /* SDRAM Timing Register 0. Exists: Always*/
    #define DRAMTMG1      0x104 /* SDRAM Timing Register 1. Exists: Always*/
    #define DRAMTMG2      0x108 /* SDRAM Timing Register 2. Exists: Always*/
    #define DRAMTMG3      0x10C /* SDRAM Timing Register 3. Exists: Always*/
    #define DRAMTMG4      0x110 /* SDRAM Timing Register 4. Exists: Always*/
    #define DRAMTMG5      0x114 /* SDRAM Timing Register 5. Exists: Always*/
    #define DRAMTMG6      0x118 /* SDRAM Timing Register 6. Exists: MEMC_MOBILE_OR_LPDDR2==1*/
    #define DRAMTMG7      0x11C /* SDRAM Timing Register 7. Exists: MEMC_MOBILE_OR_LPDDR2==1*/
    #define DRAMTMG8      0x120 /* SDRAM Timing Register 8. Exists: Always*/
    #define DRAMTMG9      0x124 /* SDRAM Timing Register 9. Exists: MEMC_DDR4==1*/
    #define DRAMTMG10     0x128 /* SDRAM Timing Register 10. Exists: MEMC_DDR4==1 && MEMC_CMD_RTN2IDLE==0 && MEMC_FREQ_RATIO==2 */
    #define DRAMTMG11     0x12C /* SDRAM Timing Register 11 . Exists: MEMC_DDR4==1*/
    #define DRAMTMG12     0x130 /* SDRAM Timing Register 12. Exists: MEMC_DDR4_OR_LPDDR4==1*/
    #define DRAMTMG13     0x134 /* SDRAM Timing Register 13. Exists: MEMC_LPDDR4==1*/
    #define DRAMTMG14     0x138 /* SDRAM Timing Register 14. Exists: MEMC_MOBILE_OR_LPDDR2==1 */
    #define DRAMTMG15     0x13C /* SDRAM Timing Register 15. Exists: MEMC_DDR3_OR_4==1*/
    #define DRAMTMG16     0x140 /* SDRAM Timing Register 16. Exists: UMCTL2_CID_EN==1*/
    #define DRAMTMG17     0x144 /* SDRAM Timing Register 17. UMCTL2_HWFFC_EN==1*/
    ////#define RSV4[2]       0x148~0x014C Reserved 4 */
    #define RFSHTMG_HET   0x150 /* Refresh Timing Register Heterogeneous. __QD_G4_RW*/
    //#define RSV5[7]       0x154~0x016C Reserved 5 */
    #define MRAMTMG0      0x170 /* MRAM Timing Register 0. Exists: UMCTL2_DDR4_MRAM_EN==1*/
    #define MRAMTMG1      0x174 /* MRAM Timing Register 1. Exists: UMCTL2_DDR4_MRAM_EN==1*/
    #define MRAMTMG4      0x178 /* MRAM Timing Register 4. Exists: UMCTL2_DDR4_MRAM_EN==1*/
    #define MRAMTMG9      0x17C /* MRAM Timing Register 9. Exists: UMCTL2_DDR4_MRAM_EN==1*/
    #define ZQCTL0        0x180 /* ZQ Control Register 0. Exists: MEMC_DDR3_OR_4_OR_LPDDR2==1*/
    #define ZQCTL1        0x184 /* ZQ Control Register 1. Exists: MEMC_DDR3_OR_4_OR_LPDDR2==1*/
    #define ZQCTL2        0x188 /* ZQ Control Register 2. Exists: MEMC_LPDDR2==1*/
    #define ZQSTAT        0x18C /* ZQ Status Register. Exists: MEMC_LPDDR2==1*/
    #define DFITMG0       0x190 /* DFI Timing Register 0. Exists: Always*/
    #define DFITMG1       0x194 /* DFI Timing Register 1. Exists: Always*/
    #define DFILPCFG0     0x198 /* DFI Low Power Configuration Register 0. Exists: Always*/
    #define DFILPCFG1     0x19C /* DFI Low Power Configuration Register 1. Exists: MEMC_DDR4==1 */
    #define DFIUPD0       0x1A0 /* DFI Update Register 0. Exists: Always*/
    #define DFIUPD1       0x1A4 /* DFI Update Register 1. Exists: Always */
    #define DFIUPD2       0x1A8 /* DFI Update Register 2. Exists: Always*/
    //#define RSV6          0x1AC /* Reserved 6 */
    #define DFIMISC       0x1B0 /* DFI Miscellaneous Control Register. Exists: Always*/
    #define DFITMG2       0x1B4 /* DFI Timing Register 2. Exists: UMCTL2_DFI_DATA_CS_EN==1*/
    #define DFITMG3       0x1B8 /* DFI Timing Register 3. Exists: MEMC_DDR4==1 && MEMC_CMD_RTN2IDLE==0 && MEMC_FREQ_RATIO==2*/
    #define DFISTAT       0x1BC /* DFI Status Register. Exists: Always*/
    #define DBICTL        0x1C0 /* DM/DBI Control Register. Exists: MEMC_DDR4_OR_LPDDR4==1*/
    #define DFIPHYMSTR    0x1C4 /* DFI PHY Master. Exists: Always*/
    //#define RSV7[14]      0x1C8~0x01FC Reserved 7 */
    #define ADDRMAP0      0x200 /* Address Map Register 0. Exists: (UMCTL2_RANKS_GT_1_OR_DCH_INTL_1==1)*/
    #define ADDRMAP1      0x204 /* Address Map Register 1. Exists: Always*/
    #define ADDRMAP2      0x208 /* Address Map Register 2. Exists: Always*/
    #define ADDRMAP3      0x20C /* Address Map Register 3. Exists: Always*/
    #define ADDRMAP4      0x210 /* Address Map Register 4. Exists: Always*/
    #define ADDRMAP5      0x214 /* Address Map Register 5. Exists: Always*/
    #define ADDRMAP6      0x218 /* Address Map Register 6. Exists: Always*/
    #define ADDRMAP7      0x21C /* Address Map Register 7. Exists: (MEMC_DDR4_OR_LPDDR4==1)*/
    #define ADDRMAP8      0x220 /* Address Map Register 8. Exists: (MEMC_DDR4==1)*/
    #define ADDRMAP9      0x224 /* Address Map Register 9. Exists: Always*/
    #define ADDRMAP10     0x228 /* Address Map Register 10. Exists: Always*/
    #define ADDRMAP11     0x22C /* Address Map Register 11. Exists: Always*/
    //#define RSV8[4]       0x230~0x023C Reserved 7 */
    #define ODTCFG        0x240 /* ODT Configuration Register. Exists: Always*/
    #define ODTMAP        0x244 /* ODT/Rank Map Register. Exists: MEMC_NUM_RANKS_1_OR_2_OR_4==1*/
    //#define RSV9[2]       0x248 ~ 0x024C Reserved 8 */
    #define SCHED         0x250 /* Scheduler Control Register. Exists: Always*/
    #define SCHED1        0x254 /* Scheduler Control Register 1. Exists: Always*/
    #define SCHED2        0x258 /* Scheduler Control Register 2. Exists: UMCTL2_DYN_BSM==1*/
    #define PERFHPR1      0x25C /* High Priority Read CAM Register 1 Exists: UPCTL2_EN_1==0*/
    //#define RSV10         0x260 /* Reserved 10 */
    #define PERFLPR1      0x264 /* Low Priority Read CAM Register 1. Exists: Always*/
    //#define RSV11         0x268 /* Reserved 11 */
    #define PERFWR1       0x26C /* Write CAM Register 1. Exists: Always*/
    #define SCHED3        0x270 /* Scheduler Control Register 3. Exists: MEMC_ENH_RDWR_SWITCH==1*/
    #define SCHED4        0x274 /* Scheduler Control Register 4. Exists: MEMC_ENH_RDWR_SWITCH==1*/
    #define SCHED5        0x278 /* Scheduler Control Register 5. Exists: MEMC_ENH_RDWR_SWITCH==1&&MEMC_INLINE_ECC==1*/
    //#define RSV12         0x27C Reserved 12 */
    #define DQMAP0        0x280 /* DQ Map Register 0. Exists: MEMC_DDR4==1 && UMCTL2_DQ_MAPPING==1*/
    #define DQMAP1        0x284 /* DQ Map Register 1. Exists: MEMC_DDR4==1 && UMCTL2_DQ_MAPPING==1 && MEMC_DRAM_DATA_WIDTH>23*/
    #define DQMAP2        0x288 /* DQ Map Register 2. Exists: MEMC_DDR4==1 && UMCTL2_DQ_MAPPING==1 && MEMC_DRAM_DATA_WIDTH>39*/
    #define DQMAP3        0x28C /* DQ Map Register 3. Exists: MEMC_DDR4==1 && UMCTL2_DQ_MAPPING==1 && MEMC_DRAM_DATA_WIDTH>55*/
    #define DQMAP4        0x290 /* DQ Map Register 4. Exists: MEMC_DDR4==1 && UMCTL2_DQ_MAPPING==1 && MEMC_DRAM_-DATA_WIDTH_72_OR_MEMC_SIDEBAND_ECC==1*/
    #define DQMAP5        0x294 /* DQ Map Register 5. Exists: MEMC_DDR4==1 && UMCTL2_DQ_MAPPING==1*/
    //#define RSV13[26]     0x298~0x2FC Reserved 13 */
    #define DBG0          0x300 /* Debug Register 0. Exists: Always*/
    #define DBG1          0x304 /* Debug Register 1. Exists: Always*/
    #define DBGCAM        0x308 /* CAM Debug Register. Exists: Always*/
    #define DBGCMD        0x30C /* Command Debug Register. Exists: Always*/
    #define DBGSTAT       0x310 /* Status Debug Register. Exists: Always*/
    //#define RSV14         0x314 /* Reserved 14 */
    #define DBGCAM1       0x318 /* CAM Debug Register 1 */
    //#define RSV15         0x31C /* Reserved 15 */
    #define SWCTL         0x320 /* Software Register Programming Control Enable, Exists: Always*/
    #define SWSTAT        0x324 /* Software Register Programming Control Status, Exists: Always */
    #define SWCTLSTATIC   0x328 /* Static Registers Write Enable, Exists: Always */
    //#define RSV16         0x32C /* Reserved 16 */
    #define OCPARCFG0     0x330 /* On-Chip Parity Configuration Register 0, Exists: UMCTL2_OCPAR_OR_OCECC_EN_1==1 */
    #define OCPARCFG1     0x334 /* On-Chip Parity Configuration Register 1. Exists: UMCTL2_OCPAR_EN_1==1*/
    #define OCPARSTAT0    0x338 /* On-Chip Parity Status Register 0. Exists: UMCTL2_OCPAR_OR_OCECC_EN_1==1 */
    #define OCPARSTAT1    0x33C /* On-Chip Parity Status Register 1. Exists: UMCTL2_OCPAR_EN_1==1 */
    #define OCPARSTAT2    0x340 /* On-Chip Parity Status Register 2. Exists: UMCTL2_OCPAR_EN_1==1 */
    #define OCPARSTAT3    0x344 /* On-Chip Parity Status Register 3. Exists: UMCTL2_OCPAR_EN_1==1 && MEMC_INLINE_ECC==0 */
    #define OCPARSTAT4    0x348 /* On-Chip Parity Status Register 4. Exists: UMCTL2_OCPAR_EN_1==1 && MEMC_INLINE_ECC==0 */
    #define OCPARSTAT5    0x34C /* On-Chip Parity Status Register 5. Exists: UMCTL2_OCPAR_EN_1==1 && MEMC_INLINE_ECC==0 */
    #define OCPARSTAT6    0x350 /* On-Chip Parity Status Register 6. Exists: UMCTL2_OCPAR_EN_1==1 && MEMC_INLINE_ECC==0 */
    #define OCPARSTAT7    0x354 /* On-Chip Parity Status Register 7. Exists: UMCTL2_OCPAR_EN_1==1 && MEMC_INLINE_ECC==0 */
    #define OCECCCFG0     0x358 /* On-Chip ECC Configuration Register 0. Exists: UMCTL2_OCECC_EN_1==1 */
    #define OCECCCFG1     0x35C /* On-Chip ECC Configuration Register 1. Exists: UMCTL2_OCECC_EN_1==1 */
    #define OCECCSTAT0    0x360 /* On-Chip ECC Status Register 0. Exists: UMCTL2_OCECC_EN_1==1 */
    #define OCECCSTAT1    0x364 /* On-Chip ECC Status Register 1. Exists: UMCTL2_OCECC_EN_1==1 */
    #define OCECCSTAT2    0x368 /* On-Chip ECC Status Register 2. Exists: UMCTL2_OCECC_EN_1==1 */
    #define POISONCFG     0x36C /* AXI Poison Configuration Register. Common for all AXI ports. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_A_AXI==1 */
    #define POISONSTAT            0x370 /* AXI Poison Status Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_A_AXI==1 */
    #define ADVECCINDEX           0x374 /* Advanced ECC Index Register. Exists: MEMC_ECC_SUPPORT>0 */
    #define ADVECCSTAT            0x378 /* Advanced ECC Status Register. Exists: MEMC_ECC_SUPPORT==2 */
    #define ECCPOISONPAT0         0x37C /* ECC Poison Pattern 0 Register. Exists: MEMC_ECC_SUPPORT>0 */
    #define ECCPOISONPAT1         0x380 /* ECC Poison Pattern 1 Register. Exists: MEMC_ECC_SUPPORT>0 && MEMC_DRAM_DATA_WIDTH==64 */
    #define ECCPOISONPAT2         0x384 /* ECC Poison Pattern 2 Register. Exists: MEMC_ECC_SUPPORT>0 */
    #define ECCAPSTAT             0x388 /* Address protection within ECC Status Register. Exists: MEMC_ECCAP==1 */
    //#define RSV17[5]              0x38C~0x39C Reserved 17 */
    #define CAPARPOISONCTL        0x3A0 /* CA parity poison contrl Register. Exists: MEMC_DDR4==1 && UMCTL2_CRC_PARITY_RETRY==1 */
    #define CAPARPOISONSTAT       0x3A4 /* CA parity poison status Register. Exists: MEMC_DDR4==1 && UMCTL2_CRC_PARITY_RETRY==1 */
    //#define RSV18[2]              0x3A8~0x3AC Reserved 18 */
    #define DYNBSMSTAT            0x3B0 /* Dynamic BSM Status Register. Exists: UMCTL2_DYN_BSM==1 */
    //#define RSV19                 0x3B4 /* Reserved 19 */
    #define CRCPARCTL3            0x3B8 /* CRC Parity Control Register3. Exists: UMCTL2_CRC_PARITY_RETRY==1 */
    //#define RSV20                 0x3BC /* Reserved 20 */
    #define REGPARCFG             0x3C0 /* Register Parity Configuration Register. Exists: UMCTL2_REGPAR_EN_1 */
    #define REGPARSTAT            0x3C4 /* Register Parity Status Register. Exists: UMCTL2_REGPAR_EN_1 */
    //#define RSV21[2]              0x3C8~0x3CC Reserved 21 */
    #define RCDINIT1              0x3D0 /* Control Word setting Register RCDINIT1. Exists: UMCTL2_HWFFC_EN==1 && MEMC_DDR4==1 */
    #define RCDINIT2              0x3D4 /* Control Word setting Register RCDINIT2. Exists: UMCTL2_HWFFC_EN==1 && MEMC_DDR4==1 */
    #define RCDINIT3              0x3D8 /* Control Word setting Register RCDINIT3. Exists: UMCTL2_HWFFC_EN==1 && MEMC_DDR4==1 */
    #define RCDINIT4              0x3DC /* Control Word setting Register RCDINIT4. Exists: UMCTL2_HWFFC_EN==1 && MEMC_DDR4==1 */
    #define OCCAPCFG              0x3E0 /* On-Chip command/Address Protection Configuration Register. Exists: UMCTL2_OCCAP_EN_1==1 */
    #define OCCAPSTAT             0x3E4 /* On-Chip command/Address Protection Status Register. Exists: UMCTL2_OCCAP_EN_1==1 && UMCTL2_INCL_ARB==1*/
    #define OCCAPCFG1             0x3E8 /* On-Chip command/Address Protection Configuration Register 1. Exists: UMCTL2_OCCAP_EN_1==1 */
    #define OCCAPSTAT1            0x3EC /* On-Chip command/Address Protection Status Register 1. Exists: UMCTL2_OCCAP_EN_1==1 */
    #define DERATESTAT            0x3F0 /* Temperature Derate Status Register */













/** @brief uMCTL2 Multi-Port Registers */

    #define  PSTAT                 0x03FC  /* Port Status Register. Exists: UMCTL2_INCL_ARB==1*/
    #define  PCCFG                 0x0400  /* Port Common Configuration Register. Exists: UMCTL2_INCL_ARB==1*/
    #define  PCFGR_0               0x0404  /* Port 0 Configuration Read Register*/
    #define  PCFGW_0               0x0408  /* Port 0 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_0               0x040C  /* Port 0 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_0      0x0410  /* Port 0 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_0     0x0414  /* Port 0 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_0      0x0418  /* Port 0 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_0     0x041C  /* Port 0 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_0      0x0420  /* Port 0 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_0     0x0424  /* Port 0 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_0      0x0428  /* Port 0 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_0     0x042C  /* Port 0 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_0      0x0430  /* Port 0 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_0     0x0434  /* Port 0 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_0      0x0438  /* Port 0 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_0     0x043C  /* Port 0 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_0      0x0440  /* Port 0 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_0     0x0444  /* Port 0 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_0      0x0448  /* Port 0 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_0     0x044C  /* Port 0 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_0      0x0450  /* Port 0 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_0     0x0454  /* Port 0 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_0      0x0458  /* Port 0 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_0     0x045C  /* Port 0 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_0     0x0460  /* Port 0 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_0    0x0464  /* Port 0 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_0     0x0468  /* Port 0 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_0    0x046C  /* Port 0 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_0     0x0470  /* Port 0 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_0    0x0474  /* Port 0 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_0     0x0478  /* Port 0 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_0    0x047C  /* Port 0 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_0     0x0480  /* Port 0 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_0    0x0484  /* Port 0 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_0     0x0488  /* Port 0 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_0    0x048C  /* Port 0 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_0               0x0490  /* Port 0 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_0            0x0494  /* Port 0 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0*/
    #define  PCFGQOS1_0            0x0498  /* Port 0 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1*/
    #define  PCFGWQOS0_0           0x049C  /* Port 0 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_0           0x04A0  /* Port 0 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV0[4]               0x04A4 ~ 0x04B0, Reserved 0 */
    #define  PCFGR_1               0x04B4  /* Port 1 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_1               0x04B8  /* Port 1 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_1               0x04BC  /* Port 1 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_1      0x04C0  /* Port 1 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_1     0x04C4  /* Port 1 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_1      0x04C8  /* Port 1 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_1     0x04CC  /* Port 1 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_1      0x04D0  /* Port 1 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_1     0x04D4  /* Port 1 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_1      0x04D8  /* Port 1 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_1     0x04DC  /* Port 1 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_1      0x04E0  /* Port 1 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_1     0x04E4  /* Port 1 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_1      0x04E8  /* Port 1 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_1     0x04EC  /* Port 1 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_1      0x04F0  /* Port 1 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_1     0x04F4  /* Port 1 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_1      0x04F8  /* Port 1 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_1     0x04FC  /* Port 1 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_1      0x0500  /* Port 1 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_1     0x0504  /* Port 1 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_1      0x0508  /* Port 1 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_1     0x050C  /* Port 1 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_1     0x0510  /* Port 1 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_1    0x0514  /* Port 1 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_1     0x0518  /* Port 1 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_1    0x051C  /* Port 1 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_1     0x0520  /* Port 1 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_1    0x0524  /* Port 1 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_1     0x0528  /* Port 1 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_1    0x052C  /* Port 1 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_1     0x0530  /* Port 1 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_1    0x0534  /* Port 1 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_1     0x0538  /* Port 1 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_1    0x053C  /* Port 1 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_1               0x0540  /* Port 1 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_1            0x0544   /* Port 1 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0*/
    #define  PCFGQOS1_1            0x0548  /* Port 1 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1*/
    #define  PCFGWQOS0_1           0x054C  /* Port 1 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_1           0x0550  /* Port 1 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV1[4]               0x0554 ~ 0x0560, Reserved 1 */
    #define  PCFGR_2               0x0564  /* Port 2 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_2               0x0568  /* Port 2 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_2               0x056C  /* Port 2 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_2      0x0570  /* Port 2 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_2     0x0574  /* Port 2 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_2      0x0578  /* Port 2 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_2     0x057C  /* Port 2 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_2      0x0580  /* Port 2 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_2     0x0584  /* Port 2 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_2      0x0588  /* Port 2 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_2     0x058C  /* Port 2 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_2      0x0590  /* Port 2 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_2     0x0594  /* Port 2 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_2      0x0598  /* Port 2 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_2     0x059C  /* Port 2 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_2      0x05A0  /* Port 2 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_2     0x05A4  /* Port 2 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_2      0x05A8  /* Port 2 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_2     0x05AC  /* Port 2 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_2      0x05B0  /* Port 2 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_2     0x05B4  /* Port 2 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_2      0x05B8  /* Port 2 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_2     0x05BC  /* Port 2 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_2     0x05C0  /* Port 2 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_2    0x05C4  /* Port 2 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_2     0x05C8  /* Port 2 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_2    0x05CC  /* Port 2 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_2     0x05D0  /* Port 2 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_2    0x05D4  /* Port 2 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_2     0x05D8  /* Port 2 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_2    0x05DC  /* Port 2 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_2     0x05E0  /* Port 2 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_2    0x05E4  /* Port 2 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_2     0x05E8  /* Port 2 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_2    0x05EC  /* Port 2 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_2               0x05F0  /* Port 2 Control Register Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_2            0x05F4   /* Port 2 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0*/
    #define  PCFGQOS1_2            0x05F8  /* Port 2 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1*/
    #define  PCFGWQOS0_2           0x05FC  /* Port 2 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_2           0x0600  /* Port 2 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV2[4]               0x0604 ~ 0x0610, Reserved 2 */
    #define  PCFGR_3               0x0614  /* Port 3 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_3               0x0618  /* Port 3 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_3               0x061C  /* Port 3 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_3      0x0620  /* Port 3 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_3     0x0624  /* Port 3 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_3      0x0628  /* Port 3 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_3     0x062C  /* Port 3 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_3      0x0630  /* Port 3 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_3     0x0634  /* Port 3 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_3      0x0638  /* Port 3 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_3     0x063C  /* Port 3 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_3      0x0640  /* Port 3 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_3     0x0644  /* Port 3 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_3      0x0648  /* Port 3 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_3     0x064C  /* Port 3 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_3      0x0650  /* Port 3 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_3     0x0654  /* Port 3 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_3      0x0658  /* Port 3 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_3     0x065C  /* Port 3 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_3      0x0660  /* Port 3 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_3     0x0664  /* Port 3 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_3      0x0668  /* Port 3 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_3     0x066C  /* Port 3 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_3     0x0670  /* Port 3 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_3    0x0674  /* Port 3 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_3     0x0678  /* Port 3 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_3    0x067C  /* Port 3 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_3     0x0680  /* Port 3 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_3    0x0684  /* Port 3 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_3     0x0688  /* Port 3 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_3    0x068C  /* Port 3 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_3     0x0690  /* Port 3 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_3    0x0694  /* Port 3 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_3     0x0698  /* Port 3 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_3    0x069C  /* Port 3 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_3               0x06A0  /* Port 3 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_3            0x06A4   /* Port 3 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0*/
    #define  PCFGQOS1_3            0x06A8  /* Port 3 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1*/
    #define  PCFGWQOS0_3           0x06AC  /* Port 3 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_3           0x06B0  /* Port 3 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV3[4]               0x06B4 ~ 0x06C0, Reserved 3 */
    #define  PCFGR_4               0x06C4  /* Port 4 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_4               0x06C8  /* Port 4 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_4               0x06CC  /* Port 4 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_4      0x06D0  /* Port 4 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_4     0x06D4  /* Port 4 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_4      0x06D8  /* Port 4 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_4     0x06DC  /* Port 4 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_4      0x06E0  /* Port 4 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_4     0x06E4  /* Port 4 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_4      0x06E8  /* Port 4 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_4     0x06EC  /* Port 4 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_4      0x06F0  /* Port 4 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_4     0x06F4  /* Port 4 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_4      0x06F8  /* Port 4 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_4     0x06FC  /* Port 4 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_4      0x0700  /* Port 4 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_4     0x0704  /* Port 4 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_4      0x0708  /* Port 4 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_4     0x070C  /* Port 4 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_4      0x0710  /* Port 4 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_4     0x0714  /* Port 4 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_4      0x0718  /* Port 4 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_4     0x071C  /* Port 4 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_4     0x0720  /* Port 4 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_4    0x0724  /* Port 4 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_4     0x0728  /* Port 4 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_4    0x072C  /* Port 4 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_4     0x0730  /* Port 4 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_4    0x0734  /* Port 4 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_4     0x0738  /* Port 4 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_4    0x073C  /* Port 4 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_4     0x0740  /* Port 4 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_4    0x0744  /* Port 4 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_4     0x0748  /* Port 4 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_4    0x074C  /* Port 4 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_4               0x0750  /* Port 4 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_4            0x0754  /* Port 4 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_4            0x0758  /* Port 4 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_4           0x075C  /* Port 4 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_4           0x0760  /* Port 4 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV4[4]               0x0764 ~ 0x0770, Reserved 4 */
    #define  PCFGR_5               0x0774  /* Port 5 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_5               0x0778  /* Port 5 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_5               0x077C  /* Port 5 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_5      0x0780  /* Port 5 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_5     0x0784  /* Port 5 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_5      0x0788  /* Port 5 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_5     0x078C  /* Port 5 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_5      0x0790  /* Port 5 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_5     0x0794  /* Port 5 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_5      0x0798  /* Port 5 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_5     0x079C  /* Port 5 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_5      0x07A0  /* Port 5 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_5     0x07A4  /* Port 5 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_5      0x07A8  /* Port 5 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_5     0x07AC  /* Port 5 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_5      0x07B0  /* Port 5 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_5     0x07B4  /* Port 5 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_5      0x07B8  /* Port 5 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_5     0x07BC  /* Port 5 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_5      0x07C0  /* Port 5 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_5     0x07C4  /* Port 5 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_5      0x07C8  /* Port 5 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_5     0x07CC  /* Port 5 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_5     0x07D0  /* Port 5 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_5    0x07D4  /* Port 5 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_5     0x07D8  /* Port 5 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_5    0x07DC  /* Port 5 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_5     0x07E0  /* Port 5 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_5    0x07E4  /* Port 5 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_5     0x07E8  /* Port 5 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_5    0x07EC  /* Port 5 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_5     0x07F0  /* Port 5 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_5    0x07F4  /* Port 5 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_5     0x07F8  /* Port 5 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_5    0x07FC  /* Port 5 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_5               0x0800  /* Port 5 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_5            0x0804  /* Port 5 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_5            0x0808  /* Port 5 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_5           0x080C  /* Port 5 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_5           0x0810  /* Port 5 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV5[4]               0x0814 ~ 0x0820, Reserved 5 */
    #define  PCFGR_6               0x0824  /* Port 6 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_6               0x0828  /* Port 6 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_6               0x082C  /* Port 6 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_6      0x0830  /* Port 6 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_6     0x0834  /* Port 6 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_6      0x0838  /* Port 6 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_6     0x083C  /* Port 6 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_6      0x0840  /* Port 6 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_6     0x0844  /* Port 6 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_6      0x0848  /* Port 6 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_6     0x084C  /* Port 6 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_6      0x0850  /* Port 6 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_6     0x0854  /* Port 6 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_6      0x0858  /* Port 6 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_6     0x085C  /* Port 6 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_6      0x0860  /* Port 6 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_6     0x0864  /* Port 6 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_6      0x0868  /* Port 6 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_6     0x086C  /* Port 6 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_6      0x0870  /* Port 6 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_6     0x0874  /* Port 6 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_6      0x0878  /* Port 6 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_6     0x087C  /* Port 6 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_6     0x0880  /* Port 6 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_6    0x0884  /* Port 6 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_6     0x0888  /* Port 6 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_6    0x088C  /* Port 6 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_6     0x0890  /* Port 6 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_6    0x0894  /* Port 6 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_6     0x0898  /* Port 6 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_6    0x089C  /* Port 6 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_6     0x08A0  /* Port 6 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_6    0x08A4  /* Port 6 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_6     0x08A8  /* Port 6 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_6    0x08AC  /* Port 6 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_6               0x08B0  /* Port 6 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_6            0x08B4  /* Port 6 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_6            0x08B8  /* Port 6 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_6           0x08BC  /* Port 6 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_6           0x08C0  /* Port 6 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV6[4]               0x08C4 ~ 0x08D0, Reserved 6 */
    #define  PCFGR_7               0x08D4  /* Port 7 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_7               0x08D8  /* Port 7 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_7               0x08DC  /* Port 7 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_7      0x08E0  /* Port 7 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_7     0x08E4  /* Port 7 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_7      0x08E8  /* Port 7 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_7     0x08EC  /* Port 7 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_7      0x08F0  /* Port 7 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_7     0x08F4  /* Port 7 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_7      0x08F8  /* Port 7 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_7     0x08FC  /* Port 7 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_7      0x0900  /* Port 7 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_7     0x0904  /* Port 7 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_7      0x0908  /* Port 7 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_7     0x090C  /* Port 7 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_7      0x0910  /* Port 7 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_7     0x0914  /* Port 7 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_7      0x0918  /* Port 7 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_7     0x091C  /* Port 7 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_7      0x0920  /* Port 7 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_7     0x0924  /* Port 7 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_7      0x0928  /* Port 7 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_7     0x092C  /* Port 7 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_7     0x0930  /* Port 7 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_7    0x0934  /* Port 7 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_7     0x0938  /* Port 7 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_7    0x093C  /* Port 7 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_7     0x0940  /* Port 7 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_7    0x0944  /* Port 7 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_7     0x0948  /* Port 7 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_7    0x094C  /* Port 7 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_7     0x0950  /* Port 7 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_7    0x0954  /* Port 7 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_7     0x0958  /* Port 7 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_7    0x095C  /* Port 7 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_7               0x0960  /* Port 7 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_7            0x0964  /* Port 7 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_7            0x0968  /* Port 7 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_7           0x096C  /* Port 7 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_7           0x0970  /* Port 7 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV7[4]               0x0974 ~ 0x0980, Reserved 7 */
    #define  PCFGR_8               0x0984  /* Port 8 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_8               0x0988  /* Port 8 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_8               0x098C  /* Port 8 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_8      0x0990  /* Port 8 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_8     0x0994  /* Port 8 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_8      0x0998  /* Port 8 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_8     0x099C  /* Port 8 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_8      0x09A0  /* Port 8 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_8     0x09A4  /* Port 8 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_8      0x09A8  /* Port 8 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_8     0x09AC  /* Port 8 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_8      0x09B0  /* Port 8 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_8     0x09B4  /* Port 8 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_8      0x09B8  /* Port 8 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_8     0x09BC  /* Port 8 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_8      0x09C0  /* Port 8 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_8     0x09C4  /* Port 8 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_8      0x09C8  /* Port 8 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_8     0x09CC  /* Port 8 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_8      0x09D0  /* Port 8 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_8     0x09D4  /* Port 8 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_8      0x09D8  /* Port 8 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_8     0x09DC  /* Port 8 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_8     0x09E0  /* Port 8 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_8    0x09E4  /* Port 8 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_8     0x09E8  /* Port 8 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_8    0x09EC  /* Port 8 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_8     0x09F0  /* Port 8 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_8    0x09F4  /* Port 8 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_8     0x09F8  /* Port 8 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_8    0x09FC  /* Port 8 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_8     0x0A00  /* Port 8 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_8    0x0A04  /* Port 8 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_8     0x0A08  /* Port 8 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_8    0x0A0C  /* Port 8 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_8               0x0A10  /* Port 8 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_8            0x0A14  /* Port 8 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_8            0x0A18  /* Port 8 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_8           0x0A1C  /* Port 8 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_8           0x0A20  /* Port 8 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV8[4]               0x0A24 ~ 0x0A30, Reserved 8 */
    #define  PCFGR_9               0x0A34  /* Port 9 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_9               0x0A38  /* Port 9 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_9               0x0A3C  /* Port 9 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_9      0x0A40  /* Port 9 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_9     0x0A44  /* Port 9 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_9      0x0A48  /* Port 9 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_9     0x0A4C  /* Port 9 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_9      0x0A50  /* Port 9 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_9     0x0A54  /* Port 9 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_9      0x0A58  /* Port 9 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_9     0x0A5C  /* Port 9 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_9      0x0A60  /* Port 9 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_9     0x0A64  /* Port 9 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_9      0x0A68  /* Port 9 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_9     0x0A6C  /* Port 9 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_9      0x0A70  /* Port 9 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_9     0x0A74  /* Port 9 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_9      0x0A78  /* Port 9 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_9     0x0A7C  /* Port 9 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_9      0x0A80  /* Port 9 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_9     0x0A84  /* Port 9 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_9      0x0A88  /* Port 9 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_9     0x0A8C  /* Port 9 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_9     0x0A90  /* Port 9 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_9    0x0A94  /* Port 9 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_9     0x0A98  /* Port 9 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_9    0x0A9C  /* Port 9 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_9     0x0AA0  /* Port 9 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_9    0x0AA4  /* Port 9 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_9     0x0AA8  /* Port 9 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_9    0x0AAC  /* Port 9 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_9     0x0AB0  /* Port 9 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_9    0x0AB4  /* Port 9 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_9     0x0AB8  /* Port 9 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_9    0x0ABC  /* Port 9 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_9               0x0AC0  /* Port 9 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_9            0x0AC4  /* Port 9 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_9            0x0AC8  /* Port 9 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_9           0x0ACC  /* Port 9 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_9           0x0AD0  /* Port 9 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV9[4]               0x0AD4 ~ 0x0AE0, Reserved 9 */
    #define  PCFGR_10              0x0AE4  /* Port 10 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_10              0x0AE8  /* Port 10 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_10              0x0AEC  /* Port 10 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_10     0x0AF0  /* Port 10 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_10    0x0AF4  /* Port 10 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_10     0x0AF8  /* Port 10 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_10    0x0AFC  /* Port 10 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_10     0x0B00  /* Port 10 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_10    0x0B04  /* Port 10 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_10     0x0B08  /* Port 10 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_10    0x0B0C  /* Port 10 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_10     0x0B10  /* Port 10 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_10    0x0B14  /* Port 10 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_10     0x0B18  /* Port 10 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_10    0x0B1C  /* Port 10 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_10     0x0B20  /* Port 10 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_10    0x0B24  /* Port 10 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_10     0x0B28  /* Port 10 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_10    0x0B2C  /* Port 10 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_10     0x0B30  /* Port 10 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_10    0x0B34  /* Port 10 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_10     0x0B38  /* Port 10 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_10    0x0B3C  /* Port 10 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_10    0x0B40  /* Port 10 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_10   0x0B44  /* Port 10 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_10    0x0B48  /* Port 10 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_10   0x0B4C  /* Port 10 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_10    0x0B50  /* Port 10 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_10   0x0B54  /* Port 10 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_10    0x0B58  /* Port 10 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_10   0x0B5C  /* Port 10 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_10    0x0B60  /* Port 10 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_10   0x0B64  /* Port 10 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_10    0x0B68  /* Port 10 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_10   0x0B6C  /* Port 10 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_10              0x0B70  /* Port 10 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_10           0x0B74  /* Port 10 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_10           0x0B78  /* Port 10 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_10          0x0B7C  /* Port 10 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_10          0x0B80  /* Port 10 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV10[4]              0x0B84 ~ 0x0B90, Reserved 10 */
    #define  PCFGR_11              0x0B94  /* Port 11 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_11              0x0B98  /* Port 11 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_11              0x0B9C  /* Port 11 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_11     0x0BA0  /* Port 11 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_11    0x0BA4  /* Port 11 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_11     0x0BA8  /* Port 11 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_11    0x0BAC  /* Port 11 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_11     0x0BB0  /* Port 11 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_11    0x0BB4  /* Port 11 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_11     0x0BB8  /* Port 11 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_11    0x0BBC  /* Port 11 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_11     0x0BC0  /* Port 11 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_11    0x0BC4  /* Port 11 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_11     0x0BC8  /* Port 11 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_11    0x0BCC  /* Port 11 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_11     0x0BD0  /* Port 11 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_11    0x0BD4  /* Port 11 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_11     0x0BD8  /* Port 11 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_11    0x0BDC  /* Port 11 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_11     0x0BE0  /* Port 11 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_11    0x0BE4  /* Port 11 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_11     0x0BE8  /* Port 11 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_11    0x0BEC  /* Port 11 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_11    0x0BF0  /* Port 11 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_11   0x0BF4  /* Port 11 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_11    0x0BF8  /* Port 11 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_11   0x0BFC  /* Port 11 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_11    0x0C00  /* Port 11 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_11   0x0C04  /* Port 11 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_11    0x0C08  /* Port 11 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_11   0x0C0C  /* Port 11 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_11    0x0C10  /* Port 11 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_11   0x0C14  /* Port 11 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_11    0x0C18  /* Port 11 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_11   0x0C1C  /* Port 11 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_11              0x0C20  /* Port 11 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_11           0x0C24  /* Port 11 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_11           0x0C28  /* Port 11 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_11          0x0C2C  /* Port 11 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_11           0x0C30  /* Port 11 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV11[4]              0x0C34 ~ 0x0C40, Reserved 11 */
    #define  PCFGR_12              0x0C44  /* Port 12 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_12              0x0C48  /* Port 12 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_12              0x0C4C  /* Port 12 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_12     0x0C50  /* Port 12 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_12    0x0C54  /* Port 12 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_12     0x0C58  /* Port 12 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_12    0x0C5C  /* Port 12 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_12     0x0C60  /* Port 12 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_12    0x0C64  /* Port 12 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_12     0x0C68  /* Port 12 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_12    0x0C6C  /* Port 12 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_12     0x0C70  /* Port 12 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_12    0x0C74  /* Port 12 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_12     0x0C78  /* Port 12 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_12    0x0C7C  /* Port 12 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_12     0x0C80  /* Port 12 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_12    0x0C84  /* Port 12 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_12     0x0C88  /* Port 12 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_12    0x0C8C  /* Port 12 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_12     0x0C90  /* Port 12 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_12    0x0C94  /* Port 12 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_12     0x0C98  /* Port 12 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_12    0x0C9C  /* Port 12 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_12    0x0CA0  /* Port 12 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_12   0x0CA4  /* Port 12 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_12    0x0CA8  /* Port 12 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_12   0x0CAC  /* Port 12 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_12    0x0CB0  /* Port 12 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_12   0x0CB4  /* Port 12 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_12    0x0CB8  /* Port 12 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_12   0x0CBC  /* Port 12 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_12    0x0CC0  /* Port 12 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_12   0x0CC4  /* Port 12 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_12    0x0CC8  /* Port 12 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_12   0x0CCC  /* Port 12 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_12              0x0CD0  /* Port 12 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_12           0x0CD4  /* Port 12 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_12           0x0CD8  /* Port 12 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_12          0x0CEC  /* Port 12 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_12          0x0CE0  /* Port 12 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV12[4]              0x0CE4 ~ 0x0CF0, Reserved 12 */
    #define  PCFGR_13              0x0CF4  /* Port 13 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_13              0x0CF8  /* Port 13 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_13              0x0CFC  /* Port 13 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_13     0x0D00  /* Port 13 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_13    0x0D04  /* Port 13 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_13     0x0D08  /* Port 13 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_13    0x0D0C  /* Port 13 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_13     0x0D10  /* Port 13 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_13    0x0D14  /* Port 13 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_13     0x0D18  /* Port 13 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_13    0x0D1C  /* Port 13 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_13     0x0D20  /* Port 13 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_13    0x0D24  /* Port 13 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_13     0x0D28  /* Port 13 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_13    0x0D2C  /* Port 13 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_13     0x0D30  /* Port 13 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_13    0x0D34  /* Port 13 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_13     0x0D38  /* Port 13 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_13    0x0D3C  /* Port 13 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_13     0x0D40  /* Port 13 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_13    0x0D44  /* Port 13 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_13     0x0D48  /* Port 13 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_13    0x0D4C  /* Port 13 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_13    0x0D50  /* Port 13 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_13   0x0D54  /* Port 13 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_13    0x0D58  /* Port 13 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_13   0x0D5C  /* Port 13 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_13    0x0D60  /* Port 13 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_13   0x0D64  /* Port 13 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_13    0x0D68  /* Port 13 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_13   0x0D6C  /* Port 13 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_13    0x0D70  /* Port 13 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_13   0x0D74  /* Port 13 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_13    0x0D78  /* Port 13 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_13   0x0D7C  /* Port 13 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_13              0x0D80  /* Port 13 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_13           0x0D84  /* Port 13 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_13           0x0D88  /* Port 13 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_13          0x0D8C  /* Port 13 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_13          0x0D90  /* Port 13 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV13[4]              0x0D94 ~ 0x0DA0, Reserved 13 */
    #define  PCFGR_14              0x0DA4  /* Port 14 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_14              0x0DA8  /* Port 14 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_14              0x0DAC  /* Port 14 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_14     0x0DB0  /* Port 14 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_14    0x0DB4  /* Port 14 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_14     0x0DB8  /* Port 14 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_14    0x0DBC  /* Port 14 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_14     0x0DC0  /* Port 14 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_14    0x0DC4  /* Port 14 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_14     0x0DC8  /* Port 14 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_14    0x0DCC  /* Port 14 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_14     0x0DD0  /* Port 14 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_14    0x0DD4  /* Port 14 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_14     0x0DD8  /* Port 14 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_14    0x0DDC  /* Port 14 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_14     0x0DE0  /* Port 14 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_14    0x0DE4  /* Port 14 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_14     0x0DE8  /* Port 14 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_14    0x0DEC  /* Port 14 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_14     0x0DF0  /* Port 14 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_14    0x0DF4  /* Port 14 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_14     0x0DF8  /* Port 14 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_14    0x0DFC  /* Port 14 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_14    0x0E00  /* Port 14 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_14   0x0E04  /* Port 14 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_14    0x0E08  /* Port 14 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_14   0x0E0C  /* Port 14 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_14    0x0E10  /* Port 14 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_14   0x0E14  /* Port 14 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_14    0x0E18  /* Port 14 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_14   0x0E1C  /* Port 14 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_14    0x0E20  /* Port 14 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_14   0x0E24  /* Port 14 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_14    0x0E28  /* Port 14 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_14   0x0E2C  /* Port 14 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_14              0x0E30  /* Port 14 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_14           0x0E34  /* Port 14 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_14           0x0E38  /* Port 14 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_14          0x0E3C  /* Port 14 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_14          0x0E40  /* Port 14 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 //   #define  RSV14[4]              0x0E44 ~ 0x0E50, Reserved 14 */
    #define  PCFGR_15              0x0E54  /* Port 15 Configuration Read Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGW_15              0x0E58  /* Port 15 Configuration Write Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGC_15              0x0E5C  /* Port 15 Common Configuration Register*/
    #define  PCFGIDMASKCH_0_15     0x0E60  /* Port 15 Channel 0 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_0_15    0x0E64  /* Port 15 Channel 0 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_1_15     0x0E68  /* Port 15 Channel 1 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_1_15    0x0E6C  /* Port 15 Channel 1 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_2_15     0x0E70  /* Port 15 Channel 2 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_2_15    0x0E74  /* Port 15 Channel 2 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_3_15     0x0E78  /* Port 15 Channel 3 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_3_15    0x0E7C  /* Port 15 Channel 3 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_4_15     0x0E80  /* Port 15 Channel 4 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_4_15    0x0E84  /* Port 15 Channel 4 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_5_15     0x0E88  /* Port 15 Channel 5 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_5_15    0x0E8C  /* Port 15 Channel 5 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_6_15     0x0E80  /* Port 15 Channel 6 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_6_15    0x0E94  /* Port 15 Channel 6 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_7_15     0x0E98  /* Port 15 Channel 7 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_7_15    0x0E9C  /* Port 15 Channel 7 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_8_15     0x0EA0  /* Port 15 Channel 8 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_8_15    0x0EA4  /* Port 15 Channel 8 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_9_15     0x0EA8  /* Port 15 Channel 9 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_9_15    0x0EAC  /* Port 15 Channel 9 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_10_15    0x0EB0  /* Port 15 Channel 10 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_10_15   0x0EB4  /* Port 15 Channel 10 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_11_15    0x0EB8  /* Port 15 Channel 11 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_11_15   0x0EBC  /* Port 15 Channel 11 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_12_15    0x0EC0  /* Port 15 Channel 12 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_12_15   0x0EC4  /* Port 15 Channel 12 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_13_15    0x0EC8  /* Port 15 Channel 13 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_13_15   0x0ECC  /* Port 15 Channel 13 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_14_15    0x0ED0  /* Port 15 Channel 14 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_14_15   0x0ED4  /* Port 15 Channel 14 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDMASKCH_15_15    0x0ED8  /* Port 15 Channel 15 Configuration ID Mask Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCFGIDVALUECH_15_15   0x0EDC  /* Port 15 Channel 15 Configuration ID Value Register. Exists: UMCTL2_PORT_CH0_0==1*/
    #define  PCTRL_15              0x0EE0  /* Port 15 Control Register. Exists: UMCTL2_INCL_ARB==1 && UMCTL2_PORT_0==1*/
    #define  PCFGQOS0_15           0x0EE4  /* Port 15 Read QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UPCTL2_EN_1 == 0 */
    #define  PCFGQOS1_15           0x0EE8  /* Port 15 Read QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPR_0==1 */
    #define  PCFGWQOS0_15          0x0EEC  /* Port 15 Write QoS Configuration Register 0. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1*/
    #define  PCFGWQOS1_15          0x0EF0  /* Port 15 Write QoS Configuration Register 1. Exists: UMCTL2_A_AXI_0==1 && UMCTL2_XPI_VPW_0==1 */
 
#endif

#ifndef _KL730_CLKS_H_
#define _KL730_CLKS_H_

#define POWER_VQ7  0
#define POWER_ISPE 0
#define POWER_CDCE 0
#define POWER_EQOS 1
#define POWER_VOC  0
#define POWER_VIC  0
#define POWER_IEU  1
#define POWER_IFPE 0
#define POWER_MIPI 0
#define POWER_MSHC 1

#define POWER_KDPU_MEM 1

#define POWER_CA5U 1
#define POWER_I2CC 1
#define POWER_GPIO 1
#define POWER_GMAC 1
#define POWER_BRC  1
#define POWER_AGPO 1
#define POWER_ACDC 1
#define POWER_IRDA 1
#define POWER_INTC 1
#define POWER_I2SS 1
#define POWER_DDRN 1
#define POWER_MBC  1
#define POWER_KDPU 1
#define POWER_MOD  1
#define POWER_JEBE 1
#define POWER_JDBE 1
#define POWER_PLLC 1
#define POWER_PDMA 1
#define POWER_DMAC 1
#define POWER_UART 1
#define POWER_INTC 1
#define POWER_WDTC 1
#define POWER_TMRC 1
#define POWER_USBC 1
#define POWER_SCRT 1
#define POWER_SSIC 1
#define POWER_SYSC 1
#define POWER_RAMBUS 1
#define POWER_PMU  1

/*  clock_0 */
#define I2CC_2_APB_CLK_OST    (POWER_I2CC == 1 ? 32 : 31)
#define I2CC_1_APB_CLK_OST    (POWER_I2CC == 1 ? 32 : 30)
#define I2CC_0_APB_CLK_OST    (POWER_I2CC == 1 ? 32 : 29)
#define GPIOC_2_APB_CLK_OST   (POWER_GPIO == 1 ? 32 : 28)
#define GPIOC_1_APB_CLK_OST   (POWER_GPIO == 1 ? 32 : 27)
#define GPIOC_0_APB_CLK_OST   (POWER_GPIO == 1 ? 32 : 26)
#define GMAC_TX_CLK_OST       (POWER_GMAC == 1 ? 32 : 25)
#define GMAC_RX_CLK_OST       (POWER_GMAC == 1 ? 32 : 24)
#define GMAC_RMII_CLK_OST     (POWER_GMAC == 1 ? 32 : 23)
#define GMAC_PTP_REF_CLK_OST  (POWER_GMAC == 1 ? 32 : 22)
#define GMAC_AXI_MMR_CLK_OST  (POWER_GMAC == 1 ? 32 : 21)
#define GMAC_AXI_DMA_CLK_OST  (POWER_GMAC == 1 ? 32 : 20)
#define DMAC_1_AHB_CLK_OST    (POWER_DMAC == 1 ? 32 : 19)
#define DMAC_0_AHB_CLK_OST    (POWER_DMAC == 1 ? 32 : 18)
#define CDCE_VCE_CLK_OST      (POWER_CDCE == 1 ? 32 : 17)
#define CDCE_BPU_CLK_OST      (POWER_CDCE == 1 ? 32 : 16)
#define CDCE_AXI_CLK_OST      (POWER_CDCE == 1 ? 32 : 15)
#define CDCE_APB_CLK_OST      (POWER_CDCE == 1 ? 32 : 14)
#define CA55U_SCU_CLK_OST     (POWER_CA5U == 1 ? 32 : 13)
#define CA55U_PERIF_CLK_OST   (POWER_CA5U == 1 ? 32 : 12)
#define CA55U_GIC_CLK_OST     (POWER_CA5U == 1 ? 32 : 11)
#define CA55U_DBG_CLK_OST     (POWER_CA5U == 1 ? 32 : 10)
#define CA55U_CORE_3_CLK_OST  (POWER_CA5U == 1 ? 32 : 9)
#define CA55U_CORE_2_CLK_OST  (POWER_CA5U == 1 ? 32 : 8)
#define CA55U_CORE_1_CLK_OST  (POWER_CA5U == 1 ? 32 : 7)
#define CA55U_CORE_0_CLK_OST  (POWER_CA5U == 1 ? 32 : 6)
#define CA55U_AXI_CLK_OST     (POWER_CA5U == 1 ? 32 : 5)
#define BRC_AXI_CLK_OST       (POWER_BRC == 1 ? 32 : 4)
#define AGPOC_APB_CLK_OST     POWER_AGPO == 1 ? 32 : (3)
#define ADCDCC_TX_MAS_CLK_OST (POWER_ACDC == 1 ? 32 : 2)
#define ADCDCC_RX_MAS_CLK_OST (POWER_ACDC == 1 ? 32 : 1)
#define ADCDCC_APB_CLK_OST    (POWER_ACDC == 1 ? 32 : 0)

/*  clock_1 */
#define IRDAC_APB_CLK_OST          (POWER_IRDA == 1 ? 32 : 31)
#define INTC_APB_CLK_OST           (POWER_INTC == 1 ? 32 : 30)

#define IFPE_APB_CLK_OST           (POWER_IFPE == 1 ? 32 : 28)
#define IEU_1_AXI_CLK_OST          (POWER_IEU == 1 ? 32 : 27)
#define IEU_1_APB_CLK_OST          (POWER_IEU == 1 ? 32 : 26)
#define IEU_0_AXI_CLK_OST          (POWER_IEU == 1 ? 32 : 25)
#define IEU_0_APB_CLK_OST          (POWER_IEU == 1 ? 32 : 24)
#define I2SSC_TX_SER_CLK_OST       (POWER_I2SS == 1 ? 32 : 23)
#define I2SSC_RX_SER_CLK_OST       (POWER_I2SS == 1 ? 32 : 22)
#define I2SSC_APB_CLK_OST          (POWER_I2SS == 1 ? 32 : 21)
#define DDRNSDMC_PUB_APB_CLK_OST   (POWER_DDRN == 1 ? 32 : 20)
#define DDRNSDMC_MCTL_APB_CLK_OST  (POWER_DDRN == 1 ? 32 : 19)
#define DDRNSDMC_DPM_15_CLK_OST    (POWER_DDRN == 1 ? 32 : 18)
#define DDRNSDMC_DPM_14_CLK_OST    (POWER_DDRN == 1 ? 32 : 17)
#define DDRNSDMC_DPM_13_CLK_OST    (POWER_DDRN == 1 ? 32 : 16)
#define DDRNSDMC_DPM_12_CLK_OST    (POWER_DDRN == 1 ? 32 : 15)
#define DDRNSDMC_DPM_11_CLK_OST    (POWER_DDRN == 1 ? 32 : 14)
#define DDRNSDMC_DPM_10_CLK_OST    (POWER_DDRN == 1 ? 32 : 13)
#define DDRNSDMC_DPM_9_CLK_OST     (POWER_DDRN == 1 ? 32 : 12)
#define DDRNSDMC_DPM_8_CLK_OST     (POWER_DDRN == 1 ? 32 : 11)
#define DDRNSDMC_DPM_7_CLK_OST     (POWER_DDRN == 1 ? 32 : 10)
#define DDRNSDMC_DPM_6_CLK_OST     (POWER_DDRN == 1 ? 32 : 9)
#define DDRNSDMC_DPM_5_CLK_OST     (POWER_DDRN == 1 ? 32 : 8)
#define DDRNSDMC_DPM_4_CLK_OST     (POWER_DDRN == 1 ? 32 : 7)
#define DDRNSDMC_DPM_3_CLK_OST     (POWER_DDRN == 1 ? 32 : 6)
#define DDRNSDMC_DPM_2_CLK_OST     (POWER_DDRN == 1 ? 32 : 5)
#define DDRNSDMC_DPM_1_CLK_OST     (POWER_DDRN == 1 ? 32 : 4)
#define DDRNSDMC_DPM_0_CLK_OST     (POWER_DDRN == 1 ? 32 : 3)
#define DDRNSDMC_AXI_CLK_OST       (POWER_DDRN == 1 ? 32 : 2)
#define DDRNSDMC_APM_APB_CLK_OST   (POWER_DDRN == 1 ? 32 : 1)
#define DDRNSDMC_MMR_APB_CLK_OST   (POWER_DDRN == 1 ? 32 : 0)

/*  clock_2 */
#define MIPIRC_0_PHY_CLK_OST          (POWER_MIPI == 1 ? 32 : 29)
#define MIPIRC_0_DEV_1_PHY_1_CLK_OST  (POWER_MIPI == 1 ? 32 : 28)
#define MIPIRC_0_DEV_1_PEL_CLK_OST    (POWER_MIPI == 1 ? 32 : 27)
#define MIPIRC_0_DEV_1_APB_CLK_OST    (POWER_MIPI == 1 ? 32 : 26)
#define MIPIRC_0_DEV_0_PHY_1_CLK_OST  (POWER_MIPI == 1 ? 32 : 25)
#define MIPIRC_0_DEV_0_PHY_0_CLK_OST  (POWER_MIPI == 1 ? 32 : 24)
#define MIPIRC_0_DEV_0_PEL_CLK_OST    (POWER_MIPI == 1 ? 32 : 23)
#define MIPIRC_0_DEV_0_APB_CLK_OST    (POWER_MIPI == 1 ? 32 : 22)
#define MIPIRC_0_CMN_PEL_CLK_OST      (POWER_MIPI == 1 ? 32 : 21)
#define MIPIRC_0_APB_MMR_CLK_OST      (POWER_MIPI == 1 ? 32 : 20)
#define MEM_MOD_BASE_CLK_OST          (POWER_MBC == 1 ? 32 : 19)
#define MBC_XBUS_3_KRN_CLK_OST        (POWER_MBC == 1 ? 32 : 18)
#define MBC_XBUS_2_MAS_CLK_OST        (POWER_MBC == 1 ? 32 : 17)
#define MBC_PBUS_6_SLV_CLK_OST        (POWER_MBC == 1 ? 32 : 16)
#define MBC_PBUS_5_SLV_CLK_OST        (POWER_MBC == 1 ? 32 : 15)
#define MBC_PBUS_2_SLV_CLK_OST        (POWER_MBC == 1 ? 32 : 14)
#define MBC_PBUS_1_SLV_CLK_OST        (POWER_MBC == 1 ? 32 : 13)
#define MBC_HBUS_1_SLV_CLK_OST        (POWER_MBC == 1 ? 32 : 12)
#define MBC_AXI_DDR_CLK_OST           (POWER_MBC == 1 ? 32 : 11)
#define MBC_AXI_CTL_CLK_OST           (POWER_MBC == 1 ? 32 : 10)
#define MBC_APB_CLK_OST               (POWER_MBC == 1 ? 32 : 9)
#define KDPU_CORE_CLK_OST             (POWER_KDPU == 1 ? 32 : 8)
#define KDPU_AXI_CLK_OST              (POWER_KDPU == 1 ? 32 : 7)
#define KDPU_APB_CLK_OST              (POWER_KDPU == 1 ? 32 : 6)
#define JEBE_CLK_OST                  (POWER_JEBE == 1 ? 32 : 5)
#define JDBE_CLK_OST                  (POWER_JEBE == 1 ? 32 : 4)
#define ISPE_GTR_CLK_OST              (POWER_ISPE == 1 ? 32 : 3)
#define ISPE_DAXI_CLK_OST             (POWER_ISPE == 1 ? 32 : 2)
#define ISPE_CACHE_CLK_OST            (POWER_ISPE == 1 ? 32 : 1)
#define ISPE_APB_CLK_OST              (POWER_ISPE == 1 ? 32 : 0)

/*  clock_3 */
#define PLLC_APB_CLK_OST                   (POWER_PLLC == 1 ? 32 : 31)
#define PDMAC_AXI_DDR_CLK_OST              (POWER_PDMA == 1 ? 32 : 30)
#define PDMAC_APB_CLK_OST                  (POWER_MSHC == 1 ? 32 : 29)
#define MSHC_DEV_1_TX_CLK_OST              (POWER_MSHC == 1 ? 32 : 28)
#define MSHC_DEV_1_TM_CLK_OST              (POWER_MSHC == 1 ? 32 : 27)
#define MSHC_DEV_1_CQETM_CLK_OST           (POWER_MSHC == 1 ? 32 : 26)
#define MSHC_DEV_1_BASE_CLK_OST            (POWER_MSHC == 1 ? 32 : 25)
#define MSHC_DEV_1_AXI_CLK_OST             (POWER_MSHC == 1 ? 32 : 24)
#define MSHC_DEV_1_AHB_CLK_OST             (POWER_MSHC == 1 ? 32 : 23)
#define MSHC_DEV_0_TX_CLK_OST              (POWER_MSHC == 1 ? 32 : 22)
#define MSHC_DEV_0_TM_CLK_OST              (POWER_MSHC == 1 ? 32 : 21)
#define MSHC_DEV_0_LBT_CLK_OST             (POWER_MSHC == 1 ? 32 : 20)
#define MSHC_DEV_0_CQETM_CLK_OST           (POWER_MSHC == 1 ? 32 : 19)
#define MSHC_DEV_0_BASE_CLK_OST            (POWER_MSHC == 1 ? 32 : 18)
#define MSHC_DEV_0_AXI_CLK_OST             (POWER_MSHC == 1 ? 32 : 17)
#define MSHC_DEV_0_AHB_CLK_OST             (POWER_MSHC == 1 ? 32 : 16)
#define MIPITC_PHY_BYTE_CLK_OST            (POWER_MIPI == 1 ? 32 : 15)
#define MIPITC_PHY_CLK_OST                 (POWER_MIPI == 1 ? 32 : 14)
#define MIPITC_PEL_CLK_OST                 (POWER_MIPI == 1 ? 32 : 13)
#define MIPITC_DSI_APB_CLK_OST             (POWER_MIPI == 1 ? 32 : 12)
#define MIPITC_CSI2_APB_CLK_OST            (POWER_MIPI == 1 ? 32 : 11)
#define MIPITC_APB_MMR_CLK_OST             (POWER_MIPI == 1 ? 32 : 10)
#define MIPIRC_1_PHY_CLK_OST               (POWER_MIPI == 1 ? 32 : 9)
#define MIPIRC_1_DEV_1_PHY_BYTE_CLK_OST    (POWER_MIPI == 1 ? 32 : 8)
#define MIPIRC_1_DEV_1_PEL_CLK_OST         (POWER_MIPI == 1 ? 32 : 7)
#define MIPIRC_1_DEV_1_APB_CLK_OST         (POWER_MIPI == 1 ? 32 : 6)
#define MIPIRC_1_DEV_0_PHY_1_BYTE_CLK_OST  (POWER_MIPI == 1 ? 32 : 5)
#define MIPIRC_1_DEV_0_PHY_0_BYTE_CLK_OST  (POWER_MIPI == 1 ? 32 : 4)
#define MIPIRC_1_DEV_0_PEL_CLK_OST         (POWER_MIPI == 1 ? 32 : 3)
#define MIPIRC_1_DEV_0_APB_CLK_OST         (POWER_MIPI == 1 ? 32 : 2)
#define MIPIRC_1_CMN_PEL_CLK_OST           (POWER_MIPI == 1 ? 32 : 1)
#define MIPIRC_1_APB_MMR_CLK_OST           (POWER_MIPI == 1 ? 32 : 0)

/*  clock_4 */
#define USB20C_UTMI_CLK_OST   (POWER_USBC == 1 ? 32 : 26)
#define USB20C_RAM_CLK_OST    (POWER_USBC == 1 ? 32 : 25)
#define USB20C_PHY_CLK_OST    (POWER_USBC == 1 ? 32 : 24)
#define USB20C_AXI_CLK_OST    (POWER_USBC == 1 ? 32 : 23)
#define USB20C_APB_CLK_OST    (POWER_USBC == 1 ? 32 : 22)
#define UARTC_4_CORE_CLK_OST  (POWER_UART == 1 ? 32 : 21)
#define UARTC_4_APB_CLK_OST   (POWER_UART == 1 ? 32 : 20)
#define UARTC_3_CORE_CLK_OST  (POWER_UART == 1 ? 32 : 19)
#define UARTC_3_APB_CLK_OST   (POWER_UART == 1 ? 32 : 18)
#define UARTC_2_CORE_CLK_OST  (POWER_UART == 1 ? 32 : 17)
#define UARTC_2_APB_CLK_OST   (POWER_UART == 1 ? 32 : 16)
#define UARTC_1_CORE_CLK_OST  (POWER_UART == 1 ? 32 : 15)
#define UARTC_1_APB_CLK_OST   (POWER_UART == 1 ? 32 : 14)
#define UARTC_0_CORE_CLK_OST  (POWER_UART == 1 ? 32 : 13)
#define UARTC_0_APB_CLK_OST   (POWER_UART == 1 ? 32 : 12)
#define TMRC_APB_CLK_OST      (POWER_TMRC == 1 ? 32 : 11)
#define SYSC_APB_CLK_OST      (POWER_SYSC == 1 ? 32 : 10)
#define SSIC_3_APB_CLK_OST    (POWER_SSIC == 1 ? 32 : 9)
#define SSIC_2_APB_CLK_OST    (POWER_SSIC == 1 ? 32 : 8)
#define SSIC_1_APB_CLK_OST    (POWER_SSIC == 1 ? 32 : 7)
#define SSIC_0_APB_CLK_OST    (POWER_SSIC == 1 ? 32 : 6)
#define XTL_CLK_OST           (POWER_RAMBUS == 1 ? 32 : 5)
#define CTR_CLK_OST           (POWER_RAMBUS == 1 ? 32 : 4)
#define AXI_DMA_CLK_OST       (POWER_RAMBUS == 1 ? 32 : 3)
#define AXI_CTL_CLK_OST       (POWER_RAMBUS == 1 ? 32 : 2)
#define PMU_BASE_CLK_OST      (POWER_PMU == 1 ? 32 : 1)
#define PMU_APB_CLK_OST       (POWER_PMU == 1 ? 32 : 0)

/*  clock_5 */
#define WDTC_APB_CLK_OST       (POWER_WDTC == 1 ? 32 : 20)
#define VQ7U_CORE_CLK_OST      (POWER_VQ7 == 1 ? 32 : 19)
#define VQ7U_AXI_DMA_CLK_OST   (POWER_VQ7 == 1 ? 32 : 18)
#define VQ7U_AXI_CTL_CLK_OST   (POWER_VQ7 == 1 ? 32 : 17)
#define VOC_1_PEL_CLK_OST      (POWER_VOC == 1 ? 32 : 16)
#define VOC_1_DAXI_CLK_OST     (POWER_VOC == 1 ? 32 : 15)
#define VOC_1_APB_CLK_OST      (POWER_VOC == 1 ? 32 : 14)
#define VOC_0_PEL_CLK_OST      (POWER_VOC == 1 ? 32 : 13)
#define VOC_0_DAXI_CLK_OST     (POWER_VOC == 1 ? 32 : 12)
#define VOC_0_APB_CLK_OST      (POWER_VOC == 1 ? 32 : 11)
#define VIC_TGEN_CLK_OST       (POWER_VIC == 1 ? 32 : 10)
#define VIC_DEV_1_PEL_CLK_OST  (POWER_VIC == 1 ? 32 : 9)
#define VIC_DEV_0_PEL_CLK_OST  (POWER_VIC == 1 ? 32 : 8)

#define VIC_APB_CLK_OST        (POWER_VIC == 1 ? 32 : 6)
#define USB30C_UTMI_CLK_OST    (POWER_USBC == 1 ? 32 : 5)
#define USB30C_RAM_CLK_OST     (POWER_USBC == 1 ? 32 : 4)
#define USB30C_PIPE_CLK_OST    (POWER_USBC == 1 ? 32 : 3)
#define USB30C_PHY_CLK_OST     (POWER_USBC == 1 ? 32 : 2)
#define USB30C_AXI_CLK_OST     (POWER_USBC == 1 ? 32 : 1)
#define USB30C_APB_CLK_OST     (POWER_USBC == 1 ? 32 : 0)

#define VOC_0_MEM_PWR        (POWER_VOC == 1 ? 32 : 31)
#define VIC_MEM_PWR          (POWER_VIC == 1 ? 32 : 30)
#define USB30C_MEM_PWR       (POWER_USBC == 1 ? 32 : 29)
#define USB20C_MEM_PWR       (POWER_USBC == 1 ? 32 : 28)
#define RAMBUS_MEM_PWR       (POWER_RAMBUS == 1 ? 32 : 27)
#define PDMAC_MEM_PWR        (POWER_PDMA == 1 ? 32 : 26)
#define MSHC_DEV_1_MEM_PWR   (POWER_MSHC == 1 ? 32 : 25)
#define MSHC_DEV_0_MEM_PWR   (POWER_MSHC == 1 ? 32 : 24)
#define MIPITC_MEM_PWR       (POWER_MIPI == 1 ? 32 : 23)
#define MIPIRC_1_MEM_PWR     (POWER_MIPI == 1 ? 32 : 22)
#define MIPIRC_0_MEM_PWR     (POWER_MIPI == 1 ? 32 : 21)
#define MBC_MEM_PWR          (POWER_MBC == 1 ? 32 : 20)
#define KDPU_MEM_PWR         (POWER_KDPU_MEM == 1 ? 32 : 19)
#define JEBE_MEM_PWR         (POWER_JEBE == 1 ? 32 : 18)
#define JDBE_MEM_PWR         (POWER_JDBE == 1 ? 32 : 17)
#define ISPE_MEM_PWR         (POWER_ISPE == 1 ? 32 : 16)
#define IFPE_MEM_PWR         (POWER_IFPE == 1 ? 32 : 15)
#define IEU_1_MEM_PWR        (POWER_IEU == 1 ? 32 : 14)
#define IEU_0_MEM_PWR        (POWER_IEU == 1 ? 32 : 13)
#define GMAC_MEM_PWR         (POWER_GMAC == 1 ? 32 : 12)
#define DMAC_1_MEM_PWR       (POWER_DMAC == 1 ? 32 : 11)
#define DMAC_0_MEM_PWR       (POWER_DMAC == 1 ? 32 : 10)
#define DDRNSDMC_MEM_PWR     (POWER_DDRN == 1 ? 32 : 9)
#define CDCE_MEM_PWR         (POWER_CDCE == 1 ? 32 : 8)
#define CA55U_GIC600_MEM_PWR (POWER_CA5U == 1 ? 32 : 7)
#define CA55U_DSU_MEM_PWR    (POWER_CA5U == 1 ? 32 : 6)
#define CA55U_CORE_3_MEM_PWR (POWER_CA5U == 1 ? 32 : 5)
#define CA55U_CORE_2_MEM_PWR (POWER_CA5U == 1 ? 32 : 4)
#define CA55U_CORE_1_MEM_PWR (POWER_CA5U == 1 ? 32 : 3)
#define CA55U_CORE_0_MEM_PWR (POWER_CA5U == 1 ? 32 : 2)
#define BRC_ROM_PWR          (POWER_BRC == 1 ? 32 : 1)
#define BRC_MEM_PWR          (POWER_BRC == 1 ? 32 : 0)

#define VQ7U_MEM_PWR         (POWER_VQ7 == 1 ? 32 : 1)
#define VOC_1_MEM_PWR        (POWER_VOC == 1 ? 32 : 0)

#define LOC(x)               ((x > 31) ? 0 : BIT(x))

#define SYSC_CLK_EN_0       (\
				LOC(I2CC_2_APB_CLK_OST)     |\
				LOC(I2CC_1_APB_CLK_OST)     |\
				LOC(I2CC_0_APB_CLK_OST)     |\
				LOC(GPIOC_2_APB_CLK_OST)    |\
				LOC(GPIOC_1_APB_CLK_OST)    |\
				LOC(GPIOC_0_APB_CLK_OST)    |\
				LOC(GMAC_TX_CLK_OST)        |\
				LOC(GMAC_RX_CLK_OST)        |\
				LOC(GMAC_RMII_CLK_OST)      |\
				LOC(GMAC_PTP_REF_CLK_OST)   |\
				LOC(GMAC_AXI_MMR_CLK_OST)   |\
				LOC(GMAC_AXI_DMA_CLK_OST)   |\
				LOC(DMAC_1_AHB_CLK_OST)     |\
				LOC(DMAC_0_AHB_CLK_OST)     |\
				LOC(CDCE_VCE_CLK_OST)       |\
				LOC(CDCE_BPU_CLK_OST)       |\
				LOC(CDCE_AXI_CLK_OST)       |\
				LOC(CDCE_APB_CLK_OST)       |\
				LOC(CA55U_SCU_CLK_OST)      |\
				LOC(CA55U_PERIF_CLK_OST)    |\
				LOC(CA55U_GIC_CLK_OST)      |\
				LOC(CA55U_DBG_CLK_OST)      |\
				LOC(CA55U_CORE_3_CLK_OST)   |\
				LOC(CA55U_CORE_2_CLK_OST)   |\
				LOC(CA55U_CORE_1_CLK_OST)   |\
				LOC(CA55U_CORE_0_CLK_OST)   |\
				LOC(CA55U_AXI_CLK_OST)      |\
				LOC(BRC_AXI_CLK_OST)        |\
				LOC(AGPOC_APB_CLK_OST)      |\
				LOC(ADCDCC_TX_MAS_CLK_OST)  |\
				LOC(ADCDCC_RX_MAS_CLK_OST)  |\
				LOC(ADCDCC_APB_CLK_OST)\
				)

#define SYSC_CLK_EN_1       (\
				LOC(IRDAC_APB_CLK_OST)          |\
				LOC(INTC_APB_CLK_OST)           |\
				LOC(IFPE_APB_CLK_OST)          |\
				LOC(IEU_1_AXI_CLK_OST)         |\
				LOC(IEU_1_APB_CLK_OST)         |\
				LOC(IEU_0_AXI_CLK_OST)         |\
				LOC(IEU_0_APB_CLK_OST)         |\
				LOC(I2SSC_TX_SER_CLK_OST)      |\
				LOC(I2SSC_RX_SER_CLK_OST)      |\
				LOC(I2SSC_APB_CLK_OST)         |\
				LOC(DDRNSDMC_PUB_APB_CLK_OST)  |\
				LOC(DDRNSDMC_MCTL_APB_CLK_OST) |\
				LOC(DDRNSDMC_DPM_15_CLK_OST)   |\
				LOC(DDRNSDMC_DPM_14_CLK_OST)   |\
				LOC(DDRNSDMC_DPM_13_CLK_OST)   |\
				LOC(DDRNSDMC_DPM_12_CLK_OST)   |\
				LOC(DDRNSDMC_DPM_11_CLK_OST)   |\
				LOC(DDRNSDMC_DPM_10_CLK_OST)   |\
				LOC(DDRNSDMC_DPM_9_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_8_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_7_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_6_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_5_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_4_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_3_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_2_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_1_CLK_OST)    |\
				LOC(DDRNSDMC_DPM_0_CLK_OST)    |\
				LOC(DDRNSDMC_AXI_CLK_OST)      |\
				LOC(DDRNSDMC_APM_APB_CLK_OST)  |\
				LOC(DDRNSDMC_MMR_APB_CLK_OST)\
				)

#define SYSC_CLK_EN_2       (\
				LOC(MIPIRC_0_PHY_CLK_OST)         |\
				LOC(MIPIRC_0_DEV_1_PHY_1_CLK_OST) |\
				LOC(MIPIRC_0_DEV_1_PEL_CLK_OST)   |\
				LOC(MIPIRC_0_DEV_1_APB_CLK_OST)   |\
				LOC(MIPIRC_0_DEV_0_PHY_1_CLK_OST) |\
				LOC(MIPIRC_0_DEV_0_PHY_0_CLK_OST) |\
				LOC(MIPIRC_0_DEV_0_PEL_CLK_OST)   |\
				LOC(MIPIRC_0_DEV_0_APB_CLK_OST)   |\
				LOC(MIPIRC_0_CMN_PEL_CLK_OST)     |\
				LOC(MIPIRC_0_APB_MMR_CLK_OST)     |\
				LOC(MEM_MOD_BASE_CLK_OST)         |\
				LOC(MBC_XBUS_3_KRN_CLK_OST)       |\
				LOC(MBC_XBUS_2_MAS_CLK_OST)       |\
				LOC(MBC_PBUS_6_SLV_CLK_OST)       |\
				LOC(MBC_PBUS_5_SLV_CLK_OST)       |\
				LOC(MBC_PBUS_2_SLV_CLK_OST)       |\
				LOC(MBC_PBUS_1_SLV_CLK_OST)       |\
				LOC(MBC_HBUS_1_SLV_CLK_OST)       |\
				LOC(MBC_AXI_DDR_CLK_OST)          |\
				LOC(MBC_AXI_CTL_CLK_OST)          |\
				LOC(MBC_APB_CLK_OST)              |\
				LOC(KDPU_CORE_CLK_OST)            |\
				LOC(KDPU_AXI_CLK_OST)             |\
				LOC(KDPU_APB_CLK_OST)             |\
				LOC(JEBE_CLK_OST)                 |\
				LOC(JDBE_CLK_OST)                 |\
				LOC(ISPE_GTR_CLK_OST)             |\
				LOC(ISPE_DAXI_CLK_OST)            |\
				LOC(ISPE_CACHE_CLK_OST)           |\
				LOC(ISPE_APB_CLK_OST)\
				)

#define SYSC_CLK_EN_3       (\
				LOC(PLLC_APB_CLK_OST)                  |\
				LOC(PDMAC_AXI_DDR_CLK_OST)             |\
				LOC(PDMAC_APB_CLK_OST)                 |\
				LOC(MSHC_DEV_1_TX_CLK_OST)             |\
				LOC(MSHC_DEV_1_TM_CLK_OST)             |\
				LOC(MSHC_DEV_1_CQETM_CLK_OST)          |\
				LOC(MSHC_DEV_1_BASE_CLK_OST)           |\
				LOC(MSHC_DEV_1_AXI_CLK_OST)            |\
				LOC(MSHC_DEV_1_AHB_CLK_OST)            |\
				LOC(MSHC_DEV_0_TX_CLK_OST)             |\
				LOC(MSHC_DEV_0_TM_CLK_OST)             |\
				LOC(MSHC_DEV_0_LBT_CLK_OST)            |\
				LOC(MSHC_DEV_0_CQETM_CLK_OST)          |\
				LOC(MSHC_DEV_0_BASE_CLK_OST)           |\
				LOC(MSHC_DEV_0_AXI_CLK_OST)            |\
				LOC(MSHC_DEV_0_AHB_CLK_OST)            |\
				LOC(MIPITC_PHY_BYTE_CLK_OST)           |\
				LOC(MIPITC_PHY_CLK_OST)                |\
				LOC(MIPITC_PEL_CLK_OST)                |\
				LOC(MIPITC_DSI_APB_CLK_OST)            |\
				LOC(MIPITC_CSI2_APB_CLK_OST)           |\
				LOC(MIPITC_APB_MMR_CLK_OST)            |\
				LOC(MIPIRC_1_PHY_CLK_OST)              |\
				LOC(MIPIRC_1_DEV_1_PHY_BYTE_CLK_OST)   |\
				LOC(MIPIRC_1_DEV_1_PEL_CLK_OST)        |\
				LOC(MIPIRC_1_DEV_1_APB_CLK_OST)        |\
				LOC(MIPIRC_1_DEV_0_PHY_1_BYTE_CLK_OST) |\
				LOC(MIPIRC_1_DEV_0_PHY_0_BYTE_CLK_OST) |\
				LOC(MIPIRC_1_DEV_0_PEL_CLK_OST)        |\
				LOC(MIPIRC_1_DEV_0_APB_CLK_OST)        |\
				LOC(MIPIRC_1_CMN_PEL_CLK_OST)          |\
				LOC(MIPIRC_1_APB_MMR_CLK_OST)\
								)

#define SYSC_CLK_EN_4       (\
				LOC(USB20C_UTMI_CLK_OST)  |\
				LOC(USB20C_RAM_CLK_OST)   |\
				LOC(USB20C_PHY_CLK_OST)   |\
				LOC(USB20C_AXI_CLK_OST)   |\
				LOC(USB20C_APB_CLK_OST)   |\
				LOC(UARTC_4_CORE_CLK_OST) |\
				LOC(UARTC_4_APB_CLK_OST)  |\
				LOC(UARTC_3_CORE_CLK_OST) |\
				LOC(UARTC_3_APB_CLK_OST)  |\
				LOC(UARTC_2_CORE_CLK_OST) |\
				LOC(UARTC_2_APB_CLK_OST)  |\
				LOC(UARTC_1_CORE_CLK_OST) |\
				LOC(UARTC_1_APB_CLK_OST)  |\
				LOC(UARTC_0_CORE_CLK_OST) |\
				LOC(UARTC_0_APB_CLK_OST)  |\
				LOC(TMRC_APB_CLK_OST)     |\
				LOC(SYSC_APB_CLK_OST)     |\
				LOC(SSIC_3_APB_CLK_OST)   |\
				LOC(SSIC_2_APB_CLK_OST)   |\
				LOC(SSIC_1_APB_CLK_OST)   |\
				LOC(SSIC_0_APB_CLK_OST)   |\
				LOC(XTL_CLK_OST)          |\
				LOC(CTR_CLK_OST)          |\
				LOC(AXI_DMA_CLK_OST)      |\
				LOC(AXI_CTL_CLK_OST)      |\
				LOC(PMU_BASE_CLK_OST)     |\
				LOC(PMU_APB_CLK_OST)\
								)

#define SYSC_CLK_EN_5       (\
				LOC(WDTC_APB_CLK_OST)      |\
				LOC(VQ7U_CORE_CLK_OST)     |\
				LOC(VQ7U_AXI_DMA_CLK_OST)  |\
				LOC(VQ7U_AXI_CTL_CLK_OST)  |\
				LOC(VOC_1_PEL_CLK_OST)     |\
				LOC(VOC_1_DAXI_CLK_OST)    |\
				LOC(VOC_1_APB_CLK_OST)     |\
				LOC(VOC_0_PEL_CLK_OST)     |\
				LOC(VOC_0_DAXI_CLK_OST)    |\
				LOC(VOC_0_APB_CLK_OST)     |\
				LOC(VIC_TGEN_CLK_OST)      |\
				LOC(VIC_DEV_1_PEL_CLK_OST) |\
				LOC(VIC_DEV_0_PEL_CLK_OST) |\
				LOC(VIC_APB_CLK_OST)       |\
				LOC(USB30C_UTMI_CLK_OST)   |\
				LOC(USB30C_RAM_CLK_OST)    |\
				LOC(USB30C_PIPE_CLK_OST)   |\
				LOC(USB30C_PHY_CLK_OST)    |\
				LOC(USB30C_AXI_CLK_OST)    |\
				LOC(USB30C_APB_CLK_OST)\
								)

#define SYSC_MEM_PWR_DOWN_0 (\
				LOC(VOC_0_MEM_PWR)        |\
				LOC(VIC_MEM_PWR)          |\
				LOC(USB30C_MEM_PWR)       |\
				LOC(USB20C_MEM_PWR)       |\
				LOC(RAMBUS_MEM_PWR)       |\
				LOC(PDMAC_MEM_PWR)        |\
				LOC(MSHC_DEV_1_MEM_PWR)   |\
				LOC(MSHC_DEV_0_MEM_PWR)   |\
				LOC(MIPITC_MEM_PWR)       |\
				LOC(MIPIRC_1_MEM_PWR)     |\
				LOC(MIPIRC_0_MEM_PWR)     |\
				LOC(MBC_MEM_PWR)          |\
				LOC(KDPU_MEM_PWR)         |\
				LOC(JEBE_MEM_PWR)         |\
				LOC(JDBE_MEM_PWR)         |\
				LOC(ISPE_MEM_PWR)         |\
				LOC(IFPE_MEM_PWR)         |\
				LOC(IEU_1_MEM_PWR)        |\
				LOC(IEU_0_MEM_PWR)        |\
				LOC(GMAC_MEM_PWR)         |\
				LOC(DMAC_1_MEM_PWR)       |\
				LOC(DMAC_0_MEM_PWR)       |\
				LOC(DDRNSDMC_MEM_PWR)     |\
				LOC(CDCE_MEM_PWR)         |\
				LOC(CA55U_GIC600_MEM_PWR) |\
				LOC(CA55U_DSU_MEM_PWR)    |\
				LOC(CA55U_CORE_3_MEM_PWR) |\
				LOC(CA55U_CORE_2_MEM_PWR) |\
				LOC(CA55U_CORE_1_MEM_PWR) |\
				LOC(CA55U_CORE_0_MEM_PWR) |\
				LOC(BRC_ROM_PWR)          |\
				LOC(BRC_MEM_PWR)\
								)

#define SYSC_MEM_PWR_DOWN_1          (\
				LOC(VQ7U_MEM_PWR) |\
				LOC(VOC_1_MEM_PWR)\
								)

/*  clock_0 */
#define I2CC_2_APB_CLK_EN    (31)
#define I2CC_1_APB_CLK_EN    (30)
#define I2CC_0_APB_CLK_EN    (29)
#define GPIOC_2_APB_CLK_EN   (28)
#define GPIOC_1_APB_CLK_EN   (27)
#define GPIOC_0_APB_CLK_EN   (26)
#define GMAC_TX_CLK_EN       (25)
#define GMAC_RX_CLK_EN       (24)
#define GMAC_RMII_CLK_EN     (23)
#define GMAC_PTP_REF_CLK_EN  (22)
#define GMAC_AXI_MMR_CLK_EN  (21)
#define GMAC_AXI_DMA_CLK_EN  (20)
#define DMAC_1_AHB_CLK_EN    (19)
#define DMAC_0_AHB_CLK_EN    (18)
#define CDCE_VCE_CLK_EN	     (17)
#define CDCE_BPU_CLK_EN	     (16)
#define CDCE_AXI_CLK_EN	     (15)
#define CDCE_APB_CLK_EN	     (14)
#define CA55U_SCU_CLK_EN     (13)
#define CA55U_PERIF_CLK_EN   (12)
#define CA55U_GIC_CLK_EN     (11)
#define CA55U_DBG_CLK_EN     (10)
#define CA55U_CORE_3_CLK_EN  (9)
#define CA55U_CORE_2_CLK_EN  (8)
#define CA55U_CORE_1_CLK_EN  (7)
#define CA55U_CORE_0_CLK_EN  (6)
#define CA55U_AXI_CTL_EN     (5)
#define BRC_AXI_CLK_EN       (4)
#define AGPOC_APB_CLK_EN     (3)
#define ADCDCC_TX_MAS_CLK_EN (2)
#define ADCDCC_RX_MAS_CLK_EN (1)
#define ADCDCC_APB_CLK_EN    (0)

/*  clock_1 */
#define IRDAC_APB_CLK_EN          ((1 << 5) | 31)
#define INTC_APB_CLK_EN           ((1 << 5) | 30)

#define IFPE_APB_CLK_EN           ((1 << 5) | 28)
#define IEU_1_AXI_CLK_EN          ((1 << 5) | 27)
#define IEU_1_APB_CLK_EN          ((1 << 5) | 26)
#define IEU_0_AXI_CLK_EN          ((1 << 5) | 25)
#define IEU_0_APB_CLK_EN          ((1 << 5) | 24)
#define I2SSC_TX_SER_CLK_EN       ((1 << 5) | 23)
#define I2SSC_RX_SER_CLK_EN       ((1 << 5) | 22)
#define I2SSC_APB_CLK_EN          ((1 << 5) | 21)
#define DDRNSDMC_PUB_APB_CLK_EN   ((1 << 5) | 20)
#define DDRNSDMC_MCTL_APB_CLK_EN  ((1 << 5) | 19)
#define DDRNSDMC_DPM_15_CLK_EN    ((1 << 5) | 18)
#define DDRNSDMC_DPM_14_CLK_EN    ((1 << 5) | 17)
#define DDRNSDMC_DPM_13_CLK_EN    ((1 << 5) | 16)
#define DDRNSDMC_DPM_12_CLK_EN    ((1 << 5) | 15)
#define DDRNSDMC_DPM_11_CLK_EN    ((1 << 5) | 14)
#define DDRNSDMC_DPM_10_CLK_EN    ((1 << 5) | 13)
#define DDRNSDMC_DPM_9_CLK_EN     ((1 << 5) | 12)
#define DDRNSDMC_DPM_8_CLK_EN     ((1 << 5) | 11)
#define DDRNSDMC_DPM_7_CLK_EN     ((1 << 5) | 10)
#define DDRNSDMC_DPM_6_CLK_EN     ((1 << 5) | 9)
#define DDRNSDMC_DPM_5_CLK_EN     ((1 << 5) | 8)
#define DDRNSDMC_DPM_4_CLK_EN     ((1 << 5) | 7)
#define DDRNSDMC_DPM_3_CLK_EN     ((1 << 5) | 6)
#define DDRNSDMC_DPM_2_CLK_EN     ((1 << 5) | 5)
#define DDRNSDMC_DPM_1_CLK_EN     ((1 << 5) | 4)
#define DDRNSDMC_DPM_0_CLK_EN     ((1 << 5) | 3)
#define DDRNSDMC_AXI_CLK_EN       ((1 << 5) | 2)
#define DDRNSDMC_APM_APB_CLK_EN   ((1 << 5) | 1)
#define DDRNSDMC_MMR_APB_CLK_EN   ((1 << 5) | 0)

/*  clock_2 */
#define MIPIRC_0_PHY_CLK_EN          ((2 << 5) | 29)
#define MIPIRC_0_DEV_1_PHY_1_CLK_EN  ((2 << 5) | 28)
#define MIPIRC_0_DEV_1_PEL_CLK_EN    ((2 << 5) | 27)
#define MIPIRC_0_DEV_1_APB_CLK_EN    ((2 << 5) | 26)
#define MIPIRC_0_DEV_0_PHY_1_CLK_EN  ((2 << 5) | 25)
#define MIPIRC_0_DEV_0_PHY_0_CLK_EN  ((2 << 5) | 24)
#define MIPIRC_0_DEV_0_PEL_CLK_EN    ((2 << 5) | 23)
#define MIPIRC_0_DEV_0_APB_CLK_EN    ((2 << 5) | 22)
#define MIPIRC_0_CMN_PEL_CLK_EN      ((2 << 5) | 21)
#define MIPIRC_0_APB_MMR_CLK_EN      ((2 << 5) | 20)
#define MEM_MOD_BASE_CLK_EN          ((2 << 5) | 19)
#define MBC_XBUS_3_KRN_CLK_EN        ((2 << 5) | 18)
#define MBC_XBUS_2_MAS_CLK_EN        ((2 << 5) | 17)
#define MBC_PBUS_6_SLV_CLK_EN        ((2 << 5) | 16)
#define MBC_PBUS_5_SLV_CLK_EN        ((2 << 5) | 15)
#define MBC_PBUS_2_SLV_CLK_EN        ((2 << 5) | 14)
#define MBC_PBUS_1_SLV_CLK_EN        ((2 << 5) | 13)
#define MBC_HBUS_1_SLV_CLK_EN        ((2 << 5) | 12)
#define MBC_AXI_DDR_CLK_EN           ((2 << 5) | 11)
#define MBC_AXI_CTL_CLK_EN           ((2 << 5) | 10)
#define MBC_APB_CLK_EN               ((2 << 5) | 9)
#define KDPU_CORE_CLK_EN             ((2 << 5) | 8)
#define KDPU_AXI_CLK_EN              ((2 << 5) | 7)
#define KDPU_APB_CLK_EN              ((2 << 5) | 6)
#define JEBE_CLK_EN                  ((2 << 5) | 5)
#define JDBE_CLK_EN                  ((2 << 5) | 4)
#define ISPE_GTR_CLK_EN              ((2 << 5) | 3)
#define ISPE_DAXI_CLK_EN             ((2 << 5) | 2)
#define ISPE_CACHE_CLK_EN            ((2 << 5) | 1)
#define ISPE_APB_CLK_EN              ((2 << 5) | 0)

/*  clock_3 */
#define PLLC_APB_CLK_EN                   ((3 << 5) | 31)
#define PDMAC_AXI_DDR_CLK_EN              ((3 << 5) | 30)
#define PDMAC_APB_CLK_EN                  ((3 << 5) | 29)
#define MSHC_DEV_1_TX_CLK_EN              ((3 << 5) | 28)
#define MSHC_DEV_1_TM_CLK_EN              ((3 << 5) | 27)
#define MSHC_DEV_1_CQETM_CLK_EN           ((3 << 5) | 26)
#define MSHC_DEV_1_BASE_CLK_EN            ((3 << 5) | 25)
#define MSHC_DEV_1_AXI_CLK_EN             ((3 << 5) | 24)
#define MSHC_DEV_1_AHB_CLK_EN             ((3 << 5) | 23)
#define MSHC_DEV_0_TX_CLK_EN              ((3 << 5) | 22)
#define MSHC_DEV_0_TM_CLK_EN              ((3 << 5) | 21)
#define MSHC_DEV_0_LBT_CLK_EN             ((3 << 5) | 20)
#define MSHC_DEV_0_CQETM_CLK_EN           ((3 << 5) | 19)
#define MSHC_DEV_0_BASE_CLK_EN            ((3 << 5) | 18)
#define MSHC_DEV_0_AXI_CLK_EN             ((3 << 5) | 17)
#define MSHC_DEV_0_AHB_CLK_EN             ((3 << 5) | 16)
#define MIPITC_PHY_BYTE_CLK_EN            ((3 << 5) | 15)
#define MIPITC_PHY_CLK_EN                 ((3 << 5) | 14)
#define MIPITC_PEL_CLK_EN                 ((3 << 5) | 13)
#define MIPITC_DSI_APB_CLK_EN             ((3 << 5) | 12)
#define MIPITC_CSI2_APB_CLK_EN            ((3 << 5) | 11)
#define MIPITC_APB_MMR_CLK_EN             ((3 << 5) | 10)
#define MIPIRC_1_PHY_CLK_EN               ((3 << 5) | 9)
#define MIPIRC_1_DEV_1_PHY_BYTE_CLK_EN    ((3 << 5) | 8)
#define MIPIRC_1_DEV_1_PEL_CLK_EN         ((3 << 5) | 7)
#define MIPIRC_1_DEV_1_APB_CLK_EN         ((3 << 5) | 6)
#define MIPIRC_1_DEV_0_PHY_1_BYTE_CLK_EN  ((3 << 5) | 5)
#define MIPIRC_1_DEV_0_PHY_0_BYTE_CLK_EN  ((3 << 5) | 4)
#define MIPIRC_1_DEV_0_PEL_CLK_EN         ((3 << 5) | 3)
#define MIPIRC_1_DEV_0_APB_CLK_EN         ((3 << 5) | 2)
#define MIPIRC_1_CMN_PEL_CLK_EN           ((3 << 5) | 1)
#define MIPIRC_1_APB_MMR_CLK_EN           ((3 << 5) | 0)

/*  clock_4 */
#define USB20C_UTMI_CLK_EN   ((4 << 5) | 26)
#define USB20C_RAM_CLK_EN    ((4 << 5) | 25)
#define USB20C_PHY_CLK_EN    ((4 << 5) | 24)
#define USB20C_AXI_CLK_EN    ((4 << 5) | 23)
#define USB20C_APB_CLK_EN    ((4 << 5) | 22)
#define UARTC_4_CORE_CLK_EN  ((4 << 5) | 21)
#define UARTC_4_APB_CLK_EN   ((4 << 5) | 20)
#define UARTC_3_CORE_CLK_EN  ((4 << 5) | 19)
#define UARTC_3_APB_CLK_EN   ((4 << 5) | 18)
#define UARTC_2_CORE_CLK_EN  ((4 << 5) | 17)
#define UARTC_2_APB_CLK_EN   ((4 << 5) | 16)
#define UARTC_1_CORE_CLK_EN  ((4 << 5) | 15)
#define UARTC_1_APB_CLK_EN   ((4 << 5) | 14)
#define UARTC_0_CORE_CLK_EN  ((4 << 5) | 13)
#define UARTC_0_APB_CLK_EN   ((4 << 5) | 12)
#define TMRC_APB_CLK_EN      ((4 << 5) | 11)
#define SYSC_APB_CLK_EN      ((4 << 5) | 10)
#define SSIC_3_APB_CLK_EN    ((4 << 5) | 9)
#define SSIC_2_APB_CLK_EN    ((4 << 5) | 8)
#define SSIC_1_APB_CLK_EN    ((4 << 5) | 7)
#define SSIC_0_APB_CLK_EN    ((4 << 5) | 6)
#define XTL_CLK_EN           ((4 << 5) | 5)
#define CTR_CLK_EN           ((4 << 5) | 4)
#define AXI_DMA_CLK_EN       ((4 << 5) | 3)
#define AXI_CTL_CLK_EN       ((4 << 5) | 2)
#define PMU_BASE_CLK_EN      ((4 << 5) | 1)
#define PMU_APB_CLK_EN       ((4 << 5) | 0)

/*  clock_5 */
#define WDTC_APB_CLK_EN       ((5 << 5) | 20)
#define VQ7U_CORE_CLK_EN       ((5 << 5) | 19)
#define VQ7U_AXI_DMA_CLK_EN   ((5 << 5) | 18)
#define VQ7U_AXI_CTL_CLK_EN   ((5 << 5) | 17)
#define VOC_1_PEL_CLK_EN      ((5 << 5) | 16)
#define VOC_1_DAXI_CLK_EN     ((5 << 5) | 15)
#define VOC_1_APB_CLK_EN      ((5 << 5) | 14)
#define VOC_0_PEL_CLK_EN      ((5 << 5) | 13)
#define VOC_0_DAXI_CLK_EN     ((5 << 5) | 12)
#define VOC_0_APB_CLK_EN      ((5 << 5) | 11)
#define VIC_TGEN_CLK_EN       ((5 << 5) | 10)
#define VIC_DEV_1_PEL_CLK_EN  ((5 << 5) | 9)
#define VIC_DEV_0_PEL_CLK_EN  ((5 << 5) | 8)

#define VIC_APB_CLK_EN        ((5 << 5) | 6)
#define USB30C_UTMI_CLK_EN    ((5 << 5) | 5)
#define USB30C_RAM_CLK_EN     ((5 << 5) | 4)
#define USB30C_PIPE_CLK_EN    ((5 << 5) | 3)
#define USB30C_PHY_CLK_EN     ((5 << 5) | 2)
#define USB30C_AXI_CLK_EN     ((5 << 5) | 1)
#define USB30C_APB_CLK_EN     ((5 << 5) | 0)

#define VOC_0_MEM_PWR_DOWN        ((6 << 5) | 31)
#define VIC_MEM_PWR_DOWN          ((6 << 5) | 30)
#define USB30C_MEM_PWR_DOWN       ((6 << 5) | 29)
#define USB20C_MEM_PWR_DOWN       ((6 << 5) | 28)
#define RAMBUS_MEM_PWR_DOWN       ((6 << 5) | 27)
#define PDMAC_MEM_PWR_DOWN        ((6 << 5) | 26)
#define MSHC_DEV_1_MEM_PWR_DOWN   ((6 << 5) | 25)
#define MSHC_DEV_0_MEM_PWR_DOWN   ((6 << 5) | 24)
#define MIPITC_MEM_PWR_DOWN       ((6 << 5) | 23)
#define MIPIRC_1_MEM_PWR_DOWN     ((6 << 5) | 22)
#define MIPIRC_0_MEM_PWR_DOWN     ((6 << 5) | 21)
#define MBC_MEM_PWR_DOWN          ((6 << 5) | 20)
#define KDPU_MEM_PWR_DOWN         ((6 << 5) | 19)
#define JEBE_MEM_PWR_DOWN         ((6 << 5) | 18)
#define JDBE_MEM_PWR_DOWN         ((6 << 5) | 17)
#define ISPE_MEM_PWR_DOWN         ((6 << 5) | 16)
#define IFPE_MEM_PWR_DOWN         ((6 << 5) | 15)
#define IEU_1_MEM_PWR_DOWN        ((6 << 5) | 14)
#define IEU_0_MEM_PWR_DOWN        ((6 << 5) | 13)
#define GMAC_MEM_PWR_DOWN         ((6 << 5) | 12)
#define DMAC_1_MEM_PWR_DOWN       ((6 << 5) | 11)
#define DMAC_0_MEM_PWR_DOWN       ((6 << 5) | 10)
#define DDRNSDMC_MEM_PWR_DOWN     ((6 << 5) | 9)
#define CDCE_MEM_PWR_DOWN         ((6 << 5) | 8)
#define CA55U_GIC600_MEM_PWR_DOWN ((6 << 5) | 7)
#define CA55U_DSU_MEM_PWR_DOWN    ((6 << 5) | 6)
#define CA55U_CORE_3_MEM_PWR_DOWN ((6 << 5) | 5)
#define CA55U_CORE_2_MEM_PWR_DOWN ((6 << 5) | 4)
#define CA55U_CORE_1_MEM_PWR_DOWN ((6 << 5) | 3)
#define CA55U_CORE_0_MEM_PWR_DOWN ((6 << 5) | 2)
#define BRC_ROM_PWR_DOWN          ((6 << 5) | 1)
#define BRC_MEM_PWR_DOWN          ((6 << 5) | 0)

#define VQ7U_MEM_PWR_DOWN         ((7 << 5) | 1)
#define VOC_1_MEM_PWR_DOWN        ((7 << 5) | 0)

int kl730_clk_init(void);

#endif /* _KL730_CLKS_H_ */

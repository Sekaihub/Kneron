/* SPDX-License-Identifier: GPL-2.0-only*/
/*
 *
 * Copyright (C) 2023 VATICS Inc.
 *
 */

#ifndef _DT_BINDINGS_VATICS_LEIPZIG_RESET_H
#define _DT_BINDINGS_VATICS_LEIPZIG_RESET_H

/* Reset Release 0 */
#define AHBC_0_RST                      0
#define AHBC_1_RST                      1
#define AHBC_2_RST                      2
#define APBC_RST                        3
#define BRC_RST                         4
#define CA7U_CORE_0_RST                 5
#define CA7U_CORE_1_RST                 6
#define CA7U_MIX_RST                    7   /* scu/peripheral/debug/APB */
#define CDCE_DAXI_RST                   8
#define CDCE_H4CDE_RST                  9
#define D1088U_RST                      10
#define DDRNSDMC_APB_RST                11
#define DDRNSDMC_DAXI_RST               12
#define DCE_RST                         13
#define DMAC_0_RST                      14
#define DMAC_1_RST                      15
#define EQOSC_RST                       16
#define HSSIC_APB_RST                   17
#define HSSIC_DEV_0_CH_0_RST            18
#define HSSIC_DEV_0_CH_1_RST            19
#define HSSIC_DEV_0_PEL_RST             20
#define HSSIC_DEV_1_PEL_RST             21
#define HSSIC_DEV_1_RST                 22
#define IFPE_RST                        23
#define ISPE_RST                        24
#define JDBE_RST                        25
#define JEBE_RST                        26
#define MBC_RST                         27
#define MEAE_RST                        28
#define BRSE_RST                        29

/* Reset Release 1 */
#define MIPIC_APB_RST                   32  /* 00 */
#define MIPIC_CSI_0_RST                 33  /* 01 */
#define MIPIC_CSI_1_RST                 34  /* 02 */
#define MIPIC_DEV_0_RX_BYTE_RST         35  /* 03 */
#define MIPIC_DEV_0_TX_BYTE_RST         36  /* 04 */
#define MIPIC_DEV_1_RX_BYTE_RST         37  /* 05 */
#define MSHC_0_RST                      38  /* 07 */
#define MSHC_1_RST                      39  /* 08 */
#define NFC_RST                         40  /* 09 */
#define OSDE_0_RST                      41  /* 10 */
#define OSDE_1_RST                      42  /* 11 */
#define ROTE_RST                        43  /* 12 */
#define USBC_AMBA_RST                   44  /* 13 */
#define VIC_AHB_RST                     45  /* 14 */
#define VIC_COMP_0_RST                  46  /* 15 */
#define VIC_COMP_1_RST                  47  /* 16 */
#define VOC_RST                         48  /* 17 */
#define SVIC_AHB_DAXI_RST               49  /* 18 */
#define SVIC_COMP_0_RST                 50  /* 19 */
#define SVIC_COMP_1_RST                 51  /* 20 */
#define VOC_TGEN_RST                    52  /* 21 */

#endif /* _DT_BINDINGS_VATICS_WARSAW_RESET_H */

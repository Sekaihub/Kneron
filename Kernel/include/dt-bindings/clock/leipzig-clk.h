/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (c) 2022-2027, VATICS CORPORATION.  All rights reserved.
 */

#ifndef _DT_BINDINGS_CLK_LEIPZIG_H
#define _DT_BINDINGS_CLK_LEIPZIG_H

#define CLK_OSC_20M                         0
#define CLK_OSC_20M_D20                     1
#define CLK_PLL_0                           2
#define CLK_PLL_1                           3
#define CLK_PLL_2                           4
#define CLK_PLL_3                           5
#define CLK_PLL_4                           6
#define CLK_PLL_5                           7
#define CLK_PLL_6                           8
#define CLK_PLL_7                           9
#define CLK_PLL_8                           10
#define CLK_PLL_9                           11
#define CLK_PLL_4_D2                        12
#define CLK_PLL_4_D3                        13
#define CLK_PLL_4_D4                        14
#define CLK_PLL_4_D6                        15
#define CLK_PLL_4_D8                        16
#define CLK_PLL_5_D3                        17
#define CLK_PLL_5_D4                        18
#define CLK_PLL_5_D5                        19
#define CLK_PLL_5_D6                        20
#define CLK_PLL_5_D8                        21
#define CLK_PLL_5_D10                       22
#define CLK_PLL_5_D16                       23
#define CLK_PLL_5_D20                       24
#define CLK_PLL_5_OUT2                      25
#define CLK_PLL_5_OUT2_D4                   26
#define CLK_PLL_5_OUT2_D10                  27
#define CLK_PLL_5_OUT2_D20                  28
#define CLK_PLL_5_OUT2_D200                 29
#define CLK_PLL_5_D3_AHB_1_GRP              30
#define CLK_PLL_6_DIV_VIC_REF               31
#define CLK_PLL_7_OUT1                      32
#define CLK_PLL_8_OUT1                      33
#define CLK_PLL_9_DIV_I2SSC_INT_RX_SERIAL   34
#define CLK_PLL_9_DIV_I2SSC_INT_TX_SERIAL   35


#define CLK_ADCDCC_APB                      50
#define CLK_ADCDCC_RX                       51
#define CLK_ADCDCC_TX                       52
#define CLK_ADCDCC_I_RX                     53
#define CLK_ADCDCC_I_TX                     54

#define CLK_AGPOC_APB                       55

#define CLK_BRC_AXI                         56

#define CLK_CA55U_AXI_CTL                   57
#define CLK_CA55U_CORE_0                    58
#define CLK_CA55U_CORE_1                    59
#define CLK_CA55U_CORE_2                    60
#define CLK_CA55U_CORE_3                    61
#define CLK_CA55U_DBG                       62
#define CLK_CA55U_GIC                       63
#define CLK_CA55U_PCLK                      64
#define CLK_CA55U_SCU                       65

#define CLK_CDCE_APB                        66
#define CLK_CDCE_AXI                        67
#define CLK_CDCE_BPU                        68
#define CLK_CDCE_VCE                        69

#define CLK_DMAC_0_AHB                      70
#define CLK_DMAC_1_AHB                      71

#define CLK_EQOSC_I_RX                      72
#define CLK_EQOSC_I_RX_D2                   73
#define CLK_EQOSC_I_RX_D20                  74
#define CLK_EQOSC_I_TX                      75
#define CLK_EQOSC_RMODE_0_MUX               76
#define CLK_EQOSC_RMODE_1_MUX               77
#define CLK_EQOSC_RMODE_2_MUX               78
#define CLK_EQOSC_RMII_PHASE_MUX            79
#define CLK_EQOSC_FREQ_MUX                  80
#define CLK_EQOS_AXI_DMA                    81
#define CLK_EQOS_AXI_MMR                    82
#define CLK_EQOSC_PTP_REF                   83
#define CLK_EQOSC_RMII                      84
#define CLK_EQOSC_RX                        85
#define CLK_EQOSC_TX                        86
#define CLK_EQOSC_O_REF                     87
#define CLK_EQOSC_O_TX                      88

#define CLK_GPIOC_0_APB                     89
#define CLK_GPIOC_1_APB                     90
#define CLK_GPIOC_2_APB                     91

#define CLK_I2C_0_APB                       92
#define CLK_I2C_1_APB                       93
#define CLK_I2C_2_APB                       94

#define CLK_DDR_MMR_APB                     95
#define CLK_DDR_APM_APB                     96
#define CLK_DDR_AXI                         97
#define CLK_DDR_DPM_0                       98
#define CLK_DDR_DPM_1                       99
#define CLK_DDR_DPM_2                       100
#define CLK_DDR_DPM_3                       101
#define CLK_DDR_DPM_4                       102
#define CLK_DDR_DPM_5                       103
#define CLK_DDR_DPM_6                       104
#define CLK_DDR_DPM_7                       105
#define CLK_DDR_DPM_8                       106
#define CLK_DDR_DPM_9                       107
#define CLK_DDR_DPM_10                      108
#define CLK_DDR_DPM_11                      109
#define CLK_DDR_DPM_12                      110
#define CLK_DDR_DPM_13                      111
#define CLK_DDR_DPM_14                      112
#define CLK_DDR_DPM_15                      113
#define CLK_DDR_MCTL_APB                    114
#define CLK_DDR_PUB_APB                     115

#define CLK_I2SSC_IO_RX_SCLK                116
#define CLK_I2SSC_IO_TX_SCLK                117
#define CLK_I2SSC_O_MCLK                    118
#define CLK_I2SSC_APB                       119
#define CLK_I2SSC_RX_SCLK                   120
#define CLK_I2SSC_TX_SCLK                   121
#define CLK_I2SSC_TX_WS                     122
#define CLK_I2SSC_RX_WS                     123

#define CLK_IEU_0_APB                       124
#define CLK_IEU_0_AXI                       125
#define CLK_IEU_1_APB                       126
#define CLK_IEU_1_AXI                       127

#define CLK_IFPE_APB                        128

#define CLK_INTC_AHB                        129

#define CLK_IRDAC_APB                       130

#define CLK_ISPE_APB                        131
#define CLK_ISPE_CACHE                      132
#define CLK_ISPE_DAXI                       133
#define CLK_ISPE_GTR                        134

#define CLK_JDBE_AHB                        135
#define CLK_JEBE_AHB                        136

#define CLK_KDPU_APB                        137
#define CLK_KDPU_AXI                        138
#define CLK_KDPU_CORE                       139

#define CLK_MBC_APB                         140
#define CLK_MBC_AXI_CTL                     141
#define CLK_MBC_AXI_DDR                     142
#define CLK_MBC_HBUS_1_SLAVE                143
#define CLK_MBC_PBUS_1_SLAVE                144
#define CLK_MBC_PBUS_2_SLAVE                145
#define CLK_MBC_PBUS_5_SLAVE                146
#define CLK_MBC_PBUS_6_SLAVE                147
#define CLK_MBC_XBUS_2_MASTER               148
#define CLK_MBC_XBUS_3_KERNEL               149

#define CLK_MEM_MODULE_BASE                 150

#define CLK_MIPIRC_0_DPHY                   153
#define CLK_MIPIRC_1_DPHY                   154
#define CLK_MIPIRC_0_APB_MMR                155
#define CLK_MIPIRC_0_COMMON_PEL             156
#define CLK_MIPIRC_0_DEV_0_APB              157
#define CLK_MIPIRC_0_DEV_0_PEL              158
#define CLK_MIPIRC_0_DEV_0_PHY_0_BYTE       159
#define CLK_MIPIRC_0_DEV_0_PHY_1_BYTE       160
#define CLK_MIPIRC_0_DEV_1_APB              161
#define CLK_MIPIRC_0_DEV_1_PEL              162
#define CLK_MIPIRC_0_DEV_1_PHY_1_BYTE       163
#define CLK_MIPIRC_0_PHY                    164
#define CLK_MIPIRC_1_APB_MMR                165
#define CLK_MIPIRC_1_COMMON_PEL             166
#define CLK_MIPIRC_1_DEV_0_APB              167
#define CLK_MIPIRC_1_DEV_0_PEL              168
#define CLK_MIPIRC_1_DEV_0_PHY_0_BYTE       169
#define CLK_MIPIRC_1_DEV_0_PHY_1_BYTE       170
#define CLK_MIPIRC_1_DEV_1_APB              171
#define CLK_MIPIRC_1_DEV_1_PEL              172
#define CLK_MIPIRC_1_DEV_1_PHY_1_BYTE       173
#define CLK_MIPIRC_1_PHY                    174

#define CLK_MIPITC_DPHY                     175
#define CLK_MIPITC_APB_MMR                  176
#define CLK_MIPITC_CSI2_APB                 177
#define CLK_MIPITC_DSI_APB                  178
#define CLK_MIPITC_PEL                      179
#define CLK_MIPITC_PHY                      180
#define CLK_MIPITC_PHY_BYTE                 181

#define CLK_MSHC_0_AHB                      182
#define CLK_MSHC_0_AXI                      183
#define CLK_MSHC_0_BASE                     184
#define CLK_MSHC_0_CQETM                    185
#define CLK_MSHC_0_LBT                      186
#define CLK_MSHC_0_TM                       187
#define CLK_MSHC_0_TX                       188
#define CLK_MSHC_1_AHB                      189
#define CLK_MSHC_1_AXI                      190
#define CLK_MSHC_1_BASE                     191
#define CLK_MSHC_1_CQETM                    192
#define CLK_MSHC_1_TM                       193
#define CLK_MSHC_1_TX                       194

#define CLK_PDMA_APB                        195
#define CLK_PDMA_AXI_DDR                    196

#define CLK_PLLC_APB                        197

#define CLK_PMU_APB                         198
#define CLK_PMU_BASE                        199

#define CLK_SCRTU_AXI_CTL                   200
#define CLK_SCRTU_AXI_DMA                   201
#define CLK_SCRTU_CTR                       202
#define CLK_SCRTU_XT1                       203

#define CLK_SSIC_0_APB                      204
#define CLK_SSIC_1_APB                      205
#define CLK_SSIC_2_APB                      206
#define CLK_SSIC_3_APB                      207

#define CLK_SYSC_APB                        208

#define CLK_TMRC_APB                        209

#define CLK_UARTC_0_APB                     210
#define CLK_UARTC_0_CORE                    211
#define CLK_UARTC_1_APB                     212
#define CLK_UARTC_1_CORE                    213
#define CLK_UARTC_2_APB                     214
#define CLK_UARTC_2_CORE                    215
#define CLK_UARTC_3_APB                     216
#define CLK_UARTC_3_CORE                    217
#define CLK_UARTC_4_APB                     218
#define CLK_UARTC_4_CORE                    219

#define CLK_USB_PHY_60M                     220
#define CLK_USB_PHY_125M                    221
#define CLK_USB20C_APB                      222
#define CLK_USB20C_AXI                      223
#define CLK_USB20C_PHY                      224
#define CLK_USB20C_RAM                      225
#define CLK_USB20C_UTMI                     226

#define CLK_USB30C_APB                      227
#define CLK_USB30C_AXI                      228
#define CLK_USB30C_PHY                      229
#define CLK_USB30C_PIPE                     230
#define CLK_USB30C_RAM                      231
#define CLK_USB30C_UTMI                     232

#define CLK_VIC_I_DEV_0                     234
#define CLK_VIC_I_DEV_1                     235
#define CLK_VIC_O_REF                       236
#define CLK_VIC_APB                         237
#define CLK_VIC_I_DEV_0_PHASE               238
#define CLK_VIC_0_PEL                       239
#define CLK_VIC_I_DEV_1_PHASE               240
#define CLK_VIC_1_PEL                       241
#define CLK_VIC_TGEN                        242

#define CLK_VOC_1_PHASE                     245
#define CLK_VOC_1_O                         246
#define CLK_VOC_0_APB                       247
#define CLK_VOC_0_DAXI                      248
#define CLK_VOC_0_PEL                       249
#define CLK_VOC_1_APB                       250
#define CLK_VOC_1_DAXI                      251
#define CLK_VOC_1_PEL                       252

#define CLK_VQ7U_AXI_CTL                    255
#define CLK_VQ7U_AXI_DMA                    256
#define CLK_VQ7U_CORE                       257

#define CLK_WDTC_APB                        258

#define CLK_RTC_32K                         260
#define CLK_USB20C_SUSP                     261
#define CLK_USB30C_SUSP                     262

/* internal memory power down */
#define MEM_PWR_BRC                         300
#define MEM_PWR_BRC_ROM                     301
#define MEM_PWR_CA55U_CORE_0                302
#define MEM_PWR_CA55U_CORE_1                303
#define MEM_PWR_CA55U_CORE_2                304
#define MEM_PWR_CA55U_CORE_3                305
#define MEM_PWR_CA55U_DSU                   306
#define MEM_PWR_CA55U_GIC_600               307
#define MEM_PWR_CDCE                        308
#define MEM_PWR_DDRNSDMC                    309
#define MEM_PWR_DMAC_0                      310
#define MEM_PWR_DMAC_1                      311
#define MEM_PWR_EQOSC                       312
#define MEM_PWR_IEU_0                       313
#define MEM_PWR_IEU_1                       314
#define MEM_PWR_IFPE                        315
#define MEM_PWR_ISPE                        316
#define MEM_PWR_JDBE                        317
#define MEM_PWR_JEBE                        318
#define MEM_PWR_KDPU                        319
#define MEM_PWR_MBC                         320
#define MEM_PWR_MIPIRC_0                    321
#define MEM_PWR_MIPIRC_1                    322
#define MEM_PWR_MIPITC                      323
#define MEM_PWR_MSHC_0                      324
#define MEM_PWR_MSHC_1                      325
#define MEM_PWR_PDMAC                       326
#define MEM_PWR_SCRTU                       327
#define MEM_PWR_USB20C                      328
#define MEM_PWR_USB30C                      329
#define MEM_PWR_VIC                         330
#define MEM_PWR_VOC_0                       331
#define MEM_PWR_VOC_1                       332
#define MEM_PWR_VQ7U                        333


#endif /* _DT_BINDINGS_CLK_LEIPZIG_H */

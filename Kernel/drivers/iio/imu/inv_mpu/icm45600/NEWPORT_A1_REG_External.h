/*
 *________________________________________________________________________________________________________
 * Copyright (c) 2017 InvenSense Inc. All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively "Software") is subject
 * to InvenSense and its licensors intellectual property rights under U.S. and international copyright
 * and other intellectual property rights laws.
 *
 * InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
 * and any use, reproduction, disclosure or distribution of the Software without an express license agreement
 * from InvenSense is strictly prohibited.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * INVENSENSE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
   OF THE SOFTWARE.
 * ________________________________________________________________________________________________________
 */
#ifndef _REG_EXTERNAL_H_
#define _REG_EXTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file REG.h
 * File exposing the device register map
 */

//#include <stdint.h>

/* forward declaration */
struct REG;



/* ----------------------------------------------------------------------------
 * Device Register map
 *
 * Next macros defines address for all newport_a1_reg registers as listed by device
 * datasheet.
 * Macros name is REG_<REGISTER_NAME> with REGISTER_NAME being the name of
 * the corresponding register in datasheet.
 * Note that macro name is REG_<REGISTER_NAME>_Bx with x being the bank
 * number for registers that are in bank 1 and further (suffix is ommitted for
 * bank 0 registers)
 * ---------------------------------------------------------------------------- */

/* IPREG_BAR */
#define REG_IPREG_BAR_REG_17_IPREG_BAR                               0xa011
#define REG_IPREG_BAR_REG_20_IPREG_BAR                               0xa014
#define REG_IPREG_BAR_REG_58_IPREG_BAR                               0xa03a
#define REG_IPREG_BAR_REG_59_IPREG_BAR                               0xa03b
#define REG_IPREG_BAR_REG_60_IPREG_BAR                               0xa03c
#define REG_IPREG_BAR_REG_61_IPREG_BAR                               0xa03d
#define REG_IPREG_BAR_REG_62_IPREG_BAR                               0xa03e
#define REG_IPREG_BAR_REG_63_IPREG_BAR                               0xa03f
#define REG_IPREG_BAR_REG_109_IPREG_BAR                              0xa06d

/* IPREG_ANA */
#define REG_IPREG_ANA_REG_1_IPREG_ANA                                0xa301
#define REG_IPREG_ANA_REG_3_IPREG_ANA                                0xa303
#define REG_IPREG_ANA_REG_4_IPREG_ANA                                0xa304

/* DREG_TOP1 */
#define REG_PWR_MGMT0_DREG_TOP1                                      0xa110
#define REG_INT1_CONFIG2_DREG_TOP1                                   0xa118
#define REG_ACCEL_CONFIG0_DREG_TOP1                                  0xa11b
#define REG_GYRO_CONFIG0_DREG_TOP1                                   0xa11c
#define REG_FIFO_CONFIG0_DREG_TOP1                                   0xa11d
#define REG_FIFO_CONFIG1_0_DREG_TOP1                                 0xa11e
#define REG_FIFO_CONFIG1_1_DREG_TOP1                                 0xa11f
#define REG_FIFO_CONFIG2_DREG_TOP1                                   0xa120
#define REG_FIFO_CONFIG3_DREG_TOP1                                   0xa121
#define REG_FIFO_CONFIG4_DREG_TOP1                                   0xa122
#define REG_OTP_HEATER_RTC_CONFIG_DREG_TOP1                          0xa126
#define REG_DMP_EXT_SEN_ODR_CFG_DREG_TOP1                            0xa127
#define REG_EDMP_APEX_EN0_DREG_TOP1                                  0xa129
#define REG_EDMP_APEX_EN1_DREG_TOP1                                  0xa12a
#define REG_APEX_BUFFER_MGMT_DREG_TOP1                               0xa12b
#define REG_IOC_PAD_SCENARIO_DREG_TOP1                               0xa12f
#define REG_WHO_AM_I_DREG_TOP1                                       0xa172
#define REG_REG_HOST_MSG_DREG_TOP1                                   0xa173

/* DREG_TOP2 */

/* IHREG_SREG */
#define REG_ACCEL_X_0_IHREG_SREG                                     0x8000
#define REG_ACCEL_X_1_IHREG_SREG                                     0x8001
#define REG_ACCEL_X_2_IHREG_SREG                                     0x8002
#define REG_ACCEL_X_3_IHREG_SREG                                     0x8003
#define REG_ACCEL_Y_0_IHREG_SREG                                     0x8004
#define REG_ACCEL_Y_1_IHREG_SREG                                     0x8005
#define REG_ACCEL_Y_2_IHREG_SREG                                     0x8006
#define REG_ACCEL_Y_3_IHREG_SREG                                     0x8007
#define REG_ACCEL_Z_0_IHREG_SREG                                     0x8008
#define REG_ACCEL_Z_1_IHREG_SREG                                     0x8009
#define REG_ACCEL_Z_2_IHREG_SREG                                     0x800a
#define REG_ACCEL_Z_3_IHREG_SREG                                     0x800b
#define REG_GYRO_X_0_IHREG_SREG                                      0x800c
#define REG_GYRO_X_1_IHREG_SREG                                      0x800d
#define REG_GYRO_X_2_IHREG_SREG                                      0x800e
#define REG_GYRO_X_3_IHREG_SREG                                      0x800f
#define REG_GYRO_Y_0_IHREG_SREG                                      0x8010
#define REG_GYRO_Y_1_IHREG_SREG                                      0x8011
#define REG_GYRO_Y_2_IHREG_SREG                                      0x8012
#define REG_GYRO_Y_3_IHREG_SREG                                      0x8013
#define REG_GYRO_Z_0_IHREG_SREG                                      0x8014
#define REG_GYRO_Z_1_IHREG_SREG                                      0x8015
#define REG_GYRO_Z_2_IHREG_SREG                                      0x8016
#define REG_GYRO_Z_3_IHREG_SREG                                      0x8017
#define REG_TEMP_0_IHREG_SREG                                        0x8018
#define REG_TEMP_1_IHREG_SREG                                        0x8019
#define REG_TEMP_2_IHREG_SREG                                        0x801a
#define REG_TEMP_3_IHREG_SREG                                        0x801b
#define REG_CTRL_IHREG_SREG                                          0x801c

/* IMEM_ROM */

/* IMEM_SRAM */
#define REG_IMEM_SRAM_REG_0_IMEM_SRAM                                0x00
#define REG_IMEM_SRAM_REG_1_IMEM_SRAM                                0x01
#define REG_IMEM_SRAM_REG_2_IMEM_SRAM                                0x02
#define REG_IMEM_SRAM_REG_3_IMEM_SRAM                                0x03
#define REG_IMEM_SRAM_REG_4_IMEM_SRAM                                0x04
#define REG_IMEM_SRAM_REG_5_IMEM_SRAM                                0x05
#define REG_IMEM_SRAM_REG_6_IMEM_SRAM                                0x06
#define REG_IMEM_SRAM_REG_7_IMEM_SRAM                                0x07
#define REG_IMEM_SRAM_REG_8_IMEM_SRAM                                0x08
#define REG_IMEM_SRAM_REG_9_IMEM_SRAM                                0x09
#define REG_IMEM_SRAM_REG_10_IMEM_SRAM                               0x0a
#define REG_IMEM_SRAM_REG_11_IMEM_SRAM                               0x0b
#define REG_IMEM_SRAM_REG_12_IMEM_SRAM                               0x0c
#define REG_IMEM_SRAM_REG_13_IMEM_SRAM                               0x0d
#define REG_IMEM_SRAM_REG_14_IMEM_SRAM                               0x0e
#define REG_IMEM_SRAM_REG_15_IMEM_SRAM                               0x0f
#define REG_IMEM_SRAM_REG_16_IMEM_SRAM                               0x10
#define REG_IMEM_SRAM_REG_17_IMEM_SRAM                               0x11
#define REG_IMEM_SRAM_REG_18_IMEM_SRAM                               0x12
#define REG_IMEM_SRAM_REG_19_IMEM_SRAM                               0x13
#define REG_IMEM_SRAM_REG_20_IMEM_SRAM                               0x14
#define REG_IMEM_SRAM_REG_21_IMEM_SRAM                               0x15
#define REG_IMEM_SRAM_REG_22_IMEM_SRAM                               0x16
#define REG_IMEM_SRAM_REG_23_IMEM_SRAM                               0x17
#define REG_IMEM_SRAM_REG_24_IMEM_SRAM                               0x18

/* IPREG_FPGA */
#define REG_MSTR_SPI_CTRL_IPREG_FPGA                                 0xa600
#define REG_MSTR_SPI_ADDR_IPREG_FPGA                                 0xa601
#define REG_MSTR_SPI_WR_DATA_IPREG_FPGA                              0xa602
#define REG_MSTR_SPI_RD_DATA_IPREG_FPGA                              0xa603
#define REG_MSTR_SPI_STATUS_IPREG_FPGA                               0xa604
#define REG_SENSOR_DATA_CTRL_IPREG_FPGA                              0xa605
#define REG_FPGA_ID_IPREG_FPGA                                       0xa606
#define REG_FPGA_CONFIG_IPREG_FPGA                                   0xa607
#define REG_REVISION1_IPREG_FPGA                                     0xa608
#define REG_REVISION2_IPREG_FPGA                                     0xa609
#define REG_ACCEL_X_FRE_IPREG_FPGA                                   0xa60a
#define REG_ACCEL_X_AMP_IPREG_FPGA                                   0xa60b
#define REG_ACCEL_X_OFS_IPREG_FPGA                                   0xa60c
#define REG_ACCEL_X_PHA_IPREG_FPGA                                   0xa60d
#define REG_ACCEL_X_Y_AEX_IPREG_FPGA                                 0xa60e
#define REG_ACCEL_Y_FRE_IPREG_FPGA                                   0xa60f
#define REG_ACCEL_Y_AMP_IPREG_FPGA                                   0xa610
#define REG_ACCEL_Y_OFS_IPREG_FPGA                                   0xa611
#define REG_ACCEL_Y_PHA_IPREG_FPGA                                   0xa612
#define REG_ACCEL_Z_FRE_IPREG_FPGA                                   0xa613
#define REG_ACCEL_Z_AMP_IPREG_FPGA                                   0xa614
#define REG_ACCEL_Z_OFS_IPREG_FPGA                                   0xa615
#define REG_ACCEL_Z_PHA_IPREG_FPGA                                   0xa616
#define REG_ACCEL_Z_GYRO_X_AEX_IPREG_FPGA                            0xa617
#define REG_GYRO_X_FRE_IPREG_FPGA                                    0xa618
#define REG_GYRO_X_AMP_IPREG_FPGA                                    0xa619
#define REG_GYRO_X_OFS_IPREG_FPGA                                    0xa61a
#define REG_GYRO_X_PHA_IPREG_FPGA                                    0xa61b
#define REG_GYRO_Y_FRE_IPREG_FPGA                                    0xa61c
#define REG_GYRO_Y_AMP_IPREG_FPGA                                    0xa61d
#define REG_GYRO_Y_OFS_IPREG_FPGA                                    0xa61e
#define REG_GYRO_Y_PHA_IPREG_FPGA                                    0xa61f
#define REG_GYRO_Y_GYRO_Z_AEX_IPREG_FPGA                             0xa620
#define REG_GYRO_Z_FRE_IPREG_FPGA                                    0xa621
#define REG_GYRO_Z_AMP_IPREG_FPGA                                    0xa622
#define REG_GYRO_Z_OFS_IPREG_FPGA                                    0xa623
#define REG_GYRO_Z_PHA_IPREG_FPGA                                    0xa624
#define REG_ACCEL_GYRO_CLKDIV_IPREG_FPGA                             0xa625
#define REG_FPGA_CTRL_IPREG_FPGA                                     0xa627
#define REG_OTP_ERROR_STATUS_IPREG_FPGA                              0xa628
#define REG_DIFF_READ_ERROR_BITMASK0_0_IPREG_FPGA                    0xa62a
#define REG_DIFF_READ_ERROR_BITMASK0_1_IPREG_FPGA                    0xa62b
#define REG_DIFF_READ_ERROR_ADDR0_0_IPREG_FPGA                       0xa62c
#define REG_DIFF_READ_ERROR_ADDR0_1_IPREG_FPGA                       0xa62d
#define REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_0_IPREG_FPGA             0xa62e
#define REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_1_IPREG_FPGA             0xa62f
#define REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_0_IPREG_FPGA             0xa630
#define REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_1_IPREG_FPGA             0xa631
#define REG_PROG_0BIT_ERROR_DATA0_0_IPREG_FPGA                       0xa632
#define REG_PROG_0BIT_ERROR_DATA0_1_IPREG_FPGA                       0xa633
#define REG_PROG_0BIT_ERROR_ADDR0_0_IPREG_FPGA                       0xa634
#define REG_PROG_0BIT_ERROR_ADDR0_1_IPREG_FPGA                       0xa635
#define REG_FPGA_REG0_IPREG_FPGA                                     0xa636
#define REG_FPGA_REG1_IPREG_FPGA                                     0xa637
#define REG_FPGA_REG2_IPREG_FPGA                                     0xa638
#define REG_FPGA_REG3_IPREG_FPGA                                     0xa639
#define REG_FPGA_REG4_IPREG_FPGA                                     0xa63a
#define REG_FPGA_REG5_IPREG_FPGA                                     0xa63b
#define REG_FPGA_STAT0_IPREG_FPGA                                    0xa63c
#define REG_FPGA_STAT1_IPREG_FPGA                                    0xa63d

/* IPREG_OTP */

/* IPREG_SYS1 */
#define REG_IPREG_SYS1_REG_42_IPREG_SYS1                             0xa42a
#define REG_IPREG_SYS1_REG_43_IPREG_SYS1                             0xa42b
#define REG_IPREG_SYS1_REG_56_IPREG_SYS1                             0xa438
#define REG_IPREG_SYS1_REG_57_IPREG_SYS1                             0xa439
#define REG_IPREG_SYS1_REG_70_IPREG_SYS1                             0xa446
#define REG_IPREG_SYS1_REG_71_IPREG_SYS1                             0xa447
#define REG_IPREG_SYS1_REG_118_IPREG_SYS1                            0xa476
#define REG_IPREG_SYS1_REG_119_IPREG_SYS1                            0xa477
#define REG_IPREG_SYS1_REG_130_IPREG_SYS1                            0xa482
#define REG_IPREG_SYS1_REG_131_IPREG_SYS1                            0xa483
#define REG_IPREG_SYS1_REG_142_IPREG_SYS1                            0xa48e
#define REG_IPREG_SYS1_REG_143_IPREG_SYS1                            0xa48f
#define REG_IPREG_SYS1_REG_166_IPREG_SYS1                            0xa4a6
#define REG_IPREG_SYS1_REG_168_IPREG_SYS1                            0xa4a8
#define REG_IPREG_SYS1_REG_169_IPREG_SYS1                            0xa4a9
#define REG_IPREG_SYS1_REG_170_IPREG_SYS1                            0xa4aa
#define REG_IPREG_SYS1_REG_171_IPREG_SYS1                            0xa4ab
#define REG_IPREG_SYS1_REG_172_IPREG_SYS1                            0xa4ac
#define REG_IPREG_SYS1_REG_173_IPREG_SYS1                            0xa4ad

/* IPREG_SYS2 */
#define REG_IPREG_SYS2_REG_24_IPREG_SYS2                             0xa518
#define REG_IPREG_SYS2_REG_25_IPREG_SYS2                             0xa519
#define REG_IPREG_SYS2_REG_32_IPREG_SYS2                             0xa520
#define REG_IPREG_SYS2_REG_33_IPREG_SYS2                             0xa521
#define REG_IPREG_SYS2_REG_40_IPREG_SYS2                             0xa528
#define REG_IPREG_SYS2_REG_41_IPREG_SYS2                             0xa529
#define REG_IPREG_SYS2_REG_48_IPREG_SYS2                             0xa530
#define REG_IPREG_SYS2_REG_49_IPREG_SYS2                             0xa531
#define REG_IPREG_SYS2_REG_56_IPREG_SYS2                             0xa538
#define REG_IPREG_SYS2_REG_57_IPREG_SYS2                             0xa539
#define REG_IPREG_SYS2_REG_64_IPREG_SYS2                             0xa540
#define REG_IPREG_SYS2_REG_65_IPREG_SYS2                             0xa541
#define REG_IPREG_SYS2_REG_123_IPREG_SYS2                            0xa57b
#define REG_IPREG_SYS2_REG_128_IPREG_SYS2                            0xa580
#define REG_IPREG_SYS2_REG_129_IPREG_SYS2                            0xa581
#define REG_IPREG_SYS2_REG_130_IPREG_SYS2                            0xa582
#define REG_IPREG_SYS2_REG_131_IPREG_SYS2                            0xa583
#define REG_IPREG_SYS2_REG_132_IPREG_SYS2                            0xa584

/* IPREG_TOP1 */
#define REG_FIFO_STATUS_IPREG_TOP1                                   0xa200
#define REG_PRG_ERR_STATUS_IPREG_TOP1                                0xa202
#define REG_FIFO_SRAM_OVRD_IPREG_TOP1                                0xa205
#define REG_I2CM_COMMAND_0_IPREG_TOP1                                0xa206
#define REG_I2CM_COMMAND_1_IPREG_TOP1                                0xa207
#define REG_I2CM_COMMAND_2_IPREG_TOP1                                0xa208
#define REG_I2CM_COMMAND_3_IPREG_TOP1                                0xa209
#define REG_I2CM_DEV_PROFILE0_IPREG_TOP1                             0xa20e
#define REG_I2CM_DEV_PROFILE1_IPREG_TOP1                             0xa20f
#define REG_I2CM_DEV_PROFILE2_IPREG_TOP1                             0xa210
#define REG_I2CM_DEV_PROFILE3_IPREG_TOP1                             0xa211
#define REG_I2CM_CONTROL_IPREG_TOP1                                  0xa216
#define REG_I2CM_STATUS_IPREG_TOP1                                   0xa218
#define REG_I2CM_EXT_DEV_STATUS_IPREG_TOP1                           0xa21a
#define REG_I2CM_RD_DATA0_IPREG_TOP1                                 0xa21b
#define REG_I2CM_RD_DATA1_IPREG_TOP1                                 0xa21c
#define REG_I2CM_RD_DATA2_IPREG_TOP1                                 0xa21d
#define REG_I2CM_RD_DATA3_IPREG_TOP1                                 0xa21e
#define REG_I2CM_RD_DATA4_IPREG_TOP1                                 0xa21f
#define REG_I2CM_RD_DATA5_IPREG_TOP1                                 0xa220
#define REG_I2CM_RD_DATA6_IPREG_TOP1                                 0xa221
#define REG_I2CM_RD_DATA7_IPREG_TOP1                                 0xa222
#define REG_I2CM_RD_DATA8_IPREG_TOP1                                 0xa223
#define REG_I2CM_RD_DATA9_IPREG_TOP1                                 0xa224
#define REG_I2CM_RD_DATA10_IPREG_TOP1                                0xa225
#define REG_I2CM_RD_DATA11_IPREG_TOP1                                0xa226
#define REG_I2CM_RD_DATA12_IPREG_TOP1                                0xa227
#define REG_I2CM_RD_DATA13_IPREG_TOP1                                0xa228
#define REG_I2CM_RD_DATA14_IPREG_TOP1                                0xa229
#define REG_I2CM_RD_DATA15_IPREG_TOP1                                0xa22a
#define REG_I2CM_RD_DATA16_IPREG_TOP1                                0xa22b
#define REG_I2CM_RD_DATA17_IPREG_TOP1                                0xa22c
#define REG_I2CM_RD_DATA18_IPREG_TOP1                                0xa22d
#define REG_I2CM_RD_DATA19_IPREG_TOP1                                0xa22e
#define REG_I2CM_RD_DATA20_IPREG_TOP1                                0xa22f
#define REG_I2CM_WR_DATA0_IPREG_TOP1                                 0xa233
#define REG_I2CM_WR_DATA1_IPREG_TOP1                                 0xa234
#define REG_I2CM_WR_DATA2_IPREG_TOP1                                 0xa235
#define REG_I2CM_WR_DATA3_IPREG_TOP1                                 0xa236
#define REG_I2CM_WR_DATA4_IPREG_TOP1                                 0xa237
#define REG_I2CM_WR_DATA5_IPREG_TOP1                                 0xa238
#define REG_DEBUG_CONTROL_IPREG_TOP1                                 0xa23d
#define REG_SRAM_ROM_MARGIN_CTRL_IPREG_TOP1                          0xa23e
#define REG_SIFS_IXC_ERROR_STATUS_IPREG_TOP1                         0xa24b
#define REG_EDMP_PRGRM_IRQ0_0_IPREG_TOP1                             0xa24f
#define REG_EDMP_PRGRM_IRQ0_1_IPREG_TOP1                             0xa250
#define REG_EDMP_PRGRM_IRQ1_0_IPREG_TOP1                             0xa251
#define REG_EDMP_PRGRM_IRQ1_1_IPREG_TOP1                             0xa252
#define REG_EDMP_PRGRM_IRQ2_0_IPREG_TOP1                             0xa253
#define REG_EDMP_PRGRM_IRQ2_1_IPREG_TOP1                             0xa254
#define REG_EDMP_SP_START_ADDR_IPREG_TOP1                            0xa255
#define REG_PMC_AGC_TIMER_CFG_IPREG_TOP1                             0xa256
#define REG_PMC_AGC_TIMER_CFG_0_IPREG_TOP1                           0xa257
#define REG_SMC_CONTROL_0_IPREG_TOP1                                 0xa258
#define REG_SMC_CONTROL_1_IPREG_TOP1                                 0xa259
#define REG_SMC_ANA_LAT_TRIM_0_IPREG_TOP1                            0xa25a
#define REG_SMC_ANA_LAT_TRIM_1_IPREG_TOP1                            0xa25b
#define REG_SMC_ANA_LAT_TRIM_STC_IPREG_TOP1                          0xa25c
#define REG_SMC_ANA_LAT_TRIM_STC_0_IPREG_TOP1                        0xa25d
#define REG_SMC_DEC1_TON_IPREG_TOP1                                  0xa25e
#define REG_SMC_ODR_STAT_IPREG_TOP1                                  0xa25f
#define REG_ACCEL_DEBUG_IPREG_TOP1                                   0xa260
#define REG_STC_CONFIG_IPREG_TOP1                                    0xa263
#define REG_STC_TICK_PER_FRC_0_IPREG_TOP1                            0xa264
#define REG_STC_TICK_PER_FRC_1_IPREG_TOP1                            0xa265
#define REG_STC_TICK_PER_FRC_SUB_IPREG_TOP1                          0xa266
#define REG_SREG_CTRL_IPREG_TOP1                                     0xa267
#define REG_SIFS_I3C_STC_CFG_IPREG_TOP1                              0xa268
#define REG_INT_PULSE_MIN_ON_INTF0_IPREG_TOP1                        0xa269
#define REG_INT_PULSE_MIN_ON_INTF1_IPREG_TOP1                        0xa26a
#define REG_INT_PULSE_MIN_OFF_INTF0_IPREG_TOP1                       0xa26b
#define REG_INT_PULSE_MIN_OFF_INTF1_IPREG_TOP1                       0xa26c
#define REG_ISR_0_7_IPREG_TOP1                                       0xa26e
#define REG_ISR_8_15_IPREG_TOP1                                      0xa26f
#define REG_ISR_16_23_IPREG_TOP1                                     0xa270
#define REG_STATUS_MASK_PIN_0_7_IPREG_TOP1                           0xa271
#define REG_STATUS_MASK_PIN_8_15_IPREG_TOP1                          0xa272
#define REG_STATUS_MASK_PIN_16_23_IPREG_TOP1                         0xa273
#define REG_INT_I2CM_SOURCE_IPREG_TOP1                               0xa274
#define REG_PSEQ_STATUS_IPREG_TOP1                                   0xa27d
#define REG_ACCEL_WOM_X_THR_IPREG_TOP1                               0xa27e
#define REG_ACCEL_WOM_Y_THR_IPREG_TOP1                               0xa27f
#define REG_ACCEL_WOM_Z_THR_IPREG_TOP1                               0xa280
#define REG_CKGA_CONFIG_IPREG_TOP1                                   0xa281
#define REG_IREG_OTP_CFG_IPREG_TOP1                                  0xa289
#define REG_OTP_CONFIG0_IPREG_TOP1                                   0xa28b
#define REG_HEAT_CTRL2_IPREG_TOP1                                    0xa28f
#define REG_SELFTEST_IPREG_TOP1                                      0xa290
#define REG_IPREG_MISC_IPREG_TOP1                                    0xa297
#define REG_SW_RCOSC1_TRIM_IPREG_TOP1                                0xa2a1
#define REG_SW_PLL1_TRIM_IPREG_TOP1                                  0xa2a2
#define REG_FIFO_SRAM_SLEEP_IPREG_TOP1                               0xa2a7
#define REG_FIFO_SRAM_RET_IPREG_TOP1                                 0xa2a8
#define REG_EDMP_SGI_0_IPREG_TOP1                                    0xa2fe
#define REG_EDMP_SGI_1_IPREG_TOP1                                    0xa2ff

/* DREG_BANK1 */
#define REG_ACCEL_DATA_X_0_DREG_BANK1                                0x00
#define REG_ACCEL_DATA_X_1_DREG_BANK1                                0x01
#define REG_ACCEL_DATA_Y_0_DREG_BANK1                                0x02
#define REG_ACCEL_DATA_Y_1_DREG_BANK1                                0x03
#define REG_ACCEL_DATA_Z_0_DREG_BANK1                                0x04
#define REG_ACCEL_DATA_Z_1_DREG_BANK1                                0x05
#define REG_GYRO_DATA_X_0_DREG_BANK1                                 0x06
#define REG_GYRO_DATA_X_1_DREG_BANK1                                 0x07
#define REG_GYRO_DATA_Y_0_DREG_BANK1                                 0x08
#define REG_GYRO_DATA_Y_1_DREG_BANK1                                 0x09
#define REG_GYRO_DATA_Z_0_DREG_BANK1                                 0x0a
#define REG_GYRO_DATA_Z_1_DREG_BANK1                                 0x0b
#define REG_TEMP_DATA_0_DREG_BANK1                                   0x0c
#define REG_TEMP_DATA_1_DREG_BANK1                                   0x0d
#define REG_TMST_FSYNC_DATA_0_DREG_BANK1                             0x0e
#define REG_TMST_FSYNC_DATA_1_DREG_BANK1                             0x0f
#define REG_PWR_MGMT0_DREG_BANK1                                     0x10
#define REG_PWR_MGMT1_DREG_BANK1                                     0x11
#define REG_FIFO_COUNT_0_DREG_BANK1                                  0x12
#define REG_FIFO_COUNT_1_DREG_BANK1                                  0x13
#define REG_FIFO_DATA_DREG_BANK1                                     0x14
#define REG_INT1_CONFIG0_DREG_BANK1                                  0x16
#define REG_INT1_CONFIG1_DREG_BANK1                                  0x17
#define REG_INT1_CONFIG2_DREG_BANK1                                  0x18
#define REG_INT1_STATUS0_DREG_BANK1                                  0x19
#define REG_INT1_STATUS1_DREG_BANK1                                  0x1a
#define REG_ACCEL_CONFIG0_DREG_BANK1                                 0x1b
#define REG_GYRO_CONFIG0_DREG_BANK1                                  0x1c
#define REG_FIFO_CONFIG0_DREG_BANK1                                  0x1d
#define REG_FIFO_CONFIG1_0_DREG_BANK1                                0x1e
#define REG_FIFO_CONFIG1_1_DREG_BANK1                                0x1f
#define REG_FIFO_CONFIG2_DREG_BANK1                                  0x20
#define REG_FIFO_CONFIG3_DREG_BANK1                                  0x21
#define REG_FIFO_CONFIG4_DREG_BANK1                                  0x22
#define REG_TMST_WOM_CONFIG_DREG_BANK1                               0x23
#define REG_FSYNC_CONFIG0_DREG_BANK1                                 0x24
#define REG_FSYNC_CONFIG1_DREG_BANK1                                 0x25
#define REG_OTP_HEATER_RTC_CONFIG_DREG_BANK1                         0x26
#define REG_DMP_EXT_SEN_ODR_CFG_DREG_BANK1                           0x27
#define REG_ODR_DECIMATE_CONFIG_DREG_BANK1                           0x28
#define REG_EDMP_APEX_EN0_DREG_BANK1                                 0x29
#define REG_EDMP_APEX_EN1_DREG_BANK1                                 0x2a
#define REG_APEX_BUFFER_MGMT_DREG_BANK1                              0x2b
#define REG_INTF_CONFIG0_DREG_BANK1                                  0x2c
#define REG_INTF_CONFIG1_OVRD_DREG_BANK1                             0x2d
#define REG_INTF_AUX_CONFIG_DREG_BANK1                               0x2e
#define REG_IOC_PAD_SCENARIO_DREG_BANK1                              0x2f
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_DREG_BANK1                     0x30
#define REG_IOC_PAD_SCENARIO_OVRD_DREG_BANK1                         0x31
#define REG_DRIVE_CONFIG0_DREG_BANK1                                 0x32
#define REG_DRIVE_CONFIG1_DREG_BANK1                                 0x33
#define REG_DRIVE_CONFIG2_DREG_BANK1                                 0x34
#define REG_REG_MISC1_DREG_BANK1                                     0x35
#define REG_REG_MISC3_DREG_BANK1                                     0x36
#define REG_INT_APEX_CONFIG0_DREG_BANK1                              0x39
#define REG_INT_APEX_CONFIG1_DREG_BANK1                              0x3a
#define REG_INT_APEX_STATUS0_DREG_BANK1                              0x3b
#define REG_INT_APEX_STATUS1_DREG_BANK1                              0x3c
#define REG_INTF_CONFIG_OVRD_AUX1_DREG_BANK1                         0x42
#define REG_ACCEL_DATA_X_AUX1_0_DREG_BANK1                           0x44
#define REG_ACCEL_DATA_X_AUX1_1_DREG_BANK1                           0x45
#define REG_ACCEL_DATA_Y_AUX1_0_DREG_BANK1                           0x46
#define REG_ACCEL_DATA_Y_AUX1_1_DREG_BANK1                           0x47
#define REG_ACCEL_DATA_Z_AUX1_0_DREG_BANK1                           0x48
#define REG_ACCEL_DATA_Z_AUX1_1_DREG_BANK1                           0x49
#define REG_GYRO_DATA_X_AUX1_0_DREG_BANK1                            0x4a
#define REG_GYRO_DATA_X_AUX1_1_DREG_BANK1                            0x4b
#define REG_GYRO_DATA_Y_AUX1_0_DREG_BANK1                            0x4c
#define REG_GYRO_DATA_Y_AUX1_1_DREG_BANK1                            0x4d
#define REG_GYRO_DATA_Z_AUX1_0_DREG_BANK1                            0x4e
#define REG_GYRO_DATA_Z_AUX1_1_DREG_BANK1                            0x4f
#define REG_TEMP_DATA_AUX1_0_DREG_BANK1                              0x50
#define REG_TEMP_DATA_AUX1_1_DREG_BANK1                              0x51
#define REG_TMST_FSYNC_DATA_AUX1_0_DREG_BANK1                        0x52
#define REG_TMST_FSYNC_DATA_AUX1_1_DREG_BANK1                        0x53
#define REG_PWR_MGMT_AUX1_DREG_BANK1                                 0x54
#define REG_FS_SEL_AUX1_DREG_BANK1                                   0x55
#define REG_INT2_CONFIG0_DREG_BANK1                                  0x56
#define REG_INT2_CONFIG1_DREG_BANK1                                  0x57
#define REG_INT2_CONFIG2_DREG_BANK1                                  0x58
#define REG_INT2_STATUS0_DREG_BANK1                                  0x59
#define REG_INT2_STATUS1_DREG_BANK1                                  0x5a
#define REG_INTF_CONFIG_OVRD_AUX2_DREG_BANK1                         0x5c
#define REG_ACCEL_DATA_X_AUX2_0_DREG_BANK1                           0x5e
#define REG_ACCEL_DATA_X_AUX2_1_DREG_BANK1                           0x5f
#define REG_ACCEL_DATA_Y_AUX2_0_DREG_BANK1                           0x60
#define REG_ACCEL_DATA_Y_AUX2_1_DREG_BANK1                           0x61
#define REG_ACCEL_DATA_Z_AUX2_0_DREG_BANK1                           0x62
#define REG_ACCEL_DATA_Z_AUX2_1_DREG_BANK1                           0x63
#define REG_GYRO_DATA_X_AUX2_0_DREG_BANK1                            0x64
#define REG_GYRO_DATA_X_AUX2_1_DREG_BANK1                            0x65
#define REG_GYRO_DATA_Y_AUX2_0_DREG_BANK1                            0x66
#define REG_GYRO_DATA_Y_AUX2_1_DREG_BANK1                            0x67
#define REG_GYRO_DATA_Z_AUX2_0_DREG_BANK1                            0x68
#define REG_GYRO_DATA_Z_AUX2_1_DREG_BANK1                            0x69
#define REG_TEMP_DATA_AUX2_0_DREG_BANK1                              0x6a
#define REG_TEMP_DATA_AUX2_1_DREG_BANK1                              0x6b
#define REG_TMST_FSYNC_DATA_AUX2_0_DREG_BANK1                        0x6c
#define REG_TMST_FSYNC_DATA_AUX2_1_DREG_BANK1                        0x6d
#define REG_PWR_MGMT_AUX2_DREG_BANK1                                 0x6e
#define REG_FS_SEL_AUX2_DREG_BANK1                                   0x6f
#define REG_INT_AUX2_CONFIG_DREG_BANK1                               0x70
#define REG_INT_AUX2_STATUS_DREG_BANK1                               0x71
#define REG_WHO_AM_I_DREG_BANK1                                      0x72
#define REG_REG_HOST_MSG_DREG_BANK1                                  0x73
#define REG_RESERVED_OTP_BYTE0_DREG_BANK1                            0x74
#define REG_RESERVED_OTP_BYTE1_DREG_BANK1                            0x75
#define REG_IREG_ADDR_15_8_DREG_BANK1                                0x7c
#define REG_IREG_ADDR_7_0_DREG_BANK1                                 0x7d
#define REG_IREG_DATA_DREG_BANK1                                     0x7e
#define REG_REG_MISC2_DREG_BANK1                                     0x7f

/* DREG_BANK2 */


/* ---------------------------------------------------------------------------
 * register IPREG_BAR
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_BAR_REG_17
 * Register Name : IPREG_BAR_REG_17
 */

/*
 * pd_mb_vbgr_test_b_d2a
 * [Supports Dynamic Change] Used to force enable areg ibias and ireg ibias (OR with PSEQ)
 */
#define REG_IPREG_BAR_REG_17_PD_MB_VBGR_TEST_B_D2A_POS      0x01
#define REG_IPREG_BAR_REG_17_PD_MB_VBGR_TEST_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_17_PD_MB_VBGR_TEST_B_D2A_POS)

/*
 * pd_minibg_b_d2a
 * [Supports Dynamic Change] Minibg force enable (OR with PSEQ)
 */
#define REG_IPREG_BAR_REG_17_PD_MINIBG_B_D2A_POS      0x02
#define REG_IPREG_BAR_REG_17_PD_MINIBG_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_17_PD_MINIBG_B_D2A_POS)

/*
 * REG_IPREG_BAR_REG_20
 * Register Name : IPREG_BAR_REG_20
 */

/*
 * io_well_bias_comp_sel_d2a
 * [Supports Dynamic Change] Pin function: when high, shorts two of the atp busses
 * Requirement at system level: when high, should not allow any other IP to connect to atp busses
 */
#define REG_IPREG_BAR_REG_20_IO_WELL_BIAS_COMP_SEL_D2A_POS      0x00
#define REG_IPREG_BAR_REG_20_IO_WELL_BIAS_COMP_SEL_D2A_MASK     0x01



/*
 * REG_IPREG_BAR_REG_58
 * Register Name : IPREG_BAR_REG_58
 */

/*
 * pads_ap_cs_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_58_PADS_AP_CS_FROM_PAD_DISABLE_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_58_PADS_AP_CS_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_PADS_AP_CS_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_ap_cs_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal pull resistor to pull pad up or down depending on direction.
 */
#define REG_IPREG_BAR_REG_58_PADS_AP_CS_PE_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_58_PADS_AP_CS_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_PADS_AP_CS_PE_TRIM_D2A_POS)

/*
 * pads_ap_cs_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up(1) or down(0)
 */
#define REG_IPREG_BAR_REG_58_PADS_AP_CS_PUD_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_58_PADS_AP_CS_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_PADS_AP_CS_PUD_TRIM_D2A_POS)

/*
 * pads_ap_sclk_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_58_PADS_AP_SCLK_FROM_PAD_DISABLE_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_58_PADS_AP_SCLK_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_PADS_AP_SCLK_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_ap_sclk_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal pull resistor to pull pad up or down depending on direction.
 */
#define REG_IPREG_BAR_REG_58_PADS_AP_SCLK_PE_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_58_PADS_AP_SCLK_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_PADS_AP_SCLK_PE_TRIM_D2A_POS)

/*
 * pads_ap_sclk_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up(1) or down(0)
 */
#define REG_IPREG_BAR_REG_58_PADS_AP_SCLK_PUD_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_58_PADS_AP_SCLK_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_PADS_AP_SCLK_PUD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_59
 * Register Name : IPREG_BAR_REG_59
 */

/*
 * pads_ap_sdi_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_59_PADS_AP_SDI_FROM_PAD_DISABLE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_59_PADS_AP_SDI_FROM_PAD_DISABLE_TRIM_D2A_MASK     0x01

/*
 * pads_ap_sdi_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal resistor to pull pad up or down depending on direction choice.
 */
#define REG_IPREG_BAR_REG_59_PADS_AP_SDI_PE_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_59_PADS_AP_SDI_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AP_SDI_PE_TRIM_D2A_POS)

/*
 * pads_ap_sdi_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_59_PADS_AP_SDI_PUD_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_59_PADS_AP_SDI_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AP_SDI_PUD_TRIM_D2A_POS)

/*
 * pads_ap_sdo_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_59_PADS_AP_SDO_FROM_PAD_DISABLE_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_59_PADS_AP_SDO_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AP_SDO_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_ap_sdo_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal resistor to pull pad up or down depending on direction choice.
 */
#define REG_IPREG_BAR_REG_59_PADS_AP_SDO_PE_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_59_PADS_AP_SDO_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AP_SDO_PE_TRIM_D2A_POS)

/*
 * pads_ap_sdo_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_59_PADS_AP_SDO_PUD_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_59_PADS_AP_SDO_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AP_SDO_PUD_TRIM_D2A_POS)

/*
 * pads_aux2_cs_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_59_PADS_AUX2_CS_FROM_PAD_DISABLE_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_59_PADS_AUX2_CS_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AUX2_CS_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_aux2_cs_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal pull resistor to pull pad up or down depending on direction.
 */
#define REG_IPREG_BAR_REG_59_PADS_AUX2_CS_PE_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_59_PADS_AUX2_CS_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_59_PADS_AUX2_CS_PE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_60
 * Register Name : IPREG_BAR_REG_60
 */

/*
 * pads_aux2_cs_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up(1) or down(0)
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX2_CS_PUD_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_60_PADS_AUX2_CS_PUD_TRIM_D2A_MASK     0x01

/*
 * pads_aux_cs_tp3_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Register to control FROM_PAD signal coming from PAD.
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_FROM_PAD_DISABLE_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_aux_cs_tp3_tp_pe_trim_d2a
 * [Supports Dynamic Change] Selects pull direction of the pad using the internal resistor either up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_TP_PE_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_TP_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_TP_PE_TRIM_D2A_POS)

/*
 * pads_aux_cs_tp3_tp_pud_trim_d2a
 * [Supports Dynamic Change] Enables pull of the pad using the internal resistor depending on the direction
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_TP_PUD_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_TP_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_CS_TP3_TP_PUD_TRIM_D2A_POS)

/*
 * pads_aux_sclk_tp2_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Register to control FROM_PAD signal coming from PAD.
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_FROM_PAD_DISABLE_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_aux_sclk_tp2_tp_pe_trim_d2a
 * [Supports Dynamic Change] Selects pull direction of the pad using the internal resistor either up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_TP_PE_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_TP_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_TP_PE_TRIM_D2A_POS)

/*
 * pads_aux_sclk_tp2_tp_pud_trim_d2a
 * [Supports Dynamic Change] Enables pull of the pad using the internal resistor depending on the direction
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_TP_PUD_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_TP_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_SCLK_TP2_TP_PUD_TRIM_D2A_POS)

/*
 * pads_aux_sdi_tp1_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Register to control FROM_PAD signal coming from PAD.
 */
#define REG_IPREG_BAR_REG_60_PADS_AUX_SDI_TP1_FROM_PAD_DISABLE_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_60_PADS_AUX_SDI_TP1_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_60_PADS_AUX_SDI_TP1_FROM_PAD_DISABLE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_61
 * Register Name : IPREG_BAR_REG_61
 */

/*
 * pads_aux_sdi_tp1_tp_pe_trim_d2a
 * [Supports Dynamic Change] Selects pull direction of the pad using the internal resistor either up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDI_TP1_TP_PE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDI_TP1_TP_PE_TRIM_D2A_MASK     0x01

/*
 * pads_aux_sdi_tp1_tp_pud_trim_d2a
 * [Supports Dynamic Change] Enables pull of the pad using the internal resistor depending on the direction
 */
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDI_TP1_TP_PUD_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDI_TP1_TP_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_AUX_SDI_TP1_TP_PUD_TRIM_D2A_POS)

/*
 * pads_aux_sdo_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDO_FROM_PAD_DISABLE_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDO_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_AUX_SDO_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_aux_sdo_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal resistor to pull pad up or down depending on direction choice.
 */
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDO_PE_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDO_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_AUX_SDO_PE_TRIM_D2A_POS)

/*
 * pads_aux_sdo_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDO_PUD_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_61_PADS_AUX_SDO_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_AUX_SDO_PUD_TRIM_D2A_POS)

/*
 * pads_int1_tp0_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Register to control FROM_PAD signal coming from PAD.
 */
#define REG_IPREG_BAR_REG_61_PADS_INT1_TP0_FROM_PAD_DISABLE_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_61_PADS_INT1_TP0_FROM_PAD_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_INT1_TP0_FROM_PAD_DISABLE_TRIM_D2A_POS)

/*
 * pads_int1_tp0_tp_pe_trim_d2a
 * [Supports Dynamic Change] Selects pull direction of the pad using the internal resistor either up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_61_PADS_INT1_TP0_TP_PE_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_61_PADS_INT1_TP0_TP_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_INT1_TP0_TP_PE_TRIM_D2A_POS)

/*
 * pads_int1_tp0_tp_pud_trim_d2a
 * [Supports Dynamic Change] Enables pull of the pad using the internal resistor depending on the direction
 */
#define REG_IPREG_BAR_REG_61_PADS_INT1_TP0_TP_PUD_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_61_PADS_INT1_TP0_TP_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_61_PADS_INT1_TP0_TP_PUD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_62
 * Register Name : IPREG_BAR_REG_62
 */

/*
 * pads_int2_from_pad_disable_trim_d2a
 * [Supports Dynamic Change] Enables/Disables from_pads signal from pad to internal chip
 */
#define REG_IPREG_BAR_REG_62_PADS_INT2_FROM_PAD_DISABLE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_62_PADS_INT2_FROM_PAD_DISABLE_TRIM_D2A_MASK     0x01

/*
 * pads_int2_pe_trim_d2a
 * [Supports Dynamic Change] Enables internal resistor to pull pad up or down depending on direction choice.
 */
#define REG_IPREG_BAR_REG_62_PADS_INT2_PE_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_62_PADS_INT2_PE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_62_PADS_INT2_PE_TRIM_D2A_POS)

/*
 * pads_int2_pud_trim_d2a
 * [Supports Dynamic Change] Selects internal resistor pull direction up (1) or down (0)
 */
#define REG_IPREG_BAR_REG_62_PADS_INT2_PUD_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_62_PADS_INT2_PUD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_62_PADS_INT2_PUD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_63
 * Register Name : IPREG_BAR_REG_63
 */

/*
 * pads_od_pud_strength_trim_d2a
 * [Supports Dynamic Change] Configures drive strength for all output pins in OD mode, which in turn controls VOL level. 0 highest pull down strength, 3 weakest pull down strength.
 */
#define REG_IPREG_BAR_REG_63_PADS_OD_PUD_STRENGTH_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_63_PADS_OD_PUD_STRENGTH_TRIM_D2A_MASK     0x03



/*
 * REG_IPREG_BAR_REG_109
 * Register Name : IPREG_BAR_REG_109
 */

/*
 * pd_gyro_bias_vcmbuffer_b_d2a
 * [Supports Dynamic Change] Power down override for vcmbuffer
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_VCMBUFFER_B_D2A_POS      0x06
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_VCMBUFFER_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_VCMBUFFER_B_D2A_POS)


/* ---------------------------------------------------------------------------
 * register IPREG_ANA
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_ANA_REG_1
 * Register Name : IPREG_ANA_REG_1
 */

/*
 * pd_accel_cp45_st_b_d2a
 * [Supports Dynamic Change] Override to power-down 4.5V CP
 */
#define REG_IPREG_ANA_REG_1_PD_ACCEL_CP45_ST_B_D2A_POS      0x00
#define REG_IPREG_ANA_REG_1_PD_ACCEL_CP45_ST_B_D2A_MASK     0x01

/*
 * pd_accel_st_b_d2a
 * [Supports Dynamic Change] Override to power-down Self-Test Regulator
 */
#define REG_IPREG_ANA_REG_1_PD_ACCEL_ST_B_D2A_POS      0x01
#define REG_IPREG_ANA_REG_1_PD_ACCEL_ST_B_D2A_MASK     (0x01 << REG_IPREG_ANA_REG_1_PD_ACCEL_ST_B_D2A_POS)



/*
 * REG_IPREG_ANA_REG_3
 * Register Name : IPREG_ANA_REG_3
 */

/*
 * gyro_drv_xst_mode_d2a
 * [Supports Dynamic Change] X self test mode selection:
 * 00: ST P/N electrodes driven differentially
 * 01: ST P electrode set to "low" & N electrode only is driven with the ST input signal
 * 10: ST N electrode set to "low" & P electrode only is driven with the ST input signal
 * 11: ST P/N electrodes driven with same polarity (both high or both low), according to the ST input signal
 */
#define REG_IPREG_ANA_REG_3_GYRO_DRV_XST_MODE_D2A_POS      0x00
#define REG_IPREG_ANA_REG_3_GYRO_DRV_XST_MODE_D2A_MASK     0x03

/*
 * gyro_drv_yst_mode_d2a
 * [Supports Dynamic Change] Y self test mode selection:
 * 00: ST P/N electrodes driven differentially
 * 01: ST P electrode set to "low" & N electrode only is driven with the ST input signal
 * 10: ST N electrode set to "low" & P electrode only is driven with the ST input signal
 * 11: ST P/N electrodes driven with same polarity (both high or both low), according to the ST input signal
 */
#define REG_IPREG_ANA_REG_3_GYRO_DRV_YST_MODE_D2A_POS      0x02
#define REG_IPREG_ANA_REG_3_GYRO_DRV_YST_MODE_D2A_MASK     (0x03 << REG_IPREG_ANA_REG_3_GYRO_DRV_YST_MODE_D2A_POS)

/*
 * gyro_drv_zst_mode_d2a
 * [Supports Dynamic Change] Z self test mode selection:
 * 00: ST P/N electrodes driven differentially
 * 01: ST P electrode set to "low" & N electrode only is driven with the ST input signal
 * 10: ST N electrode set to "low" & P electrode only is driven with the ST input signal
 * 11: ST P/N electrodes driven with same polarity (both high or both low), according to the ST input signal
 */
#define REG_IPREG_ANA_REG_3_GYRO_DRV_ZST_MODE_D2A_POS      0x04
#define REG_IPREG_ANA_REG_3_GYRO_DRV_ZST_MODE_D2A_MASK     (0x03 << REG_IPREG_ANA_REG_3_GYRO_DRV_ZST_MODE_D2A_POS)

/*
 * gyro_drv_xst_pol_d2a
 * [Supports Dynamic Change] X self test polarity selection
 */
#define REG_IPREG_ANA_REG_3_GYRO_DRV_XST_POL_D2A_POS      0x06
#define REG_IPREG_ANA_REG_3_GYRO_DRV_XST_POL_D2A_MASK     (0x01 << REG_IPREG_ANA_REG_3_GYRO_DRV_XST_POL_D2A_POS)

/*
 * gyro_drv_yst_pol_d2a
 * [Supports Dynamic Change] Y self test polarity selection
 */
#define REG_IPREG_ANA_REG_3_GYRO_DRV_YST_POL_D2A_POS      0x07
#define REG_IPREG_ANA_REG_3_GYRO_DRV_YST_POL_D2A_MASK     (0x01 << REG_IPREG_ANA_REG_3_GYRO_DRV_YST_POL_D2A_POS)



/*
 * REG_IPREG_ANA_REG_4
 * Register Name : IPREG_ANA_REG_4
 */

/*
 * gyro_drv_zst_pol_d2a
 * [Supports Dynamic Change] Z self test polarity selection
 */
#define REG_IPREG_ANA_REG_4_GYRO_DRV_ZST_POL_D2A_POS      0x00
#define REG_IPREG_ANA_REG_4_GYRO_DRV_ZST_POL_D2A_MASK     0x01


/* ---------------------------------------------------------------------------
 * register DREG_TOP1
 * ---------------------------------------------------------------------------*/

/*
 * REG_PWR_MGMT0
 * Register Name : PWR_MGMT0
 */

/*
 * accel_mode
 * [Supports Dynamic Change] Accelerometer Power-Mode for the UI/AP FIFO:
 *   00: OFF
 *   01: OFF
 *   10: LP
 *   11: LN
 */
#define REG_PWR_MGMT0_ACCEL_MODE_POS      0x00
#define REG_PWR_MGMT0_ACCEL_MODE_MASK     0x03

/*
 * gyro_mode
 * [Supports Dynamic Change] Gyroscope Power-Mode for the UI/AP FIFO:
 *   00: OFF
 *   01: STANDBY
 *   10: LP
 *   11: LN
 */
#define REG_PWR_MGMT0_GYRO_MODE_POS      0x02
#define REG_PWR_MGMT0_GYRO_MODE_MASK     (0x03 << REG_PWR_MGMT0_GYRO_MODE_POS)

/*
 * accel_vre_sel
 * [Supports Dynamic Change] Determines the analog full-scale when user full-scale <=8g
 * 0: 8g (improved noise perf)
 * 1: 16g (improved vre perf)
 */
#define REG_PWR_MGMT0_ACCEL_VRE_SEL_POS      0x04
#define REG_PWR_MGMT0_ACCEL_VRE_SEL_MASK     (0x01 << REG_PWR_MGMT0_ACCEL_VRE_SEL_POS)



/*
 * REG_INT1_CONFIG2
 * Register Name : INT1_CONFIG2
 */

/*
 * int1_drive
 * Sets INT1 PAD in to Open-drain or Push-pull
 * 1 : Open-drain
 * 0 : Push-pull
 */
#define REG_INT1_CONFIG2_INT1_DRIVE_POS      0x02
#define REG_INT1_CONFIG2_INT1_DRIVE_MASK     (0x01 << REG_INT1_CONFIG2_INT1_DRIVE_POS)



/*
 * REG_ACCEL_CONFIG0
 * Register Name : ACCEL_CONFIG0
 */

/*
 * accel_odr
 * [Supports Dynamic Change] Accelerometer Output Data Rate at the UI/AP FIFO. ODR frequency:
 *   0 -> 6.4k (LN only)
 *   1 -> 6.4k (LN only)
 *   2 -> 6.4k (LN only)
 *   3 -> 6.4k (LN only)
 *   4 -> 3.2k (LN only)
 *   5 -> 1.6k (LN only)
 *   6 -> 800 (default, LN only))
 *   7 -> 400
 *   8 -> 200
 *   9 -> 100
 *   10 -> 50
 *   11 -> 25
 *   12 -> 12.5
 *   13 -> 6.25      (LP only)
 *   14 -> 3.125    (LP only)
 *   15 -> 1.5625  (LP only)
 *
 * This field can be changed on-the-fly even if accel sensor is already on
 */
#define REG_ACCEL_CONFIG0_ACCEL_ODR_POS      0x00
#define REG_ACCEL_CONFIG0_ACCEL_ODR_MASK     0x0f



/*
 * REG_GYRO_CONFIG0
 * Register Name : GYRO_CONFIG0
 */

/*
 * gyro_odr
 * [Supports Dynamic Change] Gyroscope Output Data Rate at the UI/AP FIFO. ODR frequency:
 *   0 -> 6.4k (LN only)
 *   1 -> 6.4k (LN only)
 *   2 -> 6.4k (LN only)
 *   3 -> 6.4k (LN only)
 *   4 -> 3.2k (LN only)
 *   5 -> 1.6k (LN only)
 *   6 -> 800 (default, LN only))
 *   7 -> 400
 *   8 -> 200
 *   9 -> 100
 *   10 -> 50
 *   11 -> 25
 *   12 -> 12.5
 *   13 -> 6.25      (LP only)
 *   14 -> 3.125    (LP only)
 *   15 -> 1.5625  (LP only)
 *
 * This field can be changed on-the-fly even if gyro sensor is already on
 */
#define REG_GYRO_CONFIG0_GYRO_ODR_POS      0x00
#define REG_GYRO_CONFIG0_GYRO_ODR_MASK     0x0f



/*
 * REG_FIFO_CONFIG0
 * Register Name : FIFO_CONFIG0
 */

/*
 * fifo_depth
 * Set the FIFO depth in bytes. The minimum depth is 256 bytes, which is also the granularity of the FIFO space. The FIFO space start address is fixed and set to: fifo_phy_start_addr = (FIFO_IP_SRAM_NROW * 4) – ((fifo_depth+1) * 256)
 * The effective number of choices is capped by FIFO_MAX_DEPTH parameter. As an example, if FIFO_MAX_DEPTH=3 then fifo_depth[5:0] can assume the following values: 0, 1, 2, 3; the remaining choiches must be considered as reserved.
 * 0 : 256
 * 1 : 512
 * 2 : 768
 * 3 : 1024
 * 4 : 1280
 * ...
 * 62 : 16128
 * 63 : 16384
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG0_FIFO_DEPTH_POS      0x00
#define REG_FIFO_CONFIG0_FIFO_DEPTH_MASK     0x3f

/*
 * fifo_mode
 * [Supports Dynamic Change] Set the FIFO operation mode.
 * 2’b00: Bypass (disabled)
 * 2’b01: Stream mode - Frames are overwritten when the FIFO full condition is reached. Supported only for 8, 16, 20 bytes frame size. Whether this mode is selected for 32 or 64 bytes frame sizes, FIFO remains in Bypass mode.
 * 2’b10: Stop-on-full mode - Frames are not stored in FIFO once the FIFO full condition is reached
 * 2’b11: Reserved
 */
#define REG_FIFO_CONFIG0_FIFO_MODE_POS      0x06
#define REG_FIFO_CONFIG0_FIFO_MODE_MASK     (0x03 << REG_FIFO_CONFIG0_FIFO_MODE_POS)



/*
 * REG_FIFO_CONFIG1_0
 * Register Name : FIFO_CONFIG1_0
 */

/*
 * fifo_wm_th
 * [Supports Dynamic Change] FIFO watermark threshold. When set to 0, the watermark is disabled.
 * When writing new threshold value, user must first write threshold LSByte (bits [7:0]), then MSByte (bits [15:8]). New threshold register value will take effect only when MSByte is written. MSByte write pulse is used to check watermark level and generate WM interrupt event.
 * Can be changed on-the-fly.
 */
#define REG_FIFO_CONFIG1_0_FIFO_WM_TH_POS      0x00
#define REG_FIFO_CONFIG1_0_FIFO_WM_TH_MASK     0xff



/*
 * REG_FIFO_CONFIG1_1
 * Register Name : FIFO_CONFIG1_1
 */

/*
 * fifo_wm_th
 * [Supports Dynamic Change] FIFO watermark threshold. When set to 0, the watermark is disabled.
 * When writing new threshold value, user must first write threshold LSByte (bits [7:0]), then MSByte (bits [15:8]). New threshold register value will take effect only when MSByte is written. MSByte write pulse is used to check watermark level and generate WM interrupt event.
 * Can be changed on-the-fly.
 */
#define REG_FIFO_CONFIG1_1_FIFO_WM_TH_POS      0x00
#define REG_FIFO_CONFIG1_1_FIFO_WM_TH_MASK     0xff



/*
 * REG_FIFO_CONFIG2
 * Register Name : FIFO_CONFIG2
 */

/*
 * fifo_frame_size
 * Select the frame size when FIFO write port interface is AHB (fifo_bus_intf_sel = 1)
 * 3’b000: 8 bytes
 * 3’b001: 16 bytes
 * 3’b010: 20 bytes
 * 3’b011: 32 bytes
 * 3’b100: 64 bytes
 * Others: reserved
 * It must be changed when FIFO is disabled (Bypass mode).
 * When the FIFO write port interface is SREG, the frame size is managed by the SREG IP through sreg_fifo_frame_size port when FIFO is enabled, meaning SREG IP provides the proper frame size based on sensor configuration and also provides a FIFO flush after the size update to reset the whole FIFO.
 */
#define REG_FIFO_CONFIG2_FIFO_FRAME_SIZE_POS      0x00
#define REG_FIFO_CONFIG2_FIFO_FRAME_SIZE_MASK     0x07

/*
 * fifo_wr_wm_gt_th
 * Set write watermark interrupt generating condition.
 * 0: write watermark interrupt generated when counter is equal to threshold
 * 1: write watermark interrupt generated when counter is greater than or equal to threshold
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_WR_WM_GT_TH_POS      0x03
#define REG_FIFO_CONFIG2_FIFO_WR_WM_GT_TH_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_WR_WM_GT_TH_POS)

/*
 * fifo_int_ovfl
 * Select whether the FIFO full and FIFO watermark interrupts are generated continuously when FIFO is in overflow
 * 0: interrupts stops when FIFO is overflowed
 * 1: interrupts are continuously generated when FIFO is overflowed
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_INT_OVFL_POS      0x04
#define REG_FIFO_CONFIG2_FIFO_INT_OVFL_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_INT_OVFL_POS)

/*
 * fifo_addr_space_lock
 * Prevents write accesses from the bus to the FIFO storage area to avoid FIFO data corruption.
 * 0: write allowed
 * 1: write not allowed
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_ADDR_SPACE_LOCK_POS      0x05
#define REG_FIFO_CONFIG2_FIFO_ADDR_SPACE_LOCK_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_ADDR_SPACE_LOCK_POS)

/*
 * fifo_bus_intf_sel
 * Select the FIFO write port interface.
 * 0: SREG interface
 * 1: AHB Interface
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_BUS_INTF_SEL_POS      0x06
#define REG_FIFO_CONFIG2_FIFO_BUS_INTF_SEL_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_BUS_INTF_SEL_POS)

/*
 * fifo_flush
 * [Supports Dynamic Change] FIFO flush command. When set high the FIFO is flushed, meaning the pointers and control logic is reset. Configuration registers are not reset. The register is auto-cleared by hardware.
 * Can be changed on-the-fly.
 */
#define REG_FIFO_CONFIG2_FIFO_FLUSH_POS      0x07
#define REG_FIFO_CONFIG2_FIFO_FLUSH_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_FLUSH_POS)



/*
 * REG_FIFO_CONFIG3
 * Register Name : FIFO_CONFIG3
 */

/*
 * fifo_if_en
 * [Supports Dynamic Change] Enable the SREG-FIFO interface. The SREG-FIFO interface should be enabled when the FIFO is also enabled (i.e., not in bypass mode), so a standard enable sequence is: 1) Enable FIFO. 2) Enable SREG-FIFO interface. The opposite for the disable sequence. To prevent power drain, sreg_fifo_if_en should be set to 0 if FIFO is in bypass mode.
 */
#define REG_FIFO_CONFIG3_FIFO_IF_EN_POS      0x00
#define REG_FIFO_CONFIG3_FIFO_IF_EN_MASK     0x01

/*
 * fifo_accel_en
 * Enable accel data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_ACCEL_EN_POS      0x01
#define REG_FIFO_CONFIG3_FIFO_ACCEL_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_ACCEL_EN_POS)

/*
 * fifo_gyro_en
 * Enable gyro data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_GYRO_EN_POS      0x02
#define REG_FIFO_CONFIG3_FIFO_GYRO_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_GYRO_EN_POS)

/*
 * fifo_hires_en
 * Enable high resolution accel and gyro data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_HIRES_EN_POS      0x03
#define REG_FIFO_CONFIG3_FIFO_HIRES_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_HIRES_EN_POS)

/*
 * fifo_es0_en
 * Enable External Sensor 0 data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_ES0_EN_POS      0x04
#define REG_FIFO_CONFIG3_FIFO_ES0_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_ES0_EN_POS)

/*
 * fifo_es1_en
 * Enable External Sensor 1 data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_ES1_EN_POS      0x05
#define REG_FIFO_CONFIG3_FIFO_ES1_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_ES1_EN_POS)



/*
 * REG_FIFO_CONFIG4
 * Register Name : FIFO_CONFIG4
 */

/*
 * fifo_es0_6b_9b
 * Select how many valid bytes External Sensor 0 provides
 * 0 : 6 bytes
 * 1 : 9 bytes
 */
#define REG_FIFO_CONFIG4_FIFO_ES0_6B_9B_POS      0x00
#define REG_FIFO_CONFIG4_FIFO_ES0_6B_9B_MASK     0x01

/*
 * fifo_tmst_fsync_en
 * Enable the insertion of the Timestamp or FSYNC data into FIFO frame
 * 0 : No Timestamp/FSYNC data inserted into FIFO frame (timestamp fields are 0x0000). fsync_tag_en bit in FIFO header is 0
 * 1 : Timestamp/FSYNC data inserted into FIFO frame. fsync_tag_en bit in FIFO header is set on a FSYNC trigger event
 */
#define REG_FIFO_CONFIG4_FIFO_TMST_FSYNC_EN_POS      0x01
#define REG_FIFO_CONFIG4_FIFO_TMST_FSYNC_EN_MASK     (0x01 << REG_FIFO_CONFIG4_FIFO_TMST_FSYNC_EN_POS)

/*
 * fifo_comp_en
 * Enable the FIFO compression algorithm
 */
#define REG_FIFO_CONFIG4_FIFO_COMP_EN_POS      0x02
#define REG_FIFO_CONFIG4_FIFO_COMP_EN_MASK     (0x01 << REG_FIFO_CONFIG4_FIFO_COMP_EN_POS)

/*
 * fifo_comp_nc_flow_cfg
 * Configures the compression algorithm to write non-compressed frames at a certain rate
 * 0 : Non-compressed frame flow is disabled
 * 1 : Non-compressed frame every 8 frames
 * 2 : Non-compressed frame every 16 frames
 * 3 : Non-compressed frame every 32 frames
 * 4 : Non-compressed frame every 64 frames
 * 5 : Non-compressed frame every 128 frames
 */
#define REG_FIFO_CONFIG4_FIFO_COMP_NC_FLOW_CFG_POS      0x03
#define REG_FIFO_CONFIG4_FIFO_COMP_NC_FLOW_CFG_MASK     (0x07 << REG_FIFO_CONFIG4_FIFO_COMP_NC_FLOW_CFG_POS)



/*
 * REG_OTP_HEATER_RTC_CONFIG
 * Register Name : OTP_HEATER_RTC_CONFIG
 */

/*
 * otp_done
 * 1: Indicate OTP copy operation is completed.
 * 0: Indicate OTP copy operation is not done. Any write from serial interface block is dropped. Any read from serial interface will have 0 value return.
 */
#define REG_OTP_HEATER_RTC_CONFIG_OTP_DONE_POS      0x00
#define REG_OTP_HEATER_RTC_CONFIG_OTP_DONE_MASK     0x01

/*
 * otp_crc_pass
 * 0: The calculated CRC is not matching the CRC signature from OTP.
 * 1: Calculated CRC is matching the CRC signature from OTP.
 */
#define REG_OTP_HEATER_RTC_CONFIG_OTP_CRC_PASS_POS      0x01
#define REG_OTP_HEATER_RTC_CONFIG_OTP_CRC_PASS_MASK     (0x01 << REG_OTP_HEATER_RTC_CONFIG_OTP_CRC_PASS_POS)



/*
 * REG_DMP_EXT_SEN_ODR_CFG
 * Register Name : DMP_EXT_SEN_ODR_CFG
 */

/*
 * apex_odr
 * [Supports Dynamic Change] DMP Output Data Rate.
 * The dmp_odr needs to be smaller than or equal to both the accel_odr and gyro_odr. Also, all rates but 800Hz can be set if Accel UI/AP is in LP; in order to set the DMP ODR to 800Hz, the Accel UI/AP PM must be set in LN, otherwise the new rate will not be applied).
 *
 * 3'b000 -> 25Hz
 * 3'b001 -> 50Hz (default)
 * 3'b010 -> 100Hz
 * 3'b011 -> 200Hz
 * 3'b100 -> 400Hz
 * 3'b101 -> 800Hz      (LN-only)
 * 3'b110 -> reserved
 * 3'b111 -> reserved
 */
#define REG_DMP_EXT_SEN_ODR_CFG_APEX_ODR_POS      0x00
#define REG_DMP_EXT_SEN_ODR_CFG_APEX_ODR_MASK     0x07

/*
 * ext_odr
 * Internal external ODR for I2CM kickoff
 * 000: 3.125 Hz
 * 001: 6.25 Hz
 * 010: 12.5 Hz
 * 011: 25 Hz
 * 100: 50 Hz
 * 101: 100 Hz
 * 110: 200 Hz
 * 111: 400 Hz
 */
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_ODR_POS      0x03
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_ODR_MASK     (0x07 << REG_DMP_EXT_SEN_ODR_CFG_EXT_ODR_POS)

/*
 * ext_sensor_en
 * 1: To enable the SMC block to generate the ODR event for external snsor operation per the setting of ext_odr register.
 * 0: To disable the SMC block from generating the ODR event for the external sensor operation.
 *
 * This register is not used by any other blocks.
 */
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_SENSOR_EN_POS      0x06
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_SENSOR_EN_MASK     (0x01 << REG_DMP_EXT_SEN_ODR_CFG_EXT_SENSOR_EN_POS)



/*
 * REG_EDMP_APEX_EN0
 * Register Name : EDMP_APEX_EN0
 */

/*
 * tap_en
 * Set 1 to enable Tap algorithm
 */
#define REG_EDMP_APEX_EN0_TAP_EN_POS      0x00
#define REG_EDMP_APEX_EN0_TAP_EN_MASK     0x01

/*
 * highg_en
 * Set 1 to enable HighG algorithm
 */
#define REG_EDMP_APEX_EN0_HIGHG_EN_POS      0x01
#define REG_EDMP_APEX_EN0_HIGHG_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_HIGHG_EN_POS)

/*
 * lowg_en
 * Set 1 to enable LowG algorithm
 */
#define REG_EDMP_APEX_EN0_LOWG_EN_POS      0x02
#define REG_EDMP_APEX_EN0_LOWG_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_LOWG_EN_POS)

/*
 * tilt_en
 * Set 1 to enable Tilt algorithm
 */
#define REG_EDMP_APEX_EN0_TILT_EN_POS      0x03
#define REG_EDMP_APEX_EN0_TILT_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_TILT_EN_POS)

/*
 * pedo_en
 * Set 1 to enable Pedometer algorithm
 */
#define REG_EDMP_APEX_EN0_PEDO_EN_POS      0x04
#define REG_EDMP_APEX_EN0_PEDO_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_PEDO_EN_POS)

/*
 * ff_en
 * Set 1 to enable Freefall algorithm
 */
#define REG_EDMP_APEX_EN0_FF_EN_POS      0x05
#define REG_EDMP_APEX_EN0_FF_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_FF_EN_POS)

/*
 * r2w_en
 * Set 1 to enable Raise to Wake algorithm
 */
#define REG_EDMP_APEX_EN0_R2W_EN_POS      0x06
#define REG_EDMP_APEX_EN0_R2W_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_R2W_EN_POS)

/*
 * smd_en
 * Set 1 to enable SMD algorithm
 */
#define REG_EDMP_APEX_EN0_SMD_EN_POS      0x07
#define REG_EDMP_APEX_EN0_SMD_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_SMD_EN_POS)



/*
 * REG_EDMP_APEX_EN1
 * Register Name : EDMP_APEX_EN1
 */

/*
 * soft_hard_iron_corr_en
 * Set 1 to enable soft iron hard iron correction
 */
#define REG_EDMP_APEX_EN1_SOFT_HARD_IRON_CORR_EN_POS      0x00
#define REG_EDMP_APEX_EN1_SOFT_HARD_IRON_CORR_EN_MASK     0x01

/*
 * init_en
 * This bit is set by the host to indicate: eDMP executes only the segment of code that initialize constants used by algorithms. The register is R/W by the external host through the direct register accessing path. The register is R/C by any AHB master when it is accessed via internal AHB/APB bus.
 */
#define REG_EDMP_APEX_EN1_INIT_EN_POS      0x01
#define REG_EDMP_APEX_EN1_INIT_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_INIT_EN_POS)

/*
 * power_save_en
 * Set 1 to enable power save mode
 */
#define REG_EDMP_APEX_EN1_POWER_SAVE_EN_POS      0x02
#define REG_EDMP_APEX_EN1_POWER_SAVE_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_POWER_SAVE_EN_POS)

/*
 * feature1_en
 * Set 1 to enable reserved feature1
 */
#define REG_EDMP_APEX_EN1_FEATURE1_EN_POS      0x03
#define REG_EDMP_APEX_EN1_FEATURE1_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_FEATURE1_EN_POS)

/*
 * feature2_en
 * Set 1 to enable reserved feature2
 */
#define REG_EDMP_APEX_EN1_FEATURE2_EN_POS      0x04
#define REG_EDMP_APEX_EN1_FEATURE2_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_FEATURE2_EN_POS)

/*
 * feature3_en
 * Set 1 to enable reserved feature3
 */
#define REG_EDMP_APEX_EN1_FEATURE3_EN_POS      0x05
#define REG_EDMP_APEX_EN1_FEATURE3_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_FEATURE3_EN_POS)

/*
 * edmp_enable
 * 0: mask out all eDMP input interrupts and freeze eDMP processing after eDMP is finished with current processing sample of all ISRs.
 * 1: Enable eDMP operation mode
 */
#define REG_EDMP_APEX_EN1_EDMP_ENABLE_POS      0x06
#define REG_EDMP_APEX_EN1_EDMP_ENABLE_MASK     (0x01 << REG_EDMP_APEX_EN1_EDMP_ENABLE_POS)



/*
 * REG_APEX_BUFFER_MGMT
 * Register Name : APEX_BUFFER_MGMT
 */

/*
 * step_count_edmp_wptr
 * LSB indicates SRAM address for eDMP to write
 * MSB indicates size 2 buffer wrap around
 * 00: eDMP writes to buffer 0
 * 01: eDMP writes to buffer 1
 * 10: eDMP writes to buffer 0
 * 11: eDMP writes to buffer 1
 */
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_EDMP_WPTR_POS      0x00
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_EDMP_WPTR_MASK     0x03

/*
 * step_count_host_rptr
 * LSB indicates SRAM address for host to read
 * MSB indicates size 2 buffer wrap around
 * 00: host reads buffer 0
 * 01: host reads buffer 1
 * 10: host reads buffer 0
 * 11: host reads buffer 1
 */
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_HOST_RPTR_POS      0x02
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_HOST_RPTR_MASK     (0x03 << REG_APEX_BUFFER_MGMT_STEP_COUNT_HOST_RPTR_POS)

/*
 * ff_duration_edmp_wptr
 * LSB indicates SRAM address for eDMP to write
 * MSB indicates size 2 buffer wrap around
 * 00: eDMP writes to buffer 0
 * 01: eDMP writes to buffer 1
 * 10: eDMP writes to buffer 0
 * 11: eDMP writes to buffer 1
 */
#define REG_APEX_BUFFER_MGMT_FF_DURATION_EDMP_WPTR_POS      0x04
#define REG_APEX_BUFFER_MGMT_FF_DURATION_EDMP_WPTR_MASK     (0x03 << REG_APEX_BUFFER_MGMT_FF_DURATION_EDMP_WPTR_POS)

/*
 * ff_duration_host_rptr
 * LSB indicates SRAM address for host to read
 * MSB indicates size 2 buffer wrap around
 * 00: host reads buffer 0
 * 01: host reads buffer 1
 * 10: host reads buffer 0
 * 11: host reads buffer 1
 */
#define REG_APEX_BUFFER_MGMT_FF_DURATION_HOST_RPTR_POS      0x06
#define REG_APEX_BUFFER_MGMT_FF_DURATION_HOST_RPTR_MASK     (0x03 << REG_APEX_BUFFER_MGMT_FF_DURATION_HOST_RPTR_POS)



/*
 * REG_IOC_PAD_SCENARIO
 * Register Name : IOC_PAD_SCENARIO
 */

/*
 * aux1_enable
 * Aux1 enable :
 * 0: AUX1 disabled
 * 1: AUX1 enabled
 */
#define REG_IOC_PAD_SCENARIO_AUX1_ENABLE_POS      0x00
#define REG_IOC_PAD_SCENARIO_AUX1_ENABLE_MASK     0x01

/*
 * aux1_mode
 * Effective only when 'aux1_enable' is '1'
 * Selects modes at which AUX1 pads could be used
 * 0: AUX1in SPI Slave
 * 1: AUX1 in I2CM Master
 * 2: AUX1 in I2CM Bypass (Enable only when AP is not in SIFS mode)
 */
#define REG_IOC_PAD_SCENARIO_AUX1_MODE_POS      0x01
#define REG_IOC_PAD_SCENARIO_AUX1_MODE_MASK     (0x03 << REG_IOC_PAD_SCENARIO_AUX1_MODE_POS)

/*
 * aux2_enable
 * Aux2 enable :
 * 0: AUX2 disabled
 * 1: AUX2 enabled
 */
#define REG_IOC_PAD_SCENARIO_AUX2_ENABLE_POS      0x03
#define REG_IOC_PAD_SCENARIO_AUX2_ENABLE_MASK     (0x01 << REG_IOC_PAD_SCENARIO_AUX2_ENABLE_POS)

/*
 * pads_int2_cfg
 * Effective only when 'aux2_enable' is 0.  Selects how INT2 pads are used
 * 0 : INT2 is selected
 * 1 : FSYNC is selected
 * 2 : CLKIN is selected
 * 3 : DRDY_INTR is selected
 */
#define REG_IOC_PAD_SCENARIO_PADS_INT2_CFG_POS      0x04
#define REG_IOC_PAD_SCENARIO_PADS_INT2_CFG_MASK     (0x03 << REG_IOC_PAD_SCENARIO_PADS_INT2_CFG_POS)

/*
 * pads_drdy_passthrough
 * Effective only when 'ioc_pads_int2_cfg' is value '3' (DRDY_INTR is selected) and AP_SIFS is not in SPI mode
 * 0: drdy_intr as normal operation
 * 1 : drdy_intr is passthrough to INT1
 */
#define REG_IOC_PAD_SCENARIO_PADS_DRDY_PASSTHROUGH_POS      0x06
#define REG_IOC_PAD_SCENARIO_PADS_DRDY_PASSTHROUGH_MASK     (0x01 << REG_IOC_PAD_SCENARIO_PADS_DRDY_PASSTHROUGH_POS)



/*
 * REG_WHO_AM_I
 * Register Name : WHO_AM_I
 */

/*
 * who_am_i
 * TDK Chip ID
 */
#define REG_WHO_AM_I_WHO_AM_I_POS      0x00
#define REG_WHO_AM_I_WHO_AM_I_MASK     0xff



/*
 * REG_REG_HOST_MSG
 * Register Name : REG_HOST_MSG
 */

/*
 * testopenable
 * [Supports Dynamic Change] 1: Enable test op, Read SRAM to know if the test op is for self-test(A/G) or for self-cal(A/G)
 */
#define REG_REG_HOST_MSG_TESTOPENABLE_POS      0x00
#define REG_REG_HOST_MSG_TESTOPENABLE_MASK     0x01

/*
 * reserved1
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED1_POS      0x01
#define REG_REG_HOST_MSG_RESERVED1_MASK     (0x01 << REG_REG_HOST_MSG_RESERVED1_POS)

/*
 * reserved2
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED2_POS      0x02
#define REG_REG_HOST_MSG_RESERVED2_MASK     (0x01 << REG_REG_HOST_MSG_RESERVED2_POS)

/*
 * reserved3
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED3_POS      0x03
#define REG_REG_HOST_MSG_RESERVED3_MASK     (0x01 << REG_REG_HOST_MSG_RESERVED3_POS)

/*
 * sa_en
 * [Supports Dynamic Change] 1: Enable SA Op.
 */
#define REG_REG_HOST_MSG_SA_EN_POS      0x04
#define REG_REG_HOST_MSG_SA_EN_MASK     (0x01 << REG_REG_HOST_MSG_SA_EN_POS)

/*
 * edmp_on_demand_en
 * Set 1 to create pulse to set int_status_edmp_on_demand_pin_0,
 * int_status_edmp_on_demand_pin_1,
 * Int_status_edmp_on_demand_pin_2 to 1
 */
#define REG_REG_HOST_MSG_EDMP_ON_DEMAND_EN_POS      0x05
#define REG_REG_HOST_MSG_EDMP_ON_DEMAND_EN_MASK     (0x01 << REG_REG_HOST_MSG_EDMP_ON_DEMAND_EN_POS)

/*
 * reserved4
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED4_POS      0x06
#define REG_REG_HOST_MSG_RESERVED4_MASK     (0x03 << REG_REG_HOST_MSG_RESERVED4_POS)


/* ---------------------------------------------------------------------------
 * register DREG_TOP2
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register IHREG_SREG
 * ---------------------------------------------------------------------------*/

/*
 * REG_ACCEL_X_0
 * Register Name : ACCEL_X_0
 */

/*
 * accel_x
 * Accel X axis data
 */
#define REG_ACCEL_X_0_ACCEL_X_POS      0x00
#define REG_ACCEL_X_0_ACCEL_X_MASK     0xff



/*
 * REG_ACCEL_X_1
 * Register Name : ACCEL_X_1
 */

/*
 * accel_x
 * Accel X axis data
 */
#define REG_ACCEL_X_1_ACCEL_X_POS      0x00
#define REG_ACCEL_X_1_ACCEL_X_MASK     0xff



/*
 * REG_ACCEL_X_2
 * Register Name : ACCEL_X_2
 */

/*
 * accel_x
 * Accel X axis data
 */
#define REG_ACCEL_X_2_ACCEL_X_POS      0x00
#define REG_ACCEL_X_2_ACCEL_X_MASK     0xff



/*
 * REG_ACCEL_X_3
 * Register Name : ACCEL_X_3
 */

/*
 * accel_x
 * Accel X axis data
 */
#define REG_ACCEL_X_3_ACCEL_X_POS      0x00
#define REG_ACCEL_X_3_ACCEL_X_MASK     0xff



/*
 * REG_ACCEL_Y_0
 * Register Name : ACCEL_Y_0
 */

/*
 * accel_y
 * Accel Y axis data
 */
#define REG_ACCEL_Y_0_ACCEL_Y_POS      0x00
#define REG_ACCEL_Y_0_ACCEL_Y_MASK     0xff



/*
 * REG_ACCEL_Y_1
 * Register Name : ACCEL_Y_1
 */

/*
 * accel_y
 * Accel Y axis data
 */
#define REG_ACCEL_Y_1_ACCEL_Y_POS      0x00
#define REG_ACCEL_Y_1_ACCEL_Y_MASK     0xff



/*
 * REG_ACCEL_Y_2
 * Register Name : ACCEL_Y_2
 */

/*
 * accel_y
 * Accel Y axis data
 */
#define REG_ACCEL_Y_2_ACCEL_Y_POS      0x00
#define REG_ACCEL_Y_2_ACCEL_Y_MASK     0xff



/*
 * REG_ACCEL_Y_3
 * Register Name : ACCEL_Y_3
 */

/*
 * accel_y
 * Accel Y axis data
 */
#define REG_ACCEL_Y_3_ACCEL_Y_POS      0x00
#define REG_ACCEL_Y_3_ACCEL_Y_MASK     0xff



/*
 * REG_ACCEL_Z_0
 * Register Name : ACCEL_Z_0
 */

/*
 * accel_z
 * Accel Z axis data
 */
#define REG_ACCEL_Z_0_ACCEL_Z_POS      0x00
#define REG_ACCEL_Z_0_ACCEL_Z_MASK     0xff



/*
 * REG_ACCEL_Z_1
 * Register Name : ACCEL_Z_1
 */

/*
 * accel_z
 * Accel Z axis data
 */
#define REG_ACCEL_Z_1_ACCEL_Z_POS      0x00
#define REG_ACCEL_Z_1_ACCEL_Z_MASK     0xff



/*
 * REG_ACCEL_Z_2
 * Register Name : ACCEL_Z_2
 */

/*
 * accel_z
 * Accel Z axis data
 */
#define REG_ACCEL_Z_2_ACCEL_Z_POS      0x00
#define REG_ACCEL_Z_2_ACCEL_Z_MASK     0xff



/*
 * REG_ACCEL_Z_3
 * Register Name : ACCEL_Z_3
 */

/*
 * accel_z
 * Accel Z axis data
 */
#define REG_ACCEL_Z_3_ACCEL_Z_POS      0x00
#define REG_ACCEL_Z_3_ACCEL_Z_MASK     0xff



/*
 * REG_GYRO_X_0
 * Register Name : GYRO_X_0
 */

/*
 * gyro_x
 * Gyro X axis data
 */
#define REG_GYRO_X_0_GYRO_X_POS      0x00
#define REG_GYRO_X_0_GYRO_X_MASK     0xff



/*
 * REG_GYRO_X_1
 * Register Name : GYRO_X_1
 */

/*
 * gyro_x
 * Gyro X axis data
 */
#define REG_GYRO_X_1_GYRO_X_POS      0x00
#define REG_GYRO_X_1_GYRO_X_MASK     0xff



/*
 * REG_GYRO_X_2
 * Register Name : GYRO_X_2
 */

/*
 * gyro_x
 * Gyro X axis data
 */
#define REG_GYRO_X_2_GYRO_X_POS      0x00
#define REG_GYRO_X_2_GYRO_X_MASK     0xff



/*
 * REG_GYRO_X_3
 * Register Name : GYRO_X_3
 */

/*
 * gyro_x
 * Gyro X axis data
 */
#define REG_GYRO_X_3_GYRO_X_POS      0x00
#define REG_GYRO_X_3_GYRO_X_MASK     0xff



/*
 * REG_GYRO_Y_0
 * Register Name : GYRO_Y_0
 */

/*
 * gyro_y
 * Gyro Y axis data
 */
#define REG_GYRO_Y_0_GYRO_Y_POS      0x00
#define REG_GYRO_Y_0_GYRO_Y_MASK     0xff



/*
 * REG_GYRO_Y_1
 * Register Name : GYRO_Y_1
 */

/*
 * gyro_y
 * Gyro Y axis data
 */
#define REG_GYRO_Y_1_GYRO_Y_POS      0x00
#define REG_GYRO_Y_1_GYRO_Y_MASK     0xff



/*
 * REG_GYRO_Y_2
 * Register Name : GYRO_Y_2
 */

/*
 * gyro_y
 * Gyro Y axis data
 */
#define REG_GYRO_Y_2_GYRO_Y_POS      0x00
#define REG_GYRO_Y_2_GYRO_Y_MASK     0xff



/*
 * REG_GYRO_Y_3
 * Register Name : GYRO_Y_3
 */

/*
 * gyro_y
 * Gyro Y axis data
 */
#define REG_GYRO_Y_3_GYRO_Y_POS      0x00
#define REG_GYRO_Y_3_GYRO_Y_MASK     0xff



/*
 * REG_GYRO_Z_0
 * Register Name : GYRO_Z_0
 */

/*
 * gyro_z
 * Gyro Z axis data
 */
#define REG_GYRO_Z_0_GYRO_Z_POS      0x00
#define REG_GYRO_Z_0_GYRO_Z_MASK     0xff



/*
 * REG_GYRO_Z_1
 * Register Name : GYRO_Z_1
 */

/*
 * gyro_z
 * Gyro Z axis data
 */
#define REG_GYRO_Z_1_GYRO_Z_POS      0x00
#define REG_GYRO_Z_1_GYRO_Z_MASK     0xff



/*
 * REG_GYRO_Z_2
 * Register Name : GYRO_Z_2
 */

/*
 * gyro_z
 * Gyro Z axis data
 */
#define REG_GYRO_Z_2_GYRO_Z_POS      0x00
#define REG_GYRO_Z_2_GYRO_Z_MASK     0xff



/*
 * REG_GYRO_Z_3
 * Register Name : GYRO_Z_3
 */

/*
 * gyro_z
 * Gyro Z axis data
 */
#define REG_GYRO_Z_3_GYRO_Z_POS      0x00
#define REG_GYRO_Z_3_GYRO_Z_MASK     0xff



/*
 * REG_TEMP_0
 * Register Name : TEMP_0
 */

/*
 * temp
 * Temperature data
 */
#define REG_TEMP_0_TEMP_POS      0x00
#define REG_TEMP_0_TEMP_MASK     0xff



/*
 * REG_TEMP_1
 * Register Name : TEMP_1
 */

/*
 * temp
 * Temperature data
 */
#define REG_TEMP_1_TEMP_POS      0x00
#define REG_TEMP_1_TEMP_MASK     0xff



/*
 * REG_TEMP_2
 * Register Name : TEMP_2
 */

/*
 * temp
 * Temperature data
 */
#define REG_TEMP_2_TEMP_POS      0x00
#define REG_TEMP_2_TEMP_MASK     0xff



/*
 * REG_TEMP_3
 * Register Name : TEMP_3
 */

/*
 * temp
 * Temperature data
 */
#define REG_TEMP_3_TEMP_POS      0x00
#define REG_TEMP_3_TEMP_MASK     0xff



/*
 * REG_CTRL
 * Register Name : CTRL
 */

/*
 * ext_sens_data_rdy
 * External sensors data ready
 */
#define REG_CTRL_EXT_SENS_DATA_RDY_POS      0x00
#define REG_CTRL_EXT_SENS_DATA_RDY_MASK     0x01

/*
 * es0_vld
 * External sensor 0 data valid
 */
#define REG_CTRL_ES0_VLD_POS      0x01
#define REG_CTRL_ES0_VLD_MASK     (0x01 << REG_CTRL_ES0_VLD_POS)

/*
 * es1_vld
 * External sensor 1 data valid
 */
#define REG_CTRL_ES1_VLD_POS      0x02
#define REG_CTRL_ES1_VLD_MASK     (0x01 << REG_CTRL_ES1_VLD_POS)


/* ---------------------------------------------------------------------------
 * register IMEM_ROM
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register IMEM_SRAM
 * ---------------------------------------------------------------------------*/

/*
 * REG_IMEM_SRAM_REG_0
 * Register Name : IMEM_SRAM_REG_0
 */

/*
 * gyro_x_str_ft
 * Self-test response for gyro x axis. Units are in kdps. Full scale is 0.5kdps, LSB is 30mdps.
 */
#define REG_IMEM_SRAM_REG_0_GYRO_X_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_0_GYRO_X_STR_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_1
 * Register Name : IMEM_SRAM_REG_1
 */

/*
 * gyro_x_str_ft
 * Self-test response for gyro x axis. Units are in kdps. Full scale is 0.5kdps, LSB is 30mdps.
 */
#define REG_IMEM_SRAM_REG_1_GYRO_X_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_1_GYRO_X_STR_FT_MASK     0x7f



/*
 * REG_IMEM_SRAM_REG_2
 * Register Name : IMEM_SRAM_REG_2
 */

/*
 * gyro_y_str_ft
 * Self-test response for gyro y axis. Units are in kdps. Full scale is 0.5kdps, LSB is 30mdps.
 */
#define REG_IMEM_SRAM_REG_2_GYRO_Y_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_2_GYRO_Y_STR_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_3
 * Register Name : IMEM_SRAM_REG_3
 */

/*
 * gyro_y_str_ft
 * Self-test response for gyro y axis. Units are in kdps. Full scale is 0.5kdps, LSB is 30mdps.
 */
#define REG_IMEM_SRAM_REG_3_GYRO_Y_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_3_GYRO_Y_STR_FT_MASK     0x7f



/*
 * REG_IMEM_SRAM_REG_4
 * Register Name : IMEM_SRAM_REG_4
 */

/*
 * gyro_z_str_ft
 * Self-test response for gyro z axis. Units are in kdps. Full scale is 0.5kdps, LSB is 30mdps.
 */
#define REG_IMEM_SRAM_REG_4_GYRO_Z_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_4_GYRO_Z_STR_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_5
 * Register Name : IMEM_SRAM_REG_5
 */

/*
 * gyro_z_str_ft
 * Self-test response for gyro z axis. Units are in kdps. Full scale is 0.5kdps, LSB is 30mdps.
 */
#define REG_IMEM_SRAM_REG_5_GYRO_Z_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_5_GYRO_Z_STR_FT_MASK     0x7f



/*
 * REG_IMEM_SRAM_REG_6
 * Register Name : IMEM_SRAM_REG_6
 */

/*
 * gyro_x_cmos_gain_ft
 * Gyro x axis SC2V+ADC gain measurement result.Units are in kdps. FSR is 500 dps, resolution is 122 mdps.
 */
#define REG_IMEM_SRAM_REG_6_GYRO_X_CMOS_GAIN_FT_POS      0x00
#define REG_IMEM_SRAM_REG_6_GYRO_X_CMOS_GAIN_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_7
 * Register Name : IMEM_SRAM_REG_7
 */

/*
 * gyro_x_cmos_gain_ft
 * Gyro x axis SC2V+ADC gain measurement result.Units are in kdps. FSR is 500 dps, resolution is 122 mdps.
 */
#define REG_IMEM_SRAM_REG_7_GYRO_X_CMOS_GAIN_FT_POS      0x00
#define REG_IMEM_SRAM_REG_7_GYRO_X_CMOS_GAIN_FT_MASK     0x0f



/*
 * REG_IMEM_SRAM_REG_8
 * Register Name : IMEM_SRAM_REG_8
 */

/*
 * gyro_y_cmos_gain_ft
 * Gyro y axis SC2V+ADC gain measurement result. Units are in kdps. FSR is  500 dps, resolution is 122 mdps.
 */
#define REG_IMEM_SRAM_REG_8_GYRO_Y_CMOS_GAIN_FT_POS      0x00
#define REG_IMEM_SRAM_REG_8_GYRO_Y_CMOS_GAIN_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_9
 * Register Name : IMEM_SRAM_REG_9
 */

/*
 * gyro_y_cmos_gain_ft
 * Gyro y axis SC2V+ADC gain measurement result. Units are in kdps. FSR is  500 dps, resolution is 122 mdps.
 */
#define REG_IMEM_SRAM_REG_9_GYRO_Y_CMOS_GAIN_FT_POS      0x00
#define REG_IMEM_SRAM_REG_9_GYRO_Y_CMOS_GAIN_FT_MASK     0x0f



/*
 * REG_IMEM_SRAM_REG_10
 * Register Name : IMEM_SRAM_REG_10
 */

/*
 * gyro_z_cmos_gain_ft
 * Gyro z axis SC2V+ADC gain measurement result. Units are in kdps. FSR is 500 dps, resolution is 122 mdps.
 */
#define REG_IMEM_SRAM_REG_10_GYRO_Z_CMOS_GAIN_FT_POS      0x00
#define REG_IMEM_SRAM_REG_10_GYRO_Z_CMOS_GAIN_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_11
 * Register Name : IMEM_SRAM_REG_11
 */

/*
 * gyro_z_cmos_gain_ft
 * Gyro z axis SC2V+ADC gain measurement result. Units are in kdps. FSR is 500 dps, resolution is 122 mdps.
 */
#define REG_IMEM_SRAM_REG_11_GYRO_Z_CMOS_GAIN_FT_POS      0x00
#define REG_IMEM_SRAM_REG_11_GYRO_Z_CMOS_GAIN_FT_MASK     0x0f



/*
 * REG_IMEM_SRAM_REG_12
 * Register Name : IMEM_SRAM_REG_12
 */

/*
 * accel_x_str_ft
 * Self-test response for accel x axis. Units are gee. Full scale is 1 gee, LSB is 0.122 mgee
 */
#define REG_IMEM_SRAM_REG_12_ACCEL_X_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_12_ACCEL_X_STR_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_13
 * Register Name : IMEM_SRAM_REG_13
 */

/*
 * accel_x_str_ft
 * Self-test response for accel x axis. Units are gee. Full scale is 1 gee, LSB is 0.122 mgee
 */
#define REG_IMEM_SRAM_REG_13_ACCEL_X_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_13_ACCEL_X_STR_FT_MASK     0x3f



/*
 * REG_IMEM_SRAM_REG_14
 * Register Name : IMEM_SRAM_REG_14
 */

/*
 * accel_y_str_ft
 * Self-test response for accel y axis. Units are gee. Full scale is 1 gee, LSB is 0.122 mgee
 */
#define REG_IMEM_SRAM_REG_14_ACCEL_Y_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_14_ACCEL_Y_STR_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_15
 * Register Name : IMEM_SRAM_REG_15
 */

/*
 * accel_y_str_ft
 * Self-test response for accel y axis. Units are gee. Full scale is 1 gee, LSB is 0.122 mgee
 */
#define REG_IMEM_SRAM_REG_15_ACCEL_Y_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_15_ACCEL_Y_STR_FT_MASK     0x3f



/*
 * REG_IMEM_SRAM_REG_16
 * Register Name : IMEM_SRAM_REG_16
 */

/*
 * accel_z_str_ft
 * Self-test response for accel z axis. Units are gee.  Full scale is 1 gee, LSB is 0.122 mgee
 */
#define REG_IMEM_SRAM_REG_16_ACCEL_Z_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_16_ACCEL_Z_STR_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_17
 * Register Name : IMEM_SRAM_REG_17
 */

/*
 * accel_z_str_ft
 * Self-test response for accel z axis. Units are gee.  Full scale is 1 gee, LSB is 0.122 mgee
 */
#define REG_IMEM_SRAM_REG_17_ACCEL_Z_STR_FT_POS      0x00
#define REG_IMEM_SRAM_REG_17_ACCEL_Z_STR_FT_MASK     0x3f



/*
 * REG_IMEM_SRAM_REG_18
 * Register Name : IMEM_SRAM_REG_18
 */

/*
 * accel_x_sc_nout_ft
 * Accel X Factory Nout measurement for sensitivity calibration
 */
#define REG_IMEM_SRAM_REG_18_ACCEL_X_SC_NOUT_FT_POS      0x00
#define REG_IMEM_SRAM_REG_18_ACCEL_X_SC_NOUT_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_19
 * Register Name : IMEM_SRAM_REG_19
 */

/*
 * accel_x_sc_nout_ft
 * Accel X Factory Nout measurement for sensitivity calibration
 */
#define REG_IMEM_SRAM_REG_19_ACCEL_X_SC_NOUT_FT_POS      0x00
#define REG_IMEM_SRAM_REG_19_ACCEL_X_SC_NOUT_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_20
 * Register Name : IMEM_SRAM_REG_20
 */

/*
 * accel_y_sc_nout_ft
 * Accel Y Factory Nout measurement for sensitivity calibration
 */
#define REG_IMEM_SRAM_REG_20_ACCEL_Y_SC_NOUT_FT_POS      0x00
#define REG_IMEM_SRAM_REG_20_ACCEL_Y_SC_NOUT_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_21
 * Register Name : IMEM_SRAM_REG_21
 */

/*
 * accel_y_sc_nout_ft
 * Accel Y Factory Nout measurement for sensitivity calibration
 */
#define REG_IMEM_SRAM_REG_21_ACCEL_Y_SC_NOUT_FT_POS      0x00
#define REG_IMEM_SRAM_REG_21_ACCEL_Y_SC_NOUT_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_22
 * Register Name : IMEM_SRAM_REG_22
 */

/*
 * accel_z_sc_nout_ft
 * Accel Z Factory Nout measurement for sensitivity calibration
 */
#define REG_IMEM_SRAM_REG_22_ACCEL_Z_SC_NOUT_FT_POS      0x00
#define REG_IMEM_SRAM_REG_22_ACCEL_Z_SC_NOUT_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_23
 * Register Name : IMEM_SRAM_REG_23
 */

/*
 * accel_z_sc_nout_ft
 * Accel Z Factory Nout measurement for sensitivity calibration
 */
#define REG_IMEM_SRAM_REG_23_ACCEL_Z_SC_NOUT_FT_POS      0x00
#define REG_IMEM_SRAM_REG_23_ACCEL_Z_SC_NOUT_FT_MASK     0xff



/*
 * REG_IMEM_SRAM_REG_24
 * Register Name : IMEM_SRAM_REG_24
 */

/*
 * self_cal_ft_ver
 * Version tracking for accel/gyro self-cal FT procedure.
 */
#define REG_IMEM_SRAM_REG_24_SELF_CAL_FT_VER_POS      0x00
#define REG_IMEM_SRAM_REG_24_SELF_CAL_FT_VER_MASK     0xff


/* ---------------------------------------------------------------------------
 * register IPREG_FPGA
 * ---------------------------------------------------------------------------*/

/*
 * REG_MSTR_SPI_CTRL
 * Register Name : MSTR_SPI_CTRL
 */

/*
 * mstr_spi_rst
 * Reset the Master SPI. 0 : No action. 1 : Reset the Master SPI module. The bit must be manually cleared after a minimum delay of 100 ns.
 */
#define REG_MSTR_SPI_CTRL_MSTR_SPI_RST_POS      0x00
#define REG_MSTR_SPI_CTRL_MSTR_SPI_RST_MASK     0x01

/*
 * sent_to_slave
 * Execute a Master SPI transaction to send/receive data to/from the sensor when in indirect mode (see indirect_access_en field). 0 : No action. 1 : Execute the transaction with address specified in register MSTR_SPI_ADDR and data specified in registers MSTR_SPI_WR_DATA. In case of a read transaction, the data from slave are read from register MSTR_SPI_RD_DATA
 */
#define REG_MSTR_SPI_CTRL_SENT_TO_SLAVE_POS      0x01
#define REG_MSTR_SPI_CTRL_SENT_TO_SLAVE_MASK     (0x01 << REG_MSTR_SPI_CTRL_SENT_TO_SLAVE_POS)

/*
 * mstr_spi_freq
 * Configure the Master SPI SCLK clock frequency. 0d : 10MHz, 1d : 5MHz, 2d : 3.33MHz, 3d : 2.5MHz, 4d : 2MHz, 5d : 1.66MHz, 6d : 1.42MHz, 7d : 1.25MHz
 */
#define REG_MSTR_SPI_CTRL_MSTR_SPI_FREQ_POS      0x02
#define REG_MSTR_SPI_CTRL_MSTR_SPI_FREQ_MASK     (0x07 << REG_MSTR_SPI_CTRL_MSTR_SPI_FREQ_POS)

/*
 * indirect_access_en
 * Selects between direct/indirect access to Master SPI. 0 : Direct mode. Master SPI send/receive data specified by the reader controller. 1 : Indirect mode. Master SPI send/receive data coming from the Register Map, thus it can be programmed through the Slave SPI
 */
#define REG_MSTR_SPI_CTRL_INDIRECT_ACCESS_EN_POS      0x05
#define REG_MSTR_SPI_CTRL_INDIRECT_ACCESS_EN_MASK     (0x01 << REG_MSTR_SPI_CTRL_INDIRECT_ACCESS_EN_POS)



/*
 * REG_MSTR_SPI_ADDR
 * Register Name : MSTR_SPI_ADDR
 */

/*
 * mstr_spi_addr
 * Address of the Master SPI transaction in indirect mode.
 */
#define REG_MSTR_SPI_ADDR_MSTR_SPI_ADDR_POS      0x00
#define REG_MSTR_SPI_ADDR_MSTR_SPI_ADDR_MASK     0xff



/*
 * REG_MSTR_SPI_WR_DATA
 * Register Name : MSTR_SPI_WR_DATA
 */

/*
 * mstr_spi_wr_data
 * Write data of the Master SPI transaction in indirect mode
 */
#define REG_MSTR_SPI_WR_DATA_MSTR_SPI_WR_DATA_POS      0x00
#define REG_MSTR_SPI_WR_DATA_MSTR_SPI_WR_DATA_MASK     0xff



/*
 * REG_MSTR_SPI_RD_DATA
 * Register Name : MSTR_SPI_RD_DATA
 */

/*
 * mstr_spi_rd_data
 * Read data of the Master SPI transaction in indirect mode ; default value 0xa5(d'165) indicates that master SPI is ready to get the data from sensor
 */
#define REG_MSTR_SPI_RD_DATA_MSTR_SPI_RD_DATA_POS      0x00
#define REG_MSTR_SPI_RD_DATA_MSTR_SPI_RD_DATA_MASK     0xff



/*
 * REG_MSTR_SPI_STATUS
 * Register Name : MSTR_SPI_STATUS
 */

/*
 * mstr_spi_idle
 * State of the Master SPI in indirect mode. Read-only bit. 0 : Master SPI is running. 1 : Master SPI is idle.
 */
#define REG_MSTR_SPI_STATUS_MSTR_SPI_IDLE_POS      0x00
#define REG_MSTR_SPI_STATUS_MSTR_SPI_IDLE_MASK     0x01

/*
 * mstr_spi_done
 * State of the Master SPI transaction in indirect mode. Read-only bit. 0 : Transaction is running. 1 : Transaction not started yet or finished.
 */
#define REG_MSTR_SPI_STATUS_MSTR_SPI_DONE_POS      0x01
#define REG_MSTR_SPI_STATUS_MSTR_SPI_DONE_MASK     (0x01 << REG_MSTR_SPI_STATUS_MSTR_SPI_DONE_POS)



/*
 * REG_SENSOR_DATA_CTRL
 * Register Name : SENSOR_DATA_CTRL
 */

/*
 * start_sensor
 * Starts the generation of external sensor data. 0 : Stop data generation. 1 : Start data generation.
 */
#define REG_SENSOR_DATA_CTRL_START_SENSOR_POS      0x00
#define REG_SENSOR_DATA_CTRL_START_SENSOR_MASK     0x01

/*
 * prologue_en
 * Selects if the initialization commands to external sensor are provided. 0 : the initialization commands are not provided. 1 : the initialization commands are provided.
 */
#define REG_SENSOR_DATA_CTRL_PROLOGUE_EN_POS      0x01
#define REG_SENSOR_DATA_CTRL_PROLOGUE_EN_MASK     (0x01 << REG_SENSOR_DATA_CTRL_PROLOGUE_EN_POS)

/*
 * acc_sensor_data_en
 * Selects between Sine Waveform Generator and External Sensor accelero data. 0 : Sine Waveform Generator generates accelero data. 1 : External Sensor generates accelero data.
 */
#define REG_SENSOR_DATA_CTRL_ACC_SENSOR_DATA_EN_POS      0x02
#define REG_SENSOR_DATA_CTRL_ACC_SENSOR_DATA_EN_MASK     (0x01 << REG_SENSOR_DATA_CTRL_ACC_SENSOR_DATA_EN_POS)

/*
 * gyro_sensor_data_en
 * Selects between Sine Waveform Generator and External Sensor gyro data. 0 : Sine Waveform Generator generates gyro data. 1 : External Sensor generates gyro data.
 */
#define REG_SENSOR_DATA_CTRL_GYRO_SENSOR_DATA_EN_POS      0x03
#define REG_SENSOR_DATA_CTRL_GYRO_SENSOR_DATA_EN_MASK     (0x01 << REG_SENSOR_DATA_CTRL_GYRO_SENSOR_DATA_EN_POS)



/*
 * REG_FPGA_ID
 * Register Name : FPGA_ID
 */

/*
 * fpga_id
 * for Newport A1 FPGA, id = 0x15(d'21)
 */
#define REG_FPGA_ID_FPGA_ID_POS      0x00
#define REG_FPGA_ID_FPGA_ID_MASK     0xff



/*
 * REG_FPGA_CONFIG
 * Register Name : FPGA_CONFIG
 */

/*
 * fpga_root_clk_sel
 * Select the FPGA root clock frequency which correspond to the ASIC main clock PLL output. 0 : 20.48 MHz. 1 : 19.20 MHz.
 */
#define REG_FPGA_CONFIG_FPGA_ROOT_CLK_SEL_POS      0x00
#define REG_FPGA_CONFIG_FPGA_ROOT_CLK_SEL_MASK     0x01



/*
 * REG_REVISION1
 * Register Name : REVISION1
 */

/*
 * fpga_major_revision
 * Mayor revision number refers to project.
 */
#define REG_REVISION1_FPGA_MAJOR_REVISION_POS      0x00
#define REG_REVISION1_FPGA_MAJOR_REVISION_MASK     0xff



/*
 * REG_REVISION2
 * Register Name : REVISION2
 */

/*
 * fpga_minor_revision
 * Minor revision number refers to FPGA release. Release 1 => 1. Release 2 => 2.
 */
#define REG_REVISION2_FPGA_MINOR_REVISION_POS      0x00
#define REG_REVISION2_FPGA_MINOR_REVISION_MASK     0xff



/*
 * REG_ACCEL_X_FRE
 * Register Name : ACCEL_X_FRE
 */

/*
 * accel_x_fre
 * Accelerometer X axis input stimuli frequency selection. Depending on accel_clk_div[3:0] field and clock frequency Fclk (@ 4MHz). Fclk/2^(clk_div  [3:0]) ∙(1+accel_x_fre[7:0])/4096
 */
#define REG_ACCEL_X_FRE_ACCEL_X_FRE_POS      0x00
#define REG_ACCEL_X_FRE_ACCEL_X_FRE_MASK     0xff



/*
 * REG_ACCEL_X_AMP
 * Register Name : ACCEL_X_AMP
 */

/*
 * accel_x_amp
 * Accelerometer X axis input stimuli zero-to-peak linear amplitude selection in the range [0 gee : +40 gee[ (resolution 0.15625 gee). (accel_x_amp[7:0])/256∙40 gee
 */
#define REG_ACCEL_X_AMP_ACCEL_X_AMP_POS      0x00
#define REG_ACCEL_X_AMP_ACCEL_X_AMP_MASK     0xff



/*
 * REG_ACCEL_X_OFS
 * Register Name : ACCEL_X_OFS
 */

/*
 * accel_x_ofs
 * Accelerometer X axis input stimuli linear offset selection in the range [–40 gee : +40 gee[  (resolution 0.3125 gee) ($signed(accel_x_ofs[7:0]))/128∙40 gee
 */
#define REG_ACCEL_X_OFS_ACCEL_X_OFS_POS      0x00
#define REG_ACCEL_X_OFS_ACCEL_X_OFS_MASK     0xff



/*
 * REG_ACCEL_X_PHA
 * Register Name : ACCEL_X_PHA
 */

/*
 * accel_x_dith_en
 * When high Accelerometer X axis dither is enabled on sinewave stimulus
 */
#define REG_ACCEL_X_PHA_ACCEL_X_DITH_EN_POS      0x00
#define REG_ACCEL_X_PHA_ACCEL_X_DITH_EN_MASK     0x01

/*
 * accel_x_pha
 * Accelerometer X axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((accel_x_pha[6:0]))/128∙360 deg
 */
#define REG_ACCEL_X_PHA_ACCEL_X_PHA_POS      0x01
#define REG_ACCEL_X_PHA_ACCEL_X_PHA_MASK     (0x7f << REG_ACCEL_X_PHA_ACCEL_X_PHA_POS)



/*
 * REG_ACCEL_X_Y_AEX
 * Register Name : ACCEL_X_Y_AEX
 */

/*
 * accel_y_aex
 * Accelerometer Y axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-accel_y_aex[3:0]) ( dB equivalence :     -6dB ∙accel_y_aex[3:0] )
 */
#define REG_ACCEL_X_Y_AEX_ACCEL_Y_AEX_POS      0x00
#define REG_ACCEL_X_Y_AEX_ACCEL_Y_AEX_MASK     0x0f

/*
 * accel_x_aex
 * Accelerometer X axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-accel_x_aex[3:0])   ( dB equivalence :     -6dB ∙accel_x_aex[3:0] )
 */
#define REG_ACCEL_X_Y_AEX_ACCEL_X_AEX_POS      0x04
#define REG_ACCEL_X_Y_AEX_ACCEL_X_AEX_MASK     (0x0f << REG_ACCEL_X_Y_AEX_ACCEL_X_AEX_POS)



/*
 * REG_ACCEL_Y_FRE
 * Register Name : ACCEL_Y_FRE
 */

/*
 * accel_y_fre
 * Accelerometer Y axis input stimuli frequency selection. Depending on accel_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+accel_y_fre[7:0])/4096
 */
#define REG_ACCEL_Y_FRE_ACCEL_Y_FRE_POS      0x00
#define REG_ACCEL_Y_FRE_ACCEL_Y_FRE_MASK     0xff



/*
 * REG_ACCEL_Y_AMP
 * Register Name : ACCEL_Y_AMP
 */

/*
 * accel_y_amp
 * Accelerometer Y axis input stimuli zero-to-peak linear amplitude selection in the range [0 gee : +40 gee[  (resolution 0.15625 gee)(accel_y_amp[7:0])/256∙40 gee
 */
#define REG_ACCEL_Y_AMP_ACCEL_Y_AMP_POS      0x00
#define REG_ACCEL_Y_AMP_ACCEL_Y_AMP_MASK     0xff



/*
 * REG_ACCEL_Y_OFS
 * Register Name : ACCEL_Y_OFS
 */

/*
 * accel_y_ofs
 * Accelerometer Y axis input stimuli linear offset selection in the range [–40 gee : +40 gee[  (resolution 0.3125 gee)($signed(accel_y_ofs[7:0]))/128∙40 gee
 */
#define REG_ACCEL_Y_OFS_ACCEL_Y_OFS_POS      0x00
#define REG_ACCEL_Y_OFS_ACCEL_Y_OFS_MASK     0xff



/*
 * REG_ACCEL_Y_PHA
 * Register Name : ACCEL_Y_PHA
 */

/*
 * accel_y_dith_en
 * When high Accelerometer Y axis dither is enabled on sinewave stimulus
 */
#define REG_ACCEL_Y_PHA_ACCEL_Y_DITH_EN_POS      0x00
#define REG_ACCEL_Y_PHA_ACCEL_Y_DITH_EN_MASK     0x01

/*
 * accel_y_pha
 * Accelerometer Y axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((accel_y_pha[6:0]))/128∙360 deg
 */
#define REG_ACCEL_Y_PHA_ACCEL_Y_PHA_POS      0x01
#define REG_ACCEL_Y_PHA_ACCEL_Y_PHA_MASK     (0x7f << REG_ACCEL_Y_PHA_ACCEL_Y_PHA_POS)



/*
 * REG_ACCEL_Z_FRE
 * Register Name : ACCEL_Z_FRE
 */

/*
 * accel_z_fre
 * Accelerometer Z axis input stimuli frequency selection. Depending on accel_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+accel_z_fre[7:0])/4096
 */
#define REG_ACCEL_Z_FRE_ACCEL_Z_FRE_POS      0x00
#define REG_ACCEL_Z_FRE_ACCEL_Z_FRE_MASK     0xff



/*
 * REG_ACCEL_Z_AMP
 * Register Name : ACCEL_Z_AMP
 */

/*
 * accel_z_amp
 * Accelerometer Z axis input stimuli zero-to-peak linear amplitude selection in the range [0 gee : +40 gee[  (resolution 0.15625 gee) (accel_z_amp[7:0])/256∙40 gee
 */
#define REG_ACCEL_Z_AMP_ACCEL_Z_AMP_POS      0x00
#define REG_ACCEL_Z_AMP_ACCEL_Z_AMP_MASK     0xff



/*
 * REG_ACCEL_Z_OFS
 * Register Name : ACCEL_Z_OFS
 */

/*
 * accel_z_ofs
 * Accelerometer Z axis input stimuli linear offset selection in the range [–40 gee : +40 gee[  (resolution 0.3125 gee) ($signed(accel_z_ofs[7:0]))/128∙40 gee
 */
#define REG_ACCEL_Z_OFS_ACCEL_Z_OFS_POS      0x00
#define REG_ACCEL_Z_OFS_ACCEL_Z_OFS_MASK     0xff



/*
 * REG_ACCEL_Z_PHA
 * Register Name : ACCEL_Z_PHA
 */

/*
 * accel_z_dith_en
 * When high Accelerometer Z axis dither is enabled on sinewave stimulus
 */
#define REG_ACCEL_Z_PHA_ACCEL_Z_DITH_EN_POS      0x00
#define REG_ACCEL_Z_PHA_ACCEL_Z_DITH_EN_MASK     0x01

/*
 * accel_z_pha
 * Accelerometer Z axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((accel_z_pha[6:0]))/128∙360 deg
 */
#define REG_ACCEL_Z_PHA_ACCEL_Z_PHA_POS      0x01
#define REG_ACCEL_Z_PHA_ACCEL_Z_PHA_MASK     (0x7f << REG_ACCEL_Z_PHA_ACCEL_Z_PHA_POS)



/*
 * REG_ACCEL_Z_GYRO_X_AEX
 * Register Name : ACCEL_Z_GYRO_X_AEX
 */

/*
 * gyro_x_aex
 * Gyroscope X axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-gyro_x_aex[3:0])   ( dB equivalence :     -6dB ∙gyro_x_aex[3:0] )
 */
#define REG_ACCEL_Z_GYRO_X_AEX_GYRO_X_AEX_POS      0x00
#define REG_ACCEL_Z_GYRO_X_AEX_GYRO_X_AEX_MASK     0x0f

/*
 * accel_z_aex
 * Accelerometer Z axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-accel_z_aex[3:0])   ( dB equivalence :     -6dB ∙accel_z_aex[3:0] )
 */
#define REG_ACCEL_Z_GYRO_X_AEX_ACCEL_Z_AEX_POS      0x04
#define REG_ACCEL_Z_GYRO_X_AEX_ACCEL_Z_AEX_MASK     (0x0f << REG_ACCEL_Z_GYRO_X_AEX_ACCEL_Z_AEX_POS)



/*
 * REG_GYRO_X_FRE
 * Register Name : GYRO_X_FRE
 */

/*
 * gyro_x_fre
 * Gyroscope X axis input stimuli frequency selection. Depending on gyro_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+gyro_x_fre[7:0])/4096
 */
#define REG_GYRO_X_FRE_GYRO_X_FRE_POS      0x00
#define REG_GYRO_X_FRE_GYRO_X_FRE_MASK     0xff



/*
 * REG_GYRO_X_AMP
 * Register Name : GYRO_X_AMP
 */

/*
 * gyro_x_amp
 * Gyroscope X axis input stimuli zero-to-peak linear amplitude selection in the range [0 dps : +3000 dps[  (resolution 11.71875 dps) (gyro_x_amp[7:0])/256∙3000 dps
 */
#define REG_GYRO_X_AMP_GYRO_X_AMP_POS      0x00
#define REG_GYRO_X_AMP_GYRO_X_AMP_MASK     0xff



/*
 * REG_GYRO_X_OFS
 * Register Name : GYRO_X_OFS
 */

/*
 * gyro_x_ofs
 * Gyroscope X axis input stimuli linear offset selection in the range [–3000 dps: +3000 dps [  (resolution 23.4375 dps)($signed(gyro_x_ofs[7:0]))/128∙3000 dps
 */
#define REG_GYRO_X_OFS_GYRO_X_OFS_POS      0x00
#define REG_GYRO_X_OFS_GYRO_X_OFS_MASK     0xff



/*
 * REG_GYRO_X_PHA
 * Register Name : GYRO_X_PHA
 */

/*
 * gyro_x_dith_en
 * When high Gyroscope X axis dither is enabled on sinewave stimulus
 */
#define REG_GYRO_X_PHA_GYRO_X_DITH_EN_POS      0x00
#define REG_GYRO_X_PHA_GYRO_X_DITH_EN_MASK     0x01

/*
 * gyro_x_pha
 * Gyroscope X axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((gyro_x_pha[6:0]))/128∙360 deg
 */
#define REG_GYRO_X_PHA_GYRO_X_PHA_POS      0x01
#define REG_GYRO_X_PHA_GYRO_X_PHA_MASK     (0x7f << REG_GYRO_X_PHA_GYRO_X_PHA_POS)



/*
 * REG_GYRO_Y_FRE
 * Register Name : GYRO_Y_FRE
 */

/*
 * gyro_y_fre
 * Gyroscope Y axis input stimuli frequency selection. Depending on gyro_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+gyro_y_fre[7:0])/4096
 */
#define REG_GYRO_Y_FRE_GYRO_Y_FRE_POS      0x00
#define REG_GYRO_Y_FRE_GYRO_Y_FRE_MASK     0xff



/*
 * REG_GYRO_Y_AMP
 * Register Name : GYRO_Y_AMP
 */

/*
 * gyro_y_amp
 * Gyroscope Y axis input stimuli zero-to-peak linear amplitude selection in the range [0 dps : +3000 dps[  (resolution 11.71875 dps) (gyro_y_amp[7:0])/256∙3000 dps
 */
#define REG_GYRO_Y_AMP_GYRO_Y_AMP_POS      0x00
#define REG_GYRO_Y_AMP_GYRO_Y_AMP_MASK     0xff



/*
 * REG_GYRO_Y_OFS
 * Register Name : GYRO_Y_OFS
 */

/*
 * gyro_y_ofs
 * Gyroscope Y axis input stimuli linear offset selection in the range [–3000 dps: +3000 dps [  (resolution 23.4375 dps)($signed(gyro_y_ofs[7:0]))/128∙3000 dps
 */
#define REG_GYRO_Y_OFS_GYRO_Y_OFS_POS      0x00
#define REG_GYRO_Y_OFS_GYRO_Y_OFS_MASK     0xff



/*
 * REG_GYRO_Y_PHA
 * Register Name : GYRO_Y_PHA
 */

/*
 * gyro_y_dith_en
 * When high Gyroscope Y axis dither is enabled on sinewave stimulus
 */
#define REG_GYRO_Y_PHA_GYRO_Y_DITH_EN_POS      0x00
#define REG_GYRO_Y_PHA_GYRO_Y_DITH_EN_MASK     0x01

/*
 * gyro_y_pha
 * Gyroscope Y axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg) ((gyro_y_pha[6:0]))/128∙360 deg
 */
#define REG_GYRO_Y_PHA_GYRO_Y_PHA_POS      0x01
#define REG_GYRO_Y_PHA_GYRO_Y_PHA_MASK     (0x7f << REG_GYRO_Y_PHA_GYRO_Y_PHA_POS)



/*
 * REG_GYRO_Y_GYRO_Z_AEX
 * Register Name : GYRO_Y_GYRO_Z_AEX
 */

/*
 * gyro_z_aex
 * Gyroscope Z axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-gyro_z_aex[3:0])   ( dB equivalence :     -6dB ∙gyro_z_aex[3:0] )
 */
#define REG_GYRO_Y_GYRO_Z_AEX_GYRO_Z_AEX_POS      0x00
#define REG_GYRO_Y_GYRO_Z_AEX_GYRO_Z_AEX_MASK     0x0f

/*
 * gyro_y_aex
 * Gyroscope Y axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-gyro_y_aex[3:0])   ( dB equivalence :     -6dB ∙gyro_y_aex[3:0] )
 */
#define REG_GYRO_Y_GYRO_Z_AEX_GYRO_Y_AEX_POS      0x04
#define REG_GYRO_Y_GYRO_Z_AEX_GYRO_Y_AEX_MASK     (0x0f << REG_GYRO_Y_GYRO_Z_AEX_GYRO_Y_AEX_POS)



/*
 * REG_GYRO_Z_FRE
 * Register Name : GYRO_Z_FRE
 */

/*
 * gyro_z_fre
 * Gyroscope Z axis input stimuli frequency selection. Depending on gyro_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+gyro_z_fre[7:0])/4096
 */
#define REG_GYRO_Z_FRE_GYRO_Z_FRE_POS      0x00
#define REG_GYRO_Z_FRE_GYRO_Z_FRE_MASK     0xff



/*
 * REG_GYRO_Z_AMP
 * Register Name : GYRO_Z_AMP
 */

/*
 * gyro_z_amp
 * Gyroscope Z axis input stimuli zero-to-peak linear amplitude selection in the range [0 dps : +3000 dps[  (resolution 11.71875 dps) (gyro_z_amp[7:0])/256∙3000 dps
 */
#define REG_GYRO_Z_AMP_GYRO_Z_AMP_POS      0x00
#define REG_GYRO_Z_AMP_GYRO_Z_AMP_MASK     0xff



/*
 * REG_GYRO_Z_OFS
 * Register Name : GYRO_Z_OFS
 */

/*
 * gyro_z_ofs
 * Gyroscope Z axis input stimuli linear offset selection in the range [–3000 dps: +3000 dps [  (resolution 23.4375 dps)($signed(gyro_z_ofs[7:0]))/128∙3000 dps
 */
#define REG_GYRO_Z_OFS_GYRO_Z_OFS_POS      0x00
#define REG_GYRO_Z_OFS_GYRO_Z_OFS_MASK     0xff



/*
 * REG_GYRO_Z_PHA
 * Register Name : GYRO_Z_PHA
 */

/*
 * gyro_z_dith_en
 * When high Gyroscope Z axis dither is enabled on sinewave stimulus
 */
#define REG_GYRO_Z_PHA_GYRO_Z_DITH_EN_POS      0x00
#define REG_GYRO_Z_PHA_GYRO_Z_DITH_EN_MASK     0x01

/*
 * gyro_z_pha
 * Gyroscope Z axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((gyro_z_pha[6:0]))/128∙360 deg
 */
#define REG_GYRO_Z_PHA_GYRO_Z_PHA_POS      0x01
#define REG_GYRO_Z_PHA_GYRO_Z_PHA_MASK     (0x7f << REG_GYRO_Z_PHA_GYRO_Z_PHA_POS)



/*
 * REG_ACCEL_GYRO_CLKDIV
 * Register Name : ACCEL_GYRO_CLKDIV
 */

/*
 * gyro_clk_div
 * Gyro sinwave generator clock frequency (Fclk @ 4MHz) divider. Impacting stimuli generated frequencies. Fclk/[2^(clk_div  [3:0])]
 */
#define REG_ACCEL_GYRO_CLKDIV_GYRO_CLK_DIV_POS      0x00
#define REG_ACCEL_GYRO_CLKDIV_GYRO_CLK_DIV_MASK     0x0f

/*
 * accel_clk_div
 * Accelero sinwave generator clock frequency (Fclk @ 4MHz) divider. Impacting stimuli generated frequencies. Fclk/[2^(clk_div  [3:0])]
 */
#define REG_ACCEL_GYRO_CLKDIV_ACCEL_CLK_DIV_POS      0x04
#define REG_ACCEL_GYRO_CLKDIV_ACCEL_CLK_DIV_MASK     (0x0f << REG_ACCEL_GYRO_CLKDIV_ACCEL_CLK_DIV_POS)



/*
 * REG_FPGA_CTRL
 * Register Name : FPGA_CTRL
 */

/*
 * bram_wr_dis
 * 1: to disable write access to BRAM.
 */
#define REG_FPGA_CTRL_BRAM_WR_DIS_POS      0x00
#define REG_FPGA_CTRL_BRAM_WR_DIS_MASK     0x01

/*
 * ram_ovf
 * 1: means SRAM overflow error ever occurs.
 */
#define REG_FPGA_CTRL_RAM_OVF_POS      0x01
#define REG_FPGA_CTRL_RAM_OVF_MASK     (0x01 << REG_FPGA_CTRL_RAM_OVF_POS)



/*
 * REG_OTP_ERROR_STATUS
 * Register Name : OTP_ERROR_STATUS
 */

/*
 * diff_read_mismatch_error
 * Error due to mismatch between true vs complimentary data in OTP differential read mode
 */
#define REG_OTP_ERROR_STATUS_DIFF_READ_MISMATCH_ERROR_POS      0x00
#define REG_OTP_ERROR_STATUS_DIFF_READ_MISMATCH_ERROR_MASK     0x01

/*
 * prog_more_than_1_bit_error
 * Error when host attempts to program more than 1 bit into OTP at a given time
 */
#define REG_OTP_ERROR_STATUS_PROG_MORE_THAN_1_BIT_ERROR_POS      0x01
#define REG_OTP_ERROR_STATUS_PROG_MORE_THAN_1_BIT_ERROR_MASK     (0x01 << REG_OTP_ERROR_STATUS_PROG_MORE_THAN_1_BIT_ERROR_POS)

/*
 * prog_0_bit_error
 * Error when host attempts to program 0 bit into OTP at a given time
 */
#define REG_OTP_ERROR_STATUS_PROG_0_BIT_ERROR_POS      0x02
#define REG_OTP_ERROR_STATUS_PROG_0_BIT_ERROR_MASK     (0x01 << REG_OTP_ERROR_STATUS_PROG_0_BIT_ERROR_POS)

/*
 * cfg_mismatch_error
 * Error when there is an unexpected OTP configuration settings for MR, MRA, MRB
 */
#define REG_OTP_ERROR_STATUS_CFG_MISMATCH_ERROR_POS      0x03
#define REG_OTP_ERROR_STATUS_CFG_MISMATCH_ERROR_MASK     (0x01 << REG_OTP_ERROR_STATUS_CFG_MISMATCH_ERROR_POS)



/*
 * REG_DIFF_READ_ERROR_BITMASK0_0
 * Register Name : DIFF_READ_ERROR_BITMASK0_0
 */

/*
 * diff_read_error_bitmask
 * Field displays which bit contains mismatch between true vs complimentary data in OTP differential read mode, of the last read error location
 */
#define REG_DIFF_READ_ERROR_BITMASK0_0_DIFF_READ_ERROR_BITMASK_POS      0x00
#define REG_DIFF_READ_ERROR_BITMASK0_0_DIFF_READ_ERROR_BITMASK_MASK     0xff



/*
 * REG_DIFF_READ_ERROR_BITMASK0_1
 * Register Name : DIFF_READ_ERROR_BITMASK0_1
 */

/*
 * diff_read_error_bitmask
 * Field displays which bit contains mismatch between true vs complimentary data in OTP differential read mode, of the last read error location
 */
#define REG_DIFF_READ_ERROR_BITMASK0_1_DIFF_READ_ERROR_BITMASK_POS      0x00
#define REG_DIFF_READ_ERROR_BITMASK0_1_DIFF_READ_ERROR_BITMASK_MASK     0xff



/*
 * REG_DIFF_READ_ERROR_ADDR0_0
 * Register Name : DIFF_READ_ERROR_ADDR0_0
 */

/*
 * diff_read_error_addr
 * Field displays the last read error location where there exist a mismatch between true vs complimentary data in OTP differential read mode
 */
#define REG_DIFF_READ_ERROR_ADDR0_0_DIFF_READ_ERROR_ADDR_POS      0x00
#define REG_DIFF_READ_ERROR_ADDR0_0_DIFF_READ_ERROR_ADDR_MASK     0xff



/*
 * REG_DIFF_READ_ERROR_ADDR0_1
 * Register Name : DIFF_READ_ERROR_ADDR0_1
 */

/*
 * diff_read_error_addr
 * Field displays the last read error location where there exist a mismatch between true vs complimentary data in OTP differential read mode
 */
#define REG_DIFF_READ_ERROR_ADDR0_1_DIFF_READ_ERROR_ADDR_POS      0x00
#define REG_DIFF_READ_ERROR_ADDR0_1_DIFF_READ_ERROR_ADDR_MASK     0x03



/*
 * REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_0
 * Register Name : PROG_MORE_THAN_1BIT_ERROR_DATA0_0
 */

/*
 * prog_more_than_1_bit_error_data
 * Field displays last attempted program data which is more than 1 bit
 */
#define REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_0_PROG_MORE_THAN_1_BIT_ERROR_DATA_POS      0x00
#define REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_0_PROG_MORE_THAN_1_BIT_ERROR_DATA_MASK     0xff



/*
 * REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_1
 * Register Name : PROG_MORE_THAN_1BIT_ERROR_DATA0_1
 */

/*
 * prog_more_than_1_bit_error_data
 * Field displays last attempted program data which is more than 1 bit
 */
#define REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_1_PROG_MORE_THAN_1_BIT_ERROR_DATA_POS      0x00
#define REG_PROG_MORE_THAN_1BIT_ERROR_DATA0_1_PROG_MORE_THAN_1_BIT_ERROR_DATA_MASK     0xff



/*
 * REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_0
 * Register Name : PROG_MORE_THAN_1BIT_ERROR_ADDR0_0
 */

/*
 * prog_more_than_1_bit_error_addr
 * Field displays last attempted program location of which data is more than 1 bit
 */
#define REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_0_PROG_MORE_THAN_1_BIT_ERROR_ADDR_POS      0x00
#define REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_0_PROG_MORE_THAN_1_BIT_ERROR_ADDR_MASK     0xff



/*
 * REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_1
 * Register Name : PROG_MORE_THAN_1BIT_ERROR_ADDR0_1
 */

/*
 * prog_more_than_1_bit_error_addr
 * Field displays last attempted program location of which data is more than 1 bit
 */
#define REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_1_PROG_MORE_THAN_1_BIT_ERROR_ADDR_POS      0x00
#define REG_PROG_MORE_THAN_1BIT_ERROR_ADDR0_1_PROG_MORE_THAN_1_BIT_ERROR_ADDR_MASK     0x03



/*
 * REG_PROG_0BIT_ERROR_DATA0_0
 * Register Name : PROG_0BIT_ERROR_DATA0_0
 */

/*
 * prog_0_bit_error_data
 * Field displays last attempted program data which is 0 bit
 */
#define REG_PROG_0BIT_ERROR_DATA0_0_PROG_0_BIT_ERROR_DATA_POS      0x00
#define REG_PROG_0BIT_ERROR_DATA0_0_PROG_0_BIT_ERROR_DATA_MASK     0xff



/*
 * REG_PROG_0BIT_ERROR_DATA0_1
 * Register Name : PROG_0BIT_ERROR_DATA0_1
 */

/*
 * prog_0_bit_error_data
 * Field displays last attempted program data which is 0 bit
 */
#define REG_PROG_0BIT_ERROR_DATA0_1_PROG_0_BIT_ERROR_DATA_POS      0x00
#define REG_PROG_0BIT_ERROR_DATA0_1_PROG_0_BIT_ERROR_DATA_MASK     0xff



/*
 * REG_PROG_0BIT_ERROR_ADDR0_0
 * Register Name : PROG_0BIT_ERROR_ADDR0_0
 */

/*
 * prog_0_bit_error_error
 * Field displays last attempted program location of which data is 0 bit
 */
#define REG_PROG_0BIT_ERROR_ADDR0_0_PROG_0_BIT_ERROR_ERROR_POS      0x00
#define REG_PROG_0BIT_ERROR_ADDR0_0_PROG_0_BIT_ERROR_ERROR_MASK     0xff



/*
 * REG_PROG_0BIT_ERROR_ADDR0_1
 * Register Name : PROG_0BIT_ERROR_ADDR0_1
 */

/*
 * prog_0_bit_error_error
 * Field displays last attempted program location of which data is 0 bit
 */
#define REG_PROG_0BIT_ERROR_ADDR0_1_PROG_0_BIT_ERROR_ERROR_POS      0x00
#define REG_PROG_0BIT_ERROR_ADDR0_1_PROG_0_BIT_ERROR_ERROR_MASK     0x03



/*
 * REG_FPGA_REG0
 * Register Name : FPGA_REG0
 */

/*
 * fpga_dbg0
 * debug registers
 */
#define REG_FPGA_REG0_FPGA_DBG0_POS      0x00
#define REG_FPGA_REG0_FPGA_DBG0_MASK     0xff



/*
 * REG_FPGA_REG1
 * Register Name : FPGA_REG1
 */

/*
 * fpga_dbg1
 * debug registers
 */
#define REG_FPGA_REG1_FPGA_DBG1_POS      0x00
#define REG_FPGA_REG1_FPGA_DBG1_MASK     0xff



/*
 * REG_FPGA_REG2
 * Register Name : FPGA_REG2
 */

/*
 * fpga_dbg2
 * debug registers
 */
#define REG_FPGA_REG2_FPGA_DBG2_POS      0x00
#define REG_FPGA_REG2_FPGA_DBG2_MASK     0xff



/*
 * REG_FPGA_REG3
 * Register Name : FPGA_REG3
 */

/*
 * fpga_dbg3
 * debug registers
 */
#define REG_FPGA_REG3_FPGA_DBG3_POS      0x00
#define REG_FPGA_REG3_FPGA_DBG3_MASK     0xff



/*
 * REG_FPGA_REG4
 * Register Name : FPGA_REG4
 */

/*
 * fpga_dbg4
 * debug registers
 */
#define REG_FPGA_REG4_FPGA_DBG4_POS      0x00
#define REG_FPGA_REG4_FPGA_DBG4_MASK     0xff



/*
 * REG_FPGA_REG5
 * Register Name : FPGA_REG5
 */

/*
 * fpga_dbg5
 * debug registers
 */
#define REG_FPGA_REG5_FPGA_DBG5_POS      0x00
#define REG_FPGA_REG5_FPGA_DBG5_MASK     0xff



/*
 * REG_FPGA_STAT0
 * Register Name : FPGA_STAT0
 */

/*
 * fpga_dbgstat0
 * debug status
 */
#define REG_FPGA_STAT0_FPGA_DBGSTAT0_POS      0x00
#define REG_FPGA_STAT0_FPGA_DBGSTAT0_MASK     0xff



/*
 * REG_FPGA_STAT1
 * Register Name : FPGA_STAT1
 */

/*
 * fpga_dbgstat1
 * debug status
 */
#define REG_FPGA_STAT1_FPGA_DBGSTAT1_POS      0x00
#define REG_FPGA_STAT1_FPGA_DBGSTAT1_MASK     0xff


/* ---------------------------------------------------------------------------
 * register IPREG_OTP
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register IPREG_SYS1
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_SYS1_REG_42
 * Register Name : IPREG_SYS1_REG_42
 */

/*
 * gyro_x_offuser
 * user correction range ±62.5 [dps], resolution 7.5 [mdps]
 */
#define REG_IPREG_SYS1_REG_42_GYRO_X_OFFUSER_POS      0x00
#define REG_IPREG_SYS1_REG_42_GYRO_X_OFFUSER_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_43
 * Register Name : IPREG_SYS1_REG_43
 */

/*
 * gyro_x_offuser
 * user correction range ±62.5 [dps], resolution 7.5 [mdps]
 */
#define REG_IPREG_SYS1_REG_43_GYRO_X_OFFUSER_POS      0x00
#define REG_IPREG_SYS1_REG_43_GYRO_X_OFFUSER_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_56
 * Register Name : IPREG_SYS1_REG_56
 */

/*
 * gyro_y_offuser
 * user correction range ±62.5 [dps], resolution 7.5 [mdps]
 */
#define REG_IPREG_SYS1_REG_56_GYRO_Y_OFFUSER_POS      0x00
#define REG_IPREG_SYS1_REG_56_GYRO_Y_OFFUSER_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_57
 * Register Name : IPREG_SYS1_REG_57
 */

/*
 * gyro_y_offuser
 * user correction range ±62.5 [dps], resolution 7.5 [mdps]
 */
#define REG_IPREG_SYS1_REG_57_GYRO_Y_OFFUSER_POS      0x00
#define REG_IPREG_SYS1_REG_57_GYRO_Y_OFFUSER_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_70
 * Register Name : IPREG_SYS1_REG_70
 */

/*
 * gyro_z_offuser
 * user correction range ±62.5 [dps], resolution 7.5 [mdps]
 */
#define REG_IPREG_SYS1_REG_70_GYRO_Z_OFFUSER_POS      0x00
#define REG_IPREG_SYS1_REG_70_GYRO_Z_OFFUSER_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_71
 * Register Name : IPREG_SYS1_REG_71
 */

/*
 * gyro_z_offuser
 * user correction range ±62.5 [dps], resolution 7.5 [mdps]
 */
#define REG_IPREG_SYS1_REG_71_GYRO_Z_OFFUSER_POS      0x00
#define REG_IPREG_SYS1_REG_71_GYRO_Z_OFFUSER_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_118
 * Register Name : IPREG_SYS1_REG_118
 */

/*
 * gyro_x_usergain
 * gyro user sensitivity calibration range is(0,2] with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_118_GYRO_X_USERGAIN_POS      0x00
#define REG_IPREG_SYS1_REG_118_GYRO_X_USERGAIN_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_119
 * Register Name : IPREG_SYS1_REG_119
 */

/*
 * gyro_x_usergain
 * gyro user sensitivity calibration range is(0,2] with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_119_GYRO_X_USERGAIN_POS      0x00
#define REG_IPREG_SYS1_REG_119_GYRO_X_USERGAIN_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_130
 * Register Name : IPREG_SYS1_REG_130
 */

/*
 * gyro_y_usergain
 * gyro user sensitivity calibration range is(0,2] with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_130_GYRO_Y_USERGAIN_POS      0x00
#define REG_IPREG_SYS1_REG_130_GYRO_Y_USERGAIN_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_131
 * Register Name : IPREG_SYS1_REG_131
 */

/*
 * gyro_y_usergain
 * gyro user sensitivity calibration range is(0,2] with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_131_GYRO_Y_USERGAIN_POS      0x00
#define REG_IPREG_SYS1_REG_131_GYRO_Y_USERGAIN_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_142
 * Register Name : IPREG_SYS1_REG_142
 */

/*
 * gyro_z_usergain
 * gyro user sensitivity calibration range is(0,2] with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_142_GYRO_Z_USERGAIN_POS      0x00
#define REG_IPREG_SYS1_REG_142_GYRO_Z_USERGAIN_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_143
 * Register Name : IPREG_SYS1_REG_143
 */

/*
 * gyro_z_usergain
 * gyro user sensitivity calibration range is(0,2] with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_143_GYRO_Z_USERGAIN_POS      0x00
#define REG_IPREG_SYS1_REG_143_GYRO_Z_USERGAIN_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_166
 * Register Name : IPREG_SYS1_REG_166
 */

/*
 * gyro_afsr_mode
 * 00: disabled, use LOW; 01: disabled, use HIGH;
 * 10: enabled, starts LOW; 11: enabled, starts HIGH
 */
#define REG_IPREG_SYS1_REG_166_GYRO_AFSR_MODE_POS      0x03
#define REG_IPREG_SYS1_REG_166_GYRO_AFSR_MODE_MASK     (0x03 << REG_IPREG_SYS1_REG_166_GYRO_AFSR_MODE_POS)

/*
 * gyro_src_ctrl
 * SRC CTRL: 0x0: S4S and FIR filter off, 0x1: S4S off and FIR filter on, 0x2: S4S on and FIR filter on, 0x3: reserved (debug mode).
 */
#define REG_IPREG_SYS1_REG_166_GYRO_SRC_CTRL_POS      0x05
#define REG_IPREG_SYS1_REG_166_GYRO_SRC_CTRL_MASK     (0x03 << REG_IPREG_SYS1_REG_166_GYRO_SRC_CTRL_POS)



/*
 * REG_IPREG_SYS1_REG_168
 * Register Name : IPREG_SYS1_REG_168
 */

/*
 * gyro_afsr_shared
 * 1: all axis switch to high if just one is high;
 * 0: all axis are independently handling afsr
 */
#define REG_IPREG_SYS1_REG_168_GYRO_AFSR_SHARED_POS      0x00
#define REG_IPREG_SYS1_REG_168_GYRO_AFSR_SHARED_MASK     0x01

/*
 * gyro_ois_m6_byp
 * 0: ois notch enabled; 1: ois notch disabled
 */
#define REG_IPREG_SYS1_REG_168_GYRO_OIS_M6_BYP_POS      0x01
#define REG_IPREG_SYS1_REG_168_GYRO_OIS_M6_BYP_MASK     (0x01 << REG_IPREG_SYS1_REG_168_GYRO_OIS_M6_BYP_POS)

/*
 * REG_IPREG_SYS1_REG_169
 * Register Name : IPREG_SYS1_REG_169
 */

/*
 * gyro_dec1_sat_det
 * this 3 bit signal flags saturation detected by decimator 1st stage; when the corresponding bit is set, saturation is detected. Assignment is [0]->x [1]->y [2]->z
 */
#define REG_IPREG_SYS1_REG_169_GYRO_DEC1_SAT_DET_POS      0x00
#define REG_IPREG_SYS1_REG_169_GYRO_DEC1_SAT_DET_MASK     0x07



/*
 * REG_IPREG_SYS1_REG_170
 * Register Name : IPREG_SYS1_REG_170
 */

/*
 * gyro_lp_avg_sel
 * Gyro Low Power Mode Average Selection
 * 0:1  1:2   2:4   3:5  4:7   5:8  6:10  7:11  8:16  9:18  10:20  11:32  12-15: 64
 */
#define REG_IPREG_SYS1_REG_170_GYRO_LP_AVG_SEL_POS      0x01
#define REG_IPREG_SYS1_REG_170_GYRO_LP_AVG_SEL_MASK     (0x0f << REG_IPREG_SYS1_REG_170_GYRO_LP_AVG_SEL_POS)

/*
 * gyro_ois_hpfbw_sel
 * OIS HPF for gyro;
 * 0: bypass; 1: 1Hz; 2:250mHz; 3:62mHz; 4:16mHz
 */
#define REG_IPREG_SYS1_REG_170_GYRO_OIS_HPFBW_SEL_POS      0x05
#define REG_IPREG_SYS1_REG_170_GYRO_OIS_HPFBW_SEL_MASK     (0x07 << REG_IPREG_SYS1_REG_170_GYRO_OIS_HPFBW_SEL_POS)



/*
 * REG_IPREG_SYS1_REG_171
 * Register Name : IPREG_SYS1_REG_171
 */

/*
 * gyro_ois_lpf1bw_sel
 * selects OIS1 low pass cut-off
 * 0: bypass; 1: 1100; 2:900, 3:600; 4:285; 5:139; 6,7:65 [Hz]
 */
#define REG_IPREG_SYS1_REG_171_GYRO_OIS_LPF1BW_SEL_POS      0x00
#define REG_IPREG_SYS1_REG_171_GYRO_OIS_LPF1BW_SEL_MASK     0x07

/*
 * gyro_ois_lpf2bw_sel
 * selects OIS2 low pass cut-off
 * 0: bypass; 1: 1100; 2:900, 3:600; 4:285; 5:139; 6,7:65 [Hz]
 */
#define REG_IPREG_SYS1_REG_171_GYRO_OIS_LPF2BW_SEL_POS      0x03
#define REG_IPREG_SYS1_REG_171_GYRO_OIS_LPF2BW_SEL_MASK     (0x07 << REG_IPREG_SYS1_REG_171_GYRO_OIS_LPF2BW_SEL_POS)



/*
 * REG_IPREG_SYS1_REG_172
 * Register Name : IPREG_SYS1_REG_172
 */

/*
 * gyro_ui_lpfbw_sel
 * Selects UI path low pass cut-off
 * 0:bypass; 1: ODR/4 2: ODR/8 3:ODR/16 4:ODR/32 5:ODR/64 6,7:ODR/128
 */
#define REG_IPREG_SYS1_REG_172_GYRO_UI_LPFBW_SEL_POS      0x00
#define REG_IPREG_SYS1_REG_172_GYRO_UI_LPFBW_SEL_MASK     0x07

/*
 * gyro_lpf_bypass
 * 1: Bypass LPF in Gyro UI signal path for all axes.
 */
#define REG_IPREG_SYS1_REG_172_GYRO_LPF_BYPASS_POS      0x04
#define REG_IPREG_SYS1_REG_172_GYRO_LPF_BYPASS_MASK     (0x01 << REG_IPREG_SYS1_REG_172_GYRO_LPF_BYPASS_POS)

/*
 * gyro_ois_hpf1_byp
 * 1: bypasses HPF for OIS1 path
 */
#define REG_IPREG_SYS1_REG_172_GYRO_OIS_HPF1_BYP_POS      0x07
#define REG_IPREG_SYS1_REG_172_GYRO_OIS_HPF1_BYP_MASK     (0x01 << REG_IPREG_SYS1_REG_172_GYRO_OIS_HPF1_BYP_POS)



/*
 * REG_IPREG_SYS1_REG_173
 * Register Name : IPREG_SYS1_REG_173
 */

/*
 * gyro_ois_hpf2_byp
 * 1: bypasses HPF for OIS2 path
 */
#define REG_IPREG_SYS1_REG_173_GYRO_OIS_HPF2_BYP_POS      0x00
#define REG_IPREG_SYS1_REG_173_GYRO_OIS_HPF2_BYP_MASK     0x01


/* ---------------------------------------------------------------------------
 * register IPREG_SYS2
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_SYS2_REG_24
 * Register Name : IPREG_SYS2_REG_24
 */

/*
 * accel_x_offuser
 * gos offset correction (user): range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_24_ACCEL_X_OFFUSER_POS      0x00
#define REG_IPREG_SYS2_REG_24_ACCEL_X_OFFUSER_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_25
 * Register Name : IPREG_SYS2_REG_25
 */

/*
 * accel_x_offuser
 * gos offset correction (user): range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_25_ACCEL_X_OFFUSER_POS      0x00
#define REG_IPREG_SYS2_REG_25_ACCEL_X_OFFUSER_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_32
 * Register Name : IPREG_SYS2_REG_32
 */

/*
 * accel_y_offuser
 * gos offset correction (user): range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_32_ACCEL_Y_OFFUSER_POS      0x00
#define REG_IPREG_SYS2_REG_32_ACCEL_Y_OFFUSER_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_33
 * Register Name : IPREG_SYS2_REG_33
 */

/*
 * accel_y_offuser
 * gos offset correction (user): range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_33_ACCEL_Y_OFFUSER_POS      0x00
#define REG_IPREG_SYS2_REG_33_ACCEL_Y_OFFUSER_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_40
 * Register Name : IPREG_SYS2_REG_40
 */

/*
 * accel_z_offuser
 * gos offset correction (user): range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_40_ACCEL_Z_OFFUSER_POS      0x00
#define REG_IPREG_SYS2_REG_40_ACCEL_Z_OFFUSER_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_41
 * Register Name : IPREG_SYS2_REG_41
 */

/*
 * accel_z_offuser
 * gos offset correction (user): range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_41_ACCEL_Z_OFFUSER_POS      0x00
#define REG_IPREG_SYS2_REG_41_ACCEL_Z_OFFUSER_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_48
 * Register Name : IPREG_SYS2_REG_48
 */

/*
 * accel_x_usergain
 * gos sensitivity adjustment for user: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_48_ACCEL_X_USERGAIN_POS      0x00
#define REG_IPREG_SYS2_REG_48_ACCEL_X_USERGAIN_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_49
 * Register Name : IPREG_SYS2_REG_49
 */

/*
 * accel_x_usergain
 * gos sensitivity adjustment for user: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_49_ACCEL_X_USERGAIN_POS      0x00
#define REG_IPREG_SYS2_REG_49_ACCEL_X_USERGAIN_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_56
 * Register Name : IPREG_SYS2_REG_56
 */

/*
 * accel_y_usergain
 * gos sensitivity adjustment for user: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_56_ACCEL_Y_USERGAIN_POS      0x00
#define REG_IPREG_SYS2_REG_56_ACCEL_Y_USERGAIN_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_57
 * Register Name : IPREG_SYS2_REG_57
 */

/*
 * accel_y_usergain
 * gos sensitivity adjustment for user: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_57_ACCEL_Y_USERGAIN_POS      0x00
#define REG_IPREG_SYS2_REG_57_ACCEL_Y_USERGAIN_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_64
 * Register Name : IPREG_SYS2_REG_64
 */

/*
 * accel_z_usergain
 * gos sensitivity adjustment for user: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_64_ACCEL_Z_USERGAIN_POS      0x00
#define REG_IPREG_SYS2_REG_64_ACCEL_Z_USERGAIN_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_65
 * Register Name : IPREG_SYS2_REG_65
 */

/*
 * accel_z_usergain
 * gos sensitivity adjustment for user: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_65_ACCEL_Z_USERGAIN_POS      0x00
#define REG_IPREG_SYS2_REG_65_ACCEL_Z_USERGAIN_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_123
 * Register Name : IPREG_SYS2_REG_123
 */

/*
 * accel_src_ctrl
 * SRC CTRL: 0x0: S4S and FIR filter off, 0x1: S4S off and FIR filter on, 0x2: S4S on and FIR filter on, 0x3: reserved (debug mode).
 */
#define REG_IPREG_SYS2_REG_123_ACCEL_SRC_CTRL_POS      0x00
#define REG_IPREG_SYS2_REG_123_ACCEL_SRC_CTRL_MASK     0x03

/*
 * REG_IPREG_SYS2_REG_128
 * Register Name : IPREG_SYS2_REG_128
 */

/*
 * tmp_lpf_cfg
 * Set Temp Sensor Low Pass Filter BW (LNM)
 */
#define REG_IPREG_SYS2_REG_128_TMP_LPF_CFG_POS      0x00
#define REG_IPREG_SYS2_REG_128_TMP_LPF_CFG_MASK     0x07

/*
 * tmp_dec_cfg
 * temperature sensor decimation factor - controls the processing ODR of the temperature sensor 0 through 7. 0->bypass; 7->2^7 = 128
 */
#define REG_IPREG_SYS2_REG_128_TMP_DEC_CFG_POS      0x03
#define REG_IPREG_SYS2_REG_128_TMP_DEC_CFG_MASK     (0x07 << REG_IPREG_SYS2_REG_128_TMP_DEC_CFG_POS)

/*
 * REG_IPREG_SYS2_REG_129
 * Register Name : IPREG_SYS2_REG_129
 */

/*
 * accel_lp_avg_sel
 * Accel Low Power Mode Average Selection
 * 0:1  1:2   2:4   3:5  4:7   5:8  6:10  7:11  8:16  9:18  10:20  11:32  12-15: 64
 */
#define REG_IPREG_SYS2_REG_129_ACCEL_LP_AVG_SEL_POS      0x00
#define REG_IPREG_SYS2_REG_129_ACCEL_LP_AVG_SEL_MASK     0x0f

/*
 * accel_ois_hpfbw_sel
 * OIS HPF for XL;
 * 0: bypass; 1: 1Hz; 2:250mHz; 3:62mHz; 4:16mHz
 */
#define REG_IPREG_SYS2_REG_129_ACCEL_OIS_HPFBW_SEL_POS      0x04
#define REG_IPREG_SYS2_REG_129_ACCEL_OIS_HPFBW_SEL_MASK     (0x07 << REG_IPREG_SYS2_REG_129_ACCEL_OIS_HPFBW_SEL_POS)



/*
 * REG_IPREG_SYS2_REG_130
 * Register Name : IPREG_SYS2_REG_130
 */

/*
 * accel_ois_lpf1bw_sel
 * selects XL OIS1 low pass cut-off
 * 0: bypass; 1: 1600; 2: 1100; 3:655; 4:290; 5:135; 6:65 [Hz]
 */
#define REG_IPREG_SYS2_REG_130_ACCEL_OIS_LPF1BW_SEL_POS      0x00
#define REG_IPREG_SYS2_REG_130_ACCEL_OIS_LPF1BW_SEL_MASK     0x07

/*
 * accel_ois_lpf2bw_sel
 * selects XL OIS2 low pass cut-off
 * 0: bypass; 1: 1100; 2:900, 3:600; 4:285; 5:139; 6,7:65 [Hz]
 */
#define REG_IPREG_SYS2_REG_130_ACCEL_OIS_LPF2BW_SEL_POS      0x03
#define REG_IPREG_SYS2_REG_130_ACCEL_OIS_LPF2BW_SEL_MASK     (0x07 << REG_IPREG_SYS2_REG_130_ACCEL_OIS_LPF2BW_SEL_POS)



/*
 * REG_IPREG_SYS2_REG_131
 * Register Name : IPREG_SYS2_REG_131
 */

/*
 * accel_ui_lpfbw_sel
 * Selects UI path low pass cut-off
 * 0:bypass; 1: ODR/4 2: ODR/8 3:ODR/16 4:ODR/32 5:ODR/64 6,7:ODR/128
 */
#define REG_IPREG_SYS2_REG_131_ACCEL_UI_LPFBW_SEL_POS      0x00
#define REG_IPREG_SYS2_REG_131_ACCEL_UI_LPFBW_SEL_MASK     0x07

/*
 * accel_lpf_bypass
 * 1: Bypass LPF in Accel UI signal path for all axes.
 */
#define REG_IPREG_SYS2_REG_131_ACCEL_LPF_BYPASS_POS      0x05
#define REG_IPREG_SYS2_REG_131_ACCEL_LPF_BYPASS_MASK     (0x01 << REG_IPREG_SYS2_REG_131_ACCEL_LPF_BYPASS_POS)

/*
 * REG_IPREG_SYS2_REG_132
 * Register Name : IPREG_SYS2_REG_132
 */

/*
 * accel_ois_hpf1_byp
 * 1: bypasses HPF for XL OIS1 path
 */
#define REG_IPREG_SYS2_REG_132_ACCEL_OIS_HPF1_BYP_POS      0x00
#define REG_IPREG_SYS2_REG_132_ACCEL_OIS_HPF1_BYP_MASK     0x01

/*
 * accel_ois_hpf2_byp
 * 1: bypasses HPF for XL OIS2 path
 */
#define REG_IPREG_SYS2_REG_132_ACCEL_OIS_HPF2_BYP_POS      0x01
#define REG_IPREG_SYS2_REG_132_ACCEL_OIS_HPF2_BYP_MASK     (0x01 << REG_IPREG_SYS2_REG_132_ACCEL_OIS_HPF2_BYP_POS)

/*
 * accel_ois_m6_byp
 * 0: ois notch enabled; 1: ois notch disabled (XL OIS)
 */
#define REG_IPREG_SYS2_REG_132_ACCEL_OIS_M6_BYP_POS      0x02
#define REG_IPREG_SYS2_REG_132_ACCEL_OIS_M6_BYP_MASK     (0x01 << REG_IPREG_SYS2_REG_132_ACCEL_OIS_M6_BYP_POS)


/* ---------------------------------------------------------------------------
 * register IPREG_TOP1
 * ---------------------------------------------------------------------------*/

/*
 * REG_FIFO_STATUS
 * Register Name : FIFO_STATUS
 */

/*
 * fifo_insufficient_mem
 * [Supports Dynamic Change] In Stop-on-full mode, it indicates that there is not enough space for a complete frame to be written into FIFO. In Stream mode it is not valid.
 * 0: FIFO accepts new frames (at least one new complete frame)
 * 1: FIFO is full and does not accept new frames
 */
#define REG_FIFO_STATUS_FIFO_INSUFFICIENT_MEM_POS      0x00
#define REG_FIFO_STATUS_FIFO_INSUFFICIENT_MEM_MASK     0x01

/*
 * fifo_overflow_state
 * [Supports Dynamic Change] Indicates whether FIFO is in overflow state. When the register is asserted, at least one frame has been written into FIFO full. It deasserts when the FIFO is no more full.
 * 0: FIFO not in overflow state
 * 1: FIFO in overflow state
 */
#define REG_FIFO_STATUS_FIFO_OVERFLOW_STATE_POS      0x01
#define REG_FIFO_STATUS_FIFO_OVERFLOW_STATE_MASK     (0x01 << REG_FIFO_STATUS_FIFO_OVERFLOW_STATE_POS)



/*
 * REG_PRG_ERR_STATUS
 * Register Name : PRG_ERR_STATUS
 */

/*
 * prog_err_status
 * [Supports Dynamic Change] Indicates a programming error has occurred
 * - Set on following conditions
 *     a) fifo_mode setting to 2'b11 attempt
 * - Cleared on:
 *     a) register read
 *     b) FIFO flush.
 *
 * NOTE: This register is obsolete. It is not part of Newport implementation.
 */
#define REG_PRG_ERR_STATUS_PROG_ERR_STATUS_POS      0x00
#define REG_PRG_ERR_STATUS_PROG_ERR_STATUS_MASK     0x01



/*
 * REG_FIFO_SRAM_OVRD
 * Register Name : FIFO_SRAM_OVRD
 */

/*
 * fifo_gsleep_sram_override_actv
 * Override all SRAM global sleep inputs active (force pwr_gsleep=1)
 *
 * 0: no change to SRAM gsleep (keep control by PSEQ)
 * 1: Override SRAM glseep and force active (pwr_gsleep=1). All SRAM's are in sleep mode.
 *
 * Can be changed when FIFO is disabled (Bypass mode), AHB interface idle.
 *
 * Note: fifo_gsleep_sram_override_inactv=1 takes higher priority than  fifo_gsleep_sram_override_actv=1, i.e. gsleep will remain inactive if both set.
 */
#define REG_FIFO_SRAM_OVRD_FIFO_GSLEEP_SRAM_OVERRIDE_ACTV_POS      0x00
#define REG_FIFO_SRAM_OVRD_FIFO_GSLEEP_SRAM_OVERRIDE_ACTV_MASK     0x01

/*
 * fifo_gsleep_sram_override_inactv
 * Override all SRAM global sleep inputs inactive (force pwr_gsleep=0)
 *
 * 0: no change to SRAM gsleep (keep control by PSEQ)
 * 1: Override SRAM glseep and force inactive (pwr_gsleep=0). All SRAM's are active.
 *
 * Can be changed when FIFO is disabled (Bypass mode), AHB interface idle.
 *
 * Note: fifo_gsleep_sram_override_inactv=1 takes higher priority than  fifo_gsleep_sram_override_actv=1, i.e. gsleep will remain inactive if both set, and all SRAM's will be active.
 */
#define REG_FIFO_SRAM_OVRD_FIFO_GSLEEP_SRAM_OVERRIDE_INACTV_POS      0x01
#define REG_FIFO_SRAM_OVRD_FIFO_GSLEEP_SRAM_OVERRIDE_INACTV_MASK     (0x01 << REG_FIFO_SRAM_OVRD_FIFO_GSLEEP_SRAM_OVERRIDE_INACTV_POS)

/*
 * fifo_retention_sram_override_actv
 * Override all SRAM retention inputs active (force pwr_lv=0)
 * 0: no change to SRAM retention
 * 1: Override SRAM retention and force active (pwr_lv=0)
 * Can be changed when FIFO is disabled (Bypass mode), AHB interface idle.
 *
 * Note: fifo_retention_sram_override_inactv=1 takes higher priority than  fifo_retention_sram_override_actv=1, i.e. retention will remain inactive if both set.
 */
#define REG_FIFO_SRAM_OVRD_FIFO_RETENTION_SRAM_OVERRIDE_ACTV_POS      0x02
#define REG_FIFO_SRAM_OVRD_FIFO_RETENTION_SRAM_OVERRIDE_ACTV_MASK     (0x01 << REG_FIFO_SRAM_OVRD_FIFO_RETENTION_SRAM_OVERRIDE_ACTV_POS)

/*
 * fifo_retention_sram_override_inactv
 * Override all SRAM retention inputs inactive (force pwr_lv=1)
 * 0: no change to SRAM retention
 * 1: Override SRAM retention and force inactive (pwr_lv=1)
 * Can be changed when FIFO is disabled (Bypass mode), AHB interface idle.
 *
 * Note: fifo_retention_sram_override_inactv=1 takes higher priority than  fifo_retention_sram_override_actv=1, i.e. retention will remain inactive if both set.
 */
#define REG_FIFO_SRAM_OVRD_FIFO_RETENTION_SRAM_OVERRIDE_INACTV_POS      0x03
#define REG_FIFO_SRAM_OVRD_FIFO_RETENTION_SRAM_OVERRIDE_INACTV_MASK     (0x01 << REG_FIFO_SRAM_OVRD_FIFO_RETENTION_SRAM_OVERRIDE_INACTV_POS)



/*
 * REG_I2CM_COMMAND_0
 * Register Name : I2CM_COMMAND_0
 */

/*
 * burstlen_0
 * Specifies the burst length of  I2C communication with the external slavedevice.
 */
#define REG_I2CM_COMMAND_0_BURSTLEN_0_POS      0x00
#define REG_I2CM_COMMAND_0_BURSTLEN_0_MASK     0x0f

/*
 * r_w_0
 * R/W command. R/W=0 for Wr Op. R/W=1 for Rd Op with register address specified. R/W=2 for Rd Op without register address specified.
 */
#define REG_I2CM_COMMAND_0_R_W_0_POS      0x04
#define REG_I2CM_COMMAND_0_R_W_0_MASK     (0x03 << REG_I2CM_COMMAND_0_R_W_0_POS)

/*
 * ch_sel_0
 * Specify the channel for transaction .#. Valid value is 0, 1, 2, 3. #
 */
#define REG_I2CM_COMMAND_0_CH_SEL_0_POS      0x06
#define REG_I2CM_COMMAND_0_CH_SEL_0_MASK     (0x01 << REG_I2CM_COMMAND_0_CH_SEL_0_POS)

/*
 * endflag_0
 * Indicate if the current entry is the last I2C communication with the external slave device.
 */
#define REG_I2CM_COMMAND_0_ENDFLAG_0_POS      0x07
#define REG_I2CM_COMMAND_0_ENDFLAG_0_MASK     (0x01 << REG_I2CM_COMMAND_0_ENDFLAG_0_POS)



/*
 * REG_I2CM_COMMAND_1
 * Register Name : I2CM_COMMAND_1
 */

/*
 * burstlen_1
 * Specifies the burst length of  I2C communication with the external slavedevice.
 */
#define REG_I2CM_COMMAND_1_BURSTLEN_1_POS      0x00
#define REG_I2CM_COMMAND_1_BURSTLEN_1_MASK     0x0f

/*
 * r_w_1
 * R/W command. R/W=0 for Wr Op. R/W=1 for Rd Op with register address specified. R/W=2 for Rd Op without register address specified.
 */
#define REG_I2CM_COMMAND_1_R_W_1_POS      0x04
#define REG_I2CM_COMMAND_1_R_W_1_MASK     (0x03 << REG_I2CM_COMMAND_1_R_W_1_POS)

/*
 * ch_sel_1
 * Specify the channel for transaction .#. Valid value is 0, 1, 2, 3. #
 */
#define REG_I2CM_COMMAND_1_CH_SEL_1_POS      0x06
#define REG_I2CM_COMMAND_1_CH_SEL_1_MASK     (0x01 << REG_I2CM_COMMAND_1_CH_SEL_1_POS)

/*
 * endflag_1
 * Indicate if the current entry is the last I2C communication with the external slave device.
 */
#define REG_I2CM_COMMAND_1_ENDFLAG_1_POS      0x07
#define REG_I2CM_COMMAND_1_ENDFLAG_1_MASK     (0x01 << REG_I2CM_COMMAND_1_ENDFLAG_1_POS)



/*
 * REG_I2CM_COMMAND_2
 * Register Name : I2CM_COMMAND_2
 */

/*
 * burstlen_2
 * Specifies the burst length of  I2C communication with the external slavedevice.
 */
#define REG_I2CM_COMMAND_2_BURSTLEN_2_POS      0x00
#define REG_I2CM_COMMAND_2_BURSTLEN_2_MASK     0x0f

/*
 * r_w_2
 * R/W command. R/W=0 for Wr Op. R/W=1 for Rd Op with register address specified. R/W=2 for Rd Op without register address specified.
 */
#define REG_I2CM_COMMAND_2_R_W_2_POS      0x04
#define REG_I2CM_COMMAND_2_R_W_2_MASK     (0x03 << REG_I2CM_COMMAND_2_R_W_2_POS)

/*
 * ch_sel_2
 * Specify the channel for transaction .#. Valid value is 0, 1, 2, 3. #
 */
#define REG_I2CM_COMMAND_2_CH_SEL_2_POS      0x06
#define REG_I2CM_COMMAND_2_CH_SEL_2_MASK     (0x01 << REG_I2CM_COMMAND_2_CH_SEL_2_POS)

/*
 * endflag_2
 * Indicate if the current entry is the last I2C communication with the external slave device.
 */
#define REG_I2CM_COMMAND_2_ENDFLAG_2_POS      0x07
#define REG_I2CM_COMMAND_2_ENDFLAG_2_MASK     (0x01 << REG_I2CM_COMMAND_2_ENDFLAG_2_POS)



/*
 * REG_I2CM_COMMAND_3
 * Register Name : I2CM_COMMAND_3
 */

/*
 * burstlen_3
 * Specifies the burst length of  I2C communication with the external slavedevice.
 */
#define REG_I2CM_COMMAND_3_BURSTLEN_3_POS      0x00
#define REG_I2CM_COMMAND_3_BURSTLEN_3_MASK     0x0f

/*
 * r_w_3
 * R/W command. R/W=0 for Wr Op. R/W=1 for Rd Op with register address specified. R/W=2 for Rd Op without register address specified.
 */
#define REG_I2CM_COMMAND_3_R_W_3_POS      0x04
#define REG_I2CM_COMMAND_3_R_W_3_MASK     (0x03 << REG_I2CM_COMMAND_3_R_W_3_POS)

/*
 * ch_sel_3
 * Specify the channel for transaction .#. Valid value is 0, 1, 2, 3. #
 */
#define REG_I2CM_COMMAND_3_CH_SEL_3_POS      0x06
#define REG_I2CM_COMMAND_3_CH_SEL_3_MASK     (0x01 << REG_I2CM_COMMAND_3_CH_SEL_3_POS)

/*
 * endflag_3
 * Indicate if the current entry is the last I2C communication with the external slave device.
 */
#define REG_I2CM_COMMAND_3_ENDFLAG_3_POS      0x07
#define REG_I2CM_COMMAND_3_ENDFLAG_3_MASK     (0x01 << REG_I2CM_COMMAND_3_ENDFLAG_3_POS)



/*
 * REG_I2CM_DEV_PROFILE0
 * Register Name : I2CM_DEV_PROFILE0
 */

/*
 * rd_address_0
 * Specifies the read address for the channel 0 I2C transaction
 */
#define REG_I2CM_DEV_PROFILE0_RD_ADDRESS_0_POS      0x00
#define REG_I2CM_DEV_PROFILE0_RD_ADDRESS_0_MASK     0xff



/*
 * REG_I2CM_DEV_PROFILE1
 * Register Name : I2CM_DEV_PROFILE1
 */

/*
 * dev_id_0
 * Specifies the slave ID for the channel 0 I2C transaction
 */
#define REG_I2CM_DEV_PROFILE1_DEV_ID_0_POS      0x00
#define REG_I2CM_DEV_PROFILE1_DEV_ID_0_MASK     0x7f



/*
 * REG_I2CM_DEV_PROFILE2
 * Register Name : I2CM_DEV_PROFILE2
 */

/*
 * rd_address_1
 * Specifies the read address for the channel 1 I2C transaction
 */
#define REG_I2CM_DEV_PROFILE2_RD_ADDRESS_1_POS      0x00
#define REG_I2CM_DEV_PROFILE2_RD_ADDRESS_1_MASK     0xff



/*
 * REG_I2CM_DEV_PROFILE3
 * Register Name : I2CM_DEV_PROFILE3
 */

/*
 * dev_id_1
 * Specifies the slave ID for the channel 1 I2C transaction
 */
#define REG_I2CM_DEV_PROFILE3_DEV_ID_1_POS      0x00
#define REG_I2CM_DEV_PROFILE3_DEV_ID_1_MASK     0x7f



/*
 * REG_I2CM_CONTROL
 * Register Name : I2CM_CONTROL
 */

/*
 * i2cm_go
 * 1  : kick off i2c operation.
 * Hardware clears this bit to 0 after i2c operation is done.
 * This bit is not programmable by MCU when i2cm_busy = 1.
 * This bit is not programmable by MCU if reg_aux_pin_configuration != 2’b01.
 */
#define REG_I2CM_CONTROL_I2CM_GO_POS      0x00
#define REG_I2CM_CONTROL_I2CM_GO_MASK     0x01

/*
 * i2cm_blk_srst
 * 1 :  terminate currently on-going i2c operation without issuing STOP to external device. The status registers and read buffers are resetted to default state. Asserts i2cm_done pulse that clears slv_rdy_intr and i2cm_go
 */
#define REG_I2CM_CONTROL_I2CM_BLK_SRST_POS      0x01
#define REG_I2CM_CONTROL_I2CM_BLK_SRST_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_BLK_SRST_POS)

/*
 * i2cm_fsm_srst
 * 1 :  terminate currently on-going i2c operation.
 * Hardware clears this bit to 0 after i2c operation is terminates.
 * I2CM terminates an active transaction only when I2CM owns the SDA line. The read data  is ignored
 * This bit is not programmable by MCU when i2cm_busy = 0.
 */
#define REG_I2CM_CONTROL_I2CM_FSM_SRST_POS      0x02
#define REG_I2CM_CONTROL_I2CM_FSM_SRST_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_FSM_SRST_POS)

/*
 * i2cm_speed
 * 1: I2C Standard Mode, 0: I2C Fast Mode. Default is 0.  This bit is not programmable by MCU when i2cm_busy = 1.
 */
#define REG_I2CM_CONTROL_I2CM_SPEED_POS      0x03
#define REG_I2CM_CONTROL_I2CM_SPEED_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_SPEED_POS)

/*
 * i2cm_scl_sda_err_disable
 * 0: enable the logic to detect SCL or SDA is driven low by external. So, i2cm_scl_err and i2cm_sda_err bits will be set based on error detection.
 *
 * 1: Disable the logic to detect SCL or SDA is driven low by external. So, i2cm_scl_err  and i2cm_sda_err will not be set. Note, if i2cm_scl_err or i2cm_sda_err  is already set, the setting reserved_i2cm bit to 1 won't clear i2cm_sda_err or i2cm_scl_err. User need to read the interrupt status to clear them.   This bit is not programmable by MCU when i2cm_busy = 1.
 */
#define REG_I2CM_CONTROL_I2CM_SCL_SDA_ERR_DISABLE_POS      0x04
#define REG_I2CM_CONTROL_I2CM_SCL_SDA_ERR_DISABLE_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_SCL_SDA_ERR_DISABLE_POS)

/*
 * i2cm_timeout_disable
 * 1 : Disables 32 ms internal timeout counter   .  This bit is not programmable by MCU when i2cm_busy = 1.
 */
#define REG_I2CM_CONTROL_I2CM_TIMEOUT_DISABLE_POS      0x05
#define REG_I2CM_CONTROL_I2CM_TIMEOUT_DISABLE_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_TIMEOUT_DISABLE_POS)

/*
 * i2cm_restart_en
 *  0x0: No reSTART is used.
 *  0x1:  if R/W=1, the reSTART is used to bridge the register-address write transaction and register-data read transaction.
 *
 *  This bit is not programmable by MCU when i2cm_busy = 1.
 */
#define REG_I2CM_CONTROL_I2CM_RESTART_EN_POS      0x06
#define REG_I2CM_CONTROL_I2CM_RESTART_EN_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_RESTART_EN_POS)

/*
 * i2cm_test_en
 * 1 : The read buffer is programmable only through APB. Read data from the external sensor by I2CM are dropped.
 */
#define REG_I2CM_CONTROL_I2CM_TEST_EN_POS      0x07
#define REG_I2CM_CONTROL_I2CM_TEST_EN_MASK     (0x01 << REG_I2CM_CONTROL_I2CM_TEST_EN_POS)



/*
 * REG_I2CM_STATUS
 * Register Name : I2CM_STATUS
 */

/*
 * i2cm_busy
 * 1: i2c operation is running. 0: no i2c operation is running.
 */
#define REG_I2CM_STATUS_I2CM_BUSY_POS      0x00
#define REG_I2CM_STATUS_I2CM_BUSY_MASK     0x01

/*
 * i2cm_done
 * 1: when i2c operation completes, with or without errors. This bit is cleared due to (a) MCU read or (b) when i2c_go is programmed to 1 c) i2c_slv_intr is asserted
 */
#define REG_I2CM_STATUS_I2CM_DONE_POS      0x01
#define REG_I2CM_STATUS_I2CM_DONE_MASK     (0x01 << REG_I2CM_STATUS_I2CM_DONE_POS)

/*
 * i2cm_timeout_err
 * 1: if slave holds SDA low > 32 ms  This bit is cleared due to (a) MCU read or (b) when i2c_go is programmed to 1. c) i2c_slv_intr is asserted .
 */
#define REG_I2CM_STATUS_I2CM_TIMEOUT_ERR_POS      0x02
#define REG_I2CM_STATUS_I2CM_TIMEOUT_ERR_MASK     (0x01 << REG_I2CM_STATUS_I2CM_TIMEOUT_ERR_POS)

/*
 * i2cm_srst_err
 * 1: if current i2c operation is terminated by MCU using i2cm_fsm_srst. This bit is cleared due to (a) MCU read or (b) when i2c_go is programmed to 1.  c) i2c_slv_intr is asserted
 */
#define REG_I2CM_STATUS_I2CM_SRST_ERR_POS      0x03
#define REG_I2CM_STATUS_I2CM_SRST_ERR_MASK     (0x01 << REG_I2CM_STATUS_I2CM_SRST_ERR_POS)

/*
 * i2cm_scl_err
 * 1: if SCL is driven low by external device when I2CM tries to drives SCL from high to low.                   I2CM expects SCL is high before driving it to low, but SCL is low already before driven by I2CM. If the SCL is low at the time when i2cm_go is programmed to 1, I2CM waits for SCL is released (to 1) and then starts the I2C communication, and i2cm_scl_err  is not set. If the error occurs in the middle of a live I2C communication, I2CM terminates the current I2C communication without giving out I2C/STOP event, and i2cm_scl_err  is set.
 */
#define REG_I2CM_STATUS_I2CM_SCL_ERR_POS      0x04
#define REG_I2CM_STATUS_I2CM_SCL_ERR_MASK     (0x01 << REG_I2CM_STATUS_I2CM_SCL_ERR_POS)

/*
 * i2cm_sda_err
 * 1: if SDA is driven low by external device when I2CM has the ownership driving SDA line. During the time when I2CM owns SDA line and I2CM keeps SDA at high, but it is driven to low by external. If SDA is low at the time when i2cm_go is programmed to 1, I2CM waits for SDA is released (to 1) and then starts the I2C communication, and i2cm_sda_err is not set. If the error occurs in the middle of a live I2C communication, I2CM terminates the current I2C communication without giving out I2C/STOP event, and i2cm_sda_err is set.
 * This bit is cleared due to (a) MCU read or (b) when i2c_go is programmed to 1. c) i2c_slv_intr is asserted
 */
#define REG_I2CM_STATUS_I2CM_SDA_ERR_POS      0x05
#define REG_I2CM_STATUS_I2CM_SDA_ERR_MASK     (0x01 << REG_I2CM_STATUS_I2CM_SDA_ERR_POS)



/*
 * REG_I2CM_EXT_DEV_STATUS
 * Register Name : I2CM_EXT_DEV_STATUS
 */

/*
 * i2cm_ext_dev_status
 * status tracks the ACK/NACK feedback from the external device per each entry of the command buffer. The reg_ext_dev_status is default to 8’hFF when I2CM is kicked off. 1=NACK, 0=ACK
 */
#define REG_I2CM_EXT_DEV_STATUS_I2CM_EXT_DEV_STATUS_POS      0x00
#define REG_I2CM_EXT_DEV_STATUS_I2CM_EXT_DEV_STATUS_MASK     0x0f



/*
 * REG_I2CM_RD_DATA0
 * Register Name : I2CM_RD_DATA0
 */

/*
 * i2cm_rd_data0
 * The first  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA0_I2CM_RD_DATA0_POS      0x00
#define REG_I2CM_RD_DATA0_I2CM_RD_DATA0_MASK     0xff



/*
 * REG_I2CM_RD_DATA1
 * Register Name : I2CM_RD_DATA1
 */

/*
 * i2cm_rd_data1
 * The 2nd  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA1_I2CM_RD_DATA1_POS      0x00
#define REG_I2CM_RD_DATA1_I2CM_RD_DATA1_MASK     0xff



/*
 * REG_I2CM_RD_DATA2
 * Register Name : I2CM_RD_DATA2
 */

/*
 * i2cm_rd_data2
 * The 3nd  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA2_I2CM_RD_DATA2_POS      0x00
#define REG_I2CM_RD_DATA2_I2CM_RD_DATA2_MASK     0xff



/*
 * REG_I2CM_RD_DATA3
 * Register Name : I2CM_RD_DATA3
 */

/*
 * i2cm_rd_data3
 * The 4th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA3_I2CM_RD_DATA3_POS      0x00
#define REG_I2CM_RD_DATA3_I2CM_RD_DATA3_MASK     0xff



/*
 * REG_I2CM_RD_DATA4
 * Register Name : I2CM_RD_DATA4
 */

/*
 * i2cm_rd_data4
 * The 5th byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA4_I2CM_RD_DATA4_POS      0x00
#define REG_I2CM_RD_DATA4_I2CM_RD_DATA4_MASK     0xff



/*
 * REG_I2CM_RD_DATA5
 * Register Name : I2CM_RD_DATA5
 */

/*
 * i2cm_rd_data5
 * The 6th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA5_I2CM_RD_DATA5_POS      0x00
#define REG_I2CM_RD_DATA5_I2CM_RD_DATA5_MASK     0xff



/*
 * REG_I2CM_RD_DATA6
 * Register Name : I2CM_RD_DATA6
 */

/*
 * i2cm_rd_data6
 * The 7th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA6_I2CM_RD_DATA6_POS      0x00
#define REG_I2CM_RD_DATA6_I2CM_RD_DATA6_MASK     0xff



/*
 * REG_I2CM_RD_DATA7
 * Register Name : I2CM_RD_DATA7
 */

/*
 * i2cm_rd_data7
 * The 8th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA7_I2CM_RD_DATA7_POS      0x00
#define REG_I2CM_RD_DATA7_I2CM_RD_DATA7_MASK     0xff



/*
 * REG_I2CM_RD_DATA8
 * Register Name : I2CM_RD_DATA8
 */

/*
 * i2cm_rd_data8
 * The 9th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA8_I2CM_RD_DATA8_POS      0x00
#define REG_I2CM_RD_DATA8_I2CM_RD_DATA8_MASK     0xff



/*
 * REG_I2CM_RD_DATA9
 * Register Name : I2CM_RD_DATA9
 */

/*
 * i2cm_rd_data9
 * The 10th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA9_I2CM_RD_DATA9_POS      0x00
#define REG_I2CM_RD_DATA9_I2CM_RD_DATA9_MASK     0xff



/*
 * REG_I2CM_RD_DATA10
 * Register Name : I2CM_RD_DATA10
 */

/*
 * i2cm_rd_data10
 * The 11th byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA10_I2CM_RD_DATA10_POS      0x00
#define REG_I2CM_RD_DATA10_I2CM_RD_DATA10_MASK     0xff



/*
 * REG_I2CM_RD_DATA11
 * Register Name : I2CM_RD_DATA11
 */

/*
 * i2cm_rd_data11
 * The 12th byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA11_I2CM_RD_DATA11_POS      0x00
#define REG_I2CM_RD_DATA11_I2CM_RD_DATA11_MASK     0xff



/*
 * REG_I2CM_RD_DATA12
 * Register Name : I2CM_RD_DATA12
 */

/*
 * i2cm_rd_data12
 * The 13th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA12_I2CM_RD_DATA12_POS      0x00
#define REG_I2CM_RD_DATA12_I2CM_RD_DATA12_MASK     0xff



/*
 * REG_I2CM_RD_DATA13
 * Register Name : I2CM_RD_DATA13
 */

/*
 * i2cm_rd_data13
 * The 14th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertionof a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA13_I2CM_RD_DATA13_POS      0x00
#define REG_I2CM_RD_DATA13_I2CM_RD_DATA13_MASK     0xff



/*
 * REG_I2CM_RD_DATA14
 * Register Name : I2CM_RD_DATA14
 */

/*
 * i2cm_rd_data14
 * The 15th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA14_I2CM_RD_DATA14_POS      0x00
#define REG_I2CM_RD_DATA14_I2CM_RD_DATA14_MASK     0xff



/*
 * REG_I2CM_RD_DATA15
 * Register Name : I2CM_RD_DATA15
 */

/*
 * i2cm_rd_data15
 * The 16th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA15_I2CM_RD_DATA15_POS      0x00
#define REG_I2CM_RD_DATA15_I2CM_RD_DATA15_MASK     0xff



/*
 * REG_I2CM_RD_DATA16
 * Register Name : I2CM_RD_DATA16
 */

/*
 * i2cm_rd_data16
 * The 17th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA16_I2CM_RD_DATA16_POS      0x00
#define REG_I2CM_RD_DATA16_I2CM_RD_DATA16_MASK     0xff



/*
 * REG_I2CM_RD_DATA17
 * Register Name : I2CM_RD_DATA17
 */

/*
 * i2cm_rd_data17
 * The 18th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA17_I2CM_RD_DATA17_POS      0x00
#define REG_I2CM_RD_DATA17_I2CM_RD_DATA17_MASK     0xff



/*
 * REG_I2CM_RD_DATA18
 * Register Name : I2CM_RD_DATA18
 */

/*
 * i2cm_rd_data18
 * The 19th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA18_I2CM_RD_DATA18_POS      0x00
#define REG_I2CM_RD_DATA18_I2CM_RD_DATA18_MASK     0xff



/*
 * REG_I2CM_RD_DATA19
 * Register Name : I2CM_RD_DATA19
 */

/*
 * i2cm_rd_data19
 * The 20th  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA19_I2CM_RD_DATA19_POS      0x00
#define REG_I2CM_RD_DATA19_I2CM_RD_DATA19_MASK     0xff



/*
 * REG_I2CM_RD_DATA20
 * Register Name : I2CM_RD_DATA20
 */

/*
 * i2cm_rd_data20
 * The 21 st  byte received from i2c slave.   Contents of this register is automatically cleared to 0 when i2cm_go = 1  or  i2c_slv_intr assertion of a read operation (not write operation).
 */
#define REG_I2CM_RD_DATA20_I2CM_RD_DATA20_POS      0x00
#define REG_I2CM_RD_DATA20_I2CM_RD_DATA20_MASK     0xff



/*
 * REG_I2CM_WR_DATA0
 * Register Name : I2CM_WR_DATA0
 */

/*
 * i2cm_wr_data0
 * The data/address byte for a Write transaction
 */
#define REG_I2CM_WR_DATA0_I2CM_WR_DATA0_POS      0x00
#define REG_I2CM_WR_DATA0_I2CM_WR_DATA0_MASK     0xff



/*
 * REG_I2CM_WR_DATA1
 * Register Name : I2CM_WR_DATA1
 */

/*
 * i2cm_wr_data1
 * The data/address byte for a Write transaction
 */
#define REG_I2CM_WR_DATA1_I2CM_WR_DATA1_POS      0x00
#define REG_I2CM_WR_DATA1_I2CM_WR_DATA1_MASK     0xff



/*
 * REG_I2CM_WR_DATA2
 * Register Name : I2CM_WR_DATA2
 */

/*
 * i2cm_wr_data2
 * The data/address byte for a Write transaction
 */
#define REG_I2CM_WR_DATA2_I2CM_WR_DATA2_POS      0x00
#define REG_I2CM_WR_DATA2_I2CM_WR_DATA2_MASK     0xff



/*
 * REG_I2CM_WR_DATA3
 * Register Name : I2CM_WR_DATA3
 */

/*
 * i2cm_wr_data3
 * The data/address byte for a Write transaction
 */
#define REG_I2CM_WR_DATA3_I2CM_WR_DATA3_POS      0x00
#define REG_I2CM_WR_DATA3_I2CM_WR_DATA3_MASK     0xff



/*
 * REG_I2CM_WR_DATA4
 * Register Name : I2CM_WR_DATA4
 */

/*
 * i2cm_wr_data4
 * The data/address byte for a Write transaction
 */
#define REG_I2CM_WR_DATA4_I2CM_WR_DATA4_POS      0x00
#define REG_I2CM_WR_DATA4_I2CM_WR_DATA4_MASK     0xff



/*
 * REG_I2CM_WR_DATA5
 * Register Name : I2CM_WR_DATA5
 */

/*
 * i2cm_wr_data5
 * The data/address byte for a Write transaction
 */
#define REG_I2CM_WR_DATA5_I2CM_WR_DATA5_POS      0x00
#define REG_I2CM_WR_DATA5_I2CM_WR_DATA5_MASK     0xff



/*
 * REG_DEBUG_CONTROL
 * Register Name : DEBUG_CONTROL
 */

/*
 * debg_1
 * debug register
 */
#define REG_DEBUG_CONTROL_DEBG_1_POS      0x00
#define REG_DEBUG_CONTROL_DEBG_1_MASK     0xff



/*
 * REG_SRAM_ROM_MARGIN_CTRL
 * Register Name : SRAM_ROM_MARGIN_CTRL
 */

/*
 * fifo_sram_margin
 * Margin Control. Asynchronous.
 * Recommended setting is 2’b10.
 *
 * These bits control the read and write margin.
 * 2’b00 provides the  highest margin (slowest).
 * 2’b11 provides the least margin (fastest).
 *
 * For FA and debug, it is strongly recommended to allow control over margin (e.g. through a register) during both test and functional mode.
 *
 */
#define REG_SRAM_ROM_MARGIN_CTRL_FIFO_SRAM_MARGIN_POS      0x00
#define REG_SRAM_ROM_MARGIN_CTRL_FIFO_SRAM_MARGIN_MASK     0x03

/*
 * rom_margin
 * Margin Control. Asynchronous.
 * Recommended setting is 1’b0.
 *
 * When asserted high, margin reduces the read margin.
 * For FA and debug, it is strongly recommended to allow control over margin (e.g. through a register) during both test and functional mode.
 *
 *
 */
#define REG_SRAM_ROM_MARGIN_CTRL_ROM_MARGIN_POS      0x02
#define REG_SRAM_ROM_MARGIN_CTRL_ROM_MARGIN_MASK     (0x01 << REG_SRAM_ROM_MARGIN_CTRL_ROM_MARGIN_POS)



/*
 * REG_SIFS_IXC_ERROR_STATUS
 * Register Name : SIFS_IXC_ERROR_STATUS
 */

/*
 * sifs_ixc_timeout_err
 * [Supports Dynamic Change] 1: indicates that an IxC timeout error occurred in SIFS. No clock toggle condition from host for 32 ms while an IxC transaction was ongoing(after START and before STOP).
 * 0: no timeout error or when SPI slave is selected for serial transfers.
 */
#define REG_SIFS_IXC_ERROR_STATUS_SIFS_IXC_TIMEOUT_ERR_POS      0x00
#define REG_SIFS_IXC_ERROR_STATUS_SIFS_IXC_TIMEOUT_ERR_MASK     0x01

/*
 * aux1_sifs_ixc_timeout_err
 * [Supports Dynamic Change] 1: indicates that an IxC timeout error occurred in AUX1 SIFS. No clock toggle condition from host for 32 ms while an IxC transaction was ongoing(after START and before STOP).
 * 0: no timeout error or when SPI slave is selected for serial transfers.
 */
#define REG_SIFS_IXC_ERROR_STATUS_AUX1_SIFS_IXC_TIMEOUT_ERR_POS      0x01
#define REG_SIFS_IXC_ERROR_STATUS_AUX1_SIFS_IXC_TIMEOUT_ERR_MASK     (0x01 << REG_SIFS_IXC_ERROR_STATUS_AUX1_SIFS_IXC_TIMEOUT_ERR_POS)



/*
 * REG_EDMP_PRGRM_IRQ0_0
 * Register Name : EDMP_PRGRM_IRQ0_0
 */

/*
 * prgrm_strt_addr_irq_0
 * [Supports Dynamic Change] start address of IRQ_0 vector
 */
#define REG_EDMP_PRGRM_IRQ0_0_PRGRM_STRT_ADDR_IRQ_0_POS      0x00
#define REG_EDMP_PRGRM_IRQ0_0_PRGRM_STRT_ADDR_IRQ_0_MASK     0xff



/*
 * REG_EDMP_PRGRM_IRQ0_1
 * Register Name : EDMP_PRGRM_IRQ0_1
 */

/*
 * prgrm_strt_addr_irq_0
 * [Supports Dynamic Change] start address of IRQ_0 vector
 */
#define REG_EDMP_PRGRM_IRQ0_1_PRGRM_STRT_ADDR_IRQ_0_POS      0x00
#define REG_EDMP_PRGRM_IRQ0_1_PRGRM_STRT_ADDR_IRQ_0_MASK     0xff



/*
 * REG_EDMP_PRGRM_IRQ1_0
 * Register Name : EDMP_PRGRM_IRQ1_0
 */

/*
 * prgrm_strt_addr_irq_1
 * [Supports Dynamic Change] start address of IRQ_1 vector
 */
#define REG_EDMP_PRGRM_IRQ1_0_PRGRM_STRT_ADDR_IRQ_1_POS      0x00
#define REG_EDMP_PRGRM_IRQ1_0_PRGRM_STRT_ADDR_IRQ_1_MASK     0xff



/*
 * REG_EDMP_PRGRM_IRQ1_1
 * Register Name : EDMP_PRGRM_IRQ1_1
 */

/*
 * prgrm_strt_addr_irq_1
 * [Supports Dynamic Change] start address of IRQ_1 vector
 */
#define REG_EDMP_PRGRM_IRQ1_1_PRGRM_STRT_ADDR_IRQ_1_POS      0x00
#define REG_EDMP_PRGRM_IRQ1_1_PRGRM_STRT_ADDR_IRQ_1_MASK     0xff



/*
 * REG_EDMP_PRGRM_IRQ2_0
 * Register Name : EDMP_PRGRM_IRQ2_0
 */

/*
 * prgrm_strt_addr_irq_2
 * [Supports Dynamic Change] start address of IRQ_2 vector
 */
#define REG_EDMP_PRGRM_IRQ2_0_PRGRM_STRT_ADDR_IRQ_2_POS      0x00
#define REG_EDMP_PRGRM_IRQ2_0_PRGRM_STRT_ADDR_IRQ_2_MASK     0xff



/*
 * REG_EDMP_PRGRM_IRQ2_1
 * Register Name : EDMP_PRGRM_IRQ2_1
 */

/*
 * prgrm_strt_addr_irq_2
 * [Supports Dynamic Change] start address of IRQ_2 vector
 */
#define REG_EDMP_PRGRM_IRQ2_1_PRGRM_STRT_ADDR_IRQ_2_POS      0x00
#define REG_EDMP_PRGRM_IRQ2_1_PRGRM_STRT_ADDR_IRQ_2_MASK     0xff



/*
 * REG_EDMP_SP_START_ADDR
 * Register Name : EDMP_SP_START_ADDR
 */

/*
 * sp_start_addr
 * [Supports Dynamic Change] bit [15:8] of AHB address of SRAM allocated for DMP stack
 */
#define REG_EDMP_SP_START_ADDR_SP_START_ADDR_POS      0x00
#define REG_EDMP_SP_START_ADDR_SP_START_ADDR_MASK     0xff



/*
 * REG_PMC_AGC_TIMER_CFG
 * Register Name : PMC_AGC_TIMER_CFG
 */

/*
 * power_save_disable
 * Disable Switchable domain functionality
 */
#define REG_PMC_AGC_TIMER_CFG_POWER_SAVE_DISABLE_POS      0x00
#define REG_PMC_AGC_TIMER_CFG_POWER_SAVE_DISABLE_MASK     0x01

/*
 * sense_en_del_trim
 * Delay Gyro Sense turn ON, in Gyro LN mode. Resolution is 1 ms/LSB
 */
#define REG_PMC_AGC_TIMER_CFG_SENSE_EN_DEL_TRIM_POS      0x01
#define REG_PMC_AGC_TIMER_CFG_SENSE_EN_DEL_TRIM_MASK     (0x07 << REG_PMC_AGC_TIMER_CFG_SENSE_EN_DEL_TRIM_POS)

/*
 * gyro_drive_ovd_ctrl_trim
 * If '1', when an overdrive condition is detected, Gyro DRV will undergo a power-down/power-up cycle to recover from the fault. Maximum five trials will be performed fro recovery.
 */
#define REG_PMC_AGC_TIMER_CFG_GYRO_DRIVE_OVD_CTRL_TRIM_POS      0x04
#define REG_PMC_AGC_TIMER_CFG_GYRO_DRIVE_OVD_CTRL_TRIM_MASK     (0x01 << REG_PMC_AGC_TIMER_CFG_GYRO_DRIVE_OVD_CTRL_TRIM_POS)

/*
 * agc_timer_cfg
 * To select timeout range when enabling the gyro drive sensor.
 */
#define REG_PMC_AGC_TIMER_CFG_AGC_TIMER_CFG_POS      0x05
#define REG_PMC_AGC_TIMER_CFG_AGC_TIMER_CFG_MASK     (0x03 << REG_PMC_AGC_TIMER_CFG_AGC_TIMER_CFG_POS)

/*
 * force_gyro_sns_en
 * Force Gyro Sense ON, independently from Gyro DRV state
 */
#define REG_PMC_AGC_TIMER_CFG_FORCE_GYRO_SNS_EN_POS      0x07
#define REG_PMC_AGC_TIMER_CFG_FORCE_GYRO_SNS_EN_MASK     (0x01 << REG_PMC_AGC_TIMER_CFG_FORCE_GYRO_SNS_EN_POS)



/*
 * REG_PMC_AGC_TIMER_CFG_0
 * Register Name : PMC_AGC_TIMER_CFG_0
 */

/*
 * gyro_wdog_dis
 * When set at '1' it disables the watchdog timer detecting start-up failures of the Gyro Drive
 */
#define REG_PMC_AGC_TIMER_CFG_0_GYRO_WDOG_DIS_POS      0x00
#define REG_PMC_AGC_TIMER_CFG_0_GYRO_WDOG_DIS_MASK     0x01



/*
 * REG_SMC_CONTROL_0
 * Register Name : SMC_CONTROL_0
 */

/*
 * tmst_en
 * Time Stamp register Enable
 */
#define REG_SMC_CONTROL_0_TMST_EN_POS      0x00
#define REG_SMC_CONTROL_0_TMST_EN_MASK     0x01

/*
 * tmst_fsync_en
 * Time Stamp register Fsync Enable . When set to 1, the contents of the Timestamp feature of  FSYNC  is enabled.
 */
#define REG_SMC_CONTROL_0_TMST_FSYNC_EN_POS      0x01
#define REG_SMC_CONTROL_0_TMST_FSYNC_EN_MASK     (0x01 << REG_SMC_CONTROL_0_TMST_FSYNC_EN_POS)

/*
 * tmst_force_aux_fine_en
 * If 1 forces Time Stamp fine counting also on OIS/AUX interfaces. Otherwise, if 0, Time Stamp fine counting is enabled only on UI/AP interfaces.
 */
#define REG_SMC_CONTROL_0_TMST_FORCE_AUX_FINE_EN_POS      0x02
#define REG_SMC_CONTROL_0_TMST_FORCE_AUX_FINE_EN_MASK     (0x01 << REG_SMC_CONTROL_0_TMST_FORCE_AUX_FINE_EN_POS)

/*
 * temp_dis
 * This bit disables the temp sensor analog IP
 */
#define REG_SMC_CONTROL_0_TEMP_DIS_POS      0x03
#define REG_SMC_CONTROL_0_TEMP_DIS_MASK     (0x01 << REG_SMC_CONTROL_0_TEMP_DIS_POS)

/*
 * accel_lp_clk_sel
 * [Supports Dynamic Change] Selects between Wake-Up oscillator (0) and RC oscillator (1) for Accelerometer Low-Power mode.
 * In order to avoid unexpected behaviors, select the correct clock by writing this register before setting the accel_mode register.
 *
 * The Wake-Up oscillator LP mode cannot be used in conjunction with external synchronization (MIPI I3C or CLKIN/RTC). Setting this bit to 0 when external sync is enabled will result in an invalid configuration and will not be applied.
 * External synchronization can be enabled only if this bit is set to 1.
 *
 * For STC enable the register need to be programmed '1'
 */
#define REG_SMC_CONTROL_0_ACCEL_LP_CLK_SEL_POS      0x04
#define REG_SMC_CONTROL_0_ACCEL_LP_CLK_SEL_MASK     (0x01 << REG_SMC_CONTROL_0_ACCEL_LP_CLK_SEL_POS)

/*
 * REG_SMC_CONTROL_1
 * Register Name : SMC_CONTROL_1
 */

/*
 * ulp_ed_rcosc_wu_trim
 * Number of ODR ticks (under the WU-osc) required for the RC-osc to turn on from a complete OFF state.
 */
#define REG_SMC_CONTROL_1_ULP_ED_RCOSC_WU_TRIM_POS      0x00
#define REG_SMC_CONTROL_1_ULP_ED_RCOSC_WU_TRIM_MASK     0x07

/*
 * REG_SMC_ANA_LAT_TRIM_0
 * Register Name : SMC_ANA_LAT_TRIM_0
 */

/*
 * accel_ana_lat_trim
 * Analog latency trimming value for the Accelerometer sensor in number of ODR ticks.
 * ODR tick frequency is at its nominal value (i.e. 6.4kHz)
 */
#define REG_SMC_ANA_LAT_TRIM_0_ACCEL_ANA_LAT_TRIM_POS      0x00
#define REG_SMC_ANA_LAT_TRIM_0_ACCEL_ANA_LAT_TRIM_MASK     0x1f



/*
 * REG_SMC_ANA_LAT_TRIM_1
 * Register Name : SMC_ANA_LAT_TRIM_1
 */

/*
 * gyro_ana_lat_trim
 * Analog latency trimming value for the Gyroscope sensor in number of ODR ticks.
 * ODR tick frequency is at its nominal value (i.e. 6.4kHz)
 */
#define REG_SMC_ANA_LAT_TRIM_1_GYRO_ANA_LAT_TRIM_POS      0x00
#define REG_SMC_ANA_LAT_TRIM_1_GYRO_ANA_LAT_TRIM_MASK     0x1f



/*
 * REG_SMC_ANA_LAT_TRIM_STC
 * Register Name : SMC_ANA_LAT_TRIM_STC
 */

/*
 * accel_ana_lat_trim_stc_mode
 * Analog latency trimming value for the Accelerometer sensor in number of ODR ticks.
 * ODR tick frequency is modulated by external synchronization events (STC mode enabled).
 */
#define REG_SMC_ANA_LAT_TRIM_STC_ACCEL_ANA_LAT_TRIM_STC_MODE_POS      0x00
#define REG_SMC_ANA_LAT_TRIM_STC_ACCEL_ANA_LAT_TRIM_STC_MODE_MASK     0x1f



/*
 * REG_SMC_ANA_LAT_TRIM_STC_0
 * Register Name : SMC_ANA_LAT_TRIM_STC_0
 */

/*
 * gyro_ana_lat_trim_stc_mode
 * Analog latency trimming value for the Gyroscope sensor in number of ODR ticks.
 * ODR tick frequency is modulated by external synchronization events (STC mode enabled).
 */
#define REG_SMC_ANA_LAT_TRIM_STC_0_GYRO_ANA_LAT_TRIM_STC_MODE_POS      0x00
#define REG_SMC_ANA_LAT_TRIM_STC_0_GYRO_ANA_LAT_TRIM_STC_MODE_MASK     0x1f



/*
 * REG_SMC_DEC1_TON
 * Register Name : SMC_DEC1_TON
 */

/*
 * accel_dec1_ton
 * Number of ODR ticks (at nominal 6.4kHz) for the Accel DEC1.
 */
#define REG_SMC_DEC1_TON_ACCEL_DEC1_TON_POS      0x00
#define REG_SMC_DEC1_TON_ACCEL_DEC1_TON_MASK     0x07

/*
 * gyro_dec1_ton
 * Number of ODR ticks (at nominal 6.4kHz) for the Gyro DEC1.
 */
#define REG_SMC_DEC1_TON_GYRO_DEC1_TON_POS      0x03
#define REG_SMC_DEC1_TON_GYRO_DEC1_TON_MASK     (0x07 << REG_SMC_DEC1_TON_GYRO_DEC1_TON_POS)



/*
 * REG_SMC_ODR_STAT
 * Register Name : SMC_ODR_STAT
 */

/*
 * accel_ap_status_odr
 * Accelerometer Output Data Rate status at the UI/AP FIFO
 */
#define REG_SMC_ODR_STAT_ACCEL_AP_STATUS_ODR_POS      0x00
#define REG_SMC_ODR_STAT_ACCEL_AP_STATUS_ODR_MASK     0x0f

/*
 * gyro_ap_status_odr
 * Gyroscope Output Data Rate status at the UI/AP FIFO
 */
#define REG_SMC_ODR_STAT_GYRO_AP_STATUS_ODR_POS      0x04
#define REG_SMC_ODR_STAT_GYRO_AP_STATUS_ODR_MASK     (0x0f << REG_SMC_ODR_STAT_GYRO_AP_STATUS_ODR_POS)



/*
 * REG_ACCEL_DEBUG
 * Register Name : ACCEL_DEBUG
 */

/*
 * xl_16fs_debug
 * 0: Normal function1: Debug mode-> Sets XL digital full-scale to 16gee, XL analog C2V full-scale to 32gee and XL analog integrator gain to 2.
 */
#define REG_ACCEL_DEBUG_XL_16FS_DEBUG_POS      0x00
#define REG_ACCEL_DEBUG_XL_16FS_DEBUG_MASK     0x01



/*
 * REG_STC_CONFIG
 * Register Name : STC_CONFIG
 */

/*
 * stc_mode
 * [Supports Dynamic Change] 00: s4s mode, 01: force mode, 10: freeze mode, 11: (reserved)
 */
#define REG_STC_CONFIG_STC_MODE_POS      0x00
#define REG_STC_CONFIG_STC_MODE_MASK     0x03

/*
 * stc_sensor_sel
 * [Supports Dynamic Change] 00,01: slowest ODR, 10: accel, 11: gyro
 */
#define REG_STC_CONFIG_STC_SENSOR_SEL_POS      0x02
#define REG_STC_CONFIG_STC_SENSOR_SEL_MASK     (0x03 << REG_STC_CONFIG_STC_SENSOR_SEL_POS)



/*
 * REG_STC_TICK_PER_FRC_0
 * Register Name : STC_TICK_PER_FRC_0
 */

/*
 * tick_per_frc
 * [Supports Dynamic Change] forced value for odr tick period (in clk_smc cycles)
 */
#define REG_STC_TICK_PER_FRC_0_TICK_PER_FRC_POS      0x00
#define REG_STC_TICK_PER_FRC_0_TICK_PER_FRC_MASK     0xff



/*
 * REG_STC_TICK_PER_FRC_1
 * Register Name : STC_TICK_PER_FRC_1
 */

/*
 * tick_per_frc
 * [Supports Dynamic Change] forced value for odr tick period (in clk_smc cycles)
 */
#define REG_STC_TICK_PER_FRC_1_TICK_PER_FRC_POS      0x00
#define REG_STC_TICK_PER_FRC_1_TICK_PER_FRC_MASK     0x01



/*
 * REG_STC_TICK_PER_FRC_SUB
 * Register Name : STC_TICK_PER_FRC_SUB
 */

/*
 * tick_per_frc_sub
 * [Supports Dynamic Change] forced value for odr tick period (sub LSBs)
 */
#define REG_STC_TICK_PER_FRC_SUB_TICK_PER_FRC_SUB_POS      0x00
#define REG_STC_TICK_PER_FRC_SUB_TICK_PER_FRC_SUB_MASK     0x1f



/*
 * REG_SREG_CTRL
 * Register Name : SREG_CTRL
 */

/*
 * sreg_invalid_ind_dis
 * Disable the invalid sample tag
 * 0 : when the sensor data is invalid each sample from that sensor is substituted by the invalid sample tag (0x8000). When the sensor data is valid, every word of data coming from that sensor equal to 0x8000 or 0x8001 is substituted by 0x8002.
 * 1 : no substitution in case of invalid sample
 */
#define REG_SREG_CTRL_SREG_INVALID_IND_DIS_POS      0x00
#define REG_SREG_CTRL_SREG_INVALID_IND_DIS_MASK     0x01

/*
 * sreg_data_endian_sel
 * Select the endianess of the Sensor Data Registers and FIFO data
 * 0 : data to Sensor Registers and FIFO are in Little Endian format
 * 1 : data to Sensor Registers and FIFO are in Big Endian format
 */
#define REG_SREG_CTRL_SREG_DATA_ENDIAN_SEL_POS      0x01
#define REG_SREG_CTRL_SREG_DATA_ENDIAN_SEL_MASK     (0x01 << REG_SREG_CTRL_SREG_DATA_ENDIAN_SEL_POS)

/*
 * sreg_debug_data_inject_en
 * Select the debug mode data injection. When this bit is set, the input buffer registers are no longer updated by SIGP. The AHB sensors read-only registers become read/write, thus Host can write to them and the incoming data are stored in input buffer registers. AHB master then can access and read the injected data as they come from SIGP. A coordination between Host and and AHB master is required to avoid conflicts.
 * 0 : data injection is disabled
 * 1 : data injection is enabled
 */
#define REG_SREG_CTRL_SREG_DEBUG_DATA_INJECT_EN_POS      0x02
#define REG_SREG_CTRL_SREG_DEBUG_DATA_INJECT_EN_MASK     (0x01 << REG_SREG_CTRL_SREG_DEBUG_DATA_INJECT_EN_POS)



/*
 * REG_SIFS_I3C_STC_CFG
 * Register Name : SIFS_I3C_STC_CFG
 */

/*
 * i3c_stc_mode
 * Enable the STC controller.
 * When set to 0 the parts will deliver ODR events with
 * uncorrected frequency and phase based on internal timebase.
 * When set to 1 the frequency and phase correction loops
 * will be activated.
 * Toggling it will make the correction loops restart as out of POR.
 * STC functionality can be enabled only if accel_lp_clk_sel is set to 1; otherwise device may not behave as expected.
 *
 * To enable STC in POR, otp trim value should be '1'
 */
#define REG_SIFS_I3C_STC_CFG_I3C_STC_MODE_POS      0x02
#define REG_SIFS_I3C_STC_CFG_I3C_STC_MODE_MASK     (0x01 << REG_SIFS_I3C_STC_CFG_I3C_STC_MODE_POS)

/*
 * REG_INT_PULSE_MIN_ON_INTF0
 * Register Name : INT_PULSE_MIN_ON_INTF0
 */

/*
 * int0_tpulse_duration
 * UI/AP Interface: Pulse Min "on" duration, indicates minimum interrupt assertion duration when in pulse mode.
 * 0: Interrupt pulse duration is 100us. Use only if ODR < 4KHz (Default).
 * 1:Interrupt pulse duration is 8us. Required if ODR >= 4KHz, optional for ODR < 4KHz.
 * 2,3,4,5,6,7 are reserved.
 */
#define REG_INT_PULSE_MIN_ON_INTF0_INT0_TPULSE_DURATION_POS      0x00
#define REG_INT_PULSE_MIN_ON_INTF0_INT0_TPULSE_DURATION_MASK     0x07



/*
 * REG_INT_PULSE_MIN_ON_INTF1
 * Register Name : INT_PULSE_MIN_ON_INTF1
 */

/*
 * int1_tpulse_duration
 * UI/AP Interface: Pulse Min "on" duration, indicates minimum interrupt assertion duration when in pulse mode.
 * 0: Interrupt pulse duration is 100us. Use only if ODR < 4KHz (Default).
 * 1:Interrupt pulse duration is 8us. Required if ODR >= 4KHz, optional for ODR < 4KHz.
 * 2,3,4,5,6,7 are reserved.
 */
#define REG_INT_PULSE_MIN_ON_INTF1_INT1_TPULSE_DURATION_POS      0x00
#define REG_INT_PULSE_MIN_ON_INTF1_INT1_TPULSE_DURATION_MASK     0x07



/*
 * REG_INT_PULSE_MIN_OFF_INTF0
 * Register Name : INT_PULSE_MIN_OFF_INTF0
 */

/*
 * int0_tdeassert_disable
 * Interface UI/AP: Min "off" duration, indicates Minimum interrupt de-assertion duration.
 * 0 is 100us [default],
 * 1 is 8us,
 * 2 is: No minimum interrupt de-assertion duration requirement. Two back-to-back interrupt assertions could be separated by at least one MCLK cycle. This option should be only used for MCU and IBI interface only.
 * 3,4,5,6,7 are reserved.
 */
#define REG_INT_PULSE_MIN_OFF_INTF0_INT0_TDEASSERT_DISABLE_POS      0x00
#define REG_INT_PULSE_MIN_OFF_INTF0_INT0_TDEASSERT_DISABLE_MASK     0x07



/*
 * REG_INT_PULSE_MIN_OFF_INTF1
 * Register Name : INT_PULSE_MIN_OFF_INTF1
 */

/*
 * int1_tdeassert_disable
 * Interface UI/AP: Min "off" duration, indicates Minimum interrupt de-assertion duration.
 * 0 is 100us [default],
 * 1 is 8us,
 * 2 is: No minimum interrupt de-assertion duration requirement. Two back-to-back interrupt assertions could be separated by at least one MCLK cycle. This option should be only used for MCU and IBI interface only.
 * 3,4,5,6,7 are reserved.
 */
#define REG_INT_PULSE_MIN_OFF_INTF1_INT1_TDEASSERT_DISABLE_POS      0x00
#define REG_INT_PULSE_MIN_OFF_INTF1_INT1_TDEASSERT_DISABLE_MASK     0x07



/*
 * REG_ISR_0_7
 * Register Name : ISR_0_7
 */

/*
 * int_status_accel_drdy_pin_0
 *
 * "For edmp(irq0) interface, Indicates if status register (ISR) for accel data ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 *
 */
#define REG_ISR_0_7_INT_STATUS_ACCEL_DRDY_PIN_0_POS      0x00
#define REG_ISR_0_7_INT_STATUS_ACCEL_DRDY_PIN_0_MASK     0x01

/*
 * int_status_gyro_drdy_pin_0
 *
 * "For edmp(irq0) interface, Indicates if status register (ISR) for gyro data ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_0_7_INT_STATUS_GYRO_DRDY_PIN_0_POS      0x01
#define REG_ISR_0_7_INT_STATUS_GYRO_DRDY_PIN_0_MASK     (0x01 << REG_ISR_0_7_INT_STATUS_GYRO_DRDY_PIN_0_POS)

/*
 * int_status_ext_int_drdy_pin_0
 *
 * "For edmp(irq0) interface, Indicates if status register (ISR) for drdy from external ext_int input interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_0_7_INT_STATUS_EXT_INT_DRDY_PIN_0_POS      0x02
#define REG_ISR_0_7_INT_STATUS_EXT_INT_DRDY_PIN_0_MASK     (0x01 << REG_ISR_0_7_INT_STATUS_EXT_INT_DRDY_PIN_0_POS)

/*
 * int_status_ext_odr_drdy_pin_0
 *
 * "For edmp(irq0) interface, Indicates if status register (ISR) for ext_odr event interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_0_7_INT_STATUS_EXT_ODR_DRDY_PIN_0_POS      0x03
#define REG_ISR_0_7_INT_STATUS_EXT_ODR_DRDY_PIN_0_MASK     (0x01 << REG_ISR_0_7_INT_STATUS_EXT_ODR_DRDY_PIN_0_POS)

/*
 * int_status_wom_drdy_pin_0
 *
 * "For edmp(irq0) interface, Indicates if status register (ISR) for Wake On Motion event ORing of X, Y, and Z axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_0_7_INT_STATUS_WOM_DRDY_PIN_0_POS      0x04
#define REG_ISR_0_7_INT_STATUS_WOM_DRDY_PIN_0_MASK     (0x01 << REG_ISR_0_7_INT_STATUS_WOM_DRDY_PIN_0_POS)

/*
 * int_status_on_demand_pin_0
 *
 * "For edmp(irq0) interface, Indicates if status register (ISR) for on demand interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_0_7_INT_STATUS_ON_DEMAND_PIN_0_POS      0x05
#define REG_ISR_0_7_INT_STATUS_ON_DEMAND_PIN_0_MASK     (0x01 << REG_ISR_0_7_INT_STATUS_ON_DEMAND_PIN_0_POS)



/*
 * REG_ISR_8_15
 * Register Name : ISR_8_15
 */

/*
 * int_status_accel_drdy_pin_1
 *
 * "For edmp(irq1) interface, Indicates if status register (ISR) for accel data ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 *
 */
#define REG_ISR_8_15_INT_STATUS_ACCEL_DRDY_PIN_1_POS      0x00
#define REG_ISR_8_15_INT_STATUS_ACCEL_DRDY_PIN_1_MASK     0x01

/*
 * int_status_gyro_drdy_pin_1
 *
 * "For edmp(irq1) interface, Indicates if status register (ISR) for gyro data ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_8_15_INT_STATUS_GYRO_DRDY_PIN_1_POS      0x01
#define REG_ISR_8_15_INT_STATUS_GYRO_DRDY_PIN_1_MASK     (0x01 << REG_ISR_8_15_INT_STATUS_GYRO_DRDY_PIN_1_POS)

/*
 * int_status_ext_int_drdy_pin_1
 *
 * "For edmp(irq1) interface, Indicates if status register (ISR) for drdy from external ext_int input interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_8_15_INT_STATUS_EXT_INT_DRDY_PIN_1_POS      0x02
#define REG_ISR_8_15_INT_STATUS_EXT_INT_DRDY_PIN_1_MASK     (0x01 << REG_ISR_8_15_INT_STATUS_EXT_INT_DRDY_PIN_1_POS)

/*
 * int_status_ext_odr_drdy_pin_1
 *
 * "For edmp(irq1) interface, Indicates if status register (ISR) for ext_odr event interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_8_15_INT_STATUS_EXT_ODR_DRDY_PIN_1_POS      0x03
#define REG_ISR_8_15_INT_STATUS_EXT_ODR_DRDY_PIN_1_MASK     (0x01 << REG_ISR_8_15_INT_STATUS_EXT_ODR_DRDY_PIN_1_POS)

/*
 * int_status_wom_drdy_pin_1
 *
 * "For edmp(irq1) interface, Indicates if status register (ISR) for Wake On Motion event ORing of X, Y, and Z axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_8_15_INT_STATUS_WOM_DRDY_PIN_1_POS      0x04
#define REG_ISR_8_15_INT_STATUS_WOM_DRDY_PIN_1_MASK     (0x01 << REG_ISR_8_15_INT_STATUS_WOM_DRDY_PIN_1_POS)

/*
 * int_status_on_demand_pin_1
 *
 * "For edmp(irq1) interface, Indicates if status register (ISR) for on demand interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_8_15_INT_STATUS_ON_DEMAND_PIN_1_POS      0x05
#define REG_ISR_8_15_INT_STATUS_ON_DEMAND_PIN_1_MASK     (0x01 << REG_ISR_8_15_INT_STATUS_ON_DEMAND_PIN_1_POS)



/*
 * REG_ISR_16_23
 * Register Name : ISR_16_23
 */

/*
 * int_status_accel_drdy_pin_2
 *
 * "For edmp(irq2) interface, Indicates if status register (ISR) for accel data ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 *
 */
#define REG_ISR_16_23_INT_STATUS_ACCEL_DRDY_PIN_2_POS      0x00
#define REG_ISR_16_23_INT_STATUS_ACCEL_DRDY_PIN_2_MASK     0x01

/*
 * int_status_gyro_drdy_pin_2
 *
 * "For edmp(irq2) interface, Indicates if status register (ISR) for gyro data ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_16_23_INT_STATUS_GYRO_DRDY_PIN_2_POS      0x01
#define REG_ISR_16_23_INT_STATUS_GYRO_DRDY_PIN_2_MASK     (0x01 << REG_ISR_16_23_INT_STATUS_GYRO_DRDY_PIN_2_POS)

/*
 * int_status_ext_int_drdy_pin_2
 *
 * "For edmp(irq2) interface, Indicates if status register (ISR) for drdy from external ext_int input interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_16_23_INT_STATUS_EXT_INT_DRDY_PIN_2_POS      0x02
#define REG_ISR_16_23_INT_STATUS_EXT_INT_DRDY_PIN_2_MASK     (0x01 << REG_ISR_16_23_INT_STATUS_EXT_INT_DRDY_PIN_2_POS)

/*
 * int_status_ext_odr_drdy_pin_2
 *
 * "For edmp(irq2) interface, Indicates if status register (ISR) for ext_odr event interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_16_23_INT_STATUS_EXT_ODR_DRDY_PIN_2_POS      0x03
#define REG_ISR_16_23_INT_STATUS_EXT_ODR_DRDY_PIN_2_MASK     (0x01 << REG_ISR_16_23_INT_STATUS_EXT_ODR_DRDY_PIN_2_POS)

/*
 * int_status_wom_drdy_pin_2
 *
 * "For edmp(irq2) interface, Indicates if status register (ISR) for Wake On Motion event ORing of X, Y, and Z axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_16_23_INT_STATUS_WOM_DRDY_PIN_2_POS      0x04
#define REG_ISR_16_23_INT_STATUS_WOM_DRDY_PIN_2_MASK     (0x01 << REG_ISR_16_23_INT_STATUS_WOM_DRDY_PIN_2_POS)

/*
 * int_status_on_demand_pin_2
 *
 * "For edmp(irq2) interface, Indicates if status register (ISR) for on demand interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set."
 *
 */
#define REG_ISR_16_23_INT_STATUS_ON_DEMAND_PIN_2_POS      0x05
#define REG_ISR_16_23_INT_STATUS_ON_DEMAND_PIN_2_MASK     (0x01 << REG_ISR_16_23_INT_STATUS_ON_DEMAND_PIN_2_POS)



/*
 * REG_STATUS_MASK_PIN_0_7
 * Register Name : STATUS_MASK_PIN_0_7
 */

/*
 * int_accel_drdy_pin_0_dis
 * For edmp(irq0) interface, Indicates accel data ready masking bit  for irq0 line
 * "For UI/AP interface, Indicates if FIFO full interrupt is masked,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_0_7_INT_ACCEL_DRDY_PIN_0_DIS_POS      0x00
#define REG_STATUS_MASK_PIN_0_7_INT_ACCEL_DRDY_PIN_0_DIS_MASK     0x01

/*
 * int_gyro_drdy_pin_0_dis
 *
 * For edmp(irq0) interface, Indicates gyro data ready masking bit  for irq0 line
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_0_7_INT_GYRO_DRDY_PIN_0_DIS_POS      0x01
#define REG_STATUS_MASK_PIN_0_7_INT_GYRO_DRDY_PIN_0_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_0_7_INT_GYRO_DRDY_PIN_0_DIS_POS)

/*
 * int_ext_int_drdy_pin_0_dis
 *
 * "For edmp(irq0) interface, Indicates Ext_drdy from external ext_int input masking bit for irq0 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_0_7_INT_EXT_INT_DRDY_PIN_0_DIS_POS      0x02
#define REG_STATUS_MASK_PIN_0_7_INT_EXT_INT_DRDY_PIN_0_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_0_7_INT_EXT_INT_DRDY_PIN_0_DIS_POS)

/*
 * int_ext_odr_drdy_pin_0_dis
 *
 * "For edmp(irq0) interface, Indicates Ext_drdy from internal ext_odr event masking bit for irq0 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_0_7_INT_EXT_ODR_DRDY_PIN_0_DIS_POS      0x03
#define REG_STATUS_MASK_PIN_0_7_INT_EXT_ODR_DRDY_PIN_0_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_0_7_INT_EXT_ODR_DRDY_PIN_0_DIS_POS)

/*
 * int_wom_drdy_pin_0_dis
 * –
 * "For edmp(irq0) interface, Indicates Wake On Motion event ORing of X, Y, and Z axis masking bit for irq0 line
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_0_7_INT_WOM_DRDY_PIN_0_DIS_POS      0x04
#define REG_STATUS_MASK_PIN_0_7_INT_WOM_DRDY_PIN_0_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_0_7_INT_WOM_DRDY_PIN_0_DIS_POS)

/*
 * int_on_demand_pin_0_dis
 *
 * "For edmp(irq0) interface, Indicates on demand masking bit for irq0 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_0_7_INT_ON_DEMAND_PIN_0_DIS_POS      0x05
#define REG_STATUS_MASK_PIN_0_7_INT_ON_DEMAND_PIN_0_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_0_7_INT_ON_DEMAND_PIN_0_DIS_POS)



/*
 * REG_STATUS_MASK_PIN_8_15
 * Register Name : STATUS_MASK_PIN_8_15
 */

/*
 * int_accel_drdy_pin_1_dis
 * For edmp(irq1) interface, Indicates accel data ready masking bit  for irq1 line
 * "For UI/AP interface, Indicates if FIFO full interrupt is masked,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_8_15_INT_ACCEL_DRDY_PIN_1_DIS_POS      0x00
#define REG_STATUS_MASK_PIN_8_15_INT_ACCEL_DRDY_PIN_1_DIS_MASK     0x01

/*
 * int_gyro_drdy_pin_1_dis
 *
 * For edmp(irq1) interface, Indicates gyro data ready masking bit  for irq1 line
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_8_15_INT_GYRO_DRDY_PIN_1_DIS_POS      0x01
#define REG_STATUS_MASK_PIN_8_15_INT_GYRO_DRDY_PIN_1_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_8_15_INT_GYRO_DRDY_PIN_1_DIS_POS)

/*
 * int_ext_int_drdy_pin_1_dis
 *
 * "For edmp(irq1) interface, Indicates Ext_drdy from external ext_int input masking bit for irq1 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_8_15_INT_EXT_INT_DRDY_PIN_1_DIS_POS      0x02
#define REG_STATUS_MASK_PIN_8_15_INT_EXT_INT_DRDY_PIN_1_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_8_15_INT_EXT_INT_DRDY_PIN_1_DIS_POS)

/*
 * int_ext_odr_drdy_pin_1_dis
 *
 * "For edmp(irq1) interface, Indicates Ext_drdy from internal ext_odr event masking bit for irq1 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_8_15_INT_EXT_ODR_DRDY_PIN_1_DIS_POS      0x03
#define REG_STATUS_MASK_PIN_8_15_INT_EXT_ODR_DRDY_PIN_1_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_8_15_INT_EXT_ODR_DRDY_PIN_1_DIS_POS)

/*
 * int_wom_drdy_pin_1_dis
 * –
 * "For edmp(irq1) interface, Indicates Wake On Motion event ORing of X, Y, and Z axis masking bit for irq1 line
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_8_15_INT_WOM_DRDY_PIN_1_DIS_POS      0x04
#define REG_STATUS_MASK_PIN_8_15_INT_WOM_DRDY_PIN_1_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_8_15_INT_WOM_DRDY_PIN_1_DIS_POS)

/*
 * int_on_demand_pin_1_dis
 *
 * "For edmp(irq1) interface, Indicates on demand masking bit for irq1 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_8_15_INT_ON_DEMAND_PIN_1_DIS_POS      0x05
#define REG_STATUS_MASK_PIN_8_15_INT_ON_DEMAND_PIN_1_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_8_15_INT_ON_DEMAND_PIN_1_DIS_POS)



/*
 * REG_STATUS_MASK_PIN_16_23
 * Register Name : STATUS_MASK_PIN_16_23
 */

/*
 * int_accel_drdy_pin_2_dis
 * For edmp(irq2) interface, Indicates accel data ready masking bit  for irq2 line
 * "For UI/AP interface, Indicates if FIFO full interrupt is masked,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_16_23_INT_ACCEL_DRDY_PIN_2_DIS_POS      0x00
#define REG_STATUS_MASK_PIN_16_23_INT_ACCEL_DRDY_PIN_2_DIS_MASK     0x01

/*
 * int_gyro_drdy_pin_2_dis
 *
 * For edmp(irq2) interface, Indicates gyro data ready masking bit  for irq2 line
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_16_23_INT_GYRO_DRDY_PIN_2_DIS_POS      0x01
#define REG_STATUS_MASK_PIN_16_23_INT_GYRO_DRDY_PIN_2_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_16_23_INT_GYRO_DRDY_PIN_2_DIS_POS)

/*
 * int_ext_int_drdy_pin_2_dis
 *
 * "For edmp(irq2) interface, Indicates Ext_drdy from external ext_int input masking bit for irq2 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_16_23_INT_EXT_INT_DRDY_PIN_2_DIS_POS      0x02
#define REG_STATUS_MASK_PIN_16_23_INT_EXT_INT_DRDY_PIN_2_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_16_23_INT_EXT_INT_DRDY_PIN_2_DIS_POS)

/*
 * int_ext_odr_drdy_pin_2_dis
 *
 * "For edmp(irq2) interface, Indicates Ext_drdy from internal ext_odr event masking bit for irq2 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_16_23_INT_EXT_ODR_DRDY_PIN_2_DIS_POS      0x03
#define REG_STATUS_MASK_PIN_16_23_INT_EXT_ODR_DRDY_PIN_2_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_16_23_INT_EXT_ODR_DRDY_PIN_2_DIS_POS)

/*
 * int_wom_drdy_pin_2_dis
 * –
 * "For edmp(irq2) interface, Indicates Wake On Motion event ORing of X, Y, and Z axis masking bit for irq2 line
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_16_23_INT_WOM_DRDY_PIN_2_DIS_POS      0x04
#define REG_STATUS_MASK_PIN_16_23_INT_WOM_DRDY_PIN_2_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_16_23_INT_WOM_DRDY_PIN_2_DIS_POS)

/*
 * int_on_demand_pin_2_dis
 *
 * "For edmp(irq2) interface, Indicates on demand masking bit for irq2 line,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_STATUS_MASK_PIN_16_23_INT_ON_DEMAND_PIN_2_DIS_POS      0x05
#define REG_STATUS_MASK_PIN_16_23_INT_ON_DEMAND_PIN_2_DIS_MASK     (0x01 << REG_STATUS_MASK_PIN_16_23_INT_ON_DEMAND_PIN_2_DIS_POS)



/*
 * REG_INT_I2CM_SOURCE
 * Register Name : INT_I2CM_SOURCE
 */

/*
 * int_status_i2cm_ioc_ext_trig_en
 * "For i2cm interface, ioc_ext_trg source event enable bit.
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).   "
 *
 */
#define REG_INT_I2CM_SOURCE_INT_STATUS_I2CM_IOC_EXT_TRIG_EN_POS      0x00
#define REG_INT_I2CM_SOURCE_INT_STATUS_I2CM_IOC_EXT_TRIG_EN_MASK     0x01

/*
 * int_status_i2cm_smc_ext_odr_en
 * "For i2cm interface, smc_ext_odr source event enable bit.
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).   "
 *
 */
#define REG_INT_I2CM_SOURCE_INT_STATUS_I2CM_SMC_EXT_ODR_EN_POS      0x01
#define REG_INT_I2CM_SOURCE_INT_STATUS_I2CM_SMC_EXT_ODR_EN_MASK     (0x01 << REG_INT_I2CM_SOURCE_INT_STATUS_I2CM_SMC_EXT_ODR_EN_POS)



/*
 * REG_PSEQ_STATUS
 * Register Name : PSEQ_STATUS
 */

/*
 * sw_pwr_rdy
 * Switchable domain ready status
 */
#define REG_PSEQ_STATUS_SW_PWR_RDY_POS      0x00
#define REG_PSEQ_STATUS_SW_PWR_RDY_MASK     0x01



/*
 * REG_ACCEL_WOM_X_THR
 * Register Name : ACCEL_WOM_X_THR
 */

/*
 * wom_x_th
 * WoM thresholds are expressed in fixed “mg” independently of the selected full-scale (format <U,8,0>, range [0g : 1g], resolution 1g/256=~4mg).
 */
#define REG_ACCEL_WOM_X_THR_WOM_X_TH_POS      0x00
#define REG_ACCEL_WOM_X_THR_WOM_X_TH_MASK     0xff



/*
 * REG_ACCEL_WOM_Y_THR
 * Register Name : ACCEL_WOM_Y_THR
 */

/*
 * wom_y_th
 * WoM thresholds are expressed in fixed “mg” independently of the selected full-scale (format <U,8,0>, range [0g : 1g], resolution 1g/256=~4mg).
 */
#define REG_ACCEL_WOM_Y_THR_WOM_Y_TH_POS      0x00
#define REG_ACCEL_WOM_Y_THR_WOM_Y_TH_MASK     0xff



/*
 * REG_ACCEL_WOM_Z_THR
 * Register Name : ACCEL_WOM_Z_THR
 */

/*
 * wom_z_th
 * WoM thresholds are expressed in fixed “mg” independently of the selected full-scale (format <U,8,0>, range [0g : 1g], resolution 1g/256=~4mg).
 */
#define REG_ACCEL_WOM_Z_THR_WOM_Z_TH_POS      0x00
#define REG_ACCEL_WOM_Z_THR_WOM_Z_TH_MASK     0xff



/*
 * REG_CKGA_CONFIG
 * Register Name : CKGA_CONFIG
 */

/*
 * sel_freq_clk_gyro_pll_ref_29k
 * Selects the frequency of the Gyro PLL refclk:
 * 0: 30.72kHz (200 divider ratio)
 * 1: 29.26kHz (210 divider ratio)
 * 2: 27.93kHz (220 divider ratio)
 * 3: 26.71kHz (230 divider ratio)
 */
#define REG_CKGA_CONFIG_SEL_FREQ_CLK_GYRO_PLL_REF_29K_POS      0x02
#define REG_CKGA_CONFIG_SEL_FREQ_CLK_GYRO_PLL_REF_29K_MASK     (0x03 << REG_CKGA_CONFIG_SEL_FREQ_CLK_GYRO_PLL_REF_29K_POS)



/*
 * REG_IREG_OTP_CFG
 * Register Name : IREG_OTP_CFG
 */

/*
 * otp_copy_mode
 * OTP Copy mode:
 * 0 : No Otp Copy
 * 1 : Otp Copy bank0 and bank1/2
 * 2: Reserved
 * 3 : Copy self-test
 */
#define REG_IREG_OTP_CFG_OTP_COPY_MODE_POS      0x00
#define REG_IREG_OTP_CFG_OTP_COPY_MODE_MASK     0x03



/*
 * REG_OTP_CONFIG0
 * Register Name : OTP_CONFIG0
 */

/*
 * crcerrpro_disable
 * When otp_crc_error = 1, some registers are forced to power-on default value, not the values from OTP memory.
 * This signal (when value is 1) is to remove the force operation due to otp_crc_error = 1.
 * This signal has no effect if otp_crc_error = 0.
 */
#define REG_OTP_CONFIG0_CRCERRPRO_DISABLE_POS      0x00
#define REG_OTP_CONFIG0_CRCERRPRO_DISABLE_MASK     0x01



/*
 * REG_HEAT_CTRL2
 * Register Name : HEAT_CTRL2
 */

/*
 * pd_heater_ana_b
 * When 0 it forces power down of analog heater circuitry. Digital control is still active. Used for debug purposes.
 */
#define REG_HEAT_CTRL2_PD_HEATER_ANA_B_POS      0x00
#define REG_HEAT_CTRL2_PD_HEATER_ANA_B_MASK     0x01



/*
 * REG_SELFTEST
 * Register Name : SELFTEST
 */

/*
 * en_ax_st
 * [Supports Dynamic Change] Enable AX selftest
 */
#define REG_SELFTEST_EN_AX_ST_POS      0x00
#define REG_SELFTEST_EN_AX_ST_MASK     0x01

/*
 * en_ay_st
 * [Supports Dynamic Change] Enable AY selftest
 */
#define REG_SELFTEST_EN_AY_ST_POS      0x01
#define REG_SELFTEST_EN_AY_ST_MASK     (0x01 << REG_SELFTEST_EN_AY_ST_POS)

/*
 * en_az_st
 * [Supports Dynamic Change] Enable AZ selftest
 */
#define REG_SELFTEST_EN_AZ_ST_POS      0x02
#define REG_SELFTEST_EN_AZ_ST_MASK     (0x01 << REG_SELFTEST_EN_AZ_ST_POS)

/*
 * en_gx_st
 * [Supports Dynamic Change] Gyro x self test pin enable
 * 0: The self test electrode is biased for gyro operation
 * 1: The self test electrode is connected to the self test signal source
 */
#define REG_SELFTEST_EN_GX_ST_POS      0x03
#define REG_SELFTEST_EN_GX_ST_MASK     (0x01 << REG_SELFTEST_EN_GX_ST_POS)

/*
 * en_gy_st
 * [Supports Dynamic Change] Gyro y self test pin enable
 * 0: The self test electrode is biased for gyro operation
 * 1: The self test electrode is connected to the self test signal source
 */
#define REG_SELFTEST_EN_GY_ST_POS      0x04
#define REG_SELFTEST_EN_GY_ST_MASK     (0x01 << REG_SELFTEST_EN_GY_ST_POS)

/*
 * en_gz_st
 * [Supports Dynamic Change] Gyro z self test pin enable
 * 0: The self test electrode is biased for gyro operation
 * 1: The self test electrode is connected to the self test signal source
 */
#define REG_SELFTEST_EN_GZ_ST_POS      0x05
#define REG_SELFTEST_EN_GZ_ST_MASK     (0x01 << REG_SELFTEST_EN_GZ_ST_POS)



/*
 * REG_IPREG_MISC
 * Register Name : IPREG_MISC
 */

/*
 * edmp_idle
 * 1: Indicates eDMP is idle
 * 0 : Indicates eDMP is busy
 */
#define REG_IPREG_MISC_EDMP_IDLE_POS      0x01
#define REG_IPREG_MISC_EDMP_IDLE_MASK     (0x01 << REG_IPREG_MISC_EDMP_IDLE_POS)

/*
 * REG_SW_RCOSC1_TRIM
 * Register Name : SW_RCOSC1_TRIM
 */

/*
 * sw_rcosc1_trim
 * Stores variation of RCOSC frequency test measurement vs. target value, used for SW applications. Value to trim = (RCOSC_measurement – 6400Hz) / 6400Hz * 2540. 6400Hz is the target divided-down RCOSC freq. 2540 is the resolution coefficient: max register range / max oscillator frequency error = (2^7 - 1) / 5%, with a sign bit.
 */
#define REG_SW_RCOSC1_TRIM_SW_RCOSC1_TRIM_POS      0x00
#define REG_SW_RCOSC1_TRIM_SW_RCOSC1_TRIM_MASK     0xff



/*
 * REG_SW_PLL1_TRIM
 * Register Name : SW_PLL1_TRIM
 */

/*
 * sw_pll1_trim
 * Stores variation of PLL frequency test measurement vs. target value, used for SW applications. Value to trim =(PLL_measurement – 6144000Hz) / 6144000Hz * 2540. 6144000Hz is the target PLL freq. 2540 is the resolution coefficient: max register range / max oscillator frequency error = (2^7 - 1) / 5%, with a sign bit.
 */
#define REG_SW_PLL1_TRIM_SW_PLL1_TRIM_POS      0x00
#define REG_SW_PLL1_TRIM_SW_PLL1_TRIM_MASK     0xff



/*
 * REG_FIFO_SRAM_SLEEP
 * Register Name : FIFO_SRAM_SLEEP
 */

/*
 * fifo_gsleep_shared_sram
 * Set selected SRAM bank global sleep mode (pwr_gsleep)
 *
 * 0: selected SRAM bank sleep mode is controlled by PSEQ, ps_fifo_gsleep_fifo_sram, if this bank contains FIFO data. Otherwise SRAM is in sleep  mode (SRAM bank pwr_gsleep=1).
 *
 * 1: selected SRAM bank remains in active mode (pwr_gsleep=0).
 *
 * Can be changed when FIFO is disabled (Bypass mode), AHB interface idle.
 */
#define REG_FIFO_SRAM_SLEEP_FIFO_GSLEEP_SHARED_SRAM_POS      0x00
#define REG_FIFO_SRAM_SLEEP_FIFO_GSLEEP_SHARED_SRAM_MASK     0x03



/*
 * REG_FIFO_SRAM_RET
 * Register Name : FIFO_SRAM_RET
 */

/*
 * fifo_retention_shared_sram
 * Set selected SRAM bank in light sleep mode (pwr_lv)
 *
 * 0: selected SRAM bank is in active mode (SRAM bank pwr_lv=1)
 * 1: selected SRAM bank is in light sleep mode (pwr_lv=0)
 *
 * Can be changed when FIFO is disabled (Bypass mode), AHB interface idle.
 */
#define REG_FIFO_SRAM_RET_FIFO_RETENTION_SHARED_SRAM_POS      0x00
#define REG_FIFO_SRAM_RET_FIFO_RETENTION_SHARED_SRAM_MASK     0x03



/*
 * REG_EDMP_SGI_0
 * Register Name : EDMP_SGI_0
 */

/*
 * sgi
 * [Supports Dynamic Change] Edmp can write to cause an interrupt to host.  Read will always return 0.  Bit 0: Tap DetectBit 1: HighG DetectBit 2: LowG DetectBit 3: Tilt DetectBit 4: Step Count OverflowBit 5: Step DetectBit 6: Freefall DetectBit 7: Raise to Wake Wake DetectBit 8: Raise to Wake Sleep DetectBit 9: SMD DetectBit 10: Self-Test doneBit 11: Self-Cal doneBit 12: Secure Authentication doneBit 13: ReservedBit 14: ReservedBit 15: Reserved..
 */
#define REG_EDMP_SGI_0_SGI_POS      0x00
#define REG_EDMP_SGI_0_SGI_MASK     0xff



/*
 * REG_EDMP_SGI_1
 * Register Name : EDMP_SGI_1
 */

/*
 * sgi
 * [Supports Dynamic Change] Edmp can write to cause an interrupt to host.  Read will always return 0.  Bit 0: Tap DetectBit 1: HighG DetectBit 2: LowG DetectBit 3: Tilt DetectBit 4: Step Count OverflowBit 5: Step DetectBit 6: Freefall DetectBit 7: Raise to Wake Wake DetectBit 8: Raise to Wake Sleep DetectBit 9: SMD DetectBit 10: Self-Test doneBit 11: Self-Cal doneBit 12: Secure Authentication doneBit 13: ReservedBit 14: ReservedBit 15: Reserved..
 */
#define REG_EDMP_SGI_1_SGI_POS      0x00
#define REG_EDMP_SGI_1_SGI_MASK     0x7f


/* ---------------------------------------------------------------------------
 * register DREG_BANK1
 * ---------------------------------------------------------------------------*/

/*
 * REG_ACCEL_DATA_X_0
 * Register Name : ACCEL_DATA_X_0
 */

/*
 * accel_data_x_ap
 * Accel X axis data for UI/AP path
 */
#define REG_ACCEL_DATA_X_0_ACCEL_DATA_X_AP_POS      0x00
#define REG_ACCEL_DATA_X_0_ACCEL_DATA_X_AP_MASK     0xff



/*
 * REG_ACCEL_DATA_X_1
 * Register Name : ACCEL_DATA_X_1
 */

/*
 * accel_data_x_ap
 * Accel X axis data for UI/AP path
 */
#define REG_ACCEL_DATA_X_1_ACCEL_DATA_X_AP_POS      0x00
#define REG_ACCEL_DATA_X_1_ACCEL_DATA_X_AP_MASK     0xff



/*
 * REG_ACCEL_DATA_Y_0
 * Register Name : ACCEL_DATA_Y_0
 */

/*
 * accel_data_y_ap
 * Accel Y axis data for UI/AP path
 */
#define REG_ACCEL_DATA_Y_0_ACCEL_DATA_Y_AP_POS      0x00
#define REG_ACCEL_DATA_Y_0_ACCEL_DATA_Y_AP_MASK     0xff



/*
 * REG_ACCEL_DATA_Y_1
 * Register Name : ACCEL_DATA_Y_1
 */

/*
 * accel_data_y_ap
 * Accel Y axis data for UI/AP path
 */
#define REG_ACCEL_DATA_Y_1_ACCEL_DATA_Y_AP_POS      0x00
#define REG_ACCEL_DATA_Y_1_ACCEL_DATA_Y_AP_MASK     0xff



/*
 * REG_ACCEL_DATA_Z_0
 * Register Name : ACCEL_DATA_Z_0
 */

/*
 * accel_data_z_ap
 * Accel Z axis data for UI/AP path
 */
#define REG_ACCEL_DATA_Z_0_ACCEL_DATA_Z_AP_POS      0x00
#define REG_ACCEL_DATA_Z_0_ACCEL_DATA_Z_AP_MASK     0xff



/*
 * REG_ACCEL_DATA_Z_1
 * Register Name : ACCEL_DATA_Z_1
 */

/*
 * accel_data_z_ap
 * Accel Z axis data for UI/AP path
 */
#define REG_ACCEL_DATA_Z_1_ACCEL_DATA_Z_AP_POS      0x00
#define REG_ACCEL_DATA_Z_1_ACCEL_DATA_Z_AP_MASK     0xff



/*
 * REG_GYRO_DATA_X_0
 * Register Name : GYRO_DATA_X_0
 */

/*
 * gyro_data_x_ap
 * Gyro X axis data for UI/AP path
 */
#define REG_GYRO_DATA_X_0_GYRO_DATA_X_AP_POS      0x00
#define REG_GYRO_DATA_X_0_GYRO_DATA_X_AP_MASK     0xff



/*
 * REG_GYRO_DATA_X_1
 * Register Name : GYRO_DATA_X_1
 */

/*
 * gyro_data_x_ap
 * Gyro X axis data for UI/AP path
 */
#define REG_GYRO_DATA_X_1_GYRO_DATA_X_AP_POS      0x00
#define REG_GYRO_DATA_X_1_GYRO_DATA_X_AP_MASK     0xff



/*
 * REG_GYRO_DATA_Y_0
 * Register Name : GYRO_DATA_Y_0
 */

/*
 * gyro_data_y_ap
 * Gyro Y axis data for UI/AP path
 */
#define REG_GYRO_DATA_Y_0_GYRO_DATA_Y_AP_POS      0x00
#define REG_GYRO_DATA_Y_0_GYRO_DATA_Y_AP_MASK     0xff



/*
 * REG_GYRO_DATA_Y_1
 * Register Name : GYRO_DATA_Y_1
 */

/*
 * gyro_data_y_ap
 * Gyro Y axis data for UI/AP path
 */
#define REG_GYRO_DATA_Y_1_GYRO_DATA_Y_AP_POS      0x00
#define REG_GYRO_DATA_Y_1_GYRO_DATA_Y_AP_MASK     0xff



/*
 * REG_GYRO_DATA_Z_0
 * Register Name : GYRO_DATA_Z_0
 */

/*
 * gyro_data_z_ap
 * Gyro Z axis data for UI/AP path
 */
#define REG_GYRO_DATA_Z_0_GYRO_DATA_Z_AP_POS      0x00
#define REG_GYRO_DATA_Z_0_GYRO_DATA_Z_AP_MASK     0xff



/*
 * REG_GYRO_DATA_Z_1
 * Register Name : GYRO_DATA_Z_1
 */

/*
 * gyro_data_z_ap
 * Gyro Z axis data for UI/AP path
 */
#define REG_GYRO_DATA_Z_1_GYRO_DATA_Z_AP_POS      0x00
#define REG_GYRO_DATA_Z_1_GYRO_DATA_Z_AP_MASK     0xff



/*
 * REG_TEMP_DATA_0
 * Register Name : TEMP_DATA_0
 */

/*
 * temp_data_ap
 * Temperature data for UI/AP path
 */
#define REG_TEMP_DATA_0_TEMP_DATA_AP_POS      0x00
#define REG_TEMP_DATA_0_TEMP_DATA_AP_MASK     0xff



/*
 * REG_TEMP_DATA_1
 * Register Name : TEMP_DATA_1
 */

/*
 * temp_data_ap
 * Temperature data for UI/AP path
 */
#define REG_TEMP_DATA_1_TEMP_DATA_AP_POS      0x00
#define REG_TEMP_DATA_1_TEMP_DATA_AP_MASK     0xff



/*
 * REG_TMST_FSYNC_DATA_0
 * Register Name : TMST_FSYNC_DATA_0
 */

/*
 * tmst_fsync_data_ap
 * Timestamp/FSYNC data for UI/AP path
 */
#define REG_TMST_FSYNC_DATA_0_TMST_FSYNC_DATA_AP_POS      0x00
#define REG_TMST_FSYNC_DATA_0_TMST_FSYNC_DATA_AP_MASK     0xff



/*
 * REG_TMST_FSYNC_DATA_1
 * Register Name : TMST_FSYNC_DATA_1
 */

/*
 * tmst_fsync_data_ap
 * Timestamp/FSYNC data for UI/AP path
 */
#define REG_TMST_FSYNC_DATA_1_TMST_FSYNC_DATA_AP_POS      0x00
#define REG_TMST_FSYNC_DATA_1_TMST_FSYNC_DATA_AP_MASK     0xff



/*
 * REG_PWR_MGMT0
 * Register Name : PWR_MGMT0
 */

/*
 * accel_mode
 * [Supports Dynamic Change] Accelerometer Power-Mode for the UI/AP FIFO:
 *   00: OFF
 *   01: OFF
 *   10: LP
 *   11: LN
 */
#define REG_PWR_MGMT0_ACCEL_MODE_POS      0x00
#define REG_PWR_MGMT0_ACCEL_MODE_MASK     0x03

/*
 * gyro_mode
 * [Supports Dynamic Change] Gyroscope Power-Mode for the UI/AP FIFO:
 *   00: OFF
 *   01: STANDBY
 *   10: LP
 *   11: LN
 */
#define REG_PWR_MGMT0_GYRO_MODE_POS      0x02
#define REG_PWR_MGMT0_GYRO_MODE_MASK     (0x03 << REG_PWR_MGMT0_GYRO_MODE_POS)

/*
 * accel_vre_sel
 * [Supports Dynamic Change] Determines the analog full-scale when user full-scale <=8g
 * 0: 8g (improved noise perf)
 * 1: 16g (improved vre perf)
 */
#define REG_PWR_MGMT0_ACCEL_VRE_SEL_POS      0x04
#define REG_PWR_MGMT0_ACCEL_VRE_SEL_MASK     (0x01 << REG_PWR_MGMT0_ACCEL_VRE_SEL_POS)



/*
 * REG_PWR_MGMT1
 * Register Name : PWR_MGMT1
 */

/*
 * accel_ui_status_conf_invalid
 * Asserted if an invalid configuration is detected at the UI/AP interface of the Accelerometer sensor.
 */
#define REG_PWR_MGMT1_ACCEL_UI_STATUS_CONF_INVALID_POS      0x00
#define REG_PWR_MGMT1_ACCEL_UI_STATUS_CONF_INVALID_MASK     0x01

/*
 * gyro_ui_status_conf_invalid
 * Asserted if an invalid configuration is detected at the UI/AP interface of the Gyroscope sensor.
 */
#define REG_PWR_MGMT1_GYRO_UI_STATUS_CONF_INVALID_POS      0x01
#define REG_PWR_MGMT1_GYRO_UI_STATUS_CONF_INVALID_MASK     (0x01 << REG_PWR_MGMT1_GYRO_UI_STATUS_CONF_INVALID_POS)

/*
 * accel_ui_status_pm
 * Accelerometer Power-Mode status for the UI/AP FIFO
 */
#define REG_PWR_MGMT1_ACCEL_UI_STATUS_PM_POS      0x02
#define REG_PWR_MGMT1_ACCEL_UI_STATUS_PM_MASK     (0x03 << REG_PWR_MGMT1_ACCEL_UI_STATUS_PM_POS)

/*
 * gyro_ui_status_pm
 * Gyroscope Power-Mode status for the UI/AP FIFO
 */
#define REG_PWR_MGMT1_GYRO_UI_STATUS_PM_POS      0x04
#define REG_PWR_MGMT1_GYRO_UI_STATUS_PM_MASK     (0x03 << REG_PWR_MGMT1_GYRO_UI_STATUS_PM_POS)



/*
 * REG_FIFO_COUNT_0
 * Register Name : FIFO_COUNT_0
 */

/*
 * fifo_data_cnt
 * [Supports Dynamic Change] FIFO data counter. It returns the number of unread frames inside the FIFO.
 * Can be read anytime.
 * For the case of a 16 bit FIFO data count, this register must be read in one 2-byte burst, or one hybrid count+data burst. Internally, FIFO locks the count when the data count register is read, so that MSB and LSB bytes are from the same snapshot. The lock is to prevent the count from changing if a new frame was written to FIFO during count read.
 *
 * For SPI serial interface mode: if SPI clock frequency is more than 10 MHz, a minimum tBUF (CS_n=1) of 500ns is needed, in order to correcly read fifo frame count immediately after reading complete data frames.
 */
#define REG_FIFO_COUNT_0_FIFO_DATA_CNT_POS      0x00
#define REG_FIFO_COUNT_0_FIFO_DATA_CNT_MASK     0xff



/*
 * REG_FIFO_COUNT_1
 * Register Name : FIFO_COUNT_1
 */

/*
 * fifo_data_cnt
 * [Supports Dynamic Change] FIFO data counter. It returns the number of unread frames inside the FIFO.
 * Can be read anytime.
 * For the case of a 16 bit FIFO data count, this register must be read in one 2-byte burst, or one hybrid count+data burst. Internally, FIFO locks the count when the data count register is read, so that MSB and LSB bytes are from the same snapshot. The lock is to prevent the count from changing if a new frame was written to FIFO during count read.
 *
 * For SPI serial interface mode: if SPI clock frequency is more than 10 MHz, a minimum tBUF (CS_n=1) of 500ns is needed, in order to correcly read fifo frame count immediately after reading complete data frames.
 */
#define REG_FIFO_COUNT_1_FIFO_DATA_CNT_POS      0x00
#define REG_FIFO_COUNT_1_FIFO_DATA_CNT_MASK     0xff



/*
 * REG_FIFO_DATA
 * Register Name : FIFO_DATA
 */

/*
 * fifo_rdata
 * FIFO data read by serial interface
 */
#define REG_FIFO_DATA_FIFO_RDATA_POS      0x00
#define REG_FIFO_DATA_FIFO_RDATA_MASK     0xff



/*
 * REG_INT1_CONFIG0
 * Register Name : INT1_CONFIG0
 */

/*
 * int1_status_en_fifo_full
 * For UI/AP interface, source enable register for FIFO full interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).   "
 *
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_FIFO_FULL_POS      0x00
#define REG_INT1_CONFIG0_INT1_STATUS_EN_FIFO_FULL_MASK     0x01

/*
 * int1_status_en_fifo_ths
 * For UI/AP interface, source enable register for FIFO count ≥ FIFO threshold interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_FIFO_THS_POS      0x01
#define REG_INT1_CONFIG0_INT1_STATUS_EN_FIFO_THS_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_FIFO_THS_POS)

/*
 * int1_status_en_drdy
 * For UI/AP interface, source enable register for User Interface Sensor Register Data Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_DRDY_POS      0x02
#define REG_INT1_CONFIG0_INT1_STATUS_EN_DRDY_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_DRDY_POS)

/*
 * int1_status_en_aux1_drdy
 * For UI/AP interface, source enable register for Optical Image Stabilization Interface 1 Sensor Register Data Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AUX1_DRDY_POS      0x03
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AUX1_DRDY_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_AUX1_DRDY_POS)

/*
 * int1_status_en_ap_fsync
 * For UI/AP interface, source enable register for User Interface FSYNC interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AP_FSYNC_POS      0x04
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AP_FSYNC_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_AP_FSYNC_POS)

/*
 * int1_status_en_ap_agc_rdy
 * For UI/AP interface, source enable register for  User Interface AGC Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AP_AGC_RDY_POS      0x05
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AP_AGC_RDY_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_AP_AGC_RDY_POS)

/*
 * int1_status_en_aux1_agc_rdy
 * For UI/AP interface, source enable register for Optical Image Stabilization Interface #1 AGC Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AUX1_AGC_RDY_POS      0x06
#define REG_INT1_CONFIG0_INT1_STATUS_EN_AUX1_AGC_RDY_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_AUX1_AGC_RDY_POS)

/*
 * int1_status_en_reset_done
 * For UI/AP interface, source enable register for  Reset process is finished(after OTP copy is complete, i.e. after OTP_DONE signal)l interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG0_INT1_STATUS_EN_RESET_DONE_POS      0x07
#define REG_INT1_CONFIG0_INT1_STATUS_EN_RESET_DONE_MASK     (0x01 << REG_INT1_CONFIG0_INT1_STATUS_EN_RESET_DONE_POS)



/*
 * REG_INT1_CONFIG1
 * Register Name : INT1_CONFIG1
 */

/*
 * int1_status_en_pll_rdy
 * For UI/AP interface, source enable register for PLL is locked interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 *
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_PLL_RDY_POS      0x00
#define REG_INT1_CONFIG1_INT1_STATUS_EN_PLL_RDY_MASK     0x01

/*
 * int1_status_en_wom_x
 * For UI/AP interface, source enable register for Wake On Motion event on X axis interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_X_POS      0x01
#define REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_X_MASK     (0x01 << REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_X_POS)

/*
 * int1_status_en_wom_y
 * For UI/AP interface, source enable register for Wake On Motion event on Y axis interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_Y_POS      0x02
#define REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_Y_MASK     (0x01 << REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_Y_POS)

/*
 * int1_status_en_wom_z
 * For UI/AP interface, source enable register for Wake On Motion event on Z axis interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_Z_POS      0x03
#define REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_Z_MASK     (0x01 << REG_INT1_CONFIG1_INT1_STATUS_EN_WOM_Z_POS)

/*
 * int1_status_en_i3c_protocol_err
 * For UI/AP interface, source enable register for  I3C protocol error detected by I3C Slave interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_I3C_PROTOCOL_ERR_POS      0x04
#define REG_INT1_CONFIG1_INT1_STATUS_EN_I3C_PROTOCOL_ERR_MASK     (0x01 << REG_INT1_CONFIG1_INT1_STATUS_EN_I3C_PROTOCOL_ERR_POS)

/*
 * int1_status_en_i2cm_done
 * , For UI/AP interface, source enable register for  I2C Master operation completed interrupt.
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_I2CM_DONE_POS      0x05
#define REG_INT1_CONFIG1_INT1_STATUS_EN_I2CM_DONE_MASK     (0x01 << REG_INT1_CONFIG1_INT1_STATUS_EN_I2CM_DONE_POS)

/*
 * int1_status_en_apex_event
 *  For UI/AP interface, source enable register for  edmp event interrupt.
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT1_CONFIG1_INT1_STATUS_EN_APEX_EVENT_POS      0x06
#define REG_INT1_CONFIG1_INT1_STATUS_EN_APEX_EVENT_MASK     (0x01 << REG_INT1_CONFIG1_INT1_STATUS_EN_APEX_EVENT_POS)



/*
 * REG_INT1_CONFIG2
 * Register Name : INT1_CONFIG2
 */

/*
 * int1_polarity
 * UI/AP interface: Interrupt polarity.
 * 0: active low,
 * 1: active high,
 * Setting can be changed only when all interrupts of the corresponding serial interface are disabled.
 */
#define REG_INT1_CONFIG2_INT1_POLARITY_POS      0x00
#define REG_INT1_CONFIG2_INT1_POLARITY_MASK     0x01

/*
 * int1_mode
 * "UI/AP interface: Interrupt mode.
 * 0: pulse mode,
 * 1: latch mode,
 * Setting can be changed only when all interrupts of the corresponding serial interface are disabled."
 *
 */
#define REG_INT1_CONFIG2_INT1_MODE_POS      0x01
#define REG_INT1_CONFIG2_INT1_MODE_MASK     (0x01 << REG_INT1_CONFIG2_INT1_MODE_POS)

/*
 * int1_drive
 * Sets INT1 PAD in to Open-drain or Push-pull
 * 1 : Open-drain
 * 0 : Push-pull
 */
#define REG_INT1_CONFIG2_INT1_DRIVE_POS      0x02
#define REG_INT1_CONFIG2_INT1_DRIVE_MASK     (0x01 << REG_INT1_CONFIG2_INT1_DRIVE_POS)



/*
 * REG_INT1_STATUS0
 * Register Name : INT1_STATUS0
 */

/*
 * int1_status_fifo_full
 * For UI/AP interface, Indicates if status register (ISR) for FIFO full interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_FIFO_FULL_POS      0x00
#define REG_INT1_STATUS0_INT1_STATUS_FIFO_FULL_MASK     0x01

/*
 * int1_status_fifo_ths
 * For UI/AP interface, Indicates if status register (ISR) for FIFO count ≥ FIFO threshold interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_FIFO_THS_POS      0x01
#define REG_INT1_STATUS0_INT1_STATUS_FIFO_THS_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_FIFO_THS_POS)

/*
 * int1_status_drdy
 * For UI/AP interface, Indicates if status register (ISR) for User Interface Sensor Register Data Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_DRDY_POS      0x02
#define REG_INT1_STATUS0_INT1_STATUS_DRDY_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_DRDY_POS)

/*
 * int1_status_aux1_drdy
 * For UI/AP interface, Indicates if status register (ISR) for Optical Image Stabilization Interface 1 Sensor Register Data Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_AUX1_DRDY_POS      0x03
#define REG_INT1_STATUS0_INT1_STATUS_AUX1_DRDY_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_AUX1_DRDY_POS)

/*
 * int1_status_ap_fsync
 * For UI/AP interface, Indicates if status register (ISR) for User Interface FSYNC interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_AP_FSYNC_POS      0x04
#define REG_INT1_STATUS0_INT1_STATUS_AP_FSYNC_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_AP_FSYNC_POS)

/*
 * int1_status_ap_agc_rdy
 * For UI/AP interface, Indicates if status register (ISR) for User Interface AGC Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_AP_AGC_RDY_POS      0x05
#define REG_INT1_STATUS0_INT1_STATUS_AP_AGC_RDY_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_AP_AGC_RDY_POS)

/*
 * int1_status_aux1_agc_rdy
 * For UI/AP interface, Indicates if status register (ISR) for Optical Image Stabilization Interface #1 AGC Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_AUX1_AGC_RDY_POS      0x06
#define REG_INT1_STATUS0_INT1_STATUS_AUX1_AGC_RDY_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_AUX1_AGC_RDY_POS)

/*
 * int1_status_reset_done
 * For UI/AP interface, Indicates if status register (ISR) for Reset process is finished(after OTP copy is complete, i.e. after OTP_DONE signal) interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS0_INT1_STATUS_RESET_DONE_POS      0x07
#define REG_INT1_STATUS0_INT1_STATUS_RESET_DONE_MASK     (0x01 << REG_INT1_STATUS0_INT1_STATUS_RESET_DONE_POS)



/*
 * REG_INT1_STATUS1
 * Register Name : INT1_STATUS1
 */

/*
 * int1_status_pll_rdy
 * For UI/AP interface, Indicates if status register (ISR) for PLL is locked  interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_PLL_RDY_POS      0x00
#define REG_INT1_STATUS1_INT1_STATUS_PLL_RDY_MASK     0x01

/*
 * int1_status_wom_x
 * For UI/AP interface, Indicates if status register (ISR) for Wake On Motion event on X axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_WOM_X_POS      0x01
#define REG_INT1_STATUS1_INT1_STATUS_WOM_X_MASK     (0x01 << REG_INT1_STATUS1_INT1_STATUS_WOM_X_POS)

/*
 * int1_status_wom_y
 * For UI/AP interface, Indicates if status register (ISR) for Wake On Motion event on Y axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_WOM_Y_POS      0x02
#define REG_INT1_STATUS1_INT1_STATUS_WOM_Y_MASK     (0x01 << REG_INT1_STATUS1_INT1_STATUS_WOM_Y_POS)

/*
 * int1_status_wom_z
 * For UI/AP interface, Indicates if status register (ISR) for Wake On Motion event on Z axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_WOM_Z_POS      0x03
#define REG_INT1_STATUS1_INT1_STATUS_WOM_Z_MASK     (0x01 << REG_INT1_STATUS1_INT1_STATUS_WOM_Z_POS)

/*
 * int1_status_i3c_protocol_err
 * For UI/AP interface, Indicates if status register (ISR) for I3C protocol error detected by I3C Slave interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_I3C_PROTOCOL_ERR_POS      0x04
#define REG_INT1_STATUS1_INT1_STATUS_I3C_PROTOCOL_ERR_MASK     (0x01 << REG_INT1_STATUS1_INT1_STATUS_I3C_PROTOCOL_ERR_POS)

/*
 * int1_status_i2cm_done
 * For UI/AP interface, Indicates if status register (ISR) for I2C Master operation completed interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_I2CM_DONE_POS      0x05
#define REG_INT1_STATUS1_INT1_STATUS_I2CM_DONE_MASK     (0x01 << REG_INT1_STATUS1_INT1_STATUS_I2CM_DONE_POS)

/*
 * int1_status_apex_event
 * For UI/AP interface, Indicates if status register (ISR) for edmp eventl interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT1_STATUS1_INT1_STATUS_APEX_EVENT_POS      0x06
#define REG_INT1_STATUS1_INT1_STATUS_APEX_EVENT_MASK     (0x01 << REG_INT1_STATUS1_INT1_STATUS_APEX_EVENT_POS)



/*
 * REG_ACCEL_CONFIG0
 * Register Name : ACCEL_CONFIG0
 */

/*
 * accel_odr
 * [Supports Dynamic Change] Accelerometer Output Data Rate at the UI/AP FIFO. ODR frequency:
 *   0 -> 6.4k (LN only)
 *   1 -> 6.4k (LN only)
 *   2 -> 6.4k (LN only)
 *   3 -> 6.4k (LN only)
 *   4 -> 3.2k (LN only)
 *   5 -> 1.6k (LN only)
 *   6 -> 800 (default, LN only))
 *   7 -> 400
 *   8 -> 200
 *   9 -> 100
 *   10 -> 50
 *   11 -> 25
 *   12 -> 12.5
 *   13 -> 6.25      (LP only)
 *   14 -> 3.125    (LP only)
 *   15 -> 1.5625  (LP only)
 *
 * This field can be changed on-the-fly even if accel sensor is already on
 */
#define REG_ACCEL_CONFIG0_ACCEL_ODR_POS      0x00
#define REG_ACCEL_CONFIG0_ACCEL_ODR_MASK     0x0f

/*
 * ap_accel_fs_sel
 * [Supports Dynamic Change] Set the UI/AP signal path accel full scale
 * 0 : 32 gee
 * 1 : 16 gee
 * 2 : 8 gee
 * 3 :4 gee
 * 4 : 2 gee
 */
#define REG_ACCEL_CONFIG0_AP_ACCEL_FS_SEL_POS      0x04
#define REG_ACCEL_CONFIG0_AP_ACCEL_FS_SEL_MASK     (0x07 << REG_ACCEL_CONFIG0_AP_ACCEL_FS_SEL_POS)



/*
 * REG_GYRO_CONFIG0
 * Register Name : GYRO_CONFIG0
 */

/*
 * gyro_odr
 * [Supports Dynamic Change] Gyroscope Output Data Rate at the UI/AP FIFO. ODR frequency:
 *   0 -> 6.4k (LN only)
 *   1 -> 6.4k (LN only)
 *   2 -> 6.4k (LN only)
 *   3 -> 6.4k (LN only)
 *   4 -> 3.2k (LN only)
 *   5 -> 1.6k (LN only)
 *   6 -> 800 (default, LN only))
 *   7 -> 400
 *   8 -> 200
 *   9 -> 100
 *   10 -> 50
 *   11 -> 25
 *   12 -> 12.5
 *   13 -> 6.25      (LP only)
 *   14 -> 3.125    (LP only)
 *   15 -> 1.5625  (LP only)
 *
 * This field can be changed on-the-fly even if gyro sensor is already on
 */
#define REG_GYRO_CONFIG0_GYRO_ODR_POS      0x00
#define REG_GYRO_CONFIG0_GYRO_ODR_MASK     0x0f

/*
 * ap_gyro_fs_sel
 * [Supports Dynamic Change] Set the UI/AP signal path gyro full scale
 * 0 : 4000 dps
 * 1 : 2000 dps
 * 2 : 1000 dps
 * 3 : 500 dps
 * 4 : 250 dps
 * 5 : 125 dps
 * 6 : 62.5 dps
 * 7 : 31.25 dps
 * 8 : 15.625 dps
 */
#define REG_GYRO_CONFIG0_AP_GYRO_FS_SEL_POS      0x04
#define REG_GYRO_CONFIG0_AP_GYRO_FS_SEL_MASK     (0x0f << REG_GYRO_CONFIG0_AP_GYRO_FS_SEL_POS)



/*
 * REG_FIFO_CONFIG0
 * Register Name : FIFO_CONFIG0
 */

/*
 * fifo_depth
 * Set the FIFO depth in bytes. The minimum depth is 256 bytes, which is also the granularity of the FIFO space. The FIFO space start address is fixed and set to: fifo_phy_start_addr = (FIFO_IP_SRAM_NROW * 4) – ((fifo_depth+1) * 256)
 * The effective number of choices is capped by FIFO_MAX_DEPTH parameter. As an example, if FIFO_MAX_DEPTH=3 then fifo_depth[5:0] can assume the following values: 0, 1, 2, 3; the remaining choiches must be considered as reserved.
 * 0 : 256
 * 1 : 512
 * 2 : 768
 * 3 : 1024
 * 4 : 1280
 * ...
 * 62 : 16128
 * 63 : 16384
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG0_FIFO_DEPTH_POS      0x00
#define REG_FIFO_CONFIG0_FIFO_DEPTH_MASK     0x3f

/*
 * fifo_mode
 * [Supports Dynamic Change] Set the FIFO operation mode.
 * 2’b00: Bypass (disabled)
 * 2’b01: Stream mode - Frames are overwritten when the FIFO full condition is reached. Supported only for 8, 16, 20 bytes frame size. Whether this mode is selected for 32 or 64 bytes frame sizes, FIFO remains in Bypass mode.
 * 2’b10: Stop-on-full mode - Frames are not stored in FIFO once the FIFO full condition is reached
 * 2’b11: Reserved
 */
#define REG_FIFO_CONFIG0_FIFO_MODE_POS      0x06
#define REG_FIFO_CONFIG0_FIFO_MODE_MASK     (0x03 << REG_FIFO_CONFIG0_FIFO_MODE_POS)



/*
 * REG_FIFO_CONFIG1_0
 * Register Name : FIFO_CONFIG1_0
 */

/*
 * fifo_wm_th
 * [Supports Dynamic Change] FIFO watermark threshold. When set to 0, the watermark is disabled.
 * When writing new threshold value, user must first write threshold LSByte (bits [7:0]), then MSByte (bits [15:8]). New threshold register value will take effect only when MSByte is written. MSByte write pulse is used to check watermark level and generate WM interrupt event.
 * Can be changed on-the-fly.
 */
#define REG_FIFO_CONFIG1_0_FIFO_WM_TH_POS      0x00
#define REG_FIFO_CONFIG1_0_FIFO_WM_TH_MASK     0xff



/*
 * REG_FIFO_CONFIG1_1
 * Register Name : FIFO_CONFIG1_1
 */

/*
 * fifo_wm_th
 * [Supports Dynamic Change] FIFO watermark threshold. When set to 0, the watermark is disabled.
 * When writing new threshold value, user must first write threshold LSByte (bits [7:0]), then MSByte (bits [15:8]). New threshold register value will take effect only when MSByte is written. MSByte write pulse is used to check watermark level and generate WM interrupt event.
 * Can be changed on-the-fly.
 */
#define REG_FIFO_CONFIG1_1_FIFO_WM_TH_POS      0x00
#define REG_FIFO_CONFIG1_1_FIFO_WM_TH_MASK     0xff



/*
 * REG_FIFO_CONFIG2
 * Register Name : FIFO_CONFIG2
 */

/*
 * fifo_frame_size
 * Select the frame size when FIFO write port interface is AHB (fifo_bus_intf_sel = 1)
 * 3’b000: 8 bytes
 * 3’b001: 16 bytes
 * 3’b010: 20 bytes
 * 3’b011: 32 bytes
 * 3’b100: 64 bytes
 * Others: reserved
 * It must be changed when FIFO is disabled (Bypass mode).
 * When the FIFO write port interface is SREG, the frame size is managed by the SREG IP through sreg_fifo_frame_size port when FIFO is enabled, meaning SREG IP provides the proper frame size based on sensor configuration and also provides a FIFO flush after the size update to reset the whole FIFO.
 */
#define REG_FIFO_CONFIG2_FIFO_FRAME_SIZE_POS      0x00
#define REG_FIFO_CONFIG2_FIFO_FRAME_SIZE_MASK     0x07

/*
 * fifo_wr_wm_gt_th
 * Set write watermark interrupt generating condition.
 * 0: write watermark interrupt generated when counter is equal to threshold
 * 1: write watermark interrupt generated when counter is greater than or equal to threshold
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_WR_WM_GT_TH_POS      0x03
#define REG_FIFO_CONFIG2_FIFO_WR_WM_GT_TH_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_WR_WM_GT_TH_POS)

/*
 * fifo_int_ovfl
 * Select whether the FIFO full and FIFO watermark interrupts are generated continuously when FIFO is in overflow
 * 0: interrupts stops when FIFO is overflowed
 * 1: interrupts are continuously generated when FIFO is overflowed
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_INT_OVFL_POS      0x04
#define REG_FIFO_CONFIG2_FIFO_INT_OVFL_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_INT_OVFL_POS)

/*
 * fifo_addr_space_lock
 * Prevents write accesses from the bus to the FIFO storage area to avoid FIFO data corruption.
 * 0: write allowed
 * 1: write not allowed
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_ADDR_SPACE_LOCK_POS      0x05
#define REG_FIFO_CONFIG2_FIFO_ADDR_SPACE_LOCK_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_ADDR_SPACE_LOCK_POS)

/*
 * fifo_bus_intf_sel
 * Select the FIFO write port interface.
 * 0: SREG interface
 * 1: AHB Interface
 * Can be changed when FIFO is disabled (Bypass mode).
 */
#define REG_FIFO_CONFIG2_FIFO_BUS_INTF_SEL_POS      0x06
#define REG_FIFO_CONFIG2_FIFO_BUS_INTF_SEL_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_BUS_INTF_SEL_POS)

/*
 * fifo_flush
 * [Supports Dynamic Change] FIFO flush command. When set high the FIFO is flushed, meaning the pointers and control logic is reset. Configuration registers are not reset. The register is auto-cleared by hardware.
 * Can be changed on-the-fly.
 */
#define REG_FIFO_CONFIG2_FIFO_FLUSH_POS      0x07
#define REG_FIFO_CONFIG2_FIFO_FLUSH_MASK     (0x01 << REG_FIFO_CONFIG2_FIFO_FLUSH_POS)



/*
 * REG_FIFO_CONFIG3
 * Register Name : FIFO_CONFIG3
 */

/*
 * fifo_if_en
 * [Supports Dynamic Change] Enable the SREG-FIFO interface. The SREG-FIFO interface should be enabled when the FIFO is also enabled (i.e., not in bypass mode), so a standard enable sequence is: 1) Enable FIFO. 2) Enable SREG-FIFO interface. The opposite for the disable sequence. To prevent power drain, sreg_fifo_if_en should be set to 0 if FIFO is in bypass mode.
 */
#define REG_FIFO_CONFIG3_FIFO_IF_EN_POS      0x00
#define REG_FIFO_CONFIG3_FIFO_IF_EN_MASK     0x01

/*
 * fifo_accel_en
 * Enable accel data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_ACCEL_EN_POS      0x01
#define REG_FIFO_CONFIG3_FIFO_ACCEL_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_ACCEL_EN_POS)

/*
 * fifo_gyro_en
 * Enable gyro data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_GYRO_EN_POS      0x02
#define REG_FIFO_CONFIG3_FIFO_GYRO_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_GYRO_EN_POS)

/*
 * fifo_hires_en
 * Enable high resolution accel and gyro data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_HIRES_EN_POS      0x03
#define REG_FIFO_CONFIG3_FIFO_HIRES_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_HIRES_EN_POS)

/*
 * fifo_es0_en
 * Enable External Sensor 0 data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_ES0_EN_POS      0x04
#define REG_FIFO_CONFIG3_FIFO_ES0_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_ES0_EN_POS)

/*
 * fifo_es1_en
 * Enable External Sensor 1 data insertion into FIFO frame
 */
#define REG_FIFO_CONFIG3_FIFO_ES1_EN_POS      0x05
#define REG_FIFO_CONFIG3_FIFO_ES1_EN_MASK     (0x01 << REG_FIFO_CONFIG3_FIFO_ES1_EN_POS)



/*
 * REG_FIFO_CONFIG4
 * Register Name : FIFO_CONFIG4
 */

/*
 * fifo_es0_6b_9b
 * Select how many valid bytes External Sensor 0 provides
 * 0 : 6 bytes
 * 1 : 9 bytes
 */
#define REG_FIFO_CONFIG4_FIFO_ES0_6B_9B_POS      0x00
#define REG_FIFO_CONFIG4_FIFO_ES0_6B_9B_MASK     0x01

/*
 * fifo_tmst_fsync_en
 * Enable the insertion of the Timestamp or FSYNC data into FIFO frame
 * 0 : No Timestamp/FSYNC data inserted into FIFO frame (timestamp fields are 0x0000). fsync_tag_en bit in FIFO header is 0
 * 1 : Timestamp/FSYNC data inserted into FIFO frame. fsync_tag_en bit in FIFO header is set on a FSYNC trigger event
 */
#define REG_FIFO_CONFIG4_FIFO_TMST_FSYNC_EN_POS      0x01
#define REG_FIFO_CONFIG4_FIFO_TMST_FSYNC_EN_MASK     (0x01 << REG_FIFO_CONFIG4_FIFO_TMST_FSYNC_EN_POS)

/*
 * fifo_comp_en
 * Enable the FIFO compression algorithm
 */
#define REG_FIFO_CONFIG4_FIFO_COMP_EN_POS      0x02
#define REG_FIFO_CONFIG4_FIFO_COMP_EN_MASK     (0x01 << REG_FIFO_CONFIG4_FIFO_COMP_EN_POS)

/*
 * fifo_comp_nc_flow_cfg
 * Configures the compression algorithm to write non-compressed frames at a certain rate
 * 0 : Non-compressed frame flow is disabled
 * 1 : Non-compressed frame every 8 frames
 * 2 : Non-compressed frame every 16 frames
 * 3 : Non-compressed frame every 32 frames
 * 4 : Non-compressed frame every 64 frames
 * 5 : Non-compressed frame every 128 frames
 */
#define REG_FIFO_CONFIG4_FIFO_COMP_NC_FLOW_CFG_POS      0x03
#define REG_FIFO_CONFIG4_FIFO_COMP_NC_FLOW_CFG_MASK     (0x07 << REG_FIFO_CONFIG4_FIFO_COMP_NC_FLOW_CFG_POS)



/*
 * REG_TMST_WOM_CONFIG
 * Register Name : TMST_WOM_CONFIG
 */

/*
 * wom_int_dur
 *   0: OFF
 */
#define REG_TMST_WOM_CONFIG_WOM_INT_DUR_POS      0x00
#define REG_TMST_WOM_CONFIG_WOM_INT_DUR_MASK     0x03

/*
 * wom_int_mode
 *   1: ON
 */
#define REG_TMST_WOM_CONFIG_WOM_INT_MODE_POS      0x02
#define REG_TMST_WOM_CONFIG_WOM_INT_MODE_MASK     (0x01 << REG_TMST_WOM_CONFIG_WOM_INT_MODE_POS)

/*
 * wom_mode
 * 0 - Initial sample is stored. Future samples are compared to initial sample (Mantis)
 * 1 - Compare current sample to previous sample (Scorpion)
 */
#define REG_TMST_WOM_CONFIG_WOM_MODE_POS      0x03
#define REG_TMST_WOM_CONFIG_WOM_MODE_MASK     (0x01 << REG_TMST_WOM_CONFIG_WOM_MODE_POS)

/*
 * wom_en
 * 0 - Initial sample is stored. Future samples are compared to initial sample (Mantis)
 * 1 - Compare current sample to previous sample (Scorpion)
 */
#define REG_TMST_WOM_CONFIG_WOM_EN_POS      0x04
#define REG_TMST_WOM_CONFIG_WOM_EN_MASK     (0x01 << REG_TMST_WOM_CONFIG_WOM_EN_POS)

/*
 * tmst_resol
 * Time Stamp resolution; When set to 0 (default), time stamp resolution is 1 us. When set to 1, resolution is 16us
 */
#define REG_TMST_WOM_CONFIG_TMST_RESOL_POS      0x05
#define REG_TMST_WOM_CONFIG_TMST_RESOL_MASK     (0x01 << REG_TMST_WOM_CONFIG_TMST_RESOL_POS)

/*
 * tmst_delta_en
 * Time Stamp delta Enable : When set to 1, the Time stamp field contains the  measurement of time since  the last occurrence of trigger event
 */
#define REG_TMST_WOM_CONFIG_TMST_DELTA_EN_POS      0x06
#define REG_TMST_WOM_CONFIG_TMST_DELTA_EN_MASK     (0x01 << REG_TMST_WOM_CONFIG_TMST_DELTA_EN_POS)



/*
 * REG_FSYNC_CONFIG0
 * Register Name : FSYNC_CONFIG0
 */

/*
 * ap_fsync_sel
 * Select the sensor that will carry the Fsync tagging
 * 0 : FSYNC tagging is disabled
 * 1 : Tag Fsync flag to TEMP_OUT LSB
 * 2 : Tag Fsync flag to GYRO_XOUT LSB
 * 3 : Tag Fsync flag to GYRO_YOUT LSB
 * 4 : Tag Fsync flag to GYRO_ZOUT LSB
 * 5 : Tag Fsync flag to ACCEL_XOUT LSB
 * 6 : Tag Fsync flag to ACCEL_YOUT LSB
 * 7 : Tag Fsync flag to ACCEL_ZOUT LSB
 */
#define REG_FSYNC_CONFIG0_AP_FSYNC_SEL_POS      0x00
#define REG_FSYNC_CONFIG0_AP_FSYNC_SEL_MASK     0x07

/*
 * ap_fsync_flag_clear_sel
 * Select the fsync flag clear policy
 * 0 : the fsync flag is cleared when UI/AP sensor reg is updated
 * 1 : the fsync flag is cleared when UI/AP serial interface reads the sensor register LSB of fsync tagged axis
 */
#define REG_FSYNC_CONFIG0_AP_FSYNC_FLAG_CLEAR_SEL_POS      0x03
#define REG_FSYNC_CONFIG0_AP_FSYNC_FLAG_CLEAR_SEL_MASK     (0x01 << REG_FSYNC_CONFIG0_AP_FSYNC_FLAG_CLEAR_SEL_POS)



/*
 * REG_FSYNC_CONFIG1
 * Register Name : FSYNC_CONFIG1
 */

/*
 * aux1_fsync_sel
 * Select the sensor that will carry the Fsync tagging
 * 0 : FSYNC tagging is disabled
 * 1 : Tag Fsync flag to TEMP_OUT LSB
 * 2 : Tag Fsync flag to GYRO_XOUT LSB
 * 3 : Tag Fsync flag to GYRO_YOUT LSB
 * 4 : Tag Fsync flag to GYRO_ZOUT LSB
 * 5 : Tag Fsync flag to ACCEL_XOUT LSB
 * 6 : Tag Fsync flag to ACCEL_YOUT LSB
 * 7 : Tag Fsync flag to ACCEL_ZOUT LSB
 */
#define REG_FSYNC_CONFIG1_AUX1_FSYNC_SEL_POS      0x00
#define REG_FSYNC_CONFIG1_AUX1_FSYNC_SEL_MASK     0x07

/*
 * aux1_fsync_flag_clear_sel
 * Select the fsync flag clear policy
 * 0 : the fsync flag is cleared when OIS1 sensor reg is updated
 * 1 : the fsync flag is cleared when AUX1 serial interface reads the sensor register LSB of fsync tagged axis
 */
#define REG_FSYNC_CONFIG1_AUX1_FSYNC_FLAG_CLEAR_SEL_POS      0x03
#define REG_FSYNC_CONFIG1_AUX1_FSYNC_FLAG_CLEAR_SEL_MASK     (0x01 << REG_FSYNC_CONFIG1_AUX1_FSYNC_FLAG_CLEAR_SEL_POS)



/*
 * REG_OTP_HEATER_RTC_CONFIG
 * Register Name : OTP_HEATER_RTC_CONFIG
 */

/*
 * otp_done
 * 1: Indicate OTP copy operation is completed.
 * 0: Indicate OTP copy operation is not done. Any write from serial interface block is dropped. Any read from serial interface will have 0 value return.
 */
#define REG_OTP_HEATER_RTC_CONFIG_OTP_DONE_POS      0x00
#define REG_OTP_HEATER_RTC_CONFIG_OTP_DONE_MASK     0x01

/*
 * otp_crc_pass
 * 0: The calculated CRC is not matching the CRC signature from OTP.
 * 1: Calculated CRC is matching the CRC signature from OTP.
 */
#define REG_OTP_HEATER_RTC_CONFIG_OTP_CRC_PASS_POS      0x01
#define REG_OTP_HEATER_RTC_CONFIG_OTP_CRC_PASS_MASK     (0x01 << REG_OTP_HEATER_RTC_CONFIG_OTP_CRC_PASS_POS)

/*
 * heater_en
 * Turns on or off the heater.
 */
#define REG_OTP_HEATER_RTC_CONFIG_HEATER_EN_POS      0x02
#define REG_OTP_HEATER_RTC_CONFIG_HEATER_EN_MASK     (0x01 << REG_OTP_HEATER_RTC_CONFIG_HEATER_EN_POS)

/*
 * heater_clk_mode
 * 00: heater_clk_d2a is 0 (current is in the +ve direction through the heating element)
 * 01: heater_clk_d2a is 1 (current is in the -ve direction through the heating element)
 * 10: heater_clk_d2a toggles between 0 and 1 at 128 kHz with a 50% duty cycle
 * 11: heater_clk_d2a will have a 5-bit PN generator with 128 kHz clk. The PN generator is modified with alternating polarity to ensure 50% duty cycle
 */
#define REG_OTP_HEATER_RTC_CONFIG_HEATER_CLK_MODE_POS      0x03
#define REG_OTP_HEATER_RTC_CONFIG_HEATER_CLK_MODE_MASK     (0x03 << REG_OTP_HEATER_RTC_CONFIG_HEATER_CLK_MODE_POS)

/*
 * rtc_mode
 * If set to 1 enables the RTC functionality: the external clock source CLK_IN is used to keep the time-base and generate precise ODR values.
 * If also the I3C Synchronous Mode functionality is enabled, then setting this bit to 1 will have no effects.
 * RTC functionality can be enabled only if accel_lp_clk_sel is set to 1; otherwise device may not behave as expected.
 */
#define REG_OTP_HEATER_RTC_CONFIG_RTC_MODE_POS      0x05
#define REG_OTP_HEATER_RTC_CONFIG_RTC_MODE_MASK     (0x01 << REG_OTP_HEATER_RTC_CONFIG_RTC_MODE_POS)

/*
 * rtc_align
 * RTC align bit – re-align command is generated by writing this bit.
 */
#define REG_OTP_HEATER_RTC_CONFIG_RTC_ALIGN_POS      0x06
#define REG_OTP_HEATER_RTC_CONFIG_RTC_ALIGN_MASK     (0x01 << REG_OTP_HEATER_RTC_CONFIG_RTC_ALIGN_POS)



/*
 * REG_DMP_EXT_SEN_ODR_CFG
 * Register Name : DMP_EXT_SEN_ODR_CFG
 */

/*
 * apex_odr
 * [Supports Dynamic Change] DMP Output Data Rate.
 * The dmp_odr needs to be smaller than or equal to both the accel_odr and gyro_odr. Also, all rates but 800Hz can be set if Accel UI/AP is in LP; in order to set the DMP ODR to 800Hz, the Accel UI/AP PM must be set in LN, otherwise the new rate will not be applied).
 *
 * 3'b000 -> 25Hz
 * 3'b001 -> 50Hz (default)
 * 3'b010 -> 100Hz
 * 3'b011 -> 200Hz
 * 3'b100 -> 400Hz
 * 3'b101 -> 800Hz      (LN-only)
 * 3'b110 -> reserved
 * 3'b111 -> reserved
 */
#define REG_DMP_EXT_SEN_ODR_CFG_APEX_ODR_POS      0x00
#define REG_DMP_EXT_SEN_ODR_CFG_APEX_ODR_MASK     0x07

/*
 * ext_odr
 * Internal external ODR for I2CM kickoff
 * 000: 3.125 Hz
 * 001: 6.25 Hz
 * 010: 12.5 Hz
 * 011: 25 Hz
 * 100: 50 Hz
 * 101: 100 Hz
 * 110: 200 Hz
 * 111: 400 Hz
 */
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_ODR_POS      0x03
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_ODR_MASK     (0x07 << REG_DMP_EXT_SEN_ODR_CFG_EXT_ODR_POS)

/*
 * ext_sensor_en
 * 1: To enable the SMC block to generate the ODR event for external snsor operation per the setting of ext_odr register.
 * 0: To disable the SMC block from generating the ODR event for the external sensor operation.
 *
 * This register is not used by any other blocks.
 */
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_SENSOR_EN_POS      0x06
#define REG_DMP_EXT_SEN_ODR_CFG_EXT_SENSOR_EN_MASK     (0x01 << REG_DMP_EXT_SEN_ODR_CFG_EXT_SENSOR_EN_POS)



/*
 * REG_ODR_DECIMATE_CONFIG
 * Register Name : ODR_DECIMATE_CONFIG
 */

/*
 * accel_fifo_odr_dec
 * Decimation factor for the sreg_update rate at the Accel FIFO.
 * Decimation value is 2^(accel_fifo_down):
 *   - 4'b0000: 1 (as input ODR rate)
 *   - 4'b0001: 2
 *   - 4'b0010: 4
 *   - 4'b0011: 8
 *   - 4'b0100: 16
 *   - 4'b0101: 32
 *   - 4'b0110: 64
 *   - 4'b0111: 128
 *   - 4'b1000: 256
 *   - 4'b1001: 512
 *   - 4'b1010: 1024
 *   - 4'b1011: 2048
 *   - 4'b1100: 4096
 *   - 4'b1101: reserved
 *   - 4'b1110: reserved
 *   - 4'b1111: reserved
 *
 * The final sreg_update value will be accel_odr/2^(accel_fifo_odr_dec), with a minimum decimated rate equal to the minimum ODR value.
 */
#define REG_ODR_DECIMATE_CONFIG_ACCEL_FIFO_ODR_DEC_POS      0x00
#define REG_ODR_DECIMATE_CONFIG_ACCEL_FIFO_ODR_DEC_MASK     0x0f

/*
 * gyro_fifo_odr_dec
 * Decimation factor for the sreg_update rate at the Gyroscope FIFO.
 * Decimation value is 2^(gyro_fifo_down):
 *   - 4'b0000: 1 (as input ODR rate)
 *   - 4'b0001: 2
 *   - 4'b0010: 4
 *   - 4'b0011: 8
 *   - 4'b0100: 16
 *   - 4'b0101: 32
 *   - 4'b0110: 64
 *   - 4'b0111: 128
 *   - 4'b1000: 256
 *   - 4'b1001: 512
 *   - 4'b1010: 1024
 *   - 4'b1011: 2048
 *   - 4'b1100: 4096
 *   - 4'b1101: reserved
 *   - 4'b1110: reserved
 *   - 4'b1111: reserved
 *
 * The final sreg_update value will be gyro_odr/2^(gyro_fifo_odr_dec), with a minimum decimated rate equal to the minimum ODR value.
 */
#define REG_ODR_DECIMATE_CONFIG_GYRO_FIFO_ODR_DEC_POS      0x04
#define REG_ODR_DECIMATE_CONFIG_GYRO_FIFO_ODR_DEC_MASK     (0x0f << REG_ODR_DECIMATE_CONFIG_GYRO_FIFO_ODR_DEC_POS)



/*
 * REG_EDMP_APEX_EN0
 * Register Name : EDMP_APEX_EN0
 */

/*
 * tap_en
 * Set 1 to enable Tap algorithm
 */
#define REG_EDMP_APEX_EN0_TAP_EN_POS      0x00
#define REG_EDMP_APEX_EN0_TAP_EN_MASK     0x01

/*
 * highg_en
 * Set 1 to enable HighG algorithm
 */
#define REG_EDMP_APEX_EN0_HIGHG_EN_POS      0x01
#define REG_EDMP_APEX_EN0_HIGHG_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_HIGHG_EN_POS)

/*
 * lowg_en
 * Set 1 to enable LowG algorithm
 */
#define REG_EDMP_APEX_EN0_LOWG_EN_POS      0x02
#define REG_EDMP_APEX_EN0_LOWG_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_LOWG_EN_POS)

/*
 * tilt_en
 * Set 1 to enable Tilt algorithm
 */
#define REG_EDMP_APEX_EN0_TILT_EN_POS      0x03
#define REG_EDMP_APEX_EN0_TILT_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_TILT_EN_POS)

/*
 * pedo_en
 * Set 1 to enable Pedometer algorithm
 */
#define REG_EDMP_APEX_EN0_PEDO_EN_POS      0x04
#define REG_EDMP_APEX_EN0_PEDO_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_PEDO_EN_POS)

/*
 * ff_en
 * Set 1 to enable Freefall algorithm
 */
#define REG_EDMP_APEX_EN0_FF_EN_POS      0x05
#define REG_EDMP_APEX_EN0_FF_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_FF_EN_POS)

/*
 * r2w_en
 * Set 1 to enable Raise to Wake algorithm
 */
#define REG_EDMP_APEX_EN0_R2W_EN_POS      0x06
#define REG_EDMP_APEX_EN0_R2W_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_R2W_EN_POS)

/*
 * smd_en
 * Set 1 to enable SMD algorithm
 */
#define REG_EDMP_APEX_EN0_SMD_EN_POS      0x07
#define REG_EDMP_APEX_EN0_SMD_EN_MASK     (0x01 << REG_EDMP_APEX_EN0_SMD_EN_POS)



/*
 * REG_EDMP_APEX_EN1
 * Register Name : EDMP_APEX_EN1
 */

/*
 * soft_hard_iron_corr_en
 * Set 1 to enable soft iron hard iron correction
 */
#define REG_EDMP_APEX_EN1_SOFT_HARD_IRON_CORR_EN_POS      0x00
#define REG_EDMP_APEX_EN1_SOFT_HARD_IRON_CORR_EN_MASK     0x01

/*
 * init_en
 * This bit is set by the host to indicate: eDMP executes only the segment of code that initialize constants used by algorithms. The register is R/W by the external host through the direct register accessing path. The register is R/C by any AHB master when it is accessed via internal AHB/APB bus.
 */
#define REG_EDMP_APEX_EN1_INIT_EN_POS      0x01
#define REG_EDMP_APEX_EN1_INIT_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_INIT_EN_POS)

/*
 * power_save_en
 * Set 1 to enable power save mode
 */
#define REG_EDMP_APEX_EN1_POWER_SAVE_EN_POS      0x02
#define REG_EDMP_APEX_EN1_POWER_SAVE_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_POWER_SAVE_EN_POS)

/*
 * feature1_en
 * Set 1 to enable reserved feature1
 */
#define REG_EDMP_APEX_EN1_FEATURE1_EN_POS      0x03
#define REG_EDMP_APEX_EN1_FEATURE1_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_FEATURE1_EN_POS)

/*
 * feature2_en
 * Set 1 to enable reserved feature2
 */
#define REG_EDMP_APEX_EN1_FEATURE2_EN_POS      0x04
#define REG_EDMP_APEX_EN1_FEATURE2_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_FEATURE2_EN_POS)

/*
 * feature3_en
 * Set 1 to enable reserved feature3
 */
#define REG_EDMP_APEX_EN1_FEATURE3_EN_POS      0x05
#define REG_EDMP_APEX_EN1_FEATURE3_EN_MASK     (0x01 << REG_EDMP_APEX_EN1_FEATURE3_EN_POS)

/*
 * edmp_enable
 * 0: mask out all eDMP input interrupts and freeze eDMP processing after eDMP is finished with current processing sample of all ISRs.
 * 1: Enable eDMP operation mode
 */
#define REG_EDMP_APEX_EN1_EDMP_ENABLE_POS      0x06
#define REG_EDMP_APEX_EN1_EDMP_ENABLE_MASK     (0x01 << REG_EDMP_APEX_EN1_EDMP_ENABLE_POS)



/*
 * REG_APEX_BUFFER_MGMT
 * Register Name : APEX_BUFFER_MGMT
 */

/*
 * step_count_edmp_wptr
 * LSB indicates SRAM address for eDMP to write
 * MSB indicates size 2 buffer wrap around
 * 00: eDMP writes to buffer 0
 * 01: eDMP writes to buffer 1
 * 10: eDMP writes to buffer 0
 * 11: eDMP writes to buffer 1
 */
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_EDMP_WPTR_POS      0x00
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_EDMP_WPTR_MASK     0x03

/*
 * step_count_host_rptr
 * LSB indicates SRAM address for host to read
 * MSB indicates size 2 buffer wrap around
 * 00: host reads buffer 0
 * 01: host reads buffer 1
 * 10: host reads buffer 0
 * 11: host reads buffer 1
 */
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_HOST_RPTR_POS      0x02
#define REG_APEX_BUFFER_MGMT_STEP_COUNT_HOST_RPTR_MASK     (0x03 << REG_APEX_BUFFER_MGMT_STEP_COUNT_HOST_RPTR_POS)

/*
 * ff_duration_edmp_wptr
 * LSB indicates SRAM address for eDMP to write
 * MSB indicates size 2 buffer wrap around
 * 00: eDMP writes to buffer 0
 * 01: eDMP writes to buffer 1
 * 10: eDMP writes to buffer 0
 * 11: eDMP writes to buffer 1
 */
#define REG_APEX_BUFFER_MGMT_FF_DURATION_EDMP_WPTR_POS      0x04
#define REG_APEX_BUFFER_MGMT_FF_DURATION_EDMP_WPTR_MASK     (0x03 << REG_APEX_BUFFER_MGMT_FF_DURATION_EDMP_WPTR_POS)

/*
 * ff_duration_host_rptr
 * LSB indicates SRAM address for host to read
 * MSB indicates size 2 buffer wrap around
 * 00: host reads buffer 0
 * 01: host reads buffer 1
 * 10: host reads buffer 0
 * 11: host reads buffer 1
 */
#define REG_APEX_BUFFER_MGMT_FF_DURATION_HOST_RPTR_POS      0x06
#define REG_APEX_BUFFER_MGMT_FF_DURATION_HOST_RPTR_MASK     (0x03 << REG_APEX_BUFFER_MGMT_FF_DURATION_HOST_RPTR_POS)



/*
 * REG_INTF_CONFIG0
 * Register Name : INTF_CONFIG0
 */

/*
 * ap_spi_mode
 * SPI Mode based on CPOL and CPHA
 * 0 : spi_mode0 or spi_mode3
 * 1: spi_mode1 or spi_mode2
 */
#define REG_INTF_CONFIG0_AP_SPI_MODE_POS      0x00
#define REG_INTF_CONFIG0_AP_SPI_MODE_MASK     0x01

/*
 * ap_spi_34_mode
 * 1: SPI 4 mode, use SDO pad to send data out.
 * 0: SPI 3 mode, use SDA pad to send data out.
 */
#define REG_INTF_CONFIG0_AP_SPI_34_MODE_POS      0x01
#define REG_INTF_CONFIG0_AP_SPI_34_MODE_MASK     (0x01 << REG_INTF_CONFIG0_AP_SPI_34_MODE_POS)

/*
 * i23c_timeout_en
 * Timeout detection enabling for SIFS IxC slave.
 */
#define REG_INTF_CONFIG0_I23C_TIMEOUT_EN_POS      0x03
#define REG_INTF_CONFIG0_I23C_TIMEOUT_EN_MASK     (0x01 << REG_INTF_CONFIG0_I23C_TIMEOUT_EN_POS)

/*
 * ap_ireg_auto_addr_inc_dis
 * This register controls the address auto-increment operation of the 32-bit indirect address when accessing reg_ireg_data from serial interface.
 * 1: Disable address auto-increment operation to the 32-bit address.
 * 0: Enable address auto-increment operation to the 32-bit address.
 *
 * In write operation, the 32-bit address is auto-incremented by 1 after write to ireg_data is completed.
 * In read operation, the 32-bit address is auto-incremented by 1 after ireg_data read return data is captured into SCLK-domain read-buffer residing in serial interface block.
 * The address auto increment operation stops when the address =  SIFS_AHB_TERMINAL_ADDR. Or when write to ireg_addr* occurs.
 *
 * Multiple write to address =  SIFS_AHB_TERMINAL_ADDR will only overwrite the same location even if ireg_auto_addr_inc_dis is 0. No wrap around of AHB address is expected.
 */
#define REG_INTF_CONFIG0_AP_IREG_AUTO_ADDR_INC_DIS_POS      0x04
#define REG_INTF_CONFIG0_AP_IREG_AUTO_ADDR_INC_DIS_MASK     (0x01 << REG_INTF_CONFIG0_AP_IREG_AUTO_ADDR_INC_DIS_POS)

/*
 * virtual_access_aux1_en
 * Virtual access DTP aux1 enable
 * 1 : UI/AP take control of AUX1 interface
 * When the aux1 virtual address mode is enabled, the accessing from the SIFS_AUX1 interface is not supported.
 */
#define REG_INTF_CONFIG0_VIRTUAL_ACCESS_AUX1_EN_POS      0x05
#define REG_INTF_CONFIG0_VIRTUAL_ACCESS_AUX1_EN_MASK     (0x01 << REG_INTF_CONFIG0_VIRTUAL_ACCESS_AUX1_EN_POS)

/*
 * glitch_filter_dis
 * 1: An overwrite bit to disable the 50ns glitch filter on AP SCL input and AP SDA input.
 * 0: This bit is not used to either disable or enable the 50ns glitch filter on AP SCL input and AP SDA input.
 */
#define REG_INTF_CONFIG0_GLITCH_FILTER_DIS_POS      0x06
#define REG_INTF_CONFIG0_GLITCH_FILTER_DIS_MASK     (0x01 << REG_INTF_CONFIG0_GLITCH_FILTER_DIS_POS)

/*
 * aux1_i23c_timeout_en
 * Timeout detection enabling for SIFS AUX1 IxC slave.
 */
#define REG_INTF_CONFIG0_AUX1_I23C_TIMEOUT_EN_POS      0x07
#define REG_INTF_CONFIG0_AUX1_I23C_TIMEOUT_EN_MASK     (0x01 << REG_INTF_CONFIG0_AUX1_I23C_TIMEOUT_EN_POS)



/*
 * REG_INTF_CONFIG1_OVRD
 * Register Name : INTF_CONFIG1_OVRD
 */

/*
 * ap_spi_mode_ovrd_val
 * Override value for SPI Mode based on CPOL and CPHA
 * 0 : spi_mode0 or spi_mode3
 * 1: spi_mode1 or spi_mode2
 * No change is expected from default mode when IxC slave is selected for host serial transfer.
 */
#define REG_INTF_CONFIG1_OVRD_AP_SPI_MODE_OVRD_VAL_POS      0x00
#define REG_INTF_CONFIG1_OVRD_AP_SPI_MODE_OVRD_VAL_MASK     0x01

/*
 * ap_spi_mode_ovrd
 * Override enable for spi_mode register value
 */
#define REG_INTF_CONFIG1_OVRD_AP_SPI_MODE_OVRD_POS      0x01
#define REG_INTF_CONFIG1_OVRD_AP_SPI_MODE_OVRD_MASK     (0x01 << REG_INTF_CONFIG1_OVRD_AP_SPI_MODE_OVRD_POS)

/*
 * ap_spi_34_mode_ovrd_val
 * Override value for SPI4/SPI3 modes
 * 1: SPI 4 mode, use SDO pad to send data out.
 * 0: SPI 3 mode, use SDA pad to send data out.
 */
#define REG_INTF_CONFIG1_OVRD_AP_SPI_34_MODE_OVRD_VAL_POS      0x02
#define REG_INTF_CONFIG1_OVRD_AP_SPI_34_MODE_OVRD_VAL_MASK     (0x01 << REG_INTF_CONFIG1_OVRD_AP_SPI_34_MODE_OVRD_VAL_POS)

/*
 * ap_spi_34_mode_ovrd
 * Override enable for SPI4/SPI3 modes
 */
#define REG_INTF_CONFIG1_OVRD_AP_SPI_34_MODE_OVRD_POS      0x03
#define REG_INTF_CONFIG1_OVRD_AP_SPI_34_MODE_OVRD_MASK     (0x01 << REG_INTF_CONFIG1_OVRD_AP_SPI_34_MODE_OVRD_POS)



/*
 * REG_INTF_AUX_CONFIG
 * Register Name : INTF_AUX_CONFIG
 */

/*
 * aux1_spi_mode
 * SPI Mode based on CPOL and CPHA
 * 0 for AUX1 : spi_mode0 or spi_mode3
 * 1: spi_mode1 or spi_mode2
 */
#define REG_INTF_AUX_CONFIG_AUX1_SPI_MODE_POS      0x00
#define REG_INTF_AUX_CONFIG_AUX1_SPI_MODE_MASK     0x01

/*
 * aux1_spi_34_mode
 * 1: SPI 4 mode, use SDO pad to send data out for OIS1
 * 0: SPI 3 mode, use SDA pad to send data out for OIS1
 */
#define REG_INTF_AUX_CONFIG_AUX1_SPI_34_MODE_POS      0x01
#define REG_INTF_AUX_CONFIG_AUX1_SPI_34_MODE_MASK     (0x01 << REG_INTF_AUX_CONFIG_AUX1_SPI_34_MODE_POS)

/*
 * aux2_spi_mode
 * SPI Mode based on CPOL and CPHA
 * 0 for AUX2 : spi_mode0 or spi_mode3
 * 1: spi_mode1 or spi_mode2
 */
#define REG_INTF_AUX_CONFIG_AUX2_SPI_MODE_POS      0x02
#define REG_INTF_AUX_CONFIG_AUX2_SPI_MODE_MASK     (0x01 << REG_INTF_AUX_CONFIG_AUX2_SPI_MODE_POS)



/*
 * REG_IOC_PAD_SCENARIO
 * Register Name : IOC_PAD_SCENARIO
 */

/*
 * aux1_enable
 * Aux1 enable :
 * 0: AUX1 disabled
 * 1: AUX1 enabled
 */
#define REG_IOC_PAD_SCENARIO_AUX1_ENABLE_POS      0x00
#define REG_IOC_PAD_SCENARIO_AUX1_ENABLE_MASK     0x01

/*
 * aux1_mode
 * Effective only when 'aux1_enable' is '1'
 * Selects modes at which AUX1 pads could be used
 * 0: AUX1in SPI Slave
 * 1: AUX1 in I2CM Master
 * 2: AUX1 in I2CM Bypass (Enable only when AP is not in SIFS mode)
 */
#define REG_IOC_PAD_SCENARIO_AUX1_MODE_POS      0x01
#define REG_IOC_PAD_SCENARIO_AUX1_MODE_MASK     (0x03 << REG_IOC_PAD_SCENARIO_AUX1_MODE_POS)

/*
 * aux2_enable
 * Aux2 enable :
 * 0: AUX2 disabled
 * 1: AUX2 enabled
 */
#define REG_IOC_PAD_SCENARIO_AUX2_ENABLE_POS      0x03
#define REG_IOC_PAD_SCENARIO_AUX2_ENABLE_MASK     (0x01 << REG_IOC_PAD_SCENARIO_AUX2_ENABLE_POS)

/*
 * pads_int2_cfg
 * Effective only when 'aux2_enable' is 0.  Selects how INT2 pads are used
 * 0 : INT2 is selected
 * 1 : FSYNC is selected
 * 2 : CLKIN is selected
 * 3 : DRDY_INTR is selected
 */
#define REG_IOC_PAD_SCENARIO_PADS_INT2_CFG_POS      0x04
#define REG_IOC_PAD_SCENARIO_PADS_INT2_CFG_MASK     (0x03 << REG_IOC_PAD_SCENARIO_PADS_INT2_CFG_POS)

/*
 * pads_drdy_passthrough
 * Effective only when 'ioc_pads_int2_cfg' is value '3' (DRDY_INTR is selected) and AP_SIFS is not in SPI mode
 * 0: drdy_intr as normal operation
 * 1 : drdy_intr is passthrough to INT1
 */
#define REG_IOC_PAD_SCENARIO_PADS_DRDY_PASSTHROUGH_POS      0x06
#define REG_IOC_PAD_SCENARIO_PADS_DRDY_PASSTHROUGH_MASK     (0x01 << REG_IOC_PAD_SCENARIO_PADS_DRDY_PASSTHROUGH_POS)



/*
 * REG_IOC_PAD_SCENARIO_AUX_OVRD
 * Register Name : IOC_PAD_SCENARIO_AUX_OVRD
 */

/*
 * aux1_enable_ovrd_val
 * Override value for Aux1 enable :
 * 0: AUX1 disabled
 * 1: AUX1 enabled
 */
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_ENABLE_OVRD_VAL_POS      0x00
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_ENABLE_OVRD_VAL_MASK     0x01

/*
 * aux1_enable_ovrd
 * Override enable for aux1_enable
 */
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_ENABLE_OVRD_POS      0x01
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_ENABLE_OVRD_MASK     (0x01 << REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_ENABLE_OVRD_POS)

/*
 * aux1_mode_ovrd_val
 * Override value: Effective only when 'aux1_enable' is '1'
 * Selects modes at which AUX1 pads could be used
 * 0: AUX1in SPI Slave
 * 1: AUX1 in I2CM Master
 * 2: AUX1 in I2CM Bypass (Enable only when AP is not in SIFS mode)
 */
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_MODE_OVRD_VAL_POS      0x02
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_MODE_OVRD_VAL_MASK     (0x03 << REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_MODE_OVRD_VAL_POS)

/*
 * aux1_mode_ovrd
 * Override enable for aux1_mode
 */
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_MODE_OVRD_POS      0x04
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_MODE_OVRD_MASK     (0x01 << REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX1_MODE_OVRD_POS)

/*
 * aux2_enable_ovrd_val
 * Override value: Aux2 enable :
 * 0: AUX2 disabled
 * 1: AUX2 enabled
 */
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX2_ENABLE_OVRD_VAL_POS      0x05
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX2_ENABLE_OVRD_VAL_MASK     (0x01 << REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX2_ENABLE_OVRD_VAL_POS)

/*
 * aux2_enable_ovrd
 * Override enable for aux2_enable
 */
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX2_ENABLE_OVRD_POS      0x06
#define REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX2_ENABLE_OVRD_MASK     (0x01 << REG_IOC_PAD_SCENARIO_AUX_OVRD_AUX2_ENABLE_OVRD_POS)



/*
 * REG_IOC_PAD_SCENARIO_OVRD
 * Register Name : IOC_PAD_SCENARIO_OVRD
 */

/*
 * pads_int2_cfg_ovrd_val
 * Override value: Effective only when 'aux2_enable' is 0.  Selects how INT2 pads are used
 * 0 : INT2 is selected
 * 1 : FSYNC is selected
 * 2 : CLKIN is selected
 * 3 : DRDY_INTR is selected
 */
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_INT2_CFG_OVRD_VAL_POS      0x00
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_INT2_CFG_OVRD_VAL_MASK     0x03

/*
 * pads_int2_cfg_ovrd
 * Override enable for ioc_pads_int2_cfg
 */
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_INT2_CFG_OVRD_POS      0x02
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_INT2_CFG_OVRD_MASK     (0x01 << REG_IOC_PAD_SCENARIO_OVRD_PADS_INT2_CFG_OVRD_POS)

/*
 * pads_drdy_passthrough_ovrd_val
 * Override value: Effective only when 'ioc_pads_int2_cfg' is value '3' (DRDY_INTR is selected) and AP_SIFS is not in SPI mode
 * 0: drdy_intr as normal operation
 * 1 : drdy_intr is passthrough to INT1
 */
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_DRDY_PASSTHROUGH_OVRD_VAL_POS      0x03
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_DRDY_PASSTHROUGH_OVRD_VAL_MASK     (0x01 << REG_IOC_PAD_SCENARIO_OVRD_PADS_DRDY_PASSTHROUGH_OVRD_VAL_POS)

/*
 * pads_drdy_passthrough_ovrd
 * Override enable for ioc_pads_drdy_passthrough
 */
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_DRDY_PASSTHROUGH_OVRD_POS      0x04
#define REG_IOC_PAD_SCENARIO_OVRD_PADS_DRDY_PASSTHROUGH_OVRD_MASK     (0x01 << REG_IOC_PAD_SCENARIO_OVRD_PADS_DRDY_PASSTHROUGH_OVRD_POS)



/*
 * REG_DRIVE_CONFIG0
 * Register Name : DRIVE_CONFIG0
 */

/*
 * virtual_access_aux2_en
 * Virtual access DTP aux2 enable
 * 1 : UI/AP take control of AUX2 interface
 * When the aux2 virtual address mode is enabled, the accessing from the SIFS_AUX2 interface is not supported.
 */
#define REG_DRIVE_CONFIG0_VIRTUAL_ACCESS_AUX2_EN_POS      0x00
#define REG_DRIVE_CONFIG0_VIRTUAL_ACCESS_AUX2_EN_MASK     0x01

/*
 * pads_spi_slew
 * Slew when chip is in SPI protocol. After chip reset, the reg_pads_i2c_slew is used by default.
 * The register setting takes effect at 1.5us after the LSBit is received.
 */
#define REG_DRIVE_CONFIG0_PADS_SPI_SLEW_POS      0x01
#define REG_DRIVE_CONFIG0_PADS_SPI_SLEW_MASK     (0x07 << REG_DRIVE_CONFIG0_PADS_SPI_SLEW_POS)

/*
 * pads_i2c_slew
 * Slew when I2C Legacy slave is selected or when I3C is operating as I2C slave
 * Slew when chip is in I2C protocol. After chip reset, the pads_i2c_slew is used by default. If the 1st operation from host is a SPI transaction, then chip automatically switches to pads_spi_slew automatically. If I3C feature is enabled, chip automatically switches to use pads_sdr_slew after receiving 0x7E+W message (an I3C broadcast message).  The register setting takes effect at 1.5us after the LSBit is received.
 *
 */
#define REG_DRIVE_CONFIG0_PADS_I2C_SLEW_POS      0x04
#define REG_DRIVE_CONFIG0_PADS_I2C_SLEW_MASK     (0x07 << REG_DRIVE_CONFIG0_PADS_I2C_SLEW_POS)



/*
 * REG_DRIVE_CONFIG1
 * Register Name : DRIVE_CONFIG1
 */

/*
 * pads_i3c_sdr_slew
 * Slew when chip is in I3C SDR protocol. After chip reset, the reg_pads_i2c_slew is used by default. If I3C feature is enabled, chip automatically switches to use reg_pads_sdr_slew after receiving 0x7E+W message (an I3C broadcast message). The register setting takes effect at 1.5us after the LSBit is received.
 */
#define REG_DRIVE_CONFIG1_PADS_I3C_SDR_SLEW_POS      0x00
#define REG_DRIVE_CONFIG1_PADS_I3C_SDR_SLEW_MASK     0x07

/*
 * pads_i3c_ddr_slew
 * Slew when chip is in I3C DDR protocol. While in I3C operation, chip automatically switches to use reg_pads_ddr_slew after receiving ENTHDR0 ccc command from host. And chip automatically switches back to reg_pads_sdr_slew after host issues HDR_EXIT pattern. The register setting takes effect at 1.5us after the LSBit is received.
 */
#define REG_DRIVE_CONFIG1_PADS_I3C_DDR_SLEW_POS      0x03
#define REG_DRIVE_CONFIG1_PADS_I3C_DDR_SLEW_MASK     (0x07 << REG_DRIVE_CONFIG1_PADS_I3C_DDR_SLEW_POS)



/*
 * REG_DRIVE_CONFIG2
 * Register Name : DRIVE_CONFIG2
 */

/*
 * pads_slew
 * Slew in all modes (SPI3, SPI4, I2C, I3C) when chip is in OTP-copy operation. Whenever chip is in OTP copy operation, reg_pads_slew is used to control SDO/SDIO pad. After OTP copy is done, the reg_pads_i2c_slew is used by default . If the 1st operation from host is a SPI transaction, then chip switches to pads_spi_slew automatically. The register setting takes effect at 1.5us after the LSBit is received.
 */
#define REG_DRIVE_CONFIG2_PADS_SLEW_POS      0x00
#define REG_DRIVE_CONFIG2_PADS_SLEW_MASK     0x07



/*
 * REG_REG_MISC1
 * Register Name : REG_MISC1
 */

/*
 * osc_id_ovrd
 * Overrides the oscillator ID request (debug feature).  Use this register to select the external clock as the MCLK source.
 * [0] = 1: Requests the EDOSC.
 * [1] = 1: Requests the RCOSC.
 * [2] = 1: Requests the PLL, if it is enabled.
 * [3] = 1: Requests the external clock.
 * The selected clock source is the highest index that's requested and that is ready.
 */
#define REG_REG_MISC1_OSC_ID_OVRD_POS      0x00
#define REG_REG_MISC1_OSC_ID_OVRD_MASK     0x0f

/*
 * REG_REG_MISC3
 * Register Name : REG_MISC3
 */

/*
 * wakeup_mclk
 * Asynchronous wake-up of the MCLK (debug feature).
 */
#define REG_REG_MISC3_WAKEUP_MCLK_POS      0x00
#define REG_REG_MISC3_WAKEUP_MCLK_MASK     0x01

/*
 * edosc_force_on
 * [Supports Dynamic Change] Forces the EDOSC (oscillator 0) to be enabled.
 */
#define REG_REG_MISC3_EDOSC_FORCE_ON_POS      0x03
#define REG_REG_MISC3_EDOSC_FORCE_ON_MASK     (0x01 << REG_REG_MISC3_EDOSC_FORCE_ON_POS)



/*
 * REG_INT_APEX_CONFIG0
 * Register Name : INT_APEX_CONFIG0
 */

/*
 * int_status_mask_pin_tap_detect
 *
 * "For edmp_out interface, Indicates if Tap detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_TAP_DETECT_POS      0x00
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_TAP_DETECT_MASK     0x01

/*
 * int_status_mask_pin_high_g_det
 *
 * "For edmp_out interface, Indicates if highG detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_HIGH_G_DET_POS      0x01
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_HIGH_G_DET_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_HIGH_G_DET_POS)

/*
 * int_status_mask_pin_low_g_det
 *
 * "For edmp_out interface, Indicates if lowG detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_LOW_G_DET_POS      0x02
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_LOW_G_DET_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_LOW_G_DET_POS)

/*
 * int_status_mask_pin_tilt_det
 *
 * "For edmp_out interface, Indicates if tilt detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_TILT_DET_POS      0x03
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_TILT_DET_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_TILT_DET_POS)

/*
 * int_status_mask_pin_step_cnt_ovfl
 *
 * "For edmp_out interface,Indicates if step count overflow interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_STEP_CNT_OVFL_POS      0x04
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_STEP_CNT_OVFL_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_STEP_CNT_OVFL_POS)

/*
 * int_status_mask_pin_step_det
 *
 * "For edmp_out interface, Indicates if step detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_STEP_DET_POS      0x05
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_STEP_DET_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_STEP_DET_POS)

/*
 * int_status_mask_pin_ff_det
 *
 * "For edmp_out interface, Indicates if freefall interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_FF_DET_POS      0x06
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_FF_DET_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_FF_DET_POS)

/*
 * int_status_mask_pin_r2w_wake_det
 *
 * "For edmp_out interface, Indicates if raise to wake wake detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_R2W_WAKE_DET_POS      0x07
#define REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_R2W_WAKE_DET_MASK     (0x01 << REG_INT_APEX_CONFIG0_INT_STATUS_MASK_PIN_R2W_WAKE_DET_POS)



/*
 * REG_INT_APEX_CONFIG1
 * Register Name : INT_APEX_CONFIG1
 */

/*
 * int_status_mask_pin_r2w_sleep_det
 *
 * "For edmp_out interface, Indicates if raise to wake sleep detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_R2W_SLEEP_DET_POS      0x00
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_R2W_SLEEP_DET_MASK     0x01

/*
 * int_status_mask_pin_smd_det
 * "For edmp_out interface, Indicates if significant motion detection interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SMD_DET_POS      0x01
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SMD_DET_MASK     (0x01 << REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SMD_DET_POS)

/*
 * int_status_mask_pin_selftest_done
 *
 * "For edmp_out interface, Indicates if self-test done interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SELFTEST_DONE_POS      0x02
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SELFTEST_DONE_MASK     (0x01 << REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SELFTEST_DONE_POS)

/*
 * int_status_mask_pin_selfcalib_done
 *
 * "For edmp_out interface, Indicates if self-calibration done interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SELFCALIB_DONE_POS      0x03
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SELFCALIB_DONE_MASK     (0x01 << REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SELFCALIB_DONE_POS)

/*
 * int_status_mask_pin_sa_done
 *
 * "For edmp_out interface, secure authentication done interrupt is masked
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SA_DONE_POS      0x04
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SA_DONE_MASK     (0x01 << REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_SA_DONE_POS)

/*
 * int_status_mask_pin_reserved1
 *
 * "For edmp_out interface, Indicates if 14th bit from edmp reserved is masked,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_RESERVED1_POS      0x05
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_RESERVED1_MASK     (0x01 << REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_RESERVED1_POS)

/*
 * int_status_mask_pin_reserved2
 *
 * "For edmp_out interface, Indicates if 15th bit from edmp reservedt is masked,
 * 1: the occurrance of interrupt source event will not assert the assigned interrupt pin.
 * 0: the occurance of interrupt source event will assert the assigned interrupt pin. "
 *
 *
 */
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_RESERVED2_POS      0x06
#define REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_RESERVED2_MASK     (0x01 << REG_INT_APEX_CONFIG1_INT_STATUS_MASK_PIN_RESERVED2_POS)



/*
 * REG_INT_APEX_STATUS0
 * Register Name : INT_APEX_STATUS0
 */

/*
 * int_status_tap_detect
 * For edmp_out Interface. Indicates if status register(ISR) for Tap detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_TAP_DETECT_POS      0x00
#define REG_INT_APEX_STATUS0_INT_STATUS_TAP_DETECT_MASK     0x01

/*
 * int_status_high_g_det
 * For edmp_out Interface. Indicates if status register(ISR) for highG detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_HIGH_G_DET_POS      0x01
#define REG_INT_APEX_STATUS0_INT_STATUS_HIGH_G_DET_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_HIGH_G_DET_POS)

/*
 * int_status_low_g_det
 * For edmp_out Interface. Indicates if status register(ISR) for lowG detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_LOW_G_DET_POS      0x02
#define REG_INT_APEX_STATUS0_INT_STATUS_LOW_G_DET_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_LOW_G_DET_POS)

/*
 * int_status_tilt_det
 * For edmp_out Interface. Indicates if status register(ISR) for tilt detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_TILT_DET_POS      0x03
#define REG_INT_APEX_STATUS0_INT_STATUS_TILT_DET_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_TILT_DET_POS)

/*
 * int_status_step_cnt_ovfl
 * For edmp_out Interface. Indicates if status register(ISR) for step count overflow interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_STEP_CNT_OVFL_POS      0x04
#define REG_INT_APEX_STATUS0_INT_STATUS_STEP_CNT_OVFL_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_STEP_CNT_OVFL_POS)

/*
 * int_status_step_det
 * For edmp_out Interface. Indicates if status register(ISR) for step detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_STEP_DET_POS      0x05
#define REG_INT_APEX_STATUS0_INT_STATUS_STEP_DET_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_STEP_DET_POS)

/*
 * int_status_ff_det
 * For edmp_out Interface. Indicates if status register(ISR) for freefall interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_FF_DET_POS      0x06
#define REG_INT_APEX_STATUS0_INT_STATUS_FF_DET_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_FF_DET_POS)

/*
 * int_status_r2w_wake_det
 * For edmp_out Interface. Indicates if status register(ISR) for raise to wake wake detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS0_INT_STATUS_R2W_WAKE_DET_POS      0x07
#define REG_INT_APEX_STATUS0_INT_STATUS_R2W_WAKE_DET_MASK     (0x01 << REG_INT_APEX_STATUS0_INT_STATUS_R2W_WAKE_DET_POS)



/*
 * REG_INT_APEX_STATUS1
 * Register Name : INT_APEX_STATUS1
 */

/*
 * int_status_r2w_sleep_det
 * For edmp_out Interface. Indicates if status register(ISR) for raise to wake sleep detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_R2W_SLEEP_DET_POS      0x00
#define REG_INT_APEX_STATUS1_INT_STATUS_R2W_SLEEP_DET_MASK     0x01

/*
 * int_status_smd_det
 * For edmp_out Interface. Indicates if status register(ISR) for signif status register(ISR) foricant motion detection interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_SMD_DET_POS      0x01
#define REG_INT_APEX_STATUS1_INT_STATUS_SMD_DET_MASK     (0x01 << REG_INT_APEX_STATUS1_INT_STATUS_SMD_DET_POS)

/*
 * int_status_selftest_done
 * For edmp_out Interface. Indicates if status register(ISR) for self-test done interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_SELFTEST_DONE_POS      0x02
#define REG_INT_APEX_STATUS1_INT_STATUS_SELFTEST_DONE_MASK     (0x01 << REG_INT_APEX_STATUS1_INT_STATUS_SELFTEST_DONE_POS)

/*
 * int_status_selfcalib_done
 * For edmp_out Interface. Indicates if status register(ISR) for self-calibration done interrupt is set
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_SELFCALIB_DONE_POS      0x03
#define REG_INT_APEX_STATUS1_INT_STATUS_SELFCALIB_DONE_MASK     (0x01 << REG_INT_APEX_STATUS1_INT_STATUS_SELFCALIB_DONE_POS)

/*
 * int_status_sa_done
 * For edmp_out Interface. Indicates if status register(ISR) for secure authentication done interrupt is set
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_SA_DONE_POS      0x04
#define REG_INT_APEX_STATUS1_INT_STATUS_SA_DONE_MASK     (0x01 << REG_INT_APEX_STATUS1_INT_STATUS_SA_DONE_POS)

/*
 * int_status_reserved1
 * -status register (ISR) for 14th bit from edmp reserved
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_RESERVED1_POS      0x05
#define REG_INT_APEX_STATUS1_INT_STATUS_RESERVED1_MASK     (0x01 << REG_INT_APEX_STATUS1_INT_STATUS_RESERVED1_POS)

/*
 * int_status_reserved2
 * -status register (ISR) for 15th bit from edmp reserved
 *
 * 1: For edmp_out Interface. Indicates status set.
 * 0: For edmp_out Interface. Indicates status not set.
 */
#define REG_INT_APEX_STATUS1_INT_STATUS_RESERVED2_POS      0x06
#define REG_INT_APEX_STATUS1_INT_STATUS_RESERVED2_MASK     (0x01 << REG_INT_APEX_STATUS1_INT_STATUS_RESERVED2_POS)



/*
 * REG_INTF_CONFIG_OVRD_AUX1
 * Register Name : INTF_CONFIG_OVRD_AUX1
 */

/*
 * aux1_spi_mode_ovrd_val
 * Override value for SPI Mode based on CPOL and CPHA
 * 0 for aux1 : spi_mode0 or spi_mode3
 * 1: spi_mode1 or spi_mode2
 * No change is expected from default mode when IxC slave is selected for host serial transfer.
 */
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_MODE_OVRD_VAL_POS      0x00
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_MODE_OVRD_VAL_MASK     0x01

/*
 * aux1_spi_mode_ovrd
 * Override enable for spi_mode register value for aux1
 */
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_MODE_OVRD_POS      0x01
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_MODE_OVRD_MASK     (0x01 << REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_MODE_OVRD_POS)

/*
 * aux1_spi_34_mode_ovrd_val
 * Override value for SPI4/SPI3 modes for OIS1
 * 1: SPI 4 mode, use SDO pad to send data out.
 * 0: SPI 3 mode, use SDA pad to send data out.
 */
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_34_MODE_OVRD_VAL_POS      0x02
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_34_MODE_OVRD_VAL_MASK     (0x01 << REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_34_MODE_OVRD_VAL_POS)

/*
 * aux1_spi_34_mode_ovrd
 * Override enable for SPI4/SPI3 modes for OIS1
 */
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_34_MODE_OVRD_POS      0x03
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_34_MODE_OVRD_MASK     (0x01 << REG_INTF_CONFIG_OVRD_AUX1_AUX1_SPI_34_MODE_OVRD_POS)

/*
 * aux1_ireg_auto_addr_inc_dis
 * This register controls the address auto-increment operation of the 32-bit indirect address when accessing reg_ireg_data from serial interface of AUX1
 * 0: Disable address auto-increment operation to the 32-bit address.
 * 1: Enable address auto-increment operation to the 32-bit address.
 *
 * In write operation, the 32-bit address is auto-incremented by 1 after write to ireg_data is completed.
 * In read operation, the 32-bit address is auto-incremented by 1 after ireg_data read return data is captured into SCLK-domain read-buffer residing in serial interface block.
 * The address auto increment operation stops when the 32-bit address = 0xFFFF_FFFF. Or when write to ireg_addr* occurs.
 */
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_IREG_AUTO_ADDR_INC_DIS_POS      0x04
#define REG_INTF_CONFIG_OVRD_AUX1_AUX1_IREG_AUTO_ADDR_INC_DIS_MASK     (0x01 << REG_INTF_CONFIG_OVRD_AUX1_AUX1_IREG_AUTO_ADDR_INC_DIS_POS)



/*
 * REG_ACCEL_DATA_X_AUX1_0
 * Register Name : ACCEL_DATA_X_AUX1_0
 */

/*
 * accel_data_x_aux1
 * Accel X axis data for OIS1 path
 */
#define REG_ACCEL_DATA_X_AUX1_0_ACCEL_DATA_X_AUX1_POS      0x00
#define REG_ACCEL_DATA_X_AUX1_0_ACCEL_DATA_X_AUX1_MASK     0xff



/*
 * REG_ACCEL_DATA_X_AUX1_1
 * Register Name : ACCEL_DATA_X_AUX1_1
 */

/*
 * accel_data_x_aux1
 * Accel X axis data for OIS1 path
 */
#define REG_ACCEL_DATA_X_AUX1_1_ACCEL_DATA_X_AUX1_POS      0x00
#define REG_ACCEL_DATA_X_AUX1_1_ACCEL_DATA_X_AUX1_MASK     0xff



/*
 * REG_ACCEL_DATA_Y_AUX1_0
 * Register Name : ACCEL_DATA_Y_AUX1_0
 */

/*
 * accel_data_y_aux1
 * Accel Y axis data for OIS1 path
 */
#define REG_ACCEL_DATA_Y_AUX1_0_ACCEL_DATA_Y_AUX1_POS      0x00
#define REG_ACCEL_DATA_Y_AUX1_0_ACCEL_DATA_Y_AUX1_MASK     0xff



/*
 * REG_ACCEL_DATA_Y_AUX1_1
 * Register Name : ACCEL_DATA_Y_AUX1_1
 */

/*
 * accel_data_y_aux1
 * Accel Y axis data for OIS1 path
 */
#define REG_ACCEL_DATA_Y_AUX1_1_ACCEL_DATA_Y_AUX1_POS      0x00
#define REG_ACCEL_DATA_Y_AUX1_1_ACCEL_DATA_Y_AUX1_MASK     0xff



/*
 * REG_ACCEL_DATA_Z_AUX1_0
 * Register Name : ACCEL_DATA_Z_AUX1_0
 */

/*
 * accel_data_z_aux1
 * Accel Z axis data for OIS1 path
 */
#define REG_ACCEL_DATA_Z_AUX1_0_ACCEL_DATA_Z_AUX1_POS      0x00
#define REG_ACCEL_DATA_Z_AUX1_0_ACCEL_DATA_Z_AUX1_MASK     0xff



/*
 * REG_ACCEL_DATA_Z_AUX1_1
 * Register Name : ACCEL_DATA_Z_AUX1_1
 */

/*
 * accel_data_z_aux1
 * Accel Z axis data for OIS1 path
 */
#define REG_ACCEL_DATA_Z_AUX1_1_ACCEL_DATA_Z_AUX1_POS      0x00
#define REG_ACCEL_DATA_Z_AUX1_1_ACCEL_DATA_Z_AUX1_MASK     0xff



/*
 * REG_GYRO_DATA_X_AUX1_0
 * Register Name : GYRO_DATA_X_AUX1_0
 */

/*
 * gyro_data_x_aux1
 * Gyro X axis data for OIS1 path
 */
#define REG_GYRO_DATA_X_AUX1_0_GYRO_DATA_X_AUX1_POS      0x00
#define REG_GYRO_DATA_X_AUX1_0_GYRO_DATA_X_AUX1_MASK     0xff



/*
 * REG_GYRO_DATA_X_AUX1_1
 * Register Name : GYRO_DATA_X_AUX1_1
 */

/*
 * gyro_data_x_aux1
 * Gyro X axis data for OIS1 path
 */
#define REG_GYRO_DATA_X_AUX1_1_GYRO_DATA_X_AUX1_POS      0x00
#define REG_GYRO_DATA_X_AUX1_1_GYRO_DATA_X_AUX1_MASK     0xff



/*
 * REG_GYRO_DATA_Y_AUX1_0
 * Register Name : GYRO_DATA_Y_AUX1_0
 */

/*
 * gyro_data_y_aux1
 * Gyro Y axis data for OIS1 path
 */
#define REG_GYRO_DATA_Y_AUX1_0_GYRO_DATA_Y_AUX1_POS      0x00
#define REG_GYRO_DATA_Y_AUX1_0_GYRO_DATA_Y_AUX1_MASK     0xff



/*
 * REG_GYRO_DATA_Y_AUX1_1
 * Register Name : GYRO_DATA_Y_AUX1_1
 */

/*
 * gyro_data_y_aux1
 * Gyro Y axis data for OIS1 path
 */
#define REG_GYRO_DATA_Y_AUX1_1_GYRO_DATA_Y_AUX1_POS      0x00
#define REG_GYRO_DATA_Y_AUX1_1_GYRO_DATA_Y_AUX1_MASK     0xff



/*
 * REG_GYRO_DATA_Z_AUX1_0
 * Register Name : GYRO_DATA_Z_AUX1_0
 */

/*
 * gyro_data_z_aux1
 * Gyro Z axis data for OIS1 path
 */
#define REG_GYRO_DATA_Z_AUX1_0_GYRO_DATA_Z_AUX1_POS      0x00
#define REG_GYRO_DATA_Z_AUX1_0_GYRO_DATA_Z_AUX1_MASK     0xff



/*
 * REG_GYRO_DATA_Z_AUX1_1
 * Register Name : GYRO_DATA_Z_AUX1_1
 */

/*
 * gyro_data_z_aux1
 * Gyro Z axis data for OIS1 path
 */
#define REG_GYRO_DATA_Z_AUX1_1_GYRO_DATA_Z_AUX1_POS      0x00
#define REG_GYRO_DATA_Z_AUX1_1_GYRO_DATA_Z_AUX1_MASK     0xff



/*
 * REG_TEMP_DATA_AUX1_0
 * Register Name : TEMP_DATA_AUX1_0
 */

/*
 * temp_data_aux1
 * Temperature data for OIS1 path
 */
#define REG_TEMP_DATA_AUX1_0_TEMP_DATA_AUX1_POS      0x00
#define REG_TEMP_DATA_AUX1_0_TEMP_DATA_AUX1_MASK     0xff



/*
 * REG_TEMP_DATA_AUX1_1
 * Register Name : TEMP_DATA_AUX1_1
 */

/*
 * temp_data_aux1
 * Temperature data for OIS1 path
 */
#define REG_TEMP_DATA_AUX1_1_TEMP_DATA_AUX1_POS      0x00
#define REG_TEMP_DATA_AUX1_1_TEMP_DATA_AUX1_MASK     0xff



/*
 * REG_TMST_FSYNC_DATA_AUX1_0
 * Register Name : TMST_FSYNC_DATA_AUX1_0
 */

/*
 * tmst_fsync_data_aux1
 * Timestamp/FSYNC data for OIS1 path
 */
#define REG_TMST_FSYNC_DATA_AUX1_0_TMST_FSYNC_DATA_AUX1_POS      0x00
#define REG_TMST_FSYNC_DATA_AUX1_0_TMST_FSYNC_DATA_AUX1_MASK     0xff



/*
 * REG_TMST_FSYNC_DATA_AUX1_1
 * Register Name : TMST_FSYNC_DATA_AUX1_1
 */

/*
 * tmst_fsync_data_aux1
 * Timestamp/FSYNC data for OIS1 path
 */
#define REG_TMST_FSYNC_DATA_AUX1_1_TMST_FSYNC_DATA_AUX1_POS      0x00
#define REG_TMST_FSYNC_DATA_AUX1_1_TMST_FSYNC_DATA_AUX1_MASK     0xff



/*
 * REG_PWR_MGMT_AUX1
 * Register Name : PWR_MGMT_AUX1
 */

/*
 * accel_aux1_en
 * [Supports Dynamic Change] Enable the OIS1 interface for the Accelerometer sensor.
 *   0: OFF
 *   1: ON
 */
#define REG_PWR_MGMT_AUX1_ACCEL_AUX1_EN_POS      0x00
#define REG_PWR_MGMT_AUX1_ACCEL_AUX1_EN_MASK     0x01

/*
 * gyro_aux1_en
 * [Supports Dynamic Change] Enable the OIS1 interface for the Gyroscope sensor.
 *   0: OFF
 *   1: ON
 */
#define REG_PWR_MGMT_AUX1_GYRO_AUX1_EN_POS      0x01
#define REG_PWR_MGMT_AUX1_GYRO_AUX1_EN_MASK     (0x01 << REG_PWR_MGMT_AUX1_GYRO_AUX1_EN_POS)

/*
 * accel_aux1_status_pm
 * Accelerometer Power-Mode status for the OIS1 FIFO
 */
#define REG_PWR_MGMT_AUX1_ACCEL_AUX1_STATUS_PM_POS      0x02
#define REG_PWR_MGMT_AUX1_ACCEL_AUX1_STATUS_PM_MASK     (0x01 << REG_PWR_MGMT_AUX1_ACCEL_AUX1_STATUS_PM_POS)

/*
 * gyro_aux1_status_pm
 * Gyroscope Power-Mode status for the OIS1 FIFO
 */
#define REG_PWR_MGMT_AUX1_GYRO_AUX1_STATUS_PM_POS      0x03
#define REG_PWR_MGMT_AUX1_GYRO_AUX1_STATUS_PM_MASK     (0x01 << REG_PWR_MGMT_AUX1_GYRO_AUX1_STATUS_PM_POS)



/*
 * REG_FS_SEL_AUX1
 * Register Name : FS_SEL_AUX1
 */

/*
 * aux1_accel_fs_sel
 * [Supports Dynamic Change] Set the OIS1 signal path accel full scale
 * 0 : 32 gee
 * 1 : 16 gee
 * 2 : 8 gee
 * 3 :4 gee
 * 4 : 2 gee
 */
#define REG_FS_SEL_AUX1_AUX1_ACCEL_FS_SEL_POS      0x00
#define REG_FS_SEL_AUX1_AUX1_ACCEL_FS_SEL_MASK     0x07

/*
 * aux1_gyro_fs_sel
 * [Supports Dynamic Change] Set the OIS1 signal path gyro full scale
 * 0 : 4000 dps
 * 1 : 2000 dps
 * 2 : 1000 dps
 * 3 : 500 dps
 * 4 : 250 dps
 * 5 : 125 dps
 * 6 : 62.5 dps
 * 7 : 31.25 dps
 * 8 : 15.625 dps
 */
#define REG_FS_SEL_AUX1_AUX1_GYRO_FS_SEL_POS      0x03
#define REG_FS_SEL_AUX1_AUX1_GYRO_FS_SEL_MASK     (0x0f << REG_FS_SEL_AUX1_AUX1_GYRO_FS_SEL_POS)



/*
 * REG_INT2_CONFIG0
 * Register Name : INT2_CONFIG0
 */

/*
 * int2_status_en_fifo_full
 * For UI/AP interface, source enable register for FIFO full interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).   "
 *
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_FIFO_FULL_POS      0x00
#define REG_INT2_CONFIG0_INT2_STATUS_EN_FIFO_FULL_MASK     0x01

/*
 * int2_status_en_fifo_ths
 * For UI/AP interface, source enable register for FIFO count ≥ FIFO threshold interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_FIFO_THS_POS      0x01
#define REG_INT2_CONFIG0_INT2_STATUS_EN_FIFO_THS_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_FIFO_THS_POS)

/*
 * int2_status_en_drdy
 * For UI/AP interface, source enable register for User Interface Sensor Register Data Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_DRDY_POS      0x02
#define REG_INT2_CONFIG0_INT2_STATUS_EN_DRDY_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_DRDY_POS)

/*
 * int2_status_en_aux1_drdy
 * For UI/AP interface, source enable register for Optical Image Stabilization Interface 1 Sensor Register Data Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AUX1_DRDY_POS      0x03
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AUX1_DRDY_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_AUX1_DRDY_POS)

/*
 * int2_status_en_ap_fsync
 * For UI/AP interface, source enable register for User Interface FSYNC interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AP_FSYNC_POS      0x04
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AP_FSYNC_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_AP_FSYNC_POS)

/*
 * int2_status_en_ap_agc_rdy
 * For UI/AP interface, source enable register for  User Interface AGC Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AP_AGC_RDY_POS      0x05
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AP_AGC_RDY_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_AP_AGC_RDY_POS)

/*
 * int2_status_en_aux1_agc_rdy
 * For UI/AP interface, source enable register for Optical Image Stabilization Interface #1 AGC Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AUX1_AGC_RDY_POS      0x06
#define REG_INT2_CONFIG0_INT2_STATUS_EN_AUX1_AGC_RDY_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_AUX1_AGC_RDY_POS)

/*
 * int2_status_en_reset_done
 * For UI/AP interface, source enable register for  Reset process is finished(after OTP copy is complete, i.e. after OTP_DONE signal)l interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG0_INT2_STATUS_EN_RESET_DONE_POS      0x07
#define REG_INT2_CONFIG0_INT2_STATUS_EN_RESET_DONE_MASK     (0x01 << REG_INT2_CONFIG0_INT2_STATUS_EN_RESET_DONE_POS)



/*
 * REG_INT2_CONFIG1
 * Register Name : INT2_CONFIG1
 */

/*
 * int2_status_en_pll_rdy
 * For UI/AP interface, source enable register for PLL is locked interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 *
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_PLL_RDY_POS      0x00
#define REG_INT2_CONFIG1_INT2_STATUS_EN_PLL_RDY_MASK     0x01

/*
 * int2_status_en_wom_x
 * For UI/AP interface, source enable register for Wake On Motion event on X axis interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_X_POS      0x01
#define REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_X_MASK     (0x01 << REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_X_POS)

/*
 * int2_status_en_wom_y
 * For UI/AP interface, source enable register for Wake On Motion event on Y axis interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_Y_POS      0x02
#define REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_Y_MASK     (0x01 << REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_Y_POS)

/*
 * int2_status_en_wom_z
 * For UI/AP interface, source enable register for Wake On Motion event on Z axis interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_Z_POS      0x03
#define REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_Z_MASK     (0x01 << REG_INT2_CONFIG1_INT2_STATUS_EN_WOM_Z_POS)

/*
 * int2_status_en_i3c_protocol_err
 * For UI/AP interface, source enable register for  I3C protocol error detected by I3C Slave interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_I3C_PROTOCOL_ERR_POS      0x04
#define REG_INT2_CONFIG1_INT2_STATUS_EN_I3C_PROTOCOL_ERR_MASK     (0x01 << REG_INT2_CONFIG1_INT2_STATUS_EN_I3C_PROTOCOL_ERR_POS)

/*
 * int2_status_en_i2cm_done
 * , For UI/AP interface, source enable register for  I2C Master operation completed interrupt.
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_I2CM_DONE_POS      0x05
#define REG_INT2_CONFIG1_INT2_STATUS_EN_I2CM_DONE_MASK     (0x01 << REG_INT2_CONFIG1_INT2_STATUS_EN_I2CM_DONE_POS)

/*
 * int2_status_en_apex_event
 *  For UI/AP interface, source enable register for  edmp event interrupt.
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT2_CONFIG1_INT2_STATUS_EN_APEX_EVENT_POS      0x06
#define REG_INT2_CONFIG1_INT2_STATUS_EN_APEX_EVENT_MASK     (0x01 << REG_INT2_CONFIG1_INT2_STATUS_EN_APEX_EVENT_POS)



/*
 * REG_INT2_CONFIG2
 * Register Name : INT2_CONFIG2
 */

/*
 * int2_polarity
 * UI/AP interface: Interrupt polarity.
 * 0: active low,
 * 1: active high,
 * Setting can be changed only when all interrupts of the corresponding serial interface are disabled.
 */
#define REG_INT2_CONFIG2_INT2_POLARITY_POS      0x00
#define REG_INT2_CONFIG2_INT2_POLARITY_MASK     0x01

/*
 * int2_mode
 * "UI/AP interface: Interrupt mode.
 * 0: pulse mode,
 * 1: latch mode,
 * Setting can be changed only when all interrupts of the corresponding serial interface are disabled."
 *
 */
#define REG_INT2_CONFIG2_INT2_MODE_POS      0x01
#define REG_INT2_CONFIG2_INT2_MODE_MASK     (0x01 << REG_INT2_CONFIG2_INT2_MODE_POS)

/*
 * int2_drive
 * Sets INT1 PAD in to Open-drain or Push-pull
 * 1 : Open-drain
 * 0 : Push-pull
 */
#define REG_INT2_CONFIG2_INT2_DRIVE_POS      0x02
#define REG_INT2_CONFIG2_INT2_DRIVE_MASK     (0x01 << REG_INT2_CONFIG2_INT2_DRIVE_POS)



/*
 * REG_INT2_STATUS0
 * Register Name : INT2_STATUS0
 */

/*
 * int2_status_fifo_full
 * For UI/AP interface, Indicates if status register (ISR) for FIFO full interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_FIFO_FULL_POS      0x00
#define REG_INT2_STATUS0_INT2_STATUS_FIFO_FULL_MASK     0x01

/*
 * int2_status_fifo_ths
 * For UI/AP interface, Indicates if status register (ISR) for FIFO count ≥ FIFO threshold interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_FIFO_THS_POS      0x01
#define REG_INT2_STATUS0_INT2_STATUS_FIFO_THS_MASK     (0x01 << REG_INT2_STATUS0_INT2_STATUS_FIFO_THS_POS)

/*
 * int2_stastus_drdy
 * For UI/AP interface, Indicates if status register (ISR) for User Interface Sensor Register Data Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STASTUS_DRDY_POS      0x02
#define REG_INT2_STATUS0_INT2_STASTUS_DRDY_MASK     (0x01 << REG_INT2_STATUS0_INT2_STASTUS_DRDY_POS)

/*
 * int2_status_aux1_drdy
 * For UI/AP interface, Indicates if status register (ISR) for Optical Image Stabilization Interface 1 Sensor Register Data Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_AUX1_DRDY_POS      0x03
#define REG_INT2_STATUS0_INT2_STATUS_AUX1_DRDY_MASK     (0x01 << REG_INT2_STATUS0_INT2_STATUS_AUX1_DRDY_POS)

/*
 * int2_status_ap_fsync
 * For UI/AP interface, Indicates if status register (ISR) for User Interface FSYNC interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_AP_FSYNC_POS      0x04
#define REG_INT2_STATUS0_INT2_STATUS_AP_FSYNC_MASK     (0x01 << REG_INT2_STATUS0_INT2_STATUS_AP_FSYNC_POS)

/*
 * int2_status_ap_agc_rdy
 * For UI/AP interface, Indicates if status register (ISR) for User Interface AGC Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_AP_AGC_RDY_POS      0x05
#define REG_INT2_STATUS0_INT2_STATUS_AP_AGC_RDY_MASK     (0x01 << REG_INT2_STATUS0_INT2_STATUS_AP_AGC_RDY_POS)

/*
 * int2_status_aux1_agc_rdy
 * For UI/AP interface, Indicates if status register (ISR) for Optical Image Stabilization Interface #1 AGC Ready interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_AUX1_AGC_RDY_POS      0x06
#define REG_INT2_STATUS0_INT2_STATUS_AUX1_AGC_RDY_MASK     (0x01 << REG_INT2_STATUS0_INT2_STATUS_AUX1_AGC_RDY_POS)

/*
 * int2_status_reset_done
 * For UI/AP interface, Indicates if status register (ISR) for Reset process is finished(after OTP copy is complete, i.e. after OTP_DONE signal) interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS0_INT2_STATUS_RESET_DONE_POS      0x07
#define REG_INT2_STATUS0_INT2_STATUS_RESET_DONE_MASK     (0x01 << REG_INT2_STATUS0_INT2_STATUS_RESET_DONE_POS)



/*
 * REG_INT2_STATUS1
 * Register Name : INT2_STATUS1
 */

/*
 * int2_status_pll_rdy
 * For UI/AP interface, Indicates if status register (ISR) for PLL is locked  interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_PLL_RDY_POS      0x00
#define REG_INT2_STATUS1_INT2_STATUS_PLL_RDY_MASK     0x01

/*
 * int2_status_wom_x
 * For UI/AP interface, Indicates if status register (ISR) for Wake On Motion event on X axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_WOM_X_POS      0x01
#define REG_INT2_STATUS1_INT2_STATUS_WOM_X_MASK     (0x01 << REG_INT2_STATUS1_INT2_STATUS_WOM_X_POS)

/*
 * int2_status_wom_y
 * For UI/AP interface, Indicates if status register (ISR) for Wake On Motion event on Y axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_WOM_Y_POS      0x02
#define REG_INT2_STATUS1_INT2_STATUS_WOM_Y_MASK     (0x01 << REG_INT2_STATUS1_INT2_STATUS_WOM_Y_POS)

/*
 * int2_status_wom_z
 * For UI/AP interface, Indicates if status register (ISR) for Wake On Motion event on Z axis interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_WOM_Z_POS      0x03
#define REG_INT2_STATUS1_INT2_STATUS_WOM_Z_MASK     (0x01 << REG_INT2_STATUS1_INT2_STATUS_WOM_Z_POS)

/*
 * int2_status_i3c_protocol_err
 * For UI/AP interface, Indicates if status register (ISR) for I3C protocol error detected by I3C Slave interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_I3C_PROTOCOL_ERR_POS      0x04
#define REG_INT2_STATUS1_INT2_STATUS_I3C_PROTOCOL_ERR_MASK     (0x01 << REG_INT2_STATUS1_INT2_STATUS_I3C_PROTOCOL_ERR_POS)

/*
 * int2_status_i2cm_done
 * For UI/AP interface, Indicates if status register (ISR) for I2C Master operation completed interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_I2CM_DONE_POS      0x05
#define REG_INT2_STATUS1_INT2_STATUS_I2CM_DONE_MASK     (0x01 << REG_INT2_STATUS1_INT2_STATUS_I2CM_DONE_POS)

/*
 * int2_status_apex_event
 * For UI/AP interface, Indicates if status register (ISR) for edmp eventl interrupt is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT2_STATUS1_INT2_STATUS_APEX_EVENT_POS      0x06
#define REG_INT2_STATUS1_INT2_STATUS_APEX_EVENT_MASK     (0x01 << REG_INT2_STATUS1_INT2_STATUS_APEX_EVENT_POS)



/*
 * REG_INTF_CONFIG_OVRD_AUX2
 * Register Name : INTF_CONFIG_OVRD_AUX2
 */

/*
 * aux2_spi_mode_ovrd_val
 * Override value for SPI Mode based on CPOL and CPHA
 * 0 for aux1 : spi_mode0 or spi_mode3
 * 1: spi_mode1 or spi_mode2
 * No change is expected from default mode when IxC slave is selected for host serial transfer.
 */
#define REG_INTF_CONFIG_OVRD_AUX2_AUX2_SPI_MODE_OVRD_VAL_POS      0x00
#define REG_INTF_CONFIG_OVRD_AUX2_AUX2_SPI_MODE_OVRD_VAL_MASK     0x01

/*
 * aux2_spi_mode_ovrd
 * Override enable for spi_mode register value for aux2
 */
#define REG_INTF_CONFIG_OVRD_AUX2_AUX2_SPI_MODE_OVRD_POS      0x01
#define REG_INTF_CONFIG_OVRD_AUX2_AUX2_SPI_MODE_OVRD_MASK     (0x01 << REG_INTF_CONFIG_OVRD_AUX2_AUX2_SPI_MODE_OVRD_POS)

/*
 * aux2_ireg_auto_addr_inc_dis
 * This register controls the address auto-increment operation of the 32-bit indirect address when accessing reg_ireg_data from serial interface of AUX1
 * 0: Disable address auto-increment operation to the 32-bit address.
 * 1: Enable address auto-increment operation to the 32-bit address.
 *
 * In write operation, the 32-bit address is auto-incremented by 1 after write to ireg_data is completed.
 * In read operation, the 32-bit address is auto-incremented by 1 after ireg_data read return data is captured into SCLK-domain read-buffer residing in serial interface block.
 * The address auto increment operation stops when the 32-bit address = 0xFFFF_FFFF. Or when write to ireg_addr* occurs.
 */
#define REG_INTF_CONFIG_OVRD_AUX2_AUX2_IREG_AUTO_ADDR_INC_DIS_POS      0x02
#define REG_INTF_CONFIG_OVRD_AUX2_AUX2_IREG_AUTO_ADDR_INC_DIS_MASK     (0x01 << REG_INTF_CONFIG_OVRD_AUX2_AUX2_IREG_AUTO_ADDR_INC_DIS_POS)



/*
 * REG_ACCEL_DATA_X_AUX2_0
 * Register Name : ACCEL_DATA_X_AUX2_0
 */

/*
 * accel_data_x_aux2
 * Accel X axis data for OIS2 path
 */
#define REG_ACCEL_DATA_X_AUX2_0_ACCEL_DATA_X_AUX2_POS      0x00
#define REG_ACCEL_DATA_X_AUX2_0_ACCEL_DATA_X_AUX2_MASK     0xff



/*
 * REG_ACCEL_DATA_X_AUX2_1
 * Register Name : ACCEL_DATA_X_AUX2_1
 */

/*
 * accel_data_x_aux2
 * Accel X axis data for OIS2 path
 */
#define REG_ACCEL_DATA_X_AUX2_1_ACCEL_DATA_X_AUX2_POS      0x00
#define REG_ACCEL_DATA_X_AUX2_1_ACCEL_DATA_X_AUX2_MASK     0xff



/*
 * REG_ACCEL_DATA_Y_AUX2_0
 * Register Name : ACCEL_DATA_Y_AUX2_0
 */

/*
 * accel_data_y_aux2
 * Accel Y axis data for OIS2 path
 */
#define REG_ACCEL_DATA_Y_AUX2_0_ACCEL_DATA_Y_AUX2_POS      0x00
#define REG_ACCEL_DATA_Y_AUX2_0_ACCEL_DATA_Y_AUX2_MASK     0xff



/*
 * REG_ACCEL_DATA_Y_AUX2_1
 * Register Name : ACCEL_DATA_Y_AUX2_1
 */

/*
 * accel_data_y_aux2
 * Accel Y axis data for OIS2 path
 */
#define REG_ACCEL_DATA_Y_AUX2_1_ACCEL_DATA_Y_AUX2_POS      0x00
#define REG_ACCEL_DATA_Y_AUX2_1_ACCEL_DATA_Y_AUX2_MASK     0xff



/*
 * REG_ACCEL_DATA_Z_AUX2_0
 * Register Name : ACCEL_DATA_Z_AUX2_0
 */

/*
 * accel_data_z_aux2
 * Accel Z axis data for OIS2 path
 */
#define REG_ACCEL_DATA_Z_AUX2_0_ACCEL_DATA_Z_AUX2_POS      0x00
#define REG_ACCEL_DATA_Z_AUX2_0_ACCEL_DATA_Z_AUX2_MASK     0xff



/*
 * REG_ACCEL_DATA_Z_AUX2_1
 * Register Name : ACCEL_DATA_Z_AUX2_1
 */

/*
 * accel_data_z_aux2
 * Accel Z axis data for OIS2 path
 */
#define REG_ACCEL_DATA_Z_AUX2_1_ACCEL_DATA_Z_AUX2_POS      0x00
#define REG_ACCEL_DATA_Z_AUX2_1_ACCEL_DATA_Z_AUX2_MASK     0xff



/*
 * REG_GYRO_DATA_X_AUX2_0
 * Register Name : GYRO_DATA_X_AUX2_0
 */

/*
 * gyro_data_x_aux2
 * Gyro X axis data for OIS2 path
 */
#define REG_GYRO_DATA_X_AUX2_0_GYRO_DATA_X_AUX2_POS      0x00
#define REG_GYRO_DATA_X_AUX2_0_GYRO_DATA_X_AUX2_MASK     0xff



/*
 * REG_GYRO_DATA_X_AUX2_1
 * Register Name : GYRO_DATA_X_AUX2_1
 */

/*
 * gyro_data_x_aux2
 * Gyro X axis data for OIS2 path
 */
#define REG_GYRO_DATA_X_AUX2_1_GYRO_DATA_X_AUX2_POS      0x00
#define REG_GYRO_DATA_X_AUX2_1_GYRO_DATA_X_AUX2_MASK     0xff



/*
 * REG_GYRO_DATA_Y_AUX2_0
 * Register Name : GYRO_DATA_Y_AUX2_0
 */

/*
 * gyro_data_y_aux2
 * Gyro Y axis data for OIS2 path
 */
#define REG_GYRO_DATA_Y_AUX2_0_GYRO_DATA_Y_AUX2_POS      0x00
#define REG_GYRO_DATA_Y_AUX2_0_GYRO_DATA_Y_AUX2_MASK     0xff



/*
 * REG_GYRO_DATA_Y_AUX2_1
 * Register Name : GYRO_DATA_Y_AUX2_1
 */

/*
 * gyro_data_y_aux2
 * Gyro Y axis data for OIS2 path
 */
#define REG_GYRO_DATA_Y_AUX2_1_GYRO_DATA_Y_AUX2_POS      0x00
#define REG_GYRO_DATA_Y_AUX2_1_GYRO_DATA_Y_AUX2_MASK     0xff



/*
 * REG_GYRO_DATA_Z_AUX2_0
 * Register Name : GYRO_DATA_Z_AUX2_0
 */

/*
 * gyro_data_z_aux2
 * Gyro Z axis data for OIS2 path
 */
#define REG_GYRO_DATA_Z_AUX2_0_GYRO_DATA_Z_AUX2_POS      0x00
#define REG_GYRO_DATA_Z_AUX2_0_GYRO_DATA_Z_AUX2_MASK     0xff



/*
 * REG_GYRO_DATA_Z_AUX2_1
 * Register Name : GYRO_DATA_Z_AUX2_1
 */

/*
 * gyro_data_z_aux2
 * Gyro Z axis data for OIS2 path
 */
#define REG_GYRO_DATA_Z_AUX2_1_GYRO_DATA_Z_AUX2_POS      0x00
#define REG_GYRO_DATA_Z_AUX2_1_GYRO_DATA_Z_AUX2_MASK     0xff



/*
 * REG_TEMP_DATA_AUX2_0
 * Register Name : TEMP_DATA_AUX2_0
 */

/*
 * temp_data_aux2
 * Temperature data for OIS2 path
 */
#define REG_TEMP_DATA_AUX2_0_TEMP_DATA_AUX2_POS      0x00
#define REG_TEMP_DATA_AUX2_0_TEMP_DATA_AUX2_MASK     0xff



/*
 * REG_TEMP_DATA_AUX2_1
 * Register Name : TEMP_DATA_AUX2_1
 */

/*
 * temp_data_aux2
 * Temperature data for OIS2 path
 */
#define REG_TEMP_DATA_AUX2_1_TEMP_DATA_AUX2_POS      0x00
#define REG_TEMP_DATA_AUX2_1_TEMP_DATA_AUX2_MASK     0xff



/*
 * REG_TMST_FSYNC_DATA_AUX2_0
 * Register Name : TMST_FSYNC_DATA_AUX2_0
 */

/*
 * tmst_fsync_data_aux2
 * Timestamp/FSYNC data for OIS2 path
 */
#define REG_TMST_FSYNC_DATA_AUX2_0_TMST_FSYNC_DATA_AUX2_POS      0x00
#define REG_TMST_FSYNC_DATA_AUX2_0_TMST_FSYNC_DATA_AUX2_MASK     0xff



/*
 * REG_TMST_FSYNC_DATA_AUX2_1
 * Register Name : TMST_FSYNC_DATA_AUX2_1
 */

/*
 * tmst_fsync_data_aux2
 * Timestamp/FSYNC data for OIS2 path
 */
#define REG_TMST_FSYNC_DATA_AUX2_1_TMST_FSYNC_DATA_AUX2_POS      0x00
#define REG_TMST_FSYNC_DATA_AUX2_1_TMST_FSYNC_DATA_AUX2_MASK     0xff



/*
 * REG_PWR_MGMT_AUX2
 * Register Name : PWR_MGMT_AUX2
 */

/*
 * accel_aux2_en
 * [Supports Dynamic Change] Enable the OIS2 interface for the Accelerometer sensor.
 *   0: OFF
 *   1: ON
 */
#define REG_PWR_MGMT_AUX2_ACCEL_AUX2_EN_POS      0x00
#define REG_PWR_MGMT_AUX2_ACCEL_AUX2_EN_MASK     0x01

/*
 * gyro_aux2_en
 * [Supports Dynamic Change] Enable the OIS2 interface for the Gyroscope sensor.
 *   0: OFF
 *   1: ON
 */
#define REG_PWR_MGMT_AUX2_GYRO_AUX2_EN_POS      0x01
#define REG_PWR_MGMT_AUX2_GYRO_AUX2_EN_MASK     (0x01 << REG_PWR_MGMT_AUX2_GYRO_AUX2_EN_POS)

/*
 * accel_aux2_status_pm
 * Accelerometer Power-Mode status for the OIS2 FIFO
 */
#define REG_PWR_MGMT_AUX2_ACCEL_AUX2_STATUS_PM_POS      0x02
#define REG_PWR_MGMT_AUX2_ACCEL_AUX2_STATUS_PM_MASK     (0x01 << REG_PWR_MGMT_AUX2_ACCEL_AUX2_STATUS_PM_POS)

/*
 * gyro_aux2_status_pm
 * Gyroscope Power-Mode status for the OIS2 FIFO
 */
#define REG_PWR_MGMT_AUX2_GYRO_AUX2_STATUS_PM_POS      0x03
#define REG_PWR_MGMT_AUX2_GYRO_AUX2_STATUS_PM_MASK     (0x01 << REG_PWR_MGMT_AUX2_GYRO_AUX2_STATUS_PM_POS)



/*
 * REG_FS_SEL_AUX2
 * Register Name : FS_SEL_AUX2
 */

/*
 * aux2_accel_fs_sel
 * [Supports Dynamic Change] Set the OIS2 signal path accel full scale
 * 0 : 32 gee
 * 1 : 16 gee
 * 2 : 8 gee
 * 3 :4 gee
 * 4 : 2 gee
 */
#define REG_FS_SEL_AUX2_AUX2_ACCEL_FS_SEL_POS      0x00
#define REG_FS_SEL_AUX2_AUX2_ACCEL_FS_SEL_MASK     0x07

/*
 * aux2_gyro_fs_sel
 * [Supports Dynamic Change] Set the OIS2 signal path gyro full scale
 * 0 : 4000 dps
 * 1 : 2000 dps
 * 2 : 1000 dps
 * 3 : 500 dps
 * 4 : 250 dps
 * 5 : 125 dps
 * 6 : 62.5 dps
 * 7 : 31.25 dps
 * 8 : 15.625 dps
 */
#define REG_FS_SEL_AUX2_AUX2_GYRO_FS_SEL_POS      0x03
#define REG_FS_SEL_AUX2_AUX2_GYRO_FS_SEL_MASK     (0x0f << REG_FS_SEL_AUX2_AUX2_GYRO_FS_SEL_POS)



/*
 * REG_INT_AUX2_CONFIG
 * Register Name : INT_AUX2_CONFIG
 */

/*
 * int_en_aux2_agc_rdy
 * For AUX2 interface, source enable register for Optical Image Stabilization Interface #2 AGC Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_AGC_RDY_POS      0x00
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_AGC_RDY_MASK     0x01

/*
 * int_en_aux2_reset_done
 * For AUX2 interface, source enable register for Reset process is finished(after OTP copy is complete, i.e. after OTP_DONE signal) interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_RESET_DONE_POS      0x01
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_RESET_DONE_MASK     (0x01 << REG_INT_AUX2_CONFIG_INT_EN_AUX2_RESET_DONE_POS)

/*
 * int_en_aux2_pll_rdy
 * For AUX2 interface, source enable register for PLL is locked interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_PLL_RDY_POS      0x02
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_PLL_RDY_MASK     (0x01 << REG_INT_AUX2_CONFIG_INT_EN_AUX2_PLL_RDY_POS)

/*
 * int_en_aux2_drdy
 * For AUX2 interface, source enable register for Optical Image Stabilization Interface 2 Sensor Register Data Ready interrupt,
 * 0: disable interrupt source. The corresponding interrupt status bit will not be set and no any interrupt pin will be asserted when the specified interrupt source event occurs.
 * 1: enable interrupt source. The corresponding interrupt status bit will be set and the designated interrupt pin(s) will be asserted when the specified interrupt source event occurs.
 * [Reg block function] Setting can be changed by both UI/AP and the corresponding serial interface (AUX1 or AUX2 or MCU).
 */
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_DRDY_POS      0x03
#define REG_INT_AUX2_CONFIG_INT_EN_AUX2_DRDY_MASK     (0x01 << REG_INT_AUX2_CONFIG_INT_EN_AUX2_DRDY_POS)



/*
 * REG_INT_AUX2_STATUS
 * Register Name : INT_AUX2_STATUS
 */

/*
 * int_status_aux2_agc_rdy
 * –
 * For AUX2, Indicates if status register (ISR) for Optical Image Stabilization Interface #2 AGC Ready is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_AGC_RDY_POS      0x00
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_AGC_RDY_MASK     0x01

/*
 * int_status_aux2_reset_done
 * –For AUX2, Indicates if status register (ISR) for Reset process is finished(after OTP copy is complete, i.e. after OTP_DONE signal)
 *
 * when REG_HOST_MSG[0] = 1, then INT_AUX2_STATUS[1] is used to flag self-test done or self-calib done events from eDMP.
 *
 * The AUX2 host can read INT_AUX2_STATUS[1] to know the self test/calib status.
 *
 *
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_RESET_DONE_POS      0x01
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_RESET_DONE_MASK     (0x01 << REG_INT_AUX2_STATUS_INT_STATUS_AUX2_RESET_DONE_POS)

/*
 * int_status_aux2_pll_rdy
 * –For AUX2, Indicates if status register (ISR) for PLL is locked is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_PLL_RDY_POS      0x02
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_PLL_RDY_MASK     (0x01 << REG_INT_AUX2_STATUS_INT_STATUS_AUX2_PLL_RDY_POS)

/*
 * int_status_aux2_drdy
 * -For AUX2, Indicates if status register (ISR) for Optical Image Stabilization Interface 2 Sensor Register Data Ready is set.
 * 1: indicates status set.
 * 0: indicates status not set.
 */
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_DRDY_POS      0x03
#define REG_INT_AUX2_STATUS_INT_STATUS_AUX2_DRDY_MASK     (0x01 << REG_INT_AUX2_STATUS_INT_STATUS_AUX2_DRDY_POS)



/*
 * REG_WHO_AM_I
 * Register Name : WHO_AM_I
 */

/*
 * who_am_i
 * TDK Chip ID
 */
#define REG_WHO_AM_I_WHO_AM_I_POS      0x00
#define REG_WHO_AM_I_WHO_AM_I_MASK     0xff



/*
 * REG_REG_HOST_MSG
 * Register Name : REG_HOST_MSG
 */

/*
 * testopenable
 * [Supports Dynamic Change] 1: Enable test op, Read SRAM to know if the test op is for self-test(A/G) or for self-cal(A/G)
 */
#define REG_REG_HOST_MSG_TESTOPENABLE_POS      0x00
#define REG_REG_HOST_MSG_TESTOPENABLE_MASK     0x01

/*
 * reserved1
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED1_POS      0x01
#define REG_REG_HOST_MSG_RESERVED1_MASK     (0x01 << REG_REG_HOST_MSG_RESERVED1_POS)

/*
 * reserved2
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED2_POS      0x02
#define REG_REG_HOST_MSG_RESERVED2_MASK     (0x01 << REG_REG_HOST_MSG_RESERVED2_POS)

/*
 * reserved3
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED3_POS      0x03
#define REG_REG_HOST_MSG_RESERVED3_MASK     (0x01 << REG_REG_HOST_MSG_RESERVED3_POS)

/*
 * sa_en
 * [Supports Dynamic Change] 1: Enable SA Op.
 */
#define REG_REG_HOST_MSG_SA_EN_POS      0x04
#define REG_REG_HOST_MSG_SA_EN_MASK     (0x01 << REG_REG_HOST_MSG_SA_EN_POS)

/*
 * edmp_on_demand_en
 * Set 1 to create pulse to set int_status_edmp_on_demand_pin_0,
 * int_status_edmp_on_demand_pin_1,
 * Int_status_edmp_on_demand_pin_2 to 1
 */
#define REG_REG_HOST_MSG_EDMP_ON_DEMAND_EN_POS      0x05
#define REG_REG_HOST_MSG_EDMP_ON_DEMAND_EN_MASK     (0x01 << REG_REG_HOST_MSG_EDMP_ON_DEMAND_EN_POS)

/*
 * reserved4
 * [Supports Dynamic Change] reserved
 */
#define REG_REG_HOST_MSG_RESERVED4_POS      0x06
#define REG_REG_HOST_MSG_RESERVED4_MASK     (0x03 << REG_REG_HOST_MSG_RESERVED4_POS)



/*
 * REG_RESERVED_OTP_BYTE0
 * Register Name : RESERVED_OTP_BYTE0
 */

/*
 * reserved_otp_byte0
 * Reserve otp byte0
 */
#define REG_RESERVED_OTP_BYTE0_RESERVED_OTP_BYTE0_POS      0x00
#define REG_RESERVED_OTP_BYTE0_RESERVED_OTP_BYTE0_MASK     0x01



/*
 * REG_RESERVED_OTP_BYTE1
 * Register Name : RESERVED_OTP_BYTE1
 */

/*
 * reserved_otp_byte1
 * Reserve otp byte1
 */
#define REG_RESERVED_OTP_BYTE1_RESERVED_OTP_BYTE1_POS      0x00
#define REG_RESERVED_OTP_BYTE1_RESERVED_OTP_BYTE1_MASK     0x01



/*
 * REG_IREG_ADDR_15_8
 * Register Name : IREG_ADDR_15_8
 */

/*
 * ireg_addr_15_8
 * [Supports Dynamic Change] DREG register for holding indirect access of IREG . Bits [15:8]
 *
 * If (1) CS_N=1 when in SPI, or (2) STOP when in IxC, is followed after a write operation to this register, then a read-prefetching operation to IREG is kicked off with new address.
 *
 * Poll register ireg_ireg_done to confirm that it is '1' before writing to this register.
 */
#define REG_IREG_ADDR_15_8_IREG_ADDR_15_8_POS      0x00
#define REG_IREG_ADDR_15_8_IREG_ADDR_15_8_MASK     0xff



/*
 * REG_IREG_ADDR_7_0
 * Register Name : IREG_ADDR_7_0
 */

/*
 * ireg_addr_7_0
 * [Supports Dynamic Change] DREG register for holding indirect access of IREG . Bits [7:0]
 *
 * If (1) CS_N=1 when in SPI, or (2) STOP when in IxC, is followed after a write operation to this register, then a read-prefetching operation to IREG is kicked off with new address.
 *
 * Poll register ireg_ireg_done to confirm that it is '1' before writing to this register.
 */
#define REG_IREG_ADDR_7_0_IREG_ADDR_7_0_POS      0x00
#define REG_IREG_ADDR_7_0_IREG_ADDR_7_0_MASK     0xff



/*
 * REG_IREG_DATA
 * Register Name : IREG_DATA
 */

/*
 * ireg_data
 * [Supports Dynamic Change] DREG register for holding indirect access IREG data. Address bit LSB = 0
 *
 * A write operation to this register kicks off a write operation to IREG with the 32-bit indirect address, waiting for CS_N=1 (SPI) or STOP (IxC).
 * A read operation to this register kicks off a read-prefetching operation to IREG with the 32-bit indirect address, waiting for CS_N=1 (SPI) or STOP (I2C).
 *
 * In both write and read operations to IREG, whether auto-incremented 32-bit indirect address is used or not depends on the setting of reg_ireg_auto_addr_inc_dis register.
 *
 * A read to reg_ireg_data gets result from previous read-prefetching operation to IREG, not the value from previous write operation to reg_ireg_data.
 *
 * The DREG address auto increment stops when pointing to this register.
 *
 * Poll register ireg_ireg_done to confirm that it is '1' before writing/reading to/from this register.
 */
#define REG_IREG_DATA_IREG_DATA_POS      0x00
#define REG_IREG_DATA_IREG_DATA_MASK     0xff



/*
 * REG_REG_MISC2
 * Register Name : REG_MISC2
 */

/*
 * ireg_done
 * [Supports Dynamic Change] 0: Indicates that an Internal IREG operation is in progress. No new IREG access should be triggered.
 * 1: SIFS IREG access completed. New IREG access can be triggered
 *
 * When reset is low the ireg_done internally should be high as there is no pending IREG access within SIFS. But Host will not be able to able to read the ireg_done register bit during reset.
 *
 * During otp_copy operation ireg_done is expected to be internally high as there is no pending IREG access within SIFS. But Host will not be able to able to read the ireg_done register bit during otp_copy operation.
 *
 * After otp_done is high the ireg_done done is expected to remain high till host triggers an IREG access. IREG access is triggered under following conditions
 * a) Host writes to any of ireg_addr* register followed by posedge of sifs_idle
 * b) Host write to ireg_data register followed by sifs_idle
 * c) Host read from ireg_data register followed by sifs_idle
 *
 * Exact condition for ireg_done fall edge is an IREG operation trigger.IREG access is triggered under following conditions
 * a) Host writes to any of ireg_addr* register followed by posedge of sifs_idle
 * b) Host write to ireg_data register followed by sifs_idle
 * c) Host read from ireg_data register followed by sifs_idle
 *
 * It takes maximum of 3 available SCLK cycle after the AHB Data Phase of IREG transaction occurs for ireg_done to go high. But this exact change is visible only internally to SIFS.
 *
 * If there is no SCLK after IREG operation is done in MCLK domain, then ireg_done remains 0 until SCLK is available for synchronizing the IREG operation complete information into SCLK domain.
 *
 * SIFS, by design, does not support MCLK missing in between an IREG operation. After SIFS has asserted the MCLK request, the request stay asserted till the end of IREG operation in MCLK domain
 * SIFS AHB access internal latency for Newport is 14.5 MCLK cycles. This considers AHB bus turn around time to be 8 MCLK cycles.
 */
#define REG_REG_MISC2_IREG_DONE_POS      0x00
#define REG_REG_MISC2_IREG_DONE_MASK     0x01

/*
 * soft_rst
 * [Supports Dynamic Change] Soft reset from Host.
 */
#define REG_REG_MISC2_SOFT_RST_POS      0x01
#define REG_REG_MISC2_SOFT_RST_MASK     (0x01 << REG_REG_MISC2_SOFT_RST_POS)


/* ---------------------------------------------------------------------------
 * register DREG_BANK2
 * ---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /*#ifndef _REG_EXTERNAL_H_*/

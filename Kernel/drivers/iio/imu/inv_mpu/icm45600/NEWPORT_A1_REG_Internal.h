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
#ifndef _REG_INTERNAL_H_
#define _REG_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file REG.h
 * File exposing the device register map
 */

//#include <stdint.h>

/* forward declaration */
struct newport_a1_reg;



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
#define REG_IPREG_BAR_REG_0_IPREG_BAR                                0xa000
#define REG_IPREG_BAR_REG_1_IPREG_BAR                                0xa001
#define REG_IPREG_BAR_REG_2_IPREG_BAR                                0xa002
#define REG_IPREG_BAR_REG_3_IPREG_BAR                                0xa003
#define REG_IPREG_BAR_REG_4_IPREG_BAR                                0xa004
#define REG_IPREG_BAR_REG_5_IPREG_BAR                                0xa005
#define REG_IPREG_BAR_REG_6_IPREG_BAR                                0xa006
#define REG_IPREG_BAR_REG_7_IPREG_BAR                                0xa007
#define REG_IPREG_BAR_REG_8_IPREG_BAR                                0xa008
#define REG_IPREG_BAR_REG_9_IPREG_BAR                                0xa009
#define REG_IPREG_BAR_REG_10_IPREG_BAR                               0xa00a
#define REG_IPREG_BAR_REG_11_IPREG_BAR                               0xa00b
#define REG_IPREG_BAR_REG_12_IPREG_BAR                               0xa00c
#define REG_IPREG_BAR_REG_13_IPREG_BAR                               0xa00d
#define REG_IPREG_BAR_REG_14_IPREG_BAR                               0xa00e
#define REG_IPREG_BAR_REG_15_IPREG_BAR                               0xa00f
#define REG_IPREG_BAR_REG_16_IPREG_BAR                               0xa010
#define REG_IPREG_BAR_REG_17_IPREG_BAR                               0xa011
#define REG_IPREG_BAR_REG_18_IPREG_BAR                               0xa012
#define REG_IPREG_BAR_REG_19_IPREG_BAR                               0xa013
#define REG_IPREG_BAR_REG_20_IPREG_BAR                               0xa014
#define REG_IPREG_BAR_REG_21_IPREG_BAR                               0xa015
#define REG_IPREG_BAR_REG_22_IPREG_BAR                               0xa016
#define REG_IPREG_BAR_REG_23_IPREG_BAR                               0xa017
#define REG_IPREG_BAR_REG_24_IPREG_BAR                               0xa018
#define REG_IPREG_BAR_REG_25_IPREG_BAR                               0xa019
#define REG_IPREG_BAR_REG_26_IPREG_BAR                               0xa01a
#define REG_IPREG_BAR_REG_27_IPREG_BAR                               0xa01b
#define REG_IPREG_BAR_REG_28_IPREG_BAR                               0xa01c
#define REG_IPREG_BAR_REG_29_IPREG_BAR                               0xa01d
#define REG_IPREG_BAR_REG_30_IPREG_BAR                               0xa01e
#define REG_IPREG_BAR_REG_31_IPREG_BAR                               0xa01f
#define REG_IPREG_BAR_REG_32_IPREG_BAR                               0xa020
#define REG_IPREG_BAR_REG_33_IPREG_BAR                               0xa021
#define REG_IPREG_BAR_REG_34_IPREG_BAR                               0xa022
#define REG_IPREG_BAR_REG_35_IPREG_BAR                               0xa023
#define REG_IPREG_BAR_REG_36_IPREG_BAR                               0xa024
#define REG_IPREG_BAR_REG_37_IPREG_BAR                               0xa025
#define REG_IPREG_BAR_REG_38_IPREG_BAR                               0xa026
#define REG_IPREG_BAR_REG_39_IPREG_BAR                               0xa027
#define REG_IPREG_BAR_REG_40_IPREG_BAR                               0xa028
#define REG_IPREG_BAR_REG_41_IPREG_BAR                               0xa029
#define REG_IPREG_BAR_REG_42_IPREG_BAR                               0xa02a
#define REG_IPREG_BAR_REG_43_IPREG_BAR                               0xa02b
#define REG_IPREG_BAR_REG_44_IPREG_BAR                               0xa02c
#define REG_IPREG_BAR_REG_45_IPREG_BAR                               0xa02d
#define REG_IPREG_BAR_REG_46_IPREG_BAR                               0xa02e
#define REG_IPREG_BAR_REG_47_IPREG_BAR                               0xa02f
#define REG_IPREG_BAR_REG_48_IPREG_BAR                               0xa030
#define REG_IPREG_BAR_REG_49_IPREG_BAR                               0xa031
#define REG_IPREG_BAR_REG_50_IPREG_BAR                               0xa032
#define REG_IPREG_BAR_REG_51_IPREG_BAR                               0xa033
#define REG_IPREG_BAR_REG_52_IPREG_BAR                               0xa034
#define REG_IPREG_BAR_REG_53_IPREG_BAR                               0xa035
#define REG_IPREG_BAR_REG_54_IPREG_BAR                               0xa036
#define REG_IPREG_BAR_REG_55_IPREG_BAR                               0xa037
#define REG_IPREG_BAR_REG_56_IPREG_BAR                               0xa038
#define REG_IPREG_BAR_REG_57_IPREG_BAR                               0xa039
#define REG_IPREG_BAR_REG_58_IPREG_BAR                               0xa03a
#define REG_IPREG_BAR_REG_59_IPREG_BAR                               0xa03b
#define REG_IPREG_BAR_REG_60_IPREG_BAR                               0xa03c
#define REG_IPREG_BAR_REG_61_IPREG_BAR                               0xa03d
#define REG_IPREG_BAR_REG_62_IPREG_BAR                               0xa03e
#define REG_IPREG_BAR_REG_63_IPREG_BAR                               0xa03f
#define REG_IPREG_BAR_REG_64_IPREG_BAR                               0xa040
#define REG_IPREG_BAR_REG_65_IPREG_BAR                               0xa041
#define REG_IPREG_BAR_REG_66_IPREG_BAR                               0xa042
#define REG_IPREG_BAR_REG_67_IPREG_BAR                               0xa043
#define REG_IPREG_BAR_REG_68_IPREG_BAR                               0xa044
#define REG_IPREG_BAR_REG_69_IPREG_BAR                               0xa045
#define REG_IPREG_BAR_REG_70_IPREG_BAR                               0xa046
#define REG_IPREG_BAR_REG_71_IPREG_BAR                               0xa047
#define REG_IPREG_BAR_REG_72_IPREG_BAR                               0xa048
#define REG_IPREG_BAR_REG_73_IPREG_BAR                               0xa049
#define REG_IPREG_BAR_REG_74_IPREG_BAR                               0xa04a
#define REG_IPREG_BAR_REG_75_IPREG_BAR                               0xa04b
#define REG_IPREG_BAR_REG_76_IPREG_BAR                               0xa04c
#define REG_IPREG_BAR_REG_77_IPREG_BAR                               0xa04d
#define REG_IPREG_BAR_REG_78_IPREG_BAR                               0xa04e
#define REG_IPREG_BAR_REG_79_IPREG_BAR                               0xa04f
#define REG_IPREG_BAR_REG_80_IPREG_BAR                               0xa050
#define REG_IPREG_BAR_REG_81_IPREG_BAR                               0xa051
#define REG_IPREG_BAR_REG_82_IPREG_BAR                               0xa052
#define REG_IPREG_BAR_REG_83_IPREG_BAR                               0xa053
#define REG_IPREG_BAR_REG_84_IPREG_BAR                               0xa054
#define REG_IPREG_BAR_REG_85_IPREG_BAR                               0xa055
#define REG_IPREG_BAR_REG_86_IPREG_BAR                               0xa056
#define REG_IPREG_BAR_REG_87_IPREG_BAR                               0xa057
#define REG_IPREG_BAR_REG_88_IPREG_BAR                               0xa058
#define REG_IPREG_BAR_REG_89_IPREG_BAR                               0xa059
#define REG_IPREG_BAR_REG_90_IPREG_BAR                               0xa05a
#define REG_IPREG_BAR_REG_91_IPREG_BAR                               0xa05b
#define REG_IPREG_BAR_REG_92_IPREG_BAR                               0xa05c
#define REG_IPREG_BAR_REG_93_IPREG_BAR                               0xa05d
#define REG_IPREG_BAR_REG_94_IPREG_BAR                               0xa05e
#define REG_IPREG_BAR_REG_95_IPREG_BAR                               0xa05f
#define REG_IPREG_BAR_REG_96_IPREG_BAR                               0xa060
#define REG_IPREG_BAR_REG_97_IPREG_BAR                               0xa061
#define REG_IPREG_BAR_REG_98_IPREG_BAR                               0xa062
#define REG_IPREG_BAR_REG_99_IPREG_BAR                               0xa063
#define REG_IPREG_BAR_REG_100_IPREG_BAR                              0xa064
#define REG_IPREG_BAR_REG_101_IPREG_BAR                              0xa065
#define REG_IPREG_BAR_REG_102_IPREG_BAR                              0xa066
#define REG_IPREG_BAR_REG_103_IPREG_BAR                              0xa067
#define REG_IPREG_BAR_REG_104_IPREG_BAR                              0xa068
#define REG_IPREG_BAR_REG_105_IPREG_BAR                              0xa069
#define REG_IPREG_BAR_REG_106_IPREG_BAR                              0xa06a
#define REG_IPREG_BAR_REG_107_IPREG_BAR                              0xa06b
#define REG_IPREG_BAR_REG_108_IPREG_BAR                              0xa06c
#define REG_IPREG_BAR_REG_109_IPREG_BAR                              0xa06d
#define REG_IPREG_BAR_REG_110_IPREG_BAR                              0xa06e
#define REG_IPREG_BAR_REG_111_IPREG_BAR                              0xa06f
#define REG_IPREG_BAR_REG_112_IPREG_BAR                              0xa070
#define REG_IPREG_BAR_REG_113_IPREG_BAR                              0xa071
#define REG_IPREG_BAR_REG_114_IPREG_BAR                              0xa072
#define REG_IPREG_BAR_REG_115_IPREG_BAR                              0xa073
#define REG_IPREG_BAR_REG_116_IPREG_BAR                              0xa074
#define REG_IPREG_BAR_REG_117_IPREG_BAR                              0xa075
#define REG_IPREG_BAR_REG_118_IPREG_BAR                              0xa076
#define REG_IPREG_BAR_REG_119_IPREG_BAR                              0xa077
#define REG_IPREG_BAR_REG_120_IPREG_BAR                              0xa078
#define REG_IPREG_BAR_REG_121_IPREG_BAR                              0xa079
#define REG_IPREG_BAR_REG_122_IPREG_BAR                              0xa07a
#define REG_IPREG_BAR_REG_123_IPREG_BAR                              0xa07b
#define REG_IPREG_BAR_REG_124_IPREG_BAR                              0xa07c
#define REG_IPREG_BAR_REG_125_IPREG_BAR                              0xa07d
#define REG_IPREG_BAR_REG_126_IPREG_BAR                              0xa07e
#define REG_IPREG_BAR_REG_127_IPREG_BAR                              0xa07f
#define REG_IPREG_BAR_REG_128_IPREG_BAR                              0xa080
#define REG_IPREG_BAR_REG_129_IPREG_BAR                              0xa081
#define REG_IPREG_BAR_REG_130_IPREG_BAR                              0xa082
#define REG_IPREG_BAR_REG_131_IPREG_BAR                              0xa083
#define REG_IPREG_BAR_REG_132_IPREG_BAR                              0xa084
#define REG_IPREG_BAR_REG_133_IPREG_BAR                              0xa085
#define REG_IPREG_BAR_REG_134_IPREG_BAR                              0xa086
#define REG_IPREG_BAR_REG_135_IPREG_BAR                              0xa087
#define REG_IPREG_BAR_REG_136_IPREG_BAR                              0xa088
#define REG_IPREG_BAR_REG_137_IPREG_BAR                              0xa089
#define REG_IPREG_BAR_REG_138_IPREG_BAR                              0xa08a
#define REG_IPREG_BAR_REG_139_IPREG_BAR                              0xa08b
#define REG_IPREG_BAR_REG_140_IPREG_BAR                              0xa08c
#define REG_IPREG_BAR_REG_141_IPREG_BAR                              0xa08d
#define REG_IPREG_BAR_REG_142_IPREG_BAR                              0xa08e
#define REG_IPREG_BAR_REG_143_IPREG_BAR                              0xa08f
#define REG_IPREG_BAR_REG_144_IPREG_BAR                              0xa090
#define REG_IPREG_BAR_REG_145_IPREG_BAR                              0xa091
#define REG_IPREG_BAR_REG_146_IPREG_BAR                              0xa092
#define REG_IPREG_BAR_REG_147_IPREG_BAR                              0xa093
#define REG_IPREG_BAR_REG_148_IPREG_BAR                              0xa094
#define REG_IPREG_BAR_REG_149_IPREG_BAR                              0xa095
#define REG_IPREG_BAR_REG_150_IPREG_BAR                              0xa096
#define REG_IPREG_BAR_REG_151_IPREG_BAR                              0xa097
#define REG_IPREG_BAR_REG_152_IPREG_BAR                              0xa098
#define REG_IPREG_BAR_REG_153_IPREG_BAR                              0xa099
#define REG_IPREG_BAR_REG_154_IPREG_BAR                              0xa09a
#define REG_IPREG_BAR_REG_155_IPREG_BAR                              0xa09b
#define REG_IPREG_BAR_REG_156_IPREG_BAR                              0xa09c
#define REG_IPREG_BAR_REG_157_IPREG_BAR                              0xa09d
#define REG_IPREG_BAR_REG_158_IPREG_BAR                              0xa09e
#define REG_IPREG_BAR_REG_159_IPREG_BAR                              0xa09f
#define REG_IPREG_BAR_REG_160_IPREG_BAR                              0xa0a0
#define REG_IPREG_BAR_REG_161_IPREG_BAR                              0xa0a1
#define REG_IPREG_BAR_REG_162_IPREG_BAR                              0xa0a2

/* IPREG_ANA */
#define REG_IPREG_ANA_REG_0_IPREG_ANA                                0xa300
#define REG_IPREG_ANA_REG_1_IPREG_ANA                                0xa301
#define REG_IPREG_ANA_REG_2_IPREG_ANA                                0xa302
#define REG_IPREG_ANA_REG_3_IPREG_ANA                                0xa303
#define REG_IPREG_ANA_REG_4_IPREG_ANA                                0xa304
#define REG_IPREG_ANA_REG_5_IPREG_ANA                                0xa305
#define REG_IPREG_ANA_REG_6_IPREG_ANA                                0xa306
#define REG_IPREG_ANA_REG_7_IPREG_ANA                                0xa307
#define REG_IPREG_ANA_REG_8_IPREG_ANA                                0xa308
#define REG_IPREG_ANA_REG_9_IPREG_ANA                                0xa309
#define REG_IPREG_ANA_REG_10_IPREG_ANA                               0xa30a
#define REG_IPREG_ANA_REG_11_IPREG_ANA                               0xa30b
#define REG_ATMD_MISC1_IPREG_ANA                                     0xa30c
#define REG_ATMD_MISC2_IPREG_ANA                                     0xa30d
#define REG_ATMD_MISC3_IPREG_ANA                                     0xa30e

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
#define REG_STC_DT_DREG_TOP2                                         0xa181
#define REG_STC_TU_DREG_TOP2                                         0xa182
#define REG_STC_TPH_ACCEL_0_DREG_TOP2                                0xa183
#define REG_STC_TPH_ACCEL_1_DREG_TOP2                                0xa184
#define REG_STC_TPH_GYRO_0_DREG_TOP2                                 0xa185
#define REG_STC_TPH_GYRO_1_DREG_TOP2                                 0xa186

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
#define REG_STC_TICK_PERIOD_FULL_0_IHREG_SREG                        0x8020
#define REG_STC_TICK_PERIOD_FULL_1_IHREG_SREG                        0x8021

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
#define REG_MANU_ID_IMEM_SRAM                                        0x19
#define REG_CHIP_ID_IMEM_SRAM                                        0x1a
#define REG_REV_ID_IMEM_SRAM                                         0x1b
#define REG_ASIC_WAFER_ID_IMEM_SRAM                                  0x1c
#define REG_ASIC_DIE_ID_0_IMEM_SRAM                                  0x1d
#define REG_ASIC_DIE_ID_1_IMEM_SRAM                                  0x1e
#define REG_MEMS_WAFER_ID_IMEM_SRAM                                  0x1f
#define REG_MEMS_DIE_ID_0_IMEM_SRAM                                  0x20
#define REG_MEMS_DIE_ID_1_IMEM_SRAM                                  0x21
#define REG_SW_RCOSC_TRIM_IMEM_SRAM                                  0x22
#define REG_SW_PLL_TRIM_IMEM_SRAM                                    0x23
#define REG_SA_KEY_LAST_BYTE_IMEM_SRAM                               0x24

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
#define REG_OTP_MRA_0_IPREG_OTP                                      0xaf00
#define REG_OTP_MRA_1_IPREG_OTP                                      0xaf01
#define REG_OTP_MRB_0_IPREG_OTP                                      0xaf02
#define REG_OTP_MRB_1_IPREG_OTP                                      0xaf03
#define REG_OTP_MR_0_IPREG_OTP                                       0xaf04
#define REG_OTP_MR_1_IPREG_OTP                                       0xaf05
#define REG_OTP_CTRL_IPREG_OTP                                       0xaf06

/* IPREG_SYS1 */
#define REG_IPREG_SYS1_REG_0_IPREG_SYS1                              0xa400
#define REG_IPREG_SYS1_REG_1_IPREG_SYS1                              0xa401
#define REG_IPREG_SYS1_REG_2_IPREG_SYS1                              0xa402
#define REG_IPREG_SYS1_REG_4_IPREG_SYS1                              0xa404
#define REG_IPREG_SYS1_REG_5_IPREG_SYS1                              0xa405
#define REG_IPREG_SYS1_REG_6_IPREG_SYS1                              0xa406
#define REG_IPREG_SYS1_REG_7_IPREG_SYS1                              0xa407
#define REG_IPREG_SYS1_REG_8_IPREG_SYS1                              0xa408
#define REG_IPREG_SYS1_REG_9_IPREG_SYS1                              0xa409
#define REG_IPREG_SYS1_REG_10_IPREG_SYS1                             0xa40a
#define REG_IPREG_SYS1_REG_11_IPREG_SYS1                             0xa40b
#define REG_IPREG_SYS1_REG_12_IPREG_SYS1                             0xa40c
#define REG_IPREG_SYS1_REG_13_IPREG_SYS1                             0xa40d
#define REG_IPREG_SYS1_REG_14_IPREG_SYS1                             0xa40e
#define REG_IPREG_SYS1_REG_15_IPREG_SYS1                             0xa40f
#define REG_IPREG_SYS1_REG_16_IPREG_SYS1                             0xa410
#define REG_IPREG_SYS1_REG_17_IPREG_SYS1                             0xa411
#define REG_IPREG_SYS1_REG_18_IPREG_SYS1                             0xa412
#define REG_IPREG_SYS1_REG_19_IPREG_SYS1                             0xa413
#define REG_IPREG_SYS1_REG_20_IPREG_SYS1                             0xa414
#define REG_IPREG_SYS1_REG_21_IPREG_SYS1                             0xa415
#define REG_IPREG_SYS1_REG_22_IPREG_SYS1                             0xa416
#define REG_IPREG_SYS1_REG_23_IPREG_SYS1                             0xa417
#define REG_IPREG_SYS1_REG_24_IPREG_SYS1                             0xa418
#define REG_IPREG_SYS1_REG_25_IPREG_SYS1                             0xa419
#define REG_IPREG_SYS1_REG_26_IPREG_SYS1                             0xa41a
#define REG_IPREG_SYS1_REG_27_IPREG_SYS1                             0xa41b
#define REG_IPREG_SYS1_REG_28_IPREG_SYS1                             0xa41c
#define REG_IPREG_SYS1_REG_29_IPREG_SYS1                             0xa41d
#define REG_IPREG_SYS1_REG_30_IPREG_SYS1                             0xa41e
#define REG_IPREG_SYS1_REG_31_IPREG_SYS1                             0xa41f
#define REG_IPREG_SYS1_REG_32_IPREG_SYS1                             0xa420
#define REG_IPREG_SYS1_REG_33_IPREG_SYS1                             0xa421
#define REG_IPREG_SYS1_REG_34_IPREG_SYS1                             0xa422
#define REG_IPREG_SYS1_REG_35_IPREG_SYS1                             0xa423
#define REG_IPREG_SYS1_REG_36_IPREG_SYS1                             0xa424
#define REG_IPREG_SYS1_REG_37_IPREG_SYS1                             0xa425
#define REG_IPREG_SYS1_REG_38_IPREG_SYS1                             0xa426
#define REG_IPREG_SYS1_REG_39_IPREG_SYS1                             0xa427
#define REG_IPREG_SYS1_REG_40_IPREG_SYS1                             0xa428
#define REG_IPREG_SYS1_REG_41_IPREG_SYS1                             0xa429
#define REG_IPREG_SYS1_REG_42_IPREG_SYS1                             0xa42a
#define REG_IPREG_SYS1_REG_43_IPREG_SYS1                             0xa42b
#define REG_IPREG_SYS1_REG_44_IPREG_SYS1                             0xa42c
#define REG_IPREG_SYS1_REG_45_IPREG_SYS1                             0xa42d
#define REG_IPREG_SYS1_REG_46_IPREG_SYS1                             0xa42e
#define REG_IPREG_SYS1_REG_47_IPREG_SYS1                             0xa42f
#define REG_IPREG_SYS1_REG_48_IPREG_SYS1                             0xa430
#define REG_IPREG_SYS1_REG_49_IPREG_SYS1                             0xa431
#define REG_IPREG_SYS1_REG_50_IPREG_SYS1                             0xa432
#define REG_IPREG_SYS1_REG_51_IPREG_SYS1                             0xa433
#define REG_IPREG_SYS1_REG_52_IPREG_SYS1                             0xa434
#define REG_IPREG_SYS1_REG_53_IPREG_SYS1                             0xa435
#define REG_IPREG_SYS1_REG_54_IPREG_SYS1                             0xa436
#define REG_IPREG_SYS1_REG_55_IPREG_SYS1                             0xa437
#define REG_IPREG_SYS1_REG_56_IPREG_SYS1                             0xa438
#define REG_IPREG_SYS1_REG_57_IPREG_SYS1                             0xa439
#define REG_IPREG_SYS1_REG_58_IPREG_SYS1                             0xa43a
#define REG_IPREG_SYS1_REG_59_IPREG_SYS1                             0xa43b
#define REG_IPREG_SYS1_REG_60_IPREG_SYS1                             0xa43c
#define REG_IPREG_SYS1_REG_61_IPREG_SYS1                             0xa43d
#define REG_IPREG_SYS1_REG_62_IPREG_SYS1                             0xa43e
#define REG_IPREG_SYS1_REG_63_IPREG_SYS1                             0xa43f
#define REG_IPREG_SYS1_REG_64_IPREG_SYS1                             0xa440
#define REG_IPREG_SYS1_REG_65_IPREG_SYS1                             0xa441
#define REG_IPREG_SYS1_REG_66_IPREG_SYS1                             0xa442
#define REG_IPREG_SYS1_REG_67_IPREG_SYS1                             0xa443
#define REG_IPREG_SYS1_REG_68_IPREG_SYS1                             0xa444
#define REG_IPREG_SYS1_REG_69_IPREG_SYS1                             0xa445
#define REG_IPREG_SYS1_REG_70_IPREG_SYS1                             0xa446
#define REG_IPREG_SYS1_REG_71_IPREG_SYS1                             0xa447
#define REG_IPREG_SYS1_REG_72_IPREG_SYS1                             0xa448
#define REG_IPREG_SYS1_REG_73_IPREG_SYS1                             0xa449
#define REG_IPREG_SYS1_REG_74_IPREG_SYS1                             0xa44a
#define REG_IPREG_SYS1_REG_75_IPREG_SYS1                             0xa44b
#define REG_IPREG_SYS1_REG_76_IPREG_SYS1                             0xa44c
#define REG_IPREG_SYS1_REG_77_IPREG_SYS1                             0xa44d
#define REG_IPREG_SYS1_REG_78_IPREG_SYS1                             0xa44e
#define REG_IPREG_SYS1_REG_79_IPREG_SYS1                             0xa44f
#define REG_IPREG_SYS1_REG_80_IPREG_SYS1                             0xa450
#define REG_IPREG_SYS1_REG_81_IPREG_SYS1                             0xa451
#define REG_IPREG_SYS1_REG_82_IPREG_SYS1                             0xa452
#define REG_IPREG_SYS1_REG_83_IPREG_SYS1                             0xa453
#define REG_IPREG_SYS1_REG_84_IPREG_SYS1                             0xa454
#define REG_IPREG_SYS1_REG_85_IPREG_SYS1                             0xa455
#define REG_IPREG_SYS1_REG_86_IPREG_SYS1                             0xa456
#define REG_IPREG_SYS1_REG_87_IPREG_SYS1                             0xa457
#define REG_IPREG_SYS1_REG_88_IPREG_SYS1                             0xa458
#define REG_IPREG_SYS1_REG_89_IPREG_SYS1                             0xa459
#define REG_IPREG_SYS1_REG_90_IPREG_SYS1                             0xa45a
#define REG_IPREG_SYS1_REG_91_IPREG_SYS1                             0xa45b
#define REG_IPREG_SYS1_REG_92_IPREG_SYS1                             0xa45c
#define REG_IPREG_SYS1_REG_93_IPREG_SYS1                             0xa45d
#define REG_IPREG_SYS1_REG_94_IPREG_SYS1                             0xa45e
#define REG_IPREG_SYS1_REG_95_IPREG_SYS1                             0xa45f
#define REG_IPREG_SYS1_REG_96_IPREG_SYS1                             0xa460
#define REG_IPREG_SYS1_REG_97_IPREG_SYS1                             0xa461
#define REG_IPREG_SYS1_REG_98_IPREG_SYS1                             0xa462
#define REG_IPREG_SYS1_REG_99_IPREG_SYS1                             0xa463
#define REG_IPREG_SYS1_REG_100_IPREG_SYS1                            0xa464
#define REG_IPREG_SYS1_REG_101_IPREG_SYS1                            0xa465
#define REG_IPREG_SYS1_REG_102_IPREG_SYS1                            0xa466
#define REG_IPREG_SYS1_REG_103_IPREG_SYS1                            0xa467
#define REG_IPREG_SYS1_REG_104_IPREG_SYS1                            0xa468
#define REG_IPREG_SYS1_REG_105_IPREG_SYS1                            0xa469
#define REG_IPREG_SYS1_REG_106_IPREG_SYS1                            0xa46a
#define REG_IPREG_SYS1_REG_107_IPREG_SYS1                            0xa46b
#define REG_IPREG_SYS1_REG_108_IPREG_SYS1                            0xa46c
#define REG_IPREG_SYS1_REG_109_IPREG_SYS1                            0xa46d
#define REG_IPREG_SYS1_REG_110_IPREG_SYS1                            0xa46e
#define REG_IPREG_SYS1_REG_111_IPREG_SYS1                            0xa46f
#define REG_IPREG_SYS1_REG_112_IPREG_SYS1                            0xa470
#define REG_IPREG_SYS1_REG_113_IPREG_SYS1                            0xa471
#define REG_IPREG_SYS1_REG_114_IPREG_SYS1                            0xa472
#define REG_IPREG_SYS1_REG_115_IPREG_SYS1                            0xa473
#define REG_IPREG_SYS1_REG_116_IPREG_SYS1                            0xa474
#define REG_IPREG_SYS1_REG_117_IPREG_SYS1                            0xa475
#define REG_IPREG_SYS1_REG_118_IPREG_SYS1                            0xa476
#define REG_IPREG_SYS1_REG_119_IPREG_SYS1                            0xa477
#define REG_IPREG_SYS1_REG_120_IPREG_SYS1                            0xa478
#define REG_IPREG_SYS1_REG_121_IPREG_SYS1                            0xa479
#define REG_IPREG_SYS1_REG_122_IPREG_SYS1                            0xa47a
#define REG_IPREG_SYS1_REG_123_IPREG_SYS1                            0xa47b
#define REG_IPREG_SYS1_REG_124_IPREG_SYS1                            0xa47c
#define REG_IPREG_SYS1_REG_125_IPREG_SYS1                            0xa47d
#define REG_IPREG_SYS1_REG_126_IPREG_SYS1                            0xa47e
#define REG_IPREG_SYS1_REG_127_IPREG_SYS1                            0xa47f
#define REG_IPREG_SYS1_REG_128_IPREG_SYS1                            0xa480
#define REG_IPREG_SYS1_REG_129_IPREG_SYS1                            0xa481
#define REG_IPREG_SYS1_REG_130_IPREG_SYS1                            0xa482
#define REG_IPREG_SYS1_REG_131_IPREG_SYS1                            0xa483
#define REG_IPREG_SYS1_REG_132_IPREG_SYS1                            0xa484
#define REG_IPREG_SYS1_REG_133_IPREG_SYS1                            0xa485
#define REG_IPREG_SYS1_REG_134_IPREG_SYS1                            0xa486
#define REG_IPREG_SYS1_REG_135_IPREG_SYS1                            0xa487
#define REG_IPREG_SYS1_REG_136_IPREG_SYS1                            0xa488
#define REG_IPREG_SYS1_REG_137_IPREG_SYS1                            0xa489
#define REG_IPREG_SYS1_REG_138_IPREG_SYS1                            0xa48a
#define REG_IPREG_SYS1_REG_139_IPREG_SYS1                            0xa48b
#define REG_IPREG_SYS1_REG_140_IPREG_SYS1                            0xa48c
#define REG_IPREG_SYS1_REG_141_IPREG_SYS1                            0xa48d
#define REG_IPREG_SYS1_REG_142_IPREG_SYS1                            0xa48e
#define REG_IPREG_SYS1_REG_143_IPREG_SYS1                            0xa48f
#define REG_IPREG_SYS1_REG_144_IPREG_SYS1                            0xa490
#define REG_IPREG_SYS1_REG_145_IPREG_SYS1                            0xa491
#define REG_IPREG_SYS1_REG_146_IPREG_SYS1                            0xa492
#define REG_IPREG_SYS1_REG_147_IPREG_SYS1                            0xa493
#define REG_IPREG_SYS1_REG_148_IPREG_SYS1                            0xa494
#define REG_IPREG_SYS1_REG_149_IPREG_SYS1                            0xa495
#define REG_IPREG_SYS1_REG_150_IPREG_SYS1                            0xa496
#define REG_IPREG_SYS1_REG_151_IPREG_SYS1                            0xa497
#define REG_IPREG_SYS1_REG_152_IPREG_SYS1                            0xa498
#define REG_IPREG_SYS1_REG_153_IPREG_SYS1                            0xa499
#define REG_IPREG_SYS1_REG_154_IPREG_SYS1                            0xa49a
#define REG_IPREG_SYS1_REG_155_IPREG_SYS1                            0xa49b
#define REG_IPREG_SYS1_REG_156_IPREG_SYS1                            0xa49c
#define REG_IPREG_SYS1_REG_157_IPREG_SYS1                            0xa49d
#define REG_IPREG_SYS1_REG_158_IPREG_SYS1                            0xa49e
#define REG_IPREG_SYS1_REG_159_IPREG_SYS1                            0xa49f
#define REG_IPREG_SYS1_REG_160_IPREG_SYS1                            0xa4a0
#define REG_IPREG_SYS1_REG_161_IPREG_SYS1                            0xa4a1
#define REG_IPREG_SYS1_REG_162_IPREG_SYS1                            0xa4a2
#define REG_IPREG_SYS1_REG_163_IPREG_SYS1                            0xa4a3
#define REG_IPREG_SYS1_REG_164_IPREG_SYS1                            0xa4a4
#define REG_IPREG_SYS1_REG_165_IPREG_SYS1                            0xa4a5
#define REG_IPREG_SYS1_REG_166_IPREG_SYS1                            0xa4a6
#define REG_IPREG_SYS1_REG_167_IPREG_SYS1                            0xa4a7
#define REG_IPREG_SYS1_REG_168_IPREG_SYS1                            0xa4a8
#define REG_IPREG_SYS1_REG_169_IPREG_SYS1                            0xa4a9
#define REG_IPREG_SYS1_REG_170_IPREG_SYS1                            0xa4aa
#define REG_IPREG_SYS1_REG_171_IPREG_SYS1                            0xa4ab
#define REG_IPREG_SYS1_REG_172_IPREG_SYS1                            0xa4ac
#define REG_IPREG_SYS1_REG_173_IPREG_SYS1                            0xa4ad

/* IPREG_SYS2 */
#define REG_IPREG_SYS2_REG_0_IPREG_SYS2                              0xa500
#define REG_IPREG_SYS2_REG_1_IPREG_SYS2                              0xa501
#define REG_IPREG_SYS2_REG_2_IPREG_SYS2                              0xa502
#define REG_IPREG_SYS2_REG_3_IPREG_SYS2                              0xa503
#define REG_IPREG_SYS2_REG_4_IPREG_SYS2                              0xa504
#define REG_IPREG_SYS2_REG_5_IPREG_SYS2                              0xa505
#define REG_IPREG_SYS2_REG_6_IPREG_SYS2                              0xa506
#define REG_IPREG_SYS2_REG_7_IPREG_SYS2                              0xa507
#define REG_IPREG_SYS2_REG_8_IPREG_SYS2                              0xa508
#define REG_IPREG_SYS2_REG_9_IPREG_SYS2                              0xa509
#define REG_IPREG_SYS2_REG_10_IPREG_SYS2                             0xa50a
#define REG_IPREG_SYS2_REG_11_IPREG_SYS2                             0xa50b
#define REG_IPREG_SYS2_REG_12_IPREG_SYS2                             0xa50c
#define REG_IPREG_SYS2_REG_13_IPREG_SYS2                             0xa50d
#define REG_IPREG_SYS2_REG_14_IPREG_SYS2                             0xa50e
#define REG_IPREG_SYS2_REG_15_IPREG_SYS2                             0xa50f
#define REG_IPREG_SYS2_REG_16_IPREG_SYS2                             0xa510
#define REG_IPREG_SYS2_REG_17_IPREG_SYS2                             0xa511
#define REG_IPREG_SYS2_REG_18_IPREG_SYS2                             0xa512
#define REG_IPREG_SYS2_REG_19_IPREG_SYS2                             0xa513
#define REG_IPREG_SYS2_REG_20_IPREG_SYS2                             0xa514
#define REG_IPREG_SYS2_REG_21_IPREG_SYS2                             0xa515
#define REG_IPREG_SYS2_REG_22_IPREG_SYS2                             0xa516
#define REG_IPREG_SYS2_REG_23_IPREG_SYS2                             0xa517
#define REG_IPREG_SYS2_REG_24_IPREG_SYS2                             0xa518
#define REG_IPREG_SYS2_REG_25_IPREG_SYS2                             0xa519
#define REG_IPREG_SYS2_REG_26_IPREG_SYS2                             0xa51a
#define REG_IPREG_SYS2_REG_27_IPREG_SYS2                             0xa51b
#define REG_IPREG_SYS2_REG_28_IPREG_SYS2                             0xa51c
#define REG_IPREG_SYS2_REG_29_IPREG_SYS2                             0xa51d
#define REG_IPREG_SYS2_REG_30_IPREG_SYS2                             0xa51e
#define REG_IPREG_SYS2_REG_31_IPREG_SYS2                             0xa51f
#define REG_IPREG_SYS2_REG_32_IPREG_SYS2                             0xa520
#define REG_IPREG_SYS2_REG_33_IPREG_SYS2                             0xa521
#define REG_IPREG_SYS2_REG_34_IPREG_SYS2                             0xa522
#define REG_IPREG_SYS2_REG_35_IPREG_SYS2                             0xa523
#define REG_IPREG_SYS2_REG_36_IPREG_SYS2                             0xa524
#define REG_IPREG_SYS2_REG_37_IPREG_SYS2                             0xa525
#define REG_IPREG_SYS2_REG_38_IPREG_SYS2                             0xa526
#define REG_IPREG_SYS2_REG_39_IPREG_SYS2                             0xa527
#define REG_IPREG_SYS2_REG_40_IPREG_SYS2                             0xa528
#define REG_IPREG_SYS2_REG_41_IPREG_SYS2                             0xa529
#define REG_IPREG_SYS2_REG_42_IPREG_SYS2                             0xa52a
#define REG_IPREG_SYS2_REG_43_IPREG_SYS2                             0xa52b
#define REG_IPREG_SYS2_REG_44_IPREG_SYS2                             0xa52c
#define REG_IPREG_SYS2_REG_45_IPREG_SYS2                             0xa52d
#define REG_IPREG_SYS2_REG_46_IPREG_SYS2                             0xa52e
#define REG_IPREG_SYS2_REG_47_IPREG_SYS2                             0xa52f
#define REG_IPREG_SYS2_REG_48_IPREG_SYS2                             0xa530
#define REG_IPREG_SYS2_REG_49_IPREG_SYS2                             0xa531
#define REG_IPREG_SYS2_REG_50_IPREG_SYS2                             0xa532
#define REG_IPREG_SYS2_REG_51_IPREG_SYS2                             0xa533
#define REG_IPREG_SYS2_REG_52_IPREG_SYS2                             0xa534
#define REG_IPREG_SYS2_REG_53_IPREG_SYS2                             0xa535
#define REG_IPREG_SYS2_REG_54_IPREG_SYS2                             0xa536
#define REG_IPREG_SYS2_REG_55_IPREG_SYS2                             0xa537
#define REG_IPREG_SYS2_REG_56_IPREG_SYS2                             0xa538
#define REG_IPREG_SYS2_REG_57_IPREG_SYS2                             0xa539
#define REG_IPREG_SYS2_REG_58_IPREG_SYS2                             0xa53a
#define REG_IPREG_SYS2_REG_59_IPREG_SYS2                             0xa53b
#define REG_IPREG_SYS2_REG_60_IPREG_SYS2                             0xa53c
#define REG_IPREG_SYS2_REG_61_IPREG_SYS2                             0xa53d
#define REG_IPREG_SYS2_REG_62_IPREG_SYS2                             0xa53e
#define REG_IPREG_SYS2_REG_63_IPREG_SYS2                             0xa53f
#define REG_IPREG_SYS2_REG_64_IPREG_SYS2                             0xa540
#define REG_IPREG_SYS2_REG_65_IPREG_SYS2                             0xa541
#define REG_IPREG_SYS2_REG_66_IPREG_SYS2                             0xa542
#define REG_IPREG_SYS2_REG_67_IPREG_SYS2                             0xa543
#define REG_IPREG_SYS2_REG_68_IPREG_SYS2                             0xa544
#define REG_IPREG_SYS2_REG_69_IPREG_SYS2                             0xa545
#define REG_IPREG_SYS2_REG_70_IPREG_SYS2                             0xa546
#define REG_IPREG_SYS2_REG_71_IPREG_SYS2                             0xa547
#define REG_IPREG_SYS2_REG_72_IPREG_SYS2                             0xa548
#define REG_IPREG_SYS2_REG_73_IPREG_SYS2                             0xa549
#define REG_IPREG_SYS2_REG_74_IPREG_SYS2                             0xa54a
#define REG_IPREG_SYS2_REG_75_IPREG_SYS2                             0xa54b
#define REG_IPREG_SYS2_REG_76_IPREG_SYS2                             0xa54c
#define REG_IPREG_SYS2_REG_77_IPREG_SYS2                             0xa54d
#define REG_IPREG_SYS2_REG_78_IPREG_SYS2                             0xa54e
#define REG_IPREG_SYS2_REG_79_IPREG_SYS2                             0xa54f
#define REG_IPREG_SYS2_REG_80_IPREG_SYS2                             0xa550
#define REG_IPREG_SYS2_REG_81_IPREG_SYS2                             0xa551
#define REG_IPREG_SYS2_REG_82_IPREG_SYS2                             0xa552
#define REG_IPREG_SYS2_REG_83_IPREG_SYS2                             0xa553
#define REG_IPREG_SYS2_REG_84_IPREG_SYS2                             0xa554
#define REG_IPREG_SYS2_REG_85_IPREG_SYS2                             0xa555
#define REG_IPREG_SYS2_REG_86_IPREG_SYS2                             0xa556
#define REG_IPREG_SYS2_REG_87_IPREG_SYS2                             0xa557
#define REG_IPREG_SYS2_REG_88_IPREG_SYS2                             0xa558
#define REG_IPREG_SYS2_REG_89_IPREG_SYS2                             0xa559
#define REG_IPREG_SYS2_REG_90_IPREG_SYS2                             0xa55a
#define REG_IPREG_SYS2_REG_91_IPREG_SYS2                             0xa55b
#define REG_IPREG_SYS2_REG_92_IPREG_SYS2                             0xa55c
#define REG_IPREG_SYS2_REG_93_IPREG_SYS2                             0xa55d
#define REG_IPREG_SYS2_REG_94_IPREG_SYS2                             0xa55e
#define REG_IPREG_SYS2_REG_95_IPREG_SYS2                             0xa55f
#define REG_IPREG_SYS2_REG_96_IPREG_SYS2                             0xa560
#define REG_IPREG_SYS2_REG_97_IPREG_SYS2                             0xa561
#define REG_IPREG_SYS2_REG_98_IPREG_SYS2                             0xa562
#define REG_IPREG_SYS2_REG_99_IPREG_SYS2                             0xa563
#define REG_IPREG_SYS2_REG_100_IPREG_SYS2                            0xa564
#define REG_IPREG_SYS2_REG_101_IPREG_SYS2                            0xa565
#define REG_IPREG_SYS2_REG_102_IPREG_SYS2                            0xa566
#define REG_IPREG_SYS2_REG_103_IPREG_SYS2                            0xa567
#define REG_IPREG_SYS2_REG_104_IPREG_SYS2                            0xa568
#define REG_IPREG_SYS2_REG_105_IPREG_SYS2                            0xa569
#define REG_IPREG_SYS2_REG_106_IPREG_SYS2                            0xa56a
#define REG_IPREG_SYS2_REG_107_IPREG_SYS2                            0xa56b
#define REG_IPREG_SYS2_REG_108_IPREG_SYS2                            0xa56c
#define REG_IPREG_SYS2_REG_109_IPREG_SYS2                            0xa56d
#define REG_IPREG_SYS2_REG_110_IPREG_SYS2                            0xa56e
#define REG_IPREG_SYS2_REG_111_IPREG_SYS2                            0xa56f
#define REG_IPREG_SYS2_REG_112_IPREG_SYS2                            0xa570
#define REG_IPREG_SYS2_REG_113_IPREG_SYS2                            0xa571
#define REG_IPREG_SYS2_REG_114_IPREG_SYS2                            0xa572
#define REG_IPREG_SYS2_REG_115_IPREG_SYS2                            0xa573
#define REG_IPREG_SYS2_REG_116_IPREG_SYS2                            0xa574
#define REG_IPREG_SYS2_REG_117_IPREG_SYS2                            0xa575
#define REG_IPREG_SYS2_REG_118_IPREG_SYS2                            0xa576
#define REG_IPREG_SYS2_REG_119_IPREG_SYS2                            0xa577
#define REG_IPREG_SYS2_REG_120_IPREG_SYS2                            0xa578
#define REG_IPREG_SYS2_REG_121_IPREG_SYS2                            0xa579
#define REG_IPREG_SYS2_REG_122_IPREG_SYS2                            0xa57a
#define REG_IPREG_SYS2_REG_123_IPREG_SYS2                            0xa57b
#define REG_IPREG_SYS2_REG_124_IPREG_SYS2                            0xa57c
#define REG_IPREG_SYS2_REG_125_IPREG_SYS2                            0xa57d
#define REG_IPREG_SYS2_REG_126_IPREG_SYS2                            0xa57e
#define REG_IPREG_SYS2_REG_127_IPREG_SYS2                            0xa57f
#define REG_IPREG_SYS2_REG_128_IPREG_SYS2                            0xa580
#define REG_IPREG_SYS2_REG_129_IPREG_SYS2                            0xa581
#define REG_IPREG_SYS2_REG_130_IPREG_SYS2                            0xa582
#define REG_IPREG_SYS2_REG_131_IPREG_SYS2                            0xa583
#define REG_IPREG_SYS2_REG_132_IPREG_SYS2                            0xa584

/* IPREG_TOP1 */
#define REG_FIFO_STATUS_IPREG_TOP1                                   0xa200
#define REG_PRG_ERR_STATUS_IPREG_TOP1                                0xa202
#define REG_FIFO_LOST_COUNT_IPREG_TOP1                               0xa204
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
#define REG_I3C_PROV_ID_0_IPREG_TOP1                                 0xa23f
#define REG_I3C_PROV_ID_1_IPREG_TOP1                                 0xa240
#define REG_I3C_PROV_ID_2_IPREG_TOP1                                 0xa241
#define REG_I3C_PROV_ID_3_IPREG_TOP1                                 0xa242
#define REG_I3C_PROV_ID_4_IPREG_TOP1                                 0xa243
#define REG_I3C_PROV_ID_5_IPREG_TOP1                                 0xa244
#define REG_SIFS_I3C_BCR_IPREG_TOP1                                  0xa245
#define REG_SIFS_I3C_DCR_IPREG_TOP1                                  0xa246
#define REG_SIFS_CONTROL_IPREG_TOP1                                  0xa247
#define REG_SIFS_GETMXDS_MAXWR_IPREG_TOP1                            0xa248
#define REG_SIFS_GETMXDS_MAXRD_IPREG_TOP1                            0xa249
#define REG_SIFS_IXC_ERROR_STATUS_IPREG_TOP1                         0xa24b
#define REG_INTF_CONFIG_IPREG_TOP1                                   0xa24e
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
#define REG_PSEQ_FORCE_CTRL_0_IPREG_TOP1                             0xa275
#define REG_PSEQ_FORCE_CTRL_1_IPREG_TOP1                             0xa276
#define REG_PSEQ_FORCE_CTRL_2_IPREG_TOP1                             0xa277
#define REG_PSEQ_FORCE_CTRL_3_IPREG_TOP1                             0xa278
#define REG_PSEQ_FORCE_CTRL_4_IPREG_TOP1                             0xa279
#define REG_PSEQ_FORCE_CTRL_5_IPREG_TOP1                             0xa27a
#define REG_PSEQ_FORCE_CTRL_6_IPREG_TOP1                             0xa27b
#define REG_PSEQ_FORCE_CTRL_7_IPREG_TOP1                             0xa27c
#define REG_PSEQ_STATUS_IPREG_TOP1                                   0xa27d
#define REG_ACCEL_WOM_X_THR_IPREG_TOP1                               0xa27e
#define REG_ACCEL_WOM_Y_THR_IPREG_TOP1                               0xa27f
#define REG_ACCEL_WOM_Z_THR_IPREG_TOP1                               0xa280
#define REG_CKGA_CONFIG_IPREG_TOP1                                   0xa281
#define REG_CKGA_RCOSC_READY_TRIM_IPREG_TOP1                         0xa282
#define REG_IOC_PADS_TP_OVRD_IPREG_TOP1                              0xa283
#define REG_IOC_PADS_CONFIG0_IPREG_TOP1                              0xa284
#define REG_IOC_PADS_CONFIG1_IPREG_TOP1                              0xa285
#define REG_IOC_VOHVOL_IPREG_TOP1                                    0xa286
#define REG_IOC_VIHVIL_IPREG_TOP1                                    0xa287
#define REG_BAR_CONFIG_IPREG_TOP1                                    0xa288
#define REG_IREG_OTP_CFG_IPREG_TOP1                                  0xa289
#define REG_IREG_OTP_STATUS_IPREG_TOP1                               0xa28a
#define REG_OTP_CONFIG0_IPREG_TOP1                                   0xa28b
#define REG_OTP_CALCULATED_CRC_0_IPREG_TOP1                          0xa28c
#define REG_OTP_CALCULATED_CRC_1_IPREG_TOP1                          0xa28d
#define REG_HEAT_CTRL1_IPREG_TOP1                                    0xa28e
#define REG_HEAT_CTRL2_IPREG_TOP1                                    0xa28f
#define REG_SELFTEST_IPREG_TOP1                                      0xa290
#define REG_GYRO_SC2V_IPREG_TOP1                                     0xa291
#define REG_DTMD_DEBUG_CONFIG_IPREG_TOP1                             0xa292
#define REG_DTMD_OUT_IN_SEL_IPREG_TOP1                               0xa293
#define REG_DTMD_OUT_MODE_SEL_IPREG_TOP1                             0xa294
#define REG_RESERVED_OTP_BYTE3_IPREG_TOP1                            0xa295
#define REG_RESERVED_OTP_BYTE4_IPREG_TOP1                            0xa296
#define REG_IPREG_MISC_IPREG_TOP1                                    0xa297
#define REG_DIG_SPARE0_IPREG_TOP1                                    0xa298
#define REG_DIG_SPARE1_IPREG_TOP1                                    0xa299
#define REG_DIG_SPARE2_IPREG_TOP1                                    0xa29a
#define REG_DIG_SPARE3_IPREG_TOP1                                    0xa29b
#define REG_DIG_SPARE4_IPREG_TOP1                                    0xa29c
#define REG_DIG_SPARE5_IPREG_TOP1                                    0xa29d
#define REG_SW_RCOSC1_TRIM_IPREG_TOP1                                0xa2a1
#define REG_SW_PLL1_TRIM_IPREG_TOP1                                  0xa2a2
#define REG_SA_KEY1_LAST_BYTE_IPREG_TOP1                             0xa2a3
#define REG_AUX1_INTF_CONFIG_IPREG_TOP1                              0xa2a4
#define REG_AUX1_SIFS_GETMXDS_MAXWR_IPREG_TOP1                       0xa2a5
#define REG_AUX1_SIFS_GETMXDS_MAXRD_IPREG_TOP1                       0xa2a6
#define REG_FIFO_SRAM_SLEEP_IPREG_TOP1                               0xa2a7
#define REG_FIFO_SRAM_RET_IPREG_TOP1                                 0xa2a8
#define REG_OTP_EXPECTED_CRC_0_IPREG_TOP1                            0xa2fc
#define REG_OTP_EXPECTED_CRC_1_IPREG_TOP1                            0xa2fd
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
#define REG_REG_MISC4_DREG_BANK1                                     0x37
#define REG_REG_MISC0_DREG_BANK1                                     0x38
#define REG_INT_APEX_CONFIG0_DREG_BANK1                              0x39
#define REG_INT_APEX_CONFIG1_DREG_BANK1                              0x3a
#define REG_INT_APEX_STATUS0_DREG_BANK1                              0x3b
#define REG_INT_APEX_STATUS1_DREG_BANK1                              0x3c
#define REG_DIG_SPARE6_DREG_BANK1                                    0x3d
#define REG_DIG_SPARE7_DREG_BANK1                                    0x3e
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
#define REG_INTF_COMM_ERR_DREG_BANK1                                 0x78
#define REG_IREG_ADDR_31_24_DREG_BANK1                               0x7a
#define REG_IREG_ADDR_23_16_DREG_BANK1                               0x7b
#define REG_IREG_ADDR_15_8_DREG_BANK1                                0x7c
#define REG_IREG_ADDR_7_0_DREG_BANK1                                 0x7d
#define REG_IREG_DATA_DREG_BANK1                                     0x7e
#define REG_REG_MISC2_DREG_BANK1                                     0x7f

/* DREG_BANK2 */
#define REG_STC_DT_DREG_BANK2                                        0x81
#define REG_STC_TU_DREG_BANK2                                        0x82
#define REG_STC_TPH_ACCEL_0_DREG_BANK2                               0x83
#define REG_STC_TPH_ACCEL_1_DREG_BANK2                               0x84
#define REG_STC_TPH_GYRO_0_DREG_BANK2                                0x85
#define REG_STC_TPH_GYRO_1_DREG_BANK2                                0x86
#define REG_STC_ODR_DREG_BANK2                                       0x87


/* ---------------------------------------------------------------------------
 * register IPREG_BAR
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_BAR_REG_0
 * Register Name : IPREG_BAR_REG_0
 */

/*
 * accel_bias_spare_d2a
 * [Supports Dynamic Change] spare bits
 */
#define REG_IPREG_BAR_REG_0_ACCEL_BIAS_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_0_ACCEL_BIAS_SPARE_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_1
 * Register Name : IPREG_BAR_REG_1
 */

/*
 * en_accel_drive_half_d2a
 * [Supports Dynamic Change] Set drive buffer output to 1.25 V
 */
#define REG_IPREG_BAR_REG_1_EN_ACCEL_DRIVE_HALF_D2A_POS      0x00
#define REG_IPREG_BAR_REG_1_EN_ACCEL_DRIVE_HALF_D2A_MASK     0x01

/*
 * pd_accel_areg_b_d2a
 * [Supports Dynamic Change] Override to power-down Accel AREG
 */
#define REG_IPREG_BAR_REG_1_PD_ACCEL_AREG_B_D2A_POS      0x01
#define REG_IPREG_BAR_REG_1_PD_ACCEL_AREG_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_1_PD_ACCEL_AREG_B_D2A_POS)

/*
 * pd_accel_cp3v_only_b_d2a
 * [Supports Dynamic Change] Override to power-down 3V CP
 */
#define REG_IPREG_BAR_REG_1_PD_ACCEL_CP3V_ONLY_B_D2A_POS      0x02
#define REG_IPREG_BAR_REG_1_PD_ACCEL_CP3V_ONLY_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_1_PD_ACCEL_CP3V_ONLY_B_D2A_POS)

/*
 * pd_accel_drivebuffer_b_d2a
 * [Supports Dynamic Change] Override to power-down Accel Drive Buffer
 */
#define REG_IPREG_BAR_REG_1_PD_ACCEL_DRIVEBUFFER_B_D2A_POS      0x03
#define REG_IPREG_BAR_REG_1_PD_ACCEL_DRIVEBUFFER_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_1_PD_ACCEL_DRIVEBUFFER_B_D2A_POS)

/*
 * pd_accel_iblend_b_d2a
 * [Supports Dynamic Change] Override to power-down Accel iblend circuit
 */
#define REG_IPREG_BAR_REG_1_PD_ACCEL_IBLEND_B_D2A_POS      0x04
#define REG_IPREG_BAR_REG_1_PD_ACCEL_IBLEND_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_1_PD_ACCEL_IBLEND_B_D2A_POS)

/*
 * pd_accel_vcmbuffer_b_d2a
 * [Supports Dynamic Change] Override to power-down VCM Buffer
 */
#define REG_IPREG_BAR_REG_1_PD_ACCEL_VCMBUFFER_B_D2A_POS      0x05
#define REG_IPREG_BAR_REG_1_PD_ACCEL_VCMBUFFER_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_1_PD_ACCEL_VCMBUFFER_B_D2A_POS)

/*
 * pd_az_shield_wimpy_b_d2a
 * [Supports Dynamic Change] Override to power-down wimpy cp
 */
#define REG_IPREG_BAR_REG_1_PD_AZ_SHIELD_WIMPY_B_D2A_POS      0x06
#define REG_IPREG_BAR_REG_1_PD_AZ_SHIELD_WIMPY_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_1_PD_AZ_SHIELD_WIMPY_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_2
 * Register Name : IPREG_BAR_REG_2
 */

/*
 * accel_spare_d2a
 * [Supports Dynamic Change] bit<4>: integrator polarity, bit<3>: enable adc zero correction, bit<2>: keep adc internal vcm levels constant
 */
#define REG_IPREG_BAR_REG_2_ACCEL_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_2_ACCEL_SPARE_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_3
 * Register Name : IPREG_BAR_REG_3
 */

/*
 * en_ana_st_vref_d2a
 * [Supports Dynamic Change] Put test buffer reference voltage in BIST mode
 */
#define REG_IPREG_BAR_REG_3_EN_ANA_ST_VREF_D2A_POS      0x00
#define REG_IPREG_BAR_REG_3_EN_ANA_ST_VREF_D2A_MASK     0x0f

/*
 * accel_dig_tmode_cfg_d2a
 * [Supports Dynamic Change] digital test mode configuration
 */
#define REG_IPREG_BAR_REG_3_ACCEL_DIG_TMODE_CFG_D2A_POS      0x04
#define REG_IPREG_BAR_REG_3_ACCEL_DIG_TMODE_CFG_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_3_ACCEL_DIG_TMODE_CFG_D2A_POS)



/*
 * REG_IPREG_BAR_REG_4
 * Register Name : IPREG_BAR_REG_4
 */

/*
 * accel_test_cfg_d2a
 * [Supports Dynamic Change] Analog test MUX configuration
 */
#define REG_IPREG_BAR_REG_4_ACCEL_TEST_CFG_D2A_POS      0x00
#define REG_IPREG_BAR_REG_4_ACCEL_TEST_CFG_D2A_MASK     0x07

/*
 * accel_testbuffer_gain_d2a
 * [Supports Dynamic Change] Test buffer gain trim
 */
#define REG_IPREG_BAR_REG_4_ACCEL_TESTBUFFER_GAIN_D2A_POS      0x03
#define REG_IPREG_BAR_REG_4_ACCEL_TESTBUFFER_GAIN_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_4_ACCEL_TESTBUFFER_GAIN_D2A_POS)

/*
 * accel_drv_mode_d2a
 * [Supports Dynamic Change] drive mode configuration
 */
#define REG_IPREG_BAR_REG_4_ACCEL_DRV_MODE_D2A_POS      0x06
#define REG_IPREG_BAR_REG_4_ACCEL_DRV_MODE_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_4_ACCEL_DRV_MODE_D2A_POS)



/*
 * REG_IPREG_BAR_REG_5
 * Register Name : IPREG_BAR_REG_5
 */

/*
 * accel_xyz_sel_0_d2d
 * [Supports Dynamic Change] Axis selection for slot 1 of Round-Robin operation
 */
#define REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_0_D2D_POS      0x00
#define REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_0_D2D_MASK     0x03

/*
 * accel_xyz_sel_1_d2d
 * [Supports Dynamic Change] Axis selection for slot 2 of Round-Robin operation
 */
#define REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_1_D2D_POS      0x02
#define REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_1_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_1_D2D_POS)

/*
 * accel_xyz_sel_2_d2d
 * [Supports Dynamic Change] Axis selection for slot 3 of Round-Robin operation
 */
#define REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_2_D2D_POS      0x04
#define REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_2_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_5_ACCEL_XYZ_SEL_2_D2D_POS)

/*
 * accel_adc_fixed_ref_d2a
 * [Supports Dynamic Change] Use fixed voltage for SAR ADC reference
 */
#define REG_IPREG_BAR_REG_5_ACCEL_ADC_FIXED_REF_D2A_POS      0x06
#define REG_IPREG_BAR_REG_5_ACCEL_ADC_FIXED_REF_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_5_ACCEL_ADC_FIXED_REF_D2A_POS)

/*
 * accel_cmos_only_d2a
 * [Supports Dynamic Change] Enable cmos-only mode
 */
#define REG_IPREG_BAR_REG_5_ACCEL_CMOS_ONLY_D2A_POS      0x07
#define REG_IPREG_BAR_REG_5_ACCEL_CMOS_ONLY_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_5_ACCEL_CMOS_ONLY_D2A_POS)



/*
 * REG_IPREG_BAR_REG_6
 * Register Name : IPREG_BAR_REG_6
 */

/*
 * accel_gaincal_en_d2a
 * [Supports Dynamic Change] enable gain calibration
 */
#define REG_IPREG_BAR_REG_6_ACCEL_GAINCAL_EN_D2A_POS      0x00
#define REG_IPREG_BAR_REG_6_ACCEL_GAINCAL_EN_D2A_MASK     0x01

/*
 * accel_gap_test_en_d2a
 * [Supports Dynamic Change] enable gap test mode
 */
#define REG_IPREG_BAR_REG_6_ACCEL_GAP_TEST_EN_D2A_POS      0x01
#define REG_IPREG_BAR_REG_6_ACCEL_GAP_TEST_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_ACCEL_GAP_TEST_EN_D2A_POS)

/*
 * accel_vdrivecal_en_d2a
 * [Supports Dynamic Change] enable vdirve calibration
 */
#define REG_IPREG_BAR_REG_6_ACCEL_VDRIVECAL_EN_D2A_POS      0x02
#define REG_IPREG_BAR_REG_6_ACCEL_VDRIVECAL_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_ACCEL_VDRIVECAL_EN_D2A_POS)

/*
 * ax_drive_reset_off_d2a
 * [Supports Dynamic Change] AX drive signal not from 1.25 V
 */
#define REG_IPREG_BAR_REG_6_AX_DRIVE_RESET_OFF_D2A_POS      0x03
#define REG_IPREG_BAR_REG_6_AX_DRIVE_RESET_OFF_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_AX_DRIVE_RESET_OFF_D2A_POS)

/*
 * axy_shldcal_en_d2a
 * [Supports Dynamic Change] Enable AXY vshield calibration
 */
#define REG_IPREG_BAR_REG_6_AXY_SHLDCAL_EN_D2A_POS      0x04
#define REG_IPREG_BAR_REG_6_AXY_SHLDCAL_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_AXY_SHLDCAL_EN_D2A_POS)

/*
 * ay_drive_reset_off_d2a
 * [Supports Dynamic Change] AY drive signal not from 1.25 V
 */
#define REG_IPREG_BAR_REG_6_AY_DRIVE_RESET_OFF_D2A_POS      0x05
#define REG_IPREG_BAR_REG_6_AY_DRIVE_RESET_OFF_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_AY_DRIVE_RESET_OFF_D2A_POS)

/*
 * az_drive_reset_off_d2a
 * [Supports Dynamic Change] AZ drive signal not from 1.25 V
 */
#define REG_IPREG_BAR_REG_6_AZ_DRIVE_RESET_OFF_D2A_POS      0x06
#define REG_IPREG_BAR_REG_6_AZ_DRIVE_RESET_OFF_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_AZ_DRIVE_RESET_OFF_D2A_POS)

/*
 * en_accel_testbuffer_higain_d2a
 * [Supports Dynamic Change] Enable test buffer in high-gain mode
 */
#define REG_IPREG_BAR_REG_6_EN_ACCEL_TESTBUFFER_HIGAIN_D2A_POS      0x07
#define REG_IPREG_BAR_REG_6_EN_ACCEL_TESTBUFFER_HIGAIN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_6_EN_ACCEL_TESTBUFFER_HIGAIN_D2A_POS)



/*
 * REG_IPREG_BAR_REG_7
 * Register Name : IPREG_BAR_REG_7
 */

/*
 * en_accel_testbuffer_sw_pm1_d2a
 * [Supports Dynamic Change] Test buffer input switch 1 closed
 */
#define REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_SW_PM1_D2A_POS      0x00
#define REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_SW_PM1_D2A_MASK     0x01

/*
 * en_accel_testbuffer_sw_pm2_d2a
 * [Supports Dynamic Change] Test buffer input switch 2 closed
 */
#define REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_SW_PM2_D2A_POS      0x01
#define REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_SW_PM2_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_SW_PM2_D2A_POS)

/*
 * en_accel_testbuffer_ugdrive_d2a
 * [Supports Dynamic Change] Put test buffer in buffer mode
 */
#define REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_UGDRIVE_D2A_POS      0x02
#define REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_UGDRIVE_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_EN_ACCEL_TESTBUFFER_UGDRIVE_D2A_POS)

/*
 * en_ana_st_adc_in_d2a
 * [Supports Dynamic Change] Put ADC in BIST configuration
 */
#define REG_IPREG_BAR_REG_7_EN_ANA_ST_ADC_IN_D2A_POS      0x03
#define REG_IPREG_BAR_REG_7_EN_ANA_ST_ADC_IN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_EN_ANA_ST_ADC_IN_D2A_POS)

/*
 * pd_accel_adc_b_d2a
 * [Supports Dynamic Change] Override bit for ADC power down
 */
#define REG_IPREG_BAR_REG_7_PD_ACCEL_ADC_B_D2A_POS      0x04
#define REG_IPREG_BAR_REG_7_PD_ACCEL_ADC_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_PD_ACCEL_ADC_B_D2A_POS)

/*
 * pd_accel_adc_ref_b_d2a
 * [Supports Dynamic Change] Override bit for ADC reference power down
 */
#define REG_IPREG_BAR_REG_7_PD_ACCEL_ADC_REF_B_D2A_POS      0x05
#define REG_IPREG_BAR_REG_7_PD_ACCEL_ADC_REF_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_PD_ACCEL_ADC_REF_B_D2A_POS)

/*
 * pd_accel_c2v_b_d2a
 * [Supports Dynamic Change] Override bit for C2V power down
 */
#define REG_IPREG_BAR_REG_7_PD_ACCEL_C2V_B_D2A_POS      0x06
#define REG_IPREG_BAR_REG_7_PD_ACCEL_C2V_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_PD_ACCEL_C2V_B_D2A_POS)

/*
 * pd_accel_int_b_d2a
 * [Supports Dynamic Change] Override bit for Integrator power down
 */
#define REG_IPREG_BAR_REG_7_PD_ACCEL_INT_B_D2A_POS      0x07
#define REG_IPREG_BAR_REG_7_PD_ACCEL_INT_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_7_PD_ACCEL_INT_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_8
 * Register Name : IPREG_BAR_REG_8
 */

/*
 * pd_accel_testbuffer_b_d2a
 * [Supports Dynamic Change] Test buffer power down
 */
#define REG_IPREG_BAR_REG_8_PD_ACCEL_TESTBUFFER_B_D2A_POS      0x00
#define REG_IPREG_BAR_REG_8_PD_ACCEL_TESTBUFFER_B_D2A_MASK     0x01

/*
 * pd_accel_testbuffer_hv_b_d2a
 * [Supports Dynamic Change] Test buffer AREG power down
 */
#define REG_IPREG_BAR_REG_8_PD_ACCEL_TESTBUFFER_HV_B_D2A_POS      0x01
#define REG_IPREG_BAR_REG_8_PD_ACCEL_TESTBUFFER_HV_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_8_PD_ACCEL_TESTBUFFER_HV_B_D2A_POS)

/*
 * pd_ax_drive_b_d2a
 * [Supports Dynamic Change] AX MEMS not driven when low
 */
#define REG_IPREG_BAR_REG_8_PD_AX_DRIVE_B_D2A_POS      0x02
#define REG_IPREG_BAR_REG_8_PD_AX_DRIVE_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_8_PD_AX_DRIVE_B_D2A_POS)

/*
 * pd_ay_drive_b_d2a
 * [Supports Dynamic Change] AY MEMS not driven when low
 */
#define REG_IPREG_BAR_REG_8_PD_AY_DRIVE_B_D2A_POS      0x03
#define REG_IPREG_BAR_REG_8_PD_AY_DRIVE_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_8_PD_AY_DRIVE_B_D2A_POS)

/*
 * pd_az_drive_b_d2a
 * [Supports Dynamic Change] AZ MEMS not driven when low
 */
#define REG_IPREG_BAR_REG_8_PD_AZ_DRIVE_B_D2A_POS      0x04
#define REG_IPREG_BAR_REG_8_PD_AZ_DRIVE_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_8_PD_AZ_DRIVE_B_D2A_POS)

/*
 * rst_accel_adc_b_d2a
 * [Supports Dynamic Change] Override for ADC rst_b signal
 */
#define REG_IPREG_BAR_REG_8_RST_ACCEL_ADC_B_D2A_POS      0x05
#define REG_IPREG_BAR_REG_8_RST_ACCEL_ADC_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_8_RST_ACCEL_ADC_B_D2A_POS)

/*
 * rst_accel_arr_b_d2d
 * [Supports Dynamic Change] Override for Accel RR operation rst_b signal
 */
#define REG_IPREG_BAR_REG_8_RST_ACCEL_ARR_B_D2D_POS      0x06
#define REG_IPREG_BAR_REG_8_RST_ACCEL_ARR_B_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_8_RST_ACCEL_ARR_B_D2D_POS)

/*
 * rst_accel_c2v_b_d2a
 * [Supports Dynamic Change] Overide for C2V rst_b
 */
#define REG_IPREG_BAR_REG_8_RST_ACCEL_C2V_B_D2A_POS      0x07
#define REG_IPREG_BAR_REG_8_RST_ACCEL_C2V_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_8_RST_ACCEL_C2V_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_9
 * Register Name : IPREG_BAR_REG_9
 */

/*
 * rst_accel_integ_b_d2a
 * [Supports Dynamic Change] Overide for integrator rst_b
 */
#define REG_IPREG_BAR_REG_9_RST_ACCEL_INTEG_B_D2A_POS      0x00
#define REG_IPREG_BAR_REG_9_RST_ACCEL_INTEG_B_D2A_MASK     0x01

/*
 * rst_accel_testbuffer_b_d2a
 * [Supports Dynamic Change] Reset Accel test buffer
 */
#define REG_IPREG_BAR_REG_9_RST_ACCEL_TESTBUFFER_B_D2A_POS      0x01
#define REG_IPREG_BAR_REG_9_RST_ACCEL_TESTBUFFER_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_9_RST_ACCEL_TESTBUFFER_B_D2A_POS)

/*
 * rst_accel_testbuffer_dmd_b_d2a
 * [Supports Dynamic Change] Reset Accel test buffer DMD
 */
#define REG_IPREG_BAR_REG_9_RST_ACCEL_TESTBUFFER_DMD_B_D2A_POS      0x02
#define REG_IPREG_BAR_REG_9_RST_ACCEL_TESTBUFFER_DMD_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_9_RST_ACCEL_TESTBUFFER_DMD_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_10
 * Register Name : IPREG_BAR_REG_10
 */

/*
 * gyro_dc2v_gp_analog_d2a
 * [Supports Dynamic Change] general purpose analog
 */
#define REG_IPREG_BAR_REG_10_GYRO_DC2V_GP_ANALOG_D2A_POS      0x00
#define REG_IPREG_BAR_REG_10_GYRO_DC2V_GP_ANALOG_D2A_MASK     0x03



/*
 * REG_IPREG_BAR_REG_11
 * Register Name : IPREG_BAR_REG_11
 */

/*
 * gyro_cp25v_dft50n_d2a
 * [Supports Dynamic Change] In test-mode, this register increases the chain's DC current load from 50nA. Used to check current margin on the chain design.
 */
#define REG_IPREG_BAR_REG_11_GYRO_CP25V_DFT50N_D2A_POS      0x00
#define REG_IPREG_BAR_REG_11_GYRO_CP25V_DFT50N_D2A_MASK     0x0f

/*
 * gyro_cp25v_spare_d2a
 * [Supports Dynamic Change] Spare bits
 */
#define REG_IPREG_BAR_REG_11_GYRO_CP25V_SPARE_D2A_POS      0x04
#define REG_IPREG_BAR_REG_11_GYRO_CP25V_SPARE_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_11_GYRO_CP25V_SPARE_D2A_POS)



/*
 * REG_IPREG_BAR_REG_12
 * Register Name : IPREG_BAR_REG_12
 */

/*
 * en_ana_st_atp_d2a
 * [Supports Dynamic Change] 4 bits to control the slection of output from analog test buffer. 0 no selection of analog test buffer . 0001 selects tp0 analog test buffer output (pads_vbuf_int1_tp0_out). 0010 selects tp1 analog test buffer output (pads_vbuf_aux_sdi_tp1_out). 0100 selects tp2 analog test buffer output (pads_vbuf_aux_sclk_tp2_out). 1000 selects tp3 analog test buffer output (pads_vbuf_aux_cs_tp3_out).
 */
#define REG_IPREG_BAR_REG_12_EN_ANA_ST_ATP_D2A_POS      0x00
#define REG_IPREG_BAR_REG_12_EN_ANA_ST_ATP_D2A_MASK     0x0f

/*
 * io_char_filt_nofilt_sel_d2a
 * [Supports Dynamic Change] Selects either the pads_aux_sclk_tp2_from_pad_d2a path (0) or the pads_aux_sclk_tp2_filt_d2a glitch filter path (1)
 */
#define REG_IPREG_BAR_REG_12_IO_CHAR_FILT_NOFILT_SEL_D2A_POS      0x04
#define REG_IPREG_BAR_REG_12_IO_CHAR_FILT_NOFILT_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_12_IO_CHAR_FILT_NOFILT_SEL_D2A_POS)

/*
 * io_char_mux_sel_d2a
 * [Supports Dynamic Change] Selects either the pads_int1_tp0_to_pad_d2a (0) or the the pads_aux_sclk_tp2_from_pad_a2d/pads_aux_sclk_tp2_filt_a2d (1)
 */
#define REG_IPREG_BAR_REG_12_IO_CHAR_MUX_SEL_D2A_POS      0x05
#define REG_IPREG_BAR_REG_12_IO_CHAR_MUX_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_12_IO_CHAR_MUX_SEL_D2A_POS)

/*
 * pads_aux_cs_tp3_abuf_en_d2a
 * [Supports Dynamic Change] Enables analog buffer for the analog test signal path
 */
#define REG_IPREG_BAR_REG_12_PADS_AUX_CS_TP3_ABUF_EN_D2A_POS      0x06
#define REG_IPREG_BAR_REG_12_PADS_AUX_CS_TP3_ABUF_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_12_PADS_AUX_CS_TP3_ABUF_EN_D2A_POS)

/*
 * pads_aux_cs_tp3_anl_sel_d2a
 * [Supports Dynamic Change] Analog or digital selection for test mode
 */
#define REG_IPREG_BAR_REG_12_PADS_AUX_CS_TP3_ANL_SEL_D2A_POS      0x07
#define REG_IPREG_BAR_REG_12_PADS_AUX_CS_TP3_ANL_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_12_PADS_AUX_CS_TP3_ANL_SEL_D2A_POS)



/*
 * REG_IPREG_BAR_REG_13
 * Register Name : IPREG_BAR_REG_13
 */

/*
 * pads_aux_cs_tp3_atpbus_en_d2a
 * [Supports Dynamic Change] Analog test bus enable
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_ATPBUS_EN_D2A_POS      0x00
#define REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_ATPBUS_EN_D2A_MASK     0x01

/*
 * pads_aux_cs_tp3_dtpbus_en_d2a
 * [Supports Dynamic Change] Digital Test Bus enable
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_DTPBUS_EN_D2A_POS      0x01
#define REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_DTPBUS_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_DTPBUS_EN_D2A_POS)

/*
 * pads_aux_cs_tp3_tp_aio_sel_d2a
 * [Supports Dynamic Change] Enables analog signal path to PAD for the NV_GPODIIC/NV_GPOD devices
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_TP_AIO_SEL_D2A_POS      0x02
#define REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_TP_AIO_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_CS_TP3_TP_AIO_SEL_D2A_POS)

/*
 * pads_aux_sclk_tp2_abuf_en_d2a
 * [Supports Dynamic Change] Enables analog buffer for the analog test signal path
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ABUF_EN_D2A_POS      0x03
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ABUF_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ABUF_EN_D2A_POS)

/*
 * pads_aux_sclk_tp2_anl_sel_d2a
 * [Supports Dynamic Change] Analog or digital selection for test mode
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ANL_SEL_D2A_POS      0x04
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ANL_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ANL_SEL_D2A_POS)

/*
 * pads_aux_sclk_tp2_atpbus_en_d2a
 * [Supports Dynamic Change] Analog test bus enable
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ATPBUS_EN_D2A_POS      0x05
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ATPBUS_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_ATPBUS_EN_D2A_POS)

/*
 * pads_aux_sclk_tp2_dtpbus_en_d2a
 * [Supports Dynamic Change] Digital Test Bus enable
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_DTPBUS_EN_D2A_POS      0x06
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_DTPBUS_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_DTPBUS_EN_D2A_POS)

/*
 * pads_aux_sclk_tp2_tp_aio_sel_d2a
 * [Supports Dynamic Change] Enables analog signal path to PAD for the NV_GPODIIC/NV_GPOD devices
 */
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_TP_AIO_SEL_D2A_POS      0x07
#define REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_TP_AIO_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_13_PADS_AUX_SCLK_TP2_TP_AIO_SEL_D2A_POS)



/*
 * REG_IPREG_BAR_REG_14
 * Register Name : IPREG_BAR_REG_14
 */

/*
 * pads_aux_sdi_tp1_abuf_en_d2a
 * [Supports Dynamic Change] Enables analog buffer for the analog test signal path
 */
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ABUF_EN_D2A_POS      0x00
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ABUF_EN_D2A_MASK     0x01

/*
 * pads_aux_sdi_tp1_anl_sel_d2a
 * [Supports Dynamic Change] Analog or digital selection for test mode
 */
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ANL_SEL_D2A_POS      0x01
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ANL_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ANL_SEL_D2A_POS)

/*
 * pads_aux_sdi_tp1_atpbus_en_d2a
 * [Supports Dynamic Change] Analog test bus enable
 */
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ATPBUS_EN_D2A_POS      0x02
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ATPBUS_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_ATPBUS_EN_D2A_POS)

/*
 * pads_aux_sdi_tp1_dtpbus_en_d2a
 * [Supports Dynamic Change] Digital Test Bus enable
 */
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_DTPBUS_EN_D2A_POS      0x03
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_DTPBUS_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_DTPBUS_EN_D2A_POS)

/*
 * pads_aux_sdi_tp1_tp_aio_sel_d2a
 * [Supports Dynamic Change] Enables analog signal path to PAD for the NV_GPODIIC/NV_GPOD devices
 */
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_TP_AIO_SEL_D2A_POS      0x04
#define REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_TP_AIO_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_AUX_SDI_TP1_TP_AIO_SEL_D2A_POS)

/*
 * pads_avdd_mon_d2a
 * [Supports Dynamic Change] nan
 */
#define REG_IPREG_BAR_REG_14_PADS_AVDD_MON_D2A_POS      0x05
#define REG_IPREG_BAR_REG_14_PADS_AVDD_MON_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_AVDD_MON_D2A_POS)

/*
 * pads_int1_tp0_abuf_en_d2a
 * [Supports Dynamic Change] Enables analog buffer for the analog test signal path
 */
#define REG_IPREG_BAR_REG_14_PADS_INT1_TP0_ABUF_EN_D2A_POS      0x06
#define REG_IPREG_BAR_REG_14_PADS_INT1_TP0_ABUF_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_INT1_TP0_ABUF_EN_D2A_POS)

/*
 * pads_int1_tp0_anl_sel_d2a
 * [Supports Dynamic Change] Analog or digital selection for test mode
 */
#define REG_IPREG_BAR_REG_14_PADS_INT1_TP0_ANL_SEL_D2A_POS      0x07
#define REG_IPREG_BAR_REG_14_PADS_INT1_TP0_ANL_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_14_PADS_INT1_TP0_ANL_SEL_D2A_POS)



/*
 * REG_IPREG_BAR_REG_15
 * Register Name : IPREG_BAR_REG_15
 */

/*
 * pads_int1_tp0_atpbus_en_d2a
 * [Supports Dynamic Change] Analog test bus enable
 */
#define REG_IPREG_BAR_REG_15_PADS_INT1_TP0_ATPBUS_EN_D2A_POS      0x00
#define REG_IPREG_BAR_REG_15_PADS_INT1_TP0_ATPBUS_EN_D2A_MASK     0x01

/*
 * pads_int1_tp0_dtpbus_en_d2a
 * [Supports Dynamic Change] Digital Test Bus enable
 */
#define REG_IPREG_BAR_REG_15_PADS_INT1_TP0_DTPBUS_EN_D2A_POS      0x01
#define REG_IPREG_BAR_REG_15_PADS_INT1_TP0_DTPBUS_EN_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_15_PADS_INT1_TP0_DTPBUS_EN_D2A_POS)

/*
 * pads_int1_tp0_tp_aio_sel_d2a
 * [Supports Dynamic Change] Enables analog signal path to PAD for the NV_GPODIIC/NV_GPOD devices
 */
#define REG_IPREG_BAR_REG_15_PADS_INT1_TP0_TP_AIO_SEL_D2A_POS      0x02
#define REG_IPREG_BAR_REG_15_PADS_INT1_TP0_TP_AIO_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_15_PADS_INT1_TP0_TP_AIO_SEL_D2A_POS)

/*
 * pads_tp_lpbk_d2a
 * [Supports Dynamic Change] nan
 */
#define REG_IPREG_BAR_REG_15_PADS_TP_LPBK_D2A_POS      0x03
#define REG_IPREG_BAR_REG_15_PADS_TP_LPBK_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_15_PADS_TP_LPBK_D2A_POS)



/*
 * REG_IPREG_BAR_REG_16
 * Register Name : IPREG_BAR_REG_16
 */

/*
 * mbcore_spare_d2a
 * [Supports Dynamic Change] spare control signals
 */
#define REG_IPREG_BAR_REG_16_MBCORE_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_16_MBCORE_SPARE_D2A_MASK     0x0f

/*
 * mb_areg_cp_clamp_dis_d2a
 * [Supports Dynamic Change] used to enable/disable voltage clamp on cp buffer
 */
#define REG_IPREG_BAR_REG_16_MB_AREG_CP_CLAMP_DIS_D2A_POS      0x04
#define REG_IPREG_BAR_REG_16_MB_AREG_CP_CLAMP_DIS_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_16_MB_AREG_CP_CLAMP_DIS_D2A_POS)

/*
 * mbcore_rctrim_cap_sel_d2a
 * [Supports Dynamic Change] select which capacitance will be measured, vpmom0 or vpmom1
 */
#define REG_IPREG_BAR_REG_16_MBCORE_RCTRIM_CAP_SEL_D2A_POS      0x05
#define REG_IPREG_BAR_REG_16_MBCORE_RCTRIM_CAP_SEL_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_16_MBCORE_RCTRIM_CAP_SEL_D2A_POS)

/*
 * mbcore_rctrim_mode_d2a
 * [Supports Dynamic Change] rctrim comparator internal signal
 */
#define REG_IPREG_BAR_REG_16_MBCORE_RCTRIM_MODE_D2A_POS      0x06
#define REG_IPREG_BAR_REG_16_MBCORE_RCTRIM_MODE_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_16_MBCORE_RCTRIM_MODE_D2A_POS)

/*
 * pd_mb_areg_cp_b_d2a
 * [Supports Dynamic Change] Force enable signal for Vref_mb_cp_1p6v
 */
#define REG_IPREG_BAR_REG_16_PD_MB_AREG_CP_B_D2A_POS      0x07
#define REG_IPREG_BAR_REG_16_PD_MB_AREG_CP_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_16_PD_MB_AREG_CP_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_17
 * Register Name : IPREG_BAR_REG_17
 */

/*
 * pd_mb_vbgr_b_d2a
 * [Supports Dynamic Change] vbgr current force enable signal
 */
#define REG_IPREG_BAR_REG_17_PD_MB_VBGR_B_D2A_POS      0x00
#define REG_IPREG_BAR_REG_17_PD_MB_VBGR_B_D2A_MASK     0x01

/*
 * pd_rctrim_capmeas_b_d2a
 * [Supports Dynamic Change] enable signal for RC time constant measurement
 */
#define REG_IPREG_BAR_REG_17_PD_RCTRIM_CAPMEAS_B_D2A_POS      0x03
#define REG_IPREG_BAR_REG_17_PD_RCTRIM_CAPMEAS_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_17_PD_RCTRIM_CAPMEAS_B_D2A_POS)

/*
 * pd_rctrim_resmeas_b_d2a
 * [Supports Dynamic Change] enable signal for resistance measurement
 */
#define REG_IPREG_BAR_REG_17_PD_RCTRIM_RESMEAS_B_D2A_POS      0x04
#define REG_IPREG_BAR_REG_17_PD_RCTRIM_RESMEAS_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_17_PD_RCTRIM_RESMEAS_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_18
 * Register Name : IPREG_BAR_REG_18
 */

/*
 * scan_dreg_switch_on_d2a
 * [Supports Dynamic Change] scan dreg switch on
 */
#define REG_IPREG_BAR_REG_18_SCAN_DREG_SWITCH_ON_D2A_POS      0x00
#define REG_IPREG_BAR_REG_18_SCAN_DREG_SWITCH_ON_D2A_MASK     0x01

/*
 * scan_por_disable_d2a
 * [Supports Dynamic Change] scan por disable
 */
#define REG_IPREG_BAR_REG_18_SCAN_POR_DISABLE_D2A_POS      0x01
#define REG_IPREG_BAR_REG_18_SCAN_POR_DISABLE_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_18_SCAN_POR_DISABLE_D2A_POS)



/*
 * REG_IPREG_BAR_REG_19
 * Register Name : IPREG_BAR_REG_19
 */

/*
 * spare1_d2a
 * Spare
 */
#define REG_IPREG_BAR_REG_19_SPARE1_D2A_POS      0x00
#define REG_IPREG_BAR_REG_19_SPARE1_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_21
 * Register Name : IPREG_BAR_REG_21
 */

/*
 * tmp_spare_d2a
 * [Supports Dynamic Change] Spare Bits
 */
#define REG_IPREG_BAR_REG_21_TMP_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_21_TMP_SPARE_D2A_MASK     0x0f



/*
 * REG_IPREG_BAR_REG_22
 * Register Name : IPREG_BAR_REG_22
 */

/*
 * edosc_freq_trim_d2d
 * [Supports Dynamic Change] EDOSC Freq Trim
 */
#define REG_IPREG_BAR_REG_22_EDOSC_FREQ_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_22_EDOSC_FREQ_TRIM_D2D_MASK     0xff



/*
 * REG_IPREG_BAR_REG_23
 * Register Name : IPREG_BAR_REG_23
 */

/*
 * accel_bias_spare_trim_d2a
 * [Supports Dynamic Change] OTP spare bits
 */
#define REG_IPREG_BAR_REG_23_ACCEL_BIAS_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_23_ACCEL_BIAS_SPARE_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_24
 * Register Name : IPREG_BAR_REG_24
 */

/*
 * accel_areg_cp_trim_d2a
 * [Supports Dynamic Change] Accel CP AREG trim
 */
#define REG_IPREG_BAR_REG_24_ACCEL_AREG_CP_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_24_ACCEL_AREG_CP_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_25
 * Register Name : IPREG_BAR_REG_25
 */

/*
 * accel_areg_trim_d2a
 * [Supports Dynamic Change] trimm of the accel regulated supply
 */
#define REG_IPREG_BAR_REG_25_ACCEL_AREG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_25_ACCEL_AREG_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_26
 * Register Name : IPREG_BAR_REG_26
 */

/*
 * az_vrefshld_trim_d2a
 * [Supports Dynamic Change] Trim bits for AZ shield
 */
#define REG_IPREG_BAR_REG_26_AZ_VREFSHLD_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_26_AZ_VREFSHLD_TRIM_D2A_MASK     0x3f

/*
 * accel_vref0p7_unbuffered_trim_d2a
 * [Supports Dynamic Change] Tri-state VCM buffer output
 */
#define REG_IPREG_BAR_REG_26_ACCEL_VREF0P7_UNBUFFERED_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_26_ACCEL_VREF0P7_UNBUFFERED_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_26_ACCEL_VREF0P7_UNBUFFERED_TRIM_D2A_POS)

/*
 * az_vrefshld_out2avdd_trim_d2a
 * [Supports Dynamic Change] Short AZ shield to AVDD
 */
#define REG_IPREG_BAR_REG_26_AZ_VREFSHLD_OUT2AVDD_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_26_AZ_VREFSHLD_OUT2AVDD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_26_AZ_VREFSHLD_OUT2AVDD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_27
 * Register Name : IPREG_BAR_REG_27
 */

/*
 * az_vrefshld_out2hiz_trim_d2a
 * [Supports Dynamic Change] Tri-state AZ shield
 */
#define REG_IPREG_BAR_REG_27_AZ_VREFSHLD_OUT2HIZ_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_27_AZ_VREFSHLD_OUT2HIZ_TRIM_D2A_MASK     0x01

/*
 * en_accel_drive_chop_trim_d2a
 * [Supports Dynamic Change] Enable chopping of drive buffer
 */
#define REG_IPREG_BAR_REG_27_EN_ACCEL_DRIVE_CHOP_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_27_EN_ACCEL_DRIVE_CHOP_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_27_EN_ACCEL_DRIVE_CHOP_TRIM_D2A_POS)

/*
 * en_accel_drivebuffer_vd1p4v_trim_d2a
 * [Supports Dynamic Change] Enables special 1p4v drive mode
 */
#define REG_IPREG_BAR_REG_27_EN_ACCEL_DRIVEBUFFER_VD1P4V_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_27_EN_ACCEL_DRIVEBUFFER_VD1P4V_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_27_EN_ACCEL_DRIVEBUFFER_VD1P4V_TRIM_D2A_POS)

/*
 * pd_axy_vrefshield_b_trim_d2a
 * [Supports Dynamic Change] Override to power-down AXY vrefshield buffer
 */
#define REG_IPREG_BAR_REG_27_PD_AXY_VREFSHIELD_B_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_27_PD_AXY_VREFSHIELD_B_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_27_PD_AXY_VREFSHIELD_B_TRIM_D2A_POS)

/*
 * pd_az_negcp_b_trim_d2a
 * [Supports Dynamic Change] Override to power-down AZ negcp
 */
#define REG_IPREG_BAR_REG_27_PD_AZ_NEGCP_B_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_27_PD_AZ_NEGCP_B_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_27_PD_AZ_NEGCP_B_TRIM_D2A_POS)

/*
 * pd_az_vrefshield_b_trim_d2a
 * [Supports Dynamic Change] Override to power-down AZ vrefshield buffer
 */
#define REG_IPREG_BAR_REG_27_PD_AZ_VREFSHIELD_B_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_27_PD_AZ_VREFSHIELD_B_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_27_PD_AZ_VREFSHIELD_B_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_28
 * Register Name : IPREG_BAR_REG_28
 */

/*
 * accel_vdrive_trim_d2a
 * [Supports Dynamic Change] Accel drive voltage trim
 */
#define REG_IPREG_BAR_REG_28_ACCEL_VDRIVE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_28_ACCEL_VDRIVE_TRIM_D2A_MASK     0x03



/*
 * REG_IPREG_BAR_REG_29
 * Register Name : IPREG_BAR_REG_29
 */

/*
 * accel_spare_trim_d2a
 * [Supports Dynamic Change] bit<7>: enable adc ref chop, bit<6>: disable adc comp duty cycling, bit<5>: C2V Z-ch early enable, bit<4>: CMOS-only mode drive polarity, bit<3>: adc refbuf high (+0.25uA) current, bit<2>: adc refbuf low (-0.25uA) current, bit<1>: adc comp high (+0.5uA) current, bit<0>: adc comp low (-0.5uA) current
 */
#define REG_IPREG_BAR_REG_29_ACCEL_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_29_ACCEL_SPARE_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_30
 * Register Name : IPREG_BAR_REG_30
 */

/*
 * ax_cc_trim_d2d
 * [Supports Dynamic Change] AX CC trim
 */
#define REG_IPREG_BAR_REG_30_AX_CC_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_30_AX_CC_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_31
 * Register Name : IPREG_BAR_REG_31
 */

/*
 * axy_rst_cc_trim_d2a
 * [Supports Dynamic Change] AXY CC trim in reset mode
 */
#define REG_IPREG_BAR_REG_31_AXY_RST_CC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_31_AXY_RST_CC_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_32
 * Register Name : IPREG_BAR_REG_32
 */

/*
 * ay_cc_trim_d2d
 * [Supports Dynamic Change] AY CC trim
 */
#define REG_IPREG_BAR_REG_32_AY_CC_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_32_AY_CC_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_33
 * Register Name : IPREG_BAR_REG_33
 */

/*
 * az_cc_trim_d2d
 * [Supports Dynamic Change] AZ CC trim
 */
#define REG_IPREG_BAR_REG_33_AZ_CC_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_33_AZ_CC_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_34
 * Register Name : IPREG_BAR_REG_34
 */

/*
 * az_rst_cc_trim_d2a
 * [Supports Dynamic Change] AZ CC trim in reset mode
 */
#define REG_IPREG_BAR_REG_34_AZ_RST_CC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_34_AZ_RST_CC_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_35
 * Register Name : IPREG_BAR_REG_35
 */

/*
 * ax_cfb_trim_d2d
 * [Supports Dynamic Change] AX CFB trim
 */
#define REG_IPREG_BAR_REG_35_AX_CFB_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_35_AX_CFB_TRIM_D2D_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_36
 * Register Name : IPREG_BAR_REG_36
 */

/*
 * ax_ft_trim_d2d
 * [Supports Dynamic Change] AX feedthrough cap trim
 */
#define REG_IPREG_BAR_REG_36_AX_FT_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_36_AX_FT_TRIM_D2D_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_37
 * Register Name : IPREG_BAR_REG_37
 */

/*
 * ay_cfb_trim_d2d
 * [Supports Dynamic Change] AY CFB trim
 */
#define REG_IPREG_BAR_REG_37_AY_CFB_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_37_AY_CFB_TRIM_D2D_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_38
 * Register Name : IPREG_BAR_REG_38
 */

/*
 * ay_ft_trim_d2d
 * [Supports Dynamic Change] AY feedthrough cap trim
 */
#define REG_IPREG_BAR_REG_38_AY_FT_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_38_AY_FT_TRIM_D2D_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_39
 * Register Name : IPREG_BAR_REG_39
 */

/*
 * az_cfb_trim_d2d
 * [Supports Dynamic Change] AZ CFB trim
 */
#define REG_IPREG_BAR_REG_39_AZ_CFB_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_39_AZ_CFB_TRIM_D2D_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_40
 * Register Name : IPREG_BAR_REG_40
 */

/*
 * az_ft_trim_d2d
 * [Supports Dynamic Change] AZ feedthrough cap trim
 */
#define REG_IPREG_BAR_REG_40_AZ_FT_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_40_AZ_FT_TRIM_D2D_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_41
 * Register Name : IPREG_BAR_REG_41
 */

/*
 * accel_vbg_trim_d2a
 * [Supports Dynamic Change] Accel bandgap voltage trim
 */
#define REG_IPREG_BAR_REG_41_ACCEL_VBG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_41_ACCEL_VBG_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_42
 * Register Name : IPREG_BAR_REG_42
 */

/*
 * accel_adc_rc_trim_d2a
 * [Supports Dynamic Change] SAR ADC RC/Vref trim
 */
#define REG_IPREG_BAR_REG_42_ACCEL_ADC_RC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_42_ACCEL_ADC_RC_TRIM_D2A_MASK     0x0f

/*
 * accel_adc_ref_trim_d2a
 * [Supports Dynamic Change] Spare trim (currently unused)
 */
#define REG_IPREG_BAR_REG_42_ACCEL_ADC_REF_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_42_ACCEL_ADC_REF_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_42_ACCEL_ADC_REF_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_43
 * Register Name : IPREG_BAR_REG_43
 */

/*
 * accel_int_rc_trim_d2a
 * [Supports Dynamic Change] integrator RC trim
 */
#define REG_IPREG_BAR_REG_43_ACCEL_INT_RC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_43_ACCEL_INT_RC_TRIM_D2A_MASK     0x0f

/*
 * accel_vbgr_trim_d2a
 * [Supports Dynamic Change] Accel VBG/R current trim
 */
#define REG_IPREG_BAR_REG_43_ACCEL_VBGR_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_43_ACCEL_VBGR_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_43_ACCEL_VBGR_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_44
 * Register Name : IPREG_BAR_REG_44
 */

/*
 * ax_cd_trim_d2a
 * [Supports Dynamic Change] AX CD trim
 */
#define REG_IPREG_BAR_REG_44_AX_CD_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_44_AX_CD_TRIM_D2A_MASK     0x0f

/*
 * ax_cpmgnd_trim_d2a
 * [Supports Dynamic Change] AX CPMGND trim
 */
#define REG_IPREG_BAR_REG_44_AX_CPMGND_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_44_AX_CPMGND_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_44_AX_CPMGND_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_45
 * Register Name : IPREG_BAR_REG_45
 */

/*
 * ax_cpmsh_trim_d2a
 * [Supports Dynamic Change] AX CPMSH trim
 */
#define REG_IPREG_BAR_REG_45_AX_CPMSH_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_45_AX_CPMSH_TRIM_D2A_MASK     0x0f

/*
 * ay_cd_trim_d2a
 * [Supports Dynamic Change] AY CD trim
 */
#define REG_IPREG_BAR_REG_45_AY_CD_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_45_AY_CD_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_45_AY_CD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_46
 * Register Name : IPREG_BAR_REG_46
 */

/*
 * ay_cpmgnd_trim_d2a
 * [Supports Dynamic Change] AY CPMGND trim
 */
#define REG_IPREG_BAR_REG_46_AY_CPMGND_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_46_AY_CPMGND_TRIM_D2A_MASK     0x0f

/*
 * ay_cpmsh_trim_d2a
 * [Supports Dynamic Change] AY CPMSH trim
 */
#define REG_IPREG_BAR_REG_46_AY_CPMSH_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_46_AY_CPMSH_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_46_AY_CPMSH_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_47
 * Register Name : IPREG_BAR_REG_47
 */

/*
 * accel_testbuffer_guardband_trim_d2d
 * [Supports Dynamic Change] Test buffer guardband width trim
 */
#define REG_IPREG_BAR_REG_47_ACCEL_TESTBUFFER_GUARDBAND_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_47_ACCEL_TESTBUFFER_GUARDBAND_TRIM_D2D_MASK     0x03

/*
 * axy_c2v_highcurrent_trim_d2a
 * [Supports Dynamic Change] AXY using high current
 */
#define REG_IPREG_BAR_REG_47_AXY_C2V_HIGHCURRENT_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_47_AXY_C2V_HIGHCURRENT_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_47_AXY_C2V_HIGHCURRENT_TRIM_D2A_POS)

/*
 * az_c2v_highcurrent_trim_d2a
 * [Supports Dynamic Change] AZ using high current
 */
#define REG_IPREG_BAR_REG_47_AZ_C2V_HIGHCURRENT_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_47_AZ_C2V_HIGHCURRENT_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_47_AZ_C2V_HIGHCURRENT_TRIM_D2A_POS)

/*
 * accel_int_chop_trim_d2a
 * [Supports Dynamic Change] Integrator chop or not
 */
#define REG_IPREG_BAR_REG_47_ACCEL_INT_CHOP_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_47_ACCEL_INT_CHOP_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_47_ACCEL_INT_CHOP_TRIM_D2A_POS)

/*
 * ax_dmd_inv_trim_d2d
 * [Supports Dynamic Change] AX DMD polarity inversion
 */
#define REG_IPREG_BAR_REG_47_AX_DMD_INV_TRIM_D2D_POS      0x07
#define REG_IPREG_BAR_REG_47_AX_DMD_INV_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_47_AX_DMD_INV_TRIM_D2D_POS)



/*
 * REG_IPREG_BAR_REG_48
 * Register Name : IPREG_BAR_REG_48
 */

/*
 * ax_drv_phase_trim_d2a
 * [Supports Dynamic Change] AX drive polarity trim
 */
#define REG_IPREG_BAR_REG_48_AX_DRV_PHASE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_48_AX_DRV_PHASE_TRIM_D2A_MASK     0x01

/*
 * axy_2x_speed_trim_d2d
 * [Supports Dynamic Change] 0: AXY running at 76.8 kHz; 1: AXY running at 153.6-kHz
 */
#define REG_IPREG_BAR_REG_48_AXY_2X_SPEED_TRIM_D2D_POS      0x01
#define REG_IPREG_BAR_REG_48_AXY_2X_SPEED_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_48_AXY_2X_SPEED_TRIM_D2D_POS)

/*
 * ay_dmd_inv_trim_d2d
 * [Supports Dynamic Change] AY DMD polarity inversion
 */
#define REG_IPREG_BAR_REG_48_AY_DMD_INV_TRIM_D2D_POS      0x02
#define REG_IPREG_BAR_REG_48_AY_DMD_INV_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_48_AY_DMD_INV_TRIM_D2D_POS)

/*
 * ay_drv_phase_trim_d2a
 * [Supports Dynamic Change] AY drive polarity trim
 */
#define REG_IPREG_BAR_REG_48_AY_DRV_PHASE_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_48_AY_DRV_PHASE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_48_AY_DRV_PHASE_TRIM_D2A_POS)

/*
 * az_2x_speed_trim_d2d
 * [Supports Dynamic Change] 0: AZ running at 76.8 kHz; 1: AZ running at 153.6-kHz
 */
#define REG_IPREG_BAR_REG_48_AZ_2X_SPEED_TRIM_D2D_POS      0x04
#define REG_IPREG_BAR_REG_48_AZ_2X_SPEED_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_48_AZ_2X_SPEED_TRIM_D2D_POS)

/*
 * az_dmd_inv_trim_d2d
 * [Supports Dynamic Change] AZ DMD polarity inversion
 */
#define REG_IPREG_BAR_REG_48_AZ_DMD_INV_TRIM_D2D_POS      0x05
#define REG_IPREG_BAR_REG_48_AZ_DMD_INV_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_48_AZ_DMD_INV_TRIM_D2D_POS)

/*
 * az_drv_phase_trim_d2a
 * [Supports Dynamic Change] AZ drive polarity inversion
 */
#define REG_IPREG_BAR_REG_48_AZ_DRV_PHASE_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_48_AZ_DRV_PHASE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_48_AZ_DRV_PHASE_TRIM_D2A_POS)

/*
 * az_mems_gain_trim_d2a
 * [Supports Dynamic Change] AZ MEMS gain trim
 */
#define REG_IPREG_BAR_REG_48_AZ_MEMS_GAIN_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_48_AZ_MEMS_GAIN_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_48_AZ_MEMS_GAIN_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_49
 * Register Name : IPREG_BAR_REG_49
 */

/*
 * c2v_dis_self_su_after_su_trim_d2a
 * [Supports Dynamic Change] Disable C2V self startup after self startup
 */
#define REG_IPREG_BAR_REG_49_C2V_DIS_SELF_SU_AFTER_SU_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_49_C2V_DIS_SELF_SU_AFTER_SU_TRIM_D2A_MASK     0x01

/*
 * c2v_dis_self_su_trim_d2a
 * [Supports Dynamic Change] Disable C2V self startup
 */
#define REG_IPREG_BAR_REG_49_C2V_DIS_SELF_SU_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_49_C2V_DIS_SELF_SU_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_49_C2V_DIS_SELF_SU_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_50
 * Register Name : IPREG_BAR_REG_50
 */

/*
 * gyro_dc2v_fine_analog_trim_d2a
 * [Supports Dynamic Change] fine_analog
 */
#define REG_IPREG_BAR_REG_50_GYRO_DC2V_FINE_ANALOG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_50_GYRO_DC2V_FINE_ANALOG_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_51
 * Register Name : IPREG_BAR_REG_51
 */

/*
 * gyro_dc2v_gain_trim_d2a
 * [Supports Dynamic Change] gain trim
 */
#define REG_IPREG_BAR_REG_51_GYRO_DC2V_GAIN_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_51_GYRO_DC2V_GAIN_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_52
 * Register Name : IPREG_BAR_REG_52
 */

/*
 * gyro_dc2v_offset_trim_d2a
 * [Supports Dynamic Change] offset trim
 */
#define REG_IPREG_BAR_REG_52_GYRO_DC2V_OFFSET_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_52_GYRO_DC2V_OFFSET_TRIM_D2A_MASK     0x0f

/*
 * gyro_dc2v_ptatblend_trim_d2a
 * [Supports Dynamic Change] PTAT-blend trim
 */
#define REG_IPREG_BAR_REG_52_GYRO_DC2V_PTATBLEND_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_52_GYRO_DC2V_PTATBLEND_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_52_GYRO_DC2V_PTATBLEND_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_53
 * Register Name : IPREG_BAR_REG_53
 */

/*
 * gyro_dc2v_ib_trim_d2a
 * [Supports Dynamic Change] bias current rim
 */
#define REG_IPREG_BAR_REG_53_GYRO_DC2V_IB_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_53_GYRO_DC2V_IB_TRIM_D2A_MASK     0x07

/*
 * gyro_dc2v_io_trim_d2a
 * [Supports Dynamic Change] output current trim
 */
#define REG_IPREG_BAR_REG_53_GYRO_DC2V_IO_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_53_GYRO_DC2V_IO_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_53_GYRO_DC2V_IO_TRIM_D2A_POS)

/*
 * gyro_dc2v_fet_trim_d2a
 * [Supports Dynamic Change] feedback resistor trim
 */
#define REG_IPREG_BAR_REG_53_GYRO_DC2V_FET_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_53_GYRO_DC2V_FET_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_53_GYRO_DC2V_FET_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_54
 * Register Name : IPREG_BAR_REG_54
 */

/*
 * gyro_dc2v_rst_time_trim_d2a
 * [Supports Dynamic Change] ramp time trim
 */
#define REG_IPREG_BAR_REG_54_GYRO_DC2V_RST_TIME_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_54_GYRO_DC2V_RST_TIME_TRIM_D2A_MASK     0x03

/*
 * gyro_dc2v_spare_trim_d2a
 * [Supports Dynamic Change] spare trim
 */
#define REG_IPREG_BAR_REG_54_GYRO_DC2V_SPARE_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_54_GYRO_DC2V_SPARE_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_54_GYRO_DC2V_SPARE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_55
 * Register Name : IPREG_BAR_REG_55
 */

/*
 * gyro_cp25v_r2_trim_d2a
 * [Supports Dynamic Change] Used to compensate process-induced R1/R2 ratio error. This will be golden trim as of POR on 06/22/16. Default TBD, have 0 for starters.
 */
#define REG_IPREG_BAR_REG_55_GYRO_CP25V_R2_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_55_GYRO_CP25V_R2_TRIM_D2A_MASK     0x0f

/*
 * gyro_cp25v_cpclkdivrat_trim_d2a
 * [Supports Dynamic Change] CP clock div ratio. '0' - divrat1 (cpclk 6MHz), '1'-divrat2 (cpclk 2MHz), '2' -divrat3 (cpclk 1MHz)
 */
#define REG_IPREG_BAR_REG_55_GYRO_CP25V_CPCLKDIVRAT_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_55_GYRO_CP25V_CPCLKDIVRAT_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_55_GYRO_CP25V_CPCLKDIVRAT_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_56
 * Register Name : IPREG_BAR_REG_56
 */

/*
 * gyro_cp25v_chopclkdivrat_trim_d2a
 * [Supports Dynamic Change] Chop clk divratio. '0'-divrat24 (166.7kHz), '1'-divrat12 (333.3kHz), '2'-divrat6 (666.7kHz), '3'-divrat48 (83.3kHz)
 */
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_CHOPCLKDIVRAT_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_CHOPCLKDIVRAT_TRIM_D2A_MASK     0x03

/*
 * gyro_cp25v_cprdytimer_trim_d2a
 * [Supports Dynamic Change] cpRDY signal is asserted at 1.5ms based on a counter. We want programmability in future. '0'-1ms, '1'-1.5ms,'2'-2ms, '3'-2.5ms.
 */
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_CPRDYTIMER_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_CPRDYTIMER_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_56_GYRO_CP25V_CPRDYTIMER_TRIM_D2A_POS)

/*
 * gyro_cp25v_spare_trim_d2a
 * [Supports Dynamic Change] Spare bits
 */
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_SPARE_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_SPARE_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_56_GYRO_CP25V_SPARE_TRIM_D2A_POS)

/*
 * en_gyro_cp25v_chop_trim_d2a
 * [Supports Dynamic Change] Error Amplifier Chop Enable
 */
#define REG_IPREG_BAR_REG_56_EN_GYRO_CP25V_CHOP_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_56_EN_GYRO_CP25V_CHOP_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_56_EN_GYRO_CP25V_CHOP_TRIM_D2A_POS)

/*
 * gyro_cp25v_sync_ovrd_trim_d2a
 * [Supports Dynamic Change] 1: Disables Divider Sync wrt drive frequency
 * 0: Enables Divider Sync wrt drive frequency
 */
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_SYNC_OVRD_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_56_GYRO_CP25V_SYNC_OVRD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_56_GYRO_CP25V_SYNC_OVRD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_57
 * Register Name : IPREG_BAR_REG_57
 */

/*
 * pads_tp_areg_trim_d2a
 * [Supports Dynamic Change] If necessary, depending on the regulator used, these bits may be used to trim the avdd voltage in IO pads
 */
#define REG_IPREG_BAR_REG_57_PADS_TP_AREG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_57_PADS_TP_AREG_TRIM_D2A_MASK     0x1f

/*
 * en_io_well_bias_vddio_comp_trim_d2a
 * [Supports Dynamic Change] Register to enable or diable IO well bias VDDIO comparator. The comparator automatically detects VDDIO level and shuts off pads well bias voltages. 0 comparator is disabled 1 comparator is enabled
 *
 */
#define REG_IPREG_BAR_REG_57_EN_IO_WELL_BIAS_VDDIO_COMP_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_57_EN_IO_WELL_BIAS_VDDIO_COMP_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_57_EN_IO_WELL_BIAS_VDDIO_COMP_TRIM_D2A_POS)

/*
 * en_pads_wellbias_rxnw_trim_d2a
 * [Supports Dynamic Change] Register to enable RX nwell io voltage bias
 *
 */
#define REG_IPREG_BAR_REG_57_EN_PADS_WELLBIAS_RXNW_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_57_EN_PADS_WELLBIAS_RXNW_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_57_EN_PADS_WELLBIAS_RXNW_TRIM_D2A_POS)

/*
 * en_pads_wellbias_rxpw_trim_d2a
 * [Supports Dynamic Change] Register to enable RX pwell io voltage bias
 *
 */
#define REG_IPREG_BAR_REG_57_EN_PADS_WELLBIAS_RXPW_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_57_EN_PADS_WELLBIAS_RXPW_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_57_EN_PADS_WELLBIAS_RXPW_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_58
 * Register Name : IPREG_BAR_REG_58
 */

/*
 * en_pads_wellbias_txnw_trim_d2a
 * [Supports Dynamic Change] Register to enable TX nwell io voltage bias
 *
 */
#define REG_IPREG_BAR_REG_58_EN_PADS_WELLBIAS_TXNW_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_58_EN_PADS_WELLBIAS_TXNW_TRIM_D2A_MASK     0x01

/*
 * en_pads_wellbias_txpw_trim_d2a
 * [Supports Dynamic Change] Register to enable TX pwell io voltage bias
 *
 */
#define REG_IPREG_BAR_REG_58_EN_PADS_WELLBIAS_TXPW_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_58_EN_PADS_WELLBIAS_TXPW_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_58_EN_PADS_WELLBIAS_TXPW_TRIM_D2A_POS)

/*
 * REG_IPREG_BAR_REG_64
 * Register Name : IPREG_BAR_REG_64
 */

/*
 * mbcore_spare_trim_d2a
 * [Supports Dynamic Change] <7:1> spare trim bits, <0> used to boost 1.5V areg voltage by 4.3%
 */
#define REG_IPREG_BAR_REG_64_MBCORE_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_64_MBCORE_SPARE_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_65
 * Register Name : IPREG_BAR_REG_65
 */

/*
 * minibg_ctat_trim_d2a
 * [Supports Dynamic Change] ctat current trim value
 */
#define REG_IPREG_BAR_REG_65_MINIBG_CTAT_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_65_MINIBG_CTAT_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_66
 * Register Name : IPREG_BAR_REG_66
 */

/*
 * minibg_vbg_trim_d2a
 * [Supports Dynamic Change] miniBG bandgap voltage trim value
 */
#define REG_IPREG_BAR_REG_66_MINIBG_VBG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_66_MINIBG_VBG_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_67
 * Register Name : IPREG_BAR_REG_67
 */

/*
 * mbcore_vbgr_trim_d2a
 * [Supports Dynamic Change] vbgr current trim value
 */
#define REG_IPREG_BAR_REG_67_MBCORE_VBGR_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_67_MBCORE_VBGR_TRIM_D2A_MASK     0x0f

/*
 * minibg_ptat_trim_d2a
 * [Supports Dynamic Change] ptat current trim value
 */
#define REG_IPREG_BAR_REG_67_MINIBG_PTAT_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_67_MINIBG_PTAT_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_67_MINIBG_PTAT_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_68
 * Register Name : IPREG_BAR_REG_68
 */

/*
 * mb_startup_dis_trim_d2a
 * [Supports Dynamic Change] used to disable the speed up the turn on time of areg and ireg
 */
#define REG_IPREG_BAR_REG_68_MB_STARTUP_DIS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_68_MB_STARTUP_DIS_TRIM_D2A_MASK     0x01



/*
 * REG_IPREG_BAR_REG_69
 * Register Name : IPREG_BAR_REG_69
 */

/*
 * dreg_dvdd_fine_trim_d2a
 * [Supports Dynamic Change] dvdd fine trim
 */
#define REG_IPREG_BAR_REG_69_DREG_DVDD_FINE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_69_DREG_DVDD_FINE_TRIM_D2A_MASK     0x0f

/*
 * dreg_dvdd_coarse_trim_d2a
 * [Supports Dynamic Change] dvdd coarse trim
 */
#define REG_IPREG_BAR_REG_69_DREG_DVDD_COARSE_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_69_DREG_DVDD_COARSE_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_69_DREG_DVDD_COARSE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_70
 * Register Name : IPREG_BAR_REG_70
 */

/*
 * dreg_sw_prech_trim_d2a
 * [Supports Dynamic Change] sw dreg prech time trim
 */
#define REG_IPREG_BAR_REG_70_DREG_SW_PRECH_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_70_DREG_SW_PRECH_TRIM_D2A_MASK     0x07

/*
 * dreg_spare_trim_d2a
 * [Supports Dynamic Change] spare trim
 */
#define REG_IPREG_BAR_REG_70_DREG_SPARE_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_70_DREG_SPARE_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_70_DREG_SPARE_TRIM_D2A_POS)

/*
 * dreg_set_1meg_load_trim_d2a
 * [Supports Dynamic Change] set 1meg dreg load
 */
#define REG_IPREG_BAR_REG_70_DREG_SET_1MEG_LOAD_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_70_DREG_SET_1MEG_LOAD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_70_DREG_SET_1MEG_LOAD_TRIM_D2A_POS)

/*
 * force_on_dvdd_sw_trim_d2a
 * [Supports Dynamic Change] force switcable dvdd ON
 */
#define REG_IPREG_BAR_REG_70_FORCE_ON_DVDD_SW_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_70_FORCE_ON_DVDD_SW_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_70_FORCE_ON_DVDD_SW_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_71
 * Register Name : IPREG_BAR_REG_71
 */

/*
 * spare1_trim_d2a
 * Spare
 */
#define REG_IPREG_BAR_REG_71_SPARE1_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_71_SPARE1_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_72
 * Register Name : IPREG_BAR_REG_72
 */

/*
 * wuosc_freq_trim_d2d
 * [Supports Dynamic Change] WUOSC Freq Trim
 */
#define REG_IPREG_BAR_REG_72_WUOSC_FREQ_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_72_WUOSC_FREQ_TRIM_D2D_MASK     0xff



/*
 * REG_IPREG_BAR_REG_73
 * Register Name : IPREG_BAR_REG_73
 */

/*
 * tmp_areg_trim_d2a
 * [Supports Dynamic Change] Areg Trim for Temp Block
 */
#define REG_IPREG_BAR_REG_73_TMP_AREG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_73_TMP_AREG_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_74
 * Register Name : IPREG_BAR_REG_74
 */

/*
 * tmp_dvbe_f_trim_d2a
 * [Supports Dynamic Change] Fine dvbe Trimming Codeword
 */
#define REG_IPREG_BAR_REG_74_TMP_DVBE_F_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_74_TMP_DVBE_F_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_75
 * Register Name : IPREG_BAR_REG_75
 */

/*
 * tmp_vbe_f_trim_d2a
 * [Supports Dynamic Change] Fine vbe Trimming Codeword
 */
#define REG_IPREG_BAR_REG_75_TMP_VBE_F_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_75_TMP_VBE_F_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_76
 * Register Name : IPREG_BAR_REG_76
 */

/*
 * tmp_dvbe_c_trim_d2a
 * [Supports Dynamic Change] Coarse dvbe Trimming Codeword
 */
#define REG_IPREG_BAR_REG_76_TMP_DVBE_C_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_76_TMP_DVBE_C_TRIM_D2A_MASK     0x0f

/*
 * tmp_vbe_c_trim_d2a
 * [Supports Dynamic Change] Coarse vbe Trimming Codeword
 */
#define REG_IPREG_BAR_REG_76_TMP_VBE_C_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_76_TMP_VBE_C_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_76_TMP_VBE_C_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_77
 * Register Name : IPREG_BAR_REG_77
 */

/*
 * tmp_spare_trim_d2a
 * [Supports Dynamic Change] spare otp bits
 */
#define REG_IPREG_BAR_REG_77_TMP_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_77_TMP_SPARE_TRIM_D2A_MASK     0x07



/*
 * REG_IPREG_BAR_REG_78
 * Register Name : IPREG_BAR_REG_78
 */

/*
 * gx_dmd_fine_phase_shape_d2d
 * [Supports Dynamic Change] 7:6: level to be forced during the first clock cycle of the puncture. 0 forces level 0, 1 forces level 1 and so on. 5:4: same as above for the second clock cycle; 3:2 same as above for the third clock cycle; 1:0: same as above for the fourth clock cycle
 */
#define REG_IPREG_BAR_REG_78_GX_DMD_FINE_PHASE_SHAPE_D2D_POS      0x00
#define REG_IPREG_BAR_REG_78_GX_DMD_FINE_PHASE_SHAPE_D2D_MASK     0xff



/*
 * REG_IPREG_BAR_REG_79
 * Register Name : IPREG_BAR_REG_79
 */

/*
 * gy_dmd_fine_phase_shape_d2d
 * [Supports Dynamic Change] 7:6: level to be forced during the first clock cycle of the puncture. 0 forces level 0, 1 forces level 1 and so on. 5:4: same as above for the second clock cycle; 3:2 same as above for the third clock cycle; 1:0: same as above for the fourth clock cycle
 */
#define REG_IPREG_BAR_REG_79_GY_DMD_FINE_PHASE_SHAPE_D2D_POS      0x00
#define REG_IPREG_BAR_REG_79_GY_DMD_FINE_PHASE_SHAPE_D2D_MASK     0xff



/*
 * REG_IPREG_BAR_REG_80
 * Register Name : IPREG_BAR_REG_80
 */

/*
 * gz_dmd_fine_phase_shape_d2d
 * [Supports Dynamic Change] 7:6: level to be forced during the first clock cycle of the puncture. 0 forces level 0, 1 forces level 1 and so on. 5:4: same as above for the second clock cycle; 3:2 same as above for the third clock cycle; 1:0: same as above for the fourth clock cycle
 */
#define REG_IPREG_BAR_REG_80_GZ_DMD_FINE_PHASE_SHAPE_D2D_POS      0x00
#define REG_IPREG_BAR_REG_80_GZ_DMD_FINE_PHASE_SHAPE_D2D_MASK     0xff



/*
 * REG_IPREG_BAR_REG_81
 * Register Name : IPREG_BAR_REG_81
 */

/*
 * gdm_spare_d2d
 * [Supports Dynamic Change] nan
 */
#define REG_IPREG_BAR_REG_81_GDM_SPARE_D2D_POS      0x00
#define REG_IPREG_BAR_REG_81_GDM_SPARE_D2D_MASK     0x0f

/*
 * rst_gx_sc2v_b_mode_d2d
 * [Supports Dynamic Change] Override for rst_gx_sc2v_b: 0 -> normal operation, 10 -> gated to 0, 11 -> gated to 1
 */
#define REG_IPREG_BAR_REG_81_RST_GX_SC2V_B_MODE_D2D_POS      0x04
#define REG_IPREG_BAR_REG_81_RST_GX_SC2V_B_MODE_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_81_RST_GX_SC2V_B_MODE_D2D_POS)

/*
 * rst_gy_sc2v_b_mode_d2d
 * [Supports Dynamic Change] Override for rst_gx_sc2v_b: 0 -> normal operation, 10 -> gated to 0, 11 -> gated to 1
 */
#define REG_IPREG_BAR_REG_81_RST_GY_SC2V_B_MODE_D2D_POS      0x06
#define REG_IPREG_BAR_REG_81_RST_GY_SC2V_B_MODE_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_81_RST_GY_SC2V_B_MODE_D2D_POS)



/*
 * REG_IPREG_BAR_REG_82
 * Register Name : IPREG_BAR_REG_82
 */

/*
 * rst_gz_sc2v_b_mode_d2d
 * [Supports Dynamic Change] Override for rst_gx_sc2v_b: 0 -> normal operation, 10 -> gated to 0, 11 -> gated to 1
 */
#define REG_IPREG_BAR_REG_82_RST_GZ_SC2V_B_MODE_D2D_POS      0x00
#define REG_IPREG_BAR_REG_82_RST_GZ_SC2V_B_MODE_D2D_MASK     0x03

/*
 * gyro_dmd_dis_clk_d2d
 * [Supports Dynamic Change] Disables the 6MHz clock to dig top
 */
#define REG_IPREG_BAR_REG_82_GYRO_DMD_DIS_CLK_D2D_POS      0x02
#define REG_IPREG_BAR_REG_82_GYRO_DMD_DIS_CLK_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_82_GYRO_DMD_DIS_CLK_D2D_POS)



/*
 * REG_IPREG_BAR_REG_83
 * Register Name : IPREG_BAR_REG_83
 */

/*
 * gx_dmd_fine_phase_trim_d2d
 * [Supports Dynamic Change] Signed (comp-2) integer value. Valid range is from -40 to +40. If a value outside this range is set the behavior is not guaranteed
 */
#define REG_IPREG_BAR_REG_83_GX_DMD_FINE_PHASE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_83_GX_DMD_FINE_PHASE_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_84
 * Register Name : IPREG_BAR_REG_84
 */

/*
 * gx_dmd_phase_trim_d2d
 * [Supports Dynamic Change] Coarse phase trim determining the initial delay from the fbkclk rising edge and the generation of the demodulator signals.
 */
#define REG_IPREG_BAR_REG_84_GX_DMD_PHASE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_84_GX_DMD_PHASE_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_85
 * Register Name : IPREG_BAR_REG_85
 */

/*
 * gy_dmd_fine_phase_trim_d2d
 * [Supports Dynamic Change] Signed (comp-2) integer value. Valid range is from -40 to +40. If a value outside this range is set the behavior is not guaranteed
 */
#define REG_IPREG_BAR_REG_85_GY_DMD_FINE_PHASE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_85_GY_DMD_FINE_PHASE_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_86
 * Register Name : IPREG_BAR_REG_86
 */

/*
 * gy_dmd_phase_trim_d2d
 * [Supports Dynamic Change] Coarse phase trim determining the initial delay from the fbkclk rising edge and the generation of the demodulator signals.
 */
#define REG_IPREG_BAR_REG_86_GY_DMD_PHASE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_86_GY_DMD_PHASE_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_87
 * Register Name : IPREG_BAR_REG_87
 */

/*
 * gyro_dmd_divratio_trim_d2d
 * [Supports Dynamic Change] Unsigned integer value. PLL divider ratio (Ntot/4). Determines the Gyro drive period
 */
#define REG_IPREG_BAR_REG_87_GYRO_DMD_DIVRATIO_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_87_GYRO_DMD_DIVRATIO_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_88
 * Register Name : IPREG_BAR_REG_88
 */

/*
 * gyro_dmd_multilevels_n1_trim_d2d
 * [Supports Dynamic Change] Unsigned integer value. Duration of the level 0 in terms of number of PLL clock cycles. It must be > 0. If set to zero the generated signals can assume an unpredictable waveform
 */
#define REG_IPREG_BAR_REG_88_GYRO_DMD_MULTILEVELS_N1_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_88_GYRO_DMD_MULTILEVELS_N1_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_89
 * Register Name : IPREG_BAR_REG_89
 */

/*
 * gyro_dmd_multilevels_n2n1_trim_d2d
 * [Supports Dynamic Change] Unsigned integer value. Duration of the level 1 in terms of number of PLL clock cycles. It must be > 0. If set to zero the generated signals can assume an unpredictable waveform
 */
#define REG_IPREG_BAR_REG_89_GYRO_DMD_MULTILEVELS_N2N1_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_89_GYRO_DMD_MULTILEVELS_N2N1_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_90
 * Register Name : IPREG_BAR_REG_90
 */

/*
 * gyro_dmd_multilevels_n3n2_trim_d2d
 * [Supports Dynamic Change] Unsigned integer value. Duration of the level 2 in terms of number of PLL clock cycles. It must be > 0. If set to zero the generated signals can assume an unpredictable waveform
 */
#define REG_IPREG_BAR_REG_90_GYRO_DMD_MULTILEVELS_N3N2_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_90_GYRO_DMD_MULTILEVELS_N3N2_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_91
 * Register Name : IPREG_BAR_REG_91
 */

/*
 * gz_dmd_fine_phase_trim_d2d
 * [Supports Dynamic Change] Signed (comp-2) integer value. Valid range is from -40 to +40. If a value outside this range is set the behavior is not guaranteed
 */
#define REG_IPREG_BAR_REG_91_GZ_DMD_FINE_PHASE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_91_GZ_DMD_FINE_PHASE_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_92
 * Register Name : IPREG_BAR_REG_92
 */

/*
 * gz_dmd_phase_trim_d2d
 * [Supports Dynamic Change] Coarse phase trim determining the initial delay from the fbkclk rising edge and the generation of the demodulator signals.
 */
#define REG_IPREG_BAR_REG_92_GZ_DMD_PHASE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_92_GZ_DMD_PHASE_TRIM_D2D_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_93
 * Register Name : IPREG_BAR_REG_93
 */

/*
 * gdm_spare_trim_d2d
 * [Supports Dynamic Change] Spare configuration
 */
#define REG_IPREG_BAR_REG_93_GDM_SPARE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_93_GDM_SPARE_TRIM_D2D_MASK     0x0f

/*
 * gx_dmd_phase_quadrant_trim_d2d
 * [Supports Dynamic Change] Coarse phase trim (quadrant) determining the initial delay from the fbkclk rising edge and the generation of the demodulator signals.
 */
#define REG_IPREG_BAR_REG_93_GX_DMD_PHASE_QUADRANT_TRIM_D2D_POS      0x04
#define REG_IPREG_BAR_REG_93_GX_DMD_PHASE_QUADRANT_TRIM_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_93_GX_DMD_PHASE_QUADRANT_TRIM_D2D_POS)

/*
 * gy_dmd_phase_quadrant_trim_d2d
 * [Supports Dynamic Change] Coarse phase trim (quadrant) determining the initial delay from the fbkclk rising edge and the generation of the demodulator signals.
 */
#define REG_IPREG_BAR_REG_93_GY_DMD_PHASE_QUADRANT_TRIM_D2D_POS      0x06
#define REG_IPREG_BAR_REG_93_GY_DMD_PHASE_QUADRANT_TRIM_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_93_GY_DMD_PHASE_QUADRANT_TRIM_D2D_POS)



/*
 * REG_IPREG_BAR_REG_94
 * Register Name : IPREG_BAR_REG_94
 */

/*
 * gyro_dmd_fine_phase_width_trim_d2d
 * [Supports Dynamic Change] Puncture width from 1 to 4 when the fine phase is enabled;
 */
#define REG_IPREG_BAR_REG_94_GYRO_DMD_FINE_PHASE_WIDTH_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_94_GYRO_DMD_FINE_PHASE_WIDTH_TRIM_D2D_MASK     0x03

/*
 * gyro_dmd_lvls_mode_trim_d2d
 * [Supports Dynamic Change] Demod wave shape modes: 00: 7-level mode; 01: 3-level mode with multiple transitions; 10: 3-level mode; 11: 2-level mode (legacy mode)
 */
#define REG_IPREG_BAR_REG_94_GYRO_DMD_LVLS_MODE_TRIM_D2D_POS      0x02
#define REG_IPREG_BAR_REG_94_GYRO_DMD_LVLS_MODE_TRIM_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_94_GYRO_DMD_LVLS_MODE_TRIM_D2D_POS)

/*
 * gyro_sc2v_rst_ctrl_trim_d2d
 * [Supports Dynamic Change] 0 to 3: number of sc2v_rst pulses to be skipped before an actual one.
 */
#define REG_IPREG_BAR_REG_94_GYRO_SC2V_RST_CTRL_TRIM_D2D_POS      0x04
#define REG_IPREG_BAR_REG_94_GYRO_SC2V_RST_CTRL_TRIM_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_94_GYRO_SC2V_RST_CTRL_TRIM_D2D_POS)

/*
 * gyro_sc2v_rst_width_trim_d2d
 * [Supports Dynamic Change] Duration of sc2v reset, in PLL clock cycles. Reset is centered at transition of of sign signal
 * 00 -> 6
 * 01 -> 8
 * 10 ->10
 * 11 ->12
 */
#define REG_IPREG_BAR_REG_94_GYRO_SC2V_RST_WIDTH_TRIM_D2D_POS      0x06
#define REG_IPREG_BAR_REG_94_GYRO_SC2V_RST_WIDTH_TRIM_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_94_GYRO_SC2V_RST_WIDTH_TRIM_D2D_POS)



/*
 * REG_IPREG_BAR_REG_95
 * Register Name : IPREG_BAR_REG_95
 */

/*
 * gyro_sc2v_swcap_ctrl_cfg_trim_d2d
 * [Supports Dynamic Change] Configuration for gx_sc2v_ret_swcap_ctrl_a2a
 * 00 -> clock as reset, 01 -> clock as sign, 10 -> clock at 2 fdrive aligned to sign, 11 -> clock at fdrive/4
 */
#define REG_IPREG_BAR_REG_95_GYRO_SC2V_SWCAP_CTRL_CFG_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_95_GYRO_SC2V_SWCAP_CTRL_CFG_TRIM_D2D_MASK     0x03

/*
 * gz_dmd_phase_quadrant_trim_d2d
 * [Supports Dynamic Change] Coarse phase trim (quadrant) determining the initial delay from the fbkclk rising edge and the generation of the demodulator signals.
 */
#define REG_IPREG_BAR_REG_95_GZ_DMD_PHASE_QUADRANT_TRIM_D2D_POS      0x02
#define REG_IPREG_BAR_REG_95_GZ_DMD_PHASE_QUADRANT_TRIM_D2D_MASK     (0x03 << REG_IPREG_BAR_REG_95_GZ_DMD_PHASE_QUADRANT_TRIM_D2D_POS)

/*
 * gx_dmd_fine_phase_en_trim_d2d
 * [Supports Dynamic Change] Fine phase enable bit: 0: disabled; 1: enabled
 */
#define REG_IPREG_BAR_REG_95_GX_DMD_FINE_PHASE_EN_TRIM_D2D_POS      0x04
#define REG_IPREG_BAR_REG_95_GX_DMD_FINE_PHASE_EN_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_95_GX_DMD_FINE_PHASE_EN_TRIM_D2D_POS)

/*
 * gx_dmd_shift_trim_d2d
 * [Supports Dynamic Change] Waveform half-clock period shift. 0: no waveform shift; 1: half-clock period shift
 */
#define REG_IPREG_BAR_REG_95_GX_DMD_SHIFT_TRIM_D2D_POS      0x05
#define REG_IPREG_BAR_REG_95_GX_DMD_SHIFT_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_95_GX_DMD_SHIFT_TRIM_D2D_POS)

/*
 * gy_dmd_fine_phase_en_trim_d2d
 * [Supports Dynamic Change] Fine phase enable bit: 0: disabled; 1: enabled
 */
#define REG_IPREG_BAR_REG_95_GY_DMD_FINE_PHASE_EN_TRIM_D2D_POS      0x06
#define REG_IPREG_BAR_REG_95_GY_DMD_FINE_PHASE_EN_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_95_GY_DMD_FINE_PHASE_EN_TRIM_D2D_POS)

/*
 * gy_dmd_shift_trim_d2d
 * [Supports Dynamic Change] Waveform half-clock period shift. 0: no waveform shift; 1: half-clock period shift
 */
#define REG_IPREG_BAR_REG_95_GY_DMD_SHIFT_TRIM_D2D_POS      0x07
#define REG_IPREG_BAR_REG_95_GY_DMD_SHIFT_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_95_GY_DMD_SHIFT_TRIM_D2D_POS)



/*
 * REG_IPREG_BAR_REG_96
 * Register Name : IPREG_BAR_REG_96
 */

/*
 * gyro_2lev_cont_mode_trim_d2d
 * [Supports Dynamic Change] Sets the demod zero signal in continuous mode when the wave shape mode is set to 2-level mode. 0: gyro_ret_ctrl_zero has a high pulse around every gyro_ret_ctrl_sign rising-edge. 1: gyro_ret_ctrl_zero remains at a static 0.
 */
#define REG_IPREG_BAR_REG_96_GYRO_2LEV_CONT_MODE_TRIM_D2D_POS      0x00
#define REG_IPREG_BAR_REG_96_GYRO_2LEV_CONT_MODE_TRIM_D2D_MASK     0x01

/*
 * gyro_dmd_fd_trim_d2d
 * [Supports Dynamic Change] 0: normal operation: waveform period is Fdrive; 1: generate waveforms at double rate: waveform period is 2*Fdrive
 */
#define REG_IPREG_BAR_REG_96_GYRO_DMD_FD_TRIM_D2D_POS      0x01
#define REG_IPREG_BAR_REG_96_GYRO_DMD_FD_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_96_GYRO_DMD_FD_TRIM_D2D_POS)

/*
 * gyro_dmd_lowres_trim_d2d
 * [Supports Dynamic Change] Low resistance mixer configuration
 */
#define REG_IPREG_BAR_REG_96_GYRO_DMD_LOWRES_TRIM_D2D_POS      0x02
#define REG_IPREG_BAR_REG_96_GYRO_DMD_LOWRES_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_96_GYRO_DMD_LOWRES_TRIM_D2D_POS)

/*
 * gyro_dmd_mix_short_trim_d2d
 * [Supports Dynamic Change] Forces mixer shorted
 */
#define REG_IPREG_BAR_REG_96_GYRO_DMD_MIX_SHORT_TRIM_D2D_POS      0x03
#define REG_IPREG_BAR_REG_96_GYRO_DMD_MIX_SHORT_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_96_GYRO_DMD_MIX_SHORT_TRIM_D2D_POS)

/*
 * gyro_dmd_punct_mode_trim_d2d
 * [Supports Dynamic Change] 0: puncture to zero 1: multilevel puncture
 */
#define REG_IPREG_BAR_REG_96_GYRO_DMD_PUNCT_MODE_TRIM_D2D_POS      0x04
#define REG_IPREG_BAR_REG_96_GYRO_DMD_PUNCT_MODE_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_96_GYRO_DMD_PUNCT_MODE_TRIM_D2D_POS)

/*
 * gz_dmd_fine_phase_en_trim_d2d
 * [Supports Dynamic Change] Fine phase enable bit: 0: disabled; 1: enabled
 */
#define REG_IPREG_BAR_REG_96_GZ_DMD_FINE_PHASE_EN_TRIM_D2D_POS      0x05
#define REG_IPREG_BAR_REG_96_GZ_DMD_FINE_PHASE_EN_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_96_GZ_DMD_FINE_PHASE_EN_TRIM_D2D_POS)

/*
 * gz_dmd_shift_trim_d2d
 * [Supports Dynamic Change] Waveform half-clock period shift. 0: no waveform shift; 1: half-clock period shift
 */
#define REG_IPREG_BAR_REG_96_GZ_DMD_SHIFT_TRIM_D2D_POS      0x06
#define REG_IPREG_BAR_REG_96_GZ_DMD_SHIFT_TRIM_D2D_MASK     (0x01 << REG_IPREG_BAR_REG_96_GZ_DMD_SHIFT_TRIM_D2D_POS)



/*
 * REG_IPREG_BAR_REG_97
 * Register Name : IPREG_BAR_REG_97
 */

/*
 * gx_sc2v_cfg_spare_d2a
 * [Supports Dynamic Change] cfg spare trim
 */
#define REG_IPREG_BAR_REG_97_GX_SC2V_CFG_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_97_GX_SC2V_CFG_SPARE_D2A_MASK     0x03

/*
 * gx_sc2v_en_se_d2a
 * [Supports Dynamic Change] Single Ended test mode
 */
#define REG_IPREG_BAR_REG_97_GX_SC2V_EN_SE_D2A_POS      0x02
#define REG_IPREG_BAR_REG_97_GX_SC2V_EN_SE_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_97_GX_SC2V_EN_SE_D2A_POS)

/*
 * gy_sc2v_cfg_spare_d2a
 * [Supports Dynamic Change] cfg spare trim
 */
#define REG_IPREG_BAR_REG_97_GY_SC2V_CFG_SPARE_D2A_POS      0x04
#define REG_IPREG_BAR_REG_97_GY_SC2V_CFG_SPARE_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_97_GY_SC2V_CFG_SPARE_D2A_POS)

/*
 * gy_sc2v_en_se_d2a
 * [Supports Dynamic Change] Single Ended test mode
 */
#define REG_IPREG_BAR_REG_97_GY_SC2V_EN_SE_D2A_POS      0x06
#define REG_IPREG_BAR_REG_97_GY_SC2V_EN_SE_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_97_GY_SC2V_EN_SE_D2A_POS)



/*
 * REG_IPREG_BAR_REG_98
 * Register Name : IPREG_BAR_REG_98
 */

/*
 * gz_sc2v_cfg_spare_d2a
 * [Supports Dynamic Change] cfg spare trim
 */
#define REG_IPREG_BAR_REG_98_GZ_SC2V_CFG_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_98_GZ_SC2V_CFG_SPARE_D2A_MASK     0x03

/*
 * gz_sc2v_en_se_d2a
 * [Supports Dynamic Change] Single Ended test mode
 */
#define REG_IPREG_BAR_REG_98_GZ_SC2V_EN_SE_D2A_POS      0x02
#define REG_IPREG_BAR_REG_98_GZ_SC2V_EN_SE_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_98_GZ_SC2V_EN_SE_D2A_POS)

/*
 * gx_sc2v_dc2v_ph_meas_d2a
 * [Supports Dynamic Change] Dc2v Phase measure from atp
 */
#define REG_IPREG_BAR_REG_98_GX_SC2V_DC2V_PH_MEAS_D2A_POS      0x04
#define REG_IPREG_BAR_REG_98_GX_SC2V_DC2V_PH_MEAS_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_98_GX_SC2V_DC2V_PH_MEAS_D2A_POS)

/*
 * gx_sc2v_mux_all_short_d2a
 * [Supports Dynamic Change] Input Mux all short
 */
#define REG_IPREG_BAR_REG_98_GX_SC2V_MUX_ALL_SHORT_D2A_POS      0x05
#define REG_IPREG_BAR_REG_98_GX_SC2V_MUX_ALL_SHORT_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_98_GX_SC2V_MUX_ALL_SHORT_D2A_POS)

/*
 * gx_sc2v_oa_pd_b_ovd_d2a
 * [Supports Dynamic Change] Opamp pd_b overwrite
 */
#define REG_IPREG_BAR_REG_98_GX_SC2V_OA_PD_B_OVD_D2A_POS      0x06
#define REG_IPREG_BAR_REG_98_GX_SC2V_OA_PD_B_OVD_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_98_GX_SC2V_OA_PD_B_OVD_D2A_POS)

/*
 * gx_sc2v_os_buf_cfg_d2a
 * [Supports Dynamic Change] Offset Trim configuration
 */
#define REG_IPREG_BAR_REG_98_GX_SC2V_OS_BUF_CFG_D2A_POS      0x07
#define REG_IPREG_BAR_REG_98_GX_SC2V_OS_BUF_CFG_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_98_GX_SC2V_OS_BUF_CFG_D2A_POS)



/*
 * REG_IPREG_BAR_REG_99
 * Register Name : IPREG_BAR_REG_99
 */

/*
 * gy_sc2v_dc2v_ph_meas_d2a
 * [Supports Dynamic Change] Dc2v Phase measure from atp
 */
#define REG_IPREG_BAR_REG_99_GY_SC2V_DC2V_PH_MEAS_D2A_POS      0x00
#define REG_IPREG_BAR_REG_99_GY_SC2V_DC2V_PH_MEAS_D2A_MASK     0x01

/*
 * gy_sc2v_mux_all_short_d2a
 * [Supports Dynamic Change] Input Mux all short
 */
#define REG_IPREG_BAR_REG_99_GY_SC2V_MUX_ALL_SHORT_D2A_POS      0x01
#define REG_IPREG_BAR_REG_99_GY_SC2V_MUX_ALL_SHORT_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GY_SC2V_MUX_ALL_SHORT_D2A_POS)

/*
 * gy_sc2v_oa_pd_b_ovd_d2a
 * [Supports Dynamic Change] Opamp pd_b overwrite
 */
#define REG_IPREG_BAR_REG_99_GY_SC2V_OA_PD_B_OVD_D2A_POS      0x02
#define REG_IPREG_BAR_REG_99_GY_SC2V_OA_PD_B_OVD_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GY_SC2V_OA_PD_B_OVD_D2A_POS)

/*
 * gy_sc2v_os_buf_cfg_d2a
 * [Supports Dynamic Change] Offset Trim configuration
 */
#define REG_IPREG_BAR_REG_99_GY_SC2V_OS_BUF_CFG_D2A_POS      0x03
#define REG_IPREG_BAR_REG_99_GY_SC2V_OS_BUF_CFG_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GY_SC2V_OS_BUF_CFG_D2A_POS)

/*
 * gz_sc2v_dc2v_ph_meas_d2a
 * [Supports Dynamic Change] Dc2v Phase measure from atp
 */
#define REG_IPREG_BAR_REG_99_GZ_SC2V_DC2V_PH_MEAS_D2A_POS      0x04
#define REG_IPREG_BAR_REG_99_GZ_SC2V_DC2V_PH_MEAS_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GZ_SC2V_DC2V_PH_MEAS_D2A_POS)

/*
 * gz_sc2v_mux_all_short_d2a
 * [Supports Dynamic Change] Input Mux all short
 */
#define REG_IPREG_BAR_REG_99_GZ_SC2V_MUX_ALL_SHORT_D2A_POS      0x05
#define REG_IPREG_BAR_REG_99_GZ_SC2V_MUX_ALL_SHORT_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GZ_SC2V_MUX_ALL_SHORT_D2A_POS)

/*
 * gz_sc2v_oa_pd_b_ovd_d2a
 * [Supports Dynamic Change] Opamp pd_b overwrite
 */
#define REG_IPREG_BAR_REG_99_GZ_SC2V_OA_PD_B_OVD_D2A_POS      0x06
#define REG_IPREG_BAR_REG_99_GZ_SC2V_OA_PD_B_OVD_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GZ_SC2V_OA_PD_B_OVD_D2A_POS)

/*
 * gz_sc2v_os_buf_cfg_d2a
 * [Supports Dynamic Change] Offset Trim configuration
 */
#define REG_IPREG_BAR_REG_99_GZ_SC2V_OS_BUF_CFG_D2A_POS      0x07
#define REG_IPREG_BAR_REG_99_GZ_SC2V_OS_BUF_CFG_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_99_GZ_SC2V_OS_BUF_CFG_D2A_POS)



/*
 * REG_IPREG_BAR_REG_100
 * Register Name : IPREG_BAR_REG_100
 */

/*
 * gx_dmd_spare_d2a
 * [Supports Dynamic Change] spare CFG bits
 */
#define REG_IPREG_BAR_REG_100_GX_DMD_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_100_GX_DMD_SPARE_D2A_MASK     0x0f

/*
 * gy_dmd_spare_d2a
 * [Supports Dynamic Change] spare CFG bits
 */
#define REG_IPREG_BAR_REG_100_GY_DMD_SPARE_D2A_POS      0x04
#define REG_IPREG_BAR_REG_100_GY_DMD_SPARE_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_100_GY_DMD_SPARE_D2A_POS)



/*
 * REG_IPREG_BAR_REG_101
 * Register Name : IPREG_BAR_REG_101
 */

/*
 * gz_dmd_spare_d2a
 * [Supports Dynamic Change] spare CFG bits
 */
#define REG_IPREG_BAR_REG_101_GZ_DMD_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_101_GZ_DMD_SPARE_D2A_MASK     0x0f



/*
 * REG_IPREG_BAR_REG_102
 * Register Name : IPREG_BAR_REG_102
 */

/*
 * gyro_dmd_test_d2a
 * [Supports Dynamic Change] Gyro demod test configuration selection (0 = normal mode)
 */
#define REG_IPREG_BAR_REG_102_GYRO_DMD_TEST_D2A_POS      0x00
#define REG_IPREG_BAR_REG_102_GYRO_DMD_TEST_D2A_MASK     0x0f

/*
 * gyro_adc_clk_div2_d2a
 * [Supports Dynamic Change] Gyro demod ADC clock divide by 2 (common to 3 axes) (1 = divide by 2)
 */
#define REG_IPREG_BAR_REG_102_GYRO_ADC_CLK_DIV2_D2A_POS      0x04
#define REG_IPREG_BAR_REG_102_GYRO_ADC_CLK_DIV2_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_102_GYRO_ADC_CLK_DIV2_D2A_POS)

/*
 * pd_gyro_adc_b_d2a
 * [Supports Dynamic Change] Gyro demod ADC pd_b override (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_102_PD_GYRO_ADC_B_D2A_POS      0x05
#define REG_IPREG_BAR_REG_102_PD_GYRO_ADC_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_102_PD_GYRO_ADC_B_D2A_POS)

/*
 * pd_gyro_ana_mixer_b_d2a
 * [Supports Dynamic Change] Gyro analog mixer pd_b  override (local to stop analog mixer in test mode)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_102_PD_GYRO_ANA_MIXER_B_D2A_POS      0x06
#define REG_IPREG_BAR_REG_102_PD_GYRO_ANA_MIXER_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_102_PD_GYRO_ANA_MIXER_B_D2A_POS)



/*
 * REG_IPREG_BAR_REG_103
 * Register Name : IPREG_BAR_REG_103
 */

/*
 * gyro_drv_pdb_mask_d2a
 * [Supports Dynamic Change] From MSB to LSB: dig_pdb_reg, dig_pdb_phs, dig_pdb_gyr_loop, dig_pdb_dmdcomp, dig_pdb_oscmon, dig_pdb_eng_comp, dig_pdb_bias
 */
#define REG_IPREG_BAR_REG_103_GYRO_DRV_PDB_MASK_D2A_POS      0x00
#define REG_IPREG_BAR_REG_103_GYRO_DRV_PDB_MASK_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_104
 * Register Name : IPREG_BAR_REG_104
 */

/*
 * gyro_drv_spare1_d2a
 * [Supports Dynamic Change] nan
 */
#define REG_IPREG_BAR_REG_104_GYRO_DRV_SPARE1_D2A_POS      0x00
#define REG_IPREG_BAR_REG_104_GYRO_DRV_SPARE1_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_105
 * Register Name : IPREG_BAR_REG_105
 */

/*
 * gyro_drv_spare2_d2a
 * [Supports Dynamic Change] nan
 */
#define REG_IPREG_BAR_REG_105_GYRO_DRV_SPARE2_D2A_POS      0x00
#define REG_IPREG_BAR_REG_105_GYRO_DRV_SPARE2_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_106
 * Register Name : IPREG_BAR_REG_106
 */

/*
 * gyro_drv_test_fsmforce_d2a
 * [Supports Dynamic Change] Drive state machine access to internal state (force)
 */
#define REG_IPREG_BAR_REG_106_GYRO_DRV_TEST_FSMFORCE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_106_GYRO_DRV_TEST_FSMFORCE_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_107
 * Register Name : IPREG_BAR_REG_107
 */

/*
 * en_gyro_drv_dcc_test_d2a
 * [Supports Dynamic Change] nan
 */
#define REG_IPREG_BAR_REG_107_EN_GYRO_DRV_DCC_TEST_D2A_POS      0x00
#define REG_IPREG_BAR_REG_107_EN_GYRO_DRV_DCC_TEST_D2A_MASK     0x01

/*
 * gyro_drv_disable_oscdetector_d2a
 * [Supports Dynamic Change] Bypass oscillator monitor
 */
#define REG_IPREG_BAR_REG_107_GYRO_DRV_DISABLE_OSCDETECTOR_D2A_POS      0x01
#define REG_IPREG_BAR_REG_107_GYRO_DRV_DISABLE_OSCDETECTOR_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_107_GYRO_DRV_DISABLE_OSCDETECTOR_D2A_POS)

/*
 * gyro_drv_zero_force_d2a
 * [Supports Dynamic Change] if 1 keep drive electrodes to Vlow
 */
#define REG_IPREG_BAR_REG_107_GYRO_DRV_ZERO_FORCE_D2A_POS      0x02
#define REG_IPREG_BAR_REG_107_GYRO_DRV_ZERO_FORCE_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_107_GYRO_DRV_ZERO_FORCE_D2A_POS)



/*
 * REG_IPREG_BAR_REG_108
 * Register Name : IPREG_BAR_REG_108
 */

/*
 * gyro_bias_spare_d2a
 * [Supports Dynamic Change] Spare configuration register
 */
#define REG_IPREG_BAR_REG_108_GYRO_BIAS_SPARE_D2A_POS      0x00
#define REG_IPREG_BAR_REG_108_GYRO_BIAS_SPARE_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_109
 * Register Name : IPREG_BAR_REG_109
 */

/*
 * pd_gyro_bias_adcvcmbuffer_b_d2a
 * [Supports Dynamic Change] Power down override for adc common mode reference buffer
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_ADCVCMBUFFER_B_D2A_POS      0x00
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_ADCVCMBUFFER_B_D2A_MASK     0x01

/*
 * pd_gyro_bias_areg_b_d2a
 * [Supports Dynamic Change] Power down override for gyro avdd regulator
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_AREG_B_D2A_POS      0x01
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_AREG_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_AREG_B_D2A_POS)

/*
 * pd_gyro_bias_areg_cp25v_b_d2a
 * [Supports Dynamic Change] Power down override for cp25v avdd regulator
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_AREG_CP25V_B_D2A_POS      0x02
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_AREG_CP25V_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_AREG_CP25V_B_D2A_POS)

/*
 * pd_gyro_bias_bg_b_d2a
 * [Supports Dynamic Change] Power down override for brokaw bandgap
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_BG_B_D2A_POS      0x03
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_BG_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_BG_B_D2A_POS)

/*
 * pd_gyro_bias_ibiasgen_b_d2a
 * [Supports Dynamic Change] Power down override for internal current mirror
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_IBIASGEN_B_D2A_POS      0x04
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_IBIASGEN_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_IBIASGEN_B_D2A_POS)

/*
 * pd_gyro_bias_refbuffer_b_d2a
 * [Supports Dynamic Change] Power down override for adc current reference buffer
 */
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_REFBUFFER_B_D2A_POS      0x05
#define REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_REFBUFFER_B_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_109_PD_GYRO_BIAS_REFBUFFER_B_D2A_POS)

/*
 * REG_IPREG_BAR_REG_110
 * Register Name : IPREG_BAR_REG_110
 */

/*
 * spare2_d2a
 * Spare
 */
#define REG_IPREG_BAR_REG_110_SPARE2_D2A_POS      0x00
#define REG_IPREG_BAR_REG_110_SPARE2_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_111
 * Register Name : IPREG_BAR_REG_111
 */

/*
 * dis_gyro_pllclk_d2a
 * [Supports Dynamic Change] PLL output clock buffer disable for test purposes
 */
#define REG_IPREG_BAR_REG_111_DIS_GYRO_PLLCLK_D2A_POS      0x00
#define REG_IPREG_BAR_REG_111_DIS_GYRO_PLLCLK_D2A_MASK     0x01

/*
 * dis_rcosc_oscclk_d2a
 * [Supports Dynamic Change] RCOSC output clock buffer disable for test purposes
 */
#define REG_IPREG_BAR_REG_111_DIS_RCOSC_OSCCLK_D2A_POS      0x01
#define REG_IPREG_BAR_REG_111_DIS_RCOSC_OSCCLK_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_111_DIS_RCOSC_OSCCLK_D2A_POS)

/*
 * en_gyro_pll_refbuf_d2a
 * [Supports Dynamic Change] PLL voltage reference bufffer enable trim reg
 */
#define REG_IPREG_BAR_REG_111_EN_GYRO_PLL_REFBUF_D2A_POS      0x02
#define REG_IPREG_BAR_REG_111_EN_GYRO_PLL_REFBUF_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_111_EN_GYRO_PLL_REFBUF_D2A_POS)

/*
 * en_rcosc_calib_d2a
 * [Supports Dynamic Change] Increases the fine tuning range of RCOSC and also increases frequency trim LSB
 */
#define REG_IPREG_BAR_REG_111_EN_RCOSC_CALIB_D2A_POS      0x03
#define REG_IPREG_BAR_REG_111_EN_RCOSC_CALIB_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_111_EN_RCOSC_CALIB_D2A_POS)

/*
 * pll_vco_mode_d2a
 * [Supports Dynamic Change] PLL VCO mode, when high enable PLL VCO Vctrl DAC for VCO calibration
 */
#define REG_IPREG_BAR_REG_111_PLL_VCO_MODE_D2A_POS      0x04
#define REG_IPREG_BAR_REG_111_PLL_VCO_MODE_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_111_PLL_VCO_MODE_D2A_POS)

/*
 * sel_rcosc_plldiv_d2a
 * [Supports Dynamic Change] When high, the input to the PLL feedback divider is from RCOSC output instead of PLL output clock for test purpose
 */
#define REG_IPREG_BAR_REG_111_SEL_RCOSC_PLLDIV_D2A_POS      0x05
#define REG_IPREG_BAR_REG_111_SEL_RCOSC_PLLDIV_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_111_SEL_RCOSC_PLLDIV_D2A_POS)



/*
 * REG_IPREG_BAR_REG_112
 * Register Name : IPREG_BAR_REG_112
 */

/*
 * gx_sc2v_soc_trim_d2a
 * [Supports Dynamic Change] SOC trim
 */
#define REG_IPREG_BAR_REG_112_GX_SC2V_SOC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_112_GX_SC2V_SOC_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_113
 * Register Name : IPREG_BAR_REG_113
 */

/*
 * gy_sc2v_soc_trim_d2a
 * [Supports Dynamic Change] SOC trim
 */
#define REG_IPREG_BAR_REG_113_GY_SC2V_SOC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_113_GY_SC2V_SOC_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_114
 * Register Name : IPREG_BAR_REG_114
 */

/*
 * gz_sc2v_soc_trim_d2a
 * [Supports Dynamic Change] SOC trim
 */
#define REG_IPREG_BAR_REG_114_GZ_SC2V_SOC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_114_GZ_SC2V_SOC_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_115
 * Register Name : IPREG_BAR_REG_115
 */

/*
 * gx_sc2v_ft_trim_d2a
 * [Supports Dynamic Change] Feedthrough trim
 */
#define REG_IPREG_BAR_REG_115_GX_SC2V_FT_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_115_GX_SC2V_FT_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_116
 * Register Name : IPREG_BAR_REG_116
 */

/*
 * gx_sc2v_gain_lfs_trim_d2a
 * [Supports Dynamic Change] 500 dps LFS gain trim
 */
#define REG_IPREG_BAR_REG_116_GX_SC2V_GAIN_LFS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_116_GX_SC2V_GAIN_LFS_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_117
 * Register Name : IPREG_BAR_REG_117
 */

/*
 * gy_sc2v_ft_trim_d2a
 * [Supports Dynamic Change] Feedthrough trim
 */
#define REG_IPREG_BAR_REG_117_GY_SC2V_FT_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_117_GY_SC2V_FT_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_118
 * Register Name : IPREG_BAR_REG_118
 */

/*
 * gy_sc2v_gain_lfs_trim_d2a
 * [Supports Dynamic Change] 500 dps LFS gain trim
 */
#define REG_IPREG_BAR_REG_118_GY_SC2V_GAIN_LFS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_118_GY_SC2V_GAIN_LFS_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_119
 * Register Name : IPREG_BAR_REG_119
 */

/*
 * gz_sc2v_ft_trim_d2a
 * [Supports Dynamic Change] Feedthrough trim
 */
#define REG_IPREG_BAR_REG_119_GZ_SC2V_FT_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_119_GZ_SC2V_FT_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_120
 * Register Name : IPREG_BAR_REG_120
 */

/*
 * gz_sc2v_gain_lfs_trim_d2a
 * [Supports Dynamic Change] 500 dps LFS gain trim
 */
#define REG_IPREG_BAR_REG_120_GZ_SC2V_GAIN_LFS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_120_GZ_SC2V_GAIN_LFS_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_121
 * Register Name : IPREG_BAR_REG_121
 */

/*
 * gx_sc2v_gain_hfs_trim_d2a
 * [Supports Dynamic Change]  2000 dps HFS gain trim
 */
#define REG_IPREG_BAR_REG_121_GX_SC2V_GAIN_HFS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_121_GX_SC2V_GAIN_HFS_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_122
 * Register Name : IPREG_BAR_REG_122
 */

/*
 * gx_sc2v_off_diff_trim_d2a
 * [Supports Dynamic Change] input differential offset trim
 */
#define REG_IPREG_BAR_REG_122_GX_SC2V_OFF_DIFF_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_122_GX_SC2V_OFF_DIFF_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_123
 * Register Name : IPREG_BAR_REG_123
 */

/*
 * gy_sc2v_gain_hfs_trim_d2a
 * [Supports Dynamic Change]  2000 dps HFS gain trim
 */
#define REG_IPREG_BAR_REG_123_GY_SC2V_GAIN_HFS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_123_GY_SC2V_GAIN_HFS_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_124
 * Register Name : IPREG_BAR_REG_124
 */

/*
 * gy_sc2v_off_diff_trim_d2a
 * [Supports Dynamic Change] input differential offset trim
 */
#define REG_IPREG_BAR_REG_124_GY_SC2V_OFF_DIFF_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_124_GY_SC2V_OFF_DIFF_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_125
 * Register Name : IPREG_BAR_REG_125
 */

/*
 * gz_sc2v_gain_hfs_trim_d2a
 * [Supports Dynamic Change]  2000 dps HFS gain trim
 */
#define REG_IPREG_BAR_REG_125_GZ_SC2V_GAIN_HFS_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_125_GZ_SC2V_GAIN_HFS_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_126
 * Register Name : IPREG_BAR_REG_126
 */

/*
 * gz_sc2v_off_diff_trim_d2a
 * [Supports Dynamic Change] input differential offset trim
 */
#define REG_IPREG_BAR_REG_126_GZ_SC2V_OFF_DIFF_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_126_GZ_SC2V_OFF_DIFF_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_127
 * Register Name : IPREG_BAR_REG_127
 */

/*
 * gx_sc2v_off_cm_trim_d2a
 * [Supports Dynamic Change] input common mode offset trim
 */
#define REG_IPREG_BAR_REG_127_GX_SC2V_OFF_CM_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_127_GX_SC2V_OFF_CM_TRIM_D2A_MASK     0x0f

/*
 * gy_sc2v_off_cm_trim_d2a
 * [Supports Dynamic Change] input common mode offset trim
 */
#define REG_IPREG_BAR_REG_127_GY_SC2V_OFF_CM_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_127_GY_SC2V_OFF_CM_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_127_GY_SC2V_OFF_CM_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_128
 * Register Name : IPREG_BAR_REG_128
 */

/*
 * gz_sc2v_off_cm_trim_d2a
 * [Supports Dynamic Change] input common mode offset trim
 */
#define REG_IPREG_BAR_REG_128_GZ_SC2V_OFF_CM_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_128_GZ_SC2V_OFF_CM_TRIM_D2A_MASK     0x0f

/*
 * gx_sc2v_noise_mode_trim_d2a
 * [Supports Dynamic Change] noise mode control
 */
#define REG_IPREG_BAR_REG_128_GX_SC2V_NOISE_MODE_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_128_GX_SC2V_NOISE_MODE_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_128_GX_SC2V_NOISE_MODE_TRIM_D2A_POS)

/*
 * gy_sc2v_noise_mode_trim_d2a
 * [Supports Dynamic Change] noise mode control
 */
#define REG_IPREG_BAR_REG_128_GY_SC2V_NOISE_MODE_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_128_GY_SC2V_NOISE_MODE_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_128_GY_SC2V_NOISE_MODE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_129
 * Register Name : IPREG_BAR_REG_129
 */

/*
 * gz_sc2v_noise_mode_trim_d2a
 * [Supports Dynamic Change] noise mode control
 */
#define REG_IPREG_BAR_REG_129_GZ_SC2V_NOISE_MODE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_129_GZ_SC2V_NOISE_MODE_TRIM_D2A_MASK     0x03

/*
 * gx_sc2v_outstage_hc_trim_d2a
 * [Supports Dynamic Change] Output stage current increase
 */
#define REG_IPREG_BAR_REG_129_GX_SC2V_OUTSTAGE_HC_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_129_GX_SC2V_OUTSTAGE_HC_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_129_GX_SC2V_OUTSTAGE_HC_TRIM_D2A_POS)

/*
 * gx_sc2v_spare_trim_d2a
 * [Supports Dynamic Change] spare trim
 */
#define REG_IPREG_BAR_REG_129_GX_SC2V_SPARE_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_129_GX_SC2V_SPARE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_129_GX_SC2V_SPARE_TRIM_D2A_POS)

/*
 * gy_sc2v_outstage_hc_trim_d2a
 * [Supports Dynamic Change] Output stage current increase
 */
#define REG_IPREG_BAR_REG_129_GY_SC2V_OUTSTAGE_HC_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_129_GY_SC2V_OUTSTAGE_HC_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_129_GY_SC2V_OUTSTAGE_HC_TRIM_D2A_POS)

/*
 * gy_sc2v_spare_trim_d2a
 * [Supports Dynamic Change] spare trim
 */
#define REG_IPREG_BAR_REG_129_GY_SC2V_SPARE_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_129_GY_SC2V_SPARE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_129_GY_SC2V_SPARE_TRIM_D2A_POS)

/*
 * gz_sc2v_outstage_hc_trim_d2a
 * [Supports Dynamic Change] Output stage current increase
 */
#define REG_IPREG_BAR_REG_129_GZ_SC2V_OUTSTAGE_HC_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_129_GZ_SC2V_OUTSTAGE_HC_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_129_GZ_SC2V_OUTSTAGE_HC_TRIM_D2A_POS)

/*
 * gz_sc2v_spare_trim_d2a
 * [Supports Dynamic Change] spare trim
 */
#define REG_IPREG_BAR_REG_129_GZ_SC2V_SPARE_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_129_GZ_SC2V_SPARE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_129_GZ_SC2V_SPARE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_130
 * Register Name : IPREG_BAR_REG_130
 */

/*
 * gyro_sc2v_rrst_trim_d2a
 * [Supports Dynamic Change] Ramp reset trim
 */
#define REG_IPREG_BAR_REG_130_GYRO_SC2V_RRST_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_130_GYRO_SC2V_RRST_TRIM_D2A_MASK     0x03

/*
 * gyro_en_b_rsw_filt_trim_d2a
 * [Supports Dynamic Change] Switch Cap Filter disable
 */
#define REG_IPREG_BAR_REG_130_GYRO_EN_B_RSW_FILT_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_130_GYRO_EN_B_RSW_FILT_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_130_GYRO_EN_B_RSW_FILT_TRIM_D2A_POS)

/*
 * gyro_sc2v_dis_prt_trim_d2a
 * [Supports Dynamic Change] Input protection rst disable
 */
#define REG_IPREG_BAR_REG_130_GYRO_SC2V_DIS_PRT_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_130_GYRO_SC2V_DIS_PRT_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_130_GYRO_SC2V_DIS_PRT_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_131
 * Register Name : IPREG_BAR_REG_131
 */

/*
 * gx_dmd_spare_trim_d2a
 * [Supports Dynamic Change] spare OTP bits
 */
#define REG_IPREG_BAR_REG_131_GX_DMD_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_131_GX_DMD_SPARE_TRIM_D2A_MASK     0x0f

/*
 * gy_dmd_spare_trim_d2a
 * [Supports Dynamic Change] spare OTP bits
 */
#define REG_IPREG_BAR_REG_131_GY_DMD_SPARE_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_131_GY_DMD_SPARE_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_131_GY_DMD_SPARE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_132
 * Register Name : IPREG_BAR_REG_132
 */

/*
 * gz_dmd_spare_trim_d2a
 * [Supports Dynamic Change] spare OTP bits
 */
#define REG_IPREG_BAR_REG_132_GZ_DMD_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_132_GZ_DMD_SPARE_TRIM_D2A_MASK     0x0f

/*
 * en_gx_adc_voff_trim_d2a
 * [Supports Dynamic Change] Enable ADC input offset
 */
#define REG_IPREG_BAR_REG_132_EN_GX_ADC_VOFF_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_132_EN_GX_ADC_VOFF_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_132_EN_GX_ADC_VOFF_TRIM_D2A_POS)

/*
 * en_gy_adc_voff_trim_d2a
 * [Supports Dynamic Change] Enable ADC input offset
 */
#define REG_IPREG_BAR_REG_132_EN_GY_ADC_VOFF_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_132_EN_GY_ADC_VOFF_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_132_EN_GY_ADC_VOFF_TRIM_D2A_POS)

/*
 * en_gz_adc_voff_trim_d2a
 * [Supports Dynamic Change] Enable ADC input offset
 */
#define REG_IPREG_BAR_REG_132_EN_GZ_ADC_VOFF_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_132_EN_GZ_ADC_VOFF_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_132_EN_GZ_ADC_VOFF_TRIM_D2A_POS)

/*
 * gx_adc_voff_sign_trim_d2a
 * [Supports Dynamic Change] ADC input offset sign selection
 */
#define REG_IPREG_BAR_REG_132_GX_ADC_VOFF_SIGN_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_132_GX_ADC_VOFF_SIGN_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_132_GX_ADC_VOFF_SIGN_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_133
 * Register Name : IPREG_BAR_REG_133
 */

/*
 * gx_adc_voffx2_trim_d2a
 * [Supports Dynamic Change] Enable 2x ADC input offset selection
 */
#define REG_IPREG_BAR_REG_133_GX_ADC_VOFFX2_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_133_GX_ADC_VOFFX2_TRIM_D2A_MASK     0x01

/*
 * gx_dmd_mixer_lo_inv_trim_d2a
 * [Supports Dynamic Change] sets the polarity of the demod output
 */
#define REG_IPREG_BAR_REG_133_GX_DMD_MIXER_LO_INV_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_133_GX_DMD_MIXER_LO_INV_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GX_DMD_MIXER_LO_INV_TRIM_D2A_POS)

/*
 * gy_adc_voff_sign_trim_d2a
 * [Supports Dynamic Change] ADC input offset sign selection
 */
#define REG_IPREG_BAR_REG_133_GY_ADC_VOFF_SIGN_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_133_GY_ADC_VOFF_SIGN_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GY_ADC_VOFF_SIGN_TRIM_D2A_POS)

/*
 * gy_adc_voffx2_trim_d2a
 * [Supports Dynamic Change] Enable 2x ADC input offset selection
 */
#define REG_IPREG_BAR_REG_133_GY_ADC_VOFFX2_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_133_GY_ADC_VOFFX2_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GY_ADC_VOFFX2_TRIM_D2A_POS)

/*
 * gy_dmd_mixer_lo_inv_trim_d2a
 * [Supports Dynamic Change] sets the polarity of the demod output
 */
#define REG_IPREG_BAR_REG_133_GY_DMD_MIXER_LO_INV_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_133_GY_DMD_MIXER_LO_INV_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GY_DMD_MIXER_LO_INV_TRIM_D2A_POS)

/*
 * gz_adc_voff_sign_trim_d2a
 * [Supports Dynamic Change] ADC input offset sign selection
 */
#define REG_IPREG_BAR_REG_133_GZ_ADC_VOFF_SIGN_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_133_GZ_ADC_VOFF_SIGN_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GZ_ADC_VOFF_SIGN_TRIM_D2A_POS)

/*
 * gz_adc_voffx2_trim_d2a
 * [Supports Dynamic Change] Enable 2x ADC input offset selection
 */
#define REG_IPREG_BAR_REG_133_GZ_ADC_VOFFX2_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_133_GZ_ADC_VOFFX2_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GZ_ADC_VOFFX2_TRIM_D2A_POS)

/*
 * gz_dmd_mixer_lo_inv_trim_d2a
 * [Supports Dynamic Change] sets the polarity of the demod output
 */
#define REG_IPREG_BAR_REG_133_GZ_DMD_MIXER_LO_INV_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_133_GZ_DMD_MIXER_LO_INV_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_133_GZ_DMD_MIXER_LO_INV_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_134
 * Register Name : IPREG_BAR_REG_134
 */

/*
 * gyro_adc_chop_duty_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC chop duty cycle trim (0000: duty cycle 50%)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_134_GYRO_ADC_CHOP_DUTY_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_134_GYRO_ADC_CHOP_DUTY_TRIM_D2A_MASK     0x0f

/*
 * gyro_adc_rc_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC RC trim (0110 = typ Res & Cap corner case)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_134_GYRO_ADC_RC_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_134_GYRO_ADC_RC_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_134_GYRO_ADC_RC_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_135
 * Register Name : IPREG_BAR_REG_135
 */

/*
 * gyro_adc_chop_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC chop frequency selection (000 = chopper disabled; def. 010 = chop frequency = 8kHz)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_135_GYRO_ADC_CHOP_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_135_GYRO_ADC_CHOP_TRIM_D2A_MASK     0x07

/*
 * gyro_adc_dither_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC dither amplitude selection (000 = dither disabled)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_135_GYRO_ADC_DITHER_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_135_GYRO_ADC_DITHER_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_135_GYRO_ADC_DITHER_TRIM_D2A_POS)

/*
 * gyro_adc_gain_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC gain trim (11: FS = 1.25V)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_135_GYRO_ADC_GAIN_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_135_GYRO_ADC_GAIN_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_135_GYRO_ADC_GAIN_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_136
 * Register Name : IPREG_BAR_REG_136
 */

/*
 * en_gyro_adc_dem_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC DEM enable (1 = DEM enabled)  (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_136_EN_GYRO_ADC_DEM_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_136_EN_GYRO_ADC_DEM_TRIM_D2A_MASK     0x01

/*
 * en_gyro_adc_dither_trim_d2a
 * [Supports Dynamic Change] Enable new ADC dither feature (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_136_EN_GYRO_ADC_DITHER_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_136_EN_GYRO_ADC_DITHER_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_136_EN_GYRO_ADC_DITHER_TRIM_D2A_POS)

/*
 * en_gyro_mix_res_trim_d2a
 * [Supports Dynamic Change] Enable Resistor Divider within mixer for 7-levels mixer (1=res. divider connected; 0=res. divider floating)
 */
#define REG_IPREG_BAR_REG_136_EN_GYRO_MIX_RES_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_136_EN_GYRO_MIX_RES_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_136_EN_GYRO_MIX_RES_TRIM_D2A_POS)

/*
 * gyro_adc_chop_dm_trim_d2a
 * [Supports Dynamic Change] Gyro demod ADC chop duty mode trim (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_136_GYRO_ADC_CHOP_DM_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_136_GYRO_ADC_CHOP_DM_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_136_GYRO_ADC_CHOP_DM_TRIM_D2A_POS)

/*
 * gyro_adc_comp_duty_dis_trim_d2a
 * [Supports Dynamic Change] 1: disables comparator's duty cycle (common to 3 axes)
 */
#define REG_IPREG_BAR_REG_136_GYRO_ADC_COMP_DUTY_DIS_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_136_GYRO_ADC_COMP_DUTY_DIS_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_136_GYRO_ADC_COMP_DUTY_DIS_TRIM_D2A_POS)

/*
 * gyro_adc_int1_bw_trim_d2a
 * [Supports Dynamic Change] Trim bias current to increase int1 GBW (0 = 250nA; 1 = 375nA)
 */
#define REG_IPREG_BAR_REG_136_GYRO_ADC_INT1_BW_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_136_GYRO_ADC_INT1_BW_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_136_GYRO_ADC_INT1_BW_TRIM_D2A_POS)

/*
 * gyro_mix_levels_trim_d2a
 * [Supports Dynamic Change] Mixer levels selection (0 = 2/3-level mixer; 1 = 7-level mixer)
 */
#define REG_IPREG_BAR_REG_136_GYRO_MIX_LEVELS_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_136_GYRO_MIX_LEVELS_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_136_GYRO_MIX_LEVELS_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_137
 * Register Name : IPREG_BAR_REG_137
 */

/*
 * gyro_drv_chpclk_sel_trim_d2a
 * [Supports Dynamic Change] bit<7> hvdlog polarity, bit<6> deglitch time in normal 9V / 6V: low 150us, high 1ms, bit<5:4> chp_poshv, bit<3:2> chp_pos, bit<1:0> clk_neg
 */
#define REG_IPREG_BAR_REG_137_GYRO_DRV_CHPCLK_SEL_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_137_GYRO_DRV_CHPCLK_SEL_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_138
 * Register Name : IPREG_BAR_REG_138
 */

/*
 * gyro_drv_agc_amp_trim_d2a
 * [Supports Dynamic Change] DC2V amplitude trim
 */
#define REG_IPREG_BAR_REG_138_GYRO_DRV_AGC_AMP_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_138_GYRO_DRV_AGC_AMP_TRIM_D2A_MASK     0x0f

/*
 * gyro_drv_agc_gain_trim_d2a
 * [Supports Dynamic Change] AGC loop gain trim (V2I gain)
 */
#define REG_IPREG_BAR_REG_138_GYRO_DRV_AGC_GAIN_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_138_GYRO_DRV_AGC_GAIN_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_138_GYRO_DRV_AGC_GAIN_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_139
 * Register Name : IPREG_BAR_REG_139
 */

/*
 * gyro_drv_agc_lp_trim_d2a
 * [Supports Dynamic Change] AGC PI low pass trimming
 */
#define REG_IPREG_BAR_REG_139_GYRO_DRV_AGC_LP_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_139_GYRO_DRV_AGC_LP_TRIM_D2A_MASK     0x0f

/*
 * gyro_drv_hvsup_trim_d2a
 * [Supports Dynamic Change] Charge pump input regulator trim
 */
#define REG_IPREG_BAR_REG_139_GYRO_DRV_HVSUP_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_139_GYRO_DRV_HVSUP_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_139_GYRO_DRV_HVSUP_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_140
 * Register Name : IPREG_BAR_REG_140
 */

/*
 * gyro_drv_spare1_trim_d2a
 * [Supports Dynamic Change] Bit<3> unused, bit <2:0> OVD thresholds
 */
#define REG_IPREG_BAR_REG_140_GYRO_DRV_SPARE1_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_140_GYRO_DRV_SPARE1_TRIM_D2A_MASK     0x0f

/*
 * gyro_drv_clk_chop_sel_trim_d2a
 * [Supports Dynamic Change] AGC amplifier Chop clock configuration
 */
#define REG_IPREG_BAR_REG_140_GYRO_DRV_CLK_CHOP_SEL_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_140_GYRO_DRV_CLK_CHOP_SEL_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_140_GYRO_DRV_CLK_CHOP_SEL_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_141
 * Register Name : IPREG_BAR_REG_141
 */

/*
 * gyro_drv_phs_freq_trim_d2a
 * [Supports Dynamic Change] Phase shifter pole frequency
 */
#define REG_IPREG_BAR_REG_141_GYRO_DRV_PHS_FREQ_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_141_GYRO_DRV_PHS_FREQ_TRIM_D2A_MASK     0x07

/*
 * gyro_drv_phs_gain_cm_trim_d2a
 * [Supports Dynamic Change] Phase shifter gain trim (Start-up V2I: common mode trim)
 */
#define REG_IPREG_BAR_REG_141_GYRO_DRV_PHS_GAIN_CM_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_141_GYRO_DRV_PHS_GAIN_CM_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_141_GYRO_DRV_PHS_GAIN_CM_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_142
 * Register Name : IPREG_BAR_REG_142
 */

/*
 * gyro_drv_phs_gain_diff_trim_d2a
 * [Supports Dynamic Change] Phase shifter gain trim (Start-up V2I: differential mode trim)
 */
#define REG_IPREG_BAR_REG_142_GYRO_DRV_PHS_GAIN_DIFF_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_142_GYRO_DRV_PHS_GAIN_DIFF_TRIM_D2A_MASK     0x07

/*
 * gyro_drv_clk_oscmon_timeout_trim_d2a
 * [Supports Dynamic Change] Define range of frequency in which AGC can be considered in lock
 */
#define REG_IPREG_BAR_REG_142_GYRO_DRV_CLK_OSCMON_TIMEOUT_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_142_GYRO_DRV_CLK_OSCMON_TIMEOUT_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_142_GYRO_DRV_CLK_OSCMON_TIMEOUT_TRIM_D2A_POS)

/*
 * gyro_drv_clk_oscmon_window_trim_d2a
 * [Supports Dynamic Change] Define range of frequency in which AGC can be considered in lock
 */
#define REG_IPREG_BAR_REG_142_GYRO_DRV_CLK_OSCMON_WINDOW_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_142_GYRO_DRV_CLK_OSCMON_WINDOW_TRIM_D2A_MASK     (0x03 << REG_IPREG_BAR_REG_142_GYRO_DRV_CLK_OSCMON_WINDOW_TRIM_D2A_POS)

/*
 * gyro_drv_chop_disable_trim_d2a
 * [Supports Dynamic Change] Disable integrator chopper
 */
#define REG_IPREG_BAR_REG_142_GYRO_DRV_CHOP_DISABLE_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_142_GYRO_DRV_CHOP_DISABLE_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_142_GYRO_DRV_CHOP_DISABLE_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_143
 * Register Name : IPREG_BAR_REG_143
 */

/*
 * gyro_drv_clk_chop_disable_trim_d2a
 * [Supports Dynamic Change] Chop clock disable
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_CLK_CHOP_DISABLE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_143_GYRO_DRV_CLK_CHOP_DISABLE_TRIM_D2A_MASK     0x01

/*
 * gyro_drv_clkst_2m_trim_d2a
 * [Supports Dynamic Change] Set charge pumps frequency @2MHz for ST
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_CLKST_2M_TRIM_D2A_POS      0x01
#define REG_IPREG_BAR_REG_143_GYRO_DRV_CLKST_2M_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_CLKST_2M_TRIM_D2A_POS)

/*
 * gyro_drv_disable_suppswitch_trim_d2a
 * [Supports Dynamic Change] Disable 9 to 6V transition in normal mode
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_DISABLE_SUPPSWITCH_TRIM_D2A_POS      0x02
#define REG_IPREG_BAR_REG_143_GYRO_DRV_DISABLE_SUPPSWITCH_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_DISABLE_SUPPSWITCH_TRIM_D2A_POS)

/*
 * gyro_drv_dmdcomp_hi_cur_trim_d2a
 * Restore bias PLL reference comparator bias current
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_DMDCOMP_HI_CUR_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_143_GYRO_DRV_DMDCOMP_HI_CUR_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_DMDCOMP_HI_CUR_TRIM_D2A_POS)

/*
 * gyro_drv_hvd_swap_polarity_trim_d2a
 * [Supports Dynamic Change] Swap high voltage drive polatiry
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_HVD_SWAP_POLARITY_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_143_GYRO_DRV_HVD_SWAP_POLARITY_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_HVD_SWAP_POLARITY_TRIM_D2A_POS)

/*
 * gyro_drv_overdrive_det_dis_trim_d2a
 * [Supports Dynamic Change] Disable AGC overdrive detection
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_OVERDRIVE_DET_DIS_TRIM_D2A_POS      0x05
#define REG_IPREG_BAR_REG_143_GYRO_DRV_OVERDRIVE_DET_DIS_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_OVERDRIVE_DET_DIS_TRIM_D2A_POS)

/*
 * gyro_drv_phs_swap_polarity_trim_d2a
 * [Supports Dynamic Change] Swap phase shifter polarity
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_PHS_SWAP_POLARITY_TRIM_D2A_POS      0x06
#define REG_IPREG_BAR_REG_143_GYRO_DRV_PHS_SWAP_POLARITY_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_PHS_SWAP_POLARITY_TRIM_D2A_POS)

/*
 * gyro_drv_pllref_rdy_threshold_trim_d2a
 * [Supports Dynamic Change] If 1 pllref_rdy threshold is 100mVp, if 0 is 250mVp
 */
#define REG_IPREG_BAR_REG_143_GYRO_DRV_PLLREF_RDY_THRESHOLD_TRIM_D2A_POS      0x07
#define REG_IPREG_BAR_REG_143_GYRO_DRV_PLLREF_RDY_THRESHOLD_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_143_GYRO_DRV_PLLREF_RDY_THRESHOLD_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_144
 * Register Name : IPREG_BAR_REG_144
 */

/*
 * gyro_drv_prech_threshold_340m_trim_d2a
 * [Supports Dynamic Change] Set threshold at 340mV to achieve loop engaged
 */
#define REG_IPREG_BAR_REG_144_GYRO_DRV_PRECH_THRESHOLD_340M_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_144_GYRO_DRV_PRECH_THRESHOLD_340M_TRIM_D2A_MASK     0x01



/*
 * REG_IPREG_BAR_REG_145
 * Register Name : IPREG_BAR_REG_145
 */

/*
 * gyro_bias_bg_trim_d2a
 * [Supports Dynamic Change] Brokaw bandgap trim
 */
#define REG_IPREG_BAR_REG_145_GYRO_BIAS_BG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_145_GYRO_BIAS_BG_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_146
 * Register Name : IPREG_BAR_REG_146
 */

/*
 * gyro_bias_areg_cp25v_trim_d2a
 * [Supports Dynamic Change] cp25V regulator voltage trim
 */
#define REG_IPREG_BAR_REG_146_GYRO_BIAS_AREG_CP25V_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_146_GYRO_BIAS_AREG_CP25V_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_147
 * Register Name : IPREG_BAR_REG_147
 */

/*
 * gyro_bias_areg_trim_d2a
 * [Supports Dynamic Change] avdd gyro regulator voltage trim
 */
#define REG_IPREG_BAR_REG_147_GYRO_BIAS_AREG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_147_GYRO_BIAS_AREG_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_148
 * Register Name : IPREG_BAR_REG_148
 */

/*
 * gx_sc2v_ptatblend_highfsr_trim_d2a
 * [Supports Dynamic Change] X sc2v ptatblend trim
 */
#define REG_IPREG_BAR_REG_148_GX_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_148_GX_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_MASK     0x0f

/*
 * gy_sc2v_ptatblend_highfsr_trim_d2a
 * [Supports Dynamic Change] Y sc2v ptatblend trim
 */
#define REG_IPREG_BAR_REG_148_GY_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_148_GY_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_148_GY_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_149
 * Register Name : IPREG_BAR_REG_149
 */

/*
 * gyro_bias_curv_corr_trim_d2a
 * [Supports Dynamic Change] Curvature correction trim
 */
#define REG_IPREG_BAR_REG_149_GYRO_BIAS_CURV_CORR_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_149_GYRO_BIAS_CURV_CORR_TRIM_D2A_MASK     0x0f

/*
 * gz_sc2v_ptatblend_highfsr_trim_d2a
 * [Supports Dynamic Change] Z sc2v ptatblend trim
 */
#define REG_IPREG_BAR_REG_149_GZ_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_149_GZ_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_149_GZ_SC2V_PTATBLEND_HIGHFSR_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_150
 * Register Name : IPREG_BAR_REG_150
 */

/*
 * gyro_bias_spare1_trim_d2a
 * [Supports Dynamic Change] Spare trim registers
 */
#define REG_IPREG_BAR_REG_150_GYRO_BIAS_SPARE1_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_150_GYRO_BIAS_SPARE1_TRIM_D2A_MASK     0x07

/*
 * gyro_bias_spare2_trim_d2a
 * [Supports Dynamic Change] Spare trim registers
 */
#define REG_IPREG_BAR_REG_150_GYRO_BIAS_SPARE2_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_150_GYRO_BIAS_SPARE2_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_150_GYRO_BIAS_SPARE2_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_151
 * Register Name : IPREG_BAR_REG_151
 */

/*
 * gyro_bias_spare3_trim_d2a
 * [Supports Dynamic Change] Spare trim registers
 */
#define REG_IPREG_BAR_REG_151_GYRO_BIAS_SPARE3_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_151_GYRO_BIAS_SPARE3_TRIM_D2A_MASK     0x07

/*
 * gyro_bias_dis_curv_corr_trim_d2a
 * [Supports Dynamic Change] Curvature correction disable: '1': curvature correction disabled, '0': curvature correction enabled
 */
#define REG_IPREG_BAR_REG_151_GYRO_BIAS_DIS_CURV_CORR_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_151_GYRO_BIAS_DIS_CURV_CORR_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_151_GYRO_BIAS_DIS_CURV_CORR_TRIM_D2A_POS)

/*
 * gyro_bias_psrr_trim_d2a
 * [Supports Dynamic Change] Enhanced PSRR abilitation ('1': enhanced psrr enabled, '0': enhanced psrr disabled)
 */
#define REG_IPREG_BAR_REG_151_GYRO_BIAS_PSRR_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_151_GYRO_BIAS_PSRR_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_151_GYRO_BIAS_PSRR_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_152
 * Register Name : IPREG_BAR_REG_152
 */

/*
 * spare2_trim_d2a
 * Spare
 */
#define REG_IPREG_BAR_REG_152_SPARE2_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_152_SPARE2_TRIM_D2A_MASK     0xff



/*
 * REG_IPREG_BAR_REG_153
 * Register Name : IPREG_BAR_REG_153
 */

/*
 * gyro_pll_div_trim_d2a
 * [Supports Dynamic Change] PLL feedback divider trim
 */
#define REG_IPREG_BAR_REG_153_GYRO_PLL_DIV_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_153_GYRO_PLL_DIV_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_154
 * Register Name : IPREG_BAR_REG_154
 */

/*
 * gyro_pll_nphi_trim_d2a
 * [Supports Dynamic Change] Phase trim reg for PLL feedback divider clock at fd for digital phase shifter inside gdrive
 */
#define REG_IPREG_BAR_REG_154_GYRO_PLL_NPHI_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_154_GYRO_PLL_NPHI_TRIM_D2A_MASK     0x7f



/*
 * REG_IPREG_BAR_REG_155
 * Register Name : IPREG_BAR_REG_155
 */

/*
 * gyro_pll_vfc_trim_d2a
 * [Supports Dynamic Change] PLL VCO Vctrl DAC trim
 */
#define REG_IPREG_BAR_REG_155_GYRO_PLL_VFC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_155_GYRO_PLL_VFC_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_156
 * Register Name : IPREG_BAR_REG_156
 */

/*
 * rcosc_vfc_trim_d2a
 * [Supports Dynamic Change] RCOSC VCO Vctrl DAC trim
 */
#define REG_IPREG_BAR_REG_156_RCOSC_VFC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_156_RCOSC_VFC_TRIM_D2A_MASK     0x3f



/*
 * REG_IPREG_BAR_REG_157
 * Register Name : IPREG_BAR_REG_157
 */

/*
 * pll_vref_0p7v_trim_d2a
 * [Supports Dynamic Change] PLL reference voltage trim
 */
#define REG_IPREG_BAR_REG_157_PLL_VREF_0P7V_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_157_PLL_VREF_0P7V_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_158
 * Register Name : IPREG_BAR_REG_158
 */

/*
 * rcosc_areg_trim_d2a
 * [Supports Dynamic Change] RCOSC AREG vref trim
 */
#define REG_IPREG_BAR_REG_158_RCOSC_AREG_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_158_RCOSC_AREG_TRIM_D2A_MASK     0x1f



/*
 * REG_IPREG_BAR_REG_159
 * Register Name : IPREG_BAR_REG_159
 */

/*
 * gyro_pll_rcosc_spare_trim_d2a
 * [Supports Dynamic Change] Spare trim bits
 */
#define REG_IPREG_BAR_REG_159_GYRO_PLL_RCOSC_SPARE_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_159_GYRO_PLL_RCOSC_SPARE_TRIM_D2A_MASK     0x0f

/*
 * gyro_pll_vco_trim_d2a
 * [Supports Dynamic Change] PLL VCO capacitance DAC trim (to remove process variation)
 */
#define REG_IPREG_BAR_REG_159_GYRO_PLL_VCO_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_159_GYRO_PLL_VCO_TRIM_D2A_MASK     (0x0f << REG_IPREG_BAR_REG_159_GYRO_PLL_VCO_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_160
 * Register Name : IPREG_BAR_REG_160
 */

/*
 * rcosc_vco_trim_d2a
 * [Supports Dynamic Change] RCOSC VCO capacitance DAC trim (to remove process variation)
 */
#define REG_IPREG_BAR_REG_160_RCOSC_VCO_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_160_RCOSC_VCO_TRIM_D2A_MASK     0x0f

/*
 * gyro_pll_dcc_icp_trim_d2a
 * [Supports Dynamic Change] DCC charge-pump current trim reg. (0: icp=300uA)
 */
#define REG_IPREG_BAR_REG_160_GYRO_PLL_DCC_ICP_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_160_GYRO_PLL_DCC_ICP_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_160_GYRO_PLL_DCC_ICP_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_161
 * Register Name : IPREG_BAR_REG_161
 */

/*
 * gyro_pll_icp_trim_d2a
 * [Supports Dynamic Change] PLL charge-pump current trim
 */
#define REG_IPREG_BAR_REG_161_GYRO_PLL_ICP_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_161_GYRO_PLL_ICP_TRIM_D2A_MASK     0x07

/*
 * gyro_pll_vco_tc_trim_d2a
 * [Supports Dynamic Change] PLL VCO temperature coefficient trim
 */
#define REG_IPREG_BAR_REG_161_GYRO_PLL_VCO_TC_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_161_GYRO_PLL_VCO_TC_TRIM_D2A_MASK     (0x07 << REG_IPREG_BAR_REG_161_GYRO_PLL_VCO_TC_TRIM_D2A_POS)



/*
 * REG_IPREG_BAR_REG_162
 * Register Name : IPREG_BAR_REG_162
 */

/*
 * rcosc_vco_tc_trim_d2a
 * [Supports Dynamic Change] RCOSC VCO temperature coefficient trim
 */
#define REG_IPREG_BAR_REG_162_RCOSC_VCO_TC_TRIM_D2A_POS      0x00
#define REG_IPREG_BAR_REG_162_RCOSC_VCO_TC_TRIM_D2A_MASK     0x07

/*
 * en_gyro_pll_cpreplica_trim_d2a
 * [Supports Dynamic Change] Enable PLL charge-pump replica amplifier. 0: disable replica amp / 1: enable relica amp
 */
#define REG_IPREG_BAR_REG_162_EN_GYRO_PLL_CPREPLICA_TRIM_D2A_POS      0x03
#define REG_IPREG_BAR_REG_162_EN_GYRO_PLL_CPREPLICA_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_162_EN_GYRO_PLL_CPREPLICA_TRIM_D2A_POS)

/*
 * en_gyro_pll_dcc_cpreplica_trim_d2a
 * [Supports Dynamic Change] Enable the DCC charge-pump's replica amplifier. 0:disable replica amp / 1: enable replica amp.
 */
#define REG_IPREG_BAR_REG_162_EN_GYRO_PLL_DCC_CPREPLICA_TRIM_D2A_POS      0x04
#define REG_IPREG_BAR_REG_162_EN_GYRO_PLL_DCC_CPREPLICA_TRIM_D2A_MASK     (0x01 << REG_IPREG_BAR_REG_162_EN_GYRO_PLL_DCC_CPREPLICA_TRIM_D2A_POS)


/* ---------------------------------------------------------------------------
 * register IPREG_ANA
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_ANA_REG_0
 * Register Name : IPREG_ANA_REG_0
 */

/*
 * az_negcp_valid_a2d
 * [Supports Dynamic Change] AZ Negetive CP Ready Validity
 */
#define REG_IPREG_ANA_REG_0_AZ_NEGCP_VALID_A2D_POS      0x00
#define REG_IPREG_ANA_REG_0_AZ_NEGCP_VALID_A2D_MASK     0x01



/*
 * REG_IPREG_ANA_REG_2
 * Register Name : IPREG_ANA_REG_2
 */

/*
 * gyro_drv_test_fsmread_a2d
 * [Supports Dynamic Change] Drive state machine access to internal state (read)
 */
#define REG_IPREG_ANA_REG_2_GYRO_DRV_TEST_FSMREAD_A2D_POS      0x00
#define REG_IPREG_ANA_REG_2_GYRO_DRV_TEST_FSMREAD_A2D_MASK     0xff



/*
 * REG_IPREG_ANA_REG_5
 * Register Name : IPREG_ANA_REG_5
 */

/*
 * pads_aux_cs_tp3_tp_en_d2a
 * [Supports Dynamic Change] Test point enable
 */
#define REG_IPREG_ANA_REG_5_PADS_AUX_CS_TP3_TP_EN_D2A_POS      0x00
#define REG_IPREG_ANA_REG_5_PADS_AUX_CS_TP3_TP_EN_D2A_MASK     0x01

/*
 * pads_aux_sclk_tp2_tp_en_d2a
 * [Supports Dynamic Change] Test point enable
 */
#define REG_IPREG_ANA_REG_5_PADS_AUX_SCLK_TP2_TP_EN_D2A_POS      0x01
#define REG_IPREG_ANA_REG_5_PADS_AUX_SCLK_TP2_TP_EN_D2A_MASK     (0x01 << REG_IPREG_ANA_REG_5_PADS_AUX_SCLK_TP2_TP_EN_D2A_POS)

/*
 * pads_aux_sdi_tp1_tp_en_d2a
 * [Supports Dynamic Change] Test point enable
 */
#define REG_IPREG_ANA_REG_5_PADS_AUX_SDI_TP1_TP_EN_D2A_POS      0x02
#define REG_IPREG_ANA_REG_5_PADS_AUX_SDI_TP1_TP_EN_D2A_MASK     (0x01 << REG_IPREG_ANA_REG_5_PADS_AUX_SDI_TP1_TP_EN_D2A_POS)

/*
 * pads_int1_tp0_tp_en_d2a
 * [Supports Dynamic Change] Test point enable
 */
#define REG_IPREG_ANA_REG_5_PADS_INT1_TP0_TP_EN_D2A_POS      0x03
#define REG_IPREG_ANA_REG_5_PADS_INT1_TP0_TP_EN_D2A_MASK     (0x01 << REG_IPREG_ANA_REG_5_PADS_INT1_TP0_TP_EN_D2A_POS)



/*
 * REG_IPREG_ANA_REG_6
 * Register Name : IPREG_ANA_REG_6
 */

/*
 * pd_pads_tp_avdd_b_d2a
 * [Supports Dynamic Change] used to control whether or not the test currents are delivered to pads top
 */
#define REG_IPREG_ANA_REG_6_PD_PADS_TP_AVDD_B_D2A_POS      0x00
#define REG_IPREG_ANA_REG_6_PD_PADS_TP_AVDD_B_D2A_MASK     0x01



/*
 * REG_IPREG_ANA_REG_7
 * Register Name : IPREG_ANA_REG_7
 */

/*
 * mbcore_rctrim_cnt_a2d
 * [Supports Dynamic Change] RC Trim counter
 */
#define REG_IPREG_ANA_REG_7_MBCORE_RCTRIM_CNT_A2D_POS      0x00
#define REG_IPREG_ANA_REG_7_MBCORE_RCTRIM_CNT_A2D_MASK     0xff



/*
 * REG_IPREG_ANA_REG_8
 * Register Name : IPREG_ANA_REG_8
 */

/*
 * mbcore_rctrim_cnt_a2d
 * [Supports Dynamic Change] RC Trim counter
 */
#define REG_IPREG_ANA_REG_8_MBCORE_RCTRIM_CNT_A2D_POS      0x00
#define REG_IPREG_ANA_REG_8_MBCORE_RCTRIM_CNT_A2D_MASK     0x01



/*
 * REG_IPREG_ANA_REG_9
 * Register Name : IPREG_ANA_REG_9
 */

/*
 * pd_mbcore_rctrim_b_d2a
 * [Supports Dynamic Change] rctrim enable signal
 */
#define REG_IPREG_ANA_REG_9_PD_MBCORE_RCTRIM_B_D2A_POS      0x00
#define REG_IPREG_ANA_REG_9_PD_MBCORE_RCTRIM_B_D2A_MASK     0x01



/*
 * REG_IPREG_ANA_REG_10
 * Register Name : IPREG_ANA_REG_10
 */

/*
 * en_gyro_pll_refclk_d2a
 * [Supports Dynamic Change] PLL big digital generated reference clock(not gyro drive clock) enable for test purpose
 */
#define REG_IPREG_ANA_REG_10_EN_GYRO_PLL_REFCLK_D2A_POS      0x00
#define REG_IPREG_ANA_REG_10_EN_GYRO_PLL_REFCLK_D2A_MASK     0x01



/*
 * REG_IPREG_ANA_REG_11
 * Register Name : IPREG_ANA_REG_11
 */

/*
 * gyro_sc2v_cont_mode_trim_d2a
 * [Supports Dynamic Change] continuous mode
 */
#define REG_IPREG_ANA_REG_11_GYRO_SC2V_CONT_MODE_TRIM_D2A_POS      0x00
#define REG_IPREG_ANA_REG_11_GYRO_SC2V_CONT_MODE_TRIM_D2A_MASK     0x01



/*
 * REG_ATMD_MISC1
 * Register Name : ATMD_MISC1
 */

/*
 * atmd_addr_d2d
 * Analog test mode address of each IP (to activate address a certain IP, this bus must match IP my_addr hardwired in the analog_top).
 */
#define REG_ATMD_MISC1_ATMD_ADDR_D2D_POS      0x00
#define REG_ATMD_MISC1_ATMD_ADDR_D2D_MASK     0x3f

/*
 * atmd_data_d2d
 * This bit must be set to "high" to make the DIG_TMIP_03_TS11LP_A1_FJ able to read the instructions coming from the analog test-mode buses.
 */
#define REG_ATMD_MISC1_ATMD_DATA_D2D_POS      0x06
#define REG_ATMD_MISC1_ATMD_DATA_D2D_MASK     (0x01 << REG_ATMD_MISC1_ATMD_DATA_D2D_POS)



/*
 * REG_ATMD_MISC2
 * Register Name : ATMD_MISC2
 */

/*
 * atmd_mode_d2d
 * analog test mode number.
 */
#define REG_ATMD_MISC2_ATMD_MODE_D2D_POS      0x00
#define REG_ATMD_MISC2_ATMD_MODE_D2D_MASK     0x0f

/*
 * atmd_mode_en_d2d
 * analog test mode enable.
 * 1: enable.
 * 0: disable
 */
#define REG_ATMD_MISC2_ATMD_MODE_EN_D2D_POS      0x04
#define REG_ATMD_MISC2_ATMD_MODE_EN_D2D_MASK     (0x01 << REG_ATMD_MISC2_ATMD_MODE_EN_D2D_POS)

/*
 * atmd_reset_b_d2d
 * analog test mode reset.
 * 0: reset.
 * 1: not reset.
 * Note, this is not a self-clear bit.
 */
#define REG_ATMD_MISC2_ATMD_RESET_B_D2D_POS      0x05
#define REG_ATMD_MISC2_ATMD_RESET_B_D2D_MASK     (0x01 << REG_ATMD_MISC2_ATMD_RESET_B_D2D_POS)

/*
 * atmd_strobe_d2d
 * analog test mode stobe to, pulse for analog test mode activation.
 */
#define REG_ATMD_MISC2_ATMD_STROBE_D2D_POS      0x06
#define REG_ATMD_MISC2_ATMD_STROBE_D2D_MASK     (0x01 << REG_ATMD_MISC2_ATMD_STROBE_D2D_POS)



/*
 * REG_ATMD_MISC3
 * Register Name : ATMD_MISC3
 */

/*
 * atmd_bit_d2d
 * previous IP in the daisy-chain connection
 */
#define REG_ATMD_MISC3_ATMD_BIT_D2D_POS      0x07
#define REG_ATMD_MISC3_ATMD_BIT_D2D_MASK     (0x01 << REG_ATMD_MISC3_ATMD_BIT_D2D_POS)


/* ---------------------------------------------------------------------------
 * register DREG_TOP1
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register DREG_TOP2
 * ---------------------------------------------------------------------------*/

/*
 * REG_STC_DT
 * Register Name : STC_DT
 */

/*
 * dt
 * [Supports Dynamic Change] I3C sync mode DT
 */
#define REG_STC_DT_DT_POS      0x00
#define REG_STC_DT_DT_MASK     0xff



/*
 * REG_STC_TU
 * Register Name : STC_TU
 */

/*
 * tu
 * [Supports Dynamic Change] I3C sync mode TU
 */
#define REG_STC_TU_TU_POS      0x00
#define REG_STC_TU_TU_MASK     0x03



/*
 * REG_STC_TPH_ACCEL_0
 * Register Name : STC_TPH_ACCEL_0
 */

/*
 * stc_tph_accel
 * [Supports Dynamic Change] I3C sync mode TPH for accel
 */
#define REG_STC_TPH_ACCEL_0_STC_TPH_ACCEL_POS      0x00
#define REG_STC_TPH_ACCEL_0_STC_TPH_ACCEL_MASK     0xff



/*
 * REG_STC_TPH_ACCEL_1
 * Register Name : STC_TPH_ACCEL_1
 */

/*
 * stc_tph_accel
 * [Supports Dynamic Change] I3C sync mode TPH for accel
 */
#define REG_STC_TPH_ACCEL_1_STC_TPH_ACCEL_POS      0x00
#define REG_STC_TPH_ACCEL_1_STC_TPH_ACCEL_MASK     0xff



/*
 * REG_STC_TPH_GYRO_0
 * Register Name : STC_TPH_GYRO_0
 */

/*
 * stc_tph_gyro
 * [Supports Dynamic Change] I3C sync mode TPH for gyro
 */
#define REG_STC_TPH_GYRO_0_STC_TPH_GYRO_POS      0x00
#define REG_STC_TPH_GYRO_0_STC_TPH_GYRO_MASK     0xff



/*
 * REG_STC_TPH_GYRO_1
 * Register Name : STC_TPH_GYRO_1
 */

/*
 * stc_tph_gyro
 * [Supports Dynamic Change] I3C sync mode TPH for gyro
 */
#define REG_STC_TPH_GYRO_1_STC_TPH_GYRO_POS      0x00
#define REG_STC_TPH_GYRO_1_STC_TPH_GYRO_MASK     0xff


/* ---------------------------------------------------------------------------
 * register IHREG_SREG
 * ---------------------------------------------------------------------------*/

/*
 * REG_STC_TICK_PERIOD_FULL_0
 * Register Name : STC_TICK_PERIOD_FULL_0
 */

/*
 * stc_tick_period_full
 * Actual duration of odr tick period
 */
#define REG_STC_TICK_PERIOD_FULL_0_STC_TICK_PERIOD_FULL_POS      0x00
#define REG_STC_TICK_PERIOD_FULL_0_STC_TICK_PERIOD_FULL_MASK     0xff



/*
 * REG_STC_TICK_PERIOD_FULL_1
 * Register Name : STC_TICK_PERIOD_FULL_1
 */

/*
 * stc_tick_period_full
 * Actual duration of odr tick period
 */
#define REG_STC_TICK_PERIOD_FULL_1_STC_TICK_PERIOD_FULL_POS      0x00
#define REG_STC_TICK_PERIOD_FULL_1_STC_TICK_PERIOD_FULL_MASK     0x3f


/* ---------------------------------------------------------------------------
 * register IMEM_ROM
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register IMEM_SRAM
 * ---------------------------------------------------------------------------*/

/*
 * REG_MANU_ID
 * Register Name : MANU_ID
 */

/*
 * manu_id
 * A unique value to each supplier, assigned by Customer
 */
#define REG_MANU_ID_MANU_ID_POS      0x00
#define REG_MANU_ID_MANU_ID_MASK     0xff



/*
 * REG_CHIP_ID
 * Register Name : CHIP_ID
 */

/*
 * chip_id
 * A unique value to each chip, assigned by Customer
 */
#define REG_CHIP_ID_CHIP_ID_POS      0x00
#define REG_CHIP_ID_CHIP_ID_MASK     0xff



/*
 * REG_REV_ID
 * Register Name : REV_ID
 */

/*
 * rev_id
 * A unique value to each chip revision, assigned by Customer.
 * The device should program the MEMS revision in the OTP memory.
 * [7:4]: MEMS revision
 * [3:0]: ASIC revision
 */
#define REG_REV_ID_REV_ID_POS      0x00
#define REG_REV_ID_REV_ID_MASK     0xff



/*
 * REG_ASIC_WAFER_ID
 * Register Name : ASIC_WAFER_ID
 */

/*
 * asic_wafer_id
 * Serial Number for traceability. The devices should store the value in the OTP memory.
 */
#define REG_ASIC_WAFER_ID_ASIC_WAFER_ID_POS      0x00
#define REG_ASIC_WAFER_ID_ASIC_WAFER_ID_MASK     0xff



/*
 * REG_ASIC_DIE_ID_0
 * Register Name : ASIC_DIE_ID_0
 */

/*
 * asic_die_id_1
 * Serial Number for traceability. The devices should store the value in the OTP memory.
 */
#define REG_ASIC_DIE_ID_0_ASIC_DIE_ID_1_POS      0x00
#define REG_ASIC_DIE_ID_0_ASIC_DIE_ID_1_MASK     0xff



/*
 * REG_ASIC_DIE_ID_1
 * Register Name : ASIC_DIE_ID_1
 */

/*
 * asic_die_id_2
 * Serial Number for traceability. The devices should store the value in the OTP memory.
 */
#define REG_ASIC_DIE_ID_1_ASIC_DIE_ID_2_POS      0x00
#define REG_ASIC_DIE_ID_1_ASIC_DIE_ID_2_MASK     0xff



/*
 * REG_MEMS_WAFER_ID
 * Register Name : MEMS_WAFER_ID
 */

/*
 * mems_wafer_id
 * Serial Number for traceability. The devices should store the value in the OTP memory.
 */
#define REG_MEMS_WAFER_ID_MEMS_WAFER_ID_POS      0x00
#define REG_MEMS_WAFER_ID_MEMS_WAFER_ID_MASK     0xff



/*
 * REG_MEMS_DIE_ID_0
 * Register Name : MEMS_DIE_ID_0
 */

/*
 * mems_die_id_1
 * Serial Number for traceability. The devices should store the value in the OTP memory.
 */
#define REG_MEMS_DIE_ID_0_MEMS_DIE_ID_1_POS      0x00
#define REG_MEMS_DIE_ID_0_MEMS_DIE_ID_1_MASK     0xff



/*
 * REG_MEMS_DIE_ID_1
 * Register Name : MEMS_DIE_ID_1
 */

/*
 * mems_die_id_2
 * Serial Number for traceability. The devices should store the value in the OTP memory.
 */
#define REG_MEMS_DIE_ID_1_MEMS_DIE_ID_2_POS      0x00
#define REG_MEMS_DIE_ID_1_MEMS_DIE_ID_2_MASK     0xff



/*
 * REG_SW_RCOSC_TRIM
 * Register Name : SW_RCOSC_TRIM
 */

/*
 * sw_rcosc_trim
 * Software RCOSC
 */
#define REG_SW_RCOSC_TRIM_SW_RCOSC_TRIM_POS      0x00
#define REG_SW_RCOSC_TRIM_SW_RCOSC_TRIM_MASK     0xff



/*
 * REG_SW_PLL_TRIM
 * Register Name : SW_PLL_TRIM
 */

/*
 * sw_pll_trim
 * Software PLL
 */
#define REG_SW_PLL_TRIM_SW_PLL_TRIM_POS      0x00
#define REG_SW_PLL_TRIM_SW_PLL_TRIM_MASK     0xff



/*
 * REG_SA_KEY_LAST_BYTE
 * Register Name : SA_KEY_LAST_BYTE
 */

/*
 * sa_key_last_byte
 * Last bye of authentication key copied from OTP on Power up
 */
#define REG_SA_KEY_LAST_BYTE_SA_KEY_LAST_BYTE_POS      0x00
#define REG_SA_KEY_LAST_BYTE_SA_KEY_LAST_BYTE_MASK     0xff


/* ---------------------------------------------------------------------------
 * register IPREG_FPGA
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register IPREG_OTP
 * ---------------------------------------------------------------------------*/

/*
 * REG_OTP_MRA_0
 * Register Name : OTP_MRA_0
 */

/*
 * otp_mra
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for the programming to take effect.
 */
#define REG_OTP_MRA_0_OTP_MRA_POS      0x00
#define REG_OTP_MRA_0_OTP_MRA_MASK     0xff



/*
 * REG_OTP_MRA_1
 * Register Name : OTP_MRA_1
 */

/*
 * otp_mra
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for the programming to take effect.
 */
#define REG_OTP_MRA_1_OTP_MRA_POS      0x00
#define REG_OTP_MRA_1_OTP_MRA_MASK     0xff



/*
 * REG_OTP_MRB_0
 * Register Name : OTP_MRB_0
 */

/*
 * otp_mrb
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for thje programming to take effect.
 */
#define REG_OTP_MRB_0_OTP_MRB_POS      0x00
#define REG_OTP_MRB_0_OTP_MRB_MASK     0xff



/*
 * REG_OTP_MRB_1
 * Register Name : OTP_MRB_1
 */

/*
 * otp_mrb
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for thje programming to take effect.
 */
#define REG_OTP_MRB_1_OTP_MRB_POS      0x00
#define REG_OTP_MRB_1_OTP_MRB_MASK     0xff



/*
 * REG_OTP_MR_0
 * Register Name : OTP_MR_0
 */

/*
 * otp_mr
 * otp mode register, this is a 16- bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then bit[15:8] for the programming to take effect.
 */
#define REG_OTP_MR_0_OTP_MR_POS      0x00
#define REG_OTP_MR_0_OTP_MR_MASK     0xff



/*
 * REG_OTP_MR_1
 * Register Name : OTP_MR_1
 */

/*
 * otp_mr
 * otp mode register, this is a 16- bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then bit[15:8] for the programming to take effect.
 */
#define REG_OTP_MR_1_OTP_MR_POS      0x00
#define REG_OTP_MR_1_OTP_MR_MASK     0xff



/*
 * REG_OTP_CTRL
 * Register Name : OTP_CTRL
 */

/*
 * pgm_dly_cfg
 * One of the 3 selection bits for the PGM and SOAK pulse widths (password write protected - not supported in eagle).
 */
#define REG_OTP_CTRL_PGM_DLY_CFG_POS      0x07
#define REG_OTP_CTRL_PGM_DLY_CFG_MASK     (0x01 << REG_OTP_CTRL_PGM_DLY_CFG_POS)

/*
 * otp_reset
 * Resets OTP macro when set to 1'b1. This bit is self-cleared to 0 after OTP reset is done.
 */
#define REG_OTP_CTRL_OTP_RESET_POS      0x06
#define REG_OTP_CTRL_OTP_RESET_MASK     (0x01 << REG_OTP_CTRL_OTP_RESET_POS)

/*
 * otp_stress
 * 1: will double the read pulse width, this is required by stress test.
 */
#define REG_OTP_CTRL_OTP_STRESS_POS      0x05
#define REG_OTP_CTRL_OTP_STRESS_MASK     (0x01 << REG_OTP_CTRL_OTP_STRESS_POS)

/*
 * otp_boot
 * boot, it will be allowed to access OTP macro boot block space when boot = 1’b1
 */
#define REG_OTP_CTRL_OTP_BOOT_POS      0x04
#define REG_OTP_CTRL_OTP_BOOT_MASK     (0x01 << REG_OTP_CTRL_OTP_BOOT_POS)

/*
 * otp_reload
 * LOAD_OTP, it will be trigger DMA to do re-loading when set, and it will be clear after loading done.
 */
#define REG_OTP_CTRL_OTP_RELOAD_POS      0x03
#define REG_OTP_CTRL_OTP_RELOAD_MASK     (0x01 << REG_OTP_CTRL_OTP_RELOAD_POS)

/*
 * otp_low_pwr_mode
 * Low Power Mode, controls VREF=VREFEXT switch. When LPM='0' internal power supply (IPS) is enabled and internal read reference voltage is internally generated. When LPM='1', internal power supply (IPS) is bypassed and internal read reference voltage is supplied by VREFEXT. When program or read in single-end mode, this bit should be 0.
 */
#define REG_OTP_CTRL_OTP_LOW_PWR_MODE_POS      0x02
#define REG_OTP_CTRL_OTP_LOW_PWR_MODE_MASK     (0x01 << REG_OTP_CTRL_OTP_LOW_PWR_MODE_POS)

/*
 * otp_pwr_down
 * 0: to power up OTP for read/write operation.
 * 1: to power down OTP to save power.
 * This bit is automatically set to 1 when OTP copy operation is complete.
 */
#define REG_OTP_CTRL_OTP_PWR_DOWN_POS      0x01
#define REG_OTP_CTRL_OTP_PWR_DOWN_MASK     (0x01 << REG_OTP_CTRL_OTP_PWR_DOWN_POS)

/*
 * otp_soak
 * 1: to extend program pulse from 150us to 500us.
 */
#define REG_OTP_CTRL_OTP_SOAK_POS      0x00
#define REG_OTP_CTRL_OTP_SOAK_MASK     0x01


/* ---------------------------------------------------------------------------
 * register IPREG_SYS1
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_SYS1_REG_0
 * Register Name : IPREG_SYS1_REG_0
 */

/*
 * sigp_datainj
 * signal path test mode - Data injection for Accel/Gyro GOS/ADC
 */
#define REG_IPREG_SYS1_REG_0_SIGP_DATAINJ_POS      0x00
#define REG_IPREG_SYS1_REG_0_SIGP_DATAINJ_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_1
 * Register Name : IPREG_SYS1_REG_1
 */

/*
 * sigp_datainj
 * signal path test mode - Data injection for Accel/Gyro GOS/ADC
 */
#define REG_IPREG_SYS1_REG_1_SIGP_DATAINJ_POS      0x00
#define REG_IPREG_SYS1_REG_1_SIGP_DATAINJ_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_2
 * Register Name : IPREG_SYS1_REG_2
 */

/*
 * sigp_datainj
 * signal path test mode - Data injection for Accel/Gyro GOS/ADC
 */
#define REG_IPREG_SYS1_REG_2_SIGP_DATAINJ_POS      0x00
#define REG_IPREG_SYS1_REG_2_SIGP_DATAINJ_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_4
 * Register Name : IPREG_SYS1_REG_4
 */

/*
 * sigp_datainj_tmp
 * signal path test mode - Temperature Data injection
 */
#define REG_IPREG_SYS1_REG_4_SIGP_DATAINJ_TMP_POS      0x00
#define REG_IPREG_SYS1_REG_4_SIGP_DATAINJ_TMP_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_5
 * Register Name : IPREG_SYS1_REG_5
 */

/*
 * sigp_datainj_tmp
 * signal path test mode - Temperature Data injection
 */
#define REG_IPREG_SYS1_REG_5_SIGP_DATAINJ_TMP_POS      0x00
#define REG_IPREG_SYS1_REG_5_SIGP_DATAINJ_TMP_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_6
 * Register Name : IPREG_SYS1_REG_6
 */

/*
 * gyro_x_cmos_off_hfs
 * High full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_6_GYRO_X_CMOS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_6_GYRO_X_CMOS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_7
 * Register Name : IPREG_SYS1_REG_7
 */

/*
 * gyro_x_cmos_off_hfs
 * High full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_7_GYRO_X_CMOS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_7_GYRO_X_CMOS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_8
 * Register Name : IPREG_SYS1_REG_8
 */

/*
 * gyro_x_cmos_off_lfs
 * Low full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_8_GYRO_X_CMOS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_8_GYRO_X_CMOS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_9
 * Register Name : IPREG_SYS1_REG_9
 */

/*
 * gyro_x_cmos_off_lfs
 * Low full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_9_GYRO_X_CMOS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_9_GYRO_X_CMOS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_10
 * Register Name : IPREG_SYS1_REG_10
 */

/*
 * gyro_x_mems_off_hfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_10_GYRO_X_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_10_GYRO_X_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_11
 * Register Name : IPREG_SYS1_REG_11
 */

/*
 * gyro_x_mems_off_hfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_11_GYRO_X_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_11_GYRO_X_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_12
 * Register Name : IPREG_SYS1_REG_12
 */

/*
 * gyro_x_mems_off_lfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_12_GYRO_X_MEMS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_12_GYRO_X_MEMS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_13
 * Register Name : IPREG_SYS1_REG_13
 */

/*
 * gyro_x_mems_off_lfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_13_GYRO_X_MEMS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_13_GYRO_X_MEMS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_14
 * Register Name : IPREG_SYS1_REG_14
 */

/*
 * gyro_y_cmos_off_hfs
 * High full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_14_GYRO_Y_CMOS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_14_GYRO_Y_CMOS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_15
 * Register Name : IPREG_SYS1_REG_15
 */

/*
 * gyro_y_cmos_off_hfs
 * High full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_15_GYRO_Y_CMOS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_15_GYRO_Y_CMOS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_16
 * Register Name : IPREG_SYS1_REG_16
 */

/*
 * gyro_y_cmos_off_lfs
 * Low full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_16_GYRO_Y_CMOS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_16_GYRO_Y_CMOS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_17
 * Register Name : IPREG_SYS1_REG_17
 */

/*
 * gyro_y_cmos_off_lfs
 * Low full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_17_GYRO_Y_CMOS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_17_GYRO_Y_CMOS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_18
 * Register Name : IPREG_SYS1_REG_18
 */

/*
 * gyro_y_mems_off_hfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_18_GYRO_Y_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_18_GYRO_Y_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_19
 * Register Name : IPREG_SYS1_REG_19
 */

/*
 * gyro_y_mems_off_hfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_19_GYRO_Y_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_19_GYRO_Y_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_20
 * Register Name : IPREG_SYS1_REG_20
 */

/*
 * gyro_y_mems_off_lfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_20_GYRO_Y_MEMS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_20_GYRO_Y_MEMS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_21
 * Register Name : IPREG_SYS1_REG_21
 */

/*
 * gyro_y_mems_off_lfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_21_GYRO_Y_MEMS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_21_GYRO_Y_MEMS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_22
 * Register Name : IPREG_SYS1_REG_22
 */

/*
 * gyro_z_cmos_off_hfs
 * High full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_22_GYRO_Z_CMOS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_22_GYRO_Z_CMOS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_23
 * Register Name : IPREG_SYS1_REG_23
 */

/*
 * gyro_z_cmos_off_hfs
 * High full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_23_GYRO_Z_CMOS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_23_GYRO_Z_CMOS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_24
 * Register Name : IPREG_SYS1_REG_24
 */

/*
 * gyro_z_cmos_off_lfs
 * Low full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_24_GYRO_Z_CMOS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_24_GYRO_Z_CMOS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_25
 * Register Name : IPREG_SYS1_REG_25
 */

/*
 * gyro_z_cmos_off_lfs
 * Low full scale cmos offset adjustment
 * nominal range ±274dps, 8mdps resolution
 */
#define REG_IPREG_SYS1_REG_25_GYRO_Z_CMOS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_25_GYRO_Z_CMOS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_26
 * Register Name : IPREG_SYS1_REG_26
 */

/*
 * gyro_z_mems_off_hfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_26_GYRO_Z_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_26_GYRO_Z_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_27
 * Register Name : IPREG_SYS1_REG_27
 */

/*
 * gyro_z_mems_off_hfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_27_GYRO_Z_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_27_GYRO_Z_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_28
 * Register Name : IPREG_SYS1_REG_28
 */

/*
 * gyro_z_mems_off_lfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_28_GYRO_Z_MEMS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_28_GYRO_Z_MEMS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_29
 * Register Name : IPREG_SYS1_REG_29
 */

/*
 * gyro_z_mems_off_lfs
 * offset correction range ±1000 [dps], resolution 30 [mdps]
 */
#define REG_IPREG_SYS1_REG_29_GYRO_Z_MEMS_OFF_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_29_GYRO_Z_MEMS_OFF_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_30
 * Register Name : IPREG_SYS1_REG_30
 */

/*
 * gyro_x_mems_off_lp_hfs
 * change in offset when gyro enters Low Power Mode - high full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_30_GYRO_X_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_30_GYRO_X_MEMS_OFF_LP_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_31
 * Register Name : IPREG_SYS1_REG_31
 */

/*
 * gyro_x_mems_off_lp_hfs
 * change in offset when gyro enters Low Power Mode - high full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_31_GYRO_X_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_31_GYRO_X_MEMS_OFF_LP_HFS_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_32
 * Register Name : IPREG_SYS1_REG_32
 */

/*
 * gyro_x_mems_off_lp_hfs_grp1
 * change in offset when gyro enters Low Power Mode - high full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_32_GYRO_X_MEMS_OFF_LP_HFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_32_GYRO_X_MEMS_OFF_LP_HFS_GRP1_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_33
 * Register Name : IPREG_SYS1_REG_33
 */

/*
 * gyro_x_mems_off_lp_hfs_grp1
 * change in offset when gyro enters Low Power Mode - high full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_33_GYRO_X_MEMS_OFF_LP_HFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_33_GYRO_X_MEMS_OFF_LP_HFS_GRP1_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_34
 * Register Name : IPREG_SYS1_REG_34
 */

/*
 * gyro_x_mems_off_lp_hfs_grp4
 * change in offset when gyro enters Low Power Mode - high full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_34_GYRO_X_MEMS_OFF_LP_HFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_34_GYRO_X_MEMS_OFF_LP_HFS_GRP4_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_35
 * Register Name : IPREG_SYS1_REG_35
 */

/*
 * gyro_x_mems_off_lp_hfs_grp4
 * change in offset when gyro enters Low Power Mode - high full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_35_GYRO_X_MEMS_OFF_LP_HFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_35_GYRO_X_MEMS_OFF_LP_HFS_GRP4_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_36
 * Register Name : IPREG_SYS1_REG_36
 */

/*
 * gyro_x_mems_off_lp_lfs
 * change in offset when gyro enters Low Power Mode - low full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_36_GYRO_X_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_36_GYRO_X_MEMS_OFF_LP_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_37
 * Register Name : IPREG_SYS1_REG_37
 */

/*
 * gyro_x_mems_off_lp_lfs
 * change in offset when gyro enters Low Power Mode - low full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_37_GYRO_X_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_37_GYRO_X_MEMS_OFF_LP_LFS_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_38
 * Register Name : IPREG_SYS1_REG_38
 */

/*
 * gyro_x_mems_off_lp_lfs_grp1
 * change in offset when gyro enters Low Power Mode - low full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_38_GYRO_X_MEMS_OFF_LP_LFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_38_GYRO_X_MEMS_OFF_LP_LFS_GRP1_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_39
 * Register Name : IPREG_SYS1_REG_39
 */

/*
 * gyro_x_mems_off_lp_lfs_grp1
 * change in offset when gyro enters Low Power Mode - low full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_39_GYRO_X_MEMS_OFF_LP_LFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_39_GYRO_X_MEMS_OFF_LP_LFS_GRP1_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_40
 * Register Name : IPREG_SYS1_REG_40
 */

/*
 * gyro_x_mems_off_lp_lfs_grp4
 * change in offset when gyro enters Low Power Mode - low full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_40_GYRO_X_MEMS_OFF_LP_LFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_40_GYRO_X_MEMS_OFF_LP_LFS_GRP4_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_41
 * Register Name : IPREG_SYS1_REG_41
 */

/*
 * gyro_x_mems_off_lp_lfs_grp4
 * change in offset when gyro enters Low Power Mode - low full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_41_GYRO_X_MEMS_OFF_LP_LFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_41_GYRO_X_MEMS_OFF_LP_LFS_GRP4_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_44
 * Register Name : IPREG_SYS1_REG_44
 */

/*
 * gyro_y_mems_off_lp_hfs
 * change in offset when gyro enters Low Power Mode - high full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_44_GYRO_Y_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_44_GYRO_Y_MEMS_OFF_LP_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_45
 * Register Name : IPREG_SYS1_REG_45
 */

/*
 * gyro_y_mems_off_lp_hfs
 * change in offset when gyro enters Low Power Mode - high full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_45_GYRO_Y_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_45_GYRO_Y_MEMS_OFF_LP_HFS_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_46
 * Register Name : IPREG_SYS1_REG_46
 */

/*
 * gyro_y_mems_off_lp_hfs_grp1
 * change in offset when gyro enters Low Power Mode - high full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_46_GYRO_Y_MEMS_OFF_LP_HFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_46_GYRO_Y_MEMS_OFF_LP_HFS_GRP1_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_47
 * Register Name : IPREG_SYS1_REG_47
 */

/*
 * gyro_y_mems_off_lp_hfs_grp1
 * change in offset when gyro enters Low Power Mode - high full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_47_GYRO_Y_MEMS_OFF_LP_HFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_47_GYRO_Y_MEMS_OFF_LP_HFS_GRP1_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_48
 * Register Name : IPREG_SYS1_REG_48
 */

/*
 * gyro_y_mems_off_lp_hfs_grp4
 * change in offset when gyro enters Low Power Mode - high full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_48_GYRO_Y_MEMS_OFF_LP_HFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_48_GYRO_Y_MEMS_OFF_LP_HFS_GRP4_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_49
 * Register Name : IPREG_SYS1_REG_49
 */

/*
 * gyro_y_mems_off_lp_hfs_grp4
 * change in offset when gyro enters Low Power Mode - high full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_49_GYRO_Y_MEMS_OFF_LP_HFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_49_GYRO_Y_MEMS_OFF_LP_HFS_GRP4_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_50
 * Register Name : IPREG_SYS1_REG_50
 */

/*
 * gyro_y_mems_off_lp_lfs
 * change in offset when gyro enters Low Power Mode - low full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_50_GYRO_Y_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_50_GYRO_Y_MEMS_OFF_LP_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_51
 * Register Name : IPREG_SYS1_REG_51
 */

/*
 * gyro_y_mems_off_lp_lfs
 * change in offset when gyro enters Low Power Mode - low full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_51_GYRO_Y_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_51_GYRO_Y_MEMS_OFF_LP_LFS_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_52
 * Register Name : IPREG_SYS1_REG_52
 */

/*
 * gyro_y_mems_off_lp_lfs_grp1
 * change in offset when gyro enters Low Power Mode - low full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_52_GYRO_Y_MEMS_OFF_LP_LFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_52_GYRO_Y_MEMS_OFF_LP_LFS_GRP1_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_53
 * Register Name : IPREG_SYS1_REG_53
 */

/*
 * gyro_y_mems_off_lp_lfs_grp1
 * change in offset when gyro enters Low Power Mode - low full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_53_GYRO_Y_MEMS_OFF_LP_LFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_53_GYRO_Y_MEMS_OFF_LP_LFS_GRP1_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_54
 * Register Name : IPREG_SYS1_REG_54
 */

/*
 * gyro_y_mems_off_lp_lfs_grp4
 * change in offset when gyro enters Low Power Mode - low full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_54_GYRO_Y_MEMS_OFF_LP_LFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_54_GYRO_Y_MEMS_OFF_LP_LFS_GRP4_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_55
 * Register Name : IPREG_SYS1_REG_55
 */

/*
 * gyro_y_mems_off_lp_lfs_grp4
 * change in offset when gyro enters Low Power Mode - low full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_55_GYRO_Y_MEMS_OFF_LP_LFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_55_GYRO_Y_MEMS_OFF_LP_LFS_GRP4_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_58
 * Register Name : IPREG_SYS1_REG_58
 */

/*
 * gyro_z_mems_off_lp_hfs
 * change in offset when gyro enters Low Power Mode - high full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_58_GYRO_Z_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_58_GYRO_Z_MEMS_OFF_LP_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_59
 * Register Name : IPREG_SYS1_REG_59
 */

/*
 * gyro_z_mems_off_lp_hfs
 * change in offset when gyro enters Low Power Mode - high full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_59_GYRO_Z_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_59_GYRO_Z_MEMS_OFF_LP_HFS_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_60
 * Register Name : IPREG_SYS1_REG_60
 */

/*
 * gyro_z_mems_off_lp_hfs_grp1
 * change in offset when gyro enters Low Power Mode - high full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_60_GYRO_Z_MEMS_OFF_LP_HFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_60_GYRO_Z_MEMS_OFF_LP_HFS_GRP1_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_61
 * Register Name : IPREG_SYS1_REG_61
 */

/*
 * gyro_z_mems_off_lp_hfs_grp1
 * change in offset when gyro enters Low Power Mode - high full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_61_GYRO_Z_MEMS_OFF_LP_HFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_61_GYRO_Z_MEMS_OFF_LP_HFS_GRP1_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_62
 * Register Name : IPREG_SYS1_REG_62
 */

/*
 * gyro_z_mems_off_lp_hfs_grp4
 * change in offset when gyro enters Low Power Mode - high full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_62_GYRO_Z_MEMS_OFF_LP_HFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_62_GYRO_Z_MEMS_OFF_LP_HFS_GRP4_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_63
 * Register Name : IPREG_SYS1_REG_63
 */

/*
 * gyro_z_mems_off_lp_hfs_grp4
 * change in offset when gyro enters Low Power Mode - high full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_63_GYRO_Z_MEMS_OFF_LP_HFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_63_GYRO_Z_MEMS_OFF_LP_HFS_GRP4_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_64
 * Register Name : IPREG_SYS1_REG_64
 */

/*
 * gyro_z_mems_off_lp_lfs
 * change in offset when gyro enters Low Power Mode - low full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_64_GYRO_Z_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_64_GYRO_Z_MEMS_OFF_LP_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_65
 * Register Name : IPREG_SYS1_REG_65
 */

/*
 * gyro_z_mems_off_lp_lfs
 * change in offset when gyro enters Low Power Mode - low full scale; Navg>=16. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_65_GYRO_Z_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_65_GYRO_Z_MEMS_OFF_LP_LFS_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_66
 * Register Name : IPREG_SYS1_REG_66
 */

/*
 * gyro_z_mems_off_lp_lfs_grp1
 * change in offset when gyro enters Low Power Mode - low full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_66_GYRO_Z_MEMS_OFF_LP_LFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_66_GYRO_Z_MEMS_OFF_LP_LFS_GRP1_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_67
 * Register Name : IPREG_SYS1_REG_67
 */

/*
 * gyro_z_mems_off_lp_lfs_grp1
 * change in offset when gyro enters Low Power Mode - low full scale; Navg=1,2. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_67_GYRO_Z_MEMS_OFF_LP_LFS_GRP1_POS      0x00
#define REG_IPREG_SYS1_REG_67_GYRO_Z_MEMS_OFF_LP_LFS_GRP1_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_68
 * Register Name : IPREG_SYS1_REG_68
 */

/*
 * gyro_z_mems_off_lp_lfs_grp4
 * change in offset when gyro enters Low Power Mode - low full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_68_GYRO_Z_MEMS_OFF_LP_LFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_68_GYRO_Z_MEMS_OFF_LP_LFS_GRP4_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_69
 * Register Name : IPREG_SYS1_REG_69
 */

/*
 * gyro_z_mems_off_lp_lfs_grp4
 * change in offset when gyro enters Low Power Mode - low full scale; 4<=navg<=11. Max value is +/-62.5 dps, resolution is 1/128 dps
 */
#define REG_IPREG_SYS1_REG_69_GYRO_Z_MEMS_OFF_LP_LFS_GRP4_POS      0x00
#define REG_IPREG_SYS1_REG_69_GYRO_Z_MEMS_OFF_LP_LFS_GRP4_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_72
 * Register Name : IPREG_SYS1_REG_72
 */

/*
 * gyro_x_gain_afsr_hfs
 * High full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_72_GYRO_X_GAIN_AFSR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_72_GYRO_X_GAIN_AFSR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_73
 * Register Name : IPREG_SYS1_REG_73
 */

/*
 * gyro_x_gain_afsr_hfs
 * High full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_73_GYRO_X_GAIN_AFSR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_73_GYRO_X_GAIN_AFSR_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_74
 * Register Name : IPREG_SYS1_REG_74
 */

/*
 * gyro_x_gain_afsr_lfs
 * 500 full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_74_GYRO_X_GAIN_AFSR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_74_GYRO_X_GAIN_AFSR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_75
 * Register Name : IPREG_SYS1_REG_75
 */

/*
 * gyro_x_gain_afsr_lfs
 * 500 full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_75_GYRO_X_GAIN_AFSR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_75_GYRO_X_GAIN_AFSR_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_76
 * Register Name : IPREG_SYS1_REG_76
 */

/*
 * gyro_x_mems_offtca_hfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_76_GYRO_X_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_76_GYRO_X_MEMS_OFFTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_77
 * Register Name : IPREG_SYS1_REG_77
 */

/*
 * gyro_x_mems_offtca_hfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_77_GYRO_X_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_77_GYRO_X_MEMS_OFFTCA_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_78
 * Register Name : IPREG_SYS1_REG_78
 */

/*
 * gyro_x_mems_offtca_lfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_78_GYRO_X_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_78_GYRO_X_MEMS_OFFTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_79
 * Register Name : IPREG_SYS1_REG_79
 */

/*
 * gyro_x_mems_offtca_lfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_79_GYRO_X_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_79_GYRO_X_MEMS_OFFTCA_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_80
 * Register Name : IPREG_SYS1_REG_80
 */

/*
 * gyro_x_mems_offtcb_hfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_80_GYRO_X_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_80_GYRO_X_MEMS_OFFTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_81
 * Register Name : IPREG_SYS1_REG_81
 */

/*
 * gyro_x_mems_offtcb_hfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_81_GYRO_X_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_81_GYRO_X_MEMS_OFFTCB_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_82
 * Register Name : IPREG_SYS1_REG_82
 */

/*
 * gyro_x_mems_offtcb_lfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_82_GYRO_X_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_82_GYRO_X_MEMS_OFFTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_83
 * Register Name : IPREG_SYS1_REG_83
 */

/*
 * gyro_x_mems_offtcb_lfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_83_GYRO_X_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_83_GYRO_X_MEMS_OFFTCB_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_84
 * Register Name : IPREG_SYS1_REG_84
 */

/*
 * gyro_y_gain_afsr_hfs
 * High full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_84_GYRO_Y_GAIN_AFSR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_84_GYRO_Y_GAIN_AFSR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_85
 * Register Name : IPREG_SYS1_REG_85
 */

/*
 * gyro_y_gain_afsr_hfs
 * High full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_85_GYRO_Y_GAIN_AFSR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_85_GYRO_Y_GAIN_AFSR_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_86
 * Register Name : IPREG_SYS1_REG_86
 */

/*
 * gyro_y_gain_afsr_lfs
 * 500 full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_86_GYRO_Y_GAIN_AFSR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_86_GYRO_Y_GAIN_AFSR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_87
 * Register Name : IPREG_SYS1_REG_87
 */

/*
 * gyro_y_gain_afsr_lfs
 * 500 full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_87_GYRO_Y_GAIN_AFSR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_87_GYRO_Y_GAIN_AFSR_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_88
 * Register Name : IPREG_SYS1_REG_88
 */

/*
 * gyro_y_mems_offtca_hfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_88_GYRO_Y_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_88_GYRO_Y_MEMS_OFFTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_89
 * Register Name : IPREG_SYS1_REG_89
 */

/*
 * gyro_y_mems_offtca_hfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_89_GYRO_Y_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_89_GYRO_Y_MEMS_OFFTCA_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_90
 * Register Name : IPREG_SYS1_REG_90
 */

/*
 * gyro_y_mems_offtca_lfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_90_GYRO_Y_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_90_GYRO_Y_MEMS_OFFTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_91
 * Register Name : IPREG_SYS1_REG_91
 */

/*
 * gyro_y_mems_offtca_lfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_91_GYRO_Y_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_91_GYRO_Y_MEMS_OFFTCA_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_92
 * Register Name : IPREG_SYS1_REG_92
 */

/*
 * gyro_y_mems_offtcb_hfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_92_GYRO_Y_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_92_GYRO_Y_MEMS_OFFTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_93
 * Register Name : IPREG_SYS1_REG_93
 */

/*
 * gyro_y_mems_offtcb_hfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_93_GYRO_Y_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_93_GYRO_Y_MEMS_OFFTCB_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_94
 * Register Name : IPREG_SYS1_REG_94
 */

/*
 * gyro_y_mems_offtcb_lfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_94_GYRO_Y_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_94_GYRO_Y_MEMS_OFFTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_95
 * Register Name : IPREG_SYS1_REG_95
 */

/*
 * gyro_y_mems_offtcb_lfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_95_GYRO_Y_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_95_GYRO_Y_MEMS_OFFTCB_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_96
 * Register Name : IPREG_SYS1_REG_96
 */

/*
 * gyro_z_gain_afsr_hfs
 * High full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_96_GYRO_Z_GAIN_AFSR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_96_GYRO_Z_GAIN_AFSR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_97
 * Register Name : IPREG_SYS1_REG_97
 */

/*
 * gyro_z_gain_afsr_hfs
 * High full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_97_GYRO_Z_GAIN_AFSR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_97_GYRO_Z_GAIN_AFSR_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_98
 * Register Name : IPREG_SYS1_REG_98
 */

/*
 * gyro_z_gain_afsr_lfs
 * 500 full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_98_GYRO_Z_GAIN_AFSR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_98_GYRO_Z_GAIN_AFSR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_99
 * Register Name : IPREG_SYS1_REG_99
 */

/*
 * gyro_z_gain_afsr_lfs
 * 500 full scale gain adjustment u13.11
 */
#define REG_IPREG_SYS1_REG_99_GYRO_Z_GAIN_AFSR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_99_GYRO_Z_GAIN_AFSR_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_100
 * Register Name : IPREG_SYS1_REG_100
 */

/*
 * gyro_z_mems_offtca_hfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_100_GYRO_Z_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_100_GYRO_Z_MEMS_OFFTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_101
 * Register Name : IPREG_SYS1_REG_101
 */

/*
 * gyro_z_mems_offtca_hfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_101_GYRO_Z_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_101_GYRO_Z_MEMS_OFFTCA_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_102
 * Register Name : IPREG_SYS1_REG_102
 */

/*
 * gyro_z_mems_offtca_lfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_102_GYRO_Z_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_102_GYRO_Z_MEMS_OFFTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_103
 * Register Name : IPREG_SYS1_REG_103
 */

/*
 * gyro_z_mems_offtca_lfs
 * offset TC correction, (setting A). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T<Tmid
 */
#define REG_IPREG_SYS1_REG_103_GYRO_Z_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_103_GYRO_Z_MEMS_OFFTCA_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_104
 * Register Name : IPREG_SYS1_REG_104
 */

/*
 * gyro_z_mems_offtcb_hfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_104_GYRO_Z_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_104_GYRO_Z_MEMS_OFFTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_105
 * Register Name : IPREG_SYS1_REG_105
 */

/*
 * gyro_z_mems_offtcb_hfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_105_GYRO_Z_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_105_GYRO_Z_MEMS_OFFTCB_HFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_106
 * Register Name : IPREG_SYS1_REG_106
 */

/*
 * gyro_z_mems_offtcb_lfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_106_GYRO_Z_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_106_GYRO_Z_MEMS_OFFTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_107
 * Register Name : IPREG_SYS1_REG_107
 */

/*
 * gyro_z_mems_offtcb_lfs
 * offset TC correction, (setting B). range ±2 [dps/C], resolution 0.5 [mdps/C]; to be used for T>Tmid
 */
#define REG_IPREG_SYS1_REG_107_GYRO_Z_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_107_GYRO_Z_MEMS_OFFTCB_LFS_MASK     0x1f



/*
 * REG_IPREG_SYS1_REG_108
 * Register Name : IPREG_SYS1_REG_108
 */

/*
 * gyro_x_gain
 * GOS gyro sensitivity calibration Max allowed gain is 2 with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_108_GYRO_X_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_108_GYRO_X_GAIN_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_109
 * Register Name : IPREG_SYS1_REG_109
 */

/*
 * gyro_x_gain
 * GOS gyro sensitivity calibration Max allowed gain is 2 with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_109_GYRO_X_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_109_GYRO_X_GAIN_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_110
 * Register Name : IPREG_SYS1_REG_110
 */

/*
 * gyro_x_mems_offtca_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_110_GYRO_X_MEMS_OFFTCA_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_110_GYRO_X_MEMS_OFFTCA_SQR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_111
 * Register Name : IPREG_SYS1_REG_111
 */

/*
 * gyro_x_mems_offtca_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_111_GYRO_X_MEMS_OFFTCA_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_111_GYRO_X_MEMS_OFFTCA_SQR_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_112
 * Register Name : IPREG_SYS1_REG_112
 */

/*
 * gyro_x_mems_offtca_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_112_GYRO_X_MEMS_OFFTCA_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_112_GYRO_X_MEMS_OFFTCA_SQR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_113
 * Register Name : IPREG_SYS1_REG_113
 */

/*
 * gyro_x_mems_offtca_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_113_GYRO_X_MEMS_OFFTCA_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_113_GYRO_X_MEMS_OFFTCA_SQR_LFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_114
 * Register Name : IPREG_SYS1_REG_114
 */

/*
 * gyro_x_mems_offtcb_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_114_GYRO_X_MEMS_OFFTCB_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_114_GYRO_X_MEMS_OFFTCB_SQR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_115
 * Register Name : IPREG_SYS1_REG_115
 */

/*
 * gyro_x_mems_offtcb_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_115_GYRO_X_MEMS_OFFTCB_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_115_GYRO_X_MEMS_OFFTCB_SQR_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_116
 * Register Name : IPREG_SYS1_REG_116
 */

/*
 * gyro_x_mems_offtcb_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_116_GYRO_X_MEMS_OFFTCB_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_116_GYRO_X_MEMS_OFFTCB_SQR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_117
 * Register Name : IPREG_SYS1_REG_117
 */

/*
 * gyro_x_mems_offtcb_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_117_GYRO_X_MEMS_OFFTCB_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_117_GYRO_X_MEMS_OFFTCB_SQR_LFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_120
 * Register Name : IPREG_SYS1_REG_120
 */

/*
 * gyro_y_gain
 * GOS gyro sensitivity calibration Max allowed gain is 2 with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_120_GYRO_Y_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_120_GYRO_Y_GAIN_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_121
 * Register Name : IPREG_SYS1_REG_121
 */

/*
 * gyro_y_gain
 * GOS gyro sensitivity calibration Max allowed gain is 2 with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_121_GYRO_Y_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_121_GYRO_Y_GAIN_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_122
 * Register Name : IPREG_SYS1_REG_122
 */

/*
 * gyro_y_mems_offtca_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_122_GYRO_Y_MEMS_OFFTCA_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_122_GYRO_Y_MEMS_OFFTCA_SQR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_123
 * Register Name : IPREG_SYS1_REG_123
 */

/*
 * gyro_y_mems_offtca_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_123_GYRO_Y_MEMS_OFFTCA_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_123_GYRO_Y_MEMS_OFFTCA_SQR_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_124
 * Register Name : IPREG_SYS1_REG_124
 */

/*
 * gyro_y_mems_offtca_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_124_GYRO_Y_MEMS_OFFTCA_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_124_GYRO_Y_MEMS_OFFTCA_SQR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_125
 * Register Name : IPREG_SYS1_REG_125
 */

/*
 * gyro_y_mems_offtca_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_125_GYRO_Y_MEMS_OFFTCA_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_125_GYRO_Y_MEMS_OFFTCA_SQR_LFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_126
 * Register Name : IPREG_SYS1_REG_126
 */

/*
 * gyro_y_mems_offtcb_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_126_GYRO_Y_MEMS_OFFTCB_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_126_GYRO_Y_MEMS_OFFTCB_SQR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_127
 * Register Name : IPREG_SYS1_REG_127
 */

/*
 * gyro_y_mems_offtcb_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_127_GYRO_Y_MEMS_OFFTCB_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_127_GYRO_Y_MEMS_OFFTCB_SQR_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_128
 * Register Name : IPREG_SYS1_REG_128
 */

/*
 * gyro_y_mems_offtcb_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_128_GYRO_Y_MEMS_OFFTCB_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_128_GYRO_Y_MEMS_OFFTCB_SQR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_129
 * Register Name : IPREG_SYS1_REG_129
 */

/*
 * gyro_y_mems_offtcb_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_129_GYRO_Y_MEMS_OFFTCB_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_129_GYRO_Y_MEMS_OFFTCB_SQR_LFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_132
 * Register Name : IPREG_SYS1_REG_132
 */

/*
 * gyro_z_gain
 * GOS gyro sensitivity calibration Max allowed gain is 2 with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_132_GYRO_Z_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_132_GYRO_Z_GAIN_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_133
 * Register Name : IPREG_SYS1_REG_133
 */

/*
 * gyro_z_gain
 * GOS gyro sensitivity calibration Max allowed gain is 2 with resolution of 0.05%
 */
#define REG_IPREG_SYS1_REG_133_GYRO_Z_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_133_GYRO_Z_GAIN_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_134
 * Register Name : IPREG_SYS1_REG_134
 */

/*
 * gyro_z_mems_offtca_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_134_GYRO_Z_MEMS_OFFTCA_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_134_GYRO_Z_MEMS_OFFTCA_SQR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_135
 * Register Name : IPREG_SYS1_REG_135
 */

/*
 * gyro_z_mems_offtca_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_135_GYRO_Z_MEMS_OFFTCA_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_135_GYRO_Z_MEMS_OFFTCA_SQR_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_136
 * Register Name : IPREG_SYS1_REG_136
 */

/*
 * gyro_z_mems_offtca_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_136_GYRO_Z_MEMS_OFFTCA_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_136_GYRO_Z_MEMS_OFFTCA_SQR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_137
 * Register Name : IPREG_SYS1_REG_137
 */

/*
 * gyro_z_mems_offtca_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_137_GYRO_Z_MEMS_OFFTCA_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_137_GYRO_Z_MEMS_OFFTCA_SQR_LFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_138
 * Register Name : IPREG_SYS1_REG_138
 */

/*
 * gyro_z_mems_offtcb_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_138_GYRO_Z_MEMS_OFFTCB_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_138_GYRO_Z_MEMS_OFFTCB_SQR_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_139
 * Register Name : IPREG_SYS1_REG_139
 */

/*
 * gyro_z_mems_offtcb_sqr_hfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_139_GYRO_Z_MEMS_OFFTCB_SQR_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_139_GYRO_Z_MEMS_OFFTCB_SQR_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_140
 * Register Name : IPREG_SYS1_REG_140
 */

/*
 * gyro_z_mems_offtcb_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_140_GYRO_Z_MEMS_OFFTCB_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_140_GYRO_Z_MEMS_OFFTCB_SQR_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_141
 * Register Name : IPREG_SYS1_REG_141
 */

/*
 * gyro_z_mems_offtcb_sqr_lfs
 * second order temperature compensation O2;
 * range ±0.25 [dps/C2], resolution 0.12 [mdps/C2]
 */
#define REG_IPREG_SYS1_REG_141_GYRO_Z_MEMS_OFFTCB_SQR_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_141_GYRO_Z_MEMS_OFFTCB_SQR_LFS_MASK     0x0f



/*
 * REG_IPREG_SYS1_REG_144
 * Register Name : IPREG_SYS1_REG_144
 */

/*
 * gyro_x_gaintca_hfs
 * Gyro gain TC slope (setting A)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting A is used when T<Tmid
 */
#define REG_IPREG_SYS1_REG_144_GYRO_X_GAINTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_144_GYRO_X_GAINTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_145
 * Register Name : IPREG_SYS1_REG_145
 */

/*
 * gyro_x_gaintca_lfs
 * Gyro gain TC slope (setting A)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting A is used when T<Tmid
 */
#define REG_IPREG_SYS1_REG_145_GYRO_X_GAINTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_145_GYRO_X_GAINTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_146
 * Register Name : IPREG_SYS1_REG_146
 */

/*
 * gyro_x_gaintcb_hfs
 * Gyro gain TC slope (setting B)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting B is applied when T>Tmid
 */
#define REG_IPREG_SYS1_REG_146_GYRO_X_GAINTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_146_GYRO_X_GAINTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_147
 * Register Name : IPREG_SYS1_REG_147
 */

/*
 * gyro_x_gaintcb_lfs
 * Gyro gain TC slope (setting B)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting B is applied when T>Tmid
 */
#define REG_IPREG_SYS1_REG_147_GYRO_X_GAINTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_147_GYRO_X_GAINTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_148
 * Register Name : IPREG_SYS1_REG_148
 */

/*
 * gyro_y_gaintca_hfs
 * Gyro gain TC slope (setting A)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting A is used when T<Tmid
 */
#define REG_IPREG_SYS1_REG_148_GYRO_Y_GAINTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_148_GYRO_Y_GAINTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_149
 * Register Name : IPREG_SYS1_REG_149
 */

/*
 * gyro_y_gaintca_lfs
 * Gyro gain TC slope (setting A)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting A is used when T<Tmid
 */
#define REG_IPREG_SYS1_REG_149_GYRO_Y_GAINTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_149_GYRO_Y_GAINTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_150
 * Register Name : IPREG_SYS1_REG_150
 */

/*
 * gyro_y_gaintcb_hfs
 * Gyro gain TC slope (setting B)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting B is applied when T>Tmid
 */
#define REG_IPREG_SYS1_REG_150_GYRO_Y_GAINTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_150_GYRO_Y_GAINTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_151
 * Register Name : IPREG_SYS1_REG_151
 */

/*
 * gyro_y_gaintcb_lfs
 * Gyro gain TC slope (setting B)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting B is applied when T>Tmid
 */
#define REG_IPREG_SYS1_REG_151_GYRO_Y_GAINTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_151_GYRO_Y_GAINTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_152
 * Register Name : IPREG_SYS1_REG_152
 */

/*
 * gyro_z_gaintca_hfs
 * Gyro gain TC slope (setting A)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting A is used when T<Tmid
 */
#define REG_IPREG_SYS1_REG_152_GYRO_Z_GAINTCA_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_152_GYRO_Z_GAINTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_153
 * Register Name : IPREG_SYS1_REG_153
 */

/*
 * gyro_z_gaintca_lfs
 * Gyro gain TC slope (setting A)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting A is used when T<Tmid
 */
#define REG_IPREG_SYS1_REG_153_GYRO_Z_GAINTCA_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_153_GYRO_Z_GAINTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_154
 * Register Name : IPREG_SYS1_REG_154
 */

/*
 * gyro_z_gaintcb_hfs
 * Gyro gain TC slope (setting B)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting B is applied when T>Tmid
 */
#define REG_IPREG_SYS1_REG_154_GYRO_Z_GAINTCB_HFS_POS      0x00
#define REG_IPREG_SYS1_REG_154_GYRO_Z_GAINTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_155
 * Register Name : IPREG_SYS1_REG_155
 */

/*
 * gyro_z_gaintcb_lfs
 * Gyro gain TC slope (setting B)  Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K; setting B is applied when T>Tmid
 */
#define REG_IPREG_SYS1_REG_155_GYRO_Z_GAINTCB_LFS_POS      0x00
#define REG_IPREG_SYS1_REG_155_GYRO_Z_GAINTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS1_REG_156
 * Register Name : IPREG_SYS1_REG_156
 */

/*
 * gyro_x_ma_nf_ctrl
 * controls enabling and notch zero location - see table
 */
#define REG_IPREG_SYS1_REG_156_GYRO_X_MA_NF_CTRL_POS      0x00
#define REG_IPREG_SYS1_REG_156_GYRO_X_MA_NF_CTRL_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_157
 * Register Name : IPREG_SYS1_REG_157
 */

/*
 * gyro_y_ma_nf_ctrl
 * controls enabling and notch zero location - see table
 */
#define REG_IPREG_SYS1_REG_157_GYRO_Y_MA_NF_CTRL_POS      0x00
#define REG_IPREG_SYS1_REG_157_GYRO_Y_MA_NF_CTRL_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_158
 * Register Name : IPREG_SYS1_REG_158
 */

/*
 * gyro_z_ma_nf_ctrl
 * controls enabling and notch zero location - see table
 */
#define REG_IPREG_SYS1_REG_158_GYRO_Z_MA_NF_CTRL_POS      0x00
#define REG_IPREG_SYS1_REG_158_GYRO_Z_MA_NF_CTRL_MASK     0x3f



/*
 * REG_IPREG_SYS1_REG_159
 * Register Name : IPREG_SYS1_REG_159
 */

/*
 * gyro_x_afsr_th_high
 * AFSR thrshold high; th_high < th_low
 */
#define REG_IPREG_SYS1_REG_159_GYRO_X_AFSR_TH_HIGH_POS      0x00
#define REG_IPREG_SYS1_REG_159_GYRO_X_AFSR_TH_HIGH_MASK     0x0f

/*
 * gyro_x_afsr_th_low
 * AFSR thrshold low; dps equivalent [64:64:512, 640:128:1024]
 */
#define REG_IPREG_SYS1_REG_159_GYRO_X_AFSR_TH_LOW_POS      0x04
#define REG_IPREG_SYS1_REG_159_GYRO_X_AFSR_TH_LOW_MASK     (0x0f << REG_IPREG_SYS1_REG_159_GYRO_X_AFSR_TH_LOW_POS)



/*
 * REG_IPREG_SYS1_REG_160
 * Register Name : IPREG_SYS1_REG_160
 */

/*
 * gyro_x_tmid_gain
 * Temperature offset for dual slope mems gain-tc in 12 degreeC steps
 * -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60
 */
#define REG_IPREG_SYS1_REG_160_GYRO_X_TMID_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_160_GYRO_X_TMID_GAIN_MASK     0x0f

/*
 * gyro_x_tmid_off
 * Temperature inflection point (in deg C)  for dual slope mems offset-tc in 12  steps, -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60
 */
#define REG_IPREG_SYS1_REG_160_GYRO_X_TMID_OFF_POS      0x04
#define REG_IPREG_SYS1_REG_160_GYRO_X_TMID_OFF_MASK     (0x0f << REG_IPREG_SYS1_REG_160_GYRO_X_TMID_OFF_POS)



/*
 * REG_IPREG_SYS1_REG_161
 * Register Name : IPREG_SYS1_REG_161
 */

/*
 * gyro_y_afsr_th_high
 * AFSR thrshold high; th_high < th_low
 */
#define REG_IPREG_SYS1_REG_161_GYRO_Y_AFSR_TH_HIGH_POS      0x00
#define REG_IPREG_SYS1_REG_161_GYRO_Y_AFSR_TH_HIGH_MASK     0x0f

/*
 * gyro_y_afsr_th_low
 * AFSR thrshold low; dps equivalent [64:64:512, 640:128:1024]
 */
#define REG_IPREG_SYS1_REG_161_GYRO_Y_AFSR_TH_LOW_POS      0x04
#define REG_IPREG_SYS1_REG_161_GYRO_Y_AFSR_TH_LOW_MASK     (0x0f << REG_IPREG_SYS1_REG_161_GYRO_Y_AFSR_TH_LOW_POS)



/*
 * REG_IPREG_SYS1_REG_162
 * Register Name : IPREG_SYS1_REG_162
 */

/*
 * gyro_y_tmid_gain
 * Temperature offset for dual slope mems gain-tc in 12 degreeC steps
 * -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60
 */
#define REG_IPREG_SYS1_REG_162_GYRO_Y_TMID_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_162_GYRO_Y_TMID_GAIN_MASK     0x0f

/*
 * gyro_y_tmid_off
 * Temperature inflection point (in deg C)  for dual slope mems offset-tc in 12  steps, -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60
 */
#define REG_IPREG_SYS1_REG_162_GYRO_Y_TMID_OFF_POS      0x04
#define REG_IPREG_SYS1_REG_162_GYRO_Y_TMID_OFF_MASK     (0x0f << REG_IPREG_SYS1_REG_162_GYRO_Y_TMID_OFF_POS)



/*
 * REG_IPREG_SYS1_REG_163
 * Register Name : IPREG_SYS1_REG_163
 */

/*
 * gyro_z_afsr_th_high
 * AFSR thrshold high; th_high < th_low
 */
#define REG_IPREG_SYS1_REG_163_GYRO_Z_AFSR_TH_HIGH_POS      0x00
#define REG_IPREG_SYS1_REG_163_GYRO_Z_AFSR_TH_HIGH_MASK     0x0f

/*
 * gyro_z_afsr_th_low
 * AFSR thrshold low; dps equivalent [64:64:512, 640:128:1024]
 */
#define REG_IPREG_SYS1_REG_163_GYRO_Z_AFSR_TH_LOW_POS      0x04
#define REG_IPREG_SYS1_REG_163_GYRO_Z_AFSR_TH_LOW_MASK     (0x0f << REG_IPREG_SYS1_REG_163_GYRO_Z_AFSR_TH_LOW_POS)



/*
 * REG_IPREG_SYS1_REG_164
 * Register Name : IPREG_SYS1_REG_164
 */

/*
 * gyro_z_tmid_gain
 * Temperature offset for dual slope mems gain-tc in 12 degreeC steps
 * -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60
 */
#define REG_IPREG_SYS1_REG_164_GYRO_Z_TMID_GAIN_POS      0x00
#define REG_IPREG_SYS1_REG_164_GYRO_Z_TMID_GAIN_MASK     0x0f

/*
 * gyro_z_tmid_off
 * Temperature inflection point (in deg C)  for dual slope mems offset-tc in 12  steps, -28, -20, -12, -4, 4, 12, 20, 28, 36, 44, 52, 60
 */
#define REG_IPREG_SYS1_REG_164_GYRO_Z_TMID_OFF_POS      0x04
#define REG_IPREG_SYS1_REG_164_GYRO_Z_TMID_OFF_MASK     (0x0f << REG_IPREG_SYS1_REG_164_GYRO_Z_TMID_OFF_POS)



/*
 * REG_IPREG_SYS1_REG_165
 * Register Name : IPREG_SYS1_REG_165
 */

/*
 * gyro_x_afsr_dly_trim
 * # of 32KHz delay cycles between analog control and digital compensation, offset by 1
 */
#define REG_IPREG_SYS1_REG_165_GYRO_X_AFSR_DLY_TRIM_POS      0x00
#define REG_IPREG_SYS1_REG_165_GYRO_X_AFSR_DLY_TRIM_MASK     0x07

/*
 * gyro_y_afsr_dly_trim
 * # of 32KHz delay cycles between analog control and digital compensation, offset by 1
 */
#define REG_IPREG_SYS1_REG_165_GYRO_Y_AFSR_DLY_TRIM_POS      0x03
#define REG_IPREG_SYS1_REG_165_GYRO_Y_AFSR_DLY_TRIM_MASK     (0x07 << REG_IPREG_SYS1_REG_165_GYRO_Y_AFSR_DLY_TRIM_POS)



/*
 * REG_IPREG_SYS1_REG_166
 * Register Name : IPREG_SYS1_REG_166
 */

/*
 * gyro_z_afsr_dly_trim
 * # of 32KHz delay cycles between analog control and digital compensation, offset by 1
 */
#define REG_IPREG_SYS1_REG_166_GYRO_Z_AFSR_DLY_TRIM_POS      0x00
#define REG_IPREG_SYS1_REG_166_GYRO_Z_AFSR_DLY_TRIM_MASK     0x07

/*
 * REG_IPREG_SYS1_REG_167
 * Register Name : IPREG_SYS1_REG_167
 */

/*
 * gyro_temp_odr
 * temperature ODR selection for gyro low noise:
 * 0: 3200Hz (filtered with 1+z^-1)
 * 1: 1600Hz (no filter)
 * 2: 1600Hz (filtered with 1+z^-1)
 * 3: 800Hz (no filter)
 */
#define REG_IPREG_SYS1_REG_167_GYRO_TEMP_ODR_POS      0x00
#define REG_IPREG_SYS1_REG_167_GYRO_TEMP_ODR_MASK     0x03

/*
 * gyro_x_afsr_pulse_qual
 * 0: first over threshold qualifies, 1: >= requires 2 out of 4, 2: >= 4/8; 3: >= 6/12
 */
#define REG_IPREG_SYS1_REG_167_GYRO_X_AFSR_PULSE_QUAL_POS      0x02
#define REG_IPREG_SYS1_REG_167_GYRO_X_AFSR_PULSE_QUAL_MASK     (0x03 << REG_IPREG_SYS1_REG_167_GYRO_X_AFSR_PULSE_QUAL_POS)

/*
 * gyro_y_afsr_pulse_qual
 * 0: first over threshold qualifies, 1: >= requires 2 out of 4, 2: >= 4/8; 3: >= 6/12
 */
#define REG_IPREG_SYS1_REG_167_GYRO_Y_AFSR_PULSE_QUAL_POS      0x04
#define REG_IPREG_SYS1_REG_167_GYRO_Y_AFSR_PULSE_QUAL_MASK     (0x03 << REG_IPREG_SYS1_REG_167_GYRO_Y_AFSR_PULSE_QUAL_POS)

/*
 * gyro_z_afsr_pulse_qual
 * 0: first over threshold qualifies, 1: >= requires 2 out of 4, 2: >= 4/8; 3: >= 6/12
 */
#define REG_IPREG_SYS1_REG_167_GYRO_Z_AFSR_PULSE_QUAL_POS      0x06
#define REG_IPREG_SYS1_REG_167_GYRO_Z_AFSR_PULSE_QUAL_MASK     (0x03 << REG_IPREG_SYS1_REG_167_GYRO_Z_AFSR_PULSE_QUAL_POS)



/*
 * REG_IPREG_SYS1_REG_168
 * Register Name : IPREG_SYS1_REG_168
 */

/*
 * gyro_4000dps_fs
 * 1: part has gyroscope high full scale trimmed for 4Kdps;
 * 0: part has gyroscope high full scale trimmed for 2Kdps;
 */
#define REG_IPREG_SYS1_REG_168_GYRO_4000DPS_FS_POS      0x02
#define REG_IPREG_SYS1_REG_168_GYRO_4000DPS_FS_MASK     (0x01 << REG_IPREG_SYS1_REG_168_GYRO_4000DPS_FS_POS)



/*
 * REG_IPREG_SYS1_REG_170
 * Register Name : IPREG_SYS1_REG_170
 */

/*
 * sigp_pld_disable
 * signal path test mode - preload function disable: if set (1), the preload function is ignored through all signal paths (AP/OIS/gyro/accel)
 */
#define REG_IPREG_SYS1_REG_170_SIGP_PLD_DISABLE_POS      0x00
#define REG_IPREG_SYS1_REG_170_SIGP_PLD_DISABLE_MASK     0x01

/*
 * REG_IPREG_SYS1_REG_172
 * Register Name : IPREG_SYS1_REG_172
 */

/*
 * gyro_inj_en_gos
 * signal path test mode - Enable/Disable data injection for Gyro GOS
 */
#define REG_IPREG_SYS1_REG_172_GYRO_INJ_EN_GOS_POS      0x03
#define REG_IPREG_SYS1_REG_172_GYRO_INJ_EN_GOS_MASK     (0x01 << REG_IPREG_SYS1_REG_172_GYRO_INJ_EN_GOS_POS)

/*
 * gyro_observe_adc
 * signal path test mode - Enable/Disable Gyro ADC test
 */
#define REG_IPREG_SYS1_REG_172_GYRO_OBSERVE_ADC_POS      0x05
#define REG_IPREG_SYS1_REG_172_GYRO_OBSERVE_ADC_MASK     (0x01 << REG_IPREG_SYS1_REG_172_GYRO_OBSERVE_ADC_POS)

/*
 * gyro_observe_dec1
 * signal path test mode - Enable/Disable Gyro DEC1 test
 */
#define REG_IPREG_SYS1_REG_172_GYRO_OBSERVE_DEC1_POS      0x06
#define REG_IPREG_SYS1_REG_172_GYRO_OBSERVE_DEC1_MASK     (0x01 << REG_IPREG_SYS1_REG_172_GYRO_OBSERVE_DEC1_POS)
/* ---------------------------------------------------------------------------
 * register IPREG_SYS2
 * ---------------------------------------------------------------------------*/

/*
 * REG_IPREG_SYS2_REG_0
 * Register Name : IPREG_SYS2_REG_0
 */

/*
 * accel_x_mems_off_hfs
 * gos offset correction for 16g analog FS: range  ±4 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_0_ACCEL_X_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_0_ACCEL_X_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_1
 * Register Name : IPREG_SYS2_REG_1
 */

/*
 * accel_x_mems_off_hfs
 * gos offset correction for 16g analog FS: range  ±4 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_1_ACCEL_X_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_1_ACCEL_X_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_2
 * Register Name : IPREG_SYS2_REG_2
 */

/*
 * accel_x_oadj32
 * offset adjustment for accel analog full scale of 32 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_2_ACCEL_X_OADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_2_ACCEL_X_OADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_3
 * Register Name : IPREG_SYS2_REG_3
 */

/*
 * accel_x_oadj32
 * offset adjustment for accel analog full scale of 32 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_3_ACCEL_X_OADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_3_ACCEL_X_OADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_4
 * Register Name : IPREG_SYS2_REG_4
 */

/*
 * accel_x_oadj8
 * offset adjustment for accel analog full scale of 8 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_4_ACCEL_X_OADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_4_ACCEL_X_OADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_5
 * Register Name : IPREG_SYS2_REG_5
 */

/*
 * accel_x_oadj8
 * offset adjustment for accel analog full scale of 8 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_5_ACCEL_X_OADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_5_ACCEL_X_OADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_6
 * Register Name : IPREG_SYS2_REG_6
 */

/*
 * accel_y_mems_off_hfs
 * gos offset correction for 16g analog FS: range  ±4 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_6_ACCEL_Y_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_6_ACCEL_Y_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_7
 * Register Name : IPREG_SYS2_REG_7
 */

/*
 * accel_y_mems_off_hfs
 * gos offset correction for 16g analog FS: range  ±4 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_7_ACCEL_Y_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_7_ACCEL_Y_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_8
 * Register Name : IPREG_SYS2_REG_8
 */

/*
 * accel_y_oadj32
 * offset adjustment for accel analog full scale of 32 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_8_ACCEL_Y_OADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_8_ACCEL_Y_OADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_9
 * Register Name : IPREG_SYS2_REG_9
 */

/*
 * accel_y_oadj32
 * offset adjustment for accel analog full scale of 32 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_9_ACCEL_Y_OADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_9_ACCEL_Y_OADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_10
 * Register Name : IPREG_SYS2_REG_10
 */

/*
 * accel_y_oadj8
 * offset adjustment for accel analog full scale of 8 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_10_ACCEL_Y_OADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_10_ACCEL_Y_OADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_11
 * Register Name : IPREG_SYS2_REG_11
 */

/*
 * accel_y_oadj8
 * offset adjustment for accel analog full scale of 8 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_11_ACCEL_Y_OADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_11_ACCEL_Y_OADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_12
 * Register Name : IPREG_SYS2_REG_12
 */

/*
 * accel_z_mems_off_hfs
 * gos offset correction for 16g analog FS: range  ±4 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_12_ACCEL_Z_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_12_ACCEL_Z_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_13
 * Register Name : IPREG_SYS2_REG_13
 */

/*
 * accel_z_mems_off_hfs
 * gos offset correction for 16g analog FS: range  ±4 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_13_ACCEL_Z_MEMS_OFF_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_13_ACCEL_Z_MEMS_OFF_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_14
 * Register Name : IPREG_SYS2_REG_14
 */

/*
 * accel_z_oadj32
 * offset adjustment for accel analog full scale of 32 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_14_ACCEL_Z_OADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_14_ACCEL_Z_OADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_15
 * Register Name : IPREG_SYS2_REG_15
 */

/*
 * accel_z_oadj32
 * offset adjustment for accel analog full scale of 32 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_15_ACCEL_Z_OADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_15_ACCEL_Z_OADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_16
 * Register Name : IPREG_SYS2_REG_16
 */

/*
 * accel_z_oadj8
 * offset adjustment for accel analog full scale of 8 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_16_ACCEL_Z_OADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_16_ACCEL_Z_OADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_17
 * Register Name : IPREG_SYS2_REG_17
 */

/*
 * accel_z_oadj8
 * offset adjustment for accel analog full scale of 8 gee; range is 4 gee with resolution of 0.125mgee
 */
#define REG_IPREG_SYS2_REG_17_ACCEL_Z_OADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_17_ACCEL_Z_OADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_18
 * Register Name : IPREG_SYS2_REG_18
 */

/*
 * accel_x_mems_off_lp_hfs
 * gos offset correction for LP mode for analog FS 16g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_18_ACCEL_X_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_18_ACCEL_X_MEMS_OFF_LP_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_19
 * Register Name : IPREG_SYS2_REG_19
 */

/*
 * accel_x_mems_off_lp_hfs
 * gos offset correction for LP mode for analog FS 16g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_19_ACCEL_X_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_19_ACCEL_X_MEMS_OFF_LP_HFS_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_20
 * Register Name : IPREG_SYS2_REG_20
 */

/*
 * accel_x_mems_off_lp_hfs32
 * gos offset correction for LP mode for analog FS 32g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_20_ACCEL_X_MEMS_OFF_LP_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_20_ACCEL_X_MEMS_OFF_LP_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_21
 * Register Name : IPREG_SYS2_REG_21
 */

/*
 * accel_x_mems_off_lp_hfs32
 * gos offset correction for LP mode for analog FS 32g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_21_ACCEL_X_MEMS_OFF_LP_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_21_ACCEL_X_MEMS_OFF_LP_HFS32_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_22
 * Register Name : IPREG_SYS2_REG_22
 */

/*
 * accel_x_mems_off_lp_lfs
 * gos offset correction for LP mode for analog FS 8g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_22_ACCEL_X_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_22_ACCEL_X_MEMS_OFF_LP_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_23
 * Register Name : IPREG_SYS2_REG_23
 */

/*
 * accel_x_mems_off_lp_lfs
 * gos offset correction for LP mode for analog FS 8g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_23_ACCEL_X_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_23_ACCEL_X_MEMS_OFF_LP_LFS_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_26
 * Register Name : IPREG_SYS2_REG_26
 */

/*
 * accel_y_mems_off_lp_hfs
 * gos offset correction for LP mode for analog FS 16g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_26_ACCEL_Y_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_26_ACCEL_Y_MEMS_OFF_LP_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_27
 * Register Name : IPREG_SYS2_REG_27
 */

/*
 * accel_y_mems_off_lp_hfs
 * gos offset correction for LP mode for analog FS 16g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_27_ACCEL_Y_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_27_ACCEL_Y_MEMS_OFF_LP_HFS_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_28
 * Register Name : IPREG_SYS2_REG_28
 */

/*
 * accel_y_mems_off_lp_hfs32
 * gos offset correction for LP mode for analog FS 32g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_28_ACCEL_Y_MEMS_OFF_LP_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_28_ACCEL_Y_MEMS_OFF_LP_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_29
 * Register Name : IPREG_SYS2_REG_29
 */

/*
 * accel_y_mems_off_lp_hfs32
 * gos offset correction for LP mode for analog FS 32g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_29_ACCEL_Y_MEMS_OFF_LP_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_29_ACCEL_Y_MEMS_OFF_LP_HFS32_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_30
 * Register Name : IPREG_SYS2_REG_30
 */

/*
 * accel_y_mems_off_lp_lfs
 * gos offset correction for LP mode for analog FS 8g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_30_ACCEL_Y_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_30_ACCEL_Y_MEMS_OFF_LP_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_31
 * Register Name : IPREG_SYS2_REG_31
 */

/*
 * accel_y_mems_off_lp_lfs
 * gos offset correction for LP mode for analog FS 8g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_31_ACCEL_Y_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_31_ACCEL_Y_MEMS_OFF_LP_LFS_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_34
 * Register Name : IPREG_SYS2_REG_34
 */

/*
 * accel_z_mems_off_lp_hfs
 * gos offset correction for LP mode for analog FS 16g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_34_ACCEL_Z_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_34_ACCEL_Z_MEMS_OFF_LP_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_35
 * Register Name : IPREG_SYS2_REG_35
 */

/*
 * accel_z_mems_off_lp_hfs
 * gos offset correction for LP mode for analog FS 16g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_35_ACCEL_Z_MEMS_OFF_LP_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_35_ACCEL_Z_MEMS_OFF_LP_HFS_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_36
 * Register Name : IPREG_SYS2_REG_36
 */

/*
 * accel_z_mems_off_lp_hfs32
 * gos offset correction for LP mode for analog FS 32g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_36_ACCEL_Z_MEMS_OFF_LP_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_36_ACCEL_Z_MEMS_OFF_LP_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_37
 * Register Name : IPREG_SYS2_REG_37
 */

/*
 * accel_z_mems_off_lp_hfs32
 * gos offset correction for LP mode for analog FS 32g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_37_ACCEL_Z_MEMS_OFF_LP_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_37_ACCEL_Z_MEMS_OFF_LP_HFS32_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_38
 * Register Name : IPREG_SYS2_REG_38
 */

/*
 * accel_z_mems_off_lp_lfs
 * gos offset correction for LP mode for analog FS 8g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_38_ACCEL_Z_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_38_ACCEL_Z_MEMS_OFF_LP_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_39
 * Register Name : IPREG_SYS2_REG_39
 */

/*
 * accel_z_mems_off_lp_lfs
 * gos offset correction for LP mode for analog FS 8g : range  ±1 [gee], resolution 0.125mgee
 */
#define REG_IPREG_SYS2_REG_39_ACCEL_Z_MEMS_OFF_LP_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_39_ACCEL_Z_MEMS_OFF_LP_LFS_MASK     0x3f



/*
 * REG_IPREG_SYS2_REG_42
 * Register Name : IPREG_SYS2_REG_42
 */

/*
 * accel_x_gadj32
 * Relative gain adjustment for accel analog full scale of 32 gee; range is 86% through in steps of 0.042 %
 */
#define REG_IPREG_SYS2_REG_42_ACCEL_X_GADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_42_ACCEL_X_GADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_43
 * Register Name : IPREG_SYS2_REG_43
 */

/*
 * accel_x_gadj32
 * Relative gain adjustment for accel analog full scale of 32 gee; range is 86% through in steps of 0.042 %
 */
#define REG_IPREG_SYS2_REG_43_ACCEL_X_GADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_43_ACCEL_X_GADJ32_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_44
 * Register Name : IPREG_SYS2_REG_44
 */

/*
 * accel_x_gadj8
 * Relative gain adjustment for accel analog full scale of 8 gee; range is 86% through in steps of 0.042%
 */
#define REG_IPREG_SYS2_REG_44_ACCEL_X_GADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_44_ACCEL_X_GADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_45
 * Register Name : IPREG_SYS2_REG_45
 */

/*
 * accel_x_gadj8
 * Relative gain adjustment for accel analog full scale of 8 gee; range is 86% through in steps of 0.042%
 */
#define REG_IPREG_SYS2_REG_45_ACCEL_X_GADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_45_ACCEL_X_GADJ8_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_46
 * Register Name : IPREG_SYS2_REG_46
 */

/*
 * accel_x_gain_hfs
 * gos sensitivity adjustment for analog FS 16g: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_46_ACCEL_X_GAIN_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_46_ACCEL_X_GAIN_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_47
 * Register Name : IPREG_SYS2_REG_47
 */

/*
 * accel_x_gain_hfs
 * gos sensitivity adjustment for analog FS 16g: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_47_ACCEL_X_GAIN_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_47_ACCEL_X_GAIN_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_50
 * Register Name : IPREG_SYS2_REG_50
 */

/*
 * accel_y_gadj32
 * Relative gain adjustment for accel analog full scale of 32 gee; range is 86% through in steps of 0.042 %
 */
#define REG_IPREG_SYS2_REG_50_ACCEL_Y_GADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_50_ACCEL_Y_GADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_51
 * Register Name : IPREG_SYS2_REG_51
 */

/*
 * accel_y_gadj32
 * Relative gain adjustment for accel analog full scale of 32 gee; range is 86% through in steps of 0.042 %
 */
#define REG_IPREG_SYS2_REG_51_ACCEL_Y_GADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_51_ACCEL_Y_GADJ32_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_52
 * Register Name : IPREG_SYS2_REG_52
 */

/*
 * accel_y_gadj8
 * Relative gain adjustment for accel analog full scale of 8 gee; range is 86% through in steps of 0.042%
 */
#define REG_IPREG_SYS2_REG_52_ACCEL_Y_GADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_52_ACCEL_Y_GADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_53
 * Register Name : IPREG_SYS2_REG_53
 */

/*
 * accel_y_gadj8
 * Relative gain adjustment for accel analog full scale of 8 gee; range is 86% through in steps of 0.042%
 */
#define REG_IPREG_SYS2_REG_53_ACCEL_Y_GADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_53_ACCEL_Y_GADJ8_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_54
 * Register Name : IPREG_SYS2_REG_54
 */

/*
 * accel_y_gain_hfs
 * gos sensitivity adjustment for analog FS 16g: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_54_ACCEL_Y_GAIN_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_54_ACCEL_Y_GAIN_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_55
 * Register Name : IPREG_SYS2_REG_55
 */

/*
 * accel_y_gain_hfs
 * gos sensitivity adjustment for analog FS 16g: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_55_ACCEL_Y_GAIN_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_55_ACCEL_Y_GAIN_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_58
 * Register Name : IPREG_SYS2_REG_58
 */

/*
 * accel_z_gadj32
 * Relative gain adjustment for accel analog full scale of 32 gee; range is 86% through in steps of 0.042 %
 */
#define REG_IPREG_SYS2_REG_58_ACCEL_Z_GADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_58_ACCEL_Z_GADJ32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_59
 * Register Name : IPREG_SYS2_REG_59
 */

/*
 * accel_z_gadj32
 * Relative gain adjustment for accel analog full scale of 32 gee; range is 86% through in steps of 0.042 %
 */
#define REG_IPREG_SYS2_REG_59_ACCEL_Z_GADJ32_POS      0x00
#define REG_IPREG_SYS2_REG_59_ACCEL_Z_GADJ32_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_60
 * Register Name : IPREG_SYS2_REG_60
 */

/*
 * accel_z_gadj8
 * Relative gain adjustment for accel analog full scale of 8 gee; range is 86% through in steps of 0.042%
 */
#define REG_IPREG_SYS2_REG_60_ACCEL_Z_GADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_60_ACCEL_Z_GADJ8_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_61
 * Register Name : IPREG_SYS2_REG_61
 */

/*
 * accel_z_gadj8
 * Relative gain adjustment for accel analog full scale of 8 gee; range is 86% through in steps of 0.042%
 */
#define REG_IPREG_SYS2_REG_61_ACCEL_Z_GADJ8_POS      0x00
#define REG_IPREG_SYS2_REG_61_ACCEL_Z_GADJ8_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_62
 * Register Name : IPREG_SYS2_REG_62
 */

/*
 * accel_z_gain_hfs
 * gos sensitivity adjustment for analog FS 16g: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_62_ACCEL_Z_GAIN_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_62_ACCEL_Z_GAIN_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_63
 * Register Name : IPREG_SYS2_REG_63
 */

/*
 * accel_z_gain_hfs
 * gos sensitivity adjustment for analog FS 16g: range (0,2], resolution 0.049%
 */
#define REG_IPREG_SYS2_REG_63_ACCEL_Z_GAIN_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_63_ACCEL_Z_GAIN_HFS_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_66
 * Register Name : IPREG_SYS2_REG_66
 */

/*
 * accel_x_mems_offtca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_66_ACCEL_X_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_66_ACCEL_X_MEMS_OFFTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_67
 * Register Name : IPREG_SYS2_REG_67
 */

/*
 * accel_x_mems_offtca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_67_ACCEL_X_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_67_ACCEL_X_MEMS_OFFTCA_HFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_68
 * Register Name : IPREG_SYS2_REG_68
 */

/*
 * accel_x_mems_offtca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_68_ACCEL_X_MEMS_OFFTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_68_ACCEL_X_MEMS_OFFTCA_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_69
 * Register Name : IPREG_SYS2_REG_69
 */

/*
 * accel_x_mems_offtca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_69_ACCEL_X_MEMS_OFFTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_69_ACCEL_X_MEMS_OFFTCA_HFS32_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_70
 * Register Name : IPREG_SYS2_REG_70
 */

/*
 * accel_x_mems_offtca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_70_ACCEL_X_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_70_ACCEL_X_MEMS_OFFTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_71
 * Register Name : IPREG_SYS2_REG_71
 */

/*
 * accel_x_mems_offtca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_71_ACCEL_X_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_71_ACCEL_X_MEMS_OFFTCA_LFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_72
 * Register Name : IPREG_SYS2_REG_72
 */

/*
 * accel_x_mems_offtcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_72_ACCEL_X_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_72_ACCEL_X_MEMS_OFFTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_73
 * Register Name : IPREG_SYS2_REG_73
 */

/*
 * accel_x_mems_offtcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_73_ACCEL_X_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_73_ACCEL_X_MEMS_OFFTCB_HFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_74
 * Register Name : IPREG_SYS2_REG_74
 */

/*
 * accel_x_mems_offtcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_74_ACCEL_X_MEMS_OFFTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_74_ACCEL_X_MEMS_OFFTCB_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_75
 * Register Name : IPREG_SYS2_REG_75
 */

/*
 * accel_x_mems_offtcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_75_ACCEL_X_MEMS_OFFTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_75_ACCEL_X_MEMS_OFFTCB_HFS32_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_76
 * Register Name : IPREG_SYS2_REG_76
 */

/*
 * accel_x_mems_offtcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_76_ACCEL_X_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_76_ACCEL_X_MEMS_OFFTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_77
 * Register Name : IPREG_SYS2_REG_77
 */

/*
 * accel_x_mems_offtcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_77_ACCEL_X_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_77_ACCEL_X_MEMS_OFFTCB_LFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_78
 * Register Name : IPREG_SYS2_REG_78
 */

/*
 * accel_y_mems_offtca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_78_ACCEL_Y_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_78_ACCEL_Y_MEMS_OFFTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_79
 * Register Name : IPREG_SYS2_REG_79
 */

/*
 * accel_y_mems_offtca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_79_ACCEL_Y_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_79_ACCEL_Y_MEMS_OFFTCA_HFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_80
 * Register Name : IPREG_SYS2_REG_80
 */

/*
 * accel_y_mems_offtca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_80_ACCEL_Y_MEMS_OFFTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_80_ACCEL_Y_MEMS_OFFTCA_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_81
 * Register Name : IPREG_SYS2_REG_81
 */

/*
 * accel_y_mems_offtca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_81_ACCEL_Y_MEMS_OFFTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_81_ACCEL_Y_MEMS_OFFTCA_HFS32_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_82
 * Register Name : IPREG_SYS2_REG_82
 */

/*
 * accel_y_mems_offtca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_82_ACCEL_Y_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_82_ACCEL_Y_MEMS_OFFTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_83
 * Register Name : IPREG_SYS2_REG_83
 */

/*
 * accel_y_mems_offtca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_83_ACCEL_Y_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_83_ACCEL_Y_MEMS_OFFTCA_LFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_84
 * Register Name : IPREG_SYS2_REG_84
 */

/*
 * accel_y_mems_offtcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_84_ACCEL_Y_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_84_ACCEL_Y_MEMS_OFFTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_85
 * Register Name : IPREG_SYS2_REG_85
 */

/*
 * accel_y_mems_offtcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_85_ACCEL_Y_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_85_ACCEL_Y_MEMS_OFFTCB_HFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_86
 * Register Name : IPREG_SYS2_REG_86
 */

/*
 * accel_y_mems_offtcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_86_ACCEL_Y_MEMS_OFFTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_86_ACCEL_Y_MEMS_OFFTCB_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_87
 * Register Name : IPREG_SYS2_REG_87
 */

/*
 * accel_y_mems_offtcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_87_ACCEL_Y_MEMS_OFFTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_87_ACCEL_Y_MEMS_OFFTCB_HFS32_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_88
 * Register Name : IPREG_SYS2_REG_88
 */

/*
 * accel_y_mems_offtcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_88_ACCEL_Y_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_88_ACCEL_Y_MEMS_OFFTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_89
 * Register Name : IPREG_SYS2_REG_89
 */

/*
 * accel_y_mems_offtcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_89_ACCEL_Y_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_89_ACCEL_Y_MEMS_OFFTCB_LFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_90
 * Register Name : IPREG_SYS2_REG_90
 */

/*
 * accel_z_mems_offtca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_90_ACCEL_Z_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_90_ACCEL_Z_MEMS_OFFTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_91
 * Register Name : IPREG_SYS2_REG_91
 */

/*
 * accel_z_mems_offtca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_91_ACCEL_Z_MEMS_OFFTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_91_ACCEL_Z_MEMS_OFFTCA_HFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_92
 * Register Name : IPREG_SYS2_REG_92
 */

/*
 * accel_z_mems_offtca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_92_ACCEL_Z_MEMS_OFFTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_92_ACCEL_Z_MEMS_OFFTCA_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_93
 * Register Name : IPREG_SYS2_REG_93
 */

/*
 * accel_z_mems_offtca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_93_ACCEL_Z_MEMS_OFFTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_93_ACCEL_Z_MEMS_OFFTCA_HFS32_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_94
 * Register Name : IPREG_SYS2_REG_94
 */

/*
 * accel_z_mems_offtca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_94_ACCEL_Z_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_94_ACCEL_Z_MEMS_OFFTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_95
 * Register Name : IPREG_SYS2_REG_95
 */

/*
 * accel_z_mems_offtca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_95_ACCEL_Z_MEMS_OFFTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_95_ACCEL_Z_MEMS_OFFTCA_LFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_96
 * Register Name : IPREG_SYS2_REG_96
 */

/*
 * accel_z_mems_offtcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_96_ACCEL_Z_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_96_ACCEL_Z_MEMS_OFFTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_97
 * Register Name : IPREG_SYS2_REG_97
 */

/*
 * accel_z_mems_offtcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_97_ACCEL_Z_MEMS_OFFTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_97_ACCEL_Z_MEMS_OFFTCB_HFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_98
 * Register Name : IPREG_SYS2_REG_98
 */

/*
 * accel_z_mems_offtcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_98_ACCEL_Z_MEMS_OFFTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_98_ACCEL_Z_MEMS_OFFTCB_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_99
 * Register Name : IPREG_SYS2_REG_99
 */

/*
 * accel_z_mems_offtcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_99_ACCEL_Z_MEMS_OFFTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_99_ACCEL_Z_MEMS_OFFTCB_HFS32_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_100
 * Register Name : IPREG_SYS2_REG_100
 */

/*
 * accel_z_mems_offtcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_100_ACCEL_Z_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_100_ACCEL_Z_MEMS_OFFTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_101
 * Register Name : IPREG_SYS2_REG_101
 */

/*
 * accel_z_mems_offtcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±15.6 [mgee/C];resolution: 0.031 [mgee/C] - used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_101_ACCEL_Z_MEMS_OFFTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_101_ACCEL_Z_MEMS_OFFTCB_LFS_MASK     0x03



/*
 * REG_IPREG_SYS2_REG_102
 * Register Name : IPREG_SYS2_REG_102
 */

/*
 * accel_x_gaintca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_102_ACCEL_X_GAINTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_102_ACCEL_X_GAINTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_103
 * Register Name : IPREG_SYS2_REG_103
 */

/*
 * accel_x_gaintca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_103_ACCEL_X_GAINTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_103_ACCEL_X_GAINTCA_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_104
 * Register Name : IPREG_SYS2_REG_104
 */

/*
 * accel_x_gaintca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_104_ACCEL_X_GAINTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_104_ACCEL_X_GAINTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_105
 * Register Name : IPREG_SYS2_REG_105
 */

/*
 * accel_x_gaintcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_105_ACCEL_X_GAINTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_105_ACCEL_X_GAINTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_106
 * Register Name : IPREG_SYS2_REG_106
 */

/*
 * accel_x_gaintcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_106_ACCEL_X_GAINTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_106_ACCEL_X_GAINTCB_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_107
 * Register Name : IPREG_SYS2_REG_107
 */

/*
 * accel_x_gaintcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_107_ACCEL_X_GAINTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_107_ACCEL_X_GAINTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_108
 * Register Name : IPREG_SYS2_REG_108
 */

/*
 * accel_y_gaintca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_108_ACCEL_Y_GAINTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_108_ACCEL_Y_GAINTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_109
 * Register Name : IPREG_SYS2_REG_109
 */

/*
 * accel_y_gaintca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_109_ACCEL_Y_GAINTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_109_ACCEL_Y_GAINTCA_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_110
 * Register Name : IPREG_SYS2_REG_110
 */

/*
 * accel_y_gaintca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_110_ACCEL_Y_GAINTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_110_ACCEL_Y_GAINTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_111
 * Register Name : IPREG_SYS2_REG_111
 */

/*
 * accel_y_gaintcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_111_ACCEL_Y_GAINTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_111_ACCEL_Y_GAINTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_112
 * Register Name : IPREG_SYS2_REG_112
 */

/*
 * accel_y_gaintcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_112_ACCEL_Y_GAINTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_112_ACCEL_Y_GAINTCB_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_113
 * Register Name : IPREG_SYS2_REG_113
 */

/*
 * accel_y_gaintcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_113_ACCEL_Y_GAINTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_113_ACCEL_Y_GAINTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_114
 * Register Name : IPREG_SYS2_REG_114
 */

/*
 * accel_z_gaintca_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_114_ACCEL_Z_GAINTCA_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_114_ACCEL_Z_GAINTCA_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_115
 * Register Name : IPREG_SYS2_REG_115
 */

/*
 * accel_z_gaintca_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_115_ACCEL_Z_GAINTCA_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_115_ACCEL_Z_GAINTCA_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_116
 * Register Name : IPREG_SYS2_REG_116
 */

/*
 * accel_z_gaintca_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T<=Tmid
 */
#define REG_IPREG_SYS2_REG_116_ACCEL_Z_GAINTCA_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_116_ACCEL_Z_GAINTCA_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_117
 * Register Name : IPREG_SYS2_REG_117
 */

/*
 * accel_z_gaintcb_hfs
 * gos linear tempeature coefficient (dual slope) for analog FS 16g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_117_ACCEL_Z_GAINTCB_HFS_POS      0x00
#define REG_IPREG_SYS2_REG_117_ACCEL_Z_GAINTCB_HFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_118
 * Register Name : IPREG_SYS2_REG_118
 */

/*
 * accel_z_gaintcb_hfs32
 * gos linear tempeature coefficient (dual slope) for analog FS 32g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_118_ACCEL_Z_GAINTCB_HFS32_POS      0x00
#define REG_IPREG_SYS2_REG_118_ACCEL_Z_GAINTCB_HFS32_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_119
 * Register Name : IPREG_SYS2_REG_119
 */

/*
 * accel_z_gaintcb_lfs
 * gos linear tempeature coefficient (dual slope) for analog FS 8g; range ±0.097 [%/C]; resolution: 0.00076 [%/C]- used for T>Tmid
 */
#define REG_IPREG_SYS2_REG_119_ACCEL_Z_GAINTCB_LFS_POS      0x00
#define REG_IPREG_SYS2_REG_119_ACCEL_Z_GAINTCB_LFS_MASK     0xff



/*
 * REG_IPREG_SYS2_REG_120
 * Register Name : IPREG_SYS2_REG_120
 */

/*
 * accel_x_tmid_gain
 * Temperature inflection point (in deg C) for dual slope mems offset-tc in 8 steps, Range: [-28, 92]
 */
#define REG_IPREG_SYS2_REG_120_ACCEL_X_TMID_GAIN_POS      0x00
#define REG_IPREG_SYS2_REG_120_ACCEL_X_TMID_GAIN_MASK     0x0f

/*
 * accel_x_tmid_off
 * Temperature inflection point (in deg C) for dual slope mems offset-tc in 8 steps, Range: [-28, 92]
 */
#define REG_IPREG_SYS2_REG_120_ACCEL_X_TMID_OFF_POS      0x04
#define REG_IPREG_SYS2_REG_120_ACCEL_X_TMID_OFF_MASK     (0x0f << REG_IPREG_SYS2_REG_120_ACCEL_X_TMID_OFF_POS)



/*
 * REG_IPREG_SYS2_REG_121
 * Register Name : IPREG_SYS2_REG_121
 */

/*
 * accel_y_tmid_gain
 * Temperature inflection point (in deg C) for dual slope mems offset-tc in 8 steps, Range: [-28, 92]
 */
#define REG_IPREG_SYS2_REG_121_ACCEL_Y_TMID_GAIN_POS      0x00
#define REG_IPREG_SYS2_REG_121_ACCEL_Y_TMID_GAIN_MASK     0x0f

/*
 * accel_y_tmid_off
 * Temperature inflection point (in deg C) for dual slope mems offset-tc in 8 steps, Range: [-28, 92]
 */
#define REG_IPREG_SYS2_REG_121_ACCEL_Y_TMID_OFF_POS      0x04
#define REG_IPREG_SYS2_REG_121_ACCEL_Y_TMID_OFF_MASK     (0x0f << REG_IPREG_SYS2_REG_121_ACCEL_Y_TMID_OFF_POS)



/*
 * REG_IPREG_SYS2_REG_122
 * Register Name : IPREG_SYS2_REG_122
 */

/*
 * accel_z_tmid_gain
 * Temperature inflection point (in deg C) for dual slope mems offset-tc in 8 steps, Range: [-28, 92]
 */
#define REG_IPREG_SYS2_REG_122_ACCEL_Z_TMID_GAIN_POS      0x00
#define REG_IPREG_SYS2_REG_122_ACCEL_Z_TMID_GAIN_MASK     0x0f

/*
 * accel_z_tmid_off
 * Temperature inflection point (in deg C) for dual slope mems offset-tc in 8 steps, Range: [-28, 92]
 */
#define REG_IPREG_SYS2_REG_122_ACCEL_Z_TMID_OFF_POS      0x04
#define REG_IPREG_SYS2_REG_122_ACCEL_Z_TMID_OFF_MASK     (0x0f << REG_IPREG_SYS2_REG_122_ACCEL_Z_TMID_OFF_POS)



/*
 * REG_IPREG_SYS2_REG_123
 * Register Name : IPREG_SYS2_REG_123
 */

/*
 * accel_temp_odr
 * temperature ODR selection for accel low noise:
 * 0: 800Hz (filtered with 1+z^-1)
 * 1: 800Hz (no filter)
 * 2: 400Hz (filtered with 1+z^-1)
 * 3: 400Hz (no filter)
 * 4: 200Hz (filtered with 1+z^-1)
 * 5: 200Hz (no filter)
 * 6: 100Hz (filtered with 1+z^-1)
 * 7: 100Hz (no filter)
 */
#define REG_IPREG_SYS2_REG_123_ACCEL_TEMP_ODR_POS      0x02
#define REG_IPREG_SYS2_REG_123_ACCEL_TEMP_ODR_MASK     (0x07 << REG_IPREG_SYS2_REG_123_ACCEL_TEMP_ODR_POS)

/*
 * accel_32gee_fs
 * 1: part has accelerometer 32gee full scale capability;
 * 0: part has acceleometer full scale extending to up 16gee max;
 */
#define REG_IPREG_SYS2_REG_123_ACCEL_32GEE_FS_POS      0x05
#define REG_IPREG_SYS2_REG_123_ACCEL_32GEE_FS_MASK     (0x01 << REG_IPREG_SYS2_REG_123_ACCEL_32GEE_FS_POS)



/*
 * REG_IPREG_SYS2_REG_124
 * Register Name : IPREG_SYS2_REG_124
 */

/*
 * accel_afsr_dly_trim
 * # of 6.4KHz delay cycles between analog control and digital compensation
 * note: full scale is not automatic
 */
#define REG_IPREG_SYS2_REG_124_ACCEL_AFSR_DLY_TRIM_POS      0x00
#define REG_IPREG_SYS2_REG_124_ACCEL_AFSR_DLY_TRIM_MASK     0x0f



/*
 * REG_IPREG_SYS2_REG_125
 * Register Name : IPREG_SYS2_REG_125
 */

/*
 * tmp_co_trim
 * Trim Temp Sensor ADC reconstruction filter coeff.
 * (Range: [-1,1), Resolution: 1/64)
 */
#define REG_IPREG_SYS2_REG_125_TMP_CO_TRIM_POS      0x00
#define REG_IPREG_SYS2_REG_125_TMP_CO_TRIM_MASK     0x7f



/*
 * REG_IPREG_SYS2_REG_126
 * Register Name : IPREG_SYS2_REG_126
 */

/*
 * tmp_offset_trim
 * Trim offset in Temp sensor ADC reconstruction scaling.
 * (Range: [-64,63) degC)
 */
#define REG_IPREG_SYS2_REG_126_TMP_OFFSET_TRIM_POS      0x00
#define REG_IPREG_SYS2_REG_126_TMP_OFFSET_TRIM_MASK     0x7f



/*
 * REG_IPREG_SYS2_REG_127
 * Register Name : IPREG_SYS2_REG_127
 */

/*
 * tmp_gain_trim
 * Trim gain in Temp sensor ADC reconstruction scaling.
 * (Range: [-8,8]/128)
 */
#define REG_IPREG_SYS2_REG_127_TMP_GAIN_TRIM_POS      0x00
#define REG_IPREG_SYS2_REG_127_TMP_GAIN_TRIM_MASK     0x0f

/*
 * tmp_dis
 * Unused
 */
#define REG_IPREG_SYS2_REG_127_TMP_DIS_POS      0x04
#define REG_IPREG_SYS2_REG_127_TMP_DIS_MASK     (0x01 << REG_IPREG_SYS2_REG_127_TMP_DIS_POS)



/*
 * REG_IPREG_SYS2_REG_128
 * Register Name : IPREG_SYS2_REG_128
 */

/*
 * tmp_inj_en_gos
 * signal path test mode - Enable/Disable Temperature data injection GOS input and Temp sensor LPF.
 */
#define REG_IPREG_SYS2_REG_128_TMP_INJ_EN_GOS_POS      0x06
#define REG_IPREG_SYS2_REG_128_TMP_INJ_EN_GOS_MASK     (0x01 << REG_IPREG_SYS2_REG_128_TMP_INJ_EN_GOS_POS)



/*
 * REG_IPREG_SYS2_REG_131
 * Register Name : IPREG_SYS2_REG_131
 */

/*
 * accel_inj_en_adc
 * signal path test mode - Enable/Disable data injection at Accel ADC input
 */
#define REG_IPREG_SYS2_REG_131_ACCEL_INJ_EN_ADC_POS      0x03
#define REG_IPREG_SYS2_REG_131_ACCEL_INJ_EN_ADC_MASK     (0x01 << REG_IPREG_SYS2_REG_131_ACCEL_INJ_EN_ADC_POS)

/*
 * accel_inj_en_gos
 * signal path test mode - Enable/Disable data injection at Accel GOS
 */
#define REG_IPREG_SYS2_REG_131_ACCEL_INJ_EN_GOS_POS      0x04
#define REG_IPREG_SYS2_REG_131_ACCEL_INJ_EN_GOS_MASK     (0x01 << REG_IPREG_SYS2_REG_131_ACCEL_INJ_EN_GOS_POS)

/*
 * accel_observe_adc
 * signal path test mode - Enable/Disable Accel ADC test
 */
#define REG_IPREG_SYS2_REG_131_ACCEL_OBSERVE_ADC_POS      0x06
#define REG_IPREG_SYS2_REG_131_ACCEL_OBSERVE_ADC_MASK     (0x01 << REG_IPREG_SYS2_REG_131_ACCEL_OBSERVE_ADC_POS)

/*
 * accel_observe_dec1
 * signal path test mode - Enable/Disable Accel DEC1 test
 */
#define REG_IPREG_SYS2_REG_131_ACCEL_OBSERVE_DEC1_POS      0x07
#define REG_IPREG_SYS2_REG_131_ACCEL_OBSERVE_DEC1_MASK     (0x01 << REG_IPREG_SYS2_REG_131_ACCEL_OBSERVE_DEC1_POS)


/* ---------------------------------------------------------------------------
 * register IPREG_TOP1
 * ---------------------------------------------------------------------------*/

/*
 * REG_FIFO_LOST_COUNT
 * Register Name : FIFO_LOST_COUNT
 */

/*
 * fifo_lost_frame_cnt
 * [Supports Dynamic Change] Count of lost frames
 * - Incremented on:
 *     a) FIFO overflow
 * - Cleared on
 *     a) register read
 *     b) FIFO flush
 * Holds a maximum count of 255 lost frames
 *
 * NOTE: This register is obsolete. It is not part of Newport implementation.
 */
#define REG_FIFO_LOST_COUNT_FIFO_LOST_FRAME_CNT_POS      0x00
#define REG_FIFO_LOST_COUNT_FIFO_LOST_FRAME_CNT_MASK     0xff



/*
 * REG_I3C_PROV_ID_0
 * Register Name : I3C_PROV_ID_0
 */

/*
 * i3c_prov_id
 * Provisional ID.
 * Bit[47:33]: MIPI Manufacturing ID.
 * Bit[32]: ID type selector.
 * Bit[31:16]: Part ID.
 * Bit[15:12]: Instance ID.
 * Bit[11:0]: vendor specific.
 * For AUX1 I3C bit 0 will be inverted
 */
#define REG_I3C_PROV_ID_0_I3C_PROV_ID_POS      0x00
#define REG_I3C_PROV_ID_0_I3C_PROV_ID_MASK     0xff



/*
 * REG_I3C_PROV_ID_1
 * Register Name : I3C_PROV_ID_1
 */

/*
 * i3c_prov_id
 * Provisional ID.
 * Bit[47:33]: MIPI Manufacturing ID.
 * Bit[32]: ID type selector.
 * Bit[31:16]: Part ID.
 * Bit[15:12]: Instance ID.
 * Bit[11:0]: vendor specific.
 * For AUX1 I3C bit 0 will be inverted
 */
#define REG_I3C_PROV_ID_1_I3C_PROV_ID_POS      0x00
#define REG_I3C_PROV_ID_1_I3C_PROV_ID_MASK     0xff



/*
 * REG_I3C_PROV_ID_2
 * Register Name : I3C_PROV_ID_2
 */

/*
 * i3c_prov_id
 * Provisional ID.
 * Bit[47:33]: MIPI Manufacturing ID.
 * Bit[32]: ID type selector.
 * Bit[31:16]: Part ID.
 * Bit[15:12]: Instance ID.
 * Bit[11:0]: vendor specific.
 * For AUX1 I3C bit 0 will be inverted
 */
#define REG_I3C_PROV_ID_2_I3C_PROV_ID_POS      0x00
#define REG_I3C_PROV_ID_2_I3C_PROV_ID_MASK     0xff



/*
 * REG_I3C_PROV_ID_3
 * Register Name : I3C_PROV_ID_3
 */

/*
 * i3c_prov_id
 * Provisional ID.
 * Bit[47:33]: MIPI Manufacturing ID.
 * Bit[32]: ID type selector.
 * Bit[31:16]: Part ID.
 * Bit[15:12]: Instance ID.
 * Bit[11:0]: vendor specific.
 * For AUX1 I3C bit 0 will be inverted
 */
#define REG_I3C_PROV_ID_3_I3C_PROV_ID_POS      0x00
#define REG_I3C_PROV_ID_3_I3C_PROV_ID_MASK     0xff



/*
 * REG_I3C_PROV_ID_4
 * Register Name : I3C_PROV_ID_4
 */

/*
 * i3c_prov_id
 * Provisional ID.
 * Bit[47:33]: MIPI Manufacturing ID.
 * Bit[32]: ID type selector.
 * Bit[31:16]: Part ID.
 * Bit[15:12]: Instance ID.
 * Bit[11:0]: vendor specific.
 * For AUX1 I3C bit 0 will be inverted
 */
#define REG_I3C_PROV_ID_4_I3C_PROV_ID_POS      0x00
#define REG_I3C_PROV_ID_4_I3C_PROV_ID_MASK     0xff



/*
 * REG_I3C_PROV_ID_5
 * Register Name : I3C_PROV_ID_5
 */

/*
 * i3c_prov_id
 * Provisional ID.
 * Bit[47:33]: MIPI Manufacturing ID.
 * Bit[32]: ID type selector.
 * Bit[31:16]: Part ID.
 * Bit[15:12]: Instance ID.
 * Bit[11:0]: vendor specific.
 * For AUX1 I3C bit 0 will be inverted
 */
#define REG_I3C_PROV_ID_5_I3C_PROV_ID_POS      0x00
#define REG_I3C_PROV_ID_5_I3C_PROV_ID_MASK     0xff



/*
 * REG_SIFS_I3C_BCR
 * Register Name : SIFS_I3C_BCR
 */

/*
 * i3c_bcr
 * Bus Characteristics Register.
 * Bit[7:6]: Device Role. Fixed to 2’b00 (I3C Slave).
 * Bit[5]:    1’b0 – SDR Only   1’b1 – HDR Capable
 * For AUX1 SIFS , only SDR is supported so the value has no effect
 * Bit[4]: Bridge Identifier. Fixed to 1’b0 (Not a Bridge Device).
 * Bit[3]: Offline Capable.    1’b0 – Device will always respond to I3C Bus commands.   1’b1 – Device will not always respond  to I3C Bus commands.
 * Bit[2]: IBI Payload   1’b0 – No data byte follows the accepted IBI.      1’b1 – Madatory one or more data bytes follow the accepted IBI.
 * For AUX1 SIFS, IBI Payload is always '0' and so the value of this bit have no effect.
 * Bit[1]: IBI Request Capable.      1’b0 – Not Capable.   1’b1 – Capable.
 * Bit[0]: Max Data Speed Limitation.   1’b0 – No Limitation. Slave does not have max data speed limitation.     1’b1 – Limitation. Slave has max data speed limitation. User needs to issue GETMXDS CCC for detail max data speed limitation information.
 */
#define REG_SIFS_I3C_BCR_I3C_BCR_POS      0x00
#define REG_SIFS_I3C_BCR_I3C_BCR_MASK     0xff



/*
 * REG_SIFS_I3C_DCR
 * Register Name : SIFS_I3C_DCR
 */

/*
 * i3c_dcr
 * Device Characteristics Register describes the I3C compliant Device type.
 * Bit[7:2] =0
 * Bit[1:0]:
 *   2'b00: DCR is 8'h44 for 6-axis sensor.
 *   2'b01: DCR is 8'h41 for 3-axis accel.
 *   2'b10: DCR is 8'h42 for 3-axis gyro.
 *   2'b11: DCR is 8'h46 for 9-axis Gyro/Accel/Mag.
 */
#define REG_SIFS_I3C_DCR_I3C_DCR_POS      0x00
#define REG_SIFS_I3C_DCR_I3C_DCR_MASK     0xff



/*
 * REG_SIFS_CONTROL
 * Register Name : SIFS_CONTROL
 */

/*
 * hot_join_en
 * 1: To enable hot join feature.
 * 0: To disable hot join feature.
 */
#define REG_SIFS_CONTROL_HOT_JOIN_EN_POS      0x01
#define REG_SIFS_CONTROL_HOT_JOIN_EN_MASK     (0x01 << REG_SIFS_CONTROL_HOT_JOIN_EN_POS)

/*
 * i3c_sdr_en
 * Enable I3C SDR mode.
 */
#define REG_SIFS_CONTROL_I3C_SDR_EN_POS      0x02
#define REG_SIFS_CONTROL_I3C_SDR_EN_MASK     (0x01 << REG_SIFS_CONTROL_I3C_SDR_EN_POS)

/*
 * i3c_ddr_en
 * Enable I3C DDR mode.
 * This register should be programmed in I2C or I3C/SDR, but not in I3C/DDR. Changes is taking effect after CSB (of SPI mode) or after STOP (of I2C mode or I3C/SDR mode).
 */
#define REG_SIFS_CONTROL_I3C_DDR_EN_POS      0x03
#define REG_SIFS_CONTROL_I3C_DDR_EN_MASK     (0x01 << REG_SIFS_CONTROL_I3C_DDR_EN_POS)

/*
 * aux1_hot_join_en
 * AUX1 SIFS
 * 1: To enable hot join feature.
 * 0: To disable hot join feature.
 */
#define REG_SIFS_CONTROL_AUX1_HOT_JOIN_EN_POS      0x04
#define REG_SIFS_CONTROL_AUX1_HOT_JOIN_EN_MASK     (0x01 << REG_SIFS_CONTROL_AUX1_HOT_JOIN_EN_POS)

/*
 * aux1_i3c_sdr_en
 * Enable I3C SDR mode for AUX1 SIFS.
 */
#define REG_SIFS_CONTROL_AUX1_I3C_SDR_EN_POS      0x05
#define REG_SIFS_CONTROL_AUX1_I3C_SDR_EN_MASK     (0x01 << REG_SIFS_CONTROL_AUX1_I3C_SDR_EN_POS)



/*
 * REG_SIFS_GETMXDS_MAXWR
 * Register Name : SIFS_GETMXDS_MAXWR
 */

/*
 * getmxds_maxwr
 * Maximum Sustained Data Rate for non-CCC messages sent by Slave Device to Master Device :
 * 0: fSCL Max (default value)
 * 1: 8 MHz
 * 2: 6 MHz
 * 3: 4 MHz
 * 4: 2 MHz
 * 5–7: Reserved for future use by the MIPI Alliance
 *
 * User can configure with Register[ ADDR: ‘d36] bit [2:0]
 */
#define REG_SIFS_GETMXDS_MAXWR_GETMXDS_MAXWR_POS      0x00
#define REG_SIFS_GETMXDS_MAXWR_GETMXDS_MAXWR_MASK     0x07



/*
 * REG_SIFS_GETMXDS_MAXRD
 * Register Name : SIFS_GETMXDS_MAXRD
 */

/*
 * getmxds_maxrd
 * [2:0]: max sustained data rate for non-CCC message from salve to host.
 * [5:3]: Clock to data turn around time (Tsco).
 *        0: <= 8ns.
 *        1: <= 9ns.
 *        2: <= 10ns.
 *        3: <= 11ns.
 *        4: <= 12ns.
 *        5: reserved.
 *        6: reserved.
 *        7: > 12ns (see private agreement).
 */
#define REG_SIFS_GETMXDS_MAXRD_GETMXDS_MAXRD_POS      0x00
#define REG_SIFS_GETMXDS_MAXRD_GETMXDS_MAXRD_MASK     0x3f



/*
 * REG_INTF_CONFIG
 * Register Name : INTF_CONFIG
 */

/*
 * i2c_sda_out_dly
 * Programmable delay on the output enable path to hold transmitting data. Enabled only in I2c. It is automatically disable when SPI or I3C (i3c_sdr_en or i3c_ddr_en) is selected.
 * 1-7: programmable delay from (1 to 7) x 6.4ns
 * 8-15: delay bypassed
 */
#define REG_INTF_CONFIG_I2C_SDA_OUT_DLY_POS      0x00
#define REG_INTF_CONFIG_I2C_SDA_OUT_DLY_MASK     0x0f

/*
 * i3c_sda_out_dly
 * Is used to add delay for SDA signal from I3C slave to SIFS slave. This delay is applicable only when I3C slave IP is used for  both I3C or I2C operation. This delay is not applicable when in SPI mode, or using legacy I2C slave.
 *        0:  sda output delay = 1*6.4ns.
 *        1:  sda output delay = 2*6.4ns.
 *        2:  sda output delay = 3*6.4ns.
 *        3:  sda output delay = 4*6.4ns.
 *        4-7: delay bypassed
 */
#define REG_INTF_CONFIG_I3C_SDA_OUT_DLY_POS      0x04
#define REG_INTF_CONFIG_I3C_SDA_OUT_DLY_MASK     (0x07 << REG_INTF_CONFIG_I3C_SDA_OUT_DLY_POS)



/*
 * REG_SMC_CONTROL_0
 * Register Name : SMC_CONTROL_0
 */

/*
 * accel_ap_en
 * Enable the Accelerometer signal path at the UI/AP interface
 */
#define REG_SMC_CONTROL_0_ACCEL_AP_EN_POS      0x05
#define REG_SMC_CONTROL_0_ACCEL_AP_EN_MASK     (0x01 << REG_SMC_CONTROL_0_ACCEL_AP_EN_POS)

/*
 * gyro_ap_en
 * Enable the Gyroscope signal path at the UI/AP interface
 */
#define REG_SMC_CONTROL_0_GYRO_AP_EN_POS      0x06
#define REG_SMC_CONTROL_0_GYRO_AP_EN_MASK     (0x01 << REG_SMC_CONTROL_0_GYRO_AP_EN_POS)

/*
 * shared_cnt_dis
 * If set to 1 this bit disables the shared circuitry counter for OFF->LN transitions at the XL, allowing an immediate transition (instead of waiting for the shared circuitry to be turned on in advance).
 */
#define REG_SMC_CONTROL_0_SHARED_CNT_DIS_POS      0x07
#define REG_SMC_CONTROL_0_SHARED_CNT_DIS_MASK     (0x01 << REG_SMC_CONTROL_0_SHARED_CNT_DIS_POS)



/*
 * REG_SMC_CONTROL_1
 * Register Name : SMC_CONTROL_1
 */

/*
 * sreg_aux_accel_only_en
 * 0: SREG does not support the sensor data register read from the AUX1 and AUX2 hosts if the gyro sensor is not enabled.   All the clocks to the synchronizers related to AUX1 and AUX2 host interface should be off completely to save power.
 *
 * 1: SREG supports the sensor data register read from the AUX1 and AUX2 host if the gyro sensor is not enabled.
 */
#define REG_SMC_CONTROL_1_SREG_AUX_ACCEL_ONLY_EN_POS      0x03
#define REG_SMC_CONTROL_1_SREG_AUX_ACCEL_ONLY_EN_MASK     (0x01 << REG_SMC_CONTROL_1_SREG_AUX_ACCEL_ONLY_EN_POS)



/*
 * REG_SIFS_I3C_STC_CFG
 * Register Name : SIFS_I3C_STC_CFG
 */

/*
 * i3c_ibi_byte_en
 * Enables IBI-payload function (BCR).
 */
#define REG_SIFS_I3C_STC_CFG_I3C_IBI_BYTE_EN_POS      0x00
#define REG_SIFS_I3C_STC_CFG_I3C_IBI_BYTE_EN_MASK     0x01

/*
 * i3c_ibi_en
 * Enable/disable the IBI feature in the I3C Slave. This is a static OTP bit. When the trim value is 0, it resets all the IBI control registers and prevents any IBIs from being triggered. After OTP trim values have been loaded to registers, this bit is not meant to be used to enable/disable IBIs.
 */
#define REG_SIFS_I3C_STC_CFG_I3C_IBI_EN_POS      0x01
#define REG_SIFS_I3C_STC_CFG_I3C_IBI_EN_MASK     (0x01 << REG_SIFS_I3C_STC_CFG_I3C_IBI_EN_POS)

/*
 * getxtime_stc_mode
 * Configure chip's STC supporting capability.
 * 1: chip is capable of supporting STC operation. Setting 1 to this bit does not enable the STC operation by itself. Host need to program stc_mode to enable or disable the STC operation.
 * 0: chip does not support STC operation. When getxtime_stc_mode = 0, the setting of stc_mode is ignored and host won't be able to enable STC operation by setting stc_mode to 1.
 *
 * For STC support in power-up, otp trim value to be '1'
 *
 * Procedure to Enable the STC feature:
 * 1) Configure the device in sleep mode:
 *        a) accel_mode = gyro_mode = 0.
 *        b) accel_ois1_en = gyro_ois1_en = 0, (TDK internal note: if AUX1 interface is not trimmed off.)
 *        c) accel_ois2_en = gyro_ois2_en = 0. (TDK internal note: if AUX2 interface is not trimmed off).
 * 2) Configure the device to use the RC oscillator in LP mode:
 *        a) accel_lp_clk_sel = 1. (TDK internal note: The AULP is not supported when the STC feature is enabled.)
 * 3) Configure the STC module:
 *       a) stc_mode = 0 (TDK internal note: for S4S feature - sync with Host’s commands).
 * 4) Configure the SIGP control registers:
 *       a) accel_src_ctrl = gyro_src_ctrl = 2.
 * 5) Enable the STC functionality:
 *      a) i3c_stc_mode = 1.
 * From now on the STC feature is enabled, and the user can configure the device as needed.  All power-mode registers can now be changed as desired
 *
 * Procedure to Disable the STC feature:
 * 1) Configure the device in sleep mode:
 *      a) accel_mode = gyro_mode = 0.
 *      b) accel_ois1_en = gyro_ois1_en = 0, (TDK internal note: if AUX1 interface is not trimmed off.)
 *      c) accel_ois2_en = gyro_ois2_en = 0. (TDK internal note: if AUX2 interface is not trimmed off).
 * 2) Disable the STC functionality:
 *      i3c_stc_mode = 0.
 * 3) (optional) Configure the device to use the Wake-Up oscillator for the LP mode:
 *       a) accel_lp_clk_sel = 0.
 *       b) (TDK internal note: if the RTC feature is not trimmed off and the user enables the RTC feature with rtc_mode = 1, then accel_lp_clk_sel register can’t be set to 0 as the RTC function requires the accel_lp_clk_sel = 1.).
 * 4) Configure the SIGP control registers:
 *        accel_src_ctrl = {0, 1}; gyro_src_ctrl = {0, 1}.
 *
 * From now on the STC feature is disabled, and the user can configure the device as needed. All power-mode registers can now be changed as desired,
 */
#define REG_SIFS_I3C_STC_CFG_GETXTIME_STC_MODE_POS      0x03
#define REG_SIFS_I3C_STC_CFG_GETXTIME_STC_MODE_MASK     (0x01 << REG_SIFS_I3C_STC_CFG_GETXTIME_STC_MODE_POS)

/*
 * asynctime0_dis
 * 1: Disable asynchronouse timing control mode 0 operation.
 */
#define REG_SIFS_I3C_STC_CFG_ASYNCTIME0_DIS_POS      0x04
#define REG_SIFS_I3C_STC_CFG_ASYNCTIME0_DIS_MASK     (0x01 << REG_SIFS_I3C_STC_CFG_ASYNCTIME0_DIS_POS)

/*
 * aux1_i3c_ibi_en
 * Enable/disable the IBI feature in the AUX1 I3C Slave. This is a static OTP bit. When the trim value is 0, it resets all the IBI control registers and prevents any IBIs from being triggered. After OTP trim values have been loaded to registers, this bit is not meant to be used to enable/disable IBIs.
 */
#define REG_SIFS_I3C_STC_CFG_AUX1_I3C_IBI_EN_POS      0x05
#define REG_SIFS_I3C_STC_CFG_AUX1_I3C_IBI_EN_MASK     (0x01 << REG_SIFS_I3C_STC_CFG_AUX1_I3C_IBI_EN_POS)



/*
 * REG_PSEQ_FORCE_CTRL_0
 * Register Name : PSEQ_FORCE_CTRL_0
 */

/*
 * en_dvdd_sw_comp_d2a
 * When at b01 forces en_dvdd_sw_comp_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_0_EN_DVDD_SW_COMP_D2A_POS      0x00
#define REG_PSEQ_FORCE_CTRL_0_EN_DVDD_SW_COMP_D2A_MASK     0x03

/*
 * en_dvdd_sw_d2a
 * When at b01 forces en_dvdd_sw_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_0_EN_DVDD_SW_D2A_POS      0x02
#define REG_PSEQ_FORCE_CTRL_0_EN_DVDD_SW_D2A_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_0_EN_DVDD_SW_D2A_POS)

/*
 * en_gyro_drv_dcc_d2a
 * When at b01 forces en_gyro_drv_dcc_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_0_EN_GYRO_DRV_DCC_D2A_POS      0x04
#define REG_PSEQ_FORCE_CTRL_0_EN_GYRO_DRV_DCC_D2A_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_0_EN_GYRO_DRV_DCC_D2A_POS)

/*
 * en_gyro_drv_dig_phs_d2a
 * When at b01 forces en_gyro_drv_dig_phs_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_0_EN_GYRO_DRV_DIG_PHS_D2A_POS      0x06
#define REG_PSEQ_FORCE_CTRL_0_EN_GYRO_DRV_DIG_PHS_D2A_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_0_EN_GYRO_DRV_DIG_PHS_D2A_POS)



/*
 * REG_PSEQ_FORCE_CTRL_1
 * Register Name : PSEQ_FORCE_CTRL_1
 */

/*
 * en_gyro_pll_calib_d2a
 * When at b01 forces en_gyro_pll_calib_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_1_EN_GYRO_PLL_CALIB_D2A_POS      0x00
#define REG_PSEQ_FORCE_CTRL_1_EN_GYRO_PLL_CALIB_D2A_MASK     0x03

/*
 * en_gyro_pll_dcc_d2a
 * When at b01 forces en_gyro_pll_dcc_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_1_EN_GYRO_PLL_DCC_D2A_POS      0x02
#define REG_PSEQ_FORCE_CTRL_1_EN_GYRO_PLL_DCC_D2A_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_1_EN_GYRO_PLL_DCC_D2A_POS)

/*
 * gyro_dmd_sync_b_d2d
 * When at b01 forces gyro_dmd_sync_b_d2d at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_1_GYRO_DMD_SYNC_B_D2D_POS      0x04
#define REG_PSEQ_FORCE_CTRL_1_GYRO_DMD_SYNC_B_D2D_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_1_GYRO_DMD_SYNC_B_D2D_POS)

/*
 * gyro_drv_agc_on_a2d
 * When at b01 forces gyro_drv_agc_on_a2d at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_1_GYRO_DRV_AGC_ON_A2D_POS      0x06
#define REG_PSEQ_FORCE_CTRL_1_GYRO_DRV_AGC_ON_A2D_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_1_GYRO_DRV_AGC_ON_A2D_POS)



/*
 * REG_PSEQ_FORCE_CTRL_2
 * Register Name : PSEQ_FORCE_CTRL_2
 */

/*
 * gx_sc2v_mems_disconnect_d2a
 * When at b01 forces gx_sc2v_mems_disconnect_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_2_GX_SC2V_MEMS_DISCONNECT_D2A_POS      0x00
#define REG_PSEQ_FORCE_CTRL_2_GX_SC2V_MEMS_DISCONNECT_D2A_MASK     0x03

/*
 * gy_sc2v_mems_disconnect_d2a
 * When at b01 forces gy_sc2v_mems_disconnect_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_2_GY_SC2V_MEMS_DISCONNECT_D2A_POS      0x02
#define REG_PSEQ_FORCE_CTRL_2_GY_SC2V_MEMS_DISCONNECT_D2A_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_2_GY_SC2V_MEMS_DISCONNECT_D2A_POS)

/*
 * gz_sc2v_mems_disconnect_d2a
 * When at b01 forces gz_sc2v_mems_disconnect_d2a at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_2_GZ_SC2V_MEMS_DISCONNECT_D2A_POS      0x04
#define REG_PSEQ_FORCE_CTRL_2_GZ_SC2V_MEMS_DISCONNECT_D2A_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_2_GZ_SC2V_MEMS_DISCONNECT_D2A_POS)

/*
 * gyro_pll_ref_clk_rdy_a2d
 * When at b01 forces gyro_pll_ref_clk_rdy_a2d at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_2_GYRO_PLL_REF_CLK_RDY_A2D_POS      0x06
#define REG_PSEQ_FORCE_CTRL_2_GYRO_PLL_REF_CLK_RDY_A2D_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_2_GYRO_PLL_REF_CLK_RDY_A2D_POS)



/*
 * REG_PSEQ_FORCE_CTRL_3
 * Register Name : PSEQ_FORCE_CTRL_3
 */

/*
 * pseq_iso_en
 * When at b01 forces pseq_iso_en at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_3_PSEQ_ISO_EN_POS      0x00
#define REG_PSEQ_FORCE_CTRL_3_PSEQ_ISO_EN_MASK     0x03

/*
 * pseq_sw_clk_en
 * When at b01 forces pseq_sw_clk_en at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_3_PSEQ_SW_CLK_EN_POS      0x02
#define REG_PSEQ_FORCE_CTRL_3_PSEQ_SW_CLK_EN_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_3_PSEQ_SW_CLK_EN_POS)

/*
 * rst_gyro_dmd_b_d2d
 * When at b01 forces rst_gyro_dmd_b_d2d at '1', when at b10 forces at '0'. b00 releases any forcing
 */
#define REG_PSEQ_FORCE_CTRL_3_RST_GYRO_DMD_B_D2D_POS      0x04
#define REG_PSEQ_FORCE_CTRL_3_RST_GYRO_DMD_B_D2D_MASK     (0x03 << REG_PSEQ_FORCE_CTRL_3_RST_GYRO_DMD_B_D2D_POS)

/*
 * en_clk_gyro_2p048m_d2d
 * When at b1 forces en_clk_gyro_2p048m_d2d at '1'.
 */
#define REG_PSEQ_FORCE_CTRL_3_EN_CLK_GYRO_2P048M_D2D_POS      0x06
#define REG_PSEQ_FORCE_CTRL_3_EN_CLK_GYRO_2P048M_D2D_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_3_EN_CLK_GYRO_2P048M_D2D_POS)

/*
 * en_clk_gyro_512k_d2a
 * When at b1 forces en_clk_gyro_512k_d2a at '1'.
 */
#define REG_PSEQ_FORCE_CTRL_3_EN_CLK_GYRO_512K_D2A_POS      0x07
#define REG_PSEQ_FORCE_CTRL_3_EN_CLK_GYRO_512K_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_3_EN_CLK_GYRO_512K_D2A_POS)



/*
 * REG_PSEQ_FORCE_CTRL_4
 * Register Name : PSEQ_FORCE_CTRL_4
 */

/*
 * en_clk_gyro_6p144m_d2d
 * When at b1 forces en_clk_gyro_6p144m_d2d at '1'.
 */
#define REG_PSEQ_FORCE_CTRL_4_EN_CLK_GYRO_6P144M_D2D_POS      0x00
#define REG_PSEQ_FORCE_CTRL_4_EN_CLK_GYRO_6P144M_D2D_MASK     0x01

/*
 * gyro_cp25v_cprdy_a2d
 * When at b1 forces gyro_cp25v_cprdy_a2d at '1'.
 */
#define REG_PSEQ_FORCE_CTRL_4_GYRO_CP25V_CPRDY_A2D_POS      0x01
#define REG_PSEQ_FORCE_CTRL_4_GYRO_CP25V_CPRDY_A2D_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_GYRO_CP25V_CPRDY_A2D_POS)

/*
 * gyro_drv_idle_state_a2d
 * When at b0 forces gyro_drv_idle_state_a2d at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_4_GYRO_DRV_IDLE_STATE_A2D_POS      0x02
#define REG_PSEQ_FORCE_CTRL_4_GYRO_DRV_IDLE_STATE_A2D_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_GYRO_DRV_IDLE_STATE_A2D_POS)

/*
 * pd_gx_dmd_b_d2a
 * When at b0 forces pd_gx_dmd_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_4_PD_GX_DMD_B_D2A_POS      0x03
#define REG_PSEQ_FORCE_CTRL_4_PD_GX_DMD_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_PD_GX_DMD_B_D2A_POS)

/*
 * pd_gy_dmd_b_d2a
 * When at b0 forces pd_gy_dmd_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_4_PD_GY_DMD_B_D2A_POS      0x04
#define REG_PSEQ_FORCE_CTRL_4_PD_GY_DMD_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_PD_GY_DMD_B_D2A_POS)

/*
 * pd_gz_dmd_b_d2a
 * When at b0 forces pd_gz_dmd_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_4_PD_GZ_DMD_B_D2A_POS      0x05
#define REG_PSEQ_FORCE_CTRL_4_PD_GZ_DMD_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_PD_GZ_DMD_B_D2A_POS)

/*
 * pd_gx_sc2v_b_d2a
 * When at b0 forces pd_gx_sc2v_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_4_PD_GX_SC2V_B_D2A_POS      0x06
#define REG_PSEQ_FORCE_CTRL_4_PD_GX_SC2V_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_PD_GX_SC2V_B_D2A_POS)

/*
 * pd_gy_sc2v_b_d2a
 * When at b0 forces pd_gy_sc2v_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_4_PD_GY_SC2V_B_D2A_POS      0x07
#define REG_PSEQ_FORCE_CTRL_4_PD_GY_SC2V_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_4_PD_GY_SC2V_B_D2A_POS)



/*
 * REG_PSEQ_FORCE_CTRL_5
 * Register Name : PSEQ_FORCE_CTRL_5
 */

/*
 * pd_gz_sc2v_b_d2a
 * When at b0 forces pd_gz_sc2v_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PD_GZ_SC2V_B_D2A_POS      0x00
#define REG_PSEQ_FORCE_CTRL_5_PD_GZ_SC2V_B_D2A_MASK     0x01

/*
 * pd_gyro_bias_master_b_d2a
 * When at b0 forces pd_gyro_bias_master_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_BIAS_MASTER_B_D2A_POS      0x01
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_BIAS_MASTER_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PD_GYRO_BIAS_MASTER_B_D2A_POS)

/*
 * pd_gyro_cp25v_b_d2a
 * When at b0 forces pd_gyro_cp25v_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_CP25V_B_D2A_POS      0x02
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_CP25V_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PD_GYRO_CP25V_B_D2A_POS)

/*
 * pd_gyro_dc2v_b_d2a
 * When at b0 forces pd_gyro_dc2v_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_DC2V_B_D2A_POS      0x03
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_DC2V_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PD_GYRO_DC2V_B_D2A_POS)

/*
 * pd_gyro_drv_b_d2a
 * When at b0 forces pd_gyro_drv_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_DRV_B_D2A_POS      0x04
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_DRV_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PD_GYRO_DRV_B_D2A_POS)

/*
 * pd_gyro_pll_b_d2a
 * When at b0 forces pd_gyro_pll_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_PLL_B_D2A_POS      0x05
#define REG_PSEQ_FORCE_CTRL_5_PD_GYRO_PLL_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PD_GYRO_PLL_B_D2A_POS)

/*
 * pseq_en_gx_dmd_d2d
 * When at b0 forces pseq_en_gx_dmd_d2d at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PSEQ_EN_GX_DMD_D2D_POS      0x06
#define REG_PSEQ_FORCE_CTRL_5_PSEQ_EN_GX_DMD_D2D_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PSEQ_EN_GX_DMD_D2D_POS)

/*
 * pseq_en_gy_dmd_d2d
 * When at b0 forces pseq_en_gy_dmd_d2d at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_5_PSEQ_EN_GY_DMD_D2D_POS      0x07
#define REG_PSEQ_FORCE_CTRL_5_PSEQ_EN_GY_DMD_D2D_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_5_PSEQ_EN_GY_DMD_D2D_POS)



/*
 * REG_PSEQ_FORCE_CTRL_6
 * Register Name : PSEQ_FORCE_CTRL_6
 */

/*
 * pseq_en_gz_dmd_d2d
 * When at b0 forces pseq_en_gz_dmd_d2d at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_PSEQ_EN_GZ_DMD_D2D_POS      0x00
#define REG_PSEQ_FORCE_CTRL_6_PSEQ_EN_GZ_DMD_D2D_MASK     0x01

/*
 * rst_gx_adc_b_d2a
 * When at b0 forces rst_gx_adc_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_RST_GX_ADC_B_D2A_POS      0x01
#define REG_PSEQ_FORCE_CTRL_6_RST_GX_ADC_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_6_RST_GX_ADC_B_D2A_POS)

/*
 * rst_gy_adc_b_d2a
 * When at b0 forces rst_gy_adc_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_RST_GY_ADC_B_D2A_POS      0x02
#define REG_PSEQ_FORCE_CTRL_6_RST_GY_ADC_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_6_RST_GY_ADC_B_D2A_POS)

/*
 * rst_gz_adc_b_d2a
 * When at b0 forces rst_gz_adc_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_RST_GZ_ADC_B_D2A_POS      0x03
#define REG_PSEQ_FORCE_CTRL_6_RST_GZ_ADC_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_6_RST_GZ_ADC_B_D2A_POS)

/*
 * rst_gyro_dc2v_b_d2a
 * When at b0 forces rst_gyro_dc2v_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_RST_GYRO_DC2V_B_D2A_POS      0x04
#define REG_PSEQ_FORCE_CTRL_6_RST_GYRO_DC2V_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_6_RST_GYRO_DC2V_B_D2A_POS)

/*
 * rst_gyro_drv_b_d2a
 * When at b0 forces rst_gyro_drv_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_RST_GYRO_DRV_B_D2A_POS      0x05
#define REG_PSEQ_FORCE_CTRL_6_RST_GYRO_DRV_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_6_RST_GYRO_DRV_B_D2A_POS)

/*
 * rst_gyro_pll_b_d2a
 * When at b0 forces rst_gyro_pll_b_d2a at '0'.
 */
#define REG_PSEQ_FORCE_CTRL_6_RST_GYRO_PLL_B_D2A_POS      0x06
#define REG_PSEQ_FORCE_CTRL_6_RST_GYRO_PLL_B_D2A_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_6_RST_GYRO_PLL_B_D2A_POS)



/*
 * REG_PSEQ_FORCE_CTRL_7
 * Register Name : PSEQ_FORCE_CTRL_7
 */

/*
 * gyro_clk_6p144m_done_dis_trim
 * When at b1, leaves gyro_clk_6p144m active as long as  the Gyro Drive is ON.
 */
#define REG_PSEQ_FORCE_CTRL_7_GYRO_CLK_6P144M_DONE_DIS_TRIM_POS      0x00
#define REG_PSEQ_FORCE_CTRL_7_GYRO_CLK_6P144M_DONE_DIS_TRIM_MASK     0x01

/*
 * en_clk_tmp_3m_ovrd
 * When at b1, forces active the 3 MHz clock going to the Temp Sensor.
 */
#define REG_PSEQ_FORCE_CTRL_7_EN_CLK_TMP_3M_OVRD_POS      0x01
#define REG_PSEQ_FORCE_CTRL_7_EN_CLK_TMP_3M_OVRD_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_7_EN_CLK_TMP_3M_OVRD_POS)

/*
 * pd_tmp_b_ovrd
 * When at b1, forces at b1 pd_tmp_b_d2a.
 */
#define REG_PSEQ_FORCE_CTRL_7_PD_TMP_B_OVRD_POS      0x02
#define REG_PSEQ_FORCE_CTRL_7_PD_TMP_B_OVRD_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_7_PD_TMP_B_OVRD_POS)

/*
 * pd_tmp_bias_ovrd
 * When at b1, forces at b1 pd_tmp_bias_d2a.
 */
#define REG_PSEQ_FORCE_CTRL_7_PD_TMP_BIAS_OVRD_POS      0x03
#define REG_PSEQ_FORCE_CTRL_7_PD_TMP_BIAS_OVRD_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_7_PD_TMP_BIAS_OVRD_POS)

/*
 * cmos_only
 * When at b1,signals to the PSEQ that the part is a CMOS only one. This bit is required to be set in CMOS only scenario, to have the Gyro Drive power-up correctly.
 */
#define REG_PSEQ_FORCE_CTRL_7_CMOS_ONLY_POS      0x04
#define REG_PSEQ_FORCE_CTRL_7_CMOS_ONLY_MASK     (0x01 << REG_PSEQ_FORCE_CTRL_7_CMOS_ONLY_POS)



/*
 * REG_CKGA_CONFIG
 * Register Name : CKGA_CONFIG
 */

/*
 * dis_gyro_sync_2m_rdy
 * Disables the alignment process for the 2.048MHz clock output when the PLL clock source is selected.  When asserted, the gyro_sync_2m_rdy_d2a output signal of the CKGA never goes low.
 */
#define REG_CKGA_CONFIG_DIS_GYRO_SYNC_2M_RDY_POS      0x00
#define REG_CKGA_CONFIG_DIS_GYRO_SYNC_2M_RDY_MASK     0x01

/*
 * force_gyro_sync_2m_rdy
 * Override signal to assert the gyro_sync_2m_rdy_d2a signal no matter what the actual state of the alignment is.
 */
#define REG_CKGA_CONFIG_FORCE_GYRO_SYNC_2M_RDY_POS      0x01
#define REG_CKGA_CONFIG_FORCE_GYRO_SYNC_2M_RDY_MASK     (0x01 << REG_CKGA_CONFIG_FORCE_GYRO_SYNC_2M_RDY_POS)

/*
 * REG_CKGA_RCOSC_READY_TRIM
 * Register Name : CKGA_RCOSC_READY_TRIM
 */

/*
 * rcosc_ready_t_trim
 * Selects the number of RCOSC clock cycles before it is declared ready:
 * 0: 190 cycles
 * 1: 200 cycles
 * 2: 210 cycles
 * 3: 220 cycles
 * 4: 250 cycles
 * 5: 300 cycles
 * 6: 350 cycles
 * 7: 400 cycles
 */
#define REG_CKGA_RCOSC_READY_TRIM_RCOSC_READY_T_TRIM_POS      0x00
#define REG_CKGA_RCOSC_READY_TRIM_RCOSC_READY_T_TRIM_MASK     0x07



/*
 * REG_IOC_PADS_TP_OVRD
 * Register Name : IOC_PADS_TP_OVRD
 */

/*
 * tp0_from_pads_ovrd_sel
 * Test Port 0 override select.This register is not used in Newport.
 */
#define REG_IOC_PADS_TP_OVRD_TP0_FROM_PADS_OVRD_SEL_POS      0x00
#define REG_IOC_PADS_TP_OVRD_TP0_FROM_PADS_OVRD_SEL_MASK     0x01

/*
 * tp1_from_pads_ovrd_sel
 * Test Port 1 override select
 */
#define REG_IOC_PADS_TP_OVRD_TP1_FROM_PADS_OVRD_SEL_POS      0x01
#define REG_IOC_PADS_TP_OVRD_TP1_FROM_PADS_OVRD_SEL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP1_FROM_PADS_OVRD_SEL_POS)

/*
 * tp2_from_pads_ovrd_sel
 * Test Port 2 override select
 */
#define REG_IOC_PADS_TP_OVRD_TP2_FROM_PADS_OVRD_SEL_POS      0x02
#define REG_IOC_PADS_TP_OVRD_TP2_FROM_PADS_OVRD_SEL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP2_FROM_PADS_OVRD_SEL_POS)

/*
 * tp3_from_pads_ovrd_sel
 * Test Port 3 override select
 */
#define REG_IOC_PADS_TP_OVRD_TP3_FROM_PADS_OVRD_SEL_POS      0x03
#define REG_IOC_PADS_TP_OVRD_TP3_FROM_PADS_OVRD_SEL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP3_FROM_PADS_OVRD_SEL_POS)

/*
 * tp0_from_pads_ovrd_val
 * Test Port 0 override value. This register is not used in Newport.
 */
#define REG_IOC_PADS_TP_OVRD_TP0_FROM_PADS_OVRD_VAL_POS      0x04
#define REG_IOC_PADS_TP_OVRD_TP0_FROM_PADS_OVRD_VAL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP0_FROM_PADS_OVRD_VAL_POS)

/*
 * tp1_from_pads_ovrd_val
 * Test Port 1 override value
 */
#define REG_IOC_PADS_TP_OVRD_TP1_FROM_PADS_OVRD_VAL_POS      0x05
#define REG_IOC_PADS_TP_OVRD_TP1_FROM_PADS_OVRD_VAL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP1_FROM_PADS_OVRD_VAL_POS)

/*
 * tp2_from_pads_ovrd_val
 * Test Port 2 override value
 */
#define REG_IOC_PADS_TP_OVRD_TP2_FROM_PADS_OVRD_VAL_POS      0x06
#define REG_IOC_PADS_TP_OVRD_TP2_FROM_PADS_OVRD_VAL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP2_FROM_PADS_OVRD_VAL_POS)

/*
 * tp3_from_pads_ovrd_val
 * Test Port 3 override value
 */
#define REG_IOC_PADS_TP_OVRD_TP3_FROM_PADS_OVRD_VAL_POS      0x07
#define REG_IOC_PADS_TP_OVRD_TP3_FROM_PADS_OVRD_VAL_MASK     (0x01 << REG_IOC_PADS_TP_OVRD_TP3_FROM_PADS_OVRD_VAL_POS)



/*
 * REG_IOC_PADS_CONFIG0
 * Register Name : IOC_PADS_CONFIG0
 */

/*
 * tp0_oe
 * Test Port 0 output enable
 */
#define REG_IOC_PADS_CONFIG0_TP0_OE_POS      0x00
#define REG_IOC_PADS_CONFIG0_TP0_OE_MASK     0x01

/*
 * tp1_oe
 * Test Port 1 output enable
 */
#define REG_IOC_PADS_CONFIG0_TP1_OE_POS      0x01
#define REG_IOC_PADS_CONFIG0_TP1_OE_MASK     (0x01 << REG_IOC_PADS_CONFIG0_TP1_OE_POS)

/*
 * tp2_oe
 * Test Port 2 output enable
 */
#define REG_IOC_PADS_CONFIG0_TP2_OE_POS      0x02
#define REG_IOC_PADS_CONFIG0_TP2_OE_MASK     (0x01 << REG_IOC_PADS_CONFIG0_TP2_OE_POS)

/*
 * tp3_oe
 * Test Port 3 output enable
 */
#define REG_IOC_PADS_CONFIG0_TP3_OE_POS      0x03
#define REG_IOC_PADS_CONFIG0_TP3_OE_MASK     (0x01 << REG_IOC_PADS_CONFIG0_TP3_OE_POS)

/*
 * drdy_intr_polarity
 * DRDY interrupt polarity:
 * 0 : Active low
 * 1 : Active high
 */
#define REG_IOC_PADS_CONFIG0_DRDY_INTR_POLARITY_POS      0x04
#define REG_IOC_PADS_CONFIG0_DRDY_INTR_POLARITY_MASK     (0x01 << REG_IOC_PADS_CONFIG0_DRDY_INTR_POLARITY_POS)

/*
 * fsync_polarity
 * FSYNC pin polarity
 * 0: Active low
 * 1: Active high
 */
#define REG_IOC_PADS_CONFIG0_FSYNC_POLARITY_POS      0x05
#define REG_IOC_PADS_CONFIG0_FSYNC_POLARITY_MASK     (0x01 << REG_IOC_PADS_CONFIG0_FSYNC_POLARITY_POS)

/*
 * pads_chop_freq_sel
 * Chop Frequency Select :
 * 0 : 0
 * 1 : 1
 * 2 : 1.024MHz (50/50 duty cycle)
 * 3 : 3.072MHz (50/50 duty cycle)
 */
#define REG_IOC_PADS_CONFIG0_PADS_CHOP_FREQ_SEL_POS      0x06
#define REG_IOC_PADS_CONFIG0_PADS_CHOP_FREQ_SEL_MASK     (0x03 << REG_IOC_PADS_CONFIG0_PADS_CHOP_FREQ_SEL_POS)



/*
 * REG_IOC_PADS_CONFIG1
 * Register Name : IOC_PADS_CONFIG1
 */

/*
 * aux_sdi_tp1_od
 * AUX SDI (TP1) pad open drain setting
 */
#define REG_IOC_PADS_CONFIG1_AUX_SDI_TP1_OD_POS      0x01
#define REG_IOC_PADS_CONFIG1_AUX_SDI_TP1_OD_MASK     (0x01 << REG_IOC_PADS_CONFIG1_AUX_SDI_TP1_OD_POS)

/*
 * aux_sclk_tp2_od
 * AUX SCLK (TP2) pad open drain setting
 */
#define REG_IOC_PADS_CONFIG1_AUX_SCLK_TP2_OD_POS      0x02
#define REG_IOC_PADS_CONFIG1_AUX_SCLK_TP2_OD_MASK     (0x01 << REG_IOC_PADS_CONFIG1_AUX_SCLK_TP2_OD_POS)

/*
 * aux_cs_tp3_od
 * AUX CS (TP3) pad open drain setting
 */
#define REG_IOC_PADS_CONFIG1_AUX_CS_TP3_OD_POS      0x03
#define REG_IOC_PADS_CONFIG1_AUX_CS_TP3_OD_MASK     (0x01 << REG_IOC_PADS_CONFIG1_AUX_CS_TP3_OD_POS)



/*
 * REG_IOC_VOHVOL
 * Register Name : IOC_VOHVOL
 */

/*
 * vohvol_en
 * Enable VOVVOL Test
 */
#define REG_IOC_VOHVOL_VOHVOL_EN_POS      0x00
#define REG_IOC_VOHVOL_VOHVOL_EN_MASK     0x01

/*
 * vohvol_sel
 * VOHVOL select for setting output
 */
#define REG_IOC_VOHVOL_VOHVOL_SEL_POS      0x01
#define REG_IOC_VOHVOL_VOHVOL_SEL_MASK     (0x07 << REG_IOC_VOHVOL_VOHVOL_SEL_POS)



/*
 * REG_IOC_VIHVIL
 * Register Name : IOC_VIHVIL
 */

/*
 * tmux_sel
 * TMUX select for PAD test
 */
#define REG_IOC_VIHVIL_TMUX_SEL_POS      0x00
#define REG_IOC_VIHVIL_TMUX_SEL_MASK     0xff



/*
 * REG_BAR_CONFIG
 * Register Name : BAR_CONFIG
 */

/*
 * bar_rst
 * Reset BAR registers
 */
#define REG_BAR_CONFIG_BAR_RST_POS      0x00
#define REG_BAR_CONFIG_BAR_RST_MASK     0x01

/*
 * bar_use_otp
 * OTP CRC error protection disabled:
 * 0 : CRC error protection for OTP trimmable registers is active
 * 1 : CRC error protection for OTP trimmable registers is disabled
 */
#define REG_BAR_CONFIG_BAR_USE_OTP_POS      0x01
#define REG_BAR_CONFIG_BAR_USE_OTP_MASK     (0x01 << REG_BAR_CONFIG_BAR_USE_OTP_POS)



/*
 * REG_IREG_OTP_STATUS
 * Register Name : IREG_OTP_STATUS
 */

/*
 * otp_valid_bank
 * Specifies valid bank of otp
 */
#define REG_IREG_OTP_STATUS_OTP_VALID_BANK_POS      0x00
#define REG_IREG_OTP_STATUS_OTP_VALID_BANK_MASK     0x03



/*
 * REG_OTP_CALCULATED_CRC_0
 * Register Name : OTP_CALCULATED_CRC_0
 */

/*
 * otp_calculated_crc
 * CRC CCITT-16 checksum calculated
 */
#define REG_OTP_CALCULATED_CRC_0_OTP_CALCULATED_CRC_POS      0x00
#define REG_OTP_CALCULATED_CRC_0_OTP_CALCULATED_CRC_MASK     0xff



/*
 * REG_OTP_CALCULATED_CRC_1
 * Register Name : OTP_CALCULATED_CRC_1
 */

/*
 * otp_calculated_crc
 * CRC CCITT-16 checksum calculated
 */
#define REG_OTP_CALCULATED_CRC_1_OTP_CALCULATED_CRC_POS      0x00
#define REG_OTP_CALCULATED_CRC_1_OTP_CALCULATED_CRC_MASK     0xff



/*
 * REG_HEAT_CTRL1
 * Register Name : HEAT_CTRL1
 */

/*
 * heater_feature_disable
 * When 1 it forces heater feature disabled
 */
#define REG_HEAT_CTRL1_HEATER_FEATURE_DISABLE_POS      0x00
#define REG_HEAT_CTRL1_HEATER_FEATURE_DISABLE_MASK     0x01



/*
 * REG_GYRO_SC2V
 * Register Name : GYRO_SC2V
 */

/*
 * gyro_sc2v_cont_mode_trim_d2d
 * [Supports Dynamic Change] SC2V mode of operation: 0 -> periodic reset, 1 -> continuous mode
 */
#define REG_GYRO_SC2V_GYRO_SC2V_CONT_MODE_TRIM_D2D_POS      0x00
#define REG_GYRO_SC2V_GYRO_SC2V_CONT_MODE_TRIM_D2D_MASK     0x01



/*
 * REG_DTMD_DEBUG_CONFIG
 * Register Name : DTMD_DEBUG_CONFIG
 */

/*
 * dtmd_en
 * DTMD enable:
 * 0 : DTMD test mode is disabled
 * 1 : DTMD test mode is enabled
 */
#define REG_DTMD_DEBUG_CONFIG_DTMD_EN_POS      0x00
#define REG_DTMD_DEBUG_CONFIG_DTMD_EN_MASK     0x01

/*
 * dtp_aux1_debug
 * Debug AUX1 access:
 * 0 : Normal access
 * 1 : AP will mux with AUX1 and access AUX1 registers
 */
#define REG_DTMD_DEBUG_CONFIG_DTP_AUX1_DEBUG_POS      0x01
#define REG_DTMD_DEBUG_CONFIG_DTP_AUX1_DEBUG_MASK     (0x01 << REG_DTMD_DEBUG_CONFIG_DTP_AUX1_DEBUG_POS)

/*
 * dtp_aux2_debug
 * Debug AUX2 access:
 * 0 : Normal access
 * 1 : AP will mux with AUX2 and access AUX2 registers
 */
#define REG_DTMD_DEBUG_CONFIG_DTP_AUX2_DEBUG_POS      0x02
#define REG_DTMD_DEBUG_CONFIG_DTP_AUX2_DEBUG_MASK     (0x01 << REG_DTMD_DEBUG_CONFIG_DTP_AUX2_DEBUG_POS)

/*
 * dtmd_oe_mask
 * DTMD output pin mask, Width will be DTMD_NDTP parameter
 * Set individual bits to mask the output for the particular DTP pin
 * Value 0 will mask the output enable and disables it.
 * Eg: 4'b1101 : Will tie of dtp_to_ana_d2d[1] as '0' and set dtp_to_ana_oe_d2d[1] as '0' , while rest of them can be connected as output
 */
#define REG_DTMD_DEBUG_CONFIG_DTMD_OE_MASK_POS      0x04
#define REG_DTMD_DEBUG_CONFIG_DTMD_OE_MASK_MASK     (0x0f << REG_DTMD_DEBUG_CONFIG_DTMD_OE_MASK_POS)



/*
 * REG_DTMD_OUT_IN_SEL
 * Register Name : DTMD_OUT_IN_SEL
 */

/*
 * dtmd_out_ip_sel
 * Selects the IP that need to be enabled for DTMD out
 * 0 : No IP selected
 * 1-Max: Number of IP selected
 */
#define REG_DTMD_OUT_IN_SEL_DTMD_OUT_IP_SEL_POS      0x00
#define REG_DTMD_OUT_IN_SEL_DTMD_OUT_IP_SEL_MASK     0x1f

/*
 * dtmd_in_mode_sel
 * Selects the IP that need to be enabled for DTMD in
 * 0 : No IP selected
 * 1-Max : Number of DTMD IN mode selected
 */
#define REG_DTMD_OUT_IN_SEL_DTMD_IN_MODE_SEL_POS      0x05
#define REG_DTMD_OUT_IN_SEL_DTMD_IN_MODE_SEL_MASK     (0x07 << REG_DTMD_OUT_IN_SEL_DTMD_IN_MODE_SEL_POS)



/*
 * REG_DTMD_OUT_MODE_SEL
 * Register Name : DTMD_OUT_MODE_SEL
 */

/*
 * dtmd_out_mode_sel
 * Selects the output test modes.  This goes to all Ips
 */
#define REG_DTMD_OUT_MODE_SEL_DTMD_OUT_MODE_SEL_POS      0x00
#define REG_DTMD_OUT_MODE_SEL_DTMD_OUT_MODE_SEL_MASK     0x3f



/*
 * REG_RESERVED_OTP_BYTE3
 * Register Name : RESERVED_OTP_BYTE3
 */

/*
 * reserved_otp_byte3
 * Reserve otp byte3
 */
#define REG_RESERVED_OTP_BYTE3_RESERVED_OTP_BYTE3_POS      0x00
#define REG_RESERVED_OTP_BYTE3_RESERVED_OTP_BYTE3_MASK     0x01



/*
 * REG_RESERVED_OTP_BYTE4
 * Register Name : RESERVED_OTP_BYTE4
 */

/*
 * reserved_otp_byte4
 * Reserve otp byte4
 */
#define REG_RESERVED_OTP_BYTE4_RESERVED_OTP_BYTE4_POS      0x00
#define REG_RESERVED_OTP_BYTE4_RESERVED_OTP_BYTE4_MASK     0x01



/*
 * REG_IPREG_MISC
 * Register Name : IPREG_MISC
 */

/*
 * general_dbg_en
 * Debug enable feature used for general purpose
 */
#define REG_IPREG_MISC_GENERAL_DBG_EN_POS      0x00
#define REG_IPREG_MISC_GENERAL_DBG_EN_MASK     0x01

/*
 * general_dbg2_en
 * Debug enable feature used for general purpose 2
 */
#define REG_IPREG_MISC_GENERAL_DBG2_EN_POS      0x02
#define REG_IPREG_MISC_GENERAL_DBG2_EN_MASK     (0x01 << REG_IPREG_MISC_GENERAL_DBG2_EN_POS)



/*
 * REG_DIG_SPARE0
 * Register Name : DIG_SPARE0
 */

/*
 * dig_spare0
 * Non-OTP spare register
 */
#define REG_DIG_SPARE0_DIG_SPARE0_POS      0x00
#define REG_DIG_SPARE0_DIG_SPARE0_MASK     0xff



/*
 * REG_DIG_SPARE1
 * Register Name : DIG_SPARE1
 */

/*
 * dig_spare1
 * Non-OTP spare register
 */
#define REG_DIG_SPARE1_DIG_SPARE1_POS      0x00
#define REG_DIG_SPARE1_DIG_SPARE1_MASK     0xff



/*
 * REG_DIG_SPARE2
 * Register Name : DIG_SPARE2
 */

/*
 * dig_spare2
 * OTP spare register
 */
#define REG_DIG_SPARE2_DIG_SPARE2_POS      0x00
#define REG_DIG_SPARE2_DIG_SPARE2_MASK     0xff



/*
 * REG_DIG_SPARE3
 * Register Name : DIG_SPARE3
 */

/*
 * dig_spare3
 * OTP spare register
 */
#define REG_DIG_SPARE3_DIG_SPARE3_POS      0x00
#define REG_DIG_SPARE3_DIG_SPARE3_MASK     0xff



/*
 * REG_DIG_SPARE4
 * Register Name : DIG_SPARE4
 */

/*
 * dig_spare4
 * OTP spare register
 */
#define REG_DIG_SPARE4_DIG_SPARE4_POS      0x00
#define REG_DIG_SPARE4_DIG_SPARE4_MASK     0xff



/*
 * REG_DIG_SPARE5
 * Register Name : DIG_SPARE5
 */

/*
 * dig_spare5
 * OTP spare register
 */
#define REG_DIG_SPARE5_DIG_SPARE5_POS      0x00
#define REG_DIG_SPARE5_DIG_SPARE5_MASK     0xff



/*
 * REG_SA_KEY1_LAST_BYTE
 * Register Name : SA_KEY1_LAST_BYTE
 */

/*
 * sa_key1_last_byte
 * Last bye of authentication key copied from OTP on Power up
 */
#define REG_SA_KEY1_LAST_BYTE_SA_KEY1_LAST_BYTE_POS      0x00
#define REG_SA_KEY1_LAST_BYTE_SA_KEY1_LAST_BYTE_MASK     0xff



/*
 * REG_AUX1_INTF_CONFIG
 * Register Name : AUX1_INTF_CONFIG
 */

/*
 * aux1_i3c_sda_out_dly
 * Is used to add delay for AUX1 SIFS SDA signal from I3C slave to SIFS slave. This delay is applicable only when I3C slave IP is used for  both I3C or I2C operation. This delay is not applicable when in SPI mode, or using legacy I2C slave.
 *        0:  sda output delay = 1*6.4ns.
 *        1:  sda output delay = 2*6.4ns.
 *        2:  sda output delay = 3*6.4ns.
 *        3:  sda output delay = 4*6.4ns.
 *        4-7: delay bypassed
 */
#define REG_AUX1_INTF_CONFIG_AUX1_I3C_SDA_OUT_DLY_POS      0x00
#define REG_AUX1_INTF_CONFIG_AUX1_I3C_SDA_OUT_DLY_MASK     0x07



/*
 * REG_AUX1_SIFS_GETMXDS_MAXWR
 * Register Name : AUX1_SIFS_GETMXDS_MAXWR
 */

/*
 * aux1_getmxds_maxwr
 * Maximum Sustained Data Rate for non-CCC messages sent by Slave Device to Master Device for AUX1 I3C :
 * 0: fSCL Max (default value)
 * 1: 8 MHz
 * 2: 6 MHz
 * 3: 4 MHz
 * 4: 2 MHz
 * 5–7: Reserved for future use by the MIPI Alliance
 *
 * User can configure with Register[ ADDR: ‘d36] bit [2:0]
 */
#define REG_AUX1_SIFS_GETMXDS_MAXWR_AUX1_GETMXDS_MAXWR_POS      0x00
#define REG_AUX1_SIFS_GETMXDS_MAXWR_AUX1_GETMXDS_MAXWR_MASK     0x07



/*
 * REG_AUX1_SIFS_GETMXDS_MAXRD
 * Register Name : AUX1_SIFS_GETMXDS_MAXRD
 */

/*
 * aux1_getmxds_maxrd
 * [2:0]: max sustained data rate for non-CCC message from salve to host for AUX1 I3C.
 * [5:3]: Clock to data turn around time (Tsco).
 *        0: <= 8ns.
 *        1: <= 9ns.
 *        2: <= 10ns.
 *        3: <= 11ns.
 *        4: <= 12ns.
 *        5: reserved.
 *        6: reserved.
 *        7: > 12ns (see private agreement).
 */
#define REG_AUX1_SIFS_GETMXDS_MAXRD_AUX1_GETMXDS_MAXRD_POS      0x00
#define REG_AUX1_SIFS_GETMXDS_MAXRD_AUX1_GETMXDS_MAXRD_MASK     0x3f



/*
 * REG_OTP_EXPECTED_CRC_0
 * Register Name : OTP_EXPECTED_CRC_0
 */

/*
 * otp_expected_crc
 * CRC CCITT-16 checksum
 */
#define REG_OTP_EXPECTED_CRC_0_OTP_EXPECTED_CRC_POS      0x00
#define REG_OTP_EXPECTED_CRC_0_OTP_EXPECTED_CRC_MASK     0xff



/*
 * REG_OTP_EXPECTED_CRC_1
 * Register Name : OTP_EXPECTED_CRC_1
 */

/*
 * otp_expected_crc
 * CRC CCITT-16 checksum
 */
#define REG_OTP_EXPECTED_CRC_1_OTP_EXPECTED_CRC_POS      0x00
#define REG_OTP_EXPECTED_CRC_1_OTP_EXPECTED_CRC_MASK     0xff


/* ---------------------------------------------------------------------------
 * register DREG_BANK1
 * ---------------------------------------------------------------------------*/

/*
 * REG_INTF_CONFIG0
 * Register Name : INTF_CONFIG0
 */

/*
 * ap_spi_fuji_mode
 * 1: use special Fuji SPI mode. Refer to SPI document for detatils
 * 0: Conventional SPI mode
 */
#define REG_INTF_CONFIG0_AP_SPI_FUJI_MODE_POS      0x02
#define REG_INTF_CONFIG0_AP_SPI_FUJI_MODE_MASK     (0x01 << REG_INTF_CONFIG0_AP_SPI_FUJI_MODE_POS)

/*
 * REG_REG_MISC1
 * Register Name : REG_MISC1
 */

/*
 * osc_force_on
 * Forces the oscillator analog IP to be enabled (debug feature).  Note that if other analog circuits must be enabled at the same time or if a special power-up sequence must be followed, then this must be done separately using other override registers.
 * [0] = 1: Enables the EDOSC.
 * [1] = 1: Enables the RCOSC.
 * [2] = 1: Enables the PLL.
 * [3] = 1: Enables the external clock.
 */
#define REG_REG_MISC1_OSC_FORCE_ON_POS      0x04
#define REG_REG_MISC1_OSC_FORCE_ON_MASK     (0x0f << REG_REG_MISC1_OSC_FORCE_ON_POS)



/*
 * REG_REG_MISC3
 * Register Name : REG_MISC3
 */

/*
 * ref_force_on
 * Forces the reference clock sources to be enabled (debug feature).
 * [0] = 1: Enables the WUOSC.
 * [1] = 1: Enables the RTC, which must be provided on the CLKIN pad.
 */
#define REG_REG_MISC3_REF_FORCE_ON_POS      0x01
#define REG_REG_MISC3_REF_FORCE_ON_MASK     (0x03 << REG_REG_MISC3_REF_FORCE_ON_POS)

/*
 * REG_REG_MISC4
 * Register Name : REG_MISC4
 */

/*
 * req_ref_stb_ovrd
 * Overrides the request for the reference strobe (debug feature).  Note that this only forces the enable of a request, and cannot force the disable of a request.
 * [0] = 1: Enables the WUOSC strobe to the TMST.
 * [1] = 1: Enables the WUOSC strobe to the SMC.
 * [2] = 1: Enables the WUOSC strobe to the SIFS.
 * [3] = 1: Enables the RTC strobe to the SMC.
 * The reference clock source itself must be enabled too (see ref_force_on).
 */
#define REG_REG_MISC4_REQ_REF_STB_OVRD_POS      0x00
#define REG_REG_MISC4_REQ_REF_STB_OVRD_MASK     0x1f



/*
 * REG_REG_MISC0
 * Register Name : REG_MISC0
 */

/*
 * req_clk_all
 * [Supports Dynamic Change] Requests all IP clocks to be enabled (debug feature).
 */
#define REG_REG_MISC0_REQ_CLK_ALL_POS      0x00
#define REG_REG_MISC0_REQ_CLK_ALL_MASK     0x01

/*
 * dft_mode
 * DFT Mode
 */
#define REG_REG_MISC0_DFT_MODE_POS      0x01
#define REG_REG_MISC0_DFT_MODE_MASK     (0x0f << REG_REG_MISC0_DFT_MODE_POS)



/*
 * REG_DIG_SPARE6
 * Register Name : DIG_SPARE6
 */

/*
 * dig_spare6
 * OTP SPARE REGISTER
 */
#define REG_DIG_SPARE6_DIG_SPARE6_POS      0x00
#define REG_DIG_SPARE6_DIG_SPARE6_MASK     0xff



/*
 * REG_DIG_SPARE7
 * Register Name : DIG_SPARE7
 */

/*
 * dig_spare7
 * OTP SPARE REGISTER
 */
#define REG_DIG_SPARE7_DIG_SPARE7_POS      0x00
#define REG_DIG_SPARE7_DIG_SPARE7_MASK     0xff



/*
 * REG_INTF_COMM_ERR
 * Register Name : INTF_COMM_ERR
 */

/*
 * i3c_s0_err
 * Detect any of the following:
 *                                7’h3E / W
 *                                7’h5E / W
 *                                7’h6E / W
 *                                7’h76 / W
 *                                7’h7A / W
 *                                7’h7C / W
 *                                7’h7F / W
 *                                7’h7E / R
 * As per specification assert when above describe Address Header receive by I3C
 */
#define REG_INTF_COMM_ERR_I3C_S0_ERR_POS      0x00
#define REG_INTF_COMM_ERR_I3C_S0_ERR_MASK     0x01

/*
 * i3c_ccc_parity_err
 * If the I3C detects a parity error during a CCC code,
 * then the Slave will not be able to know that the I3C Bus has changed to HDR Mode if the CCC is ENTHDR.
 *
 * In order  to  avoid  this  situation,  if   the  I3C  detects  a  parity  error  during  a  CCC  code,  then  the  I3C  shall ignore the rest of the signal, until the HDR EXIT pattern is detected
 */
#define REG_INTF_COMM_ERR_I3C_CCC_PARITY_ERR_POS      0x01
#define REG_INTF_COMM_ERR_I3C_CCC_PARITY_ERR_MASK     (0x01 << REG_INTF_COMM_ERR_I3C_CCC_PARITY_ERR_POS)

/*
 * i3c_sdr_parity_err
 * Error will occur when I3C operating in SDR mode and parity check fail with any I3C message
 */
#define REG_INTF_COMM_ERR_I3C_SDR_PARITY_ERR_POS      0x02
#define REG_INTF_COMM_ERR_I3C_SDR_PARITY_ERR_MASK     (0x01 << REG_INTF_COMM_ERR_I3C_SDR_PARITY_ERR_POS)

/*
 * i3c_ddr_parity_err
 * Error occur when I3C operating in HDR-DDR mode check bad parity for both CMD and DATA
 */
#define REG_INTF_COMM_ERR_I3C_DDR_PARITY_ERR_POS      0x03
#define REG_INTF_COMM_ERR_I3C_DDR_PARITY_ERR_MASK     (0x01 << REG_INTF_COMM_ERR_I3C_DDR_PARITY_ERR_POS)

/*
 * i3c_ddr_framing_err
 * Error occur when I3C operating in HDR-DDR mode bad preamble. We check CMD (01) and CMD->READ which is 1Z
 */
#define REG_INTF_COMM_ERR_I3C_DDR_FRAMING_ERR_POS      0x04
#define REG_INTF_COMM_ERR_I3C_DDR_FRAMING_ERR_MASK     (0x01 << REG_INTF_COMM_ERR_I3C_DDR_FRAMING_ERR_POS)

/*
 * i3c_crc_err
 * Error occur when I3C operating in HDR-DDR mode :
 * CRC encoding (for transmitters) and CRC checking (for receivers) shall be performed on all payload bits for Command Words and Data Words.
 * Mismatched CRC is an Error.
 */
#define REG_INTF_COMM_ERR_I3C_CRC_ERR_POS      0x05
#define REG_INTF_COMM_ERR_I3C_CRC_ERR_MASK     (0x01 << REG_INTF_COMM_ERR_I3C_CRC_ERR_POS)



/*
 * REG_IREG_ADDR_31_24
 * Register Name : IREG_ADDR_31_24
 */

/*
 * ireg_addr_31_24
 * [Supports Dynamic Change] DREG register for holding indirect access of IREG . Bits [31:24]
 *
 * If (1) CS_N=1 when in SPI, or (2) STOP when in IxC, is followed after a write operation to this register, then a read-prefetching operation to IREG is kicked off with new address.
 *
 * Poll register ireg_ireg_done to confirm that it is '1' before writing to this register.
 */
#define REG_IREG_ADDR_31_24_IREG_ADDR_31_24_POS      0x00
#define REG_IREG_ADDR_31_24_IREG_ADDR_31_24_MASK     0xff



/*
 * REG_IREG_ADDR_23_16
 * Register Name : IREG_ADDR_23_16
 */

/*
 * ireg_spare
 * [Supports Dynamic Change] DREG register for holding indirect access of IREG . Bits [23:16]
 *
 * If (1) CS_N=1 when in SPI, or (2) STOP when in IxC, is followed after a write operation to this register, then a read-prefetching operation to IREG is kicked off with new address.
 *
 * Poll register ireg_ireg_done to confirm that it is '1' before writing to this register.
 */
#define REG_IREG_ADDR_23_16_IREG_SPARE_POS      0x00
#define REG_IREG_ADDR_23_16_IREG_SPARE_MASK     0xff


/* ---------------------------------------------------------------------------
 * register DREG_BANK2
 * ---------------------------------------------------------------------------*/

/*
 * REG_STC_DT
 * Register Name : STC_DT
 */

/*
 * dt
 * [Supports Dynamic Change] I3C sync mode DT
 */
#define REG_STC_DT_DT_POS      0x00
#define REG_STC_DT_DT_MASK     0xff



/*
 * REG_STC_TU
 * Register Name : STC_TU
 */

/*
 * tu
 * [Supports Dynamic Change] I3C sync mode TU
 */
#define REG_STC_TU_TU_POS      0x00
#define REG_STC_TU_TU_MASK     0x03



/*
 * REG_STC_TPH_ACCEL_0
 * Register Name : STC_TPH_ACCEL_0
 */

/*
 * stc_tph_accel
 * [Supports Dynamic Change] I3C sync mode TPH for accel
 */
#define REG_STC_TPH_ACCEL_0_STC_TPH_ACCEL_POS      0x00
#define REG_STC_TPH_ACCEL_0_STC_TPH_ACCEL_MASK     0xff



/*
 * REG_STC_TPH_ACCEL_1
 * Register Name : STC_TPH_ACCEL_1
 */

/*
 * stc_tph_accel
 * [Supports Dynamic Change] I3C sync mode TPH for accel
 */
#define REG_STC_TPH_ACCEL_1_STC_TPH_ACCEL_POS      0x00
#define REG_STC_TPH_ACCEL_1_STC_TPH_ACCEL_MASK     0xff



/*
 * REG_STC_TPH_GYRO_0
 * Register Name : STC_TPH_GYRO_0
 */

/*
 * stc_tph_gyro
 * [Supports Dynamic Change] I3C sync mode TPH for gyro
 */
#define REG_STC_TPH_GYRO_0_STC_TPH_GYRO_POS      0x00
#define REG_STC_TPH_GYRO_0_STC_TPH_GYRO_MASK     0xff



/*
 * REG_STC_TPH_GYRO_1
 * Register Name : STC_TPH_GYRO_1
 */

/*
 * stc_tph_gyro
 * [Supports Dynamic Change] I3C sync mode TPH for gyro
 */
#define REG_STC_TPH_GYRO_1_STC_TPH_GYRO_POS      0x00
#define REG_STC_TPH_GYRO_1_STC_TPH_GYRO_MASK     0xff



/*
 * REG_STC_ODR
 * Register Name : STC_ODR
 */

/*
 * stc_accel_odr
 * [Supports Dynamic Change] Accelerometer Output Data Rate at the UI FIFO. ODR frequency:
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
#define REG_STC_ODR_STC_ACCEL_ODR_POS      0x00
#define REG_STC_ODR_STC_ACCEL_ODR_MASK     0x0f

/*
 * stc_gyro_odr
 * [Supports Dynamic Change] Gyroscope Output Data Rate at the UI FIFO. ODR frequency:
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
#define REG_STC_ODR_STC_GYRO_ODR_POS      0x04
#define REG_STC_ODR_STC_GYRO_ODR_MASK     (0x0f << REG_STC_ODR_STC_GYRO_ODR_POS)



#ifdef __cplusplus
}
#endif

#endif  /*#ifndef _REG_INTERNAL_H_*/

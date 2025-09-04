/*
 * Copyright (C) 2012-2018 InvenSense, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
//#define INV_IPL

#ifndef INV_IPL
#define CFG_PEDSTEP_DET                     (3371)
#define OUT_ACCL_DAT                        (2380)
#define CFG_FB_GAIN_GYRO_ON                 (1959)
#define CFG_OUT_GYRO                        (2405)
#define PED_STEP_COUNT2_DETECTED            (3377)
#define GYRO_FIFO_RATE                      (2391)
#define FSYNC_END                           (1342)
#define PREV_PQUAT                          (2432)
#define ACCEL_FIFO_RATE                     (2356)
#define PQUAT_FIFO_RATE                     (2321)
#define CFG_FIFO_INT                        (2533)
#define CFG_AUTH                            (1361)
#define CFG_OUT_FSYNC                       (1327)
#define FCFG_1                              (1428)
#define FCFG_3                              (1458)
#define FCFG_2                              (1432)
#define FCFG_7                              (1439)
#define CFG_OUT_3QUAT                       (2263)
#define OUT_3QUAT_DAT                       (2274)
#define CFG_PED_ENABLE                      (2543)
#define CFG_EXT_GYRO_BIAS                   (1547)
#define CFG_7                               (1895)
#define OUT_PQUAT_DAT                       (2345)
#define CFG_OUT_6QUAT                       (2299)
#define CFG_PED_INT                         (3360)
#define SMD_TP2                             (1835)
#define SMD_TP1                             (1812)
#define STEPDET_END                         (2249)
#define CFG_MOTION_BIAS                     (1896)
#define CFG_OUT_ACCL                        (2370)
#define CFG_OUT_STEPDET                     (2232)
#define OUT_6QUAT_DAT                       (2310)
#define QUAT6_FIFO_RATE                     (2285)
#define OUT_GYRO_DAT                        (2415)
#define CFG_OUT_PQUAT                       (2335)
#else
#define CFG_OUT_ACCL                        (2359)
#define CFG_PEDSTEP_DET                     (3360)
#define OUT_ACCL_DAT                        (2369)
#define CFG_FB_GAIN_GYRO_ON                 (1930)
#define CFG_OUT_GYRO                        (2394)
#define PED_STEP_COUNT2_DETECTED            (3366)
#define GYRO_FIFO_RATE                      (2380)
#define FSYNC_END                           (1313)
#define PREV_PQUAT                          (2421)
#define ACCEL_FIFO_RATE                     (2345)
#define PQUAT_FIFO_RATE                     (2310)
#define CFG_FIFO_INT                        (2522)
#define CFG_AUTH                            (1332)
#define CFG_OUT_FSYNC                       (1298)
#define FCFG_1                              (1399)
#define FCFG_3                              (1429)
#define FCFG_2                              (1403)
#define FCFG_7                              (1410)
#define CFG_OUT_3QUAT                       (2252)
#define OUT_3QUAT_DAT                       (2263)
#define CFG_PED_ENABLE                      (2532)
#define CFG_EXT_GYRO_BIAS                   (1518)
#define CFG_7                               (1866)
#define OUT_PQUAT_DAT                       (2334)
#define CFG_OUT_6QUAT                       (2288)
#define CFG_PED_INT                         (3349)
#define SMD_TP2                             (1806)
#define SMD_TP1                             (1783)
#define STEPDET_END                         (2238)
#define CFG_MOTION_BIAS                     (1867)
#define CFG_OUT_STEPDET                     (2221)
#define OUT_6QUAT_DAT                       (2299)
#define QUAT6_FIFO_RATE                     (2274)
#define OUT_GYRO_DAT                        (2404)
#define CFG_OUT_PQUAT                       (2324)
#endif

#define D_EXT_GYRO_BIAS_X       (61 * 16)
#define D_EXT_GYRO_BIAS_Y       ((61 * 16) + 4)
#define D_EXT_GYRO_BIAS_Z       ((61 * 16) + 8)
#define GYRO_BIAS_X	D_EXT_GYRO_BIAS_X
#define GYRO_BIAS_Y	D_EXT_GYRO_BIAS_Y
#define GYRO_BIAS_Z	D_EXT_GYRO_BIAS_Z

#define D_EIS_ENABLE			(2 * 16 + 10)

#define D_SMD_ENABLE            (18 * 16)
#define D_SMD_MOT_THLD          (21 * 16 + 8)
#define SMD_VAR_TH	D_SMD_MOT_THLD

#define D_SMD_DELAY_THLD        (21 * 16 + 4)
#define D_SMD_DELAY2_THLD       (21 * 16 + 12)
#define D_SMD_EXE_STATE         (22 * 16)
#define D_SMD_DELAY_CNTR        (21 * 16)

#define D_VIB_DET_RATIO         (30 * 16 + 0)
#define D_VIB_MAG_TH            (31 * 16 + 0)
#define D_VIB_K                 (13 * 16 + 8)
#define D_VIB_K_1               (13 * 16 + 12)

#define D_ACC_SCALE             (29 * 16 + 0)
#define ACC_SCALE D_ACC_SCALE
#define D_ACC_DATA_SCALE        (15 * 16 + 4)
#define ACC_DATA_SCALE D_ACC_DATA_SCALE

#define D_AUTH_OUT              (992)
#define D_AUTH_IN               (996)
#define D_AUTH_A                (1000)
#define D_AUTH_B                (1004)
#define D_DMP_AUTH_INPUT		(70 * 16 + 4)
#define D_DMP_AUTH_OUTPUT		(70 * 16 + 0)

#define SC_AUT_OUTPUT_20608D		D_DMP_AUTH_OUTPUT
#define SC_AUT_INPUT_20608D		D_DMP_AUTH_INPUT

#define D_PEDSTD_BP_B           (768 + 0x1C)
#define D_PEDSTD_BP_A4          (768 + 0x40)
#define D_PEDSTD_BP_A3          (768 + 0x44)
#define D_PEDSTD_BP_A2          (768 + 0x48)
#define D_PEDSTD_BP_A1          (768 + 0x4C)
#define D_PEDSTD_SB             (768 + 0x28)
#define D_PEDSTD_SB_TIME        (768 + 0x2C)
#define D_PEDSTD_PEAKTHRSH      (768 + 0x98)
#define D_PEDSTD_TIML           (768 + 0x2A)
#define D_PEDSTD_TIMH           (768 + 0x2E)
#define D_PEDSTD_PEAK           (768 + 0X94)
#define D_PEDSTD_STEPCTR        (768 + 0x60)
#define PEDSTD_STEPCTR		D_PEDSTD_STEPCTR
#define D_PEDSTD_STEPCTR2       (58 * 16 + 8)
#define D_PEDSTD_TIMECTR        (964)
#define PEDSTD_TIMECTR		D_PEDSTD_TIMECTR
#define D_PEDSTD_DECI           (768 + 0xA0)
#define D_PEDSTD_SB2			(60 * 16 + 14)
#define D_STPDET_TIMESTAMP      (28 * 16 + 8)
#define STPDET_TIMESTAMP	D_STPDET_TIMESTAMP
#define D_PEDSTD_DRIVE_STATE    (58)
#define D_PEDSTEP_IND			(26*16 + 6)
#define PEDSTEP_IND				D_PEDSTEP_IND

#define D_HOST_NO_MOT           (976)
#define D_ACCEL_BIAS            (660)

/* Batch mode */
#define D_BM_BATCH_CNTR         (27*16+4)
#define D_BM_BATCH_THLD         (27*16+12)
#define BM_BATCH_CNTR		D_BM_BATCH_CNTR
#define BM_BATCH_THLD		D_BM_BATCH_THLD

#define D_BM_ENABLE             (28*16+6)
#define D_BM_NUMWORD_TOFILL     (28*16+4)

/* DMP running counter */
#define D_DMP_RUN_CNTR          (24*16)
#define DMPRATE_CNTR		D_DMP_RUN_CNTR

/* Sensor's ODR */
#define D_ODR_S2                (45*16+10)
#define D_ODR_S3                (45*16+14)
#define D_ODR_S4                (46*16+8)
#define D_ODR_S5                (46*16+12)
#define D_ODR_S1                (45*16+12)

#define ODR_ACCEL			D_ODR_S4
#define ODR_GYRO			D_ODR_S5
#define ODR_QUAT6			D_ODR_S2
#define ODR_PQUAT6			D_ODR_S3
#define ODR_LPQ			D_ODR_S1

/* sensor output data rate counter */
#define D_ODR_CNTR_S2           (45*16+2)
#define D_ODR_CNTR_S3           (45*16+6)
#define D_ODR_CNTR_S4           (46*16)
#define D_ODR_CNTR_S5           (46*16+4)
#define D_ODR_CNTR_S1           (45*16+4)

#define ODR_CNTR_ACCEL				D_ODR_CNTR_S4
#define ODR_CNTR_GYRO				D_ODR_CNTR_S5
#define ODR_CNTR_QUAT6				D_ODR_CNTR_S2
#define ODR_CNTR_PQUAT6			D_ODR_CNTR_S3
#define ODR_CNTR_LPQ			        D_ODR_CNTR_S1

/* DMP Fusion LP-Quat */
#define D_FS_LPQ0               (59*16)
#define D_FS_LPQ1               (59*16 + 4)
#define D_FS_LPQ2               (59*16 + 8)
#define D_FS_LPQ3               (59*16 + 12)

/* DMP Fusion (Accel+Gyro) Quat */
#define D_ACCEL_FB_GAIN			(6*16)
#define D_GYRO_SF				(6*16 + 8)
#define GYRO_SF		D_GYRO_SF
#define D_FS_Q0                 (12*16)
#define D_FS_Q1                 (12*16 + 4)
#define D_FS_Q2                 (12*16 + 8)
#define D_FS_Q3                 (12*16 + 12)

/* AK compass support */
#define D_CPASS_STATUS_CHK		(22*16 + 8)

/* data packet size reg 1 */
#define HEADER_SZ		2
#define ACCEL_DATA_SZ	6
#define GYRO_DATA_SZ	18
#define QUAT6_DATA_SZ	14
#define LPQ_DATA_SZ	14
#define PQUAT6_DATA_SZ	6
#define PED_STEPDET_TIMESTAMP_SZ	4
#define FOOTER_SZ		2
#define ACCEL_ACCURACY_SZ	2
#define GYRO_ACCURACY_SZ	2
#define CPASS_ACCURACY_SZ	2
#define FSYNC_PK_SZ		2

#define ACCEL_SET				0x4000
#define GYRO_SET				0x2000
#define LPQ_SET				0x0800
#define QUAT6_SET				0x0400
#define PQUAT6_SET			0x0200
#define PED_STEPDET_SET		0x0100
#define HEADER2_SET			0x0008
#define PED_STEPIND_SET		0x0007
#define FSYNC_HDR               0x7000

/* high byte of motion event control */
#define PEDOMETER_EN        0x4000
#define PEDOMETER_INT_EN    0x2000
#define TILT_INT_EN         0x1000
#define SMD_EN              0x0800
#define SECOND_SENSOR_AUTO  0x0400
#define ACCEL_CAL_EN        0x0200
#define GYRO_CAL_EN         0x0100
/* low byte of motion event control */
#define COMPASS_CAL_EN      0x0080
#define NINE_AXIS_EN        0x0040
#define S_HEALTH_EN         0x0020
#define FLIP_PICKUP_EN      0x0010
#define GEOMAG_RV_EN        0x0008
#define BRING_LOOK_SEE_EN   0x0004
#define BAC_ACCEL_ONLY_EN   0x0002

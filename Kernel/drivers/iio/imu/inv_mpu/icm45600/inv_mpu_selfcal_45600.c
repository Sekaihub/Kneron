/*
 * Copyright (C) 2017-2021 InvenSense, Inc.
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
#define DEBUG
#define pr_fmt(fmt) "inv_mpu: " fmt

#include "../inv_mpu_iio.h"
#include "inv_mpu_iio_reg_45600.h"
#include "./inv_imu_edmp_memmap.h"

/*
 * EDMP_STC_RESULTS
 */

#define STC_RESULTS_ACCEL_X_MASK   0x0001
#define STC_RESULTS_ACCEL_Y_MASK   0x0002
#define STC_RESULTS_ACCEL_Z_MASK   0x0004
#define STC_RESULTS_GYRO_X_MASK    0x0008
#define STC_RESULTS_GYRO_Y_MASK    0x0010
#define STC_RESULTS_GYRO_Z_MASK    0x0020
#define STC_RESULTS_ACCEL_SC_MASK  0x0040
#define STC_RESULTS_GYRO_SC_MASK   0x0080


/*
 * EDMP_STC_CONFIGPARAMS
 */

#define SELFTESTCAL_INIT_EN_MASK    0x0001
#define SELFTESTCAL_INIT_EN         0x0001
#define SELFTESTCAL_INIT_DIS        0x0000
#define SELFTEST_ACCEL_EN_MASK      0x0002
#define SELFTEST_ACCEL_EN           0x0002
#define SELFTEST_ACCEL_DIS          0x0000
#define SELFTEST_GYRO_EN_MASK       0x0004
#define SELFTEST_GYRO_EN            0x0004
#define SELFTEST_GYRO_DIS           0x0000
#define SELFCAL_ACCEL_EN_MASK       0x0008
#define SELFCAL_ACCEL_EN            0x0008
#define SELFCAL_ACCEL_DIS           0x0000
#define SELFCAL_GYRO_EN_MASK        0x0010
#define SELFCAL_GYRO_EN             0x0010
#define SELFCAL_GYRO_DIS            0x0000
#define SELFCAL_GYRO_METHOD_MASK    0x0020
#define SELFCAL_SSOM_EN_MASK        0x0040
#define SELFCAL_SSOM_EN             0x0040
#define SELFCAL_SSOM_DIS            0x0000
#define SELFTEST_AVERAGE_TIME_MASK  0x0380
#define SELFTEST_ACCEL_THRESH_MASK  0x1C00
#define SELFTEST_GYRO_THRESH_MASK   0xE000

#define SC_GYRO_X_CALC_METHOD SELFCAL_STEP_RESPONSE
#define SC_GYRO_Y_CALC_METHOD SELFCAL_SC2V_ADC
#define SC_GYRO_Z_CALC_METHOD SELFCAL_STEP_RESPONSE

enum selftest_average_time_t {
	SELFTEST_AVG_TIME_10_MS  = 0x0000,
	SELFTEST_AVG_TIME_20_MS  = 0x0080,
	SELFTEST_AVG_TIME_40_MS  = 0x0100,
	SELFTEST_AVG_TIME_80_MS  = 0x0180,
	SELFTEST_AVG_TIME_160_MS = 0x0200,
	SELFTEST_AVG_TIME_320_MS = 0x0280
} ;

typedef enum {
	SELFTEST_ACCEL_THRESHOLD_5_PERCENT  = 0x0000,
	SELFTEST_ACCEL_THRESHOLD_10_PERCENT = 0x0400,
	SELFTEST_ACCEL_THRESHOLD_15_PERCENT = 0x0800,
	SELFTEST_ACCEL_THRESHOLD_20_PERCENT = 0x0c00,
	SELFTEST_ACCEL_THRESHOLD_25_PERCENT = 0x1000,
	SELFTEST_ACCEL_THRESHOLD_30_PERCENT = 0x1400,
	SELFTEST_ACCEL_THRESHOLD_40_PERCENT = 0x1800,
	SELFTEST_ACCEL_THRESHOLD_50_PERCENT = 0x1c00
} selftest_accel_threshold_t;

typedef enum {
	SELFTEST_GYRO_THRESHOLD_5_PERCENT  = 0x0000,
	SELFTEST_GYRO_THRESHOLD_10_PERCENT = 0x2000,
	SELFTEST_GYRO_THRESHOLD_15_PERCENT = 0x4000,
	SELFTEST_GYRO_THRESHOLD_20_PERCENT = 0x6000,
	SELFTEST_GYRO_THRESHOLD_25_PERCENT = 0x8000,
	SELFTEST_GYRO_THRESHOLD_30_PERCENT = 0xa000,
	SELFTEST_GYRO_THRESHOLD_40_PERCENT = 0xc000,
	SELFTEST_GYRO_THRESHOLD_50_PERCENT = 0xe000
} selftest_gyro_threshold_t;

enum selfcal_gyro_method_t{
	SELFCAL_STEP_RESPONSE = 0x0000,
	SELFCAL_SC2V_ADC = 0x0020
} ;

#define INV_IMU_ERROR -1
#define INV_IMU_OK 0
#define SCALE_FROM_FLOAT 65536 /* To only use fixed point, values are scaled up by 2^16 */
/* User gain values are stored as an integer value between 0 and 2048 */
#define USERGAIN_SCALE 2048

#define INV_IMU_STC_STATUS_SUCCESS 1 /**< Indicates test is successful */
#define INV_IMU_STC_STATUS_FAIL    -1 /**< Indicates test is failing */
#define INV_IMU_STC_STATUS_NOT_RUN 0 /**< Indicates test has not run */


/* Self-cal internal output */
struct inv_imu_selfcal_output_internal_t {
	int32_t sc_accel_nout_meas_x;
	int32_t sc_accel_nout_meas_y;
	int32_t sc_accel_nout1_meas_z;
	int32_t sc_accel_nout2_meas_z;
	int32_t sc_accel_cmos_meas_x;
	int16_t sc_accel_nout_trim[3];
	int16_t sc_gyro_str_ft_trim[3];
	int32_t sc_gyro_step_response32[3];
	int32_t sc_gyro_gain32[3];
	int16_t sc_gyro_cmos_trim[3];
} ;


/*
 * EDMP_STC_PATCH_EN
 */

#define EDMP_SELFTESTCAL_OTPDATA_ACCEL_X_STR_FT                 0xc
#define EDMP_SELFTESTCAL_OTPDATA_ACCEL_X_STR_FT_SIZE            2

/* selfTestCal_otpData_accel_y_str_ft
 *

 */
#define EDMP_SELFTESTCAL_OTPDATA_ACCEL_Y_STR_FT                 0xe
#define EDMP_SELFTESTCAL_OTPDATA_ACCEL_Y_STR_FT_SIZE            2

/* selfTestCal_otpData_accel_z_str_ft
 *

 */
#define EDMP_SELFTESTCAL_OTPDATA_ACCEL_Z_STR_FT                 0x10
#define EDMP_SELFTESTCAL_OTPDATA_ACCEL_Z_STR_FT_SIZE            2

typedef enum {
	SELFTEST_PATCH_EN_ACCEL_PHASE1  = 0x0001,
	SELFTEST_PATCH_EN_ACCEL_PHASE2  = 0x0002,
	SELFTEST_PATCH_EN_GYRO1_PHASE1  = 0x0004,
	SELFTEST_PATCH_EN_GYRO1_PHASE2  = 0x0008,
	SELFCAL_PATCH_EN_ACCEL_AX_MEMS  = 0x0010,
	SELFCAL_PATCH_EN_ACCEL_AX_CMOS  = 0x0020,
	SELFCAL_PATCH_EN_ACCEL_AY_MEMS  = 0x0040,
	SELFCAL_PATCH_EN_ACCEL_AY_CMOS  = 0x0080,
	SELFCAL_PATCH_EN_ACCEL_AZ_MEMS1 = 0x0100,
	SELFCAL_PATCH_EN_ACCEL_AZ_MEMS2 = 0x0200,
	SELFCAL_PATCH_EN_GYRO2_PHASE1   = 0x0400,
	SELFCAL_PATCH_EN_GYRO2_PHASE2   = 0x0800
} stc_patch_params_t;

/** Self-Cal parameters */
struct  inv_imu_selfcal_parameters_t {
	/** If set, enable accel self-cal */
	uint8_t accel_en;

	/** If set, enable gyro self-cal */
	uint8_t gyro_en;

	/** If set, enable SSOM for self-cal */
	uint8_t ssom_en;

	/** The accel slope values used in self-cal calculations */
	int32_t accel_slope[3];

	/** The accel bias values used in self-cal calculations */
	int32_t accel_bias[3];

	/** The gyro slope values used in self-cal calculations */
	int32_t gyro_slope[3];

	/** The gyro bias values used in self-cal calculations */
	int32_t gyro_bias[3];

	/** The method used to calculate the gyro calibration */
	enum selfcal_gyro_method_t gyro_method[3];

	/** Averaging time */
	enum selftest_average_time_t avg_time;

	/** Mechanism for adding patches to self-test/self-cal operations */
	uint32_t patch_settings;
};

/** Self-cal outputs */
struct  inv_imu_selfcal_output_t {
	/** Global accel self-cal passed. 1 for success, 0 otherwise. */
	int8_t accel_status;

	/** Global gyro self-cal passed. 1 for success, 0 otherwise. */
	int8_t gyro_status;

	/** Calculated values for accel user gain fields. */
	uint16_t accel_gains[3];

	/** Calculated values for accel user gain fields. */
	uint16_t gyro_gains[3];
};

static int inv_imu_stc_set_accel_usergain(struct inv_mpu_state *st, uint16_t accel_user_gain[])
{
	int ii;
	int reg_index;
	int rc = 0;

	/* The accel user gain values are written to 12 bit fields in registers:
		IPREG_SYS2_REG_48, IPREG_SYS2_REG_56 and IPREG_SYS2_REG_64 */
	for (ii = 0, reg_index = REG_IPREG_SYS2_REG_48_IPREG_SYS2; ii < 3; ii++, reg_index += 8) {
		rc |= inv_ireg_write(st, reg_index, 2, (uint8_t *)&accel_user_gain[ii]);
	}
	return rc;
}

static int inv_imu_stc_set_gyro_usergain(struct inv_mpu_state *st, uint16_t gyro_user_gain[])
{
	int ii;
	int reg_index;
	int rc = 0;

	/* The gyro user gain values are written to 12 bit fields in registers:
		IPREG_SYS1_REG_118, IPREG_SYS1_REG_130 and IPREG_SYS1_REG_142 */
	for (ii = 0, reg_index = REG_IPREG_SYS1_REG_118_IPREG_SYS1; ii < 3; ii++, reg_index += 12) {
		rc |= inv_ireg_write(st, reg_index, 2, (uint8_t *)&gyro_user_gain[ii]);
	}
	return rc;
}


static int set_selfcal_parameters(struct inv_mpu_state *st,
                                  const struct inv_imu_selfcal_parameters_t *sc_params,
                                  const enum selfcal_gyro_method_t         gyro_method)

{
	int      res;
	u32 tmp_stc_params;
	u32 patch_settings;
	u32 init_en;

	inv_power_up_sram(st);

	res = inv_ireg_read(st, selfTestCal_configParams, selfTestCal_configParams_size,  (u8 *)&tmp_stc_params);
	if (res)
		return res;
	pr_info("read stc_para=%x\n", tmp_stc_params);

	tmp_stc_params &= ~( SELFTESTCAL_INIT_EN_MASK
	                    | SELFTEST_ACCEL_EN_MASK
	                    | SELFTEST_GYRO_EN_MASK
	                    | SELFCAL_ACCEL_EN_MASK
	                    | SELFCAL_GYRO_EN_MASK
	                    | SELFCAL_SSOM_EN_MASK
	                    | SELFCAL_GYRO_METHOD_MASK
	                    | SELFTEST_AVERAGE_TIME_MASK
	                    | SELFTEST_ACCEL_THRESH_MASK
	                    | SELFTEST_GYRO_THRESH_MASK);

	init_en = (sc_params->accel_en || sc_params->gyro_en);
	tmp_stc_params |= (init_en ? SELFTESTCAL_INIT_EN : SELFTESTCAL_INIT_DIS);
	tmp_stc_params |= (sc_params->accel_en ? SELFCAL_ACCEL_EN : SELFCAL_ACCEL_DIS);
	tmp_stc_params |= (sc_params->gyro_en ? SELFCAL_GYRO_EN : SELFCAL_GYRO_DIS);
	tmp_stc_params |= (sc_params->ssom_en ? SELFCAL_SSOM_EN : SELFCAL_SSOM_DIS);
	//tmp_stc_params |= (uint32_t)(sc_params->avg_time & SELFTEST_AVERAGE_TIME_MASK);
	tmp_stc_params |= SELFTEST_AVG_TIME_10_MS;
	tmp_stc_params |= (uint32_t)(gyro_method & SELFCAL_GYRO_METHOD_MASK);

	pr_info("stc_para=%x\n", tmp_stc_params);
	inv_ireg_write(st, EDMP_STC_CONFIGPARAMS, EDMP_STC_CONFIGPARAMS_SIZE, (u8 *)(&tmp_stc_params));

	tmp_stc_params = 0; /* disable any selfcal stop point */
	res = inv_ireg_write(st, 0x40, 4, (u8 *)&tmp_stc_params);
	if (res)
		return res;
	tmp_stc_params = 1344; /* SSOM accel threshold : 20.50 mg in q16 */
	res = inv_ireg_write(st, 0x154, 4, (u8 *)&tmp_stc_params);
	if (res)
		return res;
	tmp_stc_params = 52000; /* SSOM gyro threshold : 0.794 dps in q16 */
	res = inv_ireg_write(st, 0x158, 4, (u8 *)&tmp_stc_params);
	if (res)
		return res;
	patch_settings = 0;
	res = inv_ireg_write(st, EDMP_STC_PATCH_EN, EDMP_STC_PATCH_EN_SIZE, (u8 *)(&patch_settings));

	return res;
}

static int get_selfcal_output(struct inv_mpu_state *st, const struct inv_imu_selfcal_parameters_t *sc_params,
                              struct inv_imu_selfcal_output_t *         sc_output,
                              struct inv_imu_selfcal_output_internal_t *sc_output_i)
{
	int      rc = INV_IMU_OK;
	uint32_t stc_results;

	rc = inv_ireg_read(st, EDMP_STC_RESULTS, EDMP_STC_RESULTS_SIZE, (u8 *)(&stc_results));
	if (rc)
		return rc;


	if (sc_params->accel_en) {
		sc_output->accel_status = ((stc_results & STC_RESULTS_ACCEL_SC_MASK) == 0) ?
                                      INV_IMU_STC_STATUS_SUCCESS :
                                      INV_IMU_STC_STATUS_FAIL;
                pr_info("accel_sc stat=%x\n", sc_output->accel_status);
		inv_ireg_read(st, EDMP_STC_ACCEL_SC_NOUT_MEAS_X, EDMP_STC_ACCEL_SC_NOUT_MEAS_X_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout_meas_x));
		inv_ireg_read(st, EDMP_STC_ACCEL_SC_NOUT_MEAS_Y, EDMP_STC_ACCEL_SC_NOUT_MEAS_Y_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout_meas_y));
		inv_ireg_read(st, EDMP_STC_ACCEL_SC_NOUT1_MEAS_Z, EDMP_STC_ACCEL_SC_NOUT1_MEAS_Z_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout1_meas_z));
		inv_ireg_read(st, EDMP_STC_ACCEL_SC_NOUT2_MEAS_Z, EDMP_STC_ACCEL_SC_NOUT2_MEAS_Z_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout2_meas_z));
		inv_ireg_read(st, EDMP_STC_ACCEL_SC_CMOS_MEAS_X, EDMP_STC_ACCEL_SC_CMOS_MEAS_X_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_cmos_meas_x));

		inv_ireg_read(st, EDMP_ACCEL_X_SC_NOUT_FT, EDMP_ACCEL_X_SC_NOUT_FT_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout_trim[0]));
		inv_ireg_read(st, EDMP_ACCEL_X_SC_NOUT_FT, EDMP_ACCEL_X_SC_NOUT_FT_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout_trim[1]));
		inv_ireg_read(st, EDMP_ACCEL_Z_SC_NOUT_FT, EDMP_ACCEL_Z_SC_NOUT_FT_SIZE,
		                             (u8 *)&(sc_output_i->sc_accel_nout_trim[2]));

	} else {
		sc_output->accel_status            = INV_IMU_STC_STATUS_NOT_RUN;
		sc_output_i->sc_accel_nout_meas_x  = 0;
		sc_output_i->sc_accel_nout_meas_y  = 0;
		sc_output_i->sc_accel_nout1_meas_z = 0;
		sc_output_i->sc_accel_nout2_meas_z = 0;
		sc_output_i->sc_accel_cmos_meas_x  = 0;
		sc_output_i->sc_accel_nout_trim[0] = 0;
		sc_output_i->sc_accel_nout_trim[1] = 0;
		sc_output_i->sc_accel_nout_trim[2] = 0;
	}

	if (sc_params->gyro_en) {
		sc_output->gyro_status = ((stc_results & STC_RESULTS_GYRO_SC_MASK) == 0) ?
                                     INV_IMU_STC_STATUS_SUCCESS :
                                     INV_IMU_STC_STATUS_FAIL;
		pr_info("gyro_ac=%x\n", sc_output->gyro_status);

		inv_ireg_read(st, EDMP_GYRO_X_STR_FT, EDMP_GYRO_X_STR_FT_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_str_ft_trim[0]));
		inv_ireg_read(st, EDMP_GYRO_Y_STR_FT, EDMP_GYRO_Y_STR_FT_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_str_ft_trim[1]));
		inv_ireg_read(st, EDMP_GYRO_Z_STR_FT, EDMP_GYRO_Z_STR_FT_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_str_ft_trim[2]));

		inv_ireg_read(st, EDMP_STC_GAIN_GX, EDMP_STC_GAIN_GX_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_step_response32[0]));
		inv_ireg_read(st, EDMP_STC_GAIN_GY, EDMP_STC_GAIN_GY_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_step_response32[1]));
		inv_ireg_read(st, EDMP_STC_GAIN_GZ, EDMP_STC_GAIN_GZ_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_step_response32[2]));

		inv_ireg_read(st, EDMP_GYRO_X_CMOS_GAIN_FT, EDMP_GYRO_X_CMOS_GAIN_FT_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_cmos_trim[0]));
		inv_ireg_read(st, EDMP_GYRO_Y_CMOS_GAIN_FT, EDMP_GYRO_Y_CMOS_GAIN_FT_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_cmos_trim[1]));
		inv_ireg_read(st, EDMP_GYRO_Z_CMOS_GAIN_FT, EDMP_GYRO_Z_CMOS_GAIN_FT_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_cmos_trim[2]));

		inv_ireg_read(st, EDMP_STC_GAIN_GX, EDMP_STC_GAIN_GX_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_gain32[0]));
		inv_ireg_read(st, EDMP_STC_GAIN_GY, EDMP_STC_GAIN_GY_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_gain32[1]));
		inv_ireg_read(st, EDMP_STC_GAIN_GZ, EDMP_STC_GAIN_GZ_SIZE,
		                             (uint8_t *)&(sc_output_i->sc_gyro_gain32[2]));

	} else {
		sc_output->gyro_status                  = INV_IMU_STC_STATUS_NOT_RUN;
		sc_output_i->sc_gyro_str_ft_trim[0]     = 0;
		sc_output_i->sc_gyro_str_ft_trim[1]     = 0;
		sc_output_i->sc_gyro_str_ft_trim[2]     = 0;
		sc_output_i->sc_gyro_step_response32[0] = 0;
		sc_output_i->sc_gyro_step_response32[1] = 0;
		sc_output_i->sc_gyro_step_response32[2] = 0;
		sc_output_i->sc_gyro_cmos_trim[0]       = 0;
		sc_output_i->sc_gyro_cmos_trim[1]       = 0;
		sc_output_i->sc_gyro_cmos_trim[2]       = 0;
		sc_output_i->sc_gyro_gain32[0]          = 0;
		sc_output_i->sc_gyro_gain32[1]          = 0;
		sc_output_i->sc_gyro_gain32[2]          = 0;
	}
	return 0;
}

static int run_selfcal(struct inv_mpu_state *st, const struct inv_imu_selfcal_parameters_t *sc_params,
                       const enum selfcal_gyro_method_t gyro_method, struct inv_imu_selfcal_output_t *sc_output,
                       struct inv_imu_selfcal_output_internal_t *sc_output_i)
{
	int rc = INV_IMU_OK;

	rc |= inv_imu_soft_reset(st);

	msleep(10);

	rc |= set_selfcal_parameters(st, sc_params, gyro_method);

	rc |= inv_imu_run_internal_stc(st, 1);

	rc |= get_selfcal_output(st, sc_params, sc_output, sc_output_i);

	rc |= inv_imu_soft_reset(st);

	return rc;
}

static int calc_gyro_step_response_usergain(struct inv_mpu_state *st,
                                            const struct inv_imu_selfcal_parameters_t *     sc_params,
                                            const struct inv_imu_selfcal_output_internal_t *sc_output_i,
                                            uint16_t *                               gyro_usergain)
{
	int      rc = INV_IMU_OK;
	int32_t  gyro_step_response32[3];
	int16_t  gyro_step_response16[3];
	int16_t  gyro_str_ft_trim[3];
	int64_t  temp;
	uint32_t calculated_gain[3];
	int      i;

	for (i = 0; i < 3; i++) {
		gyro_str_ft_trim[i]     = sc_output_i->sc_gyro_str_ft_trim[i];
		gyro_step_response32[i] = sc_output_i->sc_gyro_step_response32[i];
		gyro_step_response16[i] = (gyro_step_response32[i] >> 11);
		temp = ((gyro_step_response16[i] - gyro_str_ft_trim[i]) * sc_params->gyro_slope[i]);
		temp = ((temp / gyro_str_ft_trim[i])) + SCALE_FROM_FLOAT + sc_params->gyro_bias[i];
		calculated_gain[i] = (SCALE_FROM_FLOAT * USERGAIN_SCALE) / temp;
		gyro_usergain[i]   = (uint16_t)(calculated_gain[i]);
	}

	return rc;
}

static int calc_gyro_sc2v_adc_usergain(struct inv_mpu_state *st,
                                       const struct inv_imu_selfcal_parameters_t *     sc_params,
                                       const struct inv_imu_selfcal_output_internal_t *sc_output_i,
                                       uint16_t *                               gyro_usergain)
{
	int      rc = INV_IMU_OK;
	int32_t  gyro_gain32[3];
	int16_t  gyro_gain16[3];
	int16_t  gyro_cmos_trim[3];
	int64_t  temp;
	uint32_t calculated_gain[3];
	int      i;

	for (i = 0; i < 3; i++) {
		gyro_cmos_trim[i] = sc_output_i->sc_gyro_cmos_trim[i];
		gyro_gain32[i]    = sc_output_i->sc_gyro_gain32[i];
		gyro_gain16[i]    = (gyro_gain32[i] >> 13);
		temp              = (gyro_gain16[i] - gyro_cmos_trim[i]) * sc_params->gyro_slope[i];
		temp = (temp / gyro_cmos_trim[i]) + (1 * SCALE_FROM_FLOAT) + sc_params->gyro_bias[i];
		calculated_gain[i] = (SCALE_FROM_FLOAT * USERGAIN_SCALE) / temp;
		gyro_usergain[i]   = (uint16_t)(calculated_gain[i]);
	}

	return rc;
}

static int calc_accel_usergain(struct inv_mpu_state *st,
			const struct inv_imu_selfcal_parameters_t *sc_params,
			const struct inv_imu_selfcal_output_internal_t *sc_output_i,
			u16 *accel_usergain)
{
	int     rc = INV_IMU_OK;
	int32_t accel_sc_nout32[3];
	int32_t accel_sc_nout1_z, accel_sc_nout2_z, accel_sc_cmos_x;
	int16_t accel_sc_nout_trim[3];
	int32_t accel_sc_nout_trim32[3];
	int64_t temp;
	int64_t calculated_gain[3];
	int     i;

	accel_sc_nout32[0] = sc_output_i->sc_accel_nout_meas_x;
	accel_sc_nout32[1] = sc_output_i->sc_accel_nout_meas_y;
	accel_sc_nout1_z   = sc_output_i->sc_accel_nout1_meas_z;
	accel_sc_nout2_z   = sc_output_i->sc_accel_nout2_meas_z;
	accel_sc_cmos_x    = sc_output_i->sc_accel_cmos_meas_x;

	temp = (int64_t)(accel_sc_nout1_z + accel_sc_nout2_z) *
	       (int64_t)(accel_sc_nout1_z + accel_sc_nout2_z);
	accel_sc_nout32[2] = temp / (int64_t)(4 * accel_sc_cmos_x);

	for (i = 0; i < 3; i++) {
		accel_sc_nout_trim[i] = sc_output_i->sc_accel_nout_trim[i];
		if (accel_sc_nout32[i] < 0.0)
			accel_sc_nout32[i] *= -1;
		accel_sc_nout_trim32[i] = accel_sc_nout_trim[i] << 4;
		temp                    = (accel_sc_nout32[i] * (int64_t)sc_params->accel_slope[i]) +
		       (accel_sc_nout_trim32[i] * (SCALE_FROM_FLOAT + (int64_t)sc_params->accel_bias[i] -
		                                   (int64_t)sc_params->accel_slope[i]));
		calculated_gain[i] =
		    ((uint64_t)accel_sc_nout_trim32[i] * SCALE_FROM_FLOAT * USERGAIN_SCALE) / temp;
		accel_usergain[i] = (uint16_t)calculated_gain[i];
	}

	return rc;
}

int inv_imu_stc_selfcal(struct inv_mpu_state *st,
			const struct inv_imu_selfcal_parameters_t *sc_params,
                        struct inv_imu_selfcal_output_t *sc_output)
{
	int                               rc = INV_IMU_OK;
	struct inv_imu_selfcal_output_internal_t sc_internal_output;
	uint16_t                          temp_step_response_gains[3], temp_sc2v_adc_gains[3];
	int                               i;

	/* If neither gyro or accel self-cal are enabled */
	if (!(sc_params->accel_en || sc_params->gyro_en))
		return INV_IMU_ERROR;

	/* If the gyro is to be calibrated */
	if (sc_params->gyro_en) {
		/* If at least one axis uses Step Response */
		if ((sc_params->gyro_method[0] == SELFCAL_STEP_RESPONSE) ||
		    (sc_params->gyro_method[1] == SELFCAL_STEP_RESPONSE) ||
		    (sc_params->gyro_method[2] == SELFCAL_STEP_RESPONSE)) {
			rc |= run_selfcal(st, sc_params, SELFCAL_STEP_RESPONSE, sc_output, &sc_internal_output);
			if (sc_output->gyro_status == INV_IMU_STC_STATUS_SUCCESS) {
				rc |= calc_gyro_step_response_usergain(st, sc_params, &sc_internal_output,
				                                       temp_step_response_gains);
			} else
				return INV_IMU_ERROR;
		}

		/* If at least one axis uses SC2V ADC */
		if ((sc_params->gyro_method[0] == SELFCAL_SC2V_ADC) ||
		    (sc_params->gyro_method[1] == SELFCAL_SC2V_ADC) ||
		    (sc_params->gyro_method[2] == SELFCAL_SC2V_ADC)) {
			rc |= run_selfcal(st, sc_params, SELFCAL_SC2V_ADC, sc_output, &sc_internal_output);
			if (sc_output->gyro_status == INV_IMU_STC_STATUS_SUCCESS)
				rc |= calc_gyro_sc2v_adc_usergain(st, sc_params, &sc_internal_output,
				                                  temp_sc2v_adc_gains);
			else
				return INV_IMU_ERROR;
		}

		/* For each axis get the gain calculation generated by the configured method */
		for (i = 0; i < 3; i++) {
			sc_output->gyro_gains[i] = (sc_params->gyro_method[i] == SELFCAL_STEP_RESPONSE) ?
                                           temp_step_response_gains[i] :
                                           temp_sc2v_adc_gains[i];
		}
	}

	/* If the accel is to be calibrated */
	if (sc_params->accel_en) {
		/* Gyro SelfCal is not enabled so SelfCal has not yet been run */
		if (!sc_params->gyro_en)
			rc |= run_selfcal(st, sc_params, SELFCAL_STEP_RESPONSE, sc_output, &sc_internal_output);
		if (sc_output->accel_status != INV_IMU_STC_STATUS_SUCCESS)
			return INV_IMU_ERROR;
		rc |= calc_accel_usergain(st, sc_params, &sc_internal_output, sc_output->accel_gains);
	}

	return rc;
}

static int calculate_gyro_gain (struct inv_mpu_state *st, struct inv_imu_selfcal_parameters_t *sc_params)
{
	struct inv_imu_selfcal_output_t sc_output;
	int                      rc = 0;

	rc |= inv_imu_stc_selfcal(st, sc_params, &sc_output);
	rc |= inv_imu_stc_set_gyro_usergain(st, sc_output.gyro_gains);

	return sc_output.gyro_status;
}

static int calculate_accel_gain (struct inv_mpu_state *st, struct inv_imu_selfcal_parameters_t *sc_params)
{
	struct inv_imu_selfcal_output_t sc_output;
	int                      rc = 0;

	rc |= inv_imu_stc_selfcal(st, sc_params, &sc_output);
	rc |= inv_imu_stc_set_accel_usergain(st, sc_output.accel_gains);

	return sc_output.accel_status;
}

int inv_imu_init_params_for_selfcal(struct inv_mpu_state *st, struct inv_imu_selfcal_parameters_t *sc_params)
{

	sc_params->avg_time       = SELFTEST_AVG_TIME_320_MS;
	sc_params->accel_en       = 1;
	sc_params->gyro_en        = 1;
	sc_params->ssom_en        = 1;
	sc_params->gyro_method[0] = SC_GYRO_X_CALC_METHOD;
	sc_params->gyro_method[1] = SC_GYRO_Y_CALC_METHOD;
	sc_params->gyro_method[2] = SC_GYRO_Z_CALC_METHOD;
#if 0
	sc_params->accel_slope[0] = SC_AX_SLOPE;
	sc_params->accel_slope[1] = SC_AY_SLOPE;
	sc_params->accel_slope[2] = SC_AZ_SLOPE;
	sc_params->accel_bias[0]  = SC_AX_BIAS;
	sc_params->accel_bias[1]  = SC_AY_BIAS;
	sc_params->accel_bias[2]  = SC_AZ_BIAS;
	sc_params->gyro_slope[0]  = SC_GX_SLOPE;
	sc_params->gyro_slope[1]  = SC_GY_SLOPE;
	sc_params->gyro_slope[2]  = SC_GZ_SLOPE;
	sc_params->gyro_bias[0]   = SC_GX_BIAS;
	sc_params->gyro_bias[1]   = SC_GY_BIAS;
	sc_params->gyro_bias[2]   = SC_GZ_BIAS;
	sc_params->patch_settings = 0;
#endif
	return 0;
}

/*
 *  inv_hw_self_test() - main function to do hardware self test
 */
int inv_hw_self_cal(struct inv_mpu_state *st)
{
	int res;
	int i;
	int gyro_sc, accel_sc;
	u8 v;
	struct inv_imu_selfcal_parameters_t sc_params;

	pr_info("start self cal\n");
	inv_imu_edmp_init_apex(st, 1);
	v = 0x0;
	for (i = 0; i < EDMP_STC_PATCH_EN_SIZE; i++) {
		res = inv_ireg_single_write(st, EDMP_STC_PATCH_EN + i, v);
		if (res)
			return res;
	}

	inv_imu_init_params_for_selfcal(st, &sc_params);
	gyro_sc = calculate_gyro_gain(st, &sc_params);

	inv_imu_init_params_for_selfcal(st, &sc_params);
	accel_sc = calculate_accel_gain(st, &sc_params);


	return (accel_sc << 1) | gyro_sc;
}

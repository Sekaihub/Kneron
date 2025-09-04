/*
 * Copyright (c) 2023, Vatics INC. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <safezone.h>
#include <wagner_log.h>

//#define MAX_NUMBER_IDS 10
//unsigned int auth_img_flags[MAX_NUMBER_IDS];

void crypto_mod_init(void)
{
	//BL1 already init
}

void auth_mod_init(void)
{
	//BL1 already init
}

int auth_mod_verify_img(unsigned int img_id, void *ptr, unsigned int len)
{
	int ret;

	ret = eip130_verifyImage(img_id, (uintptr_t)ptr, (uintptr_t)ptr);

	if (ret != 0)
		wagner_err(WAGNER_ERR_AUTHMOD_VERIFY);

	return ret;
}

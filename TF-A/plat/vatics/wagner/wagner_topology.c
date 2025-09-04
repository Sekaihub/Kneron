/*
 * Copyright (c) 2015-2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <platform_def.h>
#include <stdint.h>

#include "wagner_private.h"

/* The power domain tree descriptor */
static unsigned char power_domain_tree_desc[] = {
	/* Number of power domains at the highest power level */
	/* Number of root nodes */
	PLATFORM_CLUSTER_COUNT,
	/* Number of children for the first node */
	PLATFORM_CORE_COUNT
};

/*******************************************************************************
 * This function returns the ARM default topology tree information.
 ******************************************************************************/
const unsigned char *plat_get_power_domain_tree_desc(void)
{
	return power_domain_tree_desc;
}

/*******************************************************************************
 * This function implements a part of the critical interface between the psci
 * generic layer and the platform that allows the former to query the platform
 * to convert an MPIDR to a unique linear index. An error code (-1) is returned
 * in case the MPIDR is invalid.
 ******************************************************************************/
int plat_core_pos_by_mpidr(u_register_t mpidr)
{
	return plat_wagner_calc_core_pos(mpidr);
}


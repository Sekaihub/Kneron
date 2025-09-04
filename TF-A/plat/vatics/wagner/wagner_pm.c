/*
 * Copyright (c) 2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch_helpers.h>
#include <assert.h>
#include <common/debug.h>
#include <drivers/arm/gicv3.h>
#include <drivers/console.h>
#include <errno.h>
#include <lib/mmio.h>
#include <lib/psci/psci.h>
#include <plat/common/platform.h>
#include <platform_def.h>
#include <sysctrl.h>


#define SCPI_POWER_ON		0
#define SCPI_POWER_RETENTION	1
#define SCPI_POWER_OFF		3

#define SCPI_SYSTEM_SHUTDOWN	0
#define SCPI_SYSTEM_REBOOT	1

uintptr_t wagner_sec_entrypoint;
/*******************************************************************************
 * Platform handlers and setup function.
 ******************************************************************************/
static void wagner_cpu_standby(plat_local_state_t cpu_state)
{
	u_register_t scr;

	assert(cpu_state == PLAT_LOCAL_STATE_RET);

	scr = read_scr_el3();
	/* Enable the Non secure interrupt to wake the CPU */
	write_scr_el3(scr | SCR_IRQ_BIT | SCR_FIQ_BIT);
	isb();
	/* dsb is good practice before using wfi to enter low power states */
	dsb();
	/* Enter standby state */
	wfi();
	/* Restore SCR */
	write_scr_el3(scr);
}

/*******************************************************************************
 * Platform handler called when a power domain is about to be turned on. The
 * mpidr determines the CPU to be turned on.
 ******************************************************************************/
int wagner_pwr_domain_on(u_register_t mpidr)
{
	int rc = PSCI_E_SUCCESS;
	int cpu_id = plat_core_pos_by_mpidr(mpidr);

	if ((unsigned int)cpu_id >= PLATFORM_CORE_COUNT) {
		ERROR("%s()  CPU 0x%X\n", __func__, cpu_id);
		return PSCI_E_INVALID_PARAMS;
	}

	if (cpu_id == -1) {
		/* domain on was not called by a CPU */
		ERROR("%s() was not per CPU 0x%X\n", __func__, cpu_id);
		return PSCI_E_INVALID_PARAMS;
	}

	unsigned int pos = (unsigned int)plat_core_pos_by_mpidr(mpidr);
	uintptr_t hold_base = (pos << 2) + SECONDARY_CPU_SPIN_BASE_ADDR;

	assert(pos < PLATFORM_CORE_COUNT);

	mmio_write_32(hold_base, wagner_sec_entrypoint);
	/* No cache maintenance here, hold_base is mapped as device memory. */

	/* Make sure that the write has completed */
	dsb();
	isb();

	sev();

	return rc;
}

/*******************************************************************************
 * plat handler called when a power domain has just been powered on after
 * being turned off earlier. The target_state encodes the low power state that
 * each level has woken up from.
 ******************************************************************************/
void wagner_pwr_domain_on_finish(const psci_power_state_t *target_state)
{
	for (size_t i = 0; i <= PLAT_MAX_PWR_LVL; i++)
		VERBOSE("%s: target_state->pwr_domain_state[%lu]=%x\n",
				__func__, i, target_state->pwr_domain_state[i]);


	unsigned int pos = plat_my_core_pos();
	uintptr_t hold_base = (pos << 2) + SECONDARY_CPU_SPIN_BASE_ADDR;

	/* Clear SPIN flag */
	mmio_write_32(hold_base, 0);

	/* Enable the gic cpu interface */
	gicv3_rdistif_init(pos);
	gicv3_cpuif_enable(pos);
}


static const plat_psci_ops_t wagner_psci_ops = {
	.cpu_standby = wagner_cpu_standby,
	.pwr_domain_on = wagner_pwr_domain_on,
	.pwr_domain_on_finish = wagner_pwr_domain_on_finish,
};

int plat_setup_psci_ops(uintptr_t sec_entrypoint,
			const struct plat_psci_ops **psci_ops)
{
	wagner_sec_entrypoint = sec_entrypoint;
	flush_dcache_range((uint64_t)&wagner_sec_entrypoint,
			sizeof(wagner_sec_entrypoint));

	*psci_ops = &wagner_psci_ops;

	return 0;
}


/* sbhybrid_fw_init.c
 *
 * Firmware initialization of HW engines for use by Secure Boot.
 */

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*   Module        : SecureBoot                                               */
/*   Version       : 4.5                                                      */
/*   Configuration : SecureBoot                                               */
/*                                                                            */
/*   Date          : 2023-Feb-14                                              */
/*                                                                            */
/* Copyright (c) 2007-2023 by Rambus, Inc. and/or its subsidiaries.           */
/* All rights reserved. Unauthorized use (including, without limitation,      */
/* distribution and copying) is strictly prohibited. All use requires,        */
/* and is subject to, explicit written authorization and nondisclosure        */
/* agreements with Rambus, Inc. and/or its subsidiaries.                      */
/*                                                                            */
/* For more information or support, please go to our online support system at */
/* https://sipsupport.rambus.com.                                             */
/* In case you do not have an account for this system, please send an e-mail  */
/* to sipsupport@rambus.com.                                                  */
/* -------------------------------------------------------------------------- */

#ifndef __MODULE__
#define __MODULE__ "sbhybrid_fw_init.c"
#endif

#include "sbhybrid_internal.h"      // the API to implement

#if defined(SBHYBRID_WITH_EIP28) || defined(SBHYBRID_WITH_EIP130)
#include "device_mgmt.h"
#include "device_rw.h"
#endif
#ifdef SBHYBRID_WITH_EIP28
#include "eip28.h"
#endif /* SBHYBRID_WITH_EIP28 */
#ifdef SBHYBRID_WITH_EIP130
#include "dmares_mgmt.h"
#include "dmares_buf.h"
#include "dmares_addr.h"
#include "eip130.h"
#endif /* SBHYBRID_WITH_EIP130 */

#ifdef SBHYBRID_WITH_EIP28
/*----------------------------------------------------------------------------
 * SBHYBRID_Initialize_FW_EIP28
 */
static int
SBHYBRID_Initialize_FW_EIP28(SBHYBRID_EcdsaContext_t * const Context_p,
                             const uint32_t * const Firmware_p,
                             const uint32_t FirmwareWord32Size)
{
    EIP28_Status_t res28;

    L_DEBUG(LF_SBHYBRID, "EIP28 firmware initialization");

    // EIP-28 Initialization
    Context_p->Device_EIP28 = Device_Find(SBLIB_CFG_PKA_DEVICE);
    if (Context_p->Device_EIP28 == NULL)
    {
        L_DEBUG(LF_SBHYBRID,
                "ERROR: PKA Device (%s) not found.",
                SBLIB_CFG_PKA_DEVICE);
        return -1;
    }

    // Initialize the driver library
    // Note this also checks if it is really talking to an EIP-28
    res28 = EIP28_Initialize_CALLATOMIC(&Context_p->EIP28_IOArea,
                                        Context_p->Device_EIP28,
                                        Firmware_p,
                                        FirmwareWord32Size);
    Context_p->Device_EIP28 = NULL;
    if (res28 != EIP28_STATUS_OK)
    {
        L_DEBUG(LF_SBHYBRID,
                "ERROR: EIP28 firmware load failed. (%d)",
                (int)res28);
        return -2;
    }

    return 0;                           // 0 = success
}
#endif /* SBHYBRID_WITH_EIP28 */

#ifdef SBHYBRID_WITH_EIP130
/*----------------------------------------------------------------------------
 * SBHYBRID_Initialize_FW_EIP130
 */
static int
SBHYBRID_Initialize_FW_EIP130(const uint32_t * const Firmware_p,
                              const uint32_t FirmwareWord32Size)
{
    Device_Handle_t DeviceHandle;
    int res;

    L_DEBUG(LF_SBHYBRID, "EIP130 firmware initialization");

    DeviceHandle = Device_Find(SBLIB_CFG_SM_DEVICE);
    if (DeviceHandle == NULL)
    {
        L_DEBUG(LF_SBHYBRID,
                "ERROR: SM Device (%s) not found.",
                SBLIB_CFG_SM_DEVICE);
        return -1;
    }

    res = EIP130_FirmwareLoad(DeviceHandle, SBLIB_CFG_XM_MAILBOXNR,
                              Firmware_p, FirmwareWord32Size);
    if (res < 0)
    {
        L_DEBUG(LF_SBHYBRID,
                "ERROR: SM Device firmware load failed. (%d)",
                res);
        return -2;
    }

    return 0;
}

#endif /* SBHYBRID_WITH_EIP130 */

/*----------------------------------------------------------------------------
 * SBHYBRID_Initialize_FW
 */
SB_Result_t
SBHYBRID_Initialize_FW(SBHYBRID_Context_t * const Context_p,
                       const uint32_t * const Firmware_p,
                       const uint32_t FirmwareWord32Size)
{
#if defined(SBHYBRID_WITH_EIP28) || defined(SBHYBRID_WITH_EIP130)
    int res;
#endif

    L_DEBUG(LF_SBHYBRID, "Initializing firmware.");

#if defined(SBHYBRID_WITH_EIP28) || defined(SBHYBRID_WITH_EIP130)
    // Initialize Driver Framework
    res = Device_Initialize(NULL);
    if (res < 0)
    {
        L_DEBUG(LF_SBHYBRID,
                "ERROR: Driver Framework initialization failed (%d)",
                res);
        return SB_ERROR_HARDWARE;
    }
#endif

#ifdef SBHYBRID_WITH_EIP28
    // EIP-28 Initialization
    if (SBHYBRID_Initialize_FW_EIP28(&Context_p->AlgoContext,
                                     Firmware_p, FirmwareWord32Size) < 0)
    {
        return SB_ERROR_HARDWARE;
    }
#endif /* SBHYBRID_WITH_EIP28 */

#ifdef SBHYBRID_WITH_EIP130
    // EIP-130 Initialisation
    (void)Context_p;
    if (SBHYBRID_Initialize_FW_EIP130(Firmware_p, FirmwareWord32Size) < 0)
    {
        return SB_ERROR_HARDWARE;
    }
#endif /* SBHYBRID_WITH_EIP130 */

    return SB_SUCCESS;
}


/* end of file sbhybrid_fw_init.c */

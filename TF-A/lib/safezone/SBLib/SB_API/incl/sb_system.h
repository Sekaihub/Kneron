/* sb_system.h
 *
 * Description: Secure Boot API: System info access
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

#ifndef INCLUDE_GUARD_SB_SYSTEM_H
#define INCLUDE_GUARD_SB_SYSTEM_H

/* Internal includes. */
#include "public_defs.h"

/** Obtain system information.

    Secure Boot supports system info for Secure Boot purposes.

    @param HWVersion
    Pointer to the variable that contains the hardware version
    upon successful return.

    @param FWVersion
    Pointer to the variable that contains the firmware version
    upon successful return.

    @param MemSize
    Pointer to the variable that contains the size of the memory
    of the SB hardware upon successful return.

    @param ErrorInfo
    Pointer to the variable that contains the error information
    and location upon successful return.

    @return
    Returns SB_SUCCESS on success. All other values indicate that
    an error has occurred. There is one error code that can be
    seen:
     * SB_ERROR_HARDWARE when there is error fetching the object.
       Error may occur due to object type (not PublicData) or access
       permissions or HW, DMA, software misconfiguration.
 */
SB_Result_t
SB_SystemInfo_Read(
    uint32_t * const HWVersion,
    uint32_t * const FWVersion,
    uint32_t * const MemSize,
    uint32_t * const ErrorInfo);


#endif /* INCLUDE_GUARD_SB_SYSTEM_H */

/* end of file sb_system.h */

/* sbhybrid_sw_system_info.c
 *
 * Description: Stub implementation of Secure Boot API.
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

#include "sbhybrid_internal.h"

/* This SB_SystemInfo_Read stub implementation is for non-EIP130 implementations */
#if !defined(SBHYBRID_WITH_EIP130)
#ifndef SBLIB_CF_REMOVE_SYSTEMINFO_READ

#include "implementation_defs.h"
#include "sb_system.h"                  /* API to implement */

/* Interface function for reading system information. */
SB_Result_t
SB_SystemInfo_Read(uint32_t * const HWVersion,
                   uint32_t * const FWVersion,
                   uint32_t * const MemSize,
                   uint32_t * const ErrorInfo)
{
    PARAMETER_NOT_USED(HWVersion);
    PARAMETER_NOT_USED(FWVersion);
    PARAMETER_NOT_USED(MemSize);
    PARAMETER_NOT_USED(ErrorInfo);

    return SB_ERROR_HARDWARE;
}

#endif /* !SBLIB_CF_REMOVE_SYSTEMINFO_READ */
#endif /* !defined(SBHYBRID_WITH_EIP130) */

/* end of file sbhybrid_sw_system_info.c */

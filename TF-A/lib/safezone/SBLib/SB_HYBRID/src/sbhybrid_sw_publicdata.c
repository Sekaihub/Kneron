/* sbhybrid_sw_publicdata.c
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

// This stub implementation of SB_PublicData_read is for non-EIP130 based
// implementation
#if !defined(SBHYBRID_WITH_EIP130)
#ifndef SBLIB_CF_REMOVE_PUBLICDATA

#include "implementation_defs.h"
#include "sb_publicdata.h"              /* API to implement */

/* Interface function for reading Public Data. */
SB_Result_t
SB_PublicData_Read(uint32_t ObjectNr,
                   uint8_t * Data_p,
                   uint32_t * const DataLen_p)
{
    PARAMETER_NOT_USED(ObjectNr);
    PARAMETER_NOT_USED(Data_p);
    PARAMETER_NOT_USED(DataLen_p);

    return SB_ERROR_ARGUMENTS;
}

#endif /* !SBLIB_CF_REMOVE_PUBLICDATA */
#endif /* !defined(SBHYBRID_WITH_EIP130) */

/* end of file sbhybrid_sw_publicdata.c */

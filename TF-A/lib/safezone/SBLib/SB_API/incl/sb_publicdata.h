/* sb_publicdata.h
 *
 * Description: Secure Boot API: Public Data Access
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

#ifndef INCLUDE_GUARD_SB_PUBLICDATA_H
#define INCLUDE_GUARD_SB_PUBLICDATA_H

/* Internal includes. */
#include "public_defs.h"
#include "sb_result.h"

/** Obtain Public Data resource.

    Secure Boot supports Public Data objects stored for Secure Boot purposes.
    Note: This API provides access to Public Data objects as they are stored
          in the NVM/OTP/Memory, the function does not perform any parsing of
          the retrieved data. The parsing of retrieved data needs to be
          performed by the caller.

    @param ObjectNr
    The identity number for the Public Data object to retrieve.

    @param Data_p
    Pointer to the output buffer where the object data will be copied to, or
    NULL just to query the length of the object.
    Size of this this buffer must be provided via *DataLen_p.
    If the function fails, the contents of Data_p can have been changed.
    This buffer will be filled via DMA, thus the buffer is required to be DMA
    accessible memory.

    @param DataLen_p
    In: size, in bytes, of the buffer pointed to by Data_p.
    Out: length of the actual object, in bytes.

    It is possible to query the length of the object by calling this function
    with Data_p = NULL. In that case the object data is not returned, but the
    length will be returned via *DataLen_p.

    @return
    Returns SB_SUCCESS on success. All other values indicate that
    an error has occurred. There are two error codes that can be seen:
     * SB_ERROR_ARGUMENTS when the Object (ObjectNr parameter) is not found or
       there is another problem with the arguments
     * SB_ERROR_HARDWARE when there is error fetching the object.
       Error may occur due to object type (not PublicData) or access
       permissions or HW, DMA, software misconfiguration.
 */
SB_Result_t
SB_PublicData_Read(
    const uint32_t       ObjectNr,
    uint8_t *            Data_p,
    uint32_t *     const DataLen_p);

#endif /* INCLUDE_GUARD_SB_PUBLICDATA_H */

/* end of file sb_publicdata.h */

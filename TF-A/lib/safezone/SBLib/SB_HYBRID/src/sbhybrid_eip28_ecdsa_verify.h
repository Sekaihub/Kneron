/* sbhybrid_eip28_ecdsa_verify.h
 *
 * Description: Secure boot library: Internal definitions for
 *              ECDSA verify with EIP-28.
 */

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*   Module        : SecureBoot                                               */
/*   Version       : 4.3                                                      */
/*   Configuration : SecureBoot                                               */
/*                                                                            */
/*   Date          : 2020-Oct-30                                              */
/*                                                                            */
/* Copyright (c) 2007-2020 by Rambus, Inc. and/or its subsidiaries.           */
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

#ifndef INCLUDE_GUARD_EIP28_ECDSA_VERIFY_H
#define INCLUDE_GUARD_EIP28_ECDSA_VERIFY_H

#include "eip28.h"

typedef struct
{
    uint32_t Step;                  // FSM step of ECDSA calculation
    uint32_t Value_w_Len;           // Length of w value; needed on multiple steps
    uint8_t * Value_e_p;            // Pointer to digest value (length SBHYBRID_DIGEST_BYTES)

    Device_Handle_t Device_EIP28;   // Device handle
    EIP28_IOArea_t EIP28_IOArea;    // Device IO area
}
SBHYBRID_EcdsaContext_t;

void
SBHYBRID_EIP28_EcdsaVerify_Init(
    SBHYBRID_EcdsaContext_t * const Verify_p,
    const SBIF_PublicKey_t * const PublicKey_p,
    const SBIF_Signature_t * const Signature_p);

SB_Result_t
SBHYBRID_EIP28_EcdsaVerify_RunFsm(
    SBHYBRID_EcdsaContext_t * const Verify_p);

void
SBHYBRID_EIP28_EcdsaVerify_SetDigest(
    SBHYBRID_EcdsaContext_t * const Verify_p,
    uint8_t * Digest_p);     // length SBHYBRID_DIGEST_BYTES

#endif /* INCLUDE_GUARD_EIP28_ECDSA_VERIFY_H */

/* end of file sbhybrid_eip28_ecdsa_verify.h */

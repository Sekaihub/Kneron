/* sbhybrid_sw_rsa_verify.h
 *
 * Description: Secure boot library: Internal API for RSA operations.
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

#ifndef INCLUDE_GUARD_SBHYBRID_SW_RSA_VERIFY_H
#define INCLUDE_GUARD_SBHYBRID_SW_RSA_VERIFY_H

#include "sb_sw_rsa_verify.h"

// internal RSA Verification state structure
typedef struct
{
    /* Verification parameters, including domain parameters. */
    bool has_digest;
    uint8_t algo_type;
    uint8_t digest[RSA_DIGEST_BYTES];
    SfzCryptoBigIntPubExp PubkeyExp;
    SfzCryptoBigInt Modulus;
    SfzCryptoBigInt Signature;
}
SBHYBRID_RSA_Verify_t;

void
SBHYBRID_SW_Rsa_Verify_SetPublicKey(
    SBHYBRID_RSA_Verify_t * const Verify_p,
    const SBIF_PublicKey_t * const PublicKey_p);

void
SBHYBRID_SW_Rsa_Verify_SetSignature(
    SBHYBRID_RSA_Verify_t * const Verify_p,
    const SBIF_Signature_t * const Signature_p);

void
SBHYBRID_SW_Rsa_Verify_SetDigest(
    SBHYBRID_RSA_Verify_t * const Verify_p,
    uint8_t * Digest_p);

SB_Result_t
SBHYBRID_SW_Rsa_Verify(
    SBHYBRID_RSA_Verify_t * const Verify_p);

// A front-end for SBHYBRID_Rsa_Verify*:
//    Set public key and signature and mark digest as not yet available.
static inline
void
SBHYBRID_SW_Rsa_Verify_Init(
    SBHYBRID_RSA_Verify_t * const Verify_p,
    const SBIF_PublicKey_t * const PublicKey_p,
    const SBIF_Signature_t * const Signature_p)
{
    SBHYBRID_SW_Rsa_Verify_SetPublicKey(Verify_p, PublicKey_p);
    SBHYBRID_SW_Rsa_Verify_SetSignature(Verify_p, Signature_p);
    Verify_p->has_digest = false;
}

// A front-end for SBHYBRID_Rsa_Verify:
//    Run verify at once when digest is known.
static inline
SB_Result_t
SBHYBRID_SW_Rsa_Verify_RunFsm(
    SBHYBRID_RSA_Verify_t * const Verify_p)
{
    /* Return pending if digest is not yet available. */
    if (!Verify_p->has_digest)
    {
        return SB_ERROR_COUNT;
    }

    /* Calculate RSA Verify if the digest is available. */
    return SBHYBRID_SW_Rsa_Verify(Verify_p);
}

#endif /* INCLUDE_GUARD_SBHYBRID_SW_RSA_VERIFY_H */

/* end of file sbhybrid_sw_rsa_verify.h */

/* sbhybrid_sw_rsa_verify.c
 *
 * SW-only RSA Verify service for Secure Boot Library.
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

#ifdef SBHYBRID_WITH_SWPK

void
SBHYBRID_SW_Rsa_Verify_SetPublicKey(SBHYBRID_RSA_Verify_t * const Verify_p,
                                    const SBIF_PublicKey_t * const PublicKey_p)
{
    PRECONDITION(PublicKey_p != NULL);

    c_memcpy(Verify_p->PubkeyExp.data, PublicKey_p->pubkeyExp, sizeof(PublicKey_p->pubkeyExp));
    Verify_p->PubkeyExp.byteLen = sizeof(PublicKey_p->pubkeyExp);
    c_memcpy(Verify_p->Modulus.data, PublicKey_p->modulus, sizeof(PublicKey_p->modulus));
    Verify_p->Modulus.byteLen = sizeof(PublicKey_p->modulus);
}

void
SBHYBRID_SW_Rsa_Verify_SetSignature(SBHYBRID_RSA_Verify_t * const Verify_p,
                                    const SBIF_Signature_t * const Signature_p)
{
    PRECONDITION(Signature_p != NULL);

    c_memcpy(Verify_p->Signature.data, Signature_p->signature, sizeof(Signature_p->signature));
    Verify_p->Signature.byteLen = sizeof(Signature_p->signature);
}


void
SBHYBRID_SW_Rsa_Verify_SetDigest(SBHYBRID_RSA_Verify_t * const Verify_p,
                                 uint8_t * Digest_p)
{
    PRECONDITION(Digest_p != NULL);

    c_memcpy(Verify_p->digest, Digest_p, sizeof(Verify_p->digest));
    Verify_p->has_digest = true;
}


/* SBHYBRID_SW_Rsa_Verify
 */
SB_Result_t
SBHYBRID_SW_Rsa_Verify(SBHYBRID_RSA_Verify_t * const Verify_p)
{
    bool res;

    /* The symmetric processing is ready, do asymmetric processing. */
#if (SBIF_RSA_BITS == 2048) || (SBIF_RSA_BITS == 3072) || (SBIF_RSA_BITS == 4096)
    res = SB_SW_RSA_Verify(Verify_p->digest,
                           &Verify_p->Signature,
                           &Verify_p->PubkeyExp,
                           &Verify_p->Modulus,
                           Verify_p->algo_type);
#else
    res = false;
#endif

    return res ? SB_SUCCESS : SB_ERROR_VERIFICATION;
}

#else
extern const char * sbhybrid_empty_file; /* C forbids empty source files. */
#endif /* SBHYBRID_WITH_SWPK */

/* end of file sbhybrid_sw_rsa_verify.c */

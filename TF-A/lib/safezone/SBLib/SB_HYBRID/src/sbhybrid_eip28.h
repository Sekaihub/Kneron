/* sbhybrid_eip28.h
 *
 * Description: Secure boot library: Internal definitions for SB_HYBRID_EIP28
 *              implementation of Secure Boot API.
 *              SB_HYBRID allows to choose implementation of symmetric
 *              cryptography and asymmetric cryptography independently.
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

#ifndef INCLUDE_GUARD_SBHYBRID_EIP28_INTERNAL_H
#define INCLUDE_GUARD_SBHYBRID_EIP28_INTERNAL_H

typedef struct
{
    uint32_t Step;                  // FSM step of RSA calculation
    uint32_t Value_w_Len;           // Length of w value; needed on multiple steps
    uint8_t * Value_e_p;            // Pointer to digest value (length SBHYBRID_DIGEST_BYTES)

    Device_Handle_t Device_EIP28;   // Device handle
    EIP28_IOArea_t EIP28_IOArea;    // Device IO area

#ifdef SUPPORT_RSA_PSS
    SBHYBRID_SymmContext_t * HashEngineContext_p;
#endif
}
SBHYBRID_EIP28_Context_t;

#ifdef SBIF_ECDSA

void
SBHYBRID_EIP28_EcdsaVerify_Init(
    SBHYBRID_EIP28_Context_t * const Verify_p,
    const SBIF_PublicKey_t * const PublicKey_p,
    const SBIF_Signature_t * const Signature_p);

SB_Result_t
SBHYBRID_EIP28_EcdsaVerify_RunFsm(
    SBHYBRID_EIP28_Context_t * const Verify_p);

void
SBHYBRID_EIP28_EcdsaVerify_SetDigest(
    SBHYBRID_EIP28_Context_t * const Verify_p,
    uint8_t * Digest_p);     // length SBHYBRID_DIGEST_BYTES

#define SBHYBRID_Verify_Init      SBHYBRID_EIP28_EcdsaVerify_Init
#define SBHYBRID_Verify_RunFsm    SBHYBRID_EIP28_EcdsaVerify_RunFsm
#define SBHYBRID_Verify_SetDigest SBHYBRID_EIP28_EcdsaVerify_SetDigest

#else

void
SBHYBRID_EIP28_RSAVerify_Init(
    SBHYBRID_EIP28_Context_t * const Verify_p,
    const SBIF_PublicKey_t * const PublicKey_p,
    const SBIF_Signature_t * const Signature_p);

SB_Result_t
SBHYBRID_EIP28_RSAVerify_RunFsm(
    SBHYBRID_EIP28_Context_t * const Verify_p);

void
SBHYBRID_EIP28_RSAVerify_SetDigest(
    SBHYBRID_EIP28_Context_t * const Verify_p,
    uint8_t * Digest_p);     // length SBHYBRID_DIGEST_BYTES

#define SBHYBRID_Verify_Init      SBHYBRID_EIP28_RSAVerify_Init
#define SBHYBRID_Verify_RunFsm    SBHYBRID_EIP28_RSAVerify_RunFsm
#define SBHYBRID_Verify_SetDigest SBHYBRID_EIP28_RSAVerify_SetDigest

#endif /* SBIF_ECDSA */

#endif
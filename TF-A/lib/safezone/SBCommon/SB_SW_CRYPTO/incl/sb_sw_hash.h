/**
 *  File: sb_sw_hash.h
 *
 *  Description : Secure Boot Hash Interface.
 *
 *                Secure Boot ECDSA calculation uses this header to specify
 *                interface it uses to interact with Hash calculation.
 *
 *                The interface depends on SBIF_ECDSA_WORDS, which declares size
 *                of ECDSA calculated (and therefore) the size of output of HASH
 *                calculation.
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

#ifndef INCLUDE_GUARD_SB_SW_HASH_H
#define INCLUDE_GUARD_SB_SW_HASH_H

#include "public_defs.h"
#include "sbif.h"

#ifdef SBSWCRYPTO_CF_FULL_FUNCTIONALITY

/* Enable all hash algorithms */
#ifndef SB_SW_HASH_SHA224
#define SB_SW_HASH_SHA224
#endif
#ifndef SB_SW_HASH_SHA256
#define SB_SW_HASH_SHA256
#endif
#ifndef SB_SW_HASH_SHA384
#define SB_SW_HASH_SHA384
#endif
#ifndef SB_SW_HASH_SHA512
#define SB_SW_HASH_SHA512
#endif

#else

#ifdef SBIF_CFG_DERIVE_WRAPKEY_FROM_KDK
/* SHA256 is needed to support key derivation */
#ifndef SB_SW_HASH_SHA256
#define SB_SW_HASH_SHA256
#endif
#endif

#ifdef SBIF_ECDSA
/* Hash algorithm is derived from ECDSA operation to perform */
#if SBIF_ECDSA_WORDS == 7
#ifndef SB_SW_HASH_SHA224
#define SB_SW_HASH_SHA224
#endif
#elif SBIF_ECDSA_WORDS == 8
#ifndef SB_SW_HASH_SHA256
#define SB_SW_HASH_SHA256
#endif
#elif SBIF_ECDSA_WORDS == 12
#ifndef SB_SW_HASH_SHA384
#define SB_SW_HASH_SHA384
#endif
#elif SBIF_ECDSA_WORDS == 17
#ifndef SB_SW_HASH_SHA512
#define SB_SW_HASH_SHA512
#endif
#else /* SBIF_ECDSA_WORDS != 7 && SBIF_ECDSA_WORDS != 8 && SBIF_ECDSA_WORDS != 12 && SBIF_ECDSA_WORDS != 17 */
#error "SBIF_ECDSA_WORDS is not 7, 8, 12 or 17."
#endif /* SBIF_ECDSA_WORDS == 7 || SBIF_ECDSA_WORDS == 8 || SBIF_ECDSA_WORDS == 12 || SBIF_ECDSA_WORDS == 17 */
#endif /* SBIF_ECDSA */

#ifdef SBIF_RSA
/* Hash algorithm is always SHA-256 */
#ifndef SB_SW_HASH_SHA256
#define SB_SW_HASH_SHA256
#endif
#endif

#endif

typedef struct SB_SW_HASH_Context
{
    uint32_t type;                      /* hash type */
    uint32_t blocksize;                 /* hash block size */
    uint32_t bitcount;                  /* Assumption: image size < 512MB */
    uint32_t state[16];                 /* a, b, c, d, e, f, g, h [32/64bits] */
//#ifdef SHA2_CONTEXT_WITH_EMBEDDED_WORKSPACE
    uint32_t workspace[8];              /* a, b, c, d, e, f, g, h */
    uint32_t W[64];                     /* 64 rounds in SHA-256. */
//#endif
} SB_SW_HASH_Context_t;

void SB_SW_HASH_Init(
    SB_SW_HASH_Context_t * const ctx_p,
    uint32_t HashType);

void SB_SW_HASH_Update(
    SB_SW_HASH_Context_t * const ctx_p,
    const uint8_t * const data_p,
    const uint32_t len);

void SB_SW_HASH_FinalUpdate(
    SB_SW_HASH_Context_t * const ctx_p,
    const uint8_t * const data_p,
    const uint32_t len,
    uint32_t *digest);

/* Transform function. Intended for internal usage only. */
void SB_SW_HASH_Transform(
    SB_SW_HASH_Context_t * const ctx_p,
    const void * const data_block_p);

#if defined(SB_SW_HASH_SHA384) || defined(SB_SW_HASH_SHA512)
#ifdef SB_SW_HASH_SHA384
void SB_SW_HASH_SHA384_LoadDefaultDigest(
    uint32_t * Digest_p);
#endif

void SB_SW_HASH_SHA512_LoadDefaultDigest(
    uint32_t * Digest_p);

void SB_SW_HASH_SHA512_ProcessBlock(
    uint32_t * Digest_p,
    const uint8_t * DataBytes_p);
#endif

#endif /* INCLUDE_GUARD_SB_SW_HASH_H */

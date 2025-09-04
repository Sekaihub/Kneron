/* sbhybrid_sw.h
 *
 * Description: Secure boot library: Internal definitions for SB_HYBRID_SW
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

#ifndef INCLUDE_GUARD_SBHYBRID_SW_INTERNAL_H
#define INCLUDE_GUARD_SBHYBRID_SW_INTERNAL_H

#ifdef SBHYBRID_WITH_SWPK
#ifdef SBIF_ECDSA
#include "sbhybrid_sw_ecdsa_verify.h"
#define SBHYBRID_Verify_Init      SBHYBRID_SW_Ecdsa_Verify_Init
#define SBHYBRID_Verify_RunFsm    SBHYBRID_SW_Ecdsa_Verify_RunFsm
#define SBHYBRID_Verify_SetDigest SBHYBRID_SW_Ecdsa_Verify_SetDigest
#else
#include "sbhybrid_sw_rsa_verify.h"
#define SBHYBRID_Verify_Init      SBHYBRID_SW_Rsa_Verify_Init
#define SBHYBRID_Verify_RunFsm    SBHYBRID_SW_Rsa_Verify_RunFsm
#define SBHYBRID_Verify_SetDigest SBHYBRID_SW_Rsa_Verify_SetDigest
#endif /* SBIF_ECDSA */
#endif /* SBHYBRID_WITH_SWPK */

#ifdef SBHYBRID_WITH_SW
#include "sb_sw_hash.h"

/* Choose SHA implementation to use according to SBIF_ECDSA_WORDS/SBIF_RSA_BITS
   (SHA-224, SHA-256, SHA-384 or SHA-512). */
/* No DMA contexts to free. */
#define SBHYBRID_SHA2XX_DmaRelease(SymmContext_p) do { } while(0)

#if SBIF_ECDSA_WORDS == 17
#define SBHYBRID_SHA2XX_Init      SBHYBRID_SW_SHA512_Init
#define SBHYBRID_SHA2XX_AddBlock  SBHYBRID_SW_SHA512_AddBlock
#define SBHYBRID_SHA2XX_RunFsm    SBHYBRID_SW_SHA512_RunFsm
#define SBHYBRID_SHA2XX_GetDigest SBHYBRID_SW_SHA512_GetDigest
#elif SBIF_ECDSA_WORDS == 12
#define SBHYBRID_SHA2XX_Init      SBHYBRID_SW_SHA384_Init
#define SBHYBRID_SHA2XX_AddBlock  SBHYBRID_SW_SHA384_AddBlock
#define SBHYBRID_SHA2XX_RunFsm    SBHYBRID_SW_SHA384_RunFsm
#define SBHYBRID_SHA2XX_GetDigest SBHYBRID_SW_SHA384_GetDigest
#elif SBIF_ECDSA_WORDS == 8
#define SBHYBRID_SHA2XX_Init      SBHYBRID_SW_SHA256_Init
#define SBHYBRID_SHA2XX_AddBlock  SBHYBRID_SW_SHA256_AddBlock
#define SBHYBRID_SHA2XX_RunFsm    SBHYBRID_SW_SHA256_RunFsm
#define SBHYBRID_SHA2XX_GetDigest SBHYBRID_SW_SHA256_GetDigest
#elif SBIF_ECDSA_WORDS == 7
#define SBHYBRID_SHA2XX_Init      SBHYBRID_SW_SHA224_Init
#define SBHYBRID_SHA2XX_AddBlock  SBHYBRID_SW_SHA224_AddBlock
#define SBHYBRID_SHA2XX_RunFsm    SBHYBRID_SW_SHA224_RunFsm
#define SBHYBRID_SHA2XX_GetDigest SBHYBRID_SW_SHA224_GetDigest
#endif

#if ((SBIF_RSA_BITS == 2048) || (SBIF_RSA_BITS == 3072) || (SBIF_RSA_BITS == 4096))
#define SBHYBRID_SHA2XX_Init      SBHYBRID_SW_SHA256_Init
#define SBHYBRID_SHA2XX_AddBlock  SBHYBRID_SW_SHA256_AddBlock
#define SBHYBRID_SHA2XX_RunFsm    SBHYBRID_SW_SHA256_RunFsm
#define SBHYBRID_SHA2XX_GetDigest SBHYBRID_SW_SHA256_GetDigest
#endif

static inline SB_Result_t
SBHYBRID_SW_SHA512_Init(SBHYBRID_SymmContext_t * const Hash_p)
{
    SB_SW_HASH_Init(&Hash_p->hash_ctx, 512);
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA512_AddBlock(SBHYBRID_SymmContext_t * const Hash_p,
                            const uint8_t * DataBytes_p,
                            unsigned int DataByteCount,
                            bool fFinal)
{
    if (fFinal)
    {
        SB_SW_HASH_FinalUpdate(&Hash_p->hash_ctx,
                               DataBytes_p, DataByteCount,
                               Hash_p->hash_out);
    }
    else
    {
        SB_SW_HASH_Update(&Hash_p->hash_ctx, DataBytes_p, DataByteCount);
    }
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA512_RunFsm(SBHYBRID_SymmContext_t * const Hash_p)
{
    IDENTIFIER_NOT_USED(Hash_p);
    return SB_SUCCESS;                  /* There is never pending operations. */
}

static inline void
SBHYBRID_SW_SHA512_GetDigest(SBHYBRID_SymmContext_t * const Hash_p,
                             uint8_t * Digest_p)
{
    int i;
    for (i = 0; i < 16; i++)
    {
        uint32_t word = Hash_p->hash_out[15 - i];
        BE32_WRITE(Digest_p, word);
        Digest_p += 4;
    }
}

static inline SB_Result_t
SBHYBRID_SW_SHA384_Init(SBHYBRID_SymmContext_t * const Hash_p)
{
    SB_SW_HASH_Init(&Hash_p->hash_ctx, 384);
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA384_AddBlock(SBHYBRID_SymmContext_t * const Hash_p,
                            const uint8_t * DataBytes_p,
                            unsigned int DataByteCount,
                            bool fFinal)
{
    if (fFinal)
    {
        SB_SW_HASH_FinalUpdate(&Hash_p->hash_ctx,
                               DataBytes_p, DataByteCount,
                               Hash_p->hash_out);
    }
    else
    {
        SB_SW_HASH_Update(&Hash_p->hash_ctx, DataBytes_p, DataByteCount);
    }
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA384_RunFsm(SBHYBRID_SymmContext_t * const Hash_p)
{
    IDENTIFIER_NOT_USED(Hash_p);
    return SB_SUCCESS;                  /* There is never pending operations. */
}

static inline void
SBHYBRID_SW_SHA384_GetDigest(SBHYBRID_SymmContext_t * const Hash_p,
                             uint8_t * Digest_p)
{
    int i;
    for (i = 0; i < 12; i++)
    {
        uint32_t word = Hash_p->hash_out[11 - i];
        BE32_WRITE(Digest_p, word);
        Digest_p += 4;
    }
}

static inline SB_Result_t
SBHYBRID_SW_SHA256_Init(SBHYBRID_SymmContext_t * const Hash_p)
{
    SB_SW_HASH_Init(&Hash_p->hash_ctx, 256);
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA256_AddBlock(SBHYBRID_SymmContext_t * const Hash_p,
                            const uint8_t * DataBytes_p,
                            unsigned int DataByteCount,
                            bool fFinal)
{
    if (fFinal)
    {
        SB_SW_HASH_FinalUpdate(&Hash_p->hash_ctx,
                               DataBytes_p, DataByteCount,
                               Hash_p->hash_out);
    }
    else
    {
        SB_SW_HASH_Update(&Hash_p->hash_ctx, DataBytes_p, DataByteCount);
    }
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA256_RunFsm(SBHYBRID_SymmContext_t * const Hash_p)
{
    IDENTIFIER_NOT_USED(Hash_p);
    return SB_SUCCESS;                  /* There is never pending operations. */
}

static inline void
SBHYBRID_SW_SHA256_GetDigest(SBHYBRID_SymmContext_t * const Hash_p,
                             uint8_t * Digest_p)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        uint32_t word = Hash_p->hash_out[7 - i];
        BE32_WRITE(Digest_p, word);
        Digest_p += 4;
    }
}

static inline SB_Result_t
SBHYBRID_SW_SHA224_Init(SBHYBRID_SymmContext_t * const Hash_p)
{
    SB_SW_HASH_Init(&Hash_p->hash_ctx, 224);
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA224_AddBlock(SBHYBRID_SymmContext_t * const Hash_p,
                            const uint8_t * DataBytes_p,
                            unsigned int DataByteCount,
                            bool fFinal)
{
    if (fFinal)
    {
        SB_SW_HASH_FinalUpdate(&Hash_p->hash_ctx,
                               DataBytes_p, DataByteCount,
                               Hash_p->hash_out);
    }
    else
    {
        SB_SW_HASH_Update(&Hash_p->hash_ctx, DataBytes_p, DataByteCount);
    }
    return SB_SUCCESS;
}

static inline SB_Result_t
SBHYBRID_SW_SHA224_RunFsm(SBHYBRID_SymmContext_t * const Hash_p)
{
    IDENTIFIER_NOT_USED(Hash_p);
    return SB_SUCCESS;                  /* There is never pending operations. */
}

static inline void
SBHYBRID_SW_SHA224_GetDigest(SBHYBRID_SymmContext_t * const Hash_p,
                             uint8_t * Digest_p)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        uint32_t word = Hash_p->hash_out[6 - i];
        BE32_WRITE(Digest_p, word);
        Digest_p += 4;
    }
}


#endif /* SBHYBRID_WITH_SW */

#endif /* INCLUDE_GUARD */

/* end of file sbhybrid_sw.h */
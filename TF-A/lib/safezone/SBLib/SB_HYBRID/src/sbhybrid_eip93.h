/* sbhybrid_eip93.h
 *
 * Description: Secure boot library: Internal definitions for SB_HYBRID_EIP93
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

#ifndef INCLUDE_GUARD_SBHYBRID_EIP93_INTERNAL_H
#define INCLUDE_GUARD_SBHYBRID_EIP93_INTERNAL_H

#include "dmares_buf.h"
#include "dmares_types.h"          // DMAResource_Handle_t
#include "eip93.h"

#define SBHYBRID_SASTATE_BYTES              ((32 + 14) * 4) // size of SA + State
#define SBHYBRID_SASTATE_WORDS              (SBHYBRID_SASTATE_BYTES / 4)
#define SBHYBRID_SASTATE_WORDOFFSET_KEY     (2)
#define SBHYBRID_SASTATE_WORDOFFSET_IV      (32 + 0)
#define SBHYBRID_SASTATE_WORDOFFSET_DIGEST  (32 + 6)
/* These are for single block ECB: State is reused as single block buffer. */
#define SBHYBRID_SASTATE_WORDOFFSET_INPUT   (32 + 0)
#define SBHYBRID_SASTATE_WORDOFFSET_OUTPUT  SBHYBRID_SASTATE_WORDOFFSET_IV

#ifndef SBHYBRID_MAX_SIZE_DATA_BLOCKS
#define SBHYBRID_MAX_SIZE_DATA_BLOCKS       (0x3FFF * 64)
#define SBHYBRID_MAX_SIZE_DATA_BYTES        0x0FFFFF
#define SBHYBRID_MAX_DESCRIPTORS_PER_VECTOR (SBLIB_CFG_DATASIZE_MAX / SBHYBRID_MAX_SIZE_DATA_BLOCKS)
#endif

#define SA_STATE_HASH 0
#define SA_STATE_CIPHER 1
#define SA_STATE_CIPHER_OFFSET (SBHYBRID_SASTATE_BYTES / 4)

// free all DMA handles, except
// SymmContext_p->SA_States[SA_STATE_CIPHER].Handle
// and RingMemory.CommandRingHandle
// which is SymmContext_p->DMAHandles.Handles[0]
#define SBHYBRID_SHA2XX_DmaRelease(Context_p)                   \
    while((Context_p)->DMAHandles.Count > 1)                    \
    {                                                           \
        (Context_p)->DMAHandles.Count--;                        \
        DMAResource_Release((Context_p)->DMAHandles.Handles[(Context_p)->DMAHandles.Count]); \
    }

#if SBIF_ECDSA_WORDS == 8 || defined(SBIF_CFG_RSA_BITS)
#define SBHYBRID_SHA2XX_Init       SBHYBRID_EIP93_SHA256_Init
#define SBHYBRID_SHA2XX_AddBlock   SBHYBRID_EIP93_SHA256_AddBlock
#define SBHYBRID_SHA2XX_RunFsm     SBHYBRID_EIP93_SHA256_RunFsm
#define SBHYBRID_SHA2XX_GetDigest  SBHYBRID_EIP93_SHA256_GetDigest
#elif SBIF_ECDSA_WORDS == 7
#define SBHYBRID_SHA2XX_Init       SBHYBRID_EIP93_SHA224_Init
#define SBHYBRID_SHA2XX_AddBlock   SBHYBRID_EIP93_SHA224_AddBlock
#define SBHYBRID_SHA2XX_RunFsm     SBHYBRID_EIP93_SHA224_RunFsm
#define SBHYBRID_SHA2XX_GetDigest  SBHYBRID_EIP93_SHA224_GetDigest
#endif /* SBIF_ECDSA_WORDS */

SB_Result_t
SBHYBRID_EIP93_SHA256_Init(SBHYBRID_SymmContext_t * const Hash_p);

SB_Result_t
SBHYBRID_EIP93_SHA256_AddBlock(SBHYBRID_SymmContext_t * const Hash_p,
                               const uint8_t * DataBytes_p,
                               unsigned int DataByteCount,
                               bool fFinal);

SB_Result_t
SBHYBRID_EIP93_SHA256_RunFsm(SBHYBRID_SymmContext_t * const Hash_p);

void
SBHYBRID_EIP93_SHA256_GetDigest(SBHYBRID_SymmContext_t * const Hash_p,
                                uint8_t * Digest_p);

SB_Result_t
SBHYBRID_EIP93_SHA224_Init(SBHYBRID_SymmContext_t * const Hash_p);

SB_Result_t
SBHYBRID_EIP93_SHA224_AddBlock(SBHYBRID_SymmContext_t * const Hash_p,
                               const uint8_t * DataBytes_p,
                               unsigned int DataByteCount,
                               bool fFinal);

SB_Result_t
SBHYBRID_EIP93_SHA224_RunFsm(SBHYBRID_SymmContext_t * const Hash_p);

void
SBHYBRID_EIP93_SHA224_GetDigest(SBHYBRID_SymmContext_t * const Hash_p,
                                uint8_t * Digest_p);

#endif


/* end of file sbhybrid_eip93.h */
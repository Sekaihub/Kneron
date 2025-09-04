/* sbhybrid_internal.h
 *
 * Description: Secure boot library: Internal definitions for SB_HYBRID
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

#ifndef INCLUDE_GUARD_SBHYBRID_INTERNAL_H
#define INCLUDE_GUARD_SBHYBRID_INTERNAL_H

#include "sb_common.h"
#include "endian_utils.h"
#include "device_types.h"          // Device_Handle_t
#include "cf_sblib.h"              // Configuration toggles
#include "cfg_sblib.h"             // Configuration values
#include "aes_if.h"                // AES_IF_ResultCode_t
#include "sbhybrid_trace.h"        // Trace logging macros

/* Configure according to SB_SW, SB_PK, SB_PEPK, ... */
#define SB_SM
#ifdef SB_SW
#define SBHYBRID_WITH_SW
#define SBHYBRID_WITH_SWPK
#include "sb_sw_hash.h" // SB_SW_HASH_Context_t
#endif
#ifdef SB_PK
#define SBHYBRID_WITH_SW
#define SBHYBRID_WITH_EIP28
#define SBHYBRID_DO_DMARESOURCE_RELEASE
#include "sb_sw_hash.h" // SB_SW_HASH_Context_t
#include "eip28.h"
#endif
#ifdef SB_PE
#define SBHYBRID_WITH_EIP93
#define SBHYBRID_WITH_SWPK
#define SBHYBRID_DO_DMARESOURCE_RELEASE
#include "dmares_buf.h"
#include "dmares_types.h"
#include "eip93.h"
#endif
#ifdef SB_PEPK
#define SBHYBRID_WITH_EIP93
#define SBHYBRID_WITH_EIP28
#define SBHYBRID_DO_DMARESOURCE_RELEASE
#include "dmares_buf.h"
#include "dmares_types.h"          // DMAResource_Handle_t
#include "eip93.h"
#include "eip28.h"
#endif
#ifdef SB_SM
#define SBHYBRID_WITH_EIP130
#define SBHYBRID_WITH_EIP130PK
#define SBHYBRID_DO_DMARESOURCE_RELEASE
#include "dmares_buf.h"
#include "dmares_types.h"
#include "eip130.h"
#endif

/* Check for illegal config combinations */
#if defined(SBHYBRID_WITH_SW) + defined(SBHYBRID_WITH_EIP93) + \
    defined(SBHYBRID_WITH_EIP130) != 1
#error "Define one of: SBHYBRID_WITH_SW, SBHYBRID_WITH_EIP93 or SBHYBRID_WITH_EIP130 ."
#endif /* SBHYBRID_WITH_* */

#if defined(SBHYBRID_WITH_SWPK) + defined(SBHYBRID_WITH_EIP28) + \
    defined(SBHYBRID_WITH_EIP130PK) != 1
#error "Define one of: SBHYBRID_WITH_SWPK, SBHYBRID_WITH_EIP28 or SBHYBRID_WITH_EIP130PK."
#endif /* SBHYBRID_WITH_* */

#if (defined(SBHYBRID_WITH_EIP130PK) && !defined(SBHYBRID_WITH_EIP130)) || \
    (defined(SBHYBRID_WITH_EIP130) && !defined(SBHYBRID_WITH_EIP130PK))
#error "SBHYBRID_WITH_EIP130PK must be used in combination with SBHYBRID_WITH_EIP130."
#endif /* SBHYBRID_WITH_* */

#if defined(SBHYBRID_WITH_EIP28) && defined(SBHYBRID_WITH_EIP93) && defined(SUPPORT_RSA_PSS)
#error "RSA PSS using EIP28 and EIP93 is currently not supported!"
#endif

/* Set digest size */
#ifdef SBIF_ECDSA
#if SBIF_ECDSA_WORDS != 7 && SBIF_ECDSA_WORDS != 8 && SBIF_ECDSA_WORDS != 12 && SBIF_ECDSA_WORDS != 17
#error "Unsupported SBIF_ECDSA_WORDS"
#else
#if SBIF_ECDSA_WORDS == 17
#define SBHYBRID_DIGEST_BYTES           64
#else
#define SBHYBRID_DIGEST_BYTES           SBIF_ECDSA_BYTES
#endif
#endif
#elif defined(SBIF_RSA)
#if SBIF_RSA_BITS != 2048 && SBIF_RSA_BITS != 3072 && SBIF_RSA_BITS != 4096
#error "Unsupported SBIF_RSA_BITS"
#else
#define SBHYBRID_DIGEST_BYTES           32
#endif
#else /* !SBIF_ECDSA && !SBIF_RSA*/
#error "SBIF_ECDSA or SBIF_RSA not defined"
#endif

/* Defines required in construction of the SBHYBRID_SymmContext_t struct */
#ifdef SBHYBRID_WITH_EIP130
#if (SBIF_ECDSA_BYTES <= 32) || defined(SBIF_RSA)
#define SBHYBRID_HASH_BLOCK (64)
#else
#define SBHYBRID_HASH_BLOCK (128)
#endif

#define SBHYBRID_MAX_SIZE_LAST_DATA_BLOCK   (2048)
#define SBHYBRID_MAX_SIZE_DATA_BLOCKS       (0x3FFF * SBHYBRID_HASH_BLOCK)
#define SBHYBRID_MAX_SIZE_DATA_BYTES        0x1FFFFF
#define SBHYBRID_MAX_DMA_HANDLES            (SBLIB_CFG_DATASIZE_MAX / SBHYBRID_MAX_SIZE_DATA_BYTES)
#endif /* SBHYBRID_WITH_EIP130 */

#ifdef SBHYBRID_WITH_EIP93
#define SBHYBRID_MAX_SIZE_DATA_BLOCKS       (0x3FFF * 64)
#define SBHYBRID_MAX_SIZE_DATA_BYTES        0x0FFFFF
#define SBHYBRID_MAX_DESCRIPTORS_PER_VECTOR (SBLIB_CFG_DATASIZE_MAX / SBHYBRID_MAX_SIZE_DATA_BLOCKS)
#endif /* SBHYBRID_WITH_EIP93 */

#ifdef SBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
#undef  SBLIB_CFG_CERTIFICATES_MAX
#define SBLIB_CFG_CERTIFICATES_MAX 0
#endif

// Use count of error codes as internal PENDING status return code
#define SBHYBRID_PENDING SB_ERROR_COUNT

typedef struct
{
#ifdef SBHYBRID_WITH_SW
    void * AesIfCtx[100 / sizeof(void *)];
    SB_SW_HASH_Context_t hash_ctx;
    uint32_t hash_out[16];               // Reserved for 512 bit (SHA-224, SHA-256, SHA-384 and SHA-512 will fit)
#endif /* SBHYBRID_WITH_SW */
#ifdef SBIF_ECDSA
    uint8_t Digest[SBIF_ECDSA_BYTES]; // plain 8bit byte array format
#else
    uint8_t Digest[RSA_DIGEST_BYTES]; // plain 8bit byte array format
#endif
#ifndef SBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
#ifdef SBIF_ECDSA
    uint8_t CertDigest[SBLIB_CFG_CERTIFICATES_MAX][SBIF_ECDSA_BYTES];
#else
    uint8_t CertDigest[SBLIB_CFG_CERTIFICATES_MAX][RSA_DIGEST_BYTES];
#endif
#endif /* !SBLIB_CF_REMOVE_CERTIFICATE_SUPPORT */
#ifdef SBHYBRID_WITH_EIP93
    unsigned int PendingCount;
    Device_Handle_t Device_EIP93;
    EIP93_IOArea_t EIP93_IOArea;
    struct
    {
        DMAResource_Handle_t Handle;
        uint32_t   SA_PhysAddr;
        uint32_t   State_PhysAddr;      // state follows SA
        uint32_t * SA_Host_p;
        uint32_t * State_Host_p;        // state follows SA
    } SA_States[2];
    struct
    {
        /* Handles: According to Maximum Ring Size * 1,5, because
           half of the operations have both input and output handle.
           +1 for the ring itself. */
        DMAResource_Handle_t Handles[((SBHYBRID_MAX_DESCRIPTORS_PER_VECTOR + 2)* 3)+ 1];
        unsigned int Count;
    } DMAHandles;
#endif /* SBHYBRID_WITH_EIP93 */
#ifdef SBHYBRID_WITH_EIP130
    Device_Handle_t   Device_EIP130;
    uint16_t          InitCount;
    uint16_t          TokenId;

    uint32_t DMAHandleCount;
    DMAResource_Handle_t DMAHandles[(SBHYBRID_MAX_DMA_HANDLES + 1)* 2];

    // Members related to the hash operation
    bool HashInitialize;
    bool HashFinalize;
    bool HashDigestValid;
    uint32_t HashTempAssetId;
    uint64_t HashTotalLength;
#if (SBIF_ECDSA_BYTES <= 32) || defined(SBIF_RSA)
    uint8_t Hash[32];
#else
    uint8_t Hash[64];
#endif
#ifdef SBHYBRID_WITH_EIP130PK
    const uint8_t * HashData_p;
    uint16_t HashDataLength;

    // Members related to the ECDSA/RSA verify operation
    uint32_t KeyAssetId;
    uint32_t ParamsAssetId;
    uint32_t ParamsInBytes;
    uint32_t PublicKeyInBytes;
    uint32_t SignatureInBytes;
#ifdef SBIF_ECDSA
#ifdef SBLIB_CFG_SM_COPY_CURVEPARAMS
    uint8_t * Params;
    uint8_t  PublicKeyParams_Buffer[(6 * (4 + SBIF_ECDSA_WORDS * 4)) + 8];
#else
    const uint8_t * Params;
#endif /* SBLIB_CFG_SM_COPY_CURVEPARAMS */
#endif /* SBIF_ECDSA */
#ifdef SBIF_ECDSA
    uint8_t  PublicKey_Buffer[2 * (4 + SBIF_ECDSA_WORDS * 4)];
    uint8_t  Signature_Buffer[2 * (4 + SBIF_ECDSA_WORDS * 4)];
#else
    uint8_t  PublicKey_Buffer[8 + SBIF_RSA_WORDS * 4 + 4];
    uint8_t  Signature_Buffer[4 + SBIF_RSA_WORDS * 4];
#endif /* SBIF_ECDSA */
#endif /* SBHYBRID_WITH_EIP130PK */
#endif /* SBHYBRID_WITH_EIP130 */
} SBHYBRID_SymmContext_t;


// Internal type of image used by PK Image processing code.
typedef enum
{
    SBHYBRID_IMAGE_NONE,
    SBHYBRID_IMAGE_P
}
SBHYBRID_ImageType_t;

/* set include files according to configuration */
/* Must be after SBHYBRID_SymmContext_t and
   before SBHYBRID_Context_t due to struct definitions used in SBHYBRID_Context_t */
#ifdef SBHYBRID_WITH_EIP28
#include "sbhybrid_eip28.h"
#endif
#ifdef SBHYBRID_WITH_EIP93
#include "sbhybrid_eip93.h"
#endif
#ifdef SBHYBRID_WITH_EIP130
#include "sbhybrid_eip130.h"
#endif
#if defined(SBHYBRID_WITH_SW) || defined(SBHYBRID_WITH_SWPK)
#include "sbhybrid_sw.h"
#endif

/* SBHYBRID_Context_t

   Internal context containing all required work memory. The
   SB_StorageArea_t type pointer is casted to SBHYBRID_Context_t for
   internal use. The size must be smaller than SB_StorageArea_t.

   The structure needs to be identical to AES_IF_Ctx, to simplify internal
   operation of Secure Boot.
 */
struct AES_IF_Ctx
{
#if defined(SBHYBRID_WITH_SW) || defined(SBHYBRID_WITH_EIP93)
#ifdef SBIF_CFG_CONFIDENTIALITY_BITS
    uint8_t KeyData[SBIF_CFG_CONFIDENTIALITY_BITS / 8];
#else
    uint8_t KeyDataBuffer[256 / 8];
    uint32_t KeyDataBytes;
#endif
#endif
    AES_IF_ResultCode_t Result;
    uint32_t IV[4];

    /* Context for asymmetric and symmetric crypto */
#if defined(SBHYBRID_WITH_SWPK)
#ifdef SBIF_ECDSA
    SBHYBRID_ECDSA_Verify_t * AlgoContext_p; /* Reference to SW context */
    SBHYBRID_ECDSA_Verify_t AlgoContext; /* Context for asymmetric crypto */
#else
    SBHYBRID_RSA_Verify_t * AlgoContext_p; /* Reference to SW context */
    SBHYBRID_RSA_Verify_t AlgoContext; /* Context for asymmetric crypto */
#endif
#elif defined(SBHYBRID_WITH_EIP28)
    SBHYBRID_EIP28_Context_t * AlgoContext_p; /* Reference to EIP-28 context */
    SBHYBRID_EIP28_Context_t AlgoContext; /* Context for asymmetric crypto */
#elif defined(SBHYBRID_WITH_EIP130)
    SBHYBRID_SymmContext_t * AlgoContext_p; /* Reference to context of EIP-130 */
#endif
    SBHYBRID_SymmContext_t SymmContext; /* Context for symmetric crypto */

#ifdef SBHYBRID_WITH_EIP130
    uint32_t AssetId;                   /* Asset Identifier */
    uint32_t AssetBits;                 /* Asset data size */

#endif
    // Common variables
    uint32_t CertNr;
    uint32_t CertificateCount;
    bool NeedFinalDigest;
};

typedef struct AES_IF_Ctx SBHYBRID_Context_t;


SB_Result_t
SBHYBRID_Initialize_HW(SBHYBRID_Context_t * const Context_p);

void
SBHYBRID_Uninitialize_HW(SBHYBRID_Context_t * const Context_p);

SB_Result_t
SBHYBRID_Initialize_FW(SBHYBRID_Context_t * const Context_p,
                       const uint32_t * const Firmware_p,
                       const uint32_t FirmwareWord32Size);


#endif /* INCLUDE_GUARD_SBHYBRID_INTERNAL_H */

/* end of file sbhybrid_internal.h */

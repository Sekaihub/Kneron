/*
 * File: sbif.h
 *
 * Description: Secure Boot image format with Elliptic Curve Digital Signature
 *              Algorithm (ECDSA) and RSA.
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

#ifndef INCLUDE_GUARD_SBIF_H
#define INCLUDE_GUARD_SBIF_H

#include "public_defs.h"
#include "cfg_sbif.h"
#include "generic_utils.h"


/** Tag for image type BLp. */
#define SBIF_IMAGE_BLTp            0x424c70

/** Tag for image type BLw. */
#define SBIF_IMAGE_BLTw            0x424c77

/** Tag for image type BLe. */
#define SBIF_IMAGE_BLTe            0x424c65

/** Tag for image type BLx. */
#define SBIF_IMAGE_BLTx            0x424c78

/** Current image version number for BL images.  */
#define SBIF_VERSION          2U

/** Values for PubKeyType field: describes the location of the public key. */
#define SBIF_PUBKEY_TYPE_ROM       0x1
#define SBIF_PUBKEY_TYPE_OTP       0x2
#define SBIF_PUBKEY_TYPE_IMAGE     0x3


/** Macro to get version from the type field. */
#define SBIF_TYPE_VERSION(type)    ((type) & 0xff)

/** Macro to get type from the type field. */
#define SBIF_TYPE_TYPE(type)       ((type) >> 8)

/** Encryption key length. */
#define SBIF_ENCRYPTIONKEY_LEN ((SBIF_CFG_CONFIDENTIALITY_BITS / 32) + 2)
#define SBIF_ENCRYPTIONKEY256_LEN ((256 / 32) + 2)

/** Encryption key iv length. */
#define SBIF_ENCRYPTIONIV_LEN (128 / 32)

#ifdef SBIF_CFG_ECDSA_BITS
#define SBIF_ECDSA
#define SBIF_ECDSA_BITS_DO_U(a) a##U
#define SBIF_ECDSA_BITS_U(a)    SBIF_ECDSA_BITS_DO_U(a)
#define SBIF_ECDSA_BITS         SBIF_ECDSA_BITS_U(SBIF_CFG_ECDSA_BITS)
/** ECDSA bytes. */
#define SBIF_ECDSA_BYTES        (((SBIF_ECDSA_BITS) + 7) >> 3)
/** ECDSA words. */
#define SBIF_ECDSA_WORDS        (((SBIF_ECDSA_BITS) + 31) >> 5)
#elif defined SBIF_CFG_RSA_BITS
#define SBIF_RSA
#define SBIF_RSA_BITS_DO_U(a)   a##U
#define SBIF_RSA_BITS_U(a)      SBIF_RSA_BITS_DO_U(a)
#define SBIF_RSA_BITS           SBIF_RSA_BITS_U(SBIF_CFG_RSA_BITS)
/** RSA bytes. */
#define SBIF_RSA_BYTES          (((SBIF_RSA_BITS) + 7) >> 3)
/** RSA words. */
#define SBIF_RSA_WORDS          (((SBIF_RSA_BITS) + 31) >> 5)
#define RSA_DIGEST_BYTES 32
#define SBIF_RSA_MAX_PUBEXP_BITS 32
#else
#error "Cannot find SBIF_CFG_ECDSA_BITS/SBIF_CFG_RSA_BITS in cfg_sbif.h"
#endif /* SBIF_CFG_ECDSA_BITS */

#if SBIF_CFG_ECDSA_BITS == 224
#define SBIF_ECDSA_PAD_BITS 32
#endif /* SBIF_CFG_ECDSA_BITS */


/** Maximum number of attribute elements. */
#if SIGNTOOL == 1
#define SBIF_NUM_ATTRIBUTES 16
#else
#if (SBIF_ECDSA_BYTES == 28) || (SBIF_ECDSA_BYTES == 32) || defined(SBIF_RSA)
#define SBIF_NUM_ATTRIBUTES 8
#else
#define SBIF_NUM_ATTRIBUTES 16
#endif /* (SBIF_ECDSA_BYTES == 28) || (SBIF_ECDSA_BYTES == 32) || defined(SBIF_RSA) */
#endif /* SIGNTOOL == 1 */


typedef struct
{
#ifdef SBIF_ECDSA
    uint8_t r[SBIF_ECDSA_BYTES];    /** r. */
    uint8_t s[SBIF_ECDSA_BYTES];    /** s. */
#ifdef SBIF_ECDSA_PAD_BITS
    /* Notice: add padding to get the same size for 224 as for 256-bit ECC */
    uint8_t pad[SBIF_ECDSA_PAD_BITS / 8 * 2];
#endif /* SBIF_ECDSA_PAD_BITS */
#else /* SBIF_ECDSA */
    uint8_t signature[SBIF_RSA_BYTES];
#endif /* SBIF_ECDSA */
}
SBIF_Signature_t;

typedef struct
{
#ifdef SBIF_ECDSA
    uint8_t Qx[SBIF_ECDSA_BYTES];    /** Qx. */
    uint8_t Qy[SBIF_ECDSA_BYTES];    /** Qy. */
#else /* SBIF_ECDSA */
    uint8_t pubkeyExp[4];
    uint8_t modulus[SBIF_RSA_BYTES];
#endif /* SBIF_ECDSA */
}
SBIF_PublicKey_t;

typedef struct
{
    SBIF_PublicKey_t PublicKey;    /** Public key. */
    SBIF_Signature_t Signature;    /** Signature. */
#ifdef SBIF_RSA
    /* Notice: add padding to get the size which is multiple of 8 */
    uint8_t          Pad[4];
#endif
}
SBIF_Certificate_t;


/** Define Attribute type and its allowed constants. */
typedef uint32_t SBIF_AttributeElementType_t;

#define SBIF_ATTRIBUTE_UNUSED  0     /* All element positions not used. */
#define SBIF_ATTRIBUTE_VERSION 1     /* Version field for attribute array. */
#define SBIF_ATTRIBUTE_ROLLBACK_ID 2 /* Optional rollback identifier */

#define SBIF_ATTRIBUTE_SPI		0x80000001/* custom, spi*/
#define SBIF_ATTRIBUTE_SCRTU_FW		0x80000002/* custom, scrtu FW*/
#define SBIF_ATTRIBUTE_DDR_FW		0x80000003/* custom, ddr FW*/
#define SBIF_ATTRIBUTE_TOTAL_SZIE	0x80000004/* custom, combined size*/
#define SBIF_ATTRIBUTE_SPI_BL33_ADDR	0x80000005/* custom, spi bl33 address*/
#define SBIF_ATTRIBUTE_SPI_BL33_SIZE	0x80000006/* custom, spi bl33 size*/

/** Minimum attribute version. */
#define SBIF_ATTRIBUTE_VERSION_CURRENT 0 /** First version. */

/** Minimum current rollback identifier.
    SecureBoot shall not process images with rollback counter less than this. */
#ifdef SBIF_CFG_ATTRIBUTE_MINIMUM_ROLLBACK_ID
#define SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID \
        SBIF_CFG_ATTRIBUTE_MINIMUM_ROLLBACK_ID
#endif /* SBIF_CFG_ATTRIBUTE_MINIMUM_ROLLBACK_ID */

/** Attribute data (incl. version id). */
typedef struct
{
    SBIF_AttributeElementType_t ElementType;
    uint32_t ElementValue;
}
SBIF_AttributeElement_t;

typedef struct SBIF_Attributes
{
    /** Attribute data element. */
    SBIF_AttributeElement_t AttributeElements[SBIF_NUM_ATTRIBUTES];
}
SBIF_Attributes_t;


/**
    Signing header for the images.
 */
typedef struct
{
    uint32_t               Type;                /** Type. */
    uint32_t               PubKeyType;          /** Type of public key */
    SBIF_Signature_t       Signature;           /** Signature. */
    SBIF_PublicKey_t       PublicKey;           /** Public key (if included in image). */
#ifdef SBIF_ECDSA_PAD_BITS
    /* Notice: add padding to get the same size for 224 as for 256-bit ECC */
    uint8_t pad[SBIF_ECDSA_PAD_BITS / 8 * 2];
#endif /* SBIF_ECDSA_PAD_BITS */
    uint32_t               EncryptionKey[SBIF_ENCRYPTIONKEY256_LEN]; /** Key. */
    uint32_t               EncryptionIV[SBIF_ENCRYPTIONIV_LEN]; /** IV. */
    uint32_t               ImageLen;            /** Image length. */
    SBIF_Attributes_t      ImageAttributes;     /** Image attributes. */
    uint32_t               CertificateCount;    /** Certificate count. */
} SBIF_Header_t;


/*
  SBIF_GET_HEADER_SIZE

  Return total size of header including the space required by
  certificates. Returns 0 on error.
  Macro needs to be provided with known maximum number of bytes
  it is allowed to examine.
*/

/** Header size. */
#define SBIF_GET_HEADER_SIZE(Header_p, AccessibleByteSize)  \
    SBIF_GetHeaderSize((const void *)(Header_p), (uint32_t)(AccessibleByteSize))

/* Helper inline function for fetching image size.
   Conventionally used via SBIF_GET_HEADER_SIZE macro. */
static inline uint32_t SBIF_GetHeaderSize(
    const SBIF_Header_t * const Header_p,
    const uint32_t AccessibleByteSize)
{
    size_t size = 0;

    if (AccessibleByteSize >= sizeof(SBIF_Header_t))
    {
        uint8_t certificateCount = *(((uint8_t *)discard_const(&(Header_p->CertificateCount))) + 3);
        /* NOTE: Currently up-to 8 certificates are supported. */
        if (certificateCount <= 8)
        {
            size = sizeof(SBIF_Header_t) + (certificateCount * sizeof(SBIF_Certificate_t));
        }
    }

    return (uint32_t)size;
}


#endif

/* end of file sbif.h */

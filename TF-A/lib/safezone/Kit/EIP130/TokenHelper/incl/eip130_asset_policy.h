/* eip130_asset_policy.h
 *
 * Security Module Token helper information
 * - Asset policy definitions
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

#ifndef INCLUDE_GUARD_EIP130_ASSET_POLICY_H
#define INCLUDE_GUARD_EIP130_ASSET_POLICY_H

#include "cs_eip130.h"                  /* EIP-130 configuration */

#ifdef EIP130_FW_ASSETPOLICY_V2
/*----------------------------------------------------------------------------
 * EIP130_ASSET_POLICY_*
 *
 * The defines below define the asset policy bits.
 */
/* Policy bits [15:0] */
/* - General (Static & Dynamic Asset Store) */
#define EIP130_ASSET_POLICY_MODIFIABLE          0x0000000000000000ULL   /* 0 = modifiable asset */
#define EIP130_ASSET_POLICY_NONMODIFIABLE       0x0000000000000001ULL   /* 1 = non-modifiable asset */
#define EIP130_ASSET_POLICY_SOURCESECURE        0x0000000000000000ULL   /* 0 = Secure */
#define EIP130_ASSET_POLICY_SOURCENONSECURE     0x0000000000000100ULL   /* 1 = Non-secure */
#define EIP130_ASSET_POLICY_NOTCROSSDOMAIN      0x0000000000000000ULL   /* 0 = key operation does not cross the domain */
#define EIP130_ASSET_POLICY_CROSSDOMAIN         0x0000000000000200ULL   /* 1 = key operation does cross the domain */
#define EIP130_ASSET_POLICY_NODOMAIN            0x0000000000000400ULL   /* 0 = has domain info, 1 = no domain info */
#define EIP130_ASSET_POLICY_PUBLICDATA          0x0000000000000000ULL   /* 0 = public data */
#define EIP130_ASSET_POLICY_PRIVATEDATA         0x0000000000000800ULL   /* 1 = private data */
#define EIP130_ASSET_POLICY_FIPSAPPROVED        0x0000000000001000ULL   /* 1 = fips approved */
#define EIP130_ASSET_POLICY_NOTFIPSAPPROVED     0x0000000000000000ULL   /* 0 = not fips approved */

#define EIP130_ASSET_POLICY_GENERICDATA         0x0000000000000000ULL   /* Generic Data related */
#define EIP130_ASSET_POLICY_SYMCRYPTO           0x0000000000002000ULL   /* Symmetric Crypto related */
#define EIP130_ASSET_POLICY_ASYMCRYPTO          0x0000000000004000ULL   /* Asymmetric Crypto related */
#define EIP130_ASSET_POLICY_COPROIFC            0x0000000000006000ULL   /* Co-Processor Interface related */

/* - Dynamic Asset Store only */
#define EIP130_ASSET_POLICY_NOTTEMPORARY        0x0000000000000000ULL   /* 0 = NOT updatable Asset */
#define EIP130_ASSET_POLICY_TEMPORARY           0x0000000000000002ULL   /* 1 = Temporary (updatable) Asset */
#define EIP130_ASSET_POLICY_NOTEXPORTABLE       0x0000000000000000ULL   /* 0 = NOT exportable Asset */
#define EIP130_ASSET_POLICY_EXPORTABLE          0x0000000000000004ULL   /* 1 = Exportable Asset (AES Keywrap/RSA-OAEP/etc.) */
#define EIP130_ASSET_POLICY_NOTTRUSTEXPORT      0x0000000000000000ULL   /* 0 = NOT trusted exportable Asset */
#define EIP130_ASSET_POLICY_TRUSTEXPORT         0x0000000000000008ULL   /* 1 = Trusted exportable Asset (AES-SIV) */

/* Policy bits [31:16] */
/* - Generic Data related (Static & Dynamic Asset Store) */
#define EIP130_ASSET_POLICY_GDPRIVATEDATA       0x0000000000000000ULL   /* General private data */
#define EIP130_ASSET_POLICY_GDPUBLICDATA        0x0000000000000000ULL   /* General public data object */
#define EIP130_ASSET_POLICY_GDMONOTONIC         0x0000000000000000ULL   /* Monotonic counter */
#define EIP130_ASSET_POLICY_GDCOID              0x0000000000010000ULL   /* Crypto Officer Identifier (COID) */
#define EIP130_ASSET_POLICY_GDSECURETIMER       0x0000000000020000ULL   /* Secure Timer */
#define EIP130_ASSET_POLICY_GDHUK               0x0000000000050000ULL   /* Hardware Unique Key (HUK) (note == AS_P_SCUIDerive) */
#define EIP130_ASSET_POLICY_GDPOWERDOWN         0x00000000000E0000ULL   /* PowerDown information */
#define EIP130_ASSET_POLICY_GDSPECIALFUNC       0x00000000000F0000ULL   /* Special Function Keys or States */

/*   + Special Function Keys or States */
#define EIP130_ASSET_POLICY_GDSF_MILENAGEK_OPC  0x0000000000000000ULL   /* Milenage K and Opc */
#define EIP130_ASSET_POLICY_GDSF_MILENAGEADMIN  0x0000000000100000ULL   /* Milenage SQNms Administration */

/* - Symmetric Crypto related (Static & Dynamic Asset Store) */
#define EIP130_ASSET_POLICY_SCUIHASH            0x0000000000000000ULL   /* Hash */
#define EIP130_ASSET_POLICY_SCUIMACHASH         0x0000000000010000ULL   /* MAC - Hash based */
#define EIP130_ASSET_POLICY_SCUIMACCIPHER       0x0000000000020000ULL   /* MAC - Cipher based */
#define EIP130_ASSET_POLICY_SCUICIPHERBULK      0x0000000000030000ULL   /* Cipher - Bulk encrypt */
#define EIP130_ASSET_POLICY_SCUICIPHERAUTH      0x0000000000040000ULL   /* Cipher - Authenticated encrypt */
#define EIP130_ASSET_POLICY_SCUIWRAP            0x0000000000050000ULL   /* Key wrap */
#define EIP130_ASSET_POLICY_SCUIDERIVE          0x0000000000060000ULL   /* Key derive */
#define EIP130_ASSET_POLICY_SCUIEMMCAUTH        0x00000000000F0000ULL   /* eMMC AuthKey (also used for state) */

#define EIP130_ASSET_POLICY_SCDIRNOTUSED        0x0000000000000000ULL   /* Direction - not use/applicable */
#define EIP130_ASSET_POLICY_SCDIRENCGEN         0x0000000000100000ULL   /* Direction - Encrypt / Generate / Wrap */
#define EIP130_ASSET_POLICY_SCDIRDECVRFY        0x0000000000200000ULL   /* Direction - Decrypt / Verify / Unwrap */
#define EIP130_ASSET_POLICY_SCDIRENCDEC         0x0000000000300000ULL   /* Direction - Encrypt & Decrypt / Generate & Verify / Wrap & Unwrap */

#define EIP130_ASSET_POLICY_SCAHSHA1            0x0000000000400000ULL   /* SHA-1 */
#define EIP130_ASSET_POLICY_SCAHSM3             0x0000000000800000ULL   /* SM3 */
#define EIP130_ASSET_POLICY_SCAHPOLY1305        0x0000000000C00000ULL   /* Poly1305 (MAC only) */
#define EIP130_ASSET_POLICY_SCAHSHA224          0x0000000001000000ULL   /* SHA-2-224 */
#define EIP130_ASSET_POLICY_SCAHSHA256          0x0000000001400000ULL   /* SHA-2-256 */
#define EIP130_ASSET_POLICY_SCAHSHA384          0x0000000001800000ULL   /* SHA-2-384 */
#define EIP130_ASSET_POLICY_SCAHSHA512          0x0000000001C00000ULL   /* SHA-2-512 */
#define EIP130_ASSET_POLICY_SCAHSHA3_224        0x0000000002000000ULL   /* SHA-3-224 */
#define EIP130_ASSET_POLICY_SCAHSHA3_256        0x0000000002400000ULL   /* SHA-3-256 */
#define EIP130_ASSET_POLICY_SCAHSHA3_384        0x0000000002800000ULL   /* SHA-3-384 */
#define EIP130_ASSET_POLICY_SCAHSHA3_512        0x0000000002C00000ULL   /* SHA-3-512 */

#define EIP130_ASSET_POLICY_SCACAES             0x0000000000000000ULL   /* AES */
#define EIP130_ASSET_POLICY_SCACTDES            0x0000000000400000ULL   /* TDES/3DES */
#define EIP130_ASSET_POLICY_SCACCHACHA20        0x0000000000800000ULL   /* ChaCha20 */
#define EIP130_ASSET_POLICY_SCACSM4             0x0000000000C00000ULL   /* SM4 */
#define EIP130_ASSET_POLICY_SCACARIA            0x0000000001000000ULL   /* ARIA */
#define EIP130_ASSET_POLICY_SCACCAMELIA         0x0000000001400000ULL   /* Camelia */

#define EIP130_ASSET_POLICY_SCAWAESSIV          0x0000000000000000ULL   /* AES-SIV (key blob) */
#define EIP130_ASSET_POLICY_SCAWKEY             0x0000000008000000ULL   /* key wrap (AES & SM4) */
#define EIP130_ASSET_POLICY_SCAWAUTHKEY         0x0000000010000000ULL   /* AES key wrap for Secure Debug AuthenKey */

#define EIP130_ASSET_POLICY_SCADTRUSTED         0x0000000000000000ULL   /* Trusted key-derive key */
#define EIP130_ASSET_POLICY_SCADNORMALHASH      0x0000000000100000ULL   /* Normal key-derive key hash-based */
#define EIP130_ASSET_POLICY_SCADNORMALHMAC      0x0000000000300000ULL   /* Normal key-derive key HMAC-based */
#define EIP130_ASSET_POLICY_SCADNORMALCMAC      0x0000000000200000ULL   /* Normal key-derive key CMAC-based */

/* Specifies the Asset storage type for decrypted or derived data. */
#define EIP130_ASSET_POLICY_STANY               0x0000000004000000ULL   /* 1 = Data may be stored in public or exportable asset */
#define EIP130_ASSET_POLICY_STPRIVATE           0x0000000000000000ULL   /* 0 = Private */

#define EIP130_ASSET_POLICY_SCMCBECB            0x0000000000000000ULL   /* ECB */
#define EIP130_ASSET_POLICY_SCMCBCHACHA20       0x0000000000000000ULL   /* ChaCha20 Encrypt */
#define EIP130_ASSET_POLICY_SCMCBCBC            0x0000000008000000ULL   /* CBC */
#define EIP130_ASSET_POLICY_SCMCBCTR16          0x0000000010000000ULL   /* CTR-16 */
#define EIP130_ASSET_POLICY_SCMCBCTR32          0x0000000018000000ULL   /* CTR-32 */
#define EIP130_ASSET_POLICY_SCMCBCTR64          0x0000000020000000ULL   /* CTR-64 */
#define EIP130_ASSET_POLICY_SCMCBCTR128         0x0000000028000000ULL   /* CTR-128 */
#define EIP130_ASSET_POLICY_SCMCBXTS            0x0000000030000000ULL   /* XTS */
#define EIP130_ASSET_POLICY_SCMCBF8             0x0000000038000000ULL   /* f8 */

#define EIP130_ASSET_POLICY_SCMCACCM            0x0000000000000000ULL   /* CCM / ChaCha20+Poly1305 */
#define EIP130_ASSET_POLICY_SCMCAGCM            0x0000000008000000ULL   /* GCM */

#define EIP130_ASSET_POLICY_SCMCMCMAC           0x0000000000000000ULL   /* CMAC */
#define EIP130_ASSET_POLICY_SCMCMCBCMAC         0x0000000008000000ULL   /* CBC-MAC */

/* - Asymmetric Crypto related (Static & Dynamic Asset Store) */
#define EIP130_ASSET_POLICY_ACUI_SIGNVRFY       0x0000000000000000ULL   /* Sign/Verify */
#define EIP130_ASSET_POLICY_ACUI_KEYEXCH        0x0000000000010000ULL   /* Key Exchange */
#define EIP130_ASSET_POLICY_ACUI_DECENC         0x0000000000020000ULL   /* Decrypt/Encrypt (Unwrap/Wrap) */
#define EIP130_ASSET_POLICY_ACUI_SD             0x0000000000030000ULL   /* Secure Debug */
#define EIP130_ASSET_POLICY_ACUI_SDGPIO         0x00000000000B0000ULL   /* Secure Debug with GPIO data */
#define EIP130_ASSET_POLICY_ACUI_PARAMETERS     0x00000000000F0000ULL   /* Public key params (curve, etc) */

#define EIP130_ASSET_POLICY_ACA_DH              0x0000000000000000ULL   /* DH based key */
#define EIP130_ASSET_POLICY_ACA_DSA             0x0000000000100000ULL   /* DSA based key */
#define EIP130_ASSET_POLICY_ACA_ECDH            0x0000000000200000ULL   /* ECDH based key */
#define EIP130_ASSET_POLICY_ACA_ECDSA           0x0000000000300000ULL   /* ECDSA based key */
#define EIP130_ASSET_POLICY_ACA_CURVE25519      0x0000000000400000ULL   /* Curve25519 based key */
#define EIP130_ASSET_POLICY_ACA_EDDSA           0x0000000000500000ULL   /* EdDSA based key */
#define EIP130_ASSET_POLICY_ACA_SM2             0x0000000000600000ULL   /* SM2 based key */
#define EIP130_ASSET_POLICY_ACA_ECCELGAMAL      0x0000000000700000ULL   /* ECC-El-Gamal based key */
#define EIP130_ASSET_POLICY_ACA_RSAPKCS1V15     0x0000000000800000ULL   /* RSA-PKCS#1v1.5 based key */
#define EIP130_ASSET_POLICY_ACA_RSAPSS          0x0000000000900000ULL   /* RSA-PSS based key */
#define EIP130_ASSET_POLICY_ACA_RSAOEAP         0x0000000000A00000ULL   /* RSA-OEAP based key */
#define EIP130_ASSET_POLICY_ACA_RSAKEM          0x0000000000B00000ULL   /* RSA-KEM based key */

#define EIP130_ASSET_POLICY_ACH_NOTUSED         0x0000000000000000ULL   /* No involved hash */
#define EIP130_ASSET_POLICY_ACH_SHA1            0x0000000008000000ULL   /* SHA-1 */
#define EIP130_ASSET_POLICY_ACH_SM3             0x0000000010000000ULL   /* SM3 */
#define EIP130_ASSET_POLICY_ACH_SHA224          0x0000000020000000ULL   /* SHA-224 */
#define EIP130_ASSET_POLICY_ACH_SHA256          0x0000000028000000ULL   /* SHA-256 */
#define EIP130_ASSET_POLICY_ACH_SHA384          0x0000000030000000ULL   /* SHA-384 */
#define EIP130_ASSET_POLICY_ACH_SHA512          0x0000000038000000ULL   /* SHA-512 */
#define EIP130_ASSET_POLICY_ACH_SHA3_224        0x0000000040000000ULL   /* SHA-3-224 */
#define EIP130_ASSET_POLICY_ACH_SHA3_256        0x0000000048000000ULL   /* SHA-3-256 */
#define EIP130_ASSET_POLICY_ACH_SHA3_384        0x0000000050000000ULL   /* SHA-3-384 */
#define EIP130_ASSET_POLICY_ACH_SHA3_512        0x0000000058000000ULL   /* SHA-3-512 */

/* - Co-Processor Interface related (Static & Dynamic Asset Store) */
/* Every bit in range [31:16] refers to a Co-Processor [15:0]*/

/*----------------------------------------------------------------------------
 * Support defines to help readability
 */
/**
 * Operation based defines
 * Usage: [OPERATION] | [ALGORITHM] | [MODE] | [DIRECTION]
 *
 * Example usage:
 * AES-CBC encrypt operation:
 * EIP130_ASSET_POLICY_SYM_CIPHERBULK | EIP130_ASSET_POLICY_SCACAES | EIP130_ASSET_POLICY_SCMCBCBC | EIP130_ASSET_POLICY_SCDIRENCGEN;
 */
/* Symmetric crypto support defines */
#define EIP130_ASSET_POLICY_SYM_BASE            (EIP130_ASSET_POLICY_NONMODIFIABLE | EIP130_ASSET_POLICY_PRIVATEDATA | EIP130_ASSET_POLICY_SYMCRYPTO)
#define EIP130_ASSET_POLICY_SYM_TEMP            (EIP130_ASSET_POLICY_TEMPORARY | EIP130_ASSET_POLICY_PRIVATEDATA | EIP130_ASSET_POLICY_SYMCRYPTO)
#define EIP130_ASSET_POLICY_SYM_MACHASH         (EIP130_ASSET_POLICY_SYM_BASE | EIP130_ASSET_POLICY_SCUIMACHASH)
#define EIP130_ASSET_POLICY_SYM_MACCIPHER       (EIP130_ASSET_POLICY_SYM_BASE | EIP130_ASSET_POLICY_SCUIMACCIPHER)
#define EIP130_ASSET_POLICY_SYM_CIPHERBULK      (EIP130_ASSET_POLICY_SYM_BASE | EIP130_ASSET_POLICY_SCUICIPHERBULK)
#define EIP130_ASSET_POLICY_SYM_CIPHERAUTH      (EIP130_ASSET_POLICY_SYM_BASE | EIP130_ASSET_POLICY_SCUICIPHERAUTH)
#define EIP130_ASSET_POLICY_SYM_WRAP            (EIP130_ASSET_POLICY_SYM_BASE | EIP130_ASSET_POLICY_SCUIWRAP)
#define EIP130_ASSET_POLICY_SYM_DERIVE          (EIP130_ASSET_POLICY_SYM_BASE | EIP130_ASSET_POLICY_SCUIDERIVE)

#define EIP130_ASSET_POLICY_SYM_BULK_AES        (EIP130_ASSET_POLICY_SYM_CIPHERBULK | EIP130_ASSET_POLICY_SCACAES)
#define EIP130_ASSET_POLICY_SYM_WRAP_AES        (EIP130_ASSET_POLICY_SYM_WRAP | EIP130_ASSET_POLICY_SCACAES)
#define EIP130_ASSET_POLICY_SYM_WRAP_SM4        (EIP130_ASSET_POLICY_SYM_WRAP | EIP130_ASSET_POLICY_SCACSM4)

/* Asymmetric support defines */
#define EIP130_ASSET_POLICY_ASYM_BASE           (EIP130_ASSET_POLICY_NONMODIFIABLE | EIP130_ASSET_POLICY_ASYMCRYPTO)
#define EIP130_ASSET_POLICY_ASYM_TEMP           (EIP130_ASSET_POLICY_TEMPORARY | EIP130_ASSET_POLICY_PRIVATEDATA | EIP130_ASSET_POLICY_ASYMCRYPTO)
#define EIP130_ASSET_POLICY_ASYM_SIGNVERIFY     (EIP130_ASSET_POLICY_ASYM_BASE | EIP130_ASSET_POLICY_ACUI_SIGNVRFY)
#define EIP130_ASSET_POLICY_ASYM_KEYEXCHANGE    (EIP130_ASSET_POLICY_ASYM_BASE | EIP130_ASSET_POLICY_ACUI_KEYEXCH)
#define EIP130_ASSET_POLICY_ASYM_DECENC         (EIP130_ASSET_POLICY_ASYM_BASE | EIP130_ASSET_POLICY_ACUI_DECENC)
#define EIP130_ASSET_POLICY_ASYM_KEYPARAMS      (EIP130_ASSET_POLICY_ASYM_BASE | EIP130_ASSET_POLICY_NODOMAIN | EIP130_ASSET_POLICY_ACUI_PARAMETERS)

#else /* !EIP130_FW_ASSETPOLICY_V2 */
/*----------------------------------------------------------------------------
 * EIP130_ASSET_POLICY_*
 *
 * The defines below define the asset policy bits.
 */
/* Asset policies related to hash/HMAC and CMAC algorithms */
#define EIP130_ASSET_POLICY_SHA1                       0x0000000000000001ULL
#define EIP130_ASSET_POLICY_SHA224                     0x0000000000000002ULL
#define EIP130_ASSET_POLICY_SHA256                     0x0000000000000004ULL
#define EIP130_ASSET_POLICY_SHA384                     0x0000000000000008ULL
#define EIP130_ASSET_POLICY_SHA512                     0x0000000000000010ULL
#define EIP130_ASSET_POLICY_CMAC                       0x0000000000000020ULL
#define EIP130_ASSET_POLICY_POLY1305                   0x0000000000000080ULL
#define EIP130_ASSET_POLICY_SM3                        0x0000000000000080ULL
#define EIP130_ASSET_POLICY_SHA3_224                   0x0000000000000003ULL
#define EIP130_ASSET_POLICY_SHA3_256                   0x0000000000000005ULL
#define EIP130_ASSET_POLICY_SHA3_384                   0x0000000000000009ULL
#define EIP130_ASSET_POLICY_SHA3_512                   0x0000000000000011ULL

/* Asset policies related to cipher algorithms */
#define EIP130_ASSET_POLICY_ALGO_CIPHER_MASK           0x0000000000000300ULL
#define EIP130_ASSET_POLICY_ALGO_CIPHER_AES            0x0000000000000100ULL
#define EIP130_ASSET_POLICY_ALGO_CIPHER_TRIPLE_DES     0x0000000000000200ULL
#define EIP130_ASSET_POLICY_ALGO_CHACHA20              0x0000000000002000ULL
#define EIP130_ASSET_POLICY_ALGO_SM4                   0x0000000000004000ULL
#define EIP130_ASSET_POLICY_ALGO_ARIA                  0x0000000000008000ULL

/* Asset policies related to cipher modes */
#define EIP130_ASSET_POLICY_MODE1                      0x0000000000010000ULL
#define EIP130_ASSET_POLICY_MODE2                      0x0000000000020000ULL
#define EIP130_ASSET_POLICY_MODE3                      0x0000000000040000ULL
#define EIP130_ASSET_POLICY_MODE4                      0x0000000000080000ULL
#define EIP130_ASSET_POLICY_MODE5                      0x0000000000100000ULL
#define EIP130_ASSET_POLICY_MODE6                      0x0000000000200000ULL
#define EIP130_ASSET_POLICY_MODE7                      0x0000000000400000ULL
#define EIP130_ASSET_POLICY_MODE8                      0x0000000000800000ULL
#define EIP130_ASSET_POLICY_MODE9                      0x0000000001000000ULL
#define EIP130_ASSET_POLICY_MODE10                     0x0000000002000000ULL

/* Asset policies related to cipher/MAC operations */
#define EIP130_ASSET_POLICY_MAC_GENERATE               0x0000000004000000ULL
#define EIP130_ASSET_POLICY_MAC_VERIFY                 0x0000000008000000ULL
#define EIP130_ASSET_POLICY_ENCRYPT                    0x0000000010000000ULL
#define EIP130_ASSET_POLICY_DECRYPT                    0x0000000020000000ULL

/* Asset policies related to temporary values */
#define EIP130_ASSET_POLICY_TEMP_IV                    0x0001000000000000ULL
#define EIP130_ASSET_POLICY_TEMP_COUNTER               0x0002000000000000ULL
#define EIP130_ASSET_POLICY_TEMP_MAC                   0x0004000000000000ULL /* includes intermediate digest */
#define EIP130_ASSET_POLICY_TEMP_AUTH_STATE            0x0010000000000000ULL

/* Asset policated to monotonic counter */
#define EIP130_ASSET_POLICY_MONOTONIC                  0x0000000100000000ULL

/* Asset policies related to key derive functionality */
#define EIP130_ASSET_POLICY_TRUSTED_ROOT_KEY           0x0000000200000000ULL
#define EIP130_ASSET_POLICY_TRUSTED_KEY_DERIVE         0x0000000400000000ULL
#define EIP130_ASSET_POLICY_KEY_DERIVE                 0x0000000800000000ULL

/* Asset policies related to AES key wrap functionality */
#define EIP130_ASSET_POLICY_TRUSTED_WRAP               0x0000001000000000ULL
#define EIP130_ASSET_POLICY_AES_WRAP                   0x0000002000000000ULL

/* Asset policies related to PK operations */
#define EIP130_ASSET_POLICY_PUBLIC_KEY                 0x0000000080000000ULL
#define EIP130_ASSET_POLICY_PK_RSA_OAEP_WRAP           0x0000004000000000ULL
#define EIP130_ASSET_POLICY_PK_RSA_PKCS1_WRAP          0x0000010000000000ULL
#define EIP130_ASSET_POLICY_PK_RSA_PKCS1_SIGN          0x0000020000000000ULL
#define EIP130_ASSET_POLICY_PK_RSA_PSS_SIGN            0x0000040000000000ULL
#define EIP130_ASSET_POLICY_PK_DSA_SIGN                0x0000080000000000ULL
#define EIP130_ASSET_POLICY_PK_ECC_ECDSA_SIGN          0x0000100000000000ULL
#define EIP130_ASSET_POLICY_PK_DH_KEY                  0x0000200000000000ULL
#define EIP130_ASSET_POLICY_PK_ECDH_KEY                0x0000400000000000ULL
#define EIP130_ASSET_POLICY_PK_ECC_ELGAMAL_ENC         (EIP130_ASSET_POLICY_PK_ECC_ECDSA_SIGN|EIP130_ASSET_POLICY_PK_ECDH_KEY)
#define EIP130_ASSET_POLICY_PK_SM2_SIGN                (EIP130_ASSET_POLICY_PK_DSA_SIGN|EIP130_ASSET_POLICY_PK_ECC_ECDSA_SIGN)
#define EIP130_ASSET_POLICY_PK_SM2_KEYEXCH             (EIP130_ASSET_POLICY_PK_DSA_SIGN|EIP130_ASSET_POLICY_PK_ECDH_KEY)
#define EIP130_ASSET_POLICY_PK_SM2_WRAP                (EIP130_ASSET_POLICY_PK_DSA_SIGN|EIP130_ASSET_POLICY_PK_ECC_ECDSA_SIGN|EIP130_ASSET_POLICY_PK_ECDH_KEY)

#define EIP130_ASSET_POLICY_PUBLIC_KEY_PARAM           0x0000800000000000ULL

#define EIP130_ASSET_POLICY_EMMC_AUTH_KEY              0x0400000000000000ULL
#define EIP130_ASSET_POLICY_AUTH_KEY                   0x8000000000000000ULL

/* Asset policies related to domain */
#define EIP130_ASSET_POLICY_SOURCE_NON_SECURE          0x0100000000000000ULL
#define EIP130_ASSET_POLICY_CROSS_DOMAIN               0x0200000000000000ULL

/* Asset policies related to export functionality */
#define EIP130_ASSET_POLICY_PRIVATE_DATA               0x0800000000000000ULL
#define EIP130_ASSET_POLICY_PUBLIC_DATA                0x1000000000000000ULL

/*Asset policies related to export functionality */
#define EIP130_ASSET_POLICY_EXPORT                     0x2000000000000000ULL
#define EIP130_ASSET_POLICY_TRUSTED_EXPORT             0x4000000000000000ULL

#endif /* EIP130_FW_ASSETPOLICY_V2 */


#endif /* INCLUDE_GUARD_EIP130_ASSET_POLICY_H */

/* end of file eip130_asset_policy.h */


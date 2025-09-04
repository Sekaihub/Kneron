/* cs_eip130.h
 *
 * Configuration Settings for the EIP130 module.
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

#ifndef INCLUDE_GUARD_CS_EIP130_H
#define INCLUDE_GUARD_CS_EIP130_H

/* The next switch enables the argument checking of EIP130 functions.
 * So, disable (comment) it to reduce code size and overhead.
 */
//#define EIP130_STRICT_ARGS

/** Next defines are Hardware / Firmware specific
 *  Note that the setting of these defines depend on the used hardware/firmware
 *  configuration.
 */
/* - General defines */
//#define EIP130_HW_V2                          /** Hardware version 2 */
#define EIP130_HW_V3                          /** Hardware version 3 */
//#define EIP130_ENABLE_FIRMWARE_LOAD           /** Enable firmware load functionality */
//#define EIP130_ALLOW_MASTER_NONSECURE         /** Hardware allows a non-secure master Host */

/* - Token Group NOP */
//#define EIP130_ENABLE_NOP                     /** Enable NOP functionality */

/* - Token Group Encryption (Symmetric) */
#define EIP130_ENABLE_SYM_ALGO_AES            /** Enable AES use (Note: Enabled by default) */
#ifdef EIP130_ENABLE_SYM_ALGO_AES
//#define EIP130_ENABLE_SYM_ALGO_AES_XTS        /** Enable XTS-AES use */
//#define EIP130_ENABLE_SYM_ALGO_AES_CCM        /** Enable AES-CCM use */
//#define EIP130_ENABLE_SYM_ALGO_AES_GCM        /** Enable AES_GCM use */
//#define EIP130_ENABLE_SYM_ALGO_AES_F8         /** Enable AES-f8 use */
#endif

//#define EIP130_ENABLE_SYM_ALGO_DES            /** Enable DES use */
//#define EIP130_ENABLE_SYM_ALGO_3DES           /** Enable Triple DES (3DES) use */

//#define EIP130_ENABLE_SYM_ALGO_CHACHA20       /** Enable ChaCha20 use */

//#define EIP130_ENABLE_SYM_ALGO_ARIA           /** Enable ARIA use */
#ifdef EIP130_ENABLE_SYM_ALGO_ARIA
#define EIP130_ENABLE_SYM_ALGO_ARIA_CCM       /** Enable ARIA-CCM use */
#define EIP130_ENABLE_SYM_ALGO_ARIA_GCM       /** Enable ARIA-GCM use */
#endif

//#define EIP130_ENABLE_SYM_ALGO_SM4            /** Enable SM4 use */

/* - Token Group Hash (Symmetric) */
#define EIP130_ENABLE_SYM_ALGO_SHA512         /** Enable SHA-2-384/512 use */
//#define EIP130_ENABLE_SYM_ALGO_SHA3           /** Enable SHA3 use */
//#define EIP130_ENABLE_SYM_ALGO_SM3            /** Enable SM3 use */

/* - Token Group MAC (Symmetric) */
//#define EIP130_ENABLE_SYM_ALGO_POLY1305       /** Enable Poly1305 use */

/* - Token Group TRNG */
//#define EIP130_ENABLE_DRBG_FORCESEED          /** Enable DRBG Force Seed functionality */
#ifdef EIP130_ENABLE_SYM_ALGO_ARIA
#define EIP130_ENABLE_SYM_ALGO_ARIA_DRBG      /** Enable ARIA-CTR-DRBG use */
#endif

/* - Token Group Special Functions */
//#define EIP130_ENABLE_SF_MILENAGE             /** Enable Special Functions for Milenage */

/* - Token Group AES Wrap (Symmetric) */
#ifdef EIP130_ENABLE_SYM_ALGO_AES
#define EIP130_ENABLE_SYM_ALGO_AES_KEYWRAP    /** Enable AES Keywrap use */
#endif
//#define EIP130_ENABLE_ENCRYPTED_VECTOR        /** Enable PKI Encrypted Vector use */

/* - Token Group Asset Management */
//#define EIP130_FW_ASSET_LIFETIME_MANAGEMENT   /** Enable Asset lifetime functionality */
#define EIP130_FW_ASSETPOLICY_V2              /** Enable Asset Policy version 2 */
//#define EIP130_ENABLE_CPIF                    /** Enable CoProcessor Interface functionality */
//#define EIP130_ENABLE_ASSET_STORE_RESET       /** Enable Asset Store reset functionality */

/* - Token Group Authenticated Unlock */

/* - Token Group Public Key operations (Asymmetric) */
//#define EIP130_ENABLE_EXPLICITDIGEST          /** Enable sign/verify explicit digest use */
//#define EIP130_ENABLE_ASYM_ALGO_DH            /** Enable DH use */
//#define EIP130_ENABLE_ASYM_ALGO_ECDH          /** Enable ECDH use */
//#define EIP130_ENABLE_ASYM_ALGO_CURVE25519    /** Enable ECDH based on Curve25519 use */
#define EIP130_ENABLE_ASYM_ALGO_ECDSA         /** Enable ECDSA use */
//#define EIP130_ENABLE_ASYM_ALGO_EDDSA         /** Enable EDDSA use */
//#define EIP130_ENABLE_ASYM_ALGO_ECC_ELGAMAL   /** Enable ECC-ElGamal use */
#define EIP130_ENABLE_ASYM_ALGO_RSA           /** Enable RSA use */
//#define EIP130_ENABLE_ASYM_ALGO_SM2           /** Enable SM2 use */

/* - Token Group eMMC acces */
//#define EIP130_ENABLE_EMMC                    /** Enable eMMC token functionality */

/* - Token External Service operations */
//#define EIP130_ENABLE_EXTSERVICE              /** Enable external service functionality */

/* - Token Group Service */

/* - Token Group System */
//#define EIP130_ENABLE_FIRMWARE_SLEEP          /** Enable firmware sleep functionality */
//#define EIP130_ENABLE_FIRMWARE_HIBERNATION    /** Enable firmware hibernation functionality */
//#define EIP130_ENABLE_SYSTEM_ENTERFIPSMODE    /** Enable Enter-FIPS-mode function */


/** The next switches are intended for footprint reduction.\n
 *  Uncomment to disable the function to reduce code size and overhead.\n
 *  Comment to enable the function
 */
#define EIP130_REMOVE_MAILBOXGETOPTIONS
//#define EIP130_REMOVE_MAILBOXACCESSVERIFY
#define EIP130_REMOVE_MAILBOXACCESSCONTROL
//#define EIP130_REMOVE_MAILBOXLINK
#define EIP130_REMOVE_MAILBOXLINKRESET
//#define EIP130_REMOVE_MAILBOXUNLINK
//#define EIP130_REMOVE_MAILBOXCANWRITETOKEN
#define EIP130_REMOVE_MAILBOXRAWSTATUS
#define EIP130_REMOVE_MAILBOXRESET
#define EIP130_REMOVE_MAILBOXLINKID
#define EIP130_REMOVE_MAILBOXOUTID

#define EIP130_REMOVE_FIRMWARECHECK
#define EIP130_REMOVE_FIRMWAREDOWNLOAD
#define EIP130_REMOVE_MODULEFIRMWAREWRITTEN
#define EIP130_REMOVE_MODULEGETOPTIONS
#define EIP130_REMOVE_MODULEGETSTATUS
//#define EIP130_REMOVE_VERSION_OPTION


#endif /* INCLUDE_GUARD_CS_EIP130_H */

/* end of file cs_eip130.h */

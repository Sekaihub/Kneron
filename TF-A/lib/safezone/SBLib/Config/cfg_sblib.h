/* cfg_sblib.h
 *
 * Description: Secure boot library constants, common
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

/* Maximum size of the Secure Boot Image (excluding the header).
 * Note: Do not increase the limit unless it is known that the used
 *       Secure Boot variant is able to handle larger images.
 */
#ifndef SBLIB_CFG_DATASIZE_MAX
#define SBLIB_CFG_DATASIZE_MAX         16777216 /* 16M */
#endif

/* The size of storage workspace used by Secure Boot.
 * The minimum value depends on Secure Boot configuration and hardware used to
 * implement Secure Boot.
 */
#ifndef SBLIB_CFG_STORAGE_SIZE
#if SBLIB_CFG_DATASIZE_MAX <= (16*1024*1024)
#define SBLIB_CFG_STORAGE_SIZE         2048
#else
#define SBLIB_CFG_STORAGE_SIZE         4096
#endif
#endif

/* The maximum number of certificates allowed in SBIF images.
 */
#ifndef SBLIB_CFG_CERTIFICATES_MAX
/* Default value when not provided on compiler command-line
 */
#define SBLIB_CFG_CERTIFICATES_MAX     8
#endif

/* Verify public key. (Intended for the software implementation)
 *
 * The public key can come from ROM, OTP/NVM or image. For the ROM and OTP/NVM
 * situations, it is guaranteed to be correct. However, to ensure the system
 * is setup correctly, the Secure Boot allows basic checking for correctness
 * of used public key. For the image situation, the public key can be checked
 * based on the SHA-256 Digest that is stored in OTP/NVM.
 *
 * Define level of checking (Only applicable for ROM and OTP/NVM):
 *    0    do not validate public key (default)
 *    1    basic verification (public key is point on the curve)
 */
#ifndef SBLIB_CFG_PUBLIC_KEY_VERIFY
#define SBLIB_CFG_PUBLIC_KEY_VERIFY    0
#endif

/* Hardware target specific configuration items
 * These configuration items are ignored on other hardware targets.
 */
/* The device name to use when locating the EIP-28 PK (Public Key Accelerator)
 * device via the Driver Framework API Device_Find().
 * This device is only used if SBHYBRID_WITH_EIP28 is defined.
 */
#define SBLIB_CFG_PKA_DEVICE   "EIP28"

/* The device name to use when locating the EIP-93 PE (Packet Engine) device
 * via the Driver Framework API Device_Find().
 * This device is only used if SBHYBRID_WITH_EIP93 is defined.
 */
#define SBLIB_CFG_PE_DEVICE    "EIP93"

/* The device name to use when locating the EIP-130 SM (Security Module) device
 * via the Driver Framework API Device_Find().
 * This device is only used if SBHYBRID_WITH_EIP130 is defined.
 */
#define SBLIB_CFG_SM_DEVICE    "EIP130"

/* Only applicable for the EIP-130 SM (Security Module) the type of mailbox
 * and source data access must be defined.
 * If defined, the access is 'Secure'.
 * If not defined, the access is 'Non-secure' (default).
 */
#define SBLIB_CFG_SM_SECURE_ACCESS

/* Only applicable for the EIP-130 SM (Security Module) to control how the
 * curve parameters are loaded into the EIP-130 SM. The curve parameters are
 * initialized as 'static const uint8_t PublicKeyParameters[]', which normally
 * means that they end-up in ROM.
 * If defined, the curve parameters are copied from their ROM location to the
 *     workspace (which is assumed to be DMA safe), so that the EIP-130 SM
 *     can fetch them via the DMA transfer during the Asset Load.
 * If not defined, the curve parameters are directly fetched from ROM by the
 *     EIP-130 SM via the DMA transfer during the Asset Load. (default)
 */
#define SBLIB_CFG_SM_COPY_CURVEPARAMS

/* Configuration items that are only used for the EIP-130 SM (Security Module)
 * and EIP-123 CM (Crypto Module)
 */
/* Mailbox number to use to access the Security or Crypto Module device.
 * Must be 1, 2, 3 or 4.
 */
#define SBLIB_CFG_XM_MAILBOXNR  1

/* Define the Identity to use in tokens
 * This can be used to separate boot loader assets from the normal system
 */
#ifdef SBLIB_CFG_SM_SECURE_ACCESS
#define SBLIB_CFG_XM_TOKEN_IDENTITY  0x4F5A3647 /* COID required */
#else
#define SBLIB_CFG_XM_TOKEN_IDENTITY  0x6953424C /* Can be any */
#endif

/* The Asset Number of the Static Asset stored in OTP/NVM that is used for
 * decryption of the BLw images. The Static Asset can be an AES unwrap key
 * or derivation key to derive an AES unwrap key. The AES unwrap key must be
 * either 128-bit or 256-bit, depending on SBIF_CFG_CONFIDENTIALITY_BITS.
 * The exact Asset Number depends on the OTP/NVM contents.
 * This value is only used if SBLIB_CF_IMAGE_TYPE_W_SBCR_KEY is not defined.
 * See also: cf_sblib.h:SBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
 */
#ifndef SBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
#define SBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY_128         9
#define SBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY_256         8
#define SBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_DERIVE_KEY_128  7
#define SBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_DERIVE_KEY_256  6
#endif

/* end of file cfg_sblib.h */

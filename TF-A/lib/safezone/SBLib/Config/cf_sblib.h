/* cf_sblib.h
 *
 * Description: Configuration template for Secure Boot implementation.
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

// Define to remove calls to SB_Poll()
//#define SBLIB_CF_REMOVE_POLLING_CALLS

// Define to remove support for certificates in images.
//#define SBLIB_CF_REMOVE_CERTIFICATE_SUPPORT

// Define to remove support for wrapped images.
//#define SBLIB_CF_REMOVE_IMAGE_TYPE_W

// Define to remove support for encrypted images.
//#define SBLIB_CF_REMOVE_IMAGE_TYPE_E

// Define to remove support for plaintext images.
//#define SBLIB_CF_REMOVE_IMAGE_TYPE_P

// Define to remove support for encrypted images without key.
#define SBLIB_CF_REMOVE_IMAGE_TYPE_X

// Define to remove support for public data read.
//#define SBLIB_CF_REMOVE_PUBLICDATA

// Define to remove support for system info read.
#define SBLIB_CF_REMOVE_SYSTEMINFO_READ

// Define to remove support for set FIPS mode.
#define SBLIB_CF_REMOVE_SETFIPSMODE

// Define to use the SBCR key from SBCommon/SB_SW_CRYPTO/src/scbr_key.c as the
// AES-WRAP unwrap key or derivation key (both refered to as SBCR) for a BLw
// image.
// This define is only meaningful for the Secure Boot variant SB_SM. This
// variant has access to OTP storage that can be used for securely storing the
// SBCR, for other Secure Boot targets SBCommon/SB_SW_CRYPTO/src/scbr_key.c is
// always used.
// See also: cfg_sblib.h:SBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY
//#define SBLIB_CF_IMAGE_TYPE_W_SBCR_KEY

/* end of file cf_sblib.h */

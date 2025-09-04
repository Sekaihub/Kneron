/* cf_sb.h
 *
 * Description: Common secure boot definitions
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

/* These common definitions describe the platform and (potentially) advice in
 * platform specific optimizations.
 */

/* Specify processor endianness
 * Define either of following if not using autoconf.
 * With autoconf, none should be defined as endian
 * is detected automatically.
 */
/* #define SB_CF_LITTLEENDIAN */
/* #define SB_CF_BIGENDIAN */

/* Specific for the software implementation of AES (Rijndael). This define
 * specifies if the code must be optimized either for speed (default) or size.
 * If the define is uncommented the software implementation of AES is optimized
 * for size, with which roughly 4k bytes of ROM size is saved but the encrypt/
 * decrypt speed will be impacted.
 */
/* #define AES_OPTIMIZE_ROM_SIZE */


/* end of file cf_sb.h */

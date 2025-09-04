/**
 * File: cfg_sbif.h
 *
 * Description : Secure boot constants (special template to force 256-bit)
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

#ifndef INCLUDE_GUARD_CFG_SBIF_H
#define INCLUDE_GUARD_CFG_SBIF_H

/* Number of bits to use in ECDSA calculation.
 * Notice this is set to 256 to force support for ECDSA256
 */
#define SBIF_CFG_ECDSA_BITS           256

/* Number of AES bits to use in confidentiality protection.
 * Notice this is set to 256 to force support for AES-256
 */
#define SBIF_CFG_CONFIDENTIALITY_BITS 256

/* Minimum value for ROLLBACK ID attribute.
 * (Optional: if specified, SBIF will enforce values for rollback ID.)
 */
#define SBIF_CFG_ATTRIBUTE_MINIMUM_ROLLBACK_ID  1

/* Define this if the AES unwrap key has to be derived from the KDK
 */
#define SBIF_CFG_DERIVE_WRAPKEY_FROM_KDK

#endif /* INCLUDE_GUARD_CFG_SBIF_H */

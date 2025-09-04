/* sbcr_key.h
 *
 * Description: Internal declaration of array containing Secure Boot
 *              Confidentiality Root Key.
 *              This declaration is for aes_if.c implementation in SW,
 *              thus used by SB_SW and UpdateTool.
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

#ifndef INCLUDE_GUARD_SBCR_KEY_H
#define INCLUDE_GUARD_SBCR_KEY_H

#include "public_defs.h"
#include "cfg_sbif.h"

/* Array containing Secure Boot Confidentiality Root Key.
   The value is defined in sbcr_key.c. */
#ifdef SBIF_CFG_CONFIDENTIALITY_BITS
extern const uint8_t SBCommon_SBCRK[SBIF_CFG_CONFIDENTIALITY_BITS / 8];
#else
extern const uint8_t SBCommon_SBCRK[4 * 4];
#endif /* SBIF_CFG_CONFIDENTIALITY_BITS */

#endif /* INCLUDE_GUARD_SBCR_KEY_H */

/* end of file sbcr_key.h */

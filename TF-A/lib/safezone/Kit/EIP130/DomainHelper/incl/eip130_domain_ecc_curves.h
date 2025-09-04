/* eip130_domain_ecc_curves.h
 *
 * Standard (pre-defined) ECC curves interface.
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

#ifndef INCLUDE_GUARD_EIP130DOMAIN_ECC_CURVES_H
#define INCLUDE_GUARD_EIP130DOMAIN_ECC_CURVES_H

#include "basic_defs.h"             /* uint8_t, etc. */


/* Eip130Domain_ECCurveFamily_t - Elliptic Curve families */
typedef uint8_t Eip130Domain_ECCurveFamily_t;

#define EIP130DOMAIN_ECC_FAMILY_NONE             0U
#define EIP130DOMAIN_ECC_FAMILY_NIST_P           1U
#define EIP130DOMAIN_ECC_FAMILY_BRAINPOOL_R1     2U
#define EIP130DOMAIN_ECC_FAMILY_MONTGOMERY       3U
#define EIP130DOMAIN_ECC_FAMILY_TWISTED_EDWARDS  4U
#define EIP130DOMAIN_ECC_FAMILY_SM2              5U


/*----------------------------------------------------------------------------
 * Eip130Domain_ECC_GetCurve
 *
 * This function returns the curve parameters for the requested (standard) EC
 * curve.
 *
 * CurveFamily
 *     The family of the requested EC curve.
 *     (Please, see Eip130Domain_ECCurveFamily_t)
 *
 * CurveBits
 *      Size of the EC curve in bits
 *
 * pCurveParams
 *     Pointer that will point to the curve parameters or NULL on return.
 *
 * pCurveParamsSize
 *     Pointer that points to a size variable that will hold the size of
 *     the returned curve parameters in bytes.
 *
 * Return Value:
 *     false: If curve is not found/supported
 *     true:  If curve is found/supported
 */
bool
Eip130Domain_ECC_GetCurve(const Eip130Domain_ECCurveFamily_t CurveFamily,
                          const uint32_t CurveBits,
                          const uint8_t ** ppCurveParams,
                          uint32_t * pCurveParamsSize);


#endif /* INCLUDE_GUARD_EIP130DOMAIN_ECC_CURVES_H */

/* end of file eip130_domain_ecc_curves.h */

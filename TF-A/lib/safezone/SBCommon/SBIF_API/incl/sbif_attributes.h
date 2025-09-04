/* sbif_attributes.h
 *
 * Description: API for dealing with different SBIF attributes in
 *              Secure Boot image.
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

#ifndef INCLUDE_GUARD_SBIF_ATTRIBUTES_H
#define INCLUDE_GUARD_SBIF_ATTRIBUTES_H

#include "public_defs.h"
#include "cfg_sbif.h"
#include "sbif.h"

bool SBIF_Attributes_Add(SBIF_Attributes_t * const   Attributes_p,
                         SBIF_AttributeElementType_t ElementType,
                         uint32_t                    ElementValue);

bool SBIF_Attribute_Fetch(const SBIF_Attributes_t * const Attributes_p,
                          SBIF_AttributeElementType_t     ElementType,
                          uint32_t * const                ElementValue_p);

bool SBIF_Attribute_Check(const SBIF_Attributes_t * const Attributes_p);

#endif /* INCLUDE_GUARD_SBIF_ATTRIBUTES_H */

/* end of file sbif_attributes.h */

/* sbif_attributes.c
 *
 * Description: Tools for dealing with different SBIF attributes in
 *              Secure Boot image. Implementation.
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

#include "endian_utils.h"
#include "cfg_sbif.h"
#include "sbif_attributes.h"


/*----------------------------------------------------------------------------
 * SBIF_Attribute_Fetch
 */
bool
SBIF_Attribute_Fetch(
        const SBIF_Attributes_t * const Attributes_p,
        SBIF_AttributeElementType_t     ElementType,
        uint32_t * const                ElementValue_p)
{
    int i;

    /* Scan for insertion point. */
    for(i = 0; i < SBIF_NUM_ATTRIBUTES; i++)
    {
        SBIF_AttributeElementType_t type =
            Load_BE32(&Attributes_p->AttributeElements[i].ElementType);

        if (type == ElementType)
        {
            *ElementValue_p =
                Load_BE32(&Attributes_p->AttributeElements[i].ElementValue);
            return true;
        }
    }

    return false;
}


/*----------------------------------------------------------------------------
 * SBIF_Attribute_Check
 */
bool
SBIF_Attribute_Check(
        const SBIF_Attributes_t * const Attributes_p)
{
    SBIF_AttributeElementType_t type;
    int i;

    /* Get first attribute. */
    type = Load_BE32(&Attributes_p->AttributeElements[0].ElementType);

    /* Check there is version attribute with correct value. */
    if ((type != SBIF_ATTRIBUTE_VERSION) ||
        (Load_BE32(&Attributes_p->AttributeElements[0].ElementValue) !=
         SBIF_ATTRIBUTE_VERSION_CURRENT))
    {
        return false;
    }

    for(i = 1; i < SBIF_NUM_ATTRIBUTES; i++)
    {
        SBIF_AttributeElementType_t nextType;

        nextType = Load_BE32(&Attributes_p->AttributeElements[i].ElementType);
        if (nextType != SBIF_ATTRIBUTE_UNUSED)
        {
            /* Check attribute order or dup. */
            if (nextType <= type)
            {
                return false;
            }

            /* Check for unknown non-extension attributes. */
            if ((nextType > SBIF_ATTRIBUTE_ROLLBACK_ID) &&
                ((nextType & 0x80000000) == 0))
            {
                return false;
            }

#ifdef SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID
            /* Check attribute value (ROLLBACK ID attribute only) */
            if (nextType == SBIF_ATTRIBUTE_ROLLBACK_ID)
            {
                if (Load_BE32(&Attributes_p->AttributeElements[i].ElementValue) <
                    SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID)
                {
                    return false;
                }
            }
#endif /* SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID */
        }

        type = nextType;
    }

    return true;
}

/* end of file sbif_attributes.c */

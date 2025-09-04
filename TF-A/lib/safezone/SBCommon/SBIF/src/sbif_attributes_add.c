/* sbif_attributes_add.c
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
 * SBIF_Attributes_Add
 */
bool
SBIF_Attributes_Add(SBIF_Attributes_t * const   Attributes_p,
                    SBIF_AttributeElementType_t ElementType,
                    uint32_t                    ElementValue)
{
    int i;

    L_TRACE(LF_SBIF,
            "ElementType=0x%08x; ElementValue=0x%08x",
            (unsigned int)ElementType, ElementValue);

    /* Check extension space (free slots) */
    if (Attributes_p->AttributeElements[SBIF_NUM_ATTRIBUTES - 1].ElementType != 0)
    {
        return false;
    }

#ifdef SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID
    L_TRACE(LF_SBIF,
            "SBIF_ATTRIBUTE_ROLLBACK_ID=0x%08x; "
            "SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID=0x%08x",
            SBIF_ATTRIBUTE_ROLLBACK_ID,
            SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID);

    /* Check attribute value (ROLLBACK ID attribute only) */
    if ((ElementType == SBIF_ATTRIBUTE_ROLLBACK_ID) &&
        (ElementValue < SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID))
    {
        L_DEBUG(LF_SBIF,
                "Rejecting attribute due to minimum rollback ID (%d: %d < %d)\n",
                ElementType, ElementValue, SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID);
        return false;
    }
#endif /* SBIF_ATTRIBUTE_MINIMUM_ROLLBACK_ID */

    /* Scan for insertion point. */
    for(i = 0; i < (SBIF_NUM_ATTRIBUTES - 1); i++)
    {
        SBIF_AttributeElementType_t Type;

        Type = Load_BE32(&Attributes_p->AttributeElements[i].ElementType);
        if (Type == ElementType)
        {
            L_TRACE(LF_SBIF, "Rejecting due to dupe\n");
            return false;
        }

        if (Type > ElementType)
        {
            break;
        }

        if (Type == SBIF_ATTRIBUTE_UNUSED)
        {
            break;
        }
    }

    /* If the attribute is not the last attribute. */
    if (i < (SBIF_NUM_ATTRIBUTES -1))
    {
        int l;

        /* Move next attributes one step further away. */
        for(l = (SBIF_NUM_ATTRIBUTES - 1); l > i; l--)
        {
            Attributes_p->AttributeElements[l].ElementType =
                Attributes_p->AttributeElements[l - 1].ElementType;
            Attributes_p->AttributeElements[l].ElementValue =
                Attributes_p->AttributeElements[l - 1].ElementValue;
        }
    }

    /* Insert new attribute. */
    Store_BE32(&Attributes_p->AttributeElements[i].ElementType, ElementType);
    Store_BE32(&Attributes_p->AttributeElements[i].ElementValue, ElementValue);

    return true;
}

/* end of file sbif_attributes_add.c */

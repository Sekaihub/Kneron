/* eip93_descriptor.h
 *
 * EIP93 Driver Library Descriptor Interface
 *
 * This interface can be used by any module (not only Adapters)
 * that have to provide EIP93 Command descriptors and have to
 * interpret EIP93 Result descriptors.
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

#ifndef INCLUDE_GUARD_EIP93_DESCRIPTOR_H
#define INCLUDE_GUARD_EIP93_DESCRIPTOR_H

#include "basic_defs.h"


/*----------------------------------------------------------------------------
 * Command descriptor control fields
 */
typedef struct
{
    //Packet tail allignment boundary,Bit map with only one bit or
    //none set.
    uint8_t PadControl;
    //next header value
    uint8_t NextHeaderValue;
    //finalize hash operation
    bool fHashFinal;

} EIP93_CommandDescriptor_Control_t;


/*----------------------------------------------------------------------------
 * Result descriptor status fields
 */
typedef struct
{
    //count of pad bytes inserted/detected
    uint8_t PadStatus;
    //Pad value;
    uint8_t PadValue;
    // raw status field
    uint8_t RawStatus;

    // extended error or notification code
    unsigned int ExtendedErrorCode;
    // indicates the validity of above error or notification codes
    bool fErrorORNotificationValid;
    //sequence number fault or overflow
    bool fSequenceNumberFail;
    //pad miss match
    bool fCryptoPadFail;
    //ICV doesn't mactch
    bool fAuthenticationFail;

} EIP93_ResultDescriptor_Status_t;


/*----------------------------------------------------------------------------
 *                         Helper functions API
 *----------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------
 * EIP93_CommandDescriptor_Control_MakeWord
 *
 * This function returns Control Word for EIP93 Command descriptor.
 *
 * CommandCtrl_p (input)
 *      control fields that have to be packed in the EIP93 specific format
 *
 * Returns:
 *      a 32bit word containing all control fields in EIP93 specific format
 */
uint32_t
EIP93_CommandDescriptor_Control_MakeWord(
    const EIP93_CommandDescriptor_Control_t * const  CommandCtrl_p);


/*----------------------------------------------------------------------------
 * EIP93_ResultDescriptor_Status_InterpretWord
 *
 * This function returns Status info interpretted from
 * a status word of the EIP93 Result descriptor.
 *
 * StatusWord (input)
 *      status fields packed in the EIP93 specific format
 *
 * ResultStatus_p (output):
 *      a data structure instance containing all status fields
 *      interpretted from the EIP93 specific format
 */
void
EIP93_ResultDescriptor_Status_InterpretWord(
    const uint32_t StatusWord,
    EIP93_ResultDescriptor_Status_t * const  ResultStatus_p);


#endif /* INCLUDE_GUARD_EIP93_DESCRIPTOR_H */

/* end of file eip93_descriptor.h */

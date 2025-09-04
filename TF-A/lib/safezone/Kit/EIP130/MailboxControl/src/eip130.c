/* eip130.c
 *
 * EIP-13x Root of Trust / Security Module Driver Library API implementation
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

#include "basic_defs.h"             /* uint8_t, IDENTIFIER_NOT_USED, etc. */
#include "device_types.h"           /* Device_Handle_t */
#include "eip130.h"                 /* the API we will implement */
#include "eip130_token_common.h"    /* Eip130Token/Register_* defines */
#include "eip130_token_system.h"    /* Eip130Token_* defines */
#include "eip130_token_result.h"    /* Eip130Token_* defines */
#include "eip130_level0.h"          /* EIP130_* helper functions/defines */


#ifndef EIP130_REMOVE_MODULEGETOPTIONS
/*----------------------------------------------------------------------------
 * EIP130_ModuleGetOptions
 */
void
EIP130_ModuleGetOptions(
        Device_Handle_t Device,
        uint8_t * const fFWRam_p,
        uint8_t * const BusIfc_p,
        uint16_t * const Engines_p,
        uint16_t * const CustomEngines_p)
{
    Eip130RegisterWord_t Value = EIP130_RegisterReadOptions2(Device);

    if (fFWRam_p != NULL)
    {
        *fFWRam_p = (uint8_t)(MASK_1_BIT & (Value >> 9));
    }

    if (BusIfc_p != NULL)
    {
        *BusIfc_p = (uint8_t)(MASK_1_BIT & (Value >> 12));
    }

    if (Engines_p != NULL)
    {
        *Engines_p = (uint16_t)(MASK_6_BITS & (Value >> 0));
    }

    if (CustomEngines_p != NULL)
    {
        *CustomEngines_p = (uint16_t)(128U << (MASK_10_BITS & (Value >> 16)));
    }
}
#endif


#ifndef EIP130_REMOVE_MODULEGETSTATUS
/*----------------------------------------------------------------------------
 * EIP130_ModuleGetStatus
 */
void
EIP130_ModuleGetStatus(
        Device_Handle_t Device,
        uint8_t * const fFIPSMode_p,
        uint8_t * const fFatalError_p,
        uint8_t * const fCRC24Ok_p,
        uint8_t * const fCRC24Busy_p,
        uint8_t * const fCRC24Error_p,
        uint8_t * const fFirmwareWritten_p,
        uint8_t * const fFirmwareChecks_p,
        uint8_t * const fFirmwareAccepted_p)
{
    Eip130RegisterWord_t Value = EIP130_RegisterReadModuleStatus(Device);

    if (fFIPSMode_p != NULL)
    {
        if ((Value & BIT_1) == 0U)
        {
            *fFIPSMode_p = (uint8_t)(MASK_1_BIT & (Value >> 0));
        }
        else
        {
            *fFIPSMode_p = 0U;
        }
    }

    if (fFatalError_p != NULL)
    {
        *fFatalError_p = (uint8_t)(MASK_1_BIT & (Value >> 31));
    }

    if (fCRC24Ok_p != NULL)
    {
        *fCRC24Ok_p = (uint8_t)(MASK_1_BIT & (Value >> 9));
    }
    if (fCRC24Busy_p != NULL)
    {
        *fCRC24Busy_p = (uint8_t)(MASK_1_BIT & (Value >> 8));
    }
    if (fCRC24Error_p != NULL)
    {
        *fCRC24Error_p = (uint8_t)(MASK_1_BIT & (Value >> 10));
    }

    if (fFirmwareWritten_p != NULL)
    {
        *fFirmwareWritten_p = (uint8_t)(MASK_1_BIT & (Value >> 20));
    }
    if (fFirmwareChecks_p != NULL)
    {
        *fFirmwareChecks_p = (uint8_t)(MASK_1_BIT & (Value >> 22));
    }
    if (fFirmwareAccepted_p != NULL)
    {
        *fFirmwareAccepted_p = (uint8_t)(MASK_1_BIT & (Value >> 23));
    }
}
#endif


#ifndef EIP130_REMOVE_MODULEGETVERSION
/*----------------------------------------------------------------------------
 * EIP130_ModuleGetVersion
 */
void
EIP130_ModuleGetVersion(
        Device_Handle_t Device,
        uint8_t * const EipNumber_p,
        uint8_t * const MajorVersion_p,
        uint8_t * const MinorVersion_p,
        uint8_t * const PatchLevel_p)
{
    Eip130RegisterWord_t Value = EIP130_RegisterReadVersion(Device);

    if (EipNumber_p != NULL)
    {
        *EipNumber_p = (uint8_t)(MASK_8_BITS & (Value >> 0));
    }

    if (MajorVersion_p != NULL)
    {
        *MajorVersion_p = (uint8_t)(MASK_4_BITS & (Value >> 24));
    }
    if (MinorVersion_p != NULL)
    {
        *MinorVersion_p = (uint8_t)(MASK_4_BITS & (Value >> 20));
    }
    if (PatchLevel_p != NULL)
    {
        *PatchLevel_p = (uint8_t)(MASK_4_BITS & (Value >> 16));
    }
}
#endif


#if !defined(EIP130_REMOVE_MODULEFIRMWAREWRITTEN) || \
    !defined(EIP130_REMOVE_FIRMWAREDOWNLOAD)
/*----------------------------------------------------------------------------
 * EIP130_ModuleFirmwareWritten
 */
void
EIP130_ModuleFirmwareWritten(
        Device_Handle_t Device)
{
    EIP130_RegisterWriteModuleStatus(Device, EIP130_FIRMWARE_WRITTEN);
}
#endif


#ifndef EIP130_REMOVE_MAILBOXACCESSVERIFY
/*----------------------------------------------------------------------------
 * EIP130_MailboxAccessVerify
 */
Eip130FunctionStatus_t
EIP130_MailboxAccessVerify(
        Device_Handle_t Device,
        const uint8_t MailboxNr)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */
    Eip130RegisterWord_t Value;

    /* Check for the hardware (EIP-130/140 or EIP-133) */
    Value = EIP130_RegisterReadVersion(Device) & 0x0000FFFFU;
    if ((Value != 0x7D82U) && (Value != 0x7A85U) && (Value != 0x738CU))
    {
        /* Not supported (Is HW active?) */
        rc = -1;
    }
    else
    {
        /* Check if the mailbox number is valid */
        Value = EIP130_RegisterReadOptions(Device);
        if (MailboxNr > (MASK_4_BITS & Value))
        {
            /* Invalid mailbox number */
            rc = -2;
        }
        else
        {
            /* Intentionally no lock-out check here */
        }
    }

    return rc;
}
#endif


#if !defined(EIP130_REMOVE_MAILBOXGETOPTIONS) || \
    !defined(EIP130_REMOVE_FIRMWARECHECK)
/*----------------------------------------------------------------------------
 * EIP130_MailboxGetOptions
 */
void
EIP130_MailboxGetOptions(
        Device_Handle_t Device,
        uint8_t * const MyHostID_p,
        uint8_t * const MasterID_p,
        uint8_t * const MyProt_p,
        uint8_t * const ProtAvailable_p,
        uint8_t * const NrOfMailboxes_p,
        uint16_t * const MailboxSize_p,
        uint8_t * const HostId_p,
        uint8_t * const SecureHostId_p)
{
    Eip130RegisterWord_t Value = EIP130_RegisterReadOptions(Device);

    if (MyHostID_p != NULL)
    {
        *MyHostID_p = (uint8_t)(MASK_3_BITS & (Value >> 20));
    }
    if (MyProt_p != NULL)
    {
        *MyProt_p = (uint8_t)(MASK_1_BIT & (Value >> 23));
    }

    if (MasterID_p != NULL)
    {
        *MasterID_p = (uint8_t)(MASK_3_BITS & (Value >> 16));
    }
    if (ProtAvailable_p != NULL)
    {
        *ProtAvailable_p = (uint8_t)(MASK_1_BIT & (Value >> 19));
    }

    if (NrOfMailboxes_p != NULL)
    {
        *NrOfMailboxes_p = (uint8_t)(MASK_4_BITS & (Value >> 0));
    }

    if (MailboxSize_p != NULL)
    {
        *MailboxSize_p = (uint16_t)(0x80UL << (MASK_2_BITS & (Value >> 4)));
    }

    if (HostId_p != NULL)
    {
        *HostId_p = (uint8_t)(MASK_8_BITS & (Value >> 8));
    }

    if (SecureHostId_p != NULL)
    {
        *SecureHostId_p = (uint8_t)(MASK_8_BITS & (Value >> 24));
    }
}
#endif


#ifndef EIP130_REMOVE_MAILBOXLINKID
/*----------------------------------------------------------------------------
 * EIP130_MailboxGetLinkID
 */
Eip130FunctionStatus_t
EIP130_MailboxGetLinkID(
        Device_Handle_t Device,
        const uint8_t MailboxNr,
        uint8_t * const HostID_p,
        uint8_t * const Secure_p)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */
    Eip130RegisterWord_t Value;

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
#endif

    if (rc == 0)
    {
        /* Get linked state */
        Value = EIP130_RegisterReadMailboxStatus(Device);
        if ((Value & ((uint32_t)BIT_2 << ((MailboxNr - 1U) * 4U))) == 0U)
        {
            /* Not linked */
            rc = -2;
        }
        else
        {
            /* Get linkID's */
            Value = EIP130_RegisterReadMailboxLinkId(Device);
            Value >>= (((uint32_t)MailboxNr - 1U) * 4U);

            if (HostID_p != NULL)
            {
                *HostID_p = Value & MASK_3_BITS;
            }

            if (Secure_p != NULL)
            {
                if (Value & BIT_3)
                {
                    *Secure_p = 1U;
                }
                else
                {
                    *Secure_p = 0U;
                }
            }
        }
    }

    return rc;
}
#endif


#ifndef EIP130_REMOVE_MAILBOXACCESSCONTROL
/*----------------------------------------------------------------------------
 * EIP130_MailboxAccessControl
 */
Eip130FunctionStatus_t
EIP130_MailboxAccessControl(
        Device_Handle_t Device,
        uint8_t MailboxNr,
        uint8_t HostNr,
        bool fAccessAllowed)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
    else if (HostNr > 7U)
    {
        /* Invalid host number */
        rc = -2;
    }
#endif

    if (rc == 0)
    {
        Eip130RegisterWord_t LockOut = EIP130_RegisterReadMailboxLockout(Device);
        Eip130RegisterWord_t BitMask = BIT_0;
        Eip130RegisterWord_t BitNr = (((uint32_t)MailboxNr - 1U) * 8U) + (uint32_t)HostNr;

        if (BitNr > 0U)
        {
             BitMask <<= BitNr;
        }

        if (fAccessAllowed)
        {
            /* Clear a bit to grant access */
            LockOut &= ~BitMask;
        }
        else
        {
            /* Set a bit to lock out access */
            LockOut |= BitMask;
        }

        EIP130_RegisterWriteMailboxLockout(Device, LockOut);
    }

    return rc;
}
#endif


#if !defined(EIP130_REMOVE_MAILBOXLINK) || \
    !defined(EIP130_REMOVE_FIRMWAREDOWNLOAD) || \
    !defined(EIP130_REMOVE_FIRMWARELOGIN)
/*----------------------------------------------------------------------------
 * EIP130_MailboxLink
 */
Eip130FunctionStatus_t
EIP130_MailboxLink(
        Device_Handle_t Device,
        const uint8_t MailboxNr)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
    else
#endif

    {
        Eip130RegisterWord_t GetValue;
        Eip130RegisterWord_t SetValue;

        SetValue = (uint32_t)BIT_2 << ((MailboxNr - 1U) * 4U);
        EIP130_RegisterWriteMailboxControl(Device, SetValue);

        GetValue = EIP130_RegisterReadMailboxStatus(Device);
        if ((GetValue & SetValue) != SetValue)
        {
            /* Link failed */
            rc = -2;
        }
    }

    return rc;
}
#endif


#if !defined(EIP130_REMOVE_MAILBOXUNLINK) || \
    !defined(EIP130_REMOVE_FIRMWAREDOWNLOAD)
/*----------------------------------------------------------------------------
 * EIP130_MailboxUnlink
 */
Eip130FunctionStatus_t
EIP130_MailboxUnlink(
        Device_Handle_t Device,
        const uint8_t MailboxNr)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
    else
#endif

    {
        Eip130RegisterWord_t SetValue;
        Eip130RegisterWord_t GetValue;

        /* Unlink mailbox */
        SetValue = (uint32_t)BIT_3 << ((MailboxNr - 1U) * 4U);
        EIP130_RegisterWriteMailboxControl(Device, SetValue);
        SetValue >>= 1;                 /* Adapt for linked check */

        /* Check if the mailbox is still linked */
        GetValue = EIP130_RegisterReadMailboxStatus(Device);
        if ((GetValue & SetValue) != 0U)
        {
            /* Unlink failed */
            rc = -2;
        }
    }

    return rc;
}
#endif


#if !defined(EIP130_REMOVE_MAILBOXLINKRESET) || \
    !defined(EIP130_REMOVE_FIRMWAREDOWNLOAD)
/*----------------------------------------------------------------------------
 * EIP130_MailboxLinkReset
 */
Eip130FunctionStatus_t
EIP130_MailboxLinkReset(
        Device_Handle_t Device,
        const uint8_t MailboxNr)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
#endif

    {
        uint32_t SetValue;
        uint32_t GetValue;

        SetValue = (uint32_t)BIT_3 << ((MailboxNr - 1U) * 4U);
        EIP130_RegisterWriteMailboxReset(Device, SetValue);

        GetValue = EIP130_RegisterReadMailboxStatus(Device);
        if ((GetValue & SetValue) != SetValue)
        {
            /* Link reset failed */
            rc = -2;
        }
    }

    return rc;
}
#endif


#if !defined(EIP130_REMOVE_MAILBOXCANWRITETOKEN) || \
    !defined(EIP130_REMOVE_FIRMWAREDOWNLOAD) || \
    !defined(EIP130_REMOVE_FIRMWARELOGIN)
/*----------------------------------------------------------------------------
 * EIP130_MailboxCanWriteToken
 */
bool
EIP130_MailboxCanWriteToken(
        Device_Handle_t Device,
        const uint8_t MailboxNr,
        Eip130RegisterWord_t * const ModuleStatus)
{
    bool rc = true;                     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
         rc = false;
    }
    else
#endif

    {
        Eip130RegisterWord_t Value;

        if (ModuleStatus != NULL)
        {
            *ModuleStatus = EIP130_RegisterReadModuleStatus(Device);
            Value = EIP130_RegisterReadOptions2(Device);
            if (((*ModuleStatus & BIT_9) == 0U) ||
                (((Value & BIT_9) != 0U) && ((*ModuleStatus & BIT_23) == 0U)))
            {
                /* EIP-130 is not (yet) useable:
                 * - ROM-Only & ROM/RAM: CRC24 not OK
                 * - ROM/RAM: FW is not accepted */
                rc = false;
            }
        }

        if (rc)
        {
            /* Read and validate mailbox write status */
            Value = EIP130_RegisterReadMailboxStatus(Device);
            if ((Value & ((uint32_t)BIT_0 << ((MailboxNr - 1U) * 4U))) != 0U)
            {
                /* IN mailbox not writeable */
                rc = false;
            }
        }
    }

    return rc;
}
#endif


/*----------------------------------------------------------------------------
 * EIP130_MailboxCanReadToken
 */
bool
EIP130_MailboxCanReadToken(
        Device_Handle_t Device,
        const uint8_t MailboxNr)
{
    bool rc = true;                     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = false;
    }
    else
#endif

    {
        /* Read and validate mailbox read status */
        Eip130RegisterWord_t Value = EIP130_RegisterReadMailboxStatus(Device);
        if ((Value & ((Eip130RegisterWord_t)BIT_1 << ((MailboxNr - 1U) * 4U))) == 0U)
        {
            /* OUT mailbox not readable */
            rc = false;
        }
    }

    return rc;
}


/*----------------------------------------------------------------------------
 * EIP130_MailboxWriteAndSubmitToken
 */
Eip130FunctionStatus_t
EIP130_MailboxWriteAndSubmitToken(
        Device_Handle_t Device,
        const uint8_t MailboxNr,
        const Eip130Token_Command_t * const CommandToken_p,
        const bool fDoCanWriteCheck)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
    else if (CommandToken_p == NULL)
    {
        /* No command token */
         rc = -2;
    }
#endif

#ifndef EIP130_REMOVE_MAILBOXCANWRITETOKEN
    if ((rc == 0) && fDoCanWriteCheck)
    {
        uint32_t ModuleStatus = 0;

        if (!EIP130_MailboxCanWriteToken(Device, MailboxNr, &ModuleStatus))
        {
            /* IN mailbox not writeable */
            rc = -3;
        }
    }
#else
    IDENTIFIER_NOT_USED(fDoCanWriteCheck);
#endif

    if (rc == 0)
    {
        /* Copy the token to the IN mailbox */
        {
            uint32_t MailboxAddr = EIP130_MAILBOX_IN_BASE;
            MailboxAddr += (EIP130_MAILBOX_SPACING_BYTES * ((uint32_t)MailboxNr - 1U));

            (void)Device_Write32Array(Device, (unsigned int)MailboxAddr,
                                      CommandToken_p->W,
                                      (int)EIP130TOKEN_COMMAND_WORDS);
        }

        /* Handover the IN mailbox (containing the token) to the EIP130 */
        {
            Eip130RegisterWord_t MailboxBit = (uint32_t)BIT_0 << ((MailboxNr - 1U) * 4U);

            EIP130_RegisterWriteMailboxControl(Device, MailboxBit);
            if ((EIP130_RegisterReadMailboxStatus(Device) & MailboxBit) == 0U)
            {
                /* Check for possible race condition (Host slow compared to HW)
                 * -> Assume token submit OK when the version register read
                 *    provides the expected information */
                Eip130RegisterWord_t Value;

                Value = EIP130_RegisterReadVersion(Device) & 0x0000FFFFU;
                if ((Value != 0x7d82U) && (Value != 0x738cU))
                {
                    /* Handover failed (Is HW active?) */
                    rc = -4;
                }
            }
        }
    }

    return rc;
}


/*----------------------------------------------------------------------------
 * EIP130_MailboxReadToken
 */
Eip130FunctionStatus_t
EIP130_MailboxReadToken(
        Device_Handle_t Device,
        const uint8_t MailboxNr,
        Eip130Token_Result_t * const ResultToken_p)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume success */

#ifdef EIP130_STRICT_ARGS
    if (MailboxNr < 1U || MailboxNr > 8U)
    {
        /* Invalid mailbox number */
        rc = -1;
    }
    else if (ResultToken_p == NULL)
    {
        /* No result token */
        rc = -2;
    }
    else
#endif

    {
        if (!EIP130_MailboxCanReadToken(Device, MailboxNr))
        {
            /* OUT mailbox not readable */
            rc = -3;
        }
        else
        {
            /* Copy the token from the OUT mailbox */
            {
                uint32_t MailboxAddr = EIP130_MAILBOX_IN_BASE;
                MailboxAddr += (EIP130_MAILBOX_SPACING_BYTES * ((uint32_t)MailboxNr - 1U));

                (void)Device_Read32Array(Device, (unsigned int)MailboxAddr,
                                         ResultToken_p->W,
                                         (int)EIP130TOKEN_RESULT_WORDS);
            }

            /* Hand back the OUT mailbox to the EIP130 */
            {
                Eip130RegisterWord_t MailboxBit = (uint32_t)BIT_1 << ((MailboxNr - 1U) * 4U);

                EIP130_RegisterWriteMailboxControl(Device, MailboxBit);
            }
        }
    }

    return rc;
}


#ifndef EIP130_REMOVE_FIRMWARECHECK
/*----------------------------------------------------------------------------
 * EIP130_FirmwareCheck
 */
Eip130FunctionStatus_t
EIP130_FirmwareCheck(
        Device_Handle_t Device)
{
    Eip130FunctionStatus_t rc = 0;     /* Assume firmware not written */
    Eip130RegisterWord_t Value;

    /* Check for the hardware (EIP-130/140 or EIP-133) */
    Value = EIP130_RegisterReadVersion(Device) & 0x0000FFFFU;
    if ((Value != 0x7D82U) && (Value != 0x7A85U) && (Value != 0x738CU))
    {
        /* Not supported hardware (Is HW active?) */
        rc = -1;
    }
    else
    {
        /* Check firmware configuration */
        Value = EIP130_RegisterReadOptions2(Device);
        if ((Value & BIT_9) == 0U)
        {
            /* ROM firmware only - Firmware is ready for use */
            rc = 3;
        }
    }

    if (rc == 0)
    {
        /* RAM Firmware - Check general hardware state */
        do
        {
            Value = EIP130_RegisterReadModuleStatus(Device);
        } while ((Value & EIP130_CRC24_BUSY) != 0U);
        if (((Value & EIP130_CRC24_OK) == 0U) ||
            ((Value & EIP130_FATAL_ERROR) != 0U))
        {
            /* Hardware error */
            rc = -3;
        }
    }

    if (rc == 0)
    {
#ifdef EIP130_HW_V3
        /* Check hardware/firmware state */
        Value &= (EIP130_FIRMWARE_WRITTEN | EIP130_FIRMWARE_CHECKS_BUSY | EIP130_FIRMWARE_ACCEPTED);
        switch (Value)
        {
        default:
            /* Invalid value state -> Hardware/Firmware state error */
            rc = -4;
            break;
        case (EIP130_FIRMWARE_WRITTEN):
            /* Expected value for FW download start */
            break;
        case (EIP130_FIRMWARE_CHECKS_BUSY):
            /* Firmware image load required */
            rc = 1;
            break;
        case (EIP130_FIRMWARE_WRITTEN | EIP130_FIRMWARE_CHECKS_BUSY):
            /* Firmware image checks are still busy */
            rc = 2;
            break;
        case (EIP130_FIRMWARE_WRITTEN | EIP130_FIRMWARE_ACCEPTED):
            /* Firmware is accepted -> Firmware is ready for use */
            rc = 3;
            break;
        }
#else
        if ((Value & EIP130_FIRMWARE_WRITTEN) != 0U)
        {
            /* - Check if firmware checks are done & accepted */
            if ((Value & EIP130_FIRMWARE_CHECKS_DONE) == 0U)
            {
                /* Firmware image checks are still busy */
                rc = 2;
            }
            else if ((Value & EIP130_FIRMWARE_ACCEPTED) != 0U)
            {
                /* Firmware is accepted -> Firmware is ready for use */
                rc = 3;
            }
        }
#endif
    }

    if ((rc == 0) || (rc == 1))
    {
        /* Firmware is NOT written/checks busy */
        /* Check Host ID - Is my_id equal to master_id? */
        uint8_t MyHostID;
        uint8_t MasterID;
#ifndef EIP130_ALLOW_MASTER_NONSECURE
        uint8_t MyProt_p;
        uint8_t ProtAvailable_p;
#endif

        EIP130_MailboxGetOptions(Device,
                                 &MyHostID, &MasterID,
#ifndef EIP130_ALLOW_MASTER_NONSECURE
                                 &MyProt_p, &ProtAvailable_p,
#else
                                 NULL, NULL,
#endif
                                 NULL, NULL, NULL, NULL);
        if ((MyHostID != MasterID)
#ifndef EIP130_ALLOW_MASTER_NONSECURE
            && (MyProt_p != ProtAvailable_p)
#endif
           )
        {
            /* This Host is NOT allowed to do the firmware load */
            rc = -2;
        }
    }

    return rc;
}
#endif


#ifndef EIP130_REMOVE_FIRMWAREDOWNLOAD
/*----------------------------------------------------------------------------
 * EIP130_FirmwareLoad
 */
extern char *curret_cfgToken;
Eip130FunctionStatus_t
EIP130_FirmwareLoad(
        Device_Handle_t Device,
        const uint8_t MailboxNr,
        const uint32_t * const Firmware_p,
        const uint32_t FirmwareWord32Size)
{
    Eip130FunctionStatus_t rc;

    /* Check if firmware needs to be loaded */
    rc = EIP130_FirmwareCheck(Device);
    if (rc < 0)
    {
        /* General error */
    }
    else if (rc == 3)
    {
        /* Firmware is already loaded and accepted (started) */
        rc = 0;
    }
    else
    {
        int16_t nLoadRetries;

        for (nLoadRetries = 3; nLoadRetries > 0; nLoadRetries--)
        {
            Eip130RegisterWord_t Value;
            int32_t nRetries;

#ifdef EIP130_HW_V3
            if (rc == 0)
            {
                /* Link mailbox
                 * Note: The HW is expected to come out of reset state, so mailbox
                 *       linking should be possible! */
                rc = EIP130_MailboxLink(Device, MailboxNr);
                if (rc < 0)
                {
                    /* General error */
                    break;
                }

                /* Check if mailbox is ready for the token
                 * Note: The HW is expected to come out of reset state, so direct
                 *       mailbox use should be possible! */
                if (EIP130_MailboxCanWriteToken(Device, MailboxNr, NULL))
                {
                    /* Write RAM-based Firmware Code Validation and Boot token (image header)
                     * Note: The first 256 bytes of the firmware image */
                    rc = EIP130_MailboxWriteAndSubmitToken(Device, MailboxNr,
			(const Eip130Token_Command_t * const)curret_cfgToken,
				false);
                }
                else
                {
                    /* General error */
                    rc = -1;
                }

                /* Always unlink mailbox */
                (void)EIP130_MailboxUnlink(Device, MailboxNr);

                if (rc < 0)
                {
                    /* Report error */
                    break;
                }
            }

            if (rc != 2)
            {
                /* Check that firmware image can be written */
                nRetries = 0x7FFFFFFF;
                while (true)
                {
                    Value = EIP130_RegisterReadModuleStatus(Device);
                    if (((Value & EIP130_CRC24_OK) == 0U) ||
                        ((Value & EIP130_FATAL_ERROR) != 0U))
                    {
                        /* Hardware error */
                        rc = -5;
                        break;
                    }
                    if ((Value & EIP130_FIRMWARE_WRITTEN) == 0U)
                    {
                        /* Write firmware code to FWRAM (image data)
                         * Note: The firmware code is located directly behind
                         *       the RAM-based Firmware Code Validation and
                         *       Boot token in the firmware image. */
				(void)Device_Write32Array(
				Device, EIP130_FIRMWARE_RAM_BASE,
				&Firmware_p[0],
				((int)FirmwareWord32Size - (256 / 4)));

                        /* Report that the firmware is written */
                        EIP130_ModuleFirmwareWritten(Device);
                        break;
                    }

                    /* Handle retries */
                    nRetries--;
                    if (nRetries <= 0)
                    {
                        /* General error (Is HW active?) */
                        rc = -1;
                        break;
                    }
                }
                if (rc < 0)
                {
                    /* Report error */
                    break;
                }
            }

            /* Check if firmware is accepted */
            nRetries = 0x7FFFFFFF;
            while (true)
            {
                Value = EIP130_RegisterReadModuleStatus(Device);
                if (((Value & EIP130_CRC24_OK) == 0U) ||
                    ((Value & EIP130_FATAL_ERROR) != 0U))
                {
                    /* Hardware error */
                    rc = -5;
                    break;
                }
                if ((Value & EIP130_FIRMWARE_ACCEPTED) != 0U)
                {
                    /* Firmware accepted and ready for use */
                    rc = 0;
                    break;
                }
                if ((Value & EIP130_FIRMWARE_CHECKS_BUSY) == 0U)
                {
                    /* Firmware NOT accepted */
                    rc = 1;
                    break;
                }

                /* Handle retries */
                nRetries--;
                if (nRetries <= 0)
                {
                    /* Timeout (Is HW active?) */
                    rc = -3;
                    break;
                }
            }
            if (rc <= 0)
            {
                /* Report error or Firmware accepted and ready for use */
                break;
            }
#else
            if (rc != 2)
            {
                /* Link mailbox
                 * Note: The HW is expected to come out of reset state, so mailbox
                 *       linking should be possible! */
                rc = EIP130_MailboxLink(Device, MailboxNr);
                if (rc < 0)
                {
                    /* General error */
                    break;
                }

                /* Check if mailbox is ready for the token
                 * Note: The HW is expected to come out of reset state, so direct
                 *       mailbox use should be possible! */
                if (EIP130_MailboxCanWriteToken(Device, MailboxNr, NULL))
                {
                    /* Write RAM-based Firmware Code Validation and Boot token (image header)
                     * Note: The first 256 bytes of the firmware image */
                    rc = EIP130_MailboxWriteAndSubmitToken(Device, MailboxNr,
			(const Eip130Token_Command_t * const)curret_cfgToken,
			false);
                }
                else
                {
                    /* General error */
                    rc = -1;
                }

                /* Always unlink mailbox */
                (void)EIP130_MailboxUnlink(Device, MailboxNr);

                if (rc < 0)
                {
                    /* Report error */
                    break;
                }

                /* Write firmware code to FWRAM (image data)
                 * Note: The firmware code is located directly behind
                 *       the RAM-based Firmware Code Validation and
                 *       Boot token in the firmware image. */
                (void)Device_Write32Array(Device, EIP130_FIRMWARE_RAM_BASE,
					&Firmware_p[0],
					(int)(FirmwareWord32Size - (256 / 4)));

                /* Report that the firmware is written */
                EIP130_ModuleFirmwareWritten(Device);
                Value = EIP130_RegisterReadModuleStatus(Device);
                if (((Value & EIP130_CRC24_OK) == 0U) ||
                    ((Value & EIP130_FATAL_ERROR) != 0U))
                {
                    /* Hardware error */
                    rc = -5;
                    break;
                }
                if ((Value & EIP130_FIRMWARE_WRITTEN) == 0U)
                {
                    /* General error (Is HW active?) */
                    rc = -1;
                    break;
                }

                /* Check if firmware check is started */
                for (nRetries = 0x0000FFFF; nRetries && ((Value & EIP130_FIRMWARE_CHECKS_DONE) != 0U); nRetries--)
                {
                    Value = EIP130_RegisterReadModuleStatus(Device);
                }
                if ((Value & EIP130_FIRMWARE_CHECKS_DONE) != 0U)
                {
                    /* Timeout (Is HW active?) */
                    rc = -3;
                    break;
                }
            }
            else
            {
                Value = 0U;
            }

            /* Check if firmware is accepted */
            for (nRetries = 0x7FFFFFFF; nRetries && ((Value & EIP130_FIRMWARE_CHECKS_DONE) == 0U); nRetries--)
            {
                Value = EIP130_RegisterReadModuleStatus(Device);
            }
            if ((Value & EIP130_FIRMWARE_CHECKS_DONE) == 0U)
            {
                /* Timeout (Is HW active?) */
                rc = -3;
                break;
            }
            if ((Value & EIP130_FIRMWARE_ACCEPTED) == EIP130_FIRMWARE_ACCEPTED)
            {
                /* Firmware is accepted (started) */
                rc = 0;
                break;
            }
#endif

            /* Reset state to do firmware token and image write again */
            rc = 0;
        }
        if (nLoadRetries <= 0)
        {
            /* Firmware load error */
            rc = -4;
        }
    }

    return rc;
}
#endif


#ifndef EIP130_REMOVE_FIRMWARELOGIN
/*----------------------------------------------------------------------------
 * EIP130_FirmwareLogin
 */
Eip130FunctionStatus_t
EIP130_FirmwareLogin(
        Device_Handle_t Device,
        const uint8_t MailboxNr,
        const uint32_t Identity,
        const bool fUnlinkMailbox)
{
    Eip130FunctionStatus_t rc;

    /* Link mailbox
     * Note: The HW is expected to come out of reset state, so mailbox
     *       linking should be possible! */
    rc = EIP130_MailboxLink(Device, MailboxNr);
    if (rc >= 0)
    {
        /* Submit login token */
        {
            Eip130Token_Command_t CommandToken;

            Eip130Token_Command_SystemLogin(&CommandToken);
            Eip130Token_Command_Identity(&CommandToken, Identity);

            rc = EIP130_MailboxWriteAndSubmitToken(Device, MailboxNr,
                                                   &CommandToken, true);
        }

        if (rc >= 0)
        {
            Eip130Token_Result_t ResultToken;

            /* Wait for the response token */
            while (EIP130_MailboxCanReadToken(Device, MailboxNr) == false)
            {
                /* Do nothing while waiting */
            }

            /* Read result token */
            rc = EIP130_MailboxReadToken(Device, MailboxNr, &ResultToken);
            if (rc >= 0)
            {
                rc = Eip130Token_Result_Code(&ResultToken);
                if (rc >= 0)
                {
                    /* Normalize return */
                    rc = 0;
                }
                else
                {
                    rc |= (int)BIT_16;  /* Ignore FAsvc bit setting for this token */
                    if (rc == EIP130TOKEN_RESULT_INVALID_TOKEN)
                    {
                        /* Login token is not supported, so it must be regarded as no error */
                        rc = 0;
                    }
                }
            }
        }

        if (fUnlinkMailbox)
        {
            (void)EIP130_MailboxUnlink(Device, MailboxNr);
        }
    }

    return rc;
}
#endif


/* end of file eip130.c */

/* eip130_token_system.h
 *
 * Security Module Token helper functions
 * - System token related functions and definitions
 *
 * This module can convert a set of parameters into a Security Module Command
 * token, or parses a set of parameters from a Security Module Result token.
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_SYSTEM_H
#define INCLUDE_GUARD_EIP130TOKEN_SYSTEM_H

#include "basic_defs.h"             /* uint32_t, bool, inline, etc. */
#include "clib.h"                   /* memset */
#include "eip130_token_common.h"    /* Eip130Token_Command/Result_t */

/* OTP error codes */
typedef enum
{
    EIP130TOKEN_SYSINFO_OTP_OK                       = 0U,
    EIP130TOKEN_SYSINFO_OTP_PROTECTED_ASSET_REPLACED = 1U,
    EIP130TOKEN_SYSINFO_OTP_PROTECTED_ASSET_REMOVED  = 2U,
    EIP130TOKEN_SYSINFO_OTP_PREMATURE_END            = 3U,
    EIP130TOKEN_SYSINFO_OTP_PROGRAMMED_BIT_MISMATCH  = 4U
} Eip130Token_OTP_State_t;


typedef struct
{
    struct
    {
        uint8_t Major;
        uint8_t Minor;
        uint8_t Patch;
        uint16_t MemorySizeInBytes;
    } Hardware;

    struct
    {
        uint8_t Major;
        uint8_t Minor;
        uint8_t Patch;
        bool fIsTestFW;
    } Firmware;

    struct
    {
        uint8_t HostID;
        uint32_t Identity;
    } SelfIdentity;

    struct
    {
        uint8_t ErrorCode;
        uint16_t ErrorLocation;
    } OTP;

} Eip130Token_SystemInfo_t;


/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemInfo
 *
 * This function writes the System Information command token.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 */
static inline void
Eip130Token_Command_SystemInfo(
        Eip130Token_Command_t * const CommandToken_p)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_SYSTEMINFO);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Result_SystemInfo
 *
 * This function parses the System Information result token. It can also
 * be used to query the (fixed) length of the firmware versions string this
 * function can generate.
 *
 * ResultToken_p
 *     Pointer to the result token buffer.
 *
 * Info_p
 *     Pointer to the information structure that this function will populate.
 */
static inline void
Eip130Token_Result_SystemInfo(
        const Eip130Token_Result_t * const ResultToken_p,
        Eip130Token_SystemInfo_t * const Info_p)
{
    uint32_t MaMiPa;

    (void)memset(Info_p, 0, sizeof(Eip130Token_SystemInfo_t));

    MaMiPa = ResultToken_p->W[1];
    Info_p->Firmware.Major = (uint8_t)(MaMiPa >> 16);
    Info_p->Firmware.Minor = (uint8_t)(MaMiPa >> 8);
    Info_p->Firmware.Patch = (uint8_t)MaMiPa;
    if ((MaMiPa & BIT_31) != 0U)
    {
        Info_p->Firmware.fIsTestFW = true;
    }

    MaMiPa = ResultToken_p->W[2];
    Info_p->Hardware.Major = (uint8_t)(MaMiPa >> 16);
    Info_p->Hardware.Minor = (uint8_t)(MaMiPa >> 8);
    Info_p->Hardware.Patch = (uint8_t)MaMiPa;

    Info_p->Hardware.MemorySizeInBytes = (uint16_t)ResultToken_p->W[3];

    Info_p->SelfIdentity.HostID = (uint8_t)((ResultToken_p->W[3] >> 16) & MASK_4_BITS);
    Info_p->SelfIdentity.Identity = ResultToken_p->W[4];

    Info_p->OTP.ErrorCode = (uint8_t)((ResultToken_p->W[5] >> 12) & MASK_4_BITS);
    Info_p->OTP.ErrorLocation = (uint16_t)(ResultToken_p->W[5] & MASK_12_BITS);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemSelfTest
 *
 * This function writes the Self Test command token, with which the self test
 * can be selected manually.
 *
 * Notes:
 * - In case of hardware version 2, this token also the initiates the
 *   transition to FIPS mode when the non-FIPS mode is active at the begin of
 *   the token processing.
 * - In case of hardware version 3, the Enter-FIPS-Mode token is required for
 *   the transition to FIPS mode. (Eip130Token_Command_EnterFipsMode)
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 */
static inline void
Eip130Token_Command_SystemSelfTest(
        Eip130Token_Command_t * const CommandToken_p)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_SELFTEST);
}

/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemLogin
 *
 * This function writes the Login command token.
 * To comply with the FIPS140-3 requirement that operations in ‘FIPS-Approved
 * mode’ can only be invoked by an authenticated user (or role), the Login
 * Token must be run after each hard reset or power-cycle before any other
 * Token can be used
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 */
static inline void
Eip130Token_Command_SystemLogin(
        Eip130Token_Command_t * const CommandToken_p)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_LOGIN);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_Reset
 *
 * This function writes the Reset command token, with which a software wise
 * reset of the firmware can be performed.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 */
static inline void
Eip130Token_Command_SystemReset(
        Eip130Token_Command_t * const CommandToken_p)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_RESET);
}


#ifdef EIP130_FW_ASSET_LIFETIME_MANAGEMENT
/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemSetTime
 *
 * This function writes the Set Time command token, with which the system time
 * can be set.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * Time
 *     The time value (seconds).
 */
static inline void
Eip130Token_Command_SystemSetTime(
        Eip130Token_Command_t * const CommandToken_p,
        const uint32_t Time)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_SETTIME);
    CommandToken_p->W[2] = Time;
}
#endif


#ifdef EIP130_ENABLE_FIRMWARE_SLEEP
/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemSleep
 *
 * This function writes the Sleep command token, with which the HW (EIP-13x)
 * is placed in sleep mode.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 */
static inline void
Eip130Token_Command_SystemSleep(
        Eip130Token_Command_t * const CommandToken_p)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_SLEEP);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemResumeFromSleep
 *
 * This function writes the Resume From Sleep command token, with which the
 * HW (EIP-13x) resumed to normal operation coming out of sleep mode.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 */
static inline void
Eip130Token_Command_SystemResumeFromSleep(
        Eip130Token_Command_t * const CommandToken_p)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_RESUMEFROMSLEEP);
}
#endif


#ifdef EIP130_ENABLE_FIRMWARE_HIBERNATION
/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemHibernation
 *
 * This function writes the Hibernation command token, with which the HW
 * (EIP-13x) is placed in hibernation mode.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * DataBlobAddress
 *      Data Blob address.
 *
 * DataBlobSizeInBytes
 *      Data Blob size.
 */
static inline void
Eip130Token_Command_SystemHibernation(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenDmaAddress_t DataBlobAddress,
        const Eip130TokenDmaSize_t DataBlobSizeInBytes)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_HIBERNATION);
    CommandToken_p->W[3] = BIT_31 | BIT_27;
    CommandToken_p->W[4] = 0U;
    CommandToken_p->W[5] = 0U;
    CommandToken_p->W[6] = (Eip130TokenWord_t)(DataBlobAddress);
    CommandToken_p->W[7] = (Eip130TokenWord_t)(DataBlobAddress >> 32);
    CommandToken_p->W[8] = ((Eip130TokenWord_t)DataBlobSizeInBytes & MASK_11_BITS);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemResumeFromHibernation
 *
 * This function writes the Resume From Hibernation command token, with which
 * the HW (EIP-13x) resumed to normal operation coming out of hibernation mode.
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * DataBlobAddress
 *      Data Blob address.
 *
 * DataBlobSizeInBytes
 *      Data Blob size.
 */
static inline void
Eip130Token_Command_SystemResumeFromHibernation(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenDmaAddress_t DataBlobAddress,
        const Eip130TokenDmaSize_t DataBlobSizeInBytes)
{
    CommandToken_p->W[0] = (EIP130TOKEN_OPCODE_SYSTEM |
                            EIP130TOKEN_SUBCODE_RESUMEFROMHIBERNATION);
    CommandToken_p->W[3] = BIT_26 | (DataBlobSizeInBytes & MASK_10_BITS);
    CommandToken_p->W[4] = (Eip130TokenWord_t)(DataBlobAddress);
    CommandToken_p->W[5] = (Eip130TokenWord_t))(DataBlobAddress >> 32);
    CommandToken_p->W[6] = 0U;
    CommandToken_p->W[7] = 0U;
    CommandToken_p->W[8] = 0U;
}


/*----------------------------------------------------------------------------
 * Eip130Token_Command_SystemHibernationInfomation
 *
 * CommandToken_p
 *     Pointer to the command token buffer.
 *
 * StateAssetId
 *      Asset ID of the State Asset to use.
 *
 * KeyAssetId
 *      Asset ID of the Key Encryption Key Asset to use.
 *
 * AssociatedData_p
 *      Associated Data address.
 *
 * AssociatedDataSizeInBytes
 *      Associated Data length.
 */
static inline void
Eip130Token_Command_SystemHibernationInfomation(
        Eip130Token_Command_t * const CommandToken_p,
        const Eip130TokenAssetId_t StateAssetId,
        const Eip130TokenAssetId_t KeyAssetId,
        const uint8_t * const AssociatedData_p,
        const uint16_t AssociatedDataSizeInBytes)
{
    CommandToken_p->W[2] = (Eip130TokenWord_t)StateAssetId;
    CommandToken_p->W[9] = (Eip130TokenWord_t)KeyAssetId; /* Key Encryption Key */

    CommandToken_p->W[3] |= ((Eip130TokenWord_t)AssociatedDataSizeInBytes << 16);
    Eip130Token_Command_WriteByteArray(CommandToken_p, 10U,
                                       AssociatedData_p,
                                       AssociatedDataSizeInBytes);
}


/*----------------------------------------------------------------------------
 * Eip130Token_Result_SystemHibernation_BlobSize
 *
 * ResultToken_p
 *     Pointer to the result token buffer.
 *
 * OutputSizeInBytes_p
 *      Pointer to the variable in which the blob size must be returned.
 */
static inline void
Eip130Token_Result_SystemHibernation_BlobSize(
        const Eip130Token_Result_t * const ResultToken_p,
        uint32_t * const OutputSizeInBytes_p)
{
    *OutputSizeInBytes_p = ResultToken_p->W[1] & MASK_10_BITS;
}
#endif


#endif /* INCLUDE_GUARD_EIP130TOKEN_SYSTEM_H */

/* end of file eip130_token_system.h */

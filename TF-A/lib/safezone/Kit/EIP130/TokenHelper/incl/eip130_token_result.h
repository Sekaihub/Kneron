/* eip130_token_result.h
 *
 * Security Module Token helper result code definitions
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

#ifndef INCLUDE_GUARD_EIP130TOKEN_RESULT_H
#define INCLUDE_GUARD_EIP130TOKEN_RESULT_H

/*----------------------------------------------------------------------------
 * Most common result codes
 */
typedef enum
{
    /** [1 .. 127]: The reserved for propagating the EIP-13x firmware warnings */

    /** TRNG related warnings [64 ... 95]:\n
     * - Aprop fail\n
     * - Repcount fail\n
     * - Stuck NRBG\n
     * - Stuck output */

    /** DMA related warnings [32 ... 63]: None expected */

    /** Firmware related warnings [1 ... 31]: */
    EIP130TOKEN_RESULT_WARNING_Z1USED = 16,         /** Z=1 is used */

    /** Success */
    EIP130TOKEN_RESULT_SUCCESS = 0,                 /** No error */

    /** [-1 .. -127]: The reserved for propagating the EIP-13x firmware error */
    /** Firmware related errors [-1 ... -31]: */
    EIP130TOKEN_RESULT_INVALID_TOKEN = -1,          /** Invalid token */
    EIP130TOKEN_RESULT_INVALID_PARAMETER = -2,      /** Invalid parameter */
    EIP130TOKEN_RESULT_INVALID_KEYSIZE = -3,        /** Invalid key size */
    EIP130TOKEN_RESULT_INVALID_LENGTH = -4,         /** Invalid length */
    EIP130TOKEN_RESULT_INVALID_LOCATION = -5,       /** Invalid location */
    EIP130TOKEN_RESULT_CLOCK_ERROR = -6,            /** Clock error */
    EIP130TOKEN_RESULT_ACCESS_ERROR = -7,           /** Access error */
    EIP130TOKEN_RESULT_UNWRAP_ERROR = -10,          /** Unwrap error */
    EIP130TOKEN_RESULT_DATA_OVERRUN_ERROR = -11,    /** Data overrun error */
    EIP130TOKEN_RESULT_ASSET_CHECKSUM_ERROR = -12,  /** Asset checksum error */
    EIP130TOKEN_RESULT_INVALID_ASSET = -13,         /** Invalid Asset */
    EIP130TOKEN_RESULT_FULL_ERROR = -14,            /** Full/Overflow error */
    EIP130TOKEN_RESULT_INVALID_ADDRESS = -15,       /** Invalid address */
    EIP130TOKEN_RESULT_INVALID_MODULUS = -17,       /** Invalid Modulus */
    EIP130TOKEN_RESULT_VERIFY_ERROR = -18,          /** Verify error */
    EIP130TOKEN_RESULT_INVALID_STATE = -19,         /** Invalid state */
    EIP130TOKEN_RESULT_OTP_WRITE_ERROR = -20,       /** OTP write error */
    EIP130TOKEN_RESULT_ASSET_EXPIRED = -21,         /** Asset Lifetime has expired */
    EIP130TOKEN_RESULT_COPROCESSOR_IF_ERROR = -22,  /** Co-Processor interface error */
    EIP130TOKEN_RESULT_PANIC_ERROR = -31,           /** Panic error */

    /** DMA related errors are bus related [-32 ... -63] */

    /** TRNG related errors [-64 ... -95]: */
    EIP130TOKEN_RESULT_TRNG_SHUTDOWN_ERROR = -65,   /** Too many FROs shutdown */
    EIP130TOKEN_RESULT_DRBG_STUCK_ERROR = -66,      /** Stuck DRBG */
} Eip130Token_Result_Codes_t;


#endif /* INCLUDE_GUARD_EIP130TOKEN_RESULT_H */

/* end of file eip130_token_result.h */

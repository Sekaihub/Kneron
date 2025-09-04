/* sb_result.h
 *
 * Description: Secure Boot API return codes.
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

#ifndef INCLUDE_GUARD_SB_RESULT_H
#define INCLUDE_GUARD_SB_RESULT_H

/**
  Result codes. Error values are returned to the library caller.
 */
typedef enum
{
    SB_SUCCESS,                 /** Returned when a call has been successful. */

    SB_ERROR_ARGUMENTS,         /** Error: illegal arguments to function. */
    SB_ERROR_HARDWARE,          /** Error: Hardware access failure. */
    SB_ERROR_IMAGE_VERSION,     /** Error: Wrong image version. */
    SB_ERROR_IMAGE_TYPE,        /** Error: Unsupported image type. */
    SB_ERROR_VERIFICATION,      /** Error: Signature Verification failed. */
    SB_ERROR_CERTIFICATE_COUNT, /** Error: Unsupported count of certificates. */
    SB_ERROR_POLL,              /** Error: Poll function returned false. */

    SB_ERROR_COUNT              /** Number of return codes. */
}
SB_Result_t;

#endif /* INCLUDE_GUARD_SB_RESULT_H */

/* end of file sb_result.h */

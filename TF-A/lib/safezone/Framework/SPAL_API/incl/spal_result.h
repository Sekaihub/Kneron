/* spal_result.h
 *
 * Description: This header spal_result.h defines enumerated type
 *              SPAL_Resul_t, a common return type for SPAL API functions.
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

#ifndef INCLUDE_GUARD_SPAL_RESULT_H_
#define INCLUDE_GUARD_SPAL_RESULT_H_

#include "public_defs.h"

enum SPAL_ResultCodes
{
    SPAL_SUCCESS,
    SPAL_RESULT_NOMEM,
    SPAL_RESULT_NORESOURCE,
    SPAL_RESULT_LOCKED,
    SPAL_RESULT_INVALID,
    SPAL_RESULT_CANCELED,
    SPAL_RESULT_TIMEOUT,
    SPAL_RESULT_NOTFOUND,
    SPAL_RESULT_COUNT
};

typedef enum SPAL_ResultCodes SPAL_Result_t;

#endif /* Include guard */

/* end of file spal_result.h */

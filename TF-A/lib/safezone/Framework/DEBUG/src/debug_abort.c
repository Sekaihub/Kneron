/* debug_abort.c
 *
 * Description: Implementation of DEBUG_abort.
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

#include "implementation_defs.h"

#include <stdlib.h>
#include <stdio.h>      // fflush, stderr


/* This logic is to make it possible to get coverage reports on
   software runs that end-up (intentionally) to abort. */
#ifdef DEBUG_CF_ABORT_WRITE_PROFILE
void __gcov_flush(void);                    /* Function to write profiles on disk. */
#define DEBUG_ABORT_WRITE_PROFILE __gcov_flush()
#else
#define DEBUG_ABORT_WRITE_PROFILE do { /* Not written. */ } while(0)
#endif


void
DEBUG_abort(void)
{
#ifdef WIN32
    // avoid the "report to microsoft?" dialog and the
    // "your program seems to have stopped abnormally" message
    _set_abort_behavior(0, _WRITE_ABORT_MSG + _CALL_REPORTFAULT);
#endif

    /* flush stderr before calling abort() to make sure
       out is not cut off due to buffering. */
    fflush(stderr);

    DEBUG_ABORT_WRITE_PROFILE;

    abort();
}

/* end of file debug_abort.c */

/* debug_printf.c
 *
 * Description: Implementation of DEBUG_printf.
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

#include <stdarg.h>
#include <stdio.h>

#ifdef DEBUG_CF_USE_STDOUT
#define DEBUG_fd  stdout
#else
#define DEBUG_fd  stderr
#endif

int
DEBUG_printf(const char * format, ...)
{
    va_list ap;

    va_start(ap, format);

    (void)vfprintf(DEBUG_fd, format, ap);

#ifdef DEBUG_CF_USE_FLUSH
    (void)fflush(DEBUG_fd);
#endif

    va_end(ap);

    return 0;
}

/* end of file debug_printf.c */

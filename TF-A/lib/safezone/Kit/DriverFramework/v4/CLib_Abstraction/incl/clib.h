/* clib.h
 *
 * Driver Framework v4, C Library Abstraction
 *
 * This header function guarantees the availability of a select list of
 * Standard C APIs. This makes the user of this API compiler independent.
 * It also gives a single customization point for these functions.
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

#ifndef INCLUDE_GUARD_CLIB_H
#define INCLUDE_GUARD_CLIB_H

#include "c_lib.h"

/* Guaranteed APIs:
     memset
     memcpy
     memcmp
     memmove
     memchr
     strcpy
     strncpy
     strcmp
     strncmp
     strcat
     strlen
     strstr
     strtol
     strchr
     tolower
     toupper
     offsetof
*/

/* Note: This is a template. Copy and customize according to your needs! */

#if defined(linux) && defined(MODULE)

#include <linux/string.h>     // memmove, memcpy, memset, strcmp
#include <linux/stddef.h>     // offsetof

#else

#include <string.h>           // memmove, memset, strcmp
#include <memory.h>           // memcpy, etc.
#include <stddef.h>           // offsetof

#endif

#endif /* INCLUDE_GUARD_CLIB_H */

/* end of file clib.h */

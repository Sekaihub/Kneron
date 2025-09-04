/* c_lib.h
 *
 * Description: Wrappers for C Library functions.
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

#ifndef INCLUDE_GUARD_C_LIB_H
#define INCLUDE_GUARD_C_LIB_H

#include "public_defs.h"

void *
c_memcpy(
    void * restrict s1,
    const void * restrict s2,
    size_t n);

void *
c_memmove(
    void * s1,
    const void * s2,
    size_t n);

void *
c_memset(
    void *s,
    int c,
    size_t n);

int
c_memcmp(
    const void * s1,
    const void * s2,
    size_t n);


int
c_strcmp(
    const char * s1,
    const char * s2);

int
c_strncmp(
    const char * s1,
    const char * s2,
    size_t n);

size_t
c_strlen(
    const char * s);

long
c_strtol(
    const char * str,
    char ** endptr,
    int16_t radix);

char *
c_strchr(
    const char * str,
    int32_t c);

int
c_tolower(
    int c);

int
c_toupper(
    int c);

int *
c_memchr(
    const void * buf,
    int32_t ch,
    size_t num);


/* Zero-init macro
 *
 *   _x (input)
 *   Name of the variable that must be zeroed
 *
 */
#define ZEROINIT(_x)  c_memset(&_x, 0, sizeof(_x))


#endif /* Include guard */

/* end of file c_lib.h */

/* c_lib.c
 *
 * Description: Wrappers for C Library functions
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
#include "clib.h"
#include <stdlib.h>
#include <ctype.h>
#include <safezone.h>

void *
c_memcpy(void * restrict s1,
         const void * restrict s2,
         size_t n)
{
    return wagner_memcpy(s1, s2, n);
}


void *
c_memmove(void * s1,
          const void * s2,
          size_t n)
{
    return memmove(s1, s2, n);
}


void *
c_memset(void * s,
         int c,
         size_t n)
{
    return memset(s, c, n);
}


int
c_memcmp(const void * s1,
         const void * s2,
         size_t n)
{
    return memcmp(s1, s2, n);
}


int
c_strcmp(const char * s1,
         const char * s2)
{
    return strcmp(s1, s2);
}


int
c_strncmp(const char * s1,
          const char * s2,
          size_t n)
{
    return strncmp(s1, s2, n);
}


size_t
c_strlen(const char * s)
{
    return strlen(s);
}


long
c_strtol(const char * str,
         char ** endptr,
         int16_t radix)
{
    return strtol(str, endptr, radix);
}


char *
c_strchr(const char * str,
         int32_t c)
{
    return strchr(str, c);
}


int
c_tolower(int c)
{
    return tolower(c);
}


int
c_toupper(int c)
{
    return toupper(c);
}


int *
c_memchr(const void * buf,
         int32_t ch,
         size_t num)
{
    return memchr(buf, ch, num);
}


/* end of file c_lib.c */

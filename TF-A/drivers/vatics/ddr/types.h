/*
 * Very simple but very effective user-space memory tester.
 * Originally by Simon Kirby <sim@stormix.com> <sim@neato.org>
 * Version 2 by Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Version 3 not publicly released.
 * Version 4 rewrite:
 * Copyright (C) 2004-2010 Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Licensed under the terms of the GNU General Public License version 2 (only).
 * See the file COPYING for details.
 *
 * This file contains typedefs, structure, and union definitions.
 *
 */

#include "sizes.h"

typedef unsigned long ul;
typedef unsigned long long ull;
typedef unsigned long volatile ulv;
typedef unsigned char volatile u8v;
typedef unsigned short volatile u16v;
typedef unsigned int   volatile u32v;
typedef unsigned long  volatile u64v;

struct test {
    char *name;
    int (*fp)();
};

typedef union {
    unsigned char bytes[UL_LEN/8];
    ul val;
}mw8;

typedef union {
    unsigned short u16s[UL_LEN/16];
    ul val;
}mw16;

typedef union {
    unsigned int u32s[UL_LEN/32];
    ul val;
}mw32;

typedef union {
    unsigned long u64s[UL_LEN/64];
    ul val;
}mw64;

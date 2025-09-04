/*
 * Very simple but very effective user-space memory tester.
 * Originally by Simon Kirby <sim@stormix.com> <sim@neato.org>
 * Version 2 by Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Version 3 not publicly released.
 * Version 4 rewrite:
 * Copyright (C) 2004-2012 Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Licensed under the terms of the GNU General Public License version 2 (only).
 * See the file COPYING for details.
 *
 * This file contains the functions for the actual tests, called from the
 * main routine in memtester.c.  See other comments in that file.
 *
 */

#include <../../../include/linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "types.h"
#include "sizes.h"
#include "memtester.h"

char progress[] = "-\\|/";
#define PROGRESSLEN 4
#define PROGRESSOFTEN 2500
#define ONE 0x00000001L

mw8  mword8;
mw16 mword16;
mw32 mword32;

/* Function definitions. */

int compare_regions(ulv *bufa, ulv *bufb, size_t count) {
    int r = 0;
    size_t i;
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    u32v physaddr;

    for (i = 0; i < count; i++, p1++, p2++) {
        if (*p1 != *p2) {
            if (use_phys) {
                physaddr = physaddrbase + (i * sizeof(ul));
                printf( 
                        "FAILURE: 0x%08lx(@%p) != 0x%08lx(@%p) at physical address "
                        "0x%08x.\n", 
                        (ul) *p1, p1, (ul) *p2, p2, physaddr);
            } else {
                printf( 
                        "FAILURE: 0x%08lx != 0x%08lx at offset 0x%08lx.\n", 
                        (ul) *p1, (ul) *p2, (ul) (i * sizeof(ul)));
            }
            /* printf("Skipping to next test..."); */
            r = -1;
        }
    }
    return r;
}

int test_stuck_address(ulv *bufa, size_t count) {
    ulv *p1 = bufa;
    unsigned int j;
    size_t i;
    u32v physaddr;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < 16; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        printf("setting %3u", j);
        // fflush(stdout);
        for (i = 0; i < count; i++) {
            *p1 = ((j + i) % 2) == 0 ? (ul) p1 : ~((ul) p1);
            *p1++;
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        p1 = (ulv *) bufa;
        for (i = 0; i < count; i++, p1++) {
            if (*p1 != (((j + i) % 2) == 0 ? (ul) p1 : ~((ul) p1))) {
                if (use_phys) {
                    physaddr = physaddrbase + (i * sizeof(ul));
                    printf(
                            "FAILURE: possible bad address line at physical "
                            "address 0x%08x.\n", 
                            physaddr);
                } else {
                    printf(
                            "FAILURE: possible bad address line at offset "
                            "0x%08lx.\n", 
                            (ul) (i * sizeof(ul)));
                }
                printf( "(i,j)=(%ld,%d) Data 0x%08lx != Golden 0x%08lx\n", i, j,
				(ul)*p1, ((j + i) % 2) == 0 ? (ul) p1 : ~((ul) p1));
                printf("Skipping to next test...\n");
                // fflush(stdout);
                return -1;
            }
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int test_random_value(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    ul j = 0;
    size_t i;

    putchar(' ');
    // fflush(stdout);
    for (i = 0; i < count; i++) {
        *p1++ = *p2++ = rand_ul();
        if (!(i % PROGRESSOFTEN)) {
            //putchar('\b');
            putchar(progress[++j % PROGRESSLEN]);
            // fflush(stdout);
        }
    }
    //printf("\b \b");
    // fflush(stdout);
    return compare_regions(bufa, bufb, count);
}

int test_xor_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ ^= q;
        *p2++ ^= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_sub_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ -= q;
        *p2++ -= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_mul_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ *= q;
        *p2++ *= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_div_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        if (!q) {
            q++;
        }
        *p1++ /= q;
        *p2++ /= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_or_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ |= q;
        *p2++ |= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_and_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ &= q;
        *p2++ &= q;
    }
    return compare_regions(bufa, bufb, count);
}

int compare_regions_seqinc(ulv *bufa, ulv *bufb, size_t count, ul q) {
    int r = 0;
    size_t i;
    ulv *p1 = bufa;
    ulv *p2 = bufb;

    for (i = 0; i < count; i++, p1++, p2++) {
        if (*p1 != i + q || *p2 != i + q) {
            printf(
                        "FAILURE: 0x%08lx(@%p) != 0x%08lx(@%p), Golden: %08lx",
                        (unsigned long) *p1, p1, (unsigned long) *p2, p2, i + q);
            /* printf("Skipping to next test..."); */
            r = -1;
        }
    }
    return r;
}

int test_seqinc_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ = *p2++ = (i + q);
    }
    return compare_regions_seqinc(bufa, bufb, count, q);
}

int compare_regions_solidbits(ulv *bufa, ulv *bufb, size_t count, ul q) {
    int r = 0;
    size_t i;
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    register ul g;

    for (i = 0; i < count; i++, p1++, p2++) {
        g = (i % 2 == 0 ? q : ~q);
        if (*p1 != g || *p2 != g) {
            printf(
                        "FAILURE: 0x%08lx(@%p) != 0x%08lx(@%p), Golden: 0x%08lx\n",
                        (unsigned long) *p1, p1, (unsigned long) *p2, p2, g);
            /* printf("Skipping to next test..."); */
            r = -1;
        }
    }
    return r;
}

int test_solidbits_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    ul q;
    size_t i;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < 64; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        q = (j % 2) == 0 ? UL_ONEBITS : 0;
        printf("setting %3u", j);
        // fflush(stdout);
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = (i % 2) == 0 ? q : ~q;
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        if (compare_regions_solidbits(bufa, bufb, count, q)) {
            return -1;
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int test_checkerboard_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    ul q;
    size_t i;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < 64; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        q = (j % 2) == 0 ? CHECKERBOARD1 : CHECKERBOARD2;
        printf("setting %3u", j);
        // fflush(stdout);
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = (i % 2) == 0 ? q : ~q;
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        if (compare_regions_solidbits(bufa, bufb, count, q)) {
            return -1;
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int compare_regions_blockseq(ulv *bufa, ulv *bufb, size_t count, ul pattern) {
    int r = 0;
    size_t i;
    ulv *p1 = bufa;
    ulv *p2 = bufb;

    for (i = 0; i < count; i++, p1++, p2++) {
        if (*p1 != pattern || *p2 != pattern) {
            printf(
                        "FAILURE: 0x%08lx(@%p) != 0x%08lx(@%p), Golden: 0x%08lx\n",
                        (unsigned long) *p1, p1, (unsigned long) *p2, p2, pattern);
            /* printf("Skipping to next test..."); */
            r = -1;
        }
    }
    return r;
}

int test_blockseq_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < 256; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        // fflush(stdout);
        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = (ul) UL_BYTE(j);
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        if (compare_regions_blockseq(bufa, bufb, count, UL_BYTE(j))) {
            return -1;
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int test_walkbits0_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;
    ul g = 0;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < UL_LEN * 2; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        // fflush(stdout);
        for (i = 0; i < count; i++) {
            if (j < UL_LEN) { /* Walk it up. */
                *p1++ = *p2++ = (g = (ONE << j));
            } else { /* Walk it back down. */
                *p1++ = *p2++ = (g = (ONE << (UL_LEN * 2 - j - 1)));
            }
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        if (compare_regions_blockseq(bufa, bufb, count, g)) {
            return -1;
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int test_walkbits1_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;
    ul g = 0;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < UL_LEN * 2; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        // fflush(stdout);
        for (i = 0; i < count; i++) {
            if (j < UL_LEN) { /* Walk it up. */
                *p1++ = *p2++ = (g = (UL_ONEBITS ^ (ONE << j)));
            } else { /* Walk it back down. */
                *p1++ = *p2++ = (g = (UL_ONEBITS ^ (ONE << (UL_LEN * 2 - j - 1))));
            }
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        if (compare_regions_blockseq(bufa, bufb, count, g)) {
            return -1;
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int compare_regions_bitspread(ulv *bufa, ulv *bufb, size_t count, ul g0, ul g1) {
    int r = 0;
    size_t i;
    ulv *p1 = bufa;
    ulv *p2 = bufb;

    for (i = 0; i < count; i++, p1++, p2++) {
        if ((*p1 != (i % 2 == 0 ? g0 : g1)) || (*p2 != (i % 2 == 0 ? g0 : g1))) {
            printf(
                        "FAILURE: 0x%08lx(@%p) != 0x%08lx(@%p), Golden: 0x%08lx\n",
                        (unsigned long) *p1, p1, (unsigned long) *p2, p2, (i % 2 == 0) ? g0 : g1);
            /* printf("Skipping to next test..."); */
            r = -1;
        }
    }
    return r;
}
int test_bitspread_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;
    ul g0 = 0, g1 = 0;

    printf("           ");
    // fflush(stdout);
    for (j = 0; j < UL_LEN * 2; j++) {
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        // fflush(stdout);
        for (i = 0; i < count; i++) {
            if (j < UL_LEN) { /* Walk it up. */
                *p1++ = *p2++ = (i % 2 == 0)
                    ? (g0 = (ONE << j) | (ONE << (j + 2)))
                    : (g1 = (UL_ONEBITS ^ ((ONE << j)
                                    | (ONE << (j + 2)))));
            } else { /* Walk it back down. */
                *p1++ = *p2++ = (i % 2 == 0)
                    ? (g0 = (ONE << (UL_LEN * 2 - 1 - j)) | (ONE << (UL_LEN * 2 + 1 - j)))
                    : (g1 = (UL_ONEBITS ^ (ONE << (UL_LEN * 2 - 1 - j)
                                    | (ONE << (UL_LEN * 2 + 1 - j)))));
            }
        }
        //printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        // fflush(stdout);
        if (compare_regions_bitspread(bufa, bufb, count, g0, g1)) {
            return -1;
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

int test_bitflip_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j, k;
    ul q;
    size_t i;

    printf("           ");
    // fflush(stdout);
    for (k = 0; k < UL_LEN; k++) {
        q = ONE << k;
        for (j = 0; j < 8; j++) {
            //printf("\b\b\b\b\b\b\b\b\b\b\b");
            q = ~q;
            printf("setting %3u", k * 8 + j);
            // fflush(stdout);
            p1 = (ulv *) bufa;
            p2 = (ulv *) bufb;
            for (i = 0; i < count; i++) {
                *p1++ = *p2++ = (i % 2) == 0 ? q : ~q;
            }
            //printf("\b\b\b\b\b\b\b\b\b\b\b");
            printf("testing %3u", k * 8 + j);
            // fflush(stdout);
            if (compare_regions_bitspread(bufa, bufb, count, q, ~q)) {
                return -1;
            }
        }
    }
    //printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    // fflush(stdout);
    return 0;
}

#ifdef TEST_NARROW_WRITES    
int test_8bit_wide_random(ulv* bufa, ulv* bufb, size_t count) {
    u8v *p1, *t;
    ulv *p2;
    int attempt;
    unsigned int b, j = 0;
    size_t i;

    putchar(' ');
    // fflush(stdout);
    for (attempt = 0; attempt < 2;  attempt++) {
        if (attempt & 1) {
            p1 = (u8v *) bufa;
            p2 = bufb;
        } else {
            p1 = (u8v *) bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword8.bytes;
            *p2++ = mword8.val = rand_ul();
            for (b=0; b < UL_LEN/8; b++) {
                *p1++ = *t++;
            }
            if (!(i % PROGRESSOFTEN)) {
                //putchar('\b');
                putchar(progress[++j % PROGRESSLEN]);
                // fflush(stdout);
            }
        }
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    //printf("\b \b");
    // fflush(stdout);
    return 0;
}

int test_16bit_wide_random(ulv* bufa, ulv* bufb, size_t count) {
    u16v *p1, *t;
    ulv *p2;
    int attempt;
    unsigned int b, j = 0;
    size_t i;

    putchar( ' ' );
    fflush( stdout );
    for (attempt = 0; attempt < 2; attempt++) {
        if (attempt & 1) {
            p1 = (u16v *) bufa;
            p2 = bufb;
        } else {
            p1 = (u16v *) bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword16.u16s;
            *p2++ = mword16.val = rand_ul();
            for (b = 0; b < UL_LEN/16; b++) {
                *p1++ = *t++;
            }
            if (!(i % PROGRESSOFTEN)) {
                //putchar('\b');
                putchar(progress[++j % PROGRESSLEN]);
                // fflush(stdout);
            }
        }
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    //printf("\b \b");
    // fflush(stdout);
    return 0;
}

int test_32bit_wide_random(ulv* bufa, ulv* bufb, size_t count) {
    u32v *p1, *t;
    ulv *p2;
    int attempt;
    unsigned int b, j = 0;
    size_t i;

    putchar( ' ' );
    fflush( stdout );
    for (attempt = 0; attempt < 2; attempt++) {
        if (attempt & 1) {
            p1 = (u32v *) bufa;
            p2 = bufb;
        } else {
            p1 = (u32v *) bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword32.u32s;
            *p2++ = mword32.val = rand_ul();
            for (b = 0; b < UL_LEN/32; b++) {
                *p1++ = *t++;
            }
            if (!(i % PROGRESSOFTEN)) {
                //putchar('\b');
                putchar(progress[++j % PROGRESSLEN]);
                // fflush(stdout);
            }
        }
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    //printf("\b \b");
    // fflush(stdout);
    return 0;
}
#endif

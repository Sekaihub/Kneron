/* endian_utils.h
 *
 * Description: endian conversion helper functions.
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

#ifndef INCLUDE_GUARD_ENDIAN_UTILS_H
#define INCLUDE_GUARD_ENDIAN_UTILS_H

/* This file defines following byte order manipulation macros

   Macro name              Result    Param     Effect
   --------------------    ------    -----     ------
   BYTEORDER_SWAP32        uint32_t  uint32_t  Swaps byte order of
                                               input 32-bit value
   BYTEORDER_SWAP16        uint16_t  uint16_t  Swaps byte-order of
                                               input 16-bit value
   CPU_TO_BE32             uint32_t  uint32_t  Converts 32-bit value from CPU
                                               byte-order to big endian
   CPU_TO_LE32             uint32_t  uint32_t  Converts 32-bit value from CPU
                                               byte-order to little endian
   BE32_TO_CPU             uint32_t  uint32_t  Converts 32-bit big endian
                                               value to CPU byte-order
   LE32_TO_CPU             uint32_t  uint32_t  Converts 32-bit little endian
                                               value to CPU byte-order
   CPU_TO_BE16             uint16_t  uint16_t  Converts 16-bit value from CPU
                                               byte-order to big endian
   CPU_TO_LE16             uint16_t  uint16_t  Converts 16-bit value from CPU
                                               byte-order to little endian
   BE16_TO_CPU             uint16_t  uint16_t  Converts 16-bit big endian
                                               value to CPU byte-order
   LE16_TO_CPU             uint16_t  uint16_t  Converts 16-bit little endian
                                               value to CPU byte-order

   Also, following macros are defined for loading 32-bit or 16-bit values from
   memory, in various byte orders:

   Macro name              Result    Param     Effect
   --------------------    ------    -----     ------
   BE32_READ_ALIGNED       uint32_t  pointer   Read big endian value from
                                               aligned memory location.
   BE32_READ               uint32_t  pointer   Read big endian value from
                                               any memory location.
   LE32_READ_ALIGNED       uint32_t  pointer   Read little endian value from
                                               aligned memory location.
   LE32_READ               uint32_t  pointer   Read little endian value from
                                               any memory location.
   CPU32_READ              uint32_t  pointer   Read 32-bit value from any
                                               memory location.
   BE16_READ_ALIGNED       uint16_t  pointer   Read big endian value from
                                               aligned memory location.
   BE16_READ               uint16_t  pointer   Read big endian value from
                                               any memory location.
   LE16_READ_ALIGNED       uint16_t  pointer   Read little endian value from
                                               aligned memory location.
   LE16_READ               uint16_t  pointer   Read little endian value from
                                               any memory location.
   CPU16_READ              uint16_t  pointer   Read 16-bit value from any
                                               memory location.

   Also, following macros are provided for storing values to memory
   (either aligned or unaligned addresses):

   Macro name               Param1   Param2    Effect
   --------------------     ------   ------    ------
   BE32_WRITE_ALIGNED       pointer  uint32_t  Write big endian value from
                                               aligned memory location.
   BE32_WRITE               pointer  uint32_t  Write big endian value from
                                               any memory location.
   LE32_WRITE_ALIGNED       pointer  uint32_t  Write little endian value from
                                               aligned memory location.
   LE32_WRITE               pointer  uint32_t  Write little endian value from
                                               any memory location.
   CPU32_WRITE              pointer  uint32_t  Write 32-bit value from any
                                               memory location.
   BE16_WRITE_ALIGNED       pointer  uint16_t  Write big endian value from
                                               aligned memory location.
   BE16_WRITE               pointer  uint16_t  Write big endian value from
                                               any memory location.
   LE16_WRITE_ALIGNED       pointer  uint16_t  Write little endian value from
                                               aligned memory location.
   LE16_WRITE               pointer  uint16_t  Write little endian value from
                                               any memory location.
   CPU16_WRITE              pointer  uint16_t  Write 16-bit value from any
                                               memory location.

   Following macros are provided for constants
   Macro name                       Result    Param     Effect
   --------------------             ------    -----     ------
   BYTEORDER_SWAP32_CONSTANT        uint32_t  uint32_t  Swaps byte order of
                                                        input 32-bit constant
                                                        value
   BYTEORDER_SWAP16_CONSTANT        uint16_t  uint16_t  Swaps byte-order of
                                                        input 16-bit constant
                                                        value
   CPU_TO_BE32_CONSTANT             uint32_t  uint32_t  Converts 32-bit
                                                        constant value from CPU
                                                        byte-order to
                                                        big endian byte-order.
   CPU_TO_LE32_CONSTANT             uint32_t  uint32_t  Converts 32-bit
                                                        constant value from CPU
                                                        byte-order to
                                                        little endian
   CPU_TO_BE16_CONSTANT             uint16_t  uint16_t  Converts 16-bit
                                                        constant value from CPU
                                                        byte-order to
                                                        big endian byte-order.
   CPU_TO_LE16_CONSTANT             uint16_t  uint16_t  Converts 16-bit
                                                        constant value from CPU
                                                        byte-order to
                                                        little endian
*/

#include "cf_sb.h"
#include "implementation_defs.h"

/* Macro for byte order swapping. The macro might be overridden with
   platform specific assembly instruction. */
#ifndef BYTEORDER_SWAP32
#define BYTEORDER_SWAP32(x) \
   (((x) << 24) | \
   (((x) & 0x0000ff00U) << 8) | \
   (((x) & 0x00ff0000U) >> 8) | \
   ((x) >> 24))
#endif /* BYTEORDER_SWAP32 */

/* Similar macro for half-word entities. */
#ifndef BYTEORDER_SWAP16
#define BYTEORDER_SWAP16(x) ((uint16_t)(((x) << 8) | ((x) >> 8)))
#endif /* BYTEORDER_SWAP16 */

#ifdef SB_CF_BIGENDIAN
/* Define word / byte conversion macros for big endian. */
#define CPU_TO_BE32(x) (x)
#define CPU_TO_LE32(x) BYTEORDER_SWAP32(x)
#define BE32_TO_CPU(x) (x)
#define LE32_TO_CPU(x) BYTEORDER_SWAP32(x)

#define CPU_TO_BE16(x) (x)
#define CPU_TO_LE16(x) BYTEORDER_SWAP16(x)
#define BE16_TO_CPU(x) (x)
#define LE16_TO_CPU(x) BYTEORDER_SWAP16(x)
#elif defined(SB_CF_LITTLEENDIAN)
/* Define word / byte conversion macros for little endian. */

#define CPU_TO_BE32(x) BYTEORDER_SWAP32(x)
#define CPU_TO_LE32(x) (x)
#define BE32_TO_CPU(x) BYTEORDER_SWAP32(x)
#define LE32_TO_CPU(x) (x)

#define CPU_TO_BE16(x) BYTEORDER_SWAP16(x)
#define CPU_TO_LE16(x) (x)
#define BE16_TO_CPU(x) BYTEORDER_SWAP16(x)
#define LE16_TO_CPU(x) (x)
#else
/* Endian is not specified or endian is not big-endian or little-endian. */
#error "Endianness must be specified via SB_CF_BIGENDIAN or SB_CF_LITTLEENDIAN."
#endif /* choose code according to endianness */

/* Macros for reading 32-bit or 16-bit values in specified byte-order. */
#define LE32_READ_ALIGNED(x) LE32_TO_CPU(*(const uint32_t * const)(const void * const)(x))
#define LE16_READ_ALIGNED(x) LE16_TO_CPU(*(const uint16_t * const)(const void * const)(x))
#define BE32_READ_ALIGNED(x) BE32_TO_CPU(*(const uint32_t * const)(const void * const)(x))
#define BE16_READ_ALIGNED(x) BE16_TO_CPU(*(const uint16_t * const)(const void * const)(x))

/* Macros for writing 32-bit or 16-bit values in specified byte-order. */
#define LE32_WRITE_ALIGNED(x, y) \
    *(uint32_t *)(void *)(x) = CPU_TO_LE32(y)
#define LE16_WRITE_ALIGNED(x, y) \
    *(uint16_t *)(void *)(x) = CPU_TO_LE16(y)
#define BE32_WRITE_ALIGNED(x, y) \
    *(uint32_t *)(void *)(x) = CPU_TO_BE32(y)
#define BE16_WRITE_ALIGNED(x, y) \
    *(uint16_t *)(void *)(x) = CPU_TO_BE16(y)

#if !defined(FORCE_ALIGNED_ACCESS) && \
    (defined(UNALIGNED_ACCESS) || \
     defined(__i386__) || defined(__x86_64__))
/* These architectures support unaligned access and therefore aligned
   reads/writes can be directly used for accessing unaligned values. */
#define LE32_READ  LE32_READ_ALIGNED
#define LE16_READ  LE16_READ_ALIGNED
#define BE32_READ  BE32_READ_ALIGNED
#define BE16_READ  BE16_READ_ALIGNED
#define LE32_WRITE LE32_WRITE_ALIGNED
#define LE16_WRITE LE16_WRITE_ALIGNED
#define BE32_WRITE BE32_WRITE_ALIGNED
#define BE16_WRITE BE16_WRITE_ALIGNED

#ifndef CPU32_READ
#ifdef SB_CF_BIGENDIAN
#define CPU32_READ  BE32_READ_ALIGNED
#define CPU32_WRITE BE32_WRITE_ALIGNED
#else
#define CPU32_READ  LE32_READ_ALIGNED
#define CPU32_WRITE LE32_WRITE_ALIGNED
#endif
#endif /* CPU32_READ */

#ifndef CPU16_READ
#ifdef SB_CF_BIGENDIAN
#define CPU16_READ  BE16_READ_ALIGNED
#define CPU16_WRITE BE16_WRITE_ALIGNED
#else
#define CPU16_READ  LE16_READ_ALIGNED
#define CPU16_WRITE LE16_WRITE_ALIGNED
#endif
#endif /* CPU16_READ */

#else /* Unaligned access not available. */

#ifndef CPU32_READ
/* Macro for reading unaligned 32-bit value. */

/* Implemented as inline function: */
static inline uint32_t
cpu32_read(const void * const ptr)
{
    uintptr_t ptrInt;
    uintptr_t ptrLow;
    uintptr_t ptrHi;
    uintptr_t ptrDiff;
    uintptr_t ptrDiffRev;
    uint32_t valueLow;
    uint32_t valueHi;

    ptrInt = (uintptr_t)ptr;
    ptrLow = ptrInt & (uintptr_t)~3;
    ptrHi = (ptrInt + 3) & (uintptr_t)~3;

    ptrDiff = (ptrInt - ptrLow) * 8;
    valueLow = *(uint32_t *)ptrLow;
    valueHi = *(uint32_t *)ptrHi;

    /* Following table describes contents of valueLow and valueHi and
       desired output value:
       (big endian)
       valueLow valueHi  ptrDiff valueOut
       IIJJKKLL IIJJKKLL 0       IIJJKKLL
       IIJJKKLL MMNNOOPP 8       JJKKLLMM
       IIJJKKLL MMNNOOPP 16      KKLLMMNN
       IIJJKKLL MMNNOOPP 24      LLMMNNOO

       (little endian)
       LLKKJJII LLKKJJII 0       LLKKJJII
       LLKKJJII PPOONNMM 8       MMLLKKJJ
       LLKKJJII PPOONNMM 16      NNMMLLKK
       LLKKJJII PPOONNMM 24      OONNMMLL
     */

    ptrDiffRev = (32 - ptrDiff) & 31;
#ifdef SB_CF_BIGENDIAN
    /* Suitable shifting for big endian. */
    return (valueLow << ptrDiff) | (valueHi >> ptrDiffRev);
#else
    /* Little endian. */
    return (valueLow >> ptrDiff) | (valueHi << ptrDiffRev);
#endif /* choose code according to endianness */
}
#define CPU32_READ(x) cpu32_read(x)
#endif /* CPU32_READ */

#ifndef BE32_WRITE
static inline void be32_write(void * const Value_p,
                              const uint32_t NewValue)
{
    uint8_t * const Value8_p = (uint8_t *) Value_p;
    Value8_p[0] = (uint8_t)(NewValue >> 24);
    Value8_p[1] = (uint8_t)(NewValue >> 16);
    Value8_p[2] = (uint8_t)(NewValue >>  8);
    Value8_p[3] = (uint8_t)(NewValue >>  0);
}
#define BE32_WRITE(x, y) be32_write(x, y)
#endif /* BE32_WRITE */

#ifndef LE32_WRITE
static inline void le32_write(void * const Value_p,
                              const uint32_t NewValue)
{
    uint8_t * const Value8_p = (uint8_t *) Value_p;
    Value8_p[3] = (uint8_t)(NewValue >> 24);
    Value8_p[2] = (uint8_t)(NewValue >> 16);
    Value8_p[1] = (uint8_t)(NewValue >>  8);
    Value8_p[0] = (uint8_t)(NewValue >>  0);
}
#define LE32_WRITE(x, y) le32_write(x, y)
#endif /* LE32_WRITE */

#ifndef CPU32_WRITE
#ifdef SB_CF_BIGENDIAN
#define CPU32_WRITE BE32_WRITE
#else
#define CPU32_WRITE LE32_WRITE
#endif
#endif /* CPU32_WRITE */

#ifdef SB_CF_BIGENDIAN
/* Big endian: derive ?E32_READ from CPU32_READ */
#ifndef BE32_READ
#define BE32_READ CPU32_READ
#endif
#ifndef LE32_READ
#define LE32_READ(x) BYTEORDER_SWAP32(CPU32_READ(x))
#endif
#else
/* Little endian: derive ?E32_READ from CPU32_READ */
#ifndef LE32_READ
#define LE32_READ CPU32_READ
#endif
#ifndef BE32_READ
#define BE32_READ(x) BYTEORDER_SWAP32(CPU32_READ(x))
#endif
#endif /* SB_CF_BIGENDIAN */

#ifndef LE16_READ
#define LE16_READ(x) \
    ((*(uint8_t *)(x)) | (((uint16_t)(((uint8_t *)x)[1])) << 8))
#endif /* LE16_READ*/

#ifndef BE16_READ
#define BE16_READ(x) \
    ((((uint16_t)(*(uint8_t *)(x))) << 8) | (((uint8_t *)x)[1]))
#endif /* BE16_READ*/

#ifndef CPU16_READ
#ifdef SB_CF_BIGENDIAN
#define CPU16_READ BE16_READ
#else
#define CPU16_READ LE16_READ
#endif
#endif /* CPU16_READ */

#ifndef BE16_WRITE
static inline void be16_write(void * const Value_p,
                              const uint16_t NewValue)
{
    uint8_t * const Value8_p = (uint8_t *) Value_p;
    Value8_p[0] = (uint8_t)(NewValue >> 8);
    Value8_p[1] = (uint8_t)(NewValue >> 0);
}
#define BE16_WRITE(x, y) be16_write(x, y)
#endif /* BE16_WRITE */

#ifndef LE16_WRITE
static inline void le16_write(void * const Value_p,
                              const uint16_t NewValue)
{
    uint8_t * const Value8_p = (uint8_t *) Value_p;
    Value8_p[1] = (uint8_t)(NewValue >> 8);
    Value8_p[0] = (uint8_t)(NewValue >> 0);
}
#define LE16_WRITE(x, y) le16_write(x, y)
#endif /* LE16_WRITE */

#ifndef CPU16_WRITE
#ifdef SB_CF_BIGENDIAN
#define CPU16_WRITE BE16_WRITE
#else
#define CPU16_WRITE LE16_WRITE
#endif
#endif /* CPU16_WRITE */

#endif /* unaligned access */

/* Macro for byte order swapping of constant values.
   Reason for having separate macro for constant values is that C compilers
   are able to perform these calculations during compilation time for
   constants. */
#define BYTEORDER_SWAP32_CONSTANT(x) \
  (((x) << 24) | \
   (((x) & 0x0000ff00U) << 8) | \
   (((x) & 0x00ff0000U) >> 8) | \
   ((x) >> 24))

/* Similar macro for half-word entities. */
#define BYTEORDER_SWAP16_CONSTANT(x) \
  ((uint16_t) (((x) << 8) | ((x) >> 8)))

#ifdef SB_CF_BIGENDIAN
/* Define word / byte conversion macros for big endian, constants. */

#define CPU_TO_BE32_CONSTANT(x) (x)
#define CPU_TO_LE32_CONSTANT(x) BYTEORDER_SWAP32_CONSTANT(x)
#define BE32_TO_CPU_CONSTANT(x) (x)
#define LE32_TO_CPU_CONSTANT(x) BYTEORDER_SWAP32_CONSTANT(x)

#define CPU_TO_BE16_CONSTANT(x) (x)
#define CPU_TO_LE16_CONSTANT(x) BYTEORDER_SWAP16_CONSTANT(x)
#define BE16_TO_CPU_CONSTANT(x) (x)
#define LE16_TO_CPU_CONSTANT(x) BYTEORDER_SWAP16_CONSTANT(x)
#else
/* Define word / byte conversion macros for little endian, constants. */

#define CPU_TO_LE32_CONSTANT(x) (x)
#define CPU_TO_BE32_CONSTANT(x) BYTEORDER_SWAP32_CONSTANT(x)
#define LE32_TO_CPU_CONSTANT(x) (x)
#define BE32_TO_CPU_CONSTANT(x) BYTEORDER_SWAP32_CONSTANT(x)

#define CPU_TO_LE16_CONSTANT(x) (x)
#define CPU_TO_BE16_CONSTANT(x) BYTEORDER_SWAP16_CONSTANT(x)
#define LE16_TO_CPU_CONSTANT(x) (x)
#define BE16_TO_CPU_CONSTANT(x) BYTEORDER_SWAP16_CONSTANT(x)
#endif

static inline uint32_t
Load_BE32(const void * const Value_p)
{
    return BE32_READ((const uint8_t * const)Value_p);
}

static inline void
Store_BE32(uint32_t * const Value_p,
           const uint32_t NewValue)
{
    BE32_WRITE(Value_p, NewValue);
}

#endif /* INCLUDE_GUARD_ENDIAN_UTILS_H */

/* end of file endian_utils.h */

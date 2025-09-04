/* uECC configuration for Rambus Cryptographic libraries. */

#ifndef uECC_CONFIG
#define uECC_CONFIG 1

#include "cf_sb.h"
// #include "pscompilerdep.h"

/* Omit features not needed. */
#define uECC_SUPPORTS_secp160r1 0
#define uECC_SUPPORTS_secp256k1 0
#define uECC_SUPPORT_COMPRESSED_POINT 0

/* Extensions for uECC. */
#ifndef uECC_SUPPORTS_secp384r1
    #define uECC_SUPPORTS_secp384r1 0
#endif
#ifndef uECC_SUPPORTS_secp521r1
    #define uECC_SUPPORTS_secp521r1 0
#endif

/* Optimize performance. */
#ifndef __ARMCC5
#define uECC_OPTIMIZATION_LEVEL 4
#else
/* ARMCC is not compatible with GNU inline assembly.
   Compile without inline assembly. */
#define uECC_OPTIMIZATION_LEVEL 4
#define uECC_PLATFORM uECC_arch_other /* Omit ARM optimizations. */
#endif
#define uECC_SQUARE_FUNC 1

/* Follow general Secure Boot endianness settings. */
#ifndef uECC_VLI_NATIVE_LITTLE_ENDIAN
#ifdef SB_CF_BIGENDIAN
#define uECC_VLI_NATIVE_LITTLE_ENDIAN 0
#else
#define uECC_VLI_NATIVE_LITTLE_ENDIAN 1
#endif
#endif

#endif /* uECC_CONFIG */

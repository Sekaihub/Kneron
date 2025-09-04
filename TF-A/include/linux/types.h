#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <inttypes.h>
#include <stdint.h>
#include <linux/compiler.h>
#include <linux/kernel.h>
#include <platform_def.h>

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;

typedef __u8 u8;
typedef __u16 u16;
typedef __u32 u32;
typedef __u64 u64;

typedef __u32 uint;
/*
 * Below are truly Linux-specific types that should never collide with
 * any application/library that wants linux/types.h.
 */
#ifdef __CHECKER__
#define __bitwise__ __attribute__((bitwise))
#else
#define __bitwise__
#endif
#ifdef __CHECK_ENDIAN__
#define __bitwise __bitwise__
#else
#define __bitwise
#endif

typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;

#if defined(__GNUC__)
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;
#endif
typedef __u16 __bitwise __sum16;
typedef __u32 __bitwise __wsum;

typedef unsigned __bitwise__	gfp_t;


/*
 * A dma_addr_t can hold any valid DMA address, i.e., any address returned
 * by the DMA API.
 *
 * If the DMA API only uses 32-bit addresses, dma_addr_t need only be 32
 * bits wide.  Bus addresses, e.g., PCI BARs, may be wider than 32 bits,
 * but drivers do memory-mapped I/O to ioremapped kernel virtual addresses,
 * so they don't care about the size of the actual bus addresses.
 */
#ifdef CONFIG_DMA_ADDR_T_64BIT
typedef unsigned long long dma_addr_t;
#else
typedef u32 dma_addr_t;
#endif

// bitmap
#define BITS_PER_BYTE		8
#define BITS_TO_LONGS(nr)	DIV_ROUND_UP_2EVAL(nr, BITS_PER_BYTE * sizeof(long))
#define DECLARE_BITMAP(name, bits) \
	unsigned long name[BITS_TO_LONGS(bits)]
#define small_const_nbits(nbits) \
	        (__builtin_constant_p(nbits) && (nbits) <= BITS_PER_LONG)
#define BIT_MASK(nr)	(1UL << ((nr) % BITS_PER_LONG))
#define BIT_WORD(nr)	((nr) / BITS_PER_LONG)

static inline void bitmap_zero(unsigned long *dst, int nbits)
{
	if (small_const_nbits(nbits)) {
			*dst = 0UL;
	} else {
		int len = BITS_TO_LONGS(nbits) * sizeof(unsigned long);

		memset(dst, 0, len);
	}
}

/**
 * __set_bit - Set a bit in memory
 * @nr: the bit to set
 * @addr: the address to start counting from
 *
 * Unlike set_bit(), this function is non-atomic and may be reordered.
 * If it's called on the same region of memory simultaneously, the effect
 * may be that only one operation succeeds.
 */
static inline void generic_set_bit(int nr, volatile unsigned long *addr)
{
	unsigned long mask = BIT_MASK(nr);
	unsigned long *p = ((unsigned long *)addr) + BIT_WORD(nr);

	*p  |= mask;
}

/*
 * This routine doesn't need to be atomic.
 */
static inline int test_bit(int nr, const void * addr)
{
	return ((unsigned char *) addr)[nr >> 3] & (1U << (nr & 7));
}

#endif /* _LINUX_TYPES_H */

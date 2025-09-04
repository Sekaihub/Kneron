/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2013-2014, ARM Limited and Contributors. All rights reserved.
 */

#ifndef PDMA_MMIO_H
#define PDMA_MMIO_H

static inline void mmio_write_8(uintptr_t addr, uint8_t value)
{
	writeb(value, addr);
}

static inline uint8_t mmio_read_8(uintptr_t addr)
{
	return readb(addr);
}

static inline void mmio_write_16(uintptr_t addr, uint16_t value)
{
	writew(value, addr);
}

static inline uint16_t mmio_read_16(uintptr_t addr)
{
	return readw(addr);
}

static inline void mmio_clrsetbits_16(uintptr_t addr,
				uint16_t clear,
				uint16_t set)
{
	mmio_write_16(addr, (mmio_read_16(addr) & ~clear) | set);
}

static inline void mmio_write_32(uintptr_t addr, uint32_t value)
{
	writel(value, addr);
}

static inline uint32_t mmio_read_32(uintptr_t addr)
{
	return readl(addr);
}

static inline void mmio_write_64(uintptr_t addr, uint64_t value)
{
	writeq(value, addr);
}

static inline uint64_t mmio_read_64(uintptr_t addr)
{
	return readq(addr);
}

static inline void mmio_clrbits_32(uintptr_t addr, uint32_t clear)
{
	mmio_write_32(addr, mmio_read_32(addr) & ~clear);
}

static inline void mmio_setbits_32(uintptr_t addr, uint32_t set)
{
	mmio_write_32(addr, mmio_read_32(addr) | set);
}

static inline void mmio_clrsetbits_32(uintptr_t addr,
				uint32_t clear,
				uint32_t set)
{
	mmio_write_32(addr, (mmio_read_32(addr) & ~clear) | set);
}

#endif /* PDMA_MMIO_H */

/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Platform related header file.
 */

#ifndef _VTX_ASOC_PLATFORM_H_
#define _VTX_ASOC_PLATFORM_H_

#if defined(CONFIG_ARCH_LEIPZIG)
#include "./leipzig/vtx-asoc.h"
#elif defined(CONFIG_ARCH_VIENNA)
#include "./vienna/vtx-asoc.h"
#else
// Un-Supported Platform!
#endif


#endif /* _VTX_ASOC_PLATFORM_H_ */



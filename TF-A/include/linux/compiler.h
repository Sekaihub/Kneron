/*
 * Keep all the ugly #ifdef for system stuff here
 */

#ifndef __COMPILER_H__
#define __COMPILER_H__

#include <linux/types.h>

// LITTLE_ENDIAN
#define cpu_to_le16(x)	(x)
#define cpu_to_le32(x)	(x)
#define cpu_to_le64(x)	(x)
#define le16_to_cpu(x)	(x)
#define le32_to_cpu(x)	(x)
#define le64_to_cpu(x)	(x)
#define __le16_to_cpu(x) ((__force __u16)(__le16)(x))

#endif

/* cs_hwpal_bare.h
 *
 * Configuration Settings for the 'barebones' Driver Framework Implementation.
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

// Active debug checks
// This define must be disabled for footprint optimization
//#define HWPAL_BARE_DEBUGCHECKS

// The device names supported by Device_Find()
// remember that all listed devices will be supported by hwpal
// for footprint not used devices should be disabled.
#include <platform_def.h>
#define HWPAL_BARE_EIP130_NAME      "EIP130"
#define HWPAL_BARE_EIP93_NAME       "EIP93"
#define HWPAL_BARE_EIP28_NAME       "EIP28"

// Definition of hardware access addresses
// These addresses must match the hardware addresses configured for the device.
//#define HWPAL_BARE_EIP130_ADDRESS   0x40000000 // Secure
#define HWPAL_BARE_EIP130_ADDRESS   VPL_SCRTU_EIP130_BASE   // Non-secure
#define HWPAL_BARE_EIP93_ADDRESS    0x40010000
#define HWPAL_BARE_EIP28_ADDRESS    0x40004000

// Define size of the memory window for each device.
#define HWPAL_BARE_EIP130_WINDOWEND 0x3FFF
#define HWPAL_BARE_EIP93_WINDOWEND  0xFFFF
#define HWPAL_BARE_EIP28_WINDOWEND  0x3FFF

// Active trace of all device find operations.
//#define DEVICE_TRACE_FIND

// Active trace of all device register reads/writes
//#define DEVICE_TRACE_RW

// Activate 32bit endianess swaps when accessing device registers
//#define DEVICE_SWAP

// Number of DMA-safe buffers to support
#define DMARES_BUFFER_COUNT       9

// Fixed size of each DMA-safe buffer
#define DMARES_BUFFER_SIZE_BYTES  2048

// Activate 32bit endianess swaps when accessing dma buffers
//#define DMARESOURCE_SWAP

// Activate performance measurements
//#define HWPAL_BARE_ENABLE_SBLPERF

/* end of file cs_hwpal_bare.h */

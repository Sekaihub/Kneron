/* cs_hwpal_umdevxs.h
 *
 * Configuration Settings for Driver Framework Implementation (Example)
 */

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*   Module        : SecureBoot                                               */
/*   Version       : 4.3                                                      */
/*   Configuration : SecureBoot                                               */
/*                                                                            */
/*   Date          : 2020-Oct-30                                              */
/*                                                                            */
/* Copyright (c) 2007-2020 by Rambus, Inc. and/or its subsidiaries.           */
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

// logging level for HWPAL Device
// Choose from LOG_SEVERITY_INFO, LOG_SEVERITY_WARN, LOG_SEVERITY_CRIT
#define HWPAL_LOG_SEVERITY  LOG_SEVERITY_WARN

// maximum allowed length for a device name
#define HWPAL_MAX_DEVICE_NAME_LENGTH 64

// debug checking and trace code
#define HWPAL_STRICT_ARGS_CHECK
#define HWPAL_DEVICE_MAGIC        54333
#define HWPAL_TRACE_DEVICE_READ
#define HWPAL_TRACE_DEVICE_WRITE

// device to request from UMDevXS driver
#define HWPAL_DEVICE0_UMDEVXS  "EIP150"
#define HWPAL_DEVICE1_UMDEVXS  "EIP93"

// definition of static resources inside the above device
// Refer to the data sheet of device for the correct values
//                   Name            DeviceNr   Start    Last     Flags (see below)
#define HWPAL_DEVICES \
    HWPAL_DEVICE_ADD("EIP93",        0,         0x00000, 0x00FFF, 0), \
    HWPAL_DEVICE_ADD("EIP150",       0,         0x10000, 0x0FFFF, 0), \
    HWPAL_DEVICE_ADD("EIP150_TRNG",  1,         0x10000, 0x00080, 0), \
    HWPAL_DEVICE_ADD("EIP150_PKA",   1,         0x14000, 0x07FFF, 0), \
    HWPAL_DEVICE_ADD("EIP150_AIC",   1,         0x18000, 0x0801F, 0)
#endif

// Flags:
// (binary OR of the following)
//   0 = Disable trace
//   1 = Trace reads  (requires HWPAL_TRACE_DEVICE_READ)
//   2 = Trace writes (requires HWPAL_TRACE_DEVICE_WRITE)
//   4 = Swap word endianess before write / after read

// no remapping required
#define HWPAL_REMAP_ADDRESSES
/* device address remapping is done like this:
#define HWPAL_REMAP_ADDRESS \
      HWPAL_REMAP_ONE(_old, _new) \
      HWPAL_REMAP_ONE(_old, _new)
*/

// #of supported DMA resources
#define HWPAL_DMA_NRESOURCES 128

// only define this if the platform hardware guarantees cache coherency of
// DMA buffers, i.e. when SW does not need to do coherency management.
#undef HWPAL_ARCH_COHERENT

// DMARES_DOMAIN_DEVICE address is in the FPGA
// we must offset it from the local DMARES_DOMAIN_BUS address
#define HWPAL_DMARES_DEVICE_ADDR_OFFSET 0x50000000

/* end of file cs_hwpal_umdevxs.h */

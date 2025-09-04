/* cs_umdevxsproxy.h
 *
 * Configuration Switches for the UMDevXS Proxy Library.
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

#define UMDEVXSPROXY_LOG_PREFIX "UMDevXSProxy: "

#define UMDEVXSPROXY_NODE_NAME "//dev//umdevxs_c"

// uncomment to remove selected functionality
//#define UMDEVXSPROXY_REMOVE_DEVICE
//#define UMDEVXSPROXY_REMOVE_SMBUF
//#define UMDEVXSPROXY_REMOVE_INTERRUPT

/* end of file cs_umdevxsproxy.h */

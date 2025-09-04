/* dftest.c
 *
 * Description: test suite for Driver Framework.
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

#include "sfzutf.h"
#include "cs_dftest.h"

#ifndef DFTEST_REMOVE_BASIC_DEFINES
void suite_add_test_basic_defs(void);
#endif
#ifndef DFTEST_REMOVE_DEVICE_APIS
void suite_add_test_device_apis(void);
#endif
#ifndef DFTEST_REMOVE_DMA_RESOURCE_APIS
void suite_add_test_dma_resource_apis(void);
#endif
#ifndef DFTEST_REMOVE_CLIB
void suite_add_test_clib(void);
#endif

void build_suite(void)
{
    sfzutf_suite_create("Driver Framework Test Suite");
#ifndef DFTEST_REMOVE_BASIC_DEFINES
    suite_add_test_basic_defs();
#endif
#ifndef DFTEST_REMOVE_CLIB
    suite_add_test_clib();
#endif
#ifndef DFTEST_REMOVE_DEVICE_APIS
    suite_add_test_device_apis();
#endif
#ifndef DFTEST_REMOVE_DMA_RESOURCE_APIS
    suite_add_test_dma_resource_apis();
#endif
}

/* end of file dftest.c */

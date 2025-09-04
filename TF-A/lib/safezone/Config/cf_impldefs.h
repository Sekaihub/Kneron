/* cf_impldefs.h
 *
 * Description: Configuration options for Framework/IMPLDEFS implementation
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

/*
   All L_PRINTFs (ie. all debug/trace and panic messages).
 */
#undef  IMPLDEFS_CF_DISABLE_DEBUG_L_PRINTF


/*
   L_DEBUG print outs.
 */
#undef  IMPLDEFS_CF_DISABLE_L_DEBUG

#ifdef CFG_IMPLDEFS_NO_DEBUG
#define IMPLDEFS_CF_DISABLE_L_DEBUG
#endif


/*
   L_TRACE print outs.
 */
#define IMPLDEFS_CF_DISABLE_L_TRACE

#ifdef CFG_IMPLDEFS_ENABLE_TRACE
#undef  IMPLDEFS_CF_DISABLE_L_TRACE
#endif


/*
   ASSERT() macro, i.e. assertion checks.
 */
#undef  IMPLDEFS_CF_DISABLE_ASSERT

#ifdef CFG_IMPLDEFS_NO_DEBUG
#define IMPLDEFS_CF_DISABLE_ASSERT
#endif

/*
   PRECONDITION() macro, ie. function contract input checks.
 */
#undef  IMPLDEFS_CF_DISABLE_PRECONDITION

#ifdef CFG_IMPLDEFS_NO_DEBUG
#define IMPLDEFS_CF_DISABLE_PRECONDITION
#endif

/*
   POSTCONDITION() macro, ie. function contract output checks.
 */
#undef  IMPLDEFS_CF_DISABLE_POSTCONDITION

#ifdef CFG_IMPLDEFS_NO_DEBUG
#define IMPLDEFS_CF_DISABLE_POSTCONDITION
#endif

/**
   All assertion and function contract checks.
   (Ie. ASSERT(), PRECONDITION(), and POSTCONDITION() macros.)
 */
#undef  IMPLDEFS_CF_DISABLE_ASSERTION_CHECK

#ifdef CFG_IMPLDEFS_NO_DEBUG
#define IMPLDEFS_CF_DISABLE_ASSERTION_CHECK
#endif

/* end of file cf_impldefs.h */

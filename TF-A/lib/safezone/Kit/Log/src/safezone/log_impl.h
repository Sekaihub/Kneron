/* log_impl.h
 *
 * Log Module, implementation for SafeZone Framework
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

#ifndef INCLUDE_GUARD_LOG_IMPL_H
#define INCLUDE_GUARD_LOG_IMPL_H

#include "implementation_defs.h"        // original L_DEBUG and helpers

void
Log_HexDump_SafeZone(
    const char * szPrefix_p,
    const unsigned int PrintOffset,
    const uint8_t * Buffer_p,
    const unsigned int ByteCount,
    const char * FileLineStr_p);

#define Log_HexDump(_szPrefix_p, _PrintOffset, _Buffer_p, _ByteCount) \
    Log_HexDump_SafeZone(_szPrefix_p, _PrintOffset, _Buffer_p, _ByteCount, __FILELINE__)

#define Print_HexDump(_szPrefix_p, _PrintOffset, _Buffer_p, _ByteCount) \
    Log_HexDump_SafeZone(_szPrefix_p, _PrintOffset, _Buffer_p, _ByteCount, NULL)

#ifndef IMPLDEFS_CF_DISABLE_L_DEBUG

#define Log_Message(_str) \
    DEBUG_printf("LL_DEBUG, LF_LOG, " __FILELINE__ ": " _str)

#define Log_FormattedMessage(...) \
    DEBUG_printf("LL_DEBUG, LF_LOG, " __FILELINE__ ": " __VA_ARGS__)

#define Log_FormattedMessageINFO(...) \
    DEBUG_printf("LL_DEBUG, LF_LOG_INFO, " __FILELINE__ ": " __VA_ARGS__)

#define Log_FormattedMessageWARN(...) \
    DEBUG_printf("LL_DEBUG, LF_LOG_WARN, " __FILELINE__ ": " __VA_ARGS__)

#define Log_FormattedMessageCRIT(...) \
    DEBUG_printf("LL_DEBUG, LF_LOG_CRIT, " __FILELINE__ ": " __VA_ARGS__)

#else

// debug logs are disabled
#define Log_Message(_str)
#define Log_FormattedMessage(...)
#define Log_FormattedMessageINFO(...)
#define Log_FormattedMessageWARN(...)
#define Log_FormattedMessageCRIT(...)

#endif /* IMPLDEFS_CF_DISABLE_L_DEBUG */

#endif /* INCLUDE_GUARD_LOG_IMPL_H */

/* end of file log_impl.h */

##
## File: configure.ac
##
## Source file for building configure with automake+autoconf
##

#------------------------------------------------------------------------------
#
#    Module        : SecureBoot
#    Version       : 4.5
#    Configuration : SecureBoot
#
#    Date          : 2023-Feb-14
#
#  Copyright (c) 2007-2023 by Rambus, Inc. and/or its subsidiaries.
#  All rights reserved. Unauthorized use (including, without limitation,
#  distribution and copying) is strictly prohibited. All use requires,
#  and is subject to, explicit written authorization and nondisclosure
#  agreements with Rambus, Inc. and/or its subsidiaries.
#
#  For more information or support, please go to our online support system at
#  https://sipsupport.rambus.com.
#  In case you do not have an account for this system, please send an e-mail
#  to sipsupport@rambus.com.
#------------------------------------------------------------------------------

AC_INIT([SafeZone-SecureBoot], [4.5])

AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([foreign no-define])

AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AS

AC_C_CONST
AC_C_RESTRICT
AC_C_INLINE

AC_CHECK_SIZEOF(void *)
AC_CHECK_SIZEOF(int)
AC_CHECK_SIZEOF(long)
AC_CHECK_SIZEOF(long long)

ENDIAN_FLAGS

ENABLE_YES_NO_OPT([stackmeasurement])
AM_CONDITIONAL([ENABLE_STACK], [test "X$enable_stackmeasurement" = "Xyes"])

ENABLE_YES_NO_OPT([heapmeasurement])
AM_CONDITIONAL([ENABLE_HEAP], [test "X$enable_heapmeasurement" = "Xyes"])

ENABLE_YES_NO_OPT([perfmeasurement])
AM_CONDITIONAL([ENABLE_PERF], [test "X$enable_perfmeasurement" = "Xyes"])

ENABLE_DEBUG_OPT
AM_CONDITIONAL([ENABLE_DEBUG], [test "X$enable_debug" = "Xyes"])

ENABLE_YES_NO_OPT([coverage])
AM_CONDITIONAL([ENABLE_COVERAGE], [test "X$enable_coverage" = "Xyes"])
test x$enable_coverage = xyes && CFLAGS="$CFLAGS -fprofile-arcs -ftest-coverage"

AM_CONDITIONAL([ENABLE_GCC_STRICT_WARNINGS], [test "X$GCC_STRICT_WARNINGS" = "Xyes"])
if test "X$GCC_STRICT_WARNINGS" = "Xyes"
then
AC_MSG_NOTICE([Enabling stricter warnings.])
fi

AC_CONFIG_FILES(Makefile)

AC_OUTPUT

# end of file configure.ac

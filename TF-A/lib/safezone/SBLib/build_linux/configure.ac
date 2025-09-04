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

AM_CONDITIONAL([COMPILER_64], [test $ac_cv_sizeof_long -eq 8])
AM_CONDITIONAL([COMPILER_32], [test $ac_cv_sizeof_long -eq 4])

ENDIAN_FLAGS


ENABLE_SB_TARGET_OPT
AM_CONDITIONAL([ENABLE_VERSATILE], [test "X$enable_target" = "Xversatile"])
AM_CONDITIONAL([ENABLE_CUSTOM], [test "X$enable_target" = "Xcustom"])
AM_CONDITIONAL([ENABLE_BARE], [test "X$enable_target" = "Xbare"])


ENABLE_SB_HW
AM_CONDITIONAL([ENABLE_SBSW], [test "X$enable_sbsw" = "Xyes"])
AM_CONDITIONAL([ENABLE_SBSM], [test "X$enable_sbsm" = "Xyes"])
AM_CONDITIONAL([ENABLE_SBPK], [test "X$enable_sbpk" = "Xyes"])
AM_CONDITIONAL([ENABLE_SBPE], [test "X$enable_sbpe" = "Xyes"])
AM_CONDITIONAL([ENABLE_SBPEPK], [test "X$enable_sbpepk" = "Xyes"])

ENABLE_YES_NO_OPT([stackmeasurement])
AM_CONDITIONAL([ENABLE_STACK], [test "X$enable_stackmeasurement" = "Xyes"])

ENABLE_YES_NO_OPT([heapmeasurement])
AM_CONDITIONAL([ENABLE_HEAP], [test "X$enable_heapmeasurement" = "Xyes"])

ENABLE_YES_NO_OPT([perfmeasurement])
AM_CONDITIONAL([ENABLE_PERF], [test "X$enable_perfmeasurement" = "Xyes"])

ENABLE_YES_NO_OPT([sbsimtime])
AM_CONDITIONAL([ENABLE_SBSIM_TIME], [test "X$enable_sbsimtime" = "Xyes"])

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

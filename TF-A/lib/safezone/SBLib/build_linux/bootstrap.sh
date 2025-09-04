#!/bin/sh
#
# bootstrap.sh
#
# Generates configure for configuring this package with automake & autoconf
#

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

# Omit warnings
aclocal -I ../../m4 2>/dev/null \
  && automake --add-missing --copy 2>/dev/null \
  && autoconf 2>/dev/null

if test "$?" != "0";
then
  # Error occured in processing, then output the error
  aclocal -I ../../m4 \
    && automake --add-missing --copy \
    && autoconf
  exit $?
fi

# end of file

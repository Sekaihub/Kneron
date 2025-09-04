##
## File: Makefile.am
##
## Template for building Makefile with automake+configure
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

# --------------------------
# Secure Boot Configurations
# --------------------------
#                        I/P  C/P  SW/HW  AES SHA ECDSA/RSA WrapKey MaxCerts Curve  SBCR
#                        ---  ---  ------ --- --- ----- ------- -------- -----------
# cfgP224IPc0sw          Yes  No   SW     n/a SW  SW    n/a     0        P-224   n/a
# cfgP224IPc1sw          Yes  No   SW     n/a SW  SW    n/a     1        P-224   n/a
# cfgP224IPc2sw          Yes  No   SW     n/a SW  SW    n/a     2        P-224   n/a
# cfgP224IPc8sw          Yes  No   SW     n/a SW  SW    n/a     8        P-224   n/a
# cfgP224CPc0sw          Yes  Yes  SW     SW  SW  SW    Prg     0        P-224   128
# cfgP224CPc1sw          Yes  Yes  SW     SW  SW  SW    Prg     1        P-224   128
# cfgP224CPc2sw          Yes  Yes  SW     SW  SW  SW    Prg     2        P-224   128
# cfgP224CPc8sw          Yes  Yes  SW     SW  SW  SW    Prg     8        P-224   128
# cfgP224CPKc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-224  K128
# cfgP224CPKc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-224  K128
# cfgP224CPKc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-224  K128
# cfgP224CPKc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-224  K128
# cfgP224CXPc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-224   256
# cfgP224CXPc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-224   256
# cfgP224CXPc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-224   256
# cfgP224CXPc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-224   256
# cfgP224CXPKc0sw        Yes  Yes  SW     SW  SW  SW    Prg     0        P-224  K256
# cfgP224CXPKc1sw        Yes  Yes  SW     SW  SW  SW    Prg     1        P-224  K256
# cfgP224CXPKc2sw        Yes  Yes  SW     SW  SW  SW    Prg     2        P-224  K256
# cfgP224CXPKc8sw        Yes  Yes  SW     SW  SW  SW    Prg     8        P-224  K256
# cfgP256IPc0sw          Yes  No   SW     n/a SW  SW    n/a     0        P-256   n/a
# cfgP256IPc1sw          Yes  No   SW     n/a SW  SW    n/a     1        P-256   n/a
# cfgP256IPc2sw          Yes  No   SW     n/a SW  SW    n/a     2        P-256   n/a
# cfgP256IPc8sw          Yes  No   SW     n/a SW  SW    n/a     8        P-256   n/a
# cfgP256CPc0sw          Yes  Yes  SW     SW  SW  SW    Prg     0        P-256   128
# cfgP256CPc1sw          Yes  Yes  SW     SW  SW  SW    Prg     1        P-256   128
# cfgP256CPc2sw          Yes  Yes  SW     SW  SW  SW    Prg     2        P-256   128
# cfgP256CPc8sw          Yes  Yes  SW     SW  SW  SW    Prg     8        P-256   128
# cfgP256CPKc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-256  K128
# cfgP256CPKc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-256  K128
# cfgP256CPKc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-256  K128
# cfgP256CPKc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-256  K128
# cfgP256CXPc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-256   256
# cfgP256CXPc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-256   256
# cfgP256CXPc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-256   256
# cfgP256CXPc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-256   256
# cfgP256CXPKc0sw        Yes  Yes  SW     SW  SW  SW    Prg     0        P-256  K256
# cfgP256CXPKc1sw        Yes  Yes  SW     SW  SW  SW    Prg     1        P-256  K256
# cfgP256CXPKc2sw        Yes  Yes  SW     SW  SW  SW    Prg     2        P-256  K256
# cfgP256CXPKc8sw        Yes  Yes  SW     SW  SW  SW    Prg     8        P-256  K256
# cfgP384IPc0sw          Yes  No   SW     n/a SW  SW    n/a     0        P-384   n/a
# cfgP384IPc1sw          Yes  No   SW     n/a SW  SW    n/a     1        P-384   n/a
# cfgP384IPc2sw          Yes  No   SW     n/a SW  SW    n/a     2        P-384   n/a
# cfgP384IPc8sw          Yes  No   SW     n/a SW  SW    n/a     8        P-384   n/a
# cfgP384CPc0sw          Yes  Yes  SW     SW  SW  SW    Prg     0        P-384   128
# cfgP384CPc1sw          Yes  Yes  SW     SW  SW  SW    Prg     1        P-384   128
# cfgP384CPc2sw          Yes  Yes  SW     SW  SW  SW    Prg     2        P-384   128
# cfgP384CPc8sw          Yes  Yes  SW     SW  SW  SW    Prg     8        P-384   128
# cfgP384CPKc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-384  K128
# cfgP384CPKc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-384  K128
# cfgP384CPKc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-384  K128
# cfgP384CPKc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-384  K128
# cfgP384CXPc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-384   256
# cfgP384CXPc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-384   256
# cfgP384CXPc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-384   256
# cfgP384CXPc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-384   256
# cfgP384CXPKc0sw        Yes  Yes  SW     SW  SW  SW    Prg     0        P-384  K256
# cfgP384CXPKc1sw        Yes  Yes  SW     SW  SW  SW    Prg     1        P-384  K256
# cfgP384CXPKc2sw        Yes  Yes  SW     SW  SW  SW    Prg     2        P-384  K256
# cfgP384CXPKc8sw        Yes  Yes  SW     SW  SW  SW    Prg     8        P-384  K256
# cfgP521IPc0sw          Yes  No   SW     n/a SW  SW    n/a     0        P-521   n/a
# cfgP521IPc1sw          Yes  No   SW     n/a SW  SW    n/a     1        P-521   n/a
# cfgP521IPc2sw          Yes  No   SW     n/a SW  SW    n/a     2        P-521   n/a
# cfgP521IPc8sw          Yes  No   SW     n/a SW  SW    n/a     8        P-521   n/a
# cfgP521CPc0sw          Yes  Yes  SW     SW  SW  SW    Prg     0        P-521   128
# cfgP521CPc1sw          Yes  Yes  SW     SW  SW  SW    Prg     1        P-521   128
# cfgP521CPc2sw          Yes  Yes  SW     SW  SW  SW    Prg     2        P-521   128
# cfgP521CPc8sw          Yes  Yes  SW     SW  SW  SW    Prg     8        P-521   128
# cfgP521CPKc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-521  K128
# cfgP521CPKc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-521  K128
# cfgP521CPKc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-521  K128
# cfgP521CPKc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-521  K128
# cfgP521CXPc0sw         Yes  Yes  SW     SW  SW  SW    Prg     0        P-521   256
# cfgP521CXPc1sw         Yes  Yes  SW     SW  SW  SW    Prg     1        P-521   256
# cfgP521CXPc2sw         Yes  Yes  SW     SW  SW  SW    Prg     2        P-521   256
# cfgP521CXPc8sw         Yes  Yes  SW     SW  SW  SW    Prg     8        P-521   256
# cfgP521CXPKc0sw        Yes  Yes  SW     SW  SW  SW    Prg     0        P-521  K256
# cfgP521CXPKc1sw        Yes  Yes  SW     SW  SW  SW    Prg     1        P-521  K256
# cfgP521CXPKc2sw        Yes  Yes  SW     SW  SW  SW    Prg     2        P-521  K256
# cfgP521CXPKc8sw        Yes  Yes  SW     SW  SW  SW    Prg     8        P-521  K256
# cfgRSA2048pkcsIPc0sw   Yes  No   SW     n/a SW  SW    n/a     0        2048    n/a
# cfgRSA2048pkcsIPc1sw   Yes  No   SW     n/a SW  SW    n/a     1        2048    n/a
# cfgRSA2048pkcsIPc2sw   Yes  No   SW     n/a SW  SW    n/a     2        2048    n/a
# cfgRSA2048pkcsIPc8sw   Yes  No   SW     n/a SW  SW    n/a     8        2048    n/a
# cfgRSA2048pkcsCPc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        2048    128
# cfgRSA2048pkcsCPc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        2048    128
# cfgRSA2048pkcsCPc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        2048    128
# cfgRSA2048pkcsCPc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        2048    128
# cfgRSA2048pkcsCPKc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        2048   K128
# cfgRSA2048pkcsCPKc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        2048   K128
# cfgRSA2048pkcsCPKc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        2048   K128
# cfgRSA2048pkcsCPKc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        2048   K128
# cfgRSA2048pkcsCXPc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        2048    256
# cfgRSA2048pkcsCXPc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        2048    256
# cfgRSA2048pkcsCXPc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        2048    256
# cfgRSA2048pkcsCXPc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        2048    256
# cfgRSA2048pkcsCXPKc0sw Yes  Yes  SW     SW  SW  SW    Prg     0        2048   K256
# cfgRSA2048pkcsCXPKc1sw Yes  Yes  SW     SW  SW  SW    Prg     1        2048   K256
# cfgRSA2048pkcsCXPKc2sw Yes  Yes  SW     SW  SW  SW    Prg     2        2048   K256
# cfgRSA2048pkcsCXPKc8sw Yes  Yes  SW     SW  SW  SW    Prg     8        2048   K256
# cfgRSA3072pkcsIPc0sw   Yes  No   SW     n/a SW  SW    n/a     0        3072    n/a
# cfgRSA3072pkcsIPc1sw   Yes  No   SW     n/a SW  SW    n/a     1        3072    n/a
# cfgRSA3072pkcsIPc2sw   Yes  No   SW     n/a SW  SW    n/a     2        3072    n/a
# cfgRSA3072pkcsIPc8sw   Yes  No   SW     n/a SW  SW    n/a     8        3072    n/a
# cfgRSA3072pkcsCPc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        3072    128
# cfgRSA3072pkcsCPc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        3072    128
# cfgRSA3072pkcsCPc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        3072    128
# cfgRSA3072pkcsCPc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        3072    128
# cfgRSA3072pkcsCPKc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        3072   K128
# cfgRSA3072pkcsCPKc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        3072   K128
# cfgRSA3072pkcsCPKc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        3072   K128
# cfgRSA3072pkcsCPKc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        3072   K128
# cfgRSA3072pkcsCXPc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        3072    256
# cfgRSA3072pkcsCXPc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        3072    256
# cfgRSA3072pkcsCXPc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        3072    256
# cfgRSA3072pkcsCXPc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        3072    256
# cfgRSA3072pkcsCXPKc0sw Yes  Yes  SW     SW  SW  SW    Prg     0        3072   K256
# cfgRSA3072pkcsCXPKc1sw Yes  Yes  SW     SW  SW  SW    Prg     1        3072   K256
# cfgRSA3072pkcsCXPKc2sw Yes  Yes  SW     SW  SW  SW    Prg     2        3072   K256
# cfgRSA3072pkcsCXPKc8sw Yes  Yes  SW     SW  SW  SW    Prg     8        3072   K256
# cfgRSA4096pkcsIPc0sw   Yes  No   SW     n/a SW  SW    n/a     0        4096    n/a
# cfgRSA4096pkcsIPc1sw   Yes  No   SW     n/a SW  SW    n/a     1        4096    n/a
# cfgRSA4096pkcsIPc2sw   Yes  No   SW     n/a SW  SW    n/a     2        4096    n/a
# cfgRSA4096pkcsIPc8sw   Yes  No   SW     n/a SW  SW    n/a     8        4096    n/a
# cfgRSA4096pkcsCPc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        4096    128
# cfgRSA4096pkcsCPc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        4096    128
# cfgRSA4096pkcsCPc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        4096    128
# cfgRSA4096pkcsCPc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        4096    128
# cfgRSA4096pkcsCPKc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        4096   K128
# cfgRSA4096pkcsCPKc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        4096   K128
# cfgRSA4096pkcsCPKc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        4096   K128
# cfgRSA4096pkcsCPKc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        4096   K128
# cfgRSA4096pkcsCXPc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        4096    256
# cfgRSA4096pkcsCXPc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        4096    256
# cfgRSA4096pkcsCXPc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        4096    256
# cfgRSA4096pkcsCXPc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        4096    256
# cfgRSA4096pkcsCXPKc0sw Yes  Yes  SW     SW  SW  SW    Prg     0        4096   K256
# cfgRSA4096pkcsCXPKc1sw Yes  Yes  SW     SW  SW  SW    Prg     1        4096   K256
# cfgRSA4096pkcsCXPKc2sw Yes  Yes  SW     SW  SW  SW    Prg     2        4096   K256
# cfgRSA4096pkcsCXPKc8sw Yes  Yes  SW     SW  SW  SW    Prg     8        4096   K256
# cfgRSA2048pssIPc0sw    Yes  No   SW     n/a SW  SW    n/a     0        2048    n/a
# cfgRSA2048pssIPc1sw    Yes  No   SW     n/a SW  SW    n/a     1        2048    n/a
# cfgRSA2048pssIPc2sw    Yes  No   SW     n/a SW  SW    n/a     2        2048    n/a
# cfgRSA2048pssIPc8sw    Yes  No   SW     n/a SW  SW    n/a     8        2048    n/a
# cfgRSA2048pssCPc0sw    Yes  Yes  SW     SW  SW  SW    Prg     0        2048    128
# cfgRSA2048pssCPc1sw    Yes  Yes  SW     SW  SW  SW    Prg     1        2048    128
# cfgRSA2048pssCPc2sw    Yes  Yes  SW     SW  SW  SW    Prg     2        2048    128
# cfgRSA2048pssCPc8sw    Yes  Yes  SW     SW  SW  SW    Prg     8        2048    128
# cfgRSA2048pssCPKc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        2048   K128
# cfgRSA2048pssCPKc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        2048   K128
# cfgRSA2048pssCPKc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        2048   K128
# cfgRSA2048pssCPKc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        2048   K128
# cfgRSA2048pssCXPc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        2048    256
# cfgRSA2048pssCXPc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        2048    256
# cfgRSA2048pssCXPc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        2048    256
# cfgRSA2048pssCXPc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        2048    256
# cfgRSA2048pssCXPKc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        2048   K256
# cfgRSA2048pssCXPKc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        2048   K256
# cfgRSA2048pssCXPKc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        2048   K256
# cfgRSA2048pssCXPKc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        2048   K256
# cfgRSA3072pssIPc0sw    Yes  No   SW     n/a SW  SW    n/a     0        3072    n/a
# cfgRSA3072pssIPc1sw    Yes  No   SW     n/a SW  SW    n/a     1        3072    n/a
# cfgRSA3072pssIPc2sw    Yes  No   SW     n/a SW  SW    n/a     2        3072    n/a
# cfgRSA3072pssIPc8sw    Yes  No   SW     n/a SW  SW    n/a     8        3072    n/a
# cfgRSA3072pssCPc0sw    Yes  Yes  SW     SW  SW  SW    Prg     0        3072    128
# cfgRSA3072pssCPc1sw    Yes  Yes  SW     SW  SW  SW    Prg     1        3072    128
# cfgRSA3072pssCPc2sw    Yes  Yes  SW     SW  SW  SW    Prg     2        3072    128
# cfgRSA3072pssCPc8sw    Yes  Yes  SW     SW  SW  SW    Prg     8        3072    128
# cfgRSA3072pssCPKc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        3072   K128
# cfgRSA3072pssCPKc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        3072   K128
# cfgRSA3072pssCPKc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        3072   K128
# cfgRSA3072pssCPKc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        3072   K128
# cfgRSA3072pssCXPc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        3072    256
# cfgRSA3072pssCXPc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        3072    256
# cfgRSA3072pssCXPc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        3072    256
# cfgRSA3072pssCXPc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        3072    256
# cfgRSA3072pssCXPKc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        3072   K256
# cfgRSA3072pssCXPKc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        3072   K256
# cfgRSA3072pssCXPKc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        3072   K256
# cfgRSA3072pssCXPKc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        3072   K256
# cfgRSA4096pssIPc0sw    Yes  No   SW     n/a SW  SW    n/a     0        4096    n/a
# cfgRSA4096pssIPc1sw    Yes  No   SW     n/a SW  SW    n/a     1        4096    n/a
# cfgRSA4096pssIPc2sw    Yes  No   SW     n/a SW  SW    n/a     2        4096    n/a
# cfgRSA4096pssIPc8sw    Yes  No   SW     n/a SW  SW    n/a     8        4096    n/a
# cfgRSA4096pssCPc0sw    Yes  Yes  SW     SW  SW  SW    Prg     0        4096    128
# cfgRSA4096pssCPc1sw    Yes  Yes  SW     SW  SW  SW    Prg     1        4096    128
# cfgRSA4096pssCPc2sw    Yes  Yes  SW     SW  SW  SW    Prg     2        4096    128
# cfgRSA4096pssCPc8sw    Yes  Yes  SW     SW  SW  SW    Prg     8        4096    128
# cfgRSA4096pssCPKc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        4096   K128
# cfgRSA4096pssCPKc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        4096   K128
# cfgRSA4096pssCPKc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        4096   K128
# cfgRSA4096pssCPKc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        4096   K128
# cfgRSA4096pssCXPc0sw   Yes  Yes  SW     SW  SW  SW    Prg     0        4096    256
# cfgRSA4096pssCXPc1sw   Yes  Yes  SW     SW  SW  SW    Prg     1        4096    256
# cfgRSA4096pssCXPc2sw   Yes  Yes  SW     SW  SW  SW    Prg     2        4096    256
# cfgRSA4096pssCXPc8sw   Yes  Yes  SW     SW  SW  SW    Prg     8        4096    256
# cfgRSA4096pssCXPKc0sw  Yes  Yes  SW     SW  SW  SW    Prg     0        4096   K256
# cfgRSA4096pssCXPKc1sw  Yes  Yes  SW     SW  SW  SW    Prg     1        4096   K256
# cfgRSA4096pssCXPKc2sw  Yes  Yes  SW     SW  SW  SW    Prg     2        4096   K256
# cfgRSA4096pssCXPKc8sw  Yes  Yes  SW     SW  SW  SW    Prg     8        4096   K256
# cfgP224IPc0sm          Yes  No   SM     n/a SM  SM    n/a     0        P-224   n/a
# cfgP224IPc1sm          Yes  No   SM     n/a SM  SM    n/a     1        P-224   n/a
# cfgP224IPc2sm          Yes  No   SM     n/a SM  SM    n/a     2        P-224   n/a
# cfgP224IPc8sm          Yes  No   SM     n/a SM  SM    n/a     8        P-224   n/a
# cfgP224CPc0sm          Yes  Yes  SM     SM  SM  SM    Prg     0        P-224   128
# cfgP224CPc1sm          Yes  Yes  SM     SM  SM  SM    Prg     1        P-224   128
# cfgP224CPc2sm          Yes  Yes  SM     SM  SM  SM    Prg     2        P-224   128
# cfgP224CPc8sm          Yes  Yes  SM     SM  SM  SM    Prg     8        P-224   128
# cfgP224CNc0sm          Yes  Yes  SM     SM  SM  SM    OTP     0        P-224   128
# cfgP224CNc1sm          Yes  Yes  SM     SM  SM  SM    OTP     1        P-224   128
# cfgP224CNc2sm          Yes  Yes  SM     SM  SM  SM    OTP     2        P-224   128
# cfgP224CNc8sm          Yes  Yes  SM     SM  SM  SM    OTP     8        P-224   128
# cfgP224CNKc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-224  K256
# cfgP224CNKc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-224  K256
# cfgP224CNKc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-224  K256
# cfgP224CNKc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-224  K256
# cfgP224CXPc0sm         Yes  Yes  SM     SM  SM  SM    Prg     0        P-224   256
# cfgP224CXPc1sm         Yes  Yes  SM     SM  SM  SM    Prg     1        P-224   256
# cfgP224CXPc2sm         Yes  Yes  SM     SM  SM  SM    Prg     2        P-224   256
# cfgP224CXPc8sm         Yes  Yes  SM     SM  SM  SM    Prg     8        P-224   256
# cfgP224CXNc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-224   256
# cfgP224CXNc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-224   256
# cfgP224CXNc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-224   256
# cfgP224CXNc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-224   256
# cfgP224CXNKc0sm        Yes  Yes  SM     SM  SM  SM    OTP     0        P-224  K256
# cfgP224CXNKc1sm        Yes  Yes  SM     SM  SM  SM    OTP     1        P-224  K256
# cfgP224CXNKc2sm        Yes  Yes  SM     SM  SM  SM    OTP     2        P-224  K256
# cfgP224CXNKc8sm        Yes  Yes  SM     SM  SM  SM    OTP     8        P-224  K256
# cfgP256IPc0sm          Yes  No   SM     n/a SM  SM    n/a     0        P-256   n/a
# cfgP256IPc1sm          Yes  No   SM     n/a SM  SM    n/a     1        P-256   n/a
# cfgP256IPc2sm          Yes  No   SM     n/a SM  SM    n/a     2        P-256   n/a
# cfgP256IPc8sm          Yes  No   SM     n/a SM  SM    n/a     8        P-256   n/a
# cfgP256CPc0sm          Yes  Yes  SM     SM  SM  SM    Prg     0        P-256   128
# cfgP256CPc1sm          Yes  Yes  SM     SM  SM  SM    Prg     1        P-256   128
# cfgP256CPc2sm          Yes  Yes  SM     SM  SM  SM    Prg     2        P-256   128
# cfgP256CPc8sm          Yes  Yes  SM     SM  SM  SM    Prg     8        P-256   128
# cfgP256CNc0sm          Yes  Yes  SM     SM  SM  SM    OTP     0        P-256   128
# cfgP256CNc1sm          Yes  Yes  SM     SM  SM  SM    OTP     1        P-256   128
# cfgP256CNc2sm          Yes  Yes  SM     SM  SM  SM    OTP     2        P-256   128
# cfgP256CNc8sm          Yes  Yes  SM     SM  SM  SM    OTP     8        P-256   128
# cfgP256CNKc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-256  K256
# cfgP256CNKc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-256  K256
# cfgP256CNKc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-256  K256
# cfgP256CNKc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-256  K256
# cfgP256CXPc0sm         Yes  Yes  SM     SM  SM  SM    Prg     0        P-256   256
# cfgP256CXPc1sm         Yes  Yes  SM     SM  SM  SM    Prg     1        P-256   256
# cfgP256CXPc2sm         Yes  Yes  SM     SM  SM  SM    Prg     2        P-256   256
# cfgP256CXPc8sm         Yes  Yes  SM     SM  SM  SM    Prg     8        P-256   256
# cfgP256CXNc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-256   256
# cfgP256CXNc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-256   256
# cfgP256CXNc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-256   256
# cfgP256CXNc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-256   256
# cfgP256CXNKc0sm        Yes  Yes  SM     SM  SM  SM    OTP     0        P-256  K256
# cfgP256CXNKc1sm        Yes  Yes  SM     SM  SM  SM    OTP     1        P-256  K256
# cfgP256CXNKc2sm        Yes  Yes  SM     SM  SM  SM    OTP     2        P-256  K256
# cfgP256CXNKc8sm        Yes  Yes  SM     SM  SM  SM    OTP     8        P-256  K256
# cfgP384IPc0sm          Yes  No   SM     n/a SM  SM    n/a     0        P-384   n/a
# cfgP384IPc1sm          Yes  No   SM     n/a SM  SM    n/a     1        P-384   n/a
# cfgP384IPc2sm          Yes  No   SM     n/a SM  SM    n/a     2        P-384   n/a
# cfgP384IPc8sm          Yes  No   SM     n/a SM  SM    n/a     8        P-384   n/a
# cfgP384CPc0sm          Yes  Yes  SM     SM  SM  SM    Prg     0        P-384   128
# cfgP384CPc1sm          Yes  Yes  SM     SM  SM  SM    Prg     1        P-384   128
# cfgP384CPc2sm          Yes  Yes  SM     SM  SM  SM    Prg     2        P-384   128
# cfgP384CPc8sm          Yes  Yes  SM     SM  SM  SM    Prg     8        P-384   128
# cfgP384CNc0sm          Yes  Yes  SM     SM  SM  SM    OTP     0        P-384   128
# cfgP384CNc1sm          Yes  Yes  SM     SM  SM  SM    OTP     1        P-384   128
# cfgP384CNc2sm          Yes  Yes  SM     SM  SM  SM    OTP     2        P-384   128
# cfgP384CNc8sm          Yes  Yes  SM     SM  SM  SM    OTP     8        P-384   128
# cfgP384CNKc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-384  K256
# cfgP384CNKc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-384  K256
# cfgP384CNKc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-384  K256
# cfgP384CNKc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-384  K256
# cfgP384CXPc0sm         Yes  Yes  SM     SM  SM  SM    Prg     0        P-384   256
# cfgP384CXPc1sm         Yes  Yes  SM     SM  SM  SM    Prg     1        P-384   256
# cfgP384CXPc2sm         Yes  Yes  SM     SM  SM  SM    Prg     2        P-384   256
# cfgP384CXPc8sm         Yes  Yes  SM     SM  SM  SM    Prg     8        P-384   256
# cfgP384CXNc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-384   256
# cfgP384CXNc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-384   256
# cfgP384CXNc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-384   256
# cfgP384CXNc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-384   256
# cfgP384CXNKc0sm        Yes  Yes  SM     SM  SM  SM    OTP     0        P-384  K256
# cfgP384CXNKc1sm        Yes  Yes  SM     SM  SM  SM    OTP     1        P-384  K256
# cfgP384CXNKc2sm        Yes  Yes  SM     SM  SM  SM    OTP     2        P-384  K256
# cfgP384CXNKc8sm        Yes  Yes  SM     SM  SM  SM    OTP     8        P-384  K256
# cfgP521IPc0sm          Yes  No   SM     n/a SM  SM    n/a     0        P-521   n/a
# cfgP521IPc1sm          Yes  No   SM     n/a SM  SM    n/a     1        P-521   n/a
# cfgP521IPc2sm          Yes  No   SM     n/a SM  SM    n/a     2        P-521   n/a
# cfgP521IPc8sm          Yes  No   SM     n/a SM  SM    n/a     8        P-521   n/a
# cfgP521CPc0sm          Yes  Yes  SM     SM  SM  SM    Prg     0        P-521   128
# cfgP521CPc1sm          Yes  Yes  SM     SM  SM  SM    Prg     1        P-521   128
# cfgP521CPc2sm          Yes  Yes  SM     SM  SM  SM    Prg     2        P-521   128
# cfgP521CPc8sm          Yes  Yes  SM     SM  SM  SM    Prg     8        P-521   128
# cfgP521CNc0sm          Yes  Yes  SM     SM  SM  SM    OTP     0        P-521   128
# cfgP521CNc1sm          Yes  Yes  SM     SM  SM  SM    OTP     1        P-521   128
# cfgP521CNc2sm          Yes  Yes  SM     SM  SM  SM    OTP     2        P-521   128
# cfgP521CNc8sm          Yes  Yes  SM     SM  SM  SM    OTP     8        P-521   128
# cfgP521CNKc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-521  K256
# cfgP521CNKc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-521  K256
# cfgP521CNKc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-521  K256
# cfgP521CNKc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-521  K256
# cfgP521CXPc0sm         Yes  Yes  SM     SM  SM  SM    Prg     0        P-521   256
# cfgP521CXPc1sm         Yes  Yes  SM     SM  SM  SM    Prg     1        P-521   256
# cfgP521CXPc2sm         Yes  Yes  SM     SM  SM  SM    Prg     2        P-521   256
# cfgP521CXPc8sm         Yes  Yes  SM     SM  SM  SM    Prg     8        P-521   256
# cfgP521CXNc0sm         Yes  Yes  SM     SM  SM  SM    OTP     0        P-521   256
# cfgP521CXNc1sm         Yes  Yes  SM     SM  SM  SM    OTP     1        P-521   256
# cfgP521CXNc2sm         Yes  Yes  SM     SM  SM  SM    OTP     2        P-521   256
# cfgP521CXNc8sm         Yes  Yes  SM     SM  SM  SM    OTP     8        P-521   256
# cfgP521CXNKc0sm        Yes  Yes  SM     SM  SM  SM    OTP     0        P-521  K256
# cfgP521CXNKc1sm        Yes  Yes  SM     SM  SM  SM    OTP     1        P-521  K256
# cfgP521CXNKc2sm        Yes  Yes  SM     SM  SM  SM    OTP     2        P-521  K256
# cfgP521CXNKc8sm        Yes  Yes  SM     SM  SM  SM    OTP     8        P-521  K256
# cfgRSA2048pkcsIPc0sm   Yes  No   SM     n/a SM  SM    n/a     0        2048    n/a
# cfgRSA2048pkcsIPc1sm   Yes  No   SM     n/a SM  SM    n/a     1        2048    n/a
# cfgRSA2048pkcsIPc2sm   Yes  No   SM     n/a SM  SM    n/a     2        2048    n/a
# cfgRSA2048pkcsIPc8sm   Yes  No   SM     n/a SM  SM    n/a     8        2048    n/a
# cfgRSA2048pkcsCPc0sm   Yes  Yes  SM     SM  SM  SM    Prg     0        2048    128
# cfgRSA2048pkcsCPc1sm   Yes  Yes  SM     SM  SM  SM    Prg     1        2048    128
# cfgRSA2048pkcsCPc2sm   Yes  Yes  SM     SM  SM  SM    Prg     2        2048    128
# cfgRSA2048pkcsCPc8sm   Yes  Yes  SM     SM  SM  SM    Prg     8        2048    128
# cfgRSA2048pkcsCNc0sm   Yes  Yes  SM     SM  SM  SM    OTP     0        2048    128
# cfgRSA2048pkcsCNc1sm   Yes  Yes  SM     SM  SM  SM    OTP     1        2048    128
# cfgRSA2048pkcsCNc2sm   Yes  Yes  SM     SM  SM  SM    OTP     2        2048    128
# cfgRSA2048pkcsCNc8sm   Yes  Yes  SM     SM  SM  SM    OTP     8        2048    128
# cfgRSA2048pkcsCNKc0sm  Yes  Yes  SM     SM  SM  SM    OTP     0        2048   K256
# cfgRSA2048pkcsCNKc1sm  Yes  Yes  SM     SM  SM  SM    OTP     1        2048   K256
# cfgRSA2048pkcsCNKc2sm  Yes  Yes  SM     SM  SM  SM    OTP     2        2048   K256
# cfgRSA2048pkcsCNKc8sm  Yes  Yes  SM     SM  SM  SM    OTP     8        2048   K256
# cfgRSA2048pkcsCXPc0sm  Yes  Yes  SM     SM  SM  SM    Prg     0        2048    256
# cfgRSA2048pkcsCXPc1sm  Yes  Yes  SM     SM  SM  SM    Prg     1        2048    256
# cfgRSA2048pkcsCXPc2sm  Yes  Yes  SM     SM  SM  SM    Prg     2        2048    256
# cfgRSA2048pkcsCXPc8sm  Yes  Yes  SM     SM  SM  SM    Prg     8        2048    256
# cfgRSA2048pkcsCXNc0sm  Yes  Yes  SM     SM  SM  SM    OTP     0        2048    256
# cfgRSA2048pkcsCXNc1sm  Yes  Yes  SM     SM  SM  SM    OTP     1        2048    256
# cfgRSA2048pkcsCXNc2sm  Yes  Yes  SM     SM  SM  SM    OTP     2        2048    256
# cfgRSA2048pkcsCXNc8sm  Yes  Yes  SM     SM  SM  SM    OTP     8        2048    256
# cfgRSA2048pkcsCXNKc0sm Yes  Yes  SM     SM  SM  SM    OTP     0        2048   K256
# cfgRSA2048pkcsCXNKc1sm Yes  Yes  SM     SM  SM  SM    OTP     1        2048   K256
# cfgRSA2048pkcsCXNKc2sm Yes  Yes  SM     SM  SM  SM    OTP     2        2048   K256
# cfgRSA2048pkcsCXNKc8sm Yes  Yes  SM     SM  SM  SM    OTP     8        2048   K256
# cfgRSA3072pkcsIPc0sm   Yes  No   SM     n/a SM  SM    n/a     0        3072    n/a
# cfgRSA3072pkcsIPc1sm   Yes  No   SM     n/a SM  SM    n/a     1        3072    n/a
# cfgRSA3072pkcsIPc2sm   Yes  No   SM     n/a SM  SM    n/a     2        3072    n/a
# cfgRSA3072pkcsIPc8sm   Yes  No   SM     n/a SM  SM    n/a     8        3072    n/a
# cfgRSA3072pkcsCPc0sm   Yes  Yes  SM     SM  SM  SM    Prg     0        3072    128
# cfgRSA3072pkcsCPc1sm   Yes  Yes  SM     SM  SM  SM    Prg     1        3072    128
# cfgRSA3072pkcsCPc2sm   Yes  Yes  SM     SM  SM  SM    Prg     2        3072    128
# cfgRSA3072pkcsCPc8sm   Yes  Yes  SM     SM  SM  SM    Prg     8        3072    128
# cfgRSA3072pkcsCNc0sm   Yes  Yes  SM     SM  SM  SM    OTP     0        3072    128
# cfgRSA3072pkcsCNc1sm   Yes  Yes  SM     SM  SM  SM    OTP     1        3072    128
# cfgRSA3072pkcsCNc2sm   Yes  Yes  SM     SM  SM  SM    OTP     2        3072    128
# cfgRSA3072pkcsCNc8sm   Yes  Yes  SM     SM  SM  SM    OTP     8        3072    128
# cfgRSA3072pkcsCNKc0sm  Yes  Yes  SM     SM  SM  SM    OTP     0        3072   K256
# cfgRSA3072pkcsCNKc1sm  Yes  Yes  SM     SM  SM  SM    OTP     1        3072   K256
# cfgRSA3072pkcsCNKc2sm  Yes  Yes  SM     SM  SM  SM    OTP     2        3072   K256
# cfgRSA3072pkcsCNKc8sm  Yes  Yes  SM     SM  SM  SM    OTP     8        3072   K256
# cfgRSA3072pkcsCXPc0sm  Yes  Yes  SM     SM  SM  SM    Prg     0        3072    256
# cfgRSA3072pkcsCXPc1sm  Yes  Yes  SM     SM  SM  SM    Prg     1        3072    256
# cfgRSA3072pkcsCXPc2sm  Yes  Yes  SM     SM  SM  SM    Prg     2        3072    256
# cfgRSA3072pkcsCXPc8sm  Yes  Yes  SM     SM  SM  SM    Prg     8        3072    256
# cfgRSA3072pkcsCXNc0sm  Yes  Yes  SM     SM  SM  SM    OTP     0        3072    256
# cfgRSA3072pkcsCXNc1sm  Yes  Yes  SM     SM  SM  SM    OTP     1        3072    256
# cfgRSA3072pkcsCXNc2sm  Yes  Yes  SM     SM  SM  SM    OTP     2        3072    256
# cfgRSA3072pkcsCXNc8sm  Yes  Yes  SM     SM  SM  SM    OTP     8        3072    256
# cfgRSA3072pkcsCXNKc0sm Yes  Yes  SM     SM  SM  SM    OTP     0        3072   K256
# cfgRSA3072pkcsCXNKc1sm Yes  Yes  SM     SM  SM  SM    OTP     1        3072   K256
# cfgRSA3072pkcsCXNKc2sm Yes  Yes  SM     SM  SM  SM    OTP     2        3072   K256
# cfgRSA3072pkcsCXNKc8sm Yes  Yes  SM     SM  SM  SM    OTP     8        3072   K256
# cfgRSA2048pssIPc0sm    Yes  No   SM     n/a SM  SM    n/a     0        2048    n/a
# cfgRSA2048pssIPc1sm    Yes  No   SM     n/a SM  SM    n/a     1        2048    n/a
# cfgRSA2048pssIPc2sm    Yes  No   SM     n/a SM  SM    n/a     2        2048    n/a
# cfgRSA2048pssIPc8sm    Yes  No   SM     n/a SM  SM    n/a     8        2048    n/a
# cfgRSA2048pssCPc0sm    Yes  Yes  SM     SM  SM  SM    Prg     0        2048    128
# cfgRSA2048pssCPc1sm    Yes  Yes  SM     SM  SM  SM    Prg     1        2048    128
# cfgRSA2048pssCPc2sm    Yes  Yes  SM     SM  SM  SM    Prg     2        2048    128
# cfgRSA2048pssCPc8sm    Yes  Yes  SM     SM  SM  SM    Prg     8        2048    128
# cfgRSA2048pssCNc0sm    Yes  Yes  SM     SM  SM  SM    OTP     0        2048    128
# cfgRSA2048pssCNc1sm    Yes  Yes  SM     SM  SM  SM    OTP     1        2048    128
# cfgRSA2048pssCNc2sm    Yes  Yes  SM     SM  SM  SM    OTP     2        2048    128
# cfgRSA2048pssCNc8sm    Yes  Yes  SM     SM  SM  SM    OTP     8        2048    128
# cfgRSA2048pssCNKc0sm   Yes  Yes  SM     SM  SM  SM    OTP     0        2048   K256
# cfgRSA2048pssCNKc1sm   Yes  Yes  SM     SM  SM  SM    OTP     1        2048   K256
# cfgRSA2048pssCNKc2sm   Yes  Yes  SM     SM  SM  SM    OTP     2        2048   K256
# cfgRSA2048pssCNKc8sm   Yes  Yes  SM     SM  SM  SM    OTP     8        2048   K256
# cfgRSA2048pssCXPc0sm   Yes  Yes  SM     SM  SM  SM    Prg     0        2048    256
# cfgRSA2048pssCXPc1sm   Yes  Yes  SM     SM  SM  SM    Prg     1        2048    256
# cfgRSA2048pssCXPc2sm   Yes  Yes  SM     SM  SM  SM    Prg     2        2048    256
# cfgRSA2048pssCXPc8sm   Yes  Yes  SM     SM  SM  SM    Prg     8        2048    256
# cfgRSA2048pssCXNc0sm   Yes  Yes  SM     SM  SM  SM    OTP     0        2048    256
# cfgRSA2048pssCXNc1sm   Yes  Yes  SM     SM  SM  SM    OTP     1        2048    256
# cfgRSA2048pssCXNc2sm   Yes  Yes  SM     SM  SM  SM    OTP     2        2048    256
# cfgRSA2048pssCXNc8sm   Yes  Yes  SM     SM  SM  SM    OTP     8        2048    256
# cfgRSA2048pssCXNKc0sm  Yes  Yes  SM     SM  SM  SM    OTP     0        2048   K256
# cfgRSA2048pssCXNKc1sm  Yes  Yes  SM     SM  SM  SM    OTP     1        2048   K256
# cfgRSA2048pssCXNKc2sm  Yes  Yes  SM     SM  SM  SM    OTP     2        2048   K256
# cfgRSA2048pssCXNKc8sm  Yes  Yes  SM     SM  SM  SM    OTP     8        2048   K256
# cfgRSA3072pssIPc0sm    Yes  No   SM     n/a SM  SM    n/a     0        3072    n/a
# cfgRSA3072pssIPc1sm    Yes  No   SM     n/a SM  SM    n/a     1        3072    n/a
# cfgRSA3072pssIPc2sm    Yes  No   SM     n/a SM  SM    n/a     2        3072    n/a
# cfgRSA3072pssIPc8sm    Yes  No   SM     n/a SM  SM    n/a     8        3072    n/a
# cfgRSA3072pssCPc0sm    Yes  Yes  SM     SM  SM  SM    Prg     0        3072    128
# cfgRSA3072pssCPc1sm    Yes  Yes  SM     SM  SM  SM    Prg     1        3072    128
# cfgRSA3072pssCPc2sm    Yes  Yes  SM     SM  SM  SM    Prg     2        3072    128
# cfgRSA3072pssCPc8sm    Yes  Yes  SM     SM  SM  SM    Prg     8        3072    128
# cfgRSA3072pssCNc0sm    Yes  Yes  SM     SM  SM  SM    OTP     0        3072    128
# cfgRSA3072pssCNc1sm    Yes  Yes  SM     SM  SM  SM    OTP     1        3072    128
# cfgRSA3072pssCNc2sm    Yes  Yes  SM     SM  SM  SM    OTP     2        3072    128
# cfgRSA3072pssCNc8sm    Yes  Yes  SM     SM  SM  SM    OTP     8        3072    128
# cfgRSA3072pssCNKc0sm   Yes  Yes  SM     SM  SM  SM    OTP     0        3072   K256
# cfgRSA3072pssCNKc1sm   Yes  Yes  SM     SM  SM  SM    OTP     1        3072   K256
# cfgRSA3072pssCNKc2sm   Yes  Yes  SM     SM  SM  SM    OTP     2        3072   K256
# cfgRSA3072pssCNKc8sm   Yes  Yes  SM     SM  SM  SM    OTP     8        3072   K256
# cfgRSA3072pssCXPc0sm   Yes  Yes  SM     SM  SM  SM    Prg     0        3072    256
# cfgRSA3072pssCXPc1sm   Yes  Yes  SM     SM  SM  SM    Prg     1        3072    256
# cfgRSA3072pssCXPc2sm   Yes  Yes  SM     SM  SM  SM    Prg     2        3072    256
# cfgRSA3072pssCXPc8sm   Yes  Yes  SM     SM  SM  SM    Prg     8        3072    256
# cfgRSA3072pssCXNc0sm   Yes  Yes  SM     SM  SM  SM    OTP     0        3072    256
# cfgRSA3072pssCXNc1sm   Yes  Yes  SM     SM  SM  SM    OTP     1        3072    256
# cfgRSA3072pssCXNc2sm   Yes  Yes  SM     SM  SM  SM    OTP     2        3072    256
# cfgRSA3072pssCXNc8sm   Yes  Yes  SM     SM  SM  SM    OTP     8        3072    256
# cfgRSA3072pssCXNKc0sm  Yes  Yes  SM     SM  SM  SM    OTP     0        3072   K256
# cfgRSA3072pssCXNKc1sm  Yes  Yes  SM     SM  SM  SM    OTP     1        3072   K256
# cfgRSA3072pssCXNKc2sm  Yes  Yes  SM     SM  SM  SM    OTP     2        3072   K256
# cfgRSA3072pssCXNKc8sm  Yes  Yes  SM     SM  SM  SM    OTP     8        3072   K256
# cfgP224IPc0pk          Yes  No   PK     n/a SW  PK    n/a     0        P-224   n/a
# cfgP224IPc1pk          Yes  No   PK     n/a SW  PK    n/a     1        P-224   n/a
# cfgP224IPc2pk          Yes  No   PK     n/a SW  PK    n/a     2        P-224   n/a
# cfgP224IPc8pk          Yes  No   PK     n/a SW  PK    n/a     8        P-224   n/a
# cfgP224CPc0pk          Yes  Yes  PK     SW  SW  PK    Prg     0        P-224   128
# cfgP224CPc1pk          Yes  Yes  PK     SW  SW  PK    Prg     1        P-224   128
# cfgP224CPc2pk          Yes  Yes  PK     SW  SW  PK    Prg     2        P-224   128
# cfgP224CPc8pk          Yes  Yes  PK     SW  SW  PK    Prg     8        P-224   128
# cfgP256IPc0pk          Yes  No   PK     n/a SW  PK    n/a     0        P-256   n/a
# cfgP256IPc1pk          Yes  No   PK     n/a SW  PK    n/a     1        P-256   n/a
# cfgP256IPc2pk          Yes  No   PK     n/a SW  PK    n/a     2        P-256   n/a
# cfgP256IPc8pk          Yes  No   PK     n/a SW  PK    n/a     8        P-256   n/a
# cfgP256CPc0pk          Yes  Yes  PK     SW  SW  PK    Prg     0        P-256   128
# cfgP256CPc1pk          Yes  Yes  PK     SW  SW  PK    Prg     1        P-256   128
# cfgP256CPc2pk          Yes  Yes  PK     SW  SW  PK    Prg     2        P-256   128
# cfgP256CPc8pk          Yes  Yes  PK     SW  SW  PK    Prg     8        P-256   128
# cfgP384IPc0pk          Yes  No   PK     n/a SW  PK    n/a     0        P-384   n/a
# cfgP384IPc1pk          Yes  No   PK     n/a SW  PK    n/a     1        P-384   n/a
# cfgP384IPc2pk          Yes  No   PK     n/a SW  PK    n/a     2        P-384   n/a
# cfgP384IPc8pk          Yes  No   PK     n/a SW  PK    n/a     8        P-384   n/a
# cfgP384CPc0pk          Yes  Yes  PK     SW  SW  PK    Prg     0        P-384   128
# cfgP384CPc1pk          Yes  Yes  PK     SW  SW  PK    Prg     1        P-384   128

# cfgRSA2048pkcsIPc0pk   Yes  No   PK     n/a PK  PK    n/a     0        2048    n/a
# cfgRSA2048pkcsIPc1pk   Yes  No   PK     n/a PK  PK    n/a     1        2048    n/a
# cfgRSA2048pkcsIPc2pk   Yes  No   PK     n/a PK  PK    n/a     2        2048    n/a
# cfgRSA2048pkcsIPc8pk   Yes  No   PK     n/a PK  PK    n/a     8        2048    n/a
# cfgRSA2048pkcsCPc0pk   Yes  Yes  PK     PK  PK  PK    Prg     0        2048    128
# cfgRSA2048pkcsCPc1pk   Yes  Yes  PK     PK  PK  PK    Prg     1        2048    128
# cfgRSA2048pkcsCPc2pk   Yes  Yes  PK     PK  PK  PK    Prg     2        2048    128
# cfgRSA2048pkcsCPc8pk   Yes  Yes  PK     PK  PK  PK    Prg     8        2048    128
# cfgRSA3072pkcsIPc0pk   Yes  No   PK     n/a PK  PK    n/a     0        3072    n/a
# cfgRSA3072pkcsIPc1pk   Yes  No   PK     n/a PK  PK    n/a     1        3072    n/a
# cfgRSA3072pkcsIPc2pk   Yes  No   PK     n/a PK  PK    n/a     2        3072    n/a
# cfgRSA3072pkcsIPc8pk   Yes  No   PK     n/a PK  PK    n/a     8        3072    n/a
# cfgRSA3072pkcsCPc0pk   Yes  Yes  PK     PK  PK  PK    Prg     0        3072    128
# cfgRSA3072pkcsCPc1pk   Yes  Yes  PK     PK  PK  PK    Prg     1        3072    128
# cfgRSA3072pkcsCPc2pk   Yes  Yes  PK     PK  PK  PK    Prg     2        3072    128
# cfgRSA3072pkcsCPc8pk   Yes  Yes  PK     PK  PK  PK    Prg     8        3072    128
# cfgRSA4096pkcsIPc0pk   Yes  No   PK     n/a PK  PK    n/a     0        4096    n/a
# cfgRSA4096pkcsIPc1pk   Yes  No   PK     n/a PK  PK    n/a     1        4096    n/a
# cfgRSA4096pkcsIPc2pk   Yes  No   PK     n/a PK  PK    n/a     2        4096    n/a
# cfgRSA4096pkcsIPc8pk   Yes  No   PK     n/a PK  PK    n/a     8        4096    n/a
# cfgRSA4096pkcsCPc0pk   Yes  Yes  PK     PK  PK  PK    Prg     0        4096    128
# cfgRSA4096pkcsCPc1pk   Yes  Yes  PK     PK  PK  PK    Prg     1        4096    128
# cfgRSA4096pkcsCPc2pk   Yes  Yes  PK     PK  PK  PK    Prg     2        4096    128
# cfgRSA4096pkcsCPc8pk   Yes  Yes  PK     PK  PK  PK    Prg     8        4096    128

# cfgRSA2048pssIPc0pk    Yes  No   PK     n/a PK  PK    n/a     0        2048    n/a
# cfgRSA2048pssIPc1pk    Yes  No   PK     n/a PK  PK    n/a     1        2048    n/a
# cfgRSA2048pssIPc2pk    Yes  No   PK     n/a PK  PK    n/a     2        2048    n/a
# cfgRSA2048pssIPc8pk    Yes  No   PK     n/a PK  PK    n/a     8        2048    n/a
# cfgRSA2048pssCPc0pk    Yes  Yes  PK     PK  PK  PK    Prg     0        2048    128
# cfgRSA2048pssCPc1pk    Yes  Yes  PK     PK  PK  PK    Prg     1        2048    128
# cfgRSA2048pssCPc2pk    Yes  Yes  PK     PK  PK  PK    Prg     2        2048    128
# cfgRSA2048pssCPc8pk    Yes  Yes  PK     PK  PK  PK    Prg     8        2048    128
# cfgRSA3072pssIPc0pk    Yes  No   PK     n/a PK  PK    n/a     0        3072    n/a
# cfgRSA3072pssIPc1pk    Yes  No   PK     n/a PK  PK    n/a     1        3072    n/a
# cfgRSA3072pssIPc2pk    Yes  No   PK     n/a PK  PK    n/a     2        3072    n/a
# cfgRSA3072pssIPc8pk    Yes  No   PK     n/a PK  PK    n/a     8        3072    n/a
# cfgRSA3072pssCPc0pk    Yes  Yes  PK     PK  PK  PK    Prg     0        3072    128
# cfgRSA3072pssCPc1pk    Yes  Yes  PK     PK  PK  PK    Prg     1        3072    128
# cfgRSA3072pssCPc2pk    Yes  Yes  PK     PK  PK  PK    Prg     2        3072    128
# cfgRSA3072pssCPc8pk    Yes  Yes  PK     PK  PK  PK    Prg     8        3072    128
# cfgRSA4096pssIPc0pk    Yes  No   PK     n/a PK  PK    n/a     0        4096    n/a
# cfgRSA4096pssIPc1pk    Yes  No   PK     n/a PK  PK    n/a     1        4096    n/a
# cfgRSA4096pssIPc2pk    Yes  No   PK     n/a PK  PK    n/a     2        4096    n/a
# cfgRSA4096pssIPc8pk    Yes  No   PK     n/a PK  PK    n/a     8        4096    n/a
# cfgRSA4096pssCPc0pk    Yes  Yes  PK     PK  PK  PK    Prg     0        4096    128
# cfgRSA4096pssCPc1pk    Yes  Yes  PK     PK  PK  PK    Prg     1        4096    128
# cfgRSA4096pssCPc2pk    Yes  Yes  PK     PK  PK  PK    Prg     2        4096    128
# cfgRSA4096pssCPc8pk    Yes  Yes  PK     PK  PK  PK    Prg     8        4096    128

# cfgP384CPc2pk          Yes  Yes  PK     SW  SW  PK    Prg     2        P-384   128
# cfgP384CPc8pk          Yes  Yes  PK     SW  SW  PK    Prg     8        P-384   128
# cfgP521IPc0pk          Yes  No   PK     n/a SW  PK    n/a     0        P-521   n/a
# cfgP521IPc1pk          Yes  No   PK     n/a SW  PK    n/a     1        P-521   n/a
# cfgP521IPc2pk          Yes  No   PK     n/a SW  PK    n/a     2        P-521   n/a
# cfgP521IPc8pk          Yes  No   PK     n/a SW  PK    n/a     8        P-521   n/a
# cfgP521CPc0pk          Yes  Yes  PK     SW  SW  PK    Prg     0        P-521   128
# cfgP521CPc1pk          Yes  Yes  PK     SW  SW  PK    Prg     1        P-521   128
# cfgP521CPc2pk          Yes  Yes  PK     SW  SW  PK    Prg     2        P-521   128
# cfgP521CPc8pk          Yes  Yes  PK     SW  SW  PK    Prg     8        P-521   128
# cfgP224IPc0pe          Yes  No   PE     n/a PE  SW    n/a     0        P-224   n/a
# cfgP224IPc1pe          Yes  No   PE     n/a PE  SW    n/a     1        P-224   n/a
# cfgP224IPc2pe          Yes  No   PE     n/a PE  SW    n/a     2        P-224   n/a
# cfgP224IPc8pe          Yes  No   PE     n/a PE  SW    n/a     8        P-224   n/a
# cfgP224CPc0pe          Yes  Yes  PE     PE  PE  SW    Prg     0        P-224   128
# cfgP224CPc1pe          Yes  Yes  PE     PE  PE  SW    Prg     1        P-224   128
# cfgP224CPc2pe          Yes  Yes  PE     PE  PE  SW    Prg     2        P-224   128
# cfgP224CPc8pe          Yes  Yes  PE     PE  PE  SW    Prg     8        P-224   128
# cfgP224CXPc0pe         Yes  Yes  PE     PE  PE  SW    Prg     0        P-224   256
# cfgP224CXPc1pe         Yes  Yes  PE     PE  PE  SW    Prg     1        P-224   256
# cfgP224CXPc2pe         Yes  Yes  PE     PE  PE  SW    Prg     2        P-224   256
# cfgP224CXPc8pe         Yes  Yes  PE     PE  PE  SW    Prg     8        P-224   256
# cfgP256IPc0pe          Yes  No   PE     n/a PE  SW    n/a     0        P-256   n/a
# cfgP256IPc1pe          Yes  No   PE     n/a PE  SW    n/a     1        P-256   n/a
# cfgP256IPc2pe          Yes  No   PE     n/a PE  SW    n/a     2        P-256   n/a
# cfgP256IPc8pe          Yes  No   PE     n/a PE  SW    n/a     8        P-256   n/a
# cfgP256CPc0pe          Yes  Yes  PE     PE  PE  SW    Prg     0        P-256   128
# cfgP256CPc1pe          Yes  Yes  PE     PE  PE  SW    Prg     1        P-256   128
# cfgP256CPc2pe          Yes  Yes  PE     PE  PE  SW    Prg     2        P-256   128
# cfgP256CPc8pe          Yes  Yes  PE     PE  PE  SW    Prg     8        P-256   128
# cfgP256CXPc0pe         Yes  Yes  PE     PE  PE  SW    Prg     0        P-256   256
# cfgP256CXPc1pe         Yes  Yes  PE     PE  PE  SW    Prg     1        P-256   256
# cfgP256CXPc2pe         Yes  Yes  PE     PE  PE  SW    Prg     2        P-256   256
# cfgP256CXPc8pe         Yes  Yes  PE     PE  PE  SW    Prg     8        P-256   256
# cfgP224IPc0pepk        Yes  No   PE+PK  n/a PE  PK    n/a     0        P-224   n/a
# cfgP224IPc1pepk        Yes  No   PE+PK  n/a PE  PK    n/a     1        P-224   n/a
# cfgP224IPc2pepk        Yes  No   PE+PK  n/a PE  PK    n/a     2        P-224   n/a
# cfgP224IPc8pepk        Yes  No   PE+PK  n/a PE  PK    n/a     8        P-224   n/a
# cfgP224CPc0pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     0        P-224   128
# cfgP224CPc1pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     1        P-224   128
# cfgP224CPc2pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     2        P-224   128
# cfgP224CPc8pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     8        P-224   128
# cfgP224CXPc0pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     0        P-224   256
# cfgP224CXPc1pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     1        P-224   256
# cfgP224CXPc2pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     2        P-224   256
# cfgP224CXPc8pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     8        P-224   256
# cfgP256IPc0pepk        Yes  No   PE+PK  n/a PE  PK    n/a     0        P-256   n/a
# cfgP256IPc1pepk        Yes  No   PE+PK  n/a PE  PK    n/a     1        P-256   n/a
# cfgP256IPc2pepk        Yes  No   PE+PK  n/a PE  PK    n/a     2        P-256   n/a
# cfgP256IPc8pepk        Yes  No   PE+PK  n/a PE  PK    n/a     8        P-256   n/a
# cfgP256CPc0pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     0        P-256   128
# cfgP256CPc1pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     1        P-256   128
# cfgP256CPc2pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     2        P-256   128
# cfgP256CPc8pepk        Yes  Yes  PE+PK  PE  PE  PK    Prg     8        P-256   128
# cfgP256CXPc0pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     0        P-256   256
# cfgP256CXPc1pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     1        P-256   256
# cfgP256CXPc2pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     2        P-256   256
# cfgP256CXPc8pepk       Yes  Yes  PE+PK  PE  PE  PK    Prg     8        P-256   256

# cfgRSA2048pkcsIPc0pepk   Yes  No   PK     n/a PE  PK    n/a     0        2048    n/a
# cfgRSA2048pkcsIPc1pepk   Yes  No   PK     n/a PE  PK    n/a     1        2048    n/a
# cfgRSA2048pkcsIPc2pepk   Yes  No   PK     n/a PE  PK    n/a     2        2048    n/a
# cfgRSA2048pkcsIPc8pepk   Yes  No   PK     n/a PE  PK    n/a     8        2048    n/a
# cfgRSA2048pkcsCPc0pepk   Yes  Yes  PK     PE  PE  PK    Prg     0        2048    128
# cfgRSA2048pkcsCPc1pepk   Yes  Yes  PK     PE  PE  PK    Prg     1        2048    128
# cfgRSA2048pkcsCPc2pepk   Yes  Yes  PK     PE  PE  PK    Prg     2        2048    128
# cfgRSA2048pkcsCPc8pepk   Yes  Yes  PK     PE  PE  PK    Prg     8        2048    128
# cfgRSA3072pkcsIPc0pepk   Yes  No   PK     n/a PE  PK    n/a     0        3072    n/a
# cfgRSA3072pkcsIPc1pepk   Yes  No   PK     n/a PE  PK    n/a     1        3072    n/a
# cfgRSA3072pkcsIPc2pepk   Yes  No   PK     n/a PE  PK    n/a     2        3072    n/a
# cfgRSA3072pkcsIPc8pepk   Yes  No   PK     n/a PE  PK    n/a     8        3072    n/a
# cfgRSA3072pkcsCPc0pepk   Yes  Yes  PK     PE  PE  PK    Prg     0        3072    128
# cfgRSA3072pkcsCPc1pepk   Yes  Yes  PK     PE  PE  PK    Prg     1        3072    128
# cfgRSA3072pkcsCPc2pepk   Yes  Yes  PK     PE  PE  PK    Prg     2        3072    128
# cfgRSA3072pkcsCPc8pepk   Yes  Yes  PK     PE  PE  PK    Prg     8        3072    128
# cfgRSA4096pkcsIPc0pepk   Yes  No   PK     n/a PE  PK    n/a     0        4096    n/a
# cfgRSA4096pkcsIPc1pepk   Yes  No   PK     n/a PE  PK    n/a     1        4096    n/a
# cfgRSA4096pkcsIPc2pepk   Yes  No   PK     n/a PE  PK    n/a     2        4096    n/a
# cfgRSA4096pkcsIPc8pepk   Yes  No   PK     n/a PE  PK    n/a     8        4096    n/a
# cfgRSA4096pkcsCPc0pepk   Yes  Yes  PK     PE  PE  PK    Prg     0        4096    128
# cfgRSA4096pkcsCPc1pepk   Yes  Yes  PK     PE  PE  PK    Prg     1        4096    128
# cfgRSA4096pkcsCPc2pepk   Yes  Yes  PK     PE  PE  PK    Prg     2        4096    128
# cfgRSA4096pkcsCPc8pepk   Yes  Yes  PK     PE  PE  PK    Prg     8        4096    128



ACLOCAL_AMFLAGS = -I ../../m4
AM_CFLAGS = -std=gnu99 -Wall -pedantic

top_src = $(top_srcdir)/../..

#
# Configuration Options:
#
# ENABLE_SBSW
#    Indicates that the software-only configuration is selected
# ENABLE_SBSM
#    Indicates that the Security Module (HW) configuration is selected for
#    symmetric and asymmetric crypto operations.
# ENABLE_SBPK
#    Indicates that the Public Key Accelerator/Processor (HW) configuration
#    is selected for asymmetric crypto operations and that the symmetric crypto
#    operations are performed via software.
# ENABLE_SBPE
#    Indicates that the Packet Engine (HW) configuration is selected for
#    symmetric crypto operations and that the asymmetric crypto operations are
#    performed via software.
# ENABLE_SBPEPK
#    Indicates that the Packet Engine (HW) configuration is selected for
#    symmetric crypto operations and the Public Key Accelerator/Processor (HW)
#    configuration for asymmetric crypto operations.
#
# ENABLE_BARE
#    Indicates that the barebones-specific configuration is selected
# ENABLE_CUSTOM
#    Indicates that the customer-specific configuration is selected
#
# Note: ENABLE_BARE/CUSTOM/VERSATILE are multiple-exclusive

#
# ENABLE_DEBUG
#    Enable debugging
# ENABLE_STACK
#    Enable stack tracing
# ENABLE_HEAP
#    Enable heap tracing
# ENABLE_PERF
#    Enable performance info
# ENABLE_COVERAGE
#    Enable coverage tracing
# ENABLE_POLLING
#    Enable polling instead of interrupt
# ENABLE_SBSIM_TIME
#    Enable sbsim_(decrypt_and_)verify time reporting
#

if ENABLE_BARE
CPPFLAGS += -DCFG_ENABLE_TARGET_BARE
ABSTRACTION_BASICDEFS := v4_bare
ABSTRACTION_CLIB := v4_bare

endif
if ENABLE_CUSTOM
CPPFLAGS += -DCFG_ENABLE_TARGET_CUSTOM
ABSTRACTION_BASICDEFS := v4_bare
ABSTRACTION_CLIB := v4_bare

endif

ABSTRACTION_BASICDEFS ?= v4/Basic_Defs
ABSTRACTION_CLIB ?= v4/CLib_Abstraction

if ENABLE_STACK
CFLAGS += -finstrument-functions
CPPFLAGS += -DSTACK_MEASUREMENT -DCFG_ENABLE_STACK

endif
if ENABLE_HEAP
CPPFLAGS += -DHEAP_MEASUREMENT -DCFG_ENABLE_HEAP

endif
if ENABLE_SBSIM_TIME
CPPFLAGS += -DSBSIM_TIME_INFO

endif
if ENABLE_GCC_STRICT_WARNINGS
AM_CFLAGS += -W -Wall -Wextra -Wshadow -Wvla -Wsign-conversion -Wconversion -Wcast-qual -Wcast-align -Wswitch-enum -Wduplicated-cond -Wmissing-prototypes -Wlogical-op -Wjump-misses-init -Wdouble-promotion -Wformat=2

endif
if ENABLE_DEBUG
# Debugging enabled.
CPPFLAGS += -DCFG_ENABLE_DEBUG
else
# No debugging (performance build)
CPPFLAGS += -DCFG_IMPLDEFS_NO_DEBUG
endif

if ENABLE_COVERAGE
CPPFLAGS += -DGCOV_PROFILE -DCFG_ENABLE_COVERAGE
LIBS += -lgcov
if ENABLE_DEBUG
# With debugging, test coverage analysis requires enabling additional flag to
# dump coverage reports prior abnormal exit
CPPFLAGS += -DDEBUG_CF_ABORT_WRITE_PROFILE
endif
endif


CONFIGURATION_INCLUDES = \
    -I$(top_src)/SBLib/Config \
    -I$(top_src)/Config


if ENABLE_BARE
DMARES_INCLUDE = -I$(top_src)/Integration/DMARes_Record_bare/incl
else
DMARES_INCLUDE = -I$(top_src)/Integration/DMARes_Record/incl
endif

FRAMEWORK_HEADER_LIST = \
    $(top_src)/Framework/PUBDEFS/incl/public_defs.h

include_HEADERS =

# Flags for hardware assisted compilations
LIBSB_GENERAL_HW =
OPT_LIBDEBUG_A = libdebug.a




SECUREBOOTSIM_PROGRAM_NAMES_SW = \
    securebootsim_cfgP224IPc0sw \
    securebootsim_cfgP224IPc1sw \
    securebootsim_cfgP224IPc2sw \
    securebootsim_cfgP224IPc8sw \
    securebootsim_cfgP224CPc0sw \
    securebootsim_cfgP224CPc1sw \
    securebootsim_cfgP224CPc2sw \
    securebootsim_cfgP224CPc8sw \
    securebootsim_cfgP224CXPc0sw \
    securebootsim_cfgP224CXPc1sw \
    securebootsim_cfgP224CXPc2sw \
    securebootsim_cfgP224CXPc8sw \
    securebootsim_cfgP224CPKc0sw \
    securebootsim_cfgP224CPKc1sw \
    securebootsim_cfgP224CPKc2sw \
    securebootsim_cfgP224CPKc8sw \
    securebootsim_cfgP224CXPKc0sw \
    securebootsim_cfgP224CXPKc1sw \
    securebootsim_cfgP224CXPKc2sw \
    securebootsim_cfgP224CXPKc8sw \
    securebootsim_cfgP256IPc0sw \
    securebootsim_cfgP256IPc1sw \
    securebootsim_cfgP256IPc2sw \
    securebootsim_cfgP256IPc8sw \
    securebootsim_cfgP256CPc0sw \
    securebootsim_cfgP256CPc1sw \
    securebootsim_cfgP256CPc2sw \
    securebootsim_cfgP256CPc8sw \
    securebootsim_cfgP256CXPc0sw \
    securebootsim_cfgP256CXPc1sw \
    securebootsim_cfgP256CXPc2sw \
    securebootsim_cfgP256CXPc8sw \
    securebootsim_cfgP256CPKc0sw \
    securebootsim_cfgP256CPKc1sw \
    securebootsim_cfgP256CPKc2sw \
    securebootsim_cfgP256CPKc8sw \
    securebootsim_cfgP256CXPKc0sw \
    securebootsim_cfgP256CXPKc1sw \
    securebootsim_cfgP256CXPKc2sw \
    securebootsim_cfgP256CXPKc8sw \
    securebootsim_cfgP384IPc0sw \
    securebootsim_cfgP384IPc1sw \
    securebootsim_cfgP384IPc2sw \
    securebootsim_cfgP384IPc8sw \
    securebootsim_cfgP384CPc0sw \
    securebootsim_cfgP384CPc1sw \
    securebootsim_cfgP384CPc2sw \
    securebootsim_cfgP384CPc8sw \
    securebootsim_cfgP384CXPc0sw \
    securebootsim_cfgP384CXPc1sw \
    securebootsim_cfgP384CXPc2sw \
    securebootsim_cfgP384CXPc8sw \
    securebootsim_cfgP384CPKc0sw \
    securebootsim_cfgP384CPKc1sw \
    securebootsim_cfgP384CPKc2sw \
    securebootsim_cfgP384CPKc8sw \
    securebootsim_cfgP384CXPKc0sw \
    securebootsim_cfgP384CXPKc1sw \
    securebootsim_cfgP384CXPKc2sw \
    securebootsim_cfgP384CXPKc8sw \
    securebootsim_cfgP521IPc0sw \
    securebootsim_cfgP521IPc1sw \
    securebootsim_cfgP521IPc2sw \
    securebootsim_cfgP521IPc8sw \
    securebootsim_cfgP521CPc0sw \
    securebootsim_cfgP521CPc1sw \
    securebootsim_cfgP521CPc2sw \
    securebootsim_cfgP521CPc8sw \
    securebootsim_cfgP521CXPc0sw \
    securebootsim_cfgP521CXPc1sw \
    securebootsim_cfgP521CXPc2sw \
    securebootsim_cfgP521CXPc8sw \
    securebootsim_cfgP521CPKc0sw \
    securebootsim_cfgP521CPKc1sw \
    securebootsim_cfgP521CPKc2sw \
    securebootsim_cfgP521CPKc8sw \
    securebootsim_cfgP521CXPKc0sw \
    securebootsim_cfgP521CXPKc1sw \
    securebootsim_cfgP521CXPKc2sw \
    securebootsim_cfgP521CXPKc8sw \
    securebootsim_cfgRSA2048pkcsIPc0sw \
    securebootsim_cfgRSA2048pkcsIPc1sw \
    securebootsim_cfgRSA2048pkcsIPc2sw \
    securebootsim_cfgRSA2048pkcsIPc8sw \
    securebootsim_cfgRSA2048pkcsCPc0sw \
    securebootsim_cfgRSA2048pkcsCPc1sw \
    securebootsim_cfgRSA2048pkcsCPc2sw \
    securebootsim_cfgRSA2048pkcsCPc8sw \
    securebootsim_cfgRSA2048pkcsCXPc0sw \
    securebootsim_cfgRSA2048pkcsCXPc1sw \
    securebootsim_cfgRSA2048pkcsCXPc2sw \
    securebootsim_cfgRSA2048pkcsCXPc8sw \
    securebootsim_cfgRSA2048pkcsCPKc0sw \
    securebootsim_cfgRSA2048pkcsCPKc1sw \
    securebootsim_cfgRSA2048pkcsCPKc2sw \
    securebootsim_cfgRSA2048pkcsCPKc8sw \
    securebootsim_cfgRSA2048pkcsCXPKc0sw \
    securebootsim_cfgRSA2048pkcsCXPKc1sw \
    securebootsim_cfgRSA2048pkcsCXPKc2sw \
    securebootsim_cfgRSA2048pkcsCXPKc8sw \
    securebootsim_cfgRSA3072pkcsIPc0sw \
    securebootsim_cfgRSA3072pkcsIPc1sw \
    securebootsim_cfgRSA3072pkcsIPc2sw \
    securebootsim_cfgRSA3072pkcsIPc8sw \
    securebootsim_cfgRSA3072pkcsCPc0sw \
    securebootsim_cfgRSA3072pkcsCPc1sw \
    securebootsim_cfgRSA3072pkcsCPc2sw \
    securebootsim_cfgRSA3072pkcsCPc8sw \
    securebootsim_cfgRSA3072pkcsCXPc0sw \
    securebootsim_cfgRSA3072pkcsCXPc1sw \
    securebootsim_cfgRSA3072pkcsCXPc2sw \
    securebootsim_cfgRSA3072pkcsCXPc8sw \
    securebootsim_cfgRSA3072pkcsCPKc0sw \
    securebootsim_cfgRSA3072pkcsCPKc1sw \
    securebootsim_cfgRSA3072pkcsCPKc2sw \
    securebootsim_cfgRSA3072pkcsCPKc8sw \
    securebootsim_cfgRSA3072pkcsCXPKc0sw \
    securebootsim_cfgRSA3072pkcsCXPKc1sw \
    securebootsim_cfgRSA3072pkcsCXPKc2sw \
    securebootsim_cfgRSA3072pkcsCXPKc8sw \
    securebootsim_cfgRSA4096pkcsIPc0sw \
    securebootsim_cfgRSA4096pkcsIPc1sw \
    securebootsim_cfgRSA4096pkcsIPc2sw \
    securebootsim_cfgRSA4096pkcsIPc8sw \
    securebootsim_cfgRSA4096pkcsCPc0sw \
    securebootsim_cfgRSA4096pkcsCPc1sw \
    securebootsim_cfgRSA4096pkcsCPc2sw \
    securebootsim_cfgRSA4096pkcsCPc8sw \
    securebootsim_cfgRSA4096pkcsCXPc0sw \
    securebootsim_cfgRSA4096pkcsCXPc1sw \
    securebootsim_cfgRSA4096pkcsCXPc2sw \
    securebootsim_cfgRSA4096pkcsCXPc8sw \
    securebootsim_cfgRSA4096pkcsCPKc0sw \
    securebootsim_cfgRSA4096pkcsCPKc1sw \
    securebootsim_cfgRSA4096pkcsCPKc2sw \
    securebootsim_cfgRSA4096pkcsCPKc8sw \
    securebootsim_cfgRSA4096pkcsCXPKc0sw \
    securebootsim_cfgRSA4096pkcsCXPKc1sw \
    securebootsim_cfgRSA4096pkcsCXPKc2sw \
    securebootsim_cfgRSA4096pkcsCXPKc8sw \
    securebootsim_cfgRSA2048pssIPc0sw \
    securebootsim_cfgRSA2048pssIPc1sw \
    securebootsim_cfgRSA2048pssIPc2sw \
    securebootsim_cfgRSA2048pssIPc8sw \
    securebootsim_cfgRSA2048pssCPc0sw \
    securebootsim_cfgRSA2048pssCPc1sw \
    securebootsim_cfgRSA2048pssCPc2sw \
    securebootsim_cfgRSA2048pssCPc8sw \
    securebootsim_cfgRSA2048pssCXPc0sw \
    securebootsim_cfgRSA2048pssCXPc1sw \
    securebootsim_cfgRSA2048pssCXPc2sw \
    securebootsim_cfgRSA2048pssCXPc8sw \
    securebootsim_cfgRSA2048pssCPKc0sw \
    securebootsim_cfgRSA2048pssCPKc1sw \
    securebootsim_cfgRSA2048pssCPKc2sw \
    securebootsim_cfgRSA2048pssCPKc8sw \
    securebootsim_cfgRSA2048pssCXPKc0sw \
    securebootsim_cfgRSA2048pssCXPKc1sw \
    securebootsim_cfgRSA2048pssCXPKc2sw \
    securebootsim_cfgRSA2048pssCXPKc8sw \
    securebootsim_cfgRSA3072pssIPc0sw \
    securebootsim_cfgRSA3072pssIPc1sw \
    securebootsim_cfgRSA3072pssIPc2sw \
    securebootsim_cfgRSA3072pssIPc8sw \
    securebootsim_cfgRSA3072pssCPc0sw \
    securebootsim_cfgRSA3072pssCPc1sw \
    securebootsim_cfgRSA3072pssCPc2sw \
    securebootsim_cfgRSA3072pssCPc8sw \
    securebootsim_cfgRSA3072pssCXPc0sw \
    securebootsim_cfgRSA3072pssCXPc1sw \
    securebootsim_cfgRSA3072pssCXPc2sw \
    securebootsim_cfgRSA3072pssCXPc8sw \
    securebootsim_cfgRSA3072pssCPKc0sw \
    securebootsim_cfgRSA3072pssCPKc1sw \
    securebootsim_cfgRSA3072pssCPKc2sw \
    securebootsim_cfgRSA3072pssCPKc8sw \
    securebootsim_cfgRSA3072pssCXPKc0sw \
    securebootsim_cfgRSA3072pssCXPKc1sw \
    securebootsim_cfgRSA3072pssCXPKc2sw \
    securebootsim_cfgRSA3072pssCXPKc8sw \
    securebootsim_cfgRSA4096pssIPc0sw \
    securebootsim_cfgRSA4096pssIPc1sw \
    securebootsim_cfgRSA4096pssIPc2sw \
    securebootsim_cfgRSA4096pssIPc8sw \
    securebootsim_cfgRSA4096pssCPc0sw \
    securebootsim_cfgRSA4096pssCPc1sw \
    securebootsim_cfgRSA4096pssCPc2sw \
    securebootsim_cfgRSA4096pssCPc8sw \
    securebootsim_cfgRSA4096pssCXPc0sw \
    securebootsim_cfgRSA4096pssCXPc1sw \
    securebootsim_cfgRSA4096pssCXPc2sw \
    securebootsim_cfgRSA4096pssCXPc8sw \
    securebootsim_cfgRSA4096pssCPKc0sw \
    securebootsim_cfgRSA4096pssCPKc1sw \
    securebootsim_cfgRSA4096pssCPKc2sw \
    securebootsim_cfgRSA4096pssCPKc8sw \
    securebootsim_cfgRSA4096pssCXPKc0sw \
    securebootsim_cfgRSA4096pssCXPKc1sw \
    securebootsim_cfgRSA4096pssCXPKc2sw \
    securebootsim_cfgRSA4096pssCXPKc8sw

SECUREBOOTSIM_PROGRAM_NAMES_SM = \
    securebootsim_cfgP224IPc0sm \
    securebootsim_cfgP224IPc1sm \
    securebootsim_cfgP224IPc2sm \
    securebootsim_cfgP224IPc8sm \
    securebootsim_cfgP224CPc0sm \
    securebootsim_cfgP224CPc1sm \
    securebootsim_cfgP224CPc2sm \
    securebootsim_cfgP224CPc8sm \
    securebootsim_cfgP224CXPc0sm \
    securebootsim_cfgP224CXPc1sm \
    securebootsim_cfgP224CXPc2sm \
    securebootsim_cfgP224CXPc8sm \
    securebootsim_cfgP224CNc0sm \
    securebootsim_cfgP224CNc1sm \
    securebootsim_cfgP224CNc2sm \
    securebootsim_cfgP224CNc8sm \
    securebootsim_cfgP224CXNc0sm \
    securebootsim_cfgP224CXNc1sm \
    securebootsim_cfgP224CXNc2sm \
    securebootsim_cfgP224CXNc8sm \
    securebootsim_cfgP224CNKc0sm \
    securebootsim_cfgP224CNKc1sm \
    securebootsim_cfgP224CNKc2sm \
    securebootsim_cfgP224CNKc8sm \
    securebootsim_cfgP224CXNKc0sm \
    securebootsim_cfgP224CXNKc1sm \
    securebootsim_cfgP224CXNKc2sm \
    securebootsim_cfgP224CXNKc8sm \
    securebootsim_cfgP256IPc0sm \
    securebootsim_cfgP256IPc1sm \
    securebootsim_cfgP256IPc2sm \
    securebootsim_cfgP256IPc8sm \
    securebootsim_cfgP256CPc0sm \
    securebootsim_cfgP256CPc1sm \
    securebootsim_cfgP256CPc2sm \
    securebootsim_cfgP256CPc8sm \
    securebootsim_cfgP256CXPc0sm \
    securebootsim_cfgP256CXPc1sm \
    securebootsim_cfgP256CXPc2sm \
    securebootsim_cfgP256CXPc8sm \
    securebootsim_cfgP256CNc0sm \
    securebootsim_cfgP256CNc1sm \
    securebootsim_cfgP256CNc2sm \
    securebootsim_cfgP256CNc8sm \
    securebootsim_cfgP256CXNc0sm \
    securebootsim_cfgP256CXNc1sm \
    securebootsim_cfgP256CXNc2sm \
    securebootsim_cfgP256CXNc8sm \
    securebootsim_cfgP256CNKc0sm \
    securebootsim_cfgP256CNKc1sm \
    securebootsim_cfgP256CNKc2sm \
    securebootsim_cfgP256CNKc8sm \
    securebootsim_cfgP256CXNKc0sm \
    securebootsim_cfgP256CXNKc1sm \
    securebootsim_cfgP256CXNKc2sm \
    securebootsim_cfgP256CXNKc8sm \
    securebootsim_cfgP384IPc0sm \
    securebootsim_cfgP384IPc1sm \
    securebootsim_cfgP384IPc2sm \
    securebootsim_cfgP384IPc8sm \
    securebootsim_cfgP384CPc0sm \
    securebootsim_cfgP384CPc1sm \
    securebootsim_cfgP384CPc2sm \
    securebootsim_cfgP384CPc8sm \
    securebootsim_cfgP384CXPc0sm \
    securebootsim_cfgP384CXPc1sm \
    securebootsim_cfgP384CXPc2sm \
    securebootsim_cfgP384CXPc8sm \
    securebootsim_cfgP384CNc0sm \
    securebootsim_cfgP384CNc1sm \
    securebootsim_cfgP384CNc2sm \
    securebootsim_cfgP384CNc8sm \
    securebootsim_cfgP384CXNc0sm \
    securebootsim_cfgP384CXNc1sm \
    securebootsim_cfgP384CXNc2sm \
    securebootsim_cfgP384CXNc8sm \
    securebootsim_cfgP384CNKc0sm \
    securebootsim_cfgP384CNKc1sm \
    securebootsim_cfgP384CNKc2sm \
    securebootsim_cfgP384CNKc8sm \
    securebootsim_cfgP384CXNKc0sm \
    securebootsim_cfgP384CXNKc1sm \
    securebootsim_cfgP384CXNKc2sm \
    securebootsim_cfgP384CXNKc8sm \
    securebootsim_cfgP521IPc0sm \
    securebootsim_cfgP521IPc1sm \
    securebootsim_cfgP521IPc2sm \
    securebootsim_cfgP521IPc8sm \
    securebootsim_cfgP521CPc0sm \
    securebootsim_cfgP521CPc1sm \
    securebootsim_cfgP521CPc2sm \
    securebootsim_cfgP521CPc8sm \
    securebootsim_cfgP521CXPc0sm \
    securebootsim_cfgP521CXPc1sm \
    securebootsim_cfgP521CXPc2sm \
    securebootsim_cfgP521CXPc8sm \
    securebootsim_cfgP521CNc0sm \
    securebootsim_cfgP521CNc1sm \
    securebootsim_cfgP521CNc2sm \
    securebootsim_cfgP521CNc8sm \
    securebootsim_cfgP521CXNc0sm \
    securebootsim_cfgP521CXNc1sm \
    securebootsim_cfgP521CXNc2sm \
    securebootsim_cfgP521CXNc8sm \
    securebootsim_cfgP521CNKc0sm \
    securebootsim_cfgP521CNKc1sm \
    securebootsim_cfgP521CNKc2sm \
    securebootsim_cfgP521CNKc8sm \
    securebootsim_cfgP521CXNKc0sm \
    securebootsim_cfgP521CXNKc1sm \
    securebootsim_cfgP521CXNKc2sm \
    securebootsim_cfgP521CXNKc8sm \
    securebootsim_cfgRSA2048pkcsIPc0sm \
    securebootsim_cfgRSA2048pkcsIPc1sm \
    securebootsim_cfgRSA2048pkcsIPc2sm \
    securebootsim_cfgRSA2048pkcsIPc8sm \
    securebootsim_cfgRSA2048pkcsCPc0sm \
    securebootsim_cfgRSA2048pkcsCPc1sm \
    securebootsim_cfgRSA2048pkcsCPc2sm \
    securebootsim_cfgRSA2048pkcsCPc8sm \
    securebootsim_cfgRSA2048pkcsCXPc0sm \
    securebootsim_cfgRSA2048pkcsCXPc1sm \
    securebootsim_cfgRSA2048pkcsCXPc2sm \
    securebootsim_cfgRSA2048pkcsCXPc8sm \
    securebootsim_cfgRSA2048pkcsCNc0sm \
    securebootsim_cfgRSA2048pkcsCNc1sm \
    securebootsim_cfgRSA2048pkcsCNc2sm \
    securebootsim_cfgRSA2048pkcsCNc8sm \
    securebootsim_cfgRSA2048pkcsCXNc0sm \
    securebootsim_cfgRSA2048pkcsCXNc1sm \
    securebootsim_cfgRSA2048pkcsCXNc2sm \
    securebootsim_cfgRSA2048pkcsCXNc8sm \
    securebootsim_cfgRSA2048pkcsCNKc0sm \
    securebootsim_cfgRSA2048pkcsCNKc1sm \
    securebootsim_cfgRSA2048pkcsCNKc2sm \
    securebootsim_cfgRSA2048pkcsCNKc8sm \
    securebootsim_cfgRSA2048pkcsCXNKc0sm \
    securebootsim_cfgRSA2048pkcsCXNKc1sm \
    securebootsim_cfgRSA2048pkcsCXNKc2sm \
    securebootsim_cfgRSA2048pkcsCXNKc8sm \
    securebootsim_cfgRSA3072pkcsIPc0sm \
    securebootsim_cfgRSA3072pkcsIPc1sm \
    securebootsim_cfgRSA3072pkcsIPc2sm \
    securebootsim_cfgRSA3072pkcsIPc8sm \
    securebootsim_cfgRSA3072pkcsCPc0sm \
    securebootsim_cfgRSA3072pkcsCPc1sm \
    securebootsim_cfgRSA3072pkcsCPc2sm \
    securebootsim_cfgRSA3072pkcsCPc8sm \
    securebootsim_cfgRSA3072pkcsCXPc0sm \
    securebootsim_cfgRSA3072pkcsCXPc1sm \
    securebootsim_cfgRSA3072pkcsCXPc2sm \
    securebootsim_cfgRSA3072pkcsCXPc8sm \
    securebootsim_cfgRSA3072pkcsCNc0sm \
    securebootsim_cfgRSA3072pkcsCNc1sm \
    securebootsim_cfgRSA3072pkcsCNc2sm \
    securebootsim_cfgRSA3072pkcsCNc8sm \
    securebootsim_cfgRSA3072pkcsCXNc0sm \
    securebootsim_cfgRSA3072pkcsCXNc1sm \
    securebootsim_cfgRSA3072pkcsCXNc2sm \
    securebootsim_cfgRSA3072pkcsCXNc8sm \
    securebootsim_cfgRSA3072pkcsCNKc0sm \
    securebootsim_cfgRSA3072pkcsCNKc1sm \
    securebootsim_cfgRSA3072pkcsCNKc2sm \
    securebootsim_cfgRSA3072pkcsCNKc8sm \
    securebootsim_cfgRSA3072pkcsCXNKc0sm \
    securebootsim_cfgRSA3072pkcsCXNKc1sm \
    securebootsim_cfgRSA3072pkcsCXNKc2sm \
    securebootsim_cfgRSA3072pkcsCXNKc8sm \
    securebootsim_cfgRSA2048pssIPc0sm \
    securebootsim_cfgRSA2048pssIPc1sm \
    securebootsim_cfgRSA2048pssIPc2sm \
    securebootsim_cfgRSA2048pssIPc8sm \
    securebootsim_cfgRSA2048pssCPc0sm \
    securebootsim_cfgRSA2048pssCPc1sm \
    securebootsim_cfgRSA2048pssCPc2sm \
    securebootsim_cfgRSA2048pssCPc8sm \
    securebootsim_cfgRSA2048pssCXPc0sm \
    securebootsim_cfgRSA2048pssCXPc1sm \
    securebootsim_cfgRSA2048pssCXPc2sm \
    securebootsim_cfgRSA2048pssCXPc8sm \
    securebootsim_cfgRSA2048pssCNc0sm \
    securebootsim_cfgRSA2048pssCNc1sm \
    securebootsim_cfgRSA2048pssCNc2sm \
    securebootsim_cfgRSA2048pssCNc8sm \
    securebootsim_cfgRSA2048pssCXNc0sm \
    securebootsim_cfgRSA2048pssCXNc1sm \
    securebootsim_cfgRSA2048pssCXNc2sm \
    securebootsim_cfgRSA2048pssCXNc8sm \
    securebootsim_cfgRSA2048pssCNKc0sm \
    securebootsim_cfgRSA2048pssCNKc1sm \
    securebootsim_cfgRSA2048pssCNKc2sm \
    securebootsim_cfgRSA2048pssCNKc8sm \
    securebootsim_cfgRSA2048pssCXNKc0sm \
    securebootsim_cfgRSA2048pssCXNKc1sm \
    securebootsim_cfgRSA2048pssCXNKc2sm \
    securebootsim_cfgRSA2048pssCXNKc8sm \
    securebootsim_cfgRSA3072pssIPc0sm \
    securebootsim_cfgRSA3072pssIPc1sm \
    securebootsim_cfgRSA3072pssIPc2sm \
    securebootsim_cfgRSA3072pssIPc8sm \
    securebootsim_cfgRSA3072pssCPc0sm \
    securebootsim_cfgRSA3072pssCPc1sm \
    securebootsim_cfgRSA3072pssCPc2sm \
    securebootsim_cfgRSA3072pssCPc8sm \
    securebootsim_cfgRSA3072pssCXPc0sm \
    securebootsim_cfgRSA3072pssCXPc1sm \
    securebootsim_cfgRSA3072pssCXPc2sm \
    securebootsim_cfgRSA3072pssCXPc8sm \
    securebootsim_cfgRSA3072pssCNc0sm \
    securebootsim_cfgRSA3072pssCNc1sm \
    securebootsim_cfgRSA3072pssCNc2sm \
    securebootsim_cfgRSA3072pssCNc8sm \
    securebootsim_cfgRSA3072pssCXNc0sm \
    securebootsim_cfgRSA3072pssCXNc1sm \
    securebootsim_cfgRSA3072pssCXNc2sm \
    securebootsim_cfgRSA3072pssCXNc8sm \
    securebootsim_cfgRSA3072pssCNKc0sm \
    securebootsim_cfgRSA3072pssCNKc1sm \
    securebootsim_cfgRSA3072pssCNKc2sm \
    securebootsim_cfgRSA3072pssCNKc8sm \
    securebootsim_cfgRSA3072pssCXNKc0sm \
    securebootsim_cfgRSA3072pssCXNKc1sm \
    securebootsim_cfgRSA3072pssCXNKc2sm \
    securebootsim_cfgRSA3072pssCXNKc8sm

SECUREBOOTSIM_PROGRAM_NAMES_PE = \
    securebootsim_cfgP224IPc0pe \
    securebootsim_cfgP224IPc1pe \
    securebootsim_cfgP224IPc2pe \
    securebootsim_cfgP224IPc8pe \
    securebootsim_cfgP224CPc0pe \
    securebootsim_cfgP224CPc1pe \
    securebootsim_cfgP224CPc2pe \
    securebootsim_cfgP224CPc8pe \
    securebootsim_cfgP224CXPc0pe \
    securebootsim_cfgP224CXPc1pe \
    securebootsim_cfgP224CXPc2pe \
    securebootsim_cfgP224CXPc8pe \
    securebootsim_cfgP256IPc0pe \
    securebootsim_cfgP256IPc1pe \
    securebootsim_cfgP256IPc2pe \
    securebootsim_cfgP256IPc8pe \
    securebootsim_cfgP256CPc0pe \
    securebootsim_cfgP256CPc1pe \
    securebootsim_cfgP256CPc2pe \
    securebootsim_cfgP256CPc8pe \
    securebootsim_cfgP256CXPc0pe \
    securebootsim_cfgP256CXPc1pe \
    securebootsim_cfgP256CXPc2pe \
    securebootsim_cfgP256CXPc8pe

SECUREBOOTSIM_PROGRAM_NAMES_PEPK = \
    securebootsim_cfgP224IPc0pepk \
    securebootsim_cfgP224IPc1pepk \
    securebootsim_cfgP224IPc2pepk \
    securebootsim_cfgP224IPc8pepk \
    securebootsim_cfgP224CPc0pepk \
    securebootsim_cfgP224CPc1pepk \
    securebootsim_cfgP224CPc2pepk \
    securebootsim_cfgP224CPc8pepk \
    securebootsim_cfgP224CXPc0pepk \
    securebootsim_cfgP224CXPc1pepk \
    securebootsim_cfgP224CXPc2pepk \
    securebootsim_cfgP224CXPc8pepk \
    securebootsim_cfgP256IPc0pepk \
    securebootsim_cfgP256IPc1pepk \
    securebootsim_cfgP256IPc2pepk \
    securebootsim_cfgP256IPc8pepk \
    securebootsim_cfgP256CPc0pepk \
    securebootsim_cfgP256CPc1pepk \
    securebootsim_cfgP256CPc2pepk \
    securebootsim_cfgP256CPc8pepk \
    securebootsim_cfgP256CXPc0pepk \
    securebootsim_cfgP256CXPc1pepk \
    securebootsim_cfgP256CXPc2pepk \
    securebootsim_cfgP256CXPc8pepk \
    securebootsim_cfgRSA2048pkcsIPc0pepk \
    securebootsim_cfgRSA2048pkcsIPc1pepk \
    securebootsim_cfgRSA2048pkcsIPc2pepk \
    securebootsim_cfgRSA2048pkcsIPc8pepk \
    securebootsim_cfgRSA2048pkcsCPc0pepk \
    securebootsim_cfgRSA2048pkcsCPc1pepk \
    securebootsim_cfgRSA2048pkcsCPc2pepk \
    securebootsim_cfgRSA2048pkcsCPc8pepk \
    securebootsim_cfgRSA2048pkcsCXPc0pepk \
    securebootsim_cfgRSA2048pkcsCXPc1pepk \
    securebootsim_cfgRSA2048pkcsCXPc2pepk \
    securebootsim_cfgRSA2048pkcsCXPc8pepk \
    securebootsim_cfgRSA3072pkcsIPc0pepk \
    securebootsim_cfgRSA3072pkcsIPc1pepk \
    securebootsim_cfgRSA3072pkcsIPc2pepk \
    securebootsim_cfgRSA3072pkcsIPc8pepk \
    securebootsim_cfgRSA3072pkcsCPc0pepk \
    securebootsim_cfgRSA3072pkcsCPc1pepk \
    securebootsim_cfgRSA3072pkcsCPc2pepk \
    securebootsim_cfgRSA3072pkcsCPc8pepk \
    securebootsim_cfgRSA3072pkcsCXPc0pepk \
    securebootsim_cfgRSA3072pkcsCXPc1pepk \
    securebootsim_cfgRSA3072pkcsCXPc2pepk \
    securebootsim_cfgRSA3072pkcsCXPc8pepk \
    securebootsim_cfgRSA4096pkcsIPc0pepk \
    securebootsim_cfgRSA4096pkcsIPc1pepk \
    securebootsim_cfgRSA4096pkcsIPc2pepk \
    securebootsim_cfgRSA4096pkcsIPc8pepk \
    securebootsim_cfgRSA4096pkcsCPc0pepk \
    securebootsim_cfgRSA4096pkcsCPc1pepk \
    securebootsim_cfgRSA4096pkcsCPc2pepk \
    securebootsim_cfgRSA4096pkcsCPc8pepk \
    securebootsim_cfgRSA4096pkcsCXPc0pepk \
    securebootsim_cfgRSA4096pkcsCXPc1pepk \
    securebootsim_cfgRSA4096pkcsCXPc2pepk \
    securebootsim_cfgRSA4096pkcsCXPc8pepk

SECUREBOOTSIM_PROGRAM_NAMES_PK = \
    securebootsim_cfgP224IPc0pk \
    securebootsim_cfgP224IPc1pk \
    securebootsim_cfgP224IPc2pk \
    securebootsim_cfgP224IPc8pk \
    securebootsim_cfgP224CPc0pk \
    securebootsim_cfgP224CPc1pk \
    securebootsim_cfgP224CPc2pk \
    securebootsim_cfgP224CPc8pk \
    securebootsim_cfgP224CXPc0pk \
    securebootsim_cfgP224CXPc1pk \
    securebootsim_cfgP224CXPc2pk \
    securebootsim_cfgP224CXPc8pk \
    securebootsim_cfgP256IPc0pk \
    securebootsim_cfgP256IPc1pk \
    securebootsim_cfgP256IPc2pk \
    securebootsim_cfgP256IPc8pk \
    securebootsim_cfgP256CPc0pk \
    securebootsim_cfgP256CPc1pk \
    securebootsim_cfgP256CPc2pk \
    securebootsim_cfgP256CPc8pk \
    securebootsim_cfgP256CXPc0pk \
    securebootsim_cfgP256CXPc1pk \
    securebootsim_cfgP256CXPc2pk \
    securebootsim_cfgP256CXPc8pk \
    securebootsim_cfgP384IPc0pk \
    securebootsim_cfgP384IPc1pk \
    securebootsim_cfgP384IPc2pk \
    securebootsim_cfgP384IPc8pk \
    securebootsim_cfgP384CPc0pk \
    securebootsim_cfgP384CPc1pk \
    securebootsim_cfgP384CPc2pk \
    securebootsim_cfgP384CPc8pk \
    securebootsim_cfgP384CXPc0pk \
    securebootsim_cfgP384CXPc1pk \
    securebootsim_cfgP384CXPc2pk \
    securebootsim_cfgP384CXPc8pk \
    securebootsim_cfgP521IPc0pk \
    securebootsim_cfgP521IPc1pk \
    securebootsim_cfgP521IPc2pk \
    securebootsim_cfgP521IPc8pk \
    securebootsim_cfgP521CPc0pk \
    securebootsim_cfgP521CPc1pk \
    securebootsim_cfgP521CPc2pk \
    securebootsim_cfgP521CPc8pk \
    securebootsim_cfgP521CXPc0pk \
    securebootsim_cfgP521CXPc1pk \
    securebootsim_cfgP521CXPc2pk \
    securebootsim_cfgP521CXPc8pk \
    securebootsim_cfgRSA2048pkcsIPc0pk \
    securebootsim_cfgRSA2048pkcsIPc1pk \
    securebootsim_cfgRSA2048pkcsIPc2pk \
    securebootsim_cfgRSA2048pkcsIPc8pk \
    securebootsim_cfgRSA2048pkcsCPc0pk \
    securebootsim_cfgRSA2048pkcsCPc1pk \
    securebootsim_cfgRSA2048pkcsCPc2pk \
    securebootsim_cfgRSA2048pkcsCPc8pk \
    securebootsim_cfgRSA2048pkcsCXPc0pk \
    securebootsim_cfgRSA2048pkcsCXPc1pk \
    securebootsim_cfgRSA2048pkcsCXPc2pk \
    securebootsim_cfgRSA2048pkcsCXPc8pk \
    securebootsim_cfgRSA3072pkcsIPc0pk \
    securebootsim_cfgRSA3072pkcsIPc1pk \
    securebootsim_cfgRSA3072pkcsIPc2pk \
    securebootsim_cfgRSA3072pkcsIPc8pk \
    securebootsim_cfgRSA3072pkcsCPc0pk \
    securebootsim_cfgRSA3072pkcsCPc1pk \
    securebootsim_cfgRSA3072pkcsCPc2pk \
    securebootsim_cfgRSA3072pkcsCPc8pk \
    securebootsim_cfgRSA3072pkcsCXPc0pk \
    securebootsim_cfgRSA3072pkcsCXPc1pk \
    securebootsim_cfgRSA3072pkcsCXPc2pk \
    securebootsim_cfgRSA3072pkcsCXPc8pk \
    securebootsim_cfgRSA4096pkcsIPc0pk \
    securebootsim_cfgRSA4096pkcsIPc1pk \
    securebootsim_cfgRSA4096pkcsIPc2pk \
    securebootsim_cfgRSA4096pkcsIPc8pk \
    securebootsim_cfgRSA4096pkcsCPc0pk \
    securebootsim_cfgRSA4096pkcsCPc1pk \
    securebootsim_cfgRSA4096pkcsCPc2pk \
    securebootsim_cfgRSA4096pkcsCPc8pk \
    securebootsim_cfgRSA4096pkcsCXPc0pk \
    securebootsim_cfgRSA4096pkcsCXPc1pk \
    securebootsim_cfgRSA4096pkcsCXPc2pk \
    securebootsim_cfgRSA4096pkcsCXPc8pk \
    securebootsim_cfgRSA2048pssIPc0pk \
    securebootsim_cfgRSA2048pssIPc1pk \
    securebootsim_cfgRSA2048pssIPc2pk \
    securebootsim_cfgRSA2048pssIPc8pk \
    securebootsim_cfgRSA2048pssCPc0pk \
    securebootsim_cfgRSA2048pssCPc1pk \
    securebootsim_cfgRSA2048pssCPc2pk \
    securebootsim_cfgRSA2048pssCPc8pk \
    securebootsim_cfgRSA2048pssCXPc0pk \
    securebootsim_cfgRSA2048pssCXPc1pk \
    securebootsim_cfgRSA2048pssCXPc2pk \
    securebootsim_cfgRSA2048pssCXPc8pk \
    securebootsim_cfgRSA3072pssIPc0pk \
    securebootsim_cfgRSA3072pssIPc1pk \
    securebootsim_cfgRSA3072pssIPc2pk \
    securebootsim_cfgRSA3072pssIPc8pk \
    securebootsim_cfgRSA3072pssCPc0pk \
    securebootsim_cfgRSA3072pssCPc1pk \
    securebootsim_cfgRSA3072pssCPc2pk \
    securebootsim_cfgRSA3072pssCPc8pk \
    securebootsim_cfgRSA3072pssCXPc0pk \
    securebootsim_cfgRSA3072pssCXPc1pk \
    securebootsim_cfgRSA3072pssCXPc2pk \
    securebootsim_cfgRSA3072pssCXPc8pk \
    securebootsim_cfgRSA4096pssIPc0pk \
    securebootsim_cfgRSA4096pssIPc1pk \
    securebootsim_cfgRSA4096pssIPc2pk \
    securebootsim_cfgRSA4096pssIPc8pk \
    securebootsim_cfgRSA4096pssCPc0pk \
    securebootsim_cfgRSA4096pssCPc1pk \
    securebootsim_cfgRSA4096pssCPc2pk \
    securebootsim_cfgRSA4096pssCPc8pk \
    securebootsim_cfgRSA4096pssCXPc0pk \
    securebootsim_cfgRSA4096pssCXPc1pk \
    securebootsim_cfgRSA4096pssCXPc2pk \
    securebootsim_cfgRSA4096pssCXPc8pk

# Built by default
bin_PROGRAMS =

# Not installed by default
noinst_PROGRAMS =

# These targets are built for testing.
TEST_LIBRARIES_LIST =
check_PROGRAMS =

# These targets are not build by default.
EXTRA_PROGRAMS = \
    sbsmtest224 \
    sbpetest224 \
    sbpktest224 \
    sbpepktest224

# Add selected SW/HW variants to list of files to build.
if ENABLE_SBSW
bin_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_SW) updatetool securebootsim sbtest_publicdata_sw
SECUREBOOTSIM = securebootsim_cfgP224CPc2sw
TEST_LIBRARIES_LIST += libsbsw224.a
check_PROGRAMS += sbswtest224 sbswtestrsa2048pkcs sbswtestrsa3072pkcs sbswtestrsa4096pkcs
else
EXTRA_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_SW) updatetool sbtest_publicdata_sw
endif

if ENABLE_SBSM
bin_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_SM) securebootsim sbtest_publicdata_sm
SECUREBOOTSIM = securebootsim_cfgP224CPc2sm
TEST_LIBRARIES_LIST += libsbsm224.a
check_PROGRAMS += sbsmtest224 sbsmtestrsa2048pkcs sbsmtestrsa3072pkcs
else
EXTRA_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_SM) sbtest_publicdata_sm
endif

if ENABLE_SBPE
bin_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_PE) securebootsim
SECUREBOOTSIM = securebootsim_cfgP224CPc2pe
TEST_LIBRARIES_LIST += libsbpe224.a
check_PROGRAMS += sbpetest224
else
EXTRA_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_PE)
endif

if ENABLE_SBPEPK
bin_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_PEPK) securebootsim
SECUREBOOTSIM = securebootsim_cfgP224CPc2pepk
TEST_LIBRARIES_LIST += libsbpepk224.a
check_PROGRAMS += sbpepktest224
else
EXTRA_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_PEPK)
endif

if ENABLE_SBPK
bin_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_PK) securebootsim
SECUREBOOTSIM = securebootsim_cfgP224CPc2pk
check_PROGRAMS += sbpktest224
else
EXTRA_PROGRAMS += $(SECUREBOOTSIM_PROGRAM_NAMES_PK)
endif

# Convenience targets for building selected subsets of Secure Boot targets.
# (Note: these override --enable/disable-sb* configuration)
all_hw: all_sw all_sm all_pe all_pepk all_pk securebootsim

usual: all_sw \
    securebootsim_cfgP224IPc2sw \
    securebootsim_cfgP224CPc2sw \
    securebootsim_cfgP224CXPc2sw \
    securebootsim_cfgP224IPc2sm \
    securebootsim_cfgP224CPc2sm \
    securebootsim_cfgP224CXPc2sm \
    securebootsim_cfgP224IPc2pk \
    securebootsim_cfgP224CPc2pk \
    securebootsim_cfgP224CXPc2pk \
    securebootsim_cfgP224IPc2pe \
    securebootsim_cfgP224CPc2pe \
    securebootsim_cfgP224CXPc2pe \
    securebootsim_cfgP224IPc2pepk \
    securebootsim_cfgP224CPc2pepk \
    securebootsim_cfgP224CXPc2pepk \
    securebootsim_cfgP224CPKc2sw \
    securebootsim_cfgP224CXPKc2sw \
    securebootsim_cfgP224CNc2sm \
    securebootsim_cfgP224CXNc2sm \
    securebootsim_cfgP224CNKc2sm \
    securebootsim_cfgP224CXNKc2sm \
    securebootsim_cfgP256IPc2sw \
    securebootsim_cfgP256CPc2sw \
    securebootsim_cfgP256CXPc2sw \
    securebootsim_cfgP256IPc2sm \
    securebootsim_cfgP256CPc2sm \
    securebootsim_cfgP256CXPc2sm \
    securebootsim_cfgP256IPc2pk \
    securebootsim_cfgP256CPc2pk \
    securebootsim_cfgP256CXPc2pk \
    securebootsim_cfgP256IPc2pe \
    securebootsim_cfgP256CPc2pe \
    securebootsim_cfgP256CXPc2pe \
    securebootsim_cfgP256IPc2pepk \
    securebootsim_cfgP256CPc2pepk \
    securebootsim_cfgP256CXPc2pepk \
    securebootsim_cfgP256CPKc2sw \
    securebootsim_cfgP256CXPKc2sw \
    securebootsim_cfgP256CNc2sm \
    securebootsim_cfgP256CXNc2sm \
    securebootsim_cfgP256CNKc2sm \
    securebootsim_cfgP256CXNKc2sm \
    securebootsim_cfgP384IPc2sw \
    securebootsim_cfgP384CPc2sw \
    securebootsim_cfgP384CXPc2sw \
    securebootsim_cfgP384IPc2sm \
    securebootsim_cfgP384CPc2sm \
    securebootsim_cfgP384CXPc2sm \
    securebootsim_cfgP384IPc2pk \
    securebootsim_cfgP384CPc2pk \
    securebootsim_cfgP384CXPc2pk \
    securebootsim_cfgP384CPKc2sw \
    securebootsim_cfgP384CXPKc2sw \
    securebootsim_cfgP384CNc2sm \
    securebootsim_cfgP384CXNc2sm \
    securebootsim_cfgP384CNKc2sm \
    securebootsim_cfgP384CXNKc2sm \
    securebootsim_cfgP521IPc2sw \
    securebootsim_cfgP521CPc2sw \
    securebootsim_cfgP521CXPc2sw \
    securebootsim_cfgP521IPc2sm \
    securebootsim_cfgP521CPc2sm \
    securebootsim_cfgP521CXPc2sm \
    securebootsim_cfgP521IPc2pk \
    securebootsim_cfgP521CPc2pk \
    securebootsim_cfgP521CXPc2pk \
    securebootsim_cfgP521CPKc2sw \
    securebootsim_cfgP521CXPKc2sw \
    securebootsim_cfgP521CNc2sm \
    securebootsim_cfgP521CXNc2sm \
    securebootsim_cfgP521CNKc2sm \
    securebootsim_cfgP521CXNKc2sm \
    securebootsim_cfgRSA2048pkcsIPc2sw \
    securebootsim_cfgRSA2048pkcsCPc2sw \
    securebootsim_cfgRSA2048pkcsCXPc2sw \
    securebootsim_cfgRSA2048pkcsIPc2sm \
    securebootsim_cfgRSA2048pkcsCPc2sm \
    securebootsim_cfgRSA2048pkcsCXPc2sm \
    securebootsim_cfgRSA2048pkcsIPc2pk \
    securebootsim_cfgRSA2048pkcsCPc2pk \
    securebootsim_cfgRSA2048pkcsCXPc2pk \
    securebootsim_cfgRSA2048pkcsIPc2pepk \
    securebootsim_cfgRSA2048pkcsCPc2pepk \
    securebootsim_cfgRSA2048pkcsCXPc2pepk \
    securebootsim_cfgRSA2048pkcsCPKc2sw \
    securebootsim_cfgRSA2048pkcsCXPKc2sw \
    securebootsim_cfgRSA2048pkcsCNc2sm \
    securebootsim_cfgRSA2048pkcsCXNc2sm \
    securebootsim_cfgRSA2048pkcsCNKc2sm \
    securebootsim_cfgRSA2048pkcsCXNKc2sm \
    securebootsim_cfgRSA3072pkcsIPc2sw \
    securebootsim_cfgRSA3072pkcsCPc2sw \
    securebootsim_cfgRSA3072pkcsCXPc2sw \
    securebootsim_cfgRSA3072pkcsIPc2sm \
    securebootsim_cfgRSA3072pkcsCPc2sm \
    securebootsim_cfgRSA3072pkcsCXPc2sm \
    securebootsim_cfgRSA3072pkcsIPc2pk \
    securebootsim_cfgRSA3072pkcsCPc2pk \
    securebootsim_cfgRSA3072pkcsCXPc2pk \
    securebootsim_cfgRSA3072pkcsIPc2pepk \
    securebootsim_cfgRSA3072pkcsCPc2pepk \
    securebootsim_cfgRSA3072pkcsCXPc2pepk \
    securebootsim_cfgRSA3072pkcsCPKc2sw \
    securebootsim_cfgRSA3072pkcsCXPKc2sw \
    securebootsim_cfgRSA3072pkcsCNc2sm \
    securebootsim_cfgRSA3072pkcsCXNc2sm \
    securebootsim_cfgRSA3072pkcsCNKc2sm \
    securebootsim_cfgRSA3072pkcsCXNKc2sm \
    securebootsim_cfgRSA4096pkcsIPc2sw \
    securebootsim_cfgRSA4096pkcsCPc2sw \
    securebootsim_cfgRSA4096pkcsCXPc2sw \
    securebootsim_cfgRSA4096pkcsIPc2pk \
    securebootsim_cfgRSA4096pkcsCPc2pk \
    securebootsim_cfgRSA4096pkcsCXPc2pk \
    securebootsim_cfgRSA4096pkcsIPc2pepk \
    securebootsim_cfgRSA4096pkcsCPc2pepk \
    securebootsim_cfgRSA4096pkcsCXPc2pepk \
    securebootsim_cfgRSA4096pkcsCPKc2sw \
    securebootsim_cfgRSA4096pkcsCXPKc2sw \
    securebootsim_cfgRSA2048pssIPc2sw \
    securebootsim_cfgRSA2048pssCPc2sw \
    securebootsim_cfgRSA2048pssCXPc2sw \
    securebootsim_cfgRSA2048pssIPc2sm \
    securebootsim_cfgRSA2048pssCPc2sm \
    securebootsim_cfgRSA2048pssCXPc2sm \
    securebootsim_cfgRSA2048pssIPc2pk \
    securebootsim_cfgRSA2048pssCPc2pk \
    securebootsim_cfgRSA2048pssCXPc2pk \
    securebootsim_cfgRSA2048pssCPKc2sw \
    securebootsim_cfgRSA2048pssCXPKc2sw \
    securebootsim_cfgRSA2048pssCNc2sm \
    securebootsim_cfgRSA2048pssCXNc2sm \
    securebootsim_cfgRSA2048pssCNKc2sm \
    securebootsim_cfgRSA2048pssCXNKc2sm \
    securebootsim_cfgRSA3072pssIPc2sw \
    securebootsim_cfgRSA3072pssCPc2sw \
    securebootsim_cfgRSA3072pssCXPc2sw \
    securebootsim_cfgRSA3072pssIPc2sm \
    securebootsim_cfgRSA3072pssCPc2sm \
    securebootsim_cfgRSA3072pssCXPc2sm \
    securebootsim_cfgRSA3072pssIPc2pk \
    securebootsim_cfgRSA3072pssCPc2pk \
    securebootsim_cfgRSA3072pssCXPc2pk \
    securebootsim_cfgRSA3072pssCPKc2sw \
    securebootsim_cfgRSA3072pssCXPKc2sw \
    securebootsim_cfgRSA3072pssCNc2sm \
    securebootsim_cfgRSA3072pssCXNc2sm \
    securebootsim_cfgRSA3072pssCNKc2sm \
    securebootsim_cfgRSA3072pssCXNKc2sm \
    securebootsim_cfgRSA4096pssIPc2sw \
    securebootsim_cfgRSA4096pssCPc2sw \
    securebootsim_cfgRSA4096pssCXPc2sw \
    securebootsim_cfgRSA4096pssIPc2pk \
    securebootsim_cfgRSA4096pssCPc2pk \
    securebootsim_cfgRSA4096pssCXPc2pk \
    securebootsim_cfgRSA4096pssCPKc2sw \
    securebootsim_cfgRSA4096pssCXPKc2sw

all_sm: $(SECUREBOOTSIM_PROGRAM_NAMES_SM)
all_pe: $(SECUREBOOTSIM_PROGRAM_NAMES_PE)
all_pepk: $(SECUREBOOTSIM_PROGRAM_NAMES_PEPK)
all_pk: $(SECUREBOOTSIM_PROGRAM_NAMES_PK)
all_sw: $(SECUREBOOTSIM_PROGRAM_NAMES_SW)

noinst_LIBRARIES =

EXTRA_LIBRARIES = \
    $(TEST_LIBRARIES_LIST) \
    libsb_cfgP224IPc0sw.a \
    libsb_cfgP224IPc1sw.a \
    libsb_cfgP224IPc2sw.a \
    libsb_cfgP224IPc8sw.a \
    libsb_cfgP224CPc0sw.a \
    libsb_cfgP224CPc1sw.a \
    libsb_cfgP224CPc2sw.a \
    libsb_cfgP224CPc8sw.a \
    libsb_cfgP224CXPc0sw.a \
    libsb_cfgP224CXPc1sw.a \
    libsb_cfgP224CXPc2sw.a \
    libsb_cfgP224CXPc8sw.a \
    libsb_cfgP224IPc0sm.a \
    libsb_cfgP224IPc1sm.a \
    libsb_cfgP224IPc2sm.a \
    libsb_cfgP224IPc8sm.a \
    libsb_cfgP224CPc0sm.a \
    libsb_cfgP224CPc1sm.a \
    libsb_cfgP224CPc2sm.a \
    libsb_cfgP224CPc8sm.a \
    libsb_cfgP224CXPc0sm.a \
    libsb_cfgP224CXPc1sm.a \
    libsb_cfgP224CXPc2sm.a \
    libsb_cfgP224CXPc8sm.a \
    libsb_cfgP224IPc0pk.a \
    libsb_cfgP224IPc1pk.a \
    libsb_cfgP224IPc2pk.a \
    libsb_cfgP224IPc8pk.a \
    libsb_cfgP224CPc0pk.a \
    libsb_cfgP224CPc1pk.a \
    libsb_cfgP224CPc2pk.a \
    libsb_cfgP224CPc8pk.a \
    libsb_cfgP224CXPc0pk.a \
    libsb_cfgP224CXPc1pk.a \
    libsb_cfgP224CXPc2pk.a \
    libsb_cfgP224CXPc8pk.a \
    libsb_cfgP224IPc0pe.a \
    libsb_cfgP224IPc1pe.a \
    libsb_cfgP224IPc2pe.a \
    libsb_cfgP224IPc8pe.a \
    libsb_cfgP224CPc0pe.a \
    libsb_cfgP224CPc1pe.a \
    libsb_cfgP224CPc2pe.a \
    libsb_cfgP224CPc8pe.a \
    libsb_cfgP224CXPc0pe.a \
    libsb_cfgP224CXPc1pe.a \
    libsb_cfgP224CXPc2pe.a \
    libsb_cfgP224CXPc8pe.a \
    libsb_cfgP224IPc0pepk.a \
    libsb_cfgP224IPc1pepk.a \
    libsb_cfgP224IPc2pepk.a \
    libsb_cfgP224IPc8pepk.a \
    libsb_cfgP224CPc0pepk.a \
    libsb_cfgP224CPc1pepk.a \
    libsb_cfgP224CPc2pepk.a \
    libsb_cfgP224CPc8pepk.a \
    libsb_cfgP224CXPc0pepk.a \
    libsb_cfgP224CXPc1pepk.a \
    libsb_cfgP224CXPc2pepk.a \
    libsb_cfgP224CXPc8pepk.a \
    libsb_cfgP224CPKc0sw.a \
    libsb_cfgP224CPKc1sw.a \
    libsb_cfgP224CPKc2sw.a \
    libsb_cfgP224CPKc8sw.a \
    libsb_cfgP224CXPKc0sw.a \
    libsb_cfgP224CXPKc1sw.a \
    libsb_cfgP224CXPKc2sw.a \
    libsb_cfgP224CXPKc8sw.a \
    libsb_cfgP224CNc0sm.a \
    libsb_cfgP224CNc1sm.a \
    libsb_cfgP224CNc2sm.a \
    libsb_cfgP224CNc8sm.a \
    libsb_cfgP224CXNc0sm.a \
    libsb_cfgP224CXNc1sm.a \
    libsb_cfgP224CXNc2sm.a \
    libsb_cfgP224CXNc8sm.a \
    libsb_cfgP224CNKc0sm.a \
    libsb_cfgP224CNKc1sm.a \
    libsb_cfgP224CNKc2sm.a \
    libsb_cfgP224CNKc8sm.a \
    libsb_cfgP224CXNKc0sm.a \
    libsb_cfgP224CXNKc1sm.a \
    libsb_cfgP224CXNKc2sm.a \
    libsb_cfgP224CXNKc8sm.a \
    libsb_cfgP256IPc0sw.a \
    libsb_cfgP256IPc1sw.a \
    libsb_cfgP256IPc2sw.a \
    libsb_cfgP256IPc8sw.a \
    libsb_cfgP256CPc0sw.a \
    libsb_cfgP256CPc1sw.a \
    libsb_cfgP256CPc2sw.a \
    libsb_cfgP256CPc8sw.a \
    libsb_cfgP256CXPc0sw.a \
    libsb_cfgP256CXPc1sw.a \
    libsb_cfgP256CXPc2sw.a \
    libsb_cfgP256CXPc8sw.a \
    libsb_cfgP256IPc0sm.a \
    libsb_cfgP256IPc1sm.a \
    libsb_cfgP256IPc2sm.a \
    libsb_cfgP256IPc8sm.a \
    libsb_cfgP256CPc0sm.a \
    libsb_cfgP256CPc1sm.a \
    libsb_cfgP256CPc2sm.a \
    libsb_cfgP256CPc8sm.a \
    libsb_cfgP256CXPc0sm.a \
    libsb_cfgP256CXPc1sm.a \
    libsb_cfgP256CXPc2sm.a \
    libsb_cfgP256CXPc8sm.a \
    libsb_cfgP256IPc0pk.a \
    libsb_cfgP256IPc1pk.a \
    libsb_cfgP256IPc2pk.a \
    libsb_cfgP256IPc8pk.a \
    libsb_cfgP256CPc0pk.a \
    libsb_cfgP256CPc1pk.a \
    libsb_cfgP256CPc2pk.a \
    libsb_cfgP256CPc8pk.a \
    libsb_cfgP256CXPc0pk.a \
    libsb_cfgP256CXPc1pk.a \
    libsb_cfgP256CXPc2pk.a \
    libsb_cfgP256CXPc8pk.a \
    libsb_cfgP256IPc0pe.a \
    libsb_cfgP256IPc1pe.a \
    libsb_cfgP256IPc2pe.a \
    libsb_cfgP256IPc8pe.a \
    libsb_cfgP256CPc0pe.a \
    libsb_cfgP256CPc1pe.a \
    libsb_cfgP256CPc2pe.a \
    libsb_cfgP256CPc8pe.a \
    libsb_cfgP256CXPc0pe.a \
    libsb_cfgP256CXPc1pe.a \
    libsb_cfgP256CXPc2pe.a \
    libsb_cfgP256CXPc8pe.a \
    libsb_cfgP256IPc0pepk.a \
    libsb_cfgP256IPc1pepk.a \
    libsb_cfgP256IPc2pepk.a \
    libsb_cfgP256IPc8pepk.a \
    libsb_cfgP256CPc0pepk.a \
    libsb_cfgP256CPc1pepk.a \
    libsb_cfgP256CPc2pepk.a \
    libsb_cfgP256CPc8pepk.a \
    libsb_cfgP256CXPc0pepk.a \
    libsb_cfgP256CXPc1pepk.a \
    libsb_cfgP256CXPc2pepk.a \
    libsb_cfgP256CXPc8pepk.a \
    libsb_cfgP256CPKc0sw.a \
    libsb_cfgP256CPKc1sw.a \
    libsb_cfgP256CPKc2sw.a \
    libsb_cfgP256CPKc8sw.a \
    libsb_cfgP256CXPKc0sw.a \
    libsb_cfgP256CXPKc1sw.a \
    libsb_cfgP256CXPKc2sw.a \
    libsb_cfgP256CXPKc8sw.a \
    libsb_cfgP256CNc0sm.a \
    libsb_cfgP256CNc1sm.a \
    libsb_cfgP256CNc2sm.a \
    libsb_cfgP256CNc8sm.a \
    libsb_cfgP256CXNc0sm.a \
    libsb_cfgP256CXNc1sm.a \
    libsb_cfgP256CXNc2sm.a \
    libsb_cfgP256CXNc8sm.a \
    libsb_cfgP256CNKc0sm.a \
    libsb_cfgP256CNKc1sm.a \
    libsb_cfgP256CNKc2sm.a \
    libsb_cfgP256CNKc8sm.a \
    libsb_cfgP256CXNKc0sm.a \
    libsb_cfgP256CXNKc1sm.a \
    libsb_cfgP256CXNKc2sm.a \
    libsb_cfgP256CXNKc8sm.a \
    libsb_cfgP384IPc0sw.a \
    libsb_cfgP384IPc1sw.a \
    libsb_cfgP384IPc2sw.a \
    libsb_cfgP384IPc8sw.a \
    libsb_cfgP384CPc0sw.a \
    libsb_cfgP384CPc1sw.a \
    libsb_cfgP384CPc2sw.a \
    libsb_cfgP384CPc8sw.a \
    libsb_cfgP384CXPc0sw.a \
    libsb_cfgP384CXPc1sw.a \
    libsb_cfgP384CXPc2sw.a \
    libsb_cfgP384CXPc8sw.a \
    libsb_cfgP384IPc0sm.a \
    libsb_cfgP384IPc1sm.a \
    libsb_cfgP384IPc2sm.a \
    libsb_cfgP384IPc8sm.a \
    libsb_cfgP384CPc0sm.a \
    libsb_cfgP384CPc1sm.a \
    libsb_cfgP384CPc2sm.a \
    libsb_cfgP384CPc8sm.a \
    libsb_cfgP384CXPc0sm.a \
    libsb_cfgP384CXPc1sm.a \
    libsb_cfgP384CXPc2sm.a \
    libsb_cfgP384CXPc8sm.a \
    libsb_cfgP384IPc0pk.a \
    libsb_cfgP384IPc1pk.a \
    libsb_cfgP384IPc2pk.a \
    libsb_cfgP384IPc8pk.a \
    libsb_cfgP384CPc0pk.a \
    libsb_cfgP384CPc1pk.a \
    libsb_cfgP384CPc2pk.a \
    libsb_cfgP384CPc8pk.a \
    libsb_cfgP384CXPc0pk.a \
    libsb_cfgP384CXPc1pk.a \
    libsb_cfgP384CXPc2pk.a \
    libsb_cfgP384CXPc8pk.a \
    libsb_cfgP384CPKc0sw.a \
    libsb_cfgP384CPKc1sw.a \
    libsb_cfgP384CPKc2sw.a \
    libsb_cfgP384CPKc8sw.a \
    libsb_cfgP384CXPKc0sw.a \
    libsb_cfgP384CXPKc1sw.a \
    libsb_cfgP384CXPKc2sw.a \
    libsb_cfgP384CXPKc8sw.a \
    libsb_cfgP384CNc0sm.a \
    libsb_cfgP384CNc1sm.a \
    libsb_cfgP384CNc2sm.a \
    libsb_cfgP384CNc8sm.a \
    libsb_cfgP384CXNc0sm.a \
    libsb_cfgP384CXNc1sm.a \
    libsb_cfgP384CXNc2sm.a \
    libsb_cfgP384CXNc8sm.a \
    libsb_cfgP384CNKc0sm.a \
    libsb_cfgP384CNKc1sm.a \
    libsb_cfgP384CNKc2sm.a \
    libsb_cfgP384CNKc8sm.a \
    libsb_cfgP384CXNKc0sm.a \
    libsb_cfgP384CXNKc1sm.a \
    libsb_cfgP384CXNKc2sm.a \
    libsb_cfgP384CXNKc8sm.a \
    libsb_cfgP521IPc0sw.a \
    libsb_cfgP521IPc1sw.a \
    libsb_cfgP521IPc2sw.a \
    libsb_cfgP521IPc8sw.a \
    libsb_cfgP521CPc0sw.a \
    libsb_cfgP521CPc1sw.a \
    libsb_cfgP521CPc2sw.a \
    libsb_cfgP521CPc8sw.a \
    libsb_cfgP521CXPc0sw.a \
    libsb_cfgP521CXPc1sw.a \
    libsb_cfgP521CXPc2sw.a \
    libsb_cfgP521CXPc8sw.a \
    libsb_cfgP521IPc0sm.a \
    libsb_cfgP521IPc1sm.a \
    libsb_cfgP521IPc2sm.a \
    libsb_cfgP521IPc8sm.a \
    libsb_cfgP521CPc0sm.a \
    libsb_cfgP521CPc1sm.a \
    libsb_cfgP521CPc2sm.a \
    libsb_cfgP521CPc8sm.a \
    libsb_cfgP521CXPc0sm.a \
    libsb_cfgP521CXPc1sm.a \
    libsb_cfgP521CXPc2sm.a \
    libsb_cfgP521CXPc8sm.a \
    libsb_cfgP521IPc0pk.a \
    libsb_cfgP521IPc1pk.a \
    libsb_cfgP521IPc2pk.a \
    libsb_cfgP521IPc8pk.a \
    libsb_cfgP521CPc0pk.a \
    libsb_cfgP521CPc1pk.a \
    libsb_cfgP521CPc2pk.a \
    libsb_cfgP521CPc8pk.a \
    libsb_cfgP521CXPc0pk.a \
    libsb_cfgP521CXPc1pk.a \
    libsb_cfgP521CXPc2pk.a \
    libsb_cfgP521CXPc8pk.a \
    libsb_cfgP521CPKc0sw.a \
    libsb_cfgP521CPKc1sw.a \
    libsb_cfgP521CPKc2sw.a \
    libsb_cfgP521CPKc8sw.a \
    libsb_cfgP521CXPKc0sw.a \
    libsb_cfgP521CXPKc1sw.a \
    libsb_cfgP521CXPKc2sw.a \
    libsb_cfgP521CXPKc8sw.a \
    libsb_cfgP521CNc0sm.a \
    libsb_cfgP521CNc1sm.a \
    libsb_cfgP521CNc2sm.a \
    libsb_cfgP521CNc8sm.a \
    libsb_cfgP521CXNc0sm.a \
    libsb_cfgP521CXNc1sm.a \
    libsb_cfgP521CXNc2sm.a \
    libsb_cfgP521CXNc8sm.a \
    libsb_cfgP521CNKc0sm.a \
    libsb_cfgP521CNKc1sm.a \
    libsb_cfgP521CNKc2sm.a \
    libsb_cfgP521CNKc8sm.a \
    libsb_cfgP521CXNKc0sm.a \
    libsb_cfgP521CXNKc1sm.a \
    libsb_cfgP521CXNKc2sm.a \
    libsb_cfgP521CXNKc8sm.a \
    libsb_cfgRSA2048pkcsIPc0sw.a \
    libsb_cfgRSA2048pkcsIPc1sw.a \
    libsb_cfgRSA2048pkcsIPc2sw.a \
    libsb_cfgRSA2048pkcsIPc8sw.a \
    libsb_cfgRSA2048pkcsCPc0sw.a \
    libsb_cfgRSA2048pkcsCPc1sw.a \
    libsb_cfgRSA2048pkcsCPc2sw.a \
    libsb_cfgRSA2048pkcsCPc8sw.a \
    libsb_cfgRSA2048pkcsCXPc0sw.a \
    libsb_cfgRSA2048pkcsCXPc1sw.a \
    libsb_cfgRSA2048pkcsCXPc2sw.a \
    libsb_cfgRSA2048pkcsCXPc8sw.a \
    libsb_cfgRSA2048pkcsIPc0sm.a \
    libsb_cfgRSA2048pkcsIPc1sm.a \
    libsb_cfgRSA2048pkcsIPc2sm.a \
    libsb_cfgRSA2048pkcsIPc8sm.a \
    libsb_cfgRSA2048pkcsCPc0sm.a \
    libsb_cfgRSA2048pkcsCPc1sm.a \
    libsb_cfgRSA2048pkcsCPc2sm.a \
    libsb_cfgRSA2048pkcsCPc8sm.a \
    libsb_cfgRSA2048pkcsCXPc0sm.a \
    libsb_cfgRSA2048pkcsCXPc1sm.a \
    libsb_cfgRSA2048pkcsCXPc2sm.a \
    libsb_cfgRSA2048pkcsCXPc8sm.a \
    libsb_cfgRSA2048pkcsIPc0pk.a \
    libsb_cfgRSA2048pkcsIPc1pk.a \
    libsb_cfgRSA2048pkcsIPc2pk.a \
    libsb_cfgRSA2048pkcsIPc8pk.a \
    libsb_cfgRSA2048pkcsCPc0pk.a \
    libsb_cfgRSA2048pkcsCPc1pk.a \
    libsb_cfgRSA2048pkcsCPc2pk.a \
    libsb_cfgRSA2048pkcsCPc8pk.a \
    libsb_cfgRSA2048pkcsCXPc0pk.a \
    libsb_cfgRSA2048pkcsCXPc1pk.a \
    libsb_cfgRSA2048pkcsCXPc2pk.a \
    libsb_cfgRSA2048pkcsCXPc8pk.a \
    libsb_cfgRSA2048pkcsIPc0pepk.a \
    libsb_cfgRSA2048pkcsIPc1pepk.a \
    libsb_cfgRSA2048pkcsIPc2pepk.a \
    libsb_cfgRSA2048pkcsIPc8pepk.a \
    libsb_cfgRSA2048pkcsCPc0pepk.a \
    libsb_cfgRSA2048pkcsCPc1pepk.a \
    libsb_cfgRSA2048pkcsCPc2pepk.a \
    libsb_cfgRSA2048pkcsCPc8pepk.a \
    libsb_cfgRSA2048pkcsCXPc0pepk.a \
    libsb_cfgRSA2048pkcsCXPc1pepk.a \
    libsb_cfgRSA2048pkcsCXPc2pepk.a \
    libsb_cfgRSA2048pkcsCXPc8pepk.a \
    libsb_cfgRSA2048pkcsCPKc0sw.a \
    libsb_cfgRSA2048pkcsCPKc1sw.a \
    libsb_cfgRSA2048pkcsCPKc2sw.a \
    libsb_cfgRSA2048pkcsCPKc8sw.a \
    libsb_cfgRSA2048pkcsCXPKc0sw.a \
    libsb_cfgRSA2048pkcsCXPKc1sw.a \
    libsb_cfgRSA2048pkcsCXPKc2sw.a \
    libsb_cfgRSA2048pkcsCXPKc8sw.a \
    libsb_cfgRSA2048pkcsCNc0sm.a \
    libsb_cfgRSA2048pkcsCNc1sm.a \
    libsb_cfgRSA2048pkcsCNc2sm.a \
    libsb_cfgRSA2048pkcsCNc8sm.a \
    libsb_cfgRSA2048pkcsCXNc0sm.a \
    libsb_cfgRSA2048pkcsCXNc1sm.a \
    libsb_cfgRSA2048pkcsCXNc2sm.a \
    libsb_cfgRSA2048pkcsCXNc8sm.a \
    libsb_cfgRSA2048pkcsCNKc0sm.a \
    libsb_cfgRSA2048pkcsCNKc1sm.a \
    libsb_cfgRSA2048pkcsCNKc2sm.a \
    libsb_cfgRSA2048pkcsCNKc8sm.a \
    libsb_cfgRSA2048pkcsCXNKc0sm.a \
    libsb_cfgRSA2048pkcsCXNKc1sm.a \
    libsb_cfgRSA2048pkcsCXNKc2sm.a \
    libsb_cfgRSA2048pkcsCXNKc8sm.a \
    libsb_cfgRSA3072pkcsIPc0sw.a \
    libsb_cfgRSA3072pkcsIPc1sw.a \
    libsb_cfgRSA3072pkcsIPc2sw.a \
    libsb_cfgRSA3072pkcsIPc8sw.a \
    libsb_cfgRSA3072pkcsCPc0sw.a \
    libsb_cfgRSA3072pkcsCPc1sw.a \
    libsb_cfgRSA3072pkcsCPc2sw.a \
    libsb_cfgRSA3072pkcsCPc8sw.a \
    libsb_cfgRSA3072pkcsCXPc0sw.a \
    libsb_cfgRSA3072pkcsCXPc1sw.a \
    libsb_cfgRSA3072pkcsCXPc2sw.a \
    libsb_cfgRSA3072pkcsCXPc8sw.a \
    libsb_cfgRSA3072pkcsIPc0sm.a \
    libsb_cfgRSA3072pkcsIPc1sm.a \
    libsb_cfgRSA3072pkcsIPc2sm.a \
    libsb_cfgRSA3072pkcsIPc8sm.a \
    libsb_cfgRSA3072pkcsCPc0sm.a \
    libsb_cfgRSA3072pkcsCPc1sm.a \
    libsb_cfgRSA3072pkcsCPc2sm.a \
    libsb_cfgRSA3072pkcsCPc8sm.a \
    libsb_cfgRSA3072pkcsCXPc0sm.a \
    libsb_cfgRSA3072pkcsCXPc1sm.a \
    libsb_cfgRSA3072pkcsCXPc2sm.a \
    libsb_cfgRSA3072pkcsCXPc8sm.a \
    libsb_cfgRSA3072pkcsIPc0pk.a \
    libsb_cfgRSA3072pkcsIPc1pk.a \
    libsb_cfgRSA3072pkcsIPc2pk.a \
    libsb_cfgRSA3072pkcsIPc8pk.a \
    libsb_cfgRSA3072pkcsCPc0pk.a \
    libsb_cfgRSA3072pkcsCPc1pk.a \
    libsb_cfgRSA3072pkcsCPc2pk.a \
    libsb_cfgRSA3072pkcsCPc8pk.a \
    libsb_cfgRSA3072pkcsCXPc0pk.a \
    libsb_cfgRSA3072pkcsCXPc1pk.a \
    libsb_cfgRSA3072pkcsCXPc2pk.a \
    libsb_cfgRSA3072pkcsCXPc8pk.a \
    libsb_cfgRSA3072pkcsIPc0pepk.a \
    libsb_cfgRSA3072pkcsIPc1pepk.a \
    libsb_cfgRSA3072pkcsIPc2pepk.a \
    libsb_cfgRSA3072pkcsIPc8pepk.a \
    libsb_cfgRSA3072pkcsCPc0pepk.a \
    libsb_cfgRSA3072pkcsCPc1pepk.a \
    libsb_cfgRSA3072pkcsCPc2pepk.a \
    libsb_cfgRSA3072pkcsCPc8pepk.a \
    libsb_cfgRSA3072pkcsCXPc0pepk.a \
    libsb_cfgRSA3072pkcsCXPc1pepk.a \
    libsb_cfgRSA3072pkcsCXPc2pepk.a \
    libsb_cfgRSA3072pkcsCXPc8pepk.a \
    libsb_cfgRSA3072pkcsCPKc0sw.a \
    libsb_cfgRSA3072pkcsCPKc1sw.a \
    libsb_cfgRSA3072pkcsCPKc2sw.a \
    libsb_cfgRSA3072pkcsCPKc8sw.a \
    libsb_cfgRSA3072pkcsCXPKc0sw.a \
    libsb_cfgRSA3072pkcsCXPKc1sw.a \
    libsb_cfgRSA3072pkcsCXPKc2sw.a \
    libsb_cfgRSA3072pkcsCXPKc8sw.a \
    libsb_cfgRSA3072pkcsCNc0sm.a \
    libsb_cfgRSA3072pkcsCNc1sm.a \
    libsb_cfgRSA3072pkcsCNc2sm.a \
    libsb_cfgRSA3072pkcsCNc8sm.a \
    libsb_cfgRSA3072pkcsCXNc0sm.a \
    libsb_cfgRSA3072pkcsCXNc1sm.a \
    libsb_cfgRSA3072pkcsCXNc2sm.a \
    libsb_cfgRSA3072pkcsCXNc8sm.a \
    libsb_cfgRSA3072pkcsCNKc0sm.a \
    libsb_cfgRSA3072pkcsCNKc1sm.a \
    libsb_cfgRSA3072pkcsCNKc2sm.a \
    libsb_cfgRSA3072pkcsCNKc8sm.a \
    libsb_cfgRSA3072pkcsCXNKc0sm.a \
    libsb_cfgRSA3072pkcsCXNKc1sm.a \
    libsb_cfgRSA3072pkcsCXNKc2sm.a \
    libsb_cfgRSA3072pkcsCXNKc8sm.a \
    libsb_cfgRSA4096pkcsIPc0sw.a \
    libsb_cfgRSA4096pkcsIPc1sw.a \
    libsb_cfgRSA4096pkcsIPc2sw.a \
    libsb_cfgRSA4096pkcsIPc8sw.a \
    libsb_cfgRSA4096pkcsCPc0sw.a \
    libsb_cfgRSA4096pkcsCPc1sw.a \
    libsb_cfgRSA4096pkcsCPc2sw.a \
    libsb_cfgRSA4096pkcsCPc8sw.a \
    libsb_cfgRSA4096pkcsCXPc0sw.a \
    libsb_cfgRSA4096pkcsCXPc1sw.a \
    libsb_cfgRSA4096pkcsCXPc2sw.a \
    libsb_cfgRSA4096pkcsCXPc8sw.a \
    libsb_cfgRSA4096pkcsIPc0pk.a \
    libsb_cfgRSA4096pkcsIPc1pk.a \
    libsb_cfgRSA4096pkcsIPc2pk.a \
    libsb_cfgRSA4096pkcsIPc8pk.a \
    libsb_cfgRSA4096pkcsCPc0pk.a \
    libsb_cfgRSA4096pkcsCPc1pk.a \
    libsb_cfgRSA4096pkcsCPc2pk.a \
    libsb_cfgRSA4096pkcsCPc8pk.a \
    libsb_cfgRSA4096pkcsCXPc0pk.a \
    libsb_cfgRSA4096pkcsCXPc1pk.a \
    libsb_cfgRSA4096pkcsCXPc2pk.a \
    libsb_cfgRSA4096pkcsCXPc8pk.a \
    libsb_cfgRSA4096pkcsIPc0pepk.a \
    libsb_cfgRSA4096pkcsIPc1pepk.a \
    libsb_cfgRSA4096pkcsIPc2pepk.a \
    libsb_cfgRSA4096pkcsIPc8pepk.a \
    libsb_cfgRSA4096pkcsCPc0pepk.a \
    libsb_cfgRSA4096pkcsCPc1pepk.a \
    libsb_cfgRSA4096pkcsCPc2pepk.a \
    libsb_cfgRSA4096pkcsCPc8pepk.a \
    libsb_cfgRSA4096pkcsCXPc0pepk.a \
    libsb_cfgRSA4096pkcsCXPc1pepk.a \
    libsb_cfgRSA4096pkcsCXPc2pepk.a \
    libsb_cfgRSA4096pkcsCXPc8pepk.a \
    libsb_cfgRSA4096pkcsCPKc0sw.a \
    libsb_cfgRSA4096pkcsCPKc1sw.a \
    libsb_cfgRSA4096pkcsCPKc2sw.a \
    libsb_cfgRSA4096pkcsCPKc8sw.a \
    libsb_cfgRSA4096pkcsCXPKc0sw.a \
    libsb_cfgRSA4096pkcsCXPKc1sw.a \
    libsb_cfgRSA4096pkcsCXPKc2sw.a \
    libsb_cfgRSA4096pkcsCXPKc8sw.a \
    libsb_cfgRSA2048pssIPc0sw.a \
    libsb_cfgRSA2048pssIPc1sw.a \
    libsb_cfgRSA2048pssIPc2sw.a \
    libsb_cfgRSA2048pssIPc8sw.a \
    libsb_cfgRSA2048pssCPc0sw.a \
    libsb_cfgRSA2048pssCPc1sw.a \
    libsb_cfgRSA2048pssCPc2sw.a \
    libsb_cfgRSA2048pssCPc8sw.a \
    libsb_cfgRSA2048pssCXPc0sw.a \
    libsb_cfgRSA2048pssCXPc1sw.a \
    libsb_cfgRSA2048pssCXPc2sw.a \
    libsb_cfgRSA2048pssCXPc8sw.a \
    libsb_cfgRSA2048pssIPc0sm.a \
    libsb_cfgRSA2048pssIPc1sm.a \
    libsb_cfgRSA2048pssIPc2sm.a \
    libsb_cfgRSA2048pssIPc8sm.a \
    libsb_cfgRSA2048pssCPc0sm.a \
    libsb_cfgRSA2048pssCPc1sm.a \
    libsb_cfgRSA2048pssCPc2sm.a \
    libsb_cfgRSA2048pssCPc8sm.a \
    libsb_cfgRSA2048pssCXPc0sm.a \
    libsb_cfgRSA2048pssCXPc1sm.a \
    libsb_cfgRSA2048pssCXPc2sm.a \
    libsb_cfgRSA2048pssCXPc8sm.a \
    libsb_cfgRSA2048pssIPc0pk.a \
    libsb_cfgRSA2048pssIPc1pk.a \
    libsb_cfgRSA2048pssIPc2pk.a \
    libsb_cfgRSA2048pssIPc8pk.a \
    libsb_cfgRSA2048pssCPc0pk.a \
    libsb_cfgRSA2048pssCPc1pk.a \
    libsb_cfgRSA2048pssCPc2pk.a \
    libsb_cfgRSA2048pssCPc8pk.a \
    libsb_cfgRSA2048pssCXPc0pk.a \
    libsb_cfgRSA2048pssCXPc1pk.a \
    libsb_cfgRSA2048pssCXPc2pk.a \
    libsb_cfgRSA2048pssCXPc8pk.a \
    libsb_cfgRSA2048pssCPKc0sw.a \
    libsb_cfgRSA2048pssCPKc1sw.a \
    libsb_cfgRSA2048pssCPKc2sw.a \
    libsb_cfgRSA2048pssCPKc8sw.a \
    libsb_cfgRSA2048pssCXPKc0sw.a \
    libsb_cfgRSA2048pssCXPKc1sw.a \
    libsb_cfgRSA2048pssCXPKc2sw.a \
    libsb_cfgRSA2048pssCXPKc8sw.a \
    libsb_cfgRSA2048pssCNc0sm.a \
    libsb_cfgRSA2048pssCNc1sm.a \
    libsb_cfgRSA2048pssCNc2sm.a \
    libsb_cfgRSA2048pssCNc8sm.a \
    libsb_cfgRSA2048pssCXNc0sm.a \
    libsb_cfgRSA2048pssCXNc1sm.a \
    libsb_cfgRSA2048pssCXNc2sm.a \
    libsb_cfgRSA2048pssCXNc8sm.a \
    libsb_cfgRSA2048pssCNKc0sm.a \
    libsb_cfgRSA2048pssCNKc1sm.a \
    libsb_cfgRSA2048pssCNKc2sm.a \
    libsb_cfgRSA2048pssCNKc8sm.a \
    libsb_cfgRSA2048pssCXNKc0sm.a \
    libsb_cfgRSA2048pssCXNKc1sm.a \
    libsb_cfgRSA2048pssCXNKc2sm.a \
    libsb_cfgRSA2048pssCXNKc8sm.a \
    libsb_cfgRSA3072pssIPc0sw.a \
    libsb_cfgRSA3072pssIPc1sw.a \
    libsb_cfgRSA3072pssIPc2sw.a \
    libsb_cfgRSA3072pssIPc8sw.a \
    libsb_cfgRSA3072pssCPc0sw.a \
    libsb_cfgRSA3072pssCPc1sw.a \
    libsb_cfgRSA3072pssCPc2sw.a \
    libsb_cfgRSA3072pssCPc8sw.a \
    libsb_cfgRSA3072pssCXPc0sw.a \
    libsb_cfgRSA3072pssCXPc1sw.a \
    libsb_cfgRSA3072pssCXPc2sw.a \
    libsb_cfgRSA3072pssCXPc8sw.a \
    libsb_cfgRSA3072pssIPc0sm.a \
    libsb_cfgRSA3072pssIPc1sm.a \
    libsb_cfgRSA3072pssIPc2sm.a \
    libsb_cfgRSA3072pssIPc8sm.a \
    libsb_cfgRSA3072pssCPc0sm.a \
    libsb_cfgRSA3072pssCPc1sm.a \
    libsb_cfgRSA3072pssCPc2sm.a \
    libsb_cfgRSA3072pssCPc8sm.a \
    libsb_cfgRSA3072pssCXPc0sm.a \
    libsb_cfgRSA3072pssCXPc1sm.a \
    libsb_cfgRSA3072pssCXPc2sm.a \
    libsb_cfgRSA3072pssCXPc8sm.a \
    libsb_cfgRSA3072pssIPc0pk.a \
    libsb_cfgRSA3072pssIPc1pk.a \
    libsb_cfgRSA3072pssIPc2pk.a \
    libsb_cfgRSA3072pssIPc8pk.a \
    libsb_cfgRSA3072pssCPc0pk.a \
    libsb_cfgRSA3072pssCPc1pk.a \
    libsb_cfgRSA3072pssCPc2pk.a \
    libsb_cfgRSA3072pssCPc8pk.a \
    libsb_cfgRSA3072pssCXPc0pk.a \
    libsb_cfgRSA3072pssCXPc1pk.a \
    libsb_cfgRSA3072pssCXPc2pk.a \
    libsb_cfgRSA3072pssCXPc8pk.a \
    libsb_cfgRSA3072pssCPKc0sw.a \
    libsb_cfgRSA3072pssCPKc1sw.a \
    libsb_cfgRSA3072pssCPKc2sw.a \
    libsb_cfgRSA3072pssCPKc8sw.a \
    libsb_cfgRSA3072pssCXPKc0sw.a \
    libsb_cfgRSA3072pssCXPKc1sw.a \
    libsb_cfgRSA3072pssCXPKc2sw.a \
    libsb_cfgRSA3072pssCXPKc8sw.a \
    libsb_cfgRSA3072pssCNc0sm.a \
    libsb_cfgRSA3072pssCNc1sm.a \
    libsb_cfgRSA3072pssCNc2sm.a \
    libsb_cfgRSA3072pssCNc8sm.a \
    libsb_cfgRSA3072pssCXNc0sm.a \
    libsb_cfgRSA3072pssCXNc1sm.a \
    libsb_cfgRSA3072pssCXNc2sm.a \
    libsb_cfgRSA3072pssCXNc8sm.a \
    libsb_cfgRSA3072pssCNKc0sm.a \
    libsb_cfgRSA3072pssCNKc1sm.a \
    libsb_cfgRSA3072pssCNKc2sm.a \
    libsb_cfgRSA3072pssCNKc8sm.a \
    libsb_cfgRSA3072pssCXNKc0sm.a \
    libsb_cfgRSA3072pssCXNKc1sm.a \
    libsb_cfgRSA3072pssCXNKc2sm.a \
    libsb_cfgRSA3072pssCXNKc8sm.a \
    libsb_cfgRSA4096pssIPc0sw.a \
    libsb_cfgRSA4096pssIPc1sw.a \
    libsb_cfgRSA4096pssIPc2sw.a \
    libsb_cfgRSA4096pssIPc8sw.a \
    libsb_cfgRSA4096pssCPc0sw.a \
    libsb_cfgRSA4096pssCPc1sw.a \
    libsb_cfgRSA4096pssCPc2sw.a \
    libsb_cfgRSA4096pssCPc8sw.a \
    libsb_cfgRSA4096pssCXPc0sw.a \
    libsb_cfgRSA4096pssCXPc1sw.a \
    libsb_cfgRSA4096pssCXPc2sw.a \
    libsb_cfgRSA4096pssCXPc8sw.a \
    libsb_cfgRSA4096pssIPc0pk.a \
    libsb_cfgRSA4096pssIPc1pk.a \
    libsb_cfgRSA4096pssIPc2pk.a \
    libsb_cfgRSA4096pssIPc8pk.a \
    libsb_cfgRSA4096pssCPc0pk.a \
    libsb_cfgRSA4096pssCPc1pk.a \
    libsb_cfgRSA4096pssCPc2pk.a \
    libsb_cfgRSA4096pssCPc8pk.a \
    libsb_cfgRSA4096pssCXPc0pk.a \
    libsb_cfgRSA4096pssCXPc1pk.a \
    libsb_cfgRSA4096pssCXPc2pk.a \
    libsb_cfgRSA4096pssCXPc8pk.a \
    libsb_cfgRSA4096pssCPKc0sw.a \
    libsb_cfgRSA4096pssCPKc1sw.a \
    libsb_cfgRSA4096pssCPKc2sw.a \
    libsb_cfgRSA4096pssCPKc8sw.a \
    libsb_cfgRSA4096pssCXPKc0sw.a \
    libsb_cfgRSA4096pssCXPKc1sw.a \
    libsb_cfgRSA4096pssCXPKc2sw.a \
    libsb_cfgRSA4096pssCXPKc8sw.a

if ENABLE_BARE
LIBSBHW_TARGET = libtarget_bare.a
EXTRA_LIBRARIES += $(LIBSBHW_TARGET)
LIBSBHW_TARGET_PE = $(LIBSBHW_TARGET)
LIBSBHW_TARGET_PEPK = $(LIBSBHW_TARGET)
LIBSBHW_TARGET_PK = $(LIBSBHW_TARGET)
LIBSBHW_TARGET_SM = $(LIBSBHW_TARGET)

endif



check_LIBRARIES = libsfzutf.a libdebug.a

if COMPILER_64
    MAX_REQ = 14
    RSA2048_MEM_SIZE = 5072
    RSA3072_MEM_SIZE = 9688
    RSA4096_MEM_SIZE = 13224
endif
if COMPILER_32
    MAX_REQ = 14
    RSA2048_MEM_SIZE = 6616
    RSA3072_MEM_SIZE = 13008
    RSA4096_MEM_SIZE = 17976
endif

SBIF_ATTRIBUTE_SUPPORT_SOURCES = \
    $(top_src)/SBCommon/SBIF/src/sbif_attributes.c

ABSTRACTION_INCLUDES = \
    -I$(top_src)/Kit/DriverFramework/$(ABSTRACTION_BASICDEFS)/incl \
    -I$(top_src)/Kit/DriverFramework/$(ABSTRACTION_CLIB)/incl

LIBSB_SW_INCLUDES = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/SBCommon/Config \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl \
    -I$(top_src)/Framework/CLIB/incl \
    -I$(top_src)/Kit/DriverFramework/v4/GenericHelper/incl \
    -I$(top_src)/SBLib/SB_API/incl \
    -I$(top_src)/SBLib/SB_HYBRID/src \
    -I$(top_src)/SBCommon/SBIF_API/incl \
    -I$(top_src)/SBCommon/SBIF_TOOLS/incl \
    -I$(top_src)/SBCommon/SB_SW_CRYPTO/incl \
    -I$(top_src)/SBCommon/SB_SW_CRYPTO/incl/micro-ecc \
    -I$(top_src)/SBCommon/SB_SW_CRYPTO/incl/rsa_ssh_glue \
    -I$(top_src)/SBCommon/SB_AES_API/incl \
    -I$(top_src)/CryptoLib/MathLib/src \
    -DuECC_VLI_NATIVE_LITTLE_ENDIAN=1 -DuECC_WORD_SIZE=4 -DVERIFY_ONLY

LIBSB_SW224_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp224r1=1

LIBSB_SW224AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp224r1=1

LIBSB_SW224KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp224r1=1

LIBSB_SW224KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp224r1=1

LIBSB_SW256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp256r1=1

LIBSB_SW256AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp256r1=1

LIBSB_SW256KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp256r1=1

LIBSB_SW256KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp256r1=1

LIBSB_SW384_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp384r1=1

LIBSB_SW384AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp384r1=1

LIBSB_SW384KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp384r1=1

LIBSB_SW384KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp384r1=1

LIBSB_SW521_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp521r1=1

LIBSB_SW521AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp521r1=1

LIBSB_SW521KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp521r1=1

LIBSB_SW521KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DuECC_SUPPORTS_secp521r1=1

LIBSB_SWRSA2048pkcs_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA2048pkcsAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA2048pkcsKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA2048pkcsKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA3072pkcs_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA3072pkcsAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA3072pkcsKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA3072pkcsKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA4096pkcs_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA4096pkcsAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA4096pkcsKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA4096pkcsKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PKCS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA2048pss_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA2048pssAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA2048pssKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA2048pssKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA2048_MEM_SIZE)

LIBSB_SWRSA3072pss_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA3072pssAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA3072pssKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA3072pssKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA3072_MEM_SIZE)

LIBSB_SWRSA4096pss_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA4096pssAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA4096pssKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

LIBSB_SWRSA4096pssKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK_AES256 \
    $(LIBSB_SW_INCLUDES) \
    -DSUPPORT_RSA_PSS \
    -DSSH_MEM_MAX_REQ=$(MAX_REQ) -DSSH_MEM_SIZE=$(RSA4096_MEM_SIZE)

SECUREBOOTSIM_INCLUDES = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/SBCommon/Config \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl \
    -I$(top_src)/Framework/CLIB/incl \
    -I$(top_src)/SFZUTF/incl \
    -I$(top_src)/SBLib/SB_API/incl \
    -I$(top_src)/SBLib/SB_HYBRID/src \
    -I$(top_src)/SBCommon/SBIF_API/incl \
    -I$(top_src)/SBCommon/SBIF_TOOLS/incl \
    -I$(top_src)/SBCommon/SB_SW_CRYPTO/incl \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/GenericHelper/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl

SECUREBOOTSIM224_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM224AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM224KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224_KDK \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM224KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC224_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM256AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM256KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256_KDK \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM256KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC256_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM384_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM384AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM384KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384_KDK \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM384KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC384_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM521_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM521AES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM521KDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521_KDK \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIM521KDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/ECC521_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES)

SECUREBOOTSIMRSA2048pkcs_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA3072pkcs_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA4096pkcs_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA4096pkcsKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA4096pkcsKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PKCS

SECUREBOOTSIMRSA2048pss_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA2048pssAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA2048pssKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA2048_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA3072pss_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA3072pssAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA3072pssKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA3072_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA4096pss_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA4096pssAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA4096pssKDK_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

SECUREBOOTSIMRSA4096pssKDKAES256_INCLUDES = \
    -I$(top_src)/SBCommon/Config/RSA4096_KDK_AES256 \
    $(SECUREBOOTSIM_INCLUDES) \
    -DSUPPORT_RSA_PSS

# The SBCommon code use by (variants of) Secure Boot
SB_SW_HASH256_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/minsha_init.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/minsha_update.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/minsha_core.c

SB_SW_HASH512_SOURCES = \
    $(SB_SW_HASH256_SOURCES) \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_hash_sha512.c

SB_SW_ECDSA224_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/uECC.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa224.c

SB_SW_ECDSA256_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/uECC.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa256.c

SB_SW_ECDSA384_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/uECC.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa384.c

SB_SW_ECDSA521_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/uECC.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa521.c

SB_SW_RSA_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_rsa_verify.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_rsa_common.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_rsa_ssh_glue.c \
    $(top_src)/CryptoLib/MathLib/src/sshmp-integer-core.c \
    $(top_src)/CryptoLib/MathLib/src/sshmp-powm.c \
    $(top_src)/CryptoLib/MathLib/src/sshmp-kernel.c \
    $(top_src)/CryptoLib/MathLib/src/sshmp-montgomery.c \
    $(top_src)/CryptoLib/MathLib/src/sshmp-intmod.c \
    $(top_src)/CryptoLib/MathLib/src/sshmp-arithmetic.c

SB_SW_ECDSA_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/uECC.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa224.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa256.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa384.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sb_sw_ecdsa521.c

SB_SW_AES_SOURCES = \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/aes_if.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c

# Additional driver sources for PE (EIP-93) version.
SB_PE_DRIVER_SOURCES = \
    $(top_src)/Kit/EIP93_SL/src/eip93_sl.c \
    $(top_src)/Kit/EIP93_SL/src/eip93_arm.c \
    $(top_src)/Kit/RingHelper/src/ringhelper.c

# Additional driver sources for SM (EIP-130) version.

SB_SM_DRIVER_SOURCES = \
    $(top_src)/Kit/EIP130/TokenHelper/src/eip130_token_common.c \
    $(top_src)/Kit/EIP130/MailboxControl/src/eip130.c


# Additional driver sources for PK (EIP-28) version.
SB_PK_DRIVER_SOURCES = $(top_src)/Kit/EIP28_SL/src/eip28.c \
                       $(top_src)/Kit/EIP28_SL/src/EIP28_PKCP/eip28_ext.c

# Combinations
SB_PEPK_DRIVER_SOURCES = $(SB_PE_DRIVER_SOURCES) $(SB_PK_DRIVER_SOURCES)

LIBSB_HYBRID_GEN_INCLUDES = \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    -I$(top_src)/Kit/EIP28_SL/incl \
    -I$(top_src)/Kit/EIP28_SL/src \
    -I$(top_src)/Kit/EIP93_SL/incl \
    -I$(top_src)/Kit/EIP130/MailboxControl/incl \
    -I$(top_src)/Kit/EIP130/MailboxControl/src \
    -I$(top_src)/Kit/EIP130/TokenHelper/incl \
    -I$(top_src)/Kit/EIP130/TokenHelper/src \
    -I$(top_src)/Kit/RingHelper/incl

if ENABLE_DEBUG
LIBSB_HYBRID_GEN_INCLUDES += \
    -I$(top_src)/Kit/Log/incl \
    -I$(top_src)/Kit/Log/src/safezone

endif
LIBSB_HYBRID224_INCLUDES = \
    $(LIBSB_SW224_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID224AES256_INCLUDES = \
    $(LIBSB_SW224AES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID224KDK_INCLUDES = \
    $(LIBSB_SW224KDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID224KDKAES256_INCLUDES = \
    $(LIBSB_SW224KDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID256_INCLUDES = \
    $(LIBSB_SW256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID256AES256_INCLUDES = \
    $(LIBSB_SW256AES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID256KDK_INCLUDES = \
    $(LIBSB_SW256KDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID256KDKAES256_INCLUDES = \
    $(LIBSB_SW256KDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID384_INCLUDES = \
    $(LIBSB_SW384_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID384AES256_INCLUDES = \
    $(LIBSB_SW384AES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID384KDK_INCLUDES = \
    $(LIBSB_SW384KDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID384KDKAES256_INCLUDES = \
    $(LIBSB_SW384KDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID521_INCLUDES = \
    $(LIBSB_SW521_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID521AES256_INCLUDES = \
    $(LIBSB_SW521AES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID521KDK_INCLUDES = \
    $(LIBSB_SW521KDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRID521KDKAES256_INCLUDES = \
    $(LIBSB_SW521KDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pkcs_INCLUDES = \
    $(LIBSB_SWRSA2048pkcs_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES = \
    $(LIBSB_SWRSA2048pkcsAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES = \
    $(LIBSB_SWRSA2048pkcsKDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES = \
    $(LIBSB_SWRSA2048pkcsKDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pkcs_INCLUDES = \
    $(LIBSB_SWRSA3072pkcs_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES = \
    $(LIBSB_SWRSA3072pkcsAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES = \
    $(LIBSB_SWRSA3072pkcsKDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES = \
    $(LIBSB_SWRSA3072pkcsKDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pkcs_INCLUDES = \
    $(LIBSB_SWRSA4096pkcs_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES = \
    $(LIBSB_SWRSA4096pkcsAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pkcsKDK_INCLUDES = \
    $(LIBSB_SWRSA4096pkcsKDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pkcsKDKAES256_INCLUDES = \
    $(LIBSB_SWRSA4096pkcsKDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pss_INCLUDES = \
    $(LIBSB_SWRSA2048pss_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pssAES256_INCLUDES = \
    $(LIBSB_SWRSA2048pssAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pssKDK_INCLUDES = \
    $(LIBSB_SWRSA2048pssKDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES = \
    $(LIBSB_SWRSA2048pssKDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pss_INCLUDES = \
    $(LIBSB_SWRSA3072pss_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pssAES256_INCLUDES = \
    $(LIBSB_SWRSA3072pssAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pssKDK_INCLUDES = \
    $(LIBSB_SWRSA3072pssKDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES = \
    $(LIBSB_SWRSA3072pssKDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pss_INCLUDES = \
    $(LIBSB_SWRSA4096pss_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pssAES256_INCLUDES = \
    $(LIBSB_SWRSA4096pssAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pssKDK_INCLUDES = \
    $(LIBSB_SWRSA4096pssKDK_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

LIBSB_HYBRIDRSA4096pssKDKAES256_INCLUDES = \
    $(LIBSB_SWRSA4096pssKDKAES256_INCLUDES) \
    $(LIBSB_HYBRID_GEN_INCLUDES)

# Rules for libsb_cfgP224IPc0sw.a and securebootsim_cfgP224IPc0sw
libsb_cfgP224IPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224IPc0sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES)
securebootsim_cfgP224IPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc0sw_LDADD = libsb_cfgP224IPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc1sw.a and securebootsim_cfgP224IPc1sw
libsb_cfgP224IPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224IPc1sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES)
securebootsim_cfgP224IPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc1sw_LDADD = libsb_cfgP224IPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc2sw.a and securebootsim_cfgP224IPc2sw
libsb_cfgP224IPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224IPc2sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES)
securebootsim_cfgP224IPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc2sw_LDADD = libsb_cfgP224IPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc8sw.a and securebootsim_cfgP224IPc8sw
libsb_cfgP224IPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224IPc8sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES)
securebootsim_cfgP224IPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc8sw_LDADD = libsb_cfgP224IPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc0sw.a and securebootsim_cfgP224CPc0sw
libsb_cfgP224CPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc0sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc0sw_LDADD = libsb_cfgP224CPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc1sw.a and securebootsim_cfgP224CPc1sw
libsb_cfgP224CPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc1sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc1sw_LDADD = libsb_cfgP224CPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc2sw.a and securebootsim_cfgP224CPc2sw
libsb_cfgP224CPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc2sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc2sw_LDADD = libsb_cfgP224CPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc8sw.a and securebootsim_cfgP224CPc8sw
libsb_cfgP224CPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc8sw_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc8sw_LDADD = libsb_cfgP224CPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc0sw.a and securebootsim_cfgP224CXPc0sw
libsb_cfgP224CXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc0sw_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc0sw_LDADD = libsb_cfgP224CXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc1sw.a and securebootsim_cfgP224CXPc1sw
libsb_cfgP224CXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc1sw_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc1sw_LDADD = libsb_cfgP224CXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc2sw.a and securebootsim_cfgP224CXPc2sw
libsb_cfgP224CXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc2sw_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc2sw_LDADD = libsb_cfgP224CXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc8sw.a and securebootsim_cfgP224CXPc8sw
libsb_cfgP224CXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc8sw_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc8sw_LDADD = libsb_cfgP224CXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc0sm.a and securebootsim_cfgP224IPc0sm
libsb_cfgP224IPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224IPc0sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc0sm_LDADD = libsb_cfgP224IPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc1sm.a and securebootsim_cfgP224IPc1sm
libsb_cfgP224IPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224IPc1sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc1sm_LDADD = libsb_cfgP224IPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc2sm.a and securebootsim_cfgP224IPc2sm
libsb_cfgP224IPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224IPc2sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc2sm_LDADD = libsb_cfgP224IPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc8sm.a and securebootsim_cfgP224IPc8sm
libsb_cfgP224IPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224IPc8sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc8sm_LDADD = libsb_cfgP224IPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc0sm.a and securebootsim_cfgP224CPc0sm
libsb_cfgP224CPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc0sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc0sm_LDADD = libsb_cfgP224CPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc1sm.a and securebootsim_cfgP224CPc1sm
libsb_cfgP224CPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc1sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc1sm_LDADD = libsb_cfgP224CPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc2sm.a and securebootsim_cfgP224CPc2sm
libsb_cfgP224CPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc2sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc2sm_LDADD = libsb_cfgP224CPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc8sm.a and securebootsim_cfgP224CPc8sm
libsb_cfgP224CPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc8sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc8sm_LDADD = libsb_cfgP224CPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc0sm.a and securebootsim_cfgP224CXPc0sm
libsb_cfgP224CXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc0sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc0sm_LDADD = libsb_cfgP224CXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc1sm.a and securebootsim_cfgP224CXPc1sm
libsb_cfgP224CXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc1sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc1sm_LDADD = libsb_cfgP224CXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc2sm.a and securebootsim_cfgP224CXPc2sm
libsb_cfgP224CXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc2sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc2sm_LDADD = libsb_cfgP224CXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc8sm.a and securebootsim_cfgP224CXPc8sm
libsb_cfgP224CXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc8sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc8sm_LDADD = libsb_cfgP224CXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc0pk.a and securebootsim_cfgP224IPc0pk
libsb_cfgP224IPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224IPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224IPc0pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc0pk_LDADD = libsb_cfgP224IPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc1pk.a and securebootsim_cfgP224IPc1pk
libsb_cfgP224IPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224IPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224IPc1pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc1pk_LDADD = libsb_cfgP224IPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc2pk.a and securebootsim_cfgP224IPc2pk
libsb_cfgP224IPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224IPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224IPc2pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc2pk_LDADD = libsb_cfgP224IPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc8pk.a and securebootsim_cfgP224IPc8pk
libsb_cfgP224IPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224IPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224IPc8pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc8pk_LDADD = libsb_cfgP224IPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc0pk.a and securebootsim_cfgP224CPc0pk
libsb_cfgP224CPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc0pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc0pk_LDADD = libsb_cfgP224CPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc1pk.a and securebootsim_cfgP224CPc1pk
libsb_cfgP224CPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc1pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc1pk_LDADD = libsb_cfgP224CPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc2pk.a and securebootsim_cfgP224CPc2pk
libsb_cfgP224CPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc2pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc2pk_LDADD = libsb_cfgP224CPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc8pk.a and securebootsim_cfgP224CPc8pk
libsb_cfgP224CPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc8pk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc8pk_LDADD = libsb_cfgP224CPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc0pk.a and securebootsim_cfgP224CXPc0pk
libsb_cfgP224CXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc0pk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc0pk_LDADD = libsb_cfgP224CXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc1pk.a and securebootsim_cfgP224CXPc1pk
libsb_cfgP224CXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc1pk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc1pk_LDADD = libsb_cfgP224CXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc2pk.a and securebootsim_cfgP224CXPc2pk
libsb_cfgP224CXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc2pk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc2pk_LDADD = libsb_cfgP224CXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc8pk.a and securebootsim_cfgP224CXPc8pk
libsb_cfgP224CXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP224CXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc8pk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc8pk_LDADD = libsb_cfgP224CXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc0pe.a and securebootsim_cfgP224IPc0pe
libsb_cfgP224IPc0pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc0pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224IPc0pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc0pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc0pe_LDADD = libsb_cfgP224IPc0pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc0pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc1pe.a and securebootsim_cfgP224IPc1pe
libsb_cfgP224IPc1pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc1pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224IPc1pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc1pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc1pe_LDADD = libsb_cfgP224IPc1pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc1pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc2pe.a and securebootsim_cfgP224IPc2pe
libsb_cfgP224IPc2pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc2pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224IPc2pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc2pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc2pe_LDADD = libsb_cfgP224IPc2pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc2pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc8pe.a and securebootsim_cfgP224IPc8pe
libsb_cfgP224IPc8pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224IPc8pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224IPc8pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc8pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc8pe_LDADD = libsb_cfgP224IPc8pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc8pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc0pe.a and securebootsim_cfgP224CPc0pe
libsb_cfgP224CPc0pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc0pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc0pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc0pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc0pe_LDADD = libsb_cfgP224CPc0pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc0pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc1pe.a and securebootsim_cfgP224CPc1pe
libsb_cfgP224CPc1pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc1pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc1pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc1pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc1pe_LDADD = libsb_cfgP224CPc1pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc1pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc2pe.a and securebootsim_cfgP224CPc2pe
libsb_cfgP224CPc2pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc2pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc2pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc2pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc2pe_LDADD = libsb_cfgP224CPc2pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc2pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc8pe.a and securebootsim_cfgP224CPc8pe
libsb_cfgP224CPc8pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPc8pe_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc8pe_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc8pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc8pe_LDADD = libsb_cfgP224CPc8pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc8pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc0pe.a and securebootsim_cfgP224CXPc0pe
libsb_cfgP224CXPc0pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc0pe_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc0pe_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc0pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc0pe_LDADD = libsb_cfgP224CXPc0pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc0pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc1pe.a and securebootsim_cfgP224CXPc1pe
libsb_cfgP224CXPc1pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc1pe_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc1pe_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc1pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc1pe_LDADD = libsb_cfgP224CXPc1pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc1pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc2pe.a and securebootsim_cfgP224CXPc2pe
libsb_cfgP224CXPc2pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc2pe_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc2pe_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc2pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc2pe_LDADD = libsb_cfgP224CXPc2pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc2pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc8pe.a and securebootsim_cfgP224CXPc8pe
libsb_cfgP224CXPc8pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha224.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPc8pe_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc8pe_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc8pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc8pe_LDADD = libsb_cfgP224CXPc8pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc8pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc0pepk.a and securebootsim_cfgP224IPc0pepk
libsb_cfgP224IPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224IPc0pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc0pepk_LDADD = libsb_cfgP224IPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc1pepk.a and securebootsim_cfgP224IPc1pepk
libsb_cfgP224IPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224IPc1pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc1pepk_LDADD = libsb_cfgP224IPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc2pepk.a and securebootsim_cfgP224IPc2pepk
libsb_cfgP224IPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224IPc2pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc2pepk_LDADD = libsb_cfgP224IPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224IPc8pepk.a and securebootsim_cfgP224IPc8pepk
libsb_cfgP224IPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224IPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224IPc8pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP224IPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP224IPc8pepk_LDADD = libsb_cfgP224IPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224IPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc0pepk.a and securebootsim_cfgP224CPc0pepk
libsb_cfgP224CPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc0pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc0pepk_LDADD = libsb_cfgP224CPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc1pepk.a and securebootsim_cfgP224CPc1pepk
libsb_cfgP224CPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc1pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc1pepk_LDADD = libsb_cfgP224CPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc2pepk.a and securebootsim_cfgP224CPc2pepk
libsb_cfgP224CPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc2pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc2pepk_LDADD = libsb_cfgP224CPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPc8pepk.a and securebootsim_cfgP224CPc8pepk
libsb_cfgP224CPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPc8pepk_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPc8pepk_LDADD = libsb_cfgP224CPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc0pepk.a and securebootsim_cfgP224CXPc0pepk
libsb_cfgP224CXPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc0pepk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc0pepk_LDADD = libsb_cfgP224CXPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc1pepk.a and securebootsim_cfgP224CXPc1pepk
libsb_cfgP224CXPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc1pepk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc1pepk_LDADD = libsb_cfgP224CXPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc2pepk.a and securebootsim_cfgP224CXPc2pepk
libsb_cfgP224CXPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc2pepk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc2pepk_LDADD = libsb_cfgP224CXPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPc8pepk.a and securebootsim_cfgP224CXPc8pepk
libsb_cfgP224CXPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha224.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP224CXPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPc8pepk_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPc8pepk_LDADD = libsb_cfgP224CXPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPKc0sw.a and securebootsim_cfgP224CPKc0sw
libsb_cfgP224CPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPKc0sw_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPKc0sw_LDADD = libsb_cfgP224CPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPKc1sw.a and securebootsim_cfgP224CPKc1sw
libsb_cfgP224CPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPKc1sw_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPKc1sw_LDADD = libsb_cfgP224CPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPKc2sw.a and securebootsim_cfgP224CPKc2sw
libsb_cfgP224CPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPKc2sw_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPKc2sw_LDADD = libsb_cfgP224CPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CPKc8sw.a and securebootsim_cfgP224CPKc8sw
libsb_cfgP224CPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CPKc8sw_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CPKc8sw_LDADD = libsb_cfgP224CPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPKc0sw.a and securebootsim_cfgP224CXPKc0sw
libsb_cfgP224CXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPKc0sw_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPKc0sw_LDADD = libsb_cfgP224CXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPKc1sw.a and securebootsim_cfgP224CXPKc1sw
libsb_cfgP224CXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPKc1sw_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPKc1sw_LDADD = libsb_cfgP224CXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPKc2sw.a and securebootsim_cfgP224CXPKc2sw
libsb_cfgP224CXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPKc2sw_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPKc2sw_LDADD = libsb_cfgP224CXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXPKc8sw.a and securebootsim_cfgP224CXPKc8sw
libsb_cfgP224CXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA224_SOURCES)
libsb_cfgP224CXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP224CXPKc8sw_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXPKc8sw_LDADD = libsb_cfgP224CXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNc0sm.a and securebootsim_cfgP224CNc0sm
libsb_cfgP224CNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224CNc0sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNc0sm_LDADD = libsb_cfgP224CNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNc1sm.a and securebootsim_cfgP224CNc1sm
libsb_cfgP224CNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224CNc1sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNc1sm_LDADD = libsb_cfgP224CNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNc2sm.a and securebootsim_cfgP224CNc2sm
libsb_cfgP224CNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224CNc2sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNc2sm_LDADD = libsb_cfgP224CNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNc8sm.a and securebootsim_cfgP224CNc8sm
libsb_cfgP224CNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224CNc8sm_CPPFLAGS = $(SECUREBOOTSIM224_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNc8sm_LDADD = libsb_cfgP224CNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNc0sm.a and securebootsim_cfgP224CXNc0sm
libsb_cfgP224CXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224CXNc0sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNc0sm_LDADD = libsb_cfgP224CXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNc1sm.a and securebootsim_cfgP224CXNc1sm
libsb_cfgP224CXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224CXNc1sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNc1sm_LDADD = libsb_cfgP224CXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNc2sm.a and securebootsim_cfgP224CXNc2sm
libsb_cfgP224CXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224CXNc2sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNc2sm_LDADD = libsb_cfgP224CXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNc8sm.a and securebootsim_cfgP224CXNc8sm
libsb_cfgP224CXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224CXNc8sm_CPPFLAGS = $(SECUREBOOTSIM224AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNc8sm_LDADD = libsb_cfgP224CXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNKc0sm.a and securebootsim_cfgP224CNKc0sm
libsb_cfgP224CNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP224CNKc0sm_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNKc0sm_LDADD = libsb_cfgP224CNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNKc1sm.a and securebootsim_cfgP224CNKc1sm
libsb_cfgP224CNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP224CNKc1sm_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNKc1sm_LDADD = libsb_cfgP224CNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNKc2sm.a and securebootsim_cfgP224CNKc2sm
libsb_cfgP224CNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP224CNKc2sm_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNKc2sm_LDADD = libsb_cfgP224CNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CNKc8sm.a and securebootsim_cfgP224CNKc8sm
libsb_cfgP224CNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP224CNKc8sm_CPPFLAGS = $(SECUREBOOTSIM224KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CNKc8sm_LDADD = libsb_cfgP224CNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNKc0sm.a and securebootsim_cfgP224CXNKc0sm
libsb_cfgP224CXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP224CXNKc0sm_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNKc0sm_LDADD = libsb_cfgP224CXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNKc1sm.a and securebootsim_cfgP224CXNKc1sm
libsb_cfgP224CXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP224CXNKc1sm_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNKc1sm_LDADD = libsb_cfgP224CXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNKc2sm.a and securebootsim_cfgP224CXNKc2sm
libsb_cfgP224CXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP224CXNKc2sm_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNKc2sm_LDADD = libsb_cfgP224CXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP224CXNKc8sm.a and securebootsim_cfgP224CXNKc8sm
libsb_cfgP224CXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP224CXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID224KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP224CXNKc8sm_CPPFLAGS = $(SECUREBOOTSIM224KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP224CXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP224CXNKc8sm_LDADD = libsb_cfgP224CXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO224_A) libsb_cfgP224CXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc0sw.a and securebootsim_cfgP256IPc0sw
libsb_cfgP256IPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256IPc0sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES)
securebootsim_cfgP256IPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc0sw_LDADD = libsb_cfgP256IPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc1sw.a and securebootsim_cfgP256IPc1sw
libsb_cfgP256IPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256IPc1sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES)
securebootsim_cfgP256IPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc1sw_LDADD = libsb_cfgP256IPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc2sw.a and securebootsim_cfgP256IPc2sw
libsb_cfgP256IPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256IPc2sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES)
securebootsim_cfgP256IPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc2sw_LDADD = libsb_cfgP256IPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc8sw.a and securebootsim_cfgP256IPc8sw
libsb_cfgP256IPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256IPc8sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES)
securebootsim_cfgP256IPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc8sw_LDADD = libsb_cfgP256IPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc0sw.a and securebootsim_cfgP256CPc0sw
libsb_cfgP256CPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc0sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc0sw_LDADD = libsb_cfgP256CPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc1sw.a and securebootsim_cfgP256CPc1sw
libsb_cfgP256CPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc1sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc1sw_LDADD = libsb_cfgP256CPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc2sw.a and securebootsim_cfgP256CPc2sw
libsb_cfgP256CPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc2sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc2sw_LDADD = libsb_cfgP256CPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc8sw.a and securebootsim_cfgP256CPc8sw
libsb_cfgP256CPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc8sw_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc8sw_LDADD = libsb_cfgP256CPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc0sw.a and securebootsim_cfgP256CXPc0sw
libsb_cfgP256CXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc0sw_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc0sw_LDADD = libsb_cfgP256CXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc1sw.a and securebootsim_cfgP256CXPc1sw
libsb_cfgP256CXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc1sw_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc1sw_LDADD = libsb_cfgP256CXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc2sw.a and securebootsim_cfgP256CXPc2sw
libsb_cfgP256CXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc2sw_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc2sw_LDADD = libsb_cfgP256CXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc8sw.a and securebootsim_cfgP256CXPc8sw
libsb_cfgP256CXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc8sw_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc8sw_LDADD = libsb_cfgP256CXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc0sm.a and securebootsim_cfgP256IPc0sm
libsb_cfgP256IPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256IPc0sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc0sm_LDADD = libsb_cfgP256IPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc1sm.a and securebootsim_cfgP256IPc1sm
libsb_cfgP256IPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256IPc1sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc1sm_LDADD = libsb_cfgP256IPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc2sm.a and securebootsim_cfgP256IPc2sm
libsb_cfgP256IPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256IPc2sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc2sm_LDADD = libsb_cfgP256IPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc8sm.a and securebootsim_cfgP256IPc8sm
libsb_cfgP256IPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256IPc8sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc8sm_LDADD = libsb_cfgP256IPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc0sm.a and securebootsim_cfgP256CPc0sm
libsb_cfgP256CPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc0sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc0sm_LDADD = libsb_cfgP256CPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc1sm.a and securebootsim_cfgP256CPc1sm
libsb_cfgP256CPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc1sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc1sm_LDADD = libsb_cfgP256CPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc2sm.a and securebootsim_cfgP256CPc2sm
libsb_cfgP256CPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc2sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc2sm_LDADD = libsb_cfgP256CPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc8sm.a and securebootsim_cfgP256CPc8sm
libsb_cfgP256CPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc8sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc8sm_LDADD = libsb_cfgP256CPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc0sm.a and securebootsim_cfgP256CXPc0sm
libsb_cfgP256CXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc0sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc0sm_LDADD = libsb_cfgP256CXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc1sm.a and securebootsim_cfgP256CXPc1sm
libsb_cfgP256CXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc1sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc1sm_LDADD = libsb_cfgP256CXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc2sm.a and securebootsim_cfgP256CXPc2sm
libsb_cfgP256CXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc2sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc2sm_LDADD = libsb_cfgP256CXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc8sm.a and securebootsim_cfgP256CXPc8sm
libsb_cfgP256CXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc8sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc8sm_LDADD = libsb_cfgP256CXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc0pk.a and securebootsim_cfgP256IPc0pk
libsb_cfgP256IPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256IPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256IPc0pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc0pk_LDADD = libsb_cfgP256IPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc1pk.a and securebootsim_cfgP256IPc1pk
libsb_cfgP256IPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256IPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256IPc1pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc1pk_LDADD = libsb_cfgP256IPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc2pk.a and securebootsim_cfgP256IPc2pk
libsb_cfgP256IPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256IPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256IPc2pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc2pk_LDADD = libsb_cfgP256IPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc8pk.a and securebootsim_cfgP256IPc8pk
libsb_cfgP256IPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256IPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256IPc8pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc8pk_LDADD = libsb_cfgP256IPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc0pk.a and securebootsim_cfgP256CPc0pk
libsb_cfgP256CPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc0pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc0pk_LDADD = libsb_cfgP256CPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc1pk.a and securebootsim_cfgP256CPc1pk
libsb_cfgP256CPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc1pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc1pk_LDADD = libsb_cfgP256CPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc2pk.a and securebootsim_cfgP256CPc2pk
libsb_cfgP256CPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc2pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc2pk_LDADD = libsb_cfgP256CPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc8pk.a and securebootsim_cfgP256CPc8pk
libsb_cfgP256CPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc8pk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc8pk_LDADD = libsb_cfgP256CPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc0pk.a and securebootsim_cfgP256CXPc0pk
libsb_cfgP256CXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc0pk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc0pk_LDADD = libsb_cfgP256CXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc1pk.a and securebootsim_cfgP256CXPc1pk
libsb_cfgP256CXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc1pk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc1pk_LDADD = libsb_cfgP256CXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc2pk.a and securebootsim_cfgP256CXPc2pk
libsb_cfgP256CXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc2pk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc2pk_LDADD = libsb_cfgP256CXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc8pk.a and securebootsim_cfgP256CXPc8pk
libsb_cfgP256CXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES)
libsb_cfgP256CXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc8pk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc8pk_LDADD = libsb_cfgP256CXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc0pe.a and securebootsim_cfgP256IPc0pe
libsb_cfgP256IPc0pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc0pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256IPc0pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc0pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc0pe_LDADD = libsb_cfgP256IPc0pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc0pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc1pe.a and securebootsim_cfgP256IPc1pe
libsb_cfgP256IPc1pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc1pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256IPc1pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc1pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc1pe_LDADD = libsb_cfgP256IPc1pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc1pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc2pe.a and securebootsim_cfgP256IPc2pe
libsb_cfgP256IPc2pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc2pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256IPc2pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc2pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc2pe_LDADD = libsb_cfgP256IPc2pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc2pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc8pe.a and securebootsim_cfgP256IPc8pe
libsb_cfgP256IPc8pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256IPc8pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256IPc8pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc8pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc8pe_LDADD = libsb_cfgP256IPc8pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc8pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc0pe.a and securebootsim_cfgP256CPc0pe
libsb_cfgP256CPc0pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc0pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc0pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc0pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc0pe_LDADD = libsb_cfgP256CPc0pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc0pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc1pe.a and securebootsim_cfgP256CPc1pe
libsb_cfgP256CPc1pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc1pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc1pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc1pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc1pe_LDADD = libsb_cfgP256CPc1pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc1pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc2pe.a and securebootsim_cfgP256CPc2pe
libsb_cfgP256CPc2pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc2pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc2pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc2pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc2pe_LDADD = libsb_cfgP256CPc2pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc2pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc8pe.a and securebootsim_cfgP256CPc8pe
libsb_cfgP256CPc8pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPc8pe_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc8pe_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc8pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc8pe_LDADD = libsb_cfgP256CPc8pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc8pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc0pe.a and securebootsim_cfgP256CXPc0pe
libsb_cfgP256CXPc0pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc0pe_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc0pe_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc0pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc0pe_LDADD = libsb_cfgP256CXPc0pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc0pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc1pe.a and securebootsim_cfgP256CXPc1pe
libsb_cfgP256CXPc1pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc1pe_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc1pe_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc1pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc1pe_LDADD = libsb_cfgP256CXPc1pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc1pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc2pe.a and securebootsim_cfgP256CXPc2pe
libsb_cfgP256CXPc2pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc2pe_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc2pe_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc2pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc2pe_LDADD = libsb_cfgP256CXPc2pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc2pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc8pe.a and securebootsim_cfgP256CXPc8pe
libsb_cfgP256CXPc8pe_a_SOURCES =  $(SB_PE_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PE/src/sbpe_api_decrypt.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_hw_init.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_eip93_sha256.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_publicdata.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PE/src/sbpe_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPc8pe_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc8pe_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc8pe_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc8pe_LDADD = libsb_cfgP256CXPc8pe.a $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc8pe.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc0pepk.a and securebootsim_cfgP256IPc0pepk
libsb_cfgP256IPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256IPc0pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc0pepk_LDADD = libsb_cfgP256IPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc1pepk.a and securebootsim_cfgP256IPc1pepk
libsb_cfgP256IPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256IPc1pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc1pepk_LDADD = libsb_cfgP256IPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc2pepk.a and securebootsim_cfgP256IPc2pepk
libsb_cfgP256IPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256IPc2pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc2pepk_LDADD = libsb_cfgP256IPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256IPc8pepk.a and securebootsim_cfgP256IPc8pepk
libsb_cfgP256IPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256IPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256IPc8pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP256IPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP256IPc8pepk_LDADD = libsb_cfgP256IPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256IPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc0pepk.a and securebootsim_cfgP256CPc0pepk
libsb_cfgP256CPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc0pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc0pepk_LDADD = libsb_cfgP256CPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc1pepk.a and securebootsim_cfgP256CPc1pepk
libsb_cfgP256CPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc1pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc1pepk_LDADD = libsb_cfgP256CPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc2pepk.a and securebootsim_cfgP256CPc2pepk
libsb_cfgP256CPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc2pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc2pepk_LDADD = libsb_cfgP256CPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPc8pepk.a and securebootsim_cfgP256CPc8pepk
libsb_cfgP256CPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPc8pepk_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPc8pepk_LDADD = libsb_cfgP256CPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc0pepk.a and securebootsim_cfgP256CXPc0pepk
libsb_cfgP256CXPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc0pepk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc0pepk_LDADD = libsb_cfgP256CXPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc1pepk.a and securebootsim_cfgP256CXPc1pepk
libsb_cfgP256CXPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc1pepk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc1pepk_LDADD = libsb_cfgP256CXPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc2pepk.a and securebootsim_cfgP256CXPc2pepk
libsb_cfgP256CXPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc2pepk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc2pepk_LDADD = libsb_cfgP256CXPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPc8pepk.a and securebootsim_cfgP256CXPc8pepk
libsb_cfgP256CXPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP256CXPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPc8pepk_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPc8pepk_LDADD = libsb_cfgP256CXPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPKc0sw.a and securebootsim_cfgP256CPKc0sw
libsb_cfgP256CPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPKc0sw_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPKc0sw_LDADD = libsb_cfgP256CPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPKc1sw.a and securebootsim_cfgP256CPKc1sw
libsb_cfgP256CPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPKc1sw_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPKc1sw_LDADD = libsb_cfgP256CPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPKc2sw.a and securebootsim_cfgP256CPKc2sw
libsb_cfgP256CPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPKc2sw_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPKc2sw_LDADD = libsb_cfgP256CPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CPKc8sw.a and securebootsim_cfgP256CPKc8sw
libsb_cfgP256CPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CPKc8sw_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CPKc8sw_LDADD = libsb_cfgP256CPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPKc0sw.a and securebootsim_cfgP256CXPKc0sw
libsb_cfgP256CXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPKc0sw_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPKc0sw_LDADD = libsb_cfgP256CXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPKc1sw.a and securebootsim_cfgP256CXPKc1sw
libsb_cfgP256CXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPKc1sw_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPKc1sw_LDADD = libsb_cfgP256CXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPKc2sw.a and securebootsim_cfgP256CXPKc2sw
libsb_cfgP256CXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPKc2sw_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPKc2sw_LDADD = libsb_cfgP256CXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXPKc8sw.a and securebootsim_cfgP256CXPKc8sw
libsb_cfgP256CXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_ECDSA256_SOURCES)
libsb_cfgP256CXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP256CXPKc8sw_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXPKc8sw_LDADD = libsb_cfgP256CXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNc0sm.a and securebootsim_cfgP256CNc0sm
libsb_cfgP256CNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256CNc0sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNc0sm_LDADD = libsb_cfgP256CNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNc1sm.a and securebootsim_cfgP256CNc1sm
libsb_cfgP256CNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256CNc1sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNc1sm_LDADD = libsb_cfgP256CNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNc2sm.a and securebootsim_cfgP256CNc2sm
libsb_cfgP256CNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256CNc2sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNc2sm_LDADD = libsb_cfgP256CNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNc8sm.a and securebootsim_cfgP256CNc8sm
libsb_cfgP256CNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256CNc8sm_CPPFLAGS = $(SECUREBOOTSIM256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNc8sm_LDADD = libsb_cfgP256CNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNc0sm.a and securebootsim_cfgP256CXNc0sm
libsb_cfgP256CXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256CXNc0sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNc0sm_LDADD = libsb_cfgP256CXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNc1sm.a and securebootsim_cfgP256CXNc1sm
libsb_cfgP256CXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256CXNc1sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNc1sm_LDADD = libsb_cfgP256CXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNc2sm.a and securebootsim_cfgP256CXNc2sm
libsb_cfgP256CXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256CXNc2sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNc2sm_LDADD = libsb_cfgP256CXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNc8sm.a and securebootsim_cfgP256CXNc8sm
libsb_cfgP256CXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256CXNc8sm_CPPFLAGS = $(SECUREBOOTSIM256AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNc8sm_LDADD = libsb_cfgP256CXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNKc0sm.a and securebootsim_cfgP256CNKc0sm
libsb_cfgP256CNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP256CNKc0sm_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNKc0sm_LDADD = libsb_cfgP256CNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNKc1sm.a and securebootsim_cfgP256CNKc1sm
libsb_cfgP256CNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP256CNKc1sm_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNKc1sm_LDADD = libsb_cfgP256CNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNKc2sm.a and securebootsim_cfgP256CNKc2sm
libsb_cfgP256CNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP256CNKc2sm_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNKc2sm_LDADD = libsb_cfgP256CNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CNKc8sm.a and securebootsim_cfgP256CNKc8sm
libsb_cfgP256CNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP256CNKc8sm_CPPFLAGS = $(SECUREBOOTSIM256KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CNKc8sm_LDADD = libsb_cfgP256CNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNKc0sm.a and securebootsim_cfgP256CXNKc0sm
libsb_cfgP256CXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP256CXNKc0sm_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNKc0sm_LDADD = libsb_cfgP256CXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNKc1sm.a and securebootsim_cfgP256CXNKc1sm
libsb_cfgP256CXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP256CXNKc1sm_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNKc1sm_LDADD = libsb_cfgP256CXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNKc2sm.a and securebootsim_cfgP256CXNKc2sm
libsb_cfgP256CXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP256CXNKc2sm_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNKc2sm_LDADD = libsb_cfgP256CXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP256CXNKc8sm.a and securebootsim_cfgP256CXNKc8sm
libsb_cfgP256CXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP256CXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID256KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP256CXNKc8sm_CPPFLAGS = $(SECUREBOOTSIM256KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP256CXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP256CXNKc8sm_LDADD = libsb_cfgP256CXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO256_A) libsb_cfgP256CXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc0sw.a and securebootsim_cfgP384IPc0sw
libsb_cfgP384IPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384IPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP384IPc0sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES)
securebootsim_cfgP384IPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc0sw_LDADD = libsb_cfgP384IPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc1sw.a and securebootsim_cfgP384IPc1sw
libsb_cfgP384IPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384IPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP384IPc1sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES)
securebootsim_cfgP384IPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc1sw_LDADD = libsb_cfgP384IPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc2sw.a and securebootsim_cfgP384IPc2sw
libsb_cfgP384IPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384IPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP384IPc2sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES)
securebootsim_cfgP384IPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc2sw_LDADD = libsb_cfgP384IPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc8sw.a and securebootsim_cfgP384IPc8sw
libsb_cfgP384IPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384IPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP384IPc8sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES)
securebootsim_cfgP384IPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc8sw_LDADD = libsb_cfgP384IPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc0sw.a and securebootsim_cfgP384CPc0sw
libsb_cfgP384CPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc0sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc0sw_LDADD = libsb_cfgP384CPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc1sw.a and securebootsim_cfgP384CPc1sw
libsb_cfgP384CPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc1sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc1sw_LDADD = libsb_cfgP384CPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc2sw.a and securebootsim_cfgP384CPc2sw
libsb_cfgP384CPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc2sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc2sw_LDADD = libsb_cfgP384CPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc8sw.a and securebootsim_cfgP384CPc8sw
libsb_cfgP384CPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc8sw_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc8sw_LDADD = libsb_cfgP384CPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc0sw.a and securebootsim_cfgP384CXPc0sw
libsb_cfgP384CXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc0sw_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc0sw_LDADD = libsb_cfgP384CXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc1sw.a and securebootsim_cfgP384CXPc1sw
libsb_cfgP384CXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc1sw_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc1sw_LDADD = libsb_cfgP384CXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc2sw.a and securebootsim_cfgP384CXPc2sw
libsb_cfgP384CXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc2sw_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc2sw_LDADD = libsb_cfgP384CXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc8sw.a and securebootsim_cfgP384CXPc8sw
libsb_cfgP384CXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc8sw_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc8sw_LDADD = libsb_cfgP384CXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc0sm.a and securebootsim_cfgP384IPc0sm
libsb_cfgP384IPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384IPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP384IPc0sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc0sm_LDADD = libsb_cfgP384IPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc1sm.a and securebootsim_cfgP384IPc1sm
libsb_cfgP384IPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384IPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP384IPc1sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc1sm_LDADD = libsb_cfgP384IPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc2sm.a and securebootsim_cfgP384IPc2sm
libsb_cfgP384IPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384IPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP384IPc2sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc2sm_LDADD = libsb_cfgP384IPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc8sm.a and securebootsim_cfgP384IPc8sm
libsb_cfgP384IPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384IPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP384IPc8sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc8sm_LDADD = libsb_cfgP384IPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc0sm.a and securebootsim_cfgP384CPc0sm
libsb_cfgP384CPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc0sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc0sm_LDADD = libsb_cfgP384CPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc1sm.a and securebootsim_cfgP384CPc1sm
libsb_cfgP384CPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc1sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc1sm_LDADD = libsb_cfgP384CPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc2sm.a and securebootsim_cfgP384CPc2sm
libsb_cfgP384CPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc2sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc2sm_LDADD = libsb_cfgP384CPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc8sm.a and securebootsim_cfgP384CPc8sm
libsb_cfgP384CPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc8sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc8sm_LDADD = libsb_cfgP384CPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc0sm.a and securebootsim_cfgP384CXPc0sm
libsb_cfgP384CXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc0sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc0sm_LDADD = libsb_cfgP384CXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc1sm.a and securebootsim_cfgP384CXPc1sm
libsb_cfgP384CXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc1sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc1sm_LDADD = libsb_cfgP384CXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc2sm.a and securebootsim_cfgP384CXPc2sm
libsb_cfgP384CXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc2sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc2sm_LDADD = libsb_cfgP384CXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc8sm.a and securebootsim_cfgP384CXPc8sm
libsb_cfgP384CXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP384CXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc8sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc8sm_LDADD = libsb_cfgP384CXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc0pk.a and securebootsim_cfgP384IPc0pk
libsb_cfgP384IPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384IPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP384IPc0pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc0pk_LDADD = libsb_cfgP384IPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc1pk.a and securebootsim_cfgP384IPc1pk
libsb_cfgP384IPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384IPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP384IPc1pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc1pk_LDADD = libsb_cfgP384IPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc2pk.a and securebootsim_cfgP384IPc2pk
libsb_cfgP384IPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384IPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP384IPc2pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc2pk_LDADD = libsb_cfgP384IPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384IPc8pk.a and securebootsim_cfgP384IPc8pk
libsb_cfgP384IPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384IPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP384IPc8pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP384IPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP384IPc8pk_LDADD = libsb_cfgP384IPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384IPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc0pk.a and securebootsim_cfgP384CPc0pk
libsb_cfgP384CPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc0pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc0pk_LDADD = libsb_cfgP384CPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc1pk.a and securebootsim_cfgP384CPc1pk
libsb_cfgP384CPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc1pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc1pk_LDADD = libsb_cfgP384CPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc2pk.a and securebootsim_cfgP384CPc2pk
libsb_cfgP384CPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc2pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc2pk_LDADD = libsb_cfgP384CPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPc8pk.a and securebootsim_cfgP384CPc8pk
libsb_cfgP384CPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPc8pk_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPc8pk_LDADD = libsb_cfgP384CPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc0pk.a and securebootsim_cfgP384CXPc0pk
libsb_cfgP384CXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc0pk_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc0pk_LDADD = libsb_cfgP384CXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc1pk.a and securebootsim_cfgP384CXPc1pk
libsb_cfgP384CXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc1pk_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc1pk_LDADD = libsb_cfgP384CXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc2pk.a and securebootsim_cfgP384CXPc2pk
libsb_cfgP384CXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc2pk_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc2pk_LDADD = libsb_cfgP384CXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPc8pk.a and securebootsim_cfgP384CXPc8pk
libsb_cfgP384CXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP384CXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPc8pk_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPc8pk_LDADD = libsb_cfgP384CXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPKc0sw.a and securebootsim_cfgP384CPKc0sw
libsb_cfgP384CPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPKc0sw_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPKc0sw_LDADD = libsb_cfgP384CPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPKc1sw.a and securebootsim_cfgP384CPKc1sw
libsb_cfgP384CPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPKc1sw_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPKc1sw_LDADD = libsb_cfgP384CPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPKc2sw.a and securebootsim_cfgP384CPKc2sw
libsb_cfgP384CPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPKc2sw_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPKc2sw_LDADD = libsb_cfgP384CPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CPKc8sw.a and securebootsim_cfgP384CPKc8sw
libsb_cfgP384CPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CPKc8sw_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CPKc8sw_LDADD = libsb_cfgP384CPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPKc0sw.a and securebootsim_cfgP384CXPKc0sw
libsb_cfgP384CXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPKc0sw_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPKc0sw_LDADD = libsb_cfgP384CXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPKc1sw.a and securebootsim_cfgP384CXPKc1sw
libsb_cfgP384CXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPKc1sw_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPKc1sw_LDADD = libsb_cfgP384CXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPKc2sw.a and securebootsim_cfgP384CXPKc2sw
libsb_cfgP384CXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPKc2sw_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPKc2sw_LDADD = libsb_cfgP384CXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXPKc8sw.a and securebootsim_cfgP384CXPKc8sw
libsb_cfgP384CXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA384_SOURCES)
libsb_cfgP384CXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP384CXPKc8sw_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXPKc8sw_LDADD = libsb_cfgP384CXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNc0sm.a and securebootsim_cfgP384CNc0sm
libsb_cfgP384CNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP384CNc0sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNc0sm_LDADD = libsb_cfgP384CNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNc1sm.a and securebootsim_cfgP384CNc1sm
libsb_cfgP384CNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP384CNc1sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNc1sm_LDADD = libsb_cfgP384CNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNc2sm.a and securebootsim_cfgP384CNc2sm
libsb_cfgP384CNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP384CNc2sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNc2sm_LDADD = libsb_cfgP384CNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNc8sm.a and securebootsim_cfgP384CNc8sm
libsb_cfgP384CNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP384CNc8sm_CPPFLAGS = $(SECUREBOOTSIM384_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNc8sm_LDADD = libsb_cfgP384CNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNc0sm.a and securebootsim_cfgP384CXNc0sm
libsb_cfgP384CXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP384CXNc0sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNc0sm_LDADD = libsb_cfgP384CXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNc1sm.a and securebootsim_cfgP384CXNc1sm
libsb_cfgP384CXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP384CXNc1sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNc1sm_LDADD = libsb_cfgP384CXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNc2sm.a and securebootsim_cfgP384CXNc2sm
libsb_cfgP384CXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP384CXNc2sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNc2sm_LDADD = libsb_cfgP384CXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNc8sm.a and securebootsim_cfgP384CXNc8sm
libsb_cfgP384CXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP384CXNc8sm_CPPFLAGS = $(SECUREBOOTSIM384AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNc8sm_LDADD = libsb_cfgP384CXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNKc0sm.a and securebootsim_cfgP384CNKc0sm
libsb_cfgP384CNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP384CNKc0sm_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNKc0sm_LDADD = libsb_cfgP384CNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNKc1sm.a and securebootsim_cfgP384CNKc1sm
libsb_cfgP384CNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP384CNKc1sm_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNKc1sm_LDADD = libsb_cfgP384CNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNKc2sm.a and securebootsim_cfgP384CNKc2sm
libsb_cfgP384CNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP384CNKc2sm_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNKc2sm_LDADD = libsb_cfgP384CNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CNKc8sm.a and securebootsim_cfgP384CNKc8sm
libsb_cfgP384CNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP384CNKc8sm_CPPFLAGS = $(SECUREBOOTSIM384KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CNKc8sm_LDADD = libsb_cfgP384CNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNKc0sm.a and securebootsim_cfgP384CXNKc0sm
libsb_cfgP384CXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP384CXNKc0sm_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNKc0sm_LDADD = libsb_cfgP384CXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNKc1sm.a and securebootsim_cfgP384CXNKc1sm
libsb_cfgP384CXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP384CXNKc1sm_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNKc1sm_LDADD = libsb_cfgP384CXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNKc2sm.a and securebootsim_cfgP384CXNKc2sm
libsb_cfgP384CXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP384CXNKc2sm_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNKc2sm_LDADD = libsb_cfgP384CXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP384CXNKc8sm.a and securebootsim_cfgP384CXNKc8sm
libsb_cfgP384CXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP384CXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID384KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP384CXNKc8sm_CPPFLAGS = $(SECUREBOOTSIM384KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP384CXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP384CXNKc8sm_LDADD = libsb_cfgP384CXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO384_A) libsb_cfgP384CXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc0sw.a and securebootsim_cfgP521IPc0sw
libsb_cfgP521IPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521IPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP521IPc0sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES)
securebootsim_cfgP521IPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc0sw_LDADD = libsb_cfgP521IPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc1sw.a and securebootsim_cfgP521IPc1sw
libsb_cfgP521IPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521IPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP521IPc1sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES)
securebootsim_cfgP521IPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc1sw_LDADD = libsb_cfgP521IPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc2sw.a and securebootsim_cfgP521IPc2sw
libsb_cfgP521IPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521IPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP521IPc2sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES)
securebootsim_cfgP521IPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc2sw_LDADD = libsb_cfgP521IPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc8sw.a and securebootsim_cfgP521IPc8sw
libsb_cfgP521IPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521IPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP521IPc8sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES)
securebootsim_cfgP521IPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc8sw_LDADD = libsb_cfgP521IPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc0sw.a and securebootsim_cfgP521CPc0sw
libsb_cfgP521CPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc0sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc0sw_LDADD = libsb_cfgP521CPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc1sw.a and securebootsim_cfgP521CPc1sw
libsb_cfgP521CPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc1sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc1sw_LDADD = libsb_cfgP521CPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc2sw.a and securebootsim_cfgP521CPc2sw
libsb_cfgP521CPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc2sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc2sw_LDADD = libsb_cfgP521CPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc8sw.a and securebootsim_cfgP521CPc8sw
libsb_cfgP521CPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc8sw_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc8sw_LDADD = libsb_cfgP521CPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc0sw.a and securebootsim_cfgP521CXPc0sw
libsb_cfgP521CXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc0sw_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc0sw_LDADD = libsb_cfgP521CXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc1sw.a and securebootsim_cfgP521CXPc1sw
libsb_cfgP521CXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc1sw_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc1sw_LDADD = libsb_cfgP521CXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc2sw.a and securebootsim_cfgP521CXPc2sw
libsb_cfgP521CXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc2sw_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc2sw_LDADD = libsb_cfgP521CXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc8sw.a and securebootsim_cfgP521CXPc8sw
libsb_cfgP521CXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc8sw_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc8sw_LDADD = libsb_cfgP521CXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc0sm.a and securebootsim_cfgP521IPc0sm
libsb_cfgP521IPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521IPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP521IPc0sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc0sm_LDADD = libsb_cfgP521IPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc1sm.a and securebootsim_cfgP521IPc1sm
libsb_cfgP521IPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521IPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP521IPc1sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc1sm_LDADD = libsb_cfgP521IPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc2sm.a and securebootsim_cfgP521IPc2sm
libsb_cfgP521IPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521IPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP521IPc2sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc2sm_LDADD = libsb_cfgP521IPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc8sm.a and securebootsim_cfgP521IPc8sm
libsb_cfgP521IPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521IPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP521IPc8sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc8sm_LDADD = libsb_cfgP521IPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc0sm.a and securebootsim_cfgP521CPc0sm
libsb_cfgP521CPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc0sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc0sm_LDADD = libsb_cfgP521CPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc1sm.a and securebootsim_cfgP521CPc1sm
libsb_cfgP521CPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc1sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc1sm_LDADD = libsb_cfgP521CPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc2sm.a and securebootsim_cfgP521CPc2sm
libsb_cfgP521CPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc2sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc2sm_LDADD = libsb_cfgP521CPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc8sm.a and securebootsim_cfgP521CPc8sm
libsb_cfgP521CPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc8sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc8sm_LDADD = libsb_cfgP521CPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc0sm.a and securebootsim_cfgP521CXPc0sm
libsb_cfgP521CXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc0sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc0sm_LDADD = libsb_cfgP521CXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc1sm.a and securebootsim_cfgP521CXPc1sm
libsb_cfgP521CXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc1sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc1sm_LDADD = libsb_cfgP521CXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc2sm.a and securebootsim_cfgP521CXPc2sm
libsb_cfgP521CXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc2sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc2sm_LDADD = libsb_cfgP521CXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc8sm.a and securebootsim_cfgP521CXPc8sm
libsb_cfgP521CXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgP521CXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc8sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc8sm_LDADD = libsb_cfgP521CXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc0pk.a and securebootsim_cfgP521IPc0pk
libsb_cfgP521IPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521IPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP521IPc0pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc0pk_LDADD = libsb_cfgP521IPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc1pk.a and securebootsim_cfgP521IPc1pk
libsb_cfgP521IPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521IPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP521IPc1pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc1pk_LDADD = libsb_cfgP521IPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc2pk.a and securebootsim_cfgP521IPc2pk
libsb_cfgP521IPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521IPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP521IPc2pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc2pk_LDADD = libsb_cfgP521IPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521IPc8pk.a and securebootsim_cfgP521IPc8pk
libsb_cfgP521IPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521IPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP521IPc8pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgP521IPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgP521IPc8pk_LDADD = libsb_cfgP521IPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521IPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc0pk.a and securebootsim_cfgP521CPc0pk
libsb_cfgP521CPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc0pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc0pk_LDADD = libsb_cfgP521CPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc1pk.a and securebootsim_cfgP521CPc1pk
libsb_cfgP521CPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc1pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc1pk_LDADD = libsb_cfgP521CPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc2pk.a and securebootsim_cfgP521CPc2pk
libsb_cfgP521CPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc2pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc2pk_LDADD = libsb_cfgP521CPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPc8pk.a and securebootsim_cfgP521CPc8pk
libsb_cfgP521CPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPc8pk_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPc8pk_LDADD = libsb_cfgP521CPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc0pk.a and securebootsim_cfgP521CXPc0pk
libsb_cfgP521CXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc0pk_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc0pk_LDADD = libsb_cfgP521CXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc1pk.a and securebootsim_cfgP521CXPc1pk
libsb_cfgP521CXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc1pk_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc1pk_LDADD = libsb_cfgP521CXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc2pk.a and securebootsim_cfgP521CXPc2pk
libsb_cfgP521CXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc2pk_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc2pk_LDADD = libsb_cfgP521CXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPc8pk.a and securebootsim_cfgP521CXPc8pk
libsb_cfgP521CXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_ecdsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES)
libsb_cfgP521CXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPc8pk_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPc8pk_LDADD = libsb_cfgP521CXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPKc0sw.a and securebootsim_cfgP521CPKc0sw
libsb_cfgP521CPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPKc0sw_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPKc0sw_LDADD = libsb_cfgP521CPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPKc1sw.a and securebootsim_cfgP521CPKc1sw
libsb_cfgP521CPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPKc1sw_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPKc1sw_LDADD = libsb_cfgP521CPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPKc2sw.a and securebootsim_cfgP521CPKc2sw
libsb_cfgP521CPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPKc2sw_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPKc2sw_LDADD = libsb_cfgP521CPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CPKc8sw.a and securebootsim_cfgP521CPKc8sw
libsb_cfgP521CPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CPKc8sw_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CPKc8sw_LDADD = libsb_cfgP521CPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPKc0sw.a and securebootsim_cfgP521CXPKc0sw
libsb_cfgP521CXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPKc0sw_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPKc0sw_LDADD = libsb_cfgP521CXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPKc1sw.a and securebootsim_cfgP521CXPKc1sw
libsb_cfgP521CXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPKc1sw_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPKc1sw_LDADD = libsb_cfgP521CXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPKc2sw.a and securebootsim_cfgP521CXPKc2sw
libsb_cfgP521CXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPKc2sw_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPKc2sw_LDADD = libsb_cfgP521CXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXPKc8sw.a and securebootsim_cfgP521CXPKc8sw
libsb_cfgP521CXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA521_SOURCES)
libsb_cfgP521CXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgP521CXPKc8sw_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXPKc8sw_LDADD = libsb_cfgP521CXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNc0sm.a and securebootsim_cfgP521CNc0sm
libsb_cfgP521CNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP521CNc0sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNc0sm_LDADD = libsb_cfgP521CNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNc1sm.a and securebootsim_cfgP521CNc1sm
libsb_cfgP521CNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP521CNc1sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNc1sm_LDADD = libsb_cfgP521CNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNc2sm.a and securebootsim_cfgP521CNc2sm
libsb_cfgP521CNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP521CNc2sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNc2sm_LDADD = libsb_cfgP521CNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNc8sm.a and securebootsim_cfgP521CNc8sm
libsb_cfgP521CNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP521CNc8sm_CPPFLAGS = $(SECUREBOOTSIM521_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNc8sm_LDADD = libsb_cfgP521CNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNc0sm.a and securebootsim_cfgP521CXNc0sm
libsb_cfgP521CXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP521CXNc0sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNc0sm_LDADD = libsb_cfgP521CXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNc1sm.a and securebootsim_cfgP521CXNc1sm
libsb_cfgP521CXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP521CXNc1sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNc1sm_LDADD = libsb_cfgP521CXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNc2sm.a and securebootsim_cfgP521CXNc2sm
libsb_cfgP521CXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP521CXNc2sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNc2sm_LDADD = libsb_cfgP521CXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNc8sm.a and securebootsim_cfgP521CXNc8sm
libsb_cfgP521CXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521AES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP521CXNc8sm_CPPFLAGS = $(SECUREBOOTSIM521AES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNc8sm_LDADD = libsb_cfgP521CXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNKc0sm.a and securebootsim_cfgP521CNKc0sm
libsb_cfgP521CNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP521CNKc0sm_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNKc0sm_LDADD = libsb_cfgP521CNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNKc1sm.a and securebootsim_cfgP521CNKc1sm
libsb_cfgP521CNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP521CNKc1sm_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNKc1sm_LDADD = libsb_cfgP521CNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNKc2sm.a and securebootsim_cfgP521CNKc2sm
libsb_cfgP521CNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP521CNKc2sm_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNKc2sm_LDADD = libsb_cfgP521CNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CNKc8sm.a and securebootsim_cfgP521CNKc8sm
libsb_cfgP521CNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgP521CNKc8sm_CPPFLAGS = $(SECUREBOOTSIM521KDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CNKc8sm_LDADD = libsb_cfgP521CNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNKc0sm.a and securebootsim_cfgP521CXNKc0sm
libsb_cfgP521CXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgP521CXNKc0sm_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNKc0sm_LDADD = libsb_cfgP521CXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNKc1sm.a and securebootsim_cfgP521CXNKc1sm
libsb_cfgP521CXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgP521CXNKc1sm_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNKc1sm_LDADD = libsb_cfgP521CXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNKc2sm.a and securebootsim_cfgP521CXNKc2sm
libsb_cfgP521CXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgP521CXNKc2sm_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNKc2sm_LDADD = libsb_cfgP521CXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgP521CXNKc8sm.a and securebootsim_cfgP521CXNKc8sm
libsb_cfgP521CXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgP521CXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRID521KDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgP521CXNKc8sm_CPPFLAGS = $(SECUREBOOTSIM521KDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgP521CXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgP521CXNKc8sm_LDADD = libsb_cfgP521CXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTO521_A) libsb_cfgP521CXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc0sw.a and securebootsim_cfgRSA2048pkcsIPc0sw
libsb_cfgRSA2048pkcsIPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsIPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES)
securebootsim_cfgRSA2048pkcsIPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc0sw_LDADD = libsb_cfgRSA2048pkcsIPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc1sw.a and securebootsim_cfgRSA2048pkcsIPc1sw
libsb_cfgRSA2048pkcsIPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsIPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES)
securebootsim_cfgRSA2048pkcsIPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc1sw_LDADD = libsb_cfgRSA2048pkcsIPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc2sw.a and securebootsim_cfgRSA2048pkcsIPc2sw
libsb_cfgRSA2048pkcsIPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsIPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES)
securebootsim_cfgRSA2048pkcsIPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc2sw_LDADD = libsb_cfgRSA2048pkcsIPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc8sw.a and securebootsim_cfgRSA2048pkcsIPc8sw
libsb_cfgRSA2048pkcsIPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsIPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES)
securebootsim_cfgRSA2048pkcsIPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc8sw_LDADD = libsb_cfgRSA2048pkcsIPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc0sw.a and securebootsim_cfgRSA2048pkcsCPc0sw
libsb_cfgRSA2048pkcsCPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc0sw_LDADD = libsb_cfgRSA2048pkcsCPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc1sw.a and securebootsim_cfgRSA2048pkcsCPc1sw
libsb_cfgRSA2048pkcsCPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc1sw_LDADD = libsb_cfgRSA2048pkcsCPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc2sw.a and securebootsim_cfgRSA2048pkcsCPc2sw
libsb_cfgRSA2048pkcsCPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc2sw_LDADD = libsb_cfgRSA2048pkcsCPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc8sw.a and securebootsim_cfgRSA2048pkcsCPc8sw
libsb_cfgRSA2048pkcsCPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc8sw_LDADD = libsb_cfgRSA2048pkcsCPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc0sw.a and securebootsim_cfgRSA2048pkcsCXPc0sw
libsb_cfgRSA2048pkcsCXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc0sw_LDADD = libsb_cfgRSA2048pkcsCXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc1sw.a and securebootsim_cfgRSA2048pkcsCXPc1sw
libsb_cfgRSA2048pkcsCXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc1sw_LDADD = libsb_cfgRSA2048pkcsCXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc2sw.a and securebootsim_cfgRSA2048pkcsCXPc2sw
libsb_cfgRSA2048pkcsCXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc2sw_LDADD = libsb_cfgRSA2048pkcsCXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc8sw.a and securebootsim_cfgRSA2048pkcsCXPc8sw
libsb_cfgRSA2048pkcsCXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc8sw_LDADD = libsb_cfgRSA2048pkcsCXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc0sm.a and securebootsim_cfgRSA2048pkcsIPc0sm
libsb_cfgRSA2048pkcsIPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsIPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsIPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc0sm_LDADD = libsb_cfgRSA2048pkcsIPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc1sm.a and securebootsim_cfgRSA2048pkcsIPc1sm
libsb_cfgRSA2048pkcsIPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsIPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsIPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc1sm_LDADD = libsb_cfgRSA2048pkcsIPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc2sm.a and securebootsim_cfgRSA2048pkcsIPc2sm
libsb_cfgRSA2048pkcsIPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsIPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsIPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc2sm_LDADD = libsb_cfgRSA2048pkcsIPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc8sm.a and securebootsim_cfgRSA2048pkcsIPc8sm
libsb_cfgRSA2048pkcsIPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsIPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsIPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc8sm_LDADD = libsb_cfgRSA2048pkcsIPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc0sm.a and securebootsim_cfgRSA2048pkcsCPc0sm
libsb_cfgRSA2048pkcsCPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc0sm_LDADD = libsb_cfgRSA2048pkcsCPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc1sm.a and securebootsim_cfgRSA2048pkcsCPc1sm
libsb_cfgRSA2048pkcsCPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc1sm_LDADD = libsb_cfgRSA2048pkcsCPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc2sm.a and securebootsim_cfgRSA2048pkcsCPc2sm
libsb_cfgRSA2048pkcsCPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc2sm_LDADD = libsb_cfgRSA2048pkcsCPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc8sm.a and securebootsim_cfgRSA2048pkcsCPc8sm
libsb_cfgRSA2048pkcsCPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc8sm_LDADD = libsb_cfgRSA2048pkcsCPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc0sm.a and securebootsim_cfgRSA2048pkcsCXPc0sm
libsb_cfgRSA2048pkcsCXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc0sm_LDADD = libsb_cfgRSA2048pkcsCXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc1sm.a and securebootsim_cfgRSA2048pkcsCXPc1sm
libsb_cfgRSA2048pkcsCXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc1sm_LDADD = libsb_cfgRSA2048pkcsCXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc2sm.a and securebootsim_cfgRSA2048pkcsCXPc2sm
libsb_cfgRSA2048pkcsCXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc2sm_LDADD = libsb_cfgRSA2048pkcsCXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc8sm.a and securebootsim_cfgRSA2048pkcsCXPc8sm
libsb_cfgRSA2048pkcsCXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pkcsCXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc8sm_LDADD = libsb_cfgRSA2048pkcsCXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc0pk.a and securebootsim_cfgRSA2048pkcsIPc0pk
libsb_cfgRSA2048pkcsIPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsIPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc0pk_LDADD = libsb_cfgRSA2048pkcsIPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc1pk.a and securebootsim_cfgRSA2048pkcsIPc1pk
libsb_cfgRSA2048pkcsIPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsIPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc1pk_LDADD = libsb_cfgRSA2048pkcsIPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc2pk.a and securebootsim_cfgRSA2048pkcsIPc2pk
libsb_cfgRSA2048pkcsIPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsIPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc2pk_LDADD = libsb_cfgRSA2048pkcsIPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc8pk.a and securebootsim_cfgRSA2048pkcsIPc8pk
libsb_cfgRSA2048pkcsIPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsIPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc8pk_LDADD = libsb_cfgRSA2048pkcsIPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc0pk.a and securebootsim_cfgRSA2048pkcsCPc0pk
libsb_cfgRSA2048pkcsCPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc0pk_LDADD = libsb_cfgRSA2048pkcsCPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc1pk.a and securebootsim_cfgRSA2048pkcsCPc1pk
libsb_cfgRSA2048pkcsCPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc1pk_LDADD = libsb_cfgRSA2048pkcsCPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc2pk.a and securebootsim_cfgRSA2048pkcsCPc2pk
libsb_cfgRSA2048pkcsCPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc2pk_LDADD = libsb_cfgRSA2048pkcsCPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc8pk.a and securebootsim_cfgRSA2048pkcsCPc8pk
libsb_cfgRSA2048pkcsCPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc8pk_LDADD = libsb_cfgRSA2048pkcsCPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc0pk.a and securebootsim_cfgRSA2048pkcsCXPc0pk
libsb_cfgRSA2048pkcsCXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc0pk_LDADD = libsb_cfgRSA2048pkcsCXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc1pk.a and securebootsim_cfgRSA2048pkcsCXPc1pk
libsb_cfgRSA2048pkcsCXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc1pk_LDADD = libsb_cfgRSA2048pkcsCXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc2pk.a and securebootsim_cfgRSA2048pkcsCXPc2pk
libsb_cfgRSA2048pkcsCXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc2pk_LDADD = libsb_cfgRSA2048pkcsCXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc8pk.a and securebootsim_cfgRSA2048pkcsCXPc8pk
libsb_cfgRSA2048pkcsCXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc8pk_LDADD = libsb_cfgRSA2048pkcsCXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc0pepk.a and securebootsim_cfgRSA2048pkcsIPc0pepk
libsb_cfgRSA2048pkcsIPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsIPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc0pepk_LDADD = libsb_cfgRSA2048pkcsIPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc1pepk.a and securebootsim_cfgRSA2048pkcsIPc1pepk
libsb_cfgRSA2048pkcsIPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsIPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc1pepk_LDADD = libsb_cfgRSA2048pkcsIPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc2pepk.a and securebootsim_cfgRSA2048pkcsIPc2pepk
libsb_cfgRSA2048pkcsIPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsIPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc2pepk_LDADD = libsb_cfgRSA2048pkcsIPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsIPc8pepk.a and securebootsim_cfgRSA2048pkcsIPc8pepk
libsb_cfgRSA2048pkcsIPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsIPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsIPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pkcsIPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pkcsIPc8pepk_LDADD = libsb_cfgRSA2048pkcsIPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsIPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc0pepk.a and securebootsim_cfgRSA2048pkcsCPc0pepk
libsb_cfgRSA2048pkcsCPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc0pepk_LDADD = libsb_cfgRSA2048pkcsCPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc1pepk.a and securebootsim_cfgRSA2048pkcsCPc1pepk
libsb_cfgRSA2048pkcsCPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc1pepk_LDADD = libsb_cfgRSA2048pkcsCPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc2pepk.a and securebootsim_cfgRSA2048pkcsCPc2pepk
libsb_cfgRSA2048pkcsCPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc2pepk_LDADD = libsb_cfgRSA2048pkcsCPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPc8pepk.a and securebootsim_cfgRSA2048pkcsCPc8pepk
libsb_cfgRSA2048pkcsCPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPc8pepk_LDADD = libsb_cfgRSA2048pkcsCPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc0pepk.a and securebootsim_cfgRSA2048pkcsCXPc0pepk
libsb_cfgRSA2048pkcsCXPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc0pepk_LDADD = libsb_cfgRSA2048pkcsCXPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc1pepk.a and securebootsim_cfgRSA2048pkcsCXPc1pepk
libsb_cfgRSA2048pkcsCXPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc1pepk_LDADD = libsb_cfgRSA2048pkcsCXPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc2pepk.a and securebootsim_cfgRSA2048pkcsCXPc2pepk
libsb_cfgRSA2048pkcsCXPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc2pepk_LDADD = libsb_cfgRSA2048pkcsCXPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPc8pepk.a and securebootsim_cfgRSA2048pkcsCXPc8pepk
libsb_cfgRSA2048pkcsCXPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPc8pepk_LDADD = libsb_cfgRSA2048pkcsCXPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPKc0sw.a and securebootsim_cfgRSA2048pkcsCPKc0sw
libsb_cfgRSA2048pkcsCPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPKc0sw_LDADD = libsb_cfgRSA2048pkcsCPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPKc1sw.a and securebootsim_cfgRSA2048pkcsCPKc1sw
libsb_cfgRSA2048pkcsCPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPKc1sw_LDADD = libsb_cfgRSA2048pkcsCPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPKc2sw.a and securebootsim_cfgRSA2048pkcsCPKc2sw
libsb_cfgRSA2048pkcsCPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPKc2sw_LDADD = libsb_cfgRSA2048pkcsCPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCPKc8sw.a and securebootsim_cfgRSA2048pkcsCPKc8sw
libsb_cfgRSA2048pkcsCPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCPKc8sw_LDADD = libsb_cfgRSA2048pkcsCPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPKc0sw.a and securebootsim_cfgRSA2048pkcsCXPKc0sw
libsb_cfgRSA2048pkcsCXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPKc0sw_LDADD = libsb_cfgRSA2048pkcsCXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPKc1sw.a and securebootsim_cfgRSA2048pkcsCXPKc1sw
libsb_cfgRSA2048pkcsCXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPKc1sw_LDADD = libsb_cfgRSA2048pkcsCXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPKc2sw.a and securebootsim_cfgRSA2048pkcsCXPKc2sw
libsb_cfgRSA2048pkcsCXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPKc2sw_LDADD = libsb_cfgRSA2048pkcsCXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXPKc8sw.a and securebootsim_cfgRSA2048pkcsCXPKc8sw
libsb_cfgRSA2048pkcsCXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pkcsCXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pkcsCXPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXPKc8sw_LDADD = libsb_cfgRSA2048pkcsCXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNc0sm.a and securebootsim_cfgRSA2048pkcsCNc0sm
libsb_cfgRSA2048pkcsCNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsCNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNc0sm_LDADD = libsb_cfgRSA2048pkcsCNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNc1sm.a and securebootsim_cfgRSA2048pkcsCNc1sm
libsb_cfgRSA2048pkcsCNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsCNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNc1sm_LDADD = libsb_cfgRSA2048pkcsCNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNc2sm.a and securebootsim_cfgRSA2048pkcsCNc2sm
libsb_cfgRSA2048pkcsCNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsCNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNc2sm_LDADD = libsb_cfgRSA2048pkcsCNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNc8sm.a and securebootsim_cfgRSA2048pkcsCNc8sm
libsb_cfgRSA2048pkcsCNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsCNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNc8sm_LDADD = libsb_cfgRSA2048pkcsCNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNc0sm.a and securebootsim_cfgRSA2048pkcsCXNc0sm
libsb_cfgRSA2048pkcsCXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsCXNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNc0sm_LDADD = libsb_cfgRSA2048pkcsCXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNc1sm.a and securebootsim_cfgRSA2048pkcsCXNc1sm
libsb_cfgRSA2048pkcsCXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsCXNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNc1sm_LDADD = libsb_cfgRSA2048pkcsCXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNc2sm.a and securebootsim_cfgRSA2048pkcsCXNc2sm
libsb_cfgRSA2048pkcsCXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsCXNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNc2sm_LDADD = libsb_cfgRSA2048pkcsCXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNc8sm.a and securebootsim_cfgRSA2048pkcsCXNc8sm
libsb_cfgRSA2048pkcsCXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsCXNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNc8sm_LDADD = libsb_cfgRSA2048pkcsCXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNKc0sm.a and securebootsim_cfgRSA2048pkcsCNKc0sm
libsb_cfgRSA2048pkcsCNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pkcsCNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNKc0sm_LDADD = libsb_cfgRSA2048pkcsCNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNKc1sm.a and securebootsim_cfgRSA2048pkcsCNKc1sm
libsb_cfgRSA2048pkcsCNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pkcsCNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNKc1sm_LDADD = libsb_cfgRSA2048pkcsCNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNKc2sm.a and securebootsim_cfgRSA2048pkcsCNKc2sm
libsb_cfgRSA2048pkcsCNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pkcsCNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNKc2sm_LDADD = libsb_cfgRSA2048pkcsCNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCNKc8sm.a and securebootsim_cfgRSA2048pkcsCNKc8sm
libsb_cfgRSA2048pkcsCNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pkcsCNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCNKc8sm_LDADD = libsb_cfgRSA2048pkcsCNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNKc0sm.a and securebootsim_cfgRSA2048pkcsCXNKc0sm
libsb_cfgRSA2048pkcsCXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pkcsCXNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNKc0sm_LDADD = libsb_cfgRSA2048pkcsCXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNKc1sm.a and securebootsim_cfgRSA2048pkcsCXNKc1sm
libsb_cfgRSA2048pkcsCXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pkcsCXNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNKc1sm_LDADD = libsb_cfgRSA2048pkcsCXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNKc2sm.a and securebootsim_cfgRSA2048pkcsCXNKc2sm
libsb_cfgRSA2048pkcsCXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pkcsCXNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNKc2sm_LDADD = libsb_cfgRSA2048pkcsCXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pkcsCXNKc8sm.a and securebootsim_cfgRSA2048pkcsCXNKc8sm
libsb_cfgRSA2048pkcsCXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pkcsCXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pkcsCXNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pkcsCXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pkcsCXNKc8sm_LDADD = libsb_cfgRSA2048pkcsCXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pkcs_A) libsb_cfgRSA2048pkcsCXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc0sw.a and securebootsim_cfgRSA3072pkcsIPc0sw
libsb_cfgRSA3072pkcsIPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsIPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES)
securebootsim_cfgRSA3072pkcsIPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc0sw_LDADD = libsb_cfgRSA3072pkcsIPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc1sw.a and securebootsim_cfgRSA3072pkcsIPc1sw
libsb_cfgRSA3072pkcsIPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsIPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES)
securebootsim_cfgRSA3072pkcsIPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc1sw_LDADD = libsb_cfgRSA3072pkcsIPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc2sw.a and securebootsim_cfgRSA3072pkcsIPc2sw
libsb_cfgRSA3072pkcsIPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsIPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES)
securebootsim_cfgRSA3072pkcsIPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc2sw_LDADD = libsb_cfgRSA3072pkcsIPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc8sw.a and securebootsim_cfgRSA3072pkcsIPc8sw
libsb_cfgRSA3072pkcsIPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsIPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES)
securebootsim_cfgRSA3072pkcsIPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc8sw_LDADD = libsb_cfgRSA3072pkcsIPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc0sw.a and securebootsim_cfgRSA3072pkcsCPc0sw
libsb_cfgRSA3072pkcsCPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc0sw_LDADD = libsb_cfgRSA3072pkcsCPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc1sw.a and securebootsim_cfgRSA3072pkcsCPc1sw
libsb_cfgRSA3072pkcsCPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc1sw_LDADD = libsb_cfgRSA3072pkcsCPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc2sw.a and securebootsim_cfgRSA3072pkcsCPc2sw
libsb_cfgRSA3072pkcsCPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc2sw_LDADD = libsb_cfgRSA3072pkcsCPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc8sw.a and securebootsim_cfgRSA3072pkcsCPc8sw
libsb_cfgRSA3072pkcsCPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc8sw_LDADD = libsb_cfgRSA3072pkcsCPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc0sw.a and securebootsim_cfgRSA3072pkcsCXPc0sw
libsb_cfgRSA3072pkcsCXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc0sw_LDADD = libsb_cfgRSA3072pkcsCXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc1sw.a and securebootsim_cfgRSA3072pkcsCXPc1sw
libsb_cfgRSA3072pkcsCXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc1sw_LDADD = libsb_cfgRSA3072pkcsCXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc2sw.a and securebootsim_cfgRSA3072pkcsCXPc2sw
libsb_cfgRSA3072pkcsCXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc2sw_LDADD = libsb_cfgRSA3072pkcsCXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc8sw.a and securebootsim_cfgRSA3072pkcsCXPc8sw
libsb_cfgRSA3072pkcsCXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc8sw_LDADD = libsb_cfgRSA3072pkcsCXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc0sm.a and securebootsim_cfgRSA3072pkcsIPc0sm
libsb_cfgRSA3072pkcsIPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsIPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsIPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc0sm_LDADD = libsb_cfgRSA3072pkcsIPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc1sm.a and securebootsim_cfgRSA3072pkcsIPc1sm
libsb_cfgRSA3072pkcsIPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsIPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsIPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc1sm_LDADD = libsb_cfgRSA3072pkcsIPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc2sm.a and securebootsim_cfgRSA3072pkcsIPc2sm
libsb_cfgRSA3072pkcsIPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsIPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsIPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc2sm_LDADD = libsb_cfgRSA3072pkcsIPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc8sm.a and securebootsim_cfgRSA3072pkcsIPc8sm
libsb_cfgRSA3072pkcsIPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsIPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsIPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc8sm_LDADD = libsb_cfgRSA3072pkcsIPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc0sm.a and securebootsim_cfgRSA3072pkcsCPc0sm
libsb_cfgRSA3072pkcsCPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc0sm_LDADD = libsb_cfgRSA3072pkcsCPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc1sm.a and securebootsim_cfgRSA3072pkcsCPc1sm
libsb_cfgRSA3072pkcsCPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc1sm_LDADD = libsb_cfgRSA3072pkcsCPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc2sm.a and securebootsim_cfgRSA3072pkcsCPc2sm
libsb_cfgRSA3072pkcsCPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc2sm_LDADD = libsb_cfgRSA3072pkcsCPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc8sm.a and securebootsim_cfgRSA3072pkcsCPc8sm
libsb_cfgRSA3072pkcsCPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc8sm_LDADD = libsb_cfgRSA3072pkcsCPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc0sm.a and securebootsim_cfgRSA3072pkcsCXPc0sm
libsb_cfgRSA3072pkcsCXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc0sm_LDADD = libsb_cfgRSA3072pkcsCXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc1sm.a and securebootsim_cfgRSA3072pkcsCXPc1sm
libsb_cfgRSA3072pkcsCXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc1sm_LDADD = libsb_cfgRSA3072pkcsCXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc2sm.a and securebootsim_cfgRSA3072pkcsCXPc2sm
libsb_cfgRSA3072pkcsCXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc2sm_LDADD = libsb_cfgRSA3072pkcsCXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc8sm.a and securebootsim_cfgRSA3072pkcsCXPc8sm
libsb_cfgRSA3072pkcsCXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pkcsCXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc8sm_LDADD = libsb_cfgRSA3072pkcsCXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc0pk.a and securebootsim_cfgRSA3072pkcsIPc0pk
libsb_cfgRSA3072pkcsIPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsIPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc0pk_LDADD = libsb_cfgRSA3072pkcsIPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc1pk.a and securebootsim_cfgRSA3072pkcsIPc1pk
libsb_cfgRSA3072pkcsIPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsIPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc1pk_LDADD = libsb_cfgRSA3072pkcsIPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc2pk.a and securebootsim_cfgRSA3072pkcsIPc2pk
libsb_cfgRSA3072pkcsIPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsIPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc2pk_LDADD = libsb_cfgRSA3072pkcsIPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc8pk.a and securebootsim_cfgRSA3072pkcsIPc8pk
libsb_cfgRSA3072pkcsIPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsIPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc8pk_LDADD = libsb_cfgRSA3072pkcsIPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc0pk.a and securebootsim_cfgRSA3072pkcsCPc0pk
libsb_cfgRSA3072pkcsCPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc0pk_LDADD = libsb_cfgRSA3072pkcsCPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc1pk.a and securebootsim_cfgRSA3072pkcsCPc1pk
libsb_cfgRSA3072pkcsCPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc1pk_LDADD = libsb_cfgRSA3072pkcsCPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc2pk.a and securebootsim_cfgRSA3072pkcsCPc2pk
libsb_cfgRSA3072pkcsCPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc2pk_LDADD = libsb_cfgRSA3072pkcsCPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc8pk.a and securebootsim_cfgRSA3072pkcsCPc8pk
libsb_cfgRSA3072pkcsCPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc8pk_LDADD = libsb_cfgRSA3072pkcsCPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc0pk.a and securebootsim_cfgRSA3072pkcsCXPc0pk
libsb_cfgRSA3072pkcsCXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc0pk_LDADD = libsb_cfgRSA3072pkcsCXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc1pk.a and securebootsim_cfgRSA3072pkcsCXPc1pk
libsb_cfgRSA3072pkcsCXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc1pk_LDADD = libsb_cfgRSA3072pkcsCXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc2pk.a and securebootsim_cfgRSA3072pkcsCXPc2pk
libsb_cfgRSA3072pkcsCXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc2pk_LDADD = libsb_cfgRSA3072pkcsCXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc8pk.a and securebootsim_cfgRSA3072pkcsCXPc8pk
libsb_cfgRSA3072pkcsCXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc8pk_LDADD = libsb_cfgRSA3072pkcsCXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc0pepk.a and securebootsim_cfgRSA3072pkcsIPc0pepk
libsb_cfgRSA3072pkcsIPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsIPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc0pepk_LDADD = libsb_cfgRSA3072pkcsIPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc1pepk.a and securebootsim_cfgRSA3072pkcsIPc1pepk
libsb_cfgRSA3072pkcsIPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsIPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc1pepk_LDADD = libsb_cfgRSA3072pkcsIPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc2pepk.a and securebootsim_cfgRSA3072pkcsIPc2pepk
libsb_cfgRSA3072pkcsIPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsIPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc2pepk_LDADD = libsb_cfgRSA3072pkcsIPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsIPc8pepk.a and securebootsim_cfgRSA3072pkcsIPc8pepk
libsb_cfgRSA3072pkcsIPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsIPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsIPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pkcsIPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pkcsIPc8pepk_LDADD = libsb_cfgRSA3072pkcsIPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsIPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc0pepk.a and securebootsim_cfgRSA3072pkcsCPc0pepk
libsb_cfgRSA3072pkcsCPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc0pepk_LDADD = libsb_cfgRSA3072pkcsCPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc1pepk.a and securebootsim_cfgRSA3072pkcsCPc1pepk
libsb_cfgRSA3072pkcsCPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc1pepk_LDADD = libsb_cfgRSA3072pkcsCPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc2pepk.a and securebootsim_cfgRSA3072pkcsCPc2pepk
libsb_cfgRSA3072pkcsCPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc2pepk_LDADD = libsb_cfgRSA3072pkcsCPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPc8pepk.a and securebootsim_cfgRSA3072pkcsCPc8pepk
libsb_cfgRSA3072pkcsCPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPc8pepk_LDADD = libsb_cfgRSA3072pkcsCPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc0pepk.a and securebootsim_cfgRSA3072pkcsCXPc0pepk
libsb_cfgRSA3072pkcsCXPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc0pepk_LDADD = libsb_cfgRSA3072pkcsCXPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc1pepk.a and securebootsim_cfgRSA3072pkcsCXPc1pepk
libsb_cfgRSA3072pkcsCXPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc1pepk_LDADD = libsb_cfgRSA3072pkcsCXPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc2pepk.a and securebootsim_cfgRSA3072pkcsCXPc2pepk
libsb_cfgRSA3072pkcsCXPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc2pepk_LDADD = libsb_cfgRSA3072pkcsCXPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPc8pepk.a and securebootsim_cfgRSA3072pkcsCXPc8pepk
libsb_cfgRSA3072pkcsCXPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPc8pepk_LDADD = libsb_cfgRSA3072pkcsCXPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPKc0sw.a and securebootsim_cfgRSA3072pkcsCPKc0sw
libsb_cfgRSA3072pkcsCPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPKc0sw_LDADD = libsb_cfgRSA3072pkcsCPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPKc1sw.a and securebootsim_cfgRSA3072pkcsCPKc1sw
libsb_cfgRSA3072pkcsCPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPKc1sw_LDADD = libsb_cfgRSA3072pkcsCPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPKc2sw.a and securebootsim_cfgRSA3072pkcsCPKc2sw
libsb_cfgRSA3072pkcsCPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPKc2sw_LDADD = libsb_cfgRSA3072pkcsCPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCPKc8sw.a and securebootsim_cfgRSA3072pkcsCPKc8sw
libsb_cfgRSA3072pkcsCPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCPKc8sw_LDADD = libsb_cfgRSA3072pkcsCPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPKc0sw.a and securebootsim_cfgRSA3072pkcsCXPKc0sw
libsb_cfgRSA3072pkcsCXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPKc0sw_LDADD = libsb_cfgRSA3072pkcsCXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPKc1sw.a and securebootsim_cfgRSA3072pkcsCXPKc1sw
libsb_cfgRSA3072pkcsCXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPKc1sw_LDADD = libsb_cfgRSA3072pkcsCXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPKc2sw.a and securebootsim_cfgRSA3072pkcsCXPKc2sw
libsb_cfgRSA3072pkcsCXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPKc2sw_LDADD = libsb_cfgRSA3072pkcsCXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXPKc8sw.a and securebootsim_cfgRSA3072pkcsCXPKc8sw
libsb_cfgRSA3072pkcsCXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pkcsCXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pkcsCXPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXPKc8sw_LDADD = libsb_cfgRSA3072pkcsCXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNc0sm.a and securebootsim_cfgRSA3072pkcsCNc0sm
libsb_cfgRSA3072pkcsCNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsCNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNc0sm_LDADD = libsb_cfgRSA3072pkcsCNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNc1sm.a and securebootsim_cfgRSA3072pkcsCNc1sm
libsb_cfgRSA3072pkcsCNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsCNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNc1sm_LDADD = libsb_cfgRSA3072pkcsCNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNc2sm.a and securebootsim_cfgRSA3072pkcsCNc2sm
libsb_cfgRSA3072pkcsCNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsCNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNc2sm_LDADD = libsb_cfgRSA3072pkcsCNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNc8sm.a and securebootsim_cfgRSA3072pkcsCNc8sm
libsb_cfgRSA3072pkcsCNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsCNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNc8sm_LDADD = libsb_cfgRSA3072pkcsCNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNc0sm.a and securebootsim_cfgRSA3072pkcsCXNc0sm
libsb_cfgRSA3072pkcsCXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsCXNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNc0sm_LDADD = libsb_cfgRSA3072pkcsCXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNc1sm.a and securebootsim_cfgRSA3072pkcsCXNc1sm
libsb_cfgRSA3072pkcsCXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsCXNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNc1sm_LDADD = libsb_cfgRSA3072pkcsCXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNc2sm.a and securebootsim_cfgRSA3072pkcsCXNc2sm
libsb_cfgRSA3072pkcsCXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsCXNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNc2sm_LDADD = libsb_cfgRSA3072pkcsCXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNc8sm.a and securebootsim_cfgRSA3072pkcsCXNc8sm
libsb_cfgRSA3072pkcsCXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsCXNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNc8sm_LDADD = libsb_cfgRSA3072pkcsCXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNKc0sm.a and securebootsim_cfgRSA3072pkcsCNKc0sm
libsb_cfgRSA3072pkcsCNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pkcsCNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNKc0sm_LDADD = libsb_cfgRSA3072pkcsCNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNKc1sm.a and securebootsim_cfgRSA3072pkcsCNKc1sm
libsb_cfgRSA3072pkcsCNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pkcsCNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNKc1sm_LDADD = libsb_cfgRSA3072pkcsCNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNKc2sm.a and securebootsim_cfgRSA3072pkcsCNKc2sm
libsb_cfgRSA3072pkcsCNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pkcsCNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNKc2sm_LDADD = libsb_cfgRSA3072pkcsCNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCNKc8sm.a and securebootsim_cfgRSA3072pkcsCNKc8sm
libsb_cfgRSA3072pkcsCNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pkcsCNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCNKc8sm_LDADD = libsb_cfgRSA3072pkcsCNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNKc0sm.a and securebootsim_cfgRSA3072pkcsCXNKc0sm
libsb_cfgRSA3072pkcsCXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pkcsCXNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNKc0sm_LDADD = libsb_cfgRSA3072pkcsCXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNKc1sm.a and securebootsim_cfgRSA3072pkcsCXNKc1sm
libsb_cfgRSA3072pkcsCXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pkcsCXNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNKc1sm_LDADD = libsb_cfgRSA3072pkcsCXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNKc2sm.a and securebootsim_cfgRSA3072pkcsCXNKc2sm
libsb_cfgRSA3072pkcsCXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pkcsCXNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNKc2sm_LDADD = libsb_cfgRSA3072pkcsCXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pkcsCXNKc8sm.a and securebootsim_cfgRSA3072pkcsCXNKc8sm
libsb_cfgRSA3072pkcsCXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pkcsCXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pkcsCXNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pkcsKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pkcsCXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pkcsCXNKc8sm_LDADD = libsb_cfgRSA3072pkcsCXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pkcs_A) libsb_cfgRSA3072pkcsCXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc0sw.a and securebootsim_cfgRSA4096pkcsIPc0sw
libsb_cfgRSA4096pkcsIPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA4096pkcsIPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES)
securebootsim_cfgRSA4096pkcsIPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc0sw_LDADD = libsb_cfgRSA4096pkcsIPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc1sw.a and securebootsim_cfgRSA4096pkcsIPc1sw
libsb_cfgRSA4096pkcsIPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA4096pkcsIPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES)
securebootsim_cfgRSA4096pkcsIPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc1sw_LDADD = libsb_cfgRSA4096pkcsIPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc2sw.a and securebootsim_cfgRSA4096pkcsIPc2sw
libsb_cfgRSA4096pkcsIPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA4096pkcsIPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES)
securebootsim_cfgRSA4096pkcsIPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc2sw_LDADD = libsb_cfgRSA4096pkcsIPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc8sw.a and securebootsim_cfgRSA4096pkcsIPc8sw
libsb_cfgRSA4096pkcsIPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA4096pkcsIPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES)
securebootsim_cfgRSA4096pkcsIPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc8sw_LDADD = libsb_cfgRSA4096pkcsIPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc0sw.a and securebootsim_cfgRSA4096pkcsCPc0sw
libsb_cfgRSA4096pkcsCPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc0sw_LDADD = libsb_cfgRSA4096pkcsCPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc1sw.a and securebootsim_cfgRSA4096pkcsCPc1sw
libsb_cfgRSA4096pkcsCPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc1sw_LDADD = libsb_cfgRSA4096pkcsCPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc2sw.a and securebootsim_cfgRSA4096pkcsCPc2sw
libsb_cfgRSA4096pkcsCPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc2sw_LDADD = libsb_cfgRSA4096pkcsCPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc8sw.a and securebootsim_cfgRSA4096pkcsCPc8sw
libsb_cfgRSA4096pkcsCPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc8sw_LDADD = libsb_cfgRSA4096pkcsCPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc0sw.a and securebootsim_cfgRSA4096pkcsCXPc0sw
libsb_cfgRSA4096pkcsCXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc0sw_LDADD = libsb_cfgRSA4096pkcsCXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc1sw.a and securebootsim_cfgRSA4096pkcsCXPc1sw
libsb_cfgRSA4096pkcsCXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc1sw_LDADD = libsb_cfgRSA4096pkcsCXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc2sw.a and securebootsim_cfgRSA4096pkcsCXPc2sw
libsb_cfgRSA4096pkcsCXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc2sw_LDADD = libsb_cfgRSA4096pkcsCXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc8sw.a and securebootsim_cfgRSA4096pkcsCXPc8sw
libsb_cfgRSA4096pkcsCXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc8sw_LDADD = libsb_cfgRSA4096pkcsCXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc0pk.a and securebootsim_cfgRSA4096pkcsIPc0pk
libsb_cfgRSA4096pkcsIPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA4096pkcsIPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc0pk_LDADD = libsb_cfgRSA4096pkcsIPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc1pk.a and securebootsim_cfgRSA4096pkcsIPc1pk
libsb_cfgRSA4096pkcsIPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA4096pkcsIPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc1pk_LDADD = libsb_cfgRSA4096pkcsIPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc2pk.a and securebootsim_cfgRSA4096pkcsIPc2pk
libsb_cfgRSA4096pkcsIPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA4096pkcsIPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc2pk_LDADD = libsb_cfgRSA4096pkcsIPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc8pk.a and securebootsim_cfgRSA4096pkcsIPc8pk
libsb_cfgRSA4096pkcsIPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA4096pkcsIPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc8pk_LDADD = libsb_cfgRSA4096pkcsIPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc0pk.a and securebootsim_cfgRSA4096pkcsCPc0pk
libsb_cfgRSA4096pkcsCPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc0pk_LDADD = libsb_cfgRSA4096pkcsCPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc1pk.a and securebootsim_cfgRSA4096pkcsCPc1pk
libsb_cfgRSA4096pkcsCPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc1pk_LDADD = libsb_cfgRSA4096pkcsCPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc2pk.a and securebootsim_cfgRSA4096pkcsCPc2pk
libsb_cfgRSA4096pkcsCPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc2pk_LDADD = libsb_cfgRSA4096pkcsCPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc8pk.a and securebootsim_cfgRSA4096pkcsCPc8pk
libsb_cfgRSA4096pkcsCPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc8pk_LDADD = libsb_cfgRSA4096pkcsCPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc0pk.a and securebootsim_cfgRSA4096pkcsCXPc0pk
libsb_cfgRSA4096pkcsCXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc0pk_LDADD = libsb_cfgRSA4096pkcsCXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc1pk.a and securebootsim_cfgRSA4096pkcsCXPc1pk
libsb_cfgRSA4096pkcsCXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc1pk_LDADD = libsb_cfgRSA4096pkcsCXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc2pk.a and securebootsim_cfgRSA4096pkcsCXPc2pk
libsb_cfgRSA4096pkcsCXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc2pk_LDADD = libsb_cfgRSA4096pkcsCXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc8pk.a and securebootsim_cfgRSA4096pkcsCXPc8pk
libsb_cfgRSA4096pkcsCXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc8pk_LDADD = libsb_cfgRSA4096pkcsCXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc0pepk.a and securebootsim_cfgRSA4096pkcsIPc0pepk
libsb_cfgRSA4096pkcsIPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA4096pkcsIPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc0pepk_LDADD = libsb_cfgRSA4096pkcsIPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc1pepk.a and securebootsim_cfgRSA4096pkcsIPc1pepk
libsb_cfgRSA4096pkcsIPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA4096pkcsIPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc1pepk_LDADD = libsb_cfgRSA4096pkcsIPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc2pepk.a and securebootsim_cfgRSA4096pkcsIPc2pepk
libsb_cfgRSA4096pkcsIPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA4096pkcsIPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc2pepk_LDADD = libsb_cfgRSA4096pkcsIPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsIPc8pepk.a and securebootsim_cfgRSA4096pkcsIPc8pepk
libsb_cfgRSA4096pkcsIPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsIPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA4096pkcsIPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pkcsIPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pkcsIPc8pepk_LDADD = libsb_cfgRSA4096pkcsIPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsIPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc0pepk.a and securebootsim_cfgRSA4096pkcsCPc0pepk
libsb_cfgRSA4096pkcsCPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc0pepk_LDADD = libsb_cfgRSA4096pkcsCPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc1pepk.a and securebootsim_cfgRSA4096pkcsCPc1pepk
libsb_cfgRSA4096pkcsCPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc1pepk_LDADD = libsb_cfgRSA4096pkcsCPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc2pepk.a and securebootsim_cfgRSA4096pkcsCPc2pepk
libsb_cfgRSA4096pkcsCPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc2pepk_LDADD = libsb_cfgRSA4096pkcsCPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPc8pepk.a and securebootsim_cfgRSA4096pkcsCPc8pepk
libsb_cfgRSA4096pkcsCPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcs_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcs_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPc8pepk_LDADD = libsb_cfgRSA4096pkcsCPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc0pepk.a and securebootsim_cfgRSA4096pkcsCXPc0pepk
libsb_cfgRSA4096pkcsCXPc0pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc0pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc0pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc0pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc0pepk_LDADD = libsb_cfgRSA4096pkcsCXPc0pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc0pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc1pepk.a and securebootsim_cfgRSA4096pkcsCXPc1pepk
libsb_cfgRSA4096pkcsCXPc1pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc1pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc1pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc1pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc1pepk_LDADD = libsb_cfgRSA4096pkcsCXPc1pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc1pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc2pepk.a and securebootsim_cfgRSA4096pkcsCXPc2pepk
libsb_cfgRSA4096pkcsCXPc2pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc2pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc2pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc2pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc2pepk_LDADD = libsb_cfgRSA4096pkcsCXPc2pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc2pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPc8pepk.a and securebootsim_cfgRSA4096pkcsCXPc8pepk
libsb_cfgRSA4096pkcsCXPc8pepk_a_SOURCES =  $(SB_PEPK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_api_decrypt.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_hw_init.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_aes_if.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_eip93_sha256.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PEPK/src/sbpepk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPc8pepk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPc8pepk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPc8pepk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPc8pepk_LDADD = libsb_cfgRSA4096pkcsCXPc8pepk.a $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPc8pepk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPKc0sw.a and securebootsim_cfgRSA4096pkcsCPKc0sw
libsb_cfgRSA4096pkcsCPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPKc0sw_LDADD = libsb_cfgRSA4096pkcsCPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPKc1sw.a and securebootsim_cfgRSA4096pkcsCPKc1sw
libsb_cfgRSA4096pkcsCPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPKc1sw_LDADD = libsb_cfgRSA4096pkcsCPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPKc2sw.a and securebootsim_cfgRSA4096pkcsCPKc2sw
libsb_cfgRSA4096pkcsCPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPKc2sw_LDADD = libsb_cfgRSA4096pkcsCPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCPKc8sw.a and securebootsim_cfgRSA4096pkcsCPKc8sw
libsb_cfgRSA4096pkcsCPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCPKc8sw_LDADD = libsb_cfgRSA4096pkcsCPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPKc0sw.a and securebootsim_cfgRSA4096pkcsCXPKc0sw
libsb_cfgRSA4096pkcsCXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPKc0sw_LDADD = libsb_cfgRSA4096pkcsCXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPKc1sw.a and securebootsim_cfgRSA4096pkcsCXPKc1sw
libsb_cfgRSA4096pkcsCXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPKc1sw_LDADD = libsb_cfgRSA4096pkcsCXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPKc2sw.a and securebootsim_cfgRSA4096pkcsCXPKc2sw
libsb_cfgRSA4096pkcsCXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPKc2sw_LDADD = libsb_cfgRSA4096pkcsCXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pkcsCXPKc8sw.a and securebootsim_cfgRSA4096pkcsCXPKc8sw
libsb_cfgRSA4096pkcsCXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pkcsCXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pkcsKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pkcsCXPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pkcsKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pkcsCXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pkcsCXPKc8sw_LDADD = libsb_cfgRSA4096pkcsCXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pkcs_A) libsb_cfgRSA4096pkcsCXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc0sw.a and securebootsim_cfgRSA2048pssIPc0sw
libsb_cfgRSA2048pssIPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pssIPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES)
securebootsim_cfgRSA2048pssIPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc0sw_LDADD = libsb_cfgRSA2048pssIPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc1sw.a and securebootsim_cfgRSA2048pssIPc1sw
libsb_cfgRSA2048pssIPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pssIPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES)
securebootsim_cfgRSA2048pssIPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc1sw_LDADD = libsb_cfgRSA2048pssIPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc2sw.a and securebootsim_cfgRSA2048pssIPc2sw
libsb_cfgRSA2048pssIPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pssIPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES)
securebootsim_cfgRSA2048pssIPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc2sw_LDADD = libsb_cfgRSA2048pssIPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc8sw.a and securebootsim_cfgRSA2048pssIPc8sw
libsb_cfgRSA2048pssIPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pssIPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES)
securebootsim_cfgRSA2048pssIPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc8sw_LDADD = libsb_cfgRSA2048pssIPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc0sw.a and securebootsim_cfgRSA2048pssCPc0sw
libsb_cfgRSA2048pssCPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc0sw_LDADD = libsb_cfgRSA2048pssCPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc1sw.a and securebootsim_cfgRSA2048pssCPc1sw
libsb_cfgRSA2048pssCPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc1sw_LDADD = libsb_cfgRSA2048pssCPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc2sw.a and securebootsim_cfgRSA2048pssCPc2sw
libsb_cfgRSA2048pssCPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc2sw_LDADD = libsb_cfgRSA2048pssCPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc8sw.a and securebootsim_cfgRSA2048pssCPc8sw
libsb_cfgRSA2048pssCPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc8sw_LDADD = libsb_cfgRSA2048pssCPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc0sw.a and securebootsim_cfgRSA2048pssCXPc0sw
libsb_cfgRSA2048pssCXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc0sw_LDADD = libsb_cfgRSA2048pssCXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc1sw.a and securebootsim_cfgRSA2048pssCXPc1sw
libsb_cfgRSA2048pssCXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc1sw_LDADD = libsb_cfgRSA2048pssCXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc2sw.a and securebootsim_cfgRSA2048pssCXPc2sw
libsb_cfgRSA2048pssCXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc2sw_LDADD = libsb_cfgRSA2048pssCXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc8sw.a and securebootsim_cfgRSA2048pssCXPc8sw
libsb_cfgRSA2048pssCXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc8sw_LDADD = libsb_cfgRSA2048pssCXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc0sm.a and securebootsim_cfgRSA2048pssIPc0sm
libsb_cfgRSA2048pssIPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssIPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pssIPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc0sm_LDADD = libsb_cfgRSA2048pssIPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc1sm.a and securebootsim_cfgRSA2048pssIPc1sm
libsb_cfgRSA2048pssIPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssIPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pssIPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc1sm_LDADD = libsb_cfgRSA2048pssIPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc2sm.a and securebootsim_cfgRSA2048pssIPc2sm
libsb_cfgRSA2048pssIPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssIPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pssIPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc2sm_LDADD = libsb_cfgRSA2048pssIPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc8sm.a and securebootsim_cfgRSA2048pssIPc8sm
libsb_cfgRSA2048pssIPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssIPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pssIPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc8sm_LDADD = libsb_cfgRSA2048pssIPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc0sm.a and securebootsim_cfgRSA2048pssCPc0sm
libsb_cfgRSA2048pssCPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc0sm_LDADD = libsb_cfgRSA2048pssCPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc1sm.a and securebootsim_cfgRSA2048pssCPc1sm
libsb_cfgRSA2048pssCPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc1sm_LDADD = libsb_cfgRSA2048pssCPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc2sm.a and securebootsim_cfgRSA2048pssCPc2sm
libsb_cfgRSA2048pssCPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc2sm_LDADD = libsb_cfgRSA2048pssCPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc8sm.a and securebootsim_cfgRSA2048pssCPc8sm
libsb_cfgRSA2048pssCPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc8sm_LDADD = libsb_cfgRSA2048pssCPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc0sm.a and securebootsim_cfgRSA2048pssCXPc0sm
libsb_cfgRSA2048pssCXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc0sm_LDADD = libsb_cfgRSA2048pssCXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc1sm.a and securebootsim_cfgRSA2048pssCXPc1sm
libsb_cfgRSA2048pssCXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc1sm_LDADD = libsb_cfgRSA2048pssCXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc2sm.a and securebootsim_cfgRSA2048pssCXPc2sm
libsb_cfgRSA2048pssCXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc2sm_LDADD = libsb_cfgRSA2048pssCXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc8sm.a and securebootsim_cfgRSA2048pssCXPc8sm
libsb_cfgRSA2048pssCXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA2048pssCXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc8sm_LDADD = libsb_cfgRSA2048pssCXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc0pk.a and securebootsim_cfgRSA2048pssIPc0pk
libsb_cfgRSA2048pssIPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pssIPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc0pk_LDADD = libsb_cfgRSA2048pssIPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc1pk.a and securebootsim_cfgRSA2048pssIPc1pk
libsb_cfgRSA2048pssIPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pssIPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc1pk_LDADD = libsb_cfgRSA2048pssIPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc2pk.a and securebootsim_cfgRSA2048pssIPc2pk
libsb_cfgRSA2048pssIPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pssIPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc2pk_LDADD = libsb_cfgRSA2048pssIPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssIPc8pk.a and securebootsim_cfgRSA2048pssIPc8pk
libsb_cfgRSA2048pssIPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssIPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pssIPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA2048pssIPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA2048pssIPc8pk_LDADD = libsb_cfgRSA2048pssIPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssIPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc0pk.a and securebootsim_cfgRSA2048pssCPc0pk
libsb_cfgRSA2048pssCPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc0pk_LDADD = libsb_cfgRSA2048pssCPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc1pk.a and securebootsim_cfgRSA2048pssCPc1pk
libsb_cfgRSA2048pssCPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc1pk_LDADD = libsb_cfgRSA2048pssCPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc2pk.a and securebootsim_cfgRSA2048pssCPc2pk
libsb_cfgRSA2048pssCPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc2pk_LDADD = libsb_cfgRSA2048pssCPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPc8pk.a and securebootsim_cfgRSA2048pssCPc8pk
libsb_cfgRSA2048pssCPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPc8pk_LDADD = libsb_cfgRSA2048pssCPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc0pk.a and securebootsim_cfgRSA2048pssCXPc0pk
libsb_cfgRSA2048pssCXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc0pk_LDADD = libsb_cfgRSA2048pssCXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc1pk.a and securebootsim_cfgRSA2048pssCXPc1pk
libsb_cfgRSA2048pssCXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc1pk_LDADD = libsb_cfgRSA2048pssCXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc2pk.a and securebootsim_cfgRSA2048pssCXPc2pk
libsb_cfgRSA2048pssCXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc2pk_LDADD = libsb_cfgRSA2048pssCXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPc8pk.a and securebootsim_cfgRSA2048pssCXPc8pk
libsb_cfgRSA2048pssCXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPc8pk_LDADD = libsb_cfgRSA2048pssCXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPKc0sw.a and securebootsim_cfgRSA2048pssCPKc0sw
libsb_cfgRSA2048pssCPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPKc0sw_LDADD = libsb_cfgRSA2048pssCPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPKc1sw.a and securebootsim_cfgRSA2048pssCPKc1sw
libsb_cfgRSA2048pssCPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPKc1sw_LDADD = libsb_cfgRSA2048pssCPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPKc2sw.a and securebootsim_cfgRSA2048pssCPKc2sw
libsb_cfgRSA2048pssCPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPKc2sw_LDADD = libsb_cfgRSA2048pssCPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCPKc8sw.a and securebootsim_cfgRSA2048pssCPKc8sw
libsb_cfgRSA2048pssCPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCPKc8sw_LDADD = libsb_cfgRSA2048pssCPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPKc0sw.a and securebootsim_cfgRSA2048pssCXPKc0sw
libsb_cfgRSA2048pssCXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPKc0sw_LDADD = libsb_cfgRSA2048pssCXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPKc1sw.a and securebootsim_cfgRSA2048pssCXPKc1sw
libsb_cfgRSA2048pssCXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPKc1sw_LDADD = libsb_cfgRSA2048pssCXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPKc2sw.a and securebootsim_cfgRSA2048pssCXPKc2sw
libsb_cfgRSA2048pssCXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPKc2sw_LDADD = libsb_cfgRSA2048pssCXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXPKc8sw.a and securebootsim_cfgRSA2048pssCXPKc8sw
libsb_cfgRSA2048pssCXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA2048pssCXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA2048pssCXPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXPKc8sw_LDADD = libsb_cfgRSA2048pssCXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNc0sm.a and securebootsim_cfgRSA2048pssCNc0sm
libsb_cfgRSA2048pssCNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pssCNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNc0sm_LDADD = libsb_cfgRSA2048pssCNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNc1sm.a and securebootsim_cfgRSA2048pssCNc1sm
libsb_cfgRSA2048pssCNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pssCNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNc1sm_LDADD = libsb_cfgRSA2048pssCNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNc2sm.a and securebootsim_cfgRSA2048pssCNc2sm
libsb_cfgRSA2048pssCNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pssCNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNc2sm_LDADD = libsb_cfgRSA2048pssCNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNc8sm.a and securebootsim_cfgRSA2048pssCNc8sm
libsb_cfgRSA2048pssCNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pssCNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNc8sm_LDADD = libsb_cfgRSA2048pssCNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNc0sm.a and securebootsim_cfgRSA2048pssCXNc0sm
libsb_cfgRSA2048pssCXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pssCXNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNc0sm_LDADD = libsb_cfgRSA2048pssCXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNc1sm.a and securebootsim_cfgRSA2048pssCXNc1sm
libsb_cfgRSA2048pssCXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pssCXNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNc1sm_LDADD = libsb_cfgRSA2048pssCXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNc2sm.a and securebootsim_cfgRSA2048pssCXNc2sm
libsb_cfgRSA2048pssCXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pssCXNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNc2sm_LDADD = libsb_cfgRSA2048pssCXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNc8sm.a and securebootsim_cfgRSA2048pssCXNc8sm
libsb_cfgRSA2048pssCXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pssCXNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNc8sm_LDADD = libsb_cfgRSA2048pssCXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNKc0sm.a and securebootsim_cfgRSA2048pssCNKc0sm
libsb_cfgRSA2048pssCNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pssCNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNKc0sm_LDADD = libsb_cfgRSA2048pssCNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNKc1sm.a and securebootsim_cfgRSA2048pssCNKc1sm
libsb_cfgRSA2048pssCNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pssCNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNKc1sm_LDADD = libsb_cfgRSA2048pssCNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNKc2sm.a and securebootsim_cfgRSA2048pssCNKc2sm
libsb_cfgRSA2048pssCNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pssCNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNKc2sm_LDADD = libsb_cfgRSA2048pssCNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCNKc8sm.a and securebootsim_cfgRSA2048pssCNKc8sm
libsb_cfgRSA2048pssCNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA2048pssCNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCNKc8sm_LDADD = libsb_cfgRSA2048pssCNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNKc0sm.a and securebootsim_cfgRSA2048pssCXNKc0sm
libsb_cfgRSA2048pssCXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA2048pssCXNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNKc0sm_LDADD = libsb_cfgRSA2048pssCXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNKc1sm.a and securebootsim_cfgRSA2048pssCXNKc1sm
libsb_cfgRSA2048pssCXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA2048pssCXNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNKc1sm_LDADD = libsb_cfgRSA2048pssCXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNKc2sm.a and securebootsim_cfgRSA2048pssCXNKc2sm
libsb_cfgRSA2048pssCXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA2048pssCXNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNKc2sm_LDADD = libsb_cfgRSA2048pssCXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA2048pssCXNKc8sm.a and securebootsim_cfgRSA2048pssCXNKc8sm
libsb_cfgRSA2048pssCXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA2048pssCXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA2048pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA2048pssCXNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA2048pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA2048pssCXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA2048pssCXNKc8sm_LDADD = libsb_cfgRSA2048pssCXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA2048pss_A) libsb_cfgRSA2048pssCXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc0sw.a and securebootsim_cfgRSA3072pssIPc0sw
libsb_cfgRSA3072pssIPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pssIPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES)
securebootsim_cfgRSA3072pssIPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc0sw_LDADD = libsb_cfgRSA3072pssIPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc1sw.a and securebootsim_cfgRSA3072pssIPc1sw
libsb_cfgRSA3072pssIPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pssIPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES)
securebootsim_cfgRSA3072pssIPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc1sw_LDADD = libsb_cfgRSA3072pssIPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc2sw.a and securebootsim_cfgRSA3072pssIPc2sw
libsb_cfgRSA3072pssIPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pssIPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES)
securebootsim_cfgRSA3072pssIPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc2sw_LDADD = libsb_cfgRSA3072pssIPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc8sw.a and securebootsim_cfgRSA3072pssIPc8sw
libsb_cfgRSA3072pssIPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pssIPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES)
securebootsim_cfgRSA3072pssIPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc8sw_LDADD = libsb_cfgRSA3072pssIPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc0sw.a and securebootsim_cfgRSA3072pssCPc0sw
libsb_cfgRSA3072pssCPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc0sw_LDADD = libsb_cfgRSA3072pssCPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc1sw.a and securebootsim_cfgRSA3072pssCPc1sw
libsb_cfgRSA3072pssCPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc1sw_LDADD = libsb_cfgRSA3072pssCPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc2sw.a and securebootsim_cfgRSA3072pssCPc2sw
libsb_cfgRSA3072pssCPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc2sw_LDADD = libsb_cfgRSA3072pssCPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc8sw.a and securebootsim_cfgRSA3072pssCPc8sw
libsb_cfgRSA3072pssCPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc8sw_LDADD = libsb_cfgRSA3072pssCPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc0sw.a and securebootsim_cfgRSA3072pssCXPc0sw
libsb_cfgRSA3072pssCXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc0sw_LDADD = libsb_cfgRSA3072pssCXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc1sw.a and securebootsim_cfgRSA3072pssCXPc1sw
libsb_cfgRSA3072pssCXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc1sw_LDADD = libsb_cfgRSA3072pssCXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc2sw.a and securebootsim_cfgRSA3072pssCXPc2sw
libsb_cfgRSA3072pssCXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc2sw_LDADD = libsb_cfgRSA3072pssCXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc8sw.a and securebootsim_cfgRSA3072pssCXPc8sw
libsb_cfgRSA3072pssCXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc8sw_LDADD = libsb_cfgRSA3072pssCXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc0sm.a and securebootsim_cfgRSA3072pssIPc0sm
libsb_cfgRSA3072pssIPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssIPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pssIPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc0sm_LDADD = libsb_cfgRSA3072pssIPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc1sm.a and securebootsim_cfgRSA3072pssIPc1sm
libsb_cfgRSA3072pssIPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssIPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pssIPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc1sm_LDADD = libsb_cfgRSA3072pssIPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc2sm.a and securebootsim_cfgRSA3072pssIPc2sm
libsb_cfgRSA3072pssIPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssIPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pssIPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc2sm_LDADD = libsb_cfgRSA3072pssIPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc8sm.a and securebootsim_cfgRSA3072pssIPc8sm
libsb_cfgRSA3072pssIPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssIPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pssIPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc8sm_LDADD = libsb_cfgRSA3072pssIPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc0sm.a and securebootsim_cfgRSA3072pssCPc0sm
libsb_cfgRSA3072pssCPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc0sm_LDADD = libsb_cfgRSA3072pssCPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc1sm.a and securebootsim_cfgRSA3072pssCPc1sm
libsb_cfgRSA3072pssCPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc1sm_LDADD = libsb_cfgRSA3072pssCPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc2sm.a and securebootsim_cfgRSA3072pssCPc2sm
libsb_cfgRSA3072pssCPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc2sm_LDADD = libsb_cfgRSA3072pssCPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc8sm.a and securebootsim_cfgRSA3072pssCPc8sm
libsb_cfgRSA3072pssCPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc8sm_LDADD = libsb_cfgRSA3072pssCPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc0sm.a and securebootsim_cfgRSA3072pssCXPc0sm
libsb_cfgRSA3072pssCXPc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCXPc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc0sm_LDADD = libsb_cfgRSA3072pssCXPc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc1sm.a and securebootsim_cfgRSA3072pssCXPc1sm
libsb_cfgRSA3072pssCXPc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCXPc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc1sm_LDADD = libsb_cfgRSA3072pssCXPc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc2sm.a and securebootsim_cfgRSA3072pssCXPc2sm
libsb_cfgRSA3072pssCXPc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCXPc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc2sm_LDADD = libsb_cfgRSA3072pssCXPc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc8sm.a and securebootsim_cfgRSA3072pssCXPc8sm
libsb_cfgRSA3072pssCXPc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c
libsb_cfgRSA3072pssCXPc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc8sm_LDADD = libsb_cfgRSA3072pssCXPc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc0pk.a and securebootsim_cfgRSA3072pssIPc0pk
libsb_cfgRSA3072pssIPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pssIPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc0pk_LDADD = libsb_cfgRSA3072pssIPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc1pk.a and securebootsim_cfgRSA3072pssIPc1pk
libsb_cfgRSA3072pssIPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pssIPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc1pk_LDADD = libsb_cfgRSA3072pssIPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc2pk.a and securebootsim_cfgRSA3072pssIPc2pk
libsb_cfgRSA3072pssIPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pssIPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc2pk_LDADD = libsb_cfgRSA3072pssIPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssIPc8pk.a and securebootsim_cfgRSA3072pssIPc8pk
libsb_cfgRSA3072pssIPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssIPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pssIPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA3072pssIPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA3072pssIPc8pk_LDADD = libsb_cfgRSA3072pssIPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssIPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc0pk.a and securebootsim_cfgRSA3072pssCPc0pk
libsb_cfgRSA3072pssCPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc0pk_LDADD = libsb_cfgRSA3072pssCPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc1pk.a and securebootsim_cfgRSA3072pssCPc1pk
libsb_cfgRSA3072pssCPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc1pk_LDADD = libsb_cfgRSA3072pssCPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc2pk.a and securebootsim_cfgRSA3072pssCPc2pk
libsb_cfgRSA3072pssCPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc2pk_LDADD = libsb_cfgRSA3072pssCPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPc8pk.a and securebootsim_cfgRSA3072pssCPc8pk
libsb_cfgRSA3072pssCPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPc8pk_LDADD = libsb_cfgRSA3072pssCPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc0pk.a and securebootsim_cfgRSA3072pssCXPc0pk
libsb_cfgRSA3072pssCXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc0pk_LDADD = libsb_cfgRSA3072pssCXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc1pk.a and securebootsim_cfgRSA3072pssCXPc1pk
libsb_cfgRSA3072pssCXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc1pk_LDADD = libsb_cfgRSA3072pssCXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc2pk.a and securebootsim_cfgRSA3072pssCXPc2pk
libsb_cfgRSA3072pssCXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc2pk_LDADD = libsb_cfgRSA3072pssCXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPc8pk.a and securebootsim_cfgRSA3072pssCXPc8pk
libsb_cfgRSA3072pssCXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPc8pk_LDADD = libsb_cfgRSA3072pssCXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPKc0sw.a and securebootsim_cfgRSA3072pssCPKc0sw
libsb_cfgRSA3072pssCPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPKc0sw_LDADD = libsb_cfgRSA3072pssCPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPKc1sw.a and securebootsim_cfgRSA3072pssCPKc1sw
libsb_cfgRSA3072pssCPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPKc1sw_LDADD = libsb_cfgRSA3072pssCPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPKc2sw.a and securebootsim_cfgRSA3072pssCPKc2sw
libsb_cfgRSA3072pssCPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPKc2sw_LDADD = libsb_cfgRSA3072pssCPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCPKc8sw.a and securebootsim_cfgRSA3072pssCPKc8sw
libsb_cfgRSA3072pssCPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCPKc8sw_LDADD = libsb_cfgRSA3072pssCPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPKc0sw.a and securebootsim_cfgRSA3072pssCXPKc0sw
libsb_cfgRSA3072pssCXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPKc0sw_LDADD = libsb_cfgRSA3072pssCXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPKc1sw.a and securebootsim_cfgRSA3072pssCXPKc1sw
libsb_cfgRSA3072pssCXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPKc1sw_LDADD = libsb_cfgRSA3072pssCXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPKc2sw.a and securebootsim_cfgRSA3072pssCXPKc2sw
libsb_cfgRSA3072pssCXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPKc2sw_LDADD = libsb_cfgRSA3072pssCXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXPKc8sw.a and securebootsim_cfgRSA3072pssCXPKc8sw
libsb_cfgRSA3072pssCXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA3072pssCXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA3072pssCXPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXPKc8sw_LDADD = libsb_cfgRSA3072pssCXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNc0sm.a and securebootsim_cfgRSA3072pssCNc0sm
libsb_cfgRSA3072pssCNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pssCNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNc0sm_LDADD = libsb_cfgRSA3072pssCNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNc1sm.a and securebootsim_cfgRSA3072pssCNc1sm
libsb_cfgRSA3072pssCNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pssCNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNc1sm_LDADD = libsb_cfgRSA3072pssCNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNc2sm.a and securebootsim_cfgRSA3072pssCNc2sm
libsb_cfgRSA3072pssCNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pssCNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNc2sm_LDADD = libsb_cfgRSA3072pssCNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNc8sm.a and securebootsim_cfgRSA3072pssCNc8sm
libsb_cfgRSA3072pssCNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pssCNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNc8sm_LDADD = libsb_cfgRSA3072pssCNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNc0sm.a and securebootsim_cfgRSA3072pssCXNc0sm
libsb_cfgRSA3072pssCXNc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pssCXNc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNc0sm_LDADD = libsb_cfgRSA3072pssCXNc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNc1sm.a and securebootsim_cfgRSA3072pssCXNc1sm
libsb_cfgRSA3072pssCXNc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pssCXNc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNc1sm_LDADD = libsb_cfgRSA3072pssCXNc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNc2sm.a and securebootsim_cfgRSA3072pssCXNc2sm
libsb_cfgRSA3072pssCXNc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pssCXNc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNc2sm_LDADD = libsb_cfgRSA3072pssCXNc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNc8sm.a and securebootsim_cfgRSA3072pssCXNc8sm
libsb_cfgRSA3072pssCXNc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pssCXNc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNc8sm_LDADD = libsb_cfgRSA3072pssCXNc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNKc0sm.a and securebootsim_cfgRSA3072pssCNKc0sm
libsb_cfgRSA3072pssCNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pssCNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNKc0sm_LDADD = libsb_cfgRSA3072pssCNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNKc1sm.a and securebootsim_cfgRSA3072pssCNKc1sm
libsb_cfgRSA3072pssCNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pssCNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNKc1sm_LDADD = libsb_cfgRSA3072pssCNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNKc2sm.a and securebootsim_cfgRSA3072pssCNKc2sm
libsb_cfgRSA3072pssCNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pssCNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNKc2sm_LDADD = libsb_cfgRSA3072pssCNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCNKc8sm.a and securebootsim_cfgRSA3072pssCNKc8sm
libsb_cfgRSA3072pssCNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CFG_XM_IMAGE_TYPE_W_ASSET_KEY=6
securebootsim_cfgRSA3072pssCNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDK_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCNKc8sm_LDADD = libsb_cfgRSA3072pssCNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNKc0sm.a and securebootsim_cfgRSA3072pssCXNKc0sm
libsb_cfgRSA3072pssCXNKc0sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNKc0sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA3072pssCXNKc0sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNKc0sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNKc0sm_LDADD = libsb_cfgRSA3072pssCXNKc0sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNKc0sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNKc1sm.a and securebootsim_cfgRSA3072pssCXNKc1sm
libsb_cfgRSA3072pssCXNKc1sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNKc1sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA3072pssCXNKc1sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNKc1sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNKc1sm_LDADD = libsb_cfgRSA3072pssCXNKc1sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNKc1sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNKc2sm.a and securebootsim_cfgRSA3072pssCXNKc2sm
libsb_cfgRSA3072pssCXNKc2sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNKc2sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA3072pssCXNKc2sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNKc2sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNKc2sm_LDADD = libsb_cfgRSA3072pssCXNKc2sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNKc2sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA3072pssCXNKc8sm.a and securebootsim_cfgRSA3072pssCXNKc8sm
libsb_cfgRSA3072pssCXNKc8sm_a_SOURCES =  $(SB_SM_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SM/src/sbsm_api_decrypt.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_hw_init.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_aes_if.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_asset.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_common.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_rsa_verify.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_hash.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_publicdata.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_setfipsmode.c \
    $(top_src)/SBLib/SB_SM/src/sbsm_eip130_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c
libsb_cfgRSA3072pssCXNKc8sm_a_CPPFLAGS = $(LIBSB_HYBRIDRSA3072pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA3072pssCXNKc8sm_CPPFLAGS = $(SECUREBOOTSIMRSA3072pssKDKAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA3072pssCXNKc8sm_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA3072pssCXNKc8sm_LDADD = libsb_cfgRSA3072pssCXNKc8sm.a $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA3072pss_A) libsb_cfgRSA3072pssCXNKc8sm.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc0sw.a and securebootsim_cfgRSA4096pssIPc0sw
libsb_cfgRSA4096pssIPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA4096pssIPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES)
securebootsim_cfgRSA4096pssIPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc0sw_LDADD = libsb_cfgRSA4096pssIPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc1sw.a and securebootsim_cfgRSA4096pssIPc1sw
libsb_cfgRSA4096pssIPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA4096pssIPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES)
securebootsim_cfgRSA4096pssIPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc1sw_LDADD = libsb_cfgRSA4096pssIPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc2sw.a and securebootsim_cfgRSA4096pssIPc2sw
libsb_cfgRSA4096pssIPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA4096pssIPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES)
securebootsim_cfgRSA4096pssIPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc2sw_LDADD = libsb_cfgRSA4096pssIPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc8sw.a and securebootsim_cfgRSA4096pssIPc8sw
libsb_cfgRSA4096pssIPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA4096pssIPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES)
securebootsim_cfgRSA4096pssIPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc8sw_LDADD = libsb_cfgRSA4096pssIPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc0sw.a and securebootsim_cfgRSA4096pssCPc0sw
libsb_cfgRSA4096pssCPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc0sw_LDADD = libsb_cfgRSA4096pssCPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc1sw.a and securebootsim_cfgRSA4096pssCPc1sw
libsb_cfgRSA4096pssCPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc1sw_LDADD = libsb_cfgRSA4096pssCPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc2sw.a and securebootsim_cfgRSA4096pssCPc2sw
libsb_cfgRSA4096pssCPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc2sw_LDADD = libsb_cfgRSA4096pssCPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc8sw.a and securebootsim_cfgRSA4096pssCPc8sw
libsb_cfgRSA4096pssCPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc8sw_LDADD = libsb_cfgRSA4096pssCPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc0sw.a and securebootsim_cfgRSA4096pssCXPc0sw
libsb_cfgRSA4096pssCXPc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc0sw_LDADD = libsb_cfgRSA4096pssCXPc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc1sw.a and securebootsim_cfgRSA4096pssCXPc1sw
libsb_cfgRSA4096pssCXPc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc1sw_LDADD = libsb_cfgRSA4096pssCXPc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc2sw.a and securebootsim_cfgRSA4096pssCXPc2sw
libsb_cfgRSA4096pssCXPc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc2sw_LDADD = libsb_cfgRSA4096pssCXPc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc8sw.a and securebootsim_cfgRSA4096pssCXPc8sw
libsb_cfgRSA4096pssCXPc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc8sw_LDADD = libsb_cfgRSA4096pssCXPc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc0pk.a and securebootsim_cfgRSA4096pssIPc0pk
libsb_cfgRSA4096pssIPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT
securebootsim_cfgRSA4096pssIPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pssIPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc0pk_LDADD = libsb_cfgRSA4096pssIPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc1pk.a and securebootsim_cfgRSA4096pssIPc1pk
libsb_cfgRSA4096pssIPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1
securebootsim_cfgRSA4096pssIPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pssIPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc1pk_LDADD = libsb_cfgRSA4096pssIPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc2pk.a and securebootsim_cfgRSA4096pssIPc2pk
libsb_cfgRSA4096pssIPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2
securebootsim_cfgRSA4096pssIPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pssIPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc2pk_LDADD = libsb_cfgRSA4096pssIPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssIPc8pk.a and securebootsim_cfgRSA4096pssIPc8pk
libsb_cfgRSA4096pssIPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssIPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8
securebootsim_cfgRSA4096pssIPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE
securebootsim_cfgRSA4096pssIPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_verify.c
securebootsim_cfgRSA4096pssIPc8pk_LDADD = libsb_cfgRSA4096pssIPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssIPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc0pk.a and securebootsim_cfgRSA4096pssCPc0pk
libsb_cfgRSA4096pssCPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc0pk_LDADD = libsb_cfgRSA4096pssCPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc1pk.a and securebootsim_cfgRSA4096pssCPc1pk
libsb_cfgRSA4096pssCPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc1pk_LDADD = libsb_cfgRSA4096pssCPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc2pk.a and securebootsim_cfgRSA4096pssCPc2pk
libsb_cfgRSA4096pssCPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc2pk_LDADD = libsb_cfgRSA4096pssCPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPc8pk.a and securebootsim_cfgRSA4096pssCPc8pk
libsb_cfgRSA4096pssCPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pss_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pss_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPc8pk_LDADD = libsb_cfgRSA4096pssCPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc0pk.a and securebootsim_cfgRSA4096pssCXPc0pk
libsb_cfgRSA4096pssCXPc0pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc0pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc0pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc0pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc0pk_LDADD = libsb_cfgRSA4096pssCXPc0pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc0pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc1pk.a and securebootsim_cfgRSA4096pssCXPc1pk
libsb_cfgRSA4096pssCXPc1pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc1pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc1pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc1pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc1pk_LDADD = libsb_cfgRSA4096pssCXPc1pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc1pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc2pk.a and securebootsim_cfgRSA4096pssCXPc2pk
libsb_cfgRSA4096pssCXPc2pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc2pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc2pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc2pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc2pk_LDADD = libsb_cfgRSA4096pssCXPc2pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc2pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPc8pk.a and securebootsim_cfgRSA4096pssCXPc8pk
libsb_cfgRSA4096pssCXPc8pk_a_SOURCES =  $(SB_PK_DRIVER_SOURCES) \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_PK/src/sbpk_api_decrypt.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_hw_init.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_eip28_rsa_verify.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_aes_if.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_publicdata.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_PK/src/sbpk_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPc8pk_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPc8pk_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssAES256_INCLUDES) -DSBSIM_ALLOCATOR_DMARESOURCE -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPc8pk_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPc8pk_LDADD = libsb_cfgRSA4096pssCXPc8pk.a $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPc8pk.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPKc0sw.a and securebootsim_cfgRSA4096pssCPKc0sw
libsb_cfgRSA4096pssCPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDK_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPKc0sw_LDADD = libsb_cfgRSA4096pssCPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPKc1sw.a and securebootsim_cfgRSA4096pssCPKc1sw
libsb_cfgRSA4096pssCPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPKc1sw_LDADD = libsb_cfgRSA4096pssCPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPKc2sw.a and securebootsim_cfgRSA4096pssCPKc2sw
libsb_cfgRSA4096pssCPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPKc2sw_LDADD = libsb_cfgRSA4096pssCPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCPKc8sw.a and securebootsim_cfgRSA4096pssCPKc8sw
libsb_cfgRSA4096pssCPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDK_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDK_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCPKc8sw_LDADD = libsb_cfgRSA4096pssCPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCPKc8sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPKc0sw.a and securebootsim_cfgRSA4096pssCXPKc0sw
libsb_cfgRSA4096pssCXPKc0sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPKc0sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDKAES256_INCLUDES) -DSBLIB_CF_REMOVE_CERTIFICATE_SUPPORT -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPKc0sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPKc0sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPKc0sw_LDADD = libsb_cfgRSA4096pssCXPKc0sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPKc0sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPKc1sw.a and securebootsim_cfgRSA4096pssCXPKc1sw
libsb_cfgRSA4096pssCXPKc1sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPKc1sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=1 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPKc1sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPKc1sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPKc1sw_LDADD = libsb_cfgRSA4096pssCXPKc1sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPKc1sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPKc2sw.a and securebootsim_cfgRSA4096pssCXPKc2sw
libsb_cfgRSA4096pssCXPKc2sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPKc2sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=2 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPKc2sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPKc2sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPKc2sw_LDADD = libsb_cfgRSA4096pssCXPKc2sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPKc2sw.a $(OPT_LIBDEBUG_A)

# Rules for libsb_cfgRSA4096pssCXPKc8sw.a and securebootsim_cfgRSA4096pssCXPKc8sw
libsb_cfgRSA4096pssCXPKc8sw_a_SOURCES =  \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBLib/SB_SW/src/sbsw_api_decrypt.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_rsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_setfipsmode.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_system_info.c \
    $(top_src)/Framework/CLIB/src/c_lib.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(SB_SW_HASH256_SOURCES) \
    $(SB_SW_RSA_SOURCES)
libsb_cfgRSA4096pssCXPKc8sw_a_CPPFLAGS = $(LIBSB_HYBRIDRSA4096pssKDKAES256_INCLUDES) -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBLIB_CF_IMAGE_TYPE_W_SBCR_KEY
securebootsim_cfgRSA4096pssCXPKc8sw_CPPFLAGS = $(SECUREBOOTSIMRSA4096pssKDKAES256_INCLUDES) -DSBSIM_WITH_DECRYPT
securebootsim_cfgRSA4096pssCXPKc8sw_SOURCES = $(top_src)/SBLib/SBSIM/src/sbsim_decrypt_and_verify.c
securebootsim_cfgRSA4096pssCXPKc8sw_LDADD = libsb_cfgRSA4096pssCXPKc8sw.a $(LIBSBHW_TARGET_SW) $(LIBSBCRYPTORSA4096pss_A) libsb_cfgRSA4096pssCXPKc8sw.a $(OPT_LIBDEBUG_A)



securebootsim: $(SECUREBOOTSIM)
	cp -f $< $@

#----------------------------------------------------------------------------
# libtarget_bare: Target Barebones
#----------------------------------------------------------------------------

if ENABLE_BARE

libtarget_bare_a_CPPFLAGS = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl \
    -I$(top_src)/Framework/SPAL_API/incl \
    -I$(top_src)/Framework/CLIB/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Kit/DriverFramework/v4_bare/incl \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/GenericHelper/incl \
    -I$(top_src)/Kit/Log/incl \
    -I$(top_src)/Kit/Log/src/safezone

libtarget_bare_a_SOURCES = \
    $(top_src)/Integration/DriverFramework_v4_bare/src/hwpal_device_bare.c \
    $(top_src)/Integration/DriverFramework_v4_bare/src/hwpal_dmares_bare.c

endif

#----------------------------------------------------------------------------
# Software Only Secure Boot tests
#----------------------------------------------------------------------------

# A simple test case for Secure Boot P-224.

SBSW_CPPFLAGS = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl \
    -I$(top_src)/Framework/CLIB/incl \
    -I$(top_src)/Kit/DriverFramework/v4/GenericHelper/incl \
    -I$(top_src)/SFZUTF/incl \
    -I$(top_src)/SBLib/SB_API/incl \
    -I$(top_src)/SBLib/SB_HYBRID/src \
    -I$(top_src)/SBCommon/SBIF_API/incl \
    -I$(top_src)/SBCommon/SBIF_TOOLS/incl \
    -I$(top_src)/SBCommon/SB_SW_CRYPTO/incl

libsbsw224_a_SOURCES = \
    $(top_src)/SBLib/SB_HYBRID/src/sbhybrid_api.c

libsbsw224_a_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    -I$(top_src)/SBCommon/Config \
    $(SBSW_CPPFLAGS)

sbswtest224_LDADD = \
    libsb_cfgP224CPc0sw.a \
    $(check_LIBRARIES)

sbswtest224_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS)

sbswtest224_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestcp224.c


sbsmtest224_LDADD = \
    libsb_cfgP224CNc0sm.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW)

sbsmtest224_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE

sbsmtest224_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestcp224.c

sbpetest224_LDADD = \
    libsb_cfgP224CPc0pe.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_PE) $(LIBSB_GENERAL_HW)

sbpetest224_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE

sbpetest224_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestcp224.c

sbpepktest224_LDADD = \
    libsb_cfgP224CPc0pepk.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_PEPK) $(LIBSB_GENERAL_HW)

sbpepktest224_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE

sbpepktest224_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestcp224.c

sbpktest224_LDADD = \
    libsb_cfgP224CPc0pk.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_PK) $(LIBSB_GENERAL_HW)

sbpktest224_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS)

sbpktest224_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestcp224.c


# sb*testrsa*

# 2048pkcs
sbswtestrsa2048pkcs_LDADD = \
    libsb_cfgRSA2048pkcsCPc0sw.a \
    $(check_LIBRARIES)

sbswtestrsa2048pkcs_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS) \
    -DSUPPORT_RSA_PKCS

sbswtestrsa2048pkcs_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa2048.c

sbsmtestrsa2048pkcs_LDADD = \
    libsb_cfgRSA2048pkcsCNc0sm.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW)

sbsmtestrsa2048pkcs_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE \
    -DSUPPORT_RSA_PKCS

sbsmtestrsa2048pkcs_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa2048.c

# 3072
sbswtestrsa3072pkcs_LDADD = \
    libsb_cfgRSA3072pkcsCPc0sw.a \
    $(check_LIBRARIES)

sbswtestrsa3072pkcs_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS) \
    -DSUPPORT_RSA_PKCS

sbswtestrsa3072pkcs_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa3072.c

sbsmtestrsa3072pkcs_LDADD = \
    libsb_cfgRSA3072pkcsCNc0sm.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW)

sbsmtestrsa3072pkcs_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE \
    -DSUPPORT_RSA_PKCS

sbsmtestrsa3072pkcs_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa3072.c

# 4096
sbswtestrsa4096pkcs_LDADD = \
    libsb_cfgRSA4096pkcsCPc0sw.a \
    $(check_LIBRARIES)

sbswtestrsa4096pkcs_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA4096 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS) \
    -DSUPPORT_RSA_PKCS

sbswtestrsa4096pkcs_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa4096.c


# 2048pss
sbswtestrsa2048pss_LDADD = \
    libsb_cfgRSA2048pssCPc0sw.a \
    $(check_LIBRARIES)

sbswtestrsa2048pss_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS) \
    -DSUPPORT_RSA_PSS

sbswtestrsa2048pss_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa2048.c

sbsmtestrsa2048pss_LDADD = \
    libsb_cfgRSA2048pssCNc0sm.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW)

sbsmtestrsa2048pss_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA2048 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE \
    -DSUPPORT_RSA_PSS

sbsmtestrsa2048pss_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa2048.c

# 3072
sbswtestrsa3072pss_LDADD = \
    libsb_cfgRSA3072pssCPc0sw.a \
    $(check_LIBRARIES)

sbswtestrsa3072pss_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS) \
    -DSUPPORT_RSA_PSS

sbswtestrsa3072pss_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa3072.c

sbsmtestrsa3072pss_LDADD = \
    libsb_cfgRSA3072pssCNc0sm.a \
    $(check_LIBRARIES) \
    $(LIBSBHW_TARGET_SM) $(LIBSB_GENERAL_HW)

sbsmtestrsa3072pss_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA3072 \
    -I$(top_src)/SBCommon/Config \
    $(CONFIGURATION_INCLUDES) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    $(SBSW_CPPFLAGS) \
    -DSB_ALLOCATOR_DMARESOURCE \
    -DSUPPORT_RSA_PSS

sbsmtestrsa3072pss_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa3072.c

# 4096
sbswtestrsa4096pss_LDADD = \
    libsb_cfgRSA4096pssCPc0sw.a \
    $(check_LIBRARIES)

sbswtestrsa4096pss_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/RSA4096 \
    -I$(top_src)/SBCommon/Config \
    $(ABSTRACTION_INCLUDES) \
    $(SBSW_CPPFLAGS) \
    -DSUPPORT_RSA_PSS

sbswtestrsa4096pss_SOURCES = \
    $(top_src)/SBLib/SB_SW_TEST/src/sbswtestrsa4096.c


#----------------------------------------------------------------------------
# libsfzutf
#----------------------------------------------------------------------------

libsfzutf_a_CPPFLAGS = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl \
    -I$(top_src)/SFZUTF/incl \
    -I$(top_src)/Framework/SPAL_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/GenericHelper/incl

libsfzutf_a_SOURCES = \
    $(top_src)/SFZUTF/src/sfzutf.c \
    $(top_src)/SFZUTF/src/sfzutf_main_stdio.c \
    $(top_src)/SFZUTF/src/sfzutf_interactive.c \
    $(top_src)/SFZUTF/src/sfzutf-utils.c

if ENABLE_STACK
libsfzutf_a_SOURCES += $(top_src)/SFZUTF/src/sfzutf-stack.c
endif
if ENABLE_HEAP
libsfzutf_a_SOURCES += $(top_src)/SFZUTF/src/sfzutf-heap.c
endif
if ENABLE_PERF
libsfzutf_a_SOURCES += $(top_src)/SFZUTF/src/sfzutf-perf.c
endif


#----------------------------------------------------------------------------
# libdebug
#----------------------------------------------------------------------------

libdebug_a_CPPFLAGS = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl

libdebug_a_SOURCES = \
    $(top_src)/Framework/DEBUG/src/debug_printf.c \
    $(top_src)/Framework/DEBUG/src/debug_abort.c

if ENABLE_DEBUG
libdebug_a_CPPFLAGS += \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/Log/incl \
    -I$(top_src)/Kit/Log/src/safezone

libdebug_a_SOURCES += $(top_src)/Kit/Log/src/safezone/log_safezone.c
endif

#----------------------------------------------------------------------------
# updatetool
#----------------------------------------------------------------------------
updatetool_CPPFLAGS = \
    -I$(top_src)/SBCommon/Config/ECC224 \
    $(LIBSB_SW_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Basic_Defs/incl \
    -I$(top_src)/Kit/DriverFramework/v4/CLib_Abstraction/incl \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -DSBLIB_CFG_CERTIFICATES_MAX=8 -DSBSWCRYPTO_CF_FULL_FUNCTIONALITY -DAES_SUPPORT_ENCRYPT \
    -DuECC_SUPPORTS_secp224r1=1 -DuECC_SUPPORTS_secp256r1=1 -DuECC_SUPPORTS_secp384r1=1 -DuECC_SUPPORTS_secp521r1=1

# The updatetool is based on the same files as the Secure Boot Configuration has.
# However it requires key generation capability also.
updatetool_SOURCES = \
    $(top_src)/SBLib/UPDATE_TOOL/src/updatetool.c \
    $(SBIF_ATTRIBUTE_SUPPORT_SOURCES) \
    $(top_src)/SBCommon/SBIF_TOOLS/src/sbif_tools_convert.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_api.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_hw_init.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_aes_if.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_ecdsa_verify.c \
    $(top_src)/SBLib/SB_SW/src/sbsw_sw_publicdata.c \
    $(SB_SW_HASH512_SOURCES) \
    $(SB_SW_ECDSA_SOURCES) \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/sbcr_key.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/rijndael.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/nist-sp-chain.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/nist-health-test.c \
    $(top_src)/SBCommon/SB_SW_CRYPTO/src/nist-sp-800-90.c \
    $(top_src)/Framework/CLIB/src/c_lib.c

updatetool_LDADD = \
    libdebug.a

#----------------------------------------------------------------------------
# sbtest_publicdata
#----------------------------------------------------------------------------

sbtest_publicdata_sw_CPPFLAGS = \
    $(CONFIGURATION_INCLUDES) \
    -I$(top_src)/SBCommon/Config \
    -I$(top_src)/Framework/PUBDEFS/incl \
    -I$(top_src)/Framework/IMPLDEFS/incl \
    -I$(top_src)/Framework/CLIB/incl \
    -I$(top_src)/Kit/DriverFramework/v4/GenericHelper/incl \
    -I$(top_src)/SFZUTF/incl \
    -I$(top_src)/SBLib/SB_API/incl \
    -I$(top_src)/SBLib/SB_HYBRID/src \
    -I$(top_src)/SBCommon/SBIF_API/incl \
    -I$(top_src)/SBCommon/SBIF_TOOLS/incl \
    -I$(top_src)/SBCommon/SB_SW_CRYPTO/incl

sbtest_publicdata_sw_SOURCES = \
    $(top_src)/SBLib/SB_TEST/src/sbtest_publicdata.c

sbtest_publicdata_sw_LDADD = \
    libsb_cfgP224IPc0sw.a \
    $(LIBSBIF_A) \
    $(LIBSBCRYPTO_A) \
    libsb_cfgP224IPc0sw.a \
    $(LIBSBIF_TOOLS_KGF_A) \
    libdebug.a

sbtest_publicdata_sm_CPPFLAGS = \
    $(sbtest_publicdata_sw_CPPFLAGS) \
    $(ABSTRACTION_INCLUDES) \
    -I$(top_src)/Kit/DriverFramework/v4/Device_API/incl \
    -I$(top_src)/Kit/DriverFramework/v4/DMAResource_API/incl \
    $(DMARES_INCLUDE) \
    -I$(top_src)/Integration/UMDevXS/UserPart/incl \
    -I$(top_src)/Kit/EIP130/MailboxControl/incl \
    -I$(top_src)/Kit/EIP130/TokenHelper/incl \
    -DSBSIM_ALLOCATOR_DMARESOURCE



sbtest_publicdata_sm_SOURCES = \
    $(sbtest_publicdata_sw_SOURCES)

sbtest_publicdata_sm_LDADD = \
    libsb_cfgP224IPc0sm.a \
    $(LIBSBIF_A) \
    $(LIBSBCRYPTO_A) \
    $(LIBSBIF_TOOLS_KGF_A) \
    $(LIBSBHW_TARGET_SM) \
    libsb_cfgP224IPc0sm.a \
    libdebug.a \
    $(LIBSB_GENERAL_HW)

#----------------------------------------------------------------------------

# Notice: nobuffer.so is compiled with non-automake rule
nobuffer.so: $(top_src)/SFZUTF/util/nobuffer.c
	$(CC) $(CFLAGS) -shared -o $@ $<

# Flags & rules for running test runner
TESTRUNNER_FLAGS = "--timeout=600"

list_check:
	for test in $(check_PROGRAMS); \
	do echo '***' $$test;./$$test --list 2>&1; done

# Test runner (for single tests)
%.xml: %
	echo $(TESTRUNNER_PRE) \
            $(top_src)/SFZUTF/scripts/testrunner.pl \
            $(TESTRUNNER_FLAGS) \
            --xmllog=$@ \
            $<; \
        $(TESTRUNNER_PRE) \
            $(top_src)/SFZUTF/scripts/testrunner.pl \
            $(TESTRUNNER_FLAGS) \
            --xmllog=$@ \
            $<

run_check: $(check_PROGRAMS)
	@ok=0; \
    count=0; \
    for test in $(check_PROGRAMS); \
    do \
        count=$$((count+1)); \
        echo $(TESTRUNNER_PRE) \
            $(top_src)/SFZUTF/scripts/testrunner.pl \
            $(TESTRUNNER_FLAGS) \
            --xmllog=$$test.xml \
            $$test; \
        $(TESTRUNNER_PRE) \
            $(top_src)/SFZUTF/scripts/testrunner.pl \
            $(TESTRUNNER_FLAGS) \
            --xmllog=$$test.xml \
            $$test; \
        RES=$$?; \
        if [ "$$RES" -eq "0" ]; then \
            ok=$$((ok+1)); \
        fi; \
        if [ "$$RES" -eq "255" ]; then \
            echo "Test suite execution terminated"; \
            exit 1; \
        fi; \
    done; \
    echo "*** $$count TEST SUITES: $$ok/$$count SUCCESSFUL"

run_check_ssh: $(check_PROGRAMS)
	@ok=0; \
    count=0; \
    for test in $(check_PROGRAMS); \
    do \
        count=$$((count+1)); \
        scp $$test $(SSH_TARGET):/tmp/test; \
        echo \
            $(TESTRUNNER_PRE) \
            $(top_src)/SFZUTF/scripts/testrunner.pl \
            $(TESTRUNNER_FLAGS) \
            --interpreter=ssh \
            --interpreter-opts="-t -t $(SSH_TARGET)" \
            --xmllog=$$test.xml \
            /tmp/test \
            '#'$$test; \
        $(TESTRUNNER_PRE) \
            $(top_src)/SFZUTF/scripts/testrunner.pl \
            $(TESTRUNNER_FLAGS) \
            --interpreter=ssh \
            --interpreter-opts="-t -t $(SSH_TARGET)" \
            --xmllog=$$test.xml \
            /tmp/test; \
        RES=$$?; \
        if [ "$$RES" -eq "0" ]; then \
            ok=$$((ok+1)); \
        fi; \
        if [ "$$RES" -eq "255" ]; then \
            echo "Test suite execution terminated"; \
            exit 1; \
        fi; \
    done; \
    echo "*** $$count TEST SUITES: $$ok/$$count SUCCESSFUL"

#----------------------------------------------------------------------------
# Clean up
#----------------------------------------------------------------------------

distclean-local:
	rm -f aclocal.m4 compile configure install-sh Makefile.in missing depcomp config.guess config.sub
	rm -rf autom4te.cache
	rm -f *.gcno *.gcda *.xml
	rm -f libsb_*.a libtarget_*.a

# end of file Makefile.am

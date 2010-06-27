/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#ifndef _PRIVMPM_H /* Prevent multiple inclusion */
#define _PRIVMPM_H

#include "ut.h"       /* For utb, u32, ut_new_mem(), & ut_dispose_mem() */

#ifndef WITH_mma
#include "mpa.h"      /* For mpa_prec & mpa_dig */
#else /* WITH_mma */
#include "mma.h"      /* For mpa_prec & mpa_dig */
#endif

#include "mpm.h"      /* For flag_st, mpm_id, & MPM_DIG_BITS */

#include "register.h" /* For reg_st */

/* Type: <flag_st>
 * Note: In the interface definition, flag indentifiers are given to the user
 *         to reference the internal machine's flags.  Within the library a
 *         structure of boolean values is used to store the flags.
 */
typedef struct {
  utb div_zero;
  utb overflow;
  utb zero;
  utb negative;
} flag_st;

/* Type: <mach_st>, <mach_pt>
 * Note: The user of the MPM library is given a machine identifier as a handle
 *         on the particular machine being used.  Each machine identifier
 *         uniquely identifies the machine.  This is ensured by using a pointer
 *         to the internal machine as the identifier from which we can
 *         guarantee a unique identifier and also map one to the other easily.
 *       A machine contains a set of registers, which the user references with
 *         the register identifiers and a set of flags, referenced by flag
 *         identifiers.
 *       In addition to the user's accessible register an extra register is
 *         needed for holding intermediate results.
 *       Macros to provide the mapping from machine identifier to a pointer to
 *         a machine, and back, are given.
 */
typedef struct {
  reg_st  register_v[MPM_NUM_REGS]; /* the registers */
  flag_st flag;                     /* the flags */
  reg_st  extra_reg;                /* an extra reg for intermediate results */
#ifdef WITH_mma
  mpa_dig n0p;                      /* montgomery operations */
#endif
} mach_st, *mach_pt;

/* Convert an mpm_mid to a _mach_pt */
#define MPM_MID_T2MACH_PT(mid) ((mach_pt) mid)

/* Convert a _mach_pt to an mpm_mid */
#define MACH_PT2MPM_MID(mach_p) ((mpm_id) mach_p)

/* To hide the internal representation from the user (since the change of
 * machine architecture would cause the word size for basic arithmetic
 * operations to change) the external interface ensures a fixed representation
 * for numbers.
 * NOTE: The internal representation is that provided by the mpa package.
 * When transferring numbers in and out of registers (which use the internal
 * representation) a mapping must be performed.  This mapping is not
 * complicated.  To help this task however a constant REP_RATIO is provided,
 * which contains the number of external places in an internal place.  For
 * example, if the internal representation uses a double-word the REP_RATIO
 * would be four since there are 4 bytes in a double-word.  Also needed for
 * convertion is the base of mpm_dig which is of type mpa_dig.
 */
#define REP_RATIO ((mpa_prec) sizeof(mpa_dig))
#define BASE_MPM_DIG ((mpa_dig) (1 << MPM_DIG_BITS))

/* Argument checking and assertions */

/* The multiple precision machine provides a compile-time option to perform two
 * types of checking.  The two types of checking are internal checking of its
 * own operations and the second checking external routines at the point which
 * the interface with the mpm package - i.e. checking arguments to the
 * library's external interface.  Macros which enable these checks when defined
 * during compilation are listed below:
 *   _MPM_SELF_CHECK - check internal operations
 *   _MPM_CHECK_ARGS - check external interface
 */

#ifdef _MPM_SELF_CHECK
extern void _mpm_assert(utb, char *, short);

#define _MPM_ASSERT(bool) (_mpm_assert(bool, __FILE__, __LINE__))
#else /* _MPM_SELF_CHECK/not _MPM_SELF_CHECK */
#define _MPM_ASSERT(bool)
#endif /* not _MPM_SELF_CHECK */

#ifdef _MPM_CHECK_ARGS
extern void _mpm_check_arg(utb, char *, short, char *);

#define _MPM_CHECK_ARG(bool, func_name, param, error_desc) \
       (_mpm_check_arg(bool, func_name, param, error_desc))
#else /* _MPM_CHECK_ARGS/not _MPM_CHECK_ARGS */
#define _MPM_CHECK_ARG(bool, func_name, param, error_desc)
#endif /* not _MPM_CHECK_ARGS */

#ifndef WITH_mma
/* For add & sub */
extern utb _mpm_add_abs(reg_pt res_p, reg_pt op1_p, reg_pt op2_p);
extern utb _mpm_sub_abs(reg_pt res_p, reg_pt op1_p, reg_pt op2_p);
#endif

#endif /* not _PRIVMPM_H */

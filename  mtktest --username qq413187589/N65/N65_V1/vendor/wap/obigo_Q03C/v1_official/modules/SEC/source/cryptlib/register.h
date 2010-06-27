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

#ifndef _REG_H /* Prevent multiple inclusion */
#define _REG_H

#ifndef WITH_mma
#include "mpa.h"    /* For mpa_num & mpa_prec */
#else /* WITH_mma */
#include "mma.h"
#endif

#include "mpm.h"    /* For MPM_NEG, MPM_POS, mpm_arc, mpm_prec,
    & mpm_sign */
#include "ut.h"     /* For utb */

/* Type: <reg_st>, <reg_pt>
 * Note: A register is a container for signed multiple precision numbers stored
 *         in sign-magnitude notation.  The MPM library dynamically allocates
 *         storage for numbers so as to handle any precision that there is
 *         memory for.  To help in this a book-keeping slot in each register
 *         contains the allocated precision of that register.  If the register
 *         is required to hold a number with a larger precision than this, the
 *         places in the number would need to be reallocated.  Registers are
 *         allocated in blocks, the macro REG_BLOCK_SIZE defines the size of
 *         block.  Along with the typedef for a register, some macros are
 *         provided to make the following tests:
 *           1. a register has allocated places for a number
 *           2. a register has a defined value (on the assumption that it has
 *                allocated places for a number)
 *           3. a register has a loaded value, i.e. that the register has both
 *                allocated places and contains a valid number
 *           4. is the number defined negative
 *           5. is the number defined equal to zero
 *         An archived register is simply a register; macros are provided below
 *         to cast to and from each type.
 */
typedef struct {
  mpm_sign sign;
  mpa_num  norm_val;   /* The normalised absolute value of the number in the
                        * register. */
  mpa_prec alloc_prec; /* allocated precision */
} reg_st, *reg_pt;

/* allocated in multiples of REG_BLOCK_SIZE u32s - 288 bits is 9 */
#define REG_BLOCK_SIZE 9

/* Check if a reg_st has places allocated */
#define REG_ALLOCED(reg_s) ((reg_s).alloc_prec != 0)

/* Check if a reg_st has an defined value */
#define REG_DEFINED(reg_s) ((reg_s).norm_val.prec != 0)

/* Check if a reg_st has a loaded value */
#define REG_LOADED(reg_s) (((reg_s).alloc_prec != 0) \
    && ((reg_s).norm_val.prec != 0))

/* Check if a reg_s is negative - NOTE: Negative only if not zero */
#define REG_NEG(reg_s) (!((reg_s).norm_val.prec == 1 \
    && (reg_s).norm_val.dig[0] == 0) && (reg_s).sign == MPM_NEG)

/* Check if a reg_s is equal to zero */
#define REG_ZERO(reg_s) (((reg_s).norm_val.prec == 1) \
    && ((reg_s).norm_val.dig[0] == 0))

/* Retrieve the sign */
#define REG_SIGN(reg_s) ((reg_s).norm_val.prec == 1 \
    && (reg_s).norm_val.dig[0] == 0 ? MPM_POS : (reg_s).sign)

/* Check if a reg_s is even */
#define REG_ISEVEN(reg_s) ((reg_s).norm_val.prec == 0 \
    || !((reg_s).norm_val.dig[0] & 1))

/* Convert a register pointer to an archived register handle */
#define MPM_REG_ARC_T2REG_PT(arc) ((reg_pt) (arc))

/* Convert an archived register handle to a register pointer */
#define REG_PT2MPM_REG_ARC_T(reg_p) ((mpm_arc) (reg_p))

/* Operation: <reg_prep>
 * Syntax:    success = reg_prep(reg_p, prec, preserve);
 * Semantics: This operation can be used to prepare a register for use.  reg_p
 *              is the register, prec is the maximum expected size (must be
 *              greater than 0) and preserve is a flag to indicate whether or
 *              not the current contents of the register should be preserved.
 * Failure:   (i.e. success == UT_FALSE) Can only fail due to memory
 *              allocation difficulties.  If failure occurs, then no changes
 *              will have taken place.
 */
extern utb reg_prep(reg_pt reg_p, mpa_prec prec, utb preserve);

/* Operation: <reg_norm>
 * Syntax:    reg_norm(reg_p, prec)
 * Semantics: Normalises the register reg_p, where prec is given as the current
 *              precision of the number.  A normalised number will always have
 *              a non-zero most significant place except when the number is
 *              zero.
 * Failure:   None
 */
extern void reg_norm(reg_pt reg_p, mpa_prec prec);

/* Operation: <reg_move_abs>
 * Syntax:    success = reg_move_abs(dest_p, src_p, preserve)
 * Semantics: This routine is used to copy the absolute contents of one
 *              register into another register.  If preserve is set, it is
 *              copied and src_p remains defined, otherwise the places are
 *              transferred.  This routine does not move the sign of a
 *              register - the sign of the source register will not be
 *              corrupted under any circumstances.
 * Failure:   (i.e. success == UT_FALSE) If preserve is UT_TRUE then memory
 *              allocation failure may occur, in which case no changes will be
 *              made.
 */
extern utb reg_move_abs(reg_pt dest_p, reg_pt src_p, utb preserve);

#ifndef WITH_mma
/* Function:  <reg_gr_abs>
 * Syntax:    bool = reg_gr_abs(op1_p, op2_p)
 * Semantics: Returns the result of the "absolute greater than" comparison of
 *              the two operands: abs(op1) > abs(op2)
 * Failure:   None
 */
extern utb reg_gr_abs(reg_pt op1_p, reg_pt op2_p);
#endif

/* Function:  <reg_mpm_places>
 * Syntax:    sizeof = reg_mpm_places(reg)
 * Semantics: This routine returns the number of mpm_dig's which the
 *              contents of a register would require if stored in that
 *              representation.
 * Failure:   Overflow in the mpm_prec type - return 0
 */
extern mpm_prec reg_mpm_places(reg_pt reg_p);

#ifndef WITH_mma

/* Function:  <reg_nbits>
 * Syntax:    nbits = reg_nbits(reg)
 * Semantics: This routine returns nbits, the smallest number > 1 such that
 *              2^nbits > reg.
 */
extern u32 reg_nbits(reg_pt reg_p);

#endif

#endif /* not _REG_H */

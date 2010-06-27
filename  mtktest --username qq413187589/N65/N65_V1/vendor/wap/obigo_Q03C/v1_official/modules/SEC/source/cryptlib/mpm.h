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

#ifndef _MPM_H /* prevent multiple inclusion */
#define _MPM_H

/*loko#include "limits.h"*/  /* For USHRT_MAX */

#include "ut.h"     /* For utb, u8, u16, & u32 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ERRORS */

#define MPM_EBASE  (0x00300000) /* Module code */

#define MPM_EUNEXP (MPM_EBASE + 0x40000) /* Wrong type */
#define MPM_ENTRNL (MPM_EBASE + 0x40001) /* Internal function failure */
#define MPM_ENOMEM (MPM_EBASE + 0x40002) /* No Memory */
#define MPM_EPARAM (MPM_EBASE + 0x40003) /* Bad Parameter */

/* With this package it is possible to create, at will, multiple precision
 * arithmetic machines.  Each machine is referenced by an identifier.  Routines
 * to create new machines and to dispose of them when no longer necessary are
 * prototyped below.  The structure is hidden and as a result machines are
 * declared as (void *).
 */
typedef void *mpm_id; /* machine identifier, returned by 'new' and used on
                       * ALL subsequent calls. */

mpm_id mpm_new_mach(void);       /* Create a new machine. */
void   mpm_dispose_mach(mpm_id); /* Used to dispose machine when no longer
                                  * necessary. */

/* Externally a machine can be seen as a collection of registers and flags,
 * much like a microprocessor.  Each of the eight registers is capable of
 * storing signed multiple precision numbers.  Register seven is the only
 * special register and is used as the implied modulus operand in ALL of the
 * modulo-arithmetic functions.  It can be referenced as either R7 or RMOD.
 *  * Below is the definition of the register set.
 */
typedef enum {
  MPM_R0, MPM_R1, MPM_R2, MPM_R3, /* General purpose */
  MPM_R4, MPM_R5, MPM_R6,         /* General purpose */
  MPM_R7, MPM_RMOD = MPM_R7,      /* R7, RMOD - special modulus register */
  MPM_NUM_REGS                    /* The number of registers */
} mpm_reg;

/* After each operation, flags may be set or cleared to reflect the result
 * and/or any errors which may have occurred.  The flags are defined below.
 */
typedef enum {
  MPM_D, MPM_DIV_ZERO = MPM_D, /* Divide by zero error */
  MPM_O, MPM_OVERFLOW = MPM_O, /* Overflow - result too large error */
  MPM_Z, MPM_ZERO  = MPM_Z,    /* Zero - result was zero, also used by
                                * comparison operators */
  MPM_N, MPM_NEGATIVE = MPM_N, /* Negative - result was negative value  */
  MPM_NUM_FLAGS                /* The number of flags */
} mpm_flag;

/* The internal representation of numbers is not presented in the interface
 * definition; however a rigid external definition of the numbers is defined
 * and guaranteed not to change.  Both the operations load and store are based
 * on this representation.  Four elements or types are defined.  A multiple
 * precision number is presented as a sequence [vector - variable length] of
 * places.  Each element in this seqence is a `place' and one or more of these
 * called `places'.  In a sequence A, place A[0] is the least significant
 * place, A[1] the next and so on.  In addition to place and places,
 * `precision' is defined to be the normalized precision (in places) of the
 * number being represented.  The last element is the sign of the number which
 * is either positive or negative.  Therefore a number is represented by a
 * triplet (sign, precision, places), e.g. (+, 3, [653, 9876, 65]) would mean
 * (the base of a place being say 'b') 653 + (9876 * b) + (65 * b^2).  The
 * type definitions for these are below.
 */
typedef enum {
  MPM_NEG, MPM_POS
} mpm_sign;           /* sign */
typedef u8  mpm_dig;  /* place */
typedef u16 mpm_prec; /* precision */

#define MPM_DIG_BITS 8                   /* bits per place */
#define MPM_MAX_PREC ((mpm_prec) UINT_MAX) /* max value for mpm_prec */

/* Registers which only need to be stored/saved for later restoration into the
 * same or a different machine don't need to be converted to and from the
 * external representation.  For this purpose an archived register can be used
 * and a handle to the archive is given.  Again the structure is hidden from
 * the user and so it is declared (void *).
 */
#ifndef _MPM_ARC
#define _MPM_ARC
typedef void * mpm_arc; /* handle to an archived register */
#endif  /* ndef _MPM_ARC */

/* Function:    <mpm_load>
 * Syntax:      mpm_load(mid, dest_rid, sign, precision, places);
 * Description: This routine loads register dest_rid in the machine mid with the
 *              value represented by the triple (sign, precision, places).
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 * Usage:     For loading immediate values say 0x1, 0x2, 0x9876543210 the
 *              routine can be used as follows (since mpm_dig is a
 *              character):
 *              mpm_load(<mid>, MPM_R<i>, MPM_[POS|NEG], 1, "\0");  { zero }
 *              mpm_load(<mid>, MPM_R<i>, MPM_POS, 1, "\1"); { 1 }
 *              mpm_load(<mid>, MPM_R<i>, MPM_NEG, 1, "\2"); { -2 }
 *              mpm_load(<mid>, MPM_R<i>, MPM_POS, 5, "\x10\x32\x54\x76\x98");
 *                                              { 0x9876543210 }
 */
extern void mpm_load(mpm_id, mpm_reg, mpm_sign, mpm_prec, mpm_dig *);

/* Function:    <mpm_store>
 * Syntax:      success = mpm_store(mid, dest_sign_p, dest_precision_p,
 *                dest_places_p, max_precision, src_rid);
 * Description: This routine is used to retrieve the contents of registers and
 *              store them in the external interface representation.
 * Failure:     1) The precision of the number to be stored is greater than the
 *               maximum precision the routine was given.  The precision which
 *               would be needed is stored in dest_precision, all other outputs
 *               are undefined.
 *              2) The precision of the number is too great to store in an
 *               mpm_prec and as such the operation could never be performed!
 *               The return of zero is used to indicate this and a divide and
 *               conquer must be used to perform the store.
 */
extern utb mpm_store(mpm_id, mpm_sign *, mpm_prec *, mpm_dig *, mpm_prec,
                     mpm_reg);

/* Function:    <mpm_bload>, <mpm_bstore>
 * Description: These operations duplicate mpm_load and mpm_store, except
 *              the places data is big-endian (i.e. most significant octet
 *              first).
 */
extern void mpm_bload(mpm_id, mpm_reg, mpm_sign, mpm_prec, mpm_dig *);
extern utb mpm_bstore(mpm_id, mpm_sign *, mpm_prec *, mpm_dig *, mpm_prec,
                     mpm_reg);

/* Function:    <mpm_load_arc>, <mpm_store_arc>
 * Description: These operations duplicate mpm_load and mpm_store, except they
 *              operate on archives instead of machines and registers;
 *              mpm_load_arc() returns 0 on failure, or the requested archive
 *              on success.
 */
extern mpm_arc mpm_load_arc(mpm_sign, mpm_prec, mpm_dig *);
extern utb mpm_store_arc(mpm_sign *, mpm_prec *, mpm_dig *, mpm_prec, mpm_arc);

/* Function:    <mpm_bload_arc>, <mpm_bstore_arc>
 * Description: These operations duplicate mpm_load_arc and mpm_store_arc, except
 *              the places data is big-endian (i.e. most significant octet
 *              first).
 */
extern mpm_arc mpm_bload_arc(mpm_sign, mpm_prec, mpm_dig *);
extern utb mpm_bstore_arc(mpm_sign *, mpm_prec *, mpm_dig *, mpm_prec, mpm_arc);

/* Function:    <mpm_ltompm>
 * Syntax:      mpm_ltompm(mid, dest_rid, val);
 * Description: This routine is used to load a register with a specified signed
 *              long integral value.
 * Failure:     If memory failure occurs, the machine's OVERFLOW flag will be
 *               set.
 */
extern void mpm_ltompm(mpm_id, mpm_reg, long);

/* Function:    <mpm_mpmtol>
 * Syntax:      val = mpm_mpmtol(mid, src_rid);
 * Description: This routine is used to retrieve the value of a register as a
 *              signed long integral value.
 * Failure:     The routine cannot fail, but in the event of the register
 *              contents being too large for a long, the returned value will be
 *              LONG_MAX or LONG_MIN, depending on source sign.
 */
extern long mpm_mpmtol(mpm_id, mpm_reg);

/* Function:    <mpm_move>
 * Syntax:      mpm_move(mid, dest_rid, src_rid, preserve);
 * Description: Move the value of the source register to the destination
 *              register.  If the value of preserve is UT_TRUE, then the
 *              src_rid retains its value; if the value of preserve is not
 *              UT_TRUE the value of src_rid is not retained and the value of
 *              the register is undefined.
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_move(mpm_id, mpm_reg, mpm_reg, utb);

/* Function:    <mpm_transfer>
 * Syntax:      mpm_transfer(dest_mid, dest_rid, src_mid, src_rid, preserve);
 * Description: Used to transfer a register from one machine to another.
 *              Preserve tells the package whether it is to retain the source
 *              register.
 */
extern void mpm_transfer(mpm_id, mpm_reg, mpm_id, mpm_reg, utb);

/* Function:    <mpm_backup>
 * Syntax:      arc_reg = mpm_backup(mid, rid, preserve);
 * Description: Backup a register to archive.  If the value of preserve is true
 *              then the rid retains its value otherwise it is lost.
 * Failure:     Failure due to memory allocation difficulties will be indicated
 *              by a return value of 0.  If this does occur then the value of
 *              the source register will be retained regardless of the value of
 *              preserve.
 */
extern mpm_arc mpm_backup(mpm_id, mpm_reg, utb);

/* Function:    <mpm_restore>
 * Syntax:      mpm_restore(mid, rid, arc_reg, preserve);
 * Description: This routine restores the value in an archived register to the
 *              register of a machine (not necessarilly the machine it was
 *              archived from).  If preserve is UT_TRUE the archive remains
 *              valid after the call; otherwise it is lost and further restores
 *              will cause undefined values to be placed in registers.
 */
extern void mpm_restore(mpm_id, mpm_reg, mpm_arc, utb);

/* Function:    <mpm_copy_arc>
 * Syntax:      new_arc_reg = mpm_copy_arc(arc_reg);
 * Description: Duplicates the indicated archive register; returns 0 on failure.
 */
extern mpm_arc mpm_copy_arc(mpm_arc);

/* Function:    <mpm_kill_arc>
 * Syntax:      mpm_kill_arc(arc_reg);
 * Description: Sometimes it is necessary to dispose of (kill) an archive
 *              register without performing a restore since the value is not
 *              needed.  This routine provides this function.
 */
extern void CST32EXPORTTYPE CST16EXPORTTYPE mpm_kill_arc(mpm_arc);

/* Function:    <mpm_flag_set>
 * Syntax:      mpm_flag_set(mid, fid)
 * Description: The function returns the status of an MPM flag.
 */
extern utb mpm_flag_set(mpm_id, mpm_flag);

/* Function:    <mpm_set_flag>
 * Syntax:      mpm_set_flag(mid, fid, set)
 * Description: Sets the flag fid if set is UT_TRUE; otherwise fid is cleared.
 */
extern void mpm_set_flag(mpm_id, mpm_flag, utb);

/* Function:    <mpm_add>
 * Syntax:      mpm_add(mid, res_rid, op1_rid, op2_rid);
 * Description: Adds the contents of the op1 and op2 registers and places the
 *              result in the result register.  This routine performs a signed
 *              addition.
 * Flags:     MPM_ZERO:     if result zero
 *            MPM_NEGATIVE: if result negative
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_add(mpm_id, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_sub>
 * Syntax:      mpm_sub(mid, res_rid, op1_rid, op2_rid);
 * Description: Subtracts the contents of the op2 register from the op1 register
 *              and places the result in the result register.  This routine
 *              performs a signed subtraction.
 * Flags:     MPM_ZERO:     if result zero
 *            MPM_NEGATIVE: if result negative
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_sub(mpm_id, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_mul>
 * Syntax:      mpm_mul(mid, res_rid, op1_rid, op2_rid);
 * Description: Multiplies the contents of the op1 and op2 registers and places
 *              the result in the result register.  This routine performs a
 *              signed multiplication.
 * Flags:     MPM_ZERO:     if result zero
 *            MPM_NEGATIVE: if result negative
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_mul(mpm_id, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_div>
 * Syntax:      mpm_div(mid, qoutient_rid, remainder_rid, op1_rid, op2_rid);
 * Description: Divides the contents of the op1 register by the op2 register and
 *              places the quotient result and remainder results in registers.
 *              This routine performs a signed division where the remainder can
 *              be negative.  Note the quotient is the same sign as the
 *              mathematical (real) quotient.  The absolute value is the
 *              largest number less than the absolute value of the mathematical
 *              (real) quotient.  The sign of the remainder is the same as the
 *              sign of the numerator (this is a consequence of the above).
 * Usage:     1. quotient_rid != remainder_rid
 *            2. either quotient_rid or remainder_rid can be op1_rid or op2_rid
 *                 but not both (i.e. if quotient_rid is op1_rid then
 *                 remainder_rid can not be op1_rid or op2_rid).
 * Flags:     MPM_ZERO:     if remainder zero
 *            MPM_NEGATIVE: if quotient is negative (Note: the sign of the
 *                            remainder will be the same as the sign of the
 *                            numerator)
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_div(mpm_id, mpm_reg, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_sqrt>
 * Syntax:      mpm_sqrt(mid, root_rid, remainder_rid, op_rid);
 * Description: Calculates the square root of op, which it places in root.  If
 *              remainder_rid != root_rid then the remainder (op - root * root)
 *              is placed in remainder.  The routine fails if it runs out of
 *              memory or if op is negative.  On success, the NEG flag is
 *              cleared and the ZERO flag is set if op is an exact square (i.e.
 *              remainder is zero).  root is the largest integer satisfying
 *                                 root * root <= op
 * Usage:     Either root_rid or remainder_rid may be op_rid, but if root_rid
 *              == remainder_rid then no remainder is returned.
 * Flags:     MPM_ZERO:     if remainder zero
 *            MPM_NEGATIVE: cleared if successful
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 *            MPM_NEGATIVE set: Operand was negative.
 */
extern void mpm_sqrt(mpm_id, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_smod>
 * Syntax:      result = mpm_smod(mid, op_rid, mod_array);
 * Description: Calculates op % modulus quickly, with the restriction that:
 *                               0 < modulus < 40504
 *              .. modulus is supplied as an array of three unsigned values:
 *                  mod_array[0] = modulus
 *                  mod_array[1] = (1 << (CHAR_BIT * sizeof(mpa_dig) / 2))
 *                                 % modulus
 *                  mod_array[2] = mod_array[1] * mod_array[1] % modulus
 *              .. this is to allow the latter pair of numbers to be pre-
 *              calculated and stored in an array for increased speed.  The
 *              routine is designed for use in primality tests.  Division by
 *              zero is not tested against, since an error as a result of this
 *              should already have occurred when calculating mod_array[1].
 * Flags:     No flags are affected since the result is returned outside the
 *            machine.
 * Failure:     The routine cannot fail if given valid arguments.
 */
extern u16 mpm_smod(mpm_id, mpm_reg, const unsigned *);

/* Function:    <mpm_mod>
 * Syntax:      mpm_mod(mid, res_rid, op_rid)
 * Description: Modulo operation of the operand using the machine's modulus
 *              contained in the MPM_MOD register.
 * Comment:   The RMOD register is an implied operand.
 * Flags:     MPM_ZERO:     if result zero
 *            MPM_NEGATIVE: if result negative
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_mod(mpm_id, mpm_reg, mpm_reg);

/* Function:    <mpm_mulm>
 * Syntax:      mpm_mulm(mid, res_rid, op1_rid, op2_rid)
 * Description: Modulo multiplication.
 * Comment:   The RMOD register is an implied operand.
 * Flags:     MPM_ZERO:     if result zero
 *            MPM_NEGATIVE: if result negative
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_mulm(mpm_id, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_expm>
 * Syntax:      mpm_expm(mid, res_rid, op_rid, exp_rid);
 * Description: Modular exponentiation of the operand register to the power of
 *              the exponent register, using the machine loaded modulus, with
 *              the result put into the result.
 * Comment:   The RMOD register is an implied operand.
 * Flags:     MPM_ZERO:     if result zero
 *            MPM_NEGATIVE: if result negative
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_expm(mpm_id, mpm_reg, mpm_reg, mpm_reg);

#ifdef WITH_mma
extern void mpm_shl(mpm_id, mpm_reg, mpm_reg, u32);
extern void mpm_shr(mpm_id, mpm_reg, mpm_reg, u32);
#endif

/* Function:    <mpm_gcd>
 * Syntax:      mpm_gcd(mid, res_rid, op1_rid, op2_rid);
 * Description: This routine uses Stein's algorithm to calculate the greatest
 *              common divisor of op1 and op2.
 * Failure:     This routine can fail only on account of memory allocation
 *              failure, in which case the operands will be unchanged and
 *              the overflow flag will be set.
 */
extern void mpm_gcd(mpm_id, mpm_reg, mpm_reg, mpm_reg);

/* Function:    <mpm_clear>
 * Syntax:      mpm_clear(mid, rid)
 * Description: Sets the value of the register to zero.
 * Flags:     MPM_ZERO: always
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_clear(mpm_id, mpm_reg);

/* Function:    <mpm_cmp>
 * Syntax:      mpm_cmp(mid, op1_rid, op2_rid);
 * Description: This routine sets the flags MPM_ZERO and MPM_NEGATIVE on the
 *              results of an op1 - op2 operation.  This function should be
 *              used in conjuntion with the functions mpm_lt(), mpm_gt() &c. to
 *              provide the full complement of comparisons.
 */
extern void mpm_cmp(mpm_id, mpm_reg, mpm_reg);

/* Function:    <mpm_cmp_arc>
 * Syntax:      result = mpm_cmp_arc(op1_arc, op2_arc);
 * Description: This routine compares op1_arc and op2_arc, returning -1 if
 *              op1_arc < op2_arc, 0 if op1_arc == op2_arc or +1 if op1_arc >
 *              op2_arc.
 */
extern int mpm_cmp_arc(mpm_arc, mpm_arc);

/* Function:    <mpm_set_on>
 * Syntax:      mpm_set_on(mid, op_rid);
 * Description: Sets the flags MPM_ZERO and MPM_NEGATIVE depending on the value
 *              in register op_rid.
 */
extern void mpm_set_on(mpm_id, mpm_reg);

/* Function:    <mpm_gt>
 * Syntax:      mpm_gt(mid)
 * Description: When used after an mpm_cmp(), this will test whether op1 to the
 *              mpm_cmp() was greater than op2.  After an arithmetic operation
 *              which sets the flags according to the result this will test
 *              whether the result of the operation was greater than zero.
 */
extern utb mpm_gt(mpm_id);

/* Function:    <mpm_lt>
 * Syntax:      mpm_lt(mid)
 * Description: When used after an mpm_cmp(), this will test whether op1 to the
 *              mpm_cmp() was less than op2.  After an arithmetic operation
 *              which sets the flags according to its result, this will test
 *              whether the result of the operation was less than zero.
 */
extern utb mpm_lt(mpm_id);

/* Function:    <mpm_ge>
 * Syntax:      mpm_ge(mid)
 * Description: When used after an mpm_cmp(), this will test whether op1 to the
 *              mpm_cmp() was greater than or equal to op2.  After an
 *              arithmetic operation which sets the flags according to its
 *              result, this will test whether the result of the operation was
 *              greater than or equal to zero.
 */
extern utb mpm_ge(mpm_id);

/* Function:    <mpm_le>
 * Syntax:      mpm_le(mid)
 * Description: When used after an mpm_cmp(), this will test whether op1 to the
 *              mpm_cmp() was less than or equal to op2.  After an arithmetic
 *              operation which sets the flags according to its result, this
 *              will test whether the result of the operation was less than or
 *              equal to zero.
 */
extern utb mpm_le(mpm_id);

/* Function:    <mpm_eq>
 * Syntax:      mpm_eq(mid)
 * Description: When used after an mpm_cmp(), this will test whether op1 to the
 *              mpm_cmp() was equal to op2.  After an arithmetic operation
 *              which sets the flags according to its result, this will test
 *              whether the result of the operation was equal to zero.
 */
extern utb mpm_eq(mpm_id);

/* Function:    <mpm_odd>
 * Syntax:      odd = mpm_odd(mid, op_rid);
 * Description: This function return whether or not the registers val is odd.
 */
extern utb mpm_odd(mpm_id, mpm_reg);

/* Function:    <mpm_sizeof>
 * Syntax:      places = mpm_sizeof(mid, op_rid);
 * Description: This function returns the size in units of mpm_prec of the
 *              value contained in the register.  The size of the internally
 *              represented value is not accessible to the user of the package.
 *              This routine can be used to predetermine the size of memory
 *              required to perform a store operation.
 * Failure:     If the number cannnot be represented in the external precision
 *              because the precision is too great to store in an mpm_prec
 *              then this function will return 0.  In this circumstance the
 *              number could be divided into parts and stored.
 */
extern mpm_prec mpm_sizeof(mpm_id, mpm_reg);

/* Function:    <mpm_sizeof_arc>
 * Syntax:      places = mpm_sizeof_arc(reg_arc);
 * Description: Operates in the same manner as mpm_sizeof(), but on register
 *              archives.
 */
extern mpm_prec mpm_sizeof_arc(mpm_arc);

/* Function:    <mpm_bitlen>
 * Syntax:      bits = mpm_bitlen(mid, op_rid);
 * Description: This function returns the most significant bit + 1 of op_rid,
 *              i.e. the smallest number bits such that 2^bits > op_rid.  The
 *              exception to this is that it returns a value of 1 if op_rid is
 *              zero.
 *              represented value is not accessible to the user of the package.
 *              This routine can be used to predetermine the size of memory
 *              required to perform a store operation.
 */
extern u32 mpm_bitlen(mpm_id, mpm_reg);

/* Function:    <mpm_bitlen_arc>
 * Syntax:      bits = mpm_bitlen_arc(reg_arc);
 * Description: This function operates in the same manner as mpm_bitlen, but on
 *              register archives.
 */
extern u32 mpm_bitlen_arc(mpm_arc);

/* Function:    <mpm_is2pow_arc>
 * Syntax:      bits = mpm_is2pow_arc(reg_arc);
 * Description: This function returns UT_TRUE if reg_arc is a nonzero power of
 *              2, i.e. +/-1, +/-2, +/-4, ..
 */
extern utb mpm_is2pow_arc(mpm_arc);

/* Function:    <mpm_isneg_arc>
 * Syntax:      negative = mpm_isneg_arc(reg_arc);
 * Description: This function returns UT_TRUE if reg_arc is negative.
 */
extern utb mpm_isneg_arc(mpm_arc);

/* Function:    <mpm_2_power>
 * Syntax:      mpm_2_power(mid, dest_rid, power_2);
 * Description: This routine loads register dest_rid in machine mid with 2 raised
 *              to the power of power_2.
 * Failure:     MPM_OVERFLOW set: Memory allocation failure.
 */
extern void mpm_2_power(mpm_id, mpm_reg, u32);

/* Function:    <mpm_abs>
 * Syntax:      mpm_abs(mid, rid);
 * Description: This routine performs the absolute funtion, i.e. |rid|.
 */
extern void mpm_abs(mpm_id, mpm_reg);

/* Function:    <mpm_neg>
 * Syntax:      mpm_neg(mid, rid);
 * Description: This routine performs a negation of the operand, i.e. -rid.
 */
extern void mpm_neg(mpm_id, mpm_reg);

/* Function:    <mpm_sizeof_arc2os>
 * Syntax:      size = mpm_sizeof_arc2os(mpm_arc);
 * Description: Returns the number of octets the supplied mpm register archive
 *              would occupy if stored as an octet string, most
 *              significant byte first. Should only be used for
 *              non-negative integers.
 * Failure:     Usually none; in debug mode, returns 0 if called with a null
 *              register pointer.
 *            Failure aborts by default.
 */
extern size_t CST32EXPORTTYPE CST16EXPORTTYPE mpm_sizeof_arc2os(mpm_arc num);

/* Function:    <mpm_arc2os>
 * Syntax:      end = mpm_arc2os(mpm_arc, dest);
 * Description: Writes mpm_arc to dest as an octet string, most significant
 *              byte first.  Returns pointer to octet after last octet
 *              written, or 0 on error (in which case dest may have had
 *              some data written to it already). Should only be used
 *              for non-negative integers.
 * Failure:     Returns 0 on internal failure (probably lack of memory); in debug
 *              mode, aborts on bad parameters.
 * Errors:      MPM_ENTRNL
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE mpm_arc2os(mpm_arc num, u8 *dest);

/* Function:    <mpm_sizeof_arc2berinteger>
 * Syntax:      size = mpm_sizeof_arc2berinteger(mpm_arc);
 * Description: Returns the number of octets the supplied mpm register archive
 *              would occupy if stored as an ASN.1 integer.
 * Failure:     Usually none; in debug mode, returns 0 if called with a null
 *              register pointer.
 *            Failure aborts by default.
 */
extern sec_off_t CST32EXPORTTYPE CST16EXPORTTYPE mpm_sizeof_arc2berinteger(mpm_arc num);

/* Function:    <mpm_arc2berinteger>
 * Syntax:      end = mpm_arc2berinteger(mpm_arc, dest);
 * Description: Writes mpm_arc to dest in ASN.1 format.  Returns pointer to octet
 *              after last octet written, or 0 on error (in which case dest may
 *              have had some data written to it already).
 * Failure:     Returns 0 on internal failure (probably lack of memory); in debug
 *              mode, aborts on bad parameters.
 * Errors:      MPM_ENTRNL
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE mpm_arc2berinteger(mpm_arc num, u8 *dest);

/* Function:    <mpm_berinteger2arc>
 * Syntax:      end = mpm_berinteger2arc(src, arc);
 * Description: Reads the ASN.1 integer stored at src, and places it in arc.
 *              Returns a pointer to the octet after the last octet read.
 * Failure:     Returns 0 on failure (memory or format problems).  Inherits
 *              failures from asn1_bertag2type(), asn1_berlen2size(),
 *              ut_new_mem(), & ut_dispose_mem().  In debug mode, aborts on bad
 *              parameters.
 * Errors:      MPM_EUNEXP,MPM_ENTRNL,UT_EA1ITP,UT_EA1ISZ,UT_ENOMEM
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE mpm_berinteger2arc(u8 *src, mpm_arc *arc);


void
mpm_doubleExpm_montgomery(mpm_id mid, mpm_reg res_rid, mpm_reg op1_rid,
  mpm_reg exp1_rid, mpm_reg op2_rid, mpm_reg exp2_rid);

void
mpm_doubleExpm(mpm_id mid, mpm_reg res_rid, mpm_reg op1_rid,
  mpm_reg exp1_rid, mpm_reg op2_rid, mpm_reg exp2_rid);


/* Function:    <mpm_fput>
 * Syntax:      mpm_fput(file, msg, mach, reg);
 * Description: Writes msg, followed by the value of register reg in machine mach
 *              (in decimal) to file.
 * Failure:     Does not trap failure.
 */
extern
void mpm_fput(FILE *, const char *, mpm_id, mpm_reg);


/* Function:    <mpm_fput_hex>
 * Syntax:      int rval = mpm_fput_hex(file, msg, mach, reg);
 * Description: Writes msg, followed by the value of register reg in machine mach
 *              (in hex) to file.
 * Failure:     Returns 1 on failure (usually internal memory failure).
 */
extern
int mpm_fput_hex(FILE *, const char *, mpm_id, mpm_reg);


/* Function:    <mpm_writeToFile_ascii>
 * Summary:     Write a register to the named file.
 * Syntax:      int rval = mpm_writeToFile_ascii(const char *fname,
 *                const char *mode, const char *fmt, const char *msg,
 *                mpm_id mid, mpm_reg rid);
 * Description: The mpm_writeToFile_ascii() function writes the number
 *              in reg rid of machine mid to the file named in fname. If
 *              msg is non-NULL, it is written to the file before the
 *              number. The string fmt determines the format: if fmt is
 *              "x", the number is printed out as ASCII hex; if fmt is
 *              "d", the number is printed out as ASCII decimal.
 *
 *              This function returns 1 on failure (couldn't open file)
 *              and 0 on success. In debug mode, it returns -2 if fname,
 *              mode, fmt, or mid is NULL.
 * Memory:      This function allocates no memory.
 */

extern int
mpm_writeToFile_ascii(const char *fname, const char *mode, const char *fmt,
  const char *msg, mpm_id mid, mpm_reg rid);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef WITH_mma
#include "monty.h"
#endif

#endif /* not _MPM_H */

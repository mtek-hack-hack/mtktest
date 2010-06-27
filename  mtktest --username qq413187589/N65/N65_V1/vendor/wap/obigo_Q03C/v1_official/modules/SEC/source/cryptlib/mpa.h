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

#ifndef _MPA_H /* prevent multiple inclusion */
#define _MPA_H

/*loko#include "limits.h"*/  /* For CHAR_BIT */
#include "ut.h"     /* For utb, u8, & u32 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MPA_EBASE (0x03000000) /* Module Code */
#define MPA_EPARAM (MPA_EBASE + 0x40000) /* Bad Parameter */
#define MPA_ENOMEM (MPA_EBASE + 0x40001) /* Out Of Memory */

#ifndef CHAR_BIT		/*loko*/
  #define CHAR_BIT			8
#endif

#ifdef CST_ARCH_64

#define MPA_LOG_BIT 6
typedef unsigned long long mpa_dig;  /* MPA digit */
#define MPA_DIG_ONE 1ULL
#define MPA_DIG_FMT "L"
#define MPA_DIG_FMT_WIDTH "016"

#else /* CST_ARCH_64 */

#define MPA_LOG_BIT 5
typedef unsigned long mpa_dig;  /* MPA digit */
#define MPA_DIG_ONE 1UL
#define MPA_DIG_FMT "l"
#define MPA_DIG_FMT_WIDTH "08"

#endif /* /CST_ARCH_64 */

#define MPA_LOG_BIT_2 (MPA_LOG_BIT - 1)

/* MPA_BIT is assumed to be even.. */
#define MPA_BIT (sizeof(mpa_dig) * CHAR_BIT)
#define MPA_BIT_2 (MPA_BIT >> 1)

#define MPA_MASK_BIT (MPA_BIT - 1)
#define MPA_MASK_BIT_2 (MPA_BIT_2 - 1)

typedef unsigned mpa_prec; /* precision of numbers */

/* Type:    <mpa_num>
 * Comment: This library deals with multiple precision numbers.  Numbers are
 *            stored in a (precision, places) pair as defined below.  Note that
 *            all numbers are unsigned.
 * Note:    This library does not contain the support routines necessary to
 *            allocate/deallocate the places for numbers; it is purely the
 *            function of the library to perform mathematics on the numbers
 *            defined below.
 */
typedef struct {
  mpa_prec  prec;     /* precision of number */
  mpa_dig  *dig; /* places of number (prec of them) */
} mpa_num;

/* Function:  <mpa_norm>
 * Syntax:    mpa_norm(num_p, prec);
 * Semantics: This operation is used to normalize numbers, given a precision
 *              from which to start the normalisation.  The normalisation of
 *              numbers ensures that the most significant place of the number
 *              will be nonzero, unless the number being represented is itself
 *              zero in which case the precision is one.
 */
extern void mpa_norm(mpa_num *, mpa_prec);

/* Function:  <mpa_cmp>
 * Semantics: The mpa_cmp routine can be used to compare two normalized
 *              mpa_number_t's.  This routine returns an int, indicating the
 *              result of the comparison as follows:
 *                0 => op1 == op2
 *               -1 => op1 < op2
 *                1 => op1 > op2
 */
extern int mpa_cmp(mpa_num *, mpa_num *);

/* Function:  <mpa_add>
 * Syntax:    carry_out = mpa_add(res_p, op1_p, op2_p);
 * Semantics: Adds the multiple precision numbers op1 and op2 to give result
 *              and carry_out.
 * Note:      To decrease execution time the following implementation decisions
 *              have been made:
 *              1. Both op1_p and op2_p should be normalized on entry.
 *              2. The additive identity (zero) is not checked in the routine
 *                   as a special case and as a result could be done by the
 *                   caller without replication of the code.
 *              3. The precondition op1_p->prec >= op2_p->prec is placed on
 *                   the input parameters.
 *              4. On entry to the routine, res_p->prec need not be defined, it
 *                   is implied to be op1_p->prec.
 *              5. res_p->prec is not altered by the routine, the normalized
 *                   precision of res_p will always be op1_p (given [1] above).
 *              6. The carry return can be handled in the following way:
 *                   if(carry) {
 *                     res_p->prec = op1_p->prec + 1;
 *                     res_p->dig[res_p->prec - 1] = 1;
 *                   } else
 *                     res_p->prec = op1_p->prec;
 * Usage:     res_p, op1_p and op2_p can be different or all the same, i.e.:
 *              carry_out = mpa_add(a_p, a_p, a_p);
 *              is valid and performs `a += a'.
 */
extern utb mpa_add(mpa_num *, mpa_num *, mpa_num *);

/* Function:  <mpa_sub>
 * Syntax:    borrow_out = mpa_sub(res_p, op1_p, op2_p);
 * Semantics: Subtracts the mulitple precision number op2 from op1 to give the
 *              result and a borrow_out - if one occurs.
 * Note:      To decrease execution time the following implementation decisions
 *              have been made:
 *              1. Both op1_p and op2_p should be normalized on entry.
 *              2. The subtractive identity (zero) is not checked in the
 *                   routine as a special case and as a result could be done by
 *                   the caller without replication of the code.
 *              3. The precondition op1_p->prec >= op2_p->prec is placed on the
 *                   input parameters.
 *              4. On entry to the routine, res_p->prec need not be defined, it
 *                   is implied to be op1_p->prec.
 *              5. res_p->prec is not altered by the routine, the normalized
 *                   precision of res_p should calculated from a starting point
 *                   of op1_p->prec.
 *              6. The borrow_out return result indicates that op1_p < op2_p
 *                   when called.  This may be an error, or a valid output as
 *                   defined by the caller.
 * Usage:     res_p, op1_p and op2_p can be different or all the same, i.e.:
 *              carry_out = mpa_sub(a_p, a_p, b_p);
 *              is valid and performs `a -= b'.
 */
extern utb mpa_sub(mpa_num *res_p, mpa_num *op1_p, mpa_num *op2_p);

/* Function:  <mpa_mul>
 * Syntax:    mpa_mul(res_p, op1_p, op2_p);
 * Semantics: Multiplication of the multiple precision number op2 by op1 to
 *              give the result.
 * Note:      To decrease execution time the following implementation decisions
 *              have been made:
 *              1. Both op1_p and op2_p should be normalized on entry.
 *              2. res_p->prec need not be defined on entry to the routine but
 *                   should be capable of storing op1_p->prec + op2_p->prec
 *                   places.
 *              3. On exit, res_p->prec is unaltered, but should be set to the
 *                 normalized value which is calculated from
 *                 op1_p->prec + op2_p->prec.
 */
extern void mpa_mul(mpa_num *, mpa_num *, mpa_num *);

/* Function:  <mpa_div>
 * Syntax:    success = mpa_div(quot_p, rem_p, numer_p, denom_p);
 * Semantics: Divides the multiple precision numerator by the mulitple
 *              precision denominator to give the quotient and remainder.  If
 *              the quo_p == 0 then the quotient is discarded
 *              as it is calculated.  By this means this routine also provides
 *              a modulus operation.
 * Note:      To decrease execution time the following implementation decisions
 *              have been made:
 *              1. Both numer_p and denom_p must be normalized on entry.
 *              2. Divide by zero should be caught BEFORE this routine is
 *                   called.
 *              3. numer_p->prec >= denom_p->prec.
 *              4. Special cases numer_p > denom_p and denom_p == 1 should be
 *                   processed before being calling this routine.
 *              5. rem_p->prec need not be setup before being called, it is
 *                   implied that it will be less than denom_p->prec.
 *              6. quo_p->prec (if it is not 0) need not be
 *                   setup before being called, it is implied that it will be
 *                   less than numer_p->prec - denom_p->prec + 1.
 *              7. Both quot_p and rem_p should be normalized after the call as
 *                   neither of there precisions are altered by the routine
 * Return:    To implement multiple precision division some intermediate
 *              storage is required.  If the return is UT_FALSE then not
 *              enough storage was available and the routine exits altering
 *              NONE of its input parameters.
 */
extern utb mpa_div(mpa_num *, mpa_num *, mpa_num *, mpa_num *);

#define MPA_MOD(rem_p, numer_p, denom_p) mpa_div(0, rem_p, numer_p, denom_p)

/* Function:  <mpa_shiftl>
 * Syntax:    carry_out = mpa_shiftl(dest_p, src_p, shift);
 * Semantics: This procedure carries out a barrel shift operation.  The
 *              multiple precision number in number_p is shifted by shift bits
 *              to the left.  The bits shifted out are placed in carry_out.
 * Note:      To decrease execution time the following implementation decisions
 *              have been made:
 *              1. The precision of the destination is implied to be the same
 *                   as that of the source.
 *              2. The actual shift performed is shift % (bits per place).
 */
extern mpa_dig mpa_shiftl(mpa_num *, mpa_num *, u8);

/* Function:  <mpa_shiftr>
 * Syntax:    carry_out = mpa_shiftr(dest_p, src_p, shift);
 * Semantics: This procedure carries out a barrel shift operation.  The
 *              multiple precision number in src_p is shifted by shift
 *              bits to the right.  The bits shifted out are placed in
 *              carry_out.
 * Note:      To decrease execution time the following implementation decisions
 *              have been made:
 *              1. The precision of the destination is implied to be the same
 *                   as that of the source
 *              2. The actual shift performed is shift % (bits per place).
 */
extern mpa_dig mpa_shiftr(mpa_num *, mpa_num *, u8);

/* Function:  <mpa_sqrt>
 * Syntax:    success = mpa_sqrt(root_p, rem_p, src_p);
 * Semantics: This procedure carries out a square root operation.  The
 *              square root of the multiple precision number in src_p is placed
 *              in dest_p, while the remainder (src_p - root_p * root_p) is
 *              placed in rem_p _if_ rem_p is non-0.  The routine returns -1
 *              if it runs out of memory, 0 if rem_p = 0 and 1 otherwise
 *              (success, but rem_p != 0).
 * Note:      To decrease execution time the following implementation decisions
 *              were made:
 *                1. root_p->prec >= ((src_p->prec + 1) >> 1)
 *                2. rem_p->prec > root_p->prec
 */
extern int mpa_sqrt(mpa_num *, mpa_num *, mpa_num *);

/* Function:  <mpa_smod>
 * Syntax:    remainder = mpa_smod(op_p, modulus, half, whole);
 * Semantics: This function returns the remainder of op_p on division by
 *              modulus.  It operates very quickly, but only on numbers in the
 *              range 0 < modulus < 40504.  half should be set to (1 <<
 *              (CHAR_BIT * sizeof(mpa_dig) / 2) % modulus, and whole
 *              should be set to (half * half) % modulus.  This is to allow
 *              these values to be supplied from a precalculated table.  The
 *              routine is designed for use in primality tests.
 */
extern unsigned mpa_smod(mpa_num *, unsigned, unsigned, unsigned);

/* Function:  <mpa_gcd>
 * Syntax:    mpa_gcd(op1_p, op2_p);
 * Semantics: Computes GCD of op1 and op2, storing result in op1; corrupts op2
 *              in the process. Returns 0 on success, -1 on failure.
 */
extern int mpa_gcd(mpa_num *, mpa_num *);

/* Length in bits of an mpa_num */
u32 mpa_bitlen(mpa_num *num_p);

/* returns the bit in num_p in position pos. Offset of pos starts from zero. If
 * pos is greater than the bitlength of num_p returns 0. */
int
mpa_bitInPosition (mpa_num *num_p, u32 pos);

/* shift left and right by more than one mpa_dig */
mpa_num mpa_bigshiftl(mpa_num *src_p, u32 shift);
mpa_num mpa_bigshiftr(mpa_num *src_p, u32 shift);

/* copy to an mpa_num of the same or greater prec */
void mpa_copy(mpa_num *src_p, mpa_num *dest_p);

/* new mpa_num - deallocate memory with mpa_destroy.
 * mpa_new allocates prec mpa_digs
 * mpa_newbits allocates enough mpa_digs to contain prec bits.
 */
mpa_num mpa_new(size_t prec);
mpa_num mpa_newbits(size_t prec);
void mpa_destroy (mpa_num *victim);

/* new mpa_num with all digits zeroed */
mpa_num mpa_new0(size_t prec);
mpa_num mpa_newbits0(size_t prec);

/* xor two mpa_nums with the same precision */
utb mpa_xor(mpa_num *op1_p, mpa_num *op2_p, mpa_num *dest_p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _MPA_H */

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

#ifndef __MMA_H
#define __MMA_H

#include "mpa.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function: mma_nrm()
 *
 * Description:
 *
 * Computes: result = precision (operand)
 *
 * Eliminates zero high-words.
 *
 * Parameters:
 *   a - The operand
 *   an - >= The operand precision
 *
 * Returns:
 *   The operand precision.
 *
 * Memory:
 *   n/a
 */
extern mpa_prec
mma_nrm
(mpa_dig *a, const mpa_prec an);

/* Function: mma_len()
 *
 * Description:
 *
 * Computes: result = bitlength (operand)
 *
 * Count bits set in high word.
 *
 * Parameters:
 *   a - The operand
 *   an - >= The operand precision
 *
 * Returns:
 *   The operand precision.
 *
 * Memory:
 *   n/a
 *
 * Notes:
 *   length(0) == 1
 *   length(1) == 2
 *   length(2) == 3
 *   length(4) == 4
 */
extern u32
mma_len
(mpa_dig *a, const mpa_prec an);

/* Function: mma_tst()
 *
 * Description:
 *
 * Computes: result = bitset (operand, bit)
 *
 * Test bit set in appropriate word.
 *
 * Parameters:
 *   a - The operand
 *   an - The operand precision
 *   bit - The bit to test
 *
 * Returns:
 *   Whether the bit is set (1).
 *
 * Memory:
 *   n/a
 */
extern utb
mma_tst
(mpa_dig *a, const mpa_prec an, const u32 bit);

/* Function: mma_shl()
 *
 * Description:
 *
 * Computes: result = operand << shift
 *
 * Performs an arbitrary (non-negative) left shift.
 *
 * Parameters:
 *   r - The result is stored here
 *   a - The operand
 *   an - The operand precision
 *   shift - The number of bits by which to shift
 *
 * Returns:
 *   The result precision.
 *
 * Memory:
 *   |r| >= a + (shift + W - 1 >> w) || W = bits/dig, w = log (W)
 */
extern mpa_prec
mma_shl
(mpa_dig *d, mpa_dig *a, const mpa_prec an, const u32 s);

/* Function: mma_shr()
 *
 * Description:
 *
 * Computes: result = operand >> shift
 *
 * Performs an arbitrary (non-negative) right shift.
 *
 * Parameters:
 *   r - The result is stored here
 *   a - The operand
 *   an - The operand precision
 *   shift - The number of bits by which to shift
 *
 * Returns:
 *   The result precision.
 *
 * Memory:
 *   |r| >= MAX (1, a - (shift >> w)) || W = bits/dig, w = log (W)
 */
extern mpa_prec
mma_shr
(mpa_dig *d, mpa_dig *a, const mpa_prec an, const u32 s);

/* Function: mma_cmp()
 *
 * Description:
 *
 * Computes: result = CMP (operand1, operand2)
 *
 * Compares two multiprecision numbers.
 *
 * Parameters:
 *   a - The first operand
 *   an - The first operand precision
 *   b - The second operand
 *   bn - The second operand precision
 *
 * Returns:
 *   0 if a == b, 1 if a > b, -1 if a < b
 *
 * Memory:
 *   n/a
 */
extern int
mma_cmp
(mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn);

/* Function: mma_add()
 *
 * Description:
 *
 * Computes: result = operand1 + operand2
 *
 * Classical multiprecision addition.
 *
 * Parameters:
 *   d - The result is stored here
 *   a - The first operand
 *   an - The first operand precision
 *   b - The second operand
 *   bn - The second operand precision
 *
 * Returns:
 *   The result precision.
 *
 * Memory:
 *   |d| >= 1 + MAX(an, bn)
 */
extern mpa_prec
mma_add
(mpa_dig *d, mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn);

/* Function: mma_sub()
 *
 * Description:
 *
 * Computes: result = operand1 - operand2
 *
 * Classical multiprecision subtraction
 *
 * Parameters:
 *   d - The result is stored here
 *   a - The first operand
 *   an - The first operand precision
 *   b - The second operand
 *   bn - The second operand precision
 *
 * Returns:
 *   The result precision, 0 if a < b.
 *
 * Memory:
 *   |d| >= an
 *
 * Preconditions:
 *   a >= b : unsigned subtraction, not defined if a < b
 */
extern mpa_prec
mma_sub
(mpa_dig *d, mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn);

/* TODO: smul */

/* Function: mma_mul()
 *
 * Description:
 *
 * Computes: result = operand1 * operand2
 *
 * Classical multiprecision multiplication.
 *
 * Parameters:
 *   d - The result is stored here
 *   a - The first operand
 *   an - The first operand precision
 *   b - The second operand
 *   bn - The second operand precision
 *
 * Returns:
 *   The result precision.
 *
 * Memory:
 *   |d| >= an + bn
 */
extern mpa_prec
mma_mul
(mpa_dig *d, mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn);

/* Function: mma_sdiv()
 *
 * Description:
 *
 * Computes: quotient = numerator / denominator
 *           remainder = numerator % denominator
 *
 * Classical multiprecision/short-division.
 *
 * Parameters:
 *   q - The quotient is stored here
 *   r - The remainder is stored here, or NULL
 *   a - The numerator
 *   an - The numerator precision
 *   bd - The denominator
 *
 * Returns:
 *   The quotient precision.
 *
 * Memory:
 *   |q| >= an
 *   |r| >= 1
 *
 * Notes:
 *   bd != 0
 */
extern mpa_prec
mma_sdiv
(mpa_dig *q, mpa_dig *r, mpa_dig *a, const mpa_prec an, const mpa_dig bd);

/* Function: mma_smod()
 *
 * Description:
 *
 * Computes: remainder = numerator % denominator
 *
 * Classical multiprecision/short-modulus.
 *
 * Parameters:
 *   a - The numerator
 *   an - The numerator precision
 *   bd - The denominator
 *
 * Returns:
 *   The modulus.
 *
 * Memory:
 *   n/a
 *
 * Notes:
 *   bd != 0
 */
extern mpa_dig
mma_smod
(mpa_dig *a, const mpa_prec an, const mpa_dig bd);

/* Function: mma_div()
 *
 * Description:
 *
 * Computes: quotient = numerator / denominator
 *           remainder = numerator % denominator
 *
 * Classical long-division.
 *
 * Parameters:
 *   q - The quotient is stored here
 *   r - The remainder is stored here, or NULL
 *   rn - The remainder precision is stored here
 *   a - The numerator
 *   an - The numerator precision
 *   b - The denominator
 *   bn - The denominator precision
 *   na - Temporary storage
 *   nb - Temporary storage
 *
 * Returns:
 *   The quotient precision or 0 on /0.
 *
 * Memory:
 *   |q| >= 1 + MAX (0, an - bn)
 *   |r| >= bn
 *   |na| >= 1 + an
 *   |nb| >= 1 + bn
 */
extern mpa_prec
mma_div
(mpa_dig *q, mpa_dig *r, mpa_prec *rn, mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn, mpa_dig *na, mpa_dig *nb);

/* Function: mma_mod()
 *
 * Description:
 *
 * Computes: modulus = numerator % denominator
 *
 * Classical long-division.
 *
 * Parameters:
 *   r - The modulus is stored here
 *   a - The numerator
 *   an - The numerator precision
 *   b - The denominator
 *   bn - The denominator precision
 *   na - Temporary storage
 *   nb - Temporary storage
 *
 * Returns:
 *   The modulus precision or 0 on /0.
 *
 * Memory:
 *   |r| >= bn
 *   |na| >= 1 + an
 *   |nb| >= 1 + bn
 */
extern mpa_prec
mma_mod
(mpa_dig *r, mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn, mpa_dig *na, mpa_dig *nb);

/* Function: mma_sqr()
 *
 * Description:
 *
 * Computes: root = operand ^ 1/2
 *           remainder = operand - root * root
 *
 * Classical bit-at-a-time root.
 *
 * Parameters:
 *   q - The root is stored here
 *   r - The remainder is stored here
 *   rn - The remainder precision is stored here
 *   a - The operand
 *   an - The operand precision
 *   na - Temporary storage
 *
 * Returns:
 *   The root precision.
 *
 * Memory:
 *   |q| >= (1 + an) / 2
 *   |r| >= an
 *   |na| >= 1 + an
 */
extern mpa_prec
mma_sqr
(mpa_dig *d, mpa_dig *r, mpa_prec *rm, mpa_dig *a, const mpa_prec an, mpa_dig *na);

/* Function: mma_n0p()
 *
 * Description:
 *
 * Computes: n0p = -modulus ^ -1 % WORD_SIZE
 *
 * Classical montgomery inverse.
 *
 * Parameters:
 *   n0 - The first word of the modulus
 *
 * Returns:
 *   The montgomery inverse.
 *
 * Memory:
 *   n/a
 */
extern mpa_dig
mma_n0p
(const mpa_dig n0);

/* Function: mma_red()
 *
 * Description:
 *
 * Computes: result = REDC (operand, modulus)
 *
 * Classical montgomery reduction algorithm.
 *
 * Parameters:
 *   r - The result is stored here
 *   a - The operand
 *   an - The operand precision
 *   n - The modulus
 *   nn - The modulus precision
 *   n0p - The montgomery modulus inverse
 *   t - Temporary storage
 *
 * Returns:
 *   The result precision.
 *
 * Memory:
 *   |r| >= 1 + nn
 *   |t| >= 1 + 2 * nn
 */
extern mpa_prec
mma_red
(mpa_dig *d, mpa_dig *a, const mpa_prec an, mpa_dig *n, const mpa_prec nn, const mpa_dig n0p, mpa_dig *t);

/* Function: mma_rdm()
 *
 * Description:
 *
 * Computes: result = REDC (multiplicand * multiplier, modulus)
 *
 * Classical montgomery multiplication-reduction algorithm.
 *
 * Parameters:
 *   r - The result is stored here
 *   a - The multiplicand
 *   an - The multiplicand precision
 *   b - The multiplier
 *   bn - The multiplier precision
 *   n - The modulus
 *   nn - The modulus precision
 *   n0p - The montgomery modulus inverse
 *   t - Temporary storage
 *
 * Returns:
 *   The result precision.
 *
 * Memory:
 *   |a| >= nn        [NB]
 *   |b| >= nn        [NB]
 *   |r| >= 1 + nn
 *   |t| >= 1 + 2 * nn
 */
extern mpa_prec
mma_rdm
(mpa_dig *d, mpa_dig *a, const mpa_prec an, mpa_dig *b, const mpa_prec bn, mpa_dig *n, const mpa_prec nn, const mpa_dig n0p, mpa_dig *t);

/* exponentiation */

extern u32
mma_exw
(u32 *pos, mpa_dig *dig);

#ifdef __cplusplus
}
#endif

#endif /* __MMA_H */

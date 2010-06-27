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

#ifndef _UTMPM_H /* Prevent multiple inclusion */
#define _UTMPM_H

#include "mpm.h"   /* For mpm_id & mpm_reg */
#include "ut.h"    /* For utb, u16, & u32 */
#include "prng.h"  /* For prng_inst */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Component: euclid
 * Purpose:   Prototype for modulo-multiplicative inverse function.
 */

/* Function:    <utmpm_invm>
 * Syntax:      success = utmpm_invm(mid, res_rid, op_rid);
 * Description: This routine uses the extended Euclidean algorithm to calculate
 *              the multiplicative inverse modulo MPM_RMOD (the implied
 *              operand).  Returns success.
 * Failure:     This routine can fail (return UT_FALSE) on two acounts:
 *              1. Bad values for the algorithm - op_rid and MPM_RMOD should be
 *                   relatively prime.
 *              2. Memory allocation failure.  This allocation failure may have
 *                   occurred on an internal data entity or on machine mid.  If
 *                   an error is reported then mid should be checked for an
 *                   MPM_OVERFLOW condition and treated accordingly.
 */
extern utb utmpm_invm(mpm_id, mpm_reg, mpm_reg);

/* Component: mppt
 * Purpose: Function prototypes for the MPM primality testing utilities.
 */

/* High-level function calls */

/* Function:    <utmpm_checkPrime>
 * Summary:     Check the given big number for primality.
 * Syntax:      int rval = utmpm_checkPrime(mpm_id mid,
 *                mpm_reg reg, prng_inst *prng, long stst);
 * Description: The utmpm_checkPrime() function checks register reg
 *              of machine mid to see if it is prime. It is tested, in turn,
 *              by trial division and Fermat's test. If it passes these,
 *              it is tested by running the Miller-Rabin test stst
 *              times. If it passes this, it is considered prime.
 *
 *              The Miller-Rabin test uses the random number generator prng;
 *              if no random number generator is supplied, the function
 *              creates an r48 random number generator internally and
 *              uses that.
 *
 *              If stst is not supplied, the function runs the number of
 *              tests given by utmpm_len_numberOfRWTests().
 * 
 *              This function returns 0 on success (number is a prime),
 *              1 on failure (number is not a prime), and -1 on an
 *              internal error.
 * Memory:      This function allocates no memory.
 */
int
utmpm_checkPrime(mpm_id mid, mpm_reg reg, prng_inst *prng, long stst);


/* Function:    <utmpm_arc_checkPrime>
 * Summary:     Check the given mpm_arc for primality.
 * Syntax:      int rval = utmpm_arc_checkPrime(mpm_arc num, 
 *                prng_inst *prng, long stst);
 * Description: The utmpm_arc_checkPrime() function checks the number num
 *              to see if it is prime. It is tested, in turn, by trial
 *              division and Fermat's test. If it passes these, it is
 *              tested by running the Miller-Rabin test stst times. If
 *              it passes this, it is considered prime.
 *
 *              The Miller-Rabin test uses the random number generator prng;
 *              if no random number generator is supplied, the function
 *              creates an r48 random number generator internally and
 *              uses that.
 *
 *              If stst is not supplied, the function runs the number of
 *              tests given by utmpm_len_numberOfRWTests().
 * 
 *              This function returns 0 on success (number is a prime),
 *              1 on failure (number is not a prime), and -1 on an
 *              internal error.
 * Memory:      This function allocates no memory.
 */
int
utmpm_arc_checkPrime(mpm_arc num, prng_inst *prng, long stst);


/* Function:    <utmpm_make_prime>
 * Summary:     Make a prime of the requested length.
 * Syntax:      mpm_arc rval = utmpm_make_prime(mpm_id machine,
 *                prng_inst *prng, u32 q_length);
 * Description: The utmpm_make_prime() function makes a prime of the
 *              desired length. It returns 0 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              mpm_kill_arc (rval);
 *           (/code)
 */
extern
mpm_arc 
utmpm_make_prime(mpm_id machine, prng_inst *prng, u32 q_length);

/* low-level functions */

/* Identifier for probprime generators */
typedef void *utmpm_ippg;

/* Function:    <utmpm_div_test>
 * Syntax:      prime = utmpm_div_test(mid, rid, num_primes)
 * Description: This routine performs a prime division test on the first
 *              num_primes primes, returning the result of this test as either
 *              the contents of a register being prime or not.
 * Usage:     rid should not be MPA_RMOD.
 * Failure:     A memory allocation failure may occur, in which case the
 *              MPM_OVERFLOW flag on mid will be set.  Note however that all
 *              the registers in the machine will remain intact.
 */
extern utb utmpm_div_test(mpm_id, mpm_reg, u16);

/* Function:    <utmpm_fermat_test>
 * Syntax:      prime = utmpm_fermat_test(mid, rid, num_primes)
 * Description: This routine performs Fermat's test on the contents of the
 *              register, returning its psuedo-primality as the result.
 * Failure:     A memory allocation failure may occur, in which case the
 *              MPM_OVERFLOW flag on mid will be set.  Note however that all
 *              the registers in the machine will remain intact.
 */
extern utb utmpm_fermat_test(mpm_id, mpm_reg);

/* Function:    <utmpm_strong_test>
 * Syntax:      prime = utmpm_strong_test(mid, rid, num_iter, rand_gen)
 * Description: This routine performs Knuth's Algorithm P strong primality test
 *              the required number of times (num_iter).  Returns whether or
 *              not it passed.
 * Usage:     This routine requires a random number generator (as defined by
 *              the rng component) for the purposes of the tests.  The
 *              properties of the number generator are that it should be
 *              created to handle numbers of the same magnitude as the number
 *              which are being tested.
 */
extern utb utmpm_strong_test(mpm_id, mpm_reg, u16, prng_inst *);


/* Function:    <utmpm_len_numberOfMRTests>
 * Summary:     Gives number of Miller-Rabin tests to run.
 * Syntax:      u16 rval = utmpm_len_numberOfMRTests(u32 bitlen);
 * Memory:      This function allocates no memory.
 * Description: The utmpm_len_numberOfMRTests() function takes a length
 *              in bits bitlen. This is the length of a number which we
 *              wish to test for primality with a probability of no more
 *              than 1 in 2^80 of incorrectly identifying a composite as
 *              prime. The function returns the number of Miller-Rabin
 *              tests to run on the number in order to have this level
 *              of confidence. This number is obtained from Menezes, van
 *              Oorschot and Vanstone's Handbook of Applied
 *              Cryptography, second edition, section 4.49.
 */
u16
utmpm_len_numberOfMRTests(u32 bitlen);

/* Function:    <utmpm_mach_numberOfMRTests>
 * Summary:     Gives number of Miller-Rabin tests to run on a register.
 * Syntax:      u16 rval = utmpm_mach_numberOfMRTests(mpm_id mid, mpm_reg reg);
 * Description: The utmpm_len_numberOfMRTests() function takes a number
 *              stored in register reg of the mpm machine mid. We wish
 * Memory:      This function allocates no memory.
 *              to test this number for primality with a probability of
 *              no more than 1 in 2^80 of incorrectly identifying a
 *              composite as prime. The function returns the number of
 *              Miller-Rabin tests to run on the number in order to have
 *              this level of confidence. This number is obtained from
 *              Menezes, van Oorschot and Vanstone's Handbook of Applied
 *              Cryptography, second edition, section 4.49.
 */
u16
utmpm_mach_numberOfMRTests(mpm_id mid, mpm_reg reg);

/* Function:    <utmpm_arc_numberOfMRTests>
 * Summary:     Gives number of Miller-Rabin tests to run on an mpm_arc.
 * Syntax:      u16 rval = utmpm_arc_numberOfMRTests(mpm_arc arc);
 * Description: The utmpm_arc_numberOfMRTests() function takes a number
 *              stored in the mpm_arc arc. We wish to test this number
 *              for primality with a probability of no more than 1 in
 *              2^80 of incorrectly identifying a composite as prime.
 *              The function returns the number of Miller-Rabin tests to
 *              run on the number in order to have this level of
 *              confidence. This number is obtained from Menezes, van
 *              Oorschot and Vanstone's Handbook of Applied
 *              Cryptography, second edition, section 4.49.
 * Memory:      This function allocates no memory.
 */
u16
utmpm_arc_numberOfMRTests(mpm_arc arc);

/* Function:    <utmpm_new_ippg>
 * Syntax:      ippgid = utmpm_new_ippg(prng, mach, lo, hi, div, exp, mode);
 * Description: Returns the identifier for an incremental probable prime number
 *              generator which will generate probable primes p in the range
 *              lo < p < hi such that div divides p - 1 and gcd(p - 1, exp) = 1
 *              - if mode is 1, no strong tests are applied to the numbers
 *              generated, only small prime division, so the numbers aren't
 *              very likely to be prime, but will have no small divisors (if
 *              mode is 0, strong tests are applied).  If mode is 2, the gcd
 *              and divisor properties are _not_ tested; primes found will be
 *              congruent to 3 mod 4 (this is primarily for the BBS prng).
 *              Pseudorandom number generator prng is used, and all values are
 *              taken from machine mach.
 * Notes:       div must be ODD.
 * Failure:     If numerical or memory-related problems occur, 0 will be
 *              returned.
 */
extern utmpm_ippg utmpm_new_ippg(prng_inst *, mpm_id, mpm_reg, mpm_reg, mpm_reg,
                                 mpm_reg, int);

/* Function:    <utmpm_dispose_ippg>
 * Syntax:      utmpm_dispose_ippg(ippg);
 * Description: Tidies up and frees the indicated incremental probable prime
 *            generator.  Will not fail if given a valid argument.
 */
extern void utmpm_dispose_ippg(utmpm_ippg);

/* Function:    <utmpm_next_ipp>
 * Syntax:      success = utmpm_next_ipp(ippg, mach, reg);
 * Description: Loads register reg in machine mach with a new prime from the
 *              range indicated when creating ippg.  Only one prime should be
 *              used from each ippg, but if the first one generated doesn't
 *              satisfy further constraints, then it may be discarded and a new
 *              one requested; after an acceptable prime has been found, the
 *              generator should be disposed.
 * Failure:     Returns UT_FALSE after failure; this could be a result of
 *              either numerical or memory problems or the exhaustion of the
 *              range, i.e. the entire range for ippg has been searched and no
 *              primes were found.  If the routine fails, the generator should
 *              be disposed.  On success, returns BOOLT_TRUE.  During normal
 *              operation, failure will always be due to exhaustion of the
 *              range; memory and numerical problems are uncommon.
 */
extern utb utmpm_next_ipp(utmpm_ippg, mpm_id, mpm_reg);

/* Function:    <utmpm_ipp>
 * Syntax:      success = utmpm_ipp(prng, mach, prime, lo, hi, div, exp, mode);
 * Description: prng, mach, lo, hi, div, exp and onlydiv are supplied as
 *              arguments to utmpm_new_ippg(); this function will then call
 *              utmpm_next_ipp() to place a suitable probable prime in register
 *              prime in mach.  Finally, the function will dispose of the ippg.
 * Notes:       div must be ODD.
 * Failure:     Return value is 0 for failure of utmpm_new_ippg(), 1 for failure
 *              of utmpm_next_ipp() and 2 for success.  A return of 1 will
 *              usually indicate the absence of any primes in the indicated
 *              range.
 */
extern int utmpm_ipp(prng_inst *, mpm_id, mpm_reg, mpm_reg, mpm_reg, mpm_reg,
                     mpm_reg, int);


/* Function:    <utmpm_make_dl_params>
 * Summary:     Generate primes for use as parameters in discrete log
 *              algorithms.
 * Syntax:      int rval = utmpm_make_dl_params(int p_length, int q_length,
 *                prng_inst *prng, mpm_id machine, mpm_arc *outp,
 *                mpm_arc *outq, mpm_arc *outg, mpm_arc *outj);
 * Description: The utmpm_make_dl_params() function uses prng to
 *              generate a prime p of length p_length such that (p-1) has a
 *              prime factor q of length q_length. It then generates a
 *              base g such that g^((p-1)/q) mod p is not 1; in other
 *              words, such that the multiplicative order of g mod p is
 *              an integer multiple of q. The numbers p, q and g are
 *              returned in outp, outq and outg respectively. If outj is
 *              nonzero on input, the function calculates j s.t. p = jq + 1
 *              and puts the result in outj. If q_length is 0, the
 *              function simply calculates a large prime.
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode, returns -2 on bad parameters (NULL for any
 *              parameter except outj, q_length and outq; or q_length > 
 *              p_length; or qlength given and outq NULL).
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              mpm_kill_arc(outp);
 *              mpm_kill_arc(outq);
 *              mpm_kill_arc(outg);
 *              mpm_kill_arc(outj);
 *           (/code)
 * Example:     The following code gives an example of the use of this
 *              function.
 */

extern
int
utmpm_make_dl_params(int p_length, int q_length, prng_inst *prng,
    mpm_id machine, mpm_arc *outp, mpm_arc *outq, mpm_arc *outg,
    mpm_arc *outj);


/* Function:    <utmpm_generate_dl_keys>
 * Summary:     Generate keys for discrete log based algorithms.
 * Syntax:      int rval = utmpm_generate_dl_keys(prng_inst *prng, mpm_id
 *                machine, FILE *fdb, mpm_arc p, mpm_arc q, mpm_arc g, mpm_arc
 *                *priv, mpm_arc *pub);
 * Description: The utmpm_generate_dl_keys() function uses prng to
 *              generate a private key priv and a public key pub such
 *              that:
 *              - priv is between 2 and q-2, if q is not NULL, or
 *                between 2 and p-2 if q is NULL;
 *              - pub is g^(priv) mod p.
 *
 *              The calculations are done inside the workspace provided
 *              by machine. If fdb is non-NULL, it is taken as a pointer
 *              to a footprint database which is used to prevent
 *              generation of duplicate keys.
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode, returns -2 if any of the inputs except q and
 *              fdb are zero.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              mpm_kill_arc(priv);
 *              mpm_kill_arc(pub);
 *           (/code)
 */

extern
int
CST32EXPORTTYPE CST16EXPORTTYPE
utmpm_generate_dl_keys(prng_inst *prng, mpm_id machine, FILE *fdb, mpm_arc p,
    mpm_arc q, mpm_arc g, mpm_arc *priv, mpm_arc *pub);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _UTMPM_H */

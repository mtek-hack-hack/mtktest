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


#ifndef _SECSHARE_H
#define _SECSHARE_H

#include "cstlib.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Description: Most of this infrastructure is unused in CST v7.3; it's provided 
 * to make future expansion easier.
 */

/* Errors */

#define SECSHARE_EBASE (0x00c00000)     /* Module code */

/* Type:        <secshare_share>
 * Summary:     One block of output from a secret sharing operation
 * Description: The secshare_share structure contains two fields:
 *              - priv is the private data returned from a
 *                secshare_share_ALG operation. This data should never be
 *                transmitted in the clear or shared with anyone other
 *                than the owner.
 *              - pub is additional data associated with the owner of 
 *                the private data. This data can be made public (in
 *                many cases, it will simply be an integer).
 *
 *              Both blocks of data must be input into a secret joining
 *              operation for the secret to be reconstructed correctly.
 */
typedef struct secshare_share_s {
  ut_mblk  priv;
  ut_mblk  pub;
} secshare_share;

/* Type:        <secshare_algn>
 * Summary:     Canonical algorithm numbers
 * Description: The secshare_algn enum contains the canonical algorithm 
 *              numbers for use in the secshare_alg structure.
 */
typedef enum {
  SECSHARE_NONE,
  SECSHARE_SHAMIR,
  SECSHARE_MAX
} secshare_algn;

/* Type:        <secshare_gen_params>
 * Summary:     Union of parameters for secshare sharing algorithms
 * Description: The secshare_gen_params structure is a union of the parameter
 *              structures required by every secshare_share_ALG function.
 *              It is provided for future expansion and is not used in
 *              any currently supported share functions.
 * Notes:       All share() functions that require generation
 *              parameters will encode them in the output params
 *              ut_mblk, if necessary.
 */
typedef union secshare_gen_params_u {
  int dummy;
} secshare_gen_params;

/* Type:        <secshare_alg>
 * Summary:     Function pointers for secshare create functions
 * Description: The fields in this structure are as follows:
 *              name: a null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a secshare_alg from the secshares[] array.
 *              number: one of the canonical secshare_algn numbers given
 *                above.
 *              derive: the secshare_share_ALG function for the given ALG.
 *              join: the secshare_join_ALG function for the given ALG.
 */

typedef struct secshare_alg_s {
  const char     *name;
  secshare_algn   number;
  int           (*share)(ut_mblk *, int, int, secshare_gen_params *,
                    prng_inst *, secshare_share **, ut_mblk *);
  int           (*join)(secshare_share *, ut_mblk *, ut_mblk *);
} secshare_alg;



/* Function:    <secshare_dispose_share>
 * Summary:     Disposes of data in a secshare_share.
 * Syntax:      secshare_dispose_share(secshare_share *shr);
 * Description: The secshare_dispose_share() function disposes of the
 *              data in a secshare_share. 
 * Memory:      This function allocates no memory.
 * Notes:       The code for this function is simply:
 *            (code)
 *              if (shr->priv.data) {
 *                ut_dispose_mem(shr->priv.data);
 *                shr->priv.data = 0;
 *              }
 *              if (shr->pub.data) {
 *                ut_dispose_mem(shr->pub.data);
 *                shr->pub.data = 0;
 *              }
 *            (/code)
 */
extern
void 
secshare_dispose_share(secshare_share *shr);


/* Function:    <secshare_dispose_share_f>
 * Summary:     Disposes of an entire secshare_share.
 * Syntax:      secshare_dispose_share_f(secshare_share *shr);
 * Description: The secshare_dispose_share_f() function disposes of the
 *              data in a secshare_share and then disposes of the
 *              secshare_share itself.
 * Memory:      This function allocates no memory.
 * Notes:       The code for this function is simply:
 *            (code)
 *              if (shr->priv.data) {
 *                ut_dispose_mem(shr->priv.data);
 *                shr->priv.data = 0;
 *              }
 *              if (shr->pub.data) {
 *                ut_dispose_mem(shr->pub.data);
 *                shr->pub.data = 0;
 *              }
 *              ut_dispose_mem(shr);
 *            (/code)
 */
extern
void 
secshare_dispose_share_f(secshare_share *shr);


/* Data:        <secshares>
 * Summary:     Array of supported secshare algorithms
 * Description: The secshare array contains a pointer to the secshare_alg 
 *              structure corresponding to each of the supported secshare
 *              algorithms (currently only secshare_shamir). A specific
 *              secshare algorithm structure can be obtained from secshare
 *              using ut_choose().
 */
extern const secshare_alg *secshares[];


/*
 * Algorithm-specific declarations
 */

/*   The secret sharing scheme here is derived from the one devised by
 *   Adi Shamir and presented in "Communications of the ACM" v.24 n.11,
 *   Nov 1979, pp 612-613. The actual implementation is as described in
 *   Section 23.2 of "Applied Cryptography" by Bruce Schneier. The
 *   method works on Legendre polynomials of the form:
 *
 *      f(x) = a_m-1.x^m-1 + ... + a_1.x + M
 *
 *   where x = 1..n and all ops are over GF(p) for some prime p.
 *
 *   M is the secret to be protected and a..a_n-1 are randomly chosen
 *   coefficients.
 *
 *   It is clear that we can form a system of linear
 *   equations in m unknowns (with coefficients in GF(p)):
 *
 *     a_m-1.(x_i)^m-1 + ... + a_1.x_i + M = f(x_i)
 *
 *   where f(x_i) and x_i are known.
 *
 *   It is also clear we need m such x_i, f(x_i) pairs to recover the
 *   coefficients and hence M, the secret. We use LU decomposition to
 *   optimize the potentially costly solution step.
 */
  
/* Function:    <secshare_share_shamir>
 * Summary:     Split secret into m-of-n shares using Shamir's method.
 * Syntax:      int rval = secshare_share_shamir(ut_mblk *in, int m, int n, 
 *                secshare_gen_params *dum, prng_inst *prng,
 *                secshare_share **shares, ut_mblk *params);
 * Description: The secshare_share_shamir() function uses Shamir's 
 *              secret sharing method to make n shares out of in
 *              where m are required to recover in. dum can
 *              be null. On success, shares will contain the shares
 *              requested, and params will contain an ASN1_SEQUENCE of
 *              two DER-encoded ASN1_INTEGERs, which are m and the prime
 *              over which operations occur. This information is
 *              essential for subsequently recovering the data but can
 *              be public. The prime will be 1 bit longer than in->used.
 *
 *              The array of secshare_shares created contains public
 *              and private information for each share. The private
 *              information is simply unformatted binary data (in
 *              shares[i].priv.data) of length shares[i].pub.used.
 *              The public information is an ASN.1-encoded INTEGER
 *              giving the index of the share. The private information
 *              should be encrypted before being transmitted. After
 *              being encrypted, it must be kept associated with
 *              the public information. prng should be a
 *              cryptographically strong random number generator, as it
 *              is used to generate the prime, which is public
 *              knowledge.
 * Returns:     The function fails (and returns -1) if we fail to
 *              generate a suitable prime or if we fail to allocate
 *              memory. On success, it returns 0.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows, assuming that we have declared
 *           (code)
 *              secshare_share *shares;
 *              ut_mblk         params;
 *           (/code)
 *              and passed &shares and &params to secshare_share_shamir():
 *           (code)
 *              while (n)
 *                secshare_dispose_share (&(shares[--n]));
 *              ut_dispose_mem(shares);
 *              ut_dispose_mblk (&params)
 *           (/code)
 * Notes:       The index of each share will be between 1 and n
 *              inclusive.
 */
extern 
int
secshare_share_shamir(ut_mblk *in, int m, int n, secshare_gen_params *dum,
  prng_inst *prng, secshare_share **shares, ut_mblk *params);

/* Function:    <secshare_join_shamir>
 * Summary:     Joins m-of-n shares to recover secret with Shamir's method.
 * Syntax:      int rval = secshare_join_shamir(int m, secshare_share *shares,
 *                ut_mblk *params, ut_mblk *out);
 * Description: The secshare_join_shamir() function takes the shares
 *              and generates the shared secret if this is possible.
 *              The params field must contain the
 *              params returned by the previous call to
 *              secshare_share_shamir(); this encodes both m and the
 *              prime p which calculations are performed over.
 * Returns:     On success, out contains the recovered
 *              secret and the function returns 0. On failure, the
 *              function returns -1. 
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mblk(out);
 *           (/code)
 * Notes:       This function must be given EXACTLY m shares.
 */
extern 
int
secshare_join_shamir(secshare_share *shares, ut_mblk *params,
  ut_mblk *out);


/* Data:        <secshare_shamir>
 * Summary:     Function pointers for shamir secshare routines
 * Notes:       The ut_choose() name for this structure is
 *              "Shamir-polynomial-interpolation".
 */
extern const secshare_alg secshare_shamir;

/* Function:    <shareky_make_m_of_n>
 * Summary:     Deprecated.
 */
extern ut_mblk *shareky_make_m_of_n(ut_mblk, int, int, ut_mblk *, prng_inst *);

/* Function:    <shareky_join_m>
 * Summary:     Deprecated.
 */
extern ut_mblk *shareky_join_m(int, ut_mblk *, int *, u8 *);

#ifdef __cplusplus
 }
#endif /* __cplusplus */

#endif /* not _SECSHARE_H */


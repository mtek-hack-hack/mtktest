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

#ifndef _HSHTYPES_H /* Prevent multiple inclusion */
#define _HSHTYPES_H

#include "uttypes.h"

#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef _MPM_ARC
#define _MPM_ARC
typedef void * mpm_arc;
#endif  /* ndef _MPM_ARC */

typedef void * hash_id;

/* Type:      <hash_digest>
 * Summary:   Holds output information from hash_finish_ALG() functions.
 */

typedef union hash_digest_u {
  mpm_arc num;
  struct {
    u32  size;
    u8  *data;
  }      bits;
} hash_digest;

typedef enum {
  HASH_NUMERIC, HASH_BITS
} hash_type;

/* Type:        <hash_algn>
 * Summary:     Canonical algorithm numbers.
 * Description: The hash_algn enum contains the canonical algorithm 
 *              numbers for use in the hash_alg structure.
 */

typedef enum {
  HASH_NONE,
  HASH_RIPEMD,
  HASH_SQMOD,
  HASH_SMDC2,
  HASH_DMDC2,
  HASH_BHF,
  HASH_BSAH,
  HASH_MD5,
  HASH_MD2,
  HASH_SHA,
  HASH_RMD160,
  HASH_HMAC_MD5,
  HASH_HMAC_MD2,
  HASH_HMAC_RIPEMD,
  HASH_HMAC_RMD160,
  HASH_HMAC_SHA,
  HASH_NULLHASH,
  HASH_MAX
} hash_algn;


/* Type:        <hash_alg>
 * Summary:     Function table and other information associated with a
 *              specific hash (message digest) algorithm.
 * Description: The fields in this structure are as follows.
 *              name -- A null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a hash_alg from the hashs[] array.
 *              number -- one of the canonical hash_algn numbers given above.
 *              type -- one of HASH_NUMERIC and HASH_BITS.
 *                HASH_NUMERIC refers only to the square-mod hash
 *                algorithm, which has been removed from the CST as of
 *                version 7. All currently supported hash algorithms
 *                have type HASH_BITS.
 *
 * The remaining fields in the structure are pointers to the hash_FUNC_ALG
 * functions used by the algorithm ALG, as follows.
 *
 * Function:    <hash_start_ALG>
 * Summary:     Start a hash session.
 * Syntax:      hash_id hid = hash_start_ALG(u32 bitsize, mpm_arc modulus,
 *                (ut_mblk *) &key);
 * Description: Returns a new hash function identifier. Those algorithms which
 *              generate digests of a variable bit length will attempt to
 *              generate one of size bitsize. The second argument,
 *              modulus, is no longer used, but is retained for
 *              backwards compatibility. If key (pointer to a ut_mblk)
 *              is non-null, then it is used as a key for any algorithms
 *              which support keyed hashing (eg HMAC).
 *
 *              None of the input arguments are modified in any way.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_ALG() OR hash_kill_ALG().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 * Notes:       The parameters are merely desired sizes; the module has no
 *              obligation to comply, and many functions generate fixed size
 *              digests anyway.
 *
 * Function:    <hash_sizeof_hash_ALG>
 * Summary:     Get the output size from a hash session.
 * Syntax:      size_t size = hash_sizeof_hash_ALG(hash_id hid);
 * Description: Returns the eventual size (in bytes) of digest produced by 
 *              the current session. For those hash algorithms that
 *              produce a fixed-length output, hid can be 0.
 * Returns:     The size of output produced by the current hash session.
 * Notes;       The output size is given in BYTES, not bits.
 *
 * Function:    <hash_append_ALG>
 * Summary:     Append data to a hash session.
 * Syntax:      utb rval = hash_append_ALG(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends the nbits of data pointed to by data to the input stream
 *              of the identified message digest. Note that nbits is the
 *              number of BITS, not bytes. All supplied algorithms
 *              require that nbits be a multiple of 8.
 * Returns:     Returns UT_FALSE (= 0) on internal failure, UT_TRUE (= 1)
 *              otherwise. 
 * Errors:      Returns UT_FALSE (= 0) on internal failure. Cause of failure 
 *              varies from algorithm to algorithm; some may not fail,
 *              others might fail as a result of CST (numerical or
 *              memory-related) problems. If failure does occur, the
 *              digest must be tidied up using hash_kill_ALG().
 * Notes:       This set of functions is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for these functions, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - these functions take the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 * Function:    <hash_kill_ALG>
 * Summary:     Shut down a hash session without getting the output.
 * Syntax:      hash_kill_ALG(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_ALG() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Errors:      This routine cannot fail if given a valid digest identifier.
 * Notes:       If you have called hash_finish_ALG(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 * Function:    <hash_finish_ALG>
 * Summary:     Terminate a hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_ALG(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data and its length in bits is in
 *              hdig.bits.size. In the unlikely case that hdig.bits.size
 *              is not divisible by 8, the relevant bits in the last
 *              octet are the most significant ones.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

typedef struct hash_alg_s {
  const char   *name;
  hash_algn     number;
  hash_type     type;
  hash_id      (CST16EXPORTTYPE *start)(u32, mpm_arc, ut_mblk *);
  size_t       (CST16EXPORTTYPE *sizeof_hash)(hash_id);
  utb          (CST16EXPORTTYPE *append)(u8 *, u32, hash_id);
  void         (CST16EXPORTTYPE *kill)(hash_id);
  hash_digest  (CST16EXPORTTYPE *finish)(hash_id);
} hash_alg;

#ifdef __cplusplus
}
#endif

#endif /* _HSHTYPES_H */

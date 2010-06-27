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

#ifndef _PRIVHASH_H /* Prevent multiple inclusion */
#define _PRIVHASH_H

#include "cstopt.h"
#ifdef WITH_hash_hmac

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* HMACS:   Keyed message authentication codes using non-keyed hash algorithms.
 *  HMACs are defined in Internet RFC 2104. Much of the following terminology
 * is derived from that RFC. 
 */

/* Function:    hmac_start(ut_mblk *, const hash_alg *, size_t blocklength)
 * Syntax:      hid = hmac_start(&key, &hash_ALGNAME, blocklen);
 * Description: Starts a hash session of the hash algorithm specified by
 *              hash_ALGNAME; feeds in key XOR ipad; calculates and stores
 *              key XOR opad. The third argument, blocklength, is the
 *              block length of the hash algorithm (64 for SHA, MD5, RIPEMD
 *              128 and 160)
 * Errors:      Inherits failure from hash_start_ALGNAME; or if there isn't
 *              sufficient memory for ipad or opad.
 * Notes:       You should use the hash_start_hmac_NAME functions instead
 *              of calling this function directly, or use the hash_alg
 *              structure hash_hmac_NAME.
 */

extern hash_id hmac_start(ut_mblk *, const hash_alg *, size_t);

/* Function:    hmac_append
 * Syntax:      success = hmac_append(data, dataLengthInBits, hmac_id);
 * Description: Appends dataLengthInBits bits of data from data to the hmac
 *              session identified by hmac_id. 
 * Errors:      Returns 1 on failure, 0 on success.
 * Notes:       You should use the hash_append_hmac_NAME functions instead
 *              of calling this function directly, or use the hash_alg
 *              structure hash_hmac_NAME.
 */

extern utb 
CST32EXPORTTYPE CST16EXPORTTYPE
hmac_append(u8 *, u32, hash_id);

/* Function:    hmac_kill
 * Syntax:      hmac_kill(hmac_id);
 * Sematics:    Terminates and tidies up the HMAC session identified.
 * Errors:      No failure, or disastrous failure if passed an invalid
 *              HMAC session.
 * Notes:       You should use the hash_kill_hmac_NAME functions instead
 *              of calling this function directly, or use the hash_alg
 *              structure hash_hmac_NAME.
 */

extern void 
CST32EXPORTTYPE CST16EXPORTTYPE
hmac_kill(hash_id);


/* Function:    hmac_finish
 * Syntax:      digest = hmac_finish(hmac_id);
 * Description: Finishes the hash session and outputs the results as a
 *              hash_digest.
 * Errors:      Internal failure causes a return of 0.
 * Notes:       You should use the hash_finish_hmac_NAME functions instead
 *              of calling this function directly, or use the hash_alg
 *              structure hash_hmac_NAME.
 */

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hmac_finish(hash_id);


#endif /* def WITH_hash_hmac */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _PRIVHASH_H */

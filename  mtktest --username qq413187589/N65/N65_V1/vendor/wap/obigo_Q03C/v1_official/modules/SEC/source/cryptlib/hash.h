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

#ifndef _HASH_H /* Prevent multiple inclusion */
#define _HASH_H

#include "cstopt.h" /* For WITH_hash_ripemd, WITH_hash_sqmod,
    WITH_hash_mdc2, WITH_hash_bhf, WITH_hash_rmd160 & WITH_hash_bsah */
#include "hshtypes.h"      /* For i8, hash_id, ... */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define HASH_EBASE (0x0900000) /* Module Code */

#define HASH_ENOMEM (HASH_EBASE + 0x040000) /* Out Of Memory */
#define HASH_EHASHF (HASH_EBASE + 0x040001) /* Hash  Failure */
#define HASH_ESERR (HASH_EBASE + 0x040002) /* Syntax Error */
#define HASH_ENTRNL (HASH_EBASE + 0x040003) /* Internal Failure */
#define HASH_EMPM (HASH_EBASE + 0x040004) /* Internal Failure */
#define HASH_EPARAM (HASH_EBASE + 0x040005) /* Bad Parameters */
#define HASH_EBSAFE (HASH_EBASE + 0x040006) /* problem calling BSAFE */

/* Data:        <hashs>
 * Summary:     Array of supported hash algorithms.
 * Description: The hashs array contains a pointer to the hash_alg structure
 *              corresponding to each of the supported hash algorithms.
 *              A specific hash algorithm structure can be obtained from
 *              hashs using ut_choose().
 */
extern const hash_alg *hashes[];


/*
 * ALGORITHM-SPECIFIC DECLARATIONS
 */

#ifdef WITH_hash_sqmod

/* These are the prototypes for the SQMOD implementation; it generates a digest
 * modulo the modulus supplied to hash_start_sqmod(). It is currently 
 * deprecated.
 */
extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_sqmod(u32, mpm_arc, ut_mblk *);
extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_sqmod(hash_id);
extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_sqmod(u8 *, u32, hash_id);
extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_sqmod(hash_id);
extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_sqmod(hash_id);
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_sqmod;

#endif /* WITH_hash_sqmod */

#ifdef WITH_hash_mdc2

/* These are the prototypes for the single width MDC2 implementation; it
 * generates an n-bit digest where n is the size supplied to hash_start_smdc2
 * and 1 <= n <= 64.
 *
 * Function:    <hash_start_smdc2>
 * Summary:     Start a single-width MDC2 hash session.
 * Syntax:      hash_id hid = hash_start_smdc2(u32 bitsize, 0, 0);
 * Description: The hash_start_smdc2() function returns a handle to a hash
 *              session running single-width MDC2. On a successful call
 *              to hash_finish_smdc2() the output hash will be bitsize
 *              bits long, where bitsize is between 1 and 64.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_smdc2() OR hash_kill_smdc2().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 * Notes:       If bitsize is not between 1 and 64 inclusive it is set
 *              to 64 internally.
 *
 *
 * Function:    <hash_sizeof_hash_smdc2>
 * Summary:     Get the output digest size from an smdc2 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_smdc2(hash_id hid);
 * Description: Returns the number of bytes that the output from the
 *              given hash session hid will take up. This is 1/8 of the
 *              bitsize argument which was passed to
 *              hash_start_smdc2().
 * Returns:     The size in bytes of final output from hid.
 * Notes:       Returns 8 if the bitsize argument which was passed to
 *              hash_start_smdc2() was not between 1 and 64 inclusive.
 *              Also note that hid must be a valid hash session.
 *
 *
 * Function:    <hash_append_smdc2>
 * Summary:     Append data to an smdc2 hash session.
 * Syntax:      utb rval = hash_append_smdc2(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_smdc2>
 * Summary:     Shut down an smdc2 hash session without getting the output.
 * Syntax:      hash_kill_smdc2(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_smdc2() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_smdc2(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_smdc2>
 * Summary:     Terminate an smdc2 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_smdc2(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data and its length in bits (= the length that
 *              would be given by a call to hash_sizeof_hash_smdc2()) is
 *              in hdig.bits.size. If hdig.bits.size is not divisible by
 *              8, the relevant bits in the last octet are the most
 *              significant ones.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_smdc2(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_smdc2(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_smdc2(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_smdc2(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_smdc2(hash_id);


/* Data:        <hash_smdc2>
 * Summary:     Function pointers for smdc2 hash routines.
 * Notes:       The ut_choose() name for this structure is
 *              "MDC2-DES-single-width".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_smdc2;

/* These are the prototypes for the double width MDC2 implementation; it
 * generates an n-bit digest where n is the size supplied to hash_start_dmdc2
 * and 1 <= n <= 128.
 *
 * Function:    <hash_start_dmdc2>
 * Summary:     Start a double-width MDC2 hash session.
 * Syntax:      hash_id hid = hash_start_dmdc2(u32 bitsize, 0, 0);
 * Description: The hash_start_dmdc2() function returns a handle to a hash
 *              session running single-width MDC2. On a successful call
 *              to hash_finish_dmdc2() the output hash will be bitsize
 *              bits long, where bitsize is between 1 and 128.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_dmdc2() OR hash_kill_dmdc2().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 * Notes:       If bitsize is not between 1 and 128 inclusive it is set
 *              to 128 internally.
 *
 *
 * Function:    <hash_sizeof_hash_dmdc2>
 * Summary:     Get the output digest size from an dmdc2 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_dmdc2(hash_id hid);
 * Description: Returns the number of bytes that the output from the
 *              given hash session hid will take up. This is 1/8 of the
 *              bitsize argument which was passed to
 *              hash_start_dmdc2().
 * Returns:     The size in bytes of final output from hid.
 * Notes:       Returns 16 if the bitsize argument which was passed to
 *              hash_start_dmdc2() was not between 1 and 128 inclusive.
 *              Also note that hid must be a valid hash session.
 *
 *
 * Function:    <hash_append_dmdc2>
 * Summary:     Append data to a dmdc2 hash session.
 * Syntax:      utb rval = hash_append_dmdc2(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_dmdc2>
 * Summary:     Shut down a dmdc2 hash session without getting the output.
 * Syntax:      hash_kill_dmdc2(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_dmdc2() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_dmdc2(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_dmdc2>
 * Summary:     Terminate a dmdc2 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_dmdc2(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data and its length in bits (= the length that
 *              would be given by a call to hash_sizeof_hash_dmdc2()) is
 *              in hdig.bits.size. If hdig.bits.size is not divisible by
 *              8, the relevant bits in the last octet are the most
 *              significant ones.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_dmdc2(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_dmdc2(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_dmdc2(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_dmdc2(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_dmdc2(hash_id);


/* Data:        <hash_dmdc2>
 * Summary:     Function pointers for dmdc2 hash routines.
 * Notes:       The ut_choose() name for this structure is 
 *              "MDC2-DES-double-width".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_dmdc2;

#endif /* WITH_hash_mdc2 */

#ifdef WITH_hash_bsah

/* These are the prototypes for the BSAH implementation; it generates an
 * n-bit digest where n is the size supplied to hash_start_bsah.
 *
 * Function:    <hash_start_bsah>
 * Summary:     Start a BSAH hash session.
 * Syntax:      hash_id hid = hash_start_bsah(u32 bitsize, 0, 0);
 * Description: The hash_start_bsah() function returns a handle to a hash
 *              session running single-width MDC2. On a successful call
 *              to hash_finish_bsah() the output hash will be bitsize
 *              bits long, where bitsize is between 1 and 128.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_bsah() OR hash_kill_bsah().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 * Notes:       If bitsize is not between 1 and 128 inclusive it is set
 *              to 128 internally.
 *
 *
 * Function:    <hash_sizeof_hash_bsah>
 * Summary:     Get the output digest size from a bsah hash session.
 * Syntax:      size_t size = hash_sizeof_hash_bsah(hash_id hid);
 * Description: Returns the bitsize argument which was passed to
 *              hash_start_bsah().
 * Returns:     The size of output produced by the current hash session.
 * Notes:       Returns 128 if the bitsize argument which was passed to
 *              hash_start_bsah() was not between 1 and 128 inclusive.
 *
 *
 * Function:    <hash_append_bsah>
 * Summary:     Append data to a bsah hash session.
 * Syntax:      utb rval = hash_append_bsah(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_bsah>
 * Summary:     Shut down a bsah hash session without getting the output.
 * Syntax:      hash_kill_bsah(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_bsah() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_bsah(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_bsah>
 * Summary:     Terminate a bsah hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_bsah(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data and its length in bits (= the length that
 *              would be given by a call to hash_sizeof_hash_bsah()) is
 *              in hdig.bits.size. If hdig.bits.size is not divisible by
 *              8, the relevant bits in the last octet are the most
 *              significant ones.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_bsah(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_bsah(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_bsah(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_bsah(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_bsah(hash_id);


/* Data:        <hash_bsah>
 * Summary:     Function pointers for bsah hash routines.
 * Notes:       The ut_choose() name for this structure is "bsah".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_bsah;

#endif /* WITH_hash_bsah */

#ifdef WITH_hash_sha

/* These are the prototypes for the SHA-1 implementation; it always generates a
 * 160-bit digest.
 *
 * Function:    <hash_start_sha>
 * Summary:     Start a SHA-1 hash session.
 * Syntax:      hash_id hid = hash_start_sha(0, 0, 0);
 * Description: The hash_start_sha() function returns a handle to a hash
 *              session running SHA-1. 
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_sha() OR hash_kill_sha().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 * Notes:       It's called hash_start_sha(), but it actually runs SHA-1.
 *
 *
 * Function:    <hash_sizeof_hash_sha>
 * Summary:     Get the output digest size from a SHA-1 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_sha(hash_id hid);
 * Description: Returns 20.
 * Returns:     The size of output produced by the current hash session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_sha>
 * Summary:     Append data to a SHA-1 hash session.
 * Syntax:      utb rval = hash_append_sha(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_sha>
 * Summary:     Shut down a SHA-1 hash session without getting the output.
 * Syntax:      hash_kill_sha(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_sha() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_sha(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_sha>
 * Summary:     Terminate a SHA-1 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_sha(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 160.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_sha(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_sha(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_sha(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_sha(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_sha(hash_id);


/* Data:        <hash_sha>
 * Summary:     Function pointers for sha hash routines.
 * Notes:       The ut_choose() name for this structure is "SHA".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_sha;

/* Clones a SHA hash; creates a duplicate hash in exactly the same state.
 * On allocation failure returns null.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_clone_sha(hash_id);

/* Outputs a SHA digest to the specified target location and resets the
 * hash to its initial state; it can then be reused, it is not freed. The
 * target location must be a valid 20-octet buffer.
 */

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_output_to_sha(u8 *, hash_id);

#endif /* WITH_hash_sha */

#ifdef WITH_hash_md2

/* These are the prototypes for the MD2 implementation; it always generates a
 * 128-bit digest.
 *
 * Function:    <hash_start_md2>
 * Summary:     Start a MD2 hash session.
 * Syntax:      hash_id hid = hash_start_md2(0, 0, 0);
 * Description: The hash_start_md2() function returns a handle to a hash
 *              session running MD2. 
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_md2() OR hash_kill_md2().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_md2>
 * Summary:     Get the output digest size from a MD2 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_md2(hash_id hid);
 * Description: Returns 16.
 * Returns:     The size of output produced by the current hash session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_md2>
 * Summary:     Append data to a MD2 hash session.
 * Syntax:      utb rval = hash_append_md2(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_md2>
 * Summary:     Shut down a MD2 hash session without getting the output.
 * Syntax:      hash_kill_md2(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_md2() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_md2(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_md2>
 * Summary:     Terminate a MD2 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_md2(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 128.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_md2(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_md2(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_md2(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_md2(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_md2(hash_id);


/* Data:        <hash_md2>
 * Summary:     Function pointers for md2 hash routines.
 * Notes:       The ut_choose() name for this structure is "MD2".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_md2;

#endif /* WITH_hash_md2 */

#ifdef WITH_hash_md5

/* These are the prototypes for the MD5 implementation; it always generates a
 * 128-bit digest.
 *
 * Function:    <hash_start_md5>
 * Summary:     Start a MD5 hash session.
 * Syntax:      hash_id hid = hash_start_md5(0, 0, 0);
 * Description: The hash_start_md5() function returns a handle to a hash
 *              session running MD5. 
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_md5() OR hash_kill_md5().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_md5>
 * Summary:     Get the output digest size from a MD5 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_md5(hash_id hid);
 * Description: Returns 16.
 * Returns:     The size of output produced by the current hash session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_md5>
 * Summary:     Append data to a MD5 hash session.
 * Syntax:      utb rval = hash_append_md5(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_md5>
 * Summary:     Shut down a MD5 hash session without getting the output.
 * Syntax:      hash_kill_md5(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_md5() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_md5(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_md5>
 * Summary:     Terminate a MD5 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_md5(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 128.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_md5(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_md5(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_md5(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_md5(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_md5(hash_id);


/* Data:        <hash_md5>
 * Summary:     Function pointers for md5 hash routines.
 * Notes:       The ut_choose() name for this structure is "MD5".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_md5;

/* Clones an MD5 hash; creates a duplicate hash in exactly the same state.
 * On allocation failure returns null.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_clone_md5(hash_id);

/* Outputs an MD5 digest to the specified target location and resets the
 * hash to its initial state; it can then be reused, it is not freed. The
 * target location must be a valid 16-octet buffer.
 */

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_output_to_md5(u8 *, hash_id);

#endif /* WITH_hash_md5 */

#ifdef WITH_hash_ripemd

/* These are the prototypes for the RIPEMD implementation; it always
 * generates a 128-bit message digest.
 *
 * Function:    <hash_start_ripemd>
 * Summary:     Start a RIPEMD hash session.
 * Syntax:      hash_id hid = hash_start_ripemd(0, 0, 0);
 * Description: The hash_start_ripemd() function returns a handle to a hash
 *              session running RIPEMD. 
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_ripemd() OR hash_kill_ripemd().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_ripemd>
 * Summary:     Get the output digest size from a RIPEMD hash session.
 * Syntax:      size_t size = hash_sizeof_hash_ripemd(hash_id hid);
 * Description: Returns 16.
 * Returns:     The size of output produced by the current hash session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_ripemd>
 * Summary:     Append data to a RIPEMD hash session.
 * Syntax:      utb rval = hash_append_ripemd(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_ripemd>
 * Summary:     Shut down a RIPEMD hash session without getting the output.
 * Syntax:      hash_kill_ripemd(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_ripemd() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_ripemd(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_ripemd>
 * Summary:     Terminate a RIPEMD hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_ripemd(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 128.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_ripemd(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_ripemd(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_ripemd(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_ripemd(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_ripemd(hash_id);


/* Data:        <hash_ripemd>
 * Summary:     Function pointers for ripemd hash routines.
 * Notes:       The ut_choose() name for this structure is "RIPEMD".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_ripemd;

#endif /* WITH_hash_ripemd */

#ifdef WITH_hash_rmd160

/* These are the prototypes for the RIPEMD-160 implementation; it always
 * generates a 160-bit message digest.
 *
 * Function:    <hash_start_rmd160>
 * Summary:     Start a RIPEMD-160 hash session.
 * Syntax:      hash_id hid = hash_start_rmd160(0, 0, 0);
 * Description: The hash_start_rmd160() function returns a handle to a hash
 *              session running RIPEMD-160. 
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_rmd160() OR hash_kill_rmd160().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_rmd160>
 * Summary:     Get the output digest size from a RIPEMD-160 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_rmd160(hash_id hid);
 * Description: Returns 20.
 * Returns:     The size of output produced by the current hash session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_rmd160>
 * Summary:     Append data to a RIPEMD-160 hash session.
 * Syntax:      utb rval = hash_append_rmd160(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_rmd160>
 * Summary:     Shut down a RIPEMD-160 hash session without getting the output.
 * Syntax:      hash_kill_rmd160(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_rmd160() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_rmd160(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_rmd160>
 * Summary:     Terminate a RIPEMD-160 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_rmd160(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 160.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_rmd160(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_rmd160(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_rmd160(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_rmd160(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_rmd160(hash_id);


/* Data:        <hash_rmd160>
 * Summary:     Function pointers for rmd160 hash routines.
 * Notes:       The ut_choose() name for this structure is "RIPEMD-160".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_rmd160;

#endif /* WITH_hash_rmd160 */

#ifdef WITH_hash_bhf

/* These are the prototypes for the BHF implementation; it generates an
 * n-bit digest where n is the size supplied to hash_start_bhf.
 *
 * Function:    <hash_start_bhf>
 * Summary:     Start a BHF hash session.
 * Syntax:      hash_id hid = hash_start_bhf(u32 nbits, mpm_arc modulus, 
 *                ut_mblk *key);
 * Description: The hash_start_bhf() function returns a handle to a hash
 *              session running BHF. The output length will be nbits,
 *              rounded up to the nearest byte. The modulus is used in
 *              multiple precision arithmetic. key->data must contain a
 *              null-terminated char *.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_bhf() OR hash_kill_bhf().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_bhf>
 * Summary:     Get the output digest size from a BHF hash session.
 * Syntax:      size_t size = hash_sizeof_hash_bhf(hash_id hid);
 * Description: Returns 1/8 * the value of nbits supplied to
 *              hash_start_bhf(), rounded up to the next integer.
 * Returns:     The size of output produced by the current hash session.
 *
 *
 * Function:    <hash_append_bhf>
 * Summary:     Append data to a BHF hash session.
 * Syntax:      utb rval = hash_append_bhf(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid.
 * Returns:     Returns UT_TRUE.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_bhf>
 * Summary:     Shut down a BHF hash session without getting the output.
 * Syntax:      hash_kill_bhf(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_bhf() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_bhf(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_bhf>
 * Summary:     Terminate a BHF hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_bhf(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is the next multiple of 8
 *              up from the value of nbits supplied to hash_start_bhf().
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_bhf(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_bhf(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_bhf(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_bhf(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_bhf(hash_id);


/* Data:        <hash_bhf>
 * Summary:     Function pointers for bhf hash routines.
 * Notes:       The ut_choose() name for this structure is "BHF".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_bhf;

#endif /* WITH_hash_bhf */

#ifdef WITH_hash_hmacmd2

/* These are the prototypes for the MD2 HMAC; it always 
 * generates a 128-bit message digest.
 *
 * Function:    <hash_start_hmac_md2>
 * Summary:     Start a MD2 HMAC session.
 * Syntax:      hash_id hid = hash_start_hmac_md2(0, 0, ut_mblk *hkey);
 * Description: The hash_start_hmac_md2() function returns a handle to a 
 *              HMAC session. This produces a keyed hash using MD2 as
 *              the hash algorithm and hkey->data as the key data. The
 *              data in hkey->data is considered to be binary data of
 *              length hkey->used.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_hmac_md2() OR hash_kill_hmac_md2().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_hmac_md2>
 * Summary:     Get the output digest size from a MD2 HMAC session.
 * Syntax:      size_t size = hash_sizeof_hash_hmac_md2(hash_id hid);
 * Description: Returns 16.
 * Returns:     The size of output produced by the current HMAC session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_hmac_md2>
 * Summary:     Append data to a MD2 HMAC session.
 * Syntax:      utb rval = hash_append_hmac_md2(u8 *data, u32 nbits, 
 *                hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_hmac_md2>
 * Summary:     Shut down a MD2 HMAC session without getting the output.
 * Syntax:      hash_kill_hmac_md2(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_hmac_md2() or a failure in some other
 *              function while a HMAC session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_hmac_md2(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_hmac_md2>
 * Summary:     Terminate a MD2 HMAC session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_hmac_md2(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 128.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_hmac_md2(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_hmac_md2(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_hmac_md2(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_hmac_md2(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_hmac_md2(hash_id);


/* Data:        <hash_hmac_md2>
 * Summary:     Function pointers for hmac_md2 hash routines.
 * Notes:       The ut_choose() name for this structure is "HMAC-MD2".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_hmac_md2;

#endif /* WITH_hash_hmacmd2 */

#ifdef WITH_hash_hmacmd5

/* These are the prototypes for the MD5 HMAC; it always 
 * generates a 128-bit message digest.
 *
 * Function:    <hash_start_hmac_md5>
 * Summary:     Start a MD5 HMAC session.
 * Syntax:      hash_id hid = hash_start_hmac_md5(0, 0, ut_mblk *hkey);
 * Description: The hash_start_hmac_md5() function returns a handle to a 
 *              HMAC session. This produces a keyed hash using MD5 as
 *              the hash algorithm and hkey->data as the key data. The
 *              data in hkey->data is considered to be binary data of
 *              length hkey->used.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_hmac_md5() OR hash_kill_hmac_md5().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_hmac_md5>
 * Summary:     Get the output digest size from a MD5 HMAC session.
 * Syntax:      size_t size = hash_sizeof_hash_hmac_md5(hash_id hid);
 * Description: Returns 16.
 * Returns:     The size of output produced by the current HMAC session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_hmac_md5>
 * Summary:     Append data to a MD5 HMAC session.
 * Syntax:      utb rval = hash_append_hmac_md5(u8 *data, u32 nbits, 
 *                hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_hmac_md5>
 * Summary:     Shut down a MD5 HMAC session without getting the output.
 * Syntax:      hash_kill_hmac_md5(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_hmac_md5() or a failure in some other
 *              function while a HMAC session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_hmac_md5(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_hmac_md5>
 * Summary:     Terminate a MD5 HMAC session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_hmac_md5(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 128.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_hmac_md5(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_hmac_md5(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_hmac_md5(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_hmac_md5(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_hmac_md5(hash_id);


/* Data:        <hash_hmac_md5>
 * Summary:     Function pointers for hmac_md5 hash routines.
 * Notes:       The ut_choose() name for this structure is "HMAC-MD5".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_hmac_md5;

#endif /* WITH_hash_hmacmd5 */

#ifdef WITH_hash_hmacrmd

/* These are the prototypes for the RIPEMD HMAC; it always 
 * generates a 128-bit message digest.
 *
 * Function:    <hash_start_hmac_ripemd>
 * Summary:     Start a RIPEMD HMAC session.
 * Syntax:      hash_id hid = hash_start_hmac_ripemd(0, 0, ut_mblk *hkey);
 * Description: The hash_start_hmac_ripemd() function returns a handle to a 
 *              HMAC session. This produces a keyed hash using RIPEMD as
 *              the hash algorithm and hkey->data as the key data. The
 *              data in hkey->data is considered to be binary data of
 *              length hkey->used.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_hmac_ripemd() OR
 *              hash_kill_hmac_ripemd().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_hmac_ripemd>
 * Summary:     Get the output digest size from a RIPEMD HMAC session.
 * Syntax:      size_t size = hash_sizeof_hash_hmac_ripemd(hash_id hid);
 * Description: Returns 16.
 * Returns:     The size of output produced by the current HMAC session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_hmac_ripemd>
 * Summary:     Append data to a RIPEMD HMAC session.
 * Syntax:      utb rval = hash_append_hmac_ripemd(u8 *data, u32 nbits, 
 *                hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_hmac_ripemd>
 * Summary:     Shut down a RIPEMD HMAC session without getting the output.
 * Syntax:      hash_kill_hmac_ripemd(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_hmac_ripemd() or a failure in some other
 *              function while a HMAC session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_hmac_ripemd(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_hmac_ripemd>
 * Summary:     Terminate a RIPEMD HMAC session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_hmac_ripemd(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 128.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_hmac_ripemd(u32, mpm_arc, ut_mblk*);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_hmac_ripemd(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_hmac_ripemd(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_hmac_ripemd(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_hmac_ripemd(hash_id);


/* Data:        <hash_hmac_ripemd>
 * Summary:     Function pointers for hmac_ripemd hash routines.
 * Notes:       The ut_choose() name for this structure is "HMAC-RIPEMD".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_hmac_ripemd;

#endif /* WITH_hash_hmacrmd */

#ifdef WITH_hash_hmacr160

/* These are the prototypes for the RIPEMD-160 HMAC; it always 
 * generates a 160-bit message digest.
 *
 * Function:    <hash_start_hmac_rmd160>
 * Summary:     Start a RIPEMD-160 HMAC session.
 * Syntax:      hash_id hid = hash_start_hmac_rmd160(0, 0, ut_mblk *hkey);
 * Description: The hash_start_hmac_rmd160() function returns a handle to a 
 *              HMAC session. This produces a keyed hash using RIPEMD-160 as
 *              the hash algorithm and hkey->data as the key data. The
 *              data in hkey->data is considered to be binary data of
 *              length hkey->used.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_hmac_rmd160() OR
 *              hash_kill_hmac_rmd160().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_hmac_rmd160>
 * Summary:     Get the output digest size from a RIPEMD-160 HMAC session.
 * Syntax:      size_t size = hash_sizeof_hash_hmac_rmd160(hash_id hid);
 * Description: Returns 20.
 * Returns:     The size of output produced by the current HMAC session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_hmac_rmd160>
 * Summary:     Append data to a RIPEMD-160 HMAC session.
 * Syntax:      utb rval = hash_append_hmac_rmd160(u8 *data, u32 nbits, 
 *                hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_hmac_rmd160>
 * Summary:     Shut down a RIPEMD-160 HMAC session without getting the output.
 * Syntax:      hash_kill_hmac_rmd160(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_hmac_rmd160() or a failure in some other
 *              function while a HMAC session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_hmac_rmd160(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_hmac_rmd160>
 * Summary:     Terminate a RIPEMD-160 HMAC session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_hmac_rmd160(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 160.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_hmac_rmd160(u32, mpm_arc, ut_mblk*);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_hmac_rmd160(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_hmac_rmd160(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_hmac_rmd160(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_hmac_rmd160(hash_id);


/* Data:        <hash_hmac_rmd160>
 * Summary:     Function pointers for hmac_rmd160 hash routines.
 * Notes:       The ut_choose() name for this structure is "HMAC-RMD160".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_hmac_rmd160;

#endif /* WITH_hash_hmacr160 */

#ifdef WITH_hash_hmacsha

/* These are the prototypes for the SHA-1 HMAC; it always 
 * generates a 160-bit message digest.
 *
 * Function:    <hash_start_hmac_sha>
 * Summary:     Start a SHA-1 HMAC session.
 * Syntax:      hash_id hid = hash_start_hmac_sha(0, 0, ut_mblk *hkey);
 * Description: The hash_start_hmac_sha() function returns a handle to a 
 *              HMAC session. This produces a keyed hash using SHA-1 as
 *              the hash algorithm and hkey->data as the key data. The
 *              data in hkey->data is considered to be binary data of
 *              length hkey->used.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_hmac_sha() OR hash_kill_hmac_sha().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_hmac_sha>
 * Summary:     Get the output digest size from a SHA-1 HMAC session.
 * Syntax:      size_t size = hash_sizeof_hash_hmac_sha(hash_id hid);
 * Description: Returns 20.
 * Returns:     The size of output produced by the current HMAC session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_hmac_sha>
 * Summary:     Append data to a SHA-1 HMAC session.
 * Syntax:      utb rval = hash_append_hmac_sha(u8 *data, u32 nbits, 
 *                hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 * Errors:      In debug mode (preprocessor flag NDEBUG not defined),
 *              aborts if nbits is not a multiple of 8.
 * Notes:       This function is superficially similar to the 
 *              bsapi_append_ALG() functions, so note that they differ in
 *              the following two ways:
 *              - for this function, a return value of 0 denotes
 *                failure; for bsapi_append_ALG(), a return value of 0
 *                denotes success.
 *              - this function takes the data length in BITS;
 *                bsapi_append_ALG() takes the data length in BYTES.
 *
 *
 * Function:    <hash_kill_hmac_sha>
 * Summary:     Shut down a SHA-1 HMAC session without getting the output.
 * Syntax:      hash_kill_hmac_sha(hash_id hid);
 * Description: Terminates and tidies up the identified message digest; this
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_hmac_sha() or a failure in some other
 *              function while a HMAC session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_hmac_sha(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_hmac_sha>
 * Summary:     Terminate a SHA-1 HMAC session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_hmac_sha(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. The digest is contained in
 *              hdig.bits.data. hdig.bits.size is 160.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_hmac_sha(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_hmac_sha(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_hmac_sha(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_hmac_sha(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_hmac_sha(hash_id);


/* Data:        <hash_hmac_sha>
 * Summary:     Function pointers for hmac_sha hash routines.
 * Notes:       The ut_choose() name for this structure is "HMAC-SHA".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_hmac_sha;

#endif /* WITH_hash_hmacsha */

#ifdef WITH_hash_nullhash

/* These are the prototypes for the null hash implementation.
 *
 * Function:    <hash_start_nullhash>
 * Summary:     Start a null hash session.
 * Syntax:      hash_id hid = hash_start_nullhash(bits, 0, 0);
 * Description: The hash_start_nullhash() function returns a handle to a hash
 *              session running the null hash algorithm. If bits is set,
 *              the null hash algorithm will output the first bits of
 *              the input to hash_append_nullhash(). If bits is null,
 *              the null hash algorithm will output all of its input.
 * Returns:     A handle to the new hash session, on success. 0 on failure.
 * Memory:      The hash session must eventually be shut down using
 *              EITHER hash_finish_nullhash() OR hash_kill_nullhash().
 * Errors:      The routine may fail due to lack of memory, in which case the
 *              return value is 0.
 *
 *
 * Function:    <hash_sizeof_hash_nullhash>
 * Summary:     Get the output digest size from a SHA-1 hash session.
 * Syntax:      size_t size = hash_sizeof_hash_nullhash(hash_id hid);
 * Description: Returns the value of bits that was passed to
 *              hash_start_nullhash().
 * Returns:     The size of output produced by the current hash session.
 * Notes:       The argument hid can be 0.
 *
 *
 * Function:    <hash_append_nullhash>
 * Summary:     Append data to a SHA-1 hash session.
 * Syntax:      utb rval = hash_append_nullhash(u8 *data, u32 nbits, hash_id hid);
 * Description: Appends nbits of input from data to the input stream
 *              of the message digest session hid. Note that nbits is the
 *              number of BITS, not bytes, but it must be a multiple of 8.
 * Returns:     Returns UT_TRUE.
 *
 *
 * Function:    <hash_kill_nullhash>
 * Summary:     Shut down a SHA-1 hash session without getting the output.
 * Syntax:      hash_kill_nullhash(hash_id hid);
 * Description: Terminates and tidies up the identified hash session. This
 *              would normally be used if, for some external reason, the
 *              digest generation process had to be terminated (a
 *              failure in hash_append_nullhash() or a failure in some other
 *              function while a hash session was active).
 * Returns:     This function returns no value.
 * Notes:       If you have called hash_finish_nullhash(), whether
 *              successfully or unsuccessfully, you do not need to call
 *              this function; in debug mode, calling it will give you
 *              the error "attempt to free unallocated block of memory"
 *              and an ABORT.
 *
 *
 * Function:    <hash_finish_nullhash>
 * Summary:     Terminate a SHA-1 hash session and get the hash.
 * Syntax:      hash_digest hdig = hash_finish_nullhash(hash_id hid);
 * Description: Terminates the input data stream of the identified hash session
 *              and returns the digest in a hash_digest structure; this
 *              allocates memory. 
 *
 *              The null hash function returns the data that was passed
 *              to it in hash_append_nullhash. If the number of bits was
 *              specified on the call to hash_start_nullhash(), then
 *              this is the number of bits of input that are output,
 *              padded with NULLs if necessary to bring it to the
 *              specified length. Otherwise, this function returns all
 *              the data. hdig.bits.data is set to reflect the length in
 *              bits of the returned data.
 * Returns:     Returns a hash_digest containing the result of the
 *              digest operation.
 * Memory:      The digest data must be disposed of using 
 *              ut_dispose_mem(hdig.bits.data);
 * Errors:      On error (usually due to failure to allocate memory),
 *              hdig.bits.data will be 0.
 */

extern hash_id   
CST32EXPORTTYPE CST16EXPORTTYPE
hash_start_nullhash(u32, mpm_arc, ut_mblk *);

extern size_t    
CST32EXPORTTYPE CST16EXPORTTYPE
hash_sizeof_hash_nullhash(hash_id);

extern utb       
CST32EXPORTTYPE CST16EXPORTTYPE
hash_append_nullhash(u8 *, u32, hash_id);

extern void      
CST32EXPORTTYPE CST16EXPORTTYPE
hash_kill_nullhash(hash_id);

extern hash_digest 
CST32EXPORTTYPE CST16EXPORTTYPE
hash_finish_nullhash(hash_id);


/* Data:        <hash_nullhash>
 * Summary:     Function pointers for sha hash routines.
 * Notes:       The ut_choose() name for this structure is "nullhash".
 */
extern const hash_alg CST32EXPORTDATA CST16EXPORTDATA hash_nullhash;

#endif /* WITH_hash_nullhash */


#ifdef _CST_INTERNAL_BUILD

/* A structure that holds the three arguments to a hash_start_ALG
 * function */

typedef struct hash_args_s hash_args;

struct hash_args_s {
  u32       bitsize;
  mpm_arc   modulus;
  ut_mblk  *key;
};

/* hash_digest
 * hash_mblks(
 *   ut_mblk *inblks, -- The data to be hashed
 *   int no_of_mblks, -- The number of ut_mblks
 *   hash_alg *halg,  -- The hash algorithm to use
 *   hash_args *hargs -- The arguments to halg->start. Note that if
 *                       hargs = 0 the arguments are automatically set
 *                       as (0, 0, 0) to save time.
 * );
 * On failure, the returned hash_digest structure is entirely zeroed.
 */

ut_mblk
hash_mblks
(ut_mblk *inblks[], int no_of_mblks, hash_alg *halg, hash_args *hargs);

/* hash_digest
 * hash_mblk_list(
 *   ut_mblk_list inlist, -- The data to be hashed
 *   hash_alg *halg,  -- The hash algorithm to use
 *   hash_args *hargs -- The arguments to halg->start. Note that if
 *                       hargs = 0 the arguments are automatically set
 *                       as (0, 0, 0) to save time.
 * );
 * On failure, the returned hash_digest structure is entirely zeroed.
 */

ut_mblk
hash_mblk_list(ut_mblk_list inlist, hash_alg *halg, hash_args *hargs);

#endif /* def _CST_INTERNAL_BUILD */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _HASH_H */

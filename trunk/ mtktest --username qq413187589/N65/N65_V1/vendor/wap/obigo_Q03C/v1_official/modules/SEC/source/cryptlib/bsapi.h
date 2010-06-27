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

#ifndef _BSAPI_H /* prevent multiple inclusion */
#define _BSAPI_H

#include "cstopt.h"    /* For system-specific settings */

#include "bstypes.h"   /* For u8, bsapi_id, etc... */

#include "prng.h"      /* For prng_inst */
#include "pad.h"       /* For pad_alg */
#include "cstopt.h"    /* For WITH_hash, WITH_bsapi_des, WITH_bsapi_rsa,
    WITH_bsapi_idea, WITH_bsapi_bsa4 & WITH_bsapi_bsa5 */
#ifdef WITH_hash
#include "hash.h"      /* For hash_alg */
#endif /* WITH_hash */

#ifdef WITH_sb_ecdsa
#include "sbecdsa.h"
#endif /* WITH_sb_ecdsa */

#ifdef WITH_sb_ecdh
#include "sbecdh.h"
#endif /* WITH_sb_ecdh */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ERRORS */

#define BSAPI_EBASE (0x00400000) /* Module code */

#define BSAPI_ENOMEM (BSAPI_EBASE + 0x40000) /* Out of memory */
#define BSAPI_EXTRAC (BSAPI_EBASE + 0x40100) /* Unnecessary trailing
                                              * cyphertext */
#define BSAPI_EBADC  (BSAPI_EBASE + 0x40101) /* BAD CYPHERTEXT */
#define BSAPI_EPADFA (BSAPI_EBASE + 0x40200) /* (Un)padding failed/corrupt */
#define BSAPI_ENTRNL (BSAPI_EBASE + 0x40300) /* Internal failure */
#define BSAPI_EVFAIL (BSAPI_EBASE + 0x40400) /* Verify failed */
#define BSAPI_EBADKY (BSAPI_EBASE + 0x40500) /* Key is corrupt */
#define BSAPI_EBADIV (BSAPI_EBASE + 0x40600) /* IV is corrupt */
#define BSAPI_EPRNGF (BSAPI_EBASE + 0x40700) /* prng failure */
#define BSAPI_EWARN  (BSAPI_EBASE + 0x40800) /* Issue warning:   poor usage */
#define BSAPI_EPARAM (BSAPI_EBASE + 0x40900) /* Bad parameters */
#define BSAPI_ECMD   (BSAPI_EBASE + 0x40a00) /* Bad command */
#define BSAPI_ENOMPM (BSAPI_EBASE + 0x40b00) /* MPM create failed */
#define BSAPI_EMPMFA (BSAPI_EBASE + 0x40c00) /* MPM failure */
#define BSAPI_ESB    (BSAPI_EBASE + 0x40d00) /* Security Builder failure */
#define BSAPI_EBSAFE  (BSAPI_EBASE + 0x40d00) /* BSAFE Error */

/* Data:        <bsapis>
 * Summary:     Array of supported bsapi algorithms
 * Description: The bsapis array contains a pointer to the bsapi_alg structure
 *              corresponding to each of the supported bsapi algorithms.
 *              A specific bsapi algorithm structure can be obtained from
 *              bsapis using ut_choose().
 */
extern const bsapi_alg CST32EXPORTDATA * CST16EXPORTDATA bsapis[];

/*
 * ALGORITHM-SPECIFIC DECLARATIONS
 */


#ifdef WITH_bsapi_des

/* Function:    <bsapi_generate_sharedparams_des>
 * Summary:     Not applicable to the DES algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_des(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_des() function does nothing
 *              and returns 0.
 * Returns:     0.
 */

extern int
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_des(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);
 

/* Function:    <bsapi_generate_key_des>
 * Summary:     Generates a key for DES.
 * Syntax:      int rval = bsapi_generate_key_des(prng_inst *prng, 
 *              (ut_mblk *) &spt, 0, (bsapi_kparam *) &kparam);
 * Description: The bsapi_generate_key_des() function takes a set of key
 *              parameters kparam and a random number generator prng,
 *              and generates an 8-byte DES key with the parity bits
 *              set. The key is written to spt.data, where memory is
 *              allocated, and spt.size and spt.used are set
 *              accordingly.
 *              - kparam.des.security can be any of the possible values for
 *                bsapi_kparam_des.
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or problems with the prng. Also returns -1 if prng, 
 *              spt or &kparam is 0.
 *
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)
 */  

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_des(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_des>
 * Summary:     Not applicable to the DES algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_des(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_des() function does nothing
 *              and returns 0.
 * Returns:     0.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_des (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_des>
 * Summary:     Gets length of initialization vector for DES.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_des((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_des() function returns the number of
 *              octets of memory that must be allocated to hold the
 *              initialization vector for the algorithm des when it is used
 *              according to bmode. 
 *              - If bmode.mode = BSAPI_ECB it returns 0.
 *              - Otherwise it returns 8.
 * Returns:     The number of octets of memory that must be allocated to
 *              hold the initialization vector for the algorithm DES. Returns
 *              0 if &bmode is 0.
 * Errors:      Does not fail.      
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_des(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_des>
 * Summary:     Starts a DES session.
 * Syntax:      bsapi_id sid = bsapi_start_des((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_des() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - bmode.mode may be any one of BSAPI_ECB, BSAPI_CBC,
 *                BSAPI_CFB and BSAPI_OFB. If it is anything other than
 *                BSAPI_ECB, kset.iv must be set. If it is BSAPI_CFB or
 *                BSAPI_OFB, kset.feedback must also be set.
 *              - bmode.triple may be BSAPI_SINGLE, BSAPI_TRIPLE or
 *                BSAPI_CHAIN3. Depending on this, kset.kets will contain
 *                one or three ut_mblks containing the key data. See the item
 *                on kset.keys for more details. If you're using BSAPI_TRIPLE 
 *                it may be more convenient to use bsapi_start_triple_des()
 *                and associated functions.
 *              - bmode.key_type may be BSAPI_KEY ( = 0 ) or
 *                BSAPI_SCHEDULE. The use of BSAPI_SCHEDULE is deprecated.
 *              - bmode.fast may be BSAPI_ANSI or BSAPI_FAST. BSAPI_FAST runs
 *                the algorithm without the initial and final permutations, 
 *                which makes it faster in software. BSAPI_ANSI performs the
 *                initial and final permutations, making the implementation 
 *                ANSI-compliant, and is recommended.
 *              - prng_inst * must be provided if kset.padalg = &pad_bdes.
 *                In all other cases it can be set to 0.
 *              - kset.keys contains the key data. If bmode.triple =
 *                BSAPI_SINGLE, kset.keys must contain a ut_mblk * with
 *                kset.keys->used = 8 and kset.keys->data containing 8
 *                bytes of data. If bmode.triple = BSAPI_TRIPLE or
 *                BSAPI_CHAIN3, kset.keys must be an array of three
 *                ut_mblks, each containing eight bytes of data (to use
 *                two-key triple DES, simply set the third ut_mblk's data
 *                field to be the same as the first one's with
 *                kset.keys[2].data = kset.keys[0].data). 
 *              - kset.iv contains the initialization vector (IV) data and
 *                must be set if bmode.mode = BSAPI_CBC, BSAPI_CFB or
 *                BSAPI_OFB. Its contents depend on bmode.triple. If
 *                bmode.triple = BSAPI_SINGLE or BSAPI_TRIPLE, kset.iv must
 *                contain a ut_mblk * with kset.iv->used = 8 and 8 octets
 *                of data at kset->iv.data. If bmode.triple = BSAPI_CHAIN3,
 *                kset.iv points to the start of an array of three
 *                ut_mblks, each containing an eight-byte IV.
 *              - kset.feedback must be set if bmode.mode = BSAPI_CFB or
 *                BSAPI_OFB. For OFB mode, it should be set to 64. For CFB,
 *                it can be set to any value between 1 and 64; the higher
 *                the value the faster the algorithm will run.
 *              - kset.padalg may be 0, &pad_bdes or &pad_pkcs5. &pad_pkcs5
 *                provides the widely-used PKCS-5 style padding (now also
 *                specified in standards such as S/MIME). If kset.padalg =
 *                0, the data will be padded on encryption by appending
 *                null bytes to the end of the final encryption block if
 *                this is necessary to bring the data up to a multiple of 8
 *                bytes long. If kset.padalg = 0, no unpadding is performed
 *                on decryption. If you're using kset.padalg = 0,
 *                therefore, you should ensure that your data is an exact
 *                multiple of eight bytes in length.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.   
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_des() or
 *              bsapi_kill_des(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_des(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_des()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_des() was successful.
 * Errors:      Indicated by null (0) return value, due to memory problems
 *              or an incorrect key length. Also returns 0 if
 *              passed NULL key data or (in debug mode) if bmode.op is not 
 *              BSAPI_ENCRYPT or BSAPI_DECRYPT.
 * Example:     See bsapi_kill_des().
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_des(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_des>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_des(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_des() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held inside
 *              the session until a successful call to
 *              bsapi_readmost_des(), bsapi_read_des(), or
 *              bsapi_finish_des(). The session ID sid must have originally
 *              been returned from a call to the bsapi_start_des() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Returns
 *              -1 if the session or data passed is NULL.
 * Example:     See bsapi_kill_des().
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_des(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_des>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_des(bsapi_id sid);
 * Description: The bsapi_read_des() function reads all available data from
 *              a bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_des() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_des().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a 
 *              null sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_des(bsapi_id session);


/* Function:    <bsapi_sizeof_readmost_des>
 * Summary:     Gives size of output from bsapi_readmost_des() corresponding to
 *              input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_des(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_des() function gives the length of 
 *              output that would be produced by a call to bsapi_readmost_des() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_des().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_des(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_des>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_des(bsapi_id sid);
 * Description: The bsapi_readmost_des() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_des() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_des() function. 
 *
 *              This function is preferred to bsapi_read_des() for all normal
 *              operations.
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_des(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_des(data, len, sid);
 *                 output = bsapi_readmost_des(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_des(sid, &output);
 *               write(output);
 *               ut_dispose_list(output);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              null sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       When it is running in ECB or CBC mode the function leaves the
 *              final 8 bytes inside the session at all times if the
 *              session is decrypting.
 * Example:     See bsapi_kill_des().
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_des(bsapi_id session);


/* Function:    <bsapi_finish_des>
 * Summary:     Finishes a bsapi session using DES, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_des(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_des() function finishes the bsapi session
 *              sid for des. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_des() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_des() function. On successful
 *              completion, mlist will contain all of the processed data
 *              which has not been output in previous calls to
 *              bsapi_read_des() or bsapi_readmost_des().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or failure in unpadding. Also returns -1 on null
 *              parameters.   
 * Example:     See bsapi_kill_des().
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_des(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_des>
 * Summary:     Gives the amount of output from a given input to a DES
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_des(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_des() function returns the maximum
 *              amount of output which could be produced if inqty octets of
 *              data were input into the session sid. This does not include
 *              the effects of any data that is buffered inside the
 *              session. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_des() function.
 * Returns:     The maximum size of output for the given size of input. Returns
 *              -1 if passed a null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_des(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_des>
 * Summary:     Kills a DES session, releasing all resources.
 * Syntax:      bsapi_kill_des(bsapi_id sid);
 * Description: The bsapi_kill_des() function shuts down a bsapi_des
 *              session sid, freeing all memory associated with the session
 *              and returning no output. It is for use when it is necessary
 *              to terminate a session unfinished. The session ID sid must
 *              have originally been returned from a call to the
 *              bsapi_start_des() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function DES-encrypts (or decrypts, depending on
 *              the op parameter) stdin to stdout using the supplied key
 *              and prng_inst *; it shows how to construct a mode structure
 *              and key set, how to start an algorithm and write/read as
 *              data becomes available, and how to exit gracefully in case of
 *              any problems (it uses ut_log() for error reporting,
 *              and returns 0 on success or -1 on failure):
 * 
 *           (code)
 *               int
 *               desfunc(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset   keys = {0};
 *                 bsapi_id     sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 size_t       len;
 *                 
 *                 // Set up single ANSI ECB DES, plain key, standard (PKCS#5) padding 
 *                 md.op = op;
 *                 keys.keys = key; 
 *                 keys.padalg = &pad_pkcs5;
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_des(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_des(buf, len, sid)) {
 *                     bsapi_kill_des(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_des(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                       stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_des(sid, &cyph)) {
 *                   // even if bsapi_finish_des() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_des() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                     stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 *                 
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_des(bsapi_id session);


/* Function:    <bsapi_get_name_des>
 * Summary:     Returns bsapi_des.name.
 * Syntax:      const char *rval = bsapi_get_name_des();
 * Description: The bsapi_get_name_des() function returns the bsapi_des.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_des(void);


/* Function:    <bsapi_setkeyparity_des>
 * Summary:     Sets parity bits for a DES key.
 * Syntax:      int rval = bsapi_setkeyparity_des(ut_mblk *key); 
 * Description: The bsapi_setkeyparity_des() function sets the parity
 *              bits on key->data as appropriate for a DES key. It
 *              doesn't check the length of the key or perform any
 *              other tests.
 * Returns:     Returns -1 if passed NULL key. Otherwise 
 *              always returns 0.
 * Memory:      This function allocates no memory.
 */

extern int bsapi_setkeyparity_des(ut_mblk *key);


/* Function:    <bsapi_strongkeycheck_des>
 * Summary:     Checks that a DES key is sufficiently strong.
 * Syntax:      int rval = bsapi_setkeyparity_des(u8 *key, 
 *                bsapi_kparam_des strength); 
 * Description: The bsapi_strongkeycheck_des() function checks that the
 *              supplied DES key meets the security requirements specified
 *              by strength.
 * Returns:     Returns -1 if passed a weak key (as defined by the stength
 *              parameter). Otherwise always returns 0.
 * Memory:      This function allocates no memory.
 */

extern int
bsapi_strongkeycheck_des(u8 *deskey, bsapi_kparam_des strength);


/* Function:    <des_direct>
 * Summary:     Implements the DES algorithm.
 * Syntax:      des_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The des_direct() function feeds length octets of data from
 *              input into the DES session sid and writes the processed data 
 *              to output. The function does nothing if passed null parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    des_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_des>
 * Summary:     Function pointers for DES bsapi routines
 * Notes:       The ut_choose() name for this structure is "DES".
 */

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_des;

/* Auxiliary function support */

/* Function:    <des_reset>
 * Summary:     Changes the key and/or initialization vector in a
 *              bsapi session.
 * Syntax:      int rval = des_reset(bsapi_id sid, ut_mblk *ivnew, 
 *                ut_mblk *keynew, bsapi_mode_key_type keynewtype);
 * Description: The des_reset() function replaces the key and/or initialization
 *              vector being used in the DES session sid with keynew and/or
 *              ivnew.
 * Returns:     0 on success, -1 on failure due to key or initialization vector
 *              having incorrect length. Also returns -1 if sid is null.
*/

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    des_reset(bsapi_id session, ut_mblk *iv, ut_mblk *key,
    bsapi_mode_key_type kt);



/* Function:    <bsapi_generate_sharedparams_triple_des>
 * Summary:     Not applicable to the Triple DES algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_triple_des
 *                (prng_inst *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_triple_des() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_triple_des(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_triple_des>
 * Summary:     Generates a key for Triple DES.
 * Syntax:      int rval = bsapi_generate_key_triple_des(prng_inst *prng,
 *              (ut_mblk *) &spt, 0, (bsapi_kparam *) &kparam);
 * Description: The bsapi_generate_key_triple_des() function takes a set of
 *              key parameters kparam and a random number generator prng,
 *              and generates a 24-byte key for three-key triple DES. The
 *              key is written to spt.data, where memory is allocated, and
 *              spt.size and spt.used are set accordingly. 
 *              - kparam.des.security can be any of the possible values for
 *                bsapi_kparam_des.
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or problems with the prng. Also returns -1 if prng, 
 *              spt or &kparam is 0.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mblk (&spt);
 *           (/code)   
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_triple_des(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_triple_des>
 * Summary:     Not applicable to the Triple DES algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_triple_des
 *                (prng_inst *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_triple_des() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_triple_des (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_triple_des>
 * Summary:     Gets length of initialization vector for Triple DES.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_triple_des((bsapi_mode *)
 *                &bmode, 0);
 * Description: The bsapi_sizeof_iv_triple_des() function returns the
 *              number of octets of memory that must be allocated to hold
 *              the initialization vector for the algorithm triple_des when
 *              it is used according to bmode. 
 *              - If bmode.mode = BSAPI_ECB it returns 0.
 *              - Otherwise it returns 8.
 * Returns:     The number of octets of memory that must be allocated to
 *              hold the initialization vector for the algorithm triple_des.
 *              Also returns 0 if &bmode is 0.
 * Errors:      Does not fail.      
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_triple_des(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_triple_des>
 * Summary:     Starts a Triple DES session.
 * Syntax:      bsapi_id sid = bsapi_start_triple_des((bsapi_mode *)
 *              &bmode, prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_triple_des() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. It is exactly the same as
 *              calling bsapi_start_des with bmode.mode = BSAPI_TRIPLE,
 *              except that instead of supplying an array of three ut_mblks
 *              in kset.keys the programmer need only supply a single
 *              ut_mblk. The key data in kset.keys can be either 16 bytes
 *              long (two-key Triple DES) or 24 bytes long (three-key
 *              Triple DES).
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or
 *                BSAPI_DECRYPT.
 *              - bmode.mode may be any one of BSAPI_ECB, BSAPI_CBC,
 *                BSAPI_CFB and BSAPI_OFB.
 *              - bmode.key_type may be BSAPI_KEY ( = 0 ) or
 *                BSAPI_SCHEDULE. The use of BSAPI_SCHEDULE is deprecated.
 *              - bmode.fast may be BSAPI_ANSI or BSAPI_FAST. BSAPI_FAST runs
 *                the algorithm without the initial and final permutations, 
 *                which makes it faster in software. BSAPI_ANSI performs the
 *                initial and final permutations, making the implementation 
 *                ANSI-compliant, and is recommended.
 *              - prng_inst * must be provided if kset.padalg = &pad_bdes.
 *                In all other cases it can be set to 0.
 *              - kset.keys must contain a ut_mblk * with kset.keys->used =
 *                16 or 24 and kset.keys->data containing 16 or 24 bytes of
 *                data.
 *              - kset.iv contains the initialization vector (IV) data and
 *                must be set if bmode.mode = BSAPI_CBC, BSAPI_CFB or
 *                BSAPI_OFB. If set, it must contain a ut_mblk * with
 *                kset.iv->used = 8 and 8 octets of data at kset->iv.data.
 *              - kset.feedback must be set if bmode.mode = BSAPI_CFB or
 *                BSAPI_OFB. For OFB mode, it should be set to 64. For CFB,
 *                it can be set to any value between 1 and 64; the higher
 *                the value the faster the algorithm will run.
 *              - kset.padalg may be 0, &pad_bdes or &pad_pkcs5.
 *                &pad_pkcs5 provides the widely-used PKCS-5 style padding
 *                (now also specified in standards such as S/MIME). If
 *                kset.padalg = 0, the data will be padded on encryption by
 *                appending null bytes to the end of the final encryption
 *                block if this is necessary to bring the data up to a
 *                multiple of 8 bytes long. If kset.padalg = 0, no
 *                unpadding is performed on decryption. If you're using
 *                kset.padalg = 0, therefore, you should ensure that your
 *                data is an exact multiple of eight bytes in length.
 *              - all other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_triple_des() or
 *              bsapi_kill_triple_des(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_triple_des(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_triple_des()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_triple_des() was successful.
 * Errors:      Indicated by null (0) return value, due to memory problems
 *              or an incorrect key length. Also returns 0 if passed NULL key
 *              data or (in debug mode) if bmode.op is not BSAPI_ENCRYPT or   
 *              BSAPI_DECRYPT.          
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_triple_des(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_triple_des>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_triple_des(u8 *ptr, size_t len,
 *              bsapi_id sid);
 * Description: The bsapi_append_triple_des() function writes len octets
 *              from ptr into a bsapi session sid. The processed data is
 *              held inside the session until a successful call to
 *              bsapi_readmost_triple_des(), bsapi_read_triple_des(), or
 *              bsapi_finish_triple_des(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_triple_des() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Returns
 *              -1 if the session or data passed is NULL.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_triple_des(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_triple_des>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_triple_des(bsapi_id sid);
 * Description: The bsapi_read_triple_des function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_triple_des() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_triple_des().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              null sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None.      
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_triple_des(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_triple_des>
 * Summary:     Gives size of output from bsapi_readmost_triple_des()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_triple_des(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_triple_des() function gives the
 *              length of output that would be produced by a call to 
 *              bsapi_readmost_triple_des() subsequent to input bytes of data 
 *              being fed to the session sid with a call to 
 *              bsapi_append_triple_des().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_triple_des(size_t input, bsapi_id session);



/* Function:    <bsapi_readmost_triple_des>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_triple_des(bsapi_id sid);
 * Description: The bsapi_readmost_des() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_des() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_des() function. 
 *
 *              This function is preferred to bsapi_read_des() for all normal
 *              operations.
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_triple_des(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_triple_des(data, len, sid);
 *                 output = bsapi_readmost_triple_des(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_triple_des(sid, &output);
 *               write(output);
 *               ut_dispose_list(output);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a 
 *              null sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None.      
 * Notes:       When running in ECB or CBC mode the function leaves the 
 *              final 8 bytes inside the session when the session is decrypting. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_triple_des(bsapi_id session);


/* Function:    <bsapi_finish_triple_des>
 * Summary:     Finishes a bsapi session using Triple DES, returns output and
 *              frees memory.
 * Syntax:      int rval = bsapi_finish_triple_des(bsapi_id sid,
 *              (ut_mblk_list *) &mlist);
 * Description: The bsapi_finish_triple_des() function finishes the bsapi
 *              session sid for triple_des. The memory pointed to by sid is
 *              deallocated following a call to bsapi_finish_triple_des()
 *              whether the return value from the function indicates
 *              success or not. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_triple_des()
 *              function. On successful completion, mlist will contain all
 *              of the processed data which has not been output in previous
 *              calls to bsapi_read_triple_des() or bsapi_readmost_triple_des().
 * Returns:     0 on success or -1 on failure due to lack of memory. Returns
 *              -1 if the session or data passed is NULL.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_triple_des(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_triple_des>
 * Summary:     Gives the amount of output from a given input to a
 *              Triple DES session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_triple_des(bsapi_id sid,
 *              off_t inqty);
 * Description: The bsapi_sizeof_output_triple_des() function returns the
 *              maximum amount of output which could be produced if inqty
 *              octets of data were input into the session sid. This does
 *              not include the effects of any data that is buffered inside
 *              the session. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_triple_des() function.
 * Returns:     The maximum size of output for the given size of input. Returns 
 *              -1 if passed a null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_triple_des(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_triple_des>
 * Summary:     Kills a Triple DES session, releasing all resources.
 * Syntax:      bsapi_kill_triple_des(bsapi_id sid);
 * Description: The bsapi_kill_triple_des() function shuts down a
 *              bsapi_triple_des session sid, freeing all memory associated
 *              with the session and returning no output. It is for use
 *              when it is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_triple_des() function.
 * Returns:     void.
 * Errors:      None.
 */
 
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_triple_des(bsapi_id session);


/* Function:    <bsapi_get_name_triple_des>
 * Summary:     Returns bsapi_triple_des.name.
 * Syntax:      const char *rval = bsapi_get_name_triple_des();
 * Description: The bsapi_get_name_triple_des() function returns the 
 *              bsapi_triple_des.name field. This is the field which
 *              ut_choose() uses to convert from a string to a bsapi_alg
 *              algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_triple_des(void);


/* Function:    <triple_des_direct>
 * Summary:     Implements the Triple DES algorithm.
 * Syntax:      triple_des_direct(bsapi_id sid, u8 *input, u8 *output, 
 *                size_t length);
 * Description: The triple_des_direct() function feeds length octets of data
 *              from input into the Triple DES session sid and writes the 
 *              processed data to output.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    triple_des_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_triple_des>
 * Summary:     Function pointers for Triple DES bsapi routines
 * Notes:       The ut_choose() name for this structure is "Triple-DES".
 */

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_triple_des;


#endif /* WITH_bsapi_des */

#ifdef WITH_bsapi_dsa

/* Function:    <bsapi_generate_sharedparams_dsa>
 * Summary:     Generates shared parameters for DSA.
 * Syntax:      int rval = bsapi_generate_sharedparams_dsa(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_dsa() function generates
 *              shared parameters for DSA. param has the following fields:
 *              param.dsa_com.p_length -- the length in bits of p, the
 *              modulus. This is a prime and should be 512-1024 bits
 *              according to the DSA standard.
 *              param.dsa_com.q_length -- the length in bits of the large 
 *              subgroup order within p. To comply with the standard this
 *              must be 160.
 * Returns:     The function returns 0 on success or -1 on failure due to lack
 *              of memory, internal problems or null parameters, including
 *              null param->dsa_shrdpub.p_length or param->dsa_shrdpub.q_length.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_dsa(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_dsa>
 * Summary:     Generates a key for DSA.
 * Syntax:      int rval = bsapi_generate_key_dsa(prng_inst *prng, 
 *                (ut_mblk *) &spt, (ut_mblk *) &ppt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_key_dsa() function generates an DSA
 *              keypair. The private key is written to spt.data, where
 *              memory is allocated, and spt.size and spt.used are set
 *              accordingly. The public key is written to ppt. 
 * 
 *              The parameters to the function are a pointer to the shared
 *              public parameters and an optional footprint database
 *              FILE *. They are contained in a bsapi_kparam_dsa_key
 *              structure.
 *
 * Returns:     The function returns 0 on success or -1 on failure due to
 *              lack of memory, problems with the prng or failure to decode
 *              the ASN.1-encoded shared parameters contained in 
 *              param.dsa_key.shrdpub. Also returns -1 if any of the
 *              parameters is NULL.
 * Memory:      spt.data, ppt.data will have to be disposed of following a 
 *              successful return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              ut_dispose_mem(ppt.data);
 *           (/code)     
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_dsa(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_dsa>
 * Summary:     Generates private nonces for DSA signing.
 * Syntax:      int rval = bsapi_generate_privatenonce_dsa(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_dsa() function generates
 *              one-time, message-independent, private values for use
 *              in signing (the "k-values", as they are sometimes known).
 *              The private nonce is generated into cpt, which can then
 *              be passed to bsapi_start_dsa() in kset.pnonce.
 *
 *              The parameters to the function are the same as the parameters
 *              to bsapi_generate_key_dsa, namely a pointer to the shared
 *              public parameters and an optional footprint database
 *              FILE *. They are contained in a bsapi_kparam_dsa_key
 *              structure.
 *
 * Returns:     This function returns 0 on success, -1 on failure due to
 *              memory/internal problems. Also returns 0 if passed
 *              null shared parameters in param.
 * 
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_dsa (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_dsa>
 * Summary:     Not applicable to the DSA algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_dsa((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_dsa() function does nothing and returns 0.
 * Returns:     0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_dsa(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_dsa>
 * Summary:     Starts a DSA session.
 * Syntax:      bsapi_id sid = bsapi_start_dsa((bsapi_mode *) &bmode, 0,
 *              (bsapi_kset *) &kset);
 * Description: The bsapi_start_dsa() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform signing or verification.
 *              - bmode.op may be BSAPI_SIGN or BSAPI_VERIFY.
 *              - kset.keys contains the key data. This is a pointer to a
 *                ut_mblk which contains a DSA private key (when signing)
 *                or a DSA public key (when verifying). The key data is passed
 *                to the function as an ASN.1-encoded byte string.
 *              - kset.shrdpub contains the DSA shared public parameters. This
 *                is a pointer to a ut_mblk which contains the triple p, q and
 *                g as an ASN.1-encoded sequence of integers.
 *              - kset.hashalg is the hash algorithm to use. For DSA this
 *                MUST be either &hash_sha or (if kset.data_type == 
 *                BSAPI_DATA_TYPE_HASH) 0, or your implementation will
 *                not conform to the standard.
 *              - kset.data_type indicates what kind of data is being
 *                passed into the authentication session. If kset.data_type
 *                == BSAPI_DATA_TYPE_DATA or BSAPI_DATA_TYPE_DEFAULT (= 0),
 *                the data is hashed inside the dsa session. In this case,
 *                kset.hashalg must be specified. If kset.data_type ==
 *                BSAPI_DATA_TYPE_HASH, the data passed in to
 *                bsapi_append_dsa() is assumed to have been hashed already
 *                and is not processed further.
 *              When signing, kset.pnonce may contain a one-time private nonce 
 *              generated by bsapi_generate_pnonce_dsa(). If this is present, 
 *              bsapi will use it in generating the signature. This speeds up 
 *              signature generation because it is no longer necessary to do a 
 *              modular exponentiation. For 1024-bit signatures, the speed up
 *              is typically by a factor of 200.
 *              If kset.pnonce is non-zero, a prng need not be supplied to
 *              bsapi_start_dsa(), and any prng that is supplied will be
 *              ignored. If kset.pnonce is zero, a prng must be supplied to
 *              bsapi_start_dsa(). If both kset.pnonce and prng are zero,
 *              bsapi_start_dsa() will return 0.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure. Failure will be due to lack of memory, problems
 *              with ASN.1-decoding or bmode.op not being BSAPI_SIGN or 
 *              BSAPI_VERIFY. Also returns 0 if null key data is
 *              passed to the function.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_dsa() or
 *              bsapi_kill_dsa(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_dsa(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_dsa()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_dsa() was successful.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_dsa(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_dsa>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_dsa(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_dsa() function writes len octets from
 *              ptr into the bsapi dsa authentication session sid. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_dsa() function. 
 *              - If the session is expecting message data (if
 *                kset.data_type in bsapi_start_dsa() was
 *                BSAPI_DATA_TYPE_DATA or BSAPI_DATA_TYPE_DEFAULT) the data
 *                is passed to the internal hash session which was
 *                indicated by kset.hashalg. 
 *              - If the session is expecting an already calculated hash
 *                (if kset.data_type in bsapi_start_dsa() was
 *                BSAPI_DATA_TYPE_HASH), this function may only be called
 *                once. The ptr argument should contain the hash data and
 *                the len argument should give the length of the hash. If
 *                this function is called again it returns -1 with the
 *                error message "Hash data already read into dsa session",
 *                and the data is ignored.
 * Returns:     0 on success or -1 on failure due to memory/internal problems
 *              Also returns -1 if either ptr or sid is null.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_dsa(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_dsa>
 * Summary:     Not applicable to the DSA algorithm.
 * Syntax:      ut_mblk_list mlist = bsapi_read_dsa(bsapi_id sid);
 * Description: The bsapi_read_dsa() function does nothing and returns 0.
 * Memory:      This function allocates no memory.
 * Errors:      None.
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_dsa(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_dsa>
 * Summary:     Not applicable to the DSA algorithm.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_dsa(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_dsa() function does nothing and 
 *              returns 0.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_dsa(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_dsa>
 * Summary:     Not applicable to the DSA algorithm.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_dsa(bsapi_id sid);
 * Description: The bsapi_readmost_dsa() function does nothing and returns 0.
 * Memory:      This function allocates no memory.
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_dsa(bsapi_id session);


/* Function:    <bsapi_finish_dsa>
 * Summary:     Finishes a bsapi session using DSA, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_dsa(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: We describe signing and verification sessions separately.
 * Signing:     The bsapi_finish_dsa() function finishes the bsapi session sid
 *              for dsa. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_dsa() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_dsa() function. On successful
 *              completion, mlist will contain a ut_mblk_list with a single
 *              member (mlist->prev = mlist; mlist->next = 0). The
 *              signature data is at mlist->block.data and is of length
 *              mlist->block.used. The signature comes in the form of a
 *              DER-encoded SEQUENCE of two 160-bit INTEGERS. This is the
 *              format used in most standards, such as S/MIME and PKIX.
 * Verification:The bsapi_finish_dsa() function finishes the bsapi session
 *              sid for dsa. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_dsa() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_dsa() function. When verifying, the
 *              signature to be verified must be passed into the function
 *              in mlist (see the Example). This signature must be a
 *              DER-encoded SEQUENCE of two 160-bit INTEGERS. This is the
 *              format used in most standards, such as S/MIME and PKIX. The
 *              bsapi_finish_dsa() function checks to see if the signature
 *              is valid for the message or hash which was passed into
 *              bsapi_append_dsa(). It returns
 * Returns:     0 if the signature is correct.
 *              -1 if there was an internal error.
 *              1 if the signature did not verify.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_dsa(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_dsa>
 * Summary:     Gets size of DSA signature.
 * Syntax:      off_t outqty = bsapi_sizeof_output_dsa(bsapi_id sid,
 *                off_t inqty);
 * Description: The bsapi_sizeof_output_dsa() function returns the maximum
 *              amount of output which could be produced if inqty octets of
 *              data were input into the session sid.           
 * Returns:     48 if signing, 0 if verifying.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_dsa(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_dsa>
 * Summary:     Kills a DSA session, releasing all resources.
 * Syntax:      bsapi_kill_dsa(bsapi_id sid);
 * Description: The bsapi_kill_dsa() function shuts down a bsapi_dsa
 *              session sid, freeing all memory associated with the session
 *              and returning no output. It is for use when it is necessary
 *              to terminate a session unfinished. The session ID sid must
 *              have originally been returned from a call to the
 *              bsapi_start_dsa() function.
 * Returns:     void.
 * Errors:      None.
 */

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_dsa(bsapi_id session);


/* Function:    <bsapi_get_name_dsa>
 * Summary:     Returns bsapi_dsa.name.
 * Syntax:      const char *rval = bsapi_get_name_dsa();
 * Description: The bsapi_get_name_dsa() function returns the bsapi_dsa.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_dsa(void);


/* Function:    <bsapi_validate_shrdpub_dsa>
 * Summary:     Checks that DSA shared public parameters are valid.
 * Syntax:      int rval = bsapi_validate_shrdpub_dsa(ut_mblk *shrdPubBlk,
 *                bsapi_shrdpubval_params *bsvp);
 * Description: The bsapi_validate_shrdpub_dsa() function checks that the
 *              parameters supplied in shrdpub are correct. In other
 *              words, it checks that:
 *              - p is prime;
 *              - q is prime and divides p-1;
 *              - g has multiplicative order q mod p.
 *
 *              The additional validation parameters supplied in bsvp
 *              may be used to check that the length of p in bits is
 *              bsvp.dsa.plen, and the length of q in bits is bsvp.dsa.qlen. If
 *              one of these fields is NULL the corresponding check is
 *              not carried out, and if bsvp is NULL neither check is
 *              carried out.
 *
 *              This function returns 0 if the parameters are valid, 
 *              1 if they are invalid, and -1 if an internal error
 *              occurred.
 * Memory:      This function allocates no memory.
 * Example:     The following code fragment gives an example of the use of
 *              this function.
 *            (code)
 *               bsapi_shrdpubval_param bsvp;
 *               ut_mblk                shrdparams;  
 *
 *               bsvp.dsa.p_len = 1024; // expected length of p 
 *               bsvp.dsa.q_len = 160;  // expected length of q 
 *
 *               // copy ASN.1-encoded DSA shared parameters to shrdparams.data 
 *
 *               if (bsapi_validate_shrdpub_dsa(&shrdparams, &bsvp)) {
 *                 ut_log0(0UL, UT_ACONTINUE, "couldn't validate parameters")
 *                 return -1;
 *               }
 *             (/code)
 */
extern
int
bsapi_validate_shrdpub_dsa(ut_mblk *shrdPubBlk, 
  bsapi_shrdpubval_param *bsvp);


/* Function:    <bsapi_validate_key_dsa>
 * Summary:     Checks that DSA public and private key match.
 * Syntax:      int rval = bsapi_validate_key_dsa(ut_mblk *privBlk, 
 *                ut_mblk *pubBlk, bsapi_keyval_param *bkvp);
 * Description: The bsapi_validate_key_dsa() function checks that the
 *              private key in privBlk corresponds to the public key in
 *              pubBlk. The bkvp->dsa.shrdpub field should contain the
 *              shared public parameters for the DSA keypair.
 *
 * Returns:     This function returns 0 if the keys match; 1 if they
 *              don't; -1 if there was an internal error; and -2 if it
 *              was given null arguments.
 * Memory:      This function allocates no memory.
 * Notes:       The function checks that the private key x corresponds to
 *              the public key y by calculating g^x mod p, where g and p
 *              are obtained from the shared public parameters supplied.
 *              It also checks that  1 < x < (q-1), where q is the
 *              subprime from the parameters and that the lengths of p and q
 *              are as expected.
 * Example:     The following code fragment gives an example of the use of
 *              this function.
 *            (code)
 *               ut_mblk            pubKey;
 *               ut_mblk            privKey;
 *               ut_mblk            shrdparams;
 *               bsapi_keyval_param bkvp;
 *
 *               // copy ASN.1-encoded public key y to pubKey.data 
 *               // copy ASN.1-encoded private key to privKey.data 
 *               // copy ASN.1-encoded DSA shared parameters to shrdparams.data 
 *             
 *               bkvp.shrdpub = shrdparams;
 *
 *               if (bsapi_validate_key_dsa(&pubKey, &privKey, &bkvp)) {
 *                 ut_log0(0UL, UT_ACONTINUE, "couldn't validate parameters")
 *                 return -1;
 *               }
 *             (/code)
 */

extern
int
bsapi_validate_key_dsa(ut_mblk *privBlk, ut_mblk *pubBlk, 
  bsapi_keyval_param *bkvp);


/* Function:    <dsa_direct>
 * Summary:     Simply calls bsapi_append_dsa().
 * Syntax:      dsa_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The dsa_direct() function calls the function bsapi_append_dsa()
 *              and sets output to 0. The function does nothing if passed
 *              a null sid.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    dsa_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Function:    <set_prng_dsa>
 * Summary:     Sets DSA session prng.
 * Syntax:      int rval = set_prng_dsa(prng_inst *prng, bsapi_id session);
 * Description: The set_prng_dsa() function sets the supplied prng as the DSA
 *              session prng.
 * Returns:     This function returns 0 on success or -1 if the session is null.
 */

extern int
  CST32EXPORTTYPE CST16EXPORTTYPE
    set_prng_dsa(prng_inst *prng, bsapi_id session);


/* Data:        <bsapi_dsa>
 * Summary:     Function pointers for DSA bsapi routines
 * Notes:       The ut_choose() name for this structure is "DSA".
 */

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_dsa;


#endif /* WITH_bsapi_dsa */

#ifdef WITH_bsapi_rsa

/* Function:    <bsapi_generate_sharedparams_rsa>
 * Summary:     Not applicable to the RSA algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_rsa(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_rsa() function does nothing
 *              and returns 0.
 * Returns:     0.
 * 
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_rsa(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_rsa>
 * Summary:     Generates a key for RSA.
 * Syntax:      int rval = bsapi_generate_key_rsa(prng_inst *prng, 
 *                (ut_mblk *) &spt, (ut_mblk *) &ppt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_key_rsa() function generates an RSA
 *              keypair. The private key is written to spt.data, where
 *              memory is allocated, and spt.size and spt.used are set
 *              accordingly. The public key is written to ppt. 
 * 
 *              The parameters in param may be set as follows:
 *              - param.rsa.kbits is the required length in bits of the
 *                modulus of the output RSA key. This is the value commonly
 *                referred to as the "key length". Typical values will be
 *                768, 1024 and (rarely) 2048. The encoded key data
 *                will be longer than this bit length, because the key data
 *                includes the exponent and (sometimes) additional fields
 *                to speed up computations.
 *              - if param.rsa.crt == 1, then Chinese Remainder Theorem
 *                information is stored with the private key. This speeds
 *                up private key operations by a factor of about 4, but
 *                roughly doubles the amount of memory needed to hold the
 *                private key data (from approximately twice
 *                param.rsa.kbits to approximately four times that value).
 *                The trade-off is usually worth making, and this field
 *                should be set unless you have a good reason not to set it.
 *              - if param.rsa.fermat is 0, the public exponent is
 *                generated at random. If param.rsa.fermat is between 1 and
 *                5, the public exponent is the corresponding Fermat
 *                Number: 2^((2^n) -1) + 1. Fermat-1 is 3; Fermat-5 is
 *                65537 (in decimal) or 0x10001 (in hex). Using a Fermat
 *                number both reduces the memory necessary to store the key
 *                and speeds up public key operations by, typically, two
 *                orders of magnitude. Fermat-1 is an acceptable choice if
 *                the RSA public key is to be used for signature
 *                verification ONLY. Fermat-5 (param.rsa.fermat = 5) is
 *                used by almost all commerical Certification Authorities
 *                and is the recommended value to use here.
 *              - kpar.rsa.algorithm can be set to 0 or 1. If it is 0,
 *                bsapi_generate_key_rsa() will get the modulus from two
 *                strong primes (a strong prime is a prime p such that p-1
 *                has a large prime factor r; r-1 has a large prime factor;
 *                p+1 has a large prime factor. These primes are specified
 *                for use in, eg, ANSI X9.31. The function generates strong
 *                primes using Gordon's algorithm). If it is 1,
 *                bsapi_generate_key_rsa() will simply generate two primes,
 *                not two strong primes. It is currently believed that,
 *                particularly for moduli over 700 bits long, the
 *                overwhelming majority of primes are secure enough that
 *                there is no need to explicitly request strong primes.
 *                Additionally, the best attack currrently known against
 *                RSA will work equally well against strong primes and weak
 *                primes.
 *              - kpar.rsa.test can be set to 1, which tells
 *                bsapi_generate_key_rsa() to run a test RSA encryption and
 *                decryption immediately after generating the key, or 0,
 *                which tells it not to.
 *              - kpar.rsa.fdb is a FILE * pointing to a "footprint
 *                database", or 0. A footprint database is a file that
 *                stores hashes of previously generated keys in order to
 *                prevent generation of keys with duplicate moduli. A 16K
 *                footprint database will allow you to generate approximatley
 *                64,000 keys and guarantee no duplicates. However, if you
 *                random number generator has been well seeded, duplicate keys
 *                should not be an issue anyway and this field can usually be
 *                set to 0. The file should have been created with the CST demo                
 *                application createdb. 
 * Returns:     Returns 0 on success or -1 on failure (lack of memory/internal
 *              problems). Also, returns 0 if prng or spt is 0.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)
 * Notes:       The key data within the ut_mblks is stored in the format
 *              given in PKCS#1. The programmer can, however, safely treat
 *              them as black boxes.
 * Example:     The code fragment below assumes the existence of a
 *              previously created prng_inst *. It generates an RSA key
 *              pair. Error handling is minimal. See bsapi_kparam_rsa for
 *              more explanation of what the various fields mean.
 *           (code)
 *             bsapi_kparam kpar;
 *             ut_mblk priv, pub;
 *             // Set up key parameters here 
 *             kpar.rsa.kbits = 2048; // 2kbit key 
 *             kpar.rsa.crt = 1; // Chinese Remainder Theorem 
 *             kpar.rsa.fermat = 5; // Use Fermat 5 
 *             kpar.rsa.algorithm = 0; // Secure by construction 
 *             kpar.rsa.test = 0; // Don't bother testing it 
 *             kpar.rsa.fdb = 0; // No modulus footprinting 
 *             if(bsapi_generate_key_rsa(prng, &priv, &pub, &kpar))
 *               fprintf(stderr, "failed to generate RSA key pair");
 *             else // Success! 
 *               // Private key is at priv.data, length priv.used 
 *               // Public key is at pub.data, length pub.used *
 *           (/code)
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_rsa(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_rsa>
 * Summary:     Not applicable to the RSA algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_rsa(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_rsa() function does nothing
 *              and returns 0.
 * Returns:     0.
 * 
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_rsa (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_rsa>
 * Summary:     Not applicable to the RSA algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_rsa((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_rsa() function does nothing and returns 0.
 * Returns:     0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_rsa(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_rsa>
 * Summary:     Starts an RSA session.
 * Syntax:      bsapi_id sid = bsapi_start_rsa((bsapi_mode *) &bmode, 0,
 *              (bsapi_kset *) &kset);
 * Description: The bsapi_start_rsa() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. We describe its use first
 *              for encryption/decryption ("encryption"), then for
 *              signing/verification ("authentication").
 * Encryption:  Note: you should only be encrypting one block at a time using
 *              RSA. The following fields must be set.
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - kset.keys contains the key data. This is a pointer to a
 *                ut_mblk which contains an RSA public key (when
 *                encrypting) or an RSA private key (when decrypting).
 *              - The rest of the required information is conveyed in two
 *                other fields. kset.padalg tells the session how to format
 *                the data before encrypting, or how to recover the
 *                original data after decrypting. Some pad algorithms
 *                require parameters, which are supplied in the kset.padpar
 *                field.
 *              - If kset.padalg == 0 then kset.padpar is ignored. In this
 *                case it is up to the programmer to ensure that the data can
 *                be processed correctly. The data will be split up into blocks
 *                the length of the modulus. If any of these blocks represents
 *                a larger number than the modulus encryption will fail.
 *                Note that if the final block of plaintext is shorter than
 *                the modulus, it is padded on the RIGHT with null bytes.
 *                So "hello" doesn't become the integer represented by
 *                "...000hello" but instead "hello000...". If the data is
 *                formatted into a block the length of the modulus when it
 *                is passed to bsapi_append_rsa, this will prevent any
 *                padding happening at all.
 *              - If kset.padalg == &pad_brsa, the final block of data is
 *                padded on the left with random bytes. A random number
 *                generator must be supplied in prng. Both kset.padpar and
 *                kset.key_type should be 0 to ensure correct default
 *                behavior. When encrypting with this pad algorithm, the
 *                final block of data must be at least three bytes shorter
 *                than the modulus or there will be an error. This pad
 *                algorithm should only be used for legacy systems.
 *              - If kset.padalg == &pad_brsaorig, the final block of data
 *                is padded on the left with random bytes. A random number
 *                generator must be supplied in prng. Both kset.padpar and
 *                kset.key_type should be 0 to ensure correct default
 *                behavior. This pad algorithm should only be used for
 *                legacy systems.
 *              - If kset.padalg == &pad_pkcs1null, ALL blocks of data are
 *                padded on the left with null bytes. The padding takes up
 *                four bytes in all but the final block, and enough bytes
 *                to fill the final block up to the modulus size. Both
 *                kset.padpar and kset.key_type should be 0. This form of
 *                padding should only be used when encrypting a single block.
 *              - If kset.padalg == &pad_pkcs1, ALL blocks of data are
 *                padded on the left using random data. At least 11 bytes
 *                of pad data are added to every block. A random number
 *                generator must be provided in prng. If (for some reason)
 *                you are encrypting using the PRIVATE key,
 *                kset.padpar->key_type should be PAD_PRIVATE and
 *                kset.key_type should be 0. Otherwise, set kset.padpar and
 *                kset.key_type to 0 to ensure correct default behavior.
 *                This form of padding should only be used when encrypting
 *                a single block. Note that this is PKCS#1 version 1
 *                padding and new applications should use &pad_oaep_pkcs1
 *                unless backwards compatibility is important.
 *              - If kset.padalg == &pad_oaep_set1, padding is as described
 *                in the SET standard. All encryption blocks are padded. A
 *                random number generator must be provided in prng. When
 *                encrypting, the padding mechanism adds null bytes to fill
 *                the encryption block. When decrypting, however, it does
 *                NOT remove these null bytes. The decrypted data that is
 *                output from bsapi_finish_rsa() will always be 17 bytes
 *                shorter than the length of the modulus and will have
 *                trailing null bytes which must be removed explicitly.
 *                kset.padpar is ignored and safely be set to 0. This form
 *                of padding should only be used when encrypting a single block.
 *              - If kset.padalg == &pad_oaep_pkcs1, padding is as
 *                described in PKCS#1 version 2. This is the recommended
 *                version of padding for new applications that encrypt with
 *                RSA. A random number generator must be provided in prng.
 *                The padding algorithm takes several parameters, but if
 *                kset.padpar is set to 0 it uses the default parameters
 *                given in PKCS#1 version 2. This is the recommended course
 *                of action. Unlike the &pad_oaep_set1 case, the data is
 *                fully unpadded on decryption.
 *              - In debug mode, if kset.padalg is not one of the above values,
 *                bsapi_start_rsa() will throw an error.
 * Authentication: The following fields must be set.
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_SIGN or BSAPI_VERIFY.
 *              - kset.keys contains the key data. This is a pointer to a
 *                ut_mblk which contains an RSA private key (when signing)
 *                or an RSA public key (when verifying).
 *              - kset.hashalg is the hash algorithm to use. If you are
 *                padding with PKCS#1 this MUST be specified, even if
 *                the data you are passing in has already been hashed.
 *                PKCS#1 needs this information to perform the padding.
 *              - kset.data_type indicates what kind of data is being
 *                passed into the authentication session. If kset.data_type
 *                == BSAPI_DATA_TYPE_DATA or BSAPI_DATA_TYPE_DEFAULT (= 0),
 *                the data is hashed inside the RSA session. In this case,
 *                kset.hashalg must be specified. If kset.data_type ==
 *                BSAPI_DATA_TYPE_HASH, the data passed in to
 *                bsapi_append_rsa is assumed to have been hashed already
 *                and is not processed further (though it may still be
 *                necessary to specify.hashalg when padding with &pad_pkcs1).
 *              - The rest of the required information is conveyed in two
 *                other fields. kset.padalg tells the session how to format
 *                the hashed data before encrypting with the private key,
 *                or how to recover the hash data after decrypting with the
 *                public key. kset.padpar contains any parameters that may
 *                be required by the indicated padding algorithm.
 *              - If kset.padalg == 0 then kset.padpar is ignored. The hash
 *                data is padded on the RIGHT with null bytes to bring it
 *                up to the length of the modulus. So "hello" doesn't become
 *                the integer represented by "...000hello" but instead
 *                "hello000...". If the data is formatted into a block the
 *                length of the modulus when it is passed to bsapi_append_rsa,                
 *                this will prevent any padding happening at all.
 *              - If kset.padalg == &pad_brsa, the hash data is padded on
 *                the left with random bytes. A random number generator
 *                must be supplied in prng. Both kset.padpar and
 *                kset.key_type should be 0 to ensure correct default
 *                behavior. This pad algorithm should only be used for
 *                legacy systems.
 *              - If kset.padalg == &pad_brsaorig, the hash data is padded
 *                on the left with random bytes. A random number generator
 *                must be supplied in prng. Both kset.padpar and
 *                kset.key_type should be 0 to ensure correct default
 *                behavior. This pad algorithm should only be used for
 *                legacy systems.
 *              - If kset.padalg == &pad_pkcs1null, the hash data is padded
 *                on the left with null bytes. Both kset.padpar and
 *                kset.key_type should be 0.
 *              - If kset.padalg == &pad_pkcs1, the hash data is padded as
 *                described in PKCS#1 (both version 1.x and version 2). In
 *                this case, an algorithm identifier for the hash function
 *                is prepended to the hash data before it is encrypted with
 *                the private key. If keys.hashalg is set,
 *                bsapi_finish_rsa() will prepend the relevant algorithm
 *                identifier. If keys.hashalg is 0, bsapi_finish_rsa() will
 *                assume that the algorithm identifier has been prepended
 *                externally. When verifying, bsapi_finish_rsa() will check
 *                for the presence of the algorithm identifier if and only
 *                if keys.hashalg is nonzero.
 *              - In debug mode, if kset.padalg is not one of the above values,
 *                bsapi_start_rsa() will throw an error.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_rsa() or
 *              bsapi_kill_rsa(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_rsa(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_rsa()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_rsa() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory,
 *              problems hashing the data or if a hashing algorithm hasn't been
 *              specified when kset.data_type == BSAPI_DATA_TYPE_HASH. Also
 *              returns 0 if passed null key data or (in debug mode) an
 *              incorrect padding algorithm.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_rsa(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);

/* Function:    <bsapi_append_rsa>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_rsa(u8 *ptr, size_t len, bsapi_id sid);
 * Description: We describe encryption and authentication sessions separately.
 * Encryption:  The bsapi_append_rsa() function writes len octets from ptr
 *              into a bsapi RSA encryption session sid. The processed data
 *              is held inside the session until a successful call to
 *              bsapi_readmost_rsa(), bsapi_read_rsa(), or
 *              bsapi_finish_rsa(). Depending on the padding algorithm
 *              used, padding may be performed inside this function as well
 *              as inside bsapi_finish_rsa(); see bsapi_start_rsa() for
 *              details. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_rsa() function.
 * Authentication: The bsapi_append_rsa() function writes len octets from
 *              ptr into the bsapi RSA authentication session sid. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rsa() function. 
 *              - If the session is expecting message data (if
 *                kset.data_type in bsapi_start_rsa() was
 *                BSAPI_DATA_TYPE_DATA or BSAPI_DATA_TYPE_DEFAULT) the data
 *                is passed to the internal hash session which was
 *                indicated by kset.hashalg. 
 *              - If the session is expecting an already calculated hash
 *                (if kset.data_type in bsapi_start_rsa() was
 *                BSAPI_DATA_TYPE_HASH), this function may only be called
 *                once. The ptr argument should contain the hash data and
 *                the len argument should give the length of the hash. If
 *                this function is called again it returns -1 with the
 *                error message "Hash data already read into RSA session",
 *                and the data is ignored.
 * Returns:     0 on success or -1 on failure due to lack of memory. Returns
 *              -1 if either ptr or data is null.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_rsa(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_rsa>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_rsa(bsapi_id sid);
 * Description: The bsapi_read_rsa() function reads all available data from
 *              a bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_rsa() function. If
 *              a padding algorithm was specified on the call to
 *              bsapi_start_rsa(), the appropriate unpadding will be performed.
 * 
 *              When authenticating, this function does nothing and returns 0.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a 
 *              null sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None.
 * Notes:       The function always returns 0 if called in the middle of a
 *              signing or verification session.
 *
 *              You should never have to call this function, as you should
 *              only be encrypting one block at a time with RSA. A simple
 *              start-append-finish should cover almost all cases.
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_rsa(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_rsa>
 * Summary:     Gives size of output that can be safely read from an RSA
 *              encryption or decryption session if input bytes are fed to the
 *              session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_rsa(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_rsa() function gives the length of 
 *              output that would be produced by a call to bsapi_readmost_rsa() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_rsa().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid or if called during an RSA signing or
 *              verification session.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_rsa(size_t input, bsapi_id session);

/* Function:    <bsapi_readmost_rsa>
 * Summary:     Reads as much processed data as is safe from an 
 *              encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_rsa(bsapi_id sid);
 * Description: The bsapi_readmost_rsa() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_rsa() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_rsa() function. 
 * 
 *              When authenticating, this function does nothing and returns 0.
 * Returns:     A ut_mblk_list containing the processed data. Returns 0 if
 *              passed a null sid. If the force field has not been set, 
 *              the bsapi_readmost_rsa() function also returns 0 if no
 *              data is available.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None.
 * Notes:       The function always returns 0 if called in the middle of a
 *              signing or verification session.
 *
 *              You should never have to call this function, as you should
 *              only be encrypting one block at a time with RSA. A simple
 *              start-append-finish should cover almost all cases.
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_rsa(bsapi_id session);


/* Function:    <bsapi_finish_rsa>
 * Summary:     Finishes a bsapi session using RSA, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_rsa(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: We describe encryption/decryption, signing. and
 *              authentication sessions separately.
 * Encryption:  The bsapi_finish_rsa() function finishes the bsapi session
 *              sid for rsa. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_rsa() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rsa() function. On successful
 *              completion, mlist will contain all of the processed data
 *              which has not been output in previous calls to
 *              bsapi_read_rsa() or bsapi_readmost_rsa(). On decryption,
 *              the data is fully unpadded, except in two cases:
 *              - If kset.padalg was 0 in the call to bsapi_start_rsa(), no
 *                unpadding is performed.
 *              - If kset.padalg was &pad_oaep_set1 in the call to
 *                bsapi_start_rsa(), the plaintext in the final block of
 *                mlist may have trailing 0 bytes which must be removed
 *                manually.
 * Signing:     The bsapi_finish_rsa() function finishes the bsapi session sid
 *              for rsa. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_rsa() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rsa() function. On successful
 *              completion, mlist will contain a ut_mblk_list with a single
 *              member (mlist->prev = mlist; mlist->next = 0). The
 *              signature data is at mlist->block.data and is of length
 *              mlist->block.used. The signature data is simply the raw RSA
 *              ciphertext; it is not ASN.1 formatted in any way.
 * Verifying:   The bsapi_finish_rsa() function finishes the bsapi session
 *              sid for rsa. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_rsa() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rsa() function. When verifying, the
 *              signature to be verified must be passed into the function
 *              in mlist (see the Example). This signature must be raw RSA
 *              ciphertext as produced by bsapi_rsa when signing. The
 *              bsapi_finish_rsa() function checks to see if the signature
 *              is valid for the message or hash which was passed into
 *              bsapi_append_rsa(). It returns
 * Returns:     0 if the signature is correct
 *              -1 if there was an internal error
 *              1 if the signature decrypted correctly, but the hashes
 *                didn't match (implying that the message has been tampered
 *                with)
 *              2 if the signature failed to decrypt (implying that the
 *                signature itself has been tampered with, or that the
 *                wrong public key was supplied. There is no way to
 *                distinguish between these two cases). 
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_rsa(bsapi_id session, ut_mblk_list *data);



/* Function:    <bsapi_sizeof_output_rsa>
 * Summary:     Gives the amount of output from a given input to an RSA
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_rsa(bsapi_id sid,
 *                off_t inqty);
 * Description: The bsapi_sizeof_output_rsa() function returns the maximum
 *              amount of output which could be produced if inqty octets of
 *              data were input into the session sid.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_rsa(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_rsa>
 * Summary:     Kills an RSA session, releasing all resources.
 * Syntax:      bsapi_kill_rsa(bsapi_id sid);
 * Description: The bsapi_kill_rsa() function shuts down a bsapi_rsa
 *              session sid, freeing all memory associated with the session
 *              and returning no output. It is for use when it is necessary
 *              to terminate a session unfinished. The session ID sid must
 *              have originally been returned from a call to the
 *              bsapi_start_rsa() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function RSA-encrypts (or decrypts, depending
 *              on the op parameter) stdin to stdout using the supplied key
 *              and prng_inst *; it shows how to construct a mode structure
 *              and key set, how to start an algorithm and write/read as
 *              data becomes available, and how to exit gracefully in case of
 *              external problems (it uses ut_log() for error reporting,
 *              and returns 0 on failure, or -1 on sucess):
 *           (code)
 *               int
 *               rsafunc(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up RSA encryption, plain key, PKCS#1 padding 
 *                 md.op = op;
 *                 keys.keys = key;
 *                 keys.padalg = &pad_pkcs1;
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_rsa(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_CONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_rsa(buf, len, sid)) {
 *                     bsapi_kill_rsa(sid);
 *                     ut_log0(0UL, UT_CONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_rsa(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_rsa(sid, &cyph)) {
 *                   // even if bsapi_finish_rsa() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_rsa() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                  }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 */

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_rsa(bsapi_id session);


/* Function:    <bsapi_get_name_rsa>
 * Summary:     Returns bsapi_rsa.name.
 * Syntax:      const char *rval = bsapi_get_name_rsa();
 * Description: The bsapi_get_name_rsa() function returns the bsapi_rsa.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_rsa(void);


/* Function:    <rsa_direct>
 * Summary:     Simply calls bsapi_append_rsa().
 * Syntax:      rsa_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The rsa_direct() function calls the function bsapi_append_rsa()
 *              and sets output to 0. The function does nothing if passed
 *              a null sid.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    rsa_direct(bsapi_id session, u8 *in, u8 *out, size_t len);

/* Function:    <set_prng_rsa>
 * Summary:     Sets RSA session prng.
 * Syntax:      int rval = set_prng_rsa(prng_inst *prng, bsapi_id session);
 * Description: The set_prng_rsa() function sets the supplied prng as the RSA
 *              session prng.
 * Returns:     This function returns 0 on success or -1 if the session is null.
 */

extern int
  CST32EXPORTTYPE CST16EXPORTTYPE
    set_prng_rsa(prng_inst *prng, bsapi_id session);


/* Data:        <bsapi_rsa>
 * Summary:     Function pointers for RSA bsapi routines
 * Notes:       The ut_choose() name for this structure is "RSA".
 */

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_rsa;


#endif /* WITH_bsapi_rsa */

#ifdef WITH_bsapi_bsa4

/* Function:    <bsapi_generate_sharedparams_bsa4>
 * Summary:     Not applicable to the BSA4 algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_bsa4(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_bsa4() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_bsa4(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_bsa4>
 * Summary:     Generates a key for BSA4.
 * Syntax:      int rval = bsapi_generate_key_bsa4(prng_inst *prng,
 *              (ut_mblk *) &spt, 0, 0);
 * Description: The bsapi_generate_key_bsa4() function generates a 92-byte
 *              BSA4 key. The key is written to spt.data, where memory is
 *              allocated, and spt.size and spt.used are set accordingly. 
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or problems with the prng. Also, returns -1 if prng, 
 *              or spt is 0.
 *
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)
 */  

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_bsa4(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_bsa4>
 * Summary:     Not applicable to the BSA4 algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_bsa4(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_bsa4() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_bsa4 (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_bsa4>
 * Summary:     Not applicable to the BSA4 algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_bsa4((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_bsa4() function does nothing and returns 0.
 * Returns:     0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_bsa4(bsapi_mode *mode, bsapi_kset *keys);



/* Function:    <bsapi_start_bsa4>
 * Summary:     Starts a BSA4 session.
 * Syntax:      bsapi_id sid = bsapi_start_bsa4((bsapi_mode *) &bmode, 0,
 *              (bsapi_kset *) &kset);
 * Description: The bsapi_start_bsa4() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - kset.keys contains the key data. This is a pointer to a
 *                ut_mblk which contains 92 bytes of random data.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_bsa4() or
 *              bsapi_kill_bsa4(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_bsa4(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_bsa4()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_bsa4() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              an incorrect key length. Also returns 0 if
 *              kset.keys is null or (in debug mode) if bmode.op is not 
 *              BSAPI_ENCRYPT or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_bsa4(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_bsa4>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_bsa4(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_bsa4() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held inside
 *              the session until a successful call to
 *              bsapi_readmost_bsa4(), bsapi_read_bsa4(), or
 *              bsapi_finish_bsa4(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_bsa4() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if either ptr or sid is null.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_bsa4(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_bsa4>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_bsa4(bsapi_id sid);
 * Description: The bsapi_read_bsa4 function reads all available data from
 *              a bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_bsa4() function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_bsa4(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_bsa4>
 * Summary:     Gives size of output from bsapi_readmost_bsa4()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_bsa4(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_bsa4() function gives the length of output that 
 *              that would be produced by a call to bsapi_readmost_bsa4() 
 *              subsequent to input bytes of data being fed to the session sid with 
 *              a call to bsapi_append_bsa4().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_bsa4(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_bsa4>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_bsa4(bsapi_id sid);
 * Description: The bsapi_read_bsa4 function reads all available data from
 *              a bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_bsa4() function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       This function simply wraps bsapi_read_bsa4().
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_bsa4(bsapi_id session);


/* Function:    <bsapi_finish_bsa4>
 * Summary:     Finishes a bsapi session using BSA4, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_bsa4(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_bsa4() function finishes the bsapi session
 *              sid for bsa4. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_bsa4() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_bsa4() function. On successful
 *              completion, mlist will contain all of the processed data
 *              which has not been output in previous calls to
 *              bsapi_read_bsa4() or bsapi_readmost_bsa4().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory.
 *              Also returns -1 if passed null parameters.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_bsa4(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_bsa4>
 * Summary:     Gives the amount of output from a given input to a BSA4
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_bsa4(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_bsa4() function returns the maximum
 *              amount of output which could be produced if inqty octets of
 *              data were input into the session sid. This will always be
 *              inqty.
 * Returns:     inqty.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_bsa4(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_bsa4>
 * Summary:     Kills a BSA4 session, releasing all resources.
 * Syntax:      bsapi_kill_bsa4(bsapi_id sid);
 * Description: The bsapi_kill_bsa4() function shuts down a bsapi_bsa4
 *              session sid, freeing all memory associated with the session
 *              and returning no output. It is for use when it is necessary
 *              to terminate a session unfinished. The session ID sid must
 *              have originally been returned from a call to the
 *              bsapi_start_bsa4() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function BSA4-encrypts (or decrypts,
 *              depending on the op parameter) stdin to stdout using the
 *              supplied key and prng_inst *; it shows how to construct a
 *              mode structure and key set, how to start an algorithm and
 *              write/read as data becomes available, and how to exit
 *              gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on success or -1 on 
 *              failure):
 *           (code)
 *               int
 *               bsa4func(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up BSA4, plain key 
 *                 md.op = op;
 *                 keys.keys = key; // Only relevant field 
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_bsa4(&md, prng, &keys))) 
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_bsa4(buf, len, sid)) {
 *                     bsapi_kill_bsa4(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_bsa4(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_bsa4(sid, &cyph)) {
 *                   // even if bsapi_finish_bsa4() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_bsa4() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                  }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 */

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_bsa4(bsapi_id session);

/* Function:    <bsapi_get_name_bsa4>
 * Summary:     Returns bsapi_bsa4.name.
 * Syntax:      const char *rval = bsapi_get_name_bsa4();
 * Description: The bsapi_get_name_bsa4() function returns the bsapi_bsa4.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_bsa4(void);


/* Function:    <bsa4_direct>
 * Summary:     Implements the BSA4 algorithm.
 * Syntax:      bsa4_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The bsa4_direct() function feeds length octets of data from
 *              input into the BSA4 session sid and writes the processed data 
 *              to output. The function does nothing if passed a null sid.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsa4_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_bsa4>
 * Summary:     Function pointers for BSA4 bsapi routines
 * Notes:       The ut_choose() name for this structure is "BSA4".
 */

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_bsa4;

#endif /* WITH_bsapi_bsa4 */

#ifdef WITH_bsapi_bsa5

/* Function:    <bsapi_generate_sharedparams_bsa5>
 * Summary:     Not applicable to the BSA4 algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_bsa5(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_bsa5() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_bsa5(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_bsa5>
 * Summary:     Generates a key for BSA5.
 * Syntax:      int rval = bsapi_generate_key_bsa5(prng_inst *prng,
 *              (ut_mblk *) &spt, 0, 0);
 * Description: The bsapi_generate_key_bsa5() function generates a 256-byte
 *              BSA5 key. The key is written to spt.data, where memory is
 *              allocated, and spt.size and spt.used are set accordingly. 
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory.
 *              Also returns -1 if prng or spt is 0.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)   
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_bsa5(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_bsa5>
 * Summary:     Not applicable to the BSA5 algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_bsa5(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_bsa5() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_bsa5 (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_bsa5>
 * Summary:     Not applicable to the BSA5 algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_bsa5((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_bsa5() function does nothing and returns 0.
 * Returns:     0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_bsa5(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_bsa5>
 * Summary:     Starts a BSA5 session.
 * Syntax:      bsapi_id sid = bsapi_start_bsa5((bsapi_mode *) &bmode, 0,
 *              (bsapi_kset *) &kset);
 * Description: The bsapi_start_bsa5() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - kset.keys contains the key data. This is a pointer to
 *                a ut_mblk which contains 256 bytes of random data.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_bsa5() or
 *              bsapi_kill_bsa5(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_bsa5(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_bsa5()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_bsa5() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              incorrect key length. Also returns 0 if passed null
 *              key data or (in debug mode) if bmode.op is not BSAPI_ENCRYPT
 *              or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_bsa5(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_bsa5>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_bsa5(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_bsa5() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_bsa5(), bsapi_read_bsa5(), or
 *              bsapi_finish_bsa5(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_bsa5() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if either ptr or sid is null.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_bsa5(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_bsa5>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_bsa5(bsapi_id sid);
 * Description: The bsapi_read_bsa5 function reads all available data from
 *              a bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_bsa5()
 *              function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a 
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_bsa5(bsapi_id session);


/* Function:    <bsapi_sizeof_readmost_bsa5>
 * Summary:     Gives size of output from bsapi_readmost_bsa5()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_bsa5(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_bsa5() function gives the length of output that 
 *              that would be produced by a call to bsapi_readmost_bsa5() 
 *              subsequent to input bytes of data being fed to the session sid with 
 *              a call to bsapi_append_bsa5().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_bsa5(size_t input, bsapi_id session);



/* Function:    <bsapi_readmost_bsa5>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_bsa5(bsapi_id sid);
 * Description: The bsapi_read_bsa5 function reads all available data from
 *              a bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_bsa5()
 *              function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None.
 * Notes:       This function simply wraps bsapi_read_bsa5().
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_bsa5(bsapi_id session);


/* Function:    <bsapi_finish_bsa5>
 * Summary:     Finishes a bsapi session using BSA5, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_bsa5(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_bsa5() function finishes the bsapi session
 *              sid for bsa5. The memory pointed to by sid is
 *              deallocated following a call to bsapi_finish_bsa5()
 *              whether the return value from the function indicates
 *              success or not. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_bsa5()
 *              function. On successful completion, mlist will contain
 *              all of the processed data which has not been output in
 *              previous calls to bsapi_read_bsa5() or
 *              bsapi_readmost_bsa5().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory.
 *              Also returns -1 on null parameters.  
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_bsa5(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_bsa5>
 * Summary:     Gives the amount of output from a given input to a BSA5
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_bsa5(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_bsa5() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This will
 *              always be inqty.
 * Returns:     inqty.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_bsa5(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_bsa5>
 * Summary:     Kills a BSA5 session, releasing all resources.
 * Syntax:      bsapi_kill_bsa5(bsapi_id sid);
 * Description: The bsapi_kill_bsa5() function shuts down a bsapi_bsa5
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_bsa5() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function BSA5-encrypts (or decrypts,
 *              depending on the op parameter) stdin to stdout using the
 *              supplied key and prng_inst *; it shows how to construct
 *              a mode structure and key set, how to start an algorithm
 *              and write/read as data becomes available, and how to
 *              exit gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on failure, or -1 on
 *              success):
 *           (code)
 *               int
 *               bsa5func(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up BSA5, plain key
 *                 md.op = op;
 *                 keys.keys = key; // Only relevant field 
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_bsa5(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_bsa5(buf, len, sid)) {
 *                     bsapi_kill_bsa5(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_bsa5(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_bsa5(sid, &cyph)) {
 *                   // even if bsapi_finish_bsa5() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_bsa5() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               {
 *           (/code)
 */

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_bsa5(bsapi_id session);

/* Function:    <bsapi_get_name_bsa5>
 * Summary:     Returns bsapi_bsa5.name.
 * Syntax:      const char *rval = bsapi_get_name_bsa5();
 * Description: The bsapi_get_name_bsa5() function returns the bsapi_bsa5.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_bsa5(void);


/* Function:    <bsa5_direct>
 * Summary:     Implements the BSA5 algorithm.
 * Syntax:      bsa5_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The bsa5_direct() function feeds length octets of data from
 *              input into the BSA5 session sid and writes the processed data 
 *              to output. The function does nothing if passed a null sid.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsa5_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_bsa5>
 * Summary:     Function pointers for BSA5 bsapi routines
 * Notes:       The ut_choose() name for this structure is "BSA5".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_bsa5;

#endif /* WITH_bsapi_bsa5 */

#ifdef WITH_bsapi_idea

/* Function:    <bsapi_generate_sharedparams_idea>
 * Summary:     Not applicable to the IDEA algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_idea(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_idea() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_idea(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);

/* Function:    <bsapi_generate_key_idea>
 * Summary:     Generates a key for IDEA.
 * Syntax:      int rval = bsapi_generate_key_idea(prng_inst *prng,
 *              (ut_mblk *) &spt, 0, 0);
 * Description: The bsapi_generate_key_idea() function generates a 16-byte
 *              IDEA key. The key is written to spt.data, where memory
 *              is allocated, and spt.size and spt.used are set
 *              accordingly. 
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory.
 *              Also returns -1 if prng or spt is 0.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)     
 * Notes:       There is a class of weak keys for IDEA, but the chance of
 *              obtaining one at random is one in 2^75 so this function
 *              does not check for them.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_idea(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_idea>
 * Summary:     Not applicable to the IDEA algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_idea(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_idea() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_idea (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_idea>
 * Summary:     Gets length of initialization vector for IDEA.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_idea((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_idea() function returns the number of
 *              octets of memory that must be allocated to hold the
 *              initialization vector for the algorithm idea when it is
 *              used according to bmode. 
 *              - If bmode.mode = BSAPI_ECB it returns 0.
 *              - Otherwise it returns 8.
 * Returns:     The number of octets of memory that must be allocated to
 *              hold the initialization vector for the algorithm IDEA. Returns
 *              0 if &bmode is 0.
 * Errors:      Does not fail.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_idea(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_idea>
 * Summary:     Starts an IDEA session.
 * Syntax:      bsapi_id sid = bsapi_start_idea((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_idea() function, given operation mode
 *              information bmode, the associated key information kset,
 *              and a prng_inst * prng, creates and returns a new
 *              session to perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important
 *                field the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - bmode.mode may be any one of BSAPI_ECB, BSAPI_CBC,
 *                BSAPI_CFB and BSAPI_OFB. If it is anything other than
 *                BSAPI_ECB, kset.iv must be set. If it is BSAPI_CFB or
 *                BSAPI_OFB, kset.feedback must also be set
 *              - bmode.triple may be BSAPI_SINGLE, BSAPI_TRIPLE or
 *                BSAPI_CHAIN3. Depending on this, kset.keys will contain
 *                one or three ut_mblks ontaining the key data. See the
 *                item on kset.keys below for more details.
 *              - bmode.key_type may be BSAPI_KEY ( = 0 ) or
 *                BSAPI_SCHEDULE. The use of BSAPI_SCHEDULE is
 *                deprecated.
 *              - prng_inst * must be provided if kset.padalg = &pad_bdes.
 *                In all other cases it can be set to 0.
 *              - kset.keys contains the key data. If bmode.triple =
 *                BSAPI_SINGLE, kset.keys must contain a ut_mblk * with
 *                kset.keys->used = 8 and kset.keys->data containing 8
 *                bytes of data. If bmode.triple = BSAPI_TRIPLE or
 *                BSAPI_CHAIN3, kset.keys must be an array of three
 *                ut_mblks, each containing eight bytes of data (to use
 *                two-key triple IDEA, simply set the third ut_mblk's
 *                data field to be the same as the first one's with
 *                kset.keys[2].data = kset.keys[0].data). 
 *              - kset.iv contains the initialization vector (IV) data and
 *                must be set if bmode.mode = BSAPI_CBC, BSAPI_CFB or
 *                BSAPI_OFB. Its contents depend on bmode.triple. If
 *                bmode.triple = BSAPI_SINGLE or BSAPI_TRIPLE, kset.iv
 *                must contain a ut_mblk * with kset.iv->used = 8 and 8
 *                octets of data at kset->iv.data. If bmode.triple =
 *                BSAPI_CHAIN3, kset.iv points to the start of an array
 *                of three ut_mblks, each containing an eight-byte IV.
 *              - kset.feedback must be set if bmode.mode = BSAPI_CFB or
 *                BSAPI_OFB. For OFB mode, it should be set to 64. For
 *                CFB, it can be set to any value between 1 and 64; the
 *                higher the value the faster the algorithm will run.
 *              - kset.padalg may be 0, &pad_bdes or &pad_pkcs5. &pad_pkcs5
 *                provides the widely-used PKCS-5 style padding (now
 *                also specified in standards such as S/MIME). If
 *                kset.padalg = 0, the data will be padded on encryption
 *                by appending null bytes to the end of the final
 *                encryption block if this is necessary to bring the
 *                data up to a multiple of 8 bytes long. If kset.padalg
 *                = 0, no unpadding is performed on decryption. If
 *                you're using kset.padalg = 0, therefore, you should
 *                ensure that your data is an exact multiple of eight
 *                bytes in length.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_idea() or
 *              bsapi_kill_idea(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_idea(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_idea()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_idea() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              incorrect key length. Also returns 0 if passed null
 *              key data or (in debug mode) if bmode.op is not BSAPI_ENCRYPT
 *              or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_idea(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_idea>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_idea(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_idea() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_idea(), bsapi_read_idea(), or
 *              bsapi_finish_idea(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_idea() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if the session or data passed is NULL.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_idea(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_idea>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_idea(bsapi_id sid);
 * Description: The bsapi_read_idea function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_idea() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_idea().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */


extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_idea(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_idea>
 * Summary:     Gives size of output from bsapi_readmost_idea()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_idea(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_idea() function gives the length of output that 
 *              that would be produced by a call to bsapi_readmost_idea() 
 *              subsequent to input bytes of data being fed to the session sid with 
 *              a call to bsapi_append_idea().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_idea(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_idea>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_idea(bsapi_id sid);
 * Description: The bsapi_readmost_idea() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_idea() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_idea() function. 
 *
 *              This function is preferred to bsapi_read_idea() for all normal
 *              operations. 
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_idea(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_idea(data, len, sid);
 *                 output = bsapi_readmost_idea(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_idea(sid);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       When it is running in ECB or CBC mode the function leaves the
 *              final 8 bytes inside the session if the session is decrypting.
 * Example:     See bsapi_kill_idea().
 */
 

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_idea(bsapi_id session);

/* Function:    <bsapi_finish_idea>
 * Summary:     Finishes a bsapi session using IDEA, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_idea(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_idea() function finishes the bsapi session
 *              sid for idea. The memory pointed to by sid is
 *              deallocated following a call to bsapi_finish_idea()
 *              whether the return value from the function indicates
 *              success or not. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_idea()
 *              function. On successful completion, mlist will contain
 *              all of the processed data which has not been output in
 *              previous calls to bsapi_read_idea() or
 *              bsapi_readmost_idea().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or failure in unpadding. Also returns -1 on null
 *              parameters.   
 * Example:     See bsapi_kill_idea().
 */
 

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_idea(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_idea>
 * Summary:     Gives the amount of output from a given input to an IDEA
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_idea(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_idea() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This does not
 *              include the effects of any data that is buffered inside
 *              the session. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_idea()
 *              function.
 * Returns:     The maximum size of output for the given size of input. Returns
 *              -1 on null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_idea(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_idea>
 * Summary:     Kills an IDEA session, releasing all resources.
 * Syntax:      bsapi_kill_idea(bsapi_id sid);
 * Description: The bsapi_kill_idea() function shuts down a bsapi_idea
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_idea() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function IDEA-encrypts (or decrypts,
 *              depending on the op parameter) stdin to stdout using the
 *              supplied key and prng_inst *; it shows how to construct
 *              a mode structure and key set, how to start an algorithm
 *              and write/read as data becomes available, and how to
 *              exit gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on failure, or -1 on
 *              success):
 *           (code)
 *               int
 *               ideafunc(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up single ECB IDEA, plain key, PKCS#5 padding 
 *                 md.op = op;
 *                 keys.keys = key;
 *                 keys.padalg = &pad_pkcs5;
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_idea(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_idea(buf, len, sid)) {
 *                     bsapi_kill_idea(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_idea(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_idea(sid, &cyph)) {
 *                   // even if bsapi_finish_idea() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_idea() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_idea(bsapi_id session);

/* Function:    <bsapi_get_name_idea>
 * Summary:     Returns bsapi_idea.name.
 * Syntax:      const char *rval = bsapi_get_name_idea();
 * Description: The bsapi_get_name_idea() function returns the bsapi_idea.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_idea(void);


/* Function:    <idea_direct>
 * Summary:     Implements the IDEA algorithm.
 * Syntax:      idea_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The idea_direct() function feeds length octets of data from
 *              input into the IDEA session sid and writes the processed data 
 *              to output. The function does nothing if passed null parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    idea_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_idea>
 * Summary:     Function pointers for IDEA bsapi routines
 * Notes:       The ut_choose() name for this structure is "IDEA".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_idea;

/* Auxiliary function support */

/* Function:    <idea_reset>
 * Summary:     Changes the key and/or initialization vector in a
 *              bsapi session.
 * Syntax:      int rval = idea_reset(bsapi_id sid, ut_mblk *ivnew, 
 *                ut_mblk *keynew, bsapi_mode_key_type keynewtype);
 * Description: The idea_reset() function replaces the key and/or initialization
 *              vector being used in the IDEA session sid with keynew and/or
 *              ivnew.
 * Returns:     0 on success, -1 on failure due to key or initialization vector
 *              having incorrect length. Also returns -1 if sid is null.
*/

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    idea_reset(bsapi_id session, ut_mblk *iv, ut_mblk *key,
    bsapi_mode_key_type kt);

#endif /* WITH_bsapi_idea */

#ifdef WITH_bsapi_rc2

/* Function:    <bsapi_generate_sharedparams_rc2>
 * Summary:     Not applicable to the RC2 algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_rc2(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_rc2() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_rc2(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_rc2>
 * Summary:     Generates a key for RC2.
 * Syntax:      int rval = bsapi_generate_key_rc2(prng_inst *prng, 
 *              (ut_mblk *) &spt, 0, bsapi_kparam *param);
 * Description: The bsapi_generate_key_rc2() function generates an RC2 key. 
 *              The length of the key in bits is given by param->rc2.size.
 *              If this length in bits does not correspond to an even number 
 *              of bytes, the leading bits are set to zero. The key is written 
 *              to spt.data, where memory is allocated, and spt.size and 
 *              spt.used are set accordingly. The key must be between 1 and
 *              1024 bits in length.
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory,
 *              problems with the prng or an incorrect key length. Also 
 *              returns -1 if prng, param or spt is 0.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)      
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_rc2(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_rc2>
 * Summary:     Not applicable to the RC2 algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_rc2(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_rc2() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_rc2 (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_rc2>
 * Summary:     Gets length of initialization vector for RC2.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_rc2((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_rc2() function returns the number of
 *              octets of memory that must be allocated to hold the
 *              initialization vector for the algorithm RC2 when it is used
 *              according to bmode. 
 *              - If bmode.mode = BSAPI_ECB it returns 0.
 *              - Otherwise it returns 8.
 * Returns:     The number of octets of memory that must be allocated to
 *              hold the initialization vector for the algorithm RC2. Returns
 *              0 if &bmode is 0.
 * Errors:      Does not fail.      
 */


extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_rc2(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_rc2>
 * Summary:     Starts an RC2 session.
 * Syntax:      bsapi_id sid = bsapi_start_rc2((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_rc2() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important
 *                field the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - bmode.mode may be any one of BSAPI_ECB, BSAPI_CBC,
 *                BSAPI_CFB and BSAPI_OFB. If it is anything other than
 *                BSAPI_ECB, kset.iv must be set. If it is BSAPI_CFB or
 *                BSAPI_OFB, kset.feedback must also be set
 *              - bmode.triple may be BSAPI_SINGLE, BSAPI_TRIPLE or
 *                BSAPI_CHAIN3. Depending on this, kset.keys will contain
 *                one or three ut_mblks ontaining the key data. See the
 *                item on kset.keys below for more details.
 *              - bmode.key_type must be set to BSAPI_KEY ( = 0).
 *              - prng_inst * must be provided if kset.padalg = &pad_bdes.
 *                In all other cases it can be set to 0.
 *              - kset.keys contains the key data. If bmode.triple =
 *                BSAPI_SINGLE, kset.keys must contain a ut_mblk * with
 *                kset.keys->used = 8 and kset.keys->data containing 8
 *                bytes of data. If bmode.triple = BSAPI_TRIPLE or
 *                BSAPI_CHAIN3, kset.keys must be an array of three
 *                ut_mblks, each containing eight bytes of data (to use
 *                two-key triple RC2, simply set the third ut_mblk's
 *                data field to be the same as the first one's with
 *                kset.keys[2].data = kset.keys[0].data). 
 *              - kset.effbits must be set to the required "effective key
 *                length" in bits. The value of the kset.effbits
 *                field should always be less than or equal to the
 *                length in bits of your raw key material. Typical values
 *                are 40, 64 and 128.
 *              - kset.iv contains the initialization vector (IV) data and
 *                must be set if bmode.mode = BSAPI_CBC, BSAPI_CFB or
 *                BSAPI_OFB. Its contents depend on bmode.triple. If
 *                bmode.triple = BSAPI_SINGLE or BSAPI_TRIPLE, kset.iv
 *                must contain a ut_mblk * with kset.iv->used = 8 and 8
 *                octets of data at kset->iv.data. If bmode.triple =
 *                BSAPI_CHAIN3, kset.iv points to the start of an array
 *                of three ut_mblks, each containing an eight-byte IV.
 *              - kset.feedback must be set if bmode.mode = BSAPI_CFB or
 *                BSAPI_OFB. For OFB mode, it should be set to 64. For
 *                CFB, it can be set to any value between 1 and 64; the
 *                higher the value the faster the algorithm will run.
 *              - kset.padalg may be 0, &pad_bdes or &pad_pkcs5. &pad_pkcs5
 *                provides the widely-used PKCS-5 style padding (now
 *                also specified in standards such as S/MIME). If
 *                kset.padalg = 0, the data will be padded on encryption
 *                by appending null bytes to the end of the final
 *                encryption block if this is necessary to bring the
 *                data up to a multiple of 8 bytes long. If kset.padalg
 *                = 0, no unpadding is performed on decryption. If
 *                you're using kset.padalg = 0, therefore, you should
 *                ensure that your data is an exact multiple of eight
 *                bytes in length.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_rc2() or
 *              bsapi_kill_rc2(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_rc2(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_rc2()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_rc2() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              if kset.effbits < 40. Also returns 0 if passed null
 *              key data or (in debug mode) if bmode.op is not BSAPI_ENCRYPT
 *              or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_rc2(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_rc2>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_rc2(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_rc2() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_rc2(), bsapi_read_rc2(), or
 *              bsapi_finish_rc2(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_rc2() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if the session or data passed is NULL.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_rc2(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_rc2>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_rc2(bsapi_id sid);
 * Description: The bsapi_read_rc2 function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_rc2() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_rc2().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */
 

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_rc2(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_rc2>
 * Summary:     Gives size of output from bsapi_readmost_rc2()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_rc2(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_rc2() function gives the length of
 *              output that would be produced by a call to bsapi_readmost_rc2() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_rc2().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_rc2(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_rc2>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_rc2(bsapi_id sid);
 * Description: The bsapi_readmost_rc2() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_rc2() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_rc2() function. 
 *
 *              This function is preferred to bsapi_read_rc2() for all normal
 *              operations.
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_rc2(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_rc2(data, len, sid);
 *                 output = bsapi_readmost_rc2(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_rc2(sid);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       When it is running in ECB or CBC mode the function leaves the
 *              final 8 bytes inside the session if the session is decrypting.
 * Example:     See bsapi_kill_rc2().
 */


extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_rc2(bsapi_id session);


/* Function:    <bsapi_finish_rc2>
 * Summary:     Finishes a bsapi session using RC2, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_rc2(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_rc2() function finishes the bsapi session
 *              sid for rc2. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_rc2() whether the
 *              return value from the function indicates success or not.
 *              The session ID sid must have originally been returned
 *              from a call to the bsapi_start_rc2() function. On
 *              successful completion, mlist will contain all of the
 *              processed data which has not been output in previous
 *              calls to bsapi_read_rc2() or bsapi_readmost_rc2().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or failure in unpadding. Also returns -1 on null
 *              parameters.   
 * Example:     See bsapi_kill_rc2().
 */
 

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_rc2(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_rc2>
 * Summary:     Gives the amount of output from a given input to an RC2 
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_rc2(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_rc2() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This does not
 *              include the effects of any data that is buffered inside
 *              the session. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_rc2()
 *              function.
 * Returns:     The maximum size of output for the given size of input. Returns
 *              -1 if passed a null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_rc2(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_rc2>
 * Summary:     Kills an RC2 session, releasing all resources.
 * Syntax:      bsapi_kill_rc2(bsapi_id sid);
 * Description: The bsapi_kill_rc2() function shuts down a bsapi_rc2
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rc2() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function RC2-encrypts (or decrypts, depending
 *              on the op parameter) stdin to stdout using the supplied
 *              key and prng_inst *; it shows how to construct a mode
 *              structure and key set, how to start an algorithm and
 *              write/read as data becomes available, and how to exit
 *              gracefully in case of external problems (it uses ut_log() for
 *              error reporting, and returns 0 on success or -1 on failure):
 *           (code)
 *               int
 *               rc2func(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up single ANSI ECB RC2, plain key, PKCS#5 padding 
 *                 md.op = op;
 *                 keys.keys = key; 
 *                 keys.padalg = &pad_pkcs5;
 *                 keys.effbits = key->used*8; //effective length = key length
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_rc2(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_rc2(buf, len, sid)) {
 *                     bsapi_kill_rc2(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_rc2(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_rc2(sid, &cyph)) {
 *                   // even if bsapi_finish_rc2() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_rc2() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               } 
 *           (/code)
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_rc2(bsapi_id session);

/* Function:    <bsapi_get_name_rc2>
 * Summary:     Returns bsapi_rc2.name.
 * Syntax:      const char *rval = bsapi_get_name_rc2();
 * Description: The bsapi_get_name_rc2() function returns the bsapi_rc2.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_rc2(void);


/* Function:    <bsapi_effbits2params_rc2>
 * Summary:     Used when BER encoding/decoding RC2 params.
 * Description: The RC2 number of effective bits is not
 *              used in the BER-encoded parameters if it is less than 256.
 *              Instead, it is mapped to another number between 0 and
 *              255 using look-up tables, and this is the number that
 *              is encoded. The functions bsapi_effbits2params_rc2() and 
 *              bsapi_params2effbits_rc2() implement the lookup tables.
 *              You should never need to use them directly; they are called              
 *              by algid_aid2beraid() and algid_beraid2aid().
 */

extern u32 bsapi_effbits2params_rc2(u32 effbits);


/* Function:    <bsapi_params2effbits_rc2>
 * Summary:     Used when BER encoding/decoding RC2 params.
 * Description: The RC2 number of effective bits is not
 *              used in the BER-encoded parameters if it is less than 256.
 *              Instead, it is mapped to another number between 0 and
 *              255 using look-up tables, and this is the number that
 *              is encoded. The functions bsapi_effbits2params_rc2() and 
 *              bsapi_params2effbits_rc2() implement the lookup tables.
 *              You should never need to use them directly; they are called              
 *              by algid_aid2beraid() and algid_beraid2aid().
 */

extern u32 bsapi_params2effbits_rc2(u32 params);


/* Function:    <rc2_direct>
 * Summary:     Implements the RC2 algorithm.
 * Syntax:      rc2_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The rc2_direct() function feeds length octets of data from
 *              input into the RC2 session sid and writes the processed data 
 *              to output. The function does nothing if passed null parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    rc2_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_rc2>
 * Summary:     Function pointers for RC2 bsapi routines
 * Notes:       The ut_choose() name for this structure is "RC2".
 */

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_rc2;

#endif /* WITH_bsapi_rc2 */

#ifdef WITH_bsapi_rc4

/* Function:    <bsapi_generate_sharedparams_rc4>
 * Summary:     Not applicable to the RC4 algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_rc4(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_rc4() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_rc4(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_rc4>
 * Summary:     Generates a key for RC4.
 * Syntax:      int rval = bsapi_generate_key_rc4(prng_inst *prng, 
 *              (ut_mblk *) &spt, 0, bsapi_kparam *param);
 * Description: The bsapi_generate_key_rc4() function generates an RC4 key. 
 *              The length of the key in bits is given by param->rc4.size.
 *              If this length in bits does not correspond to an even number 
 *              of bytes, the leading bits are set to zero. The key is written 
 *              to spt.data, where memory is allocated, and spt.size and 
 *              spt.used are set accordingly. The key must be between 1 and 256
 *              bits in length.
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory,
 *              problems with the prng or an incorrect key length. Also
 *              returns -1 if spt, prng or param is null.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_rc4(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_rc4>
 * Summary:     Not applicable to the RC4 algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_rc4(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_rc4() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_rc4 (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_rc4>
 * Summary:     Not applicable to the RC4 algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_rc4((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_rc4() function does nothing and returns 0.
 * Returns:     0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_rc4(bsapi_mode *mode, bsapi_kset *keys);

/* Function:    <bsapi_start_rc4>
 * Summary:     Starts an RC4 session.
 * Syntax:      bsapi_id sid = bsapi_start_rc4((bsapi_mode *) &bmode, 0,
 *              (bsapi_kset *) &kset);
 * Description: The bsapi_start_rc4() function, given operation mode
 *              information bmode, the associated key information kset,
 *              and a prng_inst * prng, creates and returns a new
 *              session to perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important
 *                field the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - kset.keys contains the key data. This is a pointer to a
 *                ut_mblk which contains between 1 and 32 bytes of data
 *                (though usual values are 5, 8 and 16 bytes).
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_rc4() or
 *              bsapi_kill_rc4(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_rc4(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_rc4()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_rc4() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory. Also
 *              returns 0 if passed null key data or (in debug mode) if
 *              bmode.op is not BSAPI_ENCRYPT or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_rc4(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);

/* Function:    <bsapi_append_rc4>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_rc4(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_rc4() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_rc4(), bsapi_read_rc4(), or
 *              bsapi_finish_rc4(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_rc4() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if either ptr or sid is null.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_rc4(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_rc4>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_rc4(bsapi_id sid);
 * Description: The bsapi_read_rc4 function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_rc4()
 *              function.
 * Returns:     A ut_mblk_list containing the processed data. If no data
 *              is available returns 0. Also returns -1 if passed
 *              a NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_rc4(bsapi_id session);


/* Function:    <bsapi_sizeof_readmost_rc4>
 * Summary:     Gives size of output from bsapi_readmost_rc4()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_rc4(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_rc4() function gives the length of 
 *              output that would be produced by a call to bsapi_readmost_bsa4() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_rc4().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_rc4(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_rc4>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_rc4(bsapi_id sid);
 * Description: The bsapi_read_rc4 function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_rc4()
 *              function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns -1 if passed
 *              a NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       This function simply wraps bsapi_read_rc4.
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_rc4(bsapi_id session);


/* Function:    <bsapi_finish_rc4>
 * Summary:     Finishes a bsapi session using RC4, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_rc4(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_rc4() function finishes the bsapi session
 *              sid for rc4. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_rc4() whether the
 *              return value from the function indicates success or not.
 *              The session ID sid must have originally been returned
 *              from a call to the bsapi_start_rc4() function. On
 *              successful completion, mlist will contain all of the
 *              processed data which has not been output in previous
 *              calls to bsapi_read_rc4() or bsapi_readmost_rc4().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory.
 *              Also returns -1 on null parameters.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_rc4(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_rc4>
 * Summary:     Gives the amount of output from a given input to an RC4 
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_rc4(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_rc4() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This will
 *              always be inqty.
 * Returns:     inqty.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_rc4(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_rc4>
 * Summary:     Kills an RC4 session, releasing all resources.
 * Syntax:      bsapi_kill_rc4(bsapi_id sid);
 * Description: The bsapi_kill_rc4() function shuts down a bsapi_rc4
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rc4() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function RC4-encrypts (or decrypts, depending
 *              on the op parameter) stdin to stdout using the supplied
 *              key and prng_inst *; it shows how to construct a mode
 *              structure and key set, how to start an algorithm and
 *              write/read as data becomes available, and how to exit
 *              gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on success or -1 on 
 *              failure):
 *           (code)
 *               int
 *               rc4func(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up RC4, plain key 
 *                 md.op = op;
 *                 keys.keys = key; // Only relevant field 
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_rc4(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_rc4(buf, len, sid)) {
 *                     bsapi_kill_rc4(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_rc4(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_rc4(sid, &cyph)) {
 *                   // even if bsapi_finish_rc4() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_rc4() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               } 
 *           (/code)
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_rc4(bsapi_id session);

/* Function:    <bsapi_get_name_rc4>
 * Summary:     Returns bsapi_rc4.name.
 * Syntax:      const char *rval = bsapi_get_name_rc4();
 * Description: The bsapi_get_name_rc4() function returns the bsapi_rc4.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_rc4(void);


/* Function:    <rc4_direct>
 * Summary:     Implements the RC4 algorithm.
 * Syntax:      rc4_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The rc4_direct() function feeds length octets of data from
 *              input into the RC4 session sid and writes the processed data 
 *              to output. The function does nothing if passed null
 *              parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    rc4_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_rc4>
 * Summary:     Function pointers for RC4 bsapi routines
 * Notes:       The ut_choose() name for this structure is "RC4".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_rc4;

#endif /* WITH_bsapi_rc4 */

#ifdef WITH_bsapi_rc5

/* Function:    <bsapi_generate_sharedparams_rc5>
 * Summary:     Not applicable to the RC5 algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_rc5(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_rc5() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_rc5(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_rc5>
 * Summary:     Generates a key for RC5.
 * Syntax:      int rval = bsapi_generate_key_rc5(prng_inst *prng, 
 *              (ut_mblk *) &spt, 0, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_key_rc5() function generates an RC5 key. 
 *              The length of the key in bits is given by param->rc5.size.
 *              If this length in bits does not correspond to an even number 
 *              of bytes, the leading bits are set to zero. The key is written 
 *              to spt.data, where memory is allocated, and spt.size and 
 *              spt.used are set accordingly. The key must be between 0 and
 *              2040 bits in length.
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory,
 *              problems with the prng or an incorrect key length. Also returns
 *              -1 on null parameters.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_rc5(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_rc5>
 * Summary:     Not applicable to the RC5 algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_rc5(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_rc5() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_rc5 (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_rc5>
 * Summary:     Gets length of initialization vector for RC5.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_rc5((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_rc5() function returns the number of
 *              octets of memory that must be allocated to hold the
 *              initialization vector for the algorithm rc5 when it is used
 *              according to bmode. 
 *              - If bmode.mode = BSAPI_ECB it returns 0.
 *              - Otherwise it returns 8.
 * Returns:     The number of octets of memory that must be allocated to
 *              hold the initialization vector for the algorithm RC5. Returns
 *              0 if &bmode is 0.
 * Errors:      Does not fail.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_rc5(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_rc5>
 * Summary:     Starts an RC5 session.
 * Syntax:      bsapi_id sid = bsapi_start_rc5((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_rc5() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important
 *                field the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - bmode.mode may be any one of BSAPI_ECB, BSAPI_CBC,
 *                BSAPI_CFB and BSAPI_OFB. If it is anything other than
 *                BSAPI_ECB, kset.iv must be set. If it is BSAPI_CFB or
 *                BSAPI_OFB, kset.feedback must also be set
 *              - bmode.triple may be BSAPI_SINGLE, BSAPI_TRIPLE or
 *                BSAPI_CHAIN3. Depending on this, kset.keys will contain
 *                one or three ut_mblks ontaining the key data. See the
 *                item on kset.keys below for more details.
 *              - bmode.key_type must be set to BSAPI_KEY ( = 0). 
 *              - prng_inst * must be provided if kset.padalg = &pad_bdes.
 *                In all other cases it can be set to 0.
 *              - kset.keys contains the key data. A single RC5 key must be 
 *                between 0 and 255 bytes in length. If bmode.triple is 
 *                BSAPI_SINGLE, kset.keys must contain a pointer to a single
 *                ut_mblk containing the key. If it is BSAPI_TRIPLE or
 *                BSAPI_CHAIN3, kset.keys points to the start of an array
 *                of three ut_mblks containing the key data.
 *              - kset.rounds must be set to the number of rounds (at
 *                least 16 is recommended, any number between 0 and 255
 *                is permitted). 
 *              - kset.iv contains the initialization vector (IV) data and
 *                must be set if bmode.mode = BSAPI_CBC, BSAPI_CFB or
 *                BSAPI_OFB. Its contents depend on bmode.triple. If
 *                bmode.triple = BSAPI_SINGLE or BSAPI_TRIPLE, kset.iv
 *                must contain a ut_mblk * with kset.iv->used = 8 and 8
 *                octets of data at kset->iv.data. If bmode.triple =
 *                BSAPI_CHAIN3, kset.iv points to the start of an array
 *                of three ut_mblks, each containing an eight-byte IV.
 *              - kset.feedback must be set if bmode.mode = BSAPI_CFB or
 *                BSAPI_OFB. For OFB mode, it should be set to 64. For
 *                CFB, it can be set to any value between 1 and 64; the
 *                higher the value the faster the algorithm will run.
 *              - kset.padalg may be 0, &pad_bdes or &pad_pkcs5. &pad_pkcs5
 *                provides the widely-used PKCS-5 style padding (now
 *                also specified in standards such as S/MIME). If
 *                kset.padalg = 0, the data will be padded on encryption
 *                by appending null bytes to the end of the final
 *                encryption block if this is necessary to bring the
 *                data up to a multiple of 8 bytes long. If kset.padalg
 *                = 0, no unpadding is performed on decryption. If
 *                you're using kset.padalg = 0, therefore, you should
 *                ensure that your data is an exact multiple of eight
 *                bytes in length.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_rc5() or
 *              bsapi_kill_rc5(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_rc5(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_rc5()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_rc5() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              an incorrect key length. Also returns 0 if passed
 *              null key data or (in debug mode) if bmode.op is not 
 *              BSAPI_ENCRYPT or BSAPI_DECRYPT.
 * Notes:       CST implements RC5 with a block size of 64 bits. It does not
 *              support 128 bit block RC5.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_rc5(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_rc5>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_rc5(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_rc5() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_rc5(), bsapi_read_rc5(), or
 *              bsapi_finish_rc5(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_rc5() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if the session or data passed is NULL.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_rc5(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_rc5>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_rc5(bsapi_id sid);
 * Description: The bsapi_read_rc5 function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_rc5() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_rc5().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */


extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_rc5(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_rc5>
 * Summary:     Gives size of output from bsapi_readmost_rc5()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_rc5(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_rc5() function gives the length of
 *              output that would be produced by a call to bsapi_readmost_bsa4() 
 *              subsequent to input bytes of data being fed to the session sid
 *              with a call to bsapi_append_rc5().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_rc5(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_rc5>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_rc5(bsapi_id sid);
 * Description: The bsapi_readmost_rc5() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_rc5() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_rc5() function. 
 *
 *              This function is preferred to bsapi_read_rc5() for all normal
 *              operations.
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_rc5(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_rc5(data, len, sid);
 *                 output = bsapi_readmost_rc5(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_rc5(sid);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       When it is running in ECB or CBC mode the function leaves the
 *              final 8 bytes inside the session if the session is decrypting.
 * Example:     See bsapi_kill_rc5().
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_rc5(bsapi_id session);


/* Function:    <bsapi_finish_rc5>
 * Summary:     Finishes a bsapi session using RC5, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_rc5(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_rc5() function finishes the bsapi session
 *              sid for rc5. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_rc5() whether the
 *              return value from the function indicates success or not.
 *              The session ID sid must have originally been returned
 *              from a call to the bsapi_start_rc5() function. On
 *              successful completion, mlist will contain all of the
 *              processed data which has not been output in previous
 *              calls to bsapi_read_rc5() or bsapi_readmost_rc5().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or failure in unpadding. Also returns -1 on null
 *              parameters.   
 * Example:     See bsapi_kill_rc5().
 */


extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_rc5(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_rc5>
 * Summary:     Gives the amount of output from a given input to an RC5 
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_rc5(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_rc5() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This does not
 *              include the effects of any data that is buffered inside
 *              the session. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_rc5()
 *              function.
 * Returns:     The maximum size of output for the given size of input. Returns
 *              -1 if passed a null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_rc5(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_rc5>
 * Summary:     Kills an RC5 session, releasing all resources.
 * Syntax:      bsapi_kill_rc5(bsapi_id sid);
 * Description: The bsapi_kill_rc5() function shuts down a bsapi_rc5
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rc5() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function RC5-encrypts (or decrypts, depending
 *              on the op parameter) stdin to stdout using the supplied
 *              key and prng_inst *; it shows how to construct a mode
 *              structure and key set, how to start an algorithm and
 *              write/read as data becomes available, and how to exit
 *              gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on success or -1 on 
 *              failure):
 *           (code)
 *               int
 *               rc5func(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up single ECB RC5, plain key, PKCS#5 padding 
 *                 md.op = op;
 *                 keys.keys = key; 
 *                 keys.padalg = &pad_pkcs5;
 *                 keys.rounds = 16; //standard value
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_rc5(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_rc5(buf, len, sid)) {
 *                     bsapi_kill_rc5(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                   }
 *                   tmp = cyph = bsapi_readmost_rc5(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_rc5(sid, &cyph)) {
 *                   // even if bsapi_finish_rc5() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_rc5() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 } 
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_rc5(bsapi_id session);

/* Function:    <bsapi_get_name_rc5>
 * Summary:     Returns bsapi_rc5.name.
 * Syntax:      const char *rval = bsapi_get_name_rc5();
 * Description: The bsapi_get_name_rc5() function returns the bsapi_rc5.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_rc5(void);


/* Function:    <rc5_direct>
 * Summary:     Implements the RC5 algorithm.
 * Syntax:      rc5_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The rc5_direct() function feeds length octets of data from
 *              input into the RC5 session sid and writes the processed data 
 *              to output. The function does nothing if passed null
 *              parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    rc5_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_rc5>
 * Summary:     Function pointers for RC5 bsapi routines
 * Notes:       The ut_choose() name for this structure is "RC5".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_rc5;

#endif /* WITH_bsapi_rc5 */


#ifdef WITH_bsapi_pbe

/* Function:    <bsapi_generate_sharedparams_pbe>
 * Summary:     Not applicable to the pbe algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_pbe(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_pbe() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_pbe(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);

/* Function:    <bsapi_generate_key_pbe>
 * Summary:     Not applicable to the pbe algorithm.
 * Syntax:      int rval = bsapi_generate_key_pbe(prng_inst *prng,
 *              (ut_mblk *) &spt, 0, 0);
 * Description: The bsapi_generate_key_pbe() function does nothing and
 &              returns 0.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_pbe(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_pbe>
 * Summary:     Not applicable to the pbe algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_pbe(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_pbe() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_pbe (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_pbe>
 * Summary:     Not applicable to the pbe algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_pbe((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_pbe() function does nothing and
 *              returns 0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_pbe(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_pbe>
 * Summary:     Starts a passphrase-based encryption session.
 * Syntax:      bsapi_id sid = bsapi_start_pbe((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_pbe() function, given operation mode
 *              information bmode, the associated key information kset,
 *              and a prng_inst * prng, creates and returns a new
 *              session to perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important
 *                field the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - kset contains a bsapi_pbe_kset * cast as a bsapi_kset *.
 *                For further details of the fields, see the description
 *                of the bsapi_pbe_kset type in bstypes.h.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_pbe() or
 *              bsapi_kill_pbe(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_pbe(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_pbe()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_pbe() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              internal problems. Also returns 0 if passed NULL salt or
 *              passphrase data or (in debug mode) if bmode.op is not
 *              BSAPI_ENCRYPT or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_pbe(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_pbe>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_pbe(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_pbe() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_pbe(), bsapi_read_pbe(), or
 *              bsapi_finish_pbe(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_pbe() function.
 * Returns:     0 on success or -1 on failure (due to failure in function
 *              bsapi_append_ALG()). Also returns -1 if passed a
 *              NULL sid.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_pbe(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_pbe>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_pbe(bsapi_id sid);
 * Description: The bsapi_read_pbe function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_pbe() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_pbe().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a 
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_pbe(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_pbe>
 * Summary:     Gives size of output from bsapi_readmost_pbe() corresponding to
 *              input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_pbe(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_pbe() function gives the length of 
 *              output that would be produced by a call to bsapi_readmost_pbe() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_pbe().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_pbe(size_t input, bsapi_id session);



/* Function:    <bsapi_readmost_pbe>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_pbe(bsapi_id sid);
 * Description: The bsapi_readmost_pbe() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_pbe() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_pbe() function. 
 *
 *              This function is preferred to bsapi_read_pbe() for all normal
 *              operations. 
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_pbe(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_pbe(data, len, sid);
 *                 output = bsapi_readmost_pbe(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_pbe(sid);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a 
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_pbe(bsapi_id session);

/* Function:    <bsapi_finish_pbe>
 * Summary:     Finishes a bsapi session using pbe, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_pbe(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_pbe() function finishes the bsapi session
 *              sid for pbe. The memory pointed to by sid is
 *              deallocated following a call to bsapi_finish_pbe()
 *              whether the return value from the function indicates
 *              success or not. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_pbe()
 *              function. On successful completion, mlist will contain
 *              all of the processed data which has not been output in
 *              previous calls to bsapi_read_pbe() or
 *              bsapi_readmost_pbe().
 * Returns:     Returns 0 on success or -1 on failure (due to internal
 *              memory allocation problems). Also returns -1 on 
 *              null parameters.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_pbe(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_pbe>
 * Summary:     Gives the amount of output from a given input to a pbe
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_pbe(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_pbe() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This does not
 *              include the effects of any data that is buffered inside
 *              the session. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_pbe()
 *              function.
 * Returns:     The maximum size of output for the given size of input. Returns
 *              -1 on null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_pbe(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_pbe>
 * Summary:     Kills a pbe session, releasing all resources.
 * Syntax:      bsapi_kill_pbe(bsapi_id sid);
 * Description: The bsapi_kill_pbe() function shuts down a bsapi_pbe
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_pbe() function.
 * Returns:     void.
 * Errors:      None.
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_pbe(bsapi_id session);

/* Function:    <bsapi_get_name_pbe>
 * Summary:     Returns bsapi_pbe.name.
 * Syntax:      const char *rval = bsapi_get_name_pbe();
 * Description: The bsapi_get_name_pbe() function returns the bsapi_pbe.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_pbe(void);


/* Function:    <bsapi_convert_pbe_cstv7_1>
 * Summary:     Converts CST v7.1 PKCS#12 PBE to correct form.
 * Syntax:      int rval = bsapi_convert_pbe_cstv7_1(bsapi_kset *kset,
 *                u8 *data, size_t len);
 * Description: The bsapi_convert_pbe_cstv7_1() function reads in data
 *              produced by bsapi_pbe in CST v7.1 and earlier and
 *              converts it to the correct version of PKCS#12 PBE. The
 *              output data is written into the input buffer and is of
 *              the same length.
 *
 *              This function is only necessary in rare cases. When
 *              using PKCS#12 passphrase-based encryption with three-key
 *              Triple DES, CST v7.1 and earlier derived the key
 *              incorrectly in approximately 1 out of 16 times. All
 *              other forms of PKCS#12 passphrase-based encryption are
 *              correct at all times.
 *              
 *              This function decrypts the data with CST v7.1 PKCS#12
 *              and then re-encrypts it with the correct PKCS#12. It
 *              returns 0 on success, -1 on internal failure, and 1 if
 *              the initial decryption failed. A return value of 1 can
 *              mean EITHER that the encryption parameters provided in
 *              kset were incorrect (they have to be the same as the
 *              data was originally encrypted with) OR that the data was
 *              originally encrypted with the correct form of PKCS#12.
 * Memory:      This function allocates no memory.
 */

extern
int
bsapi_convert_pbe_cstv7_1(bsapi_kset *kset, u8 *data, size_t len);


extern
int
bsapi_convert_pbe_pse_v2(bsapi_kset *kset, u8 *data, size_t len);


/* Function:    <pbe_direct>
 * Summary:     Implements the pbe algorithm.
 * Syntax:      pbe_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The pbe_direct() function feeds length octets of data from
 *              input into the pbe session sid and writes the processed data 
 *              to output. The function does nothing if passed a null sid.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    pbe_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_pbe>
 * Summary:     Function pointers for pbe bsapi routines
 * Notes:       The ut_choose() name for this structure is "PBE".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_pbe;


#endif /* WITH_bsapi_pbe */


#ifdef WITH_bsapi_nullbsa

/* Function:    <bsapi_generate_sharedparams_nullbsa>
 * Summary:     Not applicable to the nullbsa algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_nullbsa(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_nullbsa() function sets 
 *              cpt->data to zero and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_nullbsa(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_nullbsa>
 * Summary:     Not applicable to the nullbsa algorithm.
 * Syntax:      int rval = bsapi_generate_generate_nullbsa(prng_inst *prng, 
 *              (ut_mblk *) &spt, (ut_mblk *) &ppt, 0);
 * Description: The bsapi_generate_sharedparams_nullbsa() function sets
 *              spt->data and ppt->data to zero and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_nullbsa(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_nullbsa>
 * Summary:     Not applicable to the nullbsa algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_nullbsa(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_nullbsa() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_nullbsa (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_nullbsa>
 * Summary:     Not applicable to the nullbsa algorithm.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_nullbsa((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_nullbsa() function does nothing and returns 0.
 * Returns:     0.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_nullbsa(bsapi_mode *mode, bsapi_kset *keys);

/* Function:    <bsapi_start_nullbsa>
 * Summary:     Starts a null cipher session.
 * Syntax:      bsapi_id sid = bsapi_start_nullbsa((bsapi_mode *) &bmode, 0,
 *              (bsapi_kset *) &kset);
 * Description: The bsapi_start_nullbsa() function creates and returns a new
 *              null bsapi session. If bmode.op == BSAPI_ENCRYPT or
 *              BSAPI_DECRYPT the session simply passes the data
 *              through without processing it. Otherwise the data is hashed 
 *              using the algorithm specified in kset->hashalg and (if 
 *              verifying) compares this output with the given signature.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure (problem starting hash session).
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_nullbsa() or
 *              bsapi_kill_nullbsa(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_nullbsa(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_nullbsa()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_nullbsa() was successful.
 * Errors:      Indicated by null (0) return value, due to NULL bmode or key 
 *              data. If signing or verifying, also returns 0 if keys->hashalg
 *              is not specified or if there are problems starting the hash 
 *              session.
 */


extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_nullbsa(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);

/* Function:    <bsapi_append_nullbsa>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_nullbsa(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_nullbsa() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_nullbsa(), bsapi_read_nullbsa(), or
 *              bsapi_finish_nullbsa(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_nullbsa() function.
 * Returns:     0 on success or -1 on failure (problem appending to hash
 *              session when signing or verifying).
 *              
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_nullbsa(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_nullbsa>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_nullbsa(bsapi_id sid);
 * Description: The bsapi_read_nullbsa function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_nullbsa()
 *              function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       The function always returns 0 if called in the middle of a
 *              signing or verification session.
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_nullbsa(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_nullbsa>
 * Summary:     Gives size of output from bsapi_readmost_nullbsa() corresponding
 *              to input bytes being fed to the encryption/decryption session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_nullbsa(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_nullbsa() function gives the length of 
 *              output that would be produced by a call to 
 *              bsapi_sizeof_readmost_nullbsa() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_nullbsa().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid or if called during a signing or
 *              verification session.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_nullbsa(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_nullbsa>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_nullbsa(bsapi_id sid);
 * Description: The bsapi_read_nullbsa function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_nullbsa()
 *              function.
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns -1 if passed a NULL sid.            
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       This function simply wraps bsapi_read_nullbsa.
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_nullbsa(bsapi_id session);


/* Function:    <bsapi_finish_nullbsa>
 * Summary:     Finishes a bsapi session using nullbsa, returns output and
 *              frees memory.
 * Syntax:      int rval = bsapi_finish_nullbsa(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_nullbsa() function finishes the bsapi session
 *              sid for nullbsa. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_nullbsa() whether the
 *              return value from the function indicates success or not.
 *              The session ID sid must have originally been returned
 *              from a call to the bsapi_start_nullbsa() function. When
 *              encrypting/decrypting, mlist will, on successful completion,
 *              contain all of the processed data which has not been output
 *              in previous calls to bsapi_read_nullbsa() or 
 *              bsapi_readmost_nullbsa(). When signing, mlist will contain
 *              the hashed data.
 * Returns:     Returns 0 on success, -1 on internal failure (due to memory
 *              allocation problems) or 1 if verification fails. Also
 *              returns -1 if passed null parameters.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_nullbsa(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_nullbsa>
 * Summary:     Gives the amount of output from a given input to a nullbsa 
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_nullbsa(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_nullbsa() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. 
 * Returns:     Size of hash digest for a signing session; 0 for verification; 
 *              inqty for encryption/decryption. Returns inqty if sid is null.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_nullbsa(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_nullbsa>
 * Summary:     Kills a nullbsa session, releasing all resources.
 * Syntax:      bsapi_kill_nullbsa(bsapi_id sid);
 * Description: The bsapi_kill_nullbsa() function shuts down a bsapi_nullbsa
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_nullbsa() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function nullbsa passes stdin to stdout. It shows 
 *              how to construct a mode structure and key set, how to start an 
 *              algorithm and write/read as data becomes available, and how to
 *              exit gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on success or -1 on failure):
 *           (code)
 *               int
 *               nullbsafunc(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up simple nullbsa
 *                 md.op = op; //must be specified
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_nullbsa(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_nullbsa(buf, len, sid)) {
 *                     bsapi_kill_nullbsa(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_nullbsa(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_nullbsa(sid, &cyph)) {
 *                   // even if bsapi_finish_nullbsa() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_nullbsa() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_nullbsa(bsapi_id session);

/* Function:    <bsapi_get_name_nullbsa>
 * Summary:     Returns bsapi_nullbsa.name.
 * Syntax:      const char *rval = bsapi_get_name_nullbsa();
 * Description: The bsapi_get_name_nullbsa() function returns the bsapi_nullbsa.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_nullbsa(void);


/* Function:    <nullbsa_direct>
 * Summary:     Implements the nullbsa algorithm.
 * Syntax:      nullbsa_direct(bsapi_id sid, u8 *input, u8 *output, 
 *                size_t length);
 * Description: The nullbsa_direct() function copies length octets of data from
 *              input to output. The function does nothing if passed null
 *              parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    nullbsa_direct(bsapi_id session, u8 *in, u8 *out, size_t len);

/* Data:        <bsapi_nullbsa>
 * Summary:     Function pointers for nullbsa bsapi routines
 * Notes:       The ut_choose() name for this structure is "nullbsa".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_nullbsa;

#endif /* WITH_bsapi_nullbsa */


/*
 *   Functions to BER-encode/decode byte arrays of DSA keys and
 *   parameters contained in a ut_mblk_list. Source code contained in
 *   bsapi/dsaut.c
 */


/* Function:    <bsapi_joinKey_dsa>
 * Summary:     ASN.1-encodes a DSA private key and its shared parameters.
 * Syntax:      bsapi_joinKey_dsa(list, &key, key_type);
 * Description: ASN.1 encoding of a DSA private key and shrdpub. Output
 *              written to ut_mblk key. list is a ut_mblk_list in which each
 *              mblk contains a DSA parameter. Therefore list must have
 *              5 elements (p, q, g, y, x).           
 *              The encoding is SEQUENCE {version, p, q, g, y, x}.
 *              key_type must be BSAPI_PRIVATE or BSAPI_KEY_TYPE_DEFAULT
 * Returns:     0 on sucess
 *              -1 if error in parameters
 *              -2 if error allocating memory
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_joinKey_dsa
  (ut_mblk_list mlist, ut_mblk *key, bsapi_kset_key_type key_type);


/* Function:    <bsapi_joinKeyAndParams_dsa>
 * Summary:     ASN.1-encodes a DSA key and its shared parameters.
 * Syntax:      bsapi_joinKeyAndParams_dsa(list, &key, &params, key_type);
 * Description: ASN.1 encoding of a DSA key and shrdpub. Output written
 *              to ut_mblk key and ut_mblk params.
 *              list is a ut_mblk_list in which each mblk contains a DSA
 *              parameter. Therefore list must either have 5 elements (p,
 *              q, g, y, x) where the mblk containing either y or x may be               
 *              empty.
 *              key_type determines whether a public or private key is
 *              being encoded. key_type may be set to BSAPI_DEFAULT in
 *              which case it is assumed that the key to be encoded is
 *              the private key *unless* the private key mblk is empty in
 *              which case the public key is encoded
 * Returns:     0 on sucess
 *              -1 if error in parameters
 *              -2 if error allocating memory
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_joinKeyAndParams_dsa
  (ut_mblk_list mlist, ut_mblk *key, ut_mblk *params,
   bsapi_kset_key_type key_type);


/* Function:    <bsapi_splitKey_dsa>
 * Summary:     ASN.1-decodes a DSA key and its shared parameters.
 * Syntax:      bsapi_splitKey_dsa(&key, &param, &list, key_type);
 * Description: Takes ASN.1 encoding of a DSA key and parameter data and
 *              writes plain key and parameters into a ut_mblk_list.
 *              The ut_mblk_list is generated in the function and written
 *              to list with each mblk containing an unencoded key or
 *              parameter. The ut_mblk_list has five elements in the
 *              following order (p, q, g, y, x)
 *              Either key contains a BER encoded DSA private key
 *              i.e. SEQUENCE {version, p, q, g, y, x} ...
 *              or key contains a BER encoded integer (x or y) and param
 *              contains a BER encoded sequence i.e. SEQUENCE {p, q, g}.
 *              In this case either the x or y ut_mblk in list will be
 *              empty.
 *              If key_type == BSAPI_DEFAULT it is assumed *key contains
 *              the private key
 * Returns:     0 on sucess
 *              -1 if error in parameters
 *              -2 if error allocating memory
 *              -3 if error when decoding BER strings
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_splitKey_dsa
  (ut_mblk *key, ut_mblk *param, ut_mblk_list *mlist,
   bsapi_kset_key_type key_type);


/* Function:    <bsapi_joinKey_rsa>
 * Summary:     ASN.1-encodes an RSA private or public key.
 * Syntax:      bsapi_joinKey_rsa(list, &key, key_type);
 * Description: ASN.1 encoding of a RSA private or public key.
 *              list is a ut_mblk_list in which each mblk contains a RSA
 *              parameter. So list can either have 2 elemnts (public key
 *              with no fermat num), 3 elemnts (public key with fermat
 *              num) or 8 elements (private key).            
 *              The public key encoding is SEQUENCE {mod, pub_epn,
 *              fermat_num}.
 *              - if no fermat_num supplied default value is 0
 *              The private key encoding is SEQUENCE {version, mod,
 *              pub_expn, priv_expn, p, q, p_expn, q_expn, crt_coeff}.             
 *              If key_type == BSAPI_KEY_TYPE_DEFAULT assume private key.
 * Returns:     0 on sucess.
 *              -1 if error in parameters.
 *              -2 if error allocating memory.
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_joinKey_rsa
  (ut_mblk_list mlist, ut_mblk *key, bsapi_kset_key_type key_type);


/* Function:    <bsapi_joinKeyAndParams_rsa>
 * Summary:     Not applicable to the RSA algorithm.
 * Syntax:      bsapi_joinKeyAndParams_rsa(NULL, NULL, NULL, 0);
 * Description: Stub function, rsa has no parameters stored seperately
 *              from the keys.
 * Returns:     0.
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_joinKeyAndParams_rsa
  (ut_mblk_list mlist, ut_mblk *key, ut_mblk *params,
   bsapi_kset_key_type key_type);


/* Function:    <bsapi_splitKey_rsa>
 * Summary:     ASN.1-decodes an RSA private or public key.
 * Syntax:      bsapi_splitKey_rsa(&key, NULL, &list, key_type);
 * Description: Takes ASN.1 encoding of a RSA key and writes plain key
 *              into a ut_mblk_list.
 *              The ut_mblk_list is generated in the function and written
 *              to list with each mblk containing an unencoded key
 *              parameter. For public keys the ut_mblk_list has three elements        
 *              in the following order (mod, pub_expn, fermat_num) and
 *              for private keys the ut_mblk_list has eight elements
 *              (mod, pub_expn, priv_expn, p, q, p_expn, q_expn,
 *              crt_coeff).
 *              If key_type == BSAPI_KEY_TYPE_DEFAULT it is assumed *key
 *              contains the private key.
 *              The params ut_mblk is not required for RSA.
 * Returns:     0 on sucess.
 *              -1 if error in parameters.
 *              -2 if error allocating memory.
 *              -3 if error when decoding BER strings.
 */
extern int
CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_splitKey_rsa
  (ut_mblk *key, ut_mblk *param, ut_mblk_list *mlist,
   bsapi_kset_key_type key_type);

/* backward-compatibility macros */
#define bsapi_generate_community_bsa4  bsapi_generate_sharedparams_bsa4
#define bsapi_make_kstruct_bsa4  bsapi_generate_privatenonce_bsa4
#define bsapi_generate_community_bsa5  bsapi_generate_sharedparams_bsa5
#define bsapi_make_kstruct_bsa5  bsapi_generate_privatenonce_bsa5
#define bsapi_generate_community_des  bsapi_generate_sharedparams_des
#define bsapi_make_kstruct_des  bsapi_generate_privatenonce_des
#define bsapi_generate_community_dsa  bsapi_generate_sharedparams_dsa
#define bsapi_make_kstruct_dsa  bsapi_generate_privatenonce_dsa
#define bsapi_generate_community_rc2  bsapi_generate_sharedparams_rc2
#define bsapi_make_kstruct_rc2  bsapi_generate_privatenonce_rc2
#define bsapi_generate_community_rc4  bsapi_generate_sharedparams_rc4
#define bsapi_make_kstruct_rc4  bsapi_generate_privatenonce_rc4
#define bsapi_generate_community_rsa  bsapi_generate_sharedparams_rsa
#define bsapi_make_kstruct_rsa  bsapi_generate_privatenonce_rsa
#define bsapi_generate_community_triple_des  bsapi_generate_sharedparams_triple_des
#define bsapi_make_kstruct_triple_des  bsapi_generate_privatenonce_triple_des


#ifdef WITH_bsapi_entrust_pbm


/* Function:    <bsapi_generate_sharedparams_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_entrust_pbm(prng_inst *prng,
 *                (ut_mblk *) &shrdpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_entrust_pbm() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_entrust_pbm(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);


/* Function:    <bsapi_generate_key_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      int rval = bsapi_generate_key_entrust_pbm
 *                (prng_inst *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_key_entrust_pbm() function does nothing
 *              and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_entrust_pbm(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_entrust_pbm
 *                (prng_inst *prng, (ut_mblk *) &pnonce, 
 *                (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_entrust_pbm() function does 
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_entrust_pbm (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      size_t rval = bsapi_sizeof_iv_entrust_pbm(bsapi_mode *mode,
 *                (bsapi_kset *) keys);
 * Description: The bsapi_sizeof_iv_entrust_pbm() function does nothing and
 *              returns 0.
 * Returns:     0.
 *
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_entrust_pbm(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_entrust_pbm>
 * Summary:     Starts an Entrust-style passphrase-based MAC session.
 * Syntax:      bsapi_id sid = bsapi_start_entrust_pbm((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_entrust_pbm() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation.
 *              A pointer to an entrust_pbm_kset structure must be passed as 
 *              the third argument, cast to a (bsapi_kset *).
 *              - bmode.op may be BSAPI_SIGN (to generate a MAC) or
 *                BSAPI_VERIFY (to verify a MAC). All other fields
 *                of bmode are ignored.
 *              - prng is ignored and may be set to 0.
 *              - kset->passphrase contains the passphrase information. The
 *                data field holds the passphrase and the used field gives
 *                its length.
 *              - kset->salt contains the salt information.The data field holds
 *                the salt and the used field gives its length. The length
 *                should be the size of the owf output.
 *              - kset->owf is the hash function used to derive the key.
 *              - kset.count gives the iteration count: how many times the
 *                passphrase and salt are to be hashed to obtain the MAC key.
 *              - kset->mac is the hash function used to obtain the MAC by
 *                hashing the message and the MAC key.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_entrust_pbm() or
 *              bsapi_kill_entrust_pbm(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_entrust_pbm(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_entrust_pbm()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_entrust_pbm() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory, 
 *              bmode.op not being BSAPI_SIGN or BSAPI_VERIFY, or problems
 *              with the hashing functions. Also returns 0 if any of the fields
 *              of kset have not been set.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_entrust_pbm(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_entrust_pbm>
 * Summary:     Feeds data into an Entrust-style passphrase-based MAC session
 *              for processing.
 * Syntax:      int rval = bsapi_append_entrust_pbm(u8 *ptr, size_t len,
 *                bsapi_id sid);
 * Description: The bsapi_append_entrust_pbm() function writes len octets from
 *              ptr into a MAC session sid. The session ID sid must have
 *              originally been returned from a call to the 
 *              bsapi_start_entrust_pbm() function.
 * Returns:     0 on success.
 *              -1 if there's an internal error or if session or data is null.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_entrust_pbm(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      ut_mblk_list rval = bsapi_read_entrust_pbm(bsapi_id session);
 * Description: The bsapi_read_entrust_pbm() function does nothing and
 *              returns 0.
 * Returns:     0.
 *
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_entrust_pbm(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_entrust_pbm(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_entrust_pbm() function does nothing
 *              and returns 0.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_entrust_pbm(size_t input, bsapi_id session);



/* Function:    <bsapi_readmost_entrust_pbm>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      ut_mblk_list rval = bsapi_readmost_entrust_pbm(bsapi_id session);
 * Description: The bsapi_readmost_entrust_pbm() function does nothing and
 *              returns 0.
 * Returns:     0.
 *
 */

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_entrust_pbm(bsapi_id session);


/* Function:    <bsapi_finish_entrust_pbm>
 * Summary:     Finishes an Entrust-style passphrase-based MAC session, returns
 *              output and frees memory.
 * Syntax:      int rval = bsapi_finish_entrust_pbm(bsapi_id sid, 
 *                (ut_mblk_list *) &data);
 * Description: We describe MAC generation and MAC verification sessions
 *              separately.
 * Signing:     The bsapi_finish_entrust_pbm() function finishes the MAC
 *              session sid.The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_entrust_pbm() whether the
 *              return value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_entrust_pbm() function. On successful
 *              completion, mlist will contain a ut_mblk_list with a single
 *              member (mlist->prev = mlist; mlist->next = 0). The
 *              MAC data is at mlist->block.data and is of length
 *              mlist->block.used. The MAC consists of the raw MAC data; it is
 *              not ASN.1 formatted in any way.
 * Verifying:   The bsapi_finish_entrust_pbm() function finishes the MAC
 *              session sid. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_entrust_pbm() whether the
 *              return value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_entrust_pbm() function. When verifying,
 *              the MAC to be verified must be passed into the function
 *              in mlist. The bsapi_finish_entrust_pbm() function checks to see          
 *              if the MAC is valid for the message which was passed into
 *              bsapi_append_entrust_pbm().
 * Returns:     0 on success (generates/verifies MAC).
 *              -1 if there was an internal error or if sid or data is null.
 *              1 if, when verifying, the MACs don't match.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_entrust_pbm(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_entrust_pbm>
 * Summary:     Gives the amount of output from a given input to an 
 *              Entrust-style passphrase-based MAC session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_entrust_pbm(bsapi_id sid, 
 *              off_t inqty);
 * Description: The bsapi_sizeof_output_entrust_pbm() function returns the
 *              maximum amount of output which could be produced if inqty
 *              octets of data were input into the session sid. 
 * Returns:     Size of output from hash function, if generating MAC.
 *              0, if verifying MAC.
 *              -1 if sid is null.
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_entrust_pbm(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_entrust_pbm>
 * Summary:     Kills an Entrust-style passphrase-based MAC session, 
 *              releasing all resources.
 * Syntax:      bsapi_kill_entrust_pbm(bsapi_id sid);
 * Description: The bsapi_kill_entrust_pbm() function shuts down a MAC session
 *              sid, freeing all memory associated with the session and
 *              returning no output. It is for use when it is necessary
 *              to terminate a session unfinished. The session ID sid must
 *              have originally been returned from a call to the
 *              bsapi_start_entrust_pbm() function.
 * Returns:     void.
 * Errors:      None.
 */

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_entrust_pbm(bsapi_id session);


/* Function:    <bsapi_get_name_entrust_pbm>
 * Summary:     Returns bsapi_entrust_pbm.name.
 * Syntax:      const char *rval = bsapi_get_name_entrust_pbm();
 * Description: The bsapi_get_name_entrust_pbm() function returns the 
 *              bsapi_entrust_pbm.name field. This is the field which
 *              ut_choose() uses to convert from a string to a bsapi_alg
 *              algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_entrust_pbm(void);


/* Function:    <entrust_pbm_direct>
 * Summary:     Not applicable to the Entrust-style PBM algorithm.
 * Syntax:      entrust_pbm_direct(void);
 * Description: The entrust_pbm_direct() function does nothing.
 * Returns:     void.
 *
 */

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    entrust_pbm_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_entrust_pbm;

#endif /* WITH_bsapi_entrust_pbm */

#ifdef WITH_bsapi_rijndael

/* Function:    <bsapi_generate_sharedparams_rijndael>
 * Summary:     Not applicable to the Rijndael algorithm.
 * Syntax:      int rval = bsapi_generate_sharedparams_rijndael(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_rijndael() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_rijndael(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);

/* Function:    <bsapi_generate_key_rijndael>
 * Summary:     Generates a key for Rijndael.
 * Syntax:      int rval = bsapi_generate_key_rijndael(prng_inst *prng,
 *              (ut_mblk *) &spt, 0, 0);
 * Description: The bsapi_generate_key_rijndael() function generates a 16-byte
 *              Rijndael key. The key is written to spt.data, where memory
 *              is allocated, and spt.size and spt.used are set
 *              accordingly. 
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory.
 *              Also returns -1 if prng or spt is 0.
 * Memory:      spt.data will have to be disposed of following a successful
 *              return. The code to do it is:
 *           (code)
 *              ut_dispose_mem(spt.data);
 *              // or...
 *              ut_dispose_mblk (&spt);
 *           (/code)     
 * Notes:       There is a class of weak keys for Rijndael, but the chance of
 *              obtaining one at random is one in 2^75 so this function
 *              does not check for them.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_rijndael(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);


/* Function:    <bsapi_generate_privatenonce_rijndael>
 * Summary:     Not applicable to the Rijndael algorithm.
 * Syntax:      int rval = bsapi_generate_privatenonce_rijndael(prng_inst
 *              *prng, (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_rijndael() function does
 *              nothing and returns 0.
 * Returns:     0.
 *
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_rijndael (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);


/* Function:    <bsapi_sizeof_iv_rijndael>
 * Summary:     Gets length of initialization vector for Rijndael.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_rijndael((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_rijndael() function returns the number of
 *              octets of memory that must be allocated to hold the
 *              initialization vector for the algorithm idea when it is
 *              used according to bmode. 
 *              - If bmode.mode = BSAPI_ECB it returns 0.
 *              - Otherwise it returns 8.
 * Returns:     The number of octets of memory that must be allocated to
 *              hold the initialization vector for the algorithm Rijndael. Returns
 *              0 if &bmode is 0.
 * Errors:      Does not fail.
 */

extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_rijndael(bsapi_mode *mode, bsapi_kset *keys);


/* Function:    <bsapi_start_rijndael>
 * Summary:     Starts an Rijndael session.
 * Syntax:      bsapi_id sid = bsapi_start_rijndael((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_rijndael() function, given operation mode
 *              information bmode, the associated key information kset,
 *              and a prng_inst * prng, creates and returns a new
 *              session to perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important
 *                field the CST will provide a sensible default.
 *              - bmode.op may be BSAPI_ENCRYPT or BSAPI_DECRYPT.
 *              - bmode.mode may be any one of BSAPI_ECB, BSAPI_CBC,
 *                BSAPI_CFB and BSAPI_OFB. If it is anything other than
 *                BSAPI_ECB, kset.iv must be set. If it is BSAPI_CFB or
 *                BSAPI_OFB, kset.feedback must also be set
 *              - bmode.triple may be BSAPI_SINGLE, BSAPI_TRIPLE or
 *                BSAPI_CHAIN3. Depending on this, kset.keys will contain
 *                one or three ut_mblks ontaining the key data. See the
 *                item on kset.keys below for more details.
 *              - bmode.key_type may be BSAPI_KEY ( = 0 ) or
 *                BSAPI_SCHEDULE. The use of BSAPI_SCHEDULE is
 *                deprecated.
 *              - prng_inst * must be provided if kset.padalg = &pad_bdes.
 *                In all other cases it can be set to 0.
 *              - kset.keys contains the key data. If bmode.triple =
 *                BSAPI_SINGLE, kset.keys must contain a ut_mblk * with
 *                kset.keys->used = 8 and kset.keys->data containing 8
 *                bytes of data. If bmode.triple = BSAPI_TRIPLE or
 *                BSAPI_CHAIN3, kset.keys must be an array of three
 *                ut_mblks, each containing eight bytes of data (to use
 *                two-key triple Rijndael, simply set the third ut_mblk's
 *                data field to be the same as the first one's with
 *                kset.keys[2].data = kset.keys[0].data). 
 *              - kset.iv contains the initialization vector (IV) data and
 *                must be set if bmode.mode = BSAPI_CBC, BSAPI_CFB or
 *                BSAPI_OFB. Its contents depend on bmode.triple. If
 *                bmode.triple = BSAPI_SINGLE or BSAPI_TRIPLE, kset.iv
 *                must contain a ut_mblk * with kset.iv->used = 8 and 8
 *                octets of data at kset->iv.data. If bmode.triple =
 *                BSAPI_CHAIN3, kset.iv points to the start of an array
 *                of three ut_mblks, each containing an eight-byte IV.
 *              - kset.feedback must be set if bmode.mode = BSAPI_CFB or
 *                BSAPI_OFB. For OFB mode, it should be set to 64. For
 *                CFB, it can be set to any value between 1 and 64; the
 *                higher the value the faster the algorithm will run.
 *              - kset.padalg may be 0, &pad_bdes or &pad_pkcs5. &pad_pkcs5
 *                provides the widely-used PKCS-5 style padding (now
 *                also specified in standards such as S/MIME). If
 *                kset.padalg = 0, the data will be padded on encryption
 *                by appending null bytes to the end of the final
 *                encryption block if this is necessary to bring the
 *                data up to a multiple of 8 bytes long. If kset.padalg
 *                = 0, no unpadding is performed on decryption. If
 *                you're using kset.padalg = 0, therefore, you should
 *                ensure that your data is an exact multiple of eight
 *                bytes in length.
 *              - All other fields will be ignored.
 * Returns:     A handle to the bsapi session which has been created, or 0
 *              on failure.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_rijndael() or
 *              bsapi_kill_rijndael(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_rijndael(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_rijndael()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_rijndael() was successful.
 * Errors:      Indicated by null (0) return value due to lack of memory or
 *              incorrect key length. Also returns 0 if passed null
 *              key data or (in debug mode) if bmode.op is not BSAPI_ENCRYPT
 *              or BSAPI_DECRYPT.
 */

extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_rijndael(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);


/* Function:    <bsapi_append_rijndael>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_rijndael(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_rijndael() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held
 *              inside the session until a successful call to
 *              bsapi_readmost_rijndael(), bsapi_read_rijndael(), or
 *              bsapi_finish_rijndael(). The session ID sid must have
 *              originally been returned from a call to the
 *              bsapi_start_rijndael() function.
 * Returns:     0 on success or -1 on failure due to lack of memory. Also
 *              returns -1 if the session or data passed is NULL.
 */

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_rijndael(u8 *data, size_t length, bsapi_id session);


/* Function:    <bsapi_read_rijndael>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_rijndael(bsapi_id sid);
 * Description: The bsapi_read_rijndael function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_rijndael() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_rijndael().
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 */


extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_rijndael(bsapi_id session);

/* Function:    <bsapi_sizeof_readmost_rijndael>
 * Summary:     Gives size of output from bsapi_readmost_rijndael()
 *              corresponding to input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_readmost_rijndael(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_rijndael() function gives the length of output that 
 *              that would be produced by a call to bsapi_readmost_rijndael() 
 *              subsequent to input bytes of data being fed to the session sid with 
 *              a call to bsapi_append_rijndael().
 * Returns:     The size of output for the given size of input. Returns
 *              0 if passed a null sid.
 */

extern size_t
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_readmost_rijndael(size_t input, bsapi_id session);


/* Function:    <bsapi_readmost_rijndael>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_rijndael(bsapi_id sid);
 * Description: The bsapi_readmost_rijndael() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_rijndael() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_rijndael() function. 
 *
 *              This function is preferred to bsapi_read_rijndael() for all normal
 *              operations. 
 * 
 *              This function will usually be used in a loop with
 *              bsapi_append_rijndael(), as in the following pseudocode:
 *           (code)
 *               while (data still left) {
 *                 bsapi_append_rijndael(data, len, sid);
 *                 output = bsapi_readmost_rijndael(sid);
 *                 write(output);
 *                 ut_dispose_list(output);
 *               }
 *               bsapi_finish_rijndael(sid);
 *           (/code)
 * Returns:     A ut_mblk_list containing the processed data. If no data is
 *              available returns 0. Also returns 0 if passed a
 *              NULL sid.
 * Memory:      The ut_mblk_list returned from this function must be
 *              disposed of with ut_dispose_list(mlist);
 * Errors:      None. 
 * Notes:       When it is running in ECB or CBC mode the function leaves the
 *              final 8 bytes inside the session if the session is decrypting.
 * Example:     See bsapi_kill_rijndael().
 */
 

extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_rijndael(bsapi_id session);

/* Function:    <bsapi_finish_rijndael>
 * Summary:     Finishes a bsapi session using Rijndael, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_rijndael(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_rijndael() function finishes the bsapi session
 *              sid for idea. The memory pointed to by sid is
 *              deallocated following a call to bsapi_finish_rijndael()
 *              whether the return value from the function indicates
 *              success or not. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_rijndael()
 *              function. On successful completion, mlist will contain
 *              all of the processed data which has not been output in
 *              previous calls to bsapi_read_rijndael() or
 *              bsapi_readmost_rijndael().
 * Returns:     Returns 0 on success or -1 on failure due to lack of memory
 *              or failure in unpadding. Also returns -1 on null
 *              parameters.   
 * Example:     See bsapi_kill_rijndael().
 */
 

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_rijndael(bsapi_id session, ut_mblk_list *data);


/* Function:    <bsapi_sizeof_output_rijndael>
 * Summary:     Gives the amount of output from a given input to an Rijndael
 *              session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_rijndael(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_rijndael() function returns the maximum
 *              amount of output which could be produced if inqty octets
 *              of data were input into the session sid. This does not
 *              include the effects of any data that is buffered inside
 *              the session. The session ID sid must have originally
 *              been returned from a call to the bsapi_start_rijndael()
 *              function.
 * Returns:     The maximum size of output for the given size of input. Returns
 *              -1 on null sid.
 * Errors:      None in general. 
 */

extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_rijndael(bsapi_id session, sec_off_t input);


/* Function:    <bsapi_kill_rijndael>
 * Summary:     Kills an Rijndael session, releasing all resources.
 * Syntax:      bsapi_kill_rijndael(bsapi_id sid);
 * Description: The bsapi_kill_rijndael() function shuts down a bsapi_rijndael
 *              session sid, freeing all memory associated with the
 *              session and returning no output. It is for use when it
 *              is necessary to terminate a session unfinished. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_rijndael() function.
 * Returns:     void.
 * Errors:      None.
 * 
 * Example:     The following function Rijndael-encrypts (or decrypts,
 *              depending on the op parameter) stdin to stdout using the
 *              supplied key and prng_inst *; it shows how to construct
 *              a mode structure and key set, how to start an algorithm
 *              and write/read as data becomes available, and how to
 *              exit gracefully in case of external problems (it uses ut_log()
 *              for error reporting, and returns 0 on failure, or -1 on
 *              success):
 *           (code)
 *               int
 *               ideafunc(ut_mblk *key, bsapi_mode_op op, prng_inst *prng)
 *               {
 *                 u8 buf[BUFSIZ];
 *                 bsapi_mode md = {BSAPI_ENCRYPT, BSAPI_ECB,
 *                   BSAPI_SINGLE, BSAPI_KEY, BSAPI_ANSI};
 *                 bsapi_kset keys = {0};
 *                 bsapi_id sid;
 *                 ut_mblk_list cyph;
 *                 ut_mblk_list tmp;
 *                 int len;
 *                 
 *                 // Set up single ECB Rijndael, plain key, PKCS#5 padding 
 *                 md.op = op;
 *                 keys.keys = key;
 *                 keys.padalg = &pad_pkcs5;
 *                 
 *                 // Process.. 
 *                 if(!(sid = bsapi_start_rijndael(&md, prng, &keys))) {
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to start()");
 *                   return -1;
 *                 }
 *                 
 *                 while((len = fread(buf, sizeof(u8), BUFSIZ, stdin))
 *                    > 0) {
 *                   if(bsapi_append_rijndael(buf, len, sid)) {
 *                     bsapi_kill_rijndael(sid);
 *                     ut_log0(0UL, UT_ACONTINUE, "failed to append()");
 *                     return -1;
 *                   }
 *                   tmp = cyph = bsapi_readmost_rijndael(sid);
 *                   while(tmp) { // Write output 
 *                     fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                      stdout);
 *                     tmp = tmp->next;
 *                   }
 *                   ut_dispose_list(cyph); // Free up list 
 *                 }
 *                 
 *                 if(bsapi_finish_rijndael(sid, &cyph)) {
 *                   // even if bsapi_finish_rijndael() fails, it shuts down the
 *                   // bsapi session so there is no need to call
 *                   // bsapi_kill_rijndael() here.
 *                   ut_log0(0UL, UT_ACONTINUE, "failed to finish()");
 *                   return -1;
 *                 }
 *                 
 *                 for(tmp = cyph; tmp; tmp = tmp->next)
 *                   fwrite(tmp->block.data, sizeof(u8), tmp->block.used,
 *                    stdout);
 *                 ut_dispose_list(cyph);
 *                 
 *                 return 0;
 *               }
 *           (/code)
 */
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_rijndael(bsapi_id session);

/* Function:    <bsapi_get_name_rijndael>
 * Summary:     Returns bsapi_rijndael.name.
 * Syntax:      const char *rval = bsapi_get_name_rijndael();
 * Description: The bsapi_get_name_rijndael() function returns the bsapi_rijndael.name
 *              field. This is the field which ut_choose() uses to convert from
 *              a string to a bsapi_alg algorithm.
 */

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_rijndael(void);


/* Function:    <rijndael_direct>
 * Summary:     Implements the Rijndael algorithm.
 * Syntax:      rijndael_direct(bsapi_id sid, u8 *input, u8 *output, size_t length);
 * Description: The rijndael_direct() function feeds length octets of data from
 *              input into the Rijndael session sid and writes the processed data 
 *              to output. The function does nothing if passed null parameters.
 * Returns:     void.
*/

extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    rijndael_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


/* Data:        <bsapi_rijndael>
 * Summary:     Function pointers for Rijndael bsapi routines
 * Notes:       The ut_choose() name for this structure is "Rijndael".
 */
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_rijndael;

/* Auxiliary function support */

/* Function:    <rijndael_reset>
 * Summary:     Changes the key and/or initialization vector in a
 *              bsapi session.
 * Syntax:      int rval = rijndael_reset(bsapi_id sid, ut_mblk *ivnew, 
 *                ut_mblk *keynew, bsapi_mode_key_type keynewtype);
 * Description: The rijndael_reset() function replaces the key and/or initialization
 *              vector being used in the Rijndael session sid with keynew and/or
 *              ivnew.
 * Returns:     0 on success, -1 on failure due to key or initialization vector
 *              having incorrect length. Also returns -1 if sid is null.
*/

extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    rijndael_reset(bsapi_id session, ut_mblk *iv, ut_mblk *key,
    bsapi_mode_key_type kt);

#endif /* WITH_bsapi_rijndael */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _BSAPI_H */

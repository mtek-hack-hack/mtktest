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

#ifndef _RSA_H /* Prevent multiple inclusion */
#define _RSA_H

#include "mpm.h"  /* For mpm_arc */
#include "prng.h" /* For prng_inst */
#include "ut.h"   /* For utb, u8, & u32 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ERRORS */

#define RSA_EBASE     (0x00200000) /* Module code */

#define RSA_ENFBIT (RSA_EBASE + 0x40000) /* Bitstring with nonfull last byte */
#define RSA_ENTRNL (RSA_EBASE + 0x40100) /* Internal function failure */
#define RSA_EUNEXP (RSA_EBASE + 0x40200) /* Wrong type */
#define RSA_EXTRAD (RSA_EBASE + 0x40300) /* Unexpected trailing data in key */
#define RSA_EPARAM (RSA_EBASE + 0x40400) /* Bad Parameter */
#define RSA_ENOMEM (RSA_EBASE + 0x40500) /* out of memory */
#define RSA_ENOKGN (RSA_EBASE + 0x40600) /* Key generation not supported */

/* Shutdown function */
extern void rsa_shutdown(int cancel);

/* Initialisation function - submit error block. */
extern int rsa_init(void);

/* Component: rsakey
 * Purpose:   Type definition of an rsa key.
 */

/* Type: <rsa_kid>
 * Note: This structure defines the contents of an RSA key identity structure.
 *         Key identities are assigned on each key in an RSA key pair. The
 *         time stamp and random number in both are identical.  This links the
 *         two uniquely (hopefully).  The public key and secret key have the
 *         key_type assigned to identify one to invert the operation of the
 *         other.
 */
typedef enum {
  RSA_PUBLIC_KEY, /* key id type for public keys */
  RSA_SECRET_KEY  /* key id type for secret keys */
} rsa_ktype;

typedef struct {
  u32       time;     /* time stamp: seconds since 00:00:00 GMT, Jan 1, 1990 */
  u32       rand;     /* a random number */
  rsa_ktype key_type; /* identify which one of pair this is */
} rsa_kid;

/* Type: <rsa_key>
 * Note: This structure defines an RSA key.  Three types of RSA key exist.
 *         They are defined in a union.
 */
typedef enum {
  RSA_SIMPLE_KEY, /* type tag for simple key */
  RSA_CRT_KEY     /* type tag for crt key */
} rsa_ktag;

typedef struct rsa_key_t {
  u32      bits;         /* bits in modulus */
  rsa_ktag key_type_tag; /* union label for type of key */
  union {
    struct smks {        /* Structure holding simple key */
      mpm_arc modulus;
      mpm_arc expon;
      u32     fermat_no; /* 0 - indicates that exp is not a Fermat numberm, else
                          * exp is 2^(2^(fermat_no - 1)) + 1 */
    } simple_key;

    struct spks {        /* Structure holding CRT-type key */
      mpm_arc p_factor;
      mpm_arc q_factor;
      mpm_arc p_expon;
      mpm_arc q_expon;
      mpm_arc conv_const;
      mpm_arc modulus;
      mpm_arc expon;
      mpm_arc pub_expon; /* Public exponent -- for PKCS #1 compatibility */
    } crt_key;
  } key_type;
} rsa_key;

/* Function:  <rsa_dispose_key>
 * Syntax:    rsa_dispose_key(key_p);
 * Semantics: Disposes of all memory associated with an rsa_key, _excluding_
 *              the rsa_key structure itself.
 * Failure:   Aborts (in debug mode only) on receipt of a null key pointer.
 */
extern void rsa_dispose_key(rsa_key *key);

/* Function:  <rsa_crypt>
 * Syntax:    crypt_arc = rsa_crypt(key_p, mess_arc);
 * Semantics: This procedure takes the message in mess_arc and en/decrypts it
 *              with the key.  The result is stored in an archive and returned
 *              as crypt_arc.
 * Failure:   message_arc represents a number which is larger than the key
 *              modulus.  Return value of 0.
 */
extern mpm_arc rsa_crypt(rsa_key *, mpm_arc);

/* Function:  <rsakg_gen_key>
 * Syntax:    success = rsakg_gen_key(seed_p, seed_q, public_p, secret_p, weak,
 *                testkey);
 * Semantics: Generates rsa keys given:
 *              a) a seed for p and q (these generators should be created to
 *                   generate numbers of half the size of the keys to be
 *                   generated).
 *              b) a public key with the following field:
 *                   1. the key should be tagged as RSA_SIMPLE_KEY
 *                   2. the expon and fermat_no fields should contain the
 *                        values of the public key we will generate
 *                   3. the bits field should be initialized so we know how
 *                        large the numbers are to be
 *              c) a secret key with the following fields:
 *                   1. the key type tag should be initialized so the routine
 *                        knows which type of a secret key is required
 *            .. for key lengths greater than 127 bits, rsakg_gen_key() will
 *            construct the key in a manner that ensures it is resistant to
 *            certain modes of attack; for key lengths less than 128 bits, the
 *            function simply chooses random primes that are suitable for use
 *            with the supplied public exponent.  It is usually sufficient to
 *            simply rely on luck to ensure these properties for large keys
 *            (700 bits or more), so the constructive approach may be disabled
 *            by setting weak to UT_TRUE.  If testkey is UT_TRUE, a trial
 *            encryption/decryption is made after generating the key.
 * Note:      All archives which are not yet in use should be initialized to
 *              0.  This is needed for error detection (see
 *              Failure).
 * Failure: Failure of the routine is indicated by a return of UT_FALSE.  The
 *            reasons for failure can be:
 *              1. If called with keys which do not conform to the input
 *                   specification this routine will fail.
 *              2. The routine failed to find a VALIDATED RSA key pair.  This
 *                   can be checked by the fact that the secret key bits are
 *                   set and so also are the other fields in the key (i.e.
 *                   secret_p->bits == public_p->bits).  You should kill all
 *                   the archives and try again.
 *              3. If a memory allocation failure occurs (in an internal data
 *                   entity or in for example the user supplied random number
 *                   generators) the routine will fail.  The secret key bits
 *                   field will be set to zero and all the archive set to
 *                   0.
 * Note:    As with most failures of this nature, they are not really
 *            recoverable.
 */
extern utb rsakg_gen_key(prng_inst *, rsa_key *, rsa_key *, utb, utb);

/* Function:  <rsa_sizeof_key2berkey>
 * Syntax:    size = rsa_sizeof_key2berkey(key);
 * Semantics: Returns the number of octets the supplied cst RSA key would
 *              occupy if stored in ASN.1 format (simple key: sequence of two
 *              ASN.1 integers (modulus followed by public exponent); CRT key:
 *              sequence of seven ASN.1 integers (modulus, exponent, p, q,
 *              exp % p, exp % q, q^-1 % p) encoded in a bit string.
 * Failure:   Usually none; in debug mode, returns 0 if called with a null
 *              key pointer.  Inherits failures from asn1_sizeof_size2berlen(),
 *              mpm_sizeof_arc2berinteger() & asn1_sizeof_type2bertag(); none
 *              of these are flagged.
 *            All failure modes abort by default.
 * Errors:    UT_ERR_A1ASZ (UT_ERR_A1ATP)
 * Note:      Reimplements a portion of the arc2berinteger code for use with
 *              Fermat public exponents.  Also incorporates bit string code.
 */
extern sec_off_t rsa_sizeof_key2berkey(rsa_key *key);

/* Function:  <rsa_key2berkey>
 * Syntax:    end = rsa_key2berkey(key, dest);
 * Semantics: Writes key to dest in ASN.1 format.  Returns pointer to octet
 *              after last octet written, or 0 on error (in which case dest may
 *              have had some data written to it already).
 * Failure:   Returns 0 on failure (memory or internal CST problems or, in
 *              debug mode, receipt of a null key pointer or null output
 *              pointer).  Inherits failures from asn1_type2bertag(),
 *              mpm_sizeof_arc2berinteger(), asn1_size2berlen(), &
 *              mpm_arc2berinteger().
 *            All failure modes are either IGNOREd or PRINTed, except for
 *              debug-specific ones, which abort.
 * Errors:    RSA_ENTRNL+0-1,UT_ERR_A1ASZ (UT_ERR_A1AP)
 * Notes:     Incorporates bit string-encoding routines.
 *            Deals correctly with fermat keys (i.e. writes them in longhand).
 */
extern u8 *rsa_key2berkey(rsa_key *key, u8 *dest);

/* Function:  <rsa_berkey2key>
 * Syntax:    end = rsa_berkey2key(src, key);
 * Semantics: Reads the ASN.1 key stored at src, and places it in key.
 *              Returns a pointer to the octet after the last octet read.
 * Failure:   Returns 0 on failure (memory, format, internal CST problems or
 *              bad parameters (debug mode only)).  Inherits failure modes from
 *              asn1_bertag2type(), asn1_berlen2size(), mpm_berinteger2arc(),
 *              & ut_new_mem().
 *            All failure modes are either IGNOREd or PRINTed, except for debug
 *              failures, which abort.
 * Errors:    RSA_EUNEXP+0-1,RSA_ENFBIT,RSA_EXTRAD,RSA_ENTRNL+2,
 *              UT_ERR_A1ITP,UT_ERR_A1ISZ,UT_ERR_NOMEM (UT_ERR_DFREE)
 * Notes:     Incorporates bit string-decoding routines.
 *            Deals correctly with fermat keys (i.e. recognises exponents of
 *              the form 2^(2^k) + 1 and stores them as fermat keys) and CRT
 *              keys.
 */
extern u8 *rsa_berkey2key(u8 *src, rsa_key **key_p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _RSA_H */

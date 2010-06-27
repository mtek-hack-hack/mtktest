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

#ifndef _BSTYPES_H /* Prevent multiple inclusion */
#define _BSTYPES_H

/*loko#include "stdio.h"*/  /* for FILE */
#include "msf_lib.h" /* for FILE */	/* LOKO 22/5 2002 */
/*#include "ansilibs.h"*/  /* for FILE */	/* LOKO 16/10 2001 */	/* LOKO 19/3 2002 */
#include "uttypes.h" /* For the standard types */
#include "padtypes.h" /* For padding algorithms */
#include "hshtypes.h" /* For hash algorithms */
#include "prntypes.h" /* For PRNGs */

#ifdef WITH_sb_ecdsa
#include "sbeccom.h"
#endif /* WITH_sb_ecdsa */ 

#ifdef WITH_sb_ecdh
#include "sbeccom.h"
#endif /* WITH_sb_ecdh */


#ifdef __cplusplus
extern "C" {
#endif

/* Types and constants... */

typedef void *bsapi_id;

/*
 * Key and shrdpub generation parameters vary so much from one
 * algorithm to the next that trying to encompass them all is futile.
 * bsapi deals with these through a single structure - kparam - which is
 * in fact a union of the structures for all supported algorithms which
 * take key generation parameters.
 */


#ifdef WITH_bsapi_des 
/* Type:        <bsapi_kparam_des>
 * Summary:     DES key parameter structure
 */
typedef struct bsapi_kparam_des_s {
  enum {DES_ANYKEY, DES_NOWEAK, DES_NOSEMIWEAK, DES_NOFOURS, DES_NOEIGHTS}
    security;
} bsapi_kparam_des;
#endif

#ifdef WITH_bsapi_rc2
/* Type:        <bsapi_kparam_rc2>
 * Summary:     RC2 key parameter structure
 */ 
typedef struct bsapi_kparam_rc2_s {
  size_t size;
} bsapi_kparam_rc2;
#endif

#ifdef WITH_bsapi_rc4
/* Type:        <bsapi_kparam_rc4>
 * Summary:     RC4 key parameter structure
 */ 
typedef struct bsapi_kparam_rc4_s {
  size_t size;
} bsapi_kparam_rc4;
#endif

#ifdef WITH_bsapi_rc5 
/* Type:        <bsapi_kparam_rc5>
 * Summary:     RC5 key parameter structure
 */
typedef struct bsapi_kparam_rc5_s {
  size_t size;
} bsapi_kparam_rc5;
#endif

#ifdef WITH_bsapi_rijndael
/* Type:        <bsapi_kparam_rijndael>
 * Summary:     Rijndael key parameter structure
 */
typedef struct bsapi_kparam_rijndael_s {
  size_t size;
} bsapi_kparam_rijndael;
#endif

#ifdef WITH_bsapi_nullbsa 
/* Type:        <bsapi_kparam_nullbsa>
 * Summary:     Nullbsa key parameter structure
 */
typedef struct bsapi_kparam_nullbsa_s {
  size_t size;
} bsapi_kparam_nullbsa;
#endif

#ifdef WITH_bsapi_dsa
/* Type:        <bsapi_kparam_dsa_shrdpub>
 * Summary:     DSA shared public parameters structure
 */
typedef struct bsapi_kparam_dsa_shrdpub_s {
  u32      p_length;
  u32      q_length;
} bsapi_kparam_dsa_shrdpub;

/* Type:        <bsapi_kparam_dsa_key>
 * Summary:     DSA key parameter structure
 */
typedef struct bsapi_kparam_dsa_key_s {
  ut_mblk  *shrdpub;
  FILE     *fdb;
} bsapi_kparam_dsa_key;
#endif

#ifdef WITH_bsapi_rsa
/* Type:        <bsapi_kparam_rsa>
 * Summary:     RSA key parameter structure
 */
typedef struct bsapi_kparam_rsa_s { 
  unsigned  kbits;
  unsigned  crt       :   1;
  unsigned  fermat    :   3;
  void     *expmanual;
  unsigned  algorithm :   1;
  unsigned  test      :   1;
  FILE     *fdb;
} bsapi_kparam_rsa;
#endif


#ifdef WITH_sb_ecdsa 
/* Type:        <bsapi_kparam_sb_ecdsa_shrdpub>
 * Summary:     ECDSA shared public parameters structure
 */
typedef struct bsapi_kparam_sb_ecdsa_com_s {
  SB_EllipticCurveID curve;
} bsapi_kparam_sb_ecdsa_shrdpub;

/* Type:        <bsapi_kparam_sb_ecdsa_key>
 * Summary:     ECDSA key parameter structure
 */
typedef struct bsapi_kparam_sb_ecdsa_key_s {
  ut_mblk    *curve;
  sb_pcFlag   pcFlag;
} bsapi_kparam_sb_ecdsa_key;
#endif

#ifdef WITH_sb_ecdh
/* Type:        <bsapi_kparam_sb_ecdh_shrdpub>
 * Summary:     ECDH shared public parameters structure
 */
typedef struct bsapi_kparam_sb_ecdh_com_s {/**/
  SB_EllipticCurveID curve;
} bsapi_kparam_sb_ecdh_shrdpub;

/* Type:        <bsapi_kparam_sb_ecdh_key>
 * Summary:     ECDH key parameter structure
 */
typedef struct bsapi_kparam_sb_ecdh_key_s {
  ut_mblk    *curve;
  sb_pcFlag   pcFlag;
} bsapi_kparam_sb_ecdh_key;
#endif 

#ifdef WITH_dh_dh
typedef struct bsapi_kparam_dh_shrdpub_s {
  unsigned int primeBits;
  unsigned int exponentBits;
} bsapi_kparam_dh_shrdpub;

typedef struct bsapi_kparams_dh_key_s {
  ut_mblk *shrdpub;
} bsapi_kparam_dh_key;
#endif /* WITH_dh_dh */

union bsapi_kparam_u { /* bsapi_kparam_u: union of the kparams */
#ifdef WITH_bsapi_des
  bsapi_kparam_des des;
#endif /* WITH_bsapi_des */
#ifdef WITH_bsapi_rsa
  bsapi_kparam_rsa rsa;
#endif /* WITH_bsapi_rsa */
#ifdef WITH_bsapi_dsa
  bsapi_kparam_dsa_shrdpub dsa_shrdpub;
  bsapi_kparam_dsa_key dsa_key;
#define        dsa_com        dsa_shrdpub
#endif /* WITH_bsapi_dsa */
#ifdef WITH_sb_ecdsa
  bsapi_kparam_sb_ecdsa_shrdpub sb_ecdsa_shrdpub;
  bsapi_kparam_sb_ecdsa_key sb_ecdsa_key;
#define   sb_ecdsa_com   sb_ecdsa_shrdpub
#endif /* WITH_sb_ecdsa */
#ifdef WITH_sb_ecdh
  bsapi_kparam_sb_ecdh_shrdpub sb_ecdh_shrdpub;
  bsapi_kparam_sb_ecdh_key sb_ecdh_key;
#define   sb_ecdh_com   sb_ecdh_shrdpub
#endif /* WITH_sb_ecdh */
#ifdef WITH_bsapi_rc2
  bsapi_kparam_rc2 rc2;
#endif /* WITH_bsapi_rc2 */
#ifdef WITH_bsapi_rc4
  bsapi_kparam_rc4 rc4;
#endif /* WITH_bsapi_rc4 */
#ifdef WITH_bsapi_rc5
  bsapi_kparam_rc5 rc5;
#endif /* WITH_bsapi_rc5 */
#ifdef WITH_bsapi_rijndael
  bsapi_kparam_rijndael rijndael;
#endif /* WITH_bsapi_rijndael */
#ifdef WITH_dh_dh
  bsapi_kparam_dh_shrdpub dh_shrdpub;
  bsapi_kparam_dh_key dh_key;
#endif /* WITH_dh_dh */
};

/* Type:        <bsapi_kparam>
 * Summary:     Union of key generation parameters for bsapi algorithms
 * Description: The bsapi_kparam structure is a union of the parameter
 *              structures required by every bsapi key generation function.
 *              See the individual algorithms for details.
 */
typedef union bsapi_kparam_u bsapi_kparam;


/* parameters for shrdpub validation. Currently only DSA is supported */

/* Type:         <bsapi_shrdpubval_param_dsa>
 * Summary:      DSA shrdpub validation parameter structure
 */

#ifdef WITH_bsapi_dsa
typedef struct bsapi_shrdpubval_param_dsa_s {
  u32 p_len;
  u32 q_len;
} bsapi_shrdpubval_param_dsa;
#endif

union bsapi_shrdpubval_param_u {
#ifdef WITH_bsapi_dsa
  bsapi_shrdpubval_param_dsa dsa;
#endif /* WITH_bsapi_dsa */
  int                        dummy;  /* prevent empty union warnings */
};


/* parameters for key validation. Currently only DSA is supported */

/* Type:         <bsapi_keyval_param_dsa>
 * Summary:      DSA key validation parameter structure
 */

#ifdef WITH_bsapi_dsa
typedef struct bsapi_keyval_param_dsa_s {
  ut_mblk  *shrdpub;
} bsapi_keyval_param_dsa;
#endif

union bsapi_keyval_param_u {
#ifdef WITH_bsapi_dsa
  bsapi_keyval_param_dsa dsa;
#endif /* WITH_bsapi_dsa */
  int                    dummy;  /* prevent empty union warnings */
};


/* Type:        <bsapi_keyval_param>
 * Summary:     Union of key validation parameters for bsapi algorithms
 * Description: The bsapi_keyval_param structure is a union of the parameter
 *              structures required by every bsapi key validation function.
 *              See the individual algorithms for details.
 */
typedef union bsapi_keyval_param_u bsapi_keyval_param;

/* Type:        <bsapi_shrdpubval_param>
 * Summary:     Union of shrdpub validation parameters for bsapi algorithms
 * Description: The bsapi_shrdpubval_param structure is a union of the parameter
 *              structures required by every bsapi shrdpub validation function.
 *              See the individual algorithms for details.
 */
typedef union bsapi_shrdpubval_param_u bsapi_shrdpubval_param;


/* Type:        <bsapi_mode>
 * Summary:     Gives encryption mode information
 * Description: The bsapi_mode structure uses the following fields:
 *              op -- indicates whether a session is going to be used 
 *                to encrypt, decrypt, sign, or verify data;  
 *              mode -- indicates which ANSI mode (Electronic Code Book, 
 *                Cipher Block Chaining, Cipher FeedBack, or Output 
 *                FeedBack) to use.
 *              triple -- indicates whether triple encryption is to be used. 
 *                All basic CST block ciphers (DES, IDEA, RC2) support this 
 *                option in both BSAPI_TRIPLE and BSAPI_CHAIN3 form. For 
 *                more details on the difference between the two triple modes, 
 *                see the CST developer's manual. In general, if you want to 
 *                use a triple mode, BSAPI_TRIPLE is both more secure and more 
 *                interoperable. If you're using triple mode, supply two or 
 *                three keys to the keys field of your bsapi_kset. To encrypt, 
 *                the message is encrypted with the first, decrypted with the 
 *                second, and encrypted with the third (or first if no third 
 *                is supplied). Decrypting reverses the procedure.
 *              key_type -- indicates whether the key(s) are being supplied as 
 *                plain keys or as precomputed key schedules. The latter is 
 *                often faster. The schedule should always be the encryption
 *                schedule; the inverse schedule will be computed as
 *                necessary. This field is only applicable to a few
 *                algorithms.
 *              fast -- only applies to DES. It indicates that the 
 *                cryptographically useless initial and final permutations 
 *                should not be performed (affords a 10% speedup in software).
 * Notes:       For more information on which fields have to be specified for
 *              a given algorithm, see the bsapi_start_ALG() function 
 *              description for that algorithm.
 */
typedef enum {
  BSAPI_ENCRYPT, BSAPI_DECRYPT, BSAPI_SIGN, BSAPI_VERIFY
} bsapi_mode_op;

typedef enum {
  BSAPI_ECB, BSAPI_CBC, BSAPI_CFB, BSAPI_OFB
} bsapi_mode_mode;

typedef enum {
  BSAPI_SINGLE, BSAPI_TRIPLE, BSAPI_CHAIN3
} bsapi_mode_triple;

typedef enum {
  BSAPI_KEY, BSAPI_SCHEDULE
} bsapi_mode_key_type;

typedef enum {
  BSAPI_ANSI, BSAPI_FAST
} bsapi_mode_fast;

typedef struct bsapi_mode_s {
  bsapi_mode_op       op;
  bsapi_mode_mode     mode;
  bsapi_mode_triple   triple;
  bsapi_mode_key_type key_type;
  bsapi_mode_fast     fast;
} bsapi_mode;

/* Type:         <bsapi_kset>
 * Summary:     Session initialization information for bsapi algorithms
 * Description: The bsapi_kset structure is passed to bsapi_start_ALG().
 *              Details of which fields need to be filled in for each
 *              algorithm are supplied in the reference guide entry for
 *              that algorithm's bsapi_start_ALG() function.
 */

typedef enum {
  BSAPI_KEY_TYPE_DEFAULT, BSAPI_SECRET, BSAPI_PUBLIC
} bsapi_kset_key_type;

#define BSAPI_PRIVATE BSAPI_SECRET

typedef enum {
  BSAPI_DATA_TYPE_DEFAULT, BSAPI_DATA_TYPE_DATA, BSAPI_DATA_TYPE_HASH
} bsapi_kset_data_type;

typedef struct bsapi_kset_s {
  ut_mblk              *keys;
  ut_mblk              *shrdpub;
#define   community     shrdpub
  u32                   effbits;   /* effective key-length -- RC2 only */
  int                   rounds;    /* number of rounds -- RC5 only */
  ut_mblk              *iv;
  unsigned              feedback;  /* OFB and CFB only */
  const pad_alg        *padalg;
  pad_params           *padpar;
#ifdef WITH_hash
  const hash_alg       *hashalg;
  unsigned              hashbits;
#endif /* WITH_hash */
  bsapi_kset_data_type  data_type; /* when signing/verifying, are we
                                    * passed the mesage text or its hash */
  ut_mblk              *pnonce;    /* precomputed pnonces for DSA */
#define    k_values     pnonce
  FILE                 *pnfprnt;   /* footprint database for pnonces in DSA */
#define    kfprnt       pnfprnt
  bsapi_kset_key_type   key_type;  /* deprecated; use pad_params */
} bsapi_kset;


/* Type:         <bsapi_pbe_kset>
 * Summary:     Session initialization information for bsapi PBE algorithms
 * Description: The bsapi_pbe_kset structure is passed to bsapi_start_pbe()
 *              and contains the fields necessary to start passphrase-based
 *              encryption under PKCS#5 v 1 or PKCS#12. These are:
 *
 *              objid -- one of the algorithm identifiers 
 *                algid_pkcs12_pbeWithSHAAnd128BitRC4 ...
 *                algid_pkcs5_pbeWithMD5AndDES_CBC given in algid.h.
 *              salt -- a ut_mblk containing the "salt" data which is appended
 *                to the passphrase before processing. This should typically be 
 *                8-20 bytes long, the longer the better.
 *              count -- the number of times the passphrase+salt is to be hashed
 *                before the output is taken for use as a key.
 *              passphrase -- the passphrase! Note that for PKCS#12 passphrase 
 *                based encryption (all the algids whose names begin with 
 *                algid_pkcs12) the passphrase which is processed is a Unicode 
 *                string. The next field,  passphraseIsAscii, can be used to 
 *                tell BSAPI if the passphrase data should be converted from 
 *                ASCII to Unicode (passphraseIsAscii = 1) or should be 
 *                interpreted as Unicode (passphraseIsAscii = 0). If the
 *                passphrase is ASCII, passphrase.used should be set
 *                equal to strlen(passphrase.data). If the passphrase is
 *                Unicode, passphrase.used should be set equal to
 *                2 * ut_bmp_strlen(passphrase.data), and passphrase.data must
 *                consist of the Unicode passphrase converted to 2-byte
 *                big-endian encoding. Simply casting a u16* to a u8* is
 *                *NOT* correct.
 *              passphraseIsAscii -- see passphrase. Tells BSAPI whether the 
 *                data in passphrase.data should be taken literally 
 *                (passphraseIsAscii = 0) or should be taken as ASCII data 
 *                and converted into a Unicode string by interpolating a null 
 *                byte between each pair of data bytes.
 *
 * Notes:      For passphrase-based encryption the chaining mode (ECB,
 *             CBC, CFB, OFB) is given by the OID, so bsapi_start_pbe
 *             ignores the mode.mode field.
 *
 *             If the PBE encryption used is PKCS#12 v1, the null
 *             terminating wide character on the string is counted as
 *             part of the passphrase data to be hashed. This is taken
 *             care of internally by BSAPI. When filling in the
 *             bsapi_pbe_kset with a Unicode passphrase, passphrase.used
 *             should be set to 2 * ut_bmp_strlen(passphrase), in other
 *             words the trailing NULL character should not be
 *             indicated.
 */


typedef struct bsapi_pbe_kset_s {
  u32          *objid;
  ut_mblk      *salt;
  int           count;
  ut_mblk      *passphrase;
  int           passphraseIsAscii;
} bsapi_pbe_kset;


/* Type:        <bsapi_entrust_pbm_kset>
 * Summary:     Session initialization information for Entrust-style PBM
 * Description: The bsapi_entrust_pbm_kset structure is passed to
 *              bsapi_start_entrust_pbm() and contains the fields
 *              necessary to start Entrust-style Passphrase-Based MACing
 *              (PBM). The fields are:
 *
 *              passphrase -- the passphrase. This can be Unicode or
 *                ASCII; the algorithm treats it simply as data of
 *                length passphrase->used.
 *              salt -- a ut_mblk containing the "salt" data which is appended
 *                to the passphrase before processing. This should typically be 
 *                the length of the output from the hash_alg owf.
 *              owf -- the hash_alg that is used to hash the passphrase
 *                + salt to produce the HMAC key.
 *              count -- the number of times to hash the passphrase and
 *                salt with owf to produce the HMAC key.
 *              mac -- the hash_alg that is used to create the HMAC.
 *                Must be one of the HMAC hash_algs (eg hash_hmac_sha).
 */

typedef struct bsapi_entrust_pbm_kset_s {
  ut_mblk *passphrase;
  ut_mblk *salt;                /* Should be the length of owf output */
  const hash_alg *owf;          /* the hash function for key derivation */
  u32 count;                    /* the iteration count, should be 1024 */
  const hash_alg *mac;          /* the actual mac function to feed */
} bsapi_entrust_pbm_kset;

/* Type:        <bsapi_type>
 * Summary:     Algorithm types for bsapi_alg structure
 * Description: Four basic types of cryptographic system are possible with
 *              bsapi, indicated by the following values.
 *
 * BSAPI_SYMMETRIC_CIPHER -- encryption algorithms where the same key is used
 *                         to decrypt a message as was used to encrypt
 *                         it.  Digital signatures are not possible with
 *                         these algorithms, although message
 *                         authentication checks are possible.
 * BSAPI_PUBLIC_CIPHER -- encryption algorithms where a different key is used
 *                      to decrypt a message to that used to encrypt it. 
 * BSAPI_SIGNATURE_FIXED -- algorithms which may only be used for digital
 *                        signatures and for which the programmer may
 *                        not specify a message digest algorithm. No
 *                        algorithms of this type are currently
 *                        supported.
 * BSAPI_SIGNATURE_USER -- algorithms which may only be used for digital
 *                       signatures but for which the programmer may
 *                       specify a message digest algorithm.
 *
 * The RSA algorithm is classified as a BSAPI_PUBLIC_CIPHER even though
 * it can also be used as a BSAPI_SIGNATURE_USER type algorithm.
 */

typedef enum {
  BSAPI_SYMMETRIC_CIPHER, BSAPI_PUBLIC_CIPHER, BSAPI_SIGNATURE_FIXED,
  BSAPI_SIGNATURE_USER
} bsapi_type;


/* Type:        <bsapi_algn>
 * Summary:     Canonical algorithm numbers
 * Description: The bsapi_algn enum contains the canonical algorithm 
 *              numbers for use in the bsapi_alg structure.
 */

typedef enum {
  BSAPI_NONE,
  BSAPI_DES,
  BSAPI_3DES,
  BSAPI_RSA,
  BSAPI_BSA4,
  BSAPI_BSA5,
  BSAPI_IDEA,
  BSAPI_DSA,
  BSAPI_RC2,
  BSAPI_RC4,
  BSAPI_PBE,
  BSAPI_SB_ECDSA,
  BSAPI_ENTRUST_PBM,
  BSAPI_RC5,
  BSAPI_DH_PKCS3,  /* dummy one for bsafe wrapper */
  BSAPI_RIJNDAEL,
  BSAPI_MAX
} bsapi_algn;


#define   BSAPI_NULLBSA  (BSAPI_MAX + 1)

/* Type:         <bsapi_alg>
 * Summary:     Function pointers for BSAPI algorithms
 * Description: The fields in this structure are as follows.
 *              name -- A null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a bsapi_alg from the bsapis[] array.
 *              number -- one of the canonical bsapi_algn numbers given above.
 *              type -- General algorithm type information. See bsapi_type for 
 *                more information. Note that there is no supported algorithm 
 *                of type BSAPI_SIGNATURE_FIXED.
 *              op --  Bit 0 of this field, if set, indicates that the 
 *                algorithm may be used for encryption. Bit 1, if set, 
 *                indicates that the algorithm may be used for digital 
 *                signatures.
 *              mode -- Bits 0 through 3 of this field indicate whether the 
 *                corresponding ANSI mode of operation (respectively ECB, 
 *                CBC, CFB, and OFB) may be selected.
 *              triple -- Bit 0 of this field, if set, indicates that the 
 *                algorithm may be used in BSAPI_TRIPLE mode. Bit 1 indicates 
 *                whether the algorithm supports BSAPI_CHAIN3 mode.
 *              key_type -- Bit 0 of this field, if set, indicates that keys 
 *                may be supplied as raw schedules (algorithm-specific 
 *                information will be required in order to make use of this 
 *                feature) in order to save on computation while starting a 
 *                session.
 *              fast -- Bit 0 of this field, if set, indicates that a 
 *                non-standard (but cryptographically insignificant) tweak 
 *                may be applied to the algorithm in order to speed its 
 *                operation up.  It is likely that DES is the only algorithm 
 *                which will ever support this feature.
 *              pad -- Bit 0 of this field, if set, indicates that padding is 
 *                relevant. It is set for all ciphers except stream ciphers 
 *                (currently BSA4, BSA5, and RC4) and DSA.
 *              kbits -- Gives the length of the key. If this length is 0 the
 *                algorithm has a variable length key.
 *              usesIV -- If this field is zero, the algorithm will not take
 *                an IV under any circumstances. Otherwise, it will take an IV
 *                under some circumstances (such as if the mode is not ECB).                 
 *
 * The remaining fields in the structure are pointers to the bsapi_FUNC_ALG
 * functions used by the algorithm ALG, as follows.
 *
 * Function:    <bsapi_generate_sharedparams_ALG>
 * Summary:     Generates shared public parameters.
 * Syntax:      int rval = bsapi_generate_sharedparams_ALG(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_sharedparams_ALG() function generates
 *              shared public parameters if ALG requires it, and returns 0
 *              otherwise.
 *
 * Function:    <bsapi_generate_key_ALG>
 * Summary:     Generates a key for ALG.
 * Syntax:      int rval = bsapi_generate_key_ALG(prng_inst *prng, (ut_mblk
 *              *) &spt, 0, (bsapi_kparam *) &kparam);
 * Description: The bsapi_generate_key_ALG() function takes a set of key
 *              parameters kparam and a random number generator prng,
 *              and generates key or keypair for ALG. The bsapi_kparam 
 *              structure varies considerably from algorithm to algorithm
 *              and is described for a given algorithm ALG in
 *              bsapi_generate_key_ALG().
 *
 * Function:    <bsapi_generate_privatenonce_ALG>
 * Summary:     Generates private nonces.
 * Syntax:      int rval = bsapi_generate_privatenonce_ALG(prng_inst *prng,
 *              (ut_mblk *) &cpt, (bsapi_kparam *) &param);
 * Description: The bsapi_generate_privatenonce_ALG() function generates
 *              private nonces for those algorithms which require a private
 *              nonce when encrypting or signing and which can generate the
 *              nonces off-line.
 * 
 * Function:    <bsapi_sizeof_iv_ALG>
 * Summary:     Gets length of initialisation vector for ALG.
 * Syntax:      size_t ivlen = bsapi_sizeof_iv_ALG((bsapi_mode *) &bmode, 0);
 * Description: The bsapi_sizeof_iv_ALG() function returns the number of
 *              octets of memory that must be allocated to hold the
 *              Initialisation Vector for the algorithm ALG when it is used
 *              according to bmode. 
 *
 * Function:    <bsapi_start_ALG>
 * Summary:     Starts an encryption session using ALG.
 * Syntax:      bsapi_id sid = bsapi_start_ALG((bsapi_mode *) &bmode,
 *              prng_inst *prng, (bsapi_kset *) &kset);
 * Description: The bsapi_start_ALG() function, given operation mode
 *              information bmode, the associated key information kset, and
 *              a prng_inst * prng, creates and returns a new session to
 *              perform the requested operation. 
 *              - both bmode and kset should be initialized to 0. This
 *                ensures that if you neglect to fill in an important field
 *                the CST will provide a sensible default.
 * Memory:      The memory allocated by this function is disposed of by 
 *              calling either bsapi_finish_ALG() or
 *              bsapi_kill_ALG(). If the session needs to be
 *              terminated prematurely, call bsapi_kill_ALG(sid).
 *              If a session terminates normally (by the use of
 *              bsapi_finish_ALG()) then the session data will be
 *              freed whether or not the actual call to
 *              bsapi_finish_ALG() was successful.
 * 
 * Function:    <bsapi_append_ALG>
 * Summary:     Feeds data into a bsapi session for processing.
 * Syntax:      int rval = bsapi_append_ALG(u8 *ptr, size_t len, bsapi_id sid);
 * Description: The bsapi_append_ALG() function writes len octets from ptr
 *              into a bsapi session sid. The processed data is held inside
 *              the session until a successful call to
 *              bsapi_readmost_ALG(), bsapi_read_ALG(), or
 *              bsapi_finish_ALG(). The session ID sid must have originally
 *              been returned from a call to the bsapi_start_ALG() function.
 * 
 * Function:    <bsapi_read_ALG>
 * Summary:     Reads all processed data from an encryption session.
 * Syntax:      ut_mblk_list mlist = bsapi_read_ALG(bsapi_id sid);
 * Description: The bsapi_read_ALG function reads all available data from a
 *              bsapi session sid and returns it in the form of a
 *              ut_mblk_list. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_ALG() function.
 *              This function is provided simply so that the developer can
 *              wrap certain other APIs around bsapi; in the normal course
 *              of events you should use bsapi_readmost_ALG().
 * Notes:       The function always returns 0 if called in the middle of a
 *              signing or verification session.
 *
 * Function:    <bsapi_sizeof_readmost_ALG>
 * Summary:     Gives size of output from bsapi_readmost_ALG() corresponding to
 *              input bytes being fed to the session.
 * Syntax:      size_t rval = bsapi_sizeof_ readmost_ALG(size_t input, 
 *                bsapi_id sid);
 * Description: The bsapi_sizeof_readmost_ALG() function gives the length of 
 *              output that would be produced by a call to bsapi_readmost_ALG() 
 *              subsequent to input bytes of data being fed to the session sid 
 *              with a call to bsapi_append_ALG().
 * 
 * Function:    <bsapi_readmost_ALG>
 * Summary:     Reads as much processed data as is safe from an encryption
 *              session.
 * Syntax:      ut_mblk_list mlist = bsapi_readmost_ALG(bsapi_id sid);
 * Description: The bsapi_readmost_ALG() function reads all available data
 *              from a bsapi session sid, except that it leaves sufficient 
 *              data within the session so that an immediate call to 
 *              bsapi_finish_ALG() will be able to attempt to unpad the data 
 *              if necessary. The data is returned in the form of a 
 *              ut_mblk_list. The session ID sid must have originally been 
 *              returned from a call to the bsapi_start_ALG() function. 
 *
 *              This function is preferred to bsapi_read_ALG() for all normal
 *              operations.
 * 
 * Function:    <bsapi_finish_ALG>
 * Summary:     Finishes a bsapi session using ALG, returns output and frees
 *              memory.
 * Syntax:      int rval = bsapi_finish_ALG(bsapi_id sid, (ut_mblk_list *)
 *              &mlist);
 * Description: The bsapi_finish_ALG() function finishes the bsapi session
 *              sid for ALG. The memory pointed to by sid is deallocated
 *              following a call to bsapi_finish_ALG() whether the return
 *              value from the function indicates success or not. The
 *              session ID sid must have originally been returned from a
 *              call to the bsapi_start_ALG() function. On successful
 *              completion, mlist will contain all of the processed data
 *              which has not been output in previous calls to
 *              bsapi_read_ALG() or bsapi_readmost_ALG().
 * 
 * Function:    <bsapi_sizeof_output_ALG>
 * Summary:     Gives the amount of output from a given input to an ALG session.
 * Syntax:      off_t outqty = bsapi_sizeof_output_ALG(bsapi_id sid, off_t
 *              inqty);
 * Description: The bsapi_sizeof_output_ALG() function returns the maximum
 *              amount of output which could be produced if inqty octets of
 *              data were input into the session sid. This does not include
 *              the effects of any data that is buffered inside the
 *              session. The session ID sid must have originally been
 *              returned from a call to the bsapi_start_ALG() function for
 *              some algorithms; for others it can be 0.
 * 
 * Function:    <bsapi_kill_ALG>
 * Summary:     Kills an ALG session, releasing all resources.
 * Syntax:      bsapi_kill_ALG(bsapi_id sid);
 * Description: The bsapi_kill_ALG() function shuts down a bsapi_ALG
 *              session sid, freeing all memory associated with the session
 *              and returning no output. It is for use when it is necessary
 *              to terminate a session unfinished. The session ID sid must
 *              have originally been returned from a call to the
 *              bsapi_start_ALG() function.
 *
 * Function:    <bsapi_get_name_ALG>
 * Summary:     Returns bsapi_ALG.name.
 * Syntax:      const char *rval = bsapi_get_name_ALG();
 * Description: The bsapi_get_name_ALG() function returns the bsapi_ALG.name
 *              field. This is the field which ut_choose uses to convert from
 *              a string to a bsapi_alg algorithm.
 */
  typedef struct bsapi_alg_s {
  const char    *name;
  bsapi_algn     number;
  bsapi_type     type;
  unsigned       op       :   2;
  unsigned       mode     :   4;
  unsigned       triple   :   2;
  unsigned       key_type :   1;
  unsigned       fast     :   1;
  unsigned       pad      :   1;
  unsigned       kbits;
  unsigned       usesIV;
  int           (CST16EXPORTTYPE *generate_sharedparams)(prng_inst *, ut_mblk *,
                   bsapi_kparam *);
  int           (CST16EXPORTTYPE *generate_key)(prng_inst *, ut_mblk *, 
                   ut_mblk *, bsapi_kparam *);
  int           (CST16EXPORTTYPE *generate_privatenonce)(prng_inst *, ut_mblk *,
                   bsapi_kparam *);
  size_t        (CST16EXPORTTYPE *sizeof_iv)(bsapi_mode *, bsapi_kset *);
  bsapi_id      (CST16EXPORTTYPE *start)(bsapi_mode *, prng_inst *, 
                   bsapi_kset *);
  sec_off_t         (CST16EXPORTTYPE *sizeof_output)(bsapi_id, sec_off_t);
  int           (CST16EXPORTTYPE *append)(u8 *, size_t, bsapi_id);
  ut_mblk_list  (CST16EXPORTTYPE *read)(bsapi_id);
  size_t        (CST16EXPORTTYPE *sizeof_readmost)(size_t, bsapi_id);
  ut_mblk_list  (CST16EXPORTTYPE *readmost)(bsapi_id);
  void          (CST16EXPORTTYPE *kill)(bsapi_id);
  int           (CST16EXPORTTYPE *finish)(bsapi_id, ut_mblk_list *);
  const char   *(CST16EXPORTTYPE *get_name)(void);
  void          (CST16EXPORTTYPE *direct)(bsapi_id, u8 *, u8 *, size_t);
} bsapi_alg;

#define generate_community generate_sharedparams
#define make_kstruct       generate_privatenonce

#ifdef __cplusplus
}
#endif

#endif /* _BSTYPES_H */

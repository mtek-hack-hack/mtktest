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

#ifndef _CSTOPT_H /* Prevent multiple inclusion */
#define _CSTOPT_H 1

#include "sec_cfg.h"

#include "config.h"  /* for __DOS__ */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define CST16EXPORTTYPE
#define CST16EXPORTDATA
#define CST32EXPORTTYPE
#define CST32EXPORTDATA

/* Options governing the type of exported function. Currently, these are only 
 * defined for the compiler flag _CSTFORWIN16DLL. This will gradually be expanded
 * to include the targets _CSTFORWIN32DLL and others.
 */

#if defined (BUILDING_CST_LIB) || defined (BUILDING_CST_DLL)
#define BUILDING_CST_LIBRARY
#endif

#define UT_LOG_EXPORTTYPE
#define CSTEXPORTTYPE
#define CSTEXPORTDATA

#ifdef WIN32
#    define CST16EXPORTTYPE
#    define CST16EXPORTDATA
#    ifdef BUILDING_CST_LIBRARY
#        ifdef BUILDING_CST_DLL   /* If building DLL */
#            define CST32EXPORTTYPE __declspec(dllexport)
#            define CST32EXPORTDATA __declspec(dllexport)
#            undef UT_LOG_EXPORTTYPE
#            define UT_LOG_EXPORTTYPE __declspec(dllexport)
#        else /* Building static library */
#            define CST32EXPORTTYPE
#            define CST32EXPORTDATA 
#        endif
#    else  /* ndef BUILDING_CST_LIBRARY -- selects these lines automatically
            * when you're linking to the CST */
#        ifdef _CST_LINK_TO_DLL
#            define CST32EXPORTTYPE __declspec(dllimport)
#            define CST32EXPORTDATA CST16EXPORTDATA __declspec(dllimport)
#            undef UT_LOG_EXPORTTYPE
#            define UT_LOG_EXPORTTYPE __declspec(dllimport)
#        else
#            define CST32EXPORTTYPE
#            define CST32EXPORTDATA
#        endif
#    endif /* def/ndef BUILDING_CST_LIBRARY */
#else
#    define CST32EXPORTTYPE
#    define CST32EXPORTDATA
#    ifdef _CSTFORWIN16DLL
#        include "windows.h"
#        define CST16EXPORTTYPE __export FAR __pascal
#        define CST16EXPORTDATA __export FAR
#    else
#        define CST16EXPORTTYPE
#        define CST16EXPORTDATA
#    endif
#endif



/* Number of small primes to divide by before making a Rabin test; the maximum
 * (higher numbers will be treated as this) is 4245, where 10.581% of numbers
 * will be accepted; 11.000% will be accepted if only 2954 test divisions are
 * made, 11.500% with 1988, 12.000% with 1385, 12.500% with 995, 13.000% with
 * 734, 13.501% with 554, 14.003% with 427, 15.006% with 268, 16.007% with 179,
 * 17.020% with 125, 18.032% with 90, 19.018% with 69, and 20.071% with 53.
 * These figures are twice what might be expected because even numbers are
 * automatically discounted.
 */
#ifndef DIV_PRIMES
#define DIV_PRIMES (995) /* 12.500% */
#endif /* DIV_PRIMES */

/* Number of Rabin tests to make before accepting a number as prime */
#ifndef STRONG_TESTS
#define STRONG_TESTS (5)
#endif /* STRONG_TESTS */

/* If you need to use some alternative to exit(), define it here. */
/* #ifdef _WINDLL  ANAO 19/12 2002
#define cst_exit(n) dllexit(n)
#else
#define cst_exit(n) exit(n)
#endif*/

/* Footprinting: 
 * Number of bits each function should hash into. This should be larger than
 * log2(estimated key population) 
 */
#define FPRNT_BITS 17

/* Number of hash functions */
#define FPRNT_FUNCS 5

/* FPRNT_BITS=28 & FPRNT_FUNCS=6 should ensure a 1.4x10^-6 probability of false 
 * duplication claims given a key population of 5 million. FPRNT_BITS=17 & 
 * FPRNT_FUNCS=5 should ensure a 2.14x10^-6 probability given a key population
 * of 2000. 
 */

/* Seed for generation of footprinting hash tables; passed to srandom(). */
#define FPRNT_SEEDVAL (0xfedcba98UL)

/* Size of dead zone at end of each block of memory (used in debug mode to 
 * check for overrunning bounds). 
 */
#define XMEM (8)

/* Do these here rather than with command-line options. */

#ifndef WITH_options

#ifndef SEC_CFG_SWWIM
	#define WITH_rsa_no_key_gen
#endif
#define WITH_bsapi
#define WITH_bsapi_blockc
/*#define WITH_bsapi_bsa4*/
/*#define WITH_bsapi_bsa5 */
#if (defined(SEC_CFG_3DES_CBC_EDE) || defined(SEC_CFG_3DES_CBC_EDE_INTERN))
	#define WITH_bsapi_des
	#define WITH_bsapi_tripdes
#endif
#if ((defined SEC_CFG_DHE_DSS) && (defined SEC_CFG_SWWIM))
	#define WITH_bsapi_dsa
#endif
#ifdef SEC_CFG_SWWIM
	#define WITH_bsapi_rsa
#endif
/*#define WITH_bsapi_rc2*/
#if( defined(SEC_CFG_RC4) || defined(SEC_CFG_RC4_INTERN) )
  #define WITH_bsapi_rc4
#endif
#if (defined(SEC_CFG_RC5_CBC) || defined(SEC_CFG_RC5_CBC_INTERN))
	#define WITH_bsapi_rc5
#endif
#ifndef SEC_CFG_SWWIM
	#define WITH_bsapi_rsa_no_key_gen
#endif
/*#define WITH_bsapi_pbe*/
/*#define WITH_bsapi_nullbsa*/
/*#define WITH_bsapi_entrust_pbm*/
#define WITH_hash 
/*#define WITH_hash_mdc2*/
/*#define WITH_hash_ripemd*/
/*#define WITH_hash_sqmod*/
/*#define WITH_hash_bhf*/
/*#define WITH_hash_bsah*/
#define WITH_hash_md5
#ifdef SEC_CFG_MD2
  #define WITH_hash_md2
#endif 
#define WITH_hash_sha
/*#define WITH_hash_rmd160*/
/*#define WITH_hash_nullhash*/
#define WITH_mpm
#define WITH_pad
/*#define WITH_pad_padnone*/
/*#define WITH_pad_bdes */
#define WITH_pad_pkcs5
/*#define WITH_pad_brsa */
#define WITH_pad_pkcs1
/*#define WITH_pad_brsaorig*/
/*#define WITH_pad_oaeppkcs*/
/*#define WITH_pad_oaepset1*/
/*#define WITH_pad_iso9796*/
/*#define WITH_pkcs12*/
/*#define WITH_prng_r48*/
#define WITH_prng
#define WITH_prng_bbs 
/*#define WITH_prng_hshf*/
/*#define WITH_prng_hshs*/
/*#define WITH_prng_lcg*/
/*#define WITH_prng_fips186*/
/*#define WITH_prng_cesgrng*/
/*#define WITH_prng_nullprng*/
#if (defined _WIN32 && !(defined WIN64))
/*#define WITH_prng_intelisd*/
/*#define WITH_prng_entpoll*/
/*#define WITH_mma*/
/*#define WITH_mma_mmavc_c*/
#endif /* def _WIN32 */
#ifdef sparc
/*#define WITH_mma
#define WITH_mma_mmasparc_S*/
#endif /* sparc */
/*#define WITH_mgf*/
/*#define WITH_hash_hmac*/
#ifdef SEC_CFG_MD2
  #define WITH_hash_hmacmd2
#endif
#define WITH_hash_hmacmd5
#define WITH_hash_hmacsha
/*#define WITH_hash_hmacrmd*/
/*#define WITH_hash_hmacr160*/
#if ((defined SEC_CFG_DHE_DSS) && (defined SEC_CFG_SWWIM))
	#define WITH_dh_dh
#endif
/*#define WITH_kdf*/
/*#define WITH_pbe_pbe*/
/*#define WITH_secshare_shamir*/
/*#define WITH_threads*/
#define CST_NO_UNICODE
#define CST_NO_THREADS

/* Allows us to test new functions internally. Customers should not
 * define this flag. 
 */

#ifdef _CST_INTERNAL_BUILD
#define WITH_capi
#define WITH_bsapi_idea
#define WITH_bsapi_rc5
#ifndef WITH_sb_ecdsa
#  define WITH_sb_ecdsa
#  define WITH_sb
#endif /* ndef WITH_sb_ecdsa */
#ifndef WITH_sb_ecdh
#  define WITH_sb_ecdh
#  define WITH_sb
#endif /* ndef WITH_sb_ecdsa */
#endif /* def CST_INTERNAL_BUILD */

/* This should ALWAYS remain commented out, but the line is present as a 
 * reminder that WITH_capi is defined for the Unix builds.
 *
 * #define WITH_capi
 */


/* DON'T EDIT THESE! These lines specify the options that must be
 * defined for consistency.
 */

#if (defined WITH_bsapi_dsa && !(defined WITH_hash_sha))
#  define WITH_hash_sha
#endif

#ifdef WITH_cstut
#  ifndef WITH_bsapi_des
#    define WITH_bsapi_des
#  endif
#  ifndef WITH_bsapi_rsa
#    define WITH_bsapi_rsa
#  endif
#endif   /* def WITH_cstut */

#ifdef WITH_bsapi_lorapi
#  ifndef WITH_bsapi_idea 
#    define WITH_bsapi_idea 
#  endif
#  ifndef WITH_bsapi_rsa 
#    define WITH_bsapi_rsa 
#  endif
#  ifndef WITH_pad_brsa
#    define WITH_pad_brsa
#  endif
#  ifndef WITH_prng_bbs 
#    define WITH_prng_bbs 
#  endif
#  ifndef WITH_prng_hshs
#    define WITH_prng_hshs
#  endif
#endif

#ifdef WITH_pbe_pbe
#  ifndef WITH_hash_sha
#    define WITH_hash_sha
#  endif
#endif

#ifdef WITH_hash_mdc2
#  ifndef WITH_bsapi_des
#    define WITH_bsapi_des
#  endif
#endif

#ifdef WITH_pad_autod1
#  ifndef WITH_pad_pkcs1 
#    define WITH_pad_pkcs1 
#  endif
#  ifndef WITH_pad_brsa
#    define WITH_pad_brsa
#  endif
#endif

#ifdef WITH_bsapi_dsa
#  ifndef WITH_hash_sha
#    define WITH_hash_sha
#  endif
#endif

#if (defined WITH_hash_hmacmd2 || defined WITH_hash_hmacmd5 \
    || defined WITH_hash_hmacsha || defined WITH_hash_hmacrmd \
    || defined WITH_hash_hmacr160)
#  ifndef WITH_hash_hmac
#    define WITH_hash_hmac
#  endif
#endif


#if (defined WITH_hash_mdc2 || defined WITH_hash_ripemd \
    || defined WITH_hash_sqmod || defined WITH_hash_bhf \
    || defined WITH_hash_bsah || defined WITH_hash_md5 \
    || defined WITH_hash_md2 || defined WITH_hash_sha \
    || defined WITH_hash_rmd160 || defined WITH_hash_hmac)
#  ifndef WITH_hash
#    define WITH_hash
#  endif
#endif

#ifdef WITH_secshare_shamir
#  ifndef WITH_secshare
#    define WITH_secshare
#  endif
#endif

#ifdef WITH_prng_entpoll
#  ifndef WITH_hash_nullhash
#    define WITH_hash_nullhash
#  endif
#endif

#ifdef WITH_pad_autod1
#define WITH_pad_pkcs1
#define WITH_pad_brsa
#endif /* WITH_pad_autod1 */

#endif /* WITH_options */

#ifdef CST_USE_ONLY_BSAFE
#ifndef CST_WITH_BSAFE_RSA
#define CST_WITH_BSAFE_RSA
#endif /* ndef CST_WITH_BSAFE_RSA */
#ifndef CST_WITH_BSAFE_RC5
#define CST_WITH_BSAFE_RC5
#endif /* ndef CST_WITH_BSAFE_RC5 */
#endif /* def CST_USE_ONLY_BSAFE */

#ifdef CST_WITH_BSAFE_RC5
#ifndef CST_WITH_BSAFE_BLOCK_CIPHER
#define CST_WITH_BSAFE_BLOCK_CIPHER
#endif /* ndef CST_WITH_BSAFE_BLOCK_CIPHER */
#endif /* ndef CST_WITH_BSAFE_RC5 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _CSTOPT_H */

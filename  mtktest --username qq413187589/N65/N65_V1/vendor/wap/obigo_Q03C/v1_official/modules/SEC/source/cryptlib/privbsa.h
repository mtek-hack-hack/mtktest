/* privbsa.h -- functions used internally by bsapi routines 
 *
 * created: WW, 27/3/98 
 */

#ifndef _PRIVBSA_H
#define _PRIVBSA_H

#include "cstopt.h"   /* For #define WITH_xxx */
#include "ut.h"
#include "mpm.h"      /* for mpm_arc */
#include "bsapi.h"    /* for bsapi_id */
#include "prng.h"     /* for prng_inst */
#ifdef CST_TIMEBOMBED
/*Removed by ANAO 29/3-2001 #include "time.h"*/
#endif /* def CST_TIMEBOMBED */

#ifdef WITH_bsapi_rsa

/* RSA functions */
 
/* 
 * An RSA signature is supposed to be a raw data stream consisting of an
 * integer number of bytes. Old-style CST signatures (up to release 6.2) 
 * consist of this data with an ASN.1 BIT STRING header in front. The 
 * following function strips the header off the signature.
 */

/* cstsig2sig: converts an old-style sig to a new-style (standards-compliant)
 * sig. Returns 0 on failure, 1 on success */

int
cstsig2sig (ut_mblk *sig_in, ut_mblk *sig_out);

/* pkcs1keyModLen: returns the modulus length in bits of a PKCS#1-encoded 
 * RSA private key.
 */

size_t
pkcs1keyModLen(ut_mblk *key);

/* pkcs1KeyModAsArc */
mpm_arc
pkcs1keyModAsArc(ut_mblk *key);

#endif  /* def WITH_bsapi_rsa */

#ifdef WITH_bsapi_des

u32
bsapi_des_f(u32 k, u8 *subkey);

void
bsapi_des_iperm(u32 *data);

void
bsapi_des_fperm(u32 *data);

u8 *
bsapi_des_schedule(u8 *key, bsapi_mode_op op, bsapi_mode_key_type key_type, 
                   u8 *sched);

void
bsapi_des_des1(u32 *data, void *ks[]);

void
bsapi_des_des1p(u32 *data, void *ks[]);

void
bsapi_des_des3(u32 *data, void *ks[]);

void
bsapi_des_des3p(u32 *data, void *ks[]);

bsapi_id
bsapi_start_des_core(bsapi_mode *mode, prng_inst *prng, bsapi_kset *keys, 
                     int vb60des);

/* used so we can do tripledes with both fixed & broken versions */
bsapi_id
bsapi_start_triple_des_core(bsapi_mode *mode, prng_inst *prng, bsapi_kset *keys,
  bsapi_id (*startfunc)(bsapi_mode *, prng_inst *, bsapi_kset *));

#endif  /* def WITH_bsapi_des */

#ifdef CST_TIMEBOMBED
#define CHECK_FOR_TIMEBOMBING(errorcode) \
  { \
    char tmbmb_msg[1024] = "+h3 @c3 0f sp@d3s!"; \
    time_t exp; \
    time_t sec; \
    exp = atol (tmbmb_msg); \
    sec = time (NULL); \
    if (sec > exp) { \
      sprintf (tmbmb_msg,\
	  "\nYou are using a timebombed evaluation copy of " \
	  CST_TIMEBOMB_PRODUCT \
	  " which expired on:\n" \
	  "  1m s0 8@d 8@8y 1 d0n+ c@r3!\n" \
	  "Contact info@baltimore.com for information on purchasing the full,\n" \
	  "non-timebombed version.\n"); \
      if (ut_log_will_print()) \
        ut_log0 (0UL, UT_AXFAIL, tmbmb_msg); \
      if (CSTFLAGS_GET_USESTDERR (ut_getflags ())) \
        fprintf (stderr, tmbmb_msg); \
      exit (1); \
    } \
  }
#else   /* def/ndef CST_TIMEBOMBED */
#define  CHECK_FOR_TIMEBOMBING(errorcode)
#endif  /* def CST_TIMEBOMBED */

#endif /* ndef _PRIVBSA_H */

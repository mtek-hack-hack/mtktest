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

#ifndef _SET_H
#define _SET_H

#include "ut.h"    /* for ut_mblk */
#include "hash.h"  /* for hash_digest */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Definitions
 */

/* Upper bounds on SET string types */

#define SET_UB_ACCTID      (74)

/* type of data contained in a set_contentData structure */

typedef enum {
  SET_EXTRADATA_NONE = 0,
  SET_EXTRADATA_PANDATA,
  SET_EXTRADATA_PANDATA0,
  SET_EXTRADATA_PANTOKEN,
  SET_EXTRADATA_PANONLY,
  SET_EXTRADATA_ACCTDATA,
  SET_EXTRADATA_MAX
} set_extradatatype;

/* the lengths of those types */
extern const size_t set_extradataype_len[];


/*
 * Types
 */

typedef struct set_pandata_s {
  char     *pan;    /* PAN -- null-terminated ASCII numerals, up to 19 digits */
  char     *cExp;   /* Card Expiry -- null-terminated ASCII numerals */
  ut_mblk  *pSec;   /* PAN Secret -- 20-byte octet string */
  ut_mblk  *exn;    /* EXNonce  -- 20-byte octet string */
} set_pandata;

typedef struct set_pandata0_s {
  char     *pan;    /* PAN -- null-terminated ASCII numerals, up to 19 digits */
  char     *cExp;   /* Card Expiry -- null-terminated ASCII numerals */
  ut_mblk  *cSec;   /* Card Secret -- 20-byte octet string */
  ut_mblk  *exn;    /* EXNonce  -- 20-byte octet string */
} set_pandata0;

typedef struct set_pantoken_s {
  char     *pan;    /* PAN -- null-terminated ASCII numerals, up to 19 digits */
  char     *cExp;   /* Card Expiry -- null-terminated ASCII numerals */
  ut_mblk  *exn;    /* EXNonce  -- 20-byte octet string */
} set_pantoken;

typedef struct set_pandonly_s {
  char     *pan;    /* PAN -- null-terminated ASCII numerals, up to 19 digits */
  ut_mblk  *exn;    /* EXNonce  -- 20-byte octet string */
} set_panonly;

typedef struct set_acctdata_s {
  char     *aId;    /* Account Identification -- ASCII string, up to 74 chars */
  ut_mblk  *exn;    /* EXNonce -- 20-byte octet string */
} set_acctdata;


/* gather them all together... */

typedef union {
  set_pandata    data;
  set_pandata0   data0;
  set_pantoken   token;
  set_panonly    only;
  set_acctdata   acct;
} set_extradata;

typedef struct set_contentData_s {
  ut_mblk             *dek;
  set_extradatatype    type;
  set_extradata        extra;
  hash_digest         *hdig;    /* set to 0 if not used */
} set_contentData;



/* This takes a block of data and converts it into the form expected by
 * bsapi_append_rsa with oaep_set padding. The data block produced, in
 * the syntax of the SET document of May 31, 1997, is:
 *   BT | BC | V | DEK | (HD) | (X)
 * ... where the two last fields, the hash data and the extra
 * information, may or may not be present.
 * 
 * oaep_set padding pads this data on the right to bring it up to the
 * keylength - 17 bytes before performing the OAEP mask-generation
 * routines.
 */

/* set_contentData_2encryptionBlock -- take data for SET transaction as
 * a series of ut_mblks and output the appropriate data block for
 * inputting into bsapi_append_rsa.
 *
 * Returns 0 on success, -1 on failure.
 *
 * DOESN'T check that the fields are the length designated by SET. This
 * must be done by the developer.
 *
 * In debug mode, checks that in and out are nonzero and that
 * in->dek->data exists and returns -2 if they don't.
 *
 * There must be no memory allocated at out prior to calling this
 * function. The function allocates memory at out.data which must be
 * disposed of.
 */



extern
int
set_contentData_2encryptionBlock (
  set_contentData *in,
  ut_mblk         *out);

/*
 *
 * Each field created in the output must be disposed of. Note that this
 * includes hdig.bits.data in the hash_digest, if it exists
 */


extern
int
set_contentData_fromEncryptionBlock (
  ut_mblk         *in,
  set_contentData *out);


/* unlike most destroy functions, doesn't deallocate memory at in; just
 * deallocates all the fields within in. Use with care!
 */

extern
void
set_contentData_destroy(set_contentData *in);

#ifdef __cplusplus
}
#endif

#endif /* _SET_H */

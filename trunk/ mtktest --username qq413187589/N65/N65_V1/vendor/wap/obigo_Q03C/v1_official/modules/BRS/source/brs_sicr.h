/*
 * Copyright (C) Obigo AB, 2002-2007.
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









#ifndef _brs_sicr_h
#define _brs_sicr_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS_CRYPTO


#define BRS_WMLS_SIGALG_NULL                      0
#define BRS_WMLS_SIGALG_RSA_SHA_PCKS1             1
#define BRS_WMLS_SIGALG_ECDSA_SHA_P1363           2

typedef struct {
  MSF_UINT8      algorithm;
  MSF_UINT16     siglen;
  unsigned char *sig;
} brs_wmls_signature_t;


#define BRS_WMLS_SIGNERINFO_IMPLICIT              0
#define BRS_WMLS_SIGNERINFO_SHA_KEY_HASH          1
#define BRS_WMLS_SIGNERINFO_WTLS_CERTIFICATE      2
#define BRS_WMLS_SIGNERINFO_X509_CERTIFICATE      3
#define BRS_WMLS_SIGNERINFO_X968_CERTIFICATE      4
#define BRS_WMLS_SIGNERINFO_CERTIFICATE_URL       5

typedef struct {
  MSF_UINT8      signer_info_type;
  MSF_UINT16     info_len;
  unsigned char *info;
} brs_wmls_signer_info_t;


#define BRS_WMLS_CONTENTTYPE_TEXT                 1
#define BRS_WMLS_CONTENTTYPE_DATA                 2

typedef struct {
  MSF_UINT8      content_type;
  MSF_UINT16     content_encoding;
  MSF_UINT8      content_present;
  MSF_UINT16     content_len;
  unsigned char *content;
} brs_wmls_content_info_t;


#define BRS_WMLS_ATTRIBUTETYPE_GMT_UTC_TIME       1
#define BRS_WMLS_ATTRIBUTETYPE_SIGNER_NONCE       2

typedef struct {
  MSF_UINT8 attribute_type;
  union {
    MSF_UINT8 gmt_utc_time[12];
    MSF_UINT8 signer_nonce[8];
  } _u;
} brs_wmls_authenticated_attribute_t;


typedef struct {
  MSF_UINT8                          version;
  brs_wmls_signature_t               signature;
  brs_wmls_signer_info_t             signer_info[2];
  brs_wmls_content_info_t            content_info;
  brs_wmls_authenticated_attribute_t authenticated_attribute;
} brs_wmls_signed_content_t;
























int
brs_wmls_create_digest_info (unsigned char *buf, int buflen,
                             unsigned char *digest_info, MSF_UINT16 *diglen,
                             MSF_UINT8 options,
                             brs_wmls_signed_content_t *sc);















int
brs_wmls_encode_signed_content (brs_wmls_signed_content_t *sc,
                                char **result, MSF_UINT16 *reslen);





brs_wmls_signed_content_t *
brs_wmls_new_signed_content (void);





void
brs_wmls_free_signed_content (brs_wmls_signed_content_t *sc);

#endif
#endif

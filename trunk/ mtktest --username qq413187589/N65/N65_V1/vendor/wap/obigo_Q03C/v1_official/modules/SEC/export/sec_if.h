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
/*
 * sec_if.h
 *
 * Created by Lone Koch
 *
 * Revision  history:
 * 
 *
 */

#ifndef _sec_if_h
#define _sec_if_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif
 
#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"    /* for msf_dcvt_t */
#endif

/**************************************************
 *
 * Global SEC Signals in Mobile Suite
 *
 **************************************************/

/**************************************************
 * WTLS
 **************************************************/

#define SEC_SIG_GET_METHODS                     ((MSF_MODID_SEC << 8) + 0x01)
#define SEC_SIG_WTLS_GET_METHODS_RESPONSE       ((MSF_MODID_SEC << 8) + 0x02)
#define SEC_SIG_WTLS_KEY_EXCHANGE               ((MSF_MODID_SEC << 8) + 0x03)
#define SEC_SIG_WTLS_KEY_EXCHANGE_RESPONSE      ((MSF_MODID_SEC << 8) + 0x04)
#define SEC_SIG_WTLS_PRF                        ((MSF_MODID_SEC << 8) + 0x05)
#define SEC_SIG_WTLS_PRF_RESPONSE               ((MSF_MODID_SEC << 8) + 0x06)
#define SEC_SIG_WTLS_VERIFY_CERT_CHAIN          ((MSF_MODID_SEC << 8) + 0x07)
#define SEC_SIG_WTLS_VERIFY_CERT_CHAIN_RESPONSE ((MSF_MODID_SEC << 8) + 0x08)
#define SEC_SIG_WTLS_GET_CLIENT_CERT            ((MSF_MODID_SEC << 8) + 0x09)
#define SEC_SIG_WTLS_GET_CLIENT_CERT_RESPONSE   ((MSF_MODID_SEC << 8) + 0x0a)
#define SEC_SIG_WTLS_COMPUTE_SIGNATURE          ((MSF_MODID_SEC << 8) + 0x0b)
#define SEC_SIG_WTLS_COMPUTE_SIGNATURE_RESPONSE ((MSF_MODID_SEC << 8) + 0x0c)

/**************************************************
 * TLS/SSL
 **************************************************/

#define SEC_SIG_GET_CIPHER_SUITES               ((MSF_MODID_SEC << 8) + 0x0d)
#define SEC_SIG_TLS_GET_CIPHER_SUITES_RESPONSE  ((MSF_MODID_SEC << 8) + 0x0e)
#define SEC_SIG_TLS_KEY_EXCHANGE                ((MSF_MODID_SEC << 8) + 0x0f)
#define SEC_SIG_TLS_KEY_EXCHANGE_RESPONSE       ((MSF_MODID_SEC << 8) + 0x10)
#define SEC_SIG_TLS_PRF                         ((MSF_MODID_SEC << 8) + 0x11)
#define SEC_SIG_TLS_PRF_RESPONSE                ((MSF_MODID_SEC << 8) + 0x12)
#define SEC_SIG_TLS_VERIFY_CERT_CHAIN           ((MSF_MODID_SEC << 8) + 0x13)
#define SEC_SIG_TLS_VERIFY_CERT_CHAIN_RESPONSE  ((MSF_MODID_SEC << 8) + 0x14)
#define SEC_SIG_TLS_GET_CLIENT_CERT             ((MSF_MODID_SEC << 8) + 0x15)
#define SEC_SIG_TLS_GET_CLIENT_CERT_RESPONSE    ((MSF_MODID_SEC << 8) + 0x16)
#define SEC_SIG_TLS_COMPUTE_SIGNATURE           ((MSF_MODID_SEC << 8) + 0x17)
#define SEC_SIG_TLS_COMPUTE_SIGNATURE_RESPONSE  ((MSF_MODID_SEC << 8) + 0x18)

/**************************************************
 * signText
 **************************************************/

#define SEC_SIG_SIGN_TEXT                       ((MSF_MODID_SEC << 8) + 0x1b)
#define SEC_SIG_SIGN_TEXT_RESPONSE              ((MSF_MODID_SEC << 8) + 0x1c)

/**************************************************
 * CRYPT
 **************************************************/

#define SEC_SIG_CONNECTION_ESTABLISHED          ((MSF_MODID_SEC << 8) + 0x1d)
#define SEC_SIG_CONNECTION_TERMINATED           ((MSF_MODID_SEC << 8) + 0x1e)
#define SEC_SIG_PEER_DELETE_LINKS               ((MSF_MODID_SEC << 8) + 0x1f)
#define SEC_SIG_PEER_LINK_TO_SESSION            ((MSF_MODID_SEC << 8) + 0x20)
#define SEC_SIG_PEER_LOOKUP                     ((MSF_MODID_SEC << 8) + 0x21)
#define SEC_SIG_PEER_LOOKUP_RESPONSE            ((MSF_MODID_SEC << 8) + 0x22)
#define SEC_SIG_SESSION_ACTIVE                  ((MSF_MODID_SEC << 8) + 0x23)
#define SEC_SIG_SESSION_INVALIDATE              ((MSF_MODID_SEC << 8) + 0x24)
#define SEC_SIG_SESSION_FETCH                   ((MSF_MODID_SEC << 8) + 0x25)
#define SEC_SIG_SESSION_FETCH_RESPONSE          ((MSF_MODID_SEC << 8) + 0x26)
#define SEC_SIG_SESSION_UPDATE                  ((MSF_MODID_SEC << 8) + 0x27)

/**************************************************
 * CERT
 **************************************************/

#define SEC_SIG_STORE_CERT                      ((MSF_MODID_SEC << 8) + 0x28)
#define SEC_SIG_STORE_CERT_RESPONSE             ((MSF_MODID_SEC << 8) + 0x29)
#define SEC_SIG_TRUSTED_CA_INFO                 ((MSF_MODID_SEC << 8) + 0x2a)
#define SEC_SIG_TRUSTED_CA_INFO_RESPONSE        ((MSF_MODID_SEC << 8) + 0x2b)
#define SEC_SIG_CERT_DELIVERY                   ((MSF_MODID_SEC << 8) + 0x2c)
#define SEC_SIG_CERT_DELIVERY_RESPONSE          ((MSF_MODID_SEC << 8) + 0x2d)
#define SEC_SIG_VIEW_CERT_NAMES                 ((MSF_MODID_SEC << 8) + 0x2e)
#define SEC_SIG_VIEW_CERT_NAMES_RESPONSE        ((MSF_MODID_SEC << 8) + 0x2f)
#define SEC_SIG_GET_CERT_IDS                    ((MSF_MODID_SEC << 8) + 0x30)
#define SEC_SIG_GET_CERT_IDS_RESPONSE           ((MSF_MODID_SEC << 8) + 0x31) 
#define SEC_SIG_GET_NBR_CERTS                   ((MSF_MODID_SEC << 8) + 0x32)
#define SEC_SIG_GET_NBR_CERTS_RESPONSE          ((MSF_MODID_SEC << 8) + 0x33)
#define SEC_SIG_VERIFY_CERT_CHAIN               ((MSF_MODID_SEC << 8) + 0x34)
#define SEC_SIG_VERIFY_CERT_CHAIN_RESPONSE      ((MSF_MODID_SEC << 8) + 0x35)

#define SEC_SIG_GENERATE_KEY_PAIR               ((MSF_MODID_SEC << 8) + 0x36)
#define SEC_SIG_GENERATE_KEY_PAIR_RESPONSE      ((MSF_MODID_SEC << 8) + 0x37)
#define SEC_SIG_DEL_KEYS_USER_CERTS             ((MSF_MODID_SEC << 8) + 0x38)
#define SEC_SIG_DEL_KEYS_USER_CERTS_RESPONSE    ((MSF_MODID_SEC << 8) + 0x39)
#define SEC_SIG_GET_USER_PUB_KEY                ((MSF_MODID_SEC << 8) + 0x3a)
#define SEC_SIG_GET_USER_PUB_KEY_RESPONSE       ((MSF_MODID_SEC << 8) + 0x3b)
#define SEC_SIG_CHANGE_PIN                      ((MSF_MODID_SEC << 8) + 0x3c)
#define SEC_SIG_CHANGE_PIN_RESPONSE             ((MSF_MODID_SEC << 8) + 0x3d)
#define SEC_SIG_VERIFY_PUK                      ((MSF_MODID_SEC << 8) + 0x3e)
#define SEC_SIG_VERIFY_PUK_RESPONSE             ((MSF_MODID_SEC << 8) + 0x3f)

#define SEC_SIG_VIEW_CURRENT_CERT               ((MSF_MODID_SEC << 8) + 0x40)
#define SEC_SIG_VIEW_CURRENT_CERT_RESPONSE      ((MSF_MODID_SEC << 8) + 0x41)
#define SEC_SIG_VIEW_SESSION_INFO               ((MSF_MODID_SEC << 8) + 0x42)
#define SEC_SIG_VIEW_SESSION_INFO_RESPONSE      ((MSF_MODID_SEC << 8) + 0x43)
#define SEC_SIG_GET_CURRENT_CERT                ((MSF_MODID_SEC << 8) + 0x44)
#define SEC_SIG_GET_CURRENT_CERT_RESPONSE       ((MSF_MODID_SEC << 8) + 0x45)
#define SEC_SIG_GET_SESSION_INFO                ((MSF_MODID_SEC << 8) + 0x46)
#define SEC_SIG_GET_SESSION_INFO_RESPONSE       ((MSF_MODID_SEC << 8) + 0x47)
#define SEC_SIG_GET_CURRENT_SEC_CLASS           ((MSF_MODID_SEC << 8) + 0x48)
#define SEC_SIG_GET_CURRENT_SEC_CLASS_RESPONSE  ((MSF_MODID_SEC << 8) + 0x49)
#define SEC_SIG_SESSION_CLEAR                   ((MSF_MODID_SEC << 8) + 0x4a)
#define SEC_SIG_SESSION_CLEAR_RESPONSE          ((MSF_MODID_SEC << 8) + 0x4b)


/**************************************************
 * Contracts
 **************************************************/

#define SEC_SIG_VIEW_CONTRACTS                  ((MSF_MODID_SEC << 8) + 0x4c)
#define SEC_SIG_VIEW_CONTRACTS_RESPONSE         ((MSF_MODID_SEC << 8) + 0x4d)
#define SEC_SIG_GET_CONTRACTS                   ((MSF_MODID_SEC << 8) + 0x4e)
#define SEC_SIG_GET_CONTRACTS_RESPONSE          ((MSF_MODID_SEC << 8) + 0x4f)
#define SEC_SIG_DELETE_CONTRACT                 ((MSF_MODID_SEC << 8) + 0x50)
#define SEC_SIG_DELETE_CONTRACT_RESPONSE        ((MSF_MODID_SEC << 8) + 0x51)

 /**************************************************
 * TI
 **************************************************/

#define SEC_SIG_VIEW_AND_GET_CERT               ((MSF_MODID_SEC << 8) + 0x52)
#define SEC_SIG_VIEW_AND_GET_CERT_RESPONSE      ((MSF_MODID_SEC << 8) + 0x53)
#define SEC_SIG_DELETE_CERT                     ((MSF_MODID_SEC << 8) + 0x54)
#define SEC_SIG_DELETE_CERT_RESPONSE            ((MSF_MODID_SEC << 8) + 0x55)
#define SEC_SIG_GET_CERT                        ((MSF_MODID_SEC << 8) + 0x56)
#define SEC_SIG_GET_CERT_RESPONSE               ((MSF_MODID_SEC << 8) + 0x57)
#define SEC_SIG_CANCEL                          ((MSF_MODID_SEC << 8) + 0x58)

/***********************************************************************
 *
 * Type and constant definitions
 *
 ***********************************************************************/

/* Secure connection protocols */
#define SEC_CONNECTION_TYPE_TLS         1
#define SEC_CONNECTION_TYPE_WTLS        2
#define SEC_CONNECTION_TYPE_SSL         3

/* Key types */
#define SEC_NON_REPUDIATION_KEY   1
#define SEC_AUTHENTICATION_KEY    2


/* Certificate options: user, root/ca or both (bitwise ORed)     */
#define SEC_GET_USER_CERT		0x01
#define SEC_GET_ROOT_CERT		0x02

/**************************************************
 * WTLS
 **************************************************/

/*---------------------------------------------
 * Key exchange
 *---------------------------------------------*/

/* The key exchange algorithms defined by WTLS. */
#define SEC_WTLS_KEY_EXCH_NULL              0
#define SEC_WTLS_KEY_EXCH_SHARED_SECRET     1
#define SEC_WTLS_KEY_EXCH_DH_ANON           2
#define SEC_WTLS_KEY_EXCH_DH_ANON_512       3
#define SEC_WTLS_KEY_EXCH_DH_ANON_768       4
#define SEC_WTLS_KEY_EXCH_RSA_ANON          5
#define SEC_WTLS_KEY_EXCH_RSA_ANON_512      6
#define SEC_WTLS_KEY_EXCH_RSA_ANON_768      7
#define SEC_WTLS_KEY_EXCH_RSA               8
#define SEC_WTLS_KEY_EXCH_RSA_512           9
#define SEC_WTLS_KEY_EXCH_RSA_768           10
#define SEC_WTLS_KEY_EXCH_ECDH_ANON         11
#define SEC_WTLS_KEY_EXCH_ECDH_ANON_113     12
#define SEC_WTLS_KEY_EXCH_ECDH_ANON_131     13
#define SEC_WTLS_KEY_EXCH_ECDH_ECDSA        14

/*---------------------------------------------
 * Parameter to key agreement routines
 *---------------------------------------------*/

typedef struct {
  MSF_UINT16     expLen;
  unsigned char *exponent;
  MSF_UINT16     modLen;
  unsigned char *modulus;
} sec_pub_key_rsa;

typedef struct {
  MSF_UINT16     len;
  unsigned char *y;
} sec_wtls_pub_key_dh;

typedef struct {
  MSF_UINT16      len;
  unsigned char *point;
} sec_wtls_pub_key_ec;

typedef struct {
  union {
    sec_pub_key_rsa rsa_key;
    sec_wtls_pub_key_dh  dh_key;
    sec_wtls_pub_key_ec  ec_key;
  } _u;
} sec_wtls_public_key;

typedef struct {
  MSF_UINT8      parameterIndex;
  MSF_UINT16     paramLen;
  unsigned char *params;
} sec_wtls_param_specifier;

typedef struct {
  MSF_UINT8          keyExchangeSuite;
  union {
    struct {
      unsigned char *identifier;
      MSF_UINT16     idLen;
    } secretKey;
    struct {
      sec_wtls_public_key      pubKey;
      sec_wtls_param_specifier paramSpecifier;
    } keyParam;
    struct {
      MSF_UINT16     bufLen;
      unsigned char *buf;
    } certificates;
  } _u;
} sec_wtls_key_exch_params;


/**************************************************
 * TLS/SSL
 **************************************************/

/*---------------------------------------------------
 * All the cipher suites, as defined in Appendix A.5
 * of the TLS specification.
 *---------------------------------------------------*/
#define SEC_TLS_NULL_WITH_NULL_NULL                   0x0000
#define SEC_TLS_RSA_WITH_NULL_MD5                     0x0001
#define SEC_TLS_RSA_WITH_NULL_SHA                     0x0002
#define SEC_TLS_RSA_EXPORT_WITH_RC4_40_MD5            0x0003
#define SEC_TLS_RSA_WITH_RC4_128_MD5                  0x0004
#define SEC_TLS_RSA_WITH_RC4_128_SHA                  0x0005
#define SEC_TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5        0x0006
#define SEC_TLS_RSA_WITH_IDEA_CBC_SHA                 0x0007
#define SEC_TLS_RSA_EXPORT_WITH_DES40_CBC_SHA         0x0008
#define SEC_TLS_RSA_WITH_DES_CBC_SHA                  0x0009
#define SEC_TLS_RSA_WITH_3DES_EDE_CBC_SHA             0x000A
#define SEC_TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA      0x000B
#define SEC_TLS_DH_DSS_WITH_DES_CBC_SHA               0x000C
#define SEC_TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA          0x000D
#define SEC_TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA      0x000E
#define SEC_TLS_DH_RSA_WITH_DES_CBC_SHA               0x000F
#define SEC_TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA          0x0010
#define SEC_TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA     0x0011
#define SEC_TLS_DHE_DSS_WITH_DES_CBC_SHA              0x0012
#define SEC_TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA         0x0013
#define SEC_TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA     0x0014
#define SEC_TLS_DHE_RSA_WITH_DES_CBC_SHA              0x0015
#define SEC_TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA         0x0016
#define SEC_TLS_DH_ANON_EXPORT_WITH_RC4_40_MD5        0x0017
#define SEC_TLS_DH_ANON_WITH_RC4_128_MD5              0x0018
#define SEC_TLS_DH_ANON_EXPORT_WITH_DES40_CBC_SHA     0x0019
#define SEC_TLS_DH_ANON_WITH_DES_CBC_SHA              0x001A
#define SEC_TLS_DH_ANON_WITH_3DES_EDE_CBC_SHA         0x001B

/* Key exchange algorithms defined by TLS.*/
#define SEC_TLS_KEYEXCH_NULL                          0
#define SEC_TLS_KEYEXCH_RSA                           1
#define SEC_TLS_KEYEXCH_RSA_EXPORT                    2
#define SEC_TLS_KEYEXCH_DH_DSS_EXPORT                 3
#define SEC_TLS_KEYEXCH_DH_DSS                        4
#define SEC_TLS_KEYEXCH_DH_RSA_EXPORT                 5
#define SEC_TLS_KEYEXCH_DH_RSA                        6
#define SEC_TLS_KEYEXCH_DHE_DSS_EXPORT                7
#define SEC_TLS_KEYEXCH_DHE_DSS                       8
#define SEC_TLS_KEYEXCH_DHE_RSA_EXPORT                9
#define SEC_TLS_KEYEXCH_DHE_RSA                       10
#define SEC_TLS_KEYEXCH_DH_ANON_EXPORT                11
#define SEC_TLS_KEYEXCH_DH_ANON                       12

/* Client certificate types, used in TLSa_getClientCertificate. */
#define SEC_TLS_CERT_RSA_SIGN                         1
#define SEC_TLS_CERT_DSS_SIGN                         2
#define SEC_TLS_CERT_RSA_FIXED_DH                     3
#define SEC_TLS_CERT_DSS_FIXED_DH                     4


/* Options for key exchange */
#define SEC_TLS_OPTION_IS_SSL                         1
#define SEC_TLS_OPTION_SSL_CLIENT_HELLO               2

/*-----------------------------------------------
 * Parameter to key agreement routines
 *-----------------------------------------------*/

typedef struct {
  unsigned char *dhP;
  MSF_UINT16     dhPLen;
  unsigned char *dhG;
  MSF_UINT16     dhGLen;
  unsigned char *dhYs;
  MSF_UINT16     dhYsLen;
} sec_tls_server_dh_params;

typedef struct {
  unsigned char *rsaModulus;
  MSF_UINT16     rsaModulusLen;
  unsigned char *rsaExponent;
  MSF_UINT16     rsaExponentLen;
} sec_tls_server_rsa_params;

typedef struct {
  unsigned char *signature;
  MSF_UINT16     signatureLen;
} sec_tls_signature;

typedef struct {
  union {
    struct {
      sec_tls_server_dh_params params;
      sec_tls_signature        signedParams;
    } dh;
    struct {
      sec_tls_server_rsa_params params;
      sec_tls_signature         signedParams;
    } rsa;
  } _u;
} sec_tls_key_exch_params;

typedef struct {
  MSF_UINT8      format;
  MSF_UINT32     certLen;
  unsigned char *cert;
} sec_tls_asn1_certificate;

typedef struct {
  MSF_UINT16     nameLen;
  unsigned char *name;
} sec_tls_distinguished_name;

typedef struct {
  MSF_UINT8      connection_type;
  MSF_UINT8      security_class;
  MSF_UINT8      key_exchange_alg;
  MSF_UINT16     key_exchange_key_len;
  MSF_UINT8      hmac_alg;
  MSF_UINT16     hmac_len;
  MSF_UINT8      encryption_alg;
  MSF_UINT16     encryption_key_len;
  MSF_UINT8      num_certs;
  sec_tls_asn1_certificate *certs;
} sec_session_info_t;


/**************************************************
 * signText
 **************************************************/

/* Values for keyIdType parameter in SECif_signText: */
#define SEC_SIGN_NO_KEY                 0
#define SEC_SIGN_SHA_KEY                1
#define SEC_SIGN_SHA_CA_KEY             2

/* Values for options parameter in SECif_signText: */
#define SEC_SIGN_RETURN_HASHED_KEY      0x2
#define SEC_SIGN_RETURN_CERTIFICATE     0x4

/* Values for algorithm parameter in SECif_signText: */
#define SEC_SIGN_ALG_RSA                1
#define SEC_SIGN_ALG_ECDSA              2

/* Values for certificateType parameter in SECif_signText: */
#define SEC_SIGN_WTLS_CERTIFICATE       2
#define SEC_SIGN_X509_CERTIFICATE       3
#define SEC_SIGN_X968_CERTIFICATE       4
#define SEC_SIGN_URL_CERTIFICATE        5

/* Values for err parameter in SECif_signText: */
#define SEC_SIGN_NO_ERROR               0
#define SEC_SIGN_MISSING_CERTIFICATE    1
#define SEC_SIGN_USER_CANCELED          2
#define SEC_SIGN_OTHER_ERROR            3

/* Contract structure */
typedef struct {
  char *contract;
  char *signature;
  MSF_UINT16 signatureLen;
  MSF_UINT32 time;
  MSF_UINT16 contractId;
} sec_contract_info_t;

/**************************************************
 * CRYPT
 **************************************************/

/*---------------------------------------------
 * Bulk encryption
 *---------------------------------------------*/

typedef MSF_UINT8 sec_cipher_alg;

/* The cipher algorithms */
#define SEC_CIPHER_NULL             0
#define SEC_CIPHER_RC5_CBC_40       1
#define SEC_CIPHER_RC5_CBC_56       2
#define SEC_CIPHER_RC5_CBC          3
#define SEC_CIPHER_DES_CBC_40       4
#define SEC_CIPHER_DES_CBC          5
#define SEC_CIPHER_3DES_CBC_EDE     6
#define SEC_CIPHER_IDEA_CBC_40      7
#define SEC_CIPHER_IDEA_CBC_56      8
#define SEC_CIPHER_IDEA_CBC         9
#define SEC_CIPHER_RC5_CBC_64      10
#define SEC_CIPHER_IDEA_CBC_64     11
#define SEC_CIPHER_RC2_CBC_40      20
#define SEC_CIPHER_RC4_40          21
#define SEC_CIPHER_RC4_128         22
#define SEC_CIPHER_AES_CBC_128     30


/* Key parameter object for bulk encryption routines. */
typedef struct {
  unsigned char *key;
  MSF_UINT16     keyLen;
  unsigned char *iv;
  MSF_UINT16     ivLen;
} sec_key_object;

/*---------------------------------------------
 * Secure hash algorithms
 *---------------------------------------------*/

typedef MSF_UINT8 sec_hash_alg;

/* Secure hash algorithms. */
#define SEC_HASH_NULL                  0
#define SEC_HASH_MD5                   1
#define SEC_HASH_SHA                   2
#define SEC_HASH_MD2                   3

typedef void *sec_hash_handle;
typedef void *sec_hmac_handle;
typedef void *sec_cipher_handle;

/*---------------------------------------------
 * Session options
 *---------------------------------------------*/

#define SEC_SESSION_OPTIONS_RESUMABLE       0x80
#define SEC_SESSION_OPTIONS_SERVER_AUTH     0x20
#define SEC_SESSION_OPTIONS_CLIENT_AUTH     0x10

/**************************************************
 * CERT
 **************************************************/

/*The certificate formats*/
#define SEC_CERT_FORMAT_WTLS              1
#define SEC_CERT_FORMAT_X509              2



/************************************************************
 *
 * Signal structures that is connected to the signals above.
 *
 ************************************************************/

/**************************************************
 * WTLS
 **************************************************/

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
} sec_wtls_get_methods_t;

typedef struct {
  MSF_INT32 objectId;
  MSF_UINT16 result;
  unsigned char *cipherMethods;
  MSF_UINT16 cipherMethodsLen;
  unsigned char *keyExchangeIds;
  MSF_UINT16 keyExchangeIdsLen;
  unsigned char *trustedKeyIds;
  MSF_UINT16 trustedKeyIdsLen;
} sec_wtls_get_methods_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  sec_wtls_key_exch_params param;
  MSF_UINT8 hashAlg;
  unsigned char *randval;
} sec_wtls_key_exchange_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  MSF_UINT8 masterSecretId;
  unsigned char *publicValue;
  MSF_UINT16 publicValueLen;
} sec_wtls_key_exchange_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_UINT8 alg;
  MSF_UINT8 masterSecretId;
  unsigned char *secret;
  MSF_UINT16 secretLen;
  char *label;
  unsigned char *seed;
  MSF_UINT16 seedLen;
  MSF_UINT16 outputLen;
} sec_wtls_prf_t;

typedef struct {
  MSF_INT32 objectId;
  MSF_UINT16 result;
  unsigned char *buf;
  MSF_UINT16 bufLen;
} sec_wtls_prf_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  unsigned char *buf;
  MSF_UINT16 bufLen;
  unsigned char *addr;
  MSF_UINT16 addrLen;
  unsigned char *domain;
  MSF_UINT16 domainLen;
} sec_wtls_verify_cert_chain_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
} sec_wtls_verify_cert_chain_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  unsigned char *buf;
  MSF_UINT16 bufLen;
} sec_wtls_get_client_cert_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  unsigned char *keyId;
  MSF_UINT16 keyIdLen;
  unsigned char *cert;
  MSF_UINT16 certLen;
} sec_wtls_get_client_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  unsigned char *keyId;
  MSF_UINT16 keyIdLen;
  unsigned char *buf;
  MSF_UINT16 bufLen;
} sec_wtls_compute_signature_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  unsigned char *signature;
  MSF_UINT16 signatureLen;
} sec_wtls_compute_signature_response_t;

/**************************************************
 * TLS/SSL
 **************************************************/

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
} sec_tls_get_cipher_suites_t;
                  
typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  unsigned char *cipherSuites;
  MSF_UINT16 cipherSuitesLen;
} sec_tls_get_cipher_suites_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  MSF_UINT8 keyExchangeAlgorithm;
  MSF_UINT8 options;
  sec_tls_key_exch_params *params;
  unsigned char *certificate;
  MSF_UINT32 certificateLen;
  unsigned char *randval;
} sec_tls_key_exchange_t;
                       
typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  MSF_UINT8 masterSecretId;
  unsigned char *publicValue;
  MSF_UINT16 publicValueLen;
} sec_tls_key_exchange_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  MSF_UINT8 masterSecretId;
  unsigned char *secret;
  MSF_UINT16 secretLen;
  char *label;
  MSF_UINT16 labelLen;
  unsigned char *seed;
  MSF_UINT16 seedLen;
  MSF_UINT16 outputLen;
} sec_tls_prf_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  unsigned char *buf;
  MSF_UINT16 bufLen;
} sec_tls_prf_response_t;
                   
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  unsigned char *addr;
  MSF_UINT16 addrLen;
  unsigned char *domain;
  MSF_UINT16 domainLen;
  sec_tls_asn1_certificate *certs;
  MSF_UINT8 numCerts;
} sec_tls_verify_cert_chain_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
} sec_tls_verify_cert_chain_response_t;
    
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  unsigned char *certTypes;
  MSF_UINT8 numCertTypes;
  sec_tls_distinguished_name *certAuthorities;
  MSF_UINT8 numCertAuthorities;
} sec_tls_get_client_cert_t;
     
typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  unsigned char *pubKeyHash;
  sec_tls_asn1_certificate *certs;
  MSF_UINT8 numCerts;
} sec_tls_get_client_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;	
  unsigned char *pubKeyHash;
  unsigned char *data;
  MSF_UINT16 dataLen;
  MSF_UINT8 alg;
} sec_tls_compute_signature_t;

typedef struct {
  MSF_INT32 objectId;	
  MSF_UINT16 result;
  unsigned char *signature;
  MSF_UINT16 signatureLen;  
} sec_tls_compute_signature_response_t;

/**************************************************
 * signText
 **************************************************/

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_INT32 signId;
  char *text;
  char *data;
  MSF_UINT16 dataLen;
  MSF_UINT8 keyIdType;
  char *keyId;
  MSF_UINT16 keyIdLen;
  MSF_UINT8 options;
} sec_sign_text_t;

typedef struct {
  MSF_INT32 id;	
  MSF_INT32 signId;
  MSF_UINT8 algorithm;
  char *signature;
  MSF_UINT16 sigLen;
  char *hashedKey;
  MSF_UINT16 hashedKeyLen;
  char *certificate;
  MSF_UINT16 certificateLen;
  MSF_UINT8 certificateType;
  MSF_UINT8 err;
} sec_sign_text_response_t;

/**************************************************
 * CRYPT
 **************************************************/

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_UINT8 masterSecretId;
  MSF_INT32 security_id;
  MSF_UINT8 full_handshake;
  sec_session_info_t sessionInfo;
} sec_connection_established_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_INT32 securityId;
  MSF_UINT8 connectionType;
} sec_connection_terminated_t;
												
typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 masterSecretId;
} sec_peer_delete_links_t;

typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 connectionType;
  unsigned char *address;
  MSF_UINT16 addressLen;
  unsigned char *domain;
  MSF_UINT16 domainLen;
  MSF_UINT16 portnum;
  MSF_UINT8 masterSecretId;
} sec_peer_link_to_session_t;

typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 id;	
  MSF_UINT8 connectionType;
  unsigned char *address;
  MSF_UINT16 addressLen;
  unsigned char *domain;
  MSF_UINT16 domainLen;
  MSF_UINT16 portnum;
} sec_peer_lookup_t;

typedef struct {
  MSF_UINT8 id;	
  MSF_UINT16 result;
  MSF_UINT8 connectionType;
  MSF_UINT8 masterSecretId;
  MSF_INT32 security_id;
} sec_peer_lookup_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 masterSecretId;
  MSF_UINT8 isActive;
} sec_session_active_t;

typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 masterSecretId;
} sec_session_invalidate_t;

typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 id;	
  MSF_UINT8 masterSecretId;
} sec_session_fetch_t;

typedef struct {
  MSF_UINT8 id;	
  MSF_UINT16 result;
  MSF_UINT8 sessionOptions;
  unsigned char *sessionId;
  MSF_UINT16 sessionIdLen;
  MSF_UINT8 cipherSuite[2];
  MSF_UINT8 compressionAlg;
  unsigned char *privateKeyId;
  MSF_UINT32 creationTime;
} sec_session_fetch_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_UINT8 masterSecretId;
  MSF_UINT8 sessionOptions;
  unsigned char *sessionId;
  MSF_UINT8 sessionIdLen;
  MSF_UINT8 cipherSuite[2];
  MSF_UINT8 compressionAlg;
  unsigned char *privateKeyId;
  MSF_UINT32 creationTime;
} sec_session_update_t;


/**************************************************
 * CERT
 **************************************************/

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  char *contentType; 
  unsigned char *cert;
  MSF_UINT16 certLen; 
  unsigned char *certURL;
} sec_store_cert_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_store_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id; 
  char *contentType;
  unsigned char *trustedCAInfoStruct;
  MSF_UINT16 trustedCAInfoStructLen;
} sec_trusted_ca_info_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_trusted_ca_info_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  unsigned char *certResponse;
  MSF_UINT16 certResponseLen;
} sec_cert_delivery_t;

typedef struct {
  MSF_INT32 id; 
  MSF_UINT16 result;
} sec_cert_delivery_response_t;
  
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id; 
  MSF_UINT8 certOptions;
} sec_view_cert_names_t;

typedef struct {
  MSF_INT32 id; 
  MSF_UINT16 result;
} sec_view_cert_names_response_t;

typedef struct{
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 certOptions;
} sec_get_cert_ids_t;

typedef struct {
  MSF_INT32 id; 
  MSF_UINT16 result;
  MSF_UINT8 nbrCerts;
  MSF_UINT8 *certIds;
} sec_get_cert_ids_response_t;


typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 certOptions;
} sec_get_nbr_certs_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
  MSF_UINT8 nbrCerts;
} sec_get_nbr_certs_response_t;

typedef struct {  
  MSF_UINT8 source;
  MSF_INT32 id;
  sec_tls_asn1_certificate *certs;
  MSF_UINT8 numCerts;
} sec_verify_cert_chain_t;

typedef struct { 
  MSF_INT32 id;
  MSF_UINT16 result;
  MSF_UINT8 format;
  unsigned char *rootCert;
  MSF_UINT16 rootLen;
} sec_verify_cert_chain_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 keyType;
  MSF_UINT8 alg;
} sec_generate_key_pair_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
  MSF_UINT8 keyType; 
  unsigned char *publicKey;
  MSF_UINT16 publicKeyLen;
  unsigned char *sig;
  MSF_UINT16 sigLen;
} sec_generate_key_pair_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 keyType;
} sec_del_keys_user_certs_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_del_keys_user_certs_response_t;
 
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 keyType;
} sec_get_user_pub_key_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result; 
  unsigned char *publicKey;
  MSF_UINT16 publicKeyLen;
  unsigned char *sig;
  MSF_UINT16 sigLen;
} sec_get_user_pub_key_response_t;
 
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 keyType;
} sec_change_pin_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_change_pin_response_t;
	
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 keyType;
} sec_verify_puk_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_verify_puk_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_INT32 securityId;
} sec_view_current_cert_t;

typedef struct {
  MSF_INT32 objectId;
  MSF_UINT16 result;
} sec_view_current_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_INT32 securityId;
} sec_view_session_info_t;

typedef struct {
  MSF_INT32 objectId;
  MSF_UINT16 result;
} sec_view_session_info_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_INT32 securityId;
} sec_get_current_cert_t;

typedef struct {
  MSF_INT32      objectId;
  MSF_UINT16     result;
  MSF_UINT8      format;
  unsigned char *cert;
  MSF_UINT16     certLen;
} sec_get_current_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_INT32 securityId;
} sec_get_session_info_t;

typedef struct {
  MSF_INT32  objectId;
  MSF_UINT16 result;
  MSF_UINT8  connectionType;
	MSF_UINT8  hMacAlg;	
  MSF_UINT8  hMacKeyLen;
	MSF_UINT8  encrAlg;
	MSF_UINT16 encrKeyLen;
	MSF_UINT16 keyExchKeyLen;				     
  MSF_UINT16 keyExchangeAlgorithm;   
} sec_get_session_info_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId; 
  MSF_INT32 securityId;
} sec_get_current_sec_class_t;

typedef struct {
  MSF_INT32 id; 
  MSF_UINT8 sec_class;
  MSF_UINT8 info_available;
  MSF_UINT8 cert_available;
} sec_get_current_sec_class_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
} sec_session_clear_t;

typedef struct {
  MSF_INT32 id; 
  MSF_UINT16 result;
} sec_session_clear_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
} sec_view_contracts_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_view_contracts_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
} sec_get_contracts_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
  MSF_UINT16 nbrContracts;
  sec_contract_info_t *contracts;
} sec_get_contracts_response_t;

/**************************************************
 * TI
 **************************************************/

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 certId;
} sec_view_and_get_cert_t;


typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
  MSF_UINT8 certId;
  unsigned char *cert;
  MSF_UINT16 certLen;
} sec_view_and_get_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 certId;
} sec_delete_cert_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT8 certId;
  MSF_UINT16 result;
} sec_delete_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 certId;
} sec_get_cert_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
  MSF_UINT8 certId;
  unsigned char *cert;
  MSF_UINT16 certLen;
  unsigned char *trustedUsage;
  MSF_UINT16 trustedUsageLen;
} sec_get_cert_response_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
} sec_cancel_t;
                           
typedef struct {
  MSF_UINT8 source;
  MSF_INT32 id;
  MSF_UINT8 contractId;
} sec_delete_contract_t;

typedef struct {
  MSF_INT32 id;
  MSF_UINT16 result;
} sec_delete_contract_response_t;



/***********************************************************************
 *
 * Function return values
 *
 * Each function in this crypto library returns an integer
 * value. Successful return is indicated by the value SEC_ERR_OK.
 * Other values indicate some sort of failure or problem.
 * It is recommended that the following constants be used
 * as return values for the Adapter functions of this API.
 *
 ***********************************************************************/

#define SEC_ERR_OK                                0
#define SEC_ERR_GENERAL_ERROR                     1
#define SEC_ERR_BUFFER_TOO_SMALL                  2
#define SEC_ERR_UNSUPPORTED_METHOD                3
#define SEC_ERR_INSUFFICIENT_MEMORY               4
#define SEC_ERR_CRYPTOLIB_NOT_INITIALISED         5
#define SEC_ERR_KEY_TOO_LONG                      6
#define SEC_ERR_NOT_IMPLEMENTED                   7
#define SEC_ERR_INVALID_PARAMETER                 8
#define SEC_ERR_DATA_LENGTH                       9
#define SEC_ERR_INVALID_KEY                      10
#define SEC_ERR_INVALID_HANDLE                   11
#define SEC_ERR_KEY_LENGTH                       12
#define SEC_ERR_MISSING_KEY                      13
#define SEC_ERR_UNKNOWN_CERTIFICATE_TYPE         14
#define SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE     15
#define SEC_ERR_BAD_CERTIFICATE                  16
#define SEC_ERR_CERTIFICATE_EXPIRED              17
#define SEC_ERR_MISSING_CERTIFICATE              18
#define SEC_ERR_NOT_FOUND                        19
#define SEC_ERR_INVALID_COMMON_NAME              20

#define SEC_ERR_USER_NOT_VERIFIED                21
#define SEC_ERR_MISSING_AUT_KEY_HANDSHAKE        22
#define SEC_ERR_REACHED_USER_CERT_LIMIT          23
#define SEC_ERR_PIN_TOO_SHORT                    24  /* The PIN was shorter than SEC_PIN_MIN_SIZE */
#define SEC_ERR_PIN_TOO_LONG                     25  /* The PIN was longer than SEC_PIN_MAX_SIZE */
#define SEC_ERR_PIN_FALSE                        26
#define SEC_ERR_PIN_LOCKED                       27
#define SEC_ERR_MISSING_PUK                      28  /* No PUK is stored on the WIM                    */
#define SEC_ERR_WRONG_PUK                        29  /* The wrong PUK was entered                      */
#define SEC_ERR_PUK_PIN_UNCHANGED                30  /* The PUK has been verified, but the PIN has not */
                                                      /* been changed due to user cancel or error in TI */  
#define SEC_ERR_HASH_NOT_VERIFIED                31
#define SEC_ERR_MISSING_AUT_KEY_OPEN_WIM         32
#define SEC_ERR_MISSING_NR_KEY_SIGN_TEXT         33

#define SEC_ERR_MISSING_KEY_CONNECT              34
#define SEC_ERR_MISSING_KEY_STORE_CERT           35
#define SEC_ERR_MISSING_KEY_DELETE_CERT          36
#define SEC_ERR_MISSING_KEY_CHANGE_AUTH          37
#define SEC_ERR_MISSING_KEY_CHANGE_NONREP        38

#define SEC_ERR_PRIV_KEY_NOT_FOUND               39
#define SEC_ERR_COULD_NOT_STORE_CONTRACT         40
#define SEC_ERR_CANCEL                           41

/****************************************
 * API invoked from other modules
 ****************************************/

void 
SECif_startInterface (void);

/**************************************************
 * WTLS
 **************************************************/

void 
SECif_wtlsGetMethods (int source, int objectId);

void 
SECif_wtlsKeyExchange (int source, int objectId, 
                       sec_wtls_key_exch_params param, MSF_UINT8 hashAlg, 
                       const unsigned char *randval);

void 
SECif_wtlsPrf (int source, int objectId, MSF_UINT8 alg, 
               int masterSecretId,
               const unsigned char *secret, int secretLen,
               const char *label,
               const unsigned char *seed, int seedLen,
               int outputLen);

void 
SECif_wtlsVerifyCertChain (int source, int objectId,
                           const unsigned char *buf, int bufLen,
                           const unsigned char *addr, int addrLen,
                           const char *domain);

void 
SECif_wtlsGetClientCert (int source, int objectId, 
                         const unsigned char *buf, int bufLen);

void 
SECif_wtlsComputeSignature (int source, int objectId,
                            const unsigned char *keyId, int keyIdLen,
                            const unsigned char *buf, int bufLen);

/**************************************************
 * TLS/SSL
 **************************************************/

void 
SECif_tlsGetCipherSuites (int source, int objectId);

void 
SECif_tlsKeyExchange (int source, int objectId, int keyExchangeAlgorithm,
                      int options, sec_tls_key_exch_params *params,
                      const unsigned char *certificate, MSF_UINT32 certificateLen,
                      const unsigned char *randval);

void 
SECif_tlsPrf (int source, int objectId, int masterSecretId,
              const unsigned char *secret, int secretLen,
              const char *label,
              const unsigned char *seed, int seedLen,
              int outputLen);
                      
void 
SECif_tlsVerifyCertChain (int source, int objectId,
                          const unsigned char *addr, MSF_UINT16 addrLen, 
                          const unsigned char *domain, MSF_UINT16 domainLen,
                          sec_tls_asn1_certificate *certificates,
                          int numCertificates);

void 
SECif_tlsGetClientCert (int source, int objectId, 
                        const unsigned char *certificateTypes,
                        int numCertificateTypes,
                        sec_tls_distinguished_name *certAuthorities,
                        int numCertAuthorities);
                                        
void 
SECif_tlsComputeSignature (int source, int objectId, 
                           const unsigned char *pubKeyHash,
                           const unsigned char *data, int dataLen,
                           int alg);


/**************************************************
 * signText
 **************************************************/

void 
SECif_signText (int source, int id, int signId, const char *text,
                const char *data, int dataLen,
                int keyIdType, const char *keyId, int keyIdLen,
                int options);

/**************************************************
 * CRYPT
 **************************************************/

/* Connection status */
void
SECif_connectionEstablished (int source, int objectId, int masterSecretId, 
                             MSF_INT32 security_id, int full_handshake,
                             sec_session_info_t sessionInfo);

void
SECif_connectionTerminated (int source, int objectId, int securityId,
                            MSF_UINT8 connectionType);

/* 'Peers' methods */
void
SECif_peerDeleteLinks (int source, int masterSecretId);

void
SECif_peerLinkToSession (int source, MSF_UINT8 connectionType,
                         const unsigned char *address, int addressLen,
                         const char *domain, MSF_UINT16 portnum,
                         int masterSecretId);

void
SECif_peerLookup (int source, int id, MSF_UINT8 connectionType,
                  const unsigned char *address, int addressLen,
                  const char *domain, MSF_UINT16 portnum);
                   
/* 'Sessions' methods */
void
SECif_sessionActive (int source, int masterSecretId, MSF_UINT8 isActive);

void
SECif_sessionInvalidate (int source, int masterSecretId);

void
SECif_sessionFetch (int source, int id, int masterSecretId);
                            
void
SECif_sessionUpdate (int source, int masterSecretId, 
                     MSF_UINT8 sessionOptions,
                     const unsigned char *sessionId, 
                     MSF_UINT8 sessionIdLen,
                     MSF_UINT8 cipherSuite[2],
                     MSF_UINT8 compressionAlg,
                     const unsigned char *privateKeyId,
                     MSF_UINT32 creationTime);

/**************************************************
 * CERT
 **************************************************/

void 
SECif_storeCert(int source, int id, const char *contentType, 
                const unsigned char *cert, MSF_UINT16 certLen, 
                const unsigned char *certURL);
void 
SECif_trustedCAInfo(int source, int id, const char *contentType,
                    const unsigned char *trustedCAInfoStruct,
                    MSF_UINT16 trustedCAInfoStructLen);
void
SECif_certDelivery(int source, int id, 
                   const unsigned char *certResponse, 
                   MSF_UINT16 certResponseLen);
void 
SECif_viewCertNames(int source, int id, int certOptions);
void 
SECif_getCertIds(int source, int id, int certOptions);

void
SECif_getNbrCerts(int source, int id, int certOptions);

void
SECif_verifyCertChain(int source, int id, sec_tls_asn1_certificate *certs, 
                      int numCerts);

void 
SECif_viewAndGetCert(int source, int id, int certId);

void
SECif_getCert(int source, int id, int certId);

void 
SECif_cancel(int source, int objectId);

void 
SECif_deleteCert(int source, int id, int certId);

void 
SECif_generateKeyPair(int source, int id, MSF_UINT8 keyType, 
                      MSF_UINT8 alg);
  
void 
SECif_delKeysUserCertsByType(int source, int id, MSF_UINT8 keyType);
void 
SECif_getUserPubKey(int source, int id, MSF_UINT8 keyType);

void 
SECif_changePin(int source, int id, MSF_UINT8 keyType);

void 
SECif_verifyPuk(int source, int id, MSF_UINT8 keyType);

void 
SECif_viewCurrentCert(int source, int objectId, int securityId);

void 
SECif_viewSessionInfo(int source, int objectId, int securityId);

void 
SECif_getCurrentCert(int source, int objectId, int securityId);

void 
SECif_getSessionInfo(int source, int objectId, int securityId);

void 
SECif_getCurrentSecClass(int source, int objectId, int securityId); 

void 
SECif_sessionClear(int source, int id);

/**************************************************
 * Contracts
 **************************************************/

void 
SECif_viewContracts(int source, int id);

void 
SECif_getContracts(int source, int id);

void 
SECif_deleteContract(int source, int id, int contractId);


/****************************************************************
 *
 * Conversion functions. Convert signals owned by the SEC-Module, 
 * convert from memory buffer to signal structs. This functions
 * shall not be called directly by other modules.
 *
 ****************************************************************/

/**************************************************
 * WTLS
 **************************************************/

int 
sec_cvt_wtls_get_methods(msf_dcvt_t *obj, sec_wtls_get_methods_t *p);

int 
sec_cvt_wtls_get_methods_response(msf_dcvt_t *obj, 
                                  sec_wtls_get_methods_response_t *p);

int 
sec_cvt_wtls_key_exchange(msf_dcvt_t *obj, sec_wtls_key_exchange_t *p);

int 
sec_cvt_wtls_key_exchange_response(msf_dcvt_t *obj, 
                                   sec_wtls_key_exchange_response_t *p);

int 
sec_cvt_wtls_prf(msf_dcvt_t *obj, sec_wtls_prf_t *p);

int 
sec_cvt_wtls_prf_response(msf_dcvt_t *obj, sec_wtls_prf_response_t *p);

int 
sec_cvt_wtls_verify_cert_chain(msf_dcvt_t *obj, 
                               sec_wtls_verify_cert_chain_t *p);

int 
sec_cvt_wtls_verify_cert_chain_response(msf_dcvt_t *obj, 
                                        sec_wtls_verify_cert_chain_response_t *p);

int 
sec_cvt_wtls_get_client_cert(msf_dcvt_t *obj, sec_wtls_get_client_cert_t *p);

int 
sec_cvt_wtls_get_client_cert_response(msf_dcvt_t *obj, 
                                      sec_wtls_get_client_cert_response_t *p);

int 
sec_cvt_wtls_compute_signature(msf_dcvt_t *obj, sec_wtls_compute_signature_t *p);

int 
sec_cvt_wtls_compute_signature_response(msf_dcvt_t *obj, 
                                        sec_wtls_compute_signature_response_t *p);

/**************************************************
 * TLS/SSL
 **************************************************/

int 
sec_cvt_tls_get_cipher_suites(msf_dcvt_t *obj, sec_tls_get_cipher_suites_t *p);

int 
sec_cvt_tls_get_cipher_suites_response(msf_dcvt_t *obj, 
                                       sec_tls_get_cipher_suites_response_t *p);

int 
sec_cvt_tls_key_exchange(msf_dcvt_t *obj, sec_tls_key_exchange_t *p);

int 
sec_cvt_tls_key_exchange_response(msf_dcvt_t *obj, 
                                  sec_tls_key_exchange_response_t *p);

int 
sec_cvt_tls_prf(msf_dcvt_t *obj, sec_tls_prf_t *p);

int 
sec_cvt_tls_prf_response(msf_dcvt_t *obj, sec_tls_prf_response_t *p);

int /*part of sec_cvt_tls_verify_cert_chain*/
sec_cvt_sec_tls_asn1_certificate (msf_dcvt_t *obj, sec_tls_asn1_certificate *p);

int 
sec_cvt_tls_verify_cert_chain(msf_dcvt_t *obj, sec_tls_verify_cert_chain_t *p);

int 
sec_cvt_tls_verify_cert_chain_response(msf_dcvt_t *obj, 
                                       sec_tls_verify_cert_chain_response_t *p);

int /*part of sec_cvt_tls_get_client_cert*/
sec_cvt_tls_distinguished_name (msf_dcvt_t *obj, sec_tls_distinguished_name *p);

int 
sec_cvt_tls_get_client_cert(msf_dcvt_t *obj, sec_tls_get_client_cert_t *p);

int 
sec_cvt_tls_get_client_cert_response(msf_dcvt_t *obj, 
                                     sec_tls_get_client_cert_response_t *p);

int 
sec_cvt_tls_compute_signature(msf_dcvt_t *obj, sec_tls_compute_signature_t *p);

int 
sec_cvt_tls_compute_signature_response(msf_dcvt_t *obj, 
                                       sec_tls_compute_signature_response_t *p);

/**************************************************
 * signText
 **************************************************/

int 
sec_cvt_sign_text(msf_dcvt_t *obj, sec_sign_text_t *p);

int 
sec_cvt_sign_text_response(msf_dcvt_t *obj, sec_sign_text_response_t *p);

/**************************************************
 * CRYPT
 **************************************************/

int 
sec_cvt_connection_established(msf_dcvt_t *obj, 
                               sec_connection_established_t *p);

int 
sec_cvt_session_info(msf_dcvt_t *obj,
                     sec_session_info_t *p);

int 
sec_cvt_connection_terminated(msf_dcvt_t *obj, 
                              sec_connection_terminated_t *p);

int 
sec_cvt_peer_delete_links(msf_dcvt_t *obj, sec_peer_delete_links_t *p);

int 
sec_cvt_peer_link_to_session(msf_dcvt_t *obj, 
                             sec_peer_link_to_session_t *p);

int 
sec_cvt_peer_lookup(msf_dcvt_t *obj, sec_peer_lookup_t *p);

int 
sec_cvt_peer_lookup_response(msf_dcvt_t *obj, 
                             sec_peer_lookup_response_t *p);

int 
sec_cvt_session_active(msf_dcvt_t *obj, sec_session_active_t *p);

int 
sec_cvt_session_invalidate(msf_dcvt_t *obj, sec_session_invalidate_t *p);

int 
sec_cvt_session_fetch(msf_dcvt_t *obj, sec_session_fetch_t *p);

int 
sec_cvt_session_fetch_response(msf_dcvt_t *obj, 
                               sec_session_fetch_response_t *p);

int 
sec_cvt_session_update(msf_dcvt_t *obj, sec_session_update_t *p);

/**************************************************
 * CERT
 **************************************************/

int 
sec_cvt_store_cert (msf_dcvt_t *obj, sec_store_cert_t *p);
int 
sec_cvt_store_cert_response (msf_dcvt_t *obj, 
                             sec_store_cert_response_t *p);
int 
sec_cvt_trusted_ca_info (msf_dcvt_t *obj, sec_trusted_ca_info_t *p);
int 
sec_cvt_trusted_ca_info_response (msf_dcvt_t *obj, 
                                  sec_trusted_ca_info_response_t *p);
int 
sec_cvt_cert_delivery (msf_dcvt_t *obj, sec_cert_delivery_t *p);
int 
sec_cvt_cert_delivery_response (msf_dcvt_t *obj, 
                                sec_cert_delivery_response_t *p);
int 
sec_cvt_view_cert_names (msf_dcvt_t *obj, sec_view_cert_names_t *p);
int 
sec_cvt_view_cert_names_response (msf_dcvt_t *obj, 
                                  sec_view_cert_names_response_t *p);
int 
sec_cvt_get_cert_ids(msf_dcvt_t *obj, sec_get_cert_ids_t *p);

int 
sec_cvt_get_cert_ids_response (msf_dcvt_t *obj, 
                               sec_get_cert_ids_response_t *p);

int 
sec_cvt_get_nbr_certs (msf_dcvt_t *obj, sec_get_nbr_certs_t *p);

int 
sec_cvt_get_nbr_certs_response (msf_dcvt_t *obj, 
                                sec_get_nbr_certs_response_t *p);

int 
sec_cvt_verify_cert_chain (msf_dcvt_t *obj, sec_verify_cert_chain_t *p);

int 
sec_cvt_verify_cert_chain_response (msf_dcvt_t *obj, 
                                    sec_verify_cert_chain_response_t *p);

int 
sec_cvt_view_and_get_cert (msf_dcvt_t *obj, sec_view_and_get_cert_t *p);
int 
sec_cvt_view_and_get_cert_response (msf_dcvt_t *obj, sec_view_and_get_cert_response_t *p);
int 
sec_cvt_delete_cert (msf_dcvt_t *obj, sec_delete_cert_t *p);
int 
sec_cvt_delete_cert_response (msf_dcvt_t *obj, 
                              sec_delete_cert_response_t *p);
int 
sec_cvt_get_cert (msf_dcvt_t *obj, sec_get_cert_t *p);

int 
sec_cvt_get_cert_response (msf_dcvt_t *obj, sec_get_cert_response_t *p);

int 
sec_cvt_cancel (msf_dcvt_t *obj, sec_cancel_t *p);

int 
sec_cvt_generate_key_pair (msf_dcvt_t *obj, 
                           sec_generate_key_pair_t *p);
int 
sec_cvt_generate_key_pair_response (msf_dcvt_t *obj, 
                                    sec_generate_key_pair_response_t *p);
int 
sec_cvt_delete_keys_user_certs (msf_dcvt_t *obj, 
                                sec_del_keys_user_certs_t *p);
int 
sec_cvt_del_keys_user_certs_response (msf_dcvt_t *obj, 
                                      sec_del_keys_user_certs_response_t *p);
int 
sec_cvt_get_user_pub_key (msf_dcvt_t *obj, 
                          sec_get_user_pub_key_t *p);
int 
sec_cvt_get_user_pub_key_response (msf_dcvt_t *obj, 
                                   sec_get_user_pub_key_response_t *p);
int 
sec_cvt_change_pin (msf_dcvt_t *obj, sec_change_pin_t *p);
int 
sec_cvt_change_pin_response (msf_dcvt_t *obj, 
                             sec_change_pin_response_t *p);
	
int 
sec_cvt_verify_puk (msf_dcvt_t *obj, sec_verify_puk_t *p);

int 
sec_cvt_verify_puk_response (msf_dcvt_t *obj, 
                             sec_verify_puk_response_t *p);

int 
sec_cvt_view_current_cert (msf_dcvt_t *obj, 
                           sec_view_current_cert_t *p);
int 
sec_cvt_view_current_cert_response (msf_dcvt_t *obj, 
                                    sec_view_current_cert_response_t *p);
int 
sec_cvt_view_session_info (msf_dcvt_t *obj, 
                           sec_view_session_info_t *p);
int 
sec_cvt_view_session_info_response (msf_dcvt_t *obj, 
                                    sec_view_session_info_response_t *p);

int 
sec_cvt_get_current_cert (msf_dcvt_t *obj, 
                           sec_get_current_cert_t *p);
int 
sec_cvt_get_current_cert_response (msf_dcvt_t *obj, 
                                    sec_get_current_cert_response_t *p);
int 
sec_cvt_get_session_info (msf_dcvt_t *obj, 
                           sec_get_session_info_t *p);
int 
sec_cvt_get_session_info_response (msf_dcvt_t *obj, 
                                    sec_get_session_info_response_t *p);
int 
sec_cvt_get_current_sec_class (msf_dcvt_t *obj, 
                               sec_get_current_sec_class_t *p);
int 
sec_cvt_get_current_sec_class_response (msf_dcvt_t *obj, 
                                        sec_get_current_sec_class_response_t *p);
int 
sec_cvt_session_clear (msf_dcvt_t *obj, sec_session_clear_t *p);
int 
sec_cvt_session_clear_response (msf_dcvt_t *obj, 
                                sec_session_clear_response_t *p);


/**************************************************
 * TI
 **************************************************/

int 
sec_cvt_view_contracts (msf_dcvt_t *obj, 
                        sec_view_contracts_t *p);
int 
sec_cvt_view_contracts_response (msf_dcvt_t *obj, 
                                 sec_view_contracts_response_t *p);
int 
sec_cvt_get_contracts (msf_dcvt_t *obj, sec_get_contracts_t *p);
int 
sec_cvt_get_contracts_response (msf_dcvt_t *obj, 
                                sec_get_contracts_response_t *p);
int 
sec_cvt_delete_contract (msf_dcvt_t *obj, sec_delete_contract_t *p);
int 
sec_cvt_delete_contract_response (msf_dcvt_t *obj, 
                                  sec_delete_contract_response_t *p);

/**********************************************************************
 * Logging functions
 **********************************************************************/

void 
sec_log_wtls_get_methods(MSF_UINT8 source, sec_wtls_get_methods_t *p);

void 
sec_log_wtls_get_methods_response(MSF_UINT8 dst, sec_wtls_get_methods_response_t *p);

void 
sec_log_wtls_key_exchange(MSF_UINT8 source, sec_wtls_key_exchange_t *p);

void
sec_log_wtls_key_exchange_response(MSF_UINT8 dst, sec_wtls_key_exchange_response_t *p);

void
sec_log_wtls_prf(MSF_UINT8 source, sec_wtls_prf_t *p);

void
sec_log_wtls_prf_response(MSF_UINT8 dst, sec_wtls_prf_response_t *p);

void
sec_log_wtls_verify_cert_chain(MSF_UINT8 source, sec_wtls_verify_cert_chain_t *p);

void 
sec_log_wtls_verify_cert_chain_response(MSF_UINT8 dst, 
                                        sec_wtls_verify_cert_chain_response_t *p);

void
sec_log_wtls_get_client_cert(MSF_UINT8 source, sec_wtls_get_client_cert_t *p);

void 
sec_log_wtls_get_client_cert_response(MSF_UINT8 dst, sec_wtls_get_client_cert_response_t *p);

void 
sec_log_wtls_compute_signature(MSF_UINT8 source, sec_wtls_compute_signature_t *p);

void 
sec_log_wtls_compute_signature_response(MSF_UINT8 dst, sec_wtls_compute_signature_response_t *p);

void 
sec_log_tls_get_cipher_suites(MSF_UINT8 source, sec_tls_get_cipher_suites_t *p);

void 
sec_log_tls_get_cipher_suites_response(MSF_UINT8 dst, 
                                       sec_tls_get_cipher_suites_response_t *p);

void 
sec_log_tls_key_exchange(MSF_UINT8 source, sec_tls_key_exchange_t *p);

void 
sec_log_tls_key_exchange_response(MSF_UINT8 dst, 
                                  sec_tls_key_exchange_response_t *p);

void
sec_log_tls_prf(MSF_UINT8 source, sec_tls_prf_t *p);

void 
sec_log_tls_prf_response(MSF_UINT8 dst, sec_tls_prf_response_t *p);

void
sec_log_tls_verify_cert_chain(MSF_UINT8 source, sec_tls_verify_cert_chain_t *p);

void 
sec_log_tls_verify_cert_chain_response(MSF_UINT8 dst, 
                                       sec_tls_verify_cert_chain_response_t *p);

void
sec_log_tls_get_client_cert(MSF_UINT8 source, sec_tls_get_client_cert_t *p);

void
sec_log_tls_get_client_cert_response(MSF_UINT8 dst, sec_tls_get_client_cert_response_t *p);

void
sec_log_tls_compute_signature(MSF_UINT8 source, sec_tls_compute_signature_t *p);

void
sec_log_tls_compute_signature_response(MSF_UINT8 dst, 
                                       sec_tls_compute_signature_response_t *p);

void 
sec_log_sign_text(MSF_UINT8 source, sec_sign_text_t *p);

void 
sec_log_sign_text_response(MSF_UINT8 dst, sec_sign_text_response_t *p);

void 
sec_log_connection_established(MSF_UINT8 source, sec_connection_established_t *p);

void 
sec_log_connection_terminated(MSF_UINT8 source, sec_connection_terminated_t *p);

void
sec_log_peer_delete_links(MSF_UINT8 source, sec_peer_delete_links_t *p);

void
sec_log_peer_link_to_session(MSF_UINT8 source, sec_peer_link_to_session_t *p);

void
sec_log_peer_lookup(MSF_UINT8 source, sec_peer_lookup_t *p);

void
sec_log_peer_lookup_response(MSF_UINT8 dst, sec_peer_lookup_response_t *p);

void
sec_log_session_active(MSF_UINT8 source, sec_session_active_t *p);

void 
sec_log_session_invalidate(MSF_UINT8 source, sec_session_invalidate_t *p);

void
sec_log_session_fetch(MSF_UINT8 source, sec_session_fetch_t *p);

void
sec_log_session_fetch_response(MSF_UINT8 dst, sec_session_fetch_response_t *p);

void
sec_log_session_update(MSF_UINT8 source, sec_session_update_t *p);

void 
sec_log_store_cert (MSF_UINT8 source, sec_store_cert_t *p);

void  
sec_log_store_cert_response (MSF_UINT8 dst, 
                             sec_store_cert_response_t *p);

void 
sec_log_trusted_ca_info (MSF_UINT8 source, sec_trusted_ca_info_t *p);

void 
sec_log_trusted_ca_info_response (MSF_UINT8 dst, 
                                  sec_trusted_ca_info_response_t *p);

void 
sec_log_cert_delivery (MSF_UINT8 source, sec_cert_delivery_t *p);

void 
sec_log_cert_delivery_response (MSF_UINT8 dst, 
                                sec_cert_delivery_response_t *p);

void 
sec_log_view_cert_names (MSF_UINT8 source, sec_view_cert_names_t *p);

void 
sec_log_view_cert_names_response (MSF_UINT8 dst, 
                                  sec_view_cert_names_response_t *p);
void 
sec_log_get_cert_ids (MSF_UINT8 source, sec_get_cert_ids_t *p);

void
sec_log_get_cert_ids_response(MSF_UINT8 dst, 
                                  sec_get_cert_ids_response_t *p);

void 
sec_log_get_nbr_certs (MSF_UINT8 source, sec_get_nbr_certs_t *p);

void 
sec_log_get_nbr_certs_response (MSF_UINT8 dst, 
                                sec_get_nbr_certs_response_t *p);

void 
sec_log_verify_cert_chain (MSF_UINT8 source, sec_verify_cert_chain_t *p);

void 
sec_log_verify_cert_chain_response (MSF_UINT8 dst, 
                                    sec_verify_cert_chain_response_t *p);

void 
sec_log_generate_key_pair (MSF_UINT8 source, sec_generate_key_pair_t *p);

void  
sec_log_generate_key_pair_response (MSF_UINT8 dst, 
                                    sec_generate_key_pair_response_t *p);

void 
sec_log_delete_keys_user_certs (MSF_UINT8 source, 
                                sec_del_keys_user_certs_t *p);

void 
sec_log_del_keys_user_certs_response (MSF_UINT8 dst, 
                                      sec_del_keys_user_certs_response_t *p);

void 
sec_log_get_user_pub_key (MSF_UINT8 source, sec_get_user_pub_key_t *p);

void 
sec_log_get_user_pub_key_response (MSF_UINT8 dst, 
                                   sec_get_user_pub_key_response_t *p);

void 
sec_log_change_pin (MSF_UINT8 source, sec_change_pin_t *p);

void 
sec_log_change_pin_response (MSF_UINT8 dst, 
                             sec_change_pin_response_t *p);

void  
sec_log_verify_puk (MSF_UINT8 source, sec_verify_puk_t *p);

void  
sec_log_verify_puk_response (MSF_UINT8 dst, 
                             sec_verify_puk_response_t *p);

void  
sec_log_view_current_cert (MSF_UINT8 source, 
                           sec_view_current_cert_t *p);
void  
sec_log_view_current_cert_response (MSF_UINT8 dst, 
                                    sec_view_current_cert_response_t *p);

void  
sec_log_view_session_info (MSF_UINT8 source, sec_view_session_info_t *p);

void 
sec_log_view_session_info_response (MSF_UINT8 dst, 
                                    sec_view_session_info_response_t *p);

void  
sec_log_get_current_cert (MSF_UINT8 source, 
                           sec_get_current_cert_t *p);
void  
sec_log_get_current_cert_response (MSF_UINT8 dst, 
                                    sec_get_current_cert_response_t *p);

void  
sec_log_get_session_info (MSF_UINT8 source, sec_get_session_info_t *p);

void 
sec_log_get_session_info_response (MSF_UINT8 dst, 
                                    sec_get_session_info_response_t *p);
void 
sec_log_get_current_sec_class (MSF_UINT8 source, 
                               sec_get_current_sec_class_t *p);

void 
sec_log_get_current_sec_class_response (MSF_UINT8 dst, 
                                        sec_get_current_sec_class_response_t *p);

void 
sec_log_session_clear (MSF_UINT8 source, sec_session_clear_t *p);

void 
sec_log_session_clear_response (MSF_UINT8 dst, 
                                sec_session_clear_response_t* p);

void 
sec_log_view_contracts (MSF_UINT8 source, sec_view_contracts_t *p);

void 
sec_log_view_contracts_response (MSF_UINT8 dst, 
                                 sec_view_contracts_response_t *p);

void 
sec_log_view_and_get_cert (MSF_UINT8 source, sec_view_and_get_cert_t *p);

void 
sec_log_view_and_get_cert_response (MSF_UINT8 dst, sec_view_and_get_cert_response_t *p);

void 
sec_log_delete_cert (MSF_UINT8 source, sec_delete_cert_t *p);

void 
sec_log_delete_cert_response (MSF_UINT8 dst, 
                              sec_delete_cert_response_t *p);

void 
sec_log_get_cert (MSF_UINT8 source, sec_get_cert_t *p);

void 
sec_log_get_cert_response (MSF_UINT8 dst, sec_get_cert_response_t *p);

void 
sec_log_cancel (MSF_UINT8 dst, sec_cancel_t *p);

void
sec_log_get_contracts (MSF_UINT8 source, sec_get_contracts_t *p);

void
sec_log_get_contracts_response (MSF_UINT8 dst, 
                                sec_get_contracts_response_t *p);

void 
sec_log_delete_contract (MSF_UINT8 source, sec_delete_contract_t *p);

void 
sec_log_delete_contract_response (MSF_UINT8 dst, 
                                  sec_delete_contract_response_t *p);

/**************************************************
 * 
 **************************************************/

void *
sec_convert (MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

void
sec_destruct (MSF_UINT8 module, MSF_UINT16 signal, void *p);


#endif




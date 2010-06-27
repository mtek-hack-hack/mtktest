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

#define SEC_SIG_GET_CIPHER_SUITES                  ((MSF_MODID_SEC << 8) + 0x0d)
#define SEC_SIG_TLS_GET_CIPHER_SUITES_RESPONSE     ((MSF_MODID_SEC << 8) + 0x0e)
#define SEC_SIG_TLS_KEY_EXCHANGE                   ((MSF_MODID_SEC << 8) + 0x0f)
#define SEC_SIG_TLS_KEY_EXCHANGE_RESPONSE          ((MSF_MODID_SEC << 8) + 0x10)
#define SEC_SIG_TLS_PRF                            ((MSF_MODID_SEC << 8) + 0x11)
#define SEC_SIG_TLS_PRF_RESPONSE                   ((MSF_MODID_SEC << 8) + 0x12)
#define SEC_SIG_TLS_VERIFY_CERT_CHAIN              ((MSF_MODID_SEC << 8) + 0x13)
#define SEC_SIG_TLS_VERIFY_CERT_CHAIN_RESPONSE     ((MSF_MODID_SEC << 8) + 0x14)
#define SEC_SIG_TLS_GET_CLIENT_CERT                ((MSF_MODID_SEC << 8) + 0x15)
#define SEC_SIG_TLS_GET_CLIENT_CERT_RESPONSE       ((MSF_MODID_SEC << 8) + 0x16)
#define SEC_SIG_TLS_COMPUTE_SIGNATURE              ((MSF_MODID_SEC << 8) + 0x17)
#define SEC_SIG_TLS_COMPUTE_SIGNATURE_RESPONSE     ((MSF_MODID_SEC << 8) + 0x18)

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

/***********************************************************************
 *
 * Type and constant definitions
 *
 ***********************************************************************/

/* Secure connection protocols */
#define SEC_CONNECTION_TYPE_TLS         1
#define SEC_CONNECTION_TYPE_WTLS        2
#define SEC_CONNECTION_TYPE_SSL         3

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
  MSF_INT32     hMacAlg;
  MSF_INT32     hMacAlgKeyLen;
  MSF_INT32     encryptionAlg;
  MSF_INT32     encryptionAlgKeyLen;
} sec_session_params;

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

/* The secure hash algorithms that can be used in WTLS. */
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

/*
 * This structure must be used in the signal SEC_SIG_WTLS_GET_METHODS_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_wtlsGetMethods, and "result"
 * is the return value, as defined below.
 * The rest of the parameters are "cipherMethods", which holds
 * pairs of values, <BulkCipherAlgorithm, HashAlgorithm>;
 * "keyExchangeIds", which holds preferred key exchange methods;
 * and "trustedKeyIds", which holds trusted certificates.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_WTLS_KEY_EXCHANGE_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_wtlsKeyExchange, and "result"
 * is the return value, as defined below.
 * The other parameters hold the master secret ID, and possibly
 * a public value to be sent to the server as part of the key
 * key exchange process.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_WTLS_PRF_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_wtlsPRF, and "result"
 * is the return value, as defined below.
 * The parameter "buf" holds the computed value.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_WTLS_VERIFY_CERT_CHAIN_RESPONSE.
 * The parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_wtlsVerifyCertificateChain, and "result"
 * is the return value, as defined below.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_WTLS_GET_CLIENT_CERT_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_wtlsGetClientCertificate, and "result"
 * is the return value, as defined below.
 * The parameter "keyId" should hold a byte-encoded Identifier value
 * that can be used to identify the client private key associated with
 * the certificate(s) contained in the buffer "cert".
 * If no suitable certificate was available, "result" should
 * be set to SEC_ERR_MISSING_CERTIFICATE.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_WTLS_COMPUTE_SIGNATURE_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_wtlsComputeSignature, and "result"
 * is the return value, as defined below.
 * The computed signature is in the buffer "signature".
 * If the requested private key was not available, the result
 * should be set to "SEC_ERR_MISSING_KEY".
 */
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
 
/*
 * This structure must be used in the signal SEC_SIG_TLS_GET_CIPHER_SUITE_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_tlsGetCipherSuites, and "result"
 * is the return value, as defined in below.
 * NOTE that each cipher suite takes up two bytes!
 */                 
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
       
/*
 * This structure must be used in the signal SEC_SIG_TLS_KEY_EXCHANGE_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_tlsVerifyCertificateChain, and "result"
 * is the return value, as defined below.
 * The other parameters hold the master secret ID, and possibly
 * a public value to be sent to the server as part of the key
 * key exchange process.
 */                
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

/*
 * This structure must be used in the signal SEC_SIG_PRF_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_tlsPRF, and "result"
 * is the return value, as defined below.
 * The parameter "buf" holds the computed value.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_VERIFY_CERT_CHAIN_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_tlsVerifyCertificateChain, and "result"
 * is the return value, as defined below.
 */
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

/*
 * This structure must be used in the signal SEC_SIG_GET_CLIENT_CERT_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_tlsGetClientCertificate, and "result"
 * is the return value, as defined in below.
 * The parameter "pubKeyHash" should hold a 20-byte SHA-1 hash of the
 * public key of the client certificate;
 * this will be used to identify the client private key associated with
 * the certificate(s) contained in the buffer "certificates".
 * If no suitable certificate was available, "result" should
 * be set to SEC_ERR_MISSING_CERTIFICATE.
 */     
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
} sec_tls_compute_signature_t;

/*
 * This structure must be used in the signal SEC_SIG_GET_COMPUTE_SIGNATURE_RESPONSE.
 * The first parameter, "objectId", should hold the same value that
 * was passed in the call to SECif_tlsComputeSignature, and "result"
 * is the return value, as defined below.
 * The computed signature is in the buffer "signature".
 * If the requested private key was not available, the result
 * should be set to "SEC_ERR_MISSING_KEY".
 */
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

/*
 * This structure must be used in the signal SEC_SIG_SIGN_TEXT_RESPONSE.
 * The parameter, "signId", should hold the same value that
 * was passed in the call to SECif_signText.
 * algorithm: the algorithm used to compute the signature. SEC_SIGN_ALG_RSA 
 * or SEC_SIGN_ALG_ECDSA. 
 * hashed key: hashed key if SEC_SIGN_RETURN_HASHED_KEY otherwise NULL.
 * certificate: certificate if SEC_SIG_RETURN_CERTIFICTE otherwise NULL.
 * certificate type: the type of certificate supplied SEC_SIGN_WTLS_CERTIFICATE,
 * SEC_SIGN_X509_CERTIFICATE, SEC_SIGN_X968_CERTIFICATE or SEC_SIGN_URL_CERTIFICATE.
 * The returnvalue should be one of SEC_SIGN_NO_ERROR, SEC_SIGN_MISSING_CERTIFICATE,
 * SIGN_USER_CANCELED or SEC_SIGN_OTHER_ERROR.
 */
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
  MSF_INT32 socketId;
  MSF_UINT8 connectionType;
  MSF_UINT8 masterSecretId;
  sec_session_params sessionInfo;
} sec_connection_established_t;

typedef struct {
  MSF_UINT8 source;
  MSF_INT32 objectId;
  MSF_INT32 socketId;
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

/*
 * This structure must be used in the signal SEC_SIG_PEER_LOOKUP_RESPONSE.
 * The first parameter, "id", should hold the same value that
 * was passed in the call to SECif_peerLookup, and "result"
 * is the return value, as defined below.
 * The result is a master secret ID. If the requested
 * peer was not found the result should be set to "SEC_ERR_NOT_FOUND".
 */
typedef struct {
  MSF_UINT8 id;	
  MSF_UINT16 result;
  MSF_UINT8 connectionType;
  MSF_UINT8 masterSecretId;
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

/*
 * This structure must be used in the signal SEC_SIG_SESSION_FETCH_RESPONSE.
 * The first parameter, "id", should hold the same value that
 * was passed in the call to SECif_sessionFetch, and "result"
 * is the return value, as defined below.
 * If the requested session slot was not found (or empty),
 * the result should be set to "SEC_ERR_NOT_FOUND". Otherwise, the values
 * found in the session slot are passed in the remaining parameters.
 */
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

#define SEC_ERR_MISSING_AUT_KEY_HANDSHAKE        22
#define SEC_ERR_MISSING_NR_KEY_SIGN_TEXT         33
#define SEC_ERR_PRIV_KEY_NOT_FOUND               39
#define SEC_ERR_CANCEL                           41

/****************************************
 * API invoked from other modules
 ****************************************/

void 
SECif_startInterface (void);

/**************************************************
 * WTLS
 **************************************************/
/*
 * Retrieve lists of crypto parameters that the crypto library supports.
 * This includes cipher methods, key exchange methods, and trusted
 * certificates.
 * The response should be delivered by the signal SEC_SIG_WTLS_GET_METHOD_
 * RESPONSE. The parameter, "objectId", should be passed back in this 
 * response.
 */
void 
SECif_wtlsGetMethods (int source, int objectId);

/*
 * Perform key exchange, using one of the methods previously
 * reported to be available.
 * Derives the master secret using the pre-master secret produced
 * by the key exchange algorithm, and the 32 random bytes
 * (ClientHello.random + ServerHello.random) supplied
 * as a parameter to this call. The master secret is kept internally in
 * the crypto library, to be used in subsequent operations.
 * The parameter "alg" is the secure hash algorithm to be used.
 * The response should be delivered by the signal SEC_SIG_WTLS_KEY_
 * EXCHANGE_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 *
 * RSA:
 * The public key to use is either given explicitly in the parameters,
 * or must be retrieved from a certificate passed to this routine.
 * This function generates a 20-byte value consisting of the given
 * "additionalData" and 19 random bytes. It encrypts the value with
 * the given public key, and stores the result in publicValue.
 * The pre-master secret is the 20-byte value appended with the
 * given public key.
 *
 * Diffie-Hellman: calculate a pre-master secret and a public value
 * to be sent to the server side.
 * The public key to use is given explicitly in the parameters.
 * This function performs a DH calculation based on the given
 * public key and a private key kept in the crypto library.
 *
 * ECDH: calculate a pre-master secret and a public value
 * to be sent to the server side.
 * The public key to use is either given explicitly in the parameters,
 * or must be retrieved from a certificate passed to this routine.
 * This function performs an ECDH calculation based on the given
 * public key and a private key kept in the crypto library.
 *
 * Null: set the pre-master secret to be the empty string.
 *
 */

void 
SECif_wtlsKeyExchange (int source, int objectId, 
                       sec_wtls_key_exch_params param, MSF_UINT8 hashAlg, 
                       const unsigned char *randval);

/*
 * Calculate the Pseudo-Random Function defined in section
 * 11.3.2 in the WTLS spec.
 * If the master secret is to be used as first parameter,
 * then "secret" is NULL, and "masterSecretId" indicates which
 * master secret to use. Otherwise, "secret" is provided explicitly.
 * The parameter "label" is a null-terminated character string.
 * The parameter "alg" is the secure hash algorithm to be used,
 * and "outputLen" is the number of bytes of output to produce.
 * The response should be delivered by the signal SEC_SIG_WTLS_PRF_
 * RESPONSE. The parameter, "objectId", should be
 * passed back in this response.
 */
void 
SECif_wtlsPrf (int source, int objectId, MSF_UINT8 alg, 
               int masterSecretId,
               const unsigned char *secret, int secretLen,
               const char *label,
               const unsigned char *seed, int seedLen,
               int outputLen);

/*
 * Verify a chain of certificates.
 * The buffer, "buf", contains a chain of certificates. See section
 * 10.5.2 in the WTLS specification.
 * The parameter "addr" holds the address of the server in the format
 * defined in section 7.5.2 of the WCMP specification.
 * If "domain" is not NULL, it holds the domain name of the server
 * as a null-terminated character string.
 *
 * If possible, this routine should verify that the given address/domainname
 * matches the "common name" field of the certificate. In case the
 * certificate does not have a common name field, or the common name
 * field holds a domain name and the "domain" parameter is NULL,
 * then the checking of the common name field is omitted.
 *
 * The response should be delivered by the signal SEC_SIG_WTLS_VERIFY_CERT_
 * CHAIN_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */
void 
SECif_wtlsVerifyCertChain (int source, int objectId,
                           const unsigned char *buf, int bufLen,
                           const unsigned char *addr, int addrLen,
                           const char *domain);

/*
 * Retrieve a client certificate.
 * The buffer, "buf", contains a list of acceptable certificate
 * authorities, as byte encoded KeyExchangeId:s. See section 10.5.4
 * in the WTLS specification.
 * The response should be delivered by the signal SEC_SIG_WTLS_GET_CLIENT_
 * CERT_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */
void 
SECif_wtlsGetClientCert (int source, int objectId, 
                         const unsigned char *buf, int bufLen);
/*
 * Compute a digital signature.
 * The buffer, "buf", contains the data to be signed, and the key
 * identifier, "keyId", contains a byte-encoded Identifier.
 * This latter value is either fetched from the Key Exchange Ids
 * passed back in SEC_SIG_WTLS_GET_METHOD_RESPONSE, or is the value
 * passed back in SEC_SIG_WTLS_GET_CLIENT_CERT_RESPONSE (provided that
 * this function has been used). The keyId value indicates
 * which key must be used for signing.
 * The response should be delivered by the signal SEC_SIG_WTLS_COMPUTE_
 * SIGNATURE_RESPONSE. The parameter, "objectId", should be passed back 
 * in this response.
 */
void 
SECif_wtlsComputeSignature (int source, int objectId,
                            const unsigned char *keyId, int keyIdLen,
                            const unsigned char *buf, int bufLen);

/**************************************************
 * TLS/SSL
 **************************************************/

/*
 * Retrieve a list of the TLS cipher suites that should be used
 * when setting up a TLS secure connection.
 * The response should be delivered by the signal SEC_SIG_TLS_GET_CIPHER
 * SUITE_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */
void 
SECif_tlsGetCipherSuites (int source, int objectId);

/*
 * Perform key exchange, using one of the methods previously
 * reported to be available. For example, if SECif_tlsGetCipherSuites
 * discovered that TLS_RSA_WITH_NULL_MD5 was available, and this
 * cipher suite was selected in the handshake, then the key exchange
 * procedure will be called with "keyExchangeAlgorithm" set
 * to TLS_KEYEXCH_RSA.
 * If 'is_ssl' is TRUE, use the SSL key exchange procedure,
 * else use TLS.
 * Derives the master secret using the pre-master secret produced
 * by the key exchange algorithm, and the 64 random bytes
 * (ClientHello.random + ServerHello.random) supplied
 * as a parameter to this call ("randval").
 * The master secret is kept internally in the crypto library,
 * to be used in subsequent operations.
 * The response should be delivered by the signal SEC_SIG_TLS_KEY_EXCHANGE_
 * RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */
void 
SECif_tlsKeyExchange (int source, int objectId, int keyExchangeAlgorithm,
                      int options, sec_tls_key_exch_params *params,
                      const unsigned char *certificate, MSF_UINT32 certificateLen,
                      const unsigned char *randval);

/*
 * Calculate the Pseudo-Random Function defined in chapter 5
 * of the TLS spec.
 * If the master secret is to be used as first parameter,
 * then "secret" is NULL, and "masterSecretId" indicates which
 * master secret to use. Otherwise, "secret" is provided explicitly.
 * The parameter "label" is a null-terminated character string,
 * and "outputLen" is the number of bytes of output to produce.
 * The response should be delivered by the signal SEC_SIG_TLS_PRF_
 * RESPONSE. The parameter, "objectId", should be
 * passed back in this response.
 */
void 
SECif_tlsPrf (int source, int objectId, int masterSecretId,
              const unsigned char *secret, int secretLen,
              const char *label,
              const unsigned char *seed, int seedLen,
              int outputLen);

/*
 * Verify a chain of certificates.
 * The parameter "certificates" contains an array of "numCertificates"
 * element of the type sec_tls_asn1_certificate.
 *
 * The parameter "socketId" holds the socket that is being used
 * to establish the TLS connection. The application may use this
 * value to extract further information about the server
 * (network address, or domain name, for example). This in turn
 * can be used to enforce a security policy, e.g., requring that
 * the Common Name field of the server certificate contain
 * the correct domain name.
 *
 * The response should be delivered by the signal SEC_SIG_TLS_VERIFY_CERT_
 * CHAIN_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */
void 
SECif_tlsVerifyCertChain (int source, int objectId,
                          const unsigned char *addr, MSF_UINT16 addrLen, 
                          const unsigned char *domain, MSF_UINT16 domainLen,
                          sec_tls_asn1_certificate *certificates,
                          int numCertificates);

/*
 * Retrieve a client certificate.
 * The parameter "certificateTypes" contains a list of
 * the types of certificates requested, sorted in order of
 * the server's preference.
 * The array "certAuthorities", contains distinguished names
 * of acceptable certificate authorities.
 * The response should be delivered by the signal SEC_SIG_TLS_GET_CLIENT_
 * CERT_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */
void 
SECif_tlsGetClientCert (int source, int objectId, 
                        const unsigned char *certificateTypes,
                        int numCertificateTypes,
                        sec_tls_distinguished_name *certAuthorities,
                        int numCertAuthorities);
/*
 * Compute a digital signature.
 * The buffer, "data", contains the data to be signed, and
 * "pubKeyHash" contains a 20-byte SHA-1 hash of the public key
 * corresponding to the private key that should be used to
 * compute the signature. This latter value is the value passed back in
 * SEC_SIG_TLS_GET_CLIENT_CERT_RESPONSE.
 * The response should be delivered by the signal SEC_SIG_TLS_COMPUTE_
 * SIGNATURE_RESPONSE. The parameter, "objectId",
 * should be passed back in this response.
 */                                     
void 
SECif_tlsComputeSignature (int source, int objectId, 
                           const unsigned char *pubKeyHash,
                           const unsigned char *data, int dataLen);


/**************************************************
 * signText
 **************************************************/
/* The Internet browser must open a dialog, display the message to sign 
 * (according to law in many countries) and wait for the end-user to 
 * confirm. Then the data (which is a digest computed from the text) is 
 * encrypted using a private key and either RSA or ECDSA. The private key 
 * used must require user verification information, such as a PIN. 
 * The user verification information must be requested every time this 
 * function is called.
 * keyIdTypes: SEC_SIGN_NO_KEY, SEC_SIGN_SHA_KEY or SEC_SIGN_SHA_CA_KEY
 * keyId: Identifies the private key, based on the previous parameter
 * options : Contains two options joined with the bitwise OR operation. 
 * available options are SEC_SIGN_RETURN_HASHED_KEY, SEC_SIGN_RETURN_CERTIFICATE
 */
void 
SECif_signText (int source, int id, int signId, const char *text,
                const char *data, int dataLen,
                int keyIdType, const char *keyId, int keyIdLen,
                int options);

/**************************************************
 * CRYPT
 **************************************************/

/*
 * Called when a SSL/TLS/WTLS connection has been established.
 * The parameter 'connectionType' is one of SEC_CONNECTION_TYPE_SSL,
 * SEC_CONNECTION_TYPE_TLS, or SEC_CONNECTION_TYPE_WTLS.
 */
void
SECif_connectionEstablished (int source, int objectId, int socketId,
                             MSF_UINT8 connectionType,
                             int masterSecretId, 
                             sec_session_params sessionInfo);
/*
 * Called when a SSL/TLS/WTLS connection has been terminated.
 * The parameter 'connectionType' is one of SEC_CONNECTION_TYPE_SSL,
 * SEC_CONNECTION_TYPE_TLS, or SEC_CONNECTION_TYPE_WTLS.
 */
void
SECif_connectionTerminated (int source, int objectId, int socketId,
                            MSF_UINT8 connectionType);

/*
 * General assumptions about the handling of the session store:
 *
 * The master secret store should be maintained in parallell with
 * the session store. This means, that the same indexes or slot
 * numbers are used both in the master secret store and the session store.
 * New slots in the master secret store are selected by the
 * key exchange routine. If no empty slots are available, the
 * old slot to be evicted should be selected using the following
 * strategy: Select a slot where the session is
 *   1) NON-resumable and NOT active
 *   2) resumable and NOT active
 *   3) NON-resumable and active
 *   4) resumable and active
 *
 * Preferably, the size of the store should be large enough that
 * cases 3 and 4 are never used. This can be accomplished by giving
 * the store one slot more than the maximum number of simultaneous
 * SSL/TLS/WTLS connections. If there are two or more candidates from
 * the same category, they should be ranked according to creation
 * time. That is, the older slot will be reused first.
 *
 * After the key exchange routine has delivered a new master secret
 * index (mid) to SSL/TLS/WTLS, it is the responsibility of SSL/TLS/WTLS
 * to call the routines
 *     SECif_sessionInvalidate (mid);
 *     SECif_peerDeleteLinks (mid);
 *
 */
/*
 * Delete all peer entries that link to the indicated
 * master secret.
 */
void
SECif_peerDeleteLinks (int source, int masterSecretId);

/*
 * Add a peer entry that links to the given master secret.
 * If such an entry already exists, overwite it.
 * "connectionType" is one of SEC_CONNECTION_TYPE_SSL,
 * SEC_CONNECTION_TYPE_TLS, or SEC_CONNECTION_TYPE_WTLS.
 */
void
SECif_peerLinkToSession (int source, MSF_UINT8 connectionType,
                         const unsigned char *address, int addressLen,
                         const char *domain, MSF_UINT16 portnum,
                         int masterSecretId);

/*
 * Find a peer with matching address and port number.
 * If none exists, try matching just the address.
 * The result, a master secret ID, is returned in
 * the signal SEC_SIG_PEER_LOOKUP_RESPONSE.
 * "connectionType" is one of SEC_CONNECTION_TYPE_SSL,
 * SEC_CONNECTION_TYPE_TLS, or SEC_CONNECTION_TYPE_WTLS.
 */
void
SECif_peerLookup (int source, int id, MSF_UINT8 connectionType,
                  const unsigned char *address, int addressLen,
                  const char *domain, MSF_UINT16 portnum);
                   
/*
 * If "isActive" != 0, then mark the indicated session slot
 * as being "active". Otherwise, mark it as "not active".
 * A session slot that is "active", SHOULD NOT be reused.
 * TLS/WTLS will keep a session marked as "active" as long as
 * any connection that is based upon that session is active.
 */
void
SECif_sessionActive (int source, int masterSecretId, MSF_UINT8 isActive);

/*
 * Mark a session entry as non-resumable.
 */
void
SECif_sessionInvalidate (int source, int masterSecretId);

/*
 * Fetch the contents of the indicated session entry.
 * The result is returned in the signal SEC_SIG_SESSION_FETCH_RESPONSE.
 */
void
SECif_sessionFetch (int source, int id, int masterSecretId);
    
/*
 * Store new values for a session entry.
 */                        
void
SECif_sessionUpdate (int source, int masterSecretId, 
                     MSF_UINT8 sessionOptions,
                     const unsigned char *sessionId, 
                     MSF_UINT8 sessionIdLen,
                     MSF_UINT8 cipherSuite[2],
                     MSF_UINT8 compressionAlg,
                     const unsigned char *privateKeyId,
                     MSF_UINT32 creationTime);

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

/**************************************************
 * 
 **************************************************/

void *
sec_convert (MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

void
sec_destruct (MSF_UINT8 module, MSF_UINT16 signal, void *p);


#endif




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
 * sec_lib.h
 *
 * Created by Anna Andréasson, Thu Jun 20, 2002.
 *
 */

#ifndef _sec_lib_h
#define _sec_lib_h

#ifndef _sec_if_h
#include "sec_if.h" /* for sec_key_object etc*/
#endif

#ifndef _msf_def_h
#include "msf_def.h"
#endif

/*Attributes for issuer and subject*/
                                                  /***OID***/
#define SEC_COUNTRY_NAME              0x00000001   /*2 5 4 6*/   
#define SEC_ORGANISATION_NAME         0x00000002   /*2 5 4 10*/
#define SEC_ORGANISATIONAL_UNIT_NAME  0x00000004   /*2 5 4 11*/
#define SEC_STATE_OR_PROVINCE_NAME    0x00000008   /*2 5 4 8*/ 
#define SEC_COMMON_NAME               0x00000010   /*2 5 4 3*/  
#define SEC_DOMAIN_COMPONENT          0x00000020   /*0 9 2342 19200300 100 1 25*/
#define SEC_SERIAL_NUMBER             0x00000040   /*2 5 4 5*/

#define SEC_DN_QUALIFIER              0x00000080   /*2 5 4 46*/
#define SEC_LOCALITY_NAME             0x00000100   /*2 5 4 7*/                         
#define SEC_TITLE                     0x00000200   /*2 5 4 12*/
#define SEC_SURNAME                   0x00000400   /*2 5 4 4*/
#define SEC_GIVENNAME                 0x00000800   /*2 5 4 42*/
#define SEC_INITIALS                  0x00001000   /*2 5 4 43*/
#define SEC_GENERATION_QUALIFIER      0x00002000   /*2 5 4 44*/

#define SEC_NAME                      0x00004000   /*2 5 4 41*/
#define SEC_EMAIL_ADDRESS             0x00008000   /*1 2 840 113549 1 9 1*/

#define SEC_UNKNOWN_ATTRIBUTE_TYPE    0x00010000

/*Extensions*/
#define SEC_CERT_EXT_UNKNOWN                   0
#define SEC_CERT_EXT_DOMAIN_INFORMATION        1
#define SEC_CERT_EXT_KEY_USAGE                15 
#define SEC_CERT_EXT_EXTENDED_KEY_USAGE       37
#define SEC_CERT_EXT_CERTIFICATE_POLICIES     32
#define SEC_CERT_EXT_SUBJECT_ALT_NAME         17
#define SEC_CERT_EXT_BASIC_CONSTRAINTS        19
#define SEC_CERT_EXT_NAME_CONSTRAINTS         30
#define SEC_CERT_EXT_POLICY_CONSTRAINTS       36
#define SEC_CERT_EXT_AUTHORITY_KEY_IDENTIFIER 35
#define SEC_CERT_EXT_SUBJECT_KEY_IDENTIFIER   14


typedef struct sec_certificate_st
{
  MSF_UINT8 certificate_version;
  MSF_UINT32 valid_not_before;
  MSF_UINT32 valid_not_after;
  unsigned char *issuer;
  unsigned char *subject;
  unsigned char *signature;
  MSF_UINT16 signatureLen;
  union {
    struct {	/* WTLS*/
      MSF_UINT8 signature_algorithm;
      MSF_UINT8 issuerIdentifierType;
      MSF_UINT16 issuercharacterSet;
      MSF_UINT8 issuerLen;
      MSF_UINT8 subjectIdentifierType;
      MSF_UINT16 subjectcharacterSet;
      MSF_UINT8 subjectLen;
      MSF_UINT8 public_key_type;
      MSF_UINT8 parameter_index;
      MSF_UINT16 expLen;
      unsigned char *rsa_exponent;
      MSF_UINT16 modLen;
      unsigned char *rsa_modulus;	
    } wtls;
    struct {	/* X509*/
      unsigned char *serialNumber;	
      MSF_UINT16 serialNumberLen;
      unsigned char *signatureAlgId;
      MSF_UINT16 signatureAlgIdLen;
      MSF_UINT16 issuerLen;
      MSF_UINT16 subjectLen;
      unsigned char *publicKeyAlgId;
      MSF_UINT16 publicKeyAlgIdLen;
      unsigned char *publicKeyVal; 
      MSF_UINT16 publicKeyValLen;
      unsigned char *extensions; 
      MSF_UINT16 extensionsLen;
      unsigned char *signatureAlgorithm;
      MSF_UINT16 signatureAlgorithmLen;		
    } x509;
  } _u;
} sec_certificate_t;

typedef struct sec_name_attribute_st 
{
	MSF_UINT32 attributeType;
  MSF_INT16 attributeCharSet;
  unsigned char *attributeValue;
  MSF_UINT16 attributeValueLen;
} sec_name_attribute_t;

typedef struct sec_x509_rsa_mod_and_exp_st 
{
  unsigned char *rsa_modulus;
  MSF_UINT16 modLen;
  unsigned char *rsa_exponent;
  MSF_UINT16 expLen;
} sec_x509_rsa_mod_and_exp_t;

typedef struct sec_x509_dsa_params_st
{
  unsigned char *publicKey;
  MSF_UINT16 publicKeyLen;
  unsigned char *dsaParams;
  MSF_UINT16 dsaParamsLen;
} sec_x509_dsa_params_t;

typedef struct sec_x509_extension_st 
{
  int extnId; 
  int critical; 
  unsigned char *extnObjectId;
  MSF_UINT16 extnObjectIdLen;
  unsigned char *extnValue; 
  MSF_UINT16 extnValueLen;
} sec_x509_extension_t;

typedef struct sec_x509_key_usage_st 
{
  int digitalSignature; 
  int nonRepudiation;
  int keyEncipherment; 
  int dataEncipherment;
  int keyAgreement; 
  int keyCertSign;
  int cRLSign; 
  int encipherOnly;
  int decipherOnly;
} sec_x509_key_usage_t;

typedef struct sec_x509_extended_key_usage_st 
{
  int anyExtendedKeyUsage; 
  int serverAuth; 
  int clientAuth; 
  int codeSigning; 
  int emailProtection; 
  int timeStamping; 
  int OCSPSigning;
} sec_x509_extended_key_usage_t;

int SEClib_isInitialised(void);
int SEClib_initialise(void);
int SEClib_terminate(void);

int SEClib_encrypt(sec_cipher_alg cipherAlg, sec_key_object key,
                      const unsigned char *data, int dataLen, 
                      unsigned char *encryptedData);
int SEClib_decrypt(sec_cipher_alg cipherAlg, sec_key_object key,
                      const unsigned char *data, int dataLen,
                      unsigned char *decryptedData);


int SEClib_encryptInit(sec_cipher_alg cipherAlg, 
                          const unsigned char *key, int keyLen,
                          sec_cipher_handle *handleptr);
int SEClib_encryptUpdate(sec_cipher_handle handle,
                            const unsigned char *data, int dataLen,
                            unsigned char *encryptedData);
int SEClib_encryptFinal(sec_cipher_handle handle);


int SEClib_decryptInit(sec_cipher_alg cipherAlg,
                          const unsigned char *key, int keyLen,
                          sec_cipher_handle *handleptr);
int SEClib_decryptUpdate(sec_cipher_handle handle,
                            const unsigned char *data, int dataLen,
                            unsigned char *decryptedData);
int SEClib_decryptFinal(sec_cipher_handle handle);


int SEClib_hash (sec_hash_alg alg,
                    const unsigned char *data, int dataLen,
                    unsigned char *digest);
int SEClib_hashInit(sec_hash_alg alg, sec_hash_handle *handleptr);
int SEClib_hashUpdate(sec_hash_handle handle,
                         const unsigned char *part, int partLen);
int SEClib_hashFinal(sec_hash_handle handle, unsigned char *digest);


int SEClib_hmacInit(sec_hash_alg alg,
                        const unsigned char *key, int keyLen,
                        sec_hmac_handle *handleptr);
int SEClib_hmacUpdate(sec_hmac_handle handle,
                          const unsigned char *part, 
                          int partLen);
int SEClib_hmacFinal(sec_hmac_handle handle, unsigned char *digest);

int SEClib_parseCertificate (MSF_UINT8 format, 
                             const unsigned char *buf, MSF_UINT16 bufLen,
                             sec_certificate_t *parsed_cert);

int SEClib_parseNameAttributes (MSF_UINT8 modId, MSF_UINT8 format, 
                                const unsigned char *buf, MSF_UINT16 bufLen,
                                int *nbrAttributes,                                
                                sec_name_attribute_t *attributes);

int SEClib_parseX509RSAModAndExp (const unsigned char *buf, MSF_UINT16 bufLen,
                                  sec_x509_rsa_mod_and_exp_t* p);

int SEClib_parseX509DSAParams (const unsigned char *buf, MSF_UINT16 bufLen,
                               sec_x509_dsa_params_t* p);

int SEClib_parseX509Extensions (const unsigned char *buf, MSF_UINT16 bufLen,
                                int* numExt, sec_x509_extension_t* p);

int SEClib_parseX509KeyUsage (const unsigned char *buf, MSF_UINT16 bufLen, 
                              sec_x509_key_usage_t* p);

int SEClib_parseX509ExtendedKeyUsage (const unsigned char *buf, MSF_UINT16 bufLen, 
                                      sec_x509_extended_key_usage_t* p);

int SEClib_generateRandom (unsigned char *randomData, int randomLen);

int SEClib_sslHashUpdateWMasterSec(sec_hash_handle handle, int masterSecretId);


int SEClib_RSAEncryption(sec_pub_key_rsa key, 
                         const unsigned char *data, int dataLen, 
                         unsigned char *buf, int *bufLen);

int SEClib_verifyRSASignature(sec_pub_key_rsa key, sec_hash_alg hashalg,
                              unsigned char *msg, int msgLen, 
                              const	unsigned char *sig, int sigLen);

int SEClib_computeRSADigitalSignature(MSF_UINT8 alreadyHashed,
                                      unsigned char *key, int keyLen, 
                                      const unsigned char *buf, int bufLen, 
                                      unsigned char *sig, int *sigLen);

int SEClib_generateRSAKeyPair(unsigned char **pubkey, int *pubkeyLen, 
                              unsigned char **privkey, int *privkeyLen);


int SEClib_generateDSAKeyPair(unsigned char **pubkey, int *pubkeyLen, 
                              unsigned char **privkey, int *privkeyLen,
                              unsigned char **shrdPub, int *shrdPubLen);

int SEClib_computeDSADigitalSignature(MSF_UINT8 alreadyHashed,
                                      const unsigned char *key, int keyLen,
                                      const unsigned char *shrdPub, int shrdPubLen, 
                                      const unsigned char *buf, int bufLen, 
                                      unsigned char *sig, int *sigLen);

int SEClib_verifyDSASignature(const unsigned char *key, int keyLen,
                              const unsigned char *shrdPub, int shrdPubLen,
                              unsigned char *msg, int msgLen,
                              const	unsigned char *sig, int sigLen);
                                   
int SEClib_generateDHKeyPair(unsigned char *dhP, int dhP_len,
                             unsigned char *dhG, int dhG_len, 
                             unsigned char *dhYs, int dhYs_len, 
                             unsigned char **client_pubkey, int *client_pubkey_len,
                             unsigned char **shared_key, int *shared_key_len );
    

#endif

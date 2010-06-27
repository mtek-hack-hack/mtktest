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







#ifndef _sec_awim_h
#define _sec_awim_h

#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _sec_if_h
#include "sec_if.h"
#endif






extern MSF_UINT8 wim_initialised;

#define KEY_HASH_SIZE		20


#define SP_RSA        SEC_TLS_CERT_RSA_SIGN
#define SP_DHE_DSS    SEC_TLS_CERT_DSS_SIGN










#define SEC_ERR_WIM_NOT_INITIALISED                    101
#define SEC_ERR_IN_PROGRESS                            102
#define SEC_ERR_OLD_ROOTCERT_FOUND										 121











#define TLS_PROTOCOL_VERSION_MAJOR                3
#define TLS_PROTOCOL_VERSION_MINOR                1
#define SSL_PROTOCOL_VERSION_MINOR                0






void SECa_wimInitialise(int id);
void SECa_wimTerminate(void);
#ifdef SEC_CFG_WTLS
void SECa_wimGetMethods(int id, MSF_UINT8 onlyServerAuth);
#endif
#ifdef SEC_CFG_TLS
void SECa_wimGetCipherSuites(int id);
#endif



#ifdef SEC_CFG_WTLS
void SECa_wimWTLSkeyExchange(int id, sec_wtls_key_exch_params param,
                             MSF_UINT8 hashAlg, const unsigned char *randval);
#endif
#ifdef SEC_CFG_TLS
void SECa_wimTLSkeyExchange(int id, int keyExchangeAlgorithm, int is_ssl,
                            sec_tls_key_exch_params *params,
                            const unsigned char *certificate, 
                            MSF_UINT32 certificateLen,
                            const unsigned char *randval);
#endif
void SECa_wimPRF(int id, MSF_UINT8 alg, int masterSecretId,
                 const unsigned char *secret, int secretLen,
                 const char *label,
                 const unsigned char *seed, int seedLen, 
                 int outputLen, MSF_UINT8 connectionType);

#ifdef SEC_CFG_SSL
int SECa_wimHashUpdateWithMasterSecret (sec_hash_handle handle, 
                                        int masterSecretId);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimDeleteKeysAndUserCertsByType(int id, MSF_UINT8 keyType);
  void SECa_wimGenerateKeyPair(int id, MSF_UINT8 keyType, 
                               const char *pin, MSF_UINT8 alg);
#endif
 




void SECa_wimVerifyCertificateChain(int id, const unsigned char *buf, 
                                    int bufLen);
#ifdef SEC_CFG_TLS
void SECa_wimVerifyTLSCertificateChain(int id, sec_tls_asn1_certificate *certs, 
                                       int numCerts);
#endif
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
void SECa_wimVerifyUserCertificateChain(int id, const unsigned char *buf, 
                                        int bufLen);
void SECa_wimVerifyTlsUserCertificateChain(int id, sec_tls_asn1_certificate *certs, 
                                           int numCerts);
void SECa_wimVerifyRootCert(int id, const unsigned char *cert, 
                            MSF_UINT16 certLen);
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimSelfsignedCert(int id, const unsigned char *cert, 
                              MSF_UINT16 certLen);
  void SECa_wimCertAlreadyExists(int id, const unsigned char *cert, 
                                 MSF_UINT16 certLen, char certType);
  void SECa_wimStoreCert(int id, const unsigned char *cert, 
                         MSF_UINT16 certLen, char certType, 
  										   void *certFriendlyName, MSF_UINT16 friendlyNameLen, 
                         MSF_INT16 charSet, const unsigned char *certURL);
  void SECa_wimStoreUserCertData(int id, int userCertId, int userCertCount, 
                                 int privKeyId, int privKeyCount, MSF_UINT8 privKeyUsage,
		  												   MSF_UINT8 alg, const unsigned char *publicKeyHash, 
		  												   const unsigned char *caPublicKeyHash,
			  											   int URLCount, MSF_UINT8 publicKeyCert, 
				  										   int nameCount, MSF_INT8 nameType);
  void SECa_wimDeleteCertificate(int certificateId);
  void SECa_wimGetCertificate(int certificateId);
  void SECa_wimGetCertificateNames(int certOptions);
  void SECa_wimGetCertificateIds(int certOptions);
  void SECa_wimGetNbrCerts(int id, int certOptions);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimGetUserCertAndSignedKey(int certId);
  void SECa_wimGetUserCertNamesByType(MSF_UINT8 keyType);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimGetUserCertNames(const unsigned char *buf, int bufLen);
	void SECa_wimGetUserCertAndKeyId(int certificateId, MSF_UINT8 connectionType);
#endif
#ifdef SEC_CFG_TLS
	void SECa_wimGetTLSUserCertNames(const unsigned char *certificateTypes, 
                                   int numCertificateTypes,
                           			   sec_tls_distinguished_name *certAuthorities, 
                                   int numCertAuthorities);  
#endif
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimGetChainOfCertificates(MSF_UINT8 chainDepth, MSF_UINT32 *certChainIds);
#endif  
void SECa_wimReadViewsAndCerts(void);
void SECa_wimStoreViewsAndCerts(const unsigned char *data, 
                                  int data_len);






void SECa_wimPeerDeleteLinks (int masterSecretId);
void SECa_wimPeerLinkToSession (MSF_UINT8 connectionType,
                                const unsigned char *address, int addressLen,
                                MSF_UINT16 portnum, int masterSecretId);
void SECa_wimPeerLookup(int id, MSF_UINT8 connectionType,
                        const unsigned char *address, int addressLen,
                        MSF_UINT16 portnum);
void SECa_wimSessionActive (int masterSecretId, MSF_UINT8 isActive);
void SECa_wimSessionInvalidate (int masterSecretId);
void SECa_wimSessionClear (void);
void SECa_wimClearSessionSlot(int masterSecretId);
void SECa_wimSessionFetch (int id, int masterSecretId);
void SECa_wimSessionUpdate (int masterSecretId, MSF_UINT8 sessionOptions,
                            const unsigned char *sessionId, MSF_UINT8 sessionIdLen,
                            MSF_UINT8 cipherSuite[2], MSF_UINT8 compressionAlg,
                            const unsigned char *privateKeyId,
                            MSF_UINT32 creationTime);




void SECa_wimComputeSignature(int id, const unsigned char *keyId, int keyIdLen,
                              const unsigned char *buf, int bufLen, MSF_UINT8 alg);
void SECa_wimFindMatchingPrivateRsaKey(int id, sec_pub_key_rsa userPublicKey);
#ifdef SEC_CFG_DHE_DSS
  void SECa_wimFindMatchingPrivateDsaKey(int id, unsigned char *pubKey, MSF_UINT16 pubKeyLen,
                                         unsigned char *dsaParams, MSF_UINT16 dsaParamsLen);
#endif
#ifdef SEC_CFG_CAN_SIGN_TEXT
  void SECa_wimSignText(int objectId, int signId, const char *data, int dataLen, 
                        int certId, int options);  
  void SECa_wimGetSignTextMatches(int objectId, int signId, int keyIdType, 
                                  const char *keyId, int keyIdLen, int options);
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
	void SECa_wimGetContracts(int id);
	void SECa_wimStoreContract(int id, const char *contract,
                             const char *sig, MSF_UINT16 sigLen, MSF_UINT32 time);
	void SECa_wimDeleteContract(int contractId);
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && (defined(SEC_CFG_WTLS))) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimSignatureVerification(int id,const unsigned char *signedTrustedCAInfo, 
                                     MSF_UINT16 signedTrustedCAInfoLen);
#endif




#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECa_wimGetPinInfo(int id, MSF_UINT8 keyType);
  void SECa_wimVerifyPin(int id, MSF_UINT8 keyType, const char *pin);
  void SECa_wimChangePin(int id, MSF_UINT8 keyType, const char *oldPin, 
                         const char *newPin);
  #ifdef SEC_CFG_PUK
		void SECa_wimVerifyPuk(int id, const char *puk, MSF_UINT16 pukLen);
    void SECa_wimChangePinWithPuk(int id, MSF_UINT8 keyType, 
                                  const char *puk, MSF_UINT16 pukLen, 
										   					  const char *newPin);
  #endif
#endif

#endif


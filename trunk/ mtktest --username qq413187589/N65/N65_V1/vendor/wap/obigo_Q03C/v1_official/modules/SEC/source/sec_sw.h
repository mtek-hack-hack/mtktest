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







#ifndef _sec_sw_h
#define _sec_sw_h

#ifndef _sec_awim_h
#include "sec_awim.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif






#define SESSION_ID_LEN          32
#define PRIVATE_KEY_ID_LEN       4
#define ADDRESS_LEN             18
#define WTLS_MASTER_SECRET_LEN 	20
#define TLS_MASTER_SECRET_LEN 	48

#define SEC_CATEGORY 'S'								

#define SESSION_HEADER                'S'
#define PEER_HEADER                   'P'
#define CA_CERTIFICATE_HEADER         'C'
#define USER_CERTIFICATE_HEADER       'U'
#define HOMEMADE_CERTIFICATE_HEADER   'H'
#define DSA_SHARED_PARAMS_HEADER      'D'
#define LOCKED_CERTIFICATE_HEADER     'L'
#define PRIVATE_KEY_HEADER            'K'
#define USERCERT_PRIVKEY_INDEX_HEADER 'I'
#define VIEWS_INDEX_HEADER            'V'
#define NON_VERIFIED_CACERT_HEADER    'N'
#define PUK_HEADER                    'B'
#define CONTRACT_HEADER               'T'
#define CERT_EXT_HEADER               'X'

#define SEC_FILE_ROOT         "/sec" 
#define SEC_FILE_PATH         "/sec/storage"
#define SEC_FILENAME_PREFIX   "/sec/storage/S_"
#define SEC_INDEXFILE_NAME    "/sec/storage/S_0"

extern int nbrStoredFiles;		
extern int indexFileHandle;   


struct UserCertKeyPairRecord {			
	int ucertId;			
	int ucertCount;
	int pkeyId;				
	int pkeyCount;
	MSF_UINT8  keyUsage;
	MSF_UINT8 alg;					
	unsigned char   publicKeyHash[KEY_HASH_SIZE];
	unsigned char	 CApublicKeyHash[KEY_HASH_SIZE];
	char   signTextpublicKeyHash[KEY_HASH_SIZE];
	char	 signTextCApublicKeyHash[KEY_HASH_SIZE];
	int URLCount;
	MSF_UINT8 publicKeyCert;	
	int nameCount; 		    
	MSF_INT8 nameType;				
};






void SWWIMa_initialise(int id);
void SWWIMa_terminate(void);

#ifdef SEC_CFG_WTLS
void SWWIMa_getMethods(int id, MSF_UINT8 onlyServerAuth);
#endif

#ifdef SEC_CFG_TLS
void SWWIMa_getCipherSuites(int id);
#endif




 
#ifdef SEC_CFG_WTLS
void SWWIMa_WTLSkeyExchange(int id, sec_wtls_key_exch_params param,
                          MSF_UINT8 hashAlg, const unsigned char *randval);
#endif

#ifdef SEC_CFG_TLS
void SWWIMa_TLSkeyExchange(int id, int keyExchangeAlgorithm, int is_ssl, 
                           sec_tls_key_exch_params *params,
                  		 	   const unsigned char *certificate, 
                           MSF_UINT32 certificateLen,
                           const unsigned char *randval);
#endif

#ifdef SEC_CFG_SSL
int SWWIMa_hashUpdateWithMasterSecret (sec_hash_handle handle, int masterSecretId);
#endif

void SWWIMa_PRF(int id, MSF_UINT8 alg, int masterSecretId,
                const unsigned char *secret, int secretLen,
                const char *label,
                const unsigned char *seed, int seedLen, 
                int outputLen, MSF_UINT8 connectionType);

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SWWIMa_generateKeyPair(int id, MSF_UINT8 keyType, 
                              const char *pin, MSF_UINT8 alg);
  void SWWIMa_deleteKeysAndUserCertsByType(int id, MSF_UINT8 keyType);
#endif

void SWWIMa_computeSignature(int id, const unsigned char *keyId, int keyIdLen,
                             const unsigned char *buf, int bufLen, MSF_UINT8 alg);
void SWWIMa_findMatchingPrivateRsaKey(int id, sec_pub_key_rsa userPublicKey);

#ifdef SEC_CFG_DHE_DSS
  void SWWIMa_findMatchingPrivateDsaKey(int id, unsigned char *pubKey, MSF_UINT16 pubKeyLen,
                                        unsigned char *dsaParams, MSF_UINT16 dsaParamsLen);
#endif





void SWWIMa_verifyCertificateChain(int id, const unsigned char *buf, int bufLen);

#ifdef SEC_CFG_TLS
void SWWIMa_verifyTLSCertificateChain(int id, sec_tls_asn1_certificate *certs, int numCerts);
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
void SWWIMa_verifyUserCertificateChain(int id, const unsigned char *buf, int bufLen);
void SWWIMa_verifyTlsUserCertificateChain(int id, sec_tls_asn1_certificate *certs, 
                                          int numCerts);
void SWWIMa_verifyRootCert(int id, const unsigned char *cert, MSF_UINT16 certLen);
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SWWIMa_selfsignedCert(int id, const unsigned char *cert, MSF_UINT16 certLen);
  void SWWIMa_certAlreadyExists(int id, const unsigned char *cert, MSF_UINT16 certLen, char certType);
  void SWWIMa_storeCert(int id, const unsigned char *cert, MSF_UINT16 certLen, char certType, 
	  									  void *certFriendlyName, MSF_UINT16 friendlyNameLen, MSF_INT16 charSet,
		  								  const unsigned char *certURL);
  void SWWIMa_storeUserCertData(int id, int userCertId, int userCertCount, 
	  												  	int privKeyId, int privKeyCount, MSF_UINT8 privKeyUsage,
		  											  	MSF_UINT8 alg, const unsigned char *publicKeyHash, 
		  											  	const unsigned char *caPublicKeyHash,
			  										  	int URLCount, MSF_UINT8 publicKeyCert, 
				  									  	int nameCount, MSF_INT8 nameType);
  void SWWIMa_deleteCertificate(int certificateId);
  void SWWIMa_getCertificate(int certificateId);
  void SWWIMa_getCertificateNames(int certOptions);
  void SWWIMa_getCertificateIds(int certOptions);
  void SWWIMa_getNbrCerts(int id, int certOptions);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SWWIMa_getUserCertAndSignedKey(int certId);
  void SWWIMa_getUserCertNamesByType(MSF_UINT8 keyType);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SWWIMa_getUserCertNames(const unsigned char *buf, int bufLen);
	void SWWIMa_getUserCertAndKeyId(int certificateId, MSF_UINT8 connectionType);
#endif

#ifdef SEC_CFG_TLS
  void SWWIMa_getTLSUserCertNames(const unsigned char *certificateTypes, int numCertificateTypes,
                                  sec_tls_distinguished_name *certAuthorities, 
                                  int numCertAuthorities);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
void SWWIMa_getChainOfCertificates(MSF_UINT8 chainDepth, MSF_UINT32 *certChainIds);
#endif
  

void SWWIMa_readViewsAndCerts(void);
void SWWIMa_storeViewsAndCerts(const unsigned char *data, int data_len);

#ifdef SEC_CFG_CAN_SIGN_TEXT
  void SWWIMa_signText(int objectId, int signId, const char *data, int dataLen, 
                       int certId, int options);
  void SWWIMa_getSignTextMatches(int objectId, int signId, int keyIdType, 
                                 const char *keyId, int keyIdLen, int options);
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
	void SWWIMa_getContracts(int id);
	void SWWIMa_storeContract(int id, const char *contract,
                          const char *sig, MSF_UINT16 sigLen, MSF_UINT32 time);
	void SWWIMa_deleteContract(int contractId);
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && (defined(SEC_CFG_WTLS))) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SWWIMa_signatureVerification(int id, const unsigned char *signedTrustedCAInfo, 
                                    MSF_UINT16 signedTrustedCAInfoLen);
#endif





void SWWIMa_peerLookup(int id, MSF_UINT8 connectionType,
                       const unsigned char *address, int addrlen,
                       MSF_UINT16 portnum);
void SWWIMa_peerLinkToSession(MSF_UINT8 connectionType,
                              const unsigned char *address, int addressLen,
                              MSF_UINT16 portnum, int masterSecretId);
void SWWIMa_peerDeleteLinks(int masterSecretId);
void SWWIMa_sessionActive(int masterSecretId, MSF_UINT8 isActive);
void SWWIMa_sessionInvalidate(int masterSecretId);
void SWWIMa_sessionClear(void);
void SWWIMa_clearSessionSlot(int masterSecretId);
void SWWIMa_sessionFetch(int id, int masterSecretId);
void SWWIMa_sessionUpdate(int masterSecretId, MSF_UINT8 sessionOptions,
                          const unsigned char *sessionId, MSF_UINT8 sessionIdLen,
                          MSF_UINT8 cipherSuite[2], MSF_UINT8 compressionAlg,
                          const unsigned char *privateKeyId,
                          MSF_UINT32 creationTime);





#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SWWIMa_getPinInfo(int id, MSF_UINT8 keyType);
  void SWWIMa_verifyPin(int id, MSF_UINT8 keyType, const char *pin);
  void SWWIMa_changePin(int id, MSF_UINT8 keyType, const char *oldPin, 
                        const char *newPin);

  #ifdef SEC_CFG_PUK
    void SWWIMa_verifyPuk(int id, const char *puk, MSF_UINT16 pukLen);
    void SWWIMa_changePinWithPuk(int id, MSF_UINT8 keyType, 
                                 const char *puk, MSF_UINT16 pukLen, 
																 const char *newPin);
  #endif
    
#endif





MSF_UINT8 SWWIM_isInitialised(void);

int SWWIM_writeEncryptedDataToFile(int fileHandle, void *data, 
																	 MSF_INT32 pos, MSF_INT32 dataLen);
int SWWIM_readDecryptedDataFromFile(int fileHandle, unsigned char *decryptedData, 
																	  int pos, int dataLen);																		 
void SWWIM_getIndexFileParams(unsigned char *in_str, char *header, MSF_UINT32 *fileId, MSF_UINT32 *count);																 
void SWWIM_getFileName(MSF_UINT32 fileId, char **fileName);
int SWWIM_createFile(int *fileHandle, MSF_UINT32 *fileId);
int SWWIM_writeToIndexFile(char header, MSF_UINT32 file_id, MSF_UINT32 count);
int SWWIM_deleteFromIndexFile(int in_file_id);
int SWWIM_deleteFile(int fileId, char in_header);
int SWWIM_changeHeaderInIndexfile(int in_file_id, char to_header);

int SWWIM_getNumStoredFiles(void);
int SWWIM_getNumStoredRootCerts(void);
int SWWIM_getNbrOfUserCerts(void);
int SWWIM_getNbrOfDownloadedUserCerts(void);

MSF_INT32 SWWIM_verifyRootCert_withHeaderN(unsigned char *cert, MSF_UINT16 certLen);

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  int SWWIM_getCACertificateFriendlyName(unsigned char **certFriendlyName, MSF_UINT16 *friendlyNameLen,
                                         int file_id, int count,
                                         MSF_INT16 *charSet, MSF_INT8 *nameType);
#endif  

int SWWIM_getRootCert(int index, unsigned char **cert, MSF_UINT16 *certLen, MSF_UINT32 *fileId);
int SWWIM_getCACertId(int index);

int SWWIM_storeUserCertDataInVector(int userCertId, int userCertCount, 
															      int privKeyId, int privKeyCount, MSF_UINT8 privKeyUsage,
															      MSF_UINT8 alg, const unsigned char *publicKeyHash, 
															      const unsigned char *caPublicKeyHash, 
															      int URLCount, MSF_UINT8 publicKeyCert, 
															      int nameCount, MSF_INT8 nameType);
int SWWIM_deleteUserCertData(int userCertId);
void SWWIM_SaveUcertKeyIndex(void);
void SWWIM_ReadUcertKeyIndex (void);
void SWWIM_clearUcertKeyIndex(void);

int SWWIM_getPublicKeyHash(int certificateId, unsigned char **keyId, int *keyIdLen);
int SWWIM_getPrivKey(int index, MSF_UINT8 alg, unsigned char **key);

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  int SWWIM_storePrivKey(unsigned char *privkey, int privkeyLen, 
                         MSF_UINT8 keyType, const char *pin, 
                         MSF_UINT32 *file_id_out, MSF_UINT32 *count_out);
#endif
  
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  int SWWIM_storeRsaPubKey(unsigned char *pubkey, int pubkeyLen, 
                           MSF_UINT8 keyType, int file_id_k, int count_k);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
#ifdef SEC_CFG_DHE_DSS
  int SWWIM_storeDsaPubValues(unsigned char *pubkey, int pubkeyLen, 
                              unsigned char *shrdPub, int shrdPubLen, 
                              MSF_UINT8 keyType, int file_id_k, int count_k);
#endif
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  int SWWIM_verifyPin(MSF_UINT8 keyType, const char *pin);
  int SWWIM_writePin(int fileId, int pkeyCount, const char *newPin);
  int SWWIM_readPin(MSF_UINT8 keyType, char *storedPin);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  #ifdef SEC_CFG_PUK
    int SWWIM_readPuk(char **storedPin, MSF_UINT16 *storedPukLen);
    int SWWIM_verifyPuk(char *puk, MSF_UINT16 pukLen, 
                        char *storedPuk, MSF_UINT16 storedPukLen);
  #endif
#endif

void SWWIM_getKeyExchangeIds(unsigned char **keyExchangeIds, int *keyExIdLen);
int SWWIM_WTLSPRF( int masterSecretId,
                  const unsigned char *secret, int secretLen, 
                  const char *label, 
                  const unsigned char *seed, int seedLen, 
                  int outputLen, unsigned char *buf);
int SWWIM_TLSPRF(int masterSecretId,
                 const unsigned char *secret, int secretLen,
                 const char *label, 
                 const unsigned char *seed, int seedLen, 
                 int outputLen, unsigned char *buf);

int SWWIM_SSLPRF(int masterSecretId,
                 const unsigned char *secret, int secretLen, 
                 const unsigned char *seed, int seedLen, 
                 int outputLen, unsigned char *buf);

#ifdef SEC_CFG_TLS
int SWWIM_findRootCert(MSF_UINT16 certAut_nameLen, unsigned char *certAut_name);
int SWWIM_findSubjectToCAcert(unsigned char *certAut_name,
                              MSF_UINT16 *subjectLen, unsigned char **subject, MSF_UINT32* in_fileId);
#endif

#endif

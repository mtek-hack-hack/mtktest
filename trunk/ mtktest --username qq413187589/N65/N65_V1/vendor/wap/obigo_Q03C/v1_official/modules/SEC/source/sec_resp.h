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












#ifndef _sec_resp_h
#define _sec_resp_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _sec_if_h
#include "sec_if.h"
#endif

#ifndef _sec_ti_h
#include "sec_ti.h"
#endif
















#ifdef SEC_CFG_WTLS
void
sec_getMethodsResponse(int dst, int objectId, int result,
                       const unsigned char *cipherMethods,
                       int cipherMethodsLen,
                       const unsigned char *keyExchangeIds,
                       int keyExchangeIdsLen,
                       const unsigned char *trustedKeyIds,
                       int trustedKeyIdsLen);

void
sec_wtlsKeyExchangeResponse(int dst, int objectId, int result,
                            int masterSecretId,
                            const unsigned char *publicValue,
                            int publicValueLen);
void
sec_wtlsPrfResponse(int dst, int objectId, int result,
                    const unsigned char *buf, int bufLen);
void
sec_wtlsVerifyCertificateChainResponse(int dst, int objectId, int result);

void
sec_wtlsGetClientCertResponse(int dst, int objectId, int result,
                              const unsigned char *keyId, int keyIdLen,
                              const unsigned char *cert, int certLen);
void
sec_wtlsComputeSignatureResponse(int dst, int objectId, int result,
                                 const unsigned char *signature,
                                 int signatureLen);
#endif 

#ifdef SEC_CFG_TLS
void
sec_tlsGetCipherSuitesResponse(int dst, int objectId, int result,
                               const unsigned char *cipherSuites,
                               int cipherSuitesLen);
void
sec_tlsKeyExchangeResponse(int dst, int objectId, int result,
                           int masterSecretId,
                           const unsigned char *publicValue,
                           int publicValueLen);
void
sec_tlsPrfResponse(int dst, int objectId, int result,
                   const unsigned char *buf, int bufLen);
void
sec_tlsVerifyCertChainResponse(int dst, int id, int result);
void
sec_tlsGetClientCertResponse(int dst, int objectId, int result,
                             const unsigned char *pubKeyHash,
                             sec_tls_asn1_certificate *certificates,
                             int numCertificates);
void
sec_tlsComputeSignatureResponse(int dst, int objectId, int result,
                                const unsigned char *signature,
                                int signatureLen);
#endif 

#ifdef SEC_CFG_CAN_SIGN_TEXT 
void
sec_signTextResponse(int dst, int id, int signId, int algorithm,
                     const char *signature, int sigLen,
                     const char *hashedKey, int hashedKeyLen,
                     const char *certificate, int certificateLen,
                     int certificateType, int err);
#endif 

void
sec_peerLookupResponse(int dst, int id, int result,
                       MSF_UINT8 connection_type,
                       int master_secret_id,
                       MSF_INT32 security_id);
void
sec_sessionFetchResponse(int dst, int id, int result,
                         MSF_UINT8 sessionOptions,
                         const unsigned char *sessionId,
                         MSF_UINT8 sessionIdLen,
                         MSF_UINT8 cipherSuite[2],
                         MSF_UINT8 compressionAlg,
                         const unsigned char *privateKeyId,
                         MSF_UINT32 creationTime);

void
sec_generateRandomResponse (int dst, int id, unsigned char *randomData, int randomLen, 
															int result);
void
sec_hashResponse (int dst, int id, unsigned char *digest, int digestLen, int result);

void
sec_hashInitResponse (int dst, int id, sec_hash_handle handleptr, int result);

void
sec_hashUpdateResponse (int dst, int id, sec_hash_handle handle, int result);

void
sec_hashFinalResponse (int dst, int id, unsigned char *digest, int digestLen, int result);

void
sec_hmacInitResponse (int dst, int id, sec_hmac_handle handleptr, int result);

void
sec_hmacUpdateResponse (int dst, int id, sec_hmac_handle handle, int result);

void
sec_hmacFinalResponse (int dst, int id, unsigned char *digest, int digestLen, 
                         int result);

void
sec_encryptResponse (int dst, int id, unsigned char *encryptedData, int encryptedDataLen,
										 int result);

void
sec_decryptResponse (int dst, int id, unsigned char *decryptedData, int decryptedDataLen, 
											 int result);

void
sec_encryptInitResponse (int dst, int id, sec_cipher_handle handleptr, int result);

void
sec_encryptUpdateResponse (int dst, int id, sec_cipher_handle handle, unsigned char *encryptedData, 
														 int encryptedDataLen, int result);
void
sec_encryptFinalResponse (int dst, int id, int result);

void
sec_decryptInitResponse (int dst, int id, sec_cipher_handle *handleptr, int result);

void
sec_decryptUpdateResponse (int dst, int id, sec_cipher_handle handle, unsigned char *decryptedData, 
														 int decryptedDataLen, int result);

void
sec_decryptFinalResponse (int dst, int id, int result);






#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )

void
sec_storeCertResponse(int dst, int id, int result);

void
sec_trustedCAInfoResponse(int dst, int id, int result);

void 
sec_certDeliveryResponse(int dst, int id, int result);

void 
sec_viewCertNamesResponse(int dst, int id, int result);
void
sec_getCertIdsResponse(int dst, int id, int result, int nbrCerts,
                       MSF_UINT8 *certIds);
void 
sec_getNbrCertsResponse(int dst, int id, int result, int nbrCerts);

void
sec_verifyCertChainResponse(int dst, int id, int result, int format, 
                            unsigned char* rootCert, int rootLen);

#endif 


#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )

void 
sec_generateKeyPairResponse(int dst, int id, int result, MSF_UINT8 keyType, 
		  											const unsigned char *publicKey, int publicKeyLen, 
		  											const unsigned char *sig, int sigLen);

void 
sec_delKeysUserCertsByTypeResponse(int dst, int id, int result);

void 
sec_getUserPubKeyResponse(int dst, int id, int result, 
													const unsigned char *publicKey, int publicKeyLen,
													const unsigned char *sig, int sigLen);

void 
sec_changePinResponse(int dst, int id, int result);

#ifdef SEC_CFG_PUK

void 
sec_verifyPukResponse(int dst, int id, int result);

#endif 
#endif 

void 
sec_viewCurrentCertResponse(int dst, int objectId, int result);

void 
sec_viewSessionInfoResponse(int dst, int objectId, int result);

void 
sec_getCurrentCertResponse(int dst, int objectId, int result, 
                           unsigned char* cert);

void 
sec_getSessionInfoResponse(int dst, int objectId, int result, 
                           sec_session_info_t *sessInf);

void 
sec_currentSecClassResponse(int dst, int id, int sec_class, int info_available,
                            int cert_available);

void 
sec_sessionClearResponse(int dst, int id, int result);

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))

void 
sec_viewContractsResponse(int dst, int id, int result);

void 
sec_getContractsResponse(int dst, int id, int result, 
                         MSF_UINT16 nbrContracts, 
                         sec_contract_info_t* contracts);

#endif 


#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT))

void 
sec_viewAndGetCertResponse(int dst, int id, int result,
                        int certId, unsigned char *cert, int certLen);
void 
sec_deleteCertResponse(int dst, int id, int certId, int result);

void 
sec_getCertResponse(int dst, int id, int result, int certId, 
                    unsigned char *cert, int certLen,
                    unsigned char *trustedUsage, int trustedUsageLen);

#endif 

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))

void 
sec_deleteContractResponse(int dst, int id, int result);

#endif 


#endif

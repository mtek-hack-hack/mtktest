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







#ifndef _sec_cwim_h
#define _sec_cwim_h

#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h" 
#endif




void SECc_wimInitialiseResponse (int id, int result);
#ifdef SEC_CFG_WTLS
void SECc_wimGetMethodsResponse (int id, int result,
   															 const unsigned char *cipherMethods,
															   int cipherMethodsLen,
															   const unsigned char *keyExchangeIds,
															   int keyExchangeIdsLen,
															   const unsigned char *trustedKeyIds,
															   int trustedKeyIdsLen);
#endif
#ifdef SEC_CFG_TLS
void SECc_wimGetCipherSuitesResponse(int id, int result,
                              		   unsigned char *cipherSuites,
                              		   int cipherSuitesLen);
#endif															



void SECc_wimKeyExchangeResponse (int id, int result, int masterSecretId,
                                  const unsigned char *publicValue,
                                  int publicValueLen);
void SECc_wimPRFResponse (int id, int result,
                          const unsigned char *buf, int bufLen);
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECc_wimGenerateKeyPairResponse(int id, int result, MSF_UINT8 keyType, 
                                       const unsigned char *publicKey, int publicKeyLen,
                                       const unsigned char *sig, int sigLen);
  void SECc_wimDeleteKeysAndUserCertsByTypeResponse(int id, int result);
#endif




void SECc_wimVerifyCertificateChainResponse(int id, int result, 
                                            MSF_UINT16 keyExchKeyLen, 
                                            int certTooOld, int certTooOldId);
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
void SECc_wimVerifyUserCertificateChainResponse(int id, int result, MSF_UINT8 alg,
                                                unsigned char *caCert, MSF_UINT16 caCertLen, 
                                                int rootCertTooOld, int rootCertTooOldId);
void SECc_wimVerifyRootCertResponse(int id, int result);
#endif
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECc_wimSelfsignedCertResponse(int id, int result, MSF_UINT8 selfsigned);
  void SECc_wimCertAlreadyExistsResponse(int id, int result, MSF_UINT8 exists, 
	  						   											 MSF_UINT32 new_valid_not_before, 
                                         MSF_UINT32 new_valid_not_after,
		  																   MSF_UINT32 old_valid_not_before, 
                                         MSF_UINT32 old_valid_not_after,
			  															   int certificateId);
  void SECc_wimStoreCertResponse(int id, int result, int certId, 
                                 MSF_UINT32 certCount, int URLCount, 
                                 int nameCount);
  void SECc_wimStoreUserCertDataResponse(int id, int result);
  void SECc_wimDeleteCertificateResponse(int certificateId, int result);
  void SECc_wimGetCertificateResponse(int result, unsigned char *cert, 
                                      MSF_UINT16 certLen,
                                      unsigned char *trustedUsage, 
                                      MSF_UINT16 trustedUsageLen);
  void SECc_wimCertificateNamesResponse(int result, int numberOfCertificates,
																	      const void *const *certificateFriendlyNames, 
																	      MSF_UINT16 *friendlyNameLen, MSF_INT16 *charSet, 
                                        MSF_INT8 *nameType, const int *certificateIds);
  void SECc_wimGetCertificateIdsResponse(int result, int nbrOfCerts, 
                                         const int *certificateIds);
  void SECc_wimGetNbrCertsResponse(int id, int result, int nbrCerts);
#endif

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECc_wimGetUserCertAndSignedKeyResponse(int result, 
                                               const unsigned char *cert, 
                                               MSF_UINT16 certLen,
		  																			   const unsigned char *sig, 
                                               int sigLen, MSF_UINT8 alg);
  void SECc_wimGetUserCertNamesByTypeResponse(int result, int numberOfCertificates, 
	  						   													  const void *const *certificateFriendlyNames, 
	  																			    MSF_UINT16 *friendlyNameLen, 
                                              MSF_INT16 *charSet, MSF_INT8 *nameType,
		  																		    const int *certificateIds);
  void SECc_wimGetUserCertNamesResponse(int result, int numberOfCertificates, 
			  														    const void *const *certificateFriendlyNames, 
			  														    MSF_UINT16 *friendlyNameLen, MSF_INT16 *charSet, 
                                        MSF_INT8 *nameType, const int *certificateIds,
                                        MSF_INT8 *chainDepth, MSF_UINT32 **certChainIds);
  




  void SECc_wimGetUserCertAndKeyIdResponse(int result, 
                                           unsigned char *cert, int certLen, 
                                           unsigned char *keyId, int keyIdLen);
#endif
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECc_wimGetChainOfCertificatesResponse(int result, int nbrOfCerts, unsigned char **certs, MSF_UINT16 *certLens);
#endif
  
void SECc_wimReadViewsAndCertsResponse( int result, 
                                       const unsigned char *data, 
                                       int len);





void SECc_wimPeerDeleteLinksResponse (int result);
void SECc_wimPeerLinkToSessionResponse (int result);
void SECc_wimPeerLookupResponse (int id, int result, MSF_UINT8 connectionType, 
                                 int masterSecretId, int deletedIndex);
void SECc_wimSessionActiveResponse (int result);
void SECc_wimSessionInvalidateResponse (int result);
void SECc_wimSessionClearResponse (int result);
void SECc_wimSessionFetchResponse (int id, int result, MSF_UINT8 sessionOptions,
                                   const unsigned char *sessionId,
                                   MSF_UINT8 sessionIdLen, MSF_UINT8 cipherSuite[2],
                                   MSF_UINT8 compressionAlg,
                                   const unsigned char *privateKeyId,
                                   MSF_UINT32 creationTime);
void SECc_wimSessionUpdateResponse (int result);




void SECc_wimComputeSignatureResponse(int id, int result, 
                                      const unsigned char *sig, int sigLen);
void SECc_wimFindMatchingPrivateKeyResponse(int id, int result, MSF_UINT32 keyId, 
							   													  int keyCount, MSF_UINT8 keyUsage);

#ifdef SEC_CFG_CAN_SIGN_TEXT
  void SECc_wimTextSigned(int objectId, int signId, int algorithm, 
                          const char *signature, int sigLen, 
  										    const char *hashedKey, int hashedKeyLen,
  										    const char *certificate, int certificateLen, 
  										    int certificateType, int err);
  void SECc_wimGetSignTextMatchesResponse(int objectId, int signId, 
                                          int result, int nbrMatches, 
                                          const void *const *friendlyNames, 
                                          MSF_UINT16 *friendlyNamesLen,
                                          MSF_INT16 *charSet, 
                                          MSF_INT8 *nameType, int *certIds);
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
  void SECc_wimGetContractsResponse(int id, int result, int nbrContracts,
                                    const char *const *contracts,
                                    const char *const *signatures, 
                                    MSF_UINT16 *signaturesLen,
                                    MSF_UINT32 *time, int *contractIds);
	void SECc_wimStoreContractResponse(int id, int result);
	void SECc_wimDeleteContractResponse(int contractId, int result);
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && (defined(SEC_CFG_WTLS))) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECc_wimSignatureVerificationResponse(int id, int result);
#endif




#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void SECc_wimGetPinInfoResponse(int id, int result);
  void SECc_wimVerifyPinResponse(int id, int result);
  void SECc_wimChangePinResponse(int id, int result);
  #ifdef SEC_CFG_PUK
    void SECc_wimVerifyPukResponse(int id, int result);
    void SECc_wimChangePinWithPukResponse(int id, int result);
  #endif
#endif


#endif

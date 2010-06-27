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







#ifndef _sec_cert_h
#define _sec_cert_h

#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h" 
#endif
#ifndef _sec_if_h
#include "sec_if.h" 
#endif  

void sec_cert_globalVarInitialise(void);
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  void sec_runStoreUserCert(int source, int id, 
                            unsigned char *cert, MSF_UINT16 certLen, 
                            const unsigned char *URL);
  void sec_runStoreCACert(int source, int id, 
                          unsigned char *cert, MSF_UINT16 certLen);
	void sec_runHashVerification(int source, int id,
                               unsigned char *trustedCAInfoStruct, 
														   MSF_UINT16 trustedCAInfoStructLen);
  void sec_runGetNbrCerts(int source, int id, int certOptions);
  void sec_runVerifyCertChain (sec_verify_cert_chain_t *params);
  void sec_runGetCertNames(int source, int id, int certOptions);
  void sec_runGetCertIds(int source, int id, int certOptions);
  void sec_runGetCert(int source, int id, int certId, int options);
  void sec_runDeleteCert(int source, int id, int certId);
  void sec_runSignatureVerification(int source, int id,
                                    unsigned char *trustedCAInfoStruct, 
                                    MSF_UINT16 trustedCAInfoStructLen);
  void sec_runCertDelivery(int source, int id, 
                           unsigned char *certResponse);
  int sec_runVerifyHash(MSF_INT16 characterSet, 
                        void *displayName, int displayNameLen,
                        unsigned char *trustedCAInfoStruct, 
                        MSF_UINT16 trustedCAInfoStructLen);
#endif
 
int sec_getPublicKeyRSA(unsigned char *cert, sec_pub_key_rsa *pubKey);
int sec_runOldRootCertHandling(int tooOldRootCertId);
#ifdef SEC_CFG_DHE_DSS
int sec_getPublicKeyDSA(unsigned char *cert, 
                        unsigned char **publicKey, MSF_UINT16 *publicKeyLen,
												unsigned char **dsaParams, MSF_UINT16 *dsaParamsLen);
#endif
int sec_getCertItemsForTi(unsigned char *cert, MSF_INT16 *issuercharSet, 
                            void **in_issuer, int *in_issuerLen, 
                            MSF_INT16 *subjectcharSet, 
                            void **in_subject, int *in_subjectLen, 
                            MSF_UINT32 *valid_not_before, 
                            MSF_UINT32 *valid_not_after,
                            unsigned char *fingerprint, int *fingerprintLen);

#endif 



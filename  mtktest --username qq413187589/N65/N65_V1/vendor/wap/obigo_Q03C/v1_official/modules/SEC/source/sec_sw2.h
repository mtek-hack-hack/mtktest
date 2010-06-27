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







#ifndef _sec_sw2_h
#define _sec_sw2_h

#ifndef _sec_if_h
#include "sec_if.h"  
#endif
#ifndef _msf_def_h
#include "sec_def.h"
#endif
#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif

void SWWIM_HMAC_hash(unsigned char *K, int KLen, 
                     unsigned char *data, int dataLen, int *result, 
                     unsigned char *buf);
void SWWIM_HMAC_MD5(unsigned char *K, int KLen, 
                     unsigned char *data, int dataLen, int *result, 
                     unsigned char *buf);
void SWWIM_P_hash(unsigned char *secret, int secretLen, 
                  unsigned char *seed, int seedLen, int *result, 
                  unsigned char *buf, int desiredLen);
void SWWIM_P_MD5(unsigned char *secret, int secretLen, 
                  unsigned char *seed, int seedLen, int *result, 
                  unsigned char *buf, int desiredLen);
int SWWIM_getUnpaddedLength(unsigned char *decryptedData, int dataLen);
int SWWIM_getPaddedLength(int dataLen);
MSF_UINT32 SWWIM_32bitMixFunction(MSF_UINT32 key);
MSF_UINT8 SWWIM_dexorsh(MSF_UINT8 val, MSF_UINT16 n);
MSF_UINT8 SWWIM_deaddsh(MSF_UINT8 val, MSF_UINT16 n);
MSF_UINT8 SWWIM_descmvl(MSF_UINT8 val, MSF_UINT16 parl, MSF_UINT16 parr);
int SWWIM_mixData(unsigned char *data, int dataLen, unsigned char **mixedData);
int SWWIM_unmixData(unsigned char *mixedData, int dataLen, unsigned char **unmixedData);
void SWWIM_getIntoStruct(unsigned char *vec, int len, unsigned char *tmpVec);
int SWWIM_getX509Subject(unsigned char *x509Cert, unsigned char **subject, MSF_UINT16 *subjectLen);
int SWWIM_getX509RsaPublicKey(unsigned char *x509Cert, MSF_UINT16 *expLen, unsigned char** exponent,
													    MSF_UINT16 *modLen, unsigned char** modulus);
int SWWIM_getSubjectKeyId(unsigned char *cert, unsigned char **keyId, int *keyIdLen);
int SWWIM_convertPublicRsaKey(sec_pub_key_rsa key, unsigned char **pubKey, MSF_UINT16 *outPubKeyLen);
int SWWIM_getPublicRsaKey(unsigned char *cert, sec_pub_key_rsa *pubKey);
#ifdef SEC_CFG_DHE_DSS
  int SWWIM_getPublicDsaKey(unsigned char *cert, 
                            unsigned char **outPubKey, MSF_UINT16 *outPubKeyLen, 
                            unsigned char **dsaParams, MSF_UINT16 *dsaParamsLen);
#endif
int SWWIM_verifyWTLSCertificate(sec_pub_key_rsa key, const unsigned char *cert);
int SWWIM_verifyX509Certificate(unsigned char *publicKeyVal, const unsigned char *cert, 
																MSF_UINT8 connectionType,
                                MSF_UINT8 chainDepth,
                                MSF_UINT8 certUsage);
int SWWIM_checkCertificateChainFormat(const unsigned char *chain, int chainLen, 
                                      sec_tls_asn1_certificate *certs, 
                                      MSF_UINT8 *numCerts);

#endif

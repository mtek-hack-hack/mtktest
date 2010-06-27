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







#ifndef _sec_ifim_h
#define _sec_ifim_h

#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _sec_if_h 
#include "sec_if.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif






#ifdef SEC_CFG_WTLS
void sec_runWtlsGetMethods (int source, int objectId);
void sec_runWtlsKeyExchange (int source, int objectId, 
                             sec_wtls_key_exch_params param, 
                             MSF_UINT8 hashAlg, 
                             const unsigned char *randval);
void sec_runWtlsPrf (int source, int objectId, MSF_UINT8 alg, 
                     int masterSecretId,
                     const unsigned char *secret, int secretLen,
                     const char *label,
                     const unsigned char *seed, int seedLen,
                     int outputLen);
void sec_runWtlsVerifyCertChain (int source, int objectId,
                                 const unsigned char *buf, int bufLen,
                                 const unsigned char *addr, int addrLen,
                                 const char *domain, int domainLen);
#ifdef SEC_CFG_WTLS_CLASS_3
void sec_runWtlsGetClientCert (int source, int objectId, 
                               const unsigned char *buf, int bufLen);
void sec_runWtlsComputeSignature (int source, int objectId,
                                  const unsigned char *keyId, int keyIdLen,
                                  const unsigned char *buf, int bufLen);
#endif 
#endif 





#ifdef SEC_CFG_TLS

void sec_runTlsGetCipherSuites (int source, int objectId);

void sec_runTlsKeyExchange (int source, int objectId, 
                            int keyExchangeAlgorithm, int is_ssl, 
                            sec_tls_key_exch_params *params,
                            const unsigned char *certificate, 
                            MSF_UINT32 certificateLen,
                            const unsigned char *randval);

void sec_runTlsPrf (int source, int objectId, int masterSecretId,
										const unsigned char *secret, int secretLen,
										const char *label,
										const unsigned char *seed, int seedLen,
										int outputLen);
                      
void sec_runTlsVerifyCertChain (int source, int objectId,
                                unsigned char *addr, MSF_UINT16 addrLen, 
                                unsigned char *domain, MSF_UINT16 domainLen,
										            sec_tls_asn1_certificate *certificates,
														    int numCertificates);
void sec_runTlsGetClientCert (int source, int objectId,
						                  const unsigned char *certificateTypes,
									            int numCertificateTypes,
												      sec_tls_distinguished_name *certAuthorities,
															int numCertAuthorities);
void sec_runTlsComputeSignature (int source, int objectId, 
                                 const unsigned char *pubKeyHash,
								                 const unsigned char *data, int dataLen,
                                 int alg);
#endif 





void sec_runConnectionEstablished (sec_connection_established_t *p);
void sec_runConnectionTerminated (int objectId, int securityId, MSF_UINT8 connectionType);


void sec_runPeerDeleteLinks (int masterSecretId);
void sec_runPeerLinkToSession (MSF_UINT8 connectionType,
								               const unsigned char *address, int addressLen,
											         MSF_UINT16 portnum,
														   int masterSecretId);
void sec_runPeerLookup (int source, int id, MSF_UINT8 connectionType,
								        const unsigned char *address, int addressLen,
											  MSF_UINT16 portnum);

void sec_runSessionActive (int masterSecretId, MSF_UINT8 isActive);
void sec_runSessionInvalidate (int masterSecretId);
void sec_runSessionFetch (int source, int id, int masterSecretId);
void sec_runSessionUpdate (int masterSecretId, MSF_UINT8 sessionOptions,
								           unsigned char *sessionId, 
											     MSF_UINT8 sessionIdLen,
													 MSF_UINT8 cipherSuite[2],
													 MSF_UINT8 compressionAlg,
													 unsigned char *privateKeyId,
													 MSF_UINT32 creationTime);
#endif 

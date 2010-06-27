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











#ifndef _sec_wtls_h
#define _sec_wtls_h

#ifndef _sec_lib_h
#include "sec_lib.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif

int 
SEC_wtlsCheckLengthAndFormat(const unsigned char *wtlscert, MSF_UINT16 *certLen);

int 
SEC_wtlsParse(const unsigned char *wtlscert, 
              MSF_UINT16 *certLen, sec_certificate_t *sp_cert);

int 
SEC_wtlsGetVersion(const unsigned char *wtlscert, MSF_UINT8 *ver);

int 
SEC_wtlsGetSignatureAlgorithm(const unsigned char *wtlscert, MSF_UINT8 *signAlg);

int 
SEC_wtlsGetIssuer(const unsigned char *wtlscert, MSF_UINT8  *issuerIdentifierType,
                  MSF_UINT16 *issuercharacterSet, 
                  MSF_UINT8  *issuerLen, unsigned char  **issuer);

int 
SEC_wtlsGetIssuerAttributes(MSF_UINT8 modId, const unsigned char *issuer, 
                            MSF_UINT16 issuerLen, 
                            MSF_UINT8 *nbrIssuerAttributes,                                
                            sec_name_attribute_t *issuerA);

int 
SEC_wtlsGetValidity(const unsigned char *wtlscert,
                    MSF_UINT32 *valid_not_before, MSF_UINT32 *valid_not_after);

int 
SEC_wtlsGetSubject(const unsigned char *wtlscert,
                   MSF_UINT8 *subjectIdentifierType,
                   MSF_UINT16 *subjectcharacterSet,
                   MSF_UINT8 *subjectLen, unsigned char **subject);

int 
SEC_wtlsGetPublicKeyType(const unsigned char *wtlscert, MSF_UINT8 *public_key_type);

int 
SEC_wtlsGetParameterSpecifier(const unsigned char *wtlscert, 
                              MSF_UINT8 *parameter_index);

int 
SEC_wtlsGetPublicKey(const unsigned char *wtlscert,
                     MSF_UINT16 *expLen, unsigned char** rsa_exponent,
                     MSF_UINT16 *modLen, unsigned char** rsa_modulus);

int 
SEC_wtlsGetSignature(const unsigned char *wtlscert,
                     unsigned char **signature, MSF_UINT16 *signatureLen);


int 
SEC_wtlsComposeCert(unsigned char **cert, MSF_UINT16 *certLen, 
                    unsigned char *pubkey, MSF_UINT16 pubkeyLen);







#endif

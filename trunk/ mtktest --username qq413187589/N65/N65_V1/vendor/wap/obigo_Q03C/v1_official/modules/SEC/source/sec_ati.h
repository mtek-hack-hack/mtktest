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







#ifndef _sec_ati_h
#define _sec_ati_h

#ifndef _sec_if_h
#include "sec_if.h"
#endif
#ifndef _sec_ti_h
#include "sec_ti.h"
#endif
#ifndef _msf_wid_h
#include "msf_wid.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"    
#endif
#ifndef _msf_core_h
#include "msf_core.h"    
#endif







typedef enum
{
	SEC_TI_OK,
	SEC_TI_CANCEL,
	SEC_TI_PIN_LOCKED,
	SEC_TI_PIN_FALSE,
	SEC_TI_HASH_FALSE,
	SEC_TI_OTHER_ERROR,
	SEC_TI_PIN_TOO_LONG,
	SEC_TI_PIN_TOO_SHORT,
	SEC_TI_WRONG_PUK,
	SEC_TI_MISSING_PUK
} sec_ti_return_val_t;






void
SECa_tiInitialise(void);

void
SECa_tiTerminate(void);


#ifdef SEC_CFG_USE_CERT
void 
SECa_tiShowCertNames(int nbrOfCerts, sec_cert_name_t *certNames);

void 
SECa_tiStoreCertDialog(MSF_INT16 issuerCharSet, void *issuer, int issuerLen, 
                       MSF_UINT32 validNotBefore, MSF_UINT32 validNotAfter, 
                       MSF_INT16 subjectCharSet, 
                       void *subject, int subjectLen, char certType);
#endif

#ifdef SEC_CFG_USE_KEYS
void 
SECa_tiChooseCertByName(int title, int nbrOfCerts, 
                        sec_cert_name_t *certNames);
#endif



void 
SECa_tiConfirmDialog(int msg, int yesMsg, int noMsg);



#ifdef SEC_CFG_CAN_SIGN_TEXT
void 
SECa_tiExtConfirmDialog(int msg, const char *text, 
                        int yesMsg, int noMsg);
#endif

#ifdef SEC_CFG_USE_CERT
void 
SECa_tiShowCert(int certId, MSF_INT16 issuerCharSet, 
                void *issuer, int issuerLen,
                MSF_UINT32 validNotBefore, MSF_UINT32 validNotAfter, 
                MSF_INT16 subjectCharSet, void *subject, int subjectLen,
                unsigned char *fingerprint, int fingerprintLen,
                int cancelStr);
#endif




void 
SECa_tiShowSessionInfo(sec_session_info_t sessInf);

#ifdef SEC_CFG_SHOW_WARNINGS



void 
SECa_tiWarningDialog(int msg);
#endif

#if((defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT))
void 
SECa_tiGeneratePin(MSF_UINT8 keyType);

void 
SECa_tiChangePinDialog(MSF_UINT8 keyType);

void 
SECa_tiChangePinResponse(sec_ti_return_val_t result);
  
void 
SECa_tiPinDialog(sec_pin_cause_t pinCause);
  
void 
SECa_tiVerifyPinResponse(sec_ti_return_val_t result);
  
void 
SECa_tiAllowDelKeys(MSF_UINT8 keyType);
#endif

#ifdef SEC_CFG_USE_CERT
void 
SECa_tiVerifyHashResponse(sec_ti_return_val_t result);

void 
SECa_tiHashDialog(MSF_INT16 charSet, void *displayName, int displayNameLen);


void 
SECa_tiConfirmDispName(MSF_INT16 charSet, 
                       void *displayName, int displayNameLen, 
                       int msg, int yesMsg, int noMsg);
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))




void 
SECa_tiShowStoredContracts(int nbrContracts, sec_contract_info_t *contracts);
#endif






void
sec_handleWidgetAction (msf_widget_action_t *p);

#ifdef SEC_CFG_SHOW_WARNINGS
void
sec_handleWidgetNotify(msf_widget_notify_t *p);
#endif 

#endif

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







#ifndef _sec_cti_h
#define _sec_cti_h

#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _sec_ati_h
#include "sec_ati.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"    
#endif


#ifdef SEC_CFG_USE_KEYS
void 
SECc_tiChooseCertByNameResponse(int certId, sec_ti_return_val_t result);
#endif

#ifdef SEC_CFG_USE_CERT
void 
SECc_tiStoreCertDialogResponse(MSF_UINT8 answer, 
                               void *friendlyName, 
                               MSF_UINT16 friendlyNameLen, 
                               MSF_INT16 charSet);
#endif

void 
SECc_tiConfirmDialogResponse(MSF_UINT8 answer);

#ifdef SEC_CFG_CAN_SIGN_TEXT
void 
SECc_tiExtConfirmDialogResponse(MSF_UINT8 answer);
#endif

#ifdef SEC_CFG_USE_KEYS
void 
SECc_tiGeneratePinResponse(sec_ti_return_val_t result, const char *pin);

void 
SECc_tiChangePinDialogResponse(sec_ti_return_val_t result);

void 
SECc_tiChangePin(MSF_UINT8 keyType, const char *oldPin, const char *newPin);

void 
SECc_tiPinDialogResponse(sec_ti_return_val_t result);

void 
SECc_tiVerifyPin(MSF_UINT8 keyType, const char *pin);

void 
SECc_tiAllowDelKeysResponse(sec_ti_return_val_t result);
#endif

#ifdef SEC_CFG_USE_CERT
void 
SECc_tiVerifyHash(MSF_UINT8 *hash);

void 
SECc_tiHashDialogResponse(sec_ti_return_val_t result);
#endif

void 
SECc_tiConfirmDispNameResponse(MSF_UINT8 answer);


#endif

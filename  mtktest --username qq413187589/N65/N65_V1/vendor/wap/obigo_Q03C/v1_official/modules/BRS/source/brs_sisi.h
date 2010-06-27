/*
 * Copyright (C) Obigo AB, 2002-2007.
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
























































































#ifndef _brs_sisi_h
#define _brs_sisi_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_sire.h"
#include "brs_siop.h"
#ifdef BRS_CONFIG_WMLS_CRYPTO
#include "brs_sicr.h"
#endif

typedef enum { 
  SI_RETURN_DONE,          
  SI_RETURN_MORE,          
  SI_RETURN_EXTERNAL,      


  SI_RETURN_EXTERNAL_NO_PARAMS    



} brs_si_enumSIReturn;

typedef struct {
  int        islibCall;  

  brs_si_ops_t *argOpS;     

  int        libNbr;
  int        libFuncIndex;
  char      *bpUrl;      
  char      *funcName;   
} brs_si_return_params_t;

typedef struct {
  void   *ua;       

  int     object_id; 

  brs_si_re_t  *RE;
  char     *baseURL;
  char     *refererURL; 

  int       timeSlice;
  MSF_UINT16    currTime;
  int       inWaitState;  

  brs_si_enumSIReturn returnInfo;
  brs_si_return_params_t *returnParams;
  int                 WMLBrowserActionInvoked; 
  int                 WMLBrowser_prev;         


  char               *WMLBrowser_goURL;  


#ifdef BRS_CONFIG_WMLS_CRYPTO
  int                        sign_id;
  brs_wmls_signed_content_t *sc; 


#endif
} brs_si_si_t;



























brs_si_si_t *
brs_si_NewWithArgString (int object_id, unsigned char *BP, MSF_UINT32 BPlen,
                     int charset, void *ua,
                     char *baseUrl, 

                     char *refererUrl, int timeSlice,
                     int *errCode);
































brs_si_si_t *
brs_si_NewWithArgOpS (int object_id, unsigned char *BP, MSF_UINT32 BPlen,
                  int charset, void *ua,
                  char **pFuncName, brs_si_ops_t **pArgOpS,
                  char *baseUrl, char* refererUrl,
                  int timeSlice, int *errCode);





void
brs_si_Delete (brs_si_si_t **pThis);


























int
brs_si_ExecBlock (brs_si_si_t *thisx);



















brs_si_var_t *
brs_si_GetReturnVal (brs_si_si_t *thisx);





void
brs_si_ReceiveReturnVal (brs_si_si_t *thisx, brs_si_var_t **pRetVal);























void
brs_si_LoadStringDone (brs_si_si_t *thisx, int charset, char *str, MSF_UINT32 str_len, int status);
























void
brs_si_ReceiveCalledSIReturnVal (brs_si_si_t *thisx, brs_si_var_t **pRetVal,
                             int browserActionInvoked, 
                             int BrowserPrev, char **pBrowserGoUrl);





int
brs_si_GetLibCalllParams (brs_si_si_t *thisx, MSF_UINT16 *pLibIndex,
                      MSF_UINT8 *pFuncIndex, brs_si_ops_t **pArgOpS);
























int
brs_si_GetExtCalllParams_URL (brs_si_si_t *thisx, char **pCallUrl);






















int
brs_si_GetExtCalllParams_rest (brs_si_si_t *thisx, char **pFuncName,
                           brs_si_ops_t **pArgOpS);






















int
brs_si_NewReturnParams (brs_si_si_t *si);

#endif
#endif

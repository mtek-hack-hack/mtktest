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






















#ifndef _brs_sisq_h
#define _brs_sisq_h

#include "brs_cfg.h"
#include "brs_dlg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_sisi.h"

#ifdef BRS_CONFIG_PLUGIN  
#ifndef  _brs_plh_h
#include "brs_plh.h"
#endif
#endif


typedef struct BPElement {
  struct BPElement *next;               


  unsigned char    *BP;                 

  MSF_UINT32            BPlen;              
  int               charset;            


  char             *callURL;            

  int               isInitialBPInvoked; 



  brs_si_si_t          *theSI;              

} brs_si_structBPElement;


typedef struct si_sq_invoke_st {
  struct si_sq_invoke_st *next;      

  int                object_id;
  void              *ua;             



  MSF_UINT32             request_id;     



  char              *load_string_content_type; 



  int                isDone;         



  int                isInWaitState;  

  int                errorCode;      


  brs_si_var_t         *theResult;      


  int                browserPrev;    


  char              *browserGoUrl;   


  brs_si_structBPElement   *BPcallList;     



} brs_si_sq_invoke_t;


typedef struct SQ {
  int             timeSlice;   

  brs_si_sq_invoke_t *invokeList;  
} brs_si_sq_t;



typedef enum {
  eSs_more = 1,   
  eSs_done,       
  eSs_done_prev,  
  eSS_done_go,    
  eSs_error,      
  eSs_extFunc,    

  eSs_lib         

} brs_si_sq_script_status_t;





brs_si_sq_t *
brs_si_SQ_Init (int time_slice);





void
brs_si_SQ_Terminate (brs_si_sq_t *sq);


brs_si_sq_invoke_t *
brs_si_SQ_FindInvokeHead (brs_si_sq_t *thisx, int object_id);


brs_si_sq_invoke_t *
brs_si_SQ_FindInvokeHeadByRequestId (brs_si_sq_t *thisx, MSF_UINT32 request_id);






int
SQ_InvokeScript (brs_si_sq_t *thisx, int object_id,
                 void *ua, unsigned char *bp, MSF_UINT32 bp_len,
                 int charset, char *url);





void
SQ_AbortScriptsForSpecificUA (brs_si_sq_t *thisx, int object_id);






brs_si_sq_script_status_t
SQ_Exec (brs_si_sq_t *thisx, int *object_id);







int
SQ_GetResult (brs_si_sq_t *thisx, int object_id, char **pResultStr);







int
SQ_GetGoParams (brs_si_sq_t *thisx, int object_id, char **pGoUrl);






int
SQ_GetPrevParams (brs_si_sq_t *thisx, int object_id);






int
SQ_GetError (brs_si_sq_t *thisx, int object_id, int *errCode);







char *
SQ_GetExternalCallParams (brs_si_sq_invoke_t *invokeEl);






int
SQ_GetLibCallParams (brs_si_sq_t *thisx, int object_id, MSF_UINT16 *pLibIndex,
                     MSF_UINT8 *pFuncIndex, 
                     brs_si_ops_t **pArgOpS);



void
SQ_ReturnValueToScript (brs_si_sq_t *thisx, int object_id, char **theValueStr);




void
SQ_ReturnVarValueToScript (brs_si_sq_t *thisx, int object_id,
                           brs_si_var_t **ppResultVar);






void
SQ_ReturnStringValueToScript (brs_si_sq_t *thisx, int object_id, char **theValue);






void
SQ_ReturnBoolValueToScript (brs_si_sq_t *thisx, int object_id, int theValue);






void
SQ_ReturnIntValueToScript (brs_si_sq_t *thisx, int object_id, MSF_INT32 theValue);








void
SQ_LoadStringDone (brs_si_sq_t *thisx, int object_id, int charset,
                   char *str, MSF_UINT32 str_len, int status);





void
SQ_LibraryErrorReceived (brs_si_sq_t *thisx, int object_id);

int
SQ_GetObjectId (brs_si_sq_t *sq, int object_id);







void
SQ_LoadErrorReceived (brs_si_sq_t *thisx, int object_id);












void
SQ_LoadDoneReceived (brs_si_sq_t *thisx, int object_id,
                     unsigned char **pBP, MSF_UINT32 BPlen, int charset);
















int
SQ_GetAnArgumentAsString (brs_si_ops_t *argOpS, char **pArgAsStr);





void
SQ_DeleteArgOpS (brs_si_ops_t **pArgOpS);


#ifdef BRS_CONFIG_WMLS_CRYPTO
void
SQ_TextSigned (brs_si_sq_t *thisx, int object_id, int sign_id, int algorithm,
               int sigLen, unsigned char *signature,
               unsigned char *hashedKey, int hashedKeyLen,
               unsigned char *certificate, int certificateLen,
               int certificateType, int err);
#endif

#ifdef BRS_CONFIG_PLUGIN  
void
SQ_ProprietaryLibraryFunctionResponse (brs_si_sq_t *thisx, int object_id,
                                       int status_code,
                                       brs_plg_wmls_var_t *result_var);
#endif
#endif
#endif

/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */






#ifndef _prs_main_h
#define _prs_main_h

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif

#ifndef _msf_prsr_h
#include "msf_prsr.h"
#endif

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif

#ifndef _prs_type_h
#include "prs_type.h"
#endif

#ifndef _prs_dlg_h
#include "prs_dlg.h"
#endif







#define PRS_STATE_FILE_INIT     0
#define PRS_STATE_FILE_READ     1
#define PRS_STATE_PIPE_READ     2
#define PRS_STATE_DONE          3



#define PRS_STATE_PRE_PROCESS_I  0
#define PRS_STATE_PRE_PROCESS_E  1
#define PRS_STATE_PROCESS_1      2
#define PRS_STATE_PROCESS_2      3
#define PRS_STATE_POST_PROCESS_E 4
#define PRS_STATE_PROCESS_SEND_1 5
#define PRS_STATE_PROCESS_SEND_2 6


#define PRS_STR_NULL            -1



#define PRS_NOT_USED            -1



#define PRS_WBXML               0x4000







#define PRS_STATUS_NEXT         2 
#define PRS_STATUS_PAUSE        3 
#define PRS_STATUS_FINISHED     4 
#define PRS_ERROR_AUTH_FAILED   5 
#define PRS_ERROR_BUILD         6 
#define PRS_ERROR_VALIDATE      7 







#ifdef PRS_LOG
#define PRS_LOG_MSG(x) prs_log_msg x
void prs_log_msg (const char *format, ...);
#else
#define PRS_LOG_MSG(x)
#endif







typedef int prs_processor_t (prs_job_t* job);



typedef struct prs_buf_st {
  struct prs_buf_st*      more;
  char*                   buf;    
  long                    length;
  long                    pos;
} prs_buf_t;



typedef struct prs_user_data_st {
  prs_node_list_t           nodeList;
  prs_validate_node_t*      internalVald;
  prs_fill_in_node_t*       fillIn;
  prs_process_list_t*       internalPre;
  int                       state;
  int                       skip;
  




  prs_node_t*               pxl; 
  prs_node_t*               pxpFirst; 
  prs_node_t*               pxpLast;
  prs_node_t*               pxpCurrent;
  int                       foundElements;

#ifdef PRS_LOG
  int                       textmode;
  int                       depth;
#endif

#ifdef MTK_TMP_PATCH /* CR27923 */
/* OMA Extension */
  prs_node_t*               wlanFirst;  /* stream of wlan/sec-ssid/eap/cert/wepkey nodes */
  prs_node_t*               wlanLast;
  prs_node_t*               crtEap;
  prs_node_t*               crtWlanSectionNode;
#endif  /* MTK_TMP_PATCH */
} prs_user_data_t;



struct prs_job_st {
  struct prs_job_st*      next;
  prs_processor_t*        run;
  msf_prsr_parser_t*      parser;
  prs_buf_t*              doc;
  char*                   readName;
  int                     readHandle;
  int                     charset;
  int                     textmode;
  int                     state;
  prs_user_data_t         userData;
  int                     sec;
  unsigned char           mac[21];
  unsigned char*          key;
  int                     keyLen;
  int                     authStep;
  prs_dlg_t*              dlg;
  MsfScreenHandle         scr;
  int                     wants_to_run;
#ifdef __MMI_DUAL_SIM__
  int                     network_account_id;
#endif
};






extern jmp_buf prs_jmpbuf;
extern int prs_insideRun;









void
prs_init (void);





void
prs_terminate (void);





void
prs_main (void);





void
prs_reg_continue_auth (char* paramName, unsigned char* param, 
                       MSF_UINT16 paramLen);




void
prs_widget_action (msf_widget_action_t *str);




void
prs_module_status (msf_module_status_t *module_status);




int
prs_module_is_active (MSF_UINT8 mod_id);








prs_job_t*
prs_create_job (char* data, long dataLength, int dataType, int charset, int doctype,
                int textMode, char *contentHeaders);
                



void
prs_add_job (prs_job_t* job);




void
prs_delete_current_job (void);




int
prs_more_jobs (void);


#endif



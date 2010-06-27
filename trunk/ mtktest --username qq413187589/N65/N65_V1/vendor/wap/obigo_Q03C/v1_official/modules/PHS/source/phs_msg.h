/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
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









#ifndef _phs_msg_h
#define _phs_msg_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _phs_sig_h
#include "phs_sig.h"
#endif


#ifndef _phs_cfg_h
#include "phs_cfg.h"
#endif

#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES 
#ifndef _uis_if_h
#include "uis_if.h"
#endif
#endif

#ifndef _stk_if_h
#include "stk_if.h"
#endif





#define PHS_MSG_SIG_NEW_MESSAGE                    PHS_MODULE_MSG + 1
#define PHS_MSG_SIG_UIS_MESSAGE_DATA               PHS_MODULE_MSG + 2  











#define PHS_STATE_NEW_MSG                     0
#define PHS_STATE_WHITELIST_DONE              1
#define PHS_STATE_PRS_STARTED                 2
#define PHS_STATE_PARSING_SI                  3
#define PHS_STATE_PARSING_SL                  4
#define PHS_STATE_PARSING_CO                  5
#define PHS_STATE_READING_HEADER              6
#define PHS_STATE_READING_BODY                7


#define PHS_PRIO_LOW                             0
#define PHS_PRIO_MEDIUM                          1
#define PHS_PRIO_HIGH                            2
#define PHS_PRIO_DELETE                          3
#define PHS_PRIO_CACHE                           4
#define PHS_PRIO_NONE                            5







typedef struct phs_co_data_st {
  struct phs_co_data_st    *next;           
  int                       type;           
  char                     *text;           
} phs_co_data_t;

 


typedef struct phs_prsd_info_st {
  char                    *href;           
  int                      priority;         
  char                    *si_id;          
  char                    *text;           
  MSF_UINT32               created;        
  MSF_UINT32               expired;        
  phs_co_data_t           *co_data;        
} phs_prs_info_t;











void
phs_msg_init (void);

void
phs_msg_main (phs_signal_t* signal);

void
phs_handle_new_push (stk_recv_request_t *p);

void
phs_handle_content_send_ack (int id, int status);

void 
phs_msg_delete_all_message_in_list (void);

#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES 

void
phs_handle_parsing_aborted (int msg_id);

void
phs_handle_uis_message_data (uis_reply_msg_t *result);

#endif
#endif



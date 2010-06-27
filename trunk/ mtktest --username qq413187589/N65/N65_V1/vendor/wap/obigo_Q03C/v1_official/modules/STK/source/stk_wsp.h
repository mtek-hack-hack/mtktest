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








#ifndef _stk_wsp_h
#define _stk_wsp_h

#ifdef STK_CONFIG_WSP





#define STK_WSP_SIG_UNIT_METHOD_INVOKE_REQ  STK_MODULE_WSP + 0
#define STK_WSP_SIG_CREATE_SESSION          STK_MODULE_WSP + 1
#define STK_WSP_SIG_METHOD_INVOKE_REQ       STK_MODULE_WSP + 2
#define STK_WSP_SIG_METHOD_RESULT_RES       STK_MODULE_WSP + 3
#define STK_WSP_SIG_METHOD_ABORT_REQ        STK_MODULE_WSP + 4
#define STK_WSP_SIG_ACK_RES                 STK_MODULE_WSP + 5
#define STK_WSP_SIG_CONFIRMED_PUSH_RES      STK_MODULE_WSP + 6















#define STK_WSP_SIG_UNIT_METHOD_RESULT_IND  STK_MODULE_WSP + 8
#define STK_WSP_SIG_SESSION_CREATED         STK_MODULE_WSP + 9
#define STK_WSP_SIG_REDIRECT_IND            STK_MODULE_WSP + 10
#define STK_WSP_SIG_ACK_CNF                 STK_MODULE_WSP + 11
#define STK_WSP_SIG_METHOD_INVOKE_CNF       STK_MODULE_WSP + 12
#define STK_WSP_SIG_METHOD_RESULT_IND       STK_MODULE_WSP + 13
#define STK_WSP_SIG_METHOD_ABORT_IND        STK_MODULE_WSP + 15
#define STK_WSP_SIG_PUSH_IND                STK_MODULE_WSP + 16
#define STK_WSP_SIG_PUSH_ABORT_IND          STK_MODULE_WSP + 17















#define STK_WSP_SIG_READ_HEADERS            STK_MODULE_WSP + 18






#define STK_WSP_OPT_CONFIRMED_PUSH          0x80
#define STK_WSP_OPT_PUSH                    0x40
#define STK_WSP_OPT_SESSION_RESUME          0x20
#define STK_WSP_OPT_ACK_HEADERS             0x10


#define STK_WSP_REDIRECT_FLAGS_PERMANENT    0x80
#define STK_WSP_REDIRECT_FLAGS_REUSE_SEC    0x40






#ifdef STK_CONFIG_WTP
typedef struct {
  MSF_UINT8      flags;
  unsigned char *address;
  int            address_len;
} stk_wsp_redirect_ind_t;
#endif









void
stk_wsp_init (void);




void
stk_wsp_terminate (void);




void
stk_wsp_delete_connection (int cidx);




int
stk_wsp_read (int cidx, int request_id, void *buf, int buflen);




void
stk_wsp_select (int cidx, int request_id);






void
stk_wsp_notify_read_ready (int cidx, int request_id);
#endif
#endif

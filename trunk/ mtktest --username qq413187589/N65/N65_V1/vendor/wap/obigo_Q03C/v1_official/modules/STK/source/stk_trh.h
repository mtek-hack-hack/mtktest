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








#ifndef _stk_trh_h
#define _stk_trh_h





#define STK_TRH_CACHE_BUFSIZE                                   800





#define STK_TRH_SIG_CONFIGURE_CHANNEL           STK_MODULE_TRH + 0
#define STK_TRH_SIG_CONFIGURE_PROXY_CHANNEL     STK_MODULE_TRH + 1
#define STK_TRH_SIG_REMOVE_CHANNEL              STK_MODULE_TRH + 2
#define STK_TRH_SIG_HTTP_REQUEST                STK_MODULE_TRH + 3
#define STK_TRH_SIG_CANCEL_REQUEST              STK_MODULE_TRH + 4
#define STK_TRH_SIG_AUTH_CREDENTIALS            STK_MODULE_TRH + 5
#define STK_TRH_SIG_OBJECT_DELETED              STK_MODULE_TRH + 6
#define STK_TRH_SIG_HOST_BY_NAME                STK_MODULE_TRH + 7
#define STK_TRH_SIG_ENABLE_COOKIES              STK_MODULE_TRH + 8
#define STK_TRH_SIG_RUN_COOKIE                  STK_MODULE_TRH + 9
#define STK_TRH_SIG_SOCKET_RELEASED             STK_MODULE_TRH + 10
#define STK_TRH_SIG_RUN_CACHE                   STK_MODULE_TRH + 11
#define STK_TRH_SIG_AWAITED_CACHE_FINISHED      STK_MODULE_TRH + 12
#define STK_TRH_SIG_DEFAULT_CHANNEL             STK_MODULE_TRH + 13
#define STK_TRH_SIG_CACHE_SET_PARAM             STK_MODULE_TRH + 14
#define STK_TRH_SIG_CLEAR                       STK_MODULE_TRH + 15
#define STK_TRH_SIG_SET_CACHE_CONTROL           STK_MODULE_TRH + 16
#define STK_TRH_SIG_MIME_TYPE                   STK_MODULE_TRH + 17
#define STK_TRH_SIG_RUN_AUTH                    STK_MODULE_TRH + 18
#define STK_TRH_SIG_DYNAMIC_HEADER              STK_MODULE_TRH + 19































typedef struct {
  int        requestId;
  char      *username;
  char      *password;
  int        options;
} stk_auth_credentials_t;

typedef struct stk_trh_reg_resp_st {
  struct stk_trh_reg_resp_st *next;
  int                         key;
  MSF_INT32                   intVal;
  unsigned char              *strVal;
} stk_trh_reg_resp_t;





void
stk_trh_init(void);

void
stk_trh_terminate(void);




void
stk_trh_delete_all(void);







void 
stk_trh_set_request_timer (int module_id, int connection_id, int request_id);





void
stk_trh_reset_request_timer (int module_id, int connection_id, int request_id);







char *
stk_trh_get_host_endpoint (int module_id, int connection_id);







char*
stk_trh_get_static_headers(int module_id, int connection_id);




void
stk_trh_read_completed (int connection_id, int request_id);





int
stk_trh_get_module_id (int connection_id);





int
stk_trh_get_channel_id (int connection_id);
#endif

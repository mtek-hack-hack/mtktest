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








#ifndef _stk_cmgr_h
#define _stk_cmgr_h






#define STK_CMGR_SIG_CREATE_CLIENT_CONNECTION        STK_MODULE_CMGR + 0
#define STK_CMGR_SIG_CREATE_SERVER_CONNECTION        STK_MODULE_CMGR + 1
#define STK_CMGR_SIG_CREATE_STREAM_CONNECTION        STK_MODULE_CMGR + 2
#define STK_CMGR_SIG_UPGRADE_TO_SECURE               STK_MODULE_CMGR + 3
#define STK_CMGR_SIG_CLOSE_CONNECTION                STK_MODULE_CMGR + 4
#define STK_CMGR_SIG_SEND_REQUEST                    STK_MODULE_CMGR + 5
#define STK_CMGR_SIG_SEND_REPLY                      STK_MODULE_CMGR + 6
#define STK_CMGR_SIG_ABORT_REQUEST                   STK_MODULE_CMGR + 7
#define STK_CMGR_SIG_CONFIRM_REQUEST                 STK_MODULE_CMGR + 8
















#define STK_CMGR_SIG_CONNECTION_CREATED           STK_MODULE_CMGR + 9
#define STK_CMGR_SIG_REDIRECT_IND                 STK_MODULE_CMGR + 10
#define STK_CMGR_SIG_CONNECTION_CLOSED            STK_MODULE_CMGR + 11
#define STK_CMGR_SIG_RECV_REPLY                   STK_MODULE_CMGR + 12
#define STK_CMGR_SIG_RECV_REQUEST                 STK_MODULE_CMGR + 13
#define STK_CMGR_SIG_REQUEST_ABORTED              STK_MODULE_CMGR + 14
#define STK_CMGR_SIG_NOTIFY                       STK_MODULE_CMGR + 15
#define STK_CMGR_SIG_NO_CONNECTION                STK_MODULE_CMGR + 16











#define STK_CMGR_SIG_OPEN                         STK_MODULE_CMGR + 17
#define STK_CMGR_SIG_OPEN_STREAM                  STK_MODULE_CMGR + 18
#define STK_CMGR_SIG_CLOSE                        STK_MODULE_CMGR + 19
#define STK_CMGR_SIG_SHUTDOWN                     STK_MODULE_CMGR + 20
#define STK_CMGR_SIG_OPENED                       STK_MODULE_CMGR + 21
#define STK_CMGR_SIG_CLOSED                       STK_MODULE_CMGR + 22
#define STK_CMGR_SIG_FAILED                       STK_MODULE_CMGR + 23
#define STK_CMGR_SIG_SOCKET_RECV_READY            STK_MODULE_CMGR + 24
#define STK_CMGR_SIG_SOCKET_SEND_READY            STK_MODULE_CMGR + 25
#define STK_CMGR_SIG_UA_PROF_CHANGED              STK_MODULE_CMGR + 26




















#define STK_CMGR_FLAG_IS_SECURE                   0x0001
#define STK_CMGR_FLAG_CLOSING                     0x0002
#define STK_CMGR_FLAG_USING_PROXY                 0x0004
#define STK_CMGR_FLAG_USE_WTP_SAR                 0x0008
#define STK_CMGR_FLAG_WTP_FIRST_REPLY             0x0010
#define STK_CMGR_FLAG_SERVER_SOCKET               0x0020
#define STK_CMGR_FLAG_PUSH_SERVER                 0x0040
#define STK_CMGR_FLAG_FIRST_REQUEST               0x0080
#define STK_CMGR_FLAG_READ_COMPLETED              0x0100
#define STK_CMGR_FLAG_SOCKET_IS_OPEN              0x0200


#define STK_CMGR_FLAG_FIRST_REPLY                 0x01
#define STK_CMGR_FLAG_IS_REDIRECTING              0x02
#define STK_CMGR_FLAG_UAPROF_SUPPORTED            0x04
#define STK_CMGR_FLAG_PROFILE_DIFF_UPDATED        0x08

#define STK_CMGR_HTTP_VERSION_UNKNOWN              0
#define STK_CMGR_HTTP_VERSION_1_0                  10
#define STK_CMGR_HTTP_VERSION_1_1                  11





#define STK_CMGR_CONNECTION_GET(cidx)  ((((cidx) < 0) || ((cidx) >= STK_CFG_MAX_CONNECTIONS)) ? NULL : stk_cmgr_connection_table[(cidx)])






#ifdef STK_CONFIG_WSP
typedef struct {
  MSF_UINT32 client_sdu_size;
  MSF_UINT32 server_sdu_size;
  MSF_UINT8  protocol_options;
  MSF_UINT8  method_mor;
  MSF_UINT8  push_mor;
} stk_cmgr_capabilities_t;
#endif

typedef struct {
  int                      module; 
  int                      connection_id;
  int                      parent_id;
  int                      cidx;
  long                     socket;
  MSF_INT32                security_id;
  int                      flags;
  int                      connection_type;
  MSF_INT32                networkAccountId;
  msf_sockaddr_t           addr;
  int                      state;
  int                      local_flags;
  int                      error_code;
  unsigned char           *connect_headers;
  int                      headers_len;
#ifdef STK_CONFIG_WSP
  int                      redir_flags;
  int                      encoding_version;
  stk_cmgr_capabilities_t  capabilities;
#endif
#ifdef STK_CONFIG_TLS
  char                    *domain;
  char                    *data_source;
#endif
} stk_cmgr_connection_t;






typedef struct {
  int            connection_id;
  msf_sockaddr_t server_addr;
  MSF_INT32      networkAccountId;
  int            connection_type;
  int            flags;
} stk_cmgr_create_client_conn_t;

typedef struct {
  int        connection_id;
  MSF_UINT16 server_port;
  int        connection_type;
  MSF_INT32  networkAccountId;
} stk_cmgr_create_server_conn_t;

typedef struct {
  int            request_id;
  int            version;
  int            method;        
  char          *url;           
  hdr_table_t   *headers;       
  int            num_entries;
  stk_content_t *content;
} stk_cmgr_request_t;

typedef struct {
  int            request_id;
  long           socket_id;
  MSF_INT32      security_id;
  int            protocol;
  int            version;
  int            status;          
  hdr_table_t   *headers;
  int            num_entries;
  stk_content_t *content;
} stk_cmgr_reply_t;

typedef struct {
  msf_sockaddr_t  addr;
  char           *data; 
  int             datalen;
} stk_cmgr_recv_from_t;






extern stk_cmgr_connection_t *stk_cmgr_connection_table[STK_CFG_MAX_CONNECTIONS];









void
stk_cmgr_init (void);




void
stk_cmgr_terminate (void);




int
stk_cmgr_is_open (int connection_id);

void
stk_cmgr_delete_request (stk_cmgr_request_t *req);

void
stk_cmgr_delete_reply (stk_cmgr_reply_t *res);




void
stk_cmgr_delete_content (int num_entries, stk_content_t *content);




long
stk_cmgr_read (int connection_id, int request_id, void *buf, long buflen);




void
stk_cmgr_select (int connection_id, int request_id);




void
stk_cmgr_notify (int cidx, int request_id, int eventType);




void
stk_cmgr_sockaddr_copy (msf_sockaddr_t *dst_addr, msf_sockaddr_t *src_addr);




int
stk_cmgr_sockaddr_equal (msf_sockaddr_t *addr1, msf_sockaddr_t *addr2);

#ifdef STK_CONFIG_TLS



char *
stk_cmgr_get_domain (int module_id, int connection_id);
#endif

#endif

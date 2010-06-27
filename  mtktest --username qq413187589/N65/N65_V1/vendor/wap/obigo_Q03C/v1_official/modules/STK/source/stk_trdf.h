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











#ifndef _stk_trdf_h
#define _stk_trdf_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifndef _stk_trh_h
#include "stk_trh.h"
#endif

#ifndef _stk_if_h
#include "stk_if.h"
#endif

#ifndef _stk_hdr_h
#include "stk_hdr.h"
#endif

#ifndef _msf_url_h
#include "msf_url.h"
#endif






#define CFG_TRH_MAX_CHANNELS                      4

#define CFG_TRH_MAX_CONNECTIONS                   10






typedef struct stk_trh_proxy_st {
  msf_sockaddr_t         proxy_address;
  MSF_UINT16             secure_port;
  char                  *userName;
  char                  *password;
  char                  *realm;
} stk_trh_proxy_t;

typedef struct stk_trh_channel_st {
  MSF_INT16              channel_id;
  MSF_INT16              connection_type;
  MSF_INT32              networkAccountId;
  MSF_INT16              time_out;
  MSF_INT16              options;
  char                  *static_headers;
  stk_trh_proxy_t       *proxy;       
} stk_trh_channel_t;



typedef struct stk_trh_transaction_st{
  struct stk_trh_transaction_st *next, *prev;

  struct stk_trh_connection_st *conn;

  
  int                    connection_id;
  MSF_UINT8              module_id;
  stk_trh_channel_t     *channel;
  msf_sockaddr_t         server_addr;
  int                    conn_flags;

  
  int                    ext_request_id; 
  int                    request_id;      
  char                  *url;
  int                    method;
  int                    status;
  int                    options;
  hdr_table_t           *headers; 
  char                  *replyFileName;
  long                   replyFileSize;
  int                    num_entries;
  stk_content_t         *content;

  
  msf_scheme_t           scheme;
  int                    state;
  int                    num_redirects;
  int                    auto_resend; 
 
  
  int                    www_auth_id;
  int                    proxy_auth_id;
  struct tr_auth_rec_st *auth_rec;

  
  long                   socket_id;
  MSF_INT32              security_id;
  int                    protocol;
  int                    reply_sink;
#ifdef STK_CONFIG_FILE
  int                    reply_src;
#endif
  char                  *buf;
  int                    buf_replypos;
  int                    reply_flags;
#ifdef STK_CONFIG_CACHE
  MSF_INT32              cache_file;
  int                    buf_cachepos;
#endif
  int                    buf_endpos;
} stk_trh_transaction_t;

typedef struct stk_trh_transaction_queue_st {
  stk_trh_transaction_t *first;
  stk_trh_transaction_t *last;
} stk_trh_transaction_queue_t;

typedef struct stk_trh_connection_st {
  int                    connection_id;
  MSF_UINT8              module_id;
  stk_trh_channel_t     *channel;
  msf_sockaddr_t         server_addr;
  MSF_UINT32             networkAccountId;
  MSF_INT16              connection_type;
  int                    conn_flags;
  int                    version;
  int                    max_requests;
  int                    num_requests;
  char                   *host_endpoint;
  int                    state;
  stk_trh_transaction_queue_t send_queue;
} stk_trh_connection_t;

typedef struct stk_trh_st {
  struct stk_trh_st     *next;

  stk_trh_transaction_queue_t wait_queue;
  
  MSF_UINT8              module_id;
  int                    num_open_connections;
  stk_trh_connection_t  *connection[CFG_TRH_MAX_CONNECTIONS + 1];
  int                    num_open_channels;
  stk_trh_channel_t     *channel[CFG_TRH_MAX_CHANNELS];
} stk_trh_t;

#endif

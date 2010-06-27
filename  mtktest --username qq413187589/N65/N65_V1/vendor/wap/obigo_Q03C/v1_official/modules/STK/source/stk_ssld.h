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








#ifndef _stk_ssld_h
#define _stk_ssld_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifdef STK_CONFIG_SSL
#ifndef _stk_tlsd_h
#include "stk_tlsd.h"
#endif







#define STK_SSL_PROTOCOL_VERSION_MAJOR                STK_TLS_PROTOCOL_VERSION_MAJOR
#define STK_SSL_PROTOCOL_VERSION_MINOR                0

#define STK_SSL_MD5_PAD_LEN                           48
#define STK_SSL_SHA_PAD_LEN                           40


#define STK_SSL_ALERT_DESC_NO_CERTIFICATE             41







extern const unsigned char stk_ssl_pad1[48];
extern const unsigned char stk_ssl_pad2[48];






int
stk_ssl_translate_alert_description (int alert_desc);

int
stk_ssl_compute_mac (stk_tls_connection_state_t *cstate,
                 unsigned char *mac_secret,
                 stk_tls_record_t *rec,
                 unsigned char *mac);

void
stk_sslhm_create_keys (stk_tls_connection_t *conn);

int
stk_sslhm_create_certificate_verify (stk_tls_connection_t *conn);

void
stk_sslhm_create_client_finished (stk_tls_connection_t *conn);

void
stk_sslhm_process_server_finished (stk_tls_connection_t *conn,
                               unsigned char *msg, int msg_len);


#endif
#endif

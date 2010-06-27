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








#ifndef _stk_tlsh_h
#define _stk_tlsh_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifdef STK_CONFIG_TLS
#ifndef _stk_tlsd_h
#include "stk_tlsd.h"
#endif








#define STK_TLSHM_SIG_START                           STK_MODULE_TLSHM + 0
#define STK_TLSHM_SIG_OPEN                            STK_MODULE_TLSHM + 1
#define STK_TLSHM_SIG_ERROR                           STK_MODULE_TLSHM + 2





#define STK_TLSHM_SIG_RECV_HSHK_MSG                   STK_MODULE_TLSHM + 3
#define STK_TLSHM_SIG_RECV_CCS                        STK_MODULE_TLSHM + 4
#define STK_TLSHM_SIG_SEND_HSHK_MSG                   STK_MODULE_TLSHM + 5
#define STK_TLSHM_SIG_SEND_CCS                        STK_MODULE_TLSHM + 6
#define STK_TLSHM_SIG_CCS_PROCESSED                   STK_MODULE_TLSHM + 7
#define STK_TLSHM_SIG_SEND_ALERT                      STK_MODULE_TLSHM + 8










#define STK_TLSHM_SIG_VERIFY_CERT_RESPONSE            STK_MODULE_TLSHM + 9
#define STK_TLSHM_SIG_KEY_EXCHANGE_RESPONSE           STK_MODULE_TLSHM + 10
#define STK_TLSHM_SIG_CLIENT_CERT_RESPONSE            STK_MODULE_TLSHM + 11
#define STK_TLSHM_SIG_COMP_SIGNATURE_RESPONSE         STK_MODULE_TLSHM + 12
#define STK_TLSHM_SIG_GET_CIPHER_SUITES_RESPONSE      STK_MODULE_TLSHM + 13
#define STK_TLSHM_SIG_PEER_LOOKUP_RESPONSE            STK_MODULE_TLSHM + 14
#define STK_TLSHM_SIG_SESSION_FETCH_RESPONSE          STK_MODULE_TLSHM + 15
#define STK_TLSHM_SIG_PRF_RESPONSE                    STK_MODULE_TLSHM + 16

















#define STK_TLSHM_STATE_WAIT_SERVER_HELLO              0x03
#define STK_TLSHM_STATE_WAIT_HANDSHAKE_MSG_1           0x04
#define STK_TLSHM_STATE_WAIT_HANDSHAKE_MSG_2           0x05
#define STK_TLSHM_STATE_WAIT_HANDSHAKE_MSG_3           0x06
#define STK_TLSHM_STATE_WAIT_HANDSHAKE_MSG_4           0x07
#define STK_TLSHM_STATE_WAIT_CCS                       0x08
#define STK_TLSHM_STATE_WAIT_FINISHED                  0x09
#define STK_TLSHM_STATE_WAIT_CONNECTOR                 0x0a
#define STK_TLSHM_STATE_CREATE_KEYS_1                  0x0b
#define STK_TLSHM_STATE_CREATE_KEYS_2                  0x0c
#define STK_TLSHM_STATE_CREATE_KEYS_3                  0x0d
#define STK_TLSHM_STATE_CREATE_KEYS_4                  0x0e
#define STK_TLSHM_STATE_WAIT_CCS_PROCESSED             0x0f
#define STK_TLSHM_STATE_CHECK_FINISHED                 0x10
#define STK_TLSHM_STATE_CREATE_FINISHED                0x11
#define STK_TLSHM_STATE_WAIT_CONNECTOR_1               0x12











void
stk_tlshm_init (void);

void
stk_tlshm_terminate (void);

void
stk_tls_handshake_free (stk_tls_handshake_t *hs);

void
stk_tlshm_install_pending_write (stk_tls_connection_t *conn);

void
stk_tlshm_send_finished (stk_tls_connection_t *conn, unsigned char *buf, int buflen);

void
stk_tlshm_handshake_finished (stk_tls_connection_t *conn);

void
stk_tlshm_handshake_error (stk_tls_connection_t *conn, int error_code, int alert_desc);

#endif
#endif

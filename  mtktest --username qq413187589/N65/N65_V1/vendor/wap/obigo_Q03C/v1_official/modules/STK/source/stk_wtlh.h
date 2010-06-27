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








#ifndef _stk_wtlh_h
#define _stk_wtlh_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif
#ifdef STK_CONFIG_WTLS

#ifndef _stk_wtld_h
#include "stk_wtld.h"
#endif

#define STK_WTLSHM_SIG_START                   STK_MODULE_WTLSHM + 0
#define STK_WTLSHM_SIG_OPEN                    STK_MODULE_WTLSHM + 1
#define STK_WTLSHM_SIG_OPENING                 STK_MODULE_WTLSHM + 2
#define STK_WTLSHM_SIG_ERROR                   STK_MODULE_WTLSHM + 3

#define STK_WTLSHM_SIG_RECV_HSHK_MSG           STK_MODULE_WTLSHM + 4
#define STK_WTLSHM_SIG_RECV_CCS                STK_MODULE_WTLSHM + 5
#define STK_WTLSHM_SIG_APPEND_HSHK_MSG         STK_MODULE_WTLSHM + 6
#define STK_WTLSHM_SIG_APPEND_CCS              STK_MODULE_WTLSHM + 7
#define STK_WTLSHM_SIG_FLUSH_BUFFER            STK_MODULE_WTLSHM + 8
#define STK_WTLSHM_SIG_FLUSH_BUFFER_WITH_DATA  STK_MODULE_WTLSHM + 9
#define STK_WTLSHM_SIG_INSTALL_PENDING         STK_MODULE_WTLSHM + 10
#define STK_WTLSHM_SIG_PENDING_INSTALLED       STK_MODULE_WTLSHM + 11

#define STK_WTLSHM_SIG_VERIFY_CERT_RESPONSE    STK_MODULE_WTLSHM + 12
#define STK_WTLSHM_SIG_KEY_EXCHANGE_RESPONSE   STK_MODULE_WTLSHM + 13
#define STK_WTLSHM_SIG_CLIENT_CERT_RESPONSE    STK_MODULE_WTLSHM + 14
#define STK_WTLSHM_SIG_COMP_SIGNATURE_RESPONSE STK_MODULE_WTLSHM + 15
#define STK_WTLSHM_SIG_GET_METHODS_RESPONSE    STK_MODULE_WTLSHM + 16
#define STK_WTLSHM_SIG_PEER_LOOKUP_RESPONSE    STK_MODULE_WTLSHM + 17
#define STK_WTLSHM_SIG_SESSION_FETCH_RESPONSE  STK_MODULE_WTLSHM + 18


typedef struct {
  unsigned char *buf;
  MSF_UINT16         buflen;
} stk_wtlshm_hsk_msg_t;


void
stk_wtlshm_init (void);

void
stk_wtlshm_terminate (void);

void
stk_wtls_handshake_free (stk_wtls_handshake_t *hs);

#endif
#endif

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








#ifndef _stk_wtls_h
#define _stk_wtls_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifdef STK_CONFIG_WTLS





#define STK_WTLS_SIG_PRF_RESPONSE           STK_MODULE_WTLS + 0
#define STK_WTLS_SIG_INITIALISE_RESPONSE    STK_MODULE_WTLS + 1
#define STK_WTLS_SIG_UNIT_DATA_REQ          STK_MODULE_WTLS + 2









#define STK_WTLS_WAIT_DATA_INTERVAL         10










void
stk_wtls_init (void);

void
stk_wtls_terminate (void);

void
stk_wtls_delete_connection (int cidx);

void
stk_wtls_create_server_connection (int cidx);




void
stk_wtls_send_pdu (stk_cmgr_connection_t *conn, void *data, long datalen);

#endif
#endif

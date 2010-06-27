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








#ifndef _stk_tls_h
#define _stk_tls_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifdef STK_CONFIG_TLS













void
stk_tls_init (void);

void
stk_tls_terminate (void);

void
stk_tls_delete_connection (int cidx);

int 
stk_tls_socket_recv (int cidx, void *buf, int len);
 
int 
stk_tls_socket_send (int cidx, void *buf, int len);

int
stk_tls_socket_select (int cidx, int type);

#endif
#endif

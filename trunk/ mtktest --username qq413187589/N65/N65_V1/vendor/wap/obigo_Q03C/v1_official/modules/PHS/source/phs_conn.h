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









#ifndef _phs_conn_h
#define _phs_conn_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _stk_if_h
#include "stk_if.h"
#endif

#ifndef _phs_if_h
#include "phs_if.h"
#endif

#ifndef _phs_main_h
#include "phs_main.h"
#endif





void
phs_conn_handle_open_connection (MSF_UINT8 module_id, phs_open_push_connection_t *p);

void
phs_conn_handle_close_connection (MSF_UINT8 module_id, MSF_UINT16 handle);

void
phs_conn_handle_connection_created (stk_connection_created_t *p);

void
phs_conn_handle_connection_closed (stk_connection_closed_t *p);

phs_connection_t*
phs_find_server_connection_by_connection_id (int connection_id);

int 
phs_conn_get_connection_type_by_connection_id (int connection_id);

int 
phs_conn_get_network_acc_id_type_by_connection_id (int connection_id);

unsigned char*
phs_conn_get_cpi_tag_by_connection_id (int connection_id);

#endif



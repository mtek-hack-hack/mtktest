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








#ifndef _stk_wdp_h
#define _stk_wdp_h





#define STK_WDP_SIG_UNIT_DATA_IND                 STK_MODULE_WDP + 1
#define STK_WDP_SIG_RECV_FROM                     STK_MODULE_WDP + 2











void
stk_wdp_init (void);

void
stk_wdp_terminate (void);

void
stk_wdp_create_connection (int cidx);

void
stk_wdp_delete_connection (int cidx);




void
stk_wdp_send_pdu (stk_cmgr_connection_t *conn, void *data, long datalen);




void
stk_wdp_sendto (stk_cmgr_connection_t *conn, void *data, long datalen,
                msf_sockaddr_t *addr);




void
stk_wdp_socket_recv_ready (stk_cmgr_connection_t *conn);

void
stk_wdp_socket_send_ready (stk_cmgr_connection_t *conn);

#endif

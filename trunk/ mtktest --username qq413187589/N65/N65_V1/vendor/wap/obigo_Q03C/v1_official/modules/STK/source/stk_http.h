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









#ifndef _stk_http_h
#define _stk_http_h


















#define STK_HTTP_SIG_SEND_REQUEST       STK_MODULE_HTTP + 0
#define STK_HTTP_SIG_SEND_REPLY         STK_MODULE_HTTP + 1
#define STK_HTTP_SIG_ABORT_REQUEST      STK_MODULE_HTTP + 2











#define STK_HTTP_SIG_RECV_REPLY         STK_MODULE_HTTP + 3
#define STK_HTTP_SIG_RECV_REQUEST       STK_MODULE_HTTP + 4
#define STK_HTTP_SIG_REQUEST_ABORTED    STK_MODULE_HTTP + 5











#define STK_HTTP_SIG_SCHEDULE           STK_MODULE_HTTP + 6












void
stk_http_init (void);




void
stk_http_terminate (void);




void
stk_http_delete_connection (int cidx);




int
stk_http_read (int cidx, int request_id, void *buf, int buflen);




void
stk_http_select (int cidx, int request_id);

#endif

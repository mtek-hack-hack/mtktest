/*
 * Copyright (C) Obigo AB, 2002-2007.
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










#ifndef _tr_cache_h
#define _tr_cache_h

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _stk_trh_h
#include "stk_trh.h"
#endif

#ifndef _stk_trdf_h
#include "stk_trdf.h"
#endif

#ifndef _stk_cmgr_h
#include "stk_cmgr.h"
#endif


#ifdef STK_CONFIG_CACHE





#define STK_CACHE_LOOKUP_NOT_IN_CACHE        0
#define STK_CACHE_LOOKUP_READY_TO_DELIVER    1
#define STK_CACHE_LOOKUP_AWAIT_WRITING       2
#define STK_CACHE_LOOKUP_VALIDATION_NEEDED   3





extern int stk_cache_index_file;    






void
stk_cache_init (void);

void
stk_cache_terminate (void);

void
stk_cache_run (void);

void
stk_cache_clear (void);


void
stk_cache_handle_set_control (stk_set_cache_control_t *p);


void
stk_cache_delete_url_match (char *url);


void
stk_cache_delete_url_prefix (char *url);

void
stk_cache_set_param (int param, MSF_UINT32 value);

stk_trh_transaction_t *
stk_cache_find_transaction (int handle);

int
stk_cache_lookup (stk_trh_transaction_t *tra, stk_cmgr_reply_t *rep);

void
stk_cache_add_response (stk_trh_transaction_t *tra, int flags);

long
stk_cache_read (int handle, void *buf, long size);

long
stk_cache_write (int handle, void *buf, long size);

void
stk_cache_select (int handle, int eventType);

void
stk_cache_close (int handle);

char*
stk_cache_get_filename (const char *url);


#ifdef STK_CONFIG_MULTIPART



int
stk_cache_handle_multipart_resp (stk_trh_transaction_t *tra, 
                                 stk_cmgr_reply_t *p);
#endif
#endif
#endif

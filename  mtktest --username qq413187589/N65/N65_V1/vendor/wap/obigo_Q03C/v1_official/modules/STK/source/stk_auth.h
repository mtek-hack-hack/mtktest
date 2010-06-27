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












#ifndef _stk_stg_auth_h
#define _stk_stg_auth_h

#ifndef _stk_cmgr_h
#include "stk_cmgr.h"
#endif

#ifndef _stk_trdf_h
#include "stk_trdf.h"
#endif


#ifdef STK_CFG_AUTH_PERSISTENT_STORAGE
extern int stk_stg_auth_index_file; 
#endif





typedef struct tr_auth_rec_st tr_auth_rec_t;






void
tr_auth_init (void);

void
tr_auth_terminate (void);




void
tr_auth_add_authorization (stk_trh_transaction_t *tra);

void
tr_auth_add_proxy_authorization (stk_trh_transaction_t *tra);





int
tr_auth_handle_status_unauthorized (stk_trh_transaction_t *tra,
                                    stk_cmgr_reply_t *p,
                                    int proxy);






int
tr_auth_make_password_request (stk_trh_transaction_t *tra);





void
tr_auth_handle_password_response (stk_trh_transaction_t *tra,
                                  stk_auth_credentials_t *p);


void
tr_auth_delete_rec (tr_auth_rec_t *auth_rec);







void
tr_auth_proxy_credentials (stk_trh_proxy_t *cred, MSF_INT8 module_id);







void
tr_auth_delete_proxy_auth (void);






void
tr_auth_delete_host_auth (void);






void
tr_auth_delete_volatile_auth (MSF_UINT8 module_id);



void
stk_stg_auth_init (void);

void
stk_stg_auth_terminate (void);

int
stk_stg_auth_check_proxy_auth (msf_sockaddr_t addr, char **realm,
                               char **username, char **password);
int
stk_stg_auth_check_host_auth (char* url, char **realm,
                              char **username, char **password);
int
stk_stg_auth_store_proxy_auth (msf_sockaddr_t addr, char *realm,
                               char* username, char* password, int options);
int
stk_stg_auth_store_host_auth (char* url, char* realm, 
                              char* username, char* password, int options);
void
stk_stg_auth_delete_host_auth (void);

void
stk_stg_auth_delete_proxy_auth (void);


#ifdef STK_CFG_AUTH_PERSISTENT_STORAGE
void stk_stg_auth_run (void);
#endif

#endif

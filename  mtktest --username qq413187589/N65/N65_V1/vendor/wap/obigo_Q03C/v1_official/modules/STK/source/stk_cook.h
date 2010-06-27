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











#ifndef _stk_cook_h
#define _stk_cook_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif


#ifdef STK_CFG_COOKIE_PERSISTENT_STORAGE
extern int stk_cookie_index_file; 
#endif








typedef struct stk_cookie_handle_st {
  struct stk_cookie_list_st    *next, *last;
} stk_cookie_handle_t;












void
stk_cookie_extract_cookies (MSF_UINT8 module_id, char* url, hdr_table_t *headers);

void
stk_cookie_add_cookies (char* url, hdr_table_t *headers, int secure_conn);







































































int stk_cookie_store_cookie (MSF_UINT8 module_id, char* url, char* name, char* value, char* domain,
                             char* path, char* portList, MSF_UINT32* expires, 
                             MSF_UINT8 version_major, MSF_UINT8 version_minor, 
                             int discard, int port, int secure);

































int stk_cookie_check_cookies (stk_cookie_handle_t* handle, char* url);































int 
stk_cookie_get_next_cookie (stk_cookie_handle_t* handle, char** name,
                            char** value,  char** domain, char** path, 
                            char** portList, MSF_UINT8* version_major, 
                            MSF_UINT8* version_minor, int* port, int* secure);






void stk_cookie_delete_all_cookies (void);







void stk_cookie_check_cookie_list (int module_id);

















void stk_cookie_init (void);

void stk_cookie_terminate (void);

#ifdef STK_CFG_COOKIE_PERSISTENT_STORAGE
void stk_cookie_run (void);
#endif

#endif


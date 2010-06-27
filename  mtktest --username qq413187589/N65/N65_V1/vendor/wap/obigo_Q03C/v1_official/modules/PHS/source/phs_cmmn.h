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










#ifndef _phs_cmmn_h
#define _phs_cmmn_h

#include "phs_main.h"




void
phs_cmmn_widget_action (msf_widget_action_t *p); 





void
phs_cmmn_get_content_type (char *headers, MSF_UINT32 *content_type_int);

int
phs_cmmn_read_data_from_stream_to_buf (int stream_handle, phs_msg_list_t* msg);

void
phs_cmmn_build_buf_from_data_buf_list (phs_msg_list_t* msg);




int
phs_disp_start_whitelist_dialog (int mod_id, char* info);

void
phs_register_dialog (int phs_module, phs_dlg_t *dlg);

int
phs_deregister_dialog (phs_dlg_t *dlg);




const char*
phs_main_get_key_as_string (int key);
 
const char*
phs_main_get_path_as_string (int key);

int
phs_main_get_path_as_int (const char* path);

int
phs_main_get_key_as_int (const char* key);




phs_msg_list_t*
phs_find_msg_by_id (int id);

void
phs_delete_msg_from_list (int id);

#endif



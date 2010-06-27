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











#ifndef _brs_plh_h
#define _brs_plh_h

#ifndef  _brs_plg_h
#include "brs_plg.h"
#endif






#define BRS_PLH_MATCH_NONE                        1
#define BRS_PLH_MATCH_ANY                         2
#define BRS_PLH_MATCH_PARTIAL                     3
#define BRS_PLH_MATCH_EXACT                       4



#define BRS_PLH_SIG_CONTINUE                      BRS_MODULE_PLUGIN + 1

















void
brs_plh_init (void);




void
brs_plh_terminate (void);




int
brs_plh_request_url (int instance_id, int request_id,
                     const char *url, const char *fragment,
                     const char *headers);




int
brs_plh_process_content (int instance_id, const char *content_type,
                         char *url, char *fragment,
                         char *headers,
                         unsigned char *buf, long buflen, char *pipe_name,
                         void *doc);




int
brs_plh_run_wmls_func (int instance_id, int lib_index, int func_index,
                       int num_params, brs_plg_wmls_var_t *params);





void
brs_plh_abort_plugin (int instance_id);













int
brs_plh_check_for_plugin (char *descriptor, int plugin_type, brs_plg_info_t *info);









int
brs_plh_get_registered_content_types (int plugin_type, char *vec[], int max_size);









int 
brs_plh_handle_response_signal (int plugin_id, int signal, int value);

#endif

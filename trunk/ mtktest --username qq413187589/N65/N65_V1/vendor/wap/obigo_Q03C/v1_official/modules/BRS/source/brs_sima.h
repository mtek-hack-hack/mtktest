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










#ifndef _brs_sima_h
#define _brs_sima_h

#ifndef  _brs_ua_h
#include "brs_ua.h"
#endif
#ifdef BRS_CONFIG_PLUGIN
#ifndef  _brs_plg_h
#include "brs_plg.h"
#endif
#endif





#define BRS_WMLS_SIG_INVOKE_SCRIPT                BRS_MODULE_WMLS + 0
#define BRS_WMLS_SIG_REFRESH_DONE                 BRS_MODULE_WMLS + 1










#define BRS_WMLS_SIG_INVOKE_DONE                  BRS_MODULE_WMLS + 3
#define BRS_WMLS_SIG_REFRESH_REQ                  BRS_MODULE_WMLS + 4










#define BRS_WMLS_SIG_DIALOG_RESPONSE              BRS_MODULE_WMLS + 5
#define BRS_WMLS_SIG_TEXT_SIGNED                  BRS_MODULE_WMLS + 6











#define BRS_WMLS_SIG_FUNC_CALL                    BRS_MODULE_WMLS + 7
#define BRS_WMLS_SIG_FUNC_RESULT                  BRS_MODULE_WMLS + 8











#define BRS_WMLS_SIG_EXEC                         BRS_MODULE_WMLS + 9










typedef struct {
  int   instance_id;
  int   charset;
  int   stream;
  char *url;
  void *ua;
} brs_wmls_invoke_script_t;

typedef struct {
  int   instance_id;
  int   error_code;
  int   wml_prev;
  char *result_str;
  char *wml_go_url;
} brs_wmls_invoke_done_t;

#ifdef BRS_CONFIG_PLUGIN
typedef struct {
  int                 instance_id;
  int                 lib_index;
  int                 func_index;
  int                 num_params;
  brs_plg_wmls_var_t *params; 
} brs_wmls_func_call_t;
#endif









void
brs_wmls_init (void);




void
brs_wmls_terminate (void);




void
brs_wmls_abort_script (int instance_id);

#endif

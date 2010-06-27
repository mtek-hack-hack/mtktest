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
/*
 * brs_plti.c
 *
 * Created by Anders Edenbrandt, Fri Oct 12 14:06:00 2001.
 *
 * Plug-in for WTAI functionality.
 *
 * Revision history:
 *
 */
#include "brs_cfg.h"
#include "brs_plg.h"
#include "brs_if.h"
#include "stk_if.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msf_url.h"
#include "msf_lib.h"
#include "msf_tel.h"
#include "msf_core.h"
#include "msf_chrt.h"


/************************************************************
 * Constants
 ************************************************************/

#define BRS_WTAI_MAKE_CALL              0
#define BRS_WTAI_SEND_DTMF              1
#define BRS_WTAI_ADD_PB_ENTRY           2


/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int   r;
  char *result_var;
} brs_plti_result_t;


/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_plti_func_instantiate (brs_plg_t *pl);

static void
brs_plti_func_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plti_func_response (brs_plg_t *pl);

static void
brs_plti_uri_instantiate (brs_plg_t *pl);

static void
brs_plti_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plti_uri_response (brs_plg_t *pl);

static void
brs_plti_sig_response (brs_plg_t *pl, int signal, int value);

static void
brs_plti_delete (brs_plg_t *pl);

static int 
brs_plti_is_phone_number (char *number);

static int 
brs_plti_is_dtmf (char *dtmf);


/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plti_register (void)
{
  brs_plg_info_t info;

  /* Lib index = 512, and func index = 0, means WTAPublic.makeCall.
   * That function takes one parameter. */
  info.run_wmls_func.num_params = 1;
  brs_plg_register (BRS_PLG_TYPE_RUN_WMLS_FUNC,
                    "512/0", &info, brs_plti_func_instantiate);

  /* Lib index = 512, and func index = 1, means WTAPublic.sendDTMF.
   * That function takes one parameter. */
  info.run_wmls_func.num_params = 1;
  brs_plg_register (BRS_PLG_TYPE_RUN_WMLS_FUNC,
                    "512/1", &info, brs_plti_func_instantiate);

  /* Lib index = 512, and func index = 0, means WTAPublic.addPBEntry.
   * That function takes two parameters. */
  info.run_wmls_func.num_params = 2;
  brs_plg_register (BRS_PLG_TYPE_RUN_WMLS_FUNC,
                    "512/2", &info, brs_plti_func_instantiate);

  /* Also, register to handle the URI-versions: */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "wtai", NULL, brs_plti_uri_instantiate);

  /* Register to handle the "tel" scheme. */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "tel", NULL, brs_plti_uri_instantiate);
}

static void
brs_plti_func_instantiate (brs_plg_t *pl)
{
  brs_plti_result_t *res;

  pl->pl_request = brs_plti_func_request;
  pl->pl_delete = brs_plti_delete;
  pl->pl_run = brs_plti_func_response;
  pl->pl_sig_response = brs_plti_sig_response;

  res = brs_plg_alloc (sizeof (brs_plti_result_t));
  res->r = 0;
  res->result_var = NULL;
  pl->pl_data = res;
}

static void
brs_plti_uri_instantiate (brs_plg_t *pl)
{
  brs_plti_result_t *res;

  pl->pl_request = brs_plti_uri_request;
  pl->pl_delete = brs_plti_delete;
  pl->pl_run = brs_plti_uri_response;
  pl->pl_sig_response = brs_plti_sig_response;

  res = brs_plg_alloc (sizeof (brs_plti_result_t));
  res->r = 0;
  res->result_var = NULL;
  pl->pl_data = res;
}

static void
brs_plti_delete (brs_plg_t *pl)
{
  brs_plti_result_t *res = pl->pl_data;

  if (res != NULL) {
    brs_plg_free (res->result_var);
    brs_plg_free (res);
  }
}

static void
brs_plti_func_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  int                 num_params = req->run_wmls_func.num_params;
  brs_plg_wmls_var_t *params = req->run_wmls_func.params;
  int                 r = 0;

  switch (req->run_wmls_func.func_index) {
  case BRS_WTAI_MAKE_CALL:
    if ((params == NULL) || (num_params != 1)) {
      r = 1;
    }
    else if  ((params[0].type != BRS_PLG_WMLS_VAR_STRING) ||
              !brs_plti_is_phone_number (params[0]._u.s_val.s)) {
      r = 2;
    }
    else {
      MSF_TEL_MAKE_CALL (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), params[0]._u.s_val.s);
    }
    break;

  case BRS_WTAI_SEND_DTMF:
    if ((params == NULL) || (num_params != 1)) {
      r = 1;
    }
    else if  ((params[0].type != BRS_PLG_WMLS_VAR_STRING) ||
              !brs_plti_is_dtmf (params[0]._u.s_val.s)) {
      r = 2;
    }
    else {
      MSF_TEL_SEND_DTMF (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), params[0]._u.s_val.s);
    }
    break;

    case BRS_WTAI_ADD_PB_ENTRY:
    if ((params == NULL) || (num_params != 2)) {
      r = 1;
    }
    else if  ((params[0].type != BRS_PLG_WMLS_VAR_STRING) ||
              !brs_plti_is_phone_number (params[0]._u.s_val.s) ||
              (params[1].type != BRS_PLG_WMLS_VAR_STRING)) {
      r = 2;
    }
    else {
      MSF_PB_ADD_ENTRY (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id),
                        params[1]._u.s_val.s, params[0]._u.s_val.s);
    }
    break;
  }

  brs_plg_wmlsvar_array_delete (num_params, params);

  if (r == 1) {
    brs_plg_abort (pl, BRS_ERROR_WMLS_INTERPRETING);
  }
  else if (r == 2) {
    brs_plti_result_t *res = pl->pl_data;
    
    res->r = 1;
    brs_plti_func_response (pl);
  }
}

/*
 * Deliver the response from the WMLScript function call.
 */
static void
brs_plti_func_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  res;
  brs_plg_wmls_var_t      *result;
  brs_plti_result_t       *p = pl->pl_data;
  int                      r = 1;

  if (p != NULL)
    r = p->r;

  result = brs_plg_alloc (sizeof (brs_plg_wmls_var_t));

  if (r > 0) {
    result->type = BRS_PLG_WMLS_VAR_INVALID;
  }
  else if (r == 0) {
    result->type = BRS_PLG_WMLS_VAR_STRING;
    result->_u.s_val.charset = MSF_CHARSET_UTF_8;
    result->_u.s_val.s_len = 0;
    result->_u.s_val.s = msf_cmmn_strdup (MSF_MODID_BRS, "");
  }
  else {
    result->type = BRS_PLG_WMLS_VAR_INTEGER;
    result->_u.i_val = r;
  }

  res.run_wmls_func.status_code = BRS_PLG_STATUS_OK;
  res.run_wmls_func.result = result;
  brs_plg_response (pl, &res);
  brs_plg_done (pl);
}

static void
brs_plti_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  brs_plti_result_t *res;
  char              *lib_name = NULL;
  char              *func_name = NULL;
  char              *param1 = NULL;
  char              *param2 = NULL;
  char              *result_var = NULL;
  char              *tmp;
  int                func_index = -1;
  int                isTELscheme = 0;

  /* Check the scheme of the url */
  tmp = msf_url_get_scheme (MSF_MODID_BRS, req->request_url.url);
  if (msf_cmmn_strcmp_nc (tmp, "tel") == 0)
  {
    /* a "tel" scheme */
    isTELscheme = 1;
  }
  brs_plg_free (tmp);

  lib_name = msf_url_get_host (MSF_MODID_BRS, req->request_url.url);
  if (isTELscheme == 0 && ((lib_name == NULL) || msf_cmmn_strcmp_nc (lib_name, "wp")))
  {
    goto err_return;
  }

  if (isTELscheme == 0)
  {
      tmp = msf_url_get_path (MSF_MODID_BRS, req->request_url.url);
      if (tmp == NULL)
        goto err_return;
      msf_cmmn_strcpy_lc (tmp, tmp + 1);
      func_name = msf_url_unescape_string (MSF_MODID_BRS, tmp);
      brs_plg_free (tmp);

      if (!msf_cmmn_strcmp_nc (func_name, "mc"))
        func_index = BRS_WTAI_MAKE_CALL;
      else if (!msf_cmmn_strcmp_nc (func_name, "sd"))
        func_index = BRS_WTAI_SEND_DTMF;
      else if (!msf_cmmn_strcmp_nc (func_name, "ap"))
        func_index = BRS_WTAI_ADD_PB_ENTRY;

      if (func_index < 0)
        goto err_return;

      res = pl->pl_data;
      param1 = msf_url_get_parameters (MSF_MODID_BRS, req->request_url.url);
      if (param1 == NULL)
        goto err_return;

      result_var = strchr (param1, '!');
      if (result_var != NULL)
      {
        *result_var = '\0';
        result_var++;
        res->result_var = msf_url_unescape_string (MSF_MODID_BRS, result_var);
      }
      else
      {
        res->result_var = NULL;
      }
  }
  else
  {
      /* "tel" scheme is used to make call */
      func_index = BRS_WTAI_MAKE_CALL;

      res = pl->pl_data;

      /* Get the phone number */
      param1 = msf_url_get_path (MSF_MODID_BRS, req->request_url.url);
	  if (param1 == NULL)
        goto err_return;
      tmp = msf_cmmn_skip_blanks(param1);
      msf_cmmn_strcpy_lc (param1, tmp);

      res->result_var = NULL;
  }

  switch (func_index) {
  case BRS_WTAI_MAKE_CALL:
    tmp = msf_url_unescape_string (MSF_MODID_BRS, param1);
    brs_plg_free (param1);
    param1 = tmp;
    if (!brs_plti_is_phone_number (param1))
      goto err_return;
    MSF_TEL_MAKE_CALL (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param1);
    break;

  case BRS_WTAI_SEND_DTMF:
    tmp = msf_url_unescape_string (MSF_MODID_BRS, param1);
    brs_plg_free (param1);
    param1 = tmp;
    if (!brs_plti_is_dtmf (param1))
      goto err_return;
    MSF_TEL_SEND_DTMF (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param1);
    break;

  case BRS_WTAI_ADD_PB_ENTRY:
    param2 = strchr (param1, ';');
    if (param2 != NULL)
	{
		*param2 = '\0';
		param2 = msf_url_unescape_string (MSF_MODID_BRS, param2 + 1);
	}
	else
	{
		param2 = msf_cmmn_strdup(MSF_MODID_BRS, (const char *)"");
	}
    tmp = msf_url_unescape_string (MSF_MODID_BRS, param1);
    brs_plg_free (param1);
    param1 = tmp;
    if (!brs_plti_is_phone_number (param1))
      goto err_return;
    /* JWO 031015; corrected the order of the parameters; param1 is the number
     * and param2 is the name; thus the order in the call below must be 
     * first param2 and then param1. This fixes TR13127.
     */
    MSF_PB_ADD_ENTRY (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param2, param1);
    break;
  }

  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (lib_name);
  brs_plg_free (func_name);
  brs_plg_free (param1);
  brs_plg_free (param2);
  return;

 err_return:
  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (lib_name);
  brs_plg_free (func_name);
  brs_plg_free (param1);
  brs_plg_free (param2);
  brs_plg_abort (pl, STK_ERR_INVALID_URL);
}

static void
brs_plti_uri_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  ret;
  brs_plti_result_t       *res = pl->pl_data;
  char                     buf[10];

  if ((res != NULL) && (res->result_var != NULL))
  {
    if (res->r == 0) {
      buf[0] = '\0';
    }
    else {
      sprintf (buf, "%d", res->r);
    }
    brs_plg_set_wml_variable (pl, res->result_var, buf);
  }

  ret.request_url.headers = NULL;
  ret.request_url.status_code = BRS_PLG_STATUS_NO_NAVIGATION;

  brs_plg_response (pl, &ret);
  brs_plg_done (pl);
}

static void
brs_plti_sig_response (brs_plg_t *pl, int signal, int value)
{
  brs_plti_result_t *res = pl->pl_data;

  signal = signal;
  res->r = value;
  brs_plg_schedule (pl);
}

static int 
brs_plti_is_phone_number (char *number)
{
  char *p = number;

  if (number == NULL)
    return 0;

  if (*p == '+')
    p++;

  if (*p == '\0')
    return 0;

  while (*p != '\0') {
    if (!ct_isdigit (*p))
      return 0;
    p++;
  }

  return 1;
}

static int 
brs_plti_is_dtmf (char *dtmf)
{
  char *p = dtmf;

  if ((dtmf == NULL) || (*p == '\0'))
    return 0;

  while (*p != '\0') {
    if((!ct_isdigit (*p)) &&
       (*p != 'A') &&
       (*p != 'B') &&
       (*p != 'C') &&
       (*p != 'D') &&
       (*p != '*') &&
       (*p != '#') &&
       (*p != ','))
      return 0;
    p++;
  }

  return 1;
}

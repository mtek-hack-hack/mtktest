
/*
 * brs_plsms.c
 *
 * Created by Derek Chen.
 *
 * Plug-in for SMS functionality.
 *
 * Revision history:
 *
 */

#include "brs_cfg.h"
#include "brs_plg.h"
#include "brs_if.h"
#include "bra_if.h"
#include "stk_if.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msf_url.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_chrt.h"


/************************************************************
 * Constants
 ************************************************************/


/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int   r;
} brs_plsms_result_t;

/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_plsms_uri_instantiate (brs_plg_t *pl);

static void
brs_plsms_delete (brs_plg_t *pl);

static void
brs_plsms_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plsms_uri_response (brs_plg_t *pl);

static void
brs_plsms_sig_response (brs_plg_t *pl, int signal, int value);

static int
brs_plsms_is_phone_number (char *number);

/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plsms_register (void)
{
  /* Register to handle the sms scheme: */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "sms", NULL, brs_plsms_uri_instantiate);
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "smsto", NULL, brs_plsms_uri_instantiate);
}

static void
brs_plsms_uri_instantiate (brs_plg_t *pl)
{
  brs_plsms_result_t *res;

  pl->pl_request = brs_plsms_uri_request;
  pl->pl_delete = brs_plsms_delete;
  pl->pl_run = brs_plsms_uri_response;
  pl->pl_sig_response = brs_plsms_sig_response;

  res = brs_plg_alloc (sizeof (brs_plsms_result_t));
  res->r = 0;
  pl->pl_data = res;
}


static void
brs_plsms_delete (brs_plg_t *pl)
{
  brs_plsms_result_t *res = pl->pl_data;

  if (res != NULL) {
    brs_plg_free (res);
  }
}


static void
brs_plsms_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  char              *param1 = NULL;
  char              *tmp;

  /* Get the phone number */
  param1 = msf_url_get_path (MSF_MODID_BRS, req->request_url.url);
  if (param1 == NULL)
    goto err_return;
  tmp = msf_cmmn_skip_blanks(param1);
  msf_cmmn_strcpy_lc (param1, tmp);

  /* Send a SMS to the number */
  tmp = msf_url_unescape_string (MSF_MODID_BRS, param1);
  brs_plg_free (param1);
  param1 = tmp;
  if (!brs_plsms_is_phone_number (param1))
    goto err_return;
  BRAif_smsSend (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param1);

  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plsms_sig_response(pl, 0, HDI_TEL_ERROR_UNSPECIFIED);
  return;

 err_return:
  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plg_abort (pl, STK_ERR_INVALID_URL);
}

static void
brs_plsms_uri_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  ret;

  ret.request_url.headers = NULL;
  ret.request_url.status_code = BRS_PLG_STATUS_NO_NAVIGATION;

  brs_plg_response (pl, &ret);
  brs_plg_done (pl);
}

static void
brs_plsms_sig_response (brs_plg_t *pl, int signal, int value)
{
  brs_plsms_result_t *res = pl->pl_data;

  signal = signal;
  res->r = value;
  brs_plg_schedule (pl);
}


static int
brs_plsms_is_phone_number (char *number)
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



/*
 * brs_plege.c
 *
 * Created by Derek Chen.
 *
 * Plug-in for EGE functionality.
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

#ifdef __SUPPORT_INFUSIO__
/************************************************************
 * Constants
 ************************************************************/


/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int   r;
} brs_plege_result_t;

/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_plege_uri_instantiate (brs_plg_t *pl);

static void
brs_plege_delete (brs_plg_t *pl);

static void
brs_plege_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plege_uri_response (brs_plg_t *pl);

static void
brs_plege_sig_response (brs_plg_t *pl, int signal, int value);

/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plege_register (void)
{
  /* Register to handle the ege scheme: */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "ege", NULL, brs_plege_uri_instantiate);
}

static void
brs_plege_uri_instantiate (brs_plg_t *pl)
{
  brs_plege_result_t *res;

  pl->pl_request = brs_plege_uri_request;
  pl->pl_delete = brs_plege_delete;
  pl->pl_run = brs_plege_uri_response;
  pl->pl_sig_response = brs_plege_sig_response;

  res = brs_plg_alloc (sizeof (brs_plege_result_t));
  res->r = 0;
  pl->pl_data = res;
}


static void
brs_plege_delete (brs_plg_t *pl)
{
  brs_plege_result_t *res = pl->pl_data;

  if (res != NULL) {
    brs_plg_free (res);
  }
}


static void
brs_plege_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  char              *param1 = NULL;
  char              *tmp;

  /* Get the ege parameter */
  param1 = msf_url_get_host (MSF_MODID_BRS, req->request_url.url);
  if (param1 == NULL)
    goto err_return;
  tmp = msf_cmmn_skip_blanks(param1);
  msf_cmmn_strcpy_lc (param1, tmp);

  /* Send the parameter to Eureka! Client (EGE handler) */
  /*
  tmp = msf_url_unescape_string (MSF_MODID_BRS, param1);
  brs_plg_free (param1);
  param1 = tmp;
  */
  /* We do not validate the parameter here.
     Just pass the parameter to EGE handler. */
  BRAif_egeSend (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param1);

  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plege_sig_response(pl, 0, HDI_TEL_ERROR_UNSPECIFIED);
  return;

 err_return:
  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plg_abort (pl, STK_ERR_INVALID_URL);
}

static void
brs_plege_uri_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  ret;

  ret.request_url.headers = NULL;
  ret.request_url.status_code = BRS_PLG_STATUS_NO_NAVIGATION;

  brs_plg_response (pl, &ret);
  brs_plg_done (pl);
}

static void
brs_plege_sig_response (brs_plg_t *pl, int signal, int value)
{
  brs_plege_result_t *res = pl->pl_data;

  signal = signal;
  res->r = value;
  brs_plg_schedule (pl);
}

#endif	/* __SUPPORT_INFUSIO__ */

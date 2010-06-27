
/*
 * brs_plrtsp.c
 *
 * Created by Derek Chen.
 *
 * Plug-in for Streaming functionality.
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

#ifdef STREAM_SUPPORT
/************************************************************
 * Constants
 ************************************************************/


/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int   r;
} brs_plrtsp_result_t;

/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_plrtsp_uri_instantiate (brs_plg_t *pl);

static void
brs_plrtsp_delete (brs_plg_t *pl);

static void
brs_plrtsp_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plrtsp_uri_response (brs_plg_t *pl);

static void
brs_plrtsp_sig_response (brs_plg_t *pl, int signal, int value);


/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plrtsp_register (void)
{
  /* Register to handle the rtsp scheme: */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "rtsp", NULL, brs_plrtsp_uri_instantiate);
}

static void
brs_plrtsp_uri_instantiate (brs_plg_t *pl)
{
  brs_plrtsp_result_t *res;

  pl->pl_request = brs_plrtsp_uri_request;
  pl->pl_delete = brs_plrtsp_delete;
  pl->pl_run = brs_plrtsp_uri_response;
  pl->pl_sig_response = brs_plrtsp_sig_response;

  res = brs_plg_alloc (sizeof (brs_plrtsp_result_t));
  res->r = 0;
  pl->pl_data = res;
}


static void
brs_plrtsp_delete (brs_plg_t *pl)
{
  brs_plrtsp_result_t *res = pl->pl_data;

  if (res != NULL) {
    brs_plg_free (res);
  }
}


static void
brs_plrtsp_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  char              *param1 = NULL;

  /* Send the rtsp url to the streaming app */
  param1 = msf_url_unescape_string (MSF_MODID_BRS, req->request_url.url);
  if (param1 == NULL)
    goto err_return;

  BRAif_rtspSend (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param1);

  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plrtsp_sig_response(pl, 0, HDI_TEL_ERROR_UNSPECIFIED);
  return;

err_return:
  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plg_abort (pl, STK_ERR_INVALID_URL);
}

static void
brs_plrtsp_uri_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  ret;

  ret.request_url.headers = NULL;
  ret.request_url.status_code = BRS_PLG_STATUS_NO_NAVIGATION;

  brs_plg_response (pl, &ret);
  brs_plg_done (pl);
}

static void
brs_plrtsp_sig_response (brs_plg_t *pl, int signal, int value)
{
  brs_plrtsp_result_t *res = pl->pl_data;

  signal = signal;
  res->r = value;
  brs_plg_schedule (pl);
}

#endif	/* End of STREAM_SUPPORT */

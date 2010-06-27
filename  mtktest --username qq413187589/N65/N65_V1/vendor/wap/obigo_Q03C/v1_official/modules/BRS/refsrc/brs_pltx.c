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
 * brs_pltx.c
 *
 * Created by Anders Edenbrandt, Mon May 21 17:17:30 2001.
 *
 * Revision history:
 *   021023, AED: Modified for Mobile Suite 2.0
 *
 */
/************************************************************
 * Parser plug-in for the content-type "text/plain".
 ************************************************************/
#include "brs_cfg.h"

#ifdef BRS_CONFIG_PLUGIN
#include "msf_cmmn.h"
#include "msf_hdr.h"
#include "msf_lib.h"
#include "msf_url.h"

#include "brs_ddt.h"
#include "brs_hdef.h"
#include "brs_if.h"
#include "brs_plg.h"
#include "brs_ua.h"


/************************************************************
 * Constants
 ************************************************************/

#define MAX_LINES_TO_READ               5
#define CHR_CR                          0x0d
#define CHR_LF                          0x0a
#define BRS_PLTX_BUF_MAX_SIZE			512

/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  void *doc;
} brs_pltx_data_t;


/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_pltx_instantiate (brs_plg_t *pl);

static void
brs_pltx_parse (brs_plg_t *pl);

static void
brs_pltx_delete (brs_plg_t *pl);

static void
brs_pltx_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_pltx_add_charNode (brs_plg_t *pl, char *buf, int pos);

/************************************************************
 * Function definitions
 ************************************************************/

void
brs_pltx_register (void)
{
  brs_plg_info_t info;

  info.proc_cont.empty = 0;
  brs_plg_register (BRS_PLG_TYPE_PROCESS_CONTENT,
                    "text/plain", &info, brs_pltx_instantiate);
}

static void
brs_pltx_instantiate (brs_plg_t *pl)
{
  pl->pl_request = brs_pltx_request;
  pl->pl_delete = brs_pltx_delete;
  pl->pl_run = NULL;
  pl->pl_sig_response = NULL;
  pl->pl_data = brs_plg_alloc (sizeof (brs_pltx_data_t));
}

static void
brs_pltx_delete (brs_plg_t *pl)
{
  brs_plg_free (pl->pl_data);
}

static void
brs_pltx_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  char       *chrs;
  int         charset;
  msf_hdr_t  *hdr = msf_hdr_create (MSF_MODID_BRS);

  brs_plg_free (req->proc_cont.url);
  brs_plg_free (req->proc_cont.fragment);

  msf_hdr_add_headers_from_text (hdr, req->proc_cont.headers);
  chrs = msf_hdr_get_parameter (hdr, MSF_HDR_CONTENT_TYPE, "charset");

  if (chrs != NULL) {
    charset = msf_charset_str2int (chrs, strlen (chrs));
    if (charset <= 0)
      charset = MSF_CHARSET_UNKNOWN;
    brs_plg_free (chrs);
  }
  else
    charset = MSF_CHARSET_LATIN_1;
  msf_hdr_delete (hdr);
  brs_plg_free (req->proc_cont.headers);

  if ((charset != MSF_CHARSET_UTF_8) && (charset != MSF_CHARSET_UNKNOWN)) {
    brs_plg_source_attach_read_filter (pl, 0, charset);
  }

#if 1
  { 
    brs_dt_tree_node_t *new_node;
    brs_ua_document_t  *bdoc;

    bdoc = req->proc_cont.doc;
    ((brs_pltx_data_t *)(pl->pl_data))->doc = bdoc;

    /* Create root node in tree */
    bdoc->doc.tree_root = brs_dt_new_element_node (BRS_HTML_ELEMENT_HTML, NULL, 0,
                                                   &(bdoc->doc));
  
    /* Create BODY node in tree */
    new_node = brs_dt_new_element_node (BRS_HTML_ELEMENT_BODY, NULL, 0,
                                        &(bdoc->doc));
    brs_dt_add_content (bdoc->doc.tree_root, new_node);
    bdoc->body_or_card = new_node;
    bdoc->doc.current_node = new_node;
  }
#endif

  pl->pl_run = brs_pltx_parse;
  brs_plg_schedule (pl);
}

static void
brs_pltx_parse (brs_plg_t *pl)
{
  static char            buf[BRS_PLTX_BUF_MAX_SIZE];
  static int             buf_len = 0;
  int                    i, r;
  int                    pos, next_pos;
  int                    done = FALSE;
  brs_plg_response_data_t res;

  for (i = 0; i < MAX_LINES_TO_READ; i++) {

    if (done)
      break;

    /* Search for end-of-line */
  try_again:
    next_pos = 0;
    for (pos = 0; pos < buf_len; pos++) {
      if (buf[pos] == CHR_CR) {
        if ((pos + 1 < buf_len) && (buf[pos + 1] == CHR_LF))
          next_pos = pos + 2;
        else
          next_pos = pos + 1;
        break;
      }
      else if (buf[pos] == CHR_LF) {
        next_pos = pos + 1;
        break;
      }
    }

    if (next_pos == 0) {
      r = brs_plg_source_read (pl, 0, buf + buf_len, BRS_PLTX_BUF_MAX_SIZE - buf_len);
      if (r > 0) {
        buf_len += r;
        if (buf_len == BRS_PLTX_BUF_MAX_SIZE){
          brs_pltx_add_charNode (pl, &(buf[0]), buf_len);        
          buf_len = 0;
        }
        goto try_again;
      }
      else if (r == BRS_PLG_ERROR_DELAYED)
        return;
      else if (r == BRS_PLG_ERROR_EOF) {
        done = TRUE;
        if (pos == 0)
          break;
      }
      else {
		if (r == 0 && ((BRS_PLTX_BUF_MAX_SIZE - buf_len) <= 1)) {
		  brs_pltx_add_charNode (pl, &(buf[0]), buf_len);        
          buf_len = 0;
		  goto try_again;
		}
		else
		{
          brs_plg_abort (pl, BRS_ERROR_UNEXPECTED_END_OF_DOC);      
          return;
		}
      }
    }

    /* Add a node to the tree, */
#if 1
    { 
      brs_dt_tree_node_t *new_node;
      brs_ua_document_t  *bdoc = ((brs_pltx_data_t *)(pl->pl_data))->doc;
      brs_pltx_add_charNode (pl, &(buf[0]), pos);

      memmove (buf, buf + next_pos, buf_len - next_pos);
      buf_len -= next_pos;

      /* Add a <br/> node */
      
      new_node = brs_dt_new_element_node (BRS_HTML_ELEMENT_BR, NULL, 0, &(bdoc->doc));
      brs_dt_add_next (bdoc->doc.current_node, new_node);
      bdoc->doc.current_node = new_node;
    }
#endif
  }

  if (done) {
    brs_ua_document_t *bdoc = ((brs_pltx_data_t *)(pl->pl_data))->doc;

    bdoc->doc.state = TreeComplete_s;

    buf_len = 0;
    res.proc_cont.status_code = BRS_PLG_STATUS_OK;
    brs_plg_response (pl, &res);
    brs_plg_done (pl);
  }
  else
    brs_plg_schedule (pl);
}

static void
brs_pltx_add_charNode (brs_plg_t *pl, char *buf, int pos){
  brs_dt_tree_node_t *new_node;
  brs_ua_document_t  *bdoc = ((brs_pltx_data_t *)(pl->pl_data))->doc;
  char               *wd = msf_cmmn_strndup (MSF_MODID_BRS, buf, pos);

  new_node = brs_dt_new_chardata_node (wd, BRS_DT_CDATA_PRSV_NODE,
                                       &(bdoc->doc));

  if (bdoc->doc.current_node->parent == bdoc->doc.tree_root) {
    brs_dt_add_content (bdoc->doc.current_node, new_node);
    bdoc->doc.current_node = new_node;
  }
  else {
    brs_dt_add_next (bdoc->doc.current_node, new_node);
    bdoc->doc.current_node = new_node;
  }
}
#endif


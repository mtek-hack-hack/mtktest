/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
/*
 * bra_sif.c
 *
 * This file contain the BRA Services Interface, E.g. the functionality
 * needed to handle signals from BRS is ipmlemented here
 * internal signal receive funtion.
 *
 */
#include "bra_cfg.h"
#include "bra_cmn.h"
#include "bra_str.h"
#include "bra_main.h"
#include "bra_sig.h"
#include "bra_sif.h"
#include "bra_win.h"
#include "bra_req.h"
#include "bra_dlg.h"
#include "bra_view.h"
#include "bra_opt.h"
#include "bra_rpl.h"
#include "bra_inse.h"
#include "bra_act.h"
#include "bra_prof.h"
#include "bra_if.h"

#include "brs_if.h"
#include "brs_env.h"

#include "msf_lib.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_url.h"  

#ifdef BRA_CONFIG_SECURITY
#include "sec_if.h"
#endif

#ifdef BRA_CFG_SELECT_MODE
#include "bra_slct.h"
#endif

#ifdef BRA_CFG_OFFLINE_PAGES
#include "bra_ofln.h"
#endif

#include "l3_inc_enums.h"
#include "ppp_l4_enums.h"
#include "wap_ps_struct.h"

#include "widget_extension.h"
/******************************************************************************
 * Local Defines
 ******************************************************************************/

#define  BRA_SIF_INITIAL_VIEWPORT_POS_X   0
#ifdef BRA_CFG_DISPLAY_TITLE
#define  BRA_SIF_INITIAL_VIEWPORT_POS_Y   20
#else
#define  BRA_SIF_INITIAL_VIEWPORT_POS_Y   0
#endif

/******************************************************************************
 * Global variables
 ******************************************************************************/

static int bra_sif_brs_status;
static int bra_sif_instance_id;
static int bra_sif_socket_id;
#ifdef BRA_CONFIG_SECURITY
static int bra_sif_sec_info = 0;
static int bra_sif_sec_cert = 0;
static MSF_INT32 bra_sif_security_id = -1;
#endif

#ifdef BRA_CFG_SELECT_MODE
static int bra_sif_select_mode; /* 0: select mode off, 1: select mode on */
#endif

#ifdef BRA_CFG_PROF_FALLBACK
//int bra_pending_bearer_switch = 0;
#define BRA_SIF_MAX_THRU_COUNT	3
int bra_sif_fallback_state = BRA_SIF_FBSTATE_NONE;
int bra_sif_gprs_bearer_state = BRA_SIF_BR_STATE_UNKNOWN;
int bra_sif_switch_to_bearer = -1;
int bra_sif_fallback_do_reload = 0;
int bra_sif_fallback_thru_count = 0;
void bra_sif_prompt_bearer_switch (int new_bearer, int do_reload);
static void bra_sif_fallback_switch_while_loading(void);
#endif

/******************************************************************************
 * Exported Functions
 *****************************************************************************/
/*
 * Initializes the variables used in this file.
 *
 * PARAMETERS
 * 
 * RETURN    : void
 */
void
bra_sif_init (void)
{
  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_DD27322128A77DF7BBA9017D0EB23AB1, "BRA: bra_sif_init()\n"));
#ifdef BRA_CFG_SELECT_MODE
  bra_sif_select_mode = 0; /* 0: select mode off, 1: select mode on */
#endif
#ifdef BRA_CFG_PROF_FALLBACK
  bra_sif_fallback_state = BRA_SIF_FBSTATE_NONE;
  //bra_sif_gprs_bearer_state = BRA_SIF_BR_STATE_UNKNOWN;
  bra_sif_switch_to_bearer = -1;
  bra_sif_fallback_do_reload = 0;
  bra_sif_fallback_thru_count = 0;
#endif
}

/*
 * This function returns the Socket id used for the current request 
 *
 * PARAMETERS
 *
 * RETURN    : Socket id
 */
int 
bra_sif_get_socket_id (void)
{
  return bra_sif_socket_id;
}

#ifdef BRA_CONFIG_SECURITY
/*
 * This function is called in response to a previous request to the Security 
 * package to return the currently used security class
 *
 * PARAMETERS
 *
 * sec_class : The currently used security class
 * info_available: Indicates if session info is available.
 * cert_available: Indicates if certificate for session is available.
 *
 * RETURN    : void
 */
void 
bra_sif_set_security_class (int sec_class, int info_available, int cert_available)
{
  bra_view_set_secure_icon (sec_class);

  bra_sif_sec_info = info_available;
  bra_sif_sec_cert = cert_available;
}

int
bra_sif_sec_info_available (void)
{
  return bra_sif_sec_info;
}

int
bra_sif_sec_cert_available (void)
{
  return bra_sif_sec_cert;
}

int
bra_sif_get_security_id (void)
{
  return bra_sif_security_id;
}
#endif

/*
 * This function is used to set the assumed state of the BRS
 *
 * PARAMETERS
 *
 * status    : Current state as defined above
 *
 * RETURN    : void
 */
void
bra_sif_set_brs_status (int status)
{
	bra_sif_brs_status = status;
}

/*
 * Returns the currently assumed BRS state
 *
 * PARAMETERS
 *
 * RETURN    : BRS state
 */
int
bra_sif_get_brs_status (void)
{
	return bra_sif_brs_status;
}

/*
 * This function is used to get the object Id previously returned in
 * a request to instantiate the BRS
 *
 * PARAMETERS
 *
 * RETURN    :
 */
int
bra_sif_get_brs_id (void)
{
	return bra_sif_instance_id;
}

/*
 * This function must be called when BRA receives the signal that BRS is 
 * active. a request to create an instance of the BRS is made.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_active (void)
{  
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  bra_sif_set_brs_status (BRA_SIF_BRS_ACTIVE);

  BRSif_createInstance (MSF_MODID_BRA,
                        bra_win_get_screen(),
                        BRA_SIF_INITIAL_VIEWPORT_POS_X, 
                        BRA_SIF_INITIAL_VIEWPORT_POS_Y,
                        prop.displaySize.height -  BRA_SIF_INITIAL_VIEWPORT_POS_Y, 
                        prop.displaySize.width -  BRA_SIF_INITIAL_VIEWPORT_POS_X,
                        "BRA");
  
  bra_sif_set_brs_status (BRA_SIF_BRS_CREATING);

}

/*
 * This function must be called when a request to instantiate the BRS has
 * returned. If there is a pending request this will be isued now.
 *
 * PARAMETERS
 *
 * p         : Pointer to signal structure
 *
 * RETURN    : void
 */ 
void
bra_sif_brs_create_responce (void *p)
{
  char* url;
  int id;
  int error;
  MsfWindowHandle paintbox;
    
  id    = (unsigned long int)((brs_created_t *)p)->instanceId, 
  error = (unsigned long int)((brs_created_t *)p)->errorCode;
  paintbox = (unsigned long int)((brs_created_t *)p)->paintBox;

  if (error < 0)
  {
    /*Handle error*/
    return;
  }

  /*Set brs status variable to Active*/
  bra_sif_set_brs_status (BRA_SIF_BRS_CREATED);
  
  bra_view_set_paintbox_handle(paintbox);

  bra_sif_instance_id = id;

  bra_sif_socket_id = 0;  

  //Q03C1
  //BRSif_navigationChange (MSF_MODID_BRA, bra_sif_get_brs_id(), BRS_MARKABLE_ELEMENT_DEFAULT|BRS_MARKABLE_ELEMENT_IMG|BRS_MARKABLE_ELEMENT_OBJECT);
    
  /*If there is a pending request, send it*/
  if((url = bra_req_get_request_url ()) != NULL)
    bra_send_request(url);

  if (bra_ofln_page_has_page_to_delete() == TRUE)
  {
      bra_ofln_page_delete_pending_page();
  }

  MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, BRS_SIG_CREATED, p);
}

/*
 * This function should be called when the BRS has terminated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_terminated (void)
{
  bra_sif_set_brs_status (BRA_SIF_BRS_NOT_ACTIVE);
  BRSc_kill();

}

/*
 * This function will call the MSF macros to try and start the BRS module
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_sif_start_brs (void)
{  		
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  if (bra_sif_brs_status == BRA_SIF_BRS_NOT_ACTIVE)
  {
    BRSif_startInterface ();
    MSF_MODULE_START(MSF_MODID_BRA, MSF_MODID_BRS,"", NULL, NULL);
    bra_sif_set_brs_status (BRA_SIF_BRS_ACTIVATED);
  }
  else if (bra_sif_brs_status == BRA_SIF_BRS_ACTIVE)
  {
    BRSif_createInstance (MSF_MODID_BRA,
                          bra_win_get_screen(),
                          BRA_SIF_INITIAL_VIEWPORT_POS_X, 
                          BRA_SIF_INITIAL_VIEWPORT_POS_Y,
                          prop.displaySize.height -  BRA_SIF_INITIAL_VIEWPORT_POS_Y, 
                          prop.displaySize.width -  BRA_SIF_INITIAL_VIEWPORT_POS_X,
                          "BRA");
    bra_sif_set_brs_status (BRA_SIF_BRS_CREATING);
  }

  /*Else the initialization proces is already started*/
}

/*
 * This function is called when the BRA receives a status notificatoin from 
 * the BRS. This information is used to update the status bar.
 *
 * PARAMETERS
 *
 * p         : Pointer to status structure (brs_status_t)
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_status (void *p )
{

  switch (((brs_status_t *)p)->status)
  {
  case BRS_STATUS_START_TRANSACTION:       
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_B96421CCDA949C60AD5F80783964F162, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_START_TRANSACTION)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    bra_create_status_bar ();
#ifdef BRA_CFG_PROF_FALLBACK
    bra_sif_fallback_state = BRA_SIF_FBSTATE_CONNECTING;
#endif
    break;
  case BRS_STATUS_END_TRANSACTION:         
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_1D43514EE8ADC364380089B518D8FBE5, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_END_TRANSACTION)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    bra_view_delete_status ();
#ifdef BRA_CFG_PROF_FALLBACK
    if (!bra_sif_is_pending_bearer_switch())
      bra_sif_fallback_state = BRA_SIF_FBSTATE_NONE;
#endif
#ifdef BRA_CFG_OFFLINE_PAGES
    if(bra_ofln_offline_mode() == 1)
    {
      bra_ofln_set_offline_mode(FALSE);
      bra_ofln_reset_offline_state();
    }
#endif    
    break;
  case BRS_STATUS_LOADING_DOCUMENT:        
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_4ABD51C55210D348585660886768123F, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_DOCUMENT)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));    
    bra_view_new_object (BRA_STR_LOADING_DOC, ((brs_status_t *)p)->url);

#ifdef BRA_CFG_PROF_FALLBACK
    if (((brs_status_t*)p)->url) 
    {
      char    *url;
      int     scheme_type;
        
      url = ((brs_status_t*)p)->url;
      scheme_type = msf_url_get_scheme_type((const char*)url);
      if (scheme_type == msf_scheme_http ||
          scheme_type == msf_scheme_https ||
          scheme_type == msf_scheme_empty)
      {
        bra_sif_fallback_switch_while_loading();
      }
    }
#endif

    break;
  case BRS_STATUS_LOADING_DOCUMENT_DONE:   
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_11BE0F566C261BB0B1777B8F44C2297B, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_DOCUMENT_DONE)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    bra_view_object_done (((brs_status_t *)p)->size);
    break;
  case BRS_STATUS_LOADING_DOCUMENT_FAILED: 
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_119956A8CBE7C5FC6CF9321246068F9C, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_DOCUMENT_FAILED)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    break;
  case BRS_STATUS_LOADING_OBJECT:          
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_FD488963BAC3D7717F754BA494796999, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    bra_view_new_object (BRA_STR_LOADING_OBJ, ((brs_status_t *)p)->url);
    break;
  case BRS_STATUS_LOADING_OBJECT_DONE:     
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_C2A66A94ED7871EB44ADE4013A5031DB, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT_DONE)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    bra_view_object_done (((brs_status_t *)p)->size);
    break;
  case BRS_STATUS_LOADING_OBJECT_FAILED:   
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_27CBB033F3CFC6A9D16B891C729EC367, "BRA: BRS Status id = %i, status = %i (BRS_STATUS_LOADING_OBJECT_FAILED)\n",((brs_status_t *)p)->instanceId, ((brs_status_t *)p)->status));
    /*bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_STATUS_DLG);*/
    break;
#ifdef BRA_CFG_OFFLINE_PAGES
  case BRS_STATUS_OFFLINE_PAGE_SAVE_OK:
    bra_ofln_saving_offline_done(TRUE);
    break;
  case BRS_STATUS_OFFLINE_PAGE_SAVE_FAILED:
    bra_ofln_saving_offline_done(FALSE);
    break;
#endif    

  default:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_SIF_EB22D3B478B871DD5D003FB7ECAEEA2C, "BRA: BRS Status Error. No such state\n"));
  }
  
  BRA_FREE (((brs_status_t *)p)->url);
}

static MsfStringHandle
bra_sif_cvt_error_to_str(int error)
{
  switch (error)
  {
    /* Invalid input */
  case BRS_ERROR_INVALID_INPUT:
    return BRA_STR_INVALID_INPUT;
  case BRS_ERROR_INVALID_URL:
    return BRA_STR_INVALID_URL;
  case BRS_ERROR_INVALID_SCHEME:
    return BRA_STR_SCHEME_NOT_SUPPORTED;
    /* Parser error codes. For more information, see msf_prsr.h. */
  case BRS_ERROR_UNKNOWN_CHARSET:
    return BRA_STR_UNKNOWN_CHARSET;
  case BRS_ERROR_SYNTAX:
  case BRS_ERROR_UNKNOWN_DOCTYPE:
  case BRS_ERROR_UNSUPPORTED_WBXML:
  case BRS_ERROR_UNEXPECTED_END_OF_DOC:
  case BRS_ERROR_VALIDATION:
  case BRS_ERROR_ABORTED:
    return BRA_STR_PARSER_ERROR;
  case BRS_ERROR_REQUIRE_FRAMES:
    return BRA_STR_REQUIRE_FRAMES;
    
    /* 'WMLS' errors, i.e., error in WMLScript */
  case BRS_ERROR_WMLS:
  case BRS_ERROR_WMLS_VERIFICATION:
  case BRS_ERROR_WMLS_LIB:
  case BRS_ERROR_WMLS_FUNC_ARGS:
  case BRS_ERROR_WMLS_EXTERNAL:
  case BRS_ERROR_WMLS_LOAD:
  case BRS_ERROR_WMLS_INTERPRETING:
  case BRS_ERROR_WMLS_ABORT:
  case BRS_ERROR_WMLS_EXIT:
    return BRA_STR_WMLS_ERROR;
    
    /* Access restrictions on WML or WMLScript */
  case BRS_ERROR_ACCESS_RESTRICTIONS_WML:
    return BRA_STR_ACCESS_RESTR_WML;
  case BRS_ERROR_ACCESS_RESTRICTIONS_WMLS:
    return BRA_STR_ACCESS_RESTR_WMLS;
    
    /* Communication errors. */
  case BRS_ERROR_COMMUNICATION:
    return BRA_STR_ERROR_COMMUNICATION;
  case BRS_ERROR_HOST_NOT_FOUND:
    return BRA_STR_HOST_NOT_FOUND;
  case BRS_ERROR_REQUEST_TIMED_OUT:
    return BRA_STR_REQUEST_TIMED_OUT;
  case BRS_ERROR_CONNECTION_FAILED:
    return BRA_STR_CONNECTION_FAILED;
  case BRS_ERROR_SECURE_CONNECTION_FAILED:
    return BRA_STR_SEC_CONNECTION_FAILED;
    
    /* Misc. */
  case BRS_ERROR_INTERNAL:
    return BRA_STR_INTERNAL_ERROR;
  case BRS_ERROR_RESEND_POST_WARNING:
    return BRA_STR_RESEND_POST_WARNING;
  case BRS_ERROR_OUT_OF_MEMORY:
    return BRA_STR_OUT_OF_MEMORY;
  case BRS_ERROR_CONTENT_TOO_LARGE:
    return BRA_STR_CONTENT_TOO_LARGE;
  default:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_SIF_CDD7F9B13D5CECBBC16F721897E21B6C, "BRA: ERROR. No such error code: error = %i \n", error));
    return BRA_STR_ID_ERR_UNDEFINED_ERROR;
  }
}

#ifdef BRA_CFG_PROF_FALLBACK
static void
bra_sif_fallback_switch_while_loading(void)
{
  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_AF9B10BA4C11A5AB4A5A11CEB05092BB, "BRA: bra_sif_fallback_switch_while_loading()\n"));
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_18121DE62E73F82956A8D02AFC887C9A, "BRA:   gprs_bearer_state=%d\n", bra_sif_gprs_bearer_state));
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_8A49F2E71C5FA589D2ABB922750619DD, "BRA:   fallback_thru_count=%d\n", bra_sif_fallback_thru_count));

  if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL))
  {
    int crtBearerType;
    crtBearerType = HDIa_networkAccountGetBearer(bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));

    if (crtBearerType == HDI_SOCKET_BEARER_GSM_GPRS &&
        bra_sif_gprs_bearer_state == BRA_SIF_BR_STATE_NOT_AVAILABLE)
    {
      bra_sif_fallback_thru_count--;
      if (bra_sif_fallback_thru_count<0)
      {
        BRSif_stop(MSF_MODID_BRA, bra_sif_get_brs_id());
        bra_sif_prompt_bearer_switch(HDI_SOCKET_BEARER_GSM_CSD, 1);
      }
    }

    if (crtBearerType == HDI_SOCKET_BEARER_GSM_CSD &&
        bra_sif_gprs_bearer_state == BRA_SIF_BR_STATE_AVAILABLE &&
        bra_view_if_has_viewable_page())
    {
      bra_sif_fallback_thru_count--;
      if (bra_sif_fallback_thru_count<0)
      {
        BRSif_stop(MSF_MODID_BRA, bra_sif_get_brs_id());
        bra_sif_prompt_bearer_switch(HDI_SOCKET_BEARER_GSM_GPRS, 1);
      }
    }
  }
}

static void
bra_sif_fallback_do_reload_page(void)
{
  bra_cmn_addr_t *addr;
  char           *reload_url;


  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_191E4C00F73C78C621EF26E6761D5481, "BRA: bra_sif_fallback_do_reload_page()\n"));

  if(bra_win_get_window(BRA_WIN_ID_VIEWPORT) != NULL)
    bra_view_enable();
  bra_sif_fallback_state = BRA_SIF_FBSTATE_CONNECTING;
  bra_sif_fallback_do_reload = 0;
 
  addr = bra_cmn_get_current_page();
  reload_url = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_URL_FALLBACK);
  if (reload_url != 0 && 0 == strcmp((const char*)BRA_CMN_HNV(addr->url), (const char*)reload_url))
    BRSif_reload (MSF_MODID_BRA, bra_sif_get_brs_id());
  else
    bra_goto_url(msf_cmmn_strdup(MSF_MODID_BRA, reload_url));
}

static void 
bra_sif_bearer_switch_response (MsfActionType response)
{
  extern void HDIa_releaseBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);
  int new_netid;

  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_ACD18B1EA1DCD6CA3C8545135C058467, "BRA: bra_sif_bearer_switch_response()\n"));

  if(response == MsfOk)
  {
    // only release current bearer if it's CSD (keep GPRS connection open to continue to receive coverage indicaton)
    if (bra_sif_switch_to_bearer == HDI_SOCKET_BEARER_GSM_CSD) {
      new_netid = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM);
    } else {
      HDIa_releaseBearer(MSF_MODID_BRA, bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));
      new_netid = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS);
    }

    /* this registry change will cause STK to update its default channel + trigger BRS to setchannel */
    bra_prof_change_key_int_value(
            BRA_PROF_ID_BRA,
            BRA_PROF_KEY_NET_ID,
            new_netid,
            NULL);
    bra_sif_fallback_state = BRA_SIF_FBSTATE_SWITCHING;
    bra_sif_fallback_thru_count = 0;
    MSF_REGISTRY_GET(MSF_MODID_BRA, 0, "/BRS/BRA", BRA_PROF_KEY_NET_ID);
  }
  else
  {
    bra_sif_fallback_state = BRA_SIF_FBSTATE_NONE;

    //if (bra_sif_switch_to_bearer == HDI_SOCKET_BEARER_GSM_GPRS)
    if (bra_sif_fallback_do_reload)
    {
      /* this is to prevent desync'd paintbox if connecting outside WAP menu*/
      //if (bra_view_if_has_viewable_page() || bra_win_get_window(BRA_WIN_ID_INSE)) {
        bra_sif_fallback_do_reload_page();
        bra_sif_fallback_thru_count = BRA_SIF_MAX_THRU_COUNT;
      //}
    } else
      bra_view_delete_status();
  }
}

void
bra_sif_prompt_bearer_switch (int new_bearer, int do_reload)
{
  MsfStringHandle ms;

  /* new_bearer: HDI_SOCKET_BEARER_GSM_CSD, HDI_SOCKET_BEARER_GSM_GPRS */
  bra_sif_switch_to_bearer = new_bearer;
  bra_sif_fallback_do_reload = do_reload;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_011C50287C6EC1658BF527714114393B, "BRA: bra_sif_prompt_bearer_switch(new_bearer=%d, do_reload=%d)\n", new_bearer, do_reload));

  if (new_bearer == HDI_SOCKET_BEARER_GSM_CSD)
    ms = BRA_STR_SWITCH_GSM_CSD;
  else { //if (new_bearer == HDI_SOCKET_BEARER_GSM_GPRS) {
    if (do_reload == 0)
      ms = BRA_STR_SWITCH_GSM_GPRS_IDLE;
    else
      ms = BRA_STR_SWITCH_GSM_GPRS_LOAD;
  }

  bra_sif_fallback_state = BRA_SIF_FBSTATE_WAITUSER;
  bra_dlg_create_dlg (MsfConfirmation,
                      ms, 
                      BRA_STR_YES, 
                      BRA_STR_NO,
                      0, 
                      bra_sif_bearer_switch_response);
}


void
bra_sif_fallback_continue (int net_id)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_5B03ADD2D47908F0CBB4F4EEF6AD3AFB, "BRA: bra_sif_fallback_continue(net_id=%d)\n", net_id));

  if ((bra_sif_switch_to_bearer==HDI_SOCKET_BEARER_GSM_CSD && net_id==bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM)) ||
      (bra_sif_switch_to_bearer==HDI_SOCKET_BEARER_GSM_GPRS && net_id==bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS))) {
    if(bra_win_get_window(BRA_WIN_ID_VIEWPORT) != NULL)
      bra_view_enable();

    if (bra_sif_fallback_do_reload)
      bra_sif_fallback_do_reload_page();
    else  
    {
        bra_sif_fallback_state = BRA_SIF_FBSTATE_NONE;
        bra_view_delete_status();
    }
  } else {
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_826CF85FAEC02CA0C2ADB09CD6C44D9E, "BRA: bra_sif_fallback_continue: net_id not match-->BRS not fully updated, reg get again\n"));
    MSF_REGISTRY_GET(MSF_MODID_BRA, 0, "/BRS/BRA", BRA_PROF_KEY_NET_ID);
  }
}

int
bra_sif_is_pending_bearer_switch(void)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_0420FC26DE3D590C1FA1EA9AB632D530, "BRA: bra_sif_is_switching_bearer: fallback_state=%d\n", bra_sif_fallback_state));
  return (bra_sif_fallback_state==BRA_SIF_FBSTATE_WAITUSER ||
          bra_sif_fallback_state == BRA_SIF_FBSTATE_SWITCHING);
}
#endif

void
bra_sif_handle_bearer_status(int bearer_type, int status)
{
  int crtBearerType;
  crtBearerType = HDIa_networkAccountGetBearer(bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));
      
  /* for level 3 fallback */
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_83AB084D26110B9972B77C7757C54F23, "BRA: bra_sif_handle_bearer_status(bearer_type=%d, status=%d)\n", bearer_type, status));

  if (!bra_view_is_busy() && !bra_view_if_has_viewable_page())
    return;

#ifdef BRA_CFG_PROF_FALLBACK
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_18121DE62E73F82956A8D02AFC887C9A, "BRA:   gprs_bearer_state=%d\n", bra_sif_gprs_bearer_state));
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_1FB36A82A98C892B628F1D7A651D05B4, "BRA:   bra_sif_fallback_state=%d\n", bra_sif_fallback_state));

  if (bearer_type == WAP_BEARER_STATUS_GPRS) {
    switch (status) {
      case WAP_GPRS_NONE:
        if (bra_sif_gprs_bearer_state==BRA_SIF_BR_STATE_AVAILABLE && crtBearerType==HDI_SOCKET_BEARER_GSM_GPRS)
          bra_sif_fallback_thru_count = -1;
        bra_sif_gprs_bearer_state = BRA_SIF_BR_STATE_NOT_AVAILABLE;
        break;
      case WAP_GPRS_COVERAGE:
      	if (bra_sif_gprs_bearer_state==BRA_SIF_BR_STATE_NOT_AVAILABLE && crtBearerType==HDI_SOCKET_BEARER_GSM_CSD)
          bra_sif_fallback_thru_count = -1;
        bra_sif_gprs_bearer_state = BRA_SIF_BR_STATE_AVAILABLE;
        break;
      case WAP_GPRS_ATTACHED:
      	if (bra_sif_gprs_bearer_state==BRA_SIF_BR_STATE_NOT_AVAILABLE && crtBearerType==HDI_SOCKET_BEARER_GSM_CSD)
          bra_sif_fallback_thru_count = -1;
        bra_sif_gprs_bearer_state = BRA_SIF_BR_STATE_AVAILABLE;
        break;
      case WAP_GPRS_DETACHED:
        break;
    }

    if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL)) {
      if (crtBearerType == HDI_SOCKET_BEARER_GSM_GPRS) {
        if (bra_sif_gprs_bearer_state == BRA_SIF_BR_STATE_NOT_AVAILABLE &&
            bra_sif_fallback_state == BRA_SIF_FBSTATE_CONNECTING &&
            bra_sif_fallback_thru_count < 0)
        {
          BRSif_stop(MSF_MODID_BRA, bra_sif_get_brs_id());
          bra_sif_prompt_bearer_switch(HDI_SOCKET_BEARER_GSM_CSD, 1);
        }

      } else if (crtBearerType == HDI_SOCKET_BEARER_GSM_CSD) {
        if (bra_sif_gprs_bearer_state == BRA_SIF_BR_STATE_AVAILABLE &&
            bra_sif_fallback_state == BRA_SIF_FBSTATE_NONE)
        {
          bra_sif_prompt_bearer_switch(HDI_SOCKET_BEARER_GSM_GPRS, 0);
        }
      }
    }
  }
#endif
}

void
bra_sif_handle_notify_bearer_info(int bearer, int status)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_1916965FDF6DCF5E1A617D315E9689AA, "BRA: bra_sif_handle_notify_bearer_info(bearer=%d, status=%d)\n", bearer, status));

  if (!bra_win_any_win_exists())
    return;

#ifdef BRA_CFG_PROF_FALLBACK
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_1FB36A82A98C892B628F1D7A651D05B4, "BRA:   bra_sif_fallback_state=%d\n", bra_sif_fallback_state));
  if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL)) {
    if (bearer==HDI_SOCKET_BEARER_GSM_CSD && (status==BRA_BRINFO_CSD_TIMEOUT || status==BRA_BRINFO_CSD_DISC)) {
      bra_sif_fallback_thru_count = 0;
      bra_sif_fallback_do_reload = 0;
      bra_sif_switch_to_bearer = HDI_SOCKET_BEARER_GSM_GPRS;

      bra_sif_bearer_switch_response(MsfOk);
    }
  }
#endif  /* BRA_CFG_PROF_FALLBACK */
}


/*
 * This function is called when an error has occured in the BRS (or other module 
 * used by BRS) after a request has been made. A error dialog is raised to the 
 * user.
 *
 * PARAMETERS
 *
 * id        : object id
 * error     : Error code as defined in BRS_if.h
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_error (int id, int error)
{
  MSF_INT32 detail_error = 0;
  MsfStringHandle ms;
  extern pBOOL isInCall(void);
  extern unsigned short GetWapCallPresent(void);  
  extern MSF_INT32 HDIa_getLastError(void);
  id = id;

  /* Ignore error in authentication */
  if(error == BRS_ERROR_AUTHENTICATION)
    return;

  if(error == BRS_ERROR_OUT_OF_MEMORY)
  {
    /* TBD */
  }
  else if(isInCall() && !GetWapCallPresent()) 
  {
    /* Don't show any dialog if MMI is not allowed to interrupt */
    return;    
  }

  ms = bra_sif_cvt_error_to_str (error);
  detail_error = HDIa_getLastError();
  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_D5FEF7B81EA34BBD6B96DC64B6693FAB, "BRA: detail_error = %d", detail_error));

  // if DNS lookup failed due to bearer failed, replace Host Not Found with Connection Failed message
  if (ms == BRA_STR_HOST_NOT_FOUND && detail_error)
  {
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_SIF_4EF02DA9F30A09B1AFCC93CB0EEFBECA, "BRA: host not found + detail_error has value\n"));
    MSF_WIDGET_RELEASE (ms);
    ms = BRA_STR_CONNECTION_FAILED;
  }

  if(ms == BRA_STR_CONNECTION_FAILED)
  {
    int current_net_id;
    current_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
    /* Don't show any 'connection failed' dialog if bearer type is CSD */
    if(HDIa_networkAccountGetBearer(current_net_id) == HDI_SOCKET_BEARER_GSM_CSD)
    {
      MSF_WIDGET_RELEASE (ms);

#ifdef BRA_CFG_PROMPT_CSD_ERROR_CAUSE
      switch (detail_error) {
        case PPPE_AUTH_FAIL:
            ms = BRA_STR_ERROR_CSD_AUTH_FAIL;
            break;
        case ABM_E_CSD_REACTIVATE:
        case ABM_E_CSD_PPP_NEGOTIATED_FAILED:
        case ABM_E_CSD_ACT_FAILED:
        case ABM_E_CSD_CALL_SETUP_FAILED:
            break;
        default:
            return;
      }
      detail_error = 0;
#else
      return;
#endif
    }

    // Replace error string with GPRS error if any
    if(detail_error > 0) {
#ifdef BRA_CFG_PROF_FALLBACK
      if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL))
      {
        MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_SIF_8A49F2E71C5FA589D2ABB922750619DD, "BRA:   fallback_thru_count=%d\n", bra_sif_fallback_thru_count));

        if (bra_sif_fallback_thru_count <= 0)
        {
          MSF_WIDGET_RELEASE(ms);
          bra_sif_prompt_bearer_switch(HDI_SOCKET_BEARER_GSM_CSD, 1);
          return;
        }
        if (detail_error==UNKNOWN_APN || detail_error==UNSUBSCRIBED_SERVICE_OPTION)
        {
          if (bra_sif_fallback_thru_count == BRA_SIF_MAX_THRU_COUNT-1)
          {
            MSF_WIDGET_RELEASE(ms);
            bra_sif_prompt_bearer_switch(HDI_SOCKET_BEARER_GSM_CSD, 1);
            return;
          }
          else
            bra_sif_fallback_thru_count--;
        }
      }
#endif

      // Replace error string with GPRS error if any
      switch(detail_error) {
        case AUTHENTICATION_FAILURE:
            MSF_WIDGET_RELEASE (ms); ms = BRA_STR_ERROR_GPRS_AUTHENTICATION_FAILURE; break;
        case UNSUPPORTED_SERVICE_OPTION:
            MSF_WIDGET_RELEASE (ms); ms = BRA_STR_ERROR_GPRS_UNSUPPORTED_SERVICE_OPTION; break;
        case UNKNOWN_APN:
            MSF_WIDGET_RELEASE (ms); ms = BRA_STR_ERROR_GPRS_UNKNOWN_APN; break;
        case UNSUBSCRIBED_SERVICE_OPTION: /* generally for wrong apn */
            MSF_WIDGET_RELEASE(ms); ms = BRA_STR_ERROR_GPRS_UNSUBSCRIBED_SERVICE_OPTION; break;
        case UNSPECIFIED:
            break;
      }
    }
  }

    bra_dlg_create_dlg (MsfAlert,
                        ms, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);
  MSF_WIDGET_RELEASE (ms);
}

/*
 * When a request is compleated the BRS send information about the loaded request.
 * this function handles such information e.g. Title and url. This function also
 * remove any previous Do-Elements which now are obsolete
 *
 * PARAMETERS
 *
 * p         : Pointer to document info structure (brs_document_info_t)
 *
 * RETURN    :
 */
void
bra_sif_handle_brs_doc_info (brs_document_info_t *p)
{
  bra_view_loading_complete(TRUE);
  bra_opt_disable_link ();
  bra_opt_disable_edit ();
  bra_opt_disable_reset ();
  bra_opt_disable_choose ();
  bra_act_disable_object_action();

#ifdef BRA_CONFIG_SECURITY
  if (p->securityId >= 0)
  {
    //int sec_on_off, port;
    //port = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT);
    //sec_on_off = (port==9202||port==9203)?1:0; 
    //if(sec_on_off)
    {    	
      SECif_getCurrentSecClass (MSF_MODID_BRA, bra_sif_get_brs_id (), p->securityId);
      //SECif_getSessionInfo(MSF_MODID_BRA, bra_sif_get_brs_id (), p->securityId); 
    }
    bra_sif_security_id = p->securityId;      
  }
  else {
    bra_sif_set_security_class(0, 0, 0);
  }  
#endif
  /*Remove any do-elements on previous page*/
  bra_opt_remove_do_elements ();
  /*Add page to recent page list*/
  bra_rpl_add_history_item(p->url, p->title);

  /*Set as currently loaded page*/
  bra_cmn_set_current_page (p->title, p->url, BRA_INSE_SET_CURRENT_TITLE | BRA_INSE_SET_CURRENT_URL);

#ifdef BRA_CFG_DISPLAY_TITLE
  /*Set Title*/
  bra_view_set_title (p->title, p->url);
#else
  /*delete title & url*/
  BRA_FREE (p->title);
  BRA_FREE (p->url);

#endif

  bra_sif_socket_id = p->socketId;

  /* enable back action softkey if necessary */
  bra_view_enable_back_action((p->flags & BRS_INFO_FLAG_ENABLE_BACK));
  bra_view_document_done(1);
}

/*
 * If the loaded documet contains Do-elements this function will receive a structure
 * with all such elements. this function will pass them on to the bra_opt_set_do_elements
 * fuction which will display them in the options menu. 
 * Note the p parameter MUST NOT be freed when this function returns.
 *
 * PARAMETERS
 *
 * p         : Do-Element structure
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_do_element (void* p)
{
  bra_opt_set_do_elements (p);
}

/*
 * This function is called from the BRS (via Signals) when an content element is selected 
 *
 * PARAMETERS
 *
 * p         : Information about the selected element
 *
 * RETURN    : void
 */
void 
brs_sif_element_focused (void *p)
{
  brs_element_focused_t *msg;

  MsfGadgetHandle input_handle = 0;  

  msg = (brs_element_focused_t *)p;

  //Q03C1
  bra_act_disable_object_action();

  bra_opt_disable_link ();
  bra_opt_disable_edit ();
  bra_opt_disable_reset ();
  bra_opt_disable_choose ();

  if (msg->type == BRS_FOCUSED_ELEMENT_LINK)
  {
    bra_opt_enable_link ();
    if(msg->title != NULL)
      bra_view_set_soft_key (0,0);

	if(msg->object_filePath)
		bra_act_enable_object_action (msg->object_url, msg->object_mime, msg->object_filePath, msg->drm_restriction);
  }
  else if (msg->type == BRS_FOCUSED_ELEMENT_SUBMIT | msg->type == BRS_FOCUSED_ELEMENT_INPUT)
  {
     bra_opt_enable_link();
  }  
  else if(msg->type == BRS_FOCUSED_ELEMENT_TEXTINPUT)
  {
    bra_opt_enable_edit ();
#if 0
/* under construction !*/
#endif
  }  
  else if (msg->type == BRS_FOCUSED_ELEMENT_IMAGE || msg->type == BRS_FOCUSED_ELEMENT_INPUT_IMAGE)
  {
    //Q03C1
    bra_act_enable_object_action (msg->object_url, msg->object_mime, msg->object_filePath, msg->drm_restriction);      
  }
  else if (msg->type == BRS_FOCUSED_ELEMENT_SELECT) {
     bra_opt_enable_edit();
  }
  else if (msg->type == BRS_FOCUSED_ELEMENT_RESET) {
     bra_opt_enable_reset();
  }
  else if (msg->type == BRS_FOCUSED_ELEMENT_INPUT_SELECTED) {
     bra_opt_enable_choose();
  }
  else if (msg->type == BRS_FOCUSED_ELEMENT_INPUT_UNSELECTED) {
     bra_opt_enable_choose();
  }
  if (bra_sif_select_mode)
    bra_view_set_idle_softkey();
  HDIa_widgetExtPaintboxInputFocus(input_handle);    
}

#ifdef BRA_CFG_OFFLINE_PAGES
/*
 * This function is called from the BRS (via Signals) when the offline page not found 
 *
 * PARAMETERS
 *
 * p         : Information about the selected element
 *
 * RETURN    : void
 */
void 
brs_sif_page_not_found_offline (void *p)
{
  bra_ofln_page_not_found(p);
}
#endif/*BRA_CFG_OFFLINE_PAGES*/


#ifdef BRA_CFG_SELECT_MODE
/*
 * This function calls a function to create either an "option" or a "select mode" menu,
 * depending on the current navigation mode.
 *
 * PARAMETERS
 *
 *
 * RETURN    : void
 */
void
bra_sif_select_menu (void)
{
  if (bra_sif_select_mode)
    bra_slct_create_menu ();
  else
    bra_opt_create_menu ();
}

/*
 * This function sets the navigation mode.
 *
 * PARAMETERS
 *
 * set       : 0: select mode off, 1: select mode on
 *
 * RETURN    : void
 */
void
bra_sif_set_select_mode (int set)
{
  bra_sif_select_mode = set;
  if (set)
    BRSif_navigationChange (MSF_MODID_BRA, bra_sif_instance_id, BRS_MARKABLE_ELEMENT_IMG | BRS_MARKABLE_ELEMENT_OBJECT | BRS_MARKABLE_ELEMENT_INPUT_IMAGE);
  else
    BRSif_navigationChange (MSF_MODID_BRA, bra_sif_instance_id, BRS_MARKABLE_ELEMENT_DEFAULT);
}

#endif /*BRA_CFG_SELECT_MODE*/



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
 * bra_if.c
 *
 * Created by Mats Tedenvall 20020710	10:28
 *
 * Revision history:
 *
 */
#include "bra_cfg.h"
#include "msf_cfg.h"
#include "bra_if.h"
#include "bra_prof.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_mem.h"
#include <string.h>
#include "bra_prs.h"
#include "bra_cbm.h"
#include "bra_cmn.h"
#include "bra_cca.h"


#ifdef BRA_CFG_CCA

static int
bra_cca_cvt_app_configure(msf_dcvt_t* cvt_obj, bra_cca_app_configure_ind_t* p);


static int
bra_cca_cvt_get_profile(msf_dcvt_t* cvt_obj, bra_cca_get_prof_ind_t* p);

static int
bra_cca_cvt_update_profile(msf_dcvt_t* cvt_obj, bra_cca_update_prof_ind_t* p);

#endif /*BRA_CFG_CCA*/


#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN

static int
bra_set_cvt_handle_net_id_select_response(msf_dcvt_t *cvt_obj, bra_net_id_select_rsp_t *p);

#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/



static int
bra_cbm_cvt_select_result(msf_dcvt_t *cvt_obj, bra_cbm_select_result_t *p);

static int
bra_cbm_cvt_add_bearer_status_notify(msf_dcvt_t *cvt_obj, 
                                     bra_cbm_add_bearer_status_notify_t *p);

static int
bra_cbm_cvt_del_bearer_status_notify(msf_dcvt_t *cvt_obj, 
                                     bra_cbm_del_bearer_status_notify_t *p);

static int
bra_cbm_cvt_bearer_status_notify(msf_dcvt_t *cvt_obj, bra_cbm_bearer_status_notify_t *p);



#ifdef BRA_CFG_DUAL_SIM

static int
bra_sim_cvt_sim_info_notify(msf_dcvt_t *cvt_obj, bra_sim_info_notify_t *p);

#endif /* BRA_CFG_DUAL_SIM */



extern void 
HDIa_releaseBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);

/**********************************************************************
 * API invoked from other modules
 **********************************************************************/

void
BRAif_startInterface (void)
{
  MSF_SIGNAL_REG_FUNCTIONS (MSF_MODID_BRA, bra_convert, bra_destruct);
}



/**********************************************************************
 * Signal-sending functions
 **********************************************************************/


/*
 * Convert signals owned by the BRA module.
 * Conversion is from signal buffer to signal structs (see above).
 */

void*
bra_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer)
{
  msf_dcvt_t  cvt_obj;
  void       *user_data;
  MSF_UINT16  length;

  if (buffer == NULL)
    return NULL;

  user_data = MSF_SIGNAL_GET_USER_DATA (buffer, &length);
  if ((user_data == NULL) || (length == 0))
    return NULL;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);

  switch (signal){
  case BRA_SIG_CREATE_UI:
    {
      bra_create_ui_t *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_create_ui_t);
      msf_dcvt_uint8(&cvt_obj, &(p->type));
      msf_dcvt_string(&cvt_obj, &(p->url));
      return (void*)p;
    }      
  case BRA_SIG_SHOW_AUTH_DIALOG:
    {
      bra_show_auth_dlg_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_show_auth_dlg_t);
      msf_dcvt_uint8(&cvt_obj, (MSF_UINT8*)&(p->module));
      msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(p->requestId));
      msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(p->authType));
      msf_dcvt_string(&cvt_obj, (char**)&(p->realm));
      msf_dcvt_string(&cvt_obj, (char**)&(p->username));
      msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(p->warnings));
      return (void*)p;
    }    
  case BRA_SIG_SHOW_DIALOG:
    {
      bra_show_dlg_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_show_dlg_t);
      msf_dcvt_uint8(&cvt_obj, &(p->dlg_type));
      msf_dcvt_uint32(&cvt_obj, &(p->ms));
      return (void*)p;
    }
  case BRA_SIG_SHOW_DIALOG_EXT:
    {
      bra_show_dlg_ext_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_show_dlg_ext_t);
      msf_dcvt_uint8(&cvt_obj, &(p->dlg_type));
      msf_dcvt_uint32(&cvt_obj, &(p->ms));
      msf_dcvt_uint32(&cvt_obj, &(p->callback));
      return (void*)p;
    }
  case BRA_SIG_WTAI_MAKE_CALL:
    {
      bra_wtai_make_call_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_wtai_make_call_t);
      msf_dcvt_uint8(&cvt_obj, &(p->modId));
      msf_dcvt_uint16(&cvt_obj, &(p->telId));
      msf_dcvt_string(&cvt_obj, &(p->number));
      return (void *)p;
    }  
  case BRA_SIG_WTAI_SEND_DTMF:
    {
      bra_wtai_send_dtmf_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_wtai_send_dtmf_t);
      msf_dcvt_uint8(&cvt_obj, &(p->modId));
      msf_dcvt_uint16(&cvt_obj, &(p->telId));
      msf_dcvt_string(&cvt_obj, &(p->dtmf));
      return (void *)p;
    }  
  case BRA_SIG_WTAI_PB_ADD_ENTRY:
    {
      bra_wtai_pb_add_entry_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_wtai_pb_add_entry_t);
      msf_dcvt_uint8(&cvt_obj, &(p->modId));
      msf_dcvt_uint16(&cvt_obj, &(p->pbId));
      msf_dcvt_string(&cvt_obj, &(p->name));
      msf_dcvt_string(&cvt_obj, &(p->number));
      return (void *)p;
    }
  case BRA_SIG_HANDLE_EXTSCHEME:
    {
      bra_handle_extscheme_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_handle_extscheme_t);
      msf_dcvt_uint8(&cvt_obj, &(p->schType));
      msf_dcvt_uint8(&cvt_obj, &(p->modId));
      msf_dcvt_uint16(&cvt_obj, &(p->id));
      msf_dcvt_string(&cvt_obj, &(p->data));
      return (void *)p;
    }
  case BRA_SIG_BEARER_STATUS:
    {
      bra_handle_bearer_status_t *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_handle_bearer_status_t);
      msf_dcvt_uint8(&cvt_obj, &(p->bearerType));
      msf_dcvt_uint32(&cvt_obj, &(p->status));
      return (void *)p;
    }
  case BRA_SIG_DOWNLOAD_COMPLETE:
    {
      bra_download_complete_t *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_download_complete_t);
      msf_dcvt_uint8(&cvt_obj, &(p->status));
      return (void *)p;
    }
  case BRA_SIG_SAT_LAUCH_REQUEST:
    {
      bra_sat_lauch_request_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_sat_lauch_request_t);
      msf_dcvt_uint8(&cvt_obj, &(p->browserMode));
      msf_dcvt_uint8(&cvt_obj, &(p->browserIdentity));
      msf_dcvt_uint8(&cvt_obj, &(p->sim_id));
      msf_dcvt_uint16(&cvt_obj, &(p->noUrl));
      msf_dcvt_string(&cvt_obj, (char **)&(p->url));
      msf_dcvt_uint16(&cvt_obj, &(p->noBearer));
      msf_dcvt_string(&cvt_obj, (char **)&(p->bearer));
      msf_dcvt_uint16(&cvt_obj, &(p->noGateway));
      msf_dcvt_string(&cvt_obj, (char **)&(p->gateway));
      return (void *)p;
    }
  case BRA_SIG_NOTIFY_PINNED_PROV:
    {
      bra_prs_pinned_prov_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_prs_pinned_prov_t);
      msf_dcvt_uint32(&cvt_obj, &(p->dlgHandle));
      msf_dcvt_uint32(&cvt_obj, &(p->yesHandle));
      msf_dcvt_uint32(&cvt_obj, &(p->noHandle));
      msf_dcvt_uint8(&cvt_obj, &(p->stage));
      msf_dcvt_uint32(&cvt_obj, &(p->sim_id));
      return (void *)p;
    }
  case BRA_SIG_REGISTER_PROV_AUTH:
    {
      bra_prs_pinned_prov_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_prs_pinned_prov_t);
      msf_dcvt_uint32(&cvt_obj, &(p->dlgHandle));
      msf_dcvt_uint32(&cvt_obj, &(p->noHandle));
      return (void *)p;
    }
  case BRA_SIG_CANCEL_PROV_CONF:
    {
      return NULL;
    }
  case BRA_SIG_SELECT_BOOKMARK:
    {
      bra_select_bookmark_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_select_bookmark_t);
      msf_dcvt_uint8(&cvt_obj, &(p->srcModId));
      return (void *)p;
    }
  case BRA_SIG_SELECT_BOOKMARK_REPLY:
    {
      bra_select_bookmark_reply_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_select_bookmark_reply_t);
      msf_dcvt_uint8(&cvt_obj, &(p->result));
      msf_dcvt_string(&cvt_obj, &(p->title));
      msf_dcvt_string(&cvt_obj, &(p->url));
      return (void *)p;
    }
  case BRA_SIG_NOTIFY_BEARER_INFO:
    {
      bra_notify_bearer_info_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_notify_bearer_info_t);
      msf_dcvt_uint8(&cvt_obj, &(p->bearer));
      msf_dcvt_uint8(&cvt_obj, &(p->status));
      return (void *)p;
    }
#ifdef __UNIFIED_MSG_SUPPORT__
  case BRA_SIG_GET_PUSH_MSG_LIST:
    {
      bra_get_push_msg_list_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_get_push_msg_list_t);
      msf_dcvt_uint16(&cvt_obj, &(p->startFromMsg));
      return (void *)p;
    }
  case BRA_SIG_GET_PUSH_MSG_INFO:
    {
      bra_get_push_msg_info_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_get_push_msg_info_t);
      msf_dcvt_uint16(&cvt_obj, &(p->startFromMsg));
      msf_dcvt_uint16(&cvt_obj, &(p->numberOfMsg));
      return (void *)p;
    }
  case BRA_SIG_VIEW_PUSH_MSG:
    {
      bra_view_push_msg_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_view_push_msg_t);
      msf_dcvt_uint16(&cvt_obj, &(p->msgIndex));
      return (void *)p;
    }
#endif    


#ifdef BRA_CFG_CCA
  case BRA_SIG_CCA_APP_CONFIGURE_IND:
    {
      bra_cca_app_configure_ind_t *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_cca_app_configure_ind_t); 
      bra_cca_cvt_app_configure(&cvt_obj, p);
      return (void*)p;
    }

  case BRA_SIG_CCA_GET_PROF_IND:
    {
      bra_cca_get_prof_ind_t *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_cca_get_prof_ind_t);
      bra_cca_cvt_get_profile(&cvt_obj, p);
      return (void*)p;
    }

  case BRA_SIG_CCA_UPDATE_PROF_IND:
    {
      bra_cca_update_prof_ind_t *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_cca_update_prof_ind_t);
      bra_cca_cvt_update_profile(&cvt_obj, p);
      return (void*)p;
    }

#endif /*BRA_CFG_CCA*/

  case BRA_SIG_DA_DOWNLOAD_INFO_IND:
    {
      bra_da_download_info_t *p;

      p = MSF_MEM_ALLOCTYPE (module, bra_da_download_info_t);
      msf_dcvt_uint32(&cvt_obj, &(p->jobCount));
      msf_dcvt_uint32(&cvt_obj, &(p->activeJobCount));
      return (void *)p;
    }

#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN

  case BRA_SIG_NET_ID_SELECT_RSP:
    {
      bra_net_id_select_rsp_t   *p;

      p = MSF_MEM_ALLOCTYPE(module, bra_net_id_select_rsp_t);
      bra_set_cvt_handle_net_id_select_response(&cvt_obj, p);
      return (void*)p;
    }

#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/


  case BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND:
      {
          bra_cbm_select_result_t   *p;
          
          p = MSF_MEM_ALLOCTYPE(module, bra_cbm_select_result_t);
          bra_cbm_cvt_select_result(&cvt_obj, p);
          return (void*)p;
      }

  case BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF:
      {
          bra_cbm_add_bearer_status_notify_t   *p;
          
          p = MSF_MEM_ALLOCTYPE(module, bra_cbm_add_bearer_status_notify_t);
          bra_cbm_cvt_add_bearer_status_notify(&cvt_obj, p);
          return (void*)p;
      }

  case BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF:
      {
          bra_cbm_del_bearer_status_notify_t   *p;
          
          p = MSF_MEM_ALLOCTYPE(module, bra_cbm_del_bearer_status_notify_t);
          bra_cbm_cvt_del_bearer_status_notify(&cvt_obj, p);
          return (void*)p;
      }

  case BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND:
      {
          bra_cbm_bearer_status_notify_t   *p;
          
          p = MSF_MEM_ALLOCTYPE(module, bra_cbm_bearer_status_notify_t);
          bra_cbm_cvt_bearer_status_notify(&cvt_obj, p);
          return (void*)p;
      }
      
#ifdef BRA_CFG_DUAL_SIM

  case BRA_SIG_SIM_INFO_NOTIFY_IND:
      {
          bra_sim_info_notify_t   *p;

          p = MSF_MEM_ALLOCTYPE(module, bra_sim_info_notify_t);
          bra_sim_cvt_sim_info_notify(&cvt_obj, p);
          return(void*)p;
      }
#endif  /* BRA_CFG_DUAL_SIM */

  default:
      return NULL;
  }

  return NULL;
}

void
bra_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p)
{
  msf_dcvt_t cvt_obj;

  if (p == NULL)
    return;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_FREE, NULL, 0, module);

  switch (signal){
  case BRA_SIG_SELECT_BOOKMARK_REPLY:
    {
      msf_dcvt_uint8(&cvt_obj, &(((bra_select_bookmark_reply_t*)p)->result));
      msf_dcvt_string(&cvt_obj, &(((bra_select_bookmark_reply_t*)p)->title));
      msf_dcvt_string(&cvt_obj, &(((bra_select_bookmark_reply_t*)p)->url));
      break;
    }

#ifdef BRA_CFG_CCA
  case BRA_SIG_CCA_APP_CONFIGURE_IND:
    {
      bra_cca_cvt_app_configure(&cvt_obj, (bra_cca_app_configure_ind_t*)p);
      break;
    }

  case BRA_SIG_CCA_GET_PROF_IND:
    {
      bra_cca_cvt_get_profile(&cvt_obj, (bra_cca_get_prof_ind_t*)p);
      break;
    }

  case BRA_SIG_CCA_UPDATE_PROF_IND:
    {
      bra_cca_cvt_update_profile(&cvt_obj, (bra_cca_update_prof_ind_t*)p);
      break;
    }

#endif /*BRA_CFG_CCA*/


#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN

  case BRA_SIG_NET_ID_SELECT_RSP:
    {
      bra_set_cvt_handle_net_id_select_response(&cvt_obj, (bra_net_id_select_rsp_t*)p);
      break;
    }
    
#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/  


    
  case BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND:
    {
      bra_cbm_cvt_select_result(&cvt_obj, (bra_cbm_select_result_t*)p);
      break;
    }
    
  case BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF:
    {
      bra_cbm_cvt_add_bearer_status_notify(&cvt_obj,
        (bra_cbm_add_bearer_status_notify_t*)p);
      break;
    }
    
  case BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF:
    {
      bra_cbm_cvt_del_bearer_status_notify(&cvt_obj, 
        (bra_cbm_del_bearer_status_notify_t*)p);
      break;
    }
    
  case BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND:
    {
      bra_cbm_cvt_bearer_status_notify(&cvt_obj, (bra_cbm_bearer_status_notify_t*)p);
      break;
    }
    
#ifdef BRA_CFG_DUAL_SIM

  case BRA_SIG_SIM_INFO_NOTIFY_IND:
    {
      bra_sim_cvt_sim_info_notify(&cvt_obj, (bra_sim_info_notify_t*)p);
      break;
    }

#endif /* BRA_CFG_DUAL_SIM */
    
  
  default:
    break;
  }

  MSF_MEM_FREE (module, p);
}

void
BRAif_createUI (MSF_UINT8 type, const char* url)
{
  bra_create_ui_t        param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.type = type;
  param.url = (char*)url;
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.type));
  msf_dcvt_string(&cvt_obj, &(param.url));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CREATE_UI, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.type));
    msf_dcvt_string(&cvt_obj, &(param.url));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_destroyUI (void)
{
  void *signal_buffer;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_DESTROY_UI, 0, MSF_MODID_BRA, 0);
  if (signal_buffer != NULL) MSF_SIGNAL_SEND (signal_buffer);
} 

void
BRAif_showAuthDialog (MSF_UINT8 module, int requestId, int authType, 
                      const char *realm, const char* username, int warnings)
{
  bra_show_auth_dlg_t    param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.module = module;
  param.requestId = requestId;
  param.authType = authType;
  param.realm = (char *)realm;
  param.username = (char *)username;
  param.warnings = warnings;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, (MSF_UINT8*)&(param.module));
  msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(param.requestId));
  msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(param.authType));
  msf_dcvt_string(&cvt_obj, (char**)&(param.realm));
  msf_dcvt_string(&cvt_obj, (char**)&(param.username));
  msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(param.warnings));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SHOW_AUTH_DIALOG, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, (MSF_UINT8*)&(param.module));
    msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(param.requestId));
    msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(param.authType));
    msf_dcvt_string(&cvt_obj, (char**)&(param.realm));
    msf_dcvt_string(&cvt_obj, (char**)&(param.username));
    msf_dcvt_int32(&cvt_obj, (MSF_INT32*)&(param.warnings));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_showDialog (MSF_UINT8 dlg_type, MSF_UINT32 ms)
{
  bra_show_dlg_t         param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.dlg_type = dlg_type;
  param.ms = ms;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.dlg_type));
  msf_dcvt_uint32(&cvt_obj, &(param.ms));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SHOW_DIALOG, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.dlg_type));
    msf_dcvt_uint32(&cvt_obj, &(param.ms));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_showDialogExt (MSF_UINT8 dlg_type, MSF_UINT32 ms, MSF_UINT32 callback)
{
  bra_show_dlg_ext_t         param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.dlg_type = dlg_type;
  param.ms = ms;
  param.callback = callback;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.dlg_type));
  msf_dcvt_uint32(&cvt_obj, &(param.ms));
  msf_dcvt_uint32(&cvt_obj, &(param.callback));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SHOW_DIALOG_EXT, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.dlg_type));
    msf_dcvt_uint32(&cvt_obj, &(param.ms));
    msf_dcvt_uint32(&cvt_obj, &(param.callback));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

int
BRAif_getNetAccId (void)
{
  return bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
}

#ifdef MMS_CFG_FALLBACK_SUPPORT
int
BRAif_getMMSFallbackStatus (void)
{
  /* returns 0 = no fallback on activated MMS profile
   *         1 = fallback supported on activated MMS profile and currently using GPRS connection
   *         2 = fallback supported on activated MMS profile and currently using CSD connection
   */
  int crtNetID;
  int mms_prof_id;
  int old_prof_id;
  int old_prof_type;
  int log_mms_netid = -1;
  int log_mms_netiddual = -1;
  int log_mms_netidgprs = -1;
  int log_mms_netidgsm = -1;


  old_prof_type = bra_prof_get_profile_id();
  old_prof_id = bra_prof_get_absolute_profile();
  mms_prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
  bra_prof_set_selected_profile(BRA_PROF_ID_MMS, mms_prof_id, NULL);
  
  log_mms_netid = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID);
  log_mms_netiddual = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_DUAL);
  log_mms_netidgprs = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS);
  log_mms_netidgsm = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_DE158F54BD5FFA83080863A2D1F7263A, "BRA: BRAif_getMMSFallbackStatus(), old prof type:%d, old prof id:%d, mms prof id:%d\n", old_prof_type, old_prof_id, mms_prof_id));
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_72B46F73221D67F94485944645F2B3EE, "BRA: netid:%d, dual:%d, gprs:%d, csd:%d\n",log_mms_netid,log_mms_netiddual,log_mms_netidgprs,log_mms_netidgsm));
  
  if (!bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_DUAL))
  {
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 0;
  }
  crtNetID = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_474B26560C1E6653BA735B86625C2D33, "BRA: crtNetID: %d\n", crtNetID));

  if (crtNetID == bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS))
  {
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 1;
  }
  if (crtNetID == bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM))
  {
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 2;
  }
  ASSERT(0);
  return 0;
}


int
BRAif_setMMSFallback (void)
{
  /* returns 0 = activated MMS Profile does not allow fallback or already fallback'd
   *         1 = data account switched
   */
  int crtNetID;
  int mms_prof_id;
  int old_prof_id;
  int old_prof_type;
  int log_mms_netid = -1;
  int log_mms_netiddual = -1;
  int log_mms_netidgprs = -1;
  int log_mms_netidgsm = -1;


  old_prof_type = bra_prof_get_profile_id();
  old_prof_id = bra_prof_get_absolute_profile();
  mms_prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
  bra_prof_set_selected_profile(BRA_PROF_ID_MMS, mms_prof_id, NULL);
  
  log_mms_netid = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID);
  log_mms_netiddual = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_DUAL);
  log_mms_netidgprs = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS);
  log_mms_netidgsm = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_D8245DF43218B4D564793D0019C05C2F, "BRA: BRAif_setMMSFallback(), old prof type:%d, old prof id:%d, mms prof id:%d\n", old_prof_type, old_prof_id, mms_prof_id));
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_72B46F73221D67F94485944645F2B3EE, "BRA: netid:%d, dual:%d, gprs:%d, csd:%d\n",log_mms_netid,log_mms_netiddual,log_mms_netidgprs,log_mms_netidgsm));

  if (!bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_DUAL))
  {
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 0;
  }
  crtNetID = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_474B26560C1E6653BA735B86625C2D33, "BRA: crtNetID: %d\n", crtNetID));

  if (crtNetID == bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS))
  {
	MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_684811E7D5A0299A7132F184E4A4836D, "BRA: id matched\n"));

    HDIa_releaseBearer(MSF_MODID_MMS, bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS));
    bra_prof_change_key_int_value(
            BRA_PROF_ID_MMS,
            BRA_PROF_KEY_NET_ID,
            bra_prof_get_key_int_value (BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM),
            NULL);
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 1;
  }
  bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
  return 0;
}


int
BRAif_restoreMMSFallback (void)
{
  /* returns 0 = activated MMS Profile does not allow fallback or already restored
   *         1 = data account switched
   */
  int crtNetID;
  int mms_prof_id;
  int old_prof_id;
  int old_prof_type;
  int log_mms_netid = -1;
  int log_mms_netiddual = -1;
  int log_mms_netidgprs = -1;
  int log_mms_netidgsm = -1;


  old_prof_type = bra_prof_get_profile_id();
  old_prof_id = bra_prof_get_absolute_profile();
  mms_prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
  bra_prof_set_selected_profile(BRA_PROF_ID_MMS, mms_prof_id, NULL);
  
  log_mms_netid = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID);
  log_mms_netiddual = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_DUAL);
  log_mms_netidgprs = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS);
  log_mms_netidgsm = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_F62A1C2FD703E7A56CBCA95A8059EC91, "BRA: BRAif_restoreMMSFallback(), old prof type:%d, old prof id:%d, mms prof id:%d\n", old_prof_type, old_prof_id, mms_prof_id));
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_72B46F73221D67F94485944645F2B3EE, "BRA: netid:%d, dual:%d, gprs:%d, csd:%d\n",log_mms_netid, log_mms_netiddual, log_mms_netidgprs, log_mms_netidgsm));

  if (!bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_DUAL))
  {
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 0;
  }
  crtNetID = bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_474B26560C1E6653BA735B86625C2D33, "BRA: crtNetID: %d\n", crtNetID));

  if (crtNetID == bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM))
  {
	MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_IF_684811E7D5A0299A7132F184E4A4836D, "BRA: id matched\n"));

    HDIa_releaseBearer(MSF_MODID_MMS, bra_prof_get_key_int_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GSM));
    bra_prof_change_key_int_value(
            BRA_PROF_ID_MMS,
            BRA_PROF_KEY_NET_ID,
            bra_prof_get_key_int_value (BRA_PROF_ID_MMS, BRA_PROF_KEY_NET_ID_GPRS),
            NULL);
    bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
    return 1;
  }
  bra_prof_set_selected_profile(old_prof_type, old_prof_id, NULL);
  return 0;
}

#endif  /* MMS_CFG_FALLBACK_SUPPORT */

void
BRAif_telMakeCall (MSF_UINT8 modId, MSF_UINT16 telId, const char* number)
{
  bra_wtai_make_call_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.modId = modId;
  param.telId = telId;
  param.number = (char*)number;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.modId));
  msf_dcvt_uint16(&cvt_obj, &(param.telId));
  msf_dcvt_string(&cvt_obj, &(param.number));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_WTAI_MAKE_CALL, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.modId));
    msf_dcvt_uint16(&cvt_obj, &(param.telId));
    msf_dcvt_string(&cvt_obj, &(param.number));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_telSendDtmf (MSF_UINT8 modId, MSF_UINT16 telId, const char* dtmf)
{
  bra_wtai_send_dtmf_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.modId = modId;
  param.telId = telId;
  param.dtmf = (char*)dtmf;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.modId));
  msf_dcvt_uint16(&cvt_obj, &(param.telId));
  msf_dcvt_string(&cvt_obj, &(param.dtmf));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_WTAI_SEND_DTMF, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.modId));
    msf_dcvt_uint16(&cvt_obj, &(param.telId));
    msf_dcvt_string(&cvt_obj, &(param.dtmf));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_pbAddEntry (MSF_UINT8 modId, MSF_UINT16 pbId, const char* name, const char* number)
{
  bra_wtai_pb_add_entry_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.modId = modId;
  param.pbId = pbId;
  param.name = (char*)name;
  param.number = (char*)number;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.modId));
  msf_dcvt_uint16(&cvt_obj, &(param.pbId));
  msf_dcvt_string(&cvt_obj, &(param.name));
  msf_dcvt_string(&cvt_obj, &(param.number));  
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_WTAI_PB_ADD_ENTRY, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.modId));
    msf_dcvt_uint16(&cvt_obj, &(param.pbId));
    msf_dcvt_string(&cvt_obj, &(param.name));
    msf_dcvt_string(&cvt_obj, &(param.number));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_satLauchRequest (MSF_UINT8 browserMode, 
                       MSF_UINT8 browserIdentity, 
                       MSF_UINT8 wap_sim_id,
                       MSF_UINT16 noUrl,
                       unsigned char *url,
                       MSF_UINT16 noBearer,
                       unsigned char *bearer,
                       MSF_UINT16 noGateway,
                       unsigned char *gateway)
{
  bra_sat_lauch_request_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.browserMode = browserMode;
  param.browserIdentity = browserIdentity;
#ifdef BRA_CFG_DUAL_SIM
  param.sim_id = bra_sim_get_bra_sim_id(wap_sim_id);
#else
  param.sim_id = 0;
#endif
  param.noUrl = noUrl;
  param.url = url;
  param.noBearer = noBearer;
  param.bearer = bearer;
  param.noGateway = noGateway;
  param.gateway = gateway;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.browserMode));
  msf_dcvt_uint8(&cvt_obj, &(param.browserIdentity));
  msf_dcvt_uint8(&cvt_obj, &(param.sim_id));
  msf_dcvt_uint16(&cvt_obj, &(param.noUrl));
  msf_dcvt_string(&cvt_obj, (char **)&(param.url));
  msf_dcvt_uint16(&cvt_obj, &(param.noBearer));
  msf_dcvt_string(&cvt_obj, (char **)&(param.bearer));
  msf_dcvt_uint16(&cvt_obj, &(param.noGateway));
  msf_dcvt_string(&cvt_obj, (char **)&(param.gateway));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SAT_LAUCH_REQUEST, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.browserMode));
    msf_dcvt_uint8(&cvt_obj, &(param.browserIdentity));
    msf_dcvt_uint8(&cvt_obj, &(param.sim_id));
    msf_dcvt_uint16(&cvt_obj, &(param.noUrl));
    msf_dcvt_string(&cvt_obj, (char **)&(param.url));
    msf_dcvt_uint16(&cvt_obj, &(param.noBearer));
    msf_dcvt_string(&cvt_obj, (char **)&(param.bearer));
    msf_dcvt_uint16(&cvt_obj, &(param.noGateway));
    msf_dcvt_string(&cvt_obj, (char **)&(param.gateway));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}


static void bra_signalNotifyPinnedProv(MSF_UINT32 dlgHandle, MSF_UINT32 yesHandle,
                                       MSF_UINT32 noHandle, MSF_UINT8 stage, MSF_UINT32 prs_sim_id) {
    bra_prs_pinned_prov_t param;
    msf_dcvt_t  cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer;
    void *user_data;


    param.sim_id = (MSF_UINT32)bra_prs_get_bra_sim_id(prs_sim_id);
    param.dlgHandle = dlgHandle;
    param.yesHandle = yesHandle;
    param.noHandle = noHandle;
    param.stage = stage;
    
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    msf_dcvt_uint32(&cvt_obj, &(param.dlgHandle));
    msf_dcvt_uint32(&cvt_obj, &(param.yesHandle));
    msf_dcvt_uint32(&cvt_obj, &(param.noHandle));
    msf_dcvt_uint8(&cvt_obj, &(param.stage));
    msf_dcvt_uint32(&cvt_obj, &(param.sim_id));

    length = cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(BRA_SIG_NOTIFY_PINNED_PROV, 0, MSF_MODID_BRA, length);
    if (signal_buffer) {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);

        msf_dcvt_uint32(&cvt_obj, &(param.dlgHandle));
        msf_dcvt_uint32(&cvt_obj, &(param.yesHandle));
        msf_dcvt_uint32(&cvt_obj, &(param.noHandle));
        msf_dcvt_uint8(&cvt_obj, &(param.stage));
        msf_dcvt_uint32(&cvt_obj, &(param.sim_id));

        MSF_SIGNAL_SEND(signal_buffer);
    }
}

void BRAif_notifyPinnedProvDocNew(MSF_UINT32 dlgHandle, MSF_UINT32 yesHandle, MSF_UINT32 noHandle, MSF_UINT32 prs_sim_id)
{
    bra_signalNotifyPinnedProv(dlgHandle, yesHandle, noHandle, BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT, prs_sim_id);
}

void BRAif_notifyPinnedProvDocAbort(void) {
    bra_signalNotifyPinnedProv(0, 0, 0, BRA_PRS_NEW_PINNED_PROV_STAGE_ABORT, 0);
}

void BRAif_invalidProvDocRecv(void) {
    void *signal_buffer;

    signal_buffer = MSF_SIGNAL_CREATE(BRA_SIG_INVALID_PROV_RECV, 0, MSF_MODID_BRA, 0);
    if (signal_buffer)
        MSF_SIGNAL_SEND(signal_buffer);
}

void BRAif_provAuthFailed(void) {
    void *signal_buffer;

    signal_buffer = MSF_SIGNAL_CREATE(BRA_SIG_PROV_AUTH_FAILED, 0, MSF_MODID_BRA, 0);
    if (signal_buffer)
        MSF_SIGNAL_SEND(signal_buffer);
}

void BRAif_registerProvAuth(MSF_UINT32 dlgHandle, MSF_UINT32 noHandle) {
    bra_prs_pinned_prov_t param;
    msf_dcvt_t  cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer;
    void *user_data;

    param.dlgHandle = dlgHandle;
    param.noHandle = noHandle;
    
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    msf_dcvt_uint32(&cvt_obj, &(param.dlgHandle));
    msf_dcvt_uint32(&cvt_obj, &(param.noHandle));
    length = cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(BRA_SIG_REGISTER_PROV_AUTH, 0, MSF_MODID_BRA, length);
    if (signal_buffer) {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);

        msf_dcvt_uint32(&cvt_obj, &(param.dlgHandle));
        msf_dcvt_uint32(&cvt_obj, &(param.noHandle));

        MSF_SIGNAL_SEND(signal_buffer);
    }
}

void
BRAif_cancelProvConf(void) {
    void *signal_buffer;
    
    signal_buffer = MSF_SIGNAL_CREATE(BRA_SIG_CANCEL_PROV_CONF, 0, MSF_MODID_BRA, 0);
    if (signal_buffer)
        MSF_SIGNAL_SEND(signal_buffer);
}

#ifdef __UNIFIED_MSG_SUPPORT__
void
BRAif_getPushMsgNumber (void)
{
  void *signal_buffer;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_GET_PUSH_MSG_NUM, 0, MSF_MODID_BRA, 0);
  if (signal_buffer != NULL) MSF_SIGNAL_SEND (signal_buffer);
} 

void
BRAif_getPushMsgList (MSF_UINT16 startFromMsg)
{
  bra_get_push_msg_list_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.startFromMsg = startFromMsg;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint16(&cvt_obj, &(param.startFromMsg));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_GET_PUSH_MSG_LIST, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint16(&cvt_obj, &(param.startFromMsg));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_getPushMsgInfo (MSF_UINT16 startFromMsg, MSF_UINT16 numberOfMsg)
{
  bra_get_push_msg_info_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.startFromMsg = startFromMsg;
  param.numberOfMsg = numberOfMsg;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint16(&cvt_obj, &(param.startFromMsg));
  msf_dcvt_uint16(&cvt_obj, &(param.numberOfMsg));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_GET_PUSH_MSG_INFO, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint16(&cvt_obj, &(param.startFromMsg));
    msf_dcvt_uint16(&cvt_obj, &(param.numberOfMsg));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_delPushMsgInbox (void)
{
  void *signal_buffer;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_DEL_PUSH_MSG_INBOX, 0, MSF_MODID_BRA, 0);
  if (signal_buffer != NULL) MSF_SIGNAL_SEND (signal_buffer);
} 

void
BRAif_viewPushMsg (MSF_UINT16 msgIndex)
{
  bra_view_push_msg_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;
  
  param.msgIndex = msgIndex;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint16(&cvt_obj, &(param.msgIndex));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_VIEW_PUSH_MSG, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint16(&cvt_obj, &(param.msgIndex));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

#endif

/* Functions for BRS Plug-in */
static void
bra_send_extscheme (MSF_UINT8 modId, MSF_UINT8 type, MSF_UINT16 id, const char* data)
{
  bra_handle_extscheme_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  param.schType = type;
  param.modId = modId;
  param.id = id;
  param.data = (char*)data;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.schType));
  msf_dcvt_uint8(&cvt_obj, &(param.modId));
  msf_dcvt_uint16(&cvt_obj, &(param.id));
  msf_dcvt_string(&cvt_obj, &(param.data));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_HANDLE_EXTSCHEME, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.schType));
    msf_dcvt_uint8(&cvt_obj, &(param.modId));
    msf_dcvt_uint16(&cvt_obj, &(param.id));
    msf_dcvt_string(&cvt_obj, &(param.data));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_smsSend (MSF_UINT8 modId, MSF_UINT16 smsId, const char* number)
{
  bra_send_extscheme(modId, BRA_SCHEME_SMS, smsId, number);
}

void
BRAif_egeSend (MSF_UINT8 modId, MSF_UINT16 egeId, const char* egeparam)
{
  bra_send_extscheme(modId, BRA_SCHEME_EGE, egeId, egeparam);
}

void
BRAif_rtspSend (MSF_UINT8 modId, MSF_UINT16 rtspId, const char* tgturl)
{
  bra_send_extscheme(modId, BRA_SCHEME_RTSP, rtspId, tgturl);
}

void
BRAif_mmsSend (MSF_UINT8 modId, MSF_UINT16 mmsId, const char* number)
{
  bra_send_extscheme(modId, BRA_SCHEME_MMS, mmsId, number);
}

void
BRAif_handleBearerStatus (MSF_UINT8 bearer_type, MSF_UINT32 status)
{
  bra_handle_bearer_status_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  param.bearerType = bearer_type;
  param.status = status;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.bearerType));
  msf_dcvt_uint32(&cvt_obj, &(param.status));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_BEARER_STATUS, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.bearerType));
    msf_dcvt_uint32(&cvt_obj, &(param.status));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_selectBookmark (MSF_UINT8 srcModId)
{
  bra_select_bookmark_t  param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  param.srcModId = srcModId;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.srcModId));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SELECT_BOOKMARK, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.srcModId));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_downloadComplete(MSF_UINT8 status)
{
  bra_download_complete_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  param.status = status;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.status));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_DOWNLOAD_COMPLETE, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.status));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_notifyBearerInfo(MSF_UINT8 bearer, MSF_UINT8 status)
{
  bra_notify_bearer_info_t   param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  param.bearer = bearer;
  param.status = status;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.bearer));
  msf_dcvt_uint8(&cvt_obj, &(param.status));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_NOTIFY_BEARER_INFO, 0,
                                     MSF_MODID_BRA, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.bearer));
    msf_dcvt_uint8(&cvt_obj, &(param.status));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

void
BRAif_DADownloadInfo(MSF_UINT32 jobCount, MSF_UINT32 activeJobCount)
{
    bra_da_download_info_t   param;
    msf_dcvt_t               cvt_obj;
    MSF_UINT16               length;
    void                    *signal_buffer, *user_data;
    
    param.jobCount = jobCount;
    param.activeJobCount = activeJobCount;

    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    msf_dcvt_uint32(&cvt_obj, &(param.jobCount));
    msf_dcvt_uint32(&cvt_obj, &(param.activeJobCount));
    length = (MSF_UINT16)cvt_obj.pos;
    
    signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_DA_DOWNLOAD_INFO_IND, 0,
        MSF_MODID_BRA, length);
    
    if (signal_buffer != NULL) {
        user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
        msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
        msf_dcvt_uint32(&cvt_obj, &(param.jobCount));
        msf_dcvt_uint32(&cvt_obj, &(param.activeJobCount));
        MSF_SIGNAL_SEND (signal_buffer);
    }
}


/**********************************************************************
 * BRA CCA interface
 **********************************************************************/

#ifdef BRA_CFG_CCA

static int
bra_cca_cvt_app_configure(msf_dcvt_t *cvt_obj, bra_cca_app_configure_ind_t *p)
{
  if (!msf_dcvt_uint16(cvt_obj, &(p->sim_id)) ||
	  !msf_dcvt_uint16(cvt_obj, &(p->config_id)) ||
	  !msf_dcvt_int32(cvt_obj, &(p->hConfig)) ||
	  !msf_dcvt_int32(cvt_obj, &(p->num_symbols)) ||
	  !msf_dcvt_array(cvt_obj, sizeof(MSF_UINT16), (int)(p->num_symbols),
	  				  (void * *)&(p->l1symbols), (msf_dcvt_element_t *)msf_dcvt_uint16) ||
	  !msf_dcvt_array(cvt_obj, sizeof(MSF_INT32), (int)(p->num_symbols),
						(void * *)&(p->l1symbols_count), (msf_dcvt_element_t *)msf_dcvt_int32))
	{
	   return FALSE;
	}
	return TRUE;
}


static int
bra_cca_cvt_get_profile(msf_dcvt_t* cvt_obj, bra_cca_get_prof_ind_t* p)
{
  if (!msf_dcvt_uint16(cvt_obj, &(p->sim_id)) ||
      !msf_dcvt_uint16(cvt_obj, &(p->app_id)) ||
 	  !msf_dcvt_int32(cvt_obj, &(p->prof_id))) 
  {
	return FALSE;
  }
  return TRUE;
}


static int
bra_cca_cvt_update_profile(msf_dcvt_t* cvt_obj, bra_cca_update_prof_ind_t* p)
{
  if (!msf_dcvt_uint16(cvt_obj, &(p->sim_id)) ||
      !msf_dcvt_uint16(cvt_obj, &(p->app_id)) ||
  	  !msf_dcvt_int32(cvt_obj, &(p->prof_id)) ||
	  !msf_dcvt_int32(cvt_obj, &(p->hConfig))) 
  {
     return FALSE;
  }
  return TRUE;
}






void
BRAif_CcaAppConfigure(MSF_UINT16 cca_sim_id, MSF_UINT16 config_id,
                      MSF_INT32 hConfig, MSF_INT32 num_symbols, 
                      MSF_UINT16* l1symbols, MSF_INT32* l1symbols_count)
{
  MSF_UINT16                length;
  msf_dcvt_t                cvt_obj;
  void                      *user_data;
  void                      *signal_buffer;
  bra_cca_app_configure_ind_t  param;
	

  param.sim_id = bra_cca_get_bra_sim_id(cca_sim_id);
  param.config_id = config_id;
  param.hConfig = hConfig;
  param.num_symbols = num_symbols;
  param.l1symbols = l1symbols;
  param.l1symbols_count = l1symbols_count;
	
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cca_cvt_app_configure(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CCA_APP_CONFIGURE_IND, 0,
		                             MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
	user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
	msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
	bra_cca_cvt_app_configure(&cvt_obj, &param);
	MSF_SIGNAL_SEND (signal_buffer);
  }
}


void 
BRAif_CcaGetProfile(MSF_UINT16 cca_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id)
{
  MSF_UINT16              length;
  msf_dcvt_t              cvt_obj;
  void                    *user_data;
  void                    *signal_buffer;
  bra_cca_get_prof_ind_t  param;
	
	
  param.sim_id = bra_cca_get_bra_sim_id(cca_sim_id);
  param.app_id = app_id;
  param.prof_id = prof_id;
	
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cca_cvt_get_profile(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CCA_GET_PROF_IND, 0,
                                     MSF_MODID_BRA, length);
	
  if (signal_buffer != NULL) 
  {
	user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
	msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
	bra_cca_cvt_get_profile(&cvt_obj, &param);
 	MSF_SIGNAL_SEND (signal_buffer);
  }
}


void
BRAif_CcaUpdateProfile(MSF_UINT16 cca_sim_id, MSF_UINT16 app_id, MSF_INT32 prof_id, MSF_INT32 hConfig)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;
  bra_cca_update_prof_ind_t  param;
	
	
  param.sim_id = bra_cca_get_bra_sim_id(cca_sim_id);
  param.app_id = app_id;
  param.prof_id = prof_id;
  param.hConfig = hConfig;
	
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cca_cvt_update_profile(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CCA_UPDATE_PROF_IND, 0,
                                     MSF_MODID_BRA, length);
	
  if (signal_buffer != NULL) 
  {
 	user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
	msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
	bra_cca_cvt_update_profile(&cvt_obj, &param);
	MSF_SIGNAL_SEND (signal_buffer);
  }
}

#endif /*BRA_CFG_CCA*/





#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN

static int
bra_set_cvt_handle_net_id_select_response(msf_dcvt_t *cvt_obj, bra_net_id_select_rsp_t *p)
{
  if (!msf_dcvt_bool(cvt_obj, &(p->result)) ||
      !msf_dcvt_uint16(cvt_obj, &(p->app_id)) ||
      !msf_dcvt_uint32(cvt_obj, &(p->id_num))  ||
      !msf_dcvt_uint32(cvt_obj, &(p->bearer_scope)) ||
      !msf_dcvt_array(cvt_obj, sizeof(MSF_UINT32), BRA_MULITI_NET_ID_MAX_NUM,
      (void * *)&(p->bearer_type), (msf_dcvt_element_t *)msf_dcvt_uint32) ||
      !msf_dcvt_array(cvt_obj, sizeof(MSF_UINT32), BRA_MULITI_NET_ID_MAX_NUM,
                     (void * *)&(p->net_id), (msf_dcvt_element_t *)msf_dcvt_uint32))
  {
    return FALSE;
  }
  return TRUE;
}



void
BRAif_handleNetIdSelectResponse(MSF_BOOL result, MSF_UINT16 app_id,
                                MSF_UINT32 id_num, MSF_UINT32 bearer_scope, 
                                MSF_UINT32 *bearer_type, MSF_UINT32 *net_id)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;  
  bra_net_id_select_rsp_t    param;
    
    
  param.result = result;
  param.app_id = app_id;
  param.id_num = id_num;
  param.bearer_scope = bearer_scope;
  param.bearer_type = bearer_type;
  param.net_id = net_id;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_set_cvt_handle_net_id_select_response(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_NET_ID_SELECT_RSP, 0, MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bra_set_cvt_handle_net_id_select_response(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }  
}

#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/







/* BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND */

static int
bra_cbm_cvt_select_result(msf_dcvt_t *cvt_obj, bra_cbm_select_result_t *p)
{
  if (!msf_dcvt_uint32(cvt_obj, &(p->acct_id)) ||
    !msf_dcvt_bool(cvt_obj, &(p->result)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


void
BRAif_cbmSelectResult(MSF_UINT32 acct_id, MSF_BOOL result)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;  
  bra_cbm_select_result_t    param;
  
  
  param.result = result;
  param.acct_id = acct_id;
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cbm_cvt_select_result(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CBM_SELECT_ACCOUNT_RESULT_IND,
    0, MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bra_cbm_cvt_select_result(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }  
}


/* BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF */

static int
bra_cbm_cvt_add_bearer_status_notify(msf_dcvt_t *cvt_obj, 
                                     bra_cbm_add_bearer_status_notify_t *p)
{
  if (!msf_dcvt_uint8(cvt_obj, &(p->index)) ||
    !msf_dcvt_bool(cvt_obj, &(p->result)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


void
BRAif_cbmAddBearerStatusNotify(MSF_UINT8 index, MSF_BOOL result)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;  
  bra_cbm_add_bearer_status_notify_t    param;
  
  
  param.result = result;
  param.index = index;
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cbm_cvt_add_bearer_status_notify(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CBM_ADD_BEARER_STATUS_NOTIFY_CNF,
    0, MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bra_cbm_cvt_add_bearer_status_notify(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }  
}


/* BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF */

static int
bra_cbm_cvt_del_bearer_status_notify(msf_dcvt_t *cvt_obj, 
                                     bra_cbm_del_bearer_status_notify_t *p)
{
  if (!msf_dcvt_uint32(cvt_obj, &(p->acct_id)) ||
    !msf_dcvt_bool(cvt_obj, &(p->result)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


void
BRAif_cbmDelBearerStatusNotify(MSF_UINT32 acct_id, MSF_BOOL result)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;  
  bra_cbm_del_bearer_status_notify_t    param;
  
  
  param.result = result;
  param.acct_id = acct_id;
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cbm_cvt_del_bearer_status_notify(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CBM_DEL_BEARER_STATUS_NOTIFY_CNF,
    0, MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bra_cbm_cvt_del_bearer_status_notify(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }  
}


/* BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND */

static int
bra_cbm_cvt_bearer_status_notify(msf_dcvt_t *cvt_obj, bra_cbm_bearer_status_notify_t *p)
{
  if (!msf_dcvt_uint32(cvt_obj, &(p->acct_id)) ||
    !msf_dcvt_uint32(cvt_obj, &(p->status)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


void
BRAif_cbmBearerStatusNotify(MSF_UINT32 acct_id, MSF_UINT32 status)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;  
  bra_cbm_bearer_status_notify_t    param;
  
  
  param.status = status;
  param.acct_id = acct_id;
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_cbm_cvt_bearer_status_notify(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND,
    0, MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bra_cbm_cvt_bearer_status_notify(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }  
}





#ifdef BRA_CFG_DUAL_SIM

/* BRA_SIG_CBM_BEARER_STATUS_NOTIFY_IND */

static int
bra_sim_cvt_sim_info_notify(msf_dcvt_t *cvt_obj, bra_sim_info_notify_t *p)
{
  if (!msf_dcvt_uint8(cvt_obj, &(p->sim_status)) ||
    !msf_dcvt_uint8(cvt_obj, &(p->setting_mode)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


void
BRAif_handleSimInfoNotify(MSF_UINT8 sim_status, MSF_UINT8 setting_mode)
{
  MSF_UINT16                 length;
  msf_dcvt_t                 cvt_obj;
  void                       *user_data;
  void                       *signal_buffer;  
  bra_sim_info_notify_t      param;
  
  
  param.sim_status = bra_sim_get_bra_sim_id((int)sim_status);
  param.setting_mode = bra_sim_get_bra_sim_id((int)setting_mode);
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bra_sim_cvt_sim_info_notify(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SIM_INFO_NOTIFY_IND,
    0, MSF_MODID_BRA, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bra_sim_cvt_sim_info_notify(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }  
}


#endif /* BRA_CFG_DUAL_SIM */




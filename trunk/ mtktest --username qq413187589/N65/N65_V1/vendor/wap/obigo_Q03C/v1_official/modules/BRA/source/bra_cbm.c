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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * bra_cbm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   CBM handler
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 *
 *******************************************************************************/



#ifndef _bra_cfg_h
#include "bra_cfg.h"
#endif 






#include "bra_int.h" 
#include "bra_cmn.h"
#include "bra_prof.h"
#include "bra_file.h"
#include "bra_main.h"
#include "bra_str.h"
#include "bra_win.h"
#include "bra_dlg.h"
#include "bra_if.h"
#include "bra_set.h"
#include "bra_cbm.h"
#include "bra_view.h"

#include "brs_if.h"
#include "msf_log.h"
#include "msf_core.h"
#include "msf_chrt.h"
#include "msf_cfg.h"

#ifdef BRA_CONFIG_MMS
#include "mea_def.h"
#include "mea_cfg.h"
#include "mms_def.h"
#include "msf_url.h"
#include "mms_aApp.h"
#endif /* BRA_CONFIG_MMS */

#include "msm.h"
#include "kal_release.h"
#include "wapadp.h"
#include "wap_ps_struct.h"


#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif




typedef enum
{
    BRA_CBM_STATUS_INIT,
    BRA_CBM_STATUS_CREATE_UI,
    BRA_CBM_STATUS_DESTROY_UI,
    BRA_CBM_STATUS_MAX_ITEM
}bra_cbm_status_enum;



typedef struct  
{  
    bra_cbm_status_enum         status;
    MSF_UINT8                   mms_app_id;
    MSF_UINT8                   bra_app_id;
    MSF_UINT8                   bra_index;    /* bearer status notify index */
    MSF_BOOL                    valid_net_id; /* acct_id is unsigned value, can not use -1 to indicate invalid value*/
    MSF_UINT32                  ext_net_id;  /* net id selected after asked */
}bra_cbm_context_t;


static bra_cbm_context_t  bra_cbm_cntx;




static void
bra_cbm_reset_cbm_context(void);

#ifdef BRA_CFG_CONN_ALWAYS_ASK

static void
bra_cbm_send_ask_select_result_cnf(MSF_UINT32 ext_net_id, MSF_BOOL result);

static void
bra_cbm_send_add_bearer_status_notify_req(MSF_UINT32 ext_net_id);

#endif /* BRA_CFG_CONN_ALWAYS_ASK */

static void
bra_cbm_send_del_bearer_status_notify_req(MSF_UINT32 ext_net_id, MSF_UINT8 index);

static void
bra_cbm_delete_bearer_status_notify(void);



#ifdef __CBM_CM_FEATURE__

static void
bra_cbm_send_view_bearer_detail_info_ind(MSF_UINT32 type, MSF_UINT32 ext_net_id);

#endif /* __CBM_CM_FEATURE__ */













MSF_UINT8
bra_cbm_get_app_id(int prof_type)
{
    if (prof_type == BRA_PROF_ID_BRA)
        return bra_cbm_cntx.bra_app_id;
    else if (prof_type == BRA_PROF_ID_MMS)
        return bra_cbm_cntx.mms_app_id;
    else
        return 0;
        
}


MSF_UINT8 
bra_cbm_get_bra_app_id(void)
{
    return bra_cbm_cntx.bra_app_id;
}


MSF_UINT8
bra_cbm_get_mms_app_id(void)
{
    return bra_cbm_cntx.mms_app_id;
}


MSF_UINT32 
bra_cbm_get_bra_asked_ext_net_id(void)
{
    return bra_cbm_cntx.ext_net_id;
}


MSF_BOOL 
bra_cbm_is_bra_asked_ext_net_id_valid(void)
{
    return bra_cbm_cntx.valid_net_id;
}


void 
bra_cbm_reset_ext_net_id(void)
{
    bra_cbm_cntx.ext_net_id = 0;
    bra_cbm_cntx.valid_net_id = FALSE;
}


MSF_UINT8 
bra_cbm_get_bra_bearer_status_notify_index(void)
{
    return bra_cbm_cntx.bra_index;
}


int
bra_cbm_get_cbm_sim_id(int bra_sim_id)
{
    int   cbm_sim_id = ALWAYS_ASK_SIM_INFO_DEFAULT;


#ifdef BRA_CFG_DUAL_SIM
    
    switch(bra_sim_id)
    {
        //    case BRA_SIM_ID_DEFAULT:
        //        cbm_sim_id = ALWAYS_ASK_SIM_INFO_DEFAULT;
        break;
        
    case BRA_SIM_ID_SIM1:
        cbm_sim_id = ALWAYS_ASK_SIM_INFO_SIM1;
        break;
        
    case BRA_SIM_ID_SIM2:
        cbm_sim_id = ALWAYS_ASK_SIM_INFO_SIM2;
        break;
    
    case BRA_SIM_ID_DUAL_SIM:
        cbm_sim_id = ALWAYS_ASK_SIM_INFO_SIM1;
    default:
        cbm_sim_id = ALWAYS_ASK_SIM_INFO_DEFAULT;
        break;
    }
#endif /* BRA_CFG_DUAL_SIM */

   return cbm_sim_id;
}


void
bra_cbm_init(void)
{
    bra_cbm_reset_cbm_context();

    /* register WAP */
    bra_cbm_cntx.bra_app_id = (MSF_UINT8)always_ask_register_app_id(BRA_STR_ID_BROWSER);
    always_ask_register_acct_select_notify((kal_uint8)bra_cbm_cntx.bra_app_id,
        REGISTER_TYPE_PRIMITIVE, (kal_uint32)MOD_WAP, NULL);

#ifdef BRA_CONFIG_MMS
    bra_cbm_cntx.mms_app_id = (MSF_UINT8)always_ask_register_app_id(BRA_STR_ID_MMS);
    always_ask_register_acct_select_notify((kal_uint8)bra_cbm_cntx.mms_app_id,
        REGISTER_TYPE_PRIMITIVE, (kal_uint32)MOD_WAP, NULL);
#endif /* BRA_CONFIG_MMS */
}


void
bra_cbm_terminate(void)
{
    always_ask_deregister_acct_select_notify((kal_uint8)bra_cbm_cntx.bra_app_id,
        REGISTER_TYPE_PRIMITIVE, (kal_uint32)MOD_WAP, NULL);
    always_ask_deregister_app_id((kal_uint8)bra_cbm_cntx.bra_app_id);
    
#ifdef BRA_CONFIG_MMS
    always_ask_deregister_acct_select_notify((kal_uint8)bra_cbm_cntx.mms_app_id,
        REGISTER_TYPE_PRIMITIVE, (kal_uint32)MOD_WAP, NULL);
    always_ask_deregister_app_id((kal_uint8)bra_cbm_cntx.mms_app_id);
#endif /* BRA_CONFIG_MMS */

    bra_cbm_delete_bearer_status_notify();

    bra_cbm_reset_cbm_context();
}


void
bra_cbm_create_ui(void)
{
    if (bra_cbm_cntx.status == BRA_CBM_STATUS_CREATE_UI)
        return;
    bra_cbm_delete_bearer_status_notify();
    bra_cbm_reset_ext_net_id();
    bra_cbm_cntx.status = BRA_CBM_STATUS_CREATE_UI;
}

void 
bra_cbm_destroy_ui(void)
{
   if (bra_cbm_cntx.status != BRA_CBM_STATUS_CREATE_UI)
       return;
   bra_cbm_delete_bearer_status_notify();
   bra_cbm_reset_ext_net_id();
   bra_cbm_cntx.status = BRA_CBM_STATUS_DESTROY_UI;
}


static void
bra_cbm_reset_cbm_context(void)
{
    bra_cbm_cntx.mms_app_id = 0;
    bra_cbm_cntx.bra_app_id = 0;
    bra_cbm_cntx.bra_index = 0;
    bra_cbm_reset_ext_net_id();
    bra_cbm_cntx.status = BRA_CBM_STATUS_INIT;
}


//MSG_ID_MMI_ALWAYS_ASK_SELEDT_ACCOUNT_RESULT_IND


void
bra_cbm_handle_ask_select_result(void *p)
{
#ifdef BRA_CFG_CONN_ALWAYS_ASK

    bra_cbm_select_result_t *data;


    data = (bra_cbm_select_result_t*)p;

    /* check if already exist the browser */
    if (bra_cbm_cntx.status != BRA_CBM_STATUS_CREATE_UI || !bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    {
      bra_cbm_send_ask_select_result_cnf(data->acct_id, data->result);
      return;
    }
    /*check if user already canceled or status is deleted because of some reason */
    if (bra_view_is_user_cancelled() || !bra_view_is_busy()) 
    {
        data->result = FALSE;
    }
    if (data->result == FALSE)
    {
        bra_cbm_delete_bearer_status_notify();
        bra_cbm_reset_ext_net_id();
        bra_view_cancel_loading();
    }
    else
    {
        /* first delete old bearer status notify */
        if (bra_cbm_cntx.valid_net_id == FALSE || bra_cbm_cntx.ext_net_id != data->acct_id)
        {
            bra_cbm_delete_bearer_status_notify();

            /* keep this net id*/
            bra_cbm_cntx.ext_net_id = data->acct_id;
            bra_cbm_cntx.valid_net_id = TRUE;
            bra_prof_change_key_int_value(bra_prof_get_profile_id(), 
                BRA_PROF_KEY_NET_ID_ASKED, data->acct_id, NULL);
            BRAa_setBearerType((int)data->acct_id);
            bra_cmn_check_profile_checksum();
            /* then add new bearer status notify */
            bra_cbm_send_add_bearer_status_notify_req(bra_cbm_cntx.ext_net_id);
            bra_view_set_request_timer();

#ifdef BRA_CFG_USE_SPLASH
            if (!bra_view_if_has_viewable_page() && !bra_view_get_paintbox())
            {
                bra_view_reset_splash_timer();
                bra_view_set_splash_timer();
            }
#endif /* BRA_CFG_USE_SPLASH */
        }
    }
    bra_cbm_send_ask_select_result_cnf(data->acct_id, data->result);
    
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
}


#ifdef BRA_CFG_CONN_ALWAYS_ASK

static void
bra_cbm_send_ask_select_result_cnf(MSF_UINT32 ext_net_id, MSF_BOOL result)
{
  MYQUEUE                                                 message;
  mmi_cbm_always_ask_select_account_result_cnf_struct     *data;   
  
  
  data = (mmi_cbm_always_ask_select_account_result_cnf_struct *)OslConstructDataPtr(sizeof(mmi_cbm_always_ask_select_account_result_cnf_struct));
  data->acct_id = (kal_uint32)ext_net_id;
  data->result = result;
  
  message.oslSrcId       = MOD_WAP;
  message.oslDestId      = MOD_MMI;
  message.oslMsgId       = MSG_ID_MMI_CBM_ALWAYS_ASK_SELECT_ACCOUNT_RESULT_CNF;
  message.oslDataPtr     = (oslParaType *)data;
  message.oslPeerBuffPtr = NULL;
  
  OslMsgSendExtQueue(&message);
}


static void
bra_cbm_send_add_bearer_status_notify_req(MSF_UINT32 ext_net_id)
{
    MYQUEUE                                         message;
    mmi_cbm_add_bearer_status_notify_req_struct     *data;   
    

    data = (mmi_cbm_add_bearer_status_notify_req_struct *)OslConstructDataPtr(sizeof(mmi_cbm_add_bearer_status_notify_req_struct));
    data->acct_id = (kal_uint32)ext_net_id;
    data->mod_id = MOD_WAP;

    message.oslSrcId       = MOD_WAP;
    message.oslDestId      = MOD_MMI;
    message.oslMsgId       = MSG_ID_MMI_CBM_ADD_BEARER_STATUS_NOTIFY_REQ;
    message.oslDataPtr     = (oslParaType *)data;
    message.oslPeerBuffPtr = NULL;
    
    OslMsgSendExtQueue(&message);
}

#endif /* BRA_CFG_CONN_ALWAYS_ASK */

void
bra_cbm_handle_add_bearer_status_notify(void *p)
{
    bra_cbm_add_bearer_status_notify_t *data;

    
    if (bra_cbm_cntx.status == BRA_CBM_STATUS_DESTROY_UI)
        return;
    data = (bra_cbm_add_bearer_status_notify_t*)p;
    if (data->result == TRUE)
    {
        bra_cbm_cntx.bra_index = data->index;
    }
    else
    {
        /* should already remove the old index here */
        bra_cbm_cntx.bra_index = 0;
    }
}


static void
bra_cbm_send_del_bearer_status_notify_req(MSF_UINT32 ext_net_id, MSF_UINT8 index)
{
    MYQUEUE                                         message;
    mmi_cbm_del_bearer_status_notify_req_struct     *data;   
    
    data = (mmi_cbm_del_bearer_status_notify_req_struct *)OslConstructDataPtr(sizeof(mmi_cbm_del_bearer_status_notify_req_struct));
    data->acct_id = (kal_uint32)ext_net_id;
    data->index = (kal_uint8)index;
    data->mod_id = MOD_WAP;
    
    message.oslSrcId       = MOD_WAP;
    message.oslDestId      = MOD_MMI;
    message.oslMsgId       = MSG_ID_MMI_CBM_DEL_BEARER_STATUS_NOTIFY_REQ;
    message.oslDataPtr     = (oslParaType *)data;
    message.oslPeerBuffPtr = NULL;
    
    OslMsgSendExtQueue(&message);
}


void
bra_cbm_handle_del_bearer_status_notify(void *p)
{
    bra_cbm_del_bearer_status_notify_t *data;


    if (bra_cbm_cntx.status == BRA_CBM_STATUS_DESTROY_UI)
        return;
    data = (bra_cbm_del_bearer_status_notify_t*)p;
    if (data->result == TRUE)
    {
        bra_cbm_cntx.bra_index = 0; /* only reset index, don not reset net id here */
    }
    else
    {
        //how to do here??
    }
}


static void
bra_cbm_delete_bearer_status_notify(void)
{
    if (bra_cbm_cntx.bra_index > 0)
    {
        bra_cbm_send_del_bearer_status_notify_req(bra_cbm_cntx.ext_net_id, 
            bra_cbm_cntx.bra_index);
        bra_cbm_cntx.bra_index = 0;
    }
}


void
bra_cbm_handle_bearer_status_notify(void *p)
{
    bra_cbm_bearer_status_notify_t *data;
    
    
    if (bra_cbm_cntx.status == BRA_CBM_STATUS_DESTROY_UI)
        return;
     data = (bra_cbm_bearer_status_notify_t*)p;
    if (bra_cbm_cntx.ext_net_id != data->acct_id)
    {
        ASSERT(!"the net id is not matched!");
        return;
    }
	if (data->status == CBM_BEARER_STATE_ACTIVATED)
		bra_cbm_cntx.valid_net_id = TRUE;
	if (data->status == CBM_BEARER_STATE_DEACTIVATED)
		bra_cbm_cntx.valid_net_id = FALSE;
}


MSF_UINT32
bra_cbm_get_using_ext_net_id(void)
{
    /* if always ask is true, use select net id, else use net id in activated profile,
     * here, BRA type is ok, just not CMN   */
    return bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
}


int 
bra_cbm_is_need_to_ask(void)
{
    int   ext_net_id;

    
    ext_net_id = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
    return always_ask_is_always_ask_data_account((kal_uint32)ext_net_id);
}


#ifdef __CBM_CM_FEATURE__
static void
bra_cbm_send_view_bearer_detail_info_ind(MSF_UINT32 type, MSF_UINT32 ext_net_id)
{
    MYQUEUE                                             message;
    mmi_cbm_app_entry_bearer_detail_info_ind_struct     *data;   
    
    data = (mmi_cbm_app_entry_bearer_detail_info_ind_struct *)OslConstructDataPtr(sizeof(mmi_cbm_app_entry_bearer_detail_info_ind_struct));
    data->acct_id = (kal_uint32)ext_net_id;
    data->entry_type  = (mmi_cbm_entry_type_enum)type; 
    
    message.oslSrcId       = MOD_WAP;
    message.oslDestId      = MOD_MMI;
    message.oslMsgId       = MSG_ID_MMI_CBM_APP_ENTRY_BEARER_DETAIL_INFO_IND;
    message.oslDataPtr     = (oslParaType *)data;
    message.oslPeerBuffPtr = NULL;
    
    OslMsgSendExtQueue(&message);
}

void
bra_cbm_create_view_bearer_detail_info_menu(void)
{
   bra_cbm_send_view_bearer_detail_info_ind(MMI_CBM_ENTRY_DETAIL_SCREEN,
       bra_cbm_get_using_ext_net_id());
}


#endif /* __CBM_CM_FEATURE__ */









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
 * Filename:
 * ---------
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef __J2ME__

#include "MMI_features.h"

/* MTK: Paul added for Java */

/*  Include: MMI header file */
#include "StdC.h"
#include "L4Dr1.h"
#include "L4Dr.h"
#include "Unicodexdcl.h"
#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "historyGprot.h"
#include "ProtocolEvents.h"
#include "wgui_categories.h"
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */
// #include "Wallpaper.h" // need POPUP_DURATION
#include "SettingDefs.h"        // need STR_SCREENSAVER_EMPTY/*Cylen 0926, customize display char*/
#include "kal_trace.h"
#include "DebugInitDef.h"
#include "mmi_trc.h"
#include "ProfileGprots.h"      /* need MYQUEUE */
#include "PhoneBookDef.h"       /* need IMG_PROCESSING_PHONEBOOK */
#include "GlobalConstants.h"    /* need MAX_SUB_MENUS */
#include "EventsGprot.h"        /* subMenuData */
#include "TimerEvents.h"
#include "WrapperGprot.h"
/*  Include: J2ME header file */
#include "jam_msg_handler.h"
#include "j2me_trace.h"
#include "wap_ps_struct.h"

/* ... Add More MMI header */
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "mmiapi.h"
#include "idleappdef.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "idleappdef.h"
#include "EventsDcl.h"
#include "simdetectiongexdcl.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "NVRAMEnum.h"
#include "DateTimeGprot.h"  /* mmi_dt_utc_sec_2_mytime*/

/* ... Add media headers */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "CallmanagementIdDef.h"

#include "wap.h"
#include "gui_setting.h"
#include "wgui.h"
#include "jal.h"
#include "jvm_adaptor.h"
#include "j2me_custom.h"
#include "j2me_custom_option.h"

#include "drm_gprot.h"
#include "drm_def.h"

#include "RightsMgrGProt.h" /* mmi_rmgr_populate_drm_info*/

#ifdef __MMI_MY_FAVORITE__
#include "MyFavoriteGProt.h"
#include "MyFavoriteResDef.h"
#endif

/************************************************************************/
/* Golbal Variable                                          */
/************************************************************************/

U8 g_mmi_java_aud_volume_level = 0xff;  /* 0~6 */
U8 g_mmi_java_is_vib_on = FALSE;        /* on-off */
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
U8 g_mmi_java_is_net_icon_on = TRUE;
#endif
U8 g_mmi_java_wap_prof_id = 0;
kal_bool g_mmi_java_get_wap_prof_ok = KAL_TRUE;

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
U8 g_mmi_java_vk_permission = 0;    /* J2ME_Choice in JavaAgencyDef.h */
#endif 


static kal_bool get_setting_only = KAL_FALSE;
static kal_bool get_domain_setting = KAL_FALSE;
static S8* gJavaPrintableStr;

java_context_struct g_java;

/*
 * Extern Variable
 */

extern kal_eventgrpid J2ME_getlist_event_group;
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);

/*****************************************************************************
 * FUNCTION
 *  InitJAVA
 * DESCRIPTION
 *  Invoked by InitFunAndGamesApp to init highlight/hint/protocol event handlers and
 *  Java MMI context for Java MMI/CM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitJAVA(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Hilite Handlers */

    SetHiliteHandler(MENU_JAVA_EM_NORMAL, mmi_java_highlight_em_normal);
    SetHiliteHandler(MENU_JAVA_EM_CLDC_TCK, mmi_java_highlight_em_cldc_tck);
    SetHiliteHandler(MENU_JAVA_EM_MIDP_TCK, mmi_java_highlight_em_midp_tck);
    SetHiliteHandler(MENU_JAVA_EM_WMAPI_TCK, mmi_java_highlight_em_wma_tck);
    SetHiliteHandler(MENU_JAVA_EM_MMAPI_TCK, mmi_java_highlight_em_mmapi_tck);

    /* Protocol handler */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_confirm_ind, MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_cnf, MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_stop_ind, MSG_ID_MMI_JAVA_MID_STOP_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_file_and_save_ind, MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_start_cnf, MSG_ID_MMI_JAVA_MID_START_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_getinfo_cnf, MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_set_setting_cnf, MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_delete_confirm_ind, MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_delete_cnf, MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_set_mode_cnf, MSG_ID_MMI_JAVA_SET_MODE_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_update_cnf, MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_timealarm_push_ind, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_wap_abort_cnf, MSG_ID_MMI_WAP_ABORT_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_java_abort_cnf, MSG_ID_MMI_JAVA_ABORT_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_show_alert_user_req, MSG_ID_MMI_JAVA_SHOW_ALERT_USER_DIALOG_REQ);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_reset_rms_ind, MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_IND);

    /* Local install AT command */

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_at_local_install_req, MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ_IND);

    /* DRM local install */

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_drm_local_install_req, MSG_ID_WAP_MMI_JAVA_INTALL_REQ);

    /* User Permission */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_permission_ind, MSG_ID_MMI_JAVA_GET_PERMISSION_IND);

    /* User Confirm */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_confirm_ind, MSG_ID_MMI_JAVA_GET_CONFIRM_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_show_percentage_ind, MSG_ID_MMI_JAVA_SHOW_PERCENTAGE_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_install_drv_ind, MSG_ID_MMI_JAVA_GET_INSTALL_DRV_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_auth_ind, MSG_ID_MMI_JAVA_GET_AUTH_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_imsi_ind, MSG_ID_MMI_JAVA_GET_IMSI_IND);

    /* InFusio Eureka */
#ifdef __SUPPORT_INFUSIO__
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_infudio_eureka_start_req, MSG_ID_WAP_MMI_EUREKA_START_REQ);
#endif /* __SUPPORT_INFUSIO__ */

#if defined(J2ME_SUPPORT_PAUSE)
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_pause_ind, MSG_ID_MMI_JAVA_PAUSE_IND);
#endif

    g_java.total_java_app_mids = 0;
    g_java.total_java_app_mid = 0;

    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
    g_java.mids_delete_state = DELETE_VALID_STATE;
    g_java.msg_ctrl = 0;
    mmi_java_load_setting();
    gJavaPrintableStr = (S8*)subMenuData;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_reset_state
 * DESCRIPTION
 *  Reset java stat, let install, update, and delete all availble
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_reset_state()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
    g_java.mids_delete_state = DELETE_VALID_STATE;
    g_java.msg_ctrl = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_menu
 * DESCRIPTION
 *  Highlight handler routine for Java menu item in FunAndGames menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void Highlight_JAVA_MENU(void) */
void mmi_java_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryScrJavaMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrJavaMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_get_list_req
 * DESCRIPTION
 *  Send message to java task, and get the MIDlet list back
 * PARAMETERS
 *  start_index     [IN]        The start point of the list
 *  extend_mode     [IN]        Send message and sync with java side, get list from pointer of pointer
 *  ptr             [OUT]       Pointer to the pointer of the list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_get_list_req(int start_index, kal_bool extend_mode, mmi_java_mids_getlist_cnf_struct **ptr)
/* void MIDSGetListReq(int start_index,kal_bool extend_mode,mmi_java_mids_getlist_cnf_struct **ptr) */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_getlist_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GETLIST_REQ);

    msg = (mmi_java_mids_getlist_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_getlist_req_struct));
    msg->session_id = 0;
    msg->game_type = GAMETYPE_JAVA_GAME;
    msg->start_indx = start_index;
    msg->mids_list_count = -1;
    msg->extend_mode = extend_mode;
    msg->confirm_data_ptr = ptr;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_GETLIST_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_fetch_mids_list
 * DESCRIPTION
 *  
 *  get the (item_index)th mids from java
 *  
 *  cache item_index ~ item_index+MMI_MAX_MENUITEMS_IN_CONTENT
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        == null  => void If imeage_full= null  => void
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 *  image_buff_p: a pointer , will be assigned to the image icon of mids(?)
 *  needToSendGetListReq:  If (item_index)th mids in cache(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool needToSendGetListReq = KAL_TRUE;

/* pBOOL j2me_fetch_mids_list( S32 item_index, UI_string_type str_buff, PU8* img_buff_p, U8 str_img_mask ) */
pBOOL mmi_java_fetch_mids_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (needToSendGetListReq)
    {
        /* only check the first item_index fetch request */
        if (item_index < g_java.total_java_app_mids
            && g_java.mids_info_start <= item_index &&
            (g_java.mids_info_end == g_java.total_java_app_mids ||
             item_index + MMI_MAX_MENUITEMS_IN_CONTENT < g_java.mids_info_end))
        {
            needToSendGetListReq = KAL_FALSE;
            /* nothing to do, because data is in cache. */
        }
        else
        {
            /* search the cache */
            int i;
            kal_uint32 event_group;
            mmi_java_mids_getlist_cnf_struct *ptr;
            kal_int32 saved_item_index = item_index;

            /* scroll up, item_index - 3 for speeding up */
            if (g_java.mids_info_start > saved_item_index)
            {
                saved_item_index -= JAVA_LIST_CACHE_COUNT - MMI_MAX_MENUITEMS_IN_CONTENT;
                if (saved_item_index < 0)
                {
                    saved_item_index = 0;
                }
            }

            if (g_java.total_java_app_mids < saved_item_index + JAVA_LIST_CACHE_COUNT)
            {
                saved_item_index = g_java.total_java_app_mids - JAVA_LIST_CACHE_COUNT;
            }
            mmi_java_send_mids_get_list_req(saved_item_index, KAL_TRUE, &ptr);
            kal_retrieve_eg_events(J2ME_getlist_event_group, 1, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

            for (i = 0; i < ptr->mids_list_count; i++)
            {
                g_java.mids_info[i] = ptr->pmids_list[i];
            }

            g_java.mids_info_start = ptr->start_indx;
            g_java.mids_info_end = ptr->start_indx + ptr->mids_list_count;
            g_java.total_java_app_mids = ptr->mids_count;

            free_local_para((local_para_struct*) ptr);
            needToSendGetListReq = KAL_FALSE;

        }
    }
    else
    {
        if (!(item_index < g_java.total_java_app_mids
              && g_java.mids_info_start <= item_index && item_index < g_java.mids_info_end))
        {
            ASSERT(0);
        }
    }

    if (g_java.total_java_app_mids == 0)
    {
        return KAL_TRUE;
    }

    ASSERT(g_java.mids_info_start <= item_index && item_index < g_java.mids_info_end);

    /* fetch the icon */
    if (img_buff_p)
    {
        if (g_java.mids_info[item_index - g_java.mids_info_start].mids_icon != NULL)
        {
            (*img_buff_p) = (PU8) g_java.mids_info[item_index - g_java.mids_info_start].mids_icon;
        }
        else
        {
            if (g_java.mids_info[item_index - g_java.mids_info_start].mid_count == 1)
            {
                (*img_buff_p) = (PU8) GetImage(IMG_JAVA_STAR1);
            }
            else
            {
                (*img_buff_p) = (PU8) GetImage(IMG_JAVA_STAR2);
            }
        }
    }
    /* fetch the item name */

    if (str_buff)
    {
        mmi_ucs2ncpy(
            (S8*) str_buff,
            (const S8*)g_java.mids_info[item_index - g_java.mids_info_start].mids_name,
            MAX_SUBMENU_CHARACTERS);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  flushListCache
 * DESCRIPTION
 *  flush the list cacahe
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void flushListCache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    needToSendGetListReq = KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_menu_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_menu_ask_terminate_cb(BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_JAVA_MENU;
        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }
 }


/*****************************************************************************
 * FUNCTION
 *  EntryScrJavaMenu
 * DESCRIPTION
 *  Enter the Java menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrJavaMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef J2ME_SUPPORT_PAUSE
    if (jvm_is_pause_mode())
    {
        if( jvm_get_initiate_game_type() == GAMETYPE_JAVA_GAME )
        {
            mmi_java_entry_resume_dialog();
        }
        else if( jvm_get_initiate_game_type() == GAMETYPE_INFUSIO_EUREKA)
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_entry_menu_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_EUREKA));
        }
        else
        {
            mmi_java_display_is_busy();
        }
        return;
    }
#endif /* J2ME_SUPPORT_PAUSE */

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    g_java.mids_info_end = g_java.mids_info_start = -1;

    /* get list at the very beginning */
    needToSendGetListReq = KAL_TRUE;

    mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);

    count = g_java.total_java_app_mids;

#ifdef __MMI_MY_FAVORITE__

    count += mmi_my_favorite_javabox_waplink_count();
    if (count == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SCREENSAVER_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);
    }

    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_JAVA);

        EntryNewScreen(SCR_JAVA, NULL, EntryScrJavaMenu, NULL);
        RegisterHighlightHandler(mmi_my_favorite_javabox_highlight_hdlr);
        if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
        {
            ShowCategory185Screen(
                STR_ID_MY_FAVORITE_FOLDER_JAVABOX,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_my_favorite_javabox_get_item_callback,
                NULL,
                0,
                KAL_TRUE,
                flushListCache,
                guiBuffer);
        }
        else
        {
            needToSendGetListReq = KAL_FALSE;
            ShowCategory184Screen(
                STR_ID_MY_FAVORITE_FOLDER_JAVABOX,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_my_favorite_javabox_get_item_callback,
                NULL,
                0,
                guiBuffer);
        }
        SetKeyHandler(mmi_my_favorite_back_to_main, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_my_favorite_back_to_main, KEY_EVENT_UP);
    }
#else

    if (count == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SCREENSAVER_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);
    }
    else
    {

        guiBuffer = GetCurrGuiBuffer(SCR_JAVA);

        EntryNewScreen(SCR_JAVA, NULL, EntryScrJavaMenu, NULL);
        RegisterHighlightHandler(mmi_java_highlight_get_mids_index);

        if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
        {
            ShowCategory185Screen(
                STR_SCR_JAVA_CAPTION,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_java_fetch_mids_list,
                NULL,
                0,
                KAL_TRUE,
                flushListCache,
                guiBuffer);
        }
        else
        {
            needToSendGetListReq = KAL_FALSE;
            ShowCategory184Screen(
                STR_SCR_JAVA_CAPTION,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_java_fetch_mids_list,
                NULL,
                0,
                guiBuffer);
        }
        SetLeftSoftkeyFunction(mmi_java_entry_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_java_entry_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
#endif

    mmi_java_load_setting();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_get_mids_index
 * DESCRIPTION
 *  Set the handler of the highlight item
 * PARAMETERS
 *  nIndex      [IN]        The index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_get_mids_index(S32 nIndex) */
void mmi_java_highlight_get_mids_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MIDS_INDEX);

    g_java.mids_index = nIndex;
    g_java.mid_index = 0;

    SetLeftSoftkeyFunction(mmi_java_entry_opt, KEY_EVENT_UP);
#ifdef __MMI_MY_FAVORITE__
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else
    SetKeyHandler(mmi_java_entry_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem; /* Stores no of children in the submenu */
    S32 maskingByte = -1;
    kal_uint8 attrib;
    S32 menuItemId;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_APP_MIDS_OPTION, NULL, mmi_java_entry_opt, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_APP_MIDS_OPTION);

    nNumofItem = GetNumOfChild(MENU_JAVA_APP_MIDS_OPTION);
    GetSequenceStringIds(MENU_JAVA_APP_MIDS_OPTION, (PU16) nStrItemList);
    SetParentHandler(MENU_JAVA_APP_MIDS_OPTION);

    SetHiliteHandler(MENU_JAVA_APP_OPTION_SELECT, mmi_java_highlight_opt_select);
    SetHiliteHandler(MENU_JAVA_APP_OPTION_LAUNCH, mmi_java_highlight_opt_launch);
    SetHiliteHandler(MENU_JAVA_APP_OPTION_UPDATE, mmi_java_highlight_opt_update);
    SetHiliteHandler(MENU_JAVA_APP_OPTION_SETTING, mmi_java_highlight_opt_setting);
    SetHiliteHandler(MENU_JAVA_APP_OPTION_INFO, mmi_java_highlight_opt_info);
    SetHiliteHandler(MENU_JAVA_APP_OPTION_DELETE, mmi_java_highlight_opt_delete);

    attrib = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_attributes;

    if (g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count == 1)
    {
        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_JAVA_APP_MIDS_OPTION, MENU_JAVA_APP_OPTION_SELECT);
        ResetBit(maskingByte, menuItemId);

    }
    else
    {
        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_JAVA_APP_MIDS_OPTION, MENU_JAVA_APP_OPTION_LAUNCH);
        ResetBit(maskingByte, menuItemId);
    }

    if (attrib & IS_DEFAULT_GAME)
    {
        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_JAVA_APP_MIDS_OPTION, MENU_JAVA_APP_OPTION_UPDATE);
        ResetBit(maskingByte, menuItemId);
        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_JAVA_APP_MIDS_OPTION, MENU_JAVA_APP_OPTION_DELETE);

        ResetBit(maskingByte, menuItemId);
    }

    if (!(attrib & CAN_BE_UPDATE))
    {
        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_JAVA_APP_MIDS_OPTION, MENU_JAVA_APP_OPTION_UPDATE);
        ResetBit(maskingByte, menuItemId);
    }
    if (!(attrib & CAN_BE_REMOVE))
    {
        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_JAVA_APP_MIDS_OPTION, MENU_JAVA_APP_OPTION_DELETE);
        ResetBit(maskingByte, menuItemId);
    }
    MaskHiliteItems(MENU_JAVA_APP_MIDS_OPTION, maskingByte);
    nNumofItem = MaskItems((PU16) nStrItemList, (U8) nNumofItem, maskingByte);

    /* 7. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8. Display Category15 Screen */
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        mmi_java_get_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        (PU16) nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_select
 * DESCRIPTION
 *  Highlight handler routine for Select menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.is_select_after_install = FALSE;
    SetLeftSoftkeyFunction(mmi_java_send_mid_getlist_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_send_mid_getlist_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_launch
 * DESCRIPTION
 *  Highlight handler routine for Launch menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.is_select_after_install = FALSE;
    SetLeftSoftkeyFunction(mmi_java_send_mid_getlist_req, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_update
 * DESCRIPTION
 *  Highlight handler routine for Update menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_entry_mids_update, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_setting
 * DESCRIPTION
 *  Highlight handler routine for Setting menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_save_opt_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_save_opt_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_info
 * DESCRIPTION
 *  Highlight handler routine for Information menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_send_mids_getinfo_req, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_delete
 * DESCRIPTION
 *  Highlight handler routine for Delete menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_send_mids_delete_req, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mid_getlist_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MID_GETLIST_REQ to MOD_J2ME to get list of
 *  MID and set protocol event handler of MSG_ID_MMI_JAVA_MID_GETLIST_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mid_getlist_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mid_getlist_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        g_java.is_select_after_install = FALSE;
        return;
    }

    /* sometime will quickly re-entry this function before
       java handle this message  */
    if (g_java.msg_ctrl & SEND_MID_GET_LIST_CTRL)
    {
        return;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_GET_LIST_CTRL;
    }

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MID_GETLIST_REQ);

    msg = (mmi_java_mid_getlist_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_getlist_req_struct));
    msg->session_id = 0;
    msg->game_type = GAMETYPE_JAVA_GAME;
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MID_GETLIST_REQ;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_getlist_cnf, MSG_ID_MMI_JAVA_MID_GETLIST_CNF);
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mid_getlist_cnf
 * DESCRIPTION
 *  This is the message "MMI_JAVA_RECV_MID_GETLIST_CNF" handler.
 *  The structure of the message contains the list of MIDlet in MIDlet suite
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mid_getlist_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mid_getlist_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MID_GETLIST_CNF);

    g_java.msg_ctrl &= (~SEND_MID_GET_LIST_CTRL);

    if (mmi_java_is_in_voice_call())
    {
        g_java.is_select_after_install = FALSE;
        return;
    }

    msg = (mmi_java_mid_getlist_cnf_struct*) MsgStruct;
    if (msg->error_code == J2ME_NO_ERROR)
    {
        U8 i;

        g_java.total_java_app_mid = msg->mid_count;

        for (i = 0; i < g_java.total_java_app_mid; i++)
        {
            g_java.mid_info[i].mid_id = msg->pmid_list[i].mid_id;
            g_java.mid_info[i].mid_icon = (U8*) msg->pmid_list[i].mid_icon;
            g_java.mid_info[i].mid_name = (U8*) msg->pmid_list[i].mid_name;
        }

        if (g_java.total_java_app_mid == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_SCREENSAVER_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                EMPTY_LIST_TONE);
        }
        else if (g_java.total_java_app_mid == 1)
        {
            mmi_java_send_mid_start_req(GAMETYPE_JAVA_GAME);
        }
        else
        {
            mmi_java_entry_opt_select();
        }
    }
    else
    {
        g_java.total_java_app_mid = 0;
        DisplayPopup(
            (PU8) GetString(STR_SCREENSAVER_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mid_launch
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_entry_mid_launch(void)
{
	mmi_java_send_mid_start_req(GAMETYPE_JAVA_GAME);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mid_launch_from_idle
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_entry_mid_launch_from_idle(void)
{
    if( g_java.is_launch_after_install )
    {
        g_java.is_launch_after_install = FALSE;
	    mmi_java_send_mid_start_req(GAMETYPE_JAVA_GAME);
    }
#ifdef __SUPPORT_INFUSIO__
    else if( g_java.is_launch_eureka_by_wap )
    {
        g_java.is_launch_eureka_by_wap = FALSE;

        g_java.mids_info_start = g_java.mids_info_end = 0;
        g_java.mids_index = g_java.mid_index = 0;
        g_java.total_java_app_mids = g_java.total_java_app_mid = 1;
        g_java.mids_info[0].mids_id = 1;
        g_java.mids_info[0].mid_count = 1;
        g_java.mid_info[0].mid_id = 1;

        mmi_java_send_mid_start_req(GAMETYPE_INFUSIO_EUREKA);
    }
#endif
    else
    {
        ASSERT(0);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mid_start_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MID_START_REQ to MOD_J2ME to launch
 *  MIDlet and set protocol event handler of MSG_ID_MMI_JAVA_MID_START_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mid_start_req(game_type_enum game_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mid_start_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    /* sometime will quickly re-entry this function before
       java handle this message  */
    if (g_java.msg_ctrl & SEND_MID_START_CTRL)
    {
        return;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_START_CTRL;
    }

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MID_START_REQ);

    msg = (mmi_java_mid_start_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_start_req_struct));
    msg->session_id = 0;
    msg->game_type = game_type;
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;
    msg->mid_id = g_java.mid_info[g_java.mid_index].mid_id;
    msg->wap_prof_id = g_mmi_java_wap_prof_id;

    jvm_enter_screen();

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MID_START_REQ;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_start_cnf, MSG_ID_MMI_JAVA_MID_START_CNF);
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mid_start_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MID_START_CNF from MOD_J2ME
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mid_start_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mid_start_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MID_START_CNF);

    g_java.msg_ctrl &= (~SEND_MID_START_CTRL);

    msg = (mmi_java_mid_start_cnf_struct*) MsgStruct;
    if (msg->error_code == J2ME_NO_ERROR)
    {
    }
    else
    {
        /* the previous start_req is not a valid request,
           no stop_ind will receive */
        /* J2ME_enter_screen(); has been called, we have to roll back status */
        jvm_exit_screen_callback();
        mmi_java_display_is_busy();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mid_stop_ind
 * DESCRIPTION
 *  This routines handles the message "MSG_ID_MMI_JAVA_MID_STOP_IND"
 *  Indicates that java stop MIDlets.
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mid_stop_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mid_stop_ind_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_mid_stop_ind_struct*) MsgStruct;

    mmi_java_send_mid_stop_res(msg->session_id);

    mmi_java_terminating_time_out_hdlr();

    if( g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA)
    {
        EntryNewScreen(SCR_JAVA_DUMMY, NULL, mmi_java_mids_install_internal, NULL);
    }
    else if( g_java.screen_after_terminate == TER_ENTRY_JAVA_MENU)
    {
        EntryNewScreen(SCR_JAVA_DUMMY, NULL, EntryScrJavaMenu, NULL);
    }
    else if( g_java.screen_after_terminate == TER_ENTRY_LAUNCH_AFTER_INSTALL)
    {
        EntryNewScreen(SCR_JAVA_DUMMY, NULL, mmi_java_launch_after_install_confirm_yes_hdlr, NULL);
    }
#ifdef __SUPPORT_INFUSIO__
    else if( g_java.screen_after_terminate == TER_ENTRY_EUREKA_BY_MENU)
    {
        EntryNewScreen(SCR_JAVA_DUMMY, NULL, mmi_java_entry_eureka_by_menu, NULL);
    }
    else if( g_java.screen_after_terminate == TER_ENTRY_EUREKA_BY_WAP)
    {
        EntryNewScreen(SCR_JAVA_DUMMY, NULL, mmi_java_entry_eureka_by_wap , NULL);
    }
#endif

    g_java.screen_after_terminate = TER_ENTRY_NONE;

    DisplayPopup((PU8) GetString(STR_JAVA_STOPPED), IMG_JAVA_POWERED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_JAVA_VM_TERMINATING);
    DeleteScreenIfPresent(SCR_JAVA_GET_PERMISSION);
    DeleteScreenIfPresent(SCR_JAVA_GET_CONFIRM);

    mmi_java_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mid_stop_res
 * DESCRIPTION
 *  When we receive "MSG_ID_MMI_JAVA_MID_STOP_IND", we should send
 *  response message "MMI_JAVA_RECV_MID_STOP_IND".
 * PARAMETERS
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mid_stop_res(kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mid_stop_res_struct *msg2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MID_STOP_IND);

    msg2 = (mmi_java_mid_stop_res_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_stop_res_struct));
    msg2->session_id = session_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MID_STOP_RES;
    Message.oslDataPtr = (local_para_struct*) msg2;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_getinfo_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ to MOD_J2ME to get info of
 *  MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_getinfo_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_getinfo_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GETINFO_REQ);

    msg = (mmi_java_mids_getinfo_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_getinfo_req_struct));
    msg->session_id = 0;
    msg->game_type = GAMETYPE_JAVA_GAME;
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_getinfo_cnf, MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF);
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_getinfo_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GETINFO_CNF from MOD_J2ME to display
 *  specific information about assigned MIDS
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_java_mids_getinfo_cnf_struct* mids_getinfo_cnf_msg = NULL;

void mmi_java_recv_mids_getinfo_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_GETINFO_CNF);

    if( mids_getinfo_cnf_msg )
    {
        if(mids_getinfo_cnf_msg->mids_info.mids_filename)
        {
            free_ctrl_buffer(mids_getinfo_cnf_msg->mids_info.mids_filename);
        }
        free_local_para((local_para_struct *)mids_getinfo_cnf_msg);
    }

    hold_local_para((local_para_struct *)MsgStruct);

    mids_getinfo_cnf_msg = (mmi_java_mids_getinfo_cnf_struct *)MsgStruct;

    mmi_java_entry_opt_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_transform_mids_info
 * DESCRIPTION
 *  This rountain parse the information in the MIDlet which send by message
 *  "MMI_JAVA_RECV_MIDS_GETINFO_CNF". We parse the MIDlet and layout the
 *  the information on screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_transform_mids_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mids_getinfo_cnf_msg->error_code == J2ME_NO_ERROR)
    {
        gJavaPrintableStr = (S8*)subMenuData;
        kal_mem_set(gJavaPrintableStr, 0, MAX_SUB_MENUS * MAX_SUB_MENU_SIZE);

        if (mids_getinfo_cnf_msg->mids_info.mids_name != NULL)
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_NAME));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_name);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_size > 0)
        {
            S8 java_size[10];

            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_SIZE));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            sprintf(java_size, "%u", mids_getinfo_cnf_msg->mids_info.mids_size);
            mmi_asc_to_ucs2(
                (PS8) & gJavaPrintableStr[mmi_ucs2strlen((PS8) gJavaPrintableStr) << 1],
                (PS8) java_size);
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_BYTE));
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_version != NULL)
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_VERSION));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_version);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_vendor != NULL)
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_VENDOR));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_vendor);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_description != NULL)
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_DESC));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_description);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_webside != NULL)
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_WEB));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_webside);
        }

        if ((mids_getinfo_cnf_msg->mids_info.mids_authorized == KAL_TRUE) &&
            (mids_getinfo_cnf_msg->mids_info.mids_authorized_by != NULL))
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_AUTH));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_authorized_by);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_auto_start_connection != NULL)
        {
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_CONN));
            mmi_ucs2cat(gJavaPrintableStr, (PS8) L" ");
            mmi_ucs2cat(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_auto_start_connection);
        }
    #ifdef __DRM_SUPPORT__

        if (mids_getinfo_cnf_msg->mids_info.mids_filename!= NULL )
        {
	        mmi_ucs2cat(gJavaPrintableStr, (PS8) L"\n-----\n");
            mmi_rmgr_populate_drm_info( (kal_wchar*)mids_getinfo_cnf_msg->mids_info.mids_filename, DRM_PERMISSION_EXECUTE, (kal_uint8*)gJavaPrintableStr);
        }
    #endif /* __DRM_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_info
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options->Information Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem; /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // U16 nStrItemList[MAX_SUB_MENUS]; /* Stores the strings id of submenus returned */

    /* gFlagDontAddHistOnScroll=1; */

    EntryNewScreen(SCR_JAVA_APP_OPTION_INFO, NULL, mmi_java_entry_opt_info, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_APP_OPTION_INFO);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_JAVA_APP_OPTION_INFO);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* GetSequenceStringIds(MENU_JAVA_APP_OPTION_INFO,nStrItemList); */

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_JAVA_APP_OPTION_INFO);

    /* 7. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_java_transform_mids_info();
    /* 8. Display Category74 Screen */
    ShowCategory74Screen(
        STR_JAVA_APP_OPTION_INFO,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) gJavaPrintableStr,
        mmi_ucs2strlen((PS8) gJavaPrintableStr),
        NULL);

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_save_opt_setting
 * DESCRIPTION
 *  Seclecting "Setting", we well send request to java to get the specific
 *  MIDlet setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_execute_opt_setting (void) */
void mmi_java_save_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    g_java.domain = -1;  /* for specific midlet */

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_get_setting_cnf, MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
    mmi_java_send_mids_get_setting_req(0, g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_get_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ to MOD_J2ME to get setting of
 * MIDS
 *  
 * PARAMETERS
 *  session_id      [IN]        
 *  mids_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_get_setting_req(kal_uint32 session_id, kal_uint32 mids_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_get_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GET_SETTING_REQ);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_mids_get_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_get_setting_req_struct));
    msg->session_id = session_id;
    msg->game_type = GAMETYPE_JAVA_GAME;
    msg->mids_id = mids_id;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_get_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_J2ME to display
 *  permission screen to user to modify
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_get_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_GET_SETTING_CNF);

    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;

    if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
    {
        g_java.mids_trusted = (U8) msg->mids_trusted;

        kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
        kal_mem_cpy(&(g_java.mids_max_setting), &(msg->mids_max_setting), sizeof(mmi_setting_struct));
    }

    if(!get_setting_only)
    {
        get_domain_setting = KAL_FALSE;
        mmi_java_entry_opt_setting();
    }

    get_setting_only = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_set_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ to MOD_J2ME to set setting of
 *  MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_set_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_set_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_SET_SETTING_REQ);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    if( g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_SET_SETTING_CTRL;
        msg = (mmi_java_mids_set_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_set_setting_req_struct));
        msg->session_id = 0;
        msg->game_type = GAMETYPE_JAVA_GAME;
        msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

        kal_mem_cpy(&(msg->mids_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_J2ME;
        Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ;
        SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_set_setting_cnf, MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF);
        Message.oslDataPtr = (local_para_struct*) msg;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_set_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_SET_SETTING_CNF from MOD_J2ME
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_set_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_SET_SETTING_CNF);

    msg = (mmi_java_mids_set_setting_cnf_struct*) MsgStruct;

    if ( g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_OK),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        /* only get the setting from Java again to update the latest setting value since exclusive setting may automatically
            update other setting value*/
        get_setting_only = KAL_TRUE;
        mmi_java_send_mids_get_setting_req(0, g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id);
        g_java.msg_ctrl &= (~SEND_MID_SET_SETTING_CTRL);
    }
    DeleteScreenIfPresent(SCR_JAVA_APP_OPTION_SETTING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_choice_level
 * DESCRIPTION
 *  Transfer PERMISSION_LEVEL to J2ME_CHOICE_LEVEL
 * PARAMETERS
 *  permisisonLevel     [IN]        Level of PERMISSION_LEVEL
 * RETURNS
 *  level of J2ME_CHOICE_LEVEL
 *****************************************************************************/
S8 mmi_java_get_choice_level(S8 permisisonLevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (permisisonLevel)
    {
        case PERMISSION_ALLOW:
        case PERMISSION_BLANKET_GRANTED:
            selected = J2ME_CHOICE_BLANKET;
            break;

        case PERMISSION_BLANKET:
            if(get_domain_setting)
            {
                selected = J2ME_CHOICE_BLANKET;
				break;
            }
        case PERMISSION_SESSION:
            selected = J2ME_CHOICE_SESSION;
            break;

        case PERMISSION_ONE_SHOT:
        case PERMISSION_DENY_SESSION:
            selected = J2ME_CHOICE_ONESHOT;
            break;

        case PERMISSION_NEVER:
        case PERMISSION_DENY:
        case PERMISSION_USER_DENIED:
            selected = J2ME_CHOICE_USERDENY;
            break;

        default:
            selected = J2ME_CHOICE_USERDENY;
            break;
    }

    return selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_perm_menu_item_count
 * DESCRIPTION
 *  Get the menu item count form a maximum permission level.
 * PARAMETERS
 *  max_level               [IN]        
 *  permisisonLevel(?)      [IN]        Level of maximum PERMISSION_LEVEL
 * RETURNS
 *  level of J2ME_CHOICE_LEVEL
 *****************************************************************************/
S32 mmi_java_get_perm_menu_item_count(S8 max_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (max_level)
    {
        case PERMISSION_ALLOW:
        case PERMISSION_BLANKET_GRANTED:
        case PERMISSION_BLANKET:
            return 4;

        case PERMISSION_SESSION:
            return 3;

        case PERMISSION_ONE_SHOT:
        case PERMISSION_DENY_SESSION:
            return 2;

        case PERMISSION_NEVER:
        case PERMISSION_DENY:
        case PERMISSION_USER_DENIED:
            return 1;

        default:
            return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_new_permission_level
 * DESCRIPTION
 *  transfer J2ME_CHOICE_LEVEL to PERMISSION_LEVEL
 * PARAMETERS
 *  choiceLevel     [IN]        Level of J2ME_CHOICE_LEVEL
 * RETURNS
 *  level of PERMISSION_LEVEL
 *****************************************************************************/
S8 mmi_java_get_new_permission_level(S8 choiceLevel, S8 max_settings, S8 org_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (choiceLevel)
    {
        case J2ME_CHOICE_BLANKET:
            if(max_settings == PERMISSION_ALLOW)
                selected = (S8) PERMISSION_ALLOW;
            else
            selected = (S8) PERMISSION_BLANKET_GRANTED;
            break;
        case J2ME_CHOICE_SESSION:
            selected = (S8) PERMISSION_SESSION;
            break;
        case J2ME_CHOICE_ONESHOT:
            selected = (S8) PERMISSION_ONE_SHOT;
            break;
        case J2ME_CHOICE_USERDENY:
			if(org_setting == PERMISSION_NEVER)
				selected = (S8) PERMISSION_NEVER;
			else
            selected = (S8) PERMISSION_USER_DENIED;
            break;
        default:
            selected = (S8) PERMISSION_USER_DENIED;
            break;
    }

    return selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_update_mids_setting
 * DESCRIPTION
 *  Update setting of the MIDLet
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_update_mids_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
    BOOL modification_not_allowed = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    for( i = 0 ; i < J2ME_SETTING_MAX ;i ++)
    {
        switch (i)
        {
            case J2ME_SETTING_NETWORK_ACCESS:
            if((g_java.mids_setting.permission_network == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_network == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }

                g_java.mids_setting.permission_network = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_network, 
																				(S8)g_java.mids_setting.permission_network);
                break;
            case J2ME_SETTING_AUTO_INVOCATION:
            if((g_java.mids_setting.permission_push == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_push == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }
                g_java.mids_setting.permission_push = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_push, 
																				(S8)g_java.mids_setting.permission_push);
                break;
            case J2ME_SETTING_MESSAGING:
            if((g_java.mids_setting.permission_message == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_message == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }
                g_java.mids_setting.permission_message = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_message, 
																				(S8)g_java.mids_setting.permission_message);
                break;
            case J2ME_SETTING_MULTIMEDIA:
            if((g_java.mids_setting.permission_multimedia == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_multimedia == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }
                g_java.mids_setting.permission_multimedia = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_multimedia, 
																				(S8)g_java.mids_setting.permission_multimedia);
                break;
            case J2ME_SETTING_DATA_READ:
            if((g_java.mids_setting.permission_data_read == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_data_read == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }
                g_java.mids_setting.permission_data_read = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_data_read, 
																				(S8)g_java.mids_setting.permission_data_read);
                break;
            case J2ME_SETTING_DATA_WRITE:
            if((g_java.mids_setting.permission_data_write == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_data_write == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }
                g_java.mids_setting.permission_data_write = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_data_write, 
																				(S8)g_java.mids_setting.permission_data_write);
                break;
            case J2ME_SETTING_LOCAL_CONNECTIVITY:
            if((g_java.mids_setting.permission_local_connectivity == PERMISSION_ALLOW && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_BLANKET) ||
                (g_java.mids_setting.permission_local_connectivity == PERMISSION_NEVER && 
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = KAL_TRUE;
                    break;
                }
                g_java.mids_setting.permission_local_connectivity = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_local_connectivity, 
																				(S8)g_java.mids_setting.permission_local_connectivity);
                break;
          }
    }
    if(modification_not_allowed){

        DisplayPopup(
            (PU8) GetString(STR_JAVA_PERMISSION_SETTING_FAIL),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_JAVA_APP_OPTION_SETTING);
        return;
    }

    #ifdef OGDR_SECURITY_SETTING
    if( g_java.domain >= 0 )
    {
        mmi_java_send_set_default_domain_req();
    }
    else
    #endif
    {
        mmi_java_send_mids_set_setting_req();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_setting_highlight_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_java_update_mids_setting);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_exit_opt_setting
 * DESCRIPTION
 *  exit point for java setting screen
 * PARAMETERS
 *  void
 *  viud(?)     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_exit_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_JAVA_APP_OPTION_SETTING;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_java_entry_opt_setting;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_setting
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options->Setting Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	U8 *inputBuffer;
	U16 inputBufferSize;
//    S32 item_offset = 0;
    MMI_ID_TYPE item_icons[] =
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
        IMG_GLOBAL_L5,
        0,
        IMG_GLOBAL_L6,
        0,
        IMG_GLOBAL_L7,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_APP_OPTION_SETTING, mmi_java_exit_opt_setting, NULL, NULL);

    InitializeCategory57Screen();

    g_java.mids_choice_index[0] = mmi_java_get_choice_level(g_java.mids_setting.permission_network);
    g_java.mids_choice_index[1] = mmi_java_get_choice_level(g_java.mids_setting.permission_push);
    g_java.mids_choice_index[2] = mmi_java_get_choice_level(g_java.mids_setting.permission_message);
    g_java.mids_choice_index[3] = mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia);
    g_java.mids_choice_index[4] = mmi_java_get_choice_level(g_java.mids_setting.permission_data_read);
    g_java.mids_choice_index[5] = mmi_java_get_choice_level(g_java.mids_setting.permission_data_write);
    g_java.mids_choice_index[6] = mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity);

    g_java.mids_choice_str[0] = (U16*)GetString(STR_JAVA_PERM_USERDENY);
    g_java.mids_choice_str[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT );
    g_java.mids_choice_str[2] = (U16*)GetString(STR_JAVA_PERM_SESSION );
    if(get_domain_setting)
    {
        g_java.mids_choice_str[3] = (U16*)GetString(STR_JAVA_PERM_BLANKET);
    }
    else
    {
        g_java.mids_choice_str[3] = (U16*)GetString(STR_JAVA_PERM_BLANKET_GRANTED);
    }

    SetInlineItemCaption(&wgui_inline_items[0],  (PU8) GetString((U16) (STR_JAVA_SETTING_NETWORK_ACCESS )));
    SetInlineItemCaption(&wgui_inline_items[2],  (PU8) GetString((U16) (STR_JAVA_SETTING_AUTO_INVOCATION)));
    SetInlineItemCaption(&wgui_inline_items[4],  (PU8) GetString((U16) (STR_JAVA_SETTING_MESSAGING      )));
    SetInlineItemCaption(&wgui_inline_items[6],  (PU8) GetString((U16) (STR_JAVA_SETTING_MULTIMEDIA     )));
    SetInlineItemCaption(&wgui_inline_items[8],  (PU8) GetString((U16) (STR_JAVA_SETTING_FILE_READ      )));
    SetInlineItemCaption(&wgui_inline_items[10], (PU8) GetString((U16) (STR_JAVA_SETTING_FILE_WRITE     )));
    SetInlineItemCaption(&wgui_inline_items[12],  (PU8) GetString((U16) (STR_JAVA_SETTING_LOCAL_CONNECTIVITY      )));

    SetInlineItemActivation(&wgui_inline_items[1],  INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[3],  INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[5],  INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[7],  INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[9],  INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[13], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(&wgui_inline_items[1],  mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_network    ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[0]);
    SetInlineItemSelect(&wgui_inline_items[3],  mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_push       ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[1]);
    SetInlineItemSelect(&wgui_inline_items[5],  mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_message    ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[2]);
    SetInlineItemSelect(&wgui_inline_items[7],  mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_multimedia ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[3]);
    SetInlineItemSelect(&wgui_inline_items[9],  mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_read  ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[4]);
    SetInlineItemSelect(&wgui_inline_items[11], mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_write ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[5]);
    SetInlineItemSelect(&wgui_inline_items[13], mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_local_connectivity ), (U8 **) g_java.mids_choice_str, &g_java.mids_choice_index[6]);


    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_APP_OPTION_SETTING);

    inputBuffer = GetCurrNInputBuffer(SCR_JAVA_APP_OPTION_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 14 , inputBuffer);
    }


    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_JAVA_APP_OPTION_SETTING);

    /* 7. Register highlight handler to be called in menu screen */
//    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    RegisterHighlightHandler(mmi_java_setting_highlight_hdlr);

    /* 8. Display Category74 Screen */
    ShowCategory57Screen(
        STR_JAVA_APP_OPTION_SETTING,
        mmi_java_get_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        14,
        (PU16) item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_java_update_mids_setting);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_delete_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ to MOD_J2ME to send
 *  delete request of MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF and
 *  MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_remove_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_REQ);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    if (g_java.mids_delete_state == DELETE_VALID_STATE)
    {
        msg = (mmi_java_mids_remove_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_remove_req_struct));
        msg->session_id = 0;
        msg->game_type = GAMETYPE_JAVA_GAME;
        msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_J2ME;
        Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ;
        SetProtocolEventHandler(
            (PsFuncPtr) mmi_java_recv_mids_delete_confirm_ind,
            MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND);
        SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_delete_cnf, MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF);
        Message.oslDataPtr = (local_para_struct*) msg;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        g_java.mids_delete_state = DELETE_START_STATE;
    }
    else
    {
        mmi_java_display_is_busy();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_delete_confirm_ind
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_REMOVE_CONFIRM_IND from MOD_J2ME to
 *  prompt user whether or not delete assigned MIDS
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_java_mids_remove_confirm_ind_struct remove_cnf_ind_msg;
void mmi_java_recv_mids_delete_confirm_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_java.mids_delete_state == DELETE_START_STATE)
    {
        kal_mem_cpy(
            &remove_cnf_ind_msg,
            (mmi_java_mids_remove_confirm_ind_struct*) MsgStruct,
            sizeof(mmi_java_mids_remove_confirm_ind_struct));
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_CONFIRM_IND);
        mmi_java_entry_mids_delete_confirm();
        g_java.mids_delete_state = DELETE_CONFIRM_STATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_delete_confirm
 * DESCRIPTION
 *  Delete Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_delete_confirm_ind(void) */
void mmi_java_entry_mids_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_DELETE_CONFIRM, NULL, mmi_java_entry_mids_delete_confirm, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_DELETE_CONFIRM);

    str = (U8*) remove_cnf_ind_msg.confirm_msg;

    ShowCategory74Screen(
        STR_JAVA_DELETE,
        mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((PS8) str),
        NULL);

    SetKeyHandler(mmi_java_mids_delete_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_mids_delete_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_mids_delete_confirm_no_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_delete_confirmed
 * DESCRIPTION
 *  Deleting screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_delete_confirmed(void) */
void mmi_java_entry_mids_delete_confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_DELETING, NULL, mmi_java_entry_mids_delete_confirmed, NULL);
    ShowCategory66Screen(
        STR_JAVA_DELETING,
        mmi_java_get_title_icon(),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_JAVA_DELETING),
        IMG_PROCESSING_PHONEBOOK,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_delete_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle function, revoked when user select yes to confirm delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_delete_confirm_res_yes(void) */
void mmi_java_mids_delete_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    mmi_java_send_mids_delete_confirm_res(KAL_TRUE);
    mmi_java_entry_mids_delete_confirmed();
    g_java.mids_delete_state = DELETE_VM_STATE;
    DeleteScreenIfPresent(SCR_JAVA_DELETE_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_delete_confirm_no_hdlr
 * DESCRIPTION
 *  Handle function, revoked when user select yes to confirm delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_delete_confirm_res_no(void) */
void mmi_java_mids_delete_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    GoBackHistory();    /* this goback history is called by keypress */
    mmi_java_send_mids_delete_confirm_res(KAL_FALSE);
    g_java.mids_delete_state = DELETE_FINISH_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_delete_confirm_cancel_hdlr
 * DESCRIPTION
 *  Handle function, revoked when user press "END" key in the "DELETE CONFIRM"
 *  screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_delete_confirm_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_java_send_mids_delete_confirm_res(KAL_FALSE);
    g_java.mids_delete_state = DELETE_FINISH_STATE;
    DisplayIdleScreen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_delete_confirm_res
 * DESCRIPTION
 *  This routines send positive MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES to MOD_J2ME
 *  to send confirmed delete request of MIDS and set protocol event handler of
 *  MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF
 * PARAMETERS
 *  confirm     [IN]        KAL_TRUE if really want to delete this MIDS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_delete_confirm_res(kal_bool confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_mids_remove_confirm_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_CONFIRM_RES);

    /* ClearInputEventHandler(MMI_DEVICE_ALL); */

    msg =
        (mmi_java_mids_remove_confirm_res_struct*)
        OslConstructDataPtr(sizeof(mmi_java_mids_remove_confirm_res_struct));
    msg->session_id = 0;
    msg->confirm = confirm;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_delete_cnf, MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_delete_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_REMOVE_CNF from MOD_J2ME to
 *  indicate user whether or not delete action is successful
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_delete_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_remove_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_CNF);

    msg = (mmi_java_mids_remove_cnf_struct*) MsgStruct;

    if (g_java.mids_delete_state > DELETE_VALID_STATE && g_java.mids_delete_state != DELETE_INVALID_STATE)
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
            DisplayPopup(
                (PU8) GetString(STR_JAVA_DELETED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            DeleteUptoScrID(SCR_JAVA);
        }
        else if (msg->error_code != J2ME_USER_CANCEL)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_JAVA);
        }
        g_java.mids_delete_state = DELETE_FINISH_STATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_option_select
 * DESCRIPTION
 *  Handle function: revoked when user change selection in "OPTION" menu.
 * PARAMETERS
 *  nIndex      [IN]        Index of selection
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_get_mid_index(S32 nIndex) */
void mmi_java_highlight_option_select(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MID_INDEX);

    g_java.mid_index = nIndex;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_select
 * DESCRIPTION
 *  Show the "OPTION" screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = g_java.total_java_app_mid;
    if (count == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SCREENSAVER_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            EMPTY_LIST_TONE);
    }
    else
    {
        U8 i;
        U8 *MID_Names[MAX_SUB_MENUS];
        U8 *MID_Icon[MAX_SUB_MENUS];
        U8 *guiBuffer;

        for (i = 0; i < count; i++)
        {
            MID_Names[i] = g_java.mid_info[i].mid_name;
            if(g_java.mid_info[i].mid_icon)
            {
                MID_Icon[i] = g_java.mid_info[i].mid_icon;
            }
            else
            {
                MID_Icon[i] = (PU8) GetImage(IMG_JAVA_STAR1);      /* g_java.mid_info[i].mid_icon; */
            }
        }

        guiBuffer = GetCurrGuiBuffer(SCR_JAVA_APP_OPTION_SELECT);
        EntryNewScreen(SCR_JAVA_APP_OPTION_SELECT, NULL, mmi_java_entry_opt_select, NULL);
        RegisterHighlightHandler(mmi_java_highlight_option_select);

        ShowCategory170Screen(
            (PU8) GetString(STR_JAVA_APP_OPTION_SELECT),
            (PU8) GetImage(mmi_java_get_title_icon()),
            (PU8) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            count,
            (U8 **) MID_Names,
            MID_Icon,
            0,
            0,
            guiBuffer);

        if (g_java.is_select_after_install)
        {
            SetLeftSoftkeyFunction(mmi_java_entry_mid_launch_after_install, KEY_EVENT_UP);
            DeleteScreenIfPresent(SCR_JAVA_LAUNCH_AFTER_INSTALL);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_java_entry_mid_launch, KEY_EVENT_UP);
        }
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

#ifdef OGDR_SECURITY_SETTING

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_set_default_setting_cnf
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_set_default_domain_cnf(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_set_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_set_default_domain_cnf_struct*) MsgStruct;

    if ( g_java.msg_ctrl & SEND_SET_DEFAULT_DOMAIN_CTRL )
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        /* only get the setting from Java again to update the latest setting value since exclusive setting may automatically
            update other setting value*/
        get_setting_only = KAL_TRUE;
        mmi_java_send_get_default_domain_req(g_java.domain);
        g_java.msg_ctrl &= (~SEND_SET_DEFAULT_DOMAIN_CTRL);
    }
    DeleteScreenIfPresent(SCR_JAVA_APP_OPTION_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_set_default_domain_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_set_default_domain_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_java_set_default_domain_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_java.msg_ctrl & SEND_SET_DEFAULT_DOMAIN_CTRL)
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_SET_DEFAULT_DOMAIN_CTRL;

        msg = (mmi_java_set_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_set_default_domain_req_struct));

        msg->type = GAMETYPE_JAVA_GAME;
        msg->domain_id = g_java.domain;
        kal_mem_cpy(&(msg->default_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));

        SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_set_default_domain_cnf,MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_CNF);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_J2ME;
        Message.oslMsgId = MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_REQ;
        Message.oslDataPtr = (local_para_struct*) msg;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_default_domain_cnf
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_default_domain_cnf(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_get_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_get_default_domain_cnf_struct *) MsgStruct;


    if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
    {
        kal_mem_cpy(&(g_java.mids_setting), &(msg->default_setting), sizeof(mmi_setting_struct));
        kal_mem_cpy(&(g_java.mids_max_setting), &(msg->max_setting), sizeof(mmi_setting_struct));
    }

    if(!get_setting_only)
    {
        get_domain_setting = KAL_TRUE;
        mmi_java_entry_opt_setting();
    }

    get_setting_only = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_get_default_domain_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_get_default_domain_req(S32 domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_java_get_default_domain_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_get_default_domain_req_struct));

    msg->type = GAMETYPE_JAVA_GAME;
    msg->domain_id = domain;

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_default_domain_cnf,MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_CNF);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_default_setting
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_default_domain_setting(S32 domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);

    g_java.domain = domain;

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_default_domain_cnf, MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_CNF);
    mmi_java_send_get_default_domain_req(domain);

}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_store_setting
 * DESCRIPTION
 *  store java setting back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_JAVA_SETTING_SOUND, &g_mmi_java_aud_volume_level, DS_BYTE, &error);
    WriteValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_vib_on, DS_BYTE, &error);
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    WriteValue(NVRAM_JAVA_SETTING_NET_ICON, &g_mmi_java_is_net_icon_on, DS_BYTE, &error);
#endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    WriteValue(NVRAM_JAVA_SETTING_VK, &g_mmi_java_vk_permission, DS_BYTE, &error);
#endif
    WriteValue(NVRAM_JAVA_SETTING_PROF_ID, &g_mmi_java_wap_prof_id, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_load_setting
 * DESCRIPTION
 *  load java setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_JAVA_SETTING_SOUND, &g_mmi_java_aud_volume_level, DS_BYTE, &error);

    /* if not init, init as 4 */
    if (g_mmi_java_aud_volume_level == 0xff)
    {
        g_mmi_java_aud_volume_level = 4;
        WriteValue(NVRAM_JAVA_SETTING_SOUND, &g_mmi_java_aud_volume_level, DS_BYTE, &error);
    }

    ReadValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_vib_on, DS_BYTE, &error);

    /* if not init, init as ON */
    if (g_mmi_java_is_vib_on == 0xff)
    {
        g_mmi_java_is_vib_on = TRUE;
        WriteValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_vib_on, DS_BYTE, &error);
    }

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    ReadValue(NVRAM_JAVA_SETTING_NET_ICON, &g_mmi_java_is_net_icon_on, DS_BYTE, &error);

    /* if not init, init as ON */
    if (g_mmi_java_is_net_icon_on > 2 || g_mmi_java_is_net_icon_on < 0)
    {
        g_mmi_java_is_net_icon_on = TRUE;
        WriteValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_net_icon_on, DS_BYTE, &error);
    }
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    ReadValue(NVRAM_JAVA_SETTING_VK, &g_mmi_java_vk_permission, DS_BYTE, &error);

    /* if not init, init as first wap profile */
    if (g_mmi_java_vk_permission == 0xff)
    {
        g_mmi_java_vk_permission = 0;
        WriteValue(NVRAM_JAVA_SETTING_VK, &g_mmi_java_vk_permission, DS_BYTE, &error);
    }
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */

    ReadValue(NVRAM_JAVA_SETTING_PROF_ID, &g_mmi_java_wap_prof_id, DS_BYTE, &error);

}

#ifdef __SUPPORT_INFUSIO__


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_eureka_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_eureka_by_wap_ask_terminate_cb(BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_EUREKA_BY_WAP;
        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_eureka_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_eureka_by_menu_ask_terminate_cb(BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_EUREKA_BY_MENU;
        jvm_pause_state_exit();
        mmi_java_entry_terminating(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_eureka
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_eureka(void)
{
    g_java.mids_info_start = g_java.mids_info_end = 0;
	g_java.mids_index = g_java.mid_index = 0;
    g_java.total_java_app_mids = g_java.total_java_app_mid = 1;
	g_java.mids_info[0].mids_id = 1;
	g_java.mids_info[0].mid_count = 1;
	g_java.mid_info[0].mid_id = 1;

	mmi_java_send_mid_start_req(GAMETYPE_INFUSIO_EUREKA);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_eureka_by_wap
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_eureka_by_wap(void)
{
#ifdef J2ME_SUPPORT_PAUSE
    if (jvm_is_pause_mode())
    {
        if( jvm_get_initiate_game_type() == GAMETYPE_INFUSIO_EUREKA )
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_entry_eureka_by_wap_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_EUREKA));
        }
        else if( jvm_get_initiate_game_type() == GAMETYPE_JAVA_GAME)
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_entry_eureka_by_wap_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME));
        }
        else
        {
            mmi_java_display_is_busy();
        }
        return;
    }
#endif /* J2ME_SUPPORT_PAUSE */

    g_java.is_launch_after_install = FALSE;
    g_java.is_select_after_install = FALSE;
    g_java.is_launch_eureka_by_wap = TRUE;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_eureka_by_menu
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_eureka_by_menu(void)
{
    jam_mid_start_set_command(NULL);
#ifdef J2ME_SUPPORT_PAUSE
    if (jvm_is_pause_mode())
    {
        if( jvm_get_initiate_game_type() == GAMETYPE_INFUSIO_EUREKA )
        {
            mmi_java_entry_resume_dialog();
        }
        else if( jvm_get_initiate_game_type() == GAMETYPE_JAVA_GAME)
        {
            mmi_java_entry_cb_terminate_dialog(mmi_java_entry_eureka_by_menu_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME));
        }
        else
        {
            mmi_java_display_is_busy();
        }
        return;
    }
#endif /* J2ME_SUPPORT_PAUSE */
    mmi_java_entry_eureka();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_menu
 * DESCRIPTION
 *  Highlight handler routine for Java menu item in FunAndGames menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_eureka(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_entry_eureka_by_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_entry_eureka_by_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

	SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
	SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_infusio_eureka_client_start_req
 * DESCRIPTION
 *  WAP ege locator to trigger eureka client launch
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_start_infusio_eureka_client(kal_char* command)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eureka_start_req_struct* ege_start;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ege_start = (eureka_start_req_struct*)OslConstructDataPtr(sizeof(eureka_start_req_struct));
	ASSERT(ege_start);
	ege_start->session_id = 0;

    if (command)
    {
	ege_start->ege_command = get_ctrl_buffer(strlen(command)+1);
	ASSERT(ege_start->ege_command);
	strcpy(ege_start->ege_command, command);
    } else {
	ege_start->ege_command = NULL;
    }

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_WAP_MMI_EUREKA_START_REQ;
    Message.oslDataPtr = (local_para_struct*) ege_start;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_infudio_eureka_start_req
 * DESCRIPTION
 *
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_recv_infudio_eureka_start_req(void *msg_struct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	eureka_start_req_struct* ege_req = (eureka_start_req_struct*)msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (ege_req)
	{
		jam_mid_start_set_command(ege_req->ege_command);
		if (ege_req->ege_command) {
			free_ctrl_buffer(ege_req->ege_command);
			ege_req->ege_command = NULL;
		}
	}
    mmi_java_entry_eureka_by_wap();
}
#endif /* __SUPPORT_INFUSIO__ */


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

#if defined(J2ME_SUPPORT_PAUSE)
void mmi_java_recv_pause_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( !jvm_is_pause_mode())
    {
        if (jvm_canbe_paused() != KAL_TRUE)
        {
            mmi_java_entry_force_terminate_dialog();
        }
        else
        {
            mmi_java_entry_terminate_dialog();
        }
    }
}
#endif /* J2ME_SUPPORT_PAUSE */


/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_launch_from_idle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  0:  not launch after installation
 *  1:  launch after installation
 *****************************************************************************/
BOOL mmi_java_is_launch_from_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_java.is_launch_after_install || g_java.is_launch_eureka_by_wap;
}

#else /* __J2ME__ */
#ifdef __MTK_TARGET__
#include "MMI_features.h"
#include "StdC.h"


/*****************************************************************************
 * FUNCTION
 *  jvm_is_busy
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool jvm_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}
#endif /* __MTK_TARGET__ */
#endif /* __J2ME__ */


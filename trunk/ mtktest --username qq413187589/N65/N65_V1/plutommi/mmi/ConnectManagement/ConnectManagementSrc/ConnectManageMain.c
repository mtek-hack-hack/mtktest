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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ConnectManageMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */



#include "MMI_features.h"

#include "ProtocolEvents.h"
#include "DebugInitDef.h"

#include "abm_soc_enums.h"
#include "abm_util.h"
#include "abm_def.h"

#ifdef __MMI_WLAN_FEATURES__
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "supc_abm_msgs.h"
#include "supc_mmi_msgs.h"
#include "mmi2abm_struct.h"

#endif /* __MMI_WLAN_FEATURES__ */

#include "GlobalMenuItems.h"
#include "CommonScreens.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_inputs.h"
#include "TimerEvents.h"
#include "DataAccountGprot.h"
#include "SettingProfile.h"
#include "l4c_common_enum.h"
#include "DataAccountGprot.h"

#include "ConnectManageStruct.h"
#include "ConnectManageResDef.h"
#include "ConnectManageGProt.h"

#include "mmi_msg_struct.h"
#include "l4c_common_enum.h"


#ifdef __CBM_ALWAYS_ASK_FEATURE__
#include "mmi2soc_struct.h"
#include "soc2mmi_struct.h"
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

#ifdef __CBM_CM_FEATURE__
static void mmi_cbm_init_highlight_handler(void);
static void mmi_cbm_highlight_entry_bearer_list(void);
static void mmi_cbm_highlight_entry_bearer_detail_info(void);
static void mmi_cbm_highlight_disconnect_confirm(void);
static void mmi_cbm_highlight_disconnect_all_confirm(void);
static void mmi_cbm_entry_bearer_list(void);
static void mmi_cbm_entry_bearer_list_option(void);
static void mmi_cbm_pre_entry_bearer_detail_info(void);
static void mmi_cbm_entry_bearer_detail_info(void);
static void mmi_cbm_disconnect_confirm(void);
static void mmi_cbm_disconnect_all_confirm(void);
static void mmi_cbm_disconnect_process(void);
static void mmi_cbm_bearer_active_ind_handler(void *info);
static void mmi_cbm_bearer_deactive_ind_handler(void *info);
static void mmi_cbm_bearer_disconnect_req_handler(U32 profile_id, U8 connect_type, U8 dilaup_type);
static void mmi_cbm_bearer_disconnect_cnf_handler(void *info);
static void mmi_cbm_bearer_get_bearer_info_req_handler();
static void mmi_cbm_bearer_get_bearer_info_cnf_handler(void *info);
static void mmi_cbm_init_data_list(void);
static U8 mmi_cbm_add_data_list_node(CBM_Display_context_struct *info, U8 backup_flag);
static U8 mmi_cbm_delete_data_list_node(U32 profile_id, U8 connect_type);
static void mmi_cbm_clear_data_list_node(void);
static S8 mmi_cbm_find_data_list_node_index(U32 profile_id, U8 connect_type);
static void mmi_cbm_start_timer(void);
static void mmi_cbm_check_is_stop_timer(void);
static U8 mmi_cbm_data_list_is_empty(void);
static void mmi_cbm_timeout_handler(void);
static U8 mmi_cbm_get_data_list_num(void);
static U8 mmi_cbm_get_data_list_profile_name(void);
static U8 mmi_cbm_get_data_list_data_size(void);
static void mmi_cbm_get_detail_info(void);
static void mmi_cbm_list_highlight_index(S32 Index);
static void mmi_cbm_convert_connect_time(U32 time);
static void mmi_cbm_pre_select_data_node(void);
static void mmi_cbm_bearer_disconnect_all_pre_handler(void);
static void mmi_cbm_bearer_disconnect_pre_handler(void);
static CBM_Display_context_struct * mmi_cbm_get_data_list_head_node(void);
static void mmi_cbm_copy_data_list_from_backup(void);
static void mmi_cbm_redraw_conn_list_screen(void);
static void mmi_cbm_redraw_conn_detail_screen(void);
static void mmi_cbm_app_entry_detail_screen_handler(void *info);
static U8 mmi_cbm_app_pre_select_data_node(U32 profile_id);
static void mmi_cbm_check_data_account_ready(void);
static void mmi_cbm_get_dtcnt_init_ready_check(FuncPtr ready_callback);
static void mmi_cbm_back_bearer_detail_screen_handler(void);
static void mmi_cbm_get_redraw_data_node(void);
static void mmi_cbm_update_conn_list_screen(void);

/**/
mmi_abm_cbm_active_ind_struct *g_cbm_active_handle_p;
mmi_abm_cbm_active_ind_struct g_cbm_active_handle_temp;

CBM_Display_context_struct g_cbm_bearer_list[CBM_MAX_BEARER_NUM];
CBM_Display_context_struct g_cbm_bearer_list_backup[CBM_MAX_BEARER_NUM/2];
CBM_bearer_list_index_struct g_cbm_bearer_list_index[CBM_MAX_BEARER_NUM];

CBM_Display_context_struct g_cbm_active_data_node;
CBM_Display_context_struct g_cbm_deactive_data_node;
CBM_Display_context_struct g_cbm_display_data_node;
CBM_connect_time_struct    g_cbm_connect_time;

U8 g_cbm_list_select_index;
U8 g_cbm_disc_flag;
U8 g_cbm_disc_all_flag;
U8 g_cbm_backup_list_flag;
U8 g_cbm_dtcnt_init_check_status;
U8 g_cbm_timer_start_flag;

U8 *g_list_data_size[CBM_MAX_BEARER_NUM];
U8 *g_list_profile_name[CBM_MAX_BEARER_NUM];

/**/
extern pBOOL IsBackHistory;
extern void (*g_DTCNTReadyCallback) (void);
extern void DataAccountReadyCheck(FuncPtr ready_callback);

extern void wgui_cat_block_list_effect(void);
extern void wgui_cat354_refresh(void);
#endif /* __CBM_CM_FEATURE__*/

/* for always ask */
#ifdef __CBM_ALWAYS_ASK_FEATURE__
mmi_cbm_app_register_info_struct g_app_register_info;
mmi_cbm_soc_ask_acct_struct g_soc_ask_acct;
static void mmi_cbm_soc_ask_acct_ind_hdlr(void *info);
static void mmi_cbm_always_ask_select_acct_callback(U32 acct_id, BOOL result);
static BOOL mmi_cbm_soc_ask_acct_queue_add(U8 app_id, module_type mod_id, U8 sim_info);
static BOOL mmi_cbm_soc_ask_acct_queue_is_empty(void);
static BOOL mmi_cbm_soc_ask_acct_queue_is_full(void);
static BOOL mmi_cbm_soc_ask_acct_queue_get(U8 *app_id, module_type *mod_id, U8 *sim_info);
static void mmi_cbm_soc_ask_acct_cnf_hdlr(BOOL result, U8 app_id, module_type mod_id, soc_bearer_status_enum option, U32 acct_id);
static void mmi_cbm_always_ask_select_result_ind(BOOL result, U32 acct_id, module_type mod_id);
static void mmi_cbm_always_ask_select_result_cnf(void *info);

extern void mmi_always_ask_delete_screen(void);
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

U8 g_cbm_dtcnt_init_status;
U8 g_cbm_soc_sim_info;
U8 g_cbm_soc_mod_id;

/* for bearer status api */
cbm_bearer_status_struct g_cbm_bearer_status[CBM_BEARER_STATUS_MAX_NUM];

static void mmi_cbm_add_bearer_status_req_hdlr(void *info);
static U8 mmi_cbm_add_bearer_status_req(U32 mod_id, U32 acct_id);
static void mmi_cbm_add_bearer_status_cnf(U8 index);
static void mmi_cbm_del_bearer_status_req_hdlr(void *info);
static BOOL mmi_cbm_del_bearer_status_req(U8 index, U8 app_id);
static void mmi_cbm_del_bearer_status_cnf(BOOL result, U32 mod_id, U32 acct_id);
static void mmi_cbm_send_bearer_status_ind(U32 acct_id, mmi_cbm_bearer_state_enum status);
static void mmi_cbm_send_bearer_status_ind_hdlr(U32 mod_id, mmi_cbm_bearer_state_enum status, U32 acct_id);

extern BOOL always_ask_create_sem(void);
extern BOOL mmi_cbm_get_app_register_info(U8 app_id, module_type mod_id, mmi_cbm_app_register_info_struct *app_register_info);
/*****************************************************************************
 * FUNCTION
 *  InitAlwaysAsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitAlwaysAsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    always_ask_create_sem();
    
    SetProtocolEventHandler(mmi_cbm_add_bearer_status_req_hdlr, MSG_ID_MMI_CBM_ADD_BEARER_STATUS_NOTIFY_REQ);
    SetProtocolEventHandler(mmi_cbm_del_bearer_status_req_hdlr, MSG_ID_MMI_CBM_DEL_BEARER_STATUS_NOTIFY_REQ);
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    SetProtocolEventHandler(mmi_cbm_soc_ask_acct_ind_hdlr, MSG_ID_MMI_SOC_ASK_ACCT_IND);
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

}

/*****************************************************************************
 * FUNCTION
 *  InitConnManageApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitConnManageApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CBM_CM_FEATURE__
    mmi_cbm_init_data_list();
    mmi_cbm_init_highlight_handler();
#endif /* __CBM_CM_FEATURE__ */
}

#ifdef __CBM_CM_FEATURE__
/*****************************************************************************
 * FUNCTION
 *  InitConnManageApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetHiliteHandler(MENU_ID_CBM_APP, mmi_cbm_highlight_entry_bearer_list);
    SetHiliteHandler(MENU_ID_CBM_DETAIL, mmi_cbm_highlight_entry_bearer_detail_info);
    SetHiliteHandler(MENU_ID_CBM_DISC, mmi_cbm_highlight_disconnect_confirm);
    SetHiliteHandler(MENU_ID_CBM_DISC_ALL, mmi_cbm_highlight_disconnect_all_confirm);
#ifdef __CBM_CM_FEATURE__
    SetProtocolEventHandler(mmi_cbm_bearer_active_ind_handler, MSG_ID_MMI_ABM_CBM_ACTIVE_IND);
    SetProtocolEventHandler(mmi_cbm_bearer_deactive_ind_handler, MSG_ID_MMI_ABM_CBM_DEACTIVE_IND);
    SetProtocolEventHandler(mmi_cbm_app_entry_detail_screen_handler, MSG_ID_MMI_CBM_APP_ENTRY_BEARER_DETAIL_INFO_IND);
#endif /* __CBM_CM_FEATURE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_highlight_entry_bearer_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_highlight_entry_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_cbm_entry_bearer_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_cbm_entry_bearer_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_highlight_entry_bearer_detail_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_highlight_entry_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_cbm_pre_entry_bearer_detail_info, KEY_EVENT_UP);
    SetKeyHandler(mmi_cbm_pre_entry_bearer_detail_info, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_highlight_disconnect_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_highlight_disconnect_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_cbm_disconnect_confirm, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_highlight_disconnect_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_highlight_disconnect_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_cbm_disconnect_all_confirm, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_entry_detail_screen_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cbm_app_entry_detail_screen(mmi_cbm_entry_type_enum entry_type, kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    U32 account_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    account_id = always_ask_get_original_id_data_account(acct_id);

    PRINT_INFORMATION(("$$$$$ mmi_cbm_app_entry_detail_screen  account_id = %d $$$$$", account_id));

    if(entry_type == MMI_CBM_ENTRY_DETAIL_SCREEN)
    {
        result = mmi_cbm_app_pre_select_data_node(account_id);

        if(result)
        {
            mmi_cbm_start_timer();
            mmi_cbm_entry_bearer_detail_info();
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 1, 1000, ERROR_TONE);
            return;
        }
    }
    else if(entry_type == MMI_CBM_ENTRY_LIST_SCREEN)
    {
        mmi_cbm_entry_bearer_list();
    }
    else
    {
        ASSERT(0);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_app_entry_detail_screen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_app_entry_detail_screen_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbm_app_entry_bearer_detail_info_ind_struct *detail_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    detail_ind = (mmi_cbm_app_entry_bearer_detail_info_ind_struct *)info;

    PRINT_INFORMATION(("$$$$$ CBM APP Entry Bearer Detail  entry_type = %d, acct_id = %d $$$$$", 
       detail_ind->entry_type, detail_ind->acct_id));

    mmi_cbm_app_entry_detail_screen(detail_ind->entry_type, detail_ind->acct_id);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_entry_bearer_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_cbm_entry_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    EntryNewScreen(SCR_ID_CBM_LIST, NULL, mmi_cbm_entry_bearer_list, NULL);
    DeleteScreenIfPresent(SCR_ID_CBM_LIST);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CBM_LIST);
 
    /* 3 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(mmi_cbm_list_highlight_index);

    nNumofItem = mmi_cbm_get_data_list_num();

    PRINT_INFORMATION(("$$$$$ CBM Entry Bearer List  nNumList = %d $$$$$", nNumofItem));

    if(nNumofItem == 0)
    {
        ShowCategory74Screen(
            STR_ID_CBM_MAIN,
            GetRootTitleIcon(MENU_ID_CBM_APP),
            0,//STR_GLOBAL_OPTIONS,
            0,//IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8 *)GetString(STR_ID_CBM_NO_CONNECTION),
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            guiBuffer);
        
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        //test
        //SetLeftSoftkeyFunction(mmi_cbm_entry_bearer_list_option, KEY_EVENT_UP);
        //mmi_cbm_start_timer();
    }
    else
    {
        mmi_cbm_get_data_list_profile_name();
        mmi_cbm_get_data_list_data_size();
        wgui_cat_block_list_effect();
        ShowCategory354Screen(
            (U8*) GetString(STR_ID_CBM_MAIN),
            0,//GetRootTitleIcon(MENU_ID_CBM_APP),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            g_list_profile_name,
            g_list_data_size,
            (PU16) gIndexIconsImageList,
            0,
            guiBuffer);
        
        SetLeftSoftkeyFunction(mmi_cbm_entry_bearer_list_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_cbm_entry_bearer_list_option, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_list_highlight_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_list_highlight_index(S32 Index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_cbm_list_select_index = Index;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_entry_bearer_list_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_entry_bearer_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    count = mmi_cbm_get_data_list_num();

    EntryNewScreen(SCR_ID_CBM_OPTION, NULL, mmi_cbm_entry_bearer_list_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CBM_OPTION);

    PRINT_INFORMATION(("$$$$$ CBM Entry Bearer Option count = %d $$$$$", count));
    
    if(count <= 1)
    {
        nNumofItem = GetNumOfChild(MENU_ID_CBM_OPTION);

        GetSequenceStringIds(MENU_ID_CBM_OPTION, nStrItemList);

        SetParentHandler(MENU_ID_CBM_OPTION);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_CBM_OPTION_ALL);

        GetSequenceStringIds(MENU_ID_CBM_OPTION_ALL, nStrItemList);

        SetParentHandler(MENU_ID_CBM_OPTION_ALL);
    }
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        0,//GetRootTitleIcon(MENU_ID_CBM_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_pre_entry_bearer_detail_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_pre_select_data_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION(("$$$$$ CBM pre select data node index = %d $$$$$", g_cbm_list_select_index));

    if(g_cbm_bearer_list[g_cbm_bearer_list_index[g_cbm_list_select_index].list_index].valid)
    {
        memcpy(&g_cbm_display_data_node, 
               &g_cbm_bearer_list[g_cbm_bearer_list_index[g_cbm_list_select_index].list_index],
               sizeof(CBM_Display_context_struct));
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, WARNING_TONE);
        return;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_app_pre_select_data_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_app_pre_select_data_node(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        PRINT_INFORMATION(("$$$$$ mmi_cbm_app_pre_select_data_node  valid = %d, acct_id = %d $$$$$", 
         g_cbm_bearer_list[i].valid, g_cbm_bearer_list[i].profile_id));

        if(g_cbm_bearer_list[i].valid && g_cbm_bearer_list[i].profile_id == profile_id)
        {
            memcpy(&g_cbm_display_data_node, 
                &g_cbm_bearer_list[i],
               sizeof(CBM_Display_context_struct));

            return TRUE;
        }
    }

    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_pre_entry_bearer_detail_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_pre_entry_bearer_detail_info(void)
{
    mmi_cbm_pre_select_data_node();
    mmi_cbm_entry_bearer_detail_info();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_entry_bearer_detail_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_entry_bearer_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION(("$$$$$ CBM Entry Bearer Detail info! $$$$$"));
    
    EntryNewScreen(SCR_ID_CBM_DETAIL, NULL, mmi_cbm_entry_bearer_detail_info, NULL);
    DeleteScreenIfPresent(SCR_ID_CBM_DETAIL);

    if (IsBackHistory)
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_CBM_DETAIL);
    }
    else
    {
        guiBuffer = NULL; 
    }

    mmi_cbm_get_detail_info();

    ShowCategory74Screen(
        STR_ID_CBM_DETAIL,
        0,//GetRootTitleIcon(MENU_ID_CBM_APP),
        NULL,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(mmi_cbm_back_bearer_detail_screen_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_cbm_back_bearer_detail_screen_handler, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_back_bearer_detail_screen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_back_bearer_detail_screen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    count = mmi_cbm_get_data_list_num();

    if(count == 0)
    {
        if(IsScreenPresent(SCR_ID_CBM_OPTION))
        {
            DeleteScreenIfPresent(SCR_ID_CBM_OPTION);
            GoBackHistory();
        }
        else
        {
            GoBackHistory();
        }
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_detail_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_get_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    U8 *info;
    U8  bearer_type;
    float data_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    info = (PU8) subMenuData;
    
    bearer_type = mmi_dtcnt_get_bearer_type((U8)g_cbm_display_data_node.profile_id);
    
    PRINT_INFORMATION(("$$$$$ CBM Detail Info profile_id = %d, bearer_type = %d, conn_status = %d $$$$$", 
        g_cbm_display_data_node.profile_id, bearer_type, g_cbm_display_data_node.active_status));
    
    if(bearer_type == 0)
    {
        ASSERT(0);
    }
    
    if(g_cbm_display_data_node.connect_type == CBM_CONNECT_TYPE_LOCAL)
    {
        if(bearer_type == DATA_ACCOUNT_BEARER_CSD)
        {
            UCS2Strcpy((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_NUMBER));         
            UCS2Strcat((PS8) info, (PS8) L"\n");
            UCS2Strcat((PS8) info, g_cbm_display_data_node.profile_name);
            UCS2Strcat((PS8) info, (PS8) L"\n");    

            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE));       
            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE_CSD));       
            UCS2Strcat((PS8) info, (PS8) L"\n");            
        }
        else if(bearer_type == DATA_ACCOUNT_BEARER_GPRS)
        {
            UCS2Strcpy((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_APN));   
            UCS2Strcat((PS8) info, (PS8) L"\n");
            UCS2Strcat((PS8) info, g_cbm_display_data_node.profile_name);
            UCS2Strcat((PS8) info, (PS8) L"\n");

            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE));       
            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE_GPRS));       
            UCS2Strcat((PS8) info, (PS8) L"\n");            
        }
        else
        {
            /*UCS2Strcpy((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_AP_NAME));     
            UCS2Strcat((PS8) info, (PS8) L"\n");
            UCS2Strcat((PS8) info, g_cbm_display_data_node.profile_name);
            UCS2Strcat((PS8) info, (PS8) L"\n");*/

            UCS2Strcpy((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE));  
            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE_WIFI));       
            UCS2Strcat((PS8) info, (PS8) L"\n");            
        }
    }
    else
    {
        /*UCS2Strcpy((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_AP_NAME));  
        UCS2Strcat((PS8) info, (PS8) L"\n");
        AnsiiToUnicodeString(tempBufUnicode, g_cbm_display_data_node.profile_name);
        UCS2Strcat((PS8) info, tempBufUnicode);
        UCS2Strcat((PS8) info, (PS8) L"\n");*/
        
        UCS2Strcpy((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE));     
        UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TYPE_DAILUP));       
        UCS2Strcat((PS8) info, (PS8) L"\n");            
    }
    
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_STATUS)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");
    
    if(g_cbm_display_data_node.active_status == CBM_CONNECT_STATUS_ACTIVE)
    {
        if((g_cbm_display_data_node.cbm_bearer_detail_info.up_speed == 0) &&
            (g_cbm_display_data_node.cbm_bearer_detail_info.down_speed == 0))
        {
            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_UNTRANSFER));     
        }
        else
        {
            UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_TRANSFERING));             
        }
    }
    else
    {
        UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_DISC));     
    }
    UCS2Strcat((PS8) info, (PS8) L"\n");

    mmi_cbm_convert_connect_time(g_cbm_display_data_node.cbm_bearer_detail_info.connect_time);
    
    PRINT_INFORMATION(("$$$$$ CBM Detail Info connect time = %d, hour = %d, minute = %d, second = %d $$$$$", 
        g_cbm_display_data_node.cbm_bearer_detail_info.connect_time, g_cbm_connect_time.hour,
        g_cbm_connect_time.minute, g_cbm_connect_time.second));
   
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_CONN_TIME)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");
    sprintf(tempBuf, "%02d:%02d:%02d", g_cbm_connect_time.hour,
        g_cbm_connect_time.minute,
        g_cbm_connect_time.second);
    
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
    UCS2Strcat((PS8) info, (PS8) L"\n");  

    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_SHARE)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");
    sprintf(tempBuf, "%d", g_cbm_display_data_node.cbm_bearer_detail_info.share_num);
    
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
    UCS2Strcat((PS8) info, (PS8) L"\n");

    
    PRINT_INFORMATION(("$$$$$ CBM Detail Info tx data size = %d, rx data size = %d, up speed = %d, donw speed = %d $$$$$", 
        g_cbm_display_data_node.cbm_bearer_detail_info.send_data_size, g_cbm_display_data_node.cbm_bearer_detail_info.receive_data_size,
        g_cbm_display_data_node.cbm_bearer_detail_info.up_speed, g_cbm_display_data_node.cbm_bearer_detail_info.down_speed));
           
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_ALL_DATA_SIZE));    
    UCS2Strcat((PS8) info, (PS8) L"\n");

    data_size = (float)g_cbm_display_data_node.cbm_bearer_detail_info.all_data_size;
    data_size = data_size / CBM_DATA_UINT_SIZE;

    sprintf(tempBuf, "%.2f", data_size);
    strcat(tempBuf, CBM_DATA_SIZE_UINT);
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
    UCS2Strcat((PS8) info, (PS8) L"\n");
    
    
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_RECEIVE_DATA_SIZE)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");

    data_size = (float)g_cbm_display_data_node.cbm_bearer_detail_info.receive_data_size;
    data_size = data_size / CBM_DATA_UINT_SIZE;
    sprintf(tempBuf, "%.2f", data_size);
    strcat(tempBuf, CBM_DATA_SIZE_UINT);
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
    UCS2Strcat((PS8) info, (PS8) L"\n");
    
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_SEND_DATA_SIZE)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");
    
    data_size = (float)g_cbm_display_data_node.cbm_bearer_detail_info.send_data_size;
    data_size = data_size / CBM_DATA_UINT_SIZE;
    sprintf(tempBuf, "%.2f", data_size);
    strcat(tempBuf, CBM_DATA_SIZE_UINT);
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
    UCS2Strcat((PS8) info, (PS8) L"\n");
    
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_UP_DATA_RATE)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");
    sprintf(tempBuf, "%.2f", g_cbm_display_data_node.cbm_bearer_detail_info.up_speed);
    strcat(tempBuf, CBM_DATA_RATE_UINT);
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
    UCS2Strcat((PS8) info, (PS8) L"\n");
    
    UCS2Strcat((PS8) info, (PS8) GetString(STR_ID_CBM_DETAIL_DOWN_DATA_RATE)); 
    UCS2Strcat((PS8) info, (PS8) L"\n");
    sprintf(tempBuf, "%.2f", g_cbm_display_data_node.cbm_bearer_detail_info.down_speed);
    strcat(tempBuf, CBM_DATA_RATE_UINT);
    AnsiiToUnicodeString(tempBufUnicode, tempBuf);
    UCS2Strcat((PS8)info, tempBufUnicode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_convert_connect_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_convert_connect_time(U32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hour, minute, second;
    U32 temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    hour = time/CBM_CONNECT_TIME_HOUR;
    temp = time%CBM_CONNECT_TIME_HOUR;
    minute = temp/CBM_CONNECT_TIME_MINU;
    temp = time%CBM_CONNECT_TIME_MINU;
    second = temp%CBM_CONNECT_TIME_MINU;  

    g_cbm_connect_time.hour = hour;
    g_cbm_connect_time.minute = minute;
    g_cbm_connect_time.second = second;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_disconnect_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_disconnect_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CBM_DUMP, NULL, mmi_cbm_disconnect_confirm, NULL);
    
    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_CBM_DISC_CONFIRM,
        IMG_GLOBAL_QUESTION,
        NULL);
    
    SetLeftSoftkeyFunction(mmi_cbm_bearer_disconnect_pre_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_disconnect_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_disconnect_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CBM_DUMP, NULL, mmi_cbm_disconnect_all_confirm, NULL);
    
    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_CBM_DISC_ALL_CONFIRM,
        IMG_GLOBAL_QUESTION,
        NULL);
    
    SetLeftSoftkeyFunction(mmi_cbm_bearer_disconnect_all_pre_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_disconnect_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_disconnect_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_CBM_DISC_PRODUCESS, NULL, mmi_cbm_disconnect_process, NULL);
    DeleteScreenIfPresent(SCR_ID_CBM_DISC_PRODUCESS);
    DeleteScreenIfPresent(SCR_ID_CBM_DUMP);
    
    ShowCategory66Screen(
        STR_ID_CBM_DISC,
        0,//GetRootTitleIcon(MENU_ID_CBM_APP),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_ID_CBM_DISC),
        NULL,
        NULL);
    
    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_dtcnt_init_ready_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_get_dtcnt_init_ready_check(FuncPtr ready_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    if(!g_cbm_dtcnt_init_check_status)
    {
        g_cbm_dtcnt_init_status = TRUE;
        g_cbm_dtcnt_init_check_status = TRUE;
        g_DTCNTReadyCallback = ready_callback;
        DTCNTGetAccountReq(0);
    }
    else
    {
        ready_callback();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_active_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_active_ind_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_cbm_active_handle_p = (mmi_abm_cbm_active_ind_struct *)info;
    memcpy(&g_cbm_active_handle_temp, g_cbm_active_handle_p, sizeof(mmi_abm_cbm_active_ind_struct));

    PRINT_INFORMATION(("$$$$$ CBM Active Indicate profile_id = %d, connect_type = %d $$$$$", 
                      g_cbm_active_handle_temp.profile_id, g_cbm_active_handle_temp.connect_type));

    if(g_cbm_active_handle_temp.connect_type == CBM_CONNECT_TYPE_LOCAL)
    {
        mmi_cbm_send_bearer_status_ind(g_cbm_active_handle_temp.profile_id, CBM_BEARER_STATE_ACTIVATED);
    }
    
    mmi_cbm_get_dtcnt_init_ready_check(mmi_cbm_check_data_account_ready);

   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_check_data_account_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_check_data_account_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 profile_name[CBM_MAX_PROFILE_NAME_LEN + 1];
    U8 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION(("$$$$$ CBM dtcnt ready profile_id = %d, connect_type = %d $$$$$", 
                      g_cbm_active_handle_temp.profile_id, g_cbm_active_handle_temp.connect_type));

    g_cbm_active_data_node.profile_id = g_cbm_active_handle_temp.profile_id;
    mmi_dtcnt_get_account_name((U8)g_cbm_active_data_node.profile_id, g_cbm_active_data_node.profile_name, sizeof(g_cbm_active_data_node.profile_name));
    UnicodeToAnsii((PS8)profile_name, (PS8)g_cbm_active_data_node.profile_name);
    len = strlen((PS8)profile_name);
    if(strlen == 0)
    {
        ASSERT(0);
        return;
    }
    PRINT_INFORMATION(("$$$$$ CBM dtcnt ready profile_name = %s, strlen = %d $$$$$", profile_name, len));

    g_cbm_active_data_node.connect_type = g_cbm_active_handle_temp.connect_type;
    g_cbm_active_data_node.active_dtcnt_id = g_cbm_active_handle_temp.profile_id;
    g_cbm_active_data_node.active_status = CBM_CONNECT_STATUS_ACTIVE;
    g_cbm_active_data_node.valid = TRUE;
    memset(&g_cbm_active_data_node.cbm_bearer_detail_info, 0, sizeof(CBM_bearer_detail_context_struct));

    if(g_cbm_active_data_node.connect_type == CBM_CONNECT_TYPE_DAILUP)
    {
        g_cbm_active_data_node.dialup_type = g_cbm_active_handle_temp.dailup_info.connect_type;
        if(g_cbm_active_data_node.dialup_type == CSD_BEARER_DIALUP)
        {
            g_cbm_active_data_node.profile_id = g_cbm_active_handle_temp.dailup_info.call_id;
        }
        else
        {
            g_cbm_active_data_node.profile_id = g_cbm_active_handle_temp.dailup_info.context_id;
        }
    }
    if(g_cbm_disc_all_flag)
    {
        PRINT_INFORMATION(("$$$$$ CBM add node to backup list $$$$$"));
        g_cbm_backup_list_flag = TRUE;
        mmi_cbm_add_data_list_node(&g_cbm_active_data_node, TRUE);
    }
    else
    {
        PRINT_INFORMATION(("$$$$$ CBM add node to list $$$$$"));
                    
        mmi_cbm_add_data_list_node(&g_cbm_active_data_node, FALSE);
    }

    if(!mmi_cbm_data_list_is_empty())
    {
        mmi_cbm_start_timer();
    }

    if(GetActiveScreenId() == SCR_ID_CBM_LIST)
    {
        mmi_cbm_redraw_conn_list_screen(); 
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_deactive_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_deactive_ind_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_abm_cbm_deactive_ind_struct *deactive_ind;
    S8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    deactive_ind = (mmi_abm_cbm_deactive_ind_struct *)info;
    
    PRINT_INFORMATION(("$$$$$ CBM Deactive Indicate profile_id = %d, connect_type = %d $$$$$", 
                      deactive_ind->profile_id, deactive_ind->connect_type));

    if(deactive_ind->connect_type == CBM_CONNECT_TYPE_DAILUP)
    {
        if(deactive_ind->dailup_info.connect_type == CSD_BEARER_DIALUP)
        {
            index = mmi_cbm_find_data_list_node_index(deactive_ind->dailup_info.call_id, deactive_ind->connect_type);
        }
        else
        {
            index = mmi_cbm_find_data_list_node_index(deactive_ind->dailup_info.context_id, deactive_ind->connect_type);
        }
    }
    else
    {
        mmi_cbm_send_bearer_status_ind(deactive_ind->profile_id, CBM_BEARER_STATE_DEACTIVATED);
        index = mmi_cbm_find_data_list_node_index(deactive_ind->profile_id, deactive_ind->connect_type);
    }
    
    if(index < 0)
    {
        ASSERT(0);
        return;
    }

    PRINT_INFORMATION(("$$$$$ CBM Deactive Indicate profile_id = %d, index = %d $$$$$", 
                      g_cbm_bearer_list[index].profile_id, index));

    /* Active Screen is detail info screen redraw the screen */
    if((GetActiveScreenId() == SCR_ID_CBM_DETAIL) &&
        (g_cbm_display_data_node.profile_id == deactive_ind->profile_id) &&
        (g_cbm_display_data_node.connect_type == deactive_ind->connect_type))
    {      
        g_cbm_bearer_list[index].active_status = CBM_CONNECT_STATUS_DEACTIVE;
        mmi_cbm_redraw_conn_detail_screen(); 
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            ASSERT(0);
            return;
        }
        mmi_cbm_check_is_stop_timer();
        return;
    }
    else if((IsScreenPresent(SCR_ID_CBM_DETAIL) &&
        (g_cbm_display_data_node.profile_id == deactive_ind->profile_id) &&
        (g_cbm_display_data_node.connect_type == deactive_ind->connect_type)))
    {
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            ASSERT(0);
            return;
        }
        DeleteScreenIfPresent(SCR_ID_CBM_DETAIL);
        mmi_cbm_check_is_stop_timer();
        return;
    }
    else if((IsScreenPresent(SCR_ID_CBM_DETAIL) &&
        ((g_cbm_display_data_node.profile_id != deactive_ind->profile_id) ||
        (g_cbm_display_data_node.connect_type != deactive_ind->connect_type))))
    {
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            ASSERT(0);
            return;
        }
        mmi_cbm_check_is_stop_timer();
        return;
    }

    if(GetActiveScreenId() == SCR_ID_CBM_OPTION)
    {        
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            ASSERT(0);
            return;
        }
        GoBackHistory();  
    }
    else if(GetActiveScreenId() == SCR_ID_CBM_LIST)
    {
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            ASSERT(0);
            return;
        }
        mmi_cbm_redraw_conn_list_screen(); 
    }
    else if(IsScreenPresent(SCR_ID_CBM_LIST))
    {
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            ASSERT(0);
            return;
        }
    }
    else
    {
        if(!mmi_cbm_delete_data_list_node(g_cbm_bearer_list[index].profile_id, g_cbm_bearer_list[index].connect_type))
        {
            //ASSERT(0); /* wap will send disconnect before connect, this delete must failed */
            return;
        }
    }

    mmi_cbm_check_is_stop_timer();
    return;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_disconnect_pre_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_disconnect_pre_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    mmi_cbm_pre_select_data_node();
    mmi_cbm_bearer_disconnect_req_handler(g_cbm_display_data_node.profile_id, g_cbm_display_data_node.connect_type, 
                                          g_cbm_display_data_node.dialup_type);
    mmi_cbm_disconnect_process();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_disconnect_all_pre_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_disconnect_all_pre_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CBM_Display_context_struct* first_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    first_node = mmi_cbm_get_data_list_head_node();
    if(first_node == NULL)
    {
        ASSERT(0);
        return;
    }

    PRINT_INFORMATION(("$$$$$ CBM Disconnect all pre handle  profile_id = %d, connect_type = %d $$$$$", 
                          first_node->profile_id, first_node->connect_type));

    mmi_cbm_bearer_disconnect_req_handler(first_node->profile_id, first_node->connect_type, first_node->dialup_type);
    mmi_cbm_disconnect_process();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_disconnect_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_disconnect_req_handler(U32 profile_id, U8 connect_type, U8 dialup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_abm_cbm_disconect_req_struct *disc_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION(("$$$$$ CBM Disconnect Req  profile_id = %d, connect_type = %d $$$$$", 
                          profile_id, connect_type));

    g_cbm_disc_flag = TRUE;
    SetProtocolEventHandler(mmi_cbm_bearer_disconnect_cnf_handler, MSG_ID_MMI_ABM_CBM_DISCONNECT_CNF);

    disc_req = (mmi_abm_cbm_disconect_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_cbm_disconect_req_struct));

    if(connect_type == CBM_CONNECT_TYPE_LOCAL)
    {
        disc_req->profile_id = profile_id;
        disc_req->connect_type = connect_type;
    }
    else
    {
        disc_req->connect_type = CBM_CONNECT_TYPE_DAILUP;    
        disc_req->dailup_info.connect_type = dialup_type;
        if(disc_req->dailup_info.connect_type == CSD_BEARER_DIALUP)
        {
            disc_req->dailup_info.call_id = profile_id;
        }
        else
        {
            disc_req->dailup_info.context_id = profile_id;
        }
    }
    

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_CBM_DISCONNECT_REQ;
    Message.oslDataPtr = (oslParaType*)disc_req;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_disconnect_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_disconnect_cnf_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_cbm_disconnect_cnf_struct *cnf;
    CBM_Display_context_struct *first_node;
    U8 count;
    S8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cnf = (mmi_abm_cbm_disconnect_cnf_struct *)info;

    PRINT_INFORMATION(("$$$$$ CBM Disconnect Cnf profile_id = %d, connect_type = %d, result = %d $$$$$", 
                      cnf->profile_id, cnf->connect_type, cnf->result));

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_CBM_DISCONNECT_CNF);

    g_cbm_disc_flag = FALSE;
    if(cnf->result == TRUE)
    {
        mmi_cbm_send_bearer_status_ind(cnf->profile_id, CBM_BEARER_STATE_DEACTIVATED);
        if(!mmi_cbm_delete_data_list_node(cnf->profile_id, cnf->connect_type))
        {
            ASSERT(0);
            return;
        }

        if(g_cbm_disc_all_flag)
        {
            first_node = mmi_cbm_get_data_list_head_node();
            if(first_node == NULL)
            {
                g_cbm_disc_all_flag = FALSE;
                if(g_cbm_backup_list_flag)
                {
                    mmi_cbm_copy_data_list_from_backup();
                }
                else
                {
                    mmi_cbm_clear_data_list_node();
                }
                /**/
                mmi_cbm_check_is_stop_timer();
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
                DeleteScreenIfPresent(SCR_ID_CBM_DISC_PRODUCESS);
                DeleteScreenIfPresent(SCR_ID_CBM_OPTION);
                DeleteScreenIfPresent(SCR_ID_CBM_DUMP);
                if(GetActiveScreenId() == SCR_ID_CBM_LIST)
                {
                    mmi_cbm_redraw_conn_list_screen(); 
                }
                return;
            }
            mmi_cbm_bearer_disconnect_req_handler(first_node->profile_id, first_node->connect_type, first_node->dialup_type);
        }
        else
        {
            /**/
            mmi_cbm_check_is_stop_timer();
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
            DeleteScreenIfPresent(SCR_ID_CBM_DISC_PRODUCESS);
            DeleteScreenIfPresent(SCR_ID_CBM_OPTION);
            DeleteScreenIfPresent(SCR_ID_CBM_DUMP);
            if(GetActiveScreenId() == SCR_ID_CBM_LIST)
            {
                mmi_cbm_redraw_conn_list_screen(); 
            }
        }
    }
    else
    {
        /**/
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 1, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_CBM_DISC_PRODUCESS);
        DeleteScreenIfPresent(SCR_ID_CBM_OPTION);
        DeleteScreenIfPresent(SCR_ID_CBM_DUMP);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_get_bearer_info_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_get_bearer_info_req_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_abm_cbm_get_bearer_info_req_struct *req;
    U8 count, i, k = 0;
    U8 bearer_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetProtocolEventHandler(mmi_cbm_bearer_get_bearer_info_cnf_handler, MSG_ID_MMI_ABM_CBM_GET_BEARER_INFO_CNF);
    
    req = (mmi_abm_cbm_get_bearer_info_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_cbm_get_bearer_info_req_struct));

    count = mmi_cbm_get_data_list_num();

    if(count == 0)
    {
        ASSERT(0);
        return;
    }

    req->count = count;

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list[i].valid)
        {
            PRINT_INFORMATION(("$$$$$ CBM Get Bearer Detail Info Req profile_id = %d, connect_type = %d $$$$$", 
                          g_cbm_bearer_list[i].profile_id, g_cbm_bearer_list[i].connect_type));
            req->bearer_req_count[k].profile_id = g_cbm_bearer_list[i].profile_id;
            req->bearer_req_count[k].connect_type = g_cbm_bearer_list[i].connect_type;
            if(g_cbm_bearer_list[i].connect_type == CBM_CONNECT_TYPE_DAILUP)
            {
                bearer_type = mmi_dtcnt_get_bearer_type((U8)g_cbm_display_data_node.profile_id);
                if(bearer_type == DATA_ACCOUNT_BEARER_CSD)
                {
                    req->bearer_req_count[k].dailup_info.connect_type = CSD_BEARER_DIALUP;
                    req->bearer_req_count[k].dailup_info.call_id = g_cbm_bearer_list[i].profile_id;
                }
                else if(bearer_type == DATA_ACCOUNT_BEARER_GPRS)
                {
                    req->bearer_req_count[k].dailup_info.connect_type = GPRS_BEARER_DIALUP;
                    req->bearer_req_count[k].dailup_info.context_id = g_cbm_bearer_list[i].profile_id;
                }
                k++;
            }
        }
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_CBM_GET_BEARER_INFO_REQ;
    Message.oslDataPtr = (oslParaType*)req;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_bearer_get_bearer_info_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_bearer_get_bearer_info_cnf_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_cbm_get_bearer_info_cnf_struct *cnf;
    S8 index , i;
    float data_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cnf = (mmi_abm_cbm_get_bearer_info_cnf_struct*)info;

    PRINT_INFORMATION(("$$$$$ CBM get Detail Cnf count = %d $$$$$", cnf->count));

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_CBM_GET_BEARER_INFO_CNF);

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list[i].valid)
        {
            g_cbm_bearer_list[i].cbm_bearer_detail_info.connect_time++;
        }
    }
    
    for(i = 0; i < cnf->count; i++)
    {
        if(cnf->bearer_cnf_count[i].result)
        {
            index = mmi_cbm_find_data_list_node_index(cnf->bearer_cnf_count[i].profile_id, CBM_CONNECT_TYPE_LOCAL);
            
            if(index < 0)
            {
                ASSERT(0);
                return;
            }

            data_size = (float)cnf->bearer_cnf_count[i].send_data_size;
            g_cbm_bearer_list[index].cbm_bearer_detail_info.up_speed = data_size  - g_cbm_bearer_list[index].cbm_bearer_detail_info.send_data_size;

            PRINT_INFORMATION(("$$$$$ CBM Detail Cnf profile_id = %d, connect_type = %d, index = %d, send_size = %d, new_send_size = %d, upspeed = %d $$$$$", 
                                g_cbm_bearer_list[index].profile_id, 
                                g_cbm_bearer_list[index].connect_type, index, 
                                g_cbm_bearer_list[index].cbm_bearer_detail_info.send_data_size,
                                cnf->bearer_cnf_count[i].send_data_size,
                                g_cbm_bearer_list[index].cbm_bearer_detail_info.up_speed));
                                
 
            data_size = (float)cnf->bearer_cnf_count[i].receive_data_size;
            g_cbm_bearer_list[index].cbm_bearer_detail_info.down_speed = data_size - g_cbm_bearer_list[index].cbm_bearer_detail_info.receive_data_size;
            
            PRINT_INFORMATION(("$$$$$ CBM Detail Cnf rece_size = %d, new_rece_size = %d, downspeed $$$$$",  
                                g_cbm_bearer_list[index].cbm_bearer_detail_info.receive_data_size,
                                cnf->bearer_cnf_count[i].receive_data_size,
                                g_cbm_bearer_list[index].cbm_bearer_detail_info.down_speed));

            g_cbm_bearer_list[index].cbm_bearer_detail_info.receive_data_size = cnf->bearer_cnf_count[i].receive_data_size;
            g_cbm_bearer_list[index].cbm_bearer_detail_info.send_data_size = cnf->bearer_cnf_count[i].send_data_size ;
            
            g_cbm_bearer_list[index].cbm_bearer_detail_info.all_data_size = cnf->bearer_cnf_count[i].receive_data_size + cnf->bearer_cnf_count[i].send_data_size;
            
            
            

        }        
    }
    
    if(GetActiveScreenId() == SCR_ID_CBM_DETAIL)
    {
        mmi_cbm_redraw_conn_detail_screen();
    }
    else if(GetActiveScreenId() == SCR_ID_CBM_LIST)
    {
        mmi_cbm_update_conn_list_screen();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_init_data_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_init_data_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_cbm_bearer_list, 0, sizeof(CBM_Display_context_struct)*CBM_MAX_BEARER_LIST_NUM);
    memset(g_cbm_bearer_list_index, 0, sizeof(CBM_bearer_list_index_struct)*CBM_MAX_BEARER_LIST_NUM);

    memset(&g_cbm_display_data_node, 0, sizeof(CBM_Display_context_struct));

    /* for bearer status api */
    memset(g_cbm_bearer_status, 0, sizeof(cbm_bearer_status_struct)*CBM_BEARER_STATUS_MAX_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_data_list_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_get_data_list_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i< CBM_MAX_BEARER_LIST_NUM; i++)
    {
        PRINT_INFORMATION(("$$$$$ CBM Get Bearer List Num acct_id = %d, conn_type = %d, valid = %d, index = %d $$$$$", 
            g_cbm_bearer_list[i].profile_id, g_cbm_bearer_list[i].connect_type, g_cbm_bearer_list[i].valid, i));
        if(g_cbm_bearer_list[i].valid)
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_data_list_profile_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_get_data_list_profile_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*---------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list_index[i].valid)
        {
            g_list_profile_name[i] = (U8*)g_cbm_bearer_list[g_cbm_bearer_list_index[i].list_index].profile_name;
        }
    }
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_data_list_data_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_get_data_list_data_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S8  data_size[CBM_MAX_DATA_SIZE_LEN + 1];
    float datasize;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list_index[i].valid)
        {
            datasize = (float)g_cbm_bearer_list[g_cbm_bearer_list_index[i].list_index].cbm_bearer_detail_info.all_data_size;
            datasize = datasize / CBM_DATA_UINT_SIZE;
            sprintf(data_size, "%.2f", datasize);
            strcat(data_size, CBM_DATA_SIZE_UINT);
            AnsiiNToUnicodeString(g_cbm_bearer_list[g_cbm_bearer_list_index[i].list_index].str_data_size, data_size, CBM_MAX_DATA_SIZE_LEN);
            g_list_data_size[i] = (U8*)g_cbm_bearer_list[g_cbm_bearer_list_index[i].list_index].str_data_size;
        }
    }
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_data_list_data_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static CBM_Display_context_struct * mmi_cbm_get_data_list_head_node(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list[i].valid)
        {
            g_cbm_bearer_list[i].valid = FALSE;
            return &g_cbm_bearer_list[i];
        }
    }
    
    return NULL;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_add_data_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_add_data_list_node(CBM_Display_context_struct *info, U8 backup_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(backup_flag)
    {
        for(i = 0; i < CBM_MAX_BEARER_LIST_NUM/2; i++)
        {
            if(!g_cbm_bearer_list_backup[i].valid)
            {
                memcpy(&g_cbm_bearer_list_backup[i], info, sizeof(CBM_Display_context_struct));
                g_cbm_bearer_list_backup[i].valid = TRUE;
                return TRUE;
            }
        }
       
        return FALSE;
    }
    else
    {
        /* check the same item */
        for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
        {
            if((g_cbm_bearer_list[i].valid) && (g_cbm_bearer_list[i].profile_id == info->profile_id) &&
                (g_cbm_bearer_list[i].connect_type == info->connect_type))
            {
                return TRUE;
            }
        }
    
        /* add node to bearer list */
        for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
        {
            if(!g_cbm_bearer_list[i].valid)
            {
                memcpy(&g_cbm_bearer_list[i], info, sizeof(CBM_Display_context_struct));
                g_cbm_bearer_list[i].valid = TRUE;
                index = i;
                PRINT_INFORMATION(("$$$$$ CBM Bearer List  acct_id = %d, conn_type = %d, valid = %d, index = %d $$$$$", 
                                              g_cbm_bearer_list[i].profile_id, g_cbm_bearer_list[i].connect_type, g_cbm_bearer_list[i].valid, i));
                break;
            }
        }

        /* update index list */
        for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
        {
            if(!g_cbm_bearer_list_index[i].valid)
            {
                g_cbm_bearer_list_index[i].list_index = index;
                g_cbm_bearer_list_index[i].valid = TRUE;
                break;
            }
        }

        return TRUE;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_delete_data_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_delete_data_list_node(U32 profile_id, U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i,j;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if((g_cbm_bearer_list[i].valid) && (g_cbm_bearer_list[i].profile_id == profile_id) && 
            (g_cbm_bearer_list[i].connect_type == connect_type))
        {
            g_cbm_bearer_list[i].valid = FALSE;
            index = i;
            break;
        }
    }

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list_index[i].list_index == index)
        {
            for(j = i; j < CBM_MAX_BEARER_LIST_NUM - 1; j++)
            {
                g_cbm_bearer_list_index[j].list_index = g_cbm_bearer_list_index[j+1].list_index;
                g_cbm_bearer_list_index[j].valid = g_cbm_bearer_list_index[j+1].valid;
            }
            return TRUE;
        }
    }
 
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_copy_data_list_from_backup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_copy_data_list_from_backup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count, count_backup;
    U8 j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    count = 0;
    count_backup = 0;

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list[i].valid)
        {
            count++;
        }
    }

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM/2; i++)
    {
        if(g_cbm_bearer_list_backup[i].valid)
        {
            count_backup++;
        }
    }

    if((CBM_MAX_BEARER_LIST_NUM - count) >= count_backup)
    {
        for(i = 0; i < count_backup; i++)
        {
            mmi_cbm_add_data_list_node(&g_cbm_bearer_list_backup[i], FALSE);
        }
    }
    else
    {
        for(i = 0; i < (CBM_MAX_BEARER_LIST_NUM - count); i++)
        {
            mmi_cbm_add_data_list_node(&g_cbm_bearer_list_backup[i], FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_clear_data_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_clear_data_list_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(g_cbm_bearer_list, 0, sizeof(CBM_Display_context_struct) * CBM_MAX_BEARER_LIST_NUM);
    memset(g_cbm_bearer_list_backup, 0, sizeof(CBM_Display_context_struct) * CBM_MAX_BEARER_LIST_NUM/2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_find_data_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S8 mmi_cbm_find_data_list_node_index(U32 profile_id, U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if((g_cbm_bearer_list[i].valid) && (g_cbm_bearer_list[i].profile_id == profile_id) &&
            (g_cbm_bearer_list[i].connect_type == connect_type))
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_find_data_list_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_data_list_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if(g_cbm_bearer_list[i].valid)
        {
            return FALSE;
        }
    }

    return TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(!g_cbm_timer_start_flag)
    {
        g_cbm_timer_start_flag = TRUE;
        StartTimer(CBM_CONNECTION_TIMER_ID, CBM_TIMER_OUT, mmi_cbm_timeout_handler);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CBM_Display_context_struct * temp;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cbm_bearer_get_bearer_info_req_handler();
    
    mmi_cbm_start_timer();

    return ;
}


/*****************************************************************************
* FUNCTION
*  mmi_cbm_update_conn_list_screen
* DESCRIPTION
*  redraw connection list screen
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static void mmi_cbm_update_conn_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_cbm_get_data_list_data_size();
    wgui_cat354_refresh();
}


/*****************************************************************************
* FUNCTION
*  mmi_cbm_redraw_conn_list_screen
* DESCRIPTION
*  redraw connection list screen
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static void mmi_cbm_redraw_conn_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_cbm_entry_bearer_list();
}


/*****************************************************************************
* FUNCTION
*  mmi_cbm_redraw_conn_detail_screen
* DESCRIPTION
*  redraw connection detail info screen
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static void mmi_cbm_redraw_conn_detail_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cbm_get_redraw_data_node();
    mmi_cbm_get_detail_info();
    ChangeCategory74MessageString((U8*)subMenuData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_redraw_data_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_get_redraw_data_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION(("$$$$$ CBM pre select data node index = %d, list index = %d $$$$$", 
                        g_cbm_bearer_list_index[g_cbm_list_select_index].list_index, g_cbm_list_select_index));

    for(i = 0; i < CBM_MAX_BEARER_LIST_NUM; i++)
    {
        if((g_cbm_bearer_list[i].valid) &&
            (g_cbm_bearer_list[i].profile_id == g_cbm_bearer_list[g_cbm_bearer_list_index[g_cbm_list_select_index].list_index].profile_id))
        {
            memcpy(&g_cbm_display_data_node, 
                &g_cbm_bearer_list[i],
               sizeof(CBM_Display_context_struct));

            return;
        }
    }
    
    ASSERT(0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_check_is_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_cbm_data_list_is_empty())
    {
        StopTimer(CBM_CONNECTION_TIMER_ID);
    }
}
#endif /* __CBM_CM_FEATURE__ */

#ifdef __CBM_ALWAYS_ASK_FEATURE__
/* soc send ask acct ind */
/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_soc_ask_acct_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_soc_ask_acct_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_soc_ask_acct_ind_struct *ask_acct_ind;
    BOOL result;
    U8 app_id;
    module_type mod_id;
    U16 App_str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ask_acct_ind = (mmi_soc_ask_acct_ind_struct*)info;

    PRINT_INFORMATION("$$$$$ always ask soc ask acct ind app_id = %d, mod_id = %d$$$$$", 
        ask_acct_ind->app_id, ask_acct_ind->mod_id);

    if(ask_acct_ind->status == SOC_ASK_ACCT_CANCEL_SCREEN)
    {
        mmi_always_ask_delete_screen();
        return;
    }
    result = always_ask_register_app_check_id(ask_acct_ind->app_id);
    if(!result)
    {
        /* send ask acct cnf failed to soc */
        mmi_cbm_soc_ask_acct_cnf_hdlr(FALSE, ask_acct_ind->app_id, ask_acct_ind->mod_id, 0, 0);
        g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_CNF;

        if(!mmi_cbm_soc_ask_acct_queue_is_empty())
        {
            /* get next indicate from queue */
            mmi_cbm_soc_ask_acct_queue_get(&app_id, &mod_id, &g_cbm_soc_sim_info);
            /* get call back or mod id by app id */
            mmi_cbm_get_app_register_info(app_id, mod_id, &g_app_register_info);
            
            g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_IND;

            always_ask_register_get_app_name(app_id, &App_str_id);
            /* show data account select screen let user select acct */
            mmi_dtcnt_select_account_option_ext(mmi_cbm_always_ask_select_acct_callback, 
                                                                App_str_id,
                                                                0,//MENU_ID_CBM_APP, 
                                                                DATA_ACCOUNT_BEARER_ALL,
#ifdef __MMI_DUAL_SIM__
                                                                DTCNT_SELECT_SIM,
#else
                                                                DTCNT_SELECT_NO_SIM,
#endif /* __MMI_DUAL_SIM__ */
                                                                DTCNT_SELECT_NO_ALWAYS_ASK
                                                                );
        }
        
        return;
    }

    if(g_soc_ask_acct.soc_cnf_flag == CBM_SOC_ASK_ACCT_IND)
    {
        if(mmi_cbm_soc_ask_acct_queue_is_full())
        {
            /* send ask acct cnf failed to soc */
            mmi_cbm_soc_ask_acct_cnf_hdlr(FALSE, ask_acct_ind->app_id, ask_acct_ind->mod_id, SOC_NEED_NOTIFY, 0);
            g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_CNF;
            return;
        }
        /* add soc ind queue */
        mmi_cbm_soc_ask_acct_queue_add(ask_acct_ind->app_id, ask_acct_ind->mod_id, ask_acct_ind->sim_src);
        return;
    }

    g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_IND;
    
    g_cbm_soc_sim_info = ask_acct_ind->sim_src;
    g_cbm_soc_mod_id = ask_acct_ind->mod_id;
    /* get call back or mod id by app id */
    mmi_cbm_get_app_register_info(ask_acct_ind->app_id, ask_acct_ind->mod_id, &g_app_register_info);

    always_ask_register_get_app_name(ask_acct_ind->app_id, &App_str_id);

    /* show data account select screen let user select acct */
    mmi_dtcnt_select_account_option_ext(mmi_cbm_always_ask_select_acct_callback, 
                                                                App_str_id,
                                                                0,//MENU_ID_CBM_APP, 
                                                                DATA_ACCOUNT_BEARER_ALL,
#ifdef __MMI_DUAL_SIM__
                                                                DTCNT_SELECT_SIM,
#else
                                                                DTCNT_SELECT_NO_SIM,
#endif /* __MMI_DUAL_SIM__ */
                                                                DTCNT_SELECT_NO_ALWAYS_ASK
                                                                );

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_soc_ask_acct_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_cbm_soc_ask_acct_queue_add(U8 app_id, module_type mod_id, U8 sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if(!g_soc_ask_acct.soc_ind_queue[i].valid)
        {
            g_soc_ask_acct.soc_ind_queue[i].app_id = app_id;
            g_soc_ask_acct.soc_ind_queue[i].mod_id = mod_id;
            g_soc_ask_acct.soc_ind_queue[i].sim_info = sim_info;
            g_soc_ask_acct.soc_ind_queue[i].valid = TRUE;
            g_soc_ask_acct.soc_ind_num++;
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_soc_ask_acct_queue_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_cbm_soc_ask_acct_queue_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(g_soc_ask_acct.soc_ind_queue[0].valid)
    {
        return FALSE;
    }
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_soc_ask_acct_queue_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_cbm_soc_ask_acct_queue_is_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(g_soc_ask_acct.soc_ind_num == ALWAYS_ASK_MAX_APP_NUM)
    {
        return TRUE;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_soc_ask_acct_queue_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_cbm_soc_ask_acct_queue_get(U8 *app_id, module_type *mod_id, U8 *sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(g_soc_ask_acct.soc_ind_queue[0].valid)
    {
        *app_id = g_soc_ask_acct.soc_ind_queue[0].app_id;
        *mod_id = g_soc_ask_acct.soc_ind_queue[0].mod_id;
        *sim_info = g_soc_ask_acct.soc_ind_queue[0].sim_info;
    }

    /**/
    for(i = 0; i < (ALWAYS_ASK_MAX_APP_NUM-1); i++)
    {
        g_soc_ask_acct.soc_ind_queue[i].app_id = g_soc_ask_acct.soc_ind_queue[i+1].app_id;
        g_soc_ask_acct.soc_ind_queue[i].mod_id = g_soc_ask_acct.soc_ind_queue[i+1].mod_id;
        g_soc_ask_acct.soc_ind_queue[i].valid = g_soc_ask_acct.soc_ind_queue[i+1].valid;
    }

    if(g_soc_ask_acct.soc_ind_num == ALWAYS_ASK_MAX_APP_NUM)
    {
        g_soc_ask_acct.soc_ind_queue[ALWAYS_ASK_MAX_APP_NUM-1].app_id = 0;
        g_soc_ask_acct.soc_ind_queue[ALWAYS_ASK_MAX_APP_NUM-1].mod_id = 0;
        g_soc_ask_acct.soc_ind_queue[ALWAYS_ASK_MAX_APP_NUM-1].valid = FALSE;
    }
    
    g_soc_ask_acct.soc_ind_num--;

    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_always_ask_select_acct_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_always_ask_select_acct_callback(U32 acct_id, BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 app_id;
    module_type mod_id;
    soc_bearer_status_enum status; /* soc_bearer_status_enum */
    U16 App_str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(g_app_register_info.register_type != REGISTER_TYPE_TOTAL)
    {
        status = 0;
    }
    else
    {
        status = SOC_NEED_NOTIFY;
    }

    /*if(result)
    {
        cbm_set_acctid_register_info(g_app_register_info.app_id, acct_id);
    }*/

    if(g_app_register_info.register_type == REGISTER_TYPE_CALLBACK)
    {
        /* send acct cnf to soc */
        mmi_cbm_soc_ask_acct_cnf_hdlr(result, g_app_register_info.app_id, g_app_register_info.mod_id, status, acct_id);
        /* set ask acct cnf flag */
        g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_CNF;
        /* return the account id to app */
        g_app_register_info.callback(acct_id, result);

        /* handler another ask acct from soc */
        if(!mmi_cbm_soc_ask_acct_queue_is_empty())
        {
            /* get next indicate from queue */
            mmi_cbm_soc_ask_acct_queue_get(&app_id, &mod_id, &g_cbm_soc_sim_info);
            /* get call back or mod id by app id */
            mmi_cbm_get_app_register_info(app_id, mod_id, &g_app_register_info);
            
            g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_IND;
            
            always_ask_register_get_app_name(app_id, &App_str_id);
            /* show data account select screen let user select acct */
            mmi_dtcnt_select_account_option_ext(mmi_cbm_always_ask_select_acct_callback, 
                App_str_id,
                0,//MENU_ID_CBM_APP, 
                DATA_ACCOUNT_BEARER_ALL,
#ifdef __MMI_DUAL_SIM__
                DTCNT_SELECT_SIM,
#else
                DTCNT_SELECT_NO_SIM,
#endif /* __MMI_DUAL_SIM__ */
                DTCNT_SELECT_NO_ALWAYS_ASK
                );
        }
    }
    else if(g_app_register_info.register_type == REGISTER_TYPE_PRIMITIVE)
    {
        /* send primitive to app */
        mmi_cbm_always_ask_select_result_ind(result, acct_id, g_app_register_info.mod_id);
    }
    else
    {
        /* send acct cnf to soc */
        mmi_cbm_soc_ask_acct_cnf_hdlr(result, g_app_register_info.app_id, g_cbm_soc_mod_id, status, acct_id);
        /* set ask acct cnf flag */
        g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_CNF;
    }

}  

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_always_ask_select_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_always_ask_select_result_ind(BOOL result, U32 acct_id, module_type mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_cbm_always_ask_select_account_result_ind_struct *ask_acct_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetProtocolEventHandler(mmi_cbm_always_ask_select_result_cnf, MSG_ID_MMI_CBM_ALWAYS_ASK_SELECT_ACCOUNT_RESULT_CNF);
    PRINT_INFORMATION("$$$$$ CBM soc ask acct int result = %d, mod_id = %d, acct_id = %d $$$$$", 
        result, mod_id, acct_id);
    
    ask_acct_cnf = (mmi_cbm_always_ask_select_account_result_ind_struct*) OslConstructDataPtr(sizeof(mmi_cbm_always_ask_select_account_result_ind_struct));
    
    ask_acct_cnf->result = result;
    ask_acct_cnf->acct_id = acct_id;
    
    Message.oslSrcId  = MOD_MMI;
    Message.oslDestId = mod_id;
    Message.oslMsgId  = MSG_ID_MMI_CBM_ALWAYS_ASK_SELECT_ACCOUNT_RESULT_IND;
    Message.oslDataPtr = (oslParaType*)ask_acct_cnf;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_always_ask_select_result_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_always_ask_select_result_cnf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 app_id;
    module_type mod_id;
    U16 App_str_id;
    soc_bearer_status_enum status; /* soc_bearer_status_enum */
    mmi_cbm_always_ask_select_account_result_cnf_struct *ask_acct_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ask_acct_cnf = (mmi_cbm_always_ask_select_account_result_cnf_struct*)info;

    ClearProtocolEventHandler(MSG_ID_MMI_CBM_ALWAYS_ASK_SELECT_ACCOUNT_RESULT_CNF);
    PRINT_INFORMATION("$$$$$ CBM soc ask acct int result = %d, acct_id = %d $$$$$", 
        ask_acct_cnf->result , ask_acct_cnf->acct_id);
    
    if(g_app_register_info.register_type != REGISTER_TYPE_TOTAL)
    {
        status = 0;
    }
    else
    {
        status = SOC_NEED_NOTIFY;
    }

    /* set ask acct cnf flag */
    g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_CNF;

    /* send acct cnf to soc */
    mmi_cbm_soc_ask_acct_cnf_hdlr(ask_acct_cnf->result, g_app_register_info.app_id, g_app_register_info.mod_id, status, ask_acct_cnf->acct_id);

    /* handler another ask acct from soc */
    if(!mmi_cbm_soc_ask_acct_queue_is_empty())
    {
        /* get next indicate from queue */
        mmi_cbm_soc_ask_acct_queue_get(&app_id, &mod_id, &g_cbm_soc_sim_info);
        /* get call back or mod id by app id */
        mmi_cbm_get_app_register_info(app_id, mod_id, &g_app_register_info);
        
        g_soc_ask_acct.soc_cnf_flag = CBM_SOC_ASK_ACCT_IND;
        
        always_ask_register_get_app_name(app_id, &App_str_id);
        /* show data account select screen let user select acct */
        mmi_dtcnt_select_account_option_ext(mmi_cbm_always_ask_select_acct_callback, 
            App_str_id,
            0,//MENU_ID_CBM_APP, 
            DATA_ACCOUNT_BEARER_ALL,
#ifdef __MMI_DUAL_SIM__
            DTCNT_SELECT_SIM,
#else
            DTCNT_SELECT_NO_SIM,
#endif /* __MMI_DUAL_SIM__ */
            DTCNT_SELECT_NO_ALWAYS_ASK
            );
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_soc_ask_acct_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_soc_ask_acct_cnf_hdlr(BOOL result, U8 app_id, module_type mod_id, soc_bearer_status_enum option, U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 acctid;
    mmi_soc_ask_acct_cnf_struct *ask_acct_cnf;
    always_ask_sim_info_enum sim_enum;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    PRINT_INFORMATION("$$$$$ CBM soc ask acct cnf result = %d, app_id = %d, mod_id = %d $$$$$", 
        result, app_id, mod_id);
    
    ask_acct_cnf = (mmi_soc_ask_acct_cnf_struct*) OslConstructDataPtr(sizeof(mmi_soc_ask_acct_cnf_struct));
    
    sim_enum = always_ask_get_sim_info_data_account(acct_id);
    if(sim_enum == SOC_SIM_INFO_SIM2)
    {
        acctid = always_ask_encode_data_account_id(acct_id, SOC_SIM_INFO_SIM2, 0, FALSE);
    }
    else
    {
        acctid = always_ask_encode_data_account_id(acct_id, SOC_SIM_INFO_SIM1, 0, FALSE);
    }
    ask_acct_cnf->result = result;
    ask_acct_cnf->app_id = app_id;
    ask_acct_cnf->mod_id = mod_id;
    ask_acct_cnf->account_id = acctid;
    ask_acct_cnf->status = option;
   
    Message.oslSrcId  = MOD_MMI;
    Message.oslDestId = MOD_SOC;
    Message.oslMsgId  = MSG_ID_MMI_SOC_ASK_ACCT_CNF;
    Message.oslDataPtr = (oslParaType*)ask_acct_cnf;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_dtcnt_init_sataus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_cbm_get_dtcnt_init_sataus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_cbm_dtcnt_init_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_set_dtcnt_init_sataus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cbm_set_dtcnt_init_sataus(kal_uint8 dtcnt_init_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_cbm_dtcnt_init_status = dtcnt_init_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_add_bearer_status_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_cbm_add_bearer_status_notify_hdlr(FuncPtrBearerStatus event_callback, kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, app_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("$$$$$ CBM add bearer status acct_id = %d, callback = %d $$$$$", acct_id, event_callback);

    if(event_callback == NULL)
    {
        ASSERT(0);
        return 0;
    }

    app_id = always_ask_get_app_id_data_account(acct_id);

    for(i = 0; i < CBM_BEARER_STATUS_MAX_NUM; i++)
    {
        if((g_cbm_bearer_status[i].valid) && (g_cbm_bearer_status[i].bearer_status_callback == event_callback) && 
            (g_cbm_bearer_status[i].app_id == app_id) && (g_cbm_bearer_status[i].acct_id == acct_id))
        {
            return g_cbm_bearer_status[i].index;
        }
    }
    

    for(i = 0; i < CBM_BEARER_STATUS_MAX_NUM; i++)
    {
        if(!g_cbm_bearer_status[i].valid)
        {
            g_cbm_bearer_status[i].valid = TRUE;
            g_cbm_bearer_status[i].bearer_status_callback = event_callback;
            g_cbm_bearer_status[i].mod_id = 0;
            g_cbm_bearer_status[i].acct_id = acct_id;
            g_cbm_bearer_status[i].index = i + 1;
            g_cbm_bearer_status[i].app_id = app_id;
            return g_cbm_bearer_status[i].index;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_del_bearer_status_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_cbm_del_bearer_status_notify_hdlr(kal_uint8 index, kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("$$$$$ CBM del bearer status index = %d, acct_id = %d $$$$$", index, acct_id);

    if(index == 0 || index > CBM_BEARER_STATUS_MAX_NUM)
    {
        ASSERT(0);
        return FALSE;
    }

    app_id = always_ask_get_app_id_data_account(acct_id);

    if((g_cbm_bearer_status[index-1].index != index) ||
        (g_cbm_bearer_status[index-1].app_id != app_id))
    {
        return FALSE;
    }
    
    if(g_cbm_bearer_status[index -1].valid)
    {
        g_cbm_bearer_status[index -1].valid = FALSE;
        g_cbm_bearer_status[index -1].bearer_status_callback = NULL;
        g_cbm_bearer_status[index -1].acct_id = 0;
        g_cbm_bearer_status[index -1].index = 0;
        g_cbm_bearer_status[index -1].app_id = 0;
        return TRUE;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_add_bearer_status_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_add_bearer_status_req_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbm_add_bearer_status_notify_req_struct *bearer_status_req;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    bearer_status_req = (mmi_cbm_add_bearer_status_notify_req_struct *)info;
    
    PRINT_INFORMATION("$$$$$ CBM add bearer status req hdlr acct_id = %d, mod_id = %d $$$$$", 
                      bearer_status_req->acct_id, bearer_status_req->mod_id);
    
    index = mmi_cbm_add_bearer_status_req(bearer_status_req->mod_id, bearer_status_req->acct_id);
    mmi_cbm_add_bearer_status_cnf(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_add_bearer_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_add_bearer_status_req(U32 mod_id, U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, app_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("$$$$$ CBM add bearer status req acct_id = %d, mod_id = %d $$$$$", acct_id, mod_id);

    app_id = always_ask_get_app_id_data_account(acct_id);

    for(i = 0; i < CBM_BEARER_STATUS_MAX_NUM; i++)
    {
        if((g_cbm_bearer_status[i].valid) && (g_cbm_bearer_status[i].mod_id == mod_id) && 
            (g_cbm_bearer_status[i].app_id == app_id) && (g_cbm_bearer_status[i].acct_id == acct_id))
        {
            return g_cbm_bearer_status[i].index;
        }
    }

    
    for(i = 0; i < CBM_BEARER_STATUS_MAX_NUM; i++)
    {
        if(!g_cbm_bearer_status[i].valid)
        {
            g_cbm_bearer_status[i].valid = TRUE;
            g_cbm_bearer_status[i].mod_id = mod_id;
            g_cbm_bearer_status[i].bearer_status_callback = NULL;
            g_cbm_bearer_status[i].acct_id = acct_id;
            g_cbm_bearer_status[i].index = i + 1;
            g_cbm_bearer_status[i].app_id = app_id;
            return g_cbm_bearer_status[i].index;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_add_bearer_status_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_add_bearer_status_cnf(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mod_id = 0;
    MYQUEUE Message;
    mmi_cbm_add_bearer_status_notify_cnf_struct *bearer_status_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ CBM add bearer status cnf index = %d $$$$$", index);

    if(index == 0 || index > CBM_BEARER_STATUS_MAX_NUM)
    {
        ASSERT(0);
        return;
    }

    if(g_cbm_bearer_status[index-1].valid)
    {
        mod_id = g_cbm_bearer_status[index-1].mod_id;
    }
    

    if(mod_id == 0)
    {
        ASSERT(0);
        return;
    }

    bearer_status_cnf = (mmi_cbm_add_bearer_status_notify_cnf_struct*) OslConstructDataPtr(sizeof(mmi_cbm_add_bearer_status_notify_cnf_struct));
    if(index == 0)
    {
        bearer_status_cnf->result = FALSE;
    }
    else
    {
        bearer_status_cnf->result = TRUE;
    }
    bearer_status_cnf->index = index;
    
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = mod_id;
    Message.oslMsgId = MSG_ID_MMI_CBM_ADD_BEARER_STATUS_NOTIFY_CNF;
    Message.oslDataPtr = (oslParaType*)bearer_status_cnf;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_del_bearer_status_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_del_bearer_status_req_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbm_del_bearer_status_notify_req_struct *bearer_status_req;
    BOOL result;
    U32 mod_id;
    U8 app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    bearer_status_req = (mmi_cbm_del_bearer_status_notify_req_struct *)info;
    
    PRINT_INFORMATION("$$$$$ CBM del bearer status req hdlr acct_id = %d, mod_id = %d, index = %d $$$$", 
                      bearer_status_req->acct_id, bearer_status_req->mod_id, bearer_status_req->index);

    app_id = always_ask_get_app_id_data_account(bearer_status_req->acct_id);
    result = mmi_cbm_del_bearer_status_req(bearer_status_req->index, app_id);

    mmi_cbm_del_bearer_status_cnf(result, bearer_status_req->mod_id, bearer_status_req->acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_del_bearer_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_cbm_del_bearer_status_req(U8 index, U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("$$$$$ CBM del bearer status req index = %d, app_id = %d $$$$$", index, app_id);
    
    if(index == 0 || index > CBM_BEARER_STATUS_MAX_NUM)
    {
        ASSERT(0);
        return FALSE;
    }

    if((g_cbm_bearer_status[index-1].index != index) ||
        (g_cbm_bearer_status[index-1].app_id != app_id))
    {
        return FALSE;
    }
        
    if(g_cbm_bearer_status[index-1].valid)
    {
        g_cbm_bearer_status[index-1].valid = FALSE;
        g_cbm_bearer_status[index-1].mod_id = 0;
        g_cbm_bearer_status[index-1].acct_id = 0;
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_del_bearer_status_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_del_bearer_status_cnf(BOOL result, U32 mod_id, U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_cbm_del_bearer_status_notify_cnf_struct *bearer_status_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ CBM del bearer status cnf result = %d, mod_id = %d, acct_id = %d $$$$$", 
                       result, mod_id, acct_id);

    bearer_status_cnf = (mmi_cbm_del_bearer_status_notify_cnf_struct*) OslConstructDataPtr(sizeof(mmi_cbm_del_bearer_status_notify_cnf_struct));
    
    bearer_status_cnf->result = result;
    bearer_status_cnf->acct_id = acct_id;
    
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = mod_id;
    Message.oslMsgId = MSG_ID_MMI_CBM_DEL_BEARER_STATUS_NOTIFY_CNF;
    Message.oslDataPtr = (oslParaType*)bearer_status_cnf;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_send_bearer_status_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_send_bearer_status_ind(U32 acct_id, mmi_cbm_bearer_state_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ CBM send bearer status ind acct = %d, status = %d $$$$$", acct_id, status);

    for(i = 0; i < CBM_BEARER_STATUS_MAX_NUM; i++)
    {
        if(g_cbm_bearer_status[i].valid && (g_cbm_bearer_status[i].acct_id == acct_id))
        {
            PRINT_INFORMATION("$$$$$ CBM send bearer status valid acct = %d$$$$$", acct_id);
            if((g_cbm_bearer_status[i].bearer_status_callback == NULL) &&
                (g_cbm_bearer_status[i].mod_id != 0))
            {
                mmi_cbm_send_bearer_status_ind_hdlr(g_cbm_bearer_status[i].mod_id, status, acct_id);
                return;
            }
            else if((g_cbm_bearer_status[i].bearer_status_callback != NULL) &&
                (g_cbm_bearer_status[i].mod_id == 0))
            {
                g_cbm_bearer_status[i].bearer_status_callback(status, acct_id);
                return;
            }
            else
            {
                ASSERT(0);
                return;
            }
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_send_bearer_status_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbm_send_bearer_status_ind_hdlr(U32 mod_id, mmi_cbm_bearer_state_enum status, U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_cbm_bearer_status_notify_ind_struct *bearer_status_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ CBM send bearer status ind mod_id = %d, status = %d, acct_id = %d $$$$$", 
        mod_id, status, acct_id);
    
    bearer_status_ind = (mmi_cbm_bearer_status_notify_ind_struct*) OslConstructDataPtr(sizeof(mmi_cbm_bearer_status_notify_ind_struct));
    
    bearer_status_ind->acct_id = acct_id;
    bearer_status_ind->status = status;
    
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = mod_id;
    Message.oslMsgId = MSG_ID_MMI_CBM_BEARER_STATUS_NOTIFY_IND;
    Message.oslDataPtr = (oslParaType*)bearer_status_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

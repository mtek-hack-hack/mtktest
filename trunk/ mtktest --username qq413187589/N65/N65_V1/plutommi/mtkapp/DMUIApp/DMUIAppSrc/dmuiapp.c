/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*	dmuiapp.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file for DMUI application.
*
* Author:
* -------
*	Xiangjun Dan (mbj06013)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/
#include "MMI_include.h"

#ifdef SYNCML_DM_SUPPORT

#include "dmuiappdef.h"
#include "dmuiprot.h"

/* DM PS head file */
#include "DMTypeDef.h"
#include "DMGprot.h"

/* Task message communication */

/* URL check function head file */
#include "app_url.h"

/* Data Account type define header file */
#include "DataAccountGprot.h"

#include "CommonScreens.h"
#include "SettingProfile.h"
#include "CentralConfigAgentGProt.h"    /* CCA header */  
#include "cbfunc.h"

#include "gpioInc.h"            /* for TurnOnBacklight function */
#include "IdleAppDef.h"         /* for POPUP_SCREENID */
#include "SettingDefs.h"        /* SCR_RESTORE_PROCESSING */
#include "PhoneBookTypes.h"
#include "SettingsGdcl.h"       /* security struct */
#include "vObjectsResDef.h"       

#include "custom_syncml_dm_config.h"  /* custom config */
#include "custom_data_account.h"

/***************************************************************************** 
* define
*****************************************************************************/
#ifndef DMUI_MAX_SERVERID
#define DMUI_MAX_SERVERID DM_ACCOUNT_MAX_NUM
#endif

#define __SYNCML_DM_TEST__

#define FILL_DMUI_INFO(dst, tag_src, value_src, format)  kal_sprintf((dst),(format),(tag_src), (value_src));

#define DMUI_SPLIT_STRING L"<!NEXT>"

/***************************************************************************** 
* Global Variable
*****************************************************************************/
dmui_context_struct dmui_context;
dmui_context_struct *ptr_dmui_context = &dmui_context;

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Variable
*****************************************************************************/
#ifdef __MMI_SYNCML_DM_OTAP__
extern syncml_dm_ota_context_struct *g_syncml_dm_ota_context;
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/
extern int mmi_bootup_is_searching_or_idle_reached(void);
extern int isInCall(void);
extern U8  AlmIsTonePlaying(void);

extern void mmi_dm_set_check_function(dm_setting_type_enum type, DMCheckCBFunc func);

bf_bool mmi_syncml_dm_check(void);

extern void mmi_dm_print_info(dm_account_struct * ptr_dm_account);

extern void mmi_dm_unfinish_check_info(void);
/*****************************************************************************
* Local Function 
*****************************************************************************/
/* high light function for DMUI setting screens */
static void mmi_dmui_highlight_main(void);
static void mmi_dmui_highlight_op_activate(void);
static void mmi_dmui_highlight_op_edit(void);
static void mmi_dmui_highlight_op_erase(void);

/* pre entry function for DMUI main menu and send message to DM PS */
static void mmi_dmui_entry_main_pre(void);
static void mmi_dmui_entry_main(void);

/* entry option menu with empty server id item or not */
static void mmi_dmui_entry_option_main(void);
static void mmi_dmui_entry_option_main_empty(void);

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
static void mmi_dmui_entry_option_main_default_profile(void);
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

/* high light functions for option screen items */
static void mmi_dmui_entry_option_activate(void);
static void mmi_dmui_entry_option_edit(void);
static void mmi_dmui_entry_option_edit_pre(void);
static void mmi_dmui_exit_option_edit(void);

static void mmi_dmui_save_highlight_serverid(S32 index);
static void mmi_dmui_info_hilite_handler(S32 hiliteid);

/* function to entry info connection settings screen */
static void mmi_dmui_info_cs_hilite_handler(S32 hiliteid);
static void mmi_dmui_info_cs_fill_struct(void);
static void mmi_dmui_info_cs_checkinput(void);

/* function to check user input in info edit screen */
static void mmi_dmui_info_checkinput(void);
static void mmi_dmui_info_inlinecustom(void);
static void mmi_dmui_info_fill_struct(void);

static void mmi_dmui_entry_option_erase_confirm(void);
static void mmi_dmui_entry_option_erase_confirm_yes(void);
static void mmi_dmui_entry_option_erase_confirm_no(void);

static void mmi_dmui_info_save_no(void);

/* functions to check popup and interrupt result */
static MMI_BOOL mmi_dmui_interrupt_check(void);
static MMI_BOOL mmi_dmui_popup_check(void);

/* entry function of connection settings */
static void mmi_dmui_info_connection_setting_entry(void);
static void mmi_dmui_exit_info_connection_setting(void);

/* entry function of data account */
static void mmi_dmui_info_cs_data_account_entry(void);

static void mmi_dmui_info_cs_data_account_cb(U32 account_id);
static void mmi_dmui_info_cs_checkinput_yes(void);
static void mmi_dmui_info_cs_checkinput_no(void);
static void mmi_dmui_info_cs_checkinput_cancel(void);
static void mmi_dmui_info_cs_ip_callback(U8 *str_buffer, U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4);

/* call back function for data account ready and read account name */
static void mmi_dmui_main_data_account_check(void);

/* function to response different case in DM setting edit screen with different case of server id */
static void mmi_dmui_info_save_confirm_serverid_inactivated_changed(void);
static void mmi_dmui_info_save_confirm_serverid_activated_changed(void);
static void mmi_dmui_info_save_confirm_serverid_nochanged(void);


/* receive DM PS message and display screen and other functions */
/* functions for download progress screen */
static void mmi_dmui_download_progress_cancel(void);
static void mmi_dmui_download_progress_no(void);
static void mmi_dmui_display_download_progress(U32 percentage);

static void mmi_dmui_entry_reset_progress(void);

/* waiting screen when edit or erase DM setting */
static void mmi_dmui_waiting_entry(void);

/* function to response key event of user pin input screen */
static void mmi_dmui_entry_user_pin_confirm(void);
static void mmi_dmui_entry_user_pin_confirm_ok(void);
static void mmi_dmui_entry_user_pin_confirm_no(void);
static void mmi_dmui_entry_user_pin_confirm_cancel(void);
static void mmi_dmui_exit_user_pin_confirm(void);
static void mmi_dmui_user_pin_change_lsk(U8 *text, U8 *cursor, S32 length);

/* function to entry download or update screen */
static void mmi_dmui_entry_download_confirm(void);
static void mmi_dmui_entry_update_confirm(void);
static void mmi_dmui_read_info_from_file(U16 *file_path);
static void mmi_dmui_oma_fill_info(U16 srcid, S8 *out);

/* function to response user input in download confirm screen */
static void mmi_dmui_download_confirm_cancel_hdlr(void);
static void mmi_dmui_download_confirm_yes_hdlr(void);
static void mmi_dmui_download_confirm_no_hdlr(void);

/* function to response user input in update confirm screen */
static void mmi_dmui_update_confirm_cancel_hdlr(void);
static void mmi_dmui_update_confirm_yes_hdlr(void);
static void mmi_dmui_update_confirm_defer_hdlr(void);

/* functions for entry alert message screen */
static void mmi_dmui_entry_alert_display(void);
static void mmi_dmui_entry_alert_confirm(void);
static void mmi_dmui_entry_alert_input(void);
static void mmi_dmui_entry_alert_single_choice(void);
static void mmi_dmui_entry_alert_multi_choice(void);

/* alert confirm */
static void mmi_dmui_entry_alert_confirm_ok(void);
static void mmi_dmui_alert_confirm_no(void);
static void mmi_dmui_alert_confirm_cancel(void);

/* alert input */
static void mmi_dmui_exit_alert_input(void);
static void mmi_dmui_alert_input_fill_item(void);
static void mmi_dmui_alert_input_confirm(void);
static void mmi_dmui_alert_input_confirm_yes(void);
static void mmi_dmui_alert_input_date_callback(U8 *str_buffer, U8 *day, U8 *month, U8 *year);
static void mmi_dmui_alert_input_time_callback(U8 *str_buffer, U8 *hour, U8 *minute, U8 *am_pm_flag);
static void mmi_dmui_alert_input_ip_callback(U8 *str_buffer, U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4);
static void mmi_dmui_return_three_digit_string(U8 *string_val, U8 digit_val);

static void mmi_dmui_alert_parse_string(void);
static void mmi_dmui_alert_parse_status(void);

/* alert single choice */
static void mmi_dmui_hilite_single_choice_handle(S32 hilited);
static void mmi_dmui_entry_alert_single_choice_ok(void);

static void mmi_dmui_init_serverid(void);

/* alert multi choice */
static void mmi_dmui_alert_multi_choice_confirm(void);
static void mmi_dmui_alert_multi_choice_confirm_yes(void);

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* function to init default DM setting profile */
static void mmi_dm_ota_init_profile(void);
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

/* function for message from DM PS */
static void mmi_dmui_add_account_rsp_handle(void *msg);
static void mmi_dmui_del_account_rsp_handle(void *msg);
static void mmi_dmui_get_account_rsp_handle(void *msg);
static void mmi_dmui_list_serverid_rsp_handle(void *msg);
static void mmi_dmui_get_pserverid_rsp_handle(void *msg);
static void mmi_dmui_set_pserverid_rsp_handle(void *msg);
static void mmi_dmui_init_session_ind_handle(void *msg);
static void mmi_dmui_userpin_ind_handle(void *msg);
static void mmi_dmui_download_ind_handle(void *msg);
static void mmi_dmui_update_ind_handle(void *msg);
static void mmi_dmui_alert_ind_handle(void *msg);
static void mmi_dmui_reset_ind_handle(void *msg);
static void mmi_dmui_download_progress_ind_handle(void *msg);
static void mmi_dmui_change_account_ind_handle(void *msg);
static void mmi_dmui_exec_complete_ind_handle(void *msg);
static void mmi_dmui_session_start_ind_handle(void *msg);
static void mmi_dmui_session_finish_ind_handle(void *msg);
static void mmi_dmui_error_ind_handle(void *msg);


/*****************************************************************************
* FUNCTION
*  mmi_dmui_init
* DESCRIPTION
*  init DMUI main menu function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_dmui_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_init function");

    SetHiliteHandler(MENU_ID_DMUI_MAIN, mmi_dmui_highlight_main);
    SetHiliteHandler(MENU_ID_DMUI_OP_ACTIVATE, mmi_dmui_highlight_op_activate);
    SetHiliteHandler(MENU_ID_DMUI_OP_EDIT, mmi_dmui_highlight_op_edit);
    SetHiliteHandler(MENU_ID_DMUI_OP_ERASE, mmi_dmui_highlight_op_erase);
    
    /*--------------- protocol event handler for message from DM PS -------------*/
    
    /* get add server id message response from DM PS */
    SetProtocolEventHandler(mmi_dmui_add_account_rsp_handle, MSG_ID_DM_ADD_ACCOUNT_RSP);
    
    /* get del server id message response from DM pS */
    SetProtocolEventHandler(mmi_dmui_del_account_rsp_handle, MSG_ID_DM_DEL_ACCOUNT_RSP);
    
    /* get info of server id message response from DM PS */
    SetProtocolEventHandler(mmi_dmui_get_account_rsp_handle, MSG_ID_DM_GET_ACCOUNT_RSP);
    
    /* get server list message from DM PS */
    SetProtocolEventHandler(mmi_dmui_list_serverid_rsp_handle, MSG_ID_DM_LIST_SERVERID_RSP);
    
    /* get primary server id message from DM PS */
    SetProtocolEventHandler(mmi_dmui_get_pserverid_rsp_handle, MSG_ID_DM_GET_PSERVERID_RSP);
    
    /* set primary server id message from DM PS */
    SetProtocolEventHandler(mmi_dmui_set_pserverid_rsp_handle, MSG_ID_DM_SET_PSERVERID_RSP);
    
    /* get init session message from DM PS */
    SetProtocolEventHandler(mmi_dmui_init_session_ind_handle, MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND);
    
    /* get user pin request from DM PS */
    SetProtocolEventHandler(mmi_dmui_userpin_ind_handle, MSG_ID_DM_GET_BOOTSTRAP_USERPIN_REQ_IND);
    
    /* get download request from DM PS */
    SetProtocolEventHandler(mmi_dmui_download_ind_handle, MSG_ID_DM_DL_REQ_IND);
    
    /* get update request from DM PS */
    SetProtocolEventHandler(mmi_dmui_update_ind_handle, MSG_ID_DM_UPDATE_REQ_IND);
    
    /* receive alert indication from DM PS */
    SetProtocolEventHandler(mmi_dmui_alert_ind_handle, MSG_ID_DM_ALERT_REQ_IND);
    SetProtocolEventHandler(mmi_dmui_reset_ind_handle, MSG_ID_DM_RESET_IND);
    SetProtocolEventHandler(mmi_dmui_download_progress_ind_handle, MSG_ID_DM_DL_PROGRESS_IND);

    SetProtocolEventHandler(mmi_dmui_change_account_ind_handle, MSG_ID_DM_CHANGE_IND);
    
    SetProtocolEventHandler(mmi_dmui_exec_complete_ind_handle, MSG_ID_DM_EXEC_COMPLETE_IND);
    SetProtocolEventHandler(mmi_dmui_session_start_ind_handle, MSG_ID_DM_SESSION_START_IND);
    SetProtocolEventHandler(mmi_dmui_session_finish_ind_handle, MSG_ID_DM_SESSION_FINISH_IND);
    SetProtocolEventHandler(mmi_dmui_error_ind_handle, MSG_ID_DM_ERROR_IND);

    mmi_dmui_init_serverid();

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
    mmi_dm_ota_init_profile();
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
    
    mmi_dm_set_check_function(DM_SETTING_TYPE_DM, mmi_syncml_dm_check);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_highlight_main
* DESCRIPTION
*  function of highlight DM UI main menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    SetLeftSoftkeyFunction(mmi_dmui_entry_main_pre, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_dmui_entry_main_pre, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_main_pre
* DESCRIPTION
*  function before entry option screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_main_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_main_pre function");    

    ptr_dmui_context->dmui_status = MMI_DMUI_LIST_SERVERID_STATUS;
    
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_LIST_SERVERID_REQ, NULL);
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_PSERVERID_REQ, NULL);

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_main
* DESCRIPTION
*  function of entry DMUI main menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_main(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8  i;
    U8  *gui_buffer = NULL;  
    PU8 sub_menu_data_ptrs[DMUI_MAX_SERVERID];
    U16 serverid_states_icon[DMUI_MAX_SERVERID];
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_main function");  

    EntryNewScreen(SCR_ID_DMUI_MAIN, NULL, mmi_dmui_entry_main, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_MAIN);
    
    RegisterHighlightHandler(mmi_dmui_save_highlight_serverid);
    
    for (i = 0; i < DMUI_MAX_SERVERID; i++)
    {
        /* if this server ID is empty */
        if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[i]) == 0)
        {
            sub_menu_data_ptrs[i] = (U8*)GetString(STR_GLOBAL_EMPTY_LIST);

            serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
        }
        else
        {
            sub_menu_data_ptrs[i] = (U8*)ptr_dmui_context->dmui_serverid_array[i];

            if ((mmi_ucs2cmp((S8*)sub_menu_data_ptrs[i], (S8*)ptr_dmui_context->dmui_primary_serverid) == 0)
				&& (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_primary_serverid) != 0))
            {
				serverid_states_icon[i] = IMG_ID_DMUI_SEL_IMAGE;
            }
            else
            {
                serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
            }
        }
    }
    
    ShowCategory73Screen(
        STR_ID_DMUI_MAIN,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        DMUI_MAX_SERVERID,
        sub_menu_data_ptrs,
        serverid_states_icon,
        (U16*)gIndexIconsImageList,
        0,
        gui_buffer,
        1);

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_save_highlight_serverid
* DESCRIPTION
*  function to save current high light server ID index
* PARAMETERS
*  index    [IN]    current high light item index
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_save_highlight_serverid(S32 index)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_context->dmui_hilite_serverid_index = index;

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
    if (index == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);

        SetLeftSoftkeyFunction(mmi_dmui_entry_option_main_default_profile, KEY_EVENT_UP);
        SetKeyHandler(mmi_dmui_entry_option_main_default_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        return;
    }
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

    if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[index]) == 0)
    {
        /* send left soft key function for change feature */
        SetLeftSoftkeyFunction(mmi_dmui_entry_option_main_empty, KEY_EVENT_UP);
        SetKeyHandler(mmi_dmui_entry_option_main_empty, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);

        SetLeftSoftkeyFunction(mmi_dmui_entry_option_edit_pre, KEY_EVENT_UP);
        SetKeyHandler(mmi_dmui_entry_option_edit_pre, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);

        SetLeftSoftkeyFunction(mmi_dmui_entry_option_main, KEY_EVENT_UP);
        SetKeyHandler(mmi_dmui_entry_option_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

}

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_main_default_profile
* DESCRIPTION
*  function of entry option screen with default profile item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_main_default_profile(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];    /* Stores the strings id of sub menus returned */
    U16 item_num;                        /* Stores no of children in the sub menu */
    U8 *gui_buffer;                      /* Buffer holding history data */
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_option_main_default_profile function"); 
    
    EntryNewScreen(SCR_ID_DMUI_OPTION, NULL, mmi_dmui_entry_option_main_default_profile, NULL);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_OPTION);
    
    item_num = GetNumOfChild(MENU_ID_DMUI_OPTION_DEFAULT_PROFILE);
    
    GetSequenceStringIds(MENU_ID_DMUI_OPTION_DEFAULT_PROFILE, str_item_list);
    
    SetParentHandler(MENU_ID_DMUI_OPTION_DEFAULT_PROFILE);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    /* Display Category Screen */
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        str_item_list,
        (PU16)gIndexIconsImageList,
        0,
        0,
        0,
        gui_buffer);
    
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_main_empty
* DESCRIPTION
*  function of entry option screen with empty server ID item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_main_empty(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 item_num;                        /* Stores no of children in the submenu */
    U8 *gui_buffer;                      /* Buffer holding history data */
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_option_main_empty function"); 

    EntryNewScreen(SCR_ID_DMUI_OPTION, NULL, mmi_dmui_entry_option_main_empty, NULL);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_OPTION);
    
    item_num = GetNumOfChild(MENU_ID_DMUI_OPTION_EMPTY);
    
    GetSequenceStringIds(MENU_ID_DMUI_OPTION_EMPTY, str_item_list);
    
    SetParentHandler(MENU_ID_DMUI_OPTION_EMPTY);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    /* Display Category Screen */
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        str_item_list,
        (PU16)gIndexIconsImageList,
        0,
        0,
        0,
        gui_buffer);
    
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_main
* DESCRIPTION
*  function of entry option menu screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_main(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 item_num;                        /* Stores no of children in the submenu */
    U8 *gui_buffer;                      /* Buffer holding history data */
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_option_main function"); 

    EntryNewScreen(SCR_ID_DMUI_OPTION, NULL, mmi_dmui_entry_option_main, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_OPTION);
    
    item_num = GetNumOfChild(MENU_ID_DMUI_OPTION);
    
    GetSequenceStringIds(MENU_ID_DMUI_OPTION, str_item_list);
    
    SetParentHandler(MENU_ID_DMUI_OPTION);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    /* Display Category Screen */
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        str_item_list,
        (PU16)gIndexIconsImageList,
        0,
        0,
        0,
        gui_buffer);
    
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_activate
* DESCRIPTION
*  function of entry option activate item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_activate(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_server_id_struct *dmui_active_serverid = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_option_activate function"); 

    dmui_active_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
    
    mmi_ucs2cpy((S8*)dmui_active_serverid->server_id,
        (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);
    
    ptr_dmui_context->dmui_status = MMI_DMUI_SET_PSERVERID_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_edit_pre
* DESCRIPTION
*  function of entry option edit item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_edit_pre(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_server_id_struct *dmui_get_account = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_option_edit_pre function"); 
    
    /* if current server id is empty */
    if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]) == 0)
    {
        memset(&ptr_dmui_context->dmui_cur_edit_account, 0x00, sizeof(dm_account_struct));

#ifdef CUSTOM_DEFAULT_DM_DTCNT_ID
        ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = (U16)CUSTOM_DEFAULT_DM_DTCNT_ID;
#else
        ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = (U16)-1;
#endif /* CUSTOM_DEFAULT_DM_DTCNT_ID */

        ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_port = (U32)DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT;

        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.server_addr, (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR);

        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_addr, (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP);

        mmi_dmui_entry_option_edit();
    }
    else    /* if server id not empty */
    {
		dmui_get_account = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));

        ptr_dmui_context->dmui_status = MMI_DMUI_GET_ACCOUNT_STATUS;

		mmi_ucs2cpy((S8*)dmui_get_account->server_id,
					(S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);

        DMUI_SEND_MSG_TO_DMPS(
            MSG_ID_DM_GET_ACCOUNT_REQ,
            (S8*)dmui_get_account
            );
    }

}

/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_edit
* DESCRIPTION
*  function of entry option edit item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_edit(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 *input_buffer;
    U8 *gui_buffer;
    U16 input_buffer_size;
    U16 icon_list[MMI_DMUI_INLINE_ITEM_TOTAL] = 
    {
        IMG_ID_DMUI_SERVERID,
        0,
        IMG_ID_DMUI_SERVER_PASSWORD,
        0,
        IMG_ID_DMUI_SERVER_ADDRESS,
        0,
        IMG_ID_DMUI_USERNAME,
        0,
        IMG_ID_DMUI_USER_PASSWORD,
        0,
#ifndef __MMI_OP01_DM_PROFILE_SETTING__    
        IMG_ID_DMUI_CONNECTION_SETTING,
        0,
#endif    
        IMG_ID_DMUI_AUTHTYPE,
        0
    };
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_entry_option_edit function");

    EntryNewScreen(SCR_ID_DMUI_INFO, mmi_dmui_exit_option_edit, NULL, NULL);
    
    InitializeCategory57Screen();
    
    RegisterHighlightHandler(mmi_dmui_info_hilite_handler);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_INFO);
    
    input_buffer = GetCurrNInputBuffer(SCR_ID_DMUI_INFO, &input_buffer_size);  

    if ((GetInlineDoneFlag(gui_buffer) == 0) &&    /* current done flag is false */
         (ptr_dmui_context->dmui_info_done_flag == MMI_TRUE))   /* current cs info */
    {
        /* DMUI info cs screen changed and set done in this screen */
        SetInlineDoneFlag(gui_buffer);   

        ptr_dmui_context->dmui_info_done_flag = MMI_FALSE;
    }

    mmi_dmui_info_fill_struct();

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_DMUI_INLINE_ITEM_TOTAL, input_buffer);
    }

    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        0,
        MMI_DMUI_INLINE_ITEM_TOTAL,
        icon_list,
        wgui_inline_items,
        0,
        gui_buffer);

    SetCategory57RightSoftkeyFunctions(mmi_dmui_info_checkinput, mmi_dmui_info_save_no);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_hilite_handler
* DESCRIPTION
*  function to set LSK and function with different high light index
* PARAMETERS
*  hiliteid        [IN]        current high light item index
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_hilite_handler(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(hiliteid)
    {
        case MMI_DMUI_SERVERID_EDITOR:
        case MMI_DMUI_SERVER_ADDRESS_EDITOR:
        case MMI_DMUI_USERNAME_EDITOR:
            break;

        case MMI_DMUI_SERVER_PASSWORD_EDITOR:
        case MMI_DMUI_USER_PASSWORD_EDITOR:
        case MMI_DMUI_AUTHTYPE_EDITOR:
            {
                SetCategory57LeftSoftkeyFunction(mmi_dmui_info_checkinput);
            }
            break;

#ifndef __MMI_OP01_DM_PROFILE_SETTING__
        case MMI_DMUI_CONNECTION_SETTING_EDITOR:
            {
                ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);

                /* when high light connection setting item */
                /* copy current conn setting struct to temp struct */
                memcpy(&(ptr_dmui_context->dmui_cur_edit_conn_setting), 
                       &(ptr_dmui_context->dmui_cur_edit_account.conn_setting),
                       sizeof(dm_conn_setting_struct));
                
                SetLeftSoftkeyFunction(mmi_dmui_info_connection_setting_entry, KEY_EVENT_UP);
            }   
            break;
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
            
        default:
            break;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_connection_setting_entry
* DESCRIPTION
*  function to entry connection setting screen
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_connection_setting_entry(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 i = 0;
    U8 *input_buffer;
    U8 *gui_buffer;
    U16 input_buffer_size;
    U16 dmui_info_cs_icon_list[MMI_DMUI_CS_INLINE_ITEM_TOTAL];
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_info_connection_setting_entry function");

    EntryNewScreen(SCR_ID_DMUI_INFO_CS, mmi_dmui_exit_info_connection_setting, NULL, NULL);
    
    InitializeCategory57Screen();
    
    RegisterHighlightHandler(mmi_dmui_info_cs_hilite_handler);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_INFO_CS);
    
    input_buffer = GetCurrNInputBuffer(SCR_ID_DMUI_INFO_CS, &input_buffer_size);

    for (i = 0; i < MMI_DMUI_CS_INLINE_ITEM_TOTAL; i+=2)
    {
        dmui_info_cs_icon_list[i] = gIndexIconsImageList[(i + 1)/2];        
        dmui_info_cs_icon_list[i + 1] = 0;
    }
    
    if ((ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id != 
        ptr_dmui_context->dmui_cur_edit_conn_setting.data_account_id)   /* data account changed */
        && (GetInlineDoneFlag(gui_buffer) == 0))
    {
        SetInlineDoneFlag(gui_buffer);
    }

    mmi_dmui_info_cs_fill_struct();
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]finish mmi_dmui_info_cs_fill_struct function");
    
    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_DMUI_CS_INLINE_ITEM_TOTAL, input_buffer);
    }
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]start showcategory 57 function");

    ShowCategory57Screen(
        STR_ID_DMUI_CONNECTION_SETTING,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        0,
        MMI_DMUI_CS_INLINE_ITEM_TOTAL,
        (U16*)dmui_info_cs_icon_list,
        wgui_inline_items,
        0,
        gui_buffer);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]end showcategory 57 function");

    SetCategory57RightSoftkeyFunctions(mmi_dmui_info_cs_checkinput, GoBackHistory);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_exit_info_connection_setting
* DESCRIPTION
*  function to exit connection setting screen
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_exit_info_connection_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history his;
    U16 inputbuffersize;    /* added for inline edit history */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    his.scrnID = SCR_ID_DMUI_INFO_CS;

    CloseCategory57Screen();
    
    his.entryFuncPtr = mmi_dmui_info_connection_setting_entry;
    
    GetCategoryHistory(his.guiBuffer);
    
    /* added for inline edit history */
    inputbuffersize = (U16)GetCategory57DataSize();
    
    /* added for inline edit history */
    GetCategory57Data((U8*)his.inputBuffer);
    
    /* added for inline edit history */    
    AddNHistory(his, (U16)inputbuffersize);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_hilite_handler
* DESCRIPTION
*  function to set LSK and function with high light index
* PARAMETERS
*  hiliteid     [IN]    current high light item index        
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_hilite_handler(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(hiliteid)
    {
        case MMI_DMUI_CS_USERNAME_EDITOR:
            break;

        case MMI_DMUI_CS_USE_PROXY_EDITOR:
        case MMI_DMUI_CS_PASSWORD_EDITOR:
        case MMI_DMUI_CS_IP:
        case MMI_DMUI_CS_PORT:
            {
                SetCategory57LeftSoftkeyFunction(mmi_dmui_info_cs_checkinput);
            }
            break;

        case MMI_DMUI_CS_DATA_ACCOUNT_EDITOR:
            {
                ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
                SetLeftSoftkeyFunction(mmi_dmui_info_cs_data_account_entry, KEY_EVENT_UP);
            }   
            break;

        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_checkinput
* DESCRIPTION
*  function to check user input in DMUI conn setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_checkinput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)ptr_dmui_context->proxy_port_str) == 0)
    {
        ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_port = -1;
    }
    else
    {
        ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_port = (U32)gui_atoi((UI_string_type)ptr_dmui_context->proxy_port_str);
    }

    if ((U32)gui_atoi((UI_string_type)ptr_dmui_context->proxy_port_str) > 65535)
    {
        /* port number shall not exceed 65535 */
        DisplayPopup(
            (U8*)GetString(STR_ID_DMUI_CS_INVALID_PORT),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8)ERROR_TONE);
        
        return;
    }

    if (ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_used == 1)
    {
        /* invalid proxy ip and use proxy */
        if ((U32)gui_atoi((UI_string_type)ptr_dmui_context->dmui_info_cs_ip[0]) == 0)
        {
            DisplayPopup(
                (U8*)GetString(STR_ID_DMUI_CS_INVALID_IP),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8)ERROR_TONE);

            return;
        }
    }

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_dmui_info_cs_checkinput_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dmui_info_cs_checkinput_no, KEY_EVENT_UP);

    SetKeyHandler(mmi_dmui_info_cs_checkinput_cancel, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_checkinput_yes
* DESCRIPTION
*  function to press yes of DMUI conn setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_checkinput_yes(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    DisplayPopup(
        (PU8)GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

    memcpy(&(ptr_dmui_context->dmui_cur_edit_account.conn_setting), 
           &(ptr_dmui_context->dmui_cur_edit_conn_setting), 
           sizeof(dm_conn_setting_struct));

    memset(&(ptr_dmui_context->dmui_cur_edit_conn_setting), 0x00, sizeof(dm_conn_setting_struct));
    
    ptr_dmui_context->dmui_info_done_flag = MMI_TRUE;    /* set for dmui info screen not display done */

    CloseCategory57Screen();
    DeleteUptoScrID(SCR_ID_DMUI_INFO);
    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_checkinput_no
* DESCRIPTION
*  function to press no of DMUI conn setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_checkinput_no(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    memset(&(ptr_dmui_context->dmui_cur_edit_conn_setting), 0x00, sizeof(dm_conn_setting_struct));
    
    ptr_dmui_context->dmui_info_done_flag = MMI_FALSE;    /* set for dmui info screen not display done */

    CloseCategory57Screen();
    DeleteUptoScrID(SCR_ID_DMUI_INFO);
    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_checkinput_cancel
* DESCRIPTION
*  function to cancel save DMUI connection setting confirm
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_checkinput_cancel(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 cur_dmui_acct_name[DM_MAX_ID_STR];

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    memset(&(ptr_dmui_context->dmui_cur_edit_conn_setting), 0x00, sizeof(dm_conn_setting_struct));

    if ((U32) ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id == (U32) (-1))
    {
        mmi_ucs2cpy((S8*) cur_dmui_acct_name, (S8*) L"");
    }
    else
    {
        mmi_dtcnt_get_account_name(
            (U32) ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id,
            (S8*) cur_dmui_acct_name,
            DM_MAX_ID_STR / 2);
    }

    if ((*cur_dmui_acct_name) != 0 && (*(cur_dmui_acct_name + 1) != 0))     /* if data account name valid, set it to cur account */
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.acct_name, (S8*)cur_dmui_acct_name);
    }

    ptr_dmui_context->dmui_info_done_flag = MMI_FALSE;    /* set for DMUI info screen not display done */

    CloseCategory57Screen();

    DeleteScreenIfPresent(SCR_ID_DMUI_INFO_CS);

    DisplayIdleScreen();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_fill_struct
* DESCRIPTION
*  function to fill inline items of DMUI connection setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_fill_struct(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    const S8 g_dmui_zero_ip[] = { '0', '\0', '0', '\0', '0', '\0', '\0', '\0' }; /* 000 */    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_info_cs_fill_struct function");
    
    ptr_dmui_context->mmi_dmui_cs_use_proxy[0] = (U8*)GetString(STR_GLOBAL_NO);
    ptr_dmui_context->mmi_dmui_cs_use_proxy[1] = (U8*)GetString(STR_GLOBAL_YES);
	
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]proxy_addr = %s \n", 
        ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_addr);

	if (ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_addr[0] == 0)
	{
		mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_info_cs_ip[0], (S8*)g_dmui_zero_ip);
		mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_info_cs_ip[1], (S8*)g_dmui_zero_ip);
		mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_info_cs_ip[2], (S8*)g_dmui_zero_ip);
		mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_info_cs_ip[3], (S8*)g_dmui_zero_ip);
	}
	else
	{
	    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]start call mmi_dmui_return_four_digit_ip \n");
        
		mmi_dmui_return_four_digit_ip((U8*)ptr_dmui_context->dmui_info_cs_ip, 
			(S8*)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_addr);

        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]end call mmi_dmui_return_four_digit_ip \n");
    }
	
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]data account id = %d \n", 
        ptr_dmui_context->dmui_cur_edit_conn_setting.data_account_id);

#ifndef __MMI_OP01_DM_PROFILE_SETTING__
    if ((U32) ptr_dmui_context->dmui_cur_edit_conn_setting.data_account_id == (U32) (-1))
    {
        mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_cur_edit_account.acct_name, (S8*) L"");
    }
    else
    {
        mmi_dtcnt_get_account_name(
            (U32) ptr_dmui_context->dmui_cur_edit_conn_setting.data_account_id,
            (S8*) ptr_dmui_context->dmui_cur_edit_account.acct_name,
            DM_MAX_ID_STR / 2);
    }

    {
        U8 temp_str[DM_MAX_ID_STR];
        
        mmi_ucs2_to_asc((S8*)temp_str, (S8*)ptr_dmui_context->dmui_cur_edit_account.acct_name);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]data account name = %s \n", temp_str);
    }
	
    /* start to display data account caption and select screen */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CS_DATA_ACCOUNT]), 
        (U8*)GetString(STR_GLOBAL_DATA_ACCOUNT));
	
    SetInlineItemActivation(
        &wgui_inline_items[MMI_DMUI_CS_DATA_ACCOUNT_EDITOR], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);

    SetInlineItemDisplayOnly(
        &wgui_inline_items[MMI_DMUI_CS_DATA_ACCOUNT_EDITOR], 
        (U8*)ptr_dmui_context->dmui_cur_edit_account.acct_name);
    /* end to display data account caption and select screen */
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

    /* start to display Use Proxy caption and select item */
    /* display Use Proxy or not */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CS_USE_PROXY]), 
        (U8*)GetString(STR_ID_DMUI_CS_USE_PROXY)); 
    
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_CS_USE_PROXY_EDITOR]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemSelect(
        &(wgui_inline_items[MMI_DMUI_CS_USE_PROXY_EDITOR]),
        (S32)2,
        (U8 **)ptr_dmui_context->mmi_dmui_cs_use_proxy,
        (S32*)&ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_used);
    /* end to display auth type caption and select edit item */

    /* start to display Proxy IP caption and select item */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CS_IP]), 
        (U8*)GetString(STR_ID_DMUI_CS_IP)); 

    SetInlineItemActivation(&(wgui_inline_items[MMI_DMUI_CS_IP_EDITOR]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

	SetInlineItemIP4(
        &(wgui_inline_items[MMI_DMUI_CS_IP_EDITOR]),
        (U8*)ptr_dmui_context->dmui_info_cs_ip[0],
        (U8*)ptr_dmui_context->dmui_info_cs_ip[1],
        (U8*)ptr_dmui_context->dmui_info_cs_ip[2],
        (U8*)ptr_dmui_context->dmui_info_cs_ip[3],
        mmi_dmui_info_cs_ip_callback);
    /* end to display Proxy IP caption and select screen */

    /* display DMUI Proxy Port password string */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CS_PORT]), 
        (U8*)GetString(STR_ID_DMUI_CS_PORT));

    if (ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_port == -1)
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->proxy_port_str, (S8*)L"");
    }
    else
    {
        gui_itoa((U32)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_port, 
			(UI_string_type)ptr_dmui_context->proxy_port_str, 10);
    }

    {
        U8 temp_str[DM_MAX_ID_STR];

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)ptr_dmui_context->proxy_port_str);
        PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_port_str = %s \n", 
            temp_str);
    
        PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_port = %d \n", 
            ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_port);
    }


    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_CS_PORT_EDITOR]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0); 

    SetInlineItemTextEdit(
        &(wgui_inline_items[MMI_DMUI_CS_PORT_EDITOR]),
        (U8*)&ptr_dmui_context->proxy_port_str,
        DMUI_MAX_PROXY_PORT_LEN,
        /* DM_MAX_ID_STR + 1, */
        INPUT_TYPE_NUMERIC | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);    
    /* display DMUI Proxy Port password string */

    /* start to display proxy username caption and full edit screen */
    /* display DM Proxy username string */   
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CS_USERNAME]), 
        (U8*)GetString(STR_ID_DMUI_CS_PROXY_USERNAME));
    
    /* set inline edit for user name */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_CS_USERNAME_EDITOR]), 
        KEY_LSK, 
        KEY_EVENT_UP);
    
    {
        U8 temp_str[DM_MAX_ID_STR];

        mmi_ucs2_to_asc((S8*)temp_str, (S8*)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_user_name);

        PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_user_name = %s \n", 
            temp_str);
    }


    SetInlineItemFullScreenEdit(
        &(wgui_inline_items[MMI_DMUI_CS_USERNAME_EDITOR]),
        STR_ID_DMUI_CS_PROXY_USERNAME,
        (U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        (U8*)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_user_name,
        DM_MAX_PROXY_LEN/2,
        /* DM_MAX_URI_SIZE + 1, */
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    
    SetInlineFullScreenEditCustomFunction(
        &(wgui_inline_items[MMI_DMUI_CS_USERNAME_EDITOR]), 
        mmi_dmui_info_inlinecustom);
    /* end to display user name caption and full edit screen */
 
    /* start to display user password caption and inline edit screen */
    /* display DM user password string */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CS_PASSWORD]), 
        (U8*)GetString(STR_ID_DMUI_CS_PROXY_PASSWORD));
    
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_CS_PASSWORD_EDITOR]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0); 

    {
        U8 temp_str[DM_MAX_ID_STR];
        
        mmi_ucs2_to_asc((S8*)temp_str, (S8*)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_user_pw);
        
        PRINT_INFORMATION_2(TRACE_GROUP_7, "[DMUI][provisioning] proxy_user_name = %s \n", 
            temp_str);
    }

    SetInlineItemTextEdit(
        &(wgui_inline_items[MMI_DMUI_CS_PASSWORD_EDITOR]),
        (U8*)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_user_pw,
        DM_MAX_PROXY_LEN/2,
        /* DM_MAX_ID_STR + 1, */
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    /* end to display user password caption and inline edit screen */
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_ip_callback
* DESCRIPTION
*  call back function to conn setting ip input
* PARAMETERS
*  buffer       [OUT]   string buffer 
*  ip1          [IN]    first input of ip
*  ip2          [IN]    second input of ip
*  ip3          [IN]    third input of ip
*  ip4          [IN]    fourth input of ip
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_ip_callback(U8 *str_buffer, 
										 U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ipaddress[4];
    U8 localbuffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ipaddress[0] = (S32)gui_atoi((UI_string_type)ip1);
    ipaddress[1] = (S32)gui_atoi((UI_string_type)ip2);
    ipaddress[2] = (S32)gui_atoi((UI_string_type)ip3);
    ipaddress[3] = (S32)gui_atoi((UI_string_type)ip4);

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[0]);
    mmi_ucs2cpy((S8*)str_buffer, (S8*)localbuffer);
    mmi_ucs2cat((S8*)str_buffer, (S8*)L".");

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[1]);
    mmi_ucs2cat((S8*)str_buffer, (S8*)localbuffer);
    mmi_ucs2cat((S8*)str_buffer, (S8*)L".");

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[2]);
    mmi_ucs2cat((S8*)str_buffer, (S8*)localbuffer);
    mmi_ucs2cat((S8*)str_buffer, (S8*)L".");

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[3]);
    mmi_ucs2cat((S8*)str_buffer, (S8*)localbuffer);

	mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_conn_setting.proxy_addr, (S8*)str_buffer);
	
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_save_no
* DESCRIPTION
*  function to cancel save DM setting operation
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    DeleteUptoScrID(SCR_ID_DMUI_MAIN);
    GoBackHistory();

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_checkinput
* DESCRIPTION
*  function to check user input DM information
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_checkinput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dmui_temp_serverid[DM_MAX_ID_STR];
    U8 temp_server_addr[DM_MAX_URI_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_ucs2cpy((S8*)dmui_temp_serverid, (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);
    mmi_ucs2_to_asc((S8*)temp_server_addr, (S8*)ptr_dmui_context->dmui_cur_edit_account.server_addr);
    
    if (applib_url_is_valid((const char *)temp_server_addr) != 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DMUI_INFO_INVALID_SERVER_ADDRESS),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    /* server id is empty */
    if (mmi_ucs2strlen((S8*)dmui_temp_serverid) == 0)  
    {
        DisplayPopup(
            (PU8)GetString(STR_ID_DMUI_INFO_SERVERID_EMPTY),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);

        return;
    }
    else if (mmi_dmui_serverid_valid((S8*)dmui_temp_serverid) == MMI_FALSE)
    {
        DisplayPopup(
            (PU8)GetString(STR_ID_DMUI_INFO_SERVERID_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        
        return;
    }
    else    /* server id not empty */
    {
        U8 index = 0;

        /* before edit server id is empty */
        if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]) == 0)
        {
            for (index = 0; index < DMUI_MAX_SERVERID; index++)
            {
                /* if server id existed */
                if (mmi_ucs2cmp((S8*)dmui_temp_serverid, (S8*)ptr_dmui_context->dmui_serverid_array[index]) == 0)
                {
                    /* server id changed and duplicate */
                    if (index != ptr_dmui_context->dmui_hilite_serverid_index)
                    {
                        DisplayPopup(
                            (PU8)GetString(STR_ID_DMUI_INFO_SERVERID_EXIST),
                            IMG_GLOBAL_ERROR,
                            1,
                            UI_POPUP_NOTIFYDURATION_TIME,
                            ERROR_TONE);

                        return;
                    }
                }

            }   /* end for loop */

            /* not a duplicate server id */
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_GLOBAL_SAVE_ASK),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_dmui_info_save_confirm_serverid_nochanged, KEY_EVENT_UP);

            SetRightSoftkeyFunction(mmi_dmui_info_save_no, KEY_EVENT_UP);    

            return;
        }   /* end operation of before empty serverid case */

        for (index = 0; index < DMUI_MAX_SERVERID; index++)
        {
            /* if server id existed */
            if (mmi_ucs2cmp((S8*)dmui_temp_serverid, (S8*)ptr_dmui_context->dmui_serverid_array[index]) == 0)
            {
                /* server id changed and duplicate */
                if (index != ptr_dmui_context->dmui_hilite_serverid_index)
                {
                    DisplayPopup(
                        (PU8)GetString(STR_ID_DMUI_INFO_SERVERID_EXIST),
                        IMG_GLOBAL_ERROR,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        ERROR_TONE);

                    return;
                }
                else    /* server id not changed */
                {
                    /* only send add command to DM PS */
                    DisplayConfirm(
                        STR_GLOBAL_YES,
                        IMG_GLOBAL_YES,
                        STR_GLOBAL_NO,
                        IMG_GLOBAL_NO,
                        get_string(STR_GLOBAL_SAVE_ASK),
                        IMG_GLOBAL_QUESTION,
                        WARNING_TONE);

                    SetLeftSoftkeyFunction(mmi_dmui_info_save_confirm_serverid_nochanged, KEY_EVENT_UP);

                    SetRightSoftkeyFunction(mmi_dmui_info_save_no, KEY_EVENT_UP);    

                    return;
                }
            }

        }   /* end loop */

        /* entry save confirm screen when server id changed and unique */
        /* in the case need send : del & add command */
        /* if this item activated, need send set command with new server id */
        if (mmi_ucs2cmp((S8*)ptr_dmui_context->dmui_primary_serverid, 
                (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]) == 0
           )
        {
            /* if edit activated item and change server id */
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_GLOBAL_SAVE_ASK),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_dmui_info_save_confirm_serverid_activated_changed, KEY_EVENT_UP);

            SetRightSoftkeyFunction(mmi_dmui_info_save_no, KEY_EVENT_UP);   

        }
        else
        {
            /* if edit inactivated item and change server id */
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_GLOBAL_SAVE_ASK),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_dmui_info_save_confirm_serverid_inactivated_changed, KEY_EVENT_UP);

            SetRightSoftkeyFunction(mmi_dmui_info_save_no, KEY_EVENT_UP); 

        }

    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_save_confirm_serverid_nochanged
* DESCRIPTION
*  function to save DM info with server id not changed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_save_confirm_serverid_nochanged(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_add_account_struct *dmui_add_account = NULL;
    U8 temp_nodename[DM_MAX_ID_STR];
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dmui_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));
    
    memset(temp_nodename, 0x00, DM_MAX_ID_STR);

    gui_itoa((U32)ptr_dmui_context->dmui_hilite_serverid_index, (UI_string_type)temp_nodename, 10);

    mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*)temp_nodename);

    memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));
    
    /* set DMUI status */
    ptr_dmui_context->dmui_status = MMI_DMUI_ADD_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);

    mmi_dmui_waiting_entry();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_save_confirm_serverid_inactivated_changed
* DESCRIPTION
*  function to save DM info with server id changed but not duplicate and inactivated
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_save_confirm_serverid_inactivated_changed(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_server_id_struct *dmui_del_serverid = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dmui_del_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
    
    mmi_ucs2cpy((S8*)dmui_del_serverid->server_id,
        (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);

    ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);

    mmi_dmui_waiting_entry();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_save_confirm_serverid_activated_changed
* DESCRIPTION
*  function to save DM info with server id changed but not duplicate and activated
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_save_confirm_serverid_activated_changed(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_server_id_struct *dmui_del_serverid = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dmui_del_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
    
    mmi_ucs2cpy((S8*)dmui_del_serverid->server_id,
        (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);

    ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);

    mmi_dmui_waiting_entry();
}



/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_data_account_cb
* DESCRIPTION
*  call back function of data account select screen
* PARAMETERS
*  account_id       [IN]        return account id from data account
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_data_account_cb(U32 account_id)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_context->dmui_data_account_init = MMI_TRUE;
    ptr_dmui_context->dmui_cur_edit_conn_setting.data_account_id = account_id;
    DeleteUptoScrID(SCR_ID_DMUI_INFO_CS);
    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_data_account_entry
* DESCRIPTION
*  function to entry data account select screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_cs_data_account_entry(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_dmui_info_cs_data_account_cb, MENU_ID_DMUI_MAIN, DATA_ACCOUNT_BEARER_GPRS);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_main_data_account_check
* DESCRIPTION
*  call back function for data account init check 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_main_data_account_check(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    /* set data account flag to MMI_TRUE */
    ptr_dmui_context->dmui_data_account_init = MMI_TRUE;

    mmi_dmui_entry_option_edit();

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_fill_struct
* DESCRIPTION
*  function of fill struct of DM information
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_fill_struct(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_NONE] = (U8*)GetString(STR_ID_DMUI_AUTHTYPE_NONE);
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_BASIC] = (U8*)GetString(STR_ID_DMUI_AUTHTYPE_BASIC);
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_MD5] = (U8*)GetString(STR_ID_DMUI_AUTHTYPE_MD5);
    ptr_dmui_context->mmi_dmui_authtype[DM_AUTH_TYPE_HMAC] = (U8*)GetString(STR_ID_DMUI_AUTHTYPE_HMAC);

    if ((U32) ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id == (U32) (-1))
    {
        mmi_ucs2cpy((S8*) ptr_dmui_context->dmui_cur_edit_account.acct_name, (S8*) L"");
    }
    else
    {
        mmi_dtcnt_get_account_name(
            (U32) ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id,
            (S8*) ptr_dmui_context->dmui_cur_edit_account.acct_name,
            DM_MAX_ID_STR / 2);
    }

    /* start to display server id caption and full edit screen */
    /* display server id string caption */
    SetInlineItemCaption(&(wgui_inline_items[MMI_DMUI_SERVERID]), (U8*) GetString(STR_ID_DMUI_SERVERID));

    /* start to display server id caption and full edit screen */    
    /* display server id string caption*/
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_SERVERID]), 
        (U8*)GetString(STR_ID_DMUI_SERVERID));
    
    /* set inline edit of server id */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_SERVERID_EDITOR]), 
        KEY_LSK, 
        KEY_EVENT_UP);
    
    SetInlineItemFullScreenEdit(
        &(wgui_inline_items[MMI_DMUI_SERVERID_EDITOR]),
        STR_ID_DMUI_SERVERID,
        (U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        (U8*)ptr_dmui_context->dmui_cur_edit_account.server_id,
        /* DM_MAX_ID_STR + 1, */
        DM_MAX_ID_STR/2, 
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    
    SetInlineFullScreenEditCustomFunction(
        &(wgui_inline_items[MMI_DMUI_SERVERID_EDITOR]), 
        mmi_dmui_info_inlinecustom);
    /* end to display server id caption and full edit screen */

    /* start to display server password caption and inline edit screen */
    /* display server password string */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_SERVER_PASSWORD]), 
        (U8*)GetString(STR_ID_DMUI_SERVER_PASSWORD));
        
    /* set inline edit for server password */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_SERVER_PASSWORD_EDITOR]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);      
    
    SetInlineItemTextEdit(
        &(wgui_inline_items[MMI_DMUI_SERVER_PASSWORD_EDITOR]),
        (U8*)ptr_dmui_context->dmui_cur_edit_account.server_pw,
        DM_MAX_ID_STR/2,
        /* DM_MAX_ID_STR + 1, */
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    /* end to display server password caption and inline edit screen */

#ifndef __MMI_OP01_DM_PROFILE_SETTING__
    /* start to display data account caption and select screen */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_CONNECTION_SETTING]), 
        (U8*)GetString(STR_ID_DMUI_CONNECTION_SETTING));

    SetInlineItemActivation(
        &wgui_inline_items[MMI_DMUI_CONNECTION_SETTING_EDITOR], 
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
        0);

    SetInlineItemDisplayOnly(
        &wgui_inline_items[MMI_DMUI_CONNECTION_SETTING_EDITOR], 
        (U8*)ptr_dmui_context->dmui_cur_edit_account.acct_name);
    /* end to display data account caption and select screen */
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

    /* start to display server address caption and full edit screen */
    /* display server address string */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_SERVER_ADDRESS]), 
        (U8*)GetString(STR_ID_DMUI_SERVER_ADDRESS));
    
    /* set full edit for server address */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_SERVER_ADDRESS_EDITOR]),
        KEY_LSK,
        KEY_EVENT_UP);      
    
    /* set full screen edit for server address */
    SetInlineItemFullScreenEdit(
        &(wgui_inline_items[MMI_DMUI_SERVER_ADDRESS_EDITOR]),
        STR_ID_DMUI_SERVER_ADDRESS,
        (U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        (U8*)ptr_dmui_context->dmui_cur_edit_account.server_addr,
        DM_MAX_URI_SIZE/2,
        /* DM_MAX_URI_SIZE + 1, */
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    
    SetInlineFullScreenEditCustomFunction(
        &(wgui_inline_items[MMI_DMUI_SERVER_ADDRESS_EDITOR]), 
        mmi_dmui_info_inlinecustom);
    /* end to display server address caption and full edit screen */

    /* start to display user name caption and full edit screen */
    /* display DM username string */   
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_USERNAME]), 
        (U8*)GetString(STR_GLOBAL_USERNAME));
    
    /* set inline edit for user name */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_USERNAME_EDITOR]), 
        KEY_LSK, 
        KEY_EVENT_UP);
    
    SetInlineItemFullScreenEdit(
        &(wgui_inline_items[MMI_DMUI_USERNAME_EDITOR]),
        STR_GLOBAL_USERNAME,
        (U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        (U8*)ptr_dmui_context->dmui_cur_edit_account.user_name,
        DM_MAX_ID_STR/2,
        /* DM_MAX_URI_SIZE + 1, */
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    
    SetInlineFullScreenEditCustomFunction(
        &(wgui_inline_items[MMI_DMUI_USERNAME_EDITOR]), 
        mmi_dmui_info_inlinecustom);
    /* end to display user name caption and full edit screen */
 
    /* start to display user password caption and inline edit screen */
    /* display DM user password string */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_USER_PASSWORD]), 
        (U8*)GetString(STR_ID_DMUI_USER_PASSWORD));
    
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_USER_PASSWORD_EDITOR]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0); 

    SetInlineItemTextEdit(
        &(wgui_inline_items[MMI_DMUI_USER_PASSWORD_EDITOR]),
        (U8*)ptr_dmui_context->dmui_cur_edit_account.user_pw,
        DM_MAX_ID_STR/2,
        /* DM_MAX_ID_STR + 1, */
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    /* end to display user password caption and inline edit screen */

    /* start to display auth type caption and select edit item */
    /* display DM auth type */
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_DMUI_AUTHTYPE]), 
        (U8*)GetString(STR_ID_DMUI_AUTHTYPE)); 
    
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_DMUI_AUTHTYPE_EDITOR]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemSelect(
        &(wgui_inline_items[MMI_DMUI_AUTHTYPE_EDITOR]),
        (S32)DM_AUTH_TYPE_TOTAL,
        (U8 **)ptr_dmui_context->mmi_dmui_authtype,
        (S32*)&ptr_dmui_context->dmui_cur_edit_account.auth_pref);
    /* end to display auth type caption and select edit item */
 
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_inlinecustom
* DESCRIPTION
*  Full Line Edit Screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_info_inlinecustom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    
    SetInputMethodAndDoneCaptionIcon((U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN));
    
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_exit_option_edit
* DESCRIPTION
*  function of exit option edit item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_exit_option_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history his;
    U16 inputbuffersize;    /* added for inline edit history */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    his.scrnID = SCR_ID_DMUI_INFO;

    CloseCategory57Screen();
    
    his.entryFuncPtr = mmi_dmui_entry_option_edit;
    
    GetCategoryHistory(his.guiBuffer);
    
    /* added for inline edit history */
    inputbuffersize = (U16)GetCategory57DataSize();
    
    /* added for inline edit history */
    GetCategory57Data((U8*)his.inputBuffer);
    
    /* added for inline edit history */    
    AddNHistory(his, (U16)inputbuffersize);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_erase_confirm
* DESCRIPTION
*  function of confirm erase item or not
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_erase_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
    DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_erase_confirm_cancel
* DESCRIPTION
*  function of confirm erase item or not
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_erase_confirm_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
    DisplayIdleScreen();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_erase_confirm
* DESCRIPTION
*  function of confirm erase item or not
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_erase_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if server id is empty popup empty and return */
    if (mmi_ucs2cmp((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index], 
        (S8*)L"") == 0)
    {
        DisplayPopup(
            (PU8)GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        
        DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);

        return;
    }

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_DMUI_DELETE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_dmui_entry_option_erase_confirm_yes, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_dmui_entry_option_erase_confirm_no, KEY_EVENT_UP);

    SetKeyHandler(mmi_dmui_entry_option_erase_confirm_cancel, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_option_erase_confirm_yes
* DESCRIPTION
*  function of entry option erase item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_option_erase_confirm_yes(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_server_id_struct *dmui_del_serverid = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    {    
		dmui_del_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
    
		mmi_ucs2cpy((S8*)dmui_del_serverid->server_id,
					(S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);

		if (mmi_ucs2cmp((S8*)dmui_del_serverid->server_id, 
			(S8*)ptr_dmui_context->dmui_primary_serverid) == 0)
		{
			ptr_dmui_context->dmui_status = MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS;

			DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
		}
		else
		{
			ptr_dmui_context->dmui_status = MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS;
			
			DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
		}

        mmi_dmui_waiting_entry();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_highlight_op_activate
* DESCRIPTION
*  high light function for DMUI option activate
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_highlight_op_activate(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_dmui_entry_option_activate, KEY_EVENT_UP);
    SetKeyHandler(mmi_dmui_entry_option_activate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_highlight_op_edit
* DESCRIPTION
*  high light function for dmui option edit
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_highlight_op_edit(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_dmui_entry_option_edit_pre, KEY_EVENT_UP);
    SetKeyHandler(mmi_dmui_entry_option_edit_pre, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_highlight_op_erase
* DESCRIPTION
*  high light function for dmui option erase
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_highlight_op_erase(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_dmui_entry_option_erase_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_dmui_entry_option_erase_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/****************************************************************************************
*                       function to receive message from DM PS 
****************************************************************************************/
/*****************************************************************************
* FUNCTION
*  mmi_dmui_add_account_rsp
* DESCRIPTION
*  function to response of add account message
* PARAMETERS
*  msg      [IN]        message point from DM PS 
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_add_account_rsp_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_result_struct *dm_result = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dm_result = (dm_result_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_add_account_rsp_handle function");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]dm_result->result_code = %d \n", dm_result->result_code);
    
    if (dm_result->result_code == 0)
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_ADD_ACCOUNT_STATUS)   /* add acct direct */
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);

            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]added server id is %s ",
                                ptr_dmui_context->dmui_cur_edit_account.server_id);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index],
                    (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS");

            DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
            DeleteScreenIfPresent(SCR_ID_DMUI_INFO);
            DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_ACTIVATED_ADD_ACCOUNT_STATUS) /* add active acct */
        {
            dm_server_id_struct *dmui_active_serverid = NULL;

            dmui_active_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
    
            mmi_ucs2cpy((S8*)dmui_active_serverid->server_id,
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);
    
            ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_SET_PSERVERID_STATUS;

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index],
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_INACTIVATED_ADD_ACCOUNT_STATUS) /* add inactive acct */
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index],
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
            DeleteScreenIfPresent(SCR_ID_DMUI_INFO);
            DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);
        }
#ifdef __MMI_SYNCML_DM_OTAP__
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_ADD_ACCOUNT_STATUS)
        {
            dm_server_id_struct *dmui_active_serverid = NULL;

            dmui_active_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));

            mmi_ucs2cpy((S8*)dmui_active_serverid->server_id,
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);
            
            /* add server id to server id array */
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[g_syncml_dm_ota_context->edit_serverid_index],
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            g_syncml_dm_ota_context->num_installed++;
            
            ptr_dmui_context->dmui_status = MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
            
        }
        /* add a provisioning server id to DM to replace an activated server id */
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_ACTIVATED_ADD_ACCOUNT_STATUS)
        {
            /* do activate empty server id to DM PS */
            dm_server_id_struct *ptr_dm_ota_active_serverid = NULL;
            
            ptr_dm_ota_active_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
            
            /* add server id to server id array */
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[g_syncml_dm_ota_context->edit_serverid_index],
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            g_syncml_dm_ota_context->num_installed++;

            mmi_ucs2cpy((S8*)ptr_dm_ota_active_serverid->server_id, 
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);
            
            ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, ptr_dm_ota_active_serverid);

        }
        /* add a provisioning server id to DM to replace an inactivated server id */
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_INACTIVATED_ADD_ACCOUNT_STATUS)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[g_syncml_dm_ota_context->edit_serverid_index],
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);
            
            g_syncml_dm_ota_context->num_installed++;
            
            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
            
            mmi_syncml_dm_next_profile();
        }
#endif  /* __MMI_SYNCML_DM_OTAP__ */        
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_INIT_ADD_ACCOUNT_STATUS)
        {
            U8 dm_init_flag = 1;
            S16 error;

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[DM_DEFAULT_PROFILE_INDEX],
                (S8*)ptr_dmui_context->dmui_cur_edit_account.server_id);
            
            memset(&ptr_dmui_context->dmui_cur_edit_account, 0x00, sizeof(dm_account_struct));
            
            WriteValue(NVRAM_DM_OTA_PROFILE_INIT, &dm_init_flag, DS_BYTE, &error); 
            
            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS; 

        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]---------ADD DM ACCOUNT ERROR!!------");
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]DMUI status = %d ", ptr_dmui_context->dmui_status);

        mmi_dm_print_info(&ptr_dmui_context->dmui_cur_edit_account);

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
        DeleteScreenIfPresent(SCR_ID_DMUI_INFO);
        DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_del_account_rsp_handle
* DESCRIPTION
*  function to response of del account message
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_del_account_rsp_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_result_struct *dm_result = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dm_result = (dm_result_struct *)msg;
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_del_account_rsp_handle function");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]dm_result->result_code = %d \n", dm_result->result_code);
    
    if (dm_result->result_code == 0)
    {
		if (ptr_dmui_context->dmui_status == MMI_DMUI_ERASE_ACTIVATED_ACCOUNT_STATUS) /* for erase active server id */
		{
			/* do activate empty server id to DM PS */
			dm_server_id_struct *dmui_active_serverid = NULL;
			
            dmui_active_serverid = (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));
			
            mmi_ucs2cpy((S8*)dmui_active_serverid->server_id, (S8*)L"");
			
            ptr_dmui_context->dmui_status = MMI_DMUI_ERASE_SET_PSERVERID_STATUS;
			
			mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index],
                (S8*)L"");
			
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_SET_PSERVERID_REQ, dmui_active_serverid);
		}
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_ERASE_INACTIVATED_ACCOUNT_STATUS)  /* for erase operation */
        {
            DisplayPopup(
                (PU8)GetString(STR_SETTING_DELETED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
        
            DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
            DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            /* clear this server ID in server ID array */
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index],
                             (S8*)L"");
            
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_ACTIVATED_DEL_ACCOUNT_STATUS)  /* for edit operation */
        {
            U8 temp_nodename[DM_MAX_ID_STR];

            dm_add_account_struct *dmui_add_account = NULL;
    
            dmui_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));
    
            memset(temp_nodename, 0x00, DM_MAX_ID_STR);
            
            gui_itoa((U32)ptr_dmui_context->dmui_hilite_serverid_index, (UI_string_type)temp_nodename, 10);
    
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*)temp_nodename);

            memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_ACTIVATED_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);            
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_INACTIVATED_DEL_ACCOUNT_STATUS)  /* for edit operation */
        {
            U8 temp_nodename[DM_MAX_ID_STR];

            dm_add_account_struct *dmui_add_account = NULL;
    
            dmui_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));
    
            memset(temp_nodename, 0x00, DM_MAX_ID_STR);

            gui_itoa((U32)ptr_dmui_context->dmui_hilite_serverid_index, (UI_string_type)temp_nodename, 10);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*)temp_nodename);

            memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DMUI_EDIT_INACTIVATED_ADD_ACCOUNT_STATUS;

            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);            
        }
#ifdef __MMI_SYNCML_DM_OTAP__
        /* Replace activated server id */
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_ACTIVATED_DEL_ACCOUNT_STATUS)
        {
            U8 temp_nodename[DM_MAX_ID_STR];
            dm_add_account_struct *ptr_dm_ota_add_account = NULL;
            
            ptr_dm_ota_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));

            memset(temp_nodename, 0x00, DM_MAX_ID_STR);
            
            gui_itoa((U32)g_syncml_dm_ota_context->edit_serverid_index, (UI_string_type)temp_nodename, 10);
            
            mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].node_name, 
                (S8*)temp_nodename);

            /* set value to DM message struct */
            mmi_syncml_dm_set_value(&ptr_dm_ota_add_account->dm_account, 
                &g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);

            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_ADD_ACCOUNT_STATUS;
            
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, ptr_dm_ota_add_account);  

        }
        /* replace inactivated server id */
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_INACTIVATED_DEL_ACCOUNT_STATUS)
        {
            U8 temp_nodename[DM_MAX_ID_STR];

            dm_add_account_struct *ptr_dm_ota_add_account = NULL;
            
            ptr_dm_ota_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));

            memset(temp_nodename, 0x00, DM_MAX_ID_STR);
            
            gui_itoa((U32)g_syncml_dm_ota_context->edit_serverid_index, (UI_string_type)temp_nodename, 10);

            mmi_ucs2cpy((S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].node_name, 
                (S8*)temp_nodename);

            /* set value to DM message struct */
            mmi_syncml_dm_set_value(&ptr_dm_ota_add_account->dm_account, 
                &g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);
            
            /* set DMUI status */
            ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_INACTIVATED_ADD_ACCOUNT_STATUS;
            
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, ptr_dm_ota_add_account);
        }
#endif  /* __MMI_SYNCML_DM_OTAP__ */
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]---------DEL DM SERVERID ERROR!!------");
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]DMUI status = %d ", ptr_dmui_context->dmui_status);

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
        DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_get_account_rsp_handle
* DESCRIPTION
*  function to response of get account information
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_get_account_rsp_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_get_dmaccount_rsp_struct *dmui_get_account = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dmui_get_account = (dm_get_dmaccount_rsp_struct *)msg;
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_get_account_rsp_handle function");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]dmui_get_account->result_code = %d \n", 
        dmui_get_account->result_code);
    
    if (dmui_get_account->result_code == 1)   /* get server id list failed */
    {
        /* If failure; then display failure popup for user notification */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]---------GET DM ACCOUNT ERROR!!------");
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]DMUI status = %d ", ptr_dmui_context->dmui_status);
        mmi_dm_unfinish_check_info();

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
    }
    /* if server id not empty get account id in DM server id list */
    else if (ptr_dmui_context->dmui_status == MMI_DMUI_GET_ACCOUNT_STATUS)
    {
        memcpy(&ptr_dmui_context->dmui_cur_edit_account, &dmui_get_account->dm_account, sizeof(dm_account_struct));

        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]MMI_DMUI_GET_ACCOUNT_STATUS \n");

        mmi_dm_print_info(&dmui_get_account->dm_account);   

        /* data account information not init */
        if (ptr_dmui_context->dmui_data_account_init == MMI_FALSE)
        {
            /* init data account from NVRAM */
            DataAccountReadyCheck(mmi_dmui_main_data_account_check);
        }
        else
        {
            /* entry option edit screen */
            mmi_dmui_entry_option_edit();
        }
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_list_serverid_rsp_handle
* DESCRIPTION
*  function to receive response of list server id
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_list_serverid_rsp_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_list_server_id_rsp_struct *ptr_serverid_list = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_serverid_list = (dm_list_server_id_rsp_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_list_serverid_rsp_handle function");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]ptr_serverid_list->result_code = %d \n", 
        ptr_serverid_list->result_code);
    
    if (ptr_serverid_list->result_code == 1)   /* get server id list failed */
    {
        /* If failure; then display failure popup for user notification */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]---------LIST DM SERVERID ERROR!!------");
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]DMUI status = %d ", ptr_dmui_context->dmui_status);
        mmi_dm_unfinish_check_info();
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
    }
    else
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_LIST_SERVERID_STATUS)
        {
        mmi_dmui_save_serverid_list(ptr_serverid_list->server_id_list); 
            ptr_dmui_context->dmui_status = MMI_DMUI_GET_PSERVERID_STATUS;
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_PSERVERID_REQ, NULL);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_ONLY_INIT_SERVERID_STATUS)
        {
            mmi_dmui_save_serverid_list(ptr_serverid_list->server_id_list); 
            ptr_dmui_context->dmui_status = MMI_DMUI_ONLY_INIT_PSERVERID_STATUS;
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_PSERVERID_REQ, NULL);
        }
#ifdef __MMI_SYNCML_DM_OTAP__
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_LIST_SERVERID_STATUS)
        {
            mmi_dmui_save_serverid_list(ptr_serverid_list->server_id_list); 
            ptr_dmui_context->dmui_status = MMI_DM_OTA_GET_PSERVERID_STATUS;
            DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_PSERVERID_REQ, NULL);
        }
#endif /* __MMI_SYNCML_DM_OTAP__ */   
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_save_serverid_list
* DESCRIPTION
*  function to save server ID list from DM PS
* PARAMETERS
*  sour_str     [IN]        Server id list from DM PS
* RETURNS
*  void
*****************************************************************************/
void mmi_dmui_save_serverid_list(U8 * sour_str)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 i = 0;   /* partner index */
    U32 j = 0;   /* character position */
    U8 division_index = 0; /* division index */
    dmui_serverid_map_struct dmui_serverid_map[DMUI_MAX_SERVERID];
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    memset(ptr_dmui_context->dmui_serverid_array, 0x00, DMUI_MAX_SERVERID * DM_MAX_ID_STR);
    memset(dmui_serverid_map, 0x00, 2 * DMUI_MAX_SERVERID * DM_MAX_ID_STR);

    while (1)
    {
        /* end of string */
        if ((*sour_str == 0) && (*(sour_str + 1) == 0))
        {
            break;
        }

        if (division_index % 2) /* if division_index is odd, save server ID */
        {
            /* save server id */
            dmui_serverid_map[i].dmui_serverid[j] = *sour_str;
        }
        else    /* if division_index is even, save node name */
        {
            /* save node name */
            dmui_serverid_map[i].dmui_nodename[j] = *sour_str;
        }
        
        j++;
        sour_str += 1;
        
        /* find 01 string */
        if ( (*sour_str == 1) && (*(sour_str + 1) == 0) )
        {
            if (division_index % 2)
            {
                dmui_serverid_map[i].dmui_serverid[j] = 0;
                dmui_serverid_map[i].dmui_serverid[j + 1] = 0;

                i++;
            }
            else
            {
                dmui_serverid_map[i].dmui_nodename[j] = 0;
                dmui_serverid_map[i].dmui_nodename[j + 1] = 0;
            }
            sour_str += 2;
            division_index++;
            j = 0;
        }
    }
    
    i = 0;
    j = 0;

    /* save server id and node name to server id array */
    for (i = 0; i < DMUI_MAX_SERVERID; i++)
    {
        if (mmi_ucs2strlen((S8*)dmui_serverid_map[i].dmui_serverid) == 0)
            continue;

        {
            j = (U32)gui_atoi((UI_string_type)dmui_serverid_map[i].dmui_nodename);
            
            if (j < DMUI_MAX_SERVERID)
                mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[j], (S8*)dmui_serverid_map[i].dmui_serverid);
            else
            {
                U8 temp_nodename[DM_MAX_ID_STR];
                U8 temp_serverid[DM_MAX_ID_STR];
                
                memset(temp_nodename, 0x00, DM_MAX_ID_STR);
                memset(temp_serverid, 0x00, DM_MAX_ID_STR);
                
                mmi_ucs2_to_asc((S8*)temp_nodename, (S8*)dmui_serverid_map[i].dmui_nodename);
                mmi_ucs2_to_asc((S8*)temp_serverid, (S8*)dmui_serverid_map[i].dmui_serverid);
                
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]error nodename = %s \n", temp_nodename);
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]error serverid = %s \n", temp_nodename);

                /* delete error server id */
                {
                    dm_server_id_struct *dmui_del_serverid = NULL;

                    dmui_del_serverid = 
                        (dm_server_id_struct *)OslConstructDataPtr(sizeof(dm_server_id_struct));

                    mmi_ucs2cpy((S8*)dmui_del_serverid->server_id, (S8*)dmui_serverid_map[i].dmui_serverid);

                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, dmui_del_serverid);
                }
            }
        }

    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_get_pserverid_rsp_handle
* DESCRIPTION
*  function to receive primary server ID from DM PS
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_get_pserverid_rsp_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_get_pserver_id_rsp_struct *ptr_pserverid = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_pserverid = (dm_get_pserver_id_rsp_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_get_pserverid_rsp_handle function");

    if (ptr_dmui_context->dmui_status == MMI_DMUI_GET_PSERVERID_STATUS)
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, (S8*)ptr_pserverid->server_id);
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
        mmi_dmui_entry_main();
    }
    else if (ptr_dmui_context->dmui_status == MMI_DMUI_ONLY_INIT_PSERVERID_STATUS)
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, (S8*)ptr_pserverid->server_id);    
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;        
    }
#ifdef __MMI_SYNCML_DM_OTAP__
    else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_GET_PSERVERID_STATUS)
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, (S8*)ptr_pserverid->server_id); 
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
        mmi_syncml_dm_entry_installation();
    }
#endif /* __MMI_SYNCML_DM_OTAP__ */
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_set_pserverid_rsp_handle
* DESCRIPTION
*  function to response of set primary server id
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_set_pserverid_rsp_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_result_struct *add_result = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    add_result = (dm_result_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_set_pserverid_rsp_handle function");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]add_result->result_code = %d \n", add_result->result_code);
    
    if (add_result->result_code == 0)
    {
        if (ptr_dmui_context->dmui_status == MMI_DMUI_SET_PSERVERID_STATUS)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_ACTIVATED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, 
                             (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);
        
            DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
        }
        else if (ptr_dmui_context->dmui_status == MMI_DMUI_EDIT_SET_PSERVERID_STATUS)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, 
                       (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index]);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

            DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
            DeleteScreenIfPresent(SCR_ID_DMUI_INFO);
            DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);

        }
		else if (ptr_dmui_context->dmui_status == MMI_DMUI_ERASE_SET_PSERVERID_STATUS)
		{
            DisplayPopup(
                (PU8)GetString(STR_SETTING_DELETED),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
			
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, (S8*)L"");
			
            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
			
            DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
            DeleteScreenIfPresent(SCR_ID_DMUI_INFO);
            DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);
		}
#ifdef __MMI_SYNCML_DM_OTAP__
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_REPACE_ACTIVATED_SET_PSERVERID_STATUS)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            
            /* reset primary server id */
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, 
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);
            
            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
            
            mmi_syncml_dm_next_profile();
	}
        else if (ptr_dmui_context->dmui_status == MMI_DM_OTA_ACTIVE_ADD_ACCOUNT_STATUS)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);

            /* reset primary server id */
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_primary_serverid, 
                (S8*)g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id);

            ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;
            
            mmi_syncml_dm_next_profile();
	}
#endif
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]---------SET DM PSERVERID ERROR!!------");
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]DMUI status = %d ", ptr_dmui_context->dmui_status);
        mmi_dm_unfinish_check_info();
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        DeleteScreenIfPresent(SCR_ID_DMUI_OPTION);
        DeleteScreenIfPresent(SCR_ID_DMUI_INFO);
        DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_init_session_confirm_ok
* DESCRIPTION
*  function to response of init session
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_init_session_confirm_ok(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_ui_struct *ptr_dmui_init_session_res = NULL;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_init_session_res = (dm_ui_struct *)OslConstructDataPtr(sizeof(dm_ui_struct));

    ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DisplayPopup(
        (PU8)GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

    /* send ok message to DM PS */
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_init_session_confirm_no
* DESCRIPTION
*  function to response of init session and back to before screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_init_session_confirm_no(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_ui_struct *ptr_dmui_init_session_res = NULL;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_init_session_res = (dm_ui_struct *)OslConstructDataPtr(sizeof(dm_ui_struct));

    ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;

    /* send cancel message to DM PS */
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res); 
    
    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_init_session_ind_handle
* DESCRIPTION
*  function to receive init session indication
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_init_session_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_ui_mode_struct *ptr_dmui_init_session = NULL;
    dm_ui_struct *ptr_dmui_init_session_res = NULL;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_init_session = (dm_ui_mode_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_init_session_ind_handle function");

    switch(ptr_dmui_init_session->ui_mode)
    {
        case DM_UI_MODE_NOTSPECIFIED:
            {
                if (DM_UI_MODE_USERINTERACTION == dm_get_ui_mode_unspecifed())
                {
                    /*
                    if (mmi_dmui_interrupt_check() == MMI_FALSE)    / * if not display confirm screen * /
                        return;
                    */

                    /* but CMCC must display this screen */
                    DisplayConfirm(
                        STR_GLOBAL_YES,
                        0,
                        STR_GLOBAL_NO,
                        0,
                        get_string(STR_ID_DMUI_NOTIF_INIT_SESSION),
                        IMG_GLOBAL_QUESTION,
                        WARNING_TONE);

                    TurnOnBacklight(1);
                
                    SetLeftSoftkeyFunction(mmi_dmui_init_session_confirm_ok, KEY_EVENT_UP);

                    SetRightSoftkeyFunction(mmi_dmui_init_session_confirm_no, KEY_EVENT_UP);
                }
				else if (DM_UI_MODE_BACKGROUND == dm_get_ui_mode_unspecifed())
				{
					ptr_dmui_init_session_res = (dm_ui_struct *)OslConstructDataPtr(sizeof(dm_ui_struct));

					ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
					
					/* send message to DM PS */
					DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);	
				}
				else if (DM_UI_MODE_INFORMATION == dm_get_ui_mode_unspecifed())
				{
					ptr_dmui_init_session_res = (dm_ui_struct *)OslConstructDataPtr(sizeof(dm_ui_struct));

					DisplayPopup(
						(PU8)GetString(STR_ID_DMUI_NOTIF_INIT_SESSION),
						IMG_GLOBAL_ACTIVATED,
						1,
						UI_POPUP_NOTIFYDURATION_TIME,
						WARNING_TONE);

                    TurnOnBacklight(1);
					
					ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
					
					/* send message to DM PS */
					DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);
				}

            }
            break;

        case DM_UI_MODE_BACKGROUND:     /* not response to DM PS */
            {    
				ptr_dmui_init_session_res = (dm_ui_struct *)OslConstructDataPtr(sizeof(dm_ui_struct));
                ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

                /* send message to DM PS */
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);
            }
            break;

        case DM_UI_MODE_INFORMATION:    /* display pop up screen */
            {    
				ptr_dmui_init_session_res = (dm_ui_struct *)OslConstructDataPtr(sizeof(dm_ui_struct));

                DisplayPopup(
                    (PU8)GetString(STR_ID_DMUI_NOTIF_INIT_SESSION),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);

                TurnOnBacklight(1);

                ptr_dmui_init_session_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

                /* send message to DM PS */
                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES, ptr_dmui_init_session_res);
                
            }
            break;

        case DM_UI_MODE_USERINTERACTION:    /* display confirm screen */
            {
                /*
                if (mmi_dmui_interrupt_check() == MMI_FALSE)    / * if not display confirm screen * /
                    return;
                */
                /* but CMCC must display this screen */

                DisplayConfirm(
                    STR_GLOBAL_OK,
                    0,
                    STR_GLOBAL_BACK,
                    0,
                    get_string(STR_ID_DMUI_NOTIF_INIT_SESSION),
                    IMG_GLOBAL_QUESTION,
                    WARNING_TONE);

                TurnOnBacklight(1);
                
                SetLeftSoftkeyFunction(mmi_dmui_init_session_confirm_ok, KEY_EVENT_UP);

                SetRightSoftkeyFunction(mmi_dmui_init_session_confirm_no, KEY_EVENT_UP);
                
            }
            break;

        default:
            break;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_userpin_ind_handle
* DESCRIPTION
*  function to receive user pin indication
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_userpin_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_userpin_ind_handle function");
    if (mmi_dmui_interrupt_check() == MMI_TRUE) /* can display user pin screen */
    {
        if (GetActiveScreenId() == SCR_ID_DMUI_ENTER_PIN)   /* user pin screen actived */
            return;
        
        if (IsScreenPresent(SCR_ID_DMUI_ENTER_PIN))     /* user pin screen is in history */
        {
            DeleteScreenIfPresent(SCR_ID_DMUI_ENTER_PIN);
        }

        TurnOnBacklight(1);
            
        mmi_dmui_entry_user_pin_confirm();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_user_pin_confirm
* DESCRIPTION
*  function to entry user pin confirm screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_user_pin_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;  
    U8 *input_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_ENTER_PIN, mmi_dmui_exit_user_pin_confirm, NULL, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_ENTER_PIN);

    input_buffer = GetCurrInputBuffer(SCR_ID_DMUI_ENTER_PIN);

    if (input_buffer == NULL)
    {
        memset(ptr_dmui_context->pin_password, 0x00, (DMUI_MAX_PIN_LENGTH + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->pin_password, (S8*)input_buffer);
    }

    RegisterInputBoxValidationFunction(mmi_dmui_user_pin_change_lsk);

#if defined UI_SMALL_PIN_EDITOR_SCREEN
    enable_resized_small_screen();
#endif 

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_ID_DMUI_NOTIF_ENTER_PIN,
        INPUT_TYPE_NUMERIC_PASSWORD,
        ptr_dmui_context->pin_password,
        (DMUI_MAX_PIN_LENGTH + 1),
        NULL,
        gui_buffer);

    SetCategory111RightSoftkeyFunction(mmi_dmui_entry_user_pin_confirm_no, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_dmui_entry_user_pin_confirm_ok, KEY_EVENT_UP);

    SetKeyHandler(mmi_dmui_entry_user_pin_confirm_cancel, KEY_END, KEY_EVENT_DOWN);
    
    if (mmi_ucs2strlen((S8*)ptr_dmui_context->pin_password) < DMUI_MIN_PIN_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RstrSettingPasswdScrSoftKeyFunc
 * DESCRIPTION
 *  This function is to change softkey function in screen according to params
 * PARAMETERS
 *  text        [IN]        
 *  cursor      [IN]        
 *  length      [IN]        current input length
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dmui_user_pin_change_lsk(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the validity of the input password */
    if ((length) < DMUI_MIN_PIN_LENGTH)
    {
        /* if length is short then disable lsk */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(mmi_dmui_entry_user_pin_confirm_ok, KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_exit_user_pin_confirm
* DESCRIPTION
*  function to exit user pin confirm screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_exit_user_pin_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr;    /* * Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr.scrnID = SCR_ID_DMUI_ENTER_PIN;
    scr.entryFuncPtr = mmi_dmui_entry_user_pin_confirm;
    mmi_ucs2cpy((S8*)scr.inputBuffer, (S8*)ptr_dmui_context->pin_password);
    GetCategoryHistory(scr.guiBuffer);
    AddHistory(scr);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_user_pin_confirm_no
* DESCRIPTION
*  function to enter pin screen right soft key response
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_user_pin_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_bootstrap_userpin_rsp_struct *dmui_user_pin = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_user_pin 
        = (dm_get_bootstrap_userpin_rsp_struct *)OslConstructDataPtr(sizeof(dm_get_bootstrap_userpin_rsp_struct));

    dmui_user_pin->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_BOOTSTRAP_USERPIN_RES, dmui_user_pin);

    DeleteScreenIfPresent(SCR_ID_DMUI_ENTER_PIN);

    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_user_pin_confirm_ok
* DESCRIPTION
*  function to enter pin code screen left soft key response
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_user_pin_confirm_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_bootstrap_userpin_rsp_struct *dmui_user_pin = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_user_pin 
        = (dm_get_bootstrap_userpin_rsp_struct *)OslConstructDataPtr(sizeof(dm_get_bootstrap_userpin_rsp_struct));

    mmi_ucs2cpy((S8*)dmui_user_pin->user_pin, (S8*)ptr_dmui_context->pin_password);

    dmui_user_pin->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_GET_BOOTSTRAP_USERPIN_RES, dmui_user_pin);

    DeleteScreenIfPresent(SCR_ID_DMUI_ENTER_PIN);

    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_user_pin_confirm_cancel
* DESCRIPTION
*  function to cancel user pin input confirm
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_user_pin_confirm_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DMUI_ENTER_PIN);

    DisplayIdleScreen();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_ind_handle
* DESCRIPTION
*  function to receive download indication
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_ind_handle(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_ind_struct *dmui_dl_ind = NULL;
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_dl_ind = (dm_dl_ind_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_download_ind_handle function");
    
    ptr_dmui_context->dmui_dd_rsp_file_path = dmui_dl_ind->file_path_ptr;

    switch(dmui_dl_ind->ui_mode)
    {
        case DM_UI_MODE_NOTSPECIFIED:
            {
                if (DM_UI_MODE_USERINTERACTION ==  dm_get_ui_mode_unspecifed())
                {
                    /* can't display download indication screen or this screen is actived */
                    if ((mmi_dmui_interrupt_check() == MMI_FALSE) || (GetActiveScreenId() == SCR_ID_DMUI_DOWNLOAD))
                        return;

                    /* download screen is in history */
                    if (IsScreenPresent(SCR_ID_DMUI_DOWNLOAD))
                    {
                        DeleteScreenIfPresent(SCR_ID_DMUI_DOWNLOAD);
                    }

                    TurnOnBacklight(1);

                    mmi_dmui_read_info_from_file(dmui_dl_ind->file_path_ptr);
                    mmi_dmui_entry_download_confirm();
                }
                else if (DM_UI_MODE_INFORMATION == dm_get_ui_mode_unspecifed())
                {
					ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
					ptr_dmui_dl_res->file_path_ptr = dmui_dl_ind->file_path_ptr;

                    DisplayPopup(
                        (PU8)GetString(STR_ID_DMUI_NOTIF_DOWNLOAD_REQUEST),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE); 

                    TurnOnBacklight(1);

                    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res);                    
                }
				else if (DM_UI_MODE_BACKGROUND == dm_get_ui_mode_unspecifed())
				{
					ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
					ptr_dmui_dl_res->file_path_ptr = dmui_dl_ind->file_path_ptr;

					ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
					
					DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res);
				}

            }
            break;

        case DM_UI_MODE_BACKGROUND:     /* not response to DM PS */
            {	
				ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
				ptr_dmui_dl_res->file_path_ptr = dmui_dl_ind->file_path_ptr;

                ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res);
            }
            break;

        case DM_UI_MODE_INFORMATION:    /* display pop up screen */
            {	
				ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
				ptr_dmui_dl_res->file_path_ptr = dmui_dl_ind->file_path_ptr;

                DisplayPopup(
                    (PU8)GetString(STR_ID_DMUI_NOTIF_DOWNLOAD_REQUEST),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);

                TurnOnBacklight(1);

                ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res);                  
            }
            break;

        case DM_UI_MODE_USERINTERACTION:    /* display confirm screen */
            {
                /* can't display download indication screen or this screen is actived */
                if ((mmi_dmui_interrupt_check() == MMI_FALSE) || (GetActiveScreenId() == SCR_ID_DMUI_DOWNLOAD))
                    return;

                /* download screen is in history */
                if (IsScreenPresent(SCR_ID_DMUI_DOWNLOAD))
                {
                    DeleteScreenIfPresent(SCR_ID_DMUI_DOWNLOAD);
                }

                TurnOnBacklight(1);

                mmi_dmui_read_info_from_file(dmui_dl_ind->file_path_ptr);
                mmi_dmui_entry_download_confirm();                
            }
            break;

        default:
            break;
    }

}



/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_confirm_no_hdlr
* DESCRIPTION
*  function to RSK of download confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));

    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_REJECT;
    ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res); 
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_confirm_yes_hdlr
* DESCRIPTION
*  function to LSK of download confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
    
    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
    ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res); 
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_confirm_cancel_hdlr
* DESCRIPTION
*  function to cancel download request
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_confirm_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
    
    ClearInputEventHandler(MMI_DEVICE_ALL);

    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;
    ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DL_RES, ptr_dmui_dl_res); 

    DeleteScreenIfPresent(SCR_ID_DMUI_DOWNLOAD);

    DisplayIdleScreen();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_download_confirm
* DESCRIPTION
*  function to entry download confirm screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_download_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_DOWNLOAD, NULL, mmi_dmui_entry_download_confirm, NULL);

    mmi_dmui_oma_fill_info(SCR_ID_DMUI_DOWNLOAD,(S8*)subMenuData);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_DOWNLOAD);

    ShowCategory74Screen(STR_ID_DMUI_NOTIF_DOWNLOAD_CAPTION,
                         GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                         STR_GLOBAL_YES, IMG_GLOBAL_YES,
                         STR_GLOBAL_NO, IMG_GLOBAL_NO,
                         (PU8)subMenuData,
                         mmi_ucs2strlen((S8*)subMenuData),
                         NULL);

    SetKeyHandler(mmi_dmui_download_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_dmui_download_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dmui_download_confirm_no_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_oma_fill_info
* DESCRIPTION
*  function to fill display string of download or update screen
* PARAMETERS
*  scrid        [IN]        flag of current screen id 
*  out          [OUT]       output string  
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_oma_fill_info(U16 scrid, S8 *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[512];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (scrid == SCR_ID_DMUI_DOWNLOAD)
    {
        FILL_DMUI_INFO(buffer + 0, GetString(STR_ID_DMUI_NOTIF_DOWNLOAD_TITLE), "\n", "%s %s\n");
        FILL_DMUI_INFO(buffer + strlen(buffer), GetString(STR_ID_DMUI_NOTIF_DOWNLOAD_INFO), "", "%s %s\n");
    }
    else
    {
        FILL_DMUI_INFO(buffer + 0, GetString(STR_ID_DMUI_NOTIF_UPDATE_TITLE), "\n", "%s %s\n");
        FILL_DMUI_INFO(buffer + strlen(buffer), GetString(STR_ID_DMUI_NOTIF_UPDATE_INFO), "", "%s %s\n");
    }

    FILL_DMUI_INFO(buffer + strlen(buffer), 
                    GetString(STR_ID_DMUI_NOTIF_NAME), 
                    ptr_dmui_context->dmui_display_info.name, 
                    "%s %s \n");

    FILL_DMUI_INFO(buffer + strlen(buffer), 
                    GetString(STR_ID_DMUI_NOTIF_TYPE),
                    ptr_dmui_context->dmui_display_info.type,
                    "%s %s \n");

    FILL_DMUI_INFO(buffer + strlen(buffer),
                    GetString(STR_ID_DMUI_NOTIF_SIZE),
                    (U32)ptr_dmui_context->dmui_display_info.size,
                    "%s %d \n");

    FILL_DMUI_INFO(buffer + strlen(buffer),
                    GetString(STR_ID_DMUI_NOTIF_DESCRIPTION),
                    ptr_dmui_context->dmui_display_info.description,
                    "%s \n%s\n");

    if (scrid != SCR_ID_DMUI_DOWNLOAD)
    {
        FILL_DMUI_INFO(buffer + strlen(buffer), GetString(STR_ID_DMUI_NOTIF_UPDATE_REBOOT), "", "%s %s \n");
    }

    mmi_ucs2cpy((S8*)out, (S8*)buffer);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_update_confirm
* DESCRIPTION
*  function to entry update confirm screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_update_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_UPDATE, NULL, mmi_dmui_entry_update_confirm, NULL);

    mmi_dmui_oma_fill_info(SCR_ID_DMUI_UPDATE,(S8*)subMenuData);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_UPDATE);

    ShowCategory74Screen(STR_ID_DMUI_NOTIF_UPDATE_CAPTION,
                         GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                         STR_GLOBAL_YES, IMG_GLOBAL_YES,
                         STR_ID_DMUI_NOTIF_UPDATE_DEFER, 0,
                         (PU8)subMenuData,
                         mmi_ucs2strlen((S8*)subMenuData),
                         NULL);

    SetKeyHandler(mmi_dmui_update_confirm_cancel_hdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_dmui_update_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dmui_update_confirm_defer_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_update_confirm_defer_hdlr
* DESCRIPTION
*  function to defer select in update confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_update_confirm_defer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));

    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_DEFER;
	ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res); 
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_update_confirm_yes_hdlr
* DESCRIPTION
*  function to 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_update_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
    
    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
	ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res); 
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_update_confirm_cancel_hdlr
* DESCRIPTION
*  function to End Kay response of update confirm screen  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_update_confirm_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));
    
    ClearInputEventHandler(MMI_DEVICE_ALL);

    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;
	ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res); 

    DeleteScreenIfPresent(SCR_ID_DMUI_UPDATE);

    DisplayIdleScreen();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_update_ind_handle
* DESCRIPTION
*  function to receive update indication
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_update_ind_handle(void *msg)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_ind_struct *dmui_dl_ind = NULL;
    dm_dd_rsp_struct *ptr_dmui_dl_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_dl_ind = (dm_dl_ind_struct *)msg;
	ptr_dmui_context->dmui_dd_rsp_file_path = dmui_dl_ind->file_path_ptr;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_update_ind_handle function");

    switch(dmui_dl_ind->ui_mode)
    {
        case DM_UI_MODE_NOTSPECIFIED:
            {
                if (DM_UI_MODE_USERINTERACTION == dm_get_ui_mode_unspecifed())
                {
                    /* if can't display update screen or this screen is actived */
                    if ((mmi_dmui_interrupt_check() == MMI_FALSE) || (GetActiveScreenId() == SCR_ID_DMUI_UPDATE))
                        return;
                    
                    /* if update screen is in history */
                    if (IsScreenPresent(SCR_ID_DMUI_UPDATE))
                    {
                        DeleteScreenIfPresent(SCR_ID_DMUI_UPDATE);
                    }

                    mmi_dmui_read_info_from_file(dmui_dl_ind->file_path_ptr);
                    mmi_dmui_entry_update_confirm();
                }
                else if (DM_UI_MODE_INFORMATION == dm_get_ui_mode_unspecifed())
                {
					ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));

                    DisplayPopup(
                        (PU8)GetString(STR_ID_DMUI_NOTIF_UPDATE_REQUEST),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);      

                    ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
					ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

                    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);                    
                }
				else if (DM_UI_MODE_BACKGROUND == dm_get_ui_mode_unspecifed())
				{
					ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));

					ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
					ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;
					
					DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);
				}

            }
            break;

        case DM_UI_MODE_BACKGROUND:     /* not response to DM PS */
            {
				ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));

                ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
				ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res);
            }
            break;

        case DM_UI_MODE_INFORMATION:    /* display pop up screen */
            {
				ptr_dmui_dl_res = (dm_dd_rsp_struct *)OslConstructDataPtr(sizeof(dm_dd_rsp_struct));

                DisplayPopup(
                    (PU8)GetString(STR_ID_DMUI_NOTIF_UPDATE_REQUEST),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);

                ptr_dmui_dl_res->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
				ptr_dmui_dl_res->file_path_ptr = ptr_dmui_context->dmui_dd_rsp_file_path;

                DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_UPDATE_RES, ptr_dmui_dl_res); 
            }
            break;

        case DM_UI_MODE_USERINTERACTION:    /* display confirm screen */
            {
                /* if can't display update screen or this screen is actived */
                if ((mmi_dmui_interrupt_check() == MMI_FALSE) || (GetActiveScreenId() == SCR_ID_DMUI_UPDATE))
                    return;
                
                /* if update screen is in history */
                if (IsScreenPresent(SCR_ID_DMUI_UPDATE))
                {
                    DeleteScreenIfPresent(SCR_ID_DMUI_UPDATE);
                }

                mmi_dmui_read_info_from_file(dmui_dl_ind->file_path_ptr);
                mmi_dmui_entry_update_confirm();                
            }
            break;

        default:
            break;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_interrupt_check
* DESCRIPTION
*  function to check screen interrupt 
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE         Can't display DM UI screen now
*  MMI_FALSE        Can display DM UI screen now
*****************************************************************************/
static MMI_BOOL mmi_dmui_interrupt_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() ||                                       /* During Call */
        GetActiveScreenId() == SCR_RESTORE_PROCESSING ||    /* During Restore Factory */
        GetActiveScreenId() == POPUP_SCREENID ||
        GetActiveScreenId() == SCR_ID_VOBJ_RECV_OBJECT ||
        gSecuritySetupContext.PINBlocked ||                 /* PUK needed after SIM lock failed or change PIN1 failed */
        mmi_shutdown_is_in_power_off_period())
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_popup_check
* DESCRIPTION
*  function to check screen interrupt 
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE     Can display popup screen now
*  MMI_FALSE    Can't display popup screen now
*****************************************************************************/
static MMI_BOOL mmi_dmui_popup_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() || AlmIsTonePlaying())
        return MMI_FALSE;
    else
        return MMI_TRUE;
        
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_ind_handle
* DESCRIPTION
*  function to receive alert message from DM PS
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U32 dmui_alert_option_mask;
    MMI_BOOL   is_readfile = MMI_FALSE;
    dm_alert_struct *ptr_dmui_alert = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_alert = (dm_alert_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_alert_ind_handle function");

    /* get current interrupt status */
    if (ptr_dmui_alert->alert_type == DM_UI_INTERACTION_DISPLAY)    /* only a display alert */
    {
        if (mmi_dmui_popup_check() == MMI_FALSE)     /* Is alarm & call screen */
            return;
    }
    else
    {
        /* if can't display alert screen or alert screen is activated */
        if ((mmi_dmui_interrupt_check() == MMI_FALSE) || 
            (GetActiveScreenId() == ptr_dmui_context->dmui_alert_scr_id))
            return;

        /* if alert screen is in history del it and new one */
        if (IsScreenPresent(ptr_dmui_context->dmui_alert_scr_id))
        {
            DeleteScreenIfPresent(ptr_dmui_context->dmui_alert_scr_id);
        }
    }

    memset(&ptr_dmui_context->dmui_alert_struct, 0x00, sizeof(dm_alert_struct));

    ptr_dmui_context->dmui_alert_struct.alert_type = ptr_dmui_alert->alert_type;    /* ALERT TYPE */
    ptr_dmui_context->dmui_alert_struct.option_mask = ptr_dmui_alert->option_mask;  /* OPTION MASK */

    ptr_dmui_context->dmui_alert_struct.alert_string = (U8*)ptr_dmui_context->dmui_alert_string;
    
    dmui_alert_option_mask = ptr_dmui_context->dmui_alert_struct.option_mask;
    
    if (ptr_dmui_alert->b_filename)     /* DM PS send string with file */
    {
        FS_HANDLE fd;  
        U32 size;

        fd = FS_Open((U16*)ptr_dmui_alert->alert_string, FS_READ_ONLY);

        is_readfile = MMI_TRUE;

        if (fd >= 0)
        {
            FS_Read(fd, ptr_dmui_context->dmui_alert_string, sizeof(ptr_dmui_alert->buffer_len), &size);
            FS_Close(fd);
        }

    }
    else
    {
        mmi_ucs2ncpy((S8*)ptr_dmui_context->dmui_alert_string,
                         (S8*)ptr_dmui_alert->alert_string, 
                         ptr_dmui_alert->buffer_len > DMUI_INPUT_BUFFER_SIZE ? 
                         DMUI_INPUT_BUFFER_SIZE : ptr_dmui_alert->buffer_len);     /* ALERT STRING */
    }

    free_ctrl_buffer(ptr_dmui_alert->alert_string);

    if (dmui_alert_option_mask)
    {
        if (dmui_alert_option_mask >= DM_ALERT_ET_MASK)  /* ET */
        {
            ptr_dmui_context->dmui_alert_struct.et = ptr_dmui_alert->et;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_ET_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_IT_MASK) /* IT */
        {
            ptr_dmui_context->dmui_alert_struct.it = ptr_dmui_alert->it;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_IT_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_MAXLEN_MASK)    /* MAX LEN */
        {
            ptr_dmui_context->dmui_alert_struct.max_len = ptr_dmui_alert->max_len;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_MAXLEN_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_DR_MASK)    /* DEFAULT */
        {
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_alert_struct.dr, (S8*)ptr_dmui_alert->dr);
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_DR_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_MAXDT_MASK) /* MAX DT */
        {
            ptr_dmui_context->dmui_alert_struct.max_dt = ptr_dmui_alert->max_dt;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_MAXDT_MASK;
        }

        if (dmui_alert_option_mask >= DM_ALERT_MINDT_MASK) /* MIN DT */
        {
            ptr_dmui_context->dmui_alert_struct.min_dt = ptr_dmui_alert->min_dt;
            dmui_alert_option_mask = dmui_alert_option_mask - DM_ALERT_MAXLEN_MASK;
        }
    }

    TurnOnBacklight(1);

    switch(ptr_dmui_alert->alert_type)
    {
    case DM_UI_INTERACTION_DISPLAY:
        {
            ptr_dmui_context->dmui_alert_scr_id = 0;
            mmi_dmui_entry_alert_display();
        }
        break;

    case DM_UI_INTERACTION_CONFIRM:
        {
            ptr_dmui_context->dmui_alert_scr_id = 0;
            mmi_dmui_entry_alert_confirm();
        }
        break;

    case DM_UI_INTERACTION_INPUT:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_ALERT_INPUT;
            mmi_dmui_entry_alert_input();
        }
        break;

    case DM_UI_INTERACTION_SINGLE_CHOICE:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_ALERT_SINGLE_CHOICE;
            mmi_dmui_entry_alert_single_choice();
        }
        break;

    case DM_UI_INTERACTION_MULTI_CHOICE:
        {
            ptr_dmui_context->dmui_alert_scr_id = SCR_ID_DMUI_ALERT_MULTI_CHOICE;
            mmi_dmui_entry_alert_multi_choice();
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_display
* DESCRIPTION
*  function to entry alert display screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_display(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    DisplayPopup(
        (PU8)(ptr_dmui_context->dmui_alert_string),
        IMG_GLOBAL_ACTIVATED,
        1,
        ptr_dmui_context->dmui_alert_struct.min_dt,
        WARNING_TONE);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_confirm
* DESCRIPTION
*  function to entry alert confirm screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_confirm(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_OK,
        IMG_GLOBAL_YES,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_NO,
        (UI_string_type)(ptr_dmui_context->dmui_alert_string),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_dmui_entry_alert_confirm_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_dmui_alert_confirm_cancel, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_dmui_alert_confirm_no, KEY_EVENT_UP); 

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_confirm_ok
* DESCRIPTION
*  function to accept alert confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_confirm_ok(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dmui_alert_rsp = (dm_alert_rsp_struct *)OslConstructDataPtr(sizeof(dm_alert_rsp_struct));

    dmui_alert_rsp->alert_type = DM_UI_INTERACTION_CONFIRM;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    DeleteScreenIfPresent(ptr_dmui_context->dmui_alert_scr_id);

    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_input
* DESCRIPTION
*  function to entry alert input screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_input(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 *input_buffer;
    U8 *gui_buffer;
    U16 input_buffer_size;
    U16 icon_list[2] = {0,0};
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_ALERT_INPUT, mmi_dmui_exit_alert_input, NULL, NULL);
    
    InitializeCategory57Screen();

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_ALERT_INPUT);
    
    input_buffer = GetCurrNInputBuffer(SCR_ID_DMUI_ALERT_INPUT, &input_buffer_size);

    mmi_dmui_alert_input_fill_item();

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2, input_buffer);
    }
    
    ShowCategory57Screen(
        STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_CANCEL,
        0,
        2,
        icon_list,
        wgui_inline_items,
        0,
        gui_buffer);

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_input_fill_item
* DESCRIPTION
*  function to fill item with different params
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_input_fill_item(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    SetInlineItemCaption(
        &(wgui_inline_items[0]), 
        (U8*)(ptr_dmui_context->dmui_alert_string));

    if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_alert_struct.dr) != 0)
    {
        mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_alert_input_text, 
                         (S8*)ptr_dmui_context->dmui_alert_struct.dr);
    }

    switch(ptr_dmui_context->dmui_alert_struct.it)
    {
    case DM_INPUT_EDIT_TYPE_ALPHA:
        {
            SetInlineItemActivation(&(wgui_inline_items[1]), KEY_LSK, KEY_EVENT_UP);  

            if (ptr_dmui_context->dmui_alert_struct.et == DM_ECHO_TYPE_TEXT)
            {
                SetInlineItemFullScreenEdit(
                    &(wgui_inline_items[1]),
                    STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
                    (U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                    (U8*)ptr_dmui_context->dmui_alert_input_text,
                    (ptr_dmui_context->dmui_alert_struct.max_len - 1),
                    INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);    
            }
            else    /* DM_ECHO_TYPE_PW */
            {
                SetInlineItemFullScreenEdit(
                    &(wgui_inline_items[1]),
                    STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
                    (U16)GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                    (U8*)ptr_dmui_context->dmui_alert_input_text,
                    (ptr_dmui_context->dmui_alert_struct.max_len - 1),
                    INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES); 
            }

            SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[1]), mmi_dmui_info_inlinecustom);

            ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
            SetCategory57RightSoftkeyFunctions(mmi_dmui_alert_input_confirm, GoBackHistory);

        }
        break;

    case DM_INPUT_EDIT_TYPE_NUMBER:
        {
            SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

            if (ptr_dmui_context->dmui_alert_struct.et == DM_ECHO_TYPE_TEXT)
            {
                SetInlineItemTextEdit(
                    &(wgui_inline_items[1]),
                    (U8*)ptr_dmui_context->dmui_alert_input_text,
                    (ptr_dmui_context->dmui_alert_struct.max_len - 1),
                    INPUT_TYPE_NUMERIC | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);  
            }
            else    /* DM_ECHO_TYPE_PW */
            {
                SetInlineItemTextEdit(
                    &(wgui_inline_items[1]),
                    (U8*)ptr_dmui_context->dmui_alert_input_text,
                    (ptr_dmui_context->dmui_alert_struct.max_len - 1),
                    INPUT_TYPE_NUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
            }

            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetCategory57LeftSoftkeyFunction(mmi_dmui_alert_input_confirm);
        }
        break;

    case DM_INPUT_EDIT_TYPE_DATE:
        {
            SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);      

            SetInlineItemDate(
                &(wgui_inline_items[1]),
                (U8*)ptr_dmui_context->dmui_alert_input_context.day,
                (U8*)ptr_dmui_context->dmui_alert_input_context.month,
                (U8*)ptr_dmui_context->dmui_alert_input_context.year,
                mmi_dmui_alert_input_date_callback);

            SetInlineItemFullWidth(&wgui_inline_items[1]);
            EnableInlineItemBoundary(&wgui_inline_items[1]);
            RightJustifyInlineItem(&wgui_inline_items[1]); 
            
            set_inline_date_boundary(2030, 2000, 12, 1);

            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetCategory57LeftSoftkeyFunction(mmi_dmui_alert_input_confirm);
        }
        break;

    case DM_INPUT_EDIT_TYPE_TIME:
        {
            SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);      

            SetInlineItemTime(
                &(wgui_inline_items[1]),
                (U8*)ptr_dmui_context->dmui_alert_input_context.hour,
                (U8*)ptr_dmui_context->dmui_alert_input_context.minute,
                NULL,
                mmi_dmui_alert_input_time_callback);

            SetInlineItemFullWidth(&(wgui_inline_items[1]));
            EnableInlineItemBoundary(&(wgui_inline_items[1]));
            RightJustifyInlineItem(&(wgui_inline_items[1]));

            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetCategory57LeftSoftkeyFunction(mmi_dmui_alert_input_confirm);
        }
        break;

    case DM_INPUT_EDIT_TYPE_PHONE:
        {
            SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

            SetInlineItemTextEdit(
                &(wgui_inline_items[1]),
                (PU8)ptr_dmui_context->dmui_alert_input_text,
                (ptr_dmui_context->dmui_alert_struct.max_len - 1),
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);

            DisableInlineItemHighlight(&(wgui_inline_items[1]));

            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetCategory57LeftSoftkeyFunction(mmi_dmui_alert_input_confirm);
        }
        break;

    case DM_INPUT_EDIT_TYPE_IP:
        {
            SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

            SetInlineItemIP4(
                &(wgui_inline_items[1]),
                (U8*)ptr_dmui_context->dmui_alert_input_context.ip_addr_str[0],
                (U8*)ptr_dmui_context->dmui_alert_input_context.ip_addr_str[1],
                (U8*)ptr_dmui_context->dmui_alert_input_context.ip_addr_str[2],
                (U8*)ptr_dmui_context->dmui_alert_input_context.ip_addr_str[3],
                mmi_dmui_alert_input_ip_callback);

            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetCategory57LeftSoftkeyFunction(mmi_dmui_alert_input_confirm);
        }
        break;

    default:
        break;
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_input_confirm
* DESCRIPTION
*  function to check alert input and pop up confirm  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_input_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),    
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_dmui_alert_input_confirm_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dmui_alert_confirm_no, KEY_EVENT_UP);
    SetKeyHandler(mmi_dmui_alert_confirm_cancel, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_input_confirm_yes
* DESCRIPTION
*  function to press yes alert input and send message to DM PS 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_input_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = (dm_alert_rsp_struct *)OslConstructDataPtr(sizeof(dm_alert_rsp_struct));

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    /* xjdan */
	dmui_alert_rsp->user_input_string = OslMalloc(DMUI_INPUT_BUFFER_SIZE);

    mmi_ucs2cpy((S8*)dmui_alert_rsp->user_input_string, (S8*)ptr_dmui_context->dmui_alert_input_text);

    dmui_alert_rsp->user_input_string_len = mmi_ucs2strlen((S8*)dmui_alert_rsp->user_input_string);

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    DeleteScreenIfPresent(ptr_dmui_context->dmui_alert_scr_id);

    ptr_dmui_context->dmui_alert_scr_id = 0;

    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_input_date_callback
* DESCRIPTION
*  call back function to alert input date
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_input_date_callback(U8* str_buffer, U8* day, U8* month, U8* year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)ptr_dmui_context->dmui_alert_input_context.year);
    mmi_ucs2cat((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)L"/");
    mmi_ucs2cat((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)ptr_dmui_context->dmui_alert_input_context.month);
    mmi_ucs2cat((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)L"/");
    mmi_ucs2cat((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)ptr_dmui_context->dmui_alert_input_context.day);

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_input_time_callback
* DESCRIPTION
*  call back function to alert input date
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_input_time_callback(U8* str_buffer, U8* hour, U8* minute, U8* am_pm_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)ptr_dmui_context->dmui_alert_input_context.hour);
    mmi_ucs2cat((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)L":");
    mmi_ucs2cat((S8*)(ptr_dmui_context->dmui_alert_input_text), (S8*)ptr_dmui_context->dmui_alert_input_context.minute);
}



/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_input_date_callback
* DESCRIPTION
*  call back function to alert input date
* PARAMETERS
*  buffer       [OUT]   string buffer 
*  ip1          [IN]    first input of ip
*  ip2          [IN]    second input of ip
*  ip3          [IN]    third input of ip
*  ip4          [IN]    fourth input of ip
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_input_ip_callback(U8 *str_buffer, 
											 U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ipaddress[4];
    U8 localbuffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ipaddress[0] = (S32)gui_atoi((UI_string_type)ip1);
    ipaddress[1] = (S32)gui_atoi((UI_string_type)ip2);
    ipaddress[2] = (S32)gui_atoi((UI_string_type)ip3);
    ipaddress[3] = (S32)gui_atoi((UI_string_type)ip4);

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[0]);
    mmi_ucs2cpy((S8*)(str_buffer), (S8*)localbuffer);
    mmi_ucs2cat((S8*)(str_buffer), (S8*)L".");

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[1]);
    mmi_ucs2cat((S8*)(str_buffer), (S8*)localbuffer);
    mmi_ucs2cat((S8*)(str_buffer), (S8*)L".");

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[2]);
    mmi_ucs2cat((S8*)(str_buffer), (S8*)localbuffer);
    mmi_ucs2cat((S8*)(str_buffer), (S8*)L".");

    mmi_dmui_return_three_digit_string(localbuffer, (U8)ipaddress[3]);
    mmi_ucs2cat((S8*)(str_buffer), (S8*)localbuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_return_three_digit_string
 * DESCRIPTION
 *  This Fun Convert the integer value to String with prefix zero.
 *  
 *  Works only for three digit integer.(0-256)
 * PARAMETERS
 *  string_val       [OUT]       Out put string value
 *  digit_val        [IN]        Input digit value
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dmui_return_three_digit_string(PU8 string_val, U8 digit_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 local_buffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (digit_val == 0)
    {
        mmi_asc_to_ucs2((S8*)string_val, (S8*)"000");
    }
    else if (digit_val < 10)
    {
        sprintf(local_buffer, "00%d", digit_val);
        mmi_asc_to_ucs2((S8*)string_val, (S8*)local_buffer);
    }
    else if (digit_val < 100)
    {
        sprintf(local_buffer, "0%d", digit_val);
        mmi_asc_to_ucs2((S8*)string_val, (S8*)local_buffer);
    }
    else
    {
        sprintf(local_buffer, "%d", digit_val);
        mmi_asc_to_ucs2((S8*)string_val, (S8*)local_buffer);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_exit_alert_input
* DESCRIPTION
*  function to exit alert input screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_exit_alert_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history his;
    U16 inputbuffersize;    /* added for inline edit history */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    his.scrnID = SCR_ID_DMUI_ALERT_INPUT;

    CloseCategory57Screen();
    
    his.entryFuncPtr = mmi_dmui_entry_alert_input;
    
    GetCategoryHistory(his.guiBuffer);
    
    /* added for inline edit history */
    inputbuffersize = (U16)GetCategory57DataSize();
    
    /* added for inline edit history */
    GetCategory57Data((U8*)his.inputBuffer);
    
    /* added for inline edit history */    
    AddNHistory(his, (U16)inputbuffersize);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_single_choice
* DESCRIPTION
*  function to entry alert single choice screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_single_choice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_ALERT_SINGLE_CHOICE, NULL, mmi_dmui_entry_alert_single_choice, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_ALERT_SINGLE_CHOICE);

    RegisterHighlightHandler(mmi_dmui_hilite_single_choice_handle); 

    mmi_dmui_alert_parse_string();

    mmi_dmui_alert_parse_status();

    ShowCategory84Screen(
        STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ptr_dmui_context->dmui_alert_choice_num,
        (U8**)subMenuDataPtrs,
        (PU16)gIndexIconsImageList,
        1,
        (S32)0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dmui_entry_alert_single_choice_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_single_choice_ok
* DESCRIPTION
*  function to press ok in alert single choice screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_single_choice_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = (dm_alert_rsp_struct *)OslConstructDataPtr(sizeof(dm_alert_rsp_struct));
    
    ptr_dmui_context->dmui_alert_choice_send[0] = ptr_dmui_context->dmui_hilite_index + '1';
    ptr_dmui_context->dmui_alert_choice_send[1] = 0;
    ptr_dmui_context->dmui_alert_choice_send[2] = 0;
    ptr_dmui_context->dmui_alert_choice_send[3] = 0;

	dmui_alert_rsp->user_input_string = (U8*)OslMalloc(DMUI_INPUT_BUFFER_SIZE);
    
	mmi_ucs2cpy((S8*)dmui_alert_rsp->user_input_string, (S8*)ptr_dmui_context->dmui_alert_choice_send);

    dmui_alert_rsp->user_input_string_len = mmi_ucs2strlen((S8*)dmui_alert_rsp->user_input_string);
    
    dmui_alert_rsp->b_filename = 0;

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    DeleteScreenIfPresent(ptr_dmui_context->dmui_alert_scr_id);

    ptr_dmui_context->dmui_alert_scr_id = 0;

    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_hilite_single_choice_handle
* DESCRIPTION
*  function to save high light index in alert single choice screen 
* PARAMETERS
*  hilited      [IN]        current high light item index
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_hilite_single_choice_handle(S32 hilited)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dmui_context->dmui_hilite_index = hilited;
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_multi_choice
* DESCRIPTION
*  function to entry alert multi choice screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_alert_multi_choice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_ALERT_MULTI_CHOICE, NULL, 
                    mmi_dmui_entry_alert_multi_choice, NULL);

    mmi_dmui_alert_parse_string();

    mmi_dmui_alert_parse_status();

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_ALERT_MULTI_CHOICE);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_dmui_alert_multi_choice_confirm, GoBackHistory);

    ShowCategory140Screen(
        STR_ID_DMUI_ALERT_DM_INFO_CAPTION,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        ptr_dmui_context->dmui_alert_choice_num,
        (U8**)subMenuDataPtrs,
        (U8*)ptr_dmui_context->dmui_alert_default_value,
        0,
        gui_buffer);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_alert_multi_choice
* DESCRIPTION
*  function to entry alert multi choice screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_parse_string(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 j = 0;
    U8 cmp_strlen = 7;
    U8 *alert_str_ptr = NULL;
    U8 alert_string[MAX_SUB_MENUS * MAX_SUB_MENU_SIZE];
    U8 temp_cmp_string[14];

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/  
    ptr_dmui_context->dmui_alert_choice_num = 0;

    mmi_ucs2cpy((S8*)alert_string, (S8*)ptr_dmui_context->dmui_alert_string);

    alert_str_ptr = alert_string;

    while (1)
    {
        /* end of parse string */
        if ((*alert_str_ptr == 0) && (*(alert_str_ptr + 1) == 0) && (alert_str_ptr != alert_string))
        {
            ptr_dmui_context->dmui_alert_choice_num++; 
            return;
        }

        mmi_ucs2ncpy((S8*)temp_cmp_string, (S8*)alert_str_ptr, cmp_strlen);

        if ( mmi_ucs2ncmp((S8*)DMUI_SPLIT_STRING, (S8*)temp_cmp_string, cmp_strlen) == 0 )
        {
            subMenuData[ptr_dmui_context->dmui_alert_choice_num][j] = 0;
            subMenuData[ptr_dmui_context->dmui_alert_choice_num][j+1] = 0;
            alert_str_ptr += 14;
            ptr_dmui_context->dmui_alert_choice_num++;
            j = 0;
        }
        else
        {
            subMenuData[ptr_dmui_context->dmui_alert_choice_num][j] = *alert_str_ptr;
            j++;
            alert_str_ptr++;
        }
    }   
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_parse_status
* DESCRIPTION
*  function to get default value from dr parameters 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_parse_status(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 index = 0;
    U8 cmp_strlen = 7;
    U8 *alert_str_ptr = NULL;
    U8 alert_string[MAX_SUB_MENUS * MAX_SUB_MENU_SIZE];
    U8 temp_cmp_string[14];
    U8 alert_dr[MAX_SUB_MENUS];

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/ 
    memset(ptr_dmui_context->dmui_alert_default_value, 0x00, MAX_SUB_MENUS);

    mmi_ucs2cpy((S8*)alert_string, (S8*)ptr_dmui_context->dmui_alert_struct.dr);

    alert_str_ptr = alert_string;

    while (1)
    {
        if ((*alert_str_ptr == 0) && (*(alert_str_ptr + 1) == 0))
        {
            alert_dr[index] = 0;
            alert_dr[index + 1] = 0;
            
            return ;
        }

        mmi_ucs2ncpy((S8*)temp_cmp_string, (S8*)alert_str_ptr, cmp_strlen);

        if ( mmi_ucs2ncmp((S8*)DMUI_SPLIT_STRING, (S8*)temp_cmp_string, cmp_strlen) == 0 )
        {
            alert_str_ptr += 14;
        }

        alert_dr[index] = *alert_str_ptr;

        if (alert_dr[index] != 0)
        {
            ptr_dmui_context->dmui_alert_default_value[alert_dr[index] - '1'] = 1;
        }

        index++;
        alert_str_ptr++;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_multi_choice_confirm
* DESCRIPTION
*  function to popup a confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_multi_choice_confirm(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_DMUI_ALERT_DM_INFO_CAPTION),    
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_dmui_alert_multi_choice_confirm_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dmui_alert_confirm_no, KEY_EVENT_UP);
    SetKeyHandler(mmi_dmui_alert_confirm_cancel, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_multi_choice_confirm_yes
* DESCRIPTION
*  function to response left key in confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_multi_choice_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 multi_send_index = 0;
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = (dm_alert_rsp_struct *)OslConstructDataPtr(sizeof(dm_alert_rsp_struct));

    while (count != ptr_dmui_context->dmui_alert_choice_num)
    {
        if (ptr_dmui_context->dmui_alert_default_value[count] == 1)
        {
            U8 count2;

            count2 = count + 1;

            ptr_dmui_context->dmui_alert_choice_send[multi_send_index] = (count + '1');
            ptr_dmui_context->dmui_alert_choice_send[multi_send_index + 1] = 0;
            multi_send_index = multi_send_index + 2;

            /* if existed another true flag in checkbox */
            while(count2 != ptr_dmui_context->dmui_alert_choice_num)
            {
                if (ptr_dmui_context->dmui_alert_default_value[count] == 1)
                {
                    mmi_ucs2cat((S8*)&ptr_dmui_context->dmui_alert_choice_send[multi_send_index], (S8*)DMUI_SPLIT_STRING);
                    multi_send_index = multi_send_index + 14;
                    break;
                }
                count2++;
            }

        }

        count++;
    }

    mmi_ucs2cpy((S8*)dmui_alert_rsp->user_input_string, (S8*)ptr_dmui_context->dmui_alert_choice_send);

    dmui_alert_rsp->user_input_string_len = mmi_ucs2strlen((S8*)dmui_alert_rsp->user_input_string);
    
    dmui_alert_rsp->b_filename = 0;

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    DeleteScreenIfPresent(SCR_ID_DMUI_ALERT_MULTI_CHOICE);

    ptr_dmui_context->dmui_alert_scr_id = 0;

    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_confirm_no
* DESCRIPTION
*  function to response right key in confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = (dm_alert_rsp_struct *)OslConstructDataPtr(sizeof(dm_alert_rsp_struct));

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    DeleteScreenIfPresent(ptr_dmui_context->dmui_alert_scr_id);

    ptr_dmui_context->dmui_alert_scr_id = 0;

    GoBackHistory();

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_alert_confirm_cancel
* DESCRIPTION
*  function to response end key in confirm screen 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_alert_confirm_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dmui_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dmui_alert_rsp = (dm_alert_rsp_struct *)OslConstructDataPtr(sizeof(dm_alert_rsp_struct));

    dmui_alert_rsp->alert_type = ptr_dmui_context->dmui_alert_struct.alert_type;

    dmui_alert_rsp->ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ALERT_RES, dmui_alert_rsp);

    ptr_dmui_context->dmui_alert_scr_id = 0;

    DisplayIdleScreen();

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_reset_ind_handle
* DESCRIPTION
*  function to receive handset reboot indication from DM PS
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_reset_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_reset_ind_handle function");
    TurnOnBacklight(1);
    mmi_dmui_entry_reset_progress();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_reset_progress
* DESCRIPTION
*  function to display reboot screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_reset_progress(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(0, 0);

    /* Call Exit Handler */
    EntryNewScreen(SCR_ID_DMUI_REBOOT, NULL, mmi_dmui_entry_reset_progress, NULL);

    ShowCategory66Screen(
        STR_ID_DMUI_NOTIF_REBOOT,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        0,
        0,
        0,
        0,
        (PU8)GetString(STR_ID_DMUI_NOTIF_REBOOT_PROGRESS),
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_progress_ind_handle
* DESCRIPTION
*  function to receive download progress and display download percents.
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_progress_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_dl_progress_struct *ptr_dmui_dlprogress = NULL;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_dlprogress = (dm_dl_progress_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_download_progress_ind_handle function");

    if (ptr_dmui_dlprogress->ui_mode == DM_UI_MODE_BACKGROUND)
        return;

    ptr_dmui_context->dmui_dl_percent = ptr_dmui_dlprogress->received_bytes * 100 / ptr_dmui_dlprogress->total_bytes;

    if (ptr_dmui_context->dmui_dl_percent == 100)
        TurnOnBacklight(1);
    
    mmi_dmui_display_download_progress((U32)ptr_dmui_context->dmui_dl_percent);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_entry_download_progress
* DESCRIPTION
*  function to entry download progress screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_entry_download_progress(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_DOWNLOAD_PROGRESS, NULL, mmi_dmui_entry_download_progress, NULL);

    ShowCategory402Screen((U8 *)GetString(STR_GLOBAL_DOWNLOADING), GetRootTitleIcon(MENU_ID_DMUI_MAIN),
                          0, 0, STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK, NULL, ptr_dmui_context->dmui_dl_percent, NULL);

    
    SetKeyHandler(mmi_dmui_download_progress_cancel, KEY_END, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_dmui_download_progress_no, KEY_EVENT_UP);
}



/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_progress_no
* DESCRIPTION
*  function to cancel download progress with right key
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_progress_no(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    dm_cancel_downloading();

    DisplayPopup((PU8)GetString(STR_ID_DMUI_USER_CANCELLED), 
        IMG_GLOBAL_ERROR, 
        1, 
        UI_POPUP_NOTIFYDURATION_TIME, 
        (U8)SUCCESS_TONE);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_display_download_progress
* DESCRIPTION
*  function to display download progress
* PARAMETERS
*  percentage       [IN]        percent of current progress
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_display_download_progress(U32 percentage)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_DMUI_DOWNLOAD_PROGRESS)   /* current screen is download progress */
    {
        if (percentage != ptr_dmui_context->dmui_dl_percent)
        {
            ptr_dmui_context->dmui_dl_percent = percentage;
            UpdateCategory402Value((U16)percentage, NULL);
        }
    }
    else if (!IsScreenPresent(SCR_ID_DMUI_DOWNLOAD_PROGRESS))   /* download progress not a scr in history */
    {
        ptr_dmui_context->dmui_dl_percent = percentage;
        mmi_dmui_entry_download_progress();
    }
    else    /* update percentage */
    {
        ptr_dmui_context->dmui_dl_percent = percentage;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_download_progress_cancel
* DESCRIPTION
*  function to back to idle screen when press end key in download progress
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_download_progress_cancel(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dm_cancel_downloading();

    DeleteScreenIfPresent(SCR_ID_DMUI_DOWNLOAD_PROGRESS);

    DisplayIdleScreen();
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_change_account_ind_handle
* DESCRIPTION
*  function to receive change account message from DM PS
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_change_account_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    dm_change_account_struct *dmui_change_account = NULL;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    dmui_change_account = (dm_change_account_struct *)msg;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_change_account_ind_handle function");

    switch (dmui_change_account->action_type)
    {
    case DM_ACTION_TYPE_ADD:
        {
            U8 i = 0;

            for (i = 0; i < DMUI_MAX_SERVERID; i++)
            {
                if (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[i]) == 0)
                {
                    mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[i],(S8*)dmui_change_account->server_id);
                    break;
                }
            }
        }
        break;

    case DM_ACTION_TYPE_UPDATE:
        break;

    case DM_ACTION_TYPE_DELETE:
        {
            U8 i = 0;

            for (i = 0; i < DMUI_MAX_SERVERID; i++)
            {
                if (mmi_ucs2cmp((S8*)ptr_dmui_context->dmui_serverid_array[i], 
                                     (S8*)dmui_change_account->server_id) == 0)
                {
                    mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_serverid_array[i],(S8*)L"");
                    break;
                }
            }
        }
        break;

    default:
        break;
    }


}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_exec_complete_ind_handle
* DESCRIPTION
*  function to receive exec complete message
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_exec_complete_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_exec_complete_ind_handle function");
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_session_start_ind_handle
* DESCRIPTION
*  function to receive session start message from DM PS
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_session_start_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_session_start_ind_handle");
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_session_finish_ind_handle
* DESCRIPTION
*  function to receive session finish message from DM PS
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_session_finish_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_session_finish_ind_handle");
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_error_ind_handle
* DESCRIPTION
*  function of exit DM UI main menu
* PARAMETERS
*  msg      [IN]        message point from DM PS
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_error_ind_handle(void *msg)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_error_ind_handle");
    
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_waiting_entry
* DESCRIPTION
*  function to add waiting screen when edit or erase DM information
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_waiting_entry(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DMUI_WAITING, NULL, NULL, NULL);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_DMUI_WAITING);
            
    DeleteScreenIfPresent(SCR_ID_DMUI_WAITING);

    ShowCategory66Screen(
        STR_ID_DMUI_MAIN,
        GetRootTitleIcon(MENU_ID_DMUI_MAIN),
        0,
        0,
        0,
        0,
        (U8*)GetString(STR_ID_DMUI_WAITING),
        IMG_GLOBAL_PROGRESS,
        gui_buffer);
            
    ClearAllKeyHandler();
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
	SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_serverid_valid
* DESCRIPTION
*  function to check server id valid or not
* PARAMETERS
*  p_serverid   [IN]
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_dmui_serverid_valid(S8 *p_serverid)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 *p = (U8*)p_serverid;
    U8 ansii_max_value = 127;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    MMI_ASSERT(p_serverid);
    
    while ((*p != 0) || (*(p + 1) != 0))
    {
        if(*p < ansii_max_value )
        {
            p++;
        }     
        else
        {
            return 0;
        }
    }
    
    return 1;
    
}

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/*****************************************************************************
* FUNCTION
*  mmi_dm_ota_init_profile
* DESCRIPTION
*  function to init default DM setting profile
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dm_ota_init_profile(void)
        {
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 dm_init_flag = 0;
    U8 temp_nodename[DM_MAX_ID_STR];
    S16 error;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ReadValue(NVRAM_DM_OTA_PROFILE_INIT, &dm_init_flag, DS_BYTE, &error);

    /* DM default setting not init */
    if ((dm_init_flag == (U8)0xFF) 
        || (mmi_ucs2strlen((S8*)ptr_dmui_context->dmui_serverid_array[DM_DEFAULT_PROFILE_INDEX]) == 0))
            {
        dm_add_account_struct *dmui_add_account = NULL;
        
        dmui_add_account = (dm_add_account_struct *)OslConstructDataPtr(sizeof(dm_add_account_struct));

        memset(temp_nodename, 0x00, DM_MAX_ID_STR);
        memset(&ptr_dmui_context->dmui_cur_edit_account, 0x00, sizeof(dm_account_struct));

        gui_itoa((U32)DM_DEFAULT_PROFILE_INDEX, (UI_string_type)temp_nodename, 10);
        
                {
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.server_id, 
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.server_pw,
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.server_addr,
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.user_name,
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.user_pw,
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW);

            ptr_dmui_context->dmui_cur_edit_account.auth_pref = DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE;

#ifdef CUSTOM_DEFAULT_DM_DTCNT_ID
            {
                ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = 
                    CUSTOM_DEFAULT_DM_DTCNT_ID;
            }
#elif defined(DM_CUSTOM_CFG_DEFAULT_PROFILE_ACCT_ID)
            {
                ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = 
                    DM_CUSTOM_CFG_DEFAULT_PROFILE_ACCT_ID;
            }
#else
            {
                ptr_dmui_context->dmui_cur_edit_account.conn_setting.data_account_id = -1;
            }
#endif

            ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_used = 
                (kal_bool)DM_CUSTOM_CFG_DEFAULT_PROFILE_USE_PROXY;

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_addr, 
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP);

            ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_port = DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT;

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_user_name,
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERNAME);

            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.conn_setting.proxy_user_pw,
                (S8*)DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERPW);
           
            mmi_ucs2cpy((S8*)ptr_dmui_context->dmui_cur_edit_account.node_name, (S8*)temp_nodename);
}

        memcpy(&dmui_add_account->dm_account, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

        /* set DMUI status */
        ptr_dmui_context->dmui_status = MMI_DM_OTA_INIT_ADD_ACCOUNT_STATUS;

        DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dmui_add_account);
    }
    else if (dm_init_flag == 1)
    {
        ptr_dmui_context->dmui_status = MMI_DMUI_ONLY_INIT_SERVERID_STATUS;
        
        DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_LIST_SERVERID_REQ, NULL);
    }

}
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

/*****************************************************************************
* FUNCTION
*  mmi_dmui_return_four_digit_ip
* DESCRIPTION
*  function to convert unicode string to 4 digit IP
* PARAMETERS
*  four_digit	 [OUT]
*  ip_ucs_string [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_dmui_return_four_digit_ip(U8 *four_digit, S8* ip_ucs_string)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
	S8 ip_ascii_string[16];
	UI_character_type ip_string[4][DMUI_MAX_IPADDRES_LENGTH * ENCODING_LENGTH];
	S8 index = 0;
	S8 i = 0;
	S8 j = 0;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dmui_return_four_digit_ip function \n");

	mmi_ucs2_to_asc((S8*)ip_ascii_string, (S8*)ip_ucs_string);
	
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]ip_ascii_string = %s \n", ip_ascii_string);
	
	for (index = 0; index < strlen(ip_ascii_string) + 1; index ++)
	{
		if(ip_ascii_string[index] == '.' || ip_ascii_string[index] == 0)
		{
			ip_string[i][j] = 0;
			j = 0;
			i++;
		}
		else
		{
			ip_string[i][j] = ip_ascii_string[index];
			j++;
		}
	}

	for (i = 0; i < 4; i++)
	{
        U8 tempint = 0;

        tempint = (U8)gui_atoi(ip_string[i]);

        mmi_dmui_return_three_digit_string((U8*)ptr_dmui_context->dmui_info_cs_ip[i], (U8)tempint);
	}

    memcpy(four_digit, ptr_dmui_context->dmui_info_cs_ip, sizeof(ptr_dmui_context->dmui_info_cs_ip));
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_read_info_from_file
* DESCRIPTION
*  function to read download or update information from file
* PARAMETERS
*  file_path        [IN]        path of received file
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_read_info_from_file(U16* file_path)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    FS_HANDLE fd;  
    U32 size;
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    fd = FS_Open(file_path, FS_READ_ONLY);

    if (fd >= 0)
    {
        FS_Read(fd, &(ptr_dmui_context->dmui_display_info), sizeof(dm_omadl_dd_struct), &size);
        FS_Close(fd);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_init_serverid
* DESCRIPTION
*  function to init server id list
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_dmui_init_serverid(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    ptr_dmui_context->dmui_status = MMI_DMUI_ONLY_INIT_SERVERID_STATUS;
    
    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_LIST_SERVERID_REQ, NULL);

}


/******************************************************************************
*                   external function for DM PS
******************************************************************************/
/*****************************************************************************
* FUNCTION
*  mmi_dm_account_is_editing
* DESCRIPTION
*  function for DM PS to get current edit server id
* PARAMETERS
*  server_id        [IN]        server id which will be change by server.
* RETURNS
*  0        no server id be edited now
*  1        this server id is editing
*****************************************************************************/
U8 mmi_dm_account_is_editing(U8* server_id)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    if (!(IsScreenPresent(SCR_ID_DMUI_INFO) || IsScreenPresent(SCR_ID_DMUI_INFO_CS)))
    {
        return 0;
    }
    else
    {
        if (mmi_ucs2cmp(
            (S8*)ptr_dmui_context->dmui_serverid_array[ptr_dmui_context->dmui_hilite_serverid_index],
            (S8*)server_id) == 0)
        {
            return 1;
        }
    }

    return 0;

}

void mmi_dm_unfinish_check_info(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 i = 0;
    U8 temp_prt[DM_MAX_URI_SIZE];
    
    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_unfinish_check_info function \n"); 
    
#ifdef __SYNCML_DM_TEST__
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_unfinish_check_info application info \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    
    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dmui_context->dmui_primary_serverid); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]primary serverid = %s \n", temp_prt);
    
    for(i = 0; i < DMUI_MAX_SERVERID; i++)
    {
        mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dmui_context->dmui_serverid_array[0]); 
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]server_id[%d] = %s \n", i, temp_prt);
    }
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]hilite_index = %d \n", ptr_dmui_context->dmui_hilite_index);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]hilite_serverid_index = %d \n", 
        ptr_dmui_context->dmui_hilite_serverid_index);
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_unfinish_check_info function \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");

    mmi_dmui_init_serverid();
    
#else
    return;
#endif /* __SYNCML_DM_TEST__ */
}


void mmi_dm_print_info(dm_account_struct * ptr_dm_account)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U8 temp_prt[DM_MAX_URI_SIZE];

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    MMI_ASSERT(ptr_dm_account);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_print_info function \n");

#ifdef __SYNCML_DM_TEST__
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_print_info application info \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");

    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->node_name); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]node_name = %s \n", temp_prt);

    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->server_id); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]server_id = %s \n", temp_prt);

    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->server_addr); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]server_addr = %s \n", temp_prt);

    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->server_pw); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]server_pw = %s \n", temp_prt);

    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->user_name); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]user_name = %s \n", temp_prt);

    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->user_pw); 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]user_pw = %s \n", temp_prt);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]auth_pref = %d \n", ptr_dm_account->auth_pref);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_print_info proxy info \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]data_account_id = %d \n", 
        ptr_dm_account->conn_setting.data_account_id);
    
    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->conn_setting.proxy_addr);    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]proxy_addr = %s \n", temp_prt);
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]proxy_port = %d \n", 
        ptr_dm_account->conn_setting.proxy_port);
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]proxy_used = %d \n", 
        ptr_dm_account->conn_setting.proxy_used);
    
    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->conn_setting.proxy_user_name);
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]proxu_user_name = %s \n", temp_prt);
    
    mmi_ucs2_to_asc((S8*)temp_prt, (S8*)ptr_dm_account->conn_setting.proxy_user_pw);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]proxu_user_pw = %s \n", temp_prt);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]mmi_dm_print_info function \n");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DMUI]================================== \n");

#else
    return;
#endif /* __SYNCML_DM_TEST__ */
}

bf_bool mmi_syncml_dm_check(void)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/
    U16 temp_screen = 0;

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    temp_screen = GetActiveScreenId();

    if (temp_screen > SCR_ID_DMUI_BASE && temp_screen < SCR_ID_DMUI_END) 
        return bf_false;

    for (temp_screen = SCR_ID_DMUI_MAIN; temp_screen < SCR_ID_DMUI_END; temp_screen++)
    {
        if (IsScreenPresent(temp_screen) == MMI_TRUE)
            return bf_false;
    }

    return bf_true;
    
}


/*****************************************************************************
 * FUNCTION
 *  dm_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 *  download_url(?)         [IN]        The source of file, normally is a link
 *  filename(?)             [IN]        The filepath of file
 *  action_type(?)          [IN]        Defined in Download agent
 * RETURNS
 *   void
 *****************************************************************************/
void dm_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#define TMP_BUFFER_SIZE     256
#define DM_PUSH_TEMP_FILE_NAME          L"Z:\\@dm\\dmpush.tmp"
    
    kal_uint8   *data_ptr = NULL;

    kal_int32   data_len = 0;

    kal_uint32  read_len = 0;
    
    FS_HANDLE fSrc, fDes;
    
    dm_push_struct *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_prompt_trace( MOD_DM, "[DM TASK] dm_receive_da_file");

    if(action != MMI_DA_PUSH)
    {
        kal_prompt_trace( MOD_DM, "[DM TASK] dm_receive_da_file from SIM2");

        FS_Delete(filepath);

        return;
    }

    fSrc = FS_Open(filepath, FS_READ_ONLY);
    
    kal_prompt_trace( MOD_DM, "[DM TASK] fSrc = %d",fSrc);

    if(fSrc < 0)
    {
        /* ASSERT(0); */
        
        return;
    }

    fDes = FS_Open(DM_PUSH_TEMP_FILE_NAME, FS_READ_WRITE | FS_CREATE_ALWAYS);
    
    if(fDes < 0)
    {
        FS_Close(fSrc);
     
        FS_Delete(filepath);

        return;
    }

    if( FS_NO_ERROR == FS_GetFileSize(fSrc, (kal_uint32*)&data_len))
    {
        kal_prompt_trace( MOD_DM, "[DM TASK] dm_receive_da_file data_len = %d",data_len);

        data_ptr = (kal_uint8*)get_ctrl_buffer(TMP_BUFFER_SIZE);

        data_ptr[0] = 0x01;
        data_ptr[1] = 0x06;
        data_ptr[2] = 0x03;
        data_ptr[3] = 0xC4;
        data_ptr[4] = 0xAF;
        data_ptr[5] = 0x87;

        if(FS_NO_ERROR == FS_Write(fDes, data_ptr, 6, NULL))
        {
            while(data_len > 0)
            {
                if(FS_NO_ERROR == FS_Read(fSrc, data_ptr, TMP_BUFFER_SIZE, &read_len))
                {
                    if(FS_NO_ERROR == FS_Write(fDes, data_ptr, read_len, NULL))
                        data_len -= read_len;
                    else
                        break;
                }
                else
                    break;                
            }
        }

        free_ctrl_buffer(data_ptr);
    }

    FS_Close(fSrc);

    FS_Close(fDes);
    
    FS_Delete(filepath);

    ptr = (dm_push_struct*)construct_local_para( sizeof(dm_push_struct), TD_RESET );
    
    mmi_ucs2cpy((S8*)(ptr->file_path), (const S8*)DM_PUSH_TEMP_FILE_NAME);

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_PUSH_IND, ptr);
}

#endif /* SYNCML_DM_SUPPORT */

/* End of dmuiapp.c */

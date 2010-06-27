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
 * DataAccount.c
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
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "DataAccountCommon.h"

#ifdef __MMI_WLAN_FEATURES__

extern U8 wgui_inline_list_menu_changed;
extern pBOOL IsBackHistory;

mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
mmi_wlan_display_struct g_wlan_display_context;
mmi_wlan_setting_struct g_wlan_setting_context;

U8 g_old_wep_key_str[MAX_WEP_KEYSTR_LEN *ENCODING_LENGTH];
S32 g_old_wep_key_len;
S32 g_old_wep_key_format;

/* for always ask */
U8 g_always_ask_connect_flag;
/* for always ask before connect flag */
U8 g_always_ask_before_connect_flag;
/* send cnf to soc after receive disconnect cnf */
U8 g_always_ask_send_cnf_flag;

void mmi_wlan_init(void);
void mmi_wlan_update_status_icon(U16 image_id, BOOL animate);

void mmi_wlan_entry_confirm(U16 msg, FuncPtr lskFuncPtr, FuncPtr rskFuncPtr);
void mmi_wlan_entry_scan_result(void);
void mmi_wlan_entry_processing(void);
void mmi_wlan_entry_abortable_processing(void);
void mmi_wlan_entry_find_network(void);
void mmi_wlan_network_clear_no(void);
void mmi_wlan_network_delete_yes(void);
void mmi_wlan_network_list_change_priority(void);
void mmi_wlan_entry_network_priority(void);
void mmi_wlan_pre_entry_network_edit(void);
void mmi_wlan_entry_network_add(void);
void mmi_wlan_entry_network_delete(void);
void mmi_wlan_ap_profile_overwrite_no(void);
void mmi_wlan_ap_profile_overwrite_yes(void);
void mmi_wlan_ap_profile_overwrite(void);
void mmi_wlan_ap_list_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_define_network(void);
void mmi_wlan_scan_result_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_scan_result_opt(void);
void mmi_wlan_entry_processing(void);
void mmi_wlan_action_abort(void);
void mmi_wlan_entry_network_disconnect(void);
void mmi_wlan_entry_find_network_connect(void);
void mmi_wlan_passphrase_input_opt_highlight_hdlr(int index);
void mmi_wlan_entry_passphrase_input_opt(void);
void mmi_wlan_entry_passphrase_input(void);
void mmi_wlan_pre_entry_find_network_connect(void);
void mmi_wlan_entry_network_connect(void);
void mmi_wlan_entry_power(void);
void mmi_wlan_action_abort_find_network(void);
void mmi_wlan_entry_network_details(void);
void mmi_wlan_pre_entry_find_network(void);
void mmi_wlan_entry_settings(void);
void mmi_wlan_wep_settings_save(void);
void mmi_wlan_wep_settings_fill_inline_struct(void);
void mmi_wlan_entry_wep_settings(void);
void mmi_wlan_exit_wep_settings(void);
void mmi_wlan_entry_wep_settings(void);
void mmi_wlan_wpa_passphrase_save(void);
void mmi_wlan_wpa_passphrase_opt_highlight_hdlr(int index);
void mmi_wlan_entry_wpa_passphrase_opt(void);
void mmi_wlan_entry_wpa_passphrase(void);
void mmi_wlan_auth_mode_ok(void);
void mmi_wlan_auth_mode_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_auth_mode(void);
void mmi_wlan_pre_entry_auth_mode(void);
void mmi_wlan_encrypt_mode_ok(void);
void mmi_wlan_encrypt_mode_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_encrypt_mode(void);
void mmi_wlan_network_edit_highlight_hdlr(S32 nIndex);
void mmi_wlan_network_edit_save_no(void);
void mmi_wlan_network_edit_save_yes(void);
void mmi_wlan_network_edit_save(void);
void mmi_wlan_network_edit_fill_inline_struct(void);
void mmi_wlan_exit_network_edit(void);
void mmi_wlan_entry_network_edit(void);
void mmi_wlan_entry_network_settings_opt(void);
void mmi_wlan_network_settings_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_network_settings(void);
void mmi_wlan_entry_conn_status(void);
void mmi_wlan_tcpip_settings_save(void);
void mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr(S32 index);
void mmi_wlan_tcpip_settings_fill_inline_struct(void);
void mmi_wlan_entry_tcpip_settings(void);
void mmi_wlan_exit_tcpip_settings(void);
void mmi_wlan_entry_tcpip_settings(void);
void mmi_wlan_pre_entry_tcpip_settings(void);
void mmi_wlan_highlight_main(void);
void mmi_wlan_highlight_power(void);
void mmi_wlan_highlight_conn_status(void);
void mmi_wlan_highlight_settings(void);
void mmi_wlan_highlight_tcpip_settings(void);
void mmi_wlan_highlight_ap_settings(void);
void mmi_wlan_highlight_network_edit(void);
void mmi_wlan_highlight_find_network_connect(void);
void mmi_wlan_highlight_network_details(void);
void mmi_wlan_highlight_find_network(void);
void mmi_wlan_highlight_define_network(void);
void mmi_wlan_highlight_network_connect(void);
void mmi_wlan_highlight_network_priority(void);
void mmi_wlan_highlight_network_delete(void);
void mmi_wlan_hint_power(U16 index);
void mmi_wlan_init_highlight_hdlr(void);
void mmi_wlan_change_priority_handler(S32 index);
void mmi_wlan_delete_space_string(S8 *Src, S8 *Des);

/* fro always ask */
void mmi_wlan_network_settings_highlight_hdlr_ext(S32 nIndex);
void mmi_wlan_entry_network_search(void);
void mmi_wlan_entry_network_ap_connnect(void);
void mmi_wlan_entry_always_ask_connnect(void);
void mmi_wlan_soc_deactivate_ind_handler(void *info);

mmi_wlan_profile_struct *g_always_ask_conn_profile_p;
extern U8 g_always_ask_screen_del_handler_flag;

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_return_to_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}

void mmi_wlan_init_profile(mmi_wlan_profile_struct *profile)
{
    memset(profile, 0, sizeof(mmi_wlan_profile_struct));
    profile->network_type = WLAN_NETWORK_TYPE_INFRA;
    profile->auth_mode = WLAN_AUTH_MODE_OPEN;
    profile->encrypt_mode = WLAN_ENCRYPT_MODE_NONE;
    profile->auth_type1 = WLAN_EAP_TLS;
#ifdef WLAN_EAP_PEAP_SUPPORT
    profile->eap_peap_auth_type = WLAN_EAP_SIM;
#endif
#ifdef WLAN_EAP_TTLS_SUPPORT
    profile->eap_ttls_auth_type = WLAN_EAP_SIM;
#endif
    profile->wep_key_len = WLAN_WEP_KEY_ENCRYPT_64;
    profile->wep_key_format = WLAN_WEP_KEY_FORMAT_HEX;
    profile->peap_version = SUPC_PHASE1_PEAP_0 | SUPC_PHASE1_PEAP_1;
    profile->use_dhcp = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_post_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_post_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef AUTO_POWER_ON
    if (g_wlan_setting_context.start_on_bootup == TRUE && mmi_bootup_get_active_flight_mode() == 0 && mmi_netset_get_active_preferred_mode() != 0)
    {
        if (g_wlan_display_context.prof_num > 0)
        {
            mmi_wlan_send_connect_req(NULL);
        }
        else
        {
            mmi_wlan_send_init_req();
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i = 0;
    U8 ImageLocation = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error);

    /*
     * memcpy(g_wlan_display_context.ip_addr, g_wlan_setting_context.ip_addr, 4);
     * memcpy(g_wlan_display_context.netmask, g_wlan_setting_context.netmask, 4);
     * memcpy(g_wlan_display_context.gateway, g_wlan_setting_context.gateway, 4);
     * memcpy(g_wlan_display_context.dns1, g_wlan_setting_context.dns1, 4);
     * memcpy(g_wlan_display_context.dns2, g_wlan_setting_context.dns2, 4);
     */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        ReadRecord(NVRAM_EF_WLAN_PROFILE_LID, (U8) (i + 1), &g_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, &error);
        if (g_wlan_prof_list[i].priority > 0)
        {
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
            g_wlan_display_context.prof_num++;
            if(g_wlan_prof_list[i].network_type == WLAN_NETWORK_TYPE_INFRA)
            {
                g_wlan_display_context.infra_prof_num++;
            }
            else
            {
                g_wlan_display_context.adhoc_prof_num++;
            }
        }
    }

    for (i = g_wlan_display_context.prof_num; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        g_wlan_profile[i] = NULL;
    }

    for (i = 0; i < MAX_INLINE_ITEM_DATA_ACCOUNT_LIST; i++)
    {
        if (i % 2)
        {
            g_wlan_display_context.icon_list[i] = IMG_ID_DTCNT_LSK_EDIT;        /* No image */
        }
        else
        {
            g_wlan_display_context.icon_list[i] = gIndexIconsImageList[ImageLocation];
            ImageLocation++;
        }
    }

    SetProtocolEventHandler(mmi_wlan_abm_wifi_activate_req_ind_hdlr, MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_IND);
    SetProtocolEventHandler(mmi_wlan_abm_wifi_deactivate_req_ind_hdlr, MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_IND);

    for(i = 0; i < MAX_WLAN_EVENT_REGISTRAR_NUM; i++)
    {
        g_wlan_display_context.event_callback[i] = NULL;
    }
    g_wlan_display_context.app_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_id        [IN]        
 *  animate         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_status_icon(U16 image_id, BOOL animate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_id == 0)
    {
        HideStatusIcon(STATUS_ICON_WLAN_SIGNAL);
        UpdateStatusIcons();
        g_wlan_display_context.status_icon = 0;
        return;
    }
    ShowStatusIcon(STATUS_ICON_WLAN_SIGNAL);
    ChangeStatusIconImage(STATUS_ICON_WLAN_SIGNAL, image_id);
    if (animate == TRUE)
    {
        AnimateStatusIcon(STATUS_ICON_WLAN_SIGNAL);
    }
    UpdateStatusIcons();
    g_wlan_display_context.prev_status_icon = g_wlan_display_context.status_icon;
    g_wlan_display_context.status_icon = image_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_find_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ssid            [?]         
 *  ssid_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_wlan_profile_struct *mmi_wlan_find_profile(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(profile_id == 0) /* temp profile */
        return NULL;
    
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if (g_wlan_profile[i]->profile_id == profile_id)
        {
            return g_wlan_profile[i];
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_confirm
 * DESCRIPTION
 *  Common function to display confirmation screem
 * PARAMETERS
 *  msg             [IN]        String index of message to be displayed in confirmation screen
 *  lskFuncPtr      [IN]        LSK handler of the confirmation screen
 *  rskFuncPtr      [IN]        RSK handler of the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_confirm(U16 msg, FuncPtr lskFuncPtr, FuncPtr rskFuncPtr)
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
        (UI_string_type) GetString(msg),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(lskFuncPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(rskFuncPtr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_main
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#ifdef __MTK_TARGET__
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
//#endif /* __MTK_TARGET__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // U8*                  hints[MAX_SUB_MENUS];   /* sms counters for display hint popups */

//#ifndef __MTK_TARGET__
//    DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR), IMG_GLOBAL_ACTIVATED, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
//   return;
//#else /* __MTK_TARGET__ */

    g_always_ask_connect_flag = FALSE;
    
    EntryNewScreen(SCR_ID_DTCNT_WLAN_MAIN, NULL, mmi_wlan_entry_main, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_MAIN);

    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_WLAN_MAIN);

    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_WLAN_MAIN, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_ID_WLAN_MAIN);
    if (g_wlan_display_context.prev_state == WLAN_STATE_NULL && 
       ((g_wlan_display_context.state == WLAN_STATE_NULL) ||
        (g_wlan_display_context.state == WLAN_STATE_DISCONNECT_WAIT) || 
        (g_wlan_display_context.state == WLAN_STATE_DEINIT_WAIT) || 
        (g_wlan_display_context.scan_state == WLAN_SCAN_STATE_ABORTING)))
    {
        nStrItemList[0] = STR_ID_DTCNT_WLAN_POWER_ON;

    }
    else
    {
        nStrItemList[0] = STR_ID_DTCNT_WLAN_POWER_OFF;
    }
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* construct hint popups for the menu items */
    /* ConstructHintsList(MENU_ID_WLAN_MAIN, hints); */
    /* Display Category52 Screen */
    ShowCategory52Screen(
        SERVICES_DATA_CONNECT_WLAN_STRING_ID,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
//#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_clear_no
 * DESCRIPTION
 *  Give up saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_clear_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_delete_yes
 * DESCRIPTION
 *  Proceed saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_delete_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S16 error;
    int del_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority == 0 ||
            g_wlan_prof_list[i].priority < g_wlan_display_context.active_wlan_profile_p->priority)
        {
            continue;
        }

        if (g_wlan_prof_list[i].priority == g_wlan_display_context.active_wlan_profile_p->priority)
        {
            del_index = i;
        }
        else if(g_wlan_prof_list[i].priority > g_wlan_display_context.active_wlan_profile_p->priority)
        {
            g_wlan_prof_list[i].priority--;
            ASSERT(g_wlan_prof_list[i].priority > 0);
            
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, i + 1, &g_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, &error)
                < NVRAM_MAX_WLAN_PROFILE_SIZE)
            {
                ASSERT(0);
            }
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        }
    }

    if(g_wlan_display_context.active_wlan_profile_p->network_type ==  WLAN_NETWORK_TYPE_INFRA)
    {
        g_wlan_display_context.infra_prof_num--;
    }
    else
    {
        g_wlan_display_context.adhoc_prof_num--;
	}

    ASSERT(del_index >= 0);

    ASSERT(g_wlan_prof_list[del_index].profile_id == g_wlan_display_context.active_wlan_profile_p->profile_id);
    
    memset(g_wlan_display_context.active_wlan_profile_p, 0, sizeof(mmi_wlan_profile_struct));

    if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, del_index + 1, g_wlan_display_context.active_wlan_profile_p,
        NVRAM_MAX_WLAN_PROFILE_SIZE, &error) < NVRAM_MAX_WLAN_PROFILE_SIZE)
    {
        ASSERT(0);
    }

    g_wlan_display_context.prof_num--;
    g_wlan_display_context.active_wlan_profile_index = 0;
    /*if (g_wlan_display_context.state == WLAN_STATE_CONNECTED &&
        g_wlan_display_context.active_wlan_profile_p == g_wlan_display_context.connected_wlan_profile)
    {
        g_wlan_display_context.connected_wlan_profile = NULL;
    }*/
    g_wlan_display_context.active_wlan_profile_p = NULL;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_list_change_priority
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_list_change_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i;
    U8 new_priority = g_wlan_display_context.new_priority;
    U8 old_priority = g_wlan_display_context.active_wlan_profile_index + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_priority == old_priority)
    {
        GoBackToHistory(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);
        return;
    }

    ASSERT(new_priority > 0);
    
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority == 0)
        {
            continue;
        }

        if (g_wlan_prof_list[i].priority >= new_priority && g_wlan_prof_list[i].priority < old_priority)
        {
            g_wlan_prof_list[i].priority++;
            
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, i + 1, &g_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, &error)
                < NVRAM_MAX_WLAN_PROFILE_SIZE)
            {
                ASSERT(0);
            }
        }
        else if (g_wlan_prof_list[i].priority <= new_priority && g_wlan_prof_list[i].priority > old_priority)
        {
            g_wlan_prof_list[i].priority--;

            ASSERT(g_wlan_prof_list[i].priority > 0);
            
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, i + 1, &g_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, &error)
                < NVRAM_MAX_WLAN_PROFILE_SIZE)
            {
                ASSERT(0);
            }
        }
        else if (g_wlan_prof_list[i].priority == old_priority)
        {
            g_wlan_prof_list[i].priority = new_priority;
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, i + 1, &g_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, &error)
                < NVRAM_MAX_WLAN_PROFILE_SIZE)
            {
                ASSERT(0);
            }
        }
        g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
    }

    g_wlan_display_context.active_wlan_profile_index = new_priority - 1;
    GoBackToHistory(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_priority
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	S32 low_limit, high_limit;
    U8 network_type;
    S32 *current_value[1];
    void (*cb_func[1]) (S32 value);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_PRIORITY, NULL, mmi_wlan_entry_network_priority, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_PRIORITY);

    g_wlan_display_context.new_priority = g_wlan_display_context.active_wlan_profile_index + 1;
    network_type = g_wlan_profile[g_wlan_display_context.active_wlan_profile_index]->network_type;

    low_limit = 1;
    high_limit = g_wlan_display_context.prof_num;

    current_value[0] = (S32 *)& g_wlan_display_context.new_priority;
    cb_func[0] = mmi_wlan_change_priority_handler;

    ShowCategory88Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT_PRIORITY,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        1,
        NULL,
        &low_limit,
        &high_limit,
        current_value,
        cb_func,
        guiBuffer);

    SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_wlan_network_list_change_priority, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_add
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_change_priority_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 priority;
    U8 network_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    priority = index;
    network_type = g_wlan_profile[g_wlan_display_context.active_wlan_profile_index]->network_type;
    
    if(network_type == WLAN_NETWORK_TYPE_INFRA)
    {
        if(priority > g_wlan_display_context.infra_prof_num)
        {
            wgui_slide_control_previous();

            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_CHANGE_INFRA_PRIORITY),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            
            
            return;
        }
    }
    else
    {
        if(priority <= g_wlan_display_context.infra_prof_num)
        {
            wgui_slide_control_next();
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_CHANGE_ADHOC_PRIORITY),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            
            
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_add
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.prof_num == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_PROFILE_FULL),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }

    g_wlan_display_context.active_wlan_profile_p = &g_wlan_display_context.temp_profile;
    mmi_wlan_init_profile(g_wlan_display_context.active_wlan_profile_p);

    g_wlan_display_context.insert_mode = TRUE;

    mmi_wlan_pre_entry_network_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_delete
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.state == WLAN_STATE_CONNECTED &&
        g_wlan_display_context.active_wlan_profile_p == g_wlan_display_context.connected_wlan_profile)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_DEL),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }

    mmi_wlan_entry_confirm(STR_ID_DTCNT_WLAN_CLEAR_CONFIRM, mmi_wlan_network_delete_yes, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ap_profile_overwrite_no
 * DESCRIPTION
 *  Give up saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_ap_profile_overwrite_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_LIST);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ap_profile_overwrite_yes
 * DESCRIPTION
 *  Proceed saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_ap_profile_overwrite_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_wlan_display_context.active_wlan_profile_p, 0, sizeof(mmi_wlan_profile_struct));
    memcpy(
        g_wlan_display_context.active_wlan_profile_p->ssid,
        g_wlan_display_context.active_ap->ssid,
        WNDRV_SSID_MAX_LEN);
    g_wlan_display_context.active_wlan_profile_p->ssid_len = g_wlan_display_context.active_ap->ssid_len;

    if (WriteRecord(
            NVRAM_EF_WLAN_PROFILE_LID,
            g_wlan_display_context.active_wlan_profile_index + 1,
            g_wlan_display_context.active_wlan_profile_p,
            NVRAM_MAX_WLAN_PROFILE_SIZE,
            &error) <
        NVRAM_MAX_WLAN_PROFILE_SIZE)
    {
        ASSERT(0);
    }

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_LIST);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ap_profile_overwrite
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_ap_profile_overwrite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_entry_confirm(
        STR_ID_DTCNT_WLAN_OVERWRITE_CONFIRM,
        mmi_wlan_ap_profile_overwrite_yes,
        mmi_wlan_ap_profile_overwrite_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_ap_list_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_ap_list_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[nIndex];
    if (g_wlan_display_context.active_wlan_profile_p->ssid_len == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        SetLeftSoftkeyFunction(mmi_wlan_ap_profile_overwrite_yes, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_ID_DTCNT_WLAN_OVERWRITE, 0);
        SetLeftSoftkeyFunction(mmi_wlan_ap_profile_overwrite, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_define_network
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_define_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.prof_num == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_PROFILE_FULL),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }

    g_wlan_display_context.active_wlan_profile_p = &g_wlan_display_context.temp_profile;
    bssinfo_to_profile(g_wlan_display_context.active_wlan_profile_p, g_wlan_display_context.active_ap, NULL, 0);
    g_wlan_display_context.insert_mode = TRUE;
    mmi_wlan_pre_entry_network_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_scan_result_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_scan_result_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.active_ap = &g_wlan_display_context.ap_list[nIndex];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_scan_result_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_scan_result_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_FIND_NETWORK_OPT, NULL, mmi_wlan_entry_scan_result_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_FIND_NETWORK_OPT);

    if (g_wlan_display_context.ap_list_num > 0)
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_FIND_NETWORK_OPT);

        GetSequenceStringIds(MENU_ID_WLAN_FIND_NETWORK_OPT, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_FIND_NETWORK_OPT);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_FIND_NETWORK_OPT2);

        GetSequenceStringIds(MENU_ID_WLAN_FIND_NETWORK_OPT2, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_FIND_NETWORK_OPT2);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
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
 *  mmi_wlan_entry_scan_result
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_scan_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ap_list_num;
    U8 *guiBuffer = NULL;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM];
    U16 iconStates[WNDRV_MAX_SCAN_RESULTS_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* static U8* PopUpDescription[MAX_WLAN_DATA_ACCOUNT_NUM]; */

    ap_list_num = g_wlan_display_context.ap_list_num;
    for (i = 0; i < ap_list_num; i++)
    {
        ASSERT(g_wlan_display_context.ap_list[i].ssid_len > 0);
        memset(subMenuData[i], 0, MAX_SUB_MENU_SIZE);
        mmi_asc_n_to_ucs2(
            (PS8) subMenuData[i],
            (PS8) g_wlan_display_context.ap_list[i].ssid,
            g_wlan_display_context.ap_list[i].ssid_len);
        subMenuDataPtrs[i] = subMenuData[i];
        switch (g_wlan_display_context.ap_list[i].network_type)
        {
            case WNDRV_SUPC_NETWORK_IBSS:
                icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
                break;
            default:
                if (g_wlan_display_context.ap_list[i].privacy > 0 ||
                    g_wlan_display_context.ap_list[i].wpa_ie_info_p == KAL_TRUE ||
                    g_wlan_display_context.ap_list[i].rsn_ie_info_p == KAL_TRUE)
                {
                    icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                }
                else
                {
                    icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;
                }
                break;
        }
        if (g_wlan_display_context.ap_list[i].rssi > -60)
        {
            iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
        }
        else if (g_wlan_display_context.ap_list[i].rssi > -70)
        {
            iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
        }
        else if (g_wlan_display_context.ap_list[i].rssi > -80)
        {
            iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
        }
        else
        {
            iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
        }
    }
    EntryNewScreen(SCR_ID_DTCNT_WLAN_SCAN_RESULT, NULL, mmi_wlan_entry_scan_result, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_SCAN_RESULT);
    RegisterHighlightHandler(mmi_wlan_scan_result_highlight_hdlr);

    /* ShowCategory53Screen(STR_ID_DTCNT_WLAN_SCAN_RESULT, 0,
       STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
       STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
       g_wlan_display_context.ap_list_num, (U8**)DataAccountName,
       (PU16)icon_list,NULL,0,  
       0, guiBuffer); */

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_SCAN_RESULT,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ap_list_num,
        subMenuDataPtrs,
        (U16*) icon_list,
        iconStates,
        0,
        guiBuffer,
        ICON_TEXT_ICON);

    SetLeftSoftkeyFunction(mmi_wlan_entry_scan_result_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_scan_result_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_processing
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE ((MMI_TRACE_G7_MISC, MMI_POC_ENTRY_REGISTERING)); */

    EntryNewScreen(SCR_ID_DTCNT_WLAN_PROCESSING, NULL, mmi_wlan_entry_processing, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_PROCESSING,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_ID_DTCNT_WLAN_PROCESSING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_action_abort
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_action_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_wlan_display_context.prev_state)
    {
        case WLAN_STATE_NULL:
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            break;
        case WLAN_STATE_INIT:
        case WLAN_STATE_CONNECTED:
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
            break;
        default:
            break;
    }
    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_abortable_processing
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_abortable_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE ((MMI_TRACE_G7_MISC, MMI_POC_ENTRY_REGISTERING)); */

    EntryNewScreen(SCR_ID_DTCNT_WLAN_PROCESSING, NULL, mmi_wlan_entry_abortable_processing, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    ShowCategory66Screen(
        SERVICES_DATA_CONNECT_WLAN_STRING_ID,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_ID_DTCNT_WLAN_PROCESSING),
        IMG_ID_DTCNT_WLAN_POPUP_CONNECT,
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_wlan_action_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_disconnect
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_send_disconnect_req();
    mmi_wlan_entry_processing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_find_network_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_find_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buf[MAX_PASSPHRASE_LEN + 1] = "";
    char passphrase[MAX_PASSPHRASE_LEN + 1] = "";
    int keylen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((PS8) buf, (PS8) g_wlan_display_context.passphrase_str);

    if (g_wlan_display_context.active_ap->rsn_ie_info_p == KAL_TRUE ||
        g_wlan_display_context.active_ap->wpa_ie_info_p == KAL_TRUE)
    {
        if(strlen(buf) == 64)
        {
            if(is_valid_hexstring((U8 *) buf, 64) == FALSE)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE),
                    IMG_GLOBAL_ERROR,
                    1,
                    DATA_ACCOUNT_NOTIFY_TIMEOUT,
                    ERROR_TONE);
                return;
            }
        }
        else if (strlen(buf) < 8 || strlen(buf) > 63)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
        keylen = strlen(buf);
        strcpy(passphrase, buf);
    }
    else if (g_wlan_display_context.active_ap->privacy > 0)
    {
        keylen = strlen(buf);
        switch (strlen(buf))
        {
            case 5:
            case 13:
                strcpy(passphrase, buf);
                break;
            case 10:
            {
                if (hex_to_string((U8 *)passphrase, (U8 *)buf, 10) == FALSE)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }
                keylen = 5;
                break;
            }
            case 26:
            {
                if (hex_to_string((U8 *)passphrase, (U8 *)buf, 26) == FALSE)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }
                keylen = 13;
                break;
            }
            default:
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                    IMG_GLOBAL_ERROR,
                    1,
                    DATA_ACCOUNT_NOTIFY_TIMEOUT,
                    ERROR_TONE);
                return;
            }
        };
    }

    if (g_wlan_display_context.active_ap != NULL)
    {
        mmi_wlan_profile_struct *prof = &g_wlan_display_context.temp_profile;

        bssinfo_to_profile(prof, g_wlan_display_context.active_ap, passphrase, keylen);
        PRINT_INFORMATION("$$$$$ WIFI always ask delete screen flag = %d $$$$$", g_always_ask_connect_flag);
        if(g_always_ask_connect_flag)
        {
            g_always_ask_screen_del_handler_flag  = TRUE;
            DeleteUptoScrID(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            if(GetActiveScreenId() != SCR_ID_DTCNT_LIST_ALWAYS_ASK)
            {
               DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            }

            GoBackHistory();
                
            if(g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED)
            {
                g_always_ask_before_connect_flag = TRUE;
            }
            else
            {
                g_always_ask_before_connect_flag = FALSE;
                
                mmi_dtcnt_wlan_connect_result(TRUE);
            }
        }
        else
        {
            mmi_wlan_entry_abortable_processing();
        }
        
        mmi_wlan_send_connect_req(prof);
        if(!g_always_ask_connect_flag)
        {
            DeleteUptoScrID(SCR_ID_DTCNT_WLAN_SCAN_RESULT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_passphrase_input_opt_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_passphrase_input_opt_highlight_hdlr(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetLeftSoftkeyFunction(mmi_wlan_entry_find_network_connect, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
        RegisterInputMethodScreenCloseFunction(mmi_wlan_return_to_editor);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_passphrase_input_opt
 * DESCRIPTION
 *  Entry function to download theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_passphrase_input_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT, NULL, mmi_wlan_entry_passphrase_input_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);

    SetParentHandler(MENU_ID_WLAN_PASSPHRASE_INTPUT_OPT);
    RegisterHighlightHandler(mmi_wlan_passphrase_input_opt_highlight_hdlr);

    numItems = GetNumOfChild(MENU_ID_WLAN_PASSPHRASE_INTPUT_OPT);

    GetSequenceStringIds(MENU_ID_WLAN_PASSPHRASE_INTPUT_OPT, nStrItemList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_passphrase_input
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_passphrase_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT, NULL, mmi_wlan_entry_passphrase_input, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT);

    if (guiBuffer == NULL)
    {
        memset(g_wlan_display_context.passphrase_str, 0, MAX_PASSPHRASE_LEN * ENCODING_LENGTH);
    }
    ShowCategory5Screen(
        STR_ID_DTCNT_WLAN_WPA_PASSPHRASE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S16) (INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE),
        (PU8) g_wlan_display_context.passphrase_str,
        MAX_PASSPHRASE_LEN + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_wlan_entry_passphrase_input_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_find_network_connect
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_find_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.active_ap)
    {
        if (g_wlan_display_context.active_ap->rsn_ie_info_p == TRUE)
        {
            if (g_wlan_display_context.active_ap->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
            {
                mmi_wlan_entry_passphrase_input();
                return;
            }
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_DEFINE_NETWORK_FIRST),
                IMG_GLOBAL_INFO,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                WARNING_TONE);
        }
        else if (g_wlan_display_context.active_ap->wpa_ie_info_p == TRUE)
        {
            if (g_wlan_display_context.active_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
            {
                mmi_wlan_entry_passphrase_input();
                return;
            }
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_DEFINE_NETWORK_FIRST),
                IMG_GLOBAL_INFO,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                WARNING_TONE);
        }
        else if (g_wlan_display_context.active_ap->privacy > 0)
        {
            mmi_wlan_entry_passphrase_input();
            return;
        }
        else    /* No security method is applied */
        {
            mmi_wlan_profile_struct *prof = &g_wlan_display_context.temp_profile;

            bssinfo_to_profile(prof, g_wlan_display_context.active_ap, NULL, 0);

            PRINT_INFORMATION("$$$$$ WIFI always ask delete screen no pw flag = %d $$$$$", g_always_ask_connect_flag);

            if(g_always_ask_connect_flag)
            {
                g_always_ask_screen_del_handler_flag  = TRUE;
                DeleteUptoScrID(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
                if(GetActiveScreenId() != SCR_ID_DTCNT_LIST_ALWAYS_ASK)
                {
                    DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
                }
               
                GoBackHistory();

                if(g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED)
                {
                    g_always_ask_before_connect_flag = TRUE;
                }
                else
                {
                    g_always_ask_before_connect_flag = FALSE;
                   
                    mmi_dtcnt_wlan_connect_result(TRUE);
                }
            }
            else
            {
                mmi_wlan_entry_abortable_processing();
            }
            mmi_wlan_send_connect_req(prof);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_connect
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_entry_abortable_processing();
    g_always_ask_connect_flag = FALSE;
    mmi_wlan_send_connect_req(g_wlan_display_context.active_wlan_profile_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_power
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_power(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.prev_state == WLAN_STATE_NULL && 
       ((g_wlan_display_context.state == WLAN_STATE_NULL) ||
        (g_wlan_display_context.state == WLAN_STATE_DISCONNECT_WAIT) || 
        (g_wlan_display_context.state == WLAN_STATE_DEINIT_WAIT) || 
        (g_wlan_display_context.scan_state == WLAN_SCAN_STATE_ABORTING)))
    {
        if (g_wlan_display_context.prof_num > 0)
        {
            mmi_wlan_entry_abortable_processing();
            mmi_wlan_send_connect_req(NULL);
        }
        else
        {
            mmi_wlan_send_init_req();
            mmi_wlan_entry_abortable_processing();
        }
    }
    else
    {
        switch (g_wlan_display_context.state)
        {
            case WLAN_STATE_INIT:
            case WLAN_STATE_INIT_WAIT:
                mmi_wlan_send_deinit_req();
                mmi_wlan_entry_processing();
                break;
            case WLAN_STATE_CONNECTED:
            case WLAN_STATE_CONNECT_WAIT:
                mmi_wlan_send_disconnect_req();
                mmi_wlan_send_deinit_req();
                mmi_wlan_entry_processing();
                break;
            case WLAN_STATE_DISCONNECT_WAIT:
                mmi_wlan_send_deinit_req();
                mmi_wlan_entry_processing();
                break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_action_abort_find_network
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_action_abort_find_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_wlan_display_context.scan_state)
    {
        case WLAN_SCAN_STATE_NULL:
            if (g_wlan_display_context.prev_state == WLAN_STATE_NULL)
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            }
            delete_action(&g_wlan_display_context.actions, WLAN_ACTION_SCAN);
            break;
        case WLAN_SCAN_STATE_WAITING:
            g_wlan_display_context.scan_state = WLAN_SCAN_STATE_ABORTING;
            if (g_wlan_display_context.prev_state == WLAN_STATE_NULL)
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            }
            break;
        default:
            ASSERT(0);
    }
    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_SCAN_PROCESSING)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_details
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    U8 *guiBuffer;
    U8 *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_DETAILS, NULL, mmi_wlan_entry_network_details, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_DETAILS);

    info = (PU8) subMenuData;

    mmi_ucs2cpy((PS8) info, GetString(STR_ID_DTCNT_WLAN_SSID));
    mmi_ucs2cat((PS8) info, (PS8) L":  ");
    if (g_wlan_display_context.active_ap->ssid_len == 0)
    {
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
    }
    else
    {
        memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(
            tempBufUnicode,
            (PS8) g_wlan_display_context.active_ap->ssid,
            g_wlan_display_context.active_ap->ssid_len);
        mmi_ucs2cat((PS8) info, tempBufUnicode);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
    }

    /*
     * mmi_ucs2cat((PS8)info, (PS8)L"BSSID:\n");
     * sprintf(tempBuf, "%02x:%02x:%02x:%02x:%02x:%02x\n\n", g_wlan_display_context.active_ap->bssid[0], g_wlan_display_context.active_ap->bssid[1],
     * g_wlan_display_context.active_ap->bssid[2], g_wlan_display_context.active_ap->bssid[3], g_wlan_display_context.active_ap->bssid[4],
     * g_wlan_display_context.active_ap->bssid[5]);
     * mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
     * mmi_ucs2cat((PS8)info, tempBufUnicode);
     */
    /*
     * mmi_ucs2cat((PS8)info, (PS8)L"Channel:\n");
     * sprintf(tempBuf, "%d\n\n", g_wlan_display_context.active_ap->channel_number);
     * mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
     * mmi_ucs2cat((PS8)info, tempBufUnicode);
     */
    mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));
    mmi_ucs2cat((PS8) info, (PS8) L":  ");
    switch (g_wlan_display_context.active_ap->network_type)
    {
        case WNDRV_SUPC_NETWORK_IBSS:
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC));
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA));
            break;
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_AUTO));
            break;
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

    mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_STRENGTH));
    mmi_ucs2cat((PS8) info, (PS8) L":  ");
    if (g_wlan_display_context.active_ap->rssi > -40)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL0));
    }
    else if (g_wlan_display_context.active_ap->rssi > -60)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL1));
    }
    else if (g_wlan_display_context.active_ap->rssi > -70)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL2));
    }
    else if (g_wlan_display_context.active_ap->rssi > -80)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL3));
    }
    else
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL4));
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

    mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SECURITY));
    mmi_ucs2cat((PS8) info, (PS8) L":  ");
    if (g_wlan_display_context.active_ap->rsn_ie_info_p == KAL_TRUE)
    {
        if (g_wlan_display_context.active_ap->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
        {
            mmi_ucs2cat((PS8) info, (PS8) L"WPA2-PSK\n\n");
        }
        else
        {
            mmi_ucs2cat((PS8) info, (PS8) L"WPA2\n\n");
        }
    }
    else if (g_wlan_display_context.active_ap->wpa_ie_info_p == KAL_TRUE)
    {
        if (g_wlan_display_context.active_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
        {
            mmi_ucs2cat((PS8) info, (PS8) L"WPA-PSK\n\n");
        }
        else
        {
            mmi_ucs2cat((PS8) info, (PS8) L"WPA\n\n");
        }
    }
    else if (g_wlan_display_context.active_ap->privacy > 0)
    {
        mmi_ucs2cat((PS8) info, (PS8) L"WEP\n\n");
    }
    else
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN));
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
    }

    mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_LINK_SPEED));
    mmi_ucs2cat((PS8) info, (PS8) L":  ");
    sprintf(tempBuf, "%d Mbit/s\n", g_wlan_display_context.active_ap->max_rate / 2);
    mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
    mmi_ucs2cat((PS8) info, tempBufUnicode);

    ShowCategory74Screen(
        STR_ID_DTCNT_WLAN_NETWORK_DETAILS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_find_network
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_find_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_SCAN_PROCESSING, NULL, mmi_wlan_entry_find_network, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_SCAN_RESULT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_FIND_NETWORK_OPT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_FIND_NETWORK,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_ID_DTCNT_WLAN_FINDING_NETWORK),
        IMG_ID_DTCNT_WLAN_POPUP_SEARCH,
        NULL);

    mmi_wlan_send_ap_list_req();

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_wlan_action_abort_find_network, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_find_network
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_find_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset AP list context */
    memset(g_wlan_display_context.ap_list, 0, sizeof(supc_abm_bss_info_struct) * WNDRV_MAX_SCAN_RESULTS_NUM);
    g_wlan_display_context.ap_list_num = 0;
    mmi_wlan_entry_find_network();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_settings
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *u8GPRSCount[MAX_SUB_MENUS];     /* sms counters for display hint popups */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_SETTINGS, NULL, mmi_wlan_entry_settings, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_SETTINGS);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_WLAN_SETTINGS);
    /* Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_WLAN_SETTINGS);
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_WLAN_SETTINGS, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_ID_WLAN_SETTINGS);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* construct hint popups for the menu items */
    ConstructHintsList(MENU_ID_WLAN_SETTINGS, u8GPRSCount);
    /* Display Category52 Screen */
    ShowCategory52Screen(
        STR_ID_DTCNT_WLAN_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
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
    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 wep_key[MAX_WEP_KEYSTR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((PS8) wep_key, (PS8) g_wlan_display_context.wep_key_str);

    if((g_wlan_display_context.sel_wep_key_index == g_wlan_display_context.wep_key_index) &&
        (g_wlan_display_context.sel_wep_key_len == g_old_wep_key_len) &&
        (g_wlan_display_context.sel_wep_key_format == g_old_wep_key_format) &&
        !(mmi_ucs2cmp((S8*)g_old_wep_key_str, (S8*)g_wlan_display_context.wep_key_str)))
    {
        GoBackToHistory(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
        return;
    }

    switch (g_wlan_display_context.sel_wep_key_len)
    {
        case WLAN_WEP_KEY_ENCRYPT_64:
            if (g_wlan_display_context.sel_wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wep_key) != 10)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }

                if (!is_valid_hexstring(wep_key, 10))
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }
            }
            else
            {
                if (strlen((const char*)wep_key) != 5)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }
            }
            break;
        case WLAN_WEP_KEY_ENCRYPT_128:
            if (g_wlan_display_context.sel_wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wep_key) != 26)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }

                if (!is_valid_hexstring(wep_key, 26))
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }
            }
            else
            {
                if (strlen((const char*)wep_key) != 13)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY),
                        IMG_GLOBAL_ERROR,
                        1,
                        DATA_ACCOUNT_NOTIFY_TIMEOUT,
                        ERROR_TONE);
                    return;
                }
            }
            break;
    }

    g_wlan_display_context.wep_key_index = g_wlan_display_context.sel_wep_key_index;
    g_wlan_display_context.wep_key_len = g_wlan_display_context.sel_wep_key_len;
    g_wlan_display_context.wep_key_format = g_wlan_display_context.sel_wep_key_format;

    g_wlan_display_context.modified = TRUE;
    GoBackToHistory(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_key_format_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_key_format_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;
    S32 old_length = 0;
    U8 wep_key[MAX_WEP_KEYSTR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.wep_key_format != index)
    {
        g_wlan_display_context.wep_key_format = index;
        switch (g_wlan_display_context.wep_key_len)
        {
            case WLAN_WEP_KEY_ENCRYPT_64:
                if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
                {
                    length = 10;
                }
                else
                {
                    length = 5;
		    mmi_ucs2_to_asc((PS8) wep_key, (PS8) g_wlan_display_context.wep_key_str);
		    old_length = strlen((PS8) wep_key);
		    if (old_length > length)
		    {
		        /* truncate key if it exceeds the limit */
			g_wlan_display_context.wep_key_str[2*length] = 0;
			g_wlan_display_context.wep_key_str[2*length + 1] = 0;
		    }
                }
                break;
            case WLAN_WEP_KEY_ENCRYPT_128:
                if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
                {
                    length = 26;
                }
                else
                {
                    length = 13;
		    mmi_ucs2_to_asc((PS8) wep_key, (PS8) g_wlan_display_context.wep_key_str);
		    old_length = strlen((PS8) wep_key);
		    if (old_length > length)
		    {
		        /* truncate key if it exceeds the limit */
			g_wlan_display_context.wep_key_str[2*length] = 0;
			g_wlan_display_context.wep_key_str[2*length + 1] = 0;
		    }
                }
                break;
            default:
                ASSERT(0);
                break;
        }
		
        ReConfigureInlineItemFullScreenEdit(
            &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY],
            STR_ID_DTCNT_WLAN_WEP_KEY,
            GetRootTitleIcon(MENU_ID_WLAN_MAIN),
            (U8*) (g_wlan_display_context.wep_key_str),
            length + 1,
            INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD);
        SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY], DataAccountFullLineEditScreen);
        RedrawCategoryFunction();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_key_len_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_key_len_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;
    S32 old_length = 0;
    U8 wep_key[MAX_WEP_KEYSTR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.wep_key_len != index)
    {
        g_wlan_display_context.wep_key_len = index;
        switch (g_wlan_display_context.wep_key_len)
        {
            case WLAN_WEP_KEY_ENCRYPT_64:
                if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
                {
                    length = 10;
                }
                else
                {
                    length = 5;
		    mmi_ucs2_to_asc((PS8) wep_key, (PS8) g_wlan_display_context.wep_key_str);
		    old_length = strlen((PS8) wep_key);
		    if (old_length > length)
		    {
		        /* truncate key if it exceeds the limit */
			g_wlan_display_context.wep_key_str[2*length] = 0;
			g_wlan_display_context.wep_key_str[2*length + 1] = 0;
		    }
                }
                break;
            case WLAN_WEP_KEY_ENCRYPT_128:
                if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
                {
                    length = 26;
                }
                else
                {
                    length = 13;
		    mmi_ucs2_to_asc((PS8) wep_key, (PS8) g_wlan_display_context.wep_key_str);
		    old_length = strlen((PS8) wep_key);
		    if (old_length > length)
		    {
     		     	/* truncate key if it exceeds the limit */
			g_wlan_display_context.wep_key_str[2*length] = 0;
			g_wlan_display_context.wep_key_str[2*length + 1] = 0;
		    }
                }
                break;
            default:
                ASSERT(0);
                break;
        }
		
        ReConfigureInlineItemFullScreenEdit(
            &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY],
            STR_ID_DTCNT_WLAN_WEP_KEY,
            GetRootTitleIcon(MENU_ID_WLAN_MAIN),
            (U8*) (g_wlan_display_context.wep_key_str),
            length + 1,
            INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD);
        SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY], DataAccountFullLineEditScreen);
        RedrawCategoryFunction();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.wep_key_index_opt[0] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ID1);
    g_wlan_display_context.wep_key_index_opt[1] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ID2);
    g_wlan_display_context.wep_key_index_opt[2] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ID3);
    g_wlan_display_context.wep_key_index_opt[3] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ID4);

    g_wlan_display_context.wep_key_len_opt[0] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_64);
    g_wlan_display_context.wep_key_len_opt[1] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_128);
    //g_wlan_display_context.wep_key_len_opt[2] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_256);

    g_wlan_display_context.wep_key_format_opt[0] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_HEX);
    g_wlan_display_context.wep_key_format_opt[1] = (PU8) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII);

    switch (g_wlan_display_context.wep_key_len)
    {
        case WLAN_WEP_KEY_ENCRYPT_64:
            if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                length = 10;
            }
            else
            {
                length = 5;
            }
            break;
        case WLAN_WEP_KEY_ENCRYPT_128:
            if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                length = 26;
            }
            else
            {
                length = 13;
            }
            break;
        default:
            ASSERT(0);
            break;            
    }

    /* WEP key in use */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ID_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ID));
    SetInlineItemActivation(&wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ID], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ID],
        4,
        g_wlan_display_context.wep_key_index_opt,
        &g_wlan_display_context.sel_wep_key_index);

    /* WEP Encryption */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ENCRYPT_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ENCRYPT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ENCRYPT],
        WLAN_WEP_KEY_ENCRYPT_TOTAL,
        g_wlan_display_context.wep_key_len_opt,
        &g_wlan_display_context.sel_wep_key_len);

    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_ENCRYPT],
        mmi_wlan_wep_settings_key_len_highlight_hdlr);


    /* WEP key format */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_FORMAT_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_FORMAT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_FORMAT],
        2,
        g_wlan_display_context.wep_key_format_opt,
        &g_wlan_display_context.sel_wep_key_format);

    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_FORMAT],
        mmi_wlan_wep_settings_key_format_highlight_hdlr);

    /* WEP key */
    SetInlineItemCaption(&wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_WEP_KEY));
    SetInlineItemActivation(&wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY],
        STR_ID_DTCNT_WLAN_WEP_KEY,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        (U8*) (g_wlan_display_context.wep_key_str),
        length + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_WEP_EDIT_WEP_KEY], DataAccountFullLineEditScreen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_wep_settings
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_wep_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_WEP_SETTINGS;
    h.entryFuncPtr = mmi_wlan_entry_wep_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wep_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wep_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;
    BOOL modified = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_WEP_SETTINGS, mmi_wlan_exit_wep_settings, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_WEP_SETTINGS);
    if (guiBuffer == NULL)
    {
        g_wlan_display_context.sel_wep_key_index = g_wlan_display_context.wep_key_index;
        g_wlan_display_context.sel_wep_key_len = g_wlan_display_context.wep_key_len;
        g_wlan_display_context.sel_wep_key_format = g_wlan_display_context.wep_key_format;

        mmi_ucs2cpy((S8*)g_old_wep_key_str, (S8*)g_wlan_display_context.wep_key_str);
        g_old_wep_key_len = g_wlan_display_context.wep_key_len;
        g_old_wep_key_format = g_wlan_display_context.wep_key_format;
    }
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_WEP_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    SetParentHandler(MITEM_DATA_ACCOUNT_PARENT_ZERO);
    mmi_wlan_wep_settings_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_WEP_EDIT_INLINE_TOTAL, inputBuffer);
    }

    if (modified == TRUE)
    {
        wgui_inline_list_menu_changed = 1;
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_WEP_KEY_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_WEP_EDIT_INLINE_TOTAL,
        (U16*) g_wlan_display_context.icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_wep_settings_save, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wpa_passphrase_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wpa_passphrase_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char passphrase[MAX_PASSPHRASE_LEN + 1] = "";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_wlan_profile_struct *active_profile = g_wlan_display_context.active_wlan_profile_p; */

    mmi_ucs2_to_asc((PS8) passphrase, (PS8) g_wlan_display_context.passphrase_str);

    if(strlen(passphrase) == 64)
    {
        if(!is_valid_hexstring((U8 *)passphrase, 64))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
    }
    else if (strlen(passphrase) < 8 || strlen(passphrase) > 63)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }

    strcpy((char*)g_wlan_display_context.passphrase, (const char*)passphrase);
    g_wlan_display_context.modified = TRUE;

    GoBackToHistory(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wpa_passphrase_opt_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wpa_passphrase_opt_highlight_hdlr(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetLeftSoftkeyFunction(mmi_wlan_wpa_passphrase_save, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
        RegisterInputMethodScreenCloseFunction(mmi_wlan_return_to_editor);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wpa_passphrase_opt
 * DESCRIPTION
 *  Entry function to download theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wpa_passphrase_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_WPA_PASSPHRASE_OPT, NULL, mmi_wlan_entry_wpa_passphrase_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_WPA_PASSPHRASE_OPT);

    SetParentHandler(MENU_ID_WLAN_WPA_PASSPHRASE_OPT);
    RegisterHighlightHandler(mmi_wlan_wpa_passphrase_opt_highlight_hdlr);

    numItems = GetNumOfChild(MENU_ID_WLAN_WPA_PASSPHRASE_OPT);

    GetSequenceStringIds(MENU_ID_WLAN_WPA_PASSPHRASE_OPT, nStrItemList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wpa_passphrase
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wpa_passphrase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_WPA_PASSPHRASE, NULL, mmi_wlan_entry_wpa_passphrase, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_WPA_PASSPHRASE);

    if (guiBuffer == NULL)
    {
        memset(g_wlan_display_context.passphrase_str, 0, (MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
        if (strlen((const char*)g_wlan_display_context.passphrase) > 0)
        {
            mmi_asc_n_to_ucs2(
                (PS8) g_wlan_display_context.passphrase_str,
                (PS8) g_wlan_display_context.passphrase,
                strlen((const char*)g_wlan_display_context.passphrase));
        }
    }
    ShowCategory5Screen(
        STR_ID_DTCNT_WLAN_WPA_PASSPHRASE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S16) (INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD),
        (PU8) g_wlan_display_context.passphrase_str,
        MAX_PASSPHRASE_LEN + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_wlan_entry_wpa_passphrase_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auth_mode_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_auth_mode_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int new_auth_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.network_type == WLAN_NETWORK_TYPE_ADHOC && g_wlan_display_context.sel_auth_mode == 2 /* WPA-None */)
    {
        new_auth_mode = WLAN_AUTH_MODE_WPAPSK;
    }
    else
    {
        new_auth_mode = g_wlan_display_context.sel_auth_mode;
    }
    
    if (g_wlan_display_context.auth_mode != new_auth_mode)
    {
        switch (g_wlan_display_context.auth_mode)
        {
            case WLAN_AUTH_MODE_OPEN:
                if (new_auth_mode == WLAN_AUTH_MODE_SHARED)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
                    break;
                }
            case WLAN_AUTH_MODE_SHARED:
                if (new_auth_mode == WLAN_AUTH_MODE_WPA ||
                    new_auth_mode == WLAN_AUTH_MODE_WPAPSK)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_TKIP;
                }
                else if (new_auth_mode == WLAN_AUTH_MODE_IEEE8021X)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
                }
                break;
            case WLAN_AUTH_MODE_WPA:
            case WLAN_AUTH_MODE_WPAPSK:
                if (new_auth_mode == WLAN_AUTH_MODE_OPEN)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_NONE;
                }
                else if (new_auth_mode == WLAN_AUTH_MODE_SHARED)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
                }
                else if (new_auth_mode == WLAN_AUTH_MODE_IEEE8021X)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
                }
                break;
            case WLAN_AUTH_MODE_IEEE8021X:
                if (new_auth_mode == WLAN_AUTH_MODE_WPA ||
                    new_auth_mode == WLAN_AUTH_MODE_WPAPSK)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_TKIP;
                }
                else if (new_auth_mode == WLAN_AUTH_MODE_OPEN)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_NONE;
                }
                else if (new_auth_mode == WLAN_AUTH_MODE_SHARED)
                {
                    g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
                }
                break;
        }
        g_wlan_display_context.modified = TRUE;
    }

    g_wlan_display_context.auth_mode = new_auth_mode;

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auth_mode_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_auth_mode_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_auth_mode = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_auth_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_auth_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[WLAN_AUTH_MODE_TOTAL];
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U16 nNumofItem; */

    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_AUTH_MODE, NULL, mmi_wlan_entry_auth_mode, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_AUTH_MODE);
    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_auth_mode_highlight_hdlr);

    nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
    nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED);
    if(g_wlan_display_context.network_type != WLAN_NETWORK_TYPE_ADHOC)
    {
        nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_IEEE8021X);
        nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA);
        nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPAPSK);
    }
    else
    {
        nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPANONE);
    }
    
    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_AUTH_MODE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        nStrList,
        NULL,
        g_wlan_display_context.sel_auth_mode,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_wlan_auth_mode_ok, KEY_EVENT_UP);

    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_auth_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_auth_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.network_type != WLAN_NETWORK_TYPE_ADHOC)
    {
        g_wlan_display_context.sel_auth_mode = g_wlan_display_context.auth_mode;
    }
    else
    {
        switch(g_wlan_display_context.auth_mode)
        {
        case WLAN_AUTH_MODE_OPEN:
            g_wlan_display_context.sel_auth_mode = 0;
            break;
        case WLAN_AUTH_MODE_SHARED:
            g_wlan_display_context.sel_auth_mode = 1;
            break;
        case WLAN_AUTH_MODE_WPAPSK:
            g_wlan_display_context.sel_auth_mode = 2;
            break;
        default:
            ASSERT(0);
        }
    }
    mmi_wlan_entry_auth_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_encrypt_mode_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_encrypt_mode_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 encrypt_mode = g_wlan_display_context.encrypt_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_wlan_display_context.auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:
        case WLAN_AUTH_MODE_SHARED:
            encrypt_mode = g_wlan_display_context.sel_encrypt_mode;
            break;
        case WLAN_AUTH_MODE_IEEE8021X:
            encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
            break;
        case WLAN_AUTH_MODE_WPA:
        case WLAN_AUTH_MODE_WPAPSK:
            if (g_wlan_display_context.sel_encrypt_mode == 0)
            {
                encrypt_mode = WLAN_ENCRYPT_MODE_TKIP;
            }
            else
            {
                encrypt_mode = WLAN_ENCRYPT_MODE_AES;
            }
            break;
    }

    if (g_wlan_display_context.encrypt_mode != encrypt_mode)
    {
        g_wlan_display_context.modified = TRUE;
        g_wlan_display_context.encrypt_mode = encrypt_mode;
    }
    /*if (g_wlan_display_context.encrypt_mode == WLAN_ENCRYPT_MODE_WEP)
    {
        mmi_wlan_entry_wep_settings();
    }
    else
    {
        GoBackHistory();
    }*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_encrypt_mode_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_encrypt_mode_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_encrypt_mode = nIndex;
    /*if (g_wlan_display_context.sel_encrypt_mode == WLAN_ENCRYPT_MODE_WEP &&
        g_wlan_display_context.auth_mode == WLAN_AUTH_MODE_OPEN)
    {
        ChangeLeftSoftkey(STR_ID_DTCNT_WLAN_CONFIGURE, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_encrypt_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_encrypt_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[2];
    U16 nNumofItem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 hiliteStorage; */

    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_ENCRYPT_MODE, NULL, mmi_wlan_entry_encrypt_mode, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_ENCRYPT_MODE);

    SetParentHandler(SCR_ID_DTCNT_WLAN_NETWORK_ENCRYPT_MODE);
    RegisterHighlightHandler(mmi_wlan_encrypt_mode_highlight_hdlr);

    switch (g_wlan_display_context.auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:
        case WLAN_AUTH_MODE_SHARED:
            nStrList[0] = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_NONE);
            nStrList[1] = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WEP);
            nNumofItem = 2;
            break;
        case WLAN_AUTH_MODE_IEEE8021X:
            nStrList[0] = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WEP);
            nNumofItem = 1;
            break;
        case WLAN_AUTH_MODE_WPA:
        case WLAN_AUTH_MODE_WPAPSK:
            nStrList[0] = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_TKIP);
            nStrList[1] = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_AES);
            nNumofItem = 2;
            break;
    }

    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_ENCRYPT_MODE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrList,
        NULL,
        g_wlan_display_context.sel_encrypt_mode,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_wlan_encrypt_mode_ok, KEY_EVENT_UP);

    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_encrypt_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_encrypt_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_wlan_display_context.auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:
        case WLAN_AUTH_MODE_SHARED:
            g_wlan_display_context.sel_encrypt_mode = g_wlan_display_context.encrypt_mode;
            break;
        case WLAN_AUTH_MODE_IEEE8021X:
            g_wlan_display_context.sel_encrypt_mode = 0;
            break;
        case WLAN_AUTH_MODE_WPA:
        case WLAN_AUTH_MODE_WPAPSK:
            if (g_wlan_display_context.encrypt_mode == WLAN_ENCRYPT_MODE_TKIP)
            {
                g_wlan_display_context.sel_encrypt_mode = 0;
            }
            else
            {
                g_wlan_display_context.sel_encrypt_mode = 1;
            }
            break;
    }
    mmi_wlan_entry_encrypt_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_encrypt_mode_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.network_type = g_wlan_display_context.network_type_dummy;
    
    /* Reset authentiation mode if it is set to WPA/WPA2 or 802.1X */
    if(g_wlan_display_context.network_type == WLAN_NETWORK_TYPE_ADHOC)
    {
        if(g_wlan_display_context.auth_mode == WLAN_AUTH_MODE_WPA || 
           g_wlan_display_context.auth_mode == WLAN_AUTH_MODE_IEEE8021X)
        {
            g_wlan_display_context.auth_mode = WLAN_AUTH_MODE_OPEN;
            g_wlan_display_context.encrypt_mode = WLAN_ENCRYPT_MODE_NONE;
        }
    }

    g_wlan_display_context.modified = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_encrypt_mode_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.network_type_dummy = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_encrypt_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[2];
    U16 nNumofItem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 hiliteStorage; */

    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_OPERATION_MODE, NULL, mmi_wlan_entry_network_type, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_OPERATION_MODE);

    if(guiBuffer == NULL)
    {
        g_wlan_display_context.network_type_dummy = g_wlan_display_context.network_type;
    }

    SetParentHandler(SCR_ID_DTCNT_WLAN_NETWORK_OPERATION_MODE);
    RegisterHighlightHandler(mmi_wlan_network_type_highlight_hdlr);

    nStrList[0] = (U8*) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA);
    nStrList[1] = (U8*) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
    nNumofItem = 2;

    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_NETWORK_TYPE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrList,
        NULL,
        g_wlan_display_context.network_type_dummy,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_wlan_network_type_ok, KEY_EVENT_UP);

    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_no_auth_settings
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_no_auth_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_NO_AUTH_SETTING),
        IMG_GLOBAL_INFO,
        1,
        DATA_ACCOUNT_NOTIFY_TIMEOUT,
        WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex == WLAN_NETWORK_EDIT_AUTH_MODE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_pre_entry_auth_mode, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_NETWORK_EDIT_NETWORK_TYPE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_type, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_NETWORK_EDIT_ENCRYPT_MODE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_pre_entry_encrypt_mode, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_NETWORK_EDIT_TCPIP_SETTINGS)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_pre_entry_tcpip_settings, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_NETWORK_EDIT_SECURITY_SETTINGS)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        switch (g_wlan_display_context.auth_mode)
        {
            case WLAN_AUTH_MODE_SHARED:
                SetLeftSoftkeyFunction(mmi_wlan_entry_wep_settings, KEY_EVENT_UP);
                break;
            case WLAN_AUTH_MODE_IEEE8021X:
            case WLAN_AUTH_MODE_WPA:
                SetLeftSoftkeyFunction(mmi_wlan_entry_eap_type, KEY_EVENT_UP);
                break;
            case WLAN_AUTH_MODE_WPAPSK:
                SetLeftSoftkeyFunction(mmi_wlan_entry_wpa_passphrase, KEY_EVENT_UP);
                break;
            default:
                if (g_wlan_display_context.encrypt_mode == WLAN_ENCRYPT_MODE_WEP)
                {
                    SetLeftSoftkeyFunction(mmi_wlan_entry_wep_settings, KEY_EVENT_UP);
                }
                else
                {
                    SetLeftSoftkeyFunction(mmi_wlan_entry_no_auth_settings, KEY_EVENT_UP);
                }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_save_no
 * DESCRIPTION
 *  Give up saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_save_yes
 * DESCRIPTION
 *  Proceed saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    U8 old_network;
    S16 error;
    U8 ssid[MAX_SSID_LEN];
    mmi_wlan_profile_struct *active_profile = g_wlan_display_context.active_wlan_profile_p;
    mmi_wlan_profile_struct *temp = NULL;
    U8 no_space_name[MAX_WLAN_PROF_NAME_LEN *ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Todo: validation required here */

    memset((PS8) no_space_name, 0, sizeof(no_space_name));
    
    mmi_ucs2_to_asc((PS8) ssid, (PS8) g_wlan_display_context.ssid_str);

    if (mmi_ucs2strlen((PS8)g_wlan_display_context.name) == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_NAME),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }

    if (strlen((const char*)ssid) == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_SSID),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }

    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if(active_profile == g_wlan_profile[i])
            continue;

        mmi_wlan_delete_space_string((S8 *)g_wlan_display_context.name, (S8 *)no_space_name);

        if(mmi_ucs2cmp((S8 *)g_wlan_profile[i]->name, (S8 *)no_space_name) == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_NAME_INUSE),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
    }

    if (g_wlan_display_context.auth_mode == WLAN_AUTH_MODE_WPAPSK)
    {
        if(strlen((const char*)g_wlan_display_context.passphrase) == 64)
        {
            if(!is_valid_hexstring(g_wlan_display_context.passphrase, 64))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE),
                    IMG_GLOBAL_ERROR,
                    1,
                    DATA_ACCOUNT_NOTIFY_TIMEOUT,
                    ERROR_TONE);
                return;
            }
        }
        else if (strlen((const char*)g_wlan_display_context.passphrase) < 8 ||
            strlen((const char*)g_wlan_display_context.passphrase) > 63)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
    }

    EntryDTCNTProgress();

    active_profile->ssid_len = strlen((const char*)ssid);
    memcpy(active_profile->ssid, ssid, active_profile->ssid_len);
    mmi_ucs2cpy((PS8)active_profile->name, (PS8)g_wlan_display_context.name);
    
    old_network = active_profile->network_type;
    active_profile->network_type = g_wlan_display_context.network_type;
    active_profile->auth_mode = g_wlan_display_context.auth_mode;
    active_profile->encrypt_mode = g_wlan_display_context.encrypt_mode;

    if (active_profile->auth_mode == WLAN_AUTH_MODE_SHARED || active_profile->encrypt_mode == WLAN_ENCRYPT_MODE_WEP)
    {
        active_profile->wep_key_index = g_wlan_display_context.wep_key_index;
        active_profile->wep_key_len = g_wlan_display_context.wep_key_len;
        active_profile->wep_key_format = g_wlan_display_context.wep_key_format;
        mmi_ucs2_to_asc((PS8) active_profile->wep_key, (PS8) g_wlan_display_context.wep_key_str);
    }

    if (active_profile->auth_mode == WLAN_AUTH_MODE_WPAPSK)
    {
        if(strlen((const char*)g_wlan_display_context.passphrase) == 64)
        {
            hex_to_string(active_profile->psk, g_wlan_display_context.passphrase, 64);
            memset(active_profile->passphrase, 0, sizeof(active_profile->passphrase));
            active_profile->psk[32] = 1;
        }
        else if (strcmp((const char*)active_profile->passphrase, (const char*)g_wlan_display_context.passphrase) != 0 ||
            active_profile->psk[0] == 0)
        {
            strcpy((char*)active_profile->passphrase, (const char*)g_wlan_display_context.passphrase);
        #ifdef __MTK_TARGET__
            pbkdf2_sha1(
                (const char*)active_profile->passphrase,
                (const char*)active_profile->ssid,
                active_profile->ssid_len,
                4096,
                active_profile->psk,
                32);
        #else /* __MTK_TARGET__ */ 
            strcpy((char*)active_profile->psk, (const char*)active_profile->passphrase);
        #endif /* __MTK_TARGET__ */ 
        }
    }

    if (active_profile->auth_mode == WLAN_AUTH_MODE_IEEE8021X || active_profile->auth_mode == WLAN_AUTH_MODE_WPA)
    {
        active_profile->auth_type1 = g_wlan_display_context.auth_type1;
        active_profile->eap_peap_auth_type = g_wlan_display_context.eap_peap_auth_type;
        active_profile->eap_ttls_auth_type = g_wlan_display_context.eap_ttls_auth_type;
#ifndef __CERTMAN_SUPPORT__
        mmi_ucs2cpy((S8*) active_profile->client_ca_path, g_wlan_display_context.client_ca_path);
        mmi_ucs2cpy((S8*) active_profile->root_ca_path, g_wlan_display_context.root_ca_path);
        mmi_ucs2cpy((S8*) active_profile->private_key_path, g_wlan_display_context.private_key_path);
#else
                active_profile->client_ca_id = g_wlan_display_context.client_ca_id;
                active_profile->root_ca_id = g_wlan_display_context.root_ca_id;
                //active_profile->private_key_id = g_wlan_display_context.private_key_id;
#endif /* __CERTMAN_SUPPORT__ */

        mmi_ucs2_to_asc((PS8) active_profile->private_key_passwd, (PS8) g_wlan_display_context.private_key_passwd_str);
        mmi_ucs2_to_asc((PS8) active_profile->username, (PS8) g_wlan_display_context.username_str);
        mmi_ucs2_to_asc((PS8) active_profile->password, (PS8) g_wlan_display_context.password_str);
    }

    if(g_wlan_display_context.allow_peap0 > 0)
    {
        active_profile->peap_version |= SUPC_PHASE1_PEAP_0;
    }
    else
    {
        active_profile->peap_version &= ~SUPC_PHASE1_PEAP_0;
    }

    if(g_wlan_display_context.allow_peap1 > 0)
    {
        active_profile->peap_version |= SUPC_PHASE1_PEAP_1;
    }
    else
    {
        active_profile->peap_version &= ~SUPC_PHASE1_PEAP_1;
    }

    active_profile->use_anonymous = g_wlan_display_context.use_anonymous;
    
    active_profile->channel = (U32)g_wlan_display_context.channel_number;

    active_profile->use_dhcp = g_wlan_display_context.use_dhcp;
    memcpy(active_profile->ip_addr, g_wlan_display_context.ip_addr, 4);
    memcpy(active_profile->netmask, g_wlan_display_context.netmask, 4);
    memcpy(active_profile->gateway, g_wlan_display_context.gateway, 4);
    memcpy(active_profile->dns1, g_wlan_display_context.dns1, 4);
    memcpy(active_profile->dns2, g_wlan_display_context.dns2, 4);

    if (g_wlan_display_context.insert_mode == TRUE)
    {
        /* Find an empty slot index first */
        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (g_wlan_prof_list[i].ssid_len == 0)
            {
                break;
            }
        }

		if(active_profile->network_type == WLAN_NETWORK_TYPE_INFRA)
		{
			if(g_wlan_display_context.adhoc_prof_num == 0)
			{
        active_profile->priority = ++g_wlan_display_context.prof_num;
        active_profile->profile_id = ++g_wlan_setting_context.profile_id_count;
        
        memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
        g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
			}
			else
			{
                for(j = g_wlan_display_context.prof_num; j > g_wlan_display_context.infra_prof_num; j--)
				{
                    g_wlan_profile[j] = g_wlan_profile[j-1];
                    g_wlan_profile[j]->priority++;
				}

                active_profile->priority = g_wlan_display_context.infra_prof_num + 1;
				active_profile->profile_id = ++g_wlan_setting_context.profile_id_count;
                memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[g_wlan_display_context.infra_prof_num] = &g_wlan_prof_list[i];
				g_wlan_display_context.prof_num++;
			}
            g_wlan_display_context.infra_prof_num++;
		}
		else 
		{
			g_wlan_display_context.adhoc_prof_num++;
			
			active_profile->priority = ++g_wlan_display_context.prof_num;
			active_profile->profile_id = ++g_wlan_setting_context.profile_id_count;

			memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
			g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
			g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
		}
        
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
        
    }
    else
    {
        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (active_profile == &g_wlan_prof_list[i])
            {
                break;
            }
        }
        /* changed ap profile network_type */
        if(active_profile->network_type != old_network)
        {
            /* adhoc -> Infrastructure*/
            if(active_profile->network_type == WLAN_NETWORK_TYPE_INFRA)
            {
                if(active_profile->priority == g_wlan_display_context.infra_prof_num + 1)
                {
                    g_wlan_display_context.infra_prof_num++;
                    g_wlan_display_context.adhoc_prof_num--;
                }
                else
                {
                    temp = active_profile;
                    for(j = (active_profile->priority - 1); j > g_wlan_display_context.infra_prof_num; j--)
                    {
                        g_wlan_profile[j] = g_wlan_profile[j - 1];
                        g_wlan_profile[j]->priority++;
                    }
                    g_wlan_profile[g_wlan_display_context.infra_prof_num ] = temp;
                    g_wlan_profile[g_wlan_display_context.infra_prof_num ]->priority = g_wlan_display_context.infra_prof_num + 1;
                    g_wlan_display_context.infra_prof_num++;
                    g_wlan_display_context.adhoc_prof_num--;
                }
            }
            else /* Infrastructure -> adhoc */
            {
                if(active_profile->priority == g_wlan_display_context.infra_prof_num)
                {
                    g_wlan_display_context.infra_prof_num--;
                    g_wlan_display_context.adhoc_prof_num++;
                }
                else
                {
                    temp = active_profile;
                    for(j = (g_wlan_prof_list[i].priority); j < g_wlan_display_context.infra_prof_num; j++)
                    {
                        g_wlan_profile[j-1] = g_wlan_profile[j];
                        g_wlan_profile[j]->priority--;
                    }
                    g_wlan_profile[g_wlan_display_context.infra_prof_num - 1] = temp;
                    g_wlan_profile[g_wlan_display_context.infra_prof_num - 1]->priority = g_wlan_display_context.infra_prof_num;
                    g_wlan_display_context.infra_prof_num--;
                    g_wlan_display_context.adhoc_prof_num++;
                }
            }
        }
    }

    /*if (g_wlan_display_context.state == WLAN_STATE_CONNECTED &&
        g_wlan_display_context.active_wlan_profile_p == g_wlan_display_context.connected_wlan_profile)
    {
        mmi_wlan_abm_ipaddr_change_req_hdlr();
    }*/

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority > 0)
        {
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, i + 1, &g_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, &error) <
        NVRAM_MAX_WLAN_PROFILE_SIZE)
    {
        ASSERT(0);
    }
        }
    }

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_DTCNT_POPUP);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_FIND_NETWORK_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_delete_space_string
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_delete_space_string(S8 *Src, S8 *Des)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 name_len = 0;
    U8 name_len_no_space = 0;
    U8 count_space_left = 0;
    U8 count_space_right = 0;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    name_len = mmi_ucs2strlen((PS8)Src)* ENCODING_LENGTH;

    /* get left space count */
    for(i = 0; i < name_len; i+=2)
    {
        if((Src[i] == 0x20) &&(Src[i+1] == 0))
        {
            count_space_left++;
        }
        else
        {
            break;
        }
    }

    /* get right space count */
    for(i = (name_len - 1); i > 0; i -= 2)
    {
        if((Src[i-1] == 0x20) &&(Src[i] == 0))
        {
            count_space_right++;
        }
        else
        {
            break;
        }
    }

    name_len_no_space = name_len - (count_space_left * ENCODING_LENGTH) - (count_space_right * ENCODING_LENGTH);

    /* delete the space both left and right */
    for(i = 0; i < name_len_no_space; i++)
    {
        Des[i] = Src[(count_space_left* ENCODING_LENGTH)+i];
    }

    Des[name_len_no_space] = 0;
    Des[name_len_no_space + 1] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_entry_confirm(STR_GLOBAL_SAVE, mmi_wlan_network_edit_save_yes, mmi_wlan_network_edit_save_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S8 buffer[10]; */
    U8 *pString = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Network Name Caption */
    SetInlineItemCaption(&wgui_inline_items[WLAN_NETWORK_EDIT_NAME_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_NAME));

    /* Network Name */
    SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_NAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NAME],
        STR_ID_DTCNT_WLAN_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.name),
        MAX_WLAN_PROF_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_NETWORK_EDIT_NAME], DataAccountFullLineEditScreen);

    /* SSID Caption */
    SetInlineItemCaption(&wgui_inline_items[WLAN_NETWORK_EDIT_SSID_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_SSID));

    /* SSID */
    SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_SSID], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_NETWORK_EDIT_SSID],
        STR_ID_DTCNT_WLAN_SSID,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.ssid_str),
        MAX_SSID_LEN,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_NETWORK_EDIT_SSID], DataAccountFullLineEditScreen);

    /* Operation Mode Caption */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NETWORK_TYPE_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));

    switch (g_wlan_display_context.network_type)
    {
        case WLAN_NETWORK_TYPE_INFRA:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            break;
        case WLAN_NETWORK_TYPE_ADHOC:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            break;
    }

    /* Operation Mode */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NETWORK_TYPE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NETWORK_TYPE],
        (U8*) pString);

    /* Channel Caption */
    /*SetInlineItemCaption(&wgui_inline_items[WLAN_NETWORK_EDIT_CHANNEL_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_ADHOC_CHANNEL));*/

    /* Populate Channel List Here */
    /*for(i = 0; i < MAX_CHANNEL_NUMBER; i++)
    {
        sprintf(buffer, "%d", i + 1);
        mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
        subMenuDataPtrs[i] = subMenuData[i];
    }*/
    
    /* Channel */
    /*SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_CHANNEL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_NETWORK_EDIT_CHANNEL],
        (S32) MAX_CHANNEL_NUMBER,
        (U8 **) subMenuDataPtrs,
        (S32*) & g_wlan_display_context.channel_number);
    if(g_wlan_display_context.network_type != WLAN_NETWORK_TYPE_ADHOC)
    {
        DisableInlineItem(&wgui_inline_items[WLAN_NETWORK_EDIT_CHANNEL], WLAN_NETWORK_EDIT_CHANNEL);
    } */           

    switch (g_wlan_display_context.auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
            break;
        case WLAN_AUTH_MODE_SHARED:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED);
            break;
        case WLAN_AUTH_MODE_IEEE8021X:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_IEEE8021X);
            break;
        case WLAN_AUTH_MODE_WPA:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA);
            break;
        case WLAN_AUTH_MODE_WPAPSK:
            if(g_wlan_display_context.network_type == WLAN_NETWORK_TYPE_ADHOC)
            {
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPANONE);
            }
            else 
            {
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPAPSK);
            }
            break;
    }

    /* Authentication Mode Caption */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_NETWORK_EDIT_AUTH_MODE_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE));

    /* Authentication Mode */
    SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_AUTH_MODE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_AUTH_MODE],
        (U8*)pString);

    switch (g_wlan_display_context.encrypt_mode)
    {
        case WLAN_ENCRYPT_MODE_NONE:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_NONE);
            break;
        case WLAN_ENCRYPT_MODE_WEP:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WEP);
            break;
        case WLAN_ENCRYPT_MODE_TKIP:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_TKIP);
            break;
        case WLAN_ENCRYPT_MODE_AES:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_AES);
            break;
    }
    
    /* Encryption Mode Caption */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_NETWORK_EDIT_ENCRYPT_MODE_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE));

    /* Encryption Mode */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_ENCRYPT_MODE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_ENCRYPT_MODE],
        (U8*) pString);

    /* Security Settings */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
        (U8*) GetString(STR_ID_DTCNT_WLAN_SECURITY_SETTINGS));

    /* TCP/IP Settings */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_TCPIP_SETTINGS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_TCPIP_SETTINGS],
        (U8*) GetString(STR_ID_DTCNT_WLAN_TCPIP_SETTINGS));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_network_edit
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_network_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_NETWORK_EDIT;
    h.entryFuncPtr = mmi_wlan_entry_network_edit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_edit
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;
    U16 inline_icon_list[WLAN_NETWORK_EDIT_INLINE_TOTAL] =
        {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0, IMG_GLOBAL_L3, 0, IMG_GLOBAL_L4, 0, IMG_GLOBAL_L5, 0, 
            IMG_GLOBAL_L6, IMG_GLOBAL_L7};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_EDIT, mmi_wlan_exit_network_edit, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_NETWORK_EDIT, &inputBufferSize);        /* added for inline edit history */

    SetParentHandler(SCR_ID_DTCNT_WLAN_NETWORK_EDIT);
    mmi_wlan_network_edit_fill_inline_struct();

    RegisterHighlightHandler(mmi_wlan_network_edit_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_NETWORK_EDIT_INLINE_TOTAL, inputBuffer);
    }

    if (GetInlineDoneFlag(guiBuffer) == 0 && g_wlan_display_context.modified == TRUE)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    if (g_wlan_display_context.insert_mode == TRUE && g_wlan_display_context.active_wlan_profile_p->ssid_len > 0)
    {
        wgui_inline_list_menu_changed = 1;
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_NETWORK_EDIT_INLINE_TOTAL,
        inline_icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_network_edit_save, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_network_edit
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_network_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mmi_wlan_profile_struct *active_profile;
    char buf[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_wlan_display_context.insert_mode)
    {
        if (g_wlan_display_context.state == WLAN_STATE_CONNECTED &&
        g_wlan_profile[g_wlan_display_context.active_wlan_profile_index] == g_wlan_display_context.connected_wlan_profile)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_EDIT),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }

        g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[g_wlan_display_context.active_wlan_profile_index];
    }

    active_profile = g_wlan_display_context.active_wlan_profile_p;
    
    memset(g_wlan_display_context.ssid_str, 0, MAX_SSID_LEN * ENCODING_LENGTH);

    if (active_profile->ssid_len > 0)
    {
        mmi_asc_n_to_ucs2(
            (PS8) g_wlan_display_context.ssid_str,
            (PS8) active_profile->ssid,
            active_profile->ssid_len);
    }

    g_wlan_display_context.network_type = active_profile->network_type;
    g_wlan_display_context.auth_mode = active_profile->auth_mode;
    g_wlan_display_context.encrypt_mode = active_profile->encrypt_mode;
    g_wlan_display_context.wep_key_index = active_profile->wep_key_index;
    g_wlan_display_context.wep_key_len = active_profile->wep_key_len;
    g_wlan_display_context.wep_key_format = active_profile->wep_key_format;
    g_wlan_display_context.auth_type1 = active_profile->auth_type1;
    g_wlan_display_context.eap_peap_auth_type = active_profile->eap_peap_auth_type;
    g_wlan_display_context.eap_ttls_auth_type = active_profile->eap_ttls_auth_type;

    g_wlan_display_context.channel_number = (S32)active_profile->channel;
    
    g_wlan_display_context.use_anonymous = active_profile->use_anonymous;
    g_wlan_display_context.use_dhcp = active_profile->use_dhcp;
    memcpy(g_wlan_display_context.ip_addr, active_profile->ip_addr, 4);
    memcpy(g_wlan_display_context.netmask, active_profile->netmask, 4);
    memcpy(g_wlan_display_context.gateway, active_profile->gateway, 4);
    memcpy(g_wlan_display_context.dns1, active_profile->dns1, 4);
    memcpy(g_wlan_display_context.dns2, active_profile->dns2, 4);

    mmi_ucs2cpy((PS8)g_wlan_display_context.name, (PS8)active_profile->name);

    if(active_profile->peap_version & SUPC_PHASE1_PEAP_0)
    {
        g_wlan_display_context.allow_peap0 = TRUE;
    }
    else
    {
        g_wlan_display_context.allow_peap0 = FALSE;
    }

    if(active_profile->peap_version & SUPC_PHASE1_PEAP_1)
    {
        g_wlan_display_context.allow_peap1 = TRUE;
    }
    else
    {
        g_wlan_display_context.allow_peap1 = FALSE;
    }


    /* Copy psk to passphrase incase psk is set by ota or hex format */
    memset(g_wlan_display_context.passphrase, 0, MAX_PASSPHRASE_LEN + 1);
    if(strlen((char *)active_profile->passphrase) == 0 && active_profile->psk[32] != 0)
    {
        
        for(i = 0; i < 32; i++)
        {
            sprintf(buf, "%02x", active_profile->psk[i]);
            strcat((char *)g_wlan_display_context.passphrase, buf);
        }
    }
    else if(strlen((char *)active_profile->passphrase) > 0)
    {
        strcpy((char*)g_wlan_display_context.passphrase, (const char*)active_profile->passphrase);
    }

#ifdef __CERTMAN_SUPPORT__
    memset(g_wlan_display_context.client_user_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->client_ca_id, g_wlan_display_context.client_user_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
    memset(g_wlan_display_context.root_ca_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->root_ca_id, g_wlan_display_context.root_ca_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
    /*memset(g_wlan_display_context.private_key_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->private_key_id, g_wlan_display_context.private_key_name, MAX_USERNAME_LEN *ENCODING_LENGTH);*/

    g_wlan_display_context.client_ca_id = active_profile->client_ca_id;
    g_wlan_display_context.root_ca_id = active_profile->root_ca_id;
    /*g_wlan_display_context.private_key_id = active_profile->private_key_id;*/
#else
    memset(g_wlan_display_context.client_ca_path, 0, FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy(g_wlan_display_context.client_ca_path, (S8*) active_profile->client_ca_path);
    memset(g_wlan_display_context.root_ca_path, 0, FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy(g_wlan_display_context.root_ca_path, (S8*) active_profile->root_ca_path);
    memset(g_wlan_display_context.private_key_path, 0, FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy(g_wlan_display_context.private_key_path, (S8*) active_profile->private_key_path);
#endif /* __CERTMAN_SUPPORT__ */
    memset(g_wlan_display_context.wep_key_str, 0, MAX_WEP_KEYSTR_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->wep_key) > 0)
    {
        mmi_asc_n_to_ucs2(
            (PS8) g_wlan_display_context.wep_key_str,
            (PS8) active_profile->wep_key,
            strlen((const char*)active_profile->wep_key));
    }

    memset(g_wlan_display_context.private_key_passwd_str, 0, MAX_PASSWORD_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->private_key_passwd) > 0)
    {
        mmi_asc_n_to_ucs2(
            (PS8) g_wlan_display_context.private_key_passwd_str,
            (PS8) active_profile->private_key_passwd,
            strlen((const char*)active_profile->private_key_passwd));
    }

    memset(g_wlan_display_context.username_str, 0, MAX_USERNAME_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->username) > 0)
    {
        mmi_asc_n_to_ucs2(
            (PS8) g_wlan_display_context.username_str,
            (PS8) active_profile->username,
            strlen((const char*)active_profile->username));
    }

    memset(g_wlan_display_context.password_str, 0, MAX_PASSWORD_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->password) > 0)
    {
        mmi_asc_n_to_ucs2(
            (PS8) g_wlan_display_context.password_str,
            (PS8) active_profile->password,
            strlen((const char*)active_profile->password));
    }

    g_wlan_display_context.modified = FALSE;

    mmi_wlan_entry_network_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_settings_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[nIndex];
    g_wlan_display_context.active_wlan_profile_index = nIndex;
    
    /*if (nIndex == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_add, KEY_EVENT_UP);
    }
    else
    {
        g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[nIndex];
        g_wlan_display_context.active_wlan_profile_index = nIndex;
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_settings_opt, KEY_EVENT_UP);
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_settings_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_settings_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT, NULL, mmi_wlan_entry_network_settings_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT);

    nNumofItem = GetNumOfChild(MENU_ID_WLAN_NETWORK_SETTINGS_OPT);

    GetSequenceStringIds(MENU_ID_WLAN_NETWORK_SETTINGS_OPT, nStrItemList);

    SetParentHandler(MENU_ID_WLAN_NETWORK_SETTINGS_OPT);

    g_wlan_display_context.insert_mode = FALSE;

    g_wlan_display_context.active_wlan_profile_p = 
        g_wlan_profile[g_wlan_display_context.active_wlan_profile_index];

    if (g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED &&
        g_wlan_display_context.connected_wlan_profile == g_wlan_display_context.active_wlan_profile_p)
    {
        nStrItemList[0] = STR_ID_DTCNT_WLAN_DISCONNECT;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
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
 *  mmi_wlan_entry_network_settings
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_settings_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer = NULL;
    U8 *DataAccountName[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_list[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountName[0] = (U8*)GetString(STR_ID_DTCNT_WIFI_SEARCH);
    icon_list[0] = 0;
    icon_state[0] = 0;
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        DataAccountName[i+1] = g_wlan_profile[i]->name;

        if(g_wlan_profile[i]->network_type == WLAN_NETWORK_TYPE_ADHOC)
        {
            icon_list[i+1] = IMG_ID_DTCNT_WLAN_ADHOC;
        }
        else
        {
            if(g_wlan_profile[i]->auth_mode == WLAN_AUTH_MODE_OPEN &&
                g_wlan_profile[i]->encrypt_mode == WLAN_ENCRYPT_MODE_NONE)
            {              
                icon_list[i+1] = IMG_ID_DTCNT_WLAN_STATION;            
            }
            else
            {
                icon_list[i+1] = IMG_ID_DTCNT_WLAN_SECURED_STATION;            
            }
        }
        
        if(g_wlan_display_context.connected_wlan_profile &&
           g_wlan_profile[i]->profile_id == g_wlan_display_context.connected_wlan_profile->profile_id)
        {
            if (g_wlan_display_context.rssi > -60)
            {
                icon_state[i+1] = IMG_ID_DTCNT_WLAN_SIGNAL3;
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon_state[i+1] = IMG_ID_DTCNT_WLAN_SIGNAL2;
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon_state[i+1] = IMG_ID_DTCNT_WLAN_SIGNAL1;
            }
            else
            {
                icon_state[i+1] = IMG_ID_DTCNT_WLAN_SIGNAL0;
            }
        }
        else 
        {
            icon_state[i+1] = 0;
        }
    }

    /* Reset insert mode here */
    g_wlan_display_context.insert_mode = FALSE;

    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS, NULL, mmi_wlan_entry_network_settings_ext, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);

    if(!guiBuffer)
    {
        g_wlan_display_context.active_wlan_profile_index = 0;
    }
    
    RegisterHighlightHandler(mmi_wlan_network_settings_highlight_hdlr_ext);

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_wlan_display_context.prof_num +1,
        (U8 **) DataAccountName,
        icon_state,
        icon_list,
        g_wlan_display_context.active_wlan_profile_index,
        NULL,
        ICON_ICON_TEXT);


    if(g_wlan_display_context.prof_num == 0)
    {
        ChangeLeftSoftkey(STR_ID_DTCNT_SEARCH, 0);
    }

    SetLeftSoftkeyFunction(mmi_wlan_entry_network_search, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_network_search, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_always_ask_connnect
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_always_ask_connnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_WIFI_ALWAYS_ASK_CONNECT_PROF, g_wlan_display_context.prev_state);

    g_always_ask_screen_del_handler_flag = TRUE;
    if(g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED && !g_always_ask_connect_flag)
    { 
        g_always_ask_before_connect_flag = TRUE;
    }
    else
    {
        g_always_ask_before_connect_flag = FALSE;
    }

    if(g_wlan_display_context.prev_state != WLAN_STATE_CONNECTED)
    { 
        g_always_ask_send_cnf_flag = FALSE;
       
        mmi_dtcnt_wlan_connect_result(TRUE);
    }
    else
    {
        g_always_ask_send_cnf_flag = TRUE;
    }

    
    g_always_ask_connect_flag = TRUE;
    
    DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
    if(GetActiveScreenId() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
    {
        GoBackHistory();   
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);
    }
    
    if(g_wlan_display_context.connected_wlan_profile == g_wlan_display_context.active_wlan_profile_p)
    {
            mmi_dtcnt_wlan_connect_result(TRUE);
    }
    else
    {
    mmi_wlan_send_connect_req(g_wlan_display_context.active_wlan_profile_p);
}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_settings_highlight_hdlr_ext(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(nIndex == 0)
    {
        ChangeLeftSoftkey(STR_ID_DTCNT_SEARCH, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_search, KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_network_search, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {  
        g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[nIndex-1];
        g_wlan_display_context.active_wlan_profile_index = nIndex-1;
        ChangeLeftSoftkey(STR_ID_DTCNT_CONNECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_always_ask_connnect,KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_always_ask_connnect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_search
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_always_ask_connect_flag = TRUE;
    mmi_wlan_pre_entry_find_network();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_ap_connnect
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_ap_connnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_entry_network_connect();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_settings
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer = NULL;
    U8 *DataAccountName[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_list[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        DataAccountName[i] = g_wlan_profile[i]->name;

        if(g_wlan_profile[i]->network_type == WLAN_NETWORK_TYPE_ADHOC)
        {
            icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
        }
        else
        {
            if(g_wlan_profile[i]->auth_mode == WLAN_AUTH_MODE_OPEN &&
                g_wlan_profile[i]->encrypt_mode == WLAN_ENCRYPT_MODE_NONE)
            {              
                icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;            
            }
            else
            {
                icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;            
            }
        }
        
        if(g_wlan_display_context.connected_wlan_profile &&
           g_wlan_profile[i]->profile_id == g_wlan_display_context.connected_wlan_profile->profile_id)
        {
            if (g_wlan_display_context.rssi > -60)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
            }
            else
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
            }
        }
        else 
        {
            icon_state[i] = 0;
        }
    }

    /* Reset insert mode here */
    g_wlan_display_context.insert_mode = FALSE;

    EntryNewScreen(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS, NULL, mmi_wlan_entry_network_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);

    if(!guiBuffer)
    {
        g_wlan_display_context.active_wlan_profile_index = 0;
    }
    
    RegisterHighlightHandler(mmi_wlan_network_settings_highlight_hdlr);

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_wlan_display_context.prof_num,
        (U8 **) DataAccountName,
        icon_state,
        icon_list,
        g_wlan_display_context.active_wlan_profile_index,
        NULL,
        ICON_ICON_TEXT);

    if(g_wlan_display_context.prof_num == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_add, KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_network_add, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {  
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_settings_opt,KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_network_settings_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_conn_status_str
 * DESCRIPTION
 *  Entry connection status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_conn_status_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    U8 *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = (PU8) subMenuData;

   mmi_ucs2cpy((PS8) info, (PS8) L"Phone MAC:  ");
    if (g_wlan_display_context.state != WLAN_STATE_NULL)
    {
        sprintf(
            tempBuf,
            "%02x:%02x:%02x:%02x:%02x:%02x\n\n",
            g_wlan_display_context.mac_addr[0],
            g_wlan_display_context.mac_addr[1],
            g_wlan_display_context.mac_addr[2],
            g_wlan_display_context.mac_addr[3],
            g_wlan_display_context.mac_addr[4],
            g_wlan_display_context.mac_addr[5]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);
    }
    else
    {
        mmi_ucs2cat((PS8) info, GetString(STR_GLOBAL_NOT_AVAILABLE));
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
    }

    if (g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SSID));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(tempBufUnicode, (PS8) g_wlan_display_context.ssid, g_wlan_display_context.ssid_len);
        mmi_ucs2cat((PS8) info, tempBufUnicode);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        mmi_ucs2cat((PS8)info, (PS8)L"BSSID:  ");
        sprintf(tempBuf, "%02x:%02x:%02x:%02x:%02x:%02x\n\n", g_wlan_display_context.bssid[0], g_wlan_display_context.bssid[1],
        g_wlan_display_context.bssid[2], g_wlan_display_context.bssid[3], g_wlan_display_context.bssid[4],
        g_wlan_display_context.bssid[5]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8)info, tempBufUnicode);
        
        mmi_ucs2cat((PS8)info, GetString(STR_ID_DTCNT_WLAN_CHANNEL));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(tempBuf, "%d\n\n", g_wlan_display_context.curr_channel_number);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8)info, tempBufUnicode);

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_STRENGTH));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        if (g_wlan_display_context.rssi > -40)
        {
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL0));
        }
        else if (g_wlan_display_context.rssi > -60)
        {
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL1));
        }
        else if (g_wlan_display_context.rssi > -70)
        {
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL2));
        }
        else if (g_wlan_display_context.rssi > -80)
        {
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL3));
        }
        else
        {
            mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL4));
        }
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_LINK_SPEED));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(tempBuf, "%d Mbit/s\n\n", g_wlan_display_context.current_data_rate / 2);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_IPADDR));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_ip_addr[0],
            g_wlan_display_context.curr_ip_addr[1],
            g_wlan_display_context.curr_ip_addr[2],
            g_wlan_display_context.curr_ip_addr[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_NETMASK));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_netmask[0],
            g_wlan_display_context.curr_netmask[1],
            g_wlan_display_context.curr_netmask[2],
            g_wlan_display_context.curr_netmask[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_GATEWAY));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_gateway[0],
            g_wlan_display_context.curr_gateway[1],
            g_wlan_display_context.curr_gateway[2],
            g_wlan_display_context.curr_gateway[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_DNS1));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_dns1[0],
            g_wlan_display_context.curr_dns1[1],
            g_wlan_display_context.curr_dns1[2],
            g_wlan_display_context.curr_dns1[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);

        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_WLAN_DNS2));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n",
            g_wlan_display_context.curr_dns2[0],
            g_wlan_display_context.curr_dns2[1],
            g_wlan_display_context.curr_dns2[2],
            g_wlan_display_context.curr_dns2[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((PS8) info, tempBufUnicode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_conn_status
 * DESCRIPTION
 *  Entry connection status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_conn_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_CONN_STATUS, NULL, mmi_wlan_entry_conn_status, NULL);

    if (IsBackHistory)
    {
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_CONN_STATUS);
    }
    else
    {
        guiBuffer = NULL; 
    }

    mmi_wlan_update_conn_status_str();

    ShowCategory74Screen(
        STR_ID_DTCNT_WLAN_CONN_STATUS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_tcpip_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_tcpip_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* mmi_wlan_entry_confirm(STR_GLOBAL_SAVE, mmi_wlan_tcpip_settings_save_yes, mmi_wlan_tcpip_settings_save_no); */
    U8 i;
    U8 StrDigit[MAX_IPADDRES_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.use_dhcp == TRUE)
    {
        memset(g_wlan_display_context.ip_addr, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.netmask, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.gateway, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.dns1, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.dns2, 0, MAX_IPADDRES_LEN);
    }
    else
    {
        for (i = 0; i < MAX_IPADDRES_LEN; i++)
        {
            mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_wlan_display_context.ip_addr_str[i]);
            g_wlan_display_context.ip_addr[i] = (U8) atoi((S8*) StrDigit);

            mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_wlan_display_context.netmask_str[i]);
            g_wlan_display_context.netmask[i] = (U8) atoi((S8*) StrDigit);

            mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_wlan_display_context.gateway_str[i]);
            g_wlan_display_context.gateway[i] = (U8) atoi((S8*) StrDigit);

            mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_wlan_display_context.dns1_str[i]);
            g_wlan_display_context.dns1[i] = (U8) atoi((S8*) StrDigit);

            mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_wlan_display_context.dns2_str[i]);
            g_wlan_display_context.dns2[i] = (U8) atoi((S8*) StrDigit);
        }
    }

    g_wlan_display_context.modified = TRUE;

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.use_dhcp != index)
    {
        g_wlan_display_context.use_dhcp = index;
        if (g_wlan_display_context.use_dhcp)
        {
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_IPADDR], WLAN_TCPIP_IPADDR);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_NETMASK], WLAN_TCPIP_NETMASK);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_GATEWAY], WLAN_TCPIP_GATEWAY);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS1], WLAN_TCPIP_DNS1);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS2], WLAN_TCPIP_DNS2);
        }
        else
        {
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_IPADDR], WLAN_TCPIP_IPADDR);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_NETMASK], WLAN_TCPIP_NETMASK);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_GATEWAY], WLAN_TCPIP_GATEWAY);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS1], WLAN_TCPIP_DNS1);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS2], WLAN_TCPIP_DNS2);
        }

        RedrawCategoryFunction();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_tcpip_settings_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_tcpip_settings_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.yes_no_opt[0] = (U8*) GetString(STR_GLOBAL_NO);
    g_wlan_display_context.yes_no_opt[1] = (U8*) GetString(STR_GLOBAL_YES);

    /* Use DHCP */
    /* SetInlineItemActivation (&wgui_inline_items[WLAN_TCPIP_USEDHCP_STR], KEY_LSK, KEY_EVENT_UP); */
    SetInlineItemCaption(&wgui_inline_items[WLAN_TCPIP_USEDHCP_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_USE_DHCP));
    SetInlineItemActivation(&wgui_inline_items[WLAN_TCPIP_USEDHCP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_TCPIP_USEDHCP],
        2,
        g_wlan_display_context.yes_no_opt,
        &g_wlan_display_context.use_dhcp_dummy);
    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[WLAN_TCPIP_USEDHCP],
        mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr);

    /* IP Address */
    /* SetInlineItemActivation (&wgui_inline_items[WLAN_TCPIP_IPADDR_STR], KEY_LSK, KEY_EVENT_UP); */
    SetInlineItemCaption(&wgui_inline_items[WLAN_TCPIP_IPADDR_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_IPADDR));

    SetInlineItemActivation(&wgui_inline_items[WLAN_TCPIP_IPADDR], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[WLAN_TCPIP_IPADDR],
        (U8*) g_wlan_display_context.ip_addr_str[0],
        (U8*) g_wlan_display_context.ip_addr_str[1],
        (U8*) g_wlan_display_context.ip_addr_str[2],
        (U8*) g_wlan_display_context.ip_addr_str[3],
        PreparedIPAddressString);

    /* Netmask */
    /* SetInlineItemActivation (&wgui_inline_items[WLAN_TCPIP_NETMASK_STR], KEY_LSK, KEY_EVENT_UP); */
    SetInlineItemCaption(&wgui_inline_items[WLAN_TCPIP_NETMASK_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_NETMASK));

    SetInlineItemActivation(&wgui_inline_items[WLAN_TCPIP_NETMASK], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[WLAN_TCPIP_NETMASK],
        (U8*) g_wlan_display_context.netmask_str[0],
        (U8*) g_wlan_display_context.netmask_str[1],
        (U8*) g_wlan_display_context.netmask_str[2],
        (U8*) g_wlan_display_context.netmask_str[3],
        PreparedIPAddressString);

    /* Gateway */
    /* SetInlineItemActivation (&wgui_inline_items[WLAN_TCPIP_GATEWAY_STR], KEY_LSK, KEY_EVENT_UP); */
    SetInlineItemCaption(&wgui_inline_items[WLAN_TCPIP_GATEWAY_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_GATEWAY));

    SetInlineItemActivation(&wgui_inline_items[WLAN_TCPIP_GATEWAY], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[WLAN_TCPIP_GATEWAY],
        (U8*) g_wlan_display_context.gateway_str[0],
        (U8*) g_wlan_display_context.gateway_str[1],
        (U8*) g_wlan_display_context.gateway_str[2],
        (U8*) g_wlan_display_context.gateway_str[3],
        PreparedIPAddressString);

    /* Primary DNS */
    /* SetInlineItemActivation (&wgui_inline_items[WLAN_TCPIP_DNS1_STR], KEY_LSK, KEY_EVENT_UP); */
    SetInlineItemCaption(&wgui_inline_items[WLAN_TCPIP_DNS1_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_DNS1));

    SetInlineItemActivation(&wgui_inline_items[WLAN_TCPIP_DNS1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[WLAN_TCPIP_DNS1],
        (U8*) g_wlan_display_context.dns1_str[0],
        (U8*) g_wlan_display_context.dns1_str[1],
        (U8*) g_wlan_display_context.dns1_str[2],
        (U8*) g_wlan_display_context.dns1_str[3],
        PreparedIPAddressString);

    /* Secondary DNS */
    /* SetInlineItemActivation (&wgui_inline_items[WLAN_TCPIP_DNS2_STR], KEY_LSK, KEY_EVENT_UP); */
    SetInlineItemCaption(&wgui_inline_items[WLAN_TCPIP_DNS2_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_DNS2));

    SetInlineItemActivation(&wgui_inline_items[WLAN_TCPIP_DNS2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[WLAN_TCPIP_DNS2],
        (U8*) g_wlan_display_context.dns2_str[0],
        (U8*) g_wlan_display_context.dns2_str[1],
        (U8*) g_wlan_display_context.dns2_str[2],
        (U8*) g_wlan_display_context.dns2_str[3],
        PreparedIPAddressString);

    /* Disable TCP/IP settings if DHCP is used. */
    if (g_wlan_display_context.use_dhcp)
    {
        DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_IPADDR], WLAN_TCPIP_IPADDR);
        DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_NETMASK], WLAN_TCPIP_NETMASK);
        DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_GATEWAY], WLAN_TCPIP_GATEWAY);
        DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS1], WLAN_TCPIP_DNS1);
        DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS2], WLAN_TCPIP_DNS2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_tcpip_settings
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_tcpip_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_TCPIP_SETTINGS;
    h.entryFuncPtr = mmi_wlan_entry_tcpip_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_tcpip_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_tcpip_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 i, ImageLocation = 0; */
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_TCPIP_SETTINGS, mmi_wlan_exit_tcpip_settings, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_TCPIP_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_TCPIP_SETTINGS, &inputBufferSize);      /* added for inline edit history */

    SetParentHandler(MITEM_DATA_ACCOUNT_PARENT_ZERO);
    mmi_wlan_tcpip_settings_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_TCPIP_INLINE_TOTAL, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_TCPIP_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_TCPIP_INLINE_TOTAL,
        (U16*) g_wlan_display_context.icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_tcpip_settings_save, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_tcpip_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_tcpip_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.use_dhcp_dummy = g_wlan_display_context.use_dhcp;

    for (i = 0; i < MAX_IPADDRES_LEN; i++)
    {
        ReturnThreeDigitString((PU8) & g_wlan_display_context.ip_addr_str[i], g_wlan_display_context.ip_addr[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.netmask_str[i], g_wlan_display_context.netmask[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.gateway_str[i], g_wlan_display_context.gateway[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.dns1_str[i], g_wlan_display_context.dns1[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.dns2_str[i], g_wlan_display_context.dns2[i]);
    }

    mmi_wlan_entry_tcpip_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_main
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_main, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_power
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_power(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_power, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_power, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_conn_status
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_conn_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_conn_status, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_conn_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_settings
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_tcpip_settings
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_tcpip_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_pre_entry_tcpip_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_pre_entry_tcpip_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_ap_settings
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_ap_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_network_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_network_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_network_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_network_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_pre_entry_network_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_pre_entry_network_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_network_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_network_define(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_network_add, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_network_add, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_find_network_connect
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_find_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_pre_entry_find_network_connect, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_pre_entry_find_network_connect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_network_details
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_network_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_network_details, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_network_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_find_network
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_find_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_pre_entry_find_network, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_pre_entry_find_network, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_define_network
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_define_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_define_network, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_define_network, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_network_connect
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED &&
        g_wlan_display_context.connected_wlan_profile == g_wlan_display_context.active_wlan_profile_p)
    {
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_disconnect, KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_network_disconnect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_wlan_entry_network_connect, KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_network_connect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_network_priority
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_network_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_network_priority, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_network_priority, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_network_delete
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_network_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_entry_network_delete, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_network_delete, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_init_highlight_hdlr
 * DESCRIPTION
 *  Initialize all highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_init_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_WLAN_MAIN, mmi_wlan_highlight_main);
    SetHiliteHandler(MENU_ID_WLAN_SETTINGS, mmi_wlan_highlight_settings);
    SetHiliteHandler(MENU_ID_WLAN_POWER, mmi_wlan_highlight_power);
    SetHiliteHandler(MENU_ID_WLAN_CONN_STATUS, mmi_wlan_highlight_conn_status);
    SetHiliteHandler(MENU_ID_WLAN_TCPIP_SETTINGS, mmi_wlan_highlight_tcpip_settings);
    SetHiliteHandler(MENU_ID_WLAN_NETWORK_SETTINGS, mmi_wlan_highlight_ap_settings);
    SetHiliteHandler(MENU_ID_WLAN_NETWORK_SETTINGS_OPT_CONNECT, mmi_wlan_highlight_network_connect);
    SetHiliteHandler(MENU_ID_WLAN_NETWORK_SETTINGS_OPT_EDIT, mmi_wlan_highlight_network_edit);
    SetHiliteHandler(MENU_ID_WLAN_NETWORK_SETTINGS_OPT_ADD, mmi_wlan_highlight_network_define);
    SetHiliteHandler(MENU_ID_WLAN_NETWORK_SETTINGS_OPT_DELETE, mmi_wlan_highlight_network_delete);
    SetHiliteHandler(MENU_ID_WLAN_NETWORK_SETTINGS_OPT_PRIORITY, mmi_wlan_highlight_network_priority);
    SetHiliteHandler(MENU_ID_WLAN_FIND_NETWORK, mmi_wlan_highlight_find_network);
    SetHiliteHandler(MENU_ID_WLAN_FIND_NETWORK_OPT_CONNECT, mmi_wlan_highlight_find_network_connect);
    SetHiliteHandler(MENU_ID_WLAN_FIND_NETWORK_OPT_DEFINE, mmi_wlan_highlight_define_network);
    SetHiliteHandler(MENU_ID_WLAN_FIND_NETWORK_OPT_REFRESH, mmi_wlan_highlight_find_network);
    SetHiliteHandler(MENU_ID_WLAN_FIND_NETWORK_OPT_DETAILS, mmi_wlan_highlight_network_details);
    mmi_wlan_eap_init_highlight_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_signal_level_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_signal_level_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_get_active_flight_mode() != 0)
    {
        return;
    }

    if (g_wlan_display_context.prev_state != WLAN_STATE_CONNECTED)
    {
        return;
    }

    if (g_wlan_display_context.rssi > -40)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT5, FALSE);
    }
    else if (g_wlan_display_context.rssi > -60)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, FALSE);
    }
    else if (g_wlan_display_context.rssi > -70)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, FALSE);
    }
    else if (g_wlan_display_context.rssi > -80)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, FALSE);
    }
    else
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_entry_ipaddr_conflict_ind
 * DESCRIPTION
 *  Entry new message indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_entry_ipaddr_conflict_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_IPADDR_CONFILICT_IND, NULL, mmi_dtcnt_entry_ipaddr_conflict_ind, NULL);

    ShowCategory65Screen((PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_IP_CONFLICT), IMG_GLOBAL_WARNING, NULL);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(GoBackHistory, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    if ((g_wlan_display_context.notification_pending == FALSE)
        &&(g_wlan_display_context.play_tone_flag))
    {
        g_wlan_display_context.play_tone_flag = FALSE;
        playRequestedTone(WARNING_TONE);
    }
    g_wlan_display_context.notification_pending = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_need_ipaddr_conflict_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_dtcnt_need_ipaddr_conflict_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wlan_display_context.notification_pending;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_get_connected_ap_ssid
 * DESCRIPTION
 *  get connected AP's SSID
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_wlan_get_connected_ap_ssid(S8 *dest, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH] = "";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!dest || len == 0)
    {
        return FALSE;
    }

    if(g_wlan_display_context.state != WLAN_STATE_CONNECTED)
    {
        return FALSE;
    }
    
    mmi_asc_n_to_ucs2(tempBufUnicode, (PS8) g_wlan_display_context.ssid, g_wlan_display_context.ssid_len);
    mmi_ucs2ncpy(dest, tempBufUnicode, (len > g_wlan_display_context.ssid_len) ? g_wlan_display_context.ssid_len : len);
    
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_redraw_network_settings_screen
 * DESCRIPTION
 *  redraw network settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wlan_redraw_network_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    PU8 icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(GetExitScrnID() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);
    
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if(g_wlan_display_context.connected_wlan_profile &&
           g_wlan_profile[i]->profile_id == g_wlan_display_context.connected_wlan_profile->profile_id)
        {
            if (g_wlan_display_context.rssi > -60)
            {
                icon = get_image(IMG_ID_DTCNT_WLAN_SIGNAL3);
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon = get_image(IMG_ID_DTCNT_WLAN_SIGNAL2);
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon = get_image(IMG_ID_DTCNT_WLAN_SIGNAL1);
            }
            else
            {
                icon = get_image(IMG_ID_DTCNT_WLAN_SIGNAL0);
            }
        }
        else 
        {
            icon = NULL;
        }
        Category73ChangeItemIcon(i, 0, icon);
    }

    Category73RedrawScreen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_redraw_network_settings_screen
 * DESCRIPTION
 *  redraw network settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wlan_redraw_conn_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EMPTY, NULL, NULL, NULL);

    ShowCategoryDummyScreen();
    
    if(g_wlan_display_context.prev_state != WLAN_STATE_CONNECTED)        
    {
        /* Force fully redraw the screen to avoid miscalculation in the editor. */
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_CONN_STATUS);
        mmi_wlan_entry_conn_status();
        return;
    }

    GoBackHistory();
    return;
}
#endif /* __MMI_WLAN_FEATURES__ */ 


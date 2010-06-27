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
 * EmailAppOTAP.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements OTA Provisioning application of Email application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**************************************************************/

#include "MMI_include.h"
#ifndef _MMI_EMAILAPPOTAP_C
#define _MMI_EMAILAPPOTAP_C

#ifdef __MMI_EMAIL__
#include "FileMgr.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
/* micha1230 */
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "ConnectManageGProt.h"
#include "EmailAppResDef.h"
#include "EmailAppProt.h"
#include "EmailAppGProt.h"
#include "MessagesExDcl.h"
#include "MessagesResourceData.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "ProfileGprots.h"
#include "Conversions.h"
#include "app_mine.h"
#include "CommonScreens.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 
#ifdef __MMI_EMAIL_OTAP__
#include "CentralConfigAgentGProt.h"    /* CCA header */
#include "ProtocolEvents.h"


/*****************************************************************************
*variables
*****************************************************************************/
mmi_email_otap_struct *g_email_otap = NULL;
MMI_BOOL mmi_email_is_in_otap = MMI_FALSE; /*global variable: to indicate in otap process*/

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
MMI_BOOL mmi_email_is_autochk_at_otap_begin = MMI_FALSE;
#endif /*!defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)*/


/*****************************************************************************
*static functions
*****************************************************************************/
static void mmi_email_prepare_installation_screen_info(S8 *info, mmi_email_oma_profile_struct *prof);
static void mmi_email_entry_installation(void);
static void mmi_email_pre_list_profile(void);
static mmi_email_oma_proxy_node* mmi_email_new_proxy_node(void);
static mmi_email_oma_application_struct* mmi_email_new_tmp_app_node(mmi_email_otap_struct *cntx);
static void mmi_email_free_tmp_app_node(mmi_email_otap_struct *cntx);
static void mmi_email_add_proxy_node_to_tail(mmi_email_oma_proxy_node *proxy_node_to_add);
static void mmi_email_free_proxy_linklist(void);
static cca_status_enum mmi_email_proc_cca_param_proxy(const cca_core_data_struct *param, mmi_email_oma_proxy_node *proxy_node_to_add);
static cca_status_enum mmi_email_proc_cca_param_application(const cca_core_data_struct *param, mmi_email_otap_struct *cntx);
static cca_status_enum mmi_email_proc_cca_param_appaddr(const cca_core_data_struct *param, mmi_email_otap_struct *cntx);
static cca_status_enum mmi_email_proc_cca_param_appauth(const cca_core_data_struct *param, mmi_email_otap_struct *cntx);
static cca_status_enum mmi_email_add_application_to_profile(mmi_email_otap_struct *cntx);
static cca_status_enum mmi_email_add_dataacctid_to_profile(mmi_email_otap_struct *cntx);
static void mmi_email_init_oma_profile(mmi_email_oma_profile_struct *prof);
static U8 mmi_email_new_otap_profile(mmi_email_otap_struct *cntx);
static cca_status_enum mmi_email_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data);
static mmi_email_otap_struct *mmi_email_new_otap_cntx(U16 conf_id, S32 doc_hdl);
static void mmi_email_send_cca_app_configure_res(U16 conf_id, S32 doc_hdl, cca_status_enum status);
static void mmi_email_split_from(const U8* from, U8* name_buf, U8* addr_buf);
static void mmi_email_check_profile_validity(void);
static MMI_BOOL mmi_email_has_any_valid_profile(void);
static void mmi_email_free_otap_cntx(void);
static U8 mmi_email_abort_otap_app(void *dummy);
static void mmi_email_otap_stop_ps(void);
static void mmi_email_otap_get_cca_status(void);
static void mmi_email_replace_screen_lsk_handler(void);
static void mmi_email_replace_screen_rsk_handler(void);
static MMI_BOOL mmi_email_check_email_addr_validity(const U8 *email_addr);
static void mmi_email_install_screen_skip(void);
static void mmi_email_display_skip_confirm(void);
static void mmi_email_otap_confirm_screen_rsk_handler(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_prepare_for_deinit
 * DESCRIPTION
 *  This function release resource and respond to CCA before deinit Email
 *  (If plug in USB, select Mass storage, this function will be called)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_otap_prepare_for_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, NULL);
   
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE);
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE);
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);

    /* GoBackHistory(); */
    /* Send a response back to CCA and free memory. */
    mmi_email_send_cca_app_configure_res(g_email_otap->conf_id, g_email_otap->doc_hdl, CCA_STATUS_ENDKEY_PRESSED);
                   
    mmi_email_free_otap_cntx();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_prepare_installation_screen_info
 * DESCRIPTION
 *  This function prepare the information to show the profile to be install
 * PARAMETERS
 *  prof            [IN]            profile to be installed
 *  info            [IN/OUT]        buffer to storage profile info to display
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_prepare_installation_screen_info(S8 *info, mmi_email_oma_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* tmp_ucs2_buf;
    U8 tmp_ascii_str[20];
    U16 out_len;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*init*/
    tmp_ucs2_buf = NULL;
    
    /*E-Mail*/
    mmi_ucs2cpy(info, GetString(STR_EMAIL_MAIN_ID)); 
    mmi_ucs2cat(info, (S8 *)L"\n");
    
    /*Profile: 1/3*/
    mmi_ucs2cat(info, GetString(STR_ID_CCA_PROFILE)); 
    mmi_ucs2cat(info, (S8 *)L":");
    sprintf((S8 *)tmp_ascii_str, "%d/%d", (g_email_otap->profile_index+1),
        g_email_otap->num_profiles);
    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                (U8*) tmp_ascii_str,
                (U16) strlen((S8*)tmp_ascii_str),
                MMI_CHSET_ASCII,
                &out_len);
    mmi_ucs2cat(info, (S8 *)tmp_ucs2_buf);
    mmi_ucs2cat(info, (S8 *)L"\n");
    if(tmp_ucs2_buf != NULL)
    {
        OslMfree(tmp_ucs2_buf);
        tmp_ucs2_buf = NULL;
    }

    /*From*/
    if(prof->is_have_smtp == MMI_TRUE)
    {
        if(mmi_ucs2strlen((S8 *)prof->smtp_node->from))
        {
            mmi_ucs2cat(info, GetString(STR_EMAIL_FROM_ID));
            mmi_ucs2cat(info, (S8 *)L":");
            mmi_ucs2cat(info, (S8 *)L"\n");
            mmi_ucs2cat(info, (S8 *)prof->smtp_node->from);
            mmi_ucs2cat(info, (S8 *)L"\n");
        }
    
    }

    /*Outgoing Server*/
    if(prof->is_have_smtp == MMI_TRUE)
    {
        if(mmi_ucs2strlen((S8*)prof->smtp_node->server_addr))
        {
            mmi_ucs2cat(info, GetString(STR_EMAIL_OUTGOING_SERVER_ID));
            mmi_ucs2cat(info, (S8 *)L":");
            mmi_ucs2cat(info, (S8 *)L"\n");       
            mmi_ucs2cat(info, (S8 *)prof->smtp_node->server_addr);
            mmi_ucs2cat(info, (S8 *)L"\n");       
        }
    
    }

    
    /*Incoming Server*/
    if(prof->is_have_pop3_imap4 == MMI_TRUE)
    {
        if(mmi_ucs2strlen((S8*)prof->pop3_imap4_node->server_addr))
        {
            mmi_ucs2cat(info, GetString(STR_EMAIL_INCOMING_SERVER_ID));
            mmi_ucs2cat(info, (S8 *)L":");
            mmi_ucs2cat(info, (S8 *)L"\n");
            mmi_ucs2cat(info, (S8 *)prof->pop3_imap4_node->server_addr);
            mmi_ucs2cat(info, (S8 *)L"\n");
        }
    
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_install_screen_skip
 * DESCRIPTION
 *  skip the current profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_install_screen_skip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_email_otap->profile[g_email_otap->profile_index]->cca_prof_status = CCA_STATUS_SETTING_SKIPPED;
    mmi_email_next_profile();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_confirm_screen_rsk_handler
 * DESCRIPTION
 *  right softkey handler of skip confirm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_confirm_screen_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, NULL);
    GoBackHistory();
    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, mmi_email_abort_otap_app);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_display_skip_confirm
 * DESCRIPTION
 *  Display skip confirmation screen, but can goback history to this screen.
 * PARAMETERS
 *  strId           [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_display_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);

    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_CCA_SKIP_PROFILE,
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(mmi_email_install_screen_skip, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_email_otap_confirm_screen_rsk_handler, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, mmi_email_abort_otap_app);
    playRequestedTone(WARNING_TONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_oma_profile_struct *prof = NULL;
    S8 *info;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Obtain the current interesting profile which is valid. */
    while(g_email_otap->profile_index < g_email_otap->num_profiles)
    {
        if(g_email_otap->profile[g_email_otap->profile_index]->is_valid_profile == TRUE)
        {
            prof = g_email_otap->profile[g_email_otap->profile_index];
            break;
        }
        else
        {
            g_email_otap->profile_index++; /*skip a profile, so g_email_otap->profile_index++*/
        }
    }

    if (prof == NULL) 
    {        
        if(g_email_otap->cca_status != CCA_STATUS_OK) /*if one profile is installed, return OK*/
        {
            g_email_otap->cca_status = CCA_STATUS_INVALID_SETTING;
        }
        /* Now, terminate the OTAP OTA provisioning application. */
        mmi_email_otap_get_cca_status();
        mmi_email_send_cca_app_configure_res(g_email_otap->conf_id, g_email_otap->doc_hdl, g_email_otap->cca_status);
        mmi_email_free_otap_cntx();
        return;
    }

    /* Obtain a temporary buffer to show messages. */
    info = (S8 *)subMenuData; /*defined in Events.c and should include EventsGprot.h*/

    mmi_email_prepare_installation_screen_info(info, prof);
    /* 
     * Entry screen. 
     */
    EntryNewScreen(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, NULL, mmi_email_entry_installation, NULL);
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE);

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_YES,
        STR_ID_CCA_SKIP,
        IMG_GLOBAL_NO,
        (U8 *)info,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        gui_buffer);

    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_OTAP_INSTALL_PROFILE;

    SetLeftSoftkeyFunction(mmi_email_pre_list_profile, KEY_EVENT_UP);    
    SetKeyHandler(mmi_email_pre_list_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_email_display_skip_confirm, KEY_EVENT_UP);    
    SetKeyHandler(mmi_email_display_skip_confirm, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /*
     * Delete screens associated with previous profile. Clear delete screen 
     * callback temporarily to prevent from terminating app.
     */
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, NULL);
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE);
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE);  
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, mmi_email_abort_otap_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_pre_list_profile
 * DESCRIPTION
 *  if the PS have not started, start PS, else send list account profile request
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void mmi_email_pre_list_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        mmi_email_ps_list_acct_profile_req();       
    }
    else
    {
        mmi_email_ps_start_req();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_replace_screen_lsk_handler
 * DESCRIPTION
 *  left softkey handler of Profile list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_replace_screen_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_pre_entry_progressing(
            STR_EMAIL_MAIN_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*) GetString(STR_SMS_PLEASE_WAIT_ID),
            NULL,
            IMG_GLOBAL_PROGRESS,
            NULL,
            NULL,
            NULL);
    mmi_email_ps_set_acct_profile_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_replace_screen_rsk_handler
 * DESCRIPTION
 *  right softkey handler of Profile list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_replace_screen_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, NULL);
    GoBackHistory();
    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, mmi_email_abort_otap_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_prof
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern const U16 gIndexIconsImageList[];
void mmi_email_otap_entry_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrItemList[MMI_EMAIL_MAX_ACCTS];
    U16 nIconItemList[MMI_EMAIL_MAX_ACCTS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    EntryNewScreen(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, NULL, mmi_email_otap_entry_prof, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE);

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        nStrItemList[i] = (U8*) email_p->prof_info.prof_misc.acct_names[i];
        nIconItemList[i] = 0;
    }

    if (mmi_email_prof_is_activated())
    {
        nIconItemList[email_p->prof_info.act_prof.act_indx] = IMG_VICON;
        email_p->prof_info.prof_misc.curr_sel_prof = email_p->prof_info.act_prof.act_indx;
    }
    else
    {
        email_p->prof_info.prof_misc.curr_sel_prof = 0;
    }

    RegisterHighlightHandler(mmi_email_hilite_prof_list);

    ShowCategory73Screen(
        STR_EMAIL_EMAIL_ACCTS_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_YES,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_EMAIL_MAX_ACCTS,
        nStrItemList,
        (U16*) nIconItemList,
        (U16*) gIndexIconsImageList,
        (S32) email_p->prof_info.prof_misc.curr_sel_prof,
        guiBuffer,
        ICON_ICON_TEXT);

    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_OTAP_REPLACE_PROFILE;
        
    SetLeftSoftkeyFunction(mmi_email_replace_screen_lsk_handler, KEY_EVENT_UP);    
    SetKeyHandler(mmi_email_replace_screen_lsk_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_email_replace_screen_rsk_handler, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_replace_screen_rsk_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    /*
     * Delete screens associated with previous profile. Clear delete screen 
     * callback temporarily to prevent from terminating app.
     */
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, NULL);
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE);
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE);   
    DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, mmi_email_abort_otap_app);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_prof_set_acct_data
 * DESCRIPTION
 *  Filll account data to message struct for PS
 * PARAMETERS
 *  msgReq      [IN/OUT]     buffer to store account data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_otap_prof_set_acct_data(mmi_email_set_acct_profile_req_struct *msgReq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_oma_profile_struct *profile;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile = g_email_otap->profile[g_email_otap->profile_index];

    /* set active profile index */
    msgReq->acct_index = email_p->prof_info.prof_misc.curr_sel_prof + 1;
    memset(&msgReq->acct, 0, sizeof(mmi_acct_profile_struct));

    /* account name info */
    if(mmi_ucs2strlen((S8*)profile->prof_name_combined))
    {        
        msgReq->acct.acct_name_len = ENCODING_LENGTH * mmi_ucs2strlen((S8*)profile->prof_name_combined);

        memcpy(
            (void*)msgReq->acct.acct_name,
            (void*)profile->prof_name_combined,
            msgReq->acct.acct_name_len);
    }
    else
    {
        UI_character_type *curr_acct_name = email_p->prof_info.prof_misc.acct_names[email_p->prof_info.prof_misc.curr_sel_prof];
        
        msgReq->acct.acct_name_len = ENCODING_LENGTH * mmi_ucs2strlen((S8*)curr_acct_name);

        memcpy(
            (void*)msgReq->acct.acct_name,
            (void*)curr_acct_name,
            msgReq->acct.acct_name_len);
    }
    msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_LEN_FLAG;
    msgReq->acct.bit_flag |= EMAIL_ACCT_NAME_FLAG;

    /* service type */
    if(profile->is_have_dataacctid == MMI_TRUE)
    {
        /* MMI_CCA_SIM_ID_DEFAULT */
        msgReq->acct.imap_pop3_info.service_type = 
            always_ask_encode_data_account_id((U32)profile->data_acct_id, 
                        ALWAYS_ASK_SIM_INFO_DEFAULT, 0, MMI_FALSE);

        /* SIM ID known */
        if(g_email_otap->sim_id != MMI_CCA_SIM_ID_DEFAULT)
        {
            if(g_email_otap->sim_id == MMI_CCA_SIM_ID_SIM1)
            {
                msgReq->acct.imap_pop3_info.service_type = 
                    always_ask_encode_data_account_id((U32)profile->data_acct_id, 
                    ALWAYS_ASK_SIM_INFO_SIM1, 0, MMI_FALSE);
                
            }
            else if(g_email_otap->sim_id == MMI_CCA_SIM_ID_SIM2)
            {
                msgReq->acct.imap_pop3_info.service_type = 
                    always_ask_encode_data_account_id((U32)profile->data_acct_id, 
                    ALWAYS_ASK_SIM_INFO_SIM2, 0, MMI_FALSE);
            }
        }

        msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_SERVICE_TYPE_FLAG;
        msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;
    }

    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* in protocol */
    if(profile->is_have_pop3_imap4)
    {
        if(strcmp((S8*)profile->pop3_imap4_node->app_id, (S8*)"110") == 0)
        {
            msgReq->acct.imap_pop3_info.in_protocol = MMI_EMAIL_PROTOCOL_POP3;
        }
        else /*imap4*/
        {
            msgReq->acct.imap_pop3_info.in_protocol = MMI_EMAIL_PROTOCOL_IMAP4;
        }
        msgReq->acct.imap_pop3_info.bit_flag |= EMAIL_IN_PROTO_FLAG;
        /* bit flag POP3 */
        msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;
        /*set in_protocol_type to be used when update active profile*/
        g_email_otap->profile[g_email_otap->profile_index]->in_protocol_type = msgReq->acct.imap_pop3_info.in_protocol;
    }
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    /* outgoing server */
    if(profile->is_have_smtp == MMI_TRUE)
    {
        msgReq->acct.bit_flag |= EMAIL_ACCT_OUT_FLAG;
        msgReq->acct.bit_flag |= EMAIL_ACCT_OUT_ADDR_FLAG;
        
        msgReq->acct.out_address.server_name_len =
            (U8) mmi_ucs2strlen((S8*) profile->smtp_node->server_addr);
        if (msgReq->acct.out_address.server_name_len > 0)
        {
            mmi_ucs2_to_asc(
                (S8*) msgReq->acct.out_address.server_name,
                (S8*) profile->smtp_node->server_addr);
        }
        msgReq->acct.out_address.bit_flag |= EMAIL_ADDR_SERVER_FLAG;
        msgReq->acct.out_address.bit_flag |= EMAIL_ADDR_SERVER_LEN_FLAG;      
                    
        /* outgoing port */
        if(mmi_ucs2strlen((S8*)profile->smtp_node->port_nbr))
        {
            msgReq->acct.out_address.port_number =
                (U16) gui_atoi((UI_string_type) profile->smtp_node->port_nbr);
        }
        else
        {
            msgReq->acct.out_address.port_number = EMAIL_DEFAULT_SMTP_PORT;
        }
        msgReq->acct.out_address.bit_flag |= EMAIL_ADDR_PORT_FLAG;
        
        /* email address */
        msgReq->acct.smtp_info.email_addr_len = 0;
        if(mmi_ucs2strlen((S8*)profile->smtp_node->from_addr))
        {
            msgReq->acct.smtp_info.email_addr_len =
                (U8) mmi_ucs2strlen((S8*) profile->smtp_node->from_addr);
            if (msgReq->acct.smtp_info.email_addr_len)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.email_address,
                    (S8*) profile->smtp_node->from_addr);
            }
        }
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_EMAIL_ADDR_LEN_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_EMAIL_ADDR_FLAG;
        
        /* display name */
        msgReq->acct.smtp_info.charset_disp_name = MMI_CHSET_UTF8;
        msgReq->acct.smtp_info.disp_name_len = 0;
        if(strlen((S8*)profile->smtp_node->from_name))
        {
            msgReq->acct.smtp_info.disp_name_len = strlen((S8*)profile->smtp_node->from_name);
            if (msgReq->acct.smtp_info.disp_name_len)
            {
                memcpy(
                    (void*)msgReq->acct.smtp_info.display_name,
                    (void*)profile->smtp_node->from_name,
                    msgReq->acct.smtp_info.disp_name_len);
            }
        }
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_DISP_NAME_CHARSET_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_DISP_NAME_LEN_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_DISP_NAME_FLAG;
        
        /* reply-to */
        msgReq->acct.smtp_info.reply_to_addr_len =
            (U8)mmi_ucs2strlen((S8*) profile->smtp_node->rt_addr);
        if (msgReq->acct.smtp_info.reply_to_addr_len)
        {
            mmi_ucs2_to_asc(
                (S8*) msgReq->acct.smtp_info.reply_to_addr,
                (S8*) profile->smtp_node->rt_addr);
        }
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_REPLY_TO_ADDR_LEN_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_REPLY_TO_ADDR_FLAG;

            /* SMTP username */
        msgReq->acct.smtp_info.login_info.user_name_length = 0;
        if(mmi_ucs2strlen((S8*)profile->smtp_node->username))
        {
            msgReq->acct.smtp_info.login_info.user_name_length =
                (U8) mmi_ucs2strlen((S8*) profile->smtp_node->username);
            if (msgReq->acct.smtp_info.login_info.user_name_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.login_info.user_name,
                    (S8*) profile->smtp_node->username);
            }
        }
        msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_USER_LEN_FLAG;
        msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_USER_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_LOGIN_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_FLAG;
        
            /* SMTP password */
        msgReq->acct.smtp_info.login_info.pass_word_length = 0;
        if(mmi_ucs2strlen((S8*)profile->smtp_node->password))
        {
            msgReq->acct.smtp_info.login_info.pass_word_length =
                (U8) mmi_ucs2strlen((S8*) profile->smtp_node->password);
            if (msgReq->acct.smtp_info.login_info.pass_word_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.smtp_info.login_info.pass_word,
                    (S8*) profile->smtp_node->password);
            }
        }
        msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_PASS_LEN_FLAG;
        msgReq->acct.smtp_info.login_info.bit_flag |= EMAIL_LOGIN_PASS_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_LOGIN_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_FLAG;
        

        /*SMTP authentication and same flag*/
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_FLAG;
        msgReq->acct.smtp_info.bit_flag |= EMAIL_OUT_AUTH_SAME_FLAG;
        if(mmi_ucs2strlen((S8*)profile->smtp_node->username) > 0)
        {
            msgReq->acct.smtp_info.smtp_auth = MMI_TRUE;
            msgReq->acct.smtp_info.smtp_auth_same = MMI_FALSE;         
        }
        else
        {
            msgReq->acct.smtp_info.smtp_auth = MMI_FALSE;
            msgReq->acct.smtp_info.smtp_auth_same = MMI_TRUE; /*same as default*/
        }
    }

        
    if(profile->is_have_pop3_imap4)
    {
        msgReq->acct.bit_flag |= EMAIL_ACCT_IN_FLAG;
        msgReq->acct.bit_flag |= EMAIL_ACCT_IN_ADDR_FLAG;
        
        /* Incoming port */
        if(mmi_ucs2strlen((S8*)profile->pop3_imap4_node->port_nbr))
        {
            msgReq->acct.in_address.port_number =
                (U16) gui_atoi((UI_string_type) profile->pop3_imap4_node->port_nbr);
        }
        else
        {
            /* if have not port data, set default port number */
            if (msgReq->acct.imap_pop3_info.in_protocol == EMAIL_PROT_POP3)
            {
                msgReq->acct.in_address.port_number = EMAIL_DEFAULT_POP3_PORT;
            }
        #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
            else
            {
                msgReq->acct.in_address.port_number = EMAIL_DEFAULT_IMAP4_PORT;
            }
        #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */
        }
        msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_PORT_FLAG;

        /* Incoming server name */
        msgReq->acct.in_address.server_name_len = 0;
        if(mmi_ucs2strlen((S8*)profile->pop3_imap4_node->server_addr))
        {
            msgReq->acct.in_address.server_name_len =
                (U8) mmi_ucs2strlen((S8*) profile->pop3_imap4_node->server_addr);
            if (msgReq->acct.in_address.server_name_len)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.in_address.server_name,
                    (S8*) profile->pop3_imap4_node->server_addr);
            }
        }
        msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_SERVER_FLAG;
        msgReq->acct.in_address.bit_flag |= EMAIL_ADDR_SERVER_LEN_FLAG;
                   
        /* user name */
        msgReq->acct.login_info.user_name_length = 0;
        if(mmi_ucs2strlen((S8*)profile->pop3_imap4_node->username))
        {
            msgReq->acct.login_info.user_name_length =
                (U8) mmi_ucs2strlen((S8*) profile->pop3_imap4_node->username);
            if (msgReq->acct.login_info.user_name_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.login_info.user_name,
                    (S8*) profile->pop3_imap4_node->username);
            }
        }
        msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_USER_LEN_FLAG;
        msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_USER_FLAG;
        
            /* password */
        msgReq->acct.login_info.pass_word_length = 0;
        if(mmi_ucs2strlen((S8*)profile->pop3_imap4_node->password))
        {
            msgReq->acct.login_info.pass_word_length =
                (U8) mmi_ucs2strlen((S8*) profile->pop3_imap4_node->password);
            if (msgReq->acct.login_info.pass_word_length)
            {
                mmi_ucs2_to_asc(
                    (S8*) msgReq->acct.login_info.pass_word,
                    (S8*) profile->pop3_imap4_node->password);
            }
        }
        msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_PASS_LEN_FLAG;
        msgReq->acct.login_info.bit_flag |= EMAIL_LOGIN_PASS_FLAG;

        msgReq->acct.bit_flag |= EMAIL_ACCT_LOGIN_FLAG;
    }   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_prof_update_act_info
 * DESCRIPTION
 *  Update current OMA Provisioning data to active account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_otap_prof_update_act_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_oma_profile_struct *profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile = g_email_otap->profile[g_email_otap->profile_index];

    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if(profile->is_have_pop3_imap4)
    {    
        /* protocol */
        email_p->prof_info.act_prof.in_prot = profile->in_protocol_type;
        if (email_p->prof_info.prof_misc.curr_prot != profile->in_protocol_type)
        {
            mmi_email_prof_update_hint();
        }   
    }
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */

    if(profile->is_have_smtp == MMI_TRUE)
    {
        U32 tmp_len;

        tmp_len = mmi_ucs2strlen((S8*) profile->smtp_node->from_addr);
        if(tmp_len > (MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS/ENCODING_LENGTH))
        {
            tmp_len = (MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS/ENCODING_LENGTH);
        }
        
        /* email address */
        mmi_ucs2ncpy(
            (S8*) email_p->prof_info.act_prof.email_addr,
            (S8*) profile->smtp_node->from_addr,
            tmp_len);
        email_p->prof_info.act_prof.email_addr[tmp_len * ENCODING_LENGTH] = '\0';
        email_p->prof_info.act_prof.email_addr[tmp_len * ENCODING_LENGTH + 1] = '\0';      
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_stop_ps
 * DESCRIPTION
 *  Send stop request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_stop_ps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
    {
        email_p->main_info.stop_cause = EMAIL_STOP_BACK_FROM_OTHER;
        mmi_email_ps_stop_req();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_get_cca_status
 * DESCRIPTION
 *  get response cca status except press end_key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_get_cca_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*CCA_STATUS_OK:when at least 1 profile is configured successfully*/
    for(i=0; i<g_email_otap->num_profiles; i++)
    {
        if(g_email_otap->profile[i]->cca_prof_status == CCA_STATUS_OK)
        {
            g_email_otap->cca_status = CCA_STATUS_OK;
            return; 
        }
    }

    /*CCA_STATUS_INVALID_SETTING:when all received profiles are invalid*/
    j = 0;
    for(i=0; i<g_email_otap->num_profiles; i++)
    {
        if(g_email_otap->profile[i]->is_valid_profile == MMI_FALSE)
        {
            j++; 
        }
    }
    if(j == g_email_otap->num_profiles)
    {
        g_email_otap->cca_status = CCA_STATUS_INVALID_SETTING;
        return; 
    }

    /*CCA_STATUS_SETTING_SKIPPED:when all received profiles are skipped*/
    j = 0;
    for(i=0; i<g_email_otap->num_profiles; i++)
    {
        if(g_email_otap->profile[i]->cca_prof_status == CCA_STATUS_SETTING_SKIPPED)
        {
            j++; 
        }
    }
    k = 0;
    for(i=0; i<g_email_otap->num_profiles; i++)
    {
        if(g_email_otap->profile[i]->is_valid_profile == MMI_TRUE)
        {
            k++; 
        }
    }
    if(j == k)
    {
        g_email_otap->cca_status = CCA_STATUS_SETTING_SKIPPED;
        return; 
    }

    g_email_otap->cca_status = CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_next_profile
 * DESCRIPTION
 *  This function leads us to process next incoming profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Increase the index of the iterator to process next profile. */
    g_email_otap->profile_index++;


    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, NULL);
    /* Whether there is another profile needed to be installed. */
    if (g_email_otap->profile_index < g_email_otap->num_profiles) 
    {
        /* Try to install next profile. */
        mmi_email_entry_installation();
    } 
    else 
    {
        DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE);
        DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE);
        DeleteScreenIfPresent(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM);
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        GoBackHistory();
        /* Send a response back to CCA and free memory. */
        mmi_email_otap_get_cca_status();
        mmi_email_send_cca_app_configure_res(g_email_otap->conf_id, g_email_otap->doc_hdl, g_email_otap->cca_status);
                       
        mmi_email_otap_stop_ps();
        mmi_email_free_otap_cntx();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_new_proxy_node
 * DESCRIPTION
 *  This function create a PROXY node buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  the node's pointer
 *****************************************************************************/
static mmi_email_oma_proxy_node* mmi_email_new_proxy_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_oma_proxy_node *proxy_node_to_add;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* malloc the node of proxy node linklist*/
    proxy_node_to_add = (mmi_email_oma_proxy_node *)OslMalloc(sizeof(mmi_email_oma_proxy_node));
    if(proxy_node_to_add == NULL)
    {
        return NULL;
    }
    /*init the first proxy linklist node before fill CCA data*/
    memset(proxy_node_to_add->proxy_parms.proxy_id, 0, sizeof(proxy_node_to_add->proxy_parms.proxy_id));
    proxy_node_to_add->proxy_parms.data_acct_id = 10;
    proxy_node_to_add->proxy_parms.is_have_proxy_id = MMI_FALSE;
    proxy_node_to_add->proxy_parms.is_have_dataacctid = MMI_FALSE;
    proxy_node_to_add->next = NULL;

    return proxy_node_to_add;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_new_tmp_app_node
 * DESCRIPTION
 *  This function malloc a temp node to store APPLICATION information
 * PARAMETERS
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  tmp_app_node pointer
 *****************************************************************************/
static mmi_email_oma_application_struct* mmi_email_new_tmp_app_node(mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cntx->tmp_app_node != NULL)
        return cntx->tmp_app_node;
    
    /* malloc the node of proxy node linklist*/
    cntx->tmp_app_node = (mmi_email_oma_application_struct *)OslMalloc(sizeof(mmi_email_oma_application_struct));
    if(cntx->tmp_app_node == NULL)
    {
        return NULL;
    }
    /*init*/
    memset(cntx->tmp_app_node, 0, sizeof(mmi_email_oma_application_struct));

    return cntx->tmp_app_node;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_free_tmp_app_node
 * DESCRIPTION
 *  free cntx->tmp_app_node
 * PARAMETERS
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_free_tmp_app_node(mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cntx->tmp_app_node != NULL)
    {
        OslMfree(cntx->tmp_app_node);
        cntx->tmp_app_node = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_add_proxy_node_to_tail
 * DESCRIPTION
 *  This function add the PROXY node to the tail of PROXY nodes link list
 * PARAMETERS
 *  proxy_node_to_add           [IN]        node to be added
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_add_proxy_node_to_tail(mmi_email_oma_proxy_node *proxy_node_to_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_oma_proxy_node *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if not valid node, not to add to linklist*/
    if(proxy_node_to_add->proxy_parms.is_have_proxy_id == MMI_FALSE
        || proxy_node_to_add->proxy_parms.is_have_dataacctid == MMI_FALSE)
    {
        OslMfree(proxy_node_to_add);
        proxy_node_to_add = NULL;
        return;
    }
    
    p = g_email_otap->proxy_linklist;
    if(p == NULL)
    {
        g_email_otap->proxy_linklist = proxy_node_to_add;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = proxy_node_to_add;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_free_proxy_linklist
 * DESCRIPTION
 *  This function free linklist of PROXY node.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_free_proxy_linklist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_oma_proxy_node *p, *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_email_otap->proxy_linklist == NULL)
    {
        return;
    }
    else
    {
        p = g_email_otap->proxy_linklist;
        while(p != NULL)
        {
            tmp = p;
            p = p->next;
            OslMfree(tmp);
        }
        g_email_otap->proxy_linklist = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_proc_cca_param_proxy
 * DESCRIPTION
 *  This function processes the parameter of PROXY node.
 * PARAMETERS
 *  param                   [IN]            A parameter with its values
 *  proxy_node_to_add       [IN/OUT]        The buffer to store PROXY information
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_proc_cca_param_proxy(const cca_core_data_struct *param, mmi_email_oma_proxy_node *proxy_node_to_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tmp_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            if(param->values.s[0])
            {
                tmp_len = strlen((S8 *)param->values.s[0]);
                if(tmp_len > 0)
                {
                    if(tmp_len > EMAIL_MAX_PROXY_ID_LEN)
                    {
                        tmp_len = EMAIL_MAX_PROXY_ID_LEN;
                    }
                    /*have init proxy_id to all 0 in mmi_email_new_proxy_node, so no need to add '\0' at proxy_id tail*/
                    strncpy((S8 *)proxy_node_to_add->proxy_parms.proxy_id, (S8 *)param->values.s[0], tmp_len);
                    proxy_node_to_add->proxy_parms.proxy_id[tmp_len] = '\0';
                
                    proxy_node_to_add->proxy_parms.is_have_proxy_id = MMI_TRUE;
                }
            }
            break;
        case CCA_NS_DATAACCTID:
            if(param->values.i[0] == CCA_NS_VAL__INVALID)
            {
                proxy_node_to_add->proxy_parms.is_have_dataacctid = MMI_FALSE;
            }
            else if(param->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                proxy_node_to_add->proxy_parms.is_have_dataacctid = MMI_FALSE;
            }
            else
            {
                proxy_node_to_add->proxy_parms.data_acct_id = param->values.i[0];
                proxy_node_to_add->proxy_parms.is_have_dataacctid = MMI_TRUE;
            }
            break;
    
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_proc_cca_param_application
 * DESCRIPTION
 *  This function processes the parameter of APPLICATION node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_proc_cca_param_application(const cca_core_data_struct *param, mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* tmp_ucs2_buf = NULL;
    U16 out_len;
    U32 tmp_len;
         
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_APPID:
            if(param->values.s[0])
            {         
                if(strcmp((S8*)param->values.s[0], (S8*)"25") == 0)
                {
                    cntx->tmp_app_node->app_type = EMAIL_OTAP_APP_SMTP;
                }
                else if(strcmp((S8*)param->values.s[0], (S8*)"110") == 0)
                {
                    cntx->tmp_app_node->app_type = EMAIL_OTAP_APP_POP3;
                }
                else if(strcmp((S8*)param->values.s[0], (S8*)"143") == 0)
                {
                    cntx->tmp_app_node->app_type = EMAIL_OTAP_APP_IMAP4;
                }

                tmp_len = strlen((S8 *)param->values.s[0]);
                if(tmp_len > 0)
                {
                    if(tmp_len > EMAIL_APPID_LEN)
                    {
                        tmp_len = EMAIL_APPID_LEN;
                    }
                    strncpy((S8 *)cntx->tmp_app_node->app_id, (S8 *)param->values.s[0], tmp_len);
                    cntx->tmp_app_node->app_id[tmp_len] = '\0';
                }
            }
            break;
        case CCA_NS_OMA_NAME:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);

                    if(tmp_ucs2_buf != NULL)
                    {
                        tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                        if(tmp_len > EMAIL_MAX_ACCT_NAME)
                        {
                            tmp_len = EMAIL_MAX_ACCT_NAME;
                        }
                        
                        mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->prof_name, (S8 *)tmp_ucs2_buf, tmp_len);
                        cntx->tmp_app_node->prof_name[tmp_len * ENCODING_LENGTH] = '\0';
                        cntx->tmp_app_node->prof_name[tmp_len * ENCODING_LENGTH + 1] = '\0';

                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        case CCA_NS_OMA_PROVIDER_ID:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);

                    if(tmp_ucs2_buf != NULL)
                    {
                        tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                        if(tmp_len > EMAIL_MAX_ACCT_NAME)
                        {
                            tmp_len = EMAIL_MAX_ACCT_NAME;
                        }
                        
                        mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->provider_id, (S8 *)tmp_ucs2_buf, tmp_len);
                        cntx->tmp_app_node->provider_id[tmp_len * ENCODING_LENGTH] = '\0';
                        cntx->tmp_app_node->provider_id[tmp_len * ENCODING_LENGTH + 1] = '\0';

                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        case CCA_NS_OMA_TO_PROXY:
            if(param->values.s[0])
            {
                tmp_len = strlen((S8 *)param->values.s[0]);
                if(tmp_len > 0)
                {
                    if(tmp_len > EMAIL_MAX_PROXY_ID_LEN)
                    {
                        tmp_len = EMAIL_MAX_PROXY_ID_LEN;
                    }
                    strncpy((S8 *)cntx->tmp_app_node->to_proxy, (S8 *)param->values.s[0], tmp_len);
                    cntx->tmp_app_node->to_proxy[tmp_len] = '\0';
                }
            }
            break;
        case CCA_NS_OMA_FROM:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]))
                {
                    U8 from_name[EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH + 1];          /*nick name after split from*/
                    U8 from_addr[MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1];   /*email address after split from*/
                    U8* tmp_ucs2_from = NULL;
                    U8* tmp_ucs2_from_addr = NULL;
                    U8* tmp_ucs2_from_name = NULL;
                    U8* tmp_chset_from_name = NULL;

                    mmi_email_split_from((const U8 *)param->values.s[0], (U8 *)from_name, (U8 *)from_addr);
                    if(mmi_email_check_email_addr_validity((const U8 *)from_addr) == MMI_TRUE)
                    {
                        /*copy from*/
                        tmp_ucs2_from = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);
                        
                        if(tmp_ucs2_from != NULL)
                        {
                            tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_from);
                            if(tmp_len > EMAIL_ADDR_INLINE_BUFF_LEN)
                            {
                                tmp_len = EMAIL_ADDR_INLINE_BUFF_LEN;
                            }
                            mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->from, (S8 *)tmp_ucs2_from, tmp_len);
                            cntx->tmp_app_node->from[tmp_len * ENCODING_LENGTH] = '\0';
                            cntx->tmp_app_node->from[tmp_len * ENCODING_LENGTH + 1] = '\0';
                        
                            /*release tmp_ucs2_from*/
                            OslMfree(tmp_ucs2_from);
                            tmp_ucs2_from = NULL;
                        }
                        
                        /*copy from_name*/
                        if(strlen((S8*)from_name) > 0)
                        {
                            /* convert from_name from utf8 to ucs2, length ignored */
                            tmp_len = strlen((S8*)from_name);
                            tmp_ucs2_from_name = mmi_email_util_chset_to_ucs2(
                                (U8*)from_name,
                                (U16)tmp_len,
                                MMI_CHSET_UTF8,
                                &out_len);
                            /* fix from_name on ucs2 format */
                            mmi_email_util_correct_disp_name((UI_character_type*)tmp_ucs2_from_name);
                            /* convert from_name from ucs2 to utf8, length ignored */
                            tmp_len = mmi_ucs2strlen((S8*)tmp_ucs2_from_name);
                            tmp_chset_from_name = mmi_email_util_ucs2_to_chset(
                                (U8*)tmp_ucs2_from_name,
                                (U16)tmp_len,
                                MMI_CHSET_UTF8,
                                &out_len);
                            /* copy tmp_chset_from_name 
                             * to from_name & cntx->tmp_app_node->from_name, 
                             * length considered 
                             */
                            tmp_len = strlen((S8*)tmp_chset_from_name);
                            if(tmp_len > EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH)
                            {
                                tmp_len = EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH;
                            }
                            strncpy((S8*)from_name, (S8*)tmp_chset_from_name, tmp_len);
                            from_name[tmp_len] = '\0';
                            strncpy((S8 *)cntx->tmp_app_node->from_name, (S8 *)from_name, tmp_len);
                            cntx->tmp_app_node->from_name[tmp_len] = '\0';

                            OslMfree(tmp_ucs2_from_name);
                            OslMfree(tmp_chset_from_name);
                        }
                        
                        /*copy from_address*/
                        if(strlen((S8*)from_addr) > 0)
                        {
                            tmp_ucs2_from_addr = mmi_email_util_chset_to_ucs2(
                                (U8*) from_addr,
                                (U16) strlen((S8*)from_addr),
                                MMI_CHSET_UTF8,
                                &out_len);
                            
                            if(tmp_ucs2_from_addr != NULL)
                            {
                                tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_from_addr);
                                if(tmp_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
                                {
                                    tmp_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
                                }
                                mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->from_addr, (S8 *)tmp_ucs2_from_addr, tmp_len);
                                cntx->tmp_app_node->from_addr[tmp_len * ENCODING_LENGTH] = '\0';
                                cntx->tmp_app_node->from_addr[tmp_len * ENCODING_LENGTH + 1] = '\0';
                            
                                /*release tmp_ucs2_from_addr*/
                                OslMfree(tmp_ucs2_from_addr);
                                tmp_ucs2_from_addr = NULL;
                            }
                        }
                    }
                }
            }
            break;
        case CCA_NS_OMA_RT_ADDR:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);
                    
                    if(tmp_ucs2_buf != NULL)
                    {
                        if (mmi_email_util_chk_addr(tmp_ucs2_buf) == TRUE)
                        {
                            tmp_len = strlen((S8 *)param->values.s[0]);
                            if(tmp_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
                            {
                                tmp_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
                            }
                            mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->rt_addr, (S8 *)tmp_ucs2_buf, tmp_len);
                            cntx->tmp_app_node->rt_addr[tmp_len * ENCODING_LENGTH] = '\0';
                            cntx->tmp_app_node->rt_addr[tmp_len * ENCODING_LENGTH + 1] = '\0';
                        }                    
                    
                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        case CCA_NS_OMA_ADDR:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);
                    
                    if(tmp_ucs2_buf != NULL)
                    {
                        tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                        if(tmp_len > MMI_EMAIL_MAX_SERVER_NAME)
                        {
                            tmp_len = MMI_EMAIL_MAX_SERVER_NAME;
                        }                
                        mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->server_addr, (S8 *)tmp_ucs2_buf, tmp_len);
                        cntx->tmp_app_node->server_addr[tmp_len * ENCODING_LENGTH] = '\0';
                        cntx->tmp_app_node->server_addr[tmp_len * ENCODING_LENGTH + 1] = '\0';

                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;    
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_proc_cca_param_appaddr
 * DESCRIPTION
 *  This function processes the parameter of APPADDR node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_proc_cca_param_appaddr(const cca_core_data_struct *param, mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8* tmp_ucs2_buf;
    U16 out_len;
    U32 tmp_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = cntx->num_profiles - 1;

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_ADDR:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);

                    if(tmp_ucs2_buf != NULL)
                    {
                        if (mmi_email_util_is_server_vaild((S8*)tmp_ucs2_buf) == MMI_TRUE)
                        {
                            tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                            if(tmp_len > MMI_EMAIL_MAX_SERVER_NAME)
                            {
                                tmp_len = MMI_EMAIL_MAX_SERVER_NAME;
                            }                
                            mmi_ucs2ncpy((S8 *)cntx->tmp_app_node->server_addr, (S8 *)tmp_ucs2_buf, tmp_len);
                            cntx->tmp_app_node->server_addr[tmp_len * ENCODING_LENGTH] = '\0';
                            cntx->tmp_app_node->server_addr[tmp_len * ENCODING_LENGTH + 1] = '\0';
                        }
                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        case CCA_NS_OMA_ADDRTYPE:
            if(param->values.i[0] == CCA_NS_VAL__INVALID)
            {
                return CCA_STATUS_FAIL;
            }
            else if(param->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                cntx->curr_node->server_addr_type = CCA_NS_VAL_IPV4;
            }
            else
            {
                cntx->curr_node->server_addr_type = param->values.i[0];
            }
            break;
        case CCA_NS_OMA_PORTNBR:
            if(param->values.s[0])
            {
                U8 i;
                S32 tmp_portnbr;
                MMI_BOOL is_portnbr_valid = MMI_TRUE;

                if(strlen(param->values.s[0]) == 0)
                {
                    is_portnbr_valid = MMI_FALSE;
                }
                else
                {
                    if(strlen(param->values.s[0]) > 5) /*1~65535, strlen("65535")is 5*/
                    {
                        is_portnbr_valid = MMI_FALSE;
                        break; /*discard PORTNBR*/
                    }
                    
                    for(i=0; i<strlen(param->values.s[0]); i++)
                    {
                        if(param->values.s[0][i] < '0' || param->values.s[0][i] > '9')
                        {
                            is_portnbr_valid = MMI_FALSE;
                            break;
                        }
                    }
                }

                if(is_portnbr_valid == MMI_TRUE)
                {            
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);

                    if(tmp_ucs2_buf != NULL)
                    {
                        tmp_portnbr = gui_atoi((UI_string_type) tmp_ucs2_buf);
                        if(tmp_portnbr > 0 && tmp_portnbr < 65536)
                        {
                            tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                            if(tmp_len > EMAIL_MAX_PROF_PORT_LEN)
                            {
                                tmp_len = EMAIL_MAX_PROF_PORT_LEN;
                            }
                            mmi_ucs2ncpy((S8 *)cntx->curr_node->port_nbr, (S8 *)tmp_ucs2_buf, tmp_len);
                            cntx->curr_node->port_nbr[tmp_len * ENCODING_LENGTH] = '\0';
                            cntx->curr_node->port_nbr[tmp_len * ENCODING_LENGTH + 1] = '\0';
                        }                    

                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        case CCA_NS_OMA_SERVICE:
            if(param->values.i[0] == CCA_NS_VAL__INVALID)
            {
                return CCA_STATUS_FAIL;
            }
            else if(param->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                cntx->curr_node->service= CCA_NS_VAL_CL_WSP;
            }
            else
            {
                cntx->curr_node->service= param->values.i[0];
            }
            break;  
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_proc_cca_param_appauth
 * DESCRIPTION
 *  This function processes the parameter of APPAUTH.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_proc_cca_param_appauth(const cca_core_data_struct *param, mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* tmp_ucs2_buf;
    U16 out_len;
    U32 tmp_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_AAUTHTYPE:
            if(param->values.i[0] == CCA_NS_VAL__INVALID)
            {
                return CCA_STATUS_FAIL;
            }
            else if(param->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                cntx->curr_node->server_addr_type = CCA_NS_VAL_HTTP_BASIC;
            }
            else
            {
                cntx->curr_node->server_addr_type = param->values.i[0];
            }
            break;
        case CCA_NS_OMA_AAUTHNAME:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);
                    
                    if(tmp_ucs2_buf != NULL)
                    {
                        if(mmi_email_util_is_username_vaild((S8*) tmp_ucs2_buf))
                        {
                            tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                            if(tmp_len > MMI_EMAIL_USR_MAX_LEN)
                            {
                                tmp_len = MMI_EMAIL_USR_MAX_LEN;
                            }                
                            mmi_ucs2ncpy((S8 *)cntx->curr_node->username, (S8 *)tmp_ucs2_buf, tmp_len);
                            cntx->curr_node->username[tmp_len * ENCODING_LENGTH] = '\0';
                            cntx->curr_node->username[tmp_len * ENCODING_LENGTH + 1] = '\0';
                        }

                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        case CCA_NS_OMA_AAUTHSECRET:
            if(param->values.s[0])
            {
                if(strlen((S8*)param->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = mmi_email_util_chset_to_ucs2(
                            (U8*) param->values.s[0],
                            (U16) strlen((S8*)param->values.s[0]),
                            MMI_CHSET_UTF8,
                            &out_len);
                    
                    if(tmp_ucs2_buf != NULL)
                    {
                        if(mmi_email_util_is_password_valid((S8*) tmp_ucs2_buf))
                        {
                            tmp_len = mmi_ucs2strlen((S8 *)tmp_ucs2_buf);
                            if(tmp_len > MMI_EMAIL_PASS_MAX_LEN)
                            {
                                tmp_len = MMI_EMAIL_PASS_MAX_LEN;
                            }                 
                            mmi_ucs2ncpy((S8 *)cntx->curr_node->password, (S8 *)tmp_ucs2_buf, tmp_len);
                            cntx->curr_node->password[tmp_len * ENCODING_LENGTH] = '\0';
                            cntx->curr_node->password[tmp_len * ENCODING_LENGTH + 1] = '\0';
                        }
                        
                        /*release tmp_ucs2_buf*/
                        OslMfree(tmp_ucs2_buf);
                        tmp_ucs2_buf = NULL;
                    }
                }
            }
            break;
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }
    return CCA_STATUS_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_email_add_application_to_profile
 * DESCRIPTION
 *  This function add tmp_app_node to a profile
 * PARAMETERS
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_add_application_to_profile(mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index, i;
    MMI_BOOL is_inserted = FALSE;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = cntx->num_profiles - 1;
    
    switch(cntx->tmp_app_node->app_type)
    {
        case EMAIL_OTAP_APP_SMTP:
            if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->from) && mmi_ucs2strlen((S8*)cntx->tmp_app_node->server_addr))
            {
                for(i=0; i<cntx->num_profiles; i++)
                {
                    if(cntx->profile[i]->is_have_smtp == MMI_FALSE
                        && cntx->profile[i]->is_have_pop3_imap4 == MMI_FALSE)
                    {
                        memcpy(cntx->profile[i]->smtp_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                        cntx->profile[i]->is_have_smtp = MMI_TRUE;
                        is_inserted = TRUE;
                        strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                        (S8*)cntx->tmp_app_node->to_proxy);
                        if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->prof_name))
                        {
                            mmi_ucs2cpy((S8*)cntx->profile[i]->prof_name_combined,
                                        (S8*)cntx->tmp_app_node->prof_name);
                        }
                        break;
                    }
                    else if(cntx->profile[i]->is_have_smtp == MMI_FALSE
                        && cntx->profile[i]->is_have_pop3_imap4 == MMI_TRUE)
                    {
                        if(mmi_ucs2cmp((S8*)cntx->tmp_app_node->provider_id,
                            (S8*)cntx->profile[i]->pop3_imap4_node->provider_id) == 0)
                        {
                            /*set prof_name_combined*/
                            if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->prof_name))
                            {
                                /*if have pop3/imap4 name, replace it*/
                                memset(cntx->profile[i]->prof_name_combined, 0, EMAIL_MAX_ACCT_NAME * ENCODING_LENGTH);
                                mmi_ucs2cpy((S8*)cntx->profile[i]->prof_name_combined,
                                        (S8*)cntx->tmp_app_node->prof_name);
                            }
                            
                            /*set to_proxy_combined*/
                            if (!strlen((S8*) cntx->tmp_app_node->to_proxy))
                            {
                                memcpy(cntx->profile[i]->smtp_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                                cntx->profile[i]->is_have_smtp = MMI_TRUE;
                                is_inserted = TRUE;
                                strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                    (S8*)cntx->profile[i]->pop3_imap4_node->to_proxy);
                                break;
                            }
                            else if (!strlen((S8*) cntx->profile[i]->pop3_imap4_node->to_proxy))
                            {
                                memcpy(cntx->profile[i]->smtp_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                                cntx->profile[i]->is_have_smtp = MMI_TRUE;
                                is_inserted = TRUE;
                                strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                    (S8*)cntx->tmp_app_node->to_proxy);
                                break;
                            }
                            else /*both have to_proxy*/
                            {
                                if(strcmp((S8*)cntx->tmp_app_node->to_proxy, (S8*)cntx->profile[i]->pop3_imap4_node->to_proxy) == 0)
                                {
                                    memcpy(cntx->profile[i]->smtp_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                                    cntx->profile[i]->is_have_smtp = MMI_TRUE;
                                    is_inserted = TRUE;
                                    strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                        (S8*)cntx->tmp_app_node->to_proxy);
                                    break;
                                }
                            }
                        }
                    }
                }
                
                if(is_inserted == FALSE && cntx->num_profiles < MMI_EMAIL_OTAP_MAX_PROFILE_NUM)
                {
                    /*create a new profile*/
                    mmi_email_new_otap_profile(cntx);
                    index = cntx->num_profiles - 1;

                    memcpy(cntx->profile[index]->smtp_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                    cntx->profile[index]->is_have_smtp = MMI_TRUE;
                    is_inserted = TRUE;
                    strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                            (S8*)cntx->tmp_app_node->to_proxy);
                    mmi_ucs2cpy((S8*)cntx->profile[i]->prof_name_combined,
                                        (S8*)cntx->tmp_app_node->prof_name);
                }
            }
            break;
        case EMAIL_OTAP_APP_POP3:
        case EMAIL_OTAP_APP_IMAP4:
            is_inserted = FALSE;
            if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->server_addr)  &&
                mmi_ucs2strlen((S8*)cntx->tmp_app_node->username))
            {
                 for(i=0; i<cntx->num_profiles; i++)
                {
                    if(cntx->profile[i]->is_have_smtp == MMI_FALSE
                        && cntx->profile[i]->is_have_pop3_imap4 == MMI_FALSE)
                    {
                        memcpy(cntx->profile[i]->pop3_imap4_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                        cntx->profile[i]->is_have_pop3_imap4 = MMI_TRUE;
                        is_inserted = TRUE;
                        strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                (S8*)cntx->tmp_app_node->to_proxy);
                        if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->prof_name))
                        {
                            mmi_ucs2cpy((S8*)cntx->profile[i]->prof_name_combined,
                                    (S8*)cntx->tmp_app_node->prof_name);
                        }
                        break;
                    }
                    else if(cntx->profile[i]->is_have_smtp == MMI_TRUE
                        && cntx->profile[i]->is_have_pop3_imap4 == MMI_FALSE)
                    {
                        if(mmi_ucs2cmp((S8*)cntx->tmp_app_node->provider_id,
                            (S8*)cntx->profile[i]->smtp_node->provider_id) == 0)
                        {
                            /*set prof_name_combined*/
                            if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->prof_name)
                                && !mmi_ucs2strlen((S8*)cntx->profile[i]->prof_name_combined))
                            {
                                mmi_ucs2cpy((S8*)cntx->profile[i]->prof_name_combined,
                                        (S8*)cntx->tmp_app_node->prof_name);
                            }
                        
                            if (!strlen((S8*) cntx->tmp_app_node->to_proxy))
                            {
                                memcpy(cntx->profile[i]->pop3_imap4_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                                cntx->profile[i]->is_have_pop3_imap4 = MMI_TRUE;
                                is_inserted = TRUE;
                                strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                        (S8*)cntx->profile[i]->smtp_node->to_proxy);
                                break;
                            }
                            else if (!strlen((S8*) cntx->profile[i]->smtp_node->to_proxy))
                            {
                                memcpy(cntx->profile[i]->pop3_imap4_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                                cntx->profile[i]->is_have_pop3_imap4 = MMI_TRUE;
                                is_inserted = TRUE;
                                strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                        (S8*)cntx->tmp_app_node->to_proxy);
                                break;
                            }
                            else /*both have to_proxy*/
                            {
                                if(strcmp((S8*)cntx->tmp_app_node->to_proxy, (S8*)cntx->profile[i]->smtp_node->to_proxy) == 0)
                                {
                                    memcpy(cntx->profile[i]->pop3_imap4_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                                    cntx->profile[i]->is_have_pop3_imap4 = MMI_TRUE;
                                    is_inserted = TRUE;
                                    strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                                            (S8*)cntx->tmp_app_node->to_proxy);
                                    break;
                                }
                            }
                        }
                    }
                }
                
                if(is_inserted == FALSE && cntx->num_profiles < MMI_EMAIL_OTAP_MAX_PROFILE_NUM)
                {
                    /*create a new profile*/
                    mmi_email_new_otap_profile(cntx);
                    index = cntx->num_profiles - 1;

                    memcpy(cntx->profile[index]->pop3_imap4_node, cntx->tmp_app_node, sizeof(mmi_email_oma_application_struct));
                    cntx->profile[index]->is_have_pop3_imap4 = MMI_TRUE;
                    is_inserted = TRUE;
                    strcpy((S8*)cntx->profile[i]->to_proxy_combined,
                            (S8*)cntx->tmp_app_node->to_proxy);
                    if(mmi_ucs2strlen((S8*)cntx->tmp_app_node->prof_name))
                    {
                        mmi_ucs2cpy((S8*)cntx->profile[i]->prof_name_combined,
                                (S8*)cntx->tmp_app_node->prof_name);
                    }
                }            
            }
            break;
    }
         
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_add_dataacctid_to_profile
 * DESCRIPTION
 *  This function scan the proxy linklist, add the matched data_acct_id to Profile
 * PARAMETERS
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_add_dataacctid_to_profile(mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_email_oma_proxy_node *p;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i<cntx->num_profiles; i++)
    {
        p = cntx->proxy_linklist;
        while(p != NULL)
        {
            if(strcmp((S8*)p->proxy_parms.proxy_id, (S8*)cntx->profile[i]->to_proxy_combined)== 0)
            {
                cntx->profile[i]->data_acct_id = p->proxy_parms.data_acct_id;
                cntx->profile[i]->is_have_dataacctid = MMI_TRUE;
                break;
            }
            p = p->next;
        }
    }
             
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_init_oma_profile
 * DESCRIPTION
 *  This function initializes a email OMA profile.
 * PARAMETERS
 *  prof            [IN/OUT]           Profile to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_init_oma_profile(mmi_email_oma_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof->data_acct_id = 10;

    if(prof->smtp_node != NULL)
    {
        memset(prof->smtp_node, 0, sizeof(mmi_email_oma_application_struct));
    }
    if(prof->smtp_node != NULL)
    {
        memset(prof->pop3_imap4_node, 0, sizeof(mmi_email_oma_application_struct));
    }

    memset(prof->prof_name_combined, 0, sizeof(prof->prof_name_combined));
    memset(prof->to_proxy_combined, 0, sizeof(prof->to_proxy_combined));
    
    prof->is_have_dataacctid = MMI_FALSE;
    prof->is_have_smtp = MMI_FALSE;
    prof->is_have_pop3_imap4 = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_new_otap_profile
 * DESCRIPTION
 *  This function allocates a temporary storage for a email profile. And it will 
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx            [IN]            control block for Email OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise, 
 *  return MMI_EMAIL_OTAP_MAX_PROFILE_NUM, i.e., an invalid index.
 *****************************************************************************/
static U8 mmi_email_new_otap_profile(mmi_email_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* No more temporary profile storage. */
    if (cntx->num_profiles == MMI_EMAIL_OTAP_MAX_PROFILE_NUM) {
        return MMI_EMAIL_OTAP_MAX_PROFILE_NUM;
    }
    
    /* Obtain the index. */
    index = cntx->num_profiles;
    
    /* Allocate memory for the profile. */
    cntx->profile[index] = (mmi_email_oma_profile_struct *)OslMalloc(sizeof(mmi_email_oma_profile_struct));
    if (cntx->profile[index] == NULL) {
        return MMI_EMAIL_OTAP_MAX_PROFILE_NUM;
    }

    cntx->profile[index]->smtp_node = (mmi_email_oma_application_struct *)OslMalloc(sizeof(mmi_email_oma_application_struct));
    cntx->profile[index]->pop3_imap4_node = (mmi_email_oma_application_struct *)OslMalloc(sizeof(mmi_email_oma_application_struct));

    /* Initialize the allocated slim VoIP profile. */
    mmi_email_init_oma_profile(cntx->profile[index]);
    cntx->profile[index]->is_valid_profile = TRUE;
        
    /* Now, we can update the number of profiles. */
    ++(cntx->num_profiles);

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum mmi_email_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_otap_struct *cntx;
    cca_core_data_struct *param;
    cca_status_enum status;
    mmi_email_oma_proxy_node *proxy_node_to_add;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_email_otap_struct *)user_data;
    
    status = CCA_STATUS_OK;             /* Initialize the status variable   */
    
    switch (symbol)
    {
        case EMAIL_OTAP_NS_PROXY:
            /* malloc the node of proxy node linklist*/
            proxy_node_to_add = mmi_email_new_proxy_node();
            if(proxy_node_to_add == NULL)
            {
                return CCA_STATUS_FAIL;
            }
                        
            /*read all the parameters of a PROXY node*/
            while (mmi_cca_doc_nodedata_next(param_list, &param) != CCA_STATUS_ENDLIST)
            {  
                status = mmi_email_proc_cca_param_proxy(param, proxy_node_to_add);  
            }

            mmi_email_add_proxy_node_to_tail(proxy_node_to_add);
            break;
            
        case EMAIL_OTAP_NS_APPLICATION:             
            /*add the pre tmp_app_node to profile[i]*/
            status = mmi_email_add_application_to_profile(cntx);
            /*reset tmp_app_node to 0*/
            memset(cntx->tmp_app_node, 0, sizeof(mmi_email_oma_application_struct));

            while (mmi_cca_doc_nodedata_next(param_list, &param) != CCA_STATUS_ENDLIST)
            { 
                status = mmi_email_proc_cca_param_application(param, cntx);
            }     
            break;
            
        case EMAIL_OTAP_NS_APPADDR:
            /*add in curr_node*/
            cntx->curr_node = cntx->tmp_app_node;
            if(cntx->curr_node != NULL)
            {
                while (mmi_cca_doc_nodedata_next(param_list, &param) != CCA_STATUS_ENDLIST)
                { 
                    status = mmi_email_proc_cca_param_appaddr(param, cntx);
                }
            }
            break;

        case EMAIL_OTAP_NS_APPAUTH:
            /*add in curr_node*/
            cntx->curr_node = cntx->tmp_app_node;
            if(cntx->curr_node != NULL)
            {
                while (mmi_cca_doc_nodedata_next(param_list, &param) != CCA_STATUS_ENDLIST)
                {   
                    status = mmi_email_proc_cca_param_appauth(param, cntx);
                }
            }
            break;
        
        default:
            break;
    } 
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_new_otap_cntx
 * DESCRIPTION
 *  This function allocates and initializes the control block of Email OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static mmi_email_otap_struct *mmi_email_new_otap_cntx(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_otap_struct *cntx;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    cntx = (mmi_email_otap_struct *)OslMalloc(sizeof(mmi_email_otap_struct));
    
    /* Clear the entire structure. */
    memset(cntx, 0, sizeof(mmi_email_otap_struct));
    cntx->conf_id = conf_id;
    cntx->doc_hdl = doc_hdl;
    
    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_send_cca_app_configure_res
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of 
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  status          [IN]            Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_send_cca_app_configure_res(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_END;
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    mmi_email_is_autochk_at_otap_begin = MMI_FALSE;
#endif /*#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)*/
    mmi_email_is_in_otap = MMI_FALSE; /*reset the status flag*/

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));

    data->config_id = conf_id;
    data->hConfig   = doc_hdl;
    data->status    = status;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 * mmi_email_split_from
 * DESCRIPTION
 *  This function split from to nickname + email address
 * PARAMETERS
 *  from         [IN]         UTF8 from address
 *  name_buf     [IN/OUT]     in buffer, out UTF8 name
 *  addr_buf     [IN/OUT]     in buffer, out UTF8 email address
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_split_from(const U8* from, U8* name_buf, U8* addr_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p;
    U16 tmp_len = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((p = (U8 *)strchr((S8*)from, '<')) == NULL) /*No nickname*/
    {
        tmp_len = strlen((S8*)from);
        if(tmp_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
        {
            tmp_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
        }
        strncpy((S8*)addr_buf, (S8*)from, tmp_len);
        addr_buf[tmp_len] = '\0';
        
        name_buf[0] = '\0';
    }
    else
    {
        if(*from == '"') /* "nickname"<abc@domain.com>*/
        {
            tmp_len = p-from-2;
            if(tmp_len > EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH)
            {
                tmp_len = EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH;
            }
            strncpy((S8*)name_buf, (S8*)(from+1), tmp_len); /*not to copy " " */
            name_buf[tmp_len] = '\0';

            tmp_len = strlen((S8*)from)-strlen((S8*)name_buf)-4;
            if(tmp_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
            {
                tmp_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
            }
            strncpy((S8*)addr_buf, (S8*)(p+1), tmp_len);/*not to copy < > */
            addr_buf[tmp_len] = '\0';
        }
        else /* nickname<abc@domain.com>*/
        {
            tmp_len = p-from;
            if(tmp_len > EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH)
            {
                tmp_len = EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH;
            }
            strncpy((S8*)name_buf, (S8*)from, tmp_len);
            name_buf[tmp_len] = '\0';

            tmp_len = strlen((S8*)from)-strlen((S8*)name_buf)-2;
            if(tmp_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
            {
                tmp_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
            }
            strncpy((S8*)addr_buf, (S8*)(p+1), tmp_len);/*not to copy < > */ 
            addr_buf[tmp_len] = '\0';
        }
    }
}


/*****************************************************************************
 * FUNCTION
 * mmi_email_check_email_addr_validity
 * DESCRIPTION
 *  This function checks the validity of an email address
 * PARAMETERS
 *  email_addr  [in]     UTF8 email address
 * RETURNS
 *  if valid, return MMI_TRUE, else return MMI_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_email_check_email_addr_validity(const U8 *email_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* tmp_ucs2_addr = NULL;
    U16 out_len;
    MMI_BOOL ret_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    tmp_ucs2_addr = mmi_email_util_chset_to_ucs2(
        (U8*) email_addr,
        (U16) strlen((S8*)email_addr),
        MMI_CHSET_UTF8,
        &out_len);

    if (mmi_email_util_chk_addr(tmp_ucs2_addr) == FALSE)
    {
        ret_value = MMI_FALSE;
    }
    else
    {
        ret_value = MMI_TRUE;
    }

    if(tmp_ucs2_addr != NULL)
    {
        OslMfree(tmp_ucs2_addr);
        tmp_ucs2_addr = NULL;
    }

    return ret_value;
}



/*****************************************************************************
 * FUNCTION
 * mmi_email_check_profile_validity
 * DESCRIPTION
 *  This function checks the validity of a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_check_profile_validity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < g_email_otap->num_profiles; ++i)
    {            
        if (g_email_otap->profile[i]->is_have_smtp == MMI_FALSE
            && g_email_otap->profile[i]->is_have_pop3_imap4 == MMI_FALSE)
        {
            g_email_otap->profile[i]->is_valid_profile = MMI_FALSE;
        }        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_has_any_valid_profile
 * DESCRIPTION
 *  This function checks if there is any valid profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  if have no valid profile, return MMI_FALSE, else return MMI_TRUE
 *****************************************************************************/
static MMI_BOOL mmi_email_has_any_valid_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < g_email_otap->num_profiles; ++i)
    {
        if(g_email_otap->profile[i]->is_valid_profile)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_free_otap_cntx
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_free_otap_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Nothing to do. Return. */
    if (g_email_otap == NULL) {
        return;
    }
    
    /* Free all profiles. */
    for (i = 0; i < g_email_otap->num_profiles; ++i) {
        if(g_email_otap->profile[i] != NULL)
        {
            if(g_email_otap->profile[i]->smtp_node != NULL)
            {
                OslMfree(g_email_otap->profile[i]->smtp_node);
                g_email_otap->profile[i]->smtp_node = NULL;
            }
            if(g_email_otap->profile[i]->pop3_imap4_node != NULL)
            {
                OslMfree(g_email_otap->profile[i]->pop3_imap4_node);
                g_email_otap->profile[i]->pop3_imap4_node = NULL;
            }
            
            OslMfree(g_email_otap->profile[i]);
            g_email_otap->profile[i] = NULL;
        }
    }
    
    mmi_email_free_proxy_linklist();
    mmi_email_free_tmp_app_node(g_email_otap); /*in case of not free tmp_app_node somewhere*/
    
    /* Free the control block. */
    OslMfree(g_email_otap);
    g_email_otap = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_abort_otap_app
 * DESCRIPTION
 *  This function should be called to exit the Email OTAP application. It is 
 *  registered as a delete screen callback such that it can be called when END
 *  key is pressed to return to idle screen.
 * PARAMETERS
 *  dummy           [IN]            Dummy parameter. Always be zero.
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop 
 *  delete other nodes in history stack. Here, always return FALSE.
 *****************************************************************************/
static U8 mmi_email_abort_otap_app(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_otap_stop_ps();

    /* Terminated. Send a response back to CCA and free memory. */
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_SKIP_CONFIRM, NULL);
    mmi_email_send_cca_app_configure_res(g_email_otap->conf_id, g_email_otap->doc_hdl, CCA_STATUS_ENDKEY_PRESSED);
    mmi_email_free_otap_cntx();
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_exec_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to Email
 *  profile.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exec_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the Email settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, EMAIL_OTAP_NS_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, EMAIL_OTAP_NS_APPLICATION, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR, EMAIL_OTAP_NS_APPADDR, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH, EMAIL_OTAP_NS_APPAUTH, 0xFFFF,
    };

    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*init proxy linklist*/
    g_email_otap->proxy_linklist = NULL;

    /* Prepare a storage for the new node*/
    if ((mmi_email_new_tmp_app_node(g_email_otap)) == NULL)
    {
        mmi_email_send_cca_app_configure_res(conf_id, doc_hdl, CCA_STATUS_FAIL);
        return;
    }

    if ((mmi_email_new_otap_profile(g_email_otap)) >= MMI_EMAIL_OTAP_MAX_PROFILE_NUM)
    {
        mmi_email_send_cca_app_configure_res(conf_id, doc_hdl, CCA_STATUS_FAIL);
        return;
    }   
    
    /* Extract VoIP settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                doc_hdl, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                mmi_email_proc_cca_nodes, /*combine profile*/
                g_email_otap);

    /*add the last tmp_app_node to profile[i]*/
    status = mmi_email_add_application_to_profile(g_email_otap);
    mmi_email_free_tmp_app_node(g_email_otap);

    mmi_email_add_dataacctid_to_profile(g_email_otap);

    /*Check dependency of address and address type*/
    mmi_email_check_profile_validity();

    /* If there is no correct Email profile, send a INVALID_SETTING response message back to CCA. */
    if (!mmi_email_has_any_valid_profile()) 
    {        
        /* Now, terminate the OTAP OTA provisioning application. */
        mmi_email_otap_stop_ps();
        mmi_email_send_cca_app_configure_res(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        mmi_email_free_otap_cntx();
        return;
    }

    /* Setup callback to free memory and send message back to CCA when users
       press END key and return to idle screen, or when the app exits. */
    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_OTAP_REPLACE_PROFILE, mmi_email_abort_otap_app);

    /* Ready to install profiles. */
    mmi_email_entry_installation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_handle_app_configure
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to Email
 *  profile.
 * PARAMETERS
 *  newConfigDoc        [IN]            CCA configuration doc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_handle_app_configure(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_is_in_otap = MMI_TRUE;
    
    /* Whether any other OTA provisioning process is still running. */
    if (g_email_otap != NULL) {
        MMI_ASSERT(0);  /* Guaranteed by CCA that this should not happen */
    }

    /* Init control block and save the ID/handle for the response msg. */
    g_email_otap = mmi_email_new_otap_cntx(newConfigDoc->config_id, newConfigDoc->hConfig);

    if (g_email_otap == NULL)
    {
        mmi_email_send_cca_app_configure_res(newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_FAIL);
        return;
    }

    /* g_email_otap is not NULL */
    g_email_otap->sim_id = newConfigDoc->sim_id;

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if(email_p->snr_info.is_auto_chk == TRUE)
    {
        mmi_email_is_autochk_at_otap_begin = MMI_TRUE;
        mmi_email_ps_abort_req();
    }
    else
#endif /*!defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)*/
    {
        mmi_email_ps_start_req();
    }
}

#endif /* __MMI_EMAIL_OTAP__ */ 
#endif /* __MMI_EMAIL__*/
#endif /* _MMI_EMAILAPPOTAP_C */



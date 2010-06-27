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
 * JProfileUIHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the profile handler
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
#ifndef _JPROFILEUIHANDLER_C
#define _JPROFILEUIHANDLER_C


#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))

#include "ProtocolEvents.h"
#include "ddl.h"
#include "wapadp.h"


#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "JProfileHandlerResDef.h"
#include "JProvWap.h"
#include "JBrowserMMITypes.h"   /* Added by Sandeep for connection active flag */
#include "JBrowserResDef.h"
#include "Conversions.h"

/* Itishree Adds */
#include "JBrowserMMIProts.h"   /* extern void mmi_brw_set_connection_active_flag(JC_BOOLEAN)
                                   extern MMI_BOOL mmi_brw_validate_url(U8 *url_p) */

#if defined(MMS_SUPPORT)        /* dilip */
/* Itishree Adds */
#include "JMMSMessageSettings.h"        /* Added for the fun extern U16 mmi_jmms_get_profile_title_icon(void) */
#include "JMMSGprot.h"
/* Itishree ends */
#endif /* defined(MMS_SUPPORT) */ /* #if defined(MMS_SUPPORT) */

/* extern void jdd_MemSetActiveModuleID(ETaskID taskId); */

static U8 g_ph_conn_index;
static U8 g_ph_done_flag;
static U8 g_ph_invalid_flag;

ph_context_struct g_ph_cntx;

/* Itishree Adds */
#ifdef __MMI_JATAAYU_CCA_SUPPORT__
static U8 g_profile_list_count;
static U8 g_ph_activated_flag;
static U8 g_ph_setting_installed_flag = PROV_SETTING_SKIPPED;
static prov_bkm_list_struct *g_bkm_list_p;
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_deinit_profiles
 * DESCRIPTION
 *  This is the deinitialization routine,to free the memory  & reset values used by profile handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_deinit_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_wap_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_wap_prof_name_arr_p);
        g_ph_cntx.ph_wap_prof_name_arr_p = NULL;
    }
    if (g_ph_cntx.ph_mms_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_mms_prof_name_arr_p);
        g_ph_cntx.ph_mms_prof_name_arr_p = NULL;
    }
    if (g_ph_cntx.profile_display_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.profile_display_p);
        g_ph_cntx.profile_display_p = NULL;
    }

    if (g_ph_cntx.ph_wap_profile_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_wap_profile_p);
        g_ph_cntx.ph_wap_profile_p = NULL;
    }
    if (g_ph_cntx.ph_mms_profile_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_mms_profile_p);
        g_ph_cntx.ph_mms_profile_p = NULL;
    }
    g_ph_cntx.ph_initialised = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_init
 * DESCRIPTION
 *  This is the profile handler Initialization API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ph_cntx.ph_initialised = MMI_TRUE;

    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
    if (g_ph_cntx.ph_activated_wap_profile == NULL)
    {
        g_ph_cntx.ph_activated_wap_profile =
            (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.ph_activated_wap_profile == NULL)
    {
        ASSERT(0);
    }
    /* Itishree ends */
    ReadValue(NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX, &g_ph_cntx.wap_actived_profile_index, DS_BYTE, &error);

    if (g_ph_cntx.wap_actived_profile_index == 0xFF)
    {
        g_ph_cntx.wap_actived_profile_index = 0x00;
        WriteValue(NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX, &g_ph_cntx.wap_actived_profile_index, DS_BYTE, &error);
    }

    mmi_ph_get_activated_profile_data(PH_BROWSER_PROFILE, g_ph_cntx.wap_actived_profile_index);
    if (g_ph_cntx.ph_activated_mms_profile == NULL)
    {
        g_ph_cntx.ph_activated_mms_profile =
            (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.ph_activated_mms_profile == NULL)
    {
        ASSERT(0);
    }
    /* Itishree ends */

    ReadValue(NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX, &g_ph_cntx.mms_actived_profile_index, DS_BYTE, &error);

    if (g_ph_cntx.mms_actived_profile_index == 0xFF)
    {
        g_ph_cntx.mms_actived_profile_index = 0x00;
        WriteValue(NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX, &g_ph_cntx.mms_actived_profile_index, DS_BYTE, &error);
    }

    mmi_ph_get_activated_profile_data(PH_MMS_PROFILE, g_ph_cntx.mms_actived_profile_index);
    /* Set Highlight handlers */
    SetHiliteHandler(MENU_ID_PH_SELECT_PROFILE_ACTIVATE, mmi_ph_activate_profile_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PH_SELECT_PROFILE_EDIT, mmi_ph_edit_profile_highlight_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_pre_entry_show_profile_list_menu
 * DESCRIPTION
 *  It is an pre entry function for showing profile name list.
 *  This makes the global profile name data ready to be displayed
 * PARAMETERS
 *  profile     [IN]        Profile Type (Browser or MMS)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_pre_entry_show_profile_list_menu(ph_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile == PH_MMS_PROFILE || profile == PH_MMS_PROV_PROFILE)
    {
    #if defined MMS_SUPPORT
        g_ph_cntx.ph_title_img_id = mmi_jmms_get_profile_title_icon();
    #endif 
    }
    else
    {
        g_ph_cntx.ph_title_img_id = SERVICES_WAP_MENU_ID;
    }
    if (profile == PH_BROWSER_PROFILE)
    {
        g_ph_cntx.profile_module = PH_BROWSER_PROFILE;
        mmi_ph_get_brw_profile_name_list();

    }
    else if (profile == PH_MMS_PROFILE)
    {
        g_ph_cntx.profile_module = PH_MMS_PROFILE;
        mmi_ph_get_mms_profile_name_list();
    }
    else if (profile == PH_BROWSER_PROV_PROFILE)
    {
        g_ph_cntx.profile_module = PH_BROWSER_PROV_PROFILE;
        mmi_ph_get_brw_profile_name_list();
    }
    else if (profile == PH_MMS_PROV_PROFILE)
    {
        g_ph_cntx.profile_module = PH_MMS_PROV_PROFILE;
        mmi_ph_get_mms_profile_name_list();
    }
    mmi_ph_entry_show_profile_list_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_entry_show_profile_list_menu
 * DESCRIPTION
 *  Entry function to show profile name list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_entry_show_profile_list_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p = NULL;
    S32 activated_index = 0;
    U16 activated_profile_image[NVRAM_WAP_PROFILE_MAX] = {0, };
    U16 title_id;
    U16 lsk_id;
    U16 lsk_img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_pend_set = 0;

    activated_index = mmi_ph_get_activated_profile_index();

    activated_profile_image[activated_index] = IMG_ID_PROF_HDLR_SET_ACTIVATED_PROFILE;

    EntryNewScreen(SCR_ID_PROF_HDLR_PROF_LIST, NULL, mmi_ph_entry_show_profile_list_menu, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_PROF_LIST);

    RegisterHighlightHandler(mmi_ph_highlight_select_profile);

    mmi_ph_get_profile_name_list();

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    if (g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE || g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE)
    {
        title_id = STR_ID_CCA_REPLACE_SETTING;
        lsk_id = STR_GLOBAL_INSTALL;
        lsk_img_id = 0;
    }
    else
    {
        title_id = STR_ID_PROF_HDLR_SELECT_PROF_CAPTION;
        lsk_id = STR_GLOBAL_OK;
        lsk_img_id = IMG_GLOBAL_OK;
    }
#else /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    title_id = STR_ID_PROF_HDLR_SELECT_PROF_CAPTION;
    lsk_id = STR_GLOBAL_OK;
    lsk_img_id = IMG_GLOBAL_OK;
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

    ShowCategory53Screen(
        title_id,
        /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
        lsk_id,
        lsk_img_id,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NVRAM_WAP_PROFILE_MAX,
        (U8 **) subMenuDataPtrs,
        (PU16) activated_profile_image,
        0,
        0,
        activated_index,
        gui_buffer_p);

    /* Register function for left soft key */

    if ((g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE) || (g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE))     /* This will handle the provisioning setting */
    {
    #ifdef __MMI_JATAAYU_CCA_SUPPORT__
        SetLeftSoftkeyFunction(mmi_ph_update_selected_profile, KEY_EVENT_UP);
        SetKeyHandler(mmi_ph_update_selected_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_prov_end_key_handler, KEY_END, KEY_EVENT_DOWN);
    #else /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
        SetLeftSoftkeyFunction(mmi_prov_get_dataaccount_data, KEY_EVENT_UP);
        SetKeyHandler(mmi_prov_get_dataaccount_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        /* Register function for right soft key */
        SetRightSoftkeyFunction(mmi_prov_confirm_abort_setting_set_up, KEY_EVENT_UP);
        SetKeyHandler(mmi_prov_confirm_abort_setting_set_up, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_prov_handle_cancel, KEY_END, KEY_EVENT_DOWN);
    #endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_ph_entry_select_editable_profile, KEY_EVENT_UP);
        SetKeyHandler(mmi_ph_entry_select_editable_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        /* Register function for right soft key */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_entry_select_editable_profile
 * DESCRIPTION
 *  This is entry function for the screen showing menu items (Activate ,Edit profile )
 *  for any selected profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_entry_select_editable_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p = NULL;    /* Buffer holding history data */
    S32 num_of_item = 0;        /* Stores no of children in the submenu */
    S8 profile_name_string[(NVRAM_WAP_PROFILE_NAME_LEN) * ENCODING_LENGTH];
    U32 count = 0;
    U16 string_item_list[MAX_SUB_MENUS_REQUIRED];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_SELECTED_PROFILE, NULL, mmi_ph_entry_select_editable_profile, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_SELECTED_PROFILE);

    num_of_item = GetNumOfChild(MENU_ID_PH_SELECT_PROFILE);
    GetSequenceStringIds(MENU_ID_PH_SELECT_PROFILE, string_item_list);
    SetParentHandler(MENU_ID_PH_SELECT_PROFILE);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(string_item_list[count]), MAX_SUBMENU_CHARACTERS);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].dcs == PH_DCS_ASCII)
        {
            mmi_asc_to_ucs2(
                (S8*) profile_name_string,
                (S8*) g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].profile_name);
        }
        else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].dcs ==
                 PH_DCS_UCS)
        {
            mmi_ucs2cpy(
                (S8*) profile_name_string,
                (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].profile_name));
        }
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].dcs == PH_DCS_ASCII)
        {
            mmi_asc_to_ucs2(
                (S8*) profile_name_string,
                (S8*) g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].profile_name);
        }
        else if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].dcs ==
                 PH_DCS_UCS)
        {
            mmi_ucs2cpy(
                (S8*) profile_name_string,
                (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].profile_name));
        }
    }

    ShowCategory353Screen(
        (U8*) (profile_name_string),
        /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_activate_profile_highlight_hdlr
 * DESCRIPTION
 *  It is the highlight handler for the MENU_ID_PH_SELECT_PROFILE_ACTIVATE menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_activate_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_ph_activate_selected_profile, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_ph_activate_selected_profile,KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_edit_profile_highlight_hdlr
 * DESCRIPTION
 *  *  It is the highlight handler for the MENU_ID_PH_SELECT_PROFILE_EDIT menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_edit_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_ph_pre_entry_edit_selected_profile, KEY_EVENT_UP);
    SetKeyHandler(mmi_ph_pre_entry_edit_selected_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_highlight_select_profile
 * DESCRIPTION
 *  This gets the highlighted index and stores it into global profile index
 * PARAMETERS
 *  index       [IN]        Index for profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_highlight_select_profile(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ph_cntx.profile_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_pre_entry_edit_selected_profile
 * DESCRIPTION
 *  It is the pre entry function for the edit profile screen,in this the profiel content data is
 *  extracted from the NVRAM & data account info is requested ,on the response of data account
 *  edit profile entry function is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_pre_entry_edit_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ph_done_flag = 0x00;
    mmi_ph_get_selected_profile_content_data(g_ph_cntx.profile_index);
    DataAccountReadyCheck(mmi_ph_handle_get_data_account_name);
    /* mmi_ph_handle_get_data_account_name(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_entry_edit_selected_profile
 * DESCRIPTION
 *  It is the entry function for the edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_entry_edit_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *input_buffer_p = NULL;  /* added for inline edit history */
    U8 *gui_buffer_p = NULL;    /* Buffer holding history data */
    U16 input_buffer_size = 0;
    U16 edit_profile_icon_list[MAX_INLINE_ITEM_EDIT_PROFILE_LIST] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0, IMG_GLOBAL_L4, 0,
        IMG_GLOBAL_L5, 0, IMG_GLOBAL_L6, 0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_EDIT_PROFILE, mmi_ph_exit_edit_selected_profile, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_EDIT_PROFILE);
    input_buffer_p = GetCurrNInputBuffer(SCR_ID_PROF_HDLR_EDIT_PROFILE, &input_buffer_size);    /* added for inline edit history */

    mmi_ph_selected_profile_fill_inline_struct();

    if (input_buffer_p != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_EDIT_PROFILE_LIST, input_buffer_p);
    }

    if ((GetInlineDoneFlag(gui_buffer_p) == 0) && (g_ph_done_flag == 0x01))
    {
        SetInlineDoneFlag(gui_buffer_p);
    }

    RegisterHighlightHandler(mmi_ph_highlight_inline_item);

    ShowCategory57Screen(STR_ID_BRW_EDIT_PROFILE,
                         // GetRootTitleIcon(SERVICES_WAP_MENU_ID), /* modified by tk */
                         GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
                         STR_GLOBAL_EDIT,
                         NULL,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK,
                         MAX_INLINE_ITEM_EDIT_PROFILE_LIST, edit_profile_icon_list, wgui_inline_items, 0, gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_ph_save_selected_profile_changes, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_exit_edit_selected_profile
 * DESCRIPTION
 *  exit handler for edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_exit_edit_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 input_buffer_size = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_PROF_HDLR_EDIT_PROFILE;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_ph_entry_edit_selected_profile;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_highlight_inline_item
 * DESCRIPTION
 *  Inline item handler of Edit profile screen
 * PARAMETERS
 *  index       [IN]        IN  this is the index of the inline item in edit profile  screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_highlight_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index == PH_PROFILE_DATA_ACCOUNT))
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, NULL);
        SetLeftSoftkeyFunction(mmi_ph_prof_list_data_acct, KEY_EVENT_UP);

    }
    else if ((index == PH_PROFILE_CONN_TYPE))
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, NULL);
        SetLeftSoftkeyFunction(mmi_ph_show_connection_type_options, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_prof_list_data_acct
 * DESCRIPTION
 *  LSK handler of Data Account item in Profile Setting inline editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_prof_list_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_ph_cntx.profile_module == PH_MMS_PROFILE) || (g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE))
    {
        mmi_dtcnt_select_account(mmi_ph_prof_callback, g_ph_cntx.ph_title_img_id, DATA_ACCOUNT_BEARER_GPRS);
    }
    else
    {
        mmi_dtcnt_select_account(mmi_ph_prof_callback, g_ph_cntx.ph_title_img_id, DATA_ACCOUNT_BEARER_ALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_prof_callback
 * DESCRIPTION
 *  This is the callback function for Data Account
 * PARAMETERS
 *  index       [IN]        This is the index for Data Account
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_prof_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_display_p == NULL)
    {
        g_ph_cntx.profile_display_p =
            (ph_show_editable_profile_struct*) jdd_MemAlloc(sizeof(ph_show_editable_profile_struct), 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.profile_display_p == NULL)
    {
        ASSERT(0);
    }
    /* Itishree ends */

    g_ph_cntx.profile_display_p->data_account = (U8) index;
    if ((g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE) || (g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE))
    {
        ph_data_account_enum data_account;

        data_account = mmi_ph_check_data_account_type(g_ph_cntx.profile_display_p->data_account);
    #ifndef __MMI_JATAAYU_CCA_SUPPORT__
        if (data_account == PH_DATA_ACCOUNT_CSD)
        {
            mmi_prov_prof_save_csd_data_acct();
        }
    #ifdef __MMI_GPRS_FEATURES__
        else if (data_account == PH_DATA_ACCOUNT_GPRS)
        {
            mmi_prov_prof_save_gprs_data_acct();
        }
    #endif /* __MMI_GPRS_FEATURES__ */ 
    #endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    }
    else
    {
        if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
        {
            g_ph_cntx.ph_wap_profile_p->data_account = g_ph_cntx.profile_display_p->data_account;
            mmi_dtcnt_get_account_name(
                g_ph_cntx.profile_display_p->data_account,
                (S8*) g_ph_cntx.profile_display_p->data_account_name,
                MAX_DATA_ACCOUNT_NAME_LEN);
            g_ph_done_flag = 0x01;
            DeleteUptoScrID(SCR_ID_PROF_HDLR_EDIT_PROFILE);
            /* DeleteNHistory(1); */
            GoBackHistory();
        }
        else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
        {
            g_ph_cntx.ph_mms_profile_p->data_account = g_ph_cntx.profile_display_p->data_account;
            mmi_dtcnt_get_account_name(
                g_ph_cntx.profile_display_p->data_account,
                (S8*) g_ph_cntx.profile_display_p->data_account_name,
                MAX_DATA_ACCOUNT_NAME_LEN);
            g_ph_done_flag = 0x01;
            GoBackHistory();
        }
        /*        mmi_dtcnt_get_account_name(
           g_ph_cntx.profile_display_p->data_account,
           (S8*) g_ph_cntx.profile_display_p->data_account_name,
           MAX_DATA_ACCOUNT_NAME_LEN);
           g_ph_done_flag = 0x01;
           DeleteNHistory(1);
           GoBackHistory(); */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_selected_profile_fill_inline_struct
 * DESCRIPTION
 *  This API handles the inline items in the edit profile screen ,like data account,username ,password,conn type.....
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_selected_profile_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_display_p == NULL)
    {
        g_ph_cntx.profile_display_p =
            (ph_show_editable_profile_struct*) jdd_MemAlloc(sizeof(ph_show_editable_profile_struct), 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.profile_display_p == NULL)
    {
        ASSERT(0);
    }
    /* Itishree ends */

    SetInlineItemActivation((wgui_inline_items + PH_PROFILE_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + PH_PROFILE_HOMEPAGE), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + PH_PROFILE_DATA_ACCOUNT), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + PH_PROFILE_CONN_TYPE), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + PH_PROFILE_USER_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + PH_PROFILE_USER_PASSWORD), KEY_LSK, KEY_EVENT_UP);

    SetInlineItemCaption((wgui_inline_items + PH_PROFILE_NAME_STR), (U8*) GetString(STR_ID_PROF_HDLR_RENAME_PROFILE));
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        SetInlineItemCaption(
            (wgui_inline_items + PH_PROFILE_HOMEPAGE_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_HOMEPAGE));
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        SetInlineItemCaption(
            (wgui_inline_items + PH_PROFILE_HOMEPAGE_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_MMSC_URL));
    }
    SetInlineItemCaption(
        (wgui_inline_items + PH_PROFILE_DATA_ACCOUNT_STR),
        (U8*) GetString(STR_ID_PROF_HDLR_DATA_ACCOUNT));
    SetInlineItemCaption((wgui_inline_items + PH_PROFILE_CONN_TYPE_STR), (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE));
    SetInlineItemCaption((wgui_inline_items + PH_PROFILE_USER_NAME_STR), (U8*) GetString(STR_ID_PROF_HDLR_USER_NAME));
    SetInlineItemCaption(
        (wgui_inline_items + PH_PROFILE_USER_PASSWORD_STR),
        (U8*) GetString(STR_ID_PROF_HDLR_PASSWORD));
    SetInlineItemDisplayOnly(
        (wgui_inline_items + PH_PROFILE_DATA_ACCOUNT),
        (U8*) g_ph_cntx.profile_display_p->data_account_name);

    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        /* profile connection type */
        if ((g_ph_cntx.ph_wap_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED)
            || (g_ph_cntx.ph_wap_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE))
        {
            SetInlineItemDisplayOnly(
                (wgui_inline_items + PH_PROFILE_CONN_TYPE),
                (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_CONNECTION));
        }
        else if (g_ph_cntx.ph_wap_profile_p->conn_type == PH_CONN_TYPE_HTTP)
        {
            SetInlineItemDisplayOnly(
                (wgui_inline_items + PH_PROFILE_CONN_TYPE),
                (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
        }
        /* profile name inline item */
        buffer_size = NVRAM_WAP_PROFILE_PROFILE_NAME_LEN;
        if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].dcs == PH_DCS_ASCII)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            mmi_asc_to_ucs2(
                (S8*) g_ph_cntx.profile_display_p->profile_name,
                (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].profile_name));

        }
        else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].dcs ==
                 PH_DCS_UCS)
        {
            mmi_ucs2cpy(
                (S8*) g_ph_cntx.profile_display_p->profile_name,
                (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].profile_name));
        }
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_NAME),
            STR_ID_PROF_HDLR_RENAME_PROFILE,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) g_ph_cntx.profile_display_p->profile_name,
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_NAME,
            mmi_ph_editable_profile_full_screen_edit);
        /* profile homepage url inline item */
        buffer_size = NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN;
        mmi_asc_to_ucs2(
            (S8*) g_ph_cntx.profile_display_p->homepage_url,
            (S8*) (g_ph_cntx.ph_wap_profile_p->homepage_url));
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_HOMEPAGE),
            STR_ID_PROF_HDLR_HOMEPAGE,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) g_ph_cntx.profile_display_p->homepage_url,
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_HOMEPAGE,
            mmi_ph_editable_profile_full_screen_edit);
        /* profile username inline item */
        buffer_size = NVRAM_WAP_PROFILE_USERNAME_LEN;
        mmi_asc_to_ucs2(
            (S8*) g_ph_cntx.profile_display_p->username,
            (S8*) (g_ph_cntx.ph_wap_profile_p->username));
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_USER_NAME),
            STR_ID_PROF_HDLR_USER_NAME,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) (g_ph_cntx.profile_display_p->username),
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_USER_NAME,
            mmi_ph_editable_profile_full_screen_edit);
        /* profile password inline item */
        buffer_size = NVRAM_WAP_PROFILE_PASSWORD_LEN;
        mmi_asc_to_ucs2(
            (S8*) g_ph_cntx.profile_display_p->password,
            (S8*) (g_ph_cntx.ph_wap_profile_p->password));
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_USER_PASSWORD),
            STR_ID_PROF_HDLR_PASSWORD,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) (g_ph_cntx.profile_display_p->password),
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_USER_PASSWORD,
            mmi_ph_editable_profile_full_screen_edit);
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {

        /* profile connection type */
        if ((g_ph_cntx.ph_mms_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED)
            || (g_ph_cntx.ph_mms_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE))
        {
            SetInlineItemDisplayOnly(
                (wgui_inline_items + PH_PROFILE_CONN_TYPE),
                (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_CONNECTION));
        }
        else if (g_ph_cntx.ph_mms_profile_p->conn_type == PH_CONN_TYPE_HTTP)
        {
            SetInlineItemDisplayOnly(
                (wgui_inline_items + PH_PROFILE_CONN_TYPE),
                (U8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
        }

        /* profile name inline item */
        buffer_size = NVRAM_WAP_PROFILE_PROFILE_NAME_LEN;
        if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].dcs == PH_DCS_ASCII)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            mmi_asc_to_ucs2(
                (S8*) g_ph_cntx.profile_display_p->profile_name,
                (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].profile_name));

        }
        else if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].dcs ==
                 PH_DCS_UCS)
        {
            mmi_ucs2cpy(
                (S8*) g_ph_cntx.profile_display_p->profile_name,
                (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[g_ph_cntx.profile_index].profile_name));
        }
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_NAME),
            STR_ID_PROF_HDLR_RENAME_PROFILE,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) (g_ph_cntx.profile_display_p->profile_name),
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_NAME,
            mmi_ph_editable_profile_full_screen_edit);

        /* profile MMSC url inline item */
        buffer_size = NVRAM_MMS_PROFILE_MMSC_URL_LEN;
        mmi_asc_to_ucs2(
            (S8*) g_ph_cntx.profile_display_p->homepage_url,
            (S8*) (g_ph_cntx.ph_mms_profile_p->mmsc_url));
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_HOMEPAGE),
            STR_ID_PROF_HDLR_HOMEPAGE,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) (g_ph_cntx.profile_display_p->homepage_url),
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_HOMEPAGE,
            mmi_ph_editable_profile_full_screen_edit);

        /* profile username inline item */
        buffer_size = NVRAM_MMS_PROFILE_USERNAME_LEN;
        mmi_asc_to_ucs2(
            (S8*) g_ph_cntx.profile_display_p->username,
            (S8*) (g_ph_cntx.ph_mms_profile_p->username));
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_USER_NAME),
            STR_ID_PROF_HDLR_USER_NAME,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) (g_ph_cntx.profile_display_p->username),
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_USER_NAME,
            mmi_ph_editable_profile_full_screen_edit);

        /* profile password inline item */
        buffer_size = NVRAM_MMS_PROFILE_PASSWORD_LEN;
        mmi_asc_to_ucs2(
            (S8*) g_ph_cntx.profile_display_p->password,
            (S8*) (g_ph_cntx.ph_mms_profile_p->password));
        SetInlineItemFullScreenEdit(
            (wgui_inline_items + PH_PROFILE_USER_PASSWORD),
            STR_ID_PROF_HDLR_PASSWORD,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            (U8*) (g_ph_cntx.profile_display_p->password),
            buffer_size,
            INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        SetInlineFullScreenEditCustomFunction(
            wgui_inline_items + PH_PROFILE_USER_PASSWORD,
            mmi_ph_editable_profile_full_screen_edit);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_editable_profile_full_screen_edit
 * DESCRIPTION
 *  It is the inline full screen edit custom function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_editable_profile_full_screen_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(g_ph_cntx.ph_title_img_id)
                                     /* GetRootTitleIcon(SERVICES_WAP_MENU_ID) */ );
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_save_selected_profile_changes
 * DESCRIPTION
 *  This is the entry function for the save edit profile changes confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_save_selected_profile_changes(void)
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
        (UI_string_type) GetString(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_ph_editable_profile_save_changes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ph_editable_profile_reject_changes, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_editable_profile_reject_changes
 * DESCRIPTION
 *  It handles the Press of RSK(NO) on the save changes screen for the editable profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_editable_profile_reject_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_editable_profile_save_changes
 * DESCRIPTION
 *  It invokes the storage into the NVRAM for the changes done in the profile struct (Browser ,MMS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_editable_profile_save_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL IsValidURL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        if (g_ph_cntx.profile_index == g_ph_cntx.wap_actived_profile_index)
        {
            mmi_brw_set_connection_active_flag(E_FALSE);
        #ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__
            if (TRUE == IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
            {
                mmi_brw_set_transport_and_data_profile();
                mmi_brw_set_connection_active_flag(E_TRUE);
            }
        #endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 
        }
        mmi_ph_update_nvram_wap_profile();
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        IsValidURL = mmi_brw_validate_url((PU8) g_ph_cntx.profile_display_p->homepage_url);
        if (IsValidURL == MMI_TRUE)
        {
            mmi_ph_update_nvram_mms_profile();
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_INVALID_URL),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }

}

/* This function is not currently in use */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_activate_selected_profile
 * DESCRIPTION
 *  It updates the current selected profile index as the activated proifle index
 *  & based on this index updates the activated profile struct.
 *  Done popup is shown on completion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_activate_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Added by Sandeep for checking data connection active or not */
    /* If the data profile is chnaged by the user then we have to set this flag as false so that 
       when a new page is fetched then we have to set the profile again */

    mmi_brw_set_connection_active_flag(E_FALSE);
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE || g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE)  /* Added By Itishree */
    {
        g_ph_cntx.wap_actived_profile_index = g_ph_cntx.profile_index;
        WriteValue(NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX, &g_ph_cntx.wap_actived_profile_index, DS_BYTE, &error);
        mmi_ph_get_activated_profile_data(PH_BROWSER_PROFILE, g_ph_cntx.profile_index);

    #ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__
        if (TRUE == IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
        {
            mmi_brw_set_transport_and_data_profile();
            mmi_brw_set_connection_active_flag(E_TRUE);
        }
    #endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE || g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE)     /* Added By Itishree */
    {
        g_ph_cntx.mms_actived_profile_index = g_ph_cntx.profile_index;
        WriteValue(NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX, &g_ph_cntx.mms_actived_profile_index, DS_BYTE, &error);
        mmi_ph_get_activated_profile_data(PH_MMS_PROFILE, g_ph_cntx.profile_index);
    }
#if defined(MMS_SUPPORT)        /* dilip */
    mmi_jmms_set_profile();
#endif 
    if (g_ph_cntx.profile_module != PH_MMS_PROV_PROFILE && g_ph_cntx.profile_module != PH_BROWSER_PROV_PROFILE) /* Added By Itishree */
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_ACTIVATED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteNHistory(1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_show_connection_type_options
 * DESCRIPTION
 *  It shows the various connection type menu item available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_show_connection_type_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;
    S32 num_of_item = 0;
    S32 count = 0;
    U32 conn_type_index = 0;
    U16 string_item_list[MAX_CONN_TYPE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_CONN_TYPE, NULL, mmi_ph_show_connection_type_options, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_ph_show_connection_type_options");

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_CONN_TYPE);

    num_of_item = GetNumOfChild(MENU_ID_PH_CONNECTION_TYPE);
    GetSequenceStringIds(MENU_ID_PH_CONNECTION_TYPE, string_item_list);
    SetParentHandler(MENU_ID_PH_CONNECTION_TYPE);

    RegisterHighlightHandler(mmi_ph_conn_type_highlight_hdlr);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) GetString(string_item_list[count]), MAX_SUBMENU_CHARACTERS);
    }
    conn_type_index = mmi_ph_get_highlighted_menu_item();
    ShowCategory36Screen(
        STR_ID_PROF_HDLR_CONN_TYPE,
        /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16) conn_type_index,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_ph_entry_edit_connection_type_details, KEY_EVENT_UP);
    //NOTE : this will be needed if we want to update the connection type just by selecting the conn type
    //      SetRightSoftkeyFunction(mmi_ph_update_connection_type,KEY_EVENT_UP);
    //      SetKeyHandler(mmi_ph_update_connection_type,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_connection_type
 * DESCRIPTION
 *  This API updates the connection type in the edit profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_connection_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ph_highlight_inline_item_conn_type(g_ph_conn_index);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_highlighted_menu_item
 * DESCRIPTION
 *  It gives the higlighted connection type menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 connection type highlighted
 *****************************************************************************/
U8 mmi_ph_get_highlighted_menu_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        if ((g_ph_cntx.ph_wap_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED)
            || (g_ph_cntx.ph_wap_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE))
        {
            return (U8) PH_MENU_CONNECTION_OREINTED;
        }
        else if (g_ph_cntx.ph_wap_profile_p->conn_type == PH_CONN_TYPE_HTTP)
        {
            return (U8) PH_MENU_HTTP;
        }
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        if ((g_ph_cntx.ph_mms_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED)
            || (g_ph_cntx.ph_mms_profile_p->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE))
        {
            return (U8) PH_MENU_CONNECTION_OREINTED;
        }
        else if (g_ph_cntx.ph_mms_profile_p->conn_type == PH_CONN_TYPE_HTTP)
        {
            return (U8) PH_MENU_HTTP;
        }

    }
    return (U8) PH_MENU_CONNECTION_OREINTED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_conn_type_highlight_hdlr
 * DESCRIPTION
 *  This API is to update the global connection type index
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_conn_type_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ph_conn_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_entry_edit_connection_type_details
 * DESCRIPTION
 *  This is the entry fucntion for connection type details inline item screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_entry_edit_connection_type_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *input_buffer_p = NULL;  /* added for inline edit history */
    U8 *gui_buffer_p = NULL;    /* Buffer holding history data */
    U16 input_buffer_size = 0;
    U32 conn_type_index = 0;    /* Sandeep */
    U16 edit_conn_type_icon_list[MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_EDIT_CONN_TYPE, mmi_ph_exit_edit_connection_type_details, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PROF_HDLR_EDIT_CONN_TYPE);
    input_buffer_p = GetCurrNInputBuffer(SCR_ID_PROF_HDLR_EDIT_CONN_TYPE, &input_buffer_size);  /* added for inline edit history */

    mmi_ph_edit_conn_type_fill_inline_struct();

    if (input_buffer_p != NULL)
    {
        if (g_ph_conn_index == PH_MENU_HTTP)
        {
            SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST, input_buffer_p);
        }
        else
        {
            SetCategory57Data(wgui_inline_items, 2, input_buffer_p);
        }
    }

    /* Sandeep */
    conn_type_index = mmi_ph_get_highlighted_menu_item();
    if (conn_type_index != g_ph_conn_index && g_ph_invalid_flag != 0x01)
    {
        SetInlineListMenuChanged();
    }
    g_ph_invalid_flag = 0x00;
    if (g_ph_conn_index == PH_MENU_HTTP)
    {
        ShowCategory57Screen(
            STR_GLOBAL_EDIT,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            STR_GLOBAL_EDIT,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST,
            edit_conn_type_icon_list,
            wgui_inline_items,
            0,
            gui_buffer_p);
    }
    else
    {
        ShowCategory57Screen(
            STR_GLOBAL_EDIT,
            /* GetRootTitleIcon(SERVICES_WAP_MENU_ID), */ GetRootTitleIcon(g_ph_cntx.ph_title_img_id),
            STR_GLOBAL_EDIT,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            2,
            edit_conn_type_icon_list,
            wgui_inline_items,
            0,
            gui_buffer_p);
    }

    SetCategory57RightSoftkeyFunctions(mmi_ph_save_connection_type_changes, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_highlight_inline_item_conn_type
 * DESCRIPTION
 *  This API updates the Browser & MMS proifle structs based  on the highlighted index
 * PARAMETERS
 *  index       [IN]        This is the index for connection type(WAP or HTTP)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_highlight_inline_item_conn_type(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == PH_MENU_CONNECTION_OREINTED)
    {
        if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
        {

        #if defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT)
            if (mmi_ucs2cmp
                ((S8*) g_ph_cntx.profile_display_p->security_option[g_ph_cntx.profile_display_p->security_opt_index],
                 (S8*) GetString(STR_ID_PROF_HDLR_ON)) == 0)
            {
                g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
                g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].conn_type =
                    CONN_TYPE_CONNECTION_OREINTED_SECURE;

            }
            else
            {
                g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;
                g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].conn_type =
                    PH_CONN_TYPE_CONNECTION_OREINTED;
            }
        #else /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */ 
            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].conn_type =
                PH_CONN_TYPE_CONNECTION_OREINTED;
        #endif /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */ 
        }
        else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
        {
        #if defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT)
            if (mmi_ucs2cmp
                ((S8*) g_ph_cntx.profile_display_p->security_option[g_ph_cntx.profile_display_p->security_opt_index],
                 (S8*) GetString(STR_ID_PROF_HDLR_ON)) == 0)
            {
                g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED_SECURE;
            }
            else
            {
                g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;
            }
        #else /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */ 
            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_CONNECTION_OREINTED;
        #endif /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */ 
        }
    }
    else if (index == PH_MENU_HTTP)
    {
        if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
        {
            g_ph_cntx.ph_wap_profile_p->conn_type = PH_CONN_TYPE_HTTP;
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[g_ph_cntx.profile_index].conn_type =
                PH_CONN_TYPE_HTTP;
        }
        else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
        {
            g_ph_cntx.ph_mms_profile_p->conn_type = PH_CONN_TYPE_HTTP;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_save_connection_type_changes
 * DESCRIPTION
 *  This API saves the changes done with the connection type like port & IP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_save_connection_type_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 ip_value[4];
    U32 ip_sum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ph_done_flag = 0x01;  /* Tk added for Handling the Done RSK label */
    g_ph_invalid_flag = 0x00;

    ip_value[0] = (U8) gui_atoi((UI_string_type) g_ph_cntx.profile_display_p->ip1);
    ip_value[1] = (U8) gui_atoi((UI_string_type) g_ph_cntx.profile_display_p->ip2);
    ip_value[2] = (U8) gui_atoi((UI_string_type) g_ph_cntx.profile_display_p->ip3);
    ip_value[3] = (U8) gui_atoi((UI_string_type) g_ph_cntx.profile_display_p->ip4);

    ip_sum = ip_value[0] + ip_value[1] + ip_value[2] + ip_value[3];

    if ((ip_sum == 0x00) && ((g_ph_conn_index == PH_MENU_CONNECTION_OREINTED)))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PROF_HDLR_INVALID_IP),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        U32 port = 0;

        port = (U32) gui_atoi((UI_string_type) g_ph_cntx.profile_display_p->proxy_port);

        if (!mmi_ucs2strlen((S8*) g_ph_cntx.profile_display_p->proxy_port))
        {
            g_ph_invalid_flag = 0x01;
            DisplayPopup(
                (PU8) GetString(STR_ID_PROF_HDLR_INVALID_INPUT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else if (port >= PH_USHORT_MAX)
        {
            g_ph_invalid_flag = 0x01;
            DisplayPopup(
                (PU8) GetString(STR_ID_PROF_HDLR_INVALID_INPUT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {

            if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
            {
                g_ph_cntx.ph_wap_profile_p->proxy_ip[0] = ip_value[0];
                g_ph_cntx.ph_wap_profile_p->proxy_ip[1] = ip_value[1];
                g_ph_cntx.ph_wap_profile_p->proxy_ip[2] = ip_value[2];
                g_ph_cntx.ph_wap_profile_p->proxy_ip[3] = ip_value[3];

                g_ph_cntx.ph_wap_profile_p->proxy_port = (U16) port;

                mmi_ph_update_connection_type();
                GoBackHistory();
            }
            else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
            {
                g_ph_cntx.ph_mms_profile_p->proxy_ip[0] = ip_value[0];
                g_ph_cntx.ph_mms_profile_p->proxy_ip[1] = ip_value[1];
                g_ph_cntx.ph_mms_profile_p->proxy_ip[2] = ip_value[2];
                g_ph_cntx.ph_mms_profile_p->proxy_ip[3] = ip_value[3];

                g_ph_cntx.ph_mms_profile_p->proxy_port = (U16) port;

                mmi_ph_update_connection_type();
                GoBackHistory();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_exit_edit_connection_type_details
 * DESCRIPTION
 *  It is te exit handler for the edit connection type screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_exit_edit_connection_type_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 input_buffer_size = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_PROF_HDLR_EDIT_CONN_TYPE;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_ph_entry_edit_connection_type_details;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_edit_conn_type_fill_inline_struct
 * DESCRIPTION
 *  This API handles the connection type inline edit screen,containing inline items like IP ,proxy port
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_edit_conn_type_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_display_p == NULL)
    {
        g_ph_cntx.profile_display_p =
            (ph_show_editable_profile_struct*) jdd_MemAlloc(sizeof(ph_show_editable_profile_struct), 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.profile_display_p == NULL)
    {
        ASSERT(0);
    }
    /* Itishree ends */
    if (g_ph_conn_index == PH_MENU_HTTP)
    {
        SetInlineItemActivation(
            (wgui_inline_items + PH_CONN_TYPE_IP_ADDRESS),
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            (wgui_inline_items + PH_CONN_TYPE_IP_ADDRESS_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_PROXY_ADDRESS));
        SetInlineItemActivation((wgui_inline_items + PH_CONN_TYPE_SECURITY), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption((wgui_inline_items + PH_CONN_TYPE_SECURITY_STR), (U8*) GetString(STR_ID_PROF_HDLR_PORT));
        /* dara NOTE ..for http ..its port in place of security */

        buffer_size = PH_MAX_PROXY_PORT_LENGTH; /* 6 */
        SetInlineItemTextEdit(
            (wgui_inline_items + PH_CONN_TYPE_SECURITY),
            (U8*) (g_ph_cntx.profile_display_p->proxy_port),
            buffer_size,
            INPUT_TYPE_NUMERIC);
        if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
        {
            gui_itoa((S32) g_ph_cntx.ph_wap_profile_p->proxy_port, (U16*) g_ph_cntx.profile_display_p->proxy_port, 10);
        }
        else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
        {
            gui_itoa((S32) g_ph_cntx.ph_mms_profile_p->proxy_port, (U16*) g_ph_cntx.profile_display_p->proxy_port, 10);
        }
    }
    else
    {
        SetInlineItemActivation(
            (wgui_inline_items + PH_CONN_TYPE_IP_ADDRESS),
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            (wgui_inline_items + PH_CONN_TYPE_IP_ADDRESS_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_IP_ADDRESS));

    #if defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT)

        SetInlineItemActivation((wgui_inline_items + PH_CONN_TYPE_SECURITY), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(
            (wgui_inline_items + PH_CONN_TYPE_SECURITY_STR),
            (U8*) GetString(STR_ID_PROF_HDLR_SECURITY));

        g_ph_cntx.profile_display_p->security_option[0] = (U8*) GetString(STR_ID_PROF_HDLR_OFF);
        g_ph_cntx.profile_display_p->security_option[1] = (U8*) GetString(STR_ID_PROF_HDLR_ON);
        SetInlineItemSelect(
            (wgui_inline_items + PH_CONN_TYPE_SECURITY),
            (S32) 0x02,
            (U8 **) g_ph_cntx.profile_display_p->security_option,
            (S32*) (&(g_ph_cntx.profile_display_p->security_opt_index)));
    #endif /* defined (WAP_SEC_SUPPORT) && defined (JATAAYU_SUPPORT) */ 
        if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
        {
            gui_itoa((S32) g_ph_cntx.ph_wap_profile_p->proxy_port, (U16*) g_ph_cntx.profile_display_p->proxy_port, 10);
        }
        else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
        {
            gui_itoa((S32) g_ph_cntx.ph_mms_profile_p->proxy_port, (U16*) g_ph_cntx.profile_display_p->proxy_port, 10);
        }
    }

    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {

        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip1, (U8) g_ph_cntx.ph_wap_profile_p->proxy_ip[0]);
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip2, (U8) g_ph_cntx.ph_wap_profile_p->proxy_ip[1]);
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip3, (U8) g_ph_cntx.ph_wap_profile_p->proxy_ip[2]);
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip4, (U8) g_ph_cntx.ph_wap_profile_p->proxy_ip[3]);

        SetInlineItemIP4(
            (wgui_inline_items + PH_CONN_TYPE_IP_ADDRESS),
            (U8*) g_ph_cntx.profile_display_p->ip1,
            (U8*) g_ph_cntx.profile_display_p->ip2,
            (U8*) g_ph_cntx.profile_display_p->ip3,
            (U8*) g_ph_cntx.profile_display_p->ip4,
            PreparedIPAddressString);

    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip1, (U8) g_ph_cntx.ph_mms_profile_p->proxy_ip[0]);
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip2, (U8) g_ph_cntx.ph_mms_profile_p->proxy_ip[1]);
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip3, (U8) g_ph_cntx.ph_mms_profile_p->proxy_ip[2]);
        ReturnThreeDigitString(g_ph_cntx.profile_display_p->ip4, (U8) g_ph_cntx.ph_mms_profile_p->proxy_ip[3]);

        SetInlineItemIP4(
            (wgui_inline_items + PH_CONN_TYPE_IP_ADDRESS),
            (U8*) g_ph_cntx.profile_display_p->ip1,
            (U8*) g_ph_cntx.profile_display_p->ip2,
            (U8*) g_ph_cntx.profile_display_p->ip3,
            (U8*) g_ph_cntx.profile_display_p->ip4,
            PreparedIPAddressString);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_selected_profile_content_data
 * DESCRIPTION
 *  This gets the content data for the profile index selected()
 *  its general for browser & MMS profiles
 * PARAMETERS
 *  profile_index       [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_selected_profile_content_data(U8 profile_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        if (g_ph_cntx.ph_wap_profile_p == NULL)
        {
            g_ph_cntx.ph_wap_profile_p =
                (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
        }
        /* Itishree Adds */
        if (g_ph_cntx.ph_wap_profile_p == NULL)
        {
            ASSERT(0);
        }
        /* Itishree Ends */
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        if (g_ph_cntx.ph_mms_profile_p == NULL)
        {
            g_ph_cntx.ph_mms_profile_p =
                (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
        }
        /* Itishree Adds */
        if (g_ph_cntx.ph_mms_profile_p == NULL)
        {
            ASSERT(0);
        }
        /* Itishree Ends */
    }
    mmi_ph_get_profile_nvram_content_data(profile_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_activated_profile_index
 * DESCRIPTION
 *  THis API returns the activated profile index
 * PARAMETERS
 *  void
 * RETURNS
 *  U8    activated profile index
 *****************************************************************************/
U8 mmi_ph_get_activated_profile_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_ph_cntx.profile_module == PH_BROWSER_PROFILE) || (g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE))      /* added by tk */
    {
        ReadValue(NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX, &g_ph_cntx.wap_actived_profile_index, DS_BYTE, &error);
        return g_ph_cntx.wap_actived_profile_index;
    }
    else if ((g_ph_cntx.profile_module == PH_MMS_PROFILE) || (g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE)) /* added by tk */
    {
        ReadValue(NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX, &g_ph_cntx.mms_actived_profile_index, DS_BYTE, &error);
        return g_ph_cntx.mms_actived_profile_index;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_check_data_account_type
 * DESCRIPTION
 *  It checks the data account type(CSD or GPRS) for the index passed
 * PARAMETERS
 *  account_index       [IN]        Data account index
 * RETURNS
 *  void
 *****************************************************************************/
ph_data_account_enum mmi_ph_check_data_account_type(U8 account_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (custom_get_csd_profile_num() > account_index)
    {
        return PH_DATA_ACCOUNT_CSD;
    }
    else if ((custom_get_gprs_profile_num() + custom_get_csd_profile_num()) >= account_index)
    {
        return PH_DATA_ACCOUNT_GPRS;
    }
    else
    {
        return PH_DATA_ACCOUNT_INVALID;
    }
}

/* This fun is not currently in use  Itishree */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_GPRS_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_GPRS_FEATURES__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_GPRS_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_GPRS_FEATURES__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_handle_get_data_account_name
 * DESCRIPTION
 *  It API checks for the profile module & then depending upon the
 *  data account type associated ,send the request to the L4 to get the data account info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_handle_get_data_account_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_ph_handle_get_data_account_name");
    if (g_ph_cntx.profile_display_p == NULL)
    {
        g_ph_cntx.profile_display_p =
            (ph_show_editable_profile_struct*) jdd_MemAlloc(sizeof(ph_show_editable_profile_struct), 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.profile_display_p == NULL)
    {
        ASSERT(0);
    }
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        mmi_dtcnt_get_account_name(
            g_ph_cntx.ph_wap_profile_p->data_account,
            (S8*) g_ph_cntx.profile_display_p->data_account_name,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        mmi_dtcnt_get_account_name(
            g_ph_cntx.ph_mms_profile_p->data_account,
            (S8*) g_ph_cntx.profile_display_p->data_account_name,
            MAX_DATA_ACCOUNT_NAME_LEN);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%s", "Data Account Name: ",
                         g_ph_cntx.profile_display_p->data_account_name);
    mmi_ph_entry_edit_selected_profile();
}

/* This function is not currently in Use */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_profile_name_list
 * DESCRIPTION
 *  This API extracts profile names from the g_ph_cntx.ph_wap_prof_name_arr_p,& g_ph_cntx.ph_mms_prof_name_arr_p
 *  into the subMenuData to be displayed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_profile_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_ph_cntx.profile_module == PH_BROWSER_PROFILE) || (g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE))
    {
        for (index = 0; index < NVRAM_WAP_PROFILE_MAX; index++)
        {
            if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs == PH_DCS_UCS)
            {
                mmi_ucs2cpy(
                    (S8*) (S8*) subMenuData[index],
                    (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name));
            }
            else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs == PH_DCS_ASCII)
            {
                mmi_asc_to_ucs2(
                    (S8*) subMenuData[index],
                    (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name));
            }

        }
    }
    else if ((g_ph_cntx.profile_module == PH_MMS_PROFILE) || (g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE))
    {
        for (index = 0; index < NVRAM_MMS_PROFILE_MAX; index++)
        {
            if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs == PH_DCS_UCS)
            {
                mmi_ucs2cpy(
                    (S8*) (S8*) subMenuData[index],
                    (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name));
            }
            else if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs == PH_DCS_ASCII)
            {
                mmi_asc_to_ucs2(
                    (S8*) subMenuData[index],
                    (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name));
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_activated_wap_profile
 * DESCRIPTION
 *  It returns the pointer to the activated wap profile content struct
 * PARAMETERS
 *  void
 * RETURNS
 *  g_ph_cntx.ph_activated_wap_profile
 *****************************************************************************/
nvram_wap_profile_content_struct *mmi_ph_get_activated_wap_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ph_cntx.ph_activated_wap_profile;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_activated_mms_profile
 * DESCRIPTION
 *  It returns the pointer to the activated MMS profile content struct
 * PARAMETERS
 *  void
 * RETURNS
 *  g_ph_cntx.ph_activated_mms_profile
 *****************************************************************************/
nvram_mms_profile_content_struct *mmi_ph_get_activated_mms_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ph_cntx.ph_activated_mms_profile;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_brw_get_activated_profile_homepage
 * DESCRIPTION
 *  It retreives the activated profile data and returns the homepage url of the activated profile
 * PARAMETERS
 *  void
 * RETURNS
 *  g_ph_cntx.ph_activated_wap_profile->homepage_url the homepage url of the activated profile
 *****************************************************************************/
U8 *mmi_ph_brw_get_activated_profile_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_activated_wap_profile == NULL)
    {
        g_ph_cntx.ph_activated_wap_profile =
            (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
        /* Itishree Adds */
        if (g_ph_cntx.ph_activated_wap_profile == NULL)
        {
            ASSERT(0);
        }
        /* Itishree Ends */
        mmi_ph_get_activated_profile_data(PH_BROWSER_PROFILE, g_ph_cntx.wap_actived_profile_index);
    }
    return (U8*) (g_ph_cntx.ph_activated_wap_profile->homepage_url);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_brw_set_activated_profile_homepage
 * DESCRIPTION
 *  It sets the url passed as the homepage url of the activated WAP profile
 * PARAMETERS
 *  homepage_url_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_brw_set_activated_profile_homepage(U8 *homepage_url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((S8*) homepage_url_p);
    if (len >= NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN)
    {
        len = NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN - 1;
    }

    memcpy(g_ph_cntx.ph_activated_wap_profile->homepage_url, homepage_url_p, len);
    g_ph_cntx.ph_activated_wap_profile->homepage_url[len] = '\0';
    mmi_ph_update_nvram_activated_wap_profile();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_mms_get_activated_profile_mmsc_url
 * DESCRIPTION
 *  It returns the mmsc url associalted with the activated mms profile
 * PARAMETERS
 *  void
 * RETURNS
 *  g_ph_cntx.ph_activated_mms_profile->mmsc_url   mmsc url of the activated profile
 *****************************************************************************/
U8 *mmi_ph_mms_get_activated_profile_mmsc_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_activated_mms_profile == NULL)
    {
        g_ph_cntx.ph_activated_mms_profile =
            (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
        /* Itishree Adds */
        if (g_ph_cntx.ph_activated_mms_profile == NULL)
        {
            ASSERT(0);
        }
        /* Itishree Ends */
        mmi_ph_get_activated_profile_data(PH_MMS_PROFILE, g_ph_cntx.mms_actived_profile_index);
    }

    return (U8*) (g_ph_cntx.ph_activated_mms_profile->mmsc_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_activated_prof_id_req_hdlr
 * DESCRIPTION
 *  This is the request handler for MSG_ID_WAP_GET_BRA_PROF_ID_REQ request ID ,it in turns retruns teh activated profile index
 * PARAMETERS
 *  req_src_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_activated_prof_id_req_hdlr(module_type req_src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE Message;

    wap_get_bra_prof_id_rsp_struct *prof_id_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_id_rsp = (wap_get_bra_prof_id_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_bra_prof_id_rsp_struct));
    prof_id_rsp->prof_id = g_ph_cntx.mms_actived_profile_index;
    prof_id_rsp->net_id = g_ph_cntx.ph_activated_wap_profile->data_account;

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = req_src_id;
    Message.oslMsgId = MSG_ID_WAP_GET_BRA_PROF_ID_RSP;
    Message.oslDataPtr = (oslParaType*) prof_id_rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_prof_list_req_hdlr
 * DESCRIPTION
 *  It is the request handler for the MSG_ID_WAP_GET_PROF_LIST_REQ ,it in turns returns the profiel name list as the response
 * PARAMETERS
 *  req_src_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_prof_list_req_hdlr(module_type req_src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_prof_list_rsp_struct *prof_list_rsp = NULL;
    ilm_struct *ilm_ptr = NULL;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_list_rsp =
        (wap_get_prof_list_rsp_struct*) construct_local_para(sizeof(wap_get_prof_list_rsp_struct), TD_CTRL);

    prof_list_rsp->result = PH_PROFILE_SUCCESS;
    prof_list_rsp->number = NVRAM_WAP_PROFILE_MAX;
    prof_list_rsp->prof_list =
        (wap_prof_entry_struct*) OslMalloc((sizeof(wap_prof_entry_struct)) * NVRAM_WAP_PROFILE_MAX);
    /* Itishree Adds */
    if (prof_list_rsp->prof_list == NULL)
    {
        ASSERT(0);
    }
    /* Itishree Ends */
    mmi_ph_get_brw_profile_name_list();

    for (index = 0; index < NVRAM_WAP_PROFILE_MAX; index++)
    {
        U8 *temp_profile_name = g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name;

        memset(prof_list_rsp->prof_list[index].name.value, 0, NVRAM_WAP_PROFILE_NAME_LEN - 1);  /* Length is 40 */
        if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs == PH_DCS_ASCII)
        {

            U32 len = strlen((S8*) temp_profile_name);

            if (len >= NVRAM_WAP_PROFILE_NAME_LEN / 2)
            {
                len = (NVRAM_WAP_PROFILE_NAME_LEN / 2) - 1;
            }
            mmi_asc_n_to_ucs2((S8*) (prof_list_rsp->prof_list[index].name.value), (S8*) temp_profile_name, len);
            prof_list_rsp->prof_list[index].name.len = (len * ENCODING_LENGTH);
        }
        else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs == PH_DCS_UCS)
        {
            U32 len = mmi_ucs2strlen((S8*) temp_profile_name);

            mmi_ucs2ncpy((S8*) (prof_list_rsp->prof_list[index].name.value), (S8*) temp_profile_name, len);
            prof_list_rsp->prof_list[index].name.len = (len * ENCODING_LENGTH);
        }
        prof_list_rsp->prof_list[index].id = index;

        if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].conn_type == PH_CONN_TYPE_HTTP)
        {
            prof_list_rsp->prof_list[index].conn_type = WAP_PROF_CONN_TYPE_HTTP;
        }
        else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].conn_type ==
                 PH_CONN_TYPE_CONNECTION_OREINTED)
        {
            prof_list_rsp->prof_list[index].conn_type = WAP_PROF_CONN_TYPE_WSP_CO;
        }
        else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].conn_type ==
                 PH_CONN_TYPE_CONNECTION_OREINTED_SECURE)
        {
            prof_list_rsp->prof_list[index].conn_type = WAP_PROF_CONN_TYPE_WSP_CO;
        }
    }
    if (g_ph_cntx.ph_wap_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_wap_prof_name_arr_p);
        g_ph_cntx.ph_wap_prof_name_arr_p = NULL;

    }
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) prof_list_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_GET_PROF_LIST_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    if (req_src_id == MOD_J2ME)
    {
        SEND_ILM(MOD_WAP, MOD_J2ME, WAP_J2ME_SAP, ilm_ptr);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Profile Name List Response sent to Java Task\n");
    }
    else if (req_src_id == MOD_MMI)
    {
        /* since in jataayu solution MOD_WAP, MOD_MMI are part of MMI task only */
        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = WAP_MMI_SAP;
        msg_send_ext_queue(ilm_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_prof_content_req_hdlr
 * DESCRIPTION
 *  It is the rquest handler for the MSG_ID_WAP_GET_PROF_CONTENT_REQ request from the java task
 *  this in turn returns the profiel content data as the response
 * PARAMETERS
 *  req_src_id      [IN]        
 *  msg             [IN]        This is pointer to profile content req struct sent by java task
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_prof_content_req_hdlr(module_type req_src_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    ilm_struct *ilm_ptr = NULL;

    wap_get_prof_content_rsp_struct *prof_cont_rsp = NULL;
    wap_get_prof_content_req_struct *content_req_ptr = NULL;
    nvram_wap_profile_content_struct *prov_wap_profile = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    content_req_ptr = (wap_get_prof_content_req_struct*) msg;

    prof_cont_rsp =
        (wap_get_prof_content_rsp_struct*) construct_local_para(sizeof(wap_get_prof_content_rsp_struct), TD_CTRL);

    if (prov_wap_profile == NULL)
    {
        prov_wap_profile = (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
    }
    /* Itishree Adds */
    if (prov_wap_profile == NULL)
    {
        ASSERT(0);
    }
    /* Itishree Ends */

    ReadRecord(
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        (U16) (content_req_ptr->id + 1),
        prov_wap_profile,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        &error);

    prof_cont_rsp->result = PH_PROFILE_SUCCESS;

    if (prov_wap_profile->conn_type == PH_CONN_TYPE_HTTP)
    {
        prof_cont_rsp->conn_type = WAP_PROF_CONN_TYPE_HTTP;
    }
    else if (prov_wap_profile->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED)
    {
        prof_cont_rsp->conn_type = WAP_PROF_CONN_TYPE_WSP_CO;
    }
    else if (prov_wap_profile->conn_type == PH_CONN_TYPE_CONNECTION_OREINTED_SECURE)
    {
        prof_cont_rsp->conn_type = WAP_PROF_CONN_TYPE_WSP_CO;
    }

    prof_cont_rsp->net_id = prov_wap_profile->data_account;
    prof_cont_rsp->id = content_req_ptr->id;

    memset(prov_wap_profile->password, 0, NVRAM_WAP_PROFILE_PASSWORD_LEN);
    if (prov_wap_profile->password == NULL)
    {
        prof_cont_rsp->password[0] = '\0';
    }
    else if (strlen((S8*) prov_wap_profile->password) >= NVRAM_WAP_PROFILE_PASSWORD_LEN)
    {
        ASSERT(0);
    }
    else
    {
        strcpy((S8*) prof_cont_rsp->password, (S8*) prov_wap_profile->password);
    }

    memset(prov_wap_profile->username, 0, NVRAM_WAP_PROFILE_USERNAME_LEN);
    if (prov_wap_profile->username == NULL)
    {
        prof_cont_rsp->username[0] = '\0';
    }
    else if (strlen((S8*) prov_wap_profile->username) >= NVRAM_WAP_PROFILE_USERNAME_LEN)
    {
        ASSERT(0);
    }
    else
    {
        strcpy((S8*) prof_cont_rsp->username, (S8*) prov_wap_profile->username);
    }

    memset(prof_cont_rsp->prx_ip, 0, 4);
    memcpy(prof_cont_rsp->prx_ip, prov_wap_profile->proxy_ip, 4);

    prof_cont_rsp->prx_port = prov_wap_profile->proxy_port;

    jdd_MemFree(prov_wap_profile);
    prov_wap_profile = NULL;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) prof_cont_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_GET_PROF_CONTENT_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    if (req_src_id == MOD_J2ME)
    {
        SEND_ILM(MOD_WAP, req_src_id, WAP_J2ME_SAP, ilm_ptr);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Profile Content Response sent to Java Task\n");
    }
    else if (req_src_id == MOD_MMI)
    {
        /* since in jataayu solution MOD_WAP, MOD_MMI are part of MMI task only */
        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = WAP_MMI_SAP;
        msg_send_ext_queue(ilm_ptr);
    }
}

/* Itishree Starts */
#ifdef __MMI_JATAAYU_CCA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_install_brw_profile
 * DESCRIPTION
 *  This API installs browser settings from provisioning data
 * PARAMETERS
 *  profile_list        [IN]        
 *  bkm_list            [IN]        
 *  profile_count       [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_ph_install_brw_profile(
                prov_wap_profile_list_struct *profile_list,
                prov_bkm_list_struct *bkm_list,
                U8 profile_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    PROV_RETCODE ret_code = PROV_OK;
    PROV_RETCODE err_code = PROV_OK;

    g_bkm_list_p = (prov_bkm_list_struct*) bkm_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_ph_install_brw_profile");
    g_profile_list_count = profile_count;

    if (bkm_list != NULL && profile_list == NULL)   /* This condition is for when there are only bookmark settings */
    {
        err_code = mmi_ph_check_for_prov_bookmark(g_bkm_list_p);
        if (err_code == PROV_BKM_INVALID)
        {
            g_ph_setting_installed_flag = PROV_ERR;
        }
        else if (err_code == PROV_BKM_OK)
        {
            g_ph_setting_installed_flag = PROV_OK;
        }
        else if (err_code == PROV_BKM_FULL)
        {
            g_ph_setting_installed_flag = PROV_SETTING_SKIPPED;
        }

        mmi_prov_show_next_profile_info(MMI_FALSE);
    }

    if (profile_list != NULL)
    {
        g_prov_profile_name_p = (PU8) profile_list->profile_name;
        g_ph_cntx.ph_wap_profile_p = profile_list->profile_content;

        result = mmi_ph_check_for_empty_profile(PH_BROWSER_PROV_PROFILE);
        if (result == MMI_TRUE)
        {
            g_ph_cntx.profile_module = PH_BROWSER_PROV_PROFILE; /* This is set bcoz it is necessary when activating the profile(Not to display the popup "Activated" ) */
            err_code = mmi_ph_check_for_prov_bookmark(g_bkm_list_p);
            mmi_ph_update_prov_nvram_wap_profile();
            g_ph_setting_installed_flag = PROV_OK;

            if (g_profile_list_count == 1 || g_ph_activated_flag == 0x00)
            {
                mmi_ph_activate_selected_profile();
                g_ph_activated_flag = 0x01;
            }

            mmi_prov_show_next_profile_info(MMI_FALSE);
        }
        else
        {
            mmi_ph_pre_entry_show_profile_list_menu(PH_BROWSER_PROV_PROFILE);
        }
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_check_for_prov_bookmark
 * DESCRIPTION
 *  This API installs bookmark settings from provisioning data
 * PARAMETERS
 *  bkm_list        [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_ph_check_for_prov_bookmark(prov_bkm_list_struct *bkm_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_RETCODE result = PROV_BKM_OK;
    U8 count = 0;
    S8 bookmark_title[MMI_BRW_BKM_MAX_TITLE_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_ph_check_for_prov_bookmark");
    while (bkm_list != NULL)
    {
        if (bkm_list->bkm_content != NULL)
        {
            mmi_chset_utf8_to_ucs2_string(
                (U8*) bookmark_title,
                (MMI_BRW_BKM_MAX_TITLE_LENGTH * ENCODING_LENGTH),
                (U8*) bkm_list->bkm_content->bm_title);

            result = mmi_brw_add_prov_bookmark((U8*) bookmark_title, (U8*) (U8*) bkm_list->bkm_content->bm_url);
            if (((result == PROV_BKM_FULL) || (result == PROV_BKM_INVALID)) && count == 0)
            {
                g_bkm_list_p = NULL;
                return result;
            }
            else if (result == PROV_BKM_FULL)
            {
                break;
            }
        }
        bkm_list = bkm_list->bkm_list_next;
        count++;
    }
    g_bkm_list_p = NULL;
    return PROV_BKM_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_install_mms_profile
 * DESCRIPTION
 *  This API installs MMS settings from provisiong data
 * PARAMETERS
 *  profile_list        [IN]        
 *  profile_count       [IN]        
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_ph_install_mms_profile(prov_mms_profile_list_struct *profile_list, U8 profile_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL empty_profile = MMI_TRUE;
    JC_BOOLEAN result = E_FALSE;
    PROV_RETCODE ret_code = PROV_OK;
    ph_data_account_enum data_account;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_ph_install_mms_profile");
    ASSERT(profile_list);
    g_profile_list_count = profile_count;

    /* To check data Account Type */

    data_account = mmi_ph_check_data_account_type(profile_list->profile_content->data_account);

    if ((data_account == PH_DATA_ACCOUNT_CSD) || (!mmi_ph_prevalidate_mms_profile(profile_list)))
    {
        if (g_ph_setting_installed_flag != PROV_OK)
        {
            g_ph_setting_installed_flag = PROV_ERR;
        }
        mmi_prov_show_next_profile_info(MMI_FALSE);
        return ret_code;
    }

    g_prov_profile_name_p = (PU8) profile_list->profile_name;
    g_ph_cntx.ph_mms_profile_p = profile_list->profile_content;

    empty_profile = mmi_ph_check_for_empty_profile(PH_MMS_PROV_PROFILE);
    g_ph_cntx.profile_module = PH_MMS_PROV_PROFILE;

    if (empty_profile == MMI_TRUE)
    {
        /* Check for activated profile in use or not */
    #if defined MMS_SUPPORT
        result = mmi_jmms_is_mms_profile_in_use();
    #endif 
        if (result == E_TRUE)
        {
            mmi_ph_update_prov_nvram_mms_profile(); /* New profile replaces the empty profile & doesn't activate */
        }
        else
        {
            mmi_ph_update_prov_nvram_mms_profile();
            if (g_profile_list_count == 1 || g_ph_activated_flag == 0x00)
            {
                mmi_ph_activate_selected_profile();
                g_ph_activated_flag = 0x01;
            }
        }
        g_ph_setting_installed_flag = PROV_OK;
        mmi_prov_show_next_profile_info(MMI_FALSE);
    }
    else
    {
        mmi_ph_pre_entry_show_profile_list_menu(PH_MMS_PROV_PROFILE);
    }
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_prevalidate_mms_profile
 * DESCRIPTION
 *  This API pre validates MMS settings from provisiong data
 * PARAMETERS
 *  profile_list        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ph_prevalidate_mms_profile(prov_mms_profile_list_struct *profile_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 url[PROV_PROFILE_MMSC_URL_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) url, (S8*) profile_list->profile_content->mmsc_url);
    return mmi_brw_validate_url(url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_check_for_empty_profile
 * DESCRIPTION
 *  This API checks for empty profile(Browser and MMS)
 * PARAMETERS
 *  profile     [IN]        Type of the profile(Browser,MMS)
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ph_check_for_empty_profile(ph_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S16 error;
    nvram_wap_profile_content_struct *wap_profile_content = NULL;
    nvram_mms_profile_content_struct *mms_profile_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check empty profile for Browser */
    if (profile == PH_BROWSER_PROV_PROFILE)
    {
        for (index = 7; index < NVRAM_WAP_PROFILE_MAX; index++)
        {
            if (wap_profile_content == NULL)
            {
                wap_profile_content =
                    (nvram_wap_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE, 1);
            }
            if (wap_profile_content == NULL)
            {
                ASSERT(0);
            }
            ReadRecord(
                NVRAM_EF_WAP_PROFILE_CONTENT_LID,
                (U16) (index + 1),
                wap_profile_content,
                NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
                &error);
            if (wap_profile_content->empty == 1)
            {
                g_ph_cntx.profile_index = index;

                if (wap_profile_content != NULL)
                {
                    jdd_MemFree(wap_profile_content);
                    wap_profile_content = NULL;
                }
                return MMI_TRUE;
            }

        }
        if (wap_profile_content != NULL)
        {
            jdd_MemFree(wap_profile_content);
            wap_profile_content = NULL;
        }
    }
    else if (profile == PH_MMS_PROV_PROFILE)    /* Check empty profile for MMS */
    {

        for (index = 7; index < NVRAM_MMS_PROFILE_MAX; index++)
        {
            if (mms_profile_content == NULL)
            {
                mms_profile_content =
                    (nvram_mms_profile_content_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE, 1);
            }
            if (mms_profile_content == NULL)
            {
                ASSERT(0);
            }
            ReadRecord(
                NVRAM_EF_MMS_PROFILE_CONTENT_LID,
                (U16) (index + 1),
                mms_profile_content,
                NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
                &error);
            if (mms_profile_content->empty == 1)
            {
                g_ph_cntx.profile_index = index;

                if (mms_profile_content != NULL)
                {
                    jdd_MemFree(mms_profile_content);
                    mms_profile_content = NULL;
                }
                return MMI_TRUE;
            }

        }
        if (mms_profile_content != NULL)
        {
            jdd_MemFree(mms_profile_content);
            mms_profile_content = NULL;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_selected_profile
 * DESCRIPTION
 *  This API updates seleted profile(Browser or MMS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_selected_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_BOOLEAN result = E_FALSE;
    PROV_RETCODE err_code = PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_module == PH_BROWSER_PROV_PROFILE)
    {
        err_code = mmi_ph_check_for_prov_bookmark(g_bkm_list_p);
        mmi_ph_update_prov_nvram_wap_profile();
        g_ph_setting_installed_flag = PROV_OK;

        if (g_profile_list_count == 1 || g_ph_activated_flag == 0x00)
        {
            mmi_ph_activate_selected_profile();
            g_ph_activated_flag = 0x01;
        }

        mmi_prov_show_next_profile_info(MMI_TRUE);
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROV_PROFILE)
    {
        /* Check for activated profile */
    #if defined MMS_SUPPORT
        result = mmi_jmms_is_mms_profile_in_use();
    #endif 
        if (result == E_TRUE && (g_ph_cntx.profile_index == g_ph_cntx.mms_actived_profile_index))
        {
            mmi_ph_profile_in_use_notification();
            return;
        }
        else if ((result == E_TRUE && (g_ph_cntx.profile_index != g_ph_cntx.mms_actived_profile_index)) ||
                 (result == E_FALSE && (g_ph_cntx.profile_index == g_ph_cntx.mms_actived_profile_index)))
        {
            mmi_ph_update_prov_nvram_mms_profile();
            g_ph_setting_installed_flag = PROV_OK;
        }
        else if (result == E_FALSE && (g_ph_cntx.profile_index != g_ph_cntx.mms_actived_profile_index))
        {
            mmi_ph_update_prov_nvram_mms_profile();
            g_ph_setting_installed_flag = PROV_OK;
            if (g_profile_list_count == 1 || g_ph_activated_flag == 0x00)
            {
                mmi_ph_activate_selected_profile();
                g_ph_activated_flag = 0x01;
            }
        }
        mmi_prov_show_next_profile_info(MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_profile_in_use_notification
 * DESCRIPTION
 *  Profile in use screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_profile_in_use_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PROF_HDLR_PROFILE_IN_USE, NULL, mmi_ph_profile_in_use_notification, NULL);

    ShowCategory164Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL,
        NULL,
        STR_ID_CCA_PROFILE_IN_USE,
        IMG_GLOBAL_WARNING,
        NULL);

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_prov_end_key_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_reset_flags
 * DESCRIPTION
 *  Reset all flags
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_reset_flags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ph_activated_flag = 0x00;
    g_ph_setting_installed_flag = PROV_SETTING_SKIPPED;
    g_prov_profile_name_p = NULL;
    g_ph_cntx.ph_mms_profile_p = NULL;
    g_ph_cntx.ph_wap_profile_p = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_setting_installed_flag
 * DESCRIPTION
 *  This API returns TRUE or FALSE depending any profile successfully installed or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
PROV_RETCODE mmi_ph_get_setting_installed_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ph_setting_installed_flag;

}

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
#endif /* _JPROFILEUIHANDLER_C */ 


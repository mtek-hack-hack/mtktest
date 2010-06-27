/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSMessageSettings.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the ui and NVRAm integration for message settings
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
#if defined (__MMI_MMS_2__) && defined(MMS_SUPPORT)

/***************************************************************************** 
* Include
*****************************************************************************/

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "MainMenuDef.h"
#include "AlarmFrameWorkProt.h"
#include "MessagesMiscell.h"
#include "ProtocolEvents.h"
#include "CallManagementGprot.h"
#include "FileManagerGProt.h"
#include "app_mine.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"

#include "mmsadp.h"
#include "MMSAppResDef.h"
#include "MMSMessageSettingsUtils.h"
#include "MMSMessageSettings.h"
#include "MMSMessageTemplates.h"
#include "MMSMsgCommonProt.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif 
#include "MMSAppProt.h"
#include "MMSAppGprot.h"
#include "ProfileHandlerTypes.h"

#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#include "custom_wap_config.h"
extern U8 global_mms_version;
static U8 g_reply_charging_done = 0;        /* /to check whether something done in reply charging screen */
static U8 g_recieve_filter_done = E_OFF;    /* /to check whether something done in filters screen */
static U8 g_compose_signature_done = E_OFF;
static void mmi_umms_image_preview(void);
#if (!defined(__MMI_SHOW_FILE_EXT__))
static S8 g_file_ext[UMMS_SIGNATURE_OBJECTS][UMMS_SIGNATURE_EXT_LENGTH];
#endif
umms_context_struct temp_context;
umms_context_struct *g_umms_context = &temp_context;
umms_memory_status_struct g_memory_status;
umms_compose_signature_inline_items_enum g_signature_current_highlighted;
/***************************************************************************** 
* Global Function
*****************************************************************************/

extern void set_leading_zero(U8 u8type);
extern void mmi_brw_prof_pre_entry_show_profile_list_menu(prof_profile_enum profile);
extern S32 mmi_uc_resize_image(U8 *file, U8 *dest_file, U32 resize_w, U32 resize_h);


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_message_settings_init
 * DESCRIPTION
 *  This function init the hilight handlers of message settings menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_message_settings_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mESSAGE sETTINGS options Highlight handlers */

    SetHiliteHandler(MENU_ID_UMMS_MMS_SETTINGS_COMPOSE, mmi_umms_highlight_compose_setings);
    SetHiliteHandler(MENU_ID_UMMS_MMS_SETTINGS_SENDING, mmi_umms_highlight_sending_setings);
    SetHiliteHandler(MENU_ID_UMMS_MMS_SETTINGS_RETRIEVAL, mmi_umms_highlight_retrieval_setings);
    SetHiliteHandler(MENU_ID_UMMS_MMS_SETTINGS_EDIT_PROFILE, mmi_umms_highlight_edit_profile);
    SetHiliteHandler(MENU_ID_UMMS_MMS_SETTINGS_MEMORY_STATUS, mmi_umms_highlight_memory_status);

	SetHiliteHandler(MENU_ID_UMMS_SIGNATURE_OPTION_VIEW, mmi_umms_highlight_view_signature);
	SetHiliteHandler(MENU_ID_UMMS_SIGNATURE_OPTION_SELECT, mmi_umms_highlight_select_signature);
	SetHiliteHandler(MENU_ID_UMMS_SIGNATURE_OPTION_DELETE, mmi_umms_highlight_delete_signature);
    
    mmi_umms_read_nvram_message_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_compose_setings
 * DESCRIPTION
 *  This function is the highlight handler of compose message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_compose_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_compose_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_compose_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_compose_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_sending_setings
 * DESCRIPTION
 *  This function is the highlight handler of sending message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_sending_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_sending_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_sending_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_sending_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_retrieval_setings
 * DESCRIPTION
 *  This function is the highlight handler of retrieval message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_retrieval_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_retrieval_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_retrieval_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_retrieval_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_edit_profile
 * DESCRIPTION
 *  This function is the highlight handler of edit profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_edit_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_profile_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_profile_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_profile_settings, KEY_WAP, KEY_EVENT_DOWN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_memory_status
 * DESCRIPTION
 *  This function is the highlight handler of memory sttaus item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_memory_status, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_memory_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_memory_status, KEY_WAP, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_view_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_view_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_compose_image_view, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_compose_image_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_compose_image_view, KEY_WAP, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_delete_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_delete_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_compose_reference_delete, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_compose_reference_delete, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_compose_reference_delete, KEY_WAP, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_select_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_select_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	SetLeftSoftkeyFunction(mmi_umms_compose_select_from_file_manager, KEY_EVENT_UP);
	SetKeyHandler(mmi_umms_compose_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_umms_compose_select_from_file_manager, KEY_WAP, KEY_EVENT_DOWN);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_read_nvram_message_settings
 * DESCRIPTION
 *  Read the the message settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_read_nvram_message_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_umms_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    if (g_umms_context->nvram_compose_settings.layout == 0xFF)
    {
    #ifdef __MMI_MMS_SIGNATURE__
        g_umms_context->nvram_compose_settings.auto_signature = (U8) E_OFF;
    #endif 
        g_umms_context->nvram_compose_settings.best_page_duration = (U8) E_OFF;
        g_umms_context->nvram_compose_settings.creation_mode = (U8) E_CREAT_MODE_FREE;
        g_umms_context->nvram_compose_settings.image_resize_option = (U8) E_IMAGE_RESIZE_OFF;
    #ifdef __DRM_SUPPORT__
        g_umms_context->nvram_compose_settings.add_drm = (U8) E_OFF;
    #endif 
        g_umms_context->nvram_compose_settings.layout = (U8) E_MMS_LAYOUT_POTRAIT;
    #ifdef __MMI_MMS_SIGNATURE__
        memset(
            g_umms_context->nvram_compose_settings.auto_signature_content,
            0x00,
            (UMMS_MAX_AUTO_SIGN_LENGTH + 1) * ENCODING_LENGTH);

        memset(
            g_umms_context->nvram_compose_settings.auto_signature_image_file,
            0x00,
            (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
        memset(
            g_umms_context->nvram_compose_settings.auto_signature_audio_file,
            0x00,
            (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
        memset(
            g_umms_context->nvram_compose_settings.auto_signature_video_file,
            0x00,
            (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);

    #endif /* __MMI_MMS_SIGNATURE__ */ 
        g_umms_context->nvram_compose_settings.max_no_pages = (U8) UMMS_MAX_POSSIBLE_SLIDES;
        g_umms_context->nvram_compose_settings.default_slide_time = ((U32) UMMS_DEFAULT_SLIDE_DURATION) / 1000; /* /convert to seconds */

        WriteRecord(
            NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
            1,
            &g_umms_context->nvram_compose_settings,
            NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
            1,
            &g_umms_context->nvram_compose_settings,
            NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
            &error);
    }

    ReadRecord(
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        1,
        &g_umms_context->nvram_sending_settings,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        &error);

    if (g_umms_context->nvram_sending_settings.delivery_report == 0xFF)
    {
        g_umms_context->nvram_sending_settings.deadline_for_reply = (U32) 0;
        g_umms_context->nvram_sending_settings.delivery_report = (U8) UMMS_DEFAULT_DELIVERY_REPORT_DURING_SENDING;
        g_umms_context->nvram_sending_settings.delivery_time = (U8) E_IMMEDIATE;
        g_umms_context->nvram_sending_settings.hide_sender = (U8) E_OFF;
        g_umms_context->nvram_sending_settings.send_and_save = (U8) E_OFF;
        g_umms_context->nvram_sending_settings.priority = (U8) E_PRIORITY_NORMAL;
        g_umms_context->nvram_sending_settings.read_report = (U8) UMMS_DEFAULT_READ_REPORT_DURING_SENDING;
        g_umms_context->nvram_sending_settings.reply_charging = (U8) E_OFF;
        g_umms_context->nvram_sending_settings.request_type = (U8) E_FULL_MMS;
        g_umms_context->nvram_sending_settings.size = (U32) 0;
        g_umms_context->nvram_sending_settings.validity_period = (U8) E_VALIDITY_PERIOD_MAX;

        WriteRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_umms_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_umms_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);
    }

    ReadValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_umms_context->nvram_retrieval_settings, DS_DOUBLE, &error);

    if (g_umms_context->nvram_retrieval_settings.home_network == 0xFF)
    {
        g_umms_context->nvram_retrieval_settings.home_network = (U8) UMMS_DEFAULT_HOME_RETRIEVAL_MODE;
        g_umms_context->nvram_retrieval_settings.roaming = (U8) UMMS_DEFAULT_ROAMING_RETRIEVAL_MODE;
        g_umms_context->nvram_retrieval_settings.anonymous_filter = (U8) UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE;
        g_umms_context->nvram_retrieval_settings.advertisement_filter = (U8) UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE;
        g_umms_context->nvram_retrieval_settings.read_report = (U8) UMMS_DEFAULT_READ_REPORT_DURING_RETRIEVAL;
        g_umms_context->nvram_retrieval_settings.delivery_report = (U8) UMMS_DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL;
    #ifndef __MMI_MMS_OMA_CONF_273__
        g_umms_context->nvram_retrieval_settings.msgsize_filter = (U16) wap_custom_get_max_mms_msg_size();
    #endif 
        WriteValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_umms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
        ReadValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_umms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
    }
    g_umms_context->on_bootup = TRUE;
    mmi_umms_set_setting_to_mma_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_setting_to_mma_req
 * DESCRIPTION
 *  This function send the request to MMA to set the setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_setting_to_mma_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_setting_req_struct *msgSet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgSet = (wap_mma_set_setting_req_struct*) OslConstructDataPtr(sizeof(*msgSet));

    msgSet->req_id = wap_mma_get_request_id();
    msgSet->app_id = MMA_APP_ID_SETTING;
    msgSet->mms_version = wap_custom_get_mms_version(); /* global_mms_version */

    g_umms_context->request_id = msgSet->req_id;

    mmi_umms_fill_settings_for_mma(msgSet);

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SET_SETTING_REQ, (oslParaType*) msgSet, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_setting_rsp
 * DESCRIPTION
 *  This function is response handler to set the seeting request.
 * PARAMETERS
 *  InMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_setting_rsp(void *InMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_set_setting_rsp_struct *set_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_rsp = (wap_mma_set_setting_rsp_struct*) InMsg;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageSetting.c] mmi_umms_set_setting_rsp result=%d*\n", set_rsp->result);

    MMI_ASSERT(g_umms_context->request_id == set_rsp->req_id);

    if (!g_umms_context->on_bootup)
    {
        g_umms_context->on_bootup = FALSE;
        if (IsScreenPresent(SCR_ID_UMMS_MESSAGE_SETTINGS))
        {
            if (set_rsp->result == MMA_RESULT_OK)
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_UNFINISHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
            }
        }
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        DeleteUptoScrID(SCR_ID_UMMS_MESSAGE_SETTINGS);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_fill_settings_for_mma
 * DESCRIPTION
 *  This function fills the various settings.
 * PARAMETERS
 *  msgSet      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_fill_settings_for_mma(wap_mma_set_setting_req_struct *msgSet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgSet->compose_sending_setting.creation_mode = mmi_umms_compose_settings_creation_mode();
    msgSet->compose_sending_setting.priority = mmi_umms_sending_settings_priority();
    msgSet->compose_sending_setting.validity_period = mmi_umms_sending_settings_validity_period();
    msgSet->compose_sending_setting.delivery_time = mmi_umms_sending_settings_delivery_time();
    msgSet->compose_sending_setting.delivery_report = mmi_umms_sending_settings_delivery_report();
    msgSet->compose_sending_setting.read_report = mmi_umms_sending_settings_read_report();
    msgSet->compose_sending_setting.max_mms_size = wap_custom_get_max_mms_msg_size();
    mmi_umms_compose_setting_image_resize_info(&msgSet->compose_sending_setting.image_resize);
#ifdef __MMI_MMS_SIGNATURE__
    mmi_umms_compose_settings_sign_info(&msgSet->compose_sending_setting.signature);
#endif 
    mmi_umms_compose_settings_default_slide_time(&msgSet->compose_sending_setting.sliding_time);
    msgSet->compose_sending_setting.layout = mmi_umms_compose_settings_layout();
#ifdef __DRM_SUPPORT__
    msgSet->compose_sending_setting.add_as_drm = mmi_umms_compose_settings_add_as_drm();
#else 
    msgSet->compose_sending_setting.add_as_drm = 0;
#endif 
    msgSet->compose_sending_setting.max_no_pages = mmi_umms_compose_settings_max_no_pages();
    msgSet->compose_sending_setting.best_page_duration = mmi_umms_compose_settings_best_page_duration();
    msgSet->compose_sending_setting.reply_charging = mmi_umms_sending_settings_reply_charging_status();
    msgSet->compose_sending_setting.request_type = mmi_umms_sending_settings_reply_charging_request_type();
    msgSet->compose_sending_setting.deadline_for_reply = mmi_umms_sending_settings_deadline_for_reply();
    msgSet->compose_sending_setting.hide_sender = mmi_umms_sending_settings_hide_sender();
#ifndef __MMI_MMS_OMA_CONF_273__
    msgSet->compose_sending_setting.size = mmi_umms_retrieval_settings_msg_size_filter();
#else
	msgSet->compose_sending_setting.size = 0;
#endif
	
#ifdef __CMCC_RETRIVAL_MODE_SETTING__
	msgSet->retrieval_setting.home_network = MMA_RETRIEVAL_MODE_IMMED;
#else
    msgSet->retrieval_setting.home_network = mmi_umms_retrieval_settings_home_network_retrieval_mode();
#endif
    msgSet->retrieval_setting.roaming = mmi_umms_retrieval_settings_roaming_retrieval_mode();
    msgSet->retrieval_setting.anonymous_filter = mmi_umms_retrieval_settings_anonymous_filter();
    msgSet->retrieval_setting.advertisement_filter = mmi_umms_retrieval_settings_advertisment_filter();
    msgSet->retrieval_setting.delivery_report = mmi_umms_retrieval_settings_delivery_report();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_select_from_file_manager(void)
{
	switch(g_signature_current_highlighted)
	{
		case E_COMPOSE_SIGNATURE_IMAGE:
			mmi_umms_compose_image_select_from_file_manager();
			break;
		case E_COMPOSE_SIGNATURE_VIDEO:
			mmi_umms_compose_video_select_from_file_manager();
			break;
		case E_COMPOSE_SIGNATURE_AUDIO:
			mmi_umms_compose_audio_select_from_file_manager();
			break;
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_profile_settings
 * DESCRIPTION
 *  This function is the entry  handler of profile settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_profile_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_prof_pre_entry_show_profile_list_menu(BRW_PROF_MMS_PROFILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_message_settings
 * DESCRIPTION
 *  This function is the entry  handler of message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_message_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;              /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item = 0;                   /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_MESSAGE_SETTINGS, NULL, mmi_umms_entry_message_settings, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_MESSAGE_SETTINGS);

    num_item = GetNumOfChild(MENU_ID_UMMS_MMS_SETTINGS);
    GetSequenceStringIds(MENU_ID_UMMS_MMS_SETTINGS, str_item_list);

    SetParentHandler(MENU_ID_UMMS_MMS_SETTINGS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UMMS_MMS_SETTINGS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_compose_settings
 * DESCRIPTION
 *  this is pre entry fn for compose settings. Init the inline items for compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_max_no_pages = g_umms_context->nvram_compose_settings.max_no_pages;
	PS8 ext_name;
	S8 mp3_ext[]={'m',0,'p',0,'3',0,0,0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(
        (S32) g_umms_context->nvram_compose_settings.default_slide_time,
        (UI_string_type) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer,
        10);
#ifdef __DRM_SUPPORT__
    g_umms_context->umms_inline_items.compose_items_list.add_drm = g_umms_context->nvram_compose_settings.add_drm;
#endif 
#ifdef __MMI_MMS_SIGNATURE__
	g_umms_context->umms_inline_items.compose_items_list.signature_flag = 0;
    g_umms_context->umms_inline_items.compose_items_list.auto_signature =
        g_umms_context->nvram_compose_settings.auto_signature;
	mmi_ucs2ncpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file ,\
				(S8*)g_umms_context->nvram_compose_settings.auto_signature_image_file, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);

	mmi_ucs2ncpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file ,\
				(S8*)g_umms_context->nvram_compose_settings.auto_signature_video_file, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);

	mmi_ucs2ncpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file ,\
			(S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);

        #if (!defined(__MMI_SHOW_FILE_EXT__))
		{
			PS8 ext_name = NULL;
			if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file))
			{
				ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
				if(ext_name != NULL)
				{
					mmi_ucs2cpy((S8*)g_file_ext[AUDIO_EXT], (S8*)ext_name);
				}
				PmgRemoveFileExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
			}

			if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file))
			{
				ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
				if(ext_name != NULL)
				{
					mmi_ucs2cpy((S8*)g_file_ext[VIDEO_EXT], (S8*)ext_name);
				}
				PmgRemoveFileExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
			}

			if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file))
			{
				ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
				if(ext_name != NULL)
				{
					mmi_ucs2cpy((S8*)g_file_ext[IMAGE_EXT], (S8*)ext_name);
				}
				PmgRemoveFileExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
			}
		}
		#elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
			if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file))
			{
					ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
					if(mmi_ucs2cmp(ext_name, mp3_ext) == 0)
					{
						PmgRemoveFileDAFExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
						g_umms_context->umms_inline_items.compose_items_list.signature_flag |= UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED; 
					}
			}
		#endif
#endif /* __MMI_MMS_SIGNATURE__ */ 
    g_umms_context->umms_inline_items.compose_items_list.best_page_duration =
        g_umms_context->nvram_compose_settings.best_page_duration;
    g_umms_context->umms_inline_items.compose_items_list.creation_mode =
        g_umms_context->nvram_compose_settings.creation_mode;
    g_umms_context->umms_inline_items.compose_items_list.image_resize_option =
        g_umms_context->nvram_compose_settings.image_resize_option;
    g_umms_context->umms_inline_items.compose_items_list.layout = g_umms_context->nvram_compose_settings.layout;

    gui_itoa(
        temp_max_no_pages,
        (UI_string_type) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer,
        10);

	mmi_umms_update_file_information();
	g_compose_signature_done = E_OFF;
    mmi_umms_entry_compose_settings();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_file_information
 * DESCRIPTION
 *  check file sanity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_file_information(void)
{
	FS_HANDLE fh = 0;
	BOOL need_update = FALSE;
	S16 error = 0;
	U8 temp_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
           return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
	
	if(mmi_ucs2strlen((S8*)g_umms_context->
		umms_inline_items.compose_items_list.auto_signature_image_file))
	{
		if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
			(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
		{
        #if (!defined(__MMI_SHOW_FILE_EXT__))
		{
			mmi_ucs2cpy((S8*)temp_file, (S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
			mmi_umms_make_file_name((S8*)temp_file, (S8*)g_file_ext[IMAGE_EXT]);
			fh = FS_Open((U16*)temp_file, FS_READ_ONLY);
		}
		#else
			fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, FS_READ_ONLY);

		#endif
			if(fh < 0)
			{
			    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] mmi_umms_update_file_information :Image file not opened");

				mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, \
						   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
				memset(g_umms_context->nvram_compose_settings.auto_signature_image_file, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
				need_update = TRUE;
				g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
			}
			else
			{
				g_umms_context->umms_inline_items.compose_items_list.signature_flag |= UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
			}
			FS_Close(fh);
		}
	}
	else
	{
		mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, \
				   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
		g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED;
	}

	if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file))
	{
		if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
			(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
		{
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			{
				mmi_ucs2cpy((S8*)temp_file, (S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
				mmi_umms_make_file_name((S8*)temp_file, (S8*)g_file_ext[VIDEO_EXT]);
				fh = FS_Open((U16*)temp_file, FS_READ_ONLY);
			}
			#else
				fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, FS_READ_ONLY);
			#endif

				if(fh < 0)
				{
				    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] mmi_umms_update_file_information :Video file not opened");

					mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, \
							   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
					memset(g_umms_context->nvram_compose_settings.auto_signature_video_file, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
					need_update = TRUE;
					g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;

				}
				else
				{
					g_umms_context->umms_inline_items.compose_items_list.signature_flag |= UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;
				}
				FS_Close(fh);
		}
	}
	else
	{
		mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, \
				   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
		g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED;

	}

	if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file))
	{
		if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
			(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
		{
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			{
				mmi_ucs2cpy((S8*)temp_file, (S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
				mmi_umms_make_file_name((S8*)temp_file, (S8*)g_file_ext[AUDIO_EXT]);
				fh = FS_Open((U16*)temp_file, FS_READ_ONLY);
			}
			#elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
					if(g_umms_context->umms_inline_items.compose_items_list.signature_flag
						& UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED)
					{
							S8 mp3_ext[]={'m',0,'p',0,'3',0,0,0};
							mmi_ucs2cpy((S8*)temp_file,(S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
							mmi_umms_make_file_name((S8*) temp_file, (S8*)mp3_ext);
							fh = FS_Open((U16*)temp_file, FS_READ_ONLY);
					}
					else
					{
						fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, FS_READ_ONLY);			
					}
			#else
				fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, FS_READ_ONLY);
			#endif
				if(fh < 0)
				{
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] mmi_umms_update_file_information :Audio file not opened");
					mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, \
							   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
					memset(g_umms_context->nvram_compose_settings.auto_signature_audio_file, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
					need_update = TRUE;
					g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;	
					g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED;
				}
				else
				{
					g_umms_context->umms_inline_items.compose_items_list.signature_flag |= UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
				}
				FS_Close(fh);
		}
	}
	else
	{
		mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, \
				   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
		g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED;
	}

	if(need_update)
	{
        WriteRecord(
            NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
            1,
            &g_umms_context->nvram_compose_settings,
            NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
            &error);
		g_umms_context->on_bootup = TRUE;
		mmi_umms_set_setting_to_mma_req();
	}

}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_compose_settings
 * DESCRIPTION
 *  This is entry fn for compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[COMPOSE_INLINE_TOTAL] = {0};
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_COMPOSE_SETTINGS, mmi_umms_exit_compose_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_COMPOSE_SETTINGS);

    InitializeCategory57Screen();

    mmi_umms_compose_fill_inline_struct();
	RegisterHighlightHandler(mmi_umms_compose_settings_highlight_hdlr);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_COMPOSE_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UMMS_COMPOSE_SETTINGS, &inputBufferSize);  /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, COMPOSE_INLINE_TOTAL, inputBuffer);        /* sets the data */
    }

    image_list[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION] = gIndexIconsImageList[count];
#ifdef __LAYOUT_SUPPORT__
    image_list[E_COMPOSE_LAYOUT_CAPTION] = gIndexIconsImageList[++count];
#endif
#ifdef __DRM_SUPPORT__
#ifdef __UMMS_DRM_SUPPORT__
    image_list[E_COMPOSE_ADD_DRM_CAPTION] = gIndexIconsImageList[++count];
#endif 
#endif 
    image_list[E_COMPOSE_CREATION_MODES_CAPTION] = gIndexIconsImageList[++count];

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    image_list[E_COMPOSE_IMAGE_RESIZE_CAPTION] = gIndexIconsImageList[++count];
#endif /* #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__ */
#ifdef __MAX_PAGE_SUPPORTED__
    image_list[E_COMPOSE_MAX_NO_PAGES_CAPTION] = gIndexIconsImageList[++count];
#endif
    image_list[E_COMPOSE_BEST_PAGE_DURATION_CAPTION] = gIndexIconsImageList[++count];
#ifdef __MMI_MMS_SIGNATURE__
    image_list[E_COMPOSE_AUTO_SIGNATURE_CAPTION] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_AUTO_SIGNATURE_CONTENT] = gIndexIconsImageList[++count];;
#endif /* __MMI_MMS_SIGNATURE__ */ 

    ShowCategory57Screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_COMPOSE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        COMPOSE_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_umms_confirm_save_compose_settings, GoBackHistory);

    SetKeyHandler(mmi_umms_read_back_auto_sign_content, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_confirm_save_compose_settings
 * DESCRIPTION
 *  It checks for default slide time value and auto sign (on/Off). If deafult slide time
 *  input 0 then error pop up. If auto sign is on buyt content is empty then also error pop up.
 *  If more than 20 slide then also error pop up.Otherwise  ask confirmation to save compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_confirm_save_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp = 0;
	U16 temp_slide_time_value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = gui_atoi((UI_string_type) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer);
    /* For empty value of slide time and no of slide field. */
#ifdef __MAX_PAGE_SUPPORTED__
    if (mmi_ucs2ncmp
        ((S8*) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer, "\0",
         1 * ENCODING_LENGTH) == 0)
    {
        DisplayPopup((U8*) GetString(STR_ID_UMMS_MAX_PAGES_LIMIT), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		return;
    }

	if (temp > UMMS_MAX_POSSIBLE_SLIDES || temp < 1)
    {
        DisplayPopup((U8*) GetString(STR_ID_UMMS_MAX_PAGES_LIMIT), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		return;
    }
#endif		
    temp_slide_time_value = gui_atoi((UI_string_type) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer);

//	if (mmi_ucs2ncmp
//             ((S8*) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer, "\0",
//              1 * ENCODING_LENGTH) == 0)
	if(temp_slide_time_value == 0)
    {
        DisplayPopup((U8*) GetString(STR_ID_UMMS_SLIDE_TIME_ZERO_ERROR), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		return;
    }

#ifdef __MMI_MMS_SIGNATURE__
     if ((g_umms_context->umms_inline_items.compose_items_list.auto_signature == E_ON)
             &&
             (mmi_ucs2ncmp
              ((S8*) g_umms_context->nvram_compose_settings.auto_signature_content, "\0",
               UMMS_MAX_AUTO_SIGN_LENGTH * ENCODING_LENGTH) == 0)
			 &&
			(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
				(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
			   &&
			(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
				(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
			   &&
			(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
				(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) == 0)
			)
    {
        DisplayPopup((U8*) GetString(STR_ID_UMMS_AUTO_SIGN_ERROR), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		return;
    }

    else
#endif /* __MMI_MMS_SIGNATURE__ */ 
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_umms_save_compose_settings, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_umms_exit_confirm_screen, KEY_EVENT_UP);

        SetKeyHandler(mmi_umms_read_back_auto_sign_content, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_confirm_screen
 * DESCRIPTION
 *  exit from the confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ///read back the auto sign content.Required because we are using the original auto sign buffer for input
    ///the auto sign content
    ReadRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_umms_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    GoBacknHistory(UMMS_GOBACK_ONE_LEVEL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for compose settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_umms_context->umms_inline_lists == NULL)
    {
        g_umms_context->umms_inline_lists =
            (umms_common_inline_lists_struct*) umms_malloc(sizeof(umms_common_inline_lists_struct));
        MMI_ASSERT(g_umms_context->umms_inline_lists != NULL);

        if (g_umms_context->umms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }
#ifdef __LAYOUT_SUPPORT__
    g_umms_context->umms_inline_items.compose_items_list.layout_list[E_MMS_LAYOUT_POTRAIT] = GetString(STR_ID_UMMS_SETTINGS_POTRAIT);
    g_umms_context->umms_inline_items.compose_items_list.layout_list[E_MMS_LAYOUT_LANDSCAPE] = GetString(STR_ID_UMMS_SETTINGS_LANDSCAPE);
#endif
    g_umms_context->umms_inline_lists->on_off_list[E_OFF] = GetString(STR_ID_UMMS_SETTINGS_OFF);
    g_umms_context->umms_inline_lists->on_off_list[E_ON] = GetString(STR_ID_UMMS_SETTINGS_ON);

    g_umms_context->umms_inline_items.compose_items_list.creation_modes_list[E_CREAT_MODE_RESTRICTED] = GetString(STR_ID_UMMS_SETTINGS_RESTRICTED);
#ifdef __MMS_CREATION_MODE_SUPPORTED__
    g_umms_context->umms_inline_items.compose_items_list.creation_modes_list[E_CREAT_MODE_WARNING] = GetString(STR_ID_UMMS_SETTINGS_WARNING);
#endif
    g_umms_context->umms_inline_items.compose_items_list.creation_modes_list[E_CREAT_MODE_FREE] = GetString(STR_ID_UMMS_SETTINGS_FREE);

    g_umms_context->umms_inline_items.compose_items_list.image_resize_list[E_IMAGE_RESIZE_OFF] = GetString(STR_ID_UMMS_SETTINGS_OFF);
    g_umms_context->umms_inline_items.compose_items_list.image_resize_list[E_IMAGE_RESIZE_160x120] = GetString(STR_ID_UMMS_SETTINGS_160_X_120);
    g_umms_context->umms_inline_items.compose_items_list.image_resize_list[E_IMAGE_RESIZE_320x240] = GetString(STR_ID_UMMS_SETTINGS_320_X_240);
    g_umms_context->umms_inline_items.compose_items_list.image_resize_list[E_IMAGE_RESIZE_640x480] = GetString(STR_ID_UMMS_SETTINGS_640_X_480);

    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_DEFAULT_SLIDE_TIMING));
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME],
        (U8*) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer,
        (UMMS_MAX_DEFAULT_SLIDE_TIME_INPUT + 1),
        INPUT_TYPE_NUMERIC);
#ifdef __LAYOUT_SUPPORT__
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_LAYOUT_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_COMPOSE_LAYOUT_CAPTION], (U8*) GetString(STR_ID_UMMS_SETTINGS_LAYOUT));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_LAYOUT],
        2,
        (U8 **) g_umms_context->umms_inline_items.compose_items_list.layout_list,
        &g_umms_context->umms_inline_items.compose_items_list.layout);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_LAYOUT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif
#ifdef __DRM_SUPPORT__
#ifdef __UMMS_DRM_SUPPORT__
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_ADD_DRM_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_COMPOSE_ADD_DRM_CAPTION], (U8*) GetString(STR_ID_UMMS_SETTINGS_ADD_DRM));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_ADD_DRM],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.compose_items_list.add_drm);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_ADD_DRM], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif
#endif /* __DRM_SUPPORT__ */ 
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_CREATION_MODES));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES],
        CREATION_MODES_TOTAL,
        (U8 **) g_umms_context->umms_inline_items.compose_items_list.creation_modes_list,
        &g_umms_context->umms_inline_items.compose_items_list.creation_mode);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_CREATION_MODES], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__

    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_IMAGE_RESIZE));

    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_IMAGE_RESIZING], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZING],
        4,
        (U8 **) g_umms_context->umms_inline_items.compose_items_list.image_resize_list,
        &g_umms_context->umms_inline_items.compose_items_list.image_resize_option);

#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ /* ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__ */
#ifdef __MAX_PAGE_SUPPORTED__
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_MAX_NO_PAGES_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_MAX_NO_PAGES_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_MAX_NUM_PAGES));
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_MAX_NO_PAGES], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_COMPOSE_MAX_NO_PAGES],
        (U8*) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer,
        (UMMS_MAX_NO_PAGES_INPUT + 1),
        INPUT_TYPE_NUMERIC);
#endif
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_BEST_PAGE_DURATION));

    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.compose_items_list.best_page_duration);
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

#ifdef __MMI_MMS_SIGNATURE__
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_AUTO_SIGNATURE));

    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.compose_items_list.auto_signature);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE));

  //  SetInlineItemCaption(
 //       &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT],
  //      (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE));

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
#endif
#endif /* __MMI_MMS_SIGNATURE__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == E_COMPOSE_AUTO_SIGNATURE_CONTENT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_umms_entry_compose_signature_settings, KEY_EVENT_UP);
    }
    if (g_compose_signature_done == E_ON)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_umms_confirm_save_compose_settings, KEY_EVENT_UP);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_compose_settings
 * DESCRIPTION
 *  Exit fn for compose settings screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_UMMS_COMPOSE_SETTINGS;
    history_buff.entryFuncPtr = mmi_umms_entry_compose_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, inputBufferSize);         /* added for inline edit history */

    if (g_umms_context->umms_inline_lists != NULL)
    {
        umms_free(g_umms_context->umms_inline_lists);
        g_umms_context->umms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_read_back_auto_sign_content
 * DESCRIPTION
 *  Read the Compose setting from NVRAm for the auto sign content
 *  Read back is required because we are using the original auto sign buffer for input
 *  the auto sign content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_read_back_auto_sign_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_umms_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_inline_custom_func
 * DESCRIPTION
 *  custom fn for Auto sign Full screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_inline_custom_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));

    SetKeyHandler(mmi_umms_read_back_auto_sign_content, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_compose_signature_settings
 * DESCRIPTION
 *  Entry function for signature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_umms_entry_compose_signature_settings(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[COMPOSE_SIGNATURE_INLINE_TOTAL] = {0};


#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS, mmi_umms_exit_compose_signature_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);

    InitializeCategory57Screen();
	RegisterHighlightHandler(mmi_umms_compose_settings_signature_highlight_hdlr);
//	mmi_umms_check_signature_files();
	mmi_umms_update_file_information();
    mmi_umms_compose_signature_fill_inline_struct(); 

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, COMPOSE_SIGNATURE_INLINE_TOTAL, inputBuffer);       /* sets the data */
    }


    if ((GetInlineDoneFlag(guiBuffer) == 0) && (g_compose_signature_done == E_ON))
    {
        SetInlineDoneFlag(guiBuffer);
    }


   	image_list[E_COMPOSE_SIGNATURE_TEXT_CAPTION] = gIndexIconsImageList[0];

    image_list[E_COMPOSE_SIGNATURE_IMAGE_CAPTION] = gIndexIconsImageList[1];
    image_list[E_COMPOSE_SIGNATURE_VIDEO_CAPTION] = gIndexIconsImageList[2];
 
    image_list[E_COMPOSE_SIGNATURE_AUDIO_CAPTION] = gIndexIconsImageList[3];

    ShowCategory57Screen(
        STR_ID_UMMS_SETTINGS_SIGNATURE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        COMPOSE_SIGNATURE_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_umms_signature_done_handler, GoBackHistory);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_signature_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline data for signature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_signature_fill_inline_struct(void)
{

	/* text */
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_TEXT_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE_TEXT));


	SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_SIGNATURE_TEXT], KEY_LSK, KEY_EVENT_UP);

    SetInlineItemFullScreenEdit(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_TEXT],
        STR_ID_UMMS_SETTINGS_EDIT_CONTENT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        (PU8) g_umms_context->nvram_compose_settings.auto_signature_content,
        UMMS_MAX_AUTO_SIGN_LENGTH + 1,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);

    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_TEXT],
        mmi_umms_compose_inline_custom_func);
	/* Image */
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_IMAGE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE_IMAGE));
 
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_SIGNATURE_IMAGE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemDisplayOnly(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_IMAGE],
        (U8*) /*g_umms_context->nvram_compose_settings.auto_signature_image_file*/
		g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
	/* Video */
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_VIDEO_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE_VIDEO));
 
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_SIGNATURE_VIDEO], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemDisplayOnly(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_VIDEO],
        (U8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);

	/* Audio*/
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_AUDIO_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE_AUDIO));
 
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_SIGNATURE_AUDIO], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemDisplayOnly(
        &wgui_inline_items[E_COMPOSE_SIGNATURE_AUDIO],
        (U8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_signature_files
 * DESCRIPTION
 *  check file sanity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_check_signature_files(void)
{
	FS_HANDLE fh = 0;

	if(mmi_ucs2strlen((S8*)g_umms_context->
		umms_inline_items.compose_items_list.auto_signature_image_file))
	{
		if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
			(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
		{

			fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, FS_READ_ONLY);
			if(fh < 0)
			{
				mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, \
						   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
			
			}
			FS_Close(fh);
		}
	}
	else
	{
		mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, \
				   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
	}

	if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file))
	{
		if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
			(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
		{
				fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, FS_READ_ONLY);
				if(fh < 0)
				{
					mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, \
							   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));

				}
				FS_Close(fh);
		}
	}
	else
	{
		mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, \
				   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
	}

	if(mmi_ucs2strlen((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file))
	{
		if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
			(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
		{
				fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, FS_READ_ONLY);
				if(fh < 0)
				{
					mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, \
							   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
	
				}
				FS_Close(fh);
		}
	}
	else
	{
		mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, \
				   (S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA));
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_compose_signature_settings
 * DESCRIPTION
 *  Exit fn for compose signature setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_compose_signature_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS;
    history_buff.entryFuncPtr = mmi_umms_entry_compose_signature_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, inputBufferSize);         /* added for inline edit history */

    if (g_umms_context->umms_inline_lists != NULL)
    {
        umms_free(g_umms_context->umms_inline_lists);
        g_umms_context->umms_inline_lists = NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_settings_signature_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for signature items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_settings_signature_highlight_hdlr(S32 index)
{

	switch(index)
	{
		case E_COMPOSE_SIGNATURE_TEXT:
			ChangeLeftSoftkey(STR_GLOBAL_EDIT, NULL);
			break;
		case E_COMPOSE_SIGNATURE_IMAGE:
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, NULL);
			g_signature_current_highlighted = E_COMPOSE_SIGNATURE_IMAGE;
			break;
		case E_COMPOSE_SIGNATURE_AUDIO:
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, NULL);
			g_signature_current_highlighted = E_COMPOSE_SIGNATURE_AUDIO;
			break;
		case E_COMPOSE_SIGNATURE_VIDEO:
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, NULL);
			g_signature_current_highlighted = E_COMPOSE_SIGNATURE_VIDEO;
			break;
	}

			
	SetLeftSoftkeyFunction(mmi_umms_compose_signature_pre_option_menu, KEY_EVENT_UP);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_signature_pre_option_menu
 * DESCRIPTION
 *  Pre entry function for options		
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_signature_pre_option_menu(void)
{

	BOOL file_exist = FALSE;

	switch(g_signature_current_highlighted)
	{
		case E_COMPOSE_SIGNATURE_IMAGE:
			if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
				(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
			{
				file_exist = TRUE;
			}
			break;
		case E_COMPOSE_SIGNATURE_AUDIO:
			if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
				(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
			{
				file_exist = TRUE;
			}

			break;
		case E_COMPOSE_SIGNATURE_VIDEO:
			if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
				(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
			{
				file_exist = TRUE;
			}

			break;
	}

	mmi_umms_compose_entry_signature_option(file_exist);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_entry_signature_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_entry_signature_option(BOOL file_selected)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U16 nNumofItem;
 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_COMPOSE_IMAGE_OPTION, mmi_umms_compose_exit_image_option, mmi_umms_compose_signature_pre_option_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_COMPOSE_IMAGE_OPTION);
   

    /* Hide menu item play and delete when file not selected. */
    /* Regiser highlight handler again. */
    mmi_frm_hide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_VIEW);

    /* File not selected */
    if (file_selected == FALSE)
    {
		//mmi_frm_hide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_VIEW);
		mmi_frm_hide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_DELETE);

    }
	else
	{
	//	mmi_frm_hide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_VIEW);
		if(g_signature_current_highlighted == E_COMPOSE_SIGNATURE_IMAGE)
		{
		//	mmi_frm_unhide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_VIEW);
		}
		mmi_frm_unhide_menu_item(MENU_ID_UMMS_SIGNATURE_OPTION_DELETE);

	}


    nNumofItem = GetNumOfChild_Ext(MENU_ID_UMMS_SIGNATURE_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_UMMS_SIGNATURE_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_UMMS_SIGNATURE_OPTION);

	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_UMMS_SETTINGS_SIGNATURE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);


}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_exit_image_option
 * DESCRIPTION
 *  screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_exit_image_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_compose_reference_delete
 * DESCRIPTION
 *  Pre entry function to delete reference from signature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_compose_reference_delete(void)
{
	g_compose_signature_done = E_ON;
//	mmi_ucs2cpy(g_umms_context->nvram_compose_settings.auto_signature_image_file, g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);

	switch(g_signature_current_highlighted)
	{
		case E_COMPOSE_SIGNATURE_IMAGE:
			memset(g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, 0, 
			(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			memset(g_file_ext[IMAGE_EXT], 0, UMMS_SIGNATURE_EXT_LENGTH);
			#endif
			break;
		case E_COMPOSE_SIGNATURE_VIDEO:
			memset(g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, 0, 
			(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			memset(g_file_ext[VIDEO_EXT], 0, UMMS_SIGNATURE_EXT_LENGTH);
			#endif
			break;
		case E_COMPOSE_SIGNATURE_AUDIO:
			memset(g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, 0, 
			(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			memset(g_file_ext[AUDIO_EXT], 0, UMMS_SIGNATURE_EXT_LENGTH);
			#endif
			break;
	}

    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);
	DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_image_select_from_file_manager
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_image_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

		if((g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
			UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
		{
			DisplayPopup((U8*) GetString(STR_ID_UMMS_VIDEO_IMAGE_NOT_ALLOWED), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
			DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
			return;
		}


    FMGR_FILTER_INIT(&filter);
	mmi_umms_set_signature_file_mgr_filter(&filter, MMA_OPEN_IMAGE_TYPES);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(
        APP_MESSAGES,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        (PsExtFuncPtr) mmi_umms_compose_image_select_path_from_file_manager);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_video_select_from_file_manager
 * DESCRIPTION
 *  select video from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_video_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (isInCall()) /* Can not preview video during call. */
    {
        //fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
        DisplayPopup(
            (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE_NOT_ALLOWED),
            IMG_GLOBAL_WARNING,
            FALSE,
            UMMS_POPUP_TIME,
            WARNING_TONE);
        DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return;
    }

	if((g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
		UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED)
		&&
		(g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
				UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED)
		)
	{
		DisplayPopup((U8*) GetString(STR_ID_UMMS_REMOVE_AUDIO_IMAGE), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
		return;
	}

	if((g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
		UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED))
	{
		DisplayPopup((U8*) GetString(STR_ID_UMMS_AUDIO_VIDEO_NOT_ALLOWED), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
		return;
	}

	if((g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
		UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED))
	{
		DisplayPopup((U8*) GetString(STR_ID_UMMS_VIDEO_IMAGE_NOT_ALLOWED), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
		return;
	}

    FMGR_FILTER_INIT(&filter);
	mmi_umms_set_signature_file_mgr_filter(&filter, MMA_OPEN_VIDEO_TYPES);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(
        APP_MESSAGES,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        (PsExtFuncPtr) mmi_umms_compose_video_select_path_from_file_manager);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_audio_select_from_file_manager
 * DESCRIPTION
 *  select audio from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_audio_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (isInCall()) /* Can not preview video during call. */
    {
        //fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
        DisplayPopup(
            (U8*) GetString(STR_ID_UMMS_SETTINGS_SIGNATURE_NOT_ALLOWED),
            IMG_GLOBAL_WARNING,
            FALSE,
            UMMS_POPUP_TIME,
            WARNING_TONE);
        DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return;
    }

	if((g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
		UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
	{
		DisplayPopup((U8*) GetString(STR_ID_UMMS_AUDIO_VIDEO_NOT_ALLOWED), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
		return;
	}

    FMGR_FILTER_INIT(&filter);
	mmi_umms_set_signature_file_mgr_filter(&filter, MMA_OPEN_AUDIO_TYPES);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(
        APP_MESSAGES,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        (PsExtFuncPtr) mmi_umms_compose_audio_select_path_from_file_manager);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_image_select_path_from_file_mamager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_image_select_path_from_file_manager(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] Select image path  :Image file path null");
		g_compose_signature_done = E_OFF;
        GoBackToHistory(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return;
    }
	g_compose_signature_done = E_ON;
    /* Check image content. */
    if (mmi_umms_composer_check_data_space((S8*) path,UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED))
    {
		g_compose_signature_done = E_ON;
        mmi_ucs2cpy((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file, (S8*) path);
        #if (!defined(__MMI_SHOW_FILE_EXT__))
		{
			PS8 ext_name;
			ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
			mmi_ucs2cpy((S8*)g_file_ext[IMAGE_EXT],(S8*)ext_name);
            PmgRemoveFileExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
		}
		#endif
		
		DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
	//	mmi_umms_image_preview();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_composer_check_data_space
 * DESCRIPTION
 *  Checks for the msg size
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  object_type     [IN]        object type (ex. image,video)
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_umms_composer_check_data_space(S8* path, U8 object_type)
{
	U32 msg_size = (UMMS_MAX_AUTO_SIGN_LENGTH + 1) *ENCODING_LENGTH;  /* Reserving space for text*/
	BOOL result = TRUE;
	U32 object_size = applib_get_file_size(path);

	if(mmi_ucs2strlen((S8*)path) > MMA_MAX_INTERNAL_FILENAME_LENGTH)
	{
        DisplayPopup((PU8) GetString(STR_ID_UMMS_SIGNATURE_PATH_TOO_LONG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return FALSE;
	}

	if(object_size <= 0)
	{
      DisplayPopup((PU8) GetString(STR_ID_UMMS_SIGNATURE_INVALID_SIZE), IMG_GLOBAL_ERROR, FALSE, UMMS_POPUP_TIME, ERROR_TONE);
	  DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
	  return FALSE; 
	}

    if (object_size > wap_custom_get_max_mms_msg_size())
    {
        DisplayPopup((PU8) GetString(STR_ID_UMMS_OPTIONS_MSG_SIZE_EXCEED), IMG_GLOBAL_UNFINISHED, FALSE, UMMS_POPUP_TIME, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return FALSE;
    }

	if(mmi_umms_check_media_validity(path, object_type) == FALSE)
	{
		return FALSE;
	}
	switch(object_type)
	{
		case UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED:
				if(g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
					UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED)
				{
					msg_size += applib_get_file_size(g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
				}
				if((object_size + msg_size) > 	wap_custom_get_max_mms_msg_size())
				{
					result = FALSE;
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] \
						Select image path  :Audio : object_size + msg_size > max_mms_size");

				}
				break;
		case UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED:
				if(g_umms_context->umms_inline_items.compose_items_list.signature_flag & 
					UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED)
				{
					msg_size += applib_get_file_size(g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
				}
				if((object_size + msg_size) > 	wap_custom_get_max_mms_msg_size())
				{
					result = FALSE;
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] \
						Select Audio path  :Image : object_size + msg_size > max_mms_size");

				}
				break;
		case UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED:
				if((object_size + msg_size) > 	wap_custom_get_max_mms_msg_size())
				{
					result = FALSE;
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] \
						Select Video path  :Text : object_size + msg_size > max_mms_size");

				}
				break;
	}

	if(result == FALSE)
	{
        DisplayPopup((PU8) GetString(STR_ID_UMMS_OPTIONS_MSG_SIZE_EXCEED), IMG_GLOBAL_ERROR, FALSE, UMMS_POPUP_TIME, ERROR_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
	}
	return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_media_validity
 * DESCRIPTION
 *  Checks for the msg size
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  object_type     [IN]        object type (ex. image,video)
 * RETURNS
 *  BOOL
 *****************************************************************************/
/* Rajbir Changes */
BOOL mmi_umms_check_media_validity(S8* filepath, U8 object_type)
{
	BOOL result = TRUE;
#ifdef	 __DRM_SUPPORT__
	mma_drm_type_enum drm_type = MMA_DRM_NONE;
	drm_type = wap_mma_umms_check_signature_drm_type((U16*)filepath);
	if(drm_type != MMA_DRM_NONE)
	{
		if(drm_type == MMA_DRM_FL_CD)
		{
			DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_ERROR, FALSE, UMMS_POPUP_TIME, ERROR_TONE);
			DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
#endif
	switch(object_type)
	{
		case UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED:
			{
				GDI_RESULT image_result;
				S32 img_widthv = 0, img_heightv = 0;
				image_result = gdi_image_get_dimension_file((S8*) filepath, &img_widthv, &img_heightv);
				if (image_result != GDI_SUCCEED || (img_widthv * img_heightv) == 0)
				{
					result = KAL_FALSE;
					
				}
			}
			break;
		case UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED:
			{
				mdi_result audio_result = 0;
			    U32 audio_du;
				audio_result = mdi_audio_get_duration((S8*) filepath, &audio_du);
				if (audio_result != GDI_SUCCEED)
				{
					result = KAL_FALSE;
				}
			}
			break;
		case UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED:
			{
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)  

				MDI_RESULT result_video = 0;
				mdi_video_info_struct video_clip;
				result_video = mdi_video_ply_open_clip_file((S8*) filepath, &video_clip);
				if (result_video != MDI_RES_VDOPLY_SUCCEED)
				{
					result = KAL_FALSE;
				}
				else
				{
					mdi_video_ply_close_clip_file();
				}

#endif
			}
			break;
		default:
			break;

	}

	if(result == FALSE)
	{
		 DisplayPopup((PU8) GetString(STR_ID_UMMS_SIGNATURE_FILE_CORRUPTED), IMG_GLOBAL_ERROR, FALSE, UMMS_POPUP_TIME, ERROR_TONE);
		 DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
	}
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_video_select_path_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_video_select_path_from_file_manager(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] Select Video path  :Video file path null");
		g_compose_signature_done = E_OFF;
        GoBackToHistory(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return;
    }

    /* Check File Path Length */
    if (mmi_umms_composer_check_data_space((S8*) path,UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED))
    {
		g_compose_signature_done = E_ON;
        mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file, (S8*) path);
        #if (!defined(__MMI_SHOW_FILE_EXT__))
		{
			PS8 ext_name;
			ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
			mmi_ucs2cpy((S8*)g_file_ext[VIDEO_EXT],(S8*)ext_name);
            PmgRemoveFileExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
		}
		#endif
		DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
		//   mmi_phb_video_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_compose_audio_select_path_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_compose_audio_select_path_from_file_manager(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] Select audio path  :audio file path null");
		g_compose_signature_done = E_OFF;
        GoBackToHistory(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
        return;
    }

    /* Check File Path Length */
    if (mmi_umms_composer_check_data_space((S8*) path,UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED))
    {
		g_compose_signature_done = E_ON;
        mmi_ucs2cpy((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file, (S8*) path);
        #if (!defined(__MMI_SHOW_FILE_EXT__))
		{
			PS8 ext_name;
			ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
			mmi_ucs2cpy((S8*)g_file_ext[AUDIO_EXT],(S8*)ext_name);
            PmgRemoveFileExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
		}		
		#elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
		{
            PS8 ext_name;
			S8 mp3_ext[]={'m',0,'p',0,'3',0,0,0};
			ext_name = mmi_fmgr_extract_ext_file_name((PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
			if(mmi_ucs2cmp(ext_name, mp3_ext) == 0)
			{
				PmgRemoveFileDAFExt((S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
				g_umms_context->umms_inline_items.compose_items_list.signature_flag |= UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED; 
			}
			else
			{
				g_umms_context->umms_inline_items.compose_items_list.signature_flag &= ~UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED;
			}
		}
		#endif
		DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
		DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
		//   mmi_phb_video_preview();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_signature_done_handler
 * DESCRIPTION
 *  Done handler for signature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_signature_done_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

        g_compose_signature_done = E_ON;
        GoBackHistory();


}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_sending_settings
 * DESCRIPTION
 *  pre entry fn for sending settings. Init the value of inline items for the screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(
        (S32) g_umms_context->nvram_sending_settings.deadline_for_reply,
        (UI_string_type) g_umms_context->umms_inline_items.sending_items_list.deadline_for_reply_buffer,
        10);
    g_umms_context->umms_inline_items.sending_items_list.delivery_report =
        (S32) g_umms_context->nvram_sending_settings.delivery_report;
    g_umms_context->umms_inline_items.sending_items_list.delivery_time =
        (S32) g_umms_context->nvram_sending_settings.delivery_time;
    g_umms_context->umms_inline_items.sending_items_list.hide_sender =
        (S32) g_umms_context->nvram_sending_settings.hide_sender;
    g_umms_context->umms_inline_items.sending_items_list.priority =
        (S32) g_umms_context->nvram_sending_settings.priority;
    g_umms_context->umms_inline_items.sending_items_list.read_report =
        (S32) g_umms_context->nvram_sending_settings.read_report;
    g_umms_context->umms_inline_items.sending_items_list.reply_charging =
        (S32) g_umms_context->nvram_sending_settings.reply_charging;
    g_umms_context->umms_inline_items.sending_items_list.request_type =
        (S32) g_umms_context->nvram_sending_settings.request_type;

    g_umms_context->umms_inline_items.sending_items_list.send_and_save =
        (S32) g_umms_context->nvram_sending_settings.send_and_save;

    g_umms_context->umms_inline_items.sending_items_list.validity_period =
        (S32) g_umms_context->nvram_sending_settings.validity_period;
    gui_itoa(
        (S32) g_umms_context->nvram_sending_settings.size,
        (UI_string_type) g_umms_context->umms_inline_items.sending_items_list.reply_msg_size_buffer,
        10);

    mmi_umms_entry_sending_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_sending_settings
 * DESCRIPTION
 *  Entry fn for sendin settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[SENDING_INLINE_TOTAL] = {0};
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_SENDING_SETTINGS, mmi_umms_exit_sending_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_SENDING_SETTINGS);

    InitializeCategory57Screen();

    mmi_umms_sending_fill_inline_struct();
    RegisterHighlightHandler(mmi_umms_sending_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_SENDING_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UMMS_SENDING_SETTINGS, &inputBufferSize);  /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, SENDING_INLINE_TOTAL, inputBuffer);        /* sets the data */
    }
    if (global_mms_version > 1)
    {
        image_list[E_SENDING_VALIDITY_PERIOD_CAPTION] = gIndexIconsImageList[count];
        image_list[E_SENDING_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_READ_REPORT_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_PRIORITY_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_DELIVERY_TIME_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_REPLY_CHARGING_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_HIDE_SENDER_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_SEND_AND_SAVE_CAPTION] = gIndexIconsImageList[++count];
    }
    else
    {
        image_list[E_SENDING_VALIDITY_PERIOD_CAPTION] = gIndexIconsImageList[count];
        image_list[E_SENDING_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_READ_REPORT_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_PRIORITY_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_DELIVERY_TIME_CAPTION] = gIndexIconsImageList[++count];
        /* image_list[E_SENDING_REPLY_CHARGING_CAPTION] = gIndexIconsImageList[5]; */
        image_list[E_SENDING_HIDE_SENDER_CAPTION] = gIndexIconsImageList[++count];
        image_list[E_SENDING_SEND_AND_SAVE_CAPTION] = gIndexIconsImageList[++count];
    }

    if (global_mms_version > 1)
    {
        ShowCategory57Screen(
            STR_ID_UMMS_MESSAGE_SETTINGS_SENDING,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SENDING_INLINE_TOTAL,
            image_list,
            wgui_inline_items,
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory57Screen(
            STR_ID_UMMS_MESSAGE_SETTINGS_SENDING,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SENDING_INLINE_TOTAL - 2,
            image_list,
            wgui_inline_items,
            0,
            guiBuffer);
    }

    SetCategory57RightSoftkeyFunctions(mmi_umms_confirm_save_sending_settings, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_sending_settings
 * DESCRIPTION
 *  Exit fn for the send setting screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_UMMS_SENDING_SETTINGS;
    history_buff.entryFuncPtr = mmi_umms_entry_sending_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, inputBufferSize);         /* added for inline edit history */

    if (g_umms_context->umms_inline_lists != NULL)
    {
        umms_free(g_umms_context->umms_inline_lists);
        g_umms_context->umms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_fill_inline_struct
 * DESCRIPTION
 *  Fill the inline struct for send settings screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_sending_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_umms_context->umms_inline_lists == NULL)
    {
        g_umms_context->umms_inline_lists =
            (umms_common_inline_lists_struct*) umms_malloc(sizeof(umms_common_inline_lists_struct));
        MMI_ASSERT(g_umms_context->umms_inline_lists != NULL);

        if (g_umms_context->umms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }

    g_umms_context->umms_inline_items.sending_items_list.validity_period_list[E_VALIDITY_PERIOD_MAX] = GetString(STR_ID_UMMS_MAXIMUM);
    g_umms_context->umms_inline_items.sending_items_list.validity_period_list[E_VALIDITY_PERIOD_1HR] = GetString(STR_ID_UMMS_SETTINGS_1_HR);
	    g_umms_context->umms_inline_items.sending_items_list.validity_period_list[E_VALIDITY_PERIOD_6HRS] = GetString(STR_ID_UMMS_SETTINGS_6_HRS);
    g_umms_context->umms_inline_items.sending_items_list.validity_period_list[E_VALIDITY_PERIOD_12HRS] = GetString(STR_ID_UMMS_SETTINGS_12_HRS);
    g_umms_context->umms_inline_items.sending_items_list.validity_period_list[E_VALIDITY_PERIOD_1DAY] = GetString(STR_ID_UMMS_SETTINGS_1_DAY);
    g_umms_context->umms_inline_items.sending_items_list.validity_period_list[E_VALIDITY_PERIOD_1WEEK] = GetString(STR_ID_UMMS_SETTINGS_1_WEEK);

    g_umms_context->umms_inline_lists->on_off_list[E_OFF] = GetString(STR_ID_UMMS_SETTINGS_OFF);
    g_umms_context->umms_inline_lists->on_off_list[E_ON] = GetString(STR_ID_UMMS_SETTINGS_ON);

    g_umms_context->umms_inline_items.sending_items_list.priority_list[E_PRIORITY_LOW] = GetString(STR_ID_UMMS_SETTINGS_LOW);
    g_umms_context->umms_inline_items.sending_items_list.priority_list[E_PRIORITY_NORMAL] = GetString(STR_GLOBAL_NORMAL);
    g_umms_context->umms_inline_items.sending_items_list.priority_list[E_PRIORITY_HIGH] = GetString(STR_ID_UMMS_SETTINGS_HIGH);

    g_umms_context->umms_inline_items.sending_items_list.delivery_time_list[E_IMMEDIATE] = GetString(STR_ID_UMMS_SETTINGS_IMMEDIATE);
    g_umms_context->umms_inline_items.sending_items_list.delivery_time_list[E_1_HR] = GetString(STR_ID_UMMS_SETTINGS_DELV_1_HR);
    g_umms_context->umms_inline_items.sending_items_list.delivery_time_list[E_12_HRS] = GetString(STR_ID_UMMS_SETTINGS_DELV_12_HRS);
    g_umms_context->umms_inline_items.sending_items_list.delivery_time_list[E_24_HRS] = GetString(STR_ID_UMMS_SETTINGS_DELV_24_HRS);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_VALIDITY_PERIOD));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD],
        VALIDITY_PERIOD_TOTAL,
        (U8 **) g_umms_context->umms_inline_items.sending_items_list.validity_period_list,
        &g_umms_context->umms_inline_items.sending_items_list.validity_period);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_VALIDITY_PERIOD], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT_CAPTION],
        (U8*) GetString(STR_ID_UMMS_DELIVERY_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.sending_items_list.delivery_report);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_DELIVERY_REPORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_READ_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_READ_REPORT_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_READ_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_READ_REPORT],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.sending_items_list.read_report);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_READ_REPORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(&wgui_inline_items[E_SENDING_PRIORITY_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_SENDING_PRIORITY_CAPTION], (U8*) GetString(STR_ID_UMMS_SETTINGS_PRIORITY));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_PRIORITY],
        3,
        (U8 **) g_umms_context->umms_inline_items.sending_items_list.priority_list,
        &g_umms_context->umms_inline_items.sending_items_list.priority);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_PRIORITY], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_DELIVERY_TIME));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME],
        DELIEVERY_TOTAL,
        (U8 **) g_umms_context->umms_inline_items.sending_items_list.delivery_time_list,
        &g_umms_context->umms_inline_items.sending_items_list.delivery_time);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_DELIVERY_TIME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_HIDE_SENDER_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_HIDE_SENDER_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_HIDE_SENDER));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_HIDE_SENDER],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.sending_items_list.hide_sender);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_HIDE_SENDER], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    /* send and save start */
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_SEND_AND_SAVE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_SEND_AND_SAVE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_SEND_AND_SAVE));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_SEND_AND_SAVE],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.sending_items_list.send_and_save);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_SEND_AND_SAVE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    /* send and save ends */

    if (global_mms_version > 1)
    {
        SetInlineItemActivation(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING_CAPTION],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING_CAPTION],
            (U8*) GetString(STR_ID_UMMS_SETTINGS_REPLY_CHARGING));
        SetInlineItemSelect(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING],
            2,
            (U8 **) g_umms_context->umms_inline_lists->on_off_list,
            &g_umms_context->umms_inline_items.sending_items_list.reply_charging);
        SetInlineItemActivation(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        RegisterInlineSelectHighlightHandler(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING],
            mmi_umms_reply_charging_highlight_hdlr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reply_charging_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler fro reply charging inline item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reply_charging_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_reply_charging_done == 1)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_umms_confirm_save_sending_settings, KEY_EVENT_UP);
    }
    if (index == E_ON)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_umms_pre_entry_sending_reply_charging_settings, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_sending_reply_charging_settings
 * DESCRIPTION
 *  Pre entry fn for reply charging settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_sending_reply_charging_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_entry_sending_reply_charging_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_confirm_save_sending_settings
 * DESCRIPTION
 *  Ask for the confirmation for saving sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_confirm_save_sending_settings(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_save_sending_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_umms_exit_confirm_screen, KEY_EVENT_UP);

    /*
     * if (g_umms_control == E_ENTRY_FROM_WRITE_MMS)
     * {
     * SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN);
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_sending_settings
 * DESCRIPTION
 *  save the send settings into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* /write global struct into values into NVRAM */
    g_umms_context->nvram_sending_settings.delivery_report =
        (U8) g_umms_context->umms_inline_items.sending_items_list.delivery_report;
    g_umms_context->nvram_sending_settings.delivery_time =
        (U8) g_umms_context->umms_inline_items.sending_items_list.delivery_time;
    g_umms_context->nvram_sending_settings.hide_sender =
        (U8) g_umms_context->umms_inline_items.sending_items_list.hide_sender;
    g_umms_context->nvram_sending_settings.priority =
        (U8) g_umms_context->umms_inline_items.sending_items_list.priority;
    g_umms_context->nvram_sending_settings.read_report =
        (U8) g_umms_context->umms_inline_items.sending_items_list.read_report;
    g_umms_context->nvram_sending_settings.reply_charging =
        (U8) g_umms_context->umms_inline_items.sending_items_list.reply_charging;
    g_umms_context->nvram_sending_settings.request_type =
        (U8) g_umms_context->umms_inline_items.sending_items_list.request_type;
    g_umms_context->nvram_sending_settings.validity_period =
        (U8) g_umms_context->umms_inline_items.sending_items_list.validity_period;
    g_umms_context->nvram_sending_settings.send_and_save =
        (U32) g_umms_context->umms_inline_items.sending_items_list.send_and_save;

    g_umms_context->nvram_sending_settings.deadline_for_reply =
        (U32) gui_atoi((UI_string_type) g_umms_context->umms_inline_items.sending_items_list.deadline_for_reply_buffer);
    g_umms_context->nvram_sending_settings.size =
        (U32) gui_atoi((UI_string_type) g_umms_context->umms_inline_items.sending_items_list.reply_msg_size_buffer);

    WriteRecord(
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        1,
        &g_umms_context->nvram_sending_settings,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        &error);
    g_umms_context->on_bootup = FALSE;
    mmi_umms_set_processing_screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_SENDING,
        STR_ID_UMMS_SETTINGS_SAVING,
        IMG_GLOBAL_PROGRESS,
        0);
    mmi_umms_entry_processing_generic();
    mmi_umms_set_setting_to_mma_req();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_sending_reply_charging_settings
 * DESCRIPTION
 *  Entry fn for the Reply charging settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_sending_reply_charging_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[SENDING_REPLY_CHARGING_INLINE_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_SENDING_SETTINGS, mmi_umms_exit_sending_reply_charging_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_SENDING_REPLY_CHARGING_SETTINGS);

    InitializeCategory57Screen();

    mmi_umms_sending_reply_charging_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_SENDING_REPLY_CHARGING_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UMMS_SENDING_REPLY_CHARGING_SETTINGS, &inputBufferSize);   /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, SENDING_REPLY_CHARGING_INLINE_TOTAL, inputBuffer); /* sets the data */
    }

    image_list[E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION] = gIndexIconsImageList[0];
    image_list[E_SENDING_REPLY_CHARGING_DEADLINE_CAPTION] = gIndexIconsImageList[1];
    image_list[E_SENDING_REPLY_CHARGING_SIZE_CAPTION] = gIndexIconsImageList[2];

    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        SENDING_REPLY_CHARGING_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_umms_sending_reply_charging_settings_done, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_reply_charging_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for reply charging settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_sending_reply_charging_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_context->umms_inline_items.sending_items_list.reply_charging_request_list[0] = GetString(STR_ID_UMMS_SETTINGS_REQUEST_TYPE_FULL_MMS);
    g_umms_context->umms_inline_items.sending_items_list.reply_charging_request_list[1] = GetString(STR_ID_UMMS_SETTINGS_REQUEST_TYPE_ONLY_TEXT);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_REQUEST_TYPE));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE],
        2,
        (U8 **) g_umms_context->umms_inline_items.sending_items_list.reply_charging_request_list,
        &g_umms_context->umms_inline_items.sending_items_list.request_type);
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_DEADLINE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_DEADLINE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_REPLY_DEADLINE));
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_DEADLINE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_DEADLINE],
        (U8*) g_umms_context->umms_inline_items.sending_items_list.deadline_for_reply_buffer,
        (UMMS_MAX_DEADLINE_TIME_VALUE_INPUT + 1),
        INPUT_TYPE_NUMERIC);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_REPLY_CHARGE_SIZE));
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE],
        (U8*) g_umms_context->umms_inline_items.sending_items_list.reply_msg_size_buffer,
        (UMMS_MAX_REPLY_CHARGE_SIZE_INPUT + 1),
        INPUT_TYPE_NUMERIC);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_sending_reply_charging_settings
 * DESCRIPTION
 *  Exit fn for reply charging setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_sending_reply_charging_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_UMMS_SENDING_REPLY_CHARGING_SETTINGS;
    history_buff.entryFuncPtr = mmi_umms_entry_sending_reply_charging_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, inputBufferSize);         /* added for inline edit history */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_reply_charging_settings_done
 * DESCRIPTION
 *  Done handler of Reply charging settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_sending_reply_charging_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_reply_charging_done = 1;

    if (mmi_ucs2ncmp
        ((S8*) g_umms_context->umms_inline_items.sending_items_list.deadline_for_reply_buffer, "\0",
         UMMS_MAX_DEADLINE_TIME_VALUE_INPUT * ENCODING_LENGTH) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_UMMS_SETTINGS_REPLY_DEADLINE_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            UMMS_POPUP_TIME,
            ERROR_TONE);
    }
    else if (mmi_ucs2ncmp
             ((S8*) g_umms_context->umms_inline_items.sending_items_list.reply_msg_size_buffer, "\0",
              UMMS_MAX_REPLY_CHARGE_SIZE_INPUT * ENCODING_LENGTH) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_UMMS_SETTINGS_REPLY_CHARGE_SIZE_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            UMMS_POPUP_TIME,
            ERROR_TONE);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_sending_settings_highlight_hdlr
 * DESCRIPTION
 *  Highlight hdlr for sending setting screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_sending_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_reply_charging_done == 1)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_umms_confirm_save_sending_settings, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_compose_settings
 * DESCRIPTION
 *  write the compose settings to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 temp_max_no_pages = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* /write global struct into values into NVRAM */
    temp_max_no_pages = gui_atoi((UI_string_type) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer);
    g_umms_context->nvram_compose_settings.default_slide_time =
        (U32) gui_atoi((UI_string_type) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer);
    #ifdef __MMI_MMS_SIGNATURE__
    g_umms_context->nvram_compose_settings.auto_signature =
        g_umms_context->umms_inline_items.compose_items_list.auto_signature;

	if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
		(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
		mmi_ucs2cpy((S8*)g_umms_context->nvram_compose_settings.auto_signature_image_file,
			(S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			{
				if(g_file_ext[IMAGE_EXT] != NULL)
				{
					mmi_umms_make_file_name((S8*)g_umms_context->nvram_compose_settings.auto_signature_image_file, (S8*)g_file_ext[IMAGE_EXT]);
				}
			}
			#endif
    }
	else
    {
		memset(g_umms_context->nvram_compose_settings.auto_signature_image_file, 0, 
			(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
    }

	if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
		(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
		mmi_ucs2cpy((S8*)g_umms_context->nvram_compose_settings.auto_signature_video_file,
			(S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			{
				if(g_file_ext[VIDEO_EXT] != NULL)
				{
					mmi_umms_make_file_name((S8*)g_umms_context->nvram_compose_settings.auto_signature_video_file, (S8*)g_file_ext[VIDEO_EXT]);
				}
			}
			#endif
    }
            else
{
		memset(g_umms_context->nvram_compose_settings.auto_signature_video_file, 0, 
			(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
}

	if(mmi_ucs2cmp((S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
		(S8*)GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
        {
		mmi_ucs2cpy((S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file,
			(S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);
			#if (!defined(__MMI_SHOW_FILE_EXT__))
			{
				if(g_file_ext[AUDIO_EXT] != NULL)
				{
					mmi_umms_make_file_name((S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file, (S8*)g_file_ext[AUDIO_EXT]);
				}
			}
			#elif (!defined(__MMI_SHOW_DAF_FILE_EXT__))
				if(g_umms_context->umms_inline_items.compose_items_list.signature_flag
					& UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED)
				{
					S8 mp3_ext[]={'m',0,'p',0,'3',0,0,0};
					mmi_umms_make_file_name((S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file, (S8*)mp3_ext);
				}
			#endif

            }
            else
            {
		memset(g_umms_context->nvram_compose_settings.auto_signature_audio_file, 0, 
			(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
}

//	mmi_ucs2cpy((S8*)g_umms_context->nvram_compose_settings.auto_signature_image_file, (S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
//	mmi_ucs2cpy((S8*)g_umms_context->nvram_compose_settings.auto_signature_video_file, (S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
//	mmi_ucs2cpy((S8*)g_umms_context->nvram_compose_settings.auto_signature_audio_file, (S8*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);

#endif /* __MMI_MMS_SIGNATURE__ */ 
    g_umms_context->nvram_compose_settings.best_page_duration =
        g_umms_context->umms_inline_items.compose_items_list.best_page_duration;
    g_umms_context->nvram_compose_settings.creation_mode =
        g_umms_context->umms_inline_items.compose_items_list.creation_mode;
    g_umms_context->nvram_compose_settings.image_resize_option =
        g_umms_context->umms_inline_items.compose_items_list.image_resize_option;
#ifdef __DRM_SUPPORT__
    g_umms_context->nvram_compose_settings.add_drm = g_umms_context->umms_inline_items.compose_items_list.add_drm;
#endif 
    g_umms_context->nvram_compose_settings.layout = g_umms_context->umms_inline_items.compose_items_list.layout;
    g_umms_context->nvram_compose_settings.max_no_pages = (U8) temp_max_no_pages;

    WriteRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_umms_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);
    g_umms_context->on_bootup = FALSE;
    mmi_umms_set_processing_screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_COMPOSE,
        STR_ID_UMMS_SETTINGS_SAVING,
        IMG_GLOBAL_PROGRESS,
        0);
    mmi_umms_entry_processing_generic();
    mmi_umms_set_setting_to_mma_req();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_retrieval_settings
 * DESCRIPTION
 *  Pre Entry fn for retrieval setting screeen.It init the retreival inline items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_context->umms_inline_items.retrieval_items_list.advertisement_filter =
        (S32) g_umms_context->nvram_retrieval_settings.advertisement_filter;
    g_umms_context->umms_inline_items.retrieval_items_list.anonymous_filter =
        (S32) g_umms_context->nvram_retrieval_settings.anonymous_filter;
    g_umms_context->umms_inline_items.retrieval_items_list.delivery_report =
        (S32) g_umms_context->nvram_retrieval_settings.delivery_report;
    g_umms_context->umms_inline_items.retrieval_items_list.home_network =
        (S32) g_umms_context->nvram_retrieval_settings.home_network - 1;
    g_umms_context->umms_inline_items.retrieval_items_list.read_report =
        (S32) g_umms_context->nvram_retrieval_settings.read_report;
    g_umms_context->umms_inline_items.retrieval_items_list.roaming =
        (S32) g_umms_context->nvram_retrieval_settings.roaming;
#ifndef __MMI_MMS_OMA_CONF_273__
    gui_itoa(
        (S32) g_umms_context->nvram_retrieval_settings.msgsize_filter,
        (UI_string_type) g_umms_context->umms_inline_items.retrieval_items_list.msg_size_filter_buffer,
        10);
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    g_recieve_filter_done = E_OFF;
    mmi_umms_entry_retrieval_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_retrieval_settings
 * DESCRIPTION
 *  Entry fn for retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[RETRIEVAL_INLINE_TOTAL] = {0};
	U8 index = 0;
	U16 total_items = RETRIEVAL_INLINE_TOTAL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_RETRIEVAL_SETTINGS, mmi_umms_exit_retrieval_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_RETRIEVAL_SETTINGS);

    InitializeCategory57Screen();

    mmi_umms_retrieval_fill_inline_struct();
    RegisterHighlightHandler(mmi_umms_retrieval_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_RETRIEVAL_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UMMS_RETRIEVAL_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, RETRIEVAL_INLINE_TOTAL, inputBuffer);      /* sets the data */
    }
#ifdef __CMCC_RETRIVAL_MODE_SETTING__
	 if (mmi_bootup_is_roaming() == TRUE)
	 {
		 total_items = RETRIEVAL_INLINE_TOTAL;
		image_list[E_RETRIEVAL_ROAMING_CAPTION] = gIndexIconsImageList[index++];
		image_list[E_RETRIEVAL_FILTERS_CAPTION] = gIndexIconsImageList[index++];
		image_list[E_RETRIEVAL_READ_REPORT_CAPTION] = gIndexIconsImageList[index++];
		image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[index++];
	 }
	 else
	 {
		total_items = RETRIEVAL_INLINE_TOTAL-2;
		image_list[E_RETRIEVAL_FILTERS_CAPTION-2] = gIndexIconsImageList[index++];
		image_list[E_RETRIEVAL_READ_REPORT_CAPTION-2] = gIndexIconsImageList[index++];
		image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION-2] = gIndexIconsImageList[index++];

	 }
#else
    image_list[E_RETRIEVAL_HOME_NETWORK_CAPTION] = gIndexIconsImageList[index++];
		image_list[E_RETRIEVAL_ROAMING_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_FILTERS_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_READ_REPORT_CAPTION] = gIndexIconsImageList[index++];
    image_list[E_RETRIEVAL_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[index++];

#endif

    ShowCategory57Screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_RETRIEVAL,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        total_items,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_umms_confirm_save_retrieval_settings, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_confirm_save_retrieval_settings
 * DESCRIPTION
 *  Confirmation screen entry fn for saving retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_confirm_save_retrieval_settings(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_save_retrieval_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_umms_exit_confirm_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_retrieval_settings
 * DESCRIPTION
 *  write the retrieval settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_OMA_CONF_273__
    S32 temp_msg_size_filter_value = 0;
#endif 
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_context->nvram_retrieval_settings.advertisement_filter =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.advertisement_filter;
    g_umms_context->nvram_retrieval_settings.anonymous_filter =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.anonymous_filter;
    g_umms_context->nvram_retrieval_settings.delivery_report =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.delivery_report;
    g_umms_context->nvram_retrieval_settings.home_network =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.home_network + 1;
    g_umms_context->nvram_retrieval_settings.read_report =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.read_report;
    g_umms_context->nvram_retrieval_settings.roaming =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.roaming;
#ifndef __MMI_MMS_OMA_CONF_273__
    temp_msg_size_filter_value = gui_atoi((UI_string_type) g_umms_context->umms_inline_items.retrieval_items_list.msg_size_filter_buffer);
    g_umms_context->nvram_retrieval_settings.msgsize_filter = (U16) temp_msg_size_filter_value;
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    WriteValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_umms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
    g_umms_context->on_bootup = FALSE;
    mmi_umms_set_processing_screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_RETRIEVAL,
        STR_ID_UMMS_SETTINGS_SAVING,
        IMG_GLOBAL_PROGRESS,
        0);
    mmi_umms_entry_processing_generic();
    mmi_umms_set_setting_to_mma_req();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for retrieval settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_retrieval_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	U16 retrieval_option = 0;
    if (g_umms_context->umms_inline_lists == NULL)
    {
        g_umms_context->umms_inline_lists =
            (umms_common_inline_lists_struct*) umms_malloc(sizeof(umms_common_inline_lists_struct) /* , 1 */ );
        MMI_ASSERT(g_umms_context->umms_inline_lists != NULL);
        if (g_umms_context->umms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }
#ifdef __CMCC_RETRIVAL_MODE_SETTING__
	 if (mmi_bootup_is_roaming() == TRUE)
	 {
		g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[0] = GetString(STR_ID_UMMS_SETTINGS_AS_HOME);
		g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[1] = GetString(STR_ID_UMMS_SETTINGS_IMMEDIATE);
		g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[2] = GetString(STR_ID_UMMS_SETTINGS_DEFFERED);
		g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[3] = GetString(STR_ID_UMMS_SETTINGS_REJECT);
	 }
	 else
	 {
		 retrieval_option = 2;
	 }

#else
    g_umms_context->umms_inline_items.retrieval_items_list.home_network_list[0] = GetString(STR_ID_UMMS_SETTINGS_IMMEDIATE);
    g_umms_context->umms_inline_items.retrieval_items_list.home_network_list[1] = GetString(STR_ID_UMMS_SETTINGS_DEFFERED);
    g_umms_context->umms_inline_items.retrieval_items_list.home_network_list[2] = GetString(STR_ID_UMMS_SETTINGS_REJECT);

    g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[0] = GetString(STR_ID_UMMS_SETTINGS_AS_HOME);
    g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[1] = GetString(STR_ID_UMMS_SETTINGS_IMMEDIATE);
    g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[2] = GetString(STR_ID_UMMS_SETTINGS_DEFFERED);
    g_umms_context->umms_inline_items.retrieval_items_list.roaming_list[3] = GetString(STR_ID_UMMS_SETTINGS_REJECT);
#endif
    g_umms_context->umms_inline_items.retrieval_items_list.read_report_list[0] = GetString(STR_ID_UMMS_SETTINGS_ON_REQUEST);
    g_umms_context->umms_inline_items.retrieval_items_list.read_report_list[1] = GetString(STR_ID_UMMS_SETTINGS_SEND);
    g_umms_context->umms_inline_items.retrieval_items_list.read_report_list[2] = GetString(STR_ID_UMMS_SETTINGS_NEVER_SEND);

    g_umms_context->umms_inline_lists->on_off_list[0] = GetString(STR_ID_UMMS_SETTINGS_OFF);
    g_umms_context->umms_inline_lists->on_off_list[1] = GetString(STR_ID_UMMS_SETTINGS_ON);
#ifdef __CMCC_RETRIVAL_MODE_SETTING__
	 if (mmi_bootup_is_roaming() == TRUE)
	 {
		SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_ROAMING_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemCaption(&wgui_inline_items[E_RETRIEVAL_ROAMING_CAPTION], (U8*) GetString(STR_ID_UMMS_SETTINGS_ROAMING));
		SetInlineItemSelect(
			&wgui_inline_items[E_RETRIEVAL_ROAMING],
			4,
			(U8 **) g_umms_context->umms_inline_items.retrieval_items_list.roaming_list,
			&g_umms_context->umms_inline_items.retrieval_items_list.roaming);
		SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_ROAMING], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	 }

#else
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_HOME_NETWORK));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_HOME_NETWORK],
        3,
        (U8 **) g_umms_context->umms_inline_items.retrieval_items_list.home_network_list,
        &g_umms_context->umms_inline_items.retrieval_items_list.home_network);
    SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_HOME_NETWORK], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_ROAMING_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_RETRIEVAL_ROAMING_CAPTION], (U8*) GetString(STR_ID_UMMS_SETTINGS_ROAMING));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_ROAMING],
        4,
        (U8 **) g_umms_context->umms_inline_items.retrieval_items_list.roaming_list,
        &g_umms_context->umms_inline_items.retrieval_items_list.roaming);
    SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_ROAMING], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif
    SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_FILTERS_CAPTION - retrieval_option], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_CAPTION - retrieval_option],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_FILTERS));

    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT_CAPTION - retrieval_option],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT_CAPTION - retrieval_option],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_READ_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_READ_REPORT - retrieval_option],
        3,
        (U8 **) g_umms_context->umms_inline_items.retrieval_items_list.read_report_list,
        &g_umms_context->umms_inline_items.retrieval_items_list.read_report);
    SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_READ_REPORT - retrieval_option], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT_CAPTION - retrieval_option],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT_CAPTION - retrieval_option],
        (U8*) GetString(STR_ID_UMMS_DELIVERY_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT - retrieval_option],
        2,
        (U8 **) g_umms_context->umms_inline_lists->on_off_list,
        &g_umms_context->umms_inline_items.retrieval_items_list.delivery_report);
    SetInlineItemActivation(&wgui_inline_items[E_RETRIEVAL_DELIVERY_REPORT - retrieval_option], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_retrieval_settings
 * DESCRIPTION
 *  Exit fn for the retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_UMMS_RETRIEVAL_SETTINGS;
    history_buff.entryFuncPtr = mmi_umms_entry_retrieval_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, inputBufferSize);         /* added for inline edit history */

    if (g_umms_context->umms_inline_lists != NULL)
    {
        umms_free(g_umms_context->umms_inline_lists);
        g_umms_context->umms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_retrieval_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	U16 caption_index = 0;
#ifdef __CMCC_RETRIVAL_MODE_SETTING__
	 if (mmi_bootup_is_roaming() == FALSE)
	 {
		 caption_index = 2;
	 }
#endif
    if (index == (E_RETRIEVAL_FILTERS_CAPTION - caption_index))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_umms_entry_retrieval_filters_settings, KEY_EVENT_UP);
    }
    if (g_recieve_filter_done == E_ON)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_umms_confirm_save_retrieval_settings, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_retrieval_filters_settings
 * DESCRIPTION
 *  Entry fn for filter settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_retrieval_filters_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;     /* added for inline edit history */
    U16 inputBufferSize = 0;    /* added for inline edit history */
    U16 image_list[RETRIEVAL_FILTER_INLINE_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS, mmi_umms_exit_retrieval_filters_settings, NULL, NULL);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS);

    InitializeCategory57Screen();

    mmi_umms_retrieval_filters_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS, &inputBufferSize);        /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, RETRIEVAL_FILTER_INLINE_TOTAL, inputBuffer);       /* sets the data */
    }

    image_list[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION] = gIndexIconsImageList[0];
#ifndef __MMI_MMS_OMA_CONF_273__
    image_list[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION] = gIndexIconsImageList[1];
    image_list[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION] = gIndexIconsImageList[2];
#else /* __MMI_MMS_OMA_CONF_273__ */ 
    image_list[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION] = gIndexIconsImageList[1];
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    ShowCategory57Screen(
        STR_ID_UMMS_SETTINGS_FILTERS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        RETRIEVAL_FILTER_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_umms_filter_done_handler, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_filter_done_handler
 * DESCRIPTION
 *  Done handler of filter screen. it checks that msg size input is not > 148KB and not empty.or 0.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_filter_done_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_OMA_CONF_273__
    U32 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = gui_atoi((UI_string_type) g_umms_context->umms_inline_items.retrieval_items_list.msg_size_filter_buffer);

    if ((temp > wap_custom_get_max_mms_msg_size())
        || (g_umms_context->umms_inline_items.retrieval_items_list.msg_size_filter_buffer[0] == 48)
        ||
        (mmi_ucs2ncmp
         ((S8*) g_umms_context->umms_inline_items.retrieval_items_list.msg_size_filter_buffer, "\0",
          UMMS_MAX_FILTER_MSG_SIZE_INPUT * ENCODING_LENGTH) == 0))
    {
        DisplayPopup((U8*) GetString(STR_ID_UMMS_MAX_MSG_SIZE_LIMT), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
    }
    else
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    {
        g_recieve_filter_done = E_ON;
        GoBackHistory();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_retrieval_filters_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline sttruct for filter settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_retrieval_filters_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_umms_context->umms_inline_lists == NULL)
    {
        g_umms_context->umms_inline_lists =
            (umms_common_inline_lists_struct*) umms_malloc(sizeof(umms_common_inline_lists_struct));
        MMI_ASSERT(g_umms_context->umms_inline_lists != NULL);
        if (g_umms_context->umms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, UMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }
    g_umms_context->umms_inline_lists->allow_reject_list[0] = GetString(STR_ID_UMMS_SETTINGS_ALLOW);
    g_umms_context->umms_inline_lists->allow_reject_list[1] = GetString(STR_ID_UMMS_SETTINGS_REJECT);

    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_ANNONYMOUS));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS],
        2,
        (U8 **) g_umms_context->umms_inline_lists->allow_reject_list,
        &g_umms_context->umms_inline_items.retrieval_items_list.anonymous_filter);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
#ifndef __MMI_MMS_OMA_CONF_273__
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_MAX_MSG_SIZE));
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE],
        (U8*) g_umms_context->umms_inline_items.retrieval_items_list.msg_size_filter_buffer,
        (UMMS_MAX_FILTER_MSG_SIZE_INPUT + 1),
        INPUT_TYPE_NUMERIC);
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION],
        (U8*) GetString(STR_ID_UMMS_SETTINGS_ADVERTISMENT));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT],
        2,
        (U8 **) g_umms_context->umms_inline_lists->allow_reject_list,
        &g_umms_context->umms_inline_items.retrieval_items_list.advertisement_filter);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_retrieval_filters_settings
 * DESCRIPTION
 *  Exit fn for filter settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_retrieval_filters_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS;
    history_buff.entryFuncPtr = mmi_umms_entry_retrieval_filters_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, inputBufferSize);         /* added for inline edit history */

    if (g_umms_context->umms_inline_lists != NULL)
    {
        umms_free(g_umms_context->umms_inline_lists);
        g_umms_context->umms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_restore_nvram_default_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_restore_nvram_default_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIGNATURE__
    g_umms_context->nvram_compose_settings.auto_signature = (U8) E_OFF;
#endif 
    g_umms_context->nvram_compose_settings.best_page_duration = (U8) E_OFF;
    g_umms_context->nvram_compose_settings.creation_mode = (U8) E_CREAT_MODE_FREE;
    g_umms_context->nvram_compose_settings.image_resize_option = (U8) E_IMAGE_RESIZE_OFF;
#ifdef __DRM_SUPPORT__
    g_umms_context->nvram_compose_settings.add_drm = (U8) E_OFF;
#endif 
    g_umms_context->nvram_compose_settings.layout = (U8) E_MMS_LAYOUT_POTRAIT;
#ifdef __MMI_MMS_SIGNATURE__
    memset(
        g_umms_context->nvram_compose_settings.auto_signature_content,
        0x00,
        (UMMS_MAX_AUTO_SIGN_LENGTH + 1) * ENCODING_LENGTH);
#endif /* __MMI_MMS_SIGNATURE__ */ 
    g_umms_context->nvram_compose_settings.max_no_pages = (U8) UMMS_MAX_POSSIBLE_SLIDES;
    g_umms_context->nvram_compose_settings.default_slide_time = ((U32) UMMS_DEFAULT_SLIDE_DURATION) / 1000;     /* /convert to seconds */

    WriteRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_umms_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    g_umms_context->nvram_sending_settings.deadline_for_reply = (U32) 0;
    g_umms_context->nvram_sending_settings.delivery_report = (U8) UMMS_DEFAULT_DELIVERY_REPORT_DURING_SENDING;
    g_umms_context->nvram_sending_settings.delivery_time = (U8) E_IMMEDIATE;
    g_umms_context->nvram_sending_settings.hide_sender = (U8) E_OFF;
    g_umms_context->nvram_sending_settings.priority = (U8) E_PRIORITY_NORMAL;
    g_umms_context->nvram_sending_settings.read_report = (U8) UMMS_DEFAULT_READ_REPORT_DURING_SENDING;
    g_umms_context->nvram_sending_settings.reply_charging = (U8) E_OFF;
    g_umms_context->nvram_sending_settings.request_type = (U8) E_FULL_MMS;
    g_umms_context->nvram_sending_settings.size = (U32) 0;
    g_umms_context->nvram_sending_settings.validity_period = (U8) E_VALIDITY_PERIOD_MAX;

    WriteRecord(
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        1,
        &g_umms_context->nvram_sending_settings,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        &error);

    g_umms_context->nvram_retrieval_settings.home_network = (U8) UMMS_DEFAULT_HOME_RETRIEVAL_MODE;
    g_umms_context->nvram_retrieval_settings.roaming = (U8) UMMS_DEFAULT_ROAMING_RETRIEVAL_MODE;
    g_umms_context->nvram_retrieval_settings.anonymous_filter = (U8) UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE;
    g_umms_context->nvram_retrieval_settings.advertisement_filter = (U8) UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE;
    g_umms_context->nvram_retrieval_settings.read_report = (U8) UMMS_DEFAULT_READ_REPORT_DURING_RETRIEVAL;
    g_umms_context->nvram_retrieval_settings.delivery_report = (U8) UMMS_DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL;
#ifndef __MMI_MMS_OMA_CONF_273__
    g_umms_context->nvram_retrieval_settings.msgsize_filter = (U16) wap_custom_get_max_mms_msg_size();
#endif 
    WriteValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_umms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
    ReadValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_umms_context->nvram_retrieval_settings, DS_DOUBLE, &error);

    mmi_umms_set_setting_to_mma_req();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_memory_status
 * DESCRIPTION
 *  This is pre entry function for memory status, which initiate the process to get it from MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */  
    
    mmi_umms_set_processing_screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_MEMORY_STATUS,
        STR_ID_UMMS_PLEASE_WAIT,
        IMG_GLOBAL_PROGRESS,
        0);
    mmi_umms_entry_processing_generic();
    mmi_umms_get_setting_memory_status_req();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_setting_memory_status_req
 * DESCRIPTION
 *  This function sends the request to get the memory status from MMA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_setting_memory_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_get_mem_status_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (wap_mma_get_mem_status_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

    msgReq->req_id = wap_mma_get_request_id();
    msgReq->app_id = MMA_APP_ID_SETTING;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ, (oslParaType*) msgReq, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_memory_status_rsp
 * DESCRIPTION
 *  This is the response handler for memory status request.
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_memory_status_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_get_mem_status_rsp_struct *msg = (wap_mma_get_mem_status_rsp_struct*) inMsg;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_get_memory_status_rsp result=%d,used_size =%d,free_size=%d *\n",
                         msg->result, msg->used_size, msg->free_size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->result == MMA_RESULT_OK)
    {
        g_memory_status.used_size = msg->used_size;
        g_memory_status.free_size = msg->free_size;
        mmi_umms_get_total_mms_num_req();

    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_total_mms_num_req
 * DESCRIPTION
 *  This function sends the request to get the total number of MMS present in different folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_total_mms_num_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_get_msg_num_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_SETTING;
    msgReq->msg_type = UM_MSG_TYPE_MMS;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (oslParaType*) msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_total_mms_num_rsp
 * DESCRIPTION
 *  This function is response handler
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_total_mms_num_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_rsp_struct *msg = (mmi_um_get_msg_num_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->result)
    {
        g_memory_status.total_mms = msg->inbox_unread_msg_number + msg->inbox_read_msg_number
            + msg->unsent_msg_number + msg->sent_msg_number + msg->draft_msg_number
            + msg->predefined_template_msg_number + msg->userdefined_template_msg_number;
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			g_memory_status.total_mms = g_memory_status.total_mms + msg->archive_msg_number;
		#endif 
        mmi_umms_entry_memory_status_screen();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_memory_status_screen
 * DESCRIPTION
 *  This function is entry function for memory status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_memory_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    S8 tempBuf[UMMS_MEMORY_STATUS_TEMP_BUF];
    S8 tempBufUnicode[UMMS_MEMORY_STATUS_TEMP_BUF * ENCODING_LENGTH];
    S8 spaceBuf[UMMS_MEMORY_STATUS_TEMP_BUF];
    U8 messageStatusTotal = 0;
    U32 free_space = 0;
    U32 size = 0;
    S32 size_kb = 0;
    S32 size_bytes = 0;
    S8 memoryStatus[UMMS_MEMORY_STATUS_MAX_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UMMS_PROGRESS))
    {
        HistoryReplace(SCR_ID_UMMS_PROGRESS, SCR_ID_UMMS_MMS_MESSAGE_STATUS, mmi_umms_entry_memory_status_screen);
        return;
    }

    if (GetActiveScreenId() != SCR_ID_UMMS_PROGRESS && IsScreenPresent(SCR_ID_UMMS_MMS_MESSAGE_STATUS) == FALSE)
    {
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        return;
    }

    EntryNewScreen(SCR_ID_UMMS_MMS_MESSAGE_STATUS, NULL, mmi_umms_pre_entry_memory_status, NULL);
    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    messageStatusTotal = UMMS_MAX_POSSIBLE_MESSAGES;

    mmi_ucs2cpy(memoryStatus, (S8*) GetString(STR_ID_UMMS_SETTINGS_MESSAGE_STATUS_TOTAL));
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    mmi_asc_to_ucs2(spaceBuf, ": ");
    mmi_ucs2cat(memoryStatus, spaceBuf);
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    sprintf(tempBuf, "%d/%d", g_memory_status.total_mms, messageStatusTotal);
    mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
    mmi_ucs2cat(memoryStatus, tempBufUnicode);

    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat(memoryStatus, spaceBuf);

    mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_UMMS_SETTINGS_MESSAGE_STATUS_USAGE));
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    mmi_asc_to_ucs2(spaceBuf, ": ");
    mmi_ucs2cat(memoryStatus, spaceBuf);
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);

    /* Added a New line after "Used Space:" */
    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat(memoryStatus, spaceBuf);
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);

    memset(tempBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    memset(tempBufUnicode, 0, UMMS_MEMORY_STATUS_TEMP_BUF * ENCODING_LENGTH);
    size = g_memory_status.used_size;
    size_kb = size / 1024;
    size_bytes = size % 1024;

    if (size_kb >= 1)
    {
        if (size_bytes > 512)
        {
            size_kb++;
        }
        sprintf(tempBuf, "%d ", size_kb);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat(memoryStatus, tempBufUnicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_UMMS_KB));

    }
    else
    {
        sprintf(tempBuf, "%d ", size);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat(memoryStatus, tempBufUnicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_UMMS_BYTES));

    }

    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat(memoryStatus, spaceBuf);
    mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_UMMS_SETTINGS_FREE_SPACE));
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    mmi_asc_to_ucs2(spaceBuf, ": ");
    mmi_ucs2cat(memoryStatus, spaceBuf);
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);

    /* Added a New line after "Free Space:" */
    mmi_asc_to_ucs2(spaceBuf, "\n");
    mmi_ucs2cat(memoryStatus, spaceBuf);
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);

    memset(tempBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    memset(tempBufUnicode, 0, UMMS_MEMORY_STATUS_TEMP_BUF * ENCODING_LENGTH);
    free_space = g_memory_status.free_size;
    size = free_space;
    size_kb = size / 1024;
    size_bytes = size % 1024;
    if (size_kb >= 1)
    {
        if (size_bytes > 512)
        {
            size_kb++;
        }
        sprintf(tempBuf, "%d ", size_kb);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat(memoryStatus, tempBufUnicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_UMMS_KB));

    }
    else
    {
        sprintf(tempBuf, "%d ", size);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat(memoryStatus, tempBufUnicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_UMMS_BYTES));

    }
    memset(spaceBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    memset(tempBuf, 0, UMMS_MEMORY_STATUS_TEMP_BUF);
    memset(tempBufUnicode, 0, UMMS_MEMORY_STATUS_TEMP_BUF * ENCODING_LENGTH);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_MMS_MESSAGE_STATUS);

    SetMessagesCurrScrnID(SCR_ID_UMMS_MMS_MESSAGE_STATUS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_UMMS_MMS_MESSAGE_STATUS);

    ShowCategory7Screen(
        STR_ID_UMMS_MESSAGE_SETTINGS_MEMORY_STATUS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) memoryStatus,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_processing_generic
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UMMS_PROGRESS, mmi_umms_exit_processing_generic, mmi_umms_entry_processing_generic, NULL);

#ifdef __MMI_MAINLCD_240X320__
    /* passing 0xffff for Title string and Title icon for the disbling the status bar and title display. */
    ShowCategory8Screen(
        0xffff,
        0xffff,
        0,
        0,
        g_umms_context->RSK_str_id,
        0,
        g_umms_context->body_str_id,
        g_umms_context->animation_image_id,
        NULL);
#else /* __MMI_MAINLCD_240X320__ */ 
    ShowCategory8Screen(
        g_umms_context->caption_str_id,
        IMG_UM_ENTRY_SCRN_CAPTION,
        0,
        0,
        g_umms_context->RSK_str_id,
        0,
        g_umms_context->body_str_id,
        g_umms_context->animation_image_id,
        NULL);
#endif /* __MMI_MAINLCD_240X320__ */ 

    if (g_umms_context->RSK_str_id == 0)
    {

        /*
         * ClearAllKeyHandler();
         * ClearKeyHandler(KEY_END, KEY_EVENT_UP);
         * ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
         * ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
         * ClearKeyHandler(KEY_END, KEY_REPEAT);
         */
        SetKeyHandler(mmi_umms_progress_screen_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
        if (isInCall())
        {
            SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
        }

        StartTimer(UMMS_INPROGRESS_TIMER_ID, UMMS_MMI_INPROGRESS_TIME_OUT, mmi_umms_time_out_processing_generic);
    }
    else
    {
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_progress_screen_end_key_hdlr
 * DESCRIPTION
 *  This function is END key handler for progressign screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_progress_screen_end_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_reset_template_state_on_end_key();
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_processing_generic
 * DESCRIPTION
 *  This function is exit handler for progressing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UMMS_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_time_out_processing_generic
 * DESCRIPTION
 *  This function called when this screen is not removed after passing of certain predefined time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_time_out_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UMMS_INPROGRESS_TIMER_ID);
    if (GetExitScrnID() == SCR_ID_UMMS_PROGRESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_processing_screen
 * DESCRIPTION
 *  This function set the various parameter of progressing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_context->caption_str_id = captionStrId;
    g_umms_context->body_str_id = bodyStrId;
    g_umms_context->animation_image_id = animationImageId;
    g_umms_context->RSK_str_id = rskStrId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_check_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_check_resize(U8 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_image_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    /* S8 *mime ; */
    U16 width = 0;
    U16 height = 0;
    S32 resize_result = 0;
    applib_mime_type_struct *mime = NULL;

    /* FS_HANDLE file_handle; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_umms_context->nvram_compose_settings.image_resize_option)
    {
        case E_IMAGE_RESIZE_OFF:
            return 0;
        case E_IMAGE_RESIZE_160x120:
            width = 160;
            height = 120;
            break;
        case E_IMAGE_RESIZE_320x240:
            width = 320;
            height = 240;
            break;
        case E_IMAGE_RESIZE_640x480:
            width = 640;
            height = 480;
            break;
    }
    mime = mime_get_file_type((U16*) filePath);
    /* mime = mma_get_mime_type_from_filename(filePath); */
    if (strstr(MMA_OPEN_IMAGE_TYPES, mime->mime_string) && mime != NULL)
    {
        /* MMI_UC_MAKE_IMAGE_FILE_PATH(mmi_uc_image_path, ++g_uc_p->main.image_no); */
        kal_wsprintf(
            (kal_uint16*) mmi_uc_image_path,
            "%c:\\%s\\%s%03d.%s",
            MMI_PUBLIC_DRV,
            "_UC",
            "image00",
            1,
            "jpg");
        // file_handle = FS_Open((U16*) mmi_uc_image_path, FS_CREATE_ALWAYS | FS_READ_WRITE); 
        //   FS_Close(file_handle);
        resize_result = mmi_uc_resize_image((U8*) filePath, mmi_uc_image_path, width, height);
        if (resize_result < 0)
        {
            //mmi_uc_display_popup(/*MMI_UC_ERROR*/);
            //DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            return -1;
        }
        else if (resize_result == 1)
        {
            memset(filePath, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
            mmi_ucs2cpy((S8*) filePath, (S8*) mmi_uc_image_path);
        }
    }
    else
    {
        return 0;
    }

    return 1;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_current_profile
 * DESCRIPTION
 *  set the current active profile.
 * PARAMETERS
 *  boot_up       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_current_mms_profile(BOOL boot_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(boot_up == FALSE)
	{
		mmi_umms_set_processing_screen(
			STR_ID_UMMS_PLEASE_WAIT,
			STR_ID_UMMS_PLEASE_WAIT,
			IMG_GLOBAL_PROGRESS,
			0);
		mmi_umms_entry_processing_generic();
		mmi_umms_set_current_profile_req();
	}
	else
	{
		mmi_umms_set_current_profile_req();
	}

}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_current_profile_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_current_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_profile_content_struct *profile_struct;
    wap_mma_set_profile_req_struct *set_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_struct = mmi_brw_prof_get_activated_mms_profile();

    set_profile = (wap_mma_set_profile_req_struct*) OslConstructDataPtr(sizeof(*set_profile));

    set_profile->req_id = wap_mma_get_request_id();
    set_profile->app_id = MMA_APP_ID_SETTING;
//    set_profile->connection_type = profile_struct->conn_type;
    set_profile->proxy_port = profile_struct->proxy_port;

	switch (profile_struct->conn_type)
	{
		case BRW_PROF_CONN_TYPE_HTTP:
			{
				set_profile->connection_type = MMA_CONN_TYPE_HTTP_PROXY;
				break;
			}

		case BRW_PROF_CONN_TYPE_CONNECTION_OREINTED:
			{
				/* if(9200) MMA_CONN_TYPE_WSP_CL; else if(9201) */
				set_profile->connection_type = MMA_CONN_TYPE_WSP_CO;
				break;
			}


		case BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
			{
				/*if(9202) MMA_CONN_TYPE_WSP_SEC_CL: else if(9203)*/
				set_profile->connection_type = MMA_CONN_TYPE_WSP_SEC_CO;
				break;
			}

	}
    set_profile->proxy_addr[0] = profile_struct->proxy_ip[0];
    set_profile->proxy_addr[1] = profile_struct->proxy_ip[1];
    set_profile->proxy_addr[2] = profile_struct->proxy_ip[2];
    set_profile->proxy_addr[3] = profile_struct->proxy_ip[3];

    mmi_asc_to_ucs2((S8*) set_profile->homepage_url, (S8*) profile_struct->url);
    mmi_asc_to_ucs2((S8*) set_profile->username, (S8*) profile_struct->username);
    mmi_asc_to_ucs2((S8*) set_profile->password, (S8*) profile_struct->password);

    set_profile->data_account = profile_struct->data_account_primary_id;

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SET_PROFILE_REQ, (oslParaType*) set_profile, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_current_profile_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  InMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_current_profile_rsp(void *InMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_profile_rsp_struct *set_profile_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_profile_rsp = (wap_mma_set_profile_rsp_struct*) InMsg;

    if (set_profile_rsp->result != MMA_RESULT_OK)
    {
		if(GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
		{
			DisplayPopup(
				(PU8) GetString(STR_GLOBAL_UNFINISHED),
				IMG_GLOBAL_UNFINISHED,
				1,
				MESSAGES_POPUP_TIME_OUT,
				(U8) ERROR_TONE);
			DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);		
    }
		return;
    }

	if(GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
	{

		mmi_umms_entry_dummy_screen();
		DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
		mmi_brw_prof_display_activation_popup();
		return;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_compose_image_view
 * DESCRIPTION
 *  custom fn for Auto sign Full screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_compose_image_view(void)
{

	FS_HANDLE fh = 0;

	fh = FS_Open((U16*)g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,FS_READ_ONLY);
	if (fh >= 0) /* file exists */
        {
            FS_Close(fh);

            EntryNewScreen(SCR_ID_UMMS_IMAGE_VIEW_IMAGE, NULL, mmi_umms_pre_entry_compose_image_view, NULL);


            
                ShowCategory222Screen(
					STR_ID_UMMS_SETTINGS_SIGNATURE,
					GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    GDI_COLOR_BLACK,
                    (PS8) NULL,
                    (PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
                    FALSE,
                    NULL,
                    GDI_IMAGE_SRC_FROM_FILE);
            

            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            /* SetGenericExitHandler(SCR_ID_PHB_IMAGE_VIEW_IMAGE, NULL, mmi_phb_image_view_from_phb_folder); */

            return;
      
    }
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_GLOBAL_NOT_AVAILABLE),
			IMG_GLOBAL_ERROR,
			FALSE,
			PHB_NOTIFY_TIMEOUT,
			ERROR_TONE);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_check_valid_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_umms_compose_image_check_valid_image(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U16 image_type;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    /* Check if image folder exists */
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
#endif
    /*
     * Check image content, check if the image header can be parsed correctly
     * Check image "size", "width", "height", value can be customize in file manage app.
     */
	if(mmi_ucs2strlen((S8*)path) > MMA_MAX_INTERNAL_FILENAME_LENGTH)
	{
        DisplayPopup((PU8) GetString(STR_ID_UMMS_SIGNATURE_PATH_TOO_LONG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return FALSE;
	}
    if (applib_get_file_size(path) > wap_custom_get_max_mms_msg_size())
    {
        DisplayPopup((PU8) GetString(STR_ID_UMMS_OPTIONS_MSG_SIZE_EXCEED), IMG_GLOBAL_UNFINISHED, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return FALSE;
    }
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
#endif
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_image_preview
 * DESCRIPTION
 *  setting image preview function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_image_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_UMMS_IMAGE_VIEW_IMAGE, NULL, mmi_umms_image_preview, NULL);

    /* entry cat222 to decode and display a image from file */

    ShowCategory222Screen(
        STR_ID_UMMS_SETTINGS_SIGNATURE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_BLACK,
        (PS8) NULL,
        (PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
        FALSE,
        mmi_umms_image_preview_callback,
        GDI_IMAGE_SRC_FROM_FILE);
    SetLeftSoftkeyFunction(mmi_umms_image_select_from_file_manager_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_preview_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_image_preview_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        /* delete to file select screen again */
        DeleteNHistory(1);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_image_select_from_file_manager_done
 * DESCRIPTION
 *  call back of select image from file manager.
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_image_select_from_file_manager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  g_phb_cntx.image_location = MMI_PHB_IMAGE_SELECT_PATH;
	g_compose_signature_done = E_ON;
//	mmi_ucs2cpy(g_umms_context->nvram_compose_settings.auto_signature_image_file, g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
    fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_make_file_name
 * DESCRIPTION
 *  Make file name with extension
 * PARAMETERS
 *  path            [IN]        File name.
 *  file_ext        [IN]        Extension
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_make_file_name(S8* file_name, S8* file_ext)
{
	S8 dot[] = {'.',0,0,0};
	S8 temp_ext[UMMS_SIGNATURE_EXT_LENGTH];

	if(file_ext != NULL)
	{
		mmi_ucs2cpy(temp_ext, dot);
		mmi_ucs2cat(temp_ext, file_ext);
		mmi_ucs2cat(file_name, temp_ext);
		return;
	}
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageSetting.c] mmi_umms_make_file_name :ext NULL");

}
#endif /* defined (__MMI_MMS_2__) && defined(MMS_SUPPORT) */ 


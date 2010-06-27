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
 *  JMMSMessageSettings.C
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
#ifndef _MMI_JMMSMMSSETTINGS_C
#define _MMI_JMMSMMSSETTINGS_C

/***************************************************************************** 
* Include
*****************************************************************************/

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "MainMenuDef.h"

#include "JMMSExdcl.h"
#include "JMMSStructs.h"

/* PMT DARA  PROFILE HANDLER 020106 */
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"

#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
/* /#include "JMMSGdcl.h" */
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "JMMSInbox.h"
#include "JMMSJSRHandler.h"
#include "JMMSMainMMS.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSOutbox.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSResDef.h"
#include "JMMSSent.h"
#include "JMMSStoreHandling.h"
#include "JMMSStructs.h"
#include "JMMSTemplates.h"
#include "JMMSUseDetails.h"
#include "JMMSView.h"
#include "JMMSWriteMMS.h"
#include "custom_wap_config.h"
#include "CallManagementGprot.h"
#include "PrvStoreDataTypes.h"
#include "PrvStoreHandleInterfaces.h"
#include "SimDetectionGprot.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

extern void set_leading_zero(U8 u8_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_messages_settings
 * DESCRIPTION
 *  This function is the highlight handler of message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_messages_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_message_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_message_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_message_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_message_settings_init
 * DESCRIPTION
 *  This function init the hilight handlers of message settings menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_message_settings_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mESSAGE sETTINGS options Highlight handlers */
    SetHiliteHandler(MENU_ID_JMMS_MMS_SETTINGS_COMPOSE, mmi_jmms_highlight_compose_setings);
    SetHiliteHandler(MENU_ID_JMMS_MMS_SETTINGS_SENDING, mmi_jmms_highlight_sending_setings);
    SetHiliteHandler(MENU_ID_JMMS_MMS_SETTINGS_RETRIEVAL, mmi_jmms_highlight_retrieval_setings);
    SetHiliteHandler(MENU_ID_JMMS_MMS_SETTINGS_EDIT_PROFILE, mmi_jmms_highlight_edit_profile);
    SetHiliteHandler(MENU_ID_JMMS_MMS_SETTINGS_MEMORY_STATUS, mmi_jmms_highlight_memory_status);

    mmi_jmms_read_nvram_message_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_message_settings
 * DESCRIPTION
 *  This function is the entry  handler of message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_message_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;                   /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_MESSAGE_SETTINGS, NULL, mmi_jmms_entry_message_settings, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_MESSAGE_SETTINGS);

    num_item = GetNumOfChild(MENU_ID_JMMS_MMS_SETTINGS);
    GetSequenceStringIds(MENU_ID_JMMS_MMS_SETTINGS, str_item_list);

    SetParentHandler(MENU_ID_JMMS_MMS_SETTINGS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_JMMS_MMS_SETTINGS,
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
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_compose_setings
 * DESCRIPTION
 *  This function is the highlight handler of compose message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_compose_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_compose_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_compose_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_compose_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_sending_setings
 * DESCRIPTION
 *  This function is the highlight handler of sending message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_sending_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_sending_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_sending_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_sending_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_retrieval_setings
 * DESCRIPTION
 *  This function is the highlight handler of retrieval message settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_retrieval_setings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_retrieval_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_retrieval_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_retrieval_settings, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_profile
 * DESCRIPTION
 *  This function is the highlight handler of edit profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* PMT DARA  PROFILE HANDLER 020106 */
    SetLeftSoftkeyFunction(mmi_jmms_show_profile_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_show_profile_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_show_profile_list, KEY_WAP, KEY_EVENT_DOWN);

}

/* PMT DARA  PROFILE HANDLER 020106 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_profile_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_profile_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ph_pre_entry_show_profile_list_menu(PH_MMS_PROFILE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_profile_title_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_jmms_get_profile_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    return (MENU_ID_UM_MAIN);
#else 
    return (MAIN_MENU_MESSAGES_MENUID);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_memory_status
 * DESCRIPTION
 *  This function is the highlight handler of memory sttaus item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_memory_status, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_memory_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_memory_status, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_memory_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if store is not ready do not try to create templates */
    mmi_jmms_entry_memory_status();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_memory_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS START 20060325 */
    U8 *gui_buffer_p;

    S8 temp_buf[20];
    S8 temp_buf_unicode[20 * ENCODING_LENGTH];
    S8 space_buf[20];
    U8 message_status_total;
    U8 message_status_used;
    int used_space = 0;
    U32 free_space;
    U32 size;
    S32 size_kb;
    S32 size_bytes;
    JDD_FSHANDLE fs_handle;
    JC_CHAR *content_fname_p = NULL;
    STORAGE_CTX *storage_handle_p = NULL;

    /* /manish incraesing size by 6(100 to 106) bytes as chnaging "Free" by "Free Space" */
    S8 memoryStatus[106 * ENCODING_LENGTH];

    U64 disk_free_space;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_entry_memory_status:%d", g_jmms_context->init_done);
    EntryNewScreen(SCR_ID_JMMS_MMS_MESSAGE_STATUS, NULL, mmi_jmms_entry_memory_status, NULL);
    message_status_total = MAX_POSSIBLE_MESSAGES;
    /* if JMMS_READY_WITHOUT_STORE it means @mms folder does not exists and message count is 0. */
    if (JMMS_READY_WITHOUT_STORE != g_jmms_context->init_done)
    {
        ret_code = mmi_jmms_get_total_number_of_messages(&message_status_used);
        if (ret_code != JC_OK)
        {
            message_status_used = 0;
        }
    }
    else
    {
        message_status_used = 0;
    }

    mmi_ucs2cpy(memoryStatus, (S8*) GetString(STR_ID_JMMS_SETTINGS_MESSAGE_STATUS_TOTAL));
    memset(space_buf, 0, 20);
    mmi_asc_to_ucs2(space_buf, ": ");
    mmi_ucs2cat(memoryStatus, space_buf);
    memset(space_buf, 0, 20);
    sprintf(temp_buf, "%d/%d", message_status_used, message_status_total);
    mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
    mmi_ucs2cat(memoryStatus, temp_buf_unicode);

    mmi_asc_to_ucs2(space_buf, "\n");
    mmi_ucs2cat(memoryStatus, space_buf);

    /* store_handle will be NULL in case of ready without store */
    if (g_jmms_context->store_handle)
    {
        storage_handle_p = (STORAGE_CTX*) g_jmms_context->store_handle;
        if ((jdd_FSInitialize(&fs_handle)) == JC_OK)
        {
            content_fname_p = (JC_CHAR*) jdd_FSFileNameTranslate(fs_handle, (JC_CHAR*) storage_handle_p->pRootPath);
            jdd_FSDeinitialize(fs_handle);
        }
        if (content_fname_p != NULL)
        {
            used_space = FS_GetFolderSize(content_fname_p, FS_COUNT_IN_BYTE, NULL, 0);
            jdd_MemFree(content_fname_p);
            if (used_space < 0)
            {
                used_space = 0;
            }
        }
    }
    mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_JMMS_SETTINGS_MESSAGE_STATUS_USAGE));
    memset(space_buf, 0, 20);
    mmi_asc_to_ucs2(space_buf, ": ");
    mmi_ucs2cat(memoryStatus, space_buf);
    memset(space_buf, 0, 20);

    /* Added a New line after "Used Space:" */
    mmi_asc_to_ucs2(space_buf, "\n");
    mmi_ucs2cat(memoryStatus, space_buf);
    memset(space_buf, 0, 20);

    memset(temp_buf, 0, 20);
    memset(temp_buf_unicode, 0, 20 * ENCODING_LENGTH);
    size = used_space;
    size_kb = size / 1024;
    size_bytes = size % 1024;

    if (size_kb >= 1)
    {
        if (size_bytes > 512)
        {
            size_kb++;
        }
        sprintf(temp_buf, "%d ", size_kb);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(memoryStatus, temp_buf_unicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_JMMS_KB));

    }
    else
    {
        sprintf(temp_buf, "%d ", size);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(memoryStatus, temp_buf_unicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_JMMS_BYTES));

    }

    disk_free_space = jdd_FSGetMMSFolderFreeSpace();
    /* mmi_jmms_get_free_size_for_mms(&disk_free_space); */
    mmi_asc_to_ucs2(space_buf, "\n");
    mmi_ucs2cat(memoryStatus, space_buf);
    mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_SETTINGS_FREE_SPACE));
    memset(space_buf, 0, 20);
    mmi_asc_to_ucs2(space_buf, ": ");
    mmi_ucs2cat(memoryStatus, space_buf);
    memset(space_buf, 0, 20);

    /* Added a New line after "Free Space:" */
    mmi_asc_to_ucs2(space_buf, "\n");
    mmi_ucs2cat(memoryStatus, space_buf);
    memset(space_buf, 0, 20);

    memset(temp_buf, 0, 20);
    memset(temp_buf_unicode, 0, 20 * ENCODING_LENGTH);
    free_space = disk_free_space;
    size = free_space;
    size_kb = size / 1024;
    size_bytes = size % 1024;
    if (size_kb >= 1)
    {
        if (size_bytes > 512)
        {
            size_kb++;
        }
        sprintf(temp_buf, "%d ", size_kb);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(memoryStatus, temp_buf_unicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_JMMS_KB));

    }
    else
    {
        sprintf(temp_buf, "%d ", size);
        mmi_asc_to_ucs2(temp_buf_unicode, temp_buf);
        mmi_ucs2cat(memoryStatus, temp_buf_unicode);
        mmi_ucs2cat(memoryStatus, (S8*) GetString(STR_ID_JMMS_BYTES));

    }
    memset(space_buf, 0, 20);
    memset(temp_buf, 0, 20);
    memset(temp_buf_unicode, 0, 20 * ENCODING_LENGTH);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_MMS_MESSAGE_STATUS);
    if ((gui_buffer_p != NULL) || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_ID_JMMS_MMS_MESSAGE_STATUS))
    {
        DeleteNScrId(SCR_ID_JMMS_MMS_MESSAGE_STATUS);
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_entry_memory_status: All is OK");

    SetMessagesCurrScrnID(SCR_ID_JMMS_MMS_MESSAGE_STATUS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_JMMS_MMS_MESSAGE_STATUS);

    ShowCategory74Screen(
        STR_ID_MESSAGE_SETTINGS_MEMORY_STATUS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) memoryStatus,
        mmi_ucs2strlen((const S8*)memoryStatus),
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* PMT VIKAS END 20060325 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_compose_settings
 * DESCRIPTION
 *  this is pre entry fn for compose settings. Init the inline items for compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_max_no_pages = g_jmms_context->nvram_compose_settings.max_no_pages;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(
        (S32) g_jmms_context->nvram_compose_settings.default_slide_time,
        (UI_string_type) g_jmms_context->jmms_inline_items.compose_items_list.defualt_slide_time_buffer,
        10);
#ifdef __DRM_SUPPORT__
    g_jmms_context->jmms_inline_items.compose_items_list.add_drm = g_jmms_context->nvram_compose_settings.add_drm;
#endif 
    // #ifdef __MMI_MMS_SIGNATURE__
    g_jmms_context->jmms_inline_items.compose_items_list.auto_signature =
        g_jmms_context->nvram_compose_settings.auto_signature;
    // #endif /* __MMI_MMS_SIGNATURE__ */
    g_jmms_context->jmms_inline_items.compose_items_list.best_page_duration =
        g_jmms_context->nvram_compose_settings.best_page_duration;
    g_jmms_context->jmms_inline_items.compose_items_list.creation_mode =
        g_jmms_context->nvram_compose_settings.creation_mode;
    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    g_jmms_context->jmms_inline_items.compose_items_list.image_resize_option =
        g_jmms_context->nvram_compose_settings.image_resize_option;
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */
    g_jmms_context->jmms_inline_items.compose_items_list.layout = g_jmms_context->nvram_compose_settings.layout;

    gui_itoa(
        temp_max_no_pages,
        (UI_string_type) g_jmms_context->jmms_inline_items.compose_items_list.max_num_pages_buffer,
        10);

    mmi_jmms_entry_compose_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_query_screen_to_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_query_screen_to_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_jmms_confirm_save_compose_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_jmms_exit_confirm_screen, KEY_EVENT_UP);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_read_back_auto_sign_content, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_setting_highlight_compose_option_edit_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_setting_highlight_compose_option_edit_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_query_screen_to_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_compose_settings
 * DESCRIPTION
 *  This is entry fn for compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;     /* added for inline edit history */
    U16 input_buffer_size;  /* added for inline edit history */
    U16 image_list[COMPOSE_INLINE_TOTAL] = {0};
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_COMPOSE_SETTINGS, mmi_jmms_exit_compose_settings, NULL, NULL);

    set_leading_zero(FALSE);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_COMPOSE_SETTINGS);

    InitializeCategory57Screen();

    mmi_jmms_compose_fill_inline_struct();
    /* RegisterHighlightHandler(ExecuteCurrHiliteHandler); */
    RegisterHighlightHandler(mmi_jmms_setting_highlight_compose_option_edit_inline_item);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_COMPOSE_SETTINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_COMPOSE_SETTINGS, &input_buffer_size);     /* added for inline edit history */

    if (input_buffer_p) /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, COMPOSE_INLINE_TOTAL, input_buffer_p);     /* sets the data */
    }

    image_list[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION] = gIndexIconsImageList[count];
#ifndef __MMI_UNIFIED_COMPOSER__
    image_list[E_COMPOSE_LAYOUT_CAPTION] = gIndexIconsImageList[++count];
#ifdef __DRM_SUPPORT__
    image_list[E_COMPOSE_ADD_DRM_CAPTION] = gIndexIconsImageList[++count];
#endif 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    image_list[E_COMPOSE_CREATION_MODES_CAPTION] = gIndexIconsImageList[++count];

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    image_list[E_COMPOSE_IMAGE_RESIZE_CAPTION] = gIndexIconsImageList[++count];
#endif /* #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__ */

#ifndef __MMI_UNIFIED_COMPOSER__
    image_list[E_COMPOSE_MAX_NO_PAGES_CAPTION] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_BEST_PAGE_DURATION_CAPTION] = gIndexIconsImageList[++count];
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    // #ifdef __MMI_MMS_SIGNATURE__
    image_list[E_COMPOSE_AUTO_SIGNATURE_CAPTION] = gIndexIconsImageList[++count];
    image_list[E_COMPOSE_AUTO_SIGNATURE_CONTENT] = IMG_ID_JMMS_WRITE_MESSAGE;
    // #endif /* __MMI_MMS_SIGNATURE__ */

    ShowCategory57Screen(
        STR_ID_MESSAGE_SETTINGS_COMPOSE,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        COMPOSE_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        gui_buffer_p);

    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_read_back_auto_sign_content, KEY_END, KEY_EVENT_DOWN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_compose_settings
 * DESCRIPTION
 *  It checks for default slide time value and auto sign (on/Off). If deafult slide time
 *  input 0 then error pop up. If auto sign is on buyt content is empty then also error pop up.
 *  If more than 20 slide then also error pop up.Otherwise  ask confirmation to save compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.compose_items_list.max_num_pages_buffer);
    //PMT VIKAS START 20060325
    //For empty value of slide time and no of slide field.  
    if (mmi_ucs2ncmp
        ((S8*) g_jmms_context->jmms_inline_items.compose_items_list.max_num_pages_buffer, "\0",
         1 * ENCODING_LENGTH) == 0)
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_PAGES_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    else if (mmi_ucs2ncmp
             ((S8*) g_jmms_context->jmms_inline_items.compose_items_list.defualt_slide_time_buffer, "\0",
              1 * ENCODING_LENGTH) == 0)
    {
        DisplayPopup((U8*) GetString(STR_ID_SLIDE_TIME_ZERO_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    else if (temp > MAX_POSSIBLE_SLIDES)
        /* PMT VIKAS END 20060325 */
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_PAGES_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    /* dilip 26 aug 2006 to prevent user from setting max page less than 1 */
    else if (temp < 1)
        /* PMT VIKAS END 20060325 */
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_PAGES_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    // #ifdef __MMI_MMS_SIGNATURE__
    else if ((g_jmms_context->jmms_inline_items.compose_items_list.auto_signature == E_ON)
             &&
             (mmi_ucs2ncmp
              ((S8*) g_jmms_context->nvram_compose_settings.auto_signature_content, "\0",
               MAX_AUTO_SIGN_LENGTH * ENCODING_LENGTH) == 0))
    {
        DisplayPopup((U8*) GetString(STR_ID_AUTO_SIGN_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    // #endif /* __MMI_MMS_SIGNATURE__ */
    else
    {
        mmi_jmms_save_compose_settings();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_confirm_screen
 * DESCRIPTION
 *  exit from the confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_compose_settings,
        NVRAM_JMMS_COMPOSE_SETTINGS_SIZE /* NVRAM_JMMS_COMPOSE_SETTINGS_SIZE */ ,
        &error);

    GoBacknHistory(1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_compose_settings
 * DESCRIPTION
 *  write the compose settings to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 temp_max_no_pages, error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* /write global struct into values into NVRAM */
    temp_max_no_pages = gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.compose_items_list.max_num_pages_buffer);
    g_jmms_context->nvram_compose_settings.default_slide_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.compose_items_list.defualt_slide_time_buffer);
    // #ifdef __MMI_MMS_SIGNATURE__
    g_jmms_context->nvram_compose_settings.auto_signature =
        g_jmms_context->jmms_inline_items.compose_items_list.auto_signature;
    // #endif /* __MMI_MMS_SIGNATURE__ */
    g_jmms_context->nvram_compose_settings.best_page_duration =
        g_jmms_context->jmms_inline_items.compose_items_list.best_page_duration;
    g_jmms_context->nvram_compose_settings.creation_mode =
        g_jmms_context->jmms_inline_items.compose_items_list.creation_mode;
    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    g_jmms_context->nvram_compose_settings.image_resize_option =
        g_jmms_context->jmms_inline_items.compose_items_list.image_resize_option;
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */
#ifdef __DRM_SUPPORT__
    g_jmms_context->nvram_compose_settings.add_drm = g_jmms_context->jmms_inline_items.compose_items_list.add_drm;
#endif 
    g_jmms_context->nvram_compose_settings.layout = g_jmms_context->jmms_inline_items.compose_items_list.layout;
    g_jmms_context->nvram_compose_settings.max_no_pages = (U8) temp_max_no_pages;

    WriteRecord(
        NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_compose_settings,
        NVRAM_JMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_JMMS_MESSAGE_SETTINGS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_read_back_auto_sign_content
 * DESCRIPTION
 *  Read the Compose setting from NVRAm for the auto sign content
 *  Read back is required because we are using the original auto sign buffer for input
 *  the auto sign content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_read_back_auto_sign_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_compose_settings,
        NVRAM_JMMS_COMPOSE_SETTINGS_SIZE /* NVRAM_JMMS_COMPOSE_SETTINGS_SIZE */ ,
        &error);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_inline_custom_func
 * DESCRIPTION
 *  custom fn for Auto sign Full screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_inline_custom_func(void)
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
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mmi_jmms_read_back_auto_sign_content, KEY_END, KEY_EVENT_DOWN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for compose settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_inline_lists == NULL)
    {
        g_jmms_context->jmms_inline_lists =
            (mmi_jmms_common_inline_lists_struct*) jdd_MemAlloc(sizeof(mmi_jmms_common_inline_lists_struct), 1);
        if (g_jmms_context->jmms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }
#ifndef __MMI_UNIFIED_COMPOSER__
    g_jmms_context->jmms_inline_items.compose_items_list.layout_list[0] = GetString(STR_ID_SETTINGS_POTRAIT);
    g_jmms_context->jmms_inline_items.compose_items_list.layout_list[1] = GetString(STR_ID_SETTINGS_LANDSCAPE);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    g_jmms_context->jmms_inline_lists->on_off_list[0] = GetString(STR_ID_SETTINGS_OFF);
    g_jmms_context->jmms_inline_lists->on_off_list[1] = GetString(STR_ID_SETTINGS_ON);

    g_jmms_context->jmms_inline_items.compose_items_list.creation_modes_list[E_CREAT_MODE_RESTRICTED] = GetString(STR_ID_SETTINGS_RESTRICTED);
#ifndef __MMI_UNIFIED_COMPOSER__
    g_jmms_context->jmms_inline_items.compose_items_list.creation_modes_list[E_CREAT_MODE_WARNING] = GetString(STR_ID_SETTINGS_WARNING);
#endif 
    g_jmms_context->jmms_inline_items.compose_items_list.creation_modes_list[E_CREAT_MODE_FREE] = GetString(STR_ID_SETTINGS_FREE);
    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    g_jmms_context->jmms_inline_items.compose_items_list.image_resize_list[0] = GetString(STR_ID_SETTINGS_OFF);
    g_jmms_context->jmms_inline_items.compose_items_list.image_resize_list[1] = GetString(STR_ID_SETTINGS_160_X_120);
    g_jmms_context->jmms_inline_items.compose_items_list.image_resize_list[2] = GetString(STR_ID_SETTINGS_320_X_240);
    g_jmms_context->jmms_inline_items.compose_items_list.image_resize_list[3] = GetString(STR_ID_SETTINGS_640_X_480);
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */

    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_DEFAULT_SLIDE_TIMING));
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_COMPOSE_DEFAULT_SLIDE_TIME],
        (U8*) g_jmms_context->jmms_inline_items.compose_items_list.defualt_slide_time_buffer,
        (MAX_DEFAULT_SLIDE_TIME_INPUT + 1),
        INPUT_TYPE_NUMERIC);

#ifndef __MMI_UNIFIED_COMPOSER__
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_LAYOUT_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_COMPOSE_LAYOUT_CAPTION], (U8*) GetString(STR_ID_SETTINGS_LAYOUT));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_LAYOUT],
        LAYOUT_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.compose_items_list.layout_list,
        &g_jmms_context->jmms_inline_items.compose_items_list.layout);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_LAYOUT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

#ifdef __DRM_SUPPORT__
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_ADD_DRM_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_COMPOSE_ADD_DRM_CAPTION], (U8*) GetString(STR_ID_SETTINGS_ADD_DRM));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_ADD_DRM],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.compose_items_list.add_drm);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_ADD_DRM], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif /* __DRM_SUPPORT__ */ 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_CREATION_MODES));
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_CREATION_MODES],
        CREATION_MODES_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.compose_items_list.creation_modes_list,
        &g_jmms_context->jmms_inline_items.compose_items_list.creation_mode);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_CREATION_MODES], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    /* PMT Umesh START - Added for Image resizing */
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZE_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_IMAGE_RESIZE));

    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_IMAGE_RESIZING], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_IMAGE_RESIZING],
        IMAGE_RESIZE_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.compose_items_list.image_resize_list,
        &g_jmms_context->jmms_inline_items.compose_items_list.image_resize_option);
    /* PMT Umesh END - Added for Image resizing */
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
#ifndef __MMI_UNIFIED_COMPOSER__
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_MAX_NO_PAGES_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_MAX_NO_PAGES_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_MAX_NUM_PAGES));
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_MAX_NO_PAGES], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_COMPOSE_MAX_NO_PAGES],
        (U8*) g_jmms_context->jmms_inline_items.compose_items_list.max_num_pages_buffer,
        (MAX_NO_PAGES_INPUT + 1),
        INPUT_TYPE_NUMERIC);

    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_BEST_PAGE_DURATION));

    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.compose_items_list.best_page_duration);
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_BEST_PAGE_DURATION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

    // #ifdef __MMI_MMS_SIGNATURE__
    SetInlineItemActivation(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_AUTO_SIGNATURE));

    SetInlineItemSelect(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.compose_items_list.auto_signature);
    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(&wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT],
        STR_ID_SETTINGS_EDIT_CONTENT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        (PU8) g_jmms_context->nvram_compose_settings.auto_signature_content,
        MAX_AUTO_SIGN_LENGTH + 1,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[E_COMPOSE_AUTO_SIGNATURE_CONTENT],
        mmi_jmms_compose_inline_custom_func);
    // #endif /* __MMI_MMS_SIGNATURE__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_compose_settings
 * DESCRIPTION
 *  Exit fn for compose settings screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 input_buffer_size;  /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_JMMS_COMPOSE_SETTINGS;
    history_buff.entryFuncPtr = mmi_jmms_entry_compose_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, input_buffer_size);       /* added for inline edit history */

    if (g_jmms_context->jmms_inline_lists != NULL)
    {
        jdd_MemFree(g_jmms_context->jmms_inline_lists);
        g_jmms_context->jmms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_sending_settings
 * DESCRIPTION
 *  pre entry fn for sending settings. Init the value of inline items for the screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(
        (S32) g_jmms_context->nvram_sending_settings.deadline_for_reply,
        (UI_string_type) g_jmms_context->jmms_inline_items.sending_items_list.deadline_for_reply_buffer,
        10);
    g_jmms_context->jmms_inline_items.sending_items_list.delivery_report =
        (S32) g_jmms_context->nvram_sending_settings.delivery_report;
    g_jmms_context->jmms_inline_items.sending_items_list.delivery_time =
        (S32) g_jmms_context->nvram_sending_settings.delivery_time;
    g_jmms_context->jmms_inline_items.sending_items_list.hide_sender =
        (S32) g_jmms_context->nvram_sending_settings.hide_sender;
    g_jmms_context->jmms_inline_items.sending_items_list.priority =
        (S32) g_jmms_context->nvram_sending_settings.priority;
    g_jmms_context->jmms_inline_items.sending_items_list.read_report =
        (S32) g_jmms_context->nvram_sending_settings.read_report;
    g_jmms_context->jmms_inline_items.sending_items_list.reply_charging =
        (S32) g_jmms_context->nvram_sending_settings.reply_charging;
    g_jmms_context->jmms_inline_items.sending_items_list.request_type =
        (S32) g_jmms_context->nvram_sending_settings.request_type;
    g_jmms_context->jmms_inline_items.sending_items_list.validity_period =
        (S32) g_jmms_context->nvram_sending_settings.validity_period;
    gui_itoa(
        (S32) g_jmms_context->nvram_sending_settings.size,
        (UI_string_type) g_jmms_context->jmms_inline_items.sending_items_list.reply_msg_size_buffer,
        10);

    mmi_jmms_check_sending_settings_control(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_sending_settings_control
 * DESCRIPTION
 *  Pre entry fn for sending settings.It check from where the this screen will be opened i.e. from Send Options
 *  during writins MMS or from Message Settings itself
 * PARAMETERS
 *  control     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_check_sending_settings_control(U8 control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control == 2)   /* /control from send options during writing mms */
    {
        g_jmms_context->g_jmms_control = E_ENTRY_FROM_WRITE_MMS;
    }
    else
    {
        g_jmms_context->g_jmms_control = E_ENTRY_FROM_MMS_SETTINGS;
    }

    g_jmms_context->g_reply_charging_done = 0;
    mmi_jmms_entry_sending_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_sending_settings
 * DESCRIPTION
 *  Entry fn for sendin settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;     /* added for inline edit history */
    U16 input_buffer_size;  /* added for inline edit history */
    U16 image_list[SENDING_INLINE_TOTAL] = {0};
    U16 strid = STR_ID_MESSAGE_SETTINGS_SENDING;
    extern U8 global_mms_version;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_SENDING_SETTINGS, mmi_jmms_exit_sending_settings, NULL, NULL);

    set_leading_zero(FALSE);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SENDING_SETTINGS);

    InitializeCategory57Screen();

    mmi_jmms_sending_fill_inline_struct();
    RegisterHighlightHandler(mmi_jmms_sending_settings_highlight_hdlr);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SENDING_SETTINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_SENDING_SETTINGS, &input_buffer_size);     /* added for inline edit history */

    if (input_buffer_p) /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, SENDING_INLINE_TOTAL, input_buffer_p);     /* sets the data */
    }
    if (global_mms_version > 1)
    {
        image_list[E_SENDING_VALIDITY_PERIOD_CAPTION] = gIndexIconsImageList[0];
        image_list[E_SENDING_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[1];
        image_list[E_SENDING_READ_REPORT_CAPTION] = gIndexIconsImageList[2];
        image_list[E_SENDING_PRIORITY_CAPTION] = gIndexIconsImageList[3];
        image_list[E_SENDING_DELIVERY_TIME_CAPTION] = gIndexIconsImageList[4];
        image_list[E_SENDING_REPLY_CHARGING_CAPTION] = gIndexIconsImageList[6];
    #ifndef __MMI_UNIFIED_COMPOSER__
        image_list[E_SENDING_HIDE_SENDER_CAPTION] = gIndexIconsImageList[5];
    #endif 
    }
    else
    {
        image_list[E_SENDING_VALIDITY_PERIOD_CAPTION] = gIndexIconsImageList[0];
        image_list[E_SENDING_DELIVERY_REPORT_CAPTION] = gIndexIconsImageList[1];
        image_list[E_SENDING_READ_REPORT_CAPTION] = gIndexIconsImageList[2];
        image_list[E_SENDING_PRIORITY_CAPTION] = gIndexIconsImageList[3];
        image_list[E_SENDING_DELIVERY_TIME_CAPTION] = gIndexIconsImageList[4];
        /* image_list[E_SENDING_REPLY_CHARGING_CAPTION] = gIndexIconsImageList[5]; */
    #ifndef __MMI_UNIFIED_COMPOSER__
        image_list[E_SENDING_HIDE_SENDER_CAPTION] = gIndexIconsImageList[5];
    #endif 
    }

    if (g_jmms_context->g_jmms_control == E_ENTRY_FROM_WRITE_MMS)
    {
        strid = STR_ID_JMMS_WRITE_MMS_SEND_OPTIONS;
    }
    if (global_mms_version > 1)
    {
        ShowCategory57Screen(
            strid,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SENDING_INLINE_TOTAL,
            image_list,
            wgui_inline_items,
            0,
            gui_buffer_p);
    }
    else
    {
        ShowCategory57Screen(
            strid,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            SENDING_INLINE_TOTAL - 2,
            image_list,
            wgui_inline_items,
            0,
            gui_buffer_p);
    }

    SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_sending_settings, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_sending_settings
 * DESCRIPTION
 *  Ask for the confirmation for saving sending settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_sending_settings(void)
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

    SetLeftSoftkeyFunction(mmi_jmms_save_sending_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_jmms_exit_confirm_screen, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_sending_settings
 * DESCRIPTION
 *  save the send settings into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_jmms_control == E_ENTRY_FROM_MMS_SETTINGS)
    {
        /* /write global struct into values into NVRAM */
        g_jmms_context->nvram_sending_settings.delivery_report =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.delivery_report;
        g_jmms_context->nvram_sending_settings.delivery_time =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.delivery_time;
        g_jmms_context->nvram_sending_settings.hide_sender =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.hide_sender;
        g_jmms_context->nvram_sending_settings.priority =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.priority;
        g_jmms_context->nvram_sending_settings.read_report =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.read_report;
        g_jmms_context->nvram_sending_settings.reply_charging =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.reply_charging;
        g_jmms_context->nvram_sending_settings.request_type =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.request_type;
        g_jmms_context->nvram_sending_settings.validity_period =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.validity_period;
        g_jmms_context->nvram_sending_settings.deadline_for_reply =
            (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.sending_items_list.
                           deadline_for_reply_buffer);
        g_jmms_context->nvram_sending_settings.size =
            (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.sending_items_list.reply_msg_size_buffer);

        WriteRecord(
            NVRAM_EF_JMMS_SENDING_SETTINGS_LID,
            1,
            &g_jmms_context->nvram_sending_settings,
            NVRAM_JMMS_SENDING_SETTINGS_SIZE,
            &error);
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_MESSAGE_SETTINGS);
    }
    else if (g_jmms_context->g_jmms_control == E_ENTRY_FROM_WRITE_MMS)
    {
        /* MAUI_00227929 Start */
        g_jmms_context->sending_settings.delivery_report =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.delivery_report;
        g_jmms_context->sending_settings.delivery_time =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.delivery_time;
        g_jmms_context->sending_settings.hide_sender =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.hide_sender;
        g_jmms_context->sending_settings.priority = (U8) g_jmms_context->jmms_inline_items.sending_items_list.priority;
        g_jmms_context->sending_settings.read_report =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.read_report;
        g_jmms_context->sending_settings.reply_charging =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.reply_charging;
        g_jmms_context->sending_settings.request_type =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.request_type;
        g_jmms_context->sending_settings.validity_period =
            (U8) g_jmms_context->jmms_inline_items.sending_items_list.validity_period;
        strcpy(
            (S8*) g_jmms_context->sending_settings.deadline_for_reply_buffer,
            (S8*) g_jmms_context->jmms_inline_items.sending_items_list.deadline_for_reply_buffer);

        strcpy(
            (S8*) g_jmms_context->sending_settings.reply_msg_size_buffer,
            (S8*) g_jmms_context->jmms_inline_items.sending_items_list.reply_msg_size_buffer);
        /* MAUI_00227929 End */

        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        g_jmms_context->g_use_local_send_setings = 1;
        DeleteUptoScrID(SCR_ID_WRITE_MMS_DONE_OPTIONS);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_fill_inline_struct
 * DESCRIPTION
 *  Fill the inline struct for send settings screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_sending_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern U8 global_mms_version;

    if (g_jmms_context->jmms_inline_lists == NULL)
    {
        g_jmms_context->jmms_inline_lists =
            (mmi_jmms_common_inline_lists_struct*) jdd_MemAlloc(sizeof(mmi_jmms_common_inline_lists_struct), 1);
        if (g_jmms_context->jmms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }

    g_jmms_context->jmms_inline_items.sending_items_list.validity_period_list[0] = GetString(STR_ID_JMMS_MAXIMUM);
    g_jmms_context->jmms_inline_items.sending_items_list.validity_period_list[1] = GetString(STR_ID_SETTINGS_1_HR);
    g_jmms_context->jmms_inline_items.sending_items_list.validity_period_list[2] = GetString(STR_ID_SETTINGS_12_HRS);
    g_jmms_context->jmms_inline_items.sending_items_list.validity_period_list[3] = GetString(STR_ID_SETTINGS_1_DAY);
    g_jmms_context->jmms_inline_items.sending_items_list.validity_period_list[4] = GetString(STR_ID_SETTINGS_1_WEEK);

    g_jmms_context->jmms_inline_lists->on_off_list[0] = GetString(STR_ID_SETTINGS_OFF);
    g_jmms_context->jmms_inline_lists->on_off_list[1] = GetString(STR_ID_SETTINGS_ON);

    g_jmms_context->jmms_inline_items.sending_items_list.priority_list[0] = GetString(STR_ID_SETTINGS_LOW);
    g_jmms_context->jmms_inline_items.sending_items_list.priority_list[1] = GetString(STR_GLOBAL_NORMAL);
    g_jmms_context->jmms_inline_items.sending_items_list.priority_list[2] = GetString(STR_ID_SETTINGS_HIGH);

    g_jmms_context->jmms_inline_items.sending_items_list.delivery_time_list[0] = GetString(STR_ID_SETTINGS_IMMEDIATE);
    g_jmms_context->jmms_inline_items.sending_items_list.delivery_time_list[1] = GetString(STR_ID_SETTINGS_1_HR);
    g_jmms_context->jmms_inline_items.sending_items_list.delivery_time_list[2] = GetString(STR_ID_SETTINGS_12_HRS);
    g_jmms_context->jmms_inline_items.sending_items_list.delivery_time_list[3] = GetString(STR_ID_SETTINGS_24_HRS);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_VALIDITY_PERIOD));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_VALIDITY_PERIOD],
        VALIDITY_PERIOD_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.sending_items_list.validity_period_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.validity_period);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_VALIDITY_PERIOD], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT_CAPTION],
        (U8*) GetString(STR_ID_JMMS_DELIVERY_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_DELIVERY_REPORT],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.delivery_report);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_DELIVERY_REPORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_READ_REPORT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_READ_REPORT_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_READ_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_READ_REPORT],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.read_report);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_READ_REPORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(&wgui_inline_items[E_SENDING_PRIORITY_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[E_SENDING_PRIORITY_CAPTION], (U8*) GetString(STR_ID_SETTINGS_PRIORITY));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_PRIORITY],
        PRIORITY_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.sending_items_list.priority_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.priority);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_PRIORITY], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_DELIVERY_TIME));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_DELIVERY_TIME],
        DELIEVERY_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.sending_items_list.delivery_time_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.delivery_time);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_DELIVERY_TIME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

#ifndef __MMI_UNIFIED_COMPOSER__
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_HIDE_SENDER_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_HIDE_SENDER_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_HIDE_SENDER));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_HIDE_SENDER],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.hide_sender);
    SetInlineItemActivation(&wgui_inline_items[E_SENDING_HIDE_SENDER], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    if (global_mms_version > 1)
    {
        SetInlineItemActivation(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING_CAPTION],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        SetInlineItemCaption(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING_CAPTION],
            (U8*) GetString(STR_ID_SETTINGS_REPLY_CHARGING));
        SetInlineItemSelect(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING],
            2,
            (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
            &g_jmms_context->jmms_inline_items.sending_items_list.reply_charging);
        SetInlineItemActivation(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);
        RegisterInlineSelectHighlightHandler(
            &wgui_inline_items[E_SENDING_REPLY_CHARGING],
            mmi_jmms_reply_charging_highlight_hdlr);
    }
    /* end */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_sending_settings
 * DESCRIPTION
 *  Exit fn for the send setting screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 input_buffer_size;  /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_JMMS_SENDING_SETTINGS;
    history_buff.entryFuncPtr = mmi_jmms_entry_sending_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, input_buffer_size);       /* added for inline edit history */

    if (g_jmms_context->jmms_inline_lists != NULL)
    {
        jdd_MemFree(g_jmms_context->jmms_inline_lists);
        g_jmms_context->jmms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_reply_charging_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler fro reply charging inline item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_reply_charging_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_reply_charging_done == 1)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_jmms_confirm_save_sending_settings, KEY_EVENT_UP);
    }
    if (index == E_ON)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_jmms_pre_entry_sending_reply_charging_settings, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_sending_reply_charging_settings
 * DESCRIPTION
 *  Entry fn for the Reply charging settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_sending_reply_charging_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p;
    U8 *input_buffer_p;     /* added for inline edit history */
    U16 input_buffer_size;  /* added for inline edit history */
    U16 image_list[SENDING_REPLY_CHARGING_INLINE_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_SENDING_SETTINGS, mmi_jmms_exit_sending_reply_charging_settings, NULL, NULL);

    set_leading_zero(FALSE);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SENDING_REPLY_CHARGING_SETTINGS);

    InitializeCategory57Screen();

    mmi_jmms_sending_reply_charging_fill_inline_struct();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SENDING_REPLY_CHARGING_SETTINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_SENDING_REPLY_CHARGING_SETTINGS, &input_buffer_size);      /* added for inline edit history */

    if (input_buffer_p) /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, SENDING_REPLY_CHARGING_INLINE_TOTAL, input_buffer_p);      /* sets the data */
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
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_jmms_sending_reply_charging_settings_done, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_reply_charging_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for reply charging settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_sending_reply_charging_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->jmms_inline_items.sending_items_list.reply_charging_request_list[0] = GetString(STR_ID_SETTINGS_REQUEST_TYPE_FULL_MMS);
    g_jmms_context->jmms_inline_items.sending_items_list.reply_charging_request_list[1] = GetString(STR_ID_SETTINGS_REQUEST_TYPE_ONLY_TEXT);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_REQUEST_TYPE));
    SetInlineItemSelect(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_REQUEST_TYPE],
        2,
        (U8 **) g_jmms_context->jmms_inline_items.sending_items_list.reply_charging_request_list,
        &g_jmms_context->jmms_inline_items.sending_items_list.request_type);
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
        (U8*) GetString(STR_ID_SETTINGS_REPLY_DEADLINE));
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_DEADLINE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_DEADLINE],
        (U8*) g_jmms_context->jmms_inline_items.sending_items_list.deadline_for_reply_buffer,
        (MAX_DEADLINE_TIME_VALUE_INPUT + 1),
        INPUT_TYPE_NUMERIC);

    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_REPLY_CHARGE_SIZE));
    SetInlineItemActivation(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_SENDING_REPLY_CHARGING_SIZE],
        (U8*) g_jmms_context->jmms_inline_items.sending_items_list.reply_msg_size_buffer,
        (MAX_REPLY_CHARGE_SIZE_INPUT + 1),
        INPUT_TYPE_NUMERIC);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_sending_reply_charging_settings
 * DESCRIPTION
 *  Exit fn for reply charging setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_sending_reply_charging_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 input_buffer_size;  /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_JMMS_SENDING_REPLY_CHARGING_SETTINGS;
    history_buff.entryFuncPtr = mmi_jmms_entry_sending_reply_charging_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, input_buffer_size);       /* added for inline edit history */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_retrieval_settings
 * DESCRIPTION
 *  Pre Entry fn for retrieval setting screeen.It init the retreival inline items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->jmms_inline_items.retrieval_items_list.advertisement_filter =
        (S32) g_jmms_context->nvram_retrieval_settings.advertisement_filter;
    g_jmms_context->jmms_inline_items.retrieval_items_list.anonymous_filter =
        (S32) g_jmms_context->nvram_retrieval_settings.anonymous_filter;
    g_jmms_context->jmms_inline_items.retrieval_items_list.delivery_report =
        (S32) g_jmms_context->nvram_retrieval_settings.delivery_report;
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    if (g_jmms_context->nvram_retrieval_settings.home_network == (U8) E_HOME_NOETWORK_RETRIEVAL_RESTRICTED)
    {
        g_jmms_context->jmms_inline_items.retrieval_items_list.home_network =
            (U8) E_HOME_NOETWORK_RETRIEVAL_DEFFERED - 1;
    }
    else
#endif /* __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__ */ 
        g_jmms_context->jmms_inline_items.retrieval_items_list.home_network =
            (S32) g_jmms_context->nvram_retrieval_settings.home_network - 1;
    g_jmms_context->jmms_inline_items.retrieval_items_list.read_report =
        (S32) g_jmms_context->nvram_retrieval_settings.read_report;
    g_jmms_context->jmms_inline_items.retrieval_items_list.roaming =
        (S32) g_jmms_context->nvram_retrieval_settings.roaming;
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__
    gui_itoa(
        (S32) g_jmms_context->nvram_retrieval_settings.msgsize_filter,
        (UI_string_type) g_jmms_context->jmms_inline_items.retrieval_items_list.msg_size_filter_buffer,
        10);
#endif /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ 
    g_jmms_context->g_recieve_filter_done = 0;
    mmi_jmms_entry_retrieval_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_retrieval_settings
 * DESCRIPTION
 *  Entry fn for retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;     /* added for inline edit history */
    U16 input_buffer_size;  /* added for inline edit history */
    U16 image_list[RETRIEVAL_INLINE_TOTAL] = {0};
    U32 total_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_RETRIEVAL_SETTINGS, mmi_jmms_exit_retrieval_settings, NULL, NULL);

    set_leading_zero(FALSE);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_RETRIEVAL_SETTINGS);

    InitializeCategory57Screen();

    total_items = mmi_jmms_retrieval_fill_inline_struct(image_list);
    RegisterHighlightHandler(mmi_jmms_retrieval_settings_highlight_hdlr);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_RETRIEVAL_SETTINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_RETRIEVAL_SETTINGS, &input_buffer_size);   /* added for inline edit history */

    if (input_buffer_p) /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, RETRIEVAL_INLINE_TOTAL, input_buffer_p);   /* sets the data */
    }

    ShowCategory57Screen(
        STR_ID_MESSAGE_SETTINGS_RETRIEVAL,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        total_items,
        image_list,
        wgui_inline_items,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_retrieval_settings, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_retrieval_settings
 * DESCRIPTION
 *  Confirmation screen entry fn for saving retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_retrieval_settings(void)
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

    SetLeftSoftkeyFunction(mmi_jmms_save_retrieval_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_jmms_exit_confirm_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_retrieval_settings
 * DESCRIPTION
 *  write the retrieval settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__
    S32 temp_msg_size_filter_value;
#endif 
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->nvram_retrieval_settings.advertisement_filter =
        (U8) g_jmms_context->jmms_inline_items.retrieval_items_list.advertisement_filter;
    g_jmms_context->nvram_retrieval_settings.anonymous_filter =
        (U8) g_jmms_context->jmms_inline_items.retrieval_items_list.anonymous_filter;
    g_jmms_context->nvram_retrieval_settings.delivery_report =
        (U8) g_jmms_context->jmms_inline_items.retrieval_items_list.delivery_report;
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    if (g_jmms_context->jmms_inline_items.retrieval_items_list.home_network + 1 ==
        (U8) E_HOME_NOETWORK_RETRIEVAL_DEFFERED)
    {
        g_jmms_context->nvram_retrieval_settings.home_network = (U8) E_HOME_NOETWORK_RETRIEVAL_RESTRICTED;
    }
    else
#endif /* __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__ */ 
        g_jmms_context->nvram_retrieval_settings.home_network =
            (U8) g_jmms_context->jmms_inline_items.retrieval_items_list.home_network + 1;
    g_jmms_context->nvram_retrieval_settings.read_report =
        (U8) g_jmms_context->jmms_inline_items.retrieval_items_list.read_report;
    g_jmms_context->nvram_retrieval_settings.roaming =
        (U8) g_jmms_context->jmms_inline_items.retrieval_items_list.roaming;
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__
    temp_msg_size_filter_value = gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.retrieval_items_list.msg_size_filter_buffer);
    g_jmms_context->nvram_retrieval_settings.msgsize_filter = (U16) temp_msg_size_filter_value;
#endif /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ 
    WriteValue(NVRAM_JMMS_RETRIEVAL_SETTINGS, &g_jmms_context->nvram_retrieval_settings, DS_DOUBLE, &error);

    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_JMMS_MESSAGE_SETTINGS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline items for retrieval settings screen
 * PARAMETERS
 *  image_list      [IN]
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_jmms_retrieval_fill_inline_struct(U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_index = 0;
    U32 icon_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_inline_lists == NULL)
    {
        g_jmms_context->jmms_inline_lists =
            (mmi_jmms_common_inline_lists_struct*) jdd_MemAlloc(sizeof(mmi_jmms_common_inline_lists_struct), 1);
        if (g_jmms_context->jmms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return 0;
        }

    }
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    g_jmms_context->jmms_inline_items.retrieval_items_list.home_network_list[0] = GetString(STR_GLOBAL_YES);
    g_jmms_context->jmms_inline_items.retrieval_items_list.home_network_list[1] = GetString(STR_GLOBAL_NO);
#else /* __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__ */ 
    g_jmms_context->jmms_inline_items.retrieval_items_list.home_network_list[0] = GetString(STR_ID_SETTINGS_IMMEDIATE);
    g_jmms_context->jmms_inline_items.retrieval_items_list.home_network_list[1] = GetString(STR_ID_SETTINGS_DEFFERED);
    g_jmms_context->jmms_inline_items.retrieval_items_list.home_network_list[2] = GetString(STR_ID_SETTINGS_REJECT);
#endif /* __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__ */ 
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    if (mmi_bootup_is_roaming() == MMI_TRUE)
#endif 
    {
        g_jmms_context->jmms_inline_items.retrieval_items_list.roaming_list[0] = GetString(STR_ID_SETTINGS_AS_HOME);
        g_jmms_context->jmms_inline_items.retrieval_items_list.roaming_list[1] = GetString(STR_ID_SETTINGS_IMMEDIATE);
        g_jmms_context->jmms_inline_items.retrieval_items_list.roaming_list[2] = GetString(STR_ID_SETTINGS_DEFFERED);
        g_jmms_context->jmms_inline_items.retrieval_items_list.roaming_list[3] = GetString(STR_ID_SETTINGS_REJECT);
    }

    g_jmms_context->jmms_inline_items.retrieval_items_list.read_report_list[0] = GetString(STR_ID_SETTINGS_ON_REQUEST);
    g_jmms_context->jmms_inline_items.retrieval_items_list.read_report_list[1] = GetString(STR_ID_SETTINGS_SEND);
    g_jmms_context->jmms_inline_items.retrieval_items_list.read_report_list[2] = GetString(STR_ID_SETTINGS_NEVER_SEND);

    g_jmms_context->jmms_inline_lists->on_off_list[0] = GetString(STR_ID_SETTINGS_OFF);
    g_jmms_context->jmms_inline_lists->on_off_list[1] = GetString(STR_ID_SETTINGS_ON);

    SetInlineItemActivation(&wgui_inline_items[curr_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    image_list[curr_index] = gIndexIconsImageList[icon_index++];
    SetInlineItemCaption(&wgui_inline_items[curr_index++], (U8*) GetString(STR_ID_SETTINGS_HOME_NETWORK));
    SetInlineItemSelect(&wgui_inline_items[curr_index],
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
                        HOME_NETWORK_TOTAL - 2,
#else 
                        HOME_NETWORK_TOTAL - 1,
#endif 
                        (U8 **) g_jmms_context->jmms_inline_items.retrieval_items_list.home_network_list,
                        &g_jmms_context->jmms_inline_items.retrieval_items_list.home_network);
    SetInlineItemActivation(&wgui_inline_items[curr_index++], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    if (mmi_bootup_is_roaming() == MMI_TRUE)
#endif 
    {
        SetInlineItemActivation(&wgui_inline_items[curr_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        image_list[curr_index] = gIndexIconsImageList[icon_index++];
        SetInlineItemCaption(&wgui_inline_items[curr_index++], (U8*) GetString(STR_ID_SETTINGS_ROAMING));
        SetInlineItemSelect(
            &wgui_inline_items[curr_index],
            ROAMING_TOTAL,
            (U8 **) g_jmms_context->jmms_inline_items.retrieval_items_list.roaming_list,
            &g_jmms_context->jmms_inline_items.retrieval_items_list.roaming);
        SetInlineItemActivation(&wgui_inline_items[curr_index++], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    }
    SetInlineItemActivation(&wgui_inline_items[curr_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    image_list[curr_index] = gIndexIconsImageList[icon_index++];
    SetInlineItemDisplayOnly(&wgui_inline_items[curr_index++], (U8*) GetString(STR_ID_SETTINGS_FILTERS));

    SetInlineItemActivation(&wgui_inline_items[curr_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    image_list[curr_index] = gIndexIconsImageList[icon_index++];
    SetInlineItemCaption(&wgui_inline_items[curr_index++], (U8*) GetString(STR_ID_SETTINGS_READ_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[curr_index],
        READ_REPORT_SEND_TOTAL,
        (U8 **) g_jmms_context->jmms_inline_items.retrieval_items_list.read_report_list,
        &g_jmms_context->jmms_inline_items.retrieval_items_list.read_report);
    SetInlineItemActivation(&wgui_inline_items[curr_index++], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemActivation(&wgui_inline_items[curr_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    image_list[curr_index] = gIndexIconsImageList[icon_index++];
    SetInlineItemCaption(&wgui_inline_items[curr_index++], (U8*) GetString(STR_ID_JMMS_DELIVERY_REPORT));
    SetInlineItemSelect(
        &wgui_inline_items[curr_index],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        &g_jmms_context->jmms_inline_items.retrieval_items_list.delivery_report);
    SetInlineItemActivation(&wgui_inline_items[curr_index++], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    return curr_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_retrieval_settings
 * DESCRIPTION
 *  Exit fn for the retrieval setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 input_buffer_size;  /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_JMMS_RETRIEVAL_SETTINGS;
    history_buff.entryFuncPtr = mmi_jmms_entry_retrieval_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, input_buffer_size);       /* added for inline edit history */

    if (g_jmms_context->jmms_inline_lists != NULL)
    {
        jdd_MemFree(g_jmms_context->jmms_inline_lists);
        g_jmms_context->jmms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_settings_highlight_hdlr
 * DESCRIPTION
 *  Highligh handler of retrieval settings screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_retrieval_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    if (mmi_bootup_is_roaming() != MMI_TRUE)
    {
        if (index == E_RETRIEVAL_FILTERS_CAPTION - 2)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_jmms_entry_retrieval_filters_settings, KEY_EVENT_UP);
        }
    }
    else
#endif /* __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__ */ 
    if (index == E_RETRIEVAL_FILTERS_CAPTION)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_jmms_entry_retrieval_filters_settings, KEY_EVENT_UP);
    }
    if (g_jmms_context->g_recieve_filter_done == 1)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_jmms_confirm_save_retrieval_settings, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_retrieval_filters_settings
 * DESCRIPTION
 *  Entry fn for filter settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_retrieval_filters_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;     /* added for inline edit history */
    U16 input_buffer_size;  /* added for inline edit history */
    U16 image_list[RETRIEVAL_FILTER_INLINE_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_RETRIEVAL_FILTERS_SETTINGS, mmi_jmms_exit_retrieval_filters_settings, NULL, NULL);

    set_leading_zero(FALSE);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_RETRIEVAL_FILTERS_SETTINGS);

    InitializeCategory57Screen();

    mmi_jmms_retrieval_filters_fill_inline_struct();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_RETRIEVAL_FILTERS_SETTINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_RETRIEVAL_FILTERS_SETTINGS, &input_buffer_size);   /* added for inline edit history */

    if (input_buffer_p) /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, RETRIEVAL_FILTER_INLINE_TOTAL, input_buffer_p);    /* sets the data */
    }

    image_list[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION] = gIndexIconsImageList[0];
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__
    image_list[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION] = gIndexIconsImageList[1];
    image_list[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION] = gIndexIconsImageList[2];
#else /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ 
    image_list[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION] = gIndexIconsImageList[1];
#endif /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ /* __MMI_JMMS_NO_OMA_CONF_273__ */
    ShowCategory57Screen(
        STR_ID_SETTINGS_FILTERS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        RETRIEVAL_FILTER_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_jmms_filter_done_handler, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_filter_done_handler
 * DESCRIPTION
 *  Done handler of filter screen. it checks that msg size input is not > 148KB and not empty.or 0.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_filter_done_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__

    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.retrieval_items_list.msg_size_filter_buffer);

    if ((temp > MAX_MMS_MSG_SIZE / 1024)
        || (g_jmms_context->jmms_inline_items.retrieval_items_list.msg_size_filter_buffer[0] == 48)
        ||
        (mmi_ucs2ncmp
         ((S8*) g_jmms_context->jmms_inline_items.retrieval_items_list.msg_size_filter_buffer, "\0",
          MAX_FILTER_MSG_SIZE_INPUT * ENCODING_LENGTH) == 0))
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_MSG_SIZE_LIMT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    else
#endif /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ 
    {
        g_jmms_context->g_recieve_filter_done = 1;
        GoBackHistory();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_retrieval_filters_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline sttruct for filter settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_retrieval_filters_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_inline_lists == NULL)
    {
        g_jmms_context->jmms_inline_lists =
            (mmi_jmms_common_inline_lists_struct*) jdd_MemAlloc(sizeof(mmi_jmms_common_inline_lists_struct), 1);
        if (g_jmms_context->jmms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }
    g_jmms_context->jmms_inline_lists->allow_reject_list[0] = GetString(STR_ID_SETTINGS_ALLOW);
    g_jmms_context->jmms_inline_lists->allow_reject_list[1] = GetString(STR_ID_SETTINGS_REJECT);

    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_ANNONYMOUS));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->allow_reject_list,
        &g_jmms_context->jmms_inline_items.retrieval_items_list.anonymous_filter);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ANONYMOUS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_MAX_MSG_SIZE));
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_MAX_MSG_SIZE],
        (U8*) g_jmms_context->jmms_inline_items.retrieval_items_list.msg_size_filter_buffer,
        (MAX_FILTER_MSG_SIZE_INPUT + 1),
        INPUT_TYPE_NUMERIC);
#endif /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ 
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION],
        (U8*) GetString(STR_ID_SETTINGS_ADVERTISMENT));
    SetInlineItemSelect(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->allow_reject_list,
        &g_jmms_context->jmms_inline_items.retrieval_items_list.advertisement_filter);
    SetInlineItemActivation(
        &wgui_inline_items[E_RETRIEVAL_FILTERS_ADVERTISEMENT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_retrieval_filters_settings
 * DESCRIPTION
 *  Exit fn for filter settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_retrieval_filters_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history history_buff;
    U16 input_buffer_size;  /* added for inline edit history */
    S16 nhistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    history_buff.scrnID = SCR_ID_JMMS_RETRIEVAL_FILTERS_SETTINGS;
    history_buff.entryFuncPtr = mmi_jmms_entry_retrieval_filters_settings;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, input_buffer_size);       /* added for inline edit history */

    if (g_jmms_context->jmms_inline_lists != NULL)
    {
        jdd_MemFree(g_jmms_context->jmms_inline_lists);
        g_jmms_context->jmms_inline_lists = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_read_nvram_message_settings
 * DESCRIPTION
 *  Read the the message settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_read_nvram_message_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_compose_settings,
        NVRAM_JMMS_COMPOSE_SETTINGS_SIZE /* NVRAM_JMMS_COMPOSE_SETTINGS_SIZE */ ,
        &error);

    if (g_jmms_context->nvram_compose_settings.layout == 0xFF)
    {
        // #ifdef __MMI_MMS_SIGNATURE__
        g_jmms_context->nvram_compose_settings.auto_signature = (U8) E_OFF;
        // #endif
        g_jmms_context->nvram_compose_settings.best_page_duration = (U8) E_OFF;
    #ifndef __MMI_UNIFIED_COMPOSER__
        g_jmms_context->nvram_compose_settings.creation_mode = (U8) E_CREAT_MODE_WARNING;
    #else 
        g_jmms_context->nvram_compose_settings.creation_mode = (U8) E_CREAT_MODE_FREE;
    #endif 

        /* HIMANSHU 05122006 START */
    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
        g_jmms_context->nvram_compose_settings.image_resize_option = (U8) E_IMAGE_RESIZE_OFF;
    #endif 
        /* HIMANSHU 05122006 END */
    #ifdef __DRM_SUPPORT__
        g_jmms_context->nvram_compose_settings.add_drm = (U8) E_OFF;
    #endif 
        g_jmms_context->nvram_compose_settings.layout = (U8) E_MMS_LAYOUT_POTRAIT;
        // #ifdef __MMI_MMS_SIGNATURE__
        memset(
            g_jmms_context->nvram_compose_settings.auto_signature_content,
            0x00,
            (MAX_AUTO_SIGN_LENGTH + 1) * ENCODING_LENGTH);
        // #endif /* __MMI_MMS_SIGNATURE__ */
        g_jmms_context->nvram_compose_settings.max_no_pages = (U8) MAX_POSSIBLE_SLIDES;
        g_jmms_context->nvram_compose_settings.default_slide_time = ((U32) DEFAULT_SLIDE_DURATION) / 1000;      /* /convert to seconds */

        WriteRecord(
            NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
            1,
            &g_jmms_context->nvram_compose_settings,
            NVRAM_JMMS_COMPOSE_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
            1,
            &g_jmms_context->nvram_compose_settings,
            NVRAM_JMMS_COMPOSE_SETTINGS_SIZE,
            &error);
    }
#ifdef __MMI_UNIFIED_COMPOSER__
    else
    {
        g_jmms_context->nvram_compose_settings.max_no_pages = (U8) MAX_POSSIBLE_SLIDES;
        g_jmms_context->nvram_compose_settings.best_page_duration = (U8) E_OFF;
    #ifdef __DRM_SUPPORT__
        g_jmms_context->nvram_compose_settings.add_drm = (U8) E_OFF;
    #endif 
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    ReadRecord(
        NVRAM_EF_JMMS_SENDING_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_sending_settings,
        NVRAM_JMMS_SENDING_SETTINGS_SIZE,
        &error);

    if (g_jmms_context->nvram_sending_settings.delivery_report == 0xFF)
    {
        g_jmms_context->nvram_sending_settings.deadline_for_reply = (U32) 0;
        g_jmms_context->nvram_sending_settings.delivery_report = (U8) DEFAULT_DELIVERY_REPORT_DURING_SENDING;
        g_jmms_context->nvram_sending_settings.delivery_time = (U8) E_IMMEDIATE;
        g_jmms_context->nvram_sending_settings.hide_sender = (U8) E_OFF;
        g_jmms_context->nvram_sending_settings.priority = (U8) E_PRIORITY_NORMAL;
        g_jmms_context->nvram_sending_settings.read_report = (U8) DEFAULT_READ_REPORT_DURING_SENDING;
        g_jmms_context->nvram_sending_settings.reply_charging = (U8) E_OFF;
        g_jmms_context->nvram_sending_settings.request_type = (U8) E_FULL_MMS;
        g_jmms_context->nvram_sending_settings.size = (U32) 0;
        g_jmms_context->nvram_sending_settings.validity_period = (U8) E_VALIDITY_PERIOD_MAX;

        WriteRecord(
            NVRAM_EF_JMMS_SENDING_SETTINGS_LID,
            1,
            &g_jmms_context->nvram_sending_settings,
            NVRAM_JMMS_SENDING_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_JMMS_SENDING_SETTINGS_LID,
            1,
            &g_jmms_context->nvram_sending_settings,
            NVRAM_JMMS_SENDING_SETTINGS_SIZE,
            &error);
    }

    ReadValue(NVRAM_JMMS_RETRIEVAL_SETTINGS, &g_jmms_context->nvram_retrieval_settings, DS_DOUBLE, &error);

    if (g_jmms_context->nvram_retrieval_settings.msgsize_filter == 0xFFFF)
    {
        g_jmms_context->nvram_retrieval_settings.home_network = (U8) DEFAULT_HOME_RETRIEVAL_MODE;
        g_jmms_context->nvram_retrieval_settings.roaming = (U8) DEFAULT_ROAMING_RETRIEVAL_MODE;
        g_jmms_context->nvram_retrieval_settings.anonymous_filter = (U8) DEFAULT_ANONYMOUS_FILTER_VALUE;
        g_jmms_context->nvram_retrieval_settings.advertisement_filter = (U8) DEFAULT_ADVERTISEMENT_FILTER_VALUE;
        g_jmms_context->nvram_retrieval_settings.read_report = (U8) DEFAULT_READ_REPORT_DURING_RETRIEVAL;
        g_jmms_context->nvram_retrieval_settings.delivery_report = (U8) DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL;
        g_jmms_context->nvram_retrieval_settings.msgsize_filter = (U16) (MAX_MMS_MSG_SIZE / 1024);
        WriteValue(NVRAM_JMMS_RETRIEVAL_SETTINGS, &g_jmms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
        ReadValue(NVRAM_JMMS_RETRIEVAL_SETTINGS, &g_jmms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
    }
#ifdef __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__
    else if (g_jmms_context->nvram_retrieval_settings.home_network == (U8) E_HOME_NOETWORK_RETRIEVAL_DEFFERED)
    {
        g_jmms_context->nvram_retrieval_settings.home_network = (U8) E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE;
        WriteValue(NVRAM_JMMS_RETRIEVAL_SETTINGS, &g_jmms_context->nvram_retrieval_settings, DS_DOUBLE, &error);
    }
#endif /* __MMI_JMMS_DEFERRED_NOT_AVAILABLE_AT_HOME_NW__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_restore_nvram_default_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_restore_nvram_default_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_jmms_context)
    {
        return;
    }
    // #ifdef __MMI_MMS_SIGNATURE__
    g_jmms_context->nvram_compose_settings.auto_signature = (U8) E_OFF;
    // #endif
    g_jmms_context->nvram_compose_settings.best_page_duration = (U8) E_OFF;
#ifndef __MMI_UNIFIED_COMPOSER__
    g_jmms_context->nvram_compose_settings.creation_mode = (U8) E_CREAT_MODE_WARNING;
#endif 
    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    g_jmms_context->nvram_compose_settings.image_resize_option = (U8) E_IMAGE_RESIZE_OFF;
#endif 
    /* HIMANSHU 05122006 END */
#ifdef __DRM_SUPPORT__
    g_jmms_context->nvram_compose_settings.add_drm = (U8) E_OFF;
#endif 
    g_jmms_context->nvram_compose_settings.layout = (U8) E_MMS_LAYOUT_POTRAIT;
    // #ifdef __MMI_MMS_SIGNATURE__
    memset(
        g_jmms_context->nvram_compose_settings.auto_signature_content,
        0x00,
        (MAX_AUTO_SIGN_LENGTH + 1) * ENCODING_LENGTH);
    // #endif /* __MMI_MMS_SIGNATURE__ */
    g_jmms_context->nvram_compose_settings.max_no_pages = (U8) MAX_POSSIBLE_SLIDES;
    g_jmms_context->nvram_compose_settings.default_slide_time = ((U32) DEFAULT_SLIDE_DURATION) / 1000;  /* /convert to seconds */

    WriteRecord(
        NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_compose_settings,
        NVRAM_JMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    g_jmms_context->nvram_sending_settings.deadline_for_reply = (U32) 0;
    g_jmms_context->nvram_sending_settings.delivery_report = (U8) DEFAULT_DELIVERY_REPORT_DURING_SENDING;
    g_jmms_context->nvram_sending_settings.delivery_time = (U8) E_IMMEDIATE;
    g_jmms_context->nvram_sending_settings.hide_sender = (U8) E_OFF;
    g_jmms_context->nvram_sending_settings.priority = (U8) E_PRIORITY_NORMAL;
    g_jmms_context->nvram_sending_settings.read_report = (U8) DEFAULT_READ_REPORT_DURING_SENDING;
    g_jmms_context->nvram_sending_settings.reply_charging = (U8) E_OFF;
    g_jmms_context->nvram_sending_settings.request_type = (U8) E_FULL_MMS;
    g_jmms_context->nvram_sending_settings.size = (U32) 0;
    g_jmms_context->nvram_sending_settings.validity_period = (U8) E_VALIDITY_PERIOD_MAX;

    WriteRecord(
        NVRAM_EF_JMMS_SENDING_SETTINGS_LID,
        1,
        &g_jmms_context->nvram_sending_settings,
        NVRAM_JMMS_SENDING_SETTINGS_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_reply_charging_settings_done
 * DESCRIPTION
 *  Done handler of Reply charging settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_sending_reply_charging_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_reply_charging_done = 1;

    if (mmi_ucs2ncmp
        ((S8*) g_jmms_context->jmms_inline_items.sending_items_list.deadline_for_reply_buffer, "\0",
         MAX_DEADLINE_TIME_VALUE_INPUT * ENCODING_LENGTH) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SETTINGS_REPLY_DEADLINE_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
    }
    else if (mmi_ucs2ncmp
             ((S8*) g_jmms_context->jmms_inline_items.sending_items_list.reply_msg_size_buffer, "\0",
              MAX_REPLY_CHARGE_SIZE_INPUT * ENCODING_LENGTH) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SETTINGS_REPLY_CHARGE_SIZE_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_sending_reply_charging_settings
 * DESCRIPTION
 *  Pre entry fn for reply charging settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_sending_reply_charging_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_entry_sending_reply_charging_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sending_settings_highlight_hdlr
 * DESCRIPTION
 *  Highlight hdlr for sending setting screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_sending_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_reply_charging_done == 1)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        SetRightSoftkeyFunction(mmi_jmms_confirm_save_sending_settings, KEY_EVENT_UP);
    }

}

/* MAUI_00227929 Start */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fill_mms_sending_settings
 * DESCRIPTION
 *  Filled mms sending settings structure either by using MMS PDU or NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fill_mms_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_use_local_send_setings == 0)
    {
        gui_itoa(
            (S32) mmi_jmms_sending_settings_deadline_for_reply(),
            (UI_string_type) g_jmms_context->sending_settings.deadline_for_reply_buffer,
            10);
        g_jmms_context->sending_settings.delivery_report = (S32) mmi_jmms_sending_settings_delivery_report();
        g_jmms_context->sending_settings.delivery_time =
            /* MAUI_00018559 Start */
            (S32) /* mmi_jmms_sending_settings_delivery_time(); */ g_jmms_context->nvram_sending_settings.delivery_time;
        /* amit commented this as we are reading values for UI so no need to have time in seconds */
        /* MAUI_00018559 End */
        g_jmms_context->sending_settings.hide_sender = (S32) mmi_jmms_sending_settings_hide_sender();
        g_jmms_context->sending_settings.priority = (S32) mmi_jmms_sending_settings_priority();
        g_jmms_context->sending_settings.read_report = (S32) mmi_jmms_sending_settings_read_report();
        g_jmms_context->sending_settings.reply_charging = (S32) mmi_jmms_sending_settings_reply_charging_status();
        g_jmms_context->sending_settings.request_type = (S32) mmi_jmms_sending_settings_reply_charging_request_type();
        g_jmms_context->sending_settings.validity_period =
            /* MAUI_00018559 Start */
            (S32) /* mmi_jmms_sending_settings_validity_period(); */ g_jmms_context->nvram_sending_settings.
            validity_period;
        /* amit commented this as we are reading values for UI so no need to have time in seconds */
        /* MAUI_00018559 End */
        gui_itoa(
            (S32) mmi_jmms_sending_settings_reply_charging_size(),
            (UI_string_type) g_jmms_context->sending_settings.reply_msg_size_buffer,
            10);

    }
    /* sanjeev added */
    else if (g_jmms_context->g_use_local_send_setings == 1)
    {
        MESSAGE_HEADERS *pMsgHeaders = NULL;
        MESSAGE_SEND *pMessageSend = NULL;

        mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &pMsgHeaders);

        /* MAUI_00018548 Start */
        if (pMsgHeaders != NULL)
        {
            pMessageSend = pMsgHeaders->pHeaders;

            g_jmms_context->sending_settings.delivery_report = (S32) pMessageSend->bDeliveryReport;

            g_jmms_context->sending_settings.hide_sender = (S32) pMessageSend->bHideSender;
            g_jmms_context->sending_settings.priority =
                /* MAUI_00018625 Start */
                (S32) pMessageSend->eMsgPriority;   /* sanjeev changes 20/12/06 */
            /* MAUI_00018625 End */
            g_jmms_context->sending_settings.read_report = (S32) pMessageSend->bReadReport;

            if (pMessageSend->pReplyChargingInfo != NULL)
            {
                g_jmms_context->sending_settings.reply_charging = (S32) E_ON;

                gui_itoa(
                    (S32) pMessageSend->pReplyChargingInfo->uiRelativeTime,
                    (UI_string_type) g_jmms_context->sending_settings.deadline_for_reply_buffer,
                    10);

                g_jmms_context->sending_settings.request_type =
                    (S32) (pMessageSend->pReplyChargingInfo->eReplyCharging);

                gui_itoa(
                    (S32) pMessageSend->pReplyChargingInfo->uiSize,
                    (UI_string_type) g_jmms_context->sending_settings.reply_msg_size_buffer,
                    10);

            }
            else
            {
                g_jmms_context->sending_settings.reply_charging = (S32) E_OFF;
            }

            switch (pMessageSend->uiExpiryTime)
            {
                case MAX_VALIDITY_PERIOD_VALUE:
                    g_jmms_context->sending_settings.validity_period = (S32) E_VALIDITY_PERIOD_MAX;
                    break;
                case 3600:
                    g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_1HR;
                    break;
                case 12 * 3600:
                    g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_12HRS;
                    break;
                case 1 * 24 * 3600:
                    g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_1DAY;
                    break;
                case 1 * 7 * 24 * 3600:
                    g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_1WEEK;
                    break;
                default:
                    g_jmms_context->sending_settings.validity_period = E_VALIDITY_PERIOD_MAX;
                    break;

            }

            switch (pMessageSend->uiDeliveryTime)
            {
                case 0:
                    g_jmms_context->sending_settings.delivery_time = E_IMMEDIATE;
                    break;
                case 3600:
                    g_jmms_context->sending_settings.delivery_time = E_1_HR;
                    break;
                case 12 * 3600:
                    g_jmms_context->sending_settings.delivery_time = E_12_HRS;
                    break;
                case 24 * 3600:
                    g_jmms_context->sending_settings.delivery_time = E_24_HRS;
                    break;
                default:
                    g_jmms_context->sending_settings.delivery_time = E_IMMEDIATE;
                    break;
            }
        }
        /* MAUI_00018548 End */
    }
}

/* MAUI_00227929 Start */

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#endif /* _MMI_JMMSMMSSETTINGS_C */ 


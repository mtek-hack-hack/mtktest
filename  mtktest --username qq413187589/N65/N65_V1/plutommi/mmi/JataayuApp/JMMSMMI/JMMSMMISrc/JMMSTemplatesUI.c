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
 *  JMMSTemplatesUI.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui for template folder in mms
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
// #if 0 //Pranav Commeneted
#ifndef _MMI_JMMSTEMPLATESSECMMI_C
#define _MMI_JMMSTEMPLATESSECMMI_C

/***************************************************************************** 
* Include
*****************************************************************************/

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "MessagesResourceData.h"
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "MainMenuDef.h"
#include <ddl.h>
#include <jcal.h>
#include <ddlbase.h>
#include "jdd_ui_datatypes.h"
#include <MessagingDataTypes.h>
#include <MessagingAPI.h>
#include "PrvMessagingDataTypes.h"
#include <ComposeUtils.h>
#include "jdd_ui_utils.h"
#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
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
#include "wapadp.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "JMMSUMHandling.h"
#endif 

#ifdef _MUTILANG_TEMPLATE_
extern U16 gCurrLangIndex;
#endif /* _MUTILANG_TEMPLATE_ */ 

#include "JMMSCoreAPI.h"
#include "custom_wap_config.h"
#include "resource_audio.h"
#include "CallManagementGprot.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "JMMSUCInterfaceProt.h"
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
/* extern audio_resource_struct* resource_mms_sounds; */
extern audio_resource_struct *resource_mms_sounds;

/* extern JC_RETCODE mmi_jdd_ui_get_image_buffer_size(JC_IMAGE_INFO *image_info); */

const mmi_jmms_template_info_struct g_mms_templates[] = 
{
    {STR_ID_JMMS_TEMPLATES_TITLE_01, IMG_ID_JMMS_TEMPLATES_01, 0},      /* MMS Template 1 */
    {STR_ID_JMMS_TEMPLATES_TITLE_02, IMG_ID_JMMS_TEMPLATES_02, 1},      /* MMS Template 2 */
    {STR_ID_JMMS_TEMPLATES_TITLE_03, IMG_ID_JMMS_TEMPLATES_03, 2},      /* MMS Template 3 */
    {STR_ID_JMMS_TEMPLATES_TITLE_04, IMG_ID_JMMS_TEMPLATES_04, 3},      /* MMS Template 4 */
    {STR_ID_JMMS_TEMPLATES_TITLE_05, IMG_ID_JMMS_TEMPLATES_05, 4},      /* MMS Template 5 */
    {STR_ID_JMMS_TEMPLATES_TITLE_06, IMG_ID_JMMS_TEMPLATES_06, 5},      /* MMS Template 6 */
    {STR_ID_JMMS_TEMPLATES_TITLE_07, IMG_ID_JMMS_TEMPLATES_07, 6},      /* MMS Template 7 */
    {STR_ID_JMMS_TEMPLATES_TITLE_08, IMG_ID_JMMS_TEMPLATES_08, 7},      /* MMS Template 8 */
    {STR_ID_JMMS_TEMPLATES_TITLE_09, IMG_ID_JMMS_TEMPLATES_09, 8},      /* MMS Template 9 */
    {STR_ID_JMMS_TEMPLATES_TITLE_10, IMG_ID_JMMS_TEMPLATES_10, 9},      /* MMS Template 10 */
};

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern void wap_send_fmt_format_rsp(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_templates
 * DESCRIPTION
 *  Highlight hdlr of Template menu item in main mms screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_templates, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_templates, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_templates, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_templates_init
 * DESCRIPTION
 *  This function init the hilight handlers of templates menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_templates_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Templates options Highlight handlers */
    SetHiliteHandler(MENU_ID_JMMS_TEMPLATES_OPTIONS_VIEW, mmi_jmms_highlight_templates_options_view);
    SetHiliteHandler(MENU_ID_JMMS_TEMPLATES_OPTIONS_WRITE_MESSAGE, mmi_jmms_highlight_templates_options_write_message);
    SetHiliteHandler(MENU_ID_JMMS_TEMPLATES_OPTIONS_PROPERTIES, mmi_jmms_highlight_templates_options_properties);
#ifdef __MMI_UNIFIED_MESSAGE__

    SetHiliteHandler(MENU_ID_JMMS_TEMPLATES_OPTIONS_VIEW_VIEW_AS, mmi_jmms_highlight_templates_options_view_view_as);
    SetHiliteHandler(
        MENU_ID_JMMS_TEMPLATES_OPTIONS_VIEW_SAVE_OBJECT,
        mmi_jmms_highlight_templates_view_options_save_objects);
    SetHiliteHandler(
        MENU_ID_JMMS_TEMPLATES_OPTIONS_VIEW_USE_NUMBER,
        mmi_jmms_highlight_templates_view_options_use_number);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    g_jmms_context->gtemplate_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_template_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_template_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_entry_template_progress_screen");

    EntryNewScreen(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS, NULL, mmi_jmms_entry_template_progress_screen, NULL);

    ShowCategory154Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_JMMS_PLEASE_WAIT),
        NULL,
        IMG_ID_JMMS_PROGRESS_FULL,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_re_create_templates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  template_complete_callback      [IN]        
 *  show_popup                      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_re_create_templates(FuncPtr template_complete_callback, MMI_BOOL show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_num_msgs = 0;
    JC_RETCODE error_code = JC_OK;

#ifdef _MUTILANG_TEMPLATE_
    U16 language_change = 0;
    S16 error;
#endif /* _MUTILANG_TEMPLATE_ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_show_popup = show_popup;
    g_jmms_context->g_template_complete_callback = NULL;
    error_code = mmi_mms_get_number_of_messages(MMI_JMMS_TEMPLATES, &total_num_msgs);
    if (error_code != JC_OK)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Error for Templates=", error_code);
        return 1;
    }
#ifdef _MUTILANG_TEMPLATE_
    ReadValue(NVRAM_JMMS_LANGUAGE_CHANGE, &language_change, DS_SHORT, &error);
    if ((total_num_msgs < __MMI_MMS_TEMPLATES_NUM__) || (language_change != gCurrLangIndex))
#else /* _MUTILANG_TEMPLATE_ */ 
    if (total_num_msgs < __MMI_MMS_TEMPLATES_NUM__)
#endif /* _MUTILANG_TEMPLATE_ */ 
    {
        /* try to delete templates only if the count is more than 0
           else delete function will not return JC_OK causing error pop up */
        if (total_num_msgs)
        {
            error_code = mmi_jmms_delete_all_message(MMI_JMMS_TEMPLATES);
            if (error_code != JC_OK && total_num_msgs > 0)
            {
                DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Error for Templates Deletion=", error_code);
                DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS);
                return 1;
            }
        }
        mmi_jmms_entry_template_progress_screen();
        g_jmms_context->gtemplate_count = 0;
        g_jmms_context->g_template_complete_callback = template_complete_callback;
        mmi_jmms_create_template_messages();
        return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_templates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_templates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_jmms_is_ready_without_store(1))
    {
        return;
    }
    if (mmi_jmms_re_create_templates(mmi_jmms_entry_templates_screen, MMI_TRUE))
    {
        return;
    }
    else
    {
        mmi_jmms_entry_templates_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_templates_screen
 * DESCRIPTION
 *  Entry fn for templates screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_templates_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;   /* Buffer holding history data */
    U8 total_num_msgs = 0;
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_mms_get_number_of_messages(MMI_JMMS_TEMPLATES, &total_num_msgs);
    g_jmms_context->store_context->num_msg_in_curr_folder = total_num_msgs;
    g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
    g_jmms_context->store_context->current_folder_name = E_JMMS_TEMPLATES;
    EntryNewScreen(SCR_ID_JMMS_TEMPLATES, NULL, mmi_jmms_entry_templates_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_TEMPLATES);

    SetParentHandler(MENU_ID_JMMS_TEMPLATES);
    RegisterHighlightHandler(mmi_jmms_folder_list_highlight_hdlr);

    ShowCategory184Screen(
        STR_ID_JMMS_TEMPLATES,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_jmms_context->store_context->num_msg_in_curr_folder,
        mmi_jmms_get_item_data_templates,
        0,
        0,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_entry_templates_options_scren, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_templates_options_scren, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_templates_options_scren, KEY_WAP, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_data_templates
 * DESCRIPTION
 *  fn retrun the item data
 * PARAMETERS
 *  item_index          [IN]        (index of item to be drawn)
 *  str_buff_p          [OUT]       (string of item)
 *  img_buff_p          [OUT]       (image corrsponding to item
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_jmms_get_item_data_templates(S32 item_index, UI_string_type str_buff_p, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_POSSIBLE_MESSAGES))
    {
        return FALSE;
    }

    if (mmi_ucs2strlen((S8*) GetString(g_mms_templates[item_index].strId)))
    {
        mmi_ucs2cpy((S8*) str_buff_p, (S8*) GetString(g_mms_templates[item_index].strId));
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff_p, (S8*) GetString(STR_ID_NO_SUBJECT));
    }

    *img_buff_p = (PU8) GetImage((U16) IMG_ID_JMMS_TEMPLATE_MMS);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_templates_options_scren
 * DESCRIPTION
 *  Entry fn for templates options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_templates_options_scren(void)
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
    EntryNewScreen(SCR_ID_JMMS_TEMPLATES_OPTIONS, NULL, mmi_jmms_entry_templates_options_scren, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_TEMPLATES_OPTIONS);

    num_item = GetNumOfChild(MENU_ID_JMMS_TEMPLATES_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_JMMS_TEMPLATES_OPTIONS, str_item_list);

    SetParentHandler(MENU_ID_JMMS_TEMPLATES_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
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
 *  mmi_jmms_highlight_templates_options_view
 * DESCRIPTION
 *  Highlight hdlr of templates option view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates_options_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
  //  SetLeftSoftkeyFunction(mmi_jmms_templates_view, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_jmms_templates_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
//    SetKeyHandler(mmi_jmms_templates_view, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_templates_options_write_message
 * DESCRIPTION
 *  Highlight hdlr of templates option write mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates_options_write_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_templates_write_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_templates_write_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_templates_write_message, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_templates_options_properties
 * DESCRIPTION
 *  Highlight hdlr of templates option properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates_options_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_templates_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_templates_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_templates_properties, KEY_WAP, KEY_EVENT_DOWN);
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_templates_options_view_view_as
 * DESCRIPTION
 *  Highlight hdlr of templates View option Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates_options_view_view_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_view_mms, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_view_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_view_mms, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_templates_view_options_save_objects
 * DESCRIPTION
 *  Highlight hdlr of templates View option Save Object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates_view_options_save_objects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_save_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_save_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_save_object, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_templates_view_options_use_number
 * DESCRIPTION
 *  Highlight hdlr of templates View option Use Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_templates_view_options_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_template_use_number, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_jmms_template_use_number, KEY_SEND, KEY_EVENT_UP); */
    SetKeyHandler(mmi_jmms_template_use_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_template_use_number, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_template_use_number
 * DESCRIPTION
 *  Pre entry fn for use details screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_template_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_pre_entry_use_details_screen(MMI_JMMS_TEMPLATES);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_templates_view_options_scren
 * DESCRIPTION
 *  Entry fn for templates options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_templates_view_options_scren(void)
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
    EntryNewScreen(SCR_ID_JMMS_TEMPLATES_VIEW_OPTIONS, NULL, mmi_jmms_entry_templates_view_options_scren, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_TEMPLATES_VIEW_OPTIONS);

    num_item = GetNumOfChild(MENU_ID_JMMS_TEMPLATES_VIEW_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_JMMS_TEMPLATES_VIEW_OPTIONS, str_item_list);

    SetParentHandler(MENU_ID_JMMS_TEMPLATES_VIEW_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
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
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_templates_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_templates_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    CONTENT_DATA Content = {0,0 };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Content.bIsStream = E_TRUE;
    error_code = mmi_jmms_get_message(MMI_JMMS_TEMPLATES, &Content, (g_jmms_context->curr_scr_hilited_index + 1));

    if (error_code != JC_OK)
    {
        mmi_jmms_error_handler(error_code);
        goto END;
    }

    g_jmms_context->last_scr_id = SCR_ID_JMMS_TEMPLATES_OPTIONS;
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_deinit_view();
#endif 
    error_code = mmi_jmms_pre_entry_mms_view(&Content);
    if (error_code == JC_ERR_MMS_PARSE_PENDING)
    {
        return;
    }

  END:

    if (error_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        error_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_templates_write_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_templates_write_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_deinit_mms_context(g_jmms_context);

    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    error_code = mmi_jmms_get_message(
                    MMI_JMMS_TEMPLATES,
                    g_jmms_context->parse_content_p,
                    (g_jmms_context->curr_scr_hilited_index + 1));

    if (error_code != JC_OK)
    {
        mmi_jmms_error_handler(error_code);
        goto END;
    }

    mmi_jmms_parsing_progressing_screen();

    error_code = mmi_jmms_jdi_parse_msg_buffer(&g_jmms_context->msg_handle, g_jmms_context->parse_content_p, E_TYPE_MMS, E_TRUE);

    if (error_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(
            g_jmms_context->msg_handle,
            mmi_jmms_templates_write_message_async_callback,
            mmi_jmms_only_abort_parsing_progress);
        return;
    }

    mmi_jmms_templates_write_message_async_callback(error_code);
    return;

  END:

    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
            g_jmms_context->parse_content_p->pFileName = NULL;
        }
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }

    if (error_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        error_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
    g_jmms_context->is_add_media_warning = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_templates_write_message_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_templates_write_message_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined (__MMI_UNIFIED_COMPOSER__)
    MESSAGE_HEADERS *msg_header_p = NULL;
    MESSAGE_SEND *send_p = NULL;
    S32 len = 0;
    JC_RETCODE ret_code_restricted = JC_OK;
#endif /* !defined (__MMI_UNIFIED_COMPOSER__) */ 
    ECreationMode create_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JC_OK != ret_code)
    {
        if (GetActiveScreenId() == SCR_ID_JMMS_PARSING_PROGRESS)
        {
            mmi_jmms_error_handler(ret_code);
        }
        goto END;
    }
    create_mode = mmi_jmms_compose_settings_creation_mode();
#ifdef __MMI_UNIFIED_COMPOSER__
    if (create_mode == E_CREATION_MODE_RESTRICTED &&
        IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
    {
        ClearExitHandler();
        mmi_jmms_uc_edit_content_restricted_mode_query();
    }
    else
    {
        ClearExitHandler();
        mmi_jmms_uc_compose_edit_request(g_jmms_context->curr_scr_hilited_index + 1, MMI_JMMS_TEMPLATES);
    }
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    ret_code = mmi_jmms_jdi_msg_register_callback(g_jmms_context->msg_handle, E_CB_ERROR_IND, (void*)mmi_jmms_error_ind_cb);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_set_content_class(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_set_creation_mode(g_jmms_context->msg_handle, create_mode);
    if (ret_code != JC_OK)
    {
        /********************************************************************
           These lines are added to ask a query if the message contains the 
           invalid media in restricted mode.

            Written By  : RAJ KUMAR GUPTA
            Date        : Augest 08, 2006
         *******************************************************************/
        if (JC_ERR_MSG_MMS_CONTENT_RESTRICTED == ret_code)
        {
            ret_code_restricted = JC_ERR_MSG_MMS_CONTENT_RESTRICTED;
        }
        else
        {
            mmi_jmms_error_handler(ret_code);
            goto END;
        }
        /*******************************************************************/
    }

    ret_code = mmi_jmms_jdi_set_msg_type(g_jmms_context->msg_handle, E_TYPE_MMS);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_set_presentation_type(g_jmms_context->msg_handle, E_PRESENTATION_SMIL);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, (U8) mmi_jmms_compose_settings_max_no_pages());
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &msg_header_p);
    if (ret_code != JC_OK || msg_header_p == NULL)
    {
        ret_code = JC_ERR_STORE_FILE_CORRUPTED;
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    if (msg_header_p->eMsgType != E_MSG_TYPE_SEND)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        goto END;
    }

    send_p = (MESSAGE_SEND*) (msg_header_p->pHeaders);

    mmi_jmms_free_addresses_list();

    /* /Make the subject buffer */
    memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
    if (send_p->pSubject != NULL)
    {

        len = (mmi_ucs2strlen((S8*) (send_p->pSubject)) + 1) * ENCODING_LENGTH;

        if (len > (MAX_SUBJECT_LENGTH * ENCODING_LENGTH))
        {
            memcpy(g_jmms_context->subject_input_buffer, send_p->pSubject, (MAX_SUBJECT_LENGTH * ENCODING_LENGTH));
        }
        else
        {
            memcpy(g_jmms_context->subject_input_buffer, send_p->pSubject, len);
        }

    }

    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

    g_jmms_context->g_use_local_send_setings = 0;
    mmi_jmms_fill_mms_sending_settings();

    if (g_jmms_context->is_add_media_warning == 0)
    {
        if (ret_code_restricted == JC_ERR_MSG_MMS_CONTENT_RESTRICTED)
        {
            mmi_jmms_edit_content_restricted_mode_query();
        }
        else
        {
            mmi_jmms_entry_write_message_screen();
        }
    }
    else
    {
        DisplayPopupCallBack(
            (PU8) GetString(STR_ID_JMMS_MMS_ERR_WARNING_CONTENT_CLASS),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE,
            mmi_jmms_entry_write_message_screen);
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
  END:
    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
            g_jmms_context->parse_content_p->pFileName = NULL;
        }
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }

    if (ret_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
    g_jmms_context->is_add_media_warning = 0;
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_templates_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_templates_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_show_mms_properties(E_MSG_NEW_MMS_TEMPLATES, MMI_JMMS_TEMPLATES);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_template_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_template_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer_p;   /* Buffer holding history data */
    S8 temp[14];
    S32 size_kb = 0, size_bytes = 0, len_to_copy = 0;
    JC_UINT32 size = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_NOTIFICATION_PROPERTIES, NULL, mmi_jmms_show_template_properties, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_NOTIFICATION_PROPERTIES);

    /* /Subject */
    mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_ID_JMMS_SUBJECT));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    if (((MESSAGE_SEND*) g_jmms_context->msg_header_type_p)->pSubject == NULL)
    {
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        len_to_copy = mmi_ucs2strlen((S8*) ((MESSAGE_SEND*) g_jmms_context->msg_header_type_p)->pSubject);
        if (len_to_copy > MAX_SUBJECT_LENGTH)
        {
            len_to_copy = MAX_SUBJECT_LENGTH;
        }
        mmi_ucs2ncat(
            (S8*) subMenuData,
            (S8*) ((MESSAGE_SEND*) g_jmms_context->msg_header_type_p)->pSubject,
            len_to_copy);
    }

    /* /Size of MMS */

    /* /size is returned in Bytes */
    ret_code = mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &size);
    if (ret_code != JC_OK)
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            mmi_jmms_deinit_mms_context(g_jmms_context);
        }
    }

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
    mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_JMMS_SIZE));

    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp);

    size_kb = size / 1024;
    size_bytes = size % 1024;

    if (size_kb >= 1)
    {
        size_kb++;
        memset(temp, 0x00, 14);
        gui_itoa((S32) size_kb, (UI_string_type) temp, 10);
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        memset(temp, 0x00, 4);
        mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_JMMS_KB));

    }
    else
    {
        memset(temp, 0x00, 14);
        gui_itoa((S32) size_bytes, (UI_string_type) temp, 10);
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        memset(temp, 0x00, 4);
        mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
        mmi_ucs2cat((S8*) subMenuData, (S8*) temp);
        mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_JMMS_BYTES));
    }

    ShowCategory78Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) subMenuData,
        mmi_ucs2strlen((S8*) subMenuData),
        gui_buffer_p);

    SetRightSoftkeyFunction(mm_jmms_back_from_template_properties, KEY_EVENT_UP);
    SetKeyHandler(mm_jmms_back_from_template_properties, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mm_jmms_end_from_template_properties, KEY_END, KEY_EVENT_DOWN);
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mm_jmms_back_from_template_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mm_jmms_back_from_template_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_deinit_mms_context(g_jmms_context);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mm_jmms_end_from_template_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mm_jmms_end_from_template_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_deinit_mms_context(g_jmms_context);
    DisplayIdleScreen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_template_messages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_template_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 i = 0; */
    PU8 img_buff_p;
    S8 *title;

    /* JC_RETCODE ret_code = JC_OK; */
    U32 audio_len = 0, image_len = 0;
    U8 *audio_buff_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * for (i = 0; i < __MMI_MMS_TEMPLATES_NUM__; i++)
     * {
     */
    title = (S8*) GetString(g_mms_templates[g_jmms_context->gtemplate_count].strId);
    img_buff_p = (PU8) GetImage((U16) (g_mms_templates[g_jmms_context->gtemplate_count].imageId));
    audio_len = resource_mms_sounds[g_mms_templates[g_jmms_context->gtemplate_count].audioId].len;
    audio_buff_p = (U8*) (resource_mms_sounds[g_mms_templates[g_jmms_context->gtemplate_count].audioId].data);

    mmi_jmms_create_template_mms(title, (U8*) (img_buff_p), image_len, audio_buff_p, audio_len);

    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_template_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subject_p           [IN]        
 *  image_buff_p        [IN]        
 *  image_len           [IN]        
 *  audio_buff_p        [IN]        
 *  audio_len           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_create_template_mms(
            S8 *subject_p,
            U8 *image_buff_p,
            U32 image_len,
            U8 *audio_buff_p,
            U32 audio_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    MESSAGE_SEND *message_send_p = NULL;
    MESSAGE_HEADERS *msg_header_p = NULL;
    S32 len = 0;
    JMMS_COMP_ERRCODE err_code;
    U8 content_type_audio[] = "audio/midi";
    JC_IMAGE_INFO img_info = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free any allocated memory */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enters create_template_jmms: %d", wap_get_mms_content_class());
    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_deinit_mms_context(g_jmms_context);
    }

    if (g_jmms_context->compose_context == NULL)
    {
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto END;
        }
    }
    mmi_jmms_free_mms_pdu_memory(g_jmms_context);

    g_jmms_context->msg_headers_p = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);

    if (NULL == g_jmms_context->msg_headers_p)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    g_jmms_context->msg_header_type_p = (MESSAGE_SEND*) jdd_MemAlloc(sizeof(MESSAGE_SEND), 1);
    if (NULL == g_jmms_context->msg_header_type_p)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    ret_code = mmi_jmms_set_mmsc_version();
    if (ret_code != JC_OK)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    msg_header_p = g_jmms_context->msg_headers_p;
    message_send_p = g_jmms_context->msg_header_type_p;

    message_send_p->pVersion = (JC_INT8*) g_jmms_context->version;

    message_send_p->bDeliveryReport = DEFAULT_DELIVERY_REPORT_DURING_SENDING;
    message_send_p->bReadReport = DEFAULT_READ_REPORT_DURING_SENDING;
    message_send_p->bHideSender = E_OFF;

    message_send_p->uiExpiryTime = MAX_VALIDITY_PERIOD_VALUE;

    message_send_p->uiDeliveryTime = 0;

    message_send_p->eMsgPriority = E_MSG_PRIORITY_NORMAL;
    message_send_p->pReplyChargingInfo = NULL;

    message_send_p->eMsgClass = E_MSG_PERSONAL_CLASS;
    message_send_p->pTo = NULL;
    message_send_p->pCc = NULL;
    message_send_p->pBcc = NULL;

    len = 0;
    len = mmi_ucs2strlen((S8*) subject_p);

    g_jmms_context->subject_p = (S8*) jdd_MemAlloc(sizeof(S8), (len + 1) * ENCODING_LENGTH);

    if ((g_jmms_context->subject_p == NULL) && (len != 0))
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    if (g_jmms_context->subject_p)
    {
        mmi_ucs2cpy((S8*) g_jmms_context->subject_p, (S8*) subject_p);
        message_send_p->pSubject = (JC_CHAR*) g_jmms_context->subject_p;
    }

    message_send_p->uiDate = 0;
    message_send_p->pFrom = NULL;

    msg_header_p->eMsgType = E_MSG_TYPE_SEND;
    msg_header_p->pHeaders = message_send_p;

    if (JMMS_COMP_OK == mmi_jmms_compose_new_mms())
    {

        g_jmms_context->compose_context->mms_bg_color = g_jmms_color_RGB_list[COLOR_WHITE];
        /* Added by Deepali for root layout. */
        err_code = mmi_jmms_set_bg_color(g_jmms_context->compose_context->mms_bg_color);
        if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
        {
            ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto END;
        }

        g_jmms_context->compose_context->curr_page_index = 0;
        err_code = mmi_jmms_compose_insert_slide();
        /* PMT HIMANSHU END 20060425 */
        if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
        {
            ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto END;
        }
    }
    else
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    ret_code = mmi_jmms_jdi_set_msg_headers(g_jmms_context->msg_handle, msg_header_p);
    if (JC_OK != ret_code)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }
    g_jmms_context->layout = CUSTOM_LAYOUT;
    jc_tcscpy(
        (UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
        (UI_character_type*) subject_p);

    mmi_jmms_compose_add_text(
        1,
        &g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font,
        g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color,
        1);

    /* TODO: Need to see if the image is out of content class */
    img_info.pImgBuffer = image_buff_p;

    mmi_jdd_ui_get_image_buffer_size(&img_info);

    /* mmi_jmms_compose_add_media_buffer(U8 *buffer, U32 size, U8 type,U8 is_attachment, U8 page_index) */
    if (wap_get_mms_content_class() > WAP_MMS_CONTENT_CLASS_TEXT)
    {
        mmi_jmms_compose_add_media_template(
            img_info.pImgBuffer,
            (U8*) img_info.psMimeType,
            img_info.uiImgSize,
            E_MEDIA_IMAGE,
            E_FALSE,
            1);
    }

    if (img_info.psMimeType != NULL)
    {
        jdd_MemFree(img_info.psMimeType);
    }
    if (wap_get_mms_content_class() > WAP_MMS_CONTENT_CLASS_IMAGE_BASIC)
    {
        mmi_jmms_compose_add_media_template(
            audio_buff_p,
            (U8*) content_type_audio,
            audio_len,
            E_MEDIA_AUDIO,
            E_FALSE,
            1);
    }
    ret_code = mmi_jmms_save_mms(
                MMI_JMMS_TEMPLATES,
                g_jmms_context->msg_handle,
                MMI_FALSE,
                0,
                mmi_jmms_create_template_mms_return_callback);
    if (ret_code == JC_ERR_MMS_ENCODE_PENDING)
    {
        return ret_code;
    }
    else if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Parsing Failed: mmi_jmms_create_template_mms");
        if (g_jmms_context->is_in_format_mode)
        {
            g_jmms_context->init_done = JMMS_TEMPLATES_INITIALIZED;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_create_template_mms: %d", g_jmms_context->init_done);
        }

    }

  END:
    mmi_jmms_create_template_mms_return_callback(ret_code);
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_template_mms_return_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_template_mms_return_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_num_msgs = 0;

#ifdef _MUTILANG_TEMPLATE_
    U16 language_change = 0;
    S16 error;
#endif /* _MUTILANG_TEMPLATE_ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "create_template_mms_return_callback: %d count:%d", ret_code,
                         g_jmms_context->gtemplate_count);
    if (ret_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_deinit_mms_context(g_jmms_context);
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
    }

    if (ret_code != JC_OK)
    {
        g_jmms_context->init_done = JMMS_INITIALIZED;
        mmi_jmms_delete_all_message(MMI_JMMS_TEMPLATES);
        if (GetActiveScreenId() == SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS)
        {
            if (g_jmms_context->g_show_popup)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
            }
            else
            {
                g_jmms_context->g_template_complete_callback();
            }
            DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS);

        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS);
        }
    }
    else
    {
        g_jmms_context->gtemplate_count++;
        if (g_jmms_context->gtemplate_count < __MMI_MMS_TEMPLATES_NUM__)
        {
            mmi_jmms_create_template_messages();
            g_jmms_context->layout = DEFAULT_LAYOUT;
            return;
        }
        else
        {
            ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_TEMPLATES, &total_num_msgs);
            if (ret_code != JC_OK)
            {
                ASSERT(0);
            }

            if (total_num_msgs == 0)
            {
                if (GetActiveScreenId() == SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        JMMS_POPUP_TIME,
                        EMPTY_LIST_TONE);
                }
                if (g_jmms_context->init_done == JMMS_INITIALIZED)
                {
                    g_jmms_context->init_done = JMMS_READY;
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_create_template_mms_return_callback: 0 MMS");
                    if (g_jmms_context->is_in_format_mode)
                    {
                        wap_send_fmt_format_rsp();
                        g_jmms_context->is_in_format_mode = 0;
                    }
                #ifdef __MMI_UNIFIED_MESSAGE__
                    mmi_um_jmms_ready_ind();
                #endif 
                }
                return;
            }
            g_jmms_context->store_context->num_msg_in_curr_folder = total_num_msgs;
            if (GetActiveScreenId() == SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS)
            {
                if (g_jmms_context->g_template_complete_callback)
                {
                    g_jmms_context->g_template_complete_callback();
                    DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS);
                    g_jmms_context->g_template_complete_callback = NULL;
                }
                else
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Templates Created but no callback screen");
                    DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS);
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS))
                {
                    if (g_jmms_context->g_template_complete_callback)
                    {
                        HistoryReplace(
                            SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS,
                            SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS,
                            g_jmms_context->g_template_complete_callback);
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Templates Creation Screen in History");
                        g_jmms_context->g_template_complete_callback = NULL;
                    }
                    else
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                                             "Templates Creation Screen in History but no entry fn");
                        DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_CREATION_PROGRESS);
                    }
                }
            }
        #ifdef _MUTILANG_TEMPLATE_
            ReadValue(NVRAM_JMMS_LANGUAGE_CHANGE, &language_change, DS_SHORT, &error);

            if (language_change == 0xFFFF)
            {
                WriteValue(NVRAM_JMMS_LANGUAGE_CHANGE, &gCurrLangIndex, DS_SHORT, &error);
            }
            else if (language_change != gCurrLangIndex)
            {
                WriteValue(NVRAM_JMMS_LANGUAGE_CHANGE, &gCurrLangIndex, DS_SHORT, &error);
            }
        #endif /* _MUTILANG_TEMPLATE_ */ 
        }
    }

    if (g_jmms_context->init_done == JMMS_INITIALIZED)
    {
        if (mmi_jmms_sys_folders_exist() == JC_OK)
        {
            g_jmms_context->init_done = JMMS_READY;
        }
        else
        {
            mmi_jmms_deinit_shutdown_with_protocol_init();
            g_jmms_context->init_done = JMMS_READY_WITHOUT_STORE;
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "create_template_mms_return_callback UM Ready: %d",
                             g_jmms_context->init_done);
        if (g_jmms_context->is_in_format_mode)
        {
            wap_send_fmt_format_rsp();
            g_jmms_context->is_in_format_mode = 0;
        }
    #ifdef __MMI_UNIFIED_MESSAGE__
        mmi_um_jmms_ready_ind();
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_new_mms_template_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_new_mms_template_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer_p;   /* Buffer holding history data */
    S8 temp[14];

    /* PMT VIKAS START 20060325 */
    S32 size = 0, size_kb = 0, size_bytes = 0, len_to_copy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS END 20060325 */

    EntryNewScreen(
        SCR_ID_JMMS_RETRIEVED_MMS_PROPERTIES,
        mmi_jmms_common_exit_property_screen,
        mmi_jmms_entry_new_mms_template_properties,
        NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_RETRIEVED_MMS_PROPERTIES);

    g_jmms_context->property_display_buffer_p =
        (U8*) jdd_MemAlloc(
                sizeof(U8),
                (MAX_BUFFER_SIZE_FOR_PROPERTY + 1 + (MAX_NO_OF_ALLOWABLE_ADDRESSES * MAX_POSSIBLE_EMAIL_LENGHT_SENT)) * ENCODING_LENGTH);
    if (g_jmms_context->property_display_buffer_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_JMMS_RETRIEVED_MMS_PROPERTIES);
        return;
    }

    /* /Subject */

    mmi_ucs2cpy((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_SUBJECT));
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);

    if (((MESSAGE_SEND*) g_jmms_context->send_msg_p)->pSubject == NULL)
    {
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        len_to_copy = mmi_ucs2strlen((S8*) ((MESSAGE_SEND*) g_jmms_context->send_msg_p)->pSubject);
        if (len_to_copy > MAX_SUBJECT_LENGTH)
        {
            len_to_copy = MAX_SUBJECT_LENGTH;
        }
        mmi_ucs2ncat(
            (S8*) g_jmms_context->property_display_buffer_p,
            (S8*) ((MESSAGE_SEND*) g_jmms_context->send_msg_p)->pSubject,
            len_to_copy);
    }

    //PMT VIKAS START 20060325
    ///MMS Size            
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_SIZE));
    memset(temp, 0x00, 14);
    mmi_asc_to_ucs2((PS8) temp, (PS8) "\n----\n");
    mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
    mmi_jmms_save_size_of_mms(&size, MMS_SIZE_RETRIVE);
    size_kb = size / 1024;
    size_bytes = size % 1024;

    if (size_kb >= 1)
    {
        size_kb++;
        memset(temp, 0x00, 14);
        gui_itoa((S32) size_kb, (UI_string_type) temp, 10);
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
        memset(temp, 0x00, 4);
        mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_KB));

    }
    else
    {
        memset(temp, 0x00, 14);
        gui_itoa((S32) size_bytes, (UI_string_type) temp, 10);
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
        memset(temp, 0x00, 4);
        mmi_asc_to_ucs2((PS8) temp, (PS8) " ");
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) temp);
        mmi_ucs2cat((S8*) g_jmms_context->property_display_buffer_p, (S8*) GetString(STR_ID_JMMS_BYTES));
    }
    /* PMT VIKAS END 20060325 */

    ShowCategory78Screen(
        /* MAUI_00018481 Start */ STR_ID_JMMS_OPTIONS_PROPERTIES,
        /* MAUI_0001848 End */ GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) g_jmms_context->property_display_buffer_p,
        mmi_ucs2strlen((S8*) g_jmms_context->property_display_buffer_p),
        gui_buffer_p);

    SetRightSoftkeyFunction(mm_jmms_back_from_sent_msg_properties, KEY_EVENT_UP);
    SetKeyHandler(mm_jmms_back_from_sent_msg_properties, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    if (isInCall() == FALSE)
    {
        SetKeyHandler(mm_jmms_end_from_sent_msg_properties, KEY_END, KEY_EVENT_DOWN);
    }

    return;

}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

#endif /* _MMI_JMMSTEMPLATESSECMMI_C */ 


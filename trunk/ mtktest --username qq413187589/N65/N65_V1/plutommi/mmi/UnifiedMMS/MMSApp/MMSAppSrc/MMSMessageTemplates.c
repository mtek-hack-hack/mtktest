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
 *  MMSMessageTemplates.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui for template folders in mms
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
 *
 * removed!
 * removed!
 * removed!
 *
 
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
#include "FileManagerGProt.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "MessagesMiscell.h"
#include "MessagesResourceData.h"
#include "ProtocolEvents.h"
#include "UnifiedMessageResDef.h"
#include "MMSMsgXMLTags.h"
#include "MMSMessageSettingsUtils.h"
#include "MMSMessageSettings.h"
#include "MMSXMLDef.h"
#include "MMSMessageTemplates.h"
#include "MMSAppResDef.h"
#include "UnifiedMessageGProt.h"
#include "MMSAppProt.h"
#include "MMSAppGprot.h"
#include "MMSMsgCommonProt.h"

extern void mmi_umms_entry_templates_options_msg_id(void);
extern kal_uint32 applib_get_file_size(kal_wchar *filename);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
//static S32 mmi_image_read_length(U8 *image);

extern U16 gCurrLangIndex;
static umms_setting_create_mms_struct g_user_defined_create;
static mmi_umms_xml_msg_struct *g_mms_xml_msg;
static mmi_umms_templates_type_enum g_template_type;
static U8 g_template_count = 0;
static U8 g_default_template_count = 0;
extern umms_context_struct *g_umms_context;
static mmi_um_msg_info_struct *g_msg_info_tpl_struct;
extern audio_resource_struct *resource_mms_sounds;
mmi_umms_template_info_struct mms_templates[] = 
{
    {STR_ID_UMMS_TEMPLATES_TITLE_01, IMG_ID_UMMS_TEMPLATES_01, 0},      /* MMS Template 1 */
    {STR_ID_UMMS_TEMPLATES_TITLE_02, IMG_ID_UMMS_TEMPLATES_02, 1},      /* MMS Template 2 */
    {STR_ID_UMMS_TEMPLATES_TITLE_03, IMG_ID_UMMS_TEMPLATES_03, 2},      /* MMS Template 3 */
    {STR_ID_UMMS_TEMPLATES_TITLE_04, IMG_ID_UMMS_TEMPLATES_04, 3},      /* MMS Template 4 */
    {STR_ID_UMMS_TEMPLATES_TITLE_05, IMG_ID_UMMS_TEMPLATES_05, 4},      /* MMS Template 5 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_templates_init
 * DESCRIPTION
 *  This function init the hilight handlers of templates menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_templates_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Templates options Highlight handlers */

    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_USER_DEFINED, mmi_umms_highlight_templates_user_defined);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_DEFAULT, mmi_umms_highlight_templates_default);

    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_WRITE_MESSAGE, mmi_umms_highlight_edit_msg);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_PROPERTIES, mmi_umms_highlight_show_properties);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE, mmi_umms_highlight_delete_msg);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE_ALL, mmi_umms_highlight_delete_all_msg);

    SetHintHandler(MENU_ID_UMMS_TEMPLATES_USER_DEFINED, mmi_umms_hint_user_defined_template);
   // SetHintHandler(MENU_ID_UMMS_TEMPLATES_DEFAULT, mmi_umms_hint_default_template);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_hint_user_defined_template
 * DESCRIPTION
 *  To construct hint popup for user defined template
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_hint_user_defined_template(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    sprintf((S8*) value, "%d ", mmi_umms_get_total_user_defined_template());
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2cat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID));
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_hint_default_template
 * DESCRIPTION
 *  To construct hint popup for default template
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_hint_default_template(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    sprintf((S8*) value, "%d ",MAX_PREDEFINED_TEMPLATE );
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2cat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID));
    return;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_templates_default
 * DESCRIPTION
 *  Highlight hdlr of default templates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_templates_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_default_template_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_default_template_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_default_template_screen, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_templates_user_defined
 * DESCRIPTION
 *  Highlight hdlr of user defined templates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_templates_user_defined(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_user_defined_template_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_user_defined_template_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_pre_entry_user_defined_template_screen, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_template_default_user_defined
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_template_default_user_defined(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;              /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item = 0;                   /* Stores no of children in the submenu */
	U8 *popUpList[MAX_SUB_MENUS];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED,
        NULL,
        mmi_umms_entry_template_default_user_defined,
        NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED);

    num_item = GetNumOfChild(MENU_ID_UM_TEMPLATE_MMS);
    GetSequenceStringIds(MENU_ID_UM_TEMPLATE_MMS, str_item_list);

    SetParentHandler(MENU_ID_UM_TEMPLATE_MMS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	ConstructHintsList(MENU_ID_UM_TEMPLATE_MMS, popUpList);
    ShowCategory52Screen(
        STR_ID_UMMS_TEMPLATES,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_default_template_screen
 * DESCRIPTION
 *  This is the mail entry function to Template module, when user enter Tempalte->MMS Template->default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_default_template_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_umms_context->default_creation_progress == FALSE)
    {

        mmi_umms_set_processing_screen(STR_ID_UMMS_TEMPLATES, STR_ID_UMMS_PLEASE_WAIT, IMG_GLOBAL_PROGRESS, 0);
        mmi_umms_entry_processing_generic();
        g_default_template_count = 0;   /* Make total template count 0 */
        mmi_umms_get_templates_num_req();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_PLEASE_WAIT),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_pre_entry_user_defined_template_screen
 * DESCRIPTION
 *  For user defined templates.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_pre_entry_user_defined_template_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_processing_screen(STR_ID_UMMS_TEMPLATES, STR_ID_UMMS_PLEASE_WAIT, IMG_GLOBAL_PROGRESS, 0);
    mmi_umms_entry_processing_generic();
     g_umms_context->current_msg_index = 0;
    mmi_umms_entry_templates(MMI_UMMS_USER_DEFINED_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_boot_up_file_format_generate_template
 * DESCRIPTION
 *  This function is called at the boot-up and when user format the file system.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_boot_up_file_format_generate_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_default_template_count = 0;
    g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_BACKGROUND;
    mmi_umms_templates_init();
    mmi_umms_get_templates_num_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_templates_num_req
 * DESCRIPTION
 *  This function sends the request to MMA, to get total number of MMSs present in the different folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_templates_num_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_req_struct *msgReq = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_get_msg_num_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_TEMPLATE;
    msgReq->msg_type = UM_MSG_TYPE_MMS;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (oslParaType*) msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_templates_num_rsp
 * DESCRIPTION
 *  The response handler for get number request. This function checks whether there is need to generate
 *  Templates or not.
 * PARAMETERS
 *  inMsg       [?]     [?]     Incoming structure for number response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_templates_num_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_rsp_struct *msg = (mmi_um_get_msg_num_rsp_struct*) inMsg;
    U16 language_change = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_get_templates_num_rsp predef templ=%d*\n",
                         msg->predefined_template_msg_number);
    if (msg->result)
    {
		U16 total_mms;

        total_mms = msg->inbox_unread_msg_number + msg->inbox_read_msg_number
            + msg->unsent_msg_number + msg->sent_msg_number + msg->draft_msg_number
            + msg->predefined_template_msg_number + msg->userdefined_template_msg_number;
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			total_mms = total_mms + msg->archive_msg_number;
		#endif 
  
        if(total_mms > (UMMS_MAX_POSSIBLE_MESSAGES - MAX_PREDEFINED_TEMPLATE))
		{
            DisplayPopup(
                (PU8) GetString(STR_ID_MMA_RESULT_FAIL_INSUFFICIENT_STORAGE),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
			DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
			return;
		}

        ReadValue(NVRAM_UMMS_LANGUAGE_CHANGE, &language_change, DS_SHORT, &error);

        if (language_change == 0xFFFF)
        {
            WriteValue(NVRAM_UMMS_LANGUAGE_CHANGE, &gCurrLangIndex, DS_SHORT, &error);
        }
/*
        else if (language_change != gCurrLangIndex)
        {
            WriteValue(NVRAM_UMMS_LANGUAGE_CHANGE, &gCurrLangIndex, DS_SHORT, &error);
        }
*/
        if (msg->predefined_template_msg_number < MAX_PREDEFINED_TEMPLATE || (language_change != gCurrLangIndex))
        {
            /* Need to generate Templates */
             g_umms_context->current_msg_index = 0;
            g_umms_context->default_creation_progress = TRUE;
              g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_FOREGROUND;
			mmi_umms_init_template_folder();
            mmi_umms_delete_all_template_req();
        }
        else
        {
            g_umms_context->default_creation_progress = FALSE;

            if (g_umms_context->state == MMI_UMMS_TEMPLATE_GEN_FOREGROUND)
            {
                g_umms_context->current_msg_index = 0;
                mmi_umms_entry_templates(MMI_UMMS_DEFAULT_TYPE);
                /* Show the template list */
            }
            else
            {
                g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_FOREGROUND;
            }
        }
    }
    else
    {
        if (g_umms_context->state == MMI_UMMS_TEMPLATE_GEN_FOREGROUND)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
			DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        }
        else
        {
            g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_FOREGROUND;
        }
    }
    if (language_change != gCurrLangIndex && !mmi_umms_is_usb_mode())
    {
        WriteValue(NVRAM_UMMS_LANGUAGE_CHANGE, &gCurrLangIndex, DS_SHORT, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_all_template_req
 * DESCRIPTION
 *  This function send the request to MMA, to delete all MMSs present in Template folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_all_template_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_um_delete_folder_req_struct *msgReq = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_delete_folder_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->msg_type = UM_MSG_TYPE_MMS;
    msgReq->msg_box_type = UM_MSG_BOX_TYPE_PREDEF_TEMPLATES;    // /*MMA_FOLDER_PREDEF_TEMPLATE*/MMA_FOLDER_TEMPLATE;
    msgReq->app_id = MMA_APP_ID_TEMPLATE;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_DELETE_FOLDER_REQ, (oslParaType*) msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_all_template_rsp
 * DESCRIPTION
 *  This is the response handler for Delete Request.
 * PARAMETERS
 *  inMsg       [?]     [?]     response structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_all_template_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_folder_rsp_struct *msg = (mmi_um_delete_folder_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_delete_all_template_rsp result=%d*\n", msg->result);
    if (msg->result)
    {
        /* Existing messages(if any) deleted successfully */
		if(g_umms_context->default_creation_progress == TRUE)
		{
			/* User has not pressed END key */
        mmi_umms_get_template_resource();
    }

    }
    else
    {
//        umms_mmi_show_template_error_msg((U8) msg->result);
		g_umms_context->default_creation_progress = FALSE;
       if (mmi_umms_is_usb_mode())
        {
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
								 "*[MMSMessageTemplates.c] mmi_umms_delete_all_template_rsp remove usb");

		   DisplayPopup(
                (PU8) GetString(STR_ID_UMMS_TEMPLATE_REMOVE_USB),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }
        else
        {
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
								 "*[MMSMessageTemplates.c] mmi_umms_delete_all_template_rsp r");

            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }
		 DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_template_resource
 * DESCRIPTION
 *  This function provide the MMS content (Image,string) to generate Template MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_template_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img_buff_p = NULL;
    S8 *title = NULL;
    U32 audio_len = 0;
    //U32 image_len = 0;
    U8 *audio_buff = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_default_template_count >= MAX_PREDEFINED_TEMPLATE)
    {
        MMI_ASSERT(0);
    }

    title = (S8*) GetString(mms_templates[g_default_template_count].strId);
    img_buff_p = (PU8) GetImage((U16) (mms_templates[g_default_template_count].imageId));
    audio_len =  resource_mms_sounds[mms_templates[g_default_template_count].audioId].len; 
    audio_buff = (U8*) (resource_mms_sounds[mms_templates[g_default_template_count].audioId].data); 

    mmi_umms_start_generate_template_xml(
        title,
        (U16) (mms_templates[g_default_template_count].imageId),
        audio_buff,
        audio_len);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_create_template_req
 * DESCRIPTION
 *  This function send the request to MMA to generate MMS, for which it sends the content of MMS in XML
 *  format.
 * PARAMETERS
 *  template_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_create_template_req(mmi_umms_templates_type_enum template_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *msg_req = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    U32 read_size = 0;
    U16 peer_buff_len = 0;
    FS_HANDLE file_handl = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));


    msg_req->msg_id = 0;
    msg_req->app_id = MMA_APP_ID_TEMPLATE;

    if (template_type == MMI_UMMS_DEFAULT_TYPE)
    {
        g_umms_context->default_mms_creation.request_id = wap_mma_get_request_id();
        msg_req->req_id = g_umms_context->default_mms_creation.request_id;
		msg_req->mode = MMA_MODE_EDIT;
        mmi_ucs2cpy((PS8) msg_req->xml_filepath, (PS8) g_umms_context->default_mms_creation.file_path);

        msg_req->xml_size = g_umms_context->default_mms_creation.xml_file_size
            = applib_get_file_size(msg_req->xml_filepath);

        msg_req->buffer_index = g_umms_context->default_mms_creation.buffer_index = 0;

        g_umms_context->default_mms_creation.file_handle = FS_Open(msg_req->xml_filepath, FS_READ_ONLY);
        file_handl = g_umms_context->default_mms_creation.file_handle;

    }
    else if (template_type == MMI_UMMS_USER_DEFINED_TYPE)
    {
        g_user_defined_create.request_id = wap_mma_get_request_id();
        msg_req->req_id = g_user_defined_create.request_id;
		msg_req->mode = MMA_MODE_UPLOAD;
		mmi_ucs2cpy((PS8) msg_req->msg_file_path, (PS8) g_user_defined_create.file_path);

        msg_req->xml_size = 0;

        msg_req->buffer_index = g_user_defined_create.buffer_index = 0;

		 msg_req->more = KAL_FALSE;
		 mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CREATE_REQ, (oslParaType*) msg_req, NULL);
		return;
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (file_handl < 0)
    {
        umms_mmi_show_template_error_msg(MMA_RESULT_FAIL);        
        StopTimer(UMMS_INPROGRESS_TIMER_ID);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_template_msg();
        return;
        //MMI_ASSERT(0);
    }

    if (msg_req->xml_size <= MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER)
    {
        msg_req->buffer_size = msg_req->xml_size;
        msg_req->more = KAL_FALSE;
    }
    else
    {
        msg_req->buffer_size = MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER;
        msg_req->more = KAL_TRUE;
    }

    peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);
    if (FS_Read
        (file_handl, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size,
         &read_size) != FS_NO_ERROR || read_size != msg_req->buffer_size)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSMessageTemplates.c] mmi_umms_create_mms_req read_size=%d buf_size=%d*\n",
                             read_size, msg_req->buffer_size);
    }

    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CREATE_REQ, (oslParaType*) msg_req, peer_buff_ptr);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_template_mms_rsp
 * DESCRIPTION
 *  This function is response handler for create request
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_create_template_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_send_create_template_rsp result=%d,buffer_index=%d *\n",
                         msg_rsp->result, msg_rsp->buffer_index);

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        if (msg_rsp->req_id == g_umms_context->default_mms_creation.request_id)
        {
            umms_mmi_show_template_error_msg(msg_rsp->result);
            FS_Close(g_umms_context->default_mms_creation.file_handle);
            StopTimer(UMMS_INPROGRESS_TIMER_ID);
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            mmi_umms_reset_template_msg();
			if(msg_rsp->result != MMA_RESULT_FAIL_IN_USB_MODE)
			{
			mmi_umms_delete_template_req(0xffffffff, MMA_FOLDER_TEMPLATE);
			}
            return;
        }
        else if (msg_rsp->req_id == g_user_defined_create.request_id)
        {
            FS_Close(g_user_defined_create.file_handle);
            /* TBD : Delete this file here */
            if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            {
                
                mmi_umms_show_error_pop_up(msg_rsp->result);
                DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            }
            else
            {
               mmi_umms_delete_umms_screens(); 
				//mmi_umms_go_to_box_list_screen();
            }
            return;

        }
        else
        {
            MMI_ASSERT(0);
        }

        /* reset state, release all resourses */
    }
    else
    {
        if (msg_rsp->msg_id == 0)
        {
            wap_mma_create_req_struct *msg_req;
            peer_buff_struct *peer_buff_ptr;
            U32 read_size = 0;
            S32 remaining_size = 0;
            U16 peer_buff_len = 0;
            FS_HANDLE file_hdl = 0;

            msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));

            msg_req->app_id = MMA_APP_ID_TEMPLATE;
            /* reset */
            msg_req->mode = MMA_MODE_EDIT;
            msg_req->msg_id = 0;

            if (msg_rsp->req_id == g_umms_context->default_mms_creation.request_id)
            {
                MMI_ASSERT(msg_rsp->buffer_index == g_umms_context->default_mms_creation.buffer_index + 1);
                msg_req->req_id = g_umms_context->default_mms_creation.request_id;
                mmi_ucs2cpy((S8*) msg_req->xml_filepath, (S8*) g_umms_context->default_mms_creation.file_path);
                msg_req->xml_size = g_umms_context->default_mms_creation.xml_file_size;
                g_umms_context->default_mms_creation.buffer_index++;
                msg_req->buffer_index = g_umms_context->default_mms_creation.buffer_index;

                remaining_size = g_umms_context->default_mms_creation.xml_file_size -
                    (msg_req->buffer_index * MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER);

                file_hdl = g_umms_context->default_mms_creation.file_handle;
            }
            else if (msg_rsp->req_id == g_user_defined_create.request_id)
            {
                MMI_ASSERT(msg_rsp->buffer_index == g_user_defined_create.buffer_index + 1);
                msg_req->req_id = g_user_defined_create.request_id;
                mmi_ucs2cpy((S8*) msg_req->xml_filepath, (S8*) g_user_defined_create.file_path);
                msg_req->xml_size = g_user_defined_create.xml_file_size;
                g_user_defined_create.buffer_index++;
                msg_req->buffer_index = g_user_defined_create.buffer_index;

                remaining_size = g_user_defined_create.xml_file_size -
                    (msg_req->buffer_index * MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER);

                file_hdl = g_user_defined_create.file_handle;
            }
            else
            {
                MMI_ASSERT(0);
            }

            /* common code */
            if (remaining_size <= MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER)
            {
                msg_req->buffer_size = remaining_size;
                msg_req->more = KAL_FALSE;
            }
            else
            {
                msg_req->buffer_size = MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER;
                msg_req->more = KAL_TRUE;
            }

            peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);

            if (FS_Read
                (file_hdl, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size,
                 &read_size) != FS_NO_ERROR || read_size != msg_req->buffer_size)
            {

                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[MMSMessageTemplate.c] mmi_umms_create_mms_rsp read_size=%d buf_size=%d*\n",
                                     read_size, msg_req->buffer_size);
            }

            mmi_umms_send_message(
                MOD_MMI,
                MOD_WAP,
                0,
                MSG_ID_WAP_MMA_CREATE_REQ,
                (oslParaType*) msg_req,
                peer_buff_ptr);

        }
        /* sending XML content completes */
        else
        {
            if (msg_rsp->req_id == g_umms_context->default_mms_creation.request_id)
            {
                FS_Close(g_umms_context->default_mms_creation.file_handle);
				if(g_umms_context->default_creation_progress == FALSE)
				{
					/* Stop creation process */
					/* delete just created MMS */
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*[MMSMessageTemplates.c] Stop Creation : mmi_umms_send_create_template_rsp  *\n"
                     );
					if(msg_rsp->result != MMA_RESULT_FAIL_IN_USB_MODE)
					{
					mmi_umms_delete_template_req(0xffffffff, MMA_FOLDER_TEMPLATE);
					mmi_umms_delete_template_req(msg_rsp->msg_id, 0);
					}
					return;
				}
                mmi_umms_save_template_mms_req((U16) msg_rsp->msg_id, (U16) MMA_FOLDER_TEMPLATE);

            }
            else if (msg_rsp->req_id == g_user_defined_create.request_id)
            {
                FS_Close(g_user_defined_create.file_handle);
                mmi_umms_save_template_mms_req((U16) msg_rsp->msg_id, (U16) MMA_FOLDER_USRDEF_TEMPLATE);
            }
            else
            {
                MMI_ASSERT(0);
            }
        }

    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_template_mms_req
 * DESCRIPTION
 *  This functin sends the save request for the MMS,whose content has been sent to MMA in create request.
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg_box     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_template_mms_req(const U16 msg_id, const U16 msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *msg_req = NULL;
    U32 temp_request_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_request_id = wap_mma_get_request_id();

    if (msg_box == MMA_FOLDER_TEMPLATE)
    {
        g_umms_context->default_mms_creation.request_id = temp_request_id;
    }
    else if (msg_box == MMA_FOLDER_USRDEF_TEMPLATE)
    {
        g_user_defined_create.request_id = temp_request_id;
    }
    else
    {
        MMI_ASSERT(0);
    }

    msg_req = (wap_mma_save_req_struct*) OslConstructDataPtr(sizeof(wap_mma_save_req_struct));
    msg_req->req_id = temp_request_id;
    msg_req->msg_id = msg_id;
    msg_req->box = msg_box;
    msg_req->app_id = MMA_APP_ID_TEMPLATE;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SAVE_REQ, (oslParaType*) msg_req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_template_mms_rsp
 * DESCRIPTION
 *  Save MMS msg response
 * PARAMETERS
 *  in_msg      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_template_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_save_template_mms_rsp result=%d *\n", msg_rsp->result);

    /* MMI_ASSERT(g_umms_context->request_id == msg_rsp->req_id); */

    if (msg_rsp->req_id == g_user_defined_create.request_id)
    {
        /* return to rajat */
        if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
        {
            /* TBD : Delete user defined file here  */
            mmi_umms_show_error_pop_up(msg_rsp->result);
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            if (msg_rsp->result != MMA_RESULT_OK)
            {
				if(msg_rsp->result != MMA_RESULT_FAIL_IN_USB_MODE)
				{
                mmi_umms_delete_template_req(msg_rsp->msg_id, 0);
            }
        }
        }

        mmi_umms_delete_umms_screens();
        mmi_umms_update_status_icon_indicator();
        return;
    }
    else if (msg_rsp->req_id == g_umms_context->default_mms_creation.request_id)
    {

		if(g_umms_context->default_creation_progress == FALSE || msg_rsp->result != MMA_RESULT_OK)
		{
			/* Stop creation process */
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*[MMSMessageTemplates.c] Stop Creation : mmi_umms_save_template_mms_rsp  *\n"
                     );
            umms_mmi_show_template_error_msg(msg_rsp->result);
			if(msg_rsp->result != MMA_RESULT_FAIL_IN_USB_MODE)
			{
			mmi_umms_delete_template_req(0xffffffff, MMA_FOLDER_TEMPLATE);
            mmi_umms_delete_template_req(msg_rsp->msg_id, 0);
		}      		
		}      		
		else  if (msg_rsp->result == MMA_RESULT_OK)
        {
            g_default_template_count++;
            if (g_default_template_count < MAX_PREDEFINED_TEMPLATE)
            {
                mmi_umms_reset_template_msg();
                mmi_umms_get_template_resource();
                return;
            }
            else
            {
                g_umms_context->default_creation_progress = FALSE;
                if (g_umms_context->state == MMI_UMMS_TEMPLATE_GEN_FOREGROUND)
                {
                    /* Entry into template,if not from boot-up */
                    mmi_umms_entry_templates(MMI_UMMS_DEFAULT_TYPE);

                }
                else
                {
                    g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_FOREGROUND;
                }
            }

        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_umms_reset_template_msg();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_template_req
 * DESCRIPTION
 *  Delete Req to MMA.
 * PARAMETERS
 *  msg_id          [IN]        
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_template_req(const U32 msg_id, const mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *req;
  //  mma_folder_enum box_id = MMA_FOLDER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSMessageTemplates.c] mmi_umms_delete_template_req \n");

    req = (wap_mma_delete_req_struct*) OslConstructDataPtr(sizeof(wap_mma_delete_req_struct));
    req->app_id = MMA_APP_ID_TEMPLATE;
    req->req_id = wap_mma_get_request_id();
    req->msg_id = msg_id;
    req->box = folder_id;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_DELETE_REQ, (oslParaType*) req, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_template_rsp
 * DESCRIPTION
 *  Response function for template delete
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_template_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_rsp->result != MMA_RESULT_OK)
    {
	    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_delete_template_rsp: DELETE FAIL:%d*\n", msg_rsp->result);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_templates
 * DESCRIPTION
 *  This function is called after all templates have been generated.
 * PARAMETERS
 *  template_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_templates(mmi_umms_templates_type_enum template_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ummi_get_template_list_info_req(template_type);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ummi_get_template_list_info_req
 * DESCRIPTION
 *  This function is called after all templates have been generated, to get the idices of the messages prsent.
 * PARAMETERS
 *  template_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ummi_get_template_list_info_req(mmi_umms_templates_type_enum template_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_list_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_get_list_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->msg_type = UM_MSG_TYPE_MMS;

    if (template_type == MMI_UMMS_DEFAULT_TYPE)
    {
        msgReq->msg_box_type = UM_MSG_BOX_TYPE_PREDEF_TEMPLATES;        // /*MMA_FOLDER_PREDEF_TEMPLATE*/MMA_FOLDER_TEMPLATE;   /* default folder  */
    }
    else
    {
        msgReq->msg_box_type = UM_MSG_BOX_TYPE_USRDEF_TEMPLATES;        // MMA_FOLDER_USRDEF_TEMPLATE;   /* user defined folder */
    }
    msgReq->start_entry = 0;
    msgReq->app_id = MMA_APP_ID_TEMPLATE;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_LIST_REQ, (oslParaType*) msgReq, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ummi_get_template_list_info_rsp
 * DESCRIPTION
 *  This function is response handler for get list request
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ummi_get_template_list_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_list_rsp_struct *msg = (mmi_um_get_list_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_ummi_get_template_list_info_rsp result=%d *\n", msg->result);
    if (msg->result)
    {
        if (msg->msg_number)
        {
            g_umms_context->msg_list_index = msg->list_info[0].msg_index;
            mmi_ummi_get_template_message_info_req(msg->msg_box_type);
        }
        else
        {
            if ((GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                && (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED) == TRUE))
            {
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_EMPTY),
					IMG_GLOBAL_EMPTY,
					1,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) EMPTY_LIST_TONE);
            }
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);

            return;
        }
    }
    else
    {
        if ((GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            && (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED) == TRUE))
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ummi_get_template_message_info_req
 * DESCRIPTION
 *  This function send the request to MMA, to get the message detail of MMSs present in Template folder
 * PARAMETERS
 *  box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ummi_get_template_message_info_req(S32 box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_info_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_get_msg_info_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->msg_type = UM_MSG_TYPE_MMS;

    msgReq->msg_box_type = box_type;    

    if (box_type == UM_MSG_BOX_TYPE_PREDEF_TEMPLATES)
    {
        msgReq->msg_number = MAX_PREDEFINED_TEMPLATE;
    }
    else if (box_type == UM_MSG_BOX_TYPE_USRDEF_TEMPLATES)
    {
        msgReq->msg_number = MAX_USERDEF_TEMPLATE;
    }
    else
    {
        MMI_ASSERT(0);
    }

    msgReq->start_entry = g_umms_context->msg_list_index;

    msgReq->app_id = MMA_APP_ID_TEMPLATE;
    mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_MSG_INFO_REQ, (oslParaType*) msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ummi_get_template_message_info_rsp
 * DESCRIPTION
 *  This function filles the message detail to global structures, which is used to show the list in UI.
 * PARAMETERS
 *  inMsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ummi_get_template_message_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
 //   S32 index_tail = 0;
    mmi_um_get_msg_info_rsp_struct *msg = (mmi_um_get_msg_info_rsp_struct*) inMsg;

    g_template_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_ummi_get_template_message_info_rsp result=%d,pred_num =%d *\n",
                         msg->result, msg->msg_number);

    if (msg->result)
    {
        g_template_count = msg->msg_number;

        if (g_template_count == 0)
        {

            if ((GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
                && (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED) == TRUE))
            {
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_EMPTY),
					IMG_GLOBAL_EMPTY,
					1,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) EMPTY_LIST_TONE);
            }
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);

            return;
        }

        g_msg_info_tpl_struct =
            (mmi_um_msg_info_struct*) umms_malloc(sizeof(mmi_um_msg_info_struct) * msg->msg_number);

        MMI_ASSERT(g_msg_info_tpl_struct != NULL);

        memset(g_msg_info_tpl_struct, 0, sizeof(mmi_um_msg_info_struct) * msg->msg_number);
        for (index = 0 ; index < msg->msg_number; index++ )
        {
            g_msg_info_tpl_struct[index].msg_index = msg->msg_info[index].msg_index;
            g_msg_info_tpl_struct[index].timestamp = msg->msg_info[index].timestamp;
            g_msg_info_tpl_struct[index].address_type = msg->msg_info[index].address_type;

            if (msg->msg_info[index].address_length > 0)
            {
                g_msg_info_tpl_struct[index].address_length = msg->msg_info[index].address_length;
                mmi_ucs2ncpy(
                    (S8*) g_msg_info_tpl_struct[index].address,
                    (S8*) msg->msg_info[index].address,
                    msg->msg_info[index].address_length);

            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) g_msg_info_tpl_struct[index].address,
                    (S8*) GetString(STR_OUTBOX_LIST_MESSAGE),
                    MMI_UM_MAX_SUBJECT_LEN);
                g_msg_info_tpl_struct[index].address_length = mmi_ucs2strlen((S8*) GetString(STR_OUTBOX_LIST_MESSAGE));
            }

            if (msg->msg_info[index].subject_length > 0)
            {
                g_msg_info_tpl_struct[index].subject_length = msg->msg_info[index].subject_length;
                mmi_ucs2ncpy(
                    (S8*) g_msg_info_tpl_struct[index].subject,
                    (S8*) msg->msg_info[index].subject,
                    msg->msg_info[index].subject_length);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) g_msg_info_tpl_struct[index].subject,
                    (S8*) GetString(STR_UM_EMPTY_SUBJECT_ID),
                    MMI_UM_MAX_SUBJECT_LEN);
                g_msg_info_tpl_struct[index].subject_length = mmi_ucs2strlen((S8*) GetString(STR_UM_EMPTY_SUBJECT_ID));
            }

            g_msg_info_tpl_struct[index].icon_id = msg->msg_info[index].icon_id;

        }
        if (msg->msg_box_type == UM_MSG_BOX_TYPE_PREDEF_TEMPLATES)
        {
            g_template_type = MMI_UMMS_DEFAULT_TYPE;
        }
        else if (msg->msg_box_type == UM_MSG_BOX_TYPE_USRDEF_TEMPLATES)
        {
            g_template_type = MMI_UMMS_USER_DEFINED_TYPE;
        }
        else
        {
            MMI_ASSERT(0);
        }
        mmi_umms_entry_templates_screen();
    }
    else
    {
        if ((GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            && (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED) == TRUE))
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

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_templates_screen
 * DESCRIPTION
 *  This is entry function to show template list in UI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_templates_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_strid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UMMS_PROGRESS))
    {
        HistoryReplace(SCR_ID_UMMS_PROGRESS, SCR_ID_UMMS_TEMPLATES, mmi_umms_entry_templates_screen);
        return;
    }

    if (g_msg_info_tpl_struct == NULL)
    {
        /* coming back from history */
        if (GetCurrGuiBuffer(SCR_ID_UMMS_TEMPLATES) == NULL)
        {
            mmi_umms_set_processing_screen(STR_ID_UMMS_TEMPLATES, STR_ID_UMMS_PLEASE_WAIT, IMG_GLOBAL_PROGRESS, 0);
            mmi_umms_entry_processing_generic();
        }
		/* Rajat Added Here for Single Delete of USer Defined Template */
		if(GetActiveScreenId() != SCR_ID_UMMS_PROGRESS)
		{
			mmi_umms_set_processing_screen(STR_ID_UMMS_TEMPLATES, STR_ID_UMMS_PLEASE_WAIT, IMG_GLOBAL_PROGRESS, 0);
			mmi_umms_entry_processing_generic();
		}
        mmi_ummi_get_template_list_info_req(g_template_type);
        return;
    }

    if ((GetActiveScreenId() != SCR_ID_UMMS_PROGRESS)
        && (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED) == FALSE))
    {
        /* this function is called from idle screen  */
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSMessageTemplate.c] mmi_umms_entry_template_screen discard response *\n");
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        if (g_msg_info_tpl_struct)
        {
            umms_free(g_msg_info_tpl_struct);
            g_msg_info_tpl_struct = NULL;
        }
        return;
    }

    if (g_template_count)
    {

        EntryNewScreen(SCR_ID_UMMS_TEMPLATES, mmi_umms_exit_template_screen, mmi_umms_entry_templates_screen, NULL);

        /* Back from history */

        /* guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_TEMPLATES); */
        if (g_template_type == MMI_UMMS_DEFAULT_TYPE)
        {
            title_strid = STR_ID_UMMS_TEMPLATE_DEFAULT;
        }
        else
        {
            title_strid = STR_ID_UMMS_TEMPLATE_USER_DEFINED;
        }

        RegisterHighlightHandler(mmi_umms_template_hilite_folder_item);

        ShowCategory184Screen(
            title_strid,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
#else
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
#endif
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_template_count,
            mmi_umms_get_item_data_templates,
            0,
            g_umms_context->current_msg_index,
            NULL);

        SetLeftSoftkeyFunction(mmi_umms_entry_templates_options_msg_id, KEY_EVENT_UP);
        SetKeyHandler(mmi_umms_entry_templates_options_msg_id, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {

				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_EMPTY),
					IMG_GLOBAL_EMPTY,
					1,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) EMPTY_LIST_TONE);

    }

    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_template_state_on_end_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_template_state_on_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Stop creation process */
	g_umms_context->default_creation_progress = FALSE;
	g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_BACKGROUND;

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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_templates_options_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_templates_options_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_template_type == MMI_UMMS_DEFAULT_TYPE)
    {
        wap_um_entry_msg_mms(UM_MSG_BOX_TYPE_PREDEF_TEMPLATES, (U16)((g_template_count - 1 ) - g_umms_context->current_msg_index));
    }
    else
    {
        wap_um_entry_msg_mms(UM_MSG_BOX_TYPE_USRDEF_TEMPLATES, (U16)((g_template_count - 1 ) - g_umms_context->current_msg_index));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_templates_options_screen
 * DESCRIPTION
 *  Entry fn for templates options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_templates_options_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;              /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UMMS_PROGRESS))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_UMMS_TEMPLATES_OPTIONS, mmi_umms_entry_templates_options_screen);
        return;
    }
    EntryNewScreen(SCR_ID_UMMS_TEMPLATES_OPTIONS, NULL, mmi_umms_entry_templates_options_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_TEMPLATES_OPTIONS);
    SetParentHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS);
    if (g_template_type == MMI_UMMS_DEFAULT_TYPE)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_TEMPLATES_OPTIONS_DELETE_ALL);
    }

    num_item = GetNumOfChild_Ext(MENU_ID_UMMS_TEMPLATES_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_UMMS_TEMPLATES_OPTIONS, str_item_list);

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
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_item_data_templates
 * DESCRIPTION
 *  This functions provide the list items to UI
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_umms_get_item_data_templates(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_PREDEFINED_TEMPLATE))
    {
        return FALSE;
    }

    if (g_msg_info_tpl_struct[item_index].subject_length)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) g_msg_info_tpl_struct[item_index].subject);
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_ID_UMMS_NO_SUBJECT));
    }

    *img_buff_p = (PU8) GetImage((U16) g_msg_info_tpl_struct[item_index].icon_id);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_exit_template_screen
 * DESCRIPTION
 *  This functions is exit function for template list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_exit_template_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_info_tpl_struct)
    {
        umms_free(g_msg_info_tpl_struct);
        g_msg_info_tpl_struct = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_template_hilite_folder_item
 * DESCRIPTION
 *  This functions is highlight function for list item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_template_hilite_folder_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_context->current_msg_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_start_generate_template_xml
 * DESCRIPTION
 *  This function generate the XML.
 * PARAMETERS
 *  subject         [IN]        [?]         [?]         [?]
 *  image_buff      [IN]        [?]         [?]         [?]
 *  image_len       [IN]        
 *  audio_buff      [IN]        [?]         [?]         [?]
 *  audio_len       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_start_generate_template_xml(
    const S8 *subject,
    const U16 image_id,
    const U8 *audio_buff,
    const U32 audio_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result = FS_NO_ERROR;
    mmi_umms_slide_struct *temp_slide_head = NULL;
    mmi_umms_object_struct *obj_head = NULL, *image_obj = NULL, *text_obj = NULL, *audio_obj = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_umms_context->default_mms_creation.file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    UMMS_MMI_MAKE_MMS_TEMPLATE_XML_FILE_PATH(g_umms_context->default_mms_creation.file_path, MMI_UMMS_DEFAULT_TYPE);
    g_mms_xml_msg = (mmi_umms_xml_msg_struct*) umms_malloc(sizeof(mmi_umms_xml_msg_struct));

    MMI_ASSERT(g_mms_xml_msg != NULL);

    memset(g_mms_xml_msg, 0, sizeof(mmi_umms_xml_msg_struct));

    g_mms_xml_msg->background_color = UMMS_MMI_DEFAULT_BG_COLOR;
    g_mms_xml_msg->foreground_color = UMMS_MMI_DEFAULT_FG_COLOR;
    g_mms_xml_msg->to_head = NULL;
    g_mms_xml_msg->cc_head = NULL;
    g_mms_xml_msg->bcc_head = NULL;
    g_mms_xml_msg->from = NULL;
    memset(g_mms_xml_msg->subject, 0, (UMMS_MMI_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) g_mms_xml_msg->subject, subject);

    g_mms_xml_msg->to_num = 0;
    g_mms_xml_msg->cc_num = 0;
    g_mms_xml_msg->bcc_num = 0;
    g_mms_xml_msg->read_report = UMMS_DEFAULT_READ_REPORT_DURING_SENDING;
    g_mms_xml_msg->delivery_report = UMMS_DEFAULT_DELIVERY_REPORT_DURING_SENDING;
    g_mms_xml_msg->priority = UMMS_DEFAULT_PRIORITY;
    g_mms_xml_msg->expiry_time = UMMS_DEFAULT_EXPIRY_TIME;
    g_mms_xml_msg->sender_visibility = UMMS_DEFAULT_SENDER_VISIBILTY;
    g_mms_xml_msg->delivery_time = UMMS_DEFAULT_DELIVERY_TIME;

    g_mms_xml_msg->slide_head = (mmi_umms_slide_struct*) umms_malloc(sizeof(mmi_umms_slide_struct));

    MMI_ASSERT(g_mms_xml_msg->slide_head != NULL);

    memset(g_mms_xml_msg->slide_head, 0, sizeof(mmi_umms_slide_struct));

    temp_slide_head = g_mms_xml_msg->slide_head;

    g_mms_xml_msg->slide_head->next = NULL;
    g_mms_xml_msg->slide_head->duration = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);
    g_mms_xml_msg->slide_head->slide_num = 1;

    /* make object list */
    obj_head = (mmi_umms_object_struct*) umms_malloc(sizeof(mmi_umms_object_struct));

    MMI_ASSERT(obj_head != NULL);

    memset(obj_head, 0, sizeof(mmi_umms_object_struct));

    image_obj = obj_head;
    image_obj->previous = NULL;
    /* make image object */

    image_obj->file_path = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);

	MMI_ASSERT(image_obj->file_path != NULL);

    image_obj->file_name = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
	MMI_ASSERT(image_obj->file_name != NULL);

    if(mmi_fill_image_data(image_obj, image_id) == FALSE)
	{
		return FALSE;
	}
    image_obj->size = applib_get_file_size((kal_wchar*) image_obj->file_path);
    /* put image data in a file */
    image_obj->id = 1;
    image_obj->reference_count = 1;
    image_obj->type = MMI_UMMS_OBJECT_TYPE_IMAGE;
    image_obj->drm_type = MMA_DRM_NONE;
    image_obj->is_virtual_file = 0;


    /* make text object  */

    image_obj->next = (mmi_umms_object_struct*) umms_malloc(sizeof(mmi_umms_object_struct));
	MMI_ASSERT(image_obj->next != NULL);
   memset(image_obj->next, 0, sizeof(mmi_umms_object_struct));
    text_obj = image_obj->next;
    text_obj->previous = image_obj;
 //   text_obj->next = NULL;


    text_obj->file_path = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
    MMI_ASSERT(text_obj->file_path != NULL);

    UMMS_MMI_MAKE_TEMPLATE_TEXT_FILE_PATH(text_obj->file_path, 0);
    text_obj->file_name = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
    MMI_ASSERT(text_obj->file_name != NULL);
    mmi_asc_to_ucs2((S8*) text_obj->file_name, (S8*) UMMS_TEMPLATE_TEXT_FILE);

    if(mmi_template_fill_text_data(text_obj->file_path, g_mms_xml_msg->subject) == FALSE)
	{
		return FALSE;
	}
    text_obj->size = applib_get_file_size((kal_wchar*) text_obj->file_path);

    /* put text data in a file */
    text_obj->id = 2;
    text_obj->reference_count = 1;
    text_obj->type = MMI_UMMS_OBJECT_TYPE_TEXT;
    text_obj->drm_type = MMA_DRM_NONE;
    text_obj->is_virtual_file = 0;

	/* make audio object */
    text_obj->next = (mmi_umms_object_struct*) umms_malloc(sizeof(mmi_umms_object_struct));
	MMI_ASSERT(text_obj->next != NULL);
	memset(text_obj->next, 0, sizeof(mmi_umms_object_struct));



    audio_obj = text_obj->next;
    audio_obj->previous = text_obj;
	audio_obj->next = NULL;

    audio_obj->file_path = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);

	MMI_ASSERT(audio_obj->file_path != NULL);

    audio_obj->file_name = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
	MMI_ASSERT(audio_obj->file_name != NULL);

    audio_obj->id = 3;
    audio_obj->reference_count = 1;
    audio_obj->type = MMI_UMMS_OBJECT_TYPE_AUDIO;
    audio_obj->drm_type = MMA_DRM_NONE;
    audio_obj->is_virtual_file = 0;
	/* put audio buffer in file */
	if(mmi_template_fill_audio_data(audio_obj, audio_buff, audio_len) == FALSE)
	{
		return FALSE;
	}
	audio_obj->size = applib_get_file_size((kal_wchar*) audio_obj->file_path);
	/* add text object in slide */
    memset(&g_mms_xml_msg->slide_head->text, 0, sizeof(mmi_umms_text_object_info_struct));
    g_mms_xml_msg->slide_head->text.background_color = UMMS_MMI_DEFAULT_BG_COLOR;
    g_mms_xml_msg->slide_head->text.foreground_color = UMMS_MMI_DEFAULT_FG_COLOR;
    g_mms_xml_msg->slide_head->text.object = text_obj;

    g_mms_xml_msg->slide_head->text.begin = 0;
    g_mms_xml_msg->slide_head->text.end = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);

	/* add image object in slide */
    memset(&g_mms_xml_msg->slide_head->image, 0, sizeof(mmi_umms_object_info_struct));
    g_mms_xml_msg->slide_head->image.object = image_obj;
	
	g_mms_xml_msg->slide_head->image.begin = 0;
	g_mms_xml_msg->slide_head->image.end = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);

	/* add audio object in slide */
    memset(&g_mms_xml_msg->slide_head->audio, 0, sizeof(mmi_umms_object_info_struct));
    g_mms_xml_msg->slide_head->audio.object = audio_obj;
	
	g_mms_xml_msg->slide_head->audio.begin = 0;
	g_mms_xml_msg->slide_head->audio.end = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);

    g_mms_xml_msg->current_slide = NULL;
    g_mms_xml_msg->object_head = obj_head;
    g_mms_xml_msg->attachment_head = NULL;
    g_mms_xml_msg->slide_timing = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);
    g_mms_xml_msg->total_slide_num = 1;

    g_mms_xml_msg->total_object_num = 3;
 
    g_mms_xml_msg->total_attachment_num = NULL;
    g_mms_xml_msg->layout = MMA_LAYOUT_TEXT_ON_TOP;

    result = mmi_umms_create_mms_xml_description_file(g_mms_xml_msg, g_umms_context->default_mms_creation.file_path);
	if(result != FS_NO_ERROR)
	{
	   PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*[MMSMessageTemplates.c]mmi_umms_start_generate_template_xml:%d *\n",result);
//		umms_mmi_show_template_error_msg(MMA_RESULT_FAIL);        
//		GetFileSystemErrorString(handle))
       DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        StopTimer(UMMS_INPROGRESS_TIMER_ID);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_template_msg();
        return FALSE;
	}
    mmi_umms_send_create_template_req(MMI_UMMS_DEFAULT_TYPE);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_template_msg
 * DESCRIPTION
 *  This functions reset the resourses held by xml generation process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_template_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S32 result = 0;
    mmi_umms_slide_struct *slide = NULL;
    mmi_umms_slide_struct *curr_slide = NULL;
    U8 xml_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide = g_mms_xml_msg->slide_head;

    while (slide)
    {
        if (slide->text.object)
        {
            if (slide->text.object->file_path)
            {
                FS_Delete(slide->text.object->file_path);
                umms_free(slide->text.object->file_path);
                slide->text.object->file_path = NULL;
            }
            if (slide->text.object->file_name)
            {
                umms_free(slide->text.object->file_name);
                slide->text.object->file_name = NULL;
            }
            umms_free(slide->text.object);
            slide->text.object = NULL;

        }
        if (slide->image.object)
        {
            if (slide->image.object->file_path)
            {
                FS_Delete(slide->image.object->file_path);
                umms_free(slide->image.object->file_path);
                slide->image.object->file_path = NULL;
            }
            if (slide->image.object->file_name)
            {
                umms_free(slide->image.object->file_name);
                slide->image.object->file_name = NULL;
            }
            umms_free(slide->image.object);
            slide->image.object = NULL;

        }
        if (slide->audio.object)
        {
            if (slide->audio.object->file_path)
            {
                FS_Delete(slide->audio.object->file_path);
                umms_free(slide->audio.object->file_path);
                slide->audio.object->file_path = NULL;
            }
            if (slide->audio.object->file_name)
            {
                umms_free(slide->audio.object->file_name);
                slide->audio.object->file_name = NULL;
            }
            umms_free(slide->audio.object);
            slide->audio.object = NULL;

        }
        curr_slide = slide;
        slide = slide->next;
        umms_free(curr_slide);
        curr_slide = NULL;

    }
    umms_free(g_mms_xml_msg);
    g_mms_xml_msg = NULL;

    UMMS_MMI_MAKE_MMS_TEMPLATE_XML_FILE_PATH(xml_file_path, MMI_UMMS_DEFAULT_TYPE);
    FS_Delete((U16*) xml_file_path);

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
 *  mmi_fill_image_data
 * DESCRIPTION
 *  This function fills the image data in a file.
 * PARAMETERS
 *  image_obj       [?]     [?]
 *  image_buff      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fill_image_data(mmi_umms_object_struct *image_obj, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_length = 0;
    S8 file_name[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    S8 file_ext[12];
    FS_HANDLE file_handle;
    U32 write_len = 0;
    U8 *image_buff = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(file_name, "image0");
    image_buff = gdi_image_get_buf_ptr_from_id(image_id); /*GH*/
    image_length = gdi_image_get_buf_len_from_id(image_id); /*GH*/

    if(image_buff == NULL || image_length == 0)
    {
	MMI_ASSERT(0);
    }

    switch (gdi_image_get_type_from_id(image_id))
    {
        case GDI_IMAGE_TYPE_GIF:
            strcpy(file_ext, ".gif");
            break;
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
            strcpy(file_ext, ".jpg");
            break;
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
            strcpy(file_ext, ".png");
            break;
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
            strcpy(file_ext, ".bmp");
            break;
        case GDI_IMAGE_TYPE_BMP:
            strcpy(file_ext, ".bmp");
            break;
        case GDI_IMAGE_TYPE_JPG:
            strcpy(file_ext, ".jpg");
            break;
    }

    strcat(file_name, file_ext);
    mmi_asc_to_ucs2((S8*) image_obj->file_name, (S8*) file_name);
    /* mmi_asc_to_ucs2((S8*)image_obj->file_path,(S8*)"D:\\_UC\\"); */
    UMMS_MMI_MAKE_IMAGE_FILE_PATH(image_obj->file_path, 0);
    mmi_ucs2cat((S8*) image_obj->file_path, (S8*) image_obj->file_name);

    file_handle = FS_Open((U16*) image_obj->file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (file_handle < 0)
    {
        umms_mmi_show_template_error_msg(MMA_RESULT_FAIL);        
        StopTimer(UMMS_INPROGRESS_TIMER_ID);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_template_msg();
        return FALSE;
       // MMI_ASSERT(0);
    }

    FS_Write(file_handle, image_buff, image_length, &write_len);
    FS_Close(file_handle);
	return TRUE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_template_fill_text_data
 * DESCRIPTION
 *  This function fills the text data in a file.
 * PARAMETERS
 *  file_path       [IN]        [?]
 *  subject         [IN]        [?]
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_template_fill_text_data(const U16 *file_path, const U16 *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 write_len = 0;
    U32 utf8_buffer_size = (mmi_ucs2strlen((S8*) subject) * 3 + ENCODING_LENGTH);
    U8 *utf8_buffer = NULL;
    U32 utf8_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_buffer = (U8*) umms_malloc(utf8_buffer_size);

    MMI_ASSERT(utf8_buffer != NULL);

    memset(utf8_buffer, 0, utf8_buffer_size);
    utf8_len = mmi_chset_ucs2_to_utf8_string(utf8_buffer, utf8_buffer_size, (U8*) subject);

    file_handle = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (file_handle < 0)
    {
		umms_free(utf8_buffer);
	//	umms_mmi_show_template_error_msg(MMA_RESULT_FAIL);        
       DisplayPopup((PU8) GetString(GetFileSystemErrorString(file_handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        StopTimer(UMMS_INPROGRESS_TIMER_ID);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_template_msg();
        return FALSE;
        //MMI_ASSERT(0);
    }

    FS_Write(
        file_handle,
        utf8_buffer,
        utf8_len - 1,   /* null terminator */
        &write_len);
    umms_free(utf8_buffer);
    FS_Close(file_handle);

	return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_template_fill_audio_data
 * DESCRIPTION
 *  Fills the audio buffer into file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_template_fill_audio_data(mmi_umms_object_struct *audio_obj, const U8 *audio_buff, const U32 audio_len)
{

	FS_HANDLE file_handle;
	U32 write_len = 0;

	mmi_asc_to_ucs2((S8*) audio_obj->file_name, (S8*) UMMS_TEMPLATE_AUDIO_FILE);
	UMMS_MMI_MAKE_AUDIO_FILE_PATH(audio_obj->file_path,0)
 
    file_handle = FS_Open((U16*) audio_obj->file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
  
    if (file_handle < 0)
    {
 //       umms_mmi_show_template_error_msg(MMA_RESULT_FAIL);    
		DisplayPopup((PU8) GetString(GetFileSystemErrorString(file_handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);		
        StopTimer(UMMS_INPROGRESS_TIMER_ID);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        mmi_umms_reset_template_msg();
        return FALSE;
       // MMI_ASSERT(0);
    }	

    FS_Write(file_handle, (U8*)audio_buff, audio_len, &write_len);
    FS_Close(file_handle);
	return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_usr_def_templ_get_msg_content_req
 * DESCRIPTION
 *  Copy msg file to template folder
 * PARAMETERS
 *  msgId       [IN]        

 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_usr_def_templ_get_msg_content_req(U32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
#else
	U8 msg_file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	PS8 file_name;
	g_user_defined_create.msg_path = (U8*)umms_malloc((MMA_MAX_INTERNAL_FILENAME_LENGTH+1)*ENCODING_LENGTH);
	MMI_ASSERT(g_user_defined_create.msg_path != NULL);
	mmi_umms_init_template_folder();
	memset(g_user_defined_create.file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH+1)*ENCODING_LENGTH);
	wap_mms_get_home_directory((kal_wchar*)g_user_defined_create.msg_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
	wap_mms_get_message_file_name(msgId, (kal_wchar*)msg_file_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
	mmi_ucs2cat((S8*)g_user_defined_create.msg_path, (S8*)"\\");
	mmi_ucs2cat((S8*)g_user_defined_create.msg_path, (S8*)msg_file_path);

	MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(g_user_defined_create.file_path);
	mmi_ucs2cat((S8*)g_user_defined_create.file_path, (S8*)"\\");
	file_name = mmi_fmgr_extract_file_name((S8*)msg_file_path);

	mmi_ucs2cat((S8*)g_user_defined_create.file_path, (S8*)file_name);
		mmi_fmgr_send_copy_req(
            FMGR_ACTION_COPY,
            (U8*) g_user_defined_create.msg_path,
            (U8*) g_user_defined_create.file_path,
            mmi_umms_save_template_file_callback);


#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_template_file_callback
 * DESCRIPTION
 *  Copy msg file to template folder rsp
 * PARAMETERS
 *  info       [IN]        

 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_template_file_callback(void* info)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;
	umms_free(g_user_defined_create.msg_path);
	g_user_defined_create.msg_path = NULL;

    if (msgPtr->result >= 0)
    {
		mmi_umms_send_create_template_req(MMI_UMMS_USER_DEFINED_TYPE);
	}
    else
    {
	    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_save_template_file_callback result=%d *\n",
                         msgPtr->result);
//		mmi_umms_show_error_pop_up(MMA_RESULT_FAIL);
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(msgPtr->result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);

		DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    }
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_usr_def_templ_get_msg_content_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgRsp      [?]     [?]
 *  buffer_size(?)      [IN](?)
 *  resp            [?](?)(?)
 *  buffer          [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_usr_def_templ_get_msg_content_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *contRsp = (wap_mma_get_content_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSMessageTemplates.c] mmi_umms_usr_def_templ_get_msg_content_rsp result=%d *\n",
                         contRsp->result);

    if (contRsp->result != MMA_RESULT_OK)
    {
        /* return to rajat */
        if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
        {
            
            mmi_umms_show_error_pop_up(contRsp->result);
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
        }
        else
        {
            mmi_umms_go_to_box_list_screen();
        }
        return;
    }
    if (contRsp->more)
    {
        wap_mma_get_content_req_struct *msg_req;

        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppMsg.c] mmi_umms_get_content_for_rr_dr_rsp Is More is true\n");
        msg_req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));
        msg_req->req_id = contRsp->req_id;
        msg_req->msg_id = contRsp->msg_id;
        msg_req->app_id = MMA_APP_ID_TEMPLATE;
        msg_req->buffer_index = ++contRsp->buffer_index;
        msg_req->mode = MMA_MODE_EDIT;
        mmi_umms_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msg_req, NULL);
        return;
    }
    else
    {
    memset(g_user_defined_create.file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    mmi_ucs2cpy((PS8) g_user_defined_create.file_path, (PS8) contRsp->xml_filepath);
    mmi_umms_send_create_template_req(MMI_UMMS_USER_DEFINED_TYPE);
}
}


/*****************************************************************************
 * FUNCTION
 *  umms_mmi_show_template_error_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  msgRsp              [?](?)
 *  buffer_size(?)      [IN](?)
 *  resp            [?](?)(?)
 *  buffer          [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void umms_mmi_show_template_error_msg(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_context->default_creation_progress = FALSE;
    if (g_umms_context->state == MMI_UMMS_TEMPLATE_GEN_FOREGROUND)
    {
        if ((GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
            && (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED) == TRUE))
        {
        if (result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_MMA_RESULT_FAIL_INSUFFICIENT_STORAGE),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }
        else if (mmi_umms_is_usb_mode())
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_UMMS_TEMPLATE_REMOVE_USB),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
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
    }
    else
    {
        g_umms_context->state = MMI_UMMS_TEMPLATE_GEN_FOREGROUND;
    }

    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_init_template_folder
 * DESCRIPTION
 *  Create uc folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_init_template_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;
    U8 folder_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(folder_path);
    
    /* if the dir exists, delete it */
    file_handle = FS_Open((WCHAR*)folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {            
        FS_Close(file_handle);

        FS_XDelete((WCHAR*)folder_path, 
           FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
           NULL, 
           0);
    }
    
    result = FS_CreateDir((WCHAR*)folder_path);
    
    if (result < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSMessageTemplates.c] mmi_umms_init_template_folder Create DIR FAIL! *\n");
    }

    FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
}
#endif /* defined (__MMI_MMS_2__) && defined(MMS_SUPPORT) */ 


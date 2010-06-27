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
 *  MMSAppUiInterface.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the ui Flow for the MMS Application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
//#ifndef _MMI_UMMSAPPUIINTERFACE_C
//#define _MMI_UMMSAPPUIINTERFACE_C
/***************************************************************************** 
* Include
*****************************************************************************/

#ifdef __MMI_MMS_2__

#include "MainMenuDef.h"
#include "CommonScreens.h"
#include "MessagesResourceData.h"
#include"wgui_status_icons.h"
#include "ProtocolEvents.h"
#include "CallManagementGprot.h"

#include "CallManagementIdDef.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CallsGprots.h"
#include "CommonStubsProt.h"
#include "IncomingCallManagementProt.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"
#include "AlarmFrameworkProt.h"
#include "mmsadp.h"
#include "MMSAppResDef.h"
#include "MMSAppGprot.h"
#include "MMSAppprot.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif 

#include "MMSAppSaveObjects.h"
#include "MessagesMiscell.h"
#ifdef __MMI_VBOOKMARK__
#include "BrowserBookmarks.h"
#endif
mmi_umms_dwnld_send_status_struct dwnld_send_status_struct; /* current selected MMS Info in UM */
mmi_umms_dwnld_send_status_struct *g_dwnld_send_status_struct = &dwnld_send_status_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_init
 * DESCRIPTION
 *  Highlight Handler Registration and Idle Screen Hnadling at Boot Up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Inbox Highlight Handlers */
    mmi_umms_entry_event_handlers();
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_SAVE_TO_TEMPLATE, mmi_umms_highlight_save_as_template);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_REPLY, mmi_umms_highlight_inbox_reply);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_REPLY_ALL, mmi_umms_highlight_inbox_reply_all);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_FORWARD, mmi_umms_highlight_forward);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_EDIT_MESSAGE, mmi_umms_highlight_edit_msg);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_DELETE, mmi_umms_highlight_delete_msg);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_DELETE_ALL, mmi_umms_highlight_delete_all_msg);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTION_REPLY_SMS, mmi_umms_highlight_reply_as_sms);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHiliteHandler(MENU_ID_UMMS_INBOX_MOVE_TO_ARCHIVE, mmi_umms_highlight_move_to_archive);
#endif 
    SetHiliteHandler(MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS, mmi_umms_highlight_save_objects);
    SetHiliteHandler(MENU_ID_UMMS_OPTIONS_USE_DETAILS, mmi_umms_highlight_use_details);
    SetHiliteHandler(MENU_ID_UMMS_OPTIONS_PROPERTIES, mmi_umms_highlight_show_properties);
    SetHiliteHandler(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD, mmi_umms_highlight_inbox_download_msg);
    SetHiliteHandler(MENU_ID_UMMS_OPTIONS_USE_DETAILS_NUMBER, mmi_umms_highlight_use_number);
    SetHiliteHandler(MENU_ID_UMMS_OPTIONS_USE_DETAILS_EMAIL, mmi_umms_highlight_use_email);
    SetHiliteHandler(MENU_ID_UMMS_OPTION_USE_DETAILS_URL, mmi_umms_highlight_use_url);
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_ADDRESSES_CALL, mmi_umms_highlight_details_call);
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK, mmi_umms_highlight_details_save_to_phbook);
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_ADDRESSES_ADD_TO_CONTACT, mmi_umms_highlight_details_add_to_contact);
    /* Archive Resources */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_SAVE_TO_TEMPLATE, mmi_umms_highlight_save_as_template);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY, mmi_umms_highlight_inbox_reply);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_REPLY_ALL, mmi_umms_highlight_inbox_reply_all);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_FORWARD, mmi_umms_highlight_forward);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_EDIT_MESSAGE, mmi_umms_highlight_edit_msg);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_DELETE, mmi_umms_highlight_delete_msg);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_OPTIONS_DELETE_ALL, mmi_umms_highlight_delete_all_msg);
    SetHiliteHandler(MENU_ID_UMMS_ARCHIVE_PROPERTIES, mmi_umms_highlight_show_properties);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
    /* Ashwani Starts */
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_CURRENT_SLIDE, mmi_umms_highlight_use_details_current_slide);
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_ALL_SLIDES, mmi_umms_highlight_use_details_all_slides);
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_MESSAGE_HEADER, mmi_umms_highlight_use_details_message_header);
    /* Ashwani Ends */

    /* Outbox Highlight Handlers */

    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_SAVE_TO_TEMPLATE, mmi_umms_highlight_save_as_template);
    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_SEND, mmi_umms_highlight_send_msg);
    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_CANCEL_SEND, mmi_umms_highlight_cancel_send);

    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_EDIT_MESSAGE, mmi_umms_highlight_edit_msg);
    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_DELETE, mmi_umms_highlight_delete_msg);
    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_DELETE_ALL, mmi_umms_highlight_delete_all_msg);
    SetHiliteHandler(MENU_ID_UMMS_OUTBOX_OPTIONS_MESSAGE_STATUS, mmi_umms_highlight_show_msg_status);
    /* Sent Highlight Handlers */

    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_SENT_SAVE_TO_TEMPLATE, mmi_umms_highlight_save_as_template);
    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_FORWARD, mmi_umms_highlight_forward);
    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_EDIT_MESSAGE, mmi_umms_highlight_edit_msg);
    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_DELETE, mmi_umms_highlight_delete_msg);
    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_DELETE_ALL, mmi_umms_highlight_delete_all_msg);
    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_MOVE_TO_DRAFTS, mmi_umms_highlight_move_to_drafts);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHiliteHandler(MENU_ID_UMMS_SENT_OPTIONS_MOVE_TO_ARCHIVE, mmi_umms_highlight_move_to_archive);
#endif 
    /* Drafts Folder Highlight Handlers */

    SetHiliteHandler(MENU_ID_UMMS_DRAFT_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_DRAFTS_OPTIONS_SENT, mmi_umms_highlight_send_msg);
    SetHiliteHandler(MENU_ID_UMMS_DRAFTS_SAVE_TO_TEMPLATE, mmi_umms_highlight_save_as_template);
    SetHiliteHandler(MENU_ID_UMMS_DRAFT_OPTIONS_FORWARD, mmi_umms_highlight_forward);
    SetHiliteHandler(MENU_ID_UMMS_DRAFT_OPTIONS_EDIT_MESSAGE, mmi_umms_highlight_edit_msg);
    SetHiliteHandler(MENU_ID_UMMS_DRAFT_OPTIONS_DELETE, mmi_umms_highlight_delete_msg);
    SetHiliteHandler(MENU_ID_UMMS_DRAFT_OPTIONS_DELETE_ALL, mmi_umms_highlight_delete_all_msg);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHiliteHandler(MENU_ID_UMMS_DRAFT_OPTIONS_MOVE_TO_ARCHIVE, mmi_umms_highlight_move_to_archive);
#endif 

    /* Template Folder Highlight Handlers */

    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_VIEW, mmi_umms_highlight_view);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_PROPERTIES, mmi_umms_highlight_show_properties);
    SetHiliteHandler(MENU_ID_UMMS_TEMPLATES_OPTIONS_WRITE_MESSAGE, mmi_umms_highlight_edit_msg);

    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_ADDRESSES_GO_TO, mmi_umms_highlight_details_go_to_url);
#ifdef __MMI_VBOOKMARK__
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_ADDRESSES_ADD_BOOKMARK, mmi_umms_highlight_details_save_as_bookmark);
#endif 
    SetHiliteHandler(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS, mmi_umms_highlight_save_video_object);
    SetHiliteHandler(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS, mmi_umms_highlight_save_audio_object);
    SetHiliteHandler(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS, mmi_umms_highlight_save_image_object);
    SetHiliteHandler(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS, mmi_umms_highlight_view_attachments);
	SetHiliteHandler(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS, mmi_umms_highlight_save_text_object);
    SetHiliteHandler(MENU_ID_UMMS_OPTIONS_LOCK_MODE, mmi_umms_highlight_lock_mode);
#ifdef __MMI_EMAIL__
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_SEND_EMAIL, mmi_umms_highlight_details_send_email);
#endif 
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_SEND_SMS, mmi_umms_highlight_details_send_sms);
    SetHiliteHandler(MENU_ID_UMMS_USE_DETAILS_SEND_MMS, mmi_umms_highlight_details_send_mms);
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_show_msg_status
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_show_msg_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_message_status, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_message_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_send_msg
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_send_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_send_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_cancel_send
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_cancel_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_cancel_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_cancel_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_delete_msg
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_delete_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_delete_msg_conformation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_view
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_view, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_save_as_template
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_as_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_save_as_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_inbox_reply
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_inbox_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_reply, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_reply, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_inbox_reply_all
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_inbox_reply_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_reply_to_all, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_reply_to_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_edit_msg
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_edit_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __CMCC_FWD_EDIT_CLUBBED__
    SetLeftSoftkeyFunction(mmi_umms_entry_fwd_edit_confirm_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_fwd_edit_confirm_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#else
    SetLeftSoftkeyFunction(mmi_umms_entry_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_delete_all_msg
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_delete_all_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_delete_all_confirmation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_reply_as_sms
 * DESCRIPTION
 *  Highlight Handler for Reply as SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_reply_as_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_reply_as_sms, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_reply_as_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_move_to_archive
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_move_to_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_move_to_archive, KEY_EVENT_UP);
    //SetKeyHandler(mmi_umms_entry_move_to_archive, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_save_objects
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_save_objects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_objects, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_save_objects, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_details
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_details, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/* Ashwani Starts */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_details_current_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_details_current_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_send_use_details_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_send_use_details_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    mmi_umms_use_details_set_app_slide(MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_details_all_slides
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_details_all_slides(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_send_use_details_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_send_use_details_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    mmi_umms_use_details_set_app_slide(MMI_MV_GET_USE_DETAILS_SLIDE_ALL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_details_message_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_details_message_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_get_header_use_details, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_get_header_use_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_lock_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_lock_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_lock_mode, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_lock_mode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* void mmi_umms_highlight_lock_mode_on(void)
   {
   ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
   ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
   SetLeftSoftkeyFunction(mmi_umms_entry_, KEY_EVENT_UP);
   SetKeyHandler(mmi_umms_entry_move_to_drafts, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
   SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
   SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
   }
   void mmi_umms_highlight_lock_mode_off(void)
   {
   ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
   ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
   SetLeftSoftkeyFunction(mmi_umms_entry_move_to_drafts, KEY_EVENT_UP);
   SetKeyHandler(mmi_umms_entry_move_to_drafts, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
   SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
   SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
   
   } */

/* Ashwani Ends */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_show_properties
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_show_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_show_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_show_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_inbox_download_msg
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_inbox_download_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_pre_entry_download_mms, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_pre_entry_download_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* Ashwani API's */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_number
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_details_addresses_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_details_addresses_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Ashwani Starts */
    mmi_umms_use_details_set_addr_type(APPLIB_ADDR_TYPE_PHONENUMBER);
    /* Ashwani Ends */

}

/* Ashwani API's */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_email
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_details_addresses_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_details_addresses_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Ashwani Starts */
    mmi_umms_use_details_set_addr_type(APPLIB_ADDR_TYPE_EMAIL);
    /* Ashwani Ends */
}

/* Ashwani API's */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_use_url
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_use_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_details_addresses_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_details_addresses_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Ashwani Starts */
    mmi_umms_use_details_set_addr_type(APPLIB_ADDR_TYPE_URL);
    /* Ashwani Ends */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_call
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_call_details, KEY_EVENT_UP);
    //SetKeyHandler(mmi_umms_entry_use_call_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_save_to_phbook
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_save_to_phbook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_save_to_phbook, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_save_to_phbook, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_add_to_contact
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_add_to_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_email_add_to_contact, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_email_add_to_contact, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* Ashwani Starts */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_go_to_url
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_go_to_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_url_go_to, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_url_go_to, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_VBOOKMARK__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_save_as_bookmark
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_save_as_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_use_url_save_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_use_url_save_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_VBOOKMARK__ */ 

#ifdef __MMI_EMAIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_send_email
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_send_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_use_email_send_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_use_email_send_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_EMAIL__ */ 

#ifdef __UNIFIED_COMPOSER_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_send_sms
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_use_details_send_sms, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_use_details_send_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_details_send_mms
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_details_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_use_details_send_mms, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_use_details_send_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 

/* Ashwani Ends */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_forward
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __CMCC_FWD_EDIT_CLUBBED__
    SetLeftSoftkeyFunction(mmi_umms_entry_fwd_edit_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_fwd_edit_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#else
    SetLeftSoftkeyFunction(mmi_umms_entry_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_move_to_drafts
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_move_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_umms_entry_move_to_drafts, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_move_to_drafts, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_properties_according_to_box_type
 * DESCRIPTION
 *  Properties Screen according to the Message Type
 * PARAMETERS
 *  current_mms_info_list       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_properties_according_to_box_type(umms_current_selected_info_struct *current_mms_info_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Rajbir dr_rr */
    mmi_umms_show_properties_mms();
}

/* Ashwani Starts */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_hilite_index(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_lock_mode_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_lock_mode_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_hilite_index(index);
}

/* Ashwani Ends */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_mms_status_icon
 * DESCRIPTION
 *  To show MMS indicator icon
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_mms_status_icon(const mmi_umms_status_icon_type_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_show_mms_status_icon status = %d \n", status);
    switch (status)
    {
        case UMMS_STATUS_OFF:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
        case UMMS_STATUS_NEW_MESSAGE:
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            ShowStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
        case UMMS_STATUS_BUSY:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            BlinkStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
        case UMMS_STATUS_FULL:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            BlinkStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
        default:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
    }
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_mms_downloading_busy
 * DESCRIPTION
 *  To handle MMS downloading indicator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_mms_downloading_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dwnld_send_status_struct->g_umms_downloading_busy++;
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_set_mms_downloading_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_downloading_busy);

    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_mms_downloading_busy
 * DESCRIPTION
 *  Reset Global variable for Download
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_mms_downloading_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dwnld_send_status_struct->g_umms_downloading_busy != 0)
    {
        g_dwnld_send_status_struct->g_umms_downloading_busy--;
    }
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_reset_mms_downloading_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_downloading_busy);
    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_download_busy
 * DESCRIPTION
 *  get Downlaod Status.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_is_download_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_is_download_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_downloading_busy);
    return g_dwnld_send_status_struct->g_umms_downloading_busy;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_stop_download_busy
 * DESCRIPTION
 *  Stop download busy.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_stop_download_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_stop_download_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_downloading_busy);
    g_dwnld_send_status_struct->g_umms_downloading_busy = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_mms_sending_busy
 * DESCRIPTION
 *  To handle MMS sending indicator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_mms_sending_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dwnld_send_status_struct->g_umms_sending_busy++;
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_set_mms_sending_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_sending_busy);
    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_reset_mms_sending_busy
 * DESCRIPTION
 *  Sending Busy.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_reset_mms_sending_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dwnld_send_status_struct->g_umms_sending_busy != 0)
    {
        g_dwnld_send_status_struct->g_umms_sending_busy--;
    }
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_reset_mms_sending_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_sending_busy);
    mmi_umms_update_status_icon_indicator();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_sending_busy
 * DESCRIPTION
 *  Get Status of Sending.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_is_sending_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_is_sending_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_sending_busy);

    return g_dwnld_send_status_struct->g_umms_sending_busy;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_stop_sending_busy
 * DESCRIPTION
 *  Stop Sending.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_stop_sending_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_stop_sending_busy Count = %d \n",
                         g_dwnld_send_status_struct->g_umms_sending_busy);
    g_dwnld_send_status_struct->g_umms_sending_busy = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_space_full
 * DESCRIPTION
 *  Space Full Indication
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_is_space_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_is_space_full \n");
    return g_dwnld_send_status_struct->no_space;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_memory_full
 * DESCRIPTION
 *  Memory Full
 * PARAMETERS
 *  memory_status       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_memory_full(const kal_bool memory_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_set_memory_full \n");
    g_dwnld_send_status_struct->no_space = memory_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_status_icon_indicator
 * DESCRIPTION
 *  To set indicator icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_status_icon_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		U32 total_num_messages = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_update_status_icon_indicator \n");
    mmi_umms_get_total_number_of_messages(&total_num_messages);
    
    if (total_num_messages >= (MAX_POSSIBLE_MESSAGES_THRESHOLD))
    {
        mmi_umms_get_msg_number_for_globals_update();
       	mmi_umms_show_mms_status_icon(UMMS_STATUS_FULL);
    }
    else
    {
        if (mmi_umms_is_download_busy() > 0 || (mmi_umms_is_sending_busy() > 0))
        {
            mmi_umms_get_msg_number_for_globals_update();
            mmi_umms_show_mms_status_icon(UMMS_STATUS_BUSY);
        }
        else
        {
            mmi_umms_get_message_number_request();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_status_icon_on_number_rsp
 * DESCRIPTION
 *  Update Icon on Get number Response.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_status_icon_on_number_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 unread_msgs = 0;
    U32 total_num_messages;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_get_total_number_of_messages(&total_num_messages);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_update_status_icon_on_number_rsp \n");

    if (total_num_messages >= (MAX_POSSIBLE_MESSAGES_THRESHOLD))
    {
        	mmi_umms_show_mms_status_icon(UMMS_STATUS_FULL);
    }
    else
    {
        if (mmi_umms_is_download_busy() > 0 || (mmi_umms_is_sending_busy() > 0))
		{
			mmi_umms_show_mms_status_icon(UMMS_STATUS_BUSY);
		}
		else
		{
        mmi_umms_get_number_of_unread_messages_in_inbox(&unread_msgs);
        if (unread_msgs > 0)
        {
            mmi_umms_show_mms_status_icon(UMMS_STATUS_NEW_MESSAGE);
        }
        else
        {
            mmi_umms_show_mms_status_icon(UMMS_STATUS_OFF);
        }
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_delete_msg_conformation
 * DESCRIPTION
 *  Entry MEssage Delete Confirmation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_delete_msg_conformation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[MAX_PROGRESS_STRING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_entry_delete_msg, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __CMCC_FWD_EDIT_CLUBBED__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_fwd_edit_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_fwd_edit_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[MAX_PROGRESS_STRING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_ID_UMMS_EDIT_CONFIRM));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_entry_edit, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_umms_entry_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_forward, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_corrupt_and_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_corrupt_and_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[MAX_PROGRESS_STRING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_ID_UMMS_CORRUPT_AND_DELETE));
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_entry_delete_corrupt, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_delete_corrupt, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_delete_all_confirmation
 * DESCRIPTION
 *  Entry MEssage Delete All Confirmation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_delete_all_confirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[MAX_PROGRESS_STRING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE_ALL));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_entry_delete_all, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_delete_all, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_content_mode_confrm_pop_up
 * DESCRIPTION
 *  Show PopUp for Restricted mode of MMS Creation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_content_mode_confrm_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[MAX_PROGRESS_STRING_LENGTH] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_ID_UMMS_RESTRICTED_MODE));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_umms_entry_edit_fwd_mode, KEY_EVENT_UP);
    SetKeyHandler(mmi_umms_entry_edit_fwd_mode, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_not_allowed_pop_up
 * DESCRIPTION
 *  Not Alowed PopUp in case of multiple entry to Message Centre.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_not_allowed_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_not_allowed_pop_up \n");
    DisplayPopup(
        (U8*) GetString(STR_ID_UMMS_OPERATION_NOT_ALLOWED),
        IMG_GLOBAL_EMPTY,
        1,
        MMI_UMMS_POPUP_TIME,
        EMPTY_LIST_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_use_details_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_use_details_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 string[MAX_PROGRESS_STRING_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_umms_use_details_progress_screen");

    EntryNewScreen(SCR_ID_UMMS_PROGRESS_USE_DETAILS, NULL, mmi_umms_use_details_progress_screen, NULL);
    mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_PLEASE_WAIT), MAX_PROGRESS_STRING_LENGTH);

    ShowCategory66Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (U8*) string,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_option_screen
 * DESCRIPTION
 *  Delete the Resrtricted Option Scrren from the History.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS_RESTRICTED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_storage_state
 * DESCRIPTION
 *  Update Storage State when Indication comes.
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_storage_state(const kal_bool state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_update_storage_state \n");
    if (state)
    {
        mmi_umms_set_memory_full(TRUE);
        mmi_umms_update_status_icon_on_number_rsp();
    }
    else
    {
        mmi_umms_set_memory_full(FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_report_screen
 * DESCRIPTION
 *  Entry Read Report and Delivery Report Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_report_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U16 nImgIltemList[MAX_SUB_MENUS] = {0, };
    U16 parentid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_entry_report_screen \n");

    EntryNewScreen(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS, NULL, mmi_umms_entry_report_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);

    mmi_umms_delete_progress_screen();
    DeleteScreenIfPresent(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
    parentid = MENU_ID_UMMS_INBOX_OPTIONS_DELIVERY_REPORT;

    nNumofItem = GetNumOfChild(parentid);
    GetSequenceStringIds(parentid, nStrItemList);
    GetSequenceImageIds(parentid, nImgIltemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
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

void mmi_umms_exit_read_report_screen(void)
{
    //

}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_enter_java_mms_options
 * DESCRIPTION
 *  Entry Screen for Java MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_enter_java_mms_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U16 nImgIltemList[MAX_SUB_MENUS] = {0, };
    U16 parentid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_enter_java_mms_options \n");

    EntryNewScreen(SCR_ID_UMMS_JAVA_OPTIONS, NULL, mmi_umms_enter_java_mms_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_JAVA_OPTIONS);

    mmi_umms_delete_progress_screen();
    DeleteScreenIfPresent(SCR_ID_UMMS_JAVA_OPTIONS);
    parentid = MENU_ID_UMMS_INBOX_OPTIONS_JAVA_MMS;

    nNumofItem = GetNumOfChild(parentid);
    GetSequenceStringIds(parentid, nStrItemList);
    GetSequenceImageIds(parentid, nImgIltemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
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
 *  mmi_umms_show_java_mms_pop_up
 * DESCRIPTION
 *  Show JAVA MMS PopUp.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_java_mms_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopupCallBack(
        (PU8) GetString(STR_ID_UMMS_FAILED_TO_DISPLAY_JSR_MMS),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE,
        mmi_umms_show_viewer_properties_mms);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_cancel_fail_pop_up
 * DESCRIPTION
 *  Show Error when Cancel could not be canceled.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_cancel_fail_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_cancel_fail_pop_up \n");
    DisplayPopup(
        (PU8) GetString(STR_ID_UMMS_COMM_ABORTED_FAILED),
        IMG_GLOBAL_WARNING,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        WARNING_TONE);
    /*DisplayPopupCallBack(
        (PU8) GetString(STR_ID_UMMS_COMM_ABORTED_FAILED),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE,
        mmi_umms_go_to_box_list_screen);*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_goto_menu_option
 * DESCRIPTION
 *  Go to Menu Option Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_goto_menu_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UMMS_NOTIFICATION))
    {
        DeleteUptoScrID(SCR_ID_UMMS_NOTIFICATION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_communication_aborted_pop_up
 * DESCRIPTION
 *  Show Eror in Communication PopUp.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_communication_aborted_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_communication_aborted_pop_up \n");
    DisplayPopup(
        (PU8) GetString(STR_ID_UMMS_COMM_ABORTED_AND_FAIL_STORE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_update_progress_screen
 * DESCRIPTION
 *  Update Progress Screen in case of Download with percent Value.
 * PARAMETERS
 *  new_percent_value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_update_progress_screen(const U32 new_percent_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
    {
    UpdateCategory402Value((U16) new_percent_value, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_java_mms_screen
 * DESCRIPTION
 *  Entry Java MMS PopUp Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_java_mms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_show_java_mms_pop_up();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_error_pop_up
 * DESCRIPTION
 *  Show Error PopUp according to the Error Type.
 * PARAMETERS
 *  error_result        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_error_pop_up(const mma_result_enum error_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 string[MAX_PROGRESS_STRING_LENGTH * ENCODING_LENGTH] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_show_error_pop_up Result = %d \n", error_result);
    switch (error_result)
    {
        case MMA_RESULT_OK:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_DONE), MAX_PROGRESS_STRING_LENGTH);
            DisplayPopup((U8*) string, IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
            return;
            break;
        case MMA_RESULT_FAIL:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_IN_CALL:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INCALL), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_NOT_READY:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_NOT_READY), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_BUSY:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_BUSY), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INSUFFICIENT_MEMORY),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INSUFFICIENT_STORAGE),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_NOT_FOUND:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_NOT_FOUND),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_CORRUPTED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_CORRUPTED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_IN_USE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_IN_USE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FILE_IO:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FILE_IO), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_UNSUPPORT_CONTENT:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_UNSUPPORT_CONTENT),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_CONNECT_ERROR:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_CONNECT_ERROR),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_SERVER_TIMEOUT),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_USER_CANCEL:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_USER_CANCEL), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INVALID_PARAMETER:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INVALID_PARAMETER),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_QUEUE_FULL:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_QUEUE_FULL), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_DELAYED:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_DELAYED), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_CONTINUE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_CONTINUE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_FOLDER_NOT_FOUND:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_FOLDER_NOT_FOUND),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_CONFIG_ERROR:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_CONFIG_ERROR),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_SERVER_ERROR:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_SERVER_ERROR),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_SERVICE_DENIED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_SERVICE_DENIED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_UNKNOWN_APN:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_UNKNOWN_APN),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_COMM_UNAUTHORIZED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_COMM_UNAUTHORIZED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INVALID_MSGID:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INVALID_MSGID),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_INVALID_FOLDER:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_INVALID_FOLDER),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_PARSE:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_MMA_RESULT_FAIL_PARSE), MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_MSGID_IS_USING:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_MSGID_IS_USING),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        case MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM:
            mmi_ucs2ncpy(
                (PS8) string,
                (PS8) GetString(STR_ID_MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM),
                MAX_PROGRESS_STRING_LENGTH);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    DisplayPopup((U8*) string, IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_um_error_pop_up
 * DESCRIPTION
 *  This is the show pop for UM responses.
 * PARAMETERS
 *  result      [IN]        [?]     [?]     result
 * RETURNS
 *  void
 *****************************************************************************/
/* Rajbir */
void mmi_umms_show_um_error_pop_up(U32 result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        if (IsScreenPresent(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED))
        {
            DeleteUptoScrID(SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED);
        }

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);

        mmi_umms_delete_progress_screen();
        mmi_umms_update_status_icon_indicator();
        return;
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        mmi_umms_delete_progress_screen();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_error_in_send_pop_up
 * DESCRIPTION
 *  Show Error PopUp During Send Operaion.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_error_in_send_pop_up(U32 msg_id,U8 *response_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 string[(MAX_PROGRESS_STRING_LENGTH + MMA_MAX_ADDR_LEN) * ENCODING_LENGTH] = {0, };
  //  U8 to_address[MMA_MAX_ADDR_LEN] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_show_error_in_send_pop_up Msg_id= %d \n", msg_id);

    //mmi_ucs2ncpy((PS8) to_address, (PS8) mmi_umms_get_to_number(msg_id), MMA_MAX_ADDR_LEN);
	if(response_text[0] != 0)
	{
    mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_ERROR_MMS_SENT), MAX_PROGRESS_STRING_LENGTH);
		mmi_ucs2ncat((PS8) string, (PS8) response_text, MAX_PROGRESS_STRING_LENGTH + MMA_MAX_RESPONSE_TEXT_LENGTH);
	}
	else
	{
		mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_ERROR_IN_SEND), MAX_PROGRESS_STRING_LENGTH);
	}

    if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))
    {
        DisplayPopup((U8*) string, IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
    }
    else
    {
        /* Show No PopUp */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_error_in_send_from_uc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_error_in_send_from_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_error_in_send_from_uc \n");
    if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_ERROR_IN_SEND),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_send_sucess_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_send_sucess_pop_up(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 string[(MAX_PROGRESS_STRING_LENGTH + MMA_MAX_ADDR_LEN) * ENCODING_LENGTH] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_send_sucess_pop_up \n");

    mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_SUCCESS_MMS_SENT_ONLY), MAX_PROGRESS_STRING_LENGTH);
    mmi_ucs2ncat((PS8) string, (PS8) mmi_umms_get_to_number(msg_id), 17 * ENCODING_LENGTH);
    if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))
    {
        DisplayPopup((U8*) string, IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_done_pop_up
 * DESCRIPTION
 *  Show Sucess PopUp.
 * PARAMETERS
 *  current_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_done_pop_up(const umms_state_enum current_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool show_pop_up = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_done_pop_up \n");
    show_pop_up = mmi_umms_show_pop(current_state);
    if (show_pop_up)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        return;
    }
    else
    {

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_notification_option_screen
 * DESCRIPTION
 *  Entry notification Option Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_notification_option_screen(void)
{
    // A dummmy Screen is shown here for the time being but actually the
    // Properties Screen is to be shown Here before showning the options

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MAX_SUB_MENUS] = {0, };
    U16 nImgIltemList[MAX_SUB_MENUS] = {0, };
    U16 parentid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_entry_notification_option_screen \n");

    EntryNewScreen(SCR_ID_UMMS_NOTIFICATION, NULL, mmi_umms_entry_notification_option_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UMMS_NOTIFICATION);

    parentid = MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION;

    if (mmi_umms_check_downloading_state())
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_INBOX_OPTIONS_DOWNLOAD);
    }

    nNumofItem = GetNumOfChild_Ext(parentid);
    GetSequenceStringIds_Ext(parentid, nStrItemList);
    GetSequenceImageIds_Ext(parentid, nImgIltemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    //SetLeftSoftkeyFunction(mmi_umms_entry_, KEY_EVENT_UP);
    //SetKeyHandler(ebr_ebook_search_string, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_dummy_screen
 * DESCRIPTION
 *  Entry Function for Dummy Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_entry_dummy_screen \n");
    EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_progress_screen
 * DESCRIPTION
 *  Delete the Progress Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UMMS_PROGRESS))
    {
        DeleteNScrId(SCR_ID_UMMS_PROGRESS);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_pop
 * DESCRIPTION
 *  Decide wether to Show the Pop Up or not based on the Current State.
 * PARAMETERS
 *  current_state       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_umms_show_pop(const umms_state_enum current_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (current_state)
    {
        case E_STATE_DELETE_MSG:
        case E_STATE_MOVE_MSG:
        case E_STATE_GLOBAL_DELETE_ALL_MSG:
        case E_STATE_SAVE_MSG:
        case E_STATE_DELETE_CORRUPT_MSG:
            return TRUE;
            break;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_use_details
 * DESCRIPTION
 *  Entry use Details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nNumofItem = 0;
    U16 nStrItemList[MMI_MV_GET_USE_DETAIL_MAX_TYPES] = {0, };
    U16 parentid = 0;
    U16 scrid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrid = SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS;
    parentid = MENU_ID_UMMS_OPTIONS_USE_DETAILS;
    EntryNewScreen(scrid, NULL, mmi_umms_entry_use_details, NULL);
    guiBuffer = GetCurrGuiBuffer(scrid);
    if((mmi_umms_get_message_type() == MMA_MSG_TYPE_READ_REPORT) ||
        (mmi_umms_get_message_type() == MMA_MSG_TYPE_DELIVERY_REPORT))
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_USE_DETAILS_CURRENT_SLIDE);
        mmi_frm_hide_menu_item(MENU_ID_UMMS_USE_DETAILS_ALL_SLIDES);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_USE_DETAILS_CURRENT_SLIDE);
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_USE_DETAILS_ALL_SLIDES);
    }
    nNumofItem = GetNumOfChild_Ext(parentid);
    GetSequenceStringIds_Ext(parentid, nStrItemList);
    SetParentHandler(parentid);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UMMS_OPTIONS_USE_DETAILS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
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
 *  mmi_umms_entry_message_status
 * DESCRIPTION
 *  Entry Function for Message Status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_message_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show the Message Status as Sending, Normal, Downloading etc. */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_entry_message_status \n");
    mmi_umms_show_message_status_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_in_creation_process_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_in_creation_process_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
    mmi_umms_go_to_box_list_screen();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_memory_full_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_memory_full_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_memory_full_pop_up \n");
    if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_MEMORY_FULL_CLEAN),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_msg_is_in_use
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_msg_is_in_use(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_msg_is_in_use \n");
    DisplayPopup(
        (U8*) GetString(STR_ID_MMA_RESULT_FAIL_FILE_IN_USE),
        IMG_GLOBAL_WARNING,
        1,
        MMI_UMMS_POPUP_TIME,
        WARNING_TONE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_option_screen_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_is_option_screen_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((IsScreenPresent(SCR_ID_UMMS_MMS_OPTIONS)) || 
        (IsScreenPresent(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES)) ||
        (IsScreenPresent(SCR_ID_UMMS_NOTIFICATION)) ||
        (IsScreenPresent(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS)) ||
        mmi_umms_is_get_content_or_header_req_state())
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_is_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall())
    {
        if ((GetActiveScreenId() == SCR_CM_ACTIVECALLSCREEN) ||
            (GetActiveScreenId() == ITEMSCR_INCOMING_CALL) ||
            (GetActiveScreenId() == SCR1004_CM_DISPENDCALLDURATION) ||
            (GetActiveScreenId() == SCR1001_CM_OUTGOINGCALLSCREEN) || (GetActiveScreenId() == SCR_CM_NOTIFYCALLABORTED))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_cancel_send_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sucess_state        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_cancel_send_popup(MMI_BOOL sucess_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSAppUiInterface.c] mmi_umms_show_not_allowed_pop_up \n");
    if (sucess_state == MMI_TRUE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_UMMS_CANCELLING_SEND_SUCESS),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_UMMS_CANCELLING_SEND_FAILURE),
            IMG_GLOBAL_WARNING,
            1,
            MMI_UMMS_POPUP_TIME,
            WARNING_TONE);
    }
}
#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_show_cancel_send_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sucess_state        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_show_book_mark_add_result(brw_add_to_bkm_err_enum book_mark_result)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 string[MAX_PROGRESS_STRING_LENGTH * ENCODING_LENGTH] = {0, };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[MMSAppUiInterface.c] mmi_umms_show_book_mark_add_result Result = %d \n", book_mark_result);
    switch (book_mark_result)
    {
        case BRW_ADD_TO_BKM_SUCCESS:
            mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_GLOBAL_DONE), MAX_PROGRESS_STRING_LENGTH);
			DisplayPopup((U8*) string, IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
            return;
            break;
		case BRW_ADD_TO_BKM_INVALID_URL:
			mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_INVALID_URL), MAX_PROGRESS_STRING_LENGTH);
			break;
		case  BRW_ADD_TO_BKM_INVALID_TITLE:
			mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_INVALID_TITLE), MAX_PROGRESS_STRING_LENGTH);
			break;
		case BRW_ADD_TO_BKM_FILE_SYSTEM_ERROR:
			mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_FILE_SYSTEM_ERROR), MAX_PROGRESS_STRING_LENGTH);
			break;
		case BRW_ADD_TO_BKM_MEMORY_FULL:
			mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_BOOK_MARK_FULL), MAX_PROGRESS_STRING_LENGTH);
			break;
		default:
			MMI_ASSERT(0);
			break;
	}
	if ((!mmi_umms_is_in_call()) && (!AlmIsTonePlaying()))
    {
        DisplayPopup((U8*) string, IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
    }
    else
	{
		/* Do Nothing*/
	}
}


#ifdef __CMCC_SEND_COUNT_RETRY_POP_UP__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_display_retry_send_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Void        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_display_retry_send_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DisplayPopup(
        (U8*) GetString(STR_ID_UMMS_SEND_FAIL_RETRY),
        IMG_GLOBAL_WARNING,
        1,
        MMI_UMMS_POPUP_TIME,
        WARNING_TONE);

}
#endif
#endif /*__MMI_VBOOKMARK__ */

#endif /* __MMI_MMS_2__ */ 
// #endif


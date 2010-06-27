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
 *  JMMSInboxUI.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui of inbox folder in mms
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JMMSINBOXSECMMI_C
#define _MMI_JMMSINBOXSECMMI_C
/***************************************************************************** 
* Include
*****************************************************************************/

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "JMMSStoreHandling.h"
#include "MainMenuDef.h"
#include "JMMSConfig.h"
#include "JMMSMainMMS.h"
#include "JMMSUseDetails.h"
#include "JMMSInbox.h"
#include "JMMSWriteMMS.h"
#include "JMMSCoreAPI.h"
#include "JMMSDRMHandler.h"
#include "JMMSView.h"

#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include <jdi_communicator.h>

#include <MessagingDatatypes.h>
#include <MessagingAPI.h>

#include "JMMSExdcl.h"
#include "JMMSPushHandling.h"


#include "JMMSCompose.h"

#include <PrvMessagingDataTypes.h>
#include <MM1DataTypes.h>
#include <ComposeUtils.h>
#include "JMMSResDef.h"

#include "JMMSCoreAPI.h"
#include "JMMSMainMMS.h"
#include "JMMSProtocols.h"
#include "JMMSView.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSPushHandling.h"
#include "MessagesResourceData.h"
#include "JMMSTemplates.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "JMMSUMHandling.h"
#endif 
#ifdef __MMI_JATAAYU_MMS_REPLY_BY_SMS__
#include "SMSapi.h"
#endif 
#include "wapadp.h"     /* compiler warning removal */
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

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* PMT VIKAS START 20060405 */
// #ifdef __MMI_MMS_SIGNATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_fw_from_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_jmms_is_fw_from_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jmms_context->fw_from_inbox;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_fw_flag_of_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_fw_flag_of_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->fw_from_inbox = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_reset_fw_flag_of_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_reset_fw_flag_of_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->fw_from_inbox = MMI_FALSE;
}

// #endif /* __MMI_MMS_SIGNATURE__ */
/* PMT VIKAS END 20060405 */

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox
 * DESCRIPTION
 *  This function is highlight handler of Inbox menu item in main mms screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_inbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_inbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_inbox, KEY_WAP, KEY_EVENT_DOWN);

}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_init
 * DESCRIPTION
 *  This function init the hilight handlers of inbox menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;

    /* U8 i = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Inbox options Highlight handlers */
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_VIEW, mmi_jmms_highlight_inbox_options_view);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_REPLY, mmi_jmms_highlight_inbox_options_reply);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_REPLY_ALL, mmi_jmms_highlight_inbox_options_reply_all);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_FORWARD, mmi_jmms_highlight_inbox_options_forward);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_DOWNLOAD, mmi_jmms_highlight_inbox_options_download);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_DELETE, mmi_jmms_highlight_inbox_options_delete);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_DELETE_ALL, mmi_jmms_highlight_inbox_options_delete_all);
    /* Vishal Start */
#ifdef __MMI_JATAAYU_MMS_REPLY_BY_SMS__
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_REPLY_BY_SMS, mmi_jmms_highlight_inbox_options_reply_by_sms);
#endif 
#ifdef __MMI_MMS_DELETE_ALL_READ_REPORT__
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_DELETE_READ_ALL, mmi_jmms_highlight_inbox_options_delete_read_all);
#endif 
#ifdef __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__
    SetHiliteHandler(
        MENU_ID_JMMS_INBOX_OPTIONS_DELETE_DELIVERY_ALL,
        mmi_jmms_highlight_inbox_options_delete_delivery_all);
#endif /* __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__ */ 
    /* Vishal end */
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_PROPERTIES, mmi_jmms_highlight_inbox_options_properties);
    /* Inbox use details highlight handlers */
    SetHiliteHandler(
        MENU_ID_JMMS_INBOX_USE_DETAILS_ADDRESSES_ADD_TO_CONTACT,
        mmi_jmms_highlight_options_use_details_add_to_contact);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_USE_DETAILS_ADDRESSES_CALL, mmi_jmms_highlight_options_use_details_call);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_SAVE_OBJECTS, mmi_jmms_highlight_inbox_options_save_object);

#ifdef __MMI_UNIFIED_MESSAGE__
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_EDIT_MESSAGE, mmi_jmms_highlight_inbox_options_edit_message);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_NUMBER, mmi_jmms_highlight_inbox_options_use_number);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS, mmi_jmms_highlight_inbox_options_use_details);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_EMAIL, mmi_jmms_highlight_options_use_details_email);
    SetHiliteHandler(MENU_ID_JMMS_INBOX_OPTIONS_USE_DETAILS_NUMBER, mmi_jmms_highlight_options_use_details_number);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    g_jmms_context->store_context->inbox_msgs_read_status =
        (U8*) jdd_MemAlloc(sizeof(U8), MAX_READ_UNREAD_STATUS_BYTES);
    if (g_jmms_context->store_context->inbox_msgs_read_status == NULL)
    {
        return;
    }

    ReadRecord(
        NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
        1,
        (g_jmms_context->store_context->inbox_msgs_read_status),
        (U16) MAX_READ_UNREAD_STATUS_BYTES,
        &error);

    /*
     * if (g_jmms_context->store_context->inbox_msgs_read_status[0] == 0xFF)
     * {
     * for (i = 0; i < MAX_READ_UNREAD_STATUS_BYTES; i++)
     * {
     * g_jmms_context->store_context->inbox_msgs_read_status[i] = 0x00;
     * }
     * 
     * WriteRecord(
     * NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
     * 1,
     * (g_jmms_context->store_context->inbox_msgs_read_status),
     * (U16) MAX_READ_UNREAD_STATUS_BYTES,
     * &error);
     * ReadRecord(
     * NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
     * 1,
     * (g_jmms_context->store_context->inbox_msgs_read_status),
     * (U16) MAX_READ_UNREAD_STATUS_BYTES,
     * &error);
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_read_unread_status_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_read_unread_status_bytes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->store_context->inbox_msgs_read_status != NULL)
    {
        jdd_MemFree(g_jmms_context->store_context->inbox_msgs_read_status);
    }

}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_inbox
 * DESCRIPTION
 *  This is pre entry fn for Inbox screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_num_msgs = 0;
    JC_RETCODE ret_code = JC_OK;
    U16 currScrenID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &total_num_msgs);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }
    /* set the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = E_JMMS_INBOX;
    g_jmms_context->msg_open_status[1] = 0;

    if (total_num_msgs == 0)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, JMMS_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }

    g_jmms_context->store_context->num_msg_in_curr_folder = total_num_msgs;
    g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
    g_jmms_context->store_context->current_folder_name = E_JMMS_INBOX;

    mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));

    g_jmms_context->store_context->jmms_start_index = 1;

    mmi_jmms_entry_get_msgs_progress_screen();

    ret_code = mmi_jmms_get_folder_msg_list(&(g_jmms_context->store_context->messages_list), MMI_JMMS_INBOX, total_num_msgs);

    if (ret_code != JC_OK || g_jmms_context->store_context->messages_list == NULL)
    {
        currScrenID = GetActiveScreenId();

        mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));

        if (currScrenID == SCR_ID_JMMS_GET_MSGS_PROGRESS_SCREEN)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ERROR_GET_MSG_LIST),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
            DeleteUptoScrID(SCR_ID_JMMS_MAIN_MENU);
        }
        else
        {
            /* to avoid the show of pop up over Phone call or some other screen */
            HistoryReplace(
                SCR_ID_JMMS_GET_MSGS_PROGRESS_SCREEN,
                SCR_ID_JMMS_GET_MSGS_ERROR_SCREEN,
                mmi_jmms_entry_msgs_get_error_screen);
        }

    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_inbox_screen
 * DESCRIPTION
 *  Entry fn for inbox screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_inbox_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;   /* Buffer holding history data */
    U8 num_item = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &num_item);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }
    //if number of msga in fodelr is not same to as in global var then
    //it means some has been recieved as user was in inbox so need to update
    ///the msgs list
    if (g_jmms_context->store_context->update_nmsgs_in_current_folder)
    {
        mmi_jmms_entry_inbox();
        g_jmms_context->curr_scr_hilited_index = 0;
        return;
    }

    ///Free any pending node to show on ideal screen
    //because after entering into inbox we can't show these nodes on ideal screen
    ///because user may can change the mms e.g. may downlaod a mms notificaction
    //so that notification will not be notification. 
    mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry();

    EntryNewScreen(SCR_ID_JMMS_INBOX, NULL, mmi_jmms_entry_inbox_screen, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_INBOX);

    SetParentHandler(MENU_ID_JMMS_INBOX);
    RegisterHighlightHandler(mmi_jmms_folder_list_highlight_hdlr);

    /* reset the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = 0;
    g_jmms_context->msg_open_status[1] = 0;

    ShowCategory184Screen(
        STR_ID_JMMS_INBOX,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_jmms_context->store_context->num_msg_in_curr_folder,
        mmi_jmms_get_item_data_inbox,
        mmi_jmms_get_item_hint_inbox,
        g_jmms_context->curr_scr_hilited_index,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_inbox_options_scren, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_inbox_options_scren, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_inbox_options_scren, KEY_WAP, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_jmms_back_from_msgs_list_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_from_msgs_list_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_data_inbox
 * DESCRIPTION
 *  fn retrun the item data
 * PARAMETERS
 *  item_index          [IN]        (index of item to be drawn)
 *  str_buff            [IN]        (string of item)
 *  img_buff_p          [IN]        (image corrsponding to item
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_jmms_get_item_data_inbox(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 count = 0;
    mmi_jmms_folder_msgs_list_struct *msgs_list_node_p = NULL;
    U8 msg_index = 0;
    MMI_BOOL is_msg_read = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_POSSIBLE_MESSAGES))
    {
        return FALSE;
    }

    msgs_list_node_p = g_jmms_context->store_context->messages_list;

    while (count != item_index && msgs_list_node_p != NULL)
    {
        msgs_list_node_p = msgs_list_node_p->next_p;
        count++;
    }

    if (msgs_list_node_p == NULL)
    {
        return FALSE;
    }

    mmi_ucs2cpy((S8*) str_buff, msgs_list_node_p->subject_as_caption_p);

    msg_index = g_jmms_context->store_context->num_msg_in_curr_folder - item_index;
    msg_index = msg_index - 1;

    switch (msgs_list_node_p->msg_type)
    {

        case E_MSG_NOTIFICATION:
            *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_MMS_NOTIFICATION));
            break;

        case E_MSG_RECEIVE:
            is_msg_read = mmi_jmms_is_msg_read(msg_index);
            if (is_msg_read == MMI_TRUE)
            {
                *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_NEW_MMS_READ));
            }
            else
            {
                *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_NEW_MMS_UNREAD));
            }
            break;

        case E_MSG_DELIVERY_REPORT:

            is_msg_read = mmi_jmms_is_msg_read(msg_index);
            if (is_msg_read == MMI_TRUE)
            {
                *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_DELIVERY_READ));
            }
            else
            {
                *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_DELIVERY_UNREAD));
            }

            break;

        case E_MSG_JAVA_MESSAGE:
            *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_JAVA_MMS));
            break;

        case E_MSG_READ_REPORT:

            is_msg_read = mmi_jmms_is_msg_read(msg_index);
            if (is_msg_read == MMI_TRUE)
            {
                *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_READ_REPORT_READ));
            }
            else
            {
                *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_READ_REPORT_UNREAD));
            }

            break;

    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_hint_inbox
 * DESCRIPTION
 *  Retrun the hint fot the item to be drawn
 * PARAMETERS
 *  item_index          [IN]        (index of item to be drawn)
 *  hint_array_p        [IN]        (hint buufer for the item_index)
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_get_item_hint_inbox(S32 item_index, UI_string_type *hint_array_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    mmi_jmms_folder_msgs_list_struct *msgs_list_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_POSSIBLE_MESSAGES))
    {
        return FALSE;
    }

    msgs_list_node_p = g_jmms_context->store_context->messages_list;
    while (count != item_index && msgs_list_node_p != NULL)
    {
        msgs_list_node_p = msgs_list_node_p->next_p;
        count++;
    }

    if (msgs_list_node_p == NULL || msgs_list_node_p->address_as_hint_p == NULL)
    {
        return 0;
    }

    if (mmi_ucs2strlen((S8*) (msgs_list_node_p->address_as_hint_p)))
    {
        memset(hint_array_p[0], 0, MAX_SUB_MENU_HINT_SIZE);
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) hint_array_p[0],
            (S8*) (msgs_list_node_p->address_as_hint_p),
            MAX_SUBMENU_CHARACTERS,
            MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        return 0;   /* No Hint Data */
    }

    return TRUE;

}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_inbox_options_scren
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_inbox_options_scren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL status = MMI_FALSE;
    U16 msg_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_type = mmi_jmms_get_msg_type(g_jmms_context->curr_scr_hilited_index);
    if (msg_type == E_MSG_NOTIFICATION)
    {
        status = mmi_jmms_is_notifiction_in_use((U16)
                                                (g_jmms_context->store_context->num_msg_in_curr_folder -
                                                 g_jmms_context->curr_scr_hilited_index));
        if (status == MMI_TRUE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_NOTF_IN_USE),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                (U8) WARNING_TONE);
            return;
        }
    }

    mmi_jmms_entry_inbox_options_scren();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_inbox_options_scren
 * DESCRIPTION
 *  Entry fn for inbox options screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_inbox_options_scren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;                   /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 msg_type = 0;
    U16 parentid;

#ifdef CORRUPT_MMS_HANDLING
    U8 number = 0;
    RETRIEVE_FILTERS StoreRetFilter = {0, };
    MESSAGE_LIST *pMessageList = NULL;
    MESSAGE_LIST *pTempMessageList = NULL;
    JC_RETCODE eRet = JC_OK;
    MESSAGE_NOTIFICATION *notification_p = NULL;
#endif /* CORRUPT_MMS_HANDLING */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    U8 curr_page = 0;
    MEDIA_INFO *image_info_p;
    U8 media_count = 0;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_type = mmi_jmms_get_msg_type(g_jmms_context->curr_scr_hilited_index);
    /* PMT VIKAS START 20060405 */
    // #ifdef __MMI_MMS_SIGNATURE__
    mmi_jmms_reset_fw_flag_of_inbox();
    // #endif
    /* PMT VIKAS END 20060405 */
    mmi_jmms_reset_fw_flag_of_message();
    switch (msg_type)
    {
        case E_MSG_NOTIFICATION:
            parentid = MENU_ID_JMMS_INBOX_OPTIONS_NOTIFICATION;
            break;
        case E_MSG_RECEIVE:
            parentid = MENU_ID_JMMS_INBOX_OPTIONS_NEW_MMS;
            break;
        case E_MSG_DELIVERY_REPORT:
            parentid = MENU_ID_JMMS_INBOX_OPTIONS_DELIVERY_REPORT;
            break;
        case E_MSG_READ_REPORT: /* /Read report have same options as Delivery Report */
            parentid = MENU_ID_JMMS_INBOX_OPTIONS_DELIVERY_REPORT;
            break;
        case E_MSG_JAVA_MESSAGE:
            parentid = MENU_ID_JMMS_INBOX_OPTIONS_JAVA_MMS;
            break;
        default:
            return;
    }

    EntryNewScreen(SCR_ID_JMMS_INBOX_OPTIONS, NULL, mmi_jmms_entry_inbox_options_scren, NULL);
#ifdef __MMI_UNIFIED_MESSAGE__
    DeleteScreenIfPresent(SCR_ID_JMMS_NOTIFICATION_PROPERTIES);
    DeleteScreenIfPresent(SCR_ID_JMMS_RETRIEVED_MMS_PROPERTIES);

    /* sandeep starts to fix PMTSW00006968 */
    if (!(msg_type == E_MSG_DELIVERY_REPORT || msg_type == E_MSG_READ_REPORT ||
          msg_type == E_MSG_NOTIFICATION || msg_type == E_MSG_JAVA_MESSAGE))
    {
        DeleteScreenIfPresent(SCR_ID_JMMS_NEW_MMS);
    }
    /* sandeep ends */

    DeleteScreenIfPresent(SCR_ID_JMMS_READ_REPORT_QUERY);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_INBOX_OPTIONS);
#ifdef __MMI_UNIFIED_MESSAGE__
    DeleteScreenIfPresent(SCR_ID_JMMS_INBOX_OPTIONS);
#endif 
    num_item = GetNumOfChild(parentid);
    /* Vishal Start */
#if defined(__MMI_MMS_DELETE_ALL_DELIVERY_REPORT__)
    if (msg_type == E_MSG_READ_REPORT)
    {   /* if msgtype is read report than hide delete all delivery report menu */
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_DELETE_READ_ALL);
        mmi_frm_hide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_DELETE_DELIVERY_ALL);
        num_item--;
    }
#endif /* defined(__MMI_MMS_DELETE_ALL_DELIVERY_REPORT__) */ 
#if defined(__MMI_MMS_DELETE_ALL_READ_REPORT__)
    if (msg_type == E_MSG_DELIVERY_REPORT)
    {   /* if msgtype is delivery report than hide delete all read report menu */
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_DELETE_DELIVERY_ALL);
        mmi_frm_hide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_DELETE_READ_ALL);
        num_item--;
    }
#endif /* defined(__MMI_MMS_DELETE_ALL_READ_REPORT__) */ 
    /* Vishal end */
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 0, &media_count, E_TRUE);
    mmi_jmms_jdi_get_current_page_index(g_jmms_context->msg_handle, &curr_page);
    image_info_p = mmi_jmms_jdi_get_image_data(curr_page);
    if (g_jmms_context->view_context != NULL)
    {
        if (    /*
                 * g_jmms_context->view_context->focus_object_type == E_MSG_FOCUS_IMAGE ||
                 * g_jmms_context->view_context->focus_object_type == E_MSG_FOCUS_AUDIO ||
                 * g_jmms_context->view_context->focus_object_type == E_MSG_FOCUS_VIDEO ||
                 */
               media_count || g_jmms_context->view_context->view_audio_id || g_jmms_context->view_context->view_video_id
               || image_info_p != NULL)
        {
            mmi_frm_unhide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_SAVE_OBJECTS);
        }
        else
        {
            if (msg_type == E_MSG_RECEIVE)
            {
                mmi_frm_hide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_SAVE_OBJECTS);
                num_item--;
            }
        }
    }
    else
    {
        if (msg_type == E_MSG_RECEIVE)
        {
            mmi_frm_hide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_SAVE_OBJECTS);
            num_item--;
        }
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef CORRUPT_MMS_HANDLING
    if (msg_type == E_MSG_NOTIFICATION)
    {
        number = g_jmms_context->store_context->num_msg_in_curr_folder;
        StoreRetFilter.uiStartIndex = number - g_jmms_context->curr_scr_hilited_index;
        StoreRetFilter.eRetrieve = E_RETRIEVE_BY_INDEX;
        StoreRetFilter.uiNumMessage = 1;
        eRet = mmi_jmms_get_messages_list((char*)MMI_JMMS_INBOX, &pTempMessageList, &StoreRetFilter);
        pMessageList = pTempMessageList;
        if (eRet != JC_OK || pMessageList == NULL)
        {
            mmi_jmms_error_handler(eRet);
            return;
        }
        notification_p = (MESSAGE_NOTIFICATION*) (pMessageList->pMessageHeaders->pHeaders);
        if (notification_p->pContentLocation == NULL || notification_p->pTransactionID == NULL ||
            notification_p->pVersion == NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Notification is Corrupt.Please check headers");
            mmi_frm_hide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_DOWNLOAD);
            num_item--;
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Notification is not corrupt");
            mmi_frm_unhide_menu_item(MENU_ID_JMMS_INBOX_OPTIONS_DOWNLOAD);
        }
    }
#endif /* CORRUPT_MMS_HANDLING */ 
    GetSequenceStringIds_Ext(parentid, str_item_list);

    SetParentHandler(parentid);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#ifndef __MMI_UNIFIED_MESSAGE__
    /* set the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = E_JMMS_INBOX;
    //PMT HIMANSHU START 20060425
    //      g_jmms_context->msg_open_status[1]=(U16)(g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
    g_jmms_context->msg_open_status[1] =
        (U32) mmi_jmms_get_message_id(
                MMI_JMMS_INBOX,
                (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index));
    /* PMT HIMANSHU END 20060425 */
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

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

#ifdef __MMI_UNIFIED_MESSAGE__
    SetRightSoftkeyFunction(mmi_jmms_back_from_option_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_from_option_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_view
 * DESCRIPTION
 *  highlight hdlr of view menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#ifdef __MMI_UNIFIED_MESSAGE__
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_view, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_view, KEY_WAP, KEY_EVENT_DOWN);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetLeftSoftkeyFunction(mmi_jmms_inbox_view, KEY_EVENT_UP);
    /* MAUI_00018463 Start */
    /* SetKeyHandler(mmi_jmms_inbox_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    /* MAUI_00018463 End */
    SetKeyHandler(mmi_jmms_inbox_view, KEY_WAP, KEY_EVENT_DOWN);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_reply
 * DESCRIPTION
 *  highlight hdlr of view menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_reply, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_inbox_reply, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_reply, KEY_WAP, KEY_EVENT_DOWN);
}

#ifdef __MMI_JATAAYU_MMS_REPLY_BY_SMS__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_msg_reply_as_sms
 * DESCRIPTION
 *  Funtion for the reply of mms as sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_msg_reply_as_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct *send_data_p = OslMalloc(sizeof(mmi_frm_sms_api_entry_write_struct));
    U8 pb_number[MAX_PB_NUMBER_LENGTH + 1];
    CONTENT_DATA content = {0, };
    U8 number = 0, *to_address_p = NULL;
    MSG_HANDLE new_msg_handle_p = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGING_HANDLER *msg_handler_p = NULL;
    MESSAGE_RETRIEVAL *receive_headers_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = g_jmms_context->store_context->num_msg_in_curr_folder;
    content.bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message("Inbox", &content, (number - g_jmms_context->curr_scr_hilited_index));
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&new_msg_handle_p, &content, E_TYPE_MMS, E_FALSE);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    msg_handler_p = (MESSAGING_HANDLER*) new_msg_handle_p;
    msg_headers_p = msg_handler_p->pMessageHeaders;
    receive_headers_p = (MESSAGE_RETRIEVAL*) msg_headers_p->pHeaders;
    to_address_p = (U8*) receive_headers_p->pFrom;
    mmi_ucs2_to_asc((S8*) pb_number, (S8*) to_address_p);

    memset((S8*) send_data_p, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

    send_data_p->string = NULL;
    send_data_p->stringlength = 0;
    send_data_p->dcs = SMSAL_UCS2_DCS;
    send_data_p->flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    send_data_p->ascii_addr = pb_number;

    mmi_frm_sms_api_entry_write_msg(send_data_p);
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_delete_screen_from_history_after_rsp();
#endif 
  END:

    OslMfree(send_data_p);
    if (new_msg_handle_p != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(new_msg_handle_p);
    }
#ifdef __MMI_UNIFIED_COMPOSER__
    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_reply_by_sms
 * DESCRIPTION
 *  highlight hdlr of by sms menu item in reply
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_reply_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_jmms_msg_reply_as_sms, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_msg_reply_as_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_msg_reply_as_sms, KEY_WAP, KEY_EVENT_DOWN);
}
#endif /* __MMI_JATAAYU_MMS_REPLY_BY_SMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_reply_all
 * DESCRIPTION
 *  highlight hdlr of view menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_reply_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_reply_all, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_inbox_reply_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_reply_all, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_forward
 * DESCRIPTION
 *  highlight hdlr of view menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_inbox_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_forward, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_download
 * DESCRIPTION
 *  highlight hdlr of view menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_download, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_inbox_download, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_download, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_delete
 * DESCRIPTION
 *  highlight hdlr of view menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_pre_delete, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_pre_delete, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_delete_all
 * DESCRIPTION
 *  highlight hdlr of delete all menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_delete_all, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_delete_all, KEY_WAP, KEY_EVENT_DOWN);
}

/* Vishal Start */
#ifdef __MMI_MMS_DELETE_ALL_READ_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_delete_read_all
 * DESCRIPTION
 *  highlight hdlr of delete all read report menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_delete_read_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_delete_read_all, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_delete_read_all, KEY_WAP, KEY_EVENT_DOWN);
}
#endif /* __MMI_MMS_DELETE_ALL_READ_REPORT__ */ 
#ifdef __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_delete_delivery_all
 * DESCRIPTION
 *  highlight hdlr of delete all delivery report menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_delete_delivery_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_delete_delivery_all, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_delete_delivery_all, KEY_WAP, KEY_EVENT_DOWN);
}
#endif /* __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__ */ 
/* Vishal end */

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_use_details
 * DESCRIPTION
 *  highlight hdlr of use details menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_UNIFIED_MESSAGE__
void mmi_jmms_highlight_inbox_options_use_number(void)
#else 
void mmi_jmms_highlight_inbox_options_use_details(void)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_use_details, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_jmms_inbox_use_details, KEY_SEND, KEY_EVENT_UP); */
    SetKeyHandler(mmi_jmms_inbox_use_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_use_details, KEY_WAP, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_properties
 * DESCRIPTION
 *  highlight hdlr of properties menu item in Inbox options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_inbox_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_inbox_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_inbox_properties, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_index = 0;

#ifndef __MMI_UNIFIED_MESSAGE__
    U8 index = 0;
#endif 
    mmi_jmms_folder_msgs_list_struct *node_p = NULL;
    MMI_BOOL is_msg_read = MMI_TRUE;
    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA content = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->store_context->messages_list;
#ifdef __MMI_UNIFIED_MESSAGE__
    while (node_p != NULL)
    {
        if (node_p->msg_index == g_jmms_context->curr_scr_hilited_index)
        {
            break;
        }
        node_p = node_p->next_p;
    }
    if (node_p == NULL)
    {
        return;
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    while (index < g_jmms_context->curr_scr_hilited_index)
    {
        node_p = node_p->next_p;
        index++;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    /* /set the msg status as read if first time read */
    msg_index = g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index;
    msg_index = msg_index - 1;
    is_msg_read = mmi_jmms_is_msg_read(msg_index);
#ifdef __MMI_UNIFIED_MESSAGE__
    if ((is_msg_read == MMI_FALSE) && node_p->msg_type != E_MSG_NOTIFICATION && node_p->msg_type != E_MSG_JAVA_MESSAGE)
#else 
    if (is_msg_read == MMI_FALSE)
#endif 
    {
        mmi_jmms_set_msg_as_read(msg_index);
    }

    //TODO:: need to test read report PDU and Delivery Report PDU
    ///currently not able to save these PDUs. Will able to test
    ///in T3
#ifdef __MMI_UNIFIED_MESSAGE__
    if (node_p->msg_type == E_MSG_DELIVERY_REPORT || node_p->msg_type == E_MSG_READ_REPORT ||
        node_p->msg_type == E_MSG_NOTIFICATION || node_p->msg_type == E_MSG_JAVA_MESSAGE)
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (node_p->msg_type == E_MSG_DELIVERY_REPORT || node_p->msg_type == E_MSG_READ_REPORT)
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (node_p->msg_type == E_MSG_NOTIFICATION)
        {
            MMI_BOOL status = mmi_jmms_is_notifiction_in_use((U16)
                                                             (g_jmms_context->store_context->num_msg_in_curr_folder -
                                                              g_jmms_context->curr_scr_hilited_index));
            if (status == MMI_TRUE)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_NOTF_IN_USE),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) WARNING_TONE);
                return;
            }
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        mmi_jmms_show_mms_properties(node_p->msg_type, MMI_JMMS_INBOX);
        return;
    }
    else
    {

        content.bIsStream = E_TRUE;
        ret_code = mmi_jmms_get_message(
                    "Inbox",
                    &content,
                    (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index));

        if (ret_code != JC_OK)
        {
            goto END;
        }

        if (is_msg_read == MMI_FALSE)
        {
            ///it means first time viewing the mms.
            ///so need to check for read report require to send

            mmi_jmms_deinit_mms_context(g_jmms_context);

            ret_code = mmi_jmms_jdi_parse_msg_buffer(&(g_jmms_context->msg_handle), &content, E_TYPE_MMS, E_FALSE);

            /* Async changes start */
            while (ret_code == JC_ERR_MMS_PARSE_PENDING)
            {
                ret_code = mmi_jmms_jdi_msg_parse_continue(g_jmms_context->msg_handle);
            };
            /* Async changes end */

            if (JC_OK != ret_code)
            {
                goto END;
            }

            ret_code = mmi_jmms_jdi_get_msg_headers(
                        g_jmms_context->msg_handle,
                        (MESSAGE_HEADERS **) (&(g_jmms_context->msg_headers_p)));
            if (JC_OK != ret_code)
            {
                goto END;
            }

            g_jmms_context->msg_header_type_p =
                (MESSAGE_RETRIEVAL*) ((MESSAGE_HEADERS*) g_jmms_context->msg_headers_p)->pHeaders;

            g_jmms_context->last_scr_id = SCR_ID_JMMS_INBOX_OPTIONS;

            g_jmms_context->mms_index =
                g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index;

            g_jmms_context->is_unread_msg_deleted = 0;
        #ifdef __MMI_UNIFIED_MESSAGE__
            g_jmms_context->show_property_screen = MMI_FALSE;
        #endif 
            mmi_jmms_handle_read_report(g_jmms_context->msg_header_type_p);

        }
        else
        {

            /* /TODO:: to be added by deeapali */
            g_jmms_context->last_scr_id = SCR_ID_JMMS_INBOX_OPTIONS;
        #ifdef __MMI_UNIFIED_MESSAGE__
            mmi_jmms_deinit_view();
        #endif 
            ret_code = mmi_jmms_pre_entry_mms_view(&content);
            if (ret_code == JC_ERR_MMS_PARSE_PENDING)
            {
                return;
            }
        }
    }

  END:

    if (ret_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }

    if (ret_code != JC_OK)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_reply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_reply_message(E_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_reply_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_reply_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_reply_message(E_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_reply_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  reply_all       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_reply_message(JC_BOOLEAN reply_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __MMI_UNIFIED_COMPOSER__
    CONTENT_DATA content = {0, };
    MSG_HANDLE h_temp_msg = NULL;
    S8 *temp_str_p = NULL;
    S8 *str_p = NULL;
    S32 len = 0;
    S32 start_index = 0;
    JC_RETCODE ret_code = JC_OK;
    U8 ret = 0;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_SEND *send_p = NULL;
    MMI_BOOL is_email = MMI_FALSE;
    S32 len_to_copy = 0;
    MMI_BOOL is_duplicate = MMI_FALSE;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    U8 number = 0;

#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = g_jmms_context->store_context->num_msg_in_curr_folder;
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_uc_reply_message(
        reply_all,
        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
    return;
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    ret_code = jdi_MsgInit(&h_temp_msg, NULL);
    if (JC_OK != ret_code)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    content.bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message("Inbox", &content, (number - g_jmms_context->curr_scr_hilited_index));

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    if (g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
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
#endif /* 0 */ 
    ret_code = mmi_jmms_jdi_msg_reply(h_temp_msg, &content, reply_all, &(g_jmms_context->msg_handle));
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

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

    ret_code = mmi_jmms_jdi_set_creation_mode(g_jmms_context->msg_handle, mmi_jmms_compose_settings_creation_mode());
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
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

    ret_code = mmi_jmms_jdi_msg_register_callback(
                g_jmms_context->msg_handle,
                E_CB_REPLY_CHARGING,
                (void*)mmi_jmms_reply_charging_ind_cb);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        ret_code = JC_ERR_STORE_FILE_CORRUPTED;
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    if (msg_headers_p->eMsgType != E_MSG_TYPE_SEND)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        goto END;
    }

    send_p = (MESSAGE_SEND*) (msg_headers_p->pHeaders);

    mmi_jmms_free_addresses_list();

    /* /Make the To Addresses list */

    if (send_p->pTo != NULL)
    {
        str_p = (S8*) (send_p->pTo);
        len = 0;
        start_index = 0;
        g_jmms_context->address_list_flag = E_TO_ADDRESSES;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {

            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                if ((*str_p) == '@')
                {
                    is_email = MMI_TRUE;
                }

                len++;
                str_p = str_p + ENCODING_LENGTH;

            }

            if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            temp_str_p = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (temp_str_p == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                goto END;
            }
            mmi_ucs2ncpy((S8*) temp_str_p, (S8*) (send_p->pTo + start_index), len_to_copy);

            if ((is_duplicate = mmi_jmms_check_duplicate_address((U8*) temp_str_p, E_NONE_ADDRESSES, -1)) != MMI_TRUE) /* compiler warning removal */
            {
                ret = mmi_jmms_add_address_in_addresse_list((S8*) temp_str_p);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    goto END;
                }
            }

            if (temp_str_p != NULL)
            {
                jdd_MemFree(temp_str_p);
                temp_str_p = NULL;
            }

            start_index = start_index + len + 1;
            len = 0;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }

        }

        if (temp_str_p != NULL)
        {
            jdd_MemFree(temp_str_p);
            temp_str_p = NULL;
        }
    }

    /* /Make the Cc Addresses list */
    if (send_p->pCc != NULL)
    {

        str_p = (S8*) (send_p->pCc);
        len = 0;
        start_index = 0;
        g_jmms_context->address_list_flag = E_CC_ADDRESSES;
        is_email = MMI_FALSE;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {

            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                len++;

                if ((*str_p) == '@')
                {
                    is_email = MMI_TRUE;
                }

                str_p = str_p + ENCODING_LENGTH;
            }

            if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            temp_str_p = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (temp_str_p == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                goto END;
            }
            mmi_ucs2ncpy((S8*) temp_str_p, (S8*) (send_p->pCc + start_index), len_to_copy);

            if ((is_duplicate = mmi_jmms_check_duplicate_address((U8*) temp_str_p, E_NONE_ADDRESSES, -1)) != MMI_TRUE) /* compiler warning removal */
            {
                ret = mmi_jmms_add_address_in_addresse_list((S8*) temp_str_p);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    goto END;
                }
            }

            if (temp_str_p != NULL)
            {
                jdd_MemFree(temp_str_p);
                temp_str_p = NULL;
            }

            start_index = start_index + len + 1;
            len = 0;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }
        }

        if (temp_str_p != NULL)
        {
            jdd_MemFree(temp_str_p);
            temp_str_p = NULL;
        }

    }

    /* /Make the BCc Addresses list */
    if (send_p->pBcc != NULL)
    {
        str_p = (S8*) (send_p->pBcc);
        len = 0;
        start_index = 0;
        g_jmms_context->address_list_flag = E_BCC_ADDRESSES;
        is_email = MMI_FALSE;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {

            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                len++;
                if ((*str_p) == '@')
                {
                    is_email = MMI_TRUE;
                }
                str_p = str_p + ENCODING_LENGTH;
            }

            if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }

            temp_str_p = (S8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
            if (temp_str_p == NULL)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                goto END;
            }
            mmi_ucs2ncpy((S8*) temp_str_p, (S8*) (send_p->pBcc + start_index), len_to_copy);

            if ((is_duplicate = mmi_jmms_check_duplicate_address((U8*) temp_str_p, E_NONE_ADDRESSES, -1)) != MMI_TRUE) /* compiler warning removal */
            {
                ret = mmi_jmms_add_address_in_addresse_list((S8*) temp_str_p);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    goto END;
                }
            }

            if (temp_str_p != NULL)
            {
                jdd_MemFree(temp_str_p);
                temp_str_p = NULL;
            }

            start_index = start_index + len + 1;
            len = 0;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }
        }
    }

    /* /Make the subject buffer */
    memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
    if (send_p->pSubject != NULL)
    {

        len = (mmi_ucs2strlen((S8*) (send_p->pSubject))) * ENCODING_LENGTH;

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

    /* g_jmms_context->g_use_local_send_setings = 0; */
    /* MAUI_00227929 Start */
    g_jmms_context->g_use_local_send_setings = 0;
    mmi_jmms_fill_mms_sending_settings();
    /* MAUI_00227929 End */
    if (g_jmms_context->is_add_media_warning == 0)
    {
        mmi_jmms_entry_write_message_screen();
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

  END:

    if (temp_str_p != NULL)
    {
        jdd_MemFree(temp_str_p);
        temp_str_p = NULL;
    }

    // TODO:: need to check whether this is to do or not
    if (h_temp_msg != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(h_temp_msg);
        h_temp_msg = NULL;
    }

    if (content.pFileName != NULL)
    {
        jdd_MemFree(content.pFileName);
        content.pFileName = NULL;
    }

    if (ret_code != JC_OK)
    {
        mmi_jmms_deinit_mms_context(g_jmms_context);
    }

    g_jmms_context->is_add_media_warning = 0;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_forward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_UNIFIED_MESSAGE__)
    U8 number = 0;
    MSG_HANDLE h_temp_msg = NULL;
#endif /* !defined(__MMI_UNIFIED_MESSAGE__) */ 
#if defined(__MMI_UNIFIED_MESSAGE__) && !defined (__MMI_UNIFIED_COMPOSER__)
    ECreationMode create_mode;
    U8 curr_page = 0;
#endif /* defined(__MMI_UNIFIED_MESSAGE__) && !defined (__MMI_UNIFIED_COMPOSER__) */ 
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_MESSAGE__
    number = g_jmms_context->store_context->num_msg_in_curr_folder;
    ret_code = jdi_MsgInit(&h_temp_msg, NULL);
    if (JC_OK != ret_code)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    if (g_jmms_context->parse_content_p != NULL)
    {
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }
    g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message(
                "Inbox",
                g_jmms_context->parse_content_p,
                (number - g_jmms_context->curr_scr_hilited_index));

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    if (g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }

    mmi_jmms_parsing_progressing_screen();
    ret_code = mmi_jmms_jdi_msg_forward(h_temp_msg, g_jmms_context->parse_content_p, &(g_jmms_context->msg_handle));
    if (h_temp_msg != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(h_temp_msg);
        h_temp_msg = NULL;
    }
#ifdef __DRM_SUPPORT__
    mmi_jmms_jdi_msg_register_callback(
        g_jmms_context->msg_handle,
        E_CB_DRM_IND,
        (void*)mmi_jmms_drm_indication_handler);
    mmi_jmms_jdi_msg_register_callback(
        g_jmms_context->msg_handle,
        E_CB_DRM_UPDATE_RIGHTS,
        (void*)mmi_jmms_drm_rights_update_handler);
    mmi_jmms_jdi_msg_register_callback(
        g_jmms_context->msg_handle,
        E_CB_DRM_INFO_LIST,
        (void*)mmi_jmms_drm_info_list_ind_handler);
    mmi_jmms_jdi_msg_register_callback(
        g_jmms_context->msg_handle,
        E_CB_DRM_CANCEL,
        (void*)mmi_jmms_drm_cancel_parse_handler);
#endif /* __DRM_SUPPORT__ */ 
    mmi_jmms_jdi_msg_register_callback(g_jmms_context->msg_handle, E_CB_ERROR_IND, (void*)mmi_jmms_error_ind_cb);

    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(
            g_jmms_context->msg_handle,
            mmi_jmms_inbox_forward_async_callback,
            mmi_jmms_only_abort_parsing_progress);
        return;
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ /* #ifndef __MMI_UNIFIED_MESSAGE__ */
    {
        U8 page_count = 0;

        mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
        if (page_count >= mmi_jmms_compose_settings_max_no_pages())
        {
            ret_code = JC_ERR_MSG_MORE_THAN_MAX_PAGE;
            mmi_jmms_error_handler(ret_code);
            return;
        }
    }
    if (mmi_jmms_is_corrupted_video_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        return;
    }
#ifdef __MMI_UNIFIED_COMPOSER__
#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_FALSE) == E_TRUE)
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
#else /* __MMI_UNIFIED_COMPOSER__ */ 

#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_FALSE) == E_TRUE)
    {
        ret_code = -1;
        goto END;
    }
#endif /* __DRM_SUPPORT__ */ 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifdef __MMI_UNIFIED_COMPOSER__
    {
        ECreationMode create_mode;

        create_mode = mmi_jmms_compose_settings_creation_mode();
        if (create_mode == E_CREATION_MODE_RESTRICTED)
        {
            if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
            {
                ret_code = JC_ERR_MSG_MMS_CONTENT_RESTRICTED;
                mmi_jmms_error_handler(ret_code);
                return;
            }
        }
    }
    mmi_jmms_uc_compose_edit_fw_request(
        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index,
        MMI_JMMS_INBOX);
    return;
#else /* __MMI_UNIFIED_COMPOSER__ */ 
    create_mode = mmi_jmms_compose_settings_creation_mode();

    if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
    {
        if (create_mode == E_CREATION_MODE_RESTRICTED)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_MMS_ERR_RESTRICTED_CONTENT_CLASS),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            return;
        }
        else if (create_mode == E_CREATION_MODE_WARNING)
        {
            g_jmms_context->is_add_media_warning = 1;
        }
    }
    if (g_jmms_context->msg_handle)
    {
        mmi_jmms_jdi_get_current_page_index(g_jmms_context->msg_handle, &curr_page);
    }
    g_jmms_context->edit_error_code = JC_OK;
    ret_code = mmi_jmms_jdi_preforwardheader(&g_jmms_context->msg_handle);      /* Forward parsing */
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        if (curr_page > 1 && g_jmms_context->msg_handle)
        {
            gui_lock_double_buffer();
            mmi_jmms_restore_view_callbacks();
            mmi_jmms_jdi_view_event(g_jmms_context->msg_handle, E_VIEW_SET_ACTIVE_SLIDE, &curr_page);
            gui_unlock_double_buffer();
        }
        goto END;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifndef __MMI_UNIFIED_COMPOSER__
    mmi_jmms_inbox_forward_async_callback(ret_code);
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_jmms_context->edit_error_code != JC_OK && curr_page > 1 && g_jmms_context->msg_handle)
    {
        gui_lock_double_buffer();
        mmi_jmms_restore_view_callbacks();
        mmi_jmms_jdi_view_event(g_jmms_context->msg_handle, E_VIEW_SET_ACTIVE_SLIDE, &curr_page);
        gui_unlock_double_buffer();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    return;

  END:

    // TODO:: need to check whether this is to do or not
#ifndef __MMI_UNIFIED_MESSAGE__
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
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    g_jmms_context->is_add_media_warning = 0;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_forward_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_forward_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_SEND *send_p = NULL;
    S32 len = 0;
    U8 total_pages = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret_code != JC_OK)
    {
        if (GetActiveScreenId() == SCR_ID_JMMS_PARSING_PROGRESS)
        {
            mmi_jmms_error_handler(ret_code);
        }
        goto END;
    }
#ifndef __MMI_UNIFIED_MESSAGE__
    if (mmi_jmms_is_corrupted_video_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        ret_code = -1;
        goto END;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
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

    ret_code = mmi_jmms_jdi_set_creation_mode(g_jmms_context->msg_handle, mmi_jmms_compose_settings_creation_mode());
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
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
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &total_pages);
    ret_code = mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, total_pages);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        ret_code = JC_ERR_STORE_FILE_CORRUPTED;
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    if (msg_headers_p->eMsgType != E_MSG_TYPE_SEND)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        goto END;
    }
    send_p = (MESSAGE_SEND*) (msg_headers_p->pHeaders);

    mmi_jmms_free_addresses_list();

    /* /Make the subject buffer */
    memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
    if (send_p->pSubject != NULL)
    {

        len = (mmi_ucs2strlen((S8*) (send_p->pSubject))) * ENCODING_LENGTH;

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

    /* PMT VIKAS START 20060405 */
    // #ifdef __MMI_MMS_SIGNATURE__
    mmi_jmms_set_fw_flag_of_inbox();
    // #endif
    /* PMT VIKAS END 20060405 */
    mmi_jmms_set_fw_flag_of_message();
    /* g_jmms_context->g_use_local_send_setings = 0; */
    /* MAUI_00227929 Start */
    g_jmms_context->g_use_local_send_setings = 1;
    mmi_jmms_fill_mms_sending_settings();
    /* MAUI_00227929 End */

    if (g_jmms_context->is_add_media_warning == 0)
    {
        mmi_jmms_entry_write_message_screen();
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

  END:

    // TODO:: need to check whether this is to do or not
#ifndef __MMI_UNIFIED_MESSAGE__
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
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    g_jmms_context->is_add_media_warning = 0;

    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);

}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MESSAGE_NOTIFICATION *notification_p = NULL;
    JC_RETCODE ret_code = JC_OK;
    U8 number = 0;

    RETRIEVE_FILTERS store_ret_filter = {0, };
    MESSAGE_LIST *message_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = g_jmms_context->store_context->num_msg_in_curr_folder;

    store_ret_filter.uiStartIndex = number - g_jmms_context->curr_scr_hilited_index;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    store_ret_filter.uiNumMessage = 1;

    ret_code = mmi_jmms_get_messages_list(MMI_JMMS_INBOX, &message_list_p, &store_ret_filter);

    if (message_list_p == NULL || ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s: %d", "mmi_jmms_inbox_download error getting message list", ret_code);
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        return;
    }

    if (message_list_p->pMessageHeaders->eMsgType != E_MSG_TYPE_NOTIFICATION)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                             "mmi_jmms_inbox_download error eMsgType is not E_MSG_TYPE_NOTIFICATION(%d)",
                             message_list_p->pMessageHeaders->eMsgType);
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        return;
    }

    notification_p = (MESSAGE_NOTIFICATION*) (message_list_p->pMessageHeaders->pHeaders);
#ifdef __MMI_JMMS_NO_OMA_CONF_273__
    if (notification_p->uiMessageSize > mmi_jmms_retrieval_settings_msg_size_filter())
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_OPTIONS_MSG_SIZE_EXCEED),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
        return;
    }
#endif /* __MMI_JMMS_NO_OMA_CONF_273__ */ 
    ret_code = mmi_jmms_download_mms((JC_INT8*) notification_p->pContentLocation,
                                     E_TYPE_DEFFERED_RETRIEVAL_FETCH,
                                     (number - g_jmms_context->curr_scr_hilited_index), 1
#ifdef __MMI_UNIFIED_COMPOSER__
                                     , mmi_jmms_handle_screen_flow_callback
#endif 
        );
    if (ret_code == JC_OK)
    {
        /* /added for retry mechanism */

        g_jmms_context->last_scr_id = GetActiveScreenId();
        g_jmms_context->progress_screen_title = STR_ID_JMMS_MMS_DOWNLOADING;
        memset(g_jmms_context->g_jmms_progress_str, 0x00, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);
        mmi_jmms_entry_communication_progress_screen();

    }

#ifdef __MMI_JMMS_EXPIRY_HANDLING__
    else if (ret_code == E_MESSAGE_EXPIRED)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_MMS_MSG_EXPIRED),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
    }
#endif /* __MMI_JMMS_EXPIRY_HANDLING__ */ 

#ifdef __MMI_JMMS_NO_OMA_CONF_273__
    else if (ret_code == E_MEMORY_FULL_ERROR)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_MMS_SIZE_EXCEEDS),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
    }
#endif /* __MMI_JMMS_NO_OMA_CONF_273__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_pre_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_pre_delete(void)
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
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_inbox_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_index = 0;
    U8 index = 0;
    mmi_jmms_folder_msgs_list_struct *node_p = NULL;
    MMI_BOOL is_msg_read = MMI_TRUE;
    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA content = {0, };
    U8 number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->store_context->messages_list;
    while (index < g_jmms_context->curr_scr_hilited_index)
    {
        node_p = node_p->next_p;
        index++;
    }

    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_INBOX, IMG_GLOBAL_DELETED);

    number = g_jmms_context->store_context->num_msg_in_curr_folder;
    /* /set the msg status as read if first time read */
    msg_index = number - g_jmms_context->curr_scr_hilited_index;
    msg_index = msg_index - 1;
    is_msg_read = mmi_jmms_is_msg_read(msg_index);

    if (is_msg_read == MMI_FALSE && node_p->msg_type != E_MSG_DELIVERY_REPORT && node_p->msg_type != E_MSG_READ_REPORT
        && node_p->msg_type != E_MSG_NOTIFICATION)
    {
        content.bIsStream = E_TRUE;
        ret_code = mmi_jmms_get_message(
                    "Inbox",
                    &content,
                    (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index));

        if (ret_code != JC_OK)
        {
            goto END;
        }

        mmi_jmms_deinit_mms_context(g_jmms_context);

        ret_code = mmi_jmms_jdi_parse_msg_buffer(&(g_jmms_context->msg_handle), &content, E_TYPE_MMS, E_FALSE);

        /* Async changes start */
        while (ret_code == JC_ERR_MMS_PARSE_PENDING)
        {
            ret_code = mmi_jmms_jdi_msg_parse_continue(g_jmms_context->msg_handle);
        };
        /* Async changes end */

        if (JC_OK != ret_code)
        {
            goto END;
        }

        ret_code = mmi_jmms_jdi_get_msg_headers(
                    g_jmms_context->msg_handle,
                    (MESSAGE_HEADERS **) (&(g_jmms_context->msg_headers_p)));
        if (JC_OK != ret_code)
        {
            goto END;
        }

        g_jmms_context->msg_header_type_p =
            (MESSAGE_RETRIEVAL*) ((MESSAGE_HEADERS*) g_jmms_context->msg_headers_p)->pHeaders;

    }

    ret_code = mmi_jmms_delete_message(MMI_JMMS_INBOX, msg_index + 1);

    if (ret_code == JC_OK)
    {

        mmi_jmms_delete_msg_status(msg_index);

        mmi_jmms_update_status_icon_indicator();

    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_INBOX, SCR_ID_UM_INBOX, mmi_um_jmms_pre_entry_inbox);
    #else 
        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
    #endif 

    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_INBOX);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        if (number <= 1)    /* /now folder will empty */
        {
            DeleteUptoScrID(SCR_ID_JMMS_MAIN_MENU);
        }
        else
        {
            DeleteUptoScrID(SCR_ID_JMMS_INBOX);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        if (is_msg_read == MMI_FALSE && node_p->msg_type != E_MSG_DELIVERY_REPORT &&
            node_p->msg_type != E_MSG_READ_REPORT && node_p->msg_type != E_MSG_NOTIFICATION)
        {
            g_jmms_context->is_unread_msg_deleted = 1;
            mmi_jmms_handle_read_report(g_jmms_context->msg_header_type_p);
        }

        if (g_jmms_context->msg_header_type_p != NULL)
        {
            g_jmms_context->msg_header_type_p = NULL;
        }
        if (g_jmms_context->msg_headers_p != NULL)
        {
            g_jmms_context->msg_headers_p = NULL;
        }
    }
    else
    {
        goto END;
    }
    return;

  END:
    if (g_jmms_context->msg_header_type_p != NULL)
    {
        g_jmms_context->msg_header_type_p = NULL;
    }
    if (g_jmms_context->msg_headers_p != NULL)
    {
        g_jmms_context->msg_headers_p = NULL;
    }
    if (ret_code != JC_OK && g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_deinit_mms_context(g_jmms_context);
        g_jmms_context->msg_handle = NULL;
    }

    DisplayPopup((U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
#ifdef __MMI_UNIFIED_MESSAGE__
    DeleteUptoScrID(SCR_ID_UM_INBOX);
#else 
    DeleteUptoScrID(SCR_ID_JMMS_INBOX);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    /* Dilip 29 Aug 2006 */
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_JMMS_DELETE_ALL_UM_INBOX),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    /* Dilip 29 Aug 2006 */
    SetLeftSoftkeyFunction(mmi_um_jmms_delete_all, KEY_EVENT_UP);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    /* Dilip 29 Aug 2006 */
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        /* MAUI_00018477 Start */ get_string(STR_ID_JMMS_DELETE_ALL_UM_INBOX),
        /* MAUI_00018477 End */ IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    /* Dilip 29 Aug 2006 */
    SetLeftSoftkeyFunction(mmi_jmms_delete_all_message_inbox, KEY_EVENT_UP);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/* Vishal Start */
#ifdef __MMI_MMS_DELETE_ALL_READ_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_delete_read_all
 * DESCRIPTION
 *  confirmation screen for delete all read reports
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_delete_read_all(void)
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
        get_string(STR_ID_JMMS_CONFIRM_DELETE_READ_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_delete_read_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* __MMI_MMS_DELETE_ALL_READ_REPORT__ */ 
#ifdef __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_delete_delivery_all
 * DESCRIPTION
 *  confirmation screen for delete all delivery reports
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_delete_delivery_all(void)
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
        get_string(STR_ID_JMMS_CONFIRM_DELETE_DELIVERY_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_delete_delivery_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__ */ 
/* Vishal end */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_message_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_all_message_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_INBOX, IMG_GLOBAL_PROGRESS);
    if (mmi_jmms_is_immediate_retrival_underway())
    {
        ret_code = -1;
    }
    else
    {
        ret_code = mmi_jmms_delete_all_message(MMI_JMMS_INBOX);
    }
    if (JC_OK != ret_code)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_INBOX);
    }
    else
    {
        /* /reset all msgs status as unread */
        mmi_jmms_delete_all_msgs_status();

        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_MAIN_MENU);
        mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
    }

}

/* Vishal Start */
#ifdef __MMI_MMS_DELETE_ALL_READ_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_read_all
 * DESCRIPTION
 *  this function calls the api to delete all msg by type with msg type as read report
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_read_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_INBOX, IMG_GLOBAL_PROGRESS);
    if (mmi_jmms_is_immediate_retrival_underway())
    {
        ret_code = -1;
    }
    else
    {
        ret_code = mmi_jmms_delete_all_message_by_type(MMI_JMMS_INBOX, E_MSG_TYPE_READ_REPORT_RESPONSE);
    }
    if (JC_OK != ret_code)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_INBOX);
    #else 
        DeleteUptoScrID(SCR_ID_JMMS_INBOX);
    #endif 
    }
    else
    {

        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);

    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_INBOX);
        mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
        DeleteUptoScrID(SCR_ID_JMMS_INBOX);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

    }

}
#endif /* __MMI_MMS_DELETE_ALL_READ_REPORT__ */ 

#ifdef __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_delivery_all
 * DESCRIPTION
 *  this function calls the api to delete all msg by type with msg type as delivery report
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_delivery_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_INBOX, IMG_GLOBAL_PROGRESS);

    ret_code = mmi_jmms_delete_all_message_by_type(MMI_JMMS_INBOX, E_MSG_TYPE_DELIVERY_REPORT);

    if (JC_OK != ret_code)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_INBOX);
    #else 
        DeleteUptoScrID(SCR_ID_JMMS_INBOX);
    #endif 
    }
    else
    {

        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_INBOX);
        mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        HistoryReplace(SCR_ID_JMMS_INBOX, SCR_ID_JMMS_INBOX, mmi_jmms_entry_inbox);
        DeleteUptoScrID(SCR_ID_JMMS_INBOX);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

    }

}

#endif /* __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__ */ 
/* Vishal end */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_use_details
 * DESCRIPTION
 *  Pre entry fn for use details screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_pre_entry_use_details_screen(MMI_JMMS_INBOX);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inbox_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inbox_properties(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_type = mmi_jmms_get_msg_type(g_jmms_context->curr_scr_hilited_index);

    if (msg_type == E_MSG_NOTIFICATION || msg_type == E_MSG_JAVA_MESSAGE || msg_type == E_MSG_DELIVERY_REPORT ||
        msg_type == E_MSG_READ_REPORT)
    {
        g_jmms_context->last_scr_id = SCR_ID_JMMS_INBOX_OPTIONS;
    }
    mmi_jmms_show_mms_properties(msg_type, MMI_JMMS_INBOX);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    mmi_jmms_folder_msgs_list_struct *node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = g_jmms_context->store_context->messages_list;
    while (index < g_jmms_context->curr_scr_hilited_index)
    {
        node_p = node_p->next_p;
        index++;
    }

    mmi_jmms_show_mms_properties(node_p->msg_type, MMI_JMMS_INBOX);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

/* /1 means read and 0 as unread */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_save_object(void)
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

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_inbox_options_edit_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_inbox_options_edit_message(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_inbox_edit_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_inbox_edit_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_inbox_edit_message, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_inbox_edit_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_inbox_edit_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    U8 curr_page = 0;

    if (g_jmms_context->msg_handle)
    {
        mmi_jmms_jdi_get_current_page_index(g_jmms_context->msg_handle, &curr_page);
    }
    g_jmms_context->edit_error_code = JC_OK;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
    g_jmms_context->g_use_local_send_setings = 0;   /* sanjeev  5/1/07 */
    mmi_jmms_edit_message(MMI_JMMS_INBOX);
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_jmms_context->edit_error_code != JC_OK && curr_page > 1 && g_jmms_context->msg_handle)
    {
        gui_lock_double_buffer();
        mmi_jmms_jdi_view_event(g_jmms_context->msg_handle, E_VIEW_SET_ACTIVE_SLIDE, &curr_page);
        gui_unlock_double_buffer();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#endif /* _MMI_JMMSINBOXSECMMI_C */ 


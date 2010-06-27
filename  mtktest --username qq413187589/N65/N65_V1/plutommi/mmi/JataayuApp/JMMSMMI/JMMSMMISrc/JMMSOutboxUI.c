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
 *  JMMSOutboxUI.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui for outbox folder in MMS
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_JMMSOUTBOXSECMMI_C
#define _MMI_JMMSOUTBOXSECMMI_C

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
#include "JMMSOutbox.h"
#include "JMMSCoreAPI.h"

#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include <jdi_communicator.h>

#include <MessagingDatatypes.h>
#include <MessagingAPI.h>
#include <PrvMessagingDataTypes.h>
#include <MM1DataTypes.h>
#include <ComposeUtils.h>
#include "JMMSCoreAPI.h"
#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
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
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageProt.h"
#include "JMMSUMHandling.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#include "wapadp.h"     /* compiler warning removal */
#ifdef __MMI_UNIFIED_COMPOSER__
#include "JMMSUCInterfaceProt.h"
#endif 
#include <PrvMessagingDataTypes.h>

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
extern U16 DeleteScreenFromToNnodes(U16 Scr_id, U16 num_nodes);
extern U8 DeleteFromScrUptoScr(U16 beyond_scrn_id, U16 till_scrnid);

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox
 * DESCRIPTION
 *  Highlight hdlr of Outbox menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_outbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_outbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_outbox, KEY_WAP, KEY_EVENT_DOWN);

}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_init
 * DESCRIPTION
 *  This function init the hilight handlers of outbox menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Outbox options Highlight handlers */
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_VIEW, mmi_jmms_highlight_outbox_options_view);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_RESEND, mmi_jmms_highlight_outbox_options_resend);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_DELETE, mmi_jmms_highlight_outbox_options_delete);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_DELETE_ALL, mmi_jmms_highlight_outbox_options_delete_all);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_PROPERTIES, mmi_jmms_highlight_outbox_options_properties);
    /* Outbox use details highlight handlers */
    SetHiliteHandler(
        MENU_ID_JMMS_OUTBOX_USE_DETAILS_ADDRESSES_ADD_TO_CONTACT,
        mmi_jmms_highlight_options_use_details_add_to_contact);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_USE_DETAILS_ADDRESSES_CALL, mmi_jmms_highlight_options_use_details_call);

#ifdef __MMI_UNIFIED_MESSAGE__
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_EDIT_MESSAGE, mmi_jmms_highlight_outbox_options_edit_message);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_SAVE_OBJECTS, mmi_jmms_highlight_outbox_options_save_object);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_NUMBER, mmi_jmms_highlight_outbox_options_use_number);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS, mmi_jmms_highlight_outbox_options_use_details);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_EMAIL, mmi_jmms_highlight_options_use_details_email);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_USE_DETAILS_NUMBER, mmi_jmms_highlight_options_use_details_number);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_SENT_TO_OTHERS, mmi_jmms_highlight_outbox_options_sent_to_others);
    SetHiliteHandler(MENU_ID_JMMS_OUTBOX_OPTIONS_MOVE_TO_DRAFTS, mmi_jmms_highlight_outbox_options_move_to_drafts);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_outbox
 * DESCRIPTION
 *  Pre entry fn for  outbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_num_msgs = 0;
    JC_RETCODE ret_code = JC_OK;
    U16 curr_scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &total_num_msgs);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }
    /* set the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = E_JMMS_OUTBOX;
    g_jmms_context->msg_open_status[1] = 0;

    if (total_num_msgs == 0)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, JMMS_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }

    g_jmms_context->store_context->num_msg_in_curr_folder = total_num_msgs;
    g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
    g_jmms_context->store_context->current_folder_name = E_JMMS_OUTBOX;

    mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));

    g_jmms_context->store_context->jmms_start_index = 1;

    mmi_jmms_entry_get_msgs_progress_screen();

    ret_code = mmi_jmms_get_folder_msg_list(&(g_jmms_context->store_context->messages_list), MMI_JMMS_OUTBOX, total_num_msgs);

    if (ret_code != JC_OK || g_jmms_context->store_context->messages_list == NULL)
    {
        curr_scr_id = GetActiveScreenId();

        mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));

        if (curr_scr_id == SCR_ID_JMMS_GET_MSGS_PROGRESS_SCREEN)
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
 *  mmi_jmms_entry_outbox_screen
 * DESCRIPTION
 *  Entry fn for outbox screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_outbox_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;   /* Buffer holding history data */
    U8 num_item;        /* Stores no of children in the submenu */
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_OUTBOX, &num_item);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }

    if (g_jmms_context->store_context->update_nmsgs_in_current_folder)
    {
        mmi_jmms_entry_outbox();
        g_jmms_context->curr_scr_hilited_index = 0;
        return;
    }

    EntryNewScreen(SCR_ID_JMMS_OUTBOX, NULL, mmi_jmms_entry_outbox_screen, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_OUTBOX);

    SetParentHandler(MENU_ID_JMMS_OUTBOX);
    RegisterHighlightHandler(mmi_jmms_folder_list_highlight_hdlr);

    /* reset the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = 0;
    g_jmms_context->msg_open_status[1] = 0;

    ShowCategory184Screen(
        STR_ID_JMMS_OUTBOX,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_jmms_context->store_context->num_msg_in_curr_folder,
        mmi_jmms_get_item_data_outbox,
        mmi_jmms_get_item_hint_outbox,
        g_jmms_context->curr_scr_hilited_index,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_entry_outbox_options_scren, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_outbox_options_scren, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_outbox_options_scren, KEY_WAP, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_jmms_back_from_msgs_list_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_from_msgs_list_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_data_outbox
 * DESCRIPTION
 *  fn retrun the item data
 * PARAMETERS
 *  item_index          [IN]        (index of item to be drawn)
 *  str_buff            [IN]        (string of item)
 *  img_buff_p          [IN]         (image corrsponding to item
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_jmms_get_item_data_outbox(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
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

    if (msgs_list_node_p == NULL)
    {
        return FALSE;
    }

    mmi_ucs2cpy((S8*) str_buff, msgs_list_node_p->subject_as_caption_p);

    *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_SENT));

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_hint_outbox
 * DESCRIPTION
 *  Retrun the hint fot the item to be drawn
 * PARAMETERS
 *  item_index          [IN]        (index of item to be drawn)
 *  hint_array_p        [IN]        (hint buufer for the item_index)
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_get_item_hint_outbox(S32 item_index, UI_string_type *hint_array_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 count = 0;
    mmi_jmms_folder_msgs_list_struct *msgs_list_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_POSSIBLE_MESSAGES))
    {
        return FALSE;
    }

    msgs_list_node = g_jmms_context->store_context->messages_list;
    while (count != item_index && msgs_list_node != NULL)
    {
        msgs_list_node = msgs_list_node->next_p;
        count++;
    }

    if (msgs_list_node == NULL || msgs_list_node->address_as_hint_p == NULL)
    {
        return 0;
    }

    if (mmi_ucs2strlen((S8*) (msgs_list_node->address_as_hint_p)))
    {
        memset(hint_array_p[0], 0, MAX_SUB_MENU_HINT_SIZE);
        mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
            (S8*) hint_array_p[0],
            (S8*) msgs_list_node->address_as_hint_p,
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
 *  mmi_jmms_entry_outbox_options_scren
 * DESCRIPTION
 *  Entry fn for outbox options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_outbox_options_scren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;                   /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */

#ifdef __MMI_UNIFIED_MESSAGE__
    U8 curr_page = 0;
    MEDIA_INFO *image_info_p;
    U8 media_count = 0;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_OUTBOX_OPTIONS, NULL, mmi_jmms_entry_outbox_options_scren, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_OUTBOX_OPTIONS);

#ifdef __MMI_UNIFIED_MESSAGE__
    DeleteScreenIfPresent(SCR_ID_JMMS_OUTBOX_OPTIONS);
#endif 
    num_item = GetNumOfChild(MENU_ID_JMMS_OUTBOX_OPTIONS);
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 0, &media_count, E_TRUE);
    mmi_jmms_jdi_get_current_page_index(g_jmms_context->msg_handle, &curr_page);
    image_info_p = mmi_jmms_jdi_get_image_data(curr_page);

    if (g_jmms_context->view_context != NULL)
    {
        if (media_count || g_jmms_context->view_context->view_audio_id || g_jmms_context->view_context->view_video_id
            || image_info_p != NULL)
        {
            mmi_frm_unhide_menu_item(MENU_ID_JMMS_OUTBOX_OPTIONS_SAVE_OBJECTS);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_JMMS_OUTBOX_OPTIONS_SAVE_OBJECTS);
            num_item--;
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_OUTBOX_OPTIONS_SAVE_OBJECTS);
        num_item--;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    GetSequenceStringIds_Ext(MENU_ID_JMMS_OUTBOX_OPTIONS, str_item_list);

    SetParentHandler(MENU_ID_JMMS_OUTBOX_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#ifndef __MMI_UNIFIED_MESSAGE__
    /* set the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = E_JMMS_OUTBOX;
    /* PMT HIMANSHU START 20060425 */
    g_jmms_context->msg_open_status[1] =
        (U32) mmi_jmms_get_message_id(
                MMI_JMMS_OUTBOX,
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
 *  mmi_jmms_highlight_outbox_options_view
 * DESCRIPTION
 *  Highlight hdlr of Outbox option view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_view(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_outbox_view, KEY_EVENT_UP);
    /* MAUI_00018463 Start */
    /* SetKeyHandler(mmi_jmms_outbox_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    /* MAUI_00018463 End */
    SetKeyHandler(mmi_jmms_outbox_view, KEY_WAP, KEY_EVENT_DOWN);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_resend
 * DESCRIPTION
 *  Highlight hdlr of Outbox option resend
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_resend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_resend, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_outbox_resend, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_resend, KEY_WAP, KEY_EVENT_DOWN);
}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_sent_to_others
 * DESCRIPTION
 *  Highlight hdlr of Outbox option sent to others
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_sent_to_others(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_sent_to_others, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_outbox_sent_to_others, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_sent_to_others, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_move_to_drafts
 * DESCRIPTION
 *  Highlight hdlr of Outbox option movr to drafts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_move_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_move_to_drafts, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_move_to_drafts, KEY_WAP, KEY_EVENT_DOWN);
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_delete
 * DESCRIPTION
 *  Highlight hdlr of Outbox option delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_pre_delete, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_pre_delete, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_delete_all
 * DESCRIPTION
 *  Highlight hdlr of Outbox option delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_delete_all, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_delete_all, KEY_WAP, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_use_details
 * DESCRIPTION
 *  Highlight hdlr of Outbox option use details
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_UNIFIED_MESSAGE__
void mmi_jmms_highlight_outbox_options_use_details(void)
#else 
void mmi_jmms_highlight_outbox_options_use_number(void)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_use_details, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_jmms_outbox_use_details, KEY_SEND, KEY_EVENT_UP); */
    SetKeyHandler(mmi_jmms_outbox_use_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_use_details, KEY_WAP, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_properties
 * DESCRIPTION
 *  Highlight hdlr of Outbox option properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_outbox_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_outbox_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_outbox_properties, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA content = {0, };
    U8 msg_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_index = g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index;
    content.bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message("Outbox", &content, (msg_index));

    if (ret_code != JC_OK)
    {
        goto END;
    }
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_deinit_view();
#endif 
    ret_code = mmi_jmms_pre_entry_mms_view(&content);
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        return;
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
 *  mmi_jmms_outbox_resend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_resend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* CONTENT_DATA Content = {0, }; */
    JC_RETCODE ret_code = JC_OK;

#ifndef __MMI_UNIFIED_MESSAGE__
    JC_INT32 index = 0;
#else 
    mmi_jmms_folder_msgs_list_struct *msgs_list_node_p = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
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
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
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
    mmi_jmms_uc_compose_edit_send_request(
        g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index,
        MMI_JMMS_OUTBOX);
    return;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifndef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_deinit_mms_context(g_jmms_context);
    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    index = (JC_INT32) (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);

    ret_code = mmi_jmms_get_message("Outbox", g_jmms_context->parse_content_p, index);

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    g_jmms_context->last_scr_id = GetActiveScreenId();

    mmi_jmms_parsing_progressing_screen();

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&g_jmms_context->msg_handle, g_jmms_context->parse_content_p, E_TYPE_MMS, E_TRUE);

    /*  */
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(
            g_jmms_context->msg_handle,
            mmi_jmms_outbox_resend_parse_async_callback,
            mmi_jmms_only_abort_parsing_progress);
        return;
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    g_jmms_context->last_scr_id = SCR_ID_UM_UNSENT;
#ifndef __MMI_UNIFIED_COMPOSER__
    if (mmi_jmms_pre_check_for_auto_signature() == E_FALSE)
    {
        mmi_jmms_display_auto_signature_error_popup();
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    msgs_list_node_p = g_jmms_context->store_context->messages_list;
    while (msgs_list_node_p != NULL && msgs_list_node_p->msg_index != g_jmms_context->curr_scr_hilited_index)
    {
        msgs_list_node_p = msgs_list_node_p->next_p;
    }
    g_jmms_context->num_attachments = msgs_list_node_p->attachment_status;
    if (g_jmms_context->num_attachments == E_JMMS_ATTACHMENT_NOT_PRESENT)
    {
        g_jmms_context->num_attachments = 0;
    }
    mmi_jmms_jdi_deinitview(g_jmms_context->msg_handle);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_jmms_outbox_resend_parse_async_callback(ret_code);
    return;
    /*  */
#ifndef __MMI_UNIFIED_MESSAGE__
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
    if (ret_code != JC_OK)
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
        }

    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_resend_parse_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_resend_parse_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_SEND *send_p;

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
#ifndef __MMI_UNIFIED_COMPOSER__
    if (mmi_jmms_pre_check_for_auto_signature() == E_FALSE)
    {
        mmi_jmms_display_auto_signature_error_popup();
        DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);
        goto END;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
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

    ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        ret_code = JC_ERR_STORE_FILE_CORRUPTED;
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    send_p = (MESSAGE_SEND*) (msg_headers_p->pHeaders);

    g_jmms_context->version = (S8*) (send_p->pVersion);

    g_jmms_context->progress_screen_title = STR_ID_PROGRESS_SENDING;

#ifdef __MMI_UNIFIED_MESSAGE__
    g_jmms_context->save_mms = MMI_FALSE;
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    //sandeep to Fix PMTSW00006445
    //    g_jmms_context->save_mms = MMI_TRUE;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    memset(g_jmms_context->g_jmms_progress_str, 0x00, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);
    mmi_jmms_entry_communication_progress_screen();

 /******************************************************************************
 This part of the function is modified to make the MMS send process asynch.

 Modified By          : Raj Kumar Gupta
 Date of Modification : 09 June 2006
 *****************************************************************************/

    /* Register the function that to be execute after the completion of the 
       encapsulation */
    mmi_jmms_add_send_callback_node(mmi_jmms_outbox_resend_send_async_callback);

    ret_code = mmi_jmms_send_mms(g_jmms_context->msg_handle, E_TYPE_NEW_MMS, E_TRUE, 1, E_TRUE
#ifdef __MMI_UNIFIED_COMPOSER__
                                 , mmi_jmms_handle_screen_flow_callback
#endif 
        );

    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);

    return;

  END:
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
    if (ret_code != JC_OK)
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
        }

    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_resend_send_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_resend_send_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JC_OK != ret_code)
    {
        if (ret_code == E_JMMS_STORAGE_FULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_STORE_FUL);
            /* Dilip Start 7th Sept 2006 */
        #ifdef __MMI_UNIFIED_MESSAGE__

            if (IsScreenPresent(SCR_ID_UM_UNSENT))
            {
                DeleteUptoScrID(SCR_ID_UM_UNSENT);
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            /* Dilip End 7th Sept 2006 */
        }
        /* Added by - Raj Kumar Gupta on 31 August, 2006 */
        else if (ret_code == E_COMMUNICATION_ABORTED)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_COMM_ABORTED),
                IMG_GLOBAL_INFO,
                1,
                JMMS_POPUP_TIME,
                (U8) SUCCESS_TONE);
            /* Dilip Start 4th Sept 2006 */
        #ifdef __MMI_UNIFIED_MESSAGE__

            if (IsScreenPresent(SCR_ID_UM_UNSENT))
            {
                DeleteUptoScrID(SCR_ID_UM_UNSENT);
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            /* Dilip End 4th Sept 2006 */
        }
        else
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        }

        mmi_jmms_deinit_mms_context(g_jmms_context);
        /* /DeleteUptoScrID(g_jmms_context->last_scr_id)        ; */
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);
    }

    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
        }
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }
}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_sent_to_others
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_sent_to_others(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* CONTENT_DATA Content = {0, }; */
    JC_RETCODE ret_code = JC_OK;
    JC_INT32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_deinit_mms_context(g_jmms_context);

    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    index = (JC_INT32) (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);

    ret_code = mmi_jmms_get_message("Outbox", g_jmms_context->parse_content_p, index);

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    mmi_jmms_parsing_progressing_screen();

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&g_jmms_context->msg_handle, g_jmms_context->parse_content_p, E_TYPE_MMS, E_TRUE);

    /*  */
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(
            g_jmms_context->msg_handle,
            mmi_jmms_outbox_sent_to_others_async_callback,
            mmi_jmms_only_abort_parsing_progress);
        return;
    }
    mmi_jmms_outbox_sent_to_others_async_callback(ret_code);
    return;
    /*  */
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

    if (ret_code != JC_OK)
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
        }

    }

    g_jmms_context->is_add_media_warning = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_sent_to_others_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_sent_to_others_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_SEND *send_p;
    S32 len = 0;
    JC_RETCODE ret_code_restricted = JC_OK;

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

    /* g_jmms_context->g_use_local_send_setings = 0; */
    /* MAUI_00227929 Start */
    g_jmms_context->g_use_local_send_setings = 1;
    mmi_jmms_fill_mms_sending_settings();
    /* MAUI_00227929 End */

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

    if (ret_code != JC_OK)
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
        }

    }

    g_jmms_context->is_add_media_warning = 0;
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_move_to_drafts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_move_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_UINT32 index = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = (JC_INT32) (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);

    ret_code = mmi_jmms_store_move_message("Outbox", "Drafts", &index);
    if (ret_code == JC_OK)
    {

        HistoryReplace(SCR_ID_JMMS_OUTBOX, SCR_ID_JMMS_OUTBOX, mmi_jmms_entry_outbox);

        if (g_jmms_context->store_context->num_msg_in_curr_folder <= 1) /* /now folder will empty */
        {
            GoBackToHistory(SCR_ID_JMMS_MAIN_MENU);
        }
        else
        {
            GoBackToHistory(SCR_ID_JMMS_OUTBOX);
        }

    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_MOVE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_OUTBOX);

    }

}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_pre_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_pre_delete(void)
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

    SetLeftSoftkeyFunction(mmi_jmms_outbox_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_post_outbox_delete_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_post_outbox_delete_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_jmms_pre_entry_outbox();
#else 
    GoBackHistory();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = g_jmms_context->store_context->num_msg_in_curr_folder;

    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_OUTBOX, IMG_GLOBAL_DELETED);

    ret_code = mmi_jmms_delete_message(MMI_JMMS_OUTBOX, (number - g_jmms_context->curr_scr_hilited_index));

    if (ret_code == JC_OK)
    {
        DisplayPopupCallBack(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            JMMS_POPUP_TIME,
            SUCCESS_TONE,
            mmi_jmms_post_outbox_delete_message);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_MAIN);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        if (g_jmms_context->store_context->num_msg_in_curr_folder - 1)
        {
            HistoryReplace(SCR_ID_JMMS_OUTBOX, SCR_ID_JMMS_OUTBOX, mmi_jmms_entry_outbox);
            DeleteUptoScrID(SCR_ID_JMMS_OUTBOX);
        }
        else
        {
            DeleteUptoScrID(SCR_ID_JMMS_MAIN_MENU);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_UNSENT);
    #else 
        DeleteUptoScrID(SCR_ID_JMMS_OUTBOX);
    #endif 

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_delete_on_sent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_delete_on_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*********************************************************************************
      These lines has been added to delete the MMS stored into the OUTBOX folder after
      It has been sent successfully. Since file handle is open so it is not able to 
      delete the MMS from the 'OUTBOX' folder. So before performing the MMS delete, 
      close all the file handles by deinitializing the message handle.

      Written By  : Raj Kumar Gupta
      Date        : Augest 22, 2006
     *********************************************************************************/

    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        g_jmms_context->msg_handle = NULL;
    }
    /*********************************************************************************/

    number = g_jmms_context->store_context->num_msg_in_curr_folder;

    ret_code = mmi_jmms_delete_message(MMI_JMMS_OUTBOX, (number - g_jmms_context->curr_scr_hilited_index));

    if (ret_code == JC_OK)
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_UNSENT, SCR_ID_UM_UNSENT, mmi_um_jmms_pre_entry_outbox);
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_UNSENT);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        HistoryReplace(SCR_ID_JMMS_OUTBOX, SCR_ID_JMMS_OUTBOX, mmi_jmms_entry_outbox);

        if (number <= 1)    /* /now folder will empty */
        {
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_MAIN_MENU);
        }
        else
        {
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_OUTBOX);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
    else
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_UNSENT);
    #else 
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_OUTBOX);
    #endif 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_delete_all(void)
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
        get_string(STR_ID_JMMS_DELETE_ALL_UM_OUTBOX),
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
        /* MAUI_00018477 Start */ get_string(STR_ID_JMMS_DELETE_ALL_UM_OUTBOX),
        /* MAUI_00018477 End */ IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    /* Dilip 29 Aug 2006 */
    SetLeftSoftkeyFunction(mmi_jmms_delete_all_message_outbox, KEY_EVENT_UP);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_message_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_all_message_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_OUTBOX, IMG_GLOBAL_PROGRESS);

    ret_code = mmi_jmms_delete_all_message(MMI_JMMS_OUTBOX);
    if (JC_OK != ret_code)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_OUTBOX);
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_MAIN_MENU);
        mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_use_details
 * DESCRIPTION
 *  Pre entry fn for outbox use details option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_pre_entry_use_details_screen(MMI_JMMS_OUTBOX);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_outbox_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_outbox_properties(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_type = mmi_jmms_get_msg_type(g_jmms_context->curr_scr_hilited_index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_show_mms_properties(msg_type, MMI_JMMS_OUTBOX);
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
    mmi_jmms_show_mms_properties(node_p->msg_type, MMI_JMMS_OUTBOX);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_edit_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_edit_message(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_outbox_edit_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_outbox_edit_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_outbox_edit_message, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_outbox_edit_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_outbox_edit_message(void)
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
    g_jmms_context->g_use_local_send_setings = 1;   /* sanjeev    5/1/07 */
    mmi_jmms_edit_message(MMI_JMMS_OUTBOX);
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_jmms_context->edit_error_code != JC_OK && curr_page > 1 && g_jmms_context->msg_handle)
    {
        gui_lock_double_buffer();
        mmi_jmms_jdi_view_event(g_jmms_context->msg_handle, E_VIEW_SET_ACTIVE_SLIDE, &curr_page);
        gui_unlock_double_buffer();
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_outbox_options_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_outbox_options_save_object(void)
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

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

#endif /* _MMI_JMMSOUTBOXSECMMI_C */ 


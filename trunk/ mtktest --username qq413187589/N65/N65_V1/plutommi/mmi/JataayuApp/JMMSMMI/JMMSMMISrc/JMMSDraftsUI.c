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
 *  JMMSDraftsUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contain the ui of dratfs folder in mms
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_JMMSDRAFTSSECMMI_C
#define _MMI_JMMSDRAFTSSECMMI_C

/***************************************************************************** 
* Include
*****************************************************************************/
// #if 0 //Pranav Commeneted
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "JMMSStoreHandling.h"
#include "MainMenuDef.h"
#include "JMMSStoreHandling.h"
#include "JMMSConfig.h"
#include "JMMSMainMMS.h"
#include "JMMSUseDetails.h"
#include "JMMSDrafts.h"

#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
// #include "transport.h"
#include "JMMSWriteMMS.h"
// #include <jdi_miscutils.h>
#include <jdi_communicator.h>

#include <MessagingDatatypes.h>
#include <MessagingAPI.h>

#include "JMMSExdcl.h"
#include "JMMSPushHandling.h"

#include "JMMSCompose.h"

#include <PrvMessagingDataTypes.h>
#include <MM1DataTypes.h>
#include <ComposeUtils.h>
#include "JMMSCoreAPI.h"
#include "JMMSResDef.h"
#include "JMMSMainMMS.h"
#include "JMMSProtocols.h"
#include "JMMSView.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSTemplates.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageProt.h"
#include "JMMSUMHandling.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
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
U16 DeleteScreenFromToNnodes(U16 ScrId, U16 num_nodes);
U8 DeleteFromScrUptoScr(U16 beyondScrnid, U16 tillScrnid);

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts
 * DESCRIPTION
 *  This function is highlight handler of Drafts menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_drafts, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_drafts, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_drafts, KEY_WAP, KEY_EVENT_DOWN);

}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_init
 * DESCRIPTION
 *  This function init the hilight handlers of drafts menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Drafts options Highlight handlers */
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_VIEW, mmi_jmms_highlight_drafts_options_view);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_SENT, mmi_jmms_highlight_drafts_options_sent);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_EDIT_MESSAGE, mmi_jmms_highlight_drafts_options_edit_message);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_DELETE, mmi_jmms_highlight_drafts_options_delete);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_DELETE_ALL, mmi_jmms_highlight_drafts_options_delete_all);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_PROPERTIES, mmi_jmms_highlight_drafts_options_properties);
    /* Drafts use details highlight handlers */
    SetHiliteHandler(
        MENU_ID_JMMS_DRAFTS_USE_DETAILS_ADDRESSES_ADD_TO_CONTACT,
        mmi_jmms_highlight_options_use_details_add_to_contact);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_USE_DETAILS_ADDRESSES_CALL, mmi_jmms_highlight_options_use_details_call);
#ifdef __MMI_UNIFIED_MESSAGE__
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_NUMBER, mmi_jmms_highlight_draft_options_use_number);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_SAVE_OBJECTS, mmi_jmms_highlight_draft_options_save_object);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS, mmi_jmms_highlight_drafts_options_use_details);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_NUMBER, mmi_jmms_highlight_options_use_details_number);
    SetHiliteHandler(MENU_ID_JMMS_DRAFTS_OPTIONS_USE_DETAILS_EMAIL, mmi_jmms_highlight_options_use_details_email);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#ifndef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_drafts
 * DESCRIPTION
 *  pre entry fn for dratfs screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_drafts(void)
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
    ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &total_num_msgs);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }

    /* set the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = E_JMMS_DRAFTS;
    g_jmms_context->msg_open_status[1] = 0;

    if (total_num_msgs == 0)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, JMMS_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }

    g_jmms_context->store_context->num_msg_in_curr_folder = total_num_msgs;
    g_jmms_context->store_context->update_nmsgs_in_current_folder = 0;
    g_jmms_context->store_context->current_folder_name = E_JMMS_DRAFTS;

    mmi_jmms_free_msgs_list(&(g_jmms_context->store_context->messages_list));

    g_jmms_context->store_context->jmms_start_index = 1;

    mmi_jmms_entry_get_msgs_progress_screen();

    ret_code = mmi_jmms_get_folder_msg_list(&(g_jmms_context->store_context->messages_list), MMI_JMMS_DRAFTS, total_num_msgs);

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
 *  mmi_jmms_entry_drafts_screen
 * DESCRIPTION
 *  Entry fn for drafts screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_drafts_screen(void)
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
    ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_DRAFTS, &num_item);
    if (ret_code != JC_OK)
    {
        ASSERT(0);
    }

    //if number of msga in fodelr is not same to as in global var then
    //it means some has been recieved as user was in inbox so need to update
    ///the msgs list
    if (g_jmms_context->store_context->update_nmsgs_in_current_folder)
    {
        mmi_jmms_entry_drafts();
        g_jmms_context->curr_scr_hilited_index = 0;
        return;
    }

    EntryNewScreen(SCR_ID_JMMS_DRAFTS, NULL, mmi_jmms_entry_drafts_screen, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_DRAFTS);

    SetParentHandler(MENU_ID_JMMS_DRAFTS);
    RegisterHighlightHandler(mmi_jmms_folder_list_highlight_hdlr);

    /* reset the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = 0;
    g_jmms_context->msg_open_status[1] = 0;

    ShowCategory184Screen(
        STR_ID_JMMS_DRAFTS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_jmms_context->store_context->num_msg_in_curr_folder,
        mmi_jmms_get_item_data_drafts,
        mmi_jmms_get_item_hint_drafts,
        g_jmms_context->curr_scr_hilited_index,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_entry_drafts_options_scren, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_drafts_options_scren, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_drafts_options_scren, KEY_WAP, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_jmms_back_from_msgs_list_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_from_msgs_list_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_data_drafts
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
pBOOL mmi_jmms_get_item_data_drafts(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
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

    /* /TODO:: may need to change the icon */
    *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_SENT_MMS));

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_hint_drafts
 * DESCRIPTION
 *  Retrun the hint fot the item to be drawn
 * PARAMETERS
 *  item_index          [IN]        (index of item to be drawn)
 *  hint_array_p        [IN]        (hint buufer for the item_index)
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_get_item_hint_drafts(S32 item_index, UI_string_type *hint_array_p)
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
            (S8*) msgs_list_node_p->address_as_hint_p,
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
 *  mmi_jmms_entry_drafts_options_scren
 * DESCRIPTION
 *  Entry fn for drafts options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_drafts_options_scren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;                   /* Buffer holding history data */
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 menuid;
    MMI_BOOL contains_add = MMI_TRUE;

#ifdef __MMI_UNIFIED_MESSAGE__
    U8 curr_page = 0;
    MEDIA_INFO *image_info_p;
    U8 media_count = 0;
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    S32 count = 0;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_jmms_folder_msgs_list_struct *msgs_list_node_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* /check whether selected msg has some adress */
    msgs_list_node_p = g_jmms_context->store_context->messages_list;
#ifdef __MMI_UNIFIED_MESSAGE__
    while (msgs_list_node_p != NULL && msgs_list_node_p->msg_index != g_jmms_context->curr_scr_hilited_index)
    {
        msgs_list_node_p = msgs_list_node_p->next_p;
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    while (count != g_jmms_context->curr_scr_hilited_index && msgs_list_node_p != NULL)
    {
        msgs_list_node_p = msgs_list_node_p->next_p;
        count++;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    /* /if hint is NULL then it means no address is present */
#ifdef __MMI_UNIFIED_MESSAGE__
    if (msgs_list_node_p->um_msg_info_p->address == NULL)
#else 
    if (msgs_list_node_p->address_as_hint_p == NULL)
#endif 
    {
        contains_add = MMI_FALSE;
    }
#ifndef __MMI_UNIFIED_MESSAGE__
    if (contains_add == MMI_TRUE)
    {
        menuid = MENU_ID_JMMS_DRAFTS_OPTIONS1;
    }
    else if (contains_add == MMI_FALSE)
    {
        menuid = MENU_ID_JMMS_DRAFTS_OPTIONS2;
    }
    else
    {
        return;
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    menuid = MENU_ID_JMMS_DRAFTS_OPTIONS1;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    EntryNewScreen(SCR_ID_JMMS_DRAFTS_OPTIONS, NULL, mmi_jmms_entry_drafts_options_scren, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_DRAFTS_OPTIONS);
#ifdef __MMI_UNIFIED_MESSAGE__
    DeleteScreenIfPresent(SCR_ID_JMMS_DRAFTS_OPTIONS);
#endif 
    num_item = GetNumOfChild(menuid);
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
            mmi_frm_unhide_menu_item(MENU_ID_JMMS_DRAFTS_OPTIONS_SAVE_OBJECTS);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_JMMS_DRAFTS_OPTIONS_SAVE_OBJECTS);
            num_item--;
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_DRAFTS_OPTIONS_SAVE_OBJECTS);
        num_item--;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    GetSequenceStringIds_Ext(menuid, str_item_list);

    SetParentHandler(menuid);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#ifndef __MMI_UNIFIED_MESSAGE__
    /* set the open msg status- for At delete */
    g_jmms_context->msg_open_status[0] = E_JMMS_DRAFTS;
    //PMT HIMANSHU START 20060425
    //      g_jmms_context->msg_open_status[1]=(U16)(g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);
    g_jmms_context->msg_open_status[1] =
        (U32) mmi_jmms_get_message_id(
                MMI_JMMS_DRAFTS,
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
 *  mmi_jmms_highlight_drafts_options_view
 * DESCRIPTION
 *  highlight hdlr of view menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts_options_view(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_drafts_view, KEY_EVENT_UP);
    /* MAUI_00018463 Start */
    /* SetKeyHandler(mmi_jmms_drafts_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    /* MAUI_00018463 End */
    SetKeyHandler(mmi_jmms_drafts_view, KEY_WAP, KEY_EVENT_DOWN);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts_options_sent
 * DESCRIPTION
 *  highlight hdlr of drafts menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts_options_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_drafts_sent, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_drafts_sent, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_drafts_sent, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts_options_edit_message
 * DESCRIPTION
 *  highlight hdlr of edit message menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts_options_edit_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#ifdef __MMI_UNIFIED_MESSAGE__
    SetLeftSoftkeyFunction(mmi_jmms_pre_drafts_edit_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_drafts_edit_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_drafts_edit_message, KEY_WAP, KEY_EVENT_DOWN);

#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetLeftSoftkeyFunction(mmi_jmms_drafts_edit_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_drafts_edit_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_drafts_edit_message, KEY_WAP, KEY_EVENT_DOWN);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts_options_delete
 * DESCRIPTION
 *  highlight hdlr of delete menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts_options_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_drafts_pre_delete, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_drafts_pre_delete, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts_options_delete_all
 * DESCRIPTION
 *  highlight hdlr of delete all menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts_options_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_drafts_delete_all, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_drafts_delete_all, KEY_WAP, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts_options_use_details
 * DESCRIPTION
 *  highlight hdlr of use details menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_UNIFIED_MESSAGE__
void mmi_jmms_highlight_drafts_options_use_details(void)
#else 
void mmi_jmms_highlight_draft_options_use_number(void)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_drafts_use_details, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_jmms_drafts_use_details, KEY_SEND, KEY_EVENT_UP); */
    SetKeyHandler(mmi_jmms_drafts_use_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_drafts_use_details, KEY_WAP, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_drafts_options_properties
 * DESCRIPTION
 *  highlight hdlr of properties menu item in Drafts options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_drafts_options_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_drafts_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_drafts_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_drafts_properties, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_view(void)
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
    ret_code = mmi_jmms_get_message("Drafts", &content, (msg_index));

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
 *  mmi_jmms_drafts_sent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* CONTENT_DATA Content = {0, }; */
    JC_RETCODE ret_code = JC_OK;

#if !defined(__MMI_UNIFIED_MESSAGE__)
    JC_INT32 index = 0;
#endif 
#if defined(__MMI_UNIFIED_MESSAGE__) && !defined (__MMI_UNIFIED_COMPOSER__)
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
    if (mmi_jmms_is_corrupted_video_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        return;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __MMI_UNIFIED_COMPOSER__
#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_FALSE) == E_TRUE)
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
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
        MMI_JMMS_DRAFTS);
    return;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifndef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_deinit_mms_context(g_jmms_context);

    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifndef __MMI_UNIFIED_COMPOSER__
#ifdef __MMI_UNIFIED_MESSAGE__
    if (mmi_jmms_pre_check_for_auto_signature() == E_FALSE)
    {
        mmi_jmms_display_auto_signature_error_popup();
        return;
    }
    msgs_list_node_p = g_jmms_context->store_context->messages_list;
    while (msgs_list_node_p != NULL && msgs_list_node_p->msg_index != g_jmms_context->curr_scr_hilited_index)
    {
        msgs_list_node_p = msgs_list_node_p->next_p;
    }
    /* Dilip Start August 24, 2006 */
    /* This part of the function is modified to remove unwanted slide if no address is present in drafts */
    g_jmms_context->num_attachments = msgs_list_node_p->attachment_status;
    if (g_jmms_context->num_attachments == E_JMMS_ATTACHMENT_NOT_PRESENT)
    {
        g_jmms_context->num_attachments = 0;
    }

    if (msgs_list_node_p->um_msg_info_p->address_length == 0)
    {
        /* If slides are greater then max limit and adress is null */
        ret_code = mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, (U8) mmi_jmms_compose_settings_max_no_pages());
        if (ret_code != JC_OK)
        {
            mmi_jmms_error_handler(ret_code);
            return;
        }
    }
    if (IsScreenPresent(SCR_ID_UM_DRAFT))
    {
        DeleteUptoScrID(SCR_ID_UM_DRAFT);
    }
    /* Dilip End August 24, 2006 */
    /* /if hint is NULL then it means no address is present */

    if (msgs_list_node_p->um_msg_info_p->address_length == 0)
    {
        DisplayPopupCallBack((U8*) GetString(STR_ID_JMMS_LACK_RECIPENTS), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE, mmi_jmms_pre_drafts_edit_message_add_recipients);     /* To bring screen to edit page. Dilip Start August 24, 2006 */
        return;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifndef __MMI_UNIFIED_MESSAGE__
    index = (JC_INT32) (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);

    ret_code = mmi_jmms_get_message("Drafts", g_jmms_context->parse_content_p, index);

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    g_jmms_context->last_scr_id = GetActiveScreenId();

#ifndef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_parsing_progressing_screen();

    ret_code = mmi_jmms_jdi_parse_msg_buffer(
                &(g_jmms_context->msg_handle),
                g_jmms_context->parse_content_p,
                E_TYPE_MMS,
                E_TRUE);

    /*  */
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(
            g_jmms_context->msg_handle,
            mmi_jmms_drafts_sent_callback,
            mmi_jmms_only_abort_parsing_progress);
        return;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__  /* sachin Parsing */
    /* mmi_jmms_jdi_deinitview(g_jmms_context->msg_handle); */
#endif 
    mmi_jmms_drafts_sent_callback(ret_code);
    return;

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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_sent_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_sent_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_count = 0;
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
    if (mmi_jmms_pre_check_for_auto_signature() == E_FALSE)
    {
        mmi_jmms_display_auto_signature_error_popup();
        DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);
        goto END;
    }

    ///Todo:  check tehse APIs should not be rquired because
    ///MMS in Drafts folder will be from write MMS and this information
    ///should already be there in MMS
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

#ifdef __MMI_UNIFIED_MESSAGE__
    g_jmms_context->save_mms = MMI_FALSE;
#else 
    g_jmms_context->save_mms = MMI_TRUE;
#endif 
    /* mmi_jmms_entry_communication_progress_screen(); */
 /******************************************************************************
    This part of the function is modified to add the blank slide into the MMS.

   Modified By          : Raj Kumar Gupta
   Date of Modification : July 25, 2006
 *****************************************************************************/
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    if (page_count == 0 && mmi_jmms_compose_settings_auto_sign_status() == E_OFF)
    {
        MMI_BOOL context_to_free = MMI_FALSE;
        JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

        if (g_jmms_context->compose_context == NULL)
        {
            g_jmms_context->compose_context =
                (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
            if (g_jmms_context->compose_context == NULL)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                return;
            }
            memset(
                g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                0,
                (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH);
        }
        DisplayPopupCallBack(
            (U8*) GetString(STR_ID_JMMS_ADD_BLANK_SLIDE),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            (U8) WARNING_TONE,
            mmi_jmms_add_blank_slide_popup_callback);
        g_jmms_context->compose_context->curr_page_index = 0;
        g_jmms_context->compose_context->mms_bg_color = g_jmms_color_RGB_list[COLOR_WHITE];
        err_code = mmi_jmms_set_bg_color(g_jmms_context->compose_context->mms_bg_color);
        if (JMMS_COMP_OK == err_code)
        {
        #ifdef MMI_ON_HARDWARE_P
            stFontAttribute text_font;

            text_font.italic = 0;
            text_font.bold = 0;
            text_font.size = MEDIUM_FONT;
        #endif /* MMI_ON_HARDWARE_P */ 
            mmi_jmms_compose_insert_slide();
        #ifdef MMI_ON_HARDWARE_P
            if (is_test_sim() == MMI_FALSE)
            {
                U32 mms_size = 0;

                mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
                mmi_ucs2cpy(
                    (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) GetString(STR_ID_JMMS_BLANK_SLIDE_STRING));
                if (!
                    (mms_size +
                     jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.
                               edit_content_buffer) * sizeof(JC_CHAR) >
                     MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE &&
                     mmi_jmms_compose_settings_creation_mode() == E_CREAT_MODE_RESTRICTED))
                {
                    g_jmms_context->disable_warning_popup = 1;
                    mmi_jmms_compose_add_text(
                        (U8) (page_count + 1),
                        &(text_font),
                        g_jmms_color_RGB_list[COLOR_BLACK],
                        1);
                    g_jmms_context->disable_warning_popup = 0;
                }
            }
        #endif /* MMI_ON_HARDWARE_P */ 
        }
        if (context_to_free == MMI_TRUE)
        {
            context_to_free = MMI_FALSE;
            if (g_jmms_context->compose_context != NULL)
            {
                jdd_MemFree(g_jmms_context->compose_context);
                g_jmms_context->compose_context = NULL;
            }
        }
        return;
    }
    else
    {
        g_jmms_context->progress_screen_title = STR_ID_PROGRESS_SENDING;
        memset(g_jmms_context->g_jmms_progress_str, 0x00, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);
        mmi_jmms_entry_communication_progress_screen();
        /* PMT VIKAS START 20060325 */
        // #ifdef __MMI_MMS_SIGNATURE__
        mmi_jmms_insert_auto_signature();
        // #endif
    }
/*****************************************************************************
   End of modification to insert the blank slide into blank MMS.
 *****************************************************************************/
 /******************************************************************************
   This part of the function is modified to make the MMS send process asynch.

   Modified By          : Raj Kumar Gupta
   Date of Modification : 09 June 2006
 *****************************************************************************/
    /* Register the function that to be execute after the completion of the 
       encapsulation */
    mmi_jmms_add_send_callback_node(mmi_jmms_send_drafts_sent_callback);
    mmi_jmms_send_mms(g_jmms_context->msg_handle, E_TYPE_NEW_MMS, E_TRUE, 1, E_TRUE
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
 *  mmi_jmms_add_blank_slide_popup_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_add_blank_slide_popup_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->progress_screen_title = STR_ID_PROGRESS_SENDING;
    memset(g_jmms_context->g_jmms_progress_str, 0x00, MAX_PROGRESS_SCREEN_HINT_LEN * ENCODING_LENGTH);
    mmi_jmms_entry_communication_progress_screen();
    /* PMT VIKAS START 20060325 */
    // #ifdef __MMI_MMS_SIGNATURE__
    mmi_jmms_insert_auto_signature();
    // #endif
    mmi_jmms_add_send_callback_node(mmi_jmms_send_drafts_sent_callback);
    mmi_jmms_send_mms(g_jmms_context->msg_handle, E_TYPE_NEW_MMS, E_TRUE, 1, E_TRUE
#ifdef __MMI_UNIFIED_COMPOSER__
                      , mmi_jmms_handle_screen_flow_callback
#endif 
        );
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_send_drafts_sent_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_send_drafts_sent_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JC_OK != ret_code)
    {
        /* PMT VIKAS START 20060405 */
        // #ifdef __MMI_MMS_SIGNATURE__
        mmi_jmms_del_inserted_auto_signature_slide();
        //    #endif 
        //PMT VIKAS END 20060405        
        ////DisplayPopup((U8*)GetString(STR_ID_JMMS_ERROR_MMS_SENT) ,IMG_GLOBAL_ERROR, 1,1000,(U8)ERROR_TONE);
        if (ret_code == E_JMMS_STORAGE_FULL)
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT_STORE_FUL);
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
        }
        else
        {
            mmi_jmms_handle_pop_up_for_interupt(STR_ID_JMMS_ERROR_MMS_SENT);
        }
    #ifdef __MMI_UNIFIED_MESSAGE__  /* Fixed by Vikram to avoid going to Options screen in case of any error */

        if (IsScreenPresent(SCR_ID_UM_DRAFT))
        {
            DeleteUptoScrID(SCR_ID_UM_DRAFT);
        }

    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, g_jmms_context->last_scr_id);

    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        mmi_jmms_deinit_mms_context(g_jmms_context);
    }

#ifndef __MMI_UNIFIED_MESSAGE__

    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
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
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_drafts_edit_message_add_recipients
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_drafts_edit_message_add_recipients(void)
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
    g_jmms_context->g_use_local_send_setings = 1;   /* sanjeev  5/1/07 */
    mmi_jmms_edit_message(MMI_JMMS_DRAFTS);
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
 *  mmi_jmms_pre_drafts_edit_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_drafts_edit_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 curr_page = 0;

    if (g_jmms_context->msg_handle)
    {
        mmi_jmms_jdi_get_current_page_index(g_jmms_context->msg_handle, &curr_page);
    }
    g_jmms_context->edit_error_code = JC_OK;
    g_jmms_context->g_use_local_send_setings = 1;   /* sanjeev  5/1/07 */
    mmi_jmms_edit_message(MMI_JMMS_DRAFTS);
    if (g_jmms_context->edit_error_code != JC_OK && curr_page > 1 && g_jmms_context->msg_handle)
    {
        gui_lock_double_buffer();
        mmi_jmms_jdi_view_event(g_jmms_context->msg_handle, E_VIEW_SET_ACTIVE_SLIDE, &curr_page);
        gui_unlock_double_buffer();
    }
}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_edit_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_UNIFIED_MESSAGE__
void mmi_jmms_drafts_edit_message(void)
#else 
void mmi_jmms_edit_message(S8 *folder_name_p)
#endif 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* CONTENT_DATA Content = {0, }; */
    JC_RETCODE ret_code = JC_OK;

#ifndef __MMI_UNIFIED_MESSAGE__
    JC_INT32 index = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_deinit_mms_context(g_jmms_context);

    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA *) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    index = (JC_INT32) (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);

    ret_code = mmi_jmms_get_message("Drafts", g_jmms_context->parse_content_p, index);
    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        goto END;
    }

    mmi_jmms_parsing_progressing_screen();
    ret_code =
        mmi_jmms_jdi_parse_msg_buffer(&(g_jmms_context->msg_handle), g_jmms_context->parse_content_p, E_TYPE_MMS,
                                      E_TRUE);

    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(g_jmms_context->msg_handle, mmi_jmms_drafts_edit_message_async_callback,
                                            mmi_jmms_only_abort_parsing_progress);
        return;
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (mmi_jmms_is_corrupted_video_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        ret_code = -1;
        return;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __MMI_UNIFIED_COMPOSER__
#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
    ret_code = mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, (U8) mmi_jmms_compose_settings_max_no_pages());
    if (ret_code != JC_OK)
    {
        ret_code = JC_ERR_MSG_MORE_THAN_MAX_PAGE;
        mmi_jmms_error_handler(ret_code);
        return;
    }
    {
        ECreationMode create_mode;

        create_mode = mmi_jmms_compose_settings_creation_mode();
        if (create_mode == E_CREATION_MODE_RESTRICTED &&
            IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
        {
            mmi_jmms_uc_edit_content_restricted_mode_query();
        }
        else
        {
            mmi_jmms_uc_compose_edit_request(g_jmms_context->store_context->num_msg_in_curr_folder -
                                             g_jmms_context->curr_scr_hilited_index, folder_name_p);
        }
    }
#else /* __MMI_UNIFIED_COMPOSER__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_jdi_preedit(&g_jmms_context->msg_handle);  /* Edit */
#endif 
    mmi_jmms_drafts_edit_message_async_callback(ret_code);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    return;

#ifndef __MMI_UNIFIED_MESSAGE__
  END:
    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
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
    g_jmms_context->is_add_media_warning = 0;

}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_edit_message_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_edit_message_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MESSAGE_SEND *send_p = NULL;

#ifdef __MMI_UNIFIED_MESSAGE__
    ECreationMode create_mode;
    MESSAGE_RETRIEVAL *reterive_p = NULL;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    S32 len = 0;
    S8 *temp_str_p = NULL;
    S8 *str_p = NULL;
    S32 start_index = 0;
    MMI_BOOL is_email = MMI_FALSE;
    S32 len_to_copy = 0;
    U8 ret = 0;
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

    ret_code =
        mmi_jmms_jdi_msg_register_callback(g_jmms_context->msg_handle, E_CB_ERROR_IND, (void *)mmi_jmms_error_ind_cb);



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



#ifndef __MMI_UNIFIED_MESSAGE__
    if (mmi_jmms_is_corrupted_video_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        ret_code = -1;
        goto END;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __MMI_UNIFIED_MESSAGE__
    create_mode = mmi_jmms_compose_settings_creation_mode();



    if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
    {
        if (create_mode == E_CREATION_MODE_RESTRICTED)
        {
            ret_code_restricted = JC_ERR_MSG_MMS_CONTENT_RESTRICTED;
        }
        else if (create_mode == E_CREATION_MODE_WARNING)
        {
            g_jmms_context->is_add_media_warning = 1;
        }
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 



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

#ifdef __MMI_UNIFIED_MESSAGE__
    if (msg_headers_p->eMsgType == E_MSG_TYPE_SEND)
    {
        send_p = (MESSAGE_SEND*) (msg_headers_p->pHeaders);
    }
    else if (msg_headers_p->eMsgType == E_MSG_TYPE_RECEIVE)
    {
        reterive_p = (MESSAGE_RETRIEVAL*) (msg_headers_p->pHeaders);
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (msg_headers_p->eMsgType != E_MSG_TYPE_SEND)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        goto END;
    }
    send_p = (MESSAGE_SEND *) (msg_headers_p->pHeaders);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    mmi_jmms_free_addresses_list();

    /* /Make the To Addresses list */



    if (send_p != NULL)
    {
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

                ret = mmi_jmms_add_address_in_addresse_list((S8*) temp_str_p);
                if (ret != 0)
                {
                    goto END;
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
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    /* /Make the To Addresses list */



    if (reterive_p != NULL)
    {
        if (reterive_p->pTo != NULL)
        {
            str_p = (S8*) (reterive_p->pTo);
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
                mmi_ucs2ncpy((S8*) temp_str_p, (S8*) (reterive_p->pTo + start_index), len_to_copy);

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
        if (reterive_p->pCc != NULL)
        {
            str_p = (S8*) (reterive_p->pCc);
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
                mmi_ucs2ncpy((S8*) temp_str_p, (S8*) (reterive_p->pCc + start_index), len_to_copy);

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

        /* /Make the subject buffer */
        memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
        if (reterive_p->pSubject != NULL)
        {
            len = (mmi_ucs2strlen((S8*) (reterive_p->pSubject))) * ENCODING_LENGTH;
            if (len > (MAX_SUBJECT_LENGTH * ENCODING_LENGTH))
            {
                memcpy(
                    g_jmms_context->subject_input_buffer,
                    reterive_p->pSubject,
                    (MAX_SUBJECT_LENGTH * ENCODING_LENGTH));
            }
            else
            {
                memcpy(g_jmms_context->subject_input_buffer, reterive_p->pSubject, len);
            }
        }
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;
    /* MAUI_00227929 Start */
    mmi_jmms_fill_mms_sending_settings();
    /* MAUI_00227929 End */
    /* g_jmms_context->g_use_local_send_setings = 0;  // sanjeev comment for priority issue. */



    if (g_jmms_context->is_add_media_warning == 0)
    {
        if (ret_code_restricted == JC_ERR_MSG_MMS_CONTENT_RESTRICTED)
        {
            U32 mms_size = 0;

            mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
            if (mms_size > MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE)
            {
                mmi_jmms_entry_write_message_screen();
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_MODE_MAX_MSG_SIZE_REACHED_NEED_DELETE),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            else
            {
                mmi_jmms_edit_content_restricted_mode_query();
            }

        }
        else
        {
            mmi_jmms_entry_write_message_screen();
        }
    }
    else
    {
        mmi_jmms_entry_write_message_screen();
        DisplayPopup((PU8) GetString(STR_ID_JMMS_MMS_ERR_WARNING_CONTENT_CLASS),
                     IMG_GLOBAL_WARNING, 1, JMMS_POPUP_TIME, WARNING_TONE);

    }

  END:

    if (temp_str_p != NULL)
    {
        jdd_MemFree(temp_str_p);
        temp_str_p = NULL;
    }
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
    g_jmms_context->is_add_media_warning = 0;
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);

    return;

}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_pre_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_pre_delete(void)
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

    SetLeftSoftkeyFunction(mmi_jmms_drafts_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_post_drafts_delete_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_post_drafts_delete_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_jmms_pre_entry_draft();
#else 
    GoBackHistory();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &number); */

    number = g_jmms_context->store_context->num_msg_in_curr_folder;

    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_DRAFTS, IMG_GLOBAL_DELETED);

    ret_code = mmi_jmms_delete_message(MMI_JMMS_DRAFTS, (number - g_jmms_context->curr_scr_hilited_index));

    if (ret_code == JC_OK)
    {
        /* Dilip 25 aug 2006 */
        DisplayPopupCallBack((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE, mmi_jmms_post_drafts_delete_message);   /* Vikram: To call entry function only after popup is over as this wil send a new request for messages in UM */
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_MAIN);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        if (g_jmms_context->store_context->num_msg_in_curr_folder - 1)
        {
            HistoryReplace(SCR_ID_JMMS_DRAFTS, SCR_ID_JMMS_DRAFTS, mmi_jmms_entry_drafts);
            DeleteUptoScrID(SCR_ID_JMMS_DRAFTS);
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
        DeleteUptoScrID(SCR_ID_UM_DRAFT);
    #else 
        DeleteUptoScrID(SCR_ID_JMMS_DRAFTS);
    #endif 

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_delete_on_sent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_delete_on_sent(void)
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
      These lines has been added to delete the MMS stored into the Draft folder after
      It has been sent successfully. Since file handle is open so it is not able to 
      delete the MMS from the 'DRAFT' folder. So before performing the MMS delete, 
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

    ret_code = mmi_jmms_delete_message(MMI_JMMS_DRAFTS, (number - g_jmms_context->curr_scr_hilited_index));

    if (ret_code == JC_OK)
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_DRAFT, SCR_ID_UM_DRAFT, mmi_um_jmms_pre_entry_draft);
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_DRAFT);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        HistoryReplace(SCR_ID_JMMS_DRAFTS, SCR_ID_JMMS_DRAFTS, mmi_jmms_entry_drafts);

        if (number <= 1)    /* /now folder will empty */
        {
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_MAIN_MENU);
        }
        else
        {
            DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_DRAFTS);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
    else
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_UM_DRAFT);
    #else 
        DeleteFromScrUptoScr(SCR_ID_JMMS_PROGRESS, SCR_ID_JMMS_DRAFTS);
    #endif 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_delete_all(void)
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
        get_string(STR_ID_JMMS_DELETE_ALL_UM_DRAFTS),
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
        /* MAUI_00018477 Start */ get_string(STR_ID_JMMS_DELETE_ALL_UM_DRAFTS),
        /* MAUI_00018477 End */ IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    /* Dilip 29 Aug 2006 */
    SetLeftSoftkeyFunction(mmi_jmms_delete_all_message_drafts, KEY_EVENT_UP);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_message_drafts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_all_message_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_progresing_screen(STR_ID_JMMS_DRAFTS, IMG_GLOBAL_PROGRESS);

    ret_code = mmi_jmms_delete_all_message(MMI_JMMS_DRAFTS);
    if (JC_OK != ret_code)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_ERROR_MMS_DELETE),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_DRAFTS);
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
 *  mmi_jmms_drafts_use_details
 * DESCRIPTION
 *  pre entry fn for use details screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_pre_entry_use_details_screen(MMI_JMMS_DRAFTS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drafts_properties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_drafts_properties(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_type = mmi_jmms_get_msg_type(g_jmms_context->curr_scr_hilited_index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_show_mms_properties(msg_type, MMI_JMMS_DRAFTS);
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
    mmi_jmms_show_mms_properties(node_p->msg_type, MMI_JMMS_DRAFTS);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_draft_options_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_draft_options_save_object(void)
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
#endif /* _MMI_JMMSDRAFTSSECMMI_C */ 


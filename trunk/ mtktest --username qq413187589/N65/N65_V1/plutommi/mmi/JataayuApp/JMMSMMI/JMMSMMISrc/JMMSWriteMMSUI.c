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
 *  JMMSWriteMMSUI.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the write mms ui and addresses addition,edit,deletion logics
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"

#include "MainMenuDef.h"
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

#include "ddlbase.h"
#include "jcerror.h"
#include "jcevent.h"
#include "jcutils.h"
#include "jdi_MMSErr.h"
#include "MessagingDataTypes.h"
#include "jdd_memapi.h"
#include "MessagesResourceData.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "miscutils.h"
#include "MMI_features_camera.h"
#include "CameraResDef.h"
#include "PhoneBookGprot.h"
#include "ComposeUtils.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "JMMSUMHandling.h"
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageProt.h"
#include "FileManagerDef.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#include "wapadp.h"     /* compiler warning removal */

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
#ifndef __MMI_UNIFIED_COMPOSER__
static pBOOL mmi_jmms_get_item_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
#endif 
/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
#endif /* ifdef __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__ */

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern void set_leading_zero(U8 u8type);
extern void EntryPhbFromMMSNumber(void);
extern void EntryPhbFromMMSEmail(void);

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_message
 * DESCRIPTION
 *  This function is the highlight handler of write message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_message_init
 * DESCRIPTION
 *  This function init the hilight handlers of write mms menu items.
 *  This is called at boot up time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_write_message_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* options Highlight handlers */
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_ADD_NUMBER, mmi_jmms_highlight_write_mms_add_number);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_ADD_EMAIL, mmi_jmms_highlight_write_mms_add_email);
#ifdef __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_ADD_NUMBER_BY_GROUP, mmi_jmms_highlight_write_mms_add_number_by_group);
    SetHiliteHandler(
        MENU_ID_JMMS_WRITE_MMS_ADD_EMAIL_ADDRESS_BY_GROUP,
        mmi_jmms_highlight_write_mms_add_email_addr_by_group);
#endif /* __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__ */ 
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_EDIT, mmi_jmms_highlight_write_mms_edit);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DELETE, mmi_jmms_highlight_write_mms_delete);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DELETE_ALL, mmi_jmms_highlight_write_mms_delete_all);

    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_ONLY, mmi_jmms_highlight_write_mms_done_send_only);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DONE_SAVE_AND_SEND, mmi_jmms_highlight_write_mms_done_save_and_send);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DONE_SAVE_TO_DRAFTS, mmi_jmms_highlight_write_mms_done_save_to_drafts);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_OPTIONS, mmi_jmms_highlight_write_mms_done_send_options);
    SetHiliteHandler(MENU_ID_JMMS_WRITE_MMS_DONE_EXIT, mmi_jmms_highlight_write_mms_done_exit);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message
 * DESCRIPTION
 *  This function is pre entry function for writing a new MMS
 *  new MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message(void)
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
    g_jmms_context->g_use_local_send_setings = 0;
    g_jmms_context->store_context->current_folder_name = E_JMMS_WRITE_MMS;

    mmi_jmms_init_msg_context_struct();     /* this will different for different ways to come here */
    /* MAUI_00227929 Start */
    mmi_jmms_fill_mms_sending_settings();   /* sanjeev added for newly added setting structure. */
    /* MAUI_00227929 End */
    /* deepali */
    if (g_jmms_context->compose_context == NULL)
    {
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
    }

    if (JMMS_COMP_OK == mmi_jmms_compose_new_mms())
    {
        mmi_jmms_entry_write_message_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_screen_in_history
 * DESCRIPTION
 *  Entry fn for Write MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_screen_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    history hist;
    historyNode *saved_history_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hist, 0, sizeof(history));
    hist.scrnID = SCR_ID_JMMS_WRITE_MMS_HISTORY;
    hist.entryFuncPtr = mmi_jmms_entry_write_message_screen;
    AddHistory(hist);
    /* This is a workaround to make sure that if small screen is the current screen on MMI.
       Its state is not changed and SCR_ID_JMMS_WRITE_MMS_HISTORY is not saved as small screen */
    GetHistoryPointer(SCR_ID_JMMS_WRITE_MMS_HISTORY, &saved_history_p);
    if (saved_history_p->isSmallScreen == 1)
    {
        saved_history_p->isSmallScreen = 0;
        set_small_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_screen
 * DESCRIPTION
 *  Entry fn for Write MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;     /* added for inline edit history */
    U16 input_buffer_size;  /* added for inline edit history */
    U16 image_list[WRITE_MMS_INLINE_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_jdi_deinitview(g_jmms_context->msg_handle);
#endif 

    if (g_jmms_context->compose_context == NULL)
    {
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
    }

    EntryNewScreen(SCR_ID_JMMS_WRITE_MMS, mmi_jmms_exit_write_message, NULL, NULL);

    set_leading_zero(FALSE);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_WRITE_MMS);

    InitializeCategory57Screen();

    mmi_jmms_write_mms_fill_inline_struct();
    RegisterHighlightHandler(mmi_jmms_write_mms_highlight_hdlr);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_WRITE_MMS, &input_buffer_size);    /* added for inline edit history */

    if (input_buffer_p) /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, WRITE_MMS_INLINE_TOTAL, input_buffer_p);   /* sets the data */
    }

    image_list[E_WRITE_MMS_TO] = IMG_ID_WRITE_MMS_TO;
    image_list[E_WRITE_MMS_CC] = IMG_ID_WRITE_MMS_CC;
    image_list[E_WRITE_MMS_BCC] = IMG_ID_WRITE_MMS_BCC;
    image_list[E_WRITE_MMS_SUBJECT] = IMG_ID_WRITE_MMS_SUBJECT;
    image_list[E_WRITE_MMS_ATTACHMENT_CAPTION] = IMG_ID_WRITE_MMS_ATTACHMENT;
    image_list[E_WRITE_MMS_EDIT_CONTENT_CAPTION] = IMG_ID_WRITE_MMS_EDIT_CONTENT;

    ShowCategory57Screen(
        NULL,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        NULL,
        NULL,
        (g_jmms_context->g_write_mms_right_soft_key),
        NULL,
        WRITE_MMS_INLINE_TOTAL,
        image_list,
        wgui_inline_items,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_jmms_done_write_mms, GoBackHistory);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_populate_phb_name
 * DESCRIPTION
 *  Fills the name from number
 * PARAMETERS
 *  name_p          [OUT]       Name from phb
 *  number_p        [IN]        Number to be searched for
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_write_populate_phb_name(S8 **name_p, S8 *number_p)
{
#ifdef __MMI_JATAAYU_MMS_DISPLAY_NAME_FROM_PHB__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *name;
    S8 *temp_address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Search The number from the Phone book */
    temp_address = (S8*) jdd_MemAlloc(sizeof(S8), (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8*) temp_address, (S8*) number_p, MAX_POSSIBLE_NUMBER_LENGHT_SENT);
    if (!mmi_ucs2chr((S8*) number_p, L'@'))
    {
        name = (PS8) lookUpNumber((PS8) temp_address);
        if (name != NULL && mmi_ucs2strlen(name) > 0)
        {
            *name_p = (S8*) name;
        }
        else
        {
            *name_p = number_p;
        }
    }
    else
    {
        *name_p = number_p;
    }
    jdd_MemFree(temp_address);
#else /* __MMI_JATAAYU_MMS_DISPLAY_NAME_FROM_PHB__ */ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *name_p = number_p;
#endif /* __MMI_JATAAYU_MMS_DISPLAY_NAME_FROM_PHB__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_mms_fill_inline_struct
 * DESCRIPTION
 *  Fills the inline structure for write mms screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_write_mms_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 *to_caption_p = NULL;
    S8 *cc_caption_p = NULL;
    S8 *bcc_caption_p = NULL;
    S8 *attachment_caption_p = g_jmms_context->g_jmms_files_caption_buff;
    S8 *slides_caption_p = g_jmms_context->g_jmms_slide_caption_buff;
    S32 len = 0, temp_len = 0;
    U8 no_attachments;

    /* PMT VIKAS START 20050325 */
    S8 str[20];
    S8 tempstr[20 * ENCODING_LENGTH] = {0x00};
    U8 page_count;
    U32 mms_size = 0;
    FLOAT mms_kb_size = 0, mms_mb_size = 0, mms_gb_size = 0, mms_tb_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS END 20050325 */
    /* TO */

    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_TO], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (g_jmms_context->num_to_addresses == 0)
    {
        to_caption_p = GetString(STR_ID_WRITE_MMS_TO_BLANK_CAPTION);
    }
    else if (g_jmms_context->num_to_addresses == 1)
    {
        mmi_jmms_write_populate_phb_name(&to_caption_p, g_jmms_context->to_address_p->address_p);
    }
    else
    {
        to_caption_p = g_jmms_context->g_jmms_to_caption_buff;
        memset(to_caption_p, 0x00, (MAX_RECIPIENTS_CAPTION_LENGTH + 1) * ENCODING_LENGTH);
        sprintf(str, "%d ", g_jmms_context->num_to_addresses);

        mmi_asc_to_ucs2((PS8) to_caption_p, (PS8) str);

        len = mmi_ucs2strlen((PS8) to_caption_p);

        temp_len = len;
        len = len + mmi_ucs2strlen((PS8) GetString(STR_ID_JMMS_RECIPIENTS));

        if (len > MAX_RECIPIENTS_CAPTION_LENGTH)
        {
            len = MAX_RECIPIENTS_CAPTION_LENGTH - temp_len;
            mmi_ucs2ncat((S8*) to_caption_p, (const S8*)GetString(STR_ID_JMMS_RECIPIENTS), len);
        }
        else
        {
            mmi_ucs2cat((S8*) to_caption_p, (const S8*)GetString(STR_ID_JMMS_RECIPIENTS));
        }

    }
    SetInlineItemDisplayOnly(&wgui_inline_items[E_WRITE_MMS_TO], (U8*) (to_caption_p));

    /* CC */
    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_CC], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (g_jmms_context->num_cc_addresses == 0)
    {
        cc_caption_p = GetString(STR_ID_WRITE_MMS_CC_BLANK_CAPTION);
    }
    else if (g_jmms_context->num_cc_addresses == 1)
    {
        mmi_jmms_write_populate_phb_name(&cc_caption_p, g_jmms_context->cc_address_p->address_p);
    }
    else
    {
        cc_caption_p = g_jmms_context->g_jmms_cc_caption_buff;
        memset(cc_caption_p, 0x00, (MAX_RECIPIENTS_CAPTION_LENGTH + 1) * ENCODING_LENGTH);

        sprintf(str, "%d ", g_jmms_context->num_cc_addresses);

        mmi_asc_to_ucs2((PS8) cc_caption_p, (PS8) str);

        len = mmi_ucs2strlen((PS8) cc_caption_p);

        temp_len = len;
        len = len + mmi_ucs2strlen((PS8) GetString(STR_ID_JMMS_RECIPIENTS));
        if (len > MAX_RECIPIENTS_CAPTION_LENGTH)
        {
            len = MAX_RECIPIENTS_CAPTION_LENGTH - temp_len;
            mmi_ucs2ncat((S8*) cc_caption_p, (const S8*)GetString(STR_ID_JMMS_RECIPIENTS), len);
        }
        else
        {
            mmi_ucs2cat((S8*) cc_caption_p, (const S8*)GetString(STR_ID_JMMS_RECIPIENTS));
        }

    }

    SetInlineItemDisplayOnly(&wgui_inline_items[E_WRITE_MMS_CC], (U8*) cc_caption_p);

    /* BCC */
    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_BCC], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    if (g_jmms_context->num_bcc_addresses == 0)
    {
        bcc_caption_p = GetString(STR_ID_WRITE_MMS_BCC_BLANK_CAPTION);
    }
    else if (g_jmms_context->num_bcc_addresses == 1)
    {
        mmi_jmms_write_populate_phb_name(&bcc_caption_p, g_jmms_context->bcc_address_p->address_p);
    }
    else
    {
        bcc_caption_p = g_jmms_context->g_jmms_bcc_caption_buff;
        memset(bcc_caption_p, 0x00, (MAX_RECIPIENTS_CAPTION_LENGTH + 1) * ENCODING_LENGTH);

        sprintf(str, "%d ", g_jmms_context->num_bcc_addresses);

        mmi_asc_to_ucs2((PS8) bcc_caption_p, (PS8) str);

        len = mmi_ucs2strlen((PS8) bcc_caption_p);

        temp_len = len;
        len = len + mmi_ucs2strlen((PS8) GetString(STR_ID_JMMS_RECIPIENTS));
        if (len > MAX_RECIPIENTS_CAPTION_LENGTH)
        {
            len = MAX_RECIPIENTS_CAPTION_LENGTH - temp_len;
            mmi_ucs2ncat((S8*) bcc_caption_p, (const S8*)GetString(STR_ID_JMMS_RECIPIENTS), len);
        }
        else
        {
            mmi_ucs2cat((S8*) bcc_caption_p, (const S8*)GetString(STR_ID_JMMS_RECIPIENTS));
        }

    }

    SetInlineItemDisplayOnly(&wgui_inline_items[E_WRITE_MMS_BCC], (U8*) bcc_caption_p);

    /* Subject */
#ifdef __MMI_JMMS_REDUCE_CHINESE_SUBJECT__
    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_SUBJECT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[E_WRITE_MMS_SUBJECT], (U8*) g_jmms_context->subject_input_buffer);
#else /* __MMI_JMMS_REDUCE_CHINESE_SUBJECT__ */ 
    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_SUBJECT], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[E_WRITE_MMS_SUBJECT],
        STR_ID_WRITE_MMS_SUBJECT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        (PU8) g_jmms_context->subject_input_buffer,
        MAX_SUBJECT_LENGTH + 1,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[E_WRITE_MMS_SUBJECT],
        mmi_jmms_write_mms_subject_custom_func);
#endif /* __MMI_JMMS_REDUCE_CHINESE_SUBJECT__ */ 

    /* Attachments */
    SetInlineItemActivation(
        &wgui_inline_items[E_WRITE_MMS_ATTACHMENT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&wgui_inline_items[E_WRITE_MMS_ATTACHMENT_CAPTION], (U8*) GetString(STR_ID_JMMS_ATTACHMENT));
    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_ATTACHMENT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    memset(attachment_caption_p, 0x00, (MAX_FILES_CAPTION_LENGTH + 1) * ENCODING_LENGTH);
    mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 0, &(no_attachments), E_TRUE);

    g_jmms_context->num_attachments = no_attachments;

    sprintf(str, "%d ", g_jmms_context->num_attachments);
    mmi_asc_to_ucs2((PS8) attachment_caption_p, (PS8) str);

    len = mmi_ucs2strlen((PS8) attachment_caption_p);
    temp_len = len;
    len = len + mmi_ucs2strlen((PS8) GetString(STR_ID_JMMS_FILES));
    if (len > MAX_FILES_CAPTION_LENGTH)
    {
        len = MAX_FILES_CAPTION_LENGTH - temp_len;
        mmi_ucs2ncat((S8*) attachment_caption_p, (const S8*)GetString(STR_ID_JMMS_FILES), len);
    }
    else
    {
        mmi_ucs2cat((S8*) attachment_caption_p, (const S8*)GetString(STR_ID_JMMS_FILES));
    }

    SetInlineItemDisplayOnly(&wgui_inline_items[E_WRITE_MMS_ATTACHMENT], (U8*) attachment_caption_p);

    /* Edit Content */
    SetInlineItemActivation(
        &wgui_inline_items[E_WRITE_MMS_EDIT_CONTENT_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[E_WRITE_MMS_EDIT_CONTENT_CAPTION],
        (U8*) GetString(STR_ID_WRITE_MMS_EDIT_CONTENT));
    SetInlineItemActivation(&wgui_inline_items[E_WRITE_MMS_EDIT_CONTENT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);

    memset(slides_caption_p, 0x00, (MAX_SLIDES_CAPTION_LENGTH + 1) * ENCODING_LENGTH);
    sprintf(str, "%d ", page_count);
    mmi_asc_to_ucs2((PS8) slides_caption_p, (PS8) str);

    len = mmi_ucs2strlen((PS8) slides_caption_p);
    temp_len = len;
    len = len + mmi_ucs2strlen((PS8) GetString(STR_ID_JMMS_SLIDES));
    if (len > MAX_SLIDES_CAPTION_LENGTH)
    {
        mmi_ucs2ncat(
            (S8*) slides_caption_p,
            (const S8*)GetString(STR_ID_JMMS_SLIDES),
            MAX_SLIDES_CAPTION_LENGTH - temp_len);
        goto END;
    }
    else
    {
        mmi_ucs2cat((S8*) slides_caption_p, (const S8*)GetString(STR_ID_JMMS_SLIDES));
    }

    //PMT VIKAS START 20050325
    //To add slide size
    mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);

    mms_kb_size = (FLOAT) mms_size / 1024;
    mms_mb_size = mms_kb_size / 1024;
    mms_gb_size = mms_mb_size / 1024;
    mms_tb_size = mms_gb_size / 1024;

    if (mms_kb_size < 1.0)
    {
        sprintf(str, " (%d ", mms_size);
        mmi_asc_to_ucs2((PS8) tempstr, (PS8) str);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) tempstr);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) GetString(STR_ID_JMMS_WRITE_MMS_BYTES));
    }
    else if (mms_kb_size < 1000.0)
    {
        if (mms_kb_size < 10.0)
        {
            sprintf(str, " (%0.2f ", mms_kb_size);
        }
        else if (mms_kb_size < 100.0)
        {
            sprintf((S8*) str, " (%0.1f ", mms_kb_size);
        }
        else
        {
            sprintf((S8*) str, " (%d ", (U32) mms_kb_size);
        }
        mmi_asc_to_ucs2((PS8) tempstr, (PS8) str);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) tempstr);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) GetString(STR_ID_JMMS_KB));
    }
    else if (mms_mb_size < 1000.0)
    {
        if (mms_mb_size < 10.0)
        {
            sprintf((S8*) str, " (%0.2f ", mms_mb_size);
        }
        else if (mms_mb_size < 100.0)
        {
            sprintf((S8*) str, " (%0.1f ", mms_mb_size);
        }
        else
        {
            sprintf((S8*) str, " (%d ", (U32) mms_mb_size);
        }
        mmi_asc_to_ucs2((PS8) tempstr, (PS8) str);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) tempstr);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) GetString(STR_ID_JMMS_MB));
    }
    else if (mms_gb_size < 1000.0)
    {
        if (mms_gb_size < 10.0)
        {
            sprintf((S8*) str, " (%0.2f ", mms_gb_size);
        }
        else if (mms_gb_size < 100.0)
        {
            sprintf((S8*) str, " (%0.1f ", mms_gb_size);
        }
        else
        {
            sprintf((S8*) str, " (%d ", (U32) mms_gb_size);
        }
        mmi_asc_to_ucs2((PS8) tempstr, (PS8) str);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) tempstr);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) GetString(STR_ID_JMMS_GB));
    }
    else if (mms_tb_size < 4.1)
    {
        sprintf((S8*) str, " (%0.2f %s", mms_tb_size, "TB");
        mmi_asc_to_ucs2((PS8) tempstr, (PS8) str);
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) tempstr);
    }
    else
    {
        /*
         * As the maximum limit of U32 datatype is 4294967295 which is equivalent to 4.0 TB
         */
        ASSERT(0);
    }

    memset(tempstr, 0, 20 * ENCODING_LENGTH);
    mmi_asc_to_ucs2((PS8) tempstr, ")");
    temp_len = len;
    len = len + mmi_ucs2strlen((PS8) tempstr);
    if (len > MAX_SLIDES_CAPTION_LENGTH)
    {
        mmi_ucs2ncat((S8*) slides_caption_p, (S8*) tempstr, MAX_SLIDES_CAPTION_LENGTH - temp_len);
    }
    else
    {
        mmi_ucs2cat((S8*) slides_caption_p, (S8*) tempstr);
    }

    /* PMT VIKAS END 20050325 */

  END:

    SetInlineItemDisplayOnly(&wgui_inline_items[E_WRITE_MMS_EDIT_CONTENT], (U8*) slides_caption_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_mms_subject_custom_func
 * DESCRIPTION
 *  Custom fn for subject editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_write_mms_subject_custom_func(void)
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

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

}

#ifdef __MMI_JMMS_REDUCE_CHINESE_SUBJECT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_input_method_and_done_go_back_to_write_mms
 * DESCRIPTION
 *  Control return to subject editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_input_method_and_done_go_back_to_write_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_input_method_and_done_hilite_handler
 * DESCRIPTION
 *  Highlighter to options on subject editor
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_input_method_and_done_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_jmms_input_method_and_done_go_back_to_write_mms, KEY_EVENT_UP);
        SetKeyHandler(mmi_jmms_input_method_and_done_go_back_to_write_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_frm_highlight_input_method_generic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_input_method_and_done_mms
 * DESCRIPTION
 *  Open option screen for subject editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_input_method_and_done_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_INPUT_METHOD_AND_DONE, NULL, mmi_jmms_input_method_and_done_mms, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_AND_DONE);
    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    RegisterHighlightHandler(mmi_jmms_input_method_and_done_hilite_handler);
    numItems = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_subject_mms
 * DESCRIPTION
 *  Open the subject editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_write_subject_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 left_softkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_WRITE_MMS_ADD_SUBJECT_EDITOR, NULL, mmi_jmms_write_subject_mms, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_WRITE_MMS_ADD_SUBJECT_EDITOR);
    ShowCategory215Screen(
        STR_ID_WRITE_MMS_SUBJECT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (PU8) g_jmms_context->subject_input_buffer,
        MAX_SUBJECT_LENGTH + 1,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_input_method_and_done_mms, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* __MMI_JMMS_REDUCE_CHINESE_SUBJECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_mms_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of write mms screen items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_write_mms_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    if (index == E_WRITE_MMS_ATTACHMENT)
    {
        if (mmi_jmms_is_message_to_fwd() == MMI_TRUE)
        {
            ChangeLeftSoftkey(NULL, NULL);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_jmms_entry_attachment_options, KEY_EVENT_UP);
        }
        ChangeTitleString((U8*) GetString(STR_ID_JMMS_ATTACHMENT));
        draw_title();
        if (g_jmms_context->g_write_mms_right_soft_key == STR_GLOBAL_DONE)
        {
            SetRightSoftkeyFunction(mmi_jmms_done_write_mms, KEY_EVENT_UP);
            ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
        }

    }
    else
    {
        if (mmi_jmms_is_message_to_fwd() == MMI_TRUE && index == E_WRITE_MMS_EDIT_CONTENT)
        {
            ChangeLeftSoftkey(NULL, NULL);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_EDIT, NULL);
        }

        if (index == E_WRITE_MMS_TO)
        {
            g_jmms_context->address_list_flag = E_TO_ADDRESSES;
            SetLeftSoftkeyFunction(mmi_jmms_entry_address_option, KEY_EVENT_UP);
            ChangeTitleString((U8*) GetString(STR_ID_WRITE_MMS_TO));
            draw_title();
        }

        if (index == E_WRITE_MMS_CC)
        {
            g_jmms_context->address_list_flag = E_CC_ADDRESSES;
            SetLeftSoftkeyFunction(mmi_jmms_entry_address_option, KEY_EVENT_UP);
            ChangeTitleString((U8*) GetString(STR_ID_WRITE_MMS_CC));
            draw_title();
        }

        if (index == E_WRITE_MMS_BCC)
        {
            g_jmms_context->address_list_flag = E_BCC_ADDRESSES;
            SetLeftSoftkeyFunction(mmi_jmms_entry_address_option, KEY_EVENT_UP);
            ChangeTitleString((U8*) GetString(STR_ID_WRITE_MMS_BCC));
            draw_title();
        }

        if (index == E_WRITE_MMS_EDIT_CONTENT)
        {
            if (mmi_jmms_is_message_to_fwd() != MMI_TRUE)
            {
                SetLeftSoftkeyFunction(mmi_jmms_pre_entry_edit_content_screen, KEY_EVENT_UP);
            }
            else
            {
                ChangeLeftSoftkey(NULL, NULL);
            }
            ChangeTitleString((U8*) GetString(STR_ID_WRITE_MMS_EDIT_CONTENT));
            draw_title();
        }

        if (index == E_WRITE_MMS_SUBJECT)
        {
            ChangeTitleString((U8*) GetString(STR_ID_WRITE_MMS_SUBJECT));
            draw_title();
        #ifdef __MMI_JMMS_REDUCE_CHINESE_SUBJECT__
            SetLeftSoftkeyFunction(mmi_jmms_write_subject_mms, KEY_EVENT_UP);
        #endif 
            if (g_jmms_context->g_write_mms_right_soft_key == STR_GLOBAL_DONE)
            {
                SetRightSoftkeyFunction(mmi_jmms_done_write_mms, KEY_EVENT_UP);
                ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
            }
        }

        if (index == E_WRITE_MMS_CC || index == E_WRITE_MMS_TO || index == E_WRITE_MMS_BCC ||
            index == E_WRITE_MMS_EDIT_CONTENT)
        {
            if (g_jmms_context->g_write_mms_right_soft_key == STR_GLOBAL_DONE)
            {
                SetRightSoftkeyFunction(mmi_jmms_done_write_mms, KEY_EVENT_UP);
                ChangeRightSoftkey(STR_GLOBAL_DONE, NULL);
            }

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_write_message
 * DESCRIPTION
 *  Exit fn of write mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_write_message(void)
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
    history_buff.scrnID = SCR_ID_JMMS_WRITE_MMS;
    history_buff.entryFuncPtr = mmi_jmms_entry_write_message_screen;
    mmi_ucs2cpy((S8*) history_buff.inputBuffer, (S8*) & nhistory);
    GetCategory57History(history_buff.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) history_buff.inputBuffer);  /* added for inline edit history */
    AddNHistory(history_buff, input_buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_address_option
 * DESCRIPTION
 *  pre entry fn for addresses options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_address_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        if (g_jmms_context->num_to_addresses == 0)
        {
            mmi_jmms_entry_addresses_option_screen();
        }
        else
        {
            g_jmms_context->g_hilite_address_item = 0;
            g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_BACK;
            mmi_jmms_entry_addresses_list_screen();
        }
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        if (g_jmms_context->num_cc_addresses == 0)
        {
            mmi_jmms_entry_addresses_option_screen();
        }
        else
        {
            g_jmms_context->g_hilite_address_item = 0;
            g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_BACK;
            mmi_jmms_entry_addresses_list_screen();
        }

    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        if (g_jmms_context->num_bcc_addresses == 0)
        {
            mmi_jmms_entry_addresses_option_screen();
        }
        else
        {
            g_jmms_context->g_hilite_address_item = 0;
            g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_BACK;
            mmi_jmms_entry_addresses_list_screen();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_addresses_option_screen
 * DESCRIPTION
 *  Entry fn for addresses option screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_addresses_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer_p;   /* Buffer holding history data */
    U16 n_str_item_list[MAX_SUB_MENUS];
    U16 n_num_of_item;
    U8 temp_num_items;
    U16 titleid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        temp_num_items = g_jmms_context->num_to_addresses;
        titleid = STR_ID_WRITE_MMS_TO;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        temp_num_items = g_jmms_context->num_cc_addresses;
        titleid = STR_ID_WRITE_MMS_CC;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        temp_num_items = g_jmms_context->num_bcc_addresses;
        titleid = STR_ID_WRITE_MMS_BCC;
    }
    else
    {
        return;
    }

    EntryNewScreen(SCR_ID_WRITE_MMS_ADDRESSES_OPTION, NULL, mmi_jmms_entry_addresses_option_screen, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_WRITE_MMS_ADDRESSES_OPTION);

    SetParentHandler(MENU_ID_JMMS_WRITE_MMS_ADDRESSES_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (temp_num_items == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_EDIT);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_EDIT);
    }

    if (temp_num_items == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_DELETE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_DELETE);
    }

    if (temp_num_items <= 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_DELETE_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_DELETE_ALL);
    }

    n_num_of_item = GetNumOfChild_Ext(MENU_ID_JMMS_WRITE_MMS_ADDRESSES_OPTIONS);

    GetSequenceStringIds_Ext(MENU_ID_JMMS_WRITE_MMS_ADDRESSES_OPTIONS, n_str_item_list);

    ShowCategory52Screen(
        titleid,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_num_of_item,
        n_str_item_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

}

#ifdef __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_add_number_by_group
 * DESCRIPTION
 *  highligh handler of Add Group menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_add_number_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_address_option_index = E_ADD_NUMBER_GROUP;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_add_group_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_message_add_group_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_add_group_screen, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_add_email_addr_by_group
 * DESCRIPTION
 *  highligh handler of Add Group menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_add_email_addr_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_address_option_index = E_ADD_EMAIL_GROUP;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_add_group_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_message_add_group_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_add_group_screen, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_add_group_screen
 * DESCRIPTION
 *  Entry fn for Add Group screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_add_group_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->num_total_addresses >= MAX_POSSIBLE_ADDRESSES)
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_ADDRESS_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    else if (g_jmms_context->g_address_option_index == E_ADD_NUMBER_GROUP)
    {
        mmi_phb_get_address_from_caller_group((U8) MMI_PHB_ENTRY_FIELD_NUMBER, mmi_jmms_get_group_address_callback);
    }
    else if (g_jmms_context->g_address_option_index == E_ADD_EMAIL_GROUP)
    {
        mmi_phb_get_address_from_caller_group((U8) MMI_PHB_ENTRY_FIELD_EMAIL, mmi_jmms_get_group_address_callback);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_group_address_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnt             [IN]        
 *  PhbIndex        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_group_address_callback(U16 cnt, U16 *PhbIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;
    U32 ret = 0;
    U32 num_addresses = 0;
    U32 duplicate_address = 0;
    MMI_BOOL result = MMI_TRUE;
    MMI_BOOL found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_UNFINISHED, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);

        return;
    }

    if (g_jmms_context->g_address_option_index == E_ADD_NUMBER_GROUP)
    {
        U8 PhbNum[MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1];
        U8 type = 0;
        S8 PhbNumUCS2[(MAX_POSSIBLE_NUMBER_LENGHT_SENT + 2) * ENCODING_LENGTH];

        for (; index < cnt; index++)
        {
            if (g_jmms_context->num_total_addresses >= MAX_POSSIBLE_ADDRESSES)
            {
                break;
            }
            memset(PhbNum, 0, MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1);
            mmi_phb_convert_to_digit(
                (U8*) PhbNum,
                (U8*) PhoneBook[PhbIndex[index]].tel.number,
                MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1);
            memset(PhbNumUCS2, 0, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 2) * ENCODING_LENGTH);
            if (PhoneBook[PhbIndex[index]].tel.type == CSMCC_INTERNATIONAL_ADDR)
            {
                type = 1;
                mmi_asc_to_ucs2((S8*) PhbNumUCS2, "+");
            }
            mmi_asc_n_to_ucs2(
                (S8*) PhbNumUCS2 + type * ENCODING_LENGTH,
                (S8*) PhbNum,
                PhoneBook[PhbIndex[index]].tel.length);

            found = mmi_jmms_check_duplicate_address((U8*) PhbNumUCS2, E_NONE_ADDRESSES, -1);  /* COMPILER WARNING REMOVAL */

            if (found == MMI_TRUE)
            {
                duplicate_address++;
            }
            else
            {
                ret = mmi_jmms_add_address_in_addresse_list((S8*) PhbNumUCS2);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
            }
        }
    }
    else if (g_jmms_context->g_address_option_index == E_ADD_EMAIL_GROUP)
    {
        U8 *email_addr;
        U8 addr_length;
        U8 email_addrUCS2[(MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1) * ENCODING_LENGTH];

        for (; index < cnt; index++)
        {
            if (g_jmms_context->num_total_addresses >= MAX_POSSIBLE_ADDRESSES)
            {
                break;
            }
            email_addr = mmi_phb_get_email_p(PhbIndex[index], &addr_length);
            if (addr_length > MAX_POSSIBLE_EMAIL_LENGHT_SENT)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[JMMSWriteMMSUI.c] mmi_mms_get_group_address_callback email addr length too long *\n");
                continue;
            }

            memset(email_addrUCS2, 0, (MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((S8*) email_addrUCS2, (S8*) email_addr, addr_length);

            if (!mmi_jmms_check_address_input_format(email_addrUCS2))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[JMMSWriteMMSUI.c] mmi_mms_get_group_address_callback invalid email addr *\n");
                if (cnt == 1)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_INPUT_FORMAT_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    return;
                }

                continue;
            }
            found = mmi_jmms_check_duplicate_address((U8*) email_addrUCS2, E_NONE_ADDRESSES, -1);      /* COMPILER WARNING REMOVAL */

            if (found == MMI_TRUE)
            {
                duplicate_address++;
            }

            else
            {
                ret = mmi_jmms_add_address_in_addresse_list((S8*) email_addrUCS2);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
            }
        }   /* End of For Loop */
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* /back to address_p list screen with newly added adress highlighted and rsk as DONE */
    g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_DONE;
    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        num_addresses = g_jmms_context->num_to_addresses;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        num_addresses = g_jmms_context->num_cc_addresses;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        num_addresses = g_jmms_context->num_bcc_addresses;
    }

    g_jmms_context->g_hilite_address_item = num_addresses;

    if (!IsScreenPresent(SCR_ID_JMMS_ADDRESS_LIST))
    {
        /* We don't need to add the SCR_CALLER_GROUPS screen to history again. So, we have to use HistoryReplace() insteasd of invoking the entry function 
           mmi_jmms_entry_addresses_list_screen()  */
        HistoryReplace(
            SCR_ID_WRITE_MMS_ADDRESSES_OPTION,
            SCR_ID_JMMS_ADDRESS_LIST,
            mmi_jmms_entry_addresses_list_screen);
    }
    DeleteUptoScrID(SCR_ID_JMMS_ADDRESS_LIST);

    if (g_jmms_context->g_address_option_index == E_ADD_NUMBER_GROUP)
    {
        if (g_jmms_context->num_total_addresses == MAX_POSSIBLE_ADDRESSES && index < cnt)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ALL_NUMBERS_COULD_NOT_BE_ADDED),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
        }
        else if ((index == cnt) && (duplicate_address != 0 && duplicate_address < cnt))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_SOME_NUMBERS_ALREADY_EXIST),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else if (duplicate_address == cnt)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ALL_NUMBERS_ALREADY_EXIST),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
            GoBackHistory();
        }

    }
    else if (g_jmms_context->g_address_option_index == E_ADD_EMAIL_GROUP)
    {

        if (g_jmms_context->num_total_addresses == MAX_POSSIBLE_ADDRESSES && index < cnt)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ALL_EMAILS_COULD_NOT_BE_ADDED),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
        }
        else if ((index == cnt) && (duplicate_address != 0 && duplicate_address < cnt))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_SOME_EMAILS_ALREADY_EXIST),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else if (duplicate_address == cnt)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ALL_EMAILS_ALREADY_EXIST),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
            GoBackHistory();
        }
    }

}

#endif /* __MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_add_number
 * DESCRIPTION
 *  highligh handler of Add Number menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_add_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_address_option_index = E_ADD_NUMBER;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_add_number, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_message_add_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_add_number, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_add_number
 * DESCRIPTION
 *  Pre Entry fn for add number option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_add_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->num_total_addresses >= 20)
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_ADDRESS_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    else
    {
        memset(g_jmms_context->g_jmms_add_number_buffer, 0x00, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);
        mmi_jmms_entry_write_message_add_number_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_add_number_screen
 * DESCRIPTION
 *  Entry fn for add number editor screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_add_number_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 left_softkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR, NULL, mmi_jmms_entry_write_message_add_number_screen, NULL);

    SetParentHandler(MENU_ID_JMMS_WRITE_MMS_ADD_NUMBER);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR);

    if (mmi_ucs2ncmp
        ((S8*) (g_jmms_context->g_jmms_add_number_buffer), "\0",
         MAX_POSSIBLE_NUMBER_LENGHT_SENT * ENCODING_LENGTH) == 0)
    {
        left_softkey = STR_ID_JMMS_SEARCH;
    }
    else
    {
        left_softkey = STR_GLOBAL_OK;
    }

    ShowCategory5Screen(
        STR_ID_WRITE_MMS_ADD_NUMBER,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        left_softkey,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_PHONE_NUMBER,
        (U8*) (g_jmms_context->g_jmms_add_number_buffer),
        MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1,
        gui_buffer_p);

    RegisterInputBoxEmptyFunction(mmi_jmms_address_fullscreen_editor_on_empty);
    RegisterInputBoxNotEmptyFunction(mmi_jmms_address_fullscreen_editor_on_not_empty);

    SetKeyHandler(mmi_jmms_address_search_phonebook_or_ok, KEY_WAP, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_jmms_address_search_phonebook_or_ok, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler((FuncPtr) mmi_jmms_address_editor_insert_character_plus, KEY_STAR, KEY_EVENT_DOWN);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_address_fullscreen_editor_on_empty
 * DESCRIPTION
 *  Fn called when editor screen is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_address_fullscreen_editor_on_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetActiveScreenId();
    if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR)
    {
        ChangeLeftSoftkey(STR_ID_JMMS_SEARCH, 0);
    }
    else if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR)
    {
        ChangeLeftSoftkey(STR_ID_JMMS_SEARCH, 0);
    }
    else
    {
        ChangeLeftSoftkey(NULL, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_address_fullscreen_editor_on_not_empty
 * DESCRIPTION
 *  This Fn called when editor screen is not empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_address_fullscreen_editor_on_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetActiveScreenId();
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR)  /* /lefyt soft key set to NULL also so left key handler get cleared */
    {
        SetLeftSoftkeyFunction(mmi_jmms_address_search_phonebook_or_ok, KEY_EVENT_UP);
    }
}

/* PMT VUIKAS START 20060325 */


/*****************************************************************************
 * FUNCTION
 *  update_mms_number_from_phonebook
 * DESCRIPTION
 *  This fn copy the number selected from phonebook to adderess editor(number) screen
 * PARAMETERS
 *  number_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void update_mms_number_from_phonebook(S8 *number_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL number_allow = MMI_TRUE;

    /* U8 *temp_str; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* (U8*) temp_str = (U8*) number_p; */
    number_allow = mmi_jmms_check_number_input_format((U8*) number_p);
    if (number_allow == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_INPUT_FORMAT_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        if (IsScreenPresent(SCR_PBOOK_LIST))
        {
            DeleteUptoScrID(SCR_PBOOK_LIST);
        }
        memset(g_jmms_context->g_jmms_add_number_buffer, 0x00, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);
        return;
    }

    if (number_p)
    {
        memset(g_jmms_context->g_jmms_add_number_buffer, 0x00, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) (g_jmms_context->g_jmms_add_number_buffer), (PS8) number_p);
    }
    /* Dilip Start 14th Sept to display out of limit number_p from phonebook */
    if (g_jmms_context->g_jmms_add_number_buffer[MAX_POSSIBLE_NUMBER_LENGHT_SENT * ENCODING_LENGTH] != '\0')
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_PHB_LIMIT_EXCEEDED),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        if (IsScreenPresent(SCR_PBOOK_LIST))
        {
            DeleteUptoScrID(SCR_PBOOK_LIST);
        }
        memset(g_jmms_context->g_jmms_add_number_buffer, 0x00, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);

    }
    /* Dilip END 14th Sept to display out of limit number_p from phonebook */
    else
    {

        HistoryReplace(
            SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR,
            SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR,
            mmi_jmms_entry_write_message_add_number_screen);
        GoBackToHistory(SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_mms_email_from_phonebook
 * DESCRIPTION
 *  This fn copy the email selected from phonebook to adderess editor(email) screen
 * PARAMETERS
 *  email_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void update_mms_email_from_phonebook(S8 *email_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL email_allow = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_allow = mmi_jmms_check_address_input_format((U8*) email_p);
    if (email_allow == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_JMMS_INPUT_FORMAT_ERROR),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        if (IsScreenPresent(SCR_PBOOK_LIST))
        {
            DeleteUptoScrID(SCR_PBOOK_LIST);
        }
        memset(g_jmms_context->g_jmms_add_email_buffer, 0x00, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);
        return;
    }

    if (email_p)
    {
        mmi_ucs2cpy((S8*) (g_jmms_context->g_jmms_add_email_buffer), (PS8) email_p);
    }

    HistoryReplace(
        SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR,
        SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR,
        mmi_jmms_entry_write_message_add_email_screen);
    GoBackToHistory(SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR);
}

/* PMT VUIKAS END 20060325 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_address_search_phonebook_or_ok
 * DESCRIPTION
 *  This fn henadled the LSK press in adderess editor(number or email) screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_address_search_phonebook_or_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL found = MMI_FALSE;
    U8 *temp_str;
    U8 length;
    MMI_BOOL format_allow = MMI_TRUE;
    U16 curr_scr_id;
    U8 num_addresses = 0;
    U8 ret = 0;
    MMI_BOOL number_allow_phb = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetActiveScreenId();

    if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR)
    {
        temp_str = g_jmms_context->g_jmms_add_number_buffer;
        length = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
    }
    else if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR)
    {
        temp_str = g_jmms_context->g_jmms_add_email_buffer;
        length = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
    }
    else
    {
        return;
    }

    if (mmi_ucs2ncmp((S8*) temp_str, "\0", length * ENCODING_LENGTH) == 0)
    {
        /* PMT VIKAS START 20060325 */
        if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR)
        {
            EntryPhbFromMMSNumber();
            temp_str = g_jmms_context->g_jmms_add_number_buffer;
        }
        else if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR)
        {
            EntryPhbFromMMSEmail();
            temp_str = g_jmms_context->g_jmms_add_email_buffer;
        }
        /* PMT VIKAS END 20060325 */
    }
    else
    {
        if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR)
        {
            number_allow_phb = mmi_jmms_check_number_input_format(temp_str);
            if (number_allow_phb == MMI_FALSE)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_INPUT_FORMAT_ERROR),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                return;
            }
        }

        if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR)
        {
            format_allow = mmi_jmms_check_address_input_format(temp_str);
        }

        if (format_allow == MMI_FALSE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_INPUT_FORMAT_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            return;
        }
        /* Dilip 1st Sept 06 */
        if (g_jmms_context->g_address_option_index == E_EDIT_ADDRESS)
        {
            U8 temp = 0;
            mmi_jmms_address_list_struct *address_node_p = NULL;

            if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
            {
                address_node_p = g_jmms_context->to_address_p;;
            }
            else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
            {
                address_node_p = g_jmms_context->cc_address_p;
            }
            else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
            {
                address_node_p = g_jmms_context->bcc_address_p;
            }
            if (address_node_p != NULL)
            {
                temp = g_jmms_context->g_hilite_address_item;
                while (temp)
                {
                    address_node_p = address_node_p->next_p;
                    temp--;
                }
            }
            if (address_node_p != NULL)
            {
                if (mmi_jmms_compair_string((S8*) temp_str, (S8*) address_node_p->address_p) != 0)
                {
                    found = mmi_jmms_check_duplicate_address(
                                temp_str,
                                g_jmms_context->address_list_flag,
                                g_jmms_context->g_hilite_address_item);
                }

            }

        }
        else
        {
            found = mmi_jmms_check_duplicate_address(temp_str, E_NONE_ADDRESSES, -1);   /* COMPILER WARNING REMOVAL */
        }
        /* Dilip 1st Sept 06 */
        if (found != MMI_TRUE)
        {
            if (g_jmms_context->g_address_option_index == E_EDIT_ADDRESS)
            {
                ret = mmi_jmms_replace_address_in_addresse_list((S8*) temp_str);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
                g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_DONE;
                g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;
                GoBackToHistory(SCR_ID_JMMS_ADDRESS_LIST);
            }
            else    /* add number or email */
            {
                ret = mmi_jmms_add_address_in_addresse_list((S8*) temp_str);
                if (ret != 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        (U8) ERROR_TONE);
                    return;
                }
                /* /back to address_p list scren with newly added adress highlighted and rsk as DONE */
                g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_DONE;
                g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

                if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
                {
                    num_addresses = g_jmms_context->num_to_addresses;
                }
                else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
                {
                    num_addresses = g_jmms_context->num_cc_addresses;
                }
                else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
                {
                    num_addresses = g_jmms_context->num_bcc_addresses;
                }

                g_jmms_context->g_hilite_address_item = num_addresses;

                if (num_addresses <= 1)
                {
                    /* We don't need to add the SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR screen to history 
                       again. So, we have to use HistoryReplace() insteasd of invoking the entry function 
                       mmi_jmms_entry_addresses_list_screen()  */
                    HistoryReplace(
                        SCR_ID_WRITE_MMS_ADDRESSES_OPTION,
                        SCR_ID_JMMS_ADDRESS_LIST,
                        mmi_jmms_entry_addresses_list_screen);
                    // mmi_jmms_entry_addresses_list_screen(); /* /new entry to address_p list screen */
                    GoBackHistory();
                }
                else
                {
                    ///it means address_p list screen already exist
                    ///just go back to that screen
                    GoBackToHistory(SCR_ID_JMMS_ADDRESS_LIST);
                }

            }

        }
        else
        {
            /* changes for adding different message for Email address_p and phone Number */
            /* Dilip Start 21 Aug 2006 */
            if (curr_scr_id == SCR_ID_JMMS_WRITE_MMS_ADD_NUMBER_EDITOR)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_ADDRESS_ALREADY_EXIST),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_EMAIL_ADDRESS_ALREADY_EXIST),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
            }
            /* Dilip End 21 Aug 2006 */
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_address_editor_insert_character_plus
 * DESCRIPTION
 *  Handler of plus Key in address_p editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_address_editor_insert_character_plus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_direct_input((UI_character_type) '+');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_add_email
 * DESCRIPTION
 *  highlight hdlr of Add email option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_add_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_address_option_index = E_ADD_EMAIL;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_add_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_message_add_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_add_email, KEY_WAP, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_add_email
 * DESCRIPTION
 *  pre entry fn of add email option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_add_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->num_total_addresses >= 20)
    {
        DisplayPopup((U8*) GetString(STR_ID_MAX_ADDRESS_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
    else
    {
        memset(g_jmms_context->g_jmms_add_email_buffer, 0x00, (MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1) * ENCODING_LENGTH);
        mmi_jmms_entry_write_message_add_email_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_add_email_screen
 * DESCRIPTION
 *  entry fn of add email editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_add_email_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 left_softkey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR, NULL, mmi_jmms_entry_write_message_add_email_screen, NULL);

    SetParentHandler(MENU_ID_JMMS_WRITE_MMS_ADD_EMAIL);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_WRITE_MMS_ADD_EMAIL_EDITOR);

    if (mmi_ucs2ncmp
        ((S8*) (g_jmms_context->g_jmms_add_email_buffer), "\0", MAX_POSSIBLE_EMAIL_LENGHT_SENT * ENCODING_LENGTH) == 0)
        /* PMT VIKAS START 20060325 */
    {
        left_softkey = STR_ID_JMMS_SEARCH;
    }
    /* PMT VIKAS END 20060325 */
    else
    {
        left_softkey = STR_GLOBAL_OK;
    }

    /* PMT VIKAS START 20060325 */
    ShowCategory5Screen(
        STR_ID_WRITE_MMS_ADD_EMAIL,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        left_softkey,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) (g_jmms_context->g_jmms_add_email_buffer),
        MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1,
        gui_buffer_p);
    /* PMT VIKAS END 20060325 */

    RegisterInputBoxEmptyFunction(mmi_jmms_address_fullscreen_editor_on_empty);
    RegisterInputBoxNotEmptyFunction(mmi_jmms_address_fullscreen_editor_on_not_empty);

    SetLeftSoftkeyFunction(mmi_jmms_address_search_phonebook_or_ok, KEY_EVENT_UP);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_delete
 * DESCRIPTION
 *  highlight hdlr of delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_delete, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_delete, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_delete_all
 * DESCRIPTION
 *  highlight hdlr of delete all option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_delete_all, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_delete_all, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_addresses_list_screen
 * DESCRIPTION
 *  Entry fn for addresses list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_addresses_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer_p = NULL;    /* Buffer holding history data */
    U16 num_item;               /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_ADDRESS_LIST, NULL, mmi_jmms_entry_addresses_list_screen, NULL);

    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        num_item = g_jmms_context->num_to_addresses;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        num_item = g_jmms_context->num_cc_addresses;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        num_item = g_jmms_context->num_bcc_addresses;
    }
    else
    {
        return;
    }

    RegisterHighlightHandler(mmi_jmms_address_list_highlight_hdlr);

    ShowCategory184Screen(
        STR_ID_JMMS_RECIPIENTS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        g_jmms_context->g_address_list_right_soft_key,
        IMG_GLOBAL_BACK,
        num_item,
        mmi_jmms_get_item_data,
        0,
        g_jmms_context->g_hilite_address_item,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_entry_addresses_option_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_addresses_option_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_addresses_option_screen, KEY_WAP, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_jmms_back_to_write_mms, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_back_to_write_mms, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_item_data
 * DESCRIPTION
 *  To get the data items of address_p list screen
 * PARAMETERS
 *  item_index          [IN]        (index of current item)
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_jmms_get_item_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_address_list_struct *address_node_p;
    U8 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        address_node_p = g_jmms_context->to_address_p;;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        address_node_p = g_jmms_context->cc_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        address_node_p = g_jmms_context->bcc_address_p;
    }
    else
    {
        return FALSE;
    }

    while (temp != item_index)
    {
        address_node_p = address_node_p->next_p;
        temp++;
    }

    memset(str_buff, 0, MAX_SUB_MENU_HINT_SIZE);
    mmi_jmms_copy_email_number_or_name_of_number_from_phb_to_buffer(
        (S8*) str_buff,
        (S8*) address_node_p->address_p,
        MAX_SUBMENU_CHARACTERS,
        MAX_SUBMENU_CHARACTERS);

    /* *img_buff_p = (PU8) GetImage((U16) (gIndexIconsImageList[item_index])); */
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        *img_buff_p = (PU8) GetImage((U16) (IMG_ID_WRITE_MMS_TO));
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        *img_buff_p = (PU8) GetImage((U16) (IMG_ID_WRITE_MMS_CC));
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        *img_buff_p = (PU8) GetImage((U16) (IMG_ID_WRITE_MMS_BCC));
    }
    else
    {
        *img_buff_p = NULL;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_address_list_highlight_hdlr
 * DESCRIPTION
 *  higjh;light hdlr  of address_p list screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_address_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_hilite_address_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_back_to_write_mms
 * DESCRIPTION
 *  go back to main write mms screeen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_back_to_write_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_edit
 * DESCRIPTION
 *  highligh hdlr of edio option in addresses options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_address_option_index = E_EDIT_ADDRESS;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_message_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_message_edit, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_edit
 * DESCRIPTION
 *  Entry fn for edit address_p option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_address_list_struct *address_node_p;
    U8 temp = 0;
    U8 is_email_address = 0;
    PS8 ch_p;
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        address_node_p = g_jmms_context->to_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        address_node_p = g_jmms_context->cc_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        address_node_p = g_jmms_context->bcc_address_p;
    }
    else
    {
        return;
    }

    while (temp != g_jmms_context->g_hilite_address_item)
    {
        address_node_p = address_node_p->next_p;
        temp++;
    }

    temp = 0;
    /* Dilip Start 2nd Sept 06 */
    /* Encoding length is removed as it was increasing the strlen by Encoding length so 'ch' was reading junk value */
    len = mmi_ucs2strlen(address_node_p->address_p);
    /* Dilip End 2nd Sept 06 */
    ch_p = address_node_p->address_p;

    while (temp < len)
    {
        if ((*ch_p) == '@')
        {
            is_email_address = 1;
            break;
        }
        else
        {
            temp++;
            ch_p = address_node_p->address_p + temp * ENCODING_LENGTH;  /* sachin */
        }
    }

    if (is_email_address == 1)
    {
        memset((g_jmms_context->g_jmms_add_email_buffer), 0x00, (MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) (g_jmms_context->g_jmms_add_email_buffer), address_node_p->address_p);
        mmi_jmms_entry_write_message_add_email_screen();

    }
    else
    {
        memset(g_jmms_context->g_jmms_add_number_buffer, 0x00, (MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) (g_jmms_context->g_jmms_add_number_buffer), address_node_p->address_p);
        mmi_jmms_entry_write_message_add_number_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_replace_address_in_addresse_list
 * DESCRIPTION
 *  Replaces the curent address_p selected with input address_p
 * PARAMETERS
 *  address_p       [IN]        (cotains the adress input)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_jmms_replace_address_in_addresse_list(S8 *address_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_address_list_struct *address_node_p;
    U8 temp = 0;
    S8 *temp_address_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        address_node_p = g_jmms_context->to_address_p;;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        address_node_p = g_jmms_context->cc_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        address_node_p = g_jmms_context->bcc_address_p;
    }
    else
    {
        return 1;
    }

    while (temp != g_jmms_context->g_hilite_address_item)
    {
        address_node_p = address_node_p->next_p;
        temp++;
    }

    temp_address_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(address_p) + 1) * ENCODING_LENGTH, sizeof(S8));
    if (temp_address_p == NULL)
    {
        return 1;   /* /memory fail */
    }

    jdd_MemFree(address_node_p->address_p);
    address_node_p->address_p = NULL;

    address_node_p->address_p = temp_address_p;

    mmi_ucs2cpy(address_node_p->address_p, address_p);

    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_delete
 * DESCRIPTION
 *  Handles the delete of slelected address_p
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = 0;
    mmi_jmms_address_list_struct *address_node_p, *address_node1_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        address_node_p = g_jmms_context->to_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        address_node_p = g_jmms_context->cc_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        address_node_p = g_jmms_context->bcc_address_p;
    }
    else
    {
        return;
    }

    address_node1_p = address_node_p;
    while (temp != g_jmms_context->g_hilite_address_item)
    {
        address_node1_p = address_node_p;
        address_node_p = address_node_p->next_p;
        temp++;
    }

    if (g_jmms_context->g_hilite_address_item == 0)
    {
        address_node1_p = address_node_p->next_p;
    }
    else
    {
        address_node1_p->next_p = address_node_p->next_p;
    }

    jdd_MemFree(address_node_p->address_p);
    jdd_MemFree(address_node_p);
    address_node_p = NULL;

    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

    (g_jmms_context->num_total_addresses)--;

    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        (g_jmms_context->num_to_addresses)--;

        if (g_jmms_context->g_hilite_address_item == 0)
        {
            g_jmms_context->to_address_p = address_node1_p;
        }

        if (g_jmms_context->num_to_addresses == 0)
        {
            GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
            return;
        }
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        (g_jmms_context->num_cc_addresses)--;

        if (g_jmms_context->g_hilite_address_item == 0)
        {
            g_jmms_context->cc_address_p = address_node1_p;
        }

        if (g_jmms_context->num_cc_addresses == 0)
        {
            GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
            return;
        }
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        (g_jmms_context->num_bcc_addresses)--;

        if (g_jmms_context->g_hilite_address_item == 0)
        {
            g_jmms_context->bcc_address_p = address_node1_p;
        }

        if (g_jmms_context->num_bcc_addresses == 0)
        {
            GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
            return;
        }
    }

    /* retun back to address_p list with elected item deleted */
    if (g_jmms_context->g_hilite_address_item == 0)
    {
        g_jmms_context->g_hilite_address_item = 0;
    }
    else
    {
        g_jmms_context->g_hilite_address_item--;
    }

    g_jmms_context->g_address_list_right_soft_key = STR_GLOBAL_DONE;
    GoBackToHistory(SCR_ID_JMMS_ADDRESS_LIST);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_delete_all
 * DESCRIPTION
 *  Handles the delete all option for addresse list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_delete_all(void)
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
        get_string(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_entry_write_message_delete_all_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message_delete_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_address_list_struct *address_node_p, *address_node1_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        address_node_p = g_jmms_context->to_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        address_node_p = g_jmms_context->cc_address_p;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        address_node_p = g_jmms_context->bcc_address_p;
    }
    else
    {
        return;
    }

    do
    {
        address_node1_p = address_node_p->next_p;
        jdd_MemFree(address_node_p->address_p);
        jdd_MemFree(address_node_p);
        address_node_p = address_node1_p;
    } while (address_node_p != NULL);

    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        g_jmms_context->num_total_addresses = g_jmms_context->num_total_addresses - g_jmms_context->num_to_addresses;
        g_jmms_context->num_to_addresses = 0;
        g_jmms_context->to_address_p = NULL;

    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        g_jmms_context->num_total_addresses = g_jmms_context->num_total_addresses - g_jmms_context->num_cc_addresses;
        g_jmms_context->num_cc_addresses = 0;
        g_jmms_context->cc_address_p = NULL;

    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        g_jmms_context->num_total_addresses = g_jmms_context->num_total_addresses - g_jmms_context->num_bcc_addresses;
        g_jmms_context->num_bcc_addresses = 0;
        g_jmms_context->bcc_address_p = NULL;
    }

    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_done_write_mms
 * DESCRIPTION
 *  Handler of Done RSK on main write mms screen.Display a new screen of done options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_done_write_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer_p;   /* Buffer holding history data */
    U16 n_str_item_list[MAX_SUB_MENUS];
    U16 n_num_of_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_WRITE_MMS_DONE_OPTIONS, NULL, mmi_jmms_done_write_mms, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_WRITE_MMS_DONE_OPTIONS);

    SetParentHandler(MENU_ID_JMMS_WRITE_MMS_DONE_OPTIONS);

    if (mmi_jmms_is_rc_info_present() == E_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SAVE_TO_DRAFTS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_ONLY);
    }

    if (g_jmms_context->num_total_addresses == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_ONLY);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_ONLY);
    }

    if ((g_jmms_context->num_total_addresses == 0) || (mmi_jmms_is_rc_info_present() == E_TRUE))
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SAVE_AND_SEND);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SAVE_AND_SEND);
    }

    if (g_jmms_context->num_total_addresses == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_OPTIONS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_WRITE_MMS_DONE_SEND_OPTIONS);
    }

    n_num_of_item = GetNumOfChild_Ext(MENU_ID_JMMS_WRITE_MMS_DONE_OPTIONS);

    GetSequenceStringIds_Ext(MENU_ID_JMMS_WRITE_MMS_DONE_OPTIONS, n_str_item_list);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_num_of_item,
        n_str_item_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_done_send_only
 * DESCRIPTION
 *  Highlight hdlr of send only option  in done options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_done_send_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_write_mms_done_send_only, KEY_EVENT_UP);
    /* MAUI_00018453 Start */
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* MAUI_00018453 End */
    SetKeyHandler(mmi_jmms_pre_entry_write_mms_done_send_only, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_done_save_and_send
 * DESCRIPTION
 *  Highlight hdlr of save and send option  in done options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_done_save_and_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_mms_done_save_and_send, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_mms_done_save_and_send, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_done_save_to_drafts
 * DESCRIPTION
 *  Highlight hdlr of save to drafts option  in done options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_done_save_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_mms_done_save_to_drafts, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_mms_done_save_to_drafts, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_done_send_options
 * DESCRIPTION
 *  Highlight hdlr of send option  in done options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_done_send_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_mms_done_send_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_write_mms_done_send_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_mms_done_send_options, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_write_mms_done_exit
 * DESCRIPTION
 *  Highlight hdlr of exit option  in done options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_write_mms_done_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_jmms_entry_write_mms_done_exit, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_write_mms_done_exit, KEY_WAP, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_go_back_from_rc_screen
 * DESCRIPTION
 *  pre entry screen before sending the created mms without saving it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_go_back_from_rc_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_write_mms_done_send_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_write_mms_done_send_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Added by deepali for reply charging. */

    if (mmi_jmms_is_rc_info_present() == E_TRUE)
    {
        if (mmi_jmms_check_valid_rc_type() == E_FALSE)
        {
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_ID_JMMS_RC_INVALID_MEDIA),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_jmms_clear_rc_info_before_send, KEY_EVENT_UP);

            SetRightSoftkeyFunction(mmi_jmms_go_back_from_rc_screen, KEY_EVENT_UP);
            return;
        }
        if (mmi_jmms_check_valid_rc_size_limits() == E_FALSE)
        {
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_ID_JMMS_RC_INVALID_SIZE),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_jmms_clear_rc_info_before_send, KEY_EVENT_UP);

            SetRightSoftkeyFunction(mmi_jmms_go_back_from_rc_screen, KEY_EVENT_UP);
            return;
        }
        if (mmi_jmms_check_valid_rc_send_time() == E_FALSE)
        {
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_ID_JMMS_RC_INVALID_TIME),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            SetLeftSoftkeyFunction(mmi_jmms_clear_rc_info_before_send, KEY_EVENT_UP);

            SetRightSoftkeyFunction(mmi_jmms_go_back_from_rc_screen, KEY_EVENT_UP);
            return;
        }
    }

    mmi_jmms_entry_write_mms_done_send_only();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_clear_rc_info_before_send
 * DESCRIPTION
 *  send the created mms without saving it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_clear_rc_info_before_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->rc_info != NULL)
    {
        if (g_jmms_context->rc_info->pReplyMsgID != NULL)
        {
            jdd_MemFree(g_jmms_context->rc_info->pReplyMsgID);
        }
        jdd_MemFree(g_jmms_context->rc_info);
        g_jmms_context->rc_info = NULL;
    }
    mmi_jmms_entry_write_mms_done_send_only();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_send_only
 * DESCRIPTION
 *  send the created mms without saving it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_send_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_count = 0;
    U32 mms_size = 0;
    ECreationMode create_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_mode = mmi_jmms_compose_settings_creation_mode();
    if (create_mode == E_CREATION_MODE_RESTRICTED)
    {
        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
        if (mms_size > MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MODE_MAX_MSG_SIZE_REACHED_NEED_DELETE),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                WARNING_TONE);
            DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
            return;
        }
        if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
        {
            mmi_jmms_edit_content_restricted_mode_query();
            return;
        }
    }
    g_jmms_context->save_mms = MMI_FALSE;

    /* /don't change the order of following 2 steps */
    g_jmms_context->last_scr_id = SCR_ID_JMMS_WRITE_MMS;
    mmi_jmms_free_message_header();
    /******************************************************************************
        This part of the function is modified to add the blank slide into the MMS.

        Modified By          : Raj Kumar Gupta
        Date of Modification : July 25, 2006
    *****************************************************************************/
    if (mmi_jmms_pre_check_for_auto_signature() == E_FALSE)
    {
        mmi_jmms_display_auto_signature_error_popup();
        return;
    }
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    if (page_count == 0 && mmi_jmms_compose_settings_auto_sign_status() == E_OFF)
    {
        JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

        DisplayPopupCallBack(
            (U8*) GetString(STR_ID_JMMS_ADD_BLANK_SLIDE),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            (U8) WARNING_TONE,
            mmi_jmms_add_blank_slide_before_send_callback);
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
                mmi_ucs2cpy(
                    (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) GetString(STR_ID_JMMS_BLANK_SLIDE_STRING));
                if (!
                    (create_mode == E_CREATION_MODE_RESTRICTED &&
                     mms_size +
                     jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.
                               edit_content_buffer) * sizeof(JC_CHAR) >
                     MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE))
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
    }
    else
    {
    #ifdef MMI_ON_HARDWARE_P
        U32 mms_size = 0;

        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
        /* To check if Size is zero but auto signature is ON , So, in this condition not to include This is a Blank MMS string */
        if (mms_size == 0 && (g_jmms_context->nvram_compose_settings.auto_signature != 1))
        {
            stFontAttribute text_font;

            /* sandeep start to fix MAUI_00227892 */
            DisplayPopupCallBack(
                (U8*) GetString(STR_ID_JMMS_ADD_DEFAULT_CHARACTERS),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                (U8) WARNING_TONE,
                mmi_jmms_add_blank_slide_before_send_callback);
            /* sandeep end to fix MAUI_00227892 */

            text_font.italic = 0;
            text_font.bold = 0;
            text_font.size = MEDIUM_FONT;
            page_count = 1;
            if (is_test_sim() == MMI_FALSE)
            {
                mmi_ucs2cpy(
                    (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) GetString(STR_ID_JMMS_BLANK_SLIDE_STRING));
                g_jmms_context->disable_warning_popup = 1;
                mmi_jmms_compose_add_text((U8) (page_count), &(text_font), g_jmms_color_RGB_list[COLOR_BLACK], 1);
                g_jmms_context->disable_warning_popup = 0;
            }
        }
        else
    #endif /* MMI_ON_HARDWARE_P */ 
        {
            mmi_jmms_add_blank_slide_before_send_callback();
        }
    }
    /*****************************************************************************
        End of modification to insert the blank slide into blank MMS.
    *****************************************************************************/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_save_and_send
 * DESCRIPTION
 *  save and send the MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_save_and_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_count = 0;
    U32 mms_size;
    ECreationMode create_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_mode = mmi_jmms_compose_settings_creation_mode();
    if (create_mode == E_CREATION_MODE_RESTRICTED)
    {
        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
        if (mms_size > MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MODE_MAX_MSG_SIZE_REACHED_NEED_DELETE),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                WARNING_TONE);
            DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
            return;
        }
        if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
        {
            mmi_jmms_edit_content_restricted_mode_query();
            return;
        }
    }
    g_jmms_context->save_mms = MMI_TRUE;
    /* /don't change the order of following 2 steps */
    g_jmms_context->last_scr_id = SCR_ID_JMMS_WRITE_MMS;
    mmi_jmms_free_message_header();
    /******************************************************************************
        This part of the function is modified to add the blank slide into the MMS.

        Modified By          : Raj Kumar Gupta
        Date of Modification : July 25, 2006
    *****************************************************************************/
    if (mmi_jmms_pre_check_for_auto_signature() == E_FALSE)
    {
        mmi_jmms_display_auto_signature_error_popup();
        return;
    }
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    if (page_count == 0 && mmi_jmms_compose_settings_auto_sign_status() == E_OFF)
    {
        JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

        DisplayPopupCallBack(
            (U8*) GetString(STR_ID_JMMS_ADD_BLANK_SLIDE),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            (U8) WARNING_TONE,
            mmi_jmms_add_blank_slide_before_send_callback);
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
                mmi_ucs2cpy(
                    (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) GetString(STR_ID_JMMS_BLANK_SLIDE_STRING));
                if (!
                    (create_mode == E_CREATION_MODE_RESTRICTED &&
                     (mms_size +
                      jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.
                                edit_content_buffer) * sizeof(JC_CHAR)) >
                     MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE))
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
    }
    else
    {
    #ifdef MMI_ON_HARDWARE_P
        U32 mms_size = 0;

        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
        /* To check if Size is zero but auto signature is ON , So, in this condition not to include This is a Blank MMS string */
        if (mms_size == 0 && g_jmms_context->nvram_compose_settings.auto_signature != 1)
        {
            stFontAttribute text_font;

            /* sandeep start to fix MAUI_00227892 */
            DisplayPopupCallBack(
                (U8*) GetString(STR_ID_JMMS_ADD_DEFAULT_CHARACTERS),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                (U8) WARNING_TONE,
                mmi_jmms_add_blank_slide_before_send_callback);
            /* sandeep end to fix MAUI_00227892 */

            text_font.italic = 0;
            text_font.bold = 0;
            text_font.size = MEDIUM_FONT;
            page_count = 1;

            if (is_test_sim() == MMI_FALSE)
            {
                mmi_ucs2cpy(
                    (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) GetString(STR_ID_JMMS_BLANK_SLIDE_STRING));
                g_jmms_context->disable_warning_popup = 1;
                mmi_jmms_compose_add_text((U8) (page_count), &(text_font), g_jmms_color_RGB_list[COLOR_BLACK], 1);
                g_jmms_context->disable_warning_popup = 0;
            }

        }
        else
    #endif /* MMI_ON_HARDWARE_P */ 
        {
            mmi_jmms_add_blank_slide_before_send_callback();
        }
    }
    /*****************************************************************************
        End of modification to insert the blank slide into blank MMS.
    *****************************************************************************/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_blank_slide_before_send_callback
 * DESCRIPTION
 *  To add the blank slide before send.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_add_blank_slide_before_send_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_use_local_send_setings == 1)
    {
        ret_code = mmi_jmms_create_and_send_new_mms(E_USE_LOCAL_SETTINGS, g_jmms_context, MMI_TRUE);
    }
    else
    {
        ret_code = mmi_jmms_create_and_send_new_mms(E_USE_NVRAM_SETTINGS, g_jmms_context, MMI_TRUE);
    }

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_save_to_drafts
 * DESCRIPTION
 *  save thre created mms to drafts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_save_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mms_size;
    ECreationMode create_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_mode = mmi_jmms_compose_settings_creation_mode();
    if (create_mode == E_CREATION_MODE_RESTRICTED)
    {
        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);
        if (mms_size > MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MODE_MAX_MSG_SIZE_REACHED_NEED_DELETE),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                WARNING_TONE);
            DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
            return;
        }
        if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
        {
            mmi_jmms_edit_content_restricted_mode_query();
            return;
        }
    }
    if (g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS)    /* it means user came here from drafts->edit MMS */
        /* /ask confirmation to replace original or new copy */
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_JMMS_REPLACE_MMS),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_jmms_entry_write_mms_done_replace_save_to_drafts, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_jmms_entry_write_mms_done_new_save_to_drafts, KEY_EVENT_UP);

        /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */
    }
    else
    {
        /* /save new mms to dratfs */
        mmi_jmms_entry_write_mms_done_new_save_to_drafts();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_replace_save_to_drafts
 * DESCRIPTION
 *  replace the mms edited with original copy (possible only for drafts)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_replace_save_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    CONTENT_DATA content = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->last_scr_id = SCR_ID_JMMS_WRITE_MMS;

    mmi_jmms_free_message_header();

    content.bIsStream = E_TRUE;
    ret_code = mmi_jmms_get_message(
                "Drafts",
                &content,
                g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index);

    if (ret_code != JC_OK)
    {
        mmi_jmms_error_handler(ret_code);
        return;
    }
    else
    {
        g_jmms_context->orig_file_name_replace_mms = jdi_UtilsTcsDup(content.pFileName);
        if (g_jmms_context->orig_file_name_replace_mms == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            mmi_jmms_error_handler(ret_code);
            return;
        }

    }

    if (g_jmms_context->g_use_local_send_setings == 1)
    {
        ret_code = mmi_jmms_create_and_send_new_mms(E_USE_LOCAL_SETTINGS, g_jmms_context, MMI_FALSE);
    }
    else
    {
        ret_code = mmi_jmms_create_and_send_new_mms(E_USE_NVRAM_SETTINGS, g_jmms_context, MMI_FALSE);

    }

    if (ret_code == JC_OK)
    {
        /* /store update the mms */
        mmi_jmms_entry_msg_saving_screen();
        mmi_jmms_save_mms(
            "Drafts",
            g_jmms_context->msg_handle,
            MMI_TRUE,
            (JC_UINT32) (g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index),
            mmi_jmms_replace_save_to_drafts_async_callback);

        return;
    }

    if (GetActiveScreenId() != SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN)
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_LIMIT_REACH;

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_FULL_REACH;
        }
        else
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_ERROR_MMS_SAVING;
        }
    #ifdef __MMI_UNIFIED_MESSAGE__
        HistoryReplace(SCR_ID_UM_DRAFT, SCR_ID_UM_DRAFT, mmi_um_jmms_pre_entry_draft);
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        HistoryReplace(
            SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN,
            SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN,
            mmi_jmms_entry_msg_saving_status_screen);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
    else
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_LIMIT_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_FULL_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ERROR_MMS_SAVING),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }

        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_replace_save_to_drafts_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_replace_save_to_drafts_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret_code != JC_OK)
    {
        goto END;
    }

    mmi_jmms_deinit_mms_context(g_jmms_context);

    if (GetActiveScreenId() != SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN)
    {
        U16 scr_id;

        g_jmms_context->progress_screen_title = STR_ID_JMMS_SAVE_SUCCESS;
        GetPreviousScrnIdOf(SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN, &scr_id);
        HistoryReplace(
            SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN,
            SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN,
            mmi_jmms_entry_msg_saving_status_screen);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteFromScrUptoScr(scr_id, SCR_ID_UM_DRAFT);
    #else 
        DeleteFromScrUptoScr(scr_id, SCR_ID_JMMS_DRAFTS);
    #endif 
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_SAVE, 1, JMMS_POPUP_TIME, SAVE_TONE);
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteUptoScrID(SCR_ID_UM_DRAFT);
    #else 
        DeleteUptoScrID(SCR_ID_JMMS_DRAFTS);
    #endif 
    }

    /* Added by Deepali, as While replacing we are not able to delete the current MMS file. 
       As to implement virtual file we need to open the file. */

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        jdd_FSInitialize(&g_jmms_context->jmms_fs_handle);
    }

    jdd_FSDelete(g_jmms_context->jmms_fs_handle, g_jmms_context->orig_file_name_replace_mms);

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    if (g_jmms_context->orig_file_name_replace_mms)
    {
        jdd_MemFree(g_jmms_context->orig_file_name_replace_mms);
        g_jmms_context->orig_file_name_replace_mms = NULL;
    }
#ifdef __MMI_UNIFIED_MESSAGE__
    HistoryReplace(SCR_ID_UM_DRAFT, SCR_ID_UM_DRAFT, mmi_um_jmms_pre_entry_draft);
#else 
    HistoryReplace(SCR_ID_JMMS_DRAFTS, SCR_ID_JMMS_DRAFTS, mmi_jmms_entry_drafts);
#endif 

/********************************/
    return;

  END:

    if (g_jmms_context->orig_file_name_replace_mms)
    {
        jdd_MemFree(g_jmms_context->orig_file_name_replace_mms);
        g_jmms_context->orig_file_name_replace_mms = NULL;
    }

    if (GetActiveScreenId() != SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN)
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_LIMIT_REACH;

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_FULL_REACH;
        }
        else
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_ERROR_MMS_SAVING;
        }
        HistoryReplace(
            SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN,
            SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN,
            mmi_jmms_entry_msg_saving_status_screen);
    }
    else
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_LIMIT_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_FULL_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ERROR_MMS_SAVING),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }

        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_new_save_to_drafts
 * DESCRIPTION
 *  save the mms to dratfs folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_new_save_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->last_scr_id = SCR_ID_JMMS_WRITE_MMS;

    mmi_jmms_free_message_header();

    if (g_jmms_context->g_use_local_send_setings == 1)
    {
        ret_code = mmi_jmms_create_and_send_new_mms(E_USE_LOCAL_SETTINGS, g_jmms_context, MMI_FALSE);
    }
    else
    {
        ret_code = mmi_jmms_create_and_send_new_mms(E_USE_NVRAM_SETTINGS, g_jmms_context, MMI_FALSE);
    }

    if (ret_code == JC_OK)
    {
        /* /save new mms */
        if (g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS)
        {
            g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
        }
        mmi_jmms_entry_msg_saving_screen();
        mmi_jmms_save_mms(
            "Drafts",
            g_jmms_context->msg_handle,
            MMI_FALSE,
            0,
            mmi_jmms_new_save_to_drafts_async_callback);
        return;
    }

    if (GetActiveScreenId() != SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN)
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_LIMIT_REACH;

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_FULL_REACH;
        }
        else
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_ERROR_MMS_SAVING;
        }
        HistoryReplace(
            SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN,
            SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN,
            mmi_jmms_entry_msg_saving_status_screen);
    }
    else
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_LIMIT_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_FULL_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ERROR_MMS_SAVING),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }

        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_new_save_to_drafts_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_new_save_to_drafts_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    U8 number = 0;
    JC_RETCODE ret_code1 = JC_OK;
    U16 scr_id = 0;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret_code != JC_OK)
    {
        goto END;
    }

    mmi_jmms_deinit_mms_context(g_jmms_context);

    if (GetActiveScreenId() != SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN)
    {
        U16 scr_id;

        g_jmms_context->progress_screen_title = STR_ID_JMMS_SAVE_SUCCESS;
        GetPreviousScrnIdOf(SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN, &scr_id);
        HistoryReplace(
            SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN,
            SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN,
            mmi_jmms_entry_msg_saving_status_screen);
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (IsScreenPresent(SCR_ID_JMMS_OUTBOX_OPTIONS))
        {
            number = g_jmms_context->store_context->num_msg_in_curr_folder;
            ret_code1 = mmi_jmms_delete_message(MMI_JMMS_OUTBOX, (number - g_jmms_context->curr_scr_hilited_index));
            HistoryReplace(SCR_ID_UM_UNSENT, SCR_ID_UM_UNSENT, mmi_um_pre_entry_unsent);
            if (number <= 1)    /* /now folder will empty */
            {
                DeleteFromScrUptoScr(scr_id, SCR_ID_UM_MAIN);
            }
            else
            {
                DeleteFromScrUptoScr(scr_id, SCR_ID_UM_UNSENT);
            }
        }
        else if (IsScreenPresent(SCR_ID_JMMS_PREVIEW))
        {
            DeleteScreenFromToNnodes(scr_id, 4);
        }
        else if (!IsScreenPresent(SCR_ID_UM_MAIN))
        {
            DeleteScreenFromToNnodes(scr_id, 2);
        }
        /* Sandeep Start 14 Nov 2006 for bug number PMT005873 PMT005873 */
        else if (IsScreenPresent(SCR_ID_UM_DRAFT))
        {
            DeleteFromScrUptoScr(scr_id, SCR_ID_UM_DRAFT);
            HistoryReplace(SCR_ID_UM_DRAFT, SCR_ID_UM_DRAFT, mmi_um_jmms_pre_entry_draft);
        }
        /* Sandeep End 14 Nov 2006 for bug number PMT005873 */
        else
        {
            DeleteScreenFromToNnodes(scr_id, 3);
        }
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        if (IsScreenPresent(SCR_ID_JMMS_DRAFTS))
        {
            DeleteFromScrUptoScr(scr_id, SCR_ID_JMMS_DRAFTS);
            HistoryReplace(SCR_ID_JMMS_DRAFTS, SCR_ID_JMMS_DRAFTS, mmi_jmms_entry_drafts);
        }
        else
        {
            DeleteScreenFromToNnodes(scr_id, 2);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_SAVE, 1, JMMS_POPUP_TIME, SAVE_TONE);
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (IsScreenPresent(SCR_ID_JMMS_OUTBOX_OPTIONS))
        {
            number = g_jmms_context->store_context->num_msg_in_curr_folder;
            ret_code1 = mmi_jmms_delete_message(MMI_JMMS_OUTBOX, (number - g_jmms_context->curr_scr_hilited_index));
            HistoryReplace(SCR_ID_UM_UNSENT, SCR_ID_UM_UNSENT, mmi_um_pre_entry_unsent);
            if (number <= 1)    /* /now folder will empty */
            {
                DeleteFromScrUptoScr(SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN, SCR_ID_UM_MAIN);
            }
            else
            {
                DeleteFromScrUptoScr(SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN, SCR_ID_UM_UNSENT);
            }
        }
        else if (IsScreenPresent(SCR_ID_JMMS_PREVIEW))
        {
            DeleteNHistory(5);
        }
        else if (!IsScreenPresent(SCR_ID_UM_MAIN))
        {
            DeleteScreenFromToNnodes(SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN, 3);
        }
        /* Sandeep Start 14 Nov 2006 for bug number PMT005873 PMT005873 */
        else if (IsScreenPresent(SCR_ID_UM_DRAFT))
        {
            DeleteUptoScrID(SCR_ID_UM_DRAFT);
        }
        /* Sandeep End 14 Nov 2006 for bug number PMT005873 */
        else
        {
            DeleteNHistory(4);
        }
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        if (IsScreenPresent(SCR_ID_JMMS_DRAFTS))
        {
            DeleteUptoScrID(SCR_ID_JMMS_DRAFTS);
        }
        else
        {
            DeleteNHistory(3);
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }

    return;

  END:

    if (GetActiveScreenId() != SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN)
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_LIMIT_REACH;

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_MEMORY_FULL_REACH;
        }
        else
        {
            g_jmms_context->progress_screen_title = STR_ID_JMMS_ERROR_MMS_SAVING;
        }
        HistoryReplace(
            SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN,
            SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN,
            mmi_jmms_entry_msg_saving_status_screen);
    }
    else
    {
        if (ret_code == E_MEMORY_FULL_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_LIMIT_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);

        }
        else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_MEMORY_FULL_REACH),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_ERROR_MMS_SAVING),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                (U8) ERROR_TONE);
        }
    #ifdef __MMI_UNIFIED_MESSAGE__
        scr_id = mmi_um_get_curr_folder_name();
        if (scr_id)
        {
            DeleteUptoScrID(scr_id);
        }
        else
        {
            DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
        }
    #else /* __MMI_UNIFIED_MESSAGE__ */ 
        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_msg_saving_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_msg_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_MSG_SAVING_PROGRESS_SCREEN, NULL, mmi_jmms_entry_msg_saving_screen, NULL);

    ShowCategory8Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        STR_ID_JMMS_SAVING_MMS,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetRightSoftkeyFunction(mmi_jmms_abort_saving_progress, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_abort_saving_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_abort_saving_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(JMMS_ASYNC_SAVE_TIMER);

    if (g_jmms_context->save_content_p != NULL)
    {
        if (g_jmms_context->save_content_p->bIsStream == E_FALSE)
        {
            jdd_MemFree(g_jmms_context->save_content_p->pBuffer);
            g_jmms_context->save_content_p->pBuffer = NULL;
        }
        if (g_jmms_context->save_content_p->pStream != NULL)
        {
            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                jdd_FSInitialize(&g_jmms_context->jmms_fs_handle);
            }

            jdd_FSDelete(g_jmms_context->jmms_fs_handle, g_jmms_context->save_content_p->pStream);

            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }

            jdd_MemFree(g_jmms_context->save_content_p->pStream);
        }
        jdd_MemFree(g_jmms_context->save_content_p);
        g_jmms_context->save_content_p = NULL;
    }

    if (g_jmms_context->async_save_context.params != NULL)
    {
        jdd_MemFree(g_jmms_context->async_save_context.params);
        g_jmms_context->async_save_context.params = NULL;
    }

    DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_msg_saving_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_msg_saving_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_SAVE_MSG_STATUS_SCREEN, NULL, mmi_jmms_entry_msg_saving_status_screen, NULL);

    ShowCategory2Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_jmms_context->progress_screen_title,
        NULL);

    SetRightSoftkeyFunction(mmi_jmms_back_from_save_msg_status_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_back_from_save_msg_status_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_back_from_save_msg_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->progress_screen_title == STR_ID_JMMS_SAVE_SUCCESS)
    {
        GoBackHistory();
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_send_options
 * DESCRIPTION
 *  This fn fills the sending settings struct and opens the sending settings screen as write in message settings file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_send_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MAUI_00227929 Start */

    g_jmms_context->jmms_inline_items.sending_items_list.delivery_report =
        (S32) g_jmms_context->sending_settings.delivery_report;

    g_jmms_context->jmms_inline_items.sending_items_list.hide_sender =
        (S32) g_jmms_context->sending_settings.hide_sender;
    g_jmms_context->jmms_inline_items.sending_items_list.priority = (S32) g_jmms_context->sending_settings.priority;
    g_jmms_context->jmms_inline_items.sending_items_list.read_report =
        (S32) g_jmms_context->sending_settings.read_report;

    if (g_jmms_context->sending_settings.reply_charging != NULL)
    {
        g_jmms_context->jmms_inline_items.sending_items_list.reply_charging = (S32) E_ON;
        g_jmms_context->jmms_inline_items.sending_items_list.request_type =
            (S32) (g_jmms_context->sending_settings.request_type);
        strcpy(
            (S8*) g_jmms_context->jmms_inline_items.sending_items_list.deadline_for_reply_buffer,
            (S8*) g_jmms_context->sending_settings.deadline_for_reply_buffer);
        strcpy(
            (S8*) g_jmms_context->jmms_inline_items.sending_items_list.reply_msg_size_buffer,
            (S8*) g_jmms_context->sending_settings.reply_msg_size_buffer);

    }
    else
    {
        g_jmms_context->jmms_inline_items.sending_items_list.reply_charging = (S32) E_OFF;
    }

    g_jmms_context->jmms_inline_items.sending_items_list.delivery_time =
        (S32) g_jmms_context->sending_settings.delivery_time;
    g_jmms_context->jmms_inline_items.sending_items_list.validity_period =
        (S32) g_jmms_context->sending_settings.validity_period;

    /* MAUI_00227929 End */
    mmi_jmms_check_sending_settings_control(2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_mms_done_exit
 * DESCRIPTION
 *  Handles the eit press on done options screen on write mms screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_mms_done_exit(void)
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
        get_string(STR_ID_JMMS_SAVE_TO_DRAFTS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_entry_write_mms_done_save_to_drafts, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_jmms_done_exit_confirm_screen, KEY_EVENT_UP);

    /* SetKeyHandler(mmi_jmms_free_addresses_list_on_end, KEY_END, KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_done_exit_confirm_screen
 * DESCRIPTION
 *  Free the address_p lists and retruns back to main mms screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_done_exit_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    U16 scrId = 0;
#endif 
    mmi_jmms_deinit_mms_context(g_jmms_context);
#ifdef __MMI_UNIFIED_MESSAGE__
    scrId = mmi_um_get_curr_folder_name();
    if (scrId)
    {
        GoBackToHistory(scrId);
    }
    else if (IsScreenPresent(SCR_FMGR_EXPLORER))
    {
        GoBackToHistory(SCR_FMGR_EXPLORER);
    }
    else if (IsScreenPresent(SCR_ID_JMMS_TEMPLATES))
    {
        GoBackToHistory(SCR_ID_JMMS_TEMPLATES);
    }
    /* Dilip Start 26 Aug 2006 to solve the control coming back to idle screen instead of proper screen */
    else if (IsScreenPresent(SCR_ID_UM_MAIN))
    {
        GoBackToHistory(SCR_ID_UM_MAIN);
    }
    else
    {
        GoBacknHistory(2);
    }
    /* Dilip End 26 Aug 2006 to solve the control coming back to idle screen instead of proper screen */

#else /* __MMI_UNIFIED_MESSAGE__ */ 
    GoBacknHistory(2);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_restricted_mode_query
 * DESCRIPTION
 *  Query screen for Edit content when restricted mode is set.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_restricted_mode_query(void)
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
        get_string(STR_ID_JMMS_EDIT_CONTENT_QUERY_RESTRICTED_MODE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_jmms_proceed_edit_content_after_media_removal, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_proceed_edit_content_after_media_removal
 * DESCRIPTION
 *  Remove invalid media and proceed in Edit content.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_proceed_edit_content_after_media_removal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_jmms_jdi_deinitview(g_jmms_context->msg_handle);
#endif 
    mmi_jmms_jdi_fit_content_class(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS);
    mmi_jmms_entry_write_message_screen();
}

#else /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  update_mms_email_from_phonebook
 * DESCRIPTION
 *  This fn copy the email selected from phonebook to adderess editor(email) screen
 * PARAMETERS
 *  email_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void update_mms_email_from_phonebook(S8 *email_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Wrong Call, Dummy Function */
    ASSERT(0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  update_mms_number_from_phonebook
 * DESCRIPTION
 *  This fn copy the number selected from phonebook to adderess editor(number) screen
 * PARAMETERS
 *  number_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void update_mms_number_from_phonebook(S8 *number_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Wrong Call, Dummy Function */
    ASSERT(0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_write_message
 * DESCRIPTION
 *  This function is pre entry function for writing a new MMS
 *  new MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_write_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Wrong Call, Dummy Function */
    ASSERT(0);
    return;
}

#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_init_msg_context_struct
 * DESCRIPTION
 *  This function is for initlizing the global context structure for writing a
 *  new MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_init_msg_context_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->msg_handle != NULL)
    {
        mmi_jmms_deinit_mms_context(g_jmms_context);
    }
    else
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        if (g_jmms_context->message_to_fw == MMI_TRUE)
        {
            mmi_jmms_deinit_mms_context(g_jmms_context);
        }
        else
        {
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
            mmi_jmms_free_addresses_list();
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        #ifdef __MMI_UNIFIED_MESSAGE__
        }
        #endif 
    }
    g_jmms_context->curr_scr_hilited_index = 0;

    g_jmms_context->curr_focused_media_type = 0;
    g_jmms_context->num_attachments = 0;
    g_jmms_context->sent_retry_counter = 0;

    memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_BACK;

    mmi_jmms_parse_continue_stop_timer();
    StopTimer(JMMS_ASYNC_SAVE_TIMER);
    StopTimer(JMMS_ASYNC_SEND_TIMER);
    mmi_jmms_end_comm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_duplicate_address
 * DESCRIPTION
 *  chekcs the duplicate address_p input
 * PARAMETERS
 *  address_p                   [IN]        
 *  ignore_address_field        [IN]        
 *  ignore_address_id           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
/* check duplicacy of input address_p */
MMI_BOOL mmi_jmms_check_duplicate_address(
            U8 *address_p,
            jmms_write_mms_addresses_options ignore_address_field,
            S32 ignore_address_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 len_diff = 0, add_len_diff = 0;
    mmi_jmms_address_list_struct *temp_p;
    MMI_BOOL found = MMI_FALSE;
    S8 tmp_str[4], tmp_str1[4] = { '0', 0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) tmp_str, (S8*) "+");
    temp_p = g_jmms_context->to_address_p;
    if (temp_p != NULL)
    {
        for (i = 0; i < g_jmms_context->num_to_addresses; i++)
        {
            if (ignore_address_field == E_TO_ADDRESSES)
                if (i == ignore_address_id) /* Amit */
                {                           /* Increase temp_p to point to next_p address_p feild */
                    temp_p = temp_p->next_p;
                    len_diff = 0;
                    add_len_diff = 0;       /* End */
                    continue;
                }
            if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str) == MMI_TRUE) ||
                (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str) == MMI_TRUE))
            {
                U16 num_len = (mmi_ucs2strlen((S8*) address_p)) * ENCODING_LENGTH;
                U16 tmp_len = (mmi_ucs2strlen((S8*) temp_p->address_p)) * ENCODING_LENGTH;

                if ((tmp_len > num_len) && (num_len >= (ENCODING_LENGTH * 7)))
                {
                    len_diff = tmp_len - num_len;
                }
                else if ((num_len > tmp_len) && (tmp_len >= (ENCODING_LENGTH * 7)))
                {
                    add_len_diff = num_len - tmp_len;
                }
                else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str1) == MMI_TRUE) ||
                         (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str1) == MMI_TRUE))
                {
                    if ((num_len >= (ENCODING_LENGTH * 7)) && (tmp_len >= (ENCODING_LENGTH * 7)))
                    {
                        add_len_diff = ENCODING_LENGTH;
                        len_diff = ENCODING_LENGTH;
                    }
                }
            }
            else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str1) == MMI_TRUE) ||
                     (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str1) == MMI_TRUE))
            {
                U16 num_len = (mmi_ucs2strlen((S8*) address_p)) * ENCODING_LENGTH;
                U16 tmp_len = (mmi_ucs2strlen((S8*) temp_p->address_p)) * ENCODING_LENGTH;

                if ((tmp_len > num_len) && (num_len >= (ENCODING_LENGTH * 7)))
                {
                    len_diff = tmp_len - num_len;
                }
                else if ((num_len > tmp_len) && (tmp_len >= (ENCODING_LENGTH * 7)))
                {
                    add_len_diff = num_len - tmp_len;
                }
                else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str) == MMI_TRUE) ||
                         (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str) == MMI_TRUE))
                {
                    if ((num_len >= (ENCODING_LENGTH * 7)) && (tmp_len >= (ENCODING_LENGTH * 7)))
                    {
                        add_len_diff = ENCODING_LENGTH;
                        len_diff = ENCODING_LENGTH;
                    }
                }
            }

            if (mmi_jmms_compair_string((S8*) address_p + add_len_diff, (S8*) temp_p->address_p + len_diff) == 0)
                /* if (mmi_ucs2cmp((S8*) address_p, temp_p->address_p) == 0) */
            {
                found = MMI_TRUE;
                break;
            }
            else
            {
                temp_p = temp_p->next_p;
                len_diff = 0;
                add_len_diff = 0;
            }
        }
    }
    if (found != MMI_TRUE)
    {
        temp_p = g_jmms_context->cc_address_p;
        if (temp_p != NULL)
        {
            for (i = 0; i < g_jmms_context->num_cc_addresses; i++)
            {
                if (ignore_address_field == E_CC_ADDRESSES)
                    if (i == ignore_address_id) /* Amit */
                    {                           /* Increase temp_p to point to next_p address_p feild */
                        temp_p = temp_p->next_p;
                        len_diff = 0;
                        add_len_diff = 0;       /* End */
                        continue;
                    }

                if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str) == MMI_TRUE) ||
                    (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str) == MMI_TRUE))
                {
                    U16 num_len = (mmi_ucs2strlen((S8*) address_p)) * ENCODING_LENGTH;
                    U16 tmp_len = (mmi_ucs2strlen((S8*) temp_p->address_p)) * ENCODING_LENGTH;

                    if ((tmp_len > num_len) && (num_len >= (ENCODING_LENGTH * 7)))
                    {
                        len_diff = tmp_len - num_len;
                    }
                    else if ((num_len > tmp_len) && (tmp_len >= (ENCODING_LENGTH * 7)))
                    {
                        add_len_diff = num_len - tmp_len;
                    }
                    else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str1) == MMI_TRUE) ||
                             (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str1) == MMI_TRUE))
                    {
                        if ((num_len >= (ENCODING_LENGTH * 7)) && (tmp_len >= (ENCODING_LENGTH * 7)))
                        {
                            add_len_diff = ENCODING_LENGTH;
                            len_diff = ENCODING_LENGTH;
                        }
                    }
                }
                else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str1) == MMI_TRUE) ||
                         (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str1) == MMI_TRUE))
                {
                    U16 num_len = (mmi_ucs2strlen((S8*) address_p)) * ENCODING_LENGTH;
                    U16 tmp_len = (mmi_ucs2strlen((S8*) temp_p->address_p)) * ENCODING_LENGTH;

                    if ((tmp_len > num_len) && (num_len >= (ENCODING_LENGTH * 7)))
                    {
                        len_diff = tmp_len - num_len;
                    }
                    else if ((num_len > tmp_len) && (tmp_len >= (ENCODING_LENGTH * 7)))
                    {
                        add_len_diff = num_len - tmp_len;
                    }
                    else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str) == MMI_TRUE) ||
                             (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str) == MMI_TRUE))
                    {
                        if ((num_len >= (ENCODING_LENGTH * 7)) && (tmp_len >= (ENCODING_LENGTH * 7)))
                        {
                            add_len_diff = ENCODING_LENGTH;
                            len_diff = ENCODING_LENGTH;
                        }
                    }
                }
                if (mmi_jmms_compair_string((S8*) address_p + add_len_diff, (S8*) temp_p->address_p + len_diff) == 0)
                {
                    found = MMI_TRUE;
                    break;
                }
                else
                {
                    temp_p = temp_p->next_p;
                    len_diff = 0;
                    add_len_diff = 0;
                }
            }
        }
    }
    if (found != MMI_TRUE)
    {
        temp_p = g_jmms_context->bcc_address_p;
        if (temp_p != NULL)
        {
            for (i = 0; i < g_jmms_context->num_bcc_addresses; i++)
            {
                if (ignore_address_field == E_BCC_ADDRESSES)
                    if (i == ignore_address_id) /* Amit */
                    {                           /* Increase temp_p to point to next_p address_p feild */
                        temp_p = temp_p->next_p;
                        len_diff = 0;
                        add_len_diff = 0;       /* End */
                        continue;
                    }

                if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str) == MMI_TRUE) ||
                    (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str) == MMI_TRUE))
                {
                    U16 num_len = (mmi_ucs2strlen((S8*) address_p)) * ENCODING_LENGTH;
                    U16 tmp_len = (mmi_ucs2strlen((S8*) temp_p->address_p)) * ENCODING_LENGTH;

                    if ((tmp_len > num_len) && (num_len >= (ENCODING_LENGTH * 7)))
                    {
                        len_diff = tmp_len - num_len;
                    }
                    else if ((num_len > tmp_len) && (tmp_len >= (ENCODING_LENGTH * 7)))
                    {
                        add_len_diff = num_len - tmp_len;
                    }
                    else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str1) == MMI_TRUE) ||
                             (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str1) == MMI_TRUE))
                    {
                        if ((num_len >= (ENCODING_LENGTH * 7)) && (tmp_len >= (ENCODING_LENGTH * 7)))
                        {
                            add_len_diff = ENCODING_LENGTH;
                            len_diff = ENCODING_LENGTH;
                        }
                    }
                }
                else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str1) == MMI_TRUE) ||
                         (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str1) == MMI_TRUE))
                {
                    U16 num_len = (mmi_ucs2strlen((S8*) address_p)) * ENCODING_LENGTH;
                    U16 tmp_len = (mmi_ucs2strlen((S8*) temp_p->address_p)) * ENCODING_LENGTH;

                    if ((tmp_len > num_len) && (num_len >= (ENCODING_LENGTH * 7)))
                    {
                        len_diff = tmp_len - num_len;
                    }
                    else if ((num_len > tmp_len) && (tmp_len >= (ENCODING_LENGTH * 7)))
                    {
                        add_len_diff = num_len - tmp_len;
                    }
                    else if ((jdi_UtilsStrStartsWith((S8*) address_p, (S8*) tmp_str) == MMI_TRUE) ||
                             (jdi_UtilsStrStartsWith((S8*) temp_p->address_p, (S8*) tmp_str) == MMI_TRUE))
                    {
                        if ((num_len >= (ENCODING_LENGTH * 7)) && (tmp_len >= (ENCODING_LENGTH * 7)))
                        {
                            add_len_diff = ENCODING_LENGTH;
                            len_diff = ENCODING_LENGTH;
                        }
                    }
                }
                if (mmi_jmms_compair_string((S8*) address_p + add_len_diff, (S8*) temp_p->address_p + len_diff) == 0)
                {
                    found = MMI_TRUE;
                    break;
                }
                else
                {
                    temp_p = temp_p->next_p;
                    len_diff = 0;
                    add_len_diff = 0;
                }
            }
        }
    }
    return found;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_number_input_format
 * DESCRIPTION
 *  checks the format of input email addrees whether valid or not
 * PARAMETERS
 *  number_p        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_jmms_check_number_input_format(U8 *number_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    S32 i;
    MMI_BOOL allow = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = STR_LEN(number_p);
    if ((CHR_AT(number_p, 0) == (U16) ('+')) && (len == 1))
    {
        allow = MMI_FALSE;
        return allow;
        goto END;
    }
    for (i = 0; i < len; i++)
    {
        if ((CHR_AT(number_p, i) != (U16) ('+')) &&
            (CHR_AT(number_p, i) < (U16) ('0') || CHR_AT(number_p, i) > (U16) ('9')))
        {
            allow = MMI_FALSE;
            return allow;
            break;

        }
        if ((CHR_AT(number_p, i) == (U16) ('+')) && (i > 0))
        {
            allow = MMI_FALSE;
            return allow;
            break;
        }
    }

  END:
    return allow;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_address_input_format
 * DESCRIPTION
 *  checks the format of input email addrees whether valid or not
 * PARAMETERS
 *  email_address_p     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_jmms_check_address_input_format(U8 *email_address_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    S32 i;

    /* PMT VIKAS START 20050325 */
    S32 pos_1 = 0, pos_2 = 0;

    /* PMT VIKAS END 20050325 */
    MMI_BOOL allow = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = STR_LEN(email_address_p);
    for (i = 0; i < len; i++)
    {
        if (CHR_AT(email_address_p, i) == (U16) ('@'))
            //PMT VIKAS START 20050325
            //now valid email is of form name@domain domain is in the form b.c
        {
            if (i == 0)
            {
                allow = MMI_FALSE;
                return allow;
            }
            pos_1 = i;
            break;
        }
    }
    if (i == len)
    {
        allow = MMI_FALSE;
        return allow;
    }
    for (; i < len; i++)
    {
        if (CHR_AT(email_address_p, i) == (U16) ('.'))
        {
            pos_2 = i;
            break;
        }
    }
    if (pos_2 + 1 == len || (pos_2 - pos_1) <= 1)
    {
        allow = MMI_FALSE;
        return allow;
    }
    for (; i < len; i++)
    {
        if (CHR_AT(email_address_p, i) == (U16) ('.'))
        {
            pos_2 = i;
        }
    }
    if (pos_2 + 1 == len)
    {
        allow = MMI_FALSE;
    }
    else
    {
        memset(g_jmms_context->email_buff, 0x00, MAX_POSSIBLE_EMAIL_LENGHT_SENT);
        mmi_ucs2cpy((S8*) g_jmms_context->email_buff, (S8*) STR_AT(email_address_p, pos_1 + 1));
        if (!mmi_jmms_addrss_is_domain_name(g_jmms_context->email_buff))
        {
            allow = MMI_FALSE;
        }
        else
        {
            memset(g_jmms_context->email_buff, 0x00, MAX_POSSIBLE_EMAIL_LENGHT_SENT);
            mmi_ucs2cpy((S8*) g_jmms_context->email_buff, (S8*) STR_AT(email_address_p, 0));
            if (!mmi_jmms_is_email_local_part(g_jmms_context->email_buff, pos_1))
                /* PMT VIKAS END 20050325 */
            {
                allow = MMI_FALSE;
            }
        }
    }

    return allow;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_addrss_is_domain_name
 * DESCRIPTION
 *  check whether input email address_p is some domain name
 * PARAMETERS
 *  str_p       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_jmms_addrss_is_domain_name(U16 *str_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*str_p == (U16) ('\0'))
    {
        return MMI_FALSE;
    }
    do
    {
        if (((*str_p >= (U16) ('a') && *str_p <= (U16) ('z')) ||
             (*str_p >= (U16) ('A') && *str_p <= (U16) ('Z')) ||
             (*str_p >= (U16) ('0') && *str_p <= (U16) ('9')) || (*str_p == (U16) ('-')) ||
             (*str_p == (U16) ('.'))) == 0)
        {
            return MMI_FALSE;
        }
        str_p++;
    }
    while (*str_p != (U16) ('\0'));

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_email_local_part
 * DESCRIPTION
 *  check whether input email address_p contains valid chars
 * PARAMETERS
 *  str_p       [IN]        
 *  cnt         [IN]        
 * RETURNS
 *  boolean
 *****************************************************************************/
MMI_BOOL mmi_jmms_is_email_local_part(U16 *str_p, S32 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < cnt; i++)
    {
        ch = CHR_AT(str_p, i);
        if ((ch >= (U16) ('a') && ch <= (U16) ('z')) ||
            (ch >= (U16) ('A') && ch <= (U16) ('Z')) || (ch >= (U16) ('0') && ch <= (U16) ('9')))
        {
            continue;
        }
        switch (ch)
        {
                /* Reference RFC 2822 */
            case (U16) ('.'):
            case (U16) ('!'):
            case (U16) ('#'):
            case (U16) ('$'):
            case (U16) ('%'):
            case (U16) ('&'):
            case (U16) ('\''):
            case (U16) ('*'):
            case (U16) ('+'):
            case (U16) ('-'):
            case (U16) ('/'):
            case (U16) ('='):
            case (U16) ('?'):
            case (U16) ('^'):
            case (U16) ('_'):
            case (U16) ('`'):
            case (U16) ('{'):
            case (U16) ('|'):
            case (U16) ('}'):
            case (U16) ('~'):
                break;
            default:
                return MMI_FALSE;
        }

    }

    return MMI_TRUE;
}

/* Deepali Added for Reply Charging handling. */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_reply_charging_ind_cb
 * DESCRIPTION
 *  Add the file content to MMS according to their Media type.
 * PARAMETERS
 *  h_msg               [IN]        
 *  call_back_arg_p     [IN]        
 *  rc_limit_p          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_reply_charging_ind_cb(MSG_HANDLE h_msg, void *call_back_arg_p, REPLY_CHARGE_LIMITS *rc_limit_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (h_msg == NULL)
    {
        ret_code = JC_ERR_MMS_INVALID_HANDLE;
        goto ERROR_HANDLE;
    }
    if (rc_limit_p == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto ERROR_HANDLE;
    }

    if (rc_limit_p != NULL)
    {
        if (g_jmms_context->rc_info != NULL)
        {
            if (g_jmms_context->rc_info->pReplyMsgID != NULL)
            {
                jdd_MemFree(g_jmms_context->rc_info->pReplyMsgID);
            }
            jdd_MemFree(g_jmms_context->rc_info);
            g_jmms_context->rc_info = NULL;
        }

        g_jmms_context->rc_info = (REPLY_CHARGE_LIMITS*) jdd_MemAlloc(sizeof(REPLY_CHARGE_LIMITS), 1);
        g_jmms_context->rc_info->eRCType = rc_limit_p->eRCType;
        g_jmms_context->rc_info->uiRCSize = rc_limit_p->uiRCSize;
        g_jmms_context->rc_info->uiRCTime = rc_limit_p->uiRCTime;
        g_jmms_context->rc_info->pReplyMsgID = (JC_INT8*) jdi_UtilsStrdup((JC_INT8*) rc_limit_p->pReplyMsgID);

    }

  ERROR_HANDLE:
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_valid_rc_size_limits
 * DESCRIPTION
 *  Check reply charging validty for message size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_check_valid_rc_size_limits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 ui_msg_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->rc_info != NULL)
    {
        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &ui_msg_size);
        if ((g_jmms_context->rc_info->uiRCSize > 0) && (g_jmms_context->rc_info->uiRCSize < ui_msg_size))
        {
            return E_FALSE;
        }
    }
    return E_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_valid_rc_type
 * DESCRIPTION
 *  Check reply charging validty for media type.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_check_valid_rc_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT8 media_count, count;
    MEDIA_INFO *media_info_list_p = NULL;
    U8 page_index = 0, total_pages = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &total_pages);

    for (page_index = 1; page_index <= total_pages; page_index++)
    {
        mmi_jmms_jdi_get_media_list(g_jmms_context->msg_handle, page_index, &media_info_list_p, &media_count, E_FALSE);

        if (media_info_list_p != NULL)
        {
            if (g_jmms_context->rc_info != NULL &&
                g_jmms_context->rc_info->eRCType == E_REPLY_CHARGING_ACCEPTED_TEXT_ONLY)
            {
                for (count = 0; count < media_count; count++)
                {
                    if (media_info_list_p->eMediaType != E_MEDIA_TEXT)
                    {
                        return E_FALSE;
                    }
                    else
                    {
                        media_info_list_p = media_info_list_p->pNext;
                    }
                }
            }
        }
    }

    return E_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_valid_rc_send_time
 * DESCRIPTION
 *  Check reply charging validty for mms sending time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_check_valid_rc_send_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U8 number = 0;
    RETRIEVE_FILTERS store_ret_filter = {0, };
    MESSAGE_LIST *message_list_p = NULL;
    JC_UINT32 send_time = 0;
    MESSAGE_RETRIEVAL *message_send_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_mms_get_number_of_messages(folder_name, &number); */
    number = g_jmms_context->store_context->num_msg_in_curr_folder;

    store_ret_filter.uiStartIndex = number - g_jmms_context->curr_scr_hilited_index;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    store_ret_filter.uiNumMessage = 1;

    ret_code = mmi_jmms_get_messages_list(MMI_JMMS_INBOX, &message_list_p, &store_ret_filter);

    if (ret_code != JC_OK || message_list_p == NULL)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        return FALSE;
    }

    message_send_p = (MESSAGE_RETRIEVAL*) (message_list_p->pMessageHeaders->pHeaders);

    if (message_send_p == NULL)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        return FALSE;
    }
    send_time = jdd_TimerGetCurrentTime() - message_send_p->uiDate;

    if (g_jmms_context->rc_info != NULL && g_jmms_context->rc_info->uiRCTime > 0)
    {
        if (send_time > g_jmms_context->rc_info->uiRCTime)
        {
            return E_FALSE;
        }
    }
    return E_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_rc_info_present
 * DESCRIPTION
 *  Check reply charging info present for the mms.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_rc_info_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->rc_info != NULL)
    {
        return E_TRUE;
    }
    else
    {
        return E_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compair_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string1_p       [IN]        
 *  string2_p       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_jmms_compair_string(S8 *string1_p, S8 *string2_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    BOOL flag = FALSE;
    JC_CHAR *tmp_str1_p = NULL;
    JC_CHAR *tmp_str2_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_str1_p = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) string1_p) * ENCODING_LENGTH + ENCODING_LENGTH, 1);
    if (tmp_str1_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return flag;
    }
    tmp_str2_p = (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) string2_p) * ENCODING_LENGTH + ENCODING_LENGTH, 1);
    if (tmp_str2_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return flag;
    }
    mmi_ucs2cpy((S8*) tmp_str1_p, (S8*) string1_p);
    mmi_ucs2cpy((S8*) tmp_str2_p, (S8*) string2_p);
    /* tmp_str2_p = jdi_UtilsTcsDup((JC_CHAR*)string2_p); */

    tmp_str1_p = jdi_UtilsTcsUpperToLower((JC_CHAR*) tmp_str1_p);
    tmp_str2_p = jdi_UtilsTcsUpperToLower((JC_CHAR*) tmp_str2_p);

    flag = mmi_ucs2cmp((S8*) tmp_str1_p, (S8*) tmp_str2_p);

    if (tmp_str1_p)
    {
        jdd_MemFree(tmp_str1_p);
    }

    if (tmp_str2_p)
    {
        jdd_MemFree(tmp_str2_p);
    }
    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_address_in_addresse_list
 * DESCRIPTION
 *  Add the input address_p in address_p list
 * PARAMETERS
 *  address_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_jmms_add_address_in_addresse_list(S8 *address_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_address_list_struct *address_temp_p, *address_node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node_p = (mmi_jmms_address_list_struct*) jdd_MemAlloc(sizeof(mmi_jmms_address_list_struct), 1);
    if (address_node_p == NULL)
    {
        return 1;
    }

    address_node_p->address_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(address_p) + 1) * ENCODING_LENGTH, sizeof(S8));
    if (address_node_p->address_p == NULL)
    {
        return 1;
    }

    mmi_ucs2cpy(address_node_p->address_p, address_p);
    address_node_p->next_p = NULL;

    if (g_jmms_context->address_list_flag == E_TO_ADDRESSES)
    {
        if (g_jmms_context->num_to_addresses == 0)
        {
            g_jmms_context->to_address_p = address_node_p;
        }
        else
        {
            address_temp_p = g_jmms_context->to_address_p;

            while (address_temp_p->next_p != NULL)
            {
                address_temp_p = address_temp_p->next_p;
            }

            address_temp_p->next_p = address_node_p;

        }
        g_jmms_context->num_to_addresses++;
    }
    else if (g_jmms_context->address_list_flag == E_CC_ADDRESSES)
    {
        if (g_jmms_context->num_cc_addresses == 0)
        {
            g_jmms_context->cc_address_p = address_node_p;
        }
        else
        {
            address_temp_p = g_jmms_context->cc_address_p;

            while (address_temp_p->next_p != NULL)
            {
                address_temp_p = address_temp_p->next_p;
            }

            address_temp_p->next_p = address_node_p;

        }
        g_jmms_context->num_cc_addresses++;
    }
    else if (g_jmms_context->address_list_flag == E_BCC_ADDRESSES)
    {
        if (g_jmms_context->num_bcc_addresses == 0)
        {
            g_jmms_context->bcc_address_p = address_node_p;
        }
        else
        {
            address_temp_p = g_jmms_context->bcc_address_p;

            while (address_temp_p->next_p != NULL)
            {
                address_temp_p = address_temp_p->next_p;
            }

            address_temp_p->next_p = address_node_p;

        }
        g_jmms_context->num_bcc_addresses++;
    }
    g_jmms_context->num_total_addresses++;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_add_from_address_in_addresse_list
 * DESCRIPTION
 *  Add the from address in address list
 * PARAMETERS
 *  address     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_jmms_add_from_address_in_addresse_list(S8 *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_address_list_struct *address_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node = (mmi_jmms_address_list_struct*) jdd_MemAlloc(sizeof(mmi_jmms_address_list_struct), 1);
    if (address_node == NULL)
    {
        return 1;
    }

    address_node->address_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(address) + 1) * ENCODING_LENGTH, sizeof(S8));
    if (address_node->address_p == NULL)
    {
        return 1;
    }

    mmi_ucs2cpy(address_node->address_p, address);
    address_node->next_p = NULL;

    g_jmms_context->from_address_p = address_node;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_addresses_list
 * DESCRIPTION
 *  This fn will free the addresses(To,Cc,Bcc) list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_addresses_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_address_list_struct *address_node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->to_address_p != NULL)
    {
        address_node_p = g_jmms_context->to_address_p;

        while (address_node_p != NULL)
        {
            g_jmms_context->to_address_p = address_node_p->next_p;
            jdd_MemFree(address_node_p->address_p);
            jdd_MemFree(address_node_p);
            address_node_p = g_jmms_context->to_address_p;

        }
    }
    g_jmms_context->num_to_addresses = 0;
    g_jmms_context->to_address_p = NULL;

    address_node_p = g_jmms_context->cc_address_p;

    if (g_jmms_context->cc_address_p != NULL)
    {

        address_node_p = g_jmms_context->cc_address_p;

        while (address_node_p != NULL)
        {
            g_jmms_context->cc_address_p = address_node_p->next_p;
            jdd_MemFree(address_node_p->address_p);
            jdd_MemFree(address_node_p);
            address_node_p = g_jmms_context->cc_address_p;

        }
    }
    g_jmms_context->num_cc_addresses = 0;
    g_jmms_context->cc_address_p = NULL;

    address_node_p = g_jmms_context->bcc_address_p;

    if (g_jmms_context->bcc_address_p != NULL)
    {

        address_node_p = g_jmms_context->bcc_address_p;

        while (address_node_p != NULL)
        {
            g_jmms_context->bcc_address_p = address_node_p->next_p;
            jdd_MemFree(address_node_p->address_p);
            jdd_MemFree(address_node_p);
            address_node_p = g_jmms_context->bcc_address_p;

        }
    }
    g_jmms_context->num_bcc_addresses = 0;
    g_jmms_context->bcc_address_p = NULL;
    g_jmms_context->num_total_addresses = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_to_addresses
 * DESCRIPTION
 *  Used to get addresses in To field
 * PARAMETERS
 *  void
 * RETURNS
 *  string containing To addresses
 *****************************************************************************/
S8 *mmi_jmms_get_to_addresses(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    mmi_jmms_address_list_struct *address_node_p;
    S8 *to_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node_p = g_jmms_context->to_address_p;

    while (address_node_p != NULL)
    {
        len = len + (mmi_ucs2strlen(address_node_p->address_p)) * ENCODING_LENGTH + ENCODING_LENGTH;
        address_node_p = address_node_p->next_p;
    }

    to_p = (S8*) jdd_MemAlloc(sizeof(S8), len);

    if (NULL == to_p)
    {
        return NULL;
    }

    address_node_p = g_jmms_context->to_address_p;

    while (address_node_p != NULL)
    {
        mmi_ucs2cat((S8*) to_p, (const S8*)address_node_p->address_p);
        address_node_p = address_node_p->next_p;

        if (address_node_p != NULL)
        {
            mmi_ucs2cat((S8*) to_p, (const S8*)";");
        }
    }

    return to_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_cc_addresses
 * DESCRIPTION
 *  used to get CC addresses
 * PARAMETERS
 *  void
 * RETURNS
 *  string containing CC addresses
 *****************************************************************************/
S8 *mmi_jmms_get_cc_addresses(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    mmi_jmms_address_list_struct *address_node_p;
    S8 *cc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node_p = g_jmms_context->cc_address_p;

    while (address_node_p != NULL)
    {
        len = len + (mmi_ucs2strlen(address_node_p->address_p)) * ENCODING_LENGTH + ENCODING_LENGTH;
        address_node_p = address_node_p->next_p;
    }

    cc_p = (S8*) jdd_MemAlloc(sizeof(S8), len);

    if (NULL == cc_p)
    {
        return NULL;
    }

    address_node_p = g_jmms_context->cc_address_p;

    while (address_node_p != NULL)
    {
        mmi_ucs2cat((S8*) cc_p, (const S8*)address_node_p->address_p);
        address_node_p = address_node_p->next_p;

        if (address_node_p != NULL)
        {
            mmi_ucs2cat((S8*) cc_p, (const S8*)";");
        }
    }

    return cc_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_bcc_addresses
 * DESCRIPTION
 *  used to get BCC addresses
 * PARAMETERS
 *  void
 * RETURNS
 *  string containing BCC addresses
 *****************************************************************************/
S8 *mmi_jmms_get_bcc_addresses(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    mmi_jmms_address_list_struct *address_node_p;
    S8 *bcc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node_p = g_jmms_context->bcc_address_p;

    while (address_node_p != NULL)
    {
        len = len + (mmi_ucs2strlen(address_node_p->address_p)) * ENCODING_LENGTH + ENCODING_LENGTH;
        address_node_p = address_node_p->next_p;
    }

    bcc_p = (S8*) jdd_MemAlloc(sizeof(S8), len);
    if (NULL == bcc_p)
    {
        return NULL;
    }

    address_node_p = g_jmms_context->bcc_address_p;

    while (address_node_p != NULL)
    {
        mmi_ucs2cat((S8*) bcc_p, (const S8*)address_node_p->address_p);
        address_node_p = address_node_p->next_p;

        if (address_node_p != NULL)
        {
            mmi_ucs2cat((S8*) bcc_p, (const S8*)";");
        }
    }

    return bcc_p;
}
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 


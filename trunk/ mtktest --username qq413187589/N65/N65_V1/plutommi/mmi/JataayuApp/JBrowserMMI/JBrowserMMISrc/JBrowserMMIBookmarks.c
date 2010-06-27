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
 * JBrowserMMIBookmarks.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for bookmark implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_JBROWSERMMIBOOKMARKS_C
#define _MMI_JBROWSERMMIBOOKMARKS_C

/*  Include: MMI header file */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "DateTimeGprot.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"
#include "jdd_ui_datatypes.h"
#include "jdd_ui_utils.h"
#include "JProvWap.h"
#include "PhoneBookGprot.h"

static U8 g_mmi_brw_bkm_add_flag;
static U8 g_free_bmk_list;


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_bookmark_list
 * DESCRIPTION
 *  Entry function for Bookmark list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_bookmark_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 nempty_id = STR_ID_BRW_EMPTY;
    U8 highlight_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read bookmark from NVRAM */
    if (g_mmi_brw_cntx.jbrowser_frm_ext_app)
    {
        if (g_mmi_brw_cntx.bookmark_url_p)
        {
            g_free_bmk_list = FALSE;
        }
        else
        {
            g_free_bmk_list = TRUE;
            mmi_brw_read_bookmark_from_nvram();
        }
    }
    else
    {
        mmi_brw_read_bookmark_from_nvram();
    }

    if (!g_mmi_brw_cntx.total_bookmark_items && g_mmi_brw_cntx.jbrowser_frm_ext_app)
    {
        g_mmi_brw_cntx.jbrowser_frm_ext_app = MMI_FALSE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        wap_send_select_bookmark_rsp(MMI_FALSE, 0);
        return;
    }

    EntryNewScreen(SCR_ID_BRW_BOOKMARKS, NULL, mmi_brw_entry_bookmark_list, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARKS);

    /* Display 'Empty' if no bookmarks are present */
    if (g_mmi_brw_cntx.total_bookmark_items == 0)
    {
        ShowCategory15Screen(
            STR_ID_BRW_BOOKMARKS,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            0,
            STR_GLOBAL_BACK,
            0,
            1,
            &nempty_id,
            (U16*) gIndexIconsImageList,
            LIST_MENU,
            0,
            gui_buffer_p);

        SetLeftSoftkeyFunction(mmi_brw_pre_entry_bookmark_options, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_pre_entry_bookmark_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        U16 lsk_label;
        FuncPtr lsk_hdlr;

        if (gui_buffer_p != NULL)
        {
            if (g_mmi_brw_bkm_add_flag)
            {
                gui_buffer_p = NULL;
                highlight_index = g_mmi_brw_cntx.index_highlighted_item;
                g_mmi_brw_bkm_add_flag = 0;
            }
        }
        if (g_mmi_brw_cntx.jbrowser_frm_ext_app)
        {
            lsk_label = STR_GLOBAL_OK;
            lsk_hdlr = mmi_brw_send_bookmark_details;
        }
        else
        {
            lsk_label = STR_GLOBAL_OPTIONS;
            lsk_hdlr = mmi_brw_pre_entry_bookmark_options;
        }

        ShowCategory184Screen(
            STR_ID_BRW_BOOKMARKS,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            lsk_label,
            0,
            STR_GLOBAL_BACK,
            0,
            g_mmi_brw_cntx.total_bookmark_items,
            mmi_brw_bookmark_list_get_item,
            0,
            highlight_index,
            gui_buffer_p);

        SetLeftSoftkeyFunction(lsk_hdlr, KEY_EVENT_UP);
        SetKeyHandler(lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(mmi_brw_bmk_list_goback_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bmk_list_goback_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bmk_list_goback_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bmk_list_goback_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.jbrowser_frm_ext_app)
    {
        g_mmi_brw_cntx.jbrowser_frm_ext_app = MMI_FALSE;
        wap_send_select_bookmark_rsp(MMI_FALSE, 0);
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_bookmark_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_bookmark_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.jbrowser_frm_ext_app = MMI_FALSE;
    wap_send_select_bookmark_rsp(MMI_TRUE, (U8) GetHighlightedItem());
}


/*****************************************************************************
 * FUNCTION
 *  wap_send_select_bookmark_rsp
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  rsp             [IN]        
 *  bmk_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_select_bookmark_rsp(MMI_BOOL rsp, U8 bmk_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_select_bookmark_rsp_struct *select_bmk_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    select_bmk_rsp =
        (wap_select_bookmark_rsp_struct*) construct_local_para(
                                            (kal_uint16) sizeof(wap_select_bookmark_rsp_struct),
                                            TD_CTRL);

    if (rsp == MMI_FALSE)
    {
        select_bmk_rsp->result = MMI_FALSE;
    }
    else
    {
        select_bmk_rsp->result = MMI_TRUE;
        strcpy((PS8) select_bmk_rsp->url, (PS8) g_mmi_brw_cntx.bookmark_url_p[bmk_index].url);
    }

    if (g_free_bmk_list)
    {
        /* Free memory allocated to bookmarks */
        if (g_mmi_brw_cntx.bookmark_title_p != NULL)
        {
            jdd_MemFree(g_mmi_brw_cntx.bookmark_title_p);
            g_mmi_brw_cntx.bookmark_title_p = NULL;
        }

        /* Free memory allocated to bookmarks */
        if (g_mmi_brw_cntx.bookmark_url_p != NULL)
        {
            jdd_MemFree(g_mmi_brw_cntx.bookmark_url_p);
            g_mmi_brw_cntx.bookmark_url_p = NULL;
        }
        g_mmi_brw_cntx.total_bookmark_items = 0;
    }

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_WAP_SELECT_BOOKMARK_RSP;
    Message.oslDataPtr = (oslParaType*) select_bmk_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmark_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of bookmarks
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_brw_bookmark_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MMI_BRW_MAX_BOOKMARKS))
    {
        return FALSE;
    }

    /* Display title if settings option is 'Show history by title' */
    if ((g_mmi_brw_cntx.show_history_as_url) || (strlen((S8*) g_mmi_brw_cntx.bookmark_title_p[item_index].title) == 0))
    {
        mmi_brw_ansii_string_concatenate_dots(str_buff, (S8*) g_mmi_brw_cntx.bookmark_url_p[item_index].url);
    }
    else
    {
        if ((g_mmi_brw_cntx.bookmark_title_p[item_index].dcs == MMI_BRW_DCS_ASCII) &&
            (strlen((S8*) g_mmi_brw_cntx.bookmark_title_p[item_index].title)) != 0)
        {
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) g_mmi_brw_cntx.bookmark_title_p[item_index].title);
        }
        else if ((g_mmi_brw_cntx.bookmark_title_p[item_index].dcs == MMI_BRW_DCS_UCS) &&
                 (mmi_ucs2strlen((S8*) g_mmi_brw_cntx.bookmark_title_p[item_index].title)) != 0)
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) g_mmi_brw_cntx.bookmark_title_p[item_index].title);
        }
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_calculate_number_of_bookmarks_stored
 * DESCRIPTION
 *  Function to calculate the total number of bookmarks stored
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_calculate_number_of_bookmarks_stored(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bkm_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (bkm_count = 0; bkm_count < MMI_BRW_MAX_BOOKMARKS; bkm_count++)
    {
        if ((strlen((S8*) g_mmi_brw_cntx.bookmark_url_p[bkm_count].url)) == 0)
        {
            break;
        }

        g_mmi_brw_cntx.total_bookmark_items++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_bookmark_options
 * DESCRIPTION
 *  Pre Entry function for Bookmark options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_bookmark_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get the current highlited bookmark index */
    g_mmi_brw_cntx.index_highlighted_item = (U8) GetHighlightedItem();

    mmi_brw_entry_bookmark_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_bookmark_options
 * DESCRIPTION
 *  Entry function for Bookmark options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_bookmark_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_list_of_items[6];
    U8 *gui_buffer_p;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BOOKMARK_OPTIONS, NULL, mmi_brw_entry_bookmark_options, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARK_OPTIONS);

    /* If no bookmarks are present, Display scren with only one option i.e 'Add bookmark' */
    if (g_mmi_brw_cntx.total_bookmark_items == 0)
    {
        num_of_items = GetNumOfChild(MENU_ID_BRW_BKM_OPTIONS_1);
        GetSequenceStringIds(MENU_ID_BRW_BKM_OPTIONS_1, uc_list_of_items);
        SetParentHandler(MENU_ID_BRW_BKM_OPTIONS_1);
    }
    else
    {
        num_of_items = GetNumOfChild(MENU_ID_BRW_BKM_OPTIONS_2);
        GetSequenceStringIds(MENU_ID_BRW_BKM_OPTIONS_2, uc_list_of_items);
        SetParentHandler(MENU_ID_BRW_BKM_OPTIONS_2);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        uc_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_add_bookmark
 * DESCRIPTION
 *  Pre Entry function for Add bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If Bookmark list is full, Dispaly 'Bookmark list is full' */
    if (g_mmi_brw_cntx.total_bookmark_items >= MMI_BRW_MAX_BOOKMARKS)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_BOOKMARK_FULL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    else
    {
        memset(g_mmi_brw_cntx.brw_bkm_selected_title, 0, ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) ("http://"));

        /* Set edit flag */
        g_mmi_brw_cntx.edit_flag = BRW_STATUS_NO;

        mmi_brw_entry_add_bookmark_screen_for_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_add_bookmark_screen_for_all
 * DESCRIPTION
 *  Entry function for Add bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_add_bookmark_screen_for_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;
    U16 input_buffer_size;
    InlineItem brw_bookmark_inline_edit_list[4];
    U16 icons_image_list[4] = {0};
    U16 string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(brw_bookmark_inline_edit_list, 0, sizeof(brw_bookmark_inline_edit_list));

    EntryNewScreen(SCR_ID_BRW_ADD_BOOKMARK, mmi_brw_exit_add_bookmark_screen_for_all, NULL, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_ADD_BOOKMARK);

    InitializeCategory57Screen();

    /* For title caption */
    SetInlineItemActivation(
        &brw_bookmark_inline_edit_list[BRW_INLINE_TITLE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&brw_bookmark_inline_edit_list[BRW_INLINE_TITLE_CAPTION], (U8*) GetString(STR_ID_BRW_TITLE));

    /* For title string */
    SetInlineItemActivation(&brw_bookmark_inline_edit_list[BRW_INLINE_TITLE], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &brw_bookmark_inline_edit_list[BRW_INLINE_TITLE],
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_mmi_brw_cntx.brw_bkm_selected_title,
        MMI_BRW_BKM_MAX_TITLE_LENGTH,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER);
    SetInlineFullScreenEditCustomFunction(&brw_bookmark_inline_edit_list[BRW_INLINE_TITLE], mmi_brw_full_screen_edit);

    /* For Address caption */
    SetInlineItemActivation(
        &brw_bookmark_inline_edit_list[BRW_INLINE_ADDRESS_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &brw_bookmark_inline_edit_list[BRW_INLINE_ADDRESS_CAPTION],
        (U8*) GetString(STR_ID_BRW_ADDRESS));

    /* For Address string (URL) */
    SetInlineItemActivation(&brw_bookmark_inline_edit_list[BRW_INLINE_URL], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &brw_bookmark_inline_edit_list[BRW_INLINE_URL],
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_mmi_brw_cntx.brw_current_url,
        MMI_BRW_BKM_MAX_URL_LENGTH,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&brw_bookmark_inline_edit_list[BRW_INLINE_URL], mmi_brw_full_screen_edit);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_BRW_ADD_BOOKMARK, &input_buffer_size);

    if (input_buffer_p != NULL)
    {
        SetCategory57Data(brw_bookmark_inline_edit_list, 4, input_buffer_p);
    }

    SetParentHandler(0);

    /* Set the softkey label to be displayed in  Category57 screen */
    RegisterHighlightHandler(mmi_brw_change_label_highlight_hdlr);

    icons_image_list[0] = gIndexIconsImageList[0];
    icons_image_list[2] = gIndexIconsImageList[1];
#ifndef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
    if ((g_mmi_brw_cntx.edit_flag == BRW_STATUS_FROM_ENTER_ADDRESS) ||
        (g_mmi_brw_cntx.edit_flag == BRW_STATUS_ADD_BKM_FROM_USE_URL))
#else /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 
    if ((g_mmi_brw_cntx.edit_flag == BRW_STATUS_FROM_ENTER_ADDRESS) ||
        (g_mmi_brw_cntx.edit_flag == BRW_STATUS_ADD_BKM_FROM_USE_URL) ||
        (g_mmi_brw_cntx.edit_flag == BRW_STATUS_ADD_BKM_FROM_OFFLINE_PAGES))
#endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 
    {
        if ((GetInlineDoneFlag(gui_buffer_p) == 0))
        {
            SetInlineDoneFlag(gui_buffer_p);
        }
        set_wgui_inline_list_menu_status(1);
    }

    if (g_mmi_brw_cntx.edit_flag == BRW_STATUS_YES)
    {
        string_id = STR_ID_BRW_EDIT_BOOKMARK;
    }
    else
    {
        string_id = STR_ID_BRW_ADD_BOOKMARK;
    }

    ShowCategory57Screen(
        string_id,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        4,
        (U16*) icons_image_list,
        brw_bookmark_inline_edit_list,
        0,
        gui_buffer_p);

    /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(mmi_brw_entry_confirmation_hdlr, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_add_bookmark_screen_for_all
 * DESCRIPTION
 *  Exit function for Add/Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_add_bookmark_screen_for_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr;
    S16 nhistory = 0;
    U16 input_buffer_size;  /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr.scrnID = SCR_ID_BRW_ADD_BOOKMARK;
    CloseCategory57Screen();
    scr.entryFuncPtr = mmi_brw_entry_add_bookmark_screen_for_all;
    mmi_ucs2cpy((S8*) scr.inputBuffer, (S8*) & nhistory);
    GetCategory57History(scr.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();  /* added for inline edit history */
    GetCategory57Data((U8*) scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(scr, (U16) input_buffer_size);          /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_edit_bookmark
 * DESCRIPTION
 *  Pre Entry function for Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_edit_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.bookmark_title_p[g_mmi_brw_cntx.index_highlighted_item].dcs == MMI_BRW_DCS_UCS)
    {
        mmi_ucs2cpy(
            (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
            (S8*) g_mmi_brw_cntx.bookmark_title_p[g_mmi_brw_cntx.index_highlighted_item].title);
    }
    else
    {
        mmi_asc_to_ucs2(
            (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
            (S8*) g_mmi_brw_cntx.bookmark_title_p[g_mmi_brw_cntx.index_highlighted_item].title);
    }

    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.brw_current_url,
        (S8*) g_mmi_brw_cntx.bookmark_url_p[g_mmi_brw_cntx.index_highlighted_item].url);

    /* Set edit flag */
    g_mmi_brw_cntx.edit_flag = BRW_STATUS_YES;
    mmi_brw_entry_add_bookmark_screen_for_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_change_label_highlight_hdlr
 * DESCRIPTION
 *  Custom Highlight handler to change the label of LSK in case of inline edit screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_change_label_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index == BRW_INLINE_TITLE) || (index == BRW_INLINE_URL))
    {
        /* Change the softkey label to 'Edit' */
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_full_screen_edit
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_full_screen_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_confirmation_hdlr
 * DESCRIPTION
 *  Entry screen for confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_confirmation_hdlr(void)
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
        get_string(STR_ID_BRW_SAVE_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_save_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_go_back_history, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_go_back_history
 * DESCRIPTION
 *  To go back to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.edit_flag == BRW_STATUS_ADD_BKM_FROM_USE_URL)
    {
        GoBacknHistory(1);
    }
    else
    {
        GoBacknHistory(2);
    }
    g_mmi_brw_cntx.edit_flag = BRW_STATUS_NO;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_bookmark
 * DESCRIPTION
 *  Function to save the bookmark to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_save_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_validate_url(g_mmi_brw_cntx.brw_current_url) == MMI_TRUE)
    {
        mmi_brw_save_bookmark_item();
        g_mmi_brw_bkm_add_flag = 1;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
        if (g_mmi_brw_cntx.edit_flag == BRW_STATUS_ADD_BKM_FROM_USE_URL)
        {
            DeleteNHistory(1);
        }
        else
        {
            DeleteNHistory(2);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_URL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_bookmark_item
 * DESCRIPTION
 *  Function to save particular bookmark item to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_save_bookmark_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* New bookmark is to be added (Add Bookmark menu) */
    if (g_mmi_brw_cntx.edit_flag != BRW_STATUS_YES)
    {
        mmi_brw_bkm_check_ucs2_flag_and_copy(
            (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
            g_mmi_brw_cntx.total_bookmark_items);
        g_mmi_brw_cntx.index_highlighted_item = g_mmi_brw_cntx.total_bookmark_items;
    }
    /* Existing bookmark is to be edited (Edit menu) */
    else
    {
        mmi_brw_bkm_check_ucs2_flag_and_copy(
            (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
            g_mmi_brw_cntx.index_highlighted_item);
    }

    mmi_brw_write_bookmark_to_nvram();

    if (g_mmi_brw_cntx.edit_flag != BRW_STATUS_YES)
    {
        g_mmi_brw_cntx.total_bookmark_items++;
    }
    else
    {
        g_mmi_brw_cntx.edit_flag = BRW_STATUS_NO;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_confirm(void)
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
        get_string(STR_ID_BRW_DELETE_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_delete_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_bookmark
 * DESCRIPTION
 *  Delete the selected bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bkm_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (bkm_count = g_mmi_brw_cntx.index_highlighted_item; bkm_count < g_mmi_brw_cntx.total_bookmark_items - 1;
         bkm_count++)
    {
        memcpy(
            &g_mmi_brw_cntx.bookmark_title_p[bkm_count],
            &g_mmi_brw_cntx.bookmark_title_p[bkm_count + 1],
            sizeof(g_mmi_brw_cntx.bookmark_title_p[bkm_count]));
        memcpy(
            &g_mmi_brw_cntx.bookmark_url_p[bkm_count],
            &g_mmi_brw_cntx.bookmark_url_p[bkm_count + 1],
            sizeof(g_mmi_brw_cntx.bookmark_url_p[bkm_count]));
    }

    /* Set the last bookmark item as 0 */
    memset(
        &g_mmi_brw_cntx.bookmark_title_p[g_mmi_brw_cntx.total_bookmark_items - 1],
        0,
        sizeof(g_mmi_brw_cntx.bookmark_title_p[g_mmi_brw_cntx.total_bookmark_items - 1]));
    memset(
        &g_mmi_brw_cntx.bookmark_url_p[g_mmi_brw_cntx.total_bookmark_items - 1],
        0,
        sizeof(g_mmi_brw_cntx.bookmark_url_p[g_mmi_brw_cntx.total_bookmark_items - 1]));

    mmi_brw_write_bookmark_to_nvram();

    g_mmi_brw_cntx.total_bookmark_items--;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_BRW_BOOKMARKS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_confirm_delete_all_bookmark
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of all the bookmarks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_delete_all_bookmark(void)
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
        get_string(STR_ID_BRW_DELETE_ALL_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_delete_all_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_all_bookmark
 * DESCRIPTION
 *  Deletes all the bookmarks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_all_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set all the bookmark entries as '0' */
    memset(g_mmi_brw_cntx.bookmark_title_p, 0, (NVRAM_BRW_BOOKMARK_TITLE_SIZE * NVRAM_BRW_NUM_BOOKMARK_TITLE_RECORDS));
    memset(g_mmi_brw_cntx.bookmark_url_p, 0, (NVRAM_BRW_BOOKMARK_URL_SIZE * NVRAM_BRW_NUM_BOOKMARK_URL_RECORDS));

    mmi_brw_write_bookmark_to_nvram();

    g_mmi_brw_cntx.total_bookmark_items = 0;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_BRW_BOOKMARKS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_goto_highlighted_bookmark
 * DESCRIPTION
 *  This function fetches the current highlighted bookmark url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_goto_highlighted_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.brw_current_url,
        (S8*) g_mmi_brw_cntx.bookmark_url_p[g_mmi_brw_cntx.index_highlighted_item].url);

    /* added by tk to set the current fetch url */
    mmi_brw_set_current_url((S8*) g_mmi_brw_cntx.brw_current_url);

    /* jdi call to fetch the url */
    mmi_brw_pre_entry_goto_url();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_read_bookmark_from_nvram
 * DESCRIPTION
 *  This function reads bookmark from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_read_bookmark_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 nvram_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read bookmarks from NVRAM if not already read */
    if ((g_mmi_brw_cntx.bookmark_title_p == NULL) && (g_mmi_brw_cntx.bookmark_url_p == NULL))
    {
        g_mmi_brw_cntx.bookmark_title_p =
            (nvram_brw_bkm_title_struct*) jdd_MemAlloc(
                                            NVRAM_BRW_NUM_BOOKMARK_TITLE_RECORDS,
                                            NVRAM_BRW_BOOKMARK_TITLE_SIZE);
        g_mmi_brw_cntx.bookmark_url_p =
            (nvram_brw_bkm_url_struct*) jdd_MemAlloc(NVRAM_BRW_NUM_BOOKMARK_URL_RECORDS, NVRAM_BRW_BOOKMARK_URL_SIZE);

        for (record_count = 1; record_count <= NVRAM_BRW_NUM_BOOKMARK_TITLE_RECORDS; record_count++)
        {
            ReadRecord(
                NVRAM_EF_BRW_BOOKMARK_TITLE_LID,
                record_count,
                &g_mmi_brw_cntx.bookmark_title_p[(record_count - 1) * TITLES_PER_RECORD],
                NVRAM_BRW_BOOKMARK_TITLE_SIZE,
                &nvram_error);
        }

        for (record_count = 1; record_count <= NVRAM_BRW_NUM_BOOKMARK_URL_RECORDS; record_count++)
        {
            ReadRecord(
                NVRAM_EF_BRW_BOOKMARK_URL_LID,
                record_count,
                &g_mmi_brw_cntx.bookmark_url_p[(record_count - 1) * URLS_PER_RECORD],
                NVRAM_BRW_BOOKMARK_URL_SIZE,
                &nvram_error);
        }

        mmi_brw_calculate_number_of_bookmarks_stored();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_write_bookmark_to_nvram
 * DESCRIPTION
 *  This function writes bookmark data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_write_bookmark_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 nvram_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read bookmarks from NVRAM if not already read */
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_BOOKMARK_TITLE_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_BOOKMARK_TITLE_LID,
            record_count,
            &g_mmi_brw_cntx.bookmark_title_p[(record_count - 1) * TITLES_PER_RECORD],
            NVRAM_BRW_BOOKMARK_TITLE_SIZE,
            &nvram_error);
    }

    for (record_count = 1; record_count <= NVRAM_BRW_NUM_BOOKMARK_URL_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_BOOKMARK_URL_LID,
            record_count,
            &g_mmi_brw_cntx.bookmark_url_p[(record_count - 1) * URLS_PER_RECORD],
            NVRAM_BRW_BOOKMARK_URL_SIZE,
            &nvram_error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_add_prov_bookmark
 * DESCRIPTION
 *  This function provides external interface to save a bookmark
 * PARAMETERS
 *  bkm_title_p     [?]     [?]     [?]
 *  bkm_url_p       [?]     [?]     [?]
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_brw_add_prov_bookmark(U8 *bkm_title_p, U8 *bkm_url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;
    U8 brw_current_url[MMI_BRW_BKM_MAX_URL_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "Request for save bookmark from external interface : in mmi_brw_add_prov_bookmark");
    mmi_asc_to_ucs2((S8*) brw_current_url, (S8*) bkm_url_p);
    if (mmi_brw_validate_url(brw_current_url) != MMI_TRUE)
    {
        return PROV_BKM_INVALID;
    }
    mmi_brw_read_bookmark_from_nvram();

    /* Bookmark list is full */
    if (g_mmi_brw_cntx.total_bookmark_items >= MMI_BRW_MAX_BOOKMARKS)
    {
        return PROV_BKM_FULL;
    }
    length = mmi_brw_bkm_calculate_strlen_ucs2_flag((PS8) bkm_title_p);
    memset(g_mmi_brw_cntx.brw_current_url, 0, ENCODING_LENGTH);
    length = mmi_ucs2strlen((PS8) brw_current_url);
    if (mmi_brw_check_http_prefix((PS8) brw_current_url) == FALSE)
    {
        mmi_asc_to_ucs2((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) ("http://"));
        length += 7;
        if (length >= MMI_BRW_BKM_MAX_URL_LENGTH)
        {
            length = MMI_BRW_BKM_MAX_URL_LENGTH - 1;
        }

        mmi_ucs2ncat((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) brw_current_url, length - 7);
    }
    else
    {
        if (length >= MMI_BRW_BKM_MAX_URL_LENGTH)
        {
            length = MMI_BRW_BKM_MAX_URL_LENGTH - 1;
        }
        mmi_ucs2ncat((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) brw_current_url, length);
    }
    /* Bookmark is to be added */
    g_mmi_brw_cntx.edit_flag = BRW_STATUS_NO;
    mmi_brw_save_bookmark_item();
    return PROV_BKM_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmark_set_as_homepage
 * DESCRIPTION
 *  This function sets the bookmark url as homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmark_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.brw_current_url,
        (S8*) g_mmi_brw_cntx.bookmark_url_p[g_mmi_brw_cntx.index_highlighted_item].url);

    mmi_brw_set_as_homepage(g_mmi_brw_cntx.brw_current_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_page_url_title_to_bookmark
 * DESCRIPTION
 *  This function saves the current url title string and url string to bookmarklist.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_save_page_url_title_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*  MMI_JDD_UI_WINDOW_INFO_STRUCT *jdd_window_info_struct_p = NULL; */
    JC_UINT32 ui_window_id = 0;
    U16 length = 0;
    U16 title_length = 0;
    JC_PAGE_INFO page_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ui_window_id = mmi_jdd_ui_get_appWindowID(E_TASK_BROWSER_CORE);

    mmi_brw_read_bookmark_from_nvram();
    /* If Bookmark list is full, Dispaly 'Bookmark list is full' */
    if (g_mmi_brw_cntx.total_bookmark_items >= MMI_BRW_MAX_BOOKMARKS)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_BOOKMARK_FULL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);

        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        jdi_BrowserGetCurrentPageInfo(g_mmi_brw_pbrowser_ctxt, &page_info);
        length = mmi_ucs2strlen((PS8) page_info.psUrl);
        if (length >= MMI_BRW_BKM_MAX_URL_LENGTH)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_URL_LEN_EXCEED),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
        }
        else
        {
            title_length = mmi_brw_bkm_calculate_strlen_ucs2_flag((S8*) page_info.psTitle);
            g_mmi_brw_cntx.edit_flag = BRW_STATUS_NO;
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) page_info.psUrl);
            mmi_brw_save_ren_page_to_bookmark();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_ren_page_to_bookmark
 * DESCRIPTION
 *  Function to save the Rendered page URL/Title to bookmark List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_save_ren_page_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_validate_url(g_mmi_brw_cntx.brw_current_url) == MMI_TRUE)
    {
        mmi_brw_save_bookmark_item();
        g_mmi_brw_bkm_add_flag = 1;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_URL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bkm_check_ucs2_flag_and_copy
 * DESCRIPTION
 *  This function gets the ucs2 flag and performs the operation depending on the return value.
 * PARAMETERS
 *  str         [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bkm_check_ucs2_flag_and_copy(S8 *str, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUCS2Flag(str))
    {
        g_mmi_brw_cntx.bookmark_title_p[index].dcs = MMI_BRW_DCS_UCS;
        mmi_ucs2cpy((S8*) (g_mmi_brw_cntx.bookmark_title_p[index].title), (str));
    }
    else
    {
        g_mmi_brw_cntx.bookmark_title_p[index].dcs = MMI_BRW_DCS_ASCII;
        mmi_ucs2_to_asc((S8*) (g_mmi_brw_cntx.bookmark_title_p[index].title), (str));
    }

    mmi_ucs2_to_asc((S8*) (g_mmi_brw_cntx.bookmark_url_p[index].url), (S8*) (g_mmi_brw_cntx.brw_current_url));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bkm_calculate_strlen_ucs2_flag
 * DESCRIPTION
 *  This function gets the ucs2 flag and calculates string length depending on the return value.
 * PARAMETERS
 *  str     [IN]        
 *  index(?)        [IN](?)
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_bkm_calculate_strlen_ucs2_flag(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen(str);
    if (length)
    {
        if (GetUCS2Flag(str))
        {
            if (length > ((MMI_BRW_BKM_MAX_TITLE_LENGTH / 2) - 1))
            {
                length = ((MMI_BRW_BKM_MAX_TITLE_LENGTH / 2) - 1);
            }
        }
        else
        {
            if (length > (MMI_BRW_BKM_MAX_TITLE_LENGTH - 1))
            {
                length = (MMI_BRW_BKM_MAX_TITLE_LENGTH - 1);
            }
        }
        mmi_ucs2ncpy((S8*) g_mmi_brw_cntx.brw_bkm_selected_title, str, length);
    }
    return length;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_http_prefix
 * DESCRIPTION
 *  This function checks whether the url contains http prefix
 * PARAMETERS
 *  url_string      [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_brw_check_http_prefix(PS8 url_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2ncmp((PS8) url_string, (PS8) L"http://", 7) == 0) ||
        (mmi_ucs2ncmp((PS8) url_string, (PS8) L"https://", 8) == 0) ||
        (mmi_ucs2ncmp((PS8) url_string, (PS8) L"HTTP://", 7) == 0) ||
        (mmi_ucs2ncmp((PS8) url_string, (PS8) L"HTTPS://", 8) == 0))
    {
        return TRUE;
    }
    return FALSE;
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#endif /* _MMI_JBROWSERMMIBOOKMARKS_C */ 


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
 * JBrowserMMIRecentPages.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for recent pages implementation.
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
 * removed!
 * removed!
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
#ifndef _MMI_JBROWSERMMIRECENTPAGES_C
#define _MMI_JBROWSERMMIRECENTPAGES_C

/*  Include: MMI header file */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"
#include "browserlayout.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_recent_page_list
 * DESCRIPTION
 *  Entry function for recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_recent_page_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    JC_UINT32 brw_rpl_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserGetHistoryCount(g_mmi_brw_pbrowser_ctxt, &brw_rpl_count);

    /* Display 'Enter Address' if no address history items are present */
    if ((brw_rpl_count) == 0)
    {
        if (GetCurrScrnId() == SCR_ID_BRW_RECENT_PAGES)
        {
            DeleteNHistory(1);
        }
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_BRW_POPUP_TIME, EMPTY_LIST_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_BRW_RECENT_PAGES, NULL, mmi_brw_entry_recent_page_list, NULL);
        gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGES);
        /* SetParentHandler(0); */
        /* RegisterHighlightHandler(ExecuteCurrHiliteHandler); */

        ShowCategory184Screen(
            STR_ID_BRW_RECENT_PAGES,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            0,
            STR_GLOBAL_BACK,
            0,
            brw_rpl_count,
            mmi_brw_recent_pages_list_get_item,
            0,
            0,
            gui_buffer_p);

        SetLeftSoftkeyFunction(mmi_brw_highlighted_recent_page, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_highlighted_recent_page, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of recent pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         [?]         [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_brw_recent_pages_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_URL_HISTORY brw_rpl_list_p = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserGetHistoryByIndex(g_mmi_brw_pbrowser_ctxt, item_index, &brw_rpl_list_p);

    /* Display URL if settings option is set as 'Show history by URL' */
    if (g_mmi_brw_cntx.show_history_as_url)
    {
        mmi_brw_unicode_string_concatenate_dots(str_buff, (S8*) brw_rpl_list_p.pmURL);
    }
    else    /* Display Title if settings option is set as 'Show history by title' */
    {
        if (mmi_ucs2strlen((S8*) brw_rpl_list_p.pmTitle) != 0)
        {
            mmi_brw_unicode_string_concatenate_dots(str_buff, (S8*) brw_rpl_list_p.pmTitle);
        }
        else
        {
            mmi_brw_unicode_string_concatenate_dots(str_buff, (S8*) brw_rpl_list_p.pmURL);
        }
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_highlighted_recent_page
 * DESCRIPTION
 *  Function to get the highlighted item and call appropriate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_highlighted_recent_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.index_highlighted_item = (U8) GetHighlightedItem();
    mmi_brw_entry_recent_page_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_recent_page_options
 * DESCRIPTION
 *  Entry function for recent page options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_recent_page_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_list_of_items[3];
    U8 *gui_buffer_p;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_RECENT_PAGE_OPTIONS, NULL, mmi_brw_entry_recent_page_options, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGE_OPTIONS);

    num_of_items = GetNumOfChild(MENU_ID_BRW_RECENT_PAGE_OPTIONS);
    GetSequenceStringIds(MENU_ID_BRW_RECENT_PAGE_OPTIONS, uc_list_of_items);
    SetParentHandler(MENU_ID_BRW_RECENT_PAGE_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
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
 *  mmi_brw_confirm_delete_recent_page
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected recent page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_delete_recent_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    JC_INT8 unicode_buf[100] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
    {
        EntryNewScreen(SCR_ID_BRW_DELETE_RECENT_PAGE_SCREEN, NULL, NULL, NULL);
        gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGES);
        mmi_ucs2cpy(unicode_buf, GetString(STR_ID_BRW_DELETE_RECENT_PAGE_ENTRY));

        ShowCategory74Screen(
            STR_GLOBAL_DELETE,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (PU8) unicode_buf,
            mmi_ucs2strlen(unicode_buf),
            gui_buffer_p);

        mmi_brw_clear_key_handler(KEY_VOL_UP);
        mmi_brw_clear_key_handler(KEY_VOL_DOWN);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_DELETE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    SetLeftSoftkeyFunction(mmi_brw_delete_recent_page, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_recent_page
 * DESCRIPTION
 *  Deletes the selected recent page from the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_recent_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserClearHistoryByIndex(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cntx.index_highlighted_item);

    jdi_BrowserHistorySave(g_mmi_brw_pbrowser_ctxt);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_BRW_RECENT_PAGES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_confirm_delete_all_recent_pages
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_confirm_delete_all_recent_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 stringID = 0; */
    U8 *gui_buffer_p;
    JC_INT8 unicode_buf[100] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_BRW_JBROWSER_MAIN))
    {
        EntryNewScreen(SCR_ID_BRW_DELETE_RECENT_PAGE_SCREEN, NULL, NULL, NULL);
        gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGES);
        mmi_ucs2cpy(unicode_buf, GetString(STR_ID_BRW_DELETE_ALL_RECENT_PAGE_ENTRY));

        ShowCategory74Screen(
            STR_GLOBAL_DELETE_ALL,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (PU8) unicode_buf,
            mmi_ucs2strlen(unicode_buf),
            gui_buffer_p);
        mmi_brw_clear_key_handler(KEY_VOL_UP);
        mmi_brw_clear_key_handler(KEY_VOL_DOWN);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_DELETE_ALL),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    SetLeftSoftkeyFunction(mmi_brw_delete_all_recent_pages, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_all_recent_pages
 * DESCRIPTION
 *  Deletes the entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_all_recent_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserClearHistory(g_mmi_brw_pbrowser_ctxt);

    jdi_BrowserHistorySave(g_mmi_brw_pbrowser_ctxt);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_BRW_RECENT_PAGES);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_goto_highlighted_recent_page
 * DESCRIPTION
 *  This function fetches the current url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_goto_highlighted_recent_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_URL_HISTORY brw_rpl_list_p = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserGetHistoryByIndex(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cntx.index_highlighted_item, &brw_rpl_list_p);
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
#endif /* 0 */ 
    /* added by tk to set the current fetch url */
    mmi_brw_set_current_url((S8*) brw_rpl_list_p.pmURL);
    /* jdi call to fetch the url */
    mmi_brw_pre_entry_goto_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_unicode_string_concatenate_dots
 * DESCRIPTION
 *  This function concatenates "..." to a string if its length is greater that MAX_SUBMENU_CHARACTERS
 * PARAMETERS
 *  str_buff        [OUT]       
 *  str             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_unicode_string_concatenate_dots(UI_string_type str_buff, S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 pout_buffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(str) > MAX_SUBMENU_CHARACTERS)
    {
        mmi_ucs2ncpy((S8*) str_buff, str, MMI_BRW_MAX_VISIBLE_URL_LENGTH - 1);
        mmi_asc_to_ucs2(pout_buffer, (S8*) "...");
        mmi_ucs2cat((S8*) str_buff, (S8*) pout_buffer);
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, str);
    }
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#endif /* _MMI_JBROWSERMMIRECENTPAGES_C */ 


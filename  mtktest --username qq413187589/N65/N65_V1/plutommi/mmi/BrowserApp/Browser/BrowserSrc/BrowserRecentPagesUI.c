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
 * BrowserRecentPagesUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for UI implementation 
 *   of recent pages.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERRECENTPAGESUI_C
#define MMI_BROWSERRECENTPAGESUI_C


#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserRecentPages.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_highlight_handlers_init
 * DESCRIPTION
 *  This function is used for registering highlight and hint handlers of
 *  recent pages module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_highlight_handlers_init(void)
{
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGES, mmi_brw_recent_pages_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_GOTO, mmi_brw_recent_page_goto_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SORT, mmi_brw_recent_page_sort_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_DELETE, mmi_brw_recent_page_delete_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_DELETE_ALL, mmi_brw_recent_page_delete_all_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SET_AS_HOMEPAGE, mmi_brw_recent_page_set_as_homepage_highlight_hdlr);
#ifdef __MMI_VBOOKMARK__
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_ADD_TO_BOOKMARK, mmi_brw_recent_page_add_to_bmk_highlight_hdlr);
#endif /*__MMI_VBOOKMARK__*/
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SEND_ADDRESS, mmi_brw_recent_page_send_address_highlight_hdlr);

    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_OPEN_HOST, mmi_brw_recent_page_open_host_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SORT_HOST, mmi_brw_recent_page_sort_host_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_DELETE_HOST, mmi_brw_recent_page_delete_host_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_DELETE_ALL_HOST, mmi_brw_recent_page_delete_all_host_highlight_hdlr);

    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SORT_BY_DATE, mmi_brw_recent_page_sort_by_date_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SORT_BY_SITE, mmi_brw_recent_page_sort_by_site_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SORT_BY_LAST_VISITED, mmi_brw_recent_page_sort_by_last_visited_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RECENT_PAGE_SORT_BY_MOST_VISITED, mmi_brw_recent_page_sort_by_most_visited_highlight_hdlr);
}


/****************************************** HIGHLIGHT HANDLERS - START *****************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Recent pages menu item
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_get_recent_pages_list_start_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_pages_get_recent_pages_list_start_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_goto, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_entry_sort_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_pages_entry_sort_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of delete menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_page_delete_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_all_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_all_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_delete_all_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_set_as_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_set_as_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_page_set_as_homepage, KEY_EVENT_UP);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_add_to_bmk_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_add_to_bmk_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_pre_entry_add_to_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_pages_pre_entry_add_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_send_address_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_send_address_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_send_address, KEY_EVENT_UP);
	SetKeyHandler(mmi_brw_recent_pages_send_address, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_open_host_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_open_host_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_page_open_host, KEY_EVENT_UP);
	SetKeyHandler(mmi_brw_recent_page_open_host, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_host_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_host_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_entry_sort_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_pages_entry_sort_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_host_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_host_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_page_delete_host_confirm, KEY_EVENT_UP);
	//SetKeyHandler(mmi_brw_recent_page_delete_host_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_all_host_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_all_host_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_recent_pages_delete_all_host_confirm, KEY_EVENT_UP);
	//SetKeyHandler(mmi_brw_recent_pages_delete_all_host_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_date_highlight_hdlr
 * DESCRIPTION
 *  This func is used for sorting the recent page list by date
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_date_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_recent_page_sort_by_date, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_site_highlight_hdlr
 * DESCRIPTION
 *  This func is used for sorting the recent page list by site
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_site_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_recent_page_sort_by_site, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_last_visited_highlight_hdlr
 * DESCRIPTION
 *  This func is used for sorting the recent page list by last visited
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_last_visited_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_recent_page_sort_by_last_visited, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_most_visited_highlight_hdlr
 * DESCRIPTION
 *  This func is used for sorting the recent page list by most visited
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_most_visited_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_recent_page_sort_by_most_visited, KEY_EVENT_UP);
}
/****************************************** HIGHLIGHT HANDLERS - END *******************************************/


/******************************************* ENTRY FUNCTIONS - START *******************************************/
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
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.list_refresh_flag)
	{
		mmi_brw_recent_pages_get_recent_pages_list_start_req();
		g_brw_cntx.list_refresh_flag = MMI_FALSE;
		return;
	}

	/*if(!g_brw_cntx.recent_page_count)
    {
		if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_EMPTY),
				(U16) IMG_GLOBAL_EMPTY,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
		}
		else
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_NO_HISTORY),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
		}
		return;
	}*/

    EntryNewScreen(SCR_ID_BRW_RECENT_PAGES, NULL, mmi_brw_entry_recent_page_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	DeleteScreenIfPresent(SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS);

    ShowCategory184Screen(
        STR_ID_BRW_RECENT_PAGES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        g_brw_cntx.recent_page_count,
        mmi_brw_recent_pages_list_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_recent_page_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_page_pre_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_brw_recent_pages_GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_pages_GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_recent_page_host_list
 * DESCRIPTION
 *  Entry function for recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_recent_page_host_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.list_refresh_flag)
	{
		mmi_brw_recent_pages_get_recent_pages_list_start_req();
		g_brw_cntx.list_refresh_flag = MMI_FALSE;
		return;
	}

    EntryNewScreen(SCR_ID_BRW_RECENT_PAGES_HOST, NULL, mmi_brw_entry_recent_page_host_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGES_HOST);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    ShowCategory184Screen(
    STR_ID_BRW_RECENT_HOSTS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        g_brw_cntx.recent_page_host_count,
        mmi_brw_recent_pages_host_list_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_recent_page_host_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_page_host_pre_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_brw_recent_pages_GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_recent_pages_GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_entry_options
 * DESCRIPTION
 *  Entry function for recent page options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U8 *guiBuffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_RECENT_PAGE_OPTIONS, NULL, mmi_brw_recent_page_entry_options, NULL);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGE_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
	{
		mmi_frm_hide_menu_item(MENU_ID_BRW_RECENT_PAGE_SORT);
	}
	else
	{
		mmi_frm_unhide_menu_item(MENU_ID_BRW_RECENT_PAGE_SORT);
	}

	num_of_items = GetNumOfChild_Ext(MENU_ID_BRW_RECENT_PAGE_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
	GetSequenceStringIds_Ext(MENU_ID_BRW_RECENT_PAGE_OPTIONS, UC_list_of_items);
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
        UC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	OslMfree(UC_list_of_items);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_host_entry_options
 * DESCRIPTION
 *  Entry function for recent page options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_host_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U8 *guiBuffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS, NULL, mmi_brw_recent_page_host_entry_options, NULL);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	num_of_items = GetNumOfChild(MENU_ID_BRW_RECENT_PAGE_OPTIONS_1);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
	GetSequenceStringIds(MENU_ID_BRW_RECENT_PAGE_OPTIONS_1, UC_list_of_items);
	SetParentHandler(MENU_ID_BRW_RECENT_PAGE_OPTIONS_1);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        UC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	OslMfree(UC_list_of_items);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected recent page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_recent_pages_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete_all_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of entire 
 *  recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete_all_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_recent_pages_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete_all_host_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of entire 
 *  recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete_all_host_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_recent_pages_delete_all_host, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_host_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected recent page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_host_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_recent_page_delete_host, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_entry_sort_options
 * DESCRIPTION
 *  Entry function for Send Address Options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_entry_sort_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U8 *guiBuffer;
    S32 num_of_items;
	U32 hilited_index=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SORT_RECENT_PAGES, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SORT_RECENT_PAGES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    num_of_items = GetNumOfChild(MENU_ID_BRW_RECENT_PAGE_SORT);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_RECENT_PAGE_SORT, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_RECENT_PAGE_SORT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_recent_pages_sorting_method_set_hilite_index(&hilited_index);

    ShowCategory11Screen(
        STR_ID_BRW_SORT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_BRW_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        UC_list_of_items,
        (U16)hilited_index,
        guiBuffer);


	ChangeLeftSoftkey(STR_ID_BRW_SELECT, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	OslMfree(UC_list_of_items);
}
/******************************************** ENTRY FUNCTIONS - END ********************************************/
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERRECENTPAGESUI_C */ 


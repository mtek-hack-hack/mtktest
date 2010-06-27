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
 * BrowserStoredPagesUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for UI implementation 
 *   of stored pages.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERSTOREDPAGESUI_C
#define MMI_BROWSERSTOREDPAGESUI_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "Conversions.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserStoredPages.h"


U8 g_brw_stored_page_size[BRW_STORED_PAGE_PROPERTIES_SIZE_LEN * ENCODING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_highlight_handlers_init
 * DESCRIPTION
 *  Highlight handler of Recent pages menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_highlight_handlers_init(void)
{
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGES, mmi_brw_stored_pages_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_OPEN, mmi_brw_stored_page_open_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_PROPERTIES, mmi_brw_stored_page_properties_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_RENAME, mmi_brw_stored_page_rename_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_DELETE, mmi_brw_stored_page_delete_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_DELETE_ALL, mmi_brw_stored_page_delete_all_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_SET_AS_HOMEPAGE, mmi_brw_stored_page_set_as_homepage_highlight_hdlr);
#ifdef __MMI_VBOOKMARK__
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_ADD_TO_BOOKMARK, mmi_brw_stored_page_add_to_bmk_highlight_hdlr);
#endif /*__MMI_VBOOKMARK__*/
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_SEND_ADDRESS, mmi_brw_stored_page_send_address_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_STORED_PAGE_MEMORY_STATUS, mmi_brw_stored_page_memory_status_highlight_hdlr);
}


/****************************************** HIGHLIGHT HANDLERS - START *****************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Recent pages menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_pages_get_saved_pages_list_start_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_stored_pages_get_saved_pages_list_start_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_open_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_open_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_pages_open, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_properties_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_properties_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_page_pre_entry_page_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_stored_page_pre_entry_page_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_rename_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_rename_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_page_entry_rename, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_delete_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of delete menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_page_delete_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_delete_all_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_delete_all_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_pages_delete_all_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_set_as_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_set_as_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_page_set_as_homepage, KEY_EVENT_UP);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_add_to_bmk_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_add_to_bmk_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_pages_add_to_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_stored_pages_add_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_send_address_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_send_address_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_pages_send_address, KEY_EVENT_UP);
	SetKeyHandler(mmi_brw_stored_pages_send_address, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_memory_status_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_memory_status_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_page_memory_status, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_rename_editor_done_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_rename_editor_done_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_stored_page_rename_confirm, KEY_EVENT_UP);
}
/****************************************** HIGHLIGHT HANDLERS - END *******************************************/


/******************************************* ENTRY FUNCTIONS - START *******************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_stored_page_list
 * DESCRIPTION
 *  Entry function for stored page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_stored_page_list(void)
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
		mmi_brw_stored_pages_get_saved_pages_list_start_req();
		g_brw_cntx.list_refresh_flag = MMI_FALSE;
		return;
	}

    EntryNewScreen(SCR_ID_BRW_STORED_PAGES, NULL, mmi_brw_entry_stored_page_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_STORED_PAGES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    ShowCategory184Screen(
        STR_ID_BRW_STORED_PAGES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        g_brw_cntx.dynamic_list_count,
        mmi_brw_stored_pages_list_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_stored_page_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_stored_page_pre_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_entry_options
 * DESCRIPTION
 *  Entry function for stored page options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_entry_options(void)
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
    EntryNewScreen(SCR_ID_BRW_STORED_PAGE_OPTIONS, NULL, mmi_brw_stored_page_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_STORED_PAGE_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	/*hiding the memory status menu item for stored pages*/
	mmi_frm_hide_menu_item(MENU_ID_BRW_STORED_PAGE_MEMORY_STATUS);

    num_of_items = GetNumOfChild_Ext(MENU_ID_BRW_STORED_PAGE_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds_Ext(MENU_ID_BRW_STORED_PAGE_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_STORED_PAGE_OPTIONS);
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
 *  mmi_brw_stored_page_delete_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_delete_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_stored_pages_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_delete_all_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of entire stored page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_delete_all_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_stored_pages_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_entry_rename
 * DESCRIPTION
 *  Entry function for full screen editor to rename stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_entry_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_STORED_PAGE_RENAME, NULL, mmi_brw_stored_page_entry_rename, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_STORED_PAGE_RENAME);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_title, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.saved_page_properties_p->label);
	}

    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_DONE, mmi_brw_stored_page_rename_editor_done_option_highlight_hdlr);

    ShowCategory215Screen(
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_brw_current_title,
        BRW_MAX_TITLE_LENGTH+1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_editor_entry_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/******************************************** ENTRY FUNCTIONS - END ********************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_rename_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_rename_confirm(void)
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
        get_string(STR_ID_BRW_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_stored_page_rename, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSTOREDPAGESUI_C */ 


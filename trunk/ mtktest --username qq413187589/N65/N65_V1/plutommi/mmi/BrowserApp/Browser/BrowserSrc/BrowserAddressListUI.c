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
 * BrowserAddressListUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for UI implementation 
 *   of browser address list.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERADDRESSLISTUI_C
#define MMI_BROWSERADDRESSLISTUI_C


#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserAddressList.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_highlight_handlers_init
 * DESCRIPTION
 *  This function is used for registering highlight and hint handlers of
 *  enter address module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_highlight_handlers_init(void)
{
    SetHiliteHandler(MENU_ID_BRW_ENTER_ADDRESS, mmi_brw_address_list_highlight_hdlr);
	SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_GOTO, mmi_brw_address_list_goto_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_EDIT, mmi_brw_address_list_edit_highlight_hdlr);
	SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_SET_AS_HOMEPAGE, mmi_brw_address_list_set_as_homepage_highlight_hdlr);
#ifdef __MMI_VBOOKMARK__
	SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_ADD_TO_BOOKMARK, mmi_brw_address_list_add_to_bmk_highlight_hdlr);
#endif /*__MMI_VBOOKMARK__*/
	SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_SEND_ADDRESS, mmi_brw_address_list_send_address_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_DELETE, mmi_brw_address_list_delete_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_ENTER_ADR_DELETE_ALL, mmi_brw_address_list_delete_all_highlight_hdlr);
}


/****************************************** HIGHLIGHT HANDLERS - START *****************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_scr_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the enter address screen
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_scr_highlight_hdlr(S32 index)
{
	g_brw_cntx.index_highlighted_item = index;

	if(index == 0)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_brw_address_list_pre_entry_enter_url, KEY_EVENT_UP);
	}
	else
	{
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_brw_address_list_entry_options, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_address_list_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of enter address menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_pre_entry_address_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_pre_entry_address_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *   _menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address Goto Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_goto, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_edit_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address Goto Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_edit_item, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_set_as_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address set as homepage Menu item.
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_set_as_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_set_as_homepage, KEY_EVENT_UP);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_add_to_bmk_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address Add To BookMarks Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_add_to_bmk_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_pre_entry_add_to_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_address_list_pre_entry_add_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_send_address_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address to send the URL to some other device
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_send_address_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_pre_entry_send_address, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_address_list_pre_entry_send_address, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_delete_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address Delete Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_delete_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_delete_all_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_delete_all_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_delete_all_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_enter_url_editor_done_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_enter_url_editor_done_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_address_list_add_item, KEY_EVENT_UP);
}
/****************************************** HIGHLIGHT HANDLERS - END *******************************************/


/******************************************* ENTRY FUNCTIONS - START *******************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_address_list
 * DESCRIPTION
 *  Entry function for enter address menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_address_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 highlight_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ENTER_ADDRESS, NULL, mmi_brw_entry_address_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ENTER_ADDRESS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    if (mmi_brw_address_list_get_hiliter_flag() && guiBuffer != NULL && guiBuffer[2] != 0)
    {
        guiBuffer = NULL;
        mmi_brw_address_list_set_hiliter_flag(MMI_FALSE);
        highlight_index = 1;
    }
    
	RegisterHighlightHandler(mmi_brw_address_list_scr_highlight_hdlr);

    ShowCategory184Screen(
        STR_ID_BRW_ENTER_ADDRESS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        g_brw_cntx.total_address_list_items + 1,
        mmi_brw_address_list_get_item,
        0,
        highlight_index,
        guiBuffer);


    SetRightSoftkeyFunction(mmi_brw_address_list_GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_address_list_GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_entry_options
 * DESCRIPTION
 *  Entry function for Enter Address Options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_entry_options(void)
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
    EntryNewScreen(SCR_ID_BRW_ENTER_ADDRESS_OPTIONS, NULL, mmi_brw_address_list_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ENTER_ADDRESS_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    num_of_items = GetNumOfChild(MENU_ID_BRW_ENTER_ADR_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_ENTER_ADR_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_ENTER_ADR_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
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

	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	OslMfree(UC_list_of_items);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_entry_enter_url
 * DESCRIPTION
 *  Entry function for full screen editor to enter the url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_entry_enter_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ENTER_URL, NULL, mmi_brw_address_list_entry_enter_url, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ENTER_URL);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_DONE, mmi_brw_address_list_enter_url_editor_done_option_highlight_hdlr);

    ShowCategory5Screen(
        STR_ID_BRW_ENTER_ADDRESS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (U8*) g_brw_hist_selected_url,
        BRW_ADDRESS_LIST_URL_LENGTH,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_editor_entry_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_delete_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_delete_confirm(void)
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
        get_string(STR_ID_BRW_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_address_list_delete_item, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_delete_all_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  enter address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_delete_all_confirm(void)
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
        get_string(STR_ID_BRW_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_address_list_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/******************************************** ENTRY FUNCTIONS - END ********************************************/
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERADDRESSLISTUI_C */ 


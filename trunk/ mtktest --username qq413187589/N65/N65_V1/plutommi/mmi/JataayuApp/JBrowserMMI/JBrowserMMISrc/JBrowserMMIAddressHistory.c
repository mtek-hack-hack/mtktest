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
 * JBrowserMMIAddressHistory.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for address history implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_JBROWSERMMIADDRESSHISTORY_C
#define _MMI_JBROWSERMMIADDRESSHISTORY_C

/*  Include: MMI header file */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"
#include "browserlayout.h"
#include "PhoneBookGprot.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_enter_address
 * DESCRIPTION
 *  Entry function for enter address menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_enter_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p = NULL;
    U8 highlight_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read address history list from NVRAM if not already read */
    if ((g_mmi_brw_cntx.address_history_title_p == NULL) && (g_mmi_brw_cntx.address_history_url_p == NULL))
    {
        g_mmi_brw_cntx.address_history_title_p =
            (nvram_brw_hist_title_struct*) jdd_MemAlloc(
                                            NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS,
                                            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE);
        g_mmi_brw_cntx.address_history_url_p =
            (nvram_brw_hist_url_struct*) jdd_MemAlloc(
                                            NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS,
                                            NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE);

        mmi_brw_read_enter_address_from_nvram();
        /* Calculate the number of entries */
        mmi_brw_calculate_number_of_address_history_items_stored();
    }

    /* Open editor if no entries are present */
    if (g_mmi_brw_cntx.total_address_history_items == 0)
    {
        mmi_asc_to_ucs2((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) ("http://"));
        mmi_brw_entry_enter_url();
    }
    else
    {
        EntryNewScreen(SCR_ID_BRW_ENTER_ADDRESS, NULL, mmi_brw_entry_enter_address, NULL);
        gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_ENTER_ADDRESS);
        if (g_mmi_brw_cntx.enter_add_hist_flag) /* && gui_buffer_p != NULL && gui_buffer_p[2] != 0 */
        {
            gui_buffer_p = NULL;
            g_mmi_brw_cntx.enter_add_hist_flag = 0;
            highlight_index = 1;
        }

        RegisterHighlightHandler(mmi_brw_enter_address_scr_highlight_hdlr);

        ShowCategory184Screen(
            STR_ID_BRW_ENTER_ADDRESS,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            g_mmi_brw_cntx.total_address_history_items + 1,
            mmi_brw_address_history_list_get_item,
            0,
            highlight_index,
            gui_buffer_p);

        SetLeftSoftkeyFunction(mmi_brw_hist_highlighted_item, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_hist_highlighted_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_enter_address_scr_highlight_hdlr
 * DESCRIPTION
 *  --
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_enter_address_scr_highlight_hdlr(S32 index)
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
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_calculate_number_of_address_history_items_stored
 * DESCRIPTION
 *  Function to calculate the total number of address history items stored
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_calculate_number_of_address_history_items_stored(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 history_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (history_count = 0; history_count < MMI_BRW_MAX_ADDRESS_HISTORY; history_count++)
    {
        if ((strlen((S8*) g_mmi_brw_cntx.address_history_url_p[history_count].url)) == 0)
        {
            break;
        }

        g_mmi_brw_cntx.total_address_history_items++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_history_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of address history
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_brw_address_history_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MMI_BRW_MAX_ADDRESS_HISTORY))
    {
        return FALSE;
    }

    if (item_index == 0)
    {
        mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_BRW_ENTER_ADDRESS));
    }
    else
    {
        /* Display title if settings option is 'Show history by title' */
        if (g_mmi_brw_cntx.show_history_as_url)
        {
            mmi_brw_ansii_string_concatenate_dots(
                str_buff,
                (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - item_index].url);
        }
        else
        {
            if ((g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - item_index].dcs ==
                 MMI_BRW_DCS_ASCII) &&
                (strlen
                 ((S8*) g_mmi_brw_cntx.
                  address_history_title_p[g_mmi_brw_cntx.total_address_history_items - item_index].title) != 0))
            {
                mmi_asc_to_ucs2(
                    (S8*) str_buff,
                    (S8*) g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - item_index].title);

            }
            else if ((g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - item_index].
                      dcs == MMI_BRW_DCS_UCS) &&
                     (mmi_ucs2strlen
                      ((S8*) g_mmi_brw_cntx.
                       address_history_title_p[g_mmi_brw_cntx.total_address_history_items - item_index].title) != 0))
            {
                mmi_ucs2cpy(
                    (S8*) str_buff,
                    (S8*) g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - item_index].title);
            }
            else
            {
                mmi_brw_ansii_string_concatenate_dots(
                    str_buff,
                    (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - item_index].url);
            }
        }
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_hist_highlighted_item
 * DESCRIPTION
 *  Function to get the highlighted item and call appropriate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_hist_highlighted_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.index_highlighted_item = (U8) GetHighlightedItem();

    if (g_mmi_brw_cntx.index_highlighted_item == 0)
    {
        /* open the editor to enter the url */
        memset(g_mmi_brw_cntx.brw_bkm_selected_title, 0, ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) ("http://"));
        mmi_brw_entry_enter_url();
    }
    else
    {
        mmi_brw_entry_enter_address_options();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_enter_address_options
 * DESCRIPTION
 *  Entry function for Enter Address Options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_enter_address_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_list_of_items[5];
    U8 *gui_buffer_p;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ENTER_ADDRESS_OPTIONS, NULL, mmi_brw_entry_enter_address_options, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_ENTER_ADDRESS_OPTIONS);

    num_of_items = GetNumOfChild(MENU_ID_BRW_ENTER_ADR_OPTIONS);
    GetSequenceStringIds(MENU_ID_BRW_ENTER_ADR_OPTIONS, uc_list_of_items);
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
        uc_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer_p);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_enter_url
 * DESCRIPTION
 *  Entry function for full screen editor to enter the url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_enter_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ENTER_URL, NULL, mmi_brw_entry_enter_url, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_ENTER_URL);

    ShowCategory5Screen(
        STR_ID_BRW_ENTER_ADDRESS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (U8*) g_mmi_brw_cntx.brw_current_url,
        MMI_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_brw_add_address_history_item, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_add_address_history_item
 * DESCRIPTION
 *  Function to add new item to the address history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_add_address_history_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S8 url_string[NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH];
    S8 title_string[NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_brw_validate_url(g_mmi_brw_cntx.brw_current_url) == MMI_TRUE)
    {
        g_mmi_brw_cntx.enter_add_hist_flag = 1;

        mmi_brw_set_current_url((S8*) g_mmi_brw_cntx.brw_current_url);
        mmi_brw_pre_entry_goto_url();
        mmi_ucs2_to_asc((S8*) url_string, (S8*) g_mmi_brw_cntx.brw_current_url);
        /* Check if URL already exists. If exists then do not add this URL to the list. */
        for (count = 0; count < g_mmi_brw_cntx.total_address_history_items; ++count)
        {
            if (strcmp((S8*) url_string, (S8*) g_mmi_brw_cntx.address_history_url_p[count].url) == 0)
            {
                mmi_brw_check_dcs_flag((S8*) title_string, count);
                mmi_brw_shift_elements(count);
                mmi_brw_check_ucs2_flag((S8*) title_string);
                strcpy(
                    (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - 1].url,
                    (S8*) url_string);
                mmi_brw_write_enter_address_to_nvram();
                DeleteScreenIfPresent(SCR_ID_BRW_ENTER_URL);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Url already exists in the list!");
                return;
            }
        }
        if (count < MMI_BRW_MAX_ADDRESS_HISTORY)
        {
            g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items].dcs = MMI_BRW_DCS_ASCII;
            mmi_ucs2_to_asc(
                (S8*) g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items].title,
                (S8*) g_mmi_brw_cntx.brw_bkm_selected_title);
            strcpy(
                (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items].url,
                (S8*) url_string);
            g_mmi_brw_cntx.total_address_history_items++;
        }
        else
        {
            mmi_brw_shift_elements(0);
        }
        g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1].dcs = MMI_BRW_DCS_ASCII;
        mmi_ucs2_to_asc(
            (S8*) g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1].title,
            (S8*) g_mmi_brw_cntx.brw_bkm_selected_title);
        strcpy(
            (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - 1].url,
            (S8*) url_string);
        mmi_brw_write_enter_address_to_nvram();
        DeleteScreenIfPresent(SCR_ID_BRW_ENTER_URL);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_URL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_update_address_history_list
 * DESCRIPTION
 *  Function to update the address history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_update_address_history_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_cntx.enter_add_hist_flag = 1;
    /* EnterAddressOption Screen should not into history when we try to fetch url from
       Enter Address list. */
    ClearExitHandler();

    mmi_brw_check_dcs_flag(
        (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
        ((U8) (g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item)));
    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.brw_current_url,
        (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item].url);

    /* added by tk to set the current fetch url */
    mmi_brw_set_current_url((S8*) g_mmi_brw_cntx.brw_current_url);
    mmi_brw_pre_entry_goto_url();
    mmi_brw_shift_elements((U8) (g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item));
    mmi_brw_check_ucs2_flag((S8*) g_mmi_brw_cntx.brw_bkm_selected_title);
    mmi_ucs2_to_asc(
        (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - 1].url,
        (S8*) g_mmi_brw_cntx.brw_current_url);
    mmi_brw_write_enter_address_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_page_title_to_nvram
 * DESCRIPTION
 *  Function to save title in NVRAM.
 * PARAMETERS
 *  title_p     [?]     [?]     [?]     title to be saved
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_save_page_title_to_nvram(U8 *title_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 nvram_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_check_ucs2_flag((S8*) title_p);

    /* Only Title needs to be updated */
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_mmi_brw_cntx.address_history_title_p[(record_count - 1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &nvram_error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_enter_address_delete_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_enter_address_delete_confirm(void)
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
        get_string(STR_ID_BRW_ENTER_ADR_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_delete_enter_address, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_enter_address
 * DESCRIPTION
 *  Delete the selected enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_enter_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_shift_elements((U8) (g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item));
    /* Set the last bookmark item as 0 */
    memset(&g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1], 0, ENCODING_LENGTH);
    memset(&g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - 1], 0, ENCODING_LENGTH);

    mmi_brw_write_enter_address_to_nvram();

    g_mmi_brw_cntx.total_address_history_items--;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    if (g_mmi_brw_cntx.total_address_history_items > 0)
    {
        DeleteUptoScrID(SCR_ID_BRW_ENTER_ADDRESS);
    }
    else
    {
        DeleteNHistory(2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_write_enter_address_to_nvram
 * DESCRIPTION
 *  This function writes enter address url/title data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_write_enter_address_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 record_count;
    S16 nvram_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_mmi_brw_cntx.address_history_title_p[(record_count - 1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &nvram_error);
    }

    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
            record_count,
            &g_mmi_brw_cntx.address_history_url_p[(record_count - 1) * URLS_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE,
            &nvram_error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_read_enter_address_from_nvram
 * DESCRIPTION
 *  This function reads enter address url/title data from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_read_enter_address_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 record_count;
    S16 nvram_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_mmi_brw_cntx.address_history_title_p[(record_count - 1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &nvram_error);
    }

    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
            record_count,
            &g_mmi_brw_cntx.address_history_url_p[(record_count - 1) * URLS_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE,
            &nvram_error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_enter_address_delete_all_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of enter address url List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_enter_address_delete_all_confirm(void)
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
        get_string(STR_ID_BRW_ENTER_ADR_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_setting_delete_history_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_add_enter_address_bookmark
 * DESCRIPTION
 *  Pre Entry function for Enter Address Add To Bookmarks screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_add_enter_address_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = strlen((PS8) g_mmi_brw_cntx.
                    address_history_url_p[g_mmi_brw_cntx.total_address_history_items -
                                          g_mmi_brw_cntx.index_highlighted_item].url);
    /* Fill the bookmark list. */
    mmi_brw_read_bookmark_from_nvram();

    if (length >= MMI_BRW_BKM_MAX_URL_LENGTH)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_URL_LEN_EXCEED), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    else if (g_mmi_brw_cntx.total_bookmark_items >= MMI_BRW_MAX_BOOKMARKS)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_BOOKMARK_FULL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);

        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        mmi_brw_check_dcs_flag(
            (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
            ((U8) (g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item)));
        mmi_asc_to_ucs2(
            (S8*) g_mmi_brw_cntx.brw_current_url,
            (S8*) g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item].url);
        /* Set edit flag */
        g_mmi_brw_cntx.edit_flag = BRW_STATUS_FROM_ENTER_ADDRESS;

        mmi_brw_entry_add_bookmark_screen_for_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_enter_address_edit_menu
 * DESCRIPTION
 *  Entry function for Enter Address Edit Menu Item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_enter_address_edit_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the editor to enter the url */
    memset(g_mmi_brw_cntx.brw_bkm_selected_title, 0, ENCODING_LENGTH);
    mmi_asc_to_ucs2(
        (S8*) g_mmi_brw_cntx.brw_current_url,
        (S8*) & g_mmi_brw_cntx.address_history_url_p[g_mmi_brw_cntx.total_address_history_items - g_mmi_brw_cntx.index_highlighted_item]);
    /* EnterAddressOption Screen should not into history when we try to fetch url from
       Enter Address list. */
    ClearExitHandler();
    mmi_brw_entry_enter_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_delete_history_all
 * DESCRIPTION
 *  Deletes the Browser Setting History(Enter address list)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_delete_history_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(
        g_mmi_brw_cntx.address_history_title_p,
        0,
        NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS);
    memset(
        g_mmi_brw_cntx.address_history_url_p,
        0,
        NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS);

    mmi_brw_write_enter_address_to_nvram();
    /* Free memory allocated to address history title */
    if (g_mmi_brw_cntx.address_history_title_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_cntx.address_history_title_p);
        g_mmi_brw_cntx.address_history_title_p = NULL;
    }

    /* Free memory allocated to address history url */
    if (g_mmi_brw_cntx.address_history_url_p != NULL)
    {
        jdd_MemFree(g_mmi_brw_cntx.address_history_url_p);
        g_mmi_brw_cntx.address_history_url_p = NULL;
    }

    g_mmi_brw_cntx.total_address_history_items = 0;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, MMI_BRW_POPUP_TIME, SUCCESS_TONE);

    DeleteNHistory(2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ansii_string_concatenate_dots
 * DESCRIPTION
 *  This function concatenates "..." to a string if its length is greater that MAX_SUBMENU_CHARACTERS
 * PARAMETERS
 *  str_buff        [OUT]       
 *  str             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ansii_string_concatenate_dots(UI_string_type str_buff, S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 pout_buffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(str) > MAX_SUBMENU_CHARACTERS)
    {
        mmi_asc_n_to_ucs2((S8*) str_buff, (S8*) str, MMI_BRW_MAX_VISIBLE_URL_LENGTH);
        str_buff[MMI_BRW_MAX_VISIBLE_URL_LENGTH] = '\0';
        mmi_asc_to_ucs2(pout_buffer, (S8*) "...");
        mmi_ucs2cat((S8*) str_buff, (S8*) pout_buffer);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) str_buff, str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_ucs2_flag
 * DESCRIPTION
 *  This function gets the ucs2 flag and performs the operation depending on the return value.
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_check_ucs2_flag(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUCS2Flag(str))
    {
        g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1].dcs = MMI_BRW_DCS_UCS;
        mmi_ucs2cpy(
            (S8*) g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1].title,
            str);
    }
    else
    {
        g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1].dcs = MMI_BRW_DCS_ASCII;
        mmi_ucs2_to_asc(
            (S8*) g_mmi_brw_cntx.address_history_title_p[g_mmi_brw_cntx.total_address_history_items - 1].title,
            str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_dcs_flag
 * DESCRIPTION
 *  This function checks the dcs flag and performs the operation depending on the return value.
 * PARAMETERS
 *  str         [IN]        
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_check_dcs_flag(S8 *str, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.address_history_title_p[index].dcs == MMI_BRW_DCS_UCS)
    {
        mmi_ucs2cpy((S8*) str, (S8*) g_mmi_brw_cntx.address_history_title_p[index].title);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) str, (S8*) g_mmi_brw_cntx.address_history_title_p[index].title);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_shift_elements
 * DESCRIPTION
 *  This function shifts the address history titles and urls
 * PARAMETERS
 *  start_pnt       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_shift_elements(U8 start_pnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = start_pnt; count < g_mmi_brw_cntx.total_address_history_items - 1; ++count)
    {
        memcpy(
            &g_mmi_brw_cntx.address_history_title_p[count],
            &g_mmi_brw_cntx.address_history_title_p[count + 1],
            sizeof(g_mmi_brw_cntx.address_history_title_p[count]));
        memcpy(
            &g_mmi_brw_cntx.address_history_url_p[count],
            &g_mmi_brw_cntx.address_history_url_p[count + 1],
            sizeof(g_mmi_brw_cntx.address_history_url_p[count]));
    }
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#endif /* _MMI_JBROWSERMMIADDRESSHISTORY_C */ 


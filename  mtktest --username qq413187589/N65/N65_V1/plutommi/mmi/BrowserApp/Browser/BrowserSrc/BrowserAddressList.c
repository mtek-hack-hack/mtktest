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
 * BrowserAddressList.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for logical implementation 
 *   of browser address list.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERADDRESSLIST_C
#define MMI_BROWSERADDRESSLIST_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserAddressList.h"


U8 g_brw_hist_selected_title[(BRW_ADDRESS_LIST_TITLE_LENGTH) * ENCODING_LENGTH];
U8 g_brw_hist_selected_url[(BRW_ADDRESS_LIST_URL_LENGTH) * ENCODING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_count_number_of_stored_items
 * DESCRIPTION
 *  Function to calculate the total number of address history items stored
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_count_number_of_stored_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 history_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.total_address_list_items = 0;

    for (history_count = 0; history_count < BRW_ADDRESS_LIST_MAX_ITEMS; history_count++)
    {
        if ((strlen((S8*) g_brw_cntx.address_list_title_p[history_count].title)) == 0)
        {
            /* If both title and url are '0' exit the loop */
            if ((strlen((S8*) g_brw_cntx.address_list_url_p[history_count].url)) == 0)
            {
                break;
            }
        }

        g_brw_cntx.total_address_list_items++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of address list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_address_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 pOutBuffer[8];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= BRW_ADDRESS_LIST_MAX_ITEMS));

    if (item_index == 0)
    {
        mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_BRW_ENTER_ADDRESS));
    }
    else
    {
			/* truncate the URL to 38 charactes and append three '.'(dots) if the length of URL exceeds 
			   MAX_SUBMENU_CHARACTERS charactes */
			if (strlen((S8*) g_brw_cntx.address_list_url_p[item_index - 1].url) > MAX_SUBMENU_CHARACTERS)
			{
				mmi_asc_n_to_ucs2(
					(S8*) str_buff,
					(S8*) g_brw_cntx.address_list_url_p[item_index - 1].url,
					BRW_MAX_VISIBLE_URL_LENGTH);
				str_buff[BRW_MAX_VISIBLE_URL_LENGTH] = '\0';
				mmi_asc_to_ucs2((S8*)pOutBuffer, (S8*) "...");
				mmi_ucs2cat((S8*) str_buff, (S8*) pOutBuffer);
			}
			else
			{
				mmi_asc_to_ucs2((S8*) str_buff, (S8*) g_brw_cntx.address_list_url_p[item_index - 1].url);
			}
		}

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_add_item
 * DESCRIPTION
 *  Function to add new item to the address history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_add_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hist_count;
	S8 url_string[NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_brw_validate_url(g_brw_hist_selected_url) < 0)
    {
        DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		DeleteUptoScrID(SCR_ID_BRW_ENTER_URL);
		/*if(IsScreenPresent(SCR_ID_BRW_ENTER_ADDRESS))
		{
		    DeleteUptoScrID(SCR_ID_BRW_ENTER_ADDRESS);
		}
		else
		{
			DeleteNScrId(SCR_ID_BRW_ENTER_URL);
		}*/
		return;
    }

    g_brw_cntx.address_list_flag = MMI_TRUE;

    mmi_ucs2cpy((S8*) g_brw_current_url, (S8*) g_brw_hist_selected_url);
    mmi_brw_pre_entry_goto_url();/* fetch the url */

	mmi_brw_address_list_set_hiliter_flag(MMI_TRUE);

	if(IsScreenPresent(SCR_ID_BRW_ENTER_ADDRESS))
	{
	DeleteUptoScrID(SCR_ID_BRW_ENTER_ADDRESS);
	}
	else
	{
		DeleteNScrId(SCR_ID_BRW_ENTER_URL);
	}

	/* Check if URL already exists. If exists then do not add this URL to the list */
	for (hist_count = 0; hist_count < g_brw_cntx.total_address_list_items; ++hist_count)
    {
		mmi_asc_to_ucs2((S8*) url_string,
			(S8*)&g_brw_cntx.address_list_url_p[hist_count].url );

		if (!mmi_ucs2cmp((S8 *)g_brw_hist_selected_url, (S8 *)url_string))
		{
			mmi_brw_address_list_set_item_at_top(hist_count);
			mmi_brw_address_list_write_list_to_nvram();
			return;
		}
	}

	if (!g_brw_cntx.total_address_list_items)
	{
		g_brw_cntx.address_list_title_p[0].dcs = BRW_DCS_ASCII;
		strcpy((S8*) g_brw_cntx.address_list_title_p[0].title, (S8*) "");
		mmi_ucs2_to_asc((S8*) g_brw_cntx.address_list_url_p[0].url, (S8*) g_brw_hist_selected_url);
	}
    else
    {
        for (hist_count = g_brw_cntx.total_address_list_items; hist_count >= 1; hist_count--)
        {
            if (hist_count < BRW_ADDRESS_LIST_MAX_ITEMS)
            {
                memcpy(
                    &g_brw_cntx.address_list_title_p[hist_count],
                    &g_brw_cntx.address_list_title_p[hist_count - 1],
                    sizeof(g_brw_cntx.address_list_title_p[hist_count]));
                memcpy(
                    &g_brw_cntx.address_list_url_p[hist_count],
                    &g_brw_cntx.address_list_url_p[hist_count - 1],
                    sizeof(g_brw_cntx.address_list_url_p[hist_count]));
            }
        }

        g_brw_cntx.address_list_title_p[0].dcs = BRW_DCS_ASCII;
		strcpy((S8*) g_brw_cntx.address_list_title_p[0].title, (S8*) "");
        mmi_ucs2_to_asc((S8*) g_brw_cntx.address_list_url_p[0].url, (S8*) g_brw_hist_selected_url);
    }

	mmi_brw_address_list_write_list_to_nvram();

    if (g_brw_cntx.total_address_list_items < BRW_ADDRESS_LIST_MAX_ITEMS)
    {
        g_brw_cntx.total_address_list_items++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_goto
 * DESCRIPTION
 *  Function to update the address history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 hist_count;
    //U16 record_count;
    //S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_cntx.address_list_flag = MMI_TRUE;
    mmi_brw_address_list_set_hiliter_flag(MMI_TRUE);
	/* EnterAddressOption Screen should not into history when we try to fetch url from
	Enter Address list. */
	ClearExitHandler();

    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) g_brw_cntx.address_list_url_p[g_brw_cntx.index_highlighted_item - 1].url);
    mmi_brw_pre_entry_goto_url();

	mmi_brw_address_list_set_item_at_top(g_brw_cntx.index_highlighted_item - 1);
	mmi_brw_address_list_write_list_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_update_title_to_nvram
 * DESCRIPTION
 *  Function to save title in NVRAM.
 * PARAMETERS
 *  title_p     [?]     title to be saved
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_update_title_to_nvram(U8 *title_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUCS2Flag((S8*)title_p))
    {
        g_brw_cntx.address_list_title_p[0].dcs = BRW_DCS_UCS;
        mmi_ucs2cpy((S8*) g_brw_cntx.address_list_title_p[0].title, (S8*)title_p);
    }
    else
    {
        g_brw_cntx.address_list_title_p[0].dcs = BRW_DCS_ASCII;
        mmi_ucs2_to_asc((S8*) g_brw_cntx.address_list_title_p[0].title, (S8*)title_p);
    }

    /* Only Title needs to be updated */
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_brw_cntx.address_list_title_p[(record_count - 1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &NvramError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_delete_item 
 * DESCRIPTION
 *  Delete the selected enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_delete_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = g_brw_cntx.index_highlighted_item - 1; count < g_brw_cntx.total_address_list_items - 1; ++count)
    {
        memcpy(
            &g_brw_cntx.address_list_title_p[count],
            &g_brw_cntx.address_list_title_p[count + 1],
            sizeof(g_brw_cntx.address_list_title_p[count]));
        memcpy(
            &g_brw_cntx.address_list_url_p[count],
            &g_brw_cntx.address_list_url_p[count + 1],
            sizeof(g_brw_cntx.address_list_url_p[count]));
    }

    memset(
        &g_brw_cntx.address_list_title_p[g_brw_cntx.total_address_list_items - 1],
        0,
        sizeof(g_brw_cntx.address_list_title_p[g_brw_cntx.total_address_list_items - 1]));
    memset(
        &g_brw_cntx.address_list_url_p[g_brw_cntx.total_address_list_items - 1],
        0,
        sizeof(g_brw_cntx.address_list_url_p[g_brw_cntx.total_address_list_items - 1]));

    mmi_brw_address_list_write_list_to_nvram();

    g_brw_cntx.total_address_list_items--;

    DisplayPopup(
		(PU8) GetString(STR_GLOBAL_DONE), 
		IMG_GLOBAL_ACTIVATED, 
		1, 
		UI_POPUP_NOTIFYDURATION_TIME, 
		SUCCESS_TONE);

	if (g_brw_cntx.total_address_list_items > 0)
	{
		DeleteUptoScrID(SCR_ID_BRW_ENTER_ADDRESS);
	}
	else
	{
		DeleteNScrId(SCR_ID_BRW_ENTER_ADDRESS);
	}
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_pre_entry_add_to_bookmark
 * DESCRIPTION
 *  Pre Entry function for Enter Address Add To Bookmarks screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_pre_entry_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 url[NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH * ENCODING_LENGTH];
	S8 title[NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memcpy(
		&title,
		&g_brw_cntx.address_list_title_p[g_brw_cntx.index_highlighted_item - 1].title,
		sizeof(g_brw_cntx.address_list_title_p[g_brw_cntx.index_highlighted_item - 1].title));
	memcpy(
		&url,
		&g_brw_cntx.address_list_url_p[g_brw_cntx.index_highlighted_item - 1].url,
		sizeof(g_brw_cntx.address_list_url_p[g_brw_cntx.index_highlighted_item - 1].url));

    if (g_brw_cntx.address_list_title_p[g_brw_cntx.index_highlighted_item - 1].dcs == BRW_DCS_UCS)
    {
        mmi_ucs2cpy((S8*)g_brw_current_title, (S8*)title);
    }
    else
    {
	    mmi_asc_to_ucs2((S8*) g_brw_current_title, (S8*) title);
    }

	mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) url);

	mmi_brw_bookmarks_add_to_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_write_list_to_nvram
 * DESCRIPTION
 *  This function writes enter address url/title data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_write_list_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_brw_cntx.address_list_title_p[(record_count-1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &NvramError);
    }

    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
            record_count,
            &g_brw_cntx.address_list_url_p[(record_count-1) * URLS_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE,
            &NvramError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_read_list_from_nvram
 * DESCRIPTION
 *  This function writes enter address url/title data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_read_list_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_brw_cntx.address_list_title_p[(record_count-1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &NvramError);
    }

    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
            record_count,
            &g_brw_cntx.address_list_url_p[(record_count-1) * URLS_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE,
            &NvramError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_edit_item
 * DESCRIPTION
 *  Entry function for Enter Address Edit Menu Item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_edit_item(void)
{
	/* Open the editor to enter the url */
    mmi_asc_to_ucs2((S8*) g_brw_hist_selected_url,
		(S8*)&g_brw_cntx.address_list_url_p[g_brw_cntx.index_highlighted_item - 1] );
    mmi_brw_address_list_entry_enter_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_delete_all
 * DESCRIPTION
 *  Deletes the Browser Setting History(Enter address list)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 NvramError;
    //U16 record_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(
        g_brw_cntx.address_list_title_p,
        0,
        NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS);
    memset(
        g_brw_cntx.address_list_url_p,
        0,
        NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS);


	mmi_brw_address_list_write_list_to_nvram();

	mmi_brw_mfree(g_brw_cntx.address_list_title_p);
	mmi_brw_mfree(g_brw_cntx.address_list_url_p);
	g_brw_cntx.address_list_title_p = NULL;
	g_brw_cntx.address_list_url_p = NULL;

    g_brw_cntx.total_address_list_items = 0;

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

	DeleteNScrId(SCR_ID_BRW_ENTER_ADDRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_set_as_homepage
 * DESCRIPTION
 *  Highlight handler of Enter Address set as homepage Menu item.
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_set_as_homepage((U8*)&g_brw_cntx.address_list_url_p[g_brw_cntx.index_highlighted_item - 1]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_pre_entry_enter_url
 * DESCRIPTION
 *  preentry function for opening the editor to enter the url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_pre_entry_enter_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_brw_hist_selected_title, 0, sizeof(g_brw_hist_selected_title));
    mmi_asc_to_ucs2((S8*) g_brw_hist_selected_url, (S8*) BRW_DEFAULT_ENTER_ADDR_STR);

    mmi_brw_address_list_entry_enter_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_address_list
 * DESCRIPTION
 *  Entry function for enter address menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_address_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 record_count;
    //S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read address history list from NVRAM if not already read */
    if ((g_brw_cntx.address_list_title_p == NULL) && (g_brw_cntx.address_list_url_p == NULL))
    {
		g_brw_cntx.address_list_title_p = 
			(nvram_brw_hist_title_struct*) mmi_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS*NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE);
		g_brw_cntx.address_list_url_p = 
			(nvram_brw_hist_url_struct*) mmi_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS*NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE);

        memset(
            g_brw_cntx.address_list_title_p,
            0,
            (NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS));
        memset(
            g_brw_cntx.address_list_url_p,
            0,
            (NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS));
    }

    mmi_brw_address_list_read_list_from_nvram();

    /* Calculate the number of entries */
    mmi_brw_address_list_count_number_of_stored_items();

    /* Open editor if no entries are present */
    if (g_brw_cntx.total_address_list_items == 0)
    {
        mmi_asc_to_ucs2((S8*) g_brw_hist_selected_url, (S8*) BRW_DEFAULT_ENTER_ADDR_STR);
        mmi_brw_address_list_entry_enter_url();
    }
    else
    {
		mmi_brw_entry_address_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_set_hiliter_flag
 * DESCRIPTION
 *  preentry function for opening the editor to enter the url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_set_hiliter_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.reset_hiliter_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_get_hiliter_flag
 * DESCRIPTION
 *  preentry function for opening the editor to enter the url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_address_list_get_hiliter_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_brw_cntx.reset_hiliter_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_set_item_at_top
 * DESCRIPTION
 *  preentry function for opening the editor to enter the url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_set_item_at_top(U32 selected_item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 list_index;
	U8 title_dcs;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(selected_item_index >= BRW_ADDRESS_LIST_MAX_ITEMS)
	{
		return;
	}

    if (g_brw_cntx.address_list_title_p[selected_item_index].dcs == BRW_DCS_UCS)
    {
		title_dcs = BRW_DCS_UCS;
        mmi_ucs2cpy(
            (S8*) g_brw_hist_selected_title,
            (S8*) g_brw_cntx.address_list_title_p[selected_item_index].title);
    }
    else
    {
		title_dcs = BRW_DCS_ASCII;
        mmi_asc_to_ucs2(
            (S8*) g_brw_hist_selected_title,
            (S8*) g_brw_cntx.address_list_title_p[selected_item_index].title);
    }

    mmi_asc_to_ucs2(
        (S8*) g_brw_hist_selected_url,
        (S8*) g_brw_cntx.address_list_url_p[selected_item_index].url);

    for (list_index = selected_item_index; list_index >= 1; list_index--)
    {
        if (list_index < BRW_ADDRESS_LIST_MAX_ITEMS)
        {
            memcpy(
                &g_brw_cntx.address_list_title_p[list_index],
                &g_brw_cntx.address_list_title_p[list_index - 1],
                sizeof(g_brw_cntx.address_list_title_p[list_index]));
            memcpy(
                &g_brw_cntx.address_list_url_p[list_index],
                &g_brw_cntx.address_list_url_p[list_index - 1],
                sizeof(g_brw_cntx.address_list_url_p[list_index]));
        }
    }

    if (title_dcs == BRW_DCS_UCS)
    {
        g_brw_cntx.address_list_title_p[0].dcs = BRW_DCS_UCS;
        mmi_ucs2cpy((S8*) g_brw_cntx.address_list_title_p[0].title, (S8*) g_brw_hist_selected_title);
    }
    else
    {
        g_brw_cntx.address_list_title_p[0].dcs = BRW_DCS_ASCII;
        mmi_ucs2_to_asc((S8*) g_brw_cntx.address_list_title_p[0].title, (S8*) g_brw_hist_selected_title);
    }

    mmi_ucs2_to_asc((S8*) g_brw_cntx.address_list_url_p[0].url, (S8*) g_brw_hist_selected_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_pre_entry_send_address
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_pre_entry_send_address(void)
{
	MMI_ASSERT(g_brw_cntx.address_list_url_p);

	mmi_asc_to_ucs2(
		(S8*) g_brw_current_url, 
		(S8*) g_brw_cntx.address_list_url_p[g_brw_cntx.index_highlighted_item - 1].url);
	mmi_brw_entry_send_address();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_free_memory
 * DESCRIPTION
 *  it de-allocates the memory for address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_mfree(g_brw_cntx.address_list_title_p);
	mmi_brw_mfree(g_brw_cntx.address_list_url_p);
	g_brw_cntx.address_list_title_p = NULL;
	g_brw_cntx.address_list_url_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_address_list_GoBackHistory
 * DESCRIPTION
 *  it de-allocates the memory for address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_address_list_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//mmi_brw_address_list_free_memory();
	GoBackHistory();
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERADDRESSLIST_C */ 

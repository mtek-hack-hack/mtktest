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
 * BrowserRecentPages.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for logical implementation 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERRECENTPAGES_C
#define MMI_BROWSERRECENTPAGES_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "Conversions.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserRecentPages.h"
/*  Include: NVRAM header file */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_pre_entry_options
 * DESCRIPTION
 *  Function to get the highlighted item and call appropriate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_cntx.index_highlighted_item = GetHighlightedItem();

	mmi_brw_recent_pages_get_recent_page_req(
			g_brw_cntx.recent_page_list[g_brw_cntx.index_highlighted_item].actual_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_host_pre_entry_options
 * DESCRIPTION
 *  Function to get the highlighted item and call appropriate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_host_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_cntx.index_highlighted_item = GetHighlightedItem();
    mmi_brw_recent_page_host_entry_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of recent pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_recent_pages_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*)str_buff, MAX_SUB_MENU_SIZE,
		(U8*)g_brw_cntx.dynamic_list[g_brw_cntx.recent_page_list[item_index].actual_index].name);
	//*img_buff_p = get_image(gIndexIconsImageList[item_index]);
	*img_buff_p = get_image(IMG_ID_BRW_RECENT_PAGES);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_host_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of recent pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_recent_pages_host_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_chset_utf8_to_ucs2_string((U8*)str_buff, MAX_SUB_MENU_SIZE,
		(U8*)g_brw_cntx.recent_page_host_list[item_index]);
	//*img_buff_p = get_image(gIndexIconsImageList[item_index]);
	*img_buff_p = get_image(IMG_ID_BRW_RECENT_PAGES);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete
 * DESCRIPTION
 *  Deletes the selected recent page from the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
	{
		g_brw_cntx.recent_page_host_delete_count = 0;
	}

	mmi_brw_recent_pages_delete_recent_page_req(
		g_brw_cntx.recent_page_list[g_brw_cntx.index_highlighted_item].actual_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete_all
 * DESCRIPTION
 *  Deletes the entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
	{
		/*mmi_brw_recent_pages_host_list_delete_item(
			g_brw_cntx.dynamic_list[g_brw_cntx.recent_page_list[0].actual_index].host);

		g_brw_cntx.recent_page_host_delete_count = g_brw_cntx.recent_page_count;
		g_brw_cntx.recent_page_count = 0;

		mmi_brw_dynamic_list_delete_items((U16)g_brw_cntx.recent_page_host_delete_count, 
			(U16)g_brw_cntx.recent_page_list[0].actual_index);*/

		g_brw_cntx.recent_page_host_delete_count = g_brw_cntx.recent_page_count;
		g_brw_cntx.recent_page_count = 0;

		mmi_brw_recent_pages_delete_recent_page_req(
			g_brw_cntx.recent_page_list[--g_brw_cntx.recent_page_host_delete_count].actual_index);
	}
	else
	{
		mmi_brw_recent_pages_delete_all_recent_page_req();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete_all_host
 * DESCRIPTION
 *  Deletes the entire recent page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete_all_host(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_recent_pages_delete_all_recent_page_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_goto
 * DESCRIPTION
 *  This function fetches the current url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;
	mmi_brw_recent_pages_load_recent_page_req(
		g_brw_cntx.recent_page_list[g_brw_cntx.index_highlighted_item].actual_index);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_set_as_homepage
 * DESCRIPTION
 *  This func is used for setting the selected URL as the current homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_set_as_homepage((U8*)g_brw_cntx.recent_page_info_p->url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_date
 * DESCRIPTION
 *  This func is used for sorting the recent pages in date wise order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GoBackToHistory(SCR_ID_BRW_RECENT_PAGES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_last_visited
 * DESCRIPTION
 *  This func is used for sorting the recent pages by last visited order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_last_visited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
	{
		DeleteUptoScrID(SCR_ID_BRW_INTERNET_SERVICES);
	}
	else if(IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))
	{
		DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
	}

	g_brw_cntx.sorting_method = WAP_BAM_RECENT_PAGE_SORT_OPTION_LAST;
	mmi_brw_recent_pages_write_sorting_method();
	//GoBackToHistory(SCR_ID_BRW_RECENT_PAGES);
	mmi_brw_recent_pages_get_recent_pages_list_start_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_most_visited
 * DESCRIPTION
 *  This func is used for sorting the recent pages by most visited order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_most_visited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
	{
		DeleteUptoScrID(SCR_ID_BRW_INTERNET_SERVICES);
	}
	else if(IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))
	{
		DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
	}

	g_brw_cntx.sorting_method = WAP_BAM_RECENT_PAGE_SORT_OPTION_FREQ;
	mmi_brw_recent_pages_write_sorting_method();
	//GoBackToHistory(SCR_ID_BRW_RECENT_PAGES);
	mmi_brw_recent_pages_get_recent_pages_list_start_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_sort_by_site
 * DESCRIPTION
 *  This func is used for sorting the recent pages in site wise order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_sort_by_site(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
	{
		DeleteUptoScrID(SCR_ID_BRW_INTERNET_SERVICES);
	}
	else if(IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))
	{
		DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
	}

	g_brw_cntx.sorting_method = WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST;
	mmi_brw_recent_pages_write_sorting_method();
	mmi_brw_recent_pages_get_recent_pages_list_start_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_recent_page_list
 * DESCRIPTION
 *  This func is used for sorting the recent pages by most visited order
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_recent_page_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
	{
		mmi_brw_recent_pages_create_host_list();
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
		    mmi_brw_entry_recent_page_host_list();
			mmi_brw_delete_busy_screen();
		}
		else
		{
			HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_RECENT_PAGES_HOST, mmi_brw_entry_recent_page_host_list);
		}
	}
	else
	{
		for(index=0; index<g_brw_cntx.dynamic_list_count; index++)
		{
			g_brw_cntx.recent_page_list[index].actual_index = index;
		}
		g_brw_cntx.recent_page_count = g_brw_cntx.dynamic_list_count;

		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
		    mmi_brw_entry_recent_page_list();
			mmi_brw_delete_busy_screen();
		}
		else
		{
			HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_RECENT_PAGES, mmi_brw_entry_recent_page_list);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_read_sorting_method
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_read_sorting_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_brw_cntx.sorting_method), DS_BYTE, &NvramError);
    if (g_brw_cntx.sorting_method == 0xFF)
    {
        g_brw_cntx.sorting_method = WAP_CUSTOM_CFG_DEFAULT_SORTING_METHOD;
        WriteValue(NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_brw_cntx.sorting_method), DS_BYTE, &NvramError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_write_sorting_method
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_write_sorting_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_brw_cntx.sorting_method), DS_BYTE, &NvramError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_recent_pages_list_start_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_recent_pages_list_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_start_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_RECENT_PAGES);
	mmi_brw_entry_browser_busy_screen();

	/*deleting the internediate screens if any*/
	DeleteNScrId(SCR_ID_BRW_RECENT_PAGES_HOST);
	DeleteNScrId(SCR_ID_BRW_RECENT_PAGES);

    myMsgPtr = (wap_bam_get_recent_pages_list_start_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_recent_pages_list_start_req_struct));

    myMsgPtr->source_id = BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
    myMsgPtr->sort_option = g_brw_cntx.sorting_method;

	mmi_brw_dynamic_list_free_memory();
	mmi_brw_recent_pages_free_memory();

    mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_recent_pages_list_continue_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_recent_pages_list_continue_req(U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_continue_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_get_recent_pages_list_continue_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_recent_pages_list_continue_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->start_index = start_index;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_recent_pages_list_end_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_recent_pages_list_end_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_end_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_get_recent_pages_list_end_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_recent_pages_list_end_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_END_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_sorting_method_set_hilite_index
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  trusted certificates list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_sorting_method_set_hilite_index(U32 *hilited_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
	S8* menuStr_p;
    S32 num_of_items;
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds(MENU_ID_BRW_RECENT_PAGE_SORT, nStrItemList);
    num_of_items = GetNumOfChild(MENU_ID_BRW_RECENT_PAGE_SORT);

	if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_LAST)
	{
		menuStr_p = GetString(STR_ID_BRW_SORT_BY_LAST_VISITED);
	}
	else if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_FREQ)
	{
		menuStr_p = GetString(STR_ID_BRW_SORT_BY_MOST_VISITED);
	}
	else if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
	{
		menuStr_p = GetString(STR_ID_BRW_SORT_BY_SITE);
	}
	else
	{
		menuStr_p = GetString(STR_ID_BRW_SORT_BY_LAST_VISITED);
	}

	for(index=0; index<num_of_items; index++)
	{
		if(!mmi_ucs2cmp(GetString(nStrItemList[index]), menuStr_p))
		{
			*hilited_index = index;
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_load_recent_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_load_recent_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_recent_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_load_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_recent_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = index;
  	myMsgPtr->charset = g_brw_cntx.charset_list_p[g_brw_cntx.encoding_method_index].id;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete_recent_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete_recent_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_recent_page_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_delete_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_recent_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = index;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_delete_all_recent_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_delete_all_recent_page_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_all_recent_pages_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_delete_all_recent_pages_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_all_recent_pages_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_create_host_list
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_create_host_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
	U32 host_index;
	MMI_BOOL isHostAlreadyAdded;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_recent_pages_host_list_free_memory();

	g_brw_cntx.recent_page_host_list = mmi_brw_malloc(g_brw_cntx.dynamic_list_count * sizeof(U32));

	for(index = 0; index < g_brw_cntx.dynamic_list_count; index++)
	{
		isHostAlreadyAdded = MMI_FALSE;
		for(host_index = 0; host_index < g_brw_cntx.recent_page_host_count; host_index++)
		{
			if(!strcmp((S8*)g_brw_cntx.recent_page_host_list[host_index], (S8*)g_brw_cntx.dynamic_list[index].host))
			{
				isHostAlreadyAdded = MMI_TRUE;
			}
		}
		if(!isHostAlreadyAdded)
		{
			g_brw_cntx.recent_page_host_list[host_index] = 
				mmi_brw_malloc((strlen((S8*)g_brw_cntx.dynamic_list[index].host)+1) * sizeof(U8));
			strcpy((S8*)g_brw_cntx.recent_page_host_list[g_brw_cntx.recent_page_host_count++], 
				(S8*)g_brw_cntx.dynamic_list[index].host);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_host_name
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_host_name(U8* recent_page_url, U8* host_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8* token;
	U8 temp_url[BRW_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	strcpy((S8*)temp_url, (S8*)recent_page_url);

	token = strtok((S8*)temp_url,(S8*)"\\");
	if(token)
	{
		token = strtok(NULL,(S8*)"\\");
		if(token)
		{
			strcpy((S8*)host_name,(S8*)token);
			return;
		}
	}
	strcpy((S8*)host_name, (S8*)"");
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_open_host
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_open_host(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
	U8* strSelectedHost;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	strSelectedHost = g_brw_cntx.recent_page_host_list[g_brw_cntx.index_highlighted_item];
	g_brw_cntx.recent_page_count = 0;

	for(index = 0; index < g_brw_cntx.dynamic_list_count; index++)
	{
		if(!strcmp((S8*)g_brw_cntx.dynamic_list[index].host, (S8*)strSelectedHost))
		{
			g_brw_cntx.recent_page_list[g_brw_cntx.recent_page_count++].actual_index = index;
		}
	}
	mmi_brw_entry_recent_page_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_delete_host
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_delete_host(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
	U8 strSelectedHost[1000];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	strcpy((S8*)strSelectedHost, (S8*)g_brw_cntx.recent_page_host_list[g_brw_cntx.index_highlighted_item]);
	g_brw_cntx.recent_page_host_delete_count = 0;

	/*creating the recent page list that has to be deleted corresponding to the selected host*/
	for(index = 0; index < g_brw_cntx.dynamic_list_count; index++)
	{
		if(!strcmp((S8*)g_brw_cntx.dynamic_list[index].host, (S8*)strSelectedHost))
		{
			g_brw_cntx.recent_page_list[g_brw_cntx.recent_page_host_delete_count++].actual_index = index;
		}
	}

	/*sending the request to delete the first page in the list*/
	if(g_brw_cntx.recent_page_host_delete_count > 0)
	{
		mmi_brw_recent_pages_delete_recent_page_req(
			g_brw_cntx.recent_page_list[--g_brw_cntx.recent_page_host_delete_count].actual_index);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_free_memory
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_recent_pages_host_list_free_memory();
	mmi_brw_mfree(g_brw_cntx.recent_page_list);
	mmi_brw_mfree(g_brw_cntx.recent_page_info_p);

	g_brw_cntx.recent_page_list = NULL;
	g_brw_cntx.recent_page_info_p = NULL;
	g_brw_cntx.recent_page_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_host_list_free_memory
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_host_list_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(index = 0; index < g_brw_cntx.recent_page_host_count; index++)
	{
		mmi_brw_mfree(g_brw_cntx.recent_page_host_list[index]);
		g_brw_cntx.recent_page_host_list[index] = NULL;
	}
	mmi_brw_mfree(g_brw_cntx.recent_page_host_list);
	g_brw_cntx.recent_page_host_list = NULL;
	g_brw_cntx.recent_page_host_count = 0;
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_pre_entry_add_to_bookmark
 * DESCRIPTION
 *  Pre Entry function for Enter Address Add To Bookmarks screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_pre_entry_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*) g_brw_cntx.recent_page_info_p->url);
	mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title, (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*) g_brw_cntx.recent_page_info_p->title);

	mmi_brw_bookmarks_add_to_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_send_address
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_send_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.recent_page_info_p);

	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.recent_page_info_p->url);
	mmi_brw_entry_send_address();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_recent_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_recent_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_page_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_get_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_recent_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = index;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_host_list_delete_item
 * DESCRIPTION
 *  deletes the selected host from the host list
 * PARAMETERS
 *  host_name		[IN]		host name in ascii
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_host_list_delete_item(U8* host_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL flag = MMI_FALSE;
	U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(index = 0; index < g_brw_cntx.recent_page_host_count-1; index++)
	{
		if(!strcmp((S8*)g_brw_cntx.recent_page_host_list[index], (S8*)host_name))
		{
			flag = MMI_TRUE;
		}
		if(flag)
		{
			mmi_brw_mfree(g_brw_cntx.recent_page_host_list[index]);
			g_brw_cntx.recent_page_host_list[index] = 
				mmi_brw_malloc((strlen((S8*)g_brw_cntx.recent_page_host_list[index+1])+1)*sizeof(U8));
			strcpy((S8*)g_brw_cntx.recent_page_host_list[index], (S8*)g_brw_cntx.recent_page_host_list[index+1]);
		}
	}
	
	if(flag)
	{
		mmi_brw_mfree(g_brw_cntx.recent_page_host_list[index]);
		g_brw_cntx.recent_page_host_list[index] = NULL;
		--g_brw_cntx.recent_page_host_count;
	}
	else
	{
		if(!strcmp((S8*)g_brw_cntx.recent_page_host_list[index], (S8*)host_name))
		{
			mmi_brw_mfree(g_brw_cntx.recent_page_host_list[index]);
			g_brw_cntx.recent_page_host_list[index] = NULL;
			--g_brw_cntx.recent_page_host_count;
		}
		else 
		{
			return;
		}
	}
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
void mmi_brw_recent_pages_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//mmi_brw_dynamic_list_free_memory();
	//mmi_brw_recent_pages_free_memory();
	GoBackHistory();
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERRECENTPAGES_C */ 


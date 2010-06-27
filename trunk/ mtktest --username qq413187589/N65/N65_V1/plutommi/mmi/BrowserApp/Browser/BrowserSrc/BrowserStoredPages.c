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
 * BrowserStoredPages.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contain the function definations for logical implementation 
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
#ifndef MMI_BROWSERSTOREDPAGES_C
#define MMI_BROWSERSTOREDPAGES_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "Conversions.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserStoredPages.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of stored pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_stored_pages_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string((U8*)str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.dynamic_list[item_index].name);
	*img_buff_p = get_image(IMG_ID_BRW_STORED_PAGES);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_send_address
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_send_address(void)
{
	MMI_ASSERT(g_brw_cntx.saved_page_properties_p);

	mmi_chset_utf8_to_ucs2_string(
		(U8*) g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.saved_page_properties_p->url);
	mmi_brw_entry_send_address();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_pre_entry_options
 * DESCRIPTION
 *  Function to get the highlighted item and call appropriate function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_cntx.index_highlighted_item = GetHighlightedItem();
	mmi_brw_stored_page_get_saved_page_req(g_brw_cntx.index_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_delete
 * DESCRIPTION
 *  Deletes the selected stored page from the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_stored_page_delete_saved_page_req(g_brw_cntx.index_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_delete_all
 * DESCRIPTION
 *  Deletes the entire stored page list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_stored_page_delete_all_saved_page_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_open
 * DESCRIPTION
 *  This function fetches the current url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;

	mmi_brw_stored_page_load_saved_page_req(g_brw_cntx.index_highlighted_item);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_set_as_homepage
 * DESCRIPTION
 *  This func is used for setting the selected URL as the current homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_set_as_homepage((U8*)g_brw_cntx.saved_page_properties_p->url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_memory_status
 * DESCRIPTION
 *  This func is used for getting the stored page memory status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_display_info_str)
	{
		mmi_brw_mfree(g_brw_display_info_str);
	}
	g_brw_display_info_str = mmi_brw_malloc(BRW_MEMORY_STATUS_MSG_LEN+1);

	mmi_asc_to_ucs2((S8*)g_brw_display_info_str, (S8*)"Stored Page Memory Status");

	mmi_brw_entry_memory_status();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_rename
 * DESCRIPTION
 *  This func is used for getting the stored page properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2strlen((S8*)g_brw_current_title))
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILENAME_EMPTY),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		DeleteNScrId(SCR_ID_BRW_STORED_PAGE_RENAME);
		return;
	}
	mmi_brw_stored_page_rename_saved_page_req((U8*)g_brw_current_title);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_load_saved_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_load_saved_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_saved_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_load_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_saved_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = index;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_delete_saved_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_delete_saved_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_saved_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_delete_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_saved_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = index;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_delete_all_saved_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_delete_all_saved_page_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_all_saved_pages_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_delete_all_saved_pages_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_all_saved_pages_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_rename_saved_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_rename_saved_page_req(U8* page_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_rename_saved_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_rename_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_rename_saved_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = g_brw_cntx.index_highlighted_item;
	mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->new_label,BRW_MAX_TITLE_LENGTH+1,(U8*)page_name);

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_get_saved_page_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_get_saved_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_get_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_saved_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = g_brw_cntx.index_highlighted_item;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_get_saved_pages_list_start_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_get_saved_pages_list_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_start_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_STORED_PAGES);
	mmi_brw_entry_browser_busy_screen();

	/*deleting the intermediate screens if any*/
	DeleteNScrId(SCR_ID_BRW_STORED_PAGES);

    myMsgPtr = (wap_bam_get_saved_pages_list_start_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_saved_pages_list_start_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_dynamic_list_free_memory();

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_get_saved_pages_list_continue_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_get_saved_pages_list_continue_req(U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_continue_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_get_saved_pages_list_continue_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_saved_pages_list_continue_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->start_index = start_index;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_get_saved_pages_list_end_req
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_get_saved_pages_list_end_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_end_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_get_saved_pages_list_end_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_saved_pages_list_end_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_END_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_page_pre_entry_page_properties
 * DESCRIPTION
 *  Entry function for store page properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_page_pre_entry_page_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 temp_str[100];
	applib_time_struct time_obj;
	S32 local_time_in_sec;
	S32 page_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.saved_page_properties_p);

	mmi_brw_object_properties_reset();

	if(g_brw_cntx.saved_page_properties_p)
	{
		g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
		mmi_chset_utf8_to_ucs2_string((U8*)g_brw_obj_properties_cntx.obj_name, (BRW_OBJECT_PROPERTIES_NAME_LEN+1)*ENCODING_LENGTH,
			(U8*)g_brw_cntx.saved_page_properties_p->label);

		g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_ADDRESS] = MMI_TRUE;
		mmi_chset_utf8_to_ucs2_string((U8*)g_brw_obj_properties_cntx.obj_address, (BRW_OBJECT_PROPERTIES_ADDRESS_LEN+1)*ENCODING_LENGTH,
			(U8*)g_brw_cntx.saved_page_properties_p->url);

		g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;
		page_size = (S32)g_brw_cntx.saved_page_properties_p->data_size;
		if( page_size > 0 )
		{
	        mmi_brw_convert_int_to_unicode_string((U8*)temp_str,(U32)g_brw_cntx.saved_page_properties_p->data_size);
	        mmi_ucs2cat((S8*)temp_str,(S8*)L" ");
	        mmi_ucs2cat((S8*)temp_str,(S8*)get_string(STR_ID_BRW_BYTES));
		}
		else
		{
			mmi_ucs2cpy((S8*)temp_str,(S8*)get_string(STR_ID_BRW_UNKNOWN));
		}
		mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_size, (S8*)temp_str);

		g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_DATE] = MMI_TRUE;
		local_time_in_sec = applib_dt_sec_utc_to_local(g_brw_cntx.saved_page_properties_p->date);
		if(applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE))
		{
			sprintf((S8*) temp_str, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);
			mmi_asc_to_ucs2((S8*)g_brw_obj_properties_cntx.obj_date, (S8*)temp_str);
		}
	}

	g_brw_obj_properties_cntx.prop_count = BRW_STORED_PAGE_PROPERTIES_COUNT;
	mmi_brw_entry_object_properties();
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_add_to_bookmark
 * DESCRIPTION
 *  Pre Entry function for Enter Address Add To Bookmarks screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*) g_brw_cntx.saved_page_properties_p->url);
	mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title, (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*) g_brw_cntx.saved_page_properties_p->label);

	mmi_brw_bookmarks_add_to_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSTOREDPAGES_C */ 


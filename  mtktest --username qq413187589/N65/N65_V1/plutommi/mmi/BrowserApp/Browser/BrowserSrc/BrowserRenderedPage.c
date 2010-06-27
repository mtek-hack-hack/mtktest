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
 * BrowserRenderedPage.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for logical implementation
 *   of rendered page.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERRENDEREDPAGE_C
#define MMI_BROWSERRENDEREDPAGE_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "Conversions.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserGprots.h"
#include "BrowserRenderedPage.h"
#include "ServiceDefs.h"
#include "DataAccountGProt.h"


MMI_BOOL g_brw_page_object_type[BRW_PAGE_OBJECT_TYPES_COUNT];
brw_page_object_struct g_brw_page_objs_image_list[BRW_PAGE_OBJECT_IMAGES_MAX];
brw_page_object_struct g_brw_page_objs_bg_image_list[BRW_PAGE_OBJECT_BG_IMAGES_MAX];
brw_page_object_struct g_brw_page_objs_sound_list[BRW_PAGE_OBJECT_SOUNDS_MAX];
brw_page_object_struct g_brw_page_objs_others_list[BRW_PAGE_OBJECT_OTHERS_MAX];
U8 g_brw_auth_username[(WAP_BAM_MAX_USER_PASSWD_LENGTH+1) * ENCODING_LENGTH];
U8 g_brw_auth_password[(WAP_BAM_MAX_USER_PASSWD_LENGTH+1) * ENCODING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_goto_homepage
 * DESCRIPTION
 *  This function is used to open the current homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_goto_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_act_profile_url[(BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) curr_act_profile_url);
    mmi_brw_pre_entry_goto_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_activate
 * DESCRIPTION
 *  This function is used for activating the select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select_mode_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.select_mode_flag = MMI_TRUE;

	mmi_brw_ren_page_navigation_change_req(WAP_BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE);
	if(g_brw_cntx.focused_element_info_p)
	{
		mmi_brw_mfree(g_brw_cntx.focused_element_info_p);
		g_brw_cntx.focused_element_info_p = NULL;
	}

	DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_select_mode_pre_entry_image_properties
 * DESCRIPTION
 *  Pre entry function to display image properties screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_select_mode_pre_entry_image_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 page_size[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        MMI_ASSERT(g_brw_cntx.focused_element_info_p);

	mmi_brw_object_properties_reset();

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_obj_properties_cntx.obj_name, (BRW_OBJECT_PROPERTIES_NAME_LEN+1)*ENCODING_LENGTH,
		(U8*)g_brw_cntx.focused_element_info_p->title);

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;
	mmi_brw_convert_int_to_unicode_string((U8*)page_size,(U32)g_brw_cntx.focused_element_info_p->size);
	mmi_ucs2cat((S8*)page_size,(S8*)L" ");
	mmi_ucs2cat((S8*)page_size,(S8*)get_string(STR_ID_BRW_BYTES));
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_size, (S8*)page_size);

	g_brw_obj_properties_cntx.prop_count = BRW_SELECT_MODE_IMAGE_PROP_COUNT;

	mmi_brw_entry_object_properties();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_pre_entry_page_properties
 * DESCRIPTION
 *  Pre entry function to display page properties screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_pre_entry_page_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 page_size[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.document_info_p);

	mmi_brw_object_properties_reset();

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_obj_properties_cntx.obj_name, (BRW_OBJECT_PROPERTIES_NAME_LEN+1)*ENCODING_LENGTH,
		(U8*)g_brw_cntx.document_info_p->title);

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_ADDRESS] = MMI_TRUE;
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_obj_properties_cntx.obj_address, (BRW_OBJECT_PROPERTIES_ADDRESS_LEN+1)*ENCODING_LENGTH,
		(U8*)g_brw_cntx.document_info_p->url);

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;
	mmi_brw_convert_int_to_unicode_string((U8*)page_size,(U32)g_brw_cntx.brw_status_info_p->document_bytes_total);
	mmi_ucs2cat((S8*)page_size,(S8*)L" ");
	mmi_ucs2cat((S8*)page_size,(S8*)get_string(STR_ID_BRW_BYTES));
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_size, (S8*)page_size);

	g_brw_obj_properties_cntx.prop_count = BRW_THIS_PAGE_PROPERTIES_COUNT;

	mmi_brw_entry_object_properties();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_set_as_homepage
 * DESCRIPTION
 *  This function is used for setting the selected link as the new homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        MMI_ASSERT(g_brw_cntx.focused_element_info_p);

	mmi_brw_set_as_homepage((U8*)g_brw_cntx.focused_element_info_p->url);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_add_to_bookmark
 * DESCRIPTION
 *  This function is used for saving the selected link as a bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_brw_cntx.focused_element_info_p);

    mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title,
          (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.focused_element_info_p->title);
    mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url,
          (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.focused_element_info_p->url);

   mmi_brw_bookmarks_add_to_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_set_as_homepage
 * DESCRIPTION
 *  This function is used for setting the current page URL
 *  as the new homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.document_info_p);

	mmi_brw_set_as_homepage((U8 *)g_brw_cntx.document_info_p->url);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_add_to_bookmark
 * DESCRIPTION
 *  This function is used for saving the current page URL
 *  as a bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title,
	    (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->title);
    mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_url,
	    (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->url);

    mmi_brw_bookmarks_add_to_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_pre_entry_send_address
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_pre_entry_send_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.focused_element_info_p);

	mmi_chset_utf8_to_ucs2_string(
		(U8*) g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.focused_element_info_p->url);
	mmi_brw_entry_send_address();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_pre_entry_send_address
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_pre_entry_send_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.document_info_p);

	mmi_chset_utf8_to_ucs2_string(
		(U8*) g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->url);
	mmi_brw_entry_send_address();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_store_offline
 * DESCRIPTION
 *  This function sends the request for storing offline the current page URL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_store_offline(void)
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
		DeleteNScrId(SCR_ID_BRW_EDIT_STORE_OFFLINE);
		return;
	}
	mmi_brw_this_page_save_page_req((U8*)g_brw_current_title);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_save_as
 * DESCRIPTION
 *  This function sends the request for saving the selected object
 *  in select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select_mode_save_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.focused_element_info_p);

	mmi_brw_ren_page_object_action_req(g_brw_cntx.focused_element_info_p->type);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_pre_exit
 * DESCRIPTION
 *  This function is used for checking pre-conditions before exiting from
 *  browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_pre_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
	if(g_brw_cntx.download_info_p &&
		g_brw_cntx.download_info_p->active_job_count)
	{
		mmi_brw_ren_page_suspend_bkgrd_downloads_confirm();
		return;
	}
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/

	mmi_brw_app_exit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_exit
 * DESCRIPTION
 *  This function sends the request to exit from the select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select_mode_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.select_mode_flag = FALSE;
	mmi_brw_ren_page_navigation_change_req(WAP_BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_backward
 * DESCRIPTION
 *  This function sends the request for opening the previous page if user press 
 *  RSK back from rendered page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;

	mmi_brw_ren_page_navigate_req(WAP_BAM_MOVE_BACKWARD, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_refresh
 * DESCRIPTION
 *  This function sends the request for refreshing the current page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;

	mmi_brw_ren_page_reload_req();
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_forward
 * DESCRIPTION
 *  This function sends the request for opening the next page in the page
 *  navigation list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;

	mmi_brw_ren_page_navigate_req(WAP_BAM_MOVE_FORWARD, 1);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_backward
 * DESCRIPTION
 *  This function sends the request for opening the previous page in the page
 *  navigation list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;

	mmi_brw_ren_page_navigate_req(WAP_BAM_MOVE_BACKWARD, 1);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_page_actions_ok
 * DESCRIPTION
 *  This function sends the request for performing selected page action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_page_actions_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* don't take any action if the selected DO element is of type "prev" and */
	/* no previous page is available in page navigation list                 */
	if( !mmi_brw_stricmp((S8*)g_brw_cntx.do_element_list[GetHighlightedItem()].event_type, (S8*)BRW_DO_ELEMENT_EVENT_TYPE_PREVIOUS) &&
		!mmi_brw_ren_page_is_backward_navigation()
	   )
	{
		mmi_brw_entry_render_page();
		return;
	}

	g_brw_cntx.index_highlighted_item = GetHighlightedItem();
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;

	mmi_brw_ren_page_activate_do_element_req();
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_navigate_page_actions_get_list_item
 * DESCRIPTION
 *  This function is used for getting an menu item on the page actions screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_ren_page_navigate_page_actions_list_get_item(S32 item_index, UI_string_type str_buff,
												 PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*)str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.do_element_list[item_index].label);

	//*img_buff_p = get_image(gIndexIconsImageList[item_index]);
	*img_buff_p = get_image(IMG_ID_BRW_DO_ELEMENTS);

	return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_get_total_item_count
 * DESCRIPTION
 *  This function is used for calculating the total of menu items on
 *  the navigate screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_get_total_item_count(PU8 count_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*count_p = 1;

	if(mmi_brw_ren_page_is_forward_navigation())
	{
		++(*count_p);
	}
	if(mmi_brw_ren_page_is_backward_navigation())
	{
		++(*count_p);
	}
	if(g_brw_cntx.do_element_count)
	{
		++(*count_p);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_goto
 * DESCRIPTION
 *  This function is used for fetching the selected link on the
 *  rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.focused_element_info_p);

	//g_brw_cntx.isBrowserFetching = MMI_TRUE;
	mmi_brw_ren_page_object_action_req(g_brw_cntx.focused_element_info_p->type);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_rsk_exit
 * DESCRIPTION
 *  This function to used for sending the request to exit from the select mode
 *  if RSK is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select_mode_rsk_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.select_mode_flag = FALSE;
	mmi_brw_ren_page_navigation_change_req(WAP_BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE);
	mmi_brw_ren_page_set_RSK();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_set_title_string
 * DESCRIPTION
 *  This function is used for setting the title string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_set_title_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(GetActiveScreenId() != SCR_ID_BRW_BROWSER_MAIN)
	{
		return;
	}

	if(g_brw_cntx.document_info_p)
	{
		mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title, (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->title);
		wgui_title_change(0,0,g_brw_current_title,WGUI_TITLE_CHANGE_TEXT);
		draw_title();
	}
	else
	{
		mmi_ucs2cpy((S8*) g_brw_current_title, GetString(STR_ID_BRW_INTERNET_SERVICES));
		wgui_title_change(0,0,g_brw_current_title,WGUI_TITLE_CHANGE_TEXT);
		draw_title();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_get_title_string
 * DESCRIPTION
 *  This function is used for getting the title string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8* mmi_brw_ren_page_get_title_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.document_info_p)
	{
		mmi_chset_utf8_to_ucs2_string((U8*) g_brw_current_title, (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->title);
	}
	else
	{
		mmi_ucs2cpy((S8*) g_brw_current_title, GetString(STR_ID_BRW_INTERNET_SERVICES));
	}
	return (U8*)g_brw_current_title;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_set_title_icon
 * DESCRIPTION
 *  This function is used for setting the title icon of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_set_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(GetActiveScreenId() != SCR_ID_BRW_BROWSER_MAIN)
	{
		return;
	}

	/*check page fetching status*/
	if(g_brw_cntx.isBrowserFetching)
	{
		mmi_brw_ren_page_show_animated_title_icon();
	}
	else /*page already fetched*/
	{
		mmi_brw_ren_page_show_non_animated_title_icon();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_show_animated_title_icon
 * DESCRIPTION
 *  This function is used for displaying the animated title icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_show_animated_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *activeProfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	activeProfile = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_wap_profile();

	if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_CSD)
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_CSD,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	else if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_GPRS)
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_GPRS,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	else if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_WIFI)
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_WIFI,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	else
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_CSD,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_show_non_animated_title_icon
 * DESCRIPTION
 *  This function is used for displaying the non-animated title icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_show_non_animated_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *activeProfile;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	activeProfile = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_wap_profile();

	if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_CSD)
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_CSD_STATIC,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	else if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_GPRS)
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_GPRS_STATIC,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	else if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_WIFI)
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_WIFI_STATIC,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	else
	{
		wgui_title_change(IMG_ID_BRW_CONNECTION_STATUS_CSD_STATIC,0,NULL,WGUI_TITLE_CHANGE_ICON);
	}
	draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_get_title_icon
 * DESCRIPTION
 *  This function is used for getting the title icon ID of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_ren_page_get_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *activeProfile;
	U16 Image_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	activeProfile = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_wap_profile();

	/*check page fetching status*/
	if(g_brw_cntx.isBrowserFetching)
	{
		switch(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id))
		{
			case DATA_ACCOUNT_BEARER_CSD:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_CSD;
				break;
			}
			case DATA_ACCOUNT_BEARER_GPRS:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_GPRS;
				break;
			}
			case DATA_ACCOUNT_BEARER_WIFI:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_WIFI;
				break;
			}
			default:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_CSD;
				break;
			}			
		}
	}
	else /*page already fetched*/
	{
		switch(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id))
		{
			case DATA_ACCOUNT_BEARER_CSD:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_CSD_STATIC;
				break;
			}
			case DATA_ACCOUNT_BEARER_GPRS:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_GPRS_STATIC;
				break;
			}
			case DATA_ACCOUNT_BEARER_WIFI:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_WIFI_STATIC;
				break;
			}
			default:
			{
				Image_id = IMG_ID_BRW_CONNECTION_STATUS_CSD_STATIC;
				break;
			}			
		}
	}
	
	return Image_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_set_LSK
 * DESCRIPTION
 *  This function is used for setting the LSK string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_set_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(GetActiveScreenId() != SCR_ID_BRW_BROWSER_MAIN)
	{
		return;
	}

	if(g_brw_cntx.isBrowserFetching)
	{
		ChangeLeftSoftkey(NULL, 0);
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else if(g_brw_cntx.document_info_p)
	{
		ChangeLeftSoftkey(STR_ID_BRW_OPTION, 0);
		SetLeftSoftkeyFunction(mmi_brw_ren_page_entry_options, KEY_EVENT_UP);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_set_RSK
 * DESCRIPTION
 *  This function is used for setting the RSK string of the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_set_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(GetActiveScreenId() != SCR_ID_BRW_BROWSER_MAIN)
	{
		return;
	}

	if(g_brw_cntx.select_mode_flag)
	{
		ChangeRightSoftkey(STR_ID_BRW_EXIT, 0);
		SetRightSoftkeyFunction(mmi_brw_ren_page_select_mode_rsk_exit, KEY_EVENT_UP);
	}
	else
	{
		if(g_brw_cntx.isBrowserFetching || !g_brw_cntx.document_info_p)
		{
			ChangeRightSoftkey(STR_GLOBAL_CANCEL, 0);
			SetRightSoftkeyFunction(mmi_brw_ren_page_stop_page_fetching, KEY_EVENT_UP);
		}
		else if(mmi_brw_ren_page_is_backward_navigation())
		{
			ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
			SetRightSoftkeyFunction(mmi_brw_ren_page_backward, KEY_EVENT_UP);
		}
		else
		{
			ChangeRightSoftkey(NULL, 0);
			SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_pre_entry_page_object_types
 * DESCRIPTION
 *  Pre entry function for displaying page object types
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_pre_entry_page_object_types(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 item_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.page_objs_images_count)
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_IMAGE] = MMI_TRUE;
	}
	else
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_IMAGE] = MMI_FALSE;
	}

	if(g_brw_cntx.page_objs_bg_images_count)
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_BG_IMAGE] = MMI_TRUE;
	}
	else
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_BG_IMAGE] = MMI_FALSE;
	}

	if(g_brw_cntx.page_objs_sounds_count)
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_SOUNDS] = MMI_TRUE;
	}
	else
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_SOUNDS] = MMI_FALSE;
	}

	if(g_brw_cntx.page_objs_others_count)
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_OTHERS] = MMI_TRUE;
	}
	else
	{
		g_brw_page_object_type[BRW_PAGE_OBJECT_TYPE_OTHERS] = MMI_FALSE;
	}

	mmi_brw_this_page_get_page_object_types_count(&item_count);

	if(item_count)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
		    mmi_brw_this_page_entry_page_object_types();
			mmi_brw_delete_busy_screen();
	    }
	    else
	    {
			HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_PAGE_OBJECT_TYPES, mmi_brw_this_page_entry_page_object_types);
		}
	}
	else
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
		    DisplayPopup(
				        (U8*) GetString(STR_ID_BRW_EMPTY),
				        (U16) IMG_GLOBAL_EMPTY,
				        0,
			    UI_POPUP_NOTIFYDURATION_TIME,
				        (U8) EMPTY_LIST_TONE);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_page_object_types_count
 * DESCRIPTION
 *  This function is used for counting the total number of page object types
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_page_object_types_count(U8* count_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 index=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*count_p = 0;

	while(index < BRW_PAGE_OBJECT_TYPES_COUNT)
	{
		if(g_brw_page_object_type[index] == MMI_TRUE)
		{
			++(*count_p);
		}
		++index;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_page_objects_count
 * DESCRIPTION
 *  This function is used for getting the total number of page objects in a
 *  particular category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_page_objects_count(U8* count_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(g_brw_cntx.selected_page_object_type)
	{
		case BRW_PAGE_OBJECT_TYPE_IMAGE:
			*count_p = g_brw_cntx.page_objs_images_count;
			break;

		case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
			*count_p = g_brw_cntx.page_objs_bg_images_count;
			break;

		case BRW_PAGE_OBJECT_TYPE_SOUNDS:
			*count_p = g_brw_cntx.page_objs_sounds_count;
			break;

		case BRW_PAGE_OBJECT_TYPE_OTHERS:
			*count_p = g_brw_cntx.page_objs_others_count;
			break;
		default:
			*count_p = 0;
			break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_object_types_get_item
 * DESCRIPTION
 *  This function is used for getting an menu item on the page object
 *  types screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_page_object_types_get_item(S32 item_index, UI_string_type str_buff,
												 PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 actual_index=0;
	U8 index = 0;
	S16 active_item_count = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	do
	{
		if(g_brw_page_object_type[index] == MMI_TRUE)
		{
			++active_item_count;
			if(active_item_count == item_index)
			{
				actual_index = index;
				break;
			}
		}
		++index;
	}while(index < BRW_PAGE_OBJECT_TYPES_COUNT);

	switch(actual_index)
	{
		case BRW_PAGE_OBJECT_TYPE_IMAGE:
			mmi_ucs2cpy((S8*)str_buff, GetString(STR_ID_BRW_IMAGES));
			break;

		case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
			mmi_ucs2cpy((S8*)str_buff, GetString(STR_ID_BRW_BG_IMAGES));
			break;

		case BRW_PAGE_OBJECT_TYPE_SOUNDS:
			mmi_ucs2cpy((S8*)str_buff, GetString(STR_ID_BRW_SOUNDS));
			break;

		case BRW_PAGE_OBJECT_TYPE_OTHERS:
			mmi_ucs2cpy((S8*)str_buff, GetString(STR_ID_BRW_OTHERS));
			break;
		default:
			str_buff = NULL;
			break;
	}
	*img_buff_p = get_image(gIndexIconsImageList[item_index]);
	return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_object_types_ok
 * DESCRIPTION
 *  This function is used for getting the index of the selected page object
 *  type and displaying all the page objects in this category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_object_types_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 hilited_item_index;
	U8 index = 0;
	S16 active_item_count = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	hilited_item_index = (U8) GetHighlightedItem();
	do
	{
		if(g_brw_page_object_type[index] == MMI_TRUE)
		{
			++active_item_count;
			if(active_item_count == hilited_item_index)
			{
				g_brw_cntx.selected_page_object_type = index;
				break;
			}
		}
		++index;
	}while(index < BRW_PAGE_OBJECT_TYPES_COUNT);

	mmi_brw_this_page_entry_page_objects();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_objects_get_item
 * DESCRIPTION
 *  This function is used for getting an menu item on the page objects screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_this_page_objects_get_item(S32 item_index, UI_string_type str_buff,
												 PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(g_brw_cntx.selected_page_object_type)
	{
		case BRW_PAGE_OBJECT_TYPE_IMAGE:
			mmi_chset_utf8_to_ucs2_string((U8*) str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.dynamic_list[g_brw_page_objs_image_list[item_index].res_list_index].name);
			break;

		case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
			mmi_chset_utf8_to_ucs2_string((U8*) str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.dynamic_list[g_brw_page_objs_bg_image_list[item_index].res_list_index].name);
			break;

		case BRW_PAGE_OBJECT_TYPE_SOUNDS:
			mmi_chset_utf8_to_ucs2_string((U8*) str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.dynamic_list[g_brw_page_objs_sound_list[item_index].res_list_index].name);
			break;

		case BRW_PAGE_OBJECT_TYPE_OTHERS:
			mmi_chset_utf8_to_ucs2_string((U8*) str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.dynamic_list[g_brw_page_objs_others_list[item_index].res_list_index].name);
			break;
		default:
			return FALSE;
	}

	//*img_buff_p = get_image(gIndexIconsImageList[item_index]);
	*img_buff_p = get_image(IMG_ID_BRW_PAGE_OBJECTS);
	return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_save_as
 * DESCRIPTION
 *  This function is used for saving a selected page object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_objects_save_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.brw_res_item_info_p);

	//mmi_brw_ren_page_object_action_req(g_brw_cntx.brw_res_item_info_p->type);
	mmi_brw_ren_page_activate_resource_req(g_brw_cntx.index_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_pre_entry_object_properties
 * DESCRIPTION
 *  Pre entry function for displaying properties of the selected page object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_objects_pre_entry_object_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 page_size[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.brw_res_item_info_p);

	mmi_brw_object_properties_reset();

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_NAME] = MMI_TRUE;
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_obj_properties_cntx.obj_name, (BRW_OBJECT_PROPERTIES_NAME_LEN+1)*ENCODING_LENGTH,
		(U8*)g_brw_cntx.brw_res_item_info_p->title);

	g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_SIZE] = MMI_TRUE;
	mmi_brw_convert_int_to_unicode_string((U8*)page_size,(U32)g_brw_cntx.brw_res_item_info_p->size);
	mmi_ucs2cat((S8*)page_size,(S8*)L" ");
	mmi_ucs2cat((S8*)page_size,(S8*)get_string(STR_ID_BRW_BYTES));
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_size, (S8*)page_size);

	g_brw_obj_properties_cntx.prop_count = BRW_PAGE_OBJECT_PROPERTIES_COUNT;

	mmi_brw_entry_object_properties();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_pre_entry_options
 * DESCRIPTION
 *  Pre entry function for displaying page objects options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_objects_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.index_highlighted_item =	mmi_brw_page_objects_get_object_res_list_index();
	mmi_brw_this_page_get_resource_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_get_object_res_list_index
 * DESCRIPTION
 *  This function is used for getting the actual resource list index of a
 *  selected page object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_brw_page_objects_get_object_res_list_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 hilited_index;
	U32 actual_res_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	hilited_index = GetHighlightedItem();

	switch(g_brw_cntx.selected_page_object_type)
	{
		case BRW_PAGE_OBJECT_TYPE_IMAGE:
			actual_res_index = g_brw_page_objs_image_list[hilited_index].res_list_index;
			break;

		case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
			actual_res_index = g_brw_page_objs_bg_image_list[hilited_index].res_list_index;
			break;

		case BRW_PAGE_OBJECT_TYPE_SOUNDS:
			actual_res_index = g_brw_page_objs_sound_list[hilited_index].res_list_index;
			break;

		case BRW_PAGE_OBJECT_TYPE_OTHERS:
			actual_res_index = g_brw_page_objs_others_list[hilited_index].res_list_index;
			break;

		default:
			actual_res_index = 0;
	}

	return actual_res_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_sec_confirm_dialog_res
 * DESCRIPTION
 *  Response function for the security confirmation dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_sec_confirm_dialog_res(S8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_show_confirm_dialog_res_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.sec_confirm_dlg_info_p);

    myMsgPtr = (wps_show_confirm_dialog_res_struct*) OslConstructDataPtr(sizeof(wps_show_confirm_dialog_res_struct));

	myMsgPtr->request_id = g_brw_cntx.sec_confirm_dlg_info_p->request_id;
	myMsgPtr->result = result;

	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_RES, myMsgPtr, NULL);

	g_brw_cntx.security_dlg_flag = MMI_FALSE;

	if(g_brw_cntx.sec_confirm_dlg_info_p)
	{
		OslMfree(g_brw_cntx.sec_confirm_dlg_info_p);
		g_brw_cntx.sec_confirm_dlg_info_p = NULL;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_show_auth_dialog_res
 * DESCRIPTION
 *  Response function for the authentication dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_show_auth_dialog_res(U16 options)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_show_auth_dialog_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_show_auth_dialog_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_show_auth_dialog_rsp_struct));

	myMsgPtr->instance_id = g_brw_cntx.http_auth_info_p->instance_id;
	myMsgPtr->request_id = g_brw_cntx.http_auth_info_p->request_id;
	myMsgPtr->options = options;
	mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->username, WAP_BAM_MAX_USER_PASSWD_LENGTH+1, (U8*)g_brw_auth_username);
	mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->password, WAP_BAM_MAX_USER_PASSWD_LENGTH+1, (U8*)g_brw_auth_password);

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP, myMsgPtr, NULL);

	g_brw_cntx.auth_dlg_flag = MMI_FALSE;

	if(g_brw_cntx.http_auth_info_p)
	{
		OslMfree(g_brw_cntx.http_auth_info_p);
		g_brw_cntx.http_auth_info_p = NULL;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_activate_do_element_req
 * DESCRIPTION
 *  Request function for activating a DO element
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_activate_do_element_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_activate_do_element_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_activate_do_element_req_struct*) OslConstructDataPtr(sizeof(wap_bam_activate_do_element_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->element_id = g_brw_cntx.do_element_list[g_brw_cntx.index_highlighted_item].element_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_req
 * DESCRIPTION
 *  Request function for moving backward/forward in recent pages naviagtion list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_req(U8 direction, U8 no_of_steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_move_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_move_req_struct*) OslConstructDataPtr(sizeof(wap_bam_move_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->direction = direction;
	myMsgPtr->steps = no_of_steps;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_MOVE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_reload_req
 * DESCRIPTION
 *  Request function for reloading the current page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_reload_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_reload_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_reload_req_struct*) OslConstructDataPtr(sizeof(wap_bam_reload_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RELOAD_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_stop_page_fetching
 * DESCRIPTION
 *  This function is used for stoping the page fetching process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_stop_page_fetching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_stop_page_fetching_req();
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_stop_page_fetching_req
 * DESCRIPTION
 *  Request function for stoping the page fetching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_stop_page_fetching_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_stop_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_stop_req_struct*) OslConstructDataPtr(sizeof(wap_bam_stop_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_STOP_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigation_change_req
 * DESCRIPTION
 *  Request function for changing the selectable item type on the web page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigation_change_req(U16 selectable_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_navigation_change_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_navigation_change_req_struct*) OslConstructDataPtr(sizeof(wap_bam_navigation_change_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->elements = selectable_items;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_save_page_req
 * DESCRIPTION
 *  Request function for saving the current opened page as offline
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_save_page_req(U8* page_label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_save_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
	mmi_brw_entry_browser_busy_screen();

	/*deleting the internediate screens if any*/
	DeleteNScrId(SCR_ID_BRW_EDIT_STORE_OFFLINE);

    myMsgPtr = (wap_bam_save_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_save_page_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
    mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->label,BRW_MAX_TITLE_LENGTH + 1,(U8*)page_label);
	myMsgPtr->overwrite = MMI_FALSE;

	g_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_SAVE_PAGE_REQ;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SAVE_PAGE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_resource_list_start_req
 * DESCRIPTION
 *  Request function for initializing the resource list and getting the total
 *  number of page resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_list_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_start_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_PAGE_OBJECTS);
	mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_get_resources_list_start_req_struct*)
		OslConstructDataPtr(sizeof(wap_bam_get_resources_list_start_req_struct));
	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_dynamic_list_free_memory();
	g_brw_cntx.page_objs_images_count = 0;
	g_brw_cntx.page_objs_bg_images_count = 0;
	g_brw_cntx.page_objs_sounds_count = 0;
	g_brw_cntx.page_objs_others_count = 0;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_resource_list_continue_req
 * DESCRIPTION
 *  Request function for getting the resource names starting from a particular index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_list_continue_req(U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_continue_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_get_resources_list_continue_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_resources_list_continue_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->start_index = start_index;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_resource_list_end_req
 * DESCRIPTION
 *  Request function for de-initializing the page resource list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_list_end_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_end_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_get_resources_list_end_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_resources_list_end_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_END_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_resource_req
 * DESCRIPTION
 *  Request function for getting the complete info of a particular resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resource_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wap_bam_get_resource_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_resource_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->index = g_brw_cntx.index_highlighted_item;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_pen_handler
 * DESCRIPTION
 *  This is a callback function for handling pen events on the rendered page
 *  screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_ren_page_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_handle_pen_event_req(point, event_type);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_is_backward_navigation
 * DESCRIPTION
 *  This function is used for checking the backward status of the page navigation
 *  list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : If a page exists before the current page in the page navigation list
 *  MMI_FALSE : otherwise
 *****************************************************************************/
MMI_BOOL mmi_brw_ren_page_is_backward_navigation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.document_info_p)
	{
		if(g_brw_cntx.document_info_p->flags & 0x0001)
		{
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_is_forward_navigation
 * DESCRIPTION
 *  This function is used for checking the forward status of the page navigation
 *  list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : If a page exists next to the current page in the page navigation list
 *  MMI_FALSE : otherwise
 *****************************************************************************/
MMI_BOOL mmi_brw_ren_page_is_forward_navigation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.document_info_p)
	{
		if(g_brw_cntx.document_info_p->flags & 0x0002)
		{
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_save_options_done
 * DESCRIPTION
 *  This function sends the 'done' user response for the auth dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_save_options_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_NOTHING);
	DeleteNScrId(SCR_ID_BRW_SHOW_AUTH_DIALOG);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_save_options_save_both
 * DESCRIPTION
 *  This function sends the 'save both' user response for the auth dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_save_options_save_both(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD);
	DeleteNScrId(SCR_ID_BRW_SHOW_AUTH_DIALOG);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_save_options_save_only_username
 * DESCRIPTION
 *  This function sends the 'save only username' user response for the auth dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_save_options_save_only_username(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME);
	DeleteNScrId(SCR_ID_BRW_SHOW_AUTH_DIALOG);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_cancel
 * DESCRIPTION
 *  This function sends the 'cancel' user response for the auth dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_CANCEL);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_handle_pen_event_req
 * DESCRIPTION
 *  This is the request function for pen event on the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_handle_pen_event_req(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_handle_pen_event_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_handle_pen_event_req_struct*) OslConstructDataPtr(sizeof(wap_bam_handle_pen_event_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
    myMsgPtr->pos_x = point.x;
    myMsgPtr->pos_y = point.y;
	myMsgPtr->type = event_type;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_HANDLE_PEN_EVENT_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_suspend_owl_rendering_req
 * DESCRIPTION
 *  This is the request function for suspending the rendering process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_suspend_owl_rendering_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //wap_bam_suspend_owl_rendering_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*myMsgPtr = (wap_bam_suspend_owl_rendering_req_struct*) OslConstructDataPtr(sizeof(wap_bam_suspend_owl_rendering_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SUSPEND_OWL_RENDERING_REQ, myMsgPtr, NULL);*/

	bam_suspend_owl_rendering();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_resume_owl_rendering_req
 * DESCRIPTION
 *  This is the request function for resuming the rendering process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_resume_owl_rendering_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //wap_bam_resume_owl_rendering_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*myMsgPtr = (wap_bam_resume_owl_rendering_req_struct*) OslConstructDataPtr(sizeof(wap_bam_resume_owl_rendering_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RESUME_OWL_RENDERING_REQ, myMsgPtr, NULL);*/

	bam_resume_owl_rendering();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_notify_screen_info_req
 * DESCRIPTION
 *  This is the request function for updating the rendered page screen settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_notify_screen_info_req(MMI_BOOL refresh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // wap_bam_notify_screen_info_req_struct *myMsgPtr;
    GDI_HANDLE title_layer = 0;
    GDI_HANDLE bottom_layer = 0;
    U32 x=0;
    U32 y=0;
    U32 w=0;
    U32 h=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if 0  /* BrowserAPP should call bam_notify_screen_info() instead. */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    Cat431GetScreenInfo(g_brw_cntx.screen_size_status,&x,&y,&w,&h,&title_layer,&bottom_layer);
    bam_notify_screen_info(x, y, w, h, title_layer, bottom_layer, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_activate_resource_req
 * DESCRIPTION
 *  This is the request function for viewing the selected rendered page resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_activate_resource_req(U32 res_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_activate_resource_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_activate_resource_req_struct*) OslConstructDataPtr(sizeof(wap_bam_activate_resource_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
    myMsgPtr->index = res_index;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_ACTIVATE_RESOURCE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_to_hotspot_req
 * DESCRIPTION
 *  This is the request function for navigating the hotspot on the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_to_hotspot_req(U32 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_navigate_to_hotspot_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_navigate_to_hotspot_req_struct*) OslConstructDataPtr(sizeof(wap_bam_navigate_to_hotspot_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
    myMsgPtr->direction = direction;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_NAVIGATE_TO_HOTSPOT_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_edit_req
 * DESCRIPTION
 *  This is the request function to take some action on the selection of an edit
 *  item on the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_edit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.focused_element_info_p);
	mmi_brw_ren_page_object_action_req(g_brw_cntx.focused_element_info_p->type);

	if(g_brw_cntx.focused_element_info_p->type == WAP_BAM_FOCUSED_ELEMENT_TEXTINPUT)
	{
		/*showing the temporary busy screen*/
		mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_OPTION);
		mmi_brw_entry_temp_busy_screen();
	    DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
    }
	else
	{
		mmi_brw_entry_render_page();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_reset_req
 * DESCRIPTION
 *  This is the request function to take some action on the selection of a reset
 *  item on the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_reset_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.focused_element_info_p);
	mmi_brw_ren_page_object_action_req(g_brw_cntx.focused_element_info_p->type);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_ok
 * DESCRIPTION
 *  This is the request function to take some action on the selection of a reset
 *  item on the rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(g_brw_auth_dlg_save_option)
	{
		case BRW_AUTH_DLG_SAVE_NONE_INDEX:
		{
			mmi_brw_ren_page_auth_dlg_save_options_done();
			break;
		}
		case BRW_AUTH_DLG_SAVE_BOTH_INDEX:
		{
			mmi_brw_ren_page_auth_dlg_save_options_save_both();
			break;
		}
		case BRW_AUTH_DLG_SAVE_USERNAME_INDEX:
		{
			mmi_brw_ren_page_auth_dlg_save_options_save_only_username();
			break;
		}
		default:
		{
			mmi_brw_ren_page_auth_dlg_save_options_done();
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_object_action_req
 * DESCRIPTION
 *  This is the generic request function to take some action on the selected
 *  rendered page item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_object_action_req(U16 sel_obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_object_action_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_object_action_req_struct*) OslConstructDataPtr(sizeof(wap_bam_object_action_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->type = sel_obj_type;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_OBJECT_ACTION_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_pre_entry_store_offline
 * DESCRIPTION
 *  Pre Entry function to display store offline screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_pre_entry_store_offline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_brw_cntx.document_info_p);

	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_title,
		(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->title);

	mmi_brw_this_page_entry_store_offline();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_sec_confirm_dialog_positive_res
 * DESCRIPTION
 *  positive response function for the security confirmation dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_sec_confirm_dialog_positive_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_sec_confirm_dialog_res(WPS_DLG_OK);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_sec_confirm_dialog_negative_res
 * DESCRIPTION
 *  neagtive response function for the security confirmation dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_sec_confirm_dialog_negative_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_sec_confirm_dialog_res(WPS_DLG_CANCEL);
	GoBackHistory();
}


#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_bkgrd_downloads_display_list
 * DESCRIPTION
 *  This function is used to display the background downloads list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_bkgrd_downloads_display_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_bkgrd_downloads_req(MMI_DA_WAP_NOTIFY_DISPLAY_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_suspend_bkgrd_downloads_accepted
 * DESCRIPTION
 *  This function is used to suspend the background downloads and then exit from
 *  the browser application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_suspend_bkgrd_downloads_accepted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_bkgrd_downloads_req(MMI_DA_WAP_NOTIFY_BROWSER_CLOSED);
	mmi_brw_app_exit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_suspend_bkgrd_downloads_rejected
 * DESCRIPTION
 *  This function is used to display the background downloads list and postpone
 *  the browser termination
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_suspend_bkgrd_downloads_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_bkgrd_downloads_req(MMI_DA_WAP_NOTIFY_DISPLAY_LIST);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_bkgrd_downloads_req
 * DESCRIPTION
 *  This function is used to send the request for displaying background
 *  downloads list or for terminating all downloads
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_bkgrd_downloads_req(mmi_da_wap_notify_enum notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_da_wap_notify_ind_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_da_wap_notify_ind_struct*) OslConstructDataPtr(sizeof(mmi_da_wap_notify_ind_struct));
	myMsgPtr->notify = notify;

    Message.src_mod_id = MOD_MMI;
    Message.dest_mod_id = MOD_MMI;
    Message.sap_id = WAP_MMI_SAP;
    Message.msg_id = (msg_type) MSG_ID_MMI_DA_WAP_NOTIFY_IND;
    Message.local_para_ptr = (local_para_struct*) myMsgPtr;
    Message.peer_buff_ptr = NULL;

    OslMsgSendExtQueue(&Message);
}
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERRENDEREDPAGE_C */


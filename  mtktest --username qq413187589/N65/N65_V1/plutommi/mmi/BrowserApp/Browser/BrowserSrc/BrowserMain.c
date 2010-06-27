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
 * BrowserMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function definations for Internet Services screen UI 
 *   including some browser common & initialization functions.
 *   
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
#ifndef MMI_BROWSERMAIN_C
#define MMI_BROWSERMAIN_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "PhoneBookDef.h"
#include "DataAccountGProt.h"   
#include "SMSApi.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserGprots.h"
#include "BrowserBookmarks.h"
#include "sat_def.h"
#include "Conversions.h"
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#include "PushInboxProts.h"
/*Include: NVRAM header file */
#include "ServiceDefs.h"
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#include "FileManagerDef.h"
#endif 
#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 
#include "app_url.h"

brw_context_struct g_brw_cntx;
U8 *g_brw_display_info_str;
U8 g_brw_current_url[(BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH];
U8 g_brw_current_title[(BRW_MAX_TITLE_LENGTH+1) * ENCODING_LENGTH];
brw_object_properties_struct g_brw_obj_properties_cntx;
S8 *gBrwOnOffStringArray[BRW_PREF_ON_OFF_TOTAL];
S8 *gBrwAlwaysNeverStringArray[BRW_PREF_ALWAYS_NEVER_TOTAL];
S8 *gBrwEnableDisableStringArray[BRW_PREF_ENABLE_DISABLE_TOTAL];
U8 g_brw_phone_number[(BRW_WTAI_PHONE_NUMBER_LEN+1) * ENCODING_LENGTH];
U32 g_brw_memory_pool_size = 0;
#ifdef APPMEM_SUPPORT
void* g_brw_memory_pool = NULL;
#else
U32 g_brw_memory_pool[BRW_ADM_MEMORY_POOL_SIZE / sizeof(U32)];
#endif /*APPMEM_SUPPORT*/
U16 g_brw_busy_scr_title_str_id = 0;
brw_file_detail_struct g_brw_open_file_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wap_init
 * DESCRIPTION
 *  Init function for browser application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_global_context_init();/*initializing browser global context*/

	mmi_brw_nvram_data_init();/*initializing browser nvram data*/

	mmi_brw_prof_init();/*initializing profile module*/

	mmi_brw_push_inbox_init();/*initializing push module*/

	mmi_prov_init();/*initializing provisioning module*/

	mmi_brw_event_hdlr_register_all_ilm_handlers();/*initializing browser protocol handlers*/

	mmi_brw_highlight_handlers_init();/*initializing browser highlight handlers*/

#ifdef APPMEM_SUPPORT
applib_mem_ap_register(
        APPLIB_MEM_AP_ID_BROWSER, 
        SERVICES_WAP_STRING_ID, 
        SERVICES_WAP_IMAGE_ID, 
        mmi_brw_asm_stop_app_callback);
#endif /*APPMEM_SUPPORT*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_init
 * DESCRIPTION
 *  Initialize the browser application whenever user enters into the wap menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*resettting the browser global context*/
	g_brw_cntx.isBrowserFetching	= MMI_FALSE;
	g_brw_cntx.mainMenuEntryFlag	= MMI_FALSE;
	g_brw_cntx.select_mode_flag		= MMI_FALSE;
	g_brw_cntx.brw_first_page_flag	= MMI_TRUE;
	g_brw_cntx.list_refresh_flag	= MMI_FALSE;
	g_brw_cntx.address_list_flag	= MMI_FALSE;
	g_brw_cntx.reset_hiliter_flag	= MMI_FALSE;
	g_brw_cntx.top_scr_id			= SCR_ID_BRW_FIRST_SCREEN_ID;

	/*initializing the global string arrays*/
    gBrwOnOffStringArray[BRW_PREF_OFF_INDEX]			 = GetString(STR_GLOBAL_OFF);
    gBrwOnOffStringArray[BRW_PREF_ON_INDEX]				 = GetString(STR_GLOBAL_ON);

    gBrwAlwaysNeverStringArray[BRW_PREF_NEVER_INDEX]	 = GetString(STR_ID_BRW_NEVER);
    gBrwAlwaysNeverStringArray[BRW_PREF_ALWAYS_INDEX]	 = GetString(STR_ID_BRW_ALWAYS);

	gBrwEnableDisableStringArray[BRW_PREF_DISABLE_INDEX] = GetString(STR_ID_BRW_DISABLE);
    gBrwEnableDisableStringArray[BRW_PREF_ENABLE_INDEX]	 = GetString(STR_ID_BRW_ENABLE);

    gBrwAuthDlgSaveOptionStringArray[BRW_AUTH_DLG_SAVE_NONE_INDEX]		= GetString(STR_ID_BRW_SAVE_NONE);
    gBrwAuthDlgSaveOptionStringArray[BRW_AUTH_DLG_SAVE_BOTH_INDEX]		= GetString(STR_ID_BRW_SAVE_BOTH);
    gBrwAuthDlgSaveOptionStringArray[BRW_AUTH_DLG_SAVE_USERNAME_INDEX]	= GetString(STR_ID_BRW_SAVE_ONLY_USERNAME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_address_highlight_handlers_init
 * DESCRIPTION
 *  This function is used for registering highlight for send address menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_address_highlight_handlers_init(void)
{
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    SetHiliteHandler(MENU_ID_BRW_SEND_ADDRESS_AS_SMS, mmi_brw_send_addr_text_msg_highlight_hdlr);
#endif
#if defined(__MMI_MMS__)
    SetHiliteHandler(MENU_ID_BRW_SEND_ADDRESS_AS_MMS, mmi_brw_send_addr_multimedia_msg_highlight_hdlr);    
#endif
#if  defined(__MMI_IRDA_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
	SetHiliteHandler(MENU_ID_BRW_SEND_ADDRESS_VIA_INFRARED, mmi_brw_send_addr_via_infrared_highlight_hdlr);
#endif
#if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
    SetHiliteHandler(MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH, mmi_brw_send_addr_via_bluetooth_highlight_hdlr);
#endif
#if  defined(__MMI_EMAIL__)
    SetHiliteHandler(MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL, mmi_brw_send_addr_via_email_highlight_hdlr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of homepage menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_entry_homepage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_inbox_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of service inbox menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_inbox_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    
    SetLeftSoftkeyFunction(mmi_brw_push_pre_entry_inbox_validation, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_push_pre_entry_inbox_validation, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_internet_services
 * DESCRIPTION
 *  This is the external interface to display internet services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_internet_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        g_brw_cntx.brw_launching_pad = BRW_LPD_MAIN_MENU;
	mmi_brw_common_gateway();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_internet_services
 * DESCRIPTION
 *  Entry function for Internet services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_internet_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U16* UC_list_of_icons;
    U8 *guiBuffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_INTERNET_SERVICES, NULL, mmi_brw_entry_internet_services, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_INTERNET_SERVICES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	//de-allocate memory for recent pages and stored pages
	mmi_brw_recent_pages_get_recent_pages_list_end_req();
	mmi_brw_stored_pages_get_saved_pages_list_end_req();

#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
		/*if background download is not active*/
		if( !g_brw_cntx.download_info_p ||
			!g_brw_cntx.download_info_p->job_count)
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_DOWNLOADS);
		}
		else /*if background download is active*/
		{
			mmi_frm_unhide_menu_item(MENU_ID_BRW_REN_PAGE_DOWNLOADS);
		}
#else 
		mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_DOWNLOADS);
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/

    num_of_items = GetNumOfChild_Ext(SERVICES_WAP_MENU_ID);
    UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    UC_list_of_icons = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds_Ext(SERVICES_WAP_MENU_ID, UC_list_of_items);
    GetSequenceImageIds_Ext(SERVICES_WAP_MENU_ID, UC_list_of_icons);
    SetParentHandler(SERVICES_WAP_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_INTERNET_SERVICES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        UC_list_of_items,
        UC_list_of_icons,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_brw_GoBackServicesMenu, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_GoBackServicesMenu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	OslMfree(UC_list_of_items);
	OslMfree(UC_list_of_icons);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_GoBackServicesMenu
 * DESCRIPTION
 *  Function to go back to services menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_GoBackServicesMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
	if( g_brw_cntx.download_info_p &&
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
 *  mmi_brw_entry_homepage
 * DESCRIPTION
 *  Entry function for homepage menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *currProfStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.homepage_settings_index == BRW_USER_DEFINED_HOMEPAGE)
	{
		mmi_asc_to_ucs2((S8*)g_brw_current_url, (S8*)g_brw_cntx.user_defined_hmpage_url);
	}
	else if(g_brw_cntx.homepage_settings_index == BRW_ACTIVE_PROFILE_HOMEPAGE)
	{
		currProfStruct = (nvram_profile_content_struct *)mmi_brw_prof_get_activated_wap_profile();
		mmi_asc_to_ucs2((S8*)g_brw_current_url, (S8*)currProfStruct->url);
	}
	else
	{
		mmi_ucs2cpy((S8*)g_brw_current_url, (S8*)" ");
	}
	mmi_brw_pre_entry_goto_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_clear_key_handler
 * DESCRIPTION
 *  Clear all key types handler for agiven key code
 * PARAMETERS
 *  key_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_clear_key_handler(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(key_code, KEY_EVENT_UP);
    ClearKeyHandler(key_code, KEY_EVENT_DOWN);
    ClearKeyHandler(key_code, KEY_LONG_PRESS);
    ClearKeyHandler(key_code, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_deinit
 * DESCRIPTION
 *  Free the memory allocated and close the browser window.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*sending the default response for confirmation dialogs in case*/ 
	/*user exit from the browser without giving any response*/
	if(g_brw_cntx.security_dlg_flag && g_brw_cntx.sec_confirm_dlg_info_p)
	{
		g_brw_cntx.security_dlg_flag = MMI_FALSE;
		if(g_brw_cntx.sec_confirm_dlg_info_p->buttons == WPS_DLG_BUTTON_YESNO)
		{
			mmi_brw_ren_page_sec_confirm_dialog_negative_res();
		}
		else
		{
			mmi_brw_ren_page_sec_confirm_dialog_positive_res();
		}
	}
	if(g_brw_cntx.auth_dlg_flag && g_brw_cntx.http_auth_info_p)
	{
		g_brw_cntx.auth_dlg_flag = MMI_FALSE;
		mmi_brw_ren_page_auth_dlg_cancel();
	}

	/*releasing memory when browser instance is being created*/
	if(g_brw_cntx.isBrowserInstance)
	{
		mmi_brw_delete_all_browser_screens();

		mmi_brw_recent_pages_get_recent_pages_list_end_req();
		mmi_brw_stored_pages_get_saved_pages_list_end_req();
		mmi_brw_this_page_get_resource_list_end_req();
		mmi_brw_delete_instance_req();
	}
	/*releasing memory when browser instance is not created but ASM is allocated for Select Bookmark Screen*/
	else if(g_brw_bkm_sel_bkm_pool)
	{
		g_brw_bkm_sel_bkm_pool = MMI_FALSE;

		/*de-initalize ADM memory*/
		if(g_brw_cntx.brw_adm_id)
		{
			kal_adm_delete(g_brw_cntx.brw_adm_id);
			g_brw_cntx.brw_adm_id = NULL;
		}

		/*de-allocate browser app ASM memory */
		if(g_brw_memory_pool)
		{
			applib_mem_ap_free(g_brw_memory_pool);
			g_brw_memory_pool = NULL;
		}

		/*reset browser engine ASM memory */
 		resetAppMemPool();

		/*if the browser app is terminated by some other App then
		send the success notification to MMI*/
		if(g_brw_cntx.brw_launching_pad == BRW_LPD_ASM_TERMINATE)
		{
			/* Notify MMI that this application is already stopped */
			applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_BROWSER, KAL_TRUE);
			g_brw_cntx.brw_launching_pad = BRW_LPD_NONE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_memory_card_plug_out_hdlr
 * DESCRIPTION
 *  This function is called from file manager to deinitalize browser if memory
 *  card is removed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_memory_card_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 currScrId;
	U16 nextScrId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*check whether file manager screen is present or not*/
    if(IsScreenPresent(SCR_FMGR_MAIN))
	{
		currScrId = SCR_FMGR_MAIN;
		
		/*check whether browser screen is present after file manager screen in history*/
		while(GetNextScrnIdOf(currScrId, &nextScrId))
		{
			if( nextScrId == SCR_ID_BRW_INTERNET_SERVICES || 
				nextScrId == SCR_ID_BRW_BROWSER_MAIN
			    )
			{
				mmi_brw_app_deinit();
				return;
			}
			currScrId = nextScrId;
		}

		/*check whether browser screen is the topmost history screen*/
		if( GetActiveScreenId() == SCR_ID_BRW_INTERNET_SERVICES ||
			GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN
			)
		{
				mmi_brw_app_deinit();
				return;
		}
	}	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wap_deinit
 * DESCRIPTION
 *  Free the memory allocated and close the browser window.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_goto_url
 * DESCRIPTION
 *  Pre Entry function for fetching url i.e when the user wants to fetch a page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_goto_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;
	//g_brw_cntx.do_element_count = 0;

	mmi_brw_load_url_req(g_brw_current_url);
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_open_file
 * DESCRIPTION
 *  Pre Entry function for opening a selected wap file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_open_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.isBrowserFetching = MMI_TRUE;
	mmi_brw_load_data_req();
	mmi_brw_entry_render_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_render_page
 * DESCRIPTION
 *  Entry function for fetching url i.e when the user wants to fetch a page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_render_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    //U8 flag = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BROWSER_MAIN, mmi_brw_exit_render_page, mmi_brw_entry_render_page, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BROWSER_MAIN);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if (IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteNScrId(SCR_ID_BRW_BROWSER_MAIN);
	}

	if(mmi_brw_is_browser_first_page())
	{
		ShowCategory132Screen(
				0,
				0,
				0,
				0,
				0,
				0,
				IMG_ID_BRW_SPLASH_SCREEN,
				guiBuffer);

		StartTimer(BRW_SPLASH_SCREEN_TIMER, 3000, mmi_brw_splash_screen_timer_callback);
		mmi_brw_splash_screen_set_title_string_and_icon();
	}
	else
	{
		ShowCategory431Screen(
				(U8*)mmi_brw_ren_page_get_title_string(),
				(U16)mmi_brw_ren_page_get_title_icon(),
				0,
				0,
				0,
				0,
				0,
				mmi_brw_ren_page_pen_handler,
				g_brw_cntx.screen_size_status,
				guiBuffer);

        mmi_brw_register_keypad_handler_req();
        mmi_brw_ren_page_notify_screen_info_req(MMI_TRUE);

		mmi_brw_ren_page_resume_owl_rendering_req();
	}

	mmi_brw_ren_page_set_LSK();
	mmi_brw_ren_page_set_RSK();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_render_page
 * DESCRIPTION
 *  Exit function for fetching url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_render_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_ren_page_suspend_owl_rendering_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_browser_busy_screen
 * DESCRIPTION
 *  Entry function for fetching url i.e when the user wants to fetch a page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_browser_busy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
	{
		return;
	}

    EntryNewScreen(SCR_ID_BRW_BUSY_SCREEN, NULL, mmi_brw_entry_browser_busy_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BUSY_SCREEN);
	
	DeleteScreenIfPresent(SCR_ID_BRW_BUSY_SCREEN);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	ShowCategory66Screen(
			g_brw_busy_scr_title_str_id,
			GetRootTitleIcon(SERVICES_WAP_MENU_ID),
			0,
			0,
			0,
			0,
			(U8*)GetString(STR_ID_BRW_PLEASE_WAIT),
			IMG_PROCESSING_PHONEBOOK,
			guiBuffer);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_temp_busy_screen
 * DESCRIPTION
 *  Entry function for temporary busy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_temp_busy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_brw_is_browser_screen(mmi_brw_get_top_screen_id()))
	{
		return;
	}

    EntryNewScreen(SCR_ID_BRW_TEMP_BUSY_SCREEN, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_TEMP_BUSY_SCREEN);

	DeleteScreenIfPresent(SCR_ID_BRW_TEMP_BUSY_SCREEN);

	ShowCategory66Screen(
			g_brw_busy_scr_title_str_id,
			GetRootTitleIcon(SERVICES_WAP_MENU_ID),
			0,
			0,
			0,
			0,
			(U8*)GetString(STR_ID_BRW_PLEASE_WAIT),
			IMG_PROCESSING_PHONEBOOK,
			guiBuffer);

	ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_validate_url
 * DESCRIPTION
 *  Utility function to validate the url.
 * PARAMETERS
 *  url_p       [IN]     Url in unicode to be validated
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_brw_validate_url(U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 temp[BRW_MAX_URL_LENGTH + 1];
	U8 url_ascii[BRW_MAX_URL_LENGTH+1];
	//S32 error_code;
	U8 uri_schm_len;
	applib_url_struct url_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	MMI_ASSERT(url_p);

	/*check the zero length and white spaces in the URL string*/
	if(!mmi_ucs2strlen((S8*)url_p) || mmi_brw_check_white_spaces((S8*)url_p))
	{
		return APPLIB_URL_ERR_INVALID_PARAM;
	}

	/* convert the UCS2 URL string into UTF-8 */
    mmi_chset_ucs2_to_utf8_string((U8*)url_ascii, BRW_MAX_URL_LENGTH + 1,(U8*)url_p);

	/* parse the URL string by using Applib API */
	if(!(S32)applib_parse_url((S8*)url_ascii, &url_info))
	{
		/* if there is an empty URI scheme in the URL then append the default ("http://") */
		/* URI scheme */
		if(url_info.scheme_type == applib_scheme_empty)
	    {
		    uri_schm_len = strlen((S8*)BRW_DEFAULT_URI_SCHEME);
		    if( strlen((S8*)url_ascii) > (BRW_MAX_URL_LENGTH - uri_schm_len) )
		    {
			    strncpy((S8*)temp, (S8*)url_ascii, BRW_MAX_URL_LENGTH  - uri_schm_len);
			    temp[BRW_MAX_URL_LENGTH  - uri_schm_len] = '\0';
		    }
		    else
		    {
		        strcpy((S8*)temp, (S8*)url_ascii);
		    }
		    strcpy((S8*)url_ascii, (S8*)BRW_DEFAULT_URI_SCHEME);
		    strcat((S8*)url_ascii, (S8*)temp);
		    mmi_chset_utf8_to_ucs2_string((U8*)url_p, (BRW_MAX_URL_LENGTH + 1)* ENCODING_LENGTH, (U8*)url_ascii);
  
		    /* check whether it contain HTTP or HTTPS URI scheme with empty host */
		    if(!(S32)applib_parse_url((S8*)url_ascii, &url_info))
		    {
			    if( url_info.scheme_type == applib_scheme_http ||
				    url_info.scheme_type == applib_scheme_https
				    )
			    {
				    if(!url_info.len[APPLIB_URL_HOST_PART])
				    {
					    return APPLIB_URL_ERR_INVALID_HOST;
	                }
			    }
		    }
	    }
	    /* check whether it contain HTTP or HTTPS URI scheme with empty host */
	    else if( url_info.scheme_type == applib_scheme_http ||
			     url_info.scheme_type == applib_scheme_https
			    )
	    {
		    if(!url_info.len[APPLIB_URL_HOST_PART])
	        {
			    return APPLIB_URL_ERR_INVALID_HOST;
		    }
	    }
    }

	/* validate the UTF-8 URL string by using Applib API */
	return (S32)applib_url_is_valid((S8*)url_ascii); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_as_homepage
 * DESCRIPTION
 *  Interface function to set the url as homepage
 * PARAMETERS
 *  url_p       [IN]		It is an ascii string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_as_homepage(U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(url_p);

	mmi_asc_to_ucs2((S8*)g_brw_current_url, (S8*)url_p);

	mmi_brw_set_as_homepage_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dummy_func
 * DESCRIPTION
 *  Its a dummy function and will be removed later
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_send_address
 * DESCRIPTION
 *  Entry function for Send Address Options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_send_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* nStrItemList;
    U8 *guiBuffer;
    S32 num_of_items;
    S32 HideItemId = -1;
    U32 maskingByte = 0xffffffff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SEND_ADDRESS_OPTIONS, NULL, mmi_brw_entry_send_address, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SEND_ADDRESS_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    num_of_items = GetNumOfChild(MENU_ID_BRW_SEND_ADDRESS_OPTIONS);
    nStrItemList = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_BRW_SEND_ADDRESS_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_send_address_highlight_handlers_init(); /* Register highlight handler every time you enter into options */

#if defined(MMS_SUPPORT)
    if ( isInCall() /*|| IsScreenPresent((U16)wap_get_screen_id())*/
	#if defined (__FLIGHT_MODE_SUPPORT__)
         || (mmi_bootup_get_active_flight_mode() == 1)
    #endif /* defined(__FLIGHT_MODE_SUPPORT__) */
         || (!mmi_bootup_is_sim_valid())
		)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, MENU_ID_BRW_SEND_ADDRESS_AS_MMS);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }
#endif /* defined(MMS_SUPPORT) */ 

	if ( !mmi_bootup_is_sim_valid()
    #if defined (__FLIGHT_MODE_SUPPORT__)
         || (mmi_bootup_get_active_flight_mode() == 1)
    #endif
        )
    {
		#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
			HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, MENU_ID_BRW_SEND_ADDRESS_AS_SMS);
			if (HideItemId != -1)
			{
				ResetBit(maskingByte, HideItemId);
			}
		#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */

		#if  defined(__MMI_IRDA_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
			HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, MENU_ID_BRW_SEND_ADDRESS_VIA_INFRARED);
			if (HideItemId != -1)
			{
				ResetBit(maskingByte, HideItemId);
			}
		#endif	/* defined(__MMI_IRDA_SUPPORT__) && defined(__MMI_VBOOKMARK__) */

		#if  defined(__MMI_EMAIL__)
			HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL);
			if (HideItemId != -1)
			{
				ResetBit(maskingByte, HideItemId);
			}
		#endif /* __MMI_EMAIL__ */
    }

#if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
	if((mmi_bootup_get_active_flight_mode() == 1))
	{
		HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH);
		if (HideItemId != -1)
		{
			ResetBit(maskingByte, HideItemId);
		}
	}
#endif /* defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__) */

	MaskHiliteItems(MENU_ID_BRW_SEND_ADDRESS_OPTIONS, maskingByte);
	num_of_items = MaskItems(nStrItemList, (U8) num_of_items, maskingByte);

    ShowCategory15Screen(
        STR_ID_BRW_SEND_ADDRESS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    OslMfree(nStrItemList);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_convert_int_to_unicode_string
 * DESCRIPTION
 *  Function to make the string from a value
 * PARAMETERS
 *  StringVal       [?]         
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_convert_int_to_unicode_string(U8 *StringVal, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 StrVal[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(StrVal, "%d", value);
    mmi_asc_to_ucs2((S8*)StringVal, (S8*)StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_convert_unicode_string_to_int
 * DESCRIPTION
 *  Function to make the string from a value
 * PARAMETERS
 *  StringVal       [?]         
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_convert_unicode_string_to_int(U8 *StringVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 StrVal[20];	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(StrVal, (S8*)StringVal);
    return atoi(StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_memory_status
 * DESCRIPTION
 *  This func is used for displaying the memory status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_MEMORY_STATUS, NULL, mmi_brw_entry_memory_status, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_MEMORY_STATUS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    ShowCategory74Screen(
        STR_ID_BRW_MEMORY_STATUS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_brw_display_info_str,
        mmi_ucs2strlen((S8*)g_brw_display_info_str)+1,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_brw_display_info_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_display_info_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_view_url
 * DESCRIPTION
 *  This func is used for displaying the URL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_view_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_VIEW_URL, NULL, mmi_brw_entry_view_url, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_VIEW_URL);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    ShowCategory74Screen(
        STR_ID_BRW_VIEW,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_brw_current_url,
        mmi_ucs2strlen((S8*)g_brw_current_url),
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_open_file_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of open file menu item
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_open_file_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_open_file, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_open_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_last_web_address_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of last web address menu item
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_last_web_address_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_last_web_address, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_open_file
 * DESCRIPTION
 *  This function is used for opening the selected web file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_open_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WML);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_HTML);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_HTM);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_XHTML);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
	mmi_fmgr_select_path_and_enter
	(
       APP_WAP,
       FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
       filter,
       (PS8) L"root",
       mmi_brw_open_file_callback
	);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_last_web_address
 * DESCRIPTION
 *  This function is used for opening last web address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_last_web_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(strlen((S8*)g_brw_cntx.last_web_address) == 0)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_EMPTY), 
			IMG_GLOBAL_EMPTY, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			EMPTY_LIST_TONE);

	}
	else
	{
		mmi_asc_to_ucs2((S8*)g_brw_current_url, (S8*)g_brw_cntx.last_web_address);
		mmi_brw_pre_entry_goto_url();
	}
}


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_text_msg_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of sending URL as text msg to other device
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_text_msg_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_send_addr_text_msg, KEY_EVENT_UP);
    //SetKeyHandler(mmi_brw_send_addr_text_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_text_msg
 * DESCRIPTION
 *  Function for sending URL as text msg to other device
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_text_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct *sendData = mmi_brw_malloc(sizeof(mmi_frm_sms_api_entry_write_struct));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendData->string = (S8*)g_brw_current_url;
    sendData->stringlength = mmi_ucs2strlen((S8*)g_brw_current_url);
    sendData->dcs = SMSAL_UCS2_DCS;
    sendData->flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    sendData->ascii_addr = NULL;
    sendData->filename = NULL;

    mmi_frm_sms_api_entry_write_msg(sendData);
    mmi_brw_mfree(sendData);
}
#endif


#if defined(__MMI_MMS__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_multimedia_msg_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of sending URL as multimedia msg to other device
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_multimedia_msg_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_send_addr_multimedia_msg, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_multimedia_msg
 * DESCRIPTION
 *  Function for sending URL as multimedia msg to other device
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_multimedia_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_text_insert_hdlr(NULL,0,(S8*)g_brw_current_url,mmi_ucs2strlen((S8*)g_brw_current_url));
}
#endif


#if  defined(__MMI_IRDA_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_infrared_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of sending URL to other device via infrared
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_infrared_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_send_addr_via_infrared, KEY_EVENT_UP);
    //SetKeyHandler(mmi_brw_send_addr_via_infrared, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_infrared
 * DESCRIPTION
 *  Function for sending URL to other device via infrared
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_infrared(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 def_drive_str[BRW_BKM_DRIVE_NAME_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf((S8*)def_drive_str, "%c", BRW_TEMP_VBKM_FILE_DRIVE);

	mmi_asc_to_ucs2((S8*)g_brw_open_file_cntx.file_path, (S8*)def_drive_str);
	mmi_ucs2cat((S8*)g_brw_open_file_cntx.file_path, (S8*)L":");
	mmi_ucs2cat((S8*)g_brw_open_file_cntx.file_path, (S8*)BRW_TEMP_VBKM_FILE_PATH);

	if(mmi_brw_bookmarks_create_standard_vbookmark_file(g_brw_open_file_cntx.file_path, g_brw_current_url))
	{
        if ( MMI_IRDA_ERR_SUCCESS == 
			 mmi_irda_send_file_obj((S8*)g_brw_open_file_cntx.file_path, mmi_brw_send_addr_via_infrared_callback)
			)
        {
            mmi_brw_entry_irda_processing_screen();
        }
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_infrared_callback
 * DESCRIPTION
 *  callback function for sending address via infrared
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_infrared_callback(void* buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free buffer if send to IrDA by using SRAM */
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    if (result == MMI_IRDA_ERR_SUCCESS)
    {
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
					TRUE,
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
	FS_Delete((UI_string_type)g_brw_open_file_cntx.file_path);/*delete temporary vbookmark file*/
    DeleteBetweenScreen(SCR_ID_BRW_SEND_ADDRESS_OPTIONS, SCR_ID_BRW_IRDA_FORWARD_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_irda_processing_screen
 * DESCRIPTION
 *  Display progressing screen when sending item via irda
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_irda_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_IRDA_FORWARD_PROCESSING, NULL, mmi_brw_entry_irda_processing_screen, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show Sending screen */
    ShowCategory66Screen(
        STR_GLOBAL_ACTIVATE,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_ACTIVATE),
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(
        SCR_ID_BRW_IRDA_FORWARD_PROCESSING,
        (HistoryDelCBPtr) mmi_brw_irda_progress_scr_del_callback);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_irda_obex_snd_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_irda_progress_scr_del_callback
 * DESCRIPTION
 *  Callback function when Irda progressing screen is deleted
 * PARAMETERS
 *  ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_brw_irda_progress_scr_del_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_irda_is_sending())  /* if Irda is sending, do not deleted this screen */
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* defined(__MMI_IRDA_SUPPORT__)	&& defined(__MMI_VBOOKMARK__) */


#if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_bluetooth_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of sending URL other device via bluetooth
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_bluetooth_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_send_addr_via_bluetooth, KEY_EVENT_UP);
    //SetKeyHandler(mmi_brw_send_addr_via_bluetooth, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_bluetooth
 * DESCRIPTION
 *  Function for sending URL to other device via bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_bluetooth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 def_drive_str[BRW_BKM_DRIVE_NAME_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf((S8*)def_drive_str, "%c", BRW_TEMP_VBKM_FILE_DRIVE);

	mmi_asc_to_ucs2((S8*)g_brw_open_file_cntx.file_path, (S8*)def_drive_str);
	mmi_ucs2cat((S8*)g_brw_open_file_cntx.file_path, (S8*)L":");
	mmi_ucs2cat((S8*)g_brw_open_file_cntx.file_path, (S8*)BRW_TEMP_VBKM_FILE_PATH);

	if(mmi_brw_bookmarks_create_standard_vbookmark_file(g_brw_open_file_cntx.file_path, g_brw_current_url))
	{
		/* call send via bluetooth API */
        if ( MMI_OPP_ERR_SUCCESS == 
			 mmi_opp_discovery_device((S8*) g_brw_open_file_cntx.file_path, mmi_brw_send_addr_via_bluetooth_callback)
			)
        {
            mmi_opp_entry_opp_device_discovery();
        }
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_bluetooth_callback
 * DESCRIPTION
 *  callback function for sending address via bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_bluetooth_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free buffer if send to bt by using SRAM */
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    if (result == MMI_OPP_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
   }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
	FS_Delete((UI_string_type)g_brw_open_file_cntx.file_path);/*delete temporary vbookmark file*/
    DeleteBetweenScreen(SCR_ID_BRW_SEND_ADDRESS_OPTIONS, SCR_OPP_SENDING);
}
#endif /* defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__) */


#if  defined(__MMI_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_email_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of sending URL to other device via email
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_email_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_send_addr_via_email, KEY_EVENT_UP);
    //SetKeyHandler(mmi_brw_send_addr_via_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_addr_via_email
 * DESCRIPTION
 *  Function for sending URL to other device via email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_addr_via_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_email_app_send_cont((S8*)g_brw_current_url);
}
#endif /* __MMI_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_object_properties
 * DESCRIPTION
 *  Entry function for store page properties
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_object_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
	U16 objPropertiesImageList[2*BRW_OBJECT_PROP_MAX_COUNT] = 
	{
		IMG_GLOBAL_L1,
		0,
		IMG_GLOBAL_L2,
		0,
		IMG_GLOBAL_L3,
		0,
		IMG_GLOBAL_L4,
		0,
	};


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_OBJECT_PROPERTIES, mmi_brw_exit_object_properties, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_OBJECT_PROPERTIES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();

    DisableCategory57ScreenDone();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_OBJECT_PROPERTIES, &inputBufferSize);

    SetParentHandler(0);

    mmi_brw_inline_struct_for_object_properties();

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2*g_brw_obj_properties_cntx.prop_count, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_BRW_PROPERTIES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        NULL,
        2*g_brw_obj_properties_cntx.prop_count,
		objPropertiesImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_inline_struct_for_object_properties
 * DESCRIPTION
 *  Function to fill values in stored page properties inine edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_inline_struct_for_object_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8	prop_index=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_NAME])
	{

		/****************** Page Name ******************/
		/* Caption */
		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemCaption((&wgui_inline_items[prop_index++]), 
			(U8*) GetString(STR_ID_BRW_NAME));

		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemDisplayOnly((&wgui_inline_items[prop_index++]), 
			(U8*) g_brw_obj_properties_cntx.obj_name);
		/****************** Page Name ******************/
	}


	if(g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_ADDRESS])
	{
		/****************** Page Address ******************/
		/* Caption */
		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemCaption((&wgui_inline_items[prop_index++]), 
			(U8*) GetString(STR_ID_BRW_ADDRESS));

		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemDisplayOnly((&wgui_inline_items[prop_index++]), 
			(U8*) g_brw_obj_properties_cntx.obj_address);
		/****************** Page Address ******************/
	}

	if(g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_SIZE])
	{
		/****************** Page Size ******************/
		/* Caption */
		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemCaption((&wgui_inline_items[prop_index++]), 
			(U8*) GetString(STR_ID_BRW_CONTENT_SIZE));

		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemDisplayOnly((&wgui_inline_items[prop_index++]), 
			(U8*) g_brw_obj_properties_cntx.obj_size);
		/****************** Page Size ******************/
	}

	if(g_brw_obj_properties_cntx.prop_status[BRW_OBJECT_PROP_DATE])
	{
		/****************** Page Date ******************/
		/* Caption */
		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemCaption((&wgui_inline_items[prop_index++]), 
			(U8*) GetString(STR_ID_BRW_DATE));

		SetInlineItemActivation((&wgui_inline_items[prop_index]), 
			INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
		SetInlineItemDisplayOnly((&wgui_inline_items[prop_index++]), 
			(U8*) g_brw_obj_properties_cntx.obj_date);
		/****************** Page Date ******************/
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_object_properties
 * DESCRIPTION
 *  Exit function for stored page properties screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_object_properties(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_BRW_OBJECT_PROPERTIES;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_entry_object_properties;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_object_properties_reset
 * DESCRIPTION
 *  Function to fill values in stored page properties inine edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_object_properties_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(index = 0; index < BRW_OBJECT_PROP_MAX_COUNT; index++)
	{
		g_brw_obj_properties_cntx.prop_status[index] = MMI_FALSE;
	}
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_name, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_address, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_size, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_obj_properties_cntx.obj_date, (S8*)L"");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_browser_first_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_brw_is_browser_first_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool) g_brw_cntx.brw_first_page_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_splash_screen_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_splash_screen_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.brw_first_page_flag = MMI_FALSE;
	if(GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
	{
	    mmi_brw_entry_render_page();
        DeleteScreenIfPresent(SCR_ID_BRW_BROWSER_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_open_file_callback
 * DESCRIPTION
 *  external call back for file manager select html file function
 * PARAMETERS
 *  fullname        [IN]	selected filename        
 *  is_short        [IN]    file name type    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_open_file_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 temp[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(fullname)
	{
		mmi_asc_to_ucs2((S8 *)temp, (S8 *)"file:\\\\\\");
		mmi_ucs2cpy((S8 *)g_brw_open_file_cntx.file_path, (S8 *)temp);
		mmi_ucs2cat((S8 *)g_brw_open_file_cntx.file_path, (S8 *)fullname);
		mmi_brw_pre_entry_open_file();
	}
	else
	{
		GoBackHistory();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_open_file_from_fmgr
 * DESCRIPTION
 *  an external interface for opening a html file from file manager
 * PARAMETERS
 *  fullname        [IN]	selected filename        
 *  is_short        [IN]    file name type    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_open_file_from_fmgr(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 temp[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!fullname)
	{
		GoBackHistory();
	}

	mmi_asc_to_ucs2((S8 *)temp, (S8 *)"file:\\\\\\");
	mmi_ucs2cpy((S8 *)g_brw_open_file_cntx.file_path, (S8 *)temp);
	mmi_ucs2cat((S8 *)g_brw_open_file_cntx.file_path, (S8 *)fullname);

    g_brw_cntx.brw_launching_pad = BRW_LPD_EXTERNAL_LOAD_DATA_REQ;
	mmi_brw_common_gateway();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_highlight_handlers_init
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_highlight_handlers_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_BRW_HOMEPAGE, mmi_brw_homepage_highlight_hdlr);

#ifdef __MMI_VBOOKMARK__
	mmi_brw_bookmarks_highlight_handlers_init();
#endif /*__MMI_VBOOKMARK__*/

	mmi_brw_address_list_highlight_handlers_init();

	mmi_brw_recent_pages_highlight_handlers_init();

	mmi_brw_stored_pages_highlight_handlers_init();

    SetHiliteHandler(MENU_ID_BRW_PUSH_INBOX, mmi_brw_push_inbox_menu_highlight_hdlr);

    /* Set highlight handlers for settings menu items */
    mmi_brw_settings_highlight_handlers_init();

    /* Set highhandlers for rendered page menu items */
    mmi_brw_ren_page_highlight_handlers_init();

    /* Set highhandlers for send adsress menu items */
    mmi_brw_send_address_highlight_handlers_init();

    SetHiliteHandler(MENU_ID_BRW_OPEN_FILE, mmi_brw_open_file_highlight_hdlr);

    SetHiliteHandler(MENU_ID_BRW_LAST_WEB_ADDR, mmi_brw_last_web_address_highlight_hdlr);

	/*full screen editor highlight handlers*/
    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_CANCEL, mmi_brw_editor_cancel_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_INPUT_METHOD, mmi_brw_editor_input_method_highlight_hdlr);
	/*full screen editor highlight handlers*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_nvram_data_init
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_nvram_data_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_read_last_web_address();

	mmi_brw_settings_read_user_defined_homepage();

	mmi_brw_recent_pages_read_sorting_method();

	mmi_brw_settings_nvram_data_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_instance_req
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_create_instance_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_create_instance_req_struct *myMsgPtr;
    GDI_HANDLE title_layer = 0;
    GDI_HANDLE bottom_layer = 0;
    U32 x=0;
    U32 y=0;
    U32 w=0;
    U32 h=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*if this flag is TRUE then there is no need of showing busy screen*/ 
	/*again because in this case it should have displayed from common*/ 
	/*gateway interface*/
	if(g_brw_cntx.common_gateway_flag)
	{
		g_brw_cntx.common_gateway_flag = MMI_FALSE;
	}
	else
	{
	    /*showing the busy screen*/
	    mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_INTERNET_SERVICES);
        mmi_brw_entry_browser_busy_screen();
	}

    myMsgPtr = (wap_bam_create_instance_req_struct*) OslConstructDataPtr(sizeof(wap_bam_create_instance_req_struct));

    Cat431GetScreenInfo(g_brw_cntx.screen_size_status,&x,&y,&w,&h,&title_layer,&bottom_layer);

    myMsgPtr->src = MOD_MMI;
    myMsgPtr->is_full_screen = (kal_bool) g_brw_cntx.screen_size_status;
    myMsgPtr->window_position_x  = x;
    myMsgPtr->window_position_y  = y;
    myMsgPtr->window_size_height = h;
    myMsgPtr->window_size_width  = w;
    myMsgPtr->category_lyr_a_hndl = title_layer;
    myMsgPtr->category_lyr_b_hndl = bottom_layer;

    mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_instance_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_instance_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_bam_delete_instance_req_struct*	myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_brw_cntx.isDeleteInsReqPending)
	{
		g_brw_cntx.isDeleteInsReqPending = MMI_TRUE;

		myMsgPtr = (wap_bam_delete_instance_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_instance_req_struct));
	    myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
    
	    mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ, myMsgPtr, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_load_url_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  url		[IN]	url in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_load_url_req(U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_bam_load_url_req_struct*	myMsgPtr;
	U8 url_ascii[BRW_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2_to_asc((S8*)url_ascii, (S8*)url);
    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserMain.c] mmi_brw_load_url_req url = %s\n", url_ascii);

    myMsgPtr = (wap_bam_load_url_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_url_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->options = WAP_BAM_OPTION_KEEP_WML_CONTEXT;
	myMsgPtr->charset = g_brw_cntx.charset_list_p[g_brw_cntx.encoding_method_index].id;
    mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->url,BRW_MAX_URL_LENGTH + 1,(U8*)url);

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_URL_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_load_data_req
 * DESCRIPTION
 *  This func is used for opening the selected wap file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_load_data_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_bam_load_data_req_struct*	myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_load_data_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_data_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->options = 0;
  	myMsgPtr->charset = g_brw_cntx.charset_list_p[g_brw_cntx.encoding_method_index].id;
    mmi_chset_ucs2_to_utf8_string
		((U8*)myMsgPtr->content_path,WAP_BAM_MAX_FILE_PATH_LEN + 1,(U8*)g_brw_open_file_cntx.file_path);

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_DATA_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_active_profile_changed
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_active_profile_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_ACTIVATE_PROFILE);
	mmi_brw_entry_browser_busy_screen();

	g_brw_cntx.brw_launching_pad = BRW_LPD_ACTIVE_PROFILE_CHANGED;
	mmi_brw_settings_set_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_active_profile_changed_without_ui
 * DESCRIPTION
 *  This function is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_active_profile_changed_without_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//g_brw_cntx.brw_launching_pad = BRW_LPD_NONE;
	mmi_brw_settings_set_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_global_context_init
 * DESCRIPTION
 *  This func is used for initializing the global context but no memory 
 *  allocation should be here
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_global_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.isWapReady = MMI_FALSE;
	g_brw_cntx.isBrowserFetching = MMI_FALSE;
	g_brw_cntx.isBrowserInstance = MMI_FALSE;
	g_brw_cntx.isDeleteInsReqPending	= MMI_FALSE;
	g_brw_cntx.mainMenuEntryFlag		= MMI_FALSE;
	g_brw_cntx.select_mode_flag		= MMI_FALSE;
	g_brw_cntx.brw_first_page_flag	= MMI_TRUE;
	g_brw_cntx.list_refresh_flag = MMI_FALSE;
	g_brw_cntx.address_list_flag		= MMI_FALSE;
	g_brw_cntx.reset_hiliter_flag		= MMI_FALSE;    
    g_brw_cntx.common_gateway_flag		= MMI_FALSE;
	g_brw_cntx.security_dlg_flag		= MMI_FALSE;
	g_brw_cntx.auth_dlg_flag			= MMI_FALSE;
	g_brw_cntx.activate_java_flag		= MMI_FALSE;
	g_brw_cntx.do_element_list = NULL;
	g_brw_cntx.dynamic_list = NULL;
	g_brw_cntx.address_list_title_p = NULL;
	g_brw_cntx.address_list_url_p = NULL;
	g_brw_cntx.http_auth_info_p = NULL;
	g_brw_cntx.sec_confirm_dlg_info_p = NULL;   		  
	g_brw_cntx.brw_status_info_p = NULL;
	g_brw_cntx.brw_res_item_info_p = NULL;
	g_brw_cntx.brw_res_item_info_p = NULL;
	g_brw_cntx.document_info_p = NULL;
	g_brw_cntx.focused_element_info_p = NULL;
	g_brw_cntx.recent_page_host_list = NULL;
	g_brw_cntx.recent_page_list = NULL;
	g_brw_cntx.charset_list_p = NULL;
#if defined (WAP_SEC_SUPPORT)
	g_brw_cntx.session_info_p = NULL;
	g_brw_cntx.trusted_cert_list_p = NULL;
	g_brw_cntx.current_cert_p = NULL;
#endif /*WAP_SEC_SUPPORT*/
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
	g_brw_cntx.download_info_p			= NULL;
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
	g_brw_cntx.top_scr_id				= SCR_ID_BRW_FIRST_SCREEN_ID;
	g_brw_cntx.brw_launching_pad		= BRW_LPD_NONE;

#ifdef __MMI_VBOOKMARK__
	mmi_brw_bookmarks_context_init();
	mmi_brw_bookmarks_create_default_bkms();
#endif /*__MMI_VBOOKMARK__*/
		
	g_brw_memory_pool_size = BRW_ADM_MEMORY_POOL_SIZE;	

	/*initializing the encoding methods list*/
	mmi_brw_settings_encoding_methods_initialize_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_read_last_web_address
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_read_last_web_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        1,
        &g_brw_cntx.last_web_address,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        &NvramError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_write_last_web_address
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_write_last_web_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        1,
        &g_brw_cntx.last_web_address,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        &NvramError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dynamic_list_free_memory
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dynamic_list_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 NvramError;
    U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < g_brw_cntx.dynamic_list_count; index++)
    {
        mmi_brw_mfree(g_brw_cntx.dynamic_list[index].name);
        mmi_brw_mfree(g_brw_cntx.dynamic_list[index].host);
		g_brw_cntx.dynamic_list[index].name	= NULL;
		g_brw_cntx.dynamic_list[index].host	= NULL;
    }
    mmi_brw_mfree(g_brw_cntx.dynamic_list);
	g_brw_cntx.dynamic_list	= NULL;
    g_brw_cntx.dynamic_list_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dynamic_list_delete_item
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dynamic_list_delete_item(U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = item_index; index < g_brw_cntx.dynamic_list_count-1; index++)
    {
	    mmi_brw_mfree(g_brw_cntx.dynamic_list[index].name);
	    mmi_brw_mfree(g_brw_cntx.dynamic_list[index].host);
		g_brw_cntx.dynamic_list[index].host	= NULL;
		g_brw_cntx.dynamic_list[index].host	= NULL;

	    if(g_brw_cntx.dynamic_list[index+1].name)
	    {
		    g_brw_cntx.dynamic_list[index].name = 
				mmi_brw_malloc((strlen((S8*)g_brw_cntx.dynamic_list[index+1].name) + 1) * sizeof(U8));
		    strcpy((S8*)g_brw_cntx.dynamic_list[index].name, (S8*)g_brw_cntx.dynamic_list[index+1].name);
	    }
	    if(g_brw_cntx.dynamic_list[index+1].host)
	    {
		    g_brw_cntx.dynamic_list[index].host = 
				mmi_brw_malloc((strlen((S8*)g_brw_cntx.dynamic_list[index+1].host)+ 1) * sizeof(U8));
		    strcpy((S8*)g_brw_cntx.dynamic_list[index].host, (S8*)g_brw_cntx.dynamic_list[index+1].host);
	    }
    }
    mmi_brw_mfree(g_brw_cntx.dynamic_list[index].name);
    mmi_brw_mfree(g_brw_cntx.dynamic_list[index].host);
	g_brw_cntx.dynamic_list[index].name	= NULL;
	g_brw_cntx.dynamic_list[index].host	= NULL;

    --g_brw_cntx.dynamic_list_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_UCS2Strtolower
 * DESCRIPTION
 *  converts a unicode string to lowercase
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_UCS2Strtolower(S8* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(str);

	for(index = 0; index < mmi_ucs2strlen((S8*)str)*ENCODING_LENGTH; index+=2)
	{
		if(str[index] >= 'A' & str[index] <= 'Z')
	        {
			str[index] += 'a' - 'A';
		}
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stricmp
 * DESCRIPTION
 *  compares two utf-8 strings in lower case
 * PARAMETERS
 *  string1		[IN]	first string in utf-8
 *  string2		[IN]	second string in utf-8
 * RETURNS
 *  void
 *****************************************************************************/
S8 mmi_brw_stricmp(S8* string1, S8* string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8* temp_str1;
	S8* temp_str2;
	S32  result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(string1);
	MMI_ASSERT(string2);
	MMI_ASSERT((strlen((S8*)string1) + 1) * ENCODING_LENGTH <= BRW_MAX_CONTROL_BUFFER_SIZE);
	MMI_ASSERT((strlen((S8*)string2) + 1) * ENCODING_LENGTH <= BRW_MAX_CONTROL_BUFFER_SIZE);

	temp_str1 = OslMalloc((strlen((S8*)string1) + 1) * ENCODING_LENGTH);
	temp_str2 = OslMalloc((strlen((S8*)string2) + 1) * ENCODING_LENGTH);

	mmi_chset_utf8_to_ucs2_string((U8*)temp_str1, (strlen((S8*)string1) + 1) * ENCODING_LENGTH, 
		(U8*)string1);
	mmi_chset_utf8_to_ucs2_string((U8*)temp_str2, (strlen((S8*)string2) + 1) * ENCODING_LENGTH, 
		(U8*)string2);

	result = (S32)mmi_ucs2icmp((S8*)temp_str1, (S8*)temp_str2);

	OslMfree(temp_str1);
	OslMfree(temp_str2);

	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_tel_make_call
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_tel_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MakeCall((S8*)g_brw_phone_number);
	mmi_brw_watai_tel_rsp(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_tel_send_dtmf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_tel_send_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MakeCall((S8*)g_brw_phone_number);
	mmi_brw_watai_tel_rsp(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_pb_add_new_entry
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_pb_add_new_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_phb_save_entry_from_others(
		(S8*)g_brw_current_url,
		(S8*)g_brw_phone_number,
		0,
		0,
		0,
		0,
		mmi_brw_watai_pb_add_new_entry_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_pb_add_new_entry_callback
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_pb_add_new_entry_callback(mmi_phb_add_from_others_error_enum error_result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);

	switch(error_result)
	{
		case MMI_PHB_OTHERS_SUCCESS:
		{
			mmi_brw_watai_pb_rsp(WAP_BAM_WTAI_RESULT_OK);			
			break;
		}
		case MMI_PHB_OTHERS_ERROR:
		{
			mmi_brw_watai_pb_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);			
			break;
		}
		default:
		{
			mmi_brw_watai_pb_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);			
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_process_uri_request
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_process_uri_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_uri_request_rsp(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_tel_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_tel_rsp(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_tel_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wtai_tel_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wtai_tel_rsp_struct));

	myMsgPtr->request_id = g_brw_cntx.sap_request_id;
	myMsgPtr->error_code = error_code;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WTAI_TEL_RSP, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_pb_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_pb_rsp(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_tel_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wtai_tel_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wtai_tel_rsp_struct));

	myMsgPtr->request_id = g_brw_cntx.sap_request_id;
	myMsgPtr->error_code = error_code;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WTAI_PB_RSP, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_rsp(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_uri_request_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_uri_request_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_uri_request_rsp_struct));

	myMsgPtr->request_id = g_brw_cntx.sap_request_id;
	myMsgPtr->error_code = error_code;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_URI_REQUEST_RSP, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_register_keypad_handler_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_register_keypad_handler_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_register_keypad_handler_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_register_keypad_handler_req_struct*) OslConstructDataPtr(sizeof(wap_bam_register_keypad_handler_req_struct));

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_REGISTER_KEYPAD_HANDLER_REQ, myMsgPtr, NULL);
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_tel_make_call_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_tel_make_call_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 tempStr[300];
	U8 msgStr[1000];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)msgStr, (S8*)GetString(STR_ID_BRW_MAKE_CALL));
	mmi_ucs2cat((S8*)msgStr, (S8*)L": ");
	//mmi_asc_to_ucs2((S8*)tempStr, (S8*)g_brw_phone_number);
	mmi_ucs2cat((S8*)msgStr, (S8*)g_brw_phone_number);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)msgStr,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_watai_tel_make_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_tel_send_dtmf_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_tel_send_dtmf_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 tempStr[300];
	U8 msgStr[1000];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)msgStr, (S8*)GetString(STR_ID_BRW_MAKE_CALL));
	mmi_ucs2cat((S8*)msgStr, (S8*)L": ");
	//mmi_asc_to_ucs2((S8*)tempStr, (S8*)g_brw_phone_number);
	mmi_ucs2cat((S8*)msgStr, (S8*)g_brw_phone_number);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)msgStr,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_watai_tel_send_dtmf, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_pb_add_new_entry_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_pb_add_new_entry_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 tempStr[300];
	U8 msgStr[1000];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)msgStr, (S8*)GetString(STR_ID_BRW_ADD_ENTRY));
	mmi_ucs2cat((S8*)msgStr, (S8*)L": ");
	mmi_ucs2cat((S8*)msgStr, (S8*)g_brw_current_url);
	mmi_ucs2cat((S8*)msgStr, (S8*)L" ");
	//mmi_ucs2cpy((S8*)tempStr, (S8*)g_brw_phone_number);
	mmi_ucs2cat((S8*)msgStr, (S8*)g_brw_phone_number);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)msgStr,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_watai_pb_add_new_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_activate_java_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for activating JAVA and
 *  terminating browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_activate_java_confirm(void)
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
        get_string(STR_ID_BRW_ACTIVATE_JAVA),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_uri_request_activate_java, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_activate_java
 * DESCRIPTION
 *  This function is used for activating Java and terminating browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_activate_java(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_INFUSIO__
	/*setting the activate java flag to true*/
	g_brw_cntx.activate_java_flag = MMI_TRUE;

	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_INTERNET_SERVICES);
	mmi_brw_entry_browser_busy_screen();

	/*deintializing the browser*/
	mmi_brw_app_deinit();
#else
	DisplayPopup(
		(PU8) GetString(STR_ID_BRW_NOT_SUPPORTED), 
		IMG_GLOBAL_ERROR, 
		1, 
		UI_POPUP_NOTIFYDURATION_TIME, 
		ERROR_TONE);	
#endif /* __SUPPORT_INFUSIO__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_send_sms_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for sending SMS to the given
 *  number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_send_sms_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 display_msg[500];
	U8 phone_number[200];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*)phone_number, 200, (U8*)g_brw_cntx.uri_request_p->param);	

	mmi_ucs2cpy((S8*)display_msg, (S8*)get_string(STR_ID_BRW_SEND_SMS_TO));
	mmi_ucs2cat((S8*)display_msg, (S8*)L" ");
	mmi_ucs2cat((S8*)display_msg, (S8*)phone_number);
	mmi_ucs2cat((S8*)display_msg, (S8*)L"?");

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)display_msg,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_uri_request_send_sms, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_send_sms
 * DESCRIPTION
 *  This function is used for sending SMS to the given number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct *sendData = mmi_brw_malloc(sizeof(mmi_frm_sms_api_entry_write_struct));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendData->string = NULL;
    sendData->stringlength = 0;
    sendData->dcs = SMSAL_UCS2_DCS;
    sendData->flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    sendData->ascii_addr = (U8*)g_brw_cntx.uri_request_p->param;
    sendData->filename = NULL;

    mmi_frm_sms_api_entry_write_msg(sendData);
    mmi_brw_mfree(sendData);

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_send_mms_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for sending MMS to the given
 *  number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_send_mms_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 display_msg[500];
	U8 phone_number[200];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*)phone_number, 200, (U8*)g_brw_cntx.uri_request_p->param);	

	mmi_ucs2cpy((S8*)display_msg, (S8*)get_string(STR_ID_BRW_SEND_MMS_TO));
	mmi_ucs2cat((S8*)display_msg, (S8*)L" ");
	mmi_ucs2cat((S8*)display_msg, (S8*)phone_number);
	mmi_ucs2cat((S8*)display_msg, (S8*)L"?");

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)display_msg,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_uri_request_send_mms, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_send_mms
 * DESCRIPTION
 *  This function is used for sending MMS to the given number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8* number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	number = (U8*)mmi_brw_malloc(strlen((S8*)g_brw_cntx.uri_request_p->param) * ENCODING_LENGTH); 
	mmi_chset_utf8_to_ucs2_string((U8*)number, strlen((S8*)g_brw_cntx.uri_request_p->param) * ENCODING_LENGTH, 
		(U8*)g_brw_cntx.uri_request_p->param);	

	mms_address_insert_hdlr((S8*)number);
	mmi_brw_mfree(number);

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_process_uri_request_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_process_uri_request_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_process_uri_request, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bearer_info_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bearer_info_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);*/

    SetLeftSoftkeyFunction(mmi_brw_switch_bearer, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_switch_bearer
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of currently selected stored page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_switch_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_load_url
 * DESCRIPTION
 *  This function is the external interface for fetching a given url
 * PARAMETERS
 *  url_p	[IN]	url in UTF-8
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_load_url(U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p);

    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserMain.c] mmi_brw_load_url url_p = %s\n", url_p);

    if(strlen((S8*)url_p) > BRW_MAX_URL_LENGTH)
    {
	    DisplayPopup(
		    (PU8) GetString(STR_ID_BRW_INVALID_URL), 
		    IMG_GLOBAL_ERROR, 
		    1, 
		    UI_POPUP_NOTIFYDURATION_TIME, 
		    ERROR_TONE);	
	    return;
    }

	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)url_p);

    if(mmi_brw_validate_url(g_brw_current_url) < 0)
    {
	    DisplayPopup(
		    (PU8) GetString(STR_ID_BRW_INVALID_URL), 
		    IMG_GLOBAL_ERROR, 
		    1, 
		    UI_POPUP_NOTIFYDURATION_TIME, 
		    ERROR_TONE);	
	    return;
    }

	/*if it is being called from inside the browser then simply fetch the url*/
	if( IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES) || IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN) )
	{
		mmi_brw_pre_entry_goto_url();		
	}
	else
	{
        g_brw_cntx.brw_launching_pad = BRW_LPD_EXTERNAL_LOAD_URL_REQ;
	    mmi_brw_common_gateway();
    }
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_add_to_bookmark
 * DESCRIPTION
 *  This function is an external interface for adding a bookmark without user
 *  interface
 * PARAMETERS
 *  title_p		[IN]		bookmark title in utf-8
 *  url_p		[IN]		bookmark URL in utf-8
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_brw_add_to_bookmark(U8* title_p, U8* url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(url_p);

    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserMain.c] mmi_brw_add_to_bookmark url_p = %s\n", url_p);

    if(strlen((S8*)url_p) > BRW_MAX_URL_LENGTH)
    {
	    return BRW_ADD_TO_BKM_INVALID_URL;
    }

	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		return BRW_ADD_TO_BKM_MEMORY_FULL;
	}

	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)url_p);

	if(title_p)
	{
		if(strlen((S8*)url_p) > BRW_MAX_TITLE_LENGTH)
		{
			return BRW_ADD_TO_BKM_INVALID_TITLE;
		}
		mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_title, (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)title_p);
	}
	else
	{
		mmi_ucs2cpy((S8*)g_brw_current_title, (S8*)L"");
	}
	
	return mmi_brw_bookmarks_add_to_bookmark_silently();
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_splash_screen_set_title_string_and_icon
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_splash_screen_set_title_string_and_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *activeProfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_title_string = (UI_string_type) GetString(STR_ID_BRW_INTERNET_SERVICES);

	activeProfile = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_wap_profile();

	if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_CSD)
	{
		MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_CSD);
	}
	else if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_GPRS)
	{
		MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_GPRS);
	}
	else if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_WIFI)
	{
		MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_WIFI);
	}
	else
	{
		MMI_title_icon = (PU8) get_image(IMG_ID_BRW_CONNECTION_STATUS_CSD);
	}

	draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_active_profile_editable
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_brw_is_active_profile_editable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *currProfStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	currProfStruct = (nvram_profile_content_struct *)mmi_brw_prof_get_activated_wap_profile();

	return currProfStruct->editable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_malloc
 * DESCRIPTION
 *  This function is used to allocate the desired memory for browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void* mmi_brw_malloc(U32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void* pMemory;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(mem_size);
	MMI_ASSERT(g_brw_cntx.brw_adm_id);

	pMemory = kal_adm_alloc(g_brw_cntx.brw_adm_id, mem_size);
	MMI_ASSERT(pMemory);

	return pMemory;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_mfree
 * DESCRIPTION
 *  This function de-allocates the memory for browser
 * PARAMETERS
 *  pMemory		[OUT]		pointer to memory	
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_mfree(void* pMemory)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(pMemory)
	{
		MMI_ASSERT(g_brw_cntx.brw_adm_id);

		kal_adm_free(g_brw_cntx.brw_adm_id, pMemory);
		pMemory = NULL;
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_memory_available
 * DESCRIPTION
 *  This function checks the availability of the memory buffer
 * PARAMETERS
 *  pMemory		[OUT]		pointer to memory	
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_is_memory_available(U32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(kal_adm_get_max_alloc_size(g_brw_cntx.brw_adm_id) < mem_size)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_OUT_OF_MEMORY), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		return MMI_FALSE;
	}
	else 
	{
		return MMI_TRUE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_splash_screen_stop_timer
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_splash_screen_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.brw_first_page_flag)
	{
		g_brw_cntx.brw_first_page_flag = MMI_FALSE;
		StopTimer(BRW_SPLASH_SCREEN_TIMER);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_positive_key_hdlr
 * DESCRIPTION
 *  This is the temporary dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_positive_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*re-setting softkeys to their original state*/
	mmi_brw_ren_page_set_LSK();
	mmi_brw_ren_page_set_RSK();

	mmi_brw_wait_user_action_rsp(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_negative_key_hdlr
 * DESCRIPTION
 *  This is the temporary dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_negative_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*re-setting softkeys to their original state*/
	mmi_brw_ren_page_set_LSK();
	mmi_brw_ren_page_set_RSK();

	mmi_brw_wait_user_action_rsp(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_rsp(MMI_BOOL positive_key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wait_user_action_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wait_user_action_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wait_user_action_rsp_struct));

	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->press_positive_sk = positive_key_state;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action
 * DESCRIPTION
 *  This func is the interface for the external application to allow browser
 *  to perform some particular action
 * PARAMETERS
 *  option		[IN]		type of browser action
 *	url			[IN]		URL string in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action(U8 option, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url_ascii[BRW_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2_to_asc((S8*)url_ascii, (S8*)url);
    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserMain.c] mmi_brw_start_browser_action url = %s\n", url_ascii);

	switch(option)
	{
		case WAP_BROWSER_GOTO_MAIN_MENU:
		{
			mmi_brw_start_browser_action_goto_main_menu();
			break;
		}
		case WAP_BROWSER_GOTO_HOMEPAGE:
		{
			mmi_brw_start_browser_action_goto_homepage();
			break;
		}
		case WAP_BROWSER_GOTO_URL:
		{
			MMI_ASSERT(url);
			mmi_brw_start_browser_action_goto_url(url);
			break;
		}
#ifdef __MMI_VBOOKMARK__
		case WAP_BROWSER_ADD_BOOKMARK:
		{
			MMI_ASSERT(url);
			mmi_brw_start_browser_action_add_to_bookmark(url);
			break;
		}
#endif /*__MMI_VBOOKMARK__*/
		case WAP_BROWSER_GOTO_URL_BACKGROUND:
		{
			MMI_ASSERT(url);
			mmi_brw_start_browser_action_goto_url_bkgrd(url);
			break;
		}
		case WAP_BROWSER_VIEW_PUSH_MSG:
		{
			mmi_brw_start_browser_action_view_push_msg();
			break;
		}
		default:
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_UNSUPPORTED_ACTION), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);	
			return;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action_goto_main_menu
 * DESCRIPTION
 *  This func is the external interface to open the browser main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action_goto_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_pre_entry_internet_services();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action_goto_homepage
 * DESCRIPTION
 *  This func is the external interface to open the browser homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action_goto_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *currProfStruct;
	U8* url_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.homepage_settings_index == BRW_USER_DEFINED_HOMEPAGE)
	{
		url_p = (U8*)g_brw_cntx.user_defined_hmpage_url;
	}
	else if(g_brw_cntx.homepage_settings_index == BRW_ACTIVE_PROFILE_HOMEPAGE)
	{
		currProfStruct = (nvram_profile_content_struct *)mmi_brw_prof_get_activated_wap_profile();
		url_p = (U8*)currProfStruct->url;
	}
	else
	{
		MMI_ASSERT(0);
	}

	mmi_brw_load_url(url_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action_goto_url
 * DESCRIPTION
 *  This func is the external interface to fetch the given url
 * PARAMETERS
 *  url		[IN]	URL string in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action_goto_url(U8* url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url_ascii[BRW_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_ucs2strlen((S8*)url_p) > BRW_MAX_URL_LENGTH)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		return;
	}

    mmi_chset_ucs2_to_utf8_string((U8*)url_ascii, BRW_MAX_URL_LENGTH + 1,(U8*)url_p);

    if(g_brw_cntx.isBrowserInstance)
	{
		/*deinitializing the current browser instance so that a new instance can be created*/
		/*this change has been done to resolve the CQ issue# MAUI_00544465*/
		mmi_brw_app_deinit();
	}

	mmi_brw_load_url(url_ascii);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action_add_to_bookmark
 * DESCRIPTION
 *  This func is an external interface to add the given url as a bookmark
 *  with user interface
 * PARAMETERS
 *  url_p		[IN]	URL string in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action_add_to_bookmark(U8* url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_ucs2strlen((S8*)url_p) > BRW_MAX_URL_LENGTH)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		return;
	}

	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	mmi_asc_to_ucs2((S8*) g_brw_current_title, (S8*)"");
	mmi_ucs2cpy((S8*)g_brw_current_url, (S8*)url_p);

	mmi_brw_bookmarks_add_to_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action_goto_url_bkgrd
 * DESCRIPTION
 *  This func is the external interface to fetch the given url in bakcground
 * PARAMETERS
 *  url_p		[IN]	URL string in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action_goto_url_bkgrd(U8* url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_ucs2strlen((S8*)url_p) > BRW_MAX_URL_LENGTH)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		return;
	}

	if(!g_brw_cntx.isBrowserInstance || !IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_UNSUPPORTED_ACTION), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		return;
	}
	else
	{
		//g_brw_cntx.isBrowserFetching = MMI_TRUE;
		//g_brw_cntx.do_element_count = 0;
		//mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)url);
		mmi_ucs2cpy((S8*)g_brw_current_url, (S8*)url_p);

		if(mmi_brw_validate_url(g_brw_current_url) < 0)
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_URL), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);	
			return;
		}
		mmi_brw_load_url_req(g_brw_current_url);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_start_browser_action_view_push_msg
 * DESCRIPTION
 *  This func is the external interface to open the push messages list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_start_browser_action_view_push_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_push_pre_entry_inbox_validation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_screen_id
 * DESCRIPTION
 *  This func is the external interface to open the push messages list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_get_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return SCR_ID_BRW_BROWSER_MAIN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_busy_screen_set_title_string_id
 * DESCRIPTION
 *  This func is used for setting the busy screen title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_busy_screen_set_title_string_id(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_busy_scr_title_str_id = id;
}


#ifdef APPMEM_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_asm_stop_app_callback
 * DESCRIPTION
 *  Initialize the browser application if not already initialized
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_asm_stop_app_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.brw_launching_pad = BRW_LPD_ASM_TERMINATE;

	/*De-allocate browser application memory*/
	mmi_brw_app_deinit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_asm_memory_pool_request_success_callback
 * DESCRIPTION
 *  Pre Entry function for Internet services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_asm_memory_pool_request_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_memory_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BROWSER, 
		WAP_CUSTOM_CFG_BROWSER_MEM_SIZE + g_brw_memory_pool_size);
	MMI_ASSERT(g_brw_memory_pool);

	setAppMemPool(g_brw_memory_pool);
    mmi_brw_create_instance_req();
}
#endif /*APPMEM_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_display_info_go_back_history
 * DESCRIPTION
 *  It de-allocates the display info str and go back to the previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_display_info_go_back_history(void)
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
		g_brw_display_info_str = NULL;
	}

	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_as_homepage_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_as_homepage_confirm(void)
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
        get_string(STR_ID_BRW_SET_AS_HOMEPAGE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_set_as_homepage_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_as_homepage_ok
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_as_homepage_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url_p[BRW_MAX_URL_LENGTH + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_brw_validate_url(g_brw_current_url) < 0)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		return;
	}

	mmi_ucs2_to_asc((S8*)url_p, (S8*)g_brw_current_url);

	if(g_brw_cntx.homepage_settings_index == BRW_USER_DEFINED_HOMEPAGE)
	{
		mmi_brw_settings_set_user_defined_homepage((U8*)url_p);
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);
	}
	else if(g_brw_cntx.homepage_settings_index == BRW_ACTIVE_PROFILE_HOMEPAGE)
	{
		if(mmi_brw_is_active_profile_editable() == BRW_PROF_READ_WRITE)
		{
			mmi_brw_prof_wap_set_homepage((S8*)url_p); 
			DisplayPopup(
				(PU8) GetString(STR_GLOBAL_DONE), 
				IMG_GLOBAL_ACTIVATED, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				SUCCESS_TONE);
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_READ_ONLY_PROFILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);	
		}
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_editor_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_EDITOR_OPTION, NULL, mmi_brw_editor_entry_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_EDITOR_OPTION);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_ID_BRW_EDITOR_OPTION);
    GetSequenceStringIds(MENU_ID_BRW_EDITOR_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_BRW_EDITOR_OPTION);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(mmi_brw_return_to_editor);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_return_to_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_editor_cancel_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_editor_cancel_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_editor_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_editor_input_method_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for exit option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_editor_input_method_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_editor_pre_entry_input_method, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_editor_pre_entry_input_method, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_editor_cancel
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_editor_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteNHistory(1);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_editor_pre_entry_input_method
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_editor_pre_entry_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	EntryInputMethodScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_all_browser_screens
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_all_browser_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
	{
		if(IsScreenPresent(g_brw_cntx.top_scr_id))
		{
			result = DeleteBetweenScreen(SCR_ID_BRW_INTERNET_SERVICES, g_brw_cntx.top_scr_id);
	}
		else if(mmi_brw_is_browser_screen(GetCurrScrnId()))
	{
			result = DeleteBetweenScreen(SCR_ID_BRW_INTERNET_SERVICES, GetCurrScrnId());
	}
		else 
	{
			result = DeleteScreenIfPresent(SCR_ID_BRW_INTERNET_SERVICES);
		}
	}
	else if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		if( IsScreenPresent(g_brw_cntx.top_scr_id) )
		{
			result = DeleteBetweenScreen(SCR_ID_BRW_BROWSER_MAIN, g_brw_cntx.top_scr_id);
		}
		else if( mmi_brw_is_browser_screen(GetCurrScrnId()) )
		{
			result = DeleteBetweenScreen(SCR_ID_BRW_BROWSER_MAIN, GetCurrScrnId());
		}
		else 
		{
			result = DeleteScreenIfPresent(SCR_ID_BRW_BROWSER_MAIN);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_browser_screen
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_is_browser_screen(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( screen_id > SCR_ID_BRW_FIRST_SCREEN_ID && 
		screen_id < SCR_ID_BRW_LAST_SCREEN_ID )
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_global_context_deinit
 * DESCRIPTION
 *  Deinitializing all the browser global context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_global_context_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.brw_adm_id)
	{
		if(g_brw_cntx.current_cert_p)
		{
			mmi_brw_mfree(g_brw_cntx.current_cert_p);
			g_brw_cntx.current_cert_p = NULL;
		}

		if(g_brw_cntx.brw_status_info_p)
		{
			mmi_brw_mfree(g_brw_cntx.brw_status_info_p);
			g_brw_cntx.brw_status_info_p = NULL;
		}

		if(g_brw_cntx.brw_res_item_info_p)
		{
			mmi_brw_mfree(g_brw_cntx.brw_res_item_info_p);
			g_brw_cntx.brw_res_item_info_p = NULL;
		}

		if(g_brw_cntx.do_element_list)
		{
			mmi_brw_mfree(g_brw_cntx.do_element_list);
			g_brw_cntx.do_element_list = NULL;
			g_brw_cntx.do_element_count = 0;
		}

		if(g_brw_cntx.document_info_p)
		{
			mmi_brw_mfree(g_brw_cntx.document_info_p);
			g_brw_cntx.document_info_p = NULL;
		}

		if(g_brw_cntx.focused_element_info_p)
		{
			mmi_brw_mfree(g_brw_cntx.focused_element_info_p);
			g_brw_cntx.focused_element_info_p = NULL;
		}

		if(g_brw_cntx.bearer_info_p)
		{
			mmi_brw_mfree(g_brw_cntx.bearer_info_p);
			g_brw_cntx.bearer_info_p = NULL;
		}

		if(g_brw_cntx.uri_request_p)
		{
			mmi_brw_mfree(g_brw_cntx.uri_request_p);
			g_brw_cntx.uri_request_p = NULL;
		}

		if(g_brw_cntx.saved_page_properties_p)
		{
			mmi_brw_mfree(g_brw_cntx.saved_page_properties_p);
			g_brw_cntx.saved_page_properties_p = NULL;
		}

		if(g_brw_display_info_str)
		{
			mmi_brw_mfree(g_brw_display_info_str);
			g_brw_display_info_str = NULL;
		}

#if defined (WAP_SEC_SUPPORT)
		if(g_brw_cntx.session_info_p)
		{
			mmi_brw_mfree(g_brw_cntx.session_info_p);
			g_brw_cntx.session_info_p = NULL;
		}
		mmi_brw_security_settings_trusted_certificates_list_free_memory();
#endif /*WAP_SEC_SUPPORT*/

#ifdef __MMI_VBOOKMARK__
		mmi_brw_bookmarks_free_memory();
#endif /*__MMI_VBOOKMARK__*/

		mmi_brw_dynamic_list_free_memory();
		mmi_brw_recent_pages_free_memory();
		mmi_brw_address_list_free_memory();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_top_screen_id
 * DESCRIPTION
 *  This func is used for initializing the browser context that should be reset
 *  everytime browser instance is created
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_top_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.top_scr_id = GetActiveScreenId();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_top_screen_id
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_get_top_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_brw_cntx.top_scr_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_status_icon
 * DESCRIPTION
 *  This func is used for showing or hiding the given status icon
  * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_status_icon(S16 icon_id, MMI_BOOL show_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(show_icon)
	{
		ShowStatusIcon(icon_id);
	}
	else
	{
		HideStatusIcon(icon_id);
	}
	UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_trim_left_white_spaces
 * DESCRIPTION
 *  This function is used for removing white spaces from a string at left end 
  * PARAMETERS
 *  string		[OUT]		string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_trim_left_white_spaces(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *tempstr;
    S32 index = 0, len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(string);

	if(!mmi_ucs2strlen(string))
	{
		return;
	}

	len = mmi_ucs2strlen(string);
	tempstr = OslMalloc((len + 1) * ENCODING_LENGTH);
	mmi_ucs2cpy((S8*)tempstr, (S8*)string);

    while( ( tempstr[index] ==  9 && tempstr[index + 1] == 0 ) ||
		   ( tempstr[index] == 10 && tempstr[index + 1] == 0 ) ||
		   ( tempstr[index] == 13 && tempstr[index + 1] == 0 ) ||
		   ( tempstr[index] == 32 && tempstr[index + 1] == 0 )
		  )
    {
        index += ENCODING_LENGTH;
        if (index >= len * ENCODING_LENGTH)
        {
            break;
        }
    }

	mmi_ucs2cpy((S8*)string, (S8*)tempstr + index);
	OslMfree(tempstr);
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_trim_right_white_spaces
 * DESCRIPTION
 *  This function is used for removing white spaces from a string at right end 
  * PARAMETERS
 *  string		[OUT]		string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_trim_right_white_spaces(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(string);

	if(!mmi_ucs2strlen(string))
	{
		return;
	}

	index = (mmi_ucs2strlen(string) - 1) * ENCODING_LENGTH;

    while( ( string[index] ==  9 && string[index + 1] == 0 ) ||
		   ( string[index] == 10 && string[index + 1] == 0 ) ||
		   ( string[index] == 13 && string[index + 1] == 0 ) ||
		   ( string[index] == 32 && string[index + 1] == 0 )
		  )
    {
        index -= ENCODING_LENGTH;
        if (index <= 0)
        {
            break;
        }
    }
	
	string[index + 2] = '\0';
	string[index + 3] = '\0';

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_white_spaces
 * DESCRIPTION
 *  This function is used for checking whether the given string contains any
 *  white spaces or not
 * PARAMETERS
 *  string		[OUT]		string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_check_white_spaces(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(string);

	if(!mmi_ucs2strlen(string))
	{
		return MMI_FALSE;
	}

	for(index = 0; index < (mmi_ucs2strlen((S8*)string) * ENCODING_LENGTH); index += ENCODING_LENGTH)
	{
		if( ( string[index] ==  9 && string[index + 1] == 0 ) ||
			( string[index] == 10 && string[index + 1] == 0 ) ||
			( string[index] == 13 && string[index + 1] == 0 ) ||
			( string[index] == 32 && string[index + 1] == 0 )
		   )
		{
			return MMI_TRUE;
		}
	}
	
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_common_gateway
 * DESCRIPTION
 *  This func is used for showing or hiding the given status icon
  * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_common_gateway(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_brw_cntx.isWapReady)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_WAP_NOT_READY), 
			IMG_GLOBAL_WARNING, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			WARNING_TONE);
		return;
	}

    if(g_brw_cntx.isBrowserInstance)
	{
		g_brw_cntx.common_gateway_flag = MMI_TRUE;

		/*showing the busy screen*/
		mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_INTERNET_SERVICES);
		mmi_brw_entry_browser_busy_screen();
		return;
	}
	else
	{
#ifdef APPMEM_SUPPORT
		g_brw_memory_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BROWSER, 
			WAP_CUSTOM_CFG_BROWSER_MEM_SIZE + g_brw_memory_pool_size);
		if(!g_brw_memory_pool)
		{
			mmi_frm_appmem_prompt_to_release_mem(
				APPLIB_MEM_AP_ID_BROWSER,
				SERVICES_WAP_IMAGE_ID,
				WAP_CUSTOM_CFG_BROWSER_MEM_SIZE + g_brw_memory_pool_size,
				mmi_brw_asm_memory_pool_request_success_callback);
			return;
		}
		else
		{
			setAppMemPool(g_brw_memory_pool);
			mmi_brw_create_instance_req();
		}
#else
        mmi_brw_create_instance_req();
#endif /*APPMEM_SUPPORT*/
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_browser_launched_from_main_menu
 * DESCRIPTION
 *  This func is used for showing or hiding the given status icon
  * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_is_browser_launched_from_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_brw_cntx.mainMenuEntryFlag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_exit
 * DESCRIPTION
 *  This function is being called to deinitialize the browser and get back to the 
 *  previous screen if user wants to exit from it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_deinit();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_dummy_screen
 * DESCRIPTION
 *  Entry function for dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_DUMMY, NULL, mmi_brw_entry_dummy_screen, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_busy_screen
 * DESCRIPTION
 *  Entry function for dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_busy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_BRW_BUSY_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_redirection_delete_brw_screens_upto_rend_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_redirection_delete_brw_screens_upto_rend_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_is_browser_screen(GetActiveScreenId()))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
		GoBackHistory();
	}
	else
	{
		DeleteFromScrUptoScr(mmi_brw_get_top_screen_id(), SCR_ID_BRW_BROWSER_MAIN);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_browser_active
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_is_browser_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES) || IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERMAIN_C */ 


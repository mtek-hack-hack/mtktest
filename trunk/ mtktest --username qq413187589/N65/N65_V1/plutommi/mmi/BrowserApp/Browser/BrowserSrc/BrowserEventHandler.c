/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  BrowserEventHandler.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *	This file contains definations of all the ilm message handlers like indication(ind),
 *  response(rsp) and cnf messages getting from Browser Adaptation Module(BAM).
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSEREVENTHANDLER_C
#define MMI_BROWSEREVENTHANDLER_C

/***************************************************************************** 
* Include
*****************************************************************************/

#ifdef __MMI_BROWSER_2__
#include "MiscFunctions.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "Conversions.h"
#include "BrowserMain.h"
#include "BrowserResDef.h"
#include "BrowserTypes.h"
#include "BrowserGprots.h"
#include "BrowserEventHandler.h"
#include "DataAccountGProt.h"   

#ifdef MMI_ON_HARDWARE_P
#include "custom_util.h"
#endif /* MMI_ON_HARDWARE_P */ 


U8 g_leftSoftKeyLabel[(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH];
U8 g_rightSoftKeyLabel[(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_event_hdlr_register_all_ilm_handlers
 * DESCRIPTION
 *  This function is used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_event_hdlr_register_all_ilm_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*BAM SAPs*/
	SetProtocolEventHandler(mmi_brw_create_instance_cnf, MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF);
	SetProtocolEventHandler(mmi_brw_delete_instance_cnf, MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_this_page_save_page_cnf, MSG_ID_WAP_BAM_SAVE_PAGE_CNF);
	SetProtocolEventHandler(mmi_brw_stored_pages_get_saved_pages_list_start_cnf, MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_CNF);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_stored_pages_get_saved_pages_list_continue_cnf, MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF);
	SetProtocolEventHandler(mmi_brw_this_page_get_resource_list_start_cnf, MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_CNF);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_this_page_get_resource_list_continue_cnf, MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_this_page_get_resource_cnf, MSG_ID_WAP_BAM_GET_RESOURCE_CNF);
	SetProtocolEventHandler(mmi_brw_settings_set_profile_cnf, MSG_ID_WAP_BAM_SET_PROFILE_CNF);
	SetProtocolEventHandler(mmi_brw_recent_pages_get_recent_pages_list_start_cnf, MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_CNF);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_recent_pages_get_recent_pages_list_continue_cnf, MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_recent_page_cnf, MSG_ID_WAP_BAM_RECENT_PAGE_CNF);
	SetProtocolEventHandler(mmi_brw_bearer_info_ind, MSG_ID_WAP_BAM_BEARER_INFO_IND);
	SetProtocolEventHandler(mmi_brw_status_ind, MSG_ID_WAP_BAM_STATUS_IND);
	SetProtocolEventHandler(mmi_brw_error_ind, MSG_ID_WAP_BAM_ERROR_IND);
	SetProtocolEventHandler(mmi_brw_document_info_ind, MSG_ID_WAP_BAM_DOCUMENT_INFO_IND);
	SetProtocolEventHandler((PsFuncPtr) mmi_brw_ren_page_do_element_ind, MSG_ID_WAP_BAM_DO_ELEMENTS_IND);
	SetProtocolEventHandler(mmi_brw_page_element_focused_ind, MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND);
	SetProtocolEventHandler(mmi_brw_set_security_class_ind, MSG_ID_WAP_BAM_SET_SEC_CLASS_IND);
	SetProtocolEventHandler(mmi_brw_watai_tel_ind, MSG_ID_WAP_BAM_WTAI_TEL_IND);
	SetProtocolEventHandler(mmi_brw_watai_pb_ind, MSG_ID_WAP_BAM_WTAI_PB_IND);
	SetProtocolEventHandler(mmi_brw_uri_request_ind, MSG_ID_WAP_BAM_URI_REQUEST_IND);
	SetProtocolEventHandler(mmi_brw_wait_user_action_ind, MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND);
	SetProtocolEventHandler(mmi_brw_ren_page_show_auth_dialog_ind, MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND);
	SetProtocolEventHandler(mmi_brw_bam_ready_ind, MSG_ID_WAP_BAM_READY_IND);
	/*BAM SAPs*/

	/*BROWSER SECURITY SAPs*/
#if defined (WAP_SEC_SUPPORT)
	SetProtocolEventHandler(mmi_brw_security_settings_get_session_info_rsp, MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP);
	SetProtocolEventHandler(mmi_brw_security_settings_get_trusted_certificate_ids_rsp, MSG_ID_WPS_SEC_GET_CERT_IDS_RSP);
	SetProtocolEventHandler(mmi_brw_security_settings_get_trusted_certificate_rsp, MSG_ID_WPS_SEC_GET_CERT_RSP);
	SetProtocolEventHandler(mmi_brw_trusted_certificates_delete_rsp, MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP);
	SetProtocolEventHandler(mmi_brw_security_settings_get_current_certificate_rsp, MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP);
#endif /*WAP_SEC_SUPPORT*/
	SetProtocolEventHandler(mmi_brw_sec_confirm_dialog_ind, MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_IND);
	SetProtocolEventHandler(mmi_brw_settings_clear_data_rsp, MSG_ID_WPS_CLEAR_RSP);
	/*BROWSER SECURITY SAPs*/

	/*OTHER SAPs*/
#ifdef __MMI_VBOOKMARK__
	SetProtocolEventHandler(mmi_brw_select_bookmark_req, MSG_ID_WAP_SELECT_BOOKMARK_REQ);
#endif /*__MMI_VBOOKMARK__*/
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
	SetProtocolEventHandler(mmi_brw_bkgrd_downloads_ind, MSG_ID_MMI_DA_DOWNLOAD_INFO_IND);
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
	SetProtocolEventHandler(mmi_brw_wap_browser_startup_req, MSG_ID_WAP_BROWSER_STARTUP_REQ);
	/*OTHER SAPs*/

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_event_hdlr_send_ilm
 * DESCRIPTION
 *  This function is used 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_event_hdlr_send_ilm(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *ilm_ptr = NULL;
    MYQUEUE Message;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ilm_ptr = allocate_ilm(MOD_MMI);
    Message.src_mod_id = MOD_MMI;
    Message.dest_mod_id = MOD_WAP;
    Message.sap_id = WAP_MMI_SAP;
    Message.msg_id = (msg_type) msg_id;
    Message.local_para_ptr = (local_para_struct*) local_param_ptr;
    Message.peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_event_hdlr_send_ilm_to_wps
 * DESCRIPTION
 *  This function is used 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_event_hdlr_send_ilm_to_wps(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *ilm_ptr = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ilm_ptr = allocate_ilm(MOD_MMI);
    Message.src_mod_id = MOD_MMI;
    Message.dest_mod_id = MOD_WPS;
    Message.sap_id = WAP_MMI_SAP;
    Message.msg_id = (msg_type) msg_id;
    Message.local_para_ptr = (local_para_struct*) local_param_ptr;
    Message.peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_event_hdlr_send_ilm_to_wps
 * DESCRIPTION
 *  This function is used 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_event_hdlr_send_ilm_to_mmi(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *ilm_ptr = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ilm_ptr = allocate_ilm(MOD_MMI);
    Message.src_mod_id = MOD_MMI;
    Message.dest_mod_id = MOD_MMI;
    Message.sap_id = WAP_MMI_SAP;
    Message.msg_id = (msg_type) msg_id;
    Message.local_para_ptr = (local_para_struct*) local_param_ptr;
    Message.peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_show_auth_dialog_ind
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_show_auth_dialog_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_show_auth_dialog_ind_struct *localBuff_p = (wap_bam_show_auth_dialog_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(g_brw_cntx.http_auth_info_p == NULL)
	{
		g_brw_cntx.http_auth_info_p = (wap_bam_show_auth_dialog_ind_struct*) 
			OslMalloc(sizeof(wap_bam_show_auth_dialog_ind_struct));
	}
	g_brw_cntx.http_auth_info_p->instance_id  = localBuff_p->instance_id;
	g_brw_cntx.http_auth_info_p->request_id  = localBuff_p->request_id;
	g_brw_cntx.http_auth_info_p->auth_type	 = localBuff_p->auth_type;
	strcpy((S8*)g_brw_cntx.http_auth_info_p->realm, (S8*)localBuff_p->realm);
	strcpy((S8*)g_brw_cntx.http_auth_info_p->username, (S8*)localBuff_p->username);
	strcpy((S8*)g_brw_cntx.http_auth_info_p->password, (S8*)localBuff_p->password);

	/*stop splash screen timer*/
	mmi_brw_splash_screen_stop_timer();

	mmi_brw_ren_page_entry_auth_dialog();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_sec_confirm_dialog_ind
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_sec_confirm_dialog_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_show_confirm_dialog_ind_struct *localBuff_p = (wps_show_confirm_dialog_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(!g_brw_cntx.sec_confirm_dlg_info_p)
	{
		g_brw_cntx.sec_confirm_dlg_info_p = (wps_show_confirm_dialog_ind_struct*) 
			OslMalloc(sizeof(wps_show_confirm_dialog_ind_struct));
	}
	g_brw_cntx.sec_confirm_dlg_info_p->request_id = localBuff_p->request_id;
	g_brw_cntx.sec_confirm_dlg_info_p->dialog_type  = localBuff_p->dialog_type;		
	g_brw_cntx.sec_confirm_dlg_info_p->buttons = localBuff_p->buttons;
	g_brw_cntx.sec_confirm_dlg_info_p->title_id  = localBuff_p->title_id;		
	g_brw_cntx.sec_confirm_dlg_info_p->text_id = localBuff_p->text_id;

	mmi_brw_ren_page_entry_sec_confirm_dialog();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_instance_cnf
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_create_instance_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_create_instance_cnf_struct *localBuff_p = (wap_bam_create_instance_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}
	else
	{
		g_brw_cntx.isBrowserInstance = MMI_TRUE;
		g_brw_cntx.brw_instance_id = localBuff_p->instance_id;
		g_brw_cntx.brw_adm_id = 
			kal_adm_create((char *)g_brw_memory_pool + WAP_CUSTOM_CFG_BROWSER_MEM_SIZE, g_brw_memory_pool_size, NULL, KAL_FALSE);
		MMI_ASSERT(g_brw_cntx.brw_adm_id);

		mmi_brw_app_init();
		mmi_brw_settings_set_profile_req();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_instance_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_instance_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.isDeleteInsReqPending = MMI_FALSE;

	if(g_brw_cntx.isBrowserInstance)
	{
		/*reset browser instance status*/
		g_brw_cntx.isBrowserInstance = MMI_FALSE;

		/*stop splash screen timer*/
		mmi_brw_splash_screen_stop_timer();

		/*deinitialize whole browser global context*/
		mmi_brw_global_context_deinit();

		if( mmi_brw_is_browser_launched_from_main_menu() )
		{
		    /*de-allocate push module memory*/
		    mmi_brw_push_free_memory();
		}

		/*de-initalize ADM memory*/
		if(g_brw_cntx.brw_adm_id)
		{
			kal_adm_delete(g_brw_cntx.brw_adm_id);
			g_brw_cntx.brw_adm_id = NULL;
		}

		/*hide security icon if visible*/
		mmi_brw_set_status_icon(STATUS_ICON_SECURITY, MMI_FALSE);

#ifdef APPMEM_SUPPORT
		/*deinit browser application ASM memory */
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
#endif /*APPMEM_SUPPORT*/
		
		if(g_brw_cntx.common_gateway_flag)
		{
			mmi_brw_common_gateway();
		}

#ifdef __SUPPORT_INFUSIO__
		if(g_brw_cntx.activate_java_flag)
		{
			/*setting the activate java flag to false*/
			g_brw_cntx.activate_java_flag = MMI_FALSE;

			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				MMI_ASSERT(g_brw_cntx.uri_request_p);
	    		mmi_java_start_infusio_eureka_client(g_brw_cntx.uri_request_p->param);
				mmi_brw_delete_busy_screen();
			}
		}
#endif /* __SUPPORT_INFUSIO__ */
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_do_element_ind
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_do_element_ind(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index;
	U16 peerBuffLen;
    wap_bam_do_elements_ind_struct *localBuff_p = (wap_bam_do_elements_ind_struct*) msg;
    wap_bam_do_elements_struct *peerBuff_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);
	MMI_ASSERT(((ilm_struct*)ilm_p)->peer_buff_ptr);

	peerBuff_p = (wap_bam_do_elements_struct *)get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);

	g_brw_cntx.do_element_count = peerBuff_p->num_elements;

	if(g_brw_cntx.do_element_list)
	{
		mmi_brw_mfree(g_brw_cntx.do_element_list);
	}

	g_brw_cntx.do_element_list = (wap_bam_do_element_t*) 
		mmi_brw_malloc(g_brw_cntx.do_element_count * sizeof(wap_bam_do_element_t));

	for(index = 0; index < g_brw_cntx.do_element_count; index++)
	{
		g_brw_cntx.do_element_list[index].element_id = peerBuff_p->elements[index].element_id;
		g_brw_cntx.do_element_list[index].is_optional = peerBuff_p->elements[index].is_optional;
		strcpy(g_brw_cntx.do_element_list[index].label, peerBuff_p->elements[index].label);
		strcpy(g_brw_cntx.do_element_list[index].event_type, peerBuff_p->elements[index].event_type);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_save_page_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_save_page_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 peerBuffLen;
    //U16 index;
    wap_bam_save_page_cnf_struct *localBuff_p = (wap_bam_save_page_cnf_struct*) msg;
    wap_bam_saved_page_struct *peerBuff_p = NULL;
    //U8 temp_str[BRW_MAX_TITLE_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);

	if(((ilm_struct*)ilm_p)->peer_buff_ptr)
	{
		peerBuff_p = (wap_bam_saved_page_struct *) get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);
	}

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
			if(IsScreenPresent(SCR_ID_BRW_STORED_PAGE_OPTIONS))
			{
				DeleteUptoScrID(SCR_ID_BRW_STORED_PAGE_OPTIONS);
			}
			else if(IsScreenPresent(SCR_ID_BRW_STORED_PAGES))
			{
				DeleteUptoScrID(SCR_ID_BRW_STORED_PAGES);
			}
			else if(IsScreenPresent(SCR_ID_BRW_REN_PAGE_THIS_PAGE))
			{
				DeleteUptoScrID(SCR_ID_BRW_REN_PAGE_THIS_PAGE);
			}
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	switch(g_brw_cntx.sap_msg_id)
	{
		case MSG_ID_WAP_BAM_SAVE_PAGE_REQ:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_DONE), 
					(U16) IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					(U8) SUCCESS_TONE);
				mmi_brw_delete_busy_screen();
				DeleteUptoScrID(SCR_ID_BRW_REN_PAGE_THIS_PAGE);
			}
			else
			{
				mmi_brw_delete_busy_screen();
			}		
			break;
		}
		case MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ:
		{
			if(!peerBuff_p)
			{
				if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
				{
					DisplayPopup(
						(U8*) GetString(STR_ID_BRW_REQUEST_FAILED),
						(U16) IMG_GLOBAL_ERROR,
						0,
						UI_POPUP_NOTIFYDURATION_TIME,
						(U8) ERROR_TONE);
					mmi_brw_delete_busy_screen();
				}
				else
				{
					mmi_brw_delete_busy_screen();
				}		
				return;
			}
			if(!g_brw_cntx.saved_page_properties_p)
			{
				g_brw_cntx.saved_page_properties_p = 
					(wap_bam_saved_page_struct*) mmi_brw_malloc(sizeof(wap_bam_saved_page_struct));
			}
			g_brw_cntx.saved_page_properties_p->date = peerBuff_p->date;
			g_brw_cntx.saved_page_properties_p->doc_size = peerBuff_p->doc_size;
			g_brw_cntx.saved_page_properties_p->data_size = peerBuff_p->data_size;
			g_brw_cntx.saved_page_properties_p->date = peerBuff_p->date;
			strcpy((S8*)g_brw_cntx.saved_page_properties_p->label,(S8*)peerBuff_p->label);
			strcpy((S8*)g_brw_cntx.saved_page_properties_p->url, (S8*)peerBuff_p->url);

			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
	    		mmi_brw_stored_page_entry_options();
				mmi_brw_delete_busy_screen();
			}
			else
			{
				HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_STORED_PAGE_OPTIONS, mmi_brw_stored_page_entry_options);
			}
			break;
		}
		case MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_DONE), 
					(U16) IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					(U8) SUCCESS_TONE);
				mmi_brw_delete_busy_screen();
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				DeleteUptoScrID(SCR_ID_BRW_STORED_PAGES);
			}
			else
			{
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				mmi_brw_delete_busy_screen();
			}		
			break;
		}
		case MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_DONE), 
					(U16) IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					(U8) SUCCESS_TONE);
				mmi_brw_delete_busy_screen();
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				DeleteUptoScrID(SCR_ID_BRW_STORED_PAGES);
			}
			else
			{
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				mmi_brw_delete_busy_screen();
			}		
			break;
		}
		case MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_DONE),
					(U16) IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					(U8) SUCCESS_TONE);
				mmi_brw_delete_busy_screen();
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				DeleteUptoScrID(SCR_ID_BRW_STORED_PAGES);
			}
			else
			{
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				mmi_brw_delete_busy_screen();
			}		
			break;
		}
		default:
		{
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_status_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_status_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_status_ind_struct *localBuff_p = (wap_bam_status_ind_struct*) msg;
	U16 prevScrId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(g_brw_cntx.brw_status_info_p == NULL)
	{
		g_brw_cntx.brw_status_info_p = (wap_bam_status_ind_struct*) mmi_brw_malloc(sizeof(wap_bam_status_ind_struct));
	}
	g_brw_cntx.brw_status_info_p->instance_id						= localBuff_p->instance_id;
	g_brw_cntx.brw_status_info_p->status							= localBuff_p->status;
	g_brw_cntx.brw_status_info_p->transaction_id					= localBuff_p->transaction_id;		
	g_brw_cntx.brw_status_info_p->upload_bytes_sent					= localBuff_p->upload_bytes_sent;
	g_brw_cntx.brw_status_info_p->upload_bytes_total				= localBuff_p->upload_bytes_total;
	g_brw_cntx.brw_status_info_p->document_bytes_read				= localBuff_p->document_bytes_read;		
	g_brw_cntx.brw_status_info_p->document_bytes_total				= localBuff_p->document_bytes_total;		
	g_brw_cntx.brw_status_info_p->document_number_of_requested		= localBuff_p->document_number_of_requested;		
	g_brw_cntx.brw_status_info_p->document_number_of_downloaded		= localBuff_p->document_number_of_downloaded;		
	g_brw_cntx.brw_status_info_p->document_number_of_failed			= localBuff_p->document_number_of_failed;		
	g_brw_cntx.brw_status_info_p->resources_bytes					= localBuff_p->resources_bytes;		
	g_brw_cntx.brw_status_info_p->resources_number_of_requested		= localBuff_p->resources_number_of_requested;		
	g_brw_cntx.brw_status_info_p->resources_number_of_downloaded	= localBuff_p->resources_number_of_downloaded;		
	g_brw_cntx.brw_status_info_p->resources_number_of_failed		= localBuff_p->resources_number_of_failed;	
	

	switch(g_brw_cntx.brw_status_info_p->status)
	{
		case WAP_BAM_STATUS_START_TRANSACTION:
		{
			if(!g_brw_cntx.isBrowserFetching)
			{
				g_brw_cntx.isBrowserFetching = MMI_TRUE;
				mmi_brw_ren_page_set_title_icon();
				mmi_brw_ren_page_set_LSK();
				mmi_brw_ren_page_set_RSK();
			}
			break;
		}
		case WAP_BAM_STATUS_END_TRANSACTION:
		{
			if(g_brw_cntx.isBrowserFetching)
			{
				if(g_brw_cntx.document_info_p)
				{
					g_brw_cntx.isBrowserFetching = MMI_FALSE;
					mmi_brw_ren_page_set_title_icon();
					mmi_brw_ren_page_set_LSK();
					mmi_brw_ren_page_set_RSK();

					/*delete all browser screens in history*/
					/*if rendered page is the active screen*/
					if(GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
					{
						if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
						{
							DeleteNScrId(SCR_ID_BRW_INTERNET_SERVICES);
						}
						else if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
						{
							DeleteNScrId(SCR_ID_BRW_BROWSER_MAIN);
						}
					}
					/*if rendered page is the top browser screen*/
					else if(mmi_brw_get_top_screen_id() == SCR_ID_BRW_BROWSER_MAIN)
					{
						GetPreviousScrnIdOf(SCR_ID_BRW_BROWSER_MAIN, &prevScrId);

						if(IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
						{
							DeleteBetweenScreen(SCR_ID_BRW_INTERNET_SERVICES, prevScrId);
						}
					}
					/*Handling special case for page redirection*/
					/*In this case from any browser screen, control will return back to the rendered page*/
					else
					{
						mmi_brw_redirection_delete_brw_screens_upto_rend_page();
					}
				}
				else
				{
					/*stop the splash screen timer*/
					mmi_brw_splash_screen_stop_timer();
					g_brw_cntx.isBrowserFetching = MMI_FALSE;
					if( !mmi_brw_is_browser_launched_from_main_menu() )
					{
						mmi_brw_app_deinit();
					}
					GoBackHistory();
				}
			}
			g_brw_cntx.address_list_flag = MMI_FALSE;
			break;
		}
		case WAP_BAM_STATUS_TRANSACTION_STATUS:
		{
			break;
		}
		default:
		{
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_set_profile_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_set_profile_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_profile_cnf_struct *localBuff_p = (wap_bam_set_profile_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	if(!g_brw_cntx.isWapReady)
	{
		g_brw_cntx.isWapReady = MMI_TRUE;
		return;
	}

	switch(g_brw_cntx.brw_launching_pad)
	{
		case BRW_LPD_NONE:
		{
			break;
		}
		case BRW_LPD_MAIN_MENU:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
	    		mmi_brw_entry_internet_services();
				mmi_brw_delete_busy_screen();
			}
			else
			{
				HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_INTERNET_SERVICES, mmi_brw_entry_internet_services);
			}
			g_brw_cntx.mainMenuEntryFlag = MMI_TRUE;
			break;
		}
		case BRW_LPD_EXTERNAL_LOAD_URL_REQ:
		{
			//g_brw_cntx.isBrowserFetching = MMI_TRUE;
			mmi_brw_load_url_req(g_brw_current_url);
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
	    		mmi_brw_entry_render_page();
				mmi_brw_delete_busy_screen();
			}
			else
			{
				HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_BROWSER_MAIN, mmi_brw_entry_render_page);
			}
			break;
		}
		case BRW_LPD_EXTERNAL_LOAD_DATA_REQ:
		{
			//g_brw_cntx.isBrowserFetching = MMI_TRUE;
			mmi_brw_load_data_req();
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				mmi_brw_entry_render_page();
				mmi_brw_delete_busy_screen();
			}
			else
			{
				HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_BROWSER_MAIN, mmi_brw_entry_render_page);
			}
			break;
		}
		case BRW_LPD_SETTINGS_PREF:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_DONE),
					(U16) IMG_GLOBAL_ACTIVATED,
					0,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) (SUCCESS_TONE));
				mmi_brw_delete_busy_screen();
			}
			else			
			{
				mmi_brw_delete_busy_screen();
			}
			DeleteScreenIfPresent(SCR_ID_BRW_BROWSER_PREFERENCES);
			break;
		}
		case BRW_LPD_RESTORE_BRW_SETTINGS:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(U8*) GetString(STR_GLOBAL_DONE),
					(U16) IMG_GLOBAL_ACTIVATED,
					0,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) (SUCCESS_TONE));
				mmi_brw_delete_busy_screen();
			}
			else			
			{
				mmi_brw_delete_busy_screen();
			}
			break;
		}
		case BRW_LPD_ACTIVE_PROFILE_CHANGED:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				mmi_brw_prof_display_activation_popup();
				mmi_brw_delete_busy_screen();
			}
			else			
			{
				mmi_brw_delete_busy_screen();
			}
			break;
		}
		default:
		{
			break;
		}
	}
	g_brw_cntx.brw_launching_pad = BRW_LPD_NONE;
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_get_saved_pages_list_start_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_get_saved_pages_list_start_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_start_cnf_struct *localBuff_p = (wap_bam_get_saved_pages_list_start_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->error_code == 0)
	{
		if(localBuff_p->num_items > 0)
		{
			g_brw_cntx.dynamic_list_count = localBuff_p->num_items;
			g_brw_cntx.dynamic_list = 
				mmi_brw_malloc(g_brw_cntx.dynamic_list_count * sizeof(brw_dynamic_list_struct));
			mmi_brw_stored_pages_get_saved_pages_list_continue_req(0);
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
			return;
		}
	}
	else
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_stored_pages_get_saved_pages_list_continue_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_stored_pages_get_saved_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
	//U32 count;
	U32 titleLen;
	S8* peerBuff_p;
	U16 peerBuffLen;
    wap_bam_get_saved_pages_list_continue_cnf_struct *localBuff_p = (wap_bam_get_saved_pages_list_continue_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);
	MMI_ASSERT(((ilm_struct*)ilm_p)->peer_buff_ptr);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	peerBuff_p = (S8*)get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);

	for(index = localBuff_p->start_index; index < localBuff_p->num_items + localBuff_p->start_index; index++)
	{
		titleLen = bam_get_bits((char *)peerBuff_p, sizeof(U32) * 8);
		g_brw_cntx.dynamic_list[index].name = mmi_brw_malloc((titleLen+1)*sizeof(U8));
		strncpy((S8*)g_brw_cntx.dynamic_list[index].name, (S8*)peerBuff_p + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT, titleLen);
		g_brw_cntx.dynamic_list[index].name[titleLen] = '\0';
		peerBuff_p += titleLen + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
		g_brw_cntx.dynamic_list[index].host = NULL;
	}
	if(index < g_brw_cntx.dynamic_list_count)
	{
		mmi_brw_stored_pages_get_saved_pages_list_continue_req(index);
	}
	else
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_entry_stored_page_list();
			mmi_brw_delete_busy_screen();
		}
		else
		{
			HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_STORED_PAGES, mmi_brw_entry_stored_page_list);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_resource_list_start_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_list_start_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_start_cnf_struct *localBuff_p = (wap_bam_get_resources_list_start_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	if(localBuff_p->num_res > 0)
	{
		g_brw_cntx.dynamic_list_count = localBuff_p->num_res;
		g_brw_cntx.dynamic_list = mmi_brw_malloc(g_brw_cntx.dynamic_list_count * sizeof(brw_dynamic_list_struct));
		mmi_brw_this_page_get_resource_list_continue_req(0);
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
 *  mmi_brw_this_page_get_resource_list_continue_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_list_continue_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
	U32 titleLen;
	U16 peerBuffLen;
	S8* peerBuff_p;
    wap_bam_get_resources_list_continue_cnf_struct *localBuff_p = (wap_bam_get_resources_list_continue_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);
	MMI_ASSERT(((ilm_struct*)ilm_p)->peer_buff_ptr);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	peerBuff_p = (S8*)get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);

	for(index = localBuff_p->start_index; index < localBuff_p->num_res + localBuff_p->start_index; index++)
	{
		g_brw_cntx.dynamic_list[index].type = bam_get_bits((char *)peerBuff_p, sizeof(U32) * 8);
		peerBuff_p += BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
		titleLen = bam_get_bits((char *)peerBuff_p, sizeof(U32) * 8);
		g_brw_cntx.dynamic_list[index].name = mmi_brw_malloc((titleLen+1)*sizeof(U8));
		strncpy((S8*)g_brw_cntx.dynamic_list[index].name, (S8*)peerBuff_p + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT, titleLen);
		g_brw_cntx.dynamic_list[index].name[titleLen] = '\0';
		peerBuff_p += titleLen + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
		g_brw_cntx.dynamic_list[index].host = NULL;

		if(g_brw_cntx.dynamic_list[index].type == WAP_BAM_RSRC_TYPE_IMAGE)
		{
			g_brw_page_objs_image_list[g_brw_cntx.page_objs_images_count++].res_list_index = index;
		}
		else if(g_brw_cntx.dynamic_list[index].type == WAP_BAM_RSRC_TYPE_BACKGROUND)
		{
			g_brw_page_objs_bg_image_list[g_brw_cntx.page_objs_bg_images_count++].res_list_index = index;
		}
		else if(g_brw_cntx.dynamic_list[index].type == WAP_BAM_RSRC_TYPE_SOUND)
		{
			g_brw_page_objs_sound_list[g_brw_cntx.page_objs_sounds_count++].res_list_index = index;
		}
		else if(g_brw_cntx.dynamic_list[index].type == WAP_BAM_RSRC_TYPE_OTHER)
		{
			g_brw_page_objs_others_list[g_brw_cntx.page_objs_others_count++].res_list_index = index;
		}

	}
	if(index < g_brw_cntx.dynamic_list_count)
	{
		mmi_brw_this_page_get_resource_list_continue_req(index);
	}
	else
	{
		mmi_brw_this_page_pre_entry_page_object_types();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_get_resource_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_get_resource_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 peerBuffLen;
    wap_bam_get_resource_cnf_struct *localBuff_p = (wap_bam_get_resource_cnf_struct*) msg;
    wap_bam_resource_item_struct *peerBuff_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);
	MMI_ASSERT(((ilm_struct*)ilm_p)->peer_buff_ptr);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	peerBuff_p = (wap_bam_resource_item_struct*) get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);

	if(g_brw_cntx.brw_res_item_info_p == NULL)
	{
		g_brw_cntx.brw_res_item_info_p = (wap_bam_resource_item_struct*) mmi_brw_malloc(sizeof(wap_bam_resource_item_struct));
	}

	g_brw_cntx.brw_res_item_info_p->type = peerBuff_p->type;
	g_brw_cntx.brw_res_item_info_p->drm_restriction = peerBuff_p->drm_restriction;
	g_brw_cntx.brw_res_item_info_p->size = peerBuff_p->size;
	strcpy((S8*)g_brw_cntx.brw_res_item_info_p->title, (S8*)peerBuff_p->title);
	strcpy((S8*)g_brw_cntx.brw_res_item_info_p->url, (S8*)peerBuff_p->url);
	strcpy((S8*)g_brw_cntx.brw_res_item_info_p->mime_type, (S8*)peerBuff_p->mime_type);
	strcpy((S8*)g_brw_cntx.brw_res_item_info_p->cache_file, (S8*)peerBuff_p->cache_file);

	if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
	{
		mmi_brw_page_objects_entry_options();
		mmi_brw_delete_busy_screen();
	}
	else
	{
		HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_PAGE_OBJECTS_OPTIONS, mmi_brw_page_objects_entry_options);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_error_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_error_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_error_ind_struct *localBuff_p = (wap_bam_error_ind_struct*) msg;
	nvram_profile_content_struct *activeProfile;
	MMI_BOOL csd_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->error_code)
	{

		switch(localBuff_p->error_code)
		{
			/*Do nothing, simply return back for Java Script errors*/
			case WAP_BAM_ERR_JSCRIPT_NONE:
			case WAP_BAM_ERR_JSCRIPT_ERR:	
			case WAP_BAM_ERR_JSCRIPT_INTERNALERR:
			case WAP_BAM_ERR_JSCRIPT_EVALERR:
			case WAP_BAM_ERR_JSCRIPT_RANGEERR:
			case WAP_BAM_ERR_JSCRIPT_REFERENCEERR:
			case WAP_BAM_ERR_JSCRIPT_SYNTAXERR:
			case WAP_BAM_ERR_JSCRIPT_TYPEERR:
			case WAP_BAM_ERR_JSCRIPT_URIERR:
			{
				return;
			}

			/*Show the error pop-up and return back*/
			case WAP_BAM_ERROR_LOW_MEMORY:
			{
				if(GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
				{
					mmi_brw_bam_error_handler(localBuff_p->error_code);
				}
				break;
			}

			/*show the error pop-up, de-initialize the browser and exit*/
			case WAP_BAM_ERROR_OUT_OF_MEMORY:
			{
				if(GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
				{
					mmi_brw_bam_error_handler(localBuff_p->error_code);
				}
				g_brw_cntx.isBrowserFetching = MMI_FALSE;

				/*stop the splash screen timer*/
				mmi_brw_splash_screen_stop_timer();

				mmi_brw_app_deinit();
				break;
			}

			/* show the error pop-up and check the following cases
			 * (1) delete rendered page screen, if no previously opened page exists
			 * (2) de-init browser application, if no previously opened page exists
			 * and it is launched from other application
			*/
			default:
			{
				/*Filtering the connection fail error popup for CSD account as it*/
				/*is handled by the CallManager*/
				csd_flag = MMI_FALSE;
				if(localBuff_p->error_code == WAP_BAM_ERROR_CONNECTION_FAILED)
				{
					activeProfile = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_wap_profile();
					if(mmi_dtcnt_get_bearer_type(activeProfile->data_account_primary_id) == DATA_ACCOUNT_BEARER_CSD)
					{
						csd_flag = MMI_TRUE;
					}
				}

				if(!csd_flag)
				{
					if(GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
					{
						mmi_brw_bam_error_handler(localBuff_p->error_code);
					}
				}
				g_brw_cntx.isBrowserFetching = MMI_FALSE;

				/*stop the splash screen timer*/
				mmi_brw_splash_screen_stop_timer();

				/*delete rendered page if no previously opened page exists*/
				if(!g_brw_cntx.document_info_p)
				{
					DeleteScreenIfPresent(SCR_ID_BRW_BROWSER_MAIN);
				}

				/*delete browser instance if control returns back to the launched 
				module*/
				if( !g_brw_cntx.document_info_p &&
					!mmi_brw_is_browser_launched_from_main_menu() )
				{
					mmi_brw_app_deinit();
				}
				break;
			}
		}
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_document_info_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_document_info_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_document_info_ind_struct *localBuff_p = (wap_bam_document_info_ind_struct*) msg;
	U8 title_temp[(BRW_MAX_TITLE_LENGTH+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(mmi_brw_is_browser_first_page())
	{
		mmi_brw_splash_screen_stop_timer();
		if(GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
		{
			mmi_brw_entry_render_page();
		}
	}

	if(g_brw_cntx.document_info_p == NULL)
	{
		g_brw_cntx.document_info_p = (wap_bam_document_info_ind_struct*) mmi_brw_malloc(sizeof(wap_bam_document_info_ind_struct));
	}

	g_brw_cntx.document_info_p->document_id = localBuff_p->document_id;
	g_brw_cntx.document_info_p->flags = localBuff_p->flags;
	g_brw_cntx.document_info_p->doc_type = localBuff_p->doc_type;
	g_brw_cntx.document_info_p->protocol = localBuff_p->protocol;
	g_brw_cntx.document_info_p->size = localBuff_p->size;
	g_brw_cntx.document_info_p->socket_id = localBuff_p->socket_id;
	g_brw_cntx.document_info_p->security_id = localBuff_p->security_id;
	g_brw_cntx.document_info_p->last_modified = localBuff_p->last_modified;
	strcpy((S8*)g_brw_cntx.document_info_p->url, (S8*)localBuff_p->url);
	strcpy((S8*)g_brw_cntx.document_info_p->title, (S8*)localBuff_p->title);

	if(g_brw_cntx.document_info_p->security_id >= 0)
	{
		mmi_brw_set_status_icon(STATUS_ICON_SECURITY, MMI_TRUE);
	}
	else
	{
		mmi_brw_set_status_icon(STATUS_ICON_SECURITY, MMI_FALSE);
	}

	mmi_brw_ren_page_set_title_string();

	if(g_brw_cntx.do_element_list)
	{
		mmi_brw_mfree(g_brw_cntx.do_element_list);
		g_brw_cntx.do_element_list = NULL;
		g_brw_cntx.do_element_count = 0;
	}
	if(g_brw_cntx.focused_element_info_p)
	{
		mmi_brw_mfree(g_brw_cntx.focused_element_info_p);
		g_brw_cntx.focused_element_info_p = NULL;
	}

	/*Updating and writing into NMRAM the last web address*/
	strcpy((S8*)g_brw_cntx.last_web_address, (S8*)localBuff_p->url);
	mmi_brw_write_last_web_address();
	/*Updating and writing into NMRAM the last web address*/

	/*Update Address list title*/
	if(g_brw_cntx.address_list_flag)
	{
		mmi_chset_utf8_to_ucs2_string((U8*)title_temp, (BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.document_info_p->title);
		mmi_brw_address_list_update_title_to_nvram(title_temp);
		g_brw_cntx.address_list_flag = MMI_FALSE;
	}
	/*Update Address list title*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_element_focused_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_element_focused_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_element_focused_ind_struct *localBuff_p = (wap_bam_element_focused_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(g_brw_cntx.focused_element_info_p == NULL)
	{
		g_brw_cntx.focused_element_info_p = (wap_bam_element_focused_ind_struct*) mmi_brw_malloc(sizeof(wap_bam_element_focused_ind_struct));
	}

	g_brw_cntx.focused_element_info_p->resource_type = localBuff_p->resource_type;
	g_brw_cntx.focused_element_info_p->type = localBuff_p->type;
	g_brw_cntx.focused_element_info_p->drm_restriction = localBuff_p->drm_restriction;
	g_brw_cntx.focused_element_info_p->size = localBuff_p->size;
	strcpy((S8*)g_brw_cntx.focused_element_info_p->resource_id, (S8*)localBuff_p->resource_id);
	strcpy((S8*)g_brw_cntx.focused_element_info_p->title, (S8*)localBuff_p->title);
	strcpy((S8*)g_brw_cntx.focused_element_info_p->url, (S8*)localBuff_p->url);
	strcpy((S8*)g_brw_cntx.focused_element_info_p->object_url, (S8*)localBuff_p->object_url);
	strcpy((S8*)g_brw_cntx.focused_element_info_p->object_mime, (S8*)localBuff_p->object_mime);
	strcpy((S8*)g_brw_cntx.focused_element_info_p->object_filePath, (S8*)localBuff_p->object_filePath);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_security_class_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_security_class_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_sec_class_ind_struct *localBuff_p = (wap_bam_set_sec_class_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_recent_pages_list_start_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_recent_pages_list_start_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_start_cnf_struct *localBuff_p = (wap_bam_get_recent_pages_list_start_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->error_code == 0)
	{
		if(localBuff_p->num_item > 0)
		{
			g_brw_cntx.dynamic_list_count = localBuff_p->num_item;
			g_brw_cntx.dynamic_list = 
				mmi_brw_malloc(g_brw_cntx.dynamic_list_count * sizeof(brw_dynamic_list_struct));
			g_brw_cntx.recent_page_list = 
				mmi_brw_malloc(g_brw_cntx.dynamic_list_count * sizeof(brw_recent_page_list_struct));
			mmi_brw_recent_pages_get_recent_pages_list_continue_req(0);
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
			return;
		}
	}
	else
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_pages_get_recent_pages_list_continue_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_pages_get_recent_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U32 * intp;
	U32 index;
	//U32 count;
	U32 titleLen;
	U16 peerBuffLen;
	S8* peerBuff_p;
    wap_bam_get_recent_pages_list_continue_cnf_struct *localBuff_p = (wap_bam_get_recent_pages_list_continue_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);
	MMI_ASSERT(((ilm_struct*)ilm_p)->peer_buff_ptr);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	peerBuff_p = (S8*)get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);

	for(index = localBuff_p->start_index; index < localBuff_p->num_items + localBuff_p->start_index; index++)
	{
		titleLen = bam_get_bits((char *)peerBuff_p, sizeof(U32) * 8);
		g_brw_cntx.dynamic_list[index].name = mmi_brw_malloc((titleLen+1) * sizeof(U8));
		strncpy((S8*)g_brw_cntx.dynamic_list[index].name, (S8*)peerBuff_p + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT, titleLen);
		g_brw_cntx.dynamic_list[index].name[titleLen] = '\0';
		peerBuff_p += (titleLen + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT);

		if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
		{
			titleLen = bam_get_bits(peerBuff_p, sizeof(U32) * 8);
			g_brw_cntx.dynamic_list[index].host = mmi_brw_malloc((titleLen+1) * sizeof(U8));
			strncpy((S8*)g_brw_cntx.dynamic_list[index].host, (S8*)peerBuff_p + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT, titleLen);
			g_brw_cntx.dynamic_list[index].host[titleLen] = '\0';
			peerBuff_p += titleLen + BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
		}
		else
		{
			g_brw_cntx.dynamic_list[index].host = NULL;
		}
	}

	if(index < g_brw_cntx.dynamic_list_count)
	{
		mmi_brw_recent_pages_get_recent_pages_list_continue_req(index);
	}
	else
	{
    	mmi_brw_pre_entry_recent_page_list();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_recent_page_cnf
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_recent_page_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 peerBuffLen;
    wap_bam_recent_page_cnf_struct *localBuff_p = (wap_bam_recent_page_cnf_struct*) msg;
    wap_bam_recent_page_struct *peerBuff_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	MMI_ASSERT(localBuff_p);
	MMI_ASSERT(ilm_p);

	if(localBuff_p->error_code)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_bam_error_handler(localBuff_p->error_code);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	switch(g_brw_cntx.sap_msg_id)
	{
		case MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ:
		{
			if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
			{
				/*if more recent pages are present in the selected host then delete them too*/
				if(g_brw_cntx.recent_page_host_delete_count > 0)
				{
					mmi_brw_dynamic_list_delete_item(
						(U16)g_brw_cntx.recent_page_list[g_brw_cntx.recent_page_host_delete_count].actual_index);

					mmi_brw_recent_pages_delete_recent_page_req(
						g_brw_cntx.recent_page_list[--g_brw_cntx.recent_page_host_delete_count].actual_index);
					break;
				}
				/*if recent page list is empty then delete the selected host(called from 'Delete All')*/
				else if(g_brw_cntx.recent_page_host_delete_count == 0)
				{
					if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
					{
						DisplayPopup(
							(PU8) GetString(STR_GLOBAL_DONE), 
							IMG_GLOBAL_ACTIVATED, 
							1, 
							UI_POPUP_NOTIFYDURATION_TIME, 
							SUCCESS_TONE);
						mmi_brw_delete_busy_screen();
						g_brw_cntx.list_refresh_flag = MMI_TRUE;
						DeleteUptoScrID(SCR_ID_BRW_RECENT_PAGES_HOST);
					}
					else
					{
						mmi_brw_delete_busy_screen();
						g_brw_cntx.list_refresh_flag = MMI_TRUE;
					}					
					break;
				}
			}//if(g_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)			
			else
			{
				if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
				{
					DisplayPopup(
						(PU8) GetString(STR_GLOBAL_DONE), 
						IMG_GLOBAL_ACTIVATED, 
						1, 
						UI_POPUP_NOTIFYDURATION_TIME, 
						SUCCESS_TONE);
					mmi_brw_delete_busy_screen();
					g_brw_cntx.list_refresh_flag = MMI_TRUE;
					DeleteUptoScrID(SCR_ID_BRW_RECENT_PAGES);
				}
				else
				{
					mmi_brw_delete_busy_screen();
					g_brw_cntx.list_refresh_flag = MMI_TRUE;
				}					
				break;
			}
		}
		case MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ:
		{
			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
				DisplayPopup(
					(PU8) GetString(STR_GLOBAL_DONE), 
					IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					SUCCESS_TONE);
				mmi_brw_delete_busy_screen();
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				if(IsScreenPresent(SCR_ID_BRW_RECENT_PAGES_HOST))
				{
					DeleteUptoScrID(SCR_ID_BRW_RECENT_PAGES_HOST);
				}
				else
				{
					DeleteUptoScrID(SCR_ID_BRW_RECENT_PAGES);
				}
			}
			else
			{
				g_brw_cntx.list_refresh_flag = MMI_TRUE;
				mmi_brw_delete_busy_screen();
			}
			break;
		}
		case MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ:
		{
			MMI_ASSERT(((ilm_struct*)ilm_p)->peer_buff_ptr);
			
			peerBuff_p = (wap_bam_recent_page_struct *) get_pdu_ptr(((ilm_struct*)ilm_p)->peer_buff_ptr, &peerBuffLen);
			if(!g_brw_cntx.recent_page_info_p)
			{
				g_brw_cntx.recent_page_info_p = 
					(wap_bam_recent_page_struct*) mmi_brw_malloc(sizeof(wap_bam_recent_page_struct));
			}
			g_brw_cntx.recent_page_info_p->timestamp = peerBuff_p->timestamp;
			g_brw_cntx.recent_page_info_p->hits = peerBuff_p->hits;
			g_brw_cntx.recent_page_info_p->url_hash = peerBuff_p->url_hash;
			strcpy((S8*)g_brw_cntx.recent_page_info_p->title,(S8*)peerBuff_p->title);
			strcpy((S8*)g_brw_cntx.recent_page_info_p->url, (S8*)peerBuff_p->url);

			if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
			{
	    		mmi_brw_recent_page_entry_options();
				mmi_brw_delete_busy_screen();
			}
			else
			{
				HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_RECENT_PAGE_OPTIONS, mmi_brw_recent_page_entry_options);
			}
			break;
		}
		default:
		{
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_tel_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_tel_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_tel_ind_struct *localBuff_p = (wap_bam_wtai_tel_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	g_brw_cntx.sap_request_id = localBuff_p->request_id;
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_phone_number, (BRW_WTAI_PHONE_NUMBER_LEN+1) * ENCODING_LENGTH, (U8*)localBuff_p->param);

	if(localBuff_p->operation == WAP_BAM_WTAI_TEL_MAKE_CALL)
	{
		mmi_brw_watai_tel_make_call_confirm();
	}
	else if(localBuff_p->operation == WAP_BAM_WTAI_TEL_SEND_DTMF)
	{
		mmi_brw_watai_tel_send_dtmf_confirm();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_watai_pb_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_watai_pb_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_pb_ind_struct *localBuff_p = (wap_bam_wtai_pb_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	g_brw_cntx.sap_request_id = localBuff_p->request_id;
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_url, (BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH, (U8*)localBuff_p->name);
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_phone_number, (BRW_WTAI_PHONE_NUMBER_LEN+1) * ENCODING_LENGTH, (U8*)localBuff_p->number);

	mmi_brw_watai_pb_add_new_entry_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_uri_request_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_uri_request_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_uri_request_ind_struct *localBuff_p = (wap_bam_uri_request_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(!g_brw_cntx.uri_request_p)
	{
		g_brw_cntx.uri_request_p = 
			(wap_bam_uri_request_ind_struct*) mmi_brw_malloc(sizeof(wap_bam_uri_request_ind_struct));
	}

	g_brw_cntx.sap_request_id = localBuff_p->request_id;
	g_brw_cntx.uri_request_p->instance_id = localBuff_p->instance_id;
	g_brw_cntx.uri_request_p->request_id = localBuff_p->request_id;
	strcpy((S8*)g_brw_cntx.uri_request_p->scheme, (S8*)localBuff_p->scheme);
	strcpy((S8*)g_brw_cntx.uri_request_p->param, (S8*)localBuff_p->param);

	if(!mmi_brw_stricmp((S8*)g_brw_cntx.uri_request_p->scheme, (S8*)BRW_URI_REQ_SCHEME_ACTIVATE_JAVA))
	{
		mmi_brw_uri_request_activate_java_confirm();
	}
	else if( !mmi_brw_stricmp((S8*)g_brw_cntx.uri_request_p->scheme, (S8*)BRW_URI_REQ_SCHEME_SEND_SMS) ||
			 !mmi_brw_stricmp((S8*)g_brw_cntx.uri_request_p->scheme, (S8*)BRW_URI_REQ_SCHEME_SEND_SMS_TO)
			 )
	{
		mmi_brw_uri_request_send_sms_confirm();
	}
	else if( !mmi_brw_stricmp((S8*)g_brw_cntx.uri_request_p->scheme, (S8*)BRW_URI_REQ_SCHEME_SEND_MMS) ||
			 !mmi_brw_stricmp((S8*)g_brw_cntx.uri_request_p->scheme, (S8*)BRW_URI_REQ_SCHEME_SEND_MMS_TO)
			 )
	{
		mmi_brw_uri_request_send_mms_confirm();
	}

	//mmi_brw_process_uri_request_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bearer_info_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bearer_info_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_bearer_info_ind_struct *localBuff_p = (wap_bam_bearer_info_ind_struct*) msg;
	nvram_profile_content_struct *currProfStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(!g_brw_cntx.bearer_info_p)
	{
		g_brw_cntx.bearer_info_p = (wap_bam_bearer_info_ind_struct*) mmi_brw_malloc(sizeof(wap_bam_bearer_info_ind_struct));
	}

	g_brw_cntx.bearer_info_p->instance_id = localBuff_p->instance_id;
	g_brw_cntx.bearer_info_p->bearer_type = localBuff_p->bearer_type;
	g_brw_cntx.bearer_info_p->bearer_state = localBuff_p->bearer_state;

	currProfStruct = (nvram_profile_content_struct *)mmi_brw_prof_get_activated_wap_profile();

	if(currProfStruct->data_account_secondary_id >= 0)
	{
		mmi_brw_bearer_info_confirm();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_data_rsp
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_data_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_rsp_struct *localBuff_p = (wps_clear_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->result)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_wps_error_handler(localBuff_p->result);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
	}
	else
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			DisplayPopup(
				(U8*) GetString(STR_GLOBAL_DONE),
				(U16) IMG_GLOBAL_ACTIVATED,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) (SUCCESS_TONE));
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
	}
	return;
}

// Dihrin Input Integration begin
#include "wap.h"
// Dihrin Input Integration end

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wait_user_action_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const char *empty_str = "";
    wap_bam_wait_user_action_ind_struct *localBuff_p = (wap_bam_wait_user_action_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

    if (GetActiveScreenId() != SCR_ID_BRW_BROWSER_MAIN)
    {
        return;
    }

	if(mmi_brw_is_browser_first_page())
	{
		mmi_brw_splash_screen_stop_timer();
		mmi_brw_entry_render_page();
	}

	if(localBuff_p->enable_positive_sk)
	{
		mmi_chset_utf8_to_ucs2_string((U8*)g_leftSoftKeyLabel, 
			(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)localBuff_p->positive_label);	
		ChangeLeftSoftkeyByString((UI_string_type)g_leftSoftKeyLabel, 0);
		SetLeftSoftkeyFunction(mmi_brw_wait_user_action_positive_key_hdlr, KEY_EVENT_UP);
	}
	else
	{
		mmi_chset_utf8_to_ucs2_string((U8*)g_leftSoftKeyLabel, 
			(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)empty_str);	
		ChangeLeftSoftkeyByString((UI_string_type)g_leftSoftKeyLabel, 0);
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}

	if(localBuff_p->enable_negative_sk)
	{
		mmi_chset_utf8_to_ucs2_string((U8*)g_rightSoftKeyLabel, 
			(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)localBuff_p->negative_label);	
		ChangeRightSoftkeyByString((UI_string_type)g_rightSoftKeyLabel, 0);
		SetRightSoftkeyFunction(mmi_brw_wait_user_action_negative_key_hdlr, KEY_EVENT_UP);
	}
	else
	{
		mmi_chset_utf8_to_ucs2_string((U8*)g_rightSoftKeyLabel, 
			(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH, (U8*)empty_str);	
		ChangeRightSoftkeyByString((UI_string_type)g_rightSoftKeyLabel, 0);
		SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
	}

	if((!localBuff_p->enable_positive_sk) && (!localBuff_p->enable_negative_sk))
	{
		mmi_brw_ren_page_set_LSK();
		mmi_brw_ren_page_set_RSK();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bam_ready_ind
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bam_ready_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_ready_ind_struct *localBuff_p = (wap_bam_ready_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	//g_brw_cntx.brw_launching_pad = BRW_LPD_NONE;
	mmi_brw_settings_set_profile_req();
}


#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bkgrd_downloads_ind
 * DESCRIPTION
 *  This function is indication for multiple downloads
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bkgrd_downloads_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_download_info_ind_struct *localBuff_p = (mmi_da_download_info_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(!g_brw_cntx.download_info_p)
	{
		g_brw_cntx.download_info_p = 
			(mmi_da_download_info_ind_struct*) OslMalloc(sizeof(mmi_da_download_info_ind_struct));
	}

	g_brw_cntx.download_info_p->job_count		 = localBuff_p->job_count;
	g_brw_cntx.download_info_p->active_job_count = localBuff_p->active_job_count;
}
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_select_bookmark_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_select_bookmark_req(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_pre_entry_select_bookmark();
}
#endif /*__MMI_VBOOKMARK__*/


#if defined (WAP_SEC_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_trusted_certificate_ids_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_trusted_certificate_ids_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_ids_rsp_struct *localBuff_p = (wps_sec_get_cert_ids_rsp_struct*) msg;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(!localBuff_p->total)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_EMPTY_TRUSTED_CERT_LIST),
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
		return;
	}
	else
	{	
		g_brw_cntx.trusted_cert_ids.total = localBuff_p->total;
        for(i = 0; i < localBuff_p->total; i++)
        {
            g_brw_cntx.trusted_cert_ids.cert_ids[i] = localBuff_p->cert_ids[i];
        }
		mmi_brw_security_settings_get_trusted_certificate_req(g_brw_cntx.trusted_cert_ids.cert_ids[0]);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_trusted_certificate_rsp
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_trusted_certificate_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_rsp_struct *localBuff_p = (wps_sec_get_cert_rsp_struct*) msg;
	U32 index;
	U8 cert_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);
	if(localBuff_p->result)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_wps_error_handler(localBuff_p->result);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	if(!g_brw_cntx.trusted_cert_list_p)
	{
		g_brw_cntx.trusted_cert_list_p = (wps_sec_get_cert_rsp_struct*) 
			mmi_brw_malloc(g_brw_cntx.trusted_cert_ids.total * sizeof(wps_sec_get_cert_rsp_struct));

		memset(g_brw_cntx.trusted_cert_list_p,0,g_brw_cntx.trusted_cert_ids.total * sizeof(wps_sec_get_cert_rsp_struct));
	}

	cert_id = localBuff_p->cert_id;

	//Assuming that cert id can be any number from (0 - BRW_MAX_TRUSTED_CERTIFICATES-1) in any order
	for(index=0; index < g_brw_cntx.trusted_cert_ids.total; index++)
	{
		if(cert_id == g_brw_cntx.trusted_cert_ids.cert_ids[index])
		{
			g_brw_cntx.trusted_cert_list_p[index].cert_id = cert_id;
			mmi_brw_security_settings_copy_trusted_certificate(&g_brw_cntx.trusted_cert_list_p[index].cert, 
				&localBuff_p->cert);
			if(index == g_brw_cntx.trusted_cert_ids.total-1)
			{
				if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
				{
	    			mmi_brw_security_settings_entry_trusted_certificates();
					mmi_brw_delete_busy_screen();
				}
				else
				{
					HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_TRUSTED_CERTIFICATES, mmi_brw_security_settings_entry_trusted_certificates);
				}
			}
			else
			{
				mmi_brw_security_settings_get_trusted_certificate_req(g_brw_cntx.trusted_cert_ids.cert_ids[index+1]);
			}
			break;
		}	
	}

	if(index == g_brw_cntx.trusted_cert_ids.total)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_REQUEST_FAILED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
	}

	/*de-allocating STK control buffers for rsa_modulus & rsa_exponent*/
	if(localBuff_p->rsa_public_key.rsa_modulus)
	{
		OslMfree(localBuff_p->rsa_public_key.rsa_modulus);
		localBuff_p->rsa_public_key.rsa_modulus = NULL;
	}
	if(localBuff_p->rsa_public_key.rsa_exponent)
	{
		OslMfree(localBuff_p->rsa_public_key.rsa_exponent);
		localBuff_p->rsa_public_key.rsa_exponent = NULL;
	}

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_session_info_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_session_info_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *localBuff_p = (wps_sec_get_session_info_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->result)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_wps_error_handler(localBuff_p->result);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	if(g_brw_cntx.session_info_p == NULL)
	{
		g_brw_cntx.session_info_p = (wps_sec_get_session_info_rsp_struct*) mmi_brw_malloc(sizeof(wps_sec_get_session_info_rsp_struct));
	}
	g_brw_cntx.session_info_p->key_exchange_alg    = localBuff_p->key_exchange_alg;
	g_brw_cntx.session_info_p->blk_encrypt_alg     = localBuff_p->blk_encrypt_alg;
	g_brw_cntx.session_info_p->hash_alg			   = localBuff_p->hash_alg;		
	g_brw_cntx.session_info_p->sec_conn_type	   = localBuff_p->sec_conn_type;

	if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
	{
	    mmi_brw_security_settings_entry_session_info();
		mmi_brw_delete_busy_screen();
	}
	else
	{
		HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_SESSION_INFO, mmi_brw_security_settings_entry_session_info);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_trusted_certificates_delete_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_trusted_certificates_delete_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_delete_ca_cert_rsp_struct *localBuff_p = (wps_sec_delete_ca_cert_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->result == WPS_OK && mmi_brw_is_browser_active())
	{
		mmi_brw_security_settings_get_trusted_certificate_ids_req();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_current_certificate_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_current_certificate_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *localBuff_p = (wps_sec_get_current_cert_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	if(localBuff_p->result)
	{
		if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
		{
			mmi_brw_wps_error_handler(localBuff_p->result);
			mmi_brw_delete_busy_screen();
		}
		else
		{
			mmi_brw_delete_busy_screen();
		}
		return;
	}

	if(g_brw_cntx.current_cert_p == NULL)
	{
		g_brw_cntx.current_cert_p = (wps_sec_get_current_cert_rsp_struct*) mmi_brw_malloc(sizeof(wps_sec_get_current_cert_rsp_struct));
	}

	mmi_brw_security_settings_copy_current_certificate(g_brw_cntx.current_cert_p, localBuff_p);

	if(GetActiveScreenId() == SCR_ID_BRW_BUSY_SCREEN)
	{
	    mmi_brw_security_settings_entry_current_cert();
		mmi_brw_delete_busy_screen();
	}
	else
	{
		HistoryReplace(SCR_ID_BRW_BUSY_SCREEN, SCR_ID_BRW_CURRENT_CERT, mmi_brw_security_settings_entry_current_cert);
	}
}
#endif /*WAP_SEC_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wap_browser_startup_req
 * DESCRIPTION
 *  Request handler for MSG_ID_WAP_BROWSER_STARTUP_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wap_browser_startup_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_browser_startup_req_struct *localBuff_p = (wap_browser_startup_req_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(localBuff_p);

	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_current_url, (BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH, (U8*)localBuff_p->url);
	mmi_brw_start_browser_action(localBuff_p->type, g_brw_current_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bam_error_handler
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bam_error_handler(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(error_code)
	{
		case WAP_BAM_ERROR_INVALID_INPUT://14
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INVALID_PARAM),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_INVALID_URL://15
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INVALID_URL),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_INVALID_SCHEME://16
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_UNSUPPORTED_SCHEME),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_UNKNOWN_CHARSET://21
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_UNSUPPORTED_ENCODING),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SYNTAX://22
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_SYNTAX_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_UNKNOWN_DOCTYPE://23
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_UNKNOWN_DOC_TYPE),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_UNSUPPORTED_WBXML://24
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_UNSUPPORTED_WBXML),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_VALIDATION://25
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_DOC_VALIDATION_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_ABORTED://26
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_PARSER_NOT_INITIALIZED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WML://40
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_ERR_WML_ACCESS_VIOLATION),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WMLS://41
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_ERR_WML_SCRIPT_ACCESS_VIOLATION),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_COMMUNICATION://50
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_ERROR_COMMUNICATION),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_HOST_NOT_FOUND://51
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_HOST_NOT_FOUND),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_REQUEST_TIMED_OUT://52
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_REQUEST_TIMEOUT),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_CONNECTION_FAILED://53
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_CONNECTION_FAILED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SECURE_CONNECTION_FAILED://54
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_SECURE_CONNECTION_FAILED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_AUTHENTICATION://55
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_ERROR_AUTHENTICATION),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SECURE_CONNECTION_CANCELLED://56
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_SECURE_CONNECTION_CANCELLED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_INTERNAL://70
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INTERNAL_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_RESEND_POST_WARNING://71
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_RESEND_POST_WARNING),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_LOW_MEMORY://72
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_ERROR_LOW_MEMORY),
				(U16) IMG_GLOBAL_WARNING,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) WARNING_TONE);
			break;
		}
		case WAP_BAM_ERROR_CONTENT_TOO_LARGE://73
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_CONTENT_TOO_LARGE),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_OUT_OF_MEMORY://75
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_OUT_OF_MEMORY),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SAVED_PAGES_NOT_FOUND://80
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_PAGE_NOT_FOUND),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SAVED_PAGES_EXISTS://81
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_PAGE_ALREADY_EXISTS),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SAVED_PAGES_FAILED://82
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_REQUEST_FAILED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_SAVED_PAGES_PARTIAL://83
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_PAGE_SAVED_PARTIALLY),
				(U16) IMG_GLOBAL_WARNING,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) WARNING_TONE);
			break;
		}
		case WAP_BAM_ERROR_SAVED_PAGES_LIMIT_EXCEEDED://84
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_PAGE_LIMIT_EXCEEDED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_RECENT_PAGES_NOT_FOUND://90
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_PAGE_NOT_FOUND),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WAP_BAM_ERROR_RECENT_PAGES_FAILED://91
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_REQUEST_FAILED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		default:
		{
			DisplayPopup(
				(U8*) GetString(STR_GLOBAL_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wps_error_handler
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_wps_error_handler(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(error_code)
	{
		case WPS_ERROR_INVALID_PARAM://3
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INVALID_PARAM),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WPS_ERROR_INVALID_CHANNEL_ID://5
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INVAL_CHANNEL_ID),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WPS_ERROR_INVALID_REQUEST_ID://6
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INVAL_REQUEST_ID),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WPS_ERROR_INVALID_SEQUENCE_NUM://7
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_INVAL_SEQUENCE_NUM),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WPS_ERROR_ACCESS_DENY://12
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_ACCESS_DENIED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WPS_ERROR_REQ_ABORT://15
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_REQUEST_ABORTED),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		case WPS_ERROR_NOT_FOUND://16
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_NOT_FOUND),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
		default:
		{
			DisplayPopup(
				(U8*) GetString(STR_GLOBAL_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			break;
		}
	}
}

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSEREVENTHANDLER_C */ 


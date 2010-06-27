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
 * JProfileUIHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the profile handler
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

#define __NEWSIMULATOR

#include "MMI_include.h"




#include "custom_nvram_editor_data_item.h"

#include "Nvram_enums.h"

// #include "UnicodeStrgprot.h"
#include "provisioning.h"
//#include "ProfileHandlerTypes.h"
#include "ProfileHandlerResDef.h"
#include "ProfileHandlerProts.h"
#include "BrowserBookmarks.h"
#include "BrowserGprots.h"
//#include "DataAccountDef.h"
//#include "DMTypeDef.h"
#include "ProtocolEvents.h"
#undef __NEWSIMULATOR

#ifdef __MMI_BROWSER_2__

/**** temporay proxy and application node structure *****/

prov_proxy_content_struct *proxy_list[MAX_PROFILE_COUNT] = {NULL, NULL, NULL, NULL, NULL};
prov_application_content_struct *app_list[MAX_PROFILE_COUNT] = {NULL, NULL, NULL, NULL, NULL};

/***** final profile list structure ****/
prov_profile_context_struct *profile_list[MAX_PROFILE_COUNT] = {NULL, NULL, NULL, NULL, NULL};


static U8 g_proxy_index_arr[MAX_PROFILE_COUNT] = {0};

static S16 g_cntx_proxy_index;
static S16 g_cntx_application_index;
static S16 g_port_flag, g_proxy_flag;
static S16 g_startpage_priority_first;
static S16 g_bookmark_count;
static S16 g_profile_index = 0, g_prof_index = 0;
static U8 g_prov_type;
static pBOOL g_bookmark_flag = FALSE;
mmi_cca_app_configure_ind_struct *config_doc = NULL;

extern S32 utf8_strlen(const U8 *s);
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);
extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

/* extern U16 UTF8Strlen(PU8 p); */
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_init(void)
{
#ifdef SYNCML_DM_SUPPORT
	mmi_dm_set_check_function(DM_SETTING_TYPE_WAP, browser_check_func);
#ifdef MMS_SUPPORT
	mmi_dm_set_check_function(DM_SETTING_TYPE_MMS, mms_check_func);
#endif
#endif
}
#ifdef SYNCML_DM_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  browser_check_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
bf_bool browser_check_func(void)
{
	if (IsScreenPresent(SCR_ID_PROV_INFO_DISPLAY) || GetActiveScreenId() == SCR_ID_PROV_INFO_DISPLAY ||
		IsScreenPresent(SCR_ID_PROF_HDLR_PROF_LIST) || GetActiveScreenId() == SCR_ID_PROF_HDLR_PROF_LIST ||
		IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN) || GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
	{
		return FALSE;
	}
	return TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mms_check_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
bf_bool mms_check_func(void)
{
	if (IsScreenPresent(SCR_ID_PROV_INFO_DISPLAY) || GetActiveScreenId() == SCR_ID_PROV_INFO_DISPLAY ||
	IsScreenPresent(SCR_ID_PROF_HDLR_PROF_LIST) || GetActiveScreenId() == SCR_ID_PROF_HDLR_PROF_LIST ||
	IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN) || GetActiveScreenId() == SCR_ID_BRW_BROWSER_MAIN)
	{
		return FALSE;
	}
	return TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_app_update_prof_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_dm_app_update_prof_ind(void *msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_update_prof_ind_struct *data;
    prof_profile_enum profile_type = BRW_PROF_BROWSER_PROFILE;
    S32 profile_count = 0;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_update_prof_ind_struct*)msg;

	if ((data->prof_id < 0 && data->prof_id != -1) ||  data->prof_id > NVRAM_PROFILE_MAX-1)
	{
#ifdef __MMI_DUAL_SIM__
		mmi_cca_send_cca_app_update_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, data->prof_id, data->hConfig, CCA_STATUS_FAIL);
#else
		mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_FAIL);
#endif
		return;
	}

	if (data->app_id != CCA_APP_BROWSER && data->app_id != CCA_APP_MMS)
	{
#ifdef __MMI_DUAL_SIM__
		mmi_cca_send_cca_app_update_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, data->prof_id, data->hConfig, CCA_STATUS_INVALID_SETTING);
#else
		mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_INVALID_SETTING);
#endif	
		return;
	}
	else
	{
		if (data->app_id == CCA_APP_BROWSER)
		{
			mmi_brw_prof_get_brw_profile_name_list();
			profile_type = BRW_PROF_BROWSER_PROFILE;
		}
		else if (data->app_id == CCA_APP_MMS)
		{
			mmi_brw_prof_get_mms_profile_name_list();
			profile_type = BRW_PROF_MMS_PROFILE;
		}
	}
	while (g_prof_name_arr_p[profile_type]->nvram_profile_name_array[profile_count].profile_name[0] != '\0' 
		  && profile_count < NVRAM_PROFILE_MAX)
	{
		profile_count++;
	}

	if (data->prof_id == -1) // if activated profile content needs to be updated.
	{
		for (i = 0; i < NVRAM_PROFILE_MAX && 
			g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].profile_name[0] != '\0'; i++)
		{
			if (g_prof_cntx.actived_profile_content_index[profile_type] == 
				g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].content_index)
			{
				data->prof_id = i;
				break;
			}
		}
	}

	if (data->prof_id >=0 && data->prof_id <= NVRAM_PROFILE_MAX-1)
	{
		/*if (g_prof_name_arr_p[profile_type]->nvram_profile_name_array[data->prof_id].content_index != 
			g_prof_cntx.actived_profile_content_index[profile_type])
		{*/
			if (data->prof_id < profile_count)
			{
#ifdef __MMI_DUAL_SIM__
				mmi_cca_send_cca_app_update_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, data->prof_id, data->hConfig,
				mmi_prov_dm_brw_update_profile(data->hConfig,data->prof_id,profile_count,profile_type));
#else	
				mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig,
					mmi_prov_dm_brw_update_profile(data->hConfig,data->prof_id,profile_count,profile_type));
#endif
				return;	
			}
			else
			{
#ifdef __MMI_DUAL_SIM__
				mmi_cca_send_cca_app_update_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, profile_count, data->hConfig,
				mmi_prov_dm_brw_update_profile(data->hConfig,data->prof_id,profile_count,profile_type));
#else				
				mmi_cca_send_cca_app_update_prof_rsp(data->app_id, profile_count, data->hConfig,
					mmi_prov_dm_brw_update_profile(data->hConfig,data->prof_id,profile_count,profile_type));
#endif	
				return;
			}
		//}

	}
	/*	if (data->app_id == CCA_APP_BROWSER)
		{
			mmi_brw_prof_get_brw_profile_name_list();
			profile_type = BRW_PROF_BROWSER_PROFILE;
		}
		else if (data->app_id == CCA_APP_MMS)
		{
			mmi_brw_prof_get_mms_profile_name_list();
			profile_type = BRW_PROF_MMS_PROFILE;
		}
		for (i = 0; i < NVRAM_PROFILE_MAX && 
			g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].profile_name != '\0'; i++)
		{
			if (data->prof_id == g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].content_index)
			{
				id_matched = TRUE;
				break;
			}
		}
	}*/

/*	if (id_matched == TRUE)
	{
		if (mmi_prov_dm_brw_update_profile(data->hConfig,i,profile_type)== TRUE)
		{
			mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_OK);
		}
		else
		{
			mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_INVALID_SETTING);
		}
	}
	else
	{
		mmi_cca_send_cca_app_update_prof_rsp(data->app_id, data->prof_id, data->hConfig, CCA_STATUS_INVALID_SETTING);
	}*/

}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_app_recv_prof_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_dm_app_recv_prof_ind(void *msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_ind_struct *data;
	nvram_profile_content_struct *profile_content = NULL;
	prof_profile_enum profile_type;
	cca_state_enum status = CCA_STATUS_OK;
	S32 hconfig = -1;
	S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_get_prof_ind_struct*)msg;

	if (data->app_id == CCA_APP_BROWSER)
	{
		mmi_brw_prof_get_brw_profile_name_list();
		profile_type = BRW_PROF_BROWSER_PROFILE;
	}
	else
	{
		mmi_brw_prof_get_mms_profile_name_list();
		profile_type = BRW_PROF_MMS_PROFILE;
	}

	if (data->prof_id >=0 && data->prof_id <= NVRAM_PROFILE_MAX-1) // if profile id exist in the range
	{
		/*for (i = 0; i < NVRAM_PROFILE_MAX && 
			g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].profile_name != '\0'; i++)
		{
			if (data->prof_id == g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].content_index)
			{
				id_matched = TRUE;
				break;
			}
		}*/
		if (g_prof_name_arr_p[profile_type]->nvram_profile_name_array[data->prof_id].profile_name[0] != '\0')
		{
			status = CCA_STATUS_OK;
			profile_content = mmi_prof_get_content(profile_type,
				(U16)g_prof_name_arr_p[profile_type]->nvram_profile_name_array[data->prof_id].content_index);
		}
		else // if profile id exist in the range but profile doesn't exist at this id then send default profile
		{
			status = CCA_STATUS_NOT_FOUND;
			profile_content = mmi_prov_dm_create_default_profile(profile_type);
		}
	}
	else if (data->prof_id == -1) // send currently activated profile
	{
		profile_content = mmi_prof_get_content(profile_type,(U16)g_prof_cntx.actived_profile_content_index[profile_type]);
		
		for (i = 0; i < NVRAM_PROFILE_MAX && 
			g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].profile_name[0] != '\0'; i++)
		{
			if (g_prof_cntx.actived_profile_content_index[profile_type] == 
				g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].content_index)
			{
				data->prof_id = i;
				status = CCA_STATUS_OK;
				break;
			}
		}
	}
	else if ((data->prof_id < 0 && data->prof_id != -1) ||  data->prof_id > NVRAM_PROFILE_MAX-1) // out of range
	{
		profile_content = mmi_prov_dm_create_default_profile(profile_type);
		status = CCA_STATUS_OUT_OF_RANGE;
	}
	
	if (profile_content == NULL)
	{
		hconfig = -1;
#ifdef __MMI_DUAL_SIM__
		mmi_cca_send_cca_app_get_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, data->prof_id, hconfig, CCA_STATUS_MEMFULL);
#else
		mmi_cca_send_cca_app_get_prof_rsp(data->app_id, data->prof_id,hconfig, CCA_STATUS_MEMFULL);
#endif
		return;
	}

	if (profile_type == BRW_PROF_BROWSER_PROFILE)
	{
		hconfig = mmi_prov_dm_browser_construct_doc(profile_content,data->prof_id,status);
	}
	else if (profile_type == BRW_PROF_MMS_PROFILE)
	{
		hconfig = mmi_prov_dm_mms_construct_doc(profile_content,data->prof_id,status);
	}

	if (hconfig != -1)
	{
#ifdef __MMI_DUAL_SIM__
		mmi_cca_send_cca_app_get_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, data->prof_id, hconfig, status);
#else
		mmi_cca_send_cca_app_get_prof_rsp(data->app_id, data->prof_id,hconfig, status);
#endif
	}
	else
	{
#ifdef __MMI_DUAL_SIM__
		mmi_cca_send_cca_app_get_prof_rsp(MMI_CCA_SIM_ID_DEFAULT, data->app_id, data->prof_id, hconfig, CCA_STATUS_MEMFULL);
#else
		mmi_cca_send_cca_app_get_prof_rsp(data->app_id, data->prof_id,hconfig, CCA_STATUS_MEMFULL);
#endif
	}
	OslMfree(profile_content);
	profile_content = NULL;
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_construct_doc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg  
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_prov_dm_browser_construct_doc(nvram_profile_content_struct *profile_content,S32 prof_index, 
									  cca_state_enum status)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	S32 hConfig, hRoot, hNode, hProxy;
	S8 ip_address[16] = {'\0'};
	S8 proxy_port_str[5] = {'\0'};

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	sprintf(ip_address,"%d.%d.%d.%d",profile_content->proxy_ip[0],
			profile_content->proxy_ip[1],profile_content->proxy_ip[2],profile_content->proxy_ip[3]);

	sprintf(proxy_port_str,"%d",profile_content->proxy_port);

	hRoot = mmi_cca_doc_new_rootnode();
	if (!hRoot)
	{
		return -1;
	}

	hProxy = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PROXY, hRoot);
	if (!hProxy)
	{
		mmi_cca_docroot_release(hRoot); 
		return -1;
	}

	mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_NODEID, "PROXY_1");
	mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_PROXY_ID, "PROXY_1");

	if (status == CCA_STATUS_NOT_FOUND || status == CCA_STATUS_OUT_OF_RANGE)
	{
		mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_NAME,"Default Profile");
	}
	else
	{
		mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_NAME, 
			(S8*) g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE]->nvram_profile_name_array[prof_index].profile_name);
	}
	mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_PXADDR, ip_address);
	mmi_cca_doc_add_nodedata_int (hProxy, CCA_NS_DATAACCTID, profile_content->data_account_primary_id);
	
	if (profile_content->data_account_secondary_id != -1)
	{
		mmi_cca_doc_add_nodedata_int (hProxy, CCA_NS_DATAACCTID, profile_content->data_account_secondary_id);
	}

	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PXAUTHINFO, hProxy);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_PXAUTH_ID, (S8*)profile_content->username);
	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_PXAUTH_PW, (S8*)profile_content->password);

	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PORT, hProxy);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_PORTNBR, proxy_port_str);
//	mmi_cca_doc_add_nodedata_int (hNode, CCA_NS_OMA_SERVICE, profile_content->conn_type);
	mmi_cca_doc_add_nodedata_int (hNode, CCA_NS_OMA_SERVICE, 
        mmi_prov_dm_get_conn_type(profile_content->conn_type,profile_content->proxy_port));

	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPLICATION, hRoot);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_APPID, "w2");
	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_TO_PROXY, "PROXY_1");

	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, hNode);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_URI, (S8*)profile_content->url);
	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_STARTPAGE, "");


	hConfig = mmi_cca_doc_new (hRoot);

	return hConfig;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_mms_construct_doc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg  
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_prov_dm_mms_construct_doc(nvram_profile_content_struct *profile_content,S32 prof_index,
								  cca_state_enum status)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	S32 hConfig, hRoot, hNode, hProxy;
	S8 ip_address[16] = {'\0'};
	S8 proxy_port_str[5] = {'\0'};

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	sprintf(ip_address,"%d.%d.%d.%d",profile_content->proxy_ip[0],
			profile_content->proxy_ip[1],profile_content->proxy_ip[2],profile_content->proxy_ip[3]);

	sprintf(proxy_port_str,"%d",profile_content->proxy_port);

	hRoot = mmi_cca_doc_new_rootnode();
	if (!hRoot)
	{
		return -1;
	}

	hProxy = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PROXY, hRoot);
	if (!hProxy)
	{
		mmi_cca_docroot_release(hRoot); 
		return -1;
	}

	mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_NODEID, "PROXY_1");
	mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_PROXY_ID, "PROXY_1");

	if (status == CCA_STATUS_NOT_FOUND || status == CCA_STATUS_OUT_OF_RANGE)
	{
		mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_NAME,"Default Profile");
	}
	else
	{
		mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_NAME, 
			(S8*)g_prof_name_arr_p[BRW_PROF_MMS_PROFILE]->nvram_profile_name_array[prof_index].profile_name);
	}
	mmi_cca_doc_add_nodedata_str (hProxy, CCA_NS_OMA_PXADDR, ip_address);
	mmi_cca_doc_add_nodedata_int (hProxy, CCA_NS_DATAACCTID, profile_content->data_account_primary_id);
	
	if (profile_content->data_account_secondary_id != -1)
	{
		mmi_cca_doc_add_nodedata_int (hProxy, CCA_NS_DATAACCTID, profile_content->data_account_secondary_id);
	}

	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PXAUTHINFO, hProxy);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_PXAUTH_ID, (S8*)profile_content->username);
	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_PXAUTH_PW, (S8*)profile_content->password);

	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PORT, hProxy);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_PORTNBR, proxy_port_str);
	//mmi_cca_doc_add_nodedata_int (hNode, CCA_NS_OMA_SERVICE, profile_content->conn_type);

	mmi_cca_doc_add_nodedata_int (hNode, CCA_NS_OMA_SERVICE, 
								mmi_prov_dm_get_conn_type(profile_content->conn_type,profile_content->proxy_port));


	hNode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPLICATION, hRoot);

	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_APPID, "w4");
	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_TO_PROXY, "PROXY_1");
	mmi_cca_doc_add_nodedata_str (hNode, CCA_NS_OMA_ADDR, (S8*)profile_content->url);


	hConfig = mmi_cca_doc_new (hRoot);

	return hConfig;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_dm_get_conn_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  newConfigDoc        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
cca_oma_values_enum mmi_prov_dm_get_conn_type(prof_conn_type_enum conn_type, U16 port_parm)
{
	if (conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED)
	{
		switch(port_parm)
		{
			case 9200:
						return CCA_NS_VAL_CL_WSP;
			case 9201:
			default: 
						return CCA_NS_VAL_CO_WSP;
		}
	}
	else if (conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE)
	{
		switch(port_parm)
		{
			case 9202:
						return CCA_NS_VAL_CL_SEC_WSP;
			case 9203:
			default: 
						return CCA_NS_VAL_CO_SEC_WSP;
		}
	}
	else if (conn_type == BRW_PROF_CONN_TYPE_HTTP)
	{
		switch(port_parm)
		{
			case 443:
						return CCA_NS_VAL_OTA_HTTP_TLS_TO;
			case 80:
			default: 
						return CCA_NS_VAL_OTA_HTTP_TO;
		}
	}
	return CCA_STATUS_FAIL;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_cca_new_doc
 * DESCRIPTION
 *  It gets the new document from CCA and sends back the hconfig to get
 the nodes or data in the document.
 * PARAMETERS
 *  newConfigDoc        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_cca_new_doc(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 config_doc = (mmi_cca_app_configure_ind_struct *)OslMalloc(sizeof(mmi_cca_app_configure_ind_struct));
	 if (config_doc == NULL)
	 {
		 MMI_ASSERT(0);
	 }
	 config_doc->config_id = newConfigDoc->config_id;
    config_doc->hConfig = newConfigDoc->hConfig;
    g_cntx_proxy_index = -1;
    g_cntx_application_index = -1;
    mmi_prov_browser_profile_handle_configuration_document(newConfigDoc->hConfig);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_mms_cca_new_doc
 * DESCRIPTION
 *   It gets the new document from CCA and sends back the hconfig to get
 the nodes or data in the document.
 * PARAMETERS
 *  newConfigDoc        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_mms_cca_new_doc(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    config_doc = (mmi_cca_app_configure_ind_struct *)OslMalloc(sizeof(mmi_cca_app_configure_ind_struct));
	 if (config_doc == NULL)
	 {
		 MMI_ASSERT(0);
	 }
	 config_doc->config_id = newConfigDoc->config_id;
    config_doc->hConfig = newConfigDoc->hConfig;

    g_cntx_proxy_index = -1;
    g_cntx_application_index = -1;
    mmi_prov_mms_profile_handle_configuration_document(newConfigDoc->hConfig);
}


/*****************************************************************************
 * FUNCTION
 *  check_merge
 * DESCRIPTION
 *  This is a dummy code to check whether merge is working properly or not.Its not being
 used.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void check_merge(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_type = BRW_PROV_BROWSER_ONLY;
    mmi_prov_merge_proxy_application_node_list();
    mmi_prov_commit_setting();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_dm_brw_update_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hConfig  i   [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
cca_state_enum mmi_prov_dm_brw_update_profile(S32 hConfig, S32 index, S32 profile_count, prof_profile_enum profile_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 nvram_profile_content_struct *profile_content = NULL;
	 cca_state_enum status = CCA_STATUS_OK;
	 S8 content_index_arr[NVRAM_PROFILE_MAX] ={0}, i=0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	 for (i = 0; i < profile_count; i++)
	 {
		content_index_arr[g_prof_name_arr_p[profile_type]->nvram_profile_name_array[i].content_index] = 1;
	 }
	 g_cntx_proxy_index = -1;
	 g_cntx_application_index = -1;
	 if (profile_type == BRW_PROF_BROWSER_PROFILE)
	 {
		status = mmi_cca_doc_process(
			hConfig,
			cca_mapping_browser,
			sizeof(cca_mapping_browser) / sizeof(U16),
			0,
			mmi_prov_browser_process_callback_nodes,
			0); 
	 }
	 else if (profile_type == BRW_PROF_MMS_PROFILE)
	 {
		 status = mmi_cca_doc_process(
            hConfig,
            cca_mapping_mms,
            sizeof(cca_mapping_mms) / sizeof(U16),
            0,
            mmi_prov_mms_process_callback_nodes,
            0);
	 }
	 if (status == CCA_STATUS_OK)
     {
        mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();

        if (mmi_prov_validate_setting() == VALIDATION_SUCCESS)
        {
			profile_content = (nvram_profile_content_struct *)OslMalloc(sizeof(nvram_profile_content_struct));

			if (profile_content == NULL)
			{
				return CCA_STATUS_MEMFULL;
			}

			if (index >= profile_count)
			{
				index = profile_count;
				i = 0;
				while (content_index_arr[i] != 0 && i < NVRAM_PROFILE_MAX)
				{
					i++;
				}
				g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].content_index = i;
			}

			if (profile_list[0]->dcs == BRW_PROF_DCS_ASCII)
			{
				strcpy(
					(S8*) g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].profile_name,
					(S8*) profile_list[0]->name);
				g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].dcs = BRW_PROF_DCS_ASCII;
			}
			else if (profile_list[0]->dcs == BRW_PROF_DCS_UCS)
			{
				mmi_ucs2cpy((S8*) g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].profile_name, 
							(S8*) profile_list[0]->name);
				g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].dcs = BRW_PROF_DCS_UCS;
			}

			strcpy((S8*) profile_content->url, (S8*) profile_list[0]->url);

			strcpy((S8*) profile_content->username, (S8*) profile_list[0]->username);

			strcpy((S8*) profile_content->password, (S8*) profile_list[0]->password);

			profile_content->data_account_primary_id = profile_list[0]->primary_dataacc_id;
			profile_content->data_account_secondary_id = profile_list[0]->secondary_dataacc_id;

			if (profile_list[0]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED ||
				profile_list[0]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE ||
				profile_list[0]->conn_type == BRW_PROF_CONN_TYPE_HTTP)
			{
				profile_content->conn_type = profile_list[0]->conn_type;
				profile_content->proxy_port = profile_list[0]->proxy_port;
			}
			else
			{
				profile_content->conn_type = BRW_PROF_CONN_TYPE_HTTP;
				profile_content->proxy_port = 80;
			}
			profile_content->proxy_ip[0] = profile_list[0]->proxy_ip[0];
			profile_content->proxy_ip[1] = profile_list[0]->proxy_ip[1];
			profile_content->proxy_ip[2] = profile_list[0]->proxy_ip[2];
			profile_content->proxy_ip[3] = profile_list[0]->proxy_ip[3];

			mmi_brw_dm_prov_update_profile(profile_content,index, profile_type);

			if (index == g_prof_cntx.actived_profile_content_index[profile_type])
			{
				if (profile_type == BRW_PROF_BROWSER_PROFILE)
				{
					mmi_brw_active_profile_changed_without_ui();
				}
				else if (profile_type == BRW_PROF_MMS_PROFILE)
				{
					mmi_umms_set_current_mms_profile(TRUE);
				}
			}

			i = 0;
			while (profile_list[i] !=  NULL)
			{
				OslMfree(profile_list[i]);
				profile_list[i] = NULL;
				i++;
			}
			g_profile_index = 0;
			OslMfree(profile_content);
			profile_content = NULL;
			return CCA_STATUS_OK;
		}
		return CCA_STATUS_FAIL;
	 }
	 return CCA_STATUS_FAIL;   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_profile_handle_configuration_document
 * DESCRIPTION
 *  Send the hconfig,mapping table and a callback to CCA ,to get the data from the doc .
	This is for browser only.
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_profile_handle_configuration_document(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cca_doc_process(
            hConfig,
            cca_mapping_browser,
            sizeof(cca_mapping_browser) / sizeof(U16),
            0,
            mmi_prov_browser_process_callback_nodes,
            0) == CCA_STATUS_OK)
    {
        g_prov_type = BRW_PROV_BROWSER_ONLY;
        mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();
        if (mmi_prov_validate_setting() == VALIDATION_SUCCESS)
        {
            DataAccountReadyCheck(mmi_prov_commit_setting);
        }
        else
        {
            mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
        }

    }
    else
    {
        mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_mms_profile_handle_configuration_document
 * DESCRIPTION
 *  Send the hconfig,mapping table and a callback to CCA ,to get the data from the doc .
	This is for MMS only.
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_mms_profile_handle_configuration_document(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cca_doc_process(
            hConfig,
            cca_mapping_mms,
            sizeof(cca_mapping_mms) / sizeof(U16),
            0,
            mmi_prov_mms_process_callback_nodes,
            0) == CCA_STATUS_OK)
    {
        g_prov_type = BRW_PROV_MMS_ONLY;
        mmi_prov_merge_proxy_application_node_list();
        mmi_prov_free_proxy_app_nodes();

        if (mmi_prov_validate_setting() == VALIDATION_SUCCESS)
        {
            DataAccountReadyCheck(mmi_prov_commit_setting);
        }
        else
        {
            mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
        }
    }
    else
    {
        mmi_prov_send_response(CCA_STATUS_INVALID_SETTING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_process_callback_nodes
 * DESCRIPTION
 *  Callback function called by CCA as per the node like (proxy,port ,apllication & bookmark)
	being triggered.Used only for browser.
 * PARAMETERS
 *  hConfig             [IN]        
 *  hNode               [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [IN]         
 *  user_data           [IN]         
 * RETURNS
 *  
 *****************************************************************************/
cca_status_enum mmi_prov_browser_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    S32 service_parm = 0, px_addrtype = -1;
    S8 *portnbr_parm = NULL, i = 0;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case BRW_PROV_BROWSER_PROXY:

            g_port_flag = 0;
            g_proxy_flag = 0;
            status = mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_PXADDRTYPE, &px_addrtype);

            if (status == CCA_STATUS_NOT_FOUND)
            {
                px_addrtype = CCA_NS_VAL_IPV4;
            }
            else if (px_addrtype != CCA_NS_VAL_IPV4)
            {
                if (px_addrtype == CCA_NS_VAL__INVALID || px_addrtype == CCA_NS_VAL__EMPTY)
                {
                    px_addrtype = CCA_NS_VAL_IPV4;
                }
                else
                {
                    return CCA_STATUS_INVALID_SETTING;
                }
            }

            /* if(status==CCA_STATUS_OK && px_addrtype == CCA_NS_VAL_IPV4)
               { */
            g_proxy_flag = 1;
            if (proxy_list[++g_cntx_proxy_index] == NULL)
            {
                proxy_list[g_cntx_proxy_index] =
                    (prov_proxy_content_struct*) OslMalloc(sizeof(prov_proxy_content_struct));
            }
            memset(proxy_list[g_cntx_proxy_index]->px_id, '\0', PROV_PROXY_ID_LEN);
            memset(proxy_list[g_cntx_proxy_index]->px_name, '\0', (NVRAM_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH);
            memset(proxy_list[g_cntx_proxy_index]->px_startpage, '\0', NVRAM_PROFILE_URL_LEN);
            memset(proxy_list[g_cntx_proxy_index]->px_authid, '\0', NVRAM_PROFILE_USERNAME_LEN);
            memset(proxy_list[g_cntx_proxy_index]->px_authpw, '\0', NVRAM_PROFILE_PASSWORD_LEN);

				proxy_list[g_cntx_proxy_index]->px_service = BRW_PROF_CONN_TYPE_HTTP;
            proxy_list[g_cntx_proxy_index]->px_port = 0;
            
            mmi_cca_iterator_restart(iter_datalist);

            while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
            {
                mmi_prov_browser_handle_proxy_params(proxy_list[g_cntx_proxy_index], data);
            }
            /* } */
            break;

        case BRW_PROV_BROWSER_PORT:
            if (g_proxy_flag == 1)
            {
                mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_SERVICE, &service_parm);
                if ((service_parm != CCA_NS_VAL_CO_SEC_WTA || service_parm != CCA_NS_VAL_CL_SEC_WTA) &&
                    g_port_flag == 0)
                {
                    mmi_cca_doc_get_nodedata_str_first(iter_datalist, CCA_NS_OMA_PORTNBR, &portnbr_parm);

                    mmi_prov_browser_handle_service_params(proxy_list[g_cntx_proxy_index], service_parm, portnbr_parm);

                    g_port_flag = 1;
                }
            }
            break;

        case BRW_PROV_BROWSER_AUTHINFO:
            if (g_proxy_flag == 1)
            {
                while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
                {
                    mmi_prov_browser_handle_proxy_params(proxy_list[g_cntx_proxy_index], data);
                }
            }
            break;

        case BRW_PROV_BROWSER_APP:

            g_startpage_priority_first = 0;
			g_bookmark_count = -1;
			g_bookmark_flag = FALSE;

            if (app_list[++g_cntx_application_index] == NULL)
            {
                app_list[g_cntx_application_index] =
                    (prov_application_content_struct*) OslMalloc(sizeof(prov_application_content_struct));
            }
			app_list[g_cntx_application_index]->bookmark_count = -1;

            memset(
                app_list[g_cntx_application_index]->app_name,
                '\0',
                sizeof(app_list[g_cntx_application_index]->app_name));
            memset(
                app_list[g_cntx_application_index]->app_url,
                '\0',
                sizeof(app_list[g_cntx_application_index]->app_url));

            for (i = 0; i < MAX_PROFILE_COUNT; i++)
            {
                app_list[g_cntx_application_index]->app_to_proxy[i] = NULL;
            }
	    for (i = 0; i < MAX_BOOKMARK_COUNT; i++)
            {
                app_list[g_cntx_application_index]->bookmark[i] = NULL;
            }
            while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
            {
                mmi_prov_browser_handle_application_params(app_list[g_cntx_application_index], data);
            }
            break;
        case BRW_PROV_BROWSER_RESOURCE:
			if (g_bookmark_count <= MAX_BOOKMARK_COUNT)
			{
				g_bookmark_count++;
				app_list[g_cntx_application_index]->bookmark[g_bookmark_count]
					= (prov_bookmark_struct*)OslMalloc(sizeof(prov_bookmark_struct));

				memset(
					 (S8*) app_list[g_cntx_application_index]->bookmark[g_bookmark_count]->bm_title,
					 '\0',
					 MAX_BOOKMARK_TITLE_LEN*ENCODING_LENGTH); 

				memset(
					(S8*) app_list[g_cntx_application_index]->bookmark[g_bookmark_count]->bm_url,
					'\0',
					MAX_BOOKMARK_URL_LEN);

            while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
            {
					mmi_prov_browser_handle_resource_params(app_list[g_cntx_application_index], data);
				}
				if (g_bookmark_count != -1)
				{
					if (app_list[g_cntx_application_index]->bookmark[g_bookmark_count]->bm_url[0] == '\0')
					{
						OslMfree(app_list[g_cntx_application_index]->bookmark[g_bookmark_count]);
						app_list[g_cntx_application_index]->bookmark[g_bookmark_count] = NULL;
						g_bookmark_count--;
					}
				}
				g_startpage_priority_first = 0;
				app_list[g_cntx_application_index]->bookmark_count = g_bookmark_count;
            }
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_mms_process_callback_nodes
 * DESCRIPTION
 *  Callback function called by CCA as per the node like (proxy,port ,apllication & bookmark)
	being triggered.Used only for MMS.
 * PARAMETERS
 *  hConfig             [IN]        
 *  hNode               [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [?]         
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
cca_status_enum mmi_prov_mms_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    S32 service_parm = 0, px_addrtype = -1;
    S8 *portnbr_parm = NULL, i = 0, j= 0;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case BRW_PROV_MMS_PROXY:

            g_port_flag = 0;
            g_proxy_flag = 0;
            status = mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_PXADDRTYPE, &px_addrtype);

            if (status == CCA_STATUS_NOT_FOUND)
            {
                px_addrtype = CCA_NS_VAL_IPV4;
            }
            else if (px_addrtype != CCA_NS_VAL_IPV4)
            {
                if (px_addrtype == CCA_NS_VAL__INVALID || px_addrtype == CCA_NS_VAL__EMPTY)
                {
                    px_addrtype = CCA_NS_VAL_IPV4;
                }
                else
                {
                    return CCA_STATUS_INVALID_SETTING;
                }
            }

            /* if(status==CCA_STATUS_OK && px_addrtype == CCA_NS_VAL_IPV4)
               { */
            g_proxy_flag = 1;
            if (proxy_list[++g_cntx_proxy_index] == NULL)
            {
                proxy_list[g_cntx_proxy_index] =
                    (prov_proxy_content_struct*) OslMalloc(sizeof(prov_proxy_content_struct));
            }
            memset(proxy_list[g_cntx_proxy_index]->px_id, '\0', PROV_PROXY_ID_LEN);
            memset(proxy_list[g_cntx_proxy_index]->px_name, '\0', (NVRAM_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH);
            memset(proxy_list[g_cntx_proxy_index]->px_startpage, '\0', NVRAM_PROFILE_URL_LEN);
            memset(proxy_list[g_cntx_proxy_index]->px_authid, '\0', NVRAM_PROFILE_USERNAME_LEN);
            memset(proxy_list[g_cntx_proxy_index]->px_authpw, '\0', NVRAM_PROFILE_PASSWORD_LEN);

				proxy_list[g_cntx_proxy_index]->px_service = BRW_PROF_CONN_TYPE_HTTP;
            proxy_list[g_cntx_proxy_index]->px_port = 0;

            mmi_cca_iterator_restart(iter_datalist);

            while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
            {
                mmi_prov_browser_handle_proxy_params(proxy_list[g_cntx_proxy_index], data);
            }
            /* } */
            break;

        case BRW_PROV_MMS_PORT:
            if (g_proxy_flag == 1)
            {
                mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_SERVICE, &service_parm);
                if ((service_parm != CCA_NS_VAL_CO_SEC_WTA || service_parm != CCA_NS_VAL_CL_SEC_WTA) &&
                    g_port_flag == 0)
                {
                    mmi_cca_doc_get_nodedata_str_first(iter_datalist, CCA_NS_OMA_PORTNBR, &portnbr_parm);

                    mmi_prov_browser_handle_service_params(proxy_list[g_cntx_proxy_index], service_parm, portnbr_parm);

                    g_port_flag = 1;
                }
            }
            break;

        case BRW_PROV_MMS_AUTHINFO:
            if (g_proxy_flag == 1)
            {
                while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
                {
                    mmi_prov_browser_handle_proxy_params(proxy_list[g_cntx_proxy_index], data);
                }
            }
            break;

        case BRW_PROV_MMS_APP:

            g_startpage_priority_first = 0;
				g_bookmark_count = -1;
			   g_bookmark_flag = FALSE;

            if (app_list[++g_cntx_application_index] == NULL)
            {
                app_list[g_cntx_application_index] =
                    (prov_application_content_struct*) OslMalloc(sizeof(prov_application_content_struct));
            }
			   app_list[g_cntx_application_index]->bookmark_count = -1;

            memset(
                app_list[g_cntx_application_index]->app_name,
                '\0',
                sizeof(app_list[g_cntx_application_index]->app_name));
            memset(
                app_list[g_cntx_application_index]->app_url,
                '\0',
                sizeof(app_list[g_cntx_application_index]->app_url));

            for (i = 0; i < MAX_PROFILE_COUNT; i++)
            {
                app_list[g_cntx_application_index]->app_to_proxy[i] = NULL;
            }
			for (i = 0; i < MAX_BOOKMARK_COUNT; i++)
            {
                app_list[g_cntx_application_index]->bookmark[i] = NULL;
            }
            while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
            {
                mmi_prov_browser_handle_application_params(app_list[g_cntx_application_index], data);
            }

				if (app_list[g_cntx_application_index]->app_url[0] == '\0')
				{
					while (app_list[g_cntx_application_index]->app_to_proxy[j] != NULL && j < MAX_TO_RPOXY)
					{
						OslMfree(app_list[g_cntx_application_index]->app_to_proxy[j]);
						app_list[g_cntx_application_index]->app_to_proxy[j] = NULL;
						j++;
					}
					OslMfree(app_list[g_cntx_application_index]);
					app_list[g_cntx_application_index] = NULL;
					g_cntx_application_index--;
				}

            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_merge_proxy_application_node_list
 * DESCRIPTION
 *	This API creates profile list based on the proxy list and application list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_merge_proxy_application_node_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 proxy_index, app_index, app_to_proxy_index;
    S32 last_proxy_index;
    S8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prov_application_content_struct app_val[2]=
       {
       0 ,"TP1","TP2",NULL,NULL,NULL,"HUTCH.CO.IN","ESSAR",
       0 ,"TP2","TP3",NULL,"","","AIRTEL.CO.IN"
       };
       prov_proxy_content_struct proxy_val[4]=
       {
       1,11,0,"TP1","203.102.11.1",1,2,9200,"ritesh","sinha","","xyz",
       2,12,0,"TP2","201.101.11.1",1,2,9201,"ritesh1","sinha1","abc","xyz",
       3,12,0,"TP3","djgfjf",1,2,9202,"ritesh2","sinha2","abc1","xyz",
       3,12,0,"TP3","202.101.11.1",1,2,9202,"ritesh3","sinha3","abc1",""
       };
       
       app_list[0]=&app_val[0];
       app_list[1]=&app_val[1];
       
       proxy_list[0]=&proxy_val[0];
       proxy_list[1]=&proxy_val[1];
       proxy_list[2]=&proxy_val[2];
       proxy_list[3]=&proxy_val[3]; */

    for (app_index = 0; app_list[app_index] != NULL && app_index < MAX_PROFILE_COUNT &&
         g_profile_index != MAX_PROFILE_COUNT; app_index++)
    {
        app_to_proxy_index = 0;
        proxy_index = 0;
        last_proxy_index = -1;

        while (app_list[app_index]->app_to_proxy[app_to_proxy_index] != NULL && proxy_list[proxy_index] != NULL
               && app_to_proxy_index < MAX_PROFILE_COUNT)
        {
            if (strcmp
                ((S8*) app_list[app_index]->app_to_proxy[app_to_proxy_index],
                 (S8*) proxy_list[proxy_index]->px_id) == 0 && proxy_list[proxy_index]->px_addr != NULL)
            {
                /* g_profile_index++; */
                if (last_proxy_index != proxy_index)
                {
                    mmi_prov_create_profile(app_list[app_index], proxy_list[proxy_index], proxy_index);
                    if (g_profile_index == MAX_PROFILE_COUNT)
                    {
                        break;
                    }
                }
                app_to_proxy_index++;
                last_proxy_index = proxy_index;
                proxy_index = 0;
            }
            else
            {
                if (proxy_index < MAX_PROFILE_COUNT && proxy_list[proxy_index+1] != NULL)
                {
                    proxy_index++;
                }
                else
                {
                    app_to_proxy_index++;
                    proxy_index = 0;
                }
            }
        }
    }

/**** This part is commented now.If we need to create a profile on the basis of proxy without application node then 
we can run this part of code *****/

    /* while( g_profile_index < MAX_PROFILE_COUNT)
       {
       if(mmi_prov_fill_profile_list_by_proxy() == FALSE)
       {
       break;
       }
       } */

    for (i = 0; i < MAX_PROFILE_COUNT; i++)
    {
        g_proxy_index_arr[i] = 0;
    }
    g_cntx_proxy_index = 0;
    g_cntx_application_index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_fill_profile_list_by_proxy
 * DESCRIPTION
 *  This API fills the remaining profile list from the remainging prxoy whose does't have any realtion
	with application "To-Proxy".
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_prov_fill_profile_list_by_proxy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MAX_PROFILE_COUNT)
    {
        if (g_proxy_index_arr[i] != 1)
        {
            break;
        }
        i++;
    }
    if (proxy_list[i] != NULL && proxy_list[i]->px_startpage != NULL)
    {
        g_proxy_index_arr[i] = 1;
        profile_list[g_profile_index] = (prov_profile_context_struct*) OslMalloc(sizeof(prov_profile_context_struct));
        if (proxy_list[i]->px_name[0] != '\0')
        {
            strcpy((S8*) profile_list[g_profile_index]->name, (S8*) proxy_list[i]->px_name);
        }
        else
        {
            strcpy((S8*) profile_list[g_profile_index]->name, (S8*) BRW_PROF_DEFAULT_WAP_PROFILE_NAME);
            profile_list[g_profile_index]->dcs = BRW_PROF_DCS_ASCII;
        }
        if (proxy_list[i]->px_startpage[0] != '\0')
        {
            strcpy((S8*) profile_list[g_profile_index]->url, (S8*) proxy_list[i]->px_startpage);
        }
        else
        {
            strcpy((S8*) profile_list[g_profile_index]->url, (S8*) BRW_PROF_DEFAULT_URL_NAME);
        }
        mmi_prov_fill_other_parm(proxy_list[i]);
        g_profile_index++;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_profile
 * DESCRIPTION
 *  This API creates the profile list.
 * PARAMETERS
 *  app_node        [IN]         
 *  proxy_node      [IN]         
 *  proxy_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_create_profile(
        prov_application_content_struct *app_node,
        prov_proxy_content_struct *proxy_node,
        S16 proxy_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 proxy_ip[4];
    U8 temp_addr[PROV_PX_ADDR_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (proxy_node->px_addr != NULL)
    {
        strncpy((S8*) temp_addr, (S8*) proxy_node->px_addr, PROV_PX_ADDR_LEN - 1);
        if (mmi_prov_convert_proxy_ipstring_to_array(temp_addr, proxy_ip) == PROV_ERR)
        {
            return;
        }
		  else if (proxy_node->px_primary_dataacc_id == proxy_node->px_secondary_dataacc_id)
		  {
			  return;
		  }
        profile_list[g_profile_index] = (prov_profile_context_struct*) OslMalloc(sizeof(prov_profile_context_struct));

    }

    if (profile_list[g_profile_index] != NULL)
    {
        memset(profile_list[g_profile_index]->url, '\0', NVRAM_PROFILE_URL_LEN);
        memset(profile_list[g_profile_index]->name, '\0', (NVRAM_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH);
        memset(profile_list[g_profile_index]->username, '\0', NVRAM_PROFILE_USERNAME_LEN);
        memset(profile_list[g_profile_index]->password, '\0', NVRAM_PROFILE_PASSWORD_LEN);
		  profile_list[g_profile_index]->bookmark_count = 0;
        while (1)
        {
            if (app_node->app_name[0] == '\0' && proxy_node->px_name[0] == '\0')
            {
                if (g_prov_type == BRW_PROV_BROWSER_ONLY)
                {
                    mmi_prov_fill_name_parm((U8*) BRW_PROF_DEFAULT_WAP_PROFILE_NAME, (U8) BRW_PROF_DCS_ASCII);
                }
                else if (g_prov_type == BRW_PROV_MMS_ONLY)
                {
                    mmi_prov_fill_name_parm((U8*) BRW_PROF_DEFAULT_MMS_PROFILE_NAME, (U8) BRW_PROF_DCS_ASCII);
                }
                mmi_prov_fill_url_parm(app_node, proxy_node);
                mmi_prov_fill_other_parm(proxy_node);
				if (app_node->bookmark_count != -1)
				{
					mmi_brw_fill_bookmark_parm(app_node);
				}
                g_profile_index++;
                break;
            }
            else if (app_node->app_name[0] != '\0')
            {
                mmi_prov_fill_name_parm(app_node->app_name, app_node->app_dcs);
                mmi_prov_fill_url_parm(app_node, proxy_node);
                mmi_prov_fill_other_parm(proxy_node);
				if (app_node->bookmark_count != -1)
				{
					mmi_brw_fill_bookmark_parm(app_node);
				}
                g_profile_index++;
                break;
            }
            else if (proxy_node->px_name[0] != '\0')
            {
                mmi_prov_fill_name_parm(proxy_node->px_name, proxy_node->px_dcs);
                mmi_prov_fill_url_parm(app_node, proxy_node);
                mmi_prov_fill_other_parm(proxy_node);
				if (app_node->bookmark_count != -1)
				{
					mmi_brw_fill_bookmark_parm(app_node);
				}
                g_profile_index++;
                break;
            }
        
        }
        g_proxy_index_arr[proxy_index] = 1;
    }
    else
    {
        MMI_ASSERT(0);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_fill_bookmark_parm
 * DESCRIPTION
 *
 * PARAMETERS
 *  name        [IN]         
 *  dcs         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_fill_bookmark_parm(prov_application_content_struct *app_node)
{
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 S16 bm_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (app_node->bookmark_count != -1)
	{
		for (bm_index = 0; bm_index <= app_node->bookmark_count; bm_index++)
		{
			profile_list[g_profile_index]->bookmark[bm_index] = 
				(prov_bookmark_struct*) OslMalloc(sizeof(prov_bookmark_struct));
			
			memset (
				(S8*)profile_list[g_profile_index]->bookmark[bm_index]->bm_title,
				'\0',
				MAX_BOOKMARK_TITLE_LEN*ENCODING_LENGTH);
			memset (
				(S8*)profile_list[g_profile_index]->bookmark[bm_index]->bm_url,
				'\0',
				MAX_BOOKMARK_URL_LEN);

			mmi_ucs2ncpy(
				(S8*) profile_list[g_profile_index]->bookmark[bm_index]->bm_title,
				(S8*) app_node->bookmark[bm_index]->bm_title,
				MAX_BOOKMARK_TITLE_LEN-1);

			strncpy(
				(S8*) profile_list[g_profile_index]->bookmark[bm_index]->bm_url,
				(S8*) app_node->bookmark[bm_index]->bm_url,
				MAX_BOOKMARK_URL_LEN-1);

			OslMfree(app_node->bookmark[bm_index]);

			app_node->bookmark[bm_index] = NULL;
		}
		app_node->bookmark_count = -1;
	}
	profile_list[g_profile_index]->bookmark_count =bm_index;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_fill_name_parm
 * DESCRIPTION
 *  This API gives the name to profile going to be created.
 * PARAMETERS
 *  name        [IN]         
 *  dcs         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_fill_name_parm(U8 *name, U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dcs)
    {
        case BRW_PROF_DCS_ASCII:

            strncpy((S8*) profile_list[g_profile_index]->name, (S8*) name, NVRAM_PROFILE_NAME_LEN);
            profile_list[g_profile_index]->dcs = BRW_PROF_DCS_ASCII;
            break;

        case BRW_PROF_DCS_UCS:

            mmi_ucs2ncpy(
                (S8*) profile_list[g_profile_index]->name,
                (S8*) name,
                NVRAM_PROFILE_NAME_LEN * ENCODING_LENGTH);
            profile_list[g_profile_index]->dcs = BRW_PROF_DCS_UCS;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_fill_url_parm
 * DESCRIPTION
 *  This API fill the URL to profile.
	If Application URL is available then it will have higher priority than proxy node URL.
	If Application URL is not available and proxy URL is available then URL for the profile will be created by proxy URL.
	if Both Proxy and Application node URL is not available,then it will be filled by default URL.
 * PARAMETERS
 *  app_node        [IN]     
 *  proxy_node      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_fill_url_parm(prov_application_content_struct *app_node, prov_proxy_content_struct *proxy_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (app_node->app_url && app_node->app_url[0] != '\0')
        {
            strncpy((S8*) profile_list[g_profile_index]->url, (S8*) app_node->app_url, NVRAM_PROFILE_URL_LEN - 1);
            break;
        }
        else if (proxy_node->px_startpage && proxy_node->px_startpage[0] != '\0')
        {
            strncpy(
                (S8*) profile_list[g_profile_index]->url,
                (S8*) proxy_node->px_startpage,
                NVRAM_PROFILE_URL_LEN - 1);
            break;
        }
        else
        {
            strncpy(
                (S8*) profile_list[g_profile_index]->url,
                (S8*) BRW_PROF_DEFAULT_URL_NAME,
                NVRAM_PROFILE_URL_LEN - 1);
            break;
        }
        /*
         * else if (proxy_node->px_startpage)
         * {
         * if (proxy_node->px_startpage[0] != '\0')
         * {
         * strncpy((S8*) profile_list[g_profile_index]->url,(S8*) proxy_node->px_startpage,NVRAM_PROFILE_URL_LEN-1);
         * }
         * else
         * {
         * strncpy((S8*) profile_list[g_profile_index]->url,(S8*) BRW_PROF_DEFAULT_URL_NAME,NVRAM_PROFILE_URL_LEN-1);
         * }
         * break;
         * 
         * }
         * if (app_node->app_url[0] =='\0' && proxy_node->px_startpage[0] == '\0')
         * {
         * strncpy((S8*) profile_list[g_profile_index]->url,(S8*) BRW_PROF_DEFAULT_URL_NAME,NVRAM_PROFILE_URL_LEN-1);
         * break;
         * }
         * else if (app_node->app_url[0] !='\0')
         * {
         * strncpy((S8*) profile_list[g_profile_index]->url,(S8*) app_node->app_url,NVRAM_PROFILE_URL_LEN-1);
         * break;
         * }
         * else if (proxy_node->px_name[0]!='\0')
         * {
         * if (proxy_node->px_startpage != NULL && proxy_node->px_startpage[0] == '\0')
         * {
         * strncpy((S8*) profile_list[g_profile_index]->url,(S8*) proxy_node->px_startpage,NVRAM_PROFILE_URL_LEN-1);
         * }
         * break;
         * }
         */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_fill_other_parm
 * DESCRIPTION
 *  This API is used to fill Primary data accID ,Secondary data accID,
	connection type,proxt port,Username ,Password and sender's address.
 * PARAMETERS
 *  proxy_node      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_fill_other_parm(prov_proxy_content_struct *proxy_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 temp_addr[PROV_PX_ADDR_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strncpy((S8*) temp_addr, (S8*) proxy_node->px_addr, PROV_PX_ADDR_LEN - 1);

    profile_list[g_profile_index]->primary_dataacc_id = proxy_node->px_primary_dataacc_id;
    profile_list[g_profile_index]->secondary_dataacc_id = proxy_node->px_secondary_dataacc_id;
    profile_list[g_profile_index]->conn_type = proxy_node->px_service;
    profile_list[g_profile_index]->proxy_port = proxy_node->px_port;

    if (proxy_node->px_authid != NULL)
    {
        strncpy(
            (S8*) profile_list[g_profile_index]->username,
            (S8*) proxy_node->px_authid,
            NVRAM_PROFILE_USERNAME_LEN - 1);
    }
    if (proxy_node->px_authpw != NULL)
    {

        strncpy(
            (S8*) profile_list[g_profile_index]->password,
            (S8*) proxy_node->px_authpw,
            NVRAM_PROFILE_USERNAME_LEN - 1);
    }

    /* if (proxy_node->px_addr !=NULL &&
       mmi_prov_convert_proxy_ipstring_to_array(proxy_node->px_addr,profile_list[g_profile_index]->proxy_ip)
       ==PROV_ERR)
       {
       profile_list[g_profile_index]->proxy_ip[0]=0;
       profile_list[g_profile_index]->proxy_ip[1]=0;
       profile_list[g_profile_index]->proxy_ip[2]=0;
       profile_list[g_profile_index]->proxy_ip[3]=0;
       } */

    mmi_prov_convert_proxy_ipstring_to_array(temp_addr, profile_list[g_profile_index]->proxy_ip);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_validate_setting
 * DESCRIPTION
 *  This API validates ,whether profile is created or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
prov_validation_enum mmi_prov_validate_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_profile_index > 0)
    {
        return VALIDATION_SUCCESS;
    }
    else
    {
        return VALIDATION_FAILURE;
    }
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_handle_proxy_params
 * DESCRIPTION
 *  Based on the namespace identifier ,it fill the proxy list.
 * PARAMETERS
 *  proxy_content       [IN]     
 *  data                [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_handle_proxy_params(prov_proxy_content_struct *proxy_content, cca_core_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len_ucs2 = 0;
	 pBOOL primary_dataacc_flag = FALSE;
	 S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            if (data->values.s[0])
            {
                /* memset(proxy_content->px_id,'\0',PROV_PROXY_ID_LEN); */
                strncpy((S8*) proxy_content->px_id, (S8*) data->values.s[0], PROV_PROXY_ID_LEN - 1);
            }
            break;
        case CCA_NS_OMA_NAME:
            if (data->values.s[0])
            {
                if (utf8_strlen((const U8*)data->values.s[0]) == (S32) strlen(data->values.s[0]))
                {
                    /* memset(proxy_content->px_name,'\0',(NVRAM_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH); */
                    strncpy(
                        (S8*) proxy_content->px_name,
                        (S8*) data->values.s[0],
                        (NVRAM_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH - 1);
                    proxy_content->px_dcs = BRW_PROF_DCS_ASCII;
                }
                else
                {
                    len_ucs2 = mmi_charset_utf8_to_ucs2_length_in_bytes((U8*) data->values.s[0]);
                    if (len_ucs2 >= sizeof(proxy_content->px_name))
                    {
                        len_ucs2 = sizeof(proxy_content->px_name);
                    }
                    mmi_chset_utf8_to_ucs2_string(
                        (U8*) proxy_content->px_name,
                        len_ucs2,
                        (U8*) data->values.s[0]);
                    /* mmi_ucs2cpy((S8*) proxy_content->px_name,(S8*) data->values.s[0]); */
                    proxy_content->px_dcs = BRW_PROF_DCS_UCS;
                }
            }
            break;

        case CCA_NS_OMA_PXADDR:
            if (data->values.s[0])
            {
                strcpy((S8*) proxy_content->px_addr, (S8*) data->values.s[0]);
                break;
            }

        case CCA_NS_DATAACCTID:

            if (data->size == 1)
            {
                if(mmi_dtcnt_get_bearer_type((U8)data->values.i[0]) != 0)
					 {
                proxy_content->px_primary_dataacc_id = data->values.i[0];
					 }
					 else
					 {
						proxy_content->px_primary_dataacc_id = (S8) -1;
					 }
                proxy_content->px_secondary_dataacc_id = (S8)-1;
            }
            else if (data->size > 1)
            {
                for (index = 0; index < data->size; index++)
					 {
						if(mmi_dtcnt_get_bearer_type((U8)data->values.i[index]) != 0)
						{
							proxy_content->px_primary_dataacc_id = data->values.i[index];
							proxy_content->px_secondary_dataacc_id =(S8) -1;
							primary_dataacc_flag = TRUE;
							break;
						}
					 }
					
					 for (; index < data->size; index++)
					 {
						if(mmi_dtcnt_get_bearer_type((U8)data->values.i[index]) != 0 &&
							proxy_content->px_primary_dataacc_id != data->values.i[index])
						{
							proxy_content->px_secondary_dataacc_id = data->values.i[index];
							break;
						}
					 }
					 if (primary_dataacc_flag == FALSE)
					 {
						proxy_content->px_primary_dataacc_id =(S8) -1;
					 }
					/* proxy_content->px_primary_dataacc_id = data->values.i[0];
                proxy_content->px_secondary_dataacc_id = data->values.i[1];
                if (proxy_content->px_primary_dataacc_id == proxy_content->px_secondary_dataacc_id)
                {
                    proxy_content->px_secondary_dataacc_id = -1;
                }*/
            }
            break;

        case CCA_NS_OMA_STARTPAGE:
            if (data->values.s[0])
            {
                /* memset(proxy_content->px_startpage,'\0',NVRAM_PROFILE_URL_LEN); */
                strncpy((S8*) proxy_content->px_startpage, (S8*) data->values.s[0], NVRAM_PROFILE_URL_LEN - 1);
            }
            break;

        case CCA_NS_OMA_PXAUTH_ID:
            if (data->values.s[0])
            {
                /* memset(proxy_content->px_authid,'\0',NVRAM_PROFILE_USERNAME_LEN); */
                strncpy((S8*) proxy_content->px_authid, (S8*) data->values.s[0], NVRAM_PROFILE_USERNAME_LEN - 1);
            }
            break;

        case CCA_NS_OMA_PXAUTH_PW:
            if (data->values.s[0])
            {
                /* memset(proxy_content->px_authpw,'\0',NVRAM_PROFILE_PASSWORD_LEN); */
                strncpy((S8*) proxy_content->px_authpw, (S8*) data->values.s[0], NVRAM_PROFILE_PASSWORD_LEN - 1);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_handle_application_params
 * DESCRIPTION
 *  Based on the namespace identifier ,it fill the application list.
 * PARAMETERS
 *  application_content     [IN]     
 *  data                    [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_handle_application_params(
        prov_application_content_struct *application_content,
        cca_core_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len_ucs2 = 0;
    S32 to_proxy_count = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_NAME:
            if (data->size)
            {
               if (data->values.s[0] != NULL && data->values.s[0][0] != '\0')
					{
                if (utf8_strlen((const U8*)data->values.s[0]) == (S32) strlen(data->values.s[0]))
                {
                    /* memset(application_content->app_name,'\0',sizeof(application_content->app_name)); */
							 // if (data->values.s[0] != NULL)
							 // {
                        strncpy(
                            (S8*) application_content->app_name,
                            (S8*) data->values.s[0],
                            sizeof(application_content->app_name) - 1);
                        application_content->app_dcs = BRW_PROF_DCS_ASCII;
							  //}
                }
                else
                {
							 // if (data->values.s[0] != NULL)
							 // {
                        len_ucs2 = mmi_charset_utf8_to_ucs2_length_in_bytes((U8*) data->values.s[0]);
                        if (len_ucs2 >= sizeof(application_content->app_name))
                        {
                            len_ucs2 = sizeof(application_content->app_name);
                        }
                        mmi_chset_utf8_to_ucs2_string(
                            (U8*) application_content->app_name,
                            len_ucs2,
                            (U8*) data->values.s[0]);
                        /* mmi_ucs2cpy((S8*) application_content->app_name,(S8*) data->values.s[0]); */
                        application_content->app_dcs = BRW_PROF_DCS_UCS;
							  //}
                    }
                }
            }
            break;
        case CCA_NS_OMA_TO_PROXY:
            to_proxy_count = data->size <= MAX_TO_RPOXY ? data->size : MAX_TO_RPOXY;
            for (i = 0; i < to_proxy_count; i++)
            {
                application_content->app_to_proxy[i] = OslMalloc(PROV_PROXY_ID_LEN);
					 memset((S8*) application_content->app_to_proxy[i],'\0',PROV_PROXY_ID_LEN);
                strncpy((S8*) application_content->app_to_proxy[i], (S8*) data->values.s[i], PROV_PROXY_ID_LEN - 1);
            }
            if (to_proxy_count < MAX_TO_RPOXY)
            {
                while (to_proxy_count != MAX_TO_RPOXY)
                {
                    application_content->app_to_proxy[to_proxy_count++] = NULL;
                }
            }
            break;

        
        case CCA_NS_OMA_ADDR:

            if (data->size)
            {
                if (data->values.s[0] != NULL && data->values.s[0][0] != '\0' 
						 && g_startpage_priority_first == 0)
                    {
                        /* memset(application_content->app_url,'\0',sizeof(application_content->app_url)); */
                        strncpy(
                            (S8*) application_content->app_url,
                            (S8*) data->values.s[0],
                        sizeof(application_content->app_url) - 1);

                        g_startpage_priority_first = 1;
                    }
                
            }
            break;

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_handle_application_params
 * DESCRIPTION
 *  Based on the namespace identifier ,it fill the application list.
 * PARAMETERS
 *  application_content     [IN]     
 *  data                    [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_handle_resource_params(
        prov_application_content_struct *application_content,
        cca_core_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len_ucs2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_NAME:
            if (data->size)
            {
				if (g_startpage_priority_first == 0)
                {
				/*	memset(
						 (S8*) application_content->bookmark[g_bookmark_count]->bm_title,
						 '\0',
						 MAX_BOOKMARK_TITLE_LEN*ENCODING_LENGTH); */
					if (data->values.s[0] != NULL && data->values.s[0][0] != '\0')
					{
					if (utf8_strlen((const U8*)data->values.s[0]) == (S32) strlen(data->values.s[0]))
						{
												mmi_asc_n_to_ucs2(
								(S8*) application_content->bookmark[g_bookmark_count]->bm_title,
								(S8*) data->values.s[0],
								MAX_BOOKMARK_TITLE_LEN - 1);
										}
					else
					{
													len_ucs2 = mmi_charset_utf8_to_ucs2_length_in_bytes((U8*) data->values.s[0]);
							if (len_ucs2 >= sizeof(application_content->bookmark[g_bookmark_count]->bm_title))
							{
								len_ucs2 = sizeof(application_content->bookmark[g_bookmark_count]->bm_title);
							}
							mmi_chset_utf8_to_ucs2_string(
										(U8*) application_content->bookmark[g_bookmark_count]->bm_title,
								len_ucs2,
								(U8*) data->values.s[0]);
								
						}
					}
				}
            }
            break;

        case CCA_NS_OMA_URI:
            if (data->size && data->values.s[0] != NULL && data->values.s[0][0] != '\0')
            {
                /*memset(
					(S8*) application_content->bookmark[g_bookmark_count]->bm_url,
					'\0',
					MAX_BOOKMARK_URL_LEN);*/

				if (g_startpage_priority_first == 0)
                {		
					g_bookmark_flag = TRUE;
					strncpy(
						(S8*) application_content->bookmark[g_bookmark_count]->bm_url,
						(S8*) data->values.s[0],
						MAX_BOOKMARK_URL_LEN - 1);       
                }
				else
				{
					g_bookmark_flag = FALSE;
					//	g_startpage_priority_first = 0;
                    strncpy(
                        (S8*) application_content->app_url,
                        (S8*) data->values.s[0],
						MAX_BOOKMARK_URL_LEN - 1);
				}
            }
			else
			{
				g_bookmark_flag = FALSE;
				//	g_startpage_priority_first = 0;
			}
            break;
  
        case CCA_NS_OMA_STARTPAGE:
            if (data->size)
            {
                             /* memset(application_content->app_url,'\0',sizeof(application_content->app_url)); */
                    if (g_bookmark_flag == TRUE)
					{
                    strncpy(
                        (S8*) application_content->app_url,
							(S8*) application_content->bookmark[g_bookmark_count]->bm_url,
							MAX_BOOKMARK_URL_LEN - 1);

						OslMfree(application_content->bookmark[g_bookmark_count]);
						application_content->bookmark[g_bookmark_count] = NULL;
						g_bookmark_count--;
                }
				                g_startpage_priority_first = 1;
            }
                   break;

    }
//	application_content->bookmark_count = g_bookmark_count;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_handle_service_params
 * DESCRIPTION
 *  it fills the service parameter for the proxy.
 * PARAMETERS
 *  proxy_content       [IN]         
 *  service_parm        [IN]        
 *  portnbr_parm        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_handle_service_params(
        prov_proxy_content_struct *proxy_content,
        S32 service_parm,
        S8 *portnbr_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

		S32 port_number = 0;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * CL-WAP            9200  WAP
     * CO-WSP            9201  WAP
     * CL-SEC-WSP        9202  WAP + Security ON
     * CO-SEC-WSP        9203  WAP + Security ON
     * CO-SEC-WTA        not supported
     * CL-SEC-WTA        not supported
     * OTA-HTTP-TO       80    HTTP
     * OTA-HTTP-TLS-TO   443   HTTP + Security ON
     * OTA-HTTP-PO       80    HTTP
     * OTA-HTTP-TLS-PO   443   HTTP + Security ON
     * 
     * all others --> HTTP
     * 
     */
    switch (service_parm)
    {

        case CCA_NS_VAL_CL_WSP:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED;
         // mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 9200);
			proxy_content->px_port = 9201;
            break;

        case CCA_NS_VAL_CO_WSP:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED;
         //   mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 9201);
			proxy_content->px_port = 9201;
            break;

        case CCA_NS_VAL_CL_SEC_WSP:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
           // mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 9202);
			proxy_content->px_port = 9203;
            break;

        case CCA_NS_VAL_CO_SEC_WSP:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
           // mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 9203);
			proxy_content->px_port = 9203;
            break;

            /* case CCA_NS_VAL_OTA_HTTP_TO:
               
               proxy_content->px_service =  BRW_PROF_CONN_TYPE_HTTP;
               mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 80);
               break; */

        case CCA_NS_VAL_OTA_HTTP_TLS_TO:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_HTTP;
            mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 443);
            break;

            /* case CCA_NS_VAL_OTA_HTTP_PO:
               
               proxy_content->px_service =  BRW_PROF_CONN_TYPE_HTTP;
               mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 80);
               break; */

        case CCA_NS_VAL_OTA_HTTP_TLS_PO:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_HTTP;
            mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 443);
            break;

        case CCA_NS_VAL_OTA_HTTP_TO:
        case CCA_NS_VAL_OTA_HTTP_PO:

            proxy_content->px_service = BRW_PROF_CONN_TYPE_HTTP;
            mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 80);
				break;

        default:
				if (portnbr_parm != NULL && portnbr_parm[0] != '\0')
				{
					port_number = atoi(portnbr_parm);
					if (port_number == 9200 || port_number == 9201)
					{
						proxy_content->px_service = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED;
					}
					else if (port_number == 9202 || port_number == 9203)
					{
						proxy_content->px_service = BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
					}
					else
					{
						proxy_content->px_service = BRW_PROF_CONN_TYPE_HTTP;
					}
				}
				else
				{
					proxy_content->px_service = BRW_PROF_CONN_TYPE_HTTP;
				}
            mmi_prov_browser_handle_port_params(proxy_content, portnbr_parm, 80);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_browser_handle_port_params
 * DESCRIPTION
 *  It fills the prot parameter for the proxy.
 * PARAMETERS
 *  proxy_content               [IN]         
 *  portnbr_parm                [IN]         
 *  default_portnbr_parm        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_browser_handle_port_params(
        prov_proxy_content_struct *proxy_content,
        S8 *portnbr_parm,
        S32 default_portnbr_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 port_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (portnbr_parm == NULL)
    {
        proxy_content->px_port = default_portnbr_parm;
    }
    else if (strcmp(portnbr_parm, "") == 0)
    {
        proxy_content->px_port = default_portnbr_parm;
    }
    else
    {
        port_number = atoi(portnbr_parm);
        if (port_number < 0 || port_number > 65535)
        {
            proxy_content->px_port = default_portnbr_parm;
        }
        else
        {
            proxy_content->px_port = port_number;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_convert_proxy_ipstring_to_array
 * DESCRIPTION
 *  This converts an IP string into an array
 * PARAMETERS
 *  parm_element_p      [IN]        
 *  proxy_ip_p          [IN]        
 * RETURNS
 *  U8					[OUT]
 *****************************************************************************/
U8 mmi_prov_convert_proxy_ipstring_to_array(U8 *parm_element_p, U8 *proxy_ip_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 proxy[MAX_PART_IP_ADDRESS];
    U32 i, j;
    U32 ip_part;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_prov_check_ip((S8*) parm_element_p))
    {
        return PROV_ERR;
    }
    if ((*parm_element_p) < '0' || (*parm_element_p) > '9')
    {
        return PROV_ERR;
    }

    for (j = 0; j < MAX_PART_IP_ADDRESS; ++j)
    {
        for (i = 0; (i < 3) && (strlen((S8*) parm_element_p));)
        {
            if (*parm_element_p == '.')
            {
                break;
            }
            if ((*parm_element_p) >= '0' && (*parm_element_p) <= '9')
            {
                proxy[i] = *parm_element_p++;
                i++;
            }
            else
            {
                return PROV_ERR;
            }
        }
        proxy[i] = '\0';
        ip_part = (U32) atoi(proxy);
        if (ip_part > PROV_IP_PART_MAX_VALUE)
        {
            return PROV_ERR;
            /* ip_part = PROV_IP_PART_MAX_VALUE; */
        }
        proxy_ip_p[j] = (U8) ip_part;
        ++parm_element_p;
    }
    return PROV_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_ip
 * DESCRIPTION
 *  Function to validate the IP
 * PARAMETERS
 *  ip      [IN]     
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_check_ip(S8 *ip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S8 *ip; */
    S8 seps[] = ".";
    S8 *token;
    S32 ip_sec = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //   ip = (S8*) OslMalloc(strlen((S8*) s) + 1);
    // strcpy((S8*)ip,(S8*) s);

    /* 1st char of ip or hostname can't be '.' */
    if (ip[0] == '.' || ip[strlen(ip) - 1] == '.')
    {
        goto err;
    }

    token = strtok(ip, seps);
    while (token)
    {
        U16 i;

        for (i = 0; i < strlen(token); i++)
        {
            if (i >= 3)
            {
                goto err;
            }

            if (token[i] < '0' || token[i] > '9')
            {
                goto err;
            }
        }

        /* this segement is ip format */
        ip_sec++;

        token = strtok(NULL, seps);
    }

    if (ip_sec != 4)
    {
        goto err;
    }

    /*    if (ip != NULL)
       {
       OslMfree(ip);
       ip = NULL;
       } */
    return 1;

  err:

    /*  if (ip != NULL)
       {
       OslMfree(ip);
       ip = NULL;
       } */

    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_commit_setting
 * DESCRIPTION
 *  This API display the profile information on idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//extern void mmi_test_dm(void);
void mmi_prov_commit_setting(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
 //   U8 *display_info = NULL;
	 S16 bookmark_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    	DeleteScreenIfPresent(SCR_ID_PROV_DUMMY);
    EntryNewScreen(SCR_ID_PROV_INFO_DISPLAY, NULL, mmi_prov_commit_setting, NULL);

 //   DeleteScreenIfPresent(SCR_ID_PROV_INFO_DISPLAY);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PROV_INFO_DISPLAY);

   /* if (g_prof_index >= 0 && g_prof_index < MAX_PROFILE_COUNT)
    {
        if (profile_list[g_prof_index] != NULL)
        {
            OslMfree(profile_list[g_prof_index]);
            profile_list[g_prof_index] = NULL;
        }
    }
    g_prof_index++;*/
    if (g_profile_index)
    {
       	mmi_brw_prov_create_display_info();

        ShowCategory74Screen(
            STR_ID_CCA_INSTALL_SETTING,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_INSTALL,
            0,
            STR_ID_CCA_SKIP,
            0,
            (U8*) subMenuData,
            mmi_ucs2strlen((const S8*)subMenuData),
            guiBuffer);
		
        SetLeftSoftkeyFunction(mmi_prov_install_setting, KEY_EVENT_UP);
   //     SetRightSoftkeyFunction(mmi_prov_commit_setting, KEY_EVENT_UP);
		SetRightSoftkeyFunction(rsk_handling_profile_content_display, KEY_EVENT_UP);
        SetKeyHandler(mmi_prov_send_end_key_event, KEY_END, KEY_EVENT_DOWN);
	//	SetKeyHandler(mmi_test_dm,KEY_1,KEY_EVENT_UP);
	//	OslMfree(display_info);
	//	ClearDelScrnIDCallbackHandler(SCR_ID_PROV_INFO_DISPLAY,NULL);
	//	SetDelScrnIDCallbackHandler(SCR_ID_PROV_INFO_DISPLAY, (HistoryDelCBPtr) mmi_prov_send_end_key_event);
     //   g_profile_index--;
    }
    else
    {
        g_prof_index = 0;
        g_prof_cntx.prov_activate_profile_flag = 0;

		while(g_profile_index < MAX_PROFILE_COUNT)
		{
			bookmark_count = 0;
			if (profile_list[g_profile_index] != NULL)
			{
				while (profile_list[g_profile_index]->bookmark_count != 0)
				{
					OslMfree(profile_list[g_profile_index]->bookmark[bookmark_count]);
					profile_list[g_profile_index]->bookmark[bookmark_count] = NULL;
					bookmark_count++;
					profile_list[g_profile_index]->bookmark_count--;
				}
				OslMfree(profile_list[g_profile_index]);
				profile_list[g_profile_index] = NULL;
			}
			g_profile_index++;
		}
		g_profile_index = 0;

        GoBackHistory();
        if (g_prof_cntx.setting_installed == 1)
        {
           if (g_prof_cntx.prov_flag == BRW_PROV_BROWSER_ONLY)
			  {
				mmi_brw_active_profile_changed_without_ui();
				mmi_prov_send_cca_status();
			  }
			else if (g_prof_cntx.prov_flag == BRW_PROV_MMS_ONLY)
			  {
				mmi_umms_set_current_mms_profile(TRUE);
					mmi_prov_send_cca_status();
			  }
		//	  mmi_prov_send_response(CCA_STATUS_OK);
            g_prof_cntx.setting_installed = 0;
        }
        else
        {
            mmi_prov_send_response(CCA_STATUS_SETTING_SKIPPED);
        }
    }
}
#if 0
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
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_send_cca_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  PU8
 *****************************************************************************/
void mmi_prov_send_cca_status(void)
{
	mmi_prov_send_response(CCA_STATUS_OK);
   g_prof_cntx.setting_installed = 0;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_create_display_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  PU8
 *****************************************************************************/
void mmi_brw_prov_create_display_info(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//	U8 *display_info = NULL;
	S8 new_line[] = "\n";

    U8 new_line_info[PROV_NEW_LINE_SIZE];

    S8 buffer[(NVRAM_PROFILE_NAME_LEN * ENCODING_LENGTH) + 1];
	S8 data_account_name[(PROF_MAX_DATAACCOUNT_NAME + 1) *ENCODING_LENGTH];
    S8 profile_count[PROV_COUNT_SIZE];
	S8 ip_address[16];
	S8 proxy_port[8];
	S8 url[(NVRAM_PROFILE_URL_LEN+1)*ENCODING_LENGTH];
#ifdef __MMI_VBOOKMARK__
	S16 index;
	S8 bookmark_count[PROV_COUNT_SIZE];
		S8 bookmark_title[(NVRAM_PROFILE_NAME_LEN * ENCODING_LENGTH)];
#endif
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		memset(subMenuData, 0, sizeof(subMenuData));
	
        mmi_asc_to_ucs2((S8*) new_line_info, (S8*) new_line);

		if (g_prov_type == BRW_PROV_BROWSER_ONLY)
		{
		mmi_ucs2cpy((PS8) subMenuData, GetString(STR_ID_CCA_BROWSER));
		}
		else if (g_prov_type == BRW_PROV_MMS_ONLY)
		{
				mmi_ucs2cpy((PS8) subMenuData, GetString(STR_ID_CCA_MMS));
		}

		mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
		
		memset(buffer, '\0', sizeof(buffer));
       	mmi_asc_to_ucs2((S8*) buffer, (S8*) "Profile Name :");

        mmi_ucs2cat((PS8) subMenuData, buffer);
        mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
        memset(buffer, '\0', sizeof(buffer));
        mmi_asc_to_ucs2((S8*) buffer, (S8*) profile_list[g_prof_index]->name);
        mmi_ucs2cat((PS8) subMenuData, buffer);

        mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
                  mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

			mmi_ucs2cat((PS8) subMenuData, GetString(STR_ID_CCA_PROFILE));
        memset(buffer, '\0', sizeof(buffer));
			sprintf(buffer, " %c %d/%d", ':', g_prof_index + 1, g_prof_index + g_profile_index);
        mmi_asc_to_ucs2((S8*) profile_count, (S8*) buffer);
        mmi_ucs2cat((PS8) subMenuData, profile_count);

        mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

        memset(buffer, '\0', sizeof(buffer));
        mmi_asc_to_ucs2((S8*) buffer, (S8*) "Connection Type :");
        mmi_ucs2cat((PS8) subMenuData, buffer);
        mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

               if (profile_list[g_prof_index]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED
            || profile_list[g_prof_index]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE)
        {
            mmi_ucs2cat((PS8) subMenuData, (S8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_WAP));
        }
        else
        {
            mmi_ucs2cat((PS8) subMenuData, (S8*) GetString(STR_ID_PROF_HDLR_CONN_TYPE_HTTP));
        }

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

    memset(buffer, '\0', sizeof(buffer));
			mmi_asc_to_ucs2((S8*) buffer, (S8*) "Proxy Server :");
	mmi_ucs2cat((PS8) subMenuData, buffer);

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
	memset(buffer, '\0', sizeof(buffer));

			sprintf(ip_address,"%d.%d.%d.%d%c",
			profile_list[g_prof_index]->proxy_ip[0],
			profile_list[g_prof_index]->proxy_ip[1],
			profile_list[g_prof_index]->proxy_ip[2],
					profile_list[g_prof_index]->proxy_ip[3],':');

	mmi_asc_to_ucs2((S8*) buffer, (S8*) ip_address);
	mmi_ucs2cat((PS8) subMenuData, buffer);

		/*	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
	memset(buffer, '\0', sizeof(buffer));
	mmi_asc_to_ucs2((S8*) buffer, (S8*) "Proxy Port:");
	mmi_ucs2cat((PS8) subMenuData, buffer);

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
		*/
	memset(buffer, '\0', sizeof(buffer));
	sprintf(proxy_port,"%d",profile_list[g_prof_index]->proxy_port);

	mmi_asc_to_ucs2((S8*) buffer, (S8*) proxy_port);
	mmi_ucs2cat((PS8) subMenuData, buffer);

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
		mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

	memset(buffer, '\0', sizeof(buffer));

		mmi_asc_to_ucs2((S8*) buffer, (S8*) "Data Account1 :");
	mmi_ucs2cat((PS8) subMenuData, buffer);

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
	memset(buffer, '\0', sizeof(buffer));
//	if (mmi_brw_prov_get_bearer_name(profile_list[g_prof_index]->primary_dataacc_id) != NULL)
//	{
		mmi_ucs2cat((PS8) subMenuData, mmi_brw_prov_get_bearer_name(profile_list[g_prof_index]->primary_dataacc_id));
//	}
	mmi_dtcnt_get_account_name(
        profile_list[g_prof_index]->primary_dataacc_id,
        (S8*) data_account_name,
        MAX_DATA_ACCOUNT_NAME_LEN);
	if (data_account_name != NULL  && data_account_name[0] != '\0')
	{
		mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
			mmi_ucs2cat((PS8) subMenuData, data_account_name);
    }
	
	if (profile_list[g_prof_index]->secondary_dataacc_id != -1)
    {
		mmi_dtcnt_get_account_name(
				profile_list[g_prof_index]->secondary_dataacc_id,
				(S8*) data_account_name,
				MAX_DATA_ACCOUNT_NAME_LEN);

		if (data_account_name != NULL  && data_account_name[0] != '\0')
        {

			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
				mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

			memset(buffer, '\0', sizeof(buffer));

				mmi_asc_to_ucs2((S8*) buffer, (S8*) "Data Account2 :");
			mmi_ucs2cat((PS8) subMenuData, buffer);

			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
		//	if (mmi_brw_prov_get_bearer_name(profile_list[g_prof_index]->secondary_dataacc_id) != NULL)
		//	{
			mmi_ucs2cat((PS8) subMenuData, mmi_brw_prov_get_bearer_name(profile_list[g_prof_index]->secondary_dataacc_id));
		//	}
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
					mmi_ucs2cat((PS8) subMenuData, data_account_name);
        }
		}
#ifdef __MMI_VBOOKMARK__
	if (profile_list[g_prof_index]->bookmark_count  != 0)
        {
		mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

		memset(buffer, '\0', sizeof(buffer));
		
			mmi_asc_to_ucs2((S8*) buffer, "Bookmarks : ");
		mmi_ucs2cat((PS8) subMenuData, buffer);

		memset(buffer, '\0', sizeof(buffer));

		sprintf (buffer,"%d",profile_list[g_prof_index]->bookmark_count);
		mmi_asc_to_ucs2((S8*) bookmark_count, (S8*)buffer);
		mmi_ucs2cat((PS8) subMenuData, bookmark_count);
		
		for (index = 0; index < profile_list[g_prof_index]->bookmark_count; index++)
		{
					mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
				mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);

			memset(buffer, '\0', sizeof(buffer));
			
				sprintf (bookmark_title,"%s%d %c","Bookmark", index+1, ':');
				mmi_asc_to_ucs2((S8*) buffer, (S8*)bookmark_title);
			mmi_ucs2cat((PS8) subMenuData, buffer);
			
				if (profile_list[g_prof_index]->bookmark[index]->bm_title[0] != '\0')
				{
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
			mmi_ucs2cat((PS8) subMenuData, (S8*)profile_list[g_prof_index]->bookmark[index]->bm_title);
			}
			
			mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
						mmi_asc_to_ucs2((S8*) url, (S8*)profile_list[g_prof_index]->bookmark[index]->bm_url);
			mmi_ucs2cat((PS8) subMenuData, url);
        }
    }
#endif

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
		mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
	
		memset(buffer, '\0', sizeof(buffer));
		if (g_prov_type == BRW_PROV_BROWSER_ONLY)
		{
			mmi_asc_to_ucs2((S8*) buffer, "Homepage :");
		}
		else
		{
			mmi_asc_to_ucs2((S8*) buffer, "MMSC Address :");
		}
	mmi_ucs2cat((PS8) subMenuData, buffer);

	mmi_ucs2cat((PS8) subMenuData, (S8*) new_line_info);
	mmi_asc_to_ucs2((S8*) url, (S8*)profile_list[g_prof_index]->url );
	mmi_ucs2cat((PS8) subMenuData, url);

//	return subMenuData;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_get_bearer_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  S8
 * RETURNS
 *  PS8
 *****************************************************************************/
S8* mmi_brw_prov_get_bearer_name(S8 data_acc_id)
        {
	U8 bearer_id;
	static S8 bearer_type[16];

	bearer_id = mmi_dtcnt_get_bearer_type(data_acc_id);

	switch(bearer_id)
        {
        case DATA_ACCOUNT_BEARER_CSD:
			mmi_asc_to_ucs2((S8*) bearer_type, "CSD");
            return bearer_type;
            
        case DATA_ACCOUNT_BEARER_GPRS:
            mmi_asc_to_ucs2((S8*) bearer_type, "GPRS");
            return bearer_type;
            
        case DATA_ACCOUNT_BEARER_WIFI:
	        mmi_asc_to_ucs2((S8*) bearer_type, "WIFI");
            return bearer_type;
    }
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  rsk_handling_profile_content_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void rsk_handling_profile_content_display(void)
{
	mmi_cca_ui_common_cancel(STR_ID_CCA_SKIP_PROFILE,mmi_brw_skip_profile);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_skip_profile
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_skip_profile(void)
{
	mmi_brw_prov_update_remaining_profile_count();
	DeleteScreenIfPresent(SCR_ID_PROV_INFO_DISPLAY);
	mmi_prov_commit_setting();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_get_content_from_setting
 * DESCRIPTION
 *  This API extract the data from created profile to save in NVRAM .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prov_get_content_from_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//	 S16 index = g_prof_index+1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	

    if (profile_list[g_prof_index]->dcs == BRW_PROF_DCS_ASCII)
    {
        mmi_asc_to_ucs2(
            (S8*) g_prof_cntx.profile_display_p->profile_name,
            (S8*) profile_list[g_prof_index]->name);
    }
    else if (profile_list[g_prof_index]->dcs == BRW_PROF_DCS_UCS)
    {
        mmi_ucs2cpy((S8*) g_prof_cntx.profile_display_p->profile_name, (S8*) profile_list[g_prof_index]->name);
    }
    mmi_asc_to_ucs2((S8*) g_prof_cntx.profile_display_p->url, (S8*) profile_list[g_prof_index]->url);

    mmi_asc_to_ucs2((S8*) g_prof_cntx.profile_display_p->username, (S8*) profile_list[g_prof_index]->username);

    mmi_asc_to_ucs2((S8*) g_prof_cntx.profile_display_p->password, (S8*) profile_list[g_prof_index]->password);

    /* g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary.data_account_type
       =BRW_PROF_DEFAULT_DATA_ACCOUNT_PRIMARY_TYPE; */

    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id
        = profile_list[g_prof_index]->primary_dataacc_id;

    /* g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary.data_account_type
       =BRW_PROF_DEFAULT_DATA_ACCOUNT_SECONDARY_TYPE; */
    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id
        = profile_list[g_prof_index]->secondary_dataacc_id;

    if (profile_list[g_prof_index]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED ||
        profile_list[g_prof_index]->conn_type == BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE ||
        profile_list[g_prof_index]->conn_type == BRW_PROF_CONN_TYPE_HTTP)
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type = profile_list[g_prof_index]->conn_type;
        g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port = profile_list[g_prof_index]->proxy_port;
    }
    else
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type = BRW_PROF_CONN_TYPE_HTTP;
        g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port = 80;
    }
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[0] = profile_list[g_prof_index]->proxy_ip[0];
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[1] = profile_list[g_prof_index]->proxy_ip[1];
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[2] = profile_list[g_prof_index]->proxy_ip[2];
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip[3] = profile_list[g_prof_index]->proxy_ip[3];

    //              OslMfree(profile_list[g_prof_index]);
    //              profile_list[g_prof_index] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_install_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_install_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_prov_type)
    {
        case BRW_PROV_BROWSER_ONLY:

            mmi_brw_prof_pre_entry_show_profile_list_menu(BRW_PROF_BROWSER_PROV_PROFILE);
            break;

        case BRW_PROV_MMS_ONLY:

            mmi_brw_prof_pre_entry_show_profile_list_menu(BRW_PROF_MMS_PROV_PROFILE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_proxy_app_nodes
 * DESCRIPTION
 *  This API frees all the memory used to create a profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_proxy_app_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (proxy_list[i] != NULL && i < MAX_PROFILE_COUNT)
    {
        OslMfree(proxy_list[i]);
        proxy_list[i] = NULL;
        i++;
    }
    i = 0;
    while (app_list[i] != NULL && i < MAX_PROFILE_COUNT)
    {
        while (app_list[i]->app_to_proxy[j] != NULL && j < MAX_TO_RPOXY)
        {
            OslMfree(app_list[i]->app_to_proxy[j]);
            app_list[i]->app_to_proxy[j] = NULL;
            j++;
        }
	j = 0;
	while (app_list[i]->bookmark[j] != NULL && j < MAX_BOOKMARK_COUNT)
	{
	    OslMfree(app_list[i]->bookmark[j]);
            app_list[i]->bookmark[j] = NULL;
            j++;
	}
        OslMfree(app_list[i]);
        app_list[i] = NULL;
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_send_end_key_event
 * DESCRIPTION
 *  This API sends end key event to CCA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_send_end_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 S16 index =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	while (index < MAX_PROFILE_COUNT)
	{
		if (profile_list[index] != NULL)
		{
			OslMfree(profile_list[index]);
			profile_list[index] = NULL;
		}
		index++;
	}
    g_prof_index = 0;
	g_profile_index = 0;
    g_prof_cntx.prov_activate_profile_flag = 0;
	g_prof_cntx.setting_installed = 0;
    mmi_prov_send_response(CCA_STATUS_ENDKEY_PRESSED);
//	SetDelScrnIDCallbackHandler(SCR_ID_PROF_HDLR_PROF_LIST, (HistoryDelCBPtr) mmi_prov_end_key_callback);
//	SetDelScrnIDCallbackHandler(SCR_ID_PROV_INFO_DISPLAY, (HistoryDelCBPtr) mmi_prov_end_key_callback);
/*	DeleteUptoScrID(SCR_ID_PROV_INFO_DISPLAY);
	DeleteScreenIfPresent(SCR_ID_PROV_INFO_DISPLAY);
	GoBackHistory();*/
	DisplayIdleScreen();
//	return FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_update_remaining_profile_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prov_update_remaining_profile_count(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VBOOKMARK__	
	mmi_brw_prov_check_bookmark();
#endif
	g_profile_index--;
	g_prof_index++;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prov_delete_screen(void)
{
	EntryNewScreen(SCR_ID_PROV_DUMMY, NULL, NULL, NULL);
	DeleteScreenIfPresent(SCR_ID_PROV_INFO_DISPLAY);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prov_check_bookmark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VBOOKMARK__
void mmi_brw_prov_check_bookmark(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	pBOOL result = FALSE;
	S16 index =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	

	if (profile_list[g_prof_index]->bookmark_count > 0)
	{
		for (index = 0;index < profile_list[g_prof_index]->bookmark_count; index++)
		{
			result = mmi_brw_add_to_bookmark(profile_list[g_prof_index]->bookmark[index]->bm_title, 
									profile_list[g_prof_index]->bookmark[index]->bm_url);
			if (result != BRW_ADD_TO_BKM_SUCCESS)
			{
				break;
			}
		}
	}
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_send_response
 * DESCRIPTION
 *  This API sends the status of the profile whether it is being installed succesfully,skipped or Invalid profile
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_send_response(cca_status_enum status)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_cca_app_configure_rsp_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (config_doc != NULL)
    {
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_MMI;
        Message.oslMsgId = PRT_MMI_CCA_APP_CONFIGURE_RSP;

        local_data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));

        local_data->config_id = config_doc->config_id;
        local_data->hConfig = config_doc->hConfig;
        local_data->status = status;

        Message.oslDataPtr = (oslParaType*) local_data;
        Message.oslPeerBuffPtr = NULL;

		  OslMfree(config_doc);
        config_doc = NULL;

        OslMsgSendExtQueue(&Message);
    }
}

#endif
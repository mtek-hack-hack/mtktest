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
 *    SyncmlOTAP.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML OTA provisioning appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_SYNCML_CCA_SUPPORT__

#include "conversions.h" 
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProtocolEvents.h"


#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"

#include "CentralConfigAgentGProt.h"    /* CCA header */
#include "mmi2syncml_struct.h"
#include "Abm_soc_enums.h"
#include "MainMenuDef.h"




/*
 * Local Variable
 */
static void mmi_syncml_cca_config_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status);
static syncml_ota_context_struct *mmi_syncml_new_ota_cntx(U16 conf_id, S32 doc_hdl);
static cca_status_enum mmi_syncml_proc_cca_nodes(
                        S32 doc_hdl, 
                        S32 node_hdl, 
                        U16 symbol, 
                        cca_iterator_struct *param_list, 
                        void *user_data);    
static S16 mmi_syncml_new_otap_profile(syncml_ota_context_struct *cntx);
static void mmi_syncml_init_slim_profile(nvram_ef_syncml_profile_struct *prof);
static U8 mmi_syncml_get_valid_profile_num(void);
static void mmi_syncml_otherapp_abort_ota_install(void);
static void mmi_syncml_entry_installation(void);
static void mmi_syncml_find_empty_profile(void);
static U8 mmi_syncml_is_empty_profile(U8 record_id);
static void mmi_syncml_next_profile(void);
static void mmi_syncml_entry_replacement(void);
static U8 mmi_syncml_install_profiles(void);
static void mmi_syncml_free_syncml_ota_cntx(void);
static void mmi_syncml_entry_replacement_confirm(void);
static void mmi_syncml_replacement_highlight_hdlr(S32 index);
static void mmi_syncml_show_info(U16 msg_id);
static void mmi_syncml_replacement_save(void);
static void goback_history_for_replace_screen(void);
static U8 Is_ANSII_format(S8 *dest ,kal_int32 dest_size);
static void mmi_syncml_exit_install(void);
static void mmi_syncml_display_skip_confirm(void);
static S32 syncml_atoi_for_ipaddr(const S8 *s);

extern S8 *syncml_itoa(S32 value, S8 *s, S32 radix);
extern S32 syncml_atoi(const S8 *s);

static syncml_ota_context_struct *g_syncml_ota_context = NULL;
extern syncml_context_struct g_syncml_context;
static U8 g_syncml_ota_next_profile;


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to syncml
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the syncml settings for each profile.
     */
    const U16 proc_tbl[] = 
     {
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY, 
            CCA_NS_SYNCML_PROXY,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PORT, 
            CCA_NS_SYNCML_PORT,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PXAUTHINFO, 
            CCA_NS_SYNCML_PXAUTHINFO,0xFFFF,            
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION, 
            CCA_NS_SYNCML_APPLICATION,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPADDR,
            CCA_NS_SYNCML_APPADDR,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPAUTH, 
            CCA_NS_SYNCML_APPAUTH,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_RESOURCE,
            CCA_NS_SYNCML_RESOURCE,0xFFFF
     };
    U8 i;
    nvram_ef_syncml_profile_struct *temp_nvram_buf;
    S16 error;
    cca_status_enum status;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_proc_cca_doc(), conf_id = %d , doc_hdl= %d", conf_id,doc_hdl);

    /* Init control block and save the ID/handle for the response msg.*/
    g_syncml_ota_context = mmi_syncml_new_ota_cntx(conf_id, doc_hdl);   

    if (g_syncml_ota_context == NULL) 
    {
        mmi_syncml_cca_config_rsp(conf_id, doc_hdl, CCA_STATUS_FAIL);
        return;
    }    

	/* this flag is to control re-entry SCR_ID_SYNC_OTA_PROFILE_INSTALL 
	 * for installing next profile. 
	 */
    g_syncml_ota_next_profile = 0;

    /* Extract data syncml settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                doc_hdl, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                mmi_syncml_proc_cca_nodes, 
                g_syncml_ota_context);
    /* If there is no correct SYNCML profile, send a INVALID_SETTING response message back to CCA. */
    if (mmi_syncml_get_valid_profile_num() == 0) 
    {        
        /* Now, terminate the SYNCML OTA provisioning application. */
        mmi_syncml_cca_config_rsp(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        mmi_syncml_free_syncml_ota_cntx();
        return;
    }

    /* Setup callback to free memory and send message back to CCA when users
       press END key and return to idle screen, or when the app exits. */
    /*read current profile name list from NVRAM*/
    temp_nvram_buf = (nvram_ef_syncml_profile_struct *)OslMalloc(sizeof(nvram_ef_syncml_profile_struct));
    if (temp_nvram_buf == NULL) 
    {
        mmi_syncml_cca_config_rsp(conf_id, doc_hdl, CCA_STATUS_FAIL);
        mmi_syncml_free_syncml_ota_cntx();
        return;
    }
    memset(temp_nvram_buf, 0, sizeof(nvram_ef_syncml_profile_struct));
    for (i=0; i<MAX_SYNCML_SV_PROFILES; i++)
    {    
PRINT_INFORMATION_2(TRACE_GROUP_7, "[SyncML][provisioning & DM]mmi_syncml_proc_cca_doc()222");    
        mmi_syncml_read_profile_from_nvram(i+1,(void*)temp_nvram_buf);
        mmi_ucs2cpy((S8 *)g_syncml_ota_context->currentprofnamelist[i],(S8 *)temp_nvram_buf->profile_name);
    }
    OslMfree(temp_nvram_buf);
    /* Ready to install profiles. */
    mmi_syncml_entry_installation();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_new_ota_cntx
 * DESCRIPTION
 *  This function allocates and initializes the control block of SYNCML OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
syncml_ota_context_struct *mmi_syncml_new_ota_cntx(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_ota_context_struct *cntx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_new_ota_cntx()");
    cntx = (syncml_ota_context_struct *)OslMalloc(sizeof(syncml_ota_context_struct));
    if (cntx == NULL) 
    {
        return NULL;
    }

    /* Clear the entire structure. */
    memset(cntx, 0, sizeof(syncml_ota_context_struct));

    /* Save the identifier for this configuration process. */
    cntx->conf_id = conf_id;
    cntx->doc_hdl = doc_hdl;
    /* Initialize the index for replacement to an invalid index. */
    for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++) 
    {
        cntx->dst_idx[i] = -1;
    }    
    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_syncml_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_ota_context_struct *cntx;
    cca_core_data_struct *param;
    cca_status_enum status;
    S16 index_profile, index_proxy;
    U8 i, j;
    U8 temp_UCS2[MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH]; 
    S8 *s;
    S8 accept[20];      /*"text/x-vcalendar" or "text/x-vcard"*/
    S8 temp_db_addr[MAX_SYNCML_DATABASE_ADDR_LEN];
    S8 temp_db_username[MAX_SYNCML_USERNAME];    
    S8 temp_db_password[MAX_SYNCML_PASSWORD]; 
    U8 flag_address,flag_username,flag_password;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (syncml_ota_context_struct*)user_data;
    index_profile = cntx->num_profiles;
    index_proxy = cntx->num_proxy;
    flag_address = 0;
    flag_username = 0;
    flag_password = 0;
    memset(accept,0,20);
    PRINT_INFORMATION_2(TRACE_GROUP_7, "[SyncML][provisioning & DM]mmi_syncml_proc_cca_nodes()");
    switch (symbol)
    {
        case CCA_NS_SYNCML_PROXY:
		{
            cntx->num_proxy++;
            if(cntx->num_proxy > MAX_SYNCML_SV_PROFILES)
            {
                return CCA_STATUS_OK;
            }
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                switch (param->id)
                {
                    case CCA_NS_OMA_PROXY_ID:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_PROXY_ID_LEN) == 1)
                            {
                                strncpy((S8 *)cntx->proxy[index_proxy].proxy_id,param->values.s[0],MAX_PROXY_ID_LEN-1);   
                                cntx->proxy[index_proxy].proxy_id[MAX_PROXY_ID_LEN-1]= '\0';
                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_PXADDR:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_PROXY_IP_ADDR_LEN) == 1)
                            {
                              strncpy((S8 *)cntx->proxy[index_proxy].proxy_addr, param->values.s[0],MAX_PROXY_IP_ADDR_LEN-1);                         
                              cntx->proxy[index_proxy].proxy_addr[MAX_PROXY_IP_ADDR_LEN-1]='\0';
                            }
                        }
                        break;
                        
                    case CCA_NS_DATAACCTID:
                         /*If data isn't ABM_E_SOCKET_BEARER_GSM_GPRS ,we pass this node*/					
				if(mmi_dtcnt_get_bearer_type((U32)param->values.i[0]) != ABM_E_SOCKET_BEARER_GSM_GPRS)
				{
					memset(&cntx->proxy[index_proxy],0,sizeof(ota_proxy_context_struct));
				       cntx->num_proxy--;
					return CCA_STATUS_FAIL;
				}
				else
                        {
                          	cntx->proxy[index_proxy].dataaccountid = (U32)param->values.i[0];
                        }
                        break;                               
                    case CCA_NS_OMA_PXADDRTYPE:
                        /*If data isn't CCA_NS_VAL_IPV4,we pass this node*/
                        if(param->values.i[0])
                        {
                            if((S8)param->values.i[0]!= (S8)CCA_NS_VAL_IPV4)
                            {
                                memset(&cntx->proxy[index_proxy],0,sizeof(ota_proxy_context_struct));
                                cntx->num_proxy--;
                                return CCA_STATUS_FAIL;
                            }
                                
                        }
                        break;  
                    default:
                        break;
                        
                }                
            }
            
            status = CCA_STATUS_OK;
            break;
        }   
        case CCA_NS_SYNCML_PORT:
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                    switch (param->id)
                    {
                        case CCA_NS_OMA_PORTNBR:
                            if(param->values.s[0])
                            {
                                if(Is_ANSII_format((S8 *)param->values.s[0],MAX_PROXY_IP_ADDR_LEN) == 1)
                                {
                                    strncpy((S8 *)cntx->proxy[index_proxy-1].proxy_portnbr, param->values.s[0],
                                                              MAX_PROXY_PORT_LEN-1);        
                                    cntx->proxy[index_proxy-1].proxy_portnbr[MAX_PROXY_PORT_LEN-1]='\0';
                                }
                            }
                            break;                                                 
                        case CCA_NS_OMA_SERVICE:
                       /*If data isn't whether CCA_NS_VAL_CL_WSP nor CCA_NS_VAL_OTA_HTTP_TO,
                                we pass this node*/
                            if(param->values.i[0])
                            {
                                if(param->values.i[0] == CCA_NS_VAL_CL_WSP)                                    
                                {                                
                                    cntx->proxy[index_proxy-1].conn_type = SYNCML_TRANS_WSP;
                                }
                                else if(param->values.i[0] == CCA_NS_VAL_OTA_HTTP_TO)
                                {
                                    cntx->proxy[index_proxy-1].conn_type = SYNCML_TRANS_HTTP;
                                }
                                else
                                {
                                    return CCA_STATUS_FAIL;
                                }
                            }                                
                        default:
                            break;
                            
                    }
            }
            status = CCA_STATUS_OK;            
            break;            
        }    
        case CCA_NS_SYNCML_PXAUTHINFO:
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                    switch (param->id)
                    {
                        case CCA_NS_OMA_PXAUTH_ID:
                            if(param->values.s[0])
                            {
                                if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_PROXY_USERNAME) == 1)
                                {
                                    strncpy((S8 *)cntx->proxy[index_proxy-1].proxy_username, param->values.s[0],
                                                              MAX_SYNCML_PROXY_USERNAME-1);        
                                    cntx->proxy[index_proxy-1].proxy_username[MAX_SYNCML_PROXY_USERNAME-1]='\0';
                                }
                            }
                            break;                                                 
                        case CCA_NS_OMA_PXAUTH_PW:
                            if(param->values.s[0])
                            {
                                if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_PROXY_PASSWORD) == 1)
                                {
                                    strncpy((S8 *)cntx->proxy[index_proxy-1].proxy_password, param->values.s[0],
                                                              MAX_SYNCML_PROXY_PASSWORD-1);        
                                    cntx->proxy[index_proxy-1].proxy_password[MAX_SYNCML_PROXY_PASSWORD-1]='\0';
                                }
                            }
                            break;                               
                        default:
                            break;
                            
                    }
            }
            status = CCA_STATUS_OK;            
            break;            
        }
        case CCA_NS_SYNCML_APPLICATION:
        {
            /* When start process this node,we predefine all the node proxy have already been processed */            
            /* Prepare a storage for the new profile. And get the new index. */
            if ((index_profile = mmi_syncml_new_otap_profile(cntx)) < 0)
            {
                return CCA_STATUS_FAIL;
            }
            cntx->num_profiles++;
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                switch (param->id)
                {
                    case CCA_NS_OMA_APPID:
                        /*syncml appid is "w5" */
                        if(param->values.s[0])
                        {
                            if(strcmp((S8 *)param->values.s[0], (S8 *)"w5") != 0)
                            {
                                return CCA_STATUS_FAIL;
                            }
                            
                        }
                        break;
                
                    case CCA_NS_OMA_NAME: 
                        if(strlen(param->values.s[0]))
                        {
							mmi_chset_utf8_to_ucs2_string(
											(U8 *)temp_UCS2, 
											MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
											(U8 *)param->values.s[0]);
                            mmi_ucs2ncpy((S8*)cntx->profile[index_profile]->profile_name,(S8*)temp_UCS2,
                                MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH);
                        }
                        break;
                
                    case CCA_NS_OMA_TO_PROXY:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_PROXY_ID_LEN) == 1)
                            {
                               strncpy((S8 *)cntx->app_to_proxy[index_profile], (S8 *)param->values.s[0],MAX_PROXY_ID_LEN-1);
                               cntx->app_to_proxy[index_profile][MAX_PROXY_ID_LEN-1]='\0';
                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_ADDR:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_SERVER_ADDR_LEN) == 1)
                            {
                                strncpy((S8 *)cntx->profile[index_profile]->server_address ,(S8 *)param->values.s[0],
                                MAX_SYNCML_SERVER_ADDR_LEN-1);
                                cntx->profile[index_profile]->server_address[MAX_SYNCML_SERVER_ADDR_LEN-1]='\0';
                            }
                            else
                            {
                                memset(cntx->profile[index_profile]->server_address, 0, MAX_SYNCML_SERVER_ADDR_LEN);
                            }
                            
                        }
                        break;                        
                
                    default:
                        break;
                        
                }
            }
            if(strncmp((S8 *)cntx->app_to_proxy[index_profile], (S8 *)"@CCA@GEN@",9)== 0)
            {
                cntx->profile[index_profile]->use_proxy = 0;

			if(mmi_dtcnt_get_bearer_type((U8)cntx->profile[index_profile]->net_id) != ABM_E_SOCKET_BEARER_GSM_GPRS)			
			{
				cntx->isvalidprof[index_profile] = MMI_FALSE;
			}
			else
			{
                cntx->isvalidprof[index_profile] = MMI_TRUE;
            }
		}
            else
            	{
            for(i=0;i<cntx->num_proxy;i++)
                {
                    if(strcmp((S8 *)cntx->app_to_proxy[index_profile], (S8 *)cntx->proxy[i].proxy_id) == 0)
                    {                     
                        for (j = 0, s = (S8*)&cntx->proxy[i].proxy_addr; j < 4; j++) 
                        {
    			            if(syncml_atoi_for_ipaddr((S8 *)s) > 255)
                            {
                                cntx->isvalidprof[index_profile] = MMI_FALSE;
                                goto end_proxy;
                            }
    						else
    						{
                                cntx->profile[index_profile]->proxy_ip[j] = (kal_uint8)syncml_atoi_for_ipaddr((S8 *)s);
    						}                           
                            s = strchr (s, '.');
                            if (s == NULL)
                                break;
                            s++;
                        }
			if(syncml_atoi((const S8 *)cntx->proxy[i].proxy_portnbr) > 65535)
                        {
                            cntx->isvalidprof[index_profile] = MMI_FALSE;
                            goto end_proxy;
                        }
			else
			{
                            cntx->profile[index_profile]->proxy_port = 
                            (U16)syncml_atoi((const S8 *)cntx->proxy[i].proxy_portnbr);
			}                        
                        cntx->profile[index_profile]->net_id = cntx->proxy[i].dataaccountid;
                        strcpy((S8 *)cntx->profile[index_profile]->proxy_username,(S8 *)cntx->proxy[i].proxy_username);
                        strcpy((S8 *)cntx->profile[index_profile]->proxy_password,(S8 *)cntx->proxy[i].proxy_password);
                        cntx->profile[index_profile]->conn_type = cntx->proxy[i].conn_type;
                        cntx->profile[index_profile]->use_proxy = 1;
                        cntx->isvalidprof[index_profile] = MMI_TRUE;
                        break;
                        
                    }
                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                }
              }
end_proxy:
            status = CCA_STATUS_OK;
            break;
        }    
        case CCA_NS_SYNCML_APPADDR:
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                switch (param->id)
                {
                    case CCA_NS_OMA_ADDR:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_SERVER_ADDR_LEN) == 1)
                            {
                                strncpy((S8 *)cntx->profile[index_profile-1]->server_address, param->values.s[0],
                                MAX_SYNCML_SERVER_ADDR_LEN-1);    
                                cntx->profile[index_profile-1]->server_address[MAX_SYNCML_SERVER_ADDR_LEN-1]='\0';
                            }
                        }

                        break;         

                    default:
                        break;
                        
                }
            }
            status = CCA_STATUS_OK;            
            break;
        }     
        case CCA_NS_SYNCML_APPAUTH:
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                switch (param->id)
                {
                    case CCA_NS_OMA_AAUTHLEVEL: 
                        /*Predefine this param is received earlier than any other params of this node.
                        If authlevel is not CCA_NS_VAL_CLIENT,we pass this node*/
                         if(param->values.i[0])
                            {
                                if(param->values.i[0] != CCA_NS_VAL_CLIENT)
                                {
                                    return CCA_STATUS_FAIL;
                                }
                            } 
                        break;    
                         
                    case CCA_NS_OMA_AAUTHNAME:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_USERNAME) == 1)
                            {
                                strncpy((S8 *)cntx->profile[index_profile-1]->server_username, param->values.s[0],
                                MAX_SYNCML_USERNAME-1);      
                                cntx->profile[index_profile-1]->server_username[MAX_SYNCML_USERNAME-1]='\0';
                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_AAUTHSECRET:
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_PASSWORD) == 1)
                            {
                                strncpy((S8 *)cntx->profile[index_profile-1]->server_password, param->values.s[0],
                                MAX_SYNCML_PASSWORD-1);        
                                cntx->profile[index_profile-1]->server_password[MAX_SYNCML_PASSWORD-1] = '\0';
                            }
                        }
                        break;            

                    default:
                        break;
                        
                }
            }
            status = CCA_STATUS_OK;
            break;
        }    
        case CCA_NS_SYNCML_RESOURCE:
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {   
                switch (param->id)
                {
                    case CCA_NS_OMA_AAUTHTYPE:
                        /*reversed */
                        break;    
                        
                    case CCA_NS_OMA_AACCEPT:
                        if(param->values.s[0])
                        {
                            /*we predefine the accept param is the last one accepted*/
                            strncpy(accept, param->values.s[0],20);
                            if(strcmp((S8 *)accept, (S8 *)"text/x-vcard") == 0)
                            {
                                if(flag_address == 1)
                                {
                                    strcpy((S8 *)cntx->profile[index_profile-1]->contact_address, temp_db_addr);        
                                }
                                if(flag_username== 1)
                                {
                                    strcpy((S8 *)cntx->profile[index_profile-1]->contact_username, temp_db_username);    
                                }
                                if(flag_password== 1)
                                {
                                    strcpy((S8 *)cntx->profile[index_profile-1]->contact_password, temp_db_password);        
                                }
                            }
                            else if(strcmp((S8 *)accept, (S8 *)"text/x-vcalendar") == 0)
                            {
                                if(flag_address == 1)
                                {
                                    strcpy((S8 *)cntx->profile[index_profile-1]->calendar_address, temp_db_addr);  
                                }
                                if(flag_username == 1)
                                {
                                    strcpy((S8 *)cntx->profile[index_profile-1]->calendar_username, temp_db_username);        
                                }
                                if(flag_password == 1)
                                {
                                    strcpy((S8 *)cntx->profile[index_profile-1]->calendar_password, temp_db_password);      
                                }
                            }
                            else
                            {
                                /*notes*/
                            }
                        }
                        memset(temp_db_addr, 0,MAX_SYNCML_DATABASE_ADDR_LEN);
                        memset(temp_db_username, 0,MAX_SYNCML_USERNAME);
                        memset(temp_db_password, 0,MAX_SYNCML_PASSWORD);
                        break;
                        
                    case CCA_NS_OMA_URI:
                        memset(temp_db_addr, 0 ,MAX_SYNCML_DATABASE_ADDR_LEN);/*clear last database info*/
                        flag_address = 1;
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_USERNAME) == 1)
                            {
                                if(strcmp((S8 *)accept, (S8 *)"text/x-vcard") == 0)
                                {
                                    strncpy((S8 *)cntx->profile[index_profile-1]->contact_address, param->values.s[0],
                                        MAX_SYNCML_DATABASE_ADDR_LEN-1);    
                                }
                                else if(strcmp((S8 *)accept, (S8 *)"text/x-vcalendar") == 0)
                                {
                                    strncpy((S8 *)cntx->profile[index_profile-1]->calendar_address, param->values.s[0],
                                        MAX_SYNCML_DATABASE_ADDR_LEN-1);    
                                }
                                else/*accept has not been received*/
                                {
                                    strncpy(temp_db_addr, param->values.s[0],MAX_SYNCML_DATABASE_ADDR_LEN-1);
                                }
                            }
                        }
                        break;

                
                    case CCA_NS_OMA_AAUTHNAME:
                        memset(temp_db_username, 0 ,MAX_SYNCML_USERNAME);/*clear last database info*/
                        flag_username = 1;
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_USERNAME) == 1)
                            {
                                if(strcmp((S8 *)accept, (S8 *)"text/x-vcard") == 0)
                                {
                                    strncpy((S8 *)cntx->profile[index_profile-1]->contact_username, param->values.s[0],
                                        MAX_SYNCML_USERNAME-1);    
                                }
                                else if(strcmp((S8 *)accept, (S8 *)"text/x-vcalendar") == 0)
                                {
                                    strncpy((S8 *)cntx->profile[index_profile-1]->calendar_username, param->values.s[0],
                                        MAX_SYNCML_USERNAME-1);    
                                }
                                else/*accept has not been received*/
                                {
                                    strncpy(temp_db_username, param->values.s[0],MAX_SYNCML_USERNAME-1);
                                }
                            }
                        }
                        break;
                        
                    case CCA_NS_OMA_AAUTHSECRET:
                        memset(temp_db_password, 0 ,MAX_SYNCML_PASSWORD);/*clear last database info*/
                        flag_password= 1;
                        if(param->values.s[0])
                        {
                            if(Is_ANSII_format((S8 *)param->values.s[0],MAX_SYNCML_PASSWORD) == 1)
                            {
                                if(strcmp((S8 *)accept, (S8 *)"text/x-vcard") == 0)
                                {
                                    strncpy((S8 *)cntx->profile[index_profile-1]->contact_password, param->values.s[0],
                                        MAX_SYNCML_PASSWORD-1);    
                                }
                                else if(strcmp((S8 *)accept, (S8 *)"text/x-vcalendar") == 0)
                                {
                                    strncpy((S8 *)cntx->profile[index_profile-1]->calendar_password, param->values.s[0],
                                        MAX_SYNCML_PASSWORD-1);    
                                }
                                else/*accept has not been received*/
                                {
                                    strncpy(temp_db_password, param->values.s[0],MAX_SYNCML_PASSWORD-1);
                                }
                            }
                        }
                        break;            
                
                    default:
                        break;
                        
                }

            }
            status = CCA_STATUS_OK;
            break;          
        }
        default:
            return CCA_STATUS_OK;
        break;
            
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_free_syncml_ota_cntx
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_free_syncml_ota_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    /* Nothing to do. Return. */
    if (g_syncml_ota_context== NULL) 
    {
        return;
    }    
    /* Free all profiles. */
    for (i = 0; i < g_syncml_ota_context->num_profiles; i++) 
    {
        if (g_syncml_ota_context->profile[i] == NULL) 
        {
            continue;
        }
        OslMfree(g_syncml_ota_context->profile[i]);
        g_syncml_ota_context->profile[i] = NULL;
    }
    /* Free the control block. */
    OslMfree(g_syncml_ota_context);
    g_syncml_ota_context = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_valid_profile_num
 * DESCRIPTION
 *  This function checks if there is any valid profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 mmi_syncml_get_valid_profile_num(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 i, num = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_get_valid_profile_num()");
	for(i =0; i<g_syncml_ota_context->num_profiles; i++)
	{
		if(g_syncml_ota_context->profile[i])/*only to judge the profiles exist in buffer.*/
		{

				if ((strlen((S8 *)g_syncml_ota_context->profile[i]->server_address)== 0)
					||(strcmp((S8*) g_syncml_ota_context->profile[i]->server_address, (S8*)"http://") == 0))
				{
					g_syncml_ota_context->isvalidprof[i] = MMI_FALSE;
                    g_syncml_ota_context->profile[i]->profile_validation &= ~0x02;
				}
                else
                {
				g_syncml_ota_context->isvalidprof[i] = MMI_TRUE;
				    g_syncml_ota_context->profile[i]->profile_validation |= 0x02;
                }
				if (((strlen((S8 *)g_syncml_ota_context->profile[i]->contact_address)== 0)
					||(strcmp((S8*) g_syncml_ota_context->profile[i]->contact_address, (S8*)"./") == 0))
					&&(g_syncml_context.applications_to_sync == SYNCML_DB_PHONEBOOK))
				{
					g_syncml_ota_context->isvalidprof[i] = MMI_FALSE;
                    g_syncml_ota_context->profile[i]->profile_validation &= ~0x04;
				} 
                else
                {
                    g_syncml_ota_context->profile[i]->profile_validation |= 0x04;
                }
				if (((strlen((S8 *)g_syncml_ota_context->profile[i]->calendar_address)== 0)
					||(strcmp((S8*) g_syncml_ota_context->profile[i]->calendar_address, (S8*)"./") == 0))
					&&(g_syncml_context.applications_to_sync == SYNCML_DB_TODOLIST))
				{
					g_syncml_ota_context->isvalidprof[i] = MMI_FALSE;
                    g_syncml_ota_context->profile[i]->profile_validation &= ~0x08;
				} 
                else
                {
                    g_syncml_ota_context->profile[i]->profile_validation |= 0x08;
                }
				if (((strlen((S8 *)g_syncml_ota_context->profile[i]->contact_address)== 0)
					||(strcmp((S8*) g_syncml_ota_context->profile[i]->contact_address, (S8*)"./") == 0)
					||(strlen((S8 *)g_syncml_ota_context->profile[i]->calendar_address)== 0)
					||(strcmp((S8*) g_syncml_ota_context->profile[i]->calendar_address, (S8*)"./") == 0))
					&&(g_syncml_context.applications_to_sync == SYNCML_DB_PHONEBOOK + SYNCML_DB_TODOLIST))
				{
					g_syncml_ota_context->isvalidprof[i] = MMI_FALSE;
				} 				
			}				
	
        if(g_syncml_ota_context->isvalidprof[i] == MMI_TRUE)
        {
            num++;
        }
	}
	return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_otherapp_abort_ota_install
 * DESCRIPTION
 *  This function will be called when other apps interrupt SCR_ID_SYNC_OTA_PROFILE_INSTALL screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_otherapp_abort_ota_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Terminated. Send a response back to CCA and free memory. */    
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, NULL);
    mmi_syncml_cca_config_rsp(g_syncml_ota_context->conf_id, g_syncml_ota_context->doc_hdl, 
    CCA_STATUS_ENDKEY_PRESSED);
    mmi_syncml_free_syncml_ota_cntx();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_syncml_profile_struct *prof;
    S8 *info;
    U8 *gui_buffer;
    U8 i, total_valid = 0;
    U8 current_valid = 0;
    U8 tmp[MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH];
    S8 tmpnum[4 * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the current interesting profile. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_entry_installation()  g_syncml_ota_context->iter = %d",g_syncml_ota_context->iter);
    for(i=0; i<MAX_SYNCML_SV_PROFILES; i++)
    {
        if(g_syncml_ota_context->isvalidprof[i] == MMI_TRUE)
        {
            total_valid++;
        }
    }
    if(total_valid == 0)
    {
        MMI_ASSERT(0);
    }
    while ((g_syncml_ota_context->isvalidprof[g_syncml_ota_context->iter] != MMI_TRUE)
            &&(g_syncml_ota_context->iter < MAX_SYNCML_SV_PROFILES))
    {
        g_syncml_ota_context->iter++;
    }
    prof = (nvram_ef_syncml_profile_struct *)g_syncml_ota_context->profile[g_syncml_ota_context->iter];

    /* Obtain a temporary buffer to show messages. */
    info = (S8 *)subMenuData;

    for(i=0; i<g_syncml_ota_context->iter+1; i++)
    {
        if(g_syncml_ota_context->isvalidprof[i])
        {
            current_valid++;
        }
    }
    /* Profile name */
    mmi_ucs2cpy(info, GetString(STR_ID_CCA_SYNCMLDS));
    mmi_ucs2cat(info, (S8 *)L": ");
    mmi_ucs2cat(info, (S8 *)prof->profile_name);
    mmi_ucs2cat(info, (S8 *)L"\n\n"); 
    
    /* Current profile num */
    mmi_ucs2cat(info, GetString(STR_ID_SYNC_PROFILE));
    mmi_ucs2cat(info, (S8 *)L": ");    
    sprintf((S8 *)&tmpnum,"%d",current_valid);
    memset(tmp,0,sizeof(tmp));
    mmi_asc_n_to_ucs2(
                (S8 *) tmp,
                (S8 *) tmpnum,
                strlen((S8*)&tmpnum));
    mmi_ucs2cat(info, (S8 *)tmp);
    mmi_ucs2cat(info, (S8 *)L"/");
    sprintf((S8*)&tmpnum,"%d",total_valid);
    memset(tmp,0,sizeof(tmp));
    mmi_asc_n_to_ucs2(
                (S8 *) tmp,
                (S8 *) tmpnum,
                strlen((S8*)&tmpnum));
    mmi_ucs2cat(info, (S8 *)tmp);  
    mmi_ucs2cat(info, (S8 *)L"\n\n"); 
    
    /* Server address */
    mmi_ucs2cat(info, GetString(STR_ID_SYNC_SERVER_ADDRESS));
    memset(tmp,0,sizeof(tmp));
    mmi_ucs2cat(info, (S8 *)L":  ");
            mmi_asc_n_to_ucs2(
            (S8 *) tmp,
            (S8 *) prof->server_address,
            strlen((S8*)prof->server_address));
    mmi_ucs2cat(info, (S8 *)tmp);
    mmi_ucs2cat(info, (S8 *)L"\n\n");  
    
    /* Contact address */
    memset(tmp, 0,MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);/*must clear 0,for the coming string maybe an empty string*/
    mmi_ucs2cat(info, GetString(STR_ID_SYNC_CONTACT_ADDRESS));
            mmi_asc_n_to_ucs2(
            (S8 *) tmp,
            (S8 *) prof->contact_address,
            strlen((S8*)prof->contact_address));
    mmi_ucs2cat(info, (S8 *)L":  ");
    mmi_ucs2cat(info, (S8 *)tmp);
    mmi_ucs2cat(info, (S8 *)L"\n\n");
    
    /* Calendar address */
    memset(tmp, 0,MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);/*must clear 0,for the coming string maybe an empty string*/
    mmi_ucs2cat(info, GetString(STR_ID_SYNC_CALENDAR_ADDRESS));
            mmi_asc_n_to_ucs2(
            (S8 *) tmp,
            (S8 *) prof->calendar_address,
            strlen((S8*)prof->calendar_address));
    mmi_ucs2cat(info, (S8 *)L":  ");
    mmi_ucs2cat(info, (S8 *)tmp);
    mmi_ucs2cat(info, (S8 *)L"\n\n");     
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_entry_installation()        info = %s",*info);
    EntryNewScreen(SCR_ID_SYNC_OTA_PROFILE_INSTALL, NULL, mmi_syncml_entry_installation, NULL);
	if (g_syncml_ota_next_profile)
	{
		/* if this flag be set, we should treat it as a new profile to install
		 * so we need to clear guibuffer (ex. scroll bar position)
		 */
		gui_buffer = NULL;
		g_syncml_ota_next_profile = 0;
	}
	else
	{
        gui_buffer = GetCurrGuiBuffer(SCR_ID_SYNC_OTA_PROFILE_INSTALL);
	}
        ShowCategory74Screen(
            STR_ID_CCA_INSTALL_SETTING,
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
            IMG_ID_SYNC_SETTINGS,
#endif            
            STR_GLOBAL_INSTALL,
            IMG_GLOBAL_YES,
            STR_ID_CCA_SKIP,
            IMG_GLOBAL_NO,
            (U8 *)info,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            gui_buffer);      
    SetLeftSoftkeyFunction(mmi_syncml_find_empty_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_display_skip_confirm, KEY_EVENT_UP);

    /* Delete screens associated with previous profile. Clear delete screen 
       callback temporarily to prevent from terminating app. */
//    DeleteScreenIfPresent(SCR_ID_SYNC_OTA_PROFILE_REPLACE);
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, NULL);   
    DeleteScreenIfPresent(SCR_ID_SYNC_OTA_PROFILE_INSTALL);
    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, (HistoryDelCBPtr)mmi_syncml_otherapp_abort_ota_install);   
    SetKeyHandler(mmi_syncml_exit_install, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_new_ota_profile
 * DESCRIPTION
 *  This function allocates a temporary storage for SYNC profile. And it will 
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx            [IN]            control block for SYNC OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise, 
 *  return -1, i.e., an invalid index.
 *****************************************************************************/
S16 mmi_syncml_new_otap_profile(syncml_ota_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* No more temporary profile storage. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_new_otap_profile()");
    if (cntx->num_profiles == MAX_SYNCML_SV_PROFILES) 
    {
        return -1;
    }
    
    /* Obtain the index. */
    index = cntx->num_profiles;
    
    /* Allocate memory for the profile. */
    cntx->profile[index] = (nvram_ef_syncml_profile_struct *)OslMalloc(sizeof(nvram_ef_syncml_profile_struct));
    if (cntx->profile[index] == NULL) 
    {
        return -1;
    }

    /* Initialize the allocated slim SYNCML profile. */
    mmi_syncml_init_slim_profile(cntx->profile[index]);

    return index;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_slim_profile
 * DESCRIPTION
 *  This function initializes a slim SYNCML profile.
 * PARAMETERS
 *  prof            [OUT]           Profile to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_slim_profile(nvram_ef_syncml_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(prof, 0, sizeof(nvram_ef_syncml_profile_struct));
    mmi_ucs2cpy((S8 *)prof->profile_name, (S8 *)DEFAULT_CCA_PROFILE_NAME);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
void mmi_syncml_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find an empty profile. */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_find_empty_profile()");
    for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
    {
        /* Whether the profile is empty. */
        if (mmi_syncml_is_empty_profile(i) == 1) 
        {
            /* Remember the index of the empty profile. */
            g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = i;
            /* Update Profile List */        
            /*Update profile name to be saved in NVRAM*/
            if(mmi_ucs2cmp((S8*)g_syncml_ota_context->profile[g_syncml_ota_context->iter]->profile_name, (S8*)L"New Profile") == 0)
            {
                mmi_ucs2cpy((S8 *)g_syncml_ota_context->currentprofnamelist[i], 
                        GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + i)));                  
            }                     
            else
            {
                mmi_ucs2cpy((S8 *)g_syncml_ota_context->currentprofnamelist[i], 
                                (S8*)g_syncml_ota_context->profile[g_syncml_ota_context->iter]->profile_name);
            }
            /* Go to the next profile if it is presented. */
            mmi_syncml_next_profile();            
            return;
        }
    }
    /* Can not find a empty profile. Enter profile replacement. */
    mmi_syncml_entry_replacement();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_empty_profile
 * DESCRIPTION
 *  This function examines whether the i-th slot in the profile list is empty.
 * PARAMETERS
 *  i               [IN]            Used to specify i-th profile
 * RETURNS
 *  Return TRUE when profile is empty. Otherwise, return FALSE.
 *****************************************************************************/
U8 mmi_syncml_is_empty_profile(U8 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_syncml_profile_struct *temp_nvram_buf;
    S16 error;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0 ;i<MAX_SYNCML_SV_PROFILES-1 ;i++)
    {
        if(g_syncml_ota_context->dst_idx[i]== record_id)
        {
            return 0;/*pass the selected slot*/
        }
    }
    temp_nvram_buf = (nvram_ef_syncml_profile_struct *)OslMalloc(sizeof(nvram_ef_syncml_profile_struct));
    if(temp_nvram_buf == 0)
    {
        MMI_ASSERT(0);
    }
    ReadRecord(NVRAM_EF_SYNCML_PROFILE_LID, (U16)record_id+1, (void*)temp_nvram_buf, 
        NVRAM_EF_SYNCML_PROFILE_SIZE, &error);  
    if((strcmp((S8 *) temp_nvram_buf->server_address, "http://")== 0)
        &&(strcmp((S8 *) temp_nvram_buf->contact_address, "./")== 0)
        &&(strcmp((S8 *) temp_nvram_buf->calendar_address, "./")== 0))
    /*  &&(temp_nvram_buf->net_id == mmi_dtcnt_get_first_account_id(
      DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI)))*/
    {
        OslMfree(temp_nvram_buf);
        return 1;
    }          
    else
    {
        OslMfree(temp_nvram_buf);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_next_profile
 * DESCRIPTION
 *  This function leads us to process next incoming profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_installed = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_next_profile()");

    /* Increase the index of the iterator to process next profile. */
    g_syncml_ota_context->iter++;

    /* Whether there is another profile needed to be installed. */
    if (g_syncml_ota_context->iter < g_syncml_ota_context->num_profiles) 
    {
        if(g_syncml_ota_context->isvalidprof[g_syncml_ota_context->iter])
        {
            /* Try to install next profile. */
            mmi_syncml_entry_installation();
        }
        else
        {
            mmi_syncml_next_profile();
        }
    } 
    else 
    {
        /* Now, save the profiles in the NVRAM. */
        num_installed = mmi_syncml_install_profiles();

        /* Send a response back to CCA and free memory. */    
        if (num_installed == 0) 
        {
            mmi_syncml_cca_config_rsp(g_syncml_ota_context->conf_id, g_syncml_ota_context->doc_hdl,
                CCA_STATUS_SETTING_SKIPPED);
        } 
        else 
        {
            mmi_syncml_cca_config_rsp(g_syncml_ota_context->conf_id, g_syncml_ota_context->doc_hdl, 
                CCA_STATUS_OK);
        }

        /* Free all allocated memory. */
        mmi_syncml_free_syncml_ota_cntx();

        /* Clear the delete screen callback. */
        ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_replacement
 * DESCRIPTION
 *  This function shows all SYNCML profiles installed on the system such that 
 *  users can select an existing profile to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *prof_name[MAX_SYNCML_SV_PROFILES];
    U8 *gui_buffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_entry_replacement()");

    /* Initialize an invalid used index of an existing profile. */
    g_syncml_ota_context->in_use = -1;   
    if(mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
    {
        g_syncml_ota_context->in_use = g_syncml_context.active_profile -1;
    }
    for(i=0; i<MAX_SYNCML_SV_PROFILES; i++)
    {
    
        if(mmi_ucs2cmp((S8*)g_syncml_ota_context->profile[i]->profile_name, (S8*)L"New Profile") == 0)
        {            
            mmi_ucs2cpy((S8*)g_syncml_ota_context->currentprofnamelist[i], GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + i)));
        }
        prof_name[i] = (U8*)g_syncml_ota_context->currentprofnamelist[i];
    }    

    EntryNewScreen(SCR_ID_SYNC_OTA_PROFILE_REPLACE, NULL, mmi_syncml_entry_replacement, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_SYNC_OTA_PROFILE_REPLACE);

    RegisterHighlightHandler(mmi_syncml_replacement_highlight_hdlr);
    
    ShowCategory53Screen(
        STR_ID_CCA_INSTALL_SETTING,
        IMG_ID_SYNC_SETTINGS,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SYNCML_SV_PROFILES,
        prof_name,
        (U16 *)gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);
    /* Delete screens associated with previous profile. Clear delete screen 
    callback temporarily to prevent from terminating app. */
    //    DeleteScreenIfPresent(SCR_ID_SYNC_OTA_PROFILE_REPLACE);
    //ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, NULL);   
    //DeleteScreenIfPresent(SCR_ID_SYNC_OTA_PROFILE_REPLACE);
    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, (HistoryDelCBPtr)mmi_syncml_otherapp_abort_ota_install);

    SetLeftSoftkeyFunction(mmi_syncml_entry_replacement_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_replacement_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(goback_history_for_replace_screen,KEY_EVENT_UP);
    SetKeyHandler(goback_history_for_replace_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_syncml_exit_install, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_replacement_confirm
 * DESCRIPTION
 *  This function shows a confirmation screen to confirm a replacement.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_replacement_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* The profile is in use. Can't be replaced. */
    if(g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] == g_syncml_ota_context->in_use)
    {
        g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = -1;
        mmi_syncml_show_info(STR_ID_SYNC_ERROR_PROFILE_IN_USE);
        return;
    }

    /* Now, confirm the replacement with the user. */
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SYNC_REPLACE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_replacement_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_exit_install, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_install_profiles
 * DESCRIPTION
 *  This function installs each incoming profile that has been chosen to 
 *  install.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of installed profiles.
 *****************************************************************************/
U8 mmi_syncml_install_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_syncml_profile_struct temp_nvram_buf;    
    S16 error;
    U8 num_installed,total_valid;
    U8 i;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_install_profiles()");

    /* Delete screens associated with the last profile. Clear delete screen
       callback temporarily to prevent from terminating app. */
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, NULL);
    if(IsScreenPresent(SCR_ID_CCA_PROGRESS))
    {
        GoBackToHistory(SCR_ID_CCA_PROGRESS);
    }
    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, (HistoryDelCBPtr)mmi_syncml_otherapp_abort_ota_install);
    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, (HistoryDelCBPtr)mmi_syncml_otherapp_abort_ota_install);    

    /* Install each profile. To make sure the order of installed profiles are
       correct, scan the slots, rather than profiles in the control block. */
    num_installed = 0;
    total_valid = 0;
    for(i=0; i<MAX_SYNCML_SV_PROFILES; i++)
    {
        if(g_syncml_ota_context->isvalidprof[i])
        {
            total_valid++;
        }
    }  
    for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
    {
        /* Continue when no incoming profile plans to install in this slot. */
        if (g_syncml_ota_context->dst_idx[i] < 0) 
        {
            continue;
        }
        if(num_installed == total_valid)
        {
            return num_installed;
        }             
        /* Save profile_id,use_proxy... before write NVRAM. */
        ReadRecord(NVRAM_EF_SYNCML_PROFILE_LID, (U8)(g_syncml_ota_context->dst_idx[i]+1), 
        (void*)&temp_nvram_buf, NVRAM_EF_SYNCML_PROFILE_SIZE, &error);
        g_syncml_ota_context->profile[i]->profile_id = temp_nvram_buf.profile_id;
        g_syncml_ota_context->profile[i]->use_proxy = temp_nvram_buf.use_proxy;
        if(strlen((S8*)g_syncml_ota_context->profile[i]->contact_address) == 0)
        {
            strcpy((S8*)g_syncml_ota_context->profile[i]->contact_address,(S8*) "./");
        }
        if(strlen((S8*)g_syncml_ota_context->profile[i]->calendar_address) == 0)
        {
            strcpy((S8*)g_syncml_ota_context->profile[i]->calendar_address,(S8*) "./");
        }

        /*restore profile name to null*/

        if(mmi_ucs2cmp((S8*)g_syncml_ota_context->profile[i]->profile_name, (S8*)L"New Profile") == 0)
        {     
            mmi_ucs2cpy((S8*)g_syncml_ota_context->profile[i]->profile_name, (S8*)L"");        
        }
        /* Save profile in the NVRAM. */
        WriteRecord(NVRAM_EF_SYNCML_PROFILE_LID, (U8)(g_syncml_ota_context->dst_idx[i]+1), 
        (void*)g_syncml_ota_context->profile[i], NVRAM_EF_SYNCML_PROFILE_SIZE, &error);
        if (error != NVRAM_WRITE_SUCCESS) 
        {
            MMI_ASSERT(0);
        }

        /* Install successfully. Update counter. */        
        num_installed++;
    }
    return num_installed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_replacement_highlight_hdlr
 * DESCRIPTION
 *  This highlight handler remembers the item chosen to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_replacement_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter]= index;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_show_info
 * DESCRIPTION
 *  This function shows a notification screen with the specified message.
 * PARAMETERS
 *  msg_id          [IN]            Message to be shown
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_show_info(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DisplayPopup(
        (U8 *)GetString(msg_id),
        IMG_GLOBAL_INFO,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        WARNING_TONE);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_replacement_save
 * DESCRIPTION
 *  This function saves the information to replace an existing profile with
 *  the current provisioned one.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_replacement_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Update Profile List */
    mmi_ucs2cpy((S8 *)g_syncml_ota_context->currentprofnamelist[g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter]], 
        (S8 *)g_syncml_ota_context->profile[g_syncml_ota_context->iter]->profile_name);      
    
    /* Go to the next profile if it is presented. */
    mmi_syncml_next_profile();
}
/*****************************************************************************
 * FUNCTION
 *  goback_history_for_replace_screen
 * DESCRIPTION
 *  This function will clear the  and gobackhistory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goback_history_for_replace_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter]= -1;  /*restore -1*/
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, NULL);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  Is_ANSII_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest             [IN]     
 *  dest_size        [IN]     
 * RETURNS 0,1
 *  
 *****************************************************************************/
U8 Is_ANSII_format(S8 *dest ,kal_int32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *p = dest;  
    U8 ansii_max_value = 127;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(*p != '\0')
    {
        if(*p < ansii_max_value )
        {
            p++;
        }     
        else
        {
            return 0;
        }
    }

    return 1;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_install
 * DESCRIPTION
 *  This function will end current install and return to IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_exit_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_INSTALL, NULL);
    ClearDelScrnIDCallbackHandler(SCR_ID_SYNC_OTA_PROFILE_REPLACE, NULL);
    mmi_syncml_cca_config_rsp(g_syncml_ota_context->conf_id, g_syncml_ota_context->doc_hdl, 
    CCA_STATUS_ENDKEY_PRESSED);
    mmi_syncml_free_syncml_ota_cntx();
    GoBackToHistory(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_display_skip_confirm
 * DESCRIPTION
 *  Display skip confirmation screen, but can goback history to this screen.
 * PARAMETERS
 *  strId           [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_syncml_display_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_OTA_SKIP_CONFIRM, NULL, NULL, NULL);

        ShowCategory164Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            STR_ID_CCA_SKIP_PROFILE,
            IMG_GLOBAL_QUESTION,
            NULL);

    SetLeftSoftkeyFunction(mmi_syncml_next_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_construct_cca_document_for_dm
 * DESCRIPTION
 *  This function construct cca document for DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_syncml_construct_cca_document_for_dm(U16 app_id, S32 prof_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_get_prof_rsp_struct *data;

    S32 hconfig, hroot, hnode ,temnode,connect_type;
    nvram_ef_syncml_profile_struct dm_profile;
    U8 temp[MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
    S8 tempint[10];
    S8 temp_ip_addr[MAX_PROXY_IP_ADDR_LEN];
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("come mmi_syncml_construct_cca_document_for_dm()__");
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_construct_cca_document_for_dm()");

    mmi_syncml_read_profile_from_nvram((U8)prof_id, &dm_profile);
    hroot = mmi_cca_doc_new_rootnode();
    if (!hroot)
    {
        MMI_ASSERT(0);
    }

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PROXY, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }

        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_NODEID, "PROXY_1");
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PROXY_ID, "PROXY_1");
        temp_ip_addr[0] = 0;
        for(i =0;i<4;i++)
        {
            syncml_itoa((S32) dm_profile.proxy_ip[i], (S8*)tempint, 10);
            strcat(temp_ip_addr,tempint);
            if(i < 3)
            {     
                strcat(temp_ip_addr,".");
            }
        }        
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXADDR, (S8*)temp_ip_addr);
        mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);
        mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_DATAACCTID, (S32)dm_profile.net_id);   

    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PORT, temnode);
        syncml_itoa((S32)dm_profile.proxy_port, (S8*)(tempint), (S32)10);
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PORTNBR, (S8*)tempint);
        connect_type = (dm_profile.conn_type == SYNCML_TRANS_HTTP) ? CCA_NS_VAL_OTA_HTTP_TO : CCA_NS_VAL_CL_WSP;
        mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_SERVICE, (S32)connect_type );    

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PXAUTHINFO, temnode);
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXAUTH_ID, (S8*)dm_profile.proxy_username);    
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXAUTH_PW, (S8*)dm_profile.proxy_password);  
    
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPLICATION, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }
        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_NODEID , "APPLICATION_1");
        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_APPID, "w5");

        mmi_chset_ucs2_to_utf8_string((U8*) temp,                        
                        MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
                        (U8*)dm_profile.profile_name);

        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_NAME ,(S8*)temp);
        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_TO_PROXY , "PROXY_1");
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPADDR, temnode);  
        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_ADDR , (S8*)dm_profile.server_address);

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPAUTH, temnode);  
        mmi_cca_doc_add_nodedata_int (hnode,CCA_NS_OMA_AAUTHLEVEL , CCA_NS_VAL_CLIENT);
        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_AAUTHNAME , (S8*)dm_profile.server_username);
        mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_AAUTHSECRET , (S8*)dm_profile.server_password);

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (S8 *)"text/x-vcard");
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (S8*)dm_profile.contact_address);
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (S8*)dm_profile.contact_username);
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (S8*)dm_profile.contact_password);       

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (S8*)"text/x-vcalendar");
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (S8*)dm_profile.calendar_address);
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (S8*)dm_profile.calendar_username);
        mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (S8*)dm_profile.calendar_password);

    hconfig = mmi_cca_doc_new (hroot);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_get_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
    data->app_id = app_id;
    data->prof_id = prof_id; 
    data->hConfig = hconfig;
    data->result = CCA_STATUS_OK;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_GET_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    kal_printf("data->hConfig  = %d");    
    OslMsgSendExtQueue(&message);    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_install_cca_document_from_dm
 * DESCRIPTION
 *  This function install the new setting into NVRAM from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_syncml_install_cca_document_from_dm(U16 app_id, S32 prof_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_update_prof_rsp_struct *data;
    nvram_ef_syncml_profile_struct temp_nvram_buf;    
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    const U16 proc_tbl[] = 
     {
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY, 
            CCA_NS_SYNCML_PROXY,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PORT, 
            CCA_NS_SYNCML_PORT,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_PROXY,CCA_NS_OMA_PXAUTHINFO, 
            CCA_NS_SYNCML_PXAUTHINFO,0xFFFF,            
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION, 
            CCA_NS_SYNCML_APPLICATION,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPADDR,
            CCA_NS_SYNCML_APPADDR,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_APPAUTH, 
            CCA_NS_SYNCML_APPAUTH,0xFFFF,
        CCA_NS_TRIGNODE,CCA_NS_OMA_APPLICATION,CCA_NS_OMA_RESOURCE,
            CCA_NS_SYNCML_RESOURCE,0xFFFF
     };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML][provisioning & DM]mmi_syncml_install_cca_document_from_dm()"); 
    g_syncml_ota_context = mmi_syncml_new_ota_cntx(0, hConfig);   

    if (g_syncml_ota_context == NULL) 
    {
        MMI_ASSERT(0);
    }
    mmi_cca_doc_process(hConfig, 
                        proc_tbl,
                        sizeof(proc_tbl) / sizeof(U16),
                        NULL, 
                        mmi_syncml_proc_cca_nodes, 
                        g_syncml_ota_context);
    if (mmi_syncml_get_valid_profile_num() == 0) 
    {        
        /*do nothing*/
    }
    else
    {
    /* Save profile_id,use_proxy... before write NVRAM. */
    ReadRecord(NVRAM_EF_SYNCML_PROFILE_LID, (U8)(prof_id), 
            (void*)&temp_nvram_buf, NVRAM_EF_SYNCML_PROFILE_SIZE, &error);
    g_syncml_ota_context->profile[0]->profile_id = 0;
    g_syncml_ota_context->profile[0]->use_proxy = temp_nvram_buf.use_proxy;
    WriteRecord(NVRAM_EF_SYNCML_PROFILE_LID, (U8)(prof_id), 
        (void*)g_syncml_ota_context->profile[0], NVRAM_EF_SYNCML_PROFILE_SIZE, &error);
        if (error != NVRAM_WRITE_SUCCESS) 
        {
            MMI_ASSERT(0);
        }
    }
    mmi_syncml_free_syncml_ota_cntx();
    data = (mmi_cca_app_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = CCA_STATUS_OK;
        
    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_UPDATE_PROF_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_checking_for_dm
 * DESCRIPTION
 *  This function used to check whether hanset can receive the new setting from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  0,1
 *****************************************************************************/

S32 mmi_syncml_checking_for_dm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
       	  ||(GetActiveScreenId() == SCR_ID_SYNC_SETTINGS) 
	         ||(IsScreenPresent(SCR_ID_SYNC_SETTINGS)))
    {
        return 0x0;
    }
    else
    {
        return 0x1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  syncml_atoi_for_ipaddr
 * DESCRIPTION
 *  This function used for ip addr.
 * PARAMETERS
 *  void
 * RETURNS
 *  0,1
 *****************************************************************************/
S32 syncml_atoi_for_ipaddr(const S8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n = 0;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((s[i] != '.')&&(s[i] != '\0'))
    {
        n *= 10;
        n += s[i] - '0';
        i++;
    }
    return n;
}

static void mmi_syncml_cca_config_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
    data->config_id = conf_id;
    data->hConfig   = doc_hdl;
    data->status    = status;
    /*
#ifdef __MMI_DUAL_SIM__
    data->sim_id = MMI_CCA_SIM_ID_DEFAULT;
#endif
    */

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;

    OslMsgSendExtQueue(&message);
}

#endif




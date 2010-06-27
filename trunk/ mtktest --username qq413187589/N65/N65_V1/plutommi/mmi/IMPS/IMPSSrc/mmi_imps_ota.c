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

/*******************************************************************************
 * Filename:
 * ---------
 * mmi_imps_ota.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements ota related function/interface for IMPS application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_IMPS_OTA__


#include "CommonScreens.h"


#include "wgui_inline_edit.h"
#include "wgui_tab_bars.h"

#include "Conversions.h"
#include "custom_data_account.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"

#include "CentralConfigAgentGProt.h"

#define IMPS_MAX_OTA_INFO_LEN  (512)  /* length of buffer for compose ota info */

static const U16 cca_mapping_imps[] = 
{
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, MMI_IMPS_NS_OMA_PROXY, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, MMI_IMPS_NS_OMA_APP, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, MMI_IMPS_NS_OMA_PXAUTHINFO, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, MMI_IMPS_NS_OMA_PORT, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH, MMI_IMPS_NS_OMA_APPAUTH, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR, MMI_IMPS_NS_OMA_APPADDR, 0xFFFF,
};

static cca_status_enum mmi_imps_ota_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);
static cca_status_enum mmi_imps_ota_parse_proxy(cca_iterator_struct *data, void *user_data);
static cca_status_enum mmi_imps_ota_parse_app(cca_iterator_struct *data, void *user_data);

static cca_status_enum mmi_imps_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_imps_ota_handle_port_params(S32 hNode, void *user_data);
static cca_status_enum mmi_imps_ota_handle_pxauthinfo_params(S32 hNode, void *user_data);
static cca_status_enum mmi_imps_ota_handle_app_params(cca_core_data_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_imps_ota_handle_appaddr_params(S32 hNode, void *user_data);
static cca_status_enum mmi_imps_ota_handle_appauth_params(S32 hNode, void *user_data);

static MMI_BOOL mmi_imps_ota_create_prof(MMI_BOOL is_proxy);
static void mmi_imps_pre_entry_ota_setting(void);
static void mmi_imps_entry_ota_setting(void);
static void mmi_imps_entry_ota_prof_list(void);
static void mmi_imps_ota_install_yes(void);
static void mmi_imps_ota_install(void);
static MMI_BOOL mmi_imps_ota_get_next(void);
static void mmi_imps_ota_skip_confirm(void);
static void mmi_imps_ota_skip_yes(void);

static void mmi_imps_ota_free_info(void);
static void mmi_imps_ota_free_prof(U8 index);
static S16 mmi_imps_ota_get_proxy_index(const S8 *px_id);
static void mmi_imps_ota_compose_app_proxy(U8 dest_index, S16 src_index);

static MMI_BOOL mmi_imps_ota_is_valid_proxy(mmi_imps_ota_prof_struct *prof);
static MMI_BOOL mmi_imps_ota_proxy_existed(S8 *px_id);
static void mmi_imps_ota_is_valid_info(void);
static MMI_BOOL mmi_imps_is_ascii_string(const U8 *utf8_str);
static MMI_BOOL mmi_imps_check_ip(U8 *ip, S8 *data, S32 len);
static MMI_BOOL mmi_imps_ota_is_use_proxy(const U8 *data);

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_send_cca_conf_rsp
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  status      [IN]        Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_send_cca_conf_rsp(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(
                                                sizeof(mmi_cca_app_configure_rsp_struct));
    
    data->config_id = imps_p->ota_prof->config_id;
    data->hConfig = imps_p->ota_prof->hConfig;
    data->status = status;

    /* Send the response message. */
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr = (oslParaType*) data;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_handle_ota
 * DESCRIPTION
 *  handle CCA document
 * PARAMETERS
 *  config_id       [IN]        CCA configuration ID
 *  hConfig         [IN]        Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_handle_ota(U16 config_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_process(
        hConfig,
        cca_mapping_imps,
        sizeof(cca_mapping_imps) / sizeof(U16),
        NULL,
        mmi_imps_ota_process_callback_nodes,
        NULL);

    mmi_imps_ota_is_valid_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_process_callback_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  hConfig             [IN]        Configuration document handle
 *  hNode               [IN]        The node handle
 *  node_symbol         [IN]        The converted node symbol
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  If there is no empty ota profile return CCA_STATUS_FAIL;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case MMI_IMPS_NS_OMA_PROXY:
            mmi_imps_ota_parse_proxy(iter_datalist, user_data);
            break;

        case MMI_IMPS_NS_OMA_APP:
            mmi_imps_ota_parse_app(iter_datalist, user_data);
            break;

        case MMI_IMPS_NS_OMA_PORT:
	        status = mmi_imps_ota_handle_port_params(hNode, user_data);
			if (status != CCA_STATUS_OK)
			{
				imps_p->ota_prof->is_curr_store = MMI_FALSE;
				mmi_imps_ota_free_prof(imps_p->ota_prof->curr_index);
			}
            break;

        case MMI_IMPS_NS_OMA_PXAUTHINFO:
            status = mmi_imps_ota_handle_pxauthinfo_params(hNode, user_data);
			if (status != CCA_STATUS_OK)
			{
				imps_p->ota_prof->is_curr_store = MMI_FALSE;
				mmi_imps_ota_free_prof(imps_p->ota_prof->curr_index);
			}
            break;

        case MMI_IMPS_NS_OMA_APPADDR:
            status = mmi_imps_ota_handle_appaddr_params(hNode, user_data);
			if (status != CCA_STATUS_OK)
			{
				for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
				{
					if (imps_p->ota_prof->app_prof_index[i])
					{
						imps_p->ota_prof->info[i]->is_valid = MMI_FALSE;
					}
				}
			}
            break;

        case MMI_IMPS_NS_OMA_APPAUTH:
            status = mmi_imps_ota_handle_appauth_params(hNode, user_data);
			if (status != CCA_STATUS_OK)
			{
				for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
				{
					if (imps_p->ota_prof->app_prof_index[i])
					{
						imps_p->ota_prof->info[i]->is_valid = MMI_FALSE;
					}
				}
			}
            break;

        default: 
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_parse_proxy
 * DESCRIPTION
 *  The function used to parse proxy node.
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_parse_proxy(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    S8 **px_id;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->is_curr_store = MMI_TRUE;

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROXY_ID, &px_id, &size);

    /* one proxy should has only one prxoy id */
    if (status != CCA_STATUS_OK || size != 1)
    {
        imps_p->ota_prof->is_curr_store = MMI_FALSE;
        return CCA_STATUS_FAIL;
    }
    /* judghe whether this proxy has existed for we only support the first valid proxy for same proxy id */
    if (mmi_imps_ota_proxy_existed(px_id[0]))
    {
        imps_p->ota_prof->is_curr_store = MMI_FALSE;
        return CCA_STATUS_FAIL;
    }

    mmi_cca_iterator_restart(iter_datalist);

    if (mmi_imps_ota_create_prof(MMI_TRUE))
    {
        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
            status = mmi_imps_ota_handle_proxy_params(data, user_data);
            if (status != CCA_STATUS_OK)
            {
                break;
            }
        }

		if (status != CCA_STATUS_OK)
		{
			/* if current proxy node is invalid, set flag to not store its child node */
            imps_p->ota_prof->is_curr_store = MMI_FALSE;
            mmi_imps_ota_free_prof(imps_p->ota_prof->curr_index);
            return status;
		}

        if (!mmi_imps_ota_is_valid_proxy(imps_p->ota_prof->info[imps_p->ota_prof->curr_index]))
        {
            /* if current proxy node is invalid, set flag to not store its child node */
            imps_p->ota_prof->is_curr_store = MMI_FALSE;
            mmi_imps_ota_free_prof(imps_p->ota_prof->curr_index);
        }
    }
    else
    {
        status = CCA_STATUS_MEMFULL;

        /* if profile memory full, set flag to not store its child node */
        imps_p->ota_prof->is_curr_store = MMI_FALSE;
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_proxy_params
 * DESCRIPTION
 *  Handle CCA PROXY node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
	U8 dataacct_type;
    mmi_imps_ota_prof_struct *prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;
            }

	        /* Whether this is a ASCII string. */
            if (!mmi_imps_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }
			
            /* Check whether the length of the proxy id is legal. */
            str_len = strlen(data->values.s[0]);
            if (str_len + 1 > IMPS_MAX_PROXY_ID_LEN)
            {
                strncpy((S8*)prof->proxy_id, data->values.s[0], IMPS_MAX_PROXY_ID_LEN - 1);
            }
            else
            {
                strcpy((S8*)prof->proxy_id, data->values.s[0]);
            }

            break;

        case CCA_NS_OMA_PXADDR:
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;
            }

			/* Whether this is a ASCII string. */
            if (!mmi_imps_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the proxy server is legal. */
            str_len = strlen(data->values.s[0]);
            
            if (!mmi_imps_check_ip((U8*)&prof->prof_info.proxy_ip, data->values.s[0], str_len))
            {
                return CCA_STATUS_FAIL;
            }
            else
            {
                prof->prof_info.use_proxy = MMI_TRUE;
            }

            break;

        case CCA_NS_DATAACCTID:
            if (data->size <= 0 || data->type != CCA_DT_INT)
            {
                return CCA_STATUS_FAIL;
            }
			
			dataacct_type = mmi_dtcnt_get_bearer_type((U8)data->values.i[0]);
			if ((dataacct_type & IMPS_DATA_ACCOUNT_TYPE) == 0)
			{
				return CCA_STATUS_FAIL;
			}

            prof->prof_info.dt_acct = data->values.i[0];

            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_port_params
 * DESCRIPTION
 *  Handle CCA port node paramters
 * PARAMETERS
 *  hNode           [IN]        CCA handler
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_port_params(S32 hNode, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 port;
    S32 str_len;
    S32 service;
    S8 *str_port = NULL;
    S8  temp[IMPS_PROF_PORT_LEN];
    cca_status_enum port_result;
    cca_status_enum service_result;
    mmi_imps_ota_prof_struct *prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (!imps_p->ota_prof->is_curr_store)
    {
        return CCA_STATUS_OK;
    }

	port_result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_PORTNBR, &str_port);
    if (port_result == CCA_STATUS_OK)
    {
		str_len = strlen(str_port);
      
        if (str_len + 1 > IMPS_PROF_PORT_LEN)
        {
            strncpy(temp, str_port, IMPS_PROF_PORT_LEN - 1);
	        temp[IMPS_PROF_PORT_LEN - 1] = 0;
            str_len = IMPS_PROF_PORT_LEN - 1;
        } 
        else
        {
        	strcpy(temp, str_port);
        }
		
        for (i = 0; i < str_len; i++)
        {
            /* Whether data is decimal number. */
            if (str_port[i] < '0' || str_port[i] > '9')
            {
                return CCA_STATUS_FAIL;
            }
        }   

        port = (S32)atoi(temp);
        
        /* Check whether value of port is legal. */
        if (port < 0 || port > 65535)
        {
            return CCA_STATUS_FAIL;
        }

        prof->prof_info.proxy_port = (U16)port;
    }
    else
    {
        return CCA_STATUS_FAIL;
    }

    service_result = mmi_cca_doc_nodedata_int_first(hNode, CCA_NS_OMA_SERVICE, (S32*)&service);

    if (service_result == CCA_STATUS_OK)
    {
        switch (service)
        {
            case CCA_NS_VAL_CL_WSP:
            case CCA_NS_VAL_CO_WSP:            
                prof->prof_info.conn_type = 1;
                break;

            case CCA_NS_VAL_OTA_HTTP_TO:
            case CCA_NS_VAL_OTA_HTTP_TLS_TO:
            case CCA_NS_VAL_OTA_HTTP_PO:
            case CCA_NS_VAL_OTA_HTTP_TLS_PO:
                prof->prof_info.conn_type = 0;
                break;

            default:
                return CCA_STATUS_FAIL;
        }
    }
    else
    {
        switch (port)
        {
            case 9200:                          /* WSP_CL */
            case 9201:                          /* WSP_CO */
                prof->prof_info.conn_type = 1;            
                break;
				
            default:
                prof->prof_info.conn_type = 0;  /* HTTP */
                break;
        }
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_pxauthinfo_params
 * DESCRIPTION
 *  Handle CCA proxy authorization parameters
 * PARAMETERS
 *  hNode           [IN]        CCA handler
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_pxauthinfo_params(S32 hNode, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    cca_status_enum result;
    S8 *value = NULL;
    mmi_imps_ota_prof_struct *prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!imps_p->ota_prof->is_curr_store)
    {
        return CCA_STATUS_OK;
    }

    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_PXAUTH_ID, &value);
    if (result == CCA_STATUS_OK)
    {
        /* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }
	
        /* Check whether the length of the proxy id is legal. */
        str_len = strlen(value);
        if (str_len + 1 > IMPS_MAX_PROXY_USERNAME_LEN)
        {
           strncpy((S8*)prof->prof_info.proxy_username, value, IMPS_MAX_PROXY_USERNAME_LEN - 1);
        }
        else
        {
	       strcpy((S8*)prof->prof_info.proxy_username, value);
        }
	}

    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_PXAUTH_PW, &value);
    if (result == CCA_STATUS_OK)
    {
       /* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }

        /* Check whether the length of the proxy password is legal. */
        str_len = strlen(value);
        if (str_len + 1 > IMPS_MAX_PROXY_PASSWORD_LEN)
        {
            strncpy((S8*)prof->prof_info.proxy_passwd, value, IMPS_MAX_PROXY_PASSWORD_LEN - 1);
        }
        else
        {
        	strcpy((S8*)prof->prof_info.proxy_passwd, value);
        }
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_parse_app
 * DESCRIPTION
 *  The function used to parse app node.
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_parse_app(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    S8 **px_id;
    S32 size;
    cca_status_enum status = CCA_STATUS_OK;
    S16 index = -1;
    U8 i, j;
    MMI_BOOL same_proxy = MMI_FALSE;
    S32 str_len;
    S8 temp[IMPS_MAX_PROXY_ID_LEN];
    mmi_imps_ota_prof_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 2 * IMPS_PROF_COUNT; i++)
    {
        prof = imps_p->ota_prof->info[i];

        imps_p->ota_prof->app_prof_index[i] = MMI_FALSE;

        if (prof != NULL && prof->is_used && (!prof->is_valid || prof->prof_info.server[0] == '\0'))
        {
            prof->is_used = MMI_FALSE;
            prof->is_valid = MMI_TRUE;

            if (prof->is_proxy)
            {
                memset(&prof->prof_info.prof_name, 0, IMPS_PROF_NAME_LEN * sizeof(UI_character_type));
                memset(&prof->prof_info.server, 0, IMPS_MAX_SERVER_ADDRESS_LEN);
                memset(&prof->prof_info.username, 0, IMPS_MAX_USERID_LEN);
                memset(&prof->prof_info.passwd, 0, IMPS_MAX_PASSWORD_LEN);
                prof->prof_info.auto_login = MMI_FALSE;
                
                prof->is_app_addr = MMI_FALSE;
                prof->is_app_auth = MMI_FALSE;
            }
            else
            {
                OslMfree(imps_p->ota_prof->info[i]);
                imps_p->ota_prof->info[i] = NULL;
                imps_p->ota_prof->total--;
            }
        }
    }

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_TO_PROXY, &px_id, &size);

    /* exist related proxy */
    if (status == CCA_STATUS_OK)
    {
        for (i = 0; i < size; i++)
        {
            /* judge whether this app include same proxy id */
            for (j = 0; j < i - 1; j++)
            {
                if (strcmp(px_id[j], px_id[i]) == 0)
                {
                    same_proxy = MMI_TRUE;
                    break;
                }
            }
            /* the app node has include this proxy node */
            if (same_proxy)
            {
                continue;
            }

            memset(temp, 0, IMPS_MAX_PROXY_ID_LEN);
            str_len = strlen(px_id[i]);
            if (str_len + 1 > IMPS_MAX_PROXY_ID_LEN)
            {
                strncpy((S8*)temp, px_id[i], IMPS_MAX_PROXY_ID_LEN - 1);
            }
            else
            {
                strcpy((S8*)temp, px_id[i]);
            }

            index = mmi_imps_ota_get_proxy_index((S8*)temp);

            /* find related proxy */
            if (index >= 0  && index < IMPS_PROF_COUNT)
            {
                /* this proxy has been used, that happened when one proxy used for mulitple app */
                if (imps_p->ota_prof->info[index]->is_used)
                {
                    /* create a new profile to store information */
                    if (mmi_imps_ota_create_prof(MMI_FALSE))
                    {
                        /* set flag for app child node can be store in this profile */
                        imps_p->ota_prof->app_prof_index[imps_p->ota_prof->curr_index] = MMI_TRUE;

                        imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_used = MMI_TRUE;
                        mmi_imps_ota_compose_app_proxy(imps_p->ota_prof->curr_index, index);
                    }
                }
                else
                {
                    /* set flag for app child node can be store in this profile */
                    imps_p->ota_prof->app_prof_index[index] = MMI_TRUE;
                    imps_p->ota_prof->info[index]->is_used = MMI_TRUE;
                }
            }
            else
            {
                return CCA_STATUS_FAIL;
            }
        }
    }
    else
    {
        if (mmi_imps_ota_create_prof(MMI_FALSE))
        {
            /* set flag for app child node can be store in this profile */
            imps_p->ota_prof->app_prof_index[imps_p->ota_prof->curr_index] = MMI_TRUE;
            imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_used = MMI_TRUE;
        }
        else
        {
            return CCA_STATUS_MEMFULL;

        }
    }

    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = mmi_imps_ota_handle_app_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_app_params
 * DESCRIPTION
 *  Handle CCA application node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_app_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    s32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_NAME:
            /* Whether the value is presented and the type is legal. If it's
               illegal, default name will be used. Still return OK. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
            {
                if (imps_p->ota_prof->app_prof_index[i])
                {
                    mmi_chset_utf8_to_ucs2_string(
                        (U8*)imps_p->ota_prof->info[i]->prof_info.prof_name,
                        IMPS_PROF_NAME_LEN * ENCODING_LENGTH,
                        (U8*)data->values.s[0]);
                }
            }
            break;

        case CCA_NS_OMA_ADDR:
			/* regard the first valid addr as profile server address */
            for (i = 0; i < data->size; i++)
            {
                if (data->type != CCA_DT_STR)
                    continue;

				/* Whether this is a ASCII string. */
                if (!mmi_imps_is_ascii_string((U8*)data->values.s[i]))
                {
                    continue;
                }

                /* Check whether the length of the server is legal. */
                str_len = strlen(data->values.s[i]);                               

                for (j = 0; j < IMPS_PROF_COUNT * 2; j++)
                {
                    if (imps_p->ota_prof->app_prof_index[j])
                    {
						if (str_len + 1 > IMPS_MAX_SERVER_ADDRESS_LEN)
						{
							strncpy((S8*)imps_p->ota_prof->info[j]->prof_info.server, data->values.s[i], 
								IMPS_MAX_SERVER_ADDRESS_LEN - 1);
						}
						else
						{
							strcpy((S8*)imps_p->ota_prof->info[j]->prof_info.server, data->values.s[i]);
						}
                    }
                }

                break;
            }
            break;

        default:
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_appaddr_params
 * DESCRIPTION
 *  Handle CCA application address node parameters
 * PARAMETERS
 *  hNode           [IN]        CCA handler
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_appaddr_params(S32 hNode, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    cca_status_enum result;
    S8 *value = NULL;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_ADDR, &value);
    if (result == CCA_STATUS_OK)
    {
        /* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }

        str_len = strlen(value);
		
        for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
        {
            if (imps_p->ota_prof->app_prof_index[i])
            {
				/* regard the first valid addr as profile server address */
                if (!imps_p->ota_prof->info[i]->is_app_addr)
                {                                     
					if (str_len + 1 > IMPS_MAX_SERVER_ADDRESS_LEN)
					{
						strncpy((S8*)imps_p->ota_prof->info[i]->prof_info.server, value, 
							IMPS_MAX_SERVER_ADDRESS_LEN - 1);
					}
					else
					{
       					strcpy((S8*)imps_p->ota_prof->info[i]->prof_info.server, value);
					}
                    
                    imps_p->ota_prof->info[i]->is_app_addr = MMI_TRUE;
                }
            }
        }
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_appauth_params
 * DESCRIPTION
 *  Handle CCA application authorization parameters
 * PARAMETERS
 *  hNode           [IN]        CCA handler
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_appauth_params(S32 hNode, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    cca_status_enum result;
    S8 *value = NULL;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_AAUTHNAME, &value);
    if (result == CCA_STATUS_OK)
    {
		/* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }

        /* Check whether the length of the proxy id is legal. */
        str_len = strlen(value);        

        /* Obtain the username. Zero-terminate username. */
        for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
        {
            if (imps_p->ota_prof->app_prof_index[i])
            {
                if (!imps_p->ota_prof->info[i]->is_app_auth)
                {
                    if (str_len + 1 > IMPS_MAX_USERID_LEN)
					{
						strncpy((S8*)imps_p->ota_prof->info[i]->prof_info.username, value, 
							IMPS_MAX_USERID_LEN - 1);
					}
					else
					{
						strcpy((S8*)imps_p->ota_prof->info[i]->prof_info.username, value);
					}

                    imps_p->ota_prof->info[i]->is_app_auth = MMI_TRUE;
                }
            }
        }
    }

    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_AAUTHSECRET, &value);
    if (result == CCA_STATUS_OK)
    {
		/* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }

        /* Check whether the length of the proxy password is legal. */
        str_len = strlen(value);        

        /* Obtain the password. Zero-terminate password. */
        for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
        {
            if (imps_p->ota_prof->app_prof_index[i])
            {
				if (str_len + 1 > IMPS_MAX_PASSWORD_LEN)
				{
					strncpy((S8*)imps_p->ota_prof->info[i]->prof_info.passwd, value, 
						IMPS_MAX_PASSWORD_LEN - 1);
				}
				else
				{
					strcpy((S8*)imps_p->ota_prof->info[i]->prof_info.passwd, value);
				}
            }
        }
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_init
 * DESCRIPTION
 *  Initialize OTA structure
 * PARAMETERS
 *  config_id       [IN]        CCA configure ID
 *  hConfig         [IN]        Handler of CCA document
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ota_init(U16 config_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 	
    MMI_ASSERT (imps_p->ota_prof == NULL);

    imps_p->ota_prof = (mmi_imps_ota_info_struct*) OslMalloc(sizeof(mmi_imps_ota_info_struct));
    memset(imps_p->ota_prof, 0, sizeof(mmi_imps_ota_info_struct));
    imps_p->ota_prof->config_id = config_id;
    imps_p->ota_prof->hConfig = hConfig;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_create_prof
 * DESCRIPTION
 *  Find free OTA profile slot and allocate memory.
 * PARAMETERS
 *  is_proxy        [IN]        Whether there is proxy
 * RETURNS
 *  If there is free OTA profile slot, return MMI_TRUE,
 *  Otherwise return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_create_prof(MMI_BOOL is_proxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    U8 used = 0;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i] == NULL)
        {
            break;
        }
    }

    index = i;

    if (i == IMPS_PROF_COUNT)
    {
        for (j = 0; j < IMPS_PROF_COUNT * 2; j++)
        {
            if (imps_p->ota_prof->info[j] && imps_p->ota_prof->info[j]->is_used)
            {
                used++;
            }
        }
        /* this process some profile has only proxy and no app, we just save app to 
        new profile, then matching it later */
        if (used < IMPS_PROF_COUNT && !is_proxy)
        {
            for (j = IMPS_PROF_COUNT; j < 2 * IMPS_PROF_COUNT; j++)
            {
                if (imps_p->ota_prof->info[j] == NULL)
                {
                    break;
                }
            }

             if (j == 2 * IMPS_PROF_COUNT)
             {
        return MMI_FALSE;
             }
             else
             {
                 index = j;
             }
        }
        else
        {
            return MMI_FALSE;
        }
    }

    imps_p->ota_prof->total++;
    imps_p->ota_prof->curr_index = index;

    imps_p->ota_prof->info[index] = (mmi_imps_ota_prof_struct*) OslMalloc(sizeof(mmi_imps_ota_prof_struct));
    memset(imps_p->ota_prof->info[index], 0, sizeof(mmi_imps_ota_prof_struct));

    imps_p->ota_prof->info[index]->is_proxy = is_proxy;
	imps_p->ota_prof->info[index]->is_valid = MMI_TRUE;

    imps_p->ota_prof->info[index]->prof_info.dt_acct = CUSTOM_DEFAULT_IMPS_DTCNT_ID;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_free_info
 * DESCRIPTION
 *  Free OTA memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_free_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL)
    {
        return;
    }

    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i])
        {
            OslMfree(imps_p->ota_prof->info[i]);
            imps_p->ota_prof->info[i] = NULL;
        }
    }

    OslMfree(imps_p->ota_prof);
    imps_p->ota_prof = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_free_prof
 * DESCRIPTION
 *  Free OTA memory
 * PARAMETERS
 *  index       [IN]        Profile index to be free
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_free_prof(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL)
    {
        return;
    }

    if (imps_p->ota_prof->info[index])
    {
        OslMfree(imps_p->ota_prof->info[index]);
        imps_p->ota_prof->info[index] = NULL;
        imps_p->ota_prof->total--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_get_proxy_index
 * DESCRIPTION
 *  Find relevant profile according proxy_id that relate proxy with application.
 * PARAMETERS
 *  px_id       [IN]        ID used to relate proxy with application
 * RETURNS
 *  If find related profile succesfully, return index of profile.
 *  otherwise return 0xFF.
 *****************************************************************************/
static S16 mmi_imps_ota_get_proxy_index(const S8 *px_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i] && imps_p->ota_prof->info[i]->is_proxy)
        {
            if (strcmp((S8*)imps_p->ota_prof->info[i]->proxy_id, px_id) == 0)
            {
                return i;
            }
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_compose_app_proxy
 * DESCRIPTION
 *  compose application node and proxynode
 * PARAMETERS
 *  dest_index      [IN]        Index of destination profile
 *  src_index       [IN]        Index of source profile
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_compose_app_proxy(U8 dest_index, S16 src_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_prof_struct *src_prof;
    mmi_imps_ota_prof_struct *dest_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest_index > IMPS_PROF_COUNT)
    {
        MMI_ASSERT(0);
        return;
    }

    if (src_index > IMPS_PROF_COUNT)
    {
        MMI_ASSERT(0);
        return;
    }

    src_prof = imps_p->ota_prof->info[src_index];
    dest_prof = imps_p->ota_prof->info[dest_index];

    dest_prof->prof_info.use_proxy = src_prof->prof_info.use_proxy;

    /* proxy server */
    if (src_prof->prof_info.use_proxy)
    {
        dest_prof->prof_info.proxy_ip[0] = src_prof->prof_info.proxy_ip[0];
        dest_prof->prof_info.proxy_ip[1] = src_prof->prof_info.proxy_ip[1];
        dest_prof->prof_info.proxy_ip[2] = src_prof->prof_info.proxy_ip[2];
        dest_prof->prof_info.proxy_ip[3] = src_prof->prof_info.proxy_ip[3];
    }

    /* proxy username */
    if (src_prof->prof_info.proxy_username[0])
    {
        strcpy((S8*)dest_prof->prof_info.proxy_username, (S8*)src_prof->prof_info.proxy_username);
    }

    /* proxy password */
    if (src_prof->prof_info.proxy_passwd[0])
    {
        strcpy((S8*)dest_prof->prof_info.proxy_passwd, (S8*)src_prof->prof_info.proxy_passwd);
    }

    /* data account */
    dest_prof->prof_info.dt_acct = src_prof->prof_info.dt_acct;

    /* port number */
    dest_prof->prof_info.proxy_port = src_prof->prof_info.proxy_port;

    /* connect type */
    dest_prof->prof_info.conn_type = src_prof->prof_info.conn_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_abort
 * DESCRIPTION
 *  This function should be called to exit the IMPS OTA application. it can
 *  be called when END key is pressed to return to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop(?)(?)
 *  delete other nodes in history stack. Here, always return FALSE.(?)(?)
 *****************************************************************************/
static U8 mmi_imps_ota_abort(void* dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL)
        return MMI_TRUE;

    /* Terminated. Send a response back to CCA and free memory. */
    mmi_imps_send_cca_conf_rsp(CCA_STATUS_ENDKEY_PRESSED);
    mmi_imps_ota_free_info();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install_status
 * DESCRIPTION
 *  This function used to judge which status will be send to CCA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_install_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_info_struct *prof = imps_p->ota_prof;
    U16 curr_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->install_no)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_OK);
    }
    else if (prof->skip_no == prof->total - prof->invalid_no)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_SETTING_SKIPPED);
    }

    mmi_imps_ota_free_info();

    ClearDelScrnIDCallbackHandler(SCR_ID_IMPS_OTA_SETTING, NULL);
    DeleteScreenIfPresent(SCR_ID_IMPS_OTA_SETTING);
    DeleteScreenIfPresent(SCR_ID_IMPS_OTA_PROF_LIST);

    if (curr_scr == SCR_ID_IMPS_OTA_SETTING || curr_scr == SCR_ID_IMPS_OTA_PROF_LIST)
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_valid_proxy
 * DESCRIPTION
 *  This function used to judge whether profile proxy is valid.
 * PARAMETERS
 *  prof        [IN]        Profile need to be check
 * RETURNS
 *  if profile proxy is valid, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_is_valid_proxy(mmi_imps_ota_prof_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(prof != NULL);

    /* no proxy id */
    if (prof->proxy_id[0] == '\0')
    {
        return MMI_FALSE;
    }

    /* no valid proxy address */
    if (!prof->prof_info.use_proxy)
    {
        return MMI_FALSE;
    }        

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_valid_info
 * DESCRIPTION
 *  This function used to judge whether profile is valid.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_is_valid_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = imps_p->ota_prof->total;
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* move profile has only app to un-used profile */
    if (count > IMPS_PROF_COUNT)
    {
        for (i = 0; i < IMPS_PROF_COUNT; i++)
        {
            if (!imps_p->ota_prof->info[i]->is_used)
            {
                 mmi_imps_ota_free_prof(i);
                 for (j = IMPS_PROF_COUNT; j < IMPS_PROF_COUNT * 2; j++)
                 {
                     if (imps_p->ota_prof->info[j] != NULL)
                     {
                         imps_p->ota_prof->info[i] = imps_p->ota_prof->info[j];
                         imps_p->ota_prof->info[j] = NULL; 
                         imps_p->ota_prof->info[i]->is_used = MMI_TRUE;
                         break;
                     }
                 }
            }
        }
    }

    /* over IMPS_PROF_COUNT number profile, delete it */
    count = imps_p->ota_prof->total;
    if (count > IMPS_PROF_COUNT)
    {
        count = IMPS_PROF_COUNT;
        imps_p->ota_prof->total = IMPS_PROF_COUNT;

        for (i = IMPS_PROF_COUNT; i < 2 * IMPS_PROF_COUNT; i++)
        {
            if (imps_p->ota_prof->info[i] != NULL)
            {
                OslMfree(imps_p->ota_prof->info[i]);
                imps_p->ota_prof->info[i] = NULL;
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        if (imps_p->ota_prof->info[i]->prof_info.server[0] == '\0')
        {
            imps_p->ota_prof->info[i]->is_valid = MMI_FALSE;
        }
        if (!imps_p->ota_prof->info[i]->is_valid)
        {
            imps_p->ota_prof->invalid_no++;
        }
    }
    /* all profiles are invalid */
    if (imps_p->ota_prof->invalid_no == count)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
        mmi_imps_ota_free_info();
        return;
    }

    mmi_imps_pre_entry_ota_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_proxy_existed
 * DESCRIPTION
 *  This function used to judge whether profile proxy exist.
 * PARAMETERS
 *  px_id       [IN]        Proxy id
 * RETURNS
 *  if profile proxy exist, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_proxy_existed(S8 *px_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(imps_p->ota_prof != NULL);

    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i] != NULL)
        {
            if (strcmp((S8*)imps_p->ota_prof->info[i]->proxy_id, px_id) == 0)
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_string
 * DESCRIPTION
 *  Compose OTA information string
 * PARAMETERS
 *  buffer      [IN/OUT]        Store string of OTA information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_string(S8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[100];
    S8 uc2_temp[200];
    U8 i;
    U8 index = imps_p->ota_prof->curr_index;

    mmi_imps_ota_prof_struct *prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* instant message */
    mmi_ucs2cpy(buffer, GetString(STR_ID_CCA_IMPS));
    mmi_ucs2cat(buffer, (S8*)L"\n");

    /* profile index */
    for (i = 0; i < imps_p->ota_prof->curr_index; i++)
    {
        if (imps_p->ota_prof->info[i]->is_valid)
        {
            continue;
        }

        index--;
    }
    sprintf(temp, "%d/%d", index + 1,
        imps_p->ota_prof->total - imps_p->ota_prof->invalid_no);

    mmi_asc_to_ucs2(uc2_temp, temp);
    mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_PROF));
    mmi_ucs2cat(buffer, (S8*)L": ");
    mmi_ucs2cat(buffer, uc2_temp);
    mmi_ucs2cat(buffer, (S8*)L"\n");

    mmi_ucs2cat(buffer, (S8*)L"\n");

    /* profile name */
    if (prof->prof_info.prof_name[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_PROF_NAME));
        mmi_ucs2cat(buffer, (S8*)L":\n");
        mmi_ucs2cat(buffer, (S8*)(prof->prof_info.prof_name));
        mmi_ucs2cat(buffer, (S8*)L"\n\n");
    }

    /* server address */
    if (prof->prof_info.server[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_SERVER));
        mmi_ucs2cat(buffer, (S8*)L":\n");
        mmi_asc_to_ucs2(uc2_temp, (S8*)prof->prof_info.server);
        mmi_ucs2cat(buffer, uc2_temp);
        mmi_ucs2cat(buffer, (S8*)L"\n\n");
    }

    /* proxy server */
    if (prof->prof_info.use_proxy)
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_PROXY_SERVER));
        mmi_ucs2cat(buffer, (S8*)L":\n");
        sprintf(
           temp,
            "%d.%d.%d.%d",
            prof->prof_info.proxy_ip[0],
            prof->prof_info.proxy_ip[1],
            prof->prof_info.proxy_ip[2],
            prof->prof_info.proxy_ip[3]);
        mmi_asc_to_ucs2(uc2_temp, temp);
        mmi_ucs2cat(buffer, uc2_temp);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_ota_setting
 * DESCRIPTION
 *  Pre-entry function for screen that display OTA information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_pre_entry_ota_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->curr_index = 0;

    while (!imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_valid &&
           imps_p->ota_prof->curr_index < imps_p->ota_prof->total)
    {
        imps_p->ota_prof->curr_index++;
    }
    mmi_imps_entry_ota_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_ota_setting
 * DESCRIPTION
 *  Entry function for screen that display OTA information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_entry_ota_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_OTA_SETTING, NULL, mmi_imps_entry_ota_setting, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_OTA_SETTING);
    SetParentHandler(0);

    mmi_imps_ota_string((S8*)subMenuData);

    ShowCategory78Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_OK,
        STR_ID_CCA_SKIP,       
        IMG_GLOBAL_BACK,
        NULL,   /* mmi_wgui_general_multiline_icon_handler */
        (U8*)subMenuData,
        mmi_ucs2strlen((S8*)subMenuData),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_ota_install, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_imps_ota_skip_confirm, KEY_EVENT_UP);
    ClearDelScrnIDCallbackHandler(SCR_ID_IMPS_OTA_SETTING, NULL);
    DeleteScreenIfPresent(SCR_ID_IMPS_OTA_SETTING);
    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_OTA_SETTING, mmi_imps_ota_abort);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_hilite_prof_list
 * DESCRIPTION
 *  Highlight handler for OTA profile list.
 * PARAMETERS
 *  index       [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_hilite_prof_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->hilite_prof = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_ota_prof_list
 * DESCRIPTION
 *  Entry screen for list profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_entry_ota_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrItemList[IMPS_PROF_COUNT];
    U16 nIconItemList[IMPS_PROF_COUNT] = {0, 0, 0};
    U8 *guiBuffer;
    S32 curr_hilite = 0;
    mmi_imps_nvram_struct *prof_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);

    EntryNewScreen(SCR_ID_IMPS_OTA_PROF_LIST, NULL, mmi_imps_entry_ota_prof_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_OTA_PROF_LIST);

    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        mmi_ucs2cpy((S8*)imps_p->ota_prof->prof_name[i], (S8*)prof_buff->prof[i].prof_name);
        nStrItemList[i] = (U8*)imps_p->ota_prof->prof_name[i];
    }

    if (prof_buff->act_prof_indx <= IMPS_PROF_COUNT && prof_buff->act_prof_indx > 0)
    {
        nIconItemList[prof_buff->act_prof_indx - 1] = IMG_VICON;
    }

    OslMfree(prof_buff);

    RegisterHighlightHandler(mmi_imps_ota_hilite_prof_list);

    ShowCategory73Screen(
        STR_ID_CCA_REPLACE_SETTING,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMPS_PROF_COUNT,
        nStrItemList,
        (U16*) nIconItemList,
        (U16*) gIndexIconsImageList,
        curr_hilite,
        guiBuffer,
        ICON_ICON_TEXT);

    SetLeftSoftkeyFunction(mmi_imps_ota_install_yes, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_ota_install_yes, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install_yes
 * DESCRIPTION
 *  Select overwrite one existing profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_install_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *prof_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);

    /* if selected profile is in use */
    if ((imps_p->ota_prof->hilite_prof == prof_buff->act_prof_indx - 1) &&
        imps_p->gen_info.is_login)
    {
        mmi_imps_util_disp_err_popup(STR_ID_CCA_PROFILE_IN_USE);
        OslMfree(prof_buff);
        return;
    }
    
    memcpy(
        &prof_buff->prof[imps_p->ota_prof->hilite_prof],
        &imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->prof_info,
        sizeof(mmi_imps_prof_struct));

    if (mmi_ucs2strlen((S8*)prof_buff->prof[imps_p->ota_prof->hilite_prof].prof_name) == 0)
    {
        S8 str_tmp[IMPS_PROF_NAME_LEN];

        sprintf(str_tmp, "Profile%d", (imps_p->ota_prof->hilite_prof + 1));
        mmi_asc_to_ucs2((S8*)prof_buff->prof[imps_p->ota_prof->hilite_prof].prof_name, str_tmp);
    }

	if (!mmi_imps_ota_is_use_proxy(prof_buff->prof[imps_p->ota_prof->hilite_prof].proxy_ip))
	{
		prof_buff->prof[imps_p->ota_prof->hilite_prof].use_proxy = MMI_FALSE;
	}

    /* no valid activated profile */
    if (!imps_p->ota_prof->is_act && !imps_p->gen_info.is_login)
    {
        prof_buff->act_prof_indx = (imps_p->ota_prof->hilite_prof + 1);
		imps_p->ota_prof->is_act = MMI_TRUE;
        memcpy(&imps_p->act_prof, &prof_buff->prof[imps_p->ota_prof->hilite_prof], sizeof(mmi_imps_prof_struct));
        mmi_imps_util_reset_cont_list();
        mmi_imps_util_reset_presence(prof_buff);
    }
   
    mmi_imps_util_write_nvram(prof_buff);

    OslMfree(prof_buff);

    imps_p->ota_prof->install_no++;    

    if (mmi_imps_ota_get_next())
    {		
        GoBackHistory();
        mmi_imps_entry_ota_setting();
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install
 * DESCRIPTION
 *  Install OTA setting, first we need to judge whether OTA parameters are valid.
 *  If there is free proflie slot, we install automatically, otherwise come to
 *  profile select screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *prof_buff;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);

    /* check whether have not configured profile */
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (mmi_ucs2strlen((S8*)prof_buff->prof[i].server) == 0)
        {
            break;
        }
    }
    /* all profiles configured */
    if (i == IMPS_PROF_COUNT)
    {
        mmi_imps_entry_ota_prof_list();
        OslMfree(prof_buff);
        return;
    }

    /* save OTA setting to NVRAM */
    memcpy(
        &prof_buff->prof[i],
        &imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->prof_info,
        sizeof(mmi_imps_prof_struct));

    if (mmi_ucs2strlen((S8*)prof_buff->prof[i].prof_name) == 0)
    {
        S8 str_tmp[IMPS_PROF_NAME_LEN];

        sprintf(str_tmp, "Profile%d", (i + 1));
        mmi_asc_to_ucs2((S8*)prof_buff->prof[i].prof_name, str_tmp);
    }

    /* no valid activated profile */
    if (!imps_p->ota_prof->is_act && !imps_p->gen_info.is_login)
    {
        prof_buff->act_prof_indx = (i + 1);
		imps_p->ota_prof->is_act = MMI_TRUE;
        memcpy(&imps_p->act_prof, &prof_buff->prof[i], sizeof(mmi_imps_prof_struct));
        mmi_imps_util_reset_cont_list();
        mmi_imps_util_reset_presence(prof_buff);
    }

	if (!mmi_imps_ota_is_use_proxy(prof_buff->prof[i].proxy_ip))
	{
		prof_buff->prof[i].use_proxy = MMI_FALSE;
	}    

    mmi_imps_util_write_nvram(prof_buff);

    OslMfree(prof_buff);

    imps_p->ota_prof->install_no++;
    if (mmi_imps_ota_get_next())
    {
        mmi_imps_entry_ota_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_get_next
 * DESCRIPTION
 *  Get next OTA setting, if no more OTA setting, response to CCA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_get_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_info_struct *prof = imps_p->ota_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->curr_index >= prof->total - 1)
    {
        mmi_imps_ota_install_status();
        return MMI_FALSE;
    }
    else
    {
        imps_p->ota_prof->curr_index++;

        while (imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_valid != MMI_TRUE &&
               imps_p->ota_prof->curr_index < imps_p->ota_prof->total)
        {
            imps_p->ota_prof->curr_index++;
 
            if (prof->curr_index >= prof->total)
            {
                mmi_imps_ota_install_status();
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_skip_confirm
 * DESCRIPTION
 *  Call CCA function to show whether skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel((U16)STR_ID_CCA_SKIP_PROFILE, mmi_imps_ota_skip_yes);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_skip_yes
 * DESCRIPTION
 *  Skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_skip_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->skip_no++;
    if (mmi_imps_ota_get_next())
    {
        mmi_imps_entry_ota_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]        Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_is_ascii_string(const U8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If this is an ASCII string, each octet should be an ASCII character. */
    for (; *utf8_str != '\0'; ++utf8_str)
    {
        if (*utf8_str > 0x7F)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_ip
 * DESCRIPTION
 *  parse string to 4 number
 * PARAMETERS
 *  ip          [OUT]       Store parsed data
 *  data        [IN]        Source data
 *  len         [IN]        Length of source data
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_imps_check_ip(U8 *ip, S8 *data, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dot_no = 0;
    S32 i = 0, j = 0, k = 0;
    S8 temp[4][4];  /* eg: 255.255.255.255 */
    S16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL || len < 7 || len > 15)    /* 0.0.0.0 */
    {
        return MMI_FALSE;
    }

    memset(temp, 0, 4 * 4);

    if (data[0] == '.' || data[len - 1] == '.')
    {
        return MMI_FALSE;
    }

    for (i = 0; i < len; i++)
    {
        if (data[i] == '.')
        {
            dot_no++;
            j++;
            k = 0;

            if ((i < len - 1) && (data[i + 1] == '.'))
            {
                return MMI_FALSE;
            }
        }
        else
        {
            if (data[i] < '0' || data[i] > '9')
            {
                return MMI_FALSE;
            }
            temp[j][k] = data[i];

            k++;
        }
    }
    if (dot_no != 3)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < 4; i++)
    {
        value = (S16)atoi(temp[i]);
        if (value > 255)
            return MMI_FALSE;

        ip[i] = value;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_use_proxy
 * DESCRIPTION
 *  Judge whether use proxy
 * PARAMETERS
 *  data        [IN]        Source data
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_is_use_proxy(const U8 *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
	U8 result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	for (i = 0; i < 4; i++)
	{
		if (data[i] != 0)
		{
			result = MMI_TRUE;
			break;
		}
	}
	return result;
}
#endif /* __MMI_IMPS_OTA__ */ 
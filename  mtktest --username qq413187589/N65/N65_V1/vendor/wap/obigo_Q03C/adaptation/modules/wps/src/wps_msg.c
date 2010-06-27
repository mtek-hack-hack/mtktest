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
 *   wps_msg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements WPS external message handler
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
#define _FILE_CODE_  _WPS_MSG_C_

#include "stdio.h"

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "fat_fs.h"

#include "wap_ps_struct.h"

#include <setjmp.h>

#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_hdr.h"
#include "msf_core.h"
#include "msf_file.h"
#include "msf_pipe.h"
#include "msf_env.h"
#include "msf_url.h"
#include "stk_if.h"
#ifdef WAP_SEC_SUPPORT
#include "sec_awim.h"
#include "sec_if.h"
#include "sec_lib.h"
#include "sec_x509.h"
#include "sec_wtls.h"
#endif /* WAP_SEC_SUPPORT */ 
#include "bra_prof.h"
#include "wapadp.h"
#include "wps_if.h"
#include "wps_main.h"
#include "widget_extension.h"

#ifdef WPS_SUPPORT

#define  WPS_PIPE_PREFIX "wps-crh-pipe"

#ifdef WPS_TASK_SUPPORT
extern void MSF_wps_fsm(void);
#endif 
extern const char *bra_prof_accept_header[];

#define WPS_MAX_STATUS_REGISTER_NUM 32
static kal_uint8 wps_ready_status = WPS_READY_STATUS_NULL;
static kal_uint8 wps_status_idx = 0;
static module_type wps_status_register[WPS_MAX_STATUS_REGISTER_NUM];

/************************************************************
 * Global function prototype
 ************************************************************/
#ifdef __IMPS__
void wps_send_imps_ready_ind(void);
#endif 

void wps_send_unset_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void wps_send_http_rsp(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 error_cause, kal_uint8 request_id);

void wps_send_set_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void wps_send_reconfig_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void
wps_send_read_content_rsp(
    module_type dst_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_uint8 request_id);

void wps_send_cancel_rsp(module_type dst_id, kal_uint8 request_id, kal_uint8 error_cause);

void wps_send_post_content_ind(module_type dst_id, kal_uint8 request_id, kal_uint8 error_cause, kal_uint8 seq_num);

void wps_send_clear_rsp(module_type dst_id, kal_uint8 request_id, kal_uint8 error_cause);

void wps_send_create_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

static void wps_send_close_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void wps_send_stream_data_send_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause, kal_uint8 seq_num);

void
wps_send_stream_data_read_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_bool more);

#ifdef WAP_SEC_SUPPORT
void
wps_send_sec_get_session_info_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_session_info_response_t *session_info,
    kal_uint8 error_cause);

void
wps_send_sec_get_current_cert_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_current_cert_response_t *current_cert,
    kal_uint8 error_cause);

void
wps_send_verify_cert_chain_rsp(
    module_type dst_id,
    sec_verify_cert_chain_response_t *rsp,
    kal_uint8 error_cause);

#endif /* WAP_SEC_SUPPORT */ 

void
wps_send_http_auth_ind(
    module_type dst_id,
    kal_uint8 channel_id,
    kal_uint8 request_id,
    kal_uint8 auth_type,
    kal_uint8 *realm);

void wps_send_status_query_rsp(module_type dst_id, kal_uint8 status);

/************************************************************
 * Local function definitions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_search_req_info_by_id
 * DESCRIPTION
 *  this function is used to search request info by request ID.
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wps_req_info_struct *wps_search_req_info_by_id(kal_uint8 channel_id, kal_uint8 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        return NULL;
    }

    for (i = 0; i < WPS_MAX_REQUESTS; i++)
    {
        req_info = chl_info->request_info[i];
        if (req_info != NULL && req_info->request_id == request_id)
        {
            return req_info;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_ilm
 * DESCRIPTION
 *  this function is to send ILM to other tasks
 * CALLS
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef WPS_TASK_SUPPORT
static void wps_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_MMI:
            sap_id = WPS_APP_SAP;
            break;
        case MOD_WAP:
            sap_id = WPS_APP_SAP;
            break;
        default:
            /* invalid value */
            sap_id = WPS_APP_SAP;
            break;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(MOD_WPS);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

SEND_ILM(MOD_WPS, dst_id, sap_id, ilm_ptr)}
#else /* WPS_TASK_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_MMI:
            sap_id = WAP_MMI_SAP;
            break;
        default:
            /* invalid value */
            return;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

SEND_ILM(MOD_WAP, dst_id, sap_id, ilm_ptr)}
#endif /* WPS_TASK_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_wap_ready_ind_hdlr
 * DESCRIPTION
 *  this function is to used to handle WAP init. completion indication
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_wap_ready_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wps_ready_status = WPS_READY_STATUS_OK;

#ifdef __IMPS__
    wps_send_imps_ready_ind();
#endif 

    /* send ready indication to each ready indication register */
    for (i = 0; i < wps_status_idx; i++)
    {
        wps_send_ilm(NULL, NULL, MSG_ID_WPS_READY_IND, wps_status_register[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_set_channel_req_hdlr
 * DESCRIPTION
 *  this function is to configure a dedicated channel for HTTP/WSP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  set_channel_req         [?]         
 *  set_channel_req_var     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_set_channel_req_hdlr(
    module_type src_mod_id,
    wps_set_channel_req_struct *set_channel_req,
    wps_set_channel_req_var_struct *set_channel_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause;
    kal_int8 channel_id = -1;
    kal_uint8 conn_type;
    msf_sockaddr_t prx_addr;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set_channel_req->use_default == KAL_TRUE)
    {
        bra_prof_content_t *prof_cont;
        kal_uint8 result;

        result = bra_prof_off_line_load_bra_active_profile(&prof_cont);
        if (result != WAP_PROF_SUCCESS)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            set_channel_req->conn_type = prof_cont->con_type;
            set_channel_req->net_id = prof_cont->net_id;
            memcpy(set_channel_req->prx_ip, prof_cont->prx_ip, 4);
            set_channel_req->prx_port = prof_cont->prx_port;
            set_channel_req->timeout = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_TIMEOUT);
            if (prof_cont->con_type == WPS_CONN_TYPE_HTTP && prof_cont->prx_ip[0] == 0
                && prof_cont->prx_ip[1] == 0 && prof_cont->prx_ip[2] == 0 && prof_cont->prx_ip[3] == 0)
            {
                set_channel_req->use_proxy = KAL_FALSE;
            }
            else
            {
                set_channel_req->use_proxy = KAL_TRUE;
            }

            if (prof_cont->username == NULL)
            {
                set_channel_req->username[0] = '\0';
            }
            else if (strlen(prof_cont->username) >= WAP_PROF_MAX_UID_SIZE)
            {
                strncpy((char*)set_channel_req->username, prof_cont->username, WAP_PROF_MAX_UID_SIZE - 1);
                set_channel_req->username[WAP_PROF_MAX_UID_SIZE - 1] = '\0';
            }
            else
            {
                strcpy((char*)set_channel_req->username, prof_cont->username);
            }
            BRA_FREE(prof_cont->username);

            if (prof_cont->password == NULL)
            {
                set_channel_req->password[0] = '\0';
            }
            else if (strlen(prof_cont->password) >= WAP_PROF_MAX_PWD_SIZE)
            {
                strncpy((char*)set_channel_req->password, prof_cont->password, WAP_PROF_MAX_PWD_SIZE - 1);
                set_channel_req->password[WAP_PROF_MAX_PWD_SIZE - 1] = '\0';
            }
            else
            {
                strcpy((char*)set_channel_req->password, prof_cont->password);
            }
            BRA_FREE(prof_cont->password);
        }
    }

    /* check connection type */
    switch (set_channel_req->conn_type)
    {
        case WPS_CONN_TYPE_HTTP:
        case WPS_CONN_TYPE_WSP_CL:
        case WPS_CONN_TYPE_WSP_CO:
            conn_type = set_channel_req->conn_type;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    /* convert and check proxy address */
    if (set_channel_req->use_proxy == KAL_TRUE
        || conn_type == WPS_CONN_TYPE_WSP_CL || conn_type == WPS_CONN_TYPE_WSP_CO)
    {
        set_channel_req->use_proxy = KAL_TRUE;
        if (set_channel_req->prx_ip[0] == 0 && set_channel_req->prx_ip[1] == 0
            && set_channel_req->prx_ip[2] == 0 && set_channel_req->prx_ip[3] == 0)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            prx_addr.addrLen = 4;
            memcpy(prx_addr.addr, set_channel_req->prx_ip, 4);
            if (set_channel_req->prx_port == 0)
            {
                switch (conn_type)
                {
                    case WPS_CONN_TYPE_HTTP:
                        prx_addr.port = WPS_DEFAULT_PRX_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CO:
                        prx_addr.port = WPS_DEFAULT_WSP_CO_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CL:
                        prx_addr.port = WPS_DEFAULT_WSP_CL_PORT;
                        break;
                }
            }
            else
            {
                prx_addr.port = set_channel_req->prx_port;
            }
        }
    }

    /* get availabe channel ID */
    channel_id = wps_get_available_channel();
    if (channel_id == -1)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }
    else
    {
        chl_info = wps_create_channel(channel_id);
        if (chl_info == NULL)
        {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
        }
        chl_info->mod_id = src_mod_id;
        chl_info->conn_type = conn_type;
        chl_info->net_id = set_channel_req->net_id;
        chl_info->timeout = set_channel_req->timeout;
    }

    /* store server auth userame/password */
    if (chl_info->server_auth_username != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, chl_info->server_auth_username);
    }
    if(set_channel_req->server_auth_username[0] != '\0')
    {
        chl_info->server_auth_username =
            (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)set_channel_req->server_auth_username);
    }
    else
    {
        chl_info->server_auth_username = NULL;
    }

    if (chl_info->server_auth_password != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, chl_info->server_auth_password);
    }
    if(set_channel_req->server_auth_password[0] != '\0')
    {
        chl_info->server_auth_password =
            (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)set_channel_req->server_auth_password);
    }
    else
    {
        chl_info->server_auth_password = NULL;
    }

    /* store static header */
    if (set_channel_req_var != NULL && set_channel_req_var->static_header_len > 0)
    {
        chl_info->static_header = MSF_MEM_ALLOC(MSF_MODID_WPS, set_channel_req_var->static_header_len + 1);
        memcpy(chl_info->static_header, set_channel_req_var->static_header, set_channel_req_var->static_header_len);
        chl_info->static_header[set_channel_req_var->static_header_len] = '\0';
    }
    else
    {
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
    #endif /* 0 */ 
    }

    if (set_channel_req->use_proxy == KAL_TRUE)
    {
        STKif_configureProxyChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            &prx_addr,
            0,
            (char*)set_channel_req->username,
            (char*)set_channel_req->password,
            NULL,
            0,
            (char*)chl_info->static_header);
    }
    else
    {
        STKif_configureChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            0,
            (char*)chl_info->static_header);
    }

    wps_hold_bearer(chl_info->net_id);
    error_cause = WPS_OK;

  error:

    /* prepare and send MSG_ID_WPS_SET_CHANNEL_RSP with failure cause */
    wps_send_set_channel_rsp(src_mod_id, channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_unset_channel_req_hdlr
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_unset_channel_req_hdlr(module_type src_mod_id, wps_unset_channel_req_struct *unset_channel_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_uint8 i; */
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check channel id */
    if (unset_channel_req->channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    /* check channel if exists */
    chl_info = g_wps_cntx.channel_info[unset_channel_req->channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INACTIVE_CHANNEL;
        goto error;
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
#endif /* 0 */ 

    STKif_removeChannel(MSF_MODID_WPS, unset_channel_req->channel_id + 1);

    wps_clear_channel(unset_channel_req->channel_id);

    error_cause = WPS_OK;

  error:
    /* prepare and send MSG_ID_WPS_UNSET_CHANNEL_RSP with failure cause */
    wps_send_unset_channel_rsp(src_mod_id, unset_channel_req->channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_reconfig_channel_req_hdlr
 * DESCRIPTION
 *  this function is to reconfigure a dedicated channel for HTTP/WSP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  set_channel_req         [?]         
 *  set_channel_req_var     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_reconfig_channel_req_hdlr(
    module_type src_mod_id,
    wps_reconfig_channel_req_struct *reconfig_channel_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info = NULL;
    kal_uint8 conn_type;
    msf_sockaddr_t prx_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check channel id */
    chl_info = g_wps_cntx.channel_info[reconfig_channel_req->channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    if (reconfig_channel_req->use_default == KAL_TRUE)
    {
        bra_prof_content_t *prof_cont;
        kal_uint8 result;

        result = bra_prof_off_line_load_bra_active_profile(&prof_cont);
        if (result != WAP_PROF_SUCCESS)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            reconfig_channel_req->conn_type = prof_cont->con_type;
            reconfig_channel_req->net_id = prof_cont->net_id;
            memcpy(reconfig_channel_req->prx_ip, prof_cont->prx_ip, 4);
            reconfig_channel_req->prx_port = prof_cont->prx_port;
            reconfig_channel_req->timeout = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_TIMEOUT);
            if (prof_cont->con_type == WPS_CONN_TYPE_HTTP && prof_cont->prx_ip[0] == 0
                && prof_cont->prx_ip[1] == 0 && prof_cont->prx_ip[2] == 0 && prof_cont->prx_ip[3] == 0)
            {
                reconfig_channel_req->use_proxy = KAL_FALSE;
            }
            else
            {
                reconfig_channel_req->use_proxy = KAL_TRUE;
            }

            if (prof_cont->username == NULL)
            {
                reconfig_channel_req->username[0] = '\0';
            }
            else if (strlen(prof_cont->username) >= WAP_PROF_MAX_UID_SIZE)
            {
                strncpy((char*)reconfig_channel_req->username, prof_cont->username, WAP_PROF_MAX_UID_SIZE - 1);
                reconfig_channel_req->username[WAP_PROF_MAX_UID_SIZE - 1] = '\0';
            }
            else
            {
                strcpy((char*)reconfig_channel_req->username, prof_cont->username);
            }
            BRA_FREE(prof_cont->username);

            if (prof_cont->password == NULL)
            {
                reconfig_channel_req->password[0] = '\0';
            }
            else if (strlen(prof_cont->password) >= WAP_PROF_MAX_PWD_SIZE)
            {
                strncpy((char*)reconfig_channel_req->password, prof_cont->password, WAP_PROF_MAX_PWD_SIZE - 1);
                reconfig_channel_req->password[WAP_PROF_MAX_PWD_SIZE - 1] = '\0';
            }
            else
            {
                strcpy((char*)reconfig_channel_req->password, prof_cont->password);
            }
            BRA_FREE(prof_cont->password);
        }
    }

    /* check connection type */
    switch (reconfig_channel_req->conn_type)
    {
        case WPS_CONN_TYPE_HTTP:
        case WPS_CONN_TYPE_WSP_CL:
        case WPS_CONN_TYPE_WSP_CO:
            conn_type = reconfig_channel_req->conn_type;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    /* convert and check proxy address */
    if (reconfig_channel_req->use_proxy == KAL_TRUE
        || conn_type == WPS_CONN_TYPE_WSP_CL || conn_type == WPS_CONN_TYPE_WSP_CO)
    {
        reconfig_channel_req->use_proxy = KAL_TRUE;
        if (reconfig_channel_req->prx_ip[0] == 0 && reconfig_channel_req->prx_ip[1] == 0
            && reconfig_channel_req->prx_ip[2] == 0 && reconfig_channel_req->prx_ip[3] == 0)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            prx_addr.addrLen = 4;
            memcpy(prx_addr.addr, reconfig_channel_req->prx_ip, 4);
            if (reconfig_channel_req->prx_port == 0)
            {
                switch (conn_type)
                {
                    case WPS_CONN_TYPE_HTTP:
                        prx_addr.port = WPS_DEFAULT_PRX_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CO:
                        prx_addr.port = WPS_DEFAULT_WSP_CO_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CL:
                        prx_addr.port = WPS_DEFAULT_WSP_CL_PORT;
                        break;
                }
            }
            else
            {
                prx_addr.port = reconfig_channel_req->prx_port;
            }
        }
    }

    chl_info->mod_id = src_mod_id;
    chl_info->conn_type = conn_type;
    chl_info->net_id = reconfig_channel_req->net_id;
    chl_info->timeout = reconfig_channel_req->timeout;

    STKif_removeChannel (MSF_MODID_WPS, (int)(chl_info->channel_id + 1));

    if (reconfig_channel_req->use_proxy == KAL_TRUE)
    {
        STKif_configureProxyChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            &prx_addr,
            0,
            (char*)reconfig_channel_req->username,
            (char*)reconfig_channel_req->password,
            NULL,
            0,
            (char*)chl_info->static_header);
    }
    else
    {
        STKif_configureChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            0,
            (char*)chl_info->static_header);
    }

    wps_hold_bearer(chl_info->net_id);
    error_cause = WPS_OK;

error:    
    /* prepare and send MSG_ID_WPS_SET_CHANNEL_RSP with failure cause */
    wps_send_reconfig_channel_rsp(src_mod_id, chl_info->channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_http_req_hdlr
 * DESCRIPTION
 *  this function is to send a HTTP/WSP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  http_req            [?]         
 *  http_req_var        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_http_req_hdlr(module_type src_mod_id, wps_http_req_struct *http_req, wps_http_req_var_struct *http_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause = 0;
    kal_uint8 channel_id = 0;
    kal_uint8 request_idx = 0;
    kal_uint8 method;
    int options;
    wps_chl_info_struct *chl_info = NULL;
    wps_req_info_struct *req_info = NULL;
    stk_content_t stkData;
    stk_content_t *stkDataPtr = NULL;
    int numEntries = 0;
    char *pipeName = NULL, *pathName = NULL, *url = NULL;
    int reply_path_len = 0, post_path_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (http_req_var == NULL)
    {
        /* invalid param */
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    channel_id = http_req->channel_id;

    /* check channel id */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    if (http_req_var->request_url_len == 0 || http_req_var->request_url == NULL)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    if (wps_search_req_info_by_id(channel_id, http_req->request_id) != NULL)
    {
        error_cause = WPS_ERROR_PENDING_REQ_EXIST;
        goto error;
    }

    /* check method */
    method = http_req->method;
    switch (method)
    {
        case WPS_HTTP_METHOD_HEAD:
        case WPS_HTTP_METHOD_GET:
        case WPS_HTTP_METHOD_DELETE:
            break;
        case WPS_HTTP_METHOD_POST:
        case WPS_HTTP_METHOD_PUT:
            if (http_req->post_type == WPS_DATA_TYPE_FILE)
            {
                FS_HANDLE fd;

                post_path_len = widget_ucs2_length((kal_uint8*) http_req->post_path);
                if (post_path_len == 0)
                {
                    error_cause = WPS_ERROR_INVALID_PARAM;
                    goto error;
                }
                fd = FS_Open(http_req->post_path, FS_READ_ONLY);
                if (fd < 0)
                {
                    error_cause = WPS_ERROR_INVALID_PARAM;
                    goto error;
                }
                else
                {
                    FS_Close(fd);
                }
            }
            else if (http_req->post_type != WPS_DATA_TYPE_BUFFER)
            {
                error_cause = WPS_ERROR_INVALID_PARAM;
                goto error;
            }
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    options = http_req->option;

    /* check reply type */
    switch (http_req->reply_type)
    {
        case WPS_DATA_TYPE_FILE:
        case WPS_DATA_TYPE_FILE_NO_PROG_IND:
        case WPS_DATA_TYPE_FILE_RESUME:
            if (http_req->reply_path == NULL)
            {
                error_cause = WPS_ERROR_INVALID_PARAM;
                goto error;
            }
            reply_path_len = widget_ucs2_length((kal_uint8*) http_req->reply_path);
            if (reply_path_len == 0)
            {
                error_cause = WPS_ERROR_INVALID_PARAM;
                goto error;
            }
            break;
        case WPS_DATA_TYPE_BUFFER:
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    /* get empty request entry */
    req_info = wps_create_request(channel_id, http_req->request_id);
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }
    request_idx = req_info->idx;

    /* save method */
    req_info->method = method;

    /* prepare for content posting */
    if (method == STK_METHOD_POST || method == STK_METHOD_PUT)
    {
        if (http_req->post_type == WPS_DATA_TYPE_BUFFER && http_req_var->post_segment_len > 0)
        {
            /* create pipe for posting data */
            pipeName = MSF_MEM_ALLOC(MSF_MODID_WPS, strlen("wps-crh-pipe") + 9);
            sprintf(pipeName, "%s%d", WPS_PIPE_PREFIX, req_info->stk_request_id);
            req_info->pipe_handle = MSF_PIPE_CREATE(MSF_MODID_WPS, pipeName);
            if (req_info->pipe_handle < 0)
            {
                error_cause = WPS_ERROR_NO_RESOURCE;
                goto error;
            }

            req_info->post_buff_size = http_req_var->post_segment_len;
            req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->post_buff_size);
            if (req_info->buff == NULL)
            {
                error_cause = WPS_ERROR_NO_RESOURCE;
                goto error;
            }

            memcpy(req_info->buff, http_req_var->post_segment, http_req_var->post_segment_len);
            req_info->buff_pos = 0;
            req_info->more_post = http_req->more_post;

            stkData.contentType = NULL;
            stkData.charset = 0;
            stkData.name = NULL;
            stkData.fileName = NULL;
            stkData.dataType = STK_BODY_PIPE;
            stkData.dataLen = http_req->post_total_len;
            stkData._u.pipeName = pipeName;
            stkDataPtr = &stkData;
            numEntries++;
        }
        else if (http_req->post_type == WPS_DATA_TYPE_FILE && post_path_len > 0)
        {
            int len;

            stkData.contentType = NULL;
            stkData.charset = 0;
            stkData.name = NULL;
            stkData.fileName = NULL;
            stkData.dataType = STK_BODY_FILE;
            stkData.dataLen = http_req->post_total_len;
            len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) http_req->post_path);
            pathName = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, HDI_EXTERNAL_LEN + len + 1);
            sprintf(pathName, "%s", HDI_EXTERNAL_PATH);
            widget_ucs2_to_utf8_string(
                (kal_uint8*) (pathName + HDI_EXTERNAL_LEN),
                len + 1,
                (kal_uint8*) http_req->post_path);
            stkData._u.pathName = pathName;
            stkDataPtr = &stkData;
            numEntries++;
            /* save post path and request header for unauthorized resend */
            req_info->post_path = (kal_wchar*) MSF_MEM_ALLOC(MSF_MODID_WPS, (post_path_len + 1) * 2);
            memcpy(req_info->post_path, http_req->post_path, (post_path_len + 1) * 2);
            req_info->req_header =
                (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_WPS, strlen((char*)(http_req_var->request_header)) + 1);
            strcpy((char*)req_info->req_header, (const char*)http_req_var->request_header);
        }
        req_info->post_total_len = http_req->post_total_len;
    }

    /* prepare for content reply */
    if (http_req->reply_type == WPS_DATA_TYPE_FILE_NO_PROG_IND)
    {
        req_info->flag |= WPS_FLAG_FILE_NO_PROG_IND;
        req_info->reply_type = WPS_DATA_TYPE_FILE;
    }
    else if(http_req->reply_type == WPS_DATA_TYPE_FILE_RESUME)
    {
        req_info->flag |= WPS_FLAG_FILE_RESUME;
        req_info->reply_type = WPS_DATA_TYPE_FILE;
    }
    else
    {
        req_info->reply_type = http_req->reply_type;
    }

    if (req_info->reply_type == WPS_DATA_TYPE_FILE)
    {
        req_info->reply_buff_size = WPS_DEFAULT_READ_BUFF_SIZE;
        req_info->reply_path = (kal_wchar*) MSF_MEM_ALLOC(MSF_MODID_WPS, (reply_path_len + 1) * 2);
        memcpy(req_info->reply_path, http_req->reply_path, (reply_path_len + 1) * 2);
    }
    else
    {
        if (http_req->reply_segment_len == 0)
        {
            req_info->reply_buff_size = req_info->assigned_reply_buff_size = WPS_DEFAULT_READ_BUFF_SIZE;
        }
        else
        {
            req_info->reply_buff_size = req_info->assigned_reply_buff_size = http_req->reply_segment_len;
        }
    }

    url = (char *)MSF_MEM_ALLOC(MSF_MODID_WPS, http_req_var->request_url_len + 1);
    memcpy(url, http_req_var->request_url, http_req_var->request_url_len);
    url[http_req_var->request_url_len] = '\0';

    req_info->url = (kal_uint8*) msf_url_make_complete (MSF_MODID_WPS, url);
	MSF_MEM_FREE(MSF_MODID_WPS, url);

    if(chl_info->server_auth_username && chl_info->server_auth_password)
    {
        /* clear auth info anyway */
        STKif_clear(MSF_MODID_WPS, STK_CLEAR_AUTH_HOST, (const char*)req_info->url);
    }

    if (method == STK_METHOD_POST || method == STK_METHOD_PUT)
    {
        STKif_httpRequest(
            MSF_MODID_WPS,
            channel_id + 1,
            req_info->stk_request_id,
            (const char*)req_info->url,
            method,
            options,
            (char*)http_req_var->request_header,
            NULL,
            0,
            numEntries,
            stkDataPtr);
        if (http_req->post_type == WPS_DATA_TYPE_BUFFER && numEntries > 0)
        {
            req_info->state = WPS_REQ_POSTING;
            wps_write_post_content(req_info);
        }
        else
        {
            req_info->state = WPS_REQ_WAIT_RSP;
        }
    }
    else
    {
        STKif_httpRequest(
            MSF_MODID_WPS,
            channel_id + 1,
            req_info->stk_request_id,
            (const char*)req_info->url,
            method,
            options,
            (char*)http_req_var->request_header,
            NULL,
            0,
            0,
            NULL);
        req_info->state = WPS_REQ_WAIT_RSP;
    }

  error:
    MSF_MEM_FREE(MSF_MODID_WPS, pipeName);
    MSF_MEM_FREE(MSF_MODID_WPS, pathName);
    if (req_info == NULL || req_info->state == WPS_REQ_NULL)
    {
        wps_send_http_rsp(src_mod_id, NULL, error_cause, http_req->request_id);
        if (req_info)
        {
            wps_clear_request(channel_id, request_idx);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_read_content_req_hdlr
 * DESCRIPTION
 *  this function is to continue to read HTTP/WSP reply content.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  read_content_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_read_content_req_hdlr(module_type src_mod_id, wps_read_content_req_struct *read_content_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = read_content_req->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, read_content_req->request_id);
    if (req_info == NULL || req_info->state != WPS_REQ_RSP_SENT)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    request_idx = req_info->idx;

    if (read_content_req->seq_num != req_info->seq_num)
    {
        error_cause = WPS_ERROR_INVALID_SEQUENCE_NUM;
        goto error;
    }

    if (read_content_req->read_segnemtn_len > 0)
    {
        req_info->reply_buff_size = read_content_req->read_segnemtn_len;
    }

    req_info->reply_buff_size = req_info->assigned_reply_buff_size;
    
    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->reply_buff_size);
    if (req_info->buff == NULL)
    {
        /* send back response and delete content */
        wps_send_read_content_rsp(src_mod_id, req_info, WPS_ERROR_NO_RESOURCE, req_info->request_id);
        wps_clear_request(channel_id, request_idx);
        return;
    }

    req_info->state = WPS_REQ_WAIT_CONTENT;
    wps_read_reply_content(req_info);
    return;

  error:
    wps_send_read_content_rsp(src_mod_id, req_info, error_cause, read_content_req->request_id);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_post_content_res_hdlr
 * DESCRIPTION
 *  this function is to to handle continuous content post of a HTTP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  post_content_res            [?]         
 *  post_content_res_var        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_post_content_res_hdlr(
    module_type src_mod_id,
    wps_post_content_res_struct *post_content_res,
    wps_post_content_res_var_struct *post_content_res_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx = 0;
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = post_content_res->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, post_content_res->request_id);
    if (req_info == NULL || req_info->state != WPS_REQ_POSTING)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    request_idx = req_info->idx;

    if (post_content_res->seq_num != req_info->seq_num)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    if (post_content_res_var == NULL || post_content_res_var->post_segment_len == 0)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    req_info->reply_buff_size = post_content_res_var->post_segment_len;

    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->reply_buff_size);
    if (req_info->buff == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    memcpy(req_info->buff, post_content_res_var->post_segment, post_content_res_var->post_segment_len);
    req_info->buff_pos = 0;
    req_info->more_post = post_content_res->more;
    wps_write_post_content(req_info);
    return;

  error:
    /* send back post indication with error code */
    if (req_info == NULL)
    {
        wps_send_post_content_ind(src_mod_id, 0, error_cause, 0);
    }
    else
    {
        wps_send_post_content_ind(src_mod_id, req_info->request_id, error_cause, 0);
        /* abort HTTP/WSP request */
        if (req_info->state == WPS_REQ_POSTING)
        {
            STKif_cancelRequest(MSF_MODID_WPS, req_info->stk_request_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_cancel_req_hdlr
 * DESCRIPTION
 *  this function is to cancel an incomplete WSP/HTTP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  cancel_req      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_cancel_req_hdlr(module_type src_mod_id, wps_cancel_req_struct *cancel_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = cancel_req->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, cancel_req->request_id);
    if (req_info == NULL || req_info->state == WPS_REQ_NULL)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    request_idx = req_info->idx;

    switch (req_info->state)
    {
        case WPS_REQ_CANCELING:
            error_cause = WPS_ERROR_PENDING_REQ_EXIST;
            goto error;
        case WPS_REQ_POSTING:
            /* post request */
            MSF_PIPE_CLOSE(req_info->pipe_handle);
            req_info->pipe_handle = -1;
            wps_clear_request_buff(req_info);
        case WPS_REQ_WAIT_RSP:
            STKif_cancelRequest(MSF_MODID_WPS, req_info->stk_request_id);
            req_info->state = WPS_REQ_CANCELING;
            break;
        case WPS_REQ_RSP_SENT:
        case WPS_REQ_WAIT_CONTENT:
            wps_send_cancel_rsp(src_mod_id, req_info->request_id, WPS_OK);
            wps_clear_request(channel_id, request_idx);
            break;
    }

    return;

  error:
    wps_send_cancel_rsp(src_mod_id, cancel_req->request_id, error_cause);
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_clear_req_hdlr(module_type src_mod_id, wps_clear_req_struct *clear_req, wps_clear_req_var_struct *clear_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    int op;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = clear_req->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    if ((clear_req->operation == WPS_CLEAR_CACHE_URL_MATCH
         || clear_req->operation == WPS_CLEAR_CACHE_URL_PREFIX)
        && (clear_req_var == NULL || clear_req_var->cache_url_len == 0 || clear_req_var->cache_url == NULL))
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    op = clear_req->operation;
    switch (op)
    {
        case WPS_CLEAR_CACHE_URL_MATCH:
        case WPS_CLEAR_CACHE_URL_PREFIX:
        case WPS_CLEAR_CACHE_ALL:
        case WPS_CLEAR_AUTH_HOST:
        case WPS_CLEAR_AUTH_PROXY:
        case WPS_CLEAR_AUTH_ALL:
        case WPS_CLEAR_COOKIES_ALL:
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    STKif_clear(MSF_MODID_WPS, op, (char*)clear_req_var->cache_url);
    error_cause = WPS_OK;

  error:
    wps_send_clear_rsp(src_mod_id, clear_req->request_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_create_stream_connection_req_hdlr(module_type src_mod_id, wps_create_stream_connection_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;
    kal_uint8 error_cause;
    kal_uint8 conn_type;
    int channel_id = -1;
    msf_sockaddr_t addr;
    char sendPipeName[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req->use_default == KAL_TRUE)
    {
        bra_prof_content_t *prof_cont;
        kal_uint8 result;

        result= bra_prof_off_line_load_bra_active_profile(&prof_cont);
        if (result != WAP_PROF_SUCCESS)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            /* req->conn_type = prof_cont->con_type; */
            req->net_id = prof_cont->net_id;
        }
    }

    /* check connection type */
    switch (req->conn_type)
    {
        case WPS_CONN_TYPE_TLS:
            conn_type = STK_CONNECTION_TYPE_TLS;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    if (req->addr[0] == 0 && req->addr[1] == 0 && req->addr[2] == 0 && req->addr[3] == 0)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }
    else
    {
        addr.addrLen = 4;
        memcpy(addr.addr, req->addr, 4);
        addr.port = req->port;
    }


    /* get availabe channel ID */
    channel_id = wps_get_available_channel();
    if (channel_id == -1)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }
    else
    {
        chl_info = wps_create_channel(channel_id);
        if (chl_info == NULL)
        {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
        }
        chl_info->mod_id = src_mod_id;
        chl_info->conn_type = conn_type;
        chl_info->net_id = req->net_id;
    }

    /* get empty request entry */
    req_info = wps_create_request(channel_id, 0);
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    sprintf(sendPipeName, "%s%d", WPS_PIPE_PREFIX, req_info->stk_request_id);
    req_info->send_pipe_handle = MSF_PIPE_CREATE(MSF_MODID_WPS, sendPipeName);
    if (req_info->send_pipe_handle < 0)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    req_info->state = WPS_REQ_CONNECTING;
    STKif_createStreamConnection (MSF_MODID_WPS, channel_id + 1, addr, conn_type,
        chl_info->net_id, sendPipeName, req->domain);

    wps_hold_bearer(chl_info->net_id);

    return;

error:
    /* prepare and send MSG_ID_WPS_CREATE_STREAM_RSP with failure cause */
    wps_send_create_stream_connection_rsp(src_mod_id, channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_close_stream_connection_req_hdlr(module_type src_mod_id, wps_close_stream_connection_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_uint8 i; */
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check channel id */
    if (req->channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    /* check channel if exists */
    chl_info = g_wps_cntx.channel_info[req->channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INACTIVE_CHANNEL;
        goto error;
    }

    STKif_closeConnection(MSF_MODID_WPS, req->channel_id + 1);

    wps_clear_request(req->channel_id, 0);
    wps_clear_channel(req->channel_id);

    error_cause = WPS_OK;

error:
   
    /* prepare and send MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP with failure cause */
    wps_send_close_stream_connection_rsp(src_mod_id, req->channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_stream_data_send_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_stream_data_send_req_hdlr(
    module_type src_mod_id,
    wps_stream_data_send_req_struct *req,
    wps_stream_data_send_req_var_struct *send_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS || !g_wps_cntx.channel_info[channel_id])
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = g_wps_cntx.channel_info[channel_id]->request_info[0];
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    
    if (req->seq_num != req_info->send_seq_num)
    {
        error_cause = WPS_ERROR_INVALID_SEQUENCE_NUM;
        goto error;
    }

    if (send_req_var == NULL || send_req_var->length == 0)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    req_info->send_buff_size = send_req_var->length;

    req_info->send_buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->send_buff_size);
    if (req_info->send_buff == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    memcpy(req_info->send_buff, send_req_var->data, send_req_var->length);
    req_info->send_buff_pos = 0;
    req_info->send_buff_size = send_req_var->length;
    req_info->send_seq_num = req->seq_num + 1;
    wps_write_to_sink(req_info);
    return;

error:
    wps_send_stream_data_send_rsp(src_mod_id, channel_id, error_cause, req->seq_num);

}


/*****************************************************************************
 * FUNCTION
 *  wps_stream_data_read_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_stream_data_read_req_hdlr(module_type src_mod_id, wps_stream_data_read_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS || !g_wps_cntx.channel_info[channel_id])
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];

    req_info = chl_info->request_info[0];
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }

    if (req->seq_num != req_info->seq_num)
    {
        error_cause = WPS_ERROR_INVALID_SEQUENCE_NUM;
        goto error;
    }

    if (req->read_length > 0)
    {
        req_info->reply_buff_size = req->read_length;
    }

    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->reply_buff_size);
    if (req_info->buff == NULL)
    {
        /* send back response and delete content */
        wps_send_stream_data_read_rsp(src_mod_id, channel_id, req_info, WPS_ERROR_NO_RESOURCE, 0);
        wps_clear_request(channel_id, 0);
        return;
    }

    req_info->seq_num = req->seq_num + 1;
    wps_read_reply_content(req_info);
    return;

error:
    wps_send_stream_data_read_rsp(src_mod_id, channel_id, req_info, error_cause, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_dl_progress_res_hdlr(module_type src_mod_id, wps_dl_progress_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;
    int isOpen;
    long available;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = res->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        return;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        return;
    }
    req_info = wps_search_req_info_by_id(channel_id, res->request_id);
    if (req_info == NULL || req_info->state == WPS_REQ_NULL)
    {
        return;
    }

    req_info->ind_sent = 0;

    MSF_PIPE_STATUS(req_info->pipe_handle, &isOpen, &available);
    if(available)
    {
        wps_read_reply_content(req_info);
    } 

    return;
}


#ifdef WAP_SEC_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_ses_create_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                 [IN]        
 *  screen_id(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wps_ses_job_struct *wps_ses_create_job(int src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;
    static unsigned int request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = MSF_MEM_ALLOCTYPE(MSF_MODID_WPS, wps_ses_job_struct);
    job->request_id = ++request_id;
    job->src = src;
    job->next = NULL;
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  wps_ses_add_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void wps_ses_add_job(wps_ses_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wps_cntx.wps_ses_queued_requests == NULL)
    {
        g_wps_cntx.wps_ses_queued_requests = job;
    }
    else
    {
        g_wps_cntx.wps_ses_queued_requests->next = job;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_session_info_req_hdlr
 * DESCRIPTION
 *  this function is to get current security session information.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_session_info_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_get_session_info_req_hdlr(module_type src_mod_id, wps_sec_get_session_info_req_struct *get_session_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = get_session_info_req->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }
    
    if (chl_info->security_id < 0)
    {
    	error_cause = WPS_ERROR_NOT_FOUND;
    	goto error;
    }    	

    SECif_getSessionInfo(MSF_MODID_WPS, channel_id, chl_info->security_id);
    return;

  error:
    wps_send_sec_get_session_info_rsp(src_mod_id, channel_id, NULL, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_current_cert_req_hdlr
 * DESCRIPTION
 *  this function is to get current certificate used in security session.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_get_current_cert_req_hdlr(module_type src_mod_id, wps_sec_get_current_cert_req_struct *get_current_cert_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = get_current_cert_req->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }
    
    if (chl_info->security_id < 0)
    {
    	error_cause = WPS_ERROR_NOT_FOUND;
    	goto error;
    }    	

    SECif_getCurrentCert(MSF_MODID_WPS, channel_id, chl_info->security_id);
    return;

  error:
    wps_send_sec_get_current_cert_rsp(src_mod_id, channel_id, NULL, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_cert_ids_req_hdlr
 * DESCRIPTION
 *  this function is to get all X.509 CA certificates stored in this device
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_get_cert_ids_req_hdlr(module_type src_mod_id, wps_sec_get_cert_ids_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);
    
    SECif_getCertIds(MSF_MODID_WPS, job->request_id, p->cert_options);
}


/*****************************************************************************
 * FUNCTION
 *  wps_ses_handle_get_cert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_sec_get_cert_req_hdlr(module_type src_mod_id, wps_sec_get_cert_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);

    SECif_getCert(MSF_MODID_WPS, job->request_id, p->cert_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_verify_cert_chain_req_hdlr
 * DESCRIPTION
 *  this function is to get all X.509 CA certificates stored in this device
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_verify_cert_chain_req_hdlr(module_type src_mod_id, wps_sec_verify_cert_chain_req_struct *verify_cert_chain_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sec_tls_asn1_certificate *certs;
    wps_sec_certificate_struct *wps_cert = NULL;
    wps_ses_job_struct *job;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!verify_cert_chain_req->cert_num)
    {
        wps_send_verify_cert_chain_rsp(src_mod_id, NULL, WPS_SEC_ERR_INVALID_PARAMETER);
        return;
    }    
    
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);

    certs = MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(sec_tls_asn1_certificate) * verify_cert_chain_req->cert_num);
    
    for(i = 0; i < verify_cert_chain_req->cert_num; i++)
    {
        wps_cert = &verify_cert_chain_req->certs[i];
        certs[i].format = wps_cert->format;
        certs[i].certLen = wps_cert->cert_len;
        certs[i].cert = wps_cert->cert;
    }
            
    SECif_verifyCertChain(MSF_MODID_WPS, job->request_id, certs, verify_cert_chain_req->cert_num);

    MSF_MEM_FREE(MSF_MODID_WPS, certs);
    return;
}
#endif /* WAP_SEC_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_http_auth_res_hdlr
 * DESCRIPTION
 *  this function is to handle the username/password response for HTTP authentication request
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  auth_res        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_http_auth_res_hdlr(module_type src_mod_id, wps_http_auth_res_struct *auth_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause;
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info = NULL;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auth_res == NULL)
    {
        /* invalid param */
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    channel_id = auth_res->channel_id;

    /* check channel id */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, auth_res->request_id);

    if (req_info == NULL || req_info->state != WPS_REQ_WAIT_RSP)
    {
        error_cause = WPS_ERROR_PENDING_REQ_EXIST;
        goto error;
    }

    if (strlen((char*)auth_res->username) == 0)
    {
        /* Abort the authentication */
        HDIc_widgetAction(MSF_MODID_STK, 0xfffffffe, req_info->stk_request_id);
        return;
    }

    /* store the username & password */
    if (req_info->username != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, req_info->username);
    }
    req_info->username = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)auth_res->username);

    if (req_info->password != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, req_info->password);
    }
    req_info->password = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)auth_res->password);

    /* notify STK to use the username and password */
    HDIc_widgetAction(MSF_MODID_STK, 0xffffffff, req_info->stk_request_id);
  error:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_status_query_req_hdlr
 * DESCRIPTION
 *  this function is to handle the query of WPS ready status
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_status_query_req_hdlr(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wps_ready_status == WPS_READY_STATUS_NULL)
    {
        if (wps_status_idx >= WPS_MAX_STATUS_REGISTER_NUM)
        {
            ASSERT(0);
        }
        wps_status_register[wps_status_idx++] = src_mod_id;
    }

    wps_send_status_query_rsp(src_mod_id, wps_ready_status);
}

#ifdef __IMPS__


/*****************************************************************************
 * FUNCTION
 *  wps_send_imps_ready_ind
 * DESCRIPTION
 *  this function is to notify WPS user that it is ready to provide service
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_imps_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wps_send_ilm(NULL, NULL, MSG_ID_WPS_READY_IND, MOD_IMPS);
}

#endif /* __IMPS__ */ 


/*****************************************************************************
 * FUNCTION
 *  wps_send_set_channel_rsp
 * DESCRIPTION
 *  this function is to response channel setup request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_set_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *set_channel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_channel_rsp = (wps_set_channel_rsp_struct*) construct_local_para(sizeof(wps_set_channel_rsp_struct), TD_CTRL);
    set_channel_rsp->result = error_cause;
    set_channel_rsp->channel_id = channel_id;

    wps_send_ilm(set_channel_rsp, NULL, MSG_ID_WPS_SET_CHANNEL_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_unset_channel_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_unset_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_rsp_struct *unset_channel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unset_channel_rsp =
        (wps_unset_channel_rsp_struct*) construct_local_para(sizeof(wps_unset_channel_rsp_struct), TD_CTRL);
    unset_channel_rsp->channel_id = channel_id;
    unset_channel_rsp->result = error_cause;

    wps_send_ilm(unset_channel_rsp, NULL, MSG_ID_WPS_UNSET_CHANNEL_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_reconfig_channel_rsp
 * DESCRIPTION
 *  this function is to response channel setup request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_reconfig_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_reconfig_channel_rsp_struct *reconfig_channel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reconfig_channel_rsp = (wps_reconfig_channel_rsp_struct*) construct_local_para(sizeof(reconfig_channel_rsp), TD_CTRL);
    reconfig_channel_rsp->result = error_cause;
    reconfig_channel_rsp->channel_id = channel_id;

    wps_send_ilm(reconfig_channel_rsp, NULL, MSG_ID_WPS_RECONFIG_CHANNEL_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_http_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  error_cause     [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_http_rsp(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 error_cause, kal_uint8 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *http_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_rsp = (wps_http_rsp_struct*) construct_local_para(sizeof(wps_http_rsp_struct), TD_CTRL);
    http_rsp->result = error_cause;

    if (error_cause == WPS_OK && req_info != NULL)
    {
        peer_buff_struct *peer_buff_ptr = NULL;
        kal_uint16 pdu_len;
        kal_uint16 len;
        wps_http_rsp_var_struct http_rsp_var;
        msf_hdr_t *hdr = NULL;
        MSF_UINT32 content_length;
        char *content_type;

        req_info->state = WPS_REQ_RSP_SENT;

        /* extract content length and content type */
        hdr = msf_hdr_create(MSF_MODID_WPS);
        msf_hdr_add_headers_from_text(hdr, req_info->rep->headers);

        if (msf_hdr_get_uint32(hdr, MSF_HDR_CONTENT_LENGTH, &content_length) && (content_length > 0))
        {
            http_rsp->content_length = content_length;
        }
        else
        {
            http_rsp->content_length = 0;
        }

        content_type = (char*)msf_hdr_get_string(hdr, MSF_HDR_CONTENT_TYPE);
        if (content_type != NULL)
        {
            if (strlen(content_type) >= 256)
                ASSERT(0) strcpy((char*)http_rsp->content_type, content_type);
        }
        http_rsp->more = (req_info->pipe_handle < 0) ? KAL_FALSE : KAL_TRUE;
        http_rsp->protocol = req_info->rep->protocol;
        http_rsp->request_id = req_info->request_id;
        http_rsp->status = req_info->rep->status;
        if (req_info->rep->newUrl != NULL)
        {
            http_rsp_var.new_url_len = strlen(req_info->rep->newUrl);
            http_rsp_var.new_url = (kal_uint8*) req_info->rep->newUrl;
        }
        else
        {
            http_rsp_var.new_url_len = 0;
        }
        if (req_info->rep->headers != NULL)
        {
            http_rsp_var.reply_header_len = strlen(req_info->rep->headers);
            http_rsp_var.reply_header = (kal_uint8*) req_info->rep->headers;
        }
        else
        {
            http_rsp_var.reply_header_len = 0;
        }
        if (req_info->reply_type == WPS_DATA_TYPE_BUFFER && req_info->buff_pos > 0)
        {
            http_rsp_var.reply_segment_len = req_info->buff_pos;
            http_rsp_var.reply_segment = req_info->buff;
        }
        else
        {
            http_rsp_var.reply_segment_len = 0;
        }

        pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_RSP, (void*)&http_rsp_var, NULL);
        if (pdu_len > 0)
        {
            peer_buff_ptr = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
            if (wps_pun_var_part
                (WPS_PUN_PACK, MSG_ID_WPS_HTTP_RSP, (void*)&http_rsp_var, get_pdu_ptr(peer_buff_ptr, &len)) != pdu_len)
            {
                free_peer_buff(peer_buff_ptr);
                peer_buff_ptr = NULL;
            }
        }
        if (req_info->reply_type == WPS_DATA_TYPE_BUFFER)
        {
            wps_clear_request_buff(req_info);
        }
        else
        {
            req_info->buff_pos = 0;
            http_rsp->more = KAL_FALSE;
        }

        msf_hdr_delete(hdr);
        wps_send_ilm(http_rsp, peer_buff_ptr, MSG_ID_WPS_HTTP_RSP, dst_id);
    }
    else
    {
        if (req_info != NULL)
        {
            http_rsp->request_id = req_info->request_id;
            http_rsp->cause = req_info->last_error;
            
            if(error_cause == WPS_ERROR_REQ_ABORT)
            {
                extern MSF_INT32 HDIa_getLastError(void);
                http_rsp->status = (kal_uint16)HDIa_getLastError();
            }
        }
        else
        {
            http_rsp->request_id = request_id;
        }
        wps_send_ilm(http_rsp, NULL, MSG_ID_WPS_HTTP_RSP, dst_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_read_content_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  error_cause     [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_read_content_rsp(
    module_type dst_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_uint8 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *read_content_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_content_rsp =
        (wps_read_content_rsp_struct*) construct_local_para(sizeof(wps_read_content_rsp_struct), TD_CTRL);
    read_content_rsp->result = error_cause;

    if (error_cause == WPS_OK && req_info != NULL)
    {
        peer_buff_struct *peer_buff_ptr = NULL;
        kal_uint16 pdu_len;
        kal_uint16 len;
        wps_read_content_rsp_var_struct read_content_rsp_var;

        read_content_rsp->more = (req_info->pipe_handle < 0) ? KAL_FALSE : KAL_TRUE;
        read_content_rsp->request_id = req_info->request_id;
        read_content_rsp->seq_num = req_info->seq_num;

        if (req_info->buff_pos > 0)
        {
            read_content_rsp_var.reply_segment_len = req_info->buff_pos;
            read_content_rsp_var.reply_segment = req_info->buff;
            pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_READ_CONTENT_RSP, (void*)&read_content_rsp_var, NULL);
            if (pdu_len > 0)
            {
                peer_buff_ptr = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
                if (wps_pun_var_part
                    (WPS_PUN_PACK, MSG_ID_WPS_READ_CONTENT_RSP, (void*)&read_content_rsp_var,
                     get_pdu_ptr(peer_buff_ptr, &len)) != pdu_len)
                {
                    free_peer_buff(peer_buff_ptr);
                    peer_buff_ptr = NULL;
                }
            }
        }

        wps_clear_request_buff(req_info);
        wps_send_ilm(read_content_rsp, peer_buff_ptr, MSG_ID_WPS_READ_CONTENT_RSP, dst_id);
        
        req_info->state = WPS_REQ_RSP_SENT;
    }
    else
    {
        read_content_rsp->request_id = request_id;
        wps_send_ilm(read_content_rsp, NULL, MSG_ID_WPS_READ_CONTENT_RSP, dst_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_dl_progress_ind
 * DESCRIPTION
 *  this function is to send the HTTP/WSP reply content downloading status indication to the callee.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  status          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_dl_progress_ind(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_ind_struct *dl_prog_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dl_prog_ind = (wps_dl_progress_ind_struct*) construct_local_para(sizeof(wps_dl_progress_ind_struct), TD_CTRL);
    dl_prog_ind->request_id = req_info->request_id;
    dl_prog_ind->acc_size = req_info->acc_size;
    dl_prog_ind->seq_num = req_info->seq_num;
    dl_prog_ind->status = status;
    if(status == WPS_DL_STATUS_ABORT)
    {
        dl_prog_ind->cause = req_info->last_error;
    }

    wps_send_ilm(dl_prog_ind, NULL, MSG_ID_WPS_DL_PROGRESS_IND, dst_id);
}

/************************************************************
 * Global function definitions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_send_cancel_rsp
 * DESCRIPTION
 *  this function is to response cancel request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_cancel_rsp(module_type dst_id, kal_uint8 request_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_rsp_struct *cancel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cancel_rsp = (wps_cancel_rsp_struct*) construct_local_para(sizeof(wps_cancel_rsp_struct), TD_CTRL);
    cancel_rsp->request_id = request_id;
    cancel_rsp->result = error_cause;

    wps_send_ilm(cancel_rsp, NULL, MSG_ID_WPS_CANCEL_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_clear_rsp
 * DESCRIPTION
 *  this function is to response clear request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_clear_rsp(module_type dst_id, kal_uint8 request_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_rsp_struct *clear_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_rsp = (wps_clear_rsp_struct*) construct_local_para(sizeof(wps_clear_rsp_struct), TD_CTRL);
    clear_rsp->request_id = request_id;
    clear_rsp->result = error_cause;

    wps_send_ilm(clear_rsp, NULL, MSG_ID_WPS_CLEAR_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_post_content_ind
 * DESCRIPTION
 *  this function is to send complete indication of segment content post
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_post_content_ind(module_type dst_id, kal_uint8 request_id, kal_uint8 error_cause, kal_uint8 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_post_content_ind_struct *post_content_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    post_content_ind =
        (wps_post_content_ind_struct*) construct_local_para(sizeof(wps_post_content_ind_struct), TD_CTRL);
    post_content_ind->request_id = request_id;
    post_content_ind->result = error_cause;
    post_content_ind->seq_num = seq_num;

    wps_send_ilm(post_content_ind, NULL, MSG_ID_WPS_POST_CONTENT_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_push_ind
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_push_ind(module_type dst_id, kal_uint8 *content_type, kal_uint32 content_length, kal_wchar *data_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_push_ind_struct *push_ind;
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_ind = (wps_push_ind_struct*) construct_local_para(sizeof(wps_push_ind_struct), TD_CTRL);
    strcpy((char*)push_ind->content_type, (const char*)content_type);
    push_ind->content_length = content_length;
    len = widget_ucs2_length((kal_uint8*) data_path);
    if (len >= 256)
    {
        ASSERT(0);
    }
    kal_mem_cpy(push_ind->data_path, data_path, ((len + 1) * 2));
    wps_send_ilm(push_ind, NULL, MSG_ID_WPS_PUSH_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_create_stream_connection_rsp
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_create_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_create_stream_connection_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_create_stream_connection_rsp_struct*) construct_local_para(sizeof(wps_create_stream_connection_rsp_struct), TD_CTRL);
    rsp->result = error_cause;
    rsp->channel_id = channel_id;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_create_stream_connection_rsp
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_send_close_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_close_stream_connection_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_close_stream_connection_rsp_struct*) construct_local_para(sizeof(wps_close_stream_connection_rsp_struct), TD_CTRL);
    rsp->result = error_cause;
    rsp->channel_id = channel_id;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_create_stream_connection_rsp
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_stream_connection_close_ind(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_stream_connection_closed_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (wps_stream_connection_closed_ind_struct*) construct_local_para(sizeof(wps_stream_connection_closed_ind_struct), TD_CTRL);
    ind->error_cause = error_cause;
    ind->channel_id = channel_id;

    wps_send_ilm(ind, NULL, MSG_ID_WPS_STREAM_CONNECTION_CLOSED_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_post_content_ind
 * DESCRIPTION
 *  this function is to send complete indication of segment content post
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_stream_data_send_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause, kal_uint8 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_stream_data_send_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_stream_data_send_rsp_struct*) construct_local_para(sizeof(wps_stream_data_send_rsp_struct), TD_CTRL);
    rsp->channel_id = channel_id;
    rsp->result = error_cause;
    rsp->seq_num = seq_num;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_STREAM_DATA_SEND_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_read_content_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  error_cause     [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_stream_data_read_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_bool more)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_stream_data_read_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_stream_data_read_rsp_struct*) construct_local_para(sizeof(wps_stream_data_read_rsp_struct), TD_CTRL);
    rsp->channel_id = channel_id;
    rsp->result = error_cause;

    if (error_cause == WPS_OK && req_info != NULL)
    {
        peer_buff_struct *peer_buff_ptr = NULL;
        kal_uint16 pdu_len;
        kal_uint16 len;
        wps_stream_data_read_rsp_var_struct read_rsp_var;

        rsp->more = more;
        rsp->seq_num = req_info->seq_num;

        if (req_info->buff_pos > 0)
        {
            read_rsp_var.length = req_info->buff_pos;
            read_rsp_var.data = req_info->buff;
            pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_STREAM_DATA_READ_RSP, (void*)&read_rsp_var, NULL);
            if (pdu_len > 0)
            {
                peer_buff_ptr = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
                if (wps_pun_var_part
                    (WPS_PUN_PACK, MSG_ID_WPS_STREAM_DATA_READ_RSP, (void*)&read_rsp_var,
                     get_pdu_ptr(peer_buff_ptr, &len)) != pdu_len)
                {
                    free_peer_buff(peer_buff_ptr);
                    peer_buff_ptr = NULL;
                }
            }
        }

        wps_clear_request_buff(req_info);
        wps_send_ilm(rsp, peer_buff_ptr, MSG_ID_WPS_STREAM_DATA_READ_RSP, dst_id);
        
        req_info->state = WPS_REQ_RSP_SENT;
    }
    else
    {
        wps_send_ilm(rsp, NULL, MSG_ID_WPS_STREAM_DATA_READ_RSP, dst_id);
    }
}

#ifdef WAP_SEC_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_session_info_rsp
 * DESCRIPTION
 *  this function is to send the result of getting session information request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  channel_id          [IN]        
 *  session_info        [?]         
 *  error_cause         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_get_session_info_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_session_info_response_t *session_info,
    kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    wps_sec_get_session_info_rsp_struct *get_session_info_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_session_info_rsp =
        (wps_sec_get_session_info_rsp_struct*) construct_local_para(
                                                sizeof(wps_sec_get_session_info_rsp_struct),
                                                TD_CTRL);

    chl_info = g_wps_cntx.channel_info[channel_id];
    get_session_info_rsp->channel_id = channel_id;

    if (error_cause == WPS_OK && session_info != NULL)
    {
        get_session_info_rsp->result = WPS_OK;
        get_session_info_rsp->sec_conn_type = (kal_uint8) session_info->connectionType;
        get_session_info_rsp->key_exchange_alg = (kal_uint16) session_info->keyExchangeAlgorithm;
        get_session_info_rsp->blk_encrypt_alg = (kal_uint8) session_info->encrAlg;
        get_session_info_rsp->hash_alg = (kal_uint8) session_info->hMacAlg;
    }
    else
    {
    #if 1    	
        get_session_info_rsp->result = WPS_ERROR_NOT_FOUND;    
    #else    	    
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
    }

    wps_send_ilm(get_session_info_rsp, NULL, MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_issuer_str
 * DESCRIPTION
 *  this function is to used to get the issuer (or subject) name of a certificate
 * CALLS
 *  
 * PARAMETERS
 *  charSet         [IN]        
 *  issuer          [?]         
 *  issuerLen       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *wps_sec_get_issuer_str(MSF_INT16 charSet, void *issuer, int issuerLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 nbrIssuerAtts;
    sec_name_attribute_t *issuerAtt = NULL;
    int i, attLen, attStrPos;
    char *attStr, *tmpStr;
    long tmpStrLen;
    int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int sec_tiCvtToUtf8(unsigned char *strToCvt, long strToCvtLen, char *dst, long *dstLen, MSF_INT16 charSet);

    /* Use parser to get issuer attributes. */
    if (charSet == -1)  /* X.509 certificate */
    {
        SEC_x509GetNbrIssuerStrings(issuer, (MSF_UINT16) issuerLen, &nbrIssuerAtts);
        issuerAtt = (sec_name_attribute_t*) MSF_MEM_ALLOC(MSF_MODID_WPS, nbrIssuerAtts * sizeof(sec_name_attribute_t));
        SEC_x509GetIssuerAttributes(
            MSF_MODID_WPS,
            (const unsigned char*)issuer,
            (MSF_UINT16) issuerLen,
            &nbrIssuerAtts,
            issuerAtt);
    }
    else    /* WTLS certificate */
    {
        SEC_wtlsGetIssuerAttributes(MSF_MODID_WPS, issuer, (MSF_UINT16) issuerLen, &nbrIssuerAtts, NULL);
        issuerAtt = (sec_name_attribute_t*) MSF_MEM_ALLOC(MSF_MODID_WPS, nbrIssuerAtts * sizeof(sec_name_attribute_t));
        SEC_wtlsGetIssuerAttributes(
            MSF_MODID_WPS,
            (const unsigned char*)issuer,
            (MSF_UINT16) issuerLen,
            &nbrIssuerAtts,
            issuerAtt);
        for (i = 0; i < nbrIssuerAtts; i++)
        {
            issuerAtt[i].attributeCharSet = charSet;
        }
    }

    /* Get length of string to show */
    attLen = 0;
    attStrPos = 0;
    for (i = 0; i < nbrIssuerAtts; i++)
    {
        attLen += issuerAtt[i].attributeValueLen * 2;
    }

    attStr = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, (attLen * 2 + attStrPos + nbrIssuerAtts + 5));
    tmpStr = attStr;

    for (i = 0; i < nbrIssuerAtts; i++)
    {
        tmpStrLen = (issuerAtt[i].attributeValueLen * 2) + 2;

        result = sec_tiCvtToUtf8(
                    issuerAtt[i].attributeValue,
                    issuerAtt[i].attributeValueLen,
                    tmpStr,
                    &tmpStrLen,
                    issuerAtt[i].attributeCharSet);
        if (result != SEC_ERR_OK)
        {
            for (i = 0; i < nbrIssuerAtts; i++)
            {
                MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt[i].attributeValue);
            }
            MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt);
            return NULL;
        }

        attStrPos += tmpStrLen;
        tmpStr += (tmpStrLen + 1);
        attStr[attStrPos++] = ',';
    }   /* for */

    attStrPos--;
    attStr[attStrPos] = '\0';
    for (i = 0; i < nbrIssuerAtts; i++)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt[i].attributeValue);
    }
    MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt);

    return attStr;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_sig_alg_name
 * DESCRIPTION
 *  this function is to used to get signature algorithm name of a certificate
 * CALLS
 *  
 * PARAMETERS
 *  sig_alg_name            [?]         
 *  sig_alg_name_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *wps_sec_get_sig_alg_name(void *sig_alg_name, MSF_UINT16 sig_alg_name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const unsigned char wps_oid_rsa[] = "\x2A\x86\x48\x86\xF7\x0D\x01\x01";
    const unsigned char wps_oid_dsa[] = "\x2A\x86\x48\xCE\x38\x04\x03";
    unsigned char *cert = (unsigned char*)sig_alg_name;
    MSF_UINT16 i = 0, dsa = 0;
    char *name = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, 32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sig_alg_name_len - 1); i++)
    {
        if (*cert == wps_oid_rsa[i])
        {
            cert++;
        }
        else if (*cert == wps_oid_dsa[i])
        {
            dsa = 1;
            cert++;
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WPS, name);
            return NULL;
        }
    }

    if (dsa == 0)
    {
        if (*cert == 5)
        {
            sprintf(name, "sha1RSA");
        }
        else if (*cert == 4)
        {
            sprintf(name, "md5RSA");
        }
        else if (*cert == 2)
        {
            sprintf(name, "md2RSA");
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WPS, name);
            return NULL;
        }
    }
    else
    {
        if (*cert == 3)
        {
            sprintf(name, "sha1DSA");
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WPS, name);
            return NULL;
        }
    }

    return name;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_convert_cert
 * DESCRIPTION
 *  this function is to used to convert sec_certificate_t type to wps_sec_cert_content_struct type
 * CALLS
 *  
 * PARAMETERS
 *  sig_alg_name            [?]         
 *  sig_alg_name_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wps_sec_convert_cert(kal_uint8 format, sec_certificate_t *parsed_cert, wps_sec_cert_content_struct *cert_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cert_content->type = format;
    cert_content->version = (kal_uint8) parsed_cert->certificate_version;
    cert_content->not_after = (kal_uint32) parsed_cert->valid_not_after;
    cert_content->not_before = (kal_uint32) parsed_cert->valid_not_before;

    if (format == SEC_CERT_FORMAT_X509)
    {
        if (parsed_cert->issuer)
        {
            kal_uint8 *issuer =
                (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert->issuer, parsed_cert->_u.x509.issuerLen);
            if (issuer)
            {
                cert_content->issuer_len = strlen((char*)issuer);
                if (cert_content->issuer_len > 256)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(cert_content->issuer, issuer, cert_content->issuer_len);
                MSF_MEM_FREE(MSF_MODID_WPS, issuer);
            }
        }
        if (parsed_cert->subject)
        {
            kal_uint8 *subject =
                (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert->subject, parsed_cert->_u.x509.subjectLen);
            if (subject)
            {
                cert_content->subject_len = strlen((char*)subject);
                if (cert_content->subject_len > 256)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(cert_content->subject, subject, cert_content->subject_len);
                MSF_MEM_FREE(MSF_MODID_WPS, subject);
            }
        }
        if (parsed_cert->_u.x509.serialNumber)
        {
            cert_content->serial_num_len = (kal_uint16) parsed_cert->_u.x509.serialNumberLen;
            if (cert_content->serial_num_len > 128)
            {
                ASSERT(0);
            }
            kal_mem_cpy(
                cert_content->serial_num,
                parsed_cert->_u.x509.serialNumber,
                parsed_cert->_u.x509.serialNumberLen);
        }
        if (parsed_cert->_u.x509.signatureAlgorithm)
        {
            kal_uint8 *sig_alg_name =
                (kal_uint8*) wps_sec_get_sig_alg_name(
                                parsed_cert->_u.x509.signatureAlgorithm,
                                parsed_cert->_u.x509.signatureAlgorithmLen);
            if (sig_alg_name)
            {
                cert_content->sig_alg_name_len = strlen((char*)sig_alg_name);
                if (cert_content->sig_alg_name_len > 128)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(
                    cert_content->sig_alg_name,
                    sig_alg_name,
                    cert_content->sig_alg_name_len);
                MSF_MEM_FREE(MSF_MODID_WPS, sig_alg_name);
            }
        }
    }
    else if (format == SEC_CERT_FORMAT_WTLS)
    {
        if (parsed_cert->issuer)
        {
            kal_uint8 *issuer =
                (kal_uint8*) wps_sec_get_issuer_str(
                                    parsed_cert->_u.wtls.issuercharacterSet,
                                    parsed_cert->issuer,
                                    parsed_cert->_u.wtls.issuerLen);
            if (issuer)
            {
                cert_content->issuer_len = strlen((char*)issuer);
                if (cert_content->issuer_len > 256)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(cert_content->issuer, issuer, cert_content->issuer_len);
                MSF_MEM_FREE(MSF_MODID_WPS, issuer);
            }
        }
        if (parsed_cert->subject)
        {
            kal_uint8 *subject =
                (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert->subject, parsed_cert->_u.wtls.subjectLen);
            if (subject)
            {
                cert_content->subject_len = strlen((char*)subject);
                if (cert_content->subject_len > 256)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(cert_content->subject, subject, cert_content->subject_len);
                MSF_MEM_FREE(MSF_MODID_WPS, subject);
            }
        }
        
        cert_content->serial_num_len = 0;

        if (parsed_cert->_u.wtls.signature_algorithm == 0)   /* anonymous */
        {
            kal_sprintf((char*)cert_content->sig_alg_name, "anonymous");
        }
        else if (parsed_cert->_u.wtls.signature_algorithm == 1)      /* ecdsa_sha */
        {
            kal_sprintf((char*)cert_content->sig_alg_name, "ecdsa_sha");
        }
        else if (parsed_cert->_u.wtls.signature_algorithm == 2)      /* rsa_sha */
        {
            kal_sprintf((char*)cert_content->sig_alg_name, "rsa_sha");
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_convert_rsa_public_key
 * DESCRIPTION
 *  this function is to used to convert sec_certificate_t type to wps_sec_cert_content_struct type
 * CALLS
 *  
 * PARAMETERS
 *  sig_alg_name            [?]         
 *  sig_alg_name_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wps_sec_convert_rsa_public_key(sec_x509_rsa_mod_and_exp_t *rsa_mod_and_exp, wps_sec_rsa_public_key_struct *rsa_public_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* modulus */
    if (rsa_mod_and_exp->rsa_modulus && rsa_mod_and_exp->modLen > 0)
    {
        rsa_public_key->mod_len = rsa_mod_and_exp->modLen;
        rsa_public_key->rsa_modulus = (kal_uint8*)get_ctrl_buffer((kal_uint16)rsa_mod_and_exp->modLen);
        kal_mem_cpy(rsa_public_key->rsa_modulus, rsa_mod_and_exp->rsa_modulus, rsa_mod_and_exp->modLen);
    }
    else
    {
        rsa_public_key->rsa_modulus = NULL;
        rsa_public_key->mod_len = 0;
    }

    /* exponent */
    if (rsa_mod_and_exp->rsa_exponent && rsa_mod_and_exp->expLen > 0)
    {
        rsa_public_key->exp_len = rsa_mod_and_exp->expLen;
        rsa_public_key->rsa_exponent = (kal_uint8*)get_ctrl_buffer((kal_uint16)rsa_mod_and_exp->expLen);
        kal_mem_cpy(rsa_public_key->rsa_exponent, rsa_mod_and_exp->rsa_exponent, rsa_mod_and_exp->expLen);
    }
    else
    {
        rsa_public_key->rsa_exponent = NULL;
        rsa_public_key->exp_len = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_current_cert_rsp
 * DESCRIPTION
 *  this function is to send the result of getting current certificate request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  channel_id          [IN]        
 *  current_cert        [?]         
 *  error_cause         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_get_current_cert_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_current_cert_response_t *current_cert,
    kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *get_current_cert_rsp;
    sec_certificate_t parsed_cert;
    kal_uint8 format = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&parsed_cert, 0, sizeof(sec_certificate_t));

    get_current_cert_rsp =
        (wps_sec_get_current_cert_rsp_struct*) construct_local_para(
                                                sizeof(wps_sec_get_current_cert_rsp_struct),
                                                TD_CTRL);

    get_current_cert_rsp->channel_id = channel_id;

    if (error_cause == WPS_OK && current_cert != NULL)
    {
        format = current_cert->format;
        if (SEClib_parseCertificate(current_cert->format, current_cert->cert, current_cert->certLen, &parsed_cert) ==
            SEC_ERR_OK)
        {
            error_cause = WPS_OK;
        }
        else
        {
            error_cause = WPS_ERROR_NOT_FOUND;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (error_cause == WPS_OK)
    {
        get_current_cert_rsp->result = WPS_OK;
        get_current_cert_rsp->channel_id = channel_id;
        get_current_cert_rsp->type = format;
        get_current_cert_rsp->version = (kal_uint8) parsed_cert.certificate_version;
        get_current_cert_rsp->not_after = (kal_uint32) parsed_cert.valid_not_after;
        get_current_cert_rsp->not_before = (kal_uint32) parsed_cert.valid_not_before;

        if (format == SEC_CERT_FORMAT_X509)
        {
            if (parsed_cert.issuer)
            {
                kal_uint8 *issuer =
                    (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert.issuer, parsed_cert._u.x509.issuerLen);
                if (issuer)
                {
                    get_current_cert_rsp->issuer_len = strlen((char*)issuer);
                    if (get_current_cert_rsp->issuer_len > 256)
                    {
                        ASSERT(0);
                    }
                    kal_mem_cpy(get_current_cert_rsp->issuer, issuer, get_current_cert_rsp->issuer_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, issuer);
                }
            }
            if (parsed_cert.subject)
            {
                kal_uint8 *subject =
                    (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert.subject, parsed_cert._u.x509.subjectLen);
                if (subject)
                {
                    get_current_cert_rsp->subject_len = strlen((char*)subject);
                    if (get_current_cert_rsp->subject_len > 256)
                    {
                        ASSERT(0);
                    }
                    kal_mem_cpy(get_current_cert_rsp->subject, subject, get_current_cert_rsp->subject_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, subject);
                }
            }
            if (parsed_cert._u.x509.serialNumber)
            {
                get_current_cert_rsp->serial_num_len = (kal_uint16) parsed_cert._u.x509.serialNumberLen;
                if (get_current_cert_rsp->serial_num_len > 128)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(
                    get_current_cert_rsp->serial_num,
                    parsed_cert._u.x509.serialNumber,
                    parsed_cert._u.x509.serialNumberLen);
            }
            if (parsed_cert._u.x509.signatureAlgorithm)
            {
                kal_uint8 *sig_alg_name =
                    (kal_uint8*) wps_sec_get_sig_alg_name(
                                    parsed_cert._u.x509.signatureAlgorithm,
                                    parsed_cert._u.x509.signatureAlgorithmLen);
                if (sig_alg_name)
                {
                    get_current_cert_rsp->sig_alg_name_len = strlen((char*)sig_alg_name);
                    if (get_current_cert_rsp->sig_alg_name_len > 128)
                    {
                        ASSERT(0);
                    }
                    kal_mem_cpy(
                        get_current_cert_rsp->sig_alg_name,
                        sig_alg_name,
                        get_current_cert_rsp->sig_alg_name_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, sig_alg_name);
                }
            }
        }
        else if (format == SEC_CERT_FORMAT_WTLS)
        {
            if (parsed_cert.issuer)
            {
                kal_uint8 *issuer =
                    (kal_uint8*) wps_sec_get_issuer_str(
                                    parsed_cert._u.wtls.issuercharacterSet,
                                    parsed_cert.issuer,
                                    parsed_cert._u.wtls.issuerLen);
                if (issuer)
                {
                    get_current_cert_rsp->issuer_len = strlen((char*)issuer);
                    if (get_current_cert_rsp->issuer_len > 256)
                    {
                        ASSERT(0);
                    }
                    kal_mem_cpy(get_current_cert_rsp->issuer, issuer, get_current_cert_rsp->issuer_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, issuer);
                }
            }
            if (parsed_cert.subject)
            {
                kal_uint8 *subject =
                    (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert.subject, parsed_cert._u.wtls.subjectLen);
                if (subject)
                {
                    get_current_cert_rsp->subject_len = strlen((char*)subject);
                    if (get_current_cert_rsp->subject_len > 256)
                    {
                        ASSERT(0);
                    }
                    kal_mem_cpy(get_current_cert_rsp->subject, subject, get_current_cert_rsp->subject_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, subject);
                }
            }
            
            get_current_cert_rsp->serial_num_len = 0;
            
            if (parsed_cert._u.wtls.signature_algorithm == 0)   /* anonymous */
            {
                kal_sprintf((char*)get_current_cert_rsp->sig_alg_name, "anonymous");
            }
            else if (parsed_cert._u.wtls.signature_algorithm == 1)      /* ecdsa_sha */
            {
                kal_sprintf((char*)get_current_cert_rsp->sig_alg_name, "ecdsa_sha");
            }
            else if (parsed_cert._u.wtls.signature_algorithm == 2)      /* rsa_sha */
            {
                kal_sprintf((char*)get_current_cert_rsp->sig_alg_name, "rsa_sha");
            }
        }
    }
    else
    {
        get_current_cert_rsp->result = WPS_ERROR_NOT_FOUND;
    }

    wps_send_ilm(get_current_cert_rsp, NULL, MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_cert_ids_rsp
 * DESCRIPTION
 *  this function is to send the indication of a x509 ca certificate
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  total               [IN]        
 *  cert_ids            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_sec_get_cert_ids_rsp(MSF_UINT8 dst_id, MSF_UINT8 total, MSF_UINT8 *cert_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_ids_rsp_struct *p;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_sec_get_cert_ids_rsp_struct*) construct_local_para(sizeof(wps_sec_get_cert_ids_rsp_struct), TD_RESET);

    p->total = total;

    if (total > 0)
    {
        ASSERT(cert_ids);
        for(i = 0; i < total; i++)
        {
            p->cert_ids[i] = cert_ids[i];
        }
    }

    wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_GET_CERT_IDS_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_cert_rsp
 * DESCRIPTION
 *  this function is to send the indication of a x509 ca certificate
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  index               [IN]        
 *  result              [IN]        
 *  not_after           [IN]        
 *  not_before          [IN]        
 *  type                [IN]        
 *  version             [IN]        
 *  issuer              [IN]        
 *  subject             [IN]        
 *  serial_num          [IN]        
 *  sig_alg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_get_cert_rsp(
    MSF_UINT8 dst_id,
    MSF_UINT8 index,
    MSF_UINT8 result,
    MSF_UINT32 not_after,
    MSF_UINT32 not_before,
    MSF_UINT8 type,
    MSF_UINT8 version,
    const char *issuer,
    const char *subject,
    const char *serial_num,
    const char *sig_alg_name,
    unsigned char *rsa_modulus,
    MSF_UINT16 mod_len,
    unsigned char *rsa_exponent,
    MSF_UINT16 exp_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_rsp_struct *p;
    wps_sec_cert_content_struct *cert;
    wps_sec_rsa_public_key_struct *key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_sec_get_cert_rsp_struct*) construct_local_para(sizeof(wps_sec_get_cert_rsp_struct), TD_RESET);

    p->result = result;
    p->cert_id = index;

    if (result != WPS_OK)
    {
        wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_GET_CERT_RSP, dst_id);
    }

    cert = &p->cert;
    key = &p->rsa_public_key;

    cert->type = type;
    cert->version = (kal_uint8) version;
    cert->not_after = (kal_uint32) not_after;
    cert->not_before = (kal_uint32) not_before;

    if (issuer)
    {
        cert->issuer_len = strlen(issuer);
        kal_mem_cpy(cert->issuer, issuer, cert->issuer_len);
    }
    if (subject)
    {
        cert->subject_len = strlen(subject);
        kal_mem_cpy(cert->subject, subject, cert->subject_len);
    }
    if (serial_num)
    {
        cert->serial_num_len = strlen(serial_num);
        kal_mem_cpy(cert->serial_num, serial_num, cert->serial_num_len);
    }
    if (sig_alg_name)
    {
        cert->sig_alg_name_len = strlen((char*)sig_alg_name);
        kal_mem_cpy(cert->sig_alg_name, sig_alg_name, cert->sig_alg_name_len);
    }

    if (rsa_modulus && mod_len > 0)
    {
        key->mod_len = mod_len;
        key->rsa_modulus = (kal_uint8*) get_ctrl_buffer((kal_uint16) mod_len);
        kal_mem_cpy(key->rsa_modulus, rsa_modulus, mod_len);
    }

    /* exponent */
    if (rsa_exponent && exp_len > 0)
    {
        key->exp_len = exp_len;
        key->rsa_exponent = (kal_uint8*) get_ctrl_buffer((kal_uint16) exp_len);
        kal_mem_cpy(key->rsa_exponent, rsa_exponent, exp_len);
    }

    wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_GET_CERT_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_verify_cert_chain_rsp
 * DESCRIPTION
 *  this function is to send the result of verify certificate chain request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  channel_id          [IN]        
 *  current_cert        [?]         
 *  error_cause         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_verify_cert_chain_rsp(
    module_type dst_id,
    sec_verify_cert_chain_response_t *rsp,
    kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_verify_cert_chain_rsp_struct *verify_cert_chain_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    verify_cert_chain_rsp =
        (wps_sec_verify_cert_chain_rsp_struct*) construct_local_para(sizeof(wps_sec_verify_cert_chain_rsp_struct), TD_RESET);

    if(rsp == NULL)
    {
        verify_cert_chain_rsp->result = error_cause;
        goto error;
    }

    switch(rsp->result)
    {
    case SEC_ERR_OK:
        verify_cert_chain_rsp->result = WPS_SEC_OK;
        break;
    case SEC_ERR_INSUFFICIENT_MEMORY:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_INSUFFICIENT_MEMORY;
        break;
    case SEC_ERR_INVALID_PARAMETER:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_INVALID_PARAMETER;
        break;
    case SEC_ERR_CRYPTOLIB_NOT_INITIALISED:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_CRYPTOLIB_NOT_INITIALISED;
        break;
    case SEC_ERR_INVALID_KEY:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_INVALID_KEY;
        break;
    case SEC_ERR_UNKNOWN_CERTIFICATE_TYPE:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_UNKNOWN_CERTIFICATE_TYPE;
        break;
    case SEC_ERR_BAD_CERTIFICATE:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_BAD_CERTIFICATE;
        break;
    case SEC_ERR_CERTIFICATE_EXPIRED:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_CERTIFICATE_EXPIRED;
        break;
    case SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE;
        break;
    default:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
        break;
    }

    verify_cert_chain_rsp->format = rsp->format;
    if(rsp->rootCert != NULL && rsp->rootLen > 0)
    {
        int file_handle, result;
        kal_uint8 *filename;
        char tempfile[] = "/jal_root.cer";
        
        MSF_FILE_REMOVE(tempfile);
        file_handle = MSF_FILE_OPEN(MSF_MODID_WPS, tempfile, MSF_FILE_SET_WRONLY| MSF_FILE_SET_CREATE, rsp->rootLen);
        if(file_handle < 1)
        {
            verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
            goto error;
        }
        
    	result = MSF_FILE_WRITE(file_handle, rsp->rootCert, rsp->rootLen);
        if ((result < rsp->rootLen) || (result == -1))
    	{
    		MSF_FILE_CLOSE(file_handle);		
    		MSF_FILE_REMOVE(tempfile);
            verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
    		goto error;
    	}

        MSF_FILE_CLOSE(file_handle);		

        filename = HDI_FileNameTranslate(tempfile);

        if (!filename)
    	{
    		MSF_FILE_REMOVE(tempfile);
            verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
    		goto error;
    	}

        widget_ucs2_strcpy((kal_uint8*)verify_cert_chain_rsp->root_cert, (const kal_uint8*)filename);
        verify_cert_chain_rsp->root_len = rsp->rootLen;

        HDI_FileNameFree(filename);            
    }

error:
    wps_send_ilm(verify_cert_chain_rsp, NULL, MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP, dst_id);
}

#endif /* WAP_SEC_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_send_http_auth_ind
 * DESCRIPTION
 *  this function is to send the indication of HTTP authentication request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  request_id      [IN]        
 *  auth_type       [IN]        
 *  realm           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_http_auth_ind(
    module_type dst_id,
    kal_uint8 channel_id,
    kal_uint8 request_id,
    kal_uint8 auth_type,
    kal_uint8 *realm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_struct *http_auth_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_auth_ind = (wps_http_auth_ind_struct*) construct_local_para(sizeof(wps_http_auth_ind_struct), TD_CTRL);

    http_auth_ind->request_id = request_id;
    http_auth_ind->channel_id = channel_id;
    http_auth_ind->auth_type = auth_type;
    memcpy(http_auth_ind->realm, realm, 256);
    http_auth_ind->realm[255] = 0;
    http_auth_ind->realm_len = strlen((char*)http_auth_ind->realm);

    wps_send_ilm(http_auth_ind, NULL, MSG_ID_WPS_HTTP_AUTH_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_status_query_rsp
 * DESCRIPTION
 *  this function is to send the response of status query
 * CALLS
 *  
 * PARAMETERS
 *  dst_id      [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_status_query_rsp(module_type dst_id, kal_uint8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_status_query_rsp_struct *status_query_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status_query_rsp =
        (wps_status_query_rsp_struct*) construct_local_para(sizeof(wps_status_query_rsp_struct), TD_CTRL);

    status_query_rsp->status = status;

    wps_send_ilm(status_query_rsp, NULL, MSG_ID_WPS_STATUS_QUERY_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_fsm
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_fsm(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_WAP_READY_IND:
            wps_wap_ready_ind_hdlr();
            break;
        case MSG_ID_WPS_SET_CHANNEL_REQ:
        {
            wps_set_channel_req_var_struct set_channel_req_var;

            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &set_channel_req_var,
                    get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_set_channel_req_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_set_channel_req_struct*) ilm_ptr->local_para_ptr,
                    &set_channel_req_var);
            }
            else
            {
                wps_set_channel_req_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_set_channel_req_struct*) ilm_ptr->local_para_ptr,
                    NULL);
            }
        }
            break;
        case MSG_ID_WPS_UNSET_CHANNEL_REQ:
            wps_unset_channel_req_hdlr(ilm_ptr->src_mod_id, (wps_unset_channel_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_RECONFIG_CHANNEL_REQ:
            wps_reconfig_channel_req_hdlr(ilm_ptr->src_mod_id, (wps_reconfig_channel_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_CREATE_STREAM_CONNECTION_REQ:
            wps_create_stream_connection_req_hdlr(ilm_ptr->src_mod_id, (wps_create_stream_connection_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_CLOSE_STREAM_CONNECTION_REQ:
            wps_close_stream_connection_req_hdlr(ilm_ptr->src_mod_id, (wps_close_stream_connection_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_STREAM_DATA_SEND_REQ:
            {
                wps_stream_data_send_req_var_struct send_req_var;

                memset(&send_req_var, 0, sizeof(wps_stream_data_send_req_var_struct));
                if (ilm_ptr->peer_buff_ptr && 
                    wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id, &send_req_var, get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len)) > 0)
                {
                    wps_stream_data_send_req_hdlr(ilm_ptr->src_mod_id, 
                        (wps_stream_data_send_req_struct*) ilm_ptr->local_para_ptr, &send_req_var);
                }
                else
                {
                    wps_stream_data_send_req_hdlr(ilm_ptr->src_mod_id, 
                        (wps_stream_data_send_req_struct*) ilm_ptr->local_para_ptr, NULL);
                }
            }
            break;
        case MSG_ID_WPS_STREAM_DATA_READ_REQ:
            wps_stream_data_read_req_hdlr(ilm_ptr->src_mod_id, (wps_stream_data_read_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_HTTP_REQ:
        {
            wps_http_req_var_struct http_req_var;

            memset(&http_req_var, 0, sizeof(wps_http_req_var_struct));
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &http_req_var,
                    get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_http_req_hdlr(ilm_ptr->src_mod_id, (wps_http_req_struct*) ilm_ptr->local_para_ptr, &http_req_var);
            }
            else
            {
                wps_http_req_hdlr(ilm_ptr->src_mod_id, (wps_http_req_struct*) ilm_ptr->local_para_ptr, NULL);
            }
        }
            break;
        case MSG_ID_WPS_READ_CONTENT_REQ:
            wps_read_content_req_hdlr(ilm_ptr->src_mod_id, (wps_read_content_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_POST_CONTENT_RES:
        {
            wps_post_content_res_var_struct post_content_res_var;

            memset(&post_content_res_var, 0, sizeof(wps_post_content_res_var_struct));
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &post_content_res_var,
                    get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_post_content_res_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_post_content_res_struct*) ilm_ptr->local_para_ptr,
                    &post_content_res_var);
            }
            else
            {
                wps_post_content_res_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_post_content_res_struct*) ilm_ptr->local_para_ptr,
                    NULL);
            }
        }
            break;
        case MSG_ID_WPS_CANCEL_REQ:
            wps_cancel_req_hdlr(ilm_ptr->src_mod_id, (wps_cancel_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_CLEAR_REQ:
        {
            wps_clear_req_var_struct clear_req_var;

            memset(&clear_req_var, 0, sizeof(wps_clear_req_var_struct));
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &clear_req_var,
                    get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_clear_req_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_clear_req_struct*) ilm_ptr->local_para_ptr,
                    &clear_req_var);
            }
            else
            {
                wps_clear_req_hdlr(ilm_ptr->src_mod_id, (wps_clear_req_struct*) ilm_ptr->local_para_ptr, NULL);
            }
        }
            break;
        case MSG_ID_WPS_DL_PROGRESS_RES:
            wps_dl_progress_res_hdlr(ilm_ptr->src_mod_id, (wps_dl_progress_res_struct*) ilm_ptr->local_para_ptr);
            break;
    #ifdef WAP_SEC_SUPPORT
        case MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ:
            wps_sec_get_session_info_req_hdlr(
                ilm_ptr->src_mod_id,
                (wps_sec_get_session_info_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ:
            wps_sec_get_current_cert_req_hdlr(
                ilm_ptr->src_mod_id,
                (wps_sec_get_current_cert_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ:
            wps_sec_verify_cert_chain_req_hdlr(
                ilm_ptr->src_mod_id,
                (wps_sec_verify_cert_chain_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_GET_CERT_IDS_REQ:
            wps_sec_get_cert_ids_req_hdlr(ilm_ptr->src_mod_id, 
                (wps_sec_get_cert_ids_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_GET_CERT_REQ:
            wps_sec_get_cert_req_hdlr(ilm_ptr->src_mod_id, 
                (wps_sec_get_cert_req_struct*) ilm_ptr->local_para_ptr);
            break;
    #endif /* WAP_SEC_SUPPORT */ 
        case MSG_ID_WPS_HTTP_AUTH_RES:
            wps_http_auth_res_hdlr(ilm_ptr->src_mod_id, (wps_http_auth_res_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_STATUS_QUERY_REQ:
            wps_status_query_req_hdlr(ilm_ptr->src_mod_id);
            break;
    }
#ifdef WPS_TASK_SUPPORT
    free_ilm(ilm_ptr);
    MSF_wps_fsm();
#endif /* WPS_TASK_SUPPORT */ 
}

/*************************************************************
 * Test Code
 *************************************************************/
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
#ifdef WAP_SEC_SUPPORT	  
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
#endif /* 0 */ 

#endif /* WPS_SUPPORT */ 


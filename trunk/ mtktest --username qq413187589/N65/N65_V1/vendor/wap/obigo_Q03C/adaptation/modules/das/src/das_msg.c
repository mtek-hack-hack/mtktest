/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   das_msg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines primitive related functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "msf_def.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_core.h"

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "fat_fs.h"
#include "wap_ps_struct.h"

#include "das_main.h"
#include "das_msg.h"

#include "wapadp.h"
#include "wap_ps_struct.h"
#include "widget_extension.h"
#include "dlagentdef.h"
#include "connectmanagegprot.h"

/*****************************************************************************
 * FUNCTION
 *  das_send_dl_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_src         [IN]
 *  data_type       [IN]
 *  url             [?]
 *  mime_type       [?]
 *  file_name       [?]
 * RETURNS
 *
 *****************************************************************************/
int das_send_dl_ind(MSF_UINT8 mod_src, MSF_UINT8 data_type, const char *url, const char *mime_type, const kal_uint8 *file_name, const char *header, MSF_INT32 network_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    mmi_da_dispatch_file_var_struct *peer_pdu = NULL;
    mmi_da_dispatch_file_req_struct *p;
    kal_uint16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_RESET);
    p->mime_type = 0;
    p->mime_subtype = 0;

    memset(p->url, 0, sizeof(p->url));

    if (data_type == MsfResourceBuffer)
    {
#ifndef __MMI_DUAL_SIM__
        p->action = MMI_DA_PUSH;
#else
		if(always_ask_get_sim_info_data_account((kal_uint32)network_account_id) == ALWAYS_ASK_SIM_INFO_SIM2)
		{
			p->action = MMI_DA_PUSH_SIM2;
		}
		else
		{
			p->action = MMI_DA_PUSH_SIM1;
		}
#endif
    }
    else if (mod_src == MSF_MODID_SMA || mod_src == MSF_MODID_MEA)
    {
        p->action = MMI_DA_SAVE_AS;
        strcpy((char *)p->url, "mms://");
    }
    else if (data_type == MsfResourceFile)
    {
        p->action = MMI_DA_SAVE_AS;
    }
    else
    {
        p->action = MMI_DA_WAP_DOWNLOAD;

        if (strlen(url) > 0)
        {
            strncpy((char *)p->url, url, strlen(url) > sizeof(p->url) ? sizeof(p->url) : strlen(url));
        }
        else
        {
            strcpy((char *)p->url, "http://");
        }
    }

    memset(p->filepath, 0, sizeof(p->filepath));
    widget_ucs2_strcpy((kal_uint8*) p->filepath, (const kal_uint8*)file_name);

    strcpy((char *)p->mime_type_string, (const char*)mime_type);

    peer_buff_ptr = construct_peer_buff(sizeof(mmi_da_dispatch_file_var_struct) + strlen(header), 0, 0, TD_RESET);
    
    peer_pdu = (mmi_da_dispatch_file_var_struct *)get_pdu_ptr(peer_buff_ptr, &length);
    peer_pdu->header_len = strlen(header);
    memcpy(peer_pdu->header, header, peer_pdu->header_len);

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_DA_DISPATCH_FILE_REQ;  /* Set the message id */
    ilm_ptr->peer_buff_ptr = peer_buff_ptr;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return 1;
}

void das_send_file_dl_ind(das_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    kal_uint16 length;
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_ind_struct *p;
    peer_buff_struct *peer_buff_ptr = NULL;
    wap_mmi_file_dl_var_struct var = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wap_mmi_file_dl_ind_struct*) construct_local_para(sizeof(wap_mmi_file_dl_ind_struct), TD_RESET);
    p->session_id = job->id;

    memset(p->url, 0, WAP_DL_MAX_URL_LEN);
    if(job->url)
    {
        len = strlen(job->url);
        strncpy((char *)p->url, job->url, len > WAP_DL_MAX_URL_LEN ? WAP_DL_MAX_URL_LEN : len);
    }

    memset(p->mime_type, 0, WAP_DL_MAX_MIME_TYPE_LEN);
    if(job->mime_type)
    {
        len = strlen(job->mime_type);
        strncpy((char *)p->mime_type, job->mime_type, len > WAP_DL_MAX_MIME_TYPE_LEN ? WAP_DL_MAX_MIME_TYPE_LEN : len);
    }
    
    memset(p->file_name, 0, WAP_DL_MAX_FILE_NAME_LEN);
    widget_utf8_to_ucs2_string(p->file_name, WAP_DL_MAX_FILE_NAME_LEN, (const kal_uint8 *)job->file_name);

    p->file_length = job->total_size;


    if (job->header)
    {
        var.header_len = strlen(job->header);
        var.header = (kal_uint8*) job->header;
    }
    else
    {
        var.header_len = 0;
    }

    if (job->buffer_tail > 0)
    {
        var.content_len = job->buffer_tail;
        var.content = (kal_uint8*) job->buffer;
    }
    else
    {
        var.content_len = 0;
    }

    len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WAP_MMI_FILE_DL_IND, (void*)&var, NULL);
    if (len > 0)
    {
        peer_buff_ptr = construct_peer_buff(len, 0, 0, TD_RESET);
        if (wps_pun_var_part
            (WPS_PUN_PACK, MSG_ID_WAP_MMI_FILE_DL_IND, (void*)&var, get_pdu_ptr(peer_buff_ptr, &length)) != len)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_IND;  /* Set the message id */
    ilm_ptr->peer_buff_ptr = peer_buff_ptr;
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

}

void das_send_file_dl_progress_ind(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_progress_ind_struct *p;
    das_job_t *job;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(session_id);

    p = (wap_mmi_file_dl_progress_ind_struct*) construct_local_para(sizeof(wap_mmi_file_dl_progress_ind_struct), TD_RESET);
    p->session_id = session_id;

    if(!job)
    {
        p->seq_num = 0;
        p->acc_size = 0;
    }
    else
    {
        if(job->status == DAS_STATUS_DOWNLOADING)
        {
            p->status = WAP_DL_STATUS_DOWNLOADING;
            p->cause = WAP_DL_ERROR_OK;
        }
        else if(job->status == DAS_STATUS_COMPLETE)
        {
            p->status = WAP_DL_STATUS_COMPLETE;
            p->cause = WAP_DL_ERROR_OK;
        }
        else
        {
            p->status = WAP_DL_STATUS_ABORTED;
            p->cause = job->cause;
        }
        p->seq_num = ++job->seq_num;
        p->acc_size = job->download_size;
        job->indication_sent = TRUE;
	    job->status = DAS_STATUS_WAITING;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND;  /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}

static void das_send_dl_stop_rsp(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_stop_rsp_struct *p;
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wap_mmi_file_dl_stop_rsp_struct*) construct_local_para(sizeof(wap_mmi_file_dl_stop_rsp_struct), TD_RESET);

    p->session_id = session_id;
    p->status = WAP_DL_STATUS_CANCELLED;

    job = das_find_job_by_session_id(session_id);

    if(!job)
    {
        p->seq_num = 0;
        p->cause = WAP_DL_ERROR_INVALID_SESSION_ID;
        p->acc_size = 0;
    }
    else
    {
        p->seq_num = ++job->seq_num;
        p->cause = WAP_DL_ERROR_CANCELLED;
        p->acc_size = job->download_size;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_STOP_RSP;  /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}

static int das_file_dl_res_hdlr(wap_mmi_file_dl_res_struct *res)
{
    das_job_t *job;
    int file_handle;

    job = das_find_job_by_session_id(res->session_id);

    if(!job)
    {
        das_send_file_dl_progress_ind(res->session_id); /* Invalid Session Id */
        return 0;
    }

    if(res->result != WAP_DL_ERROR_OK)
    {
        job->cause = DAS_ERR_USER_CANCELLED;
        job->status = DAS_STATUS_ABORTED;
    }
    else
    {
        ASSERT(job->status != DAS_STATUS_WAITING);
        
        FS_Delete((WCHAR *)res->file_path);

        file_handle = FS_Open((WCHAR *)res->file_path, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

        if (file_handle <= 0)
        {
            job->cause = file_handle;
            job->status = DAS_STATUS_ABORTED;
        }
        else
        {
            job->file_handle = file_handle;
            job->status = DAS_STATUS_DOWNLOADING;
        }
    }
    return 1;
}

static int das_file_dl_progress_res_hdlr(wap_mmi_file_dl_progress_res_struct *res)
{
    das_job_t *job;

    job = das_find_job_by_session_id(res->session_id);

    if(!job)
        return -1;

    job->indication_sent = 0;
	job->status = DAS_STATUS_DOWNLOADING;
	return 1;
}

static int das_file_dl_stop_req_hdlr(wap_mmi_file_dl_stop_req_struct *res)
{
    das_job_t *job;

    job = das_find_job_by_session_id(res->session_id);

    if(!job)
    {
        das_send_dl_stop_rsp(res->session_id);
        return 0;
    }

    job->status = DAS_STATUS_ABORTED;
	job->cause = DAS_ERR_USER_CANCELLED;
    FS_Close(job->file_handle);
    das_send_dl_stop_rsp(res->session_id);
    return 1;
}

int das_handle_message(ilm_struct *ilm_ptr)
{
    int ret = 0;
    switch (ilm_ptr->msg_id)
    {
    case MSG_ID_WAP_MMI_FILE_DL_RES:        
        ret = das_file_dl_res_hdlr((wap_mmi_file_dl_res_struct *)ilm_ptr->local_para_ptr);
        break;
    case MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES:
        ret = das_file_dl_progress_res_hdlr((wap_mmi_file_dl_progress_res_struct *)ilm_ptr->local_para_ptr);
        break;
    case MSG_ID_WAP_MMI_FILE_DL_STOP_REQ:
        ret = das_file_dl_stop_req_hdlr((wap_mmi_file_dl_stop_req_struct *)ilm_ptr->local_para_ptr);
        break;
    default:
        return -1;
    }
    if(ret)
        das_wantsToRun = 1;
    return 0;
}

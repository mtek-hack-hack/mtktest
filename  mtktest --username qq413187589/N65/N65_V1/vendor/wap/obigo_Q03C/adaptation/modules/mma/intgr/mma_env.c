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
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stack_types.h"
#include "task_config.h"
#include "wap_ps_struct.h"

/* FS service */
#include "fs_type.h"
#include "fs_func.h"

/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_file.h"
#include "msf_errc.h"

/* MSM */
#include "msm_env.h"

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "msig.h"
#include "fldmgr.h"
#include "mltypes.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"
#include "sma_if.h"

/* MMA */
#include "mmsadp.h"
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_intsig.h"
#include "mma_main.h"
#include "mma_send.h"
#include "mma_if.h"
#include "mma_if_wrapper.h"
#include "mma_rpl.h"
#include "mma_utils.h"
#include "mma_conf.h"

/* Misc */
#include "widget_extension.h"
#include "wapadp.h"

#ifdef __UNIFIED_COMPOSER_SUPPORT__
/******************************************************************************
 * Local variables/functions
 ******************************************************************************/
const char *MMA_VERSION = "MmsAdaptor1.0";

static int mma_inside_run = 0;
static jmp_buf mma_jmpbuf;

void MMAc_kill(void);
/******************************************************************************
 * Extern variables/functions
 ******************************************************************************/
extern int msm_get_module_status(MSF_UINT8 modId);
extern MSF_BOOL smaIsRunning(void);

/******************************************************************************
 * ILM handling
 ******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_mms_start_uc_req
 * DESCRIPTION
 *  this function will be called to start unified composer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id)
{
    wap_mma_uc_start_req_struct *req = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    req = (wap_mma_uc_start_req_struct *)
        construct_local_para((kal_uint16) sizeof(wap_mma_uc_start_req_struct), TD_CTRL);
    req->app_id = 0; /*MMA_APP_ID_MMS_APP;*/
    req->mode = mode;
    req->msg_id = msg_id;
    
    ilm_ptr->msg_id			= MSG_ID_WAP_MMA_UC_START_REQ;
    ilm_ptr->local_para_ptr	= (local_para_struct *)req;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_get_setting_rsp
 * DESCRIPTION
 *  this function will be called to return setting value.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  creation
 *  prio
 *  validity
 *  delivery
 *  dr
 *  rr
 *  max_mms_size
 *  *resizing
 *  *signature
 *  *sliding_time
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_get_setting_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint8 creation, 
    kal_uint8 prio, kal_uint8 validity, kal_uint8 delivery, kal_bool dr, kal_bool rr,
    kal_uint32 max_mms_size, mma_image_resizing_struct *resizing, mma_signature_struct *signature, 
    mma_setting_struct *sliding_time)
{
    wap_mma_get_setting_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_GET_SETTING_RSP;
    rsp = (wap_mma_get_setting_rsp_struct *)
        construct_local_para((kal_uint16) sizeof(wap_mma_get_setting_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->creation_mode = creation;
    rsp->priority = prio;
    rsp->validity_period = validity;
    rsp->delivery_time = delivery;
    rsp->delivery_report = dr;
    rsp->read_report = rr;
    rsp->max_mms_size = max_mms_size;
    memset(&rsp->image_resize, 0x0, sizeof(mma_image_resizing_struct));
    memset(&rsp->signature, 0x0, sizeof(mma_signature_struct));
    memset(&rsp->sliding_time, 0x0, sizeof(mma_setting_struct));

    if (resizing)
    {
        memcpy(&rsp->image_resize, resizing, sizeof(mma_image_resizing_struct));
    }

    if (signature)
    {
        memcpy(&rsp->signature, signature, sizeof(mma_signature_struct));
    }

    if (sliding_time)
    {
        memcpy(&rsp->sliding_time, sliding_time, sizeof(mma_setting_struct));
    }

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}
/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_get_mem_status_rsp
 * DESCRIPTION
 *  this function will be called to return memory status.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  creation
 *  prio
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_get_mem_status_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 used_size, 
    kal_uint32 free_size)
{
    wap_mma_get_mem_status_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP;
    rsp = (wap_mma_get_mem_status_rsp_struct *)
        construct_local_para((kal_uint16) sizeof(wap_mma_get_mem_status_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->used_size = used_size;
    rsp->free_size = free_size;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_get_content_rsp
 * DESCRIPTION
 *  this function will be called to return setting value.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *  header_size
 *  body_size
 *  xml_size
 *  xml_filepath
 *  buffer_index
 *  buffer_size
 *  more
 *  buff
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_get_content_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id, 
    kal_uint32 header_size, kal_uint32 body_size, kal_uint32 xml_size, kal_wchar *xml_filepath, 
    kal_uint32 buffer_index, kal_uint32 buffer_size, kal_bool more, char *buff)
{
    wap_mma_get_content_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
    peer_buff_struct *peer_buff_ptr = NULL;
    MSF_UINT8 *peer_pdu = NULL;
    MSF_UINT16 peer_pdu_len = 0;

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_GET_CONTENT_RSP;
    rsp = (wap_mma_get_content_rsp_struct *)
        construct_local_para((kal_uint16) sizeof(wap_mma_get_content_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;
    rsp->mms_header_size = header_size;
    rsp->mms_body_size = body_size;
    rsp->xml_size = xml_size;
    if(xml_filepath != NULL)
    {
        widget_ucs2_strncpy((kal_uint8*) &rsp->xml_filepath, (kal_uint8*) xml_filepath, 100 * sizeof(kal_wchar));
    }
    rsp->buffer_index = buffer_index;
    rsp->buffer_size = buffer_size;
    rsp->more = more;

    if(buffer_size > 0 && buff != NULL)
    {
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(buffer_size, 0, 0, TD_CTRL);
        peer_pdu = (MSF_UINT8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        if (peer_pdu)
        {
            memcpy((kal_uint8*) peer_pdu, (kal_uint8*) buff, buffer_size);
        }
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
    }
    else
    {
        ilm_ptr->peer_buff_ptr = NULL;
    }

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_create_rsp
 * DESCRIPTION
 *  this function will be called to request creation info in ilm buffer.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *  buffer_index
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_create_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id, 
    kal_uint32 buffer_index)
{
    wap_mma_create_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_CREATE_RSP;
    rsp = (wap_mma_create_rsp_struct *)
        construct_local_para((kal_uint16) sizeof(wap_mma_create_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;
    rsp->buffer_index = buffer_index;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_preview_rsp
 * DESCRIPTION
 *  this function will be called to return preview response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_preview_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id)
{
    wap_mma_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_PREVIEW_RSP;
    rsp = (wap_mma_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_save_rsp
 * DESCRIPTION
 *  this function will be called to return save response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_save_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id)
{
    wap_mma_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_SAVE_RSP;
    rsp = (wap_mma_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_send_ind
 * DESCRIPTION
 *  this function will be called to send indication of sending progress.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *  response_text
 *  box
 *  send_and_save
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_send_ind(kal_uint8 app_id, kal_uint32 req_id, kal_uint32 msg_id, kal_uint8 retry, kal_uint8 percent)
{
    wap_mma_send_ind_struct *ind = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_SEND_IND;
    ind = (wap_mma_send_ind_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_send_ind_struct), TD_CTRL);
    ind->app_id = app_id;
    ind->req_id = req_id;
    ind->msg_id = msg_id;
    ind->retry = retry;
    ind->percent = percent;

    ilm_ptr->local_para_ptr = (local_para_struct *)ind;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_send_rsp
 * DESCRIPTION
 *  this function will be called to return send response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *  rr_id
 *  response_text
 *  box
 *  send_and_save
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_send_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id, 
    kal_uint32 rr_id, kal_wchar *response_text, kal_uint16 box, kal_bool send_and_save)
{
    wap_mma_send_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_SEND_RSP;
    rsp = (wap_mma_send_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_send_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;
    rsp->rr_id = rr_id;
    if(response_text != NULL)
    {
        widget_ucs2_strncpy((kal_uint8 *)rsp->response_text, (kal_uint8 *)response_text, 256 * sizeof(kal_wchar));
    }
    else
    {
        rsp->response_text[0] = 0;
    }
    rsp->box = box;
    rsp->send_and_save = send_and_save;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_cancel_send_rsp
 * DESCRIPTION
 *  this function will be called to return send cancellation response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_cancel_send_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id)
{
    wap_mma_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_CANCEL_SEND_RSP;
    rsp = (wap_mma_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}
/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_download_ind
 * DESCRIPTION
 *  this function will be called to send indication of sending progress.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *  response_text
 *  box
 *  send_and_save
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_download_ind(kal_uint8 app_id, kal_uint32 req_id, kal_uint32 notif_id, kal_uint8 retry, 
    kal_uint8 percent, kal_uint32 bytes)
{
    wap_mma_download_ind_struct *ind = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_DOWNLOAD_IND;
    ind = (wap_mma_download_ind_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_download_ind_struct), TD_CTRL);
    ind->app_id = app_id;
    ind->req_id = req_id;
    ind->msg_id = notif_id;
    ind->retry = retry;
    ind->percent = percent;
    ind->bytes_received = bytes;

    ilm_ptr->local_para_ptr = (local_para_struct *)ind;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_download_rsp
 * DESCRIPTION
 *  this function will be called to return download response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_download_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id)
{
    wap_mma_download_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_DOWNLOAD_RSP;
    rsp = (wap_mma_download_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_download_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_cancel_download_rsp
 * DESCRIPTION
 *  this function will be called to return download cancellation response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_cancel_download_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 notif_id)
{
    wap_mma_cancel_download_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP;
    rsp = (wap_mma_cancel_download_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_cancel_download_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = notif_id;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_msg_is_valid_rsp
 * DESCRIPTION
 *  this function will be called to return validity check response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  list
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_msg_is_valid_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint8 *existence, 
    kal_uint16 *box)
{
    wap_mma_msg_is_valid_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_MSG_IS_VALID_RSP;
    rsp = (wap_mma_msg_is_valid_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_msg_is_valid_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    memset(rsp->msg_validity_list, 0x00, MMA_MAX_MSG_ARRAY_NUM);
    memset(rsp->box, 0x00, MMA_MAX_MSG_ARRAY_NUM * sizeof(kal_uint16));
    if (existence != NULL)
    {
        memcpy(rsp->msg_validity_list, existence, MMA_MAX_MSG_ARRAY_NUM);
    }
    if (box != NULL)
    {
        memcpy(rsp->box, box, MMA_MAX_MSG_ARRAY_NUM * sizeof(kal_uint16));
    }

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  wap_send_wap_mma_delete_rsp
 * DESCRIPTION
 *  this function will be called to return deletion response.
 * PARAMETERS
 *  app_id
 *  req_id
 *  result
 *  msg_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_wap_mma_delete_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id)
{
    wap_mma_rsp_struct *rsp = NULL;
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = MSG_ID_WAP_MMA_DELETE_RSP;
    rsp = (wap_mma_rsp_struct *) construct_local_para((kal_uint16) sizeof(wap_mma_rsp_struct), TD_CTRL);
    rsp->app_id = app_id;
    rsp->req_id = req_id;
    rsp->result = result;
    rsp->msg_id = msg_id;

    ilm_ptr->local_para_ptr = (local_para_struct *)rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_uc_msg_hdlr
* DESCRIPTION
*  This function is used to handle signal passed from UC to WAP
*
* CALLS
*
* PARAMETERS
* ilm_ptr
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_mma_msg_hdlr(ilm_struct *ilm_ptr)
{
    switch(ilm_ptr->msg_id)
    {
        case MSG_ID_WAP_MMA_UC_START_RSP:
        {
            wap_mma_uc_start_rsp_struct *local_data = (wap_mma_uc_start_rsp_struct *)ilm_ptr->local_para_ptr;
            msf_dcvt_t cvt;
            void *sig, *sigData;
            MSF_UINT16 length;
            MSF_UINT8 destModId = smaIsRunning() ? MSF_MODID_SMA : MSF_MODID_MEA;
        
            msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
            msf_dcvt_uint8(&cvt, (MSF_UINT8 *)&local_data->result);
            msf_dcvt_uint8(&cvt, (MSF_UINT8 *)&local_data->mode);
            length = (MSF_UINT16)cvt.pos;
            sig = MSF_SIGNAL_CREATE (MMA_SIG_START_UC_RSP, MSF_MODID_MMA, destModId, length);
            sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
            msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, MSF_MODID_MMA);
            msf_dcvt_uint8(&cvt, (MSF_UINT8 *)&local_data->result);
            msf_dcvt_uint8(&cvt, (MSF_UINT8 *)&local_data->mode);
            MSF_SIGNAL_SEND (sig);
            break;
        }

        case MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ:
        {
            wap_mma_get_mem_status_req_struct *req = (wap_mma_get_mem_status_req_struct *)ilm_ptr->local_para_ptr;
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_get_mem_status_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, 0, 0);
            }
            else
            {
                kal_uint32 free_size = 0;
                kal_int32 used_size = 0;
                kal_uint8 *path = NULL;
#ifdef __USB_IN_NORMAL_MODE__
                if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
                {
                    wap_send_wap_mma_get_mem_status_rsp(req->app_id, req->req_id, 
                        MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE, 0, 0);
                    break;
                }
#endif  
                free_size = msm_get_disk_free_space(WAP_STORAGE_MMS);
                path = HDI_FileNameTranslate(MMS_FOLDER);
                used_size = FS_GetFolderSize((const WCHAR*)path, FS_COUNT_IN_BYTE, NULL, 0);
                used_size = (used_size < 0) ? 0 : used_size;
                HDI_FileNameFree(path);

                wap_send_wap_mma_get_mem_status_rsp(req->app_id, req->req_id, MMA_RESULT_OK, (kal_uint32)used_size, 
                    free_size);
            }
            break;
        }

        case MSG_ID_WAP_MMA_GET_SETTING_REQ:
        {
            wap_mma_get_setting_req_struct *local_data = (wap_mma_get_setting_req_struct *)ilm_ptr->local_para_ptr;
            if(msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MEA) != MODULE_STATUS_ACTIVE ||
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_get_setting_rsp(local_data->app_id, local_data->req_id, MMA_RESULT_FAIL_NOT_READY, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);
            }
            else
            {
                kal_uint8 creation, prio, validity, delivery;
                kal_bool dr, rr;
                kal_uint32 max_mms_size;
                mma_image_resizing_struct resizing;
                mma_signature_struct signature;
                mma_setting_struct sliding_time;

                creation = (kal_uint8)mma_conf_get_creation_mode();
                prio = (kal_uint8)mma_conf_get_priority();
                validity = (kal_uint8)mma_conf_get_expiry_time();
                delivery = (kal_uint8)mma_conf_get_delivery_time();
                dr = mma_conf_get_delivery_report();
                rr = mma_conf_get_read_report();
                max_mms_size = mma_conf_get_max_mms_size();
                mma_conf_get_image_resizing(&resizing);
                mma_conf_get_signature(&signature);
                mma_conf_get_sliding_time(&sliding_time);

                wap_send_wap_mma_get_setting_rsp(local_data->app_id, local_data->req_id, MMA_RESULT_OK, creation, prio, validity, delivery, dr, rr, 
                    max_mms_size, &resizing, &signature, &sliding_time);
            }
            break;
        }
        
        case MSG_ID_WAP_MMA_GET_CONTENT_REQ:
        {
            wap_mma_get_content_req_struct *req = (wap_mma_get_content_req_struct *)ilm_ptr->local_para_ptr;

            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_get_content_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id, 0, 0,
                    0, NULL, req->buffer_index, 0, FALSE, NULL);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_get_content_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                memset(&info, 0x0, sizeof(mma_get_content_info_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id = req->msg_id;
                info.buffer_index = req->buffer_index;
                info.mode = req->mode;
                info.creation_mode = req->creation_mode;
                info.header = NULL;
                info.body = NULL;
                info.state = PARSE_STATE_STARTED;
                info.sub_state = 0;
                entry.entry_info = &info;
                mma_get_mms_content(&entry);
            }
            break;
        }

        case MSG_ID_WAP_MMA_CREATE_REQ:
        {
            wap_mma_create_req_struct *req = (wap_mma_create_req_struct *)ilm_ptr->local_para_ptr;
            
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_create_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, 0, req->buffer_index);
                break;
            }
            else
            {
                mma_request_entry_struct entry;
                mma_create_mms_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                memset(&info, 0x0, sizeof(mma_create_mms_info_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.o_msg_id = req->msg_id;
                info.mode = req->mode;
                info.xml_size = req->xml_size;
                info.xml_filepath = req->xml_filepath;
                info.buffer_index = req->buffer_index;
                info.more = req->more;
                info.msg_id = 0;
                info.header = NULL;
                info.body = NULL;
                //info.m_handle
                //info.t_handle
                info.state = CREATE_STATE_STARTED;
                info.sub_state = 0;
                entry.entry_info = &info;
                mma_create_mms(&entry);
            }
            break;
        }

        case MSG_ID_WAP_MMA_PREVIEW_REQ:
        {
            wap_mma_preview_req_struct *req = (wap_mma_preview_req_struct *)ilm_ptr->local_para_ptr;
            
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_preview_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_preview_mms_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                memset(&info, 0x0, sizeof(mma_preview_mms_info_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id = req->msg_id;
                info.state = PREVIEW_STATE_STARTED;
                entry.entry_info = &info;
                mma_preview_mms(&entry);
            }
            break;
        }

        case MSG_ID_WAP_MMA_SAVE_REQ:
        {
            wap_mma_save_req_struct *req = (wap_mma_save_req_struct *)ilm_ptr->local_para_ptr;
            
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_save_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_move_mms_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                memset(&info, 0x0, sizeof(mma_move_mms_info_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id = req->msg_id;
                info.folder = req->box;
                entry.entry_info = &info;
                mma_move_mms(&entry);
            }
            break;
        }

        case MSG_ID_WAP_MMA_SEND_REQ:
        {
            wap_mma_send_req_struct *req = (wap_mma_send_req_struct *)ilm_ptr->local_para_ptr;
            
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_send_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id, 0, NULL, 
                    req->box, req->send_and_save);
            }
            else
            {
                mma_send_request_entry_struct entry;
                memset(&entry, 0x0, sizeof(mma_send_request_entry_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.mms_sender = MSF_MODID_MMA;
                entry.app_id = req->app_id;
                entry.req_id = req->req_id;
                entry.msg_id = req->msg_id;
                entry.send_and_save = req->send_and_save;
                entry.is_read_report = req->is_read_report;
                entry.folder = req->box;
                entry.state = MMA_SEND_START;
                mma_send_mms(&entry);
            }
            break;
        }

        case MSG_ID_WAP_MMA_CANCEL_SEND_REQ:
        {
            wap_mma_cancel_send_req_struct *req = (wap_mma_cancel_send_req_struct *)ilm_ptr->local_para_ptr;
            
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_cancel_send_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_cancel_send_mms_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id = req->msg_id;
                entry.entry_info = &info;
                mma_cancel_send_mms(&entry);
            }
            break;
        }
        case MSG_ID_WAP_MMA_DOWNLOAD_REQ:
        {
            wap_mma_download_req_struct *req = (wap_mma_download_req_struct *)ilm_ptr->local_para_ptr;
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_download_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_download_mms_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                memset(&info, 0x0, sizeof(mma_download_mms_info_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.notif_id = req->msg_id;
                entry.entry_info = &info;
                mma_download_mms(&entry);
            }
            break;
        }
        case MSG_ID_WAP_MMA_DOWNLOAD_RES:
        {
            wap_mma_download_res_struct *req = (wap_mma_download_res_struct *)ilm_ptr->local_para_ptr;
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
            }
            else
            {
                mma_request_entry_struct *entry = NULL;
                if((entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_DOWNLOAD_REQ)) != NULL)  /* Only one DOWNLOAD_REQ at a time */
                {
                    mma_download_mms_info_struct *info = (mma_download_mms_info_struct *)entry->entry_info;
                    wap_send_wap_mma_download_ind(info->app_id, req->req_id, info->notif_id, 0, info->percent, 
                        info->bytes_received);
                }
            }
            break;
        }

        case MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ:
        {
            wap_mma_cancel_download_req_struct *req = (wap_mma_cancel_download_req_struct *)ilm_ptr->local_para_ptr;
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_cancel_download_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_cancel_download_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id = req->msg_id;
                entry.entry_info = &info;
                mma_cancel_download_mms(&entry);
            }
            break;
        }
        
        case MSG_ID_WAP_MMA_MSG_IS_VALID_REQ:
        {
            wap_mma_msg_is_valid_req_struct *req = (wap_mma_msg_is_valid_req_struct *)ilm_ptr->local_para_ptr;
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_msg_is_valid_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, NULL, NULL);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_check_mms_info_struct info;
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id_list = req->msg_id_list;
                entry.entry_info = &info;
                mma_check_mms(&entry);
            }
            break;
        }

        case MSG_ID_WAP_MMA_DELETE_REQ:
        {
            wap_mma_delete_req_struct *req = (wap_mma_delete_req_struct *)ilm_ptr->local_para_ptr;
            
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE || 
                msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                wap_send_wap_mma_delete_rsp(req->app_id, req->req_id, MMA_RESULT_FAIL_NOT_READY, req->msg_id);
            }
            else
            {
                mma_request_entry_struct entry;
                mma_delete_mms_info_struct info;
                
                memset(&entry, 0x0, sizeof(mma_request_entry_struct));
                memset(&info, 0x0, sizeof(mma_delete_mms_info_struct));
                entry.ilm_sender = ilm_ptr->src_mod_id;
                entry.ilm_msg_id = ilm_ptr->msg_id;
                entry.req_id = req->req_id;
                info.app_id = req->app_id;
                info.msg_id = req->msg_id;
                info.box = req->box;
                info.list = NULL;
                info.curr = 0;
                info.state = DELETE_STATE_STARTED;
                entry.entry_info = &info;
                mma_delete_mms(&entry);
            }
            break;
        }

        case MSG_ID_WAP_BROWSER_SHUTDOWN_REQ:
        {
            if(msm_get_module_status (MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
            {
                break;
            }
            else
            {
                /* Abort foreground operation */
                if (mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_PREVIEW_REQ) != NULL)
                {
                    if (msm_get_module_status (MSF_MODID_SMA) == MODULE_STATUS_ACTIVE ||
                        msm_get_module_status (MSF_MODID_SMA) == MODULE_STATUS_CREATED ||
                        msm_get_module_status (MSF_MODID_SMA) == MODULE_STATUS_STANDBY)
                    {
                        MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SMA);
                    }
                    else if (msm_get_module_status (MSF_MODID_SLS) == MODULE_STATUS_ACTIVE ||
                             msm_get_module_status (MSF_MODID_SLS) == MODULE_STATUS_CREATED ||
                             msm_get_module_status (MSF_MODID_SLS) == MODULE_STATUS_STANDBY)
                    {
                        MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
                    }
                }
            }
        }
        
        default:
			break;
    }
}

/******************************************************************************
 * Function
 ******************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mma_exception_handler
 * DESCRIPTION
 *  this function will be called when exception event happen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_inside_run)
    {
        longjmp(mma_jmpbuf, 1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_cvt_mma_start_uc_rsp
 * DESCRIPTION
 *  Converts a parameters into a signal buffer for mma_uc_start_rsp_struct
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static int mma_cvt_mma_start_uc_rsp(msf_dcvt_t *obj, mma_uc_start_rsp_struct *data)
{
    MSF_UINT8 result = 0, mode = 0;

    if (NULL == data)
    {
        return FALSE;
    }
    result = (MSF_UINT8)data->result; 
    mode = (MSF_UINT8)data->mode;

    if (!msf_dcvt_uint8(obj, &result) || !msf_dcvt_uint8(obj, &mode))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
            MMA_ENV_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    }

    data->result = result;
    data->mode = mode;
    return TRUE; 
}

/*****************************************************************************
 * FUNCTION
 *  mma_convert
 * DESCRIPTION
 *  this function will be called module mmc receive message and want translate to internal message.
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *mma_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t  cvt_obj;
    void       *user_data;
    MSF_UINT16  length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( buffer == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
        MMA_ENV_B30ED9605412B3BFAC03B6BBDCECFEB5, "%s(%d) mma_convert: Invalid parameter", __FILE__, __LINE__));
        return NULL;
    }
        
    user_data = MSF_SIGNAL_GET_USER_DATA (buffer, &length);
    if ((user_data == NULL) || (length == 0))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
        MMA_ENV_DF68A2316CCCE57104790C19326659E0, "%s(%d) mma_convert: No data received", __FILE__, __LINE__));
        return NULL;
    }
        
    msf_dcvt_init (&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);
    
    switch (signal)
    {
    case MMA_SIG_START_UC_RSP:
    {
        mma_uc_start_rsp_struct *data = MSF_MEM_ALLOCTYPE (module, mma_uc_start_rsp_struct);
		if (data == NULL)
        {
            /* error allocating memoryt */
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
            MMA_ENV_48260F3B8175755B927DB3C437A1031B, "%s(%d) mma_convert: Unable to allocate memory.", __FILE__, __LINE__));
        }
        else 
        {   
            memset(data, 0x00, sizeof(mma_uc_start_rsp_struct));
        
            if (!mma_cvt_mma_start_uc_rsp(&cvt_obj, data))
            {
                /* error converting data */
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                MMA_ENV_6D760ADCA728656A6695D5E2D6A3D1EB, "%s(%d) mma_convert: Unable convert data.", __FILE__, __LINE__));
                MSF_MEM_FREE( module, data);
                data = NULL;
            }
        }
        return data;
    }
    default:
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
            MMA_ENV_73D190F3BD68EFBDAFFAD6B29FBED01A, "%s(%d) mma_convert: Received unknown signal.", __FILE__, __LINE__));
        return NULL;
    }
    } /* switch */

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_destruct
 * DESCRIPTION
 *  destory the mma module
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t cvt_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
        MMA_ENV_6F602A0BD185958FE7F6F5E588186435, "%s(%d) mma_destruct: no signal data \n", __FILE__, __LINE__));
        return;
    }
    
    msf_dcvt_init (&cvt_obj, MSF_DCVT_FREE, NULL, 0, module);
    switch (signal)
    {
    case MMA_SIG_START_UC_RSP:
        {
            if (!mma_cvt_mma_start_uc_rsp( &cvt_obj, p))
            {
                /* error converting data */
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                MMA_ENV_E42144F68F42A221BD49FCD96C7232A8, "%s(%d) mma_destruct: Unable convert.", __FILE__, __LINE__));
            }
            break;
        }
    default:
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                MMA_ENV_08A42F002533C976AEFC1BCE2F116F3F, "%s(%d) mma_destruct: Received unknown signal.", __FILE__, __LINE__));
            return;
        }
    } /* switch */
  MSF_MEM_FREE (module, p);}

/*****************************************************************************
 * FUNCTION
 *  mmaMsfSignalHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmaMsfSignalHandler(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case MSF_SIG_MODULE_EXECUTE_COMMAND:
            MMSif_applicationReg(MSF_MODID_MMA);
            break;
        case MSF_SIG_MODULE_TERMINATE:
            mma_signal_terminate();
            MMAc_kill();
            p = NULL;   /* been released in MMAc_kill() */
            break;
        case MSF_SIG_TIMER_EXPIRED:
        {
            msf_timer_expired_t *timer = (msf_timer_expired_t *)p;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_ENV_5C06C8C621352338017A184D651399CC, "MMA: received signal MSF_SIG_TIMER_EXPIRED\n"));
            if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
            {
                /* MMA is not currently active, skip this signal */
                break;
            }

            if (timer->timerID == MMA_SEND_TIMER_ID)
            {
                mma_send_request_entry_struct *next = NULL;
                mma_send_update_countdown();
                if((next = mma_send_get_pending_entry()) != NULL)
                {
                    mma_send_mms(next);
                }

                if(mma_send_get_countdown_entry_no() > 0)  /* Restart the timer */
                {
                    mma_send_start_resend_timer();
                }
            }
            break;
        }
        
        case MSF_SIG_MODULE_STATUS:  /* handle SLS/SMA status */
        {
            msf_module_status_t *st = (msf_module_status_t*)p;
            mma_request_entry_struct *entry = NULL;

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_ENV_7C36403D6B5304459A6BCF561266B091, "MMA: received signal MSF_SIG_MODULE_STATUS (%d, %d)\n", 
                st->modId, st->status));
            
            /* handle the received module status */
            if(st->modId == MSF_MODID_SLS)
            {
                if ((entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_GET_CONTENT_REQ)) != NULL)
                {
                    if(st->status == MODULE_STATUS_ACTIVE)
                    {
                        (void)SLSif_startInterface();
                    } 
                    else if(st->status == MODULE_STATUS_TERMINATED)
                    {
                        mma_get_content_info_struct *info = (mma_get_content_info_struct *)entry->entry_info;
                        ASSERT(info->state == PARSE_STATE_ABORTED || info->state == PARSE_STATE_SLS_DEACTIVATED);
                    }
                    mma_get_mms_content(entry);
                }
            }
            else if(st->modId == MSF_MODID_SMA)
            {
                if ((entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_PREVIEW_REQ)) != NULL)
                {
                    if(st->status == MODULE_STATUS_ACTIVE)
                    {
                        (void)SMAif_startInterface();
                    } 
                    else if(st->status == MODULE_STATUS_TERMINATED)
                    {
                        mma_preview_mms_info_struct *info = (mma_preview_mms_info_struct *)entry->entry_info;
                        info->state = PREVIEW_STATE_SMA_DEACTIVATED;
                        //ASSERT(info->state == PREVIEW_STATE_SMA_DEACTIVATED);
                    }
                    mma_preview_mms(entry);
                }
            }
            break;
        }
    }
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MMA, signal, p);
}

/*****************************************************************************
 * FUNCTION
 *  mmaMmsSignalHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  p           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmaMmsSignalHandler(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case MMS_SIG_CREATE_MSG_REPLY:
        {
            MmsMsgReplySig *sig = (MmsMsgReplySig *)p;
            mma_wrapper_entry_struct *active_entry = mma_wrapper_get_active_entry(MMA_WRAPPER_CREATE);

            ASSERT(active_entry != NULL);
            mma_reply_create_message_response(active_entry->sender, sig->result, sig->msgId);
            mma_wrapper_schedule(MMA_WRAPPER_CREATE);
            break;
        }

        case MMS_SIG_MOV_MSG_REPLY:
        {
            MmsResultSig *sig = (MmsResultSig *)p;
            mma_wrapper_entry_struct *active_entry = mma_wrapper_get_active_entry(MMA_WRAPPER_MOVE);

            ASSERT(active_entry != NULL);
            mma_reply_move_message_response(active_entry->sender, sig->result);
            mma_wrapper_schedule(MMA_WRAPPER_MOVE);
            break;
        }
        
        case MMS_SIG_MSG_DONE_REPLY:
        {
            MmsMsgDoneReplySig *sig = (MmsMsgDoneReplySig *)p;
            mma_wrapper_entry_struct *active_entry = mma_wrapper_get_active_entry(MMA_WRAPPER_CREATE_DONE);

            ASSERT(active_entry != NULL);
            mma_reply_create_message_done_response(active_entry->sender, sig->result, sig->msgId);
            mma_wrapper_schedule(MMA_WRAPPER_CREATE_DONE);
            break;
        }
        
        case MMS_SIG_GET_FLDR_REPLY:
        {
            mma_wrapper_entry_struct *active_entry = mma_wrapper_get_active_entry(MMA_WRAPPER_GET_FOLDER);

            ASSERT(active_entry != NULL);
            mma_reply_folder_content(active_entry->sender, (MmsListOfProperties *)p);
            mma_wrapper_schedule(MMA_WRAPPER_GET_FOLDER);
            break;
        }
        
        case MMS_SIG_SEND_MSG_REPLY:
        {
            MmsResultSig *sig = (MmsResultSig *)p;
            mma_send_request_entry_struct *send_entry = mma_send_get_sending_entry();
            mma_request_entry_struct *c_entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CANCEL_SEND_REQ);

            ASSERT(send_entry != NULL);
            if(sig->result == MMS_RESULT_CANCELLED_BY_USER)
            {
                if(c_entry != NULL && *(kal_uint32 *)c_entry->entry_info == send_entry->msg_id)
                {
                    mma_reply_cancel_send_message_response(MSF_MODID_MMA, MMS_RESULT_OK, sig->responseStatus, 
                        sig->responseText, send_entry->msg_id);
                }
                mma_reply_send_message_response(send_entry->mms_sender, MMS_RESULT_CANCELLED_BY_USER, 0, NULL, 
                    send_entry->msg_id);
            }
#if MMA_CFG_SENDING_RETRY_TIME
            else if(sig->result != MMS_RESULT_OK && send_entry->retry < MMA_CFG_SENDING_RETRY_TIME)
            {
                    send_entry->state = MMA_SEND_PENDING;
                    send_entry->retry++;
  #if MMA_CFG_SENDING_RETRY_INTERVAL_INCREASE
                    send_entry->retry_countdown = MMA_CFG_SENDING_RETRY_INTERVAL * send_entry->retry;
  #else
                    send_entry->retry_countdown = MMA_CFG_SENDING_RETRY_INTERVAL;
  #endif
                    mma_send_start_resend_timer();
            }
#endif
            else  /* succeed or fail */
            {
                if (c_entry != NULL && *(kal_uint32 *)c_entry->entry_info == send_entry->msg_id)
                {
                    mma_reply_cancel_send_message_response(MSF_MODID_MMA, MMA_RESULT_FAIL, sig->responseStatus, 
                        sig->responseText, send_entry->msg_id);
                }

                mma_reply_send_message_response(send_entry->mms_sender, sig->result, sig->responseStatus, 
                    sig->responseText, send_entry->msg_id);
            }

            if((send_entry = mma_send_get_pending_entry()) != NULL)  /* next request */
            {
                mma_send_mms(send_entry);
            }
            mma_wrapper_schedule(MMA_WRAPPER_SEND);
            break;
        }
        
        case MMS_SIG_PROGRESS_STATUS_REPLY:
        {
            MmsProgressStatus *sig = (MmsProgressStatus *)p;
            switch (sig->operation)
            {
            case MMS_PROGRESS_STATUS_SEND:
            {
                mma_send_request_entry_struct *send_entry = mma_send_get_sending_entry();
                if (send_entry != NULL && sig->msgId == send_entry->msg_id)  /* posting M-Send.conf or... */
                {
                    mma_reply_progress_status(send_entry->mms_sender, sig->operation, sig->state, sig->msgId, 
                        sig->progress, sig->totalLength, sig->queueLength);
                }
                else  /* posting M-NotifyResp.ind or...*/
                {
                }
                break;
            }
            
            case MMS_PROGRESS_STATUS_IMMRETRIEVE:
            {
                mma_reply_progress_status(MSF_MODID_MEA, sig->operation, sig->state, sig->msgId, 
                    sig->progress, sig->totalLength, sig->queueLength);
                break;
            }
            
            case MMS_PROGRESS_STATUS_RETRIEVE:
            {
#ifdef __MMI_MMS_BGSR_SUPPORT__
                mma_reply_progress_status(MSF_MODID_MMA, sig->operation, sig->state, sig->msgId, 
                    sig->progress, sig->totalLength, sig->queueLength);
#else
                mma_reply_progress_status(MSF_MODID_MEA, sig->operation, sig->state, sig->msgId, 
                    sig->progress, sig->totalLength, sig->queueLength);
#endif
                break;
            }

            default:
                ASSERT(0);
                break;
            }
            break;
        }

#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMS_SIG_RETRIEVE_MSG_REPLY:  /* Only for BGSR */
        {
            MmsMsgReplySig *sig = (MmsMsgReplySig *)p;
            mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_DOWNLOAD_REQ);
            mma_request_entry_struct *c_entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ);
            mma_download_mms_info_struct *dl_info = entry->entry_info;

            ASSERT(entry != NULL && dl_info != NULL);
            if (sig->result == MMS_RESULT_CANCELLED_BY_USER)
            {
                if((c_entry != NULL) && (*(kal_uint32 *)c_entry->entry_info == dl_info->notif_id))
                {
                    mma_reply_retrieve_cancel_response(MSF_MODID_MMA, MMS_RESULT_OK, dl_info->notif_id);
                }
                mma_reply_retrieve_message_response(MSF_MODID_MMA, MMS_RESULT_CANCELLED_BY_USER, 0);
                
            }
            else
            {
                if((c_entry != NULL) && (*(kal_uint32 *)c_entry->entry_info == dl_info->notif_id))
                {
                    mma_reply_retrieve_cancel_response(MSF_MODID_MMA, MMS_RESULT_ERROR, dl_info->notif_id);
                }
                mma_reply_retrieve_message_response(MSF_MODID_MMA, sig->result, sig->msgId);
            }
            break;
        }
        
        case MMS_SIG_SEND_RR_REPLY:  /* Only for BGSR */
        {
            MmsRRReplySig *sig = (MmsRRReplySig *)p;
            mma_send_request_entry_struct *send_entry = mma_send_get_sending_entry();

            ASSERT(send_entry != NULL && send_entry->msg_id == sig->msgId);
            mma_reply_send_rr_response(send_entry->mms_sender, sig->result, send_entry->msg_id, sig->rrId);
            if((send_entry = mma_send_get_pending_entry()) != NULL)  /* next request */
            {
                mma_send_mms(send_entry);
            }
            mma_wrapper_schedule(MMA_WRAPPER_SEND);
            break;
        }
#else
        case MMS_SIG_RETRIEVE_MSG_REPLY:
        case MMS_SIG_SEND_RR_REPLY:
#endif        
        case MMS_SIG_NOTIFICATION:
        case MMS_SIG_ERROR:
        case MMS_SIG_DELETE_MSG_REPLY:
        case MMS_SIG_READ_REPORT_IND:
        case MMS_SIG_DELIVERY_REPORT:
        case MMS_SIG_GET_MSG_INFO_REPLY:
            mma_reply_default_response(signal, p);
            break;
    }
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MMA, signal, p);
 }

/*****************************************************************************
 * FUNCTION
 *  mmaSlsSignalHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  p           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmaSlsSignalHandler(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case SLS_OPEN_SMIL_RSP:
        {
            SlsOpenSmilRsp *rsp = (SlsOpenSmilRsp *)p;
            mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_GET_CONTENT_REQ);
            mma_get_content_info_struct *info = (mma_get_content_info_struct *)entry->entry_info;
#if SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES
            if((rsp->result == SLS_RESULT_OK || rsp->result == SLS_RESULT_TO_MANY_SLIDES) && rsp->noOfSlides > 0)
#else
            if ((rsp->result == SLS_RESULT_OK && rsp->noOfSlides > 0) ||
                (rsp->result == SLS_RESULT_TO_MANY_SLIDES && info->mode != MMA_MODE_EDIT))
#endif 
            {
                mma_copy_sls_root_layout(&rsp->rootLayout, &info->body->root_layout);
                info->body->slide_no = rsp->noOfSlides;
                mma_copy_attachment_info(info->body, rsp->unrefItems);
                mma_get_mms_content(entry);
            }
            else
            {
                (void)SLSif_closeSmil(MSF_MODID_MMA);
                info->state = PARSE_STATE_SLS_DEACTIVATING;
                info->header->multipart_type = MMA_MULTIPART_MIXED;
            }
            break;
        }

        case SLS_CLOSE_SMIL_RSP:
        {
            SlsCloseSmilRsp *rsp = (SlsCloseSmilRsp *)p;
            mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_GET_CONTENT_REQ);
            mma_get_content_info_struct *info = (mma_get_content_info_struct *) entry->entry_info;
            if (rsp->result != SLS_RESULT_OK)
            {
                mma_result_enum ret = MMA_RESULT_OK;
                
                MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
                ret = translate_sls_result_to_mma(rsp->result);
                wap_send_wap_mma_get_content_rsp(info->app_id, entry->req_id, ret, info->msg_id, 0, 0, 0, NULL, 
                    info->buffer_index, 0, FALSE, NULL);
                info->state = PARSE_STATE_ABORTED;
            }
            mma_get_mms_content(entry);
            break;
        }
        
        case SLS_GET_SLIDE_INFO_RSP:
        {
            SlsGetSlideInfoRsp *rsp = (SlsGetSlideInfoRsp *)p;
            mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_GET_CONTENT_REQ);
            mma_get_content_info_struct *info = (mma_get_content_info_struct *) entry->entry_info;

            if(rsp->result == SLS_RESULT_OK)
            {
                mma_copy_slide_info(info->body, &rsp->slideInfo);

            }
            else
            {
                mma_result_enum ret = MMA_RESULT_OK;
                
                MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
                ret = translate_sls_result_to_mma(rsp->result);
                wap_send_wap_mma_get_content_rsp(info->app_id, entry->req_id, ret, info->msg_id, 0, 0, 0, NULL, 
                    info->buffer_index, 0, FALSE, NULL);
                info->state = PARSE_STATE_ABORTED;
            }
            mma_get_mms_content(entry);
            break;
        }
    }
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MMA, signal, p);
}

/*****************************************************************************
 * FUNCTION
 *  mmaSmaSignalHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  p           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmaSmaSignalHandler(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case SMA_SIG_PLAY_SMIL_RSP:  /* finish SMIL playing */
        {
            mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_PREVIEW_REQ);
            mma_preview_mms_info_struct *info = NULL;
            SmaResult result = ((SmaPlaySmilRsp *)p)->result;

            ASSERT(entry != NULL);
            info = entry->entry_info;
            if(info->state < PREVIEW_STATE_SMIL_PLAYED)
            {
                wap_send_wap_mma_preview_rsp(info->app_id, entry->req_id, translate_sma_result_to_mma(result), 
                    info->msg_id);
            }
            info->state = PREVIEW_STATE_SMA_DEACTIVATING;
            mma_preview_mms(entry);
            break;
        }
        
        case SMA_SIG_PLAY_SMIL_IND:
        {
            mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_PREVIEW_REQ);
            mma_preview_mms_info_struct *info = NULL;
            ASSERT(entry != NULL);
            info = entry->entry_info;
            wap_send_wap_mma_preview_rsp(info->app_id, entry->req_id, MMA_RESULT_OK, info->msg_id);
            info->state = PREVIEW_STATE_SMIL_PLAYED;
            break;
        }
    }
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MMA, signal, p);
}

/*****************************************************************************
 * FUNCTION
 *  mmaSignalReceive
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module mma.
 * PARAMETERS
 *  srcModule       [IN]        
 *  signal          [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmaSignalReceive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srcModule)
    {
        case MSF_MODID_MSM:
            mmaMsfSignalHandler(signal, p);
            break;

        case MSF_MODID_MMS:
            mmaMmsSignalHandler(signal, p);
            break;

        case MSF_MODID_SLS:
            mmaSlsSignalHandler(signal, p);
             break;

        case MSF_MODID_SMA:
            mmaSmaSignalHandler(signal, p);
            break;
        default:
            break;
    }
}

/******************************************************************************
 * Obigo Callback Function
 ******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  MMAc_start
 * DESCRIPTION
 *  this function will be called when module mma is initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_inside_run = 0;
    memset(mma_jmpbuf, 0, sizeof(mma_jmpbuf));

    /* Initialize the memory allocator. Needed in most other functions. */
    MSF_MEM_INIT(MSF_MODID_MMA, mma_exception_handler);

    /* Initiate internal global data */
    mma_init();

    /* Register the signal queue */
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_MMA);

    /* Register conversion and destruction functions */
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_MMA, mma_convert, mma_destruct);

    /* Registrate the module into MSF */
    MSF_MODULE_IS_CREATED(MSF_MODID_MMA, (char*)MMA_VERSION);
    MSF_MODULE_IS_ACTIVE(MSF_MODID_MMA);
}

/*****************************************************************************
 * FUNCTION
 *  MMAc_kill
 * DESCRIPTION
 *  this function will be called MSF environment want terminate mmc module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_MMA);
    MSF_FILE_CLOSE_ALL(MSF_MODID_MMA);  /* Only if the module use files. */
    MSF_MEM_FREE_ALL(MSF_MODID_MMA);
    MSF_MODULE_IS_TERMINATED(MSF_MODID_MMA);
    MSF_KILL_TASK(MSF_MODID_MMA);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMS, MMA_ENV_F3697BBDD018C7B6D4ED76994BD92AAD, "%s(%d): MMA module is terminated.\n", __FILE__, __LINE__));
}

/*****************************************************************************
 * FUNCTION
 *  MMAc_wantsToRun
 * DESCRIPTION
 *  this function will be called when MSF environment want to known
 *  module mma have something to do or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int MMAc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if there are any signals in the external signal queue or
       in the internal signal queue. */

    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_MMA) > 0 || mma_signal_queue_is_empty() != KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  MMAc_run
 * DESCRIPTION
 *  this function will be called when module mmc want process something.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_inside_run = 1;

    if (setjmp(mma_jmpbuf) == 0)
    {
        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_MMA, mmaSignalReceive));  /* Get external signals */
        mma_signal_process();  /* process internal signal */
    }
    else
    {
        /*
         * A longjmp from xxx_exception_handler. If we are here there is no more
         * memory, and the situation could not be worse.
         * Send out an error and terminate as the figure above.
         */
        MSF_ERROR(MSF_MODID_MMA, MSF_ERR_MODULE_OUT_OF_MEMORY);

        MMAc_kill();
    }
    /* Clear the global variable, the module is now outside the Run function. */
    mma_inside_run = 0;
}
#endif

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
 *   cam_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of image module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_api.h"

#ifdef __MED_CAM_MOD__

static void cam_send_outgoing_ilm(module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr);
static void cam_send_incoming_ilm(module_type src_mod_id, module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr);

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

static void cam_send_outgoing_ilm(module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct* ilm = NULL;
    module_type src_mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    src_mod_id = stack_int_get_active_module_id();

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = MED_SAP;

    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;

    ilm->dest_mod_id = dest_mod_id;

    msg_send_ext_queue(ilm);
}


static void cam_send_incoming_ilm(module_type src_mod_id, module_type dest_mod_id, kal_uint16 msg_id, void* local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = dest_mod_id;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_xenon_flash_status_ind
 * DESCRIPTION
 *  This function is to send xenon flash status indication.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  status         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_xenon_flash_status_ind(kal_uint16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_xenon_flash_ind_struct,ind_p);

    ind_p->status = status;

    cam_send_outgoing_ilm(cam_context_p->src_mod,MSG_ID_MEDIA_CAM_XENON_FLASH_STATUS_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_power_up_req
 * DESCRIPTION
 *  This function is to send camera power up request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_power_up_req(module_type src_mod_id, kal_uint16 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_power_up_req_struct,msg_p);

    msg_p->seq_num = seq_num;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_POWER_UP_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_power_down_req
 * DESCRIPTION
 *  This function is to send camera power down request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_power_down_req(module_type src_mod_id, kal_int16 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_power_down_req_struct,msg_p);

    msg_p->delay_time = delay_time;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_POWER_DOWN_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_preview_req
 * DESCRIPTION
 *  This function is to send camera preview request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_preview_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type dest_mod_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_preview_req_struct,msg_p);

    kal_mem_cpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_cam_preview_req_struct) - sizeof(local_para_struct));

#if defined(ISP_SUPPORT)
    dest_mod_id = MOD_MED_C;
#else
    dest_mod_id = MOD_MED;
#endif

    cam_send_incoming_ilm(src_mod_id,dest_mod_id,MSG_ID_MEDIA_CAM_PREVIEW_REQ,(void*)msg_p);
}

#if defined (BARCODE_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  cam_send_barcode_preview_req
 * DESCRIPTION
 *  This function is to send camera preview request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_barcode_preview_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_preview_req_struct,msg_p);

    kal_mem_cpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_cam_preview_req_struct) - sizeof(local_para_struct));

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_BARCODE_PREVIEW_REQ,(void*)msg_p);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cam_send_stop_req
 * DESCRIPTION
 *  This function is to send camera stop request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_stop_req_struct,msg_p);
    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_STOP_REQ,(void*)msg_p);
}

#if defined (BARCODE_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  cam_send_barcode_stop_req
 * DESCRIPTION
 *  This function is to send camera stop request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_barcode_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_stop_req_struct,msg_p);
    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_BARCODE_STOP_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_barcode_stop_capture_req
 * DESCRIPTION
 *  This function is to send camera stop request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_barcode_stop_capture_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_stop_req_struct,msg_p);
    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_BARCODE_STOP_CAPTURE_REQ,(void*)msg_p);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cam_send_capture_req
 * DESCRIPTION
 *  This function is to send camera capture request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_capture_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_capture_req_struct,msg_p);

    kal_mem_cpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_cam_capture_req_struct) - sizeof(local_para_struct));

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_CAPTURE_REQ,(void*)msg_p);
}

#if defined (BARCODE_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  cam_send_barcode_capture_req
 * DESCRIPTION
 *  This function is to send camera capture request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_barcode_capture_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_barcode_capture_struct,msg_p);

    kal_mem_cpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_cam_barcode_capture_struct) - sizeof(local_para_struct));

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_BARCODE_CAPTURE_REQ,(void*)msg_p);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cam_send_set_param_req
 * DESCRIPTION
 *  This function is to send set parameter request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_set_param_req(module_type src_mod_id, kal_uint16 param_id, kal_int16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_set_param_req_struct,msg_p);

    msg_p->param_id = param_id;
    msg_p->value = value;
    
    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_SET_PARAM_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_set_flash_req
 * DESCRIPTION
 *  This function is to send set flash request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  flash_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_set_flash_req(module_type src_mod_id, kal_int16 flash_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_set_flash_req_struct,msg_p);

    msg_p->flash_mode = flash_mode;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_SET_FLASH_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_cal_mwb_req
 * DESCRIPTION
 *  This function is to send calculate manual WB req
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  pmwb            [?]         
 *  op_type         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_cal_mwb_req(module_type src_mod_id, void *pmwb, kal_uint8 op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cam_mwb_process_struct *mwb_p = (cam_mwb_process_struct*) pmwb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_mwb_operation_req_struct,msg_p);

    msg_p->pmwb = (media_cam_mwb_process_struct*) mwb_p;
    msg_p->op_type = op_type;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_CAL_MANUAL_WB_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_mwb_operation_req
 * DESCRIPTION
 *  This function is to send mwb operation req
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  op_type         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_mwb_operation_req(module_type src_mod_id, kal_uint8 op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_mwb_operation_req_struct,msg_p);

    msg_p->op_type = op_type;
    msg_p->pmwb = NULL;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_MWB_OPERATION_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_set_overlay_palette_req
 * DESCRIPTION
 *  This function is to send set overlay palette request message.
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  palette_size        [IN]        
 *  palette_addr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_set_overlay_palette_req(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_set_overlay_palette_req_struct,msg_p);

    msg_p->palette_size = palette_size;
    msg_p->palette_addr = palette_addr;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_SET_OVERLAY_PALETTE_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_ready_ind
 * DESCRIPTION
 *  This function is to send camera ready indication message.
 * PARAMETERS
 *  result      [IN]        
 *  module_type src_mod_id(?)
 *  kal_uint16 param_id(?)
 *  kal_int16 value(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_ready_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_ready_ind_struct,ind_p);

    ind_p->result = result;
    ind_p->seq_num = cam_context_p->seq_num;

    cam_send_outgoing_ilm(cam_context_p->src_mod,MSG_ID_MEDIA_CAM_READY_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_preview_fail_ind
 * DESCRIPTION
 *  This function is to send camera preview fail indication message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_preview_fail_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_preview_fail_ind_struct,ind_p);

    ind_p->result = result;

    cam_send_outgoing_ilm(cam_context_p->src_mod,MSG_ID_MEDIA_CAM_PREVIEW_FAIL_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_event_ind
 * DESCRIPTION
 *  This function is to send camera event indication message.
 * PARAMETERS
 *  event       [IN]        
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_event_ind(kal_uint8 event, kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_event_ind_struct,ind_p);

    ind_p->event = event;
    ind_p->cause = cause;

    cam_send_outgoing_ilm(MOD_MED,MSG_ID_MEDIA_CAM_EVENT_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_capture_event_ind
 * DESCRIPTION
 *  This function is to send camera capture event indication message.
 * PARAMETERS
 *  result      [IN]        
 *  count       [IN]        
 *  kal_uint8 event(?)
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_capture_event_ind(kal_int16 result, kal_uint16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_capture_event_ind_struct,ind_p);

    ind_p->result = result;
    ind_p->count = count;

    cam_send_outgoing_ilm(cam_context_p->src_mod,MSG_ID_MEDIA_CAM_CAPTURE_EVENT_IND,(void*)ind_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_autofocus_process_done_ind
 * DESCRIPTION
 *  This function is to send camera autofocus event indication message.
 * PARAMETERS
 *  event       [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_autofocus_process_done_ind(kal_uint8 event, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_event_ind_struct,ind_p);

    ind_p->event = event;
    ind_p->cause = result;

    cam_send_outgoing_ilm(cam_context_p->src_mod,MSG_ID_MEDIA_CAM_AF_PROCESS_DONE_IND,(void*)ind_p);
}

#if defined (BARCODE_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  cam_send_barcode_decode_done_ind
 * DESCRIPTION
 *  This function is to send camera autofocus event indication message.
 * PARAMETERS
 *  event       [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_barcode_decode_done_ind(media_cam_barcode_event_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_barcode_event_ind_struct ,ind_p);

    ind_p->event = ind->event;
    ind_p->cause = ind->cause;
    ind_p->encoding = ind->encoding;
    ind_p->nsymbol = ind->nsymbol;
    ind_p->symbolid = ind->symbolid;
    ind_p->paritydata = ind->paritydata;
    ind_p->barcode_type = ind->barcode_type;
    cam_send_outgoing_ilm(cam_context_p->src_mod,MSG_ID_MEDIA_CAM_BARCODE_DECODE_DONE_IND,(void*)ind_p);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cam_send_start_fast_zoom_req
 * DESCRIPTION
 *  This function is to send camera start fast zoom request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  zoom_in         [IN]        
 *  zoom_limit      [IN]        
 *  zoom_step       [IN]        
 *  zoom_speed      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_start_fast_zoom_req(
        module_type src_mod_id,
        kal_bool zoom_in,
        kal_uint8 zoom_limit,
        kal_uint8 zoom_step,
        kal_uint8 zoom_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_start_fast_zoom_req_struct,msg_p);

    msg_p->zoom_in = zoom_in;
    msg_p->zoom_limit = zoom_limit;
    msg_p->zoom_step = zoom_step;
    msg_p->zoom_speed = zoom_speed;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_START_FAST_ZOOM_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_stop_fast_zoom_req
 * DESCRIPTION
 *  This function is to send camera stop fast zoom request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_stop_fast_zoom_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_stop_fast_zoom_req_struct,msg_p);
    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_STOP_FAST_ZOOM_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_get_fast_zoom_factor_req
 * DESCRIPTION
 *  This function is to send camera get fast zoom factor request message.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  factor          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_get_fast_zoom_factor_req(module_type src_mod_id, kal_uint8 *factor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_get_fast_zoom_factor_req_struct,msg_p);

    msg_p->factor = factor;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_GET_FAST_ZOOM_FACTOR_REQ,(void*)msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  cam_send_get_focus_steps_req
 * DESCRIPTION
 *  This function is to send camera get focus steps request message.
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  total_steps         [?]         
 *  current_steps       [?]         
 *  flag                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void cam_send_get_focus_steps_req(
        module_type src_mod_id,
        kal_uint32 *total_steps,
        kal_uint32 *current_steps,
        kal_bool *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CONSTRUCT_LOCAL_PARAM(media_cam_get_focus_steps_req_struct,msg_p);

    msg_p->total_steps = total_steps;
    msg_p->current_steps = current_steps;
    msg_p->flag = flag;

    cam_send_incoming_ilm(src_mod_id,MOD_MED,MSG_ID_MEDIA_CAM_GET_FOCUS_STEPS_REQ,(void*)msg_p);
}

#endif /* __MED_CAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 


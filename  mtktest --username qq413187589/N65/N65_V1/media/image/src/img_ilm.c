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
 * img_ilm.c
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

#ifdef __MED_IMG_MOD__


/*****************************************************************************
 * FUNCTION
 *  img_send_decode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_decode_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_decode_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_img_decode_req_struct*) construct_local_para(sizeof(media_img_decode_req_struct), TD_CTRL);

    memcpy(
        ((kal_uint8*) msg_p) + sizeof(local_para_struct),
        ((kal_uint8*) data) + sizeof(local_para_struct),
        sizeof(media_img_decode_req_struct) - sizeof(local_para_struct));

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_DECODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_decode_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  seq_num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_decode_finish_ind(kal_int16 result, kal_uint16 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_decode_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_img_decode_finish_ind_struct*)
        construct_local_para(sizeof(media_img_decode_finish_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->seq_num = seq_num;
    ind_p->image_width = img_context_p->image_width;
    ind_p->image_height = img_context_p->image_height;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = img_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_DECODE_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_decode_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 *  arg0        [IN]        
 *  arg1        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_decode_event_ind(kal_uint8 cause, kal_uint32 arg0, kal_uint32 arg1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_decode_event_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_img_decode_event_ind_struct*)
        construct_local_para(sizeof(media_img_decode_event_ind_struct), TD_CTRL);

    ind_p->cause = cause;
    ind_p->arg0 = arg0;
    ind_p->arg1 = arg1;

    ilm_ptr = allocate_ilm(MOD_JPEG_HISR);
    ilm_ptr->src_mod_id = MOD_JPEG_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_DECODE_EVENT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_encode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_encode_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_encode_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;
    img_encode_struct *encode = (img_encode_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_img_encode_req_struct*) construct_local_para(sizeof(media_img_encode_req_struct), TD_CTRL);

    msg_p->image_width = encode->image_width;
    msg_p->image_height = encode->image_height;
    msg_p->image_quality = encode->image_quality;
    msg_p->image_buffer_p = encode->image_buffer_p;
    msg_p->image_buffer_size = encode->image_buffer_size;
    msg_p->target_width = encode->target_width;
    msg_p->target_height = encode->target_height;
    msg_p->media_mode = encode->media_mode;
    msg_p->media_type = encode->media_type;
    msg_p->data = encode->data;
    msg_p->file_buffer_len = encode->file_buffer_len;
    msg_p->file_size_p = encode->file_size_p;
    msg_p->seq_num = encode->seq_num;
    msg_p->blocking = encode->blocking;
    msg_p->gray_mode = encode->gray_mode;

#if MT6228_SERIES
    msg_p->jpeg_yuv_mode = encode->jpeg_yuv_mode;

    msg_p->thumbnail_mode = encode->thumbnail_mode;
    msg_p->thumbnail_width = encode->thumbnail_width;
    msg_p->thumbnail_height = encode->thumbnail_height;

    msg_p->overlay_frame_mode = encode->overlay_frame_mode;
    msg_p->overlay_color_depth = encode->overlay_color_depth;
    msg_p->overlay_frame_source_key = encode->overlay_frame_source_key;
    msg_p->overlay_frame_width = encode->overlay_frame_width;
    msg_p->overlay_frame_height = encode->overlay_frame_height;
    msg_p->overlay_frame_buffer_address = encode->overlay_frame_buffer_address;
#endif /* MT6228_SERIES */ 

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_ENCODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_encode_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  seq_num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_encode_finish_ind(kal_int16 result, kal_uint16 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_encode_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_img_encode_finish_ind_struct*)
        construct_local_para(sizeof(media_img_encode_finish_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->seq_num = seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = img_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_ENCODE_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_encode_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_encode_event_ind(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_encode_event_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_img_encode_event_ind_struct*)
        construct_local_para(sizeof(media_img_encode_event_ind_struct), TD_CTRL);

    ind_p->cause = cause;

    ilm_ptr = allocate_ilm(MOD_JPEG_HISR);
    ilm_ptr->src_mod_id = MOD_JPEG_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_ENCODE_EVENT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_resize_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_resize_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_resize_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;
    img_resize_struct *resize = (img_resize_struct*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_img_resize_req_struct*) construct_local_para(sizeof(media_img_resize_req_struct), TD_CTRL);

    msg_p->src_image_address = resize->src_image_address;
    msg_p->dest_image_address = resize->dest_image_address;
    msg_p->dest_buffer_size = resize->dest_buffer_size;
    msg_p->src_width = resize->src_width;
    msg_p->src_height = resize->src_height;
    msg_p->src_pitch = resize->src_pitch;
    msg_p->target_width = resize->target_width;
    msg_p->target_height = resize->target_height;
    msg_p->image_clip_x1 = resize->image_clip_x1;
    msg_p->image_clip_x2 = resize->image_clip_x2;
    msg_p->image_clip_y1 = resize->image_clip_y1;
    msg_p->image_clip_y2 = resize->image_clip_y2;
    msg_p->seq_num = resize->seq_num;
    msg_p->blocking = resize->blocking;
    msg_p->type = resize->type;
    msg_p->data_order = resize->data_order;
#if MT6228_SERIES
    msg_p->image_pitch_mode = resize->image_pitch_mode;
    msg_p->image_data_format = resize->image_data_format;
    msg_p->image_pitch_bytes = resize->image_pitch_bytes;
#endif /* MT6228_SERIES */ 

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_RESIZE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_resize_done_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  seq_num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_resize_done_ind(kal_int16 result, kal_uint16 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_resize_done_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_img_resize_done_ind_struct*)
        construct_local_para(sizeof(media_img_resize_done_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->seq_num = seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = img_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_RESIZE_DONE_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_stop_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_img_stop_req_struct*) construct_local_para(sizeof(media_img_stop_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_STOP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  img_send_exif_decode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void img_send_exif_decode_req(module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_img_exif_decode_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_img_exif_decode_req_struct*)
        construct_local_para(sizeof(media_img_exif_decode_req_struct), TD_CTRL);

    msg_p->exif_info = data;

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_IMG_EXIF_DECODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

#endif /* __MED_IMG_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 


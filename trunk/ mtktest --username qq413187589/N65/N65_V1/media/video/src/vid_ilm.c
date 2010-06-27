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
 * vid_ilm.c
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
#include "drv_comm.h"

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
#include "med_trc.h"
#include "med_utility.h"

#ifdef __SF_MP4_SUPPORT__ //tom@2008.2.28:  07b add
#include "med_main.h"
#endif
#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
#include "med_v_struct.h"


/*****************************************************************************
 * FUNCTION
 *  vid_send_record_finish_ind
 * DESCRIPTION
 *  This function is to send video record finished indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_record_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_record_finish_ind_struct*)
        construct_local_para(sizeof(media_vid_record_finish_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->seq_num = vid_context_p->seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_RECORD_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_file_merge_done_ind
 * DESCRIPTION
 *  This function is to send video record finished indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_file_merge_done_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_merge_done_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_file_merge_done_ind_struct*)
        construct_local_para(sizeof(media_vid_file_merge_done_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_edt_encode_merge_done_ind
 * DESCRIPTION
 *  This function is to send merge done requst for video editor
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_edt_encode_merge_done_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_merge_done_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_edt_enc_merge_done_ind_struct*)
        construct_local_para(sizeof(media_vid_edt_enc_merge_done_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->seq_num = vid_context_p->seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_EDT_ENC_MERGE_DONE_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



/*****************************************************************************
 * FUNCTION
 *  vid_send_file_ready_ind
 * DESCRIPTION
 *  This function is to send video file ready indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_file_ready_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_ready_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_file_ready_ind_struct*) construct_local_para(sizeof(media_vid_file_ready_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->image_width = vid_context_p->image_width;
    ind_p->image_height = vid_context_p->image_height;
    ind_p->total_frame_num = vid_context_p->total_frame_num;
    ind_p->total_time = vid_context_p->total_time;
    ind_p->seq_num = vid_context_p->seq_num;
    ind_p->handle = vid_context_p->handle;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_FILE_READY_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_play_finish_ind
 * DESCRIPTION
 *  This function is to send video play finish indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_play_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SEND_PLAY_FINISH_IND);
    
    ind_p = (media_vid_play_finish_ind_struct*)
        construct_local_para(sizeof(media_vid_play_finish_ind_struct), TD_CTRL);

    ind_p->result = result;
    ind_p->seq_num = vid_context_p->seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_PLAY_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_decode_event_ind
 * DESCRIPTION
 *  This function is to send video decode event indication to video module
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_decode_event_ind(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_decode_event_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_decode_event_ind_struct*)
        construct_local_para(sizeof(media_vid_decode_event_ind_struct), TD_CTRL);

    ind_p->event = event;

    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_DECODE_EVENT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}




/*****************************************************************************
 * FUNCTION
 *  vid_edt_send_encode_event_ind
 * DESCRIPTION
 *  This function is to send video transcode event indication to video module
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_send_encode_event_ind(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_encode_event_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_edt_encode_event_ind_struct*)
        construct_local_para(sizeof(media_vid_edt_encode_event_ind_struct), TD_CTRL);

    ind_p->event = event;

    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_EDT_ENCODE_EVENT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



/*****************************************************************************
 * FUNCTION
 *  vid_send_seek_done_ind
 * DESCRIPTION
 *  This function is to send seek done indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_seek_done_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_done_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_seek_done_ind_struct*) construct_local_para(sizeof(media_vid_seek_done_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ind_p->seq_num = vid_context_p->seq_num;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_SEEK_DONE_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_iframe_ready_ind
 * DESCRIPTION
 *  This function is to send i-frame ready indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_iframe_ready_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_iframe_ready_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_iframe_ready_ind_struct*)
        construct_local_para(sizeof(media_vid_iframe_ready_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_IFRAME_READY_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_set_overlay_palette_req
 * DESCRIPTION
 *  This function is to send set overlay palette request message.
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  palette_size        [IN]        
 *  palette_addr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_set_overlay_palette_req(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_overlay_palette_req_struct *msg_p;
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_cam_set_overlay_palette_req_struct*)
        construct_local_para(sizeof(media_cam_set_overlay_palette_req_struct), TD_CTRL);

    msg_p->palette_size = palette_size;
    msg_p->palette_addr = palette_addr;

    ilm_ptr = allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_SET_OVERLAY_PALETTE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

#endif /* defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 



#if defined(__MED_VID_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_send_audio_play_finish_ind
 * DESCRIPTION
 *  This function is to send audio play finish indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_audio_play_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_audio_play_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_audio_play_finish_ind_struct*)
        construct_local_para(sizeof(media_vid_audio_play_finish_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_AUDIO_PLAY_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

/* ============= Send message to Media-v ============== */


/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_record_req
 * DESCRIPTION
 *  This function is to send visual record request to media-v task
 * PARAMETERS
 *  data        [?]     
 *  media_visual_record_req_struct* msg_p(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_record_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_record_req_struct*) construct_local_para(sizeof(media_visual_record_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_RECORD_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_stop_req
 * DESCRIPTION
 *  This function is to send visual stop request to media-v task
 * PARAMETERS
 *  data        [?]     
 *  media_visual_stop_req_struct* msg_p(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_stop_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_stop_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_stop_req_struct*) construct_local_para(sizeof(media_visual_stop_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_STOP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_play_req
 * DESCRIPTION
 *  This function is to send visual play request to media-v task
 * PARAMETERS
 *  data        [?]     
 *  media_visual_play_req_struct* msg_p(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_play_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_play_req_struct*) construct_local_para(sizeof(media_visual_play_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_seek_req
 * DESCRIPTION
 *  This function is to send visual seek request to media-v task
 * PARAMETERS
 *  frame_num       [IN]        
 *  display         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_seek_req(kal_uint32 frame_num, kal_uint8 display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_seek_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_seek_req_struct*) construct_local_para(sizeof(media_visual_seek_req_struct), TD_CTRL);

    msg_p->frame_num = frame_num;
    msg_p->display = display;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_SEEK_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_file_merge_req
 * DESCRIPTION
 *  This function is to send visual file merge request to media-v task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_file_merge_req(kal_uint16 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_file_merge_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_file_merge_req_struct*)
        construct_local_para(sizeof(media_visual_file_merge_req_struct), TD_CTRL);

    msg_p->mode = mode;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_FILE_MERGE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}
#endif /* defined(__MED_VID_MOD__) */ 




#if defined(__MED_MJPG_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_play_req
 * DESCRIPTION
 *  This function is to send visual play request to media-v task
 * PARAMETERS
 *  data        [?]     
 *  media_visual_play_req_struct* msg_p(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_play_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_play_req_struct*) construct_local_para(sizeof(media_visual_play_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_stop_req
 * DESCRIPTION
 *  This function is to send visual stop request to media-v task
 * PARAMETERS
 *  data        [?]     
 *  media_visual_stop_req_struct* msg_p(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_stop_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_stop_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_stop_req_struct*) construct_local_para(sizeof(media_visual_stop_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_STOP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



#if defined(__MED_MJPG_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_send_visual_record_req
 * DESCRIPTION
 *  This function is to send visual record request to media-v task
 * PARAMETERS
 *  data        [?]     
 *  media_visual_record_req_struct* msg_p(?)
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_visual_record_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_req_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_record_req_struct*) construct_local_para(sizeof(media_visual_record_req_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_RECORD_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



/*****************************************************************************
 * FUNCTION
 *  vid_send_encode_visual_data_ind
 * DESCRIPTION
 *  This function is to send encode visual data indication message.
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_encode_visual_data_ind(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_encode_visual_data_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_encode_visual_data_ind_struct*)
        construct_local_para(sizeof(media_encode_visual_data_ind_struct), TD_CTRL);

    ind_p->event = event;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_ENCODE_VISUAL_DATA_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



/*****************************************************************************
 * FUNCTION
 *  vid_send_mjpeg_encode_ind
 * DESCRIPTION
 *  This function is to send encode visual data indication message.
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_send_mjpeg_encode_ind(kal_uint8 return_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mjpeg_encode_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;
    kal_uint32 cur_time;
    kal_uint32 duration;
    kal_uint32 fps;
    kal_bool is_fps_fixed = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* drop frame if needed */
    if (vid_context_p->rec_drop_frame)
    {
        if((vid_context_p->rec_drop_counter % vid_context_p->rec_drop_frame) != 0)
        {
            /* drop a frame */
            vid_context_p->rec_drop_counter++;                    
            return;
        }
        else
        {
            vid_context_p->rec_drop_counter = 1; 
        }
    }
        
    if (!vid_context_p->mjpeg_is_fps_fixed)
    {
        /* fps not fixed, need keep calculate */
        
        cur_time = drv_get_current_time();
        duration = drv_get_duration_ms(vid_context_p->mjpeg_prev_frame_time);
        fps = 1000 * 1000 / duration; /* 1000 * fps */

        if (vid_context_p->frame_rate == fps)
        {
            /* frame rate fixed */
            is_fps_fixed = KAL_TRUE;  
            vid_context_p->mjpeg_is_fps_fixed = KAL_TRUE;
        }   
            
        vid_context_p->frame_rate = fps;
        vid_context_p->mjpeg_prev_frame_time = cur_time;
    }

    if  (vid_context_p->mjpeg_is_jpg_encoding)
    {
        /* jpeg is still encoding, do not send this message */
        vid_context_p->mjpeg_insert_frame_count++;
        
        return;
    }
   
    ind_p = (media_mjpeg_encode_ind_struct*)
        construct_local_para(sizeof(media_mjpeg_encode_ind_struct), TD_CTRL);

    ind_p->is_update_fps = is_fps_fixed;
    
    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_MJPEG_ENCODE_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}
#endif /* defined(__MED_MJPG_ENC_MOD__) */
#endif /* defined(__MED_MJPG_MOD__) */ 

#ifdef __SF_MP4_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vid_sf_send_file_ready_ind
 * DESCRIPTION
 *  This function is to send video file ready indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_sf_send_file_ready_ind(media_vid_file_ready_ind_struct *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_ready_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    if (file_info == NULL)
    	return;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_file_ready_ind_struct*) construct_local_para(sizeof(media_vid_file_ready_ind_struct), TD_CTRL);
    kal_prompt_trace(MOD_MED, "In vid_sf_send_file_ready_ind, file_info->result:%d", file_info->result);
#if defined(__SF_MP4_SUPPORT__)
//Huyanwei Add it 
    if(file_info->result==MED_RES_MP4_NO_VIDEO_TRACK)  //tom@2008.1.23: bugfix from snowfish
        file_info->result=MED_RES_OK;
#endif

    ind_p->result = file_info->result;
    ind_p->image_width = file_info->image_width;
    ind_p->image_height = file_info->image_height;
    ind_p->total_frame_num = file_info->total_frame_num;
    ind_p->total_time = file_info->total_time;
    ind_p->seq_num = file_info->seq_num;
    ind_p->handle = file_info->handle;

    vid_context_p->image_height = file_info->image_height;
    vid_context_p->image_width = file_info->image_width;
    vid_context_p->total_time = file_info->total_time;
    vid_context_p->handle = file_info->handle;
    
    vid_set_image_size(file_info->image_width,file_info->image_height);
    vid_set_total_time(file_info->total_time);

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_FILE_READY_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  vid_sf_send_play_finish_ind
 * DESCRIPTION
 *  This function is to send video play finish indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_sf_send_play_finish_ind(media_vid_play_finish_ind_struct* finish_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    if (finish_info == NULL)
    	return;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SEND_PLAY_FINISH_IND);
    VID_ENTER_STATE(VID_FILE_READY);
    
    ind_p = (media_vid_play_finish_ind_struct*)
        construct_local_para(sizeof(media_vid_play_finish_ind_struct), TD_CTRL);

    ind_p->result = finish_info->result;
    ind_p->seq_num = finish_info->seq_num;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_PLAY_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

/*****************************************************************************
 * FUNCTION
 *  vid_sf_send_seek_done_ind
 * DESCRIPTION
 *  This function is to send seek done indication to the request module
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vid_sf_send_seek_done_ind(media_vid_seek_done_ind_struct* seek_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_done_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    if (seek_info == NULL)
    	return;

    kal_prompt_trace(MOD_MED, "In vid_sf_send_seek_done_ind, seek_info->result:%d, vid_context_p->total_time:%d", seek_info->result, vid_context_p->total_time);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_seek_done_ind_struct*) construct_local_para(sizeof(media_vid_seek_done_ind_struct), TD_CTRL);

    ind_p->result = seek_info->result;

    ilm_ptr = allocate_ilm(MOD_MED);
    ilm_ptr->src_mod_id = MOD_MED;
    ilm_ptr->dest_mod_id = vid_context_p->src_mod;
    ind_p->seq_num = seek_info->seq_num;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_SEEK_DONE_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

#endif //__SF_MP4_SUPPORT__

#endif /* MED_NOT_PRESENT */ 


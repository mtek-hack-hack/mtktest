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
 * vcall_ilm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of vcall
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Task Management */
#include "syscomp_config.h"
#include "task_config.h"

/* Timer Management  */
#include "stacklib.h"
#include "event_shed.h" /* event schedulet */
#include "stack_timer.h"

#include "app_buff_alloc.h"     /* buffer management API */
#include "lcd_cqueue.h" /* circular queue */
#include "app2soc_struct.h"     /* interface with Applications */

#include <setjmp.h>

#include "soc_api.h"
#include "fat_fs.h"
#include "rtc_sw.h"

#include "stack_utils.h"

#include "kal_trace.h"

#include <time.h>
#include "l1audio.h"
#include "med_main.h"
#include "med_global.h"
#include "med_struct.h"
#include "med_trc.h"

#ifdef __MED_VCALL_MOD__
#include "med_vt_struct.h"
#include "vcall.h"

static kal_int32 vcall_result;
static kal_int32 vcall_src_mod_id;

/*****************************************************************************
 * FUNCTION
 *  vcall_send_ilm
 * DESCRIPTION
 *  send ilm for vcall related functions
 * PARAMETERS
 *  dst_mod_id          [IN]        Dest module ID
 *  src_mod_id          [IN]        Source module ID
 *  msg_id              [IN]        Message ID
 *  sap_id              [IN]        SAP ID
 *  local_param_ptr     [IN]        Local parameter pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_msg(
    module_type src_mod_id, 
    module_type dst_mod_id, 
    kal_uint16 msg_id, 
    kal_uint16 sap_id, 
    void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(src_mod_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = dst_mod_id;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_video_codec_open_req
 * DESCRIPTION
 *  send a message to from MMI to MED to open video codec
 * PARAMETERS
 *  src_mod_id          [IN]        caller's module id
 *  recorder_view_type  [IN]
 *  recorder            [IN]
 *  player_view_type    [IN]
 *  player              [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
void vcall_send_video_codec_open_req(
    module_type src_mod_id,
    media_vcall_view_type_enum recorder_view_type,
    media_video_record_struct *recorder, 
    media_vcall_view_type_enum player_view_type,
    media_video_playback_struct *player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_codec_open_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_VIDEO_CODEC_OPEN_REQ);    
    
    msg_p = (media_vcall_video_codec_open_req_struct*) construct_local_para(
        sizeof(media_vcall_video_codec_open_req_struct), TD_CTRL);

    msg_p->recorder_view_type = recorder_view_type;
    msg_p->player_view_type = player_view_type;
    memcpy(&msg_p->recorder, recorder, sizeof(media_video_record_struct));
    memcpy(&msg_p->player, player, sizeof(media_video_playback_struct));

    vcall_src_mod_id = src_mod_id;
    
    vcall_send_msg(
        src_mod_id, 
        MOD_MED, 
        MSG_ID_MEDIA_VCALL_VIDEO_CODEC_OPEN_REQ,
        MED_SAP, 
        msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_video_codec_close_req
 * DESCRIPTION
 *  send a message from MMI to MED to close video codec
 * PARAMETERS
 *  src_mod_id              [IN]        source module id
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_video_codec_close_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_codec_close_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_VIDEO_CODEC_CLOSE_REQ);  
    
    msg_p = (media_vcall_video_codec_close_req_struct*)construct_local_para(
        sizeof(media_vcall_video_codec_close_req_struct), TD_CTRL);

    vcall_src_mod_id = src_mod_id;

    vcall_send_msg(
        src_mod_id, 
        MOD_MED, 
        MSG_ID_MEDIA_VCALL_VIDEO_CODEC_CLOSE_REQ,
        MED_SAP, 
        msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_channel_report_ind
 * DESCRIPTION
 *  send a message from MED to MMI to report channel status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_channel_report_ind(void)
{
    /* TODO :NOT USED ?? */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_channel_report_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_CHANNEL_REPORT_IND);     
    
    msg_p = (media_vcall_channel_report_ind_struct*) construct_local_para(
        sizeof(media_vcall_channel_report_ind_struct), TD_CTRL);

    vcall_send_msg(
        MOD_MED, 
        vcall_src_mod_id, 
        MSG_ID_MEDIA_VCALL_CHANNEL_REPORT_IND,
        MED_SAP, 
        msg_p);
}



/*****************************************************************************
 * FUNCTION
 *  vcall_send_channel_status_ind
 * DESCRIPTION
 *  send a message from VT to MED to notify channel status
 * PARAMETERS
 *  in_audio_chl    [IN]
 *  out_audio_chl   [IN]
 *  in_video_chl    [IN]
 *  out_video_chl   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_channel_status_ind(
    vt_struct_audio_capability *in_audio_chl,
    vt_struct_audio_capability *out_audio_chl,
    vt_struct_video_capability *in_video_chl,
    vt_struct_video_capability *out_video_chl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_channel_status_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_CHANNEL_STATUS_IND);    
    
    msg_p = (media_vcall_channel_status_ind_struct*) construct_local_para(
        sizeof(media_vcall_channel_status_ind_struct), TD_CTRL);
    
    memcpy(&msg_p->input_audio_chl, in_audio_chl, sizeof(vt_struct_audio_capability));
    memcpy(&msg_p->output_audio_chl, out_audio_chl, sizeof(vt_struct_audio_capability));
    memcpy(&msg_p->input_video_chl, in_video_chl, sizeof(vt_struct_video_capability));
    memcpy(&msg_p->output_video_chl, out_video_chl, sizeof(vt_struct_video_capability));

    vcall_send_msg(
        MOD_VT, 
        MOD_MED, 
        MSG_ID_MEDIA_VCALL_CHANNEL_STATUS_IND,
        MED_SAP, 
        msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_video_replenish_data_ready_ind
 * DESCRIPTION
 *  send a message from VT to MED to nofify video replenish data ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_video_replenish_data_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_replenish_data_ready_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_VIDEO_REPLENISH_DATA_READY_IND);       
    
    msg_p = (media_vcall_video_replenish_data_ready_ind_struct*) construct_local_para(
        sizeof(media_vcall_video_replenish_data_ready_ind_struct), TD_CTRL);

    vcall_send_msg(
        MOD_VT, 
        MOD_MED, 
        MSG_ID_MEDIA_VCALL_VIDEO_REPLENISH_DATA_READY_IND,
        MED_SAP, 
        msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_vt_pause_in_video_channel_req
 * DESCRIPTION
 *  send a message to vt task, notify it to resume in video channel
 *  encode data ready
 * PARAMETERS
 *  event_seq_no        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_vt_pause_in_video_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_send_msg(
        MOD_MED, 
        MOD_VT,
        MSG_ID_MED_VT_VIDEO_PAUSE,
        MED_SAP, 
        NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_vt_resume_in_video_channel_req
 * DESCRIPTION
 *  send a message to vt task, notify it to pause in video channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_vt_resume_in_video_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_send_msg(
        MOD_MED, 
        MOD_VT,
        MSG_ID_MED_VT_VIDEO_RESUME,
        MED_SAP, 
        NULL);      
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_video_encode_data_ready_ind
 * DESCRIPTION
 *  send a message from Video Encoder(VISUAL_HISR) to MED to nofify video 
 *  encode data ready
 * PARAMETERS
 *  event_seq_no        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_video_encode_data_ready_ind(kal_uint32 event_seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_encode_data_ready_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* NOTE!!: This function is callbacked under hisr */    
//  kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_VIDEO_ENCODE_DATA_READY_IND);      
    
    msg_p = (media_vcall_video_encode_data_ready_ind_struct*) construct_local_para(
        sizeof(media_vcall_video_encode_data_ready_ind_struct), TD_CTRL);
    
    msg_p->event_seq_no = event_seq_no;

    vcall_send_msg(
        MOD_VISUAL_HISR, 
        MOD_MED,
        MSG_ID_MEDIA_VCALL_VIDEO_ENCODE_DATA_READY_IND,
        MED_SAP, 
        msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  vcall_send_video_decode_data_ready_ind
 * DESCRIPTION
 *  send a message from Video Decoder(VISUAL_HISR) to MED to nofify video decode data ready
 * PARAMETERS
 *  event_seq_no        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_video_decode_data_ready_ind(kal_uint32 event_seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_decode_data_ready_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* NOTE!!: This function is callbacked under hisr */
//    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_VIDEO_DECODE_DATA_READY_IND); 
    
    msg_p = (media_vcall_video_decode_data_ready_ind_struct*) construct_local_para(
        sizeof(media_vcall_video_decode_data_ready_ind_struct), TD_CTRL);
    
    msg_p->event_seq_no = event_seq_no;

    vcall_send_msg(
        MOD_VISUAL_HISR, 
        MOD_MED, 
        MSG_ID_MEDIA_VCALL_VIDEO_DECODE_DATA_READY_IND,
        MED_SAP, 
        msg_p);
}



/*****************************************************************************
 * FUNCTION
 *  vcall_send_video_codec_report_ind
 * DESCRIPTION
 *  send codec event to MMI
 * PARAMETERS
 *  codec_event         [IN]        event
 *  para                [IN]        para
 * RETURNS
 *  void
 *****************************************************************************/
void vcall_send_video_codec_report_ind(media_vcall_codec_event_enum codec_event, kal_int32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_codec_report_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SEND_VIDEO_CODEC_REPORT_IND, codec_event, para);
    
    msg_p = (media_vcall_video_codec_report_ind_struct*) construct_local_para(
        sizeof(media_vcall_video_codec_report_ind_struct), TD_CTRL);
    
    msg_p->seq_no = vcall_ctx.seq_num;
    msg_p->codec_event = codec_event;
    msg_p->para = para;

    vcall_send_msg(
        MOD_MED,
        MOD_MMI,
        MSG_ID_MEDIA_VCALL_VIDEO_CODEC_REPORT_IND,
        MED_SAP, 
        msg_p);
    
}



/*****************************************************************************
 * FUNCTION
 *  media_vcall_open_video_codec
 * DESCRIPTION
 *  open video codec for a video call
 * PARAMETERS
 *  recorder_view_type  [IN]
 *  recorder            [IN]
 *  player_view_type    [IN]
 *  player              [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_vcall_open_video_codec(
    module_type src_mod_id,
    media_vcall_view_type_enum recorder_view_type,
    media_video_record_struct *recorder, 
    media_vcall_view_type_enum player_view_type,
    media_video_playback_struct *player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcall_result = MED_RES_OK;
    
    vcall_send_video_codec_open_req(
        src_mod_id, 
        recorder_view_type, 
        recorder, 
        player_view_type, 
        player);
    
    VCALL_WAIT_EVENT(VCALL_EVT_WAIT);

    return vcall_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vcall_close_video_codec
 * DESCRIPTION
 *  close video codec for a video call
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_vcall_close_video_codec(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    vcall_result = MED_RES_OK;
    
    vcall_send_video_codec_close_req(src_mod_id);
    
    VCALL_WAIT_EVENT(VCALL_EVT_WAIT);
    
    return vcall_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_vall_is_cam_able_to_update_para
 * DESCRIPTION
 *  is camera able to update parameters or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_bool media_vall_is_cam_able_to_update_para(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (vcall_ctx.local_view.type == VCALL_VIEW_SHOW_VIDEO)
    {
        /* local show video preview */
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  media_vcall_set_result
 * DESCRIPTION
 *  set result
 * PARAMETERS
 *  result          [IN]
 *  line            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void media_vcall_set_result(kal_int32 result, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_GROUP_4, VCALL_TRC_SET_RESULT, line);     
    
    med_debug_print_result(result);
    vcall_result = result;
}

#endif /* __MED_VCALL_MOD__ */


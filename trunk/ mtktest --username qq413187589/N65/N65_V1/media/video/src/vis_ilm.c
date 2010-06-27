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
 * vis_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of visual module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_V_NOT_PRESENT

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

/* local includes */
#include "med_global.h"
#include "med_struct.h"
#include "med_v_struct.h"
#include "med_v_context.h"
#include "med_trc.h"


#ifdef __MED_VID_MOD__
#include "rtc_sw.h"
#include "lcd_if.h"
#ifdef ISP_SUPPORT
#include "isp_if.h"
#endif 
#ifdef MP4_CODEC
#include "FSAL.h"
#include "MP4_Parser.h"
#include "MP4_Producer_Audio.h"
#include "MP4_Sample_Data_Audio.h"
#include "video_file_creator.h"
#include "drv_comm.h"
#include "visual_comm.h"
#include "l1audio.h"
#include "bmd.h"
#include "video_dec_glb.h"
#include "video_enc_glb.h"
#include "video_glb.h"
#endif /* MP4_CODEC */ 
#include "vid_main.h"
#include "med_utility.h"



/*****************************************************************************
 * FUNCTION
 *  vis_send_stop_cnf
 * DESCRIPTION
 *  This function is to send visual stop confirm message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_stop_cnf(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_stop_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_stop_cnf_struct*) construct_local_para(sizeof(media_visual_stop_cnf_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_STOP_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_play_cnf
 * DESCRIPTION
 *  This function is to send visual play confirm message.
 * PARAMETERS
 *  result          [IN]        
 *  frame_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_play_cnf(kal_int16 result, kal_uint32 frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_play_cnf_struct*) construct_local_para(sizeof(media_visual_play_cnf_struct), TD_CTRL);

    msg_p->audio_start_frame_num = frame_num;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_seek_cnf
 * DESCRIPTION
 *  This function is to send visual seek confirm message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_seek_cnf(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_seek_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_seek_cnf_struct*) construct_local_para(sizeof(media_visual_seek_cnf_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_SEEK_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}



/*****************************************************************************
 * FUNCTION
 *  vis_send_decode_visual_data_ind
 * DESCRIPTION
 *  This function is to send decode visual data indication message.
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_decode_visual_data_ind(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_decode_visual_data_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_decode_visual_data_ind_struct*)
        construct_local_para(sizeof(media_decode_visual_data_ind_struct), TD_CTRL);

    ind_p->event = event;

    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_DECODE_VISUAL_DATA_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}





/*****************************************************************************
 * FUNCTION
 *  vis_send_seek_done_ind
 * DESCRIPTION
 *  This function is to send visual seek done indication message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_seek_done_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* temp */
    media_visual_play_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_visual_play_finish_ind_struct*)
        construct_local_para(sizeof(media_visual_play_finish_ind_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_play_finish_ind
 * DESCRIPTION
 *  This function is to send visual play finish indication message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_play_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VIS_TRC_SEND_PLAY_FINISH_IND);
    med_debug_print_result(result, __LINE__);
    
    ind_p = (media_visual_play_finish_ind_struct*)
        construct_local_para(sizeof(media_visual_play_finish_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_error_recover_ind
 * DESCRIPTION
 *  This function is to send error recover indication message to Media task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_error_recover_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VID_ERROR_RECOVER_IND;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}



#if defined(__MED_VID_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vis_send_file_merge_cnf
 * DESCRIPTION
 *  This function is to send visual file merge confirm message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_file_merge_cnf(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_file_merge_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_file_merge_cnf_struct*)
        construct_local_para(sizeof(media_visual_file_merge_cnf_struct), TD_CTRL);

    msg_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_FILE_MERGE_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vis_send_record_cnf
 * DESCRIPTION
 *  This function is to send visual record confirm message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_record_cnf(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_record_cnf_struct*) construct_local_para(sizeof(media_visual_record_cnf_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_RECORD_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_record_finish_ind
 * DESCRIPTION
 *  This function is to send visual record finish indication message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_record_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_visual_record_finish_ind_struct*)
        construct_local_para(sizeof(media_visual_record_finish_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_RECORD_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_encode_visual_data_ind
 * DESCRIPTION
 *  This function is to send encode visual data indication message.
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_encode_visual_data_ind(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_encode_visual_data_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event == VIDEO_ENC_EVENT_COUNT_FILE_SIZE)
    {
        if (vid_evaluate_residual_size(video_enc_get_bitstream_file_size()) == 0)
        {
            video_enc_stop_record();
            event = VIDEO_ENC_EVENT_COMPLETE;
        }
        else
        {
            return;
        }
    }
    ind_p = (media_encode_visual_data_ind_struct*)
        construct_local_para(sizeof(media_encode_visual_data_ind_struct), TD_CTRL);

    ind_p->event = event;

    ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
    ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
    ilm_ptr->dest_mod_id = MOD_MED_V;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_ENCODE_VISUAL_DATA_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}
#endif /* defined(__MED_VID_ENC_MOD__) */

#endif /* __MED_VID_MOD__ */ 



#if defined(__MED_MJPG_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vis_send_play_cnf
 * DESCRIPTION
 *  This function is to send visual play confirm message.
 * PARAMETERS
 *  result          [IN]        
 *  frame_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_play_cnf(kal_int16 result, kal_uint32 frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_play_cnf_struct*) construct_local_para(sizeof(media_visual_play_cnf_struct), TD_CTRL);

    msg_p->audio_start_frame_num = frame_num;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

/*****************************************************************************
 * FUNCTION
 *  vis_send_play_finish_ind
 * DESCRIPTION
 *  This function is to send visual play finish indication message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_play_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VIS_TRC_SEND_PLAY_FINISH_IND);
    med_debug_print_result(result);
    
    ind_p = (media_visual_play_finish_ind_struct*)
        construct_local_para(sizeof(media_visual_play_finish_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_PLAY_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_record_cnf
 * DESCRIPTION
 *  This function is to send visual record confirm message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_record_cnf(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_record_cnf_struct*) construct_local_para(sizeof(media_visual_record_cnf_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_RECORD_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_stop_cnf
 * DESCRIPTION
 *  This function is to send visual stop confirm message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_stop_cnf(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_stop_cnf_struct *msg_p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_visual_stop_cnf_struct*) construct_local_para(sizeof(media_visual_stop_cnf_struct), TD_CTRL);

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_STOP_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  vis_send_record_finish_ind
 * DESCRIPTION
 *  This function is to send visual record finish indication message.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vis_send_record_finish_ind(kal_int16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_finish_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_visual_record_finish_ind_struct*)
        construct_local_para(sizeof(media_visual_record_finish_ind_struct), TD_CTRL);

    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_VISUAL_RECORD_FINISH_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}

#endif /* defined(__MED_MJPG_MOD__) */ 

#endif /* MED_V_NOT_PRESENT */ 


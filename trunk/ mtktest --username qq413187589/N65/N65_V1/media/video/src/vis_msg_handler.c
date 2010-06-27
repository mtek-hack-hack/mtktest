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
 *   vis_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of visual module.
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

/*==== INCLUDES =========*/
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
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "fat_fs.h"

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

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_v_struct.h"
#include "med_v_context.h"
#include "med_v_main.h"
#include "med_main.h"
#include "vid_main.h"
#include "med_utility.h"

#if defined(__MED_MJPG_MOD__)
#include "vid_avi.h"
#include "jpeg.h"
#endif

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif 

/***************************************************************************** 
 * Global Variables
 *****************************************************************************/
#if defined(__MED_VID_MOD__)
extern kal_int32 vid_get_result_from_fsal_error(kal_int32 error_code);
extern STMp4Parser *stMp4Parser_v_ptr;

#if defined(__MED_VID_ENC_MOD__)
extern MP4_FILELIST_STRUCT mp4_files;
extern STFSAL stFSAL;
extern STMp4Parser stMp4Parser;
extern STFSAL stFSALProducerAudData;
extern STFSAL stFSALProducerAudMeta;
extern STMp4Producer stMp4Producer;

extern const kal_uint16 lenSpeechBitsAMR[];
extern const kal_uint16 lenSpeechBitsAMR_WB[];

#if IS_CHIP_MT6219_AND_LATTER_VERSION
extern const kal_uint16 lenSpeechBitsAMR_WB[];
#endif 
kal_uint32 buffer_enc_tmp[1024 / 4];
kal_uint32 buffer_enc_real_meta_tmp[1024 / 4];
kal_uint32 buffer_merge_buffer[1024];
kal_uint32 buffer_enc_audio_sample_tmp[1024 / 4];
kal_uint32 buffer_enc_audio_tmp[1024 / 4];
#endif /* defined(__MED_VID_ENC_MOD__) */


/***************************************************************************** 
 * Local Functions 
 *****************************************************************************/
void vis_merge_editor_file(void);
void vis_merge_recorder_file(void);


/*****************************************************************************
 * FUNCTION
 *  vis_stop_req_hdlr
 * DESCRIPTION
 *  Stop visual request
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    VIS_ENTER_STATE(VISUAL_IDLE);
    vis_send_stop_cnf(MED_V_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  vis_decode_visual_data_ind_hdlr
 * DESCRIPTION
 *  Decode visual data handler
 *  Help driver to do visual related action in VIS task
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_decode_visual_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_decode_visual_data_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;
    ind_p = (media_decode_visual_data_ind_struct*) ilm_ptr->local_para_ptr;

    /* debug info */
    kal_trace(TRACE_GROUP_4, VIS_TRC_DECODE_DATA_IND_HDLR);
    kal_trace(TRACE_GROUP_4, VIS_TRC_DECODE_EVENT, ind_p->event);    

    if (VIS_IN_STATE(VISUAL_PLAY))
    {
        switch (ind_p->event)
        {
            case VIDEO_DEC_DRV_SEEK_ACTION:
                video_seek_action();
                break;

            case VIDEO_DEC_EVENT_BUFFER_EMPTY:
            {
                MEDIA_STATUS_CODE status;

                status = video_dec_put_frame_to_buffer();
                kal_trace(TRACE_GROUP_4, VIS_TRC_CALLING_VIDEO_DEC_PUT_FRAME_TO_BUFFER, __LINE__, status);                

            #ifdef __MED_VID_PDL_MOD__
                if ((vid_context_p->media_mode == MED_MODE_PDL_FILE) && 
                    (status != MEDIA_STATUS_OK))
                {
                    MP4_Parser_Status eMp4ParserRet;
                    kal_uint32 available_time;  

                    eMp4ParserRet = MP4_Video_GetAvailableDur(stMp4Parser_v_ptr, &available_time);
                    kal_trace(TRACE_GROUP_4, VIS_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, __LINE__, status, available_time);                 
    
                    if (eMp4ParserRet != MP4_PARSER_OK)
                    {
                        VIS_ENTER_STATE(VISUAL_IDLE);
                        vis_send_play_finish_ind(MED_RES_PARSER_ERROR);
                        return;
                    }     
                    
                    if ((available_time < vid_context_p->total_video_time) && 
                        (status == FSAL_READ_EOF || status == FSAL_SEEK_EOF))
                    {
                        VIS_ENTER_STATE(VISUAL_IDLE);                        
                        vis_send_play_finish_ind(MED_RES_PDL_VIDEO_UNDERFLOW);
                        return;
                    }
                    else if(status == FSAL_ERROR)
                    {   
                        /* FSAL read or seek error, but video already get at least 1 frame */
                        status = MEDIA_STATUS_OK;
                    }
                }
            #endif /* __MED_VID_PDL_MOD__ */
                
                if (status != MEDIA_STATUS_OK)
                {
                    VID_VIS_ERROR_TRACE(status, __LINE__);
                    VIS_ENTER_STATE(VISUAL_IDLE);
                    vis_send_play_finish_ind((kal_int16)vid_get_result_from_media_status(status));
                }
                break;
            }
            case VIDEO_DEC_EVENT_COMPLETE:
                VIS_ENTER_STATE(VISUAL_IDLE);
                vis_send_play_finish_ind(MED_V_RES_OK);
                break;

            case VIDEO_DEC_EVENT_SEEK_DONE:
                vis_send_seek_cnf(MED_V_RES_OK);
                break;

            case VIDEO_DEC_EVENT_NO_TRACK:
                vis_send_play_cnf(MED_V_RES_OK, 0);
                break;

            case VIDEO_DEC_RECOVER:
            {
                vis_send_error_recover_ind();
                break;
            }
            case VIDEO_DEC_EVENT_FAIL:
                VIS_ENTER_STATE(VISUAL_IDLE);
                vis_send_play_finish_ind(MED_RES_VIDEO_ERROR);
                break;

            case VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE:
                /* Should play mute, if video is not end!! */
                /* If video is also end, please stop it. */
                ASSERT(ind_p->event != VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE);
                break;

            default:
                ASSERT(0);
                break;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vis_play_req_hdlr
 * DESCRIPTION
 *  Play request handler
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_visual_play_req_struct*) ilm_ptr->local_para_ptr;

    VIS_ENTER_STATE(VISUAL_PLAY);

    vis_send_play_cnf(MED_V_RES_OK, 0);
}


/*****************************************************************************
 * FUNCTION
 *  vis_seek_req_hdlr
 * DESCRIPTION
 *  Seek request handler
 * PARAMETERS
 *  ilm_ptr     [IN]     message data  
 * RETURNS
 *  void
 *****************************************************************************/
void vis_seek_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_seek_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_visual_seek_req_struct*) ilm_ptr->local_para_ptr;
}


#if defined(__MED_VID_ENC_MOD__) || defined(__MED_VID_EDT_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vis_clean_temp_files
 * DESCRIPTION
 *  Clean temp files after file merge
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vis_clean_temp_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_FILE);
    FS_Delete(med_v_context_p->storing_path);

    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
    FS_Delete(med_v_context_p->storing_path);

    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_FILE);
    FS_Delete(med_v_context_p->storing_path);

    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_META_FILE);
    FS_Delete(med_v_context_p->storing_path);

    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_REAL_META_FILE);
    FS_Delete(med_v_context_p->storing_path);
}



/*****************************************************************************
 * FUNCTION
 *  vis_merge_file
 * DESCRIPTION
 *  Merge two files
 * PARAMETERS
 *  file_src        [IN]         source file (FSAL)
 *  file_dst        [IN/OUT]     dest file (FSAL)
 * RETURNS
 *  Merge result
 *****************************************************************************/
kal_int16 vis_merge_file(STFSAL *file_src, STFSAL *file_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_size;
    kal_uint32 dst_size;
    FSAL_Status eFSALRet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eFSALRet = FSAL_GetFileSize(file_src, &src_size);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        return vid_get_result_from_fsal_error(FSAL_GetLastError(file_src));
    }
    eFSALRet = FSAL_GetFileSize(file_dst, &dst_size);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        return vid_get_result_from_fsal_error(FSAL_GetLastError(file_dst));
    }

    eFSALRet = FSAL_Seek(file_dst, dst_size);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        return vid_get_result_from_fsal_error(FSAL_GetLastError(file_dst));
    }

    eFSALRet = FSAL_Seek(file_src, 0);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        return vid_get_result_from_fsal_error(FSAL_GetLastError(file_src));
    }
    while (src_size >= sizeof(buffer_merge_buffer))
    {
        eFSALRet = FSAL_Read(file_src, (kal_uint8*) buffer_merge_buffer, sizeof(buffer_merge_buffer));
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            return vid_get_result_from_fsal_error(FSAL_GetLastError(file_src));
        }
        eFSALRet = FSAL_Write(file_dst, (kal_uint8*) buffer_merge_buffer, sizeof(buffer_merge_buffer));
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            return vid_get_result_from_fsal_error(FSAL_GetLastError(file_dst));
        }
        src_size -= sizeof(buffer_merge_buffer);
    }
    if (src_size)
    {
        eFSALRet = FSAL_Read(file_src, (kal_uint8*) buffer_merge_buffer, src_size);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            return vid_get_result_from_fsal_error(FSAL_GetLastError(file_src));
        }
        eFSALRet = FSAL_Write(file_dst, (kal_uint8*) buffer_merge_buffer, src_size);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            return vid_get_result_from_fsal_error(FSAL_GetLastError(file_dst));
        }
        src_size = 0;
    }
    return MED_RES_OK;

}



/*****************************************************************************
 * FUNCTION
 *  vis_file_merge_req_hdlr
 * DESCRIPTION
 *  This function is to handle visual file merge request
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_file_merge_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    media_visual_file_merge_req_struct* msg_p = 
        (media_visual_file_merge_req_struct *) ilm_ptr->local_para_ptr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (MED_MODE_FILE == msg_p->mode)
    {
        vis_merge_recorder_file();
    }
    else if (MED_MODE_EDITOR_FILE == msg_p->mode)
    {
    #ifdef __MED_VID_EDT_MOD__    
        vis_merge_editor_file();
    #endif
    }

    /* ignore other cases */
}
#endif /* defined(__MED_VID_ENC_MOD__) || defined(__MED_VID_EDT_MOD__) */



#if defined(__MED_VID_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vis_record_req_hdlr
 * DESCRIPTION
 *  Record request handler
 * PARAMETERS
 *  ilm_ptr     [IN]      message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_visual_record_req_struct*) ilm_ptr->local_para_ptr;

    VIS_ENTER_STATE(VISUAL_RECORD);

    vis_send_record_cnf(MED_V_RES_OK);
}




/*****************************************************************************
 * FUNCTION
 *  vis_encode_visual_data_ind_hdlr
 * DESCRIPTION
 *  Encode visual data
 *  Help driver to do visual related action in VIS task
 * PARAMETERS
 *  ilm_ptr     [IN]        message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_encode_visual_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_encode_visual_data_ind_struct *ind_p;
    kal_uint32 residual_size;
    kal_uint32 increase_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VIS_IN_STATE(VISUAL_RECORD))
    {
        MEDIA_STATUS_CODE status;

        ind_p = (media_encode_visual_data_ind_struct*) ilm_ptr->local_para_ptr;

        switch (ind_p->event)
        {
            case VIDEO_ENC_EVENT_VIDEO_BUFFER_AVAIL:
                residual_size = vid_file_visual_residual_size();
                /* reserve some space for meta file */
                if (residual_size > 0 )
                {
                    kal_int32 result;

                    status = video_enc_buffer_store_file(residual_size, &increase_size);
                    VID_VALUE_TRACE( residual_size, increase_size, vid_context_p->file_size_info.disk_cluster_size);
                    
                    if (status != MEDIA_STATUS_OK &&
                       (result = VIDEO_GetLastError()) != MED_STAT_VIDEO_ENC_RESOURCE_NOT_AVAIL)
                    {
                        video_enc_stop_record();
                        VID_VIS_ERROR_TRACE(result, __LINE__);
                        VIS_ENTER_STATE(VISUAL_IDLE);
                        vis_send_record_finish_ind((kal_int16)vid_get_result_from_media_status(status));
                        break;
                    }
                    
                    vid_context_p->file_size_info.video_bitstream_size += increase_size;
                    vid_context_p->file_size_info.video_rm_size = video_evaluate_real_meta_file_size(vid_context_p->file_size_info.short_header_mode);
                    vid_context_p->file_size = vid_get_current_file_size();
                    
                    if (vid_context_p->file_size > vid_context_p->file_size_info.file_size_limit ||
                        (status != MEDIA_STATUS_OK &&
                         (result = VIDEO_GetLastError()) == MED_STAT_VIDEO_ENC_RESOURCE_NOT_AVAIL))
                    {
                        video_enc_stop_record();
                        VIS_ENTER_STATE(VISUAL_IDLE);
                        vis_send_record_finish_ind(MED_RES_END_OF_FILE);
                    }
                }
                else
                {
                    video_enc_stop_record();
                    VIS_ENTER_STATE(VISUAL_IDLE);
                    vis_send_record_finish_ind(MED_RES_END_OF_FILE);
                }
                break;

            case VIDEO_ENC_EVENT_META_BUFFER_AVAIL:
                residual_size = vid_file_meta_residual_size();
                status = meta_enc_buffer_store_file(residual_size, &increase_size);
                VID_VALUE_TRACE(residual_size, increase_size, __LINE__);
                
                if (status != MEDIA_STATUS_OK && VIDEO_GetLastError() != MED_STAT_VIDEO_ENC_RESOURCE_NOT_AVAIL)
                {
                    video_enc_stop_record();
                    VIS_ENTER_STATE(VISUAL_IDLE);
                    vis_send_record_finish_ind((kal_int16)vid_get_result_from_media_status(status));
                    break;
                }
                vid_context_p->file_size_info.video_meta_size += increase_size;
                vid_context_p->file_size_info.video_rm_size = video_evaluate_real_meta_file_size(vid_context_p->file_size_info.short_header_mode);
                vid_context_p->file_size = vid_get_current_file_size();
                
                if (vid_context_p->file_size > vid_context_p->file_size_info.file_size_limit ||
                    (status != MEDIA_STATUS_OK && VIDEO_GetLastError() == MED_STAT_VIDEO_ENC_RESOURCE_NOT_AVAIL))
                {
                    video_enc_stop_record();
                    VIS_ENTER_STATE(VISUAL_IDLE);
                    vis_send_record_finish_ind(MED_RES_END_OF_FILE);
                }
                break;

            case VIDEO_ENC_EVENT_COMPLETE:
                VIS_ENTER_STATE(VISUAL_IDLE);
                vis_send_record_finish_ind(MED_RES_END_OF_FILE);
                break;
            case VIDEO_ENC_EVENT_FAIL:
                VIS_ENTER_STATE(VISUAL_IDLE);
                vis_send_record_finish_ind(MED_RES_FAIL);
                break;
            default:
                break;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vis_write_audio_sample_data
 * DESCRIPTION
 *  Write audio sample(meta) file for video file merge
 * PARAMETERS
 *  audio_sample_count      [OUT]     audio sample count
 * RETURNS
 *  write result
 *****************************************************************************/
kal_int16 vis_write_audio_sample_data(kal_uint32 *audio_sample_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bAMRType = 0; /* 0:AMR 1:AMR-WB */
    kal_uint32 uSampleCount = 0;
    kal_uint32 uAMRFileLen;
    kal_uint32 uAMRFilePos;
    FSAL_Status eFSALRet;
    kal_bool audio_file_open = KAL_FALSE;
    kal_bool audio_meta_file_open = KAL_FALSE;
    kal_int16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open sample data file for writing */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
    if ((vid_context_p->file_handle = FS_Open(med_v_context_p->storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
        {
            result = MED_RES_WRITE_PROTECTION;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
        VID_FSAL_ERROR_TRACE(vid_context_p->file_handle, __LINE__);
        goto audio_sample_error;
    }
    audio_meta_file_open = KAL_TRUE;
    eFSALRet = FSAL_Open_WithHandle(&stFSALProducerAudMeta, (void*)vid_context_p->file_handle);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }
    FSAL_SetBuffer(
        &stFSALProducerAudMeta,
        (kal_uint32) sizeof(buffer_enc_audio_sample_tmp),
        (kal_uint8*) buffer_enc_audio_sample_tmp);

    /* open amr file */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_FILE);
    eFSALRet = FSAL_Open(&stFSALProducerAudData, (void*)med_v_context_p->storing_path, FSAL_READ);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }
    audio_file_open = KAL_TRUE;
    FSAL_SetBuffer(&stFSALProducerAudData, (kal_uint32) sizeof(buffer_enc_audio_tmp), (kal_uint8*) buffer_enc_audio_tmp);

    eFSALRet = FSAL_GetFileSize(&stFSALProducerAudData, &uAMRFileLen);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }
    uAMRFilePos = 8;

    eFSALRet = FSAL_Write_UINT8(&stFSALProducerAudMeta, MP4_AUDIO_AMR);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }

    /* reserve for sample count */
    eFSALRet = FSAL_Write_UINT(&stFSALProducerAudMeta, 0);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }

    /* parse each audio frame */
    while (uAMRFilePos < uAMRFileLen)
    {
        unsigned char bFrameHeader;
        unsigned char bFrameType;
        unsigned char bFrameLength;
        unsigned char bFQI;

        eFSALRet = FSAL_Seek(&stFSALProducerAudData, uAMRFilePos);
        if (eFSALRet != FSAL_OK)
        {
            result = MED_RES_OPEN_FILE_FAIL;
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto audio_sample_error;
        }

        eFSALRet = FSAL_Read_Bytes(&stFSALProducerAudData, &bFrameHeader, 1);
        if (eFSALRet != FSAL_OK)
        {
            result = MED_RES_OPEN_FILE_FAIL;
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto audio_sample_error;
        }

        bFrameType = (bFrameHeader >> 3) & 0x0F;
        bFQI = (bFrameHeader >> 2) & 0x01;
        if (bFQI == 0)
        {
            result = MED_RES_OPEN_FILE_FAIL;
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto audio_sample_error;
        }
        // ASSERT(bFQI==1);
        // After this line, bFQI is no more valid and hence can be used as temporary variable.

        if (bAMRType == 0)
        {
            bFQI = 8;   /* AMR */
        }
        else
        {
            bFQI = 9;   /* AMR-WB */
        }

        if (bFrameType <= bFQI)
        {
            bFrameLength = (lenSpeechBitsAMR[bFrameType] + 7) / 8;
        }
        else if (bFrameType == 15)
        {
            bFrameLength = 0;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto audio_sample_error;
            /* ASSERT(0); */
        }

        uAMRFilePos += (bFrameLength + 1);

        /* Handle the case for partial frame */
        if (uAMRFilePos > uAMRFileLen)
        {
            break;
        }

        uSampleCount++;

        /* eFSALRet = FSAL_Write_UINT8(&stFSALProducerAudMeta, bFrameType); */
        eFSALRet = FSAL_Write_Bytes(&stFSALProducerAudMeta, &bFrameType, 1);
        if (eFSALRet != FSAL_OK)
        {
            result = MED_RES_OPEN_FILE_FAIL;
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto audio_sample_error;
        }
    }

    /* close AMR file */
    eFSALRet = FSAL_Close(&stFSALProducerAudData);
    audio_file_open = KAL_FALSE;
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }

    /* go back to write sample count */
    eFSALRet = FSAL_Seek(&stFSALProducerAudMeta, 1);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }

    eFSALRet = FSAL_Write_UINT(&stFSALProducerAudMeta, uSampleCount);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }

    eFSALRet = FSAL_Close(&stFSALProducerAudMeta);
    audio_meta_file_open = KAL_FALSE;
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto audio_sample_error;
    }

    result = MED_RES_OK;
    *audio_sample_count = uSampleCount;

  audio_sample_error:
    if (audio_file_open)
    {
        FSAL_Close(&stFSALProducerAudData);
    }
    if (audio_meta_file_open)
    {
        FSAL_Close(&stFSALProducerAudMeta);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  vis_read_file_path
 * DESCRIPTION
 *  Read file path for further use
 * PARAMETERS
 *  path        [OUT]      file path
 * RETURNS
 *  void
 *****************************************************************************/
void vis_read_file_path(kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_READ_ONLY);
    if (fd >= 0)
    {
        kal_wchar flag;

        result = FS_Read(fd, &flag, 1 * ENCODE_BYTE, &len);
        if (flag == L'Y')
        {
            vid_context_p->use_pseudo_merge = KAL_TRUE;
        }
        else
        {
            vid_context_p->use_pseudo_merge = KAL_FALSE;
        }
        VID_VALUE_TRACE(vid_context_p->use_pseudo_merge, flag, __LINE__);

        result = FS_Read(fd, path, MAX_FILE_NAME_LEN * 2, &len);
        FS_Close(fd);
    }

}



/*****************************************************************************
 * FUNCTION
 *  vis_merge_recorder_file
 * DESCRIPTION
 *  Handle visual file merge request for video recorder
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void vis_merge_recorder_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    kal_uint32 video_file_size;
    kal_uint32 audio_trak_size = 0;
    MP4_FILE_INFO video_file_info;
    kal_uint32 video_mdatsz_pos;
    kal_uint32 cluster_size;
    FS_DiskInfo disc_info;
    kal_wchar drive[4] = L" :\\";
    kal_uint8 test_vos_data[60];
    STMp4SampleDataAudio stMp4SampleData;
    MP4_SampleData_Status eMp4SampleDataStatus;
    kal_uint32 uAudioFileLen;
    kal_bool audio_file_exist;
    kal_bool video_real_meta_file_exist;
    kal_bool video_file_open = KAL_FALSE;
    kal_bool video_meta_file_open = KAL_FALSE;
    kal_bool video_real_meta_file_open = KAL_FALSE;
    kal_bool audio_file_open = KAL_FALSE;
    kal_bool audio_meta_file_open = KAL_FALSE;
    MP4_FILE_CREATE_STRUCT file_struct;
    kal_int16 result = 0;
    MEDIA_STATUS_CODE status;
    kal_int32 attribute;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vis_read_file_path(med_v_context_p->current_file_name);
    vis_read_file_path(med_v_context_p->storing_path);
    /* Jensen add */
    kal_mem_cpy(med_v_context_p->storing_path2, med_v_context_p->storing_path, MAX_FILE_NAME_LEN * 2);
    // If power off abnormal at the below procedure, med task can't recovery these conditions.
    // Therefore, delete "z:\\video_file.ini" first!!
    FS_Rename((kal_wchar*) VID_INIT_FILE, (kal_wchar*) VID_DUMMY_INIT_FILE);
    FS_Delete((kal_wchar*) VID_INIT_FILE);

    /* Log disc info for debugging */
    drive[0] = med_v_context_p->storing_path[0];
    FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
    cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;
    kal_prompt_trace(MOD_MED, "Free cluster=%d, cluster size= %d, line= %d", disc_info.FreeClusters, cluster_size,__LINE__);
    /* Open video file */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_FILE);

    eFSALRet = FSAL_Open(&mp4_files.MEDIA_VIDEO_FILE, (void*)med_v_context_p->storing_path, FSAL_APPEND);
    if (eFSALRet != FSAL_OK)
    {
        result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto merge_error;
    }
    video_file_open = KAL_TRUE;
    /* Open meta file */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_META_FILE);
    eFSALRet = FSAL_Open(&mp4_files.MEDIA_META_FILE, (void*)med_v_context_p->storing_path, FSAL_APPEND);
    if (eFSALRet != FSAL_OK)
    {
        result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto merge_error;
    }
    video_meta_file_open = KAL_TRUE;
    FSAL_SetBuffer(&mp4_files.MEDIA_META_FILE, (kal_uint32) sizeof(buffer_enc_tmp), (kal_uint8*) buffer_enc_tmp);

    /* Open Audio file */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_FILE);
    eFSALRet = FSAL_Open(&stFSALProducerAudData, (void*)med_v_context_p->storing_path, FSAL_READ);
    if (eFSALRet == FSAL_OK)
    {
        audio_file_exist = KAL_TRUE;
        FSAL_Close(&stFSALProducerAudData);
    }
    else
    {
        audio_file_exist = KAL_FALSE;
    }

    /* check video real meta file exist */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_REAL_META_FILE);
    eFSALRet = FSAL_Open(&mp4_files.REAL_META_FILE, (void*)med_v_context_p->storing_path, FSAL_READ);
    if (eFSALRet == FSAL_OK)
    {
        video_real_meta_file_exist = KAL_TRUE;
        FSAL_Close(&mp4_files.REAL_META_FILE);
    }
    else
    {
        video_real_meta_file_exist = KAL_FALSE;
    }

    /* Video video file/meta file ready */

    /* Create video real meta file */
    {
        t_rtc rtctime;

        file_struct.temp_video_size = 0;

        status = video_enc_get_timescale(&mp4_files.MEDIA_META_FILE, &file_struct.time_scale);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
            }
            goto merge_error;
        }
        status = video_enc_get_type(&mp4_files.MEDIA_META_FILE, &file_struct.short_header);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
            }
            goto merge_error;
        }
        RTC_GetTime(&rtctime);
        file_struct.create_time = mpeg4_cratetime_translate(&rtctime);
        file_struct.total_duration = 0;
        status = video_enc_get_frame_size(&mp4_files.MEDIA_META_FILE, &file_struct.frame_width, &file_struct.frame_height);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
            }
            goto merge_error;
        }
        status = video_enc_get_framerate(&mp4_files.MEDIA_META_FILE, &file_struct.frame_rate);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
            }
            goto merge_error;
        }
        status = video_enc_get_vos_length(&mp4_files.MEDIA_META_FILE, &file_struct.VOS_length);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
            }
            goto merge_error;
        }

        if (file_struct.short_header == 0)
        {
            if (file_struct.VOS_length > 60)
            {
                goto merge_error;
            }

            file_struct.VOS_ptr = test_vos_data;
            status = video_enc_get_vos_data(test_vos_data, file_struct.VOS_length, &mp4_files.MEDIA_META_FILE);
        }
        status = video_enc_get_totalframes(
                    &mp4_files.MEDIA_VIDEO_FILE,
                    &mp4_files.MEDIA_META_FILE,
                    &file_struct,
                    &file_struct.frame_number);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
            }
            goto merge_error;
        }

        eFSALRet = FSAL_GetFileSize(&mp4_files.MEDIA_VIDEO_FILE, &video_file_size);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        status = video_enc_get_mdatsz_pos(&mp4_files.MEDIA_META_FILE, &video_mdatsz_pos);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
            }
            goto merge_error;
        }

        if (audio_file_exist != KAL_TRUE && video_real_meta_file_exist == KAL_TRUE)
        {
            eFSALRet = FSAL_Seek(&mp4_files.MEDIA_VIDEO_FILE, video_mdatsz_pos);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            /* Maybe some wrong bitstream will be include, because the characteristics of PS_Merge. */
            eFSALRet = FSAL_Read_UINT(&mp4_files.MEDIA_VIDEO_FILE, &file_struct.temp_video_size);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            status = video_enc_get_totalframes(
                        &mp4_files.MEDIA_VIDEO_FILE,
                        &mp4_files.MEDIA_META_FILE,
                        &file_struct,
                        &file_struct.frame_number);
            if (status != MEDIA_STATUS_OK)
            {
                VID_VIS_ERROR_TRACE(status, __LINE__);
                result = vid_get_result_from_media_status(status);
                if (result == MED_RES_FSAL_ERROR)
                {
                    result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
                }
                goto merge_error;
            }
        }

        if (vid_context_p->use_pseudo_merge)
        {
            video_file_size = ((video_file_size + cluster_size - 1) / cluster_size) * cluster_size;
            eFSALRet = FSAL_Write_UINT_AT(
                        &mp4_files.MEDIA_VIDEO_FILE,
                        video_file_size - video_mdatsz_pos,
                        video_mdatsz_pos);
        }
        else
        {
            eFSALRet = FSAL_Write_UINT_AT(
                        &mp4_files.MEDIA_VIDEO_FILE,
                        video_file_size - video_mdatsz_pos,
                        video_mdatsz_pos);
        }
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        FS_Commit(mp4_files.MEDIA_VIDEO_FILE.hFile);

        /* Create REAL_META FILE */
        med_remove_file_name(med_v_context_p->storing_path);
        kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_REAL_META_FILE);

        if ((vid_context_p->file_handle = FS_Open(med_v_context_p->storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
        {
            if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
            {
                result = MED_RES_WRITE_PROTECTION;
            }
            else
            {
                result = MED_RES_OPEN_FILE_FAIL;
            }
            goto merge_error;
        }
        video_real_meta_file_open = KAL_TRUE;
        eFSALRet = FSAL_Open_WithHandle(&mp4_files.REAL_META_FILE, (void*)vid_context_p->file_handle);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        FSAL_SetBuffer(
            &mp4_files.REAL_META_FILE,
            (kal_uint32) sizeof(buffer_enc_real_meta_tmp),
            (kal_uint8*) buffer_enc_real_meta_tmp);

        status = video_enc_generate_META_file(&file_struct, &mp4_files.REAL_META_FILE, &video_file_info);
        if (status != MEDIA_STATUS_OK)
        {
            VID_VIS_ERROR_TRACE(status, __LINE__);
            result = vid_get_result_from_media_status(status);
            if (result == MED_RES_FSAL_ERROR)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
            }
            goto merge_error;
        }

        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        video_file_open = KAL_FALSE;
    }

    if ((vid_context_p->use_pseudo_merge == KAL_FALSE) && (audio_file_exist == KAL_TRUE))
    {
        kal_uint32 result_bytes;
        MP4_Producer_Status AudioProducerStat;

        med_remove_file_name(med_v_context_p->storing_path);
        kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_FILE);

        eFSALRet = FSAL_Open(&stFSALProducerAudData, (void*)med_v_context_p->storing_path, FSAL_READ);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        audio_file_open = KAL_TRUE;

        AudioProducerStat = MP4_Produce_CalculateLimitedAudioFileSize(
                                &stFSALProducerAudData,
                                (kal_uint32) video_file_size,
                                (kal_uint32) file_struct.total_duration,
                                0,  /* 0: AMR 1: WB-AMR */
                                &result_bytes);
        if (AudioProducerStat != MP4_PRODUCER_OK)
        {
            result = MED_RES_AUDIO_ERROR;
            VID_AUD_ERROR_TRACE(AudioProducerStat, __LINE__);
            goto merge_error;
        }

        eFSALRet = FSAL_Direct_Seek(&stFSALProducerAudData, result_bytes);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        FS_Truncate(stFSALProducerAudData.hFile);
        FSAL_Close(&stFSALProducerAudData);
        audio_file_open = KAL_FALSE;
    }

    /* Create audio real meta file */
    if (audio_file_exist == KAL_TRUE)   /* Audio file exist */
    {
        kal_uint32 audio_sample_count;

        med_remove_file_name(med_v_context_p->storing_path);
        kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_FILE);
        eFSALRet = FSAL_Open(&stFSALProducerAudData, (void*)med_v_context_p->storing_path, FSAL_APPEND);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        audio_file_open = KAL_TRUE;
        eFSALRet = FSAL_GetFileSize(&stFSALProducerAudData, &uAudioFileLen);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }

        eFSALRet = FSAL_Seek(&stFSALProducerAudData, 0);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }

        if (vid_context_p->use_pseudo_merge)
        {
            uAudioFileLen = ((uAudioFileLen + cluster_size - 1) / cluster_size) * cluster_size;
        }

        eFSALRet = FSAL_Write_UINT(&stFSALProducerAudData, uAudioFileLen);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }

        FSAL_Close(&stFSALProducerAudData);
        audio_file_open = KAL_FALSE;
        /* Log disc info for debugging */
        FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
        kal_prompt_trace(MOD_MED, "Free cluster=%d, cluster size= %d, line= %d", disc_info.FreeClusters, cluster_size,__LINE__);
        /* Create audio meta file */
        /* generate audio sample data file */
        result = vis_write_audio_sample_data(&audio_sample_count);
        if (result != MED_RES_OK)
        {
            VID_AUD_ERROR_TRACE(result, __LINE__);
            goto merge_error;
        }

        if (audio_sample_count > 0)
        {
            /* Create audio real meta file */
            med_remove_file_name(med_v_context_p->storing_path);
            kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
            eFSALRet = FSAL_Open(&stFSALProducerAudMeta, (void*)med_v_context_p->storing_path, FSAL_READ);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudMeta));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            audio_meta_file_open = KAL_TRUE;
            FSAL_SetBuffer(
                &stFSALProducerAudMeta,
                (kal_uint32) sizeof(buffer_enc_audio_sample_tmp),
                (kal_uint8*) buffer_enc_audio_sample_tmp);
            eMp4SampleDataStatus = MP4_AudioSampleData_Init(&stMp4SampleData, &stFSALProducerAudMeta);
            if (eMp4SampleDataStatus != MP4_SAMPLE_DATA_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudMeta));
                result = MED_RES_MP4_SAMPLEDATA_ERROR;
                goto merge_error;
            }

            MP4_Produce_Init(&stMp4Producer, &stMp4SampleData, &mp4_files.REAL_META_FILE);
            MP4_Produce_Trak_Audio(&stMp4Producer, &audio_trak_size, video_file_size);
            /* Add audio trak size */
            video_file_info.FC_ATOM[moov].size += audio_trak_size;
            eFSALRet = FSAL_Close(&stFSALProducerAudMeta);
            audio_meta_file_open = KAL_FALSE;
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudMeta));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }

            eFSALRet = FSAL_Write_UINT_AT(
                        &mp4_files.REAL_META_FILE,
                        video_file_info.FC_ATOM[moov].size,
                        video_file_info.FC_ATOM[moov].pos);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            FS_Commit(mp4_files.REAL_META_FILE.hFile);
            /* Merge video real meta file and audio real meta file */

            /* Delete audio meta file to save some space */
            med_remove_file_name(med_v_context_p->storing_path);
            kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
            FS_Delete(med_v_context_p->storing_path);
            vid_context_p->record_audio = KAL_TRUE;
        }
        else
        {
            eFSALRet = FSAL_Write_UINT_AT(
                        &mp4_files.REAL_META_FILE,
                        video_file_info.FC_ATOM[moov].size,
                        video_file_info.FC_ATOM[moov].pos);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            FS_Commit(mp4_files.REAL_META_FILE.hFile);
            vid_context_p->record_audio = KAL_FALSE;
            FSAL_Close(&stFSALProducerAudData);
            audio_file_open = KAL_FALSE;
        }
    }
    else
    {
        /* Create audio real meta file */
        med_remove_file_name(med_v_context_p->storing_path);
        kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
        eFSALRet = FSAL_Open(&stFSALProducerAudMeta, (void*)med_v_context_p->storing_path, FSAL_READ);
        /* Audio file not exist, but audio meta file exist */
        if (eFSALRet == FSAL_OK)
        {
            audio_meta_file_open = KAL_TRUE;
            FSAL_SetBuffer(
                &stFSALProducerAudMeta,
                (kal_uint32) sizeof(buffer_enc_audio_sample_tmp),
                (kal_uint8*) buffer_enc_audio_sample_tmp);
            eMp4SampleDataStatus = MP4_AudioSampleData_Init(&stMp4SampleData, &stFSALProducerAudMeta);
            if (eMp4SampleDataStatus != MP4_SAMPLE_DATA_OK)
            {
                VID_PARSE_ERROR_TRACE(eMp4SampleDataStatus, __LINE__);
                result = MED_RES_MP4_SAMPLEDATA_ERROR;
                goto merge_error;
            }

            /* Log disc info for debugging */
            FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
            kal_prompt_trace(MOD_MED, "Free cluster=%d, cluster size= %d, line= %d", disc_info.FreeClusters, cluster_size,__LINE__);

            MP4_Produce_Init(&stMp4Producer, &stMp4SampleData, &mp4_files.REAL_META_FILE);
            MP4_Produce_Trak_Audio(&stMp4Producer, &audio_trak_size, video_file_size);
            /* Add audio trak size */
            video_file_info.FC_ATOM[moov].size += audio_trak_size;
            eFSALRet = FSAL_Close(&stFSALProducerAudMeta);
            audio_meta_file_open = KAL_FALSE;
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudMeta));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }

            eFSALRet = FSAL_Write_UINT_AT(
                        &mp4_files.REAL_META_FILE,
                        video_file_info.FC_ATOM[moov].size,
                        video_file_info.FC_ATOM[moov].pos);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            FS_Commit(mp4_files.REAL_META_FILE.hFile);
            /* Merge video real meta file and audio real meta file */

            /* Delete audio meta file to save some space */
            med_remove_file_name(med_v_context_p->storing_path);
            kal_wstrcat(med_v_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
            FS_Delete(med_v_context_p->storing_path);

            vid_context_p->record_audio = KAL_TRUE;
        }
        else
        {
            eFSALRet = FSAL_Write_UINT_AT(
                        &mp4_files.REAL_META_FILE,
                        video_file_info.FC_ATOM[moov].size,
                        video_file_info.FC_ATOM[moov].pos);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            FS_Commit(mp4_files.REAL_META_FILE.hFile);
            vid_context_p->record_audio = KAL_FALSE;
        }
    }

    eFSALRet = FSAL_Close(&mp4_files.REAL_META_FILE);
    video_real_meta_file_open = KAL_FALSE;
    if (eFSALRet != FSAL_OK)
    {
        result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto merge_error;
    }
    eFSALRet = FSAL_Close(&mp4_files.MEDIA_META_FILE);
    video_meta_file_open = KAL_FALSE;
    if (eFSALRet != FSAL_OK)
    {
        result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_META_FILE));
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        goto merge_error;
    }
    /* Delete Visual Meta file to save some space */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_META_FILE);
    FS_Delete(med_v_context_p->storing_path);

    /* Merge audio/video bistream */
    if (vid_context_p->record_audio)
    {
        med_remove_file_name(med_v_context_p->storing_path);
        kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_FILE);
        med_remove_file_name(med_v_context_p->storing_path2);
        kal_wstrcat(med_v_context_p->storing_path2, VID_AUDIO_FILE);

        if (vid_context_p->use_pseudo_merge)
        {
            FS_PseudoMerge(med_v_context_p->storing_path, med_v_context_p->storing_path2);
        }
        else
        {
            eFSALRet = FSAL_Open(&stFSALProducerAudData, med_v_context_p->storing_path2, FSAL_READ);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            audio_file_open = KAL_TRUE;

            eFSALRet = FSAL_Open(&mp4_files.MEDIA_VIDEO_FILE, med_v_context_p->storing_path, FSAL_APPEND);
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            video_file_open = KAL_TRUE;

            result = vis_merge_file(&stFSALProducerAudData, &mp4_files.MEDIA_VIDEO_FILE);
            if (result != MED_RES_OK)
            {
                VID_VIS_ERROR_TRACE(result, __LINE__);
                goto merge_error;
            }

            eFSALRet = FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
            video_file_open = KAL_FALSE;
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
            eFSALRet = FSAL_Close(&stFSALProducerAudData);
            audio_file_open = KAL_FALSE;
            if (eFSALRet != FSAL_OK)
            {
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudData));
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                goto merge_error;
            }
        }

    }

    /* Merge av bitstream file and av real meta file */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_FILE);
    med_remove_file_name(med_v_context_p->storing_path2);
    kal_wstrcat(med_v_context_p->storing_path2, VID_VISUAL_REAL_META_FILE);

    if (vid_context_p->use_pseudo_merge)
    {
        FS_PseudoMerge(med_v_context_p->storing_path, med_v_context_p->storing_path2);
    }
    else
    {
        eFSALRet = FSAL_Open(&mp4_files.REAL_META_FILE, med_v_context_p->storing_path2, FSAL_READ);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        video_real_meta_file_open = KAL_TRUE;

        eFSALRet = FSAL_Open(&mp4_files.MEDIA_VIDEO_FILE, med_v_context_p->storing_path, FSAL_APPEND);
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        video_file_open = KAL_TRUE;

        result = vis_merge_file(&mp4_files.REAL_META_FILE, &mp4_files.MEDIA_VIDEO_FILE);
        if (result != MED_RES_OK)
        {
            VID_VIS_ERROR_TRACE(result, __LINE__);
            goto merge_error;
        }

        eFSALRet = FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        video_file_open = KAL_FALSE;
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.MEDIA_VIDEO_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
        eFSALRet = FSAL_Close(&mp4_files.REAL_META_FILE);
        video_real_meta_file_open = KAL_FALSE;
        if (eFSALRet != FSAL_OK)
        {
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&mp4_files.REAL_META_FILE));
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            goto merge_error;
        }
    }

    /* Log disc info for debugging */
    FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
    kal_prompt_trace(MOD_MED, "Free cluster=%d, cluster size= %d, line= %d", disc_info.FreeClusters, cluster_size,__LINE__);

    /* Rename to file name specified by MMI */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_FILE);
    /* Check if current file exist */
    if ((file_handle = FS_Open((kal_wchar*) med_v_context_p->current_file_name, FS_READ_ONLY)) < 0)
    {
        FS_Rename(med_v_context_p->storing_path, med_v_context_p->current_file_name);
        attribute = FS_GetAttributes(med_v_context_p->current_file_name);
        attribute &= (~FS_ATTR_HIDDEN);
        FS_SetAttributes(med_v_context_p->current_file_name, (kal_uint8)attribute);
        result = MED_RES_OK;
    }
    else
    {
        FS_Close(file_handle);           
        result = MED_RES_OPEN_FILE_FAIL;
    }

  merge_error:
    if (video_file_open)
    {
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
    }
    if (video_meta_file_open)
    {
        FSAL_Close(&mp4_files.MEDIA_META_FILE);
    }
    if (video_real_meta_file_open)
    {
        FSAL_Close(&mp4_files.REAL_META_FILE);
    }
    if (audio_file_open)
    {
        FSAL_Close(&stFSALProducerAudData);
    }
    if (audio_meta_file_open)
    {
        FSAL_Close(&stFSALProducerAudMeta);
    }

    /* clean all temp files */
    vis_clean_temp_files();
    /* send file merge confirm message to media task */
    vis_send_file_merge_cnf(result);

}
#endif /* defined(__MED_VID_ENC_MOD__) */



#if defined(__MED_VID_EDT_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vis_merge_editor_file
 * DESCRIPTION
 *  Handle visual file merge request for video editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vis_merge_editor_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    kal_uint32 video_file_size;
    kal_uint32 video_size;
    kal_uint32 audio_size;
    kal_uint8 *audio_tmp;
    kal_uint32 audio_trak_size;
    MP4_FILE_INFO video_file_info;    
    t_rtc rtctime;
    MP4_FILE_CREATE_STRUCT file_struct;
    kal_uint32 video_mdatsz_pos;
    MEDIA_STATUS_CODE status;
    kal_int32 result;
    kal_uint32 uAudioFileLen;
    STMp4SampleDataAudio stMp4SampleData;
    MP4_SampleData_Status eMp4SampleDataStatus;    
    FS_DiskInfo disc_info;
    kal_wchar drive[4] = L" :\\";    
    FS_HANDLE file_handle;    
    kal_uint8 test_vos_data[60]; 
    kal_uint32 cluster_size;    
    kal_int32 attribute;
    
    /*----------------------------------------------------------------*/
    /* Macro                                                          */
    /*----------------------------------------------------------------*/
#define EDT_MERGE_V_DRV_ERROR_HDLR(__FILE_H__)                      \
    do{                                                             \
        if (status != MEDIA_STATUS_OK)                              \
        {                                                           \
            VID_VIS_ERROR_TRACE(status, __LINE__);                  \
            result = vid_get_result_from_media_status(status);      \
            if (result == MED_RES_FSAL_ERROR)                       \
            {                                                       \
                result = vid_get_result_from_fsal_error(FSAL_GetLastError(&__FILE_H__));    \
            }                                                       \
            goto edt_merge_error;                                   \
        }                                                           \
    } while(0);


#define EDT_MERGE_FSAL_ERROR_HDLR(__FILE_H__)           \
    do{                                                 \
        if (eFSALRet != FSAL_OK)                        \
        {                                               \
            result = vid_get_result_from_fsal_error(FSAL_GetLastError(&__FILE_H__));    \
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);   \
            goto edt_merge_error;                       \
        }                                               \
    } while(0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	file_struct.temp_video_size = 0;
    result = MED_RES_OK;

    kal_mem_cpy(med_v_context_p->current_file_name, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    kal_mem_cpy(med_v_context_p->storing_path, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    
    FSAL_CacheFlush(&mp4_files.MEDIA_VIDEO_FILE);
    eFSALRet = FSAL_GetFileSize(&mp4_files.MEDIA_VIDEO_FILE, &video_file_size);
    EDT_MERGE_FSAL_ERROR_HDLR(mp4_files.MEDIA_VIDEO_FILE);

    status = video_enc_get_timescale(&mp4_files.MEDIA_META_FILE, &file_struct.time_scale);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);
               
    status =  video_enc_get_type(&mp4_files.MEDIA_META_FILE, &file_struct.short_header);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);
  
    RTC_GetTime(&rtctime);
	file_struct.create_time = mpeg4_cratetime_translate(&rtctime);

    status = video_enc_get_frame_size(&mp4_files.MEDIA_META_FILE, &file_struct.frame_width,&file_struct.frame_height);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);

    status = video_enc_get_framerate(&mp4_files.MEDIA_META_FILE, &file_struct.frame_rate);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);
    
    status = video_enc_get_vos_length(&mp4_files.MEDIA_META_FILE, &file_struct.VOS_length);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);
    
    status=video_enc_get_mdatsz_pos(&mp4_files.MEDIA_META_FILE, &video_mdatsz_pos);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);

    eFSALRet = FSAL_Write_UINT_AT (
                &mp4_files.MEDIA_VIDEO_FILE,
                video_file_size-video_mdatsz_pos,
                video_mdatsz_pos);
    EDT_MERGE_FSAL_ERROR_HDLR(mp4_files.MEDIA_VIDEO_FILE);
    
    status = video_enc_get_vos_length(&mp4_files.MEDIA_META_FILE, &file_struct.VOS_length);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);
    
    if (file_struct.short_header == 0)
    {
        ASSERT(file_struct.VOS_length <= 60);
        file_struct.VOS_ptr = test_vos_data;
        status = video_enc_get_vos_data(test_vos_data, file_struct.VOS_length, &mp4_files.MEDIA_META_FILE);
        EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_META_FILE);
    }

    status = video_enc_get_totalframes(&mp4_files.MEDIA_VIDEO_FILE, &mp4_files.MEDIA_META_FILE,&file_struct,&file_struct.frame_number);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.MEDIA_VIDEO_FILE);
    
    status = video_enc_generate_META_file(&file_struct,&mp4_files.REAL_META_FILE, &video_file_info);
    EDT_MERGE_V_DRV_ERROR_HDLR(mp4_files.REAL_META_FILE);
    
    FSAL_CacheFlush(&mp4_files.MEDIA_VIDEO_FILE);
    eFSALRet = FSAL_GetFileSize(&mp4_files.MEDIA_VIDEO_FILE, &video_size);
    EDT_MERGE_FSAL_ERROR_HDLR(mp4_files.MEDIA_VIDEO_FILE);
    
    FSAL_CacheFlush(&stFSALProducerAudData);
    eFSALRet = FSAL_GetFileSize(&stFSALProducerAudData, &uAudioFileLen);
    EDT_MERGE_FSAL_ERROR_HDLR(stFSALProducerAudData);    
     
    eFSALRet = FSAL_Seek(&stFSALProducerAudData, 0);
    EDT_MERGE_FSAL_ERROR_HDLR(stFSALProducerAudData);        

            
    eMp4SampleDataStatus = MP4_AudioSampleData_Init(&stMp4SampleData, &stFSALProducerAudMeta);
    MP4_AudioSampleData_SetVidEditFlag(&stMp4SampleData);
    
    if (eMp4SampleDataStatus != MP4_SAMPLE_DATA_OK)
    {
        result = vid_get_result_from_fsal_error(FSAL_GetLastError(&stFSALProducerAudMeta));
        result = MED_RES_MP4_SAMPLEDATA_ERROR;
        goto edt_merge_error;
    }
   
    MP4_Produce_Init(&stMp4Producer, &stMp4SampleData, &mp4_files.REAL_META_FILE);
    MP4_Produce_SetVidEditFlag(&stMp4Producer);
    MP4_Produce_Trak_Audio(&stMp4Producer, &audio_trak_size, video_file_size);
                        
    /* Add audio trak size */
    video_file_info.FC_ATOM[moov].size += audio_trak_size;
            
    eFSALRet = FSAL_Write_UINT_AT(
                &mp4_files.REAL_META_FILE,
                video_file_info.FC_ATOM[moov].size,
                video_file_info.FC_ATOM[moov].pos);
    EDT_MERGE_FSAL_ERROR_HDLR(mp4_files.REAL_META_FILE);      

    eFSALRet = FSAL_Seek(&mp4_files.MEDIA_VIDEO_FILE, video_size);
    EDT_MERGE_FSAL_ERROR_HDLR(mp4_files.MEDIA_VIDEO_FILE);   
    
    FSAL_CacheFlush(&stFSALProducerAudData);
    eFSALRet = FSAL_GetFileSize(&stFSALProducerAudData, &audio_size);
    EDT_MERGE_FSAL_ERROR_HDLR(stFSALProducerAudData);   
    
    audio_size = audio_size+8;
    audio_tmp = (kal_uint8 *)&audio_size;
            
    FSAL_Write_Bytes(&mp4_files.MEDIA_VIDEO_FILE, (kal_uint8 *)&audio_tmp[3], 1);
    FSAL_Write_Bytes(&mp4_files.MEDIA_VIDEO_FILE, (kal_uint8 *)&audio_tmp[2], 1);
    FSAL_Write_Bytes(&mp4_files.MEDIA_VIDEO_FILE, (kal_uint8 *)&audio_tmp[1], 1);
    FSAL_Write_Bytes(&mp4_files.MEDIA_VIDEO_FILE, (kal_uint8 *)&audio_tmp[0], 1);
    FSAL_Write_Bytes(&mp4_files.MEDIA_VIDEO_FILE, (kal_uint8 *)"mdat", 4);

    FSAL_CacheFlush(&stFSALProducerAudData);
    FSAL_CacheFlush(&mp4_files.MEDIA_VIDEO_FILE);
    result = vis_merge_file(&stFSALProducerAudData, &mp4_files.MEDIA_VIDEO_FILE);
    if (result != MED_RES_OK)
    {
        VID_VIS_ERROR_TRACE(result, __LINE__);
        goto edt_merge_error;
    }

    FSAL_CacheFlush(&mp4_files.REAL_META_FILE);
    FSAL_CacheFlush(&mp4_files.MEDIA_VIDEO_FILE);
    result = vis_merge_file(&mp4_files.REAL_META_FILE,&mp4_files.MEDIA_VIDEO_FILE);
    if (result != MED_RES_OK)
    {
        VID_VIS_ERROR_TRACE(result, __LINE__);
        goto edt_merge_error;
    }

    /* close opened files */
    if (vid_context_p->edt_is_v_data_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        vid_context_p->edt_is_v_data_file_opened = KAL_FALSE;
    }

    if (vid_context_p->edt_is_v_meta_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_META_FILE);    
        vid_context_p->edt_is_v_meta_file_opened = KAL_FALSE;        
    }

    if (vid_context_p->edt_is_v_real_meta_file_opened)
    {
        FSAL_Close(&mp4_files.REAL_META_FILE);    
        vid_context_p->edt_is_v_real_meta_file_opened = KAL_FALSE;        
    }    

    if (vid_context_p->edt_is_a_data_file_opened)
    {
        FSAL_Close(&stFSALProducerAudData);
        vid_context_p->edt_is_a_data_file_opened = KAL_FALSE;        
    }

    if (vid_context_p->edt_is_a_meta_file_opened)
    {
        FSAL_Close(&stFSALProducerAudMeta);
        vid_context_p->edt_is_a_meta_file_opened = KAL_FALSE;        
    }

    /* Log disc info for debugging */
    drive[0] = med_v_context_p->storing_path[0];
    FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
    cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;
    kal_prompt_trace(MOD_MED, "Free cluster=%d, cluster size= %d, line= %d", disc_info.FreeClusters, cluster_size,__LINE__);

    /* Rename to file name specified by MMI */
    med_remove_file_name(med_v_context_p->storing_path);
    kal_wstrcat(med_v_context_p->storing_path, VID_VISUAL_FILE);
    
    /* Check if current file exist */
    if ((file_handle = FS_Open((kal_wchar*) med_v_context_p->current_file_name, FS_READ_ONLY)) < 0)
    {
        FS_Close(file_handle);
        FS_Rename(med_v_context_p->storing_path, med_v_context_p->current_file_name);
        attribute = FS_GetAttributes(med_v_context_p->current_file_name);
        attribute &= (~FS_ATTR_HIDDEN);
        FS_SetAttributes(med_v_context_p->current_file_name, (kal_uint8)attribute);
        result = MED_RES_OK;
    }
    else
    {
        FS_Close(file_handle);           
        result = MED_RES_OPEN_FILE_FAIL;
    }

edt_merge_error:
    /* clean all temp files */
    vis_clean_temp_files();
    /* send file merge confirm message to media task */
    vis_send_file_merge_cnf(result);


}
#endif /* defined(__MED_VID_EDT_MOD__) */
#endif /* __MED_VID_MOD__ */ 







#if defined(__MED_MJPG_MOD__)
/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Global Variables
 *****************************************************************************/
static jpeg_decode_process_struct jpg_decode;


/***************************************************************************** 
 * Local Functions
 *****************************************************************************/
void vis_display_video_frame(void *arg);





/*****************************************************************************
 * FUNCTION
 *  vis_stop_req_hdlr
 * DESCRIPTION
 *  THandle visual stop request
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    med_v_stop_timer(VIS_MJPG_DECODE_TIMER);

    VIS_ENTER_STATE(VISUAL_IDLE);
    vis_send_stop_cnf(MED_V_RES_OK);
}



/*****************************************************************************
 * FUNCTION
 *  vis_play_req_hdlr
 * DESCRIPTION
 *  Handle visual play request
 * PARAMETERS
 *  ilm_ptr     [IN]     message data 
 * RETURNS
 *  void
 *****************************************************************************/
void vis_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_visual_play_req_struct*) ilm_ptr->local_para_ptr;

    VIS_ENTER_STATE(VISUAL_PLAY);
    vis_send_play_cnf(MED_V_RES_OK, 0);
    vis_display_video_frame(NULL);
}



/* DEBUG/PROFILING use */
//#define VIS_MJPG_SLA_LOGGOING
#ifdef VIS_MJPG_SLA_LOGGOING
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction); 
#endif 
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

/*****************************************************************************
 * FUNCTION
 *  vis_display_video_frame
 * DESCRIPTION
 *  Display one jpeg frame of MJPEG
 * PARAMETERS
 *  arg     [IN]     not used
 * RETURNS
 *  void
 *****************************************************************************/
void vis_display_video_frame(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 dec_ret;
    kal_int32 result;
    kal_bool is_skip_frame = KAL_FALSE;
    kal_bool is_drop_frame = KAL_FALSE;
    kal_uint32 cur_tick;
    kal_uint64 accurate_disp_tick;
    kal_int32 tick_diff;
    kal_int64 calibration_time;
    kal_int32 timer_duration;
    kal_int32 skip_frame_count = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!VIS_IN_STATE(VISUAL_PLAY))
    {
        return;
    }

#ifdef VIS_MJPG_SLA_LOGGOING
    SLA_CustomLogging("VIS_DISPLAY", 1); /* 1 start */
#endif 

    if (((vid_context_p->play_speed > 0) &&
         (vid_context_p->time_played > vid_context_p->total_time)) ||
        ((vid_context_p->play_speed < 0) && (vid_context_p->time_played < 0)))
    {
        vis_send_play_finish_ind(MED_V_RES_OK);
        VIS_ENTER_STATE(VISUAL_IDLE);                
        return;
    }

    result = MED_RES_OK;

    kal_get_time(&cur_tick);

    /* debug info */
    vid_context_p->debug_total_frame++;
    
    if (cur_tick < vid_context_p->start_tick)
    {
        kal_prompt_trace(MOD_MED_V, "[VIS_MSG] Tick wrap around");
        
        kal_prompt_trace(
            MOD_MED_V, 
            "[VIS_MSG] TICK. Start:%d, Cur:%d, Frame:%d", 
            vid_context_p->start_tick, 
            cur_tick, 
            vid_context_p->current_frame_num);
    
        vid_context_p->start_tick = cur_tick;
        vid_context_p->current_frame_num = 0;

        vid_context_p->accurate_time_played += vid_context_p->accurate_period;
        vid_context_p->time_played = (vid_context_p->accurate_time_played >> VID_MJPG_ACCURATE_TIME_SHIFT);

        if (vid_context_p->time_played > vid_context_p->total_time)
        {
            vid_context_p->time_played = vid_context_p->total_time;
        }
        
        med_v_start_timer(VIS_MJPG_DECODE_TIMER, vid_context_p->period_fraction, vis_display_video_frame, 0);
    }
    else
    {
        accurate_disp_tick 
            = (kal_uint64)vid_context_p->start_tick + 
              ((kal_uint64)vid_context_p->current_frame_num * 
               (kal_uint64)100000000 * /* 1000 * 1000 * 100 */
               (kal_uint64)vid_context_p->avi_scale / 
               (kal_uint64)vid_context_p->avi_rate / 
               (kal_uint64)4615 /
               (kal_uint64)vid_context_p->play_speed);

        /* 
            [cal tick time per frame]
            tick_per_frame_period = 1000;
            tick_per_frame_period *= avi_data.vid_scale;        
            tick_per_frame_period /= avi_data.vid_rate;

            [convert to tick]
            tick_per_frame_period *= 1000; 
            tick_per_frame_period /= 4615;

            [adjust speed]
            tick_per_frame_period *= 100;
            tick_per_frame_period /= vid_context_p->play_speed;
        */

        tick_diff = cur_tick - accurate_disp_tick;
        
        kal_prompt_trace(
            MOD_MED_V, 
            "[VIS_MSG] TICK. Start:%d, Cur:%d, Acc:%d", 
            vid_context_p->start_tick, 
            cur_tick, 
            accurate_disp_tick);

        kal_prompt_trace(
            MOD_MED_V, 
            "[VIS_MSG] Frame:%d", 
            vid_context_p->current_frame_num);

        /* time_played is in ms */            
        vid_context_p->accurate_time_played += vid_context_p->accurate_period; 
        vid_context_p->time_played = (vid_context_p->accurate_time_played >> VID_MJPG_ACCURATE_TIME_SHIFT);
        
        if (vid_context_p->time_played > vid_context_p->total_time)
        {
            vid_context_p->time_played = vid_context_p->total_time;
        }
        
        if (tick_diff < 0)
        {
            /* timeout come too fast - need delay next timer */
            calibration_time = kal_ticks_to_milli_secs((kal_uint32)(-tick_diff));
            timer_duration = vid_context_p->period_fraction + calibration_time;

            /* drop frame, fps need smaller than max */
            vid_context_p->drop_accumulator += vid_context_p->drop_value;
            if (vid_context_p->drop_accumulator > 1000)
            {
                kal_prompt_trace(MOD_MED_V, "[VIS_MSG] drop frame: A");                                
                vid_context_p->drop_accumulator -= 1000;
                is_drop_frame = KAL_TRUE;                
            }            
        }
        else
        {
            /* timeout come too late - need accelerate next timer */
            calibration_time = kal_ticks_to_milli_secs((kal_uint32)tick_diff);

            if (vid_context_p->period_fraction > calibration_time)
            {
                timer_duration = vid_context_p->period_fraction - calibration_time;
                
                /* drop frame, fps need smaller than max */
                vid_context_p->drop_accumulator += vid_context_p->drop_value;
                if (vid_context_p->drop_accumulator > 1000)
                {
                    kal_prompt_trace(MOD_MED_V, "[VIS_MSG] drop frame: B");                
                    vid_context_p->drop_accumulator -= 1000;
                    is_drop_frame = KAL_TRUE;                
                }    
            }
            else
            {
                skip_frame_count = calibration_time / vid_context_p->period_fraction;
                is_skip_frame = KAL_TRUE;
                
                ASSERT(skip_frame_count > 0);
                
                timer_duration = ((skip_frame_count+1) * vid_context_p->period_fraction) - calibration_time;
                kal_prompt_trace(MOD_MED_V, "[VIS_MSG] skipframe:%d", skip_frame_count);                
            }
        }
        
        kal_prompt_trace(MOD_MED_V, "[VIS_MSG] calibration:%d", calibration_time);
        kal_prompt_trace(MOD_MED_V, "[VIS_MSG] Timer:%d", timer_duration);
        med_v_start_timer(VIS_MJPG_DECODE_TIMER, timer_duration, vis_display_video_frame, 0);
    }

    if (is_skip_frame)
    {
        while (skip_frame_count)
        {
        #ifdef VIS_MJPG_SLA_LOGGOING            
            SLA_CustomLogging("SKIP_FRAME", 1); /* 1 start */            
        #endif 
        
            result = med_avi_skip_video_frame();

        #ifdef VIS_MJPG_SLA_LOGGOING
            SLA_CustomLogging("SKIP_FRAME", 0); /* 0 stop */                        
        #endif
        
            vid_context_p->current_frame_num++;

            /* time_played is in ms */   
            vid_context_p->accurate_time_played += vid_context_p->accurate_period; 
            vid_context_p->time_played = (vid_context_p->accurate_time_played >> VID_MJPG_ACCURATE_TIME_SHIFT);

            if (vid_context_p->time_played > vid_context_p->total_time)
            {
                vid_context_p->time_played = vid_context_p->total_time;
            }
            
            if (result == MED_RES_VIDEO_END)
            {
                break;
            }

            vid_context_p->debug_skip_frame++;
            skip_frame_count--;
        }    

    #ifdef VIS_MJPG_SLA_LOGGOING
        SLA_CustomLogging("READ_FRAME", 1); /* 1 start */   
    #endif 
    
        result = med_avi_read_video_frame_move_next(
                    (kal_char*) vid_context_p->file_buffer_address, 
                    &vid_context_p->file_size);

    #ifdef VIS_MJPG_SLA_LOGGOING
        SLA_CustomLogging("READ_FRAME", 0); /* 0 stop */   
    #endif

        
        vid_context_p->current_frame_num++;            
    }
    else if (is_drop_frame)
    {
    #ifdef VIS_MJPG_SLA_LOGGOING        
        SLA_CustomLogging("SKIP_FRAME", 1); /* 1 start */            
    #endif
    
        result = med_avi_skip_video_frame();

    #ifdef VIS_MJPG_SLA_LOGGOING
        SLA_CustomLogging("SKIP_FRAME", 0); /* 0 stop */             
    #endif 
    
        vid_context_p->current_frame_num++;  
        vid_context_p->debug_drop_frame++;            
    }
    else
    {
    #ifdef VIS_MJPG_SLA_LOGGOING        
        SLA_CustomLogging("READ_FRAME", 1); /* 1 start */           
    #endif 
    
        result = med_avi_read_video_frame_move_next(
                    (kal_char*) vid_context_p->file_buffer_address, 
                    &vid_context_p->file_size);
    
    #ifdef VIS_MJPG_SLA_LOGGOING
        SLA_CustomLogging("READ_FRAME", 0); /* 0 stop */  
    #endif    
        
        vid_context_p->current_frame_num++;        
    }

#ifdef VIS_MJPG_SLA_LOGGOING
    SLA_CustomLogging("VIS_DISPLAY", 0); /* 0 stop */
#endif
    
    if (result == MED_RES_VIDEO_END)
    {
        med_v_stop_timer(VIS_MJPG_DECODE_TIMER);
        VIS_ENTER_STATE(VISUAL_IDLE);                
        vis_send_play_finish_ind(MED_V_RES_OK);
        return;
    }
    else if (result == MED_RES_OK)
    {
        /* do nothing */
    }
    else
    {
        /* error handling */
        med_v_stop_timer(VIS_MJPG_DECODE_TIMER);        
        stop_jpeg_video_play();
        VIS_ENTER_STATE(VISUAL_IDLE);        
        vis_send_play_finish_ind(MED_V_RES_ERROR);
        return;
    }

    if (is_drop_frame || is_skip_frame)
    {
        return;
    }

    /* display to LCM only if image path is opened */
    if (vid_context_p->image_path_open)
    {
        /* set new frame for display */
        jpg_decode.jpeg_file_handle = 0;
        jpg_decode.jpeg_file_buffer_address = vid_context_p->file_buffer_address;
        jpg_decode.jpeg_file_size = vid_context_p->file_size;
        jpg_decode.jpeg_file_buffer_size = vid_context_p->file_size;
        jpg_decode.intmem_start_address = vid_context_p->intmem_start_address;
        jpg_decode.intmem_size = vid_context_p->intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
        jpg_decode.extmem_start_address = vid_context_p->extmem_start_address;
        jpg_decode.extmem_size = vid_context_p->extmem_size = MAX_IMG_DEC_EXT_MEM_SIZE;
        jpg_decode.image_buffer_address = (kal_uint32)vid_context_p->image_buffer_address;
        jpg_decode.image_buffer_size = vid_context_p->image_buffer_size;
        jpg_decode.image_width = vid_context_p->display_width;
        jpg_decode.image_height = vid_context_p->display_height;
        jpg_decode.jpeg_decode_cb = NULL;

        /* Display current frame to LCD */
    #ifdef VIS_MJPG_SLA_LOGGOING        
        SLA_CustomLogging("JPG_PLAY", 1); /* 1 start */
    #endif

        #if defined(__SW_JPEG_CODEC_SUPPORT__)
        {
            kal_uint32 stack_begin;
            
            med_get_med_int_stack_mem(&stack_begin);

        #if defined(__MTK_TARGET__)
            /* switch stack only avaialbe on target */
            dec_ret = (kal_uint8)INT_SwitchStackToRun(
                            (void*)stack_begin,
                            MED_INT_STACK_MEM_SIZE,
                            (kal_func_ptr)jpeg_video_play, 
                            2,          /* 2 arg */
                            &jpg_decode,
                            KAL_TRUE);
        #else /* __MTK_TARGET__ */
            dec_ret = jpeg_video_play(&jpg_decode, KAL_TRUE);
        #endif /* __MTK_TARGET__ */

            med_free_med_int_stack_mem();
        }
        #else /* __SW_JPEG_CODEC_SUPPORT__ */
            dec_ret = jpeg_video_play(
                        &jpg_decode,
                        (kal_uint16*)vid_context_p->image_buffer_address,
                        vid_context_p->display_width,
                        KAL_TRUE);
        #endif /* __SW_JPEG_CODEC_SUPPORT__ */
       
        
    #ifdef VIS_MJPG_SLA_LOGGOING
        SLA_CustomLogging("JPG_PLAY", 0); /* 0 stop */
    #endif

        /* overflow is hw bug, sometimes it will decode failed which we shall ignore */
        if (dec_ret != JPEG_DECODE_SUCCESS && dec_ret != JPEG_DECODE_DECODER_OVERFLOW_FAIL)
        {
            med_v_stop_timer(VIS_MJPG_DECODE_TIMER);
            VIS_ENTER_STATE(VISUAL_IDLE);                
            vis_send_play_finish_ind(MED_V_RES_OK);
            return;            
        }
       
    }
}

#if defined(__MED_MJPG_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vis_record_req_hdlr
 * DESCRIPTION
 *  Handle visual record request
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void vis_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_visual_record_req_struct*) ilm_ptr->local_para_ptr;

    VIS_ENTER_STATE(VISUAL_RECORD);

    vis_send_record_cnf(MED_V_RES_OK);

}

/*****************************************************************************
 * FUNCTION
 *  vis_encode_visual_data_ind_hdlr
 * DESCRIPTION
 *  Handle visual encode data indication
 * PARAMETERS
 *  ilm_ptr     [IN]     message data 
 * RETURNS
 *  void
 *****************************************************************************/
void vis_encode_visual_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_encode_visual_data_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_v_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VIS_IN_STATE(VISUAL_RECORD))
    {
        ind_p = (media_encode_visual_data_ind_struct*) ilm_ptr->local_para_ptr;
        switch (ind_p->event)
        {
            case MED_AVI_SAVE_TYPE_DATA:
                if (med_avi_dump_data_buffer_to_file() != MED_RES_OK)
                {
                    VIS_ENTER_STATE(VISUAL_IDLE);
                    vis_send_record_finish_ind(MED_RES_FAIL);
                }
                break;
            case MED_AVI_SAVE_TYPE_IDX:
                if (med_avi_dump_idx_buffer_to_file() != MED_RES_OK)
                {
                    VIS_ENTER_STATE(VISUAL_IDLE);
                    vis_send_record_finish_ind(MED_RES_FAIL);
                }
                break;
            case MED_AVI_SAVE_TYPE_TERMINATE:
                /* dumped remianed data, then file will be closed */
                if (med_avi_toggle_data_buffer() == MED_RES_OK)
                {
                    med_avi_dump_data_buffer_to_file();                                    
                }

                if (med_avi_toggle_idx_buffer() == MED_RES_OK)
                {
                    med_avi_dump_idx_buffer_to_file();
                }
                break;
            default:
                ASSERT(0);
                break;
        }
    }
}

#endif /* defined(__MED_MJPG_ENC_MOD__) */
#endif /* defined(__MED_MJPG_MOD__) */ 

#endif /* MED_V_NOT_PRESENT */ 


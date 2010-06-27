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
 *   vid_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of video module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

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
#include "fat_fs.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "vid_main.h"
#include "aud_main.h"

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MED_MJPG_MOD__)
#include "vid_avi.h"
#endif

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)

vid_context_struct *vid_context_p = &(med_context.vid_context);

#define DUMMY_VIDEO_FILE_CONTENT L"d:\\video\\dummy.3gp\0\0\0\0\0\0\0\0\0\0\0\0"



#if defined(__MED_VID_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_create_dummy_video_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_create_dummy_video_file(void)
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
#ifdef __NVRAM_IN_USB_MS__
    if (stack_query_boot_mode() == USBMS_BOOT)
    {
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    /* creat folder */
    fd = FS_Open((kal_uint16*)VID_SYSTEM_FOLDER, FS_OPEN_DIR | FS_READ_ONLY);

    if (fd  >= 0)
    {
        /* path already exist */        
        FS_Close(fd);
    }
    else
    {
        /* file not exist */
        fd = FS_CreateDir((kal_uint16*)VID_SYSTEM_FOLDER);
    }

    if ((fd = FS_Open((kal_wchar*) VID_DUMMY_INIT_FILE, FS_READ_ONLY)) >= 0)
    {
        FS_Close(fd);
        return;
    }
    else if ((fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_READ_ONLY)) >= 0)
    {
        FS_Close(fd);
        /* FS_Rename((kal_wchar*)VID_INIT_FILE, (kal_wchar*)VID_DUMMY_INIT_FILE); */
        return;
    }
    fd = FS_Open((kal_wchar*) VID_DUMMY_INIT_FILE, FS_CREATE | FS_READ_WRITE);
    if (fd >= 0)
    {
        result = FS_Write(fd, DUMMY_VIDEO_FILE_CONTENT, kal_wstrlen(DUMMY_VIDEO_FILE_CONTENT) * ENCODE_BYTE, &len);
        FS_Close(fd);
    }

}

#endif /* defined(__MED_VID_MOD__) */ 


/*****************************************************************************
 * FUNCTION
 *  vid_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of video module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;
#if defined(__MED_VID_MOD__)
    vid_create_dummy_video_file();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  vid_main
 * DESCRIPTION
 *  This function is main message dispatching function of video module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
    #if defined(__MED_VID_MOD__)
        case MSG_ID_MEDIA_VID_STOP_REQ:
            vid_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_OPEN_REQ:
            vid_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CLOSE_REQ:
            vid_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PLAY_REQ:
            vid_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SEEK_REQ:
            vid_seek_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SET_STOP_TIME:
            vid_set_stop_time_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_GET_IFRAME_REQ:
            vid_get_iframe_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SET_DISPLAY_REQ:
            vid_set_display_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SET_PARAM_REQ:
            vid_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_PLAY_CNF:
            vid_visual_play_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_SEEK_CNF:
            vid_visual_seek_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_PLAY_FINISH_IND:
            vid_visual_play_finish_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_DECODE_EVENT_IND:
            vid_decode_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_ERROR_RECOVER_IND:
            vid_error_recover_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_AUDIO_PLAY_FINISH_IND:
            vid_audio_play_finish_ind_hdlr(ilm_ptr);
            break;
        /* from MED_V */            
        case MSG_ID_MEDIA_VISUAL_STOP_CNF:
            vid_visual_stop_cnf_hdlr(ilm_ptr);
            break;       

    #if defined(__MED_VID_ENC_MOD__)
        case MSG_ID_MEDIA_VID_PREVIEW_REQ:
            vid_preview_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_RECORD_REQ:
            vid_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PAUSE_REQ:
            vid_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_RESUME_REQ:
            vid_resume_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_FILE_MERGE_REQ:
            vid_file_merge_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_UPDATE_BLT_PAUSE_REQ:
            vid_update_blt_pause_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_UPDATE_BLT_RESUME_REQ:
            vid_update_blt_resume_req_hdlr(ilm_ptr);
            break;             
        case MSG_ID_MEDIA_VID_SET_OVERLAY_PALETTE_REQ:
            vid_set_overlay_palette_req_hdlr(ilm_ptr);
            break;            

        /* from MED_V */
        case MSG_ID_MEDIA_VISUAL_RECORD_CNF:
            vid_visual_record_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_RECORD_FINISH_IND:
            vid_visual_record_finish_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_FILE_MERGE_CNF:
            vid_visual_file_merge_cnf_hdlr(ilm_ptr);
            break;            
    #endif /* defined(__MED_VID_ENC_MOD__) */
    
    #if defined(__MED_VID_EDT_MOD__)
        case MSG_ID_MEDIA_VID_EDT_SET_ACTIVE_REQ:
            vid_edt_set_active_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_EDT_ENC_OPEN_REQ:
            vid_edt_enc_open_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_EDT_ENC_CLOSE_REQ:
            vid_edt_enc_close_req_hdlr(ilm_ptr);
            break;        
        case MSG_ID_MEDIA_VID_EDT_ENC_APPEND_REQ:
            vid_edt_enc_append_req_hdlr(ilm_ptr);
            break;        
        case MSG_ID_MEDIA_VID_EDT_ENC_MERGE_REQ:
            vid_edt_enc_merge_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_EDT_ENC_STOP_MERGE_REQ:
            vid_edt_enc_stop_merge_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_EDT_OPEN_BGM_REQ:
            vid_edt_open_bgm_req_hdlr(ilm_ptr);
            break;                    
        case MSG_ID_MEDIA_VID_EDT_CLOSE_BGM_REQ:
            vid_edt_close_bgm_req_hdlr(ilm_ptr);
            break;     
        case MSG_ID_MEDIA_VID_EDT_OPEN_SILENCE_REQ:
            vid_edt_open_silence_req_hdlr(ilm_ptr);
            break;                    
        case MSG_ID_MEDIA_VID_EDT_CLOSE_SILENCE_REQ:
            vid_edt_close_silence_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_EDT_ENCODE_EVENT_IND:
            vid_edt_encode_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_EDT_INIT_REQ:
            vid_edt_init_req_hdlr(ilm_ptr);
            break;
    #endif /* defined(__MED_VID_EDT_MOD__) */

    #if defined(__MED_VID_PDL_MOD__)
        case MSG_ID_MEDIA_VID_GET_PDL_PRECENT_REQ:
            vid_get_pdl_precent_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_PDL_MAX_TIME_REQ: 
            vid_get_pdl_max_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CHECK_IS_PDL_REQ:
            vid_check_is_pdl_req_hdlr(ilm_ptr);
            break;            
    #endif /* defined(__MED_VID_PDL_MOD__) */
    
        case MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_CNF:
            aud_media_record_low_stop_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_CNF:
            aud_media_record_low_pause_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_CNF:
            aud_media_record_low_resume_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_RECORD_ERROR_IND:
            aud_media_record_low_error_ind_hdlr(ilm_ptr);
            break;
    #endif /* __MED_VID_MOD__ */ 

    
    #if defined(__MED_MJPG_MOD__)
        case MSG_ID_MEDIA_VID_STOP_REQ:
            vid_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_OPEN_REQ:
            vid_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CLOSE_REQ:
            vid_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PLAY_REQ:
            vid_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SEEK_REQ:
            vid_seek_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SET_STOP_TIME:
            vid_set_stop_time_req_hdlr(ilm_ptr);
            break;                
        case MSG_ID_MEDIA_VID_GET_IFRAME_REQ:
            vid_get_iframe_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SET_DISPLAY_REQ:
            vid_set_display_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SET_PARAM_REQ:
            vid_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_DECODE_EVENT_IND:
            vid_decode_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_AUDIO_PLAY_FINISH_IND:
            vid_audio_play_finish_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_STOP_CNF:
            vid_visual_stop_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_PLAY_FINISH_IND:
            vid_visual_play_finish_ind_hdlr(ilm_ptr);
            break;            
    #if defined(__MED_MJPG_ENC_MOD__)
        case MSG_ID_MEDIA_VID_PREVIEW_REQ:
            vid_preview_req_hdlr(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_VID_RECORD_REQ:
            vid_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_FILE_MERGE_REQ:
            vid_file_merge_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PAUSE_REQ:
            vid_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_RESUME_REQ:
            vid_resume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_UPDATE_BLT_PAUSE_REQ:
            vid_update_blt_pause_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_UPDATE_BLT_RESUME_REQ:
            vid_update_blt_resume_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_MJPEG_ENCODE_IND:
            vid_mjpeg_encode_event_ind_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VISUAL_RECORD_CNF:
            vid_visual_record_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_RECORD_FINISH_IND:
            vid_visual_record_finish_ind_hdlr(ilm_ptr);
            break;            
    #endif /* defined(__MED_MJPG_ENC_MOD__) */

        case MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_CNF:
            aud_media_record_low_stop_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_CNF:
            aud_media_record_low_pause_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_CNF:
            aud_media_record_low_resume_cnf_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_V_AUDIO_RECORD_ERROR_IND:
            aud_media_record_low_error_ind_hdlr(ilm_ptr);
            break;
    
    #endif /* defined(__MED_MJPG_MOD__) */ 

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_init
 * DESCRIPTION
 *  This function is used to init video module of media task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool vid_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->state = VID_IDLE;
    vid_context_p->aud_state = VID_AUD_IDLE;
    vid_context_p->vid_event = kal_create_event_group("vid_events");
    vid_context_p->vid_event_ext = kal_create_event_group("vid_events_ext");
    vid_context_p->image_path_open = KAL_FALSE;
    vid_context_p->em_mode = VID_EM_MODE_DISABLED;
#ifdef __MED_VID_MOD__
    vid_context_p->audio_frame_num = 0;
    vid_context_p->total_frame_num = 0;
    vid_context_p->current_time = 0;
    vid_context_p->total_time = 0;
    vid_context_p->display_width = 0;
    vid_context_p->display_height = 0;
    vid_context_p->image_width = 0;
    vid_context_p->image_height = 0;
    vid_context_p->file_size = 0;
    vid_context_p->storing_path[0] = 0;
    vid_context_p->handle = NULL;
    vid_context_p->data_idx = -1;
    vid_context_p->play_speed = 100;
 
    vid_context_p->vid_get_time_mutex = kal_create_mutex("VID_GET_TIME");
    
#endif /* __MED_VID_MOD__ */ 
#if defined(__MED_MJPG_MOD__)
    vid_context_p->total_frame_num = 0;
    vid_context_p->current_time = 0;
    vid_context_p->total_time = 0;
    vid_context_p->display_width = 0;
    vid_context_p->display_height = 0;
    vid_context_p->image_width = 0;
    vid_context_p->image_height = 0;
    vid_context_p->file_size = 0;
    vid_context_p->storing_path[0] = 0;
    
    vid_context_p->mjpeg_mutex = kal_create_mutex("VID_MJPEG");
    vid_context_p->mjpeg_insert_frame_count = 1;
    vid_context_p->mjpeg_is_jpg_encoding = KAL_FALSE;

    /* init avi kernel */
    med_avi_init();
#endif /* defined(__MED_MJPG_MOD__) */

#ifdef __MED_VID_EDT_MOD__
    vid_context_p->edt_video_buff_p = NULL;
#endif /*__MED_VID_EDT_MOD__*/

    return KAL_TRUE;
}
 
#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 
#endif /* MED_NOT_PRESENT */ 


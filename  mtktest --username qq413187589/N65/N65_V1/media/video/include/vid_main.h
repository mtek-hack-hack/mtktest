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
 * vid_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global functions/variables of video module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#define MED_HIDE_VIDEO_TEMP_FILE
#ifdef MED_HIDE_VIDEO_TEMP_FILE
#define VID_TEMP_FILE_ATTRIBUTES FS_READ_WRITE|FS_CREATE_ALWAYS|FS_ATTR_HIDDEN
#else 
#define VID_TEMP_FILE_ATTRIBUTES FS_READ_WRITE|FS_CREATE_ALWAYS
#endif 

#if defined(__MED_VID_MOD__)

#ifndef _VID_MAIN_H
#define _VID_MAIN_H

typedef enum
{
    VID_EVT_NOWAIT      = 0x00000000,
    VID_EVT_RECORD      = 0x00000001,
    VID_EVT_STOP        = 0x00000002,
    VID_EVT_OPEN_FILE   = 0x00000004,
    VID_EVT_CLOSE_FILE  = 0x00000008,
    VID_EVT_PLAY        = 0x00000010,
    VID_EVT_SEEK        = 0x00000020,
    VID_EVT_PAUSE       = 0x00000040,
    VID_EVT_RESUME      = 0x00000080,
    VID_EVT_SNAPSHOT    = 0x00000100,
    VID_EVT_GET_IFRAME  = 0x00000200,
    VID_EVT_GET_INFO    = 0x00000400,
    VID_EVT_FILE_MERGE  = 0x00000800,
    VID_EVT_OPEN        = 0x00001000,
    VID_EVT_CLOSE       = 0x00002000,
    VID_EVT_PREVIEW     = 0x00004000,
    VID_EVT_BLOCK       = 0x00008000       /* general use */
}
vid_wait_event_enum;

#define VID_WAIT_EVENT(evt_)        \
do{                                 \
    kal_uint32 retrieved_events;    \
    VID_WAIT_EVT(evt_, __LINE__);   \
    kal_retrieve_eg_events(         \
        vid_context_p->vid_event,   \
        (evt_),                     \
        KAL_OR_CONSUME,             \
        &retrieved_events,          \
        KAL_SUSPEND);               \
} while(0)

#define VID_SET_EVENT(evt_)                                     \
do{                                                             \
    kal_set_eg_events(vid_context_p->vid_event, (evt_),KAL_OR); \
    VID_SET_EVT(evt_,__LINE__);                                 \
} while(0)

#define VID_HAS_TRACK(track_) ((vid_context_p->video_track&track_)!=0)

#define VID_SYSTEM_FOLDER           (L"z:\\@Video")
#define VID_INIT_FILE               (L"z:\\@Video\\video_file.ini")
#define VID_DUMMY_INIT_FILE         (L"z:\\@Video\\video_dummy_file.ini")
#define VID_AUDIO_FILE              (L"~audio.tmp")
#define VID_AUDIO_SAMPLE_FILE       (L"~audio_sample.tmp")
#define VID_AUDIO_REAL_META_FILE    (L"~audio_real_meta.tmp")
#define VID_VISUAL_FILE             (L"~visual.tmp")
#define VID_VISUAL_META_FILE        (L"~visual_meta.tmp")
#define VID_VISUAL_REAL_META_FILE   (L"~visual_real_meta.tmp")

#define VID_PDL_BUFFER_TIME_FOR_PLAY    (1000*6)    /* cache 6 sec for buffering */

/*==== PROTOTYPE ===========*/
/* main */
extern void vid_startup_hdlr(ilm_struct *ilm_ptr);
extern void vid_main(ilm_struct *ilm_ptr);
extern kal_bool vid_init(void);

/* msg handler */
extern void vid_release_memory(void);
extern void vid_update_frame_to_buffer(void);
extern kal_uint32 vid_evaluate_residual_size(kal_uint32 video_size);
extern kal_uint32 vid_evaluate_audio_real_meta_file_size(kal_uint64 audio_record_time);
extern kal_uint32 vid_evaluate_audio_meta_file_size(kal_uint64 audio_record_time);
extern kal_uint32 vid_file_visual_residual_size(void);
extern kal_uint32 vid_file_audio_residual_size(void);
extern kal_uint32 vid_file_meta_residual_size(void);
extern kal_uint32 vid_get_current_file_size(void);
extern kal_uint16 vid_get_disc_free_space(kal_wchar *dir_name, kal_uint64 *free);
extern kal_int32 vid_get_result_from_media_status(MEDIA_STATUS_CODE status);
extern void vid_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_record_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_file_merge_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_open_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_close_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_play_finish_hdlr(void);
extern void vid_play_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_seek_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_stop_time_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_iframe_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_display_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_update_blt_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_update_blt_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_overlay_palette_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_set_active_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_enc_open_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_enc_close_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_enc_append_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_enc_merge_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_enc_stop_merge_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_open_bgm_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_close_bgm_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_open_silence_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_close_silence_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_init_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_deinit_req_hdlr(ilm_struct *ilm_ptr);
extern kal_int32 vid_edt_get_encode_result_from_media_status(MEDIA_STATUS_CODE status, STFSAL *stfsal_p);
extern void vid_get_pdl_precent_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_pdl_max_time_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_check_is_pdl_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_record_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_stop_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_play_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_seek_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_file_merge_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_record_finish_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_play_finish_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_edt_encode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_decode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_audio_play_finish_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_error_recover_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_clean_temp_files(void);
extern kal_bool vid_check_unfinished_file(void);
extern void vid_stop_unfinished_task(void);
extern kal_bool vid_is_audio_channel_available(void);
extern kal_int16 vid_abort_by_client_switching(void);
extern kal_bool vid_is_pdl_audio_buf_underflow(void);
extern void vid_stop_visual(void);
extern void vid_stop_audio(void);
extern void vid_set_handle(kal_int32 handle);
extern kal_bool vid_is_aud_playing(void);
extern kal_int32 vid_get_aud_format(void);
extern void vid_set_vol_level(kal_uint8 vol_level);

/* MED -> MMI Indication */
extern void vid_send_record_finish_ind(kal_int16 result);
extern void vid_send_file_merge_done_ind(kal_int16 result);
extern void vid_send_file_ready_ind(kal_int16 result);
extern void vid_send_play_finish_ind(kal_int16 result);
extern void vid_send_decode_event_ind(kal_uint8 event);
extern void vid_send_seek_done_ind(kal_int16 result);
extern void vid_send_iframe_ready_ind(kal_int16 result);
extern void vid_send_audio_play_finish_ind(kal_int16 result);
extern void vid_send_edt_encode_merge_done_ind(kal_int16 result);

extern void vid_send_set_overlay_palette_req(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr);

/* HISR -> MED */
extern void vid_send_decode_event_ind(kal_uint8 event);
extern void vid_edt_send_encode_event_ind(kal_uint8 event);

/* MED -> MED_V Request */
extern void vid_send_visual_record_req(void *data);
extern void vid_send_visual_stop_req(void *data);
extern void vid_send_visual_play_req(void *data);
extern void vid_send_visual_seek_req(kal_uint32 frame_num, kal_uint8 display);
extern void vid_send_visual_file_merge_req(kal_uint8 mode);

/* api */
extern void vid_set_result(kal_int32 result, kal_uint32 line);
extern void vid_set_pdl_result(kal_int32 result, kal_uint32 line);
extern void vid_set_image_size(kal_uint16 x, kal_uint16 y);
extern void vid_set_total_time(kal_uint64 total_time, kal_uint64 video_total_time, kal_uint64 audio_total_time);

/* util */
extern void vid_debug_print_cur_state(kal_uint32 line);
extern void vid_debug_print_mp4_parser_return(kal_int32 mp4_ret, kal_uint32 line);
extern void vid_debug_print_vid_drv_return(kal_int32 vid_ret, kal_uint32 line);

#endif /* _VID_MAIN_H */ 

#endif /* __MED_VID_MOD__ */ 

#if defined(__MED_MJPG_MOD__)
#ifndef _VID_MAIN_H
#define _VID_MAIN_H

#define VID_INIT_FILE              (L"z:\\video_file.ini")
#define VID_DUMMY_INIT_FILE        (L"z:\\video_dummy_file.ini")
#define VID_CLIP_LENGTH   65535 /* second */

typedef enum
{
    VID_EVT_NOWAIT = 0x0000,
    VID_EVT_RECORD = 0x0001,
    VID_EVT_STOP = 0x0002,
    VID_EVT_OPEN_FILE = 0x0004,
    VID_EVT_CLOSE_FILE = 0x0008,
    VID_EVT_PLAY = 0x0010,
    VID_EVT_SEEK = 0x0020,
    VID_EVT_PAUSE = 0x0040,
    VID_EVT_RESUME = 0x0080,
    VID_EVT_SNAPSHOT = 0x0100,
    VID_EVT_GET_IFRAME = 0x0200,
    VID_EVT_GET_INFO = 0x0400,
    VID_EVT_FILE_MERGE = 0x0800,
    VID_EVT_OPEN = 0x1000,
    VID_EVT_CLOSE = 0x2000,
    VID_EVT_PREVIEW = 0x4000,
    VID_EVT_BLOCK = 0x8000       /* general use */
}
vid_wait_event_enum;

typedef enum
{
    VID_EVT_SET_PAL = 0x0001
}
vid_wait_event_ext_enum;

#define VID_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         VID_WAIT_EVT(evt_, __LINE__);                            \
         kal_retrieve_eg_events(vid_context_p->vid_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define VID_SET_EVENT(evt_) do{                                                          \
                              kal_set_eg_events(vid_context_p->vid_event, (evt_),KAL_OR);\
                              VID_SET_EVT(evt_,__LINE__);                                \
                              } while(0)

/*==== PROTOTYPE ===========*/
/* main */
extern void vid_startup_hdlr(ilm_struct *ilm_ptr);
extern void vid_main(ilm_struct *ilm_ptr);
extern kal_bool vid_init(void);

/* msg handler */
extern kal_uint32 vid_get_current_file_size(void);
extern kal_uint16 vid_get_disc_free_space(kal_wchar *dir_name, kal_uint64 *free);
extern kal_int32 vid_start_video_record(void);
extern void vid_stop_video_record(void);
extern kal_int32 vid_pause_video_record(void);
extern kal_int32 vid_resume_video_record(void);

extern void vid_preview_check(void *arg);
extern void vid_preview_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_record_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_file_merge_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_open_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_close_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_play_finish_hdlr(void);
extern void vid_play_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_seek_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_stop_time_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_get_iframe_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_display_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_update_blt_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_update_blt_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void vid_decode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_record_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_stop_cnf_hdlr(ilm_struct *ilm_ptr);
extern void vid_visual_record_finish_ind_hdlr(ilm_struct *ilm_ptr);

extern void vid_audio_play_finish_ind_hdlr(ilm_struct *ilm_ptr);
extern kal_int32 vid_write_audio(void);
extern kal_int32 vid_record_audio(void);
extern void vid_stop_audio_record(void);
extern void vid_stop_audio_play(void);
extern kal_bool vid_is_aud_playing(void);
extern kal_int32 vid_get_aud_format(void);

extern void vid_stop_unfinished_task(void);
extern void vid_clean_temp_files(void);
extern kal_bool vid_check_unfinished_file(void);
extern kal_bool vid_is_audio_channel_available(void);
extern kal_int16 vid_abort_by_client_switching(void);
extern void vid_set_vol_level(kal_uint8 vol_level);

/* ilm */
extern void vid_send_preview_req(module_type src_mod_id, void *data);
extern void vid_send_record_req(module_type src_mod_id, void *data);
extern void vid_send_stop_req(module_type src_mod_id);
extern void vid_send_file_merge_req(module_type src_mod_id, void *data);
extern void vid_send_open_req(module_type src_mod_id, void *data);
extern void vid_send_close_req(module_type src_mod_id);
extern void vid_send_play_req(module_type src_mod_id, void *data);
extern void vid_send_seek_req(module_type src_mod_id, void *data);
extern void vid_send_pause_req(module_type src_mod_id);
extern void vid_send_resume_req(module_type src_mod_id);
extern void vid_send_snapshot_req(module_type src_mod_id, void *data);
extern void vid_send_get_iframe_req(module_type src_mod_id, void *data);
extern void vid_send_record_finish_ind(kal_int16 result);
extern void vid_send_file_merge_done_ind(kal_int16 result);
extern void vid_send_file_ready_ind(kal_int16 result);
extern void vid_send_play_finish_ind(kal_int16 result);
extern void vid_send_decode_event_ind(kal_uint8 event);
extern void vid_send_seek_done_ind(kal_int16 result);
extern void vid_send_iframe_ready_ind(kal_int16 result);
extern void vid_send_set_display_req(module_type src_mod_id, kal_uint8 device);
extern void vid_send_set_param_req(module_type src_mod_id, void *data);
extern void vid_send_audio_play_finish_ind(kal_int16 result);
extern void vid_send_set_overlay_palette_req(module_type src_mod_id, kal_uint8 palette_size, kal_uint32 *palette_addr);

extern void vid_mjpeg_encode_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void vid_send_mjpeg_encode_ind(kal_uint8 return_code);

/* MED -> Media-v */
extern void vid_send_visual_record_req(void *data);
extern void vid_send_visual_stop_req(void *data);
extern void vid_send_visual_play_req(void *data);
extern void vid_send_encode_visual_data_ind(kal_uint8 event);

/* api */
extern void vid_set_result(kal_int32 result, kal_uint32 line);
extern void vid_set_image_size(kal_uint16 x, kal_uint16 y);
extern void vid_set_total_time(kal_uint64 total_time, kal_uint64 video_total_time, kal_uint64 audio_total_time);


/* util */
extern void vid_debug_print_cur_state(kal_uint32 line);

#endif /* _VID_MAIN_H */ 

#endif /* defined(__MED_MJPG_MOD__) */ 

#ifdef __SF_MP4_SUPPORT__
void vid_sf_send_file_ready_ind(media_vid_file_ready_ind_struct *file_info);
void vid_sf_send_play_finish_ind(media_vid_play_finish_ind_struct* finish_info);
void vid_sf_send_seek_done_ind(media_vid_seek_done_ind_struct* seek_info);
#endif //__SF_MP4_SUPPORT__

#endif /* MED_NOT_PRESENT */ 


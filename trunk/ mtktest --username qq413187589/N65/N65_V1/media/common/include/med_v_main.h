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
 * med_v_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes function prototypes of media v task.
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

#ifndef _MED_V_MAIN_H
#define _MED_V_MAIN_H

typedef enum
{
    MED_V_RES_OK = 0,
    MED_V_RES_FAIL,
    MED_V_RES_BUSY,
    MED_V_RES_DISC_FULL,
    MED_V_RES_OPEN_FILE_FAIL,
    MED_V_RES_END_OF_FILE,
    MED_V_RES_TERMINATED,
    MED_V_RES_BAD_FORMAT,
    MED_V_RES_INVALID_FORMAT,
    MED_V_RES_ERROR,
    MED_V_RES_NO_DISC,
    MED_V_RES_NOT_ENOUGH_SPACE,
    MED_V_RES_INVALID_HANDLE,
    MED_V_RES_NO_HANDLE,
    MED_V_RES_RESUME,
    MED_V_RES_BLOCKED,
    MED_V_RES_MEM_INSUFFICIENT,
    MED_V_RES_BUFFER_INSUFFICIENT,
    MED_V_RES_FILE_EXIST,
    MED_V_RES_WRITE_PROTECTION,
    MED_V_RES_NO_VIDEO_TRACK,
    MED_V_NO_OF_RES
}
med_v_result_enum;


#define MED_V_BASE_TIMER_ID     0x0000

typedef enum
{
    VIS_MJPG_DECODE_TIMER,

    /* insert timer before this enum */
    MAX_NUM_OF_MED_V_TIMER
}
med_v_timer_enum;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
}
med_v_timer_table_struct;


#define AUD_CACUE_WAIT_EVENT(evt_) do{                                     \
         kal_uint32 retrieved_events;                                      \
         kal_retrieve_eg_events(med_v_context_p->aud_cache_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define AUD_CACHE_SET_EVENT(evt_) do{                                  \
   kal_set_eg_events(med_v_context_p->aud_cache_event, (evt_),KAL_OR); \
   } while(0)

typedef enum
{
    AUD_CACHE_EVT_START =0x01,
    AUD_CACHE_EVT_CLOSE =0x02,
    AUD_CACHE_EVT_RESET =0x04
}
aud_cache_event_enum;


extern void med_v_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void med_v_stop_timer(kal_uint8 timer_id);


extern void vis_record_req_hdlr(ilm_struct *ilm_ptr);
extern void vis_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void vis_play_req_hdlr(ilm_struct *ilm_ptr);
extern void vis_seek_req_hdlr(ilm_struct *ilm_ptr);
extern void vis_file_merge_req_hdlr(ilm_struct *ilm_ptr);
extern void vis_encode_visual_data_ind_hdlr(ilm_struct *ilm_ptr);
extern void vis_decode_visual_data_ind_hdlr(ilm_struct *ilm_ptr);

/*audio build cache*/
extern void audio_start_build_cache(ilm_struct *ilm_ptr);
extern void audio_stop_build_cache(ilm_struct *ilm_ptr);
extern void audio_process_build_cache(ilm_struct *ilm_ptr);
extern void audio_close_build_cache(ilm_struct *ilm_ptr);
extern void audio_reset_build_cache_variables(ilm_struct *ilm_ptr);

/* audio record in low priority task */
extern void med_v_aud_record_init(void);
extern void med_v_aud_start_record_req_hdlr(ilm_struct *ilm_ptr);
extern void med_v_aud_stop_record_req_hdlr(ilm_struct *ilm_ptr_in);
extern void med_v_aud_pause_record_req_hdlr(ilm_struct *ilm_ptr);
extern void med_v_aud_resume_record_req_hdlr(ilm_struct *ilm_ptr);
extern void med_v_aud_read_data_ind_hdlr(ilm_struct *ilm_ptr);

/* ilm */
extern void vis_send_record_cnf(kal_int16 result);
extern void vis_send_stop_cnf(kal_int16 result);
extern void vis_send_play_cnf(kal_int16 result, kal_uint32 frame_num);
extern void vis_send_seek_cnf(kal_int16 result);
extern void vis_send_file_merge_cnf(kal_int16 result);
extern void vis_send_record_finish_ind(kal_int16 result);
extern void vis_send_seek_done_ind(kal_int16 result);
extern void vis_send_play_finish_ind(kal_int16 result);
extern void vis_send_decode_visual_data_ind(kal_uint8 event);
extern void vis_send_encode_visual_data_ind(kal_uint8 event);
extern void vis_send_error_recover_ind(void);
extern void vis_send_play_restart_ind(kal_uint32 audio_frame_number);

#endif /* _MED_V_MAIN_H */ 

#endif /* MED_V_NOT_PRESENT */ 


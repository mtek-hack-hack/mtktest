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
 *   VTProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Telephony Prototype
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef VT_PROT_H
#define VT_PROT_H

#include "MMI_features.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "VTCallScrProt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_VT_POPUP_TIME_OUT             (UI_POPUP_NOTIFYDURATION_TIME_2000)
#define MMI_VT_DEFAULT_EV           (MMI_VT_EV_0) 
#define MMI_VT_DEFAULT_VOLUME               (MMI_VT_VOL_3) 
#define MMI_VT_DEFAULT_ZOOM                 (MMI_VT_ZOOM_10X)
#define MMI_VT_START_CAMERA_QUERY_TIMEOUT          (2000)
#define MMI_VT_DTMF_LEN                     (40)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
 
typedef enum
{
    MMI_VT_ANSWER_MODE_PROMPT,
    MMI_VT_ANSWER_MODE_START_CAMERA,
    MMI_VT_ANSWER_MODE_STOP_CAMERA,
    MMI_VT_ANSWER_MODE_END_OF_ENUM
} mmi_vt_answer_mode_enum;

typedef enum
{
    MMI_VT_DIAL_MODE_START_CAMERA,
    MMI_VT_DIAL_MODE_STOP_CAMERA,
    MMI_VT_DIAL_MODE_END_OF_ENUM
} mmi_vt_dial_mode_enum;

typedef enum
{
    MMI_VT_AUDIO_OPTION_MIC_OFF,
    MMI_VT_AUDIO_OPTION_SPEAKER_OFF,
    MMI_VT_AUDIO_OPTION_TOTAL_NUM
} mmi_vt_audio_option_enum;

typedef enum
{
    MMI_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL,
    MMI_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL,
#ifdef MMS_SUPPORT
    MMI_VT_MO_FAIL_ACTION_SEND_MMS,
#endif /* MMS_SUPPORT */
    MMI_VT_MO_FAIL_ACTION_SEND_SMS,
    MMI_VT_MO_FAIL_ACTION_TOTAL_NUM
} mmi_vt_mo_fail_action_enum;

typedef enum
{
    MMI_VT_VIDEO_QUALITY_SMOOTH,
    MMI_VT_VIDEO_QUALITY_NORMAL,
    MMI_VT_VIDEO_QUALITY_SHARP,
    MMI_VT_VIDEO_QUALITY_END_OF_ENUM
} mmi_vt_video_quality_enum;

typedef enum
{
    MMI_VT_INCALL_SCREEN_MODE_INCALL,
    MMI_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY,
    MMI_VT_INCALL_SCREEN_MODE_SNAPSHOT, // remove!
    MMI_VT_INCALL_SCREEN_MODE_VOLUME, // remove!
    MMI_VT_INCALL_SCREEN_MODE_BRIGHTNESS, // remove!
    MMI_VT_INCALL_SCREEN_MODE_END_OF_ENUM
} mmi_vt_incall_screen_mode_enum;

typedef enum
{
    MMI_VT_INCALL_PIC_STATUS_BUILT_IN,
    MMI_VT_INCALL_PIC_STATUS_FILE,
    MMI_VT_INCALL_PIC_STATUS_END_OF_ENUM
} mmi_vt_incall_pic_status_enum;
    
typedef struct
{
    U16 curr_hilite_index;
    MMI_BOOL is_camera_on;
    MMI_BOOL is_backend_camera;
    MMI_BOOL is_mic_on;
    MMI_BOOL is_speaker_on;
    MMI_BOOL is_image_switch;
    MMI_BOOL is_small_region_hide;
    MMI_BOOL is_mirror;
    MMI_BOOL is_hand_free;
    mmi_vt_ev_enum ev;    
    mmi_vt_vol_enum volume;    
    mmi_vt_zoom_enum zoom_status;    
    mmi_vt_video_quality_enum video_quality;
    mmi_vt_incall_screen_mode_enum mode;
} mmi_vt_incall_screen_struct;

typedef struct
{
    S8 dial_pad_buffer[MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH];
} mmi_vt_dial_info_struct;

typedef struct
{
    U8  incall_image_file_path[NVRAM_EF_VT_SETTING_SIZE]; /* UCS2 with NULL terminator */
    U16 curr_hilite_index;
    mmi_vt_answer_mode_enum answer_mode;
    mmi_vt_dial_mode_enum dial_mode;
    MMI_BOOL audio_opt[MMI_VT_AUDIO_OPTION_TOTAL_NUM]; /* used for category */
    MMI_BOOL is_mic_off;
    MMI_BOOL is_speaker_off;
}mmi_vt_setting_struct;

typedef struct
{
    mmi_vt_incall_screen_struct incall_screen;
    mmi_vt_dial_info_struct mo_info;
    mmi_vt_setting_struct setting;
} mmi_vt_cntx_struct;

/***************************************************************************** 
 * Variable 
 *****************************************************************************/
 extern mmi_vt_cntx_struct *g_vt_p;

/***************************************************************************** 
 * Function 
 *****************************************************************************/
 
/* VTMain.c */
extern void mmi_vt_entry_incall_option(void);
extern void mmi_vt_dialer_make_vt(void);
extern void mmi_vt_handle_incall_option(void);
extern void mmi_vt_init_highlight_handler(void);
extern void mmi_vt_highlight_main(void);
extern void mmi_vt_highlight_incall_opt_make_video_call(void);
extern void mmi_vt_highlight_incall_opt_start_camera(void);
extern void mmi_vt_highlight_incall_opt_stop_camera(void);
extern void mmi_vt_highlight_incall_opt_mute_mic(void);
extern void mmi_vt_highlight_incall_opt_unmute_mic(void);
extern void mmi_vt_highlight_incall_opt_mute_speaker(void);
extern void mmi_vt_highlight_incall_opt_unmute_speaker(void);
extern void mmi_vt_highlight_incall_opt_switch_pic(void);
extern void mmi_vt_highlight_incall_opt_hide_small_pic(void);
extern void mmi_vt_highlight_incall_opt_unhide_small_pic(void);
extern void mmi_vt_highlight_incall_opt_alt_pic(void);
extern void mmi_vt_highlight_incall_opt_switch_audio_path(void);
extern void mmi_vt_highlight_incall_opt_advanced(void);
extern void mmi_vt_highlight_incall_opt_setting(void);
extern void mmi_vt_highlight_setting_answer_mode(void);
extern void mmi_vt_highlight_setting_dial_mode(void);
extern void mmi_vt_highlight_setting_alt_incall_pic(void);
extern void mmi_vt_highlight_setting_audio_option(void);
extern void mmi_vt_highlight_setting_incall_image_default(void);
extern void mmi_vt_highlight_setting_incall_image_user_define(void);
extern void mmi_vt_hint_setting_alt_incall_pic(U16 index);
extern void mmi_vt_highlight_advance_brightness(void);
extern void mmi_vt_highlight_advance_video_quality(void);
extern void mmi_vt_highlight_advance_record_audio(void);
extern void mmi_vt_highlight_advance_save_pic(void);
extern void mmi_vt_highlight_advance_mirror_image(void);
extern void mmi_vt_hint_advance_brightness(U16 index);
extern void mmi_vt_hint_advance_video_quality(U16 index);
extern void mmi_vt_hint_advance_mirror_image(U16 index);
extern void mmi_vt_init_setting(void);
extern void mmi_vt_dialer_make_vt(void);
extern void mmi_vt_make_video_call(S8 *strNumber);
extern void mmi_vt_ucm_act_req(U8 op_code, void *act_struct);
extern void mmi_vt_speech_ind(BOOL speech, U8 rat);
extern void mmi_vt_incall_opt_start_camera(void);
extern void mmi_vt_incall_opt_stop_camera(void);
extern void mmi_vt_incall_opt_mute_mic(void);
extern void mmi_vt_incall_opt_unmute_mic(void);
extern void mmi_vt_incall_opt_mute_speaker(void);
extern void mmi_vt_incall_opt_unmute_speaker(void);
extern void mmi_vt_incall_opt_switch_pic(void);
extern void mmi_vt_incall_opt_hide_small_pic(void);
extern void mmi_vt_incall_opt_unhide_small_pic(void);
extern void mmi_vt_entry_advanced(void);
extern void mmi_vt_entry_setting(void);
extern void mmi_vt_entry_answer_mode(void);
extern void mmi_vt_entry_dial_mode(void);
extern void mmi_vt_entry_alt_incall_pic(void);
extern void mmi_vt_entry_audio_option(void);
extern void mmi_vt_entry_audio_opt_confirm(void);
extern void mmi_vt_audio_opt_confirm_yes(void);
extern void mmi_vt_audio_opt_confirm_no(void);
extern void mmi_vt_setting_get_hilite_index(S32 index);
extern void mmi_vt_set_answer_mode(void);
extern void mmi_vt_set_dial_mode(void);
extern void mmi_vt_set_incall_pic_default(void);
extern void mmi_vt_entry_file_mgr_to_select_incall_pic(void);
extern void mmi_vt_set_incall_pic_from_fm(PU16 file_path, S32 is_short);
extern void mmi_vt_set_incall_pic_from_fm_during_incall(PU16 file_path, S32 is_short);
extern void mmi_vt_mo_fail_post_action_add_to_history(void);
extern void mmi_vt_entry_mo_fail_post_action(void);
extern void mmi_vt_process_mo_fail_post_action(void);
extern void mmi_vt_entry_video_quality(void);
extern void mmi_vt_entry_mirror_image(void);
extern void mmi_vt_advance_get_hilite_index(S32 index);
extern void mmi_vt_video_quality_done(void);
extern void mmi_vt_add_incall_to_history(void);
extern void mmi_vt_entry_in_call(void);
extern void mmi_vt_start_camera_query_yes(void);
extern void mmi_vt_start_camera_query_no(void);
extern void mmi_vt_start_camera_query_timeout(void);
extern void mmi_vt_entry_brightness(void);
extern void mmi_vt_entry_save_pic(void);
extern void mmi_vt_entry_dialer_screen(void);
extern void mmi_vt_pre_entry_new_call(void);
extern void mmi_vt_bt_set_audio_path(void);

/* VTUtil.c */
extern MMI_BOOL mmi_vt_get_camera_status(void);
extern void mmi_vt_set_camera_status(MMI_BOOL status);
extern MMI_BOOL mmi_vt_get_backend_camera_status(void);
extern void mmi_vt_set_backend_camera_status(MMI_BOOL status);
extern MMI_BOOL mmi_vt_get_mic_status(void);
extern void mmi_vt_set_mic_status(MMI_BOOL status);
extern MMI_BOOL mmi_vt_get_speaker_status(void);
extern void mmi_vt_set_speaker_status(MMI_BOOL status);
extern MMI_BOOL mmi_vt_get_pic_switch_status(void);
extern void mmi_vt_set_pic_switch_status(MMI_BOOL status);
extern MMI_BOOL mmi_vt_get_hide_small_pic_status(void);
extern void mmi_vt_set_hide_small_pic_status(MMI_BOOL status);
extern U16* mmi_vt_get_file_name(U16* file_path);
extern void mmi_vt_set_incall_pic(U16* file_path);
extern void mmi_vt_entry_dummy(void);
extern mmi_vt_video_quality_enum mmi_vt_get_video_quality_status(void);
extern void mmi_vt_set_video_quality_status(mmi_vt_video_quality_enum status);
extern MMI_BOOL mmi_vt_get_mirror_status(void);
extern void mmi_vt_set_mirror_status(MMI_BOOL status);
extern void mmi_vt_init_incall_setting(void);
extern mmi_vt_incall_screen_mode_enum mmi_vt_get_incall_screen_mode(void);
extern void mmi_vt_set_incall_screen_mode(mmi_vt_incall_screen_mode_enum mode);
extern mmi_vt_ev_enum mmi_vt_get_ev_status(void);
extern void mmi_vt_set_ev_status(mmi_vt_ev_enum status);
extern mmi_vt_zoom_enum mmi_vt_get_zoom_status(void);
extern void mmi_vt_set_zoom_status(mmi_vt_zoom_enum status);
extern mmi_vt_vol_enum mmi_vt_get_volume_status(void);
extern void mmi_vt_set_volume_status(mmi_vt_vol_enum status);
extern MMI_BOOL mmi_vt_get_hand_free_status(void);
extern void mmi_vt_set_hand_free_status(MMI_BOOL status);
extern MMI_BOOL mmi_vt_get_call_cost_status(S8* unit_uincode_str, S8* cost_uincode_str);
extern mmi_vt_incall_pic_status_enum mmi_vt_get_incall_pic(U16* default_pic_id, S8** file_unicode_str_ptr);
extern U16* mmi_vt_get_remote_display_name(void);
extern applib_time_struct* mmi_vt_get_call_start_time(void);

#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* VT_PROT_H */ 


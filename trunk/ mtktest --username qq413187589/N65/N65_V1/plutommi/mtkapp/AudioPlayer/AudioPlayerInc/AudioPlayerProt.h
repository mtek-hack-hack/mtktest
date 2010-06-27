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
*  AudioPlayerProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player proto-type
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * rebase maintrunk.MAUI_MBJ on 2007-4-24 0:25:15.
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef _AUDIO_PLAYER_PROT_H
#define _AUDIO_PLAYER_PROT_H

/*
 * Need to include:
 * (1) MMIDataType.h
 * (2) mdi_datatype.h
 */

#ifdef __MMI_AUDIO_PLAYER__

#ifdef __MMI_A2DP_SUPPORT__
extern void mmi_audply_bt_open_callback(S32 result);
extern void mmi_audply_read_bt_settings(void);
extern void mmi_audply_write_bt_settings(void);
extern BOOL mmi_audply_is_output_to_bt(void);
extern void mmi_audply_switch_bt_output(void);
extern void mmi_audply_sync_bt_output(void);
extern void mmi_audply_bt_stop(BOOL stop_codec, BOOL notify_opener);
#endif /*__MMI_A2DP_SUPPORT__*/

extern void mmi_audply_play(void);
extern void mmi_audply_pause(void);
extern void mmi_audply_resume(void);
extern void mmi_audply_restore(void);

extern BOOL mmi_audply_is_wait_open_bt(void);
extern void mmi_audply_back_to_main_screen_and_play(void);

extern void populateAudioPlayerMenu(void);

extern S32 mmi_audply_lookup_audio_file_format(UI_string_type file_ext);

/* return whether will audio player play or attempt to play song */
extern BOOL mmi_audply_is_play_activated(void);
extern BOOL mmi_audply_is_playing(void);
extern void mmi_audply_set_subLCD_shown(BOOL is_shown);

extern void mmi_audply_clear_play_seconds(void);
extern U32 mmi_audply_get_play_seconds(void);
extern void mmi_audply_update_play_seconds(void);

/* send mdi request */
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
extern void mmi_audply_calc_spectrum(BOOL on);
extern void mmi_audply_turn_on_spectrum(void);
extern void mmi_audply_turn_off_spectrum(void);
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
extern void mmi_audply_do_restore_action(void);
extern S32 mmi_audply_do_restore_action_without_handle_result(void);
extern void mmi_audply_do_play_action(void);

extern S32 mmi_audply_do_portion_play_action_without_handle_result(PS8 error_class);
extern void mmi_audply_do_pause_action(BOOL need_pop_up);
extern void mmi_audply_do_resume_action(void);
extern void mmi_audply_do_stop_action(void);
extern void mmi_audply_stop_playing(void);
extern void mmi_audply_seek_stop_playing(void);

/* handle mdi callback */
extern void mmi_audply_play_callback_hdlr(mdi_result result);
extern void mmi_audply_pause_callback_hdlr(mdi_result result);
extern BOOL mmi_audply_background_callback_hdlr(mdi_result result);
extern void mmi_audply_build_cache_fail_callback_hdlr(void *inMsg);
extern void mmi_audply_auto_update_duration_hdlr(U32 duration);

extern void mmi_audply_encoding_type_change_callback(void);

/* update UI & states */
extern void mmi_audply_play_completed(void);
extern void mmi_audply_played(void);
extern void mmi_audply_stopped(void);
extern void mmi_audply_paused(void);
extern void mmi_audply_resumed(void);

extern void mmi_audply_get_fs_info(void);
extern void mmi_audply_read_settings(void);
extern void mmi_audply_write_settings(void);

extern void InitAudioPlayerApp(void);
extern void HighlightAudioPlayer(void);

extern void mmi_audply_update_main_button_flag(void);
extern void mmi_audply_update_main(void);
extern void mmi_audply_entry_main(void);
extern void mmi_audply_exit_main(void);
extern void mmi_audply_seeking_exit_main(void);

extern void mmi_audply_entry_list(void);
extern void mmi_audply_exit_list(void);
extern void mmi_audply_list_highlight_hdlr(S32 index);
extern pBOOL mmi_audply_list_getitem(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

extern void mmi_audply_entry_option(void);
extern void mmi_audply_exit_option(void);
extern void mmi_audply_option_highlight_hdlr(S32 index);
extern void mmi_audply_option_right_arrow_key(void);
extern void mmi_audply_option_LSK(void);

extern void mmi_audply_entry_two_layers_settings(void);
extern void mmi_audply_two_layer_settings_highlight_hdlr(S32 index);
extern void mmi_audply_two_layer_settings_highlight_hdlr(S32 index);
extern void mmi_audply_two_layer_settings_LSK(void);
extern void mmi_audply_entry_player_settings(void);
extern void mmi_audply_exit_player_settings(void);
extern void mmi_audply_player_settings_highlight_hdlr(S32 index);
extern void mmi_audply_player_settings_done(void);
extern void mmi_audply_entry_display_settings(void);
extern void mmi_audply_exit_display_settings(void);
extern void mmi_audply_display_settings_highlight_hdlr(S32 index);
extern void mmi_audply_display_settings_done(void);
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
extern void mmi_audply_entry_sound_effect_settings(void);
extern void mmi_audply_exit_sound_effect_settings(void);
extern void mmi_audply_sound_effect_settings_highlight_hdlr(S32 index);
extern void mmi_audply_sound_effect_settings_back(void);
extern void mmi_audply_sound_effect_settings_done(void);
#endif /*defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__)  || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/

#ifdef __MMI_A2DP_SUPPORT__
extern void mmi_audply_entry_bluetooth_settings(void);
extern void mmi_audply_exit_bluetooth_settings(void);
extern void mmi_audply_bluetooth_settings_highlight_hdlr(S32 index);
extern void mmi_audply_bluetooth_settings_done(void);
extern void mmi_audply_select_bt_a2dp_headset(void);
#endif /* __MMI_A2DP_SUPPORT__ */

extern void mmi_audply_entry_settings(void);
extern void mmi_audply_settings_highlight_hdlr(S32 index);

extern void mmi_audply_exit_settings(void);
extern void mmi_audply_settings_LSK(void);

extern void mmi_audply_entry_detail(void);
extern void mmi_audply_detail_highlight_hdlr(S32 index);
extern void mmi_audply_exit_detail(void);

extern void mmi_audply_entry_remove_confirm(void);
extern void mmi_audply_exit_remove_confirm(void);
extern void mmi_audply_remove_confirm_LSK(void);

extern void mmi_audply_entry_remove_all_confirm(void);
extern void mmi_audply_exit_remove_all_confirm(void);
extern void mmi_audply_remove_all_confirm_LSK(void);

extern void mmi_audply_process_add_files_in_folder(void);
extern void mmi_audply_process_add_files_end(U8 result);
extern void mmi_audply_entry_processing_add(void);
extern void mmi_audply_exit_processing_add(void);
extern void mmi_audply_add_file_hdlr(S8 *fullPath, int is_short);
extern void mmi_audply_update_list_hdlr(const PS8 old_path, const PS8 new_path, U8 action_type, BOOL is_folder);

extern BOOL mmi_audply_can_delete_folder(S8 *fullPath);
extern BOOL mmi_audply_can_delete_file(S8 *fullPath);
extern BOOL mmi_audply_can_delete_all_files(S8 *fullPath);
extern void mmi_audply_need_reinit(void);

extern void mmi_audply_timer(void);
extern void mmi_audply_update_progress_target_time(U32 old_duration);
extern BOOL mmi_audply_update_total_duration_by_cache(void);
extern void mmi_audply_fast_forward(void);
extern void mmi_audply_rewind(void);
extern void mmi_audply_determine_progress_speed(void);
extern void mmi_audply_initialize_cache(void);
extern void mmi_audply_refresh_cache(BOOL check_name);
extern U8* mmi_audply_determine_cache_ptr(void);
extern void mmi_audply_press_button_canceled(void);
extern void mmi_audply_press_stop_button_up(void);
extern void mmi_audply_press_play_button_up(void);
extern void mmi_audply_press_prev_button_up(void);
extern void mmi_audply_press_next_button_up(void);
extern void mmi_audply_press_stop_button_down(void);
extern void mmi_audply_press_play_button_down(void);
extern void mmi_audply_press_prev_button_down(void);
extern void mmi_audply_press_next_button_down(void);
extern void mmi_audply_press_next_button_longpress(void);
extern void mmi_audply_press_prev_button_longpress(void);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_audply_touch_progress_seeking(S16 cor_x);
extern void mmi_audply_touch_progress_hdlr(S16 cor_x);
extern void mmi_audply_touch_progress_pen_up(void);
#endif

extern void mmi_audply_press_inc_volume(void);
extern void mmi_audply_press_inc_volume_up(void);
extern void mmi_audply_press_inc_volume_down(void);
extern void mmi_audply_press_dec_volume(void);
extern void mmi_audply_press_dec_volume_up(void);
extern void mmi_audply_press_dec_volume_down(void);
extern BOOL mmi_audply_save_volume(U8 volume);
extern U8 mmi_audply_get_volume(void);

#ifdef __DRM_SUPPORT__
extern S8 mmi_audply_drm_valide_right(U16* filename);
#endif

extern void mmi_audply_regenerate_play_list(void);
extern void mmi_audply_refresh_play_list(void);
extern void mmi_audply_refresh_play_list_end(U8 result);
extern void mmi_audply_exit_refresh_list(void);
extern void mmi_audply_reload_play_list(void);

extern void mmi_audply_msdc_plug_in_hdlr(BOOL has_popup);
extern void mmi_audply_msdc_plug_out_hdlr(BOOL has_popup);

extern U8 mmi_audply_delete_history_hdlr(void *in_param);

#ifdef __MMI_AUDIO_TIME_STRETCH__
extern U16 mmi_audply_speed_get_index(U16 speed);
extern U16 mmi_audply_speed_get_speed(U16 index);
extern BOOL mmi_audply_apply_change_in_setting(U16 index);
extern void mmi_audply_speed_set_speed(void);
extern void mmi_audply_speed_close(void);
extern S32 mmi_audply_speed_check_before_play(U16 speed);

#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
extern void mmi_audply_lyric_check_backlight(const BOOL on);
extern void mmi_audply_stop_lyric(void);
extern void mmi_audply_clear_lyric_context(void);
extern BOOL mmi_audply_init_lyric(void);
extern BOOL mmi_audply_parse_lyric(U16 *cur_char);
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#endif /* __MMI_AUDIO_PLAYER__ */ 

extern U16 mmi_audply_err_str(S32 result);
extern BOOL mmi_audply_err_img_tone(S32 result);

/* single play */
extern void mmi_audply_single_play_timer(void);
extern void mmi_audply_single_play(UI_string_type filefullname, void (*exit_callback_func) (void));
extern void mmi_audply_play_in_melody_composer(UI_string_type filefullname, void (*exit_callback_func) (void));
extern void mmi_audply_entry_play_animation(void);
extern void mmi_audply_exit_play_animation(void);
extern U8 mmi_audply_delete_play_animation_history_hdlr(void *param_p);
extern S32 mmi_audply_do_single_play_action(UI_string_type filefullname);
extern S32 mmi_audply_do_single_play_action_in_meldoy_composer(UI_string_type filefullname);
extern void mmi_audply_do_single_stop_action(void);
extern void mmi_audply_single_play_callback_hdlr(mdi_result result);

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
extern void HighlightSubAudioPlayer(void);
extern void mmi_sub_audply_entry_main(void);
extern void mmi_sub_audply_exit_main(void);
extern void mmi_sub_audply_entry_option(void);
extern void mmi_sub_audply_option_lsk(void);
extern void mmi_sub_audply_exit_option(void);
extern void mmi_sub_audply_entry_playlist(void);
extern void mmi_sub_audply_entry_repeat_setting(void);
extern void mmi_sub_audply_shuffle_setting(void);
extern BOOL mmi_sub_audply_refresh_list_key_handler(void);
extern void mmi_sub_audply_refresh_list_popup(void);
extern U8 EntrySubLCDMainMenu(void);
extern void DinitSubLCDHistory(void);
extern BOOL mmi_sub_audply_entry_main_key_handler(void);
extern BOOL mmi_sub_audply_entry_option_key_handler(void);
extern BOOL mmi_sub_audply_entry_list_key_handler(void);
extern U8 mmi_sub_audply_delete_history_hdlr(void *in_param);
extern void mmi_sub_audply_press_play_button_down(void);
extern void mmi_sub_audply_press_play_button_up(void);
extern void mmi_sub_audply_press_prev_button_down(void);
extern void mmi_sub_audply_press_prev_button_up(void);
extern void mmi_sub_audply_press_next_button_down(void);
extern void mmi_sub_audply_press_next_button_up(void);
extern void mmi_sub_audply_update_main(void);
extern BOOL mmi_sub_audply_entry_playlist_key_handler(void);
extern void mmi_sub_audply_exit_audply_app(void);
extern BOOL mmi_sub_audply_popup_error_key_handler(void);
extern void mmi_sub_audply_popup_error(void);
extern void mmi_sub_audply_play_file_in_sub_playlist(void);
extern  void mmi_sub_audply_exit_playlist(void);
#endif

#endif /* _AUDIO_PLAYER_PROT_H */ 


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
*  FMRadioProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main prototype
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef _FM_RADIO_PROT_H
#define _FM_RADIO_PROT_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
/*
 * Need to include:
 * (1) xxx.h
 * (2) yyy.h
 */

extern void mmi_fmrdo_set_subLCD_shown(BOOL is_shown);
extern void mmi_fmrdo_power_on_main_screen(BOOL turn_on);
extern BOOL mmi_fmrdo_is_power_on(void);
extern UI_string_type mmi_fmrdo_get_channel_name_or_freq(void);
#if defined(FM_RADIO_WITH_TV)
extern void mmi_fmrdo_preset_list_done( U16* signal_band );
#else
extern void mmi_fmrdo_preset_list_done(U8 *signal_band);
#endif
extern void mmi_fmrdo_start_twinkle_frequency(void);
extern void mmi_fmrdo_stop_twinkle_frequency(BOOL is_shown);

extern void mmi_fmrdo_long_press_number_key(void);
extern void mmi_fmrdo_release_number_key(void);

extern void mmi_fmrdo_twinkle_frequency_timer(void);
extern void mmi_fmrdo_step_down_timer(void);
extern void mmi_fmrdo_step_up_timer(void);
extern BOOL mmi_fmrdo_is_stepping_up(void);
extern BOOL mmi_fmrdo_is_stepping_down(void);

extern U16 mmi_fmrdo_get_freq_from_str(UI_string_type input_str);

extern void mmi_fmrdo_set_channel(S16 channel_index, U16 freq, UI_string_type name);

extern U8 mmi_fmrdo_get_volume(void);
extern void mmi_fmrdo_set_volume(U8 volume);

extern void mmi_fmrdo_write_settings_to_nvram(void);

extern void mmi_fmrdo_inc_volume(void);
extern void mmi_fmrdo_dec_volume(void);

extern void mmi_fmrdo_init_app(void);
extern void mmi_fmrdo_run_app(void);
extern void mmi_fmrdo_stop_audply(void);
extern void mmi_fmrdo_highlight_menu(void);

extern S16 mmi_fmrdo_match_channel_list(U16 frequency);

extern void mmi_fmrdo_press_step_down_button(void);
extern void mmi_fmrdo_release_step_down_button(void);

extern void mmi_fmrdo_press_step_up_button(void);
extern void mmi_fmrdo_release_step_up_button(void);

extern void mmi_fmrdo_press_search_button(void);
extern void mmi_fmrdo_release_search_button(void);

extern void mmi_fmrdo_press_power_button(void);
extern void mmi_fmrdo_release_power_button(void);

extern U8 mmi_fmrdo_exit_root(void *param_p);
extern void mmi_fmrdo_entry_main(void);
extern void mmi_fmrdo_exit_main(void);

extern void mmi_fmrdo_entry_main_option(void);
extern void mmi_fmrdo_exit_main_option(void);
extern void mmi_fmrdo_main_option_highlight_hdlr(S32 index);
extern void mmi_fmrdo_main_option_LSK(void);

extern pBOOL mmi_fmrdo_channel_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_fmrdo_channel_list_item_hint(S32 item_index, UI_string_type *hint_array);
extern void mmi_fmrdo_entry_channel_list(void);
extern void mmi_fmrdo_exit_channel_list(void);
extern void mmi_fmrdo_channel_list_highlight_hdlr(S32 index);

extern void mmi_fmrdo_entry_manual_input(void);
extern void mmi_fmrdo_exit_manual_input(void);
extern void mmi_fmrdo_manual_input_highlight_hdlr(S32 index);
extern void mmi_fmrdo_manual_input_LSK(void);

extern void mmi_fmrdo_entry_preset_list_confirm(void);
extern void mmi_fmrdo_exit_preset_list_confirm(void);
extern void mmi_fmrdo_preset_list_confirm_LSK(void);

extern void mmi_fmrdo_entry_settings(void);
extern void mmi_fmrdo_exit_settings(void);
extern void mmi_fmrdo_settings_highlight_hdlr(S32 index);
extern void mmi_fmrdo_settings_LSK(void);

extern void mmi_fmrdo_entry_channel_option(void);
extern void mmi_fmrdo_exit_channel_option(void);
extern void mmi_fmrdo_channel_option_highlight_hdlr(S32 index);
extern void mmi_fmrdo_channel_option_LSK(void);

extern void mmi_fmrdo_entry_searching(void);
extern void mmi_fmrdo_exit_searching(void);
extern void mmi_fmrdo_searching_abort(void);

extern void mmi_fmrdo_entry_channel_edit(void);
extern void mmi_fmrdo_exit_channel_edit(void);
extern void mmi_fmrdo_channel_edit_highlight_hdlr(S32 index);
extern void mmi_fmrdo_channel_edit_LSK(void);

extern void mmi_fmrdo_entry_channel_name_edit(void);

extern void mmi_fmrdo_entry_channel_name_edit_option(void);
extern void mmi_fmrdo_channel_name_edit_option_highlight_hdlr(S32 index);
extern void mmi_fmrdo_channel_name_edit_option_LSK(void);

extern void mmi_fmrdo_entry_clear_channel_confirm(void);
extern void mmi_fmrdo_exit_clear_channel_confirm(void);
extern void mmi_fmrdo_clear_channel_LSK(void);

extern void mmi_fmrdo_entry_save_channel_confirm(void);
extern void mmi_fmrdo_exit_save_channel_confirm(void);
extern void mmi_fmrdo_save_channel_LSK(void);
extern void mmi_fmrdo_save_channel_RSK(void);

#if defined(__MMI_FM_RADIO_RECORD__)
extern void mmi_fmrdo_release_record_button(void);
extern void mmi_fmrdo_release_append_button(void);
extern void mmi_fmrdo_release_stop_button(void);
extern void mmi_fmrdo_release_resume_button(void);
extern void mmi_fmrdo_select_file_callback(void *fullname, int is_short);
extern void mmi_fmrdo_send_record_req(BOOL is_append);
extern void mmi_fmrdo_entry_main_record_screen(void);
extern void mmi_fmrdo_entry_main_pause_screen(void);
extern void mmi_fmrdo_entry_restore_main_screen(void);
extern void mmi_fmrdo_record_stopped_hdlr(void);
extern void mmi_fmrdo_entry_edit_filename(void);
extern void mmi_fmrdo_entry_edit_abort_query(void);
extern void mmi_fmrdo_abort_edit_file(void);
extern void mmi_fmrdo_entry_edit_filename_option(void);
extern void mmi_fmrdo_highlight_record_save_file(void);
extern void mmi_fmrdo_highlight_record_input_method(void);
extern void mmi_fmrdo_record_save_file(void);
extern void mmi_fmrdo_entry_record_list(void);
extern void mmi_fmrdo_browse_file_callback(void *fullname, int is_short);
extern void mmi_fmrdo_record_error_hdlr(S32 cause);

extern void mmi_fmrdo_util_get_storage_path(UI_string_type path, U8 storage);
extern BOOL mmi_fmrdo_util_check_storage_folder(UI_string_type path);
extern void mmi_fmrdo_util_append_file_ext(UI_string_type filename, U8 format);
extern void mmi_fmrdo_util_remove_file_ext(UI_string_type filename);
extern BOOL mmi_fmrdo_util_check_file_exist(UI_string_type filename);
extern void mmi_fmrdo_util_increase_file_name(UI_string_type filename);
extern BOOL mmi_fmrdo_util_get_new_file(UI_string_type fullname);
extern UI_string_type mmi_fmrdo_util_get_file_name(UI_string_type fullname);
extern void mmi_fmrdo_util_init_duration(void);
extern void mmi_fmrdo_util_start_duration(void);
extern void mmi_fmrdo_util_update_duration(void);
extern void mmi_fmrdo_util_stop_duration(void);
extern void mmi_fmrdo_go_back_2_history(void);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#ifdef __MMI_FM_RADIO_ON_SUBLCD__
extern void mmi_fmrdo_sub_entry_main(void);
extern void mmi_fmrdo_sub_exit_main(void);
extern void mmi_fmrdo_sub_main_register_keys(void);
extern void mmi_fmrdo_sub_press_step_down_button(void);
extern void mmi_fmrdo_sub_release_step_down_button(void);
extern void mmi_fmrdo_sub_press_step_up_button(void);
extern void mmi_fmrdo_sub_release_step_up_button(void);
extern void mmi_fmrdo_sub_press_power_button(void);
extern void mmi_fmrdo_sub_release_power_button(void);
extern void mmi_fmrdo_sub_goto_previous_channel(U16 freq);
extern void mmi_fmrdo_sub_goto_next_channel(U16 freq);
extern void mmi_fmrdo_sub_entry_option(void);
extern void mmi_fmrdo_sub_exit_option(void);
extern void mmi_fmrdo_sub_option_highlight_hdlr(S32 index);
extern void mmi_fmrdo_sub_option_LSK(void);
extern void mmi_fmrdo_sub_entry_step_mode(void);
extern void mmi_fmrdo_sub_entry_channel_mode(void);
extern void mmi_fmrdo_sub_entry_search_mode(void);
extern void mmi_fmrdo_sub_entry_searching(void);
extern void mmi_fmrdo_sub_exit_searching(void);
extern void mmi_fmrdo_sub_highlight_menu(void);
extern void GoBackSubLCDHistory(void);
extern BOOL mmi_fmrdo_sub_entry_run_app_key_handler(void);
extern BOOL mmi_fmrdo_sub_entry_option_key_handler(void);
extern BOOL mmi_fmrdo_sub_entry_search_key_handler(void);
extern BOOL mmi_fmrdo_sub_entry_power_on_key_handler(void);
extern void mmi_fmrdo_sub_show_power_on_popup(void);
extern U8 mmi_fmrdo_sub_exit_root(void *param_p);
extern BOOL mmi_fmrdo_sub_entry_main_from_idle(void);

extern BOOL mmi_fmrao_sub_exit_by_earphone_plug_out(void);
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/

/* FMRadioMsgHdlr.c */
extern BOOL mmi_fmrdo_continued(S32 result);
extern void mmi_fmrdo_preempted(S32 result);
extern void mmi_fmrdo_goto_channel(U16 channel_index);
extern void mmi_fmrdo_set_frequency(U16 freq);
extern void mmi_fmrdo_power_on_before_preset_auto_search(void);
extern void mmi_fmrdo_power_on(BOOL turn_on);
extern void mmi_fmrdo_search_frequency_start(U16 start_freq, BOOL is_step_up);
extern void mmi_fmrdo_search_frequency(BOOL is_valid);
extern void mmi_fmrdo_search_frequency_stop(void);
#if defined(FM_RADIO_WITH_TV)
void mmi_fmrdo_search_all_channels_start( void (*callback_func)(U16* signal_band) );
extern void mmi_fmrdo_search_all_channels( U16 signal_level );
#else
void mmi_fmrdo_search_all_channels_start(void (*callback_func) (U8 *signal_band));
extern void mmi_fmrdo_search_all_channels(U8 signal_level);
#endif
extern void mmi_fmrdo_search_all_channels_stop(void);

#if defined(__MMI_FM_RADIO_RECORD__)
extern void mmi_fmrdo_start_record(UI_string_type filename, U8 format, U8 quality);
extern void mmi_fmrdo_stop_record(void);
extern void mmi_fmrdo_stop_record_on_exit(void);
extern void mmi_fmrdo_pause_record(void);
extern void mmi_fmrdo_resume_record(void);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#endif /* __MMI_FM_RADIO__ */ 
#endif /* _FM_RADIO_PROT_H */ 


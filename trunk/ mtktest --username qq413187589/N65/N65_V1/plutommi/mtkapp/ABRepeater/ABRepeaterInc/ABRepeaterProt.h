/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  ABRepeaterProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater proto-type
*
* Author:
* -------
*  Tarun Bakshi
*
*********************************************************************************************/

#ifndef _AB_REPEATER_PROT_H
#define _AB_REPEATER_PROT_H

/*
 * Need to include:
 * (1) MMIDataType.h
 * (2) mdi_datatype.h
 */

#ifdef __MMI_AB_REPEATER__
extern U8 mmi_abrepeat_get_preferred_or_available_list(void);

extern void InitABRepeaterApp(void);
extern void HighlightABRepeater(void);
extern void mmi_abrepeat_entry_list(void);
extern void mmi_abrepeat_select_file(void);
extern void* mmi_abrepeat_build_cache_ptr(void);
extern void mmi_abrepeat_entry_build_cache(void);
extern void mmi_abrepeat_exit_build_cache(void);
extern U8 mmi_abrepeat_exit_build_cache_root(void* param);
extern void mmi_abrepeat_build_cache_start(void);
extern void mmi_abrepeat_build_cache_process(void);
extern void mmi_abrepeat_storage_highlight_hdlr(void);
extern void mmi_abrepeat_option_highlight_hdlr(S32 index);
extern void mmi_abrepeat_inline_edit_hightlight_hdlr(S32 index);
extern void mmi_abrepeat_exit_storage_media(void);
extern void mmi_abrepeat_save_storage(void);
extern void mmi_abrepeat_enter_storage_media(void);
extern void mmi_abrepeat_enter_highlight_hdlr(void);
extern void mmi_abrepeat_entry_option(void);
extern void mmi_abrepeat_option_lsk(void);
extern void mmi_abrepeat_rsk_action(void);
extern U8 mmi_abrepeat_delete_history_hdlr(void *in_param);
extern void mmi_abrepeat_redraw_setting_play_screen(void);
extern void mmi_abrepeat_read_settings(void);
extern void mmi_abrepeat_filename_callback(void *fullname, int is_short);
extern void mmi_abrepeat_entry_main(void);
extern void mmi_abrepeat_exit_main(void);
extern void mmi_abrepeat_get_fs_info(void);
extern void mmi_abrepeat_setting_set_key_handlers(void);
extern void mmi_abrepeat_setting_press_digit_up(void);
extern void mmi_abrepeat_play_press_digit_down_hdlr(U16 keycode);
extern void mmi_abrepeat_play_press_digit_down(void);
extern void mmi_abrepeat_setting_press_digit_down(void);
extern void mmi_abrepeat_setting_press_digit_down_hdlr(U16 keycode);
extern void mmi_abrepeat_setting_press_digit_up_hdlr(U16 keycode);
extern void mmi_abrepeat_setting_long_press_digit_hdlr(U16 keycode);
extern void mmi_abrepeat_setting_long_press_digit(void);
extern void mmi_abrepeat_set_mainplay_section_key_handler(void);
extern void mmi_abrepeat_press_play_button_down(void);
extern void mmi_abrepeat_press_rewind_button_down(void);
extern void mmi_abrepeat_press_forward_button_down(void);
extern void mmi_abrepeat_press_stop_button_down(void);
extern void mmi_abrepeat_press_play_button_up(void);
extern void mmi_abrepeat_press_rewind_button_up(void);
extern void mmi_abrepeat_press_forward_button_up(void);
extern void mmi_abrepeat_press_stop_button_up(void);

extern void mmi_abrepeat_press_inc_volume(void);
extern void mmi_abrepeat_press_dec_volume(void);
extern void mmi_abrepeat_press_inc_volume_down(void);
extern void mmi_abrepeat_press_dec_volume_down(void);

extern void mmi_abrepeat_play_set_key_handlers(void);
extern void mmi_abrepeat_play_press_digit_up(void);
extern void mmi_abrepeat_play_press_digit_up_hdlr(U16 keycode);

extern void mmi_abrepeat_do_stop_action(void);
extern void mmi_abrepeat_stopped(void);

extern void mmi_abrepeat_do_pause_action(void);
extern void mmi_abrepeat_paused(void);
extern void mmi_abrepeat_play_completed(void);
extern void mmi_abrepeat_pause_callback_hdlr(mdi_result result);

extern void mmi_abrepeat_do_resume_action(void);
extern void mmi_abrepeat_resumed(void);
extern void mmi_abrepeat_resume_callback_hdlr(mdi_result result);

extern void mmi_abrepeat_do_play_action(void);
extern S32 mmi_abrepeat_do_play_action_without_handle_result(void);
extern void mmi_abrepeat_play_callback_hdlr(mdi_result result);
extern void mmi_abrepeat_played(void);
extern void mmi_abrepeat_timer(void);
extern U16 mmi_abrepeat_err_str(S32 result);

#ifdef SIMULATOR_TESTING
extern U32 mmi_abrepeat_dummy_get_curr_offset(void);
extern void dummy_file_offset(void);
#endif /* SIMULATOR_TESTING */ 

/* manish adding this function */
extern void mmi_abrepeat_option_back(void);

#if !defined(__MMI_SHOW_DAF_FILE_EXT__)  
extern void mmi_abrepeat_hide_ext_name(S8 *file_name);
#endif /*!defined(__MMI_SHOW_DAF_FILE_EXT__)*/

#endif /* __MMI_AB_REPEATER__ */ 

#endif /* _AB_REPEATER_PROT_H */ 


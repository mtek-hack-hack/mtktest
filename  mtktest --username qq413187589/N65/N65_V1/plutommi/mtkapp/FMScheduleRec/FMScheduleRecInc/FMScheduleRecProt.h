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
 *   FMScheduleRecProt.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  .............
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_FMSRPROT_H
#define _MMI_FMSRPROT_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

/* FMScheduleRec.c */
extern BOOL mmi_fmsr_alarm_expire_check_file(void *ptr);
extern BOOL mmi_fmsr_alarm_expire_check_mode(void);
extern void mmi_fmsr_alarm_expire_ind(U16 index, BOOL power_on_record);

extern BOOL mmi_fmsr_rec_start_remaining_timer(void);
extern BOOL mmi_fmsr_send_record_req(void);
extern BOOL mmi_fmsr_send_re_record_req(void);
extern void mmi_fmsr_send_stop_req(void);
extern void mmi_fmsr_send_pause_req(void);
extern void mmi_fmsr_send_resume_req(void);
extern void mmi_fmsr_stop_record_ind(void);
extern U32 mmi_fmsr_get_duration_ticks(void);
extern void mmi_fmsr_init_duration(void);
extern void mmi_fmsr_start_duration(void);
extern void mmi_fmsr_update_duration(void);

extern void mmi_fmsr_pre_entry_recording(void);
extern void mmi_fmsr_entry_recording(void);
extern void mmi_fmsr_exit_recording(void);
extern U8 mmi_fmsr_del_scr_callback(void *p);
extern void mmi_fmsr_rec_release_RSK(void);
extern void mmi_fmsr_rec_release_LSK(void);

extern void mmi_fmsr_show_record_result(void);
extern void mmi_fmsr_entry_show_msg(void);
extern void mmi_fmsr_exit_show_msg(void);
extern void mmi_fmsr_show_msg_confirm(void);
extern void mmi_fmsr_show_msg_prepare_data(S8 *str);
extern void mmi_fmsr_record_error_hdlr(S32 cause);

extern U8 mmi_fmsr_battery_status_interrupt_hdlr(mmi_frm_int_event_type interrupt_event);
extern U8 mmi_fmsr_post_interrupt_hdlr(mmi_frm_int_event_type interrupt_event);
extern MMI_BOOL mmi_fmsr_is_schedule_rec_running(void);
extern void mmi_fmsr_init_app(void);

/* FMScheduleRecScreen.c */
extern void mmi_fmsr_init_screen(void);
extern void mmi_fmsr_show_main(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);
extern void mmi_fmsr_hide_main(void);
extern void mmi_fmsr_redraw_main_all(void);
extern void mmi_fmsr_redraw_state(void);
extern void mmi_fmsr_redraw_frequency(void);
extern void mmi_fmsr_redraw_duration(void);
extern void mmi_fmsr_redraw_date(void);
extern void mmi_fmsr_redraw_time(void);
extern void mmi_fmsr_redraw_LSK_up(void);
extern void mmi_fmsr_redraw_RSK_up(void);
extern void mmi_fmsr_redraw_LSK_down(void);
extern void mmi_fmsr_redraw_RSK_down(void);
extern void mmi_fmsr_redraw_LSK(U16 left_softkey, U16 left_softkey_icon);
extern void mmi_fmsr_change_pause_screen(void);
extern void mmi_fmsr_restore_recording_screen(void);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_fmsr_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmsr_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmsr_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_SUBLCD__
extern void mmi_fmsr_entry_sublcd_screen(void);
extern void mmi_fmsr_exit_sublcd_screen(void);
extern void mmi_fmsr_entry_sublcd_msg_screen(void);
extern void mmi_fmsr_exit_sublcd_msg_screen(void);
#endif

/* FMScheduleRecSetting.c */
extern void mmi_fmsr_init_setting(void);
extern void mmi_fmsr_deinit_setting(void);
extern U8 mmi_fmsr_mapping_repeat_to_alm(U8 fmsr_rt);
extern void mmi_fmsr_highlight_app(void);
extern void mmi_fmsr_pre_entry_main_list(void);
extern void mmi_fmsr_entry_main_list(void);
extern void mmi_fmsr_main_list_highlight_hdlr(S32 index);
extern void mmi_fmsr_main_list_update_state(U16 index, MMI_BOOL on_off);
extern BOOL mmi_fmsr_util_get_state_for_reinitialize_alarm(U8 index);

extern void mmi_fmsr_main_setting_prepare_inline_data(void);
extern void mmi_fmsr_entry_main_setting(void);
extern void mmi_fmsr_exit_main_setting(void);
extern void mmi_fmsr_main_setting_fill_inline_item(void);
extern void mmi_fmsr_main_setting_highlight_hdlr(S32 index);
extern void mmi_fmsr_main_setting_save_confirm(void);
extern BOOL mmi_fmsr_main_setting_check_freq_and_file(void);
extern void mmi_fmsr_main_setting_save_and_set(void);
extern void mmi_fmsr_main_setting_abort(void);
extern void mmi_fmsr_int_cb_function(void);
extern U8 mmi_fmsr_expiry_cb_handler(U8 index, U16 *period, BOOL power_on);
extern void mmi_fmsr_reinit_queue(void);
extern void mmi_fmsr_util_get_setting_for_alarm(U8 index, MYTIME *alarmTime, U8 *repeat, U8 *weekday, MYTIME* preReminder);

extern void mmi_fmsr_highlight_chan_list(void);
extern void mmi_fmsr_highlight_chan_manual(void);
extern void mmi_fmsr_entry_chan_setting(void);
extern void mmi_fmsr_entry_chan_list(void);
extern void mmi_fmsr_chan_list_select(void);
extern void mmi_fmsr_entry_chan_manual(void);
extern void mmi_fmsr_exit_chan_manual(void);
extern void mmi_fmsr_chan_manual_input_LSK(void);

extern void mmi_fmsr_rec_setting_prepare_inline_data(void);
extern void mmi_fmsr_rec_setting_highlight_hdlr(S32 item_index);
extern void mmi_fmsr_entry_rec_setting(void);
extern void mmi_fmsr_exit_rec_setting(void);
extern void mmi_fmsr_rec_setting_fill_inline_item(void);
extern void mmi_fmsr_rec_setting_done(void);
extern void mmi_fmsr_rec_select_file(void);
extern void mmi_fmsr_rec_select_file_done(void *fullname, int is_short);

//extern void mmi_fmsr_entry_rec_edit_filename(void);
//extern void mmi_fmsr_entry_rec_edit_filename_option(void);
//extern void mmi_fmsr_highlight_rec_edit_done(void);
//extern void mmi_fmsr_highlight_rec_edit_input_method(void);
//extern void mmi_fmsr_rec_edit_done(void);

extern void mmi_fmsr_util_get_date_from_int(S8 *str_year, S8 *str_mon, S8 *str_day, U16 year, U8 mon, U8 day);
extern void mmi_fmsr_util_get_date_from_str(S8 *str_year, S8 *str_mon, S8 *str_day, U16 *year, U8 *mon, U8 *day);
extern void mmi_fmsr_util_get_time_from_int(
                S8 *str_hour1,
                S8 *str_min1,
                S8 *str_hour2,
                S8 *str_min2,
                U8 hour1,
                U8 min1,
                U8 hour2,
                U8 min2);
extern void mmi_fmsr_util_get_time_from_str(
                S8 *str_hour1,
                S8 *str_min1,
                S8 *str_hour2,
                S8 *str_min2,
                U8 *hour1,
                U8 *min1,
                U8 *hour2,
                U8 *min2);
extern void mmi_fmsr_util_get_weekday_from_int(U8 *weekday_state, U8 weekday);
extern void mmi_fmsr_util_get_weekday_from_array(U8 *weekday_state, U8 *weekday);
extern void mmi_fmsr_util_get_storage_path(UI_string_type path, U8 storage);
extern S32 mmi_fmsr_util_check_storage_folder(UI_string_type path);
extern S32 mmi_fmsr_util_check_file_exist(UI_string_type path);
extern void mmi_fmsr_util_append_file_ext(UI_string_type filename, U8 format);
extern void mmi_fmsr_util_get_full_path(UI_string_type full_path, UI_string_type file_name, U8 storage, U8 format);
extern UI_string_type mmi_fmsr_util_get_file_name(UI_string_type fullname);
extern void mmi_fmsr_util_remove_file_ext(UI_string_type filename);
extern void mmi_fmsr_util_get_new_file(UI_string_type fullname, U8 format);
extern BOOL mmi_fmsr_util_check_time_overlap(
                U8 shour1,
                U8 smin1,
                U8 shour2,
                U8 smin2,
                U8 dhour1,
                U8 dmin1,
                U8 dhour2,
                U8 dmin2);
extern BOOL mmi_fmsr_util_check_repeat_overlap(
                U8 repeat1,
                U16 year1,
                U8 mon1,
                U8 day1,
                U8 weekday1,
                U8 repeat2,
                U16 year2,
                U8 mon2,
                U8 day2,
                U8 weekday2);
extern void mmi_fmsr_go_back_2_history(void);

/* FMScheduleRecMsgHdlr.c */
extern void mmi_fmsr_mdi_callback(S32 result);
extern void mmi_fmsr_power_on(void);
extern void mmi_fmsr_power_off(void);
extern BOOL mmi_fmsr_start_record(UI_string_type filename, U8 format, U8 quality);
extern void mmi_fmsr_stop_record(void);
extern void mmi_fmsr_pause_record(void);
extern void mmi_fmsr_resume_record(void);
extern void mmi_fmsr_increase_volume(void);
extern void mmi_fmsr_decrease_volume(void);

#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* _MMI_FMSRPROT_H */ /* #ifndef _MMI_FMSRPROT_H */


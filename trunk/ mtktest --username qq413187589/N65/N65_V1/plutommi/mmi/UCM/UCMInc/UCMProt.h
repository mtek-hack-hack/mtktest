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
 *  UCMProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_PROT_H
#define UCM_PROT_H

#ifdef __MMI_INTELLIGENT_CALL_ALERT__
#include "mdi_datatype.h"
#endif

#define MMI_UCM_MAX_ACTIVE_TAB                  (1)
#define MMI_UCM_MAX_HELD_TAB                    (3)
#define MMI_UCM_MAX_NUM_TAB                     (MMI_UCM_MAX_ACTIVE_TAB + MMI_UCM_MAX_HELD_TAB)
#define MMI_UCM_MAX_NUM_INDEX                   (5)
#define MMI_UCM_SCREEN_DIGITS                   (13)        /* Idle screen digits */

#define MMI_UCM_DTMF_LEN                   (40)
#define MMI_UCM_END_TEXT_LEN                (50)
#define MMI_UCM_NOTIFY_TIMEOUT  (2000)

#define MMI_UCM_CALL_COST_UNIT_DIGITS                   (2)       
#define MMI_UCM_CALL_COST_COST_DIGITS                   (10)  

typedef enum
{
    MMI_UCM_NONE = 0,
    MMI_UCM_RING_TONE,
    MMI_UCM_WAITING_TONE,
    MMI_UCM_INCOMING_TONE_TOTAL
} mmi_ucm_incoming_tone_enum;

typedef enum
{
    MMI_UCM_NONE_ORIGIN = 0,
    MMI_UCM_MO_ORIGIN,
    MMI_UCM_MT_ORIGIN,
    MMI_UCM_CALL_ORIGIN_TOTAL
} mmi_ucm_call_origin_enum;

typedef enum
{
    MMI_UCM_IDLE_PROCESS_STATE = 0,
    MMI_UCM_WAIT_PROCESS_STATE,
    MMI_UCM_DO_PROCESS_STATE,
    MMI_UCM_COMP_PROCESS_STATE,
    MMI_UCM_PROCESS_STATE_TOTAL
} mmi_ucm_process_state_enum;

typedef enum
{
    MMI_UCM_ENTRY_MENU = 0,
    MMI_UCM_ENTRY_SEND_KEY,
    MMI_UCM_ENTRY_CENTER_KEY,
    MMI_UCM_ENTRY_DIAL_CALL_TYPE_TOTAL
} mmi_ucm_entry_dial_call_type_enum;

typedef struct
{
    S16 call_id;
    mmi_ucm_remote_info_struct remote_info;
    mmi_ucm_call_origin_enum call_origin;
    mmi_ucm_module_origin_enum module_id; /* the module that initializes the call */
    l4c_source_id_enum l4c_source; /* information that needs UCM to bypass to L4C */
    mmi_ucm_process_state_enum proc_state;
    mmi_ucm_act_opcode_enum act_type;
    MYTIME start_time;
    MYTIME end_time;
} mmi_ucm_call_entry_struct;

typedef struct
{
    S16 group_id;
    mmi_ucm_call_type_enum call_type;
    mmi_ucm_call_state_enum call_state;
    mmi_ucm_call_entry_struct call_info[MMI_UCM_MAX_NUM_INDEX];
    U8 num_call;
} mmi_ucm_group_entry_struct;

typedef struct
{
    mmi_ucm_group_entry_struct group_info[MMI_UCM_MAX_NUM_TAB];
    U8 num_group;
} mmi_ucm_call_list_struct;

typedef struct
{
    S32 group_index;
    S32 call_index;
} mmi_ucm_index_info_struct;

typedef struct
{
    U8 disp_dtmf[(MMI_UCM_DTMF_LEN + 1) * ENCODING_LENGTH];   /* 80 unicode + 2 bytes null terminator. input and display dtmf for category screen */
    U8 input_dtmf[(MMI_UCM_DTMF_LEN + 1)];                    /* 40 ascii + 1 byte null terminator. actual inputted dtmf for VoIP RTP */
    S32 hilite_tab;
    S32 hilite_index;
    S32 hilite_multi_held_index;
    S32 no_rcode_count; /* do not send result code for how many times */
    mmi_ucm_index_info_struct index_list[MMI_UCM_MAX_NUM_TAB * MMI_UCM_MAX_NUM_INDEX];
    mmi_ucm_act_opcode_enum curr_action;
    mmi_ucm_module_origin_enum curr_module;
    mmi_ucm_l4c_info_struct l4c_info; /* information that needs UCM to bypass to L4C */
    mmi_ucm_incoming_tone_enum play_tone;
    mmi_ucm_nw_status_enum nw_service_status;
    mmi_ucm_dtmf_struct dtmf;
    mmi_ucm_entry_dial_call_type_enum entry_type;
    FuncPtr  sendkey_hdlr;
    FuncPtr  centerkey_hdlr;
    MMI_BOOL is_ring_after_vibra;
    MMI_BOOL is_speech;
    MMI_BOOL is_loud;
    MMI_BOOL is_mute;
    MMI_BOOL is_dtmf;
    MMI_BOOL is_delay_ciev;
    MMI_BOOL is_bgs_selected;
    MMI_BOOL is_ringtone_suppress;
    MMI_BOOL is_dtmf_start;
} mmi_ucm_call_misc_struct;

typedef struct
{
    MYTIME  call_duration;
    U8 *disp_msg;
    U16 image_id;
    U16 tone_id;
} mmi_ucm_call_end_struct;

typedef struct
{
    U16 title_string;
    U16 body_string; /* string ID */
    U8* body_string_pointer; /* string pointer */
    U16 animation_image;
    U16 lsk_string;
    FuncPtr lsk_funcPtr;
    U16 rsk_string;
    FuncPtr rsk_funcPtr;
    FuncPtr send_funcPtr;
    FuncPtr end_funcPtr;
} mmi_ucm_proc_scr_struct;

typedef struct
{
    mmi_ucm_id_info_struct uid_info;
    U16 symbol[(MMI_UCM_CALL_COST_UNIT_DIGITS + 1)];
    U16 cost[(MMI_UCM_CALL_COST_COST_DIGITS + 1)];
} mmi_ucm_call_cost_cntx_struct;

typedef struct
{
    mmi_ucm_call_list_struct call_list;
    mmi_ucm_call_misc_struct call_misc;
    mmi_ucm_dial_info_struct mo_info;
    mmi_ucm_ring_info_struct mo_mt_display; /* Information for MO and MT call screen */
    mmi_ucm_proc_scr_struct proc_scr;
    mmi_ucm_display_cnf_struct cnf_scr;
    mmi_ucm_call_end_struct call_end;
    mmi_ucm_auto_redial_struct auto_redial;
    mmi_ucm_call_cost_cntx_struct call_cost;
} mmi_ucm_cntx_struct;

extern mmi_ucm_cntx_struct *g_ucm_p;
extern const U16 mmi_ucm_idle_screen_digits[MMI_UCM_SCREEN_DIGITS];

/* UCMMain.c */
extern void mmi_ucm_init_context(void);
extern void mmi_ucm_init_highlight_handler(void);
extern void mmi_ucm_init_hint_handler(void);
extern void mmi_ucm_init_protocol_handler(void);
extern void mmi_ucm_reset_group_entry(S32 group_index);
extern void mmi_ucm_reset_call_entry(S32 group_index, S32 call_index);
extern void mmi_ucm_reset_index_list(void);
extern void mmi_ucm_outgoing_call_sendkey(void);
extern void mmi_ucm_outgoing_call_endkey(void);
extern void mmi_ucm_incoming_call_sendkey(void);
extern void mmi_ucm_incoming_call_endkey(void);
extern MMI_BOOL mmi_ucm_incoming_call_show_option(void);
extern void mmi_ucm_in_call_sendkey(void);
extern void mmi_ucm_in_call_endkey(void);
extern MMI_BOOL mmi_ucm_in_call_show_option(void);
extern MMI_BOOL mmi_ucm_dial_option(void);
extern MMI_BOOL mmi_ucm_answer_option(void);
extern MMI_BOOL mmi_ucm_deflect_option(void);
extern MMI_BOOL mmi_ucm_replace_option(void);
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
extern MMI_BOOL mmi_ucm_redial_from_other_sim_option(void);
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */
extern MMI_BOOL mmi_ucm_end_all_active_option(void);
extern MMI_BOOL mmi_ucm_end_all_held_option(void);
extern MMI_BOOL mmi_ucm_bk_sound_incoming_option(void);
extern MMI_BOOL mmi_ucm_hold_single_option(void);
extern MMI_BOOL mmi_ucm_hold_single_check(S32 index);
extern MMI_BOOL mmi_ucm_hold_conference_option(void);
extern MMI_BOOL mmi_ucm_hold_conference_check(S32 index);
extern MMI_BOOL mmi_ucm_retrieve_single_option(void);
extern MMI_BOOL mmi_ucm_retrieve_single_check(S32 index);
extern MMI_BOOL mmi_ucm_retrieve_conference_option(void);
extern MMI_BOOL mmi_ucm_retrieve_conference_check(S32 index);
extern MMI_BOOL mmi_ucm_swap_option(void);
extern MMI_BOOL mmi_ucm_swap_check(S32 index);
extern MMI_BOOL mmi_ucm_conference_option(void);
extern MMI_BOOL mmi_ucm_conference_check(S32 index);
extern MMI_BOOL mmi_ucm_split_option(void);
extern MMI_BOOL mmi_ucm_end_single_option(void);
extern MMI_BOOL mmi_ucm_end_conference_option(void);
extern MMI_BOOL mmi_ucm_end_conference_check(S32 index);
extern MMI_BOOL mmi_ucm_end_all_option(void);
extern MMI_BOOL mmi_ucm_transfer_option(void);
extern MMI_BOOL mmi_ucm_transfer_check(S32 index);
extern MMI_BOOL mmi_ucm_new_call_option(void);
extern MMI_BOOL mmi_ucm_phonebook_option(void);
extern MMI_BOOL mmi_ucm_sms_option(void);
extern MMI_BOOL mmi_ucm_sound_recorder_option(void);
extern MMI_BOOL mmi_ucm_bk_sound_in_call_option(void);
extern MMI_BOOL mmi_ucm_loud_option(void);
extern MMI_BOOL mmi_ucm_mute_option(void);
extern MMI_BOOL mmi_ucm_dtmf_option(void);
extern MMI_BOOL mmi_ucm_swap_bt_audio_path_option(void);
extern MMI_BOOL mmi_ucm_connect_bt_default_headset_option(void);
extern MMI_BOOL mmi_ucm_ctm_option(void);
extern void mmi_ucm_dial_action(void);
extern void mmi_ucm_hold_and_dial_action(void);
extern void mmi_ucm_accept_action(void);
extern void mmi_ucm_hold_and_accept_action(void);
extern void mmi_ucm_hold_action(void);
extern void mmi_ucm_hold_action_with_index(S32 group_index);
extern void mmi_ucm_retrieve_action(void);
extern void mmi_ucm_retrieve_action_with_index(S32 group_index);
extern void mmi_ucm_swap_action(void);
extern void mmi_ucm_swap_action_with_index(S32 current_index, S32 assign_index);
extern void mmi_ucm_conference_action(void);
extern void mmi_ucm_conference_action_with_index(S32 current_index, S32 assign_index);
extern void mmi_ucm_split_action(void);
extern void mmi_ucm_split_action_with_index(S32 group_index, S32 call_index);
extern void mmi_ucm_deflect_action(void);
extern void mmi_ucm_deflect_action_with_number(PU8 number);
extern void mmi_ucm_transfer_action(void);
extern void mmi_ucm_explict_call_transfer_action(void);
extern void mmi_ucm_end_single_action(void);
extern void mmi_ucm_end_single_action_with_index(S32 group_index, S32 call_index);
extern void mmi_ucm_end_conference_action(void);
extern void mmi_ucm_end_conference_action_with_index(S32 group_index);
// extern void mmi_ucm_end_all_action(void);
extern void mmi_ucm_end_all_action_with_type(mmi_ucm_call_type_enum call_type);
extern void mmi_ucm_end_active_and_retrieve_action(void);
extern void mmi_ucm_end_active_and_retrieve_action_with_index(S32 group_index);
extern void mmi_ucm_end_active_and_accept_action(void);
extern void mmi_ucm_end_all_and_accept_action(void);
extern void mmi_ucm_auto_quick_end(void);
extern void mmi_ucm_end_all_held_action(void);
extern void mmi_ucm_end_all_active_action(void);
extern void mmi_ucm_auto_reject_action_with_index(S32 group_index, S32 call_index);
extern void mmi_ucm_release_action(void);
extern void mmi_ucm_force_release_action(void);
extern void mmi_ucm_log_call_history(S32 group_index, S32 call_index, MMI_BOOL is_connect);
extern void mmi_ucm_log_call_duration(S32 group_index, S32 call_index);

/* UCMUtil.c */
extern S32 mmi_ucm_get_outgoing_group(mmi_ucm_call_type_enum call_type, mmi_ucm_index_info_struct *index_list);
extern S32 mmi_ucm_get_incoming_group(mmi_ucm_call_type_enum call_type, mmi_ucm_index_info_struct *index_list);
extern S32 mmi_ucm_get_active_group(mmi_ucm_call_type_enum call_type, MMI_BOOL single_only, mmi_ucm_index_info_struct *index_list);
extern S32 mmi_ucm_get_held_group(mmi_ucm_call_type_enum call_type, MMI_BOOL single_only, mmi_ucm_index_info_struct *index_list);
extern MMI_BOOL mmi_ucm_is_busy(void);
extern MMI_BOOL mmi_ucm_is_crss(mmi_ucm_call_type_enum call_type, U8 *num_uri);
extern MMI_BOOL mmi_ucm_is_sos_number(mmi_ucm_call_type_enum call_type, U8 *num_uri);
extern MMI_BOOL mmi_ucm_is_sos_in_call_list(void);
extern MMI_BOOL mmi_ucm_is_sos_wait_dial(void);
extern MMI_BOOL mmi_ucm_emergency_call_present(void);
extern S32 mmi_ucm_get_process_state(mmi_ucm_process_state_enum proc_state, mmi_ucm_index_info_struct *index_list);
extern S32 mmi_ucm_set_process_state(S32 group_index, S32 call_index, mmi_ucm_process_state_enum old_state, mmi_ucm_process_state_enum new_state);
extern U16 mmi_ucm_get_act_rsp_string_id(mmi_ucm_act_opcode_enum action);
extern void mmi_ucm_search_call_list(mmi_ucm_call_info_struct call_list, mmi_ucm_index_info_struct *index_list);
extern void mmi_ucm_sync_call_state_to_headset(void);
extern void mmi_ucm_play_inband_tone(void);
extern void mmi_ucm_stop_inband_tone(void);
extern void mmi_ucm_play_incoming_tone(void);
extern void mmi_ucm_stop_incoming_tone(void);
#ifdef __MMI_CONNECT_NOTICE__
extern void mmi_ucm_play_connect_notice(void);
#endif /* __MMI_CONNECT_NOTICE__ */ 
extern void mmi_ucm_play_ringtone(void);
extern void mmi_ucm_stop_ringtone(void);
extern void mmi_ucm_play_tone_with_text(void);
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
extern void mmi_ucm_play_tone_with_text_callback(mdi_result result);
#endif
extern void mmi_ucm_play_tone_after_vibration(void);
extern void mmi_ucm_play_waitingtone(void);
extern void mmi_ucm_stop_waitingtone(void);
extern S32 mmi_ucm_get_group_index_by_call_state(mmi_ucm_call_state_enum call_state);
extern S32 mmi_ucm_get_group_index_by_call_state_and_type(mmi_ucm_call_state_enum call_state, mmi_ucm_call_type_enum call_type);
extern MMI_BOOL mmi_ucm_get_index_by_id(mmi_ucm_id_info_struct* uid_info, mmi_ucm_index_info_struct* index);
extern void mmi_ucm_in_call_ssc_parse(void);
extern void mmi_ucm_make_voip_call_from_incall_dialer(void);
extern void mmi_ucm_make_voice_call_from_incall_dialer(void);
extern void mmi_ucm_make_voice_call_from_dtmf_editor(void);
extern void mmi_ucm_call_time_reminder(void);
extern MMI_BOOL mmi_ucm_check_gsm_number(S8 *strNumber);
extern MMI_BOOL mmi_ucm_check_if_scr_older(U16 check_scr, U16 base_scr);
extern U32 mmi_ucm_get_phb_call_type(mmi_ucm_call_type_enum ucm_call_type);
#ifdef __MMI_SIDEKEY_SUPPRESS_RING__
extern void mmi_ucm_suppress_incoming_tone(void);
extern void mmi_ucm_set_side_key_after_suppress_ring(void);
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_ucm_set_call_channel(mmi_ucm_call_type_enum ucm_call_type);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void mmi_ucm_set_sendkey_hdlr(FuncPtr sendkey_hdlr);
extern FuncPtr mmi_ucm_get_sendkey_hdlr(void);
extern void mmi_ucm_exec_sendkey_hdlr(void);
extern U8 mmi_ucm_get_error_tone(void);
extern void mmi_ucm_set_centerkey_hdlr(FuncPtr centerkey_hdlr);
extern FuncPtr mmi_ucm_get_centerkey_hdlr(void);
extern void mmi_ucm_exec_centerkey_hdlr(void);
extern MMI_BOOL mmi_ucm_is_file_valid(U16* file_path);
extern MMI_BOOL mmi_ucm_is_caller_video_sound(void* image_info);
extern MMI_BOOL mmi_ucm_is_pending_action(void);
extern void mmi_ucm_validate_start_time(void);
extern S32 mmi_ucm_get_call_index_by_call_id(mmi_ucm_call_entry_struct *call_list, U8 call_list_size, U8 call_id);

/* UCMUI.c */
extern void mmi_ucm_highlight_incoming_opt_answer(void);
extern void mmi_ucm_highlight_incoming_opt_deflect(void);
extern void mmi_ucm_highlight_incoming_opt_replace(void);
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
extern void mmi_ucm_highlight_incoming_opt_redial_from_other_sim(void);
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */
extern void mmi_ucm_highlight_incoming_opt_end_all_active(void);
extern void mmi_ucm_highlight_incoming_opt_end_all_held(void);
extern void mmi_ucm_highlight_incoming_opt_background_sound(void);
extern void mmi_ucm_highlight_incall_opt_hold_single(void);
extern void mmi_ucm_highlight_incall_opt_hold_conf(void);
extern void mmi_ucm_highlight_incall_opt_retrieve_single(void);
extern void mmi_ucm_highlight_incall_opt_retrieve_conf(void);
extern void mmi_ucm_highlight_incall_opt_swap(void);
extern void mmi_ucm_highlight_incall_opt_conf(void);
extern void mmi_ucm_highlight_incall_opt_split(void);    
extern void mmi_ucm_highlight_incall_opt_end_single(void);    
extern void mmi_ucm_highlight_incall_opt_end_conf(void);    
extern void mmi_ucm_highlight_incall_opt_end_all(void);    
extern void mmi_ucm_highlight_incall_opt_transfer(void);    
extern void mmi_ucm_highlight_incall_opt_new_call(void);
extern void mmi_ucm_highlight_incall_opt_phonebook(void);
extern void mmi_ucm_highlight_incall_opt_sms(void);
extern void mmi_ucm_highlight_incall_opt_sound_recorder(void);
extern void mmi_ucm_highlight_incall_opt_bkg_sound(void);
extern void mmi_ucm_highlight_incall_opt_mute(void);
extern void mmi_ucm_highlight_incall_opt_dtmf(void);
extern void mmi_ucm_highlight_newcall_opt_voice(void); 
extern void mmi_ucm_highlight_newcall_opt_voip(void);
extern void mmi_ucm_highlight_connect_last_bt_device(void);
extern void mmi_ucm_hint_connect_last_bt_device(U16 index);
extern void mmi_ucm_dtmf_key_down(void);
extern void mmi_ucm_dtmf_key_up(void);
extern void mmi_ucm_entry_save_phonebook(void);
extern void mmi_ucm_entry_in_call(void);
extern void mmi_ucm_exit_in_call(void);
extern void mmi_ucm_highlight_in_call_item(S32 index);
extern void mmi_ucm_tab_jump(S32 index);
extern void mmi_ucm_tab_prev(void);
extern void mmi_ucm_tab_next(void);
extern void mmi_ucm_handle_incoming_option(void);
extern void mmi_ucm_pre_entry_dtmf_editor(void);
extern void mmi_ucm_entry_dtmf_editor(void);
extern void mmi_voip_send_dtmf_start(void);
extern void mmi_ucm_entry_multi_held_call(void);
extern void mmi_ucm_entry_incall_option(void);
extern void mmi_ucm_entry_outgoing_call(void);
extern void mmi_ucm_exit_outgoing_call(void);
extern void mmi_ucm_entry_abort_outgoing_call(void);
extern void mmi_ucm_entry_outgoing_call_sublcd(void);
extern void mmi_ucm_exit_outgoing_call_sublcd(void);
extern void mmi_ucm_entry_incoming_call(void);
extern void mmi_ucm_exit_incoming_call(void);
extern void mmi_ucm_entry_incoming_call_sublcd(void);
extern void mmi_ucm_exit_incoming_call_sublcd(void);
extern void mmi_ucm_entry_incoming_call_static_sublcd(void);
extern void mmi_ucm_exit_incoming_call_static_sublcd(void);
extern void mmi_ucm_entry_incoming_call_option(void);
extern void mmi_ucm_set_sidekey(void);
extern void mmi_ucm_pre_entry_send_dtmp(void);
extern void mmi_ucm_entry_call_end(void);
extern void mmi_ucm_exit_call_end(void);
extern void mmi_ucm_call_end_timeout_handler(void);
extern void mmi_ucm_entry_voip_dialer_screen(void);
extern void mmi_ucm_entry_voice_dialer_screen(void);
extern void mmi_ucm_entry_dialer_option(void);
extern void mmi_ucm_set_mute(void);
extern void mmi_ucm_hint_mute(U16 index);
extern void mmi_ucm_hint_dtmf_in_call(U16 index);
extern void mmi_ucm_entry_new_call_opt(void);
extern void mmi_ucm_highlight_newcall_opt_voip(void);
extern void mmi_ucm_highlight_newcall_opt_voice(void);
extern void mmi_ucm_entry_transfer(void);
extern void mmi_ucm_transfer(void);
extern void mmi_ucm_replace(void);
extern void mmi_ucm_entry_deflect(void);
extern void mmi_ucm_deflect(void);
extern void mmi_ucm_go_back_screen_check(void);
extern void mmi_ucm_tab_highlight(void);
extern void mmi_ucm_add_incall_to_history(void);
extern U8 mmi_ucm_entry_confirm_delete_callback(void *in_param);
extern void mmi_ucm_entry_confirm(void);
extern void mmi_ucm_display_confirm(void);
extern void mmi_ucm_execute_confirm_hdlr(void);
extern void mmi_ucm_set_dtmf_in_call(void);
extern void mmi_ucm_pre_send_dtmf(void);
extern void mmi_ucm_add_processing_to_history(void);
extern void mmi_ucm_highlight_newcall_opt_dial(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_ucm_highlight_newcall_opt_sim2_dial(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void mmi_ucm_highlight_newcall_opt_save(void);
extern void mmi_ucm_set_loud_speaker(void);
extern void mmi_ucm_delete_common_screens(void);
extern void mmi_ucm_add_auto_redial_to_history(void);
extern void mmi_ucm_entry_auto_redial(void);
extern void mmi_ucm_auto_redial_timeout_handler(void);
extern void mmi_ucm_auto_redial_abort(void);
extern U8 mmi_ucm_auto_redial_delete_callback(void *in_param);
extern void mmi_ucm_highlight_switch_audio_path(void);
extern void mmi_ucm_highlight_ctm_connect(void);
extern void mmi_ucm_bt_set_audio_path(void);
extern void mmi_ucm_entry_marker(void);
extern void mmi_ucm_entry_in_call_sublcd(void);
extern void mmi_ucm_exit_in_call_sublcd(void);
extern void mmi_ucm_delete_sublcd_screens(void);
extern void mmi_ucm_app_entry_dial_option_internal(U8 *num_uri, mmi_ucm_callback_func_ptr callback_after_dial, void* callback_para);
extern void mmi_ucm_entry_call_type(void);
extern void mmi_ucm_highlight_call_type_voice(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_ucm_highlight_call_type_voice_sim2(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void mmi_ucm_highlight_call_type_voip(void);
extern void mmi_ucm_highlight_call_type_video(void);
extern void mmi_ucm_dial_option_make_call(void);
extern void mmi_ucm_entry_processing_screen(void);
extern void mmi_ucm_entry_dial_option_by_sendkey(void);
extern void mmi_ucm_dial_option_make_call_exec_callback(void);
extern void mmi_ucm_dial_option_unhide_menu_item(void);
extern void mmi_ucm_set_processing_parameter(
        U16 titleStr,
        U16 bodyStr,
        U16 animationImg,
        U16 lskStr,
        FuncPtr lskFunc,
        U16 rskStr,
        FuncPtr rskFunc,
        FuncPtr sendFunc,
        FuncPtr endFunc);

extern void mmi_ucm_set_processing_parameter_with_body_string_p(
        U16 titleStr,
        U8* bodyStrP,
        U16 animationImg,
        U16 lskStr,
        FuncPtr lskFunc,
        U16 rskStr,
        FuncPtr rskFunc,
        FuncPtr sendFunc,
        FuncPtr endFunc);

#ifdef __MMI_BG_SOUND_EFFECT__
extern void mmi_ucm_cancel_bgs_effect_select(void);
extern void mmi_ucm_entry_bgs_effect_select(void);
extern void mmi_ucm_bgs_effect_highlight_hdlr(S32 index);
extern void mmi_ucm_bgs_effect_select(void);
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
extern void mmi_ucm_redial_from_other_sim(void);
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */

/* UCMSetting.c */
extern void mmi_ucm_highlight_call_history(void);
extern void mmi_ucm_highlight_general_call_setting(void);
extern void mmi_ucm_highlight_general_call_setting_more(void);
extern void mmi_ucm_entry_call_center(void);
extern void mmi_ucm_entry_call_general_setting(void);
extern void mmi_ucm_entry_call_general_setting_more(void);

#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_ucm_highlight_general_call_setting_sim1(void);
extern void mmi_ucm_entry_call_general_setting_sim1(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* UCM_PROT_H */ 


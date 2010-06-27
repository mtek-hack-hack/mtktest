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
 * SoundRecorderProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
#ifndef _SOUND_RECORDER_PROT_H
#define _SOUND_RECORDER_PROT_H
#include "MMIDataType.h"

#ifdef __MMI_SOUND_RECORDER__
extern void populateSoundRecorderMenu(void);
extern void InitSoundRecorderApp(void);
extern void mmi_sndrec_entry_in_idle(void);
extern void mmi_sndrec_entry_in_call(void);
extern void mmi_sndrec_entry_main(void);
extern void mmi_sndrec_hightlight_main(void);
extern void mmi_sndrec_entry_record_in_sms(U16* file_path, U32 max_file_size, void(*callbackfuc)(BOOL result, U16* filepath));
extern void mmi_sndrec_send_sms_req(void);
#ifdef __MMI_SOUND_RECORDER_STYLE_X__
extern void mmi_sndrec_highlight_list(void);
extern void mmi_sndrec_entry_style_x_main(void);
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
extern void mmi_sndrec_create_sound_folder(void);
extern BOOL mmi_sndrec_check_dest_folder(U8 drv_letter);
extern void mmi_sndrec_get_new_file_name(UI_string_type filename);
extern void mmi_sndrec_get_new_file(UI_string_type filename, UI_string_type fullname);
extern void mmi_sndrec_init_file_list(void);
extern void mmi_sndrec_get_full_path(S16 drv_letter);
extern BOOL mmi_sndrec_is_file_exist(void);

extern void mmi_sndrec_entry_option(void);

extern void mmi_sndrec_exit_hdlr(void);
extern void mmi_sndrec_set_interrupt_hdlr(void);
extern BOOL mmi_sndrec_check_usb_mode(void);
extern void mmi_sndrec_entry_record(void);
extern void mmi_sndrec_hightlight_record(void);
extern void mmi_sndrec_entry_record_paused(void);
extern void mmi_sndrec_record_stopped_hdlr(void);
extern void mmi_sndrec_record_disk_full_hdlr(void);
extern void mmi_sndrec_entry_edit_name(void);
extern void mmi_sndrec_entry_abort_query(void);
extern void mmi_sndrec_abort_file(void);
extern void mmi_sndrec_send_record_req(void);

extern void mmi_sndrec_entry_play(void);
extern void mmi_sndrec_hightlight_play(void);
extern void mmi_sndrec_entry_play_paused(void);
extern void mmi_sndrec_send_play_req(void);

extern void mmi_sndrec_entry_append(void);
extern void mmi_sndrec_hightlight_append(void);
extern void mmi_sndrec_send_append_req(void);

extern void mmi_sndrec_entry_rename_option(void);
extern void mmi_sndrec_entry_save(void);
extern void mmi_sndrec_hightlight_save(void);
extern void mmi_sndrec_hightlight_input_method(void);

extern void mmi_sndrec_hightlight_delete(void);
extern void mmi_sndrec_hightlight_delete_all(void);
extern void mmi_sndrec_hightlight_settings(void);

extern void mmi_sndrec_entry_inline_edit(void);
extern void mmi_sndrec_exit_inline_edit(void);
extern void mmi_sndrec_inline_edit_hightlight_hdlr(S32 index);

extern void mmi_sndrec_init_settings(void);
extern void mmi_sndrec_settings_pre_save(void);
extern void mmi_sndrec_entry_settings_save_query(void);
extern void mmi_sndrec_exit_settings_save_query(void);
extern void mmi_sndrec_get_settings(void);

extern void mmi_sndrec_set_sidekey_handler(void);
extern void mmi_sndrec_error_hdlr(S32 cause);
extern void mmi_sndrec_delete_name_editor_history_nodes(void);
extern void mmi_sndrec_delete_history_nodes(U16 screenId);
extern void mmi_sndrec_go_back_2_history(void);

extern void mmi_sndrec_auto_record_init(void);
extern void mmi_sndrec_auto_record_change_setting(S32 vm_support, S32 auto_record);
extern void mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id, MMI_BOOL speech_on);
extern MMI_BOOL mmi_sndrec_auto_record_is_on(void);
extern S32 mmi_sndrec_get_datarate(void);

/* Msg Handler */
extern MMI_ID_TYPE mmi_sndrec_get_res_string(U8 result);
extern U32 mmi_sndrec_get_duration_ticks(void);
extern void mmi_sndrec_init_duration(void);
extern void mmi_sndrec_start_duration(void);
extern void mmi_sndrec_update_duration(void);
extern BOOL mmi_sndrec_start_record(UI_string_type filename, U8 format, U8 quality);
extern BOOL mmi_sndrec_start_record_with_limit(UI_string_type filename, U8 format, U8 quality, U32 size_limit, U32 time_limit);
extern U8 mmi_sndrec_get_record_format(U8 format);
extern BOOL mmi_sndrec_start_play(UI_string_type filename);
extern void mmi_sndrec_stop_play(void);
extern void mmi_sndrec_stop_record(void);
extern void mmi_sndrec_pause(void);
extern void mmi_sndrec_resume(void);
extern void mmi_sndrec_set_media_volume(U8 volume);
extern void mmi_sndrec_set_speech_volume(U8 volume);
extern void mmi_sndrec_entry_in_voip_call(void);
extern void mmi_sndrec_remove_file_ext(UI_string_type filename);
extern void mmi_sndrec_entry_save_query(void);
extern void mmi_sndrec_save_file_in_sms(void);
extern void mmi_sndrec_abort_file_in_sms(void);
extern MMI_BOOL mmi_sndrec_record_is_on(void);
extern void mmi_sndrec_auto_record_switch_sim2(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id, MMI_BOOL speech_on);

#endif /* __MMI_SOUND_RECORDER__ */ 

#endif /* _SOUND_RECORDER_PROT_H */ 


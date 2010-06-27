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
 * BGSoundProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef _MMI_BGSOUNDPROT_H
#define _MMI_BGSOUNDPROT_H

#include "MMI_features.h"

#ifdef __MMI_BG_SOUND_EFFECT__

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
extern void mmi_bgsnd_call_setup_init(void);
extern void mmi_bgsnd_highlight_call_setup(void);
extern void mmi_bgsnd_entry_call_setup(void);

extern void mmi_bgsnd_highlight_cs_status(void);
extern void mmi_bgsnd_hint_cs_status(U16 index);
extern void mmi_bgsnd_cs_status_toggle(void);

extern void mmi_bgsnd_highlight_cs_playback_setup(void);
extern void mmi_bgsnd_cs_playback_prepare_inline_data(void);
extern void mmi_bgsnd_entry_cs_playback_setup(void);
extern void mmi_bgsnd_exit_cs_playback_setup(void);
extern void mmi_bgsnd_cs_playback_repeat_hdlr(S32 index);
extern void mmi_bgsnd_cs_playback_fill_inline_item(void);
extern void mmi_bgsnd_cs_playback_save_confirm(void);
extern void mmi_bgsnd_cs_playback_save(void);
extern void mmi_bgsnd_cs_playback_abort(void);

extern void mmi_bgsnd_highlight_cs_effect_list(void);
extern void mmi_bgsnd_cs_effect_highlight_callback(void);
extern void mmi_bgsnd_cs_effect_highlight_hdlr(S32 index);
extern void mmi_bgsnd_entry_cs_effect_list(void);
extern void mmi_bgsnd_exit_cs_effect_list(void);
extern void mmi_bgsnd_cs_effect_stop_and_back(void);
extern void mmi_bgsnd_cs_effect_select_item(void);
extern void mmi_bgsnd_highlight_cs_ext_effect_select(void);
extern void mmi_bgsnd_highlight_cs_ext_effect_edit(void);
extern void mmi_bgsnd_highlight_cs_ext_effect_delete(void);
extern void mmi_bgsnd_highlight_cs_ext_effect_add(void);
extern void mmi_bgsnd_cs_ext_pre_entry_option(void);
extern void mmi_bgsnd_entry_cs_ext_effect_option(void);
extern void mmi_bgsnd_cs_ext_effect_select_item(void);
extern void mmi_bgsnd_cs_ext_effect_select_from_fmgr(void);
extern void mmi_bgsnd_cs_ext_effect_select_file_done(void *fullname, int is_short);
extern void mmi_bgsnd_cs_ext_effect_delete_confirm(void);
extern void mmi_bgsnd_cs_ext_effect_delete(void);

extern void mmi_bgsnd_util_prepare_effect_list(BOOL add_no_effect);
extern void mmi_bgsnd_util_prepare_ext_file_index(void);
extern void mmi_bgsnd_util_play_by_highlight_index(U16 index);
extern void mmi_bgsnd_util_play_file(U16 *full_path);
extern void mmi_bgsnd_util_read_setup_data(void);
extern void mmi_bgsnd_util_write_setup_data(void);
extern BOOL mmi_bgsnd_util_check_file_format(void *file_name);
extern void mmi_bgsnd_util_set_ext_effect_status(U16 index, BOOL state);
extern BOOL mmi_bgsnd_util_get_ext_effect_status(U16 index);
extern void mmi_bgsnd_util_stop_setup_play_sound(void);
extern void mmi_bgsnd_util_play_result(S32 result);
extern void mmi_bgsnd_go_back_2_history(void);

extern void mmi_bgsnd_call_init(void);

extern void mmi_bgsnd_entry_mo_call_list(void);
extern void mmi_bgsnd_mo_call_make_call(void);

extern void mmi_bgsnd_highlight_mt_call_effect(void);
extern void mmi_bgsnd_mt_call_list_highlight_hdlr(S32 index);
extern void mmi_bgsnd_pre_entry_mt_call_list(void);
extern void mmi_bgsnd_entry_mt_call_list(void);
extern void mmi_bgsnd_exit_mt_call_list(void);
extern void mmi_bgsnd_mt_call_answer(void);

extern void mmi_bgsnd_highlight_call_manage(void);
extern void mmi_bgsnd_pre_entry_call_manage(void);
extern void mmi_bgsnd_entry_call_manage(void);
extern void mmi_bgsnd_exit_call_manage(void);
extern void mmi_bgsnd_highlight_cm_status(void);
extern void mmi_bgsnd_hint_cm_status(U16 index);
extern void mmi_bgsnd_cm_status_toggle(void);
extern void mmi_bgsnd_highlight_cm_setting(void);
extern void mmi_bgsnd_cm_setting_prepare_inline_data(void);
extern void mmi_bgsnd_entry_cm_setting(void);
extern void mmi_bgsnd_exit_cm_setting(void);
extern void mmi_bgsnd_cm_setting_repeat_hdlr(S32 index);
extern void mmi_bgsnd_cm_setting_fill_inline_item(void);
extern void mmi_bgsnd_cm_setting_apply_change(void);
extern void mmi_bgsnd_highlight_cm_effect_list(void);
extern void mmi_bgsnd_cm_effect_highlight_hdlr(S32 index);
extern void mmi_bgsnd_entry_cm_effect_list(void);
extern void mmi_bgsnd_exit_cm_effect_list(void);
extern void mmi_bgsnd_cm_effect_apply_change(void);

extern void mmi_bgsnd_util_play_sound_in_call(void);
extern void mmi_bgsnd_util_play_by_highlight_index_in_call(U16 index);
extern void mmi_bgsnd_util_play_file_in_call(U16 *full_path);
extern BOOL mmi_bgsnd_util_check_ext_file_format(U16 index);
extern void mmi_bgsnd_util_calling_change_state(BOOL is_on);
#ifndef __UCM_SUPPORT__
extern void mmi_bgsnd_util_stop_play_sound(void);
#endif
extern void mmi_bgsnd_util_delete_cm_setting_screen(void);
extern void mmi_bgsnd_common_cm_stop_play_sound(void);

#ifdef __DRM_SUPPORT__
extern void mmi_bgsnd_util_ext_effect_check_forward_rule(U16 index, BOOL add_no_effect);
#endif

extern BOOL mmi_bgsnd_check_usb_mode(void);
extern void mmi_bgsnd_pre_entry_call_setup(void);

#endif /* __MMI_BG_SOUND_EFFECT__ */ 
#endif /* _MMI_BGSOUNDPROT_H */ 


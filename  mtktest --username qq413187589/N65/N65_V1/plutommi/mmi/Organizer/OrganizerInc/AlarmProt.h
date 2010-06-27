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
 * AlarmFramework.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements alarm scheduler for alarm, to do list, schedule power on/off and theme.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : AlarmProt.h

   PURPOSE     : Alarm application 

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : June 16,03

**************************************************************/

#ifndef _ALARMPROT_H
#define _ALARMPROT_H

#include "MMIDataType.h"
#include "DateTimeType.h"

extern void EntryAlmMenu(void);
extern void EntryAlmSaveConfirmation(void);
extern void HighlightAlmMenu(void);
extern void AlmPrepareInlineScreen(void);
extern void AlmStopHandler(void);
extern void AlmSnoozeHandler(void);
extern U8 mmi_alm_stop_alarm_by_delete_screen(void);
extern void AlmWriteToNvram(void);
extern void ExitAlmIndicationScreen(void);
extern void AlmActivateIndicator(void);
extern void AlmDeactivateIndicator(void);
extern void EntryAlmPowerOnConfirmation(void);
extern void EntryAlmEditScreen(void);
extern void AlmFillInlineEditStruct(void);
extern void ExitAlmEditScreen(void);
extern void AlmSaveInlineEdit(void);
extern BOOL AlmIsInlineEditorChanged(S32 index);
extern void ExitAlmSubLcdScreen(void);
extern U8 AlmIsAnyAlarmActivated(void);
extern void AlmHandleEndKey(void);
extern void mmi_alm_check_history_and_poweroff(void);
extern void AlmExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern void AlmReInitQueueCBH(void);
extern U8 AlmExpiryHandlerCB(U8 index, U16 *period, BOOL power_on);
extern void AlmInitNvram(void);
extern U8 AlmGetSnoozeInterval(U8 almIndex);

/* PMT PANKAJ START (added for alarm audio options support */
#ifdef __MMI_ALM_AUDIO_OPTIONS__

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
extern void mmi_alm_entry_aud_opt_tone(void);
extern void mmi_alm_exit_aud_opt_tone(void);
extern void mmi_alm_tone_setup_hilite_hdlr(S32 index);
extern void mmi_alm_entry_tone_setup_set_alarm_tone(void);
extern void mmi_alm_entry_tone_setup_ext_melody(void);
extern void mmi_alm_tone_setup_ext_melody_hilight_hdlr(S32 index);
extern void mmi_alm_tone_setup_ext_melody_option(void);
extern U8 mmi_alm_tone_setup_convert_empty_slot_menu_list(U8 idx);
extern void mmi_alm_entry_tone_setup_ext_melody_drv(void);
extern void mmi_alm_tone_setup_ext_melody_drv_select(void);
extern void mmi_alm_tone_setup_ext_melody_drv_select_callback(void *path, int is_short);
extern void mmi_alm_tone_setup_set_ring_tone_id(void);
extern void mmi_alm_tone_setup_delete_ext_melody(U16 ToneId);
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

extern void mmi_alm_display_popup(void);

extern void mmi_alm_entry_aud_opt_fmrdo(void);
extern void HighlightAlmInlineAudioOptions(S32 index);
extern void mmi_alm_aud_fmrdo_init_channe_list(void);
extern void mmi_alm_aud_fmrdo_play_alarm(U8 alarm_index, U8 volume);
extern void mmi_alm_entry_aud_opt_fmrdo_channel_list(void);

extern void mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr(S32 index);
extern void mmi_alm_aud_opt_fmrdo_highlight_hdlr(S32 index);
extern void mmi_alm_entry_aud_opt_fmrdo_channel_options(void);
extern void mmi_alm_fmrdo_channel_opt_highlight_hdlr(S32 index);
extern void mmi_alm_aud_opt_fmrdo_channel_opt_lsk_hdlr(void);

/* channel data editing */
extern void mmi_alm_aud_opt_fmrdo_channel_edit_highlight_hdlr(S32 index);
extern void mmi_alm_entry_aud_opt_fmrdo_channel_name_edit(void);
extern void mmi_alm_aud_opt_fmrdo_channel_edit_LSK(void);
extern void mmi_alm_entry_aud_opt_fmrdo_clear_channel_confirm(void);
extern void mmi_alm_aud_opt_fmrdo_channel_name_edit_opt_highlight_hdlr(S32 index);
extern void mmi_alm_fmrdo_channel_name_edit_option_LSK(void);
extern void mmi_alm_entry_fmrdo_clear_channel_confirm(void);
extern void mmi_alm_exit_fmrdo_clear_channel_confirm(void);
extern void mmi_alm_fmrdo_clear_channel_LSK(void);
extern void mmi_alm_entry_fmrdo_save_channel_confirm(void);
extern void mmi_alm_exit_fmrdo_save_channel_confirm(void);
extern void mmi_alm_fmrdo_save_channel_LSK(void);
extern void mmi_alm_fmrdo_save_channel_RSK(void);
extern void mmi_alm_aud_opt_fmrdo_channel_name_edit_option_LSK(void);
extern void mmi_alm_entry_fmrdo_channel_name_edit_option(void);
extern void mmi_alm_entry_fmrdo_prev_channel(void);
extern void mmi_alm_exit_fmrdo_prev_channel(void);

/* manual input functions */
extern void mmi_alm_entry_fmrdo_manual_input(void);
extern void mmi_alm_exit_fmrdo_manual_input(void);
extern void mmi_alm_fmrdo_manual_input_highlight_hdlr(S32 index);
extern void mmi_alm_fmrdo_manual_input_options(void);
extern void mmi_alm_entry_fmrdo_manual_input_options(void);
extern void mmi_alm_fmrdo_manual_input_opt_highlight_hdlr(S32 index);
extern void mmi_alm_fmrdo_manual_input_opt_lsk_hdlr(void);
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 
/* PMT PANKAJ END */

#endif /* _ALARMPROT_H */ 


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
 * Profiles_prot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Settings application function prototypes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Profiles_prot.h

   PURPOSE     : Settings application function prototypes

   REMARKS     : nil

   AUTHOR      : Ashima Bajaj

   DATE     : 

**************************************************************/

#ifndef _PIXCOM_PROFILESPROT_H
#define _PIXCOM_PROFILESPROT_H

#include "MMIDataType.h"

#include "custom_equipment.h"

extern BOOL mmi_profiles_is_device_profile(void);

extern void mmi_profiles_entry_main_screen(void);
extern void mmi_profiles_exit_main_screen(void);

extern void mmi_profiles_entry_options(void);

extern void mmi_profiles_entry_activate_profile(void);
extern void mmi_profiles_entry_activate_profile_by_id(U8 profileId);

extern void mmi_profiles_entry_customize(void);
extern void mmi_profiles_exit_customize(void);

extern void mmi_profiles_entry_volume_type(void);
extern void mmi_profiles_exit_volume_type(void);

extern void mmi_profiles_entry_alert_type(void);

extern void mmi_profiles_entry_ring_type(void);

#ifdef __MMI_CONNECT_NOTICE__
extern void mmi_profiles_entry_connect_notice(void);
#endif /* __MMI_CONNECT_NOTICE__ */ 

extern void GetProfileVolumeLevelHiliteIndex(S32);
extern void EntryScrProfilesCommonVolumeLevel(void);
extern void EntryScrProfilesCommonVolumeLevel1(void);
extern void ExitScrProfilesCommonVolumeLevel(void);

extern void mmi_profiles_entry_answering_mode(void);

#if !defined(HARDWARE_LED_NOT_SUPPORT)
extern void mmi_profiles_entry_status_LED(void);
extern void mmi_profiles_exit_status_LED(void);
#endif /* HARDWARE_LED_NOT_SUPPORT */ 

extern void mmi_profiles_entry_tone_setup(void);
extern U8   mmi_profiles_get_melody_list(U16 CurMelodyID, U16 *selecteditem);

extern void mmi_profiles_entry_ring_tone_list(void);
extern void mmi_profiles_exit_ring_tone_list(void);

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern void mmi_profiles_entry_card2_ring_tone_list(void);
extern void mmi_profiles_exit_card2_ring_tone_list(void);
extern void mmi_profiles_set_card2_ring_tone_id_callback(U8 ExtMelodyFlag, U16 ringTone);
extern void mmi_profiles_entry_card2_ring_tone_list_hdlr(void);
extern void mmi_profiles_entry_card2_message_tone(void);
extern void mmi_profiles_exit_card2_message_tone(void);
extern void mmi_profiles_entry_card2_message_tone_hdlr(void);
#endif

#ifdef __MMI_VIDEO_TELEPHONY__
extern void mmi_profiles_entry_video_call_ring_tone_list(void);
extern void mmi_profiles_exit_video_call_ring_tone_list(void);
extern void mmi_profiles_entry_video_call_tone_list_hdlr(void);
extern void mmi_profiles_set_video_call_tone_id_callback(U8 ExtMelodyFlag, U16 ringTone);
#endif

extern void mmi_profiles_entry_power_on_tone(void);
extern void mmi_profiles_exit_power_on_tone(void);

extern void mmi_profiles_entry_power_off_tone(void);
extern void mmi_profiles_exit_power_off_tone(void);

#ifdef __MMI_CLAMSHELL__
extern void HighlightProfilesCoverOpenToneSetup(void);
extern void mmi_profiles_entry_cover_open_tone(void);
extern void mmi_profiles_exit_cover_open_tone(void);

extern void HighlightProfilesCoverCloseToneSetup(void);
extern void mmi_profiles_entry_cover_close_tone(void);
extern void mmi_profiles_exit_cover_close_tone(void);
#endif /* __MMI_CLAMSHELL__ */ 

extern void mmi_profiles_entry_message_tone(void);
extern void mmi_profiles_exit_message_tone(void);

extern void mmi_profiles_entry_keypad_tone(void);

extern void mmi_profiles_entry_alarm_tone(void);
extern void mmi_profiles_exit_alarm_tone(void);

extern void mmi_profiles_entry_ring_tone_list_hdlr(void);
extern void mmi_profiles_set_ring_tone_id_count_id(void (*Func_Callback) (U8, U16));
extern void mmi_profiles_set_ring_tone_id_callback(U8 ExtMelodyFlag, U16 ringTone);

extern void mmi_profiles_Ext_melody_action_hdlr(void);
extern void mmi_profiles_Ext_melody_entry_menu(void);

extern void mmi_profiles_entry_power_on_tone_hdlr(void);
extern void mmi_profiles_entry_power_off_tone_hdlr(void);

#ifdef __MMI_CLAMSHELL__
extern void mmi_profiles_entry_cover_open_tone_hdlr(void);
extern void mmi_profiles_entry_cover_close_tone_hdlr(void);
#endif /* __MMI_CLAMSHELL__ */ 

extern void mmi_profiles_entry_message_tone_hdlr(void);
extern void mmi_profiles_entry_answering_mode_hdlr(void);

#if !defined(HARDWARE_LED_NOT_SUPPORT)
extern void mmi_profiles_entry_status_LED_hdlr(void);
#endif 
extern void mmi_profiles_entry_alarm_tone_hdlr(void);
extern void mmi_profiles_entry_volume_level_hdlr(void);
extern void mmi_profiles_entry_extra_tone(void);


extern void mmi_profiles_melody_list_highlight_hdlr(S32 index);
extern void GetCurrScreenHandlerfour(S32);
extern void GetCurrScreenHandlerfive(S32);
extern void GetCurrScreenHandlersix(S32 item_index);

/* profile confirm pop up*/
extern void mmi_profiles_set_query_popup(void (*fn_lsk) (void), void (*fn_rsk) (void));
extern void mmi_profiles_set_answering_mode_query_popup(void);
extern void mmi_profiles_set_extra_tone_query_popup(void);
extern void mmi_profiles_entry_query_popup(void);

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
extern void mmi_profiles_entry_intelligent_call_alert(void);
#endif 


extern void mmi_profiles_stop_tone_and_go_back(void);
extern void mmi_profiles_preview_play_tone(void);
extern void mmi_profiles_preview_stop_tone(void);
extern void mmi_profiles_vol_inc_dec_play_keypad_tone(void);
extern void mmi_profiles_show_alert_status_icon(void);

extern void mmi_profiles_preview_play_color_id(void);
extern void mmi_profiles_preview_stop_color_id(void);
extern void mmi_profiles_get_dynamic_tone_ids(void);
extern void mmi_profiles_stop_silent_profile_vibrate(void);

extern void mmi_profiles_entry_extra_tone_hdlr(void);
extern void mmi_profiles_set_alert_type_ring_hdlr(void);
extern void mmi_profiles_set_alert_type_vib_only_hdlr(void);
extern void mmi_profiles_set_alert_type_vib_and_ring_hdlr(void);
extern void mmi_profiles_set_alert_type_vib_then_ring_hdlr(void);
extern void mmi_profiles_set_alert_type_light_only_hdlr(void);

extern void mmi_profiles_set_ring_type_ascending_hdlr(void);
extern void mmi_profiles_set_ring_type_single_hdlr(void);
extern void mmi_profiles_set_ring_type_repeat_hdlr(void);

#ifdef __MMI_CONNECT_NOTICE__
extern void mmi_profiles_set_connect_notice_none_hdlr(void);
extern void mmi_profiles_set_connect_notice_tone_only_hdlr(void);
extern void mmi_profiles_set_connect_notice_vib_only_hdlr(void);
extern void mmi_profiles_set_connect_notice_tone_and_vib_hdlr(void);
#endif /* __MMI_CONNECT_NOTICE__ */ 

extern void mmi_profiles_set_key_pad_tone_silent_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_click_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_tone_hdlr(void);

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
extern void mmi_profiles_set_key_pad_tone_human1_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_human2_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_human3_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_human4_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_human5_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_human6_hdlr(void);
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

#if defined(__MMI_CUST_KEYPAD_TONE__)
extern void mmi_profiles_set_key_pad_tone_cust1_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_cust2_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_cust3_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_cust4_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_cust5_hdlr(void);
extern void mmi_profiles_set_key_pad_tone_cust6_hdlr(void);
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

extern void mmi_profiles_continue_volume_ring_tone(void *info);


/*Hint handlers*/

/*tone setup*/
extern void mmi_profiles_hint_hdlr_incoming_call(U16 index);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern void mmi_profiles_hint_hdlr_card2_incoming_call(U16 index);
#endif
#ifdef __MMI_VIDEO_TELEPHONY__
extern void mmi_profiles_hint_hdlr_video_call(U16 index);
#endif
extern void mmi_profiles_hint_hdlr_alarm_tone(U16 index);
extern void mmi_profiles_hint_hdlr_power_on_tone(U16 index);
extern void mmi_profiles_hint_hdlr_power_off_tone(U16 index);
#ifdef __MMI_CLAMSHELL__
extern void mmi_profiles_hint_hdlr_cover_open_tone(U16 index);
extern void mmi_profiles_hint_hdlr_cover_close_tone(U16 index);
#endif /* __MMI_CLAMSHELL__ */ 
extern void mmi_profiles_hint_hdlr_message_tone(U16 index);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern void mmi_profiles_hint_hdlr_card2_message_tone(U16 index);
#endif
extern void mmi_profiles_hint_hdlr_key_pad_tone(U16 index);

/*volume*/
extern void mmi_profiles_hint_hdlr_ring_tone_volume(U16 index);
extern void mmi_profiles_hint_hdlr_key_tone_volume(U16 index);

extern void mmi_profiles_hint_hdlr_alert_type(U16 index);
extern void mmi_profiles_hint_hdlr_ring_type(U16 index);

#ifdef __MMI_CONNECT_NOTICE__
extern void mmi_profiles_hint_hdlr_connect_notice(U16 index);
#endif 

#if !defined(HARDWARE_LED_NOT_SUPPORT)
extern void mmi_profiles_hint_hdlr_status_LED(U16 index);
#endif 

/*highlight handler*/
extern void mmi_profiles_hilite_hdlr_key_pad_silent(void);
extern void mmi_profiles_hilite_hdlr_key_pad_click(void);
extern void mmi_profiles_hilite_hdlr_key_pad_tone(void);

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
extern void mmi_profiles_hilite_hdlr_key_pad_human1(void);
extern void mmi_profiles_hilite_hdlr_key_pad_human2(void);
extern void mmi_profiles_hilite_hdlr_key_pad_human3(void);
extern void mmi_profiles_hilite_hdlr_key_pad_human4(void);
extern void mmi_profiles_hilite_hdlr_key_pad_human5(void);
extern void mmi_profiles_hilite_hdlr_key_pad_human6(void);
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

#if defined(__MMI_CUST_KEYPAD_TONE__)
extern void mmi_profiles_hilite_hdlr_key_pad_cust1(void);
extern void mmi_profiles_hilite_hdlr_key_pad_cust2(void);
extern void mmi_profiles_hilite_hdlr_key_pad_cust3(void);
extern void mmi_profiles_hilite_hdlr_key_pad_cust4(void);
extern void mmi_profiles_hilite_hdlr_key_pad_cust5(void);
extern void mmi_profiles_hilite_hdlr_key_pad_cust6(void);
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

extern void mmi_profiles_hilite_hdlr_ring_tone_volume(void);
extern void mmi_profiles_hilite_hdlr_key_tone_volume(void);

extern void mmi_profiles_hilite_hdlr_ring_type_single(void);
extern void mmi_profiles_hilite_hdlr_ring_type_repeat(void);
extern void mmi_profiles_hilite_hdlr_ring_type_ascending(void);

#ifdef __MMI_CONNECT_NOTICE__
extern void mmi_profiles_hilite_hdlr_connect_notice(void);
extern void mmi_profiles_hilite_hdlr_connect_notice_none(void);
extern void mmi_profiles_hilite_hdlr_connect_notice_tone_only(void);
extern void mmi_profiles_hilite_hdlr_connect_notice_vib_only(void);
extern void mmi_profiles_hilite_hdlr_connect_notice_tone_and_vib(void);
#endif /* __MMI_CONNECT_NOTICE__ */ 

/*alert type*/
extern void mmi_profiles_hilite_hdlr_alert_type(void);
extern void mmi_profiles_hilite_hdlr_alert_type_ring(void);
extern void mmi_profiles_hilite_hdlr_alert_type_vib_only(void);
extern void mmi_profiles_hilite_hdlr_alert_type_vib_and_ring(void);
extern void mmi_profiles_hilite_hdlr_alert_type_vib_then_ring(void);
extern void mmi_profiles_hilite_hdlr_alert_type_light_only(void);

extern void mmi_profiles_hilite_hdlr_options(void);
extern void mmi_profiles_hilite_hdlr_activate(void);
extern void mmi_profiles_hilite_hdlr_customize(void);
extern void mmi_profiles_hilite_hdlr_volume(void);
extern void mmi_profiles_hilite_hdlr_ring_type(void);
extern void mmi_profiles_hilite_hdlr_answering_mode(void);

#if !defined(HARDWARE_LED_NOT_SUPPORT)
extern void mmi_profiles_hilite_hdlr_status_LED(void);
#endif 

/*tone setup*/
extern void mmi_profiles_hilite_hdlr_tone_setup(void);
extern void mmi_profiles_hilite_hdlr_ring_tone(void);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern void mmi_profiles_hilite_hdlr_card2_ring_tone(void);
#endif
#ifdef __MMI_VIDEO_TELEPHONY__
extern void mmi_profiles_hilite_hldr_video_call_tone(void);
#endif
extern void mmi_profiles_hilite_hdlr_power_on_tone(void);
extern void mmi_profiles_hilite_hdlr_power_off_tone(void);
extern void mmi_profiles_hilite_hdlr_message_tone(void);
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
extern void mmi_profiles_hilite_hdlr_card2_message_tone(void);
#endif
extern void mmi_profiles_hilite_hdlr_key_pad_tone_setup(void);
extern void mmi_profiles_hilite_hdlr_alarm_tone(void);
extern void mmi_profiles_hilite_hdlr_extra_tone(void);

extern void mmi_profiles_hilite_hdlr_headset_mode(void);
#ifdef __MMI_BT_PROFILE__
extern void mmi_profiles_hilite_hdlr_bt_mode(void);
#endif 
extern void mmi_profiles_hilite_hdlr_indoor_mode(void);
extern void mmi_profiles_hilite_hdlr_outdoor_mode(void);
extern void mmi_profiles_hilite_hdlr_meeting_mode(void);
extern void mmi_profiles_hilite_hdlr_general_mode(void);

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
extern void mmi_profiles_hilite_hdlr_intelligent_call_alert(void);
extern void mmi_profiles_hint_hdlr_intelligent_call_alert(U16 index);
extern void mmi_profiles_hilite_hdlr_intelligent_call_alert_on(void);
extern void mmi_profiles_hilite_hdlr_intelligent_call_alert_off(void);
extern void mmi_profiles_set_intelligent_call_alert_on_hdlr(void);
extern void mmi_profiles_set_intelligent_call_alert_off_hdlr(void);
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

#endif /* _PIXCOM_PROFILESPROT_H */ 


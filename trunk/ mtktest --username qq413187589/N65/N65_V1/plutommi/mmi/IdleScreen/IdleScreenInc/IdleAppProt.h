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
 * IdleAppProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Idle screen prototype header
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

/**********************************************************************************
   Filename:      idleapp_prot.h
   Author:
   Date Created:  September-13-2002
   Contains:      Idle screen application
**********************************************************************************/

#ifndef __IDLEAPP_PROT_H__
#define __IDLEAPP_PROT_H__

/* Lisen 01252005 */
extern U8 IdleScreenEmergencyCallCheckNKeypadLock(KEYBRD_MESSAGE *eventKey);

extern void EntryIdleScreen(void);
extern void ExitIdleScreen(void);

extern void HandleIdleScreenDigitEntry(void);
extern void IdleScreenDigitHandler(void);
extern void ExitIdleScreenDigitHandler(void);
extern void IdleDialPadSavePhoneBook(void);
extern void IdleDialPadCall(void);
extern void IdleSetKeyPadLockFlag(void);

/* U16 AutoKeyPadLockTime(void); */
extern void IdleSetStatusIcon(S16);
extern void IdleResetStatusIcon(S16);

/* void IdleEnterNameScreen(void); */
extern void IdleCallSpeedDialOnLongPress(void);
extern void IdleAbbrevDialling(void);
extern void IdleShowScrInvalidLocation(void);

extern void IdleShowScrNoPhoneNumEntry(void);

extern void IdleShowScrNoSpeedDialNumSaved(void);

extern void IdleHandlePoundKeyForKeypadLock(void);
extern void IdleHandleKeypadLockProcess(void);

extern void SearchingSrceenTimeOutHandler(void);

extern void IdleScreenSaverGroupKeyHandler(void);
extern void ExitScreenSaver(void);
extern void EntryIdleSetScreenSaver(void);

extern void LeavePartialOnScreenSaverIfOk(void);
extern void EnterPartialOnScreenSaverIfOk(void);
extern void RedrawPartialOnScreenSaverIfOk(void);
extern void EntryPartialOnScreenSaver(void);

extern void IdleToggleProfile(void);
extern void IdleStopToggleTimer(void);
extern pBOOL IsChineseSet(void);
extern pBOOL IsEnglishSet(void);
extern pBOOL IsTrChineseSet(void);
extern pBOOL IsSmChineseSet(void);
extern void SubLCDIdleScreen(void);
extern void ShowIdleAppSubLcd(void);
extern void EntryIdleAppSubLcdWithErrorMsg(U8 *message, U16 message_icon, U8 *history_buffer);

extern void IdleDisableLongPress(void);
extern void IdleRefreshServiceIndicationArea(void);
extern void IdleRSKPressOnScreenSaver(void);

extern void IdleSetLRKey(void);
extern void RedrawIdleScreen(void);

extern void ExitSubLCDIdleScr(void);

/* revised idle screen API */
extern void mmi_idle_dummy_key_handler(void);
extern void mmi_idle_start_keypad_lock(void);
extern void mmi_idle_set_keypad_lock_string(void);
extern pBOOL mmi_idle_is_on_idle_screen(void);
extern pBOOL mmi_idle_is_screensaver_running(void);
extern void mmi_idle_generic_keypad_lock_screen_exit_hdlr(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_idle_pen_block(void);
#endif
extern void mmi_idle_notify_bootup_ready_to_wap(void);
extern void mmi_idle_notify_bootup_ready_to_l4c(void);
extern void mmi_idle_notify_bootup_ready_to_certman(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_idle_notify_dual_sim_status_to_wap(void);
#endif

extern void EntryScrQuickAccessMenuLockKpad(void);
extern void EntryShctInIdle(void);
extern void PopulateCommonCategoryResources(void);

/* screen saver */
extern void mmi_scrsvr_lcd_sleepin_handler(void);
extern void mmi_scrsvr_lcd_sleepout_handler(void);

extern void mmi_idle_restart_keypad_lock_timer(void);
extern void mmi_idle_restart_screensaver_timer(void);

#ifdef __MMI_NITZ__
extern void mmi_idle_update_opname_from_nitz(void);
extern void mmi_idle_update_nitz_content(void);
extern pBOOL mmi_idle_check_nitz_display_validation(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_idle_update_sim2_nitz_content(void);
extern pBOOL mmi_idle_check_sim2_nitz_display_validation(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_NITZ__ */

#ifdef __MMI_SIMAP_SUPPORT__
extern void mmi_idle_entry_bt_access_profile_idle_screen(void);
#endif
extern MMI_BOOL mmi_idle_is_camp_on_chinese_network(U8 *plmn);
extern pBOOL mmi_idle_is_allow_to_display_song_name(void);
extern void mmi_idle_remove_dialer_screen_exit_handler(void);

extern void mmi_idle_key_event_backlight_check(void);
extern void mmi_idle_key_event_keypad_lock_check(KEYBRD_MESSAGE *eventKey);

#ifdef __MMI_OP01_WITH_WAP_KEY__
extern void mmi_idle_entry_internet_confirm(void);
#endif
extern void mmi_idle_delete_dialpad_from_history(void);
#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
extern MMI_BOOL mmi_idle_is_display_touch_shortcuts(void);
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_idle_entry_dual_sim_root_screen(void);
#endif

#ifdef __MMI_UCM__
extern void mmi_idle_highlight_dial_pad_option_dial(void);
extern void mmi_idle_highlight_dial_pad_option_save(void);

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
extern void mmi_idle_highlight_dial_pad_option_input(void);
extern void mmi_idle_highlight_dial_pad_option_mode(void);
extern void mmi_idle_entry_dial_voip_call(void);
extern void mmi_idle_set_dial_mode(U8 mode);
extern U8 mmi_idle_get_dial_mode(void);
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

extern void mmi_idle_entry_dial_selection(void);
extern void mmi_idle_entry_dial_pad_option(void);
#endif /* __MMI_UCM__*/

#endif /* __IDLEAPP_PROT_H__ */ 


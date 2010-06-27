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
 * MMI_features.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI keypad config function.
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

#ifndef _KEYBRD_H_
#define _KEYBRD_H_

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "FrameworkStruct.h"
#include "QueueGprot.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define TOTAL_KEYS GetMaxPresentAllKeys()       /* JL 040223 for 3 extra keys. 22 */

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern const U16 PresentAllKeys[];

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void ExecuteCurrKeyHandler(S16 keyCode, S16 keyType);    /* execute current key func handler */
extern void GetkeyInfo(U16 *keyCode, U16 *keyType); /* gives key code & key type of last key event */
extern void SetkeyInfo(U16 keyCode, U16 keyType);
extern FuncPtr GetKeyHandler(U16 keyCode, U16 keyType);
extern void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType);   /* key event handlers */

extern void SetGroupKeyHandler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType);    /* helper to register the same key handler for a group of key codes */
extern void ClearKeyHandler(U16 keyCode, U16 keyType);
extern void ClearAllKeyHandler(void);
extern void PowerAndEndKeyHandler(void);                /* power key & end key handler */

#ifdef __MMI_SUBLCD_MASTER_MODE__
extern void SwitchKeyFuncPtrs(void);
#endif

extern void ProcessKeyEvent(U32 MsgType, U16 DeviceKeyCode);

/* Max 2005/02/20 */
extern void InitProcessKeyEvent(void);
extern void InitKeypadBeforePWRON(void);
extern void KeyHandleBeforePWRON(void *paraBuff);
extern void ClearKeyEvents(void);
extern S16 GetHumanVoiceToneID(S16 MMIKeyCode);
extern U16 GetCurKeypadTone(void);
extern U16 GetKeypadTone(S16 KeyCode);
extern U8 SetCurKeypadTone(U16 KeyTone);
extern U8 GetKeypadDuration(S16 KeyCode);
extern void StopCurrentKeyPadTone(void);
extern U8 GetMaxPresentAllKeys(void);
extern U8 GetMaxPresentDigitsKeys(void);

extern void mmi_kbd_reset_key_state(U32 MsgType, U16 KeyMapIndex);
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);
extern mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void);
extern BOOL mmi_frm_kbd_is_tone_played(S16 key_code, S16 key_type);
extern void mmi_frm_kbd_reg_pre_key_hdlr(PsKeyProcessCBPtr func);
extern void mmi_frm_kbd_reg_post_key_hdlr(PsKeyProcessCBPtr func);
extern void mmi_frm_stop_keypad_tone(S16 key_code);
extern void mmi_frm_play_keypad_tone(S16 key_code);

extern void mmi_frm_set_key_handle_in_high_frequency(MMI_BOOL is_enable);

extern void mmi_frm_convert_process_key_event(U32 Keyevent, U16 DeviceKeyCode);

extern MMI_BOOL mmi_kbd_set_concurrent_mode(U32 mode);
extern U32 mmi_kbd_get_concurrent_mode(void);
extern U8 mmi_kbd_get_key_is_pressing_count(void);
extern S16 mmi_kbd_reverse_code(S16 mmi_key_code);

extern void mmi_frm_key_handle(void *paraBuff);
extern MMI_BOOL mmi_kbd_process_keyptr_change(void* new_key_ptr);

void mmi_frm_set_default_power_onoff_key(void);

extern MMI_BOOL mmi_frm_kbd_is_key_supported(S16 key_code);
extern U16 mmi_frm_get_idx_from_device_key_code(U16 DeviceKeyCode);

#ifdef __MMI_SUBLCD_MASTER_MODE__                                   /* moved from keybrd.c - by xd */
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
extern FuncPtr currKeyFuncPtrs_slave[MAX_KEYS][MAX_KEY_TYPE];
extern FuncPtr currKeyFuncPtrs_master[MAX_KEYS][MAX_KEY_TYPE];
#else
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
#endif /* __MMI_SUBLCD_MASTER_MODE__ */

#endif /* _KEYBRD_H_ */ 


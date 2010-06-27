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
 * QuickAccessMenuItem.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Contains functionality for Quick Access Menu Items
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

   FILENAME : QuickAccessMenuItem.c

   PURPOSE     : Contains functionality for Quick Access Menu Items

   REMARKS     :  KeyPad lock is implemented in this file rest
               options are put are under construction    

   AUTHOR      : Manish Vohra,Deepali

   DATE     : Feb 28, 2003

**************************************************************/

#include "MMI_include.h"

#include "QuickAccessMenuItem_def.h"
#include "MiscFunctions.h"
#include "wgui_status_icons.h"
#include "CallManagementGprot.h"
#include "QuickAccessMenuItemProt.h"
// #include "QuickAccessMenuItemsGdcl.h"
#include "SimDetectionGexdcl.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "ProfileGprots.h"
#ifdef __MMI_TOUCH_SCREEN__
#endif 
#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#endif 

#include "PhoneBookGprot.h"
#include "SimDetectionGprot.h"
#include "custom_util.h"
#include "gpioInc.h"

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "NetworkSetupDefs.h"
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

U8 isEmergencyCallDropped = 0;  /* Robin 1217 */

/* not treating as an array of characters these
   two are array of integers so length need not be 
   multiplied by ENCODING LENGTH */
U16 aligned_emgNumberArr[(EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH / 2];

S8 *emgNumberArr = (S8 *) & aligned_emgNumberArr;

/* To pass no to call management it is required to pass string */
/* S16 curDigit; */
U8 gEmerencyNoDialed = 0;


/*****************************************************************************
 * FUNCTION
 *  HandlePoundKeyForUnlock
 * DESCRIPTION
 *  This fn handle the press of
 *  Pound key , after RSK has been pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandlePoundKeyForUnlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(KEYPADUNLOCKEDMESSAGE_TIMER);
    g_keylock_context.gKeyPadLockFlag = 0;

    /* Lisen 02182005 */
#ifdef __MMI_KEYPADLOCK_WITH_KEYTONE__

#else 
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
#endif 

    playRequestedTone(SUCCESS_TONE);
    EntryScrKeyPadUnlockMessage();
#ifdef __MMI_TOUCH_SCREEN__
    ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_UNLOCK);
    UpdateStatusIcons();    /* 101805 ChangeStatusIconImage Calvin: ChangeStatusIconImage will not call UpdateStatusIcon */
#else /* __MMI_TOUCH_SCREEN__ */ 
    IdleResetStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrKeyPadUnlockMessage
 * DESCRIPTION
 *  Entry fn to show that Keypad has been unlocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrKeyPadUnlockMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(KPAD_SCR_UNLOCK_MESSAGE, ExitScrKeyPadUnlockMessage, NULL, NULL);

    ShowCategory64Screen(KPAD_SCR_UNLOCKED_MESSAGE_RUNNING_STR, IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE, 0);
    /* Start Timer */
    StartTimer(KEYPADUNLOCKEDMESSAGE_TIMER, KEYPAD_UNLOCK_SCR_TIMEOUT, GoBackHistory);

    SetGroupKeyHandler(DisplayIdleScreen, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);

    /* Set the Exit handler , called in case of async events ,when transient screen on display */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrKeyPadUnlockMessage
 * DESCRIPTION
 *  Exit function Key Pad Unlocked Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrKeyPadUnlockMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(KEYPADUNLOCKEDMESSAGE_TIMER);
    stopRequestedTone(SUCCESS_TONE);
}

/* Leo start 20050731 */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  ScrAfterPressingRSKTimeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ScrAfterPressingRSKTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_block();
    GoBackHistory();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* Leo end 20050731 */


/*****************************************************************************
 * FUNCTION
 *  EntryScrAfterPessingRSK
 * DESCRIPTION
 *  shows the screen after pressing RSK indicating
 *  messge " press # to unlock "
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrAfterPessingRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(KPAD_SCR_UNLOCK_HELP_MESSAGE, ExitScrAfterPessingRSK, NULL, NULL);

    /* Leo start 20050731 */
#ifdef __MMI_TOUCH_SCREEN__
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        ShowCategory264Screen(
            get_string(TOUCH_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR),
            get_image(IMG_TOUCH_SCR_PEN_CLICK_AREA),
            0,
            NULL,
            NULL);
    }
    else
    {
        ShowCategory264Screen(
            get_string(TOUCH_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR),
            get_image(IMG_TOUCH_SCR_PEN_CLICK_AREA),
        #ifdef __MMI_WGUI_CSK_ENABLE__
            IMG_CSK_DIAL_ICON,
        #else
            0,
        #endif
            NULL,
            NULL);
    }
    /* Start Timer */
    StartTimer(KEYPADUNLOCKEDHELPMESSAGE_TIMER, KEYPADUNLOCK_TIMEOUT, ScrAfterPressingRSKTimeout /* GoBackHistory */ );
#else /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    ShowCategory64Screen(KPAD_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR, IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE, 0);
#else 
    ShowCategory64Screen(KPAD_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR2, IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE, 0);
#endif 
    /* Start Timer */
    StartTimer(KEYPADUNLOCKEDHELPMESSAGE_TIMER, KEYPADUNLOCK_TIMEOUT, GoBackHistory);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* Leo end 20050731 */

    SetGroupKeyHandler(GoBackHistory, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);

#ifdef __MMI_TOUCH_SCREEN__
    /* SetKeyHandler(EntryScrAfterPessingRSK,KEY_SEND,KEY_EVENT_DOWN); */
    mmi_pen_unblock();
    SetKeyHandler(HandlePoundKeyForUnlock, KEY_POUND, KEY_EVENT_DOWN); //sc.wu HandlePoundKeyForUnlock press key #
#else /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
    /* SetKeyHandler(EntryScrAfterPessingRSK,KEY_RSK,KEY_EVENT_DOWN); */
    SetKeyHandler(HandlePoundKeyForUnlock, KEY_POUND, KEY_EVENT_DOWN);
#ifdef __MMI_SLIDE__    /* diamond, 2005/08/17 keypad lock for slide phone */
    SetKeyHandler(HandlePoundKeyForUnlock, KEY_LSK, KEY_EVENT_DOWN);
#endif 
#else /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 
    /* SetKeyHandler(EntryScrAfterPessingRSK,KEY_LSK,KEY_EVENT_DOWN); */
    SetKeyHandler(HandlePoundKeyForUnlock, KEY_STAR, KEY_EVENT_DOWN);
#ifdef __MMI_SLIDE__    /* diamond, 2005/08/17 keypad lock for slide phone */
    SetKeyHandler(HandlePoundKeyForUnlock, KEY_RSK, KEY_EVENT_DOWN);
#endif 
#endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 
#endif /* __MMI_TOUCH_SCREEN__ */ 
    playRequestedTone(SUCCESS_TONE);

    TurnOnBacklight(1);

}


/*****************************************************************************
 * FUNCTION
 *  ExitScrAfterPessingRSK
 * DESCRIPTION
 *  Exit function for the scrren after
 *  that give message messge " press # to unlock "
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrAfterPessingRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(KEYPADUNLOCKEDHELPMESSAGE_TIMER);
    stopRequestedTone(SUCCESS_TONE);
}

#if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)


/*****************************************************************************
 * FUNCTION
 *  EntryScrKeyPadLockOnPessingAnyKey
 * DESCRIPTION
 *  shows the screen after pressing any key indicating
 *  messge " press RSK to unlock "
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrKeyPadLockOnPessingAnyKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(KPAD_SCR_UNLOCK_FIRST_HELP_MESSAGE, ExitScrKeyPadLockOnPessingAnyKey, NULL, NULL);

    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        mmi_frm_kbd_reg_pre_key_hdlr(IdleScreenEmergencyCallCheckNKeypadLock);
    }

#ifdef __MMI_TOUCH_SCREEN__
    ShowCategory64Screen(TOUCH_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR, IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE, 0);
#else /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    ShowCategory64Screen(KPAD_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR, IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE, 0);
#else 
    ShowCategory64Screen(KPAD_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR2, IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE, 0);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* Start Timer */
    StartTimer(KEYPADUNLOCKEDHELPMESSAGE_TIMER, KEYPADUNLOCK_TIMEOUT, GoBackHistory);

    /* SetGroupKeyHandler(GoBackHistory,(PU16)PresentAllKeys,(U8)TOTAL_KEYS,(U16)KEY_EVENT_DOWN); */

    SetGroupKeyHandler(MMI_dummy_function, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);

#ifdef __MMI_TOUCH_SCREEN__
    SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
#else /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    SetKeyHandler(EntryScrAfterPessingRSK, KEY_RSK, KEY_EVENT_DOWN);
#else 
    SetKeyHandler(EntryScrAfterPessingRSK, KEY_LSK, KEY_EVENT_DOWN);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 

    playRequestedTone(SUCCESS_TONE);

    TurnOnBacklight(1);

}


/*****************************************************************************
 * FUNCTION
 *  ExitScrKeyPadLockOnPessingAnyKey
 * DESCRIPTION
 *  Exit function for the scrren after
 *  that give message messge " press # to unlock "
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrKeyPadLockOnPessingAnyKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

    StopTimer(KEYPADUNLOCKEDHELPMESSAGE_TIMER);
    stopRequestedTone(SUCCESS_TONE);
}

#endif /* defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__) */ 


/*****************************************************************************
 * FUNCTION
 *  MakeEmergencyCall
 * DESCRIPTION
 *  Make the emergency call in case of
 *  Keypad lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeEmergencyCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER);
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
    {
        mmi_voip_app_make_call((U8*) emgNumberArr);
    }
    else
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
    {
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_sim_error_set_emergency_call_path();
    #endif
        MakeCall(emgNumberArr);
    }
    g_keylock_context.gKeyPadLockFlag = 0;

    /* Lisen 02182005 */
#ifdef __MMI_KEYPADLOCK_WITH_KEYTONE__

#else 
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#endif 

    memset(emgNumberArr, 0, (EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  DropEmergencyCall
 * DESCRIPTION
 *  Drop Emergency call
 *  and back to idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DropEmergencyCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    isEmergencyCallDropped = 1; /* Robin 1217 */
    StopTimer(EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER);
    /* g_keylock_context.gKeyPadLockFlag=1; */

    /* Lisen 02182005 */
#ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#endif 

    memset(emgNumberArr, 0, (EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  EmergencyCallCheck
 * DESCRIPTION
 *  Check the number entered on idel scrreen
 *  if it is Emergency Number
 * PARAMETERS
 *  keyCode         [IN]        
 *  keyType         [IN]        
 *  KeyType(?)      [IN]        
 *  KeyCode(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 EmergengyNoArrIndex = 0;  /* Robin 1217 */
void EmergencyCallCheck(S16 keyCode, S16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyType == KEY_EVENT_DOWN)
    {
        char aTemp[5];

        /* Robin 1217, static U8 EmergengyNoArrIndex=0; */
        U8 AnsValidateEmgNo;
        U8 i;

        if ((keyCode >= 0) && (keyCode <= 9))
        {
            sprintf(aTemp, "%d", keyCode);
            emgNumberArr[EmergengyNoArrIndex] = *aTemp;

        #ifdef __UCS2_ENCODING
            emgNumberArr[++EmergengyNoArrIndex] = 0;
        #endif 

            emgNumberArr[++EmergengyNoArrIndex] = 0;
            for (i = 0; (EmergengyNoArrIndex > 0) || emgNumberArr != NULL; i++)
            {
                AnsValidateEmgNo = ValidateEmergencyNo(emgNumberArr);
                switch (AnsValidateEmgNo)
                {
                    case 0: /* Number not Matched, so shift number by one digit and try again. */
                        memcpy(
                            emgNumberArr,
                            emgNumberArr + ENCODING_LENGTH,
                            (EMERGENCY_NUMBER_LENGTH * ENCODING_LENGTH));
                        /* Robin 1217 */
                        if (EmergengyNoArrIndex <= 1 ||
                            EmergengyNoArrIndex > (EMERGENCY_NUMBER_LENGTH * ENCODING_LENGTH))
                        {
                            memset(emgNumberArr, 0, (EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
                            EmergengyNoArrIndex = 0;
                            break;
                        }
                        EmergengyNoArrIndex = EmergengyNoArrIndex - ENCODING_LENGTH;
                        continue;
                    case 1:                         /* Number Partially Matched. */
                        break;
                    case 2:                         /* Number found as Emergency Number. */
                        isEmergencyCallDropped = 0; /* Robin 1217 */
                        EntryNewScreen(EMERENCY_CALL_SCR_DISPLAY_ID, ExitEmergencyCallScr, NULL, NULL);
                        EmergengyNoArrIndex = 0;
                        gEmerencyNoDialed = 1;

                        /* diamond, 2006/04/04 Sync with reference phone to display keypad lock icon in this screen */
                    #ifdef __MMI_TOUCH_SCREEN__
                        ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK);
                    #else 
                        ShowStatusIcon(STATUS_ICON_KEYPAD_LOCK);
                    #endif 

                    #if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
                        SetDialingKeypadCallHandler(MakeEmergencyCall);
                        SetDialingKeypadPhonebookHandler(NULL);
                    #endif /* defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */

                    #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
                        if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
                        {
                            ShowCategory404Screen(0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, IMG_ID_VOIP_CALL_EDITOR, (U8*) emgNumberArr, 4, NULL);
                        }
                        else
                    #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
                        {
                        #if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                            if (mmi_bootup_get_active_flight_mode() != 1)
                            {
                                EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
                            }
                        #endif /* defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
                            ShowCategory16Screen(0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (U8*) emgNumberArr, 4, NULL);
                        }

                        /* g_keylock_context.gKeyPadLockFlag=0; */
                        ClearInputEventHandler(MMI_DEVICE_KEY); /* Not allow category 16 to process key event */

                    #if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                        SetCenterSoftkeyFunction(MakeEmergencyCall, KEY_EVENT_DOWN);
                    #endif 
                        /* Lisen 02182005 */
                    #ifdef __MMI_KEYPADLOCK_WITH_KEYTONE__

                    #else 
                        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
                    #endif 
                        SetGroupKeyHandler(DropEmergencyCall, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP); /* KEY_EVENT_DOWN, keytone will play non-stop */
                        StartTimer(
                            EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER,
                            EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMEOUT,
                            DropEmergencyCall);
                        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

                        SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
                        SetRightSoftkeyFunction(DropEmergencyCall, KEY_EVENT_UP);

                    #ifdef __MMI_DUAL_SIM_MASTER__
                        MTPNP_PFAL_CC_HandleSendKeys(MakeEmergencyCall, KEY_EVENT_UP);
                    #else
                        SetKeyHandler(MakeEmergencyCall, KEY_SEND, KEY_EVENT_UP);
                    #endif

                        SetKeyHandler(DropEmergencyCall, KEY_END, KEY_EVENT_DOWN);
                        TurnOnBacklight(1);
                        break;
                    default:
                        memset(emgNumberArr, 0, (EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
                        EmergengyNoArrIndex = 0;
                        break;
                }
                break;
            }

        }
        else
        {
            memset(emgNumberArr, 0, (EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
            EmergengyNoArrIndex = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitEmergencyCallScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEmergencyCallScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2006/04/17 Always hide keypad lock icon when leave this screen */
#ifdef __MMI_TOUCH_SCREEN__
    ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_UNLOCK);
#else 
    HideStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif 

    if (isEmergencyCallDropped == 0)    /* Robin 1217 */
    {
        StopTimer(EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER);
    #ifdef __MMI_DUAL_SIM_MASTER__
		if (!CheckValidEmergencyNo1(emgNumberArr, SIM1) && !CheckValidEmergencyNo1(emgNumberArr, SIM2))
    #endif
            memset(emgNumberArr, 0, (EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ValidateEmergencyNo
 * DESCRIPTION
 *  Validate the Emergency Number.
 * PARAMETERS
 *  tempbuffer      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 ValidateEmergencyNo(S8 *tempbuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nNumLen;
    S32 nLen;
    U8 i;
#ifdef __MMI_DUAL_SIM_MASTER__
    U8 sim1_result, sim2_result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nNumLen = mmi_ucs2strlen(tempbuffer);
#ifdef __MMI_Emergency_Call_911_Support__
  /***  Robin 0714 Begin ***/
  /***  For Insert SIM, Dail 911 as emergency call ***/

    nLen = mmi_ucs2strlen((PS8) EmergencyNumber[0]);
    if (nLen == nNumLen)
    {
        if ((mmi_ucs2cmp((PS8) EmergencyNumber[0], tempbuffer) == 0))
        {
            return 2;
        }
    }
    else if (nLen > nNumLen)
    {
        if ((mmi_ucs2ncmp((PS8) EmergencyNumber[0], tempbuffer, nNumLen) == 0))
        {
            return 1;
        }
    }

  /***  Robin 0714 End ***/

#else /* __MMI_Emergency_Call_911_Support__ */ 
    for (i = 0; i < MAX_EMERGENCYNUMBER; i++)
    {
        nLen = mmi_ucs2strlen((PS8) EmergencyNumber[i]);

        if (nLen == nNumLen)
        {
            if ((mmi_ucs2cmp((PS8) EmergencyNumber[i], tempbuffer) == 0))
            {
                return 2;
            }
        }
        else if (nLen > nNumLen)
        {
            if ((mmi_ucs2ncmp((PS8) EmergencyNumber[i], tempbuffer, nNumLen) == 0))
            {
                return 1;
            }
        }
    }

#endif /* __MMI_Emergency_Call_911_Support__ */ 
    /* call Phone book API to validate the entered number from Phonebook SOS enteries. */

#ifdef __MMI_DUAL_SIM_MASTER__
    sim1_result = mmi_phb_check_valid_sos_number(tempbuffer, SIM1);
    sim2_result = mmi_phb_check_valid_sos_number(tempbuffer, SIM2);
    if (sim1_result == 2 || sim2_result == 2)
    {
        return 2;
    }
    else if (sim1_result == 1 || sim2_result == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    return mmi_phb_check_valid_sos_number(tempbuffer);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


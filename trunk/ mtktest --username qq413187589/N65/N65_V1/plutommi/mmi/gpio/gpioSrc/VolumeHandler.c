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
 * VolumeHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Volume Key Handlers
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

   FILENAME : VolumeHandler.c

   PURPOSE     : Volume Key Handlers

   REMARKS     : nil

   AUTHOR      : Deepali, NEERAJ SHARMA

   DATE     : July 22,03

**************************************************************/
#include "MMI_include.h"
#include "VolumeHandler.h"
#include "SettingProfile.h"
#include "ProfileGProts.h"
#include "UserProfilesResDef.h"

#include "CallManagementStruct.h"
#include "CallManagementGProt.h"
#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#include "gpioInc.h"
#include "IdleAppDef.h"
#include "SimDetectionDef.h"

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

static mmi_frm_kbd_tone_state_enum key_tone_state = MMI_KEY_TONE_INVALID;

#ifdef __MMI_AUDIO_PLAYER__
BOOL mmi_audply_is_playing(void);
void mmi_audply_press_inc_volume(void);
void mmi_audply_press_dec_volume(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_FM_RADIO__
BOOL mmi_fmrdo_is_power_on(void);
void mmi_fmrdo_inc_volume(void);
void mmi_fmrdo_dec_volume(void);
#endif /* __MMI_FM_RADIO__ */ 

extern S32 volume_level_UI;
FuncPtr volumeDecreaseFunction;
FuncPtr volumeIncreaseFunction;
FuncPtr volumeMinFunction;
FuncPtr volumeMaxFunction;
FuncPtr hardwareVolumeFunction;
U16 volumeCaption;
S32 *initialVolume;
U16 LSKCaption;
U16 RSKCaption;
FuncPtr LSKCallback;
FuncPtr RSKCallback;
FuncPtr ExitCallback;
U32 volumeTimer;
U8 updownFlag;
S32 volLevel;

/* PMT HIMANSHU START 20050729 */
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__)

#define LONGPRESS_DELAY 6

/* variable for synchronizing the time of KEY_LONG_PRESS event with MMI_PEN_EVENT_LONG_TAP event */
U16 callback_timer = 0;

#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
/* PMT HIMANSHU END 20050729 */

/*****************************************************************************
 * FUNCTION
 *  play_keypad_tone
 * DESCRIPTION
 *  play current profile keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void play_keypad_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 keypad_tone;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsSilentModeActivated())
    {
#ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!IsMeetingModeActivated())
#endif 
        {
            keypad_tone = GetKeypadToneType();
            if (keypad_tone == KEYPAD_CLICK)
            {
                AudioPlayReq(TONE_KEY_CLICK, DEVICE_AUDIO_PLAY_ONCE);
            }
            else if (keypad_tone != KEYPAD_SILENT)
            {
                AudioPlayReq(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetDefaultVolumeKeyHandlers
 * DESCRIPTION
 *  Sets Default Volume Handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetDefaultVolumeKeyHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 isValid = 0;
    mmi_frm_kbd_tone_state_enum currKeyToneState;
    U16 activeScrId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isIncomingCall())
    {
        volLevel = GetRingVolumeLevel();
        SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            STR_COMMON_VOLUME_LEVEL_RING_CAPTION,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            1000,
            RingVolumeExitFunction,
            0,
            VOLUMEHANDLER_RING_TONE);
        isValid = 1;
    }
    else if (isInCall() && !IsWapCallPresent())
    {
        volLevel = GetModeSpeechVolume();
        SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            /* MTK added by JL 031125 for string ID not found */ STR_VOLUME_LEVEL_CAPTION /* JL comment STR_DEFAULT_VOLUME_CAPTION */ ,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            1000,
            SpeechVolumeExitFunction,
            0,
            VOLUMEHANDLER_SPEECH_TONE);
        isValid = 1;
    }

    /* setup volume key handler when entering related screens */    
    activeScrId = GetActiveScreenId();
    if ( (((activeScrId == IDLE_SCREEN_ID) || (activeScrId == SCR_SIM_INSERTION) || 
           (activeScrId == SCR_SIM_BLOCK)) && !g_keylock_context.gKeyPadLockFlag) || 
         (activeScrId == IDLE_SCREEN_DIGIT_HANDLER_ID) || 
         (activeScrId == SCR_DIAL_SOS_NUM))
    {
        volLevel = GetKeypadVolumeLevel();
        SetVolumeKeyHandlerFunctions(
            play_keypad_tone,
            play_keypad_tone,
            NULL,
            NULL,
            /* MTK added by JL 031125 for string ID not found */ STR_COMMON_VOLUME_LEVEL_KEY_CAPTION /* JL comment  STR_KEY_TONE_VOLUME_CAPTION */ ,
            &volLevel,
            0,
            STR_GLOBAL_BACK,
            NULL,
            ExitScrSetKeyPadVolumeLevel,
            2000,
            KeyPadVolumeExitFunction,
            0,
            VOLUMEHANDLER_KEY_TONE);
        isValid = 1;

        /* disable side key keytone played by framework */
        currKeyToneState = mmi_frm_kbd_get_key_tone_state();
        if (currKeyToneState != MMI_KEY_VOL_TONE_DISABLED)
        {
            key_tone_state = currKeyToneState;
            mmi_frm_kbd_set_tone_state(MMI_KEY_VOL_TONE_DISABLED);
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */

    if (isValid)
    {

        if (updownFlag)
        {
            SetKeyHandler(SetKeyPadVolUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(SetKeyPadVolMaxLongPress, KEY_UP_ARROW, KEY_LONG_PRESS);
            SetKeyHandler(SetKeyPadVolDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(SetKeyPadVolMinLongPress, KEY_DOWN_ARROW, KEY_LONG_PRESS);
        }

	       if(isInCall()) //增加调节
		{		
			
		#ifdef __MMI_NO_VOL_KEYS__ 
		//sc.wu __MMI_NO_VOL_KEYS__
	            SetKeyHandler(SetKeyPadVolUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
	            SetKeyHandler(SetKeyPadVolMaxLongPress, KEY_UP_ARROW, KEY_LONG_PRESS);
	            SetKeyHandler(SetKeyPadVolDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	            SetKeyHandler(SetKeyPadVolMinLongPress, KEY_DOWN_ARROW, KEY_LONG_PRESS);
	#else
	        SetKeyHandler(SetKeyPadVolUp, KEY_VOL_UP, KEY_EVENT_DOWN);
	        SetKeyHandler(SetKeyPadVolMaxLongPress, KEY_VOL_UP, KEY_LONG_PRESS);
	        SetKeyHandler(SetKeyPadVolDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	        SetKeyHandler(SetKeyPadVolMinLongPress, KEY_VOL_DOWN, KEY_LONG_PRESS);
	#endif		
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  SetVolumeKeyHandlerFunctions
 * DESCRIPTION
 *  Init Function to be called before using Volume Screen
 * PARAMETERS
 *  decreaseFunction        [IN]        Function to be called when volume down key is pressed.
 *  increaseFunction        [IN]        
 *  minFunction             [IN]        
 *  maxFunction             [IN]        
 *  caption                 [IN]        
 *  volume                  [?]         
 *  captionLSK              [IN]        
 *  captionRSK              [IN]        
 *  callbackLSK             [IN]        
 *  callbackRSK             [IN]        
 *  timerDuration           [IN]        
 *  callbackExit            [IN]        
 *  updown                  [IN]        
 *  type                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetVolumeKeyHandlerFunctions(
        FuncPtr decreaseFunction,
        FuncPtr increaseFunction,
        FuncPtr minFunction,
        FuncPtr maxFunction,
        U16 caption,
        S32 *volume,
        U16 captionLSK,
        U16 captionRSK,
        FuncPtr callbackLSK,
        FuncPtr callbackRSK,
        U32 timerDuration,
        FuncPtr callbackExit,
        U8 updown,
        VOLUMEHANDLER_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    volumeDecreaseFunction = decreaseFunction;
    volumeIncreaseFunction = increaseFunction;
    volumeMinFunction = minFunction;
    volumeMaxFunction = maxFunction;
    volumeCaption = caption;
    initialVolume = volume;
    LSKCaption = captionLSK;
    RSKCaption = captionRSK;
    LSKCallback = callbackLSK;
    RSKCallback = callbackRSK;
    volumeTimer = timerDuration;
    ExitCallback = callbackExit;
    updownFlag = updown;
    if (type == VOLUMEHANDLER_RING_TONE)
    {
        hardwareVolumeFunction = RingToneVolumeFunction;
    }
    else if (type == VOLUMEHANDLER_SPEECH_TONE)
    {
        hardwareVolumeFunction = SpeechVolumeFunction;
    }
    else
    {
        hardwareVolumeFunction = KeyPadVolumeFunction;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrSetKeyPadVolumeLevel
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSetKeyPadVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_KEY_TONE_VOLUME);

    EntryNewScreen(SCR_KEY_TONE_VOLUME, StopKeyPadVolumeLevelTimer, NULL, NULL);

    ShowCategory105Screen(
        volumeCaption,
        IMG_PROFILES_TITLEE,
        LSKCaption,
        0,
        RSKCaption,
        0,
        (S32*) initialVolume,
        guiBuffer);

    if (volumeTimer)
    {
        SetGroupKeyHandler(ExitScrSetKeyPadVolumeLevel, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
    }

    SetLeftSoftkeyFunction(LSKCallback, KEY_EVENT_UP);
    SetRightSoftkeyFunction(RSKCallback, KEY_EVENT_UP);


#ifdef __MMI_NO_VOL_KEYS__ 
//sc.wu __MMI_NO_VOL_KEYS__ //UNI@bw_20070409a 没有音量键的处理
	    SetKeyHandler(ShowVerticalBarUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
	    SetKeyHandler(ShowVerticalBarMax, KEY_UP_ARROW, KEY_LONG_PRESS);
	    SetKeyHandler(ShowVerticalBarDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	    SetKeyHandler(ShowVerticalBarMin, KEY_DOWN_ARROW, KEY_LONG_PRESS);
#else
	    SetKeyHandler(ShowVerticalBarUp, KEY_VOL_UP, KEY_EVENT_DOWN);
	    SetKeyHandler(ShowVerticalBarMax, KEY_VOL_UP, KEY_LONG_PRESS);
	    SetKeyHandler(ShowVerticalBarDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	    SetKeyHandler(ShowVerticalBarMin, KEY_VOL_DOWN, KEY_LONG_PRESS);
#endif
    if (updownFlag)
    {
        SetKeyHandler(ShowVerticalBarUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ShowVerticalBarMax, KEY_UP_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(ShowVerticalBarDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ShowVerticalBarMin, KEY_DOWN_ARROW, KEY_LONG_PRESS);
    }

    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }

    /* SetExitHandler(SCR_KEY_TONE_VOLUME,StopKeyPadVolumeLevelTimer); */

}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolDown
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolDown(void)
{
#ifdef __MMI_AUDIO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_is_playing())
    {
        mmi_audply_press_dec_volume();
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_dec_volume();
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
    {
        EntryScrSetKeyPadVolumeLevel();
        ShowVerticalBarDown();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolUp
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolUp(void)
{
#ifdef __MMI_AUDIO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_is_playing())
    {
        mmi_audply_press_inc_volume();
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_inc_volume();
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
    {
        EntryScrSetKeyPadVolumeLevel();
        ShowVerticalBarUp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolMinLongPress
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolMinLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        mmi_audply_press_dec_volume();
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_dec_volume();
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
    {
        EntryScrSetKeyPadVolumeLevel();
        ShowVerticalBarMin();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadVolMaxLongPress
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadVolMaxLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        mmi_audply_press_inc_volume();
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_inc_volume();
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
    {
        EntryScrSetKeyPadVolumeLevel();
        ShowVerticalBarMax();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarUp
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    show_vertical_bar_next();
    *initialVolume = volume_level_UI;
    hardwareVolumeFunction();
    if (volumeIncreaseFunction)
    {
        volumeIncreaseFunction();
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarDown
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    show_vertical_bar_previous();
    *initialVolume = volume_level_UI;
    hardwareVolumeFunction();
    if (volumeDecreaseFunction)
    {
        volumeDecreaseFunction();
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarMax
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarMax(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    show_vertical_bar(LEVEL7);
    *initialVolume = volume_level_UI;
    hardwareVolumeFunction();
    if (volumeMaxFunction)
    {
        volumeMaxFunction();
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowVerticalBarMin
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVerticalBarMin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    show_vertical_bar(LEVEL1);
    *initialVolume = volume_level_UI;
    hardwareVolumeFunction();
    if (volumeMinFunction)
    {
        volumeMinFunction();
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  StopKeyPadVolumeLevelTimer
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopKeyPadVolumeLevelTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    if (ExitCallback)
    {
        ExitCallback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrSetKeyPadVolumeLevel
 * DESCRIPTION
 *  To Increase Volume level of keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrSetKeyPadVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  SpeechVolumeFunction
 * DESCRIPTION
 *  Sets Default Volume Handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpeechVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetSpeechVolume(volume_level_UI);

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_set_headset_speaker_volume(volume_level_UI);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  RingToneVolumeFunction
 * DESCRIPTION
 *  Ring Tone Volume Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RingToneVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetRingerVolume(volume_level_UI);

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_set_headset_speaker_volume(volume_level_UI);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  SpeechVolumeExitFunction
 * DESCRIPTION
 *  Speech volume Exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpeechVolumeExitFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SaveSpeechVolume((U8) volume_level_UI);
}


/*****************************************************************************
 * FUNCTION
 *  RingVolumeExitFunction
 * DESCRIPTION
 *  Ring volume Exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RingVolumeExitFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetActivatedRingVolumeLevel((MMI_VOLUME_LEVEL_ENUM) volume_level_UI);
}


/*****************************************************************************
 * FUNCTION
 *  KeyPadVolumeFunction
 * DESCRIPTION
 *  Keypad volume function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KeyPadVolumeFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyPadVolume(volume_level_UI);
}


/*****************************************************************************
 * FUNCTION
 *  KeyPadVolumeExitFunction
 * DESCRIPTION
 *  KeyPad Volume Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KeyPadVolumeExitFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* MTK Brian added for setting activated keypad volume, 2003/12/02 */
    SetActivatedKeypadVolumeLevel((MMI_VOLUME_LEVEL_ENUM) volume_level_UI);
}

/* PMT HIMANSHU START 20050729 */
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__)


/*****************************************************************************
 * FUNCTION
 *  CallShowVerticalBarMax
 * DESCRIPTION
 *  Callback function for time synchronization of KEY_LONG_PRESS
 *  and MMI_PEN_EVENT_LONG_TAP event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallShowVerticalBarMax(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    callback_timer++;
    if (callback_timer >= LONGPRESS_DELAY)
    {
        ShowVerticalBarMax();
        callback_timer = 0;
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CallShowVerticalBarMin
 * DESCRIPTION
 *  Callback function for time synchronization of KEY_LONG_PRESS
 *  and MMI_PEN_EVENT_LONG_TAP event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallShowVerticalBarMin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volumeTimer)
    {
        StopTimer(KEY_VOL_TIMER_ID);
    }
    callback_timer++;
    if (callback_timer >= LONGPRESS_DELAY)
    {
        ShowVerticalBarMin();
        callback_timer = 0;
    }
    if (volumeTimer)
    {
        StartTimer(KEY_VOL_TIMER_ID, KEY_VOLUME_TIMEOUT, ExitScrSetKeyPadVolumeLevel);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetCallbackTimer
 * DESCRIPTION
 *  Callback function of PEN_EVENT_UP event for reseting the
 *  synchronization variable.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCallbackTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_timer = 0;
}

#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
/* PMT HIMANSHU END 20050729 */


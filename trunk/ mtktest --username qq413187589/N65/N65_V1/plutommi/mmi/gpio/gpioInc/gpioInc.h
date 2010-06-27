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
 * gpioInc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Header file for GPIO Utility Functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_GPIO_H
#define MMI_GPIO_H

#include "kal_non_specific_general_types.h"
#include "device.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "custom_led_patterns.h"
#include "SettingProfile.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define MMIDEVMSK_VIBON     0x00000001
#define MMIDEVMSK_VIBSMS        0x00000002
#define MMIDEVMSK_RESERVED_2      0x00000004
#define MMIDEVMSK_RESERVED_3       0x00000008
#define MMIDEVMSK_RESERVED_4      0x00000010
#define MMIDEVMSK_RESERVED_5      0x00000020
#define MMIDEVMSK_RESERVED_6      0x00000040
#define MMIDEVMSK_RESERVED_7      0x00000080

#define MMIDEV_GET_FLAG(a)       ( (gDeviceState & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMIDEV_SET_FLAG(a)       ( gDeviceState |=  a )
#define MMIDEV_RESET_FLAG(a)   ( gDeviceState &=  ~a )
#define MMIDEV_QRY_OCCUPY()       ( (gDeviceState == 0) ? MMI_FALSE : MMI_TRUE )

#define     PHNSET_GPIO_SLIDE_CLAM_SETTING_BACK_TO_IDLE 0X00
#define     PHNSET_GPIO_SLIDE_CLAM_SETTING_REJECT_CALL   0X01
#define     PHNSET_GPIO_SLIDE_CLAM_SETTING_KEYPAD_LOCK   0X02

#define SetRingerVolume(volume) mdi_audio_set_volume(MDI_VOLUME_MEDIA,(U8)(volume))
#define SetKeyPadVolume(volume) mdi_audio_set_volume(MDI_VOLUME_KEY,(U8)(volume))
#define SetSpeechVolume(volume) mdi_audio_set_volume(MDI_VOLUME_SPH,(U8)(volume))

#define MuteOnMicrophone() SetMuteReq(MDI_DEVICE_MICROPHONE,1)
#define MuteOffMicrophone() SetMuteReq(MDI_DEVICE_MICROPHONE,0)

#define MuteOnSpeaker() SetMuteReq(MDI_DEVICE_SPEAKER,1)
#define MuteOffSpeaker() SetMuteReq(MDI_DEVICE_SPEAKER,0)

#define LCDBackLightOn() SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD,5);\
                   SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD,5);

#define LCDBackLightOff() SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD,0);\
                    SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD,0);

#define KeyPadBackLightOn() SetGPIOLevelReq(GPIO_DEV_LED_KEY,5)
#define KeyPadBackLightOff() SetGPIOLevelReq(GPIO_DEV_LED_KEY,0)

#define SetBackLightStatusOff()        SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_1,LED_LIGHT_LEVEL0);\
                              SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_2,LED_LIGHT_LEVEL0);         \
                              SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_3,LED_LIGHT_LEVEL0);

#define SetBackLightStatusRedOn()      SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_1,LED_LIGHT_LEVEL5)
#define SetBackLightStatusGreenOn()    SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_2,LED_LIGHT_LEVEL5)
#define SetBackLightStatusBlueOn()     SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_3,LED_LIGHT_LEVEL5)

#define SetBackLightStatusRedOff()     SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_1,LED_LIGHT_LEVEL0)
#define SetBackLightStatusGreenOff()   SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_2,LED_LIGHT_LEVEL0)
#define SetBackLightStatusBlueOff()    SetGPIOLevelReq((gpio_device_enum)GPIO_DEV_LED_STATUS_3,LED_LIGHT_LEVEL0)

#define StartLEDPatternPowerOn()          PlayPatternReq(LED_POWER_ON, 1)
#define StopLEDPatternPowerOn()              PlayPatternReq(LED_POWER_ON, 0)

#define StartLEDPatternPowerOff()            PlayPatternReq(LED_POWER_OFF, 1)
#define StopLEDPatternPowerOff()          PlayPatternReq(LED_POWER_OFF, 0)

#define StartLEDPatternBatteryWarning()         PlayPatternReq(LED_BATTERY_WARNING, 1)
#define StopLEDPatternBatteryWarning()       PlayPatternReq(LED_BATTERY_WARNING, 0)

#define StartLEDPatternBatteryLow()          PlayPatternReq(LED_BATTERY_LOW, 1)
#define StopLEDPatternBatteryLow()           PlayPatternReq(LED_BATTERY_LOW, 0)

#define StartLEDPatternConnect900()          PlayPatternReq(LED_Connect900, 1)
#define StopLEDPatternConnect900()           PlayPatternReq(LED_Connect900, 0)

#define StartLEDPatternConnect1800()         PlayPatternReq(LED_Connect1800, 1)
#define StopLEDPatternConnect1800()          PlayPatternReq(LED_Connect1800, 0)

#define StartLEDPatternConnect1900()         PlayPatternReq(LED_Connect1900, 1)
#define StopLEDPatternConnect1900()          PlayPatternReq(LED_Connect1900, 0)

#define StartLEDPatternRoaming()            PlayPatternReq(LED_Roaming, 1)
#define StopLEDPatternRoaming()           PlayPatternReq(LED_Roaming, 0)

#define StartLEDPatternLimitService()        PlayPatternReq(LED_LimitService, 1)
#define StopLEDPatternLimitService()         PlayPatternReq(LED_LimitService, 0)

#define StartLEDPatternNoService()            PlayPatternReq(LED_NoService, 1)
#define StopLEDPatternNoService()            PlayPatternReq(LED_NoService, 0)

#define StartLEDPatternBackGround()            PlayPatternReq(GetBackgroundPattern(), 1)
#define StopLEDPatternBackGround()             SendPlayPatternReqToHW(GetBackgroundPattern(), 0)

#define StartLEDPatternCharging()            PlayPatternReq(LED_OnCharging, 1)
#define StopLEDPatternCharging()          PlayPatternReq(LED_OnCharging, 0)

#define StartLEDPatternFullCharging()        PlayPatternReq(LED_FullCharging, 1)
#define StopLEDPatternFullCharging()         PlayPatternReq(LED_FullCharging, 0)

#define StartLEDPatternMessageIn()           PlayPatternReq(LED_MessageIn, 1)
#define StopLEDPatternMessageIn()            PlayPatternReq(LED_MessageIn, 0)

#define StartLEDPatternMessageRemind()       PlayPatternReq(LED_MessageRemind, 1)
#define StopLEDPatternMessageRemind()        PlayPatternReq(LED_MessageRemind, 0)

#define StartLEDPatternCaller1()          PlayPatternReq(LED_Caller1, 1)
#define StopLEDPatternCaller1()              PlayPatternReq(LED_Caller1, 0)

#define StartLEDPatternCaller2()          PlayPatternReq(LED_Caller2, 1)
#define StopLEDPatternCaller2()              PlayPatternReq(LED_Caller2, 0)

#define StartLEDPatternCaller3()          PlayPatternReq(LED_Caller3, 1)
#define StopLEDPatternCaller3()              PlayPatternReq(LED_Caller3, 0)

#define StartLEDPatternCaller4()          PlayPatternReq(LED_Caller4, 1)
#define StopLEDPatternCaller4()              PlayPatternReq(LED_Caller4, 0)

#define StartLEDPatternCaller5()          PlayPatternReq(LED_Caller5, 1)
#define StopLEDPatternCaller5()              PlayPatternReq(LED_Caller5, 0)

#define StartLEDPatternCaller6()          PlayPatternReq(LED_Caller6, 1)
#define StopLEDPatternCaller6()              PlayPatternReq(LED_Caller6, 0)

#ifndef __VIBRATOR_TONE_SUPPORT__//su-2008/12/04
#define VibratorOn()                            \
{                                               \
   if( MMIDEV_QRY_OCCUPY() == MMI_FALSE )       \
   {                                            \
      PlayPatternReq(VIB_PATTERN_1,PLAY_REPEAT);\
   }                                            \
   MMIDEV_SET_FLAG(MMIDEVMSK_VIBON);            \
}

#define VibratorOff()                         \
{                                             \
   MMIDEV_RESET_FLAG(MMIDEVMSK_VIBON);        \
   if( MMIDEV_QRY_OCCUPY() == MMI_FALSE )     \
   {                                          \
      PlayPatternReq(VIB_PATTERN_1,PLAY_STOP);\
   }                                          \
}

#define PlayVibratorOnce()                    \
{                                             \
   if( MMIDEV_QRY_OCCUPY() == MMI_FALSE )     \
   {                                          \
      PlayPatternReq(VIB_PATTERN_1,PLAY_ONCE);\
   }                                          \
}

#define PlaySmsVibratorOnce()                 \
{                                             \
   if( MMIDEV_QRY_OCCUPY() == MMI_FALSE )     \
   {                                          \
      PlayPatternReq(VIB_PATTERN_3,PLAY_ONCE);\
   }                                          \
}
#else

#define VibratorOn()                            \
{                                               \
	AudioPlayReq(TONE_VIBRATOR, DEVICE_AUDIO_PLAY_INFINITE);\
}

#define VibratorOff()                         \
{                                             \
	AudioStopReq(TONE_VIBRATOR);\
}

#define PlayVibratorOnce()                    \
{                                             \
	AudioPlayReq(TONE_VIBRATOR, DEVICE_AUDIO_PLAY_ONCE);\
}

#define PlaySmsVibratorOnce()                 \
{                                             \
	extern void closeVibrator();\
	AudioPlayReq(TONE_VIBRATOR, DEVICE_AUDIO_PLAY_ONCE);\
	StartTimer (AUDIO_VIBRATOT_TIMER,2000, closeVibrator);\
}
#endif
#define IsClamOpen()    gMMIClamState

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef enum
{
    PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_TITLE,
    PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_ON,
    PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_OFF,
    PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_TITLE,
    PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_YES,
    PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_NO,
    PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_TITLE,
    PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_ON,
    PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_OFF
} phnset_gpio_slide_clam_behavior_enum;

typedef enum
{
    GPIO_BACKLIGHT_PERMANENT = 0,
    GPIO_BACKLIGHT_SHORT_TIME
} gpio_backlight_time_enum;



typedef enum
{
    MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER,          /* 0 */
    MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE,     /* 1 */
    MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE,    /* 2 */
    MMI_GPIO_BACKLIGHT_TIMER_STATE_IN_SLEEP_MODE      /* 3 */
} MMI_GPIO_BACKLIGHT_TIMER_STATE;

/***************************************************************************** 
             
* Extern Global 
Variable                                                                    
*****************************************************************************/
extern U8 gMMIClamState;
extern U8 isEarphonePlugged;
extern U32 gDeviceState;

/***************************************************************************** 
             
* Extern Global 
Function                                                                    
*****************************************************************************/
/* gpio devices detection indication */
extern void GpioDetectInd(void *info);

/* sets the Mute on */
extern void SetMuteReq(audio_type_enum audio, MMI_BOOL onoff);

extern void SetGPIOLevelReq(gpio_device_enum device, U8 level);
extern void PlayPatternReq(U8 pattern, U8 action);
extern void PlayPatternCallerGroup(MMI_LEDLIGHT_STATUS_ENUM pattern);
extern void StopPatternCallerGroup(MMI_LEDLIGHT_STATUS_ENUM pattern);
extern void SetModeSpeechVolume(void);
extern void SaveSpeechVolume(U8 level);
extern U8 GetModeSpeechVolume(void);
extern void EnableHandsFree(void);
extern void DisbleHandsFree(void);

extern void EarPhoneScrExitOut(void);
extern void EarPhonePlugOutScrTimeout(void);
extern void EarPhonePlugInScrTimeout(void);
extern BOOL mmi_gpio_is_earphone_plug_in(void);

extern void ShowEarphoneSubLCDPopup(void);
extern void EarPhonePlugInScrExit(void);

extern void GetRingToneRange(U8 *startId, U8 *totalId);
extern void GetMidiRange(U8 *startId, U8 *totalId);
extern void GetToneRange(U8 *startId, U8 *totalId);
extern void GetMiscToneRange(U8 *startId, U8 *totalId);
extern void SendPlayPatternReqToHW(U8 pattern, U8 action);
extern kal_uint8 GpioCtrlReq(kal_uint8 action);

extern void HalfModeBacklight(void);
extern U8 GetBackgroundPattern(void);

extern MMI_BOOL IsBacklightOn(void);
extern void TurnOnBacklight(gpio_backlight_time_enum time_enum);
extern void TurnOffBacklight(void);
extern void CloseBacklight(void);
extern void mmi_gpio_backlight_ctrl_req_hdlr(void *msg, int mod_id , void *peer_buf);
extern void mmi_gpio_led_ctrl_req_hdlr(void *msg, int mod_id , void *peer_buf);

extern void InitHWBacklightTest(void);
extern void SetBacklightMode(void *info);
extern void SetBacklightModeExe(U8 mode);

extern void GpioCtrlReqHdlr(void *inMsg);
extern void GpioPlayReqHdlr(void *inMsg);

extern void KeyPadLCDBackLightStop(void);

extern BOOL mmi_gpio_is_lcd_sleep(void);
extern BOOL IsClamClose(void);

extern MMI_GPIO_BACKLIGHT_TIMER_STATE mmi_gpio_get_backlight_timer_state(void);

extern void mmi_gpio_detect_send_ack(U8 gpio_device);

#endif /* MMI_GPIO_H */ 


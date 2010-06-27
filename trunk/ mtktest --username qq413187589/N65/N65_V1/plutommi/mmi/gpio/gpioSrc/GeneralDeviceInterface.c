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
 * GeneralDeviceInterface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Utility functions for GPIO
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"
/*  Include: MMI header file */
#include "gpioInc.h"
#include "PhnsetPROT.h"
#include "PhnsetGPIO.h"
#include "IdleAppDef.h"
#include "wgui_status_icons.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "IdleAppProt.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "CallManagementIdDef.h"
#include "CallManagementGprot.h"
#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif
#include "CommonScreens.h"
#include "mmiapi_enum.h"
#include "mmiapi_struct.h"
#include "Mdi_datatype.h"
#include "Mdi_audio.h"
#include "mdi_video.h"
#include "lcd_if.h"
#include "custom_equipment.h"
#include "AlarmFrameworkProt.h"
#include "PhoneBookTypes.h"
#include "WPSSProtos.h"

#ifdef __CTM_SUPPORT__
#include "TextPhoneProt.h"
#endif 

#if defined(__MMI_BT_SUPPORT__)
#include "BTMMIScrGprots.h"
#endif 

#ifdef __MMI_SLIDE__
#include "QuickAccessMenuItemProt.h"
#endif /* __MMI_SLIDE__ */ 

#if defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_TVOUT__)
#include "VdoPlyGprot.h"
#endif 

#ifdef __MMI_TVOUT__
#include "PhoneSetupGprots.h"
#endif 

#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
#include "mmi_features_camera.h"
#endif

#ifdef __MMI_SUBLCD_CAMERA__
#include "mdi_camera.h"
#include "cameraapp.h"
#endif

#ifdef __MMI_SLIDESHOW__
#include "SlideShowGProt.h"   /* ignore slide shell effect */
#endif /* __MMI_SLIDESHOW__ */

#ifdef __MMI_FACTORY_MODE__
#include "FactoryModeProt.h"
#endif /* __MMI_FACTORY_MODE__ */


#include "SettingDefs.h"
#include "MainMenuDef.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"

#if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__)
#include "wndrv_api.h"
#endif

#ifdef __MMI_VIDEO_PLAYER__
#include "VdoPlyGprot.h"
#endif

#ifdef __MMI_VIDEO_RECORDER__
#include "VdoRecGprot.h"
#endif

#ifdef __MMI_GAME__
#include "GameFramework.h" /* temp solution for checking if current screen is game screen */
#endif /* __MMI_GAME__ */

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif

#ifdef __MMI_FM_RADIO_ON_SUBLCD__
#include "FMRadioDef.h"
#include "FMRadioProt.h"
#endif

/***************************************************************************** 
* Local variable
*****************************************************************************/
static U8 isTimerSuspend;   /* Is UI timer (aligned) suspended. 0 == non-suspend, 1 == suspend */

static U8 gbacklight_mode = 1;
static U8 gpioOutOfCtrl;
static U8 sublcd_backlight; /* 0 = dark. 1 = light */
static U8 keypad_backlight; /* 0 = dark. 1 = light */

/* 0 = no timer, 1 = timer for half mode backlight , 2 = timer for sleep mode, 3 = in sleep mode */
MMI_GPIO_BACKLIGHT_TIMER_STATE gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
static U8 IsCallerGroupPatternPlaying;
static U8 aud_mode_to_resume;

/***************************************************************************** 
* Local function
*****************************************************************************/
static void BacklightTimerHdlr(void);

#if (defined(__MMI_CLAMCLOSE_BACK2IDLE__) || defined (__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) )
static void ClamCloseGotoIdleScreen(void);
#endif 
#if defined(__MMI_CLAMSHELL__) || defined(__MMI_SLIDE__)
static BOOL IsClamToneAllow(void);
#endif
static void EarphoneConnectHdlr(BOOL is_in);
static void EarphoneDisplayPopup(BOOL is_plugin);
static void GpioEarphonePlugIn(void);
static void GpioEarphonePlugOut(void);
static void GpioTurnOffKeypadLight(void);
static void GpioLCDSleepIn(void);
static void GpioLCDSleepOut(void);
static void GpioTurnOnKeypadLight(void);

/***************************************************************************** 
* Global function
*****************************************************************************/
void SetBacklightMode(void *info);
void GpioSendMsg(U16 src_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

#if defined(__MMI_LCMSLEEP_BACK2IDLE__)
void LCMSleepGotoIdleScreen(void);
#endif 

/***************************************************************************** 
* Global variable
*****************************************************************************/
U8 lcd_backlight = 1;   /* 0 = dark, 1 = half light, 2 = full light  */

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && !defined(__AMNT__)
U8 gMMIClamState = 0;   /* Sync with Drv state */
#else 
U8 gMMIClamState = 1;
#endif 

U8 isEarphonePlugged = 0;

#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
BOOL gIsInSleepMode = KAL_FALSE;
#endif 

#ifdef __MMI_ENGINEER_MODE__
U32 gClamOpenCnt = 0;
U32 gClamCloseCnt = 0;
#endif /* __MMI_ENGINEER_MODE__ */ 

U32 gDeviceState = 0x0; /* Keep device state for concurrency accessing */

/***************************************************************************** 
* External variable
*****************************************************************************/
extern pBOOL processingNow;
extern U8 mmi_msg_need_mem_full_ind(void);

#if ( defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
extern U8 gCurrentMode;
#endif 

extern PROFILE gcurrentprofile;

/***************************************************************************** 
* External functitons
*****************************************************************************/
extern void UI_BLT_double_buffer(S32 x1, S32 y1, S32 x2, S32 y2);

extern void SendSetHWLevelInfoReq(void);

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_is_play_activated(void);

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
void mmi_audply_turn_on_spectrum(void);
void mmi_audply_turn_off_spectrum(void);
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_FM_RADIO__
extern BOOL mmi_fmrdo_is_power_on(void);
#endif 

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
extern void ShowSubLCDAnalogClockScreen(void);
#endif 



/*****************************************************************************
 * FUNCTION
 *  backlight_check_call_present
 * DESCRIPTION
 *  check if there is a call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL backlight_check_call_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We should not use GetTotalCallCount() because it does not handle automatic call redial */
    if (isInCall() && !IsWapCallPresent())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GpioDetectInd
 * DESCRIPTION
 *  Event handler of gpio detect indication
 *  
 *  PARAMETERS: mmi_eq_gpio_detect_ind_struct *
 *  info        [IN]        
 *****************************************************************************/
void GpioDetectInd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct *gpioDetectInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpioDetectInd = (mmi_eq_gpio_detect_ind_struct*) info;

    mmi_gpio_detect_send_ack(gpioDetectInd->gpio_device);

    if (mmi_bootup_is_before_power_on() == MMI_TRUE)
    {
        switch (gpioDetectInd->gpio_device)
        {
            case EXT_DEV_EARPHONE:
                if (gpioDetectInd->on_off == 1)
                {
                    isEarphonePlugged = 1;
                    {
                    #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
                        IdleSetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
                    #endif 
                    }
                }
                else
                {
                    isEarphonePlugged = 0;
                }
                if (isEarphonePlugged)
                {
                    mmi_profiles_earphone_plug_in_callback();
                }
                else
                {
                    mmi_profiles_earphone_plug_out_callback();
                }
                break;

            #ifdef __MMI_CLAMSHELL__
            case EXT_DEV_CLAM_OPEN:
                gMMIClamState = 1;
                break;
            case EXT_DEV_CLAM_CLOSE:
                gMMIClamState = 0;
                break;
            #endif /* __MMI_CLAMSHELL__ */ 

            default:
                break;
        }
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[GPIO] GPIO indication before power on");
        return;
    }

    switch (gpioDetectInd->gpio_device)
    {
        case EXT_DEV_EARPHONE:  /* Earphone plug in/out */
        {
            if (gpioDetectInd->on_off == 1)
            {
                EarphoneConnectHdlr(MMI_TRUE);
            }
            else
            {
                EarphoneConnectHdlr(MMI_FALSE);
            }

            break;
        }
        case EXT_DEV_KEY_1: /* SEND(END) key press */
        {
            if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
            {
                if (isInCall())
                {
                    PRINT_INFORMATION("\n[GpioDetectInd] In Call, Ready to Process Headset Key\n");
                #ifdef __MMI_UCM__
                    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
                    {
                        mmi_ucm_app_headset_key();
                    }
                #elif defined(__MMI_VOIP__)
                    if (GetTotalCallCount() != 0)
                    {
                        ProcessHeadsetKeyPress();
                        PRINT_INFORMATION("\n[GpioDetectInd] Process Headset Key for GSM\n");
                    }
                    else if (mmi_voip_app_total_call() != 0)
                    {
                        mmi_voip_entry_headsetkey();
                        PRINT_INFORMATION("\n[GpioDetectInd] Process Headset Key for VoIP\n");
                    }
                #else
                    ProcessHeadsetKeyPress();
                #endif
                }
            }

            break;
        }
    #ifdef __MMI_CLAMSHELL__        /* { */
        case EXT_DEV_CLAM_OPEN: /* Clam open */
        {
#ifdef __MMI_SUBLCD_MASTER_MODE__
            SubLCDMasterModeClamOpen();
#endif/* __MMI_SUBLCD_MASTER_MODE__ */   
            gMMIClamState = 1;

        #if defined(__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) 
            if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION)
                ForceSubLCDScreen(ShowIdleAppSubLcd);
        #endif 

        #ifdef __MMI_SUBLCD_CAMERA__

            if(mmi_sublcd_camera_delete_screen_if_present())
                GoBackHistory();
            else if (mmi_idle_is_on_idle_screen()==TRUE)
                EntryIdleScreen();
        #endif


            if (!AlmIsRTCPwron())
            {
                TurnOnBacklight(1);
            }

        #ifdef __MMI_UCM__
            mmi_ucm_app_clam_open();
        #else
            NotifyCMClampOpen();
        #endif

            if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
            {
                if (IsClamToneAllow()&& mdi_audio_mma_is_idle())
                {
                    playRequestedTone(COVER_OPEN_TONE);
                }

            #ifdef __MMI_SLIDE__/* keypad lock for slide phone */   /* { */
                if (g_keylock_context.gKeyPadLockFlag)
                {
                    if (isInCall())
                    {
                        /* Not display unlock message if there is an incoming call when the slide is closed */
                        StopTimer(KEYPADUNLOCKEDMESSAGE_TIMER);
                        g_keylock_context.gKeyPadLockFlag = 0;
                    #ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
                        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
                    #endif 

                    #ifdef __MMI_TOUCH_SCREEN__
                        ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_UNLOCK);
                    #else 
                        IdleResetStatusIcon(STATUS_ICON_KEYPAD_LOCK);
                    #endif 

                    }
                    else
                    {
                        HandlePoundKeyForUnlock();
                    }

                #ifdef __MMI_TOUCH_SCREEN__     /* unblock pen for touch screen phone */
                    mmi_pen_unblock();
                #endif 
                }
            #endif /* __MMI_SLIDE__ */ /* } */

            #ifdef __MMI_CLAMOPEN_STOP_SCRSAVER__
                if (GetActiveScreenId() == IDLE_SCREEN_SCREENSAVER_ID)
                {
                    GoBackHistory();    /* Screensaver is running */
                }
                else
            #endif /* __MMI_CLAMOPEN_STOP_SCRSAVER__ */ 
                    mmi_idle_restart_screensaver_timer();   /* diamond, 2006/01/16 Restart screensaver timer when clam is open */
            }

        #ifdef __MMI_ENGINEER_MODE__
            gClamOpenCnt++;
        #endif 

            break;
        }

        case EXT_DEV_CLAM_CLOSE:    /* Clam close */
        {
            gMMIClamState = 0;

            if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
            {
            #ifdef __MMI_UCM__
                mmi_ucm_app_clam_close();
            #else
                NotifyCMClampClose();
            #endif   

            #if (defined __MMI_CLAMCLOSE_BACK2IDLE__ || defined __MMI_SUBLCD_SHOW_ANALOG_CLOCK__)
                ClamCloseGotoIdleScreen();
            #endif                 
                
            #ifndef __MMI_SLIDE__
                CloseBacklight();
            #else /* __MMI_SLIDE__ */ 
                if (AlmIsRTCPwron())
                {
                    TurnOnBacklight(0);
                }
                else
                {
                    TurnOnBacklight(1);
                }
            #endif /* __MMI_SLIDE__ */ 

                if (IsClamToneAllow()&& mdi_audio_mma_is_idle())
                {
                    playRequestedTone(COVER_CLOSE_TONE);
                }

            #if defined(__MMI_SUBLCD_CAMERA__)
                if ( mmi_idle_is_on_idle_screen()
                     && mmi_bootup_is_sim_valid() 
                     && !g_keylock_context.gKeyPadLockFlag)
                {
                    SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
                }
            #endif

            }
            else
            {
            #ifdef __MMI_UCM__
                mmi_ucm_app_clam_close();
            #else
                NotifyCMClampClose();
            #endif               		
            }
            	

        #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
            ForceSubLCDScreen(ShowSubLCDAnalogClockScreen);
        #endif 


        #ifdef __MMI_ENGINEER_MODE__
            gClamCloseCnt++;
        #endif 
            break;
        }
    #endif /* __MMI_CLAMSHELL__ */ /* } */

        default:
            break;
    }

    /* Popup screen display permisstion flag */
    /* Shall reset this flag in the end of msg handler func */
    SetInterruptPopupDisplay(POPUP_ALL_ON);
}

/*
 *Earphone_Handling_Functions
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_is_earphone_plug_in
 * DESCRIPTION
 *  tell other applications if the earphone exist
 * PARAMETERS
 *  void
 * RETURNS
 *  yse or no
 *****************************************************************************/
BOOL mmi_gpio_is_earphone_plug_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (isEarphonePlugged == 1);
}


/*****************************************************************************
 * FUNCTION
 *  EarphoneConnectHdlr
 * DESCRIPTION
 *  General handler for earphone plug in/out
 *  
 *  PARAMETERS: is_in
 *  is_in       [IN]        
 *****************************************************************************/
static void EarphoneConnectHdlr(BOOL is_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not switch profile if not normal power on mode */
    /* 1. Charge power on --> X */
    /* 2. Alarm power on --> X  */
    /* 3. RTC power on --> X   */
#ifdef __MMI_UI_DALMATIAN_STATUSBAR__
    disable_statusbar_fill_background();
#endif 

    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION)
    {
        EarphoneDisplayPopup(is_in);
        
        if (is_in)
        {
            GpioEarphonePlugIn();
        }
        else
        {
            GpioEarphonePlugOut();
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
            if (mmi_fmrao_sub_exit_by_earphone_plug_out())
            {
                /* Because the clam is closed, we don't need to display the popup at mainLCD */
                return;
            }
        #endif
        }
    }
    else
    {
        if (is_in)
        {
            isEarphonePlugged = 1;  /* diamond, 2005/10/28 Fit the case of alarm power on + GPIO detection + keypad power on */
            aud_mode_to_resume = mdi_audio_get_audio_mode();
            mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
            mmi_profiles_earphone_plug_in_callback();
        #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
            IdleSetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        #endif 
        }
        else
        {
            isEarphonePlugged = 0;
            mdi_audio_set_audio_mode(aud_mode_to_resume);
            mmi_profiles_earphone_plug_out_callback();
        #if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
            IdleResetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
        #endif 
        }
    }
#ifdef __MMI_UI_DALMATIAN_STATUSBAR__
    enable_statusbar_fill_background();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  EarphonePopupSublcd
 * DESCRIPTION
 *  Display earphone plug in/out popup on SubLCD
 *  
 *  PARAMETERS: void
 *****************************************************************************/
void EarphonePopupSublcd()
{
	DisplaySubLcdPopup(IMG_EARPHONE_POPUP_SUBLCD);
}


/*****************************************************************************
 * FUNCTION
 *  EarphoneDisplayPopup
 * DESCRIPTION
 *  Display earphone plug in/out popup
 *  
 *  PARAMETERS: BOOL
 *  is_plugin       [IN]        
 *****************************************************************************/
static void EarphoneDisplayPopup(BOOL is_plugin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    U8 pp_flag, tone_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Application who wanna stop popup has to intercept related messages and set the flag */
    pp_flag = GetInterruptPopupDisplay();
    if ((pp_flag & POPUP_DSPL_ON) == 0)
    {
        return;
    }

    if (pp_flag & POPUP_TONE_ON)
    {
        tone_id = AUX_TONE;
    }

    /* Cases not allow to display popup */
    /* 1. Call manager adjusting history */
    /* 2. During power on animation */
    /* 3. Power on mode is neither Keypad nor Exception (Means, Alarm, Charger, Usb) */
    /* 4. In Engineer mode */
    /* 5. In Factory mode  */
    if ((GetTransitionToActiveFlag() == MMI_TRUE)
        || (mmi_bootup_is_in_power_on_period() == MMI_TRUE)
        || (g_pwr_context.PowerOnMode != POWER_ON_KEYPAD && g_pwr_context.PowerOnMode != POWER_ON_EXCEPTION))
    {
        return;
    }

#ifdef __MMI_ENGINEER_MODE__
    if (gCurrentMode == ENGINEERING_MODE)
    {
        return;
    }
#endif /* __MMI_ENGINEER_MODE__ */ 

#ifdef __MMI_FACTORY_MODE__
    if (gCurrentMode == FACTORY_MODE)
    {
        return;
    }
#endif /* __MMI_FACTORY_MODE__ */ 

#ifdef __CTM_SUPPORT__
    if (mmi_ctm_is_tty_on() == MMI_TRUE)
    {
        if (is_plugin == MMI_TRUE)
        {
            str_id = STR_CTM_TTY_PLUG_IN;
        }
        else
        {
            str_id = STR_CTM_TTY_PLUG_OUT;
        }
    }
    else
#endif /* __CTM_SUPPORT__ */ 
    {
        /* Display popup according plug in/out */
        if (is_plugin == MMI_TRUE)  /* Plug in */
        {
            str_id = STR_GLOBAL_EARPHONE_IN;
        }
        else    /* Plug out */
        {
            str_id = STR_GLOBAL_EARPHONE_OUT;
        }
    }

    /* Should turn on backlight first to make LCD sleep out */
    TurnOnBacklight(1);

    DisplayPopup((U8*) GetString(str_id), IMG_EARPHONE_POPUP_MAINLCD, 0, UI_POPUP_NOTIFYDURATION_TIME, tone_id);
#ifdef __MMI_SUBLCD__
    if (MMI_TRUE == is_plugin)
    {
        ForceSubLCDScreen(EarphonePopupSublcd);//fugui for sublcd master
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GpioEarphonePlugIn
 * DESCRIPTION
 *  General action after earphone plug in
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void GpioEarphonePlugIn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    isEarphonePlugged = 1;
#ifdef __CTM_SUPPORT__
    mmi_ctm_switch_tty_status(MMI_TRUE);
    if (mmi_ctm_is_tty_on())
    {
    	  /* take as TTY, don't switch profile */
        return;
    }
#endif /* __CTM_SUPPORT__ */ 
    mmi_profiles_earphone_plug_in_callback();
#if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) ||  defined(__MMI_BT_SUPPORT__))
    IdleSetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  GpioEarphonePlugOut
 * DESCRIPTION
 *  General action after earphone plug out
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void GpioEarphonePlugOut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    isEarphonePlugged = 0;
#ifdef __CTM_SUPPORT__
    mmi_ctm_switch_tty_status(MMI_FALSE);
    if (mmi_ctm_is_tty_on())
    {
        /* take as TTY, don't switch profile */
        return;
    }
#endif /* __CTM_SUPPORT__ */ 
    mmi_profiles_earphone_plug_out_callback();
#if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__))
#if defined(__MMI_BT_SUPPORT__)
    if (!mmi_bt_is_hs_connected() && !mmi_bt_is_a2dp_connected())
#endif 
    {
        IdleResetStatusIcon(STATUS_ICON_EARPHONE_INDICATOR);
    }
#endif /* (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_SUPPORT__)) */ 
}

/*
 * Clam_handling_functions
 */


#ifdef __MMI_GAME__
/*****************************************************************************
 * FUNCTION
 *  IsCurrentScrGameScr
 * DESCRIPTION
 *  temp solution for checking if current screen is game screen
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
BOOL IsCurrentScrGameScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetExitScrnID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_id == GFX_MENU_SCREEN ||
        scr_id == GFX_GAME_SCREEN ||
        scr_id == GFX_LEVEL_SCREEN ||
        scr_id == GFX_GRADE_SCREEN ||
        scr_id == GFX_HELP_SCREEN ||
        scr_id == GFX_GAMEOVER_SCREEN)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_GAME__ */


#if defined(__MMI_CLAMSHELL__) || defined(__MMI_SLIDE__)
/*****************************************************************************
 * FUNCTION
 *  IsClamToneAllow
 * DESCRIPTION
 *  Query if clam tone allow to play (No other audio tone is playing, except clam tone it self
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static BOOL IsClamToneAllow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("IsClamToneAllow??");
    PRINT_INFORMATION("IsClamToneAllow?? is in call?: %d",isInCall());
    PRINT_INFORMATION("IsClamToneAllow?? is wap call?: %d",IsWapCallPresent());
    if (((g_pwr_context.PowerOnMode==POWER_ON_KEYPAD) || (g_pwr_context.PowerOnMode==POWER_ON_EXCEPTION)) 
        && (!AlmIsRTCPwron()) && ((!isInCall()) || (IsWapCallPresent()))
        && (!AlmIsTonePlaying())
#ifdef __MMI_AUDIO_PLAYER__
        && (!mmi_audply_is_play_activated())
#endif 
#ifdef __MMI_FM_RADIO__
        && (!mmi_fmrdo_is_power_on())
#endif 
#ifdef __MMI_SLIDESHOW__
        && (!mmi_slidshow_aud_is_playing())
#endif
#ifdef __MMI_VIDEO_PLAYER__
        && (!mmi_vdoply_is_in_app())
        && (!mdi_video_is_playing())        
#endif
#ifdef __MMI_VIDEO_RECORDER__
        && (!mmi_vdorec_is_in_app())
        && (!mdi_video_is_recording())        
#endif
#ifdef __MMI_GAME__
        && (!IsCurrentScrGameScr())
#endif
        )
        return MMI_TRUE;
    else
    {
        return MMI_FALSE;
    }

}
#endif /* #if defined(__MMI_CLAMSHELL__) || defined(__MMI_SLIDE__) */


/*****************************************************************************
 * FUNCTION
 *  IsClamClose
 * DESCRIPTION
 *  Query clam statue
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
BOOL IsClamClose(void)
{
#ifdef __MMI_CLAMSHELL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gMMIClamState)
    {
        return MMI_TRUE;    /* 0: Close */
    }
    else
#endif /* __MMI_CLAMSHELL__ */ 
        return MMI_FALSE;   /* 1: Open */
}


/*****************************************************************************
 * FUNCTION
 *  SetClamState
 * DESCRIPTION
 *  Set clam state
 * PARAMETERS
 *  clam_state      [IN]        Clam state
 * RETURNS
 *  void
 *****************************************************************************/
void SetClamState(U16 clam_state)
{
#ifdef __MMI_CLAMSHELL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clam_state == EXT_DEV_CLAM_OPEN)
    {
        gMMIClamState = 1;  /* open */
    }
    else if (clam_state == EXT_DEV_CLAM_CLOSE)
    {
        gMMIClamState = 0;  /* close */
    }
    else
    {
        MMI_ASSERT(0);  /* wrong parameter */
    }

#else /* __MMI_CLAMSHELL__ */ 
    MMI_ASSERT(0);  /* shall not call this function when no clam support */
#endif /* __MMI_CLAMSHELL__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  ClamCloseGotoIdleScreen
 * DESCRIPTION
 *  Function for clam close go back to idle screen
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
#if (defined(__MMI_CLAMCLOSE_BACK2IDLE__) || defined (__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) )
static void ClamCloseGotoIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (backlight_check_call_present())
    {
        if (isEarphonePlugged == 1
    #if defined(__MMI_BT_SUPPORT__)
            || mmi_bt_is_incall_aud_swap2bt() == MMI_TRUE
    #endif 
            )
            return;
    }
    PRINT_INFORMATION("ClamCloseGotoIdleScreen():END Key Press, FP: %x", GetKeyHandler(KEY_END, KEY_EVENT_DOWN));

#ifdef __MMI_FACTORY_MODE__
    if (gCurrentMode == FACTORY_MODE)
    {
        FM_RestoreAudio();
        return;
    }
#endif /* __MMI_FACTORY_MODE__ */ 

    ClearKeyEvents();
    ExecuteCurrKeyHandler(KEY_END, KEY_EVENT_DOWN);

    #ifdef __MMI_SUBLCD_MASTER_MODE__
    SubLCDMasterModeClamclosed();
    #endif

}
#endif /* (defined(__MMI_CLAMCLOSE_BACK2IDLE__) || defined (__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) ) */ 

/*
 * LED_pattern_handling_functions
 */


/*****************************************************************************
 * FUNCTION
 *  GetBackgroundPattern
 * DESCRIPTION
 *  Returns Existing Pattern
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
U8 GetBackgroundPattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 band_pattern = LED_NoService;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.LowBatteryFlag && (!g_charbat_context.isChargerConnected))    /* Robin 1217, Charger connect shall not play battery low pattern */
    {
        band_pattern = LED_BATTERY_LOW;
    }
#ifdef __MMI_LED_POWERON_CHARGEFULL__
    else if (g_charbat_context.ChargingComplete == 1)
    {
        band_pattern = LED_FullCharging;
    }
#endif /* __MMI_LED_POWERON_CHARGEFULL__ */ 
    else if (mmi_bootup_is_roaming() == MMI_TRUE)
    {
        band_pattern = LED_Roaming;
    }
    else if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
    {
        switch (g_pwr_context.CurrentCampOnBand)
        {
            case NW_BAND_PGSM900:
            case NW_BAND_EGSM900:
            case NW_BAND_RGSM900:
                band_pattern = LED_Connect900;
                break;
            case NW_BAND_DCS1800:
                band_pattern = LED_Connect1800;
                break;
            case NW_BAND_PCS1900:
                band_pattern = LED_Connect1900;
                break;
            default:
                band_pattern = LED_Connect900;
                break;
        }
    }
    else if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE)
    {
        band_pattern = LED_LimitService;
    }
    else
    {
        band_pattern = LED_NoService;
    }

    return band_pattern;
}


/*****************************************************************************
 * FUNCTION
 *  PlayPatternReq
 * DESCRIPTION
 *  Plays a pattern on vibrator or LED
 *  
 *  PARAMETERS:
 *  pattern     [IN]        
 *  action      [IN]        ON/OFF
 *****************************************************************************/
void PlayPatternReq(U8 pattern, U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signed char pat = (signed char)pattern;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gCurrentMode == ENGINEERING_MODE || gCurrentMode == FACTORY_MODE)
    {
        return;
    }

    /* Other module might request to obtain control of LEDs from MMI */
    if (gpioOutOfCtrl == 1 && !(pat >= VIB_PATTERN_BEGIN && pat <= VIB_PATTERN_END))
    {
        return;
    }

    /* Background LED pattern (for example: Camp on LED, Low battery...etc) */
    /* play request might comes anytime, it will interrupt the on going  */
    /* caller group pattern */
    if ((IsCallerGroupPatternPlaying)
        && (((pat >= LED_PATTERN_BEGIN) && (pat < LED_Caller1)) || ((pat > LED_Caller6) && (pat <= LED_PATTERN_END))))
    {
        return;
    }

    if ((!g_phnset_gpio_cntx_p->led_setting) && pattern == GetBackgroundPattern() && action != PLAY_STOP)
    {
        return;
    }

    SendPlayPatternReqToHW(pat, action);

    /* Start play CampOn LED pattern */
    if ((pat >= LED_PATTERN_BEGIN && pat < LED_PATTERN_END) && 
        (action == PLAY_STOP) && 
        (g_phnset_gpio_cntx_p->led_setting) && 
        (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE))
    {
        SendPlayPatternReqToHW(GetBackgroundPattern(), PLAY_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PlayPatternCallerGroup
 * DESCRIPTION
 *  Plays pattern as caller group functionality
 *  
 *  PARAMETERS:
 *  pattern     [IN]        
 *****************************************************************************/
void PlayPatternCallerGroup(MMI_LEDLIGHT_STATUS_ENUM pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsCallerGroupPatternPlaying = 1;

    switch (pattern)
    {
        case COLOR_PATTERN1:
            StartLEDPatternCaller1();
            break;
        case COLOR_PATTERN2:
            StartLEDPatternCaller2();
            break;
        case COLOR_PATTERN3:
            StartLEDPatternCaller3();
            break;
        case COLOR_PATTERN4:
            StartLEDPatternCaller4();
            break;
        case COLOR_PATTERN5:
            StartLEDPatternCaller5();
            break;
        case COLOR_PATTERN6:
            StartLEDPatternCaller6();
            break;
        default:
            IsCallerGroupPatternPlaying = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  StopPatternCallerGroup
 * DESCRIPTION
 *  Stops pattern as caller group functionality
 *  
 *  PARAMETERS:
 *  pattern     [IN]        
 *****************************************************************************/
void StopPatternCallerGroup(MMI_LEDLIGHT_STATUS_ENUM pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsCallerGroupPatternPlaying = 0;

    switch (pattern)
    {
        case COLOR_PATTERN1:
            StopLEDPatternCaller1();
            break;
        case COLOR_PATTERN2:
            StopLEDPatternCaller2();
            break;
        case COLOR_PATTERN3:
            StopLEDPatternCaller3();
            break;
        case COLOR_PATTERN4:
            StopLEDPatternCaller4();
            break;
        case COLOR_PATTERN5:
            StopLEDPatternCaller5();
            break;
        case COLOR_PATTERN6:
            StopLEDPatternCaller6();
            break;
    }
}

/*
 * Tone_ID_Range_Qery_functions
 */


/*****************************************************************************
 * FUNCTION
 *  GetRingToneRange
 * DESCRIPTION
 *  Gets Tone Range for Ring Tones
 *  
 *  PARAMETERS:
 *  startId     [IN]        
 *  totalId     [IN]        
 *****************************************************************************/
void GetRingToneRange(U8 *startId, U8 *totalId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 endId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_get_fixed_imelody_range(startId, &endId);
    *totalId = endId - *startId + 1;
}


/*****************************************************************************
 * FUNCTION
 *  GetMidiRange
 * DESCRIPTION
 *  Gets Tone Range for Midi Tones
 *  
 *  PARAMETERS:
 *  startId     [IN]        
 *  totalId     [IN]        
 *****************************************************************************/
void GetMidiRange(U8 *startId, U8 *totalId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 endId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_get_fixed_midi_range(startId, &endId);
    *totalId = endId - *startId + 1;
}


/*****************************************************************************
 * FUNCTION
 *  GetToneRange
 * DESCRIPTION
 *  Gets Tone Range for General Tones
 *  
 *  PARAMETERS: startid: Starting Range Value
 *  startId     [IN]        
 *  totalId     [IN]        
 *****************************************************************************/
void GetToneRange(U8 *startId, U8 *totalId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 endId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_get_fixed_sound_range(startId, &endId);
    *totalId = endId - *startId + 1;
}


/*****************************************************************************
 * FUNCTION
 *  GetMiscToneRange
 * DESCRIPTION
 *  Gets Tone Range for Misc Tones
 *  
 *  PARAMETERS: startid: Starting Range Value
 *  startId     [IN]        
 *  totalId     [IN]        
 *****************************************************************************/
void GetMiscToneRange(U8 *startId, U8 *totalId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 endId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_get_fixed_message_sound_range(startId, &endId);
    *totalId = endId - *startId + 1;
}

/* 
 * Backlight_handling_functions
 */


/*****************************************************************************
 * FUNCTION
 *  GpioWakeUpTimer
 * DESCRIPTION
 *  Wake up timer
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void GpioWakeUpTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resume timer if suspended */
    if (isTimerSuspend == 1)
    {
//        if (mmi_bootup_get_active_flight_mode() == 0)
//        {
            mmi_frm_resume_timers(TIMER_IS_NO_ALIGNMENT);
//        }
        isTimerSuspend = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  GpioTurnOffKeypadLight
 * DESCRIPTION
 *  turn off keypad backlight
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
static void GpioTurnOffKeypadLight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* turn off keypad backlight */
    StopTimer(GPIO_KEYPAD_LIGHT_TIMER);
    if (keypad_backlight == 1)
    {
	 KeyPadBackLightOff();
        keypad_backlight = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GpioLCDSleepIn
 * DESCRIPTION
 *  Wake up LCM
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void GpioLCDSleepIn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gIsInSleepMode == FALSE)
    {
        /* stop screensaver if need, since it might playing video */
        mmi_scrsvr_lcd_sleepin_handler();

        /* tvout sleepin */
    #ifdef __MMI_TVOUT__
        mmi_phnset_tvout_lcd_sleepin_handler();
    #endif 
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audply_turn_off_spectrum();
    #endif 

    #if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__)
		wndrv_LCD_isOFF();
    #endif /* #if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__) */

        lcd_sleep_in(MAIN_LCD);
        gIsInSleepMode = TRUE;

    #ifdef __MMI_TOUCH_SCREEN__
        /* diamond, 2006/06/22 Pen will not be blocked if backlight is becoming off */
        if ((g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen || g_keylock_context.IsOnKeyLockCallbackScreen) && g_keylock_context.gKeyPadLockFlag)
        {
            mmi_pen_unblock();
        }
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  GpioLCDSleepOut
 * DESCRIPTION
 *  Sleep LCM
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void GpioLCDSleepOut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gIsInSleepMode)
    {
        //ClearInterruptEventHandler(MSG_ID_MMI_EQ_ALARM_IND);

        lcd_sleep_out(MAIN_LCD);
        gIsInSleepMode = FALSE;

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audply_turn_on_spectrum();
    #endif 

        update_mainlcd_dt_display();
        update_sublcd_dt_display();
    #if defined(__MMI_SUBLCD__)
        {
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_repaint_all();
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        }
    #endif /* defined(__MMI_SUBLCD__) */ 

        /* redraw main lcd */
        gdi_lcd_repaint_all();

        /* resume screensaver if it is playing before sleep-in, must after lcd sleep out */
        mmi_scrsvr_lcd_sleepout_handler();

    #if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__)
        wndrv_LCD_isON();
    #endif /* #if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__) */
        
        /* tvout sleepout */
    #ifdef __MMI_TVOUT__
        mmi_phnset_tvout_lcd_sleepout_handler();
    #endif 

    #ifdef __MMI_TOUCH_SCREEN__
        /* diamond, 2006/06/09 Pen will not be blocked if keypad lock timeout after backlight is off */
	/*shaokai modify it start 090901*/
        //if ((g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen || g_keylock_context.IsOnKeyLockCallbackScreen) && g_keylock_context.gKeyPadLockFlag)
        if ((g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen) && g_keylock_context.gKeyPadLockFlag)
        {
            mmi_pen_block();
        }
	/*shaokai modify it end 090901*/
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
}





/* 2009.07.20 added by hongzhe.liu for keyenter backlight + */
#ifdef KEY_ENTER_BACKLIGHT_SUPPORT
void PlayKeyEnterBacklight(gpio_device_keyenter_backlight_typedef style)
{
	SetGPIOLevelReq(GPIO_DEV_KEYENTER_BACKLIGHT, style);	
}
#endif
/* 2009.07.20 added by hongzhe.liu for keyenter backlight - */












/*****************************************************************************
 * FUNCTION
 *  GpioTurnOnKeypadLight
 * DESCRIPTION
 *  turn on keypad backlight
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void GpioTurnOnKeypadLight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* turn on keypad backlight if currently off and clam open */
    if (gMMIClamState == 1 && g_keylock_context.gKeyPadLockFlag == 0)//keypad_backlight == 0 &&//yuyang
    {
	 KeyPadBackLightOn();
        keypad_backlight = 1;
    }
    StartTimer(GPIO_KEYPAD_LIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, GpioTurnOffKeypadLight);

}
/*****************************************************************************
 * FUNCTION
 *  Get key backlight status
 * DESCRIPTION
 *  Get key backlight status
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
U8 Get_KeypadLight_Status(void) //LIJUNZHAO_ADD_GET_KEYBACK_STATUS_080428
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "keypad_backlight:%d", keypad_backlight);
    return keypad_backlight;
}
#ifdef MMI_BK_LIGHT_DELAY_TIME


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_set_main_lcd_level_5
 * DESCRIPTION
 *  Set main LCD level to 5.
 *  PARAMETERS:
 *  void
 *****************************************************************************/
static void mmi_gpio_set_main_lcd_level_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
}
#endif /* MMI_BK_LIGHT_DELAY_TIME */ 


/*****************************************************************************
 * FUNCTION
 *  IsBacklightOn
 * DESCRIPTION
 *  Test whether the backlight is on (half-light or full-light)
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
MMI_BOOL IsBacklightOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_backlight)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_get_backlight_timer_state
 * DESCRIPTION
 *  get backlight timer state
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
MMI_GPIO_BACKLIGHT_TIMER_STATE mmi_gpio_get_backlight_timer_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gBackLightTimerStatus;
}


/*****************************************************************************
 * FUNCTION
 *  HalfModeBacklight
 * DESCRIPTION
 *  Takes the Backlight to Half Mode
 *  (Backlit is dimmed but not black)
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void HalfModeBacklight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gbacklight_mode == 1)   /* for AT command */
    {
        if (sublcd_backlight == 0)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
            sublcd_backlight = 1;
        }

        if (lcd_backlight == 0 && gMMIClamState == 1)   /* sleep mode */
        {
        #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
            GpioLCDSleepOut();

            UI_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

            update_mainlcd_dt_display();
            update_sublcd_dt_display();

            /* resume screensaver if it is playing before sleep-in, must after lcd sleep out */
            mmi_scrsvr_lcd_sleepout_handler();

            /* tvout sleepout */
        #ifdef __MMI_TVOUT__
            mmi_phnset_tvout_lcd_sleepout_handler();
        #endif 
        #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
            SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL1);
            lcd_backlight = 1;
        }

        if (isTimerSuspend == 1)
        {
//            if (mmi_bootup_get_active_flight_mode() == 0)
//            {
                mmi_frm_resume_timers(TIMER_IS_NO_ALIGNMENT);
//            }
            isTimerSuspend = 0;
        }
        if (gBackLightTimerStatus > MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE)
        {
            StopTimer(BACKLIGHT_TIMER);
            StartTimer(BACKLIGHT_TIMER, LCD_CLAM_OPEN_HALFLITE_TO_OFF_TIME, BacklightTimerHdlr);
            gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
        }
    }
}

#if defined(__MMI_SYNC_LCD_GPIO_MODE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_turn_on_all_light
 * DESCRIPTION
 *  Turn on all light to whole bright
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gpio_turn_on_all_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "turn_on_all_light() lcd_backlight=%d", lcd_backlight);    
    
    GpioLCDSleepOut();
    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    lcd_backlight = 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_turn_off_all_light
 * DESCRIPTION
 *  Turn off all light to whole dark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gpio_turn_off_all_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "turn_off_all_light() lcd_backlight=%d", lcd_backlight);    
    
    /* set lcd backlight to half mode */
    if (lcd_backlight != 0) /* backlight is on */
    {
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
        lcd_backlight = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  TurnOffBacklight
 * DESCRIPTION
 *  It is typically paired with TurnOnBacklight(0) in order to resume backlight timer.
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void TurnOffBacklight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "TurnOffBacklight(): lcd_backlight=%d, BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    
    
    /* Share the same code for target and PC simulator */

    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

    if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
    {
        StopTimer(BACKLIGHT_TIMER);
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  BacklightTimerHdlr
 * DESCRIPTION
 *  Timer handler to switch backlight state
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
static void BacklightTimerHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "BacklightTimerHdlr() lcd_backlight=%d, BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    

    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

    if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
    {
        StopTimer(BACKLIGHT_TIMER);
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    }
    else if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE)
    {
        if (lcd_backlight == 2)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL1);
            lcd_backlight = 1;
        }

        StopTimer(BACKLIGHT_TIMER);
        StartTimer(BACKLIGHT_TIMER, LCD_CLAM_OPEN_HALFLITE_TO_OFF_TIME, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
    }
    else    /* gBackLightTimerStatus == 2 */
    {
        if (lcd_backlight == 1)
        {
            if ((g_phb_cntx.processing == FALSE)
                && (mdi_audio_get_state() != MDI_AUDIO_RECORD) && (mdi_audio_get_state() != MDI_AUDIO_RECORD_PAUSED))
            {
                SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);

            #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)   /* { */
                GpioLCDSleepIn();
            #ifdef __MMI_LCMSLEEP_BACK2IDLE__
                LCMSleepGotoIdleScreen();
            #endif 
            #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ /* } */
                lcd_backlight = 0;
            }

            gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_IN_SLEEP_MODE;
        }

    #ifdef __MMI_CLAMSHELL__
        if (isTimerSuspend == 0
            && g_charbat_context.isChargerConnected == 0
            /* && !backlight_check_call_present() */ && mmi_msg_need_mem_full_ind() == 0 && g_phb_cntx.processing == false
    #if defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_TVOUT__)
            && mmi_vdoply_is_in_play_and_tvout_enable() == MMI_FALSE
    #endif 
            && mdi_audio_get_state() != MDI_AUDIO_RECORD && mdi_audio_get_state() != MDI_AUDIO_RECORD_PAUSED)
    #else /* __MMI_CLAMSHELL__ */ 
        if (isTimerSuspend == 0 && g_charbat_context.isChargerConnected == 0 /*&& !backlight_check_call_present()*/
    #if defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_TVOUT__)
            && mmi_vdoply_is_in_play_and_tvout_enable() == MMI_FALSE
    #endif 
            && g_phb_cntx.processing == FALSE && mdi_audio_get_state() != MDI_AUDIO_RECORD &&
            mdi_audio_get_state() != MDI_AUDIO_RECORD_PAUSED)
    #endif /* __MMI_CLAMSHELL__ */ 
        {
//            if (mmi_bootup_get_active_flight_mode() == 0)
//            {
                mmi_frm_suspend_timers(TIMER_IS_NO_ALIGNMENT);
//            }
            isTimerSuspend = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  TurnOnBacklight
 * DESCRIPTION
 *  Turns On the backlight
 * PARAMETERS
 *  time_enum       [IN]        Time duration type
 *****************************************************************************/
void TurnOnBacklight(gpio_backlight_time_enum time_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "TurnOnBacklight() time_enum=%d, BLTimerStat=%d", time_enum, gBackLightTimerStatus);    
    
    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

#ifdef MMI_BK_LIGHT_DELAY_TIME
    StopMyTimer(GPIO_BACKLIGHT_DELAY_TIMER);
#endif 

    /* resume timer if suspended */
    if (isTimerSuspend == 1)
    {
//        if (mmi_bootup_get_active_flight_mode() == 0)
//        {
            mmi_frm_resume_timers(TIMER_IS_NO_ALIGNMENT);
//        }
        isTimerSuspend = 0;
    }
    
#ifdef LCM_MMI_TYPE_QUERY
#ifdef __MMI_LCD_PARTIAL_ON__
    /* If LCD is transmissive, there is meanless for partial display.
       But if LCD is reflective or transflective, user can see the display when backlight is off.
       In this case, when turn on backlight, handset should leave Screen saver */
   if (get_lcm_type)
   {
       if (get_lcm_type() == LCM_TRANSFLECTIVE_TYPE)
        {
            LeavePartialOnScreenSaverIfOk();
        }
    }
#endif    
#endif /* LCM_MMI_TYPE_QUERY */

    /* lcd backlight */
    if (lcd_backlight == 0)
    {
        lcd_backlight = 2;

    #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
        GpioLCDSleepOut();
    #endif 

    #ifdef __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__       /* { */

    #ifdef MMI_BK_LIGHT_DELAY_TIME
        StartTimer(GPIO_BACKLIGHT_DELAY_TIMER, MMI_BK_LIGHT_DELAY_TIME, mmi_gpio_set_main_lcd_level_5);
    #else 
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    #endif 

    #else /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* }{ */
        if (gMMIClamState == 1) /* clam is opened */
        {
        #ifdef MMI_BK_LIGHT_DELAY_TIME
            StartTimer(GPIO_BACKLIGHT_DELAY_TIMER, MMI_BK_LIGHT_DELAY_TIME, mmi_gpio_set_main_lcd_level_5);
        #else 
            SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        #endif 

            lcd_backlight = 2;
        }
        else    /* clam is closed */
        {
        #ifndef __MMI_SLIDE__
            SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL1);
            lcd_backlight = 1;
        #else
            #ifdef MMI_BK_LIGHT_DELAY_TIME
                StartTimer(GPIO_BACKLIGHT_DELAY_TIMER, MMI_BK_LIGHT_DELAY_TIME, mmi_gpio_set_main_lcd_level_5);
            #else 
                SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
            #endif 
                lcd_backlight = 2;        
        #endif 
        }
    #endif /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* } */
    }
    else if (lcd_backlight == 1)
    {
    #ifdef __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        lcd_backlight = 2;

    #else /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* }{ */
    #ifndef __MMI_SLIDE__
        if (gMMIClamState == 1 || !mmi_bootup_is_searching_or_idle_reached())   /* clam is opened */
    #endif 
        {
            SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
            lcd_backlight = 2;
        }
    #endif /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* } */
    }
    else if (lcd_backlight == 2 )  /* backlight off */
    {
    	SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }

    if (time_enum != GPIO_BACKLIGHT_PERMANENT)
   {
        /* turn on keypad backlight if currently off and clam open */
        GpioTurnOnKeypadLight();
    }

    /* start/stop timer according to input parameter */
    if (time_enum == GPIO_BACKLIGHT_PERMANENT)
    {
        StopTimer(BACKLIGHT_TIMER);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER;
    }
    else if (gBackLightTimerStatus != MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)    /* start a timer */
    {
        StopTimer(BACKLIGHT_TIMER);

    #ifdef __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    #else /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* }{ */
    #if defined (__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
        if (gMMIClamState == 1) /* clam is opened */
        {
            StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
            gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
        }
        else    /* clam is closed */
        {
            StartTimer(BACKLIGHT_TIMER, LCD_CLAM_CLOSE_HALFLITE_TO_OFF_TIME, BacklightTimerHdlr);
            gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
        }
    #else /* defined (__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    #endif /* defined (__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 
    #endif /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* } */
    }
}


/*****************************************************************************
 * FUNCTION
 *  CloseBacklight
 * DESCRIPTION
 *  Immeditae Baclight Close not going thru Half Mode
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void CloseBacklight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "CloseBacklight() lcd_backlight=%d BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    
    
    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

    /* stop backlight timer */
    if (gBackLightTimerStatus != MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
    {
        StopTimer(BACKLIGHT_TIMER);
    }

#ifdef __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__       /* { */
    if (lcd_backlight == 1) /* backlight is half light */
    {
        lcd_backlight = 2;
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }
    else if (lcd_backlight == 0)    /* backlight is off */
    {
        lcd_backlight = 2;
    #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
        GpioLCDSleepOut();

        update_mainlcd_dt_display();
        update_sublcd_dt_display();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        GpioWakeUpTimer();
        gIsInSleepMode = 0;
        /* resume screensaver if it is playing before sleep-in, must after lcd sleep out */
        mmi_scrsvr_lcd_sleepout_handler();

        SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
    #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }

#else /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* }{ */
    /* set lcd backlight to half mode */
    if (lcd_backlight == 2) /* backlight is on */
    {
        lcd_backlight = 1;
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL1);
    }
    else if (lcd_backlight == 0)    /* backlight is off */
    {
        lcd_backlight = 1;
    #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
        GpioLCDSleepOut();
        update_mainlcd_dt_display();
        update_sublcd_dt_display();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        GpioWakeUpTimer();
        gIsInSleepMode = 0;
        /* resume screensaver if it is playing before sleep-in, must after lcd sleep out */
        mmi_scrsvr_lcd_sleepout_handler();

        SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
    #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }
#endif /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ /* } */

    /* turn off keypad backlight */
    GpioTurnOffKeypadLight();
#ifdef __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__
    StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
    gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
#else /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ 
    StartTimer(BACKLIGHT_TIMER, LCD_CLAM_CLOSE_HALFLITE_TO_OFF_TIME, BacklightTimerHdlr);
    gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
#endif /* __MMI_GPIO_3_STAGE_SUB_BACKLIGHT__ */ 
}

#else /* defined(__MMI_SYNC_LCD_GPIO_MODE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_turn_on_all_light
 * DESCRIPTION
 *  Turn on all light to whole bright
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gpio_turn_on_all_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "turn_on_all_light() lcd_backlight=%d, BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    
    
    GpioLCDSleepOut();
    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    lcd_backlight = 2;

    SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
    sublcd_backlight = 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_turn_off_all_light
 * DESCRIPTION
 *  Turn off all light to whole dark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gpio_turn_off_all_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "turn_off_all_light() lcd_backlight=%d", lcd_backlight);    
    
    /* set lcd backlight to half mode */
    if (lcd_backlight != 0) /* backlight is on */
    {
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
        lcd_backlight = 0;
    }

    /* turn on sub-lcd baclight */
    if (sublcd_backlight != 0)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL0);
        sublcd_backlight = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  TurnOffBacklight
 * DESCRIPTION
 *  Turns Off the backlight
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void TurnOffBacklight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "TurnOffBacklight() lcd_backlight=%d, BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    
        
    /* Share the same code for target and PC simulator */

    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

    if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER) /* resume backlight mechanism */
    {
        StopTimer(BACKLIGHT_TIMER);
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  BacklightTimerHdlr
 * DESCRIPTION
 *  Timer handler to switch backlight state
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
static void BacklightTimerHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "BacklightTimerHdlr() lcd_backlight=%d, BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    
    
    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

    if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER) /* resume backlight mechanism */
    {
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
        StopTimer(BACKLIGHT_TIMER);
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
    }
    else if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE)
    {
        if (lcd_backlight == 2) /* full light, switch to half light */
        {
            SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL1);
            lcd_backlight = 1;
        }

        if (sublcd_backlight == 1)
        {
            sublcd_backlight = 0;
            SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL0);
        }

        StopTimer(BACKLIGHT_TIMER);

    #ifdef __MMI_CLAMSHELL__
        if (gMMIClamState == 0)
        {
            StartTimer(BACKLIGHT_TIMER, LCD_CLAM_CLOSE_HALFLITE_TO_OFF_TIME, BacklightTimerHdlr);
        }
        else
    #endif /* __MMI_CLAMSHELL__ */ 
            StartTimer(BACKLIGHT_TIMER, LCD_CLAM_OPEN_HALFLITE_TO_OFF_TIME, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
    }
    else    /* gBackLightTimerStatus == 2 */
    {
        if (sublcd_backlight == 1)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL0);
            sublcd_backlight = 0;
        }

        if (lcd_backlight == 1)
        {
            if (/*!backlight_check_call_present()
                &&*/ (g_phb_cntx.processing == FALSE)
                && (mdi_audio_get_state() != MDI_AUDIO_RECORD) && (mdi_audio_get_state() != MDI_AUDIO_RECORD_PAUSED))
            {
            #ifdef __MMI_LCD_PARTIAL_ON__
                /* We do not enter partial display screen saver before idle screen */
                if (((mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE) || mmi_bootup_is_sim_removed() == MMI_TRUE)
                    && PhnsetIsScrSvrPartialOn())
                {
                    /* 1. Turn off backlight if defined(__MMI_GPIO_DISABLE_SLEEP_MODE__), but keep
                       half backlight if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__).
                       (Typically __MMI_GPIO_DISABLE_SLEEP_MODE__ means that LCM can 
                       retain display even when backlight is turned off, and hence we
                       can turn off backlight without making LCM sleep.)
                       
                       2. __MMI_LCMSLEEP_BACK2IDLE__ is currently ignored */
                    if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE)
                    {
                        EnterPartialOnScreenSaverIfOk();
                    }
                #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
                    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
                    lcd_backlight = 0;
                #endif /* defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
                }
                else
            #endif /* __MMI_LCD_PARTIAL_ON__ */ 
                {
                    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
                #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
                    GpioLCDSleepIn();

                #ifdef __MMI_LCMSLEEP_BACK2IDLE__
                    LCMSleepGotoIdleScreen();
                #endif 
                #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
                    lcd_backlight = 0;
                }
            }

            gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_IN_SLEEP_MODE;
        }

        if (isTimerSuspend == 0 && g_charbat_context.isChargerConnected == 0 /*&& !backlight_check_call_present()*/
    #ifdef __MMI_CLAMSHELL__
            && mmi_msg_need_mem_full_ind() == 0
    #endif 
    #if defined(__MMI_VIDEO_PLAYER__) && defined(__MMI_TVOUT__)
            && mmi_vdoply_is_in_play_and_tvout_enable() == MMI_FALSE
    #endif 
            && g_phb_cntx.processing == FALSE
            && mdi_audio_get_state() != MDI_AUDIO_RECORD && mdi_audio_get_state() != MDI_AUDIO_RECORD_PAUSED)
        {
//            if (mmi_bootup_get_active_flight_mode() == 0)
//            {
                mmi_frm_suspend_timers(TIMER_IS_NO_ALIGNMENT);
//            }
            isTimerSuspend = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  TurnOnBacklight
 * DESCRIPTION
 *  Turns On the backlight
 * PARAMETERS
 *  time_enum       [IN]        Time duration type
 *****************************************************************************/
void TurnOnBacklight(gpio_backlight_time_enum time_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "TurnOnBacklight() time_enum=%d, BLTimerStat=%d", time_enum, gBackLightTimerStatus);    
    
    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

#ifdef MMI_BK_LIGHT_DELAY_TIME
    StopMyTimer(GPIO_BACKLIGHT_DELAY_TIMER);
#endif 
    /* resume timer if suspended */
    if (isTimerSuspend == 1)
    {
//        if (mmi_bootup_get_active_flight_mode() == 0)
//        {
            mmi_frm_resume_timers(TIMER_IS_NO_ALIGNMENT);
//        }
        isTimerSuspend = 0;
    }

#ifdef LCM_MMI_TYPE_QUERY
#ifdef __MMI_LCD_PARTIAL_ON__
    /* If LCD is transmissive, there is meanless for partial display.
       But if LCD is reflective or transflective, user can see the display when backlight is off.
       In this case, when turn on backlight, handset should leave Screen saver */
   if (get_lcm_type)
   {
       if (get_lcm_type() == LCM_TRANSFLECTIVE_TYPE)
        {
            LeavePartialOnScreenSaverIfOk();
        }
    }

#endif    
#endif /* #ifdef LCM_MMI_TYPE_QUERY */

    /* turn on sub-lcd backlight if currently off */
    if (sublcd_backlight == 0)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        sublcd_backlight = 1;
    #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) && defined(__MMI_SUBLCD__)
        {
            S32 lcd_width;
            S32 lcd_height;

            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_get_dimension(&lcd_width, &lcd_height);
            UI_BLT_double_buffer(0, 0, lcd_width - 1, lcd_height - 1);
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

        }
    #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) && defined(__MMI_SUBLCD__) */ 
    }

    if (lcd_backlight == 0 && gMMIClamState == 1)   /* sleep mode and clam open */
    {
    #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)

        GpioLCDSleepOut();
        update_mainlcd_dt_display();
        update_sublcd_dt_display();
        UI_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

        /* resume screensaver if it is playing before sleep-in */
        mmi_scrsvr_lcd_sleepout_handler();

        /* tvout sleepout */
    #ifdef __MMI_TVOUT__
        mmi_phnset_tvout_lcd_sleepout_handler();
    #endif 

    #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 

    #ifdef MMI_BK_LIGHT_DELAY_TIME
        StartTimer(GPIO_BACKLIGHT_DELAY_TIMER, MMI_BK_LIGHT_DELAY_TIME, mmi_gpio_set_main_lcd_level_5);
    #else 
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    #endif 

        lcd_backlight = 2;
    }
    else if (lcd_backlight == 1 && gMMIClamState == 1)  /* backlight off and clam open */
    {
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        lcd_backlight = 2;
    }
    else if (lcd_backlight == 2 && gMMIClamState == 1)  /* backlight off and clam open */
    {
    	SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }

    if (time_enum != GPIO_BACKLIGHT_PERMANENT)
    {
        /* turn on keypad backlight if currently off and clam open */
        GpioTurnOnKeypadLight();
    }

    /* start/stop timer according to input parameter */
    if (time_enum == GPIO_BACKLIGHT_PERMANENT)
    {
        StopTimer(BACKLIGHT_TIMER);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER;
    }
    else if (gBackLightTimerStatus != MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)    /* start a timer */
    {
        StopTimer(BACKLIGHT_TIMER);
        StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
        gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CloseBacklight
 * DESCRIPTION
 *  Immeditae Baclight Close not going thru Half Mode
 *  We do not handle __MMI_LCD_PARTIAL_ON__ because CloseBacklight() is used only in clamshell
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void CloseBacklight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "CloseBacklight() lcd_backlight=%d, BLTimerStat=%d", lcd_backlight, gBackLightTimerStatus);    
    
    /* AT command disables backlight mechanism */
    if (gbacklight_mode == 0)
    {
        return;
    }

    /* stop backlight timer */
    if (gBackLightTimerStatus != MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
    {
        StopTimer(BACKLIGHT_TIMER);
    }

    /* turn off main-lcd backlight */
    if (lcd_backlight != 0)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
    #if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
        GpioLCDSleepIn();

    #ifdef __MMI_LCMSLEEP_BACK2IDLE__
        LCMSleepGotoIdleScreen();
    #endif 
    #endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 
        lcd_backlight = 0;
    }

    /* turn off keypad backlight */
    GpioTurnOffKeypadLight();

    /* turn on sub-lcd baclight */
    if (sublcd_backlight == 0)
    {
        GpioWakeUpTimer();
        gIsInSleepMode = 0;
        GpioLCDSleepOut();
        SetGPIOLevelReq(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        sublcd_backlight = 1;
    }

    StartTimer(BACKLIGHT_TIMER, g_phnset_gpio_cntx_p->bl_setting_hftime * 1000, BacklightTimerHdlr);
    gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
}
#endif /* defined(__MMI_SYNC_LCD_GPIO_MODE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_backlight_ctrl_req_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_BACKLIGHT_CONTROL_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gpio_backlight_ctrl_req_hdlr(void *msg, int mod_id , void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_backlight_control_req_struct *req = (mmiapi_backlight_control_req_struct*) msg;
    mmiapi_backlight_control_rsp_struct *rsp =
        (mmiapi_backlight_control_rsp_struct*) OslConstructDataPtr(sizeof(mmiapi_backlight_control_rsp_struct));

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BACKLIGHT_TIMER);

    if (req->on_off)
    {
        if (req->disable_timer)
        {
            mmi_gpio_turn_on_all_light();
            StopTimer(BACKLIGHT_TIMER);
            gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER;
        }
        else
        {
            if (gBackLightTimerStatus < MMI_GPIO_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE || gbacklight_mode == 0)
            {   /* resume backlight timer and turn on the backlight */
                TurnOnBacklight(1);

                /* if the timer is disable, resume timer */
                if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
                {
                    TurnOffBacklight();
                }
            }
            else
            {
                gBackLightTimerStatus = MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER;
                TurnOffBacklight();
            }
        }
    }
    else
    {
        mmi_gpio_turn_off_all_light();
    }

    if (gBackLightTimerStatus == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER) /* timer disabled */
    {
        rsp->disable_timer = TRUE;
    }
    else
    {
        rsp->disable_timer = FALSE;
    }

    rsp->on_off = req->on_off;

    Message.oslSrcId = MOD_MMI;
    if (mod_id == MOD_L1SP)
    {
        Message.oslDestId = MOD_MED;
    }
    else
    {
        Message.oslDestId = mod_id;
    }
    Message.oslMsgId = MSG_ID_MMIAPI_BACKLIGHT_CONTROL_RSP;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_led_ctrl_req_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_LED_CONTROL_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gpio_led_ctrl_req_hdlr(void *msg, int mod_id , void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_led_control_req_struct *req = (mmiapi_led_control_req_struct*) msg;
    mmiapi_led_control_rsp_struct *rsp =
        (mmiapi_led_control_rsp_struct*) OslConstructDataPtr(sizeof(mmiapi_led_control_rsp_struct));

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req->on_off)
    {
        /* disable led background play pattern */
        gpioOutOfCtrl = 1;
        StopLEDPatternBackGround();

        /* turn on led */
        SetBackLightStatusRedOn();
        SetBackLightStatusGreenOn();
        SetBackLightStatusBlueOn();
    }
    else
    {
        /* turn off led */
        SetBackLightStatusRedOff();
        SetBackLightStatusGreenOff();
        SetBackLightStatusBlueOff();

        /* enable led background play pattern */
        gpioOutOfCtrl = 0;
        StartLEDPatternBackGround();
    }

    rsp->on_off = req->on_off;

    Message.oslSrcId = MOD_MMI;
    if (mod_id == MOD_L1SP)
    {
        Message.oslDestId = MOD_MED;
    }
    else
    {
        Message.oslDestId = mod_id;
    }
    Message.oslMsgId = MSG_ID_MMIAPI_LED_CONTROL_RSP;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  InitHWBacklightTest
 * DESCRIPTION
 *  Initialisation function for Back Light Test
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void InitHWBacklightTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(SetBacklightMode, MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND);
}


/*****************************************************************************
 * FUNCTION
 *  SetBacklightModeExe
 * DESCRIPTION
 *  Sets BackLight Mode
 *  
 *  PARAMETERS: void
 *  mode        [IN]        
 *****************************************************************************/
void SetBacklightModeExe(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == 1)  /* enable backlight mechanism. */
    {
        gbacklight_mode = mode;
        TurnOffBacklight();
    }
    else    /* disable backlight mechanism. */
    {
        gbacklight_mode = 1;
        TurnOnBacklight(0);
        gbacklight_mode = mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetBacklightMode
 * DESCRIPTION
 *  Protocol Handler for MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND
 *  
 *  PARAMETERS: info: Data from L4
 *  info        [IN]        
 *****************************************************************************/
void SetBacklightMode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_sleep_mode_req_ind_struct *msg = (mmi_eq_set_sleep_mode_req_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetBacklightModeExe((U8) msg->on_off);

}

/*
 * Audio volume path                                
 */


/*****************************************************************************
 * FUNCTION
 *  EnableHandsFree
 * DESCRIPTION
 *  Enables Hands Free Mode
 *  
 *  PARAMETERS: mode
 *  void
 *****************************************************************************/
void EnableHandsFree(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_audio_mode(AUD_MODE_LOUDSPK);
    SetModeSpeechVolume();
}


/*****************************************************************************
 * FUNCTION
 *  DisbleHandsFree
 * DESCRIPTION
 *  Disables Hands Free Mode
 *  
 *  PARAMETERS: mode
 *  void
 *****************************************************************************/
void DisbleHandsFree(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isEarphonePlugged)
    {
    #ifdef __CTM_SUPPORT__
        if (mmi_ctm_is_tty_on() == MMI_FALSE)
    #endif 
        {
            mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
            SetModeSpeechVolume();
            return;
        }
    }
    mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
    SetModeSpeechVolume();
}


/*****************************************************************************
 * FUNCTION
 *  SaveSpeechVolume
 * DESCRIPTION
 *  Saves Speech Volume
 *  
 *  PARAMETERS:
 *  level       [IN]        
 *****************************************************************************/
void SaveSpeechVolume(U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 audio_mode = mdi_audio_get_audio_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_NORMAL:
            WriteValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_HEADSET:
            WriteValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_LOUDSPK:
            WriteValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
    }
    SetSpeechVolume(level);
}


/*****************************************************************************
 * FUNCTION
 *  SetModeSpeechVolume
 * DESCRIPTION
 *  Sets Speech Volume as per the mode
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void SetModeSpeechVolume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 audio_mode = mdi_audio_get_audio_mode();
    U8 level;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_NORMAL:
            ReadValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_HEADSET:
            ReadValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_LOUDSPK:
            ReadValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
    }
    if (level == 0xFF)
    {
        level = LEVEL4;
        WriteValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
        WriteValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
        WriteValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
    }
    SetSpeechVolume(level);
}


/*****************************************************************************
 * FUNCTION
 *  GetModeSpeechVolume
 * DESCRIPTION
 *  Gets Speech Volume as per the mode
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
U8 GetModeSpeechVolume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 audio_mode = mdi_audio_get_audio_mode();
    U8 level;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_NORMAL:
            ReadValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_HEADSET:
            ReadValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_LOUDSPK:
            ReadValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
    }
    if (level == 0xFF)
    {
        level = LEVEL4;
    }
    return level;
}

/*
 * Device control interface for other modules
 */


/*****************************************************************************
 * FUNCTION
 *  GpioCtrlReq
 * DESCRIPTION
 *  Api for other modules get gpio control
 *  
 *  PARAMETERS: action: MMIAPI_DEV_CTRL_GET / MMIAPI_DEV_CTRL_RELEASE
 *  action      [IN]        
 *****************************************************************************/
kal_uint8 GpioCtrlReq(kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == MMIAPI_DEV_CTRL_GET)
    {
        if (gpioOutOfCtrl == 1)
        {
            result = MMI_FALSE;
        }
        else
        {
            gpioOutOfCtrl = 1;
            StopLEDPatternBackGround();
        }
    }
    else if (action == MMIAPI_DEV_CTRL_RELEASE)
    {
        if (gpioOutOfCtrl == 0)
        {
            result = MMI_FALSE;
        }
        else
        {
            gpioOutOfCtrl = 0;
            StartLEDPatternBackGround();
            GpioTurnOffKeypadLight();
            TurnOnBacklight(1);
        }
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  GpioCtrlReqHdlr
 * DESCRIPTION
 *  Other module get device control through MMI
 *  
 *  PARAMETERS: mmiapi_device_get_ctrl_req_struct *
 *  inMsg       [IN]        
 *****************************************************************************/
void GpioCtrlReqHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_device_get_ctrl_req_struct *p = (mmiapi_device_get_ctrl_req_struct*) inMsg;
    mmiapi_device_get_ctrl_rsp_struct *p_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_out = OslConstructDataPtr(sizeof(mmiapi_device_get_ctrl_rsp_struct));
    p_out->result = GpioCtrlReq(p->action);

    GpioSendMsg(p->src_mod_id, MSG_ID_MMIAPI_DEVICE_GET_CTRL_RSP, (void*)p_out, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  GpioPlayReq
 * DESCRIPTION
 *  Other module control gpio device
 *  
 *  PARAMETERS: p_type, p_level
 *  p_type      [IN]        
 *  p_level     [IN]        
 *****************************************************************************/
kal_uint8 GpioPlayReq(kal_uint8 p_type, kal_uint8 p_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_TRUE;
    U8 device = 0, level = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_type)
    {
        case MMIAPI_DEV_TYPE_MAINLCD_BL:
            device = GPIO_DEV_LED_MAINLCD;
            break;
        case MMIAPI_DEV_TYPE_SUBLCD_BL:
            device = GPIO_DEV_LED_SUBLCD;
            break;
        case MMIAPI_DEV_TYPE_KEYPAD_BL:
            device = GPIO_DEV_LED_KEY;
            break;
        case MMIAPI_DEV_TYPE_LED_1:
            device = GPIO_DEV_LED_STATUS_1;
            break;
        case MMIAPI_DEV_TYPE_LED_2:
            device = GPIO_DEV_LED_STATUS_2;
            break;
        case MMIAPI_DEV_TYPE_LED_3:
            device = GPIO_DEV_LED_STATUS_3;
            break;
        case MMIAPI_DEV_TYPE_VIBRATOR:
            device = GPIO_DEV_VIBRATOR;
            break;
        default:
            result = MMI_FALSE;
            break;
    }

    switch (p_level)
    {
        case MMIAPI_DEV_LEVEL_0:
            level = LED_LIGHT_LEVEL0;
            break;
        case MMIAPI_DEV_LEVEL_1:
            level = LED_LIGHT_LEVEL1;
            break;
        case MMIAPI_DEV_LEVEL_2:
            level = LED_LIGHT_LEVEL2;
            break;
        case MMIAPI_DEV_LEVEL_3:
            level = LED_LIGHT_LEVEL3;
            break;
        case MMIAPI_DEV_LEVEL_4:
            level = LED_LIGHT_LEVEL4;
            break;
        case MMIAPI_DEV_LEVEL_5:
            level = LED_LIGHT_LEVEL5;
            break;
        default:
            result = MMI_FALSE;
            break;
    }
    SetGPIOLevelReq(device, level);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  GpioPlayReqHdlr
 * DESCRIPTION
 *  Other module play device function through MMI
 *  
 *  PARAMETERS: mmiapi_device_play_req_struct *
 *  inMsg       [IN]        
 *****************************************************************************/
void GpioPlayReqHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_device_play_req_struct *p = (mmiapi_device_play_req_struct*) inMsg;
    mmiapi_device_play_rsp_struct *p_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_out = OslConstructDataPtr(sizeof(mmiapi_device_play_rsp_struct));
    p_out->result = GpioPlayReq(p->type, p->level);
    GpioSendMsg(p->src_mod_id, MSG_ID_MMIAPI_DEVICE_PLAY_RSP, (void*)p_out, (void*)NULL);
}

/*******************************************************/
/*                                                     */
/*    Send Message to Lower layer                      */
/*                                                     */
/*******************************************************/


/*****************************************************************************
 * FUNCTION
 *  SendPlayPatternReqToHW
 * DESCRIPTION
 *  Send pattern request to H/W
 *  
 *  PARAMETERS: pattern: pattern to be played
 *  pattern     [IN]        
 *  action      [IN]        ON/OFF
 *****************************************************************************/
void SendPlayPatternReqToHW(U8 pattern, U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_play_pattern_req_struct *displayLedPattern;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = MSG_ID_MMI_EQ_PLAY_PATTERN_REQ;
    displayLedPattern = OslConstructDataPtr(sizeof(mmi_eq_play_pattern_req_struct));
    displayLedPattern->pattern = pattern;
    displayLedPattern->action = action;
    Message.oslDataPtr = (oslParaType*) displayLedPattern;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SetGPIOLevelReq
 * DESCRIPTION
 *  Set Levels of Devices like LCD, LEDs
 *  
 *  PARAMETERS: device: device
 *  device      [IN]        
 *  level       [IN]        Device Level
 *****************************************************************************/
void SetGPIOLevelReq(gpio_device_enum device, U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_exe_gpio_level_req_struct *setGPIOLevelReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __LCD_ESD_RECOVERY__
    if ((device == GPIO_DEV_LED_MAINLCD) || (device == GPIO_DEV_LED_SUBLCD))
    {
        if (level == LED_LIGHT_LEVEL0)
        {
            gdi_lcd_stop_esd_recovery_timer();
        }
        else
        {
            gdi_lcd_start_esd_recovery_timer();
        }
    }
#endif /* __LCD_ESD_RECOVERY__ */ 

    Message.oslMsgId = MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ;
    setGPIOLevelReq = OslConstructDataPtr(sizeof(mmi_eq_exe_gpio_level_req_struct));
    setGPIOLevelReq->gpio_dev_type = device;
    if ((device == GPIO_DEV_LED_MAINLCD) && (level == LED_LIGHT_LEVEL5))
    {
        setGPIOLevelReq->gpio_dev_level = g_phnset_gpio_cntx_p->bl_setting_level;
    }
    else
    {
        setGPIOLevelReq->gpio_dev_level = level;
    }
    Message.oslDataPtr = (oslParaType*) setGPIOLevelReq;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetMuteReq
 * DESCRIPTION
 *  Mutes the device
 *  
 *  PARAMETERS: device: device
 *  device      [IN]        
 *  onoff       [IN]        TRUE/FALSE
 *****************************************************************************/
void SetMuteReq(audio_type_enum device, MMI_BOOL onoff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_set_mute_req_struct *setMuteReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = MSG_ID_MMI_EQ_SET_MUTE_REQ;
    setMuteReq = OslConstructDataPtr(sizeof(mmi_eq_set_mute_req_struct));
    setMuteReq->audio_device = device;
    setMuteReq->mute_onoff = onoff;
    Message.oslDataPtr = (oslParaType*) setMuteReq;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  GpioSendMsg
 * DESCRIPTION
 *  Send message to other modules
 *  
 *  PARAMETERS: mmiapi_device_play_req_struct *
 *  src_mod_id          [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 *****************************************************************************/
void GpioSendMsg(U16 src_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = (oslMsgType) msg_id;         /* Type casting, to make compiler happer */
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = (oslModuleType) src_mod_id; /* Type casting, to make compiler happer */
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  KeyPadLCDBackLightStop
 * DESCRIPTION
 *  KeyPadLCDBackLightStop
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS:
 *  void
 *****************************************************************************/
void KeyPadLCDBackLightStop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_KEYPAD_BACKLIGHT);
    LCDBackLightOff();
    KeyPadBackLightOff();
}


/*****************************************************************************
 * FUNCTION
 *  LCMSleepGotoIdleScreen
 * DESCRIPTION
 *  KeyPadLCDBackLightStop
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
#if defined(__MMI_LCMSLEEP_BACK2IDLE__)
void LCMSleepGotoIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isEarphonePlugged == 1 && backlight_check_call_present())
    {
        return;
    }

#if defined(__MMI_FACTORY_MODE__) || defined(__MMI_ENGINEER_MODE__)
    if (gCurrentMode == FACTORY_MODE || gCurrentMode == ENGINEERING_MODE)
    {
        return;
    }
#endif /* defined(__MMI_FACTORY_MODE__) || defined(__MMI_ENGINEER_MODE__) */ 

    PRINT_INFORMATION("LCMSleepGotoIdleScreen():END Key Press, FP: %x", GetKeyHandler(KEY_END, KEY_EVENT_DOWN));
    ExecuteCurrKeyHandler(KEY_END, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_LCMSLEEP_BACK2IDLE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_is_lcd_sleep
 * DESCRIPTION
 *  To tell applications that lcd is sleeping or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gpio_is_lcd_sleep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIsInSleepMode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_detect_send_ack
 * DESCRIPTION
 *  send ack to PS
 * PARAMETERS
 *  action          [IN]        
 *  Action(?)       [IN]        Battery_sttus
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gpio_detect_send_ack(U8 gpio_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_res_req_struct *param_ack;

    param_ack = OslConstructDataPtr(sizeof(mmi_eq_gpio_detect_res_req_struct));

    param_ack->ext_gpio_device = gpio_device;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[MMI-GPIO] Send Ack to PS: gpio_device = %d", param_ack->ext_gpio_device);

    GpioSendMsg(MOD_L4C, MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ, param_ack, (void*)NULL);
}

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It For Power And Charge

#define MAIN_POWER_SET      0 
#define SUB_POWER_SET        1
#define MAIN_POWER_CHARGE_SET       0 
#define SUB_POWER_CHARGE_SET         1 


extern const char gpio_power_sw_pin;      
extern const char gpio_chr_sw_pin;          
 U8 g_power_set_state = MAIN_POWER_SET ;        
 U8 g_chr_set_state      = MAIN_POWER_CHARGE_SET ;       
 
extern void  PowerSwCtl(BOOL  bPowerCtl); 
extern void  ChargeSwCtl(BOOL bChrCtl );   

void  PowerSwCtl(BOOL  bPowerCtl)
{
	#ifndef MMI_ON_WIN32
	//Huyanwei Add It
	GPIO_ModeSetup(gpio_power_sw_pin, 0);    
	GPIO_InitIO(1, gpio_power_sw_pin);
      if (MAIN_POWER_SET == bPowerCtl)
      	{
      	       g_power_set_state = MAIN_POWER_SET;
		GPIO_WriteIO(1,gpio_power_sw_pin);
      	}
       else
     	{
     		g_power_set_state = SUB_POWER_SET;
		GPIO_WriteIO(0,gpio_power_sw_pin);
     	}
	#endif   
}

void  ChargeSwCtl(BOOL bChrCtl )
{
	#ifndef MMI_ON_WIN32
	//Huyanwei Add It
	GPIO_ModeSetup(gpio_chr_sw_pin, 0);    	
	GPIO_InitIO(1, gpio_chr_sw_pin);

      if (MAIN_POWER_CHARGE_SET == bChrCtl)
      	{
      		g_chr_set_state = MAIN_POWER_CHARGE_SET;
			
		GPIO_WriteIO(0,gpio_chr_sw_pin);
      	}
       else
     	{
     		g_chr_set_state = SUB_POWER_CHARGE_SET;
		GPIO_WriteIO(1,gpio_chr_sw_pin);
     	}
	#endif
}

#endif



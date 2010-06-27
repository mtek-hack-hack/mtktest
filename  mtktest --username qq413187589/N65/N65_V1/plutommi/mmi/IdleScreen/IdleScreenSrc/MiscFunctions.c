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
 *  MiscFunctions.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Misc Functions
 *  (1) Power On/Off
 *  (2) Analog clock 
 *  (3) Others - UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#include "CSP.h"
#include "gui_setting.h"
#include "CustDataProts.h"
#include "AlarmFrameWorkProt.h"
#include "IdleAppDef.h"
#include "MiscFunctions.h"
#include "SimDetectionGprot.h"
#include "gpioInc.h"
#include "SimDetectionGexdcl.h"
#include "IdleAppProt.h"
#include "ProfileGprots.h"
#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "WPSSProtos.h" /* phone setup interface */
#include "CallManagementIdDef.h"        /* for MT screen id */
#include "AvatarGprot.h"
#include "CustResDef.h"

#include "PhoneSetup.h" /* Cylen 0926, customize display char */
#include "GpioInc.h"

#include "wgui_status_icons.h"
#include "ProfilesGexdcl.h"     /* for profile global var */
#include "SettingGprots.h"

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 


#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif 

#include "datetimetype.h"
#include "app_datetime.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*****************************************************************************
* Global Variabl                                                          
*****************************************************************************/
#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
BOOL DirectMode = FALSE;
#endif 

#ifdef __DRM_SUPPORT__
static S32 consumer;
#endif

BOOL g_pwron_is_terminate_diplay = FALSE;
BOOL g_pwron_is_image = FALSE;
BOOL g_pwron_is_successful_play = FALSE;
BOOL g_pwron_is_entered = FALSE;

/*****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void ShowLowPowerShutdownScr(void);
extern void EntryFMMenu(void);
extern void ReqReadDailNum(void);
extern void wgui_set_animation(S32 x, S32 y, MMI_ID_TYPE img);

extern void InitAllApplications(void);

extern void CallBackPowerOnAnimationComplete(GDI_RESULT ret);
extern void RegisterCategory166AnimationCompleteCallback(void (*f) (S32 result));
extern void PowerOnBatteryIndicationComplete(void);

extern BOOL IsClamClose(void);
extern void ShowCategory310Screen(UI_string_type string);

#ifdef __MMI_AVATAR__
extern void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id, U32 *serial_num);
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)

U8 FMPatternBuffer[20];
S8 *ssc_fm_string = SSC_FACTORY_MODE;
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 

/*****************************************************************************
* Local Function 
*****************************************************************************/
void mmi_pwron_exit_animation_screen(void);
void exit_custom_startup_screen(void);

/*****************************************************************************
*
*  Power On
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  goto_opening_screen
 * DESCRIPTION
 *  go to opening screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goto_opening_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetAbnormalReset() == 1)    /* abnormal reset */
    {
        TurnOnBacklight(1);
        ResetAbnormalReset();

        /* to initialize SMS/CPHS after abnormal reset */
    #ifndef __MMI_DUAL_SIM_MASTER__
        CSPModifyHiliteHandlers();
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        BeforeEntryIdleScr();
    }
    else
    {
        TurnOnBacklight(1);
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        InitAllApplications();
        exit_custom_startup_screen();
    }

    GetPhoneLock(); /* diamond, 2006/02/27 Move this function call here because smu is not initialized in exception power on */
}


/*****************************************************************************
 * FUNCTION
 *  exit_custom_startup_screen
 * DESCRIPTION
 *  exit power on animation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_custom_startup_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetAbnormalReset() == 0)
    {
        gui_hide_animations();
    #ifndef __MMI_DUAL_SIM_MASTER__
        CSPModifyHiliteHandlers();      /* CSP Functionality needs to be here after all
                                           applications have initialised */
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        ShowWelcomeScr();
        ShowIdleAppSubLcd();
    }
}

#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)


/*****************************************************************************
 * FUNCTION
 *  CallBackPowerOnAnimationCompleteWrapper
 * DESCRIPTION
 *  wrapper function to enumate poweron animation play finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallBackPowerOnAnimationCompleteWrapper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CallBackPowerOnAnimationComplete(0);
}

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 
extern U8 IsBatteryLow(void) ;
#endif

/*****************************************************************************
 * FUNCTION
 *  DirectModeToFM
 * DESCRIPTION
 *  Direct entry factory mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void DirectModeToFM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DirectMode = TRUE;

    /* Low battery shutdown */
    if (((g_charbat_context.batteryStatus == PMIC_VBAT_STATUS ||        /* Battery Status */
          g_charbat_context.batteryStatus == PMIC_CHARGER_OUT) && g_charbat_context.isChargerConnected == 0) && (g_charbat_context.chargerLevel == BATTERY_LOW_POWEROFF))       /* Battery Level */
    {
#if defined(DOUBLE_BATTERY_SUPPORT)	
     #ifndef MMI_ON_WIN32
	//Huyanwei Add It 
	if( IsBatteryLow() == 1 )
    #endif
#endif
        {
        	ShowLowPowerShutdownScr();
        	return;
    	}
    }
    gui_hide_animations();
    EntryFMMenu();
}


/*****************************************************************************
 * FUNCTION
 *  KeyPatternIdentifier
 * DESCRIPTION
 *  Key Pattern Identifier
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void KeyPatternIdentifier(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    /* Avoid compile warning because KEY_0 is 0 for now, 
       but it might be changed to non-zero value in the future. */
    S16 Keycode_signed;     

    static U8 index = 0;
    U8 *pTemp;
    U8 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    Keycode_signed = (S16) Keycode;

    len = (strlen((char*)(ssc_fm_string)));

    if (index < len)
    {
        /* Only accept '#' , '*', '0' ~ '9' */
        if (Keycode == KEY_POUND)
        {
            FMPatternBuffer[index] = '#';
        }
        else if (Keycode == KEY_STAR)
        {
            FMPatternBuffer[index] = '*';
        }
        else if ((Keycode_signed >= KEY_0) && (Keycode <= KEY_9))  /* 0 ~ 9 */
        {
            FMPatternBuffer[index] = Keycode + '0';
        }

        index++;
    }

    if (index == len)
    {
        pTemp = (U8*) ssc_fm_string;
        if (strcmp((S8*) pTemp, (S8*) FMPatternBuffer) == 0)
        {
            ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_STAR, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_0, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_1, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_2, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_3, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_4, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_5, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_6, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_7, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_8, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_9, KEY_EVENT_DOWN);

            DirectModeToFM();
        }
    }

}

#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_play_video_callback
 * DESCRIPTION
 *  play power on video result callback function
 * PARAMETERS
 *  result      [IN]        Play video's reult
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_play_video_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_ANIMATION_FINISH);

    if (g_pwron_is_terminate_diplay)
    {
        /* means already terminated by time out, shall skip this callback */
        return;
    }

    /* treat as gif animation */
    /* change to GIF's return */
    if (result < 0)
    {
        /* return false, will force to enter the next procedure of power on */
        CallBackPowerOnAnimationComplete(-1);
    }
    else
    {
        /* play finish successfully - reset flag to PWRON_DISPLAY_SUCCESS */
        g_pwron_is_successful_play = TRUE;

        /* call before access NVRAM */
        CallBackPowerOnAnimationComplete(GDI_GIF_LAST_FRAME);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_show_image_callback
 * DESCRIPTION
 *  show power on image result callback function
 * PARAMETERS
 *  result      [IN]        Play video's reult
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_show_image_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_IMAGE_FINISH);

    if (g_pwron_is_terminate_diplay)
    {
        /* means already terminated by time out, shall skip this callback */
        return;
    }

    if (result < 0 && result != GDI_IMAGE_IS_STILL_IMAGE)
    {
        /* return false, will force to enter the next procedure of power on */
        CallBackPowerOnAnimationComplete(result);
    }
    /* diamond, 2005/08/28 fix still image cannot enter idle screen issue */
    else if (result == GDI_IMAGE_IS_STILL_IMAGE)
    {
        g_pwron_is_successful_play = TRUE;
        CallBackPowerOnAnimationComplete(result);
    }
    /* end, diamond */
    else
    {
        /* play finish successfully */
        g_pwron_is_successful_play = TRUE;

        /* call before access NVRAM */
        CallBackPowerOnAnimationComplete(GDI_SUCCEED);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_froce_terminate_display
 * DESCRIPTION
 *  force terminate power on display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pwron_froce_terminate_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_ANIMATION_TIMEOUT);

    /* if never successfully play once, force stop */
    if (!g_pwron_is_successful_play)
    {
        g_pwron_is_terminate_diplay = TRUE;
        g_pwron_is_successful_play = TRUE;

        /* mimic gif last frame callback */
        CallBackPowerOnAnimationComplete(GDI_GIF_LAST_FRAME);

        /* start another timer to try */
        gui_start_timer(200, mmi_pwron_froce_terminate_display);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_stop_animation
 * DESCRIPTION
 *  this function is used to stop power on animation screen, called when ready
 *  to enter idle screen, it is used to solve NVRAM & timer interlace problem
 *  
 *  [Note]
 *  when ready to enter power on screen, it will enter goto_opening_screen(),
 *  in this function, it will call InitAllApplications(), there are NVRAM access
 *  in this function, which will cause NVRAM & timer interlace problem.
 *  
 *  we have to stop all animation timer when we are sure poweron procdure success.
 *  we may call this function in mmi_ready_to_idle_screen_ind.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_stop_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pwron_flag;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != SCR_OPEN_SCREEN_ID)
    {
        return;
    }

    /* stop force teminate timer */
    gui_cancel_timer(mmi_pwron_froce_terminate_display);

    /* There is a race condition.
     * There is a GUI timer expiration event in queue for still image callback.
     * It is processed after SimPasswdReqResponse is called.
     * MMI needs to avoid from continuously receiving it twice.
     */
    g_pwron_is_terminate_diplay = TRUE;

    if (g_pwron_is_image)
    {
        /* stop image playing */
        StopCategory166Animation();
    }
    else
    {
    #if defined(__MMI_VIDEO_PLAYER__)
        /* stop video playing */
        StopCategory224Video();
    #endif /* defined(__MMI_VIDEO_PLAYER__) */ 
    }

    /* write proper value to NVRAM */
    if (!g_pwron_is_successful_play)
    {
    #if defined(__MMI_POWER_ON_OFF_DISPLAY__)
        /* restore default */
        PhnsetRstPwrOnDisplayDefault();
    #endif /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 
    }

    pwron_flag = PWRON_DISPLAY_SUCCESS;
    WriteValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_pause_video
 * DESCRIPTION
 *  pause video, this funcion will be used by TV-Out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
void mmi_pwron_pause_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pwron_is_image)
    {
        PauseCategory224Video();
    }
}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_resume_video
 * DESCRIPTION
 *  resume video, this funcion will be used by TV-Out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
void mmi_pwron_resume_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pwron_is_image)
    {
        ResumeCategory224Video();
    }
}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_draw_sublcd_dummy_screen
 * DESCRIPTION
 *  dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_pwron_draw_sublcd_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw nothing, just for category224's sublcd screen have a screen to goback. */
}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_drm_callback
 * DESCRIPTION
 *  Power on DRM consume callback
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_drm_callback(S32 res, S32 id)
{
    DRM_stop_consume(consumer);
    /* PhnsetScreenSaverBadFileCallBack(); */
}

#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_entry_animation_screen
 * DESCRIPTION
 *  start play poweron animation
 *  (1) GIF animation
 *  (2) Still image
 *  (3) Video clip
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_entry_animation_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 disp_id;
    PS8 filename_ptr;

    S16 error;
    U16 pwron_flag;
    U16 force_stop_time;

#ifdef __MMI_AVATAR__
    U32 serial_num;
#endif

#if defined(__MMI_VIDEO_PLAYER__)
    SubLCDHistoryNode sub_history;
    BOOL play_audio;
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 

#if defined(__MMI_POWER_ON_OFF_DISPLAY__)
    FS_HANDLE fs_handle;
#endif /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 
    U16 res_type = FMGR_GROUP_IMAGE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * 
     * Power On Procedure
     * 
     * Power On Display      NAND       SIM        Net Search    Idle Scr
     * #----------------------#----------#----------#-------------#-----------# 
     * (option)    (option)    (option)
     * 
     * 
     */

    /* if is entered before, means back from interrupt while playing power on display */
    if (g_pwron_is_entered)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_BACK2_ANIMATION);
        ClearInputEventHandler(MMI_DEVICE_ALL); /* Prevent from END key is pre-registered by call management */
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        /* MT/SMS/USSD or other inetrrupt happened during poweron display, some initialzation need to be done afterward */
        PowerOnBatteryIndicationComplete();
        return;
    }

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_START_ANIMATION);

    /* init */
    filename_ptr = NULL;
    disp_id = 0;

    g_pwron_is_entered = TRUE;
    g_pwron_is_image = TRUE;
    g_pwron_is_successful_play = FALSE;

    if (mmi_bootup_is_sim_failure_received() == MMI_TRUE)
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION_SIM_FAIL;
    }
    else if (mmi_bootup_is_sim_need_security_check() == MMI_TRUE)
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION_PSWD_REQ;
    }
    else
    {
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION;        /* 0x04: Power on animation */
    }

    TurnOnBacklight(0);

   /*******************************************/
    /* Valid power on display checking         */
   /*******************************************/

    /* Valid power on display restoration checking */
    ReadValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);

    /* 
     * 0xff is the default value, each time power on display play successfully, 
     * it will set to 0xff as well.
     */

#if defined(__MMI_POWER_ON_OFF_DISPLAY__)
    if (pwron_flag == PWRON_DISPLAY_FAILED)
    {
        /* if flag is PWRON_DISPLAY_FAILED, means something wrong happened during playing power on display */
        /* we will restore power on display to default settings */
        PhnsetRstPwrOnDisplayDefault();
    }
#endif /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 

    /* set the flag to 0x01 , if play successfully to end, will reset back to 0xff */
    pwron_flag = PWRON_DISPLAY_PLAYING;
    WriteValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);

#if defined(__MMI_POWER_ON_OFF_DISPLAY__)
   /*******************************************/
    /* Get animation resource from phone setup */
   /*******************************************/
    PhnsetGetPwrOnDisp(&disp_id);

    if (disp_id == 0xff)    /* invalid format */
    {
        /* reset as default */
        PhnsetRstPwrOnDisplayDefault();

        /* this id must be a valid id */
        PhnsetGetPwrOnDisp(&disp_id);
    }
    else if (disp_id == 0x00 || /* source from file */
             disp_id == 0x01)   /* short file name */
    {
        PS8 error;

        disp_id = 0x00;

        /* filename buffer is allocated in phnset */
        filename_ptr = PhnsetGetPwrOnFileName();

        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_POWER_ON_OFF_DSPL, filename_ptr, &error))
        {
            /* limit check failed */
            /* reset to default */
            PhnsetRstPwrOnDisplayDefault();

            /* this id must be a valid id */
            PhnsetGetPwrOnDisp(&disp_id);
            filename_ptr = NULL;
        }
    }
#ifdef __MMI_AVATAR__
    else if(PhnsetGetDisplayType(disp_id) == PHNSET_TYPE_DISP_AVATAR)
    {
        dispchar_get_current_avatar_id(disp_id, (U32 *)&filename_ptr, (U32 *)&serial_num);

        if (!mmi_avatar_is_avatar_valid((U32)filename_ptr, (U32)serial_num))
        {
            PhnsetRstPwrOnDisplayDefault();

            /* this id must be a valid id */
            PhnsetGetPwrOnDisp(&disp_id);
        }   
        filename_ptr = NULL;
    }
#endif /* __MMI_AVATAR__ */
    else
    {
        /* source from intenal resource */
        filename_ptr = NULL;
    }

   /*******************************************/
    /* Check if is image or video              */
   /*******************************************/
    /* get file resource type */
    if (filename_ptr != NULL)
    {
#ifdef __DRM_SUPPORT__
        U8 permission = 0;
        kal_bool is_permitted = KAL_FALSE;
#endif

        /* source from file */
        res_type = mmi_fmgr_get_file_group(filename_ptr);

        if (res_type == FMGR_GROUP_IMAGE)
        {
            g_pwron_is_image = TRUE;
#ifdef __DRM_SUPPORT__
            permission = DRM_PERMISSION_DISPLAY;
#endif
        }
        else if (res_type == FMGR_GROUP_VIDEO)
        {
            g_pwron_is_image = FALSE;
#ifdef __DRM_SUPPORT__
            permission = DRM_PERMISSION_PLAY;
#endif
        }
  #ifdef __MMI_SWFLASH__
        else if (res_type == FMGR_GROUP_SWFLASH)
        {
            g_pwron_is_image = TRUE;
        }
    #endif /* __MMI_SWFLASH__ */
        else
        {
            /* unsupported file format ext */
            PhnsetRstPwrOnDisplayDefault();

            /* this id must be a valid id */
            PhnsetGetPwrOnDisp(&disp_id);
            filename_ptr = NULL;
        }

    #ifdef __DRM_SUPPORT__
        /* DRM permission check */
        if ((fs_handle = DRM_open_file((PU16) filename_ptr, FS_READ_ONLY, permission)) >= FS_NO_ERROR)
        {
            if (res_type == FMGR_GROUP_IMAGE && DRM_validate_forward_rule(fs_handle, permission))
            {
                consumer = DRM_consume_rights(fs_handle, permission, mmi_pwron_drm_callback);
                is_permitted = KAL_TRUE;
            }
        #ifdef __MMI_SWFLASH__
            else if (res_type == FMGR_GROUP_SWFLASH && DRM_validate_forward_rule(fs_handle, permission))
            {
                consumer = DRM_consume_rights(fs_handle, permission, mmi_pwron_drm_callback);
                is_permitted = KAL_TRUE;
            }
        #endif                        
            else if (res_type == FMGR_GROUP_VIDEO && DRM_validate_forward_rule(fs_handle, permission))
            {
                consumer = DRM_consume_rights(fs_handle, permission, mmi_pwron_drm_callback);
                is_permitted = KAL_TRUE;
            }
            DRM_close_file(fs_handle);
        }
    #else /* __DRM_SUPPORT__ */ 
        fs_handle = FS_Open((U16*) filename_ptr, FS_READ_ONLY);
    #endif /* __DRM_SUPPORT__ */ 

        if (fs_handle < FS_NO_ERROR 
#ifdef __DRM_SUPPORT__ 
            || is_permitted == KAL_FALSE
#endif /* __DRM_SUPPORT__ */
            )
        {
            /* open file failed */
            /* reset as default */
            PhnsetRstPwrOnDisplayDefault();

            /* this id must be a valid id */
            PhnsetGetPwrOnDisp(&disp_id);
            filename_ptr = NULL;
        }
        else
        {
            /* open file successful */
            FS_Close(fs_handle);
        }

        
    }

    /* check internal resource type */
    if (filename_ptr == NULL)
    {
        res_type = PhnsetGetDisplayType(disp_id);

        if (res_type == PHNSET_TYPE_DISP_IMAGE)
        {
            g_pwron_is_image = TRUE;
            res_type = FMGR_GROUP_IMAGE;
        }
        else if (res_type == PHNSET_TYPE_DISP_VIDEO)
        {
            g_pwron_is_image = FALSE;
            res_type = FMGR_GROUP_VIDEO;
        }
    #ifdef __MMI_SWFLASH__
        else if (res_type == PHNSET_TYPE_DISP_SWFLASH)
        {
            g_pwron_is_image = TRUE;
            res_type = FMGR_GROUP_SWFLASH;
        }
    #endif /* __MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        else if (res_type == PHNSET_TYPE_DISP_AVATAR)
        {
            g_pwron_is_image = TRUE;
            res_type = FMGR_GROUP_AVATAR;
        }
    #endif /* __MMI_AVATAR__ */
        else
        {
            #ifndef WIN32
            MMI_ASSERT(0);
	     #endif
        }
    }

#else /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 

    /* play from internal build in resource */
    g_pwron_is_image = TRUE;
#ifdef __MMI_POWER_ON_OFF_DISPLAY__     /* Cylen 0926, customize display char */
    disp_id = IMG_ID_PHNSET_ON_0;
#else 
    disp_id = IMG_ID_PHNSET_ON_ANIMATION_DEFAULT;
#endif 
    filename_ptr = NULL;

#endif /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 

   /*******************************************/
    /* Start to play                           */
   /*******************************************/
    if (res_type == FMGR_GROUP_IMAGE)
    {
        /* Play GIF animation or still image */
        if (ExitCategoryFunction != NULL)
        {
            ExitCategoryFunction();
        }
        ShowCategory166Screen(disp_id, filename_ptr, mmi_pwron_show_image_callback);

    #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
        if (!IsClamClose())
        {
            ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
        }
        else
    #endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
            ShowCategory313Screen(IMG_SUBLCD_POWER_ON_SCR, NULL);

        /* play power on tone */
        playRequestedTone(POWER_ON_TONE);
    }
    else if (res_type == FMGR_GROUP_VIDEO)
    {
        /* Play video clip */
    #if defined(__MMI_VIDEO_PLAYER__)

        /* check silent mode */
        play_audio = (gcurrentprofile.toneSetup.powerOnTone != POWERON_SILENT) ? TRUE : FALSE;

        /* set volume as ring tone volume */
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        /* add sublcd screen in history */
        /* 
         * this is when Categry224 play finish, it's sublcd will go back history,
         * If we go back to root sublcd screen, sometimes it might draw an empty 
         * screen due to sim or network not ready.
         * So we have to let it back to a dummy screen, whihc will draw nothing .
         */

        sub_history.entryFuncPtr = mmi_pwron_draw_sublcd_dummy_screen;
        AddSubLCDHistory(&sub_history);

        /* entry video play screen */
        ShowCategory224Screen(
            disp_id,                        /* video id */
            filename_ptr,                   /* filename */
            0,                              /* repeat_count *//* 0 means infinite */
            TRUE,                           /* is_visaul_update */
            play_audio,                     /* is_play_audio */
            FALSE,                          /* is_lcd_sleep *//* already in non-sleep mode */
            GDI_COLOR_BLACK,                /* bg_color */
            mmi_pwron_play_video_callback,  /* (*play_finish_callback)(S16) */
            NULL);                          /* gui_buffer */
    #else /* defined(__MMI_VIDEO_PLAYER__) */ 
        MMI_ASSERT(0);
    #endif /* defined(__MMI_VIDEO_PLAYER__) */ 

    }
#ifdef __MMI_SWFLASH__
    else if (res_type == FMGR_GROUP_SWFLASH)
    {
        ShowCategory229Screen(
            0,                      /* title_str */
            0,            /* title_icon */
            0,                      /* lsk_str */
            0,                      /* lsk_icon */
            0,                    /* rsk_str */
            0,                    /* rsk_icon */
            disp_id,                        /* resource_id */
            filename_ptr,                               /* resource_filename */
            1,                                  /* repeat_count */
            MMI_TRUE,                          /* is_play_audio */
            0,                          /* is_vibrate_on */
            0,                          /* is_interaction_on */
            0,                           /* is_lcd_no_sleep */
            MMI_TRUE,                          /* is_full_screen */
            GDI_COLOR_WHITE,                    /* bg_color */
            mmi_pwron_show_image_callback,
            NULL);
        
    }
#endif
#ifdef __MMI_AVATAR__
    else if (res_type == FMGR_GROUP_AVATAR)
    {
        dispchar_get_current_avatar_id(disp_id, (U32 *)&filename_ptr, (U32 *)&serial_num);


        /* Play GIF animation or still image */
        if (ExitCategoryFunction != NULL)
        {
            ExitCategoryFunction();
        }
        ShowCategory166Screen(disp_id, filename_ptr, mmi_pwron_show_image_callback);

    #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
        if (!IsClamClose())
        {
            ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
        }
        else
    #endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
            ShowCategory313Screen(IMG_SUBLCD_POWER_ON_SCR, NULL);

        /* play power on tone */
        playRequestedTone(POWER_ON_TONE);
        
    }
#endif /* __MMI_AVATAR__ */

#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
    SetKeyHandler(KeyPatternIdentifier, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_STAR, KEY_EVENT_DOWN);

    SetKeyHandler(KeyPatternIdentifier, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(KeyPatternIdentifier, KEY_9, KEY_EVENT_DOWN);

#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 

    StartLEDPatternPowerOn();
    ReplaceNewScreenHandler(SCR_OPEN_SCREEN_ID, mmi_pwron_exit_animation_screen, mmi_pwron_entry_animation_screen);

    /* this timer is used to avoid gif/video play too long, will force to enter idle */
    ReadValue(NVRAM_POWER_ON_FORCE_STOP_TIME, &force_stop_time, DS_SHORT, &error);

    /* not set in NVRAM, use defulat 20 sec limit */
    if (force_stop_time == 0xffff)
    {
        force_stop_time = 20000;
    }

    /* POWER ON time have NVRAM-timer interlace problem, so put time at last to eliminate this problem */
    gui_start_timer(force_stop_time, mmi_pwron_froce_terminate_display);
    g_pwron_is_terminate_diplay = FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_exception_check_display
 * DESCRIPTION
 *  this function is for exception power on to check wether need to restore
 *  power on diplay to default or not.
 *  we cant 100% guarantee decoder will work for all image/video from file, we
 *  use this method to restore back if decoder has assert or fatal error.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_exception_check_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 pwron_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Valid power on display restoration checking */
    ReadValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);

    /* this means exception happened during previous decoding process */
    if (pwron_flag == PWRON_DISPLAY_PLAYING)
    {
    #if defined(__MMI_POWER_ON_OFF_DISPLAY__)
        PhnsetRstPwrOnDisplayDefault();
    #endif 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_exit_animation_screen
 * DESCRIPTION
 *  exit power on animation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_exit_animation_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pwron_flag;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_POWER_ON_LEAVE_ANIMATION);

    TurnOffBacklight(); /* To start backlight timer */

    ExitSubLCDIdleScr();    /* Add idle screen to sub-lcd history if power on animation is interrupted */

    /* if is force stopped by MT call, treat this recource as play successfully */
    if (GetActiveScreenId() == ITEMSCR_INCOMING_CALL)
    {
        pwron_flag = PWRON_DISPLAY_SUCCESS;
        WriteValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);
    }

    gui_cancel_timer(mmi_pwron_froce_terminate_display);
}
#ifdef __MMI_MAINLCD_128X128__
S32 ANALOG_CLOCK_DIAL_X = 36;
S32 ANALOG_CLOCK_DIAL_Y = 36;
#else
S32 ANALOG_CLOCK_DIAL_X = 26;
S32 ANALOG_CLOCK_DIAL_Y = 26;
#endif

/*****************************************************************************
 * FUNCTION
 *  analog_clock_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void analog_clock_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT HIMANSHU START 20050625 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    #if defined (__MMI_MAINLCD_320X240__)
        ANALOG_CLOCK_DIAL_X = (MMI_SIGNAL_WIDTH);
        ANALOG_CLOCK_DIAL_Y = 26;
    #else /* defined (__MMI_MAINLCD_320X240__) */
        ANALOG_CLOCK_DIAL_X = (MMI_SIGNAL_WIDTH) + 7;  //sc.wu analog clock
        ANALOG_CLOCK_DIAL_Y = (MMI_status_bar_height);
    #endif /* defined (__MMI_MAINLCD_320X240__) */
#else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
    ANALOG_CLOCK_DIAL_X = (UI_device_width >> 1) - (ANALOG_CLOCK_DIAL_WIDTH >> 1);
    ANALOG_CLOCK_DIAL_Y = (UI_device_height >> 1) - (ANALOG_CLOCK_DIAL_HEIGHT >> 1);
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
}

extern void PB_test_demo(void);


/*****************************************************************************
 * FUNCTION
 *  initialize_UI_demo
 * DESCRIPTION
 *  Initialize UI environment
 *
 *  Remark: this function may be executed more than one times for special poweron
 *          mode (e.g. Alarm poweron, Charger poweron, USB poweron)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_UI_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_init();
    mmi_frm_scrmem_init();
    dm_init();
    wgui_init();
    initialize_category_screens();
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION ||
#if defined(__NVRAM_IN_USB_MS__)        /* for alarm in usb boot mode */
        g_pwr_context.PowerOnMode == POWER_ON_USB ||
#endif 
        g_pwr_context.PowerOnMode == POWER_ON_ALARM || g_pwr_context.PowerOnMode == POWER_ON_CHARGER_IN)
    {
        mmi_pen_init();
        mmi_pen_enable();
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

    /* Temporary: Must be moved to boot up application */
    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION)
    {
        ShowStatusIcon(STATUS_ICON_SIGNAL_STRENGTH);
        ShowStatusIcon(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH);
    #ifdef __MMI_DUAL_SIM_MASTER__
        ShowStatusIcon(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
    #endif
    }
    else
    {
        HideStatusIcon(STATUS_ICON_SIGNAL_STRENGTH);
        HideStatusIcon(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH);
    #ifdef __MMI_DUAL_SIM_MASTER__
        HideStatusIcon(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
    #endif
    }
    ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
#ifdef __MMI_TOUCH_SCREEN__
    ChangeStatusIconImage(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_UNLOCK);
    UpdateStatusIcons();    /* 101805 ChangeStatusIconImage Calvin: ChangeStatusIconImage will not call UpdateStatusIcon */
    ShowStatusIcon(STATUS_ICON_KEYPAD_LOCK);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  redraw_custom_startup_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_custom_startup_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    c.r = 255;
    c.b = 255;
    c.g = 255;
    c.alpha = 100;
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_fill_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, c);
    gui_measure_image(get_image(CUSTOM_LOGO_IMAGE_ID), &iwidth, &iheight);
    gui_show_image(
        (UI_device_width >> 1) - (iwidth >> 1),
        (UI_device_height >> 1) - (iheight >> 1),
        get_image(CUSTOM_LOGO_IMAGE_ID));
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  goto_custom_startup_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goto_custom_startup_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    redraw_custom_startup_screen();
    gui_start_timer(DEMO_OPENING_CUSTOM_LOGO_TIMEOUT, exit_custom_startup_screen);
}


/*****************************************************************************
 * FUNCTION
 *  UI_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_update(void)
{
#if(!BUILD_TYPE_X86WIN32_DISABLE_REDRAW)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (RedrawCategoryFunction != NULL)
    {
        RedrawCategoryFunction();
    }
    if (SUBLCD_RedrawCategoryFunction != NULL)
    {
        SUBLCD_RedrawCategoryFunction();
    }
#endif /* (!BUILD_TYPE_X86WIN32_DISABLE_REDRAW) */ 
}


/*****************************************************************************
 * FUNCTION
 *  terminate_UI_demo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void terminate_UI_demo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ExitCategoryFunction != NULL)
    {
        ExitCategoryFunction();
    }
    if (SUBLCD_ExitCategoryFunction != NULL)
    {
        SUBLCD_ExitCategoryFunction();
    }
    gui_hide_animations();
}

U8 temp_sublcd_display_flag = 0;


/*****************************************************************************
 * FUNCTION
 *  toggle_temp_sublcd_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void toggle_temp_sublcd_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp_sublcd_display_flag)
    {
        temp_sublcd_display_flag = 0;
        ShowCategory302Screen(NULL);
    }
    else
    {
        temp_sublcd_display_flag = 1;
        ShowCategory301Screen((U8*) GetString(TEMP_SUBLCD_ANIMATION_STR_ID), TEMP_SUBLCD_ANIMATION_IMAGE_ID, NULL);
    }
}


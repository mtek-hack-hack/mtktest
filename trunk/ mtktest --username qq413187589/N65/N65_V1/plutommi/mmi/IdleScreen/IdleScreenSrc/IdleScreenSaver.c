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
 *   IdleScreenSaver.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Screensaver
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#include "MiscFunctions.h"
#include "DateTimeGprot.h"
#include "CommonScreens.h"
#include "wgui_softkeys.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "SettingGprots.h"
#include "audioinc.h"
#include "gpioInc.h"
#include "SettingProfile.h"
#include "WPSSProtos.h"
#include "DownloadDefs.h"
#include "QuickAccessMenuItemProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "PhoneSetupGprots.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "FileManagerGProt.h"   /* file path / file error */
#include "FileManagerDef.h"     /* error string id */
#include "AvatarGprot.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif 

#include "custom_util.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 


/****************************************************************************
* Global Variable                                                           
*****************************************************************************/
static BOOL g_scrsvr_is_image;
#ifdef __DRM_SUPPORT__
static S32 consumer;
#endif

extern U8 screen_saver_type;
extern idle_context_struct g_idle_context;

#ifndef __MMI_GPIO_DISABLE_SLEEP_MODE__
extern BOOL gIsInSleepMode;
#endif 

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern BOOL IsClamClose(void);

#ifdef __MMI_AVATAR__
extern void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id, U32 *serial_num);
#endif

/*****************************************************************************
* Local Function 
*****************************************************************************/

#ifdef __MMI_LCD_PARTIAL_ON__


/*****************************************************************************
 * FUNCTION
 *  LeavePartialOnScreenSaverIfOk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LeavePartialOnScreenSaverIfOk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCREEN_SAVER_PARTIAL_ON_ID)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EnterPartialOnScreenSaverIfOk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterPartialOnScreenSaverIfOk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != SCREEN_SAVER_PARTIAL_ON_ID)
    {
        EntryPartialOnScreenSaver();
    }
}


/*****************************************************************************
 * FUNCTION
 *  RedrawPartialOnScreenSaverIfOk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawPartialOnScreenSaverIfOk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCREEN_SAVER_PARTIAL_ON_ID)
    {
        UI_time t;

        GetDateTime(&t);
        Category161ChangeTime(&t);
        RedrawCategory161Screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  PartialOnScreenSaverGoBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PartialOnScreenSaverGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);

    /* Flush key queue */
    ClearKeyEvents();
    GoBackHistory();

    /* Tricky. Check if the previous screen is keypad locked         */
    /* We can not use g_keylock_context.gKeyPadLockFlag nor g_idle_context.IsRSKPressOnScreenSaver    */
    /* because partial-on screen saver can display on screens other than idle screen. */

#ifdef __MMI_TOUCH_SCREEN__

    if (keycode == KEY_SEND && GetKeyHandler(keycode, keytype) == EntryScrAfterPessingRSK)
    {
        EntryScrAfterPessingRSK();
    }

#else /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    if ((get_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY) == EntryScrAfterPessingRSK) && (keycode == KEY_RSK))
    {
        EntryScrAfterPessingRSK();
    }
#endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    if ((get_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY) == EntryScrAfterPessingRSK) && (keycode == KEY_LSK))
    {
        EntryScrAfterPessingRSK();
    }
#endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 

#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitPartialOnScreenSaver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitPartialOnScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Tricky. We need at least one dummy exit handler. Otherwise, ExitCategoryFunction wont be invoked. */
    g_idle_context.ScreenSaverRunFlag = 0;
    /* leave_full_screen(); //Already invoked in UI_common_screen_exit() */
}


/*****************************************************************************
 * FUNCTION
 *  EntryPartialOnScreenSaver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPartialOnScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIDE__
    if (IsClamClose())
    {
        return;
    }
#endif /* __MMI_SLIDE__ */ 

    if (GetActiveScreenId() == IDLE_SCREEN_ID)
    {
        g_idle_context.ScreenSaverRunFlag = 1;
    }

#if 0
	#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
#endif /* 0 */ /* #if 0 */

    EntryNewScreen(SCREEN_SAVER_PARTIAL_ON_ID, ExitPartialOnScreenSaver, NULL, NULL);

    entry_full_screen();

    SetGroupKeyHandler(PartialOnScreenSaverGoBack, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);

    GetDateTime(&t);
    ShowCategory161Screen(&t);
}

#endif /* __MMI_LCD_PARTIAL_ON__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_scrsvr_play_video_callback
 * DESCRIPTION
 *  Play screen saver video result callback function
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scrsvr_play_video_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* treat as gif animation */
    if (result < 0)
    {
        g_idle_context.ScreenSaverRunFlag = 0;  /* FALSE */
        TurnOnBacklight(1);                     /* 1 means restart timer backlight */
        PhnsetScreenSaverBadFileCallBack();     /* reset as default */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_scrsvr_lcd_sleepin_handler
 * DESCRIPTION
 *  Screen saver lcd sleep in handler (sleep in means turn off)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scrsvr_lcd_sleepin_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ScreenSaverRunFlag == 1) /* == TRUE */
    {
        g_idle_context.IsScrSvrSleepIn = 1; /* TRUE */

        /* force to enter a dummy screen - which will exit screensaver's screen */
        EntryNewScreen(IDLE_SCREEN_DUMMY_ID, NULL, NULL, NULL);

        /* entry full screen - force mainlcd status bar not update */
        entry_full_screen();

        /* clear full screen as black */
        gdi_layer_clear(GDI_COLOR_BLACK);

        /* force sub to play timer */
        ShowSubLCDScreen(ShowIdleAppSubLcd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_scrsvr_lcd_sleepout_handler
 * DESCRIPTION
 *  Screen saver lcd sleep out handler (sleep out means turn on)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scrsvr_lcd_sleepout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if it is in dummy screen */
    /* This function may be called by alarm or other interupt when they try to turn on backlight */
    /* when lcd is already sleep out, so add this protection             */

    if (GetExitScrnID() != IDLE_SCREEN_DUMMY_ID)
    {
        /* stop keypad lock timer if alarm interrupts when LCD backlight is off */
        PRINT_INFORMATION("[Keypad Lock] ExitIdleScreen: Timer %d Stop", g_idle_context.AutoLockTimeOut);
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);

        return;
    }

    if (g_idle_context.IsScrSvrSleepIn == 1)    /* == TRUE */
    {
        g_idle_context.IsScrSvrSleepIn = 0;
        EntryIdleSetScreenSaver();
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_scrsvr_pen_up_handler
 * DESCRIPTION
 *  Screen saver pen up handler
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scrsvr_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayIdleScreen();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_scrsvr_drm_callback
 * DESCRIPTION
 *  Screen saver DRM consume callback
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scrsvr_drm_callback(S32 res, S32 id)
{
    DRM_stop_consume(consumer);
    PhnsetScreenSaverBadFileCallBack();
}

#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  EntryIdleSetScreenSaver
 * DESCRIPTION
 *  Enter screen saver from idle screenScreen saver pen up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryIdleSetScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_screensaver;
    U8 *guiBuffer;
    U16 res_type;
#ifdef __MMI_AVATAR__
    U32 serial_num;
#endif
    PS8 filename_ptr = NULL;
    FS_HANDLE fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Screensaver timeout");

    /* if clam is close then want try to enter screen saver, do not enter */
#ifndef __MMI_SLIDE__
    if (IsClamClose())
    {
        PRINT_INFORMATION("Screensaver is not executed because clam is close");
        return;
    }
#endif /* __MMI_SLIDE__ */ 

    g_idle_context.ScreenSaverRunFlag = 1;

#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
    if (gIsInSleepMode)
    {
        mmi_scrsvr_lcd_sleepin_handler();
        g_idle_context.ScreenSaverRunFlag = 0;
        return;
    }
#endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */ 

    EntryNewScreen(IDLE_SCREEN_SCREENSAVER_ID, ExitScreenSaver, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(IDLE_SCREEN_SCREENSAVER_ID);
    g_idle_context.IsRSKPressOnScreenSaver = 0;

    PhnsetGetCurScrSvr(&cur_screensaver);

    if (PhnsetIsScrSvrAnalogClock())
    {
        screen_saver_type = ANALOG_SCREEN_SAVER;
        ShowCategory131Screen(cur_screensaver, NULL);
    }
    else if (PhnsetIsScrSvrDigitalClock())
    {
        screen_saver_type = DIGITAL_SCREEN_SAVER;
        ShowCategory131Screen(cur_screensaver, NULL);
    }
#ifdef __MMI_THEMES_V2_SUPPORT__
    else if (PhnsetIsScrSvrCurrentTheme())
    {
        ShowCategory166Screen(cur_screensaver, filename_ptr, NULL);
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    else
    {
        /* play image or video */

      /*******************************************/
        /* Get animation resource from phone setup */
      /*******************************************/

        if (cur_screensaver == 0xff)    /* invalid format */
        {
            /* reset as default */
            PhnsetScreenSaverBadFileCallBack();
            return;
        }
    #if defined(__MMI_FILE_MANAGER__)		
        else if (cur_screensaver == 0x00 || /* source from file */
                 cur_screensaver == 0x01)   /* short file name */
        {
            PS8 error;

            cur_screensaver = 0x00;

            /* filename buffer is allocated in phnset */
            filename_ptr = PhnsetGetCurScrSvrFileName();

            if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_SCREEN_SAVER, filename_ptr, &error))
            {
                /* limit check failed */
                /* reset to default */
                PhnsetScreenSaverBadFileCallBack();
                return;
            }

        }
    #endif /* __MMI_FILE_MANAGER__ */
    #ifdef __MMI_AVATAR__
        else if(PhnsetGetDisplayType(cur_screensaver) == PHNSET_TYPE_DISP_AVATAR)
        {
            dispchar_get_current_avatar_id(cur_screensaver, (U32 *)&filename_ptr, (U32 *)&serial_num);
    
            if (!mmi_avatar_is_avatar_valid((U32)filename_ptr, (U32)serial_num))
            {
                /* reset to default */
                PhnsetScreenSaverBadFileCallBack();
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
#if defined(__MMI_FILE_MANAGER__)		
        /* get file resource type */
        if (filename_ptr != NULL)
        {
#ifdef __DRM_SUPPORT__
            U8 permission = 0;
#endif
            /* source from file */
            res_type = mmi_fmgr_get_file_group(filename_ptr);

            if (res_type == FMGR_GROUP_IMAGE)
            {
                g_scrsvr_is_image = TRUE;
#ifdef __DRM_SUPPORT__
                permission = DRM_PERMISSION_DISPLAY;
#endif
            }
            else if (res_type == FMGR_GROUP_VIDEO)
            {
                g_scrsvr_is_image = FALSE;
#ifdef __DRM_SUPPORT__
                permission = DRM_PERMISSION_PLAY;
#endif
            }
        #ifdef __MMI_SWFLASH__
            else if (res_type == FMGR_GROUP_SWFLASH)
            {
                g_scrsvr_is_image = TRUE;
            }
        #endif /* __MMI_SWFLASH__ */
            else
            {
                /* unsupported file format ext */
                /* reset as default */
                PhnsetScreenSaverBadFileCallBack();
                return;
            }

            
        #ifdef __DRM_SUPPORT__
            {
            
                MMI_BOOL is_permitted = MMI_FALSE;
                /* DRM permission check */
                if ((fs_handle = DRM_open_file((PU16) filename_ptr, FS_READ_ONLY, permission)) >= FS_NO_ERROR)
                {
                    if (res_type == FMGR_GROUP_IMAGE && DRM_validate_forward_rule(fs_handle, permission))
                    {
                        consumer = DRM_consume_rights(fs_handle, permission, mmi_scrsvr_drm_callback);
                        is_permitted = MMI_TRUE;
                    }
                #ifdef __MMI_SWFLASH__
                    else if (res_type == FMGR_GROUP_SWFLASH && DRM_validate_forward_rule(fs_handle, permission))
                    {
                        consumer = DRM_consume_rights(fs_handle, permission, mmi_scrsvr_drm_callback);
                        is_permitted = MMI_TRUE;
                    }
                #endif                        
                    else if (res_type == FMGR_GROUP_VIDEO && DRM_validate_forward_rule(fs_handle, permission))
                    {
                        /* consumer = DRM_consume_rights(fs_handle, DRM_PERMISSION_PLAY, mmi_scrsvr_drm_callback); */
                        is_permitted = MMI_TRUE;
                    }
                    DRM_close_file(fs_handle);
                }
                else if (fs_handle < FS_NO_ERROR)   /* file open error but not DRM related problem */
                {
                    /* To determine DRM right or image problem */
                    fs_handle = FS_Open((U16*) filename_ptr, FS_READ_ONLY);
                    if (fs_handle >= FS_NO_ERROR)
                    {
                        is_permitted = MMI_FALSE;   /* DRM right problem */
                        FS_Close(fs_handle);
                    }
                    else
                    {
                        is_permitted = MMI_TRUE;    /* image problem */
                    }
            
                }
            
                /* if not permitted */
                if (!is_permitted)
                {
            
                    PhnsetRstScrSvrDefault();
            
                    /* no permission to display */
                    DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                    return;
                }
            }
        #else /* __DRM_SUPPORT__ */ 
            fs_handle = FS_Open((U16*) filename_ptr, FS_READ_ONLY);
        
            if (fs_handle < FS_NO_ERROR)
            {
                /* open file failed */
                /* reset as default */
                PhnsetScreenSaverBadFileCallBack();
                return;
            }
            else
            {
                /* open file successful */
                FS_Close(fs_handle);
            }
        #endif /* __DRM_SUPPORT__ */ 



            
        }
#endif /* __MMI_FILE_MANAGER__ */

        /* check internal resource type */
        if (filename_ptr == NULL)
        {
            res_type = PhnsetGetDisplayType(cur_screensaver);

            if (res_type == PHNSET_TYPE_DISP_IMAGE)
            {
                g_scrsvr_is_image = TRUE;
                res_type = FMGR_GROUP_IMAGE;
            }
            else if (res_type == PHNSET_TYPE_DISP_VIDEO)
            {
                g_scrsvr_is_image = FALSE;
                res_type = FMGR_GROUP_VIDEO;
            }
        #ifdef __MMI_SWFLASH__
            else if (res_type == PHNSET_TYPE_DISP_SWFLASH)
            {
                g_scrsvr_is_image = FALSE;
                res_type = FMGR_GROUP_SWFLASH;
            }
        #endif /* __MMI_SWFLASH__ */
        #ifdef __MMI_AVATAR__
            else if (res_type == PHNSET_TYPE_DISP_AVATAR)
            {
                g_scrsvr_is_image = TRUE;
                res_type = FMGR_GROUP_AVATAR;
            }
        #endif /* __MMI_SWFLASH__ */
            else
            {
                MMI_ASSERT(0);
            }
        }

      /*******************************************/
        /* Start to play                           */
      /*******************************************/
        if (res_type == FMGR_GROUP_IMAGE)
        {
            /* Play GIF animation or still image */
            ShowCategory166Screen(cur_screensaver, filename_ptr, NULL);
        }
        else if (res_type == FMGR_GROUP_VIDEO)
        {
            /* Play video clip */
        #if defined(__MMI_VIDEO_PLAYER__)

            /* entry video play full screen */
            ShowCategory224Screen(
                cur_screensaver,                /* video id */
                filename_ptr,                   /* filename */
                0,                              /* repeat_count *//* 0 means infinite */
                MMI_TRUE,                       /* is_visaul_update */
                MMI_FALSE,                      /* is_play_audio */
                MMI_FALSE,                      /* is_lcd_no_sleep *//* need sleep in */
                GDI_COLOR_BLACK,                /* bg_color */
                mmi_scrsvr_play_video_callback, /* (*play_finish_callback)(S16) */
                NULL);                          /* gui_buffer */

            /* category 224 will stop lcd sleep mechansim, we must let MMI can sleep in */

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
                cur_screensaver,                        /* resource_id */
                filename_ptr,                               /* resource_filename */
                1,                                  /* repeat_count */
                0,                          /* is_play_audio */
                0,                          /* is_vibrate_on */
                0,                          /* is_interaction_on */
                0,                           /* is_lcd_no_sleep */
                MMI_TRUE,                          /* is_full_screen */
                GDI_COLOR_WHITE,                    /* bg_color */
                PhnsetWpSsPlayCallBack,
                guiBuffer);
            
        }
    #endif
    #ifdef __MMI_AVATAR__
        else if (res_type == FMGR_GROUP_AVATAR)
        {
            /* Play GIF animation or still image */
            dispchar_get_current_avatar_id(cur_screensaver, (U32 *)&filename_ptr, (U32 *)&serial_num);
            ShowCategory166Screen(cur_screensaver, filename_ptr, mmi_scrsvr_play_video_callback);
            
        }
#endif /* __MMI_AVATAR__ */
    
    }

    SetGroupKeyHandler(
        IdleScreenSaverGroupKeyHandler,
        (PU16) PresentAllKeys /* ScreenSaverLocks */ ,
        (U8) TOTAL_KEYS /* MAX_KEYS - 3 */ ,
        KEY_EVENT_DOWN);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_up_handler(mmi_scrsvr_pen_up_handler);
    wgui_register_pen_down_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_move_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_abort_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_repeat_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_long_tap_handler(mmi_pen_dummy_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* keypad lock key handler */
    if (g_keylock_context.gKeyPadLockFlag != 0) /*  If KeyPad Locked */
    {
    #ifdef __MMI_TOUCH_SCREEN__
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_SEND, KEY_EVENT_DOWN);
    #else /* __MMI_TOUCH_SCREEN__ */ 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_RSK, KEY_EVENT_DOWN);
    #endif 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_LSK, KEY_EVENT_DOWN);
    #endif 
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitScreenSaver
 * DESCRIPTION
 *  Exit function for screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.ScreenSaverRunFlag = 0;

    if (!g_idle_context.IsScrSvrSleepIn)
    {
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID); /* diamond, 2006/02/07 Keypad lock timer should be stopped because screensaver may be interrupted by a call */
    }
#ifdef __DRM_SUPPORT__
    DRM_stop_consume(consumer);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenSaverGroupKeyHandler
 * DESCRIPTION
 *  Group key handler fn for screen saver keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenSaverGroupKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  IdleRSKPressOnScreenSaver
 * DESCRIPTION
 *  This function tells if RSk has been pressed on idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleRSKPressOnScreenSaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsRSKPressOnScreenSaver = 1;
    EntryIdleScreen();
}


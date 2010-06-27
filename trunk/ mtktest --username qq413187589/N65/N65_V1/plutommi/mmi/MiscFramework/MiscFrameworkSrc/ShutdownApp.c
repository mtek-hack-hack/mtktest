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
 *   ShutdownApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for shutdowns whole system operation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#include "BuildCfg.h"
#include "AudioInc.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "ProfilesGexdcl.h"
#include "gpioInc.h"
#include "AlarmFrameworkProt.h"
#include "Bootup.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "MessagesExDcl.h"      /* extern void DeInitMessagesApp (void) */
#include "CallManagementGprot.h"        /* extern void DeInitCM(void) */
#include "FileManagerGProt.h"   /* file path, file error */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "WPSSProtos.h" /* phone setup interface */
#include "SimDetectionDef.h"
#include "SimDetectionGexdcl.h"

#ifdef __MMI_TVOUT__
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* __MMI_TVOUT__ */ 

#include "lcd_sw.h"
#include "lcd_if.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif 

#ifdef __MMI_CSTAR__
#include "cstarHMI.h"
#endif

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_custom_hw.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

/***************************************************************************** 
* Define
*****************************************************************************/
static void mmi_shutdown_speech_off_for_outstanding_call(void);
#ifdef __MMI_BT_SUPPORT__
extern void mmi_bt_host_device_power_off_pre_process(void);
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct _shutdown_callback_info
{
    FuncPtr shutdown_callback_f;
    U8 shutdown_callback_t;
} SHUTDOWNCALLBACKINFO;


/*****************************************************************************
* Global Variabl                                                          
*****************************************************************************/
#ifdef __DRM_SUPPORT__
static S32 consumer;
#endif

/*****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void QuitSystemOperation(void);      /* system shutdown operation */
extern void ShutdownSystemOperation(void);  /* kill all the object */
extern void CallBackPowerOffAnimationComplete(GDI_RESULT ret);
extern void DeInitApps(void);
extern void DeInitAllApplications(void);
extern void DeInitInsertApp(void);
extern void SPOFDeInit(void);
extern void KillWindowObject(void);         /* kill all semaphore and thread objects */
extern U16 KillObjects(void);               /* kill windows object */
extern void DeInitTimers(void);             /* stop all timers */

#ifdef __MMI_TODOLIST__
extern void DeInitToDoListApp(void);
#endif 
#ifdef __MMI_AVATAR__
extern void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id, U32 *serial_num);
#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
//static U8     gNetworkDeattachRspFlag = 0;
//static U8     gWapPowerOffRspFlag = 0;
//static U8     gShutDownAudioPlayFinishRspFlag = 0;
//static U8     gPowerOffPeriod = 0;
static pBOOL g_shutdown_is_terminate_diplay;
static pBOOL g_shutdown_is_successful_play = MMI_TRUE;
static pBOOL g_shutdown_is_image;
static pBOOL g_shutdown_is_still_image = MMI_FALSE;


/*****************************************************************************
* Local Function 
*****************************************************************************/
/* void mmi_shutdown_froce_terminate_display(void); */
void SystemShutdownTimeout(void);

#ifdef __MMI_WLAN_FEATURES__
static void mmi_shutdown_wifi_req(void);
#endif

static SHUTDOWNCALLBACKINFO mmi_shutdown_callbacks[] = 
{
    /* callback_timing = 0 : execute the callback before shutdown processes */
    /* callback_timing = 1 : execute the callback before quit system operation */
#ifdef __USB_IN_NORMAL_MODE__
    {mmi_usb_shutdown_handler, 0},
#endif
    {mmi_shutdown_speech_off_for_outstanding_call, 0},
#ifdef __MMI_BT_SUPPORT__
    {mmi_bt_host_device_power_off_pre_process, 0},
#endif
#ifdef __MMI_VOIP__
    {mmi_voip_deinit, 0},
#endif
#ifdef __MMI_WLAN_FEATURES__
    {mmi_shutdown_wifi_req, 0},
#endif
    {NULL, 0}   /* dummy one, please add callbacks before this entity */
};


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_exe_callback
 * DESCRIPTION
 *  Execute callbacks before shutdown
 * PARAMETERS
 *  t_flag      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_exe_callback(U8 t_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; mmi_shutdown_callbacks[i].shutdown_callback_f != NULL; i++)
    {
        if (mmi_shutdown_callbacks[i].shutdown_callback_f != NULL &&
            mmi_shutdown_callbacks[i].shutdown_callback_t == t_flag)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[Shutdown] Execute shutdown callback %d", i + 1);
            (*mmi_shutdown_callbacks[i].shutdown_callback_f) ();
            mmi_shutdown_callbacks[i].shutdown_callback_f = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  NwPlmnSetRSP
 * DESCRIPTION
 *  response handling of network deregister req
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NwPlmnSetRSP(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[NwPlmnSetRSP] Shutdown Proc: DeAttach Rsp Back");
    /* gNetworkDeattachRspFlag=1; */
    g_pwr_context.PowerOffMMIStatus |= 0x01;

    if (g_shutdown_is_still_image && g_shutdown_is_successful_play)
    {
        CallBackPowerOffAnimationComplete(GDI_GIF_LAST_FRAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RequestRacDetach
 * DESCRIPTION
 *  request to deregister network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void RequestRacDetach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NwPlmnSetRSP, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/*****************************************************************************
 * FUNCTION
 *  NwPlmnSetRSP
 * DESCRIPTION
 *  response handling of network deregister req
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NwPlmnSet2RSP(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* power off L4C2 first */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_POWER_OFF_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* then detach L4C1 */
    RequestRacDetach();
}


/*****************************************************************************
 * FUNCTION
 *  RequestRacDetach
 * DESCRIPTION
 *  request to deregister network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void RequestRac2Detach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetSlaveProtocolEventHandler(NwPlmnSet2RSP, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */


/* MTK justin WAP poweroff support */
#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  WapBrowserPoweroffRsp
 * DESCRIPTION
 *  After the WAP browser is shutdown, deregister network
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void WapBrowserPoweroffRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[WapBrowserPoweroffRsp] Shutdown Proc: WAP Back");
    /* gWapPowerOffRspFlag = 1; */
    g_pwr_context.PowerOffMMIStatus |= 0x02;
}


/*****************************************************************************
 * FUNCTION
 *  RequestWapShutdown
 * DESCRIPTION
 *  After the WAP browser is shutdown, deregister network
 *  
 *  This is used to shutdowns whole system opeartion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void RequestWapShutdown()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(WapBrowserPoweroffRsp, MSG_ID_WAP_BROWSER_POWEROFF_RSP);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_BROWSER_POWEROFF_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    /* The WAP browser should send back MSG_ID_WAP_BROWSER_POWEROFF_RSP in limited time. */
}

#endif /* WAP_SUPPORT */ 
/* MTK justin end */


/*****************************************************************************
 * FUNCTION
 *  ShutDownAudioFinishRes
 * DESCRIPTION
 *  handler fn for power off tone finish  ind
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 ShutDownAudioFinishRes(mmi_frm_int_event_type interrupt_evnet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[ShutDownAudioFinishRes] Shutdown Proc: Audio Back");
    /* gShutDownAudioPlayFinishRspFlag = 1; */
    g_pwr_context.PowerOffMMIStatus |= 0x04;

    if (g_shutdown_is_still_image && g_shutdown_is_successful_play)
    {
        CallBackPowerOffAnimationComplete(GDI_GIF_LAST_FRAME);
    }

    return MMI_FALSE;   /* ?? */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_play_video_callback
 * DESCRIPTION
 *  Play shutdown video result callback function
 * PARAMETERS
 *  result      [IN]        Of playing video
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_play_video_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shutdown_is_terminate_diplay)
    {
        return; /* means already terminated by time out, shall skip this callback */
    }

    /* treat as gif animation */
    /* change to GIF's return */

    g_pwr_context.PowerOffMMIStatus |= 0x04;

    if (result < 0)
    {
        /* failed to play video */
        g_shutdown_is_successful_play = MMI_FALSE;

        /* failed to play video, and force to shutdown */
        /* gShutDownAudioPlayFinishRspFlag = 1; */
        CallBackPowerOffAnimationComplete(result);
    }
    else
    {
        /* play video successfully */
        /* g_shutdown_is_successful_play = MMI_TRUE; */

        /* notify successful play once */
        /* gShutDownAudioPlayFinishRspFlag = 1; */
        CallBackPowerOffAnimationComplete(GDI_GIF_LAST_FRAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_show_image_callback
 * DESCRIPTION
 *  Show power off image result callback function
 * PARAMETERS
 *  result      [IN]        Of showing image
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_show_image_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shutdown_is_terminate_diplay)
    {
        return; /* means already terminated by time out, shall skip this callback */
    }

    if (result < 0)
    {
        /* failed to play video */
        g_shutdown_is_successful_play = MMI_FALSE;

        /* failed to play video, and force to shutdown */
        CallBackPowerOffAnimationComplete(result);
    }
    else if (result == GDI_IMAGE_IS_STILL_IMAGE)
    {
        /* g_shutdown_is_successful_play = MMI_TRUE; */
        g_shutdown_is_still_image = MMI_TRUE;
        CallBackPowerOffAnimationComplete(result);
    }
    else
    {
        /* play finish successfully */
        /* g_shutdown_is_successful_play = MMI_TRUE; */
        CallBackPowerOffAnimationComplete(result);
    }
}

/**************************************************************

   FUNCTION NAME     : mmi_shutdown_froce_terminate_display

   PURPOSE        : Force terminate shutdown display

   INPUT PARAMETERS  : nil

   OUTPUT PARAMETERS : nil

   RETURNS        : void

**************************************************************/
/*
 * void mmi_shutdown_froce_terminate_display(void)
 * {
 * // if can successful play once (can loop), do not need force teminate
 * if(!g_shutdown_is_successful_play)
 * {
 * g_shutdown_is_terminate_diplay   = MMI_TRUE;
 * g_shutdown_is_successful_play = MMI_TRUE;
 * 
 * CallBackPowerOffAnimationComplete(-1);
 * }
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_stop_animation
 * DESCRIPTION
 *  Stop power off animation screen when ready to shutdown
 *  
 *  When ready to enter power on screen, it will enter goto_opening_screen(),
 *  in this function, it will call InitAllApplications(), there are NVRAM access
 *  in this function, which will cause NVRAM & timer interlace problem.
 *  
 *  We have to stop all animation timer when we are sure poweron procdure success.
 *  We may call this function in mmi_ready_to_idle_screen_ind.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_stop_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pwroff_flag;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop force teminate timer */
    /* gui_cancel_timer(mmi_shutdown_froce_terminate_display); */

    if (g_shutdown_is_image)
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
    if (!g_shutdown_is_successful_play)
    {
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        /* restore default */
        PhnsetRstPwrOffDisplayDefault();
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
    }

    pwroff_flag = PWROFF_DISPLAY_SUCCESS;
    WriteValue(NVRAM_POWER_OFF_DISPLAY_SUCCESS, &pwroff_flag, DS_SHORT, &error);
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pwroff_drm_callback
 * DESCRIPTION
 *  Power off DRM consume callback
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwroff_drm_callback(S32 res, S32 id)
{
    DRM_stop_consume(consumer);
    /* PhnsetScreenSaverBadFileCallBack(); */
}

#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_entry_animation_screen
 * DESCRIPTION
 *  Start play power off animation (GIF animation, still image, or video clip)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_entry_animation_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 disp_id;
    PS8 filename_ptr = NULL;
    FS_HANDLE fs_handle;
    U16 res_type = FMGR_GROUP_IMAGE;
    S16 error;
    U8 pwroff_flag;
    U8 pwron_flag;

#ifdef __MMI_AVATAR__
    U32 serial_num;
#endif

    /* U16          force_stop_time; */

#if defined(__MMI_VIDEO_PLAYER__)
    BOOL play_audio;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_shutdown_is_successful_play = MMI_FALSE; */
    g_shutdown_is_image = MMI_TRUE;

    TurnOnBacklight(0);

    /* 1. If shutdown while power on display is playing, we still dont know it will play successfully or not, so set the flag to 0xff, let it check next time */
    ReadValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);
    if (pwron_flag == PWRON_DISPLAY_PLAYING)
    {
        pwron_flag = PWRON_DISPLAY_SUCCESS;
        WriteValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &pwron_flag, DS_SHORT, &error);
    }

    /* 2. This timer is used to avoid gif/video play too long, will force to enter idle */
    /*
     * ReadValue(NVRAM_POWER_OFF_FORCE_STOP_TIME, &force_stop_time, DS_SHORT, &error);
     * if(force_stop_time == 0xffff)
     * {
     * // not set in NVRAM, use defulat 15 sec limit
     * force_stop_time = 15000;
     * }
     * 
     * gui_start_timer(force_stop_time, mmi_shutdown_froce_terminate_display);
     */
    g_shutdown_is_terminate_diplay = MMI_FALSE;

    /* 3. Valid power off display restoration checking */
    ReadValue(NVRAM_POWER_OFF_DISPLAY_SUCCESS, &pwroff_flag, DS_SHORT, &error);
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    if (pwron_flag == PWRON_DISPLAY_FAILED)
    {
        /* If not 0xff, means something wrong happened during playing power off display, we will restore power off display to default settings */
        PhnsetRstPwrOffDisplayDefault();
    }
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

    /* 4. Set the flag to 0x01 , if play successfully to end, will reset back to 0xff */
    pwroff_flag = PWROFF_DISPLAY_PLAYING;
    WriteValue(NVRAM_POWER_OFF_DISPLAY_SUCCESS, &pwroff_flag, DS_SHORT, &error);

    /* 5. Get animation resource from phone setup */
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    PhnsetGetPwrOffDisp(&disp_id);

    if (disp_id == 0xff)    /* invalid format */
    {
        PhnsetRstPwrOffDisplayDefault();    /* reset as default */
        PhnsetGetPwrOffDisp(&disp_id);      /* this id must be a valid id */
    }
    else if (disp_id == 0x00 || disp_id == 0x01)    /* 0x00: source from file, 0x01: short file name */
    {
        PS8 error;

        disp_id = 0x00;

        filename_ptr = PhnsetGetPwrOffFileName();   /* filename buffer is allocated in phnset */
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_POWER_ON_OFF_DSPL, filename_ptr, &error))
        {
            /* limit check failed */
            /* reset to default */
            PhnsetRstPwrOffDisplayDefault();

            /* this id must be a valid id */
            PhnsetGetPwrOffDisp(&disp_id);
            filename_ptr = NULL;
        }
    }
#ifdef __MMI_AVATAR__
    else if(PhnsetGetDisplayType(disp_id) == PHNSET_TYPE_DISP_AVATAR)
    {
        dispchar_get_current_avatar_id(disp_id, (U32 *)&filename_ptr, (U32 *)&serial_num);

        if (!mmi_avatar_is_avatar_valid((U32)filename_ptr, (U32)serial_num))
        {
            PhnsetRstPwrOffDisplayDefault();

            /* this id must be a valid id */
            PhnsetGetPwrOffDisp(&disp_id);
        }   
        filename_ptr = NULL;
    }
#endif /* __MMI_AVATAR__ */
    else    /* source from intenal resource */
    {
        filename_ptr = NULL;
    }

    /* 6. Check if is image or video */
    if (filename_ptr != NULL)   /* get file resource type */
    {
#ifdef __DRM_SUPPORT__
        U8 permission = 0;
        kal_bool is_permitted = KAL_FALSE; 
#endif
        
        res_type = mmi_fmgr_get_file_group(filename_ptr);   /* source from file */

        if (res_type == FMGR_GROUP_IMAGE)
        {
            g_shutdown_is_image = MMI_TRUE;
#ifdef __DRM_SUPPORT__
            permission = DRM_PERMISSION_DISPLAY;
#endif
        }
        else if (res_type == FMGR_GROUP_VIDEO)
        {
            g_shutdown_is_image = MMI_FALSE;
#ifdef __DRM_SUPPORT__
            permission = DRM_PERMISSION_PLAY;
#endif
        }
    #ifdef __MMI_SWFLASH__
        else if (res_type == FMGR_GROUP_SWFLASH)
        {
            g_shutdown_is_image = TRUE;
        }
    #endif /* __MMI_SWFLASH__ */
        else
        {
            PhnsetRstPwrOffDisplayDefault();    /* unsupported file format ext and restore default */
            PhnsetGetPwrOffDisp(&disp_id);      /* this id must be a valid id */
            filename_ptr = NULL;
        }

    #ifdef __DRM_SUPPORT__
        /* DRM permission check */
        if ((fs_handle = DRM_open_file((PU16) filename_ptr, FS_READ_ONLY, permission)) >= FS_NO_ERROR)
        {
            if (res_type == FMGR_GROUP_IMAGE && DRM_validate_forward_rule(fs_handle, permission))
            {
                consumer = DRM_consume_rights(fs_handle, permission, mmi_pwroff_drm_callback);
                is_permitted = KAL_TRUE;
            }
        #ifdef __MMI_SWFLASH__
            else if (res_type == FMGR_GROUP_SWFLASH && DRM_validate_forward_rule(fs_handle, permission))
            {
                consumer = DRM_consume_rights(fs_handle, permission, mmi_pwroff_drm_callback);
                is_permitted = KAL_TRUE;
            }
        #endif /* __MMI_SWFLASH__ */
            else if (res_type == FMGR_GROUP_VIDEO && DRM_validate_forward_rule(fs_handle, permission))
            {
                /* consumer = DRM_consume_rights(fs_handle, DRM_PERMISSION_PLAY, mmi_pwroff_drm_callback); */
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
            PhnsetRstPwrOffDisplayDefault();    /* open file failed and reset as default */
            PhnsetGetPwrOffDisp(&disp_id);      /* this id must be a valid id */
            filename_ptr = NULL;
        }
        else
        {
            FS_Close(fs_handle);    /* open file successful */
        }


        
    }

    /* 7. Check internal resource type */
    if (filename_ptr == NULL)
    {
        res_type = PhnsetGetDisplayType(disp_id);

        if (res_type == PHNSET_TYPE_DISP_IMAGE)
        {
            g_shutdown_is_image = MMI_TRUE;
            res_type = FMGR_GROUP_IMAGE;
        }
        else if (res_type == PHNSET_TYPE_DISP_VIDEO)
        {
            g_shutdown_is_image = MMI_FALSE;
            res_type = FMGR_GROUP_VIDEO;
        }
    #ifdef __MMI_SWFLASH__
        else if (res_type == PHNSET_TYPE_DISP_SWFLASH)
        {
            g_shutdown_is_image = TRUE;
            res_type = FMGR_GROUP_SWFLASH;
        }
    #endif /* __MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        else if (res_type == PHNSET_TYPE_DISP_AVATAR)
        {
            g_shutdown_is_image = TRUE;
            res_type = FMGR_GROUP_AVATAR;
        }
    #endif /* __MMI_SWFLASH__ */
        else
        {
            MMI_ASSERT(0);
        }
    }

#else /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
    /* 7. Play from internal build in resource */
    g_shutdown_is_image = MMI_TRUE;
    disp_id = IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT;  /* Cylen 0926, customize display char */
    filename_ptr = NULL;

#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

    /* 8. Start to play */
    if (res_type == FMGR_GROUP_IMAGE)
    {
        ShowCategory166Screen(disp_id, filename_ptr, mmi_shutdown_show_image_callback);
        ShowCategory313Screen(IMG_SUBLCD_SYSTEM_SHUTDOWN, NULL);

        /* play power off tone */
        if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT)
        {
            playRequestedTone(POWER_OFF_TONE);
            /* Shall set interrupt event handler */
            /* mdi will register event handler itself, shall not preempt it */
            mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_AUDIO_PLAY_FINISH, ShutDownAudioFinishRes, NULL);
        }
        else
        {
            /* gShutDownAudioPlayFinishRspFlag = 1; */
            g_pwr_context.PowerOffMMIStatus |= 0x04;
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[ShutdownSystemOperation] Shutdown Proc: Audio Back");
        }
    }
    else if (res_type == FMGR_GROUP_VIDEO)
    {
    #if defined(__MMI_VIDEO_PLAYER__)
        /* check silent mode */
        play_audio = (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT) ? MMI_TRUE : MMI_FALSE;

        /* set volume as ring tone volume */
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        /* entry video play screen */
        ShowCategory224Screen(
            disp_id,                            /* video id */
            filename_ptr,                       /* filename */
            0,                                  /* repeat_count, 0 means infinite */
            MMI_TRUE,                           /* is_visaul_update */
            play_audio,                         /* is_play_audio */
            MMI_FALSE,                          /* is_lcd_sleep, already in non sleep mode */
            GDI_COLOR_BLACK,                    /* bg_color */
            mmi_shutdown_play_video_callback,   /* (*play_finish_callback)(S16) */
            NULL);                              /* gui_buffer */
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
            mmi_shutdown_show_image_callback,
            NULL);
        
    }
#endif  /* __MMI_SWFLASH__ */
#ifdef __MMI_AVATAR__
    else if (res_type == FMGR_GROUP_AVATAR)
    {

        dispchar_get_current_avatar_id(disp_id, (U32 *)&filename_ptr, (U32 *)&serial_num);
        
        ShowCategory166Screen(disp_id, filename_ptr, mmi_shutdown_show_image_callback);
        ShowCategory313Screen(IMG_SUBLCD_SYSTEM_SHUTDOWN, NULL);

        /* play power off tone */
        if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT)
        {
            playRequestedTone(POWER_OFF_TONE);
            /* Shall set interrupt event handler */
            /* mdi will register event handler itself, shall not preempt it */
            mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_AUDIO_PLAY_FINISH, ShutDownAudioFinishRes, NULL);            
        }
        else
        {
            /* gShutDownAudioPlayFinishRspFlag = 1; */
            g_pwr_context.PowerOffMMIStatus |= 0x04;
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[ShutdownSystemOperation] Shutdown Proc: Audio Back");
        }
        
    }
#endif /* __MMI_AVATAR__ */

}

#if defined(HORSERACE_SUPPORT)
extern int   FlagsReachIdle	 ;
extern void SendMessagesMMIToTwo(msg_type MSG_ID );
#endif
/*****************************************************************************
 * FUNCTION
 *  ShutdownSystemOperation
 * DESCRIPTION
 *  Shutdowns whole system opeartion
 *  
 *  This is used to shutdowns whole system opeartion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShutdownSystemOperation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    /*
     * When power off the system, subLCD may be still in master mode.
     * We need to let subLCD enter the slave mode and subLCD could be shown the power off screen.
     */
    SubLCDMasterModeClamOpen();
#endif /* __MMI_SUBLCD_MASTER_MODE__ */

    /* gPowerOffPeriod = 1; */
    g_pwr_context.PowerOffMMIStatus = MMI_POWER_OFF_ANIMATION;

   #if defined(HORSERACE_SUPPORT)
	   FlagsReachIdle	=0 ;
	   SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
#if defined(NOKE_DEBUG)
	   noke_dbg_printf("Huyanwei Debug Shut Down System ......\r\n");
#endif
   #endif

    /* exit poweroff anmation screen by enter a dummy screen */
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

    PRINT_INFORMATION("File: [%s]  Line: [%d] <<it shutdowns whole system opeartion>>\n", __FILE__, __LINE__);

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_AD_Shutdown(MTPNP_AD_SHUTDOWN_NORMAL);
#endif

    #if defined(__MMI_CSTAR__)
    ExitCstarInputMethod();
    #endif

    mmi_shutdown_exe_callback(0);   /* execute callbacks from other app */

    TurnOnBacklight(0);                     /* turn on backlight for power off animation */
    StopTimer(TIMER_REAL_TIME_CLOCK);       /* stops one sec timer */
    mdi_audio_suspend_background_play();    /* stop background music */
    DeInitFramework();                      /* clear history, key, timer, protocol, hardware events & other objects */
    DeInitCM();                             /* deinit call management */
    ClearAllProtocolEventHandler();         /* clear registered handlers */
    DeInitTimers();                         /* stop all timers */
    DeInitApps();                           /* deinit applications */
    AlmDeInit();                            /* deinit alarm */
    terminate_UI_demo();                    /* temporary: should be done in a more formal manner */
#ifdef __MMI_BT_PROFILE__
    mdi_audio_bt_hfp_turn_off();            /* Switch path back to phone then before disconnect SCO*/
    mdi_audio_bt_close_stream(BT_HFP);    
#endif 
    mmi_shutdown_entry_animation_screen();  /* dispalay shutdown animation screen */
    StartLEDPatternPowerOff();              /* play LED pattern for shutdown */

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[ShutdownSystemOperation] ShutDown Proc: Start! ");

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    RequestRac2Detach();
#else
    RequestRacDetach();                         /* detach network */
#endif

#ifdef WAP_SUPPORT
    RequestWapShutdown();                       /* detach wap */
#else 
    g_pwr_context.PowerOffMMIStatus |= 0x02;    /* gWapPowerOffRspFlag = 1; */
#endif 
#ifndef __MTK_TARGET__
    g_pwr_context.PowerOffMMIStatus |= 0x04;    /* no audio playback in MoDIS */
#endif

    /* start a timer to force shutdown if there is no detach response from RAC/L4C */
    StartTimer(SYSTEM_SHUTDOWN, POWER_OFF_TIMER_STAGE_1, SystemShutdownTimeout);
}


/*****************************************************************************
 * FUNCTION
 *  SystemShutdownTimeout
 * DESCRIPTION
 *  Call back fn on timeout of timer SYSTEM_SHUTDOWN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SystemShutdownTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SYSTEM_SHUTDOWN);

    //gNetworkDeattachRspFlag=1;
    //gShutDownAudioPlayFinishRspFlag = 1;
    //gWapPowerOffRspFlag = 1;
    g_pwr_context.PowerOffMMIStatus = 0x0F; /* MMI_POWER_OFF_QUIT; */

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SystemShutdownTimeout] ShutDown Proc: Timeout! ");

    /* start a new timer to quit system operation */
    StartTimer(SYSTEM_SHUTDOWN, POWER_OFF_TIMER_STAGE_2, QuitSystemOperation);  /* Robin 1217, Guard Timer */

}


/*****************************************************************************
 * FUNCTION
 *  PowerOffRsp
 * DESCRIPTION
 *  Res handling of Power Off req.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PowerOffRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_power_off_rsp_struct *p = (mmi_eq_power_off_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KeyPadLCDBackLightStop();


    if (p->result == MMI_TRUE)
    {
        PRINT_INFORMATION("@@@@@ ShutDown Process Success!!!!!  @@@@@");
    }
    else
    {
        PRINT_INFORMATION("@@@@@ ShutDown Process Failure!!!!!  @@@@@");
    }
}


/*****************************************************************************
 * FUNCTION
 *  QuitSystemOperation
 * DESCRIPTION
 *  Send req to L4 to power off the device.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void QuitSystemOperation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shutdown_is_terminate_diplay = MMI_TRUE;

    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);    /* turn off backlight to prevent blank screen */

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_AD_Shutdown(MTPNP_AD_SHUTDOWN_QUICK);
#endif

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_stop();
    }
#endif /* __MMI_TVOUT__ */ 

    mmi_shutdown_stop_animation();  /* stop shut down animations */

    /* exit poweroff anmation screen by enter a dummy screen */
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

    /* stop music again, cause ExitCategoryVdoplyScreen will resume it */
    mdi_audio_suspend_background_play();

    /* gPowerOffPeriod = 1; */
    g_pwr_context.PowerOffMMIStatus = MMI_POWER_OFF_QUIT;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[QuitSystemOperation] ShutDown Proc: Poweroff! ");

    StopTimer(SYSTEM_SHUTDOWN); /* stops shutdown timer */

    mmi_shutdown_exe_callback(1);   /* execute callbacks from other app */

    StopLEDPatternPowerOff();       /* stop LCD pattern for shutdown */
    lcd_power_on(MAIN_LCD, 0);      /* power off lcd */
#ifdef __MMI_SUBLCD__
    lcd_power_on(SUB_LCD, 0);       /* power off sub-lcd */
#endif 
#ifndef __MTK_TARGET__
    exit(0);
#endif 
    SetProtocolEventHandler(PowerOffRsp, PRT_POWER_OFF_RSP);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_POWER_OFF_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);   /* message for power off device */

    OslDumpDataInFile();
}


/*****************************************************************************
 * FUNCTION
 *  CallBackPowerOffAnimationComplete
 * DESCRIPTION
 *  Call back fn for Power off animation.
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CallBackPowerOffAnimationComplete(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[CallBackPwrOffAniCmplte] Shutdown Proc: Animation CallBack");

#if !defined(__MMI_DUAL_SIM_MASTER__) || defined (__MMI_DUAL_SIM_SINGLE_CALL__)
    if (ret < 0)
#else
    if (ret < 0 && MTPNP_AD_SDK_Is_Shutdown_Finished())
#endif
    {
        /* broken animation image */
        QuitSystemOperation();
        return;
    }

    /* if(gNetworkDeattachRspFlag && gShutDownAudioPlayFinishRspFlag && gWapPowerOffRspFlag ) */
#if !defined(__MMI_DUAL_SIM_MASTER__) || defined (__MMI_DUAL_SIM_SINGLE_CALL__)
    if (g_pwr_context.PowerOffMMIStatus == 0x0F)
#else
	if (g_pwr_context.PowerOffMMIStatus == 0x0F && MTPNP_AD_SDK_Is_Shutdown_Finished())
#endif
    {
        /* if receive all detach flags, start to quit system operation */
        /* else, wait stage 2 timer expires to quit system operation */
        //gNetworkDeattachRspFlag=0;
        //gShutDownAudioPlayFinishRspFlag = 0;
        //gWapPowerOffRspFlag = 0;
        QuitSystemOperation();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_is_in_power_off_period
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_shutdown_is_in_power_off_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PowerOffMMIStatus > MMI_POWER_OFF_DEFAULT)
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
 *  DeInitAllApplications
 * DESCRIPTION
 *  De-initialization
 *  
 *  This is used to De-initialize all applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitAllApplications(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPOFDeInit();           /* deinit schedule power on/off */
    DeInitMessagesApp();    /* deinit message application */
#ifdef __MMI_TODOLIST__
    DeInitToDoListApp();    /* deinit to do list */
#endif
}


/*****************************************************************************
 * FUNCTION
 *  DeInitInsertSimApp
 * DESCRIPTION
 *  DeInitialization
 *  
 *  This is used to De-initialize applications when no SIM is present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitInsertSimApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TODOLIST__
    DeInitToDoListApp();    /* deinit to do list */
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  DeInitApps
 * DESCRIPTION
 *  DeInitialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitApps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern U8 gInitAllAppFlag;
    extern U8 gInsertSimAppFlag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gInitAllAppFlag)
    {
        DeInitAllApplications();
    }
    else if (gInsertSimAppFlag)
    {
        DeInitInsertSimApp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeInitTimers
 * DESCRIPTION
 *  DeInitialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitTimers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 timer_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop all timers no matter it is running or not */
    for (timer_id = 0; timer_id < MAX_TIMERS; timer_id++)
    {
        StopTimer(timer_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_speech_off_for_outstanding_call
 * DESCRIPTION
 *  Shutdown callback to check if there is a call in shutdown period
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_shutdown_speech_off_for_outstanding_call(void)
{
    if (isInCall())
    {
        if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_GSM)
        {
            mdi_audio_speech_codec_stop();
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);
        }
        else if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_WCDMA)
        {
            mdi_audio_speech_codec_stop();
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_WCDMA);
        }        	
    }
}


#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_wifi_req
 * DESCRIPTION
 *  shutdown wifi the module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_shutdown_wifi_req(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WNDRV;
    Message.oslMsgId = MSG_ID_WNDRV_MMI_POWEROFF_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* __MTK_TARGET__ */
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
#endif /* 0 */
#endif /* __MMI_WLAN_FEATURES__ */


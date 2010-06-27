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
*  AudioPlayerMsgHandler.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player message handling
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * modify API : BOOL mmi_audply_is_playing(void)
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"

#include "SettingProfile.h"
#include "HardwareEvents.h"

#include "IdleAppDef.h"
#include "CommonScreens.h"

/* dependent headers for AudioPlayerXXX.h" */
#include "gui_data_types.h"
#include "mdi_datatype.h"
#include "Conversions.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"
#include "Ucs2prot.h"
#include "IdleAppProt.h"
#include "gpioInc.h"
#include "mdi_audio.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerPlayList.h"

#ifdef __MMI_SUBLCD__
#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) || defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
#include "gui_spectrum.h"
#endif

#include "CallManagementGprot.h"
#include "IdleAppProt.h"

/*DRM related*/
#include "DRM_gprot.h"
#include "RightsMgrResDef.h"
#include "DRM_errcode.h"

#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
static BOOL wait_open_bt = FALSE;
#endif

/* For single play */
extern U8 single_play_state;
extern U32 single_play_duration;
extern kal_uint32 single_play_time;
extern BOOL in_single_play_screen;
extern U8 single_volume;

#ifdef __MMI_AUDIO_PLAYER__

extern BOOL g_mmi_audply_play_completed_after_button_down;  /* defined in AudioPlayerSrc.c */
extern BOOL g_mmi_audply_init_done;                         /* defined in AudioPlayerSrc.c */
/* for memery card plug-in and plug-out */
extern BOOL need_refresh_list;
extern BOOL need_reload_list;
extern BOOL no_card_in_slot;

extern void (*RedrawCategoryFunction) (void);   /* defined in wgui_categories.c */
extern void idle_screen_show_network_details(void);  /* defined in wgui_categories_idlescreen.c */
//extern pBOOL mmi_bootup_is_sim_valid(void);     /* defined in BootupApp.c */

extern audply_struct g_audply;  /* defined in AudioPlayerSrc.c */

extern BOOL g_mmi_audply_longpressed; /* defined in AudioPlayerSrc.c */
extern BOOL g_mmi_audply_non_play_longpressed; /* defined in AudioPlayerSrc.c */

#ifdef __MTK_TARGET__
extern __align(4) U8 audio_cache[BUILD_CACHE_SIZE]; /* defined in AudioPlayerSrc.c */
#else
extern U8 audio_cache[BUILD_CACHE_SIZE]; /* defined in AudioPlayerSrc.c */
#endif /* __MTK_TARGET__ */

extern BOOL g_mmi_audply_longpressed ;

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
#ifndef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
__align(2) S8 g_mmi_lyric_str_buff[AUDPLY_LYRIC_STR_BUFF_MAX_SIZE];
#else
S8 *g_mmi_lyric_str_buff = NULL ;
#endif /*__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__*/
BOOL lyric_parse_ok = FALSE;
BOOL lyric_backlight_has_turn_on = FALSE;
BOOL lyric_full = FALSE;
extern BOOL lyric_reEntry;
extern BOOL g_audply_lyrics_valid;

extern scrolling_text *audply_scrolling_lyric_p1;
extern audply_lyric_struct audply_lyric;                /* defined in AudioPlayerSrc.c */
extern audply_lyric_printing_struct audply_lyric_print; /* defined in AudioPlayerMainScreen.c */
#ifdef __GDI_MEMORY_PROFILE_2__
extern GDI_HANDLE audply_osd_layer;                     /* defined in AudioPlayerMainScren.c */
#endif /*__GDI_MEMORY_PROFILE_2__*/
extern U8 PhnsetGetDefEncodingType(void);
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

extern signed char g_audply_main_selected_button;   /* defined in AudioPlayerMainScreen.c */
extern BOOL g_audply_main_selected_button_down;     /* defined in AudioPlayerMainScreen.c */

#ifdef __MMI_A2DP_SUPPORT__
extern mmi_bt_dev_struct *mmi_audply_get_bt_headset(void);
static kal_bool to_resume = KAL_FALSE;
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
BOOL static is_spectrum_calc_on = FALSE;
extern spectrum_struct g_aud_ply_spectrum;
extern BOOL g_audply_spectrum_valid;
extern BOOL g_audply_spectrum_blocked;

#ifdef __MMI_SUBLCD__
extern spectrum_struct g_aud_ply_spectrum_sub_lcd;
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_calc_spectrum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_calc_spectrum(BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_spectrum_calc_on)
    {
        if (!on)
        {
            mdi_audio_stop_calc_spectrum();
        }
    }
    else
    {
        if (on)
        {
            mdi_audio_start_calc_spectrum();
        }
    }
    is_spectrum_calc_on = on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_turn_on_spectrum
 * DESCRIPTION
 *  called when back light is truned on.
 * IMPACT
 *  start calcting specturm and drawing spectrum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_turn_on_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
    {
        if (g_audply.state == STATE_PLAY)
        {
        /*turn on calc for sunLCD*/
        #ifdef __MMI_SUBLCD__
            mmi_audply_calc_spectrum(TRUE);
        #endif
            if (g_audply.in_main_screen)
            {
            	mmi_audply_calc_spectrum(TRUE);
                mmi_audio_spectrum_init_display(&g_aud_ply_spectrum);
                mmi_audio_spectrum_start_display(&g_aud_ply_spectrum);
            }
        #ifdef __MMI_SUBLCD__
            if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
            {
                ShowIdleAppSubLcd();
            }
        #endif /* __MMI_SUBLCD__ */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_turn_off_spectrum
 * DESCRIPTION
 *  called when back light is truned off.
 * IMPACT
 *  stop calcing specturm and stop drawing spectrum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_turn_off_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.spectrum_style != 0 )
    {
        if (g_audply.state == STATE_PLAY)
        {
            mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum);
        #ifdef __MMI_SUBLCD__
            mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum_sub_lcd);
        #endif 
            mmi_audply_calc_spectrum(FALSE);
        }
    }
}

#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
extern void GoBackSubLCDHistory(void);
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_play_speed_normal
 * DESCRIPTION
 *  return is the current play speed normal
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_is_play_speed_normal(void)
{
#ifdef __MMI_AUDIO_TIME_STRETCH__
    return g_audply.speed == MDI_AUDIO_SPEED_NORMAL;
#else
    return TRUE;
#endif
}

#ifdef __MMI_A2DP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_wait_open_bt
 * DESCRIPTION
 *  return if it's waiting for opening bt
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_is_wait_open_bt(void)
{
    return wait_open_bt;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_open_callback(S32 result)
{
    BOOL prev_wait_open_bt = wait_open_bt;


    PRINT_INFORMATION("mmi_audply_bt_open_callback: wait_open=%d, longpress=%d, result=%d\n",wait_open_bt,g_mmi_audply_longpressed,result);

    wait_open_bt = FALSE;
    if(g_mmi_audply_longpressed)
    {
        return ;
    }
    switch( result )
    {
    case AV_BT_CALLBACK_EVENT_OPEN_OK:
        if (g_audply.state == STATE_PLAY)
        {
            av_bt_open_codec(KAL_TRUE);
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = TRUE ;
            mmi_audply_turn_off_spectrum();
        #endif
        }
        else
        {
            av_bt_open_codec(KAL_FALSE);
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = TRUE ;
        #endif
            if (to_resume)
            {
                ASSERT(g_audply.state == STATE_PAUSED);
                to_resume = KAL_FALSE;
                /*change state because it is not called by button pressing and 
                  it might already be in main screen so there is no chance to update 
                  state by calling entry main screen*/
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
                g_audply_main_selected_button_down = FALSE;                                
                mmi_audply_do_resume_action();
            }
            else
            {
                if (g_audply.need_restore)
                {
                    mmi_audply_do_restore_action();
                }
                else
                {
                    mmi_audply_do_play_action();
                }
            }
            if( g_audply.state == STATE_IDLE )
            {
                av_bt_close_codec();
            #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
                g_audply_spectrum_blocked = FALSE ;
            #endif
            }
        }
        break;
    case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
    case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
        if (g_audply.state == STATE_PLAY)
        {
            av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
            mmi_audply_turn_on_spectrum();
        #endif            
        }
        else if (to_resume)
        {
            ASSERT(g_audply.state == STATE_PAUSED);
            to_resume = KAL_FALSE;
            /*change state because it is not called by button pressing and 
              it might already be in main screen so there is no chance to update 
              state by calling entry main screen*/
            g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
            g_audply_main_selected_button_down = FALSE;                            
            mmi_audply_do_resume_action();
        }
        else
        {
            if (g_audply.need_restore)
            {
                mmi_audply_do_restore_action();
            }
            else
            {
                mmi_audply_do_play_action();
            }
        }
        break;
    case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
        to_resume = KAL_FALSE;
        g_audply.need_replay = prev_wait_open_bt;
        break;
    case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
    case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
    case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
    case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        if( g_audply.state == STATE_PLAY )
        {
            av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
            mmi_audply_turn_on_spectrum();
        #endif            
        }
        break;
    case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        if (g_audply.state == STATE_PLAY)
        {
            wait_open_bt = TRUE;
            av_bt_open(mmi_audply_get_bt_headset(), g_audply.prev_filefullname, 
                mmi_audply_bt_open_callback, !mmi_audply_is_play_speed_normal(),
                KAL_TRUE);
        }
        else
        {
            av_bt_close(KAL_FALSE);
        }
        break;
    case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        if (mmi_audply_is_output_to_bt() && av_bt_is_streaming() &&
            g_audply.state == STATE_PLAY)
        {
            mmi_audply_do_pause_action(FALSE);
            if (g_audply.state != STATE_PLAY)
            {
                av_bt_close_codec();
            #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
                g_audply_spectrum_blocked = FALSE ;  
            #endif                
            }
            if (g_audply.state == STATE_PAUSED)
            {
                to_resume = KAL_TRUE;
                av_bt_pause();
            }
            //av_bt_pause();
        }
        break;
    case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
        if (to_resume)
        {
            to_resume = KAL_FALSE;
            if (g_audply.state == STATE_PAUSED)
            {
                mmi_audply_resume();
            }
            else if (g_audply.state == STATE_IDLE && !wait_open_bt)
            {
                av_bt_close(KAL_FALSE);
            }
        }
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_switch_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_switch_bt_output(void)
{
    if (mmi_audply_is_output_to_bt())
    {
        /* switch output: OFF -> ON */
        if (g_audply.state == STATE_PLAY)
        {
            wait_open_bt = TRUE;
            av_bt_open(mmi_audply_get_bt_headset(), g_audply.prev_filefullname, 
                mmi_audply_bt_open_callback, !mmi_audply_is_play_speed_normal(),
                KAL_TRUE);
        }
    }
    else
    {
        /* switch output: ON -> OFF */
        if (g_audply.state == STATE_PLAY)
        {
            av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
            mmi_audply_turn_on_spectrum();
        #endif    
        }
        av_bt_close(KAL_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sync_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_sync_bt_output(void)
{
    AV_BT_CALLBACK callback = NULL;
    kal_wchar *filename;

    PRINT_INFORMATION("mmi_audply_sync_bt_output\n");

    ASSERT( mmi_audply_is_output_to_bt() );

    to_resume = KAL_FALSE;
    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_do_pause_action(TRUE);
        av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
            /*normally not need to turn on spectrum, in case pause not succeed*/
            mmi_audply_turn_on_spectrum();
        #endif        
        callback = mmi_audply_bt_open_callback;
    }
    else if (wait_open_bt)
    {
        callback = mmi_audply_bt_open_callback;
    }

    if (callback)
    {
        if (g_audply.state == STATE_PLAY) // can't pause
        {
            filename = g_audply.prev_filefullname;
        }
        else if (g_audply.state == STATE_PAUSED)
        {
            to_resume = KAL_TRUE;
            filename = g_audply.prev_filefullname;
        }
        else
        {
            filename = g_audply.filefullname;
        }
        wait_open_bt = TRUE;
        av_bt_open(mmi_audply_get_bt_headset(), filename, callback, 
            !mmi_audply_is_play_speed_normal(), KAL_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stop_codec      [IN]
 *  notify_opener   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_stop(BOOL stop_codec, BOOL notify_opener)
{

    /* always stop codec*/
    if( mmi_audply_is_output_to_bt() )
    {
//        if (stop_codec)
//        {
            av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
            mmi_audply_turn_on_spectrum();
        #endif            
//        }
        av_bt_close(notify_opener);
    }
}

#endif /* __MMI_A2DP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_play(void)
{
#ifdef __MMI_A2DP_SUPPORT__
    to_resume = KAL_FALSE;
    if( mmi_audply_is_output_to_bt() )
    {
        if( g_audply.state == STATE_PLAY )
        {
            mmi_audply_do_stop_action();
            av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
            mmi_audply_turn_on_spectrum();
        #endif
        }    
    #if defined(MT6223) || defined(MT6223P)
        if(!g_audply.support_A2DP)
        {
            DisplayPopup((PU8) GetString(STR_ID_AUDPLY_NOT_SUPPORT_A2DP), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);   
            mdi_audio_start_background_timer();
            g_audply.continue_playing = TRUE ;
            return;
        }
    #endif
        wait_open_bt = TRUE;
        av_bt_open(mmi_audply_get_bt_headset(), g_audply.filefullname, 
            mmi_audply_bt_open_callback, !mmi_audply_is_play_speed_normal(),
            KAL_TRUE);
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        mmi_audply_do_play_action();    /* do play action */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_restore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_restore(void)
{
#ifdef __MMI_A2DP_SUPPORT__
    to_resume = KAL_FALSE;
    if( mmi_audply_is_output_to_bt() )
    {
        wait_open_bt = TRUE;
        av_bt_open(mmi_audply_get_bt_headset(), g_audply.filefullname, 
            mmi_audply_bt_open_callback, !mmi_audply_is_play_speed_normal(),
            KAL_TRUE);
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        mmi_audply_do_restore_action();    /* do restore action */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pause(void)
{
    mmi_audply_do_pause_action(TRUE);   /* do pause action */
#ifdef __MMI_A2DP_SUPPORT__
    if( mmi_audply_is_output_to_bt() )
    {
        if( g_audply.state != STATE_PLAY )
        {
            av_bt_close_codec();
        #ifdef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
            g_audply_spectrum_blocked = FALSE ;
        #endif            
            av_bt_close(KAL_FALSE);
        }
        //av_bt_close(KAL_FALSE);
    }
#endif /* __MMI_A2DP_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_resume(void)
{
#ifdef __MMI_A2DP_SUPPORT__
    if( mmi_audply_is_output_to_bt() )
    {
        to_resume = KAL_TRUE;
        wait_open_bt = TRUE;
        av_bt_open(mmi_audply_get_bt_headset(), g_audply.prev_filefullname, 
            mmi_audply_bt_open_callback, !mmi_audply_is_play_speed_normal(),
            KAL_TRUE);
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        mmi_audply_do_resume_action();  /* do resume action */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_restore_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_restore_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = mmi_audply_do_restore_action_without_handle_result();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_played();
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        mmi_audply_play_completed();    /* in the case that we stopped a file when it's play finished */
    }
    else
    {
        mmi_audply_stopped();
        if (result > 0 && result != MDI_AUDIO_BLOCKED)
        {
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
            if(g_audply.in_sub_screen)
            {
                ExecSubLCDCurrExitHandler();
		        UI_set_sub_LCD_graphics_context();
                ClearAllKeyHandler();
                mmi_sub_audply_popup_error_key_handler();
                UI_set_main_LCD_graphics_context();

            }
            else
#endif
            {
                mmi_audply_display_popup(result);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_restore_action_without_handle_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_do_restore_action_without_handle_result()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U8* cache_ptr = NULL ;

#ifdef __MMI_AUDIO_TIME_STRETCH__
    S32 check_result;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
    g_audply.wait_next = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;
    /* mmi_audply_clear_play_seconds(); */

    if(mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
    {
        g_audply.duration = 0 ;
    }
    mmi_audply_determine_progress_speed();

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
      	UI_set_sub_LCD_graphics_context();
        mmi_audply_redraw_main_time();  /* update time: show 00:00 */
    	UI_set_main_LCD_graphics_context();
	}
    else
#endif
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_time();  /* update time: show MM:SS */
    }

    /* This could happen when timer experied after suspend background play or another play or record req by others */
    if (mdi_audio_is_background_play_suspended() || (g_audply.state == STATE_IDLE && !mdi_audio_is_idle()))
    {
        g_audply.need_replay = TRUE;
        g_audply.need_restore = TRUE;
        g_audply.state = STATE_IDLE;
        result = -1;
    }
    else
    {
        g_audply.state = STATE_IDLE;    /* for preventing from terminated callback; */
        g_audply.need_replay = FALSE;

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Check if audio time stretch support for the file */
        if ((check_result = mmi_audply_speed_check_before_play(g_audply.speed)) != MDI_AUDIO_SUCCESS)
        {
            mdi_audio_stop_all();
            return check_result;
        }

        /* Set audio time stretch speed before play request */
        mmi_audply_speed_set_speed();
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

        cache_ptr = mmi_audply_determine_cache_ptr();

        /*regisiter auto update time callback*/
        mdi_audio_regisiter_auto_update_duration_handler(mmi_audply_auto_update_duration_hdlr);

        /* Restore request */
        result = mdi_audio_restore_file_with_vol_path(
                    g_audply.filefullname,
                    DEVICE_AUDIO_PLAY_ONCE,
                    cache_ptr,
                    mmi_audply_play_callback_hdlr,
                    MDI_AUD_VOL_EX(g_audply.volume),
                    MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Reset speed if not play successfully */
        if (result != MDI_AUDIO_SUCCESS)
        {
            mmi_audply_speed_close();
        }
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

        if (result == MDI_AUDIO_SUCCESS)
        {
            g_audply.state = STATE_PLAY;
        }
        else if (result == MDI_AUDIO_BLOCKED)
        {
            g_audply.need_replay = TRUE;
            g_audply.need_restore = TRUE;
        }
        else if (result == MDI_AUDIO_BAD_FORMAT)    /* in this case, it means not able to do real resume. Let's try replay it */
        {
            mmi_audply_clear_play_seconds();
            if (g_audply.in_main_screen)
            {
                mmi_audply_redraw_main_time();  /* update time: show 00:00 */
            }
            
            cache_ptr = mmi_audply_determine_cache_ptr();

            /*regisiter auto update time callback*/
            mdi_audio_regisiter_auto_update_duration_handler(mmi_audply_auto_update_duration_hdlr);

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
            if(g_audply.in_sub_screen)
            {
             	UI_set_sub_LCD_graphics_context();
                mmi_audply_redraw_main_time();  /* update time: show 00:00 */
	    	    UI_set_main_LCD_graphics_context();
		    }
#endif
            result = mdi_audio_play_file_portion_with_vol_path(
                       g_audply.filefullname,
                       g_audply.new_play_time,
                       0,
                       DEVICE_AUDIO_PLAY_ONCE,
                       cache_ptr,
                       mmi_audply_play_callback_hdlr,
                       MDI_AUD_VOL_EX(g_audply.volume),
                       MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

            if (result == MDI_AUDIO_SUCCESS)
            {
                g_audply.state = STATE_PLAY;
            }
        }
    }

    return (S32) result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_play_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S8  error_class = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result =  mmi_audply_do_portion_play_action_without_handle_result(&error_class);

    if (error_class == 1)
    {
        if (result == MDI_AUDIO_SUCCESS)
        {
            mmi_audply_played();
        }
        else if (result == MDI_AUDIO_END_OF_FILE)
        {
            mmi_audply_play_completed();    /* in the case that we stopped a file when it's play finished */
        }
        else
        {
/*            if (g_audply.repeat_mode == REPEAT_ALL && 
                !g_audply.in_main_screen &&
                g_audply.n_total_items > 1)
            {
                mmi_audply_play_completed();
            }
            else */
            {
                mmi_audply_stopped();
                if (result > 0 && result != MDI_AUDIO_BLOCKED)
                {
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
                    if(g_audply.in_sub_screen)
                    {
                        ExecSubLCDCurrExitHandler();
    		            UI_set_sub_LCD_graphics_context();
                        ClearAllKeyHandler();
                        mmi_sub_audply_popup_error_key_handler();
                        UI_set_main_LCD_graphics_context();
                    }
                    else
#endif
                    {
                        g_audply.seekable = FALSE;
                        mmi_audply_display_popup(result);
                    }
                }
                if (g_audply.repeat_mode != REPEAT_ONE && g_audply.n_total_items > 1)
                {
                    mdi_audio_start_background_timer();
                    g_audply.continue_playing = TRUE ;
                }
            }
        }
    }
    else if (error_class == 0)
    {
/*        if (g_audply.repeat_mode == REPEAT_ALL && 
            !g_audply.in_main_screen &&
            g_audply.n_total_items > 1)
        {
            mmi_audply_play_completed();
        }
        else*/
        {
            mmi_audply_stopped();
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
            if(g_audply.in_sub_screen)
            {
                ExecSubLCDCurrExitHandler();
    	        UI_set_sub_LCD_graphics_context();
                ClearAllKeyHandler();
                mmi_sub_audply_popup_error_key_handler();
                UI_set_main_LCD_graphics_context();
            }
            else
#endif
            {
                g_audply.seekable = FALSE;
                DisplayPopup(
                    (PU8)GetString(GetFileSystemErrorString(result)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    (U8)ERROR_TONE);
            }

            if (g_audply.repeat_mode != REPEAT_ONE && g_audply.n_total_items > 1)
            {
                mdi_audio_start_background_timer();
                g_audply.continue_playing = TRUE ;
            }

        }
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_portion_play_action_without_handle_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_class     [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_do_portion_play_action_without_handle_result(PS8 error_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U8* cache_ptr = NULL ;
    FS_HANDLE handle;
#ifdef __MMI_AUDIO_TIME_STRETCH__
    S32 check_result;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
    g_audply.wait_next = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;

    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_time();  /* update time: show MM:SS */
    }
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    else if(g_audply.in_sub_screen)
    {
    	UI_set_sub_LCD_graphics_context();
        mmi_audply_redraw_main_time();  /* update time: show 00:00 */
    	UI_set_main_LCD_graphics_context();
    }
#endif
    if (mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
    {
        g_audply.duration = 0 ;
    }
    mmi_audply_determine_progress_speed();
    
    /*check and refresh cache*/
    mmi_audply_refresh_cache(TRUE);

    /* Check if file exists or not */
    handle = DRM_open_file((PU16)g_audply.filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    if (handle >= FS_NO_ERROR)
    {
        *error_class = 1;
        DRM_close_file(handle);
    }
    else
    {
        *error_class = 0;
        mmi_audply_stop_playing();
        return (S32)handle;
    }

    /* This could happen when timer experied after suspend background play or another play or record req by others */
    if (mdi_audio_is_background_play_suspended() || (g_audply.state == STATE_IDLE && !mdi_audio_is_idle()))
    {
        g_audply.need_replay = TRUE;
        g_audply.state = STATE_IDLE;
        result = -1;
    }
    else
    {
        g_audply.state = STATE_IDLE;    /* for preventing from terminated callback; */
        g_audply.need_replay = FALSE;
 
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Check if audio time stretch support for the file */
        if ((check_result = mmi_audply_speed_check_before_play(g_audply.speed)) != MDI_AUDIO_SUCCESS)
        {
            mdi_audio_stop_all();
            return check_result;
        }

        /* Set audio time stretch speed before play request */
        mmi_audply_speed_set_speed();
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
    
        cache_ptr = mmi_audply_determine_cache_ptr();

        /*regisiter auto update time callback*/
        mdi_audio_regisiter_auto_update_duration_handler(mmi_audply_auto_update_duration_hdlr);

        /* Portion play request */
        result = mdi_audio_play_file_portion_with_vol_path(
                   g_audply.filefullname,
                   g_audply.new_play_time,
                   0,
                   DEVICE_AUDIO_PLAY_ONCE,
                   cache_ptr,
                   mmi_audply_play_callback_hdlr,
                   MDI_AUD_VOL_EX(g_audply.volume),
                   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Reset speed if not play successfully */
        if (result != MDI_AUDIO_SUCCESS)
        {
            mmi_audply_speed_close();
        }
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

        if (result == MDI_AUDIO_SUCCESS)
        {
            g_audply.state = STATE_PLAY;
        }
        else if (result == MDI_AUDIO_BLOCKED)
        {
            g_audply.need_replay = TRUE;
        }
    }

    return (S32) result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_pause_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_pause_action(BOOL need_pop_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;
    
    result = mdi_audio_pause(0, mmi_audply_pause_callback_hdlr);
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_paused();
    }
    else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
    {
        /* pause action for ADIF AAC files are not supportted so keep it playing */
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
        if(need_pop_up)
        {
        #ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
            if(g_audply.in_sub_screen)
            {
                ExecSubLCDCurrExitHandler();    
                UI_set_sub_LCD_graphics_context();
                ClearAllKeyHandler();
                ShowCategory311Screen((U8*)get_string(mmi_audply_err_str(result)), IMG_GLOBAL_WARNING, NULL);
                StartTimer(POPUP_SUBLCD,700,GoBackSubLCDHistory);
              	UI_set_main_LCD_graphics_context();		
            }
            else
        #endif
            DisplayPopup((PU8) GetString(STR_ID_AUDPLY_CANNOT_PAUSE), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
        }
    }
    else
    {
        mmi_audply_play_completed();
    }

    /* If not continue playing, restore speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    if (result != MDI_AUDIO_UNSUPPORTED_OPERATION)
    {
        mmi_audply_speed_close();
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_resume_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_resume_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;

    /* Set play speed before resume, no need to check support because file is not close yet */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_set_speed();
#endif 

    /*in case it is muted by profile switching*/
    mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_EX(g_audply.volume));

    result = mdi_audio_resume(0, mmi_audply_play_callback_hdlr);

    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_resumed();
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        mmi_audply_play_completed();    /* in the case that we paused a file when it's play finished */
    }    
    else
    {
        g_audply.state = STATE_IDLE;

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Reset speed if not play successfully */
        mmi_audply_speed_close();
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
            if(g_audply.in_sub_screen)
            {
                ExecSubLCDCurrExitHandler();
		        UI_set_sub_LCD_graphics_context();
                ClearAllKeyHandler();
                mmi_sub_audply_popup_error_key_handler();
                UI_set_main_LCD_graphics_context();
            }
            else
#endif
            {
                mmi_audply_display_popup(result);
            }
            //g_audply.seekable = FALSE ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_stop_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_stop_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;
    g_audply.state = STATE_IDLE;    /* for preventing from set g_audply.need_replay = TRUE; */
    mdi_audio_stop_file();
    mmi_audply_stopped();

    if (g_audply.n_total_items == 0 && g_audply.pick_index == -1)
    {
        mmi_audply_clear_play_seconds();
        g_audply.restorable = FALSE;
        g_audply.seekable = FALSE;
        g_audply.need_to_build_cache = FALSE;
        g_audply.title[0] = 0;
        g_audply.filefullname[0] = 0;
        g_audply.buff_head = 0;
        g_audply.n_buff_items = 0;

        memset(g_audply.bitset, 0, MAX_PLAY_LIST_BYTES);
        g_audply.n_total_items = 0;
        g_audply.pick_index = -1;
        g_audply.pick_count = 0;

        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_screen();
        }
    }
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_audply_redraw_main_time();
        UI_set_main_LCD_graphics_context();
    }
#endif
    /* restore to normal speed when stop play */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_close();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stop_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stop_playing()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_audply_init_done)
    {
        return;
    }
    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
    g_audply.wait_next = FALSE;
    g_audply.need_replay = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;
    //mmi_audply_clear_play_seconds();
    if (g_audply.state != STATE_IDLE)
    {
        mmi_audply_do_stop_action();    /* stop song */
    }

    mmi_audply_clear_play_seconds();
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_time();
        mmi_audply_redraw_main_progressbar() ;
    }

#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_seek_stop_playing
 * DESCRIPTION
 *  do the stop playing actions except redraw mainscreen ones
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_seek_stop_playing()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
    g_audply.wait_next = FALSE;
    g_audply.need_replay = FALSE;
    g_audply.need_restore = FALSE;
    g_audply.continue_playing = FALSE;

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__     
    mmi_audply_stop_lyric();
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    /*this shall be done before state to IDLE, or it will not work*/
    mmi_audply_turn_off_spectrum();
#endif
    /*set before mdi_audio_stop_file to prevent from calling play_callback_hdlr*/
    g_audply.state = STATE_IDLE; 
    
    mdi_audio_stop_file();

#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
//    mmi_audply_speed_close();
#endif
    /*in case in rewind mode that old_play_time > new_play_time*/
    g_audply.old_play_time = 0 ;
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_encoding_type_change_callback
 * DESCRIPTION
 *  when default encoding type is changed, audio player can update file name
 * PARAMETERS
 *      
 * RETURNS
 *
 *****************************************************************************/
void mmi_audply_encoding_type_change_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    UI_character_type filefullname[FMGR_MAX_PATH_LEN + 1];
    UI_character_type wchar_filename[FMGR_MAX_FILE_LEN];
    UI_character_type filename[FMGR_MAX_FILE_LEN];
    UI_character_type ext[FMGR_MAX_EXT_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*set to zero so that it will use the new encoding type to update buffer*/
    g_audply.n_buff_items = 0 ;

    /*try to update current song title*/
    if ((result = mmi_audply_playlist_get_fullfilename(filefullname, g_audply.pick_index)) != 0)
    {
        if (result == 2)    /* if it is a short filename */
        {
            mmi_audply_extract_filename(wchar_filename, filefullname);
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) filename,
                (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH,
                (U8*) wchar_filename,
                g_chset_text_encoding);
        }
        else
        {
            mmi_audply_extract_filename(filename, filefullname);
        }
        mmi_audply_split_filename_ext(filename, g_audply.title, ext);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_background_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_background_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Audply: mmi_audply_background_callback_hdlr, replay:%d, longpress:%d, wait_next:%d, restore:%d, continue:%d",
                        g_audply.need_replay,g_mmi_audply_longpressed,g_audply.wait_next,g_audply.need_restore,g_audply.continue_playing);
    /*when under longpressed, shall skip background callback*/
    if (g_audply.need_replay && !g_mmi_audply_longpressed)
    {
        StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
        if (g_audply.wait_next || !g_audply.need_restore)
        {
            /*if output to bt, bt_callback will check need_restore flag then decide whether to play or 
              to restore. So we shall reset need_restore flag while wait_next is true */
            if(g_audply.wait_next)
            {
                g_audply.need_restore = FALSE ;
            }
            mmi_audply_clear_play_seconds();
            mmi_audply_play();
        }
        else
        {
            mmi_audply_restore();
        }
        return TRUE;
    }
    else if(g_audply.continue_playing)
    {
        mmi_audply_play_completed();
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_play_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("Audply: mmi_audply_play_callback_hdlr, state:%d, result:%d, restorable:%d",
                       g_audply.state,result,g_audply.restorable);

    
    /* restore to normal speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_close();
#endif 

    /* ignore it */
    if (g_audply.state != STATE_PLAY)
    {
        return;
    }

    /* handle result */
    g_audply.need_restore = FALSE;

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            g_audply.need_replay = FALSE;
            if (g_audply.in_main_screen == TRUE)
            {
                g_audply.new_play_time = g_audply.duration;
                mmi_audply_redraw_main_progressbar();
                if (!mmi_audply_does_present_list_file_exist())
                {
                    mmi_audply_init_playlist();    
                }
            }
            mmi_audply_play_completed();
            break;
        case MDI_AUDIO_TERMINATED:
            g_audply.need_replay = TRUE;
            if (g_audply.restorable)
            {
                if (mdi_audio_store_file(0) == MDI_AUDIO_SUCCESS)
                {
                    g_audply.need_restore = TRUE;
                }
            }
            mmi_audply_stopped();
            break;
    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_TIMEOUT:
            mmi_audply_display_popup(result);
            mmi_audply_do_stop_action();
        #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
            mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
        #endif
            break;
    #endif /* __DRM_SUPPORT__ */
        default:
/*            if (g_audply.repeat_mode == REPEAT_ALL && !g_audply.in_main_screen)
            {
                g_audply.need_replay = FALSE;
                mmi_audply_play_completed();
            }
            else*/
            {
                g_audply.need_replay = FALSE;
                mmi_audply_stopped();
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
                if(g_audply.in_sub_screen)
                {
                    ExecSubLCDCurrExitHandler();
		            UI_set_sub_LCD_graphics_context();
                    ClearAllKeyHandler();
                    mmi_sub_audply_popup_error_key_handler();
                    UI_set_main_LCD_graphics_context();
		}
                else
#endif    
                {
                    mmi_audply_display_popup(result);
                }
                if (g_audply.repeat_mode != REPEAT_ONE && g_audply.n_total_items > 1)
                {
                    mdi_audio_start_background_timer();
                    g_audply.continue_playing = TRUE ;
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pause_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pause_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("Audply: mmi_audply_pause_callback_hdlr, state:%d, result:%d",
                       g_audply.state,result);

    
    /* ignore it */
    if (g_audply.state != STATE_PAUSED)
    {
        return;
    }

    /* handle result */
    g_audply.need_replay = FALSE;
    g_audply.need_restore = FALSE;

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            mmi_audply_play_completed();
            break;
        case MDI_AUDIO_TERMINATED:
            mmi_audply_clear_play_seconds();
            mmi_audply_stopped();
            break;
        default:
            mmi_audply_clear_play_seconds();
            mmi_audply_stopped();
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
                if(g_audply.in_sub_screen)
                {
                    ExecSubLCDCurrExitHandler();
                    UI_set_sub_LCD_graphics_context();
                    ClearAllKeyHandler();
                    mmi_sub_audply_popup_error_key_handler();
                    UI_set_main_LCD_graphics_context();
                }
                else
#endif    
                {
                    mmi_audply_display_popup(result);
                }
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_build_cache_fail_callback_hdlr
 * DESCRIPTION
 *  when build cache fail, set to non-seekable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_build_cache_fail_callback_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("Audply: mmi_audply_build_cache_fail_callback_hdlr, state:%d",
                       g_audply.state);


    g_audply.seekable = FALSE ;
    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_seek_stop_playing();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_auto_update_duration_hdlr
 * DESCRIPTION
 *  handle auto update duration
 * PARAMETERS
 *  duration    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_auto_update_duration_hdlr(U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* when MMI changes to next/previous song but haven't played yet(press next/prev key)
      ,update dur ind might update the wrong song */
    if(!g_audply.file_name_identical)
    {
        PRINT_INFORMATION("Audply: auto duration update FAIL : file name not identical");
        return;
    }

    if(g_audply.state != STATE_IDLE && duration != 0)
    {
        g_audply.duration = duration;
        mmi_audply_determine_progress_speed();
        PRINT_INFORMATION("Audply: auto duration update SUCCESS : %d",g_audply.duration);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play_completed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_play_completed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
#endif

    /* update state */
    g_audply.state = STATE_IDLE;
    g_audply.continue_playing = FALSE ;

    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
    mmi_audply_clear_play_seconds();

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif    
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__)
        mmi_audply_calc_spectrum(FALSE);
    #endif 
    }

    if (g_audply.n_total_items == 0 && g_audply.pick_index == -1)
    {
        mmi_audply_clear_play_seconds();
        g_audply.restorable = FALSE;
        g_audply.seekable = FALSE;
        g_audply.need_to_build_cache = FALSE;
        g_audply.title[0] = 0;
        g_audply.filefullname[0] = 0;
        g_audply.buff_head = 0;
        g_audply.n_buff_items = 0;

        memset(g_audply.bitset, 0, MAX_PLAY_LIST_BYTES);
        g_audply.n_total_items = 0;
        g_audply.pick_index = -1;
        g_audply.pick_count = 0;

        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_screen();
        }
    }
    /* check if buttin is pressed down is to avoid repeating on a short file too quick and cause a result to block other commands */
    if (g_audply.in_main_screen && g_audply_main_selected_button_down &&
        (g_audply_main_selected_button == AUDPLY_MAIN_STOP ||
         g_audply_main_selected_button == AUDPLY_MAIN_PREV || g_audply_main_selected_button == AUDPLY_MAIN_NEXT))
    {
        g_mmi_audply_play_completed_after_button_down = TRUE;
    }
    else
    {
        BOOL picked_OK = FALSE;

        if (mmi_audply_pick_playlist() < 0)
        {
            mmi_audply_pick_playlist(); /* pick after play list  reset */
            if (mmi_audply_apply_picked_file())
            {
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_STOP;
                g_audply_main_selected_button_down = FALSE;
                picked_OK = TRUE;
            }
        }
        else
        {
            if (mmi_audply_apply_picked_file())
            {
                StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
                StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_play);    /* wait for 0.7 second to request play */
                g_audply.wait_next = TRUE;
                /*it is not necessary to set need_store to false here, but to make it identical, make every need_restore
                  to false after wait_next is true*/
                g_audply.need_restore = FALSE;
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_STOP;
                g_audply_main_selected_button_down = FALSE;
                picked_OK = TRUE;
            }
        }

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__
       if(g_audply.in_sub_screen)
       {
            UI_set_sub_LCD_graphics_context();
            mmi_audply_redraw_main_screen();
            UI_set_main_LCD_graphics_context();
       }
       else if(picked_OK && g_audply.in_sub_list_screen)
       {
            dynamic_list_goto_item(g_audply.pick_index);
       }
#endif    
        if (g_audply.in_main_screen)
        {
            mmi_audply_update_main_button_flag();
            mmi_audply_redraw_main_screen();
        }
        else if (picked_OK && g_audply.in_list_screen)
        {
            dynamic_list_goto_item(g_audply.pick_index);
        }
        else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
        {
        #ifdef __GDI_MEMORY_PROFILE_2__
            if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
            {
                idle_screen_show_network_details();
            }
        #else /* __GDI_MEMORY_PROFILE_2__ */ 
            RedrawCategoryFunction();
        #endif /* __GDI_MEMORY_PROFILE_2__ */ 
        }
    }

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (g_audply.in_main_screen)
    {
        mmi_audply_spectrum_display_stop();
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

/*disable lyric display*/
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif    
    {
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_stop_scroll_lyric_and_clean_screen();
        audply_lyric.is_ready = FALSE;
        lyric_parse_ok = FALSE;
        mmi_audply_lyric_check_backlight(0);
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
     }

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stopped
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stopped()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
#endif

    /* update state */
    g_audply.state = STATE_IDLE;

    if (g_audply.n_total_items > 0)
    {
	#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	    if(g_audply.in_sub_screen)
        {
		    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
        }
		else
    #endif
        {
		    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_STOP;
        }
    }
    else
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_DISABLED;
    }
    g_audply_main_selected_button_down = FALSE;

    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif    
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) /*&& defined(__MMI_SUBLCD__)*/
        mmi_audply_calc_spectrum(FALSE);
    #endif 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_stop_lyric();
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
    }

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
        UI_set_main_LCD_graphics_context();
    }
    else
#endif    
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audply_spectrum_display_stop();
    #endif 
    }
    else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
        {
            idle_screen_show_network_details();
        }
    #else /* __GDI_MEMORY_PROFILE_2__ */ 
        RedrawCategoryFunction();
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_resumed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_resumed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update state */
    g_audply.state = STATE_PLAY;

    StartTimer(AUDPLY_COUNT_PLAY_TIMER, 500, mmi_audply_timer);

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif    
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__)
        if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
        {
            mmi_audply_calc_spectrum(TRUE);
        }
    #endif /* defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__) */ 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_lyric_check_backlight(1);
    #endif 
    }

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
        UI_set_sub_LCD_graphics_context();
         mmi_sub_audply_redraw_main_toggle_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
        UI_set_main_LCD_graphics_context();
    }
    else
#endif    
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
        {
            mmi_audply_spectrum_display_start();
        }
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
    }
    else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
        {
            idle_screen_show_network_details();
        }
    #else /* __GDI_MEMORY_PROFILE_2__ */ 
        RedrawCategoryFunction();
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_paused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_paused()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update state */
    g_audply.state = STATE_PAUSED;

    mmi_audply_update_play_seconds();
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
      if(!g_audply.in_sub_screen)
#endif    
     {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) //&& defined(__MMI_SUBLCD__)
        mmi_audply_calc_spectrum(FALSE);
    #endif 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_lyric_check_backlight(0);
    #endif 
    }

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
        UI_set_sub_LCD_graphics_context();
         mmi_sub_audply_redraw_main_toggle_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
        UI_set_main_LCD_graphics_context();
    }
    else
#endif    
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audply_spectrum_display_stop();
    #endif 
    }
    else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
        {
            idle_screen_show_network_details();
        }
    #else /* __GDI_MEMORY_PROFILE_2__ */ 
        RedrawCategoryFunction();
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__

/*****************************************************************************
 * FUNCTION
 *  UCS2StrMatch
 * DESCRIPTION
 *  For lyric parse string
 * PARAMETERS
 *  strSrc              [IN]        
 *  break_chars         [IN]        
 *  matchs_count        [IN]        
 *  strMatchs           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 UCS2StrMatch(const S8 *strSrc, const S8 *break_chars, S32 matchs_count, S8 **strMatchs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset, i;
    U16 *src = (U16*) strSrc;
    S32 src_length = mmi_ucs2strlen(strSrc);
    S32 break_chars_length = mmi_ucs2strlen(break_chars);
    U16 **matchs = (U16 **) strMatchs;
    S8 *is_matching = (S8*)OslMalloc(matchs_count);
    S8 *matchs_length = (S8*)OslMalloc(matchs_count);


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < matchs_count; i++)
    {
        is_matching[i] = 1;
        matchs_length[i] = mmi_ucs2strlen(strMatchs[i]);
    }

    for (offset = 0; offset < src_length; offset++)
    {
        BOOL no_match_all = TRUE;

        for (i = 0; i < matchs_count; i++)
        {
            if (!is_matching[i])    /* not match */
            {
                continue;
            }
            no_match_all = FALSE;
            if (offset == matchs_length[i])
            {
                S32 x = 0;

                for (; x < break_chars_length; x++)
                {
                    if (src[offset] == ((U16*) break_chars)[x])
                    {
                        OslMfree(is_matching);
                        OslMfree(matchs_length);
                        return i;   /* match */
                    }
                }
                is_matching[i] = 0;
            }
            else if (matchs[i][offset] != src[offset])
            {
                is_matching[i] = 0;
            }
        }
        if (no_match_all)
        {
            OslMfree(is_matching);
            OslMfree(matchs_length);
            return -1;
        }
    }
    OslMfree(is_matching);
    OslMfree(matchs_length);
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_check_backlight
 * DESCRIPTION
 *  check if the backlight should be turned on for displaying lyric.
 *  conditions to fit : 1. under play state
 *  2. lyrics_display == 1
 *  3. lyric parse ok
 *  4. in audply main screen
 * PARAMETERS
 *  on      [IN]        Boolean to check turn on or turn off.  on:1, off:0
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lyric_check_backlight(const BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!on && lyric_backlight_has_turn_on)    /* to turn off backlight */
    {
        TurnOffBacklight();
        lyric_backlight_has_turn_on = FALSE;
    }
    else if (on && !lyric_backlight_has_turn_on)    /* to turn on backlight while displaying lyric */
    {
        if (g_audply.state == STATE_PLAY && g_audply.lyrics_display && lyric_parse_ok && g_audply.in_main_screen && g_audply_lyrics_valid)
        {
            TurnOnBacklight(0);
            lyric_backlight_has_turn_on = TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lrc_encoding_type
 * DESCRIPTION
 *  check if the lrc is an Unicode encoded file or the user specified encoded file.
 * PARAMETERS
 *  str     [IN]        Pointer to the text source.
 *  BL      [OUT]       A number to verify big or little indian
 * RETURNS
 *  a mmi_chset_enum that sprcifies UTF8/UCS2/User Specified  encoded type.
 *****************************************************************************/
mmi_chset_enum mmi_audply_lrc_encoding_type(const S8 *str, audply_UCS2_encode_enum *BL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str[0] == (S8) 0xEF && str[1] == (S8) 0xBB && str[2] == (S8) 0xBF)
    {
        *BL = NON_UCS2;
        return MMI_CHSET_UTF8;
    }
    else if (str[0] == (S8) 0xFE && str[1] == (S8) 0xFF)
    {
        *BL = UCS2_BIG_ENDIAN;
        return MMI_CHSET_UCS2;
    }
    else if (str[0] == (S8) 0xFF && str[1] == (S8) 0xFE)
    {
        *BL = UCS2_LITTLE_ENDIAN;
        return MMI_CHSET_UCS2;
    }
    else
    {
        *BL = NON_UCS2;
        return PhnsetGetDefEncodingType();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stop_lyric
 * DESCRIPTION
 *  called when audio playing is stopped
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stop_lyric()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean the scrolling screen. */
    mmi_audply_stop_scroll_lyric_and_clean_screen();
    audply_lyric.is_ready = FALSE;
    lyric_parse_ok = FALSE;
    mmi_audply_lyric_check_backlight(0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_clear_lyric_context
 * DESCRIPTION
 *  Clear all lyric context and set audply_lyric.is_ready to FALSE.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_clear_lyric_context()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_scrolling_lyric_p1)
    {
        gui_scrolling_text_stop(audply_scrolling_lyric_p1);
        audply_scrolling_lyric_p1 = NULL;
    }
    memset(g_mmi_lyric_str_buff, 0, AUDPLY_LYRIC_STR_BUFF_MAX_SIZE);
    memset(&audply_lyric, 0, sizeof(audply_lyric_struct));
    lyric_full = FALSE;
    audply_lyric.is_ready = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_post_process
 * DESCRIPTION
 *  If  the string buffer pool is not large enough, the string might ended in the middle of a
 *  lyrics line.which indicates that it is not ended in '\n' nor '\t'. the parser only takes the
 *  lyrics ended with '\n' or '\t'. this function try to take care of it.
 * PARAMETERS
 *  src             [?]         
 *  total_size      [IN]        in bytes
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lyric_post_process(S8 *src, U32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_length = 0;
    S8 *temp_src = src + total_size - 2;    /* subtract by 2 because it is 2 byte aligned. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U16* temp_src = (U16*)src + (total_size/2) -1  ; */
    if (mmi_ucs2find(temp_src, (S8*) L"\r\n", &num_length, -1) == 1)
    {
        temp_src -= num_length * 2;
        memset(temp_src + 2, 0, num_length * 2);
    }
    else
    {
        src[total_size - 1] = 0x00;
        src[total_size - 2] = '\n';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_UCS2_memcpy
 * DESCRIPTION
 *  If  the string buffer pool is not large enough, the string might ended in the middle of a
 *  lyrics line.which indicates that it is not ended in '\n' nor '\t'. the parser only takes the
 *  lyrics ended with '\n' or '\t'. this function try to take care of it.
 * PARAMETERS
 *  dest            [?]         
 *  src             [?]         
 *  total_size      [IN]        in bytes
 *  BL              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lyric_UCS2_memcpy(S8 *dest, S8 *src, U32 total_size, audply_UCS2_encode_enum BL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (BL == UCS2_LITTLE_ENDIAN)
    {
        memcpy(dest, src, total_size);
    }
    else if (BL == UCS2_BIG_ENDIAN)
    {
        U32 i;

        for (i = 0; i < total_size; i += 2)
        {
            *(dest + i) = *(src + i + 1);
            *(dest + i + 1) = *(src + i);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lrc_FS_Read_one_line
 * DESCRIPTION
 *  read a line from FS into a temp buffer
 *  1. if the buffer is not large enough : append '\n' in the end of it and seek for real '\n' in the FS
 *  2. if the buffer is larger than one line : seek for first '\n' in FS
 * IMPACT
 *  when it is successfully parsed, it'll set audply_lyric.is_ready to TRUE.
 *  otherwise, it is reset to FALSE by calling mmi_audply_clear_lyric().
 * PARAMETERS
 *  handle                  [IN]        File handle for FS
 *  temp_buf_pool           [IN]        Temp buffer bool to store the read chars from FS
 *  temp_buf_pool_size      [IN]        Max size for one line
 *  read_size               [OUT]       The real read size for one line
 *  lrc_encoding_chset      [IN]        
 *  BL                      [IN]        To indicate big or little endian
 * RETURNS
 *  return TRUE if it's successfully read; otherwise, return FALSE.
 *****************************************************************************/
BOOL mmi_audply_lrc_FS_Read_one_line(
        FS_HANDLE handle,
        S8 *temp_buf_pool,
        const U32 temp_buf_pool_size,
        U32 *read_size,
        mmi_chset_enum lrc_encoding_chset,
        audply_UCS2_encode_enum BL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_Read(handle, temp_buf_pool, temp_buf_pool_size, read_size) < 0)
    {
        return FALSE;
    }
    else if (*read_size != 0)
    {
        U32 i;
        U32 line_len;
        U32 read_over_total_line_len = 0;
        BOOL found = FALSE;

        for (i = 0; i < *read_size; i++)
        {
            if (lrc_encoding_chset == MMI_CHSET_UCS2)
            {
                if (BL == UCS2_LITTLE_ENDIAN)
                {
                    if (temp_buf_pool[i] == '\n' && temp_buf_pool[i + 1] == 0)
                    {
                        found = TRUE;
                        break;
                    }
                }
                else if (BL == UCS2_BIG_ENDIAN)
                {
                    if (temp_buf_pool[i] == 0 && temp_buf_pool[i + 1] == '\n')
                    {
                        found = TRUE;
                        break;
                    }
                }
                i++;
            }
            else
            {
                if (temp_buf_pool[i] == '\n')
                {
                    found = TRUE;
                    break;
                }
            }
        }

        if (found)
        {
            /* if found, i will not be added by for loop. */
            line_len = i + 1;
            /* make it 2 byte aligned. */
            if (lrc_encoding_chset == MMI_CHSET_UCS2)
            {
                line_len++;
            }
        }
        else
        {
            line_len = i;
        }
        /* reach the end of file */
        if ((line_len < *read_size) || (line_len == *read_size && found))
        {
            /* seek back to the end of first line */
            FS_Seek(handle, line_len - *read_size, FS_FILE_CURRENT);
            /* replace with zero value till the end of temp_buf */
            memset(temp_buf_pool + line_len, 0, *read_size - line_len);
        }
        else    /* line_len == *read_size && !found */
        {
            S8 *read_over_buf = NULL;
            const U32 read_over_buf_size = 256;
            U32 read_over_read_size;
            U32 j, read_over_line_len;
            U32 read_over_total_size = 0;

            if ((read_over_buf = OslMalloc(read_over_buf_size)) == NULL)
            {
                return FALSE;
            }
            else
            {
                memset(read_over_buf, 0, read_over_buf_size);
            }

            if(temp_buf_pool_size-line_len>=2)
            {
                line_len += 2 ;
                *read_size = line_len;
            }

            if (BL == UCS2_LITTLE_ENDIAN)
            {
                temp_buf_pool[line_len - 1] = 0;
                temp_buf_pool[line_len - 2] = '\n';

            }
            else if (BL == UCS2_BIG_ENDIAN)
            {
                temp_buf_pool[line_len - 1] = '\n';
                temp_buf_pool[line_len - 2] = 0;
            }
            else
            {
                temp_buf_pool[line_len - 2] = '\n';
                temp_buf_pool[line_len - 1] = 0;
            }

            found = FALSE;
            do
            {
                if (FS_Read(handle, read_over_buf, read_over_buf_size, &read_over_read_size) < 0)
                {
                    OslMfree(read_over_buf);
                    return FALSE;
                }

                if (!read_over_read_size)   /* end of file */
                {
                    OslMfree(read_over_buf);
                    return TRUE;
                }
                else
                {
                    for (j = 0; j < read_over_read_size; j++)
                    {
                        if (lrc_encoding_chset == MMI_CHSET_UCS2)
                        {
                            if (BL == UCS2_LITTLE_ENDIAN)
                            {
                                if (read_over_buf[j] == '\n' && read_over_buf[j + 1] == 0)
                                {
                                    found = TRUE;
                                    break;
                                }
                            }
                            else if (BL == UCS2_BIG_ENDIAN)
                            {
                                if (read_over_buf[j] == 0 && read_over_buf[j + 1] == '\n')
                                {
                                    found = TRUE;
                                    break;
                                }
                            }
                            j++;
                        }
                        else
                        {
                            if (read_over_buf[j] == '\n')
                            {
                                found = TRUE;
                                break;
                            }
                        }

                    }
                    read_over_line_len = j + 1;

                    /* make it 2 byte aligned */
                    if (lrc_encoding_chset == MMI_CHSET_UCS2)
                    {
                        read_over_line_len++;
                    }

                    read_over_total_line_len += read_over_line_len;
                    read_over_total_size += read_over_read_size;
                }
                /* haven't reach the end */
            } while (read_over_line_len >= read_over_read_size && !found);
            OslMfree(read_over_buf);
            FS_Seek(handle, read_over_total_line_len - read_over_total_size, FS_FILE_CURRENT);
        }
        *read_size = line_len;  /* + read_over_total_line_len ; */
        return TRUE;
    }
    else
    {
        return TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_lyric
 * DESCRIPTION
 *  Init and parse lyric
 * IMPACT
 *  when it is successfully parsed, it'll set audply_lyric.is_ready to TRUE.
 *  otherwise, it is reset to FALSE by calling mmi_audply_clear_lyric().
 * PARAMETERS
 *  void
 * RETURNS
 *  return TRUE if it's successfully parsed; otherwise, return FALSE.
 *****************************************************************************/
BOOL mmi_audply_init_lyric()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 str_len;
    UI_character_type *file_name_end = NULL, *temp_file_name_end = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    if( g_mmi_lyric_str_buff == NULL )
    {
        return FALSE;
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__*/

    mmi_audply_clear_lyric_context();

    mmi_ucs2cpy((PS8)audply_lyric.lyric_file_path, (const PS8)g_audply.filefullname);

    str_len = mmi_ucs2strlen((const PS8)audply_lyric.lyric_file_path);

    temp_file_name_end = audply_lyric.lyric_file_path;
    while( (temp_file_name_end = (UI_character_type*) mmi_ucs2chr((S8*) temp_file_name_end, L'.')) != NULL )
    {
        file_name_end = temp_file_name_end;
        temp_file_name_end++;
    }

    if (file_name_end)
    {
        *file_name_end = 0;
    }
    mmi_ucs2cat((PS8)audply_lyric.lyric_file_path, (const PS8)L".lrc");

    if ((handle = FS_Open((PU16) audply_lyric.lyric_file_path, FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        U32 file_size = 0;
        U32 str_size = 0;

        S8 *temp_buf_pool = NULL;
        const U32 temp_buf_pool_size = AUDPLY_LYRIC_TMP_BUFF_MAX_SIZE;   /* 128 ;//256 ; */
        U32 read_size;

        S8 *str_buf_pool = g_mmi_lyric_str_buff;    /* converted buff pool */
        S8 *temp_str_buf_pool = str_buf_pool;
        U32 buf_size = AUDPLY_LYRIC_STR_BUFF_MAX_SIZE;           /* size of converted buff pool */
        U32 temp_str_buf_size = buf_size;

        U32 total_read_size = 0;
        U32 total_str_size = 0;

        audply_UCS2_encode_enum BL = NON_UCS2;  /* when it is encoded in UCS2, use this variable to indicate Big or Little endian */

        if (FS_GetFileSize(handle, &file_size) < 0 || !file_size)
        {
            FS_Close(handle);
            return FALSE;
        }

        if ((temp_buf_pool = OslMalloc(temp_buf_pool_size)) == NULL)
        {
            FS_Close(handle);
            return FALSE;
        }
        memset(temp_buf_pool, 0, temp_buf_pool_size);

        /* to know what coding type it is */
        FS_Read(handle, temp_buf_pool, 3, &read_size);
        audply_lyric.lrc_encoding_chset = mmi_audply_lrc_encoding_type(temp_buf_pool, &BL);
        FS_Seek(handle, -3, FS_FILE_CURRENT);

        while (total_read_size < file_size && !lyric_full)
        {
            /* read one line until '\n' */
            if (mmi_audply_lrc_FS_Read_one_line
                (handle, temp_buf_pool, temp_buf_pool_size, &read_size, audply_lyric.lrc_encoding_chset, BL) == FALSE)
            {
                OslMfree((void*)temp_buf_pool);
                FS_Close(handle);
                return FALSE;
            }
            if (!read_size)
            {
                break;
            }
            // append zero if not large enough.
            //                      if(read_size<temp_buf_pool_size)
            //                              memset(temp_buf_pool+read_size,0,temp_buf_pool_size-read_size) ;

            if (audply_lyric.lrc_encoding_chset != MMI_CHSET_UCS2)
            {
                if (temp_str_buf_size >= 4) /* if size is smaller than 4 , the converter might over write the un-authorized memory space. */
                {
                    str_size = mmi_chset_convert(
                                audply_lyric.lrc_encoding_chset,
                                MMI_CHSET_UCS2,
                                temp_buf_pool,
                                temp_str_buf_pool,
                                temp_str_buf_size);
                    /* str_size -= 2 ; */
                    temp_str_buf_pool[str_size - 1] = 0;
                    temp_str_buf_pool[str_size - 2] = '\n';
                }
                if (temp_str_buf_size == str_size + 2)
                {
                    mmi_audply_lyric_post_process(str_buf_pool, buf_size);
                }

                // if need to concern about the str_buf not adequate situation, need to append '\n' ??
                //MMI_ASSERT(str_size!=0) ;
            }
            else
            {
                if (temp_str_buf_size < read_size)
                {
                    mmi_audply_lyric_UCS2_memcpy(temp_str_buf_pool, temp_buf_pool, temp_str_buf_size, BL);
                    str_size = read_size;
                    mmi_audply_lyric_post_process(str_buf_pool, buf_size);
                }
                else
                {
                    mmi_audply_lyric_UCS2_memcpy(temp_str_buf_pool, temp_buf_pool, read_size, BL);
                    str_size = read_size;
                }
            }

            if (!(mmi_audply_parse_lyric((U16*) temp_str_buf_pool)))
            {
                OslMfree((void*)temp_buf_pool);
                audply_lyric.is_ready = FALSE;
                FS_Close(handle);
                return FALSE;
            }

            /* str_buff is not adequate for the lrc file. */
            if (total_str_size + str_size > buf_size)   /* temp_str_buf_size) */
            {
                total_str_size = buf_size;
                break;
            }
            total_str_size += str_size;
            total_read_size += read_size;
            temp_str_buf_size -= str_size;
            temp_str_buf_pool += str_size;

        }

        OslMfree((void*)temp_buf_pool);

/*        if (total_str_size > buf_size)
        {
            audply_lyric.lyric_buf_pool.str_size = buf_size;
        }
        else
        {
            audply_lyric.lyric_buf_pool.str_size = total_str_size - 2;
        }

        audply_lyric.lyric_buf_pool.buf = str_buf_pool;
        audply_lyric.lyric_buf_pool.buf_size = buf_size;*/

        audply_lyric.cur_line = audply_lyric.first_line;
        audply_lyric.is_ready = TRUE;
        FS_Close(handle);
        return TRUE;

    }
    return FALSE;   /* no such .lrc exists. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_parse_lyric
 * DESCRIPTION
 *  parse current lyric string
 * PARAMETERS
 *  cur_char        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_audply_parse_lyric(U16 *cur_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audply_lyric_parse_status_enum status = LINE_START;
    S32 match_index = 0;
    S32 num_length = 0;
    S32 time_phase1, time_phase2, time_phase3, time_phaseMS;
    U32 temp_time;
    S32 temp_num, i, j;
    U16 *temp_ptrU16;
    U16 *tag_ids[5] = {L"ar", L"ti", L"al", L"by", L"offset" };

    S32 time_count_line = 0;    /* counting how many time tages for one lyric */
    S8 *line_lyric1 = NULL ;

    //      U16             line_lyric1_size;
    //      S8*             line_lyric2;
    //      U16             line_lyric2_size;
    audply_lyric_line_struct *temp_lyric = NULL;
    audply_lyric_line_struct *cur_lyric = NULL;
    audply_lyric_line_struct *pre_lyric = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cur_char)
    {
        switch (status)
        {
            case LINE_START:
                time_count_line = 0;
                line_lyric1 = NULL;
                //                      line_lyric1_size = 0;
                //                      line_lyric2 = NULL;
                //                      line_lyric2_size = 0;

                if ((cur_char = (U16*) mmi_ucs2chr((S8*) cur_char, L'[')) == NULL)
                {
                    return TRUE;
                }
                else
                {
                    status = TAG_START;
                }
                break;

            case LINE_END:
                if (line_lyric1 || time_count_line)
                {
                    if (!audply_lyric.first_line)
                    {
                        audply_lyric.first_line = &audply_lyric.lyric[0];
                        for (j = 0; j < time_count_line; j++)
                        {
                            if (audply_lyric.first_line->time > audply_lyric.lyric[j].time)
                            {
                                audply_lyric.first_line = &audply_lyric.lyric[j];
                            }
                        }
                    }
                    for (i = 0; i < time_count_line; i++)
                    {
                        temp_lyric = &audply_lyric.lyric[audply_lyric.lyric_count - i - 1];
                        temp_lyric->line_lyric1 = line_lyric1;
                        /* temp_lyric->line_lyric2 = line_lyric2; */
                        cur_lyric = audply_lyric.first_line;
                        pre_lyric = NULL;
                        while (cur_lyric)
                        {
							if(temp_lyric == cur_lyric)
							{
								break;
							}
                            if (temp_lyric->time < cur_lyric->time)
                            {
                                temp_lyric->next = cur_lyric;
                                if (pre_lyric)
                                {
                                    pre_lyric->next = temp_lyric;
                                }
                                else
                                {
                                    audply_lyric.first_line = temp_lyric;
                                }
                                break;
                            }
                            pre_lyric = cur_lyric;
                            cur_lyric = cur_lyric->next;
                            ASSERT(pre_lyric != cur_lyric);                            
                        }
                        if (!cur_lyric && temp_lyric != audply_lyric.first_line)
                        {
                            if (pre_lyric)
                            {
                                pre_lyric->next = temp_lyric;
                            }
                            else
                            {
                                audply_lyric.first_line = temp_lyric;
                            }
                        }
                    }
                }
                return TRUE;
                //                      status = LINE_START;
                //                      continue;
                break;
            case TAG_START:
                time_phase1 = 0xffffff;
                time_phase2 = 0xffffff;
                time_phase3 = 0xffffff;
                time_phaseMS = 0xffffff;

                TRIM_LEFT;
                match_index = UCS2StrMatch((S8*) cur_char, (S8*) L"[]:. \t\r\n", 5, (S8 **) tag_ids);

                if (match_index == -1)
                {
                    cur_char--;
                    status = TAG_TIME1;
                }
                else
                {
                    cur_char += mmi_ucs2strlen((S8*) tag_ids[match_index]);
                    TRIM_LEFT;
                    if (!cur_char)
                    {
                        return TRUE;
                    }
                    if (*cur_char != L':')
                    {
                        FIND_TAG_END;
                    }
                    else
                    {
                        switch (match_index)    /* { L"ar", L"ti", L"al", L"by", L"offset" } */
                        {
                            case 0:
                                status = TAG_ID_AR;
                                break;
                            case 1:
                                status = TAG_ID_TI;
                                break;
                            case 2:
                                status = TAG_ID_AL;
                                break;
                            case 3:
                                status = TAG_ID_BY;
                                break;
                            case 4:
                                status = TAG_ID_OFFSET;
                                break;
                        }
                    }
                }
                break;

            case TAG_END:
                temp_time = 0xffffff;
                if (time_phase1 != 0xffffff && time_phase2 != 0xffffff && time_phase3 != 0xffffff)
                {
                    temp_time = time_phase1 * 3600 + time_phase2 * 60 + time_phase3;
                }
                else if (time_phase1 != 0xffffff && time_phase2 != 0xffffff)
                {
                    temp_time = time_phase1 * 60 + time_phase2;
                }
                else if (time_phase1 != 0xffffff)
                {
                    temp_time = time_phase1;
                }

                if(temp_time != 0xffffff)
                {
                    temp_time *= 1000 ;
                    if (time_phaseMS != 0xffffff)
                    {
                        temp_time += time_phaseMS ;                                            
                    }
                }
                else
                {
                    if (time_phaseMS != 0xffffff)
                    {
                        temp_time = time_phaseMS ;
                     }
                }
                
                if (temp_time != 0xffffff)
                {
                    /* handle more than one time tags for one lyric */
                    temp_lyric = &audply_lyric.lyric[audply_lyric.lyric_count++];
                    time_count_line++;
                    temp_lyric->next = NULL;
                    temp_lyric->time = temp_time;
                    if (audply_lyric.lyric_count == AUDPLY_LYRIC_MAX_LINE_COUNT)
                    {
                        lyric_full = TRUE;
                        return TRUE;
                    }
                }

                cur_char = (U16*) mmi_ucs2trim_left((S8*) cur_char, (S8*) L" \t");
                if (!cur_char)
                {
                    return TRUE;
                }
                if (*cur_char == L'[')
                {
                    status = TAG_START;
                }
                else if (*cur_char == L'\r' || *cur_char == L'\n')
                {
                    status = LINE_END;
                }
                else
                {
                    status = TAG_LYRIC1;
                    continue;
                }
                break;

            case TAG_LYRIC1:
                if (mmi_ucs2find((S8*) cur_char, (S8*) L"\r\n", &num_length, 1) == -1)
                {
                    return FALSE;
                }
                line_lyric1 = (S8*) cur_char;
                cur_char += num_length;
                /*       if (*cur_char == L'`')
                   {
                   status = TAG_LYRIC2;
                   continue;
                   } */
                if (*cur_char == L'\r' || *cur_char == L'\n')
                {
                    status = LINE_END;
                }
                *cur_char = 0;
                break;

                /*
                 * case TAG_LYRIC2:
                 * if (mmi_ucs2find((S8*)cur_char,(S8*)L"\r\n", &num_length, 1) == -1)
                 * {
                 * return FALSE;
                 * }
                 * line_lyric2 = (S8*)cur_char;
                 * cur_char += num_length;
                 * status = LINE_END;
                 * *cur_char = 0;
                 * break;
                 */
            case TAG_TIME1:
                TRIM_LEFT;
                if (mmi_ucs2toi((S8*) cur_char, &time_phase1, &num_length) >= 0 &&
                    time_phase1 >= 0 && time_phase1 <= 60)
                {
                    cur_char += num_length;
                    TRIM_LEFT;
                    if (*cur_char == L':')
                    {
                        status = TAG_TIME2;
                    }
                    else if (*cur_char == L'.')
                    {
                        status = TAG_MS;
                    }
                    else
                    {
                        FIND_TAG_END;
                    }
                }
                else
                {
                    time_phase1 = 0xffffff;
                    FIND_TAG_END;
                }
                break;

            case TAG_TIME2:
                TRIM_LEFT;
                if (mmi_ucs2toi((S8*) cur_char, &time_phase2, &num_length) >= 0 &&
                    time_phase2 >= 0 && time_phase2 <= 60)
                {
                    cur_char += num_length;
                    TRIM_LEFT;
                    if (*cur_char == L':')
                    {
                        status = TAG_TIME3;
                    }
                    else if (*cur_char == L'.')
                    {
                        status = TAG_MS;
                    }
                    else
                    {
                        FIND_TAG_END;
                    }
                }
                else
                {
                    time_phase2 = 0xffffff;
                    FIND_TAG_END;
                }
                break;

            case TAG_TIME3:
                TRIM_LEFT;
                if (mmi_ucs2toi((S8*) cur_char, &time_phase3, &num_length) >= 0 &&
                    time_phase3 >= 0 && time_phase3 <= 60)
                {
                    cur_char += num_length;
                    TRIM_LEFT;
                    if (*cur_char == L'.')
                    {
                        status = TAG_MS;
                    }
                    else
                    {
                        FIND_TAG_END;
                    }
                }
                else
                {
                    time_phase3 = 0xffffff;
                    FIND_TAG_END;
                }
                break;

            case TAG_MS:
                TRIM_LEFT;
                if (mmi_ucs2toi((S8*) cur_char, &time_phaseMS, &num_length) >= 0 &&
                      time_phaseMS >= 0 && time_phaseMS < 1000)
                {
                    if(time_phaseMS>0 && time_phaseMS < 10)
                    {
                        time_phaseMS *= 100 ;
                    }
                    else if(time_phaseMS>=10 && time_phaseMS < 100)
                    {
                        time_phaseMS *= 10 ;
                    }
                }
                else
                {
                    time_phaseMS = 0xffffff;
                }
                FIND_TAG_END;
                break;
            case TAG_ID_AR:
                if ((temp_ptrU16 = (U16*) mmi_ucs2chr((S8*) cur_char, L']')) == NULL)
                {
                    return TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_ARTIST_LEN + 1)
                   {
                   mmi_ucs2ncpy((S8*)audply_lyric.lyric_tag_id.artist,(S8*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_TI:
                if ((temp_ptrU16 = (U16*) mmi_ucs2chr((S8*) cur_char, L']')) == NULL)
                {
                    return TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_TITLE_LEN + 1)
                   {
                   mmi_ucs2ncpy((S8*)audply_lyric.lyric_tag_id.title,(S8*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_AL:
                if ((temp_ptrU16 = (U16*) mmi_ucs2chr((S8*) cur_char, L']')) == NULL)
                {
                    return TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_ALBUM_LEN + 1)
                   {
                   mmi_ucs2ncpy((S8*)audply_lyric.lyric_tag_id.album,(S8*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_BY:
                if ((temp_ptrU16 = (U16*) mmi_ucs2chr((S8*) cur_char, L']')) == NULL)
                {
                    return TRUE;
                }
                /* if (temp_ptrU16 - cur_char <= MAX_ID3_GENRE_LEN + 1)
                   {
                   mmi_ucs2ncpy((S8*)audply_lyric.lyric_tag_id.genre,(S8*)cur_char,
                   temp_ptrU16 - cur_char );
                   } */
                FIND_TAG_END;
                break;

            case TAG_ID_OFFSET:
                TRIM_LEFT;
                if (mmi_ucs2toi((S8*) cur_char, &temp_num, &num_length) >= 0)
                {
                    audply_lyric.offset_time = temp_num;
                }
                FIND_TAG_END;
                break;

            default:
                break;
        }   /* End switch */

        cur_char++;
    }   /* End whlie */
    return TRUE;
}

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_played
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_played()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    //if(!g_audply.in_sub_screen && IsClamClose())
    if(IsSubLCDInMasterMode() == MMI_FALSE && IsClamClose())
    {
        /*
         * If the clam is closed and then resume the background play,
         * we need to entry master mode again.
         */
        EntrySubLCDMasterFromIdle();        
    }
#endif
    
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif    
    {
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        /* re-inialize the lyric. */
        lyric_parse_ok = mmi_audply_init_lyric();
        if(lyric_parse_ok)
        {
     	    PRINT_INFORMATION("audply_Lyrics: Lyrics Parse Success");
        }else
        {
    	    PRINT_INFORMATION("audply_Lyrics: Lyrics Parse Fail");
        }
        /* re-direct the target_layer, cause init_lyric will clean it to 0 ; */
    #ifdef __GDI_MEMORY_PROFILE_2__
        audply_lyric_print.target_layer = audply_osd_layer;
    #endif /*__GDI_MEMORY_PROFILE_2__*/
        lyric_reEntry = TRUE ;
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
     }

    /* update state */
    g_audply.state = STATE_PLAY;

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif 
    { 
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__    
        if(g_audply.lyrics_display && g_audply.in_main_screen && g_audply_lyrics_valid)
        {
              mmi_audply_lyric_on_time();
        }
    #endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/
    }
    StartTimer(AUDPLY_COUNT_PLAY_TIMER, 500, mmi_audply_timer);

    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;      /* for prev, next button */
    g_audply_main_selected_button_down = FALSE;

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(!g_audply.in_sub_screen)
#endif    
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__)
        /* this turn on spetrcm action is especially for subLCD, in case it is not in main screen so did not turn on for sub*/
        if (!mmi_gpio_is_lcd_sleep())
        {
            if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
            {
                mmi_audply_calc_spectrum(TRUE);
            }
        }
    #endif /* defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__) */ 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_lyric_check_backlight(1);
    #endif 
   }

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__
    if(g_audply.in_sub_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_sub_audply_redraw_main_toggle_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
        UI_set_main_LCD_graphics_context();
    }
    else
#endif  
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (!mmi_gpio_is_lcd_sleep())
        {
            if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
            {
                mmi_audply_spectrum_display_start();
            }
        }
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
    }
    else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
        {
            idle_screen_show_network_details();
        }
    #else /* __GDI_MEMORY_PROFILE_2__ */ 
        RedrawCategoryFunction();
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_msdc_plug_in_hdlr
 * DESCRIPTION
 *  handle CARD plug-in event
 * PARAMETERS
 *  has_popup       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_msdc_plug_in_hdlr(BOOL has_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_audply_init_done)
    {
        if (g_audply.preferred_list == (U8)MMI_CARD_DRV && g_audply.present_list == (U8)MMI_PUBLIC_DRV)
        {
            /* switch present list to CARD */
            PRINT_INFORMATION("Audply | Debug: card plug-in & set present list as card!");
            g_audply.present_list = (U8)MMI_CARD_DRV;
            if (g_audply.list_auto_gen)
            {
                need_refresh_list = TRUE;
            }
            else
            {
                need_reload_list = TRUE;
            }
            /* check again, when plug in memory card in setting screen. */
            if (no_card_in_slot)
            {
                no_card_in_slot = FALSE;
            }

            mmi_audply_stop_playing();

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_msdc_plug_out_hdlr
 * DESCRIPTION
 *  handle CARD plug-out event
 * PARAMETERS
 *  has_popup       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_msdc_plug_out_hdlr(BOOL has_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_audply_init_done)
    {
        if (g_audply.preferred_list == (U8)MMI_CARD_DRV && g_audply.present_list == (U8)MMI_CARD_DRV)
        {
            /* switch present list to PHONE */
            PRINT_INFORMATION("Audply | Debug: card plug-out & set present list as phone!");
            g_audply.present_list = (U8)MMI_PUBLIC_DRV;
            need_reload_list = TRUE;

/*            if (g_audply.list_auto_gen)
            {
                if (need_refresh_list && !(AUDIO_PLAYER_BASE < GetCurrScrnId() && AUDIO_PLAYER_BASE_MAX > GetCurrScrnId()))
                {
                    need_refresh_list = FALSE;
                }
                else
                {
                    PRINT_INFORMATION("Audply | Debug: need reload list!!!");
                    need_reload_list = TRUE;
                }
            }
            else
            {
                PRINT_INFORMATION("Audply | Debug: need reload list!!!");
                need_reload_list = TRUE;
            }
*/

            /* check again, when plug out memory card in setting screen. */
            if (g_audply.preferred_list == MMI_CARD_DRV &&
               !g_audply.list_auto_gen &&
                FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < 0)
            {
                no_card_in_slot = TRUE;
            }

            mmi_audply_refresh_cache(FALSE);

           /* if (g_audply.in_main_screen)
            {
                PRINT_INFORMATION("Audply | Debug: card plug-out & in main screen, auto gen = %d", g_audply.list_auto_gen);
                mmi_audply_regen_and_reload_playlist((BOOL)g_audply.list_auto_gen, TRUE);
            }*/
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_play_activated
 * DESCRIPTION
 *  indicate whether will audio player (or single song) play or attempt to play song soon
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_is_play_activated()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return single_play_state == STATE_PLAY || g_audply.state == STATE_PLAY || g_audply.wait_next;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_playing
 * DESCRIPTION
 *  indicate whether will audio player is playing a song
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_mmi_audply_init_done && (g_audply.state == STATE_PLAY || g_audply.wait_next));
}

#endif /* __MMI_AUDIO_PLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_err_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_audply_err_str(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_PROHIBIT:
        case MDI_AUDIO_DRM_TIMEOUT:
            return STR_GLOBAL_DRM_PROHIBITED;
    #endif /* __DRM_SUPPORT__ */ 
        case MDI_AUDIO_BUSY:
            return STR_ID_AUDPLY_DEVICE_BUSY;
        case MDI_AUDIO_DISC_FULL:
            return STR_ID_AUDPLY_LIST_FULL;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            return STR_ID_AUDPLY_OPEN_FILE_ERROR;
        case MDI_AUDIO_BAD_FORMAT:
            return STR_ID_AUDPLY_BAD_FORMAT;
        case MDI_AUDIO_INVALID_FORMAT:
            return STR_ID_AUDPLY_INVALID_FORMAT;
        case MDI_AUDIO_UNSUPPORTED_CHANNEL:
            return STR_ID_AUDPLY_UNSUPPORTED_CHANNEL;
        case MDI_AUDIO_UNSUPPORTED_FREQ:
            return STR_ID_AUDPLY_UNSUPPORTED_FREQ;
        case MDI_AUDIO_UNSUPPORTED_TYPE:
            return STR_ID_AUDPLY_UNSUPPORTED_TYPE;
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
            return STR_ID_AUDPLY_ERROR;
        case MDI_AUDIO_NO_SPACE:
            return STR_ID_AUDPLY_NO_SPACE;
        case MDI_AUDIO_UNSUPPORTED_SPEED:
            return STR_ID_AUDPLY_UNSUPPORTED_SPEED;
        case MDI_AUDIO_MP4_NO_AUDIO_TRACK:
            return STR_ID_AUDPLY_NO_AUDIO_TRACK;
        case MDI_AUDIO_DECODER_NOT_SUPPORT:
            return STR_ID_AUDPLY_DECODER_NOT_SUPPORT;
        default:
            return STR_ID_AUDPLY_COMMAND_ERROR;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_err_img_tone
 * DESCRIPTION
 *  retun True: Error img/tone, False: Warning img/tone
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_err_img_tone(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ErrorImgTone;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_PROHIBIT:
        case MDI_AUDIO_DRM_TIMEOUT:
    #endif /* __DRM_SUPPORT__ */ 
        case MDI_AUDIO_BUSY:
        case MDI_AUDIO_DISC_FULL:
        case MDI_AUDIO_NO_SPACE:
            ErrorImgTone = FALSE ;
            break;
            
        case MDI_AUDIO_OPEN_FILE_FAIL:
        case MDI_AUDIO_BAD_FORMAT:
        case MDI_AUDIO_INVALID_FORMAT:
        case MDI_AUDIO_UNSUPPORTED_CHANNEL:
        case MDI_AUDIO_UNSUPPORTED_FREQ:
        case MDI_AUDIO_UNSUPPORTED_TYPE:
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
        case MDI_AUDIO_UNSUPPORTED_SPEED:
        case MDI_AUDIO_MP4_NO_AUDIO_TRACK:
        case MDI_AUDIO_DECODER_NOT_SUPPORT:
            ErrorImgTone = TRUE;
            break;
        default:
            ErrorImgTone = TRUE;
            break;
    }

    return ErrorImgTone ;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_single_play_action_in_meldoy_composer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname        [IN]        
 *  mdi_result result(?)
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_do_single_play_action_in_meldoy_composer(UI_string_type filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_play_file_with_vol_path(
                filefullname,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL,
                mmi_audply_single_play_callback_hdlr,
                single_volume,
                MDI_DEVICE_SPEAKER2);

    single_play_duration = 0;
    if (result == MDI_AUDIO_SUCCESS)
    {
        single_play_state = STATE_PLAY;
        kal_get_time(&single_play_time);
        StartTimer(AUDPLY_SINGLE_PLAY_TIMER, 500, mmi_audply_single_play_timer);
    }
    else
    {
        single_play_state = STATE_IDLE;
    }

    return (S32) result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_single_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname        [IN]        
 *  mdi_result result(?)
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_do_single_play_action(UI_string_type filefullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_play_file_with_vol_path(
                filefullname,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL,
                mmi_audply_single_play_callback_hdlr,
                single_volume,
                MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    single_play_duration = 0;
    if (result == MDI_AUDIO_SUCCESS)
    {
        single_play_state = STATE_PLAY;
        kal_get_time(&single_play_time);
        StartTimer(AUDPLY_SINGLE_PLAY_TIMER, 500, mmi_audply_single_play_timer);
    }
    else
    {
        single_play_state = STATE_IDLE;
    }

    return (S32) result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_single_stop_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_single_stop_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    single_play_state = STATE_IDLE;
    mdi_audio_stop_file();
    StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_play_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_play_state == STATE_IDLE)
    {
        return;
    }

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            single_play_state = STATE_IDLE;
            if (in_single_play_screen)
            {
                GoBackHistory();
            }
            else
            {
                //DeleteNScrId(SCR_ID_AUDPLY_PLAY_ANIMATION); /* under popup screen */
                DeleteScreenIfPresent(SCR_ID_AUDPLY_PLAY_ANIMATION); /* under popup screen */
            }
            break;
        case MDI_AUDIO_TERMINATED:
            single_play_state = STATE_IDLE;
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            if (in_single_play_screen)
            {
                GoBackHistory();
            }
            else
            {
                //DeleteNScrId(SCR_ID_AUDPLY_PLAY_ANIMATION); /* under popup screen */
                DeleteScreenIfPresent(SCR_ID_AUDPLY_PLAY_ANIMATION); /* under popup screen */
            }
            break;
    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_TIMEOUT:
            single_play_state = STATE_IDLE;
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            mmi_audply_do_single_stop_action();
            mmi_audply_display_popup(result);
            //DeleteNScrId(SCR_ID_AUDPLY_PLAY_ANIMATION);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_PLAY_ANIMATION); /* under popup screen */
            break;
    #endif /* __DRM_SUPPORT__ */
        default:
            single_play_state = STATE_IDLE;
            StopTimer(AUDPLY_SINGLE_PLAY_TIMER);
            mmi_audply_display_popup(result);
            //DeleteNScrId(SCR_ID_AUDPLY_PLAY_ANIMATION);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_PLAY_ANIMATION); /* under popup screen */
            break;
    }
}


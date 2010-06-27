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
*  FMRadioMsgHdlr.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio message handling program
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
 * Remove MMI_ON_WIN32 and MMI_ON_HARDWARE_P
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
 * multiple access mechanism.
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_FM_RADIO__
#include "CommonScreens.h"

#include "aud_defs.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#include "SettingProfile.h"


#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"

#if defined(__MMI_FM_RADIO_RECORD__)
#if defined(__DRM_SUPPORT__)
#include "Drm_gprot.h"
#endif /* defined(__DRM_SUPPORT__) */ 
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if defined(__MERCURY_MASTER__)
#include "MTPNP_AD_master_header.h"
#endif  /* __MERCURY_MASTER__ */

#if defined(FM_RADIO_WITH_TV)
static void (*search_all_channels_callback_func)(U16* signal_band);
#else
static void (*search_all_channels_callback_func) (U8 *signal_band);
#endif

typedef struct
{
    U16 freq;
    U16 stop_freq;
    BOOL is_step_up;
} mmi_fmrdo_search_one_struct;

typedef struct
{
    U16 get_signal_count;
    U8 sub_band_mask[FM_SUB_BAND_NUM / 8 + 1];
	#if defined(FM_RADIO_WITH_TV)
	U16 signal_band[FM_BANDWIDTH+1];
	#else
    U8 signal_band[FM_BANDWIDTH + 1];
	#endif
    U8 select_count;
} mmi_fmrdo_search_all_struct;

static mmi_fmrdo_search_all_struct fmrdo_search_all;
static mmi_fmrdo_search_one_struct fmrdo_search_one;
static U16 g_fmrdo_search_cancel_count = 0;

extern mmi_fmrdo_struct g_fmrdo;    /* defined in FMRadioSrc.c */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_continued
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_fmrdo_continued(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_preempted)
    {
        mmi_fmrdo_power_on(TRUE);
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
        if (g_fmrdo.in_subLCD_main_screen)
        {
            UI_set_sub_LCD_graphics_context();
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, FALSE, g_fmrdo.is_power_on, TRUE);
            UI_set_main_LCD_graphics_context();
            if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
            {
                g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                g_fmrdo.is_button_down = FALSE;
            }
            else if (mmi_fmrdo_is_stepping_up() || mmi_fmrdo_is_stepping_down())
            {
                mdi_fmr_mute(1);    /* mute in the begining of step down/up */
            }
            return TRUE;
        }
        #endif 
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, FALSE, g_fmrdo.is_power_on, TRUE);
            if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
            {
                g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                g_fmrdo.is_button_down = FALSE;
            }
            else if (mmi_fmrdo_is_stepping_up() || mmi_fmrdo_is_stepping_down())
            {
                mdi_fmr_mute(1);    /* mute in the begining of step down/up */
            }
        }
        else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
        {
            RedrawCategoryFunction();
        }

        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_preempted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_preempted(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_NOT_READY)
    {
        return;
    }

#if defined(__MMI_FM_RADIO_RECORD__)
    /* Stop FM radio recording, but do not stop playing */
    if ((g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE) &&
        result == MDI_AUDIO_STOP_FM_RECORD)
    {
        /* Display enter file name screen */
        mmi_fmrdo_record_stopped_hdlr();

        g_fmrdo.state = FMRDO_STATE_READY;

        return;
    }
    /* Stop FM radio recording, then stop FM radio */
    else if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        g_fmrdo.state = FMRDO_STATE_READY;
        /* Save file using default name */

        mmi_fmrdo_entry_restore_main_screen();

        /* record not finish correctly, show the error, and remain FM radio playing */
        if (result != MDI_AUDIO_TERMINATED)
        {
            mmi_fmrdo_record_error_hdlr(result);
            return;
        }
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    /* Stop FM Playing */
    mmi_fmrdo_search_frequency_stop();
    mmi_fmrdo_search_all_channels_stop();
    g_fmrdo.is_power_on = FALSE;
    g_fmrdo.is_preempted = TRUE;
    g_fmrdo.state = FMRDO_STATE_NOT_READY;
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
     if (g_fmrdo.in_subLCD_main_screen)   
    {
        /* update freqency text color */
        
        UI_set_sub_LCD_graphics_context();
        mmi_fmrdo_sub_redraw_frequency(g_fmrdo.frequency, TRUE);
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, FALSE, FALSE, TRUE);
        UI_set_main_LCD_graphics_context();
    
                
        if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
        {
            g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            g_fmrdo.is_button_down = FALSE;
        }
        return;
    }
                   
    #endif
    if (g_fmrdo.in_main_screen)
    {
        /* update freqency text color */
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, FALSE, FALSE, TRUE);
        if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
        {
            g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            g_fmrdo.is_button_down = FALSE;
        }
    }
    else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
    {
        RedrawCategoryFunction();
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
 *  mmi_fmrdo_goto_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_goto_channel(U16 channel_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = g_fmrdo.channel_list.freq[channel_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.frequency = freq;
    g_fmrdo.channel_index = channel_index;

    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_frequency(freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(freq);
        mmi_fmrdo_redraw_main_channel_name(0);
    }
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(g_fmrdo.in_subLCD_main_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_fmrdo_sub_redraw_frequency(freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(freq);
        mmi_fmrdo_redraw_main_channel_name(0);
        UI_set_main_LCD_graphics_context();
        if (g_fmrdo.is_power_on)
      {
        mdi_fmr_set_freq(freq);
      }
      return;
     }
    #endif

    if (g_fmrdo.is_power_on)
    {
      	mdi_fmr_mute(0);//ghw111
        mdi_fmr_set_freq(freq);
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
 *  mmi_fmrdo_set_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_frequency(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 channel_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.frequency = freq;
    if ((channel_index = mmi_fmrdo_match_channel_list(freq)) >= 0)
    {
        g_fmrdo.channel_index = channel_index;
    }
    else
    {
        g_fmrdo.channel_index = -1;
    }

    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_frequency(freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(freq);
        mmi_fmrdo_redraw_main_channel_name(0);
    }
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(g_fmrdo.in_subLCD_main_screen)
    {
        UI_set_sub_LCD_graphics_context();
        mmi_fmrdo_sub_redraw_frequency(freq, TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(freq);
        mmi_fmrdo_redraw_main_channel_name(0);
        UI_set_main_LCD_graphics_context();
         if (g_fmrdo.is_power_on)
       {
        mdi_fmr_set_freq(freq);
       }
       return;
     }
    #endif

    if (g_fmrdo.is_power_on)
    {
        mdi_fmr_set_freq(freq);
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
 *  mmi_fmrdo_power_on_before_preset_auto_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on_before_preset_auto_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.is_preempted = FALSE;

    if (!mdi_check_device_ownership())
    {
        g_fmrdo.is_power_on = FALSE;
    }
    else
    {
        /* mute it before searching */
        mdi_audio_set_mute(AUD_VOLUME_FMR, TRUE);
    #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
        if(g_fmrdo.loud_speaker_on)
        {
            mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, (mdi_callback) mmi_fmrdo_preempted);            
        }
        else
    #endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */
        {
            mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, (mdi_callback) mmi_fmrdo_preempted);
        }
        g_fmrdo.is_power_on = TRUE;
        g_fmrdo.state = FMRDO_STATE_READY;
    }
}



#ifdef FM_RADIO_WITH_TV
extern void AnalogTV_PowerOff_Close_I2C_Leakage(void) ;
#endif

extern MDI_RESULT mdi_video_rec_power_off(void) ;
extern void power_off_isp_leakage(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on(BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_ready)
    {
        return;
    }

    if ((g_fmrdo.state == FMRDO_STATE_NOT_READY && !turn_on) || (g_fmrdo.state != FMRDO_STATE_NOT_READY && turn_on))
    {
        g_fmrdo.is_preempted = FALSE;
        return;
    }

    if (turn_on)
    {
        if (!mdi_check_device_ownership())
        {
            g_fmrdo.is_power_on = FALSE;
        }
        else
        {
		/* 2009.08.13 added by hongzhe.liu + */
		DisplayPopup((U8*) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, TRUE, 15000, 0 /*No tone SUCCESS_TONE*/);
		/* 2009.08.13 added by hongzhe.liu - */
            mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmrdo.volume);
        #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
            if(g_fmrdo.loud_speaker_on)
            {
                mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, (mdi_callback) mmi_fmrdo_preempted);            
            }
            else
        #endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */
            {
                mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, (mdi_callback) mmi_fmrdo_preempted);
            }
            mdi_fmr_set_freq(g_fmrdo.frequency);
            g_fmrdo.state = FMRDO_STATE_READY;
            g_fmrdo.is_power_on = TRUE;

		/* 2009.08.13 added by hongzhe.liu + */
		ExitDisplayPopup();
		GoBackHistory();
		/* 2009.08.13 added by hongzhe.liu - */
        }
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__   
        if(g_fmrdo.in_subLCD_main_screen)
        {
            UI_set_sub_LCD_graphics_context();
            mmi_fmrdo_sub_redraw_frequency(g_fmrdo.frequency, TRUE);
            UI_set_main_LCD_graphics_context();
            g_fmrdo.is_preempted = FALSE;
                
        }
        if(IsSubLCDInMasterMode())
        {
            if (g_idle_context.IsOnIdleScreen) /* update idle screen */
            {
            #ifdef __GDI_MEMORY_PROFILE_2__
            #if !defined(__MMI_DUAL_SIM_MASTER__)
            if (mmi_bootup_is_sim_valid() == MMI_TRUE)
            #else   /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_bootup_is_sim_valid() == MMI_TRUE || !MTPNP_PFAL_Is_Card2Absent())
            #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                idle_screen_show_network_details();
            }
            #else /* __GDI_MEMORY_PROFILE_2__ */ 
                RedrawCategoryFunction();
            #endif /* __GDI_MEMORY_PROFILE_2__ */ 
            }

            return;
         }
        #endif
    
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
        #ifdef __MMI_FM_RADIO_ANIMATION__
            mmi_fmrdo_animation_start();
        #endif 
        }
    }
    else
    {
        mdi_audio_stop_fmr();
    #ifdef __MMI_FM_RADIO_ANIMATION__
        mmi_fmrdo_animation_stop();
    #endif 

	#if 0
	def FM_RADIO_WITH_TV
	// 解决从FM 出来后漏电问题    
	//Huyanwei Add It 
	power_off_isp_leakage();
	
#if defined(NOKE_DEBUG)	
	noke_dbg_printf("\r\n FM  AnalogTV_PowerOff_Close_I2C_Leakage)\r\n");
#endif
	AnalogTV_PowerOff_Close_I2C_Leakage();
	#endif	
    }


    g_fmrdo.is_preempted = FALSE;
    #ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(IsSubLCDInMasterMode())
    {
        if (g_idle_context.IsOnIdleScreen) /* update idle screen */
		{
    #ifdef __GDI_MEMORY_PROFILE_2__
    #if !defined(__MMI_DUAL_SIM_MASTER__)
        if (mmi_bootup_is_sim_valid() == MMI_TRUE)
    #else   /* __MMI_DUAL_SIM_MASTER__ */
        if (mmi_bootup_is_sim_valid() == MMI_TRUE || !MTPNP_PFAL_Is_Card2Absent())
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        {            
            idle_screen_show_network_details();
        }
        #else /* __GDI_MEMORY_PROFILE_2__ */ 
            RedrawCategoryFunction();
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }
        }
    #endif

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_frequency_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_freq      [IN]        
 *  is_step_up      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_frequency_start(U16 start_freq, BOOL is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not let voice go out while searching */
#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_bt_hfp_turn_off();
#endif
    /* mute it before searching */
    mdi_audio_set_mute(AUD_VOLUME_FMR, TRUE);

    mdi_fmr_evaluate_threshold();

    fmrdo_search_one.freq = start_freq;
    if (is_step_up)
    {
        if (start_freq > MIN_FM_FREQUENCY)
        {
            fmrdo_search_one.stop_freq = start_freq - 1;
        }
        else
        {
            start_freq = MAX_FM_FREQUENCY;
        }
    }
    else
    {
        if (start_freq < MAX_FM_FREQUENCY)
        {
            fmrdo_search_one.stop_freq = start_freq + 1;
        }
        else
        {
            start_freq = MIN_FM_FREQUENCY;
        }
    }
    fmrdo_search_one.is_step_up = is_step_up;
    g_fmrdo.state = FMRDO_STATE_SEARCH_ONE;

    /* start valid stop test */
    mdi_fmr_check_is_valid_stop(start_freq, is_step_up, mmi_fmrdo_search_frequency);

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_valid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_frequency(BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo_search_cancel_count > 0)
    {
        g_fmrdo_search_cancel_count--;
        return;
    }

    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }

    if (!is_valid && fmrdo_search_one.freq != fmrdo_search_one.stop_freq)
    {
        /* update frequency */
        if (fmrdo_search_one.is_step_up)
        {
            if (fmrdo_search_one.freq < MAX_FM_FREQUENCY)
            {
                fmrdo_search_one.freq++;
            }
            else
            {
                fmrdo_search_one.freq = MIN_FM_FREQUENCY;
            }
        }
        else
        {
            if (fmrdo_search_one.freq > MIN_FM_FREQUENCY)
            {
                fmrdo_search_one.freq--;
            }
            else
            {
                fmrdo_search_one.freq = MAX_FM_FREQUENCY;
            }
        }

        /* update display */
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_frequency(fmrdo_search_one.freq, TRUE);
            mmi_fmrdo_redraw_main_channel_tuner(fmrdo_search_one.freq);
        }
         #ifdef __MMI_FM_RADIO_ON_SUBLCD__
        if(g_fmrdo.in_subLCD_main_screen)
        {
            UI_set_sub_LCD_graphics_context();
            mmi_fmrdo_sub_redraw_frequency(fmrdo_search_one.freq, TRUE);
            mmi_fmrdo_redraw_main_channel_tuner(fmrdo_search_one.freq);
            UI_set_main_LCD_graphics_context();
        }
        #endif

        /* test valid stop again */
        mdi_fmr_check_is_valid_stop(fmrdo_search_one.freq, fmrdo_search_one.is_step_up, mmi_fmrdo_search_frequency);
    }
    else
    {
        /* don't move this statement below mmi_fmrdo_set_frequency for properly updating subLCD */
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_set_frequency(fmrdo_search_one.freq);
        /* Resume bluetooth volume if SCO connected*/
    #if defined(__MMI_BT_FM_VIA_SCO__)
        mdi_audio_bt_hfp_turn_on();
    #endif         
        mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmrdo.volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_frequency_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_frequency_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_ready && g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        g_fmrdo_search_cancel_count++;
        //mdi_fmr_cancel_checking_is_valid_stop();
        /* don't move this statement below mmi_fmrdo_set_frequency for properly updating subLCD */
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_set_frequency(fmrdo_search_one.freq);
        /* Resume bluetooth volume if SCO connected*/
    #if defined(__MMI_BT_FM_VIA_SCO__)
        mdi_audio_bt_hfp_turn_on();
    #endif        
        mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmrdo.volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_find_best_frequency_in_sub_band
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sub_band        [?]     
 * RETURNS
 *  
 *****************************************************************************/
#if defined(FM_RADIO_WITH_TV)
S16 mmi_fmrdo_find_best_frequency_in_sub_band( U16* sub_band )
#else
S16 mmi_fmrdo_find_best_frequency_in_sub_band(U8 *sub_band)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(FM_RADIO_WITH_TV)
    U16 signal_level;
    U16 max_signal_level = 1;
    #else
    U8 signal_level;
    U8 max_signal_level = 1;
    #endif
    S16 i;
    S16 index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < FM_SUB_BANDWIDTH; i++)
    {
        if (!FM_SIG_MARK(sub_band[i]))
        {
            signal_level = FM_SIG_LVL(sub_band[i]);
            if (signal_level >= max_signal_level)
            {
                index = i;
                max_signal_level = signal_level;
            }
        }
    }

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_channels_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(FM_RADIO_WITH_TV)
void mmi_fmrdo_search_all_channels_start( void (*callback_func)(U16* signal_band) )
#else
void mmi_fmrdo_search_all_channels_start(void (*callback_func) (U8 *signal_band))
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not let voice go out while searching */
#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_bt_hfp_turn_off();
#endif

    /* mute it before searching */
    mdi_audio_set_mute(AUD_VOLUME_FMR, TRUE);

    mdi_fmr_evaluate_threshold();

    search_all_channels_callback_func = callback_func;
    g_fmrdo.state = FMRDO_STATE_SEARCH_ALL;

    /* init search_p */
    memset(&fmrdo_search_all, 0, sizeof(mmi_fmrdo_search_all_struct));

    /* populate signal band */
    mdi_fmr_get_signal_level(MIN_FM_FREQUENCY, 1, mmi_fmrdo_search_all_channels);

#ifdef __MMI_SUBLCD__
    if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
    {
        ShowIdleAppSubLcd();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_channels
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal_level        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

//hongzhe.liu add
#if 0
int fm_signal[FM_BANDWIDTH+1]={	35,40,75,32,65,78,120,230,12,66,
								35,40,75,32,65,78,120,230,12,66,
								35,40,75,32,65,78,120,230,12,66,
								35,40,75,32,65,78,120,230,12,66
								};
#else
int fm_signal[FM_BANDWIDTH+1]={0};
#endif
int fm_channel_locked[FM_BANDWIDTH+2][2]={{0,0}};
int fm_channel_filter_locked[FM_BANDWIDTH+1][2]={{0,0}};
int fm_channel_selected[FM_RADIO_CHANNEL_NUM][2]={{0,0}};
int mmi_fmdo_channel_filter(int freq_start)
{
	int i = 0, j=0,k=0;
	int pre_signal = 0;
	int curr_signal = 0;
	int chan_found = freq_start;
	int temp[2];
	int is_rise = 0;
	int channel_count=0;
	int temp1[2];

#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r sizeof : %d \n", FM_RADIO_CHANNEL_NUM * sizeof(fm_channel_selected));
#endif
	for( i=0; i<FM_BANDWIDTH; i++ )
	{
#if defined(NOKE_DEBUG)
		//noke_dbg_printf("\r fm_signal[%d] = %d \n", freq_start+i, fm_signal[i]);
#endif		
		curr_signal = fm_signal[i];
		if( i== FM_BANDWIDTH-1 && curr_signal>pre_signal )
		{
			fm_channel_locked[j][0] = freq_start + i - 1;
			fm_channel_locked[j++][1] = fm_signal[i-1];
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r ===> Hongzhe.liu : found channel %d  \n", freq_start + i - 1);
#endif
			break;
		}else{
			if( curr_signal < pre_signal && pre_signal >= 25 && is_rise == 1)
			{
				fm_channel_locked[j][0] = freq_start + i - 1;
				fm_channel_locked[j++][1] = pre_signal;
#if defined(NOKE_DEBUG)
				noke_dbg_printf("\r ==> Hongzhe.liu : found channel %d  \n", freq_start + i - 1);
#endif
				//pre_signal = 0;
				pre_signal = curr_signal;
				is_rise = 0;
			}else if(curr_signal < pre_signal){
				is_rise = 0;
				pre_signal = curr_signal;
			}else{
				is_rise = 1;
				pre_signal = curr_signal;
			}
		}
	}
	channel_count = j;

#if defined(NOKE_DEBUG)
	for( i=0; i<FM_BANDWIDTH; i++ )
	{
		if( i%5 == 0 )

			noke_dbg_printf("\r\n");
		noke_dbg_printf("%4d:%4d\t", 875+i, fm_signal[i]);
	}
	noke_dbg_printf("\r\n------------------------------------\n");
	for( i=0; i<=channel_count; i++ )
	{
		if( i%5 == 0 )
			noke_dbg_printf("\r\n");
		noke_dbg_printf("%4d:%4d\t", fm_channel_locked[i][0], fm_channel_locked[i][1]);
	}
	noke_dbg_printf("\r\n------------------------------------\n");
#endif
	for( i=1, j=0; i<=channel_count; i++ )
	{
		temp[0] = fm_channel_locked[i][0] - fm_channel_locked[i-1][0];
		temp[1] = fm_channel_locked[i+1][0] - fm_channel_locked[i][0];
		if( temp[0] < 4 && temp[0]>0 )
		{
			if( temp[1] < 4 )
			{
				temp1[0] = 0;
				temp1[1] = 0;
				for( k=0; k<3; k++ )
				{
					if( fm_channel_locked[k+i-1][1]>temp1[1] )
					{
						temp1[0] = fm_channel_locked[k+i-1][0];
						temp1[1] = fm_channel_locked[k+i-1][1];
					}
				}
				fm_channel_filter_locked[j][0]=temp1[0];
				fm_channel_filter_locked[j++][1]=temp1[1];
				
				i += 2;
			}else{
				fm_channel_filter_locked[j][0]=fm_channel_locked[i-1][0]+temp[0]/2;
				fm_channel_filter_locked[j++][1]=fm_channel_locked[i-1][1];
				i++;
			}
		}else{
			fm_channel_filter_locked[j][0]=fm_channel_locked[i-1][0];
			fm_channel_filter_locked[j++][1]=fm_channel_locked[i-1][1];
		}
	}
#if defined(NOKE_DEBUG)	
	noke_dbg_printf("\r\n------------------------------------\n");
#endif
	channel_count = j;
#if defined(NOKE_DEBUG)
	for( i=0; i<=channel_count; i++ )
	{
		if( i%5 == 0 )
			noke_dbg_printf("\r\n");
		noke_dbg_printf("%4d:%4d\t", fm_channel_filter_locked[i][0], fm_channel_filter_locked[i][1]);
	}
	noke_dbg_printf("\r\n------------------------------------\n");
#endif	
	if ( channel_count > FM_RADIO_CHANNEL_NUM )
	{
		for( i = 0; i<channel_count-1; i++ )
		{
			for( k=1; k<channel_count-i; k++ )
			{
				if( fm_channel_filter_locked[k-1][1]<fm_channel_filter_locked[k][1] )
				{
					temp[0] = fm_channel_filter_locked[k][0];
					fm_channel_filter_locked[k][0] = fm_channel_filter_locked[k-1][0];
					fm_channel_filter_locked[k-1][0]= temp[0];

					temp[1] = fm_channel_filter_locked[k][1];
					fm_channel_filter_locked[k][1] = fm_channel_filter_locked[k-1][1];
					fm_channel_filter_locked[k-1][1]= temp[1];
				}
			}
		}
	}
	memcpy( fm_channel_selected, fm_channel_filter_locked, sizeof( fm_channel_filter_locked ) );
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nsize of : %d \r\n", sizeof(fm_channel_filter_locked));
	for( i=0; i<FM_RADIO_CHANNEL_NUM; i ++ )
	{
		noke_dbg_printf("\r## Hongzhe.liu : channel selected :index:[%d] chan:[%d] = [%d]\n", i, fm_channel_selected[i][0], fm_channel_selected[i][1]);
	}
#endif
	return channel_count ;
	
}


//hongzhe.liu end

#if defined(FM_RADIO_WITH_TV)
void mmi_fmrdo_search_all_channels( U16 signal_level )
#else

void mmi_fmrdo_search_all_channels(U8 signal_level)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    int channel_count=0; //hongzhe.liu
    unsigned char  CurrentVolume =0 ;
#if defined(__MMI_FM_RADIO_PRESET_TOP_N__)
    U8 level, max_signal_level;
    S16 index;
#else
    U16 offset, avaliable_sub_band_count;
#endif
    mmi_fmrdo_search_all_struct *search_p = &fmrdo_search_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ALL)
    {
        return;
    }

#if defined(NOKE_DEBUG)
    //noke_dbg_printf("\r\nHuyanwei : mmi_fmrdo_search_all_channels :Debug: %d \r\n",g_fmrdo.volume);
    //noke_dbg_printf("\r\nHuyanwei : mmi_fmrdo_search_all_channels(%d) \r\n",signal_level);
#endif	
#ifndef FM_RADIO_WITH_TV
//Hongzhe.Liu 
  search_p->signal_band[search_p->get_signal_count++] =  signal_level ;
#else
    CurrentVolume = g_fmrdo.volume ;	
    fm_signal[search_p->get_signal_count] = signal_level; //hongzhe.liu add
    search_p->signal_band[search_p->get_signal_count++] = 2 + (signal_level-60)/10; //hongzhe.liu add
#endif	
#if defined(NOKE_DEBUG)
     noke_dbg_printf("\r\n Huyanwei Debug: search_p->get_signal_count: %d < %d \r\n",search_p->get_signal_count,FM_BANDWIDTH);
#endif
    if (search_p->get_signal_count < FM_BANDWIDTH)
    {
        mdi_fmr_get_signal_level((U16) (MIN_FM_FREQUENCY + search_p->get_signal_count), 1, mmi_fmrdo_search_all_channels);      /* populate signal band */
    }
    else
    {
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug: Done......................\r\n");
#endif
    	#ifndef FM_RADIO_WITH_TV
	//del by hongzhe.liu
    /* Find out the Top-N strongest signal channel */
    #if defined(__MMI_FM_RADIO_PRESET_TOP_N__)
        for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
        {
            max_signal_level = 0;
            index = -1;
            
            for(j = 0; j < FM_BANDWIDTH; j++)
            {
                if (!FM_SIG_MARK(search_p->signal_band[j]))
                {
                    level = FM_SIG_LVL(search_p->signal_band[j]);
                    if (level > max_signal_level)
                    {
                        index = j;
                        max_signal_level = level;
                    }
                }
            }

            if(index > 0)
            {
                FM_MARK_SIG(search_p->signal_band[index]);
            }
            else
            {
                goto finished;
            }
        }
    
    #else /* defined(__MMI_FM_RADIO_PRESET_TOP_N__) */
    /* search until no available frequency or FM_SUB_BAND_NUM frequencies are found */
        avaliable_sub_band_count = FM_SUB_BAND_NUM;
	#error "222"
        do
        {
            S16 index;

            for (offset = i = 0; i < FM_SUB_BAND_NUM; i++)
            {
                if (!FM_SUB_MARK(search_p->sub_band_mask[i / 8], (i % 8)))
                {
                    index = mmi_fmrdo_find_best_frequency_in_sub_band(&search_p->signal_band[offset]);
                    if (index >= 0)
                    {
                        j = offset + index;
                        FM_MARK_SIG(search_p->signal_band[j]);
                        search_p->select_count++;
                        if (search_p->select_count == FM_SUB_BAND_NUM)
                        {
                            goto finished;
                        }
                    }
                    else
                    {
                        FM_MARK_SUB(search_p->sub_band_mask[i / 8], (i % 8));
                        avaliable_sub_band_count--;
                    }
                }
                offset += FM_SUB_BANDWIDTH;
            }
        } while (avaliable_sub_band_count > 0);
    #endif /* defined(__MMI_FM_RADIO_PRESET_TOP_N__) */
#else
	//hongzhe.liu add
	channel_count = mmi_fmdo_channel_filter( MIN_FM_FREQUENCY );
	//hongzhe.liu add end	
#endif    
      finished:
        if (search_all_channels_callback_func != NULL)
        {
        #ifndef FM_RADIO_WITH_TV
        /* Stops at the first auto search channel after search */
        #if defined(__MMI_FM_RADIO_FIRST_CHANNEL__)
            MMI_BOOL is_channel_found = MMI_FALSE;

            for (i = 0; i < FM_BANDWIDTH; i++)
            {
                if (FM_SIG_MARK(search_p->signal_band[i]))
                {
                    /* Set first channel to play after search */
                    mdi_fmr_set_freq((U16) (i + MIN_FM_FREQUENCY));
                    g_fmrdo.frequency = i + MIN_FM_FREQUENCY;
                    is_channel_found = MMI_TRUE;
                    break;
                }
            }

            if (!is_channel_found)
        #endif /* defined(__MMI_FM_RADIO_FIRST_CHANNEL__) */ 
            {
                mdi_fmr_set_freq(g_fmrdo.frequency);
            }
	#else
		if ( channel_count > 0 )
		{
			g_fmrdo.frequency = fm_channel_selected[0][0];
		}else{
			g_fmrdo.frequency = DEFAULT_FREQUENCY;
		}
		g_fmrdo.is_power_on = TRUE;
		g_fmrdo.is_ready         = TRUE;
		g_fmrdo.state		     = FMRDO_STATE_READY ;
		//g_fmrdo.is_search_on = TRUE;
		g_fmrdo.volume = CurrentVolume ;
#if defined(NOKE_DEBUG)
	         noke_dbg_printf("\r\n Huyanwei Debug 0: %d \r\n",g_fmrdo.volume);		
#endif
		mmi_fmrdo_set_volume(g_fmrdo.volume);
		mdi_fmr_set_freq(g_fmrdo.frequency);
		
 	    	#endif
            /* Resume SCO volume if SCO connected*/
        #if defined(__MMI_BT_FM_VIA_SCO__)
            mdi_audio_bt_hfp_turn_on();
        #endif		
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\n Huyanwei Debug 1: %d \r\n",g_fmrdo.volume);
#endif
            mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmrdo.volume);
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\n Huyanwei Debug 2: %d \r\n",g_fmrdo.volume);
#endif
            search_all_channels_callback_func(search_p->signal_band);
            search_all_channels_callback_func = NULL;
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
 *  mmi_fmrdo_search_all_channels_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_all_channels_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_ready && g_fmrdo.state == FMRDO_STATE_SEARCH_ALL)
    {
        mdi_fmr_set_freq(g_fmrdo.frequency);
        /* Resume SCO volume if SCO connected*/
    #if defined(__MMI_BT_FM_VIA_SCO__)
        mdi_audio_bt_hfp_turn_on();
    #endif
        mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmrdo.volume);
        search_all_channels_callback_func = NULL;
        mdi_fmr_cancel_getting_signal_level();
        g_fmrdo.state = FMRDO_STATE_READY;
        DeleteScreenIfPresent(SCR_ID_FMRDO_SEARCHING);

    #ifdef __MMI_SUBLCD__
        if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
        {
            ShowIdleAppSubLcd();
        }
    #endif /* __MMI_SUBLCD__ */ 
    }
}

#if defined(__MMI_FM_RADIO_RECORD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_record
 * DESCRIPTION
 *  Start to record FM radio
 * PARAMETERS
 *  filename        [IN]        
 *  format          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_record(UI_string_type filename, U8 format, U8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_format;
    mdi_result result;

#ifdef __DRM_SUPPORT__
    {
        FS_HANDLE handle;
        BOOL is_permitted = FALSE;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        if ((handle = DRM_open_file((PU16) filename, FS_READ_ONLY, DRM_PERMISSION_NONE)) >= FS_NO_ERROR)
        {
            if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
            {
                is_permitted = TRUE;
            }
            DRM_close_file(handle);
        }
        else if (handle < -1)   /* file open error. but not DRM related problem */
        {
            is_permitted = TRUE;
        }

        if (!is_permitted)
        {
            mmi_fmrdo_record_error_hdlr(DRM_NOT_PERMIT_TO_APPEND);
            return;
        }
    }
#endif /* __DRM_SUPPORT__ */ 
    switch (format)
    {

        case FM_FORMAT_AMR:
            file_format = MEDIA_AMR;
            break;
        case FM_FORMAT_WAV:
            file_format = MEDIA_WAV_DVI_ADPCM;
            break;
#if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
        case FM_FORMAT_AWB:
            file_format = MEDIA_AMR_WB;
            break;
#endif
        default:
            file_format = MEDIA_AMR;
            break;
    }

    result = mdi_fmr_start_record(filename, file_format, quality, NULL, mmi_fmrdo_preempted);
    if (result == MDI_AUDIO_SUCCESS)
    {
        g_fmrdo.state = FMRDO_STATE_RECORD;
        mmi_fmrdo_entry_main_record_screen();

        mmi_fmrdo_util_init_duration();
        mmi_fmrdo_util_start_duration();
    }
    else
    {
        mmi_fmrdo_record_error_hdlr(result);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_record
 * DESCRIPTION
 *  Stop record FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* State will update in mmi_fmrdo_preempted() when call back */
    if ((result = mdi_audio_stop_fmr_record_only()) != MDI_AUDIO_SUCCESS)
    {
        /* No reason not stop, error Handling Here. */
        g_fmrdo.state = FMRDO_STATE_READY;

        mmi_fmrdo_entry_restore_main_screen();
        mmi_fmrdo_record_error_hdlr(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_record_on_exit
 * DESCRIPTION
 *  Always stop FM radio record when exit the main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_record_on_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        if ((result = mdi_audio_stop_fmr_record_only()) != MDI_AUDIO_SUCCESS)
        {
            /* No reason not stop, error Handling Here. */
            g_fmrdo.state = FMRDO_STATE_READY;
            mmi_fmrdo_record_error_hdlr(result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pause_record
 * DESCRIPTION
 *  Pause record FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pause_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_RECORD)
    {
        result = mdi_fmr_pause_record(mmi_fmrdo_preempted);

        mmi_fmrdo_util_stop_duration();
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_fmrdo.state = FMRDO_STATE_RECORD_PAUSE;
            mmi_fmrdo_entry_main_pause_screen();
        }
        else
        {
            g_fmrdo.state = FMRDO_STATE_READY;

            mmi_fmrdo_entry_restore_main_screen();
            mmi_fmrdo_record_error_hdlr(result);
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_resume_record
 * DESCRIPTION
 *  Resume record FM radio from pause state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_resume_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {

        result = mdi_frm_resume_record(mmi_fmrdo_preempted);
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_fmrdo.state = FMRDO_STATE_RECORD;

            mmi_fmrdo_util_start_duration();
            mmi_fmrdo_entry_main_record_screen();
        }
        else
        {
            g_fmrdo.state = FMRDO_STATE_READY;

            mmi_fmrdo_entry_restore_main_screen();
            mmi_fmrdo_record_error_hdlr(result);
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }
}
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#endif /* __MMI_FM_RADIO__ */ 


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  ABRepeaterMsgHandler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater message handling
*
* Author:
* -------
*  Tarun Bakshi
*
*============================================================================
*             HISTORY
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
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
* 
* 
* 
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


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

#include "mdi_audio.h"
#include "ABRepeaterResDef.h"
#include "ABRepeaterDef.h"
#include "ABRepeaterType.h"
#include "ABRepeaterProt.h"
#include "ABRepeaterMainScreen.h"

#include "CallManagementGprot.h"
#include "IdleAppProt.h"
#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#define DRM_NOT_PERMIT_TO_PLAY   9999
#endif /* __DRM_SUPPORT__ */ 

#ifdef __MMI_AB_REPEATER__

extern abrepeat_struct g_abrepeat;                      /* defined in ABRepeaterSrc.c */
extern ab_data_struct g_mmi_abrepeat_abplay_data[];
extern BOOL g_mmi_abrepeat_start_progress;
extern BOOL g_mmi_abrepeat_end_progress;
extern signed char g_mmi_abrepeat_draw_refer_state[MAX_AB_POINT];

/* manish adding these vars */
extern S32 g_mmi_abrepeat_Back_Stop;         /* will set audio is stoped by pressing Back key on main AB screen */
extern S32 g_mmi_abrepeat_Option_lsk_stop;   /* will set when audio is stoped by pressing option key on main AB screen */
U16 g_mmi_abrepeat_Callback = NOTHING;

#ifdef __MTK_TARGET__
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);
#endif /* __MTK_TARGET__ */

extern MMI_BOOL IsBacklightOn(void);

#ifdef SIMULATOR_TESTING
extern BOOL inscreen_first_time;
U32 offset = 0;
#endif /* SIMULATOR_TESTING */ 
#endif /* __MMI_AB_REPEATER__ */ /* __MMI_AB_REPEATER */

#ifdef __MMI_AB_REPEATER__


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_do_stop_action
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_do_stop_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_abrepeat.state = AB_STATE_IDLE;
    mdi_audio_stop_file();
    mmi_abrepeat_stopped();
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_probar_to_zero
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_draw_probar_to_zero(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_abrepeat.prgbar_cur_offset = 0;
    mmi_abrepeat_redraw_progress_bar();
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_stopped
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_stopped(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* update state */
    /* manish adding these vars */
    U16 Code, Type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Manish adding here to ensure not draw the screen items when some interrupt is there
    so that aviod writing on interrupt screen */
    if (GetActiveScreenId() != SCR_ID_AB_MAIN)
    {
        g_mmi_abrepeat_Callback = PLAY_STOPPED;
        StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* stop the progrss bar redraw timer too */
        
        return;
    }
    
    g_abrepeat.state = AB_STATE_IDLE;
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_STOP;
    
    /* manish adding this */
    GetkeyInfo(&Code, &Type);
    
    if (g_mmi_abrepeat_Back_Stop == TRUE || (Code == KEY_END) || g_mmi_abrepeat_Option_lsk_stop == TRUE)
    {
    /* don' draw when going back by Back key,End key or selection option
        to switch screen so that return immedaitely in these cases */
    }
    else
    {
        mmi_abrepeat_redraw_main_buttons();
    }
    
    /* Check if its a stop for absection play */
    if (g_abrepeat.curr_play_section >= 0)
    {
        g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_play_section] = AB_SECTION_NON_PLAYING;
        
        if (g_mmi_abrepeat_Back_Stop == TRUE || (Code == KEY_END) || g_mmi_abrepeat_Option_lsk_stop == TRUE)
        {
            /* /don' draw */
        }
        else
        {
            mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_play_section);
        }
        
        if (g_abrepeat.state != AB_STATE_PAUSED)
        {
            g_abrepeat.curr_play_section = -1;
        }
    }
    
    if (g_abrepeat.curr_set_section  >= 0)
    {
        g_abrepeat.abkey_state = AB_SET_IDLE;
        g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_set_section ] = AB_SECTION_DISABLED;
        g_mmi_abrepeat_start_progress = FALSE;
        g_mmi_abrepeat_end_progress = FALSE;
        mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_set_section );
        g_abrepeat.curr_set_section  = -1;
    }
    
    /* manish adding here */
    
    if (g_mmi_abrepeat_Back_Stop == TRUE || (Code == KEY_END) || g_mmi_abrepeat_Option_lsk_stop == TRUE)
    {
        /* /don' draw */
    }
    else
    {
        g_abrepeat.prgbar_cur_offset = 0;
        mmi_abrepeat_redraw_progress_bar();
    }
    
    StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* stop the progrss bar redraw timer too */
#ifdef SIMULATOR_TESTING
    StopTimer(ABREPEAT_DUMMY_FILE_PROG_TIMER);      /* stop the progressing file timer */
    offset = 0;
#endif /* SIMULATOR_TESTING */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_do_pause_action
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_do_pause_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_pause(0, mmi_abrepeat_pause_callback_hdlr);
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_abrepeat_paused();
    }
    else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
    {
        /* pause action for ADIF AAC files are not supportted so keep it playing */
        g_abrepeat.main_selected_button = ABREPEAT_MAIN_PLAY;
        DisplayPopup((PU8) GetString(STR_ID_ABREPEAT_CANNOT_PAUSE), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
    }
    else
    {
        mmi_abrepeat_play_completed();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_paused
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_paused(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update state */
    g_abrepeat.state = AB_STATE_PAUSED;
    StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* pause the progrss bar draw timer too */
#ifdef SIMULATOR_TESTING
    StopTimer(ABREPEAT_DUMMY_FILE_PROG_TIMER);      /* stop the progressing file timer */
#endif 
    /* Check if its a stop for absection play */
    if (g_abrepeat.curr_play_section >= 0)
    {
        g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_play_section] = AB_SECTION_NON_PLAYING;
        mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_play_section);
    }
    mmi_abrepeat_redraw_main_buttons();
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_completed
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_completed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Manish adding here to ensure not draw the screen items when some interrupt is there
    so that avoid writing on interrupt screen */
    if (GetActiveScreenId() != SCR_ID_AB_MAIN)
    {
        g_mmi_abrepeat_Callback = PLAY_COMPLETED;
        StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* stop the progress bar draw */
        return;
    }
    
    g_abrepeat.state = AB_STATE_IDLE;
    
    StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* stop the progress bar draw */
#ifdef SIMULATOR_TESTING
    StopTimer(ABREPEAT_DUMMY_FILE_PROG_TIMER);      /* stop the progressing file timer */
#endif 
    
    g_abrepeat.is_main_sel_btn_down = FALSE;
    g_abrepeat.is_absection_sel_btn_down = FALSE;
    
    /*setting mode*/
    if (g_abrepeat.cur_mode == AB_SETTING_MODE)
    {
        g_abrepeat.prgbar_cur_offset = g_abrepeat.total_offset-1;
        mmi_abrepeat_redraw_progress_bar();
        
        if (g_abrepeat.curr_set_section >= 0)
        {
            g_abrepeat.abkey_state = AB_SET_IDLE; 
            g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_set_section] = AB_SECTION_DISABLED;
            g_mmi_abrepeat_start_progress = FALSE;
            g_mmi_abrepeat_end_progress = FALSE;
            mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_set_section);
            g_abrepeat.curr_set_section  = -1;
        }
        
        mmi_abrepeat_redraw_main_buttons();
        mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, FALSE);
        if(IsBacklightOn())
        {
            gui_start_timer(50, mmi_abrepeat_draw_probar_to_zero);
        }
        else
        {
            mmi_abrepeat_draw_probar_to_zero();
            //g_abrepeat.prgbar_cur_offset = 0;
            //mmi_abrepeat_redraw_progress_bar();
        }

    }
    else/*play mode*/
    {
        if (g_abrepeat.replay_btn_state == AB_REPLAY_ONCE) 
        {
            if (g_abrepeat.curr_play_section >= 0)
            {
                g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_play_section] = AB_SECTION_NON_PLAYING;
                mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_play_section);
                g_abrepeat.curr_play_section = -1;
            }
            else
            {
                g_abrepeat.prgbar_cur_offset = g_abrepeat.total_offset-1;
                mmi_abrepeat_redraw_progress_bar();
            }
            
            mmi_abrepeat_redraw_main_buttons();
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, FALSE);
            if(IsBacklightOn())
            {
                gui_start_timer(50, mmi_abrepeat_draw_probar_to_zero);
            }
            else
            {
                mmi_abrepeat_draw_probar_to_zero();
                //g_abrepeat.prgbar_cur_offset = 0;
                //mmi_abrepeat_redraw_progress_bar();
            }
        }
        else /*always */
        {   
            if(g_abrepeat.curr_play_section < 0)
            {
                g_abrepeat.prgbar_cur_offset = g_abrepeat.total_offset-1;
                mmi_abrepeat_redraw_progress_bar();
            }
            mmi_abrepeat_do_play_action();
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pause_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_pause_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ignore it */
    if (g_abrepeat.state != AB_STATE_PAUSED)
    {
        return;
    }
    
    switch (result)
    {
    case MDI_AUDIO_END_OF_FILE:
        mmi_abrepeat_play_completed();
        break;
    case MDI_AUDIO_TERMINATED:
        mmi_abrepeat_stopped();
        break;
#ifdef __DRM_SUPPORT__
    case MDI_AUDIO_DRM_TIMEOUT:
        mmi_abrepeat_do_stop_action();
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        break;
#endif
    default:
        mmi_abrepeat_stopped();
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_do_resume_action
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_do_resume_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_resume(0, mmi_abrepeat_resume_callback_hdlr);
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_abrepeat_resumed();
    }
    else
    {
        g_abrepeat.state = AB_STATE_IDLE;
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_resumed
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_resumed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update state */
    g_abrepeat.state = AB_STATE_PLAY;
    if (g_abrepeat.curr_play_section >= 0)  /* if its a ab section resume ...only then to redraw */
    {
        g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_play_section] = AB_SECTION_PLAYING;
        mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_play_section);
    }
    
    mdi_audio_get_progress_time(&g_abrepeat.prgbar_cur_offset);
    mmi_abrepeat_redraw_progress_bar();
    
    StartTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, mmi_abrepeat_timer);      /* resume progress bar draw */
#ifdef SIMULATOR_TESTING
    StartTimer(ABREPEAT_DUMMY_FILE_PROG_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, dummy_file_offset); /* resume the file progress too */
#endif 
    
    mmi_abrepeat_redraw_main_buttons();
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_resume_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_resume_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ignore it */
    if (g_abrepeat.state != AB_STATE_PLAY)
    {
        return;
    }
    
    switch (result)
    {
    case MDI_AUDIO_END_OF_FILE:
        mmi_abrepeat_play_completed();
        break;
    case MDI_AUDIO_TERMINATED:
        mmi_abrepeat_stopped();
        break;
#ifdef __DRM_SUPPORT__
    case MDI_AUDIO_DRM_TIMEOUT:
        mmi_abrepeat_do_stop_action();
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        break;
#endif
    default:
        mmi_abrepeat_stopped();
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_do_play_action
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_do_play_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = mmi_abrepeat_do_play_action_without_handle_result();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_abrepeat_played();
    }
    else
    {
        mmi_abrepeat_stopped();
        if (result > 0 && result != MDI_AUDIO_BLOCKED)
        {
            DisplayPopup((PU8) GetString(mmi_abrepeat_err_str(result)), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_do_play_action_without_handle_result
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  S32
*****************************************************************************/
S32 mmi_abrepeat_do_play_action_without_handle_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    FS_HANDLE fs_hdle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This could happen when timer experied after suspend background play or another play or record req by others */
    //if (mdi_audio_is_background_play_suspended() || (g_abrepeat.state == AB_STATE_IDLE && !mdi_audio_is_idle()))
    //{
    //    g_abrepeat.state = AB_STATE_IDLE;
    //    result = -1;
    //}
    //else
    {
        g_abrepeat.state = AB_STATE_IDLE;   /* for preventing from terminated callback; */

        /*check before play, the file may be replaced by BT FTP*/
#ifdef __MTK_TARGET__
#ifdef __DRM_SUPPORT__
        fs_hdle = DRM_open_file((PU16)g_abrepeat.filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY );
        if(fs_hdle >= 0)
        {
            if (!DRM_validate_permission(fs_hdle, NULL, DRM_PERMISSION_PLAY))
            {
                DRM_close_file(fs_hdle);
                return MDI_AUDIO_DRM_PROHIBIT;
            }
        }
#else
        fs_hdle = FS_Open(g_abrepeat.filefullname, FS_READ_ONLY );
#endif /*__DRM_SUPPORT__ */
        if (fs_hdle >= 0)
        {
            FS_HANDLE fs_result;
            U32 audio_file_size = 0;
            U32 audio_checksum = 0;
            U32 read_size = 0;
            void *buf;
            buf = get_ctrl_buffer( 1024 );
#ifdef __DRM_SUPPORT__
            if((fs_result = DRM_read_file(fs_hdle, buf, 1024, &read_size)) == FS_NO_ERROR && read_size != 0 )
#else
            if((fs_result = FS_Read(fs_hdle, buf, 1024, &read_size)) == FS_NO_ERROR && read_size != 0 )
#endif  /*__DRM_SUPPORT__ */
            {
                audio_checksum = med_crc_calculate( (kal_uint8 const *)buf, read_size );
            }
                
#ifdef __DRM_SUPPORT__   
            fs_result = DRM_file_size(fs_hdle, &audio_file_size);
            DRM_close_file(fs_hdle);
#else 
            fs_result = FS_GetFileSize(fs_hdle, &audio_file_size);
            FS_Close(fs_hdle);
#endif  /*__DRM_SUPPORT__ */

            free_ctrl_buffer(buf);

            if (fs_result != FS_NO_ERROR
                || audio_file_size != g_abrepeat.audio_file_size
                || audio_checksum != g_abrepeat.audio_checksum )
            {
                return (S32)MDI_AUDIO_OPEN_FILE_FAIL;
            }
        }
        else
        {
            return (S32)MDI_AUDIO_OPEN_FILE_FAIL;
        }

#endif /*__MTK_TARGET__*/

        if (g_abrepeat.curr_play_section >= 0)
        {
            result = mdi_audio_play_file_portion_with_vol_path(
                g_abrepeat.filefullname,
                g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abstart,
                g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abend,
                DEVICE_AUDIO_PLAY_ONCE,
                mmi_abrepeat_build_cache_ptr(),
                mmi_abrepeat_play_callback_hdlr,
                g_abrepeat.volume,
                MDI_DEVICE_SPEAKER2);
        }
        else
        {
            result = mdi_audio_play_file_with_vol_path(
                g_abrepeat.filefullname,
                DEVICE_AUDIO_PLAY_ONCE,
                mmi_abrepeat_build_cache_ptr(),
                mmi_abrepeat_play_callback_hdlr,
                g_abrepeat.volume,
                MDI_DEVICE_SPEAKER2);
        }
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_abrepeat.state = AB_STATE_PLAY;
        }
    }
    
    return (S32) result;
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_played
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_played(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update state */
    g_abrepeat.state = AB_STATE_PLAY;
    
    /* manish adding on  here to ensure progress bar is drawn always
    even for files <500ms */
    mdi_audio_get_progress_time(&g_abrepeat.prgbar_cur_offset);
    mmi_abrepeat_redraw_progress_bar();
    
    StartTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, mmi_abrepeat_timer);
#ifdef SIMULATOR_TESTING
    StartTimer(ABREPEAT_DUMMY_FILE_PROG_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, dummy_file_offset); /* start the file progress too */
#endif 
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;  /* for prev, next button */
    g_abrepeat.is_main_sel_btn_down = FALSE;
    
    mmi_abrepeat_redraw_main_buttons();
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.state != AB_STATE_PLAY)
    {
        return;
    }
    
    switch (result)
    {
    case MDI_AUDIO_END_OF_FILE:
        mmi_abrepeat_play_completed();
        break;
    case MDI_AUDIO_TERMINATED:
        mmi_abrepeat_stopped();
        break;
#ifdef __DRM_SUPPORT__
    case MDI_AUDIO_DRM_TIMEOUT:
        mmi_abrepeat_do_stop_action();
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        break;
#endif
    default:
        mmi_abrepeat_stopped();
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_err_str
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  U16
*****************************************************************************/
U16 mmi_abrepeat_err_str(S32 result)
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
        return STR_GLOBAL_DRM_PROHIBITED;
    case MDI_AUDIO_DRM_TIMEOUT:
        return STR_GLOBAL_DRM_PROHIBITED;
#endif /* __DRM_SUPPORT__ */ 
    case MDI_AUDIO_FAIL:
        return STR_ID_ABREPEAT_COMMAND_ERROR;
    case MDI_AUDIO_BUSY:
        return STR_ID_ABREPEAT_DEVICE_BUSY;
    case MDI_AUDIO_DISC_FULL:
        return STR_ID_ABREPEAT_DISC_FULL;
    case MDI_AUDIO_OPEN_FILE_FAIL:
        return STR_ID_ABREPEAT_OPEN_FILE_ERROR;
    case MDI_AUDIO_BAD_FORMAT:
        return STR_ID_ABREPEAT_BAD_FORMAT;
    case MDI_AUDIO_INVALID_FORMAT:
        return STR_ID_ABREPEAT_INVALID_FORMAT;
    case MDI_AUDIO_UNSUPPORTED_CHANNEL:
        return STR_ID_ABREPEAT_UNSUPPORTED_CHANNEL;
    case MDI_AUDIO_UNSUPPORTED_FREQ:
        return STR_ID_ABREPEAT_UNSUPPORTED_FREQ;
    case MDI_AUDIO_UNSUPPORTED_TYPE:
        return STR_ID_ABREPEAT_UNSUPPORTED_TYPE;
    case MDI_AUDIO_ERROR:
        return STR_ID_ABREPEAT_ERROR;
    case MDI_AUDIO_NO_SPACE:
        return STR_ID_ABREPEAT_NO_SPACE;
    default:
        return STR_ID_ABREPEAT_COMMAND_ERROR;
    }
}

#ifdef SIMULATOR_TESTING


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_dummy_get_curr_offset
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
U32 mmi_abrepeat_dummy_get_curr_offset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return offset;
}


/*****************************************************************************
* FUNCTION
*  dummy_file_offset
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void dummy_file_offset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (offset >= g_abrepeat.total_offset || inscreen_first_time)
    {
        offset = 0;
        inscreen_first_time = FALSE;
    }
    else
    {
        offset += 2;
    }
}
#endif /* SIMULATOR_TESTING */ 

#endif /* __MMI_AB_REPEATER__ */ 


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
 *   FMScheduleRecMsgHdlr.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  .............
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_FMSRMSGHDLR_C
#define _MMI_FMSRMSGHDLR_C


#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

/*  Include: MMI header file */
#include "CommonScreens.h"

#include "aud_defs.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#if defined(__DRM_SUPPORT__)
#include "Drm_gprot.h"
#endif /* defined(__DRM_SUPPORT__) */ 
/* ... Add More MMI header */
#include "DateTimeGProt.h"
#include "FMScheduleRecDef.h"
#include "FMScheduleRecType.h"
#include "FMScheduleRecProt.h"

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_mdi_callback
 * DESCRIPTION
 *  The callback function for mdi.
 * PARAMETERS
 *  result      [IN]        The result of a mdi command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_mdi_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state == FMSR_STATE_IDLE)
    {
        return;
    }

    /* Stop FM radio recording, but not stop playing yet */
    if ((g_fmsr_cntx.rec.state == FMSR_STATE_RECORD || g_fmsr_cntx.rec.state == FMSR_STATE_PAUSE) &&
        result == MDI_AUDIO_STOP_FM_RECORD)
    {
        if (g_fmsr_cntx.rec.state == FMSR_STATE_PAUSE)
        {
            g_fmsr_cntx.rec.is_screen_paused = TRUE;
        }

        g_fmsr_cntx.rec.state = FMSR_STATE_READY;
        return;
    }
    /* Stop FM radio recording, stop FM radio, then show error message  */
    else if (g_fmsr_cntx.rec.state == FMSR_STATE_RECORD || g_fmsr_cntx.rec.state == FMSR_STATE_PAUSE)
    {
        if (g_fmsr_cntx.rec.state == FMSR_STATE_PAUSE)
        {
            g_fmsr_cntx.rec.is_screen_paused = TRUE;
        }

        g_fmsr_cntx.rec.state = FMSR_STATE_READY;

        /* record not finish correctly, stop FM radio then show the error */
        if (result != MDI_AUDIO_TERMINATED)
        {
            /* Do not show message in the FM radio stop callback. */
            g_fmsr_cntx.rec.is_show_msg = FALSE;
            mmi_fmsr_power_off();

            /* Show error message in the result screen */
            g_fmsr_cntx.rec.is_show_msg = TRUE;
            mmi_fmsr_record_error_hdlr(result);
        
            return;
        }
    }

    /* Stop FM Playing */
    g_fmsr_cntx.rec.state = FMSR_STATE_IDLE;
    mmi_fmsr_record_error_hdlr(result);

    //#ifdef __MMI_SUBLCD__
    //      if( g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL )
    //              ShowIdleAppSubLcd();
    //#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_power_on
 * DESCRIPTION
 *  Power on the FM radio and playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state != FMSR_STATE_IDLE)
    {
        /* Enter error screen */
        return;
    }

    if (!mdi_check_device_ownership())
    {
        /* Enter error screen */
        return;
    }
    else
    {
        /* Stop all aduo and begin to record */
        mdi_audio_stop_all();

        mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmsr_cntx.rec.volume);
        mdi_fmr_power_on_with_path(
            MDI_DEVICE_SPEAKER_BOTH /* MDI_DEVICE_SPEAKER2 */ ,
            (mdi_callback) mmi_fmsr_mdi_callback);
        mdi_fmr_set_freq(g_fmsr_cntx.rec.freqency);
        g_fmsr_cntx.rec.state = FMSR_STATE_READY;
    }

    //#ifdef __MMI_SUBLCD__
    //      if( g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL )
    //              ShowIdleAppSubLcd();
    //#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_power_off
 * DESCRIPTION
 *  Power off the FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state == FMSR_STATE_IDLE)
    {
        return;
    }

    mdi_audio_stop_fmr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_start_record
 * DESCRIPTION
 *  Start to record FM radio
 * PARAMETERS
 *  filename        [IN]        The record file name
 *  format          [IN]        The record file format
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmsr_start_record(UI_string_type filename, U8 format, U8 quality)
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
            mmi_fmsr_record_error_hdlr(DRM_NOT_PERMIT_TO_APPEND);
            return FALSE;
        }
    }
#endif /* __DRM_SUPPORT__ */ 
    switch (format)
    {

        case FMSR_FORMAT_AMR:
            file_format = MEDIA_AMR;
            break;
        case FMSR_FORMAT_WAV:
            file_format = MEDIA_WAV_DVI_ADPCM;
            break;
#if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
        case FMSR_FORMAT_AWB:
            file_format = MEDIA_AMR_WB;
            break;
#endif
        default:
            file_format = MEDIA_AMR;
            break;

    }

    result = mdi_fmr_start_record(filename, file_format, quality, NULL, mmi_fmsr_mdi_callback);

    if (result == MDI_AUDIO_SUCCESS)
    {
        g_fmsr_cntx.rec.state = FMSR_STATE_RECORD;
        return TRUE;
    }
    /* Record request fail, need to stop FM radio playing */
    else if(g_fmsr_cntx.rec.state == FMSR_STATE_READY)
    {
        /* Do not show message in the FM radio stop callback. */
        g_fmsr_cntx.rec.is_show_msg = FALSE;
        mmi_fmsr_power_off();    
    }

    /* Show error message for the error cause */
    g_fmsr_cntx.rec.is_show_msg = TRUE;
    mmi_fmsr_record_error_hdlr(result);
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_stop_record
 * DESCRIPTION
 *  Stop record FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state == FMSR_STATE_READY || g_fmsr_cntx.rec.state == FMSR_STATE_IDLE)
    {
        return;
    }

    if (g_fmsr_cntx.rec.state == FMSR_STATE_RECORD)
    {
        mmi_fmsr_update_duration();
    }

    /* State will update in mmi_fmrdo_preempted() when call back */
    if ((result = mdi_audio_stop_fmr_record_only()) != MDI_AUDIO_SUCCESS)
    {
        /* No reason not stop, error Handling Here. */
        mmi_fmsr_record_error_hdlr(result);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_pause_record
 * DESCRIPTION
 *  Pause FM radio record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_pause_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state == FMSR_STATE_RECORD)
    {
        result = mdi_fmr_pause_record(mmi_fmsr_mdi_callback);

        mmi_fmsr_update_duration();
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_fmsr_cntx.rec.state = FMSR_STATE_PAUSE;
            mmi_fmsr_change_pause_screen();
            mmi_fmsr_redraw_LSK_up();/*add to fix redraw LSK issue*/
        }
        else    /* Can't pause, stop recording */
        {
            g_fmsr_cntx.rec.state = FMSR_STATE_READY;
            mmi_fmsr_record_error_hdlr(result);

            g_fmsr_cntx.rec.is_show_msg = FALSE;
            mmi_fmsr_power_off();
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_resume_record
 * DESCRIPTION
 *  Resume FM radio record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_resume_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.state == FMSR_STATE_PAUSE)
    {
        result = mdi_frm_resume_record(mmi_fmsr_mdi_callback);

        if (result == MDI_AUDIO_SUCCESS)
        {
            g_fmsr_cntx.rec.state = FMSR_STATE_RECORD;
            mmi_fmsr_start_duration();
            mmi_fmsr_restore_recording_screen();
            mmi_fmsr_redraw_LSK_up();/*add to fix redraw LSK issue*/
        }
        else
        {
            g_fmsr_cntx.rec.state = FMSR_STATE_READY;
        
            /* Do not show message in the FM radio stop callback. */
            g_fmsr_cntx.rec.is_show_msg = FALSE;
            mmi_fmsr_power_off();

            /* Show error message in the result screen */
            g_fmsr_cntx.rec.is_show_msg = TRUE;
            mmi_fmsr_record_error_hdlr(result);
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_increase_volume
 * DESCRIPTION
 *  Increase the playing volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_increase_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.volume < MAX_VOL_LEVEL - 1)
    {
        mdi_audio_set_volume(AUD_VOLUME_FMR, ++g_fmsr_cntx.rec.volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_decrease_volume
 * DESCRIPTION
 *  Decrease the playing volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmsr_decrease_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmsr_cntx.rec.volume > 0)
    {
        mdi_audio_set_volume(AUD_VOLUME_FMR, --g_fmsr_cntx.rec.volume);
    }
}

#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* _MMI_FMSRMSGHDLR_C */ /* #ifndef _MMI_FMSRMSGHDLR_C */


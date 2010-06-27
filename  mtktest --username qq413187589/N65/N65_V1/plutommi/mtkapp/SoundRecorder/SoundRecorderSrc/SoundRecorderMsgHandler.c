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
 * SoundRecorderMsgHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_SOUND_RECORDER__

#include "wgui.h"
#include "IdleAppProt.h"
#include "ProtocolEvents.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MiscFunctions.h"
#include "TaskInit.h"
#include "ProfileGprots.h"
#include "SettingProfile.h"
#include "gpioInc.h"
#include "CommonScreens.h"

#include "custom_util.h"
#include "aud_defs.h"
#include "med_struct.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "FileManagerDef.h"

#include "SoundRecorderDef.h"
#include "SoundRecorderType.h"
#include "SoundRecorderProt.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#define DRM_NOT_PERMIT_TO_PLAY   9999
#define DRM_NOT_PERMIT_TO_APPEND 10000
#endif /* __DRM_SUPPORT__ */ 

extern void ClearKeyEvents(void);
extern SoundRecorderStruct SoundRecorder;
extern void(*mmi_sndrec_sms_record_callback) (BOOL result, U16* filepath);

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_res_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID_TYPE mmi_sndrec_get_res_string(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MDI_AUDIO_FAIL:
            return STR_ID_SNDREC_COMMAND_ERROR;
        case MDI_AUDIO_BUSY:
            return STR_ID_SNDREC_DEVICE_BUSY;
        case MDI_AUDIO_DISC_FULL:
            /* return STR_ID_SNDREC_DISC_FULL; */
            return FMGR_FS_DISK_FULL_TEXT;  /* use file manager disk full string id for unified error message notification */
        case MDI_AUDIO_OPEN_FILE_FAIL:
            return STR_ID_SNDREC_OPEN_FILE_ERROR;
        case MDI_AUDIO_BAD_FORMAT:
            return STR_ID_SNDREC_BAD_FORMAT;
        case MDI_AUDIO_INVALID_FORMAT:
            return STR_ID_SNDREC_INVALID_FORMAT;
        case MDI_AUDIO_NO_DISC:
            return STR_ID_SNDREC_NO_CARD;
        case MDI_AUDIO_ERROR:
            return STR_ID_SNDREC_ERROR;
        default:
            return STR_ID_SNDREC_COMMAND_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_duration_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_sndrec_get_duration_ticks()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SoundRecorder.constSeconds + SoundRecorder.recSeconds;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_init_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_init_duration()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.recSeconds = 0;
    SoundRecorder.constSeconds = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_start_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_start_duration()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.constSeconds += SoundRecorder.recSeconds;
    SoundRecorder.recSeconds = 0;
    kal_get_time((kal_uint32*) & SoundRecorder.recTime);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_update_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_update_duration()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    SoundRecorder.recSeconds = current_time - SoundRecorder.recTime;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_record_event_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.cmdProcessing = FALSE;
    if (SoundRecorder.state == STATE_RECORD)
    {
        if (result == MDI_AUDIO_TERMINATED)
        {
            SoundRecorder.state = STATE_IDLE;
            if (!SoundRecorder.isFromCallExpress && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist() &&
                SoundRecorder.isSlefStop)
            {
                mmi_sndrec_record_stopped_hdlr();
            }
            else if (SoundRecorder.isAppend)    /* this should never be in call so we can gobackhistory to file list screen */
            {
                GoBackToHistory(SCR_FMGR_EXPLORER);
                SoundRecorder.isFromCallExpress = FALSE;
                SoundRecorder.isAppend = FALSE;
            }
            else if (SoundRecorder.isFromCallExpress)
            {
                GoBackHistory();
                SoundRecorder.isFromCallExpress = FALSE;
            }
        }
	    else if (result == MDI_AUDIO_SUCCESS)
	    {
	        DisplayPopupCallBack( (PU8)GetString( STR_ID_SNDREC_SMS_RECORD_TIMEOUT ), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE, mmi_sndrec_entry_save_query);
	    }
        else
        {
            SoundRecorder.state = STATE_IDLE;
            if (!SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                if (result == MDI_AUDIO_DISC_FULL)
                {
                    mmi_sndrec_record_disk_full_hdlr();
                }
            	mmi_sndrec_error_hdlr((U8) result);
            }
            else
            {
                mmi_sndrec_error_hdlr((U8) result);
            }
            TurnOnBacklight(1);
        }
    }
	else
	{
		if (mmi_sndrec_sms_record_callback != NULL)
		{	
			mmi_sndrec_sms_record_callback(TRUE, SoundRecorder.fullName);
			mmi_sndrec_sms_record_callback = NULL;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_record_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  format          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_sndrec_get_record_format(U8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_format = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    switch (format)
    {
    #ifndef MT6205B
        case FORMAT_AMR:
            file_format = MEDIA_AMR;
            break;
        case FORMAT_WAV:
            file_format = MEDIA_WAV_DVI_ADPCM;
            break;
    #endif /* MT6205B */ 
    #if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
        case FORMAT_AWB:
            file_format = MEDIA_AMR_WB;
            break;
    #endif /* defined(AMRWB_ENCODE) && defined(AMRWB_DECODE) */ 
        case FORMAT_VM:
            file_format = MEDIA_GSM_EFR;
            break;
        case FORMAT_EVL:
            file_format = MEDIA_VOIPEVL;
            break;
            
        default:
    #ifndef MT6205B
            file_format = MEDIA_AMR;
    #else 
            file_format = MEDIA_GSM_EFR;
    #endif 
            break;
    }
#endif /* __MTK_TARGET__ */

    return file_format;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_start_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  format          [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_sndrec_start_record(UI_string_type filename, U8 format, U8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_format;
    BOOL ok = FALSE;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SoundRecorder.cmdProcessing)
    {
    #ifdef __MTK_TARGET__
    #ifdef __DRM_SUPPORT__
        {
            FS_HANDLE handle;
            BOOL is_permitted = FALSE;

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
                mmi_sndrec_error_hdlr(DRM_NOT_PERMIT_TO_APPEND);
                SoundRecorder.isFromCallExpress = FALSE;
                mdi_audio_stop_all();
                return FALSE;
            }
        }
    #endif /* __DRM_SUPPORT__ */ 
        file_format = mmi_sndrec_get_record_format(format);
    #else /* __MTK_TARGET__ */ 
        file_format = 0;
    #endif /* __MTK_TARGET__ */ 
        result = mdi_audio_start_record(filename, file_format, quality, NULL, mmi_sndrec_record_event_hdlr);
        if (result == MDI_AUDIO_SUCCESS)
        {
            SoundRecorder.state = STATE_RECORD;
            SoundRecorder.isSlefStop = FALSE;
            mmi_sndrec_init_duration();
            mmi_sndrec_start_duration();
            EntryNewScreen(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, NULL, NULL);
            if (SoundRecorder.isAppend)
            {
                mmi_sndrec_entry_append();
            }
            else
            {
                mmi_sndrec_entry_record();
            }
            ok = TRUE;
        }
        else
        {
            mmi_sndrec_error_hdlr(result);
            SoundRecorder.isFromCallExpress = FALSE;
        }
    }

    return ok;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_start_record_with_limit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  format          [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_sndrec_start_record_with_limit(UI_string_type filename, U8 format, U8 quality, U32 size_limit, U32 time_limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_format;
    BOOL ok = FALSE;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SoundRecorder.cmdProcessing)
    {
    #ifdef __MTK_TARGET__
        file_format = mmi_sndrec_get_record_format(format);
    #else /* __MTK_TARGET__ */ 
        file_format = 0;
    #endif /* __MTK_TARGET__ */ 
        result = mdi_audio_start_record_with_limit(filename, file_format, quality, NULL, mmi_sndrec_record_event_hdlr, size_limit, time_limit);
        if (result == MDI_AUDIO_SUCCESS)
        {
            SoundRecorder.state = STATE_RECORD;
            SoundRecorder.isSlefStop = FALSE;
            mmi_sndrec_init_duration();
            mmi_sndrec_start_duration();
            EntryNewScreen(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, NULL, NULL);
            if (SoundRecorder.isAppend)
            {
                mmi_sndrec_entry_append();
            }
            else
            {
                mmi_sndrec_entry_record();
            }
            ok = TRUE;
        }
        else
        {
            mmi_sndrec_error_hdlr(result);
            SoundRecorder.isFromCallExpress = FALSE;
        }
    }

    return ok;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_stop_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SoundRecorder.cmdProcessing)
    {
        SoundRecorder.isSlefStop = TRUE;
        mdi_audio_stop_record();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_play_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_play_event_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.cmdProcessing = FALSE;
    if (SoundRecorder.state == STATE_PLAY)
    {
        if (result == MDI_AUDIO_END_OF_FILE)
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_error_hdlr((U8) result);
            TurnOnBacklight(1);
        }
        else if (result == MDI_AUDIO_TERMINATED)
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_error_hdlr((U8) result);
        }
        else
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_error_hdlr((U8) result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_start_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_sndrec_start_play(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ok = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SoundRecorder.cmdProcessing)
    {
        mdi_result result;

    #ifdef __DRM_SUPPORT__
        {
            FS_HANDLE handle;
            BOOL is_permitted = FALSE;

            if ((handle = DRM_open_file((PU16) filename, FS_READ_ONLY, DRM_PERMISSION_NONE)) >= FS_NO_ERROR)
            {
                is_permitted = TRUE;
                DRM_close_file(handle);
            }
            else if (handle < -1)   /* file open error, but not DRM related problem */
            {
                is_permitted = TRUE;
            }

            if (!is_permitted)
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_error_hdlr(DRM_NOT_PERMIT_TO_PLAY);
                mdi_audio_stop_all();
                return FALSE;
            }
        }
    #endif /* __DRM_SUPPORT__ */ 
        result = mdi_audio_play_file(filename, DEVICE_AUDIO_PLAY_ONCE, NULL, mmi_sndrec_play_event_hdlr);
        if (result == MDI_AUDIO_SUCCESS)
        {
            SoundRecorder.state = STATE_PLAY;
            SoundRecorder.isSlefStop = FALSE;
            mmi_sndrec_init_duration();
            mmi_sndrec_start_duration();
            EntryNewScreen(SCR_ID_SNDREC_PLAY, mmi_sndrec_exit_hdlr, NULL, NULL);
            mmi_sndrec_entry_play();
            ok = TRUE;
        }
        else
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_error_hdlr(result);
        }
    }

    return ok;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_stop_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_stop_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SoundRecorder.cmdProcessing)
    {
        SoundRecorder.isSlefStop = TRUE;
        mdi_audio_stop_file();
        /* GoBackHistory(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pause_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pause_event_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.cmdProcessing = FALSE;

    if (result == MDI_AUDIO_TERMINATED)
    {
        if ((SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED))
        {
            SoundRecorder.state = STATE_IDLE;
            if (!SoundRecorder.isFromCallExpress && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist() &&
                SoundRecorder.isSlefStop)
            {
                mmi_sndrec_record_stopped_hdlr();
            }
            else if (SoundRecorder.isAppend)    /* this should never be in call so we can gobackhistory to file list screen */
            {
                GoBackToHistory(SCR_FMGR_EXPLORER);
                SoundRecorder.isFromCallExpress = FALSE;
                SoundRecorder.isAppend = FALSE;
            }
            else if (SoundRecorder.isFromCallExpress)
            {
                GoBackToHistory(SCR_FMGR_EXPLORER);
                SoundRecorder.isFromCallExpress = FALSE;
            }
        }
        else if (SoundRecorder.state == STATE_PLAY || SoundRecorder.state == STATE_PLAY_PAUSED)
        {
            SoundRecorder.state = STATE_IDLE;
            GoBackHistory();
        }
		else
		{
			if (mmi_sndrec_sms_record_callback != NULL)
			{	
				mmi_sndrec_sms_record_callback(TRUE, SoundRecorder.fullName);
				mmi_sndrec_sms_record_callback = NULL;
			}
		}
    }
    else if(result == MDI_AUDIO_SUCCESS)
    {
        DisplayPopupCallBack( (PU8)GetString( STR_ID_SNDREC_SMS_RECORD_TIMEOUT ), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE, mmi_sndrec_entry_save_query);
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        if ((SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED))
        {
            SoundRecorder.state = STATE_IDLE;
            if (!SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                mmi_sndrec_record_stopped_hdlr();
            }
            else
            {
                mmi_sndrec_error_hdlr((U8) result);
            }
        }
        else if (SoundRecorder.state == STATE_PLAY || SoundRecorder.state == STATE_PLAY_PAUSED)
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_error_hdlr((U8) result);
        }
        TurnOnBacklight(1);
    }
    else
    {
        if (SoundRecorder.state != STATE_IDLE)
        {
            BOOL isRecord = (SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED);

            if (isRecord && result == MDI_AUDIO_FAIL)
            {
                result = MDI_AUDIO_DISC_FULL;
            }
            if (isRecord && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_record_stopped_hdlr();
            }
            else
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_error_hdlr((U8) result);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.state != STATE_IDLE && !SoundRecorder.cmdProcessing)
    {
        mdi_result result = mdi_audio_pause(0, mmi_sndrec_pause_event_hdlr);

        mmi_sndrec_update_duration();
        if (result == MDI_AUDIO_SUCCESS)
        {
            if (SoundRecorder.state == STATE_PLAY)
            {
                SoundRecorder.state = STATE_PLAY_PAUSED;
                mmi_sndrec_entry_play_paused();
            }
            else if (SoundRecorder.state == STATE_RECORD)
            {
                SoundRecorder.state = STATE_RECORD_PAUSED;
                mmi_sndrec_entry_record_paused();
            }
        }
        else
        {
            if (SoundRecorder.state == STATE_RECORD && result == MDI_AUDIO_FAIL)
            {
                result = MDI_AUDIO_DISC_FULL;
            }
            if (SoundRecorder.state == STATE_RECORD && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_record_stopped_hdlr();
            }
            else
            {
                if (SoundRecorder.state == STATE_PLAY)
                {
                    result = MDI_AUDIO_END_OF_FILE;
                }
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_error_hdlr((U8) result);
            }
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_resume_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_resume_event_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.cmdProcessing = FALSE;

    if (result == MDI_AUDIO_TERMINATED)
    {
        if ((SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED))
        {
            SoundRecorder.state = STATE_IDLE;
            if (!SoundRecorder.isFromCallExpress && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist() &&
                SoundRecorder.isSlefStop)
            {
                mmi_sndrec_record_stopped_hdlr();
            }
            else if (SoundRecorder.isAppend)    /* this should never be in call so we can gobackhistory to file list screen */
            {
                GoBackToHistory(SCR_FMGR_EXPLORER);
                SoundRecorder.isFromCallExpress = FALSE;
                SoundRecorder.isAppend = FALSE;
            }
            else if (SoundRecorder.isFromCallExpress)
            {
                GoBackToHistory(SCR_FMGR_EXPLORER);
                SoundRecorder.isFromCallExpress = FALSE;
            }
        }
        else if (SoundRecorder.state == STATE_PLAY || SoundRecorder.state == STATE_PLAY_PAUSED)
        {
            SoundRecorder.state = STATE_IDLE;
            GoBackHistory();
        }
		else
		{
			if (mmi_sndrec_sms_record_callback != NULL)
			{	
				mmi_sndrec_sms_record_callback(TRUE, SoundRecorder.fullName);
				mmi_sndrec_sms_record_callback = NULL;
			}
		}
    }
    else if(result == MDI_AUDIO_SUCCESS)
    {
        DisplayPopupCallBack( (PU8)GetString( STR_ID_SNDREC_SMS_RECORD_TIMEOUT ), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE, mmi_sndrec_entry_save_query);
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        if ((SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED))
        {
            SoundRecorder.state = STATE_IDLE;
            if (!SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                mmi_sndrec_record_stopped_hdlr();
            }
            else
            {
                mmi_sndrec_error_hdlr((U8) result);
            }
        }
        else if (SoundRecorder.state == STATE_PLAY || SoundRecorder.state == STATE_PLAY_PAUSED)
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_error_hdlr((U8) result);
        }
        TurnOnBacklight(1);
    }
    else
    {
        if (SoundRecorder.state != STATE_IDLE)
        {
            BOOL isRecord = (SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED);

            if (isRecord && result == MDI_AUDIO_FAIL)
            {
                result = MDI_AUDIO_DISC_FULL;
            }
            if (isRecord && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                SoundRecorder.state = STATE_IDLE;
                if (result == MDI_AUDIO_DISC_FULL)
                {
                    mmi_sndrec_record_disk_full_hdlr();
                }
                mmi_sndrec_error_hdlr((U8) result);
            }
            else
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_error_hdlr((U8) result);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.state != STATE_IDLE && !SoundRecorder.cmdProcessing)
    {
        mdi_result result;

        result = mdi_audio_resume(0, mmi_sndrec_resume_event_hdlr);
        if (result == MDI_AUDIO_SUCCESS)
        {
            if (SoundRecorder.state == STATE_PLAY_PAUSED)
            {
                SoundRecorder.state = STATE_PLAY;
                mmi_sndrec_start_duration();
                mmi_sndrec_entry_play();
            }
            else if (SoundRecorder.state == STATE_RECORD_PAUSED)
            {
                SoundRecorder.state = STATE_RECORD;
                mmi_sndrec_start_duration();
                if (SoundRecorder.isAppend)
                {
                    mmi_sndrec_entry_append();
                }
                else
                {
                    mmi_sndrec_entry_record();
                }
            }
        }
        else
        {
            if (SoundRecorder.state == STATE_RECORD_PAUSED && !SoundRecorder.isAppend && mmi_sndrec_is_file_exist())
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_record_stopped_hdlr();
            }
            else
            {
                SoundRecorder.state = STATE_IDLE;
                mmi_sndrec_error_hdlr((U8) result);
            }
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_media_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_set_media_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_speech_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_set_speech_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(MDI_VOLUME_SPH, volume);
}

#endif /* __MMI_SOUND_RECORDER__ */ 


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
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * AudioSrc.c
 *
 * Project:
 * --------
 *   MediaTeck GSM
 *
 * Description:
 * ------------
 *   This Module defines the L4 Audio Driver Routines.
 *
 * Author:
 * -------
 * -------
 *             
 *
 * HISTORY
 * -------
 * Created On 12 March
*******************************************************************************/
#include "MMI_include.h"

#include "aud_defs.h"

#include "audioInc.h"
#include "taskInit.h"
#include "ProtocolEvents.h"
#include "DownloadProtos.h"
#include "gpioInc.h"
#include "ProfilesGexdcl.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "Drm_def.h"
#include "DRM_gprot.h"

#include "ProfileMgrGProt.h"
#include "ProfilesGexdcl.h"


#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
#include "resource_audio.h"
#include "SettingProfile.h"
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

#include "ProfileGprots.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "IdleAppDef.h"
#include "CommonScreens.h"

extern void StopAudioFileSystem(U16 AudioId); // defined in DownloadSrc.c
extern void mmi_profiles_set_ring_tone_playing(BOOL);

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
static U8 IsHumanVoiceKeyTonePlaying = 0;


/*****************************************************************************
 * FUNCTION
 *  CanPlayHumanVoiceKeyTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 CanPlayHumanVoiceKeyTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen ||
            g_idle_context.IsOnSimErrorDialerScreen || g_idle_context.IsOnDialerScreen) &&
        (mdi_audio_is_idle() || IsHumanVoiceKeyTonePlaying);
}


/*****************************************************************************
 * FUNCTION
 *  HumanVoiceKeyTonePlayHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HumanVoiceKeyTonePlayHandler(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsHumanVoiceKeyTonePlaying = 0;
}
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

#if defined(__MMI_CUST_KEYPAD_TONE__)
static U8 IsCustKeyTonePlaying = 0;


/*****************************************************************************
 * FUNCTION
 *  CanPlayCustKeyTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 CanPlayCustKeyTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen ||
            g_idle_context.IsOnSimErrorDialerScreen || g_idle_context.IsOnDialerScreen) &&
        (mdi_audio_is_idle() || IsCustKeyTonePlaying);
}


/*****************************************************************************
 * FUNCTION
 *  CustKeyTonePlayHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CustKeyTonePlayHandler(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsCustKeyTonePlaying = 0;
}
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

/*********************************************************************
  * Function         : AudioPlayToneMDICallBack
  *
  * Purpose       : This function is call back function for AudioPlayToneWithCallBack
  *                              if play file fail.
  * 
  * Input Parameters :  mdi_result result
  *
  * Output Parameters  : none
  *
  * Returns       : void
  *
  * Remarks       :  There are 3 types of tone might use file
  *
  *                                1. Incomming Call
  *                                2. Aalrm Tone
  *                                3. Message Tone
  *
  *                               File might play fail, cause of file broken or file not exist, 
  *                               This function will be call back if mdi play fail
  *
  *
**********************************************************************/
static U8 tone_style_callback = 0, tone_type_callback = 0, tone_volume_callback = 0;


/*****************************************************************************
 * FUNCTION
 *  AudioPlayToneMDICallBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayToneMDICallBack(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[AudSrc] AudioPlayToneMDICallBack, result=%d, tone_type", result,tone_type_callback);
    if (result != MDI_AUDIO_SUCCESS && result != MDI_AUDIO_TERMINATED &&
        result != MDI_AUDIO_RESUME && result != MDI_AUDIO_BLOCKED && result != MDI_AUDIO_END_OF_FILE)
    {
        switch (tone_type_callback)
        {
            case INCOMING_CALL_TONE:
            case CARD2_INCOMING_CALL_TONE:
                /*after pop up, incoming call will call palyRequestedTone again 
                  , the DRM_PROHIBITED result will force to play default tone*/
                if(result == MDI_AUDIO_DRM_TIMEOUT)
                {                
                    /*call stopRequestedTone so that gPlayReqToneFlag can be reset*/
                    stopRequestedToneWithId(INCOMING_CALL_TONE,gcallbackToneId);
                    DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),IMG_GLOBAL_WARNING,0,1000,(U8) WARNING_TONE);
                    return ;
                }
                else
                {
                    gcallbackToneId = gstartMidiId ;
                    mdi_audio_play_id_with_vol_path(
                        (U16) (gstartMidiId),
                        tone_style_callback,
                        NULL,
                        NULL,
                        tone_volume_callback,
                        MDI_DEVICE_SPEAKER_BOTH);
                }
            break;

            case ALARM_TONE:
                /*after pop up, incoming call will call palyRequestedTone again 
                  , the DRM_PROHIBITED result will force to play default tone*/
                if(result == MDI_AUDIO_DRM_TIMEOUT)
                {
                    DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),IMG_GLOBAL_WARNING,0,1000,(U8) WARNING_TONE);
                    return;
                }
                else
                {
                    gcallbackToneId = gstartMidiId+1 ;
                    mdi_audio_play_id_with_vol_path(
                        (U16) (gstartMidiId+1),
                        tone_style_callback,
                        NULL,
                        NULL,
                        tone_volume_callback,
                        MDI_DEVICE_SPEAKER_BOTH);
                }
                break;

            case MESSAGE_TONE:
            case CARD2_MESSAGE_TONE:
                gcallbackToneId = gstartMiscToneId + 4 ;
                mdi_audio_play_id_with_vol_path(
                    (U16) (gstartMiscToneId + 4),
                    tone_style_callback,
                    NULL,
                    NULL,
                    tone_volume_callback,
                    MDI_DEVICE_SPEAKER_BOTH);
                break;

            default:
                ASSERT(0);
                break;
        }
        mmi_profiles_set_ring_tone_playing(TRUE);
    }
    else
    {
        mmi_profiles_set_ring_tone_playing(FALSE);
    }
}

/*********************************************************************
  * Function         : AudioPlayToneWithCallBack
  *
  * Purpose       : This function is play tone function with callbakc for mdi interface
  * 
  * Input Parameters :  U16 soundId, U8 style, U8 tone_type
  *
  * Output Parameters  : none
  *
  * Returns       : void
  *
  * Remarks       :  There are 3 types of tone might use file
  *
  *                                1. Incomming Call  ( StartRingTone()  )
  *                                2. Aalrm Tone ( playRequestedTone(ALARM_TONE) )
  *                                3. Message Tone ( playRequestedTone(MESSAGE_TONE) )
  *
  *                               File might play fail, cause of file broken or file not exist, 
  *                               This function will be call back register function if mdi play fail
  *                               Shall play default ringtone in callback function
  *
**********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  AudioPlayToneWithCallBack
 * DESCRIPTION
 *  This paly tone API will paly default tone while playing fail (EX: paly file 
 *  fail.. etc.)
 * PARAMETERS
 *  soundId         [IN]        
 *  style           [IN]        
 *  tone_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayToneWithCallBack(U16 soundId, U8 style, U8 tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioPlayToneWithCallBackVolPath(soundId, style, tone_type, GetRingVolumeLevel(), MDI_DEVICE_SPEAKER_BOTH);
}

/*********************************************************************
  * Function         : AudioPlayToneWithCallBackVolPath
  *
  * Purpose       : This function is play tone function with callbakc for mdi interface
  * 
  * Input Parameters :  U16 soundId, U8 style, U8 tone_type, U8 volume, U8 path
  *
  * Output Parameters  : none
  *
  * Returns       : void
  *
  * Remarks       :  There are 3 types of tone might use file
  *
  *                                1. Incomming Call  ( StartRingTone()  )
  *                                2. Aalrm Tone ( playRequestedTone(ALARM_TONE) )
  *                                3. Message Tone ( playRequestedTone(MESSAGE_TONE) )
  *
  *                               File might play fail, cause of file broken or file not exist, 
  *                               This function will be call back register function if mdi play fail
  *                               Shall play default ringtone in callback function
  *
**********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  AudioPlayToneWithCallBackVolPath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundId         [IN]        
 *  style           [IN]        
 *  tone_type       [IN]        
 *  volume          [IN]        
 *  path            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayToneWithCallBackVolPath(U16 soundId, U8 style, U8 tone_type, U8 volume, U8 path)
{
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[MAX_EXT_MELODY_FULLNAME_WIDTH];
#else /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
    S8 buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
    BOOL play_file = FALSE;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[AudSrc] AudioPlayToneWithCallBackVolPath(), soundId=%d", soundId);
    
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    if (soundId >= PMG_EXT_MELODY_BEGIN && soundId <= PMG_EXT_MELODY_END)
    {
        if (PmgGetFilePathNameByAudioId(buf, sizeof(buf), soundId) == MMI_TRUE)
        {
            play_file = TRUE;
        }
        
        #ifdef __DRM_SUPPORT__
        /*DRM forwardable double check*/
        if(play_file)
        {
            FS_HANDLE handle;
            handle = DRM_open_file((PU16)buf, FS_READ_ONLY, DRM_PERMISSION_PLAY);

            if (handle >= FS_NO_ERROR)
            {
                play_file = DRM_validate_forward_rule(handle, DRM_PERMISSION_PLAY);
                DRM_close_file(handle);
                PRINT_INFORMATION("[User Profiles] DRM forwardable check, result:%d", play_file);
            }
        }
        #endif /*__DRM_SUPPORT__*/
        
        if(!play_file)
        {
            PRINT_INFORMATION("[User Profiles] get external melody fail, soundId:%d, tone type:%d", soundId, tone_type);
            /* Play default audio resource */
            switch (tone_type)
            {
                case INCOMING_CALL_TONE:
                case CARD2_INCOMING_CALL_TONE:
                    soundId = gstartMidiId; 
                    break;
                case ALARM_TONE:
                    soundId = gstartMidiId + 1; 
                    break;
                case MESSAGE_TONE:
                case CARD2_MESSAGE_TONE:
                    soundId = gstartMidiId + 4; 
                    break;                    
            }
        }
    }
    else
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
    {
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        if (GetAudioNameWithPathInFileSystem(soundId, (PS8) buf) != NULL)
        {
            play_file = TRUE;
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    }
    tone_style_callback = style;
    tone_type_callback = tone_type;
    tone_volume_callback = volume;
    gcallbackToneId = soundId ;
    if (play_file)
    {
        result = mdi_audio_play_file_with_vol_path(
                    (void*)buf,
                    style,
                    NULL,
                    AudioPlayToneMDICallBack,
                    tone_volume_callback,
                    path);
    }
    else
    {
#if defined(NOKE_DEBUG)
    	 noke_dbg_printf("\r\n huyanwei Add it For AudioPlayToneWithCallBackVolPath() => mdi_audio_play_id_with_vol_path() \r\n");
#endif
        result = mdi_audio_play_id_with_vol_path(soundId, style, NULL, AudioPlayToneMDICallBack, volume, path);
    }
    if (result != MDI_AUDIO_SUCCESS)
    {
        AudioPlayToneMDICallBack(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AudioPlayReqWithVolPath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundId     [IN]        
 *  style       [IN]        
 *  volume      [IN]        
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayReqWithVolPath(U16 soundId, U8 style, U8 volume, U8 path)
{
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[MAX_EXT_MELODY_FULLNAME_WIDTH];
#else /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
    S8 buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[AudSrc] AudioPlayReqWithVolPath(), soundId=%d", soundId);

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    if (soundId >= PMG_EXT_MELODY_BEGIN && soundId <= PMG_EXT_MELODY_END)
    {
        if (PmgGetFilePathNameByAudioId(buf, sizeof(buf), soundId) == MMI_TRUE)
        {
            mdi_audio_play_file_with_vol_path(buf, style, NULL, NULL, volume, path);
        }
    }
    else
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    if (soundId >= MIN_HUMAN_VOICE_ID && soundId <= MAX_HUMAN_VOICE_ID)
    {
        audio_resource_struct *audio_resource_p = &resource_human_voice_tones[soundId - MIN_HUMAN_VOICE_ID];

        if (mdi_audio_play_string_with_vol_path(
                (void*)audio_resource_p->data,
                audio_resource_p->len,
                (U8) audio_resource_p->format,
                style,
                NULL,
                HumanVoiceKeyTonePlayHandler,
                volume,
                path) == MDI_AUDIO_SUCCESS)
        {
            IsHumanVoiceKeyTonePlaying = 1;
        }
        else
        {
            IsHumanVoiceKeyTonePlaying = 0;
        }
    }
    else
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 
#if defined(__MMI_CUST_KEYPAD_TONE__)
    if (soundId >= MIN_KEYPAD_TONE_ID && soundId <= MAX_KEYPAD_TONE_ID)
    {
        audio_resource_struct *audio_resource_p = &resource_keypad_tones[soundId - MIN_KEYPAD_TONE_ID];

        if (mdi_audio_play_string_with_vol_path(
                (void*)audio_resource_p->data,
                audio_resource_p->len,
                (U8) audio_resource_p->format,
                style,
                NULL,
                CustKeyTonePlayHandler,
                volume,
                path) == MDI_AUDIO_SUCCESS)
        {
            IsCustKeyTonePlaying = 1;
        }
        else
        {
            IsCustKeyTonePlaying = 0;
        }
    }
    else
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (GetAudioNameWithPathInFileSystem(soundId, buf) != NULL)
    {
        mdi_audio_play_file_with_vol_path(buf, style, NULL, NULL, volume, path);
    }
    else
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    {
        mdi_audio_play_id_with_vol_path(soundId, style, NULL, NULL, volume, path);
    }
}

/*********************************************************************
  * Function         : AudioPlayReq
  *
  * Purpose       : This function Play request tone
  * 
  * Input Parameters :  U16 soundId, U8 style
  *
  * Output Parameters  : none
  *
  * Returns       : void
  *
  * Remarks       :  
  *
  *
**********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  AudioPlayReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundId     [IN]        
 *  style       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayReq(U16 soundId, U8 style)
{
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[MAX_EXT_MELODY_FULLNAME_WIDTH];
#else /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
    S8 buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[AudSrc] AudioPlayReq(), soundId=%d, style=%d", soundId,style);

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    if (soundId >= PMG_EXT_MELODY_BEGIN && soundId <= PMG_EXT_MELODY_END)
    {
        if (PmgGetFilePathNameByAudioId(buf, sizeof(buf), soundId) == MMI_TRUE)
        {
            mdi_audio_play_file(buf, style, NULL, NULL);
        }
    }
    else
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    if (soundId >= MIN_HUMAN_VOICE_ID && soundId <= MAX_HUMAN_VOICE_ID)
    {
        audio_resource_struct *audio_resource_p = &resource_human_voice_tones[soundId - MIN_HUMAN_VOICE_ID];

        if (mdi_audio_play_string_with_vol_path(
                (void*)audio_resource_p->data,
                audio_resource_p->len,
                (U8) audio_resource_p->format,
                style,
                NULL,
                HumanVoiceKeyTonePlayHandler,
                GetKeypadVolumeLevel(),
                MDI_DEVICE_SPEAKER2) == MDI_AUDIO_SUCCESS)
        {
            IsHumanVoiceKeyTonePlaying = 1;
        }
        else
        {
            IsHumanVoiceKeyTonePlaying = 0;
        }
    }
    else
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 
#if defined(__MMI_CUST_KEYPAD_TONE__)
    if (soundId >= MIN_KEYPAD_TONE_ID && soundId <= MAX_KEYPAD_TONE_ID)
    {
        audio_resource_struct *audio_resource_p = &resource_keypad_tones[soundId - MIN_KEYPAD_TONE_ID];

        if (mdi_audio_play_string_with_vol_path(
                (void*)audio_resource_p->data,
                audio_resource_p->len,
                (U8) audio_resource_p->format,
                style,
                NULL,
                CustKeyTonePlayHandler,
                GetKeypadVolumeLevel(),
                MDI_DEVICE_SPEAKER2) == MDI_AUDIO_SUCCESS)
        {
            IsCustKeyTonePlaying = 1;
        }
        else
        {
            IsCustKeyTonePlaying = 0;
        }
    }
    else
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (GetAudioNameWithPathInFileSystem(soundId, buf) != NULL)
    {
        mdi_audio_play_file(buf, style, NULL, NULL);
    }
    else
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    {
        mdi_audio_play_id(soundId, style, NULL, NULL);
    }
}

/*********************************************************************
 Function         : AudioStopReq
 Purpose       : This function stops sound playing.
 Input Parameters : U8 soundId
 Output Parameters  : none
 Returns       : void
 Remarks       :
**********************************************************************/
//su-2008/12/04
   #if defined __VIBRATOR_TONE_SUPPORT__
	void closeVibrator()
   	{
   	                VibratorOff();
   	}
   #endif

/*****************************************************************************
 * FUNCTION
 *  AudioStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundId     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioStopReq(U16 soundId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("[AudSrc] AudioStopReq(), soundId=%d", soundId);

    if (soundId >= FILESYSTEM_AUDIO_BASE && soundId <= FILESYSTEM_AUDIO_BASE_END)
    {
        StopAudioFileSystem(soundId);
    }
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    else if (soundId >= PMG_EXT_MELODY_BEGIN && soundId <= PMG_EXT_MELODY_END)
    {
        mdi_audio_stop_file();
    }
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    else if (soundId >= MIN_HUMAN_VOICE_ID && soundId <= MAX_HUMAN_VOICE_ID)
    {
        mdi_audio_stop_string();
    }
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 
    else
    {
        mdi_audio_stop_id(soundId);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AudioPlayIMelodyString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [?]         
 *  len         [IN]        
 *  style       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayIMelodyString(U8 *string, U16 len, U8 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_play_ext_imelody_req_struct *iMelodyPlayReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > MAX_RING_COMPOSE_LEN)
    {
        return;
    }
    iMelodyPlayReq = OslConstructDataPtr(sizeof(mmi_eq_play_ext_imelody_req_struct));
    memcpy(iMelodyPlayReq->imelody, string, len);
    iMelodyPlayReq->len = len;
    iMelodyPlayReq->play_style = style;
    Message.oslMsgId = PRT_EQ_PLAY_EXT_IMELODY_REQ;
    Message.oslDataPtr = (oslParaType*) iMelodyPlayReq;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  AudioPlayIMelodyFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [?]         
 *  style       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayIMelodyFile(U8 *file, U8 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file)   /* !=NULL */
    {
    #if 1
        mdi_audio_play_file(file, style, NULL, NULL);
    #else /* 1 */ 
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
    #endif /* 1 */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  AudioPlayIMelodyFileWithId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [?]         
 *  style       [IN]        
 *  nId         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AudioPlayIMelodyFileWithId(U8 *file, U8 style, U16 nId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file)   /* !=NULL */
    {
        MYQUEUE Message;
        mmi_eq_play_audio_by_name_req_struct *audioByNamePlayReq;

        if (mmi_ucs2strlen((PS8) file) > MAX_MELODY_FILE_NAME)
        {
            return;
        }
        audioByNamePlayReq = OslConstructDataPtr(sizeof(mmi_eq_play_audio_by_name_req_struct));
        audioByNamePlayReq->style = style,
            audioByNamePlayReq->identifier = nId,
            mmi_ucs2cpy((PS8) audioByNamePlayReq->file_name, (PS8) file),
            Message.oslMsgId = PRT_EQ_PLAY_AUDIO_BY_NAME_REQ;
        Message.oslDataPtr = (oslParaType*) audioByNamePlayReq;
        Message.oslPeerBuffPtr = NULL;
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        OslMsgSendExtQueue(&Message);
    }

}


/*****************************************************************************
 * FUNCTION
 *  AudioStopIMelodyFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void AudioStopIMelodyFile(U8 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file)
    {
    #if 1
        mdi_audio_stop_file();
    #else /* 1 */ 
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
    #endif /* 1 */ 
    }
}

// #if 0


/*****************************************************************************
 * FUNCTION
 *  PlayAudioMidiStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audioBuffer     [?]         
 *  length          [IN]        
 *  style           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PlayAudioMidiStream(U8 *audioBuffer, U16 length, U8 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 format = MEDIA_SMF;  /* AUD_MEDIA_SMF; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PlayAudioStream(audioBuffer, length, format, style);
}


/*****************************************************************************
 * FUNCTION
 *  PlayAudioWavStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audioBuffer     [?]         
 *  length          [IN]        
 *  style           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PlayAudioWavStream(U8 *audioBuffer, U16 length, U8 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 format = MEDIA_WAV;  /* AUD_MEDIA_WAV; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PlayAudioStream(audioBuffer, length, format, style);
}


/*****************************************************************************
 * FUNCTION
 *  PlayAudioDviStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audioBuffer     [?]         
 *  length          [IN]        
 *  style           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PlayAudioDviStream(U8 *audioBuffer, U16 length, U8 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 format = MEDIA_DVI_ADPCM;    /* AUD_MEDIA_WAV; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PlayAudioStream(audioBuffer, length, format, style);
}


/*****************************************************************************
 * FUNCTION
 *  PlayAudioStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audioBuffer     [?]         
 *  length          [IN]        
 *  format          [IN]        
 *  style           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PlayAudioStream(U8 *audioBuffer, U16 length, U8 format, U8 style)
{
#if 1
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_play_string((void*)audioBuffer, length, format, style, NULL, NULL);
#else /* 1 */ 
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
#endif /* 1 */ 
}


/*****************************************************************************
 * FUNCTION
 *  StopAudioMidiStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopAudioMidiStream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopAudioStream();
}


/*****************************************************************************
 * FUNCTION
 *  StopAudioWavStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopAudioWavStream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopAudioStream();
}


/*****************************************************************************
 * FUNCTION
 *  StopAudioDviStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopAudioDviStream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopAudioStream();
}


/*****************************************************************************
 * FUNCTION
 *  StopAudioStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopAudioStream(void)
{
#if 1
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();
#else /* 1 */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 1 */ 
}

// #endif


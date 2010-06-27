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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   CommonStubs.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .......
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CommonStubs.c

   PURPOSE     : Stubs for Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG

   DATE     : Nov 12,02

**************************************************************/
#include "MMI_include.h"

#ifndef __MMI_UCM__

#include "wgui_status_icons.h"

#include "gpioInc.h"
#include "UserProfilesResDef.h"
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#include "SettingProfile.h"
#include "SettingGprots.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "VolumeHandler.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "AudioInc.h"

#include "CallManagementIdDef.h"
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "CallStructureManagementProt.h"
#include "PsCallHelperGprot.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"
#ifdef __CTM_SUPPORT__
#include "TextPhoneDef.h"
#endif /* __CTM_SUPPORT__ */ 


#include "CommonStubsProt.h"

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGProts.h"
#endif 

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif 

/* Begin: added by Tim for sound recorder in call */
#ifdef __MMI_SOUND_RECORDER__
extern void mmi_sndrec_entry_from_call(void);
#endif 
/* End: added by Tim for sound recorder in call */

extern void playRequestedToneWithId(U16 toneid, ALL_TONE_ENUM playtone);
extern void stopRequestedToneWithId(U16 toneid, ALL_TONE_ENUM playtone);

//static U16 gMyRing;
//static U16 gBackLight;
//static U16 gHFreeHeldFlag=FALSE;
//static pBOOL gDtmfFlag = TRUE;
//static pBOOL gIsSilent=FALSE;
//static pBOOL gPhoneinMute=FALSE;
//static pBOOL gLSpkNowOff=FALSE;
//static pBOOL gIsInternalAlert=FALSE;
//static pBOOL gVoiceRecordingFlag=FALSE;
//static MMI_ALERT_TYPE gAlertType;


/*****************************************************************************
 * FUNCTION
 *  IsPhoneInMute
 * DESCRIPTION
 *  This function informs whethere the phone is in mute or not.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  U16(?)      [OUT]       
 * RETURNS
 *  returns TRUE if muted else FALSE
 *****************************************************************************/
U16 IsPhoneInMute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsMute;
}


/*****************************************************************************
 * FUNCTION
 *  MutethePhone
 * DESCRIPTION
 *  This function mutes the phone i,e currently changing the global flag.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  changes(?)      [OUT]       The value of gPhoneinMute.
 * RETURNS
 *  void
 *****************************************************************************/
void MutethePhone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsMute = TRUE;
    MuteOnMicrophone();
    ShowStatusIcon(STATUS_ICON_MUTE);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  UnMutethePhone
 * DESCRIPTION
 *  This function informs whethere the phone is in mute or not.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  U16(?)      [OUT]       
 * RETURNS
 *  returns TRUE if muted else FALSE(?)
 *****************************************************************************/
void UnMutethePhone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsMute = FALSE;
    MuteOffMicrophone();
    HideStatusIcon(STATUS_ICON_MUTE);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  IsPhoneInSilent
 * DESCRIPTION
 *  This function informs whethere the phone is silent or not.
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  U16(?)      [OUT]       
 * RETURNS
 *  returns TRUE if silent else FALSE
 *****************************************************************************/
pBOOL IsPhoneInSilent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsSilent;
}


/*****************************************************************************
 * FUNCTION
 *  UnSilencethePhone
 * DESCRIPTION
 *  This function silences the phone
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UnSilencethePhone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsSilent = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SetLSpkNowOff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetLSpkNowOff(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsLoudSpk = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetLSpkNowOff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetLSpkNowOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsLoudSpk;
}


/*****************************************************************************
 * FUNCTION
 *  SetVoiceRecordingFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetVoiceRecordingFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsRecord = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetVoiceRecordingFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetVoiceRecordingFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsRecord;
}


/*****************************************************************************
 * FUNCTION
 *  CMSetupAlertForMT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CMSetupAlertForMT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHB_CM_INTERFACE *PhoneNumberStruct;
    CM_CALL_HANDLE tmp;

#ifdef __MMI_INCOMING_CALL_VIDEO__
    U16 imgId;
#endif 
#ifdef __MMI_PROFILE_ALERT_TYPE_DOMINANT__
    MMI_ALERT_TYPE alert_type;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp = GetIncomingCallHandle();
    PhoneNumberStruct = GetCMPhoneBookStruct();

    cm_p->alert_info.RingToneId = PhoneNumberStruct->ringtoneId;
    cm_p->alert_info.BacklightPatternId = PhoneNumberStruct->backlightId;
    cm_p->alert_info.AlertType = PhoneNumberStruct->alertType;

#ifdef __MMI_INCOMING_CALL_VIDEO__
    imgId = GetCallImgId(tmp);
    if (((imgId & 0x8000) || ((imgId & 0x3fff) >= VDO_ID_PHB_MTCALL_1)) && (imgId & 0x4000))
        /* user defined video file or system default video resource */
        /* use video sound as ring tone */
    {
        cm_p->alert_info.RingToneId = CM_RINGTONE_VIDEO;
    }
    else
#endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
        /* phb not set ring tone => use profile default */
    if (cm_p->alert_info.RingToneId == 0)
    {
        cm_p->alert_info.RingToneId = GetRingToneID();
    }

    /* phb not set backlight pattern => use profile default */
    if (cm_p->alert_info.BacklightPatternId == 0)
    {
        cm_p->alert_info.BacklightPatternId = GetLightStatus();
    }

    /* phb not set alert type => use profile default */
    if (cm_p->alert_info.AlertType == MMI_ALERT_NONE)
    {
        cm_p->alert_info.AlertType = GetMtCallAlertTypeEnum();
    }

#ifdef __MMI_PROFILE_ALERT_TYPE_DOMINANT__
    /* get alert type from profile */
    alert_type = GetMtCallAlertTypeEnum();
    /* if alert type is vibration only or silent, do not ring according to the caller group */
    if (alert_type == MMI_VIBRATION_ONLY || alert_type == MMI_SILENT)
    {
        cm_p->alert_info.AlertType = alert_type;
    }
#endif /* __MMI_PROFILE_ALERT_TYPE_DOMINANT__ */ 

#ifdef __MMI_CM_DATA_CALL_ONLY_PLAY_TONE__
    if (GetCallType(tmp) == CM_DATA_CALL)
    {
        cm_p->alert_info.RingToneId = TONE_DATA_CALL;
    }

    if (GetPreviousCallWAP() == TRUE)
    {
        SetPreviousCallWAP(FALSE);
        cm_p->alert_info.RingToneId = TONE_DATA_CALL;
    }
#endif /* __MMI_CM_DATA_CALL_ONLY_PLAY_TONE__ */ 
}


	
/*****************************************************************************
 * FUNCTION
 *  ShowIncomingCallIndication
 * DESCRIPTION
 *  This function is called to Show incoming call indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowIncomingCallIndication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* before show incoming call indication, it must entered incoming call screen 
       which will already suspend audio, no need to stop again */
    /* StopRingtoneOrVibrator(); */

    PRINT_INFORMATION("ShowIncomingCallIndication\n");

#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanwei Add It : ShowIncomingCallIndication() \r\n");
#endif	
#ifdef __MMI_CM_CCBS_SUPPORT__
	if(GetDropCCBSAnswerMTFlag() == TRUE)
	{
		PRINT_INFORMATION("ShowIncomingCallIndication: Dropping CCBS answering MT, don't play sound\n");
		return;
	}
#endif /*__MMI_CM_CCBS_SUPPORT__*/

    CMSetupAlertForMT();

    StartRingtoneOrVibrator();

#ifdef __MMI_INCOMING_CALL_VIDEO__
    if(cm_p->alert_info.RingToneId != CM_RINGTONE_VIDEO)
#endif 
    	SetRingingFlag(TRUE);

#ifdef __MMI_CM_CCBS_SUPPORT__
#else   
    if (GetCCBSFlag() == TRUE)
    {
        StartTimer(CM_CCBS_NOTIFYDURATION_TIMER, CM_CCBS_NOTIFY_TIMEOUT, StopIncomingCallIndication);
    }
#endif /*__MMI_CM_CCBS_SUPPORT__*/

}


/*****************************************************************************
 * FUNCTION
 *  StopIncomingCallIndication
 * DESCRIPTION
 *  This function is called to Stop incoming call indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopIncomingCallIndication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCallWaitFlag() && (!GetWait2RingCallFlag()))
    {
        /* stop waiting call indication */
        SetCallWaitFlag(FALSE);
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_StopRing1);
        AudioStopReq(TONE_CALL_WAITING);

    #if defined(__MMI_BT_SUPPORT__)
        mmi_bt_stop_hf_ring_req();
    #endif 

        SetNoTwiceRingFlag(FALSE);
        StopRingtoneOrVibrator();
    }
    else
    {
        /* stop incoming call indication */
        if (GetWait2RingCallFlag())
        {
            SetWait2RingCallFlag(FALSE);
            SetNoTwiceRingFlag(FALSE);
        }
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_StopRing2);
        StopRingtoneOrVibrator();
    }

    if (GetAutoAnswerFlag() == TRUE && GetTotalCallCount() == 0)
    {
        StopTimer(CM_AUTOANSWER_NOTIFYDURATION_TIMER);
        SetAutoAnswerFlag(FALSE);
    }

    if (GetCCBSFlag() == TRUE)
    {
        StopTimer(CM_CCBS_NOTIFYDURATION_TIMER);
    }

    SetRingAfterVibFlag(FALSE);
    SetRingingFlag(FALSE);

    if (GetExitScrnID() == ITEMSCR_INCOMING_CALL && GetTotalCallCount() == 1)
    {
    #ifdef __MMI_INCOMING_CALL_VIDEO__
        CM_CALL_HANDLE handle;
        U16 imgId;

        handle = GetIncomingCallHandle();
        imgId = GetCallImgId(handle);

        /* pause video */
        if ((imgId & 0x8000) || ((imgId & 0x3fff) >= VDO_ID_PHB_MTCALL_1))
        {
            StopCategory17Video();
        }
        else
    #endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
            MOMTHideAnimation();
    }

}


/*****************************************************************************
 * FUNCTION
 *  CMPlayMTRingTone
 * DESCRIPTION
 *  This function is called to play ring or vibrator
 *  according to current setting
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CMPlayMTRingTone(U16 tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INCOMING_CALL_VIDEO__
    if (tone != CM_RINGTONE_VIDEO)
#endif 
        StartRingTone(tone);
}


/*****************************************************************************
 * FUNCTION
 *  StartRingtoneOrVibrator
 * DESCRIPTION
 *  This function is called to play ring or vibrator
 *  according to current setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartRingtoneOrVibrator(void)
{
#if defined(__MMI_BT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_aud2hf() == MMI_TRUE)
    {
        mmi_bt_start_hf_ring_req();
    }
#endif /* defined(__MMI_BT_SUPPORT__) */ 

    switch (cm_p->alert_info.AlertType)
    {
        case MMI_RING:
            /* StartRingTone (cm_p->alert_info.RingToneId); */
            CMPlayMTRingTone(cm_p->alert_info.RingToneId);
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOn();
            break;
        case MMI_VIBRATION_AND_RING:
            VibratorOn();

      /************************************************/
            /* Robin 0602, Remove set AT command profile functions */
            /* AT command will query MMI when needed                   */
      /************************************************/
            /* NSC This API is not correct not integrated wit Profiles Silent Mode */
            /*
             * if(IsPhoneInSilent())
             * SilentModeOff();
             */
            /* StartRingTone (cm_p->alert_info.RingToneId); */
            CMPlayMTRingTone(cm_p->alert_info.RingToneId);
            break;
        case MMI_VIBRATION_THEN_RING:
            VibratorThenRing();
            break;
        case MMI_SILENT:
            VibratorOn();
            break;
        case MMI_ALERT_NONE:
            break;
        default:
            /* StartRingTone (cm_p->alert_info.RingToneId); */
            CMPlayMTRingTone(cm_p->alert_info.RingToneId);
            break;
    }
    PlayPatternCallerGroup((MMI_LEDLIGHT_STATUS_ENUM) cm_p->alert_info.BacklightPatternId);
}


/*****************************************************************************
 * FUNCTION
 *  StopRingtoneOrVibrator
 * DESCRIPTION
 *  This function stops RingTone or Vibrarator depending on Alert Type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopRingtoneOrVibrator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_SUPPORT__)
    if (mmi_bt_is_aud2hf() == MMI_TRUE)
    {
        mmi_bt_stop_hf_ring_req();
    }
#endif /* defined(__MMI_BT_SUPPORT__) */ 

    switch (cm_p->alert_info.AlertType)
    {
        case MMI_RING:
            StopRingTone(cm_p->alert_info.RingToneId);
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOff();
            break;
        case MMI_VIBRATION_AND_RING:
            StopRingTone(cm_p->alert_info.RingToneId);
            VibratorOff();
            break;
        case MMI_VIBRATION_THEN_RING:
            /* NSC Does not make the mobile go back into Silent Mode */
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            VibratorOff();
            StopRingTone(cm_p->alert_info.RingToneId);
            break;
        case MMI_SILENT:
            break;
        case MMI_ALERT_NONE:
            break;
        default:
            break;
    }
    StopPatternCallerGroup((MMI_LEDLIGHT_STATUS_ENUM) cm_p->alert_info.BacklightPatternId);
}

#ifdef __MMI_INTELLIGENT_CALL_ALERT__
U16 intelligent_call_alert_ring_tone;
U8 is_intelligent_call_alert_playing_text = 0;


/*****************************************************************************
 * FUNCTION
 *  PlayIncomingCallTextHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PlayIncomingCallTextHandler(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_intelligent_call_alert_playing_text = 0;
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        playRequestedToneWithId(intelligent_call_alert_ring_tone, INCOMING_CALL_TONE);
    }
}
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */ 


/*****************************************************************************
 * FUNCTION
 *  StartRingTone
 * DESCRIPTION
 *  This function statrs the ringtone
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  ringTone        [IN]        
 *  ringtone(?)     [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
void StartRingTone(U16 ringTone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ringTone < MAX_TONE_ID)
    {
        playRequestedToneWithId(ringTone, INCOMING_CALL_TONE);
    }
    else if (!IsSilentModeActivated())
    {
    #ifdef __MMI_INTELLIGENT_CALL_ALERT__
        U16 text[(MAX_NAME + MAX_CM_NUMBER) / 2 + 1];
        U16 count;
        S32 text_len;

        MMI_INTELLIGENT_CALL_ALERT_TYPE isIntelligentCallAlertOn = GetIntelligentCallAert();

        if (isIntelligentCallAlertOn == MMI_INTELLIGENT_CALL_ALERT_ON)
        {
            for (count = 0; count < MAX_CALLS; count++)
            {
                if (CM_INCOMING_STATE == cm_p->state_info.AllCalls[count].curr_state)
                {
                    text[0] = 0;
                #ifdef DIGIT_TONE_SUPPORT
                    mmi_ucs2cpy((S8*) text, (S8*) cm_p->state_info.AllCalls[count].number);
                #endif 
                #if defined(SIMPLE_TTS) || defined(DIGIT_TONE_SUPPORT)
                    mmi_ucs2cat((S8*) text, (S8*) cm_p->state_info.AllCalls[count].pBname);
                #endif 
                    text[(MAX_NAME + MAX_CM_NUMBER) / 2] = 0;
                    break;
                }
            }

            text_len = mmi_ucs2strlen((S8*) text);
            if (text_len > 0 &&
                mdi_audio_play_text_with_vol_path(
                    (U8*) text,
                    mmi_ucs2strlen((S8*) text),
                    100,
                    NULL,
                    PlayIncomingCallTextHandler,
                    GetRingVolumeLevel(),
                    MDI_DEVICE_SPEAKER_BOTH) == MDI_AUDIO_SUCCESS)
            {
                intelligent_call_alert_ring_tone = ringTone;
                is_intelligent_call_alert_playing_text = 1;
            }
            else
            {
                playRequestedToneWithId(ringTone, INCOMING_CALL_TONE);
            }
        }
        else
    #endif /* __MMI_INTELLIGENT_CALL_ALERT__ */ 
            playRequestedToneWithId(ringTone, INCOMING_CALL_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  StopRingTone
 * DESCRIPTION
 *  This function stops the ringtone
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  ringTone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StopRingTone(U16 ringTone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
    if (is_intelligent_call_alert_playing_text)
    {
        mdi_audio_stop_all();
    }
    else
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */

    stopRequestedToneWithId(ringTone, INCOMING_CALL_TONE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  VibratorThenRing
 * DESCRIPTION
 *  This function is called for Vibrator Then Ring indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VibratorThenRing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VibratorOn();
    StartTimer(CM_ALERT_NOTIFYDURATION_TIMER, VIB_THEN_RING_DURATION, StopVibratorPlayRing);
}


/*****************************************************************************
 * FUNCTION
 *  StopVibratorPlayRing
 * DESCRIPTION
 *  This function is called for StopVibrator PlayRing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_INCOMING_CALL_VIDEO__
extern void EnableCategory17Audio(void);
#endif 
void StopVibratorPlayRing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
    VibratorOff();
    /* StartRingTone (cm_p->alert_info.RingToneId); */
#ifdef __MMI_INCOMING_CALL_VIDEO__
    if (cm_p->alert_info.RingToneId == CM_RINGTONE_VIDEO)
    {
        /* turn on audio path */
        EnableCategory17Audio();
        SetRingAfterVibFlag(TRUE);
    }
#endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
    CMPlayMTRingTone(cm_p->alert_info.RingToneId);
}


/*****************************************************************************
 * FUNCTION
 *  PlayConnectNotice
 * DESCRIPTION
 *  This function is wrapper to Play Ring Tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CONNECT_NOTICE__
void PlayConnectNotice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetConnectNoticeType())
    {
        case MMI_NOTICE_NONE:
            break;
        case MMI_NOTICE_TONE_ONLY:
            playRequestedTone(CONNECT_TONE);
            break;
        case MMI_NOTICE_VIB_ONLY:
            PlayVibratorOnce();
            break;
        case MMI_NOTICE_TONE_AND_VIB:
            playRequestedTone(CONNECT_TONE);
            PlayVibratorOnce();
            break;
    }
}
#endif /* __MMI_CONNECT_NOTICE__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetRingAfterVibFlag
 * DESCRIPTION
 *  This function returns state of alerts
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetRingAfterVibFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsRingAfterVib;
}


/*****************************************************************************
 * FUNCTION
 *  SetRingAfterVibFlag
 * DESCRIPTION
 *  This function checks to see if need to ring again
 * PARAMETERS
 *  truth       [IN]        
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void SetRingAfterVibFlag(pBOOL truth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsRingAfterVib = truth;
}


/*****************************************************************************
 * FUNCTION
 *  GetSpeechFlag
 * DESCRIPTION
 *  This function returns state of alerts
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetSpeechFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("GetSpeechFlag:%d",cm_p->alert_info.IsSpeechOn);
    return cm_p->alert_info.IsSpeechOn;
}


/*****************************************************************************
 * FUNCTION
 *  SetSpeechFlag
 * DESCRIPTION
 *  This function checks to see if remote is alerting
 * PARAMETERS
 *  truth       [IN]        
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void SetSpeechFlag(pBOOL truth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("SetSpeechFlag:%d",truth);
    cm_p->alert_info.IsSpeechOn = truth;
}


/*****************************************************************************
 * FUNCTION
 *  SetRingingFlag
 * DESCRIPTION
 *  This function checks to see if remote is alerting
 * PARAMETERS
 *  truth       [IN]        
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void SetRingingFlag(pBOOL truth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("SetRingingFlag: %d\n", truth);

    cm_p->alert_info.IsRinging = truth;
}


/*****************************************************************************
 * FUNCTION
 *  GetRingingFlag
 * DESCRIPTION
 *  This function returns state of internal alerts indication
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetRingingFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsRinging;
}


/*****************************************************************************
 * FUNCTION
 *  GetInternalAlert
 * DESCRIPTION
 *  This function returns state of internal alerts indication
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetInternalAlert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsInternalAlert;
}


/*****************************************************************************
 * FUNCTION
 *  SetInternalAlert
 * DESCRIPTION
 *  This function checks to see if USSD is supported in the phone/network
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  truth       [IN]        
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void SetInternalAlert(pBOOL truth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.IsInternalAlert = truth;
}


/*****************************************************************************
 * FUNCTION
 *  PlayInternalOutgoingTone
 * DESCRIPTION
 *  Stops playing waiting call tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PlayInternalOutgoingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInternalAlert(TRUE);
    StartRingTone(TONE_RINGING_CALL_GSM);
}


/*****************************************************************************
 * FUNCTION
 *  StopInternalOutgoingTone
 * DESCRIPTION
 *  Stops playing waiting call tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopInternalOutgoingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInternalAlert(FALSE);
    AudioStopReq(TONE_RINGING_CALL_GSM);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackPlayInternalTone
 * DESCRIPTION
 *  This function plays GSMtone
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackPlayInternalTone(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = DeriveInternalAlrtIndVal(info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PlayInternalTone);
        PlayInternalOutgoingTone();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetDTMFFlag
 * DESCRIPTION
 *  Sets the DTMF Flag
 * PARAMETERS
 *  dtmfFlag        [IN]        
 *  TRUE(?)         [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetDTMFFlag(pBOOL dtmfFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->alert_info.DTMF = dtmfFlag;
}


/*****************************************************************************
 * FUNCTION
 *  GetDTMFFlag
 * DESCRIPTION
 *  Gets the DTMF Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetDTMFFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.DTMF;
}


/*****************************************************************************
 * FUNCTION
 *  DTMFFunction
 * DESCRIPTION
 *  This function enables or Disables the DTMF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DTMFFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetDTMFFlag() == TRUE)
    {
        SetDTMFFlag(FALSE);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_SCR1002_OFF_LSK);
    }
    else
    {
        SetDTMFFlag(TRUE);
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_SCR1002_ON_LSK);
    }
    Hint2024DTMF(GetCurrHiliteID());
    RedrawCategoryFunction();
    HiliteM2024DTMF();
}


/*****************************************************************************
 * FUNCTION
 *  SetHFreeHeld
 * DESCRIPTION
 *  Sets the HFreeHeld Flag
 * PARAMETERS
 *  HFreeHeldFlag       [IN]        
 *  Flag(?)             [IN]        Value to set
 * RETURNS
 *  void
 *****************************************************************************/
void SetHFreeHeld(BOOL HFreeHeldFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TRUE: current LSpk, show HHeld as RSK,
       FALSE: current no LSpk, show HFree as RSK */
    cm_p->alert_info.IsHFree = HFreeHeldFlag;
}


/*****************************************************************************
 * FUNCTION
 *  GetHFreeHeld
 * DESCRIPTION
 *  Gets the HFreeHeld Flag
 * PARAMETERS
 *  void
 *  Flag(?)     [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetHFreeHeld(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->alert_info.IsHFree;
}


/*****************************************************************************
 * FUNCTION
 *  LoudSpeakerFunction
 * DESCRIPTION
 *  This function enables the Loud Speaker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LoudSpeakerFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetHFreeHeld() == FALSE)
    {
        SetHFreeHeld(TRUE);
        if (GetExitScrnID() == SCR_CM_ACTIVECALLSCREEN)
        {
            /* in active screen */
            ChangeRightSoftkey(STR_SCR1002_LOUDSP_H_HELD_RSK, IMG_SCR1002_LOUDSP_RSK);
        }

        EnableHandsFree();
        SetLoudSpeaker(TRUE);
    }
    else
    {
        SetHFreeHeld(FALSE);
        if (GetExitScrnID() == SCR_CM_ACTIVECALLSCREEN)
        {
            /* in active screen */
            ChangeRightSoftkey(STR_SCR1002_LOUDSP_H_FREE_RSK, IMG_SCR1002_LOUDSP_RSK);
        }

        DisbleHandsFree();
        SetLoudSpeaker(FALSE);
    }

    EntryScrLoudSpNotifyScreen();
}


/*****************************************************************************
 * FUNCTION
 *  OptionMuteorUnMutetheCall
 * DESCRIPTION
 *  This handles the Mute functionality in Options
 *  
 *  This toggles the functionality btw Mute & Unmute.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void OptionMuteorUnMutetheCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsPhoneInMute())
    {
        UnMutethePhone();
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_SCR1002_ON_LSK);
    }
    else
    {
        MutethePhone();
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_SCR1002_OFF_LSK);
    }
    Hint2020Mute(GetCurrHiliteID());
    RedrawCategoryFunction();
    HiliteM2020Mute();
}


/*****************************************************************************
 * FUNCTION
 *  IsSimControlProcedure
 * DESCRIPTION
 *  This function is a stub for checking sim control proc.
 *  
 *  This is a part of other application
 * PARAMETERS
 *  buf     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsSimControlProcedure(PU8 buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IsManufactuerSpecific
 * DESCRIPTION
 *  This function is a stub for checking manufactuer specific string
 *  
 *  This is a part of other application
 * PARAMETERS
 *  buf     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsManufactuerSpecific(PU8 buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SetSideVolumeKeysForCM
 * DESCRIPTION
 *  Sets Key Handlers for Volume Key in CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetSideVolumeKeysForCM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(DummyAforSideKeyHandling, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(DummyCforSideKeyHandling, KEY_VOL_DOWN, KEY_EVENT_DOWN);

#ifdef __CTM_SUPPORT__
    if (ctm_p->status == FALSE)
#endif /* __CTM_SUPPORT__ */ 
    {
        SetKeyHandler(DummyBforSideKeyHandling, KEY_VOL_UP, KEY_LONG_PRESS);
#ifdef __MMI_IN_CALL_CAMERA_KEY_START_SOUND_RECORD__
        SetKeyHandler(DummyBforSideKeyHandling, KEY_CAMERA, KEY_EVENT_UP);
#endif 
        SetKeyHandler(DummyDforSideKeyHandling, KEY_VOL_DOWN, KEY_LONG_PRESS);
    }

    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_DOWN, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  DummyAforSideKeyHandling
 * DESCRIPTION
 *  Sets Key Handler for Volume Up Key in CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyAforSideKeyHandling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(SetKeyPadVolUp, KEY_VOL_UP, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DummyBforSideKeyHandling
 * DESCRIPTION
 *  Sets Key Handler for Volume Up Key in CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyBforSideKeyHandling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_UP);
#ifdef __MMI_IN_CALL_CAMERA_KEY_START_SOUND_RECORD__
    ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_CAMERA, KEY_EVENT_UP);
#endif /* __MMI_IN_CALL_CAMERA_KEY_START_SOUND_RECORD__ */ 
    SetKeyPadStartVoiceRecordLongPress();
}


/*****************************************************************************
 * FUNCTION
 *  DummyCforSideKeyHandling
 * DESCRIPTION
 *  Sets Key Handler for Volume Down Key in CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyCforSideKeyHandling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(SetKeyPadVolDown, KEY_VOL_DOWN, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DummyDforSideKeyHandling
 * DESCRIPTION
 *  Sets Key Handler for Volume Down Key in CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyDforSideKeyHandling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyPadStopVoiceRecordLongPress();
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadStartVoiceRecordLongPress
 * DESCRIPTION
 *  To stop voice memo recording
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadStartVoiceRecordLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetTotalActiveCallCount() > 0)
    {
    #ifdef __MMI_SOUND_RECORDER__
        /* Begin: added by Tim for sound recorder in call */
        mmi_sndrec_entry_from_call();
        /* End: added by Tim for sound recorder in call */
    #else /* __MMI_SOUND_RECORDER__ */ 
        MakePsStartVoiceRecord();
    #endif /* __MMI_SOUND_RECORDER__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetKeyPadStopVoiceRecordLongPress
 * DESCRIPTION
 *  To stop voice memo recording
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeyPadStopVoiceRecordLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_StopRecord);

    SetVoiceRecordingFlag(FALSE);
    HideStatusIcon(STATUS_ICON_VOICE_RECORD);
    UpdateStatusIcons();
#ifdef __MMI_SOUND_RECORDER__
    // Begin: added by Tim for sound recorder in call
    //      mdi_audio_stop_record();
    // End: added by Tim for sound recorder in call
#else /* __MMI_SOUND_RECORDER__ */ 
    MakePsStopVoiceRecord();
#endif /* __MMI_SOUND_RECORDER__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  insert_screen_before_call_marker
 * DESCRIPTION
 *  insert the history before marker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void insert_screen_before_call_marker(U16 scrnID, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history hist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hist, 0, sizeof(history));

    hist.scrnID = scrnID;
    hist.entryFuncPtr = entryFuncPtr;

    InsertHistoryBeforeThisScrnReference(GetCmMarkerScrnID(), &hist);
}

#endif /* __MMI_UCM__ */
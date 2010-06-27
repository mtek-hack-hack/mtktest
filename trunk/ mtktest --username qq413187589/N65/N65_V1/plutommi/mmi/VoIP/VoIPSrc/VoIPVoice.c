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
 *  VoIPVoice.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MTK_TARGET__
#include <windows.h>
#endif 
#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "AlarmFrameWorkProt.h"
#include "CallManagementGprot.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "ProfileGprots.h"
#include "SoundRecorderProt.h" /* for auto record */
#include "wgui_status_icons.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "med_struct.h"
#include "rtp_api.h"
#include "device.h"         /* for call_status_req enum */

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_switch_session
 * DESCRIPTION
 *  Start critical session based on the current state. For bluetooth SCO link,
 *  session is started when outgoing call is dialing or incoming call is ringing;
 *  session is ended when the last call is disconnected.
 *  For MDI sound control, session is started when outgoing call is dialing or
 *  incoming call is answering; session is ended when the last call is disconnected or 
 *  only one incoming call exists, because session should stop first in order to play ringtone.
 * PARAMETERS
 *  currState       [IN]        Current state to switch session
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_switch_session(mmi_voip_call_state_enum currState)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currState)
    {
        case MMI_VOIP_OUTGOING_STATE:
            if (g_voip_cntx_p->call_list_info.numTotal == 1)
            {
                AlmDisableExpiryHandler();
            #ifdef __MMI_BT_PROFILE__
                mmi_profiles_bt_call_start_callback();
            #endif
                mmi_voip_call_status_req(UEM_CALL_SETUP); /* trigger uem to send headset key gpio detection */

                if (g_voip_cntx_p->call_list_info.inSession == FALSE)
                {
                    g_voip_cntx_p->call_list_info.inSession = TRUE;
                #ifndef __MMI_UCM__                  
                    mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_VOIP); /* set mdi speech mode on */
                #else
                    mmi_voip_ucm_session_ind(MDI_AUDIO_SPEECH_APP_ID_VOIP, TRUE);
                #endif
                }
            }
            break;
        case MMI_VOIP_INCOMING_STATE:
            if (g_voip_cntx_p->call_list_info.numTotal == 1)
            {
                AlmDisableExpiryHandler();
            #ifdef __MMI_BT_PROFILE__
                mmi_profiles_bt_call_start_callback();
            #endif
                mmi_voip_call_status_req(UEM_CALL_SETUP); /* trigger uem to send headset key gpio detection */
            }
            break;
        case MMI_VOIP_ACTIVE_STATE:
            if (g_voip_cntx_p->call_list_info.inSession == FALSE)
            {
                g_voip_cntx_p->call_list_info.inSession = TRUE;
            #ifndef __MMI_UCM__            
                mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_VOIP); /* set mdi speech mode on */
            #else
                mmi_voip_ucm_session_ind(MDI_AUDIO_SPEECH_APP_ID_VOIP, TRUE);
            #endif
            }
            break;
        case MMI_VOIP_IDLE_STATE:
            /* incoming call needs to play ringtone, so mdi session should stop first. 
               when accepting call, mdi session should not stop */
            if ((g_voip_cntx_p->call_list_info.numTotal == 1) && 
                (mmi_voip_get_incoming_call_id() != -1) && 
                (g_voip_cntx_p->call_list_info.processCId == -1))
            {
                if (g_voip_cntx_p->call_list_info.inSession == TRUE)
                {
                #ifndef __MMI_UCM__
                    mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_VOIP); /* set mdi speech mode off */
                #else
                    mmi_voip_ucm_session_ind(MDI_AUDIO_SPEECH_APP_ID_VOIP, FALSE);
                #endif
                    g_voip_cntx_p->call_list_info.inSession = FALSE;
                }
            }
            else if (g_voip_cntx_p->call_list_info.numTotal == 0)
            {
                if (g_voip_cntx_p->call_misc_info.isMute == TRUE)
                {
                    g_voip_cntx_p->call_misc_info.isMute = FALSE;
                    MuteOffMicrophone();
                    HideStatusIcon(STATUS_ICON_MUTE);
                    UpdateStatusIcons();
                }
                if (g_voip_cntx_p->call_misc_info.isLoud == TRUE)
                {
                    g_voip_cntx_p->call_misc_info.isLoud = FALSE;
                    DisbleHandsFree();
                    SetLoudSpeaker(FALSE);
                }

                if (g_voip_cntx_p->call_list_info.processCId == -1) /* when dialing call, do not reset misc structure */
                {
                    /* reset misc structure to prevent misuse by next call */
                    memset(&g_voip_cntx_p->call_misc_info, 0, sizeof(mmi_voip_call_misc_struct));
                    g_voip_cntx_p->call_misc_info.isDtmf = TRUE;
                }

                if (g_voip_cntx_p->call_list_info.inSession == TRUE)
                {
                #ifndef __MMI_UCM__
                    mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_VOIP); /* set mdi speech mode off */
                #else
                    mmi_voip_ucm_session_ind(MDI_AUDIO_SPEECH_APP_ID_VOIP, FALSE);
                #endif
                    g_voip_cntx_p->call_list_info.inSession = FALSE;
                }

                mmi_voip_call_status_req(UEM_CALL_DISCONNECT); /* trigger uem to send headset key gpio detection */
            #ifdef __MMI_BT_PROFILE__
                /* do not turn off sco link in case gsm needs to turn on again */
                if (GetTotalCallCount() == 0)
                {
                    PRINT_INFORMATION("\n[mmi_voip_switch_session] SCO Ends\n");
                    mmi_profiles_bt_call_end_callback();
                }
                else
                {
                    PRINT_INFORMATION("\n[mmi_voip_switch_session] SCO Not Ends\n");
                }
            #endif
                mdi_audio_resume_background_play(); /* resume audio */
                AlmEnableExpiryHandler();
            }
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_create_rtp
 * DESCRIPTION
 *  Create RTP.
 * PARAMETERS
 *  sdp     [IN]        Sdp information passed by voip cc
 * RETURNS
 *  rtp handle that is given by voip media
 *****************************************************************************/
S32 mmi_voip_create_rtp(voip_sdp_struct *sdp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rtpHandle = 0, profIndex = 0, i = 0;
    U16 sdpCodec = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;

    if (sdp->num_codec == 0)
    {
        return -1;
    }

    rtpHandle = rtp_create(
                    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct,
                    sdp->local_addr,
                    sdp->remote_addr,
                    sdp->remote_rtp_port,
                    sdp->remote_rtcp_port,
                    sdp->local_rtp_port,
                    sdp->local_rtcp_port,
                    SOC_QOS_VOICE);
    if (rtpHandle < 0)
    {
        PRINT_INFORMATION("\n[mmi_voip_create_rtp] Create RTP Fail, RTP Handle: %d\n", rtpHandle);
        return -1;
    }

    rtp_set_payload_type(rtpHandle, sdp->local_payload_type[0]);
    if (sdp->sdp_status & VOIP_SDP_STATUS_IS_DTMF)
    {
        rtp_set_dtmf_payload_type(rtpHandle, sdp->dtmf_payload_type);
    }
	
    /* SRTP */
    if (g_voip_cntx_p->call_setting_info.saved_setting.srtp == 1)
    {
        rtp_set_srtp_param(rtpHandle, &sdp->crypto_info->crypto);
    }
    
    voip_set_ptime(rtpHandle, sdp->ptime);
    voip_set_maxptime(rtpHandle, sdp->maxptime);

    sdpCodec = sdp->codec[0];
    /* g7231 annexa */
    if ((sdp->codec[0] == VOIP_CODEC_G7231) && (sdp->g7231_annexa != VOIP_ANNEX_NONE))
    {
        switch (sdp->g7231_annexa)
        {
            case VOIP_ANNEX_NO:
                sdpCodec |= VOIP_CODEC_G7231_ANNEXA_PRESENT;
                break;
            case VOIP_ANNEX_YES:
                sdpCodec |= VOIP_CODEC_G7231_ANNEXA_PRESENT;
                sdpCodec |= VOIP_CODEC_G7231_ANNEXA;
                break;
            default:
                MMI_ASSERT(0); /* g7231_annexa should either VOIP_ANNEX_NO or VOIP_ANNEX_YES */
        }
    }

    /* g729 annexb */
    if ((sdp->codec[0] == VOIP_CODEC_G729) && (sdp->g729_annexb != VOIP_ANNEX_NONE))
    {
        switch (sdp->g729_annexb)
        {
            case VOIP_ANNEX_NO:
                sdpCodec |= VOIP_CODEC_G729_ANNEXB_PRESENT;
                break;
            case VOIP_ANNEX_YES:
                sdpCodec |= VOIP_CODEC_G729_ANNEXB_PRESENT;
                sdpCodec |= VOIP_CODEC_G729_ANNEXB;
                break;
            default:
                MMI_ASSERT(0); /* g729_annexb should either VOIP_ANNEX_NO or VOIP_ANNEX_YES */
        }
    }
    
    /* comfort noise */
    if (g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise == 0)
    {
        for (i = 0; i < VOIP_MAX_NUM_CODEC; i++)
        {
            if (sdp->codec[i] == VOIP_CODEC_CN)
            {
                sdpCodec |= VOIP_CODEC_CN;
                break;
            }
        }
    }
    rtp_voip_init(rtpHandle, sdpCodec, sdp->modeset[0]);
    PRINT_INFORMATION("\n[mmi_voip_create_rtp] Use to Lock Resource...Start");
    mdi_audio_speech_encode_start((S8)rtpHandle);
    mdi_audio_speech_encode_stop((S8)rtpHandle);
    mdi_audio_speech_decode_start((S8)rtpHandle);
    mdi_audio_speech_decode_stop((S8)rtpHandle);
    PRINT_INFORMATION("\n[mmi_voip_create_rtp] Use to Lock Resource...End");
    return rtpHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_close_rtp
 * DESCRIPTION
 *  Close RTP.
 * PARAMETERS
 *  rtpHandle       [IN]        Intended to close rtp handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_close_rtp(S32 rtpHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (voip_curr_voip_state((S8) rtpHandle))
    {
        case VOIP_ENCODE:
            mdi_audio_speech_encode_stop((S8) rtpHandle);
            break;
        case VOIP_DECODE:
            mdi_audio_speech_decode_stop((S8) rtpHandle);
            break;
        case VOIP_ENCODE_DECODE:
            mdi_audio_speech_encode_stop((S8) rtpHandle);
            mdi_audio_speech_decode_stop((S8) rtpHandle);
            break;
        default:
            break;
    }
    rtp_close((S8) rtpHandle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_switch_rtp
 * DESCRIPTION
 *  Switch RTP based on the current RTP direction in the call point of view.
 * PARAMETERS
 *  isSuspend       [IN]        Suspend all audio paths before action
 *  callId          [IN]        Call id
 *  dialogId        [IN]        Dialog id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_switch_rtp(MMI_BOOL isSuspend, S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    S32 i = 0, j = 0, rtpHandle = 0, rtpDirection = 0, numDialog = 0;
    MMI_BOOL isMixer = FALSE;
#ifdef __MMI_UCM__
    MMI_BOOL localSwitch = FALSE, remoteSwitch = FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset dtmf queue when rtp change in case the dtmf timer expiry 
       but rtp cannot allow to send dtmf anymore */
    StopTimer(VOIP_DTMF_TIMER);
    memset(&g_voip_cntx_p->dtmf_queue_info, 0, sizeof(mmi_voip_dtmf_queue_struct));
    
    if (callId != -1)
    {
        callIndex = mmi_voip_get_call_index(callId);
        if (dialogId != -1)
        {
            dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
            rtpHandle = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
            if (rtpHandle != -1)
            {
                numDialog = g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog;
                rtpDirection =
                    (isSuspend == TRUE) ? (VOIP_RTP_DIRECTION_INACTIVE) : (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].sdp_info.direction);
                if (numDialog == VOIP_MAX_NUM_DIALOG)
                {
                    isMixer = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].isMixer;
                    if ((rtpDirection == VOIP_RTP_DIRECTION_SENDRECV) && (isMixer == FALSE))
                    {
                    #ifndef __MMI_UCM__
                        mmi_voip_control_rtp(rtpHandle, rtpDirection);
                    #else
                        if (isSuspend == FALSE)
                        {
                            mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                            mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                        }
                    #endif /* __MMI_UCM__ */
                        mdi_audio_speech_mixer_add((S8) rtpHandle);
                        g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].isMixer = TRUE;
                    }
                    else if ((rtpDirection != VOIP_RTP_DIRECTION_SENDRECV) && (isMixer == TRUE))
                    {
                        mdi_audio_speech_mixer_remove((S8) rtpHandle);
                        g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].isMixer = FALSE;
                    #ifndef __MMI_UCM__
                        mmi_voip_control_rtp(rtpHandle, rtpDirection);
                    #else
                        if (isSuspend == FALSE)
                        {
                            mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                            mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                        }
                    #endif /* __MMI_UCM__ */
                    }
                    else
                    {
                    #ifndef __MMI_UCM__
                        mmi_voip_control_rtp(rtpHandle, rtpDirection);  /* remain the same */
                    #else
                        if (isSuspend == FALSE)
                        {
                            mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                            mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                        }
                    #endif /* __MMI_UCM__ */
                    }
                }
                else    /* not conference call */
                {
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].isMixer = FALSE;
                #ifndef __MMI_UCM__
                    mmi_voip_control_rtp(rtpHandle, rtpDirection);
                #else
                    if (isSuspend == FALSE)
                    {
                        mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                        mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                    }
                #endif /* __MMI_UCM__ */
                }
            }
        }
        else    /* dialogId == -1 */
        {
            for (i = 0; i < g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog; i++)
            {
                rtpHandle = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].rtpHandle;
                if (rtpHandle != -1)
                {
                    numDialog = g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog;
                    rtpDirection =
                        (isSuspend == TRUE) ? (VOIP_RTP_DIRECTION_INACTIVE) : (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].sdp_info.direction);
                    if (numDialog == VOIP_MAX_NUM_DIALOG)
                    {
                        isMixer = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].isMixer;
                        if ((rtpDirection == VOIP_RTP_DIRECTION_SENDRECV) && (isMixer == FALSE))
                        {
                        #ifndef __MMI_UCM__
                            mmi_voip_control_rtp(rtpHandle, rtpDirection);
                        #else
                            if (isSuspend == FALSE)
                            {
                                mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                                mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                            }
                        #endif /* __MMI_UCM__ */
                            mdi_audio_speech_mixer_add((S8) rtpHandle);
                            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].isMixer = TRUE;
                        }
                        else if ((rtpDirection != VOIP_RTP_DIRECTION_SENDRECV) && (isMixer == TRUE))
                        {
                            mdi_audio_speech_mixer_remove((S8) rtpHandle);
                            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].isMixer = FALSE;
                        #ifndef __MMI_UCM__
                            mmi_voip_control_rtp(rtpHandle, rtpDirection);
                        #else
                            if (isSuspend == FALSE)
                            {
                                mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                                mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                            }
                        #endif /* __MMI_UCM__ */
                        }
                        else
                        {
                        #ifndef __MMI_UCM__
                            mmi_voip_control_rtp(rtpHandle, rtpDirection);      /* remain the same */
                        #else
                            if (isSuspend == FALSE)
                            {
                                mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                                mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                            }
                        #endif /* __MMI_UCM__ */
                        }
                    }
                    else    /* not conference call */
                    {
                        g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].isMixer = FALSE;
                    #ifndef __MMI_UCM__
                        mmi_voip_control_rtp(rtpHandle, rtpDirection);
                    #else
                        if (isSuspend == FALSE)
                        {
                            mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                            mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                        }
                    #endif /* __MMI_UCM__ */
                    }
                }
            }
        }
    }
    else    /* callId == -1 */
    {
        for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
        {
            for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
            {
                rtpHandle = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].rtpHandle;
                if (rtpHandle != -1)
                {
                    numDialog = g_voip_cntx_p->call_list_info.call_info[i].numDialog;
                    rtpDirection =
                        (isSuspend == TRUE) ? (VOIP_RTP_DIRECTION_INACTIVE) : (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].sdp_info.direction);
                    if (numDialog == VOIP_MAX_NUM_DIALOG)
                    {
                        isMixer = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].isMixer;
                        if ((rtpDirection == VOIP_RTP_DIRECTION_SENDRECV) && (isMixer == FALSE))
                        {
                        #ifndef __MMI_UCM__
                            mmi_voip_control_rtp(rtpHandle, rtpDirection);
                        #else
                            if (isSuspend == FALSE)
                            {
                                mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                                mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                            }
                        #endif /* __MMI_UCM__ */
                            mdi_audio_speech_mixer_add((S8) rtpHandle);
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].isMixer = TRUE;
                        }
                        else if ((rtpDirection != VOIP_RTP_DIRECTION_SENDRECV) && (isMixer == TRUE))
                        {
                            mdi_audio_speech_mixer_remove((S8) rtpHandle);
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].isMixer = FALSE;
                        #ifndef __MMI_UCM__
                            mmi_voip_control_rtp(rtpHandle, rtpDirection);
                        #else
                            if (isSuspend == FALSE)
                            {
                                mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                                mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                            }
                        #endif /* __MMI_UCM__ */
                        }
                        else
                        {
                        #ifndef __MMI_UCM__
                            mmi_voip_control_rtp(rtpHandle, rtpDirection);      /* remain the same */
                        #else
                            if (isSuspend == FALSE)
                            {
                                mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                                mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                            }
                        #endif /* __MMI_UCM__ */
                        }
                    }
                    else    /* not conference call */
                    {
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].isMixer = FALSE;
                    #ifndef __MMI_UCM__
                        mmi_voip_control_rtp(rtpHandle, rtpDirection);
                    #else
                        if (isSuspend == FALSE)
                        {
                            mmi_voip_ucm_get_speech_direction(rtpDirection, &localSwitch, &remoteSwitch);
                            mmi_voip_ucm_speech_ind(rtpHandle, localSwitch, remoteSwitch);
                        }
                    #endif /* __MMI_UCM__ */
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_control_rtp
 * DESCRIPTION
 *  Switch RTP based on the current RTP direction in the RTP point of view.
 * PARAMETERS
 *  rtpHandle           [IN]        Rtp handle
 *  rtpDirection        [IN]        Rtp direction
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_control_rtp(S32 rtpHandle, S32 rtpDirection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rtpDirection)
    {
        case VOIP_RTP_DIRECTION_SENDRECV:                   /*  send and receive */
            switch (voip_curr_voip_state((S8) rtpHandle))   /* ensure not to set encoding / decoding twice */
            {
                case VOIP_IDLE:
                    mdi_audio_speech_encode_start((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
                    mdi_audio_speech_decode_start((S8) rtpHandle);                    
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
                    break;
                case VOIP_ENCODE:
                    mdi_audio_speech_decode_start((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
                    break;
                case VOIP_DECODE:
                    mdi_audio_speech_encode_start((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
                    break;
                case VOIP_ENCODE_DECODE:
                    break;
                default:
                    MMI_ASSERT(0);
                    break;
            }
            break;
        #if 0   /* implement send only as inactive */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
        case VOIP_RTP_DIRECTION_RECVONLY:                   /*  receive only */
            switch (voip_curr_voip_state((S8) rtpHandle))   /* ensure not to set encoding / decoding twice */
            {
                case VOIP_IDLE:
                    mdi_audio_speech_decode_start((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
                    break;
                case VOIP_ENCODE:
                    mdi_audio_speech_encode_stop((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
                    mdi_audio_speech_decode_start((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
                    break;
                case VOIP_DECODE:
                    break;
                case VOIP_ENCODE_DECODE:
                    mdi_audio_speech_encode_stop((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
                    break;
                default:
                    MMI_ASSERT(0);
                    break;
            }
            break;
        case VOIP_RTP_DIRECTION_SENDONLY:                   /*  send only */
        case VOIP_RTP_DIRECTION_INACTIVE:                   /*  rtp session suspends */
            switch (voip_curr_voip_state((S8) rtpHandle))   /* ensure not to set encoding / decoding twice */
            {
                case VOIP_IDLE:
                    break;
                case VOIP_ENCODE:
                    mdi_audio_speech_encode_stop((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
                    break;
                case VOIP_DECODE:
                    mdi_audio_speech_decode_stop((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
                    break;
                case VOIP_ENCODE_DECODE:
                    mdi_audio_speech_encode_stop((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
                    mdi_audio_speech_decode_stop((S8) rtpHandle);
                    mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
                    break;
                default:
                    MMI_ASSERT(0);
                    break;
            }
            break;
        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_remove_mixer_before_close
 * DESCRIPTION
 *  Remove mixer if any before closeing RTP.
 * PARAMETERS
 *  callIndex       [IN]        Call index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_remove_mixer_before_close(S32 callIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
    {
        if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].isMixer == TRUE)
        {
            mdi_audio_speech_mixer_remove((S8) g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].rtpHandle);
            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].isMixer = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dtmf_key_down
 * DESCRIPTION
 *  Push DTMF event (start / stop) to DTMF queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dtmf_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0, keyType = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &keyType);

    if (g_voip_cntx_p->dtmf_queue_info.timerStatus == 0) /* no timer */
    {
        mmi_voip_send_dtmf_start(keyCode);
        StartTimer(VOIP_DTMF_TIMER, (MMI_VOIP_GENERAL_TIMEOUT * 0.05), mmi_voip_pop_dtmf_queue);
        g_voip_cntx_p->dtmf_queue_info.timerStatus = 1;
    }
    else
    {
        mmi_voip_push_dtmf_queue(keyCode);
    }
#ifndef __MMI_UCM__
    wgui_execute_key_handler(keyCode, keyType);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dtmf_key_up
 * DESCRIPTION
 *  Pop DTMF event (start / stop) from DTMF queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dtmf_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0, keyType = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &keyType);

    if (g_voip_cntx_p->dtmf_queue_info.timerStatus == 0) /* no timer */
    {
        mmi_voip_send_dtmf_stop();
        StartTimer(VOIP_DTMF_TIMER, (MMI_VOIP_GENERAL_TIMEOUT * 0.05), mmi_voip_pop_dtmf_queue);
        g_voip_cntx_p->dtmf_queue_info.timerStatus = 1;
    }
    else
    {
        mmi_voip_push_dtmf_queue(255);
    }
#ifndef __MMI_UCM__
    wgui_execute_key_handler(keyCode, keyType);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_push_dtmf_queue
 * DESCRIPTION
 *  Push DTMF event (start / stop) to DTMF queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_push_dtmf_queue(U16 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->dtmf_queue_info.dtmfQueue[g_voip_cntx_p->dtmf_queue_info.currPos] = keyCode;
    g_voip_cntx_p->dtmf_queue_info.currPos++;
    // MMI_ASSERT(g_voip_cntx_p->dtmf_queue_info.currPos < MMI_VOIP_DTMF_LEN * ENCODING_LENGTH);
    if (g_voip_cntx_p->dtmf_queue_info.currPos >= MMI_VOIP_DTMF_LEN * ENCODING_LENGTH)
    {
        PRINT_INFORMATION("\n[mmi_voip_push_dtmf_queue] DTMF Queue Exhausts!\n");
        if (g_voip_cntx_p->dtmf_queue_info.dtmfQueue[0] != 255)
        {
            if (keyCode != 255)
            {
                PRINT_INFORMATION("\n[mmi_voip_push_dtmf_queue] First Start, Last Start, First Position Becomes %d\n", keyCode);
                g_voip_cntx_p->dtmf_queue_info.currPos = 0;
                g_voip_cntx_p->dtmf_queue_info.dtmfQueue[g_voip_cntx_p->dtmf_queue_info.currPos] = keyCode;
                g_voip_cntx_p->dtmf_queue_info.currPos++;
            }
            else
            {
                PRINT_INFORMATION("\n[mmi_voip_push_dtmf_queue] First Start, Last Stop, Current Position Becomes 0\n");
                g_voip_cntx_p->dtmf_queue_info.currPos = 0;
            }
        }
        else
        {
            if (keyCode != 255)
            {
                PRINT_INFORMATION("\n[mmi_voip_push_dtmf_queue] First Stop, Last Start, Second Position Becomes %d\n", keyCode);
                g_voip_cntx_p->dtmf_queue_info.currPos = 1;
                g_voip_cntx_p->dtmf_queue_info.dtmfQueue[g_voip_cntx_p->dtmf_queue_info.currPos] = keyCode;
                g_voip_cntx_p->dtmf_queue_info.currPos++;
            }
            else
            {
                PRINT_INFORMATION("\n[mmi_voip_push_dtmf_queue] First Stop, Last Stop, Cureent Position Becomes 1\n");
                g_voip_cntx_p->dtmf_queue_info.currPos = 1;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_pop_dtmf_queue
 * DESCRIPTION
 *  Pop DTMF event (start / stop) from DTMF queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_pop_dtmf_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_voip_pop_dtmf_queue] Timer Expiry! Current Position: %d, Key Code: %d\n", g_voip_cntx_p->dtmf_queue_info.currPos, g_voip_cntx_p->dtmf_queue_info.dtmfQueue[0]);
    if (g_voip_cntx_p->dtmf_queue_info.currPos != 0)
    {
        if (g_voip_cntx_p->dtmf_queue_info.dtmfQueue[0] != 255)
        {
            mmi_voip_send_dtmf_start(g_voip_cntx_p->dtmf_queue_info.dtmfQueue[0]);            
        }
        else
        {
            mmi_voip_send_dtmf_stop();
        }
        for (i = 0; i < g_voip_cntx_p->dtmf_queue_info.currPos; i++)
        {
            g_voip_cntx_p->dtmf_queue_info.dtmfQueue[i] = g_voip_cntx_p->dtmf_queue_info.dtmfQueue[i + 1];
        }        
        g_voip_cntx_p->dtmf_queue_info.currPos--;        
        StartTimer(VOIP_DTMF_TIMER, (MMI_VOIP_GENERAL_TIMEOUT * 0.05), mmi_voip_pop_dtmf_queue);
        g_voip_cntx_p->dtmf_queue_info.timerStatus = 1;
    }
    else
    {
        g_voip_cntx_p->dtmf_queue_info.timerStatus = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_send_dtmf_start
 * DESCRIPTION
 *  Send DTMF sound to remote side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_send_dtmf_start(U16 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, currhiliteTab = 0, numDialog = 0, rtpHandle[VOIP_MAX_NUM_DIALOG];
    // U16 keyCode = 0, keyType = 0;
    MMI_BOOL outbandDtmf = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    numDialog = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog;

    for (i = 0; i < numDialog; i++)
    {
        /* only send dtmf to the dialog that encoding is started */
        if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].sdp_info.direction == VOIP_RTP_DIRECTION_SENDRECV)
        {
            rtpHandle[i] = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].rtpHandle;
            outbandDtmf = (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].sdp_info.sdp_status & VOIP_SDP_STATUS_IS_DTMF);
        }
        else
        {
            rtpHandle[i] = -1;
        }
    }
    if (numDialog == VOIP_MAX_NUM_DIALOG)
    {
        /* always send inband dtmf for conference call in case one dialog is inband and the other is outband */
        outbandDtmf = FALSE;
    }    

    PRINT_INFORMATION("\n[mmi_voip_send_dtmf_start] Local DTMF: %d, Remote DTMF: %d\n", g_voip_cntx_p->call_setting_info.saved_setting.dtmf, outbandDtmf);
    // GetkeyInfo(&keyCode, &keyType);
    if (mmi_voip_validate_dtmf(keyCode))
    {
        if (g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_TYPE_NONE)
        {
            /* do nothing */
        }
        else if ((g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_IN_BAND) || 
                 (outbandDtmf == FALSE)) /* remote doesn't support outband dtmf */
        {
            if (g_voip_cntx_p->call_misc_info.isMute == FALSE)
            {
                MuteOnMicrophone(); /* temporarily turn off microphone */
            }
            for (i = 0; i < numDialog; i++)
            {
                if (rtpHandle[i] != -1)
                {
                    mdi_audio_speech_dtmf_start(
                        rtpHandle[i],
                        mmi_voip_get_dtmf_keycode_enum(&keyCode),
                        RTP_DTMF_TYPE_INBAND);
                }
            }
        }
        /* send outband dtmf only if both local and remote support outband dtmf */
        else if ((g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_OUT_OF_BAND) && 
                 (outbandDtmf == TRUE))
        {
            if (g_voip_cntx_p->call_misc_info.isMute == FALSE)
            {
                MuteOnMicrophone(); /* temporarily turn off microphone */
            }
            for (i = 0; i < numDialog; i++)
            {
                if (rtpHandle[i] != -1)
                {
                    mdi_audio_speech_dtmf_start(
                        rtpHandle[i],
                        mmi_voip_get_dtmf_keycode_enum(&keyCode),
                        RTP_DTMF_TYPE_RFC2833);
                }
            }
        }
    }
    // wgui_execute_key_handler(keyCode, keyType);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_send_dtmf_stop
 * DESCRIPTION
 *  Stop DTMF sound to remote side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_send_dtmf_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, currhiliteTab = 0, numDialog = 0, rtpHandle[VOIP_MAX_NUM_DIALOG];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    numDialog = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].numDialog;

    for (i = 0; i < numDialog; i++)
    {
        /* only send dtmf to the dialog that encoding is started */
        if (g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].sdp_info.direction == VOIP_RTP_DIRECTION_SENDRECV)
        {
            rtpHandle[i] = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].dialog_info[i].rtpHandle;
        }
        else
        {
            rtpHandle[i] = -1;
        }
    } 

    if (g_voip_cntx_p->call_setting_info.saved_setting.dtmf != VOIP_DTMF_TYPE_NONE)
    {
        if (g_voip_cntx_p->call_misc_info.isMute == FALSE)
        {
            MuteOffMicrophone();
        }
        for (i = 0; i < numDialog; i++)
        {
            if (rtpHandle[i] != -1)
            {
                mdi_audio_speech_dtmf_stop(rtpHandle[i]);
            }
        }
    }
    else    /* g_voip_cntx_p->call_setting_info.saved_setting.dtmf == VOIP_DTMF_TYPE_NONE */
    {
        /* do nothing */
    }
}
#endif /* __MMI_VOIP__ */


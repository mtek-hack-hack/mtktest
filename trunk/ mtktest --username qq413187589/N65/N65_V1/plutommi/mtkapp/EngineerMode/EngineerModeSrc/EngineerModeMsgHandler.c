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
 * EngineerModeMsgHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode message handler
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************/
/*************************  Header Files *************************/
/*****************************************************************/

#include "MMI_features.h"

#ifdef __MMI_ENGINEER_MODE__    

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

#include "wgui.h"
#include "IdleAppProt.h"
#include "ProtocolEvents.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MiscFunctions.h"
#include "TaskInit.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
#include "EngineerModeTracer.h"
#include "NetworkSetupGProt.h"
#include "wgui_status_icons.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "CommonScreens.h"

#include "device.h"
#include "uart_sw.h"    
#include "med_struct.h"
#include "custom_util.h"
#include "lcd_sw.h"
#include "resource_audio.h"

#ifdef __MTK_TARGET__
#include "l1audio.h"
#endif 

#ifdef __TST_MODULE__
#include "tst.h"        /* TST extern functions */
#endif /* __TST_MODULE__ */ 

#include "l4c_common_enum.h"

/*****************************************************************/
/****************  Structure / Variables Declaration *************/
/*****************************************************************/

/* gprs */
#ifdef __MOD_TCM__
kal_uint8 g_gprs_pdp_idx = 0;
kal_bool g_gprs_set_minqos_required = 0;

#ifdef __R99__
static const kal_uint16 pdp_context_idx[EM_GPRS_PDP_CONTEXT_MAX_NUM][2][18] = 
{
    1, 2, 4, 5, 5, 16, 4, 72, 72, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context1] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context2] */
    1, 2, 4, 5, 5, 16, 4, 72, 72, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context3] */
    1, 2, 4, 3, 6, 16, 4, 88, 88, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context4] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context5] */
    1, 2, 4, 5, 6, 16, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context6] */
    1, 2, 4, 5, 6, 16, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context7] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context8] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context9] */
    1, 2, 4, 5, 5, 16, 4, 72, 72, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context10] */
    1, 2, 4, 2, 5, 16, 4, 72, 72, 0, 0, 1, 150, 6, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context11] */
    1, 2, 4, 2, 5, 16, 4, 72, 72, 0, 0, 1, 150, 6, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context12] */
    1, 2, 4, 1, 5, 16, 4, 72, 72, 0, 0, 1, 150, 6, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context13] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context14] */
    1, 2, 1, 3, 7, 9, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* [PDP context15] */
    1, 2, 4, 5, 6, 17, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context 30] */
    1, 2, 4, 3, 7, 17, 4, 120, 120, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  /* [PDP context 31] */
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__)*/
};

#else /* __R99__ */ 
static const kal_uint16 pdp_context_idx[EM_GPRS_PDP_CONTEXT_MAX_NUM][2][6] = 
{
    1, 2, 4, 5, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context1] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context2] */
    1, 2, 4, 5, 5, 16, 0, 0, 4, 0, 2, 0,    /* [PDP context3] */
    1, 2, 4, 3, 6, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context4] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context5] */
    1, 2, 4, 5, 6, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context6] */
    1, 2, 4, 5, 6, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context7] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context8] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context9] */
    1, 2, 4, 5, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context10] */
    1, 2, 4, 2, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context11] */
    1, 2, 4, 2, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context12] */
    1, 2, 4, 1, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context13] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context14] */
    1, 2, 1, 3, 7, 9, 0, 0, 0, 0, 0, 0      /* [PDP context15] */
};
#endif /* __R99__ */ 

#endif /* __MOD_TCM__ */ 

static U8 EmSetUartMsgDepth = 0;
kal_bool UART_setting = 0;

static UART_PORT old_tst_port;
static UART_baudrate old_tst_baudrate;

#ifndef L4_NOT_PRESENT
static UART_PORT old_ps_port;
static UART_baudrate old_ps_baudrate;
#endif /* L4_NOT_PRESENT */ 


/*****************************************************************/
/******************  External functions / variables **************/
/*****************************************************************/
extern EM_GPRS_ACT_PDP_TYPE_ENUM EmGprsActivatePDPType; 

extern U8 currentHighlightIndex;
extern U8 g_em_set_uart_req_type;

extern U8 EmPortSetting;
extern U8 EmAppPortArray[EM_APP_MAX_NUM];
extern U8 EmAppBaudArray[EM_APP_MAX_NUM];
extern U32 EmUartPortTSTHighlight, EmUartBaudTSTHighlight;
extern U32 EmUartPortPSHighlight, EmUartBaudPSHighlight;
extern U32 EmUartPortCTIHighlight, EmUartBaudCTIHighlight;
extern U32 EmUartPortTSTL1Highlight, EmUartBaudTSTL1Highlight;

extern UART_PORT TST_PORT;
extern UART_baudrate TST_BAUDRATE;
extern kal_bool High_Speed_SIM;
extern U8 UART_POWER_SETTING;
extern U8 SWDBG_Profile;

#ifndef L4_NOT_PRESENT
extern UART_PORT PS_UART_PORT;
extern UART_baudrate PS_BAUDRATE;
#endif /* L4_NOT_PRESENT */ 

extern EmAudioParamStruct AudioParameter;

/*****************************************************************/
/********************  Code Body (NetworkInfo) *******************/
/*****************************************************************/

/*****************************************************************************
 * FUNCTION
 *  EngineerModeStartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStartRes(void *inMsg)
{
#if defined(__EM_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_start_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeStatusUpdate(rsp_p->mod_id, rsp_p->info_request);
        EngineerModeSuccessNotice(EM_UPDATE_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_UPDATE_ERROR_TEXT);
    }
    DeleteScreenIfPresent(EM_NETWORK_INFO_MENU_SCR);

#endif 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStatusInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStatusInd(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__EM_MODE__)
    EngineerModeStatusIndHdlr(inMsg);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModePlayAudioReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModePlayAudioReq(U8 index, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_play_audio_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_play_audio_req_struct));
    switch (type)
    {
        case AUD_MIDI:
            msg_p->sound_id = index + MIN_MIDI_ID;
            break;
        case AUD_IMELODY:
            msg_p->sound_id = index + MIN_RING_TONE_ID;
            break;
        case AUD_SOUND:
            msg_p->sound_id = index + MIN_SND_ID;
            break;
        default:
            msg_p->sound_id = index + MIN_MIDI_ID;
            break;
    }
    msg_p->style = DEVICE_AUDIO_PLAY_INFINITE;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_PLAY_AUDIO_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStopAudioReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStopAudioReq(U8 index, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_stop_audio_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_stop_audio_req_struct));
    switch (type)
    {
        case AUD_MIDI:
            msg_p->sound_id = index + MIN_MIDI_ID;
            break;
        case AUD_IMELODY:
            msg_p->sound_id = index + MIN_RING_TONE_ID;
            break;
        case AUD_SOUND:
            msg_p->sound_id = index + MIN_SND_ID;
            break;
        default:
            msg_p->sound_id = index + MIN_MIDI_ID;
            break;
    }
    EngineerModeSendMsg(MSG_ID_MMI_EQ_STOP_AUDIO_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetVolumeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volumeType      [IN]        
 *  volumeLevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetVolumeReq(U8 volumeType, U8 volumeLevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (volumeType)
    {
        case MDI_VOLUME_CTN:
            TONE_SetOutputVolume(volumeLevel, 0);
            break;
        case MDI_VOLUME_KEY:
            KT_SetOutputVolume(volumeLevel, 0);
            break;
        case MDI_VOLUME_MIC:
            L1SP_SetMicrophoneVolume(volumeLevel);
            break;
        case MDI_VOLUME_FMR:
            Media_SetOutputVolume(volumeLevel, 0);
            break;
        case MDI_VOLUME_SPH:
            L1SP_SetOutputVolume(volumeLevel, 0);
            break;
        case MDI_VOLUME_SID:
            L1SP_SetSidetoneVolume(volumeLevel);
            break;
        case MDI_VOLUME_MEDIA:
            Media_SetOutputVolume(volumeLevel, 0);
            break;
        default:
            break;

    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetAudioProfileReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetAudioProfileReq(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EngineerModeGetAudioProfileRes, MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP);

    msg_p = OslConstructDataPtr(sizeof(mmi_eq_get_audio_profile_req_struct));
    msg_p->audio_prof_in.mode = mode;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetAudioProfileRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetAudioProfileRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_profile_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP);

    if (rsp_p->result)
    {
        EmUpdateAudioProfile(
            rsp_p->audio_prof_out.speech,
            rsp_p->audio_prof_out.keytone,
            rsp_p->audio_prof_out.melody,
            rsp_p->audio_prof_out.sound,
            rsp_p->audio_prof_out.mic,
            rsp_p->audio_prof_out.sidetone,
            rsp_p->audio_prof_out.tv_out_volume_gain,
            rsp_p->audio_prof_out.max_melody_volume_gain,
            rsp_p->audio_prof_out.melody_volume_gain_step
            );
    }
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetAudioProfileReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audioProfile        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetAudioProfileReq(void *audioProfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_profile_req_struct *msg_p;
    EmAudioProfileStruct *p = (EmAudioProfileStruct*) audioProfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EngineerModeSetAudioProfileRes, MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP);

    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_audio_profile_req_struct));
    msg_p->audio_prof.mode = p->mode;
    memcpy(msg_p->audio_prof.speech, p->speech, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.keytone, p->keytone, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.melody, p->melody, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.sound, p->sound, MAX_EM_VOLUME_LEVEL);
    memcpy(msg_p->audio_prof.mic, p->mic, MAX_EM_VOLUME_LEVEL);
    msg_p->audio_prof.sidetone = p->sidetone;
    memcpy(msg_p->audio_prof.tv_out_volume_gain, p->tvout, MAX_EM_VOLUME_LEVEL);
    msg_p->audio_prof.max_melody_volume_gain = p->vol_16_level_max_gain;
    msg_p->audio_prof.melody_volume_gain_step = p->vol_16_level_step;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetAudioProfileRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetAudioProfileRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_profile_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP);

    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetAudioParamReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetAudioParamReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EngineerModeGetAudioParamRes, MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP);

    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetAudioParamRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetAudioParamRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_audio_param_rsp_struct *rsp_p = (mmi_eq_get_audio_param_rsp_struct*) inMsg;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP);

    if (rsp_p->result)
    {
        /* Read debug info from NVRAM directly, not through message*/
        ReadValue(NVRAM_AUDIO_DEBUG_INFO1, &AudioParameter.debug_info[0], DS_DOUBLE, &error);
        ReadValue(NVRAM_AUDIO_DEBUG_INFO2, &AudioParameter.debug_info[4], DS_DOUBLE, &error);
        EmUpdateAudioParam((U8*) & (rsp_p->audio_para));
    }
    else
    {
        EngineerModeWarningNotice(EM_AUD_SET_ERROR_TEXT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetAudioParamReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audioParam      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetAudioParamReq(void *audioParam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_param_req_struct *msg_p;
    EmAudioParamStruct *p = (EmAudioParamStruct*) audioParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EngineerModeSetAudioParamRes, MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP);

    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_audio_param_req_struct));
    msg_p->audio_para.selected_FIR_output_index = p->selected_FIR_output_index;
    memcpy(msg_p->audio_para.speech_common_para, p->speech_common_para, sizeof(p->speech_common_para));
    memcpy(msg_p->audio_para.speech_mode_para, p->speech_mode_para, sizeof(p->speech_mode_para));
    msg_p->audio_para.max_swing = p->max_swing;

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ, msg_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetAudioParamRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetAudioParamRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_audio_param_rsp_struct *rsp_p = inMsg;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP);

    if (rsp_p->result)
    {
        /* Write debug info from NVRAM directly, not through message*/
        WriteValue(NVRAM_AUDIO_DEBUG_INFO1, &AudioParameter.debug_info[0], DS_DOUBLE, &error);
        WriteValue(NVRAM_AUDIO_DEBUG_INFO2, &AudioParameter.debug_info[4], DS_DOUBLE, &error);

#ifdef __MTK_TARGET__       
        /* Set debug info param to L1 directly. */
        L1Audio_SetDebugInfo(AudioParameter.debug_info);
#endif /* __MTK_TARGET__ */

        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
}

/* gprs */
#ifdef __MOD_TCM__
#ifdef __R99__


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActFillstruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_eqos_st     [?]         
 *  idx             [IN]        
 *  ismin           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void EngineerModeGprsActFillstruct(l4c_eqos_struct *l4c_eqos_st, kal_uint8 idx, kal_uint8 ismin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ismin != 0)
    {
        ismin = 1;
        l4c_eqos_st->qos_type = ATCI_MIN_QOS;
    }
    else
    {
        ismin = 0;
        l4c_eqos_st->qos_type = ATCI_REQ_QOS;
    }

    idx -= 1;

    if (idx > EM_GPRS_PDP_CONTEXT_MAX_NUM )
    {
        idx = 0;
    }

    if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        l4c_eqos_st->context_id = TCM_EM_PDP_CID_1;
    }
    else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY || EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
    {
        l4c_eqos_st->context_id = TCM_EM_PDP_CID_2;
    }
    else
        ASSERT(0);

    l4c_eqos_st->traffic_class = pdp_context_idx[idx][ismin][6];
    l4c_eqos_st->delivery_order = pdp_context_idx[idx][ismin][11];
    l4c_eqos_st->delivery_of_err_sdu = pdp_context_idx[idx][ismin][15];
    l4c_eqos_st->max_sdu_size = pdp_context_idx[idx][ismin][12];
    l4c_eqos_st->max_bitrate_up_lnk = pdp_context_idx[idx][ismin][7];
    l4c_eqos_st->max_bitrate_down_lnk = pdp_context_idx[idx][ismin][8];
    l4c_eqos_st->residual_bit_err_rate = pdp_context_idx[idx][ismin][14];
    l4c_eqos_st->sdu_err_ratio = pdp_context_idx[idx][ismin][13];
    l4c_eqos_st->transfer_delay = pdp_context_idx[idx][ismin][16];
    l4c_eqos_st->traffic_hndl_priority = pdp_context_idx[idx][ismin][17];
    l4c_eqos_st->guarntd_bit_rate_up_lnk = pdp_context_idx[idx][ismin][9];
    l4c_eqos_st->guarntd_bit_rate_down_lnk = pdp_context_idx[idx][ismin][10];
}
#else /* __R99__ */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActFillstruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_qos_st      [?]         
 *  idx             [IN]        
 *  ismin           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void EngineerModeGprsActFillstruct(l4c_qos_struct *l4c_qos_st, kal_uint8 idx, kal_uint8 ismin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ismin != 0)
    {
        ismin = 1;
        l4c_qos_st->qos_type = ATCI_MIN_QOS;
    }
    else
    {
        ismin = 0;
        l4c_qos_st->qos_type = ATCI_REQ_QOS;
    }

    idx -= 1;
    /* Lisen 0906 */
    if (idx > EM_GPRS_PDP_CONTEXT_MAX_NUM )
    {
        idx = 0;
    }

    if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        l4c_qos_st->context_id = TCM_EM_PDP_CID_1;
    }
    else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY || EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
    {
        l4c_qos_st->context_id = TCM_EM_PDP_CID_2;
    }
    else
        ASSERT(0);

    l4c_qos_st->delay_class = pdp_context_idx[idx][ismin][2];
    l4c_qos_st->reliability_class = pdp_context_idx[idx][ismin][3];
    l4c_qos_st->peak_throughput = pdp_context_idx[idx][ismin][4];
    l4c_qos_st->precedence_class = pdp_context_idx[idx][ismin][1];
    l4c_qos_st->mean_throughput = pdp_context_idx[idx][ismin][5];

}

#endif /* __R99__ */ 
#endif /* __MOD_TCM__ */ 

/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActivatePDPContext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdp_idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsActivatePDPContext(kal_uint8 pdp_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        mmi_ps_set_definition_req_struct *msg_p;    
        
        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_definition_req_struct));
        msg_p->pdp.context_id = TCM_EM_PDP_CID_1;  /* 1st PDP */
    #if defined(__R99__) && defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__R99__) && defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */
        {
            msg_p->pdp.apn_length = 12;
            kal_sprintf((kal_char*) msg_p->pdp.apn, "%s", "smg7.etsi.fr");
            msg_p->pdp.dcomp_algo = 0;
            msg_p->pdp.hcomp_algo = 0;
            msg_p->pdp.pdp_type = IPV4_ADDR_TYPE;
            msg_p->pdp.pdp_addr_len = IPV4_ADDR_LEN;
            msg_p->pdp.addr_val[0] = 192;
            msg_p->pdp.addr_val[1] = 168;
            msg_p->pdp.addr_val[2] = 1;
            msg_p->pdp.addr_val[3] = 1;
        }
        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_DEFINITION_REQ, msg_p, NULL);
    }
    else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
    {
        mmi_ps_set_definition_req_struct *msg_p;    
          
        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_definition_req_struct));
        msg_p->pdp.context_id = TCM_EM_PDP_CID_2;  /* 2nd PDP */
    #if defined(__R99__) && defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__R99__) && defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */
        {     
            msg_p->pdp.apn_length = 12;
            kal_sprintf((kal_char*) msg_p->pdp.apn, "%s", "smg7.etsi.fr");
            msg_p->pdp.dcomp_algo = 0;
            msg_p->pdp.hcomp_algo = 0;
            msg_p->pdp.pdp_type = IPV4_ADDR_TYPE;
            msg_p->pdp.pdp_addr_len = IPV4_ADDR_LEN;
            msg_p->pdp.addr_val[0] = 192;
            msg_p->pdp.addr_val[1] = 168;
            msg_p->pdp.addr_val[2] = 1;
            msg_p->pdp.addr_val[3] = 1;
        }
        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_DEFINITION_REQ, msg_p, NULL);
    }
    else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY)
    {
        mmi_ps_set_sec_definition_req_struct *msg_p;    
        
        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_definition_req_struct));
        msg_p->pdp.context_id = TCM_EM_PDP_CID_2;  /* 2nd PDP */
        msg_p->pdp.prim_context_id = 2;  
        msg_p->pdp.dcomp_algo= 0;
        msg_p->pdp.hcomp_algo= 0;
        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ, msg_p, NULL);          
    }
    else
        ASSERT(0);

#endif /* __MOD_TCM__ */ 

#ifndef __MTK_TARGET__
    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSetDefinitionRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSetDefinitionRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_set_definition_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == KAL_FALSE)
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
    else
    {

    #ifdef __R99__
        mmi_ps_set_eqos_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_eqos_req_struct));
        msg_p->qos_type = ATCI_REQ_QOS;
        EngineerModeGprsActFillstruct(&msg_p->min, g_gprs_pdp_idx, 0);

        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_EQOS_REQ, msg_p, NULL);
    #else /* __R99__ */ 
        mmi_ps_set_qos_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_qos_req_struct));
        msg_p->qos_type = ATCI_REQ_QOS;
        EngineerModeGprsActFillstruct(&msg_p->min, g_gprs_pdp_idx, 0);

        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_QOS_REQ, msg_p, NULL);
    #endif /* __R99__ */ 
    }
#endif /* __MOD_TCM__ */ 
}

#ifdef __R99__


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSetEQosRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSetEQosRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_set_eqos_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == KAL_FALSE)
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
        return;
    }
    /* Joseph: Do not set min QoS here. Set Min QoS manually from CATCHER */
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
#endif /* 0 */ 
    {
        /* Send ACTIVATE Request */
        mmi_ps_act_test_req_struct *msg_p;

        /* kal_uint8 qos_type; */

        msg_p = OslConstructDataPtr(sizeof(mmi_ps_act_test_req_struct));
        msg_p->opcode = TCM_PDP_ACTIVATE;

        if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
        {
            msg_p->cid = TCM_EM_PDP_CID_1;  /* 1st PDP */
        }
        else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY || EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
        {
            msg_p->cid = TCM_EM_PDP_CID_2;  /* 2nd PDP */
        }    
        else
            ASSERT(0);

        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_ACT_TEST_REQ, msg_p, NULL);
    }
#endif /* __MOD_TCM__ */ 
}

#endif /* __R99__ */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSetQosRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSetQosRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_set_qos_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == KAL_FALSE)
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
        return;
    }

    /* Joseph: Do not set min QoS here. Set Min QoS manually from CATCHER */
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
#endif /* 0 */ 
    {
        /* Send ACTIVATE Request */
        mmi_ps_act_test_req_struct *msg_p;

        /* kal_uint8 qos_type; */

        msg_p = OslConstructDataPtr(sizeof(mmi_ps_act_test_req_struct));
        msg_p->opcode = TCM_PDP_ACTIVATE;

        if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
        {
            msg_p->cid = TCM_EM_PDP_CID_1;  /* 1st PDP */
        }
        else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY || EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
        {
            msg_p->cid = TCM_EM_PDP_CID_2;  /* 2nd PDP */
        }    
        else
            ASSERT(0);

        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_ACT_TEST_REQ, msg_p, NULL);
    }
#endif /* __MOD_TCM__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActTestRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsActTestRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_act_test_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
#endif /* __MOD_TCM__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsAttachReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsAttachReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__

    mmi_nw_set_attach_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha0120 */
    SetProtocolEventHandler(EngineerModeGprsAttachRes, MSG_ID_MMI_NW_SET_ATTACH_RSP);

    msg_p = OslConstructDataPtr(sizeof(mmi_nw_set_attach_req_struct));
    msg_p->type = RAC_PS;
    msg_p->opcode = RAC_ATTACH;
    msg_p->is_poweroff = KAL_FALSE;

    EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_NW_SET_ATTACH_REQ, msg_p, NULL);

#endif /* __MOD_TCM__ */ /* __MOD_TCM */

#ifndef __MTK_TARGET__
    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsAttachRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsAttachRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    //micha0120 begin
    //L4 would send indication to change gprs status using msg_id_mmi_ps_gprs_status_update_ind
    mmi_nw_set_attach_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_NW_SET_ATTACH_RSP);
    
    if (rsp_p->result == MMI_TRUE)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
    /* micha0120 end */
#endif /* __MOD_TCM__ */ /* __MOD_TCM */
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsDeactivatePDPReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsDeactivatePDPReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_act_test_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_ps_act_test_req_struct));
    msg_p->opcode = TCM_PDP_DEACTIVATE;

    if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        msg_p->cid = TCM_EM_PDP_CID_1;  /* 1st PDP */
    }
    else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY || EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
    {
        msg_p->cid = TCM_EM_PDP_CID_2;  /* 2nd PDP */
    }    
    else
        ASSERT(0);

    EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_ACT_TEST_REQ, msg_p, NULL);
#endif /* __MOD_TCM__ */ /* __MOD_TCM */

#ifndef __MTK_TARGET__
    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsDeactivatePDPRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsDeactivatePDPRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_act_test_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
#endif /* __MOD_TCM__ */ /* __MOD_TCM */
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSendDataReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSendDataReq(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_send_data_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_ps_send_data_req_struct));

    if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        msg_p->cid = TCM_EM_PDP_CID_1;  /* 1st PDP */
    }
    else if (EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY  || EmGprsActivatePDPType == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
    {
        msg_p->cid = TCM_EM_PDP_CID_2;  /* 2nd PDP */
    }    
    else
        ASSERT(0);
    
    msg_p->size = size;

    EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SEND_DATA_REQ, msg_p, NULL);
#endif /* __MOD_TCM__ */ /* __MOD_TCM */

#ifndef __MTK_TARGET__
    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSendDataRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSendDataRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_send_data_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
#endif /* __MOD_TCM__ */ /* __MOD_TCM */
}


/*****************************************************************************
 * FUNCTION
 *  EM_GetBaudRateByIdx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 EM_GetBaudRateByIdx(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (idx)
    {
        case 0:
            return UART_BAUD_AUTO;
        case 1:
            return UART_BAUD_75;
        case 2:
            return UART_BAUD_150;
        case 3:
            return UART_BAUD_300;
        case 4:
            return UART_BAUD_600;
        case 5:
            return UART_BAUD_1200;
        case 6:
            return UART_BAUD_2400;
        case 7:
            return UART_BAUD_4800;
        case 8:
            return UART_BAUD_7200;
        case 9:
            return UART_BAUD_9600;
        case 10:
            return UART_BAUD_14400;
        case 11:
            return UART_BAUD_19200;
        case 12:
            return UART_BAUD_28800;
        case 13:
            return UART_BAUD_33900;
        case 14:
            return UART_BAUD_38400;
        case 15:
            return UART_BAUD_57600;
        case 16:
            return UART_BAUD_115200;
        case 17:
            return UART_BAUD_230400;
        case 18:
            return UART_BAUD_460800;
        case 19:
            return UART_BAUD_921600;
        default:
            return UART_BAUD_115200;
    }

}


/*****************************************************************************
 * FUNCTION
 *  EM_GetIdxByBaudRate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  baud        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 EM_GetIdxByBaudRate(U32 baud)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (baud)
    {
        case UART_BAUD_AUTO:
            return 0;
        case UART_BAUD_75:
            return 1;
        case UART_BAUD_150:
            return 2;
        case UART_BAUD_300:
            return 3;
        case UART_BAUD_600:
            return 4;
        case UART_BAUD_1200:
            return 5;
        case UART_BAUD_2400:
            return 6;
        case UART_BAUD_4800:
            return 7;
        case UART_BAUD_7200:
            return 8;
        case UART_BAUD_9600:
            return 9;
        case UART_BAUD_14400:
            return 10;
        case UART_BAUD_19200:
            return 11;
        case UART_BAUD_28800:
            return 12;
        case UART_BAUD_33900:
            return 13;
        case UART_BAUD_38400:
            return 14;
        case UART_BAUD_57600:
            return 15;
        case UART_BAUD_115200:
            return 16;
        case UART_BAUD_230400:
            return 17;
        case UART_BAUD_460800:
            return 18;
        case UART_BAUD_921600:
            return 19;
        default:
            return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetUartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ConfApp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetUartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EngineerModeGetUartRes, MSG_ID_EM_GET_UART_RSP);
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_UART_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_uart_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EmAppPortArray[EM_APP_TST_PS] = rsp_p->tst_uart_port_ps;
        EmAppPortArray[EM_APP_PS] = rsp_p->ps_uart_port;
        EmAppPortArray[EM_APP_TST_L1] = rsp_p->tst_uart_port_l1;
        EmAppPortArray[EM_APP_CTI] = rsp_p->cti_uart_port;

        EmAppBaudArray[EM_APP_TST_PS] = EM_GetIdxByBaudRate(rsp_p->tst_baud_rate_ps);
        EmAppBaudArray[EM_APP_PS] = EM_GetIdxByBaudRate(rsp_p->ps_baud_rate);
        EmAppBaudArray[EM_APP_TST_L1] = EM_GetIdxByBaudRate(rsp_p->tst_baud_rate_l1);
        EmAppBaudArray[EM_APP_CTI] = EM_GetIdxByBaudRate(rsp_p->cti_baud_rate);

        /**************************/
        /* TST-PS Port & Baudrate */
        /**************************/
    #ifdef __MMI_USB_SUPPORT__
        if (EmAppPortArray[EM_APP_TST_PS]==uart_port_usb)  // uart_port_usb = 4 
        {
            EmUartPortTSTHighlight = EM_USB_PORT; 
        }
        else
    #endif
        if (EmAppPortArray[EM_APP_TST_PS]==uart_port_null) // uart_port_null == 99
        {
            EmUartPortTSTHighlight = EM_UART_PORT_NULL; 
        }
        else
        {
            EmUartPortTSTHighlight = EmAppPortArray[EM_APP_TST_PS];         
        }
        EmUartBaudTSTHighlight = EmAppBaudArray[EM_APP_TST_PS];


        /**************************/
        /*** PS Port & Baudrate ***/
        /**************************/
    #ifdef __MMI_USB_SUPPORT__
        if (EmAppPortArray[EM_APP_PS]==uart_port_usb)  // uart_port_usb = 4 
        {
            EmUartPortPSHighlight = EM_USB_PORT;
        }
        else
    #endif
        if (EmAppPortArray[EM_APP_PS]==uart_port_null) // uart_port_null == 99
        {
            EmUartPortPSHighlight = EM_UART_PORT_NULL; 
        }
        else
        {
            EmUartPortPSHighlight = EmAppPortArray[EM_APP_PS];
        }        
        EmUartBaudPSHighlight = EmAppBaudArray[EM_APP_PS];    


        /**************************/
        /* TST-L1 Port & Baudrate */
        /**************************/
    #ifdef __MMI_USB_SUPPORT__
        if (EmAppPortArray[EM_APP_TST_L1]==uart_port_usb)  // uart_port_usb = 4 
        {
            EmUartPortTSTL1Highlight = EM_USB_PORT; 
        }
        else
    #endif
        if (EmAppPortArray[EM_APP_TST_L1]==uart_port_null) // uart_port_null == 99
        {
            EmUartPortTSTL1Highlight = EM_UART_PORT_NULL; 
        }
        else
        {
            EmUartPortTSTL1Highlight = EmAppPortArray[EM_APP_TST_L1];         
        }
        EmUartBaudTSTL1Highlight = EmAppBaudArray[EM_APP_TST_L1];


        /**************************/
        /** CTI Port & Baudrate ***/
        /**************************/
    #ifdef __MMI_USB_SUPPORT__
        if (EmAppPortArray[EM_APP_CTI]==uart_port_usb)  // uart_port_usb = 4 
        {
            EmUartPortCTIHighlight = EM_USB_PORT;
        }
        else
    #endif
        if (EmAppPortArray[EM_APP_CTI]==uart_port_null) // uart_port_null == 99
        {
            EmUartPortCTIHighlight = EM_UART_PORT_NULL; 
        }
        else
        {
            EmUartPortCTIHighlight = EmAppPortArray[EM_APP_CTI];         
        }
        EmUartBaudCTIHighlight = EmAppBaudArray[EM_APP_CTI];


        switch(g_em_set_uart_req_type)
        {
            case EM_SET_UART_UART_SETTING:
            {
                EntryEmUartSetting();
                break;
            }
            case EM_SET_UART_HIGH_SPEED_SIM:
            {
                EntryEmHighSpeedSIM();
                break;
            }
            case EM_SET_UART_SWDBG:
            {
            #if (defined(MT6229) || defined(MT6227) || defined(MT6228) || defined(MT6225) || defined(MT6268T) || defined(MT6230) || defined(MT6227D) || defined(MT6223) || defined(MT6226D) || defined(MT6223P) ) 
                EntryEmSWDBG();
            #endif
                break;
            }
            case EM_SET_UART_POWER_SETTING:
            {
                EntrySetUartPowerONOFFScr();
                break;
            }
            default:
                ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetHighSpeedSIMReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetHighSpeedSIMReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_uart_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_uart_req_struct));

    msg_p->func_id = UART_NVRAM_LID_FUNC_HIGH_SPEED_SIM;

    msg_p->ps_port = EmAppPortArray[EM_APP_PS];
    msg_p->tst_port_ps = EmAppPortArray[EM_APP_TST_PS];    
    msg_p->tst_port_l1 = EmAppPortArray[EM_APP_TST_L1];    
    msg_p->cti_uart_port = EmAppPortArray[EM_APP_CTI];    

//    msg_p->ps_baud_rate = PS_BAUDRATE;
//    msg_p->tst_baud_rate = TST_BAUDRATE;
    msg_p->ps_baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_PS]);
    msg_p->tst_baud_rate_ps = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_PS]);
    msg_p->tst_baud_rate_l1 = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_L1]);
    msg_p->cti_baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_CTI]);

    msg_p->High_Speed_SIM_Enabled = High_Speed_SIM;

    msg_p->swdbg = SWDBG_Profile;

    msg_p->uart_power_setting = UART_POWER_SETTING;
    
    UART_setting = FALSE;
    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_UART_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetUartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetUartReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_uart_req_struct *msg_p;

    extern kal_uint8 SWDBG_Profile;
    extern kal_uint8 UART_POWER_SETTING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_uart_req_struct));

    msg_p->func_id = UART_NVRAM_LID_FUNC_UART_CONFIG;

#if defined(__DSPIRDBG__)&& defined(__MMI_USB_SUPPORT__)
    if ((SWDBG_Profile-1) == EM_SWDBG_MCU_DSP_IRDBG)     /* SWDBG is 1-based */
    {
        if( (EmAppPortArray[EM_APP_PS]==uart_port_usb) || 
            (EmAppPortArray[EM_APP_TST_PS]==uart_port_usb) || 
            (EmAppPortArray[EM_APP_TST_L1]==uart_port_usb) || 
            (EmAppPortArray[EM_APP_CTI]==uart_port_usb) )
//            (EmUartPortCTIHighlight == EM_USB_PORT+1))
        {
            SWDBG_Profile = EM_SWDBG_RESET+1;
        }
    }
#endif /* __DISPIRDBG__) */

    msg_p->ps_port = EmAppPortArray[EM_APP_PS];
    msg_p->tst_port_ps = EmAppPortArray[EM_APP_TST_PS];
    msg_p->tst_port_l1 = EmAppPortArray[EM_APP_TST_L1];
    msg_p->cti_uart_port = EmAppPortArray[EM_APP_CTI];
    
    msg_p->ps_baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_PS]);
    msg_p->tst_baud_rate_ps = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_PS]);
    msg_p->tst_baud_rate_l1 = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_L1]);
    msg_p->cti_baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_CTI]);
    
    msg_p->High_Speed_SIM_Enabled = High_Speed_SIM;
    msg_p->swdbg = SWDBG_Profile;
    msg_p->uart_power_setting = UART_POWER_SETTING;


    old_tst_port = TST_PORT;
    old_ps_port = PS_UART_PORT;
    old_tst_baudrate = TST_BAUDRATE;
    old_ps_baudrate = PS_BAUDRATE;
    UART_setting = TRUE;

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_UART_REQ, msg_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_uart_rsp_struct *rsp_p = inMsg;
    S16 pError;
    extern kal_uint8 SWDBG_Profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        kal_uint8 swdbg_type;

        swdbg_type = SWDBG_Profile - 1;
        WriteValue(NVRAM_EM_SWDBG_MODE, &swdbg_type, DS_BYTE, &pError);

        /* Lisen 09062005 */
    #ifndef __DYNAMIC_UART_PORT_SWITCHING__
        EngineerModeSuccessRebootNotice(EM_NOTICE_SUCCESS_REBOOT_TEXT);
    #else /* __DYNAMIC_UART_PORT_SWITCHING__ */ 
        if (UART_setting == TRUE &&
            (old_tst_port != EmAppPortArray[EM_APP_TST_PS] ||
             old_ps_port != EmAppPortArray[EM_APP_PS] ||
             old_tst_baudrate != EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_PS]) ||
             old_ps_baudrate != EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_PS])))
        {
            EngineeringModeUartSendDetachReq();
            EmSetUartMsgDepth = 0;
        }
        else
        {
            DeleteScreenIfPresent(EM_DEV_INLINE_CONFIG_UART_MENU_SCR);
            EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
        }

        UART_setting = FALSE;
    #endif /* __DYNAMIC_UART_PORT_SWITCHING__ */ /* __SHUTDOWN_AFTER_UART_PORT_SETTING__ */
    }
    else
    {
        DisplayPopup((PU8) GetString(EM_DEV_SET_UART_ERROR_TEXT), IMG_GLOBAL_WARNING, 0, EM_NOTIFY_DURATION, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EngineeringModeUartSendDetachReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineeringModeUartSendDetachReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_detach_uart_port_req_struct *msp_p_detach_uart1;
    mmi_detach_uart_port_req_struct *msp_p_detach_uart2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EmSetUartMsgDepth = 0;

    /* Detach for TST */
    msp_p_detach_uart1 = OslConstructDataPtr(sizeof(mmi_detach_uart_port_req_struct));
    msp_p_detach_uart1->module_id = MOD_TST_READER;
    msp_p_detach_uart1->port = old_tst_port;

    /* Detach for L4C */
    msp_p_detach_uart2 = OslConstructDataPtr(sizeof(mmi_detach_uart_port_req_struct));
    msp_p_detach_uart2->module_id = MOD_L4C;
    msp_p_detach_uart2->port = old_ps_port;

    EngineerModeSendMsg(MSG_ID_MMI_DETACH_UART_PORT_REQ, msp_p_detach_uart1, NULL);
    EngineerModeSendMsg(MSG_ID_MMI_DETACH_UART_PORT_REQ, msp_p_detach_uart2, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeDetachUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeDetachUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_attach_uart_port_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!rsp_p->result)
    {
        EmSetUartMsgDepth++;
        if (EmSetUartMsgDepth == 2)
        {
            EngineeringModeUartSendAttachReq();
            EmSetUartMsgDepth = 0;
        }
    }
    else
    {
        DeleteScreenIfPresent(EM_DEV_INLINE_CONFIG_UART_MENU_SCR);
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
}

/* Lisen 1111 */


/*****************************************************************************
 * FUNCTION
 *  EngineeringModeUartSendAttachReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineeringModeUartSendAttachReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_attach_uart_port_req_struct *msp_p_uart1;
    mmi_attach_uart_port_req_struct *msp_p_uart2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Attach for TST */
    msp_p_uart1 = OslConstructDataPtr(sizeof(mmi_attach_uart_port_req_struct));
    msp_p_uart1->module_id = MOD_TST_READER;
    msp_p_uart1->port = EmAppPortArray[EM_APP_TST_PS];
    msp_p_uart1->baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_PS]);

    /* Attach for L4C */
    msp_p_uart2 = OslConstructDataPtr(sizeof(mmi_attach_uart_port_req_struct));
    msp_p_uart2->module_id = MOD_L4C;
    msp_p_uart2->port = EmAppPortArray[EM_APP_PS];
    msp_p_uart2->baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_PS]);

    EmSetUartMsgDepth = 0;
    EngineerModeSendMsg(MSG_ID_MMI_ATTACH_UART_PORT_REQ, msp_p_uart1, NULL);
    EngineerModeSendMsg(MSG_ID_MMI_ATTACH_UART_PORT_REQ, msp_p_uart2, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeAttachUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeAttachUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_attach_uart_port_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!rsp_p->result)
    {
        EmSetUartMsgDepth++;
        if (EmSetUartMsgDepth == 2)
        {
            DeleteScreenIfPresent(EM_DEV_INLINE_CONFIG_UART_MENU_SCR);
            EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
            EmSetUartMsgDepth = 0;
        }
    }
    else
    {
        DeleteScreenIfPresent(EM_DEV_INLINE_CONFIG_UART_MENU_SCR);
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetSleepModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetSleepModeReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_sleep_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_sleep_mode_req_struct));
    if (index == 0) /* Enable */
    {
        msg_p->on_off = KAL_TRUE;
    }
    else    /* Disable */
    {
        msg_p->on_off = KAL_FALSE;
    }

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ, msg_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetSleepModeRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetSleepModeRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_sleep_mode_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
}

#if defined(DCM_ENABLE)


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetDCMModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetDCMModeReq(U16 is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_dcm_enable_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_dcm_enable_req_struct));

    if (is_on)  /* Enable */
    {
        msg_p->enable = KAL_TRUE;
    }
    else    /* Disable */
    {
        msg_p->enable = KAL_FALSE;
    }

    EngineerModeSendMsg(MSG_ID_MMI_EQ_DCM_ENABLE_REQ, msg_p, NULL);
    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
}
#endif /* defined(DCM_ENABLE) */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSendMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->dest_mod_id = MOD_L4C;

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSendMsg_Check_Prefer_SIM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSendMsg_Check_Prefer_SIM(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    U32 source_id=MOD_L4C;
    U8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__    
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID,
               NVRAM_SYS_FLIGHTMODE_STATE, 
               (void*)buffer, 
               NVRAM_EF_SYS_CACHE_OCTET_SIZE, &pError);

    if (buffer[L4C_SETTING_DUAL_SIM_UART] ==  L4C_UART_TO_SIM2)
    {
        source_id = MOD_L4C_2;
    }
#endif /* #ifdef __MMI_DUAL_SIM_SINGLE_CALL__ */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->dest_mod_id = source_id;

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSendMsg_Ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSendMsg_Ext(U16 msg_id, U16 dest_mod_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = BT_APP_SAP;
    ilm_ptr->dest_mod_id = dest_mod_id;

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);

}

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */


/**************************************************************
**	FUNCTION NAME		: EmGetNWCellLockReq
**
** 	PURPOSE				: Get EM Network Cell Lock request function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmGetNWCellLockReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler (EmGetNWCellLockRsp, MSG_ID_MMI_EM_GET_CELL_LOCK_RSP);           
    EngineerModeSendMsg(MSG_ID_MMI_EM_GET_CELL_LOCK_REQ, NULL, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EmGetNWCellLockRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmGetNWCellLockRsp(void *inMsg)
{
#if defined(__EM_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_get_cell_lock_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryEmNWCellLockMenu(rsp_p->turn_on_or_off, rsp_p->band_indicator, rsp_p->lock_arfcn);

#endif /*  */ 
}


/**************************************************************
**	FUNCTION NAME		: EmSetNWCellLockReq
**
** 	PURPOSE				: Set EM Network Cell Lock request function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmSetNWCellLockReq(MMI_BOOL on_off, MMI_BOOL band1900_on, U16 arfcn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_set_cell_lock_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler (EmSetNWCellLockRsp, MSG_ID_MMI_EM_SET_CELL_LOCK_RSP);           
    msg_p = OslConstructDataPtr(sizeof(mmi_em_set_cell_lock_req_struct));
    msg_p->turn_on_or_off = on_off; 
    msg_p->band_indicator = band1900_on;
    msg_p->lock_arfcn = arfcn;    
    EngineerModeSendMsg(MSG_ID_MMI_EM_SET_CELL_LOCK_REQ, msg_p, NULL);
}


/**************************************************************
**	FUNCTION NAME		: EmSetNWCellLockRsp
**
** 	PURPOSE				: Set Cell Lock request response function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmSetNWCellLockRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_set_cell_lock_rsp_struct *rsp_p = inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_UPDATE_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_UPDATE_ERROR_TEXT);
    }
}

#endif /* __MMI_ENGINEER_MODE__ */ 


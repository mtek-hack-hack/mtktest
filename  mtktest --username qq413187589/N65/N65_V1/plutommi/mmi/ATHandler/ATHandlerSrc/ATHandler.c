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
 *   ATHandler.c
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
 * 
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
 * send MSG_ID_MMI_AT_GENERAL_RES_REQ to L4 in ATSetDateandTimeFormat()
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * Remove compile option: MMI_ON_HARDWARE_P & MMI_ON_WIN32
 *
 * removed!
 * removed!
 * Add check for MMI_PS_AT_LANG_EN.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix compile warning.
 *
 * removed!
 * removed!
 * Add LCM Test support.
 *
 * removed!
 * removed!
 * Set Greeting text modification.
 *
 * removed!
 * removed!
 * Modify Index parameter of AtSetProfileTone.
 *
 * removed!
 * removed!
 * Add check length: 0xFF = only modify mode for setting greeting text.
 *
 * removed!
 * removed!
 * Add AT general response for set_silent mode.
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

/**********************************************************************************
   Filename:      ATHandler.c
   Author:        Gautam
   Date Created:  
   Contains:   AT comamnd handler
**********************************************************************************/
#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "ATHandlerProt.h"
// #include "ATHandlerDcl.h"

#include "DateTimeType.h"
#include "AlarmGProt.h"
#include "AlarmFrameWorkProt.h"
#include "CallManagementGProt.h"
#include "CallManagementStruct.h"
#include "gpioInc.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"        /* IsTrChineseSet(), IsSmChinsesSet() */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "MMIThemes.h"
#include "PhoneSetupGprots.h"   /* PhnsetGetTimeFormat(), PhnsetGetDateFormat() */
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#include "Profiles_prot.h"
#include "SettingDefs.h"        /* MAX_SETTING_WELCOME_TEXT */
#include "SettingGprots.h"
#include "SettingProt.h"
#include "SimDetectionGexdcl.h"
#include "SettingsGdcl.h"
#include "WPSSProtos.h"
#include "ShortcutsProts.h"
#include "SSCStringHandle.h"    /* SSC_ENGLISH, ... defination */
#include "wgui_status_icons.h"
#include "DownloadDefs.h"
#include "WallpaperDefs.h"
#include "PhoneSetup.h"


#ifndef YEARFORMATE
#define YEARFORMATE 2000
#endif 

BOOL SetFromAT = FALSE;

extern U8 gprofileId;
extern U8 gactivatedprofile;
extern U16 gCurrLangIndex;
extern U16 gMaxDeployedLangs;
extern sLanguageDetails *gLanguageArray;
extern rtc_format_struct gclockData;
extern S8 gHour[];
extern S8 gMinute[];
extern S8 gDate[];
extern S8 gMonth[];
extern S8 gYear[];
extern U8 gPLMN[];

extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

extern BOOL AtSetProfileTone(U8 profileID, PROFILE_TONE_TYPE_ENUM tone_type, U8 tone_idx);
extern void RefreshNwProviderName(U8 *UpdatePlmn);
extern void MutethePhone(void);
extern void UnMutethePhone(void);
void ATRstFactoryDefault(void *ind);
void ATRstConfirm(void);
void ATVerifyPINRsp(void *info);
void ATLCMRGBTestHandler(void *ind);

/*****************************************************************************
 * FUNCTION
 *  ATHandlerInit
 * DESCRIPTION
 *  Set Volume : in the existing profile???
 *  Set Mute Mode
 *  Set Silent Mode
 *  Set Vibartion Mode
 *  Simulate Key Input
 *  Display Text On Main LCD : in what ever screen or the scren that ermits the same
 *  Display Status Icon : Irrespective of the condition?
 *  Set Alarm                        :Organise
 *  Delete Alarm ... would he give the ID ???:Organizer
 *  Set Date and Time                :Settings phonesetup
 *  Set Date and Time Format            .Settings
 *  Set language                     : Settings
 *  Set Greeting Text                :Settings
 *  Make Outgoing Call
 *  Answer Incoming Call
 *  Hang up outgoig call during dialling
 *  Sync Call Table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ATHandlerInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(ATSetVolume, PRT_MSG_ID_MMI_EQ_VOLUME_CHANGE_IND);
    SetProtocolEventHandler(ATSimulateKeyBoard, PRT_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND);
    SetProtocolEventHandler(ATTextOnLCD, PRT_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND);
    SetProtocolEventHandler(AtShowStatusIcon, PRT_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND);
    SetProtocolEventHandler(ATSetRTC, PRT_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND);
    SetProtocolEventHandler(ATSetAlarm, MSG_ID_MMI_AT_ALARM_SET_REQ_IND);
    SetProtocolEventHandler(ATQueryAlarm, MSG_ID_MMI_AT_ALARM_QUERY_REQ_IND);
    SetProtocolEventHandler(ATCancelAlarm, MSG_ID_MMI_AT_ALARM_DELETE_REQ_IND);
    SetProtocolEventHandler(ATMakeOutgoingCall, PRT_MSG_ID_MMI_CC_DIAL_REQ_IND);
    SetProtocolEventHandler(ATAnswerIncomingCall, PRT_MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND);
#if defined(__MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(ATHangupCall, PRT_MSG_ID_MMI_CC_CALL_ABORT_REQ_IND);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetProtocolEventHandler(ATHangupCall, PRT_MSG_ID_MMI_CC_CALL_ABORT_REQ_IND);
    SetProtocolEventHandler(ATSetProfileHandler, PRT_MMI_SET_MMI_DEFAULT_PROF_IND);
    SetProtocolEventHandler(ATSyncCallTable, PRT_MSG_ID_MMI_CC_SYNC_TABLE_REQ_IND);
    SetProtocolEventHandler(AtSetGreetingTextHdlr, PRT_MMI_EQ_SET_GREETING_TEXT_REQ_IND);
    SetProtocolEventHandler(ATSetLanguage, PRT_MMI_EQ_SET_LANGUAGE_REQ_IND);
    SetProtocolEventHandler(ATSetSilentMode, PRT_MMI_EQ_SET_SILENT_MODE_REQ_IND);
    SetProtocolEventHandler(ATSetVibrationMode, PRT_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND);
    SetProtocolEventHandler(ATSetDateandTimeFormat, PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND);
    SetProtocolEventHandler(ATSetMute, PRT_MMI_EQ_MUTE_CHANGE_IND);
    SetProtocolEventHandler(AtQueryGreetingTextIndHdlr, PRT_MMI_EQ_QUERY_GREETING_TEXT_REQ_IND);
    SetProtocolEventHandler(AtQueryLangIndHdlr, PRT_MMI_EQ_QUERY_LANGUAGE_REQ_IND);
    SetProtocolEventHandler(AtQuerySilentModeIndHdlr, PRT_MMI_EQ_QUERY_SILENT_MODE_REQ_IND);
    SetProtocolEventHandler(AtQueryVibratorModeIndHdlr, PRT_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND);
    SetProtocolEventHandler(AtQueryDTFmtIndHdlr, PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND);
    SetProtocolEventHandler(AtQueryMuteModeIndHdlr, PRT_MMI_EQ_QUERY_MUTE_MODE_REQ_IND);
    SetProtocolEventHandler(ATPowerReset, MSG_ID_MMI_POWER_RESET_IND);
    SetProtocolEventHandler(ATRstFactoryDefault, PRT_MMI_FACTORY_RESTORE_REQ_IND);
    SetProtocolEventHandler(ATLCMRGBTestHandler, MSG_ID_MMI_EM_RGB_TEST_REQ_IND);
}

/*********************/
/* Send Message Func */
/*********************/


/*****************************************************************************
 * FUNCTION
 *  SendMsg2AT
 * DESCRIPTION
 *  Send message to AT
 * PARAMETERS
 *  msg_id              [IN]        Message id
 *  local_param_ptr     [?]         Local parameter pointer
 *  peer_buf_ptr        [?]         Peer buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void SendMsg2AT(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
}

/******************/
/* Greeting Text  */
/******************/


/*****************************************************************************
 * FUNCTION
 *  AtSetGreetingTextHdlr
 * DESCRIPTION
 *  Set greeting text from AT command
 * PARAMETERS
 *  msg     [?]     Greeting text to be set
 * RETURNS
 *  void
 *****************************************************************************/
void AtSetGreetingTextHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp_msg;
    mmi_eq_set_greeting_text_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_greeting_text_req_ind_struct*) msg;
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

    if ( (msgReq->length < (MAX_SETTING_WELCOME_TEXT * ENCODING_LENGTH)) || (msgReq->length == 0xFF))
    {
        rsp_msg->result = PhnsetSetWelcomeText((MMI_BOOL) msgReq->mode, (U8) msgReq->dcs, (U8*) msgReq->text, (U8)msgReq->length);
    }
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
}

/***************/
/* Language    */
/***************/


/*****************************************************************************
 * FUNCTION
 *  AtQueryGreetingTextIndHdlr
 * DESCRIPTION
 *  Query Greeting Text from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void AtQueryGreetingTextIndHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_greeting_text_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_eq_query_greeting_text_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_greeting_text_res_req_struct));

    rsp_msg->mode = IsShowWelcomeScr1();
    rsp_msg->dcs = L4_UCS2;
    PhnsetGetWelcomeText((S8*) rsp_msg->text, sizeof(rsp_msg->text));
    rsp_msg->length = (U8) mmi_ucs2strlen((S8*) rsp_msg->text);

    SendMsg2AT(PRT_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ, (void*)rsp_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  ATSetLanguage
 * DESCRIPTION
 *  Set Language from AT command
 * PARAMETERS
 *  msg     [?]     Set language request
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetLanguage(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* to see the value of language code */
    U8 data = 0;
    S16 error;
    S8 *ssc_sp;
    mmi_eq_set_language_req_ind_struct *msgInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgInd = (mmi_eq_set_language_req_ind_struct*) msg;

    switch (msgInd->lang_code)
    {
        case MMI_PS_AT_LANG_TW:
            ssc_sp = SSC_TCHINESE;  /* data = 1; */
            break;
        case MMI_PS_AT_LANG_ZH:
            ssc_sp = SSC_SCHINESE;  /* data = 2; */
            break;

        case MMI_PS_AT_LANG_DEFAULT:
        case MMI_PS_AT_LANG_EN:
        default:
            ssc_sp = SSC_ENGLISH;   /* data = 0; */
            break;
    }

    for (data = 0; data < gMaxDeployedLangs; data++)
    {
        if (strcmp((PS8) gLanguageArray[data].aLangSSC, ssc_sp) == 0)
        {
            break;
        }
    }

    /* Language not support (out of boundary) */
    if (data >= gMaxDeployedLangs)
    {
        SendLangChange2AT(0xFF);
        return;
    }

    if (data != gCurrLangIndex)
    {
        SetCurrentLanguage(data);
        WriteValue(NVRAM_SETTING_LANG, &data, DS_BYTE, &error);
        RefreshNwProviderName(gPLMN);
        if (g_idle_context.IsOnIdleScreen)
        {
            EntryIdleScreen();
        }
    }

    SendLangChange2AT(data);
}


/*****************************************************************************
 * FUNCTION
 *  AtQueryLangIndHdlr
 * DESCRIPTION
 *  Query language setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void AtQueryLangIndHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lang_type = MMI_PS_AT_LANG_DEFAULT;
    mmi_eq_query_language_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg =
        (mmi_eq_query_language_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_query_language_res_req_struct));

    if (IsTrChineseSet())
    {
        lang_type = MMI_PS_AT_LANG_TW;
    }
    else if (IsSmChineseSet())
    {
        lang_type = MMI_PS_AT_LANG_ZH;
    }
    else if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
    	lang_type = MMI_PS_AT_LANG_EN;
    }
    else
    {
        lang_type = MMI_PS_AT_LANG_UNKWN;
    }

    res_msg->lang_code = lang_type;

    SendMsg2AT(PRT_MMI_EQ_QUERY_LANGUAGE_RES_REQ, (void*)res_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SendLangChange2AT
 * DESCRIPTION
 *  Send to AT command when language change, for AT+CLAE
 * PARAMETERS
 *  code        [IN]        Language to be set
 * RETURNS
 *  void
 *****************************************************************************/
void SendLangChange2AT(U8 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_language_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_language_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_language_req_struct));

    /*
     * switch (code)
     * {
     * case 0: msgReq->lang_code = MMI_PS_AT_LANG_EN; break;
     * case 1: msgReq->lang_code = MMI_PS_AT_LANG_TW; break;
     * case 2: msgReq->lang_code = MMI_PS_AT_LANG_ZH; break;
     * default: msgReq->lang_code = MMI_PS_AT_LANG_EN; break;
     * }
     */

    if (code > gMaxDeployedLangs)
    {
        msgReq->lang_code = MMI_PS_AT_LANG_UNKWN;
    }
    else
    {
        if (strcmp((PS8) gLanguageArray[code].aLangSSC, SSC_ENGLISH) == 0)
        {
            msgReq->lang_code = MMI_PS_AT_LANG_EN;
        }
        else if (strcmp((PS8) gLanguageArray[code].aLangSSC, SSC_TCHINESE) == 0)
        {
            msgReq->lang_code = MMI_PS_AT_LANG_TW;
        }
        else if (strcmp((PS8) gLanguageArray[code].aLangSSC, SSC_SCHINESE) == 0)
        {
            msgReq->lang_code = MMI_PS_AT_LANG_ZH;
        }
        else
        {
            msgReq->lang_code = MMI_PS_AT_LANG_UNKWN;
        }
    }

    SendMsg2AT(PRT_MMI_EQ_SET_LANGUAGE_REQ, (void*)msgReq, NULL);
}

/***************/
/* Silent mode */
/***************/


/*****************************************************************************
 * FUNCTION
 *  ATSetSilentMode
 * DESCRIPTION
 *  Set Silent Mode from AT command
 * PARAMETERS
 *  msg     [?]     Set silent mode on/off request message
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetSilentMode(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_silent_mode_req_struct *msgReq;
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_silent_mode_req_struct*) msg;
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    
    SetFromAT = TRUE;
    if (msgReq->mode)
    {
        ClearKeyEvents();
        ActivateSilentProfile();
        if (IsSilentModeActivated())
        {
            /* set silent mode successfully */
            rsp_msg->result = TRUE;
        }
        else
        {
            /* set silent mode failed */
            rsp_msg->result = FALSE;
        }
    }
    else
    {
        ClearKeyEvents();
        DeactivateSilentProfile();
        if (IsSilentModeActivated())
        {
            /* deactivate silent mode failed */
            rsp_msg->result = FALSE;
        }
        else
        {
            /* deactivate silent mode successfully */
            rsp_msg->result = TRUE;
        }
    }
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
    
    SetFromAT = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  AtQuerySilentModeIndHdlr
 * DESCRIPTION
 *  Query silent mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void AtQuerySilentModeIndHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_silent_mode_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg =
        (mmi_eq_query_silent_mode_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_silent_mode_res_req_struct));

    if (gactivatedprofile == 5) /* 5: Silent Profile */
    {
        res_msg->mode = MMI_TRUE;
    }
    else
    {
        res_msg->mode = MMI_FALSE;
    }

    SendMsg2AT(PRT_MMI_EQ_QUERY_SILENT_MODE_RES_REQ, (void*)res_msg, NULL);
}

/******************/
/* Vibration Mode */
/******************/


/*****************************************************************************
 * FUNCTION
 *  ATSetVibrationMode
 * DESCRIPTION
 *  AT Command set Vibrator Mode
 * PARAMETERS
 *  msg     [?]     Set vibration mode on/off request
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetVibrationMode(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmpValue = gprofileId;
    mmi_eq_set_vibrator_mode_req_ind_struct *msgInd;
    MMI_ALERT_TYPE alertType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgInd = (mmi_eq_set_vibrator_mode_req_ind_struct*) msg;
    SetFromAT = TRUE;
    gprofileId = gactivatedprofile;
    alertType = GetMtCallAlertTypeEnum();
    if (msgInd->mode == 1)
    {
        if ((alertType == MMI_ALERT_NONE) || (alertType == MMI_SILENT))
        {
            SetMtCallAlertTypeEnum(MMI_VIBRATION_ONLY);
        }
        else if (alertType == MMI_RING)
        {
            SetMtCallAlertTypeEnum(MMI_VIBRATION_AND_RING);
        }
    }
    else if (msgInd->mode == 0)
    {
        if ((alertType == MMI_VIBRATION_AND_RING) || (alertType == MMI_VIBRATION_THEN_RING))
        {
            SetMtCallAlertTypeEnum(MMI_RING);
        }
        else if (alertType == MMI_VIBRATION_ONLY)
        {
            SetMtCallAlertTypeEnum(MMI_SILENT);
        }
    }
    gprofileId = tmpValue;
    SetFromAT = FALSE;

    if (GetActiveScreenId() == SCR_PROFILES_CUSTOMIZE)
    {
        mmi_profiles_exit_customize();
        GoBackHistory();

    }
}


/*****************************************************************************
 * FUNCTION
 *  AtQueryVibratorModeIndHdlr
 * DESCRIPTION
 *  Query vibrator mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void AtQueryVibratorModeIndHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE alert_type;
    mmi_eq_query_vibrator_mode_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg = (mmi_eq_query_vibrator_mode_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_vibrator_mode_res_req_struct));

    alert_type = GetMtCallAlertTypeEnum();
    if (alert_type == MMI_VIBRATION_ONLY ||
        alert_type == MMI_VIBRATION_AND_RING || alert_type == MMI_VIBRATION_THEN_RING)
    {
        res_msg->mode = MMI_TRUE;
    }
    else
    {
        res_msg->mode = MMI_FALSE;
    }

    SendMsg2AT(PRT_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ, (void*)res_msg, NULL);
}

/********************/
/* Date/Time Format */
/********************/


/*****************************************************************************
 * FUNCTION
 *  ATSetDateandTimeFormat
 * DESCRIPTION
 *  AT Command set Date Time Format
 * PARAMETERS
 *  msg     [?]     Set date time format request message, specifying time/date
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetDateandTimeFormat(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_time_fmt = 0;
    mmi_eq_set_date_time_format_req_ind_struct *msgReq;
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_date_time_format_req_ind_struct*) msg;

    SetFromAT = TRUE;

    if (msgReq->is_date_set)
    {

        switch (msgReq->mode)
        {
            case DATE_DD_MMM_YYYY:
                date_time_fmt = 0;
                break;
            case DATE_DD_MM_YYYY_S:
                date_time_fmt = 1;
                break;
            case DATE_MM_DD_YYYY_S:
                date_time_fmt = 2;
                break;
            case DATE_YYYY_MM_DD_S:
                date_time_fmt = 3;
                break;
            case DATE_YYYY_MM_DD_H:
                date_time_fmt = 4;
                break;
            case DATE_MMM_DD_YYYY:
                date_time_fmt = 5;
                break;
            default:
                break;  /* we do not have suport for this format */
        }

        PhnsetSetDateFormat(date_time_fmt);

    }
    else
    {
        switch (msgReq->mode)
        {
            case TIME_HH_MM_24:
                date_time_fmt = 1;
                break;
            case TIME_HH_MM_12:
                date_time_fmt = 0;
                break;
            default:
                break;  /* formt not support */
        }

        PhnsetSetTimeFormat(date_time_fmt);
    }

    SetFromAT = FALSE;

    if (g_idle_context.IsOnIdleScreen)
    {
        EntryIdleScreen();
    }

    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    
    rsp_msg->result = TRUE;
    
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  AtQueryDTFmtIndHdlr
 * DESCRIPTION
 *  Query date time format setting from AT command
 * PARAMETERS
 *  msg     [?]     Query type (time/date)
 * RETURNS
 *  void
 *****************************************************************************/
void AtQueryDTFmtIndHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_time_fmt;
    mmi_eq_query_date_time_format_req_ind_struct *in_msg = (mmi_eq_query_date_time_format_req_ind_struct*) msg;
    mmi_eq_query_date_time_format_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg = (mmi_eq_query_date_time_format_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_date_time_format_res_req_struct));

    if (in_msg->is_date == MMI_TRUE)
    {   /* Query date format */

        res_msg->is_date = MMI_TRUE;
        date_time_fmt = PhnsetGetDateFormat();

        switch (date_time_fmt)
        {
            case 0:
                res_msg->mode = DATE_DD_MMM_YYYY;
                break;
            case 1:
                res_msg->mode = DATE_DD_MM_YYYY_S;
                break;
            case 2:
                res_msg->mode = DATE_MM_DD_YYYY_S;
                break;
            case 3:
                res_msg->mode = DATE_YYYY_MM_DD_S;
                break;
            case 4:
                res_msg->mode = DATE_YYYY_MM_DD_H;
                break;
            case 5:
                res_msg->mode = DATE_MMM_DD_YYYY;
                break;
            default:
                res_msg->mode = 0;
                break;
        }

    }
    else
    {   /* Query time format */

        res_msg->is_date = MMI_FALSE;
        date_time_fmt = PhnsetGetTimeFormat();

        switch (date_time_fmt)
        {
            case 0:
                res_msg->mode = TIME_HH_MM_12;
                break;
            case 1:
                res_msg->mode = TIME_HH_MM_24;
                break;
            default:
                res_msg->mode = TIME_HH_MM_12;
                break;
        }
    }

    SendMsg2AT(PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ, (void*)res_msg, NULL);
}

/*******************/
/* Mute mode       */
/*******************/


/*****************************************************************************
 * FUNCTION
 *  ATSetMute
 * DESCRIPTION
 *  AT Command set Mute
 * PARAMETERS
 *  msg     [?]     Set mute on/off request
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetMute(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_set_mute_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_mute_req_struct*) msg;

    if (!isInCall())
    {
        return;
    }

    SetFromAT = TRUE;

    switch (msgReq->audio_device)
    {
        case MDI_DEVICE_MICROPHONE:
            if ((msgReq->mute_onoff == MMI_TRUE) && !IsPhoneInMute())
            {
                MutethePhone();
            }
            else if ((msgReq->mute_onoff == MMI_FALSE) && IsPhoneInMute())
            {
                UnMutethePhone();
            }
            break;

        case MDI_DEVICE_SPEAKER:
            if (msgReq->mute_onoff == MMI_TRUE)
            {
                MuteOnSpeaker();
            }
            else
            {
                MuteOnSpeaker();
            }
            break;

        default:
            break;
    }

    SetFromAT = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  AtQueryMuteModeIndHdlr
 * DESCRIPTION
 *  Query mute mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void AtQueryMuteModeIndHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_mute_mode_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg = (mmi_eq_query_mute_mode_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_mute_mode_res_req_struct));

    if (IsPhoneInMute())
    {
        res_msg->mode = MMI_TRUE;
    }
    else
    {
        res_msg->mode = MMI_FALSE;
    }

    SendMsg2AT(PRT_MMI_EQ_QUERY_MUTE_MODE_RES_REQ, (void*)res_msg, NULL);
}

/*********/
/* Volume */
/*********/


/*****************************************************************************
 * FUNCTION
 *  ATSetVolume
 * DESCRIPTION
 *  AT command set volume
 * PARAMETERS
 *  msg     [?]     Volume type/level setting request
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetVolume(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 tmpValue;
    mmi_eq_set_volume_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_volume_req_struct*) msg;
    SetFromAT = TRUE;
    tmpValue = gprofileId;
    gprofileId = gactivatedprofile;

    switch (msgReq->volume_type)
    {
        case MDI_VOLUME_MEDIA:
            if (msgReq->volume_level < MDI_MAX_VOLUME_LEVEL)
                /* MTK Brian added for setting activated ring tone volume, 2003/12/02 */
            {
                SetActivatedRingVolumeLevel(msgReq->volume_level);
            }
            break;
        case MDI_VOLUME_KEY:
            if (msgReq->volume_level < MDI_MAX_VOLUME_LEVEL)
                /* MTK Brian added for setting activated keypad volume, 2003/12/02 */
            {
                SetActivatedKeypadVolumeLevel(msgReq->volume_level);
            }
            break;

        case MDI_VOLUME_SPH:
            if (msgReq->volume_level < MDI_MAX_VOLUME_LEVEL)
            {
                SaveSpeechVolume(msgReq->volume_level);
            }
            break;
        default:
            break;

    }
    gprofileId = (U8) tmpValue;
    SetFromAT = FALSE;
}

/**********/
/* Keybord */
/**********/


/*****************************************************************************
 * FUNCTION
 *  ATSimulateKeyBoard
 * DESCRIPTION
 *  AT command simulate key board event
 * PARAMETERS
 *  msg     [?]     Keypad status/key code message
 * RETURNS
 *  void
 *****************************************************************************/
void ATSimulateKeyBoard(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_simulate_key_press_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_simulate_key_press_req_ind_struct*) msg;
    SetFromAT = TRUE;
    ProcessKeyEvent(msgReq->keypad_status, msgReq->keycode);
    /* can not be tested on windiows as status value reuired is 513 ,.. 8 bits ?? */
    SetFromAT = FALSE;
}

/*************/
/* Status Icon */
/*************/


/*****************************************************************************
 * FUNCTION
 *  AtShowStatusIcon
 * DESCRIPTION
 *  AT command set to show status icon
 * PARAMETERS
 *  msg     [?]     Status icon id to be shown
 * RETURNS
 *  void
 *****************************************************************************/
void AtShowStatusIcon(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_set_indicator_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_indicator_req_ind_struct*) msg;
    SetFromAT = TRUE;
    if (msgReq->icon_id < MAX_STATUS_ICONS)
    {
        ShowStatusIcon(msgReq->icon_id);
        UpdateStatusIcons();
    }

    SetFromAT = FALSE;
}

/*******/
/* RTC */
/*******/


/*****************************************************************************
 * FUNCTION
 *  ATSetRTC
 * DESCRIPTION
 *  AT command set RTC
 * PARAMETERS
 *  msg     [?]     RTC
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetRTC(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYTIME alarmDateTime;
    mmi_eq_set_rtc_time_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_rtc_time_req_ind_struct*) msg;

    SetFromAT = TRUE;
    if (msgReq->rtc_type == RTC_TIME_CLOCK_IND)
    {
        mmi_at_general_res_req_struct *rsp_msg;

        rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

        alarmDateTime.nSec = msgReq->alarm.data_time.rtc_sec;
        alarmDateTime.nMin = msgReq->alarm.data_time.rtc_min;
        alarmDateTime.nHour = msgReq->alarm.data_time.rtc_hour;
        alarmDateTime.nDay = msgReq->alarm.data_time.rtc_day;
        alarmDateTime.nMonth = msgReq->alarm.data_time.rtc_mon;
        alarmDateTime.nYear = msgReq->alarm.data_time.rtc_year + YEARFORMATE;

        if (PhnsetSetDTFromAT(alarmDateTime))
        {
            rsp_msg->result = TRUE;
        }
        else
        {
            rsp_msg->result = FALSE;
        }

        SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
    }
    SetFromAT = FALSE;

    if (g_idle_context.IsOnIdleScreen)
    {
        EntryIdleScreen();
    }

}

/********/
/* Alarm */
/********/


/*****************************************************************************
 * FUNCTION
 *  ATQueryAlarm
 * DESCRIPTION
 *  Query alarm setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void ATQueryAlarm(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFromAT = TRUE;
    AlmQueryAlarmFromAT();
    SetFromAT = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ATSetAlarm
 * DESCRIPTION
 *  AT command set alarm
 * PARAMETERS
 *  msg     [?]     Alarm time/index to be set
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetAlarm(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_alarm_set_req_ind_struct *req = (mmi_at_alarm_set_req_ind_struct*) msg;
    mmi_at_alarm_set_res_req_struct *rsp;
    MYTIME alarmDateTime;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFromAT = TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_AT_ALARM_SET_RES_REQ;
    rsp = (mmi_at_alarm_set_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_alarm_set_res_req_struct));

    if (req->alarm.alarm_index < NUM_OF_ALM)
    {
        alarmDateTime.nSec = req->alarm.date_time.rtc_sec;
        alarmDateTime.nMin = req->alarm.date_time.rtc_min;
        alarmDateTime.nHour = req->alarm.date_time.rtc_hour;
        alarmDateTime.nDay = req->alarm.date_time.rtc_day;
        alarmDateTime.nMonth = req->alarm.date_time.rtc_mon;
        alarmDateTime.nYear = req->alarm.date_time.rtc_year + YEARFORMATE;
        ClearKeyEvents();

        AlmSetAlarmFromAT(req->alarm.alarm_index, alarmDateTime, req->alarm.recurr);
        rsp->result = KAL_TRUE;
    }
    else
    {
        rsp->result = KAL_FALSE;
    }

    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetFromAT = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ATCancelAlarm
 * DESCRIPTION
 *  AT command cancel alarm
 * PARAMETERS
 *  msg     [?]     Alarm index to be set
 * RETURNS
 *  void
 *****************************************************************************/
void ATCancelAlarm(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_alarm_delete_req_ind_struct *req = (mmi_at_alarm_delete_req_ind_struct*) msg;
    mmi_at_alarm_delete_res_req_struct *rsp;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFromAT = TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ;
    rsp = (mmi_at_alarm_delete_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_alarm_delete_res_req_struct));

    if (req->alarm_index < NUM_OF_ALM)
    {
        ClearKeyEvents();
        AlmCancelAlarmFromAT(req->alarm_index);
        rsp->result = KAL_TRUE;
    }
    else
    {
        rsp->result = KAL_FALSE;
    }

    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    SetFromAT = FALSE;
}

/*******/
/* Call */
/*******/


/*****************************************************************************
 * FUNCTION
 *  ATAnswerIncomingCall
 * DESCRIPTION
 *  AT command answer incoming call
 * PARAMETERS
 *  msg     [?]     Call id to be answered
 * RETURNS
 *  void
 *****************************************************************************/
void ATAnswerIncomingCall(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_accept_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_cc_call_accept_req_ind_struct*) msg;
    AcceptCallForAT(msgReq->call_id);
}


/*****************************************************************************
 * FUNCTION
 *  ATMakeOutgoingCall
 * DESCRIPTION
 *  AT command make outgoing call
 * PARAMETERS
 *  msg     [?]     Destination number/call type to be made
 * RETURNS
 *  void
 *****************************************************************************/
void ATMakeOutgoingCall(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_cc_dial_req_ind_struct *msgReq;
    PU8 start;
    U8 number[MAX_DIGIT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_cc_dial_req_ind_struct*) msg;

    memset((PS8) number, 0, MAX_DIGIT);
    start = number;
    if (msgReq->dest.type & 0x10)
    {
        number[0] = '+';
        start++;
    }

    if (msgReq->dest.length < MAX_DIGIT)
    {
        strncpy((PS8) start, (PS8) msgReq->dest.number, msgReq->dest.length);
    }
    else
    {
        strcpy((PS8) start, (PS8) msgReq->dest.number);
    }
    MakeMOForAT((PS8) number, msgReq->dest.length, msgReq->call_type);
}


/*****************************************************************************
 * FUNCTION
 *  ATHangupCall
 * DESCRIPTION
 *  AT command hang up call
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void ATHangupCall(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* use of id feild.. t */
    mmi_cc_call_release_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_cc_call_release_ind_struct*) msg;
    RemoveOutgoingIndicationScreen();
}


/*****************************************************************************
 * FUNCTION
 *  ATSyncCallTable
 * DESCRIPTION
 *  AT command sync call table
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void ATSyncCallTable(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetSyncCallFromATFlag(TRUE);
    SyncCallList();
}

/*************/
/* Text on LCD */
/*************/

static U8 buffer[100];


/*****************************************************************************
 * FUNCTION
 *  ATTextOnLCD
 * DESCRIPTION
 *  AT command show text on LCD (function not working)
 * PARAMETERS
 *  msg     [?]     Message to be shown(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ATTextOnLCD(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int buffersize = 100;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.IsOnIdleScreen)
    {
        ClearKeyEvents();
        ShowCategory5Screen(
            0,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
            buffer,
            buffersize,
            0);
        SetLeftSoftkeyFunction(ATTextOnLCDExit, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ATTextOnLCDExit
 * DESCRIPTION
 *  Exit text on LCD screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ATTextOnLCDExit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryIdleScreen();
}

/********/
/* Profile */
/********/


/*****************************************************************************
 * FUNCTION
 *  ATSetProfileHandler
 * DESCRIPTION
 *  AT command set profile
 * PARAMETERS
 *  msg     [?]     Wall paper/tone/home city/theme/short cut setting request
 * RETURNS
 *  void
 *****************************************************************************/
void ATSetProfileHandler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_set_mmi_default_prof_ind_struct *mmi_set_prof_struct = (mmi_set_mmi_default_prof_ind_struct*) msg;

    mmi_at_general_res_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    msgReq->result = MMI_FALSE;

    if (mmi_set_prof_struct->op != 1)   /* Query command, not imlpemented, send response with error result to L4 */
    {
        goto MMILAB_ATSETPROF_END;
    }

    switch (mmi_set_prof_struct->category)
    {
        case 0: /* Wallpaper */
        {
            if (PhnsetSetDisplayFromAT((U8) (mmi_set_prof_struct->param3 - 1), (U8) MMI_PHNSET_TYPE_WP) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
        case 1: /* Tone */
        {
            if (mmi_set_prof_struct->param2 == 0)
            {
                if (AtSetProfileTone(mmi_set_prof_struct->param1, TONE_POWERONTONE, (mmi_set_prof_struct->param3 - 1)) ==
                    MMI_TRUE)
                {
                    msgReq->result = MMI_TRUE;
                }
            }
            break;
        }
        case 2: /* Home City */
        {
            if (ATSetHomeCity((U8) (mmi_set_prof_struct->param3)) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
    #if defined(__MMI_THEMES_APPLICATION__)
        case 3: /* Theme */
        {
            if (ATSetTheme((U8) (mmi_set_prof_struct->param3 - 1)) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
    #endif /* defined(__MMI_THEMES_APPLICATION__) */ 
    #ifndef __DISABLE_SHORTCUTS_IMPL__
        case 4: /* Shortcut */
        {
            if (ATSetShortcuts((PU8) mmi_set_prof_struct->param4) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
    #endif /* __DISABLE_SHORTCUTS_IMPL__ */ 
        case 5: /* Screen Saver */
        {
            if (PhnsetSetDisplayFromAT((U8) (mmi_set_prof_struct->param3 - 1), (U8) MMI_PHNSET_TYPE_SS) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        case 6: /* Power On */
        {
            if (PhnsetSetDisplayFromAT((U8) (mmi_set_prof_struct->param3 - 1), (U8) MMI_PHNSET_TYPE_PWRON) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
        case 7: /* Power Off */
        {
            if (PhnsetSetDisplayFromAT((U8) (mmi_set_prof_struct->param3 - 1), (U8) MMI_PHNSET_TYPE_PWROFF) == MMI_TRUE)
            {
                msgReq->result = MMI_TRUE;
            }

            break;
        }
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
        default:
            msgReq->result = MMI_FALSE;
            break;
    }

  MMILAB_ATSETPROF_END:
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)msgReq, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  ATPowerReset
 * DESCRIPTION
 *  AT command reset power
 * PARAMETERS
 *  ind     [?]     
 *  in    msg      no action(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ATPowerReset(void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_power_reset_ind_struct *msg = (mmi_power_reset_ind_struct*) ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmATPowerReset(msg->poweroff, msg->rtc_timer);
}


/*****************************************************************************
 * FUNCTION
 *  ATRstFactoryDefault
 * DESCRIPTION
 *  AT command restore factory default
 * PARAMETERS
 *  ind     [?]     
 *  in    msg      no action(?)
 * RETURNS
 *  void
 *****************************************************************************/
extern SecuritySetupContext gSecuritySetupContext;
void ATRstFactoryDefault(void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMIPHONEVERIFYREQ *local_data;

    mmi_factory_restore_req_ind_struct *msg = (mmi_factory_restore_req_ind_struct*) ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    Message.oslMsgId = PRT_MMI_SMU_VERIFY_PIN_REQ;
    local_data = (MMIPHONEVERIFYREQ*) OslConstructDataPtr(sizeof(MMIPHONEVERIFYREQ));
    memset(local_data->pin, '\0', (MAX_SIM_SETTING_PASSWD_LEN + 1));
    memset(local_data->new_pin, '\0', (MAX_SIM_SETTING_PASSWD_LEN + 1));
    local_data->pin_type = MMI_SETTING_TYPE_PHONELOCK;
    /*  Change gInputPhoneLockBuffer to ASCII then copy local_data->pin */
    memcpy(local_data->pin, msg->pwd, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    /* set the protocol handler to handle the response of this request */

    gSecuritySetupContext.VerifyPassSuccessCallBack = ATRstConfirm;

    SetProtocolEventHandler(ATVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  ATVerifyPINRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ATVerifyPINRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void FillCountDownNumber(sim_chv_info_struct chv_info);

    mmi_smu_verify_pin_rsp_struct *local_data = (mmi_smu_verify_pin_rsp_struct*) info;

    FillCountDownNumber(local_data->chv_info);

    gSecuritySetupContext.PINBlocked = 0;
    g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;  /* 0x01: Invalid SIM reset */
    if (local_data->next_type != MMI_SETTING_TYPE_NO_REQUIRED)
    {
        mmi_at_general_res_req_struct *rsp_msg;

        rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

        rsp_msg->result = FALSE;

        SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
    }
    else
    {
        SECSETVerifyPINRsp(info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ATRstConfirm
 * DESCRIPTION
 *  This function is to handle AT command restore factory default
 *  Following functions: RstStartRestore
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
extern pBOOL bStatus;
void ATRstConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

    RstStartRestore();
    if (bStatus)
    {
        rsp_msg->result = TRUE;
    }
    else
    {
        rsp_msg->result = FALSE;
    }

    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  ATLCMRGBTestHandler
 * DESCRIPTION
 *  This function is to handle AT command LCM RGB Test
  * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void ATLCMRGBTestHandler(void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp_msg;
    mmi_em_rgb_test_req_ind_struct *msg = (mmi_em_rgb_test_req_ind_struct*) ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void EMLCDSetColor(U8 red, U8 green, U8 blue);
    
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

    if (msg->type)
    {
        if ((msg->red > 255) || (msg->green > 255) || (msg->blue > 255))
        {
            rsp_msg->result = FALSE;
        }
        else
        {
            rsp_msg->result = TRUE;
            EMLCDSetColor((U8)msg->red, (U8)msg->green, (U8)msg->blue);       
        }
    }
    else
    {
        rsp_msg->result = TRUE;
        GoBackHistory();
    }    
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp_msg, NULL);
}

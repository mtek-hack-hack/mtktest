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
 *   OutgoingCallmanagement.c
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
 * Replace 2G compile options.
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
 * add to source control recursely
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
 * Apply new bootup revise APIs
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

   FILENAME : OutgoingCallmanagement.c

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG

   DATE     : Nov 11,02

**************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "wgui.h"

#include "DateTimeGprot.h"
/* micha0521 */
#include "SATDefs.h"
#include "SATGProts.h"
#include "SimDetectionGexdcl.h"
#include "gpioInc.h"
#include "CSP.h"
#include "CallSetUp.h"
#include "ProfileGprots.h"
#include "ManageCallMain.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "MessagesExDcl.h"
#include "MessagesResourceData.h"
#include "SMSApi.h"
#include "AlarmFrameworkProt.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#ifdef __MMI_VOICE_MEMO__
#include "VoiceMemoProt.h"
#endif 
#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderProt.h"
#endif 
#ifdef __MMI_AUDIO_PLAYER__
#include "AudioPlayerProt.h"
#endif 

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

#ifdef __CTM_SUPPORT__
#include "TextPhoneDef.h"
#include "TextPhoneProt.h"
#endif /* __CTM_SUPPORT__ */ 
#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#include "CallManagementIdDefEX.h"
#include "CallManagementStructEX.h"
#include "CallStructureManagementProtEX.h"
#include "CmErrorTypesEX.h"
#include "CmErrorHandlersProtEX.h"
#include "HistoryHelperProtEX.h"
#include "CommonStubsProtEX.h"
#include "PsCallHelperDefEX.h"
#include "mmiapi_struct.h"
#include "PsCallHelperGprotEX.h"
#include "RedialHelperGProtEX.h"
#include "CallManagementGprotEX.h"
#include "IncomingCallManagementProtEX.h"
#include "OutgoingCallHelperProtEX.h"

#include "OutgoingCallManagementProtEX.h"

#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMResDef.h"

/* micha1115 */
#include "CallSetUpEnum.h"
#include "SimDetectionGprot.h"

#define TEMP_NO 10
#define SCR_TEXT_LEN 50

static OUTGOING_CALL gCurrOutcall;  /* This is a global variable usefull till the */
static PU8 gcallList[MAX_CALLS];
static U16 gcallListImage[MAX_CALLS];
static U16 gcallListlen = 0;
static U16 gHilitedCall = 0;
static U8 gListOperation = 0;

U16 gtmpOutgoingIndex;

extern MYTIME gTimeStructForCallDuration;
extern const U16 CMIdleScreenDigits[];
extern S8 DTMFPadCallBuffer[MAX_DIGITS_USSD];
extern PU8 gdispnameForSubLCD;

extern void MMIProcessActionMsg(void);

#if defined(__MMI_PHB_CALL_SHOW_PICTURE_FROM_FILE__)
extern S8 *mmi_phb_image_get_path_from_id(U16 index);
#endif 


/*****************************************************************************
 * FUNCTION
 *  ReinitializeOutgoingCall
 * DESCRIPTION
 *  To ReInitialize the Outgoing Call Management Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReinitializeOutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDialIndication(FALSE);
#ifdef __IP_NUMBER__
    SetTempUseIPNumber(FALSE);
#endif 

    SetProtocolEventHandler(PsCBackPlayInternalTone, PRT_PLAY_GSM_TONE);
    SetProtocolEventHandler(OutgoingCallConnected, PRT_OUTGOINGCALL_CONNECTED);
    SetProtocolEventHandler(PsCbackOutgoingCallIdSync, PRT_OUTGOINGCALL_EVENT_RSP);
    SetProtocolEventHandler(PsCBackUSSDResponse, PRT_USSD_RES_SUCCESS);
#ifdef __MMI_DUAL_SIM_MASTER__
    SetSlaveProtocolEventHandler(mmi_gsm_slave_ussd_response, PRT_USSD_RES_SUCCESS);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(MakeCallReqInd, PRT_MMI_MAKE_CALL_REQ_IND);
	#endif /* MMI_ON_HARDWARE_P */
}


/*****************************************************************************
 * FUNCTION
 *  InitOutGoingCall
 * DESCRIPTION
 *  To Initialize the Outgoing Call Management Application
 *  
 *  This function sets up the handlers required for event flow and
 *  application management.This function is invoked from InitIncomingCall.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitOutGoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReinitializeOutgoingCall();

    SetHiliteHandler(MITEM2011_CM_S_ACTIVE_END, HiliteM2019AllActiveEnd);
    SetHiliteHandler(MITEM2011_CM_END_SINGLE, HiliteM2011EndSingle);
    SetHiliteHandler(MITEM2011_CM_INC_END_SINGLE, HiliteM2011IncEndSingle);
    SetHiliteHandler(MITEM2019_CM_ALL_ACTIVE_END, HiliteM2019AllActiveEnd);
    SetHiliteHandler(MITEM2020_CM_ALL_HELD_END, HiliteM2020AllHeldEnd);
    SetHiliteHandler(MITEM2050_CM_END_HELD_ENDALL_HELD, HiliteM2020AllHeldEnd);
    SetHiliteHandler(MITEM2011_CM_END, HiliteM2016AllCallEnd);
    SetHiliteHandler(MITEM2011_CM_END_ALL, HiliteM2016AllCallEnd);
    SetHiliteHandler(MITEM2016_CM_ALL_CALL_END, HiliteM2016AllCallEnd);
    SetHiliteHandler(MITEM_OUTGOING_REJECT, HiliteIncomingReject);

    SetHiliteHandler(MITEM2010_CM_ACTIVE_HOLD, HiliteM2010ActiveHold);
    SetHiliteHandler(MITEM2010_CM_M_ACTIVE_HOLD, HiliteM2010ActiveHold);
    SetHiliteHandler(MITEM2012_CM_HELD_RETRIEVE, HiliteM2012HeldRetrieve);
    SetHiliteHandler(MITEM2012_CM_M_HELD_RETRIEVE, HiliteM2012HeldRetrieve);
    SetHiliteHandler(MITEM2014_CM_CALL_SWAP, HiliteM2014Swap);
    SetHiliteHandler(MITEM2015_CM_CALL_CONFER, HiliteM2015Conference);
    SetHiliteHandler(MITEM2017_CM_CALL_TRANSFER, HiliteM2017Transfer);
    SetHiliteHandler(MITEM2018_CM_CALL_SPLIT, HiliteM2018Split);

    SetHiliteHandler(MITEM2031_CM_PBOOK, HiliteM2031PBookAppEntry);
    SetHiliteHandler(MITEM2032_CM_SMS, HiliteM2032MsgAppEntry);
#ifdef __MMI_VOICE_MEMO__
    SetHiliteHandler(MITEM2022_CM_VOICE_MEMO, HiliteM2022VoiceMemo);
#endif 
#ifdef __MMI_SOUND_RECORDER__
    SetHiliteHandler(MITEM2026_CM_SOUND_RECORDER, HiliteM2026SoundRecorder);
#endif 
#ifdef __MMI_AUDIO_PLAYER__
    SetHiliteHandler(MITEM2025_CM_AUDIO_PLAYER, HiliteM2025AudioPlayer);
#endif 

#if defined(__MMI_BT_SUPPORT__)
    SetHiliteHandler(MITEM_CM_BT_SETPATH, HiliteBTCMSetPath);
#endif 

    SetHiliteHandler(MITEM2020_CM_MUTE, HiliteM2020Mute);
    SetHiliteHandler(MITEM2024_CM_DTMF, HiliteM2024DTMF);
    SetHiliteHandler(MITEM2021_CM_NEWCALL, HiliteM2021NewCall);
#ifdef __CTM_SUPPORT__
    SetHiliteHandler(MITEM2027_CM_CTM, HiliteM2027CTM);
#endif 

    SetHintHandler(MITEM2020_CM_MUTE, Hint2020Mute);
    SetHintHandler(MITEM2024_CM_DTMF, Hint2024DTMF);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2011EndSingle
 * DESCRIPTION
 *  hilite handler to invoke End Single function call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2011EndSingle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2011 End Single \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
#ifdef __PS_SERVICE__
    SetLeftSoftkeyFunction(HangupHilited, KEY_EVENT_UP);
#else 
    SetLeftSoftkeyFunction(EndSingleAndGoBack, KEY_EVENT_UP);
#endif 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2011IncEndSingle
 * DESCRIPTION
 *  hilite handler to invoke End Single function call
 *  when MT call present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2011IncEndSingle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2011 End Single \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(EndSingleAndGoBack, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2011SingleActiveEnd
 * DESCRIPTION
 *  Hilite function for selecting active call to end
 *  
 *  In case there is only one active call the incoming call must be accepted
 *  otherwise a screen to select an active call to end must be Shown
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2011SingleActiveEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EndSingleActiveAndGoBack, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2019AllActiveEnd
 * DESCRIPTION
 *  hilite handler to invoke function that hangup all the active call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2019AllActiveEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2019 AllActiveEnd \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(HangupallActive, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2020AllHeldEnd
 * DESCRIPTION
 *  hilite handler to invoke the function that hangup all the heldcall
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2020AllHeldEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2020 AllHeldEnd \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(HangupallHeld, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2016AllCallEnd
 * DESCRIPTION
 *  hilite handler to invoke the hangup of all the calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2016AllCallEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2016 AllCallEnd \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(KbCBackEndAllCallsExceptIncoming, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteIncomingReject
 * DESCRIPTION
 *  hilite handler to incoming reject call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteIncomingReject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n HiliteIncomingReject\n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(KbCBackCallIncomingRejected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2010ActiveHold
 * DESCRIPTION
 *  hilite handler to invoke the hold function call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2010ActiveHold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2010 ActiveHold\n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(MakeActiveCallHold, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2012HeldRetrieve
 * DESCRIPTION
 *  hilite handler to invoke the Retrieve function call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2012HeldRetrieve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2012 HeldRetrieve \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(RetrieveHeldCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2014Swap
 * DESCRIPTION
 *  hilite handler to invoke the Swap function call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2014Swap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2014 Swap \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(SwapCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2015Conference
 * DESCRIPTION
 *  hilite handler to invoke the Conference function call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2015Conference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2015 Conference \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(ConferenceCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2017Transfer
 * DESCRIPTION
 *  hilite handler to invoke the function that transfer the call
 *  
 *  yet to  implement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2017Transfer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2017 Transfer \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(TransferCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2018Split
 * DESCRIPTION
 *  hilite handler to invoke the Split function call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2018Split(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2018 Split \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
#ifdef __PS_SERVICE__
    SetLeftSoftkeyFunction(SplitHilited, KEY_EVENT_UP);
#else 
    SetLeftSoftkeyFunction(SplitAndGoBack, KEY_EVENT_UP);
#endif 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DummyEnterPhbFrmActiveCall
 * DESCRIPTION
 *  set CM screen flag before go to PHB application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyEnterPhbFrmActiveCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCMScrnFlag(FALSE);
    mmi_phb_call_enter_from_active_call();
    DeleteScreenIfPresent(SCR1003_CM_ACTIVECALLOPTIONS);    
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2031PBookAppEntry
 * DESCRIPTION
 *  hilite handler to invoke the Pbook app entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2031PBookAppEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2031 PBookAppEntry \n");

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetKeyHandler(DummyEnterPhbFrmActiveCall, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(DummyEnterPhbFrmActiveCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DummyPreEntryScrMessagesMenuList
 * DESCRIPTION
 *  set CM screen flag before go to SMS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyPreEntryScrMessagesMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCMScrnFlag(FALSE);
    PreEntryScrMessagesMenuList();
    DeleteScreenIfPresent(SCR1003_CM_ACTIVECALLOPTIONS);    
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2032MsgAppEntry
 * DESCRIPTION
 *  hilite handler to invoke the Msg App Entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2032MsgAppEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2032 MsgAppEntry \n");

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetKeyHandler(DummyPreEntryScrMessagesMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(DummyPreEntryScrMessagesMenuList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#ifdef __MMI_VOICE_MEMO__


/*****************************************************************************
 * FUNCTION
 *  DummyEntryVoiceMemoInCall
 * DESCRIPTION
 *  set CM screen flag before go to Voice Memo application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyEntryVoiceMemoInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCMScrnFlag(FALSE);
    EntryVoiceMemoInCall();
    DeleteScreenIfPresent(SCR1003_CM_ACTIVECALLOPTIONS);    
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2022VoiceMemo
 * DESCRIPTION
 *  hilite handler to invoke the VoiceMemo function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2022VoiceMemo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2022 Voice Memo \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(DummyEntryVoiceMemoInCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VOICE_MEMO__ */ 

#ifdef __MMI_SOUND_RECORDER__


/*****************************************************************************
 * FUNCTION
 *  DummyEntrySoundRecorderInCall
 * DESCRIPTION
 *  set CM screen flag before go to Sound Recorder application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyEntrySoundRecorderInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCMScrnFlag(FALSE);
    mmi_sndrec_entry_in_call();
    DeleteScreenIfPresent(SCR1003_CM_ACTIVECALLOPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2026SoundRecorder
 * DESCRIPTION
 *  hilite handler to invoke the VoiceMemo function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2026SoundRecorder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2026 Sound Recorder \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(DummyEntrySoundRecorderInCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_SOUND_RECORDER__ */ 

#ifdef __MMI_AUDIO_PLAYER__


/*****************************************************************************
 * FUNCTION
 *  DummyEntryAudioPlayerInCall
 * DESCRIPTION
 *  set CM screen flag before go to Audio Player application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyEntryAudioPlayerInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCMScrnFlag(FALSE);
    mmi_audply_entry_main();
    DeleteScreenIfPresent(SCR1003_CM_ACTIVECALLOPTIONS);    
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2025AudioPlayer
 * DESCRIPTION
 *  hilite handler to invoke the AudioPlayer function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2025AudioPlayer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2025 Audio Player \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(DummyEntryAudioPlayerInCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_AUDIO_PLAYER__ */ 

#if defined(__MMI_BT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  HiliteBTCMSetPath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteBTCMSetPath(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n CM--BT Set Voice Path \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(ProcessBTSetVoicePath, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ProcessBTSetVoicePath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessBTSetVoicePath(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_incall_aud_swap2bt() == MMI_TRUE)
    {
        /* Current voice path in BT, shall transfer to AG */
        mmi_bt_switch_voice_path_incall(MMI_FALSE);
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }
    else
    {
        /* Current voice path in AG, shall transfer to BT */
        mmi_bt_switch_voice_path_incall(MMI_TRUE);
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 

    }
}

#endif /* defined(__MMI_BT_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  HiliteM2020Mute
 * DESCRIPTION
 *  hilite handler to invoke the Mute function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2020Mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2020 Mute \n");

    if (IsPhoneInMute())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_SCR1002_OFF_LSK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_SCR1002_ON_LSK);
    }

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(OptionMuteorUnMutetheCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2024DTMF
 * DESCRIPTION
 *  hilite handler to invoke the DTMF function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2024DTMF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2024 DTMF \n");

    if (GetDTMFFlag() == TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_SCR1002_OFF_LSK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_SCR1002_ON_LSK);
    }

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(DTMFFunction, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#ifdef __CTM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  HiliteM2027CTM
 * DESCRIPTION
 *  hilite handler to invoke the CTM connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2027CTM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2027 CTM \n");

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_ctm_connect, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __CTM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  HiliteM2023LoudSp
 * DESCRIPTION
 *  hilite handler to invoke the LoudSpeaker function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2023LoudSp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2023 Loud Speaker \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(LoudSpeakerFunction /* fromOptions */ , KEY_EVENT_UP);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteM2021NewCall
 * DESCRIPTION
 *  hilite handler to invoke the NewCall function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteM2021NewCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n 2021 New Call \n");

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SCR1003_LSK);
    SetLeftSoftkeyFunction(EnterScreenAndHandleDigit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  Hint2020Mute
 * DESCRIPTION
 *  hint handler to get mute status
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Hint2020Mute(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsPhoneInMute() == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  Hint2024DTMF
 * DESCRIPTION
 *  hint handler to get dtmf status
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Hint2024DTMF(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetDTMFFlag() == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakeMOForAT
 * DESCRIPTION
 *  Makes MO Call from AT Command
 * PARAMETERS
 *  num             [IN]        
 *  length          [IN]        
 *  callType        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MakeMOForAT(PS8 num, U8 length, U8 callType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHB_CM_INTERFACE phb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() == CM_OUTGOING_STATE)
    {
        ASSERT(0);
    }

    memset(&gCurrOutcall, 0, sizeof(OUTGOING_CALL));
    if (strlen((void*)num) > MAX_DIGIT)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"Number too big\n");
        ShowCallManagementErrorMessage(ERR_INVALID_NUMBER_FORMAT, cm_p->ucm_operation);
        return;
    }

    if (length > 0)
    {
        mmi_asc_to_ucs2((PS8) gCurrOutcall.Number, (PS8) num);
    }

    SetPreviousState((CALL_STATE) GetCurrentState());
    SetCurrentState(CM_OUTGOING_STATE);

    gtmpOutgoingIndex = GetFirstFreeIndex();
    AddNewCallInfo(
        (PU8) gCurrOutcall.Number,
        GetCurrentState(),
        GetPreviousState(),
        CM_CALL_MO,
        MMI_UCM_INVALID_ID,
        callType);

    SetCCFlag(TRUE);
    SetDialIndication(FALSE);

    if (length > 0)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        phb_data = mmi_phb_call_get_data_for_call_mgnt((PU8) gCurrOutcall.Number, TRUE, SIM1);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        phb_data = mmi_phb_call_get_data_for_call_mgnt((PU8) gCurrOutcall.Number, TRUE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        SetCMPhoneBookStruct(&phb_data);
        SetOutgoingNamefromPhonebook();
    }    	

    SetProtocolEventHandler(OutgoingCallConnected, PRT_OUTGOINGCALL_CONNECTED);

    mmi_gsm_dial_req_ind();
}

/*****************************************************************************
 * FUNCTION
 *  MakeMOForAT
 * DESCRIPTION
 *  Makes MO CSD Call from ABM
 * PARAMETERS
 *  num             [IN]        
 *  length          [IN]        
 *  callType        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCSDForABM(PS8 num, U8 length, U8 callType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHB_CM_INTERFACE phb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() == CM_OUTGOING_STATE)
    {
        ASSERT(0);
    }

    memset(&gCurrOutcall, 0, sizeof(OUTGOING_CALL));
    if (strlen((void*)num) > MAX_DIGIT)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"Number too big\n");
        ShowCallManagementErrorMessage(ERR_INVALID_NUMBER_FORMAT, cm_p->ucm_operation);
        return;
    }

    if (length > 0)
    {
        mmi_asc_to_ucs2((PS8) gCurrOutcall.Number, (PS8) num);
    }

    SetPreviousState((CALL_STATE) GetCurrentState());
    SetCurrentState(CM_OUTGOING_STATE);

    gtmpOutgoingIndex = GetFirstFreeIndex();
    AddNewCallInfo(
        (PU8) gCurrOutcall.Number,
        GetCurrentState(),
        GetPreviousState(),
        CM_CALL_MO,
        MMI_UCM_INVALID_ID,
        callType);

    SetCCFlag(TRUE);
    SetDialIndication(FALSE);

    if (length > 0)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        phb_data = mmi_phb_call_get_data_for_call_mgnt((PU8) gCurrOutcall.Number, TRUE, SIM1);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        phb_data = mmi_phb_call_get_data_for_call_mgnt((PU8) gCurrOutcall.Number, TRUE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        SetCMPhoneBookStruct(&phb_data);
        SetOutgoingNamefromPhonebook();
    }    	

    SetProtocolEventHandler(OutgoingCallConnected, PRT_OUTGOINGCALL_CONNECTED);

    mmi_gsm_dial_rsp(TRUE, CC_OPERATION, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  OutgoingProcessCMEvent
 * DESCRIPTION
 *  This is the Entry function for all the Events while the Call-Management application
 *  is Active.
 *  
 *  This function handles the events from both keyboard and protocol stack.
 *  The keyboard events have KB in there defination and Protocol has PS.
 * PARAMETERS
 *  inEvenType      [IN]        
 *  MsgStruct       [?]         
 *  pointer(?)      [IN]        To the event's associated structure)
 * RETURNS
 *  void
 *****************************************************************************/
void OutgoingProcessCMEvent(CM_EVENT_TYPES inEvenType, void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ACTION_RESULT result = CM_CALL_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX In OutgoingProcessCMEvent\n");

    switch (inEvenType)
    {
        case CM_PS_SHOW_OUTGOING_CALL_SCREEN:
            ProcessShowOutgoingCallScreen();
            break;

        case CM_PS_SHOW_REQUESTING_CALL_SCREEN:
            if (GetActiveScreenId() == SCR_CM_REQUESTINGUSSD)
            {
                /* current active screen is SS requesting, display and remove previous*/
                EntryScrUSSDReq();
                RemoveSSReqScr();
                SetDelScrnIDCallbackHandler(SCR_CM_REQUESTINGUSSD, (HistoryDelCBPtr) SSReqHistoryDelHdlr);                
            }
            else if (IsScreenPresent(SCR_CM_REQUESTINGUSSD))
            {
                /* SS requesting screen is in history, do nothing */
            }
            else
            {
                /* current active screen is NOT SS requesting, not in history also, display requesting screen*/
                EntryScrUSSDReq();
            }
            
            /* if (IsScreenPresent(CM_SCR_MARKER) == FALSE)
               AddMarkerToHistory(); */
            break;

        case CM_PS_USSD_RECVD:
            ProcessUSSDrecieved(MsgStruct);
            break;

        case CM_KB_OUTGOINGCALL:
            /* MO SEND key */
            result = ProcessKBOutgoingEvent(MsgStruct);
            break;

        case CM_PS_CALLCONNECTED:
            /* connect ind */
            result = ProcessPSCallconnectedEvent(MsgStruct);
            break;

        case CM_KB_HANGUPREQ:
            /* 1X send, drop single call */
            result = ProcessKBHangupReqEvent(MsgStruct);
            break;

        case CM_PS_HANGUPSUC:
            result = ProcessPSHangupSucEvent(MsgStruct);
            break;

        case CM_KB_HANGUPALLREQ:
            /* END key in CM */
            result = ProcessKBHangupallReqEvent(MsgStruct);
            break;

        case CM_PS_HANGUPALLSUC:
            result = ProcessPSHangupallSucEvent(MsgStruct);
            break;

        case CM_KB_HANGUPALLACTREQ:
            /* Menu End All Active */
            result = ProcessKBHangupallActReqEvent(MsgStruct);
            break;

        case CM_PS_HANGUPALLACTSUC:
            result = ProcessPSHangupallActSucEvent(MsgStruct);
            break;

        case CM_KB_HANGUPALLHLDREQ:
            result = ProcessKBHangupallHldReqEvent(MsgStruct);
            break;

        case CM_PS_HANGUPALLHLDSUC:
            result = ProcessPSHangupallHldSucEvent(MsgStruct);
            break;

        case CM_KB_HOLDREQ:
            result = ProcessKBHoldReqEvent(MsgStruct);
            break;

        case CM_PS_HOLDSUC:
            result = ProcessPSHoldSucEvent(MsgStruct);
            break;

        case CM_KB_RETRIEVEREQ:
            result = ProcessKBRetrieveReqEvent(MsgStruct);
            break;

        case CM_PS_RETRIEVESUC:
            result = ProcessPSRetrieveSucEvent(MsgStruct);
            break;

        case CM_KB_SWAPREQ:
            result = ProcessKBSwapReqEvent(MsgStruct);
            break;

        case CM_PS_SWAPSUC:
            result = ProcessPSSwapSucEvent(MsgStruct);
            break;

        case CM_KB_CONFREQ:
            result = ProcessKBConfReqEvent(MsgStruct);
            break;

        case CM_PS_CONFSUC:
            result = ProcessPSConfSucEvent(MsgStruct);
            break;

        case CM_KB_SPLITREQ:
            result = ProcessKBSplitReqEvent(MsgStruct);
            break;

        case CM_PS_SPLITSUC:
            result = ProcessPSSplitSucEvent(MsgStruct);
            break;

        case CM_KB_ECT_REQ:
            result = ProcessKBEctReqEvent(MsgStruct);
            break;

             case CM_PS_ECT_SUC:
               result=ProcessPSEctSuccessful(MsgStruct);
               break; 

        case CM_KB_CALL_DEFLECT_REQ:
            MakePsCallDeflect((void*)PsCBackCallDeflected, (PU8) MsgStruct);
            ShowCategory302Screen(NULL);
            break;

        case CM_PS_INCOMING_CALL_DEFLECT:
			if(cm_p->ucm_operation)
			{
				mmi_gsm_deflect_rsp(TRUE, NULL);
			}
            break;

        default:
            PRINT_INFORMATION("\n CM Event Handler does not exist \n");
            break;
    }
    PRINT_INFORMATION_2(MMI_TRACE_G5_CM, "*-------[OutgoingCallManagement.c] OutgoingProcessCMEvent: result = "
                         " %d-------*\n", (int)result);
}


/*****************************************************************************
 * FUNCTION
 *  ProcessShowOutgoingCallScreen
 * DESCRIPTION
 *  This is the function to show outgoing call only when the Call list is recieved
 *  
 *  This invokes the protocol function if the state is in Idle/hold state.
 *  In Active state,it makes the request to hold and after success it initiates the call.
 * PARAMETERS
 *  void
 *  void(?)                 [IN]        *(this points to OUTGOING_CALL structure)
 *  ACTION_RESULT(?)        [OUT]       
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.(?)
 *****************************************************************************/
void ProcessShowOutgoingCallScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX In ProcessShowOutgoingCallScreen \n");

    switch (GetPreviousState())
    {
        case CM_IDLE_STATE:
            /* do not have to suspend audio for CSD call */
            EntryScr1001OutgoingCall();
            if (GetOutgoingCallType() != CM_CSD_CALL)
            {
                mdi_audio_suspend_background_play();
            }
            if (IsScreenPresent(CM_SCR_MARKER) == FALSE)
            {
                AddMarkerToHistory();
            }
            break;

        case CM_INCOMING_STATE:
        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            EntryScr1001OutgoingCall();
            if (GetOutgoingCallOrigin() == CM_CALL_MO_STK)
            {
                AddMarkerToHistory();
            }
            break;

        default:
            PRINT_INFORMATION("\n KBOutgoingEvent CM State Machine is in incorrect state \n");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBOutgoingEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_OUTGOINGCALL.
 *  
 *  This invokes the protocol function if the state is in Idle/hold state.
 *  In Active state,it makes the request to hold and after success it initiates the call.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to OUTGOING_CALL structure)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBOutgoingEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USSD_REPLY_UCS2__
        {
            OUTGOING_CALL * p = (OUTGOING_CALL*)MsgStruct;
            if ( p->bIsUcs2 )
        memcpy(&gCurrOutcall, MsgStruct, sizeof(OUTGOING_CALL));
            else {
                memset(&gCurrOutcall, 0, sizeof(OUTGOING_CALL));
                mmi_asc_to_ucs2((S8 *)gCurrOutcall.Number, (S8 *)p->Number);
                gCurrOutcall.call_type = p->call_type;
            }
        }
#else /*__MMI_USSD_REPLY_UCS2__*/
        memcpy(&gCurrOutcall, MsgStruct, sizeof(OUTGOING_CALL));
#endif /*__MMI_USSD_REPLY_UCS2__*/

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            if (AllowMoreCalls() && DTMFPadCallBuffer[0] != 0)
            {
                SetPreviousState(CM_IDLE_STATE);
                SetCurrentState(CM_OUTGOING_STATE);

                gtmpOutgoingIndex = GetFirstFreeIndex();
                AddNewCallInfo(
                    gCurrOutcall.Number,
                    CM_OUTGOING_STATE,
                    CM_IDLE_STATE,
                    CM_CALL_MO,
                    (CM_CALL_HANDLE) (255), /*255 for temp call id*/
                    gCurrOutcall.call_type);

                #ifdef __MMI_USSD_REPLY_UCS2__
                    MakePsInitiateCall((PU8)MsgStruct, (void*)OutgoingCallConnected);
                #else /*__MMI_USSD_REPLY_UCS2__*/
                    MakePsInitiateCall((PU8) DTMFPadCallBuffer, (void*)OutgoingCallConnected);
                #endif /*__MMI_USSD_REPLY_UCS2__*/

            }
            else
            {
                ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
                return CM_CALL_FAILURE;
            }
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("XXX In ProcessKBOutgoingEvent already outgoing, can't make MO\n");
            ShowCallManagementErrorMessage(ERR_L4C_GEN_CAUSE, cm_p->ucm_operation);
            return CM_CALL_FAILURE;

        case CM_INCOMING_STATE:
        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            if (AllowMoreCalls())
            {
                /* send SS when MT call and previous USSR seession exists,
            	   need to abort previous session */
                DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
                DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);
            	
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_OUTGOING_STATE);

                gtmpOutgoingIndex = GetFirstFreeIndex();
                AddNewCallInfo(
                    gCurrOutcall.Number,
                    GetCurrentState(),
                    CM_IDLE_STATE,
                    CM_CALL_MO,
                    (CM_CALL_HANDLE) (255), /*255 for temp call id*/
                    gCurrOutcall.call_type);
            #ifdef __MMI_USSD_REPLY_UCS2__ 
                MakePsInitiateCall((PU8)MsgStruct, (void*)OutgoingCallConnected);
            #else /*__MMI_USSD_REPLY_UCS2__*/
                MakePsInitiateCall((PU8) DTMFPadCallBuffer, (void*)OutgoingCallConnected);
            #endif /*__MMI_USSD_REPLY_UCS2__*/
            }
            else
            {
        	    /* send SS when MT call and previous USSR seession exists,
            	   need to abort previous session */
            	DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
            	DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);
            	
                ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
                return CM_CALL_FAILURE;
            }
            break;

        default:
            PRINT_INFORMATION("\n KBOutgoingEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }

    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSCallconnectedEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_CALLCONNECTED.
 *  
 *  This change the state of the call to ACTIVE & also changes the
 *  state of the State m/c.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to CM_CALL_HANDLE of the call which requested CM_KB_OUTGOINGCALL)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSCallconnectedEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE callHandle;
    CM_CALL_HANDLE *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (CM_CALL_HANDLE*) MsgStruct;
    callHandle = *handle;

    if (callHandle == -1)
    {
        PRINT_INFORMATION("\n PSCallconnectedEvent Getting the Connected Handle has -1 \n");
        return CM_CALL_FAILURE;
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSCallconnectedEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            MakeHold();
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_ACTIVE_STATE);

            SetCallState(gtmpOutgoingIndex, CM_ACTIVE_STATE, FALSE);

            if (GetTotalCallCount() > 1)
            {
                CM_CALL_HANDLE handle;

                handle = GetIncomingCallHandle();
                if (handle != -1)
                {
                    PHB_CM_INTERFACE phb_data;

                    SetPreviousState(CM_ACTIVE_STATE);
                    SetCurrentState(CM_INCOMING_STATE);

                    /* MT call caller picture, ringtone...will be overwrite by MO call, 
                       it needs to be restored after MO call connected */
                #ifdef __MMI_DUAL_SIM_MASTER__
                    phb_data = mmi_phb_call_get_data_for_call_mgnt(GetCallNumber(handle), FALSE, SIM1);
                #else /* __MMI_DUAL_SIM_MASTER__ */
                    phb_data = mmi_phb_call_get_data_for_call_mgnt(GetCallNumber(handle), FALSE);
                #endif /* __MMI_DUAL_SIM_MASTER__ */
                #ifdef __MMI_INCOMING_CALL_VIDEO__
                    /* waiting call and ccbs invoke can't use video for display */
                    if (GetTotalCallCount() > 0 || GetCCBSFlag() == TRUE)
                    {
                        phb_data.videoId = 0;
                    }
                #endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
                    SetCMPhoneBookStruct(&phb_data);
                }
            }
            mmi_gsm_connect_ind(callHandle);
            break;

        case CM_INCOMING_STATE:
            PRINT_INFORMATION("\n PSCallconnectedEvent CM_INCOMING_STATE not handled still \n");
            break;

        case CM_ACTIVE_STATE:
            PRINT_INFORMATION("\n PSCallconnectedEvent CM_ACTIVE_STATE not handled still \n");
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n PSCallconnectedEvent CM_HOLD_STATE not handled still \n");
            break;

        default:
            PRINT_INFORMATION("\n PSCallconnectedEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBHangupReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_HANGUPREQ.
 *  
 *  This Sets the flag CM_HANGUP_REQUESTED and invoke the protocol function irrespective of the state.
 *  The chances of this being invoked in idle state is very less.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to CM_CALL_HANDLE of the call to get dropped)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBHangupReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;
    CALL_STATE state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX In ProcessKBHangupReqEvent\n");

    if (GetInternalAlert() == TRUE)
    {
        StopInternalOutgoingTone();
    }

    handle = *((CM_CALL_HANDLE*) MsgStruct);

    state = GetCallState(handle);
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\nKBHangupEvent CM_IDLE_STATE not handled still \n");
            break;
        case CM_OUTGOING_STATE:
            SetCallflag(handle, CM_HANGUP_REQUESTED, TRUE);
            if (state == CM_ACTIVE_STATE || state == CM_HOLD_STATE || state == CM_INCOMING_STATE)
            {
                /* Start by Julia: Drop call refinement */
                SetCallState(handle, CM_DISCONNECTING_STATE, TRUE);
                //EntryScr1001OutgoingCall();
                // End by Julia
                MakePsEndSelectiveCall((void*)HangupReqSucess, handle);
            }
            else if ((GetDialIndication() == FALSE) || (GetOutgoingCallType() == CM_CSD_CALL))
            {
                SetCallAbortReqSentFlag(TRUE);
                /* Start by Julia: Drop call refinement */
                handle = GetOutgoingCallHandle();
                SetCallState(handle, CM_DISCONNECTING_STATE, TRUE);
                //EntryScr1001OutgoingCall();
                // End by Julia
                MakePsAthRequest((void*)PsCBackOutgoingCallEnded);
            }
            else
            {
                /* Start by Julia: Drop call refinement */
                SetCallState(handle, CM_DISCONNECTING_STATE, TRUE);
                //EntryScr1001OutgoingCall();
                // End by Julia
                MakePsEndSelectiveCall((void*)HangupReqSucess, handle);
            }
            break;
        case CM_INCOMING_STATE:
            // Start by Julia: Drop call refinement
            // Drop call refinement is not applicable when waiting call exists
            SetCallflag(handle, CM_HANGUP_REQUESTED, TRUE);
            MakePsEndSelectiveCall((void*)HangupReqSucess, handle);
            break;
            /* End by Julia */
        case CM_ACTIVE_STATE:
        case CM_HOLD_STATE:
            SetCallflag(handle, CM_HANGUP_REQUESTED, TRUE);
            /* Start by Julia: Drop call refinement */
            SetCallState(handle, CM_DISCONNECTING_STATE, TRUE);
            //EntryScr1002ActiveCall();
            // End by Julia
            MakePsEndSelectiveCall((void*)HangupReqSucess, handle);
            break;
        default:
            PRINT_INFORMATION("\n KBHangupEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSHangupSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_HANGUPSUC.
 *  
 *  This resets the CM_HANGUP_REQUESTED flag and then change the states of the call to IDLE
 *  if necessary it also changes the state of the State m/c.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to CM_CALL_HANDLE of the call which requested CM_KB_HANGUPREQ)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSHangupSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE *handle;
    U8 flag = FALSE;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent XXX");
    PRINT_INFORMATION("\n X@X@X@X!!\n");

    handle = (CM_CALL_HANDLE*) MsgStruct;
    if ((*handle == -1) || (GetMMIStructIndexof(*handle) == -1))
    {
        PRINT_INFORMATION("\nBad call handle -1 in HangupSuc\n");
		ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
        return CM_CALL_FAILURE;
    }

    /*Store uid info for UCM release ind*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if(cm_p->state_info.AllCalls[count].call_handle == (*handle))
        {
            cm_p->disc_call.ucm_current_uid.call_id = cm_p->state_info.AllCalls[count].call_handle;
            cm_p->disc_call.ucm_current_uid.group_id = cm_p->state_info.AllCalls[count].group_id;
            cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);            
            cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */
         #ifdef __SAT__            
            if (GetCallDirFlag(*handle) == CM_CALL_MO_STK)
            {
                if (GetCurrentState() == CM_OUTGOING_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_BEFORE_CONNECT);
                }
                else if (GetCurrentState() == CM_ACTIVE_STATE || GetCurrentState() == CM_HOLD_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_AFTER_CONNECT);
                }
            }
        #endif /* __SAT__ */ 
        }
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSHangupSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent : Outgoing StateXXX");
            
            if (GetCallState(*handle) == CM_OUTGOING_STATE)
            {
                PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent : Call being dropped is outgoingXXX");
                flag = TRUE;
            }
            
            ResetCallflag((*handle), CM_HANGUP_REQUESTED, TRUE);
            SetCallState((*handle), CM_IDLE_STATE, TRUE);
            if (GetTotalCallCount() == 0)
            {
                PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent :GetTotalCallCount=0XXX");
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_IDLE_STATE);
            }
            else
            {
                PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent :GetTotalCallCount not 0 XXX");
                if (flag)
                {
                    SetCurrentState(GetPreviousState());
                    SetPreviousState(CM_OUTGOING_STATE);
                }
                /*else if (CM_OUTGOING_STATE == GetCurrentState())
                {
                    break;
                }*/

                if (GetTotalCallCount() == GetTotalHoldCallCount())
                {
                    SetPreviousState(GetCurrentState());
                    SetCurrentState(CM_HOLD_STATE);
                }
            }

            mmi_gsm_release_ind(GetCallEndCause());

            if(cm_p->ucm_operation == MMI_GSM_UCM_END_SINGLE && GetCallAbortReqSentFlag() == TRUE)
            {
                SetCallAbortReqSentFlag(FALSE);
                mmi_gsm_end_single_rsp(TRUE, NULL);
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT && GetCallAbortReqSentFlag() == TRUE)
            {
                SetCallAbortReqSentFlag(FALSE);
                mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ALL && GetCallAbortReqSentFlag() == TRUE)
            {
                SetCallAbortReqSentFlag(FALSE);
                mmi_gsm_end_all_rsp(TRUE, NULL);
            }
            
            break;

        case CM_INCOMING_STATE:
            PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent : Incoming StateXXX");
            /* rel active and accept waiting but waiting is released by network */
            if (GetIncomingCallHandle() == *handle)
            {
                SetCurrentState(GetPreviousState());
                SetPreviousState(CM_INCOMING_STATE);
                SetCallState((*handle), CM_IDLE_STATE, TRUE);
            }
            else
            {
                SetCallState((*handle), CM_IDLE_STATE, TRUE);

                if (GetTotalActiveCallCount() != 0)
                {
                    SetPreviousState(CM_ACTIVE_STATE);
                }
                else if (GetTotalHoldCallCount() != 0)
                {
                    SetPreviousState(CM_HOLD_STATE);
                }
            }

            mmi_gsm_release_ind(GetCallEndCause());

            if(cm_p->ucm_operation == MMI_GSM_UCM_END_SINGLE && (*handle == MMI_UCM_INVALID_ID))
            {
                mmi_gsm_end_single_rsp(TRUE, NULL);
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT && (*handle == MMI_UCM_INVALID_ID))
            {
                mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ALL && (*handle == MMI_UCM_INVALID_ID))
            {
                mmi_gsm_end_all_rsp(TRUE, NULL);
            }
            
            break;

        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            PRINT_INFORMATION("XXX In ProcessPSHangupSucEvent : HOLD/Active StateXXX");
            ResetCallflag((*handle), CM_HANGUP_REQUESTED, TRUE);
            SetCallState((*handle), CM_IDLE_STATE, TRUE);

            if (GetTotalCallCount() == 0)
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_IDLE_STATE);
            }
            else if ((GetTotalActiveCallCount() == 0) && (GetTotalCallCount() == GetTotalHoldCallCount()))
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_HOLD_STATE);
            }

            mmi_gsm_release_ind( GetCallEndCause());

            if(cm_p->ucm_operation == MMI_GSM_UCM_END_SINGLE && GetCallAbortReqSentFlag() == TRUE)
            {
                SetCallAbortReqSentFlag(FALSE);
                mmi_gsm_end_single_rsp(TRUE, NULL);
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT && GetCallAbortReqSentFlag() == TRUE)
            {
                SetCallAbortReqSentFlag(FALSE);
                mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ALL && GetCallAbortReqSentFlag() == TRUE)
            {
                SetCallAbortReqSentFlag(FALSE);
                mmi_gsm_end_all_rsp(TRUE, NULL);
            }

            break;

        default:
            PRINT_INFORMATION("\n PSHangupSucEvent CM State m/c Corrupted \n");

            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBHangupallReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_HANGUPALLREQ.
 *  
 *  This Sets the flag CM_HANGUP_REQUESTED to all the calls
 *  Invoke the protocol function irrespective of the state.
 *  This is always Invoked in Active state.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the Hangup is requested on all calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBHangupallReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBHangupallReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
            // Start by Julia: Drop call refinement
            // Drop call refinement is not applicable when waiting call exists
            SetAllHangupFlag();
            MakePsHangupallRequest((void*)HangupallReqSucess);
            break;
            /* End by Julia */
        case CM_OUTGOING_STATE:
        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            SetAllHangupFlag();
            /* Start by Julia: Drop call refinement */
            SetAllExceptWaitingCallState(CM_DISCONNECTING_STATE);
            //EntryScr1002ActiveCall();
            // End by Julia
            MakePsHangupallRequest((void*)HangupallReqSucess);
            break;
        default:
            PRINT_INFORMATION("\n KBHangupallReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSHangupallSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_HANGUPALLSUC.
 *  
 *  This resets the CM_HANGUP_REQUESTED flag & change the state of the all calls
 *  to IDLE.It also changes the state m/c to IDLE.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_HANGUPALLREQ is on all calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSHangupallSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE *handle;
    CALL_STATE state;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (CM_CALL_HANDLE*) MsgStruct;

    /* Start by Julia: Drop call refinement */
    if ((*handle) == -1 || GetMMIStructIndexof(*handle) == -1)
    {
        /* call already dropped */
        PRINT_INFORMATION("\nBad call handle -1 in HangupAllSuc\n");
		ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
        return CM_CALL_FAILURE;
    }
    
    /*Store uid info for UCM release ind*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if(cm_p->state_info.AllCalls[count].call_handle == *handle)
        {
            cm_p->disc_call.ucm_current_uid.call_id = cm_p->state_info.AllCalls[count].call_handle;
            cm_p->disc_call.ucm_current_uid.group_id = cm_p->state_info.AllCalls[count].group_id;
            cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);
            cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */

        #ifdef __SAT__ 
            if (GetCallDirFlag(cm_p->state_info.AllCalls[count].call_handle) == CM_CALL_MO_STK)
            {
                if (GetCurrentState() == CM_OUTGOING_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_BEFORE_CONNECT);
                }
                else if (GetCurrentState() == CM_ACTIVE_STATE || GetCurrentState() == CM_HOLD_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_AFTER_CONNECT);
                }
            }
        #endif /* __SAT__ */ 
        }
    }

    state = GetCallState(*handle);
    if (state != CM_STATE_UNKNOWN)
    {
        SetCallState((*handle), CM_IDLE_STATE, TRUE);
    }
	
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSHangupallSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_INCOMING_STATE:
        case CM_OUTGOING_STATE:
        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            if (GetTotalCallCount() == 0)
            {
                SetPreviousState(GetCurrentState());
				SetCurrentState(CM_IDLE_STATE);
            }
            else if (state == CM_INCOMING_STATE || state == CM_OUTGOING_STATE)
            {
                SetCurrentState(GetPreviousState());
                SetPreviousState(state);
            }
            
            mmi_gsm_release_ind(GetCallEndCause());
            
            break;
        default:
            PRINT_INFORMATION("\n PSHangupallSucEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBHangupallActReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_HANGUPALLACTREQ.
 *  
 *  This Sets the flag CM_HANGUP_REQUESTED to all the Active calls
 *  Invoke the protocol function irrespective of the state.
 *  This is always Invoked in Active state as active call take precedence over held call.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the Hangup is requested on all Active calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBHangupallActReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBHangupallActReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n KBHangupallActReqEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
            // Start by Julia: Drop call refinement
            // Drop call refinement is not applicable when waiting call exists
            SetAllActHangupFlag();
            MakePsHangupallActiveRequest((void*)HangupallActReqSucess);
            break;
            /* End by Julia */
        case CM_ACTIVE_STATE:
            SetAllActHangupFlag();
            /* Start by Julia: Drop call refinement */
            SetAllActiveCallState(CM_DISCONNECTING_STATE);
            //EntryScr1002ActiveCall();
            // End by Julia
            MakePsHangupallActiveRequest((void*)HangupallActReqSucess);
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n KBHangupallActReqEvent CM_HOLD_STATE not handled still \n");
            break;

        default:
            PRINT_INFORMATION("\n KBHangupallActReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSHangupallActSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_HANGUPALLACTSUC.
 *  
 *  This resets the CM_HANGUP_REQUESTED flag & change the state of the all Active calls
 *  to IDLE.If necessary,It also changes the state of the state m/c.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_HANGUPALLACTREQ is on all Active calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSHangupallActSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE *handle;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n *** In ProcessPSHangupallActSucEvent\n");

    handle = (CM_CALL_HANDLE*) MsgStruct;

    /* Start by Julia: Drop call refinement */
    if ((*handle) == -1)
    {
        PRINT_INFORMATION("\nBad call handle -1 in HangupAllActSuc\n");
		ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
        return CM_CALL_FAILURE;
    }
    
    /*Store uid info for UCM release ind*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if(cm_p->state_info.AllCalls[count].call_handle == *handle)
        {
            cm_p->disc_call.ucm_current_uid.call_id = cm_p->state_info.AllCalls[count].call_handle;
            cm_p->disc_call.ucm_current_uid.group_id = cm_p->state_info.AllCalls[count].group_id;
            cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);            
            cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */
        #ifdef __SAT__ 
            if (GetCallDirFlag(cm_p->state_info.AllCalls[count].call_handle) == CM_CALL_MO_STK)
            {
                if (GetCurrentState() == CM_OUTGOING_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_BEFORE_CONNECT);
                }
                else if (GetCurrentState() == CM_ACTIVE_STATE || GetCurrentState() == CM_HOLD_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_AFTER_CONNECT);
                }
            }
	 #endif /* __SAT__ */ 
        }
    }
    
    SetCallState(*handle, CM_IDLE_STATE, TRUE);
    /*if (GetTotalActiveCallCount() >= 1)
    {
    	if(cm_p->ucm_operation == MMI_GSM_UCM_END_CONFERENCE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
		{
			mmi_gsm_end_conference_rsp(TRUE, NULL);
		}
        return CM_CALL_SUCCESS;
    }*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSHangupallActSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSHangupallActSucEvent CM_OUTGOING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
			break;

        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
            MakeAllActHangup();
            if (GetTotalCallCount() == 0)
            {
                SetPreviousState(GetCurrentState());
				SetCurrentState(CM_IDLE_STATE);
            }
            
            mmi_gsm_release_ind(GetCallEndCause());
            
			/*if(cm_p->ucm_operation == MMI_GSM_UCM_END_CONFERENCE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_conference_rsp(TRUE, NULL);
			}*/
			
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n PSHangupallActSucEvent CM_HOLD_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        default:
            PRINT_INFORMATION("\n Illegal state to be in  \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBHangupallHldReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_HANGUPALLHLDREQ.
 *  
 *  This Sets the flag CM_HANGUP_REQUESTED to all the Hold/Held calls
 *  Invoke the protocol function irrespective of the state.
 *  This is Invoked in Active or Hold state.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the Hangup is requested on all Hold State calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBHangupallHldReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetAllHldHangupFlag();
    // Start by Julia: Drop call refinement
    // Drop call refinement is not applicable when waiting call exists
    if (GetCurrentState() != CM_INCOMING_STATE)
    {
        SetAllHeldCallState(CM_DISCONNECTING_STATE);
        /* EntryScr1002ActiveCall(); */
    }
    /* End by Julia */
    MakePsSendRelHeld((void*)HangupallHldReqSucess);
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSHangupallHldSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_HANGUPALLHLDSUC.
 *  
 *  This resets the CM_HANGUP_REQUESTED flag & change the state of the all held calls
 *  to IDLE.If necessary,It also changes the state of the state m/c.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_HANGUPALLHLDREQ is on all Held/Hold state calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSHangupallHldSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE *handle;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (CM_CALL_HANDLE*) MsgStruct;

    /* Start by Julia: Drop call refinement */
    if ((*handle) == -1)
    {
        PRINT_INFORMATION("\nBad call handle -1 in HangupAllHldSuc\n");
		ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
        return CM_CALL_FAILURE;
    }

    /*Store uid info for UCM release ind*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if(cm_p->state_info.AllCalls[count].call_handle == *handle)
        {
            cm_p->disc_call.ucm_current_uid.call_id = cm_p->state_info.AllCalls[count].call_handle;
            cm_p->disc_call.ucm_current_uid.group_id = cm_p->state_info.AllCalls[count].group_id;
            cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);       
            cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */			

        #ifdef __SAT__ 
            if (GetCallDirFlag(cm_p->state_info.AllCalls[count].call_handle) == CM_CALL_MO_STK)
            {
                if (GetCurrentState() == CM_OUTGOING_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_BEFORE_CONNECT);
                }
                else if (GetCurrentState() == CM_ACTIVE_STATE || GetCurrentState() == CM_HOLD_STATE)
                {
                    SATCallExitCause(SAT_CALL_DISCONNECT_AFTER_CONNECT);
                }
            }
        #endif /* __SAT__ */
        }
    }

    SetCallState((*handle), CM_IDLE_STATE, TRUE);

    /*if (GetTotalHoldCallCount() > 0)
    {
		if(cm_p->ucm_operation == MMI_GSM_UCM_END_CONFERENCE &&
            cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
		{
			mmi_gsm_end_conference_rsp(TRUE, NULL);
		}
        return CM_CALL_SUCCESS;
    }*/

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSHangupallHldSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSHangupallHldSucEvent CM_OUTGOING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_INCOMING_STATE:
            PRINT_INFORMATION("\n PSHangupallHldSucEvent CM_INCOMING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_ACTIVE_STATE:
        case CM_HOLD_STATE:
            if (GetTotalCallCount() == 0)
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_IDLE_STATE);
            }
			/*if(cm_p->ucm_operation == MMI_GSM_UCM_END_CONFERENCE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_conference_rsp(TRUE, NULL);
			}*/
			mmi_gsm_release_ind(GetCallEndCause());
            break;

        default:
            PRINT_INFORMATION("\n PSHangupallHldSucEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBHoldReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_HOLDREQ.
 *  
 *  This Sets the flag CM_HOLD_REQUESTED to all the active call
 *  Invoke the protocol function irrespective of the state.
 *  The chances of this being invoked in Idle or Hold  state is very less.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the hold is request on all active calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBHoldReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetChldReqSent() != CM_ACTION_NONE)
    {
        return CM_CALL_FAILURE;
    }

    flag = GetAllCallFlags();
    if (((flag & CM_SWAP_REQUESTED) != 0) || 
    	((flag & CM_CONF_REQUESTED) != 0) ||
    	((flag & CM_ECT_REQUESTED) != 0))
    {
        return CM_CALL_FAILURE;
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBHoldReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n KBHoldReqEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
            PRINT_INFORMATION("\n KBHoldReqEvent CM_INCOMING_STATE not handled still \n");
            break;

        case CM_ACTIVE_STATE:
            SetHoldFlag();
            MakePsActiveHold((void*)HoldReqSucess);
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n KBHoldReqEvent CM_HOLD_STATE not handled still \n");
            break;

        default:
            PRINT_INFORMATION("\n KBHoldReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }

    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSHoldSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_HOLDSUC.
 *  
 *  This resets the CM_HOLD_REQUESTED flag & change the state of the call from
 *  ACTIVE to HOLD if necessary it also changes the state of the State m/c.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_HOLDREQ is on all active call)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSHoldSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSHoldSucEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSHoldSucEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
            PRINT_INFORMATION("\n PSHoldSucEvent CM_INCOMING_STATE \n");
            MakeHold();
            EntryScr1005NotifyHoldSucess();
            SyncCallList();
            break;

        case CM_ACTIVE_STATE:
            PRINT_INFORMATION("\n PSHoldSucEvent CM_ACTIVE_STATE \n");
            MakeHold();
            EntryScr1005NotifyHoldSucess();
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n HoldSucEvent CM_HOLD_STATE not handled still \n");
            break;

        default:
            PRINT_INFORMATION("\n PSHoldSucEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBRetrieveReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_RETRIEVEREQ.
 *  
 *  This Sets the flag CM_RETRIEVE_REQUESTED to all the held call
 *  Invoke the protocol function irrespective of the state.
 *  The chances of this being invoked in Idle or Active state is very less.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the Retrieve is request on all held calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBRetrieveReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetChldReqSent() != CM_ACTION_NONE)
    {
        return CM_CALL_FAILURE;
    }

    flag = GetAllCallFlags();
    if (((flag & CM_SWAP_REQUESTED) != 0) || 
    	((flag & CM_CONF_REQUESTED) != 0) ||
    	((flag & CM_ECT_REQUESTED) != 0))
    {
        return CM_CALL_FAILURE;
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBRetrieveReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n KBRetrieveReqEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
        case CM_HOLD_STATE:
            SetRetrieveFlag();
            MakePsActiveHold((void*)RetrieveReqSucess);
            break;

        default:
            PRINT_INFORMATION("\n KBRetrieveReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSRetrieveSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_RETRIEVESUC.
 *  
 *  This resets the CM_RETRIEVE_REQUESTED flag & change the state of the call from
 *  HOLD to ACTIVE if necessary it also changes the state of the State m/c.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_RETRIEVEREQ is on all Held/Hold calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSRetrieveSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSRetrieveSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
			break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSRetrieveSucEvent CM_OUTGOING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
			break;

        case CM_INCOMING_STATE:
            PRINT_INFORMATION("\n PSRetrieveSucEvent CM_INCOMING_STATE \n");
            MakeRetrieve();
            SetPreviousState(CM_ACTIVE_STATE);
			if(cm_p->ucm_operation == MMI_GSM_UCM_RETRIEVE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_retrieve_rsp(TRUE, NULL);
			}
			break;

        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            MakeRetrieve();
            if ((GetTotalCallCount() == GetTotalActiveCallCount()) && (GetTotalHoldCallCount() == 0))
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_ACTIVE_STATE);
            }
			if(cm_p->ucm_operation == MMI_GSM_UCM_RETRIEVE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_retrieve_rsp(TRUE, NULL);
			}
            break;
        default:
            PRINT_INFORMATION("\n PSRetrieveSucEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBSwapReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_SWAPREQ.
 *  
 *  This Sets the flag CM_SWAP_REQUESTED to all the calls
 *  Invoke the protocol function irrespective of the state.
 *  This is always Invoked in Active state.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the Swap is requested on all calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBSwapReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = GetAllCallFlags();

    if (GetChldReqSent() != CM_ACTION_NONE ||     
    	((flag & CM_SWAP_REQUESTED) != 0) || 
    	((flag & CM_CONF_REQUESTED) != 0) ||
    	((flag & CM_ECT_REQUESTED) != 0))
    {
        return CM_CALL_FAILURE;
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBSwapReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n KBSwapReqEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_HOLD_STATE:
        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
            SetSwapFlag();
            MakePsSwapCallRequest((void*)SwapReqSucess);
            break;
        default:
            PRINT_INFORMATION("\n KBSwapReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSSwapSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_SWAPSUC.
 *  
 *  This resets the CM_SWAP_REQUESTED flag & change the state of the call from
 *  HOLD to ACTIVE & viceversa.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_SWAPREQ is on all calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSSwapSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetTotalCallCount() > 0)
    {
        SyncCallList();
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSSwapSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSSwapSucEvent CM_OUTGOING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_INCOMING_STATE:
            MakeSwap();
			if(cm_p->ucm_operation == MMI_GSM_UCM_SWAP &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_swap_rsp(TRUE, NULL);
			}
            break;

        case CM_HOLD_STATE:
            MakeSwap();
			if(cm_p->ucm_operation == MMI_GSM_UCM_SWAP &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_swap_rsp(TRUE, NULL);
			}
            break;

        case CM_ACTIVE_STATE:
            MakeSwap();
			if(cm_p->ucm_operation == MMI_GSM_UCM_SWAP &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_swap_rsp(TRUE, NULL);
			}
            break;

        default:
            PRINT_INFORMATION("\n PSSwapSucEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBConfReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_CONFREQ.
 *  
 *  This Sets the flag CM_CONF_REQUESTED to all the calls
 *  Invoke the protocol function irrespective of the state.
 *  This is always Invoked in Active state.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to NULL as the Conference is requested on all calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBConfReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = GetAllCallFlags();
    if (((flag & CM_SWAP_REQUESTED) != 0) || 
    	((flag & CM_CONF_REQUESTED) != 0) ||
    	((flag & CM_ECT_REQUESTED) != 0))
    {
        return CM_CALL_FAILURE;
    }

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBConfReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n KBConfReqEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
            SetConfFlag();
            MakePsConfCallRequest();
            break;
        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n KBConfReqEvent CM_HOLD_STATE not handled still \n");
            break;

        default:
            PRINT_INFORMATION("\n KBConfReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSConfSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_CONFSUC.
 *  
 *  This resets the CM_CONF_REQUESTED flag & change the state of the all calls
 *  to ACTIVE.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Is Null as the request CM_KB_CONFREQ is on all calls)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSConfSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSConfSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSConfSucEvent CM_OUTGOING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
			break;

        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
            MakeConf();
			if(cm_p->ucm_operation == MMI_GSM_UCM_CONFERENCE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_conference_rsp(TRUE, NULL);
			}
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n PSConfSucEvent CM_HOLD_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        default:
            PRINT_INFORMATION("\n PSConfSucEvent CM State m/c Corrupted \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBSplitReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_SPLITREQ.
 *  
 *  This Sets the flag CM_SPLIT_REQUESTED to the particular call selected
 *  from the group of active calls.
 *  Invoke the protocol function irrespective of the state.
 *  This is always Invoked in Active state.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to CM_CALL_HANDLE of the call to be splitted in the conference)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBSplitReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE callIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((void*)&callIndex, MsgStruct, sizeof(CM_CALL_HANDLE));

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n KBSplitReqEvent CM_IDLE_STATE not handled still \n");
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n KBSplitReqEvent CM_OUTGOING_STATE not handled still \n");
            break;

        case CM_INCOMING_STATE:
            if (GetTotalActiveCallCount() >= 2)
            {
                SetCallflag(callIndex, CM_SPLIT_REQUESTED, TRUE);
                MakePsSplitRequest(callIndex);
            }
            else
            {
                PRINT_INFORMATION("\n Not enuf calls to make a split request \n");
            }
            break;

        case CM_ACTIVE_STATE:
            if (GetTotalActiveCallCount() >= 2)
            {
                SetCallflag(callIndex, CM_SPLIT_REQUESTED, TRUE);
                MakePsSplitRequest(callIndex);
            }
            else
            {
                PRINT_INFORMATION("\n Not enuf calls to make a split request \n");
            }
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n KBSplitReqEvent CM_HOLD_STATE not handled still \n");
            break;

        default:
            PRINT_INFORMATION("\n KBSplitReqEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSSplitSucEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_SPLITSUC.
 *  
 *  This resets the CM_SPLIT_REQUESTED flag & change the state of that particular call to active
 *  other calls states are changed to HOLD.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to CM_CALL_HANDLE of the call that requested CM_KB_SPLITREQ)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSSplitSucEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            PRINT_INFORMATION("\n PSSplitSucEvent CM_IDLE_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_OUTGOING_STATE:
            PRINT_INFORMATION("\n PSSplitSucEvent CM_OUTGOING_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
            MakeSplitSucess();
			if(cm_p->ucm_operation == MMI_GSM_UCM_SPLIT)
			{
				mmi_gsm_split_rsp(TRUE, NULL);
			}
            break;

        case CM_HOLD_STATE:
            PRINT_INFORMATION("\n PSSplitSucEvent CM_HOLD_STATE not handled still \n");
			ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
            break;

        default:
            PRINT_INFORMATION("\n PSSplitSucEvent CM State m/c Corrupted \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessKBEctReqEvent
 * DESCRIPTION
 *  This is the function to process Keyboard(Request) Event CM_KB_HANGUPREQ.
 *  
 *  This Sets the flag CM_HANGUP_REQUESTED and invoke the protocol function irrespective of the state.
 *  The chances of this being invoked in idle state is very less.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 *  this(?)                 [IN]        Points to CM_CALL_HANDLE of the call to get dropped)
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessKBEctReqEvent(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = GetAllCallFlags();
    if (((flag & CM_SWAP_REQUESTED) != 0) || 
    	((flag & CM_CONF_REQUESTED) != 0) ||
    	((flag & CM_ECT_REQUESTED) != 0))
    {
        return CM_CALL_FAILURE;
    }

    switch (GetCurrentState())
    {
        case CM_OUTGOING_STATE:
            if (GetTotalActiveCallCount() == 1 || GetTotalHoldCallCount() == 1)
            {
                S16 index;

                index = GetOutgoingCallIndex();
                if (index == -1)
                {
                    break;
                }
                SetCallflag(index, CM_ECT_REQUESTED, FALSE);
                MakePsEctRequest();
            }
            else
            {
                PRINT_INFORMATION("\n Not Enuf Calls to make transfer \n");
            }
            break;

        case CM_INCOMING_STATE:
        case CM_ACTIVE_STATE:
        case CM_HOLD_STATE:
            if (GetTotalActiveCallCount() == 1 && GetTotalHoldCallCount() == 1)
            {
                S16 index;

                index = GetActiveCallIndex();
                if (index == -1)
                {
                    break;
                }
                SetCallflag(index, CM_ECT_REQUESTED, FALSE);
                MakePsEctRequest();
            }
            else
            {
                PRINT_INFORMATION("\n Not Enuf Calls to make transfer \n");
            }
            break;

        default:
            PRINT_INFORMATION("\n ECT Default does not exit \n");
            return CM_CALL_FAILURE;
    }
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSEctSuccessful
 * DESCRIPTION
 *  This is the function to process Protocol(Response) Event CM_PS_ECT_SUCCESS.
 * PARAMETERS
 *  MsgStruct               [?]         
 *  ACTION_RESULT(?)        [OUT]       
 * RETURNS
 *  This returns CM_CALL_SUCCESS if success or CM_CALL_FAILURE if failure.
 *****************************************************************************/
ACTION_RESULT ProcessPSEctSuccessful(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX - In ProcessPSEctSuccessful XXX\n");

    /* only active mpty can be split */
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].status_flag & CM_ECT_REQUESTED)
        {
            ResetCallflag(count, CM_ECT_REQUESTED, FALSE);
        }
    }
	if(cm_p->ucm_operation == MMI_GSM_UCM_EXPLICT_CALL_TRANSFER &&
        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
	{
		mmi_gsm_explicit_call_transfer_rsp(TRUE, NULL);
	}
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCallDeflected
 * DESCRIPTION
 *  This function is called back by the protocol stack when the
 *  Incoming Call is deflected
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCallDeflected(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckCallDeflectSuccess(info, &result))
    {
        PRINT_INFORMATION("XXX - In PsCBackCallDeflected XXX\n");
        OutgoingProcessCMEvent(CM_PS_INCOMING_CALL_DEFLECT, info);
        /* ProcessIncomingEvents (CM_PS_INCOMING_CALL_DEFLECT, info); */
    }
    else
    {
        PRINT_INFORMATION("XXX - FAILED FAILED FAILED In PsCBackCallDeflected XXX\n");
        ProcessIncomingFailureEvents(CM_PS_INCOMING_CALL_DEFLECT, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EndSingleAndGoBack
 * DESCRIPTION
 *  This function display the list of active and held calls
 *  to choose the call that needs to be ended.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EndSingleAndGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gcallListlen = GetAllDispNameorNum(gcallList, gcallListImage, NULL, &dummy);

    if (gcallListlen != GetTotalActiveCallCount() + GetTotalHoldCallCount())
    {
        PRINT_INFORMATION("\nFatal Error in CM Call Structure 4\n");
    }

    gListOperation = 1;
    EntryScr1009CallListScreen();
}


/*****************************************************************************
 * FUNCTION
 *  EndSingleActiveAndGoBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EndSingleActiveAndGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gcallListlen = GetAllActDispNameorNum(gcallList);

    gListOperation = 1;
    EntryScr1009CallListScreen();
}


/*****************************************************************************
 * FUNCTION
 *  SplitAndGoBack
 * DESCRIPTION
 *  This function display the list of active call
 *  to choose the call that needs to be splitted.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SplitAndGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gcallListlen = GetAllActDispNameorNum(gcallList);

    if (gcallListlen != GetTotalActiveCallCount())
    {
        PRINT_INFORMATION("\nFatal Error in CM Call Structure 4\n");
    }

    gListOperation = 2;
    EntryScr1009CallListScreen();
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrHiliteCall
 * DESCRIPTION
 *  This is the hilite handler for the gcallList listview displayed.
 *  
 *  gHilitedCall will be updated by this function
 * PARAMETERS
 *  hiliteIndex     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrHiliteCall(S32 hiliteIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CM_CALL_HANDLE temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gHilitedCall = (U16) hiliteIndex;

    temp = GetCallHandle(gcallList[gHilitedCall]);
    if (temp > 0)
    {
		Cat19UpdateDuration(GetCallStartTime (temp));
    }
}

/*****************************************************************************
 * FUNCTION
 *  GetCurrStartCallTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MYTIME *GetCurrStartCallTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CM_CALL_HANDLE temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = GetCallHandle(gcallList[gHilitedCall]);
    if (temp > 0)
    {
		return GetCallStartTime (temp);
}
    return NULL;

}

/*****************************************************************************
 * FUNCTION
 *  HangupHilited
 * DESCRIPTION
 *  Hangup the selected or hilted call
 *  
 *  this function converts the index to callhandle
 *  and invoke the hangup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HangupHilited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = GetCallHandle(gcallList[gHilitedCall]);
    HangupCall(temp);
}


/*****************************************************************************
 * FUNCTION
 *  SplitHilited
 * DESCRIPTION
 *  Split the selected or hilted call
 *  
 *  this function converts the index to callhandle
 *  and invoke the Splitcall
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SplitHilited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = GetCallHandle(gcallList[gHilitedCall]);
    SplitCall(temp);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1009CallListScreen
 * DESCRIPTION
 *  display the list of strings stored by gcallList
 *  
 *  The gcallList can contain the list of active or held calls
 *  depending on the scenario the LSK operation is also depending on
 *  gListOperation.If gListOperation==1 then operation is HANGUP request.
 *  If gListOperation==2 then the operation is SPLIT.
 * PARAMETERS
 *  void
 *  gListOperation(?)       [IN]        GcallList,gcallListlen global variables filled by other function
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1009CallListScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR1009_CM_CALLLISTSCREEN, NULL, EntryScr1009CallListScreen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR1009_CM_CALLLISTSCREEN);

    SetParentHandler(0);
    RegisterHighlightHandler(SetCurrHiliteCall);

    ShowCategory6Screen(
        STR_SCR1009_CAPTION,
        IMG_SCR1009_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        gcallListlen,
        gcallList,
        NULL,
        0,
        guiBuffer);

    if (gListOperation == 1)
    {
        SetLeftSoftkeyFunction(HangupHilited, KEY_EVENT_UP);
    }
    else if (gListOperation == 2)
    {
        SetLeftSoftkeyFunction(SplitHilited, KEY_EVENT_UP);
    }

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1001OutgoingCall
 * DESCRIPTION
 *  Shows the outgoing call screen
 *  
 *  This is invoked whenever the User requests for a outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1001OutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr1001OutgoingCall
 * DESCRIPTION
 *  Typical exit screen to add the history variable of the screen.
 *  
 *  Updates the history variables of the screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr1001OutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() == CM_OUTGOING_STATE)
    {
        history Scr1001;
        S16 nHistory = 0;

        Scr1001.scrnID = SCR1001_CM_OUTGOINGCALLSCREEN;
        Scr1001.entryFuncPtr = EntryScr1001OutgoingCall;
        mmi_ucs2cpy((S8*) Scr1001.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(Scr1001.guiBuffer);
        AddHistory(Scr1001);
    }
#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__))    /* PMT MANISH   20050623 */ /*MTK Mick 20070212*/
	ResetCenterSoftkey();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLcdScr1001OutgoingCall
 * DESCRIPTION
 *  Entry screen for Sub Lcd OutGoing Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLcdScr1001OutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    ShowCategory311Screen(gdispnameForSubLCD, IMG_CM_SUBLCD_CALLING, NULL);
    SetSubLCDExitHandler(ExitSubLcdScr1001OutgoingCall);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLcdScr1001OutgoingCall
 * DESCRIPTION
 *  Exit Handler for Sub Lcd OutGoing Call Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLcdScr1001OutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() == CM_OUTGOING_STATE && !IsSubLCDScreenPresent(SUB_LCD_SCR1001_CM_OUTGOINGCALLSCREEN))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = EntrySubLcdScr1001OutgoingCall;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SUB_LCD_SCR1001_CM_OUTGOINGCALLSCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrOutgoingMultipleOptions
 * DESCRIPTION
 *  This function is the entry screen for the outgoing call
 *  option menu when there are more than one calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrOutgoingMultipleOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    static U8 *PopUpList[10];
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 nStrItemList[10];   /* Stores the strings id of submenus returned */
    U16 menuId;
    S16 nActiveCall;
    U16 nHeldCall;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nActiveCall = GetTotalActiveCallCount();
    nHeldCall = GetTotalHoldCallCount();

    if (GetIncomingCallHandle() == -1)
    {
        /* no waiting call */
        if (nActiveCall == 1 && nHeldCall == 0)
        {
            menuId = MITEM2008_CM_WAIT_ACT_LSKOPTIONS;
        }
        else if (nActiveCall == 0 && nHeldCall == 1)
        {
            menuId = MITEM2008_CM_WAIT_S_HOLD_LSKOPTIONS;
        }
        else if (nActiveCall > 1 && nHeldCall == 0)
        {
            menuId = MITEM2008_CM_WAIT_MACT_LSKOPTIONS;
        }
        else if (nActiveCall == 0 && nHeldCall > 1)
        {
            menuId = MITEM2008_CM_WAIT_M_HOLD_LSKOPTIONS;
        }
        else
        {
            return;
        }
    }
    else
    {
        /* waiting call present */
        if (nActiveCall == 1 && nHeldCall == 0)
        {
            menuId = MITEM2008_CM_INC_ACT_LSKOPTIONS;
        }
        else if (nActiveCall == 0 && nHeldCall == 1)
        {
            menuId = MITEM2008_CM_INC_S_HOLD_LSKOPTIONS;
        }
        else if (nActiveCall > 1 && nHeldCall == 0)
        {
            menuId = MITEM2008_CM_INC_MACT_LSKOPTIONS;
        }
        else if (nActiveCall == 0 && nHeldCall > 1)
        {
            menuId = MITEM2008_CM_INC_M_HOLD_LSKOPTIONS;
        }
        else
        {
        		/* 1 MO + 1 waiting */
        		menuId = MITEM2008_CM_INC_LSKOPTIONS;
        }
    }

    EntryNewScreen(ITEM_SCR_OUT_WAIT_HOLD_OPN, NULL, EntryScrOutgoingMultipleOptions, NULL);

    SetCMScrnFlag(TRUE);

    guiBuffer = GetCurrGuiBuffer(ITEM_SCR_OUT_WAIT_HOLD_OPN);
    SetParentHandler(menuId);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);

    ConstructHintsList(menuId, PopUpList);

    ShowCategory55Screen(
        STR_SCR1002_CAPTION,
        IMG_SCR1002_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U8 **) PopUpList,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(HangupAll, KEY_END, KEY_EVENT_DOWN);

    SetSideVolumeKeysForCM();
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1002ActiveCall
 * DESCRIPTION
 *  This displays the list of active/Held calls or the single active/held call.
 *  
 *  This is the sort of base screen after processing the response events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1002ActiveCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCbackAfterSS(NULL);
    if (GetNotifySSFlag())
    {
        PRINT_INFORMATION(" XXX EntryScr1002ActiveCall: Notify Flag Set XXX\n");
        /* between call connected (MO or MT) and get time rsp to show active call screen, 
           if the call is dropped, we stilll need to log the call as connected. */
        if (GetCallHandleForStartTimeUpdate())
        {
            MYTIME t;

            DTGetRTCTime(&t);
            UpdateCallStartTimeAndLogCall(GetCallHandleForStartTimeUpdate(), &t);
            SetCallHandleForStartTimeUpdate(0);
        }

        SetCbackAfterSS((FuncPtr) EntryScr1002ActiveCall);
        return;
    }

#ifdef __CTM_SUPPORT__
    if (ctm_p->state == MMI_CTM_STATE_CONNECTED)
    {
        entry_ctm_talking();
        return;
    }
#endif /* __CTM_SUPPORT__ */ 

    if (GetExitScrnID() != SCR_CM_ACTIVECALLSCREEN)
    {
        EntryNewScreen(SCR_CM_ACTIVECALLSCREEN, NULL, NULL, NULL);
        ShowCategoryDummyScreen();
    }

    ReplaceNewScreenHandler(SCR_CM_ACTIVECALLSCREEN, NULL, EntryScr1002ActiveCall);

    SetTransitionToActiveFlag(TRUE);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens())
    {
        MYTIME curtime;

        DTGetRTCTime(&curtime);
        DummyScr1002ActiveCall(&curtime);
    }
    else
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 
        CMGetExactTime(DummyScr1002ActiveCall);
}


/*****************************************************************************
 * FUNCTION
 *  DummyScr1002ActiveCall
 * DESCRIPTION
 *  This is a dummy function for EntryScr1002ActiveCall()
 *  this is made because of asynchronous CMGetExactTime
 *  
 *  This is the sort of base screen after processing the
 *  response events.
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DummyScr1002ActiveCall(MYTIME *t)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLcdScr1002ActiveCall
 * DESCRIPTION
 *  Entry screen for Sub Lcd Active Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLcdScr1002ActiveCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    ShowCategory304Screen(IMG_CM_STATE_CONNECTED, NULL);
    SetSubLCDExitHandler(ExitSubLcdScr1002ActiveCall);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLcdScr1002ActiveCall
 * DESCRIPTION
 *  Exit Handler for Sub Lcd Active Call Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLcdScr1002ActiveCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsSubLCDScreenPresent(SUB_LCD_SCR_CM_ACTIVECALLSCREEN))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = EntrySubLcdScr1002ActiveCall;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SUB_LCD_SCR_CM_ACTIVECALLSCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1003CMActiveCallOptions
 * DESCRIPTION
 *  This handles the LSK functionality for the active screen.
 *  Displays options depending on the scenario.
 *  
 *  This handles all the scenario depending on the menuitem defined.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1003CMActiveCallOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 parentId;
    U8 *guiBuffer;
    U8 *inputBuffer;
    static U8 *PopUpList[40];
    U16 nNumofItem;
    U16 nStrItemList[20];
    S16 nActiveCall = 0;
    U16 nHoldCall = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Added For CPHS */
    /* U16 isConfPresent=0;
       U16 isHoldPresent=0;
       S32 maskingByte=-1; */

    nActiveCall = GetTotalActiveCallCount();
    nHoldCall = GetTotalHoldCallCount();

    PRINT_INFORMATION("\n active option: active:%d, held:%d\n", nActiveCall, nHoldCall);

    if (nActiveCall + nHoldCall == 0)
    {
        return;
    }

    if ((nActiveCall == 1) && (nHoldCall == 0))
    {
        U8 type;

        type = GetActiveCallType();
        if (type == CSMCC_DATA_CALL || type == CSMCC_FAX_CALL)
        {
            parentId = MITEM2001_CM_SINGLE_DATA_LSKOPTIONS;
        }
        else
        {
            parentId = MITEM2001_CM_SINGLE_ACTIVE_LSKOPTIONS;
            // isHoldPresent=1; /* Added For CPHS */
        }
    }
    else if ((nActiveCall == 0) && (nHoldCall == 1))
    {
        parentId = MITEM2002_CM_SINGLE_HOLD_LSKOPTIONS;
    }
    else if ((nActiveCall == 1) && (nHoldCall == 1))
    {
        parentId = MITEM2003_CM_S_ACTIVE_S_HOLD_LSKOPTIONS;
        // isConfPresent=1; /* Added For CPHS */
    }
    else if ((nActiveCall > 1) && (nHoldCall == 0))
    {
        parentId = MITEM2004_CM_M_ACTIVE_LSKOPTIONS;
    }
    else if ((nActiveCall == 0) && (nHoldCall > 1))
    {
        parentId = MITEM2005_CM_M_HOLD_LSKOPTIONS;
    }
    else if ((nActiveCall > 1) && (nHoldCall == 1))
    {
        parentId = MITEM2006_CM_M_ACTIVE_S_HOLD_LSKOPTIONS;
        // isConfPresent=1; /* Added For CPHS */
    }
    else if ((nActiveCall == 1) && (nHoldCall > 1))
    {
        parentId = MITEM2007_CM_S_ACTIVE_M_HOLD_LSKOPTIONS;
        // isConfPresent=1; /* Added For CPHS */
    }
    else
    {
        return;
    }

    PRINT_INFORMATION("\n parent:%d\n", parentId);

    EntryNewScreen(SCR1003_CM_ACTIVECALLOPTIONS, ExitScr1003CMActiveCallOptions, NULL, NULL);

    SetCMScrnFlag(TRUE);
    guiBuffer = GetCurrGuiBuffer(SCR1003_CM_ACTIVECALLOPTIONS);
    if (IsScreenPresent(SCR1003_CM_ACTIVECALLOPTIONS))
    {
        inputBuffer = GetCurrInputBuffer(SCR1003_CM_ACTIVECALLOPTIONS);
        if (inputBuffer[0] != (nActiveCall + nHoldCall))
        {
            /* call count changed, always highlight the first item */
            guiBuffer = NULL;
        }
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(parentId);

#ifdef __CTM_SUPPORT__
    if (!((GetTotalActiveCallCount() > 0) &&
          (ctm_p->state == MMI_CTM_STATE_OPENED) && (ctm_p->mode_activated == CTM_DIRECT_MODE)))
    {
        /* only opened and unconnected case need to show connect ctm option */
        mmi_frm_hide_menu_item(MITEM2027_CM_CTM);
    }
    if (ctm_p->status == TRUE)
    {
        mmi_frm_hide_menu_item(MITEM2026_CM_SOUND_RECORDER);
    }
#endif /* __CTM_SUPPORT__ */ 

#if defined(__MMI_BT_SUPPORT__)

   /*************************************************/
   /** Notice!!! */
   /** 1. The voice transfer menu item should be the last one in the option menu */
   /** 2. The voice transfer menu item is only added in XXX_CM_XXX_ACTIVE_XXX parentId. */
   /**   So this screen has to removed this menu item while BT headset connected */
   /*************************************************/

    if (mmi_bt_is_hs_connected() != MMI_TRUE)
    {
        switch (parentId)
        {
            case MITEM2001_CM_SINGLE_DATA_LSKOPTIONS:
            case MITEM2002_CM_SINGLE_HOLD_LSKOPTIONS:
            case MITEM2005_CM_M_HOLD_LSKOPTIONS:
                break;
            default:
                mmi_frm_hide_menu_item(MITEM_CM_BT_SETPATH);
                break;

        }
    }
    /* Add by Elvis*/
    #ifdef __BT_INBAND_RING__
    mmi_frm_hide_menu_item(MITEM_CM_BT_SETPATH);
    #endif
    /* End of Elvis */

#endif /* defined(__MMI_BT_SUPPORT__) */ 

    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(parentId);
    GetSequenceStringIds_Ext(parentId, nStrItemList);

    ConstructHintsList(parentId, PopUpList);

    PRINT_INFORMATION("\n active option: %d\n", nNumofItem);

    ShowCategory55Screen(
        STR_SCR1002_CAPTION,
        IMG_SCR1002_CAPTION,
        STR_GLOBAL_OK,
        IMG_SCR1003_LSK,
        STR_GLOBAL_BACK,
        IMG_SCR1003_RSK,
        nNumofItem,
        nStrItemList,
        (U8 **) PopUpList,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(HangupAll, KEY_END, KEY_EVENT_DOWN);

    SetSideVolumeKeysForCM();
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr1003CMActiveCallOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr1003CMActiveCallOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr1001;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CTM_SUPPORT__
    mmi_frm_unhide_menu_item(MITEM2027_CM_CTM);
    mmi_frm_unhide_menu_item(MITEM2026_CM_SOUND_RECORDER);
#endif /* __CTM_SUPPORT__ */ 
#if defined(__MMI_BT_SUPPORT__)
    mmi_frm_unhide_menu_item(MITEM_CM_BT_SETPATH);
#endif 

    Scr1001.scrnID = SCR1003_CM_ACTIVECALLOPTIONS;
    Scr1001.entryFuncPtr = EntryScr1003CMActiveCallOptions;
    memset (Scr1001.inputBuffer, 0, sizeof (Scr1001.inputBuffer));
    Scr1001.inputBuffer[0] = (U8) GetTotalCallCount();
    GetCategoryHistory(Scr1001.guiBuffer);
    AddHistory(Scr1001);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1004NotifyEndCallDuration
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Hangup of a single call is success with a timeout of CM_NOTIFY_TIMEOUT.
 *  
 *  This has to display the time,we need to have the time display catefory function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1004NotifyEndCallDuration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr1004NotifyEndCallDuration
 * DESCRIPTION
 *  This just stops timer which was started in the entry function.
 *  
 *  History might be added if required not
 *  added as the notification does not need history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr1004NotifyEndCallDuration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_NOTIFYDURATION_TIMER);

    if (GetErrorToneFlag() == TONE_BUSY_CALL_GSM)
    {
        AudioStopReq(TONE_BUSY_CALL_GSM);
    }
    else if (GetErrorToneFlag() > 0)
    {
        stopRequestedTone(GetErrorToneFlag());
    }
        SetErrorToneFlag(0);

    if (GetPOPUpFlag())
    {
        SetPOPUpFlag(FALSE);
        AdjustHistoryForCM();
    }

    if (CMAllowInterrupt())
    {
        MMIProcessActionMsg();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrNotifyCallAborted
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Hangup of a single call is success with a timeout of CM_NOTIFY_TIMEOUT.
 *  
 *  This has to display the time,we need to have the time display catefory function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrNotifyCallAborted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 MessageString[TEMP_NO * 3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CM_NOTIFYCALLABORTED, ExitScrNotifyCMPopUp, NULL, NULL);

    PRINT_INFORMATION(" XXX In EntryScrNotifyCallAborted\n");

    if (GetDropRequestFlag() == TRUE)
    {
        mmi_ucs2cpy((PS8) MessageString, (PS8) GetString(STR_CALL_ABORTED));
        SetDropRequestFlag(FALSE);
    }
    else
    {
        mmi_ucs2cpy((PS8) MessageString, (PS8) GetString(STR_CALL_ENDED));
    }

    SetCallEndedBeforeConnFlag(FALSE);

    ShowCategory63Screen(MessageString, IMG_CM_STATE_ENDED, NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    SetPOPUpFlag(TRUE);
    StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, GoBackfromNotifyScr);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1005NotifyHoldSucess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Hold request is success with a timeout of CM_NOTIFY_TIMEOUT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1005NotifyHoldSucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n EntryScr1005NotifyHoldSucess \n");

    EntryScrNotifyCHLDSucess(STR_NFY_CALL_HLD, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1006NotifyRetrieveSucess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Retrieve request is success with a timeout of CM_NOTIFY_TIMEOUT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1006NotifyRetrieveSucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryScrNotifyCHLDSucess(STR_NFY_CALL_RTVD, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1007NotifySwapSucess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Swap request is success with a timeout of CM_NOTIFY_TIMEOUT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1007NotifySwapSucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetTotalActiveCallCount() > 0 && GetTotalHoldCallCount() > 0)
    {
        EntryScrNotifyCHLDSucess(STR_NFY_CALL_SWAP, FALSE);
    }
    else if (GetTotalActiveCallCount() > 0)
    {
        EntryScrNotifyCHLDSucess(STR_NFY_CALL_RTVD, FALSE);
    }
    else if (GetTotalHoldCallCount() > 0)
    {
        EntryScrNotifyCHLDSucess(STR_NFY_CALL_HLD, TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1008NotifyConfSucess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Conference request is success with a timeout of CM_NOTIFY_TIMEOUT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1008NotifyConfSucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryScrNotifyCHLDSucess(STR_NFY_CALL_CONF, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr1010NotifySplitSucess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Split request is success with a timeout of CM_NOTIFY_TIMEOUT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr1010NotifySplitSucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryScrNotifyCHLDSucess(STR_NFY_CALL_SPLIT, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrNotifyCHLDSucess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  Split request is success with a timeout of CM_NOTIFY_TIMEOUT.
 * PARAMETERS
 *  notify_string       [IN]        
 *  play_tone           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrNotifyCHLDSucess(U16 notify_string, pBOOL play_tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR1010_CM_DISPSPLITCALLSUCESS, ExitScrNotifyCMPopUpTone, NULL, NULL);

#ifndef __MMI_CM_SHOW_CHLD_DONE__
    ShowCategory62Screen(notify_string, IMG_GLOBAL_ACTIVATED, NULL);
#else 
    ShowCategory62Screen(STR_ACTION_DONE, IMAGE_CCBS_ACTIVATED, NULL);
#endif 

    SetLeftSoftkeyFunction(GoBackfromNotifyScr, KEY_EVENT_UP);

    if (play_tone == TRUE && GetTotalCallCount() == 0)
    {
        playRequestedTone(SUCCESS_TONE_IN_CALL);
        SetErrorToneFlag(SUCCESS_TONE_IN_CALL);
    }

    SetKeysForPOPUp();
    SetPOPUpFlag(TRUE);
    StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, GoBackfromNotifyScr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrNotifyCMPopUpTone
 * DESCRIPTION
 *  This just stops timer which was started in the entry function.
 *  
 *  History might be added if required not
 *  added as the notification does not need history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrNotifyCMPopUpTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetErrorToneFlag() > 0)
    {
        stopRequestedTone(GetErrorToneFlag());
        SetErrorToneFlag(0);
    }
    StopTimer(CM_NOTIFYDURATION_TIMER);

    if (GetPOPUpFlag())
    {
        SetPOPUpFlag(FALSE);
        AdjustHistoryForCM();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrLoudSpNotifyScreen
 * DESCRIPTION
 *  display the notification screen in case of lous speaker
 * PARAMETERS
 *  void
 *  gListOperation(?)       [IN]        GcallList,gcallListlen global variables filled by other function
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrLoudSpNotifyScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8* guiBuffer; */

    PRINT_INFORMATION("XXX EntryScrLoudSpNotifyScreen\n");

    EntryNewScreen(SCR_CM_NOTIFY_LOUDSPEAKER, ExitScrNotifyCMPopUp, NULL, NULL);

    /* guiBuffer = GetCurrGuiBuffer(SCR_CM_NOTIFY_LOUDSPEAKER); */

    if (LoudSpeaker() == TRUE)
    {
        ShowCategory62Screen(STR_NFY_LOUDSPEAKER_ON, 0, NULL);
    }
    else
    {
        ShowCategory62Screen(STR_NFY_LOUDSPEAKER_OFF, 0, NULL);
    }

    SetLeftSoftkeyFunction(GoBackfromNotifyScr, KEY_EVENT_UP);
    SetPOPUpFlag(TRUE);
    SetKeysForPOPUp();
    StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, GoBackfromNotifyScr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrNotifyCMPopUp
 * DESCRIPTION
 *  This function is the exit screen for for displaying SS info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrNotifyCMPopUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_NOTIFYDURATION_TIMER);
    if (GetPOPUpFlag())
    {
        SetPOPUpFlag(FALSE);
        AdjustHistoryForCM();
    }
}

/************************ CISS *************************************/


/*****************************************************************************
 * FUNCTION
 *  EntryScrUSSDReq
 * DESCRIPTION
 *  This function shows USSD screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrUSSDReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In EntryScrUSSDReq\n");

    SetAbortCallRequestedFlag(FALSE);

    EntryNewScreen(SCR_CM_REQUESTINGUSSD, NULL, EntryScrUSSDReq, NULL);

    /* micha1115 */
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NUMBER);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NO_ANS_TIME);
    DeleteScreenIfPresent(SCR_ID_CALLSET_WAITING_MAIN);

    ShowCategory8Screen(
        STR_USSD_REQ_CAPTION,
        IMG_CM_USSD_REQUEST,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_SCR_USSD_REQ_LSK,
        STR_USSD_REQ_DISP_SCR,
        IMG_CM_SS_OUTGOING,
        NULL);

    /* micha0915 */
    SetDelScrnIDCallbackHandler(SCR_CM_REQUESTINGUSSD, (HistoryDelCBPtr) SSReqHistoryDelHdlr);

    SetRightSoftkeyFunction(AbortUSSDRequest, KEY_EVENT_UP);
    SetKeyHandler(AbortUSSDRequestEND, KEY_END, KEY_EVENT_DOWN);
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_set_slave_ss_falg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_set_slave_ss_falg(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In mmi_gsm_set_slave_ss_falg:%d\n", flag);
    cm_p->slave_ss_session = flag;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_set_slave_reply_ussr_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_set_slave_reply_ussr_flag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In mmi_gsm_set_slave_reply_ussr_flag:%d\n", flag);
    cm_p->slave_reply_ussr = flag;
}

#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  SSReqHistoryDelHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 SSReqHistoryDelHdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** SSReqHistoryDelHdlr\n");

    if (FALSE == GetAbortCallRequestedFlag())
    {
        SetAbortCallRequestedFlag(TRUE);
        MakePsDropUSSDReq(NULL);
    }
    else
    {
        PRINT_INFORMATION("*** In  SSReqHistoryDelHdlr.. Not sending ATH\n");
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  RemoveSSReqScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8(?)
 *****************************************************************************/
void RemoveSSReqScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_CM_REQUESTINGUSSD, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CM_REQUESTINGUSSD);
}


/*****************************************************************************
 * FUNCTION
 *  AbortUSSDRequest
 * DESCRIPTION
 *  Invokes the helper function to hangup or disconnect the call
 *  which is yet to connect.
 *  
 *  This is invoked whenever the User press LSK in the UssdReq screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortUSSDRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In AbortUSSDRequest Request\n");

    if (FALSE == GetAbortCallRequestedFlag())
    {
        SetAbortCallRequestedFlag(TRUE);
        MakePsDropUSSDReq(CBackDropUSSDReq);
    }
    else
    {
        PRINT_INFORMATION("*** In AbortUSSDRequest Request .. Not sending ATH\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  AbortUSSDRequestEND
 * DESCRIPTION
 *  This is called when end key is pressed
 *  on USSD screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortUSSDRequestEND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In AbortUSSDRequest Request\n");

    if (FALSE == GetAbortCallRequestedFlag())
    {
        SetAbortCallRequestedFlag(TRUE);
        MakePsDropUSSDReq(CBackDropUSSDReqEND);
    }
    else
    {
        PRINT_INFORMATION("*** In AbortUSSDRequest Request .. Not sending ATH\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  ProcessUSSDrecieved
 * DESCRIPTION
 *  This function is called by the state machine function in
 *  response to the USSD data recieved by the MS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessUSSDrecieved(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USSD_GOBACK_IDLE__
    if (((MMI_SS_USSD_RSP*) info)->op_code == SS_OP_UNSTRUCTUREDSS_REQUEST)
    {
        RemoveSSReqScr();
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
        DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);
        GoBackHistory();
        StopTimer(USSD_UCM_DISPLAY_TIMER);
    #ifdef __MMI_USSR_TIMER__  
        StopTimer(USSR_SESSION_TIMER);
    #endif /* __MMI_USSR_TIMER__ */        
        return;
    }
#endif    
    
    if (((MMI_SS_USSD_RSP*) info)->result.flag == L4C_OK)
    {
        DeriveUSSDbuf(info);
        if (IsScreenPresent(SCR_CM_REQUESTINGUSSD))
        {
            HistoryReplace(SCR_CM_REQUESTINGUSSD, ITEM_SCR_USSN_MSG, EntryScrDisplayUSSDRes);
            mmi_gsm_display_ussd_info_on_active_call();
            return;
        }
        else
        {
            mmi_gsm_display_ussd_info();
        }
    }
    else
    {
        if ((mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) == 0 &&
             mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) == 0)|| 
            (GetActiveScreenId() == SCR_CM_REQUESTINGUSSD))
        {
        #ifdef __MMI_SS_SHOW_CAUSE__
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            RemoveSSReqScr();
            ShowCauseString(((MMI_SS_USSD_RSP*) info)->result.cause, temp_string);
            ShowCategory74Screen(
                STR_TITLE_SCR_USSD_MSG,
                0,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                0,
                0,
                (PU8) temp_string,
                mmi_ucs2strlen(temp_string),
                NULL);
            SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        #else /* __MMI_SS_SHOW_CAUSE__ */ 
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
            RemoveSSReqScr();
        #endif /* __MMI_SS_SHOW_CAUSE__ */ 
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
            RemoveSSReqScr();
        }

        StopTimer(USSD_UCM_DISPLAY_TIMER);
    #ifdef __MMI_USSR_TIMER__  
        StopTimer(USSR_SESSION_TIMER);
    #endif /* __MMI_USSR_TIMER__ */
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
    DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);
    DeleteScreenIfPresent(SCR_SYMBOL_PICKER_SCREEN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_display_ussd_info
 * DESCRIPTION
 *  show USSD info if it is not MT/MO call screen.
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_display_ussd_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_gsm_display_ussd_info");

    if(mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
       mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        StartTimer(USSD_UCM_DISPLAY_TIMER, 500, mmi_gsm_display_ussd_info_on_active_call);
        return;
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);

    EntryScrDisplayUSSDRes();
#ifdef __MMI_RECEIVE_USSD_TONE__
    MuteOnMicrophone();
    playRequestedTone(WARNING_TONE);
    if (IsPhoneInMute() == MMI_FALSE)
    {
        MuteOffMicrophone();
    }
#endif /* __MMI_RECEIVE_USSD_TONE__ */

    StopTimer(USSD_UCM_DISPLAY_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_display_ussd_info_on_active_call
 * DESCRIPTION
 *  show USSD info on active call screen.
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_display_ussd_info_on_active_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_gsm_display_ussd_info_on_active_call");
    
    if ((GetExitScrnID() != SCR_ID_UCM_IN_CALL &&
        GetExitScrnID() != SCR_ID_UCM_IN_CALL_OPTION &&
        GetExitScrnID() != SCR_ID_UCM_DTMF_EDITOR) ||
        mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
        mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        StartTimer(USSD_UCM_DISPLAY_TIMER, 100, mmi_gsm_display_ussd_info_on_active_call);
        return;
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);

    EntryScrDisplayUSSDRes();
#ifdef __MMI_RECEIVE_USSD_TONE__
    MuteOnMicrophone();
    playRequestedTone(WARNING_TONE);
    if (IsPhoneInMute() == MMI_FALSE)
    {
        MuteOffMicrophone();
    }
#endif /* __MMI_RECEIVE_USSD_TONE__ */
}

/*****************************************************************************
 * FUNCTION
 *  GetOutCallType
 * DESCRIPTION
 *  Get outgoing call type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetOutCallType(void)
{
    return gCurrOutcall.call_type;
}


#endif /* __MMI_UCM__ */

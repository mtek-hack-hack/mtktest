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
 *   CallManagementIncoming.c
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
 * Disable center key when exiting incoming call screen.
 *
 * removed!
 * removed!
 * Turn on backlight after showing category screen
 *
 * removed!
 * removed!
 * Add compile option for touch screen
 *
 * removed!
 * removed!
 * Disable center key
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add compile option
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add notification information
 *
 * removed!
 * removed!
 * clear Delete Screen Handler after user selects OK
 *
 * removed!
 * removed!
 * Don't resume audio when the incoming call is in black list.
 *
 * removed!
 * removed!
 * allow English character (uppercase and lowercase)
 *
 * removed!
 * removed!
 * enable center key and set handler for it.
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

   FILENAME : CallManagementIncoming.c

   PURPOSE     : Call Management application

   REMARKS     : To keep in mind that History must always be saved
              Skipping nodes it to be decided

   AUTHOR      : Ashish

   DATE     : Nov 8,02

**************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__

#include "ProtocolEvents.h"
#include "WrapperGprot.h"
#include "wgui.h"
#include "CSP.h"


#include "ProfileGprots.h"
#include "BootUp.h"
#include "PowerOnChargerProt.h"
#include "MessagesExDcl.h"
#include "SmsPsHandler.h"
#include "MessagesResourceData.h"
#include "SMSApi.h"

#include "AlarmFrameworkProt.h"
#include "SATDefs.h"
#include "SATGProts.h"
#include "SimDetectionGexdcl.h"
#include "gpioInc.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "CallSetUp.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "AudioInc.h"

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
#include "RedialHelperGProtEX.h"
#include "CommonStubsProtEX.h"
#include "PsCallHelperDefEX.h"
#include "mmiapi_struct.h"
#include "PsCallHelperGprotEX.h"
#include "CallManagementGprotEX.h"
#include "OutgoingCallHelperProtEX.h"
#include "OutgoingCallManagementProtEX.h"
#include "MessagesResourceData.h"

#include "IncomingCallManagementProtEX.h"
#include "PhonebookDef.h"       /* For enum IMG_PHB_DEFAULT */
#include "CommonScreens.h"      /* for popup window timer. */

#include "UCMGProt.h"
#include "UCMCallProt.h"

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "ddl.h"
#include "jcutils.h"
#include "jcerror.h"
#include "jdd_tapi.h"
#endif

#include "SettingGprots.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#include "UCMResDef.h"
#endif /*__MMI_UCM__*/

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/* static CM_CALL_HANDLE gCallToEnd;// This is the call Selected for ending */
static CM_CALL_HANDLE gMyCallHandle;
static S8 CallDeflectBuffer[MAX_NUMBER];
static U8 gDTMFConfirmBuf[MAX_DTMFBUF_DIGITS];
static U8 cashSign[8];
static U8 AocBuffer[10];
static pBOOL gAttempToReject = FALSE;
static pBOOL gAttempToAnswer = FALSE;
static pBOOL gAcceptIncoming = FALSE;   /* tells if there is a incoming call waiting to be accepted */

/* static pBOOL gHold2End=FALSE;// tells if there is a pending hold call 2 end */

/* static U16 gIdleScreenDigitsAnyKeyAnswer[MAX_CM_SCREEN_DIGITS_ANYKEY] =
   {
   KEY_0,KEY_1,KEY_2,KEY_3,
   KEY_4,KEY_5,KEY_6,KEY_7,
   KEY_8,KEY_9,KEY_STAR,KEY_POUND,
   KEY_UP_ARROW,
   KEY_DOWN_ARROW,
   KEY_LEFT_ARROW,
   KEY_RIGHT_ARROW,
   KEY_CLEAR, KEY_ENTER, KEY_QUICK_ACS
   }; */

S16 CallDeflectDigitKeyCode = -1;
U16 gSSEvent = 0;
MMI_BOOL gSSEventNotifyPresent = MMI_FALSE;
U16 gSSEventNotify = 0;

extern U8 isEarphonePlugged;
extern U32 gSumACMValue;
extern S8 gUSSDbuf[];
extern S8 UnicodeDTMFPadCallBuffer[];
extern const U16 CMIdleScreenDigits[];
extern PU8 gdispnameForSubLCD;
extern U8 isCSPPresent;
extern U16 gtmpOutgoingIndex;

#ifdef WAP_SUPPORT
extern int wap_bearer_csd_is_disc(void);
#endif 

#ifdef __MMI_CLAMSHELL__
extern BOOL IsClamClose(void);
#endif 

extern void show_call_cost_UI(PU8 symbol, PU8 value);


/*****************************************************************************
 * FUNCTION
 *  ReinitalizeIncomingCall
 * DESCRIPTION
 *  To Re-Initialize the Incoming Call Management Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReinitalizeIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(PsCBackIncomingCallAccepted, PRT_INCOMINGCALL_ACCEPT_SUCCESS);
    SetProtocolEventHandler(PsCBackCallIncoming, PRT_INCOMINGCALL_EVENT);
    SetProtocolEventHandler(PsCBackCallWait, PRT_INCOMING_CALL_WAIT);
    SetProtocolEventHandler(PsCBackSpeechIndication, PRT_SPEECH_IND_EVENT);
    SetProtocolEventHandler(PsCBackAocIndication, PRT_AOC_EVENT_IND);
    SetProtocolEventHandler(PsCBackNotifySSInd, PRT_NOTIFY_SS_EVENT);
#ifdef __MMI_DUAL_SIM_MASTER__
    SetSlaveProtocolEventHandler(PsCBackNotifySSInd, PRT_NOTIFY_SS_EVENT);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    
    SetProtocolEventHandler(PsCBackNotifyCNAPSSInd, PRT_NOTIFY_SS_CNAP_EVENT);

    SetProtocolEventHandler(PsCBackCcbsActivate, PRT_OUTGOING_DISCONNECT_IND);
    SetProtocolEventHandler(PsCBackCCBSInvoked, PRT_CCBS_NOTIFY_IND);
    SetProtocolEventHandler(PsCBackConfirmDTMFString, PRT_DTMF_CONFIRM_IND);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);

    SetProtocolEventHandler(mmi_gsm_csd_call_approve, PRT_CSD_CALL_APPROVE_REQ);

    SetProtocolEventHandler(PsCBackUSSNInd, PRT_USSN_IND);
    SetProtocolEventHandler(PsCBackUSSRInd, PRT_USSR_IND);

    SetProtocolEventHandler(CALLSETClipRsp, PRT_MMI_SS_CLIP_INTERROGATE_IND);
    SetProtocolEventHandler(CALLSETClirRsp, PRT_MMI_SS_CLIR_INTERROGATE_IND);
    SetProtocolEventHandler(CALLSETColpRsp, PRT_MMI_SS_COLP_INTERROGATE_IND);
    SetProtocolEventHandler(CALLSETColrRsp, PRT_MMI_SS_COLR_INTERROGATE_IND);
    SetProtocolEventHandler(CALLSETCnapRsp, PRT_MMI_SS_CNAP_INTERROGATE_IND);
    SetProtocolEventHandler(CALLSETCcbsQueryRsp, PRT_MMI_SS_CCBS_RSP);
    SetProtocolEventHandler(CALLSETEmlppQueryRsp, PRT_MMI_SS_EMLPP_RSP);
    SetProtocolEventHandler(CALLSETWaitingRsp, PRT_MMI_SS_CALL_WAIT_RSP);
    SetProtocolEventHandler(CALLSETForwardRsp, PRT_MMI_SS_CALL_FORWARD_RSP);
    SetProtocolEventHandler(CALLSETBarringRsp, PRT_MMI_SS_CALL_BARRING_RSP);
    SetProtocolEventHandler(CALLSETBarringPassRsp, PRT_MMI_SS_CHANGE_PASSWORD_RSP);

#ifdef __MMI_DUAL_SIM_MASTER__
    SetSlaveProtocolEventHandler(mmi_gsm_slave_ussn_ind, PRT_USSN_IND);
    SetSlaveProtocolEventHandler(mmi_gsm_slave_ussr_ind, PRT_USSR_IND);

    SetSlaveProtocolEventHandler(CALLSETClipRsp, PRT_MMI_SS_CLIP_INTERROGATE_IND);
    SetSlaveProtocolEventHandler(CALLSETClirRsp, PRT_MMI_SS_CLIR_INTERROGATE_IND);
    SetSlaveProtocolEventHandler(CALLSETColpRsp, PRT_MMI_SS_COLP_INTERROGATE_IND);
    SetSlaveProtocolEventHandler(CALLSETColrRsp, PRT_MMI_SS_COLR_INTERROGATE_IND);
    SetSlaveProtocolEventHandler(CALLSETCnapRsp, PRT_MMI_SS_CNAP_INTERROGATE_IND);
    SetSlaveProtocolEventHandler(CALLSETCcbsQueryRsp, PRT_MMI_SS_CCBS_RSP);
    SetSlaveProtocolEventHandler(CALLSETEmlppQueryRsp, PRT_MMI_SS_EMLPP_RSP);
    SetSlaveProtocolEventHandler(CALLSETWaitingRsp, PRT_MMI_SS_CALL_WAIT_RSP);
    SetSlaveProtocolEventHandler(CALLSETForwardRsp, PRT_MMI_SS_CALL_FORWARD_RSP);
    SetSlaveProtocolEventHandler(CALLSETBarringRsp, PRT_MMI_SS_CALL_BARRING_RSP);
    SetSlaveProtocolEventHandler(CALLSETBarringPassRsp, PRT_MMI_SS_CHANGE_PASSWORD_RSP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  InitIncomingCall
 * DESCRIPTION
 *  To Initialize the Incoming Call Management Application
 *  
 *  This function sets up the handlers required for event flow and
 *  application management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReinitalizeIncomingCall();

    SetHiliteHandler(MITEM_INC_OPT_ANSWER, HiliteMenuIncomingAnswer);
    SetHiliteHandler(MITEM_INC_OPT_DEFLN, HiliteMenuIncomingCallDeflection);
    SetHiliteHandler(MITEM_CCBS_OPT_DIAL, HiliteMenuCCBSDial);

    SetHiliteHandler(MITEM_INC_ACT_OPT_END_ACT, HiliteM2019AllActiveEnd);
    SetHiliteHandler(MITEM_IAH_OPT_END_ACT, HiliteM2019AllActiveEnd);
    SetHiliteHandler(MITEM_IMA_OPT_END_ONE_ACT, HiliteM2011SingleActiveEnd);
    SetHiliteHandler(MITEM_IMAH_OPT_END_ONE_ACT, HiliteM2019AllActiveEnd);

    SetHiliteHandler(MITEM_IMA_OPT_END_ALL_ACT, HiliteMenuEndAllCalls);
    SetHiliteHandler(MITEM_INC_MHLD_OPT_END, HiliteMenuEndAllCalls);
    SetHiliteHandler(MITEM_IAH_OPT_END_ALL, HiliteMenuEndAllCalls);

    SetHiliteHandler(MITEM_INC_HLD_OPT_END, HiliteM2020AllHeldEnd);
    SetHiliteHandler(MITEM_IAH_OPT_END_HLD, HiliteM2020AllHeldEnd);
    SetHiliteHandler(MITEM_IAMH_ALL_HELD_END, HiliteM2020AllHeldEnd);

    SetHiliteHandler(MITEM_INC_ACT_OPT_HOLD_ACT, HiliteM2014Swap);
    SetHiliteHandler(MITEM_IMA_OPT_HOLD_CONF, HiliteM2014Swap);
    SetHiliteHandler(MITEM_INC_HLD_OPT_RTRV, HiliteM2014Swap);
    SetHiliteHandler(MITEM_INC_MHLD_OPT_RTRV, HiliteM2014Swap);
    SetHiliteHandler(MITEM_IAH_OPT_SWAP, HiliteM2014Swap);

    SetHiliteHandler(MITEM_IAH_OPT_CONFER, HiliteM2015Conference);
    SetHiliteHandler(MITEM_IAH_OPT_TRANSFER, HiliteM2017Transfer);
    SetHiliteHandler(MITEM_IMA_OPT_SPLIT, HiliteM2018Split);
    SetHiliteHandler(MITEM_INC_ACT_OPT_MUTE, HiliteM2020Mute);
    SetHiliteHandler(MITEM_INC_ACT_OPT_LOUDSP, HiliteM2023LoudSp);

	SetHintHandler(MITEM_INC_ACT_OPT_MUTE, Hint2020Mute); /*option menu for waiting call*/
}


/*****************************************************************************
 * FUNCTION
 *  HiliteMenuIncomingAnswer
 * DESCRIPTION
 *  Hilite function for Incoming Answer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteMenuIncomingAnswer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(KbCBackCallIncomingAccepted, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteMenuIncomingCallDeflection
 * DESCRIPTION
 *  Hilite function for Call Deflection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteMenuIncomingCallDeflection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_HiliteMenuIncomingCallDeflection);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(HandleCallDelfectDigitEntry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteMenuCCBSDial
 * DESCRIPTION
 *  hilite handler to invoke the function that dials the ccbs call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteMenuCCBSDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_HiliteMenuCCBSDial);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(KbCBackCCBSDialCall, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HiliteMenuEndAllCalls
 * DESCRIPTION
 *  Hilite function End all call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteMenuEndAllCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_HiliteMenuEndAllCalls);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(KbCBackEndAllCallsExceptIncoming, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCallIncoming
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  is an incoming call
 *  
 *  The toHistory is so that the Incoming Call Screen is saved
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCallIncoming(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackCallIncoming);
    ProcessIncomingEvents(CM_PS_CALL_INCOMING, info);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCallWait
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  is an incoming call
 *  
 *  The toHistory is so that the Incoming Call Screen is saved
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCallWait(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackCallWait);
    ProcessIncomingEvents(CM_PS_CALL_WAIT, info);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackNetworkCallDropped
 * DESCRIPTION
 *  This function is called back by the protocol stack when the
 *  Netowrk drops incoming call
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackNetworkCallDropped(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackNetworkCallDropped);
    ProcessIncomingEvents(CM_PS_NWK_CALL_DROP, info);
}

/*****************************************************************************
 * FUNCTION
 *  PsCBackActivatedCCBS
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  CCBS activation response is received
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackActivatedCCBS(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckChldRequestSuccess(info, &result))
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackActivatedCCBS1);
        ProcessIncomingEvents(CM_PS_ACTIVATED_CCBS, info);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackActivatedCCBS2);
        ProcessIncomingFailureEvents(CM_PS_ACTIVATED_CCBS, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCcbsActivate
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  is outgoing call disconnect indication(CCBS)
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCcbsActivate(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackCcbsActivate);
    result = CheckRspCcbsFlag(info);
    if (result == TRUE)
    {
        ProcessIncomingEvents(CM_PS_CCBS_ACTIVATE, info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCCBSInvoked
 * DESCRIPTION
 *  This function is called back by the protocol stack when CCBS
 *  notification is there
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCCBSInvoked(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackCCBSInvoked);
    SetCCBSFlag(TRUE);
    ProcessIncomingEvents(CM_PS_CCBS_INVOKE, info);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackNotifySSInd
 * DESCRIPTION
 *  This function is intended for registering no on operation
 *  for PS Callback
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackNotifySSInd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) > 0) /*for both SIM1 and SIM2*/
    {	
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackNotifySSInd);
        ProcessIncomingEvents(CM_PS_SS_EVENT, info);
    }
}

/*****************************************************************************
 * FUNCTION
 *  PsCBackNotifyCNAPSSInd
 * DESCRIPTION
 *  This function is intended for registering no on operation
 *  for PS Callback
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackNotifyCNAPSSInd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() != CM_INCOMING_STATE)
    {
        return;
    }
    
    if(((MMI_SS_CNAP_IND*) info)->name_present)
    {
        SetCNAPName(((MMI_SS_CNAP_IND*)info)->call_id,
                    ((MMI_SS_CNAP_IND*)info)->dcs,
                    ((MMI_SS_CNAP_IND*)info)->length,
                    ((MMI_SS_CNAP_IND*)info)->name);        

        mmi_gsm_sync_call_list_ind();
    }
    else
    {
        for (count = 0; count < MAX_CALLS; count++)
        {
            if (cm_p->state_info.AllCalls[count].call_handle == ((MMI_SS_CNAP_IND*)info)->call_id)
            {

                if (mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[count].CNAPname) != 0)
                {
                    memset(&cm_p->state_info.AllCalls[count].CNAPname, 0, sizeof(cm_p->state_info.AllCalls[count].CNAPname));
                    mmi_gsm_sync_call_list_ind();
                }
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  PsCBackSpeechIndication
 * DESCRIPTION
 *  This function is called back by the protocol stack when the
 *  Held Call is made active.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackSpeechIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackSpeechIndication);
    ProcessIncomingEvents(CM_PS_SPEECH_IND, info);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackAocIndication
 * DESCRIPTION
 *  This function is called back by the protocol stack when the AOC
 *  indication is sent by the PS
 *  
 *  Info passed to the function is the call handle
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackAocIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackAocIndication);
    ProcessIncomingEvents(CM_PS_AOC_INDICATION, info);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackConfirmDTMFString
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackConfirmDTMFString(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DTMF_CONFIRM_IND *msg = (MMI_DTMF_CONFIRM_IND*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gDTMFConfirmBuf, 0, MAX_DTMFBUF_DIGITS);
    strcpy((PS8) gDTMFConfirmBuf, (PS8) msg->digits);

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackAocIndication);

    ProcessIncomingEvents(CM_PS_CONFIRM_DTMF_STRING, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  NotifyCMClampOpen
 * DESCRIPTION
 *  Clamp Open Handler for CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CLAMSHELL__
void NotifyCMClampOpen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        if (TRUE == (((MMI_ANSWERING_MODE*) GetAnswerMode())->coverAnswer))
        {
            KbCBackCallIncomingAccepted();
        }
    #ifdef __MMI_INCOMING_CALL_VIDEO__
        else
        {
            CM_CALL_HANDLE handle;
            U16 imgId;

            handle = GetIncomingCallHandle();
            imgId = GetCallImgId(handle);

            /* overwrite sub LCD with static image */
            if ((imgId & 0x8000) || ((imgId & 0x3fff) >= VDO_ID_PHB_MTCALL_1))
            {
                /* user defined video file or system default video resource */
                /* draw static sub LCD */
                DisableCategory17VideoUpdate();
                ShowCategory332Screen(IMG_CM_STATE_CONNECTED);
                EnableCategory17VideoUpdate();
            }
        }
    #endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  NotifyCMClampClose
 * DESCRIPTION
 *  Clamp Close Handler for CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NotifyCMClampClose(void)
{
    ASSERT(0);
}
#endif /* __MMI_CLAMSHELL__ */ 


/*****************************************************************************
 * FUNCTION
 *  HangupAllCalls
 * DESCRIPTION
 *  Hangs Up All Calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HangupAllCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_HangupAllCalls);

#ifdef WAP_SUPPORT
    if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE) > 0 && wap_bearer_csd_is_disc())
    {
        return;
    }
#endif /* WAP_SUPPORT */ 

    mmi_ucm_end_all_action();
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackCallIncomingAccepted
 * DESCRIPTION
 *  This function is called back by the keyboard handler
 *  when the user selects accepts incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackCallIncomingAccepted(void)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackCallIncomingRejected
 * DESCRIPTION
 *  This function is called back by the keyboard handler
 *  when the user selects rejects incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackCallIncomingRejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAttempToReject = TRUE;
    ProcessIncomingEvents(CM_KB_INCOMING_CALL_REJECT, NULL);
}

#ifdef __MMI_SIDEKEY_SUPPRESS_RING__


/*****************************************************************************
 * FUNCTION
 *  KbCBackCallIncomingRejectedNoTone
 * DESCRIPTION
 *  Reject MT call and stop ring tone when long press
 *  or double press side down key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackCallIncomingRejectedNoTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAttempToReject = TRUE;
    UnSilencethePhone();
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    ProcessIncomingEvents(CM_KB_INCOMING_CALL_REJECT, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackCallIncomingSuppressTone
 * DESCRIPTION
 *  Set key handler for side down key in its first press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackCallIncomingSuppressTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(KbCBackCallIncomingRejectedNoTone, KEY_VOL_DOWN, KEY_EVENT_UP);
}
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 


/*****************************************************************************
 * FUNCTION
 *  KbCBackEndActiveAcceptIncomingCall
 * DESCRIPTION
 *  End active and accept waiting call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackEndActiveAcceptIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopIncomingCallIndication();
    ProcessIncomingEvents(CM_KB_END_ACTIVE_ACCEPT_INCOMING, NULL);
}

/**************************************************************

   FUNCTION NAME     : KbCBackEndSelectiveActiveCall(void)

   PURPOSE           : This function is called back by the keyboard handler
                         when the user selects option to End an active call

   INPUT PARAMETERS  : nil

   OUTPUT PARAMETERS : nil

   RETURNS           : void

   REMARKS           : nil

**************************************************************/
/* void KbCBackEndSelectiveActiveCall(void)
   {
   if (gCallToEnd!=-1)
   MakePsEndSelectiveCall ((void*)PsCBackselectedCallEnded, gCallToEnd);
   else
   PRINT_INFORMATION("CM_TEST File: [%s]  Line: [%d] <<No Call To End>>\n",__FILE__,__LINE__);
   } */


/*****************************************************************************
 * FUNCTION
 *  KbCBackEndAllCallsExceptIncoming
 * DESCRIPTION
 *  This function is called back by the keyboard handler
 *  when the user selects rejects incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackEndAllCallsExceptIncoming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UnSilencethePhone();
    OutgoingProcessCMEvent(CM_KB_HANGUPALLREQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  IgnoreCCBS
 * DESCRIPTION
 *  To invoke the function that ignore the CCBS invoke
 *  
 *  yet to  implement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IgnoreCCBS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_IgnoreCCBS);
    SetCCBSFlag(FALSE);
    MakePsEndSelectiveCall((void*)HangupReqSucess, GetOutgoingCallHandle());
}

/*****************************************************************************
 * FUNCTION
 *  ActivateCCBS
 * DESCRIPTION
 *  To invoke the function that activates the CCBS
 *  
 *  yet to  implement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateCCBS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ActivateCCBS);
    SetCCBSFlag(FALSE);
    MakePsActivateCCBS((void*)PsCBackActivatedCCBS);
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackCCBSDialCall
 * DESCRIPTION
 *  This function is called back by the keyboard handler
 *  when the user selects dial ccbs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackCCBSDialCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UnSilencethePhone();
    StopIncomingCallIndication();
    CCBSUpdateCallInfo();
    ProcessIncomingEvents(CM_PS_CCBS_INVOKE_DIAL, NULL);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackCCBSInvokeRejected
 * DESCRIPTION
 *  This function is called back by the keyboard handler
 *  when the user selects rejects ccbs invoke
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackCCBSInvokeRejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UnSilencethePhone();
    StopIncomingCallIndication();
    ProcessIncomingEvents(CM_PS_CCBS_INVOKE_REJECT, NULL);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  IgnoreDTMFStringAndGoBackHistory
 * DESCRIPTION
 *  cancels sending dtmf string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IgnoreDTMFStringAndGoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("IgnoreDTMFStringAndGoBackHistory\n");

    SetNoSave();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ConfirmDTMFString
 * DESCRIPTION
 *  Send confirm dtmf notification to ps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConfirmDTMFString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MakePsSendDTMFString(gDTMFConfirmBuf);
}


/*****************************************************************************
 * FUNCTION
 *  SetKeysForPOPUp
 * DESCRIPTION
 *  Sets Group Handler for all Keys on Popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetKeysForPOPUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler((FuncPtr) POPUPHandler, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  POPUPHandler
 * DESCRIPTION
 *  Group Key Handler for all Keys on CM Popups
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void POPUPHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_NOTIFYDURATION_TIMER);
    GoBackfromNotifyScr();
}


/*****************************************************************************
 * FUNCTION
 *  ProcessHeadsetKeyPress
 * DESCRIPTION
 *  HeadSet Key Handling Depending on various conditions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_sms_abort_sms(void);
extern U16 GetCurrScreenID(void);
void ProcessHeadsetKeyPress(void)
{
    ASSERT(0);
}


#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 

extern void Process_InComingCall_G_Sensor(void) ;

#endif


/*****************************************************************************
 * FUNCTION
 *  ProcessIncomingEvents
 * DESCRIPTION
 *  This function is the entry into the Call Management State
 *  Machine.
 *  
 *  This function controls the Incoming Call management applicaion
 *  as per keyboard event and protocol event
 * PARAMETERS
 *  event           [IN]        
 *  info            [?]         
 *  Incoming(?)     [IN]        Event Type, Any information associated with the event
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessIncomingEvents(CM_EVENT_TYPES event, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ACTION_RESULT result = CM_NO_INCOMING;

    /* Start by Julia: Drop call refinement */
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* End by Julia */
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessIncomingEvents);

    switch (event)
    {

      /******************* indications *********************/

        case CM_PS_CALL_INCOMING:
            /* incoming call */
		result = ProcessIncomingCallEvent(info);

		   #if defined(G_SENSOR_SUPPORT)
		   //Huyanwei Add It 
		   Process_InComingCall_G_Sensor();
		   #endif

			
            if (result != CM_CALL_SUCCESS)
            {
                if (result == CM_NO_INCOMING)
                {
                    PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Cannot Accept anymore incoming calls>>\n", __FILE__, __LINE__);
                }
                else
                {
                    PRINT_INFORMATION("CM_TEST File: [%s]  Line: [%d] <<Error Processing Incoming Call Event>>\n",
                                       __FILE__, __LINE__);
                }
            }
            break;

        case CM_PS_CALL_WAIT:
            /* waiting call */
            // Start by Julia: Drop call refinement
            // automatically release all disconnecting call before incoming call comes in 
            SetAutoReleaseFlag(TRUE);
            ReleaseCall();
            /* End by Julia */
            result = ProcessCallWait(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** Error processing waiting call>>\n", __FILE__,
                                   __LINE__);
            }
            break;

        case CM_PS_CCBS_ACTIVATE:
            /* CCBS available ind */
            EntryScrCcbsActivate();
            break;

        case CM_PS_CCBS_INVOKE:
            /* CCBS invoke */
            result = ProcessInvokedCcbs(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("CM_TEST File: [%s]  Line: [%d] <<Error Processing CCBS Invoke Event>>\n", __FILE__,
                                   __LINE__);
            }
            break;

        case CM_PS_INCOMING_CALL_DROPPED:
            /* MT drop */
            SetIncomingCallDroppedFlag(TRUE);
            result = ProcessIncomingCallRejected(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Could Not drop incoming call>>\n",
                                   __FILE__, __LINE__);
            }
            break;
            
        case CM_PS_NWK_CALL_DROP:
            /* call drop */
            result = ProcessEndCallIdAndGoBack(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("CM_TEST File: [%s]  Line: [%d] <<Error Processing Network Drop Event>>\n", __FILE__,
                                   __LINE__);
            }
            break;

        case CM_PS_SS_EVENT:
            ProcessShowSSEventNotification(info);
            break;

        case CM_PS_SPEECH_IND:
            ReverseSpeechIndication(info);
            break;

        case CM_PS_AOC_INDICATION:
            result = ProcessAocIndication(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Error In processing AOC >>\n",
                                   __FILE__, __LINE__);
            }
            break;

        case CM_PS_CONFIRM_DTMF_STRING:
            /* DTMF confirm ind */
            StartTimer(CM_AUTO_DTMF_CONFIRM_TIMER, CM_NOTIFY_TIMEOUT, EntryScrConfirmDTMFString);
            break;

   /****************** request/responses ***********************/

        case CM_KB_INCOMING_CALL_ACCEPT:
            /* SEND key in MT call */
            ProcessStateCheckIncomingCall();
            break;

        case CM_PS_INCOMING_CALL_CONNECTED:
            /* SEND key rsp */
            result = ProcessAcceptIncomingCall(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** COuld Not accept incoming call>>\n",
                                   __FILE__, __LINE__);
            }
            break;

        case CM_PS_ACTIVE_CALL_HELD:
            result = ProcessCallsHeld(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Could Not hold active call>>\n",
                                   __FILE__, __LINE__);
            }
            break;

        case CM_KB_INCOMING_CALL_REJECT:
            handle = GetIncomingCallHandle();
            /* END key in MT call */
            if (GetTotalCallCount() > 1)
            {
                SetCallState(handle, CM_DISCONNECTING_STATE, TRUE);
                MakePsSendUDUB((void*)PsCBackIncomingCallRejected);    /* special case for ending waitng call */
            }
            else
            {
                SetCallState(handle, CM_DISCONNECTING_STATE, TRUE);
                MakePsAthRequest((void*)PsCBackIncomingCallRejected);
            }
            break;

        case CM_PS_INCOMING_CALL_REJECTED:
            /* 0 send / END key rsp */
            SetIncomingCallDroppedFlag(TRUE);
            result = ProcessIncomingCallRejected(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Could Not drop incoming call>>\n",
                                   __FILE__, __LINE__);
            }
            break;

        case CM_KB_END_ACTIVE_ACCEPT_INCOMING:
            /* 1 send */
            /* Start by Julia: Drop call refinement */
            SetAllActiveCallState(CM_DISCONNECTING_STATE);
            //EntryScr1002ActiveCall();
            // End by Julia
            gAttempToAnswer = TRUE;
            MakePsHangupallActiveAcceptOtherRequest((void*)PsCBackselectedCallEnded);
            SetProtocolEventHandler(PsCBackCheckChldIncomingCallAccepted, PRT_END_CHLD_RSP);
            break;

        case CM_PS_ACTIVE_CALL_DISCONNECTED:
            /* 1 send / Menu End Single release ind */
            OutgoingProcessCMEvent(CM_PS_HANGUPSUC, info);
            break;

        case CM_KB_END_ALL_ACTIVE_RETRIEVE_HELD:
            /* 1 send */
            /* Start by Julia: Drop call refinement */
            SetAllActiveCallState(CM_DISCONNECTING_STATE);
            //EntryScr1002ActiveCall();
            // End by Julia
            MakePsHangupallActiveAcceptOtherRequest((void*)PsCBackActiveCallEndedHeldRetrieved);
            break;

        case CM_PS_ALL_ACTIVE_CALL_DISCONNECTED:
            /* 1 send release ind */
            result = ProcessEndAllActiveCall(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Could Not end all active calls>>\n",
                                   __FILE__, __LINE__);
            }
            break;

        case CM_PS_HELD_CALL_ACTIVE:
            /* 1 send rsp */
            result = ProcessHold2Active(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** State Machine ** Could Not make hold call active>>\n",
                                   __FILE__, __LINE__);
            }
            break;

        case CM_PS_CCBS_INVOKE_DIAL:
            /* SEND key in CCBS invoke, change to KB */
            result = ProcessCCBSDialRequest(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** Error processing Dial CCBS>>\n", __FILE__, __LINE__);
            }
            break;

        case CM_PS_ACTIVATED_CCBS:
            /* 5 send rsp */
            EntryScrNotifyCCBSSuccess();
            break;

        case CM_PS_CCBS_INVOKE_REJECT:
            /* END key in CCBS invoke */
            result = ProcessCCBSRejectRequest(info);
            if (result != CM_CALL_SUCCESS)
            {
                PRINT_INFORMATION("File: [%s]  Line: [%d] <<** Error processing Dial CCBS>>\n", __FILE__, __LINE__);
            }
            break;

        case CM_KB_HANG_ALL_CALLS:
            /* END key in MMI, move to outgoingcallmanagement */
            /* Start by Julia: Drop call refinement */
            /*
             * #ifdef __MMI_CLAMSHELL__
             * if (IsClamClose() == FALSE)
             * #endif
             */
            SetAllCallState(CM_DISCONNECTING_STATE);
            //EntryScr1002ActiveCall();
            // End by Julia
            if (-1 != GetIncomingCallHandle())
            {
                StopIncomingCallIndication();
            }
            MakePsHangupallCallsRequest((void*)HangupallReqSucess);
            break;

        default:
            PRINT_INFORMATION("File: [%s]  Line: [%d] <<Not Valid State Machine event>>\n", __FILE__, __LINE__);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  ProcessIncomingCallEvent
 * DESCRIPTION
 *  This function is called by the state machine function
 *  hold Process an incoming call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with incoming call
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessIncomingCallEvent(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IncomingCall myIncmg;
    U8 TempNumber[MAX_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessIncomingCallEvent);


    DeriveCallInfo(info, &myIncmg);
	
    mmi_asc_to_ucs2((PS8) TempNumber, (PS8) myIncmg.Number);
    mmi_ucs2cpy((PS8) myIncmg.Number, (PS8) TempNumber);

    switch (GetCurrentState())
    {
        case CM_IDLE_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessIncomingCallEvent1);

            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_INCOMING_STATE);

            AddNewCallInfo(
                myIncmg.Number,
                GetCurrentState(),
                GetPreviousState(),
                CM_CALL_MT,
                (CM_CALL_HANDLE) myIncmg.callHandle,
                myIncmg.callType);
			
            /*CNAP*/
            if(((MMI_INCOMING*)info)->name_present)
            {
                SetCNAPName(((MMI_INCOMING*)info)->call_id,
                            ((MMI_INCOMING*)info)->dcs,
                            ((MMI_INCOMING*)info)->length,
                            ((MMI_INCOMING*)info)->name);
            }

	#ifdef __MMI_CM_BLACK_LIST__//sc.wu, backlist
		if (BlockedHandle((CM_CALL_HANDLE) myIncmg.callHandle) == TRUE)
		{
		    ProcessIncomingEvents(CM_KB_INCOMING_CALL_REJECT, info);
		    return CM_CALL_SUCCESS;
		}
	#endif /* __MMI_CM_BLACK_LIST__ */ 
            
			mmi_gsm_ring_ind();

			return CM_CALL_SUCCESS;

        case CM_OUTGOING_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessIncomingCallEvent2);

            if (cm_p->redial_info.RedialState == TRUE)
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_INCOMING_STATE);

                AddNewCallInfo(
                    myIncmg.Number,
                    GetCurrentState(),
                    GetPreviousState(),
                    CM_CALL_MT,
                    (CM_CALL_HANDLE) myIncmg.callHandle,
                    myIncmg.callType);

                mmi_gsm_ring_ind();

                return CM_CALL_SUCCESS;
            }
            else
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_INCOMING_STATE);

                AddNewCallInfo(
                    myIncmg.Number,
                    GetCurrentState(),
                    GetPreviousState(),
                    CM_CALL_MT,
                    (CM_CALL_HANDLE) myIncmg.callHandle,
                    myIncmg.callType);
                
                mmi_gsm_ring_ind();

                return CM_CALL_SUCCESS;
            }
    }	
    return CM_CALL_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessCallWait
 * DESCRIPTION
 *  This function is called by the state machine function
 *  hold Process an incoming call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with incoming call
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessCallWait(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IncomingCall myIncmg;
    U8 TempNumber[MAX_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessCallWait);

    gAttempToAnswer = FALSE;

    SetPreviousState(GetCurrentState());
    SetCurrentState(CM_INCOMING_STATE);

    SetCallWaitFlag(TRUE);

    DeriveCallInfoFromWait(info, &myIncmg);
    mmi_asc_to_ucs2((PS8) TempNumber, (PS8) myIncmg.Number);
    mmi_ucs2cpy((PS8) myIncmg.Number, (PS8) TempNumber);

    AddNewCallInfo(
        myIncmg.Number,
        GetCurrentState(),
        GetPreviousState(),
        CM_CALL_MT,
        (CM_CALL_HANDLE) myIncmg.callHandle,
        myIncmg.callType);

    /*CNAP*/
    if(((MMI_CALL_WAIT*)info)->name_present)
    {
        SetCNAPName(((MMI_CALL_WAIT*)info)->call_id,
                    ((MMI_CALL_WAIT*)info)->dcs,
                     ((MMI_CALL_WAIT*)info)->length,
                     ((MMI_CALL_WAIT*)info)->name);
    }

    mmi_gsm_ring_ind();

    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessInvokedCcbs
 * DESCRIPTION
 *  This function is called when CCBS
 *  invoked notification is there
 * PARAMETERS
 *  info            [?]         
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessInvokedCcbs(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IncomingCall myIncmg;
    U8 TempNumber[MAX_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessInvokedCcbs);

    DeriveCcbsCallInfo(info, &myIncmg);
    mmi_asc_to_ucs2((PS8) TempNumber, (PS8) myIncmg.Number);
    mmi_ucs2cpy((PS8) myIncmg.Number, (PS8) TempNumber);
    SetCCBSHandle((CM_CALL_HANDLE) myIncmg.callHandle);
    SetCCBSNumber((U8 *)myIncmg.Number);
    EntryScrCCBSInvokeEvent();
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  ProcessIncomingCallRejected
 * DESCRIPTION
 *  This function is called by the state machine function reject
 *  incoming call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with incoming call
 *  Success(?)      [OUT]       Or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessIncomingCallRejected(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0;    /* Set if previous state is outgoing */
    U16 count = 0;
    BOOL ath = FALSE;    /* Set if use ath to drop the incoming call*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessIncomingCallRejected);

    /*Store uid info for UCM release ind*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if(GetTotalCallCount() == 1 && GetCurrentState() == CM_INCOMING_STATE)
        {
            if(cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE)
            {
                cm_p->disc_call.ucm_current_uid.call_id = cm_p->state_info.AllCalls[count].call_handle;
                cm_p->disc_call.ucm_current_uid.group_id = cm_p->state_info.AllCalls[count].group_id;
                cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);            
                cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */
                ath = TRUE;
                break;
            }
        }
        else if(cm_p->state_info.AllCalls[count].call_handle == ((MMI_RELEASE_IND*) info)->call_id)
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

    if ((GetTotalCallCount() > 1) && (GetIncomingCallHandle() != ((MMI_RELEASE_IND*) info)->call_id))
    {
        /* use chld to reject */
        /* dropped is not MT call, use default drop call handler */
        PsCBackNetworkCallDropped(info);
        return CM_CALL_SUCCESS;
    }
    else if ((GetTotalCallCount() == 1 && GetCurrentState() != CM_INCOMING_STATE) || (GetIncomingCallHandle() == -1))
    {
        /* use ath to reject or call already dropped when ath rsp comes */
        CM_CALL_HANDLE handle;

        PRINT_INFORMATION("ProcessIncomingCallRejected: not incoming state");
        handle = GetHungUpHandle();
        if (handle != -1)
        {
            OutgoingProcessCMEvent(CM_PS_HANGUPSUC, (void*)&handle);
        }
        return CM_CALL_SUCCESS;
    }

    gAttempToReject = FALSE;
    ResetCallflag(GetIncomingCallHandle(), CM_HANGUP_REQUESTED, TRUE);

    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);

    switch (GetPreviousState())
    {
        case CM_IDLE_STATE:
            SetPreviousState(CM_INCOMING_STATE);
            SetCurrentState(CM_IDLE_STATE);
            break;

        case CM_HOLD_STATE:
            if (GetTotalHoldCallCount() > 0)
            {
                SetCurrentState(CM_HOLD_STATE);
                SetPreviousState(CM_INCOMING_STATE);
            }
            else
            {
                SetCurrentState(CM_IDLE_STATE);
                SetPreviousState(CM_IDLE_STATE);
            }
            break;

        case CM_ACTIVE_STATE:
            if (GetTotalActiveCallCount() > 0)
            {
                SetCurrentState(CM_ACTIVE_STATE);
                SetPreviousState(CM_INCOMING_STATE);
            }
            else
            {
                SetCurrentState(CM_IDLE_STATE);
                SetPreviousState(CM_IDLE_STATE);
            }
            break;

        case CM_INCOMING_STATE:
            if (GetCurrentState() == CM_OUTGOING_STATE)
            {
            }
            else if (GetCurrentState() == CM_INCOMING_STATE)
            {
            }
            else if (GetTotalActiveCallCount() > 0)
            {
                SetCurrentState(CM_ACTIVE_STATE);
            }
            else if (GetTotalHoldCallCount() > 0)
            {
                SetCurrentState(CM_HOLD_STATE);
            }
            else
            {
                SetCurrentState(CM_IDLE_STATE);
            }
            break;

        case CM_OUTGOING_STATE:
            flag = 1;
            break;

        default:
            PRINT_INFORMATION("Previous State is Unknown this should not happen\n");
            return CM_CALL_FAILURE;
    }

    if (GetIncomingCallDroppedFlag())
    {
        SetIncomingCallDroppedFlag(FALSE);
    }

    PurgeIncomingCallStructure();

    if (1 == flag)
    {
        UpdateStateMachine();
    }

    mmi_gsm_release_ind(GetCallEndCause());

    /*ath is not like chld*/
    if(ath == TRUE)
    {
        if(cm_p->ucm_operation == MMI_GSM_UCM_END_SINGLE)
        {
            mmi_gsm_end_single_rsp(TRUE, NULL);
        }
        else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ALL)
        {
            mmi_gsm_end_all_rsp(TRUE, NULL);
        }
    }
    
    return CM_CALL_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  ProcessEndCallIdAndGoBack
 * DESCRIPTION
 *  This function is called by the state machine function in
 *  to make call to protocol stack to get call list to sync with MMI
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessEndCallIdAndGoBack(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;
    CALL_STATE state;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessEndCallIdAndGoBack);

    handle = DeriveCallHandle(info);

    if(GetCCBSHandle() == handle)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"CCBS recall timeout:%d", handle);
        mmi_gsm_ccbs_recall_conf_cancel();
        return;
    }

    /*Store uid info for UCM release ind*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if(cm_p->state_info.AllCalls[count].call_handle == ((MMI_RELEASE_IND*) info)->call_id)
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
        #endif /*  __SAT__ */
        }
    }

    state = GetCurrentState();

    if (GetMMIStructIndexof(handle) == -1)
    {
        PRINT_INFORMATION("\ncall already dropped in ProcessEndCallIdAndGoBack\n");
        return CM_CALL_SUCCESS;
    }

    SetCallEndCause((U16) ((MMI_RELEASE_IND*) info)->cause);
    
    state = GetCallState(handle);

    /* when there's pending req on the dropped call, sync all call state with PS */
    if (GetCallflag(handle, TRUE) & (~CM_HANGUP_REQUESTED) != 0)
    {
        SyncCallList();
    }

    switch (state)
    {
        case CM_INCOMING_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessEndCallIdAndGoBack1);
            SetCallEndCause(0);
            ProcessIncomingEvents(CM_PS_INCOMING_CALL_DROPPED, info);
            return CM_CALL_SUCCESS;

        case CM_OUTGOING_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessEndCallIdAndGoBack2);

            if (cm_p->ucm_operation == MMI_GSM_UCM_IDLE && IsRedialSet() && IsRedialNeeded((U16) ((MMI_RELEASE_IND*) info)->cause))
            {
                MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessEndCallIdAndGoBack3);
                SetRedialNumber();
                OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, GetCallEndCause());
                /* SetCallEndCause(0); */
                SetCallEndedBeforeConnFlag(FALSE);
                return CM_CALL_SUCCESS;
            }

            SetCallState(handle, CM_IDLE_STATE, TRUE);
            UpdateStateMachine();
            if (GetCurrentState() == CM_OUTGOING_STATE)
            {
                SetCurrentState(GetPreviousState());
                SetPreviousState(CM_OUTGOING_STATE);
            }

            mmi_gsm_release_ind(GetCallEndCause());
            return CM_CALL_SUCCESS;

        case CM_HOLD_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessEndCallIdAndGoBack4);

            if (GetCurrentState() == CM_OUTGOING_STATE)
            {
                SetCallState(handle, CM_IDLE_STATE, TRUE);
                if (GetTotalHoldCallCount() == GetTotalCallCount())
                {
                    SetPreviousState(CM_OUTGOING_STATE);
                    SetCurrentState(CM_HOLD_STATE);
                }
                mmi_gsm_release_ind(GetCallEndCause());
                return CM_CALL_SUCCESS;
            }
            SetCallflag(handle, CM_HANGUP_REQUESTED, TRUE);
            OutgoingProcessCMEvent(CM_PS_HANGUPSUC, (void*)&handle);
            return CM_CALL_SUCCESS;

        case CM_ACTIVE_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessEndCallIdAndGoBack5);

            SetCallflag(handle, CM_HANGUP_REQUESTED, TRUE);
            OutgoingProcessCMEvent(CM_PS_HANGUPSUC, (void*)&handle);
            return CM_CALL_SUCCESS;

        default:
            PRINT_INFORMATION("<<** State Machine ** Not valid call state for handle>>\n");
            return CM_CALL_FAILURE;

    }
    return CM_CALL_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  ProcessShowSSEventNotification
 * DESCRIPTION
 *  This function derives SS information from PS and calls necessary
 *  entry function to show string
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessShowSSEventNotification(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeriveSSEvent(info);

    if(!IsMyTimerExist(SS_NOTIFY_TIMER))
    {
        StartTimer(SS_NOTIFY_TIMER, 100, UI_dummy_function);
        EntryScrShowSSEvent();
    }

#ifdef __CTM_SUPPORT__
    if(gSSEvent == CSMCC_NOTIFY_MPTY)
    {
        /*close CTM if the call is added into a conference*/
        mmi_gsm_ctm_open(FALSE);
    }
#endif  /*__CTM_SUPPORT__*/
    
}


/*****************************************************************************
 * FUNCTION
 *  ProcessAocIndication
 * DESCRIPTION
 *  This function is called by the state machine function in
 *  to make call to protocol stack to get call list to sync with MMI
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessAocIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acmIndValue;
    U8 temp[8];
    MMI_CCM_STRUCT *tmp_ccm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessAocIndication);

    tmp_ccm = (MMI_CCM_STRUCT*) info;    
    
    SetShowAOC(TRUE);

    memset(cashSign, 0, sizeof(cashSign));
    cashSign[0] = '$';

    acmIndValue = DeriveCcmValue(info);
    gSumACMValue += acmIndValue;

    memset((S8*) temp, 0, sizeof(temp));
    sprintf((S8*) temp, "%d", (U32) gSumACMValue);

    mmi_asc_to_ucs2((S8*) AocBuffer, (S8*) temp);

    switch (GetCurrentState())
    {
    	case CM_OUTGOING_STATE:
        case CM_HOLD_STATE:
        case CM_ACTIVE_STATE:
            //show_call_cost_UI(cashSign, (PU8) AocBuffer);
            mmi_gsm_call_cost_ind(tmp_ccm->call_id , (PU8) cashSign, (PU8) AocBuffer);
            return CM_CALL_SUCCESS;

        default:
            PRINT_INFORMATION("<<** Cannot Process AOC indication in this state>>\n");
            return CM_CALL_FAILURE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ReverseSpeechIndication
 * DESCRIPTION
 *  This function is called reverse the speech
 * PARAMETERS
 *  info        [?]         
 *  Info(?)     [IN]        From the PS
 * RETURNS
 *  void
 *****************************************************************************/
void ReverseSpeechIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL status;
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = CheckStatusOfSpeech(info, &type);
    MakePsReverseSpeechStatus(status, type);
}

/*****************************************************************************
 * FUNCTION
 *  IsAttemptToAnswer
 * DESCRIPTION
 *  
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL IsAttemptToAnswer(void)
{
    return gAttempToAnswer;
}


#ifdef __MMI_VOIP__
/**************************************************************
 * FUNCTION
 *  mmi_voip_entry_ans_to_disconn_gsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 **************************************************************/
void mmi_voip_entry_ans_to_disconn_gsm(void)
{
    SetAllCallsHangupFlag();
    ProcessIncomingEvents(CM_KB_HANG_ALL_CALLS, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_ans_to_conn_gsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_ans_to_conn_gsm(void)
{
    if (GetTotalActiveCallCount() > 0)
    {
        gAcceptIncoming = TRUE;
        SetHoldFlag();
        MakePsActiveHold((void*)PsCBackActiveCallsHeld);
    }
    else
    {
        MakePsCallAcceptIncoming((void*)PsCBackIncomingCallAccepted);
    }
}
#endif /* __MMI_VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  ProcessStateCheckIncomingCall
 * DESCRIPTION
 *  This function is called by the state machine function to
 *  decide what to do before accepting an incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessStateCheckIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessStateCheckIncomingCall);

    gAttempToAnswer = TRUE;

#ifdef __MMI_VOIP__
    /* release all voip calls before answering gsm call */
    if (mmi_voip_app_total_call())
    {
        mmi_voip_app_set_conn_flag(MMI_VOIP_CALL_CONN_GSM);
        mmi_voip_entry_ans_to_disconn_voip();
    }
    else
#endif /* __MMI_VOIP__ */
    {
        if (GetTotalActiveCallCount() > 0)
        {
            gAcceptIncoming = TRUE;
            SetHoldFlag();
            MakePsActiveHold((void*)PsCBackActiveCallsHeld);
        }
        else
        {
            MakePsCallAcceptIncoming((void*)PsCBackIncomingCallAccepted);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackIncomingCallAccepted
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  Incoming Call is accepted
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackIncomingCallAccepted(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAttempToAnswer = FALSE;

    if (CheckAtaSuccess(info, &result))
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackIncomingCallAccepted1);
        ProcessIncomingEvents(CM_PS_INCOMING_CALL_CONNECTED, info);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackIncomingCallAccepted2);
        /* accept fail doesn't imply call is disconnected */
        ProcessIncomingFailureEvents(CM_PS_INCOMING_CALL_CONNECTED, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCheckChldIncomingCallAccepted
 * DESCRIPTION
 *  This function is required to check the chld response and call
 *  necessary function
 *  
 *  This call back is registered in case it is required to
 *  accept incoming call via a chld request.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCheckChldIncomingCallAccepted(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetChldReqSent(CM_ACTION_NONE);

    if (CheckChldRequestSuccess(info, &cause))
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackCheckChldIncomingCallAccepted1);
        ProcessIncomingEvents(CM_PS_INCOMING_CALL_CONNECTED, info);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackCheckChldIncomingCallAccepted2);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ProcessIncomingFailureEvents(CM_PS_INCOMING_CALL_CONNECTED, cause);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackActiveCallsHeld
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  Active call is held
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackActiveCallsHeld(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    MMI_CHLD_RSP *chld_rsp = (MMI_CHLD_RSP*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackActiveCallsHeld);

    if(chld_rsp->opcode != CSMCC_HOLD_ACTIVE_AND_ACCEPT)
    {
        PRINT_INFORMATION("GSM call application:the chld op code:%d is not right",chld_rsp->opcode);
        return;
    }
    
    if (CheckChldRequestSuccess(info, &result))
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackActiveCallsHeld1);
        ProcessIncomingEvents(CM_PS_ACTIVE_CALL_HELD, info);
    }
    else
    {
        ResetHoldFlag();
        gAttempToAnswer = FALSE;
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_PsCBackActiveCallsHeld2, result);
        ProcessIncomingFailureEvents(CM_PS_ACTIVE_CALL_HELD, result);

        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ProcessCallsHeld
 * DESCRIPTION
 *  This function is called by the state machine function
 *  hold a call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with held call
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessCallsHeld(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessCallsHeld);

    if (GetTotalCallCount() > 0)
    {
        SyncCallList();
    }

    gAttempToAnswer = FALSE;

    switch (GetPreviousState())
    {
        case CM_INCOMING_STATE:
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ProcessCallsHeld);

            SetCurrentState(CM_INCOMING_STATE);
            SetPreviousState(CM_HOLD_STATE);
            MakeHold();
/*			if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_ACCEPT &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_hold_and_accept_rsp(TRUE, NULL);
    		}
			else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD &&
                        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_hold_rsp(TRUE, NULL);
    		}*/
            return CM_CALL_SUCCESS;

        case CM_ACTIVE_STATE:
            if (gAcceptIncoming)
            {
                MakeHold();
                ProcessIncomingEvents(CM_PS_INCOMING_CALL_CONNECTED, info);
                gAcceptIncoming = FALSE;
            }
            else
            {
                SetPreviousState(CM_HOLD_STATE);
                SetCurrentState(CM_ACTIVE_STATE);
                SetIncomingCallStateActive();
/*				if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_ACCEPT &&
                    cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
				{
					mmi_gsm_hold_and_accept_rsp(TRUE, NULL);
    			}
				else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD &&
                            cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
				{
					mmi_gsm_hold_rsp(TRUE, NULL);
    			}*/
            }
            return CM_CALL_SUCCESS;

        case CM_HOLD_STATE:
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_HOLD_STATE);
/*			if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_ACCEPT &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_hold_and_accept_rsp(TRUE, NULL);
    		}
			else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD &&
                        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_hold_rsp(TRUE, NULL);
    		}*/
            return CM_CALL_SUCCESS;
        default:
            return CM_CALL_FAILURE;
    }
    /* return CM_CALL_FAILURE; */
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackIncomingCallRejected
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  Incoming Call is reject
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackIncomingCallRejected(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackIncomingCallRejected);
    ProcessIncomingEvents(CM_PS_INCOMING_CALL_REJECTED, info);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
}


/*****************************************************************************
 * FUNCTION
 *  ProcessAcceptIncomingCall
 * DESCRIPTION
 *  This function is called by the state machine function accept
 *  incoming call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with incoming call
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessAcceptIncomingCall(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessAcceptIncomingCall);

    switch (GetPreviousState())
    {
        case CM_IDLE_STATE:
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_ACTIVE_STATE);
            SetIncomingCallStateActive();
			
			if(cm_p->ucm_operation == MMI_GSM_UCM_ACCEPT &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_accept_rsp(TRUE, NULL);
    		}
			else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT &&
                        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
    		}
            
            return CM_CALL_SUCCESS;

        case CM_ACTIVE_STATE:
            SetPreviousState(CM_INCOMING_STATE);
            SetCurrentState(CM_ACTIVE_STATE);
            SetIncomingCallStateActive();
			
			if(cm_p->ucm_operation == MMI_GSM_UCM_ACCEPT &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_accept_rsp(TRUE, NULL);
    		}
			else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT &&
                        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
    		}
			
            return CM_CALL_SUCCESS;

        case CM_HOLD_STATE:
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_ACTIVE_STATE);
            SetIncomingCallStateActive();

			if(cm_p->ucm_operation == MMI_GSM_UCM_ACCEPT &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_accept_rsp(TRUE, NULL);
    		}
			else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT &&
                        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
    		}

            return CM_CALL_SUCCESS;

        case CM_INCOMING_STATE:
        case CM_OUTGOING_STATE:
            SetPreviousState(CM_INCOMING_STATE);
            SetCurrentState(CM_ACTIVE_STATE);
            SetIncomingCallStateActive();

			if(cm_p->ucm_operation == MMI_GSM_UCM_ACCEPT &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_accept_rsp(TRUE, NULL);
    		}
			else if(cm_p->ucm_operation == MMI_UCM_END_ACTIVE_AND_ACCEPT &&
                        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_accept_rsp(TRUE, NULL);
    		}

            return CM_CALL_SUCCESS;

        default:
            return CM_CALL_FAILURE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackselectedCallEnded
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  selected active call ends
 *  
 *  info is actually the Call Handle
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackselectedCallEnded(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);

    gMyCallHandle = DeriveCallHandle(info);
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackselectedCallEnded, gMyCallHandle);
    ProcessIncomingEvents(CM_PS_ACTIVE_CALL_DISCONNECTED, &gMyCallHandle);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackActiveCallEndedHeldRetrieved
 * DESCRIPTION
 *  This function is called back by the protocol stack when active
 *  call ended for retrieve held
 *  
 *  info is actually the Call Handle
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackActiveCallEndedHeldRetrieved(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackActiveCallEndedHeldRetrieved);
    gMyCallHandle = DeriveCallHandle(info);

    ProcessIncomingEvents(CM_PS_ALL_ACTIVE_CALL_DISCONNECTED, &gMyCallHandle);
}


/*****************************************************************************
 * FUNCTION
 *  ProcessEndAllActiveCall
 * DESCRIPTION
 *  This function is called by the state machine function to
 *  end all active call
 * PARAMETERS
 *  info        [?]         
 *  Call(?)     [IN]        Handle
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessEndAllActiveCall(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE *handle;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessEndAllActiveCall);

    handle = (CM_CALL_HANDLE*) info;

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
    
    /* Start by Julia: Drop call refinement */
    if ((*handle) == -1)
    {
        PRINT_INFORMATION("\nBad call handle -1 in EndAllActiveCall\n");
		ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
        return CM_CALL_FAILURE;
    }
    /* dropped call is already released due to rel complete */
    else if (GetMMIStructIndexof(*handle) == -1)
    {
        PRINT_INFORMATION("\ncall already dropped in EndAllActiveCall\n");
		ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
        return CM_CALL_SUCCESS;
    }
    SetCallState(*handle, CM_IDLE_STATE, TRUE);
    
    mmi_gsm_release_ind(GetCallEndCause());
    
	return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  CBackHangupAllActive
 * DESCRIPTION
 *  Hangs Up all Active Calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CBackHangupAllActive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetChldReqSent(CM_ACTION_NONE);
    
    PRINT_INFORMATION("*** CBackHangupAllActive held calls ***");

    if(cm_p->ucm_operation == MMI_GSM_UCM_END_CONFERENCE &&
        cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
    {
        mmi_gsm_end_conference_rsp(TRUE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CBackHangupAllActiveAcceptOther
 * DESCRIPTION
 *  Hangs Up all Active Calls Except Incoming
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CBackHangupAllActiveAcceptOther(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 holdCall, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetChldReqSent(CM_ACTION_NONE);

    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);

    if (CheckChldRequestSuccess(info, &result))
    {
        holdCall = GetTotalHoldCallCount();
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_CBackHangupAllActiveAcceptOther, holdCall);

        if (holdCall > 0)
        {
            ProcessIncomingEvents(CM_PS_HELD_CALL_ACTIVE, NULL);
        }
    }
    else
    {
        /* fail to hold and accept => state not changed */
        ResetAllHangupFlag();
		RestoreCallState();
        if (GetTotalCallCount() > 0)
        {
            ShowCallManagementErrorMessage(result, cm_p->ucm_operation);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ProcessHold2Active
 * DESCRIPTION
 *  This function is called by the state machine function to
 *  make hold call active
 * PARAMETERS
 *  info                    [?]         
 *  Any(?)                  [IN]        Information associated with Held Call
 *  ACTION_RESULT(?)        [OUT]       If the function was a success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessHold2Active(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessHold2Active);

    if (GetTotalCallCount() > 0)
    {
        SyncCallList();
    }

    UpdateStateMachine();
    MakeRetrieve();

    switch (GetCurrentState())
    {
        case CM_INCOMING_STATE:
            SetPreviousState(CM_ACTIVE_STATE);
			if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_RETRIEVE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_retrieve_rsp(TRUE, NULL);
			}
            return CM_CALL_SUCCESS;

        case CM_ACTIVE_STATE:
            SetPreviousState(CM_HOLD_STATE);
			if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_RETRIEVE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_retrieve_rsp(TRUE, NULL);
			}
            return CM_CALL_SUCCESS;

        case CM_HOLD_STATE:
            if ((GetTotalCallCount() == GetTotalActiveCallCount()) && (GetTotalHoldCallCount() == 0))
            {
                SetPreviousState(GetCurrentState());
                SetCurrentState(CM_ACTIVE_STATE);
            }
			if(cm_p->ucm_operation == MMI_GSM_UCM_END_ACTIVE_AND_RETRIEVE &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_end_active_and_retrieve_rsp(TRUE, NULL);
			}
            return CM_CALL_SUCCESS;
        default:
            PRINT_INFORMATION("File: [%s]  Line: [%d] <<Problem in Hold To active>>\n", __FILE__, __LINE__);
            return CM_CALL_FAILURE;
    }
    /* return CM_CALL_FAILURE; */
}


/*****************************************************************************
 * FUNCTION
 *  ProcessCCBSDialRequest
 * DESCRIPTION
 *  This function is called by the state machine function
 *  to dial CCBS call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with ccbs
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessCCBSDialRequest(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessCCBSDialRequest);

    mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*)GetCCBSNumber());

    return CM_CALL_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  CCBSDialResponse
 * DESCRIPTION
 *  This function is called back by the protocol
 *  CCBS Dial response is recieved
 *  
 *  info is
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CCBSDialResponse(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_CCBSDialResponse);

    if (CheckChldRequestSuccess(info, &result))
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CCBSDialResponse1);
        
        SetPreviousState((CALL_STATE) GetCurrentState());
        SetCurrentState(CM_OUTGOING_STATE);
        
        gtmpOutgoingIndex = GetFirstFreeIndex();
        AddNewCallInfo(
            GetCCBSNumber(),
            (CALL_STATE) GetCurrentState(),
            CM_IDLE_STATE,
            CM_CALL_MO,
            GetCCBSHandle(),
            CSMCC_VOICE_CALL);
        
        if(cm_p->ucm_operation == MMI_GSM_UCM_DIAL)
        {
            mmi_gsm_dial_rsp(TRUE, CC_OPERATION, NULL);
        }
        else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_DIAL)
        {
            mmi_gsm_hold_and_dial_rsp(TRUE, CC_OPERATION, NULL);
        }
        else
        {
            ASSERT(0);
        }

        SetCCBSFlag(FALSE);
        SetCCBSHandle(-1);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CCBSDialResponse2);
        ProcessIncomingFailureEvents(CM_PS_CCBS_INVOKE_DIAL, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ProcessCCBSRejectRequest
 * DESCRIPTION
 *  This function is called by the state machine function
 *  to reject CCBS call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with ccbs
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
ACTION_RESULT ProcessCCBSRejectRequest(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessCCBSRejectRequest);
    SetCCBSFlag(FALSE);
    MakePsSendUDUB(NULL);
    return CM_CALL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackCCBSRejectResponse
 * DESCRIPTION
 *  This function is called back by the protocol
 *  stack when USSD data is recieved by n/w
 *  
 *  info is
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackCCBSRejectResponse(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_PsCBackCCBSRejectResponse);

    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
    ProcessIncomingEvents(CM_PS_INCOMING_CALL_REJECTED, info);
}


/*****************************************************************************
 * FUNCTION
 *  AcceptCallForAT
 * DESCRIPTION
 *  Accept Incoming Call from AT Command
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AcceptCallForAT(S16 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("AcceptCallForAT:%d",handle);
    SetPreviousState(CM_INCOMING_STATE);
    SetCurrentState(CM_ACTIVE_STATE);
    SetIncomingCallStateActive();
    mmi_gsm_accept_req_ind(handle);
}

#define PHB_PICTURE_TYPE_PIC_FILE                1


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncomingCallEvent
 * DESCRIPTION
 *  This function is the entry screen for the incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncomingCallEvent(void)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrIncomingCallEvent
 * DESCRIPTION
 *  This function is the exit screen for the incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrIncomingCallEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr101;
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ((defined __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__))
    ResetCenterSoftkey();
#endif 
    if (-1 != GetIncomingCallHandle())
    {
        mmi_ucs2cpy((S8*) scr101.inputBuffer, (PS8) & nHistory);
        scr101.scrnID = ITEMSCR_INCOMING_CALL;
        scr101.entryFuncPtr = EntryScrIncomingCallEvent;
        GetCategoryHistory(scr101.guiBuffer);
        AddHistory(scr101);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLcdScrIncomingCallEvent
 * DESCRIPTION
 *  Entry screen for Sub Lcd Incoming Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLcdScrIncomingCallEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    ShowCategory311Screen(gdispnameForSubLCD, IMG_CM_SUBLCD_CALLING, NULL);
    SetSubLCDExitHandler(ExitSubLcdScrIncomingCallEvent);
}

#ifdef __MMI_INCOMING_CALL_VIDEO__


/*****************************************************************************
 * FUNCTION
 *  EntrySubLcdScrStaticIncomingCallEvent
 * DESCRIPTION
 *  Entry screen for Sub Lcd Incoming Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLcdScrStaticIncomingCallEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    ShowCategory332Screen(IMG_CM_STATE_CONNECTED);
    SetSubLCDExitHandler(ExitSubLcdScrStaticIncomingCallEvent);
}
#endif /* __MMI_INCOMING_CALL_VIDEO__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitSubLcdScrIncomingCallEvent
 * DESCRIPTION
 *  Exit Handler for Sub Lcd Incoming Call Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLcdScrIncomingCallEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INCOMING_CALL_VIDEO__
    //StopCategory17Video();
#endif 

    if (-1 != GetIncomingCallHandle() && !IsSubLCDScreenPresent(SUB_LCD_ITEMSCR_INCOMING_CALL))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = EntrySubLcdScrIncomingCallEvent;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SUB_LCD_ITEMSCR_INCOMING_CALL);
    }
}

#ifdef __MMI_INCOMING_CALL_VIDEO__


/*****************************************************************************
 * FUNCTION
 *  ExitSubLcdScrStaticIncomingCallEvent
 * DESCRIPTION
 *  Exit Handler for Sub Lcd Incoming Call Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLcdScrStaticIncomingCallEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopCategory17Video();

    if (-1 != GetIncomingCallHandle() && !IsSubLCDScreenPresent(SUB_LCD_ITEMSCR_INCOMING_CALL))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = EntrySubLcdScrStaticIncomingCallEvent;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SUB_LCD_ITEMSCR_INCOMING_CALL);
    }
}
#endif /* __MMI_INCOMING_CALL_VIDEO__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncomingMultipleOptions
 * DESCRIPTION
 *  Entry screen for Incoming Call option menu when
 *  there are more than one calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncomingMultipleOptions(void)
{
    ASSERT(0);
}

/*****************************************************************************
 * FUNCTION
 *  ExitScrIncomingMultipleOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrIncomingMultipleOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr1001;
	U16 nHistory=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_SUPPORT__)
    mmi_frm_unhide_menu_item(MITEM_INC_ACT_OPT_LOUDSP);
#endif 

    Scr1001.scrnID = ITEM_SCR_INC_MACT_OPN;
    Scr1001.entryFuncPtr = EntryScrIncomingMultipleOptions;
    mmi_ucs2cpy((S8*) Scr1001.inputBuffer, (PS8) & nHistory);    
    GetCategoryHistory(Scr1001.guiBuffer);
    AddHistory(Scr1001);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIncomingOptions
 * DESCRIPTION
 *  This function is the entry screen for the incoming call options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIncomingOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 number_of_items = 0;
    U16 list_of_items[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(ITEM_SCR_INCOMING_OPTIONS, NULL, EntryScrIncomingOptions, NULL);

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_EntryScrIncomingOptions);

    /* incoming call option menu will not enter other app, 
       no need to set CM flag */
    /* SetCMScrnFlag(TRUE); */

    guiBuffer = GetCurrGuiBuffer(ITEM_SCR_INCOMING_OPTIONS);    /* Getting the Index from history  */
#ifdef __MMI_VOIP__
    /* hide call deflect option menu if voip call exists */
    if (mmi_voip_app_total_call())
    {
        mmi_frm_hide_menu_item(MITEM_INC_OPT_DEFLN);
    }
#endif /* __MMI_VOIP__ */
    number_of_items = GetNumOfChild_Ext(MITEM_OPT_PSEUDO);
    GetSequenceStringIds_Ext(MITEM_OPT_PSEUDO, list_of_items);
    
    SetParentHandler(MITEM_OPT_PSEUDO);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory1Screen(
        STR_SCR1002_CAPTION,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        number_of_items,
        list_of_items,
        0,
        guiBuffer);
    /*
     * Leo Remove, use category1 instead.
     * ShowCategory101Screen(STR_OPT_PSEUDO, 0,
     * STR_GLOBAL_OK, IMG_GLOBAL_OK,
     * STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     * MITEM_OPT_PSEUDO, guiBuffer);
     */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(KbCBackCallIncomingAccepted, KEY_SEND, KEY_EVENT_DOWN);

    SetSideVolumeKeysForCM();
    /* 
     * #ifdef __MMI_SIDEKEY_SUPPRESS_RING__
     * SetKeyHandler(StopIncomingCallIndication,KEY_VOL_DOWN,KEY_EVENT_DOWN);
     * SetKeyHandler(KbCBackCallIncomingSuppressTone,KEY_VOL_DOWN,KEY_EVENT_UP);
     * SetKeyHandler(KbCBackCallIncomingRejectedNoTone,KEY_VOL_DOWN,KEY_EVENT_LONG_PRESS);
     * #else
     * SetKeyHandler(KbCBackCallIncomingAccepted,KEY_VOL_UP,KEY_EVENT_DOWN);
     * SetKeyHandler(KbCBackCallIncomingRejected,KEY_VOL_DOWN,KEY_EVENT_DOWN);
     * #endif
     */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrCcbsActivate
 * DESCRIPTION
 *  This function is the entry screen for displaying CCBS Info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCcbsActivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_gsm_ccbs_activation_conf((U8 *)get_string(STR_NFY_CCBS));
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrCcbsActivate
 * DESCRIPTION
 *  This function is the exit screen for CCBS info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrCcbsActivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetErrorToneFlag() > 0)
    {
        stopRequestedTone(GetErrorToneFlag());
        SetErrorToneFlag(0);
    }

    /*for 5+ send to activate CCBS*/
    Scr.scrnID = ITEM_SCR_CCBS_IND;
    Scr.entryFuncPtr = EntryScrCcbsActivate;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    AddHistory(Scr);
	
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrNotifyCCBSSuccess
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  ccbs activation is success with a timeout of CM_NOTIFY_TIMEOUT.
 *  
 *  This has to display the time,we need to have the time display catefory function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrNotifyCCBSSuccess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gsm_notify_ind((U8 *)get_string(CCBS_ACTIVATED_STR), NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrCCBSInvokeEvent
 * DESCRIPTION
 *  This function is the entry screen for the CCBS Invoke
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCCBSInvokeEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gsm_ccbs_recall_conf(GetCCBSNumber());
    playRequestedTone(CALL_REMINDER_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrCCBSInvokeMultipleOptions
 * DESCRIPTION
 *  This function is the entry screen for the CCBS Invoke
 *  option menu when there are more than one calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCCBSInvokeMultipleOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    static U8 *PopUpList[10];
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 nStrItemList[10];   /* Stores the strings id of submenus returned */
    U16 menuId;
    S16 nActiveCall;
    U16 nHeldCall;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_EntryScrCCBSInvokeMultipleOptions);

    nActiveCall = GetTotalActiveCallCount();
    nHeldCall = GetTotalHoldCallCount();

    if (nActiveCall == 1 && nHeldCall == 0)
    {
        menuId = MITEM_CCBS_ACT_OPT_PSEUDO;
    }
    else if (nActiveCall == 0 && nHeldCall == 1)
    {
        menuId = MITEM_CCBS_HLD_OPT_PSEUDO;
    }
    else if (nActiveCall > 1 && nHeldCall == 0)
    {
        menuId = MITEM_CCBS_MACT_OPT_PSEUDO;
    }
    else if (nActiveCall == 0 && nHeldCall > 1)
    {
        menuId = MITEM_CCBS_MHLD_OPT_PSEUDO;
    }
    else if (nActiveCall == 1 && nHeldCall == 1)
    {
        menuId = MITEM_CCBS_ACT_HLD_OPT_PSEUDO;
    }
    else if (nActiveCall > 1 && nHeldCall > 0)
    {
        menuId = MITEM_CCBS_MACT_HLD_OPT_PSEUDO;
    }
    else if (nActiveCall > 0 && nHeldCall > 1)
    {
        menuId = MITEM_CCBS_ACT_MHLD_OPT_PSEUDO;
    }
    else
    {
        return;
    }

    EntryNewScreen(ITEM_SCR_CCBS_ACT_MHLD_OPN, NULL, EntryScrCCBSInvokeMultipleOptions, NULL);

    guiBuffer = GetCurrGuiBuffer(ITEM_SCR_CCBS_ACT_MHLD_OPN);
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

    if (GetTotalActiveCallCount() == 0 || GetTotalHoldCallCount() == 0)
    {
        SetKeyHandler(KbCBackCCBSDialCall, KEY_SEND, KEY_EVENT_DOWN);
    }

#ifdef __MMI_CLAMSHELL__
    SetKeyHandler(KbCBackCCBSInvokeRejected, KEY_END, KEY_EVENT_DOWN);
#else 
    SetKeyHandler(KbCBackEndAllCallsExceptIncoming, KEY_END, KEY_EVENT_DOWN);
#endif 

    SetSideVolumeKeysForCM();
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrShowSSEvent
 * DESCRIPTION
 *  This function is the entry screen for displaying SS info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrShowSSEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8* guiBuffer; */
    U16 scrIdDisplay;
	U8 ptrDisplayString[150];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrIdDisplay = GetStrDisplayForId(gSSEvent);
    if (scrIdDisplay == 0)
    {
        return;
    }

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_EntryScrShowSSEvent);

    SetNotifySSFlag(TRUE);

    // guiBuffer = GetCurrGuiBuffer(ITEM_SCR_SS_NFY);   /* Getting the Index from history  */

	mmi_ucs2cpy((PS8) ptrDisplayString, (PS8) GetString(scrIdDisplay));
	
	if(gSSEventNotifyPresent) /* By Mick: present notification info to user*/
	{
		switch(gSSEventNotify)
		{
			case 1: 	/* The call is forwarded : 00000001*/
				mmi_ucs2cat((S8 *)ptrDisplayString, (S8 *)(L", "));
				mmi_ucs2cat((S8 *)ptrDisplayString, (S8 *)GetString(STR_ID_CALL_IS_FORWARDED_CALL));
				break;
			case 2:		/* 00000010 */
				//mmi_ucs2cat((S8 *)ptrDisplayString, (S8 *)(L"(02)"));
				break;
			case 4:		/* The received call is forwarded : 00000100*/
				if(gSSEvent != CSMCC_NOTIFY_CF) /*avoid double call forwarded msg*/
				{
					mmi_ucs2cat((S8 *)ptrDisplayString, (S8 *)(L", "));
					mmi_ucs2cat((S8 *)ptrDisplayString, (S8 *)GetString(STR_ID_CALL_IS_FORWARDED));
				}
				break;
			default:
				break;
		}
	}

	/*ShowCategory63Screen((U8*) ptrDisplayString, 0, NULL);*/
    mmi_gsm_notify_ind((U8*) ptrDisplayString, NULL, NULL);

    /*SetPOPUpFlag(TRUE);
    SetKeysForPOPUp();
    StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, GoBackfromNotifyScr);*/
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrShowSSEvent
 * DESCRIPTION
 *  This function is the exit screen for for displaying SS info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrShowSSEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ExitScrShowSSEvent);
    StopTimer(CM_NOTIFYDURATION_TIMER);

    if (GetPOPUpFlag())
    {
        SetPOPUpFlag(FALSE);
        AdjustHistoryForCM();
    }

    SetNotifySSFlag(FALSE);

    if (GetCbackAfterSS())
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ExitScrShowSSEvent1);

        if (GetCurrentState() == CM_INCOMING_STATE && IsScreenPresent(ITEMSCR_INCOMING_CALL))
        {
            SetCbackAfterSS(NULL);
            GoBackToHistory(ITEMSCR_INCOMING_CALL);
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ExitScrShowSSEvent2);
        }
        else if ((GetCbackAfterSS() == EntryScr1002ActiveCall) && IsScreenPresent(SCR_CM_ACTIVECALLSCREEN))
        {
            GoBackToHistory(SCR_CM_ACTIVECALLSCREEN);
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ExitScrShowSSEvent3);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ExitScrShowSSEvent4);
            (*GetCbackAfterSS())();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HandleCallDelfectDigitEntry
 * DESCRIPTION
 *  This function is entered when a key
 *  is pressed at the Call Deflect screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleCallDelfectDigitEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(CallDeflectBuffer, 0, sizeof(CallDeflectBuffer));

    GetkeyInfo(&Keycode, &Keytype);
    CallDeflectDigitKeyCode = Keycode;

    EntryCallDeflectDigitHandler();
}


/*****************************************************************************
 * FUNCTION
 *  EntryCallDeflectDigitHandler
 * DESCRIPTION
 *  Inputs the digits of a phone number for Call Deflection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCallDeflectDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID, ExitCallDeflectDigitHandler, NULL, NULL);

    cm_p->history_info.IsSave = TRUE;

    history_buffer = GetCurrGuiBuffer(ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID);

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_EntryCallDeflectDigitHandler);

    RegisterInputBoxEmptyFunction(CallDeflectScreenEmpty);
    RegisterInputBoxNotEmptyFunction(CallDeflectScreenNotEmpty);

    ShowCategory16Screen(
        CALL_DEFLECT_SEARCH_LSK,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) CallDeflectBuffer,
        MAX_DIGIT,
        history_buffer);

    if (GetTotalCallCount() == 1)
    {
        SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
    #ifdef __MMI_CLAMSHELL__
        SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
    #else 
        SetKeyHandler(KbCBackEndAllCallsExceptIncoming, KEY_END, KEY_EVENT_DOWN);
    #endif 
    }

    if ((CallDeflectDigitKeyCode >= KEY_0 && CallDeflectDigitKeyCode <= KEY_9) ||
        CallDeflectDigitKeyCode == KEY_STAR || CallDeflectDigitKeyCode == KEY_POUND)
    {
        ExecuteCurrKeyHandler(CallDeflectDigitKeyCode, KEY_EVENT_DOWN);
    }

    SetCategory16RightSoftkeyFunction(CheckBeforeGoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCallDeflectDigitHandler
 * DESCRIPTION
 *  exit fn for Call Deflect digit handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCallDeflectDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->history_info.IsSave)
    {
        history h;
        S16 nHistory = 0;

        h.scrnID = ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID;
        h.entryFuncPtr = EntryCallDeflectDigitHandler;
        CallDeflectDigitKeyCode = -1;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
    else
    {
        cm_p->history_info.IsSave = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CallDeflectScreenEmpty
 * DESCRIPTION
 *  register function when screen is empty for call deflection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallDeflectScreenEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(CALL_DEFLECT_SEARCH_LSK, 0);
    SetLeftSoftkeyFunction(mmi_phb_call_enter_from_deflect_option, KEY_EVENT_UP);
    ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(UI_dummy_function);
    SetDialingKeypadPhonebookHandler(mmi_phb_call_enter_from_deflect_option);
#else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    SetCenterSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 
}


/*****************************************************************************
 * FUNCTION
 *  CallDeflectScreenNotEmpty
 * DESCRIPTION
 *  register function when screen is not empty for call deflection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallDeflectScreenNotEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(CallDeflectDigitCall, KEY_EVENT_UP);

#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_PFAL_CC_HandleSendKeys(CallDeflectDigitCall,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(CallDeflectDigitCall, KEY_SEND, KEY_EVENT_DOWN);
#endif/* __MMI_DUAL_SIM_MASTER__ */
#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(CallDeflectDigitCall);
    SetDialingKeypadPhonebookHandler(mmi_phb_call_enter_from_deflect_option);
#else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 

#ifdef __MMI_DUAL_SIM_MASTER__
     MTPNP_PFAL_CC_SetCenterFunc(CallDeflectDigitCall);
     SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
#else  /* __MMI_DUAL_SIM_MASTER__ */
    SetCenterSoftkeyFunction(CallDeflectDigitCall, KEY_EVENT_UP);
#endif   /* __MMI_DUAL_SIM_MASTER__ */
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 
}


/*****************************************************************************
 * FUNCTION
 *  CallDeflectDigitCall
 * DESCRIPTION
 *  Make a call from scratch pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallDeflectDigitCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCallDeflectFlag(TRUE);
    MakeCall(CallDeflectBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  CheckBeforeGoBackHistory
 * DESCRIPTION
 *  exit fn for Call Deflect digit handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CheckBeforeGoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetNoSave();
    if (0 == GetTotalCallCount())
    {
        GoBackfromNotifyScr();
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrConfirmDTMFString
 * DESCRIPTION
 *  Entry func to screen prompting for dtmf
 *  confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrConfirmDTMFString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempBuf[MAX_DTMFBUF_DIGITS * ENCODING_LENGTH + 40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempBuf, 0, sizeof(tempBuf));

    if (GetTotalActiveCallCount() < 1)
    {
        return;
    }

    mmi_ucs2cpy((S8*) tempBuf, (S8*) GetString(STR_DTMF_CONFIRMATION));
    mmi_asc_to_ucs2((S8*) tempBuf + (mmi_ucs2strlen((S8*) tempBuf) * ENCODING_LENGTH), (S8*) gDTMFConfirmBuf);
    mmi_gsm_auto_dtmf_conf_display((U8*) tempBuf);    
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrConfirmDTMFString
 * DESCRIPTION
 *  exit function for EntryScrConfirmDTMFString()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrConfirmDTMFString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->history_info.IsSave)
    {
        history scr101;
        U16 nHistory = 0;

        mmi_ucs2cpy((S8*) scr101.inputBuffer, (PS8) & nHistory);
        scr101.scrnID = ITEM_SCR_CONFIRM_DTMF_STRING;
        scr101.entryFuncPtr = EntryScrConfirmDTMFString;
        GetCategoryHistory(scr101.guiBuffer);
        AddHistory(scr101);
    }
    else
    {
        cm_p->history_info.IsSave = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  NotifyMONumberChange
 * DESCRIPTION
 *  This function displays number change notification
 * PARAMETERS
 *  newNumber               [IN]        
 *  ptrDisplayString        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void NotifyMONumberChange(U8 *newNumber, U8 *ptrDisplayString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_ucm_app_outgoing_call(MMI_UCM_SIM1_CALL_TYPE_ALL) > 0)
    {
        SetCalledNumber(index, newNumber);
        mmi_gsm_notify_ind((U8*) ptrDisplayString, NULL, NULL);
        mmi_gsm_sync_call_list_ind();
    }
#if defined(__MMI_DUAL_SIM_MASTER__)
    else if(mmi_ucm_app_outgoing_call(MMI_UCM_SIM2_CALL_TYPE_ALL) > 0)
    {
        MTPNP_PFAL_sat_info_ind(newNumber, ptrDisplayString);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  InvisibleDigitHandler
 * DESCRIPTION
 *  Set group key handler for single MT call screen
 *  instead of enter dial pad screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InvisibleDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDtmfBuf();

    AuxInvisibleDigitHandler();

#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_PFAL_CC_HandleSendKeys(MakeCallFromDTMFScr,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(MakeCallFromDTMFScr, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    SetKeyHandler(MakeCallFromDTMFScr, KEY_SEND, KEY_EVENT_DOWN);
    SetGroupKeyHandler(AuxInvisibleDigitHandler, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  AuxInvisibleDigitHandler
 * DESCRIPTION
 *  Convert key digits to ascii to fill dtmf buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AuxInvisibleDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 keycode, keytype;
    U8 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo((U16*) & keycode, (U16*) & keytype);
    len = (U8) mmi_ucs2strlen((S8*) UnicodeDTMFPadCallBuffer);
    if (keycode >= KEY_0 && keycode <= KEY_9)
    {
        UnicodeDTMFPadCallBuffer[len * ENCODING_LENGTH] = keycode + '0';
    }
    else if (keycode == KEY_STAR)
    {
        UnicodeDTMFPadCallBuffer[len * ENCODING_LENGTH] = '*';
    }
    else if (keycode == KEY_POUND)
    {
        UnicodeDTMFPadCallBuffer[len * ENCODING_LENGTH] = '#';
    }
}

/****************************** CISS ***********************************************/

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_slave_ussn_ind
 * DESCRIPTION
 *  This function is intended for registering USSN Indication
 *  for PS Callback
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_slave_ussn_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_gsm_slave_ussn_ind");
    mmi_gsm_set_slave_ss_falg(TRUE);
    PsCBackUSSNInd(info);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_slave_ussr_ind
 * DESCRIPTION
 *  This function is intended for registering USSR Indication
 *  for PS Callback
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_slave_ussr_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_gsm_slave_ussr_ind");
    mmi_gsm_set_slave_ss_falg(TRUE);
    PsCBackUSSRInd(info);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  PsCBackUSSNInd
 * DESCRIPTION
 *  This function is intended for registering USSN Indication
 *  for PS Callback
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackUSSNInd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeriveUSSNbuf(info);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);

    if (IsScreenPresent(SCR_CM_REQUESTINGUSSD))
    {
        HistoryReplace(SCR_CM_REQUESTINGUSSD, ITEM_SCR_USSN_MSG, EntryScrDisplayUSSNMsg);
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) USSRDelHistoryHdlr);
        mmi_gsm_display_ussn_info_on_active_call();
    }
    else
    {
        mmi_gsm_display_ussn_info();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_display_ussn_info
 * DESCRIPTION
 *  show USSN info if it is not MT/MO call screen.
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_display_ussn_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_gsm_display_ussn_info");
    
    if(mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
       mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        StartTimer(USSD_UCM_DISPLAY_TIMER, 500, mmi_gsm_display_ussn_info_on_active_call);
        return;
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);

    EntryScrDisplayUSSNMsg();
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
 *  mmi_gsm_display_ussn_info_on_active_call
 * DESCRIPTION
 *  show USSN info on active call screen.
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_display_ussn_info_on_active_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_gsm_display_ussn_info_on_active_call");
    
    if ((GetExitScrnID() != SCR_ID_UCM_IN_CALL &&
        GetExitScrnID() != SCR_ID_UCM_IN_CALL_OPTION &&
        GetExitScrnID() != SCR_ID_UCM_DTMF_EDITOR) ||
        mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
        mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)

    {
        StartTimer(USSD_UCM_DISPLAY_TIMER, 100, mmi_gsm_display_ussn_info_on_active_call);
        return;
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);

    EntryScrDisplayUSSNMsg();
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
 *  PsCBackUSSRInd
 * DESCRIPTION
 *  This function is intended for registering USSR Indication
 *  for PS Callback
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackUSSRInd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeriveUSSRbuf(info);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
#ifdef __MMI_USSR_TIMER__  
    StartTimer(USSR_SESSION_TIMER, 180000, USSRTimeout); /*Auto expire after 3 mins if network has no action*/
#endif /* __MMI_USSR_TIMER__ */

    if (IsScreenPresent(SCR_CM_REQUESTINGUSSD))
    {
        HistoryReplace(SCR_CM_REQUESTINGUSSD, ITEM_SCR_USSN_MSG, EntryScrDisplayUSSRMsg);
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) USSRDelHistoryHdlr);
        mmi_gsm_display_ussr_info_on_active_call();
    }
    else
    {
        mmi_gsm_display_ussr_info();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_display_ussr_info
 * DESCRIPTION
 *  show USSR info if it is not MT/MO call screen.
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_display_ussr_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_gsm_display_ussr_info");
    
    if(mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
       mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        StartTimer(USSD_UCM_DISPLAY_TIMER, 500, mmi_gsm_display_ussr_info_on_active_call);
        return;
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);

    EntryScrDisplayUSSRMsg();
        
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
 *  mmi_gsm_display_ussr_info_on_active_call
 * DESCRIPTION
 *  show USSR info on active call screen.
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_display_ussr_info_on_active_call()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("mmi_gsm_display_ussr_info_on_active_call");
    
    if ((GetExitScrnID() != SCR_ID_UCM_IN_CALL &&
        GetExitScrnID() != SCR_ID_UCM_IN_CALL_OPTION &&
        GetExitScrnID() != SCR_ID_UCM_DTMF_EDITOR) ||
        mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
        mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        StartTimer(USSD_UCM_DISPLAY_TIMER, 100, mmi_gsm_display_ussr_info_on_active_call);
        return;
    }

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);

    EntryScrDisplayUSSRMsg();
        
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
 *  EntryScrDisplayUSSNMsg
 * DESCRIPTION
 *  This function is the entry screen for displaying USSN info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrDisplayUSSNMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
    StopTimer(USSD_UCM_DISPLAY_TIMER);

    EntryNewScreen(ITEM_SCR_USSN_MSG, ExitScrDisplayUSSNMsg, EntryScrDisplayUSSNMsg, NULL);

    RemoveSSReqScr();

    ShowCategory74Screen(
        STR_TITLE_SCR_USSN_MSG,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) gUSSDbuf,
        mmi_ucs2strlen(gUSSDbuf),
        NULL);

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) USSRDelHistoryHdlr);

    TurnOnBacklight(1);
    SetLeftSoftkeyFunction(MMIUSSNReceiveOK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(MMIUSSNReceiveBack, KEY_EVENT_UP);
    SetKeyHandler(MMIUSSNReceiveEnd, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);
}

/*****************************************************************************
 * FUNCTION
 *  ExitScrDisplayUSSNMsg
 * DESCRIPTION
 *  This function is the exit screen for USSN screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrDisplayUSSNMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("ExitScrDisplayUSSNMsg");

    if (CheckIsBackHistory() == MMI_FALSE)
    {
        mmi_gsm_display_ussn_info_on_active_call();
    }

    return;
}

#ifdef __MMI_USSR_TIMER__  
/*****************************************************************************
 * FUNCTION
 *  USSRTimeout
 * DESCRIPTION
 *  This function is called when USSR is timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void USSRTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_USSR_TIMER__  
    StopTimer(USSR_SESSION_TIMER);
#endif /* __MMI_USSR_TIMER__ */

    MakePsDropUSSDReq(NULL);
    DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
    RemoveSSReqScr();
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
    DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);
    
    StopTimer(USSD_UCM_DISPLAY_TIMER);

    return;
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  GoBackFromUSSNMsg
 * DESCRIPTION
 *  This function is the entry screen for displaying USSN info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackFromUSSNMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  MMIUSSNReceiveOK
 * DESCRIPTION
 *  Receive USSN OK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMIUSSNReceiveOK(void)
{
    ClearDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, NULL);
    GoBackFromUSSNMsg();
    
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  MMIUSSNReceiveAbort
 * DESCRIPTION
 *  Receive USSN Abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMIUSSNReceiveAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetCFCondStage();

    Message.oslSrcId = MOD_MMI;
    
#ifdef __MMI_DUAL_SIM_MASTER__
    if(cm_p->slave_ss_session == TRUE)
    {
        Message.oslDestId = MOD_L4C_2;
    }
    else
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        Message.oslDestId = MOD_L4C;
    }

    Message.oslMsgId = PRT_SS_STRING_ABORT_REQ;
    Message.oslPeerBuffPtr = NULL;
    Message.oslDataPtr = NULL;

    ClearProtocolEventHandler(PRT_SS_STRING_ABORT_RSP);
    OslMsgSendExtQueue(&Message);

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  MMIUSSNReceiveBack
 * DESCRIPTION
 *  Receive USSN Back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMIUSSNReceiveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    MMIUSSNReceiveAbort();
    GoBackFromUSSNMsg();
}


/*****************************************************************************
 * FUNCTION
 *  MMIUSSNReceiveEnd
 * DESCRIPTION
 *  Receive USSN Back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMIUSSNReceiveEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    MMIUSSNReceiveAbort();
    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) > 0 ||
    #ifdef __MMI_DUAL_SIM_MASTER__
        (mmi_secset_is_in_puk_check() == MMI_TRUE || mmi_secset_is_in_sim2_puk_check() == MMI_TRUE)
    #else
        (mmi_secset_is_in_puk_check() == MMI_TRUE)
    #endif
    )
    {
        GoBackHistory();
    }
    else
    {
        DisplayIdleScreen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrDisplayUSSRMsg
 * DESCRIPTION
 *  This function is the entry screen for displaying USSR info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrDisplayUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);
    StopTimer(USSD_UCM_DISPLAY_TIMER);

    EntryNewScreen(ITEM_SCR_USSN_MSG, ExitScrDisplayUSSRMsg, EntryScrDisplayUSSRMsg, NULL);

    RemoveSSReqScr();

    ShowCategory74Screen(
        STR_TITLE_SCR_USSR_MSG,
        0,
        STR_GLOBAL_REPLY,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (PU8) gUSSDbuf,
        mmi_ucs2strlen(gUSSDbuf),
        NULL);

    TurnOnBacklight(1);

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) USSRDelHistoryHdlr);

    SetRightSoftkeyFunction(AbortUSSDResultRequest, KEY_EVENT_UP);
    SetKeyHandler(AbortUSSDResultRequestEND, KEY_END, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(EntryScrEditUSSRMsg, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);
}

/*****************************************************************************
 * FUNCTION
 *  ExitScrDisplayUSSRMsg
 * DESCRIPTION
 *  This function is the exit screen for USSR screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrDisplayUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("Exit function for USSR or USSR reply screen");

    if (CheckIsBackHistory() == MMI_FALSE)
    {
        mmi_gsm_display_ussr_info_on_active_call();
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  USSRDelHistoryHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 USSRDelHistoryHdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) != 0)
    {
        PRINT_INFORMATION("Don't drop abort SS, it is still in call");
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsDropUSSDReq);

    ResetCFCondStage();

    Message.oslSrcId = MOD_MMI;
    
#ifdef __MMI_DUAL_SIM_MASTER__
    if(cm_p->slave_ss_session == TRUE)
    {
        Message.oslDestId = MOD_L4C_2;
    }
    else
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        Message.oslDestId = MOD_L4C;
    }

    Message.oslMsgId = PRT_SS_STRING_ABORT_REQ;
    Message.oslPeerBuffPtr = NULL;
    Message.oslDataPtr = NULL;

    ClearProtocolEventHandler(PRT_SS_STRING_ABORT_RSP);
    OslMsgSendExtQueue(&Message);

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  RegisterUSSRMsgKeyFunction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [?]         
 *  cursor      [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterUSSRMsgKeyFunction(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the validity of the input password */
    if ((length) < 1)
    {
        /* if length is short then disable lsk */
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrDisplayUSSDRes
 * DESCRIPTION
 *  This function is the entry screen for displaying USSN info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrDisplayUSSDRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    EntryNewScreen(ITEM_SCR_USSN_MSG, NULL, EntryScrDisplayUSSDRes, NULL);

    RemoveSSReqScr();

    ShowCategory74Screen(
        STR_TITLE_SCR_USSD_MSG,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (PU8) gUSSDbuf,
        mmi_ucs2strlen(gUSSDbuf),
        NULL);

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  EntryScrEditUSSRMsg
 * DESCRIPTION
 *  This function is the entry screen for Editing USSR info by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEditUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(ITEM_SCR_USSR_EDIT, ExitScrDisplayUSSRMsg, EntryScrEditUSSRMsg, NULL);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    StopTimer(USSD_UCM_DISPLAY_TIMER);

    guiBuffer = GetCurrGuiBuffer(ITEM_SCR_USSR_EDIT);

    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSCFNum, 0, (MAX_CC_ADDR_LEN * ENCODING_LENGTH) + 2);
    }
    RegisterInputBoxValidationFunction(RegisterUSSRMsgKeyFunction);
    ShowCategory5Screen(
        STR_TITLE_SCR_USSR_EDIT_MSG,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
#ifdef __MMI_USSD_REPLY_UCS2__
        (S16)INPUT_TYPE_NUMERIC_CHANGEABLE,
#else /*__MMI_USSD_REPLY_UCS2__*/
        (S16) (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
#endif /*__MMI_USSD_REPLY_UCS2__*/
        (U8*) g_callset_context.SSCFNum,
        MAX_CC_ADDR_LEN,
        guiBuffer);

    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) USSRDelHistoryHdlr);

    SetCategory5RightSoftkeyFunction(EditUSSRGoBack, KEY_EVENT_UP);
    SetKeyHandler(AbortUSSDResultRequestEND, KEY_END, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(SendUSSRMsg, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);

    if (mmi_ucs2strlen((S8*) g_callset_context.SSCFNum) == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EditUSSRGoBack
 * DESCRIPTION
 *  Sends USSR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EditUSSRGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  SendUSSRMsg
 * DESCRIPTION
 *  Sends USSR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 Buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);

#ifdef __MMI_USSR_TIMER__  
    StopTimer(USSR_SESSION_TIMER);
#endif /* __MMI_USSR_TIMER__ */

    ClearExitHandler();
    ClearDtmfBuf();
    FillDtmfBuff((PU8) g_callset_context.SSCFNum);
    Buf = GetDtmfBuffer();

#ifdef __MMI_DUAL_SIM_MASTER__
    if(cm_p->slave_ss_session == TRUE)
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
        mmi_gsm_set_slave_reply_ussr_flag(MMI_TRUE);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_USSD_REPLY_UCS2__
        if(UssrCheckUCS2((U16 *)UnicodeDTMFPadCallBuffer, MAX_DIGITS_USSD) == TRUE)
        {
            PRINT_INFORMATION("SEND USSR REPLY: UCS2 format,char num:%d",mmi_ucs2strlen(UnicodeDTMFPadCallBuffer));
            MakeReplyUSSRCall((PS8)Buf,CSMCC_VOICE_CALL);
        }
        else
        {
            PRINT_INFORMATION("SEND USSR REPLY: not UCS2 format");
            MakeMyCall((PS8) Buf,CSMCC_VOICE_CALL);
        }
#else
        MakeMyCall((PS8) Buf,CSMCC_VOICE_CALL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  UssrCheckUCS2
 * DESCRIPTION
 *  check if UCS2 char exists
 * PARAMETERS
 *  buf         [?]         
 *  charNum     [IN]        number of char in buffer
 * RETURNS
 *  return true if UCS2 char exists, else return false
 *****************************************************************************/
BOOL UssrCheckUCS2(U16 *buf, U32 charNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *buffer = buf;
    U32 charNumber = charNum;
    U16 c;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < charNumber)
    {
        c = buffer[count];
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            return KAL_TRUE;
        }
        count++;
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  AbortUSSDResultRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortUSSDResultRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_AbortUSSDResultRequest);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    ClearExitHandler();
    MakePsDropUSSDReq(CBackDropUSSDReq);
#ifdef __MMI_USSR_TIMER__  
    StopTimer(USSR_SESSION_TIMER);
#endif /* __MMI_USSR_TIMER__ */
}


/*****************************************************************************
 * FUNCTION
 *  AbortUSSDResultRequestEND
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortUSSDResultRequestEND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) != 0)
    {
        PRINT_INFORMATION("Press end key on USSD screen when it is in call, then drop the calls.");
        mmi_ucm_end_all_action();
        return;
    }

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_AbortUSSDResultRequestEND);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
    ClearExitHandler();
    MakePsDropUSSDReq(CBackDropUSSDReqEND);
#ifdef __MMI_USSR_TIMER__  
    StopTimer(USSR_SESSION_TIMER);
#endif /* __MMI_USSR_TIMER__ */

}


/*****************************************************************************
 * FUNCTION
 *  ResumeSSScrInCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResumeSSScrInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history temphistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(ITEM_SCR_USSN_MSG))
    {
        GetHistory(ITEM_SCR_USSN_MSG, &temphistory);
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSR_EDIT, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
        DeleteScreenIfPresent(ITEM_SCR_USSR_EDIT);

        (*(temphistory.entryFuncPtr)) ();
    }
    else if (IsScreenPresent(SCR_CM_REQUESTINGUSSD))
    {
        GetHistory(SCR_CM_REQUESTINGUSSD, &temphistory);
        SetDelScrnIDCallbackHandler(SCR_CM_REQUESTINGUSSD, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(SCR_CM_REQUESTINGUSSD);

        (*(temphistory.entryFuncPtr)) ();
    }
}

#endif /* __MMI_UCM__ */

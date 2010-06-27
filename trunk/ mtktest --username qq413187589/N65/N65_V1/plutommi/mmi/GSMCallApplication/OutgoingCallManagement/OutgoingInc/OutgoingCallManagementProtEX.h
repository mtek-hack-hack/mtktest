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
 * Filename:
 * ---------
 *  OutgoingCallManagementProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : OutgoingCallManagementProt.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : Nov 16,02

**************************************************************/
#ifdef __MMI_UCM__

#ifndef _PIXCOM_OUTGOINGCALLMANAGEMENT_PROT_H
#define _PIXCOM_OUTGOINGCALLMANAGEMENT_PROT_H

//#include "MMIDataType.h"
//#include "CallManagementStruct.h"

extern void ReinitializeOutgoingCall(void);
extern void InitOutGoingCall(void);

extern void HiliteM2011EndSingle(void);
extern void HiliteM2011IncEndSingle(void);
extern void HiliteM2011SingleActiveEnd(void);
extern void HiliteM2019AllActiveEnd(void);
extern void HiliteM2020AllHeldEnd(void);
extern void HiliteM2016AllCallEnd(void);
extern void HiliteIncomingReject(void);
extern void HiliteM2010ActiveHold(void);
extern void HiliteM2012HeldRetrieve(void);
extern void HiliteM2014Swap(void);
extern void HiliteM2015Conference(void);
extern void HiliteM2017Transfer(void);
extern void HiliteM2018Split(void);
extern void HiliteM2031PBookAppEntry(void);
extern void HiliteM2032MsgAppEntry(void);

#ifdef __MMI_VOICE_MEMO__
extern void HiliteM2022VoiceMemo(void);
#endif 
#ifdef __MMI_SOUND_RECORDER__
extern void HiliteM2026SoundRecorder(void);
#endif 
#ifdef __MMI_AUDIO_PLAYER__
extern void HiliteM2025AudioPlayer(void);
#endif 

#if defined(__MMI_BT_SUPPORT__)
extern void HiliteBTCMSetPath(void);
extern void ProcessBTSetVoicePath(void);
#endif /* defined(__MMI_BT_SUPPORT__) */ 

extern void HiliteM2020Mute(void);
extern void HiliteM2024DTMF(void);
extern void HiliteM2023LoudSp(void);
extern void HiliteM2021NewCall(void);
extern void HiliteM2027CTM(void);

extern void Hint2020Mute(U16 index);
extern void Hint2024DTMF(U16 index);

extern void OutgoingProcessCMEvent(CM_EVENT_TYPES inEvenType, void *MsgStruct);
extern void ProcessShowOutgoingCallScreen(void);
extern ACTION_RESULT ProcessKBOutgoingEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSCallconnectedEvent(void *CallIndex);
extern ACTION_RESULT ProcessKBHangupReqEvent(void *CallIndex);
extern ACTION_RESULT ProcessPSHangupSucEvent(void *CallIndex);
extern ACTION_RESULT ProcessKBHangupallReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSHangupallSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBHangupallActReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSHangupallActSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBHangupallHldReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSHangupallHldSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBHoldReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSHoldSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBRetrieveReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSRetrieveSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBSwapReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSSwapSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBConfReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSConfSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBSplitReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSSplitSucEvent(void *MsgStruct);
extern ACTION_RESULT ProcessKBEctReqEvent(void *MsgStruct);
extern ACTION_RESULT ProcessPSEctSuccessful(void *MsgStruct);
extern void PsCBackCallDeflected(void *info);

extern void EndSingleAndGoBack(void);
extern void EndSingleActiveAndGoBack(void);
extern void SplitAndGoBack(void);
extern void SetCurrHiliteCall(S32 hiliteIndex);
extern void HangupHilited(void);
extern void SplitHilited(void);
extern MYTIME *GetCurrStartCallTime(void);


extern void EntryScr1009CallListScreen(void);
extern void EntryScr1001OutgoingCall(void);
extern void ExitScr1001OutgoingCall(void);
extern void EntrySubLcdScr1001OutgoingCall(void);
extern void ExitSubLcdScr1001OutgoingCall(void);
extern void EntryScrOutgoingMultipleOptions(void);
extern void EntryScr1002ActiveCall(void);
extern void DummyScr1002ActiveCall(MYTIME *t);
extern void EntrySubLcdScr1002ActiveCall(void);
extern void ExitSubLcdScr1002ActiveCall(void);
extern void EntryScr1003CMActiveCallOptions(void);
extern void ExitScr1003CMActiveCallOptions(void);
extern void EntryScr1004NotifyEndCallDuration(void);
extern void ExitScr1004NotifyEndCallDuration(void);
extern void EntryScrNotifyCallAborted(void);
extern void EntryScr1005NotifyHoldSucess(void);
extern void EntryScr1006NotifyRetrieveSucess(void);
extern void EntryScr1007NotifySwapSucess(void);
extern void EntryScr1008NotifyConfSucess(void);
extern void EntryScr1010NotifySplitSucess(void);
extern void EntryScrNotifyCHLDSucess(U16 notify_string, pBOOL play_tone);
extern void ExitScrNotifyCMPopUpTone(void);
extern void EntryScrLoudSpNotifyScreen(void);
extern void ExitScrNotifyCMPopUp(void);

/************************** CISS *****************************/
extern void EntryScrUSSDReq(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_gsm_set_slave_ss_falg(pBOOL flag);
extern void mmi_gsm_set_slave_reply_ussr_flag(pBOOL flag);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void AbortUSSDRequest(void);
extern void AbortUSSDRequestEND(void);
extern void ProcessUSSDrecieved(void *info);
extern void mmi_gsm_display_ussd_info(void);
extern void mmi_gsm_display_ussd_info_on_active_call(void);

/* micha0915 */
extern U8 SSReqHistoryDelHdlr(void *in_param);

extern U8 GetOutCallType(void);

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
#endif /* 0 */ 
#endif /* _PIXCOM_OUTGOINGCALLMANAGEMENT_PROT_H */ 
#endif /* __MMI_UCM__ */
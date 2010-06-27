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
 *  IncomingCallManagementProt.h
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

   FILENAME : IncomingCallManagementProt.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Manish

   DATE     : Nov 8,02

**************************************************************/
#ifndef __MMI_UCM__

#ifndef _INCOMINGCALLMANAGEMENT_PROT_H
#define _INCOMINGCALLMANAGEMENT_PROT_H

extern void ReinitalizeIncomingCall(void);
extern void InitIncomingCall(void);

extern void HiliteMenuIncomingAnswer(void);
extern void HiliteMenuIncomingCallDeflection(void);
extern void HiliteMenuCCBSDial(void);
extern void HiliteMenuIncomingEndActive(void);
extern void HiliteMenuEndAllCalls(void);
extern void HiliteCallToEnd(S32 itemIdx);

extern void EntryScrIncomingCallEvent(void);
extern void ExitScrIncomingCallEvent(void);
extern void EntrySubLcdScrIncomingCallEvent(void);
extern void ExitSubLcdScrIncomingCallEvent(void);
extern void EntrySubLcdScrStaticIncomingCallEvent(void);
extern void ExitSubLcdScrStaticIncomingCallEvent(void);
extern void EntryScrIncomingMultipleOptions(void);
extern void ExitScrIncomingMultipleOptions(void);
extern void EntryScrIncomingOptions(void);
extern void EntryScrCcbsActivate(void);
extern void ExitScrCcbsActivate(void);
extern void EntryScrNotifyCCBSSuccess(void);
extern void EntryScrCCBSInvokeEvent(void);
extern void EntryScrCCBSInvokeMultipleOptions(void);
extern void EntryScrShowSSEvent(void);
extern void ExitScrShowSSEvent(void);
extern void EntryScrShowActiveCallToEnd(void);
extern void HandleCallDelfectDigitEntry(void);
extern void EntryCallDeflectDigitHandler(void);
extern void ExitCallDeflectDigitHandler(void);
extern void EntryScrConfirmDTMFString(void);
extern void ExitScrConfirmDTMFString(void);
extern void ExitScrShowNumberChangeNotification(void);

extern void PsCBackCallIncoming(void *info);
extern void PsCBackCallWait(void *info);
extern void PsCBackNetworkCallDropped(void *info);
#ifdef __MMI_CM_CCBS_SUPPORT__
extern void PsCBackCCBSNetworkCallDropped(void *info);
extern ACTION_RESULT ProcessCCBSIncomingCallRejected(void *info);
extern ACTION_RESULT ProcessCCBSEndCallIdAndGoBack(void *info);
#endif /*__MMI_CM_CCBS_SUPPORT__*/
extern void PsCBackCcbsActivate(void *info);
extern void PsCBackActivatedCCBS(void *info);
extern void PsCBackCCBSInvoked(void *info);
extern void PsCBackNotifySSInd(void *info);
extern void PsCBackNotifyCNAPSSInd(void *info);
extern void PsCBackSpeechIndication(void *info);
extern void PsCBackAocIndication(void *info);
extern void PsCBackConfirmDTMFString(void *info);

extern void KbCBackCallIncomingAccepted(void);
extern void KbCBackCallIncomingRejected(void);

#ifdef __MMI_SIDEKEY_SUPPRESS_RING__
extern void KbCBackCallIncomingRejectedNoTone(void);
extern void KbCBackCallIncomingSuppressTone(void);
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 
extern void KbCBackEndActiveAcceptIncomingCall(void);
extern void KbCBackEndSelectiveActiveCall(void);
extern void KbCBackEndAllCallsExceptIncoming(void);
extern void KbCBackCCBSDialCall(void);
extern void KbCBackCCBSInvokeRejected(void);
extern void IgnoreCCBS(void);
extern void ActivateCCBS(void);

extern void ProcessIncomingEvents(CM_EVENT_TYPES event, void *info);
extern ACTION_RESULT ProcessIncomingCallEvent(void *info);
extern ACTION_RESULT ProcessCallWait(void *info);
extern ACTION_RESULT ProcessInvokedCcbs(void *info);
extern ACTION_RESULT ProcessIncomingCallRejected(void *info);
extern ACTION_RESULT ProcessEndCallIdAndGoBack(void *info);
extern void ProcessShowSSEventNotification(void *info);
extern ACTION_RESULT ProcessAocIndication(void *info);
extern void ReverseSpeechIndication(void *info);
extern void ProcessStateCheckIncomingCall(void);

extern void PsCBackIncomingCallAccepted(void *info);
extern void PsCBackCheckChldIncomingCallAccepted(void *info);
extern void PsCBackActiveCallsHeld(void *info);
extern ACTION_RESULT ProcessCallsHeld(void *info);
extern void PsCBackIncomingCallRejected(void *info);
extern ACTION_RESULT ProcessAcceptIncomingCall(void *info);
extern void PsCBackselectedCallEnded(void *info);
extern void PsCBackActiveCallEndedHeldRetrieved(void *info);
extern ACTION_RESULT ProcessEndAllActiveCall(void *info);
extern void CBackHangupAllActive(void);
extern void CBackHangupAllActiveAcceptOther(void *info);
extern ACTION_RESULT ProcessHold2Active(void *info);
extern ACTION_RESULT ProcessCCBSDialRequest(void *info);
extern ACTION_RESULT ProcessCCBSRejectRequest(void *info);
extern void PsCBackCCBSRejectResponse(void *info);
extern void CCBSDialResponse(void *info);

extern void CallDeflectScreenEmpty(void);
extern void CallDeflectScreenNotEmpty(void);
extern void CallDeflectDigitCall(void);
extern void CheckBeforeGoBackHistory(void);

extern void ConfirmDTMFString(void);
extern void IgnoreDTMFStringAndGoBackHistory(void);

extern void SetKeysForPOPUp(void);
extern void POPUPHandler(void);

extern void InvisibleDigitHandler(void);
extern void AuxInvisibleDigitHandler(void);

extern pBOOL IsAttemptToAnswer(void);

/**************************** CISS ********************************/

extern void PsCBackUSSNInd(void *info);
extern void PsCBackUSSRInd(void *info);

extern void EntryScrDisplayUSSNMsg(void);

/*Mick 2007/03/11*/
#ifdef __MMI_USSR_TIMER__  
extern void USSRTimeout(void);
#endif

/* micha0317 */
extern void GoBackFromUSSNMsg(void);
extern void EntryScrDisplayUSSRMsg(void);
extern void ExitScrDisplayUSSRMsg(void);
extern void EntryScrDisplayUSSDRes(void);
extern void EntryScrEditUSSRMsg(void);
extern void MMIUSSNReceiveOK(void);
extern void MMIUSSNReceiveAbort(void);
extern void MMIUSSNReceiveBack(void);
extern void MMIUSSNReceiveEnd(void);


extern void SendUSSRMsg(void);
extern BOOL UssrCheckUCS2(U16 *buf, U32 charNum);
extern void AbortUSSDResultRequest(void);
extern void AbortUSSDResultRequestEND(void);

/* micha0610 */
extern void ResumeSSScrInCall(void);

/* micha0110 */
extern U8 USSRDelHistoryHdlr(void *in_param);
extern void EditUSSRGoBack(void);

extern pBOOL gAttempToReject;
#endif /* _INCOMINGCALLMANAGEMENT_PROT_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "IncomingCallManagementProtEX.h"
#endif /* __MMI_UCM__ */
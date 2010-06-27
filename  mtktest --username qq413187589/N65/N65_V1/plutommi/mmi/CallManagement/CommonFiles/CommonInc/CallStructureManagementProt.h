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
 *  CallStructureManagementProt.h
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

   FILENAME : CallStructureManagementProt.h

   PURPOSE     : Call Strucutre Management API

   REMARKS     : nil

   AUTHOR      : Ashish

   DATE     : Nov 8,02

**************************************************************/
#ifndef __MMI_UCM__

#ifndef CALLSTRUCTUREMANAGEMENT_PROT_H
#define CALLSTRUCTUREMANAGEMENT_PROT_H

typedef struct
{
    CALL_INFO AllCalls[MAX_CALLS];
    CALL_INFO CallStructureForCallLog;
    CALL_STATE CurrentState;
    CALL_STATE PrevState;
    U8 NumofActivecalls;
    U8 NumofHeldcalls;
    U8 TotalCallCount;
    U8 OldestCallIndex;
} cm_state_struct;

extern void ReinitalizeCallManagement(void);
extern void ResetGlobalValues(void);
extern void InitCallInfo(void);
extern void ResetCallInfo(CM_CALL_HANDLE nCallHandle, pBOOL bIsHandle);
extern void PurgeOutgoingCallsStructure(void);
extern void PurgeIncomingCallStructure(void);

#ifdef __MMI_CM_CCBS_SUPPORT__
extern void PurgeIncomingCallStructureForCCBS(void);
extern CM_CALL_HANDLE GetCCBSIncomingCallHandle(void);
extern void SetCCBSHandle(CM_CALL_HANDLE ccbsHandle);
extern CM_CALL_HANDLE GetCCBSHandle(void);
extern void SetDropCCBSAnswerMTFlag(pBOOL flag);
extern pBOOL GetDropCCBSAnswerMTFlag(void);
#endif /*__MMI_CM_CCBS_SUPPORT__*/

extern void PurgeAllCalls(void);

extern void AddNewCallInfo(
                PU8 Number,
                CALL_STATE currentstate,
                CALL_STATE prevstate,
                CALL_DIR MOflag,
                CM_CALL_HANDLE currentCallHandle,
                U8 callType);

extern void SetIncomingCallStateActive(void);
extern void SetCallState(CM_CALL_HANDLE nCallHandle, CALL_STATE state, pBOOL bIsHandle);

/* Start by Julia: Drop call refinement */
extern void SetAllCallState(CALL_STATE state);
extern void SetAllExceptWaitingCallState(CALL_STATE state);
extern void SetAllActiveCallState(CALL_STATE state);
extern void SetAllHeldCallState(CALL_STATE state);

/* End by Julia */
extern CALL_STATE GetCallState(CM_CALL_HANDLE handle);
extern void RestoreCallState(void);

extern void PsCbackSyncCallList(void *MsgStruct);
extern void UpdateStateMachine(void);

extern void SetHoldFlag(void);
extern void ResetHoldFlag(void);
extern void SetRetrieveFlag(void);
extern void ResetRetrieveFlag(void);
extern void SetSwapFlag(void);
extern void ResetSwapFlag(void);
extern void SetConfFlag(void);
extern void ResetConfFlag(void);
extern void ResetSplitFlag(void);
extern void ResetEctFlag(void);
extern void SetAllHangupFlag(void);
extern void SetAllCallsHangupFlag(void);
extern void SetAllActHangupFlag(void);
extern void SetAllHldHangupFlag(void);
extern void ResetAllHangupFlag(void);
extern BOOL CheckAllCallflag(void);
extern U8 GetAllCallFlags(void);

extern CHLD_REQ_ACTION GetChldReqSent(void);
extern void SetChldReqSent(CHLD_REQ_ACTION action);

extern void MakeHold(void);
extern void MakeRetrieve(void);
extern void MakeSwap(void);
extern void MakeConf(void);
extern void MakeAllActHangup(void);
extern void MakeSplitSucess(void);

extern pBOOL AllowMoreCalls(void);
extern CALL_STATE GetPreviousState(void);
extern void SetCurrentState(CALL_STATE state);
extern void SetPreviousState(CALL_STATE state);
extern void SetCallflag(CM_CALL_HANDLE nCallHandle, U8 flag, pBOOL bIsHandle);
extern U8 GetCallflag(CM_CALL_HANDLE nCallHandle, pBOOL bIsHandle);
extern void ResetCallflag(CM_CALL_HANDLE nCallHandle, U8 flag, pBOOL bIsHandle);
extern U16 GetCallDirFlag(CM_CALL_HANDLE handle);

extern CM_CALL_HANDLE MapItemId2CallHandle(U16 idx);
extern S16 GetMMIStructIndexof(CM_CALL_HANDLE nCallIndex);
extern S16 GetFirstFreeIndex(void);

/* Start by Julia: Drop call refinement */
extern CM_CALL_HANDLE GetDisconnectingCallHandle(void);

/* End by Julia */
extern CM_CALL_HANDLE GetIncomingCallHandle(void);
extern void SetOutgoingCallHandle(CM_CALL_HANDLE handle);
extern CM_CALL_HANDLE GetOutgoingCallHandle(void);
extern CALL_DIR GetOutgoingCallOrigin(void);
extern CM_CALL_HANDLE GetCallHandle(PU8 Dispname);
extern CM_CALL_HANDLE GetHungUpHandle(void);
extern S16 GetOutgoingCallIndex(void);
extern U8 GetAllDispNameorNum(PU8 *Dispnames, U16 *DispStrids, U16 *Iconids, S16 *HighlightIndex);
extern U8 GetAllActDispNameorNum(PU8 *Dispnames);
extern U16 GetImgIdofState(CALL_STATE tmpState);

extern void SetCalledNumber(S16 index, U8 *msg);
extern void SetCNAPName(CM_CALL_HANDLE call_handle, U8 dcs, U8 length, U8 *CNAP_name);
extern void SetCalledNumWithTypeAux(S16 index, void *msg);
extern void SetCalledNumWithType(S16 index, void *msg);
extern void SetOutgoingNamefromPhonebook(void);
extern PU8 GetOutgoingNumber(void);
extern PU8 GetOutgoingName(void);
extern U8 GetOutgoingCallType(void);
extern U8 GetIncomingCallType(void);
extern S16 GetActiveCallIndex(void);
extern PU8 GetCallName(CM_CALL_HANDLE handle);
extern PU8 GetCallNumber(CM_CALL_HANDLE handle);
extern U8 GetCallType(CM_CALL_HANDLE handle);
extern MYTIME * GetCallStartTime (CM_CALL_HANDLE handle);
extern U16 GetCallImgId(CM_CALL_HANDLE handle);

#ifdef __MMI_PHB_CALL_SHOW_PICTURE_FROM_FILE__
extern S8 *GetCallImgPath(CM_CALL_HANDLE handle);
#endif 
#ifdef __MMI_INCOMING_CALL_VIDEO__
extern S8 *GetCallVideoPath(CM_CALL_HANDLE handle);
#endif 
extern U8 GetActiveCallType(void);
extern PU8 GetDispNameorNum(void);

#ifdef __MMI_CM_BLACK_LIST__
extern pBOOL BlockedHandle(CM_CALL_HANDLE handle);
extern void SetBlackIncomingFlag(pBOOL value);
extern pBOOL GetBlackIncomingFlag(void);
#endif /* __MMI_CM_BLACK_LIST__ */
extern void SetClearKeyFlag(pBOOL value);
extern pBOOL GetClearKeyFlag(void);
extern void SetCCFlag(pBOOL value);
extern pBOOL GetCCFlag(void);
extern void SetTransitionToActiveFlag(pBOOL flag);
extern void SetAnswerMode(void *mode);
extern void *GetAnswerMode(void);
extern void SetAutoAnswerFlag(pBOOL flag);
extern pBOOL GetAutoAnswerFlag(void);

/* Start by Julia: Drop call refinement */
extern void SetAutoReleaseFlag(pBOOL flag);
extern pBOOL GetAutoReleaseFlag(void);

/* End by Julia */
extern void SetAbortCallRequestedFlag(pBOOL flag);
extern pBOOL GetAbortCallRequestedFlag(void);
extern void SetCallAbortReqSentFlag(pBOOL flag);
extern pBOOL GetCallAbortReqSentFlag(void);
extern void SetDropRequestFlag(pBOOL flag);
extern pBOOL GetDropRequestFlag(void);
extern void SetIncomingCallDroppedFlag(pBOOL flag);
extern pBOOL GetIncomingCallDroppedFlag(void);
extern void SetCallWaitFlag(pBOOL flag);
extern pBOOL GetCallWaitFlag(void);
extern void SetNoTwiceRingFlag(pBOOL flag);
extern pBOOL GetNoTwiceRingFlag(void);
extern void SetWait2RingCallFlag(pBOOL flag);
extern pBOOL GetWait2RingCallFlag(void);
extern void SetCallEndedBeforeConnFlag(pBOOL flag);
extern pBOOL GetCallEndedBeforeConnFlag(void);
extern void SetErrorToneFlag(U8 flag);
extern U8 GetErrorToneFlag(void);
extern void SetShowAOC(pBOOL flag);
extern pBOOL GetShowAOC(void);
extern void SetDTMFKeyUpFlag(pBOOL flag);
extern pBOOL GetDTMFKeyUpFlag(void);
extern void SetCMScrnFlag(pBOOL flag);
extern pBOOL GetCMScrnFlag(void);

extern void UpdateActiveCallScrnIfPresent(void);
extern pBOOL EmergencyCallPresent(void);

extern void SetWapCallPresent(pBOOL flag);
extern void SetPreviousCallWAP(pBOOL flag);
extern pBOOL GetPreviousCallWAP(void);
extern U16 CMAllowInterrupt(void);

extern void SetCallEndCause(U16 cause);
extern U16 GetCallEndCause(void);

#ifdef __IP_NUMBER__
extern void SetTempUseIPNumber(pBOOL flag);
extern pBOOL GetTempUseIPNumber(void);
#endif

extern void SetCMPhoneBookStruct(PHB_CM_INTERFACE *pNumberStruct);
extern PHB_CM_INTERFACE *GetCMPhoneBookStruct(void);
extern void SetCallDeflectFlag(pBOOL flag);
extern pBOOL GetCallDeflectFlag(void);
extern void SetActivatedCcbsFlag(pBOOL ccbsFlag);
extern pBOOL GetActivatedCcbsFlag(void);
extern void SetCCBSFlag(pBOOL ccbsFlag);
extern pBOOL GetCCBSFlag(void);
extern void CCBSUpdateCallInfo(void);

extern void LogCall(void);
extern void LogCallWithStartTime(CALL_INFO *log);
extern void LogCallInfoForCallHistory(CM_CALL_HANDLE handle);
extern void UpdateCallStartTimeAndLogCall(CM_CALL_HANDLE handle, MYTIME *t);
extern void SetCallHandleForStartTimeUpdate(CM_CALL_HANDLE handle);
extern CM_CALL_HANDLE GetCallHandleForStartTimeUpdate(void);
extern void GetEndTimeAndNotifyCallAborted(void);
extern void GetDateTimeAndNotifyCallAbortedCBack(MYTIME *t);
extern void GetEndTimeAndNotifyCallMissed(void);
extern void GetDateTimeAndNotifyCallMissedCBack(MYTIME *t);
extern void GetEndTimeAndLogUnconnectedMOCall(void);
extern void GetDateTimeAndLogUnconnectedMOCallCBack(MYTIME *t);
extern void GetEndTimeAndNotifyEndCallDuration(CM_CALL_HANDLE handle);
extern void GetDateTimeAndNotifyEndCallDurationCBack(MYTIME *t);
extern void UpdateCallStartTimeforWapCall(MYTIME *t);

extern void InitializeTimeStructure(TIMEANDINDEX *time, MYTIME *t);
extern MYTIME *GetStartCallTime(void);

extern void SetPriorityCall(pBOOL priority);
extern pBOOL GetPriorityCall(void);
extern void SetDialedDigitCalledFlag(pBOOL flag);
extern pBOOL GetDialedDigitCalledFlag(void);
extern void SetSATScrnSavedFlag(pBOOL flag);
extern pBOOL GetSATScrnSavedFlag(void);

#endif /* CALLSTRUCTUREMANAGEMENT_PROT_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "CallStructureManagementProtEX.h"
#endif /* __MMI_UCM__ */
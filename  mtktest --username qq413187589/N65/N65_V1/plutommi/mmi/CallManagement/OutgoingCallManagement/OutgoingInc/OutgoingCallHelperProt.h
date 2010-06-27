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
 *  OutgoingCallHelperProt.h
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

   FILENAME : OutgoingCallHelperProt.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : Nov 16,02

**************************************************************/
#ifndef __MMI_UCM__

#ifndef _PIXCOM_OUTGOINGCALLHELPER_PROT_H
#define _PIXCOM_OUTGOINGCALLHELPER_PROT_H

extern void MakeMyCall(PS8 strNumber);
#ifdef __MMI_USSD_REPLY_UCS2__
extern void MakeReplyUSSRCall(PS8 strNumber);
#endif
extern void CheckShortCutOrCall(void);
extern void MakeOutgoingcall(OUTGOING_CALL MsgStruct);
extern pBOOL IsStandardGsmSS(PU8 dtmfBuf);
extern pBOOL isHashString(PU8 buf);
extern pBOOL isShortString(PU8 buf);
extern pBOOL UCS2StrNoFirstPositionSearch(PS8 strNumber, S8 charToSearch);
extern pBOOL UCS2StrFirstPositionSearch(PS8 strNumber);
extern void PsCBackSetCallFeatures(void *info);
extern void PsCbackOutgoingCallIdSync(void *MsgStruct);
extern void OutgoingCallConnected(void *MsgStruct);
extern void PsCBackOutgoingCallEnded(void *MsgStruct);
extern void PsCBackUSSDResponse(void *info);
/* Mick 2006/11/30*/
extern void MakeCallReqInd(void *MsgStruct);

/* Start by Julia: Drop call refinement */
extern void ReleaseCall(void);

/* End by Julia */
// extern void DropRequest(void);
extern void HangupCall(CM_CALL_HANDLE CallHandle);
extern void HangupReqSucess(void *MsgStruct);

extern void HangupAll(void);
extern void HangupallReqSucess(void *MsgStruct);
extern void HangupallActive(void);
extern void HangupallActReqSucess(void *MsgStruct);
extern void HangupallHeld(void);
extern void HangupallHldReqSucess(void *MsgStruct);
extern void MakeActiveCallHold(void);
extern void HoldReqSucess(void *MsgStruct);
extern void RetrieveHeldCall(void);
extern void RetrieveReqSucess(void *MsgStruct);
extern void SwapCall(void);
extern void SwapReqSucess(void *MsgStruct);
extern void ConferenceCall(void);
extern void ConfReqSucess(void *MsgStruct);
extern void SplitCall(CM_CALL_HANDLE CallHandle);
extern void SplitReqSucess(void *MsgStruct);
extern void TransferCall(void);
extern void EctReqSucess(void *MsgStruct);

extern void EntryScrDisplayDialedDigits(void);
extern void ExitScrDisplayDialedDigits(void);
extern void InCallSSCParsing(void);
extern void HandleDTMFScreenDigits(void);
extern void UpdateDialedDigitDisplay(void);
extern void HandleDTMFScreenStopTone(void);
extern void HandleDisplayDialedDigits(void);
extern void DialDigitScreenEmpty(void);
extern void DialDigitScreenNotEmpty(void);
extern void MakeCallFromDTMFScr(void);
extern void CallMgmtSavePhoneBook(void);

extern void ClearDtmfBuf(void);
extern void FillDtmfBuff(PU8 buf);
extern PU8 GetDtmfBuffer(void);

/**********************************************************************/

//void ProcessAcceptIncomingForAT(void *MsgStruct);
//void AcceptIncomingSuc(void* MsgStruct);

/* void StoreAndKeepKeyCode (U16 keycode, U16 keytype); */
extern void SetDialIndication(pBOOL truth);
extern pBOOL GetDialIndication(void);

#endif /* _PIXCOM_OUTGOINGCALLHELPER_PROT_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "OutgoingCallHelperProtEX.h"
#endif /* __MMI_UCM__ */

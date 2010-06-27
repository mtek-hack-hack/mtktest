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
 *  CallManagementGprot.h
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

   FILENAME : CallManagementGprot.h

   PURPOSE     : Call Management Global Prototypes

   REMARKS     : nil

   AUTHOR      : Ashish

   DATE     : Nov 8,02

**************************************************************/
#ifndef __MMI_UCM__

#ifndef _INCOMING_CALL_MANGEMENT_GPROT_H
#define _INCOMING_CALL_MANGEMENT_GPROT_H

#include "CallManagementStruct.h"

extern void InitCallManagement(void);
extern void DeInitCM(void);
extern pBOOL isInCall(void);
extern pBOOL isOutgoingCall(void);
extern pBOOL isIncomingCall(void);
extern pBOOL IsWapCallPresent(void);
extern pBOOL IsFaxCallPresent(void);
extern void CheckAndPrintMsgId(U16 Id);

extern CALL_STATE GetCurrentState(void);
extern U16 GetTotalCallCount(void);

#ifdef __MMI_CM_CCBS_SUPPORT__
extern U16 GetTotalCallCountIncCCBS(void);
#endif /*__MMI_CM_CCBS_SUPPORT__*/

extern S16 GetTotalActiveCallCount(void);
extern U16 GetTotalHoldCallCount(void);

extern void mmi_voip_entry_ans_to_disconn_gsm(void);
extern void mmi_voip_entry_ans_to_conn_gsm(void);
extern void DropRequest(void);

extern void SyncCallList(void);
extern void SetMissedCallFlag(pBOOL flag);
extern pBOOL GetMissedCallFlag(void);
extern void SetSyncCallFromATFlag(pBOOL flag);
extern pBOOL GetSyncCallFromATFlag(void);

extern pBOOL GetTransitionToActiveFlag(void);
extern pBOOL GetWapCallPresent(void);

extern void MakeMOForAT(PS8 num, U8 length, U8 callType);
extern void AcceptCallForAT(S16 handle);
extern void HangupAllCalls(void);

extern U16 IsPhoneInMute(void);
extern void SetLSpkNowOff(pBOOL flag);
extern pBOOL GetDTMFFlag(void);
extern U8 MapDtmfEnum2Ascii(U16 digit);
extern void EnterScreenAndHandleDigit(void);

extern U16 GetCmMarkerScrnID(void);

extern void NotifyCMClampOpen(void);
extern void NotifyCMClampClose(void);
extern void ProcessHeadsetKeyPress(void);

extern void CBackCallDeflectNumberFromPB(PS8 number);
extern void MakeCall(PS8 strNumber);
extern void ShowOutgoingIndicationScreen(PU8 number);
extern void RemoveOutgoingIndicationScreen(void);
extern void NotifyMONumberChange(U8 *newNumber, U8 *ptrDisplayString);
extern void NotifyMTNumberChange(U8 *newNumber, U8 *ptrDisplayString);


/* micha0915 */
extern void RemoveSSReqScr(void);

/*****************************************/
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
/* under construction !*/
/* under construction !*/
#ifdef __IP_NUMBER__
/* under construction !*/
/* under construction !*/
#endif
#endif /* 0 */ 
#endif /* _INCOMING_CALL_MANGEMENT_GPROT_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "CallManagementGprotEX.h"
#endif /* __MMI_UCM__ */
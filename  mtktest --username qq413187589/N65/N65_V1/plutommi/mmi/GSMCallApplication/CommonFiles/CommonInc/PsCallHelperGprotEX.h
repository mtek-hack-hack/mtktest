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
 *  PsCallHelperGprot.h
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

   FILENAME : PsCallHelperGprot.h

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG

   DATE     : Nov 16,02

**************************************************************/
#ifdef __MMI_UCM__

#ifndef _PIXCOM_PSCALLHELPER_GPROT_H
#define _PIXCOM_PSCALLHELPER_GPROT_H

extern void MakePsInitiateCall(U8 *MsgStruct, void *callBack);
extern void MakePsSSVUSSDReq(U8 *MsgStruct, U8 *IPNum, U16 length, void *callBack);
extern void MakePsCallAcceptIncoming(void *callBack);
extern void MakePsAthRequest(void *callBack);

/* Start by Julia: Drop call refinement */
extern void MakePsReleaseCompleteRequest(CM_CALL_HANDLE handle);

/* End by Julia */
extern void MakePsSendUDUB(void *callBack);
extern void MakePsHangupallActiveAcceptOtherRequest(void *callBack);
extern void MakePsEndSelectiveCall(void *callBack, CM_CALL_HANDLE handle);
extern void MakePsActiveHold(void *callBack);
extern void MakePsSplitRequest(CM_CALL_HANDLE nCallHandle);
extern void MakePsConfCallRequest(void);
extern void MakePsEctRequest(void);
extern void MakePsActivateCCBS(void *callBack);
extern void MakePsHangupallRequest(void *callBack);
extern void MakePsSwapCallRequest(void *callBack);
extern void MakePsSendRelHeld(void *callBack);
extern void MakePsHangupallActiveRequest(void *callBack);
extern void MakePsHangupallCallsRequest(void *callBack);
extern void MakePsCallDeflect(void *callBack, PU8 CallDeflectNumber);
extern void MakePsGetCallList(void *callBack);
extern void MakePsDropUSSDReq(PsFuncPtr callBack);
extern void MakePsSendDTMFTone(U16 *MsgStruct);
extern void MakePsStopDTMFTone(void);
extern void MakePsSendDTMFString(U8 *MsgStruct);
extern void MakePsReverseSpeechStatus(pBOOL status, U8 type);
extern void MakePsStartVoiceRecord(void);
extern void MakePsStopVoiceRecord(void);
extern void StartVoiceRecordReqSucess(void *MsgStruct);
extern void VoiceRecordFinishHandler(void *MsgStruct);

extern pBOOL DeriveAndSetCallFeatures(void *info);
extern S16 DeriveOutgoingCallIdRsp(void *info, U16 *cause);
extern CM_CALL_HANDLE DeriveCallHandle(void *info);
extern void DeriveCallInfo(void *info, IncomingCall *incmg);
extern void DeriveCallInfoFromWait(void *info, IncomingCall *incmg);
extern void DeriveCcbsCallInfo(void *info, IncomingCall *incmg);
extern void DeriveSSEvent(void *info);
extern U16 GetStrDisplayForId(U16 event);
extern U32 DeriveCcmValue(void *info);
extern U8 DeriveInternalAlrtIndVal(void *info);
extern pBOOL CheckStatusOfSpeech(void *info, U8 *type);
extern void DeriveUSSDData(U8 dcs, U8 length, U8 *ussd_string);
extern void DeriveUSSNbuf(void *info);
extern void DeriveUSSRbuf(void *info);
extern void DeriveUSSDbuf(void *info);

extern pBOOL CheckChldRequestSuccess(void *info, U16 *cause);
extern void CheckFailureChld(void *info);
extern U16 CheckCallDeflectSuccess(void *info, U16 *cause);
extern U16 CheckAtaSuccess(void *info, U16 *cause);
extern pBOOL CheckRspCcbsFlag(void *info);

extern void CBackDropUSSDReq(void *info);
extern void CBackDropUSSDReqEND(void *info);
extern void CBackDropUSSDSatReq(void *info);

#endif /* _PIXCOM_PSCALLHELPER_GPROT_H */ 
#endif /* __MMI_UCM__ */

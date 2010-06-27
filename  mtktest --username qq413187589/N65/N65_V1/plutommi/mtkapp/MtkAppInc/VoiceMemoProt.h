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
 *  VoiceMemoProt.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _VOICE_MEMO_PROT_H
#define _VOICE_MEMO_PROT_H
#include "MMIDataType.h"

#ifdef __MMI_VOICE_MEMO__
extern void populateVoiceMemoMenu(void);
extern void InitVoiceMemoApp(void);
extern void EntryVoiceMemoInCall(void);
extern void EntryVoiceMemoIdle(void);
extern void EntryVoiceMemoMenu(void);
extern void HighlightVoiceMemo(void);
extern void GetVoiceMemoIndex(S32 index);
extern void ExitScrVoiceMemoList(void);
extern void EntryVoiceMemoList(U16 no_of_vm, UI_string_type file_name_list, BOOL more_entry, U32 free_space);
extern void EntryVoiceMemoRecord(void);
extern void HighlightVoiceMemoRecord(void);
extern void EntryVoiceMemoPlay(void);
extern void HighlightVoiceMemoPlay(void);
extern void EntryVoiceMemoAppend(void);
extern void HighlightVoiceMemoAppend(void);
extern void EntryVoiceMemoDelete(void);
extern void ExitVoiceMemoDelete(void);
extern void HighlightVoiceMemoDelete(void);
extern void EntryVoiceMemoDeleteAll(void);
extern void ExitVoiceMemoDeleteAll(void);
extern void HighlightVoiceMemoDeleteAll(void);
extern void EntryVoiceMemoOptionSave(void);
extern void ExitVoiceMemoOptionSave(void);
extern void HighlightVoiceMemoOptionSave(void);
extern void HighlightVoiceMemoOptionInputMethod(void);
extern void EntryVoiceMemoRenameOption(void);
extern void ExitVoiceMemoRenameOption(void);
extern void EntryVoiceMemoRename(void);
extern void ExitVoiceMemoRename(void);
extern void HighlightVoiceMemoRename(void);
extern void KbCBackRecordResume(void);
extern void KbCBackRecordPause(void);
extern void KbCBackRecordStop(void);
extern void KbCBackPlayResume(void);
extern void KbCBackPlayPause(void);
extern void KbCBackPlayStop(void);
extern void KbCBackAppendResume(void);
extern void KbCBackAppendPause(void);
extern void KbCBackAppendStop(void);
extern void VoiceMemoRecordMap(U32 index);
extern void VoiceMemoDummyFunction(void);
extern void VoiceMemoResetEventHandler(void);
extern void ExitVoiceMemo(void);
extern void EntryVoiceMemoRecordRename(void);
extern void ExitVoiceMemoRecordRename(void);
extern void EntryVoiceMemoAppendRename(void);
extern void ExitVoiceMemoAppendRename(void);
extern void EntryVoiceMemoAbortQuery(void);
extern void ExitVoiceMemoAbortQuery(void);

extern void SendVoiceMemoGetInfoReq(void);
extern void SendVoiceMemoRecordReq(void);
extern void SendVoiceMemoPlayReq(void);
extern void SendVoiceMemoRecordResumeReq(void);
extern void SendVoiceMemoPlayResumeReq(void);
extern void SendVoiceMemoRecordPauseReq(void);
extern void SendVoiceMemoPlayPauseReq(void);
extern void SendVoiceMemoRecordStopReq(void);
extern void SendVoiceMemoPlayStopReq(void);
extern void SendVoiceMemoAbortReq(void);
extern void SendVoiceMemoAppendReq(void);
extern void SendVoiceMemoDeleteMsg(void);
extern void SendVoiceMemoDeleteAllMsg(void);
extern void SendVoiceMemoRenameMsg(void);

extern void VoiceMemoExceptionHandler(U8 cause);
extern void VoiceMemoDeleteRecord(U16 index);

extern void GoBackHistory2(void);
extern void GoBackHistory1(void);
extern void DeleteVoiceMemoHistoryNodes(U16 screenId);
extern void DeleteVoiceMemoHistoryNodesG(void);
extern void SetVoiceMemoDeleteHistoryNodes(U16 screenId);
extern void VoiceMemoSaveFileName(UI_string_type file_name);

extern void VoiceMemoGetInfoRes(void *inMsg);
extern void VoiceMemoRecordRes(void *inMsg);
extern void VoiceMemoPlayRes(void *inMsg);
extern void VoiceMemoStopRes(void *inMsg);
extern void VoiceMemoDeleteRes(void *inMsg);
extern void VoiceMemoAbortRes(void *inMsg);
extern void VoiceMemoPauseRes(void *inMsg);
extern void VoiceMemoResumeRes(void *inMsg);
extern void VoiceMemoAppendRes(void *inMsg);
extern void VoiceMemoRenameRes(void *inMsg);
extern void VoiceMemoRecordFinishInd(void *inMsg);
extern void VoiceMemoPlayFinishInd(void *inMsg);

extern void VoiceMemoRecordReq(U8 dir);
extern void VoiceMemoPauseReq(void);
extern void VoiceMemoStopReq(void);
extern void VoiceMemoAbortReq(void);
extern void VoiceMemoResumeReq(void);
extern void VoiceMemoAppendReq(UI_string_type filename);
extern void VoiceMemoPlayReq(UI_string_type filename);
extern void VoiceMemoDeleteReq(UI_string_type filename);
extern void VoiceMemoDeleteAllReq(void);
extern void VoiceMemoRenameReq(UI_string_type old, UI_string_type new);
extern void VoiceMemoGetInfoReq(void);

extern void VoiceMemoSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

#ifdef VOICE_RECOGNITION_TEST
extern void VRSampleStopRes(void *inMsg);
extern void VRSampleRecordRes(void *inMsg);
extern void VRSampleRecordFinishInd(void *inMsg);
extern void VRSampleDeleteRes(void *inMsg);
extern void VRSampleGetInfoRes(void *inMsg);
extern kal_bool VRSampleRecordReq(U8 dir);
#endif /* VOICE_RECOGNITION_TEST */ 

#endif /* __MMI_VOICE_MEMO__ */ /* VM_SUPPORT */

#endif /* _VOICE_MEMO_PROT_H */ 

